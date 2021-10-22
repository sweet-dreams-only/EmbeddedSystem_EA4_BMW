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
 *            Module: FrSM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrSM_Cfg.h
 *   Generation Time: 2018-07-30 19:49:07
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


#if defined(FRSM_CFG_H)
#else
#define FRSM_CFG_H

/* -----------------------------------------------------------------------------
      Includes
 ----------------------------------------------------------------------------- */

#include "FrSM_Types.h"
#include "Fr_GeneralTypes.h"



/* -----------------------------------------------------------------------------
    Precompile Definitions
 ----------------------------------------------------------------------------- */


#define FRSM_VERSION_INFO_API                 STD_OFF
#define FRSM_ALLSLOTS_SUPPORT                 STD_OFF
#define FRSM_GET_WAKEUP_RX_STATUS_SUPPORT     STD_OFF
#define FRSM_ECU_PASSIVE_MODE                 STD_OFF
#define FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  STD_OFF


/* General Module Defines */
#ifndef FRSM_DEV_ERROR_DETECT
#define FRSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef FRSM_DEV_ERROR_REPORT
#define FRSM_DEV_ERROR_REPORT STD_ON
#endif
#ifndef FRSM_USE_DUMMY_FUNCTIONS
#define FRSM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FRSM_USE_DUMMY_STATEMENT
#define FRSM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FRSM_DUMMY_STATEMENT
#define FRSM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRSM_DUMMY_STATEMENT_CONST
#define FRSM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FRSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FRSM_ATOMIC_VARIABLE_ACCESS
#define FRSM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FRSM_PROCESSOR_RH850_1363
#define FRSM_PROCESSOR_RH850_1363
#endif
#ifndef FRSM_COMP_GREENHILLS
#define FRSM_COMP_GREENHILLS
#endif
#ifndef FRSM_GEN_GENERATOR_MSR
#define FRSM_GEN_GENERATOR_MSR
#endif
#ifndef FRSM_CPUTYPE_BITORDER_LSB2MSB
#define FRSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef FRSM_CONFIGURATION_VARIANT_PRECOMPILE
#define FRSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FRSM_CONFIGURATION_VARIANT_LINKTIME
#define FRSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FRSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FRSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FRSM_CONFIGURATION_VARIANT
#define FRSM_CONFIGURATION_VARIANT FRSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FRSM_POSTBUILD_VARIANT_SUPPORT
#define FRSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

 
#define FRSM_WAKEUP_ECU_ALL_CLUSTERS          FALSE




/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  FrSMPCGetConstantDuplicatedRootDataMacros  FrSM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define FrSM_GetClusterConfigOfPCConfig()                             FrSM_ClusterConfig  /**< the pointer to FrSM_ClusterConfig */
#define FrSM_GetSizeOfClusterConfigOfPCConfig()                       1U  /**< the number of accomplishable value elements in FrSM_ClusterConfig */
#define FrSM_GetVarStructOfPCConfig()                                 FrSM_VarStruct  /**< the pointer to FrSM_VarStruct */
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCGetDuplicatedRootDataMacros  FrSM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define FrSM_GetSizeOfVarStructOfPCConfig()                           FrSM_GetSizeOfClusterConfigOfPCConfig()  /**< the number of accomplishable value elements in FrSM_VarStruct */
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCGetDataMacros  FrSM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define FrSM_GetControllerIndexOfClusterConfig(Index)                 (FrSM_GetClusterConfigOfPCConfig()[(Index)].ControllerIndexOfClusterConfig)
#define FrSM_GetDurationT1OfClusterConfig(Index)                      (FrSM_GetClusterConfigOfPCConfig()[(Index)].DurationT1OfClusterConfig)
#define FrSM_GetDurationT2OfClusterConfig(Index)                      (FrSM_GetClusterConfigOfPCConfig()[(Index)].DurationT2OfClusterConfig)
#define FrSM_GetDurationT3OfClusterConfig(Index)                      (FrSM_GetClusterConfigOfPCConfig()[(Index)].DurationT3OfClusterConfig)
#define FrSM_GetDurationT4OfClusterConfig(Index)                      (FrSM_GetClusterConfigOfPCConfig()[(Index)].DurationT4OfClusterConfig)
#define FrSM_GetFrChannelOfClusterConfig(Index)                       (FrSM_GetClusterConfigOfPCConfig()[(Index)].FrChannelOfClusterConfig)
#define FrSM_GetFrIfClusterIndexOfClusterConfig(Index)                (FrSM_GetClusterConfigOfPCConfig()[(Index)].FrIfClusterIndexOfClusterConfig)
#define FrSM_GetNetworkHandleOfClusterConfig(Index)                   ((NetworkHandleType)FrSM_GetClusterConfigOfPCConfig()[(Index)].NetworkHandleOfClusterConfig)
#define FrSM_GetNumWakeupPatternsOfClusterConfig(Index)               (FrSM_GetClusterConfigOfPCConfig()[(Index)].NumWakeupPatternsOfClusterConfig)
#define FrSM_GetStartupRepetitionsOfClusterConfig(Index)              (FrSM_GetClusterConfigOfPCConfig()[(Index)].StartupRepetitionsOfClusterConfig)
#define FrSM_GetStartupRepetitionsWithWakeupOfClusterConfig(Index)    (FrSM_GetClusterConfigOfPCConfig()[(Index)].StartupRepetitionsWithWakeupOfClusterConfig)
#define FrSM_GetTrcvStbyDelayOfClusterConfig(Index)                   (FrSM_GetClusterConfigOfPCConfig()[(Index)].TrcvStbyDelayOfClusterConfig)
#define FrSM_IsTrcv_HandlingOfClusterConfig(Index)                    ((FrSM_GetClusterConfigOfPCConfig()[(Index)].Trcv_HandlingOfClusterConfig) != FALSE)
#define FrSM_GetInternalStateOfVarStruct(Index)                       (FrSM_GetVarStructOfPCConfig()[(Index)].InternalStateOfVarStruct)
#define FrSM_GetRequestedComModeOfVarStruct(Index)                    (FrSM_GetVarStructOfPCConfig()[(Index)].RequestedComModeOfVarStruct)
#define FrSM_GetStartup_CounterOfVarStruct(Index)                     (FrSM_GetVarStructOfPCConfig()[(Index)].Startup_CounterOfVarStruct)
#define FrSM_GetTimer_ColdstartDelayOfVarStruct(Index)                (FrSM_GetVarStructOfPCConfig()[(Index)].Timer_ColdstartDelayOfVarStruct)
#define FrSM_GetTimer_RetryStartUpOfVarStruct(Index)                  (FrSM_GetVarStructOfPCConfig()[(Index)].Timer_RetryStartUpOfVarStruct)
#define FrSM_GetTimer_StartUpMonitoringOfVarStruct(Index)             (FrSM_GetVarStructOfPCConfig()[(Index)].Timer_StartUpMonitoringOfVarStruct)
#define FrSM_GetWakeUpPatternCounterOfVarStruct(Index)                (FrSM_GetVarStructOfPCConfig()[(Index)].WakeUpPatternCounterOfVarStruct)
#define FrSM_GetWakeUpTypeOfVarStruct(Index)                          (FrSM_GetVarStructOfPCConfig()[(Index)].WakeUpTypeOfVarStruct)
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCGetDeduplicatedDataMacros  FrSM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define FrSM_GetSizeOfClusterConfig()                                 FrSM_GetSizeOfClusterConfigOfPCConfig()
#define FrSM_GetSizeOfVarStruct()                                     FrSM_GetSizeOfVarStructOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCSetDataMacros  FrSM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define FrSM_SetInternalStateOfVarStruct(Index, Value)                FrSM_GetVarStructOfPCConfig()[(Index)].InternalStateOfVarStruct = (Value)
#define FrSM_SetRequestedComModeOfVarStruct(Index, Value)             FrSM_GetVarStructOfPCConfig()[(Index)].RequestedComModeOfVarStruct = (Value)
#define FrSM_SetStartup_CounterOfVarStruct(Index, Value)              FrSM_GetVarStructOfPCConfig()[(Index)].Startup_CounterOfVarStruct = (Value)
#define FrSM_SetTimer_ColdstartDelayOfVarStruct(Index, Value)         FrSM_GetVarStructOfPCConfig()[(Index)].Timer_ColdstartDelayOfVarStruct = (Value)
#define FrSM_SetTimer_RetryStartUpOfVarStruct(Index, Value)           FrSM_GetVarStructOfPCConfig()[(Index)].Timer_RetryStartUpOfVarStruct = (Value)
#define FrSM_SetTimer_StartUpMonitoringOfVarStruct(Index, Value)      FrSM_GetVarStructOfPCConfig()[(Index)].Timer_StartUpMonitoringOfVarStruct = (Value)
#define FrSM_SetWakeUpPatternCounterOfVarStruct(Index, Value)         FrSM_GetVarStructOfPCConfig()[(Index)].WakeUpPatternCounterOfVarStruct = (Value)
#define FrSM_SetWakeUpTypeOfVarStruct(Index, Value)                   FrSM_GetVarStructOfPCConfig()[(Index)].WakeUpTypeOfVarStruct = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCHasMacros  FrSM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define FrSM_HasClusterConfig()                                       (TRUE != FALSE)
#define FrSM_HasControllerIndexOfClusterConfig()                      (TRUE != FALSE)
#define FrSM_HasDurationT1OfClusterConfig()                           (TRUE != FALSE)
#define FrSM_HasDurationT2OfClusterConfig()                           (TRUE != FALSE)
#define FrSM_HasDurationT3OfClusterConfig()                           (TRUE != FALSE)
#define FrSM_HasDurationT4OfClusterConfig()                           (TRUE != FALSE)
#define FrSM_HasFrChannelOfClusterConfig()                            (TRUE != FALSE)
#define FrSM_HasFrIfClusterIndexOfClusterConfig()                     (TRUE != FALSE)
#define FrSM_HasNetworkHandleOfClusterConfig()                        (TRUE != FALSE)
#define FrSM_HasNumWakeupPatternsOfClusterConfig()                    (TRUE != FALSE)
#define FrSM_HasStartupRepetitionsOfClusterConfig()                   (TRUE != FALSE)
#define FrSM_HasStartupRepetitionsWithWakeupOfClusterConfig()         (TRUE != FALSE)
#define FrSM_HasTrcvStbyDelayOfClusterConfig()                        (TRUE != FALSE)
#define FrSM_HasTrcv_HandlingOfClusterConfig()                        (TRUE != FALSE)
#define FrSM_HasSizeOfClusterConfig()                                 (TRUE != FALSE)
#define FrSM_HasSizeOfVarStruct()                                     (TRUE != FALSE)
#define FrSM_HasVarStruct()                                           (TRUE != FALSE)
#define FrSM_HasInternalStateOfVarStruct()                            (TRUE != FALSE)
#define FrSM_HasRequestedComModeOfVarStruct()                         (TRUE != FALSE)
#define FrSM_HasStartup_CounterOfVarStruct()                          (TRUE != FALSE)
#define FrSM_HasTimer_ColdstartDelayOfVarStruct()                     (TRUE != FALSE)
#define FrSM_HasTimer_RetryStartUpOfVarStruct()                       (TRUE != FALSE)
#define FrSM_HasTimer_StartUpMonitoringOfVarStruct()                  (TRUE != FALSE)
#define FrSM_HasWakeUpPatternCounterOfVarStruct()                     (TRUE != FALSE)
#define FrSM_HasWakeUpTypeOfVarStruct()                               (TRUE != FALSE)
#define FrSM_HasPCConfig()                                            (TRUE != FALSE)
#define FrSM_HasClusterConfigOfPCConfig()                             (TRUE != FALSE)
#define FrSM_HasSizeOfClusterConfigOfPCConfig()                       (TRUE != FALSE)
#define FrSM_HasSizeOfVarStructOfPCConfig()                           (TRUE != FALSE)
#define FrSM_HasVarStructOfPCConfig()                                 (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCIncrementDataMacros  FrSM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define FrSM_IncInternalStateOfVarStruct(Index)                       FrSM_GetInternalStateOfVarStruct(Index)++
#define FrSM_IncRequestedComModeOfVarStruct(Index)                    FrSM_GetRequestedComModeOfVarStruct(Index)++
#define FrSM_IncStartup_CounterOfVarStruct(Index)                     FrSM_GetStartup_CounterOfVarStruct(Index)++
#define FrSM_IncTimer_ColdstartDelayOfVarStruct(Index)                FrSM_GetTimer_ColdstartDelayOfVarStruct(Index)++
#define FrSM_IncTimer_RetryStartUpOfVarStruct(Index)                  FrSM_GetTimer_RetryStartUpOfVarStruct(Index)++
#define FrSM_IncTimer_StartUpMonitoringOfVarStruct(Index)             FrSM_GetTimer_StartUpMonitoringOfVarStruct(Index)++
#define FrSM_IncWakeUpPatternCounterOfVarStruct(Index)                FrSM_GetWakeUpPatternCounterOfVarStruct(Index)++
#define FrSM_IncWakeUpTypeOfVarStruct(Index)                          FrSM_GetWakeUpTypeOfVarStruct(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCDecrementDataMacros  FrSM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define FrSM_DecInternalStateOfVarStruct(Index)                       FrSM_GetInternalStateOfVarStruct(Index)--
#define FrSM_DecRequestedComModeOfVarStruct(Index)                    FrSM_GetRequestedComModeOfVarStruct(Index)--
#define FrSM_DecStartup_CounterOfVarStruct(Index)                     FrSM_GetStartup_CounterOfVarStruct(Index)--
#define FrSM_DecTimer_ColdstartDelayOfVarStruct(Index)                FrSM_GetTimer_ColdstartDelayOfVarStruct(Index)--
#define FrSM_DecTimer_RetryStartUpOfVarStruct(Index)                  FrSM_GetTimer_RetryStartUpOfVarStruct(Index)--
#define FrSM_DecTimer_StartUpMonitoringOfVarStruct(Index)             FrSM_GetTimer_StartUpMonitoringOfVarStruct(Index)--
#define FrSM_DecWakeUpPatternCounterOfVarStruct(Index)                FrSM_GetWakeUpPatternCounterOfVarStruct(Index)--
#define FrSM_DecWakeUpTypeOfVarStruct(Index)                          FrSM_GetWakeUpTypeOfVarStruct(Index)--
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  FrSMPCDataSwitches  FrSM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define FRSM_CLUSTERCONFIG                                            STD_ON
#define FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG                         STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.CheckWakeupReason' Reason: 'the value of FrSM_CheckWakeupReasonOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_COLDSTARTECUOFCLUSTERCONFIG                              STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.ColdstartEcu' Reason: 'the value of FrSM_ColdstartEcuOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_CONTROLLERINDEXOFCLUSTERCONFIG                           STD_ON
#define FRSM_DELAYSTARTUPWITHOUTWAKEUPOFCLUSTERCONFIG                 STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.DelayStartupWithoutWakeup' Reason: 'the value of FrSM_DelayStartupWithoutWakeupOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_DEMEVENTCLUSTERSTARTUPOFCLUSTERCONFIG                    STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.DemEventClusterStartup' Reason: 'Default assumption no DemEventID' */
#define FRSM_DEMEVENTCLUSTERSYNCLOSSOFCLUSTERCONFIG                   STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.DemEventClusterSyncLoss' Reason: 'Default assumption no DemEventID' */
#define FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG                      STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.Dual_Channel_Support' Reason: 'the value of FrSM_Dual_Channel_SupportOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_DURATIONT1OFCLUSTERCONFIG                                STD_ON
#define FRSM_DURATIONT2OFCLUSTERCONFIG                                STD_ON
#define FRSM_DURATIONT3OFCLUSTERCONFIG                                STD_ON
#define FRSM_DURATIONT4OFCLUSTERCONFIG                                STD_ON
#define FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG                    STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.Enable_Consecutive_Wup' Reason: 'the value of FrSM_Enable_Consecutive_WupOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_FRCHANNELOFCLUSTERCONFIG                                 STD_ON
#define FRSM_FRIFCLUSTERINDEXOFCLUSTERCONFIG                          STD_ON
#define FRSM_NETWORKHANDLEOFCLUSTERCONFIG                             STD_ON
#define FRSM_NUMWAKEUPPATTERNSOFCLUSTERCONFIG                         STD_ON
#define FRSM_STARTUP_UNLIMITEDOFCLUSTERCONFIG                         STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.StartUp_Unlimited' Reason: 'the value of FrSM_StartUp_UnlimitedOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_STARTUPREPETITIONSOFCLUSTERCONFIG                        STD_ON
#define FRSM_STARTUPREPETITIONSWITHWAKEUPOFCLUSTERCONFIG              STD_ON
#define FRSM_STARTUP_CLUSTER_PROD_ERROR_DETECTOFCLUSTERCONFIG         STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.Startup_Cluster_Prod_Error_Detect' Reason: 'the value of FrSM_Startup_Cluster_Prod_Error_DetectOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_SYNC_LOSS_CLUSTER_PROD_ERROR_DETECTOFCLUSTERCONFIG       STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.Sync_Loss_Cluster_Prod_Error_Detect' Reason: 'the value of FrSM_Sync_Loss_Cluster_Prod_Error_DetectOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG                 STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.Transceiver_Standby_Delay' Reason: 'the value of FrSM_Transceiver_Standby_DelayOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_TRCVSTBYDELAYOFCLUSTERCONFIG                             STD_ON
#define FRSM_TRCV_HANDLINGOFCLUSTERCONFIG                             STD_ON
#define FRSM_WAKEUP_UNLIMITEDOFCLUSTERCONFIG                          STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.WakeUp_Unlimited' Reason: 'the value of FrSM_WakeUp_UnlimitedOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_WAKEUPECUOFCLUSTERCONFIG                                 STD_OFF  /**< Deactivateable: 'FrSM_ClusterConfig.WakeupEcu' Reason: 'the value of FrSM_WakeupEcuOfClusterConfig is always 'false' due to this, the array is deactivated.' */
#define FRSM_FINALMAGICNUMBER                                         STD_OFF  /**< Deactivateable: 'FrSM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define FRSM_INITDATAHASHCODE                                         STD_OFF  /**< Deactivateable: 'FrSM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define FRSM_SIZEOFCLUSTERCONFIG                                      STD_ON
#define FRSM_SIZEOFVARSTRUCT                                          STD_ON
#define FRSM_VARSTRUCT                                                STD_ON
#define FRSM_INTERNALSTATEOFVARSTRUCT                                 STD_ON
#define FRSM_REQUESTEDCOMMODEOFVARSTRUCT                              STD_ON
#define FRSM_STARTUP_COUNTEROFVARSTRUCT                               STD_ON
#define FRSM_TIMER_COLDSTARTDELAYOFVARSTRUCT                          STD_ON
#define FRSM_TIMER_RETRYSTARTUPOFVARSTRUCT                            STD_ON
#define FRSM_TIMER_STARTUPMONITORINGOFVARSTRUCT                       STD_ON
#define FRSM_WAKEUPPATTERNCOUNTEROFVARSTRUCT                          STD_ON
#define FRSM_WAKEUPTYPEOFVARSTRUCT                                    STD_ON
#define FRSM_PCCONFIG                                                 STD_ON
#define FRSM_CLUSTERCONFIGOFPCCONFIG                                  STD_ON
#define FRSM_FINALMAGICNUMBEROFPCCONFIG                               STD_OFF  /**< Deactivateable: 'FrSM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define FRSM_INITDATAHASHCODEOFPCCONFIG                               STD_OFF  /**< Deactivateable: 'FrSM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define FRSM_SIZEOFCLUSTERCONFIGOFPCCONFIG                            STD_ON
#define FRSM_SIZEOFVARSTRUCTOFPCCONFIG                                STD_ON
#define FRSM_VARSTRUCTOFPCCONFIG                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCMinNumericValueDefines  FrSM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define FRSM_MIN_INTERNALSTATEOFVARSTRUCT                             0U
#define FRSM_MIN_STARTUP_COUNTEROFVARSTRUCT                           0U
#define FRSM_MIN_TIMER_COLDSTARTDELAYOFVARSTRUCT                      0U
#define FRSM_MIN_TIMER_RETRYSTARTUPOFVARSTRUCT                        0U
#define FRSM_MIN_TIMER_STARTUPMONITORINGOFVARSTRUCT                   0U
#define FRSM_MIN_WAKEUPPATTERNCOUNTEROFVARSTRUCT                      0U
#define FRSM_MIN_WAKEUPTYPEOFVARSTRUCT                                0U
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCMaxNumericValueDefines  FrSM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define FRSM_MAX_INTERNALSTATEOFVARSTRUCT                             255U
#define FRSM_MAX_STARTUP_COUNTEROFVARSTRUCT                           255U
#define FRSM_MAX_TIMER_COLDSTARTDELAYOFVARSTRUCT                      65535U
#define FRSM_MAX_TIMER_RETRYSTARTUPOFVARSTRUCT                        255U
#define FRSM_MAX_TIMER_STARTUPMONITORINGOFVARSTRUCT                   255U
#define FRSM_MAX_WAKEUPPATTERNCOUNTEROFVARSTRUCT                      255U
#define FRSM_MAX_WAKEUPTYPEOFVARSTRUCT                                255U
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCNoReferenceDefines  FrSM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define FRSM_NO_CONTROLLERINDEXOFCLUSTERCONFIG                        255U
#define FRSM_NO_FRIFCLUSTERINDEXOFCLUSTERCONFIG                       255U
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCIsReducedToDefineDefines  FrSM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define FRSM_ISDEF_CONTROLLERINDEXOFCLUSTERCONFIG                     STD_OFF
#define FRSM_ISDEF_DURATIONT1OFCLUSTERCONFIG                          STD_OFF
#define FRSM_ISDEF_DURATIONT2OFCLUSTERCONFIG                          STD_OFF
#define FRSM_ISDEF_DURATIONT3OFCLUSTERCONFIG                          STD_OFF
#define FRSM_ISDEF_DURATIONT4OFCLUSTERCONFIG                          STD_OFF
#define FRSM_ISDEF_FRCHANNELOFCLUSTERCONFIG                           STD_OFF
#define FRSM_ISDEF_FRIFCLUSTERINDEXOFCLUSTERCONFIG                    STD_OFF
#define FRSM_ISDEF_NETWORKHANDLEOFCLUSTERCONFIG                       STD_OFF
#define FRSM_ISDEF_NUMWAKEUPPATTERNSOFCLUSTERCONFIG                   STD_OFF
#define FRSM_ISDEF_STARTUPREPETITIONSOFCLUSTERCONFIG                  STD_OFF
#define FRSM_ISDEF_STARTUPREPETITIONSWITHWAKEUPOFCLUSTERCONFIG        STD_OFF
#define FRSM_ISDEF_TRCVSTBYDELAYOFCLUSTERCONFIG                       STD_OFF
#define FRSM_ISDEF_TRCV_HANDLINGOFCLUSTERCONFIG                       STD_OFF
#define FRSM_ISDEF_CLUSTERCONFIGOFPCCONFIG                            STD_ON
#define FRSM_ISDEF_VARSTRUCTOFPCCONFIG                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCEqualsAlwaysToDefines  FrSM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define FRSM_EQ2_CONTROLLERINDEXOFCLUSTERCONFIG                       
#define FRSM_EQ2_DURATIONT1OFCLUSTERCONFIG                            
#define FRSM_EQ2_DURATIONT2OFCLUSTERCONFIG                            
#define FRSM_EQ2_DURATIONT3OFCLUSTERCONFIG                            
#define FRSM_EQ2_DURATIONT4OFCLUSTERCONFIG                            
#define FRSM_EQ2_FRCHANNELOFCLUSTERCONFIG                             
#define FRSM_EQ2_FRIFCLUSTERINDEXOFCLUSTERCONFIG                      
#define FRSM_EQ2_NETWORKHANDLEOFCLUSTERCONFIG                         
#define FRSM_EQ2_NUMWAKEUPPATTERNSOFCLUSTERCONFIG                     
#define FRSM_EQ2_STARTUPREPETITIONSOFCLUSTERCONFIG                    
#define FRSM_EQ2_STARTUPREPETITIONSWITHWAKEUPOFCLUSTERCONFIG          
#define FRSM_EQ2_TRCVSTBYDELAYOFCLUSTERCONFIG                         
#define FRSM_EQ2_TRCV_HANDLINGOFCLUSTERCONFIG                         
#define FRSM_EQ2_CLUSTERCONFIGOFPCCONFIG                              FrSM_ClusterConfig
#define FRSM_EQ2_VARSTRUCTOFPCCONFIG                                  FrSM_VarStruct
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCSymbolicInitializationPointers  FrSM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define FrSM_Config_Ptr                                               NULL_PTR  /**< symbolic identifier which shall be used to initialize 'FrSM' */
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCInitializationSymbols  FrSM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define FrSM_Config                                                   NULL_PTR  /**< symbolic identifier which could be used to initialize 'FrSM */
/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCGeneral  FrSM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define FRSM_CHECK_INIT_POINTER                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define FRSM_FINAL_MAGIC_NUMBER                                       0x8E1EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of FrSM */
#define FRSM_INDIVIDUAL_POSTBUILD                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'FrSM' is not configured to be postbuild capable. */
#define FRSM_INIT_DATA                                                FRSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define FRSM_INIT_DATA_HASH_CODE                                      -134194613L  /**< the precompile constant to validate the initialization structure at initialization time of FrSM with a hashcode. The seed value is '0x8E1EU' */
#define FRSM_USE_ECUM_BSW_ERROR_HOOK                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define FRSM_USE_INIT_POINTER                                         STD_OFF  /**< STD_ON if the init pointer FrSM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  FrSMPCIterableTypes  FrSM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate FrSM_ClusterConfig */
typedef uint8_least FrSM_ClusterConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCIterableTypesWithSizeRelations  FrSM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate FrSM_VarStruct */
typedef FrSM_ClusterConfigIterType FrSM_VarStructIterType;

/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCValueTypes  FrSM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for FrSM_ControllerIndexOfClusterConfig */
typedef uint8 FrSM_ControllerIndexOfClusterConfigType;

/**   \brief  value based type definition for FrSM_DurationT1OfClusterConfig */
typedef uint8 FrSM_DurationT1OfClusterConfigType;

/**   \brief  value based type definition for FrSM_DurationT2OfClusterConfig */
typedef uint8 FrSM_DurationT2OfClusterConfigType;

/**   \brief  value based type definition for FrSM_DurationT3OfClusterConfig */
typedef uint8 FrSM_DurationT3OfClusterConfigType;

/**   \brief  value based type definition for FrSM_DurationT4OfClusterConfig */
typedef uint16 FrSM_DurationT4OfClusterConfigType;

/**   \brief  value based type definition for FrSM_FrIfClusterIndexOfClusterConfig */
typedef uint8 FrSM_FrIfClusterIndexOfClusterConfigType;

/**   \brief  value based type definition for FrSM_NetworkHandleOfClusterConfig */
typedef uint8 FrSM_NetworkHandleOfClusterConfigType;

/**   \brief  value based type definition for FrSM_NumWakeupPatternsOfClusterConfig */
typedef uint8 FrSM_NumWakeupPatternsOfClusterConfigType;

/**   \brief  value based type definition for FrSM_StartupRepetitionsOfClusterConfig */
typedef uint8 FrSM_StartupRepetitionsOfClusterConfigType;

/**   \brief  value based type definition for FrSM_StartupRepetitionsWithWakeupOfClusterConfig */
typedef uint8 FrSM_StartupRepetitionsWithWakeupOfClusterConfigType;

/**   \brief  value based type definition for FrSM_TrcvStbyDelayOfClusterConfig */
typedef uint8 FrSM_TrcvStbyDelayOfClusterConfigType;

/**   \brief  value based type definition for FrSM_Trcv_HandlingOfClusterConfig */
typedef boolean FrSM_Trcv_HandlingOfClusterConfigType;

/**   \brief  value based type definition for FrSM_SizeOfClusterConfig */
typedef uint8 FrSM_SizeOfClusterConfigType;

/**   \brief  value based type definition for FrSM_SizeOfVarStruct */
typedef uint8 FrSM_SizeOfVarStructType;

/**   \brief  value based type definition for FrSM_InternalStateOfVarStruct */
typedef uint8 FrSM_InternalStateOfVarStructType;

/**   \brief  value based type definition for FrSM_Startup_CounterOfVarStruct */
typedef uint8 FrSM_Startup_CounterOfVarStructType;

/**   \brief  value based type definition for FrSM_Timer_ColdstartDelayOfVarStruct */
typedef uint16 FrSM_Timer_ColdstartDelayOfVarStructType;

/**   \brief  value based type definition for FrSM_Timer_RetryStartUpOfVarStruct */
typedef uint8 FrSM_Timer_RetryStartUpOfVarStructType;

/**   \brief  value based type definition for FrSM_Timer_StartUpMonitoringOfVarStruct */
typedef uint8 FrSM_Timer_StartUpMonitoringOfVarStructType;

/**   \brief  value based type definition for FrSM_WakeUpPatternCounterOfVarStruct */
typedef uint8 FrSM_WakeUpPatternCounterOfVarStructType;

/**   \brief  value based type definition for FrSM_WakeUpTypeOfVarStruct */
typedef uint8 FrSM_WakeUpTypeOfVarStructType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  FrSMPCStructTypes  FrSM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in FrSM_ClusterConfig */
typedef struct sFrSM_ClusterConfigType
{
  FrSM_DurationT4OfClusterConfigType DurationT4OfClusterConfig;
  FrSM_Trcv_HandlingOfClusterConfigType Trcv_HandlingOfClusterConfig;
  FrSM_ControllerIndexOfClusterConfigType ControllerIndexOfClusterConfig;
  FrSM_DurationT1OfClusterConfigType DurationT1OfClusterConfig;
  FrSM_DurationT2OfClusterConfigType DurationT2OfClusterConfig;
  FrSM_DurationT3OfClusterConfigType DurationT3OfClusterConfig;
  FrSM_FrIfClusterIndexOfClusterConfigType FrIfClusterIndexOfClusterConfig;
  FrSM_NetworkHandleOfClusterConfigType NetworkHandleOfClusterConfig;
  FrSM_NumWakeupPatternsOfClusterConfigType NumWakeupPatternsOfClusterConfig;
  FrSM_StartupRepetitionsOfClusterConfigType StartupRepetitionsOfClusterConfig;
  FrSM_StartupRepetitionsWithWakeupOfClusterConfigType StartupRepetitionsWithWakeupOfClusterConfig;
  FrSM_TrcvStbyDelayOfClusterConfigType TrcvStbyDelayOfClusterConfig;
  Fr_ChannelType FrChannelOfClusterConfig;
} FrSM_ClusterConfigType;

/**   \brief  type used in FrSM_VarStruct */
typedef struct sFrSM_VarStructType
{
  FrSM_Timer_ColdstartDelayOfVarStructType Timer_ColdstartDelayOfVarStruct;
  FrSM_InternalStateOfVarStructType InternalStateOfVarStruct;
  FrSM_Startup_CounterOfVarStructType Startup_CounterOfVarStruct;
  FrSM_Timer_RetryStartUpOfVarStructType Timer_RetryStartUpOfVarStruct;
  FrSM_Timer_StartUpMonitoringOfVarStructType Timer_StartUpMonitoringOfVarStruct;
  FrSM_WakeUpPatternCounterOfVarStructType WakeUpPatternCounterOfVarStruct;
  FrSM_WakeUpTypeOfVarStructType WakeUpTypeOfVarStruct;
  ComM_ModeType RequestedComModeOfVarStruct;
} FrSM_VarStructType;

/** 
  \}
*/ 

/** 
  \defgroup  FrSMPCRootValueTypes  FrSM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in FrSM_PCConfig */
typedef struct sFrSM_PCConfigType
{
  uint8 FrSM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} FrSM_PCConfigType;

typedef FrSM_PCConfigType FrSM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  FrSM_ClusterConfig
**********************************************************************************************************************/
/** 
  \var    FrSM_ClusterConfig
  \brief  root config struct
  \details
  Element                         Description
  DurationT4                  
  Trcv_Handling               
  ControllerIndex             
  DurationT1                  
  DurationT2                  
  DurationT3                  
  FrIfClusterIndex            
  NetworkHandle               
  NumWakeupPatterns           
  StartupRepetitions          
  StartupRepetitionsWithWakeup
  TrcvStbyDelay               
  FrChannel                   
*/ 
#define FRSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(FrSM_ClusterConfigType, FRSM_CONST) FrSM_ClusterConfig[1];
#define FRSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  FrSM_VarStruct
**********************************************************************************************************************/
/** 
  \var    FrSM_VarStruct
  \details
  Element                    Description
  Timer_ColdstartDelay   
  InternalState          
  Startup_Counter        
  Timer_RetryStartUp     
  Timer_StartUpMonitoring
  WakeUpPatternCounter   
  WakeUpType             
  RequestedComMode       
*/ 
#define FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(FrSM_VarStructType, FRSM_VAR_NOINIT) FrSM_VarStruct[1];
#define FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/



/* -----------------------------------------------------------------------------
    Function Prototypes
 ----------------------------------------------------------------------------- */




#define FRSM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */


/*******************************************************************************************************************/
/*! \brief       FrSM_MainFunction determine the POC status of all FlexRay CC that are connected to the corresponding FlexRay cluster process the state machine of the corresponding cluster.
 *  \details     -
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      -
 *  \trace       -
 **********************************************************************************************************************/
FUNC( void, FRSM_CODE )FrSM_MainFunction( FrSM_SizeOfVarStructType FrSM_ClusterIndex );

/*******************************************************************************************************************/
/*! \brief       Calls the FrSM_MainFunction with the local cluster index
 *  \details     -
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      -
 *  \trace       -
 **********************************************************************************************************************/
extern FUNC(void, FRSM_CODE) FrSM_MainFunction_0(void);


#define FRSM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */



#endif /* FRSM_CFG_H */

