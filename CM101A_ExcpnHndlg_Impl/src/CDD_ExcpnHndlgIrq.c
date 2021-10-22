/**********************************************************************************************************************
* Copyright 2015, 2016 Nxtr
* Nxtr Confidential
*
* Module File Name  : CDD_ExcpnHndlgIrq.c 
* Module Description: Implements the interrupt handling and exception handling functionality of CM101A Exception Handling RH850
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          7 %
* %derived_by:       rzk04c %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 09/11/15   1       KMC       Initial Version                                                                EA4#1832
* 01/19/15   2       LWW       Updated Irq errata support                                                     EA4#3185
* 02/10/16	 3		 AJM       Updated SysErrIrq for including check for Peripehral Bus Data Parity Fault	  EA4#3765
* 03/22/16   4       AJM       Updated SysErrIrq for including DTS Double bit RAM ECC Fault					  EA4#4632
* 04/05/16   5       AJM	   Updates to SysErrIrq for INVLDRAMAREA handling and code flash ecc errors	  	  EA4#5099
* 08/08/16   6       AJM	   Removing single bit code flash handling,added handling on interconnect		  EA4#6629 
							   reserved area access and	inavlid memory access
* 09/20/17   7       AJM       Split multiple address range checks for interconnect reserved area for PIL     EA4#15385
**********************************************************************************************************************/
#include <v800_ghs.h> /* for LDSR, STSR intrinsics */  
#include "Rte_CDD_ExcpnHndlg.h"
#include "CDD_ExcpnHndlg.h"
#include "CDD_ExcpnHndlg_private.h"
#include "seg_regs.h" /* for SEGFLAG */
#include "ecc_regs.h" /* for ECC bank and address registers ECCCPU1DEDF0 etc */
#include "NxtrMcuSuprtLib.h" /* for NxtrSwRstFromExcpn() */
#include "dma_regs.h" /* for DMASSDTSER2 */


/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 2.1 [NXTRDEV 2.1.1]: Deviation allowed for Renesas P1M exception handler errata syncp workaround - 
                                          for readability, the assembly language statements are placed near the definition 
										  of the handler that needs the workaround */

#define FPUINVLDOPERSTSBIT_CNT_U32	((uint32)(0x00004000U))
#define FPUDIVBYZEROSTSBIT_CNT_U32	((uint32)(0x00002000U))
#define FPUOVFSTSBIT_CNT_U32		((uint32)(0x00001000U))

#define MEMERRINFOREADWRBIT_CNT_U32 ((uint32)(0x00000001U))

#define CF1STERSTRADRPARMASK_CNT_U32 ((uint32)(0x00000004U)) 
#define CF1STERSTRDBLBITMASK_CNT_U32 ((uint32)(0x00000002U)) 
#define CF1STERSTRSNGBITMASK_CNT_U32 ((uint32)(0x00000001U)) 

#define PRPHLBUSDATAPARMASK_CNT_U32 ((uint32)(0x10000000U)) 
#define DTSDBLBITMASK_CNT_U32 		((uint32)(0x80000000U)) 

#define LCLRAMBASADR_CNT_U32 0xFEB80000U  /* base address of local RAM */
/* on R7F701311, local RAM actually starts at 0xFEBE0000 -- base address is 0xFEB80000 and offset starts at 0x00060000 */

/* SEGFLAG bit masks */
#define SEGVPGFMASK_CNT_U16		((uint16)(0x0200U))   /* VPGF is bit 9 of SEGFLAG */
#define SEGVCRFMASK_CNT_U16		((uint16)(0x0100U))   /* VCRF is bit 8 of SEGFLAG */
#define SEGTCMFMASK_CNT_U16		((uint16)(0x0040U))   /* TCMF is bit 6 of SEGFLAG */
#define SEGROMFMASK_CNT_U16		((uint16)(0x0020U))   /* ROMF is bit 5 of SEGFLAG */
#define SEGVCIFMASK_CNT_U16		((uint16)(0x0010U))   /* VCIF is bit 4 of SEGFLAG */

/* system register register IDs and selection IDs */
#define FPSRREGID_CNT_S32 		6	/* register ID of FPSR */
#define FPSRSELNID_CNT_S32 		0	/* selection ID of FPSR */

#define FPEPCREGID_CNT_S32 		7	/* register ID of FPEPC */
#define FPEPCSELNID_CNT_S32 	0	/* selection ID of FPEPC */

#define MEIREGID_CNT_S32 		8	/* register ID of MEI */
#define MEISELNID_CNT_S32 		2	/* selection ID of MEI */

#define MEAREGID_CNT_S32 		6	/* register ID of MEA */
#define MEASELNID_CNT_S32 		2	/* selection ID of MEA */

#define INTCNCTRESDAREA1UPPRADR_CNT_U08			(0XFFFF4FFFU)
#define INTCNCTRESDAREA1LOWRADR_CNT_U08			(0xFFFF0000U)
#define INTCNCTRESDAREA2UPPRADR_CNT_U08			(0XFFFEBFFFU)
#define INTCNCTRESDAREA2LOWRADR_CNT_U08			(0xFFFE0000U)
#define INTCNCTRESDAREA3UPPRADR_CNT_U08			(0XFE9FFFFFU)
#define INTCNCTRESDAREA3LOWRADR_CNT_U08			(0XFB000000U)
#define INTCNCTRESDAREA4UPPRADR_CNT_U08			(0XF8FFFFFFU)
#define INTCNCTRESDAREA4LOWRADR_CNT_U08			(0XF3000000U)
#define INVLDMEMACSUPPRADR_CNT_U08				(0XFFFF7EFFU)
#define INVLDMEMACSLOWRADR_CNT_U08				(0xFFFF7900U)

#define CDD_ExcpnHndlg_START_SEC_CODE 
#include "CDD_ExcpnHndlg_MemMap.h"

/**********************************************************************************************************************
*   Patched_SysErrIrq:
*   This section provides the SYNCP workaround for the SYSERR exception (see Renesas Technical Update TN-RH8-S001A/E)
**********************************************************************************************************************/
__asm("   .align  4");
__asm("   .globl  _Patched_SysErrIrq");
__asm("   .extern _SysErrIrq");
__asm("_Patched_SysErrIrq:");
__asm("   syncp");
__asm("   jr    _SysErrIrq");

/*****************************************************************************************************************
 * Name        :   SysErrIrq
 * Description :   Implementation of SYSERR Exception Handling 
 *                 Saves information about the SYSERR cause and performs software reset
 * Inputs      :   Registers containing SYSERR cause information
 * Outputs     :   None
 * Usage Notes :   Called on SYSERR exception occurring after the change from RBASE to EBASE
 *                 SYSERR is an exception with FE "Saved Resource"
 ****************************************************************************************************************/
/* Use GreenHills pragma for creating an interrupt service routine.  
   The (FE) argument is for RH850 FE level exceptions */
#pragma ghs interrupt(FE)  
FUNC(void, CDD_ExcpnHndlg_CODE) SysErrIrq(void)
{
	VAR (McuDiagc1, AUTOMATIC) TmpSrc_Cnt_T_enum;
	VAR (uint32, AUTOMATIC) TmpData_Cnt_T_u32;
	VAR (uint16, AUTOMATIC) Segflag_Cnt_T_u16; 
	VAR (uint32, AUTOMATIC) SegAddr_Cnt_T_u32; 
	VAR (boolean, AUTOMATIC) IntcnctResdAreaFlt_Cnt_T_logl = FALSE;
    
	TmpData_Cnt_T_u32 = 0U; 
	Segflag_Cnt_T_u16 = SEGFLAG; /* copy register to local variable to avoid MISRA Rule 12.2 and/or 12.4 warning */
	SegAddr_Cnt_T_u32 = SEGADDR; /* copy register to local variable to avoid MISRA Rule 12.2 and/or 12.4 warning */
	
    if((SegAddr_Cnt_T_u32 >= INTCNCTRESDAREA1LOWRADR_CNT_U08) && (SegAddr_Cnt_T_u32 <= INTCNCTRESDAREA1UPPRADR_CNT_U08))
    {
        IntcnctResdAreaFlt_Cnt_T_logl = TRUE;
    }
    else if((SegAddr_Cnt_T_u32 >= INTCNCTRESDAREA2LOWRADR_CNT_U08) && (SegAddr_Cnt_T_u32 <= INTCNCTRESDAREA2UPPRADR_CNT_U08))
    {
        IntcnctResdAreaFlt_Cnt_T_logl = TRUE;
    }
	else if((SegAddr_Cnt_T_u32 >= INTCNCTRESDAREA3LOWRADR_CNT_U08) && (SegAddr_Cnt_T_u32 <= INTCNCTRESDAREA3UPPRADR_CNT_U08))
    {
        IntcnctResdAreaFlt_Cnt_T_logl = TRUE;
    }
	else if((SegAddr_Cnt_T_u32 >= INTCNCTRESDAREA4LOWRADR_CNT_U08) && (SegAddr_Cnt_T_u32 <= INTCNCTRESDAREA4UPPRADR_CNT_U08))
    {
        IntcnctResdAreaFlt_Cnt_T_logl = TRUE;
    }
    else
    {
        /* Do Nothing */
    }
	/* Determine source of error from the SEGFLAG bits and indicate in BRAMDAT0 */
	if ((Segflag_Cnt_T_u16 & SEGVPGFMASK_CNT_U16) != 0U)
	{
		TmpSrc_Cnt_T_enum = MCUDIAGC_PRPHLBUSGUARD;  
	}
	else if ((Segflag_Cnt_T_u16 & SEGVCRFMASK_CNT_U16) != 0U)
	{
		TmpSrc_Cnt_T_enum = MCUDIAGC_INTPRPHLGUARD;
	}
	else if ((Segflag_Cnt_T_u16 & SEGTCMFMASK_CNT_U16) != 0U)
	{
		/* Identify bank that failed to get address information from the correct register */
		if (ECCCPU1DEDF0 == 1U)  
		{
			TmpData_Cnt_T_u32 = (uint32)(ECCCPU1LR1STEADR0_PE1 << 4U) | LCLRAMBASADR_CNT_U32;
			TmpSrc_Cnt_T_enum = MCUDIAGC_LCLRAMDBLBIT;
		}
		else if (ECCCPU1DEDF1 == 1U)
		{
			TmpData_Cnt_T_u32 = (uint32)(ECCCPU1LR1STEADR1_PE1 << 4U) | LCLRAMBASADR_CNT_U32 | 0x00000004UL;
			TmpSrc_Cnt_T_enum = MCUDIAGC_LCLRAMDBLBIT;
		}
		else if (ECCCPU1DEDF2 == 1U)
		{
			TmpData_Cnt_T_u32 = (uint32)(ECCCPU1LR1STEADR2_PE1 << 4U) | LCLRAMBASADR_CNT_U32 | 0x00000008UL;
			TmpSrc_Cnt_T_enum = MCUDIAGC_LCLRAMDBLBIT;
		}
		else if (ECCCPU1DEDF3 == 1U) /* bank 3 */
		{
			TmpData_Cnt_T_u32 = (uint32)(ECCCPU1LR1STEADR3_PE1 << 4U) | LCLRAMBASADR_CNT_U32 | 0x0000000CUL;
			TmpSrc_Cnt_T_enum = MCUDIAGC_LCLRAMDBLBIT;
		}
		else
		{
			/*Access to invalid RAM area caused the error*/
			TmpSrc_Cnt_T_enum = MCUDIAGC_INVLDRAMAREA;			
		}

	}
	else if (((Segflag_Cnt_T_u16 & SEGROMFMASK_CNT_U16) != 0U) || ((Segflag_Cnt_T_u16 & SEGVCIFMASK_CNT_U16) != 0U))  
	/* Both bits have code flash ECC */
	{
		if ((ECCFLICF1STERSTR_PE1 & CF1STERSTRADRPARMASK_CNT_U32) != 0U)
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_ADRPAR; /* Address Parity */
			TmpData_Cnt_T_u32 = ECCFLICF1STEADR0_PE1;
		}
		else if ((ECCFLICF1STERSTR_PE1 & CF1STERSTRDBLBITMASK_CNT_U32) != 0U)
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_CODFLSDBLBIT; /* Double Bit Failure */
			TmpData_Cnt_T_u32 = ECCFLICF1STEADR0_PE1;
		}
		else if ((ECCFLICF1STERSTR_VCI & CF1STERSTRADRPARMASK_CNT_U32) != 0U)
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_ADRPAR; /* Address Parity */
			TmpData_Cnt_T_u32 = ECCFLICF1STEADR0_VCI;
		}
		else if ((ECCFLICF1STERSTR_VCI & CF1STERSTRDBLBITMASK_CNT_U32) != 0U)
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_CODFLSDBLBIT; /* Double Bit Failure */
			TmpData_Cnt_T_u32 = ECCFLICF1STEADR0_VCI;
		}
		else if ((ECMMESSTR0 & PRPHLBUSDATAPARMASK_CNT_U32) != 0U)
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_PRPHLBUSDATAPAR; /* Bus Parity Failure */
		}
		else if ((DMASSDTSER2 & DTSDBLBITMASK_CNT_U32)!= 0U)
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_DTSDBLBIT; /* DTS RAM Double Bit ECC fault */
			TmpData_Cnt_T_u32 = DMASSDTSER2;
		}
		else if(IntcnctResdAreaFlt_Cnt_T_logl != FALSE)
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_INTCNCTRESDAREA; /* Interconnect Reserved Area access */
			TmpData_Cnt_T_u32 = SegAddr_Cnt_T_u32;
		}
		else if ((SegAddr_Cnt_T_u32 >= INVLDMEMACSLOWRADR_CNT_U08) && (SegAddr_Cnt_T_u32 <= INVLDMEMACSUPPRADR_CNT_U08))
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_INVLDMEMACS; /* Invalid Memory Access */
			TmpData_Cnt_T_u32 = SegAddr_Cnt_T_u32;
		}
		else
		{
			TmpSrc_Cnt_T_enum = MCUDIAGC_VCIE; /* PBG & Other VCIE cause */
		}
	}
	else /* Assume instruction fetch error drove SYSERR */
	{
		TmpSrc_Cnt_T_enum = MCUDIAGC_INSTRFETCH;
	}
	/* Issue software reset */
	NxtrSwRstFromExcpn(TmpSrc_Cnt_T_enum, TmpData_Cnt_T_u32);	
}

/**********************************************************************************************************************
*   Patched_FpuErrIrq:
*   This section provides the SYNCP workaround for the Floating Point exception (see Renesas Technical Update TN-RH8-S001A/E)
**********************************************************************************************************************/
__asm("   .align  4");
__asm("   .globl  _Patched_FpuErrIrq");
__asm("   .extern _FpuErrIrq");
__asm("_Patched_FpuErrIrq:");
__asm("   syncp");
__asm("   jr    _FpuErrIrq");

/*****************************************************************************************************************
 * Name        :   FpuErrIrq
 * Description :   Implementation of Floating Point Unit Exception (Imprecise) Handling 
 *                 Saves information about the FPU exception cause and performs software reset
 * Inputs      :   Registers containing FPU exception information
 * Outputs     :   None
 * Usage Notes :   Called on FPU exception (imprecise) (FPI)
 *                 FPI is an exception with EI "Saved Resource"
 ****************************************************************************************************************/
/* Use GreenHills pragma for creating an interrupt service routine.  
   The default is for RH850 EI level exceptions */
#pragma ghs interrupt
FUNC(void, CDD_ExcpnHndlg_CODE) FpuErrIrq(void)
{
	VAR (uint32, AUTOMATIC) FpuExcpnProgCntr_Cnt_T_u32;
	VAR (uint32, AUTOMATIC) FpuStsReg_Cnt_T_u32;
	VAR (McuDiagc1, AUTOMATIC) McuDiagcData0_Cnt_T_enum;
	
	FpuExcpnProgCntr_Cnt_T_u32 = __STSR (FPEPCREGID_CNT_S32, FPEPCSELNID_CNT_S32);
	FpuStsReg_Cnt_T_u32 = __STSR (FPSRREGID_CNT_S32, FPSRSELNID_CNT_S32);
	
	if ((FpuStsReg_Cnt_T_u32 & FPUINVLDOPERSTSBIT_CNT_U32) != 0U)
	{
		McuDiagcData0_Cnt_T_enum = MCUDIAGC_FPUERRINVLDOPER;
	}
	else if ((FpuStsReg_Cnt_T_u32 & FPUDIVBYZEROSTSBIT_CNT_U32) != 0U)
	{
		McuDiagcData0_Cnt_T_enum = MCUDIAGC_FPUERRDIVBYZERO;
	}
	else if ((FpuStsReg_Cnt_T_u32 & FPUOVFSTSBIT_CNT_U32) != 0U)
	{
		McuDiagcData0_Cnt_T_enum = MCUDIAGC_FPUERROVF;
	}
	else
	{
		McuDiagcData0_Cnt_T_enum = MCUDIAGC_FPUERRUKWN;
	}
	/* Issue software reset */
	NxtrSwRstFromExcpn(McuDiagcData0_Cnt_T_enum, FpuExcpnProgCntr_Cnt_T_u32);	
}

/*****************************************************************************************************************
 * Name        :   AlgnErrIrq
 * Description :   Implementation of Misalignment  Exception Handling 
 *                 Saves information about the misalignment exception cause and performs software reset
 * Inputs      :   Registers containing misalignment exception information
 * Outputs     :   None
 * Usage Notes :   Called on misalignment exception (MAE)
 *                 MAE is an exception with FE "Saved Resource"
 ****************************************************************************************************************/
/* Use GreenHills pragma for creating an interrupt service routine.  
   The (FE) argument is for RH850 FE level exceptions */
#pragma ghs interrupt(FE)
FUNC(void, CDD_ExcpnHndlg_CODE) AlgnErrIrq(void)
{
	VAR (uint32, AUTOMATIC) MemErrInfo_Cnt_T_u32;
	VAR (uint32, AUTOMATIC) MemErrAdr_Cnt_T_u32;
	VAR (McuDiagc1, AUTOMATIC) McuDiagcData0_Cnt_T_enum;
	
	MemErrInfo_Cnt_T_u32 = __STSR (MEIREGID_CNT_S32, MEISELNID_CNT_S32);
	MemErrAdr_Cnt_T_u32 = __STSR (MEAREGID_CNT_S32, MEASELNID_CNT_S32);
	
	if ((MemErrInfo_Cnt_T_u32 & MEMERRINFOREADWRBIT_CNT_U32) == MEMERRINFOREADWRBIT_CNT_U32)
	{
		McuDiagcData0_Cnt_T_enum = MCUDIAGC_ALGNWR;
	}
	else
	{
		McuDiagcData0_Cnt_T_enum = MCUDIAGC_ALGNREAD;
	}
	/* Issue software reset */
	NxtrSwRstFromExcpn(McuDiagcData0_Cnt_T_enum, MemErrAdr_Cnt_T_u32);	
}

/*****************************************************************************************************************
 * Name        :   ResdOperIrq
 * Description :   Implementation of Reserved Operation (reserved instruction) Exception Handling 
 *                 Saves information about the exception cause and performs software reset
 * Inputs      :   FEPC - FE exception program counter
 * Outputs     :   None
 * Usage Notes :   Called on reserved instruction exception (RIE)
 *                 RIE is an exception with FE "Saved Resource"
 ****************************************************************************************************************/
/* Use GreenHills pragma for creating an interrupt service routine.  
   The (FE) argument is for RH850 FE level exceptions */
#pragma ghs interrupt(FE)
FUNC(void, CDD_ExcpnHndlg_CODE) ResdOperIrq(void)
{
	/* Issue software reset */
	NxtrSwRstFromExcpn(MCUDIAGC_RESDOPER, 0U);	
}

#define CDD_ExcpnHndlg_STOP_SEC_CODE 
#include "CDD_ExcpnHndlg_MemMap.h"
