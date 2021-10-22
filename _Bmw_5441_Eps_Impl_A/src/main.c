/**********************************************************************************************************************
* Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name: main.c
* Module Description: Initial startup related code containing main() and the initialization
*                     task which calls EcuM_StartupTwo()
* Project           : BMW
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          8 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/06/17  1        KJS       Initial version.                                                               EA4#14844
* 09/26/17  2        KJS       Added EcuM header file and cleaned up revision history text.                   EA4#14844
* 10/18/17  3        KJS       Added SPI init routine to initalize the SPI RAM.                               EA4#14844
* 12/18/17  4        KJS       Dummy symbols as a place holder for Checksum symbols definition to fix 
                               NTC 2C issue                                                                   EA4#19273
							   
* 01/11/18  5        AR        Update for NTC 20 Fix                                                          EA4#19308	
* 03/17/18  6        AR        Updated for flash programming support                                          EA4#20395
* 06/29/18  7        AR        Anomaly EA4#25375 fix                                                          EA4#25375						   
**********************************************************************************************************************/

#include "Std_Types.h"
#include "EcuM.h"
#include "Os.h"
#include "ostm_regs.h"
#include "WdgM.h"
#include "WdgIf.h"
#include "Wdgm_PBcfg.h"
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "CDD_NvMProxy.h"
#include "CDD_NvMProxy_Cbk.h"
#include "fbl_TmplMonr.h"
#include "seg_regs.h"
#include "ecc_regs.h"


void FblEnableSysErrExceptions(void);
void FblEnableCodeFlashECCNtf(void);

#pragma ghs section rosdata=".APPCRC"
const uint32 DummyApplCrc = 0x00000000U;
#pragma ghs section

#pragma ghs section rosdata=".CAL1CRC"
const uint32 DummyCal1Crc = 0x00000000U;
#pragma ghs section

#pragma ghs section rosdata=".CAL1_FLASH"
const uint32 DummyCal1Val = 0x00000000U;
#pragma ghs section

#pragma ghs section rosdata=".CAL2CRC"
const uint32 DummyCal2Crc = 0x00000000U;
#pragma ghs section

#pragma ghs section rosdata=".CAL2_FLASH"
const uint32 DummyCal2Val = 0x00000000U;
#pragma ghs section

/**********************************************************************************************************************
  * Name:        main
  * Description: Main function of the application, only calling EcuM_Init()
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Called by low level startup code
  ********************************************************************************************************************/
int main (void)
{
	FblEnableSysErrExceptions();
	FblEnableCodeFlashECCNtf();
    EcuM_Init();
    return(0);
}

/**********************************************************************************************************************
  * Name:        Task_InitBsw_Appl10
  * Description: Task declaration that calls EcuM_StartupTwo
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Called by O/S (autostart task)
  ********************************************************************************************************************/
TASK(Task_InitBsw_Appl10)
{
    OSTM0TT = 1U;  /* Stop the O/S Timer until after Rte_Start is called */

    EcuM_StartupTwo();
    (void)TerminateTask();
}

/**********************************************************************************************************************
* Name:        FblEnableSysErrExceptions
* Description: Function configures additional error notification
* Inputs:      None
* Outputs:     None
* Usage Notes: None
**********************************************************************************************************************/
void FblEnableSysErrExceptions(void)
{
    /* Configure SEGCONT for all but instruction cache error notification */
    SEGCONT = 0x0370U;
}

void FblEnableCodeFlashECCNtf(void)
{

    /* Enabling ECC and Address parity error notifications to ECM */
    ECCFLICFERRINT_VCI = 0x00000007U;
    ECCFLICFERRINT_PE1 = 0x00000007U;

    __SYNCM();
}

/**********************************************************************************************************************
  * Name:        PrepForNvmWrAll
  * Description: Preparing to perform Nvm write all - Except 2msTmplMonr and 4msBsw tasks, 
                 stop all periodic tasks and Watchdog supervision, Shutdown DEM, stop COM  
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Called from BswM.
  ********************************************************************************************************************/
void PrepForNvmWrAll(void)
{
    Os_DisableInterruptSource(CounterIsr_OsCounter);

	  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
	/* Shutdown DEM in order to write DEM data to NVM - 
	   As long as tasks are running, DEM should not be shutdown since application components 
	   that are using DEM services causes DET error after if DEM shutdown earlier*/
	Dem_Shutdown();	
	/* Disable FlexRay interrupts to avoid com stack related stuffs interrupting Nvm WriteAll() */
	Os_DisableInterruptSource(Fr_IrqLine0);
	Os_DisableInterruptSource(Fr_IrqTimer0);	 
	/* Stop all periodic tasks except 2msTmplMonr, 4msBsw tasks - no longer all these tasks need to be active */
	(void)CancelAlarm(Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms);
	(void)CancelAlarm(Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms);
	(void)CancelAlarm(Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms);
	(void)CancelAlarm(Rte_Al_TE_Darh_QueueHandler);
	(void)CancelAlarm(Rte_Al_TE_Task_100ms_Appl10_0_100ms);
	(void)CancelAlarm(Rte_Al_TE_Task_100ms_Appl7_0_100ms);
	(void)CancelAlarm(Rte_Al_TE_Task_100ms_Appl9_0_100ms);
	(void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl10_0_10ms);
	(void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl7_0_10ms);
	(void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl8_0_10ms);
	(void)CancelAlarm(Rte_Al_TE_Task_10ms_Appl9_0_10ms);
	(void)CancelAlarm(Rte_Al_TE_Task_2msA_Appl10_0_2ms);
	(void)CancelAlarm(Rte_Al_TE_Task_2msB_Appl10_0_2ms);
	(void)CancelAlarm(Rte_Al_TE_Task_2ms_Appl7_0_2ms);
	(void)CancelAlarm(Rte_Al_TE_Task_2ms_Appl8_0_2ms);
	(void)CancelAlarm(Rte_Al_TE_Task_2ms_Appl9_0_2ms);
	(void)CancelAlarm(Rte_Al_TE_Task_4ms_Appl7_0_4ms);
	(void)CancelAlarm(Rte_Al_TE_Task_ComBsw_Appl10_0_10ms);

	/* Deactivate supervision of the periodic tasks to prevent the software watchdog from diagnosing the canceled tasks
	 * as alive monitor failures. */
    (void)WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_SE_10msBsw_Appl10, WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_End ); /* This task cannot be "active" when the deactivate call is made below */	 
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_2msA_Appl10);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl10);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl10);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl10);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_10msBsw_Appl10);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl9);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl9);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl9);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl8);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl8);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl7);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl7);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl7);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl7);
	(void)WdgM_DeactivateSupervisionEntity(WdgMConf_WdgMSupervisedEntity_SE_2msB_Appl10);

	/* Resume OS interrupt and allow the non-canceled tasks to run again. */
    Os_EnableInterruptSource(CounterIsr_OsCounter, TRUE);
	
}


/**********************************************************************************************************************
  * Name:        PostNvmWrAll
  * Description: This function used to avoid interruption by OS during EcuM_Godown() call.
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Called from BswM.
  ********************************************************************************************************************/
void PostNvmWrAll(void)
{
	VAR(TickType, AUTOMATIC) Ticks_Cnt_T_u32;

	/* Disable OS counter interrupt - Entering into no point of return */
    Os_DisableInterruptSource(CounterIsr_OsCounter);	

	/* SetRelAlarm function called to activate alarms for tasks - Otherwise Rte_Stop causes DET errors - 
	   This will not activate tasks since OS counter interrupt disabled   */
	(void)GetAlarm(Rte_Al_TE2_Task_4msBsw_Appl10_0_4ms, &Ticks_Cnt_T_u32);
	(void)SetRelAlarm(Rte_Al_TE2_Task_10msBsw_Appl10_0_10ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(10));
	(void)SetRelAlarm(Rte_Al_TE2_Task_5msBsw_Appl10_0_5ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(5));
	(void)SetRelAlarm(Rte_Al_TE2_Task_ComBsw_Appl10_0_5ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(5));
	(void)SetRelAlarm(Rte_Al_TE_Darh_QueueHandler,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(100));
	(void)SetRelAlarm(Rte_Al_TE_Task_100ms_Appl10_0_100ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(100));
	(void)SetRelAlarm(Rte_Al_TE_Task_100ms_Appl7_0_100ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(100));
	(void)SetRelAlarm(Rte_Al_TE_Task_100ms_Appl9_0_100ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(100));
	(void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl10_0_10ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(10));
	(void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl7_0_10ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(10));
	(void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl8_0_10ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(10));
	(void)SetRelAlarm(Rte_Al_TE_Task_10ms_Appl9_0_10ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(10));
	(void)SetRelAlarm(Rte_Al_TE_Task_2msA_Appl10_0_2ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(2));
	(void)SetRelAlarm(Rte_Al_TE_Task_2msB_Appl10_0_2ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(2));
	(void)SetRelAlarm(Rte_Al_TE_Task_2ms_Appl7_0_2ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(2));
	(void)SetRelAlarm(Rte_Al_TE_Task_2ms_Appl8_0_2ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(2));
	(void)SetRelAlarm(Rte_Al_TE_Task_2ms_Appl9_0_2ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(2));
	(void)SetRelAlarm(Rte_Al_TE_Task_4ms_Appl7_0_4ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(4));
	(void)SetRelAlarm(Rte_Al_TE_Task_ComBsw_Appl10_0_10ms,Ticks_Cnt_T_u32, OS_MS2TICKS_OsCounter(10));	
	
}
