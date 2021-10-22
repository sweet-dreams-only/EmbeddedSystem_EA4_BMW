/**********************************************************************************************************************
* Copyright 2015,2016,2017 Nxtr 
* Nxtr Confidential
*
* Module File Name: CDD_FlsMemNonRte.c
* Module Description: Flash Memory Complex Driver NonRte Functionality
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          12 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/05/15  1        LWW       Initial Version                                                                 EA4#1830
* 01/11/16  2        AJM       Changes for Flash CRC Region check					       					   EA4#3245 
* 01/15/16  3        AJM       Changes DTS interrupt enable on second last channel							   EA4#3245
* 03/09/16  4        Selva     Updated to FDD v2.2 (ChkForStrtUpTest added at Init)							   EA4#3820
* 03/29/16  5		 AJM       Added the DTS Transfer Flag Clear functionality   							   EA4#5005
* 03/31/16  6	     AJM       Removed Code Flash Single Bit ECC error handler and disabling the DTS after use EA4#4960 
* 08/20/16  7	     AJM       Added ISR handler for single bit ECC error			 						   EA4#6660
* 08/31/16  8	     AJM       Added handling for code flash hard fault				 						   EA4#7340
* 03/07/17  9        AJM       Updated to include micro diag error cases & updates per code review             EA4#7197,EA4#8359
* 04/24/17  10       AJM       Quality Updates                                                                 EA4#10797
* 05/17/17  11       LWW       Updates to remove unnecessary MemMap header include                             EA4#11988
* 07/31/17  12       AJM       Updates to ResvCrcHwUnit_Oper Portif and corrected fault injection code         EA4#13563
* 09/18/17  13       AJM       Updates to Code flash classification check as per renesas feedback and          EA4#15078
                               modifying the error injection code accordingly       
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "CDD_FlsMem.h"
#include "CDD_FlsMem_Cfg_private.h"
#include "Rte_CDD_FlsMem.h" 
#include "CDD_SyncCrc.h"
#include "CDD_NxtrTi.h"
#include "ecc_regs.h"
#include "CDD_ExcpnHndlg.h"
#include "dma_regs.h"
#include "NxtrMcuSuprtLib.h"
#include "Os.h"
#include "intc_regs.h"
#include "McuErrInj.h"
#include <v800_ghs.h> /* for SYNCM,SYNCI */  

/* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.2]	Cast of a variable address to an integer type required for writing a variable address to a register. */
 
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define CDD_FlsMemNonRte_START_SEC_VAR_INIT_128
#include "CDD_FlsMemNonRte_MemMap.h"

VAR(uint32, AUTOMATIC) HwCrcCalcdRes_C[HWCRCRESARYSIZE_CNT_U08] = {0U,0U,0U,0U,0U,0U,0U,0U};
    
#define CDD_FlsMemNonRte_STOP_SEC_VAR_INIT_128
#include "CDD_FlsMemNonRte_MemMap.h"
    
 
#define CPU1PEID_CNT_U32 				((uint32)0x01U)
#define CODFLSTOCRCSPID_CNT_U32			((uint32)0x02U)  			/* Code Flash to CRC Peripheral SPID = 2U */
#define CRCTOLCLRAMSPID_CNT_U32			((uint32)0x00U)  			/* CRC Peripheral to Local RAM SPID = 0U */
  
#define USRMODDIS_CNT_U32				((uint32)0x0U)  			/* User Mode Bit : 1: User Mode Access Disabled */

#define FLSBLKLEN_CNT_U32				((uint32)0x0003FFFCU)		/* Max Transfer is 0xFFFF * 4 bytes per transfer */
#define DTSDATALEN_CNT_U32				((uint32)4U)

#define READADRCASE0_CNT_U08			((uint8)0U)
#define READADRCASE1_CNT_U08			((uint8)1U)
#define READADRCASE2_CNT_U08			((uint8)2U)
#define READADRCASE3_CNT_U08			((uint8)3U)
#define ERRADRMASK_CNT_U32              ((uint32)0x80UL)
#define NROFADRCHK_CNT_U08              ((uint8)4U)


/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/
#define CDD_FlsMem_START_SEC_CONST_UNSPECIFIED
#include "CDD_FlsMem_MemMap.h"

static const uint32 CrcClrData_M = 0U;	/* Clear variable for the CRC HW */
#if(MCUDIAGCERRINJ == STD_ON)
volatile const uint32 AddressParityTestDisableVal_M = 0x00004000U;
#endif

#define CDD_FlsMem_STOP_SEC_CONST_UNSPECIFIED
#include "CDD_FlsMem_MemMap.h"

/******************************************** Local Function Prototypes **********************************************/
#if(MCUDIAGCERRINJ == STD_ON)
static FUNC(void, CDD_McuDiagcTest_CODE) AddressParityTestFunction(void);
#endif
/*********************************************** Function Definitions ************************************************/
#define CDD_FlsMem_START_SEC_CODE
#include "CDD_FlsMem_MemMap.h"

/**********************************************************************************************************************
  * Name:        FlsMemInit2
  * Description: Non-RTE Function to Initilaize the DTS after allocating a CRC hardware
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called from Startup Sequence
  ********************************************************************************************************************/
FUNC(void, CDD_FlsMem_CODE) FlsMemInit2(void)
{

	VAR (uint32, AUTOMATIC) CrcHwIdxInReg_T_u32 = (uint32)0U;
	VAR (uint32, AUTOMATIC) CrcHwIdxOutReg_T_u32 = (uint32)0U;
	VAR (Std_ReturnType, AUTOMATIC) RetVal_T_enum;
	VAR(boolean,AUTOMATIC) ExecStrtUpTest_Cnt_T_logl; 
	
    (void)ChkForStrtUpTest_Oper(&ExecStrtUpTest_Cnt_T_logl);
	if(ExecStrtUpTest_Cnt_T_logl == TRUE)
	{
		*Rte_Pim_CrcHwIdxKey() = 0U;
	
		RetVal_T_enum = ResvCrcHwUnit_Oper(CRCHWRESVMOD_RESV, CRCHWRESVCFG_32BITCRC32BITWIDTH, &CrcHwIdxInReg_T_u32, &CrcHwIdxOutReg_T_u32, 0u, Rte_Pim_CrcHwIdxKey());

		if( RTE_E_OK == RetVal_T_enum )
		{
			/* DTS_Init is called as a trusted function */
			Call_DtsInin(CrcHwIdxInReg_T_u32,CrcHwIdxOutReg_T_u32);
		}
		
		/* capture the system time and store to PIM */
		GetRefTmr100MicroSec32bit_Oper(Rte_Pim_CodFlsCrcChkStrtTi());
	}
	else
	{
		*Rte_Pim_PwrOnRstCrcChkCmpl() = TRUE;
	}

}

/**********************************************************************************************************************
  * Name:        DtsInin
  * Description: DTS Register Setup Function
  * Inputs:      CrcHwIdxInReg,CrcHwIdxOutReg
  * Outputs:     NONE
  * Usage Notes: To be called from FlsMemInit2
                 Need to run in Supervisor mode
  ********************************************************************************************************************/

FUNC(void, CDD_FlsMem_CODE) DtsInin(uint32 CrcHwIdxInReg, uint32 CrcHwIdxOutReg) 
{
 
	VAR (uint8, AUTOMATIC) NrOfChPerRegn_Cnt_T_u08 = (uint8)0U;
	VAR (uint8, AUTOMATIC) Loop_Cnt_T_u08 = (uint8)0U;
	VAR (uint8, AUTOMATIC) ChNr_Cnt_T_u08  = (uint8)0U;
	VAR (uint8, AUTOMATIC) NrOfCrcRegn_Cnt_T_u08 ;
	VAR (sint32, AUTOMATIC) TempCrcFlsBlkLen_Cnt_T_s32;
	
	for (NrOfCrcRegn_Cnt_T_u08 = 0U; NrOfCrcRegn_Cnt_T_u08 < NROFFLSCRCREGNS_CNT_U08; NrOfCrcRegn_Cnt_T_u08++)
	{
        TempCrcFlsBlkLen_Cnt_T_s32 = (sint32)FlsCfgTbl[NrOfCrcRegn_Cnt_T_u08].CrcFlsBlkLen;
		
	    while(TempCrcFlsBlkLen_Cnt_T_s32 > 0)
		{
		    NrOfChPerRegn_Cnt_T_u08++;
		    TempCrcFlsBlkLen_Cnt_T_s32 -= (sint32)FLSBLKLEN_CNT_U32;
		}
		
		while(0U < NrOfChPerRegn_Cnt_T_u08 )
		{
			DTSMstrCfg[ChNr_Cnt_T_u08].DTSnnnCM.UINT32 = ((uint32)CPU1PEID_CNT_U32 << 20)
														| ((uint32)CODFLSTOCRCSPID_CNT_U32 << 18)
														| ((uint32)USRMODDIS_CNT_U32 << 17);
			/* Clear the DTSFSL transfer request bit */
			DTSCfg[ChNr_Cnt_T_u08].DMASSDTFSC.BIT.DRQC = (uint32)1U;
		
			/* Start address of the block */
			DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTSA.UINT32 = (uint32)((FlsCfgTbl[NrOfCrcRegn_Cnt_T_u08].CrcFlsBlkStrtAdr+
														(Loop_Cnt_T_u08 * FLSBLKLEN_CNT_U32))) ;
			
			/* Destination address is the CRC input register address which shall be 
			returned by the Reserve CRC function */
			DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTDA.UINT32 = CrcHwIdxInReg;
			
			/* Set the count register with 0xFFFF if there is a chain down for the 
			block of flash. If not get the length of the transfer block in the 
			last chain and set it in the transfer count register */
			if(1U == NrOfChPerRegn_Cnt_T_u08 )
			{
				DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTTC.UINT32 = 
								(uint32)((FlsCfgTbl[NrOfCrcRegn_Cnt_T_u08].CrcFlsBlkLen - (Loop_Cnt_T_u08 *FLSBLKLEN_CNT_U32))/DTSDATALEN_CNT_U32);
			}
			else
			{
				DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTTC.UINT32 = 
								(uint32)(FLSBLKLEN_CNT_U32/DTSDATALEN_CNT_U32);
			}
			
			DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTTCT.UINT32 = ((uint32)0x00U << 28)				/* Reserved */
											|	((uint32)0x00U << 27)				/* DMA transfer when transfer errored */
											|	(((uint32)((uint32)ChNr_Cnt_T_u08 +1U)<< 18)	/* Next Channel in Chain */
											|	((uint32)0x01U << 16))				/* Chain Enable: Chain at last Transfer */
											|	((uint32)0x00U << 15)				/* Disable - Transfer count match interrupt  */
											|	((uint32)0x00U << 14)				/* Disable - Transfer completion interrupt  */
											|	((uint32)0x00U << 11)				/* Disable -Reload function 2 */
											|	((uint32)0x00U << 9)				/* Disable- Reload Function 1 */
											|	((uint32)0x02U << 7)				/* Fixed -Destinable address count direction */
											|	((uint32)0x00U << 5)				/* Increment - Source Address count direction */
											|	((uint32)0x02U << 2)				/* Transfer Data Size - 32 bits */
											|	((uint32)0x01U << 0);				/* Block transfer 1 by transfer count */


			/* Enable - Channel Operation */
			DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTFSL.BIT.REQEN = (uint32)1U;
			
			NrOfChPerRegn_Cnt_T_u08--;
			/* Next Chain in DTS */
			ChNr_Cnt_T_u08++;
			
			Loop_Cnt_T_u08++;
		}
		
		Loop_Cnt_T_u08 = 0U;
		
		/* DTS to transfer the Data from the CRC module to the local RAM*/
		DTSMstrCfg[ChNr_Cnt_T_u08 ].DTSnnnCM.UINT32 = ((uint32)CPU1PEID_CNT_U32 << 20)
												| ((uint32)CRCTOLCLRAMSPID_CNT_U32 << 18)
												| ((uint32)USRMODDIS_CNT_U32 << 17);
		/* Clear the DTSFSL transfer request bit */
		DTSCfg[ChNr_Cnt_T_u08].DMASSDTFSC.BIT.DRQC = (uint32)1U;

		/* Start address of the DTS transfer is the CRC HW output address*/
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTSA.UINT32 = CrcHwIdxOutReg;   
		
		/* Destination address is the destination register address where 
		the calculated CRC shall be saved */
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTDA.UINT32 = (uint32)&(HwCrcCalcdRes_C[NrOfCrcRegn_Cnt_T_u08]);
		
		/* Transfer Count is one 32 bit CRC data */
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTTC.UINT32 = (uint32)0x1U;
		
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTTCT.UINT32 = 	((uint32)0x00U << 28)				/* Reserved */
											|	((uint32)0x00U << 27)				/* DMA transfer when transfer errored */
											|	((uint32)((uint32)ChNr_Cnt_T_u08 +1U)<< 18)		/* Next Channel in Chain */
											|	((uint32)0x01U << 16)				/* Chain Enable */
											|	((uint32)0x00U << 15)				/* Disable - Transfer count match interrupt  */
											|	((uint32)0x00U << 14)				/* Disable - Transfer completion interrupt  */
											|	((uint32)0x00U << 11)				/* Disable -Reload function 2 */
											|	((uint32)0x00U << 9)				/* Disable- Reload Function 1 */
											|	((uint32)0x02U << 7)				/* Fixed -Destinable address count direction */
											|	((uint32)0x00U << 5)				/* Increment - Source Address count direction */
											|	((uint32)0x02U << 2)				/* Transfer Data Size - 32 bits */
											|	((uint32)0x01U << 0);				/* Block transfer 1 by transfer count */
		
		/* Enable - Channel Operation */	
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTFSL.BIT.REQEN = (uint32)1U;
		/* Next Chain in DTS */
		ChNr_Cnt_T_u08 ++;

		/* DTS to clear the CRC hardware registers by transferring data from 
		a Zero Array to the CRC registers*/
		DTSMstrCfg[ChNr_Cnt_T_u08 ].DTSnnnCM.UINT32 = ((uint32)CPU1PEID_CNT_U32 << 20)
					| ((uint32)CODFLSTOCRCSPID_CNT_U32 << 18)
					| ((uint32)USRMODDIS_CNT_U32 << 17);
		/* Clear the DTSFSL transfer request bit */
		DTSCfg[ChNr_Cnt_T_u08].DMASSDTFSC.BIT.DRQC = (uint32)1U;
					
		/* Start address of the DTS transfer is the Zero Constant address*/
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTSA.UINT32 = (uint32)&(CrcClrData_M);  
		
		/* Destination address is the output CRC Register Address */
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTDA.UINT32 = CrcHwIdxOutReg;	
		
		/* Transfer Count is 1 for the Output Register of the CRC HW */
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTTC.UINT32 = (uint32)0x1U;
		
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTTCT.UINT32 = 	((uint32)0x00U << 28)				/* Reserved */
											|	((uint32)0x00U << 27)				/* DMA transfer when transfer errored */
											|	((uint32)((uint32)ChNr_Cnt_T_u08 +1U)<< 18)		/* Next Channel in Chain */
											|	((uint32)0x01U << 16)				/* Chain Enable */
											|	((uint32)0x00U << 15)				/* Disable - Transfer count match interrupt  */
											|	((uint32)0x00U << 14)				/* Disable - Transfer completion interrupt  */
											|	((uint32)0x00U << 11)				/* Disable -Reload function 2 */
											|	((uint32)0x00U << 9)				/* Disable- Reload Function 1 */
											|	((uint32)0x02U << 7)				/* Fixed -Destinable address count direction */
											|	((uint32)0x00U << 5)				/* Increment - Source Address count direction */
											|	((uint32)0x02U << 2)				/* Transfer Data Size - 32 bits */
											|	((uint32)0x01U << 0);				/* Block transfer 1 by transfer count */
		
		/* Enable - Channel Operation */
		DTSCfg[ChNr_Cnt_T_u08 ].DMASSDTFSL.BIT.REQEN = 1U;
		/* Next Chain in DTS */
		ChNr_Cnt_T_u08++;
	}

	DTSCfg[ChNr_Cnt_T_u08  -1U].DMASSDTTCT.BIT.CHNE = 	0U	;			/* Chain Disable */
	DTSCfg[ChNr_Cnt_T_u08  -1U].DMASSDTTCT.BIT.TCE  = 	1U	;			/* Enable - Transfer completion interrupt on last transfer  */

	/* Clear the DTS Interrupt flag */
	INTIFPINTCLR0 = 0xFFFFFFFFU;
	/* Start transfer from the first chain */
	DTSCfg[0U].DMASSDTFSS.BIT.DRQS = 1U;
}

/**********************************************************************************************************************
  * Name:        CodFlsSngBitEcc
  * Description: Code flash Ecc Single bit error handler
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called from FlsMemPer2
                 Need to run in Supervisor mode
  ********************************************************************************************************************/
FUNC(void, CDD_FlsMem_CODE) CodFlsSngBitEcc(void) 
{
	VAR(uint32, AUTOMATIC) CodFlsErrAdr_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) RegVal_Cnt_T_u32;
	VAR(uint8, AUTOMATIC)  LoopCntr_Cnt_T_u08;
    P2VAR(uint32, AUTOMATIC, AUTOMATIC)ChkAdr_Cnt_T_u32;
	#if(MCUDIAGCERRINJ == STD_ON)
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	#endif	
	SuspendAllInterrupts();

	*Rte_Pim_CodFlsSngBitErr() = TRUE;

	/* Clear the Error from ECM Status Register */
	RegVal_Cnt_T_u32 = 0x00000010U;
	WrProtdRegEcm_u32 (RegVal_Cnt_T_u32, &ECMESSTC1);
		
	if(ECCFLICFOVFSTR_PE1 != 0U)
	{
		/* Save Address for debug purpose */
		CodFlsErrAdr_Cnt_T_u32 = ECCFLICF1STEADR0_PE1;
		/* Overflow detected do a software reset */
		NxtrSwRstFromExcpn(MCUDIAGC_CODFLSSNGBITHARDFLT, CodFlsErrAdr_Cnt_T_u32);
	}
	else if((ECCFLICF1STERSTR_PE1 & 0x00000001U) !=0U)
	{
		CodFlsErrAdr_Cnt_T_u32 = ECCFLICF1STEADR0_PE1;

        /* Read back memories from addresses having the same word line (bits 20-9) and different 
        * column line (bits 8-4) as the SED address (Caution: exclude SED address itself)
        * Address generation form SED address: XOR with 0x80, 0x40, 0x20, 0x10 */
        for (LoopCntr_Cnt_T_u08 = 0U;LoopCntr_Cnt_T_u08 < NROFADRCHK_CNT_U08 ; LoopCntr_Cnt_T_u08++)
        {
            ChkAdr_Cnt_T_u32 = (uint32*)(CodFlsErrAdr_Cnt_T_u32 ^ (ERRADRMASK_CNT_U32 >> LoopCntr_Cnt_T_u08));
            switch (LoopCntr_Cnt_T_u08)
            {
                case READADRCASE0_CNT_U08:
                    *Rte_Pim_CodFlsDummyRead1() = *ChkAdr_Cnt_T_u32;
                break;

                case READADRCASE1_CNT_U08:
                    *Rte_Pim_CodFlsDummyRead2() = *ChkAdr_Cnt_T_u32;
                break;

                case READADRCASE2_CNT_U08:
                    *Rte_Pim_CodFlsDummyRead3() = *ChkAdr_Cnt_T_u32;
                break;
                
                default: /* case READADRCASE3_CNT_U08 */
                    #if (MCUDIAGCERRINJ == STD_ON)
                    if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT01CASE03_CNT_U32)
                    {
                        /* Clear BRAMDAT2 Register */
                        ClrErrInjReg_Oper();
                        /* A Code Flash uncorrectable ECC generates a SYSERR after a executing a few instructions in the pipeline.
                        Therefore, the error injection statement has to be the first address to be read to prevent clearing 
                        of the status register as soon as injecting the error in the last dummy ready statement read 
                        from ECC Test Area. Use address which causes intentional ECC 2-bit error injection. */
                        *Rte_Pim_CodFlsDummyRead4() = *(uint32*)MCUERRINJ_DBLBITECCERRADR_CNT_U32;
                    }
                    else
                    {
                        *Rte_Pim_CodFlsDummyRead4() = *ChkAdr_Cnt_T_u32; 
                    }
                    #else
                    *Rte_Pim_CodFlsDummyRead4() = *ChkAdr_Cnt_T_u32;
                    #endif
                break;
            }
        }
        __SYNCM();
        __SYNCI();
        /* Check if a double bit error has occurred in case the error has still not propagated to the SYSERR yet*/
        if((ECCFLICF1STERSTR_PE1 & 0x00000002U) != 0x02U)
        {
            /* Clear the Error from CF Status Register */
            ECCFLICFSTCLR_PE1 = 0x00000001U;
        }

	}
	else
	{
		/* Do Nothing */
	}
	if(ECCFLICFOVFSTR_VCI != 0u)
	{
		/* Save Address for debug purpose */
		CodFlsErrAdr_Cnt_T_u32 = ECCFLICF1STEADR0_VCI;
		/* Overflow detected do a software reset */
		NxtrSwRstFromExcpn(MCUDIAGC_CODFLSSNGBITHARDFLT, CodFlsErrAdr_Cnt_T_u32);
	}
	else if ((ECCFLICF1STERSTR_VCI & 0x00000001U) !=0U)
	{
		CodFlsErrAdr_Cnt_T_u32 = ECCFLICF1STEADR0_VCI;
        /* Read back memories from addresses having the same word line (bits 20-9) and different 
        column line (bits 8-4) as the SED address (Caution: exclude SED address itself)
        Address generation form SED address: XOR with 0x80, 0x40, 0x20, 0x10 */
        for (LoopCntr_Cnt_T_u08 = 0U;LoopCntr_Cnt_T_u08 < NROFADRCHK_CNT_U08 ; LoopCntr_Cnt_T_u08++)
        {
            ChkAdr_Cnt_T_u32 = (uint32*)(CodFlsErrAdr_Cnt_T_u32 ^ (ERRADRMASK_CNT_U32 >> LoopCntr_Cnt_T_u08));
            switch (LoopCntr_Cnt_T_u08)
            {
                case READADRCASE0_CNT_U08:
                    *Rte_Pim_CodFlsDummyRead1() = *ChkAdr_Cnt_T_u32;
                break;

                case READADRCASE1_CNT_U08:
                    *Rte_Pim_CodFlsDummyRead2() = *ChkAdr_Cnt_T_u32;
                break;

                case READADRCASE2_CNT_U08:
                    *Rte_Pim_CodFlsDummyRead3() = *ChkAdr_Cnt_T_u32;
                break;
                
                default: /* case READADRCASE3_CNT_U08 */
                    #if (MCUDIAGCERRINJ == STD_ON)
                    if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT01CASE04_CNT_U32)
                    {
                        /* Clear BRAMDAT2 Register */
                        ClrErrInjReg_Oper();
                        /* A Code Flash uncorrectable ECC generates a SYSERR after a executing a few instructions in the pipeline.
                        Therefore, the error injection statement has to be the first address to be read to prevent clearing 
                        of the status register as soon as injecting the error in the last dummy ready statement read 
                        from ECC Test Area. Use address which causes intentional ECC 2-bit error injection. */
                        *Rte_Pim_CodFlsDummyRead4() = *(uint32*)MCUERRINJ_DBLBITECCERRADR_CNT_U32;
                    }
                    else
                    {
                        *Rte_Pim_CodFlsDummyRead4() = *ChkAdr_Cnt_T_u32 ;
                    }
                    #else
                    *Rte_Pim_CodFlsDummyRead4() = *ChkAdr_Cnt_T_u32;
                    #endif
                break;
            }
        }
        __SYNCM();
        __SYNCI();
        /* Check if a double bit error has occurred in case the error has still not propagated to the SYSERR yet*/
        if((ECCFLICF1STERSTR_PE1 & 0x00000002U) != 0x02U)
        {
            /* Clear the Error from CF Status Register */
            ECCFLICFSTCLR_VCI = 0x00000001U;
            /* Clear the Error from CF Status Register */
            ECCFLICFSTCLR_PE1 = 0x00000001U;
        }
    }
	else
	{
		/* Do Nothing */
	}
	
	ResumeAllInterrupts();

}

#if (MCUDIAGCERRINJ == STD_ON)
/**********************************************************************************************************************
  * Name:        InjCodFlsEccErr
  * Description: Non-RTE function for injecting ecc errors for code flash
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called on event from DF003
  ********************************************************************************************************************/
FUNC(void, CDD_FlsMem_CODE) InjCodFlsEccErr(void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	
	ReadErrInjReg_Oper (&ErrId_Cnt_T_u32);
	
	/* Single Bit Soft fault from CPU read */
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0002BIT00CASE01_CNT_U32)
	{
	    /* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable CF Address parity so inadvertently trigger it since it has a higher precedence */ 
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();
		McuDiagcTestVar1_G = *(uint32*)MCUERRINJ_SNGBITECCERRADR1_CNT_U32;
	}
	
	/* Single Bit Soft fault from DMA read */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0002BIT00CASE02_CNT_U32)
	{
	    /* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable CF Address parity so inadvertently trigger it since it has a higher precedence */
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();
		/* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
		DMASSDCEN8 = 	0x00000000U;
		DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32 << 4)
			| ((uint32)MCUERRINJ_PRPHLTOLCLRAMSPID_CNT_U32 << 2)
			| ((uint32)MCUERRINJ_USRMODDI_CNT_U32 << 1);
		DMASSDSA8 = MCUERRINJ_SNGBITECCERRADR1_CNT_U32;              /* CF Address */
		DMASSDDA8 = (uint32)(&( DmaWrDataVar_G));    /* Local RAM Address */
		DMASSDTC8 =   ((uint32)0x00U << 16)
			| ((uint32)0x01U << 0);
		DMASSDTCT8 = 	((uint32)0x00U << 27)
			|	((uint32)0x00U << 26)
			|	((uint32)0x00U << 18)
			|	((uint32)0x00U << 16)
			|	((uint32)0x00U << 15)
			|	((uint32)0x00U << 14)
			|	((uint32)0x01U << 13)
			|	((uint32)0x00U << 11)
			|	((uint32)0x00U << 9)
			|	((uint32)0x00U << 7)
			|	((uint32)0x00U << 5)
			|	((uint32)0x02U << 2)
			|	((uint32)0x01U << 0);

		DMASSDTFR8 =   ((uint32)0U << 1)
				|  ((uint32)0U << 0);
	
		/* enabling DMA channel should trigger the DMA transfer */
		DMASSDCEN8 = 0x00000001U;
		DMASSDCSTS8 = 0x00000001;
	}
	
	/* Single Bit Hard fault from CPU
	need to suspend all interrupts so that the ISR is not entered as soon as we read from the first memory location */
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT00CASE01_CNT_U32)
	{
		SuspendAllInterrupts();
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable CF Address parity so inadvertently trigger it since it has a higher precedence */
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();

		McuDiagcTestVar1_G = *(uint32*)MCUERRINJ_SNGBITECCERRADR1_CNT_U32;
		McuDiagcTestVar1_G = *(uint32*)MCUERRINJ_SNGBITECCERRADR2_CNT_U32;

		ResumeAllInterrupts();
	}
	
	/* Single Bit Hard fault from DMA
	need to suspend all interrupts so that the ISR is not entered as soon as we read from the first memory location */
	else if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT00CASE02_CNT_U32)
	{
	    /* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		SuspendAllInterrupts();
		/* Disable CF Address parity so inadvertently trigger it since it has a higher precedence */
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();

		/* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
		DMASSDCEN8 = 	0x00000000U;
		DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32 << 4)
			| ((uint32)MCUERRINJ_PRPHLTOLCLRAMSPID_CNT_U32 << 2)
			| ((uint32)MCUERRINJ_USRMODDI_CNT_U32 << 1);
		DMASSDSA8 = MCUERRINJ_SNGBITECCERRADR1_CNT_U32;              /* CF Address */
		DMASSDDA8 = (uint32)(&( DmaWrDataVar_G));    /* Local RAM Address */
		DMASSDTC8 =   ((uint32)0x00U << 16)
			| ((uint32)0x01U << 0);
		DMASSDTCT8 = 	((uint32)0x00U << 27)
			|	((uint32)0x00U << 26)
			|	((uint32)0x00U << 18)
			|	((uint32)0x00U << 16)
			|	((uint32)0x00U << 15)
			|	((uint32)0x00U << 14)
			|	((uint32)0x01U << 13)
			|	((uint32)0x00U << 11)
			|	((uint32)0x00U << 9)
			|	((uint32)0x00U << 7)
			|	((uint32)0x00U << 5)
			|	((uint32)0x02U << 2)
			|	((uint32)0x01U << 0);

		DMASSDTFR8 =   ((uint32)0U << 1)
				|  ((uint32)0U << 0);
	
		/* enabling DMA channel should trigger the DMA transfer */
		DMASSDCEN8 = 0x00000001U;
		DMASSDCSTS8 = 0x00000001;
		__SYNCM();
		
		/* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
		DMASSDCEN8 = 	0x00000000U;
		DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32 << 4)
			| ((uint32)MCUERRINJ_PRPHLTOLCLRAMSPID_CNT_U32 << 2)
			| ((uint32)MCUERRINJ_USRMODDI_CNT_U32 << 1);
		DMASSDSA8 = MCUERRINJ_SNGBITECCERRADR2_CNT_U32;              /* CF Address */
		DMASSDDA8 = (uint32)(&( DmaWrDataVar_G));    /* Local RAM Address */
		DMASSDTC8 =   ((uint32)0x00U << 16)
			| ((uint32)0x01U << 0);
		DMASSDTCT8 = 	((uint32)0x00U << 27)
			|	((uint32)0x00U << 26)
			|	((uint32)0x00U << 18)
			|	((uint32)0x00U << 16)
			|	((uint32)0x00U << 15)
			|	((uint32)0x00U << 14)
			|	((uint32)0x01U << 13)
			|	((uint32)0x00U << 11)
			|	((uint32)0x00U << 9)
			|	((uint32)0x00U << 7)
			|	((uint32)0x00U << 5)
			|	((uint32)0x02U << 2)
			|	((uint32)0x01U << 0);

		DMASSDTFR8 =   ((uint32)0U << 1)
				|  ((uint32)0U << 0);
	
		/* enabling DMA channel should trigger the DMA transfer */
		DMASSDCEN8 = 0x00000001U;
		DMASSDCSTS8 = 0x00000001;
		
		__SYNCM();
		ResumeAllInterrupts();
	}

	/* Double Bit fault from CPU */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT01CASE01_CNT_U32)
	{
	    /* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Disable CF Address parity so inadvertently trigger it since it has a higher precedence */
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();
		McuDiagcTestVar1_G = *(uint32*)MCUERRINJ_DBLBITECCERRADR_CNT_U32;
	}
	
	
	/* Double Bit fault from CPU during single bit classification check */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT01CASE03_CNT_U32)
	{
		/* Disable CF Address parity so inadvertently trigger it since it has a higher precedence */
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();

		/* ClrErrInjReg function is not called here because the ErrId is being used in the ISR
		Clearing happens in the ISR */
		McuDiagcTestVar1_G = *(uint32*)MCUERRINJ_SNGBITECCERRADR1_CNT_U32;
	}
	
	/* Double Bit fault from DMA during single bit classification check */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT01CASE04_CNT_U32)
	{
	    /* ClrErrInjReg function is not called here because the ErrId is being used in the ISR
		Clearing happens in the ISR */
		/* Disable CF Address parity so inadvertently trigger it since it has a higher precedence */
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();

		/* Set up DMA Channel 10 to do a DMA transfer from CF to LRAM as follows */
		DMASSDCEN8 = 	0x00000000U;
		DMASSDM10CM = ((uint32)MCUERRINJ_CPU1PEID_CNT_U32 << 4)
			| ((uint32)MCUERRINJ_PRPHLTOLCLRAMSPID_CNT_U32 << 2)
			| ((uint32)MCUERRINJ_USRMODDI_CNT_U32 << 1);
		DMASSDSA8 = MCUERRINJ_SNGBITECCERRADR1_CNT_U32;              /* CF Address */
		DMASSDDA8 = (uint32)(&( DmaWrDataVar_G));    /* Local RAM Address */
		DMASSDTC8 =   ((uint32)0x00U << 16)
			| ((uint32)0x01U << 0);
		DMASSDTCT8 = 	((uint32)0x00U << 27)
			|	((uint32)0x00U << 26)
			|	((uint32)0x00U << 18)
			|	((uint32)0x00U << 16)
			|	((uint32)0x00U << 15)
			|	((uint32)0x00U << 14)
			|	((uint32)0x01U << 13)
			|	((uint32)0x00U << 11)
			|	((uint32)0x00U << 9)
			|	((uint32)0x00U << 7)
			|	((uint32)0x00U << 5)
			|	((uint32)0x02U << 2)
			|	((uint32)0x01U << 0);

		DMASSDTFR8 =   ((uint32)0U << 1)
				|  ((uint32)0U << 0);
	
		/* enabling DMA channel should trigger the DMA transfer */
		DMASSDCEN8 = 0x00000001U;
		DMASSDCSTS8 = 0x00000001;
	}
	
	/* Address Parity fault from CPU
	Special Conditions:Execution from RAM must be enabled; current test is testing data access */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0003BIT02CASE01_CNT_U32)
	{
	    
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		__LDSR(24, 4, 0x00030002U);  /* ICCTRL = 0x00030002 */
		__SYNCI();
		(void) memcpy((void*)&McuDiagcTestAry_G, (void*)&AddressParityTestFunction, sizeof(McuDiagcTestAry_G));
		((void (*)(void))&McuDiagcTestAry_G)();

	}
	else
	{
		/* Do Nothing */
	}

}

static FUNC(void, CDD_McuDiagcTest_CODE) AddressParityTestFunction(void)
{
	ECCFLICFAPCTL = 0x00004002U;
	ECCFLICFAPCTL = AddressParityTestDisableVal_M;
	__asm("  jr 0x00");
}

#endif

#define CDD_FlsMem_STOP_SEC_CODE
#include "CDD_FlsMem_MemMap.h"

