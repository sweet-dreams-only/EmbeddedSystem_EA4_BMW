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
 *              File: BswM_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:09
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

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif

/* -----------------------------------------------------------------------------
    &&&~ MACROS
 ----------------------------------------------------------------------------- */
/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_SetIpduGroup(pduId, bitVal) Com_SetIpduGroup(BswM_ComIPduGroupState, (pduId), (bitVal))
#define BswM_SetIpduReinitGroup(pduId, bitVal)
#define BswM_SetIpduDMGroup(pduId, bitVal)

/* PRQA S 3453 1 */ /* MD_BswM_3453 */
#define BswM_MarkPduGroupControlInvocation(control) BswM_PduGroupControlInvocation |= (control)
#define BswM_MarkDmControlInvocation() BswM_PduGroupControlInvocation |= BSWM_GROUPCONTROL_DM



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
/*!
 * \brief       Updates the state of a rule.
 * \details     Set rule state of passed ruleId to passed state.
 * \param[in]   ruleId    Id of the rule to update.
 * \param[in]   state     New state of the rule.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state);

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * \brief       Updates a timer.
 * \details     Set timer value of passed timerId to passed value and calculates the new state.
 * \param[in]   timerId   Id of the timer to update.
 * \param[in]   value     New value of the timer.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_SizeOfTimerValueType timerId, BswM_TimerValueType value);

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_BswM_0779 */

/**********************************************************************************************************************
 *  ImmediateSwcRequest
 *********************************************************************************************************************/
/*! \defgroup    ImmediateSwcRequest
 * \{
 */
/**********************************************************************************************************************
 *  BswM_ImmediateSwcRequest
 *********************************************************************************************************************/
/*!
 * \brief       Arbitrates depending immediate rules of a Swc Mode Request port.
 * \details     Checks if port is valid and arbitrates depending immediate rules.
 * \param[IN]   requestId  Index of a swc mode request port.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Function called by immediate swc request functions (BswMRteRequestFunctions).
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ImmediateSwcRequest(BswM_SizeOfModeRequestMappingType requestId);
/*! \} */ /* End of group ImmediateSwcRequest */

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionListFunctions
 * \{
 */

/*!
 * \{
 * \brief       Execute actions of action list.
 * \details     Generated function which depends on the configuration. Executes the actions of the action list in the
 *              configured order.
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_GoOffOne(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_PrepShtdwn(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Rstrt(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_SysTime(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Vin(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Darh(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_StdDiag_SessionChangeToDefaultSession(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Dlog(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Darh(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Disable_Rx_And_Tx_Normal(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Vin(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Omc(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_StdDiag(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_StdDiag(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Rule_Systime_Init_True(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Enable_RX_Disable_TX_NORMAL(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Disable_RX_Enable_TX_NORMAL(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Omc(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Dlog(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Darh(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_3_ENABLED(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Enable_RX_AND_TX_NORMAL(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_4_DISABLED(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_StdDiag(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_4_ENABLED(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_StdDiag_SessionChangeToOtherSession(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_3_DISABLED(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Omc(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Dlog(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Rule_Start_Systime_Run_when_Systime_Init_True(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Vin(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_Disable(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Dcm_ShutDown_HardReset(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Dcm_ShutDown_EcuReset(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Coding(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Dcm_HardResetStartTimer(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Coding(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Coding(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Coding_BusComOff(void);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Coding_BusComOn(void);
/*! \} */ /* End of sharing description for BswMActionListFunctions */
/*! \} */ /* End of group BswMActionListFunctions */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMRuleFunctions
 * \{
 */

/*!
 * \{
 * \brief       Arbitrates the configured rule.
 * \details     Generated function which depends on the configuration. Arbitrates the rule and returns the action list
 *              which shall be executed.
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no ActionList shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_GoOffOne(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_PrepShtdwn(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Rst(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Run(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_OMC_INITIALIZE(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Com_PduGroup3Enabled(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Enable_Rx_Disable_Tx(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Start_StdDiag_Run_when_StdDiag_Init(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Start_Systime_Run_when_Systime_Init(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Switch_StdDiagSessionChangeIndication(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_A_FlexRay_372befd6_TX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Enable_Rx_Enable_Tx(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_A_FlexRay_372befd6_RX(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Vin_Initialize(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Disable_Rx_Disable_Tx(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Com_PduGroup4Enabled(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dlog_Run(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Disable_Rx_Enable_Tx(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Darh_Run(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dcm_HardReset(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Start_StdDiag_Init_when_Omc_Run(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dcm_EcuResetForReprogramming(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Systime_Init(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Coding_Init(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dlog_Init(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Set_DarhReportError_due_ComM_and_CEL_mode(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Darh_Init(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dcm_HardResetStartTimer(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Coding_Run(void);
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Coding_BusComSwitch(void);
/*! \} */ /* End of sharing description for BswMRuleFunctions */
/*! \} */ /* End of group BswMRuleFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/* PRQA S 0779 VARIABLEDECLARATIONS */ /* MD_BswM_0779 */ 

#define BSWM_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

BSWM_LOCAL VAR(uint8, BSWM_VAR_NOINIT) BswM_PduGroupControlInvocation;

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


BSWM_LOCAL VAR(Rte_ModeType_ErrorMemoryLockSignalReceptionMode, BSWM_VAR_NOINIT) BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode;
BSWM_LOCAL VAR(Rte_ModeType_StdDiag_SessionModeGroup, BSWM_VAR_NOINIT) BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup;
BSWM_LOCAL VAR(Rte_ModeType_StdDiag_NormalCommunicationModeGroup, BSWM_VAR_NOINIT) BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup;
BSWM_LOCAL VAR(Rte_ModeType_Vin_VinComMode, BSWM_VAR_NOINIT) BswM_Switch_VinComSwitchPort_Mode;
BSWM_LOCAL VAR(Rte_ModeType_DarhReportErrorMode, BSWM_VAR_NOINIT) BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode;
BSWM_LOCAL VAR(Rte_ModeType_Coding_BusComMode, BSWM_VAR_NOINIT) BswM_Switch_Coding_BusComModeSwitch_Mode;
BSWM_LOCAL VAR(Omc_LifeCycleRequestType, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_MSRP_Omc_requestMode;
BSWM_LOCAL VAR(Dlog_LifeCycleRequestType, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_MSRP_Dlog_requestMode;
BSWM_LOCAL VAR(StdDiag_LifeCycleRequestType, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_MSRP_StdDiag_requestMode;
BSWM_LOCAL VAR(SysTime_LifeCycleRequestType, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_MSRP_SysTime_requestMode;
BSWM_LOCAL VAR(Darh_LifeCycleRequestType, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_MSRP_Darh_requestMode;
BSWM_LOCAL VAR(Vin_LifeCycleRequestType, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_MSRP_Vin_requestMode;
BSWM_LOCAL VAR(Coding_LifeCycleRequestType, BSWM_VAR_NOINIT) BswM_RteRequest_Provide_MSRP_Coding_requestMode;

BSWM_LOCAL VAR(NormalCommunicationModeType, BSWM_VAR_NOINIT) Request_StdDiag_ComControlModeRequest_requestedMode;
BSWM_LOCAL VAR(Rte_ModeType_Dlog_LifeCycle, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode;
BSWM_LOCAL VAR(Rte_ModeType_StdDiag_LifeCycle, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode;
BSWM_LOCAL VAR(Rte_ModeType_SysTime_LifeCycle, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode;
BSWM_LOCAL VAR(Rte_ModeType_Omc_LifeCycle, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode;
BSWM_LOCAL VAR(Rte_ModeType_DcmDiagnosticSessionControl, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
BSWM_LOCAL VAR(Rte_ModeType_Darh_LifeCycle, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode;
BSWM_LOCAL VAR(Rte_ModeType_Vin_LifeCycle, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode;
BSWM_LOCAL VAR(Rte_ModeType_DcmEcuReset, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset;
BSWM_LOCAL VAR(Rte_ModeType_DcmCommunicationControl, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6;
BSWM_LOCAL VAR(Rte_ModeType_Coding_LifeCycle, BSWM_VAR_NOINIT) BswM_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode;
BSWM_LOCAL VAR(Rte_ModeType_Stm_CentralErrorLockMode, BSWM_VAR_NOINIT) BswM_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode;


/* PRQA S 3218 3 */ /* MD_BswM_3218 */
BSWM_LOCAL VAR(Com_IpduGroupVector, BSWM_VAR_NOINIT) BswM_ComIPduGroupState;

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* PRQA L:VARIABLEDECLARATIONS */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BswM_0310 */ 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionLists
**********************************************************************************************************************/
/** 
  \var    BswM_ActionLists
  \details
  Element    Description
  FctPtr     Pointer to the array list function.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionLists[47] = {
    /* Index    FctPtr                                                                                   Comment                   Referable Keys */
  { /*     0 */ BswM_ActionList_AL_Run                                                            },  /* [Priority: 0] */  /* [AL_AL_Run] */
  { /*     1 */ BswM_ActionList_AL_GoOffOne                                                       },  /* [Priority: 0] */  /* [AL_AL_GoOffOne] */
  { /*     2 */ BswM_ActionList_AL_PrepShtdwn                                                     },  /* [Priority: 0] */  /* [AL_AL_PrepShtdwn] */
  { /*     3 */ BswM_ActionList_AL_Rstrt                                                          },  /* [Priority: 0] */  /* [AL_AL_Rstrt] */
  { /*     4 */ BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit                          },  /* [Priority: 0] */  /* [AL_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit] */
  { /*     5 */ BswM_ActionList_AL_Stop_SysTime                                                   },  /* [Priority: 0] */  /* [AL_AL_Stop_SysTime] */
  { /*     6 */ BswM_ActionList_AL_Run_Vin                                                        },  /* [Priority: 0] */  /* [AL_AL_Run_Vin] */
  { /*     7 */ BswM_ActionList_AL_Initialize_Darh                                                },  /* [Priority: 0] */  /* [AL_AL_Initialize_Darh] */
  { /*     8 */ BswM_ActionList_AL_StdDiag_SessionChangeToDefaultSession                          },  /* [Priority: 0] */  /* [AL_AL_StdDiag_SessionChangeToDefaultSession] */
  { /*     9 */ BswM_ActionList_AL_Run_Dlog                                                       },  /* [Priority: 0] */  /* [AL_AL_Run_Dlog] */
  { /*    10 */ BswM_ActionList_AL_Stop_Darh                                                      },  /* [Priority: 0] */  /* [AL_AL_Stop_Darh] */
  { /*    11 */ BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit                          },  /* [Priority: 0] */  /* [AL_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit] */
  { /*    12 */ BswM_ActionList_AL_NDC_Disable_Rx_And_Tx_Normal                                   },  /* [Priority: 0] */  /* [AL_AL_NDC_Disable_Rx_And_Tx_Normal] */
  { /*    13 */ BswM_ActionList_AL_Initialize_Vin                                                 },  /* [Priority: 0] */  /* [AL_AL_Initialize_Vin] */
  { /*    14 */ BswM_ActionList_AL_Stop_Omc                                                       },  /* [Priority: 0] */  /* [AL_AL_Stop_Omc] */
  { /*    15 */ BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_Disable                               },  /* [Priority: 0] */  /* [AL_CC_AL_A_FlexRay_372befd6_TX_Disable] */
  { /*    16 */ BswM_ActionList_AL_Stop_StdDiag                                                   },  /* [Priority: 0] */  /* [AL_AL_Stop_StdDiag] */
  { /*    17 */ BswM_ActionList_AL_Run_StdDiag                                                    },  /* [Priority: 0] */  /* [AL_AL_Run_StdDiag] */
  { /*    18 */ BswM_ActionList_AL_Rule_Systime_Init_True                                         },  /* [Priority: 0] */  /* [AL_AL_Rule_Systime_Init_True] */
  { /*    19 */ BswM_ActionList_AL_NDC_Enable_RX_Disable_TX_NORMAL                                },  /* [Priority: 0] */  /* [AL_AL_NDC_Enable_RX_Disable_TX_NORMAL] */
  { /*    20 */ BswM_ActionList_AL_NDC_Disable_RX_Enable_TX_NORMAL                                },  /* [Priority: 0] */  /* [AL_AL_NDC_Disable_RX_Enable_TX_NORMAL] */
  { /*    21 */ BswM_ActionList_AL_Initialize_Omc                                                 },  /* [Priority: 0] */  /* [AL_AL_Initialize_Omc] */
  { /*    22 */ BswM_ActionList_AL_Stop_Dlog                                                      },  /* [Priority: 0] */  /* [AL_AL_Stop_Dlog] */
  { /*    23 */ BswM_ActionList_AL_Run_Darh                                                       },  /* [Priority: 0] */  /* [AL_AL_Run_Darh] */
  { /*    24 */ BswM_ActionList_AL_COM_PDU_GROUP_3_ENABLED                                        },  /* [Priority: 0] */  /* [AL_AL_COM_PDU_GROUP_3_ENABLED] */
  { /*    25 */ BswM_ActionList_AL_NDC_Enable_RX_AND_TX_NORMAL                                    },  /* [Priority: 0] */  /* [AL_AL_NDC_Enable_RX_AND_TX_NORMAL] */
  { /*    26 */ BswM_ActionList_AL_COM_PDU_GROUP_4_DISABLED                                       },  /* [Priority: 0] */  /* [AL_AL_COM_PDU_GROUP_4_DISABLED] */
  { /*    27 */ BswM_ActionList_AL_Initialize_StdDiag                                             },  /* [Priority: 0] */  /* [AL_AL_Initialize_StdDiag] */
  { /*    28 */ BswM_ActionList_AL_COM_PDU_GROUP_4_ENABLED                                        },  /* [Priority: 0] */  /* [AL_AL_COM_PDU_GROUP_4_ENABLED] */
  { /*    29 */ BswM_ActionList_AL_StdDiag_SessionChangeToOtherSession                            },  /* [Priority: 0] */  /* [AL_AL_StdDiag_SessionChangeToOtherSession] */
  { /*    30 */ BswM_ActionList_AL_COM_PDU_GROUP_3_DISABLED                                       },  /* [Priority: 0] */  /* [AL_AL_COM_PDU_GROUP_3_DISABLED] */
  { /*    31 */ BswM_ActionList_AL_Run_Omc                                                        },  /* [Priority: 0] */  /* [AL_AL_Run_Omc] */
  { /*    32 */ BswM_ActionList_AL_Initialize_Dlog                                                },  /* [Priority: 0] */  /* [AL_AL_Initialize_Dlog] */
  { /*    33 */ BswM_ActionList_AL_Rule_Start_Systime_Run_when_Systime_Init_True                  },  /* [Priority: 0] */  /* [AL_AL_Rule_Start_Systime_Run_when_Systime_Init_True] */
  { /*    34 */ BswM_ActionList_AL_Stop_Vin                                                       },  /* [Priority: 0] */  /* [AL_AL_Stop_Vin] */
  { /*    35 */ BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_Disable                               },  /* [Priority: 0] */  /* [AL_CC_AL_A_FlexRay_372befd6_RX_Disable] */
  { /*    36 */ BswM_ActionList_INIT_AL_Initialize                                                },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*    37 */ BswM_ActionList_AL_Dcm_ShutDown_HardReset                                         },  /* [Priority: 0] */  /* [AL_AL_Dcm_ShutDown_HardReset] */
  { /*    38 */ BswM_ActionList_AL_Dcm_ShutDown_EcuReset                                          },  /* [Priority: 0] */  /* [AL_AL_Dcm_ShutDown_EcuReset] */
  { /*    39 */ BswM_ActionList_AL_Initialize_Coding                                              },  /* [Priority: 0] */  /* [AL_AL_Initialize_Coding] */
  { /*    40 */ BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False },  /* [Priority: 0] */  /* [AL_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False] */
  { /*    41 */ BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True  },  /* [Priority: 0] */  /* [AL_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True] */
  { /*    42 */ BswM_ActionList_AL_Dcm_HardResetStartTimer                                        },  /* [Priority: 0] */  /* [AL_AL_Dcm_HardResetStartTimer] */
  { /*    43 */ BswM_ActionList_AL_Run_Coding                                                     },  /* [Priority: 0] */  /* [AL_AL_Run_Coding] */
  { /*    44 */ BswM_ActionList_AL_Stop_Coding                                                    },  /* [Priority: 0] */  /* [AL_AL_Stop_Coding] */
  { /*    45 */ BswM_ActionList_AL_Coding_BusComOff                                               },  /* [Priority: 0] */  /* [AL_AL_Coding_BusComOff] */
  { /*    46 */ BswM_ActionList_AL_Coding_BusComOn                                                }   /* [Priority: 0] */  /* [AL_AL_Coding_BusComOn] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRules
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRules
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRules[22] = {
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       1U },  /* [R_Rule_PrepShtdwn] */
  { /*     1 */       4U },  /* [R_Rule_OMC_INITIALIZE] */
  { /*     2 */       6U },  /* [R_Rule_NDC_Enable_Rx_Disable_Tx] */
  { /*     3 */       7U },  /* [R_Rule_Start_StdDiag_Run_when_StdDiag_Init] */
  { /*     4 */       8U },  /* [R_Rule_Start_Systime_Run_when_Systime_Init] */
  { /*     5 */       9U },  /* [R_Rule_Switch_StdDiagSessionChangeIndication] */
  { /*     6 */      11U },  /* [R_Rule_NDC_Enable_Rx_Enable_Tx] */
  { /*     7 */      13U },  /* [R_Rule_Vin_Initialize] */
  { /*     8 */      14U },  /* [R_Rule_NDC_Disable_Rx_Disable_Tx] */
  { /*     9 */      16U },  /* [R_Rule_Dlog_Run] */
  { /*    10 */      17U },  /* [R_Rule_NDC_Disable_Rx_Enable_Tx] */
  { /*    11 */      18U },  /* [R_Rule_Darh_Run] */
  { /*    12 */      19U },  /* [R_Rule_Dcm_HardReset] */
  { /*    13 */      20U },  /* [R_Rule_Start_StdDiag_Init_when_Omc_Run] */
  { /*    14 */      21U },  /* [R_Rule_Dcm_EcuResetForReprogramming] */
  { /*    15 */      22U },  /* [R_Rule_Systime_Init] */
  { /*    16 */      23U },  /* [R_Rule_Coding_Init] */
  { /*    17 */      24U },  /* [R_Rule_Dlog_Init] */
  { /*    18 */      25U },  /* [R_Rule_Set_DarhReportError_due_ComM_and_CEL_mode] */
  { /*    19 */      26U },  /* [R_Rule_Darh_Init] */
  { /*    20 */      27U },  /* [R_Rule_Dcm_HardResetStartTimer] */
  { /*    21 */      28U }   /* [R_Rule_Coding_Run] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericMapping
**********************************************************************************************************************/
/** 
  \var    BswM_GenericMapping
  \brief  Maps the external id of BswMGenericRequest to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMGenericRequest.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
  InitValue                Initialization value of port.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_GenericMappingType, BSWM_CONST) BswM_GenericMapping[2] = {
    /* Index    ExternalId  ImmediateUserEndIdx  ImmediateUserStartIdx  InitValue                                            Referable Keys */
  { /*     0 */ 0         ,                  2U,                    1U, BSWM_GENERICVALUE_BswMSt_StrtUpTwoA           },  /* [GENERIC_0, MRP_BswMSt] */
  { /*     1 */ 1         ,                  3U,                    2U, BSWM_GENERICVALUE_BswM_ShutdownReason_Default }   /* [GENERIC_1, MRP_BswM_ShutdownReason] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  MaskedBits          contains bitcoded the boolean data of BswM_ForcedOfImmediateUser, BswM_RulesIndUsedOfImmediateUser
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[4] = {
    /* Index    MaskedBits  RulesIndEndIdx                         RulesIndStartIdx                               Comment                                                  Referable Keys */
  { /*     0 */      0x01U,                                    7U,                                      0U },  /* [Name: CC_FrSMIndication_A_FlexRay_372befd6] */  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6, FRSM_CHANNEL_0] */
  { /*     1 */      0x03U,                                   11U,                                      7U },  /* [Name: BswMSt]                               */  /* [MRP_BswMSt, GENERIC_0] */
  { /*     2 */      0x02U, BSWM_NO_RULESINDENDIDXOFIMMEDIATEUSER, BSWM_NO_RULESINDSTARTIDXOFIMMEDIATEUSER },  /* [Name: BswM_ShutdownReason]                  */  /* [MRP_BswM_ShutdownReason, GENERIC_1] */
  { /*     3 */      0x01U,                                   15U,                                     11U }   /* [Name: StdDiag_ComControlModeRequest]        */  /* [MRP_StdDiag_ComControlModeRequest, SWC_REQUEST_0] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Rules
**********************************************************************************************************************/
/** 
  \var    BswM_Rules
  \details
  Element    Description
  Id         External id of rule.
  Init       Initialization value of rule state (TRUE, FALSE, UNDEFINED or DEACTIVATED).
  FctPtr     Pointer to the rule function which does the arbitration.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_Rules[30] = {
    /* Index    Id   Init            FctPtr                                                          Referable Keys */
  { /*     0 */ 14U, BSWM_FALSE    , BswM_Rule_Rule_GoOffOne                                  },  /* [R_Rule_GoOffOne, MRP_BswMSt] */
  { /*     1 */ 20U, BSWM_FALSE    , BswM_Rule_Rule_PrepShtdwn                                },  /* [R_Rule_PrepShtdwn, MRP_BswMSt, MRP_SysStMod] */
  { /*     2 */ 21U, BSWM_FALSE    , BswM_Rule_Rule_Rst                                       },  /* [R_Rule_Rst, MRP_BswMSt] */
  { /*     3 */ 22U, BSWM_FALSE    , BswM_Rule_Rule_Run                                       },  /* [R_Rule_Run, MRP_BswMSt] */
  { /*     4 */ 19U, BSWM_FALSE    , BswM_Rule_Rule_OMC_INITIALIZE                            },  /* [R_Rule_OMC_INITIALIZE, MRP_SwcModeNotification_Omc_LifeCycle] */
  { /*     5 */  5U, BSWM_FALSE    , BswM_Rule_Rule_Com_PduGroup3Enabled                      },  /* [R_Rule_Com_PduGroup3Enabled, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  { /*     6 */ 17U, BSWM_FALSE    , BswM_Rule_Rule_NDC_Enable_Rx_Disable_Tx                  },  /* [R_Rule_NDC_Enable_Rx_Disable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  { /*     7 */ 25U, BSWM_FALSE    , BswM_Rule_Rule_Start_StdDiag_Run_when_StdDiag_Init       },  /* [R_Rule_Start_StdDiag_Run_when_StdDiag_Init, MRP_SwcModeNotification_StdDiag_LifeCycle] */
  { /*     8 */ 26U, BSWM_FALSE    , BswM_Rule_Rule_Start_Systime_Run_when_Systime_Init       },  /* [R_Rule_Start_Systime_Run_when_Systime_Init, MRP_SwcModeNotification_SysTime_LifeCycle, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  { /*     9 */ 27U, BSWM_FALSE    , BswM_Rule_Rule_Switch_StdDiagSessionChangeIndication     },  /* [R_Rule_Switch_StdDiagSessionChangeIndication, MRP_SwcModeNotification_DcmDiagnosticSessionControl] */
  { /*    10 */  2U, BSWM_FALSE    , BswM_Rule_CC_A_FlexRay_372befd6_TX                       },  /* [R_CC_A_FlexRay_372befd6_TX, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  { /*    11 */ 18U, BSWM_FALSE    , BswM_Rule_Rule_NDC_Enable_Rx_Enable_Tx                   },  /* [R_Rule_NDC_Enable_Rx_Enable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  { /*    12 */  1U, BSWM_FALSE    , BswM_Rule_CC_A_FlexRay_372befd6_RX                       },  /* [R_CC_A_FlexRay_372befd6_RX, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  { /*    13 */ 29U, BSWM_FALSE    , BswM_Rule_Rule_Vin_Initialize                            },  /* [R_Rule_Vin_Initialize, MRP_SwcModeNotification_Vin_LifeCycle] */
  { /*    14 */ 15U, BSWM_FALSE    , BswM_Rule_Rule_NDC_Disable_Rx_Disable_Tx                 },  /* [R_Rule_NDC_Disable_Rx_Disable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  { /*    15 */  6U, BSWM_FALSE    , BswM_Rule_Rule_Com_PduGroup4Enabled                      },  /* [R_Rule_Com_PduGroup4Enabled, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  { /*    16 */ 13U, BSWM_FALSE    , BswM_Rule_Rule_Dlog_Run                                  },  /* [R_Rule_Dlog_Run, MRP_SwcModeNotification_Dlog_LifeCycle] */
  { /*    17 */ 16U, BSWM_FALSE    , BswM_Rule_Rule_NDC_Disable_Rx_Enable_Tx                  },  /* [R_Rule_NDC_Disable_Rx_Enable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  { /*    18 */  8U, BSWM_FALSE    , BswM_Rule_Rule_Darh_Run                                  },  /* [R_Rule_Darh_Run, MRP_SwcModeNotification_Darh_LifeCycle] */
  { /*    19 */ 10U, BSWM_FALSE    , BswM_Rule_Rule_Dcm_HardReset                             },  /* [R_Rule_Dcm_HardReset, MRP_Dcm_HardResetTimer] */
  { /*    20 */ 24U, BSWM_FALSE    , BswM_Rule_Rule_Start_StdDiag_Init_when_Omc_Run           },  /* [R_Rule_Start_StdDiag_Init_when_Omc_Run, MRP_SwcModeNotification_Omc_LifeCycle, MRP_SwcModeNotification_Dlog_LifeCycle, MRP_SwcModeNotification_StdDiag_LifeCycle] */
  { /*    21 */  9U, BSWM_FALSE    , BswM_Rule_Rule_Dcm_EcuResetForReprogramming              },  /* [R_Rule_Dcm_EcuResetForReprogramming, MRP_SwcModeNotification_DcmEcuReset, MRP_SwcModeNotification_DcmDiagnosticSessionControl] */
  { /*    22 */ 28U, BSWM_FALSE    , BswM_Rule_Rule_Systime_Init                              },  /* [R_Rule_Systime_Init, MRP_SwcModeNotification_SysTime_LifeCycle] */
  { /*    23 */  3U, BSWM_FALSE    , BswM_Rule_Rule_Coding_Init                               },  /* [R_Rule_Coding_Init, MRP_SwcModeNotification_Coding_LifeCycle, MRP_SwcModeNotification_Dlog_LifeCycle, MRP_NvmJobModeIndication_NvmReadAllCompleted] */
  { /*    24 */ 12U, BSWM_FALSE    , BswM_Rule_Rule_Dlog_Init                                 },  /* [R_Rule_Dlog_Init, MRP_SwcModeNotification_Dlog_LifeCycle] */
  { /*    25 */ 23U, BSWM_UNDEFINED, BswM_Rule_Rule_Set_DarhReportError_due_ComM_and_CEL_mode },  /* [R_Rule_Set_DarhReportError_due_ComM_and_CEL_mode, MRP_SWCModeSwitch_currentCentralErrorLockMode, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  { /*    26 */  7U, BSWM_FALSE    , BswM_Rule_Rule_Darh_Init                                 },  /* [R_Rule_Darh_Init, MRP_SwcModeNotification_Darh_LifeCycle] */
  { /*    27 */ 11U, BSWM_FALSE    , BswM_Rule_Rule_Dcm_HardResetStartTimer                   },  /* [R_Rule_Dcm_HardResetStartTimer, MRP_SwcModeNotification_DcmEcuReset] */
  { /*    28 */  4U, BSWM_FALSE    , BswM_Rule_Rule_Coding_Run                                },  /* [R_Rule_Coding_Run, MRP_SwcModeNotification_Coding_LifeCycle] */
  { /*    29 */  0U, BSWM_FALSE    , BswM_Rule_Rule_Coding_BusComSwitch                       }   /* [R_Rule_Coding_BusComSwitch, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesInd
**********************************************************************************************************************/
/** 
  \var    BswM_RulesInd
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesInd[15] = {
  /* Index    RulesInd      Referable Keys */
  /*     0 */       5U,  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     1 */       8U,  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     2 */      10U,  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     3 */      12U,  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     4 */      15U,  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     5 */      25U,  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     6 */      29U,  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     7 */       0U,  /* [MRP_BswMSt] */
  /*     8 */       1U,  /* [MRP_BswMSt] */
  /*     9 */       2U,  /* [MRP_BswMSt] */
  /*    10 */       3U,  /* [MRP_BswMSt] */
  /*    11 */       6U,  /* [MRP_StdDiag_ComControlModeRequest] */
  /*    12 */      11U,  /* [MRP_StdDiag_ComControlModeRequest] */
  /*    13 */      14U,  /* [MRP_StdDiag_ComControlModeRequest] */
  /*    14 */      17U   /* [MRP_StdDiag_ComControlModeRequest] */
};
#define BSWM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_ActionListQueueType, BSWM_VAR_NOINIT) BswM_ActionListQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [AL_AL_Run] */
  /*     1 */  /* [AL_AL_GoOffOne] */
  /*     2 */  /* [AL_AL_PrepShtdwn] */
  /*     3 */  /* [AL_AL_Rstrt] */
  /*     4 */  /* [AL_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit] */
  /*     5 */  /* [AL_AL_Stop_SysTime] */
  /*     6 */  /* [AL_AL_Run_Vin] */
  /*     7 */  /* [AL_AL_Initialize_Darh] */
  /*     8 */  /* [AL_AL_StdDiag_SessionChangeToDefaultSession] */
  /*     9 */  /* [AL_AL_Run_Dlog] */
  /*    10 */  /* [AL_AL_Stop_Darh] */
  /*    11 */  /* [AL_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit] */
  /*    12 */  /* [AL_AL_NDC_Disable_Rx_And_Tx_Normal] */
  /*    13 */  /* [AL_AL_Initialize_Vin] */
  /*    14 */  /* [AL_AL_Stop_Omc] */
  /*    15 */  /* [AL_CC_AL_A_FlexRay_372befd6_TX_Disable] */
  /*    16 */  /* [AL_AL_Stop_StdDiag] */
  /*    17 */  /* [AL_AL_Run_StdDiag] */
  /*    18 */  /* [AL_AL_Rule_Systime_Init_True] */
  /*    19 */  /* [AL_AL_NDC_Enable_RX_Disable_TX_NORMAL] */
  /*    20 */  /* [AL_AL_NDC_Disable_RX_Enable_TX_NORMAL] */
  /*    21 */  /* [AL_AL_Initialize_Omc] */
  /*    22 */  /* [AL_AL_Stop_Dlog] */
  /*    23 */  /* [AL_AL_Run_Darh] */
  /*    24 */  /* [AL_AL_COM_PDU_GROUP_3_ENABLED] */
  /*    25 */  /* [AL_AL_NDC_Enable_RX_AND_TX_NORMAL] */
  /*    26 */  /* [AL_AL_COM_PDU_GROUP_4_DISABLED] */
  /*    27 */  /* [AL_AL_Initialize_StdDiag] */
  /*    28 */  /* [AL_AL_COM_PDU_GROUP_4_ENABLED] */
  /*    29 */  /* [AL_AL_StdDiag_SessionChangeToOtherSession] */
  /*    30 */  /* [AL_AL_COM_PDU_GROUP_3_DISABLED] */
  /*    31 */  /* [AL_AL_Run_Omc] */
  /*    32 */  /* [AL_AL_Initialize_Dlog] */
  /*    33 */  /* [AL_AL_Rule_Start_Systime_Run_when_Systime_Init_True] */
  /*    34 */  /* [AL_AL_Stop_Vin] */
  /*    35 */  /* [AL_CC_AL_A_FlexRay_372befd6_RX_Disable] */
  /*    36 */  /* [AL_INIT_AL_Initialize] */
  /*    37 */  /* [AL_AL_Dcm_ShutDown_HardReset] */
  /*    38 */  /* [AL_AL_Dcm_ShutDown_EcuReset] */
  /*    39 */  /* [AL_AL_Initialize_Coding] */
  /*    40 */  /* [AL_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False] */
  /*    41 */  /* [AL_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True] */
  /*    42 */  /* [AL_AL_Dcm_HardResetStartTimer] */
  /*    43 */  /* [AL_AL_Run_Coding] */
  /*    44 */  /* [AL_AL_Stop_Coding] */
  /*    45 */  /* [AL_AL_Coding_BusComOff] */
  /*    46 */  /* [AL_AL_Coding_BusComOn] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_FrSMState
**********************************************************************************************************************/
/** 
  \var    BswM_FrSMState
  \brief  Variable to store current mode of BswMFrSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(FrSM_BswM_StateType, BSWM_VAR_NOINIT) BswM_FrSMState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [FRSM_CHANNEL_0, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_NOINIT) BswM_GenericState[2];
  /* Index        Referable Keys  */
  /*     0 */  /* [GENERIC_0, MRP_BswMSt] */
  /*     1 */  /* [GENERIC_1, MRP_BswM_ShutdownReason] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_ZERO_INIT) BswM_Initialized = FALSE;
#define BSWM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NOINIT) BswM_ModeRequestQueue[4];
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_CC_FrSMIndication_A_FlexRay_372befd6, FRSM_CHANNEL_0] */
  /*     1 */  /* [MRP_BswMSt, GENERIC_0] */
  /*     2 */  /* [MRP_BswM_ShutdownReason, GENERIC_1] */
  /*     3 */  /* [MRP_StdDiag_ComControlModeRequest, SWC_REQUEST_0] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_NvMJobState
**********************************************************************************************************************/
/** 
  \var    BswM_NvMJobState
  \brief  Variable to store current mode of BswMNvMJobModeIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(NvM_RequestResultType, BSWM_VAR_NOINIT) BswM_NvMJobState[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [NVM_JOB_0, MRP_NvmJobModeIndication_NvmReadAllCompleted] */

#define BSWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(BswM_RuleStatesType, BSWM_VAR_NOINIT) BswM_RuleStates[30];
  /* Index        Referable Keys  */
  /*     0 */  /* [R_Rule_GoOffOne, MRP_BswMSt] */
  /*     1 */  /* [R_Rule_PrepShtdwn, MRP_BswMSt, MRP_SysStMod] */
  /*     2 */  /* [R_Rule_Rst, MRP_BswMSt] */
  /*     3 */  /* [R_Rule_Run, MRP_BswMSt] */
  /*     4 */  /* [R_Rule_OMC_INITIALIZE, MRP_SwcModeNotification_Omc_LifeCycle] */
  /*     5 */  /* [R_Rule_Com_PduGroup3Enabled, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     6 */  /* [R_Rule_NDC_Enable_Rx_Disable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  /*     7 */  /* [R_Rule_Start_StdDiag_Run_when_StdDiag_Init, MRP_SwcModeNotification_StdDiag_LifeCycle] */
  /*     8 */  /* [R_Rule_Start_Systime_Run_when_Systime_Init, MRP_SwcModeNotification_SysTime_LifeCycle, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*     9 */  /* [R_Rule_Switch_StdDiagSessionChangeIndication, MRP_SwcModeNotification_DcmDiagnosticSessionControl] */
  /*    10 */  /* [R_CC_A_FlexRay_372befd6_TX, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*    11 */  /* [R_Rule_NDC_Enable_Rx_Enable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  /*    12 */  /* [R_CC_A_FlexRay_372befd6_RX, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*    13 */  /* [R_Rule_Vin_Initialize, MRP_SwcModeNotification_Vin_LifeCycle] */
  /*    14 */  /* [R_Rule_NDC_Disable_Rx_Disable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  /*    15 */  /* [R_Rule_Com_PduGroup4Enabled, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*    16 */  /* [R_Rule_Dlog_Run, MRP_SwcModeNotification_Dlog_LifeCycle] */
  /*    17 */  /* [R_Rule_NDC_Disable_Rx_Enable_Tx, MRP_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6, MRP_StdDiag_ComControlModeRequest] */
  /*    18 */  /* [R_Rule_Darh_Run, MRP_SwcModeNotification_Darh_LifeCycle] */
  /*    19 */  /* [R_Rule_Dcm_HardReset, MRP_Dcm_HardResetTimer] */
  /*    20 */  /* [R_Rule_Start_StdDiag_Init_when_Omc_Run, MRP_SwcModeNotification_Omc_LifeCycle, MRP_SwcModeNotification_Dlog_LifeCycle, MRP_SwcModeNotification_StdDiag_LifeCycle] */
  /*    21 */  /* [R_Rule_Dcm_EcuResetForReprogramming, MRP_SwcModeNotification_DcmEcuReset, MRP_SwcModeNotification_DcmDiagnosticSessionControl] */
  /*    22 */  /* [R_Rule_Systime_Init, MRP_SwcModeNotification_SysTime_LifeCycle] */
  /*    23 */  /* [R_Rule_Coding_Init, MRP_SwcModeNotification_Coding_LifeCycle, MRP_SwcModeNotification_Dlog_LifeCycle, MRP_NvmJobModeIndication_NvmReadAllCompleted] */
  /*    24 */  /* [R_Rule_Dlog_Init, MRP_SwcModeNotification_Dlog_LifeCycle] */
  /*    25 */  /* [R_Rule_Set_DarhReportError_due_ComM_and_CEL_mode, MRP_SWCModeSwitch_currentCentralErrorLockMode, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */
  /*    26 */  /* [R_Rule_Darh_Init, MRP_SwcModeNotification_Darh_LifeCycle] */
  /*    27 */  /* [R_Rule_Dcm_HardResetStartTimer, MRP_SwcModeNotification_DcmEcuReset] */
  /*    28 */  /* [R_Rule_Coding_Run, MRP_SwcModeNotification_Coding_LifeCycle] */
  /*    29 */  /* [R_Rule_Coding_BusComSwitch, MRP_CC_FrSMIndication_A_FlexRay_372befd6] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_TimerStateType, BSWM_VAR_NOINIT) BswM_TimerState;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_Dcm_HardResetTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(uBswM_TimerValueType, BSWM_VAR_NOINIT) BswM_TimerValue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [MRP_Dcm_HardResetTimer] */

#define BSWM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_ExecuteIpduGroupControl()
 **********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_ExecuteIpduGroupControl(void)
{
  Com_IpduGroupVector ipduGroupState;
  uint16 iCnt;
  uint8 controlInvocation = BSWM_GROUPCONTROL_IDLE;

  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if(BswM_PduGroupControlInvocation != BSWM_GROUPCONTROL_IDLE)
  {
    if((BswM_PduGroupControlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
    {
      iCnt = BSWM_IPDUGROUPVECTORSIZE;
      while(iCnt-- > (uint16)0x0000) /* PRQA S 3440 */ /* MD_BswM_3440 */
      {
        ipduGroupState[iCnt] = BswM_ComIPduGroupState[iCnt]; /* SBSW_BSWM_SETIPDUGROUPVECTOR */
      }
    }
    controlInvocation = BswM_PduGroupControlInvocation;
    BswM_PduGroupControlInvocation = BSWM_GROUPCONTROL_IDLE;
  }
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if(controlInvocation != BSWM_GROUPCONTROL_IDLE)
  {
    if((controlInvocation & BSWM_GROUPCONTROL_NORMAL) != 0u)
    {
      Com_IpduGroupControl(ipduGroupState, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
    }
  }
} /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */


/**********************************************************************************************************************
 *  BswM_UpdateRuleStates()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateRuleStates(BswM_SizeOfRuleStatesType ruleId, BswM_RuleStatesType state)
{
  if (ruleId < BswM_GetSizeOfRuleStates())
  {
    BswM_SetRuleStates(ruleId, state); /* SBSW_BSWM_SETRULESTATE */
  }
}

/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_SizeOfTimerValueType timerId, BswM_TimerValueType value)
{
  if (timerId < BswM_GetSizeOfTimerValue())
  {
      SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      BswM_SetTimerValue(timerId, value); /* SBSW_BSWM_SETTIMER */
      BswM_SetTimerState(timerId, (BswM_TimerStateType)((value != 0u) ? BSWM_TIMER_STARTED : BSWM_TIMER_STOPPED)); /* SBSW_BSWM_SETTIMER */
      SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
}

/**********************************************************************************************************************
 *  BswM_Init_Gen
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Init_Gen(void)
{

  BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode = 0xFF;
  BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup = 0xFF;
  BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup = 0xFF;
  BswM_Switch_VinComSwitchPort_Mode = 0xFF;
  BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode = 0xFF;
  BswM_Switch_Coding_BusComModeSwitch_Mode = 0xFF;
  BswM_RteRequest_Provide_MSRP_Omc_requestMode = 0xFFU;
  BswM_RteRequest_Provide_MSRP_Dlog_requestMode = 0xFFU;
  BswM_RteRequest_Provide_MSRP_StdDiag_requestMode = 0xFFU;
  BswM_RteRequest_Provide_MSRP_SysTime_requestMode = 0xFFU;
  BswM_RteRequest_Provide_MSRP_Darh_requestMode = 0xFFU;
  BswM_RteRequest_Provide_MSRP_Vin_requestMode = 0xFFU;
  BswM_RteRequest_Provide_MSRP_Coding_requestMode = 0xFFU;
  Request_StdDiag_ComControlModeRequest_requestedMode = DISABLE_RX_AND_TX_NORMAL;
  BswM_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode = RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED;
  BswM_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode = RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED;
  BswM_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode = RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED;
  BswM_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode = RTE_MODE_Omc_LifeCycle_OMC_STOPPED;
  BswM_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION;
  BswM_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode = RTE_MODE_Darh_LifeCycle_DARH_STOPPED;
  BswM_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode = RTE_MODE_Vin_LifeCycle_VIN_STOPPED;
  BswM_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset = RTE_MODE_DcmEcuReset_NONE;
  BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM;
  BswM_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode = RTE_MODE_Coding_LifeCycle_CODING_STOPPED;
  BswM_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode = RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID;
  BswM_PduGroupControlInvocation = BSWM_GROUPCONTROL_IDLE;

  /* PRQA S 3109 COMCLEARIPDU */ /* MD_BswM_3109 */
  Com_ClearIpduGroupVector(BswM_ComIPduGroupState); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMCLEARIPDU */

  (void)BswM_ActionList_INIT_AL_Initialize();
}

/**********************************************************************************************************************
 *  BswMRteRequestFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Read_StdDiag_ComControlModeRequest
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_Read_StdDiag_ComControlModeRequest(void)
{
  (void)Rte_Read_Request_StdDiag_ComControlModeRequest_requestedMode(&Request_StdDiag_ComControlModeRequest_requestedMode);  /* SBSW_BSWM_RTE_READ */
  BswM_ImmediateSwcRequest(0);
}

/**********************************************************************************************************************
 *  BswM_ImmediateSwcRequest
 *********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_ImmediateSwcRequest(BswM_SizeOfModeRequestMappingType requestId)
{
  if(requestId < BswM_GetSizeOfModeRequestMapping())
  {
    BswM_ImmediateModeRequest(BswM_GetImmediateUserStartIdxOfModeRequestMapping(requestId), BswM_GetImmediateUserEndIdxOfModeRequestMapping(requestId), BSWM_SWCREQUESTMODE_ID);
  }
}

/**********************************************************************************************************************
 *  BswM_ModeNotificationFct
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_ModeNotificationFct(void)
{
  if(BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode != 0xFF)
  {
    if(Rte_Switch_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode(BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode) == RTE_E_OK)
    {
      BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode = 0xFF;
    }
  }
  if(BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup != 0xFF)
  {
    if(Rte_Switch_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup(BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup) == RTE_E_OK)
    {
      BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup = 0xFF;
    }
  }
  if(BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup != 0xFF)
  {
    if(Rte_Switch_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup(BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup) == RTE_E_OK)
    {
      BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup = 0xFF;
    }
  }
  if(BswM_Switch_VinComSwitchPort_Mode != 0xFF)
  {
    if(Rte_Switch_Switch_VinComSwitchPort_Mode(BswM_Switch_VinComSwitchPort_Mode) == RTE_E_OK)
    {
      BswM_Switch_VinComSwitchPort_Mode = 0xFF;
    }
  }
  if(BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode != 0xFF)
  {
    if(Rte_Switch_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode(BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode) == RTE_E_OK)
    {
      BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode = 0xFF;
    }
  }
  if(BswM_Switch_Coding_BusComModeSwitch_Mode != 0xFF)
  {
    if(Rte_Switch_Switch_Coding_BusComModeSwitch_Mode(BswM_Switch_Coding_BusComModeSwitch_Mode) == RTE_E_OK)
    {
      BswM_Switch_Coding_BusComModeSwitch_Mode = 0xFF;
    }
  }
  if(BswM_RteRequest_Provide_MSRP_Omc_requestMode != 0xFFU)
  {
    if(Rte_Write_Provide_MSRP_Omc_requestMode(BswM_RteRequest_Provide_MSRP_Omc_requestMode) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_MSRP_Omc_requestMode = 0xFFU;
    }
  }
  if(BswM_RteRequest_Provide_MSRP_Dlog_requestMode != 0xFFU)
  {
    if(Rte_Write_Provide_MSRP_Dlog_requestMode(BswM_RteRequest_Provide_MSRP_Dlog_requestMode) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_MSRP_Dlog_requestMode = 0xFFU;
    }
  }
  if(BswM_RteRequest_Provide_MSRP_StdDiag_requestMode != 0xFFU)
  {
    if(Rte_Write_Provide_MSRP_StdDiag_requestMode(BswM_RteRequest_Provide_MSRP_StdDiag_requestMode) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_MSRP_StdDiag_requestMode = 0xFFU;
    }
  }
  if(BswM_RteRequest_Provide_MSRP_SysTime_requestMode != 0xFFU)
  {
    if(Rte_Write_Provide_MSRP_SysTime_requestMode(BswM_RteRequest_Provide_MSRP_SysTime_requestMode) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_MSRP_SysTime_requestMode = 0xFFU;
    }
  }
  if(BswM_RteRequest_Provide_MSRP_Darh_requestMode != 0xFFU)
  {
    if(Rte_Write_Provide_MSRP_Darh_requestMode(BswM_RteRequest_Provide_MSRP_Darh_requestMode) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_MSRP_Darh_requestMode = 0xFFU;
    }
  }
  if(BswM_RteRequest_Provide_MSRP_Vin_requestMode != 0xFFU)
  {
    if(Rte_Write_Provide_MSRP_Vin_requestMode(BswM_RteRequest_Provide_MSRP_Vin_requestMode) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_MSRP_Vin_requestMode = 0xFFU;
    }
  }
  if(BswM_RteRequest_Provide_MSRP_Coding_requestMode != 0xFFU)
  {
    if(Rte_Write_Provide_MSRP_Coding_requestMode(BswM_RteRequest_Provide_MSRP_Coding_requestMode) == RTE_E_OK)
    {
      BswM_RteRequest_Provide_MSRP_Coding_requestMode = 0xFFU;
    }
  }
}

/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct(void)
{
  uint32 mode;
  mode = Rte_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode();
  if (mode != RTE_TRANSITION_Dlog_LifeCycle)
  {
    BswM_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode = (Rte_ModeType_Dlog_LifeCycle)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode();
  if (mode != RTE_TRANSITION_StdDiag_LifeCycle)
  {
    BswM_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode = (Rte_ModeType_StdDiag_LifeCycle)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode();
  if (mode != RTE_TRANSITION_SysTime_LifeCycle)
  {
    BswM_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode = (Rte_ModeType_SysTime_LifeCycle)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode();
  if (mode != RTE_TRANSITION_Omc_LifeCycle)
  {
    BswM_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode = (Rte_ModeType_Omc_LifeCycle)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl();
  if (mode != RTE_TRANSITION_DcmDiagnosticSessionControl)
  {
    BswM_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = (Rte_ModeType_DcmDiagnosticSessionControl)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode();
  if (mode != RTE_TRANSITION_Darh_LifeCycle)
  {
    BswM_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode = (Rte_ModeType_Darh_LifeCycle)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode();
  if (mode != RTE_TRANSITION_Vin_LifeCycle)
  {
    BswM_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode = (Rte_ModeType_Vin_LifeCycle)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset();
  if (mode != RTE_TRANSITION_DcmEcuReset)
  {
    BswM_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset = (Rte_ModeType_DcmEcuReset)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6();
  if (mode != RTE_TRANSITION_DcmCommunicationControl)
  {
    BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 = (Rte_ModeType_DcmCommunicationControl)mode;
  }
  mode = Rte_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode();
  if (mode != RTE_TRANSITION_Coding_LifeCycle)
  {
    BswM_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode = (Rte_ModeType_Coding_LifeCycle)mode;
  }
  mode = Rte_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode();
  if (mode != RTE_TRANSITION_Stm_CentralErrorLockMode)
  {
    BswM_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode = (Rte_ModeType_Stm_CentralErrorLockMode)mode;
  }
}

/**********************************************************************************************************************
 *  BswMActionListFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run(void)
{
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_GoOffOne
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_GoOffOne(void)
{
  BswM_SHUTDOWN_NvMWriteAll();
  BswM_FinalizeShtdwn();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_PrepShtdwn
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_PrepShtdwn(void)
{
  (void)BswM_ActionList_AL_Stop_Darh();
  (void)BswM_ActionList_AL_Stop_Dlog();
  (void)BswM_ActionList_AL_Stop_Omc();
  (void)BswM_ActionList_AL_Stop_StdDiag();
  (void)BswM_ActionList_AL_Stop_SysTime();
  (void)BswM_ActionList_AL_Stop_Vin();
  (void)BswM_ActionList_AL_Stop_Coding();
  BwmM_GetShutdownOngoing();
  BswM_ShtdwnHndlg_PrepShutdown();
  BswM_DiagcMgrPwrDwn();
  BswM_RequestMode(BSWM_GENERIC_BswMSt, BSWM_GENERICVALUE_BswMSt_GoOffOne);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Rstrt
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Rstrt(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Dem_Init(NULL_PTR);
  /*lint -restore */
  BswM_RequestMode(BSWM_GENERIC_BswMSt, BSWM_GENERICVALUE_BswMSt_Run);
  BswM_Restart();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup2, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup2, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup3, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup3, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup4, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup4, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup5, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup5, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup6, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup6, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup7, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup7, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup8, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup8, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup9, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup9, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup10, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup10, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Stop_SysTime
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_SysTime(void)
{
  BswM_RteRequest_Provide_MSRP_SysTime_requestMode = SYSTIME_STOPPED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_Vin
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Vin(void)
{
  BswM_RteRequest_Provide_MSRP_Vin_requestMode = VIN_RUNNING;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Initialize_Darh
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Darh(void)
{
  BswM_RteRequest_Provide_MSRP_Darh_requestMode = DARH_INITIALIZED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_StdDiag_SessionChangeToDefaultSession
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_StdDiag_SessionChangeToDefaultSession(void)
{
  BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup = RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_Dlog
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Dlog(void)
{
  BswM_RteRequest_Provide_MSRP_Dlog_requestMode = DLOG_RUNNING;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Stop_Darh
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Darh(void)
{
  BswM_RteRequest_Provide_MSRP_Darh_requestMode = DARH_STOPPED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup2, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup2, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup3, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup3, TRUE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NDC_Disable_Rx_And_Tx_Normal
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Disable_Rx_And_Tx_Normal(void)
{
  BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup = RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Initialize_Vin
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Vin(void)
{
  BswM_RteRequest_Provide_MSRP_Vin_requestMode = VIN_INITIALIZED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Stop_Omc
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Omc(void)
{
  BswM_RteRequest_Provide_MSRP_Omc_requestMode = OMC_STOPPED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup2, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup2, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup3, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_OUT_PduGroup3, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Stop_StdDiag
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_StdDiag(void)
{
  BswM_RteRequest_Provide_MSRP_StdDiag_requestMode = STDDIAG_STOPPED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_StdDiag
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_StdDiag(void)
{
  BswM_RteRequest_Provide_MSRP_StdDiag_requestMode = STDDIAG_RUNNING;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Rule_Systime_Init_True
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Rule_Systime_Init_True(void)
{
  BswM_RteRequest_Provide_MSRP_SysTime_requestMode = SYSTIME_INITIALIZED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NDC_Enable_RX_Disable_TX_NORMAL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Enable_RX_Disable_TX_NORMAL(void)
{
  BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup = RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NDC_Disable_RX_Enable_TX_NORMAL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Disable_RX_Enable_TX_NORMAL(void)
{
  BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup = RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Initialize_Omc
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Omc(void)
{
  BswM_RteRequest_Provide_MSRP_Omc_requestMode = OMC_INITIALIZED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Stop_Dlog
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Dlog(void)
{
  BswM_RteRequest_Provide_MSRP_Dlog_requestMode = DLOG_STOPPED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_Darh
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Darh(void)
{
  BswM_RteRequest_Provide_MSRP_Darh_requestMode = DARH_RUNNING;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_COM_PDU_GROUP_3_ENABLED
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_3_ENABLED(void)
{
  BswM_Switch_VinComSwitchPort_Mode = RTE_MODE_Vin_VinComMode_VIN_VINCOMON;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_NDC_Enable_RX_AND_TX_NORMAL
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_NDC_Enable_RX_AND_TX_NORMAL(void)
{
  BswM_Switch_StdDiagComControlNormalNotificationPort_CommunicationModeDeclarationGroup = RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_COM_PDU_GROUP_4_DISABLED
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_4_DISABLED(void)
{
  BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode = RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Initialize_StdDiag
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_StdDiag(void)
{
  BswM_RteRequest_Provide_MSRP_StdDiag_requestMode = STDDIAG_INITIALIZED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_COM_PDU_GROUP_4_ENABLED
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_4_ENABLED(void)
{
  BswM_Switch_ErrorMemoryLockSignalReceptionSwitchPort_currentEMLockSignalReceptionMode = RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_StdDiag_SessionChangeToOtherSession
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_StdDiag_SessionChangeToOtherSession(void)
{
  BswM_Switch_StdDiagSessionChangeIndicationPort_SessionModeDeclarationGroup = RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_OTHER_SESSION;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_COM_PDU_GROUP_3_DISABLED
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_COM_PDU_GROUP_3_DISABLED(void)
{
  BswM_Switch_VinComSwitchPort_Mode = RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_Omc
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Omc(void)
{
  BswM_RteRequest_Provide_MSRP_Omc_requestMode = OMC_RUNNING;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Initialize_Dlog
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Dlog(void)
{
  BswM_RteRequest_Provide_MSRP_Dlog_requestMode = DLOG_INITIALIZED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Rule_Start_Systime_Run_when_Systime_Init_True
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Rule_Start_Systime_Run_when_Systime_Init_True(void)
{
  BswM_RteRequest_Provide_MSRP_SysTime_requestMode = SYSTIME_RUNNING;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Stop_Vin
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Vin(void)
{
  BswM_RteRequest_Provide_MSRP_Vin_requestMode = VIN_STOPPED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_Disable
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_Disable(void)
{
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup2, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup2, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup3, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup3, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup4, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup4, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup5, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup5, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup6, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup6, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup7, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup7, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup8, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup8, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup9, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup9, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup10, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  /* PRQA S 0277, 3109, 3201, 3325 COMSETIPDU */ /* MD_BswM_0277, MD_BswM_3109, MD_BswM_3201, MD_BswM_3325 */ /*lint -e506 -e572 */
  BswM_SetIpduDMGroup(ComConf_ComIPduGroup_EPS_IN_PduGroup10, FALSE); /* SBSW_BSWM_IPDUGROUPVECTORCALL */
  /* PRQA L:COMSETIPDU */ /*lint +e506 +e572 */
  BswM_MarkPduGroupControlInvocation(BSWM_GROUPCONTROL_NORMAL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_INIT_AL_Initialize
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_INIT_AL_Initialize(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Fee_30_SmallSector_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  NvM_Init();
  /*lint -restore */
  BswM_INIT_NvMReadAll();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Dem_Init(NULL_PTR);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Dem_SetOperationCycleState(0,0);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Os_Call_NxtrWdgM_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  GuardCfgAndDiagcInit1();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  SyncCrcInit0();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  FlsMemInit2();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  E2EProtectionWrapperInit();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  FrTrcv_30_Tja1082_Init();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Fr_Init(&Fr_Config);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  FrIf_Init(&FrIf_Config);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Com_Init(Com_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  IpduM_Init(IpduM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  PduR_Init(PduR_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  FrSM_Init(FrSM_Config_Ptr);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  FrTp_Init(&FrTp_Config);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  FrXcp_Init(NULL_PTR);
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Xcp_Init();
  /*lint -restore */
  BswM_AL_SetProgrammableInterrupts();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  ComM_Init();
  /*lint -restore */
  ComM_CommunicationAllowed(ComMConf_ComMChannel_A_FlexRay_372befd6, TRUE);
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Dcm_Init(NULL_PTR);
  /*lint -restore */
  (void)ComM_RequestComMode(ComMConf_ComMUser_USR_A_FlexRay_372befd6, COMM_FULL_COMMUNICATION);
  (void)BswM_ActionList_AL_Initialize_Omc();
  (void)BswM_ActionList_AL_Initialize_Vin();
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  (void)Rte_Start();
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  Os_ModifyPeripheral32(InterruptController, (uint32 *)0xFFFEEAF0U, 0xFFFEFFFFU, 0x0U);;
  /*lint -restore */
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  OSTM0TS = 1U;
  /*lint -restore */
  BswM_RequestMode(BSWM_GENERIC_BswMSt, BSWM_GENERICVALUE_BswMSt_Run);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Dcm_ShutDown_HardReset
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Dcm_ShutDown_HardReset(void)
{
  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BswM_3200 */
  NxtrSwRst(MCUDIAGC_PWRONRST,0u);
  /*lint -restore */
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Dcm_ShutDown_EcuReset
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Dcm_ShutDown_EcuReset(void)
{
  BswM_RequestMode(BSWM_GENERIC_BswM_ShutdownReason, BSWM_GENERICVALUE_BswM_ShutdownReason_Prog);
  BswM_ShtdwnHndlg_PrepShutdown();
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Initialize_Coding
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Initialize_Coding(void)
{
  BswM_RteRequest_Provide_MSRP_Coding_requestMode = CODING_INITIALIZED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False(void)
{
  BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode = RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_INACTIVE;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True(void)
{
  BswM_Switch_SwitchPort_Darh_ReportErrorMode_DarhReportErrorMode = RTE_MODE_DarhReportErrorMode_DARH_REPORT_ERROR_ACTIVE;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Dcm_HardResetStartTimer
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Dcm_HardResetStartTimer(void)
{
  BswM_UpdateTimer(BSWM_TMR_Dcm_HardResetTimer, 300UL);
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Run_Coding
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Run_Coding(void)
{
  BswM_RteRequest_Provide_MSRP_Coding_requestMode = CODING_RUNNING;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Stop_Coding
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Stop_Coding(void)
{
  BswM_RteRequest_Provide_MSRP_Coding_requestMode = CODING_STOPPED;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Coding_BusComOff
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Coding_BusComOff(void)
{
  BswM_Switch_Coding_BusComModeSwitch_Mode = RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswM_ActionList_AL_Coding_BusComOn
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_ActionList_AL_Coding_BusComOn(void)
{
  BswM_Switch_Coding_BusComModeSwitch_Mode = RTE_MODE_Coding_BusComMode_CODING_BUSCOMON;
  return E_OK;
}/* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  BswMRuleFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Rule_Rule_GoOffOne
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_GoOffOne(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_GoOffOne) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_GoOffOne. */
    if(BswM_GetGenericState(0) == BSWM_GENERICVALUE_BswMSt_GoOffOne)
    {
      /* Return conditional action list BswM_ActionList_AL_GoOffOne. */
      retVal = BSWM_ID_AL_AL_GoOffOne;
    }
    /* No false action list configured. */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_PrepShtdwn
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_PrepShtdwn(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_PrepShtdwn) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_PrepShtdwn. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((BswM_GetGenericState(0) == BSWM_GENERICVALUE_BswMSt_PrepShtdwn) || (Rte_SysStMod_SysSt_Val == 1u))
    {
      /* Return conditional action list BswM_ActionList_AL_PrepShtdwn. */
      retVal = BSWM_ID_AL_AL_PrepShtdwn;
    }
    /* No false action list configured. */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Rst
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Rst(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Rst) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Restrt. */
    if(BswM_GetGenericState(0) == BSWM_GENERICVALUE_BswMSt_Rst)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Rst) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Rst, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Rstrt. */
        retVal = BSWM_ID_AL_AL_Rstrt;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Rst, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Run
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Run(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Run) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Run. */
    if(BswM_GetGenericState(0) == BSWM_GENERICVALUE_BswMSt_Run)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Run) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Run, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Run. */
        retVal = BSWM_ID_AL_AL_Run;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Run, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_OMC_INITIALIZE
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_OMC_INITIALIZE(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_OMC_INITIALIZE) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Omc_IsInitialized. */
    if(BswM_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode == RTE_MODE_Omc_LifeCycle_OMC_INITIALIZED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_OMC_INITIALIZE) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_OMC_INITIALIZE, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Run_Omc. */
        retVal = BSWM_ID_AL_AL_Run_Omc;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_OMC_INITIALIZE, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Com_PduGroup3Enabled
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Com_PduGroup3Enabled(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup3Enabled) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression CC_LE_A_FlexRay_372befd6_RX. */
    if((BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE) || (BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE_ECU_PASSIVE))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup3Enabled) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup3Enabled, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_COM_PDU_GROUP_3_ENABLED. */
        retVal = BSWM_ID_AL_AL_COM_PDU_GROUP_3_ENABLED;
      }
    }
    else
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup3Enabled) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup3Enabled, BSWM_FALSE);
        /* Return triggered action list BswM_ActionList_AL_COM_PDU_GROUP_3_DISABLED. */
        retVal = BSWM_ID_AL_AL_COM_PDU_GROUP_3_DISABLED;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_NDC_Enable_Rx_Disable_Tx
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Enable_Rx_Disable_Tx(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Disable_Tx) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_NDC_Rx_Enabled_Tx_Disabled. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_DISABLE_TX_NORMAL))) && (!(((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == DISABLE_RX_ENABLE_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL)))))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Disable_Tx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Disable_Tx, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_NDC_Enable_RX_Disable_TX_NORMAL. */
        retVal = BSWM_ID_AL_AL_NDC_Enable_RX_Disable_TX_NORMAL;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Disable_Tx, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Start_StdDiag_Run_when_StdDiag_Init
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Start_StdDiag_Run_when_StdDiag_Init(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Run_when_StdDiag_Init) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_StdDiag_IsInitialized. */
    if(BswM_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode == RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Run_when_StdDiag_Init) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Run_when_StdDiag_Init, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Run_StdDiag. */
        retVal = BSWM_ID_AL_AL_Run_StdDiag;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Run_when_StdDiag_Init, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Start_Systime_Run_when_Systime_Init
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Start_Systime_Run_when_Systime_Init(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Start_Systime_Run_when_Systime_Init) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Start_Systime_Run_when_Systime_Init. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((BswM_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode == RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED) && ((BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE) || (BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE_ECU_PASSIVE)))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Start_Systime_Run_when_Systime_Init) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Start_Systime_Run_when_Systime_Init, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Rule_Start_Systime_Run_when_Systime_Init_True. */
        retVal = BSWM_ID_AL_AL_Rule_Start_Systime_Run_when_Systime_Init_True;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Start_Systime_Run_when_Systime_Init, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Switch_StdDiagSessionChangeIndication
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Switch_StdDiagSessionChangeIndication(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Switch_StdDiagSessionChangeIndication) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_DiagSession_IsDefaultSession. */
    if(BswM_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl == RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Switch_StdDiagSessionChangeIndication) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Switch_StdDiagSessionChangeIndication, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_StdDiag_SessionChangeToDefaultSession. */
        retVal = BSWM_ID_AL_AL_StdDiag_SessionChangeToDefaultSession;
      }
    }
    else
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Switch_StdDiagSessionChangeIndication) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Switch_StdDiagSessionChangeIndication, BSWM_FALSE);
        /* Return triggered action list BswM_ActionList_AL_StdDiag_SessionChangeToOtherSession. */
        retVal = BSWM_ID_AL_AL_StdDiag_SessionChangeToOtherSession;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_A_FlexRay_372befd6_TX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_A_FlexRay_372befd6_TX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_TX) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression CC_LE_A_FlexRay_372befd6_TX. */
    if((BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE) || (BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE_ECU_PASSIVE))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_TX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_TX, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit. */
        retVal = BSWM_ID_AL_CC_AL_A_FlexRay_372befd6_TX_EnableNoinit;
      }
    }
    else
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_TX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_TX, BSWM_FALSE);
        /* Return triggered action list BswM_ActionList_CC_AL_A_FlexRay_372befd6_TX_Disable. */
        retVal = BSWM_ID_AL_CC_AL_A_FlexRay_372befd6_TX_Disable;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_NDC_Enable_Rx_Enable_Tx
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Enable_Rx_Enable_Tx(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Enable_Tx) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_NDC_Rx_Enabled_Tx_Enabled. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_DISABLE_TX_NORMAL))) && (((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == DISABLE_RX_ENABLE_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL))))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Enable_Tx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Enable_Tx, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_NDC_Enable_RX_AND_TX_NORMAL. */
        retVal = BSWM_ID_AL_AL_NDC_Enable_RX_AND_TX_NORMAL;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Enable_Rx_Enable_Tx, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_CC_A_FlexRay_372befd6_RX
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_CC_A_FlexRay_372befd6_RX(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_RX) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression CC_LE_A_FlexRay_372befd6_RX. */
    if((BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE) || (BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE_ECU_PASSIVE))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_RX) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_RX, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit. */
        retVal = BSWM_ID_AL_CC_AL_A_FlexRay_372befd6_RX_EnableNoinit;
      }
    }
    else
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_RX) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_CC_A_FlexRay_372befd6_RX, BSWM_FALSE);
        /* Return triggered action list BswM_ActionList_CC_AL_A_FlexRay_372befd6_RX_Disable. */
        retVal = BSWM_ID_AL_CC_AL_A_FlexRay_372befd6_RX_Disable;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Vin_Initialize
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Vin_Initialize(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Vin_Initialize) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Vin_IsInitialized. */
    if(BswM_Mode_Notification_SwcModeNotification_Vin_LifeCycle_Mode == RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Vin_Initialize) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Vin_Initialize, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Run_Vin. */
        retVal = BSWM_ID_AL_AL_Run_Vin;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Vin_Initialize, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_NDC_Disable_Rx_Disable_Tx
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Disable_Rx_Disable_Tx(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Disable_Tx) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_NDC_Rx_Disabled_Tx_Disabled. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((!(((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_DISABLE_TX_NORMAL)))) && (!(((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == DISABLE_RX_ENABLE_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL)))))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Disable_Tx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Disable_Tx, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_NDC_Disable_Rx_And_Tx_Normal. */
        retVal = BSWM_ID_AL_AL_NDC_Disable_Rx_And_Tx_Normal;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Disable_Tx, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Com_PduGroup4Enabled
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Com_PduGroup4Enabled(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup4Enabled) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression CC_LE_A_FlexRay_372befd6_RX. */
    if((BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE) || (BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE_ECU_PASSIVE))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup4Enabled) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup4Enabled, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_COM_PDU_GROUP_4_ENABLED. */
        retVal = BSWM_ID_AL_AL_COM_PDU_GROUP_4_ENABLED;
      }
    }
    else
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup4Enabled) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Com_PduGroup4Enabled, BSWM_FALSE);
        /* Return triggered action list BswM_ActionList_AL_COM_PDU_GROUP_4_DISABLED. */
        retVal = BSWM_ID_AL_AL_COM_PDU_GROUP_4_DISABLED;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Dlog_Run
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dlog_Run(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dlog_Run) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Dlog_IsInitialized. */
    if(BswM_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode == RTE_MODE_Dlog_LifeCycle_DLOG_INITIALIZED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dlog_Run) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dlog_Run, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Run_Dlog. */
        retVal = BSWM_ID_AL_AL_Run_Dlog;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dlog_Run, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_NDC_Disable_Rx_Enable_Tx
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_NDC_Disable_Rx_Enable_Tx(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Enable_Tx) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_NDC_Rx_Disabled_Tx_Enabled. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((!(((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_DISABLE_TX_NORMAL)))) && (((BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM) || (BswM_Mode_Notification_SwcModeNotification_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6 == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM)) && ((Request_StdDiag_ComControlModeRequest_requestedMode == DISABLE_RX_ENABLE_TX_NORMAL) || (Request_StdDiag_ComControlModeRequest_requestedMode == ENABLE_RX_AND_TX_NORMAL))))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Enable_Tx) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Enable_Tx, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_NDC_Disable_RX_Enable_TX_NORMAL. */
        retVal = BSWM_ID_AL_AL_NDC_Disable_RX_Enable_TX_NORMAL;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_NDC_Disable_Rx_Enable_Tx, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Darh_Run
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Darh_Run(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Darh_Run) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Darh_IsInitialized. */
    if(BswM_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode == RTE_MODE_Darh_LifeCycle_DARH_INITIALIZED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Darh_Run) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Darh_Run, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Run_Darh. */
        retVal = BSWM_ID_AL_AL_Run_Darh;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Darh_Run, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Dcm_HardReset
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dcm_HardReset(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dcm_HardReset) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_IsDcmHardResetTimerExpired. */
    if(BswM_GetTimerState(0) == BSWM_TIMER_EXPIRED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dcm_HardReset) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dcm_HardReset, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Dcm_ShutDown_HardReset. */
        retVal = BSWM_ID_AL_AL_Dcm_ShutDown_HardReset;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dcm_HardReset, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Start_StdDiag_Init_when_Omc_Run
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Start_StdDiag_Init_when_Omc_Run(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Init_when_Omc_Run) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Start_StdDiag_Init_when_Omc_Run_and_Dlog_Run. */
    if((BswM_Mode_Notification_SwcModeNotification_Omc_LifeCycle_Mode == RTE_MODE_Omc_LifeCycle_OMC_RUNNING) && (BswM_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode == RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING) && (BswM_Mode_Notification_SwcModeNotification_StdDiag_LifeCycle_Mode == RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Init_when_Omc_Run) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Init_when_Omc_Run, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Initialize_StdDiag. */
        retVal = BSWM_ID_AL_AL_Initialize_StdDiag;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Start_StdDiag_Init_when_Omc_Run, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Dcm_EcuResetForReprogramming
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dcm_EcuResetForReprogramming(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dcm_EcuResetForReprogramming) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_DcmEcuReset. */
    if((BswM_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset == RTE_MODE_DcmEcuReset_EXECUTE) && (BswM_Mode_Notification_SwcModeNotification_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl == RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dcm_EcuResetForReprogramming) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dcm_EcuResetForReprogramming, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Dcm_ShutDown_EcuReset. */
        retVal = BSWM_ID_AL_AL_Dcm_ShutDown_EcuReset;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dcm_EcuResetForReprogramming, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Systime_Init
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Systime_Init(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Systime_Init) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Set_Systime_Init. */
    if(BswM_Mode_Notification_SwcModeNotification_SysTime_LifeCycle_Mode == RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Systime_Init) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Systime_Init, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Rule_Systime_Init_True. */
        retVal = BSWM_ID_AL_AL_Rule_Systime_Init_True;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Systime_Init, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Coding_Init
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Coding_Init(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Coding_Init) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Coding_IsReadyToInit. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((BswM_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode == RTE_MODE_Coding_LifeCycle_CODING_STOPPED) && (BswM_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode == RTE_MODE_Dlog_LifeCycle_DLOG_RUNNING) && (BswM_GetNvMJobState(0) != NVM_REQ_PENDING))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Coding_Init) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Coding_Init, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Initialize_Coding. */
        retVal = BSWM_ID_AL_AL_Initialize_Coding;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Coding_Init, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Dlog_Init
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dlog_Init(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dlog_Init) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_IsDlogReadyToBeInitialized. */
    if(BswM_Mode_Notification_SwcModeNotification_Dlog_LifeCycle_Mode == RTE_MODE_Dlog_LifeCycle_DLOG_STOPPED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dlog_Init) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dlog_Init, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Initialize_Dlog. */
        retVal = BSWM_ID_AL_AL_Initialize_Dlog;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dlog_Init, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Set_DarhReportError_due_ComM_and_CEL_mode
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Set_DarhReportError_due_ComM_and_CEL_mode(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Set_DarhReportError_due_ComM_and_CEL_mode) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Set_DarhReportError_due_ComM_and_CEL_mode. */ /* PRQA S 3415 1 */ /* MD_MSR_12.4 */
    if((BswM_Mode_Notification_SWCModeSwitch_currentCentralErrorLockMode_currentCentralErrorLockMode != RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID) && ((BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE) || (BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE_PASSIVE)))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Set_DarhReportError_due_ComM_and_CEL_mode) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Set_DarhReportError_due_ComM_and_CEL_mode, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True. */
        retVal = BSWM_ID_AL_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_True;
      }
    }
    else
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Set_DarhReportError_due_ComM_and_CEL_mode) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Set_DarhReportError_due_ComM_and_CEL_mode, BSWM_FALSE);
        /* Return triggered action list BswM_ActionList_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False. */
        retVal = BSWM_ID_AL_AL_Set_DarhReportError_due_ComM_and_CEL_mode_BswMActionList_False;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Darh_Init
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Darh_Init(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Darh_Init) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_IsDarhReadyToBeInitialized. */
    if(BswM_Mode_Notification_SwcModeNotification_Darh_LifeCycle_Mode == RTE_MODE_Darh_LifeCycle_DARH_STOPPED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Darh_Init) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Darh_Init, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Initialize_Darh. */
        retVal = BSWM_ID_AL_AL_Initialize_Darh;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Darh_Init, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Dcm_HardResetStartTimer
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Dcm_HardResetStartTimer(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dcm_HardResetStartTimer) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_ECU_Hard_Reset. */
    if(BswM_Mode_Notification_SwcModeNotification_DcmEcuReset_DcmEcuReset == RTE_MODE_DcmEcuReset_HARD)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Dcm_HardResetStartTimer) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dcm_HardResetStartTimer, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Dcm_HardResetStartTimer. */
        retVal = BSWM_ID_AL_AL_Dcm_HardResetStartTimer;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Dcm_HardResetStartTimer, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Coding_Run
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Coding_Run(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Coding_Run) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_Coding_IsReadyToRun. */
    if(BswM_Mode_Notification_SwcModeNotification_Coding_LifeCycle_Mode == RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED)
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Coding_Run) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Coding_Run, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Run_Coding. */
        retVal = BSWM_ID_AL_AL_Run_Coding;
      }
    }
    else
    {
      BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Coding_Run, BSWM_FALSE);
      /* No false action list configured. */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BswM_Rule_Rule_Coding_BusComSwitch
 *********************************************************************************************************************/
BSWM_LOCAL FUNC(BswM_HandleType, BSWM_CODE) BswM_Rule_Rule_Coding_BusComSwitch(void)
{
  BswM_HandleType retVal = BSWM_NO_ACTIONLIST;
  if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Coding_BusComSwitch) != BSWM_DEACTIVATED )
  {
    /* Evaluate logical expression LogEx_IsFullComEnabled. */
    if((BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE) || (BswM_GetFrSMState(0) == FRSM_BSWM_ONLINE_PASSIVE))
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Coding_BusComSwitch) != BSWM_TRUE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Coding_BusComSwitch, BSWM_TRUE);
        /* Return triggered action list BswM_ActionList_AL_Coding_BusComOn. */
        retVal = BSWM_ID_AL_AL_Coding_BusComOn;
      }
    }
    else
    {
      if( BswM_GetRuleStates(BSWM_ID_RULE_Rule_Coding_BusComSwitch) != BSWM_FALSE ) /* COV_BSWM_TRIGGEREDRULEEXECUTION */
      {
        BswM_UpdateRuleStates(BSWM_ID_RULE_Rule_Coding_BusComSwitch, BSWM_FALSE);
        /* Return triggered action list BswM_ActionList_AL_Coding_BusComOff. */
        retVal = BSWM_ID_AL_AL_Coding_BusComOff;
      }
    }
  }
  return retVal;
}



#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

