/**********************************************************************************************************************
* Copyright 2015, 2016, 2017, 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_ExcpnHndlgNonRte.c 
* Module Description: Implements the non-RTE functionality of CM101A Exception Handling RH850
*                     Includes SetMcuDiagcIdnData and GetMcuDiagcIdnData server runnables
* Project           : CBD
* Author            : Kathleen Creager
***********************************************************************************************************************
* Version Control:
* %version:          13 %
* %derived_by:       nz4246 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  ----------------------------------------------------------------------------- ---------
* 09/11/15   1       KMC       Initial Version                                                               EA4#1832
* 11/20/15   2       LWW       Update for anomaly correction per FDD                                         EA4#2577
* 01/19/15   3       LWW       Updated for error and protection hook removal                                 EA4#3185
* 02/10/16	 4		 AJM       Updated for Clock monitor FENMI handling, 									 EA4#3765
							   Fault processing for Start up test of P Bus and PBG,Soft and Hard Reset Cases
* 03/22/16   5       AJM       Changed DTS RAM Double BIT ECC fault to SYSERR type from FENMI		  		 EA4#4632
* 04/05/16   6       AJM	   Added Mode error handlers, removed SPI Dbl bit Handler.SetMcuDiagcIdnData	 EA4#5099
							   function has been modified to update BRAMDAT0/1 in case of DBGRST also
* 02/11/17   7       AJM       Added micro diag error injection points                                       EA4#8355 
* 05/25/17   8       Shruthi   WdgMConfig structure name is now a #define in CDD_ExcpnHndlg_Cfg.h            EA4#11956 
* 07/20/17   9       AJM       Added few uDiag error cases and corrected others as per anomalies EA4#12488,
                               EA4#13613,EA4#12018                                                           EA4#13344
* 09/20/17   10      AJM       Added additional debug info for MPU exception and ECM master checker compare  EA4#15032
                               error.Added new reset cause check QUICKIGNRST in SetMcuDiagcIdnData
* 10/17/17   11      AJM       Removed compiler warning for local constant definition                        EA4#16352
* 03/29/18   12      AJM       Added handler for DTS single bit ECC errors and updating reset reason for     EA4#20984,EA4#21920
                               CUSTRST
* 06/27/18	 13		SLBecks	   Modified error case to use different address in CF; Updated test case to be   EA4#23559
*							   OS function call independent to directly write to ECI register INTC1EIC9					   
**********************************************************************************************************************/

#include <v800_ghs.h> /* for LDSR, STSR intrinsics */  
#include "Rte_CDD_ExcpnHndlg.h"
#include "CDD_ExcpnHndlg.h"
#include "CDD_ExcpnHndlg_private.h"
#include "CDD_ExcpnHndlg_Cfg.h"
#include "ram_regs.h" /* for BRAMDAT0, BRAMDAT1 */
#include "ecc_regs.h" /* for ECCCSIH0*, etc. */
#include "dma_regs.h" /* for DMASSDMACER */
#include "WdgM.h"
#include "WdgM_PBcfg.h" /* for declarations needed in distinguishing program flow, deadline monitor, and alive monitor faults */
#include "NxtrMcuSuprtLib.h" /* for NxtrSwRstFromExcpn(), WrProtdRegSys_u32() */
#include "McuErrInj.h" 

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define FPCFGININVAL_CNT_T_U32    0x0000001CU /* enable invalid operation, divide by zero, and overflow FPU exceptions */

/* system register register IDs and selection IDs */
#define FPCFGREGID_CNT_S32 		10	/* register ID of FPCFG */
#define FPCFGSELNID_CNT_S32 	0	/* selection ID of FPCFG */
#define REGFEPCREGID_CNT_S32 	2	/* register ID of FEPC */
#define REGFEPCSELNID_CNT_S32 	0	/* selection ID of FEPC */
#define MEAREGID_CNT_S32 		6	/* register ID of MEA */
#define MEASELNID_CNT_S32 	    2	/* selection ID of MEA */

#define CDD_ExcpnHndlg_START_SEC_CODE 
#include "CDD_ExcpnHndlg_MemMap.h"
/*****************************************************************************************************************
 * Name        :   ExcpnHndlgInit1
 * Description :   Pre-OS initialization for the CM101A ExcpnHandlg component 
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   Non-RTE function because it needs to be called before the OS is started - so
 *                 that floating point exceptions can be enabled before anything uses floating point
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) ExcpnHndlgInit1(void)
{
	/* configure floating point exceptions */
	__LDSR (FPCFGREGID_CNT_S32, FPCFGSELNID_CNT_S32, FPCFGININVAL_CNT_T_U32);

}

/*****************************************************************************************************************
 * Name        :   FeNmiPeg
 * Description :   PEG Exception Handling callback for the CM101A ExcpnHandlg component 
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiPeg(void)
{
	/* Identify reset cause and reset */
	NxtrSwRstFromExcpn(MCUDIAGC_PROCRELMGUARD, 0U);	
}

/*****************************************************************************************************************
 * Name        :   FeNmiDmaTrf
 * Description :   DMA Transfer Error exception handler callback for the CM101A ExcpnHandlg component 
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiDmaTrf(void)
{
	NxtrSwRstFromExcpn(MCUDIAGC_DMATRFERR, DMASSDMACER);
}

/*****************************************************************************************************************
 * Name        :   FeNmiDmaRegAcsProtnErr
 * Description :   DMA Register Access Protection Error exception handler callback for the CM101A ExcpnHandlg component 
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiDmaRegAcsProtnErr(void)
{
	NxtrSwRstFromExcpn(MCUDIAGC_DMAREGACSPROTCNERR, DMASSDMACER);
}

/*****************************************************************************************************************
 * Name        :   FeNmiEcmMstChkrCmp
 * Description :   ECM Master Checker Compare exception handler callback for the CM101A ExcpnHandlg component 
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiEcmMstChkrCmp(void)
{
    VAR (uint32, AUTOMATIC) FltInfo_Cnt_T_u32;
    FltInfo_Cnt_T_u32 = __STSR(REGFEPCREGID_CNT_S32,REGFEPCSELNID_CNT_S32);
	NxtrSwRstFromExcpn(MCUDIAGC_ECMMSTCHKRERR, FltInfo_Cnt_T_u32);
}

/*****************************************************************************************************************
 * Name        :   FeNmiWdg
 * Description :   Watchdog Exception Handler callback for the CM101A ExcpnHandlg component 
 * Inputs      :   None
 * Outputs     :   None
 * Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiWdg(void)
{
	VAR (McuDiagc1, AUTOMATIC) FltVal_Cnt_T_enum;
	VAR (uint32, AUTOMATIC) FltInfo_Cnt_T_u32;
	P2CONST (WdgM_ConfigType, AUTOMATIC, CDD_ExcpnHndlg_APPL_CONST) WdgCfgPtr_T_rec; 
    VAR (WdgM_SupervisedEntityIdType, AUTOMATIC) NumOfWdgMgrEnty; 
    VAR (WdgM_SupervisedEntityIdType, AUTOMATIC) EntyId; 
    P2CONST (WdgM_SupervisedEntityType, AUTOMATIC, CDD_ExcpnHndlg_APPL_CONST) EntyPtr_T_rec; 

    WdgCfgPtr_T_rec = &WDGMCFG_REC; 
	NumOfWdgMgrEnty = WdgCfgPtr_T_rec->NrOfSupervisedEntities;
	
	/* default to MCUDIAGC_FENMIWDG if no other violations found */
	FltVal_Cnt_T_enum = MCUDIAGC_FENMIWDG;
	FltInfo_Cnt_T_u32 = 0U;
	
	EntyId = 0U;
	
    /* For all configured Entities or until fault cause is found */
    while ((EntyId < NumOfWdgMgrEnty) && (FltVal_Cnt_T_enum == MCUDIAGC_FENMIWDG))
    {
        EntyPtr_T_rec  = &WdgCfgPtr_T_rec->WdgMSupervisedEntityRef[EntyId];
		if (EntyPtr_T_rec->EntityStatusGRef->ProgramFlowViolationCnt != 0U)
		{
			FltVal_Cnt_T_enum = MCUDIAGC_FENMIPROGFLOW;
			FltInfo_Cnt_T_u32 = (uint32)EntyId;
		}
		else if (EntyPtr_T_rec->EntityStatusGRef->FailedSupervisionRefCycles != 0U)
		{
			FltVal_Cnt_T_enum = MCUDIAGC_FENMIALVMONR;
			FltInfo_Cnt_T_u32 = (uint32)EntyId;
		}
		else if (EntyPtr_T_rec->EntityStatusGRef->DeadlineViolationCnt != 0U)
		{
			FltVal_Cnt_T_enum = MCUDIAGC_FENMIDEADLINEMONR;
			FltInfo_Cnt_T_u32 = (uint32)EntyId;
		}
		else
		{
			/* do nothing */
		}
		EntyId++;
	}
	
	NxtrSwRstFromExcpn(FltVal_Cnt_T_enum, FltInfo_Cnt_T_u32);
}

/*****************************************************************************************************************
* Name        :   SetMcuDiagcIdnData
* Description :   Implementation of SetMcuDiagcIdnData special function 
*                 Sets the reset reason and supporting information
* Inputs      :   McuDiagcData0_Arg - data to be saved in BRAMDAT0
*             :   McuDiagcData1_Arg - data to be saved in BRAMDAT1
* Outputs     :   BRAMDAT0 - global output - backup RAM used to save the reset reason
*             :   BRAMDAT1 - global output - backup RAM used to save additional supporting information
* Usage Notes :   This is a server runnable which may be called from both RTE and non-RTE functions, but calls 
*                 from RTE functions will look like library calls, i.e. will not use a client/server port.
*                 May be called multiple times but only updates data once per reset, except when setting
*                 a flash programming request which will always update the data
****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) SetMcuDiagcIdnData(McuDiagc1 McuDiagcData0_Arg, 
													uint32 McuDiagcData1_Arg)
{
	VAR(McuDiagc1, AUTOMATIC) RstInfo_Cnt_T_enum; 
	
	RstInfo_Cnt_T_enum = (McuDiagc1)BRAMDAT0;  /* copy current reset info from backup RAM */
	
	if ((McuDiagcData0_Arg == MCUDIAGC_FLSPROGMREQ) || 
		(RstInfo_Cnt_T_enum == MCUDIAGC_PWRONRST) || 
		(RstInfo_Cnt_T_enum == MCUDIAGC_DBGRST) ||		
		(RstInfo_Cnt_T_enum == MCUDIAGC_FLSPROGMCMPL) ||
		(RstInfo_Cnt_T_enum == MCUDIAGC_HARDRST) ||
		(RstInfo_Cnt_T_enum == MCUDIAGC_SOFTRST) ||
        (RstInfo_Cnt_T_enum == MCUDIAGC_QUICKIGNRST) ||
        (RstInfo_Cnt_T_enum == MCUDIAGC_CUSTRST)
		#if (MCUDIAGCERRINJ == STD_ON)
		||
		(RstInfo_Cnt_T_enum == MCUDIAGC_MCUDIAGCTEST)
		#endif
		)
	{
		BRAMDAT0 = McuDiagcData0_Arg;
		BRAMDAT1 = McuDiagcData1_Arg;
	}
}

/*****************************************************************************************************************
* Name        :   GetMcuDiagcIdnData
* Description :   Implementation of GetMcuDiagcIdnData special function 
*                 Gets the reset reason/pre-os error code
* Inputs      :   BRAMDAT0
* Outputs     :   *McuDiagcData0_Arg - reset reason / pre-os error code
* Usage Notes :   This is a server runnable which may be called from both RTE and non-RTE functions, but calls 
*                 from RTE functions will look like library calls, i.e. will not use a client/server port.
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) GetMcuDiagcIdnData(P2VAR(McuDiagc1, AUTOMATIC, ExcpnHndlg_APPL_VAR) McuDiagcData0_Arg) 
{
		*McuDiagcData0_Arg = BRAMDAT0;
}

/*****************************************************************************************************************
* Name        :   ProcUkwnExcpnErr
* Description :   Implementation of Process Unknown Exception Error
*                 Handles reaction to Unknown Exception
* Inputs      :   McuDiagcData1_Arg - fault error code argument
* Outputs     :   None
* Usage Notes :   This is a server runnable which is expected to be called by the Os Error Handler (non-RTE context)
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) ProcUkwnExcpnErr(uint32 McuDiagcData1_Arg) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_UKWNEXCPN, McuDiagcData1_Arg);
}

/*****************************************************************************************************************
* Name        :   ProcMpuExcpnErr
* Description :   Implementation of Process MPU Exception Error
*                 Handles reaction to Memory Protection Violation
* Inputs      :   McuDiagcData1_Arg - fault error code argument/updated with the error address
* Outputs     :   None
* Usage Notes :   This is a server runnable which is expected to be called by the Os Error Handler (non-RTE context)
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) ProcMpuExcpnErr(uint32 McuDiagcData1_Arg) 
{
    McuDiagcData1_Arg = __STSR(MEAREGID_CNT_S32,MEASELNID_CNT_S32);
	NxtrSwRstFromExcpn(MCUDIAGC_MPU, McuDiagcData1_Arg);
}

/*****************************************************************************************************************
* Name        :   ProcPrvlgdInstrExcpnErr
* Description :   Implementation of Process Privileged Instruction Exception Error
*                 Handles reaction to Privileged Instruction Exception
* Inputs      :   McuDiagcData1_Arg - fault error code argument
* Outputs     :   None
* Usage Notes :   This is a server runnable which is expected to be called by the Os Error Handler (non-RTE context)
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) ProcPrvlgdInstrExcpnErr(uint32 McuDiagcData1_Arg) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_PRVLGDINSTREXCPN, McuDiagcData1_Arg);
}

/*****************************************************************************************************************
* Name        :   ProcPrmntOsErr
* Description :   Implementation of Process Permanent OS Error
*                 Handles reaction to Permanent OS Errors
* Inputs      :   McuDiagcData1_Arg - fault error code argument
* Outputs     :   None
* Usage Notes :   This is a server runnable which is expected to be called by the Os Error Handler (non-RTE context)
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) ProcPrmntOsErr(uint32 McuDiagcData1_Arg) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_PRMNTOSERR, McuDiagcData1_Arg);
}

/*****************************************************************************************************************
* Name        :   ProcNonCritOsErr
* Description :   Implementation of Process Non Critical OS Error
*                 Handles reaction to Non Critical OS Errors
* Inputs      :   McuDiagcData1_Arg - fault error code argument
* Outputs     :   ExcpnHndlgOsErrCod_C - error code variable polled in a periodic function
* Usage Notes :   This is a server runnable which is expected to be called by the Os Error Handler (non-RTE context)
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) ProcNonCritOsErr(uint32 McuDiagcData1_Arg) 
{
	ExcpnHndlgOsErrCod_C = (uint16)McuDiagcData1_Arg;
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr0RtLowrLimFlt
* Description :   Clock Monitor 0 Runtime Lower Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr0RtLowrLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR0RTLOWRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr0RtUpprLimFlt
* Description :   Clock Monitor 0 Runtime Upper Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr0RtUpprLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR0RTUPPRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr1RtLowrLimFlt
* Description :   Clock Monitor 1 Runtime Lower Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr1RtLowrLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR1RTLOWRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr1RtUpprLimFlt
* Description :   Clock Monitor 1 Runtime Upper Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr1RtUpprLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR1RTUPPRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr2RtLowrLimFlt
* Description :   Clock Monitor 2 Runtime Lower Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr2RtLowrLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR2RTLOWRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr2RtUpprLimFlt
* Description :   Clock Monitor 2 Runtime Upper Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR)
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr2RtUpprLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR2RTUPPRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr3RtLowrLimFlt
* Description :   Clock Monitor 3 Runtime Lower Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component..
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr3RtLowrLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR3RTLOWRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiClkMonr3RtUpprLimFlt
* Description :   Clock Monitor 3 Runtime Upper Limit Failure exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiClkMonr3RtUpprLimFlt(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_CLKMONR3RTUPPRLIMFLT,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiOperModErrSngChipInactv
* Description :   Single Chip Mode in Single chip mode inactive exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
 FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiOperModErrSngChipInactv(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_OPERMODERRSNGCHIPINACTV,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiOperModErrFlsProgmModStrtd
* Description :   Flash programming Mode in Single chip mode active exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
 FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiOperModErrFlsProgmModStrtd(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_OPERMODERRFLSPROGMMODSTRTD,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiOperModErrTestModStrtd
* Description :   Test Mode in Single chip mode active exception handler callback for the CM101A 
				  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
 FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiOperModErrTestModStrtd(void) 
{
	NxtrSwRstFromExcpn(MCUDIAGC_OPERMODERRTESTMODSTRTD,0U);
}

/*****************************************************************************************************************
* Name        :   FeNmiDtsEccSngBitErr
* Description :   DTS single bit ECC error exception handler callback for the CM101A  ExcpnHandlg component.
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from Mcu FENMI interrupt handler MCU_FEINT_ISR
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) FeNmiDtsEccSngBitErr(void) 
{
    /* Do a software Reset with reset reason as DTS single bit error and error information from DMASSDTSER2 register */
	NxtrSwRstFromExcpn(MCUDIAGC_DTSECCSNGBITERR,DMASSDTSER2);
}

#if (MCUDIAGCERRINJ == STD_ON)
/*****************************************************************************************************************
* Name        :   InjMcuRtErr
* Description :   Inject run time micro diagnostic faults
				  .
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjMcuRtErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT00CASE01_CNT_U32)
	{
		/* CPU Core Miscompare */
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		TESTCOMPREG0 = 0x11111111U;
		TESTCOMPREG1 = 0X22222222U;
		/* According to SAN, a Read is required to induce a CPU Lockstep Fault */
		McuDiagcTestVar1_G = TESTCOMPREG0;
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT00CASE02_CNT_U32)
	{
		/* Clear the PDMA register to inject error by writing 0 and the protection bits*/
		PDMACOMPPDMA_COMP_CNTRL = 0x80000000U;
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* According to SAN, writing this value will generate an error that is flagged as compare error in the ECM */
		PDMACOMPPDMA_COMP_CNTRL = 0xBFFF070FU;
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT02CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		asm(" rie");
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT03CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_G = *(uint32*)((uint32)&osGlobalShared_StartAddr + 1U);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT04CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		*(uint32*)((uint32)&osGlobalShared_StartAddr + 1U) = 0U;
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT05CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		ECCFLICFAPCTL = 0x00004001U;
		__LDSR(24, 13, 0x00000000U);
		__SYNCM();
		asm(" jmp 0x0100A8B0[r0]");
	}	
	/* Special Conditons:
	MPU settings need to be configured to remove protection on these MPU regions for Interconnect reserved area test: 0x02240xx
	The effect of not doing so will result in an MPU violation. */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT06CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		*(uint32 *)0xFFFF0000U = 0U;
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT06CASE02_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		*(uint32 *)0xFFFE0000U = 0U;
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT06CASE03_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		*(uint32 *)0xFB000000U = 0U;
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT06CASE04_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		*(uint32 *)0xF3000000U = 0U;
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT07CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_G = *(uint32 *)0xFFFF7900U;
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjPbgRtErr
* Description :   Inject PBG run time error
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjPbgRtErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);

	if (ErrId_Cnt_T_u32 == MCUERRINJ_NTC0022BIT01CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_G = INTC2EIC32;
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjModErr
* Description :   Inject run time micro controller mode errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjModErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0024BIT00CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Induce Flash Programming Mode Fault  */
		WrProtdRegEcm_u32 (ECMPE0 | 0x00200000U, &ECMPE0);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0024BIT01CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Induce Test Mode Fault  */
		WrProtdRegEcm_u32 (ECMPE0 | 0x00400000U, &ECMPE0);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0024BIT02CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Induce Single Chip Mode Fault  */
		WrProtdRegEcm_u32 (ECMPE0 | 0x00800000U, &ECMPE0);
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjMemProtnErr
* Description :   Inject run time memory protection errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjMemProtnErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	/* Inject Privileged Instruction Execution Error */
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0025BIT01CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_G = __STSR(0,0);
	}
	/* MPU Violation (this convers MDP and MIP Exception)
	This tests assumes that code flash ends at 0x00100000 and that the MPU is blocking read access by the CPU from this memory */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0025BIT00CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_G = *(uint32*)0x01008004U;
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjFpuErr
* Description :   Inject run time floating point errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjFpuErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	static volatile VAR(float32, AUTOMATIC) McuDiagcTestVar1_F;
	static volatile VAR(float32, AUTOMATIC)McuDiagcTestVar2_F;
	
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	/* Floating Point Invalid Operation */
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0028BIT01CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_F = -4294967298.0F;
		McuDiagcTestVar1_G = (uint32)McuDiagcTestVar1_F;
	}
	/* Division: 0/0 */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0028BIT01CASE02_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_F = 0.0F;
		McuDiagcTestVar2_F = 0.0/McuDiagcTestVar1_F;
	}
	/* High float value greater than integer max casted to an integer */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0028BIT01CASE03_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_F = FLT_MAX;
		McuDiagcTestVar1_G = (uint32)McuDiagcTestVar1_F;
	}
	/* Floating Point Divide By Zero */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0028BIT02CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_F = 0.0F;
		McuDiagcTestVar2_F = 2.0F / McuDiagcTestVar1_F;
	}
	/* Floating Point Overflow */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0028BIT03CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		McuDiagcTestVar1_F = FLT_MAX;
		McuDiagcTestVar2_F = (McuDiagcTestVar1_F * McuDiagcTestVar1_F);
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjProgSeqErr
* Description :   Inject Program Sequence errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjProgSeqErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC002ABIT00CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Program Flow error */
		WdgM_CheckpointReached(0U,0U);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC002ABIT02CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Alive monitoring error */
		CancelAlarm(0U);
	}
	else
	{
		/* Do Nothing */
	}
}
/*****************************************************************************************************************
* Name        :   InjWdgErr
* Description :   Inject watchdog errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjWdgErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC002CBIT00CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Mask the watchdog ISR from execution */
		INTC1EIC9 |= 0x0080U;
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjOsPrmntGenericRtErr
* Description :   Inject operating system permanent generic errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjOsPrmntGenericRtErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	/* This is not a comprehensive test. Assumptions: this test is dependent on the OS */
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0030BIT00CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Trying to set a non-existent register */
		osSetIMRmEI(65535U);
	}
	/* This test assumes that FETRAP exception is not being purposely used and is mapped to the unhandled exception handler */
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0030BIT01CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		asm(" fetrap 1");
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjOsTmpGenericRtErr
* Description :   Inject operating system temporary generic errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjOsTmpGenericRtErr (void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	/* This is not a comprehensive test. Assumptions: this test is dependent on the OS
	This test assumes that there will never be 255 tasks in a system (i.e. task with ID 255 will always be invalid) */
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0031BIT00CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Activating a task that does not exist */
		ActivateTask(255U);
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjClkMonrErr
* Description :   Inject clock monitor run time errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjClkMonrErr(void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0023BIT02CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Clock Monitor Test Register */
		WrProtdRegSysClmac_u32 (CLMACCLMATEST | 0x0000000AU, &CLMACCLMATEST);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0023BIT03CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Pseudo Error Injection Register */
		WrProtdRegEcm_u32 (ECMPE0 | 0x00000010U, &ECMPE0);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0023BIT06CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Clock Monitor Test Register */
		WrProtdRegSysClmac_u32 (CLMACCLMATEST | 0x00000022U, &CLMACCLMATEST);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0023BIT07CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Pseudo Error Injection Register */
		WrProtdRegEcm_u32 (ECMPE0 | 0x00000040U, &ECMPE0);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0027BIT02CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Clock Monitor Test Register */
		WrProtdRegSysClmac_u32 (CLMACCLMATEST | 0x00000012U, &CLMACCLMATEST);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0027BIT03CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Pseudo Error Injection Register */
		WrProtdRegEcm_u32 (ECMPE0 | 0x00000100U, &ECMPE0);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0027BIT06CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Clock Monitor Test Register */
		WrProtdRegSysClmac_u32 (CLMACCLMATEST | 0x00000042U, &CLMACCLMATEST);
	}
	else if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0027BIT07CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Inject error by writing to Pseudo Error Injection Register */
		WrProtdRegEcm_u32 (ECMPE0 | 0x00000400U, &ECMPE0);
	}
	else
	{
		/* Do Nothing */
	}
}

/*****************************************************************************************************************
* Name        :   InjMcuVltgMonrErr
* Description :   Inject voltage monitor errors
* Inputs      :   None
* Outputs     :   None
* Usage Notes :   Called from McuErrInj for micro diagnostic testing
 ****************************************************************************************************************/
FUNC(void, CDD_ExcpnHndlg_CODE) InjMcuVltgMonrErr(void)
{
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == MCUERRINJ_NTC0049BIT00CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* induce CVM diagnostic overvoltage */
		WrProtdRegSys_u08(0x08U, &SYSCVMDIAG); 
	}
	else if(ErrId_Cnt_T_u32== MCUERRINJ_NTC0049BIT01CASE01_CNT_U32)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* induce CVM diagnostic undervoltage */
		WrProtdRegSys_u08(0x04U, &SYSCVMDIAG); 
	}
	else
	{
		/* Do Nothing */
	}
}
#endif

#define CDD_ExcpnHndlg_STOP_SEC_CODE 
#include "CDD_ExcpnHndlg_MemMap.h"
