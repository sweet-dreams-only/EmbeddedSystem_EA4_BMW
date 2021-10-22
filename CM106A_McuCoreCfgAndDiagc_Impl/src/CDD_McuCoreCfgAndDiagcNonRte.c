/**********************************************************************************************************************
* Copyright 2015, 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name: CDD_McuCoreCfgAndDiagcNonRte.c
* Module Description: Mcu Core Configuration and Diagnostics Complex Driver NonRte Functionality
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          4 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/19/15  1        LWW       Initial Version                                                                 EA4#1848
* 02/24/16	2		 AJM       Replaced GetMcuDiagcData with ChkForStrtUpTest to check for 					   EA4#3981	
							   start up test condition
* 04/04/16	3		 Selva     Replaced ChkForStrtUpTest with  GetMcuDiagcData on PWRRST 				       EA4#5095
							    in Init1
* 11/21/16	4		 AJM       Conditionally compiled micro diag fault injection                               EA4#8365
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include <v800_ghs.h>
#include "Rte_CDD_McuCoreCfgAndDiagc.h"
#include "CDD_McuCoreCfgAndDiagc.h"
#include "NxtrMcuSuprtLib.h"
#include "CDD_ExcpnHndlg.h"
#include "sys_regs.h"
#include "ecm_regs.h"
#include "lockstep_regs.h"
#include "McuErrInj.h"
 
/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/
#define CDD_McuCoreCfgAndDiagc_STOP_SEC_CODE
#include "CDD_McuCoreCfgAndDiagc_MemMap.h"

/**********************************************************************************************************************
  * Name:        McuCoreCfgAndDiagcInit1
  * Description: Non-RTE initialization function checking BIST results
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at appropriate time during initialization prior to the O/S starting
  ********************************************************************************************************************/
FUNC(void, CDD_McuCoreCfgAndDiagc_CODE) McuCoreCfgAndDiagcInit1(void)
{
	VAR(McuDiagc1, AUTOMATIC) DiagcIdn_Cnt_T_enum;
	VAR(uint32, AUTOMATIC) SYSDEBUGMODE_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSDEBUGMODEB_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ECMMSSE109_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ECMCSSE109_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ECMMSSE108_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ECMCSSE108_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSBISTRESULT_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSBISTRESULTB_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSLBISTSIG1_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSLBISTREF1_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSLBISTSIG2_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSLBISTREF2_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSMBISTREF_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSMBISTSIG_Cnt_T_u32;
	#if(MCUDIAGCERRINJ == STD_ON)
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	#endif
	
	GetMcuDiagcIdnData(&DiagcIdn_Cnt_T_enum);

	#if (MCUDIAGCERRINJ == STD_ON)
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);

	/* This Error injection has to be performed before the Interrupt Vector table jumps from R Base to E 
	base.The jump happens when the OS is initialized. McuCoreCfgAndDiagcInit1 is run before the InitOS 
	functions is called and hence the test is placed in this part of the start up sequence. */

	if (ErrId_Cnt_T_u32 == 0x00294001U)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper();
		/* Read from a mis-aligned address which causes MPU violation to create PreOS Exception */
		*(uint32*)((uint32)&osGlobalShared_StartAddr) = *(uint32*)((uint32)&osGlobalShared_StartAddr + 1U);
	}
	if (ErrId_Cnt_T_u32 == 0x00294004U)
	{
		/* Clear BRAMDAT2 Register */
		ClrErrInjReg_Oper ();
		/* Generate SYSERR by reading Test area of CF 2 Bit ECC */
		McuDiagcTestVar1_G = *(uint32*)0x0100A8B0U;
	}
	#endif
	
	/* Only Run test on Power-On-Reset when not in Debug Mode */
	SYSDEBUGMODE_Cnt_T_u32 = SYSDEBUGMODE;
	SYSDEBUGMODEB_Cnt_T_u32 = SYSDEBUGMODEB;

	
	if (((MCUDIAGC_PWRONRST == DiagcIdn_Cnt_T_enum) 
	#if(MCUDIAGCERRINJ == STD_ON)
		||(MCUDIAGC_MCUDIAGCTEST == DiagcIdn_Cnt_T_enum)
	#endif
		)&&
		((SYSDEBUGMODE_Cnt_T_u32 == 0U) || (SYSDEBUGMODEB_Cnt_T_u32 == 1U)))
	{
		#if(MCUDIAGCERRINJ == STD_ON)
		/* Inject Error by setting the corresponding bit in ECMPEn for BIST 1 Bit ECC */
		if(ErrId_Cnt_T_u32 == 0x00210101U)
		{
			/* Clear BRAMDAT2 Register */
			ClrErrInjReg_Oper();
			WrProtdRegEcm_u32 (0x00000100U,&ECMPE1);
		}
		/* Inject Error by setting the corresponding bit in ECMPEn for BIST 2 Bit ECC */
		if(ErrId_Cnt_T_u32 == 0x00210102U)
		{
			/* Clear BRAMDAT2 Register */
			ClrErrInjReg_Oper();
			WrProtdRegEcm_u32 (0x00000200U,&ECMPE1);
		}
		#endif
		ECMMSSE109_Cnt_T_u32 = ECMMSSE109;
		ECMCSSE109_Cnt_T_u32 = ECMCSSE109;
		ECMMSSE108_Cnt_T_u32 = ECMMSSE108;
		ECMCSSE108_Cnt_T_u32 = ECMCSSE108;
		
		/* Check if 2/1 Bit ECC Error occurred during BIST execution */
		if ((1U == ECMMSSE109_Cnt_T_u32) || (1U == ECMCSSE109_Cnt_T_u32)|| (1U == ECMCSSE108_Cnt_T_u32) ||(1U == ECMMSSE108_Cnt_T_u32))
		{
			SetMcuDiagcIdnData(MCUDIAGC_BISTECCERR, 0U);
		}
		else
		{
			SYSBISTRESULT_Cnt_T_u32 = SYSBIST_RESULT;
			SYSBISTRESULTB_Cnt_T_u32 = SYSBIST_RESULTB;
			#if(MCUDIAGCERRINJ == STD_ON)
			/* Inject Error by faulting one of the result value to 0 */
			if(ErrId_Cnt_T_u32 == 0x00211001U)
			{
				/* Clear BRAMDAT2 Register */
				ClrErrInjReg_Oper();
				SYSBISTRESULT_Cnt_T_u32 = 0U;
				SYSBISTRESULTB_Cnt_T_u32 = 0U;
			}
			#endif
			/* At least one Register indicates BIST Completed Successfully */
			if ((SYSBISTRESULT_Cnt_T_u32 != 2U) && (SYSBISTRESULTB_Cnt_T_u32 != 5U))
			{
				SetMcuDiagcIdnData(MCUDIAGC_BISTNOTCMPLERR, 0U);
			}
			else
			{
				SYSLBISTSIG1_Cnt_T_u32 = SYSLBISTSIG1;
				SYSLBISTREF1_Cnt_T_u32 = SYSLBISTREF1;
				SYSLBISTSIG2_Cnt_T_u32 = SYSLBISTSIG2;
				SYSLBISTREF2_Cnt_T_u32 = SYSLBISTREF2;
				#if(MCUDIAGCERRINJ == STD_ON)
				/* Inject Error by faulting one of the result value to 0 */
				if(ErrId_Cnt_T_u32 == 0x00210401U)
				{
					/* Clear BRAMDAT2 Register */
					ClrErrInjReg_Oper();
					SYSLBISTREF1_Cnt_T_u32 = 0x000FFFFFU;
				}
				if(ErrId_Cnt_T_u32 == 0x00210402U)
				{
					/* Clear BRAMDAT2 Register */
					ClrErrInjReg_Oper();
					SYSLBISTREF2_Cnt_T_u32 = 0x000FFFFFU;
				}
				#endif
				/* Check if there were any errors during LBIST execution */
				if ((SYSLBISTSIG1_Cnt_T_u32 != SYSLBISTREF1_Cnt_T_u32) || (SYSLBISTSIG2_Cnt_T_u32 != SYSLBISTREF2_Cnt_T_u32))
				{
					SetMcuDiagcIdnData(MCUDIAGC_LOGLBISTERR, 0U);
				}
				else
				{
					SYSMBISTREF_Cnt_T_u32 = SYSMBISTREF;
					SYSMBISTSIG_Cnt_T_u32 = SYSMBISTSIG;
					#if(MCUDIAGCERRINJ == STD_ON)
					/* Inject Error by faulting one of the result value to 0 */
					if(ErrId_Cnt_T_u32 == 0x00100101U)
					{
						/* Clear BRAMDAT2 Register */
						ClrErrInjReg_Oper();
						SYSMBISTREF_Cnt_T_u32 = 0x000FFFFFU;
					}
					#endif
					/* Check if there were any errors during MBIST execution */
					if (SYSMBISTREF_Cnt_T_u32 != SYSMBISTSIG_Cnt_T_u32)
					{
						SetMcuDiagcIdnData(MCUDIAGC_MEMBISTERR, 0U);
					}
				}
			}
		}
	}
	
}

/**********************************************************************************************************************
  * Name:        McuCoreCfgAndDiagcInit2
  * Description: Non-RTE initialization function checking Core and DMA Lockstep functionality
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called at appropriate time during initialization prior to the O/S starting
  ********************************************************************************************************************/
FUNC(void, CDD_McuCoreCfgAndDiagc_CODE) McuCoreCfgAndDiagcInit2(void)
{
	VAR(boolean,AUTOMATIC) ExecStrtUpTest_Cnt_T_logl;
	VAR(uint32, AUTOMATIC) SavedECMEMK0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SavedECMMICFG0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SavedECMNMICFG0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SavedECMIRCFG0_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ECMMSSE001_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ECMCSSE001_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSDEBUGMODE_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) SYSDEBUGMODEB_Cnt_T_u32;
	#if(MCUDIAGCERRINJ == STD_ON)
	VAR(uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) DiagcIdn_Cnt_T_enum;
	#endif

	ChkForStrtUpTest_Oper(&ExecStrtUpTest_Cnt_T_logl);

	#if (MCUDIAGCERRINJ == STD_ON)
	GetMcuDiagcIdnData(&DiagcIdn_Cnt_T_enum);
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	#endif
	
	ECMMSSE001_Cnt_T_u32 = ECMMSSE001;
	ECMCSSE001_Cnt_T_u32 = ECMCSSE001;
	SYSDEBUGMODE_Cnt_T_u32 = SYSDEBUGMODE;
	SYSDEBUGMODEB_Cnt_T_u32 = SYSDEBUGMODEB;
	
	/* Only Run test on Power-On-Reset and if lockstep failure has not already occurred */
	if (((TRUE == ExecStrtUpTest_Cnt_T_logl)
	#if(MCUDIAGCERRINJ == STD_ON)
		||(MCUDIAGC_MCUDIAGCTEST == DiagcIdn_Cnt_T_enum)
	#endif
		) &&((ECMMSSE001_Cnt_T_u32 == 0U) && (ECMCSSE001_Cnt_T_u32 == 0U)) &&
	    ((SYSDEBUGMODE_Cnt_T_u32 == 0U) || (SYSDEBUGMODEB_Cnt_T_u32 == 1U)))
	{
		/* Save contents of modified registers */
		SavedECMEMK0_Cnt_T_u32 = ECMEMK0;
		SavedECMMICFG0_Cnt_T_u32 = ECMMICFG0;
		SavedECMNMICFG0_Cnt_T_u32 = ECMNMICFG0;
		SavedECMIRCFG0_Cnt_T_u32 = ECMIRCFG0;
		
		/* Mask the Error Source 1, NMI Interrupt and MI Interrupt of the ECMmESSTR0 register */
		WrProtdRegEcm_u32((SavedECMEMK0_Cnt_T_u32 | ((uint32)1U<<1U)), &ECMEMK0);
		WrProtdRegEcm_u32((SavedECMMICFG0_Cnt_T_u32 & ~((uint32)1U<<1U)), &ECMMICFG0);
		WrProtdRegEcm_u32((SavedECMNMICFG0_Cnt_T_u32 & ~((uint32)1U<<1U)), &ECMNMICFG0);
		WrProtdRegEcm_u32((SavedECMIRCFG0_Cnt_T_u32 & ~((uint32)1U<<1U)), &ECMIRCFG0);
		
		/* Inject Fault to cause a DMA Lockstep Error */
		PDMACOMPPDMA_COMP_CNTRL = 0xBFFF070FU;
		/* Wait until read from the TESTCOMPREG0 is complete to trigger the fault */
		__SYNCM();
		
		/* FaultInjectionPoint */
		#if (MCUDIAGCERRINJ== STD_ON)
		if (ErrId_Cnt_T_u32 == 0x00214001U)
		{
			/* Clear BRAMDAT2 Register */
			ClrErrInjReg_Oper();
			/* Clear error by setting the corresponding bit in ECMESSTC0 */
			WrProtdRegEcm_u32 (0x0000002U, &ECMESSTC0);
		}
		#endif
		
		ECMMSSE001_Cnt_T_u32 = ECMMSSE001;
		ECMCSSE001_Cnt_T_u32 = ECMCSSE001;
	
		/* Check if the DMA Lockstep fault was notified */
		if ((ECMMSSE001_Cnt_T_u32 == 0U) || (ECMCSSE001_Cnt_T_u32 == 0U))
		{
			/* DMA Lockstep test failed */
			SetMcuDiagcIdnData(MCUDIAGC_DMALOCKSTEPERR, 0U);
		}
		else
		{
			/* Clear Notification */
			WrProtdRegEcm_u32(((uint32)1U<<1U), &ECMESSTC0);
			
			/* Inject Fault to cause a CPU Lockstep Error */
			TESTCOMPREG0 = 0x11111111U;
			TESTCOMPREG1 = 0x22222222U;
			
			/* According to SAN, a Read is required to induce a CPU Lockstep Fault */
			*Rte_Pim_CoreCompTestRegRead() = TESTCOMPREG0;
			/* Wait until read from the TESTCOMPREG0 is complete to trigger the fault */
			__SYNCM();
			
			#if (MCUDIAGCERRINJ == STD_ON)
			/* FaultInjectionPoint2 */
			if (ErrId_Cnt_T_u32 == 0x00212001U)
			{
				/* Clear BRAMDAT2 Register */
				ClrErrInjReg_Oper();
				/* Clear Error by setting the corresponding bit in ECMESSTC0 */
				WrProtdRegEcm_u32 (0x0000002U, &ECMESSTC0);
			}
			#endif
			
			ECMMSSE001_Cnt_T_u32 = ECMMSSE001;
			ECMCSSE001_Cnt_T_u32 = ECMCSSE001;
		
			/* Check if the CPU Lockstep fault was notified */
			if ((ECMMSSE001_Cnt_T_u32 == 0U) || (ECMCSSE001_Cnt_T_u32 == 0U))
			{
				SetMcuDiagcIdnData(MCUDIAGC_CPULOCKSTEPERR, 0U);
			}
		}
		
		/* Clear Notification */
		WrProtdRegEcm_u32(((uint32)1U<<1U), &ECMESSTC0);
		
		/* Restore contents of modified registers */
		WrProtdRegEcm_u32(SavedECMEMK0_Cnt_T_u32, &ECMEMK0);
		WrProtdRegEcm_u32(SavedECMMICFG0_Cnt_T_u32, &ECMMICFG0);
		WrProtdRegEcm_u32(SavedECMNMICFG0_Cnt_T_u32, &ECMNMICFG0);
		WrProtdRegEcm_u32(SavedECMIRCFG0_Cnt_T_u32, &ECMIRCFG0);
	}
}

#define CDD_McuCoreCfgAndDiagc_STOP_SEC_CODE
#include "CDD_McuCoreCfgAndDiagc_MemMap.h"
