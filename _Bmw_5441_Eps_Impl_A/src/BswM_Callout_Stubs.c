/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: BswM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Callout_Stubs.c
 *   Generation Time: 2018-03-13 12:55:27
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   BswM_Callout_Stubs.c
* Module Description: Stub for BswM configuration hooks
* Project           : BMW 5441
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          7 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/06/17  1        KJS       Initial Version                                                                EA4#14844
* 09/26/17  2        KJS       Updates to BswM naminig                                                        EA4#14844
* 10/04/17  3        KJS       Added interrupt enables for FlexRay communication                              EA4#14844
* 10/25/17  4        AR        Modified BswM_SHUTDOWN_NvMWriteAll to prevent timing violations                EA4#17066
* 11/23/17  5        AR        Updated shutdown sequence                                                      EA4#17066
* 03/17/18  6        AR        Updated for flash programming support                                          EA4#20395
* 06/29/18  7        AR        Anomaly EA4#25375 fix                                                          EA4#25375
**********************************************************************************************************************/
/************************************************ Include Statements *************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define BSWM_CALLOUT_STUBS_SOURCE
#include "BswM.h"
#include "BswM_Private_Cfg.h"



/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "WdgM.h"
#include "WdgM_PBcfg.h"
#include "WdgIf.h"
#include "Os.h"
#include "CDD_NvMProxy.h"
#include "CDD_NvMProxy_Cbk.h"
#include "CDD_ExcpnHndlg.h"
#include "DiagcMgr.h"
#include "CDD_NxtrTi.h" 
#include "Wdgm_PBcfg.h"
 
/* Maximum duration allowed for a NvM Cancel request to complete to ensure proper restart times in units of 100us: */
#define BSWMWRCNCLMAXDURN_100US_U32  2500

/* Periodicity of slowest task */
#define BSWMSLOWESTTASKPERD_MS_U32   100U

#define BSWMWRALLPASSD_CNT_U08  0x55U
#define BSWMWRALLFAILD_CNT_U08  0xAAU
#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"
#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_SHUTDOWN_NvMWriteAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_SHUTDOWN_NvMWriteAll>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    VAR(NvM_RequestResultType, AUTOMATIC) MultiBlockStatus;
	VAR(NvM_RequestResultType, AUTOMATIC) ClsChkStatus;
	
	/* Stop the normal periodic tasks. */
	PrepForNvmWrAll();
	/* Stop the OS tick for consistency.  Note that the SetRelAlarm functions cannot be called when OS interrupts
	 * are disabled which is why this mechanism was used instead. */

    /* Don't perform write all for hard resets */
    if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownReason) != BSWM_GENERICVALUE_BswM_ShutdownReason_HardReset) 
    {
        /* Force storing of RAM block statuses in case of restart event (i.e. quick ignition cycle) */
        NvMProxy_MultiBlkCallBack(NVM_WRITE_ALL, NVM_REQ_PENDING);
        NvM_WriteAll();

        /* Loop until WriteAll completes */
        do
        {
            NvM_MainFunction();
            Fee_30_SmallSector_MainFunction();
            Fls_MainFunction();

            NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &MultiBlockStatus);	
			/* Let us not worry about quick ignition cycle until proper shutdown sequence establised */
			
        }while ((MultiBlockStatus==NVM_REQ_PENDING));


		/* Issue the close check write only if the WriteAll didn't fail */
        if (MultiBlockStatus != NVM_REQ_NOT_OK)
        {
			/* Close Check Block Write */
			NvMProxy_ClsChkWr_Oper();
			
			/* Commit the close check flag to FEE */
			do
			{
				NvM_MainFunction();
				Fee_30_SmallSector_MainFunction();
				Fls_MainFunction();

				NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_Rte_NvmBlock_CDD_NvMProxy_ShtdwnClsChk, &ClsChkStatus);

			} while (ClsChkStatus==NVM_REQ_PENDING);				
		}
		

    }

	PostNvmWrAll();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_SHUTDOWN_NvMWriteAll */


FUNC(void, BSWM_CODE) BswM_FinalizeShtdwn(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_FinalizeShtdwn>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	/* Power down */
	EcuM_ClearValidatedWakeupEvent(0x2);
	(void)Os_Call_EcuM_GoDown(BSWM_MODULE_ID);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_FinalizeShtdwn */


FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_INIT_NvMReadAll>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

    NvM_RequestResultType MultiBlockStatus;

    NvM_ReadAll();
    
    /* Loop until ReadAll operation completes */
    do
    {
     Call_NvM_MainFunction();
     Fee_30_SmallSector_MainFunction();
     Call_Fls_MainFunction();
     
     NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &MultiBlockStatus);
    }
    while(MultiBlockStatus==NVM_REQ_PENDING);

    NvMProxy_Init0();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_INIT_NvMReadAll */


FUNC(void, BSWM_CODE) BswM_ShtdwnHndlg_PrepShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ShtdwnHndlg_PrepShutdown>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

    if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownReason) == BSWM_GENERICVALUE_BswM_ShutdownReason_Prog)
    {
        EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU);
		(void)Os_Call_EcuM_GoDown(BSWM_MODULE_ID);
    }
    else if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownReason) == BSWM_GENERICVALUE_BswM_ShutdownReason_HardReset)
    {
        EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU);
    }
    else if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownReason) == BSWM_GENERICVALUE_BswM_ShutdownReason_SoftReset)
    {
        EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU);
    }
    else
    {
        EcuM_SelectShutdownTarget(ECUM_STATE_OFF, 0);
        BswM_RequestMode(BSWM_GENERIC_BswM_ShutdownReason, BSWM_GENERICVALUE_BswM_ShutdownReason_SwtOff);
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ShtdwnHndlg_PrepShutdown */


FUNC(void, BSWM_CODE) BswM_Restart(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_Restart>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    VAR(TickType, AUTOMATIC) Ticks_Cnt_T_u32;

    // TODO: <KJS> Replace once CMS is integrated (void)CallNonTrustedFunction(NtWrapS_CmnMfgSrv_Init, NULL_PTR);
    

    /* Synchronize with the slowest task (100ms) to ensure the proper sequence when releasing the resource and
    * avoid program flow violations when the 10ms check point is re-entered.
    */
    do
    {
        GetAlarm(Rte_Al_TE_Task_100ms_Appl10_0_100ms, &Ticks_Cnt_T_u32);
    } while (Ticks_Cnt_T_u32 < OS_MS2TICKS_OsCounter(BSWMSLOWESTTASKPERD_MS_U32));

    /* Resume all periodic tasks */
    // TODO: <KJS> - Determine if this is needed. Call_ReleaseResource(SHUTDOWN_ONGOING);

    /* At this point, all of the periodics associated with SHUTDOWN_ONGOING will execute.  This is intentionally done
     * before enabling supervision as the time between right now and the next system tick will not be exactly 2ms as
     * the watchdog expects and will lead to program flow violations.
     */

    SuspendOSInterrupts();
    /* TODO: <KJS> Restore once watchdog is configured.
      WdgM_ActivateSupervisionEntity(SE_0);  //10ms Bsw
    WdgM_ActivateSupervisionEntity(SE_1);
    WdgM_ActivateSupervisionEntity(SE_2);
    WdgM_ActivateSupervisionEntity(SE_3);
    WdgM_ActivateSupervisionEntity(SE_4);
    WdgM_ActivateSupervisionEntity(SE_5);
    WdgM_ActivateSupervisionEntity(SE_6);
    WdgM_ActivateSupervisionEntity(SE_7);
    */ 
    ResumeOSInterrupts();

    // TODO: <KJS> - Determine need for this (void)WdgM_CheckpointReached(SE_0, CP_0_0); /* Needed to avoid program flow violations for this task */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_Restart */


FUNC(void, BSWM_CODE) BswM_DiagcMgrPwrDwn(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_DiagcMgrPwrDwn>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

    if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownReason) != BSWM_GENERICVALUE_BswM_ShutdownReason_HardReset)
    {
        (void)DiagcMgrPwrDwn();
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_DiagcMgrPwrDwn */


FUNC(void, BSWM_CODE) BwmM_GetShutdownOngoing(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BwmM_GetShutdownOngoing>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

    /* Stop all periodic tasks except 2msTmplMonr, 4ms tasks */
// TODO: <KJS> Determine if this is needed     Call_GetResource(SHUTDOWN_ONGOING);
/* TODO: <KJS> Determine what is needed from the list below*/
    
    //(void)WdgM_CheckpointReached(SE_0, CP_0_1); /* This task cannot be "active" when the deactivate call is made below */
    //WdgM_DeactivateSupervisionEntity(SE_0);  /* 10ms BSW */
    //WdgM_DeactivateSupervisionEntity(SE_1);
    //WdgM_DeactivateSupervisionEntity(SE_2);
    //WdgM_DeactivateSupervisionEntity(SE_3);
    //WdgM_DeactivateSupervisionEntity(SE_4);
    //WdgM_DeactivateSupervisionEntity(SE_5);
    //WdgM_DeactivateSupervisionEntity(SE_6);
    //WdgM_DeactivateSupervisionEntity(SE_7);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BwmM_GetShutdownOngoing */


FUNC(void, BSWM_CODE) BswM_AL_SetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    Os_EnableInterruptSource(Fr_IrqLine0, FALSE);
    Os_EnableInterruptSource(Fr_IrqTimer0, FALSE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_AL_SetProgrammableInterrupts */


#define BSWM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: BSWM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


