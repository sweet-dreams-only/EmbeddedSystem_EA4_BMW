
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------*/
/*         \file  FrSM.c
 *        \brief  FrSM source file
 *
 *      \details  Implementation of AUTOSAR FlexRay State Manager AUTOSAR Release 4
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-04-13  MFi     ESCAN00058511 Create Ccl_Asr4SmFr Implementation according to ASR 4.0.3
 *  01.01.00  2013-03-13  MFi     ESCAN00062540 FrIf_AllowColdstart is called several times in sequence
 *                                ESCAN00066690 Adapt FrSM to new BswM header structure Include  "BswM_FrSM.h" instead  "BswM.h"
 *                                ESCAN00066936 Correct compiler abstraction and memory mapping
 *                                ESCAN00067082 SetWakeupChannel not called in case of an internal dual channel wake up
 *  01.02.00  2013-09-23  MFi     ESCAN00069426 Memory Mapping not possible for variable FRSM_WakeUpTypeOfVarStruct, FRSM_StartupCounter and FRSM_WakeUpPatternCounter
 *  01.03.00  2014-01-23  MFi     ESCAN00071806 ECU communication not set to "ECU passive mode" (FRTRCV_TRCVMODE_RECEIVEONLY)
 *                                ESCAN00073139 Unlimited Startup repetitions also repeats wake-up (REPETITIONS_WITH_WAKEUP)
 *  01.04.00  2014-09-23  MFi     ESCAN00078750 Post-Build Selectable (Identity Manager)
 *                                ESCAN00075457 Add support for delayed FlexRay communication cluster shutdown
 *  01.04.01  2014-11-21  MFi     ESCAN00079315 FrSM stays in state HALT_REQ (Freeze not evaluated)
 *  01.05.00  2015-05-13  MFi     ESCAN00083893 Allow Wake Up Attempts On Both Channels
 *  02.00.00  2015-09-13  MFi     ESCAN00080304 FEAT-427:  SafeBSW Step I
 *                                ESCAN00085151 FEAT-1527: SafeBSW Step 3
 *                                ESCAN00084385 Only a single wakeup pattern is transmitted (even FrSMNumWakeupPatterns is greater one). Start FRSM_WakeUpPatternCounterOfVarStruct also in T20, resp. T20c
 *                                ESCAN00085133 Compiler error: API Det_ReportError missing
 *                                ESCAN00086137 The main function raises a Det error (FRSM_SID_MAINFUNCTION0, FRSM_E_UNINIT) (BSW00450)
 *                                ESCAN00086153 MISRA deviation: MISRA-C:2004 Rule 8.8 (external linkage of FrSM_ConfigPtr)
 *  02.01.00  2016-02-13  MFi     ESCAN00087808 FEAT-1688: SafeBSW Step 4
 *  02.02.00  2017-01-13  MFi     FEATC-1079    Multi Fr Cluster
 *  02.02.01  2017-11-23  MFi     ESCAN00097415 FlexRay communication not possible at  non wakeup cluster (multi cluster system, with mixed wakeup and non wakeup clusters, with deactivated check wake up reason)
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1 */

#define FRSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "BswM_FrSM.h"

#include "ComM.h"         /* needed because of communication manager modes */
#include "ComM_BusSM.h"  /* indication function */

#include "SchM_FrSM.h" /* interrupts blocked by ASR SchM */

#include "FrIf.h"
/* \trace SPEC-11008 */
#include "FrSM.h"
/* \trace SPEC-10995 */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
/* \trace SPEC-11030 */
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

#if (  ( FRSM_SW_MAJOR_VERSION != 0x02u ) || ( FRSM_SW_MINOR_VERSION != 0x02u ) || ( FRSM_SW_PATCH_VERSION != 0x00u )  )
/* \trace SPEC-10927 */
# error "File FrSM.c: Source and FrSM.h file are inconsistent!"
#endif
#if (  ( CCL_ASR4SMFR_VERSION != CCL_ASR4SMFR_TYPES_HEADER_VERSION ) || ( CCL_ASR4SMFR_RELEASE_VERSION != CCL_ASR4SMFR_TYPES_HEADER_RELEASE_VERSION )  )
# error "File FrSM.c: Source and FrSM_Types.h file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

#define FRSM_RX_STATUS_NO_WAKEUP_DETECTED           (0x00u)

/* values for  FRSM_WakeUpTypeOfVarStruct    */
#define FRSM_PERFORM_INITIAL_WAKEUP                 (0x00u)     /* no wakeup on any (active) channel   */
#define FRSM_PERFORM_STANDARD_WAKEUP                (0x00u)    /* SingleCh Wakeup OR WU_CHANNEL_INITIAL, WU_CHANNEL_FORWARD has been performed */
#define FRSM_PERFORM_SINGLE_CHANNEL_WAKEUP          (0x00u)
#define FRSM_WU_DETECTED_ON_CHANNEL_A               (0x01u)
#define FRSM_WU_DETECTED_ON_CHANNEL_B               (0x02u)

#define FRSM_PERFORM_NO_WAKEUP                      (0x03u)   /* WU on all channels (ALL_WU_BY_BUS) OR no wakeup ECU */
#define FRSM_WU_DETECTED_ON_ALL_CHANNELS            FRSM_PERFORM_NO_WAKEUP
#define FRSM_PERFORM_DUAL_CHANNEL_WAKEUP            (0x04u) /* DualChannel CH_AB; plain internal, NO_WU_BY_BUS, FE_SET_WU_CHANNEL_INITIAL  */

#define   FRSM_TIMER_COLDSTARTDELAY_USED            STD_OFF
#define   FRSM_RUN_TIMER_CS_TRCV_DELAY              STD_OFF

#if ( FRSM_COLDSTARTECUOFCLUSTERCONFIG == STD_ON )
# if (  ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON ) || ( FRSM_DELAYSTARTUPWITHOUTWAKEUPOFCLUSTERCONFIG == STD_ON )  )
#  undef  FRSM_TIMER_COLDSTARTDELAY_USED  /* PRQA S 0841 */  /* MD_MSR_19.6  */
#  define FRSM_TIMER_COLDSTARTDELAY_USED            STD_ON
#  undef  FRSM_RUN_TIMER_CS_TRCV_DELAY  /* PRQA S 0841 */  /* MD_MSR_19.6  */
#  define FRSM_RUN_TIMER_CS_TRCV_DELAY              STD_ON
# endif /* FRSM_WAKEUPECUOFCLUSTERCONFIG  FRSM_DELAYSTARTUPWITHOUTWAKEUPOFCLUSTERCONFIG   */
#endif /* FRSM_COLDSTARTECUOFCLUSTERCONFIG */

/* FRSM_TRANSITION_T02_NEEDED */
#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_OFF )
/* All clusters without wakeup configured */
# define FRSM_STARTUP_WITHOUT_WAKEUP_POSSIBLE       STD_ON
#elif ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON )
/* Some clusters without wakeup, depending on the wakeup type */
# define FRSM_STARTUP_WITHOUT_WAKEUP_POSSIBLE       STD_ON
#elif ( FRSM_WAKEUP_ECU_ALL_CLUSTERS == FALSE )
/* Some clusters without wakeup configured  */
# define FRSM_STARTUP_WITHOUT_WAKEUP_POSSIBLE       STD_ON
#else
/* All clusters with wakeup configured  */
# define FRSM_STARTUP_WITHOUT_WAKEUP_POSSIBLE       STD_OFF
#endif

#if ( FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG == STD_ON )

# undef  FRSM_RUN_TIMER_CS_TRCV_DELAY  /* PRQA S 0841 */  /* MD_MSR_19.6  */
# define FRSM_RUN_TIMER_CS_TRCV_DELAY     STD_ON

# define FrSM_SetTrcvStbyDelay                    FrSM_SetTimer_ColdstartDelayOfVarStruct
# define FrSM_GetTrcvStbyDelay                    FrSM_GetTimer_ColdstartDelayOfVarStruct
# define FrSM_DecTrcvStbyDelay                    FrSM_DecTimer_ColdstartDelayOfVarStruct

#endif /*  TRANSCEIVER_STANDBY_DELAY ) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* To provide compatibility, the component defines a FRSM_LOCAL on its own. */
#if !defined ( FRSM_LOCAL ) /* COV_FRSM_CHECKDEFINE */
# define FRSM_LOCAL static
#endif
#if !defined ( FRSM_LOCAL_INLINE ) /* COV_FRSM_CHECKDEFINE */
# define FRSM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define FRSM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/* \trace SPEC-10922 */
/*! Initialization state of the module */
FRSM_LOCAL VAR( boolean, FRSM_VAR_ZERO_INIT ) FRSM_IsInitialized = FALSE;

#define FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FRSM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
# if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
/*! Ecu passive mode of the module */
FRSM_LOCAL VAR( boolean, FRSM_VAR_NOINIT )  FrSM_EcuPassiveMode;
# else
#  define FrSM_EcuPassiveMode   0
# endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */
#else
# define FrSM_EcuPassiveMode   0
#endif /* ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */

#define FRSM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( FRSM_USE_INIT_POINTER == STD_ON )
#define FRSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*! Pointer to the current configuration */
FRSM_LOCAL P2CONST( FrSM_ConfigType, FRSM_VAR_ZERO_INIT, FRSM_INIT_DATA ) FrSM_ConfigDataPtr = NULL_PTR;
# define FRSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* ( FRSM_USE_INIT_POINTER == STD_ON ) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FRSM_START_SEC_CODE
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  FrSM_MapNetworkHandleToLocalIndex()
 **********************************************************************************************************************/
/*! \brief        Map network handle to local index
 *  \details      Determines the local index from the passed index
 *  \param[in]    FrSM_NetworkHandle                   identification number of the network
 *  \return       FrSM Index - valid if given handle was found otherwise value out of range
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(FrSM_SizeOfVarStructType, FRSM_CODE) FrSM_MapNetworkHandleToLocalIndex( NetworkHandleType NetworkHandle );

/**********************************************************************************************************************
  FrSM_HandleComModeRequest
 **********************************************************************************************************************/
/*! \brief        Handles valid communication mode request
 *  \details      Memorizes the communication mode and triggers short transitions i.e. without hardware mode changes
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_HandleComModeRequest( FrSM_SizeOfVarStructType FrSM_ClusterIndex );

#if (   ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) && (  ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) || ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_ON ) )  )
/**********************************************************************************************************************
  FrSM_DetermineWakeupReason
 **********************************************************************************************************************/
/*! \brief        Determine the wake up reason
 *  \details      Determine the wake up reason by evaluating the transceiver and controller
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG FRSM_TRCV_HANDLINGOFCLUSTERCONFIG FRSM_GET_WAKEUP_RX_STATUS_SUPPORT
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_DetermineWakeupReason( FrSM_SizeOfVarStructType FrSM_ClusterIndex );
#endif /*  FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG FRSM_TRCV_HANDLINGOFCLUSTERCONFIG FRSM_GET_WAKEUP_RX_STATUS_SUPPORT */

/**********************************************************************************************************************
  FrSM_TimerTriggeredTransitions
 **********************************************************************************************************************/
/*! \brief        Evaluate timers ColdstartDelay, RetryStartUp and StartUpMonitoring
 *  \details      Evaluate the timer and triggers the according transition, T05 T06 T04 T30 T31 T32 T33
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_TimerTriggeredTransitions( FrSM_SizeOfVarStructType FrSM_ClusterIndex );

#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
/**********************************************************************************************************************
  FrSM_StateWakeup
 **********************************************************************************************************************/
/*! \brief        Handles the wake up state
 *  \details      Performs the wakeup pattern transmission and if finished, switches to state startup
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       FRSM_WAKEUPECUOFCLUSTERCONFIG
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_StateWakeup( FrSM_SizeOfVarStructType FrSM_ClusterIndex, Fr_POCStateType  FrSM_CurrentPocStatusState, Fr_WakeupStateType  FrSM_CurrentPocStatusWakeupStatus );
#endif /* WakeupEcu FRSM_WAKEUPECUOFCLUSTERCONFIG */

/**********************************************************************************************************************
  FrSM_StateStartOnline
 **********************************************************************************************************************/
/*! \brief        Handles the states startup, online, online passive, keyslot only
 *  \details      Performs the transition triggered by protocol operation control status in case the internal state is not ready and not wakeup and not halt requested
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_StateStartOnline( FrSM_SizeOfVarStructType FrSM_ClusterIndex, Fr_POCStateType  FrSM_CurrentPocStatusState, Fr_SlotModeType FrSM_CurrentPocStatusSlotMode );

/**********************************************************************************************************************
  FrSM_RunTimer
 **********************************************************************************************************************/
/*! \brief        Handles timers ColdstartDelay, RetryStartUp and StartUpMonitoring
 *  \details      Updates the timer cold start delay, timer retry start up and timer start up monitoring
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_RunTimer( FrSM_SizeOfVarStructType FrSM_ClusterIndex );

/**********************************************************************************************************************
  FrSM_StateReady
 **********************************************************************************************************************/
/*! \brief        Handles the state ready
 *  \details      Performs the transition T01 or T02 if the requested communication mode is equal to full communication
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_StateReady( FrSM_SizeOfVarStructType FrSM_ClusterIndex );

#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
/**********************************************************************************************************************
  FrSM_StartTrcv
 **********************************************************************************************************************/
/*! \brief        Starts the transceiver
 *  \details      Sets the transceiver mode to NORMAL or RECEIVEONLY;  T01 T02 T05 T06
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       FRSM_TRCV_HANDLINGOFCLUSTERCONFIG
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL FUNC( void, FRSM_CODE ) FrSM_StartTrcv( FrSM_SizeOfVarStructType FrSM_ClusterIndex );
#endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

/**********************************************************************************************************************
  FrSM_StopTrcvGoToReady
 **********************************************************************************************************************/
/*! \brief        Stops the transceiver
 *  \details      Sets the transceiver mode to STANDBY and informs BswM;  T11 T12 T13
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL FUNC( void, FRSM_CODE ) FrSM_StopTrcvGoToReady( FrSM_SizeOfVarStructType FrSM_ClusterIndex );

/**********************************************************************************************************************
  FrSM_FrGoOffline
 **********************************************************************************************************************/
/*! \brief        Exit the state online
 *  \details      Set FrIf state to GOTO_OFFLINE and informs ComM;  T10 T16 T20
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
FRSM_LOCAL FUNC( void, FRSM_CODE ) FrSM_FrGoOffline( FrSM_SizeOfVarStructType FrSM_ClusterIndex );

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FrSM_MapNetworkHandleToLocalIndex
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(FrSM_SizeOfVarStructType, FRSM_CODE) FrSM_MapNetworkHandleToLocalIndex( NetworkHandleType NetworkHandle )
{
  FrSM_VarStructIterType FrSM_ClusterIndex;

  /* lint -e442  -e440 */
  for ( FrSM_ClusterIndex = 0; FrSM_ClusterIndex < FrSM_GetSizeOfVarStruct( ); FrSM_ClusterIndex ++ ) /* lint +e442 +e440 */
  {
    if ( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ) == NetworkHandle )
    {
      break;
    } /* NetworkHandle index in list ==> NetworkHandle valid */
  }

  return (FrSM_SizeOfVarStructType)FrSM_ClusterIndex;

} /* FrSM_MapNetworkHandleToLocalIndex */

/********************************************************************************************************************
 * FUNCTION: FrSM_FrGoOffline
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FRSM_LOCAL FUNC( void, FRSM_CODE ) FrSM_FrGoOffline( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{
  ComM_ModeType           FrSM_ComMMode       = COMM_NO_COMMUNICATION;   /* CREQ-105686 */

  (void)FrIf_SetState( FrSM_GetFrIfClusterIndexOfClusterConfig( FrSM_ClusterIndex ), FRIF_GOTO_OFFLINE );
  /* \trace SPEC-11007 */
  ComM_BusSM_ModeIndication ( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), &FrSM_ComMMode );   /* CREQ-105686 */  /* SBSW_FRSM_COMMMODEINDICATION_CALL */
#if ( FRSM_DEMEVENTCLUSTERSYNCLOSSOFCLUSTERCONFIG == STD_ON )
  if ( FrSM_IsSync_Loss_Cluster_Prod_Error_DetectOfClusterConfig( FrSM_ClusterIndex ) )  /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
  {
    FrSM_Dem_ReportErrorEvent( FrSM_GetDemEventClusterSyncLossOfClusterConfig( FrSM_ClusterIndex ), DEM_EVENT_STATUS_FAILED );
  }
#endif

  FrSM_SetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT3OfClusterConfig( FrSM_ClusterIndex ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex,  FRSM_BSWM_ONLINE_PASSIVE ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

}    /* end FrSM_FrGoOffline() */

#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
/********************************************************************************************************************
 * FUNCTION: FrSM_StartTrcv
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FRSM_LOCAL FUNC( void, FRSM_CODE ) FrSM_StartTrcv( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{
  FrTrcv_TrcvModeType     FrSM_TrcvMode       = FRTRCV_TRCVMODE_NORMAL;

  if ( FrSM_IsTrcv_HandlingOfClusterConfig( FrSM_ClusterIndex ) )  /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
  {
    /* T01 T02 FrSM_SetEcuPassive() */
#if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
    if ( FrSM_EcuPassiveMode == TRUE )
    {
      FrSM_TrcvMode = FRTRCV_TRCVMODE_RECEIVEONLY;
      /* \trace SPEC-10939 */
    }
#endif /* ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */

    if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_B ) /* COV_FRSM_CONFIG_PARAMETER_DUAL_ALWAYS_TRUE */
    {
      (void)FrIf_SetTransceiverMode( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_A, FrSM_TrcvMode );
      /* \trace SPEC-11007 */
      /* \trace SPEC-11019 */
    }
    if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_A ) /* COV_FRSM_CONFIG_PARAMETER_DUAL_ALWAYS_TRUE */
    {
      (void)FrIf_SetTransceiverMode( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_B, FrSM_TrcvMode );
      /* \trace SPEC-11007 */
      /* \trace SPEC-11019 */
    }
  }

}    /* end FrSM_StartTrcv() */
#endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

/********************************************************************************************************************
 * FUNCTION: FrSM_StopTrcvGoToReady
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FRSM_LOCAL FUNC( void, FRSM_CODE ) FrSM_StopTrcvGoToReady( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{
  /* T11 T12 T13 */
#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
  if ( FrSM_IsTrcv_HandlingOfClusterConfig( FrSM_ClusterIndex ) )  /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
  {
    if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_B ) /* COV_FRSM_CONFIG_PARAMETER_DUAL_ALWAYS_TRUE */
    {
      (void)FrIf_SetTransceiverMode( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_A, FRTRCV_TRCVMODE_STANDBY );
      /* \trace SPEC-11007 */
    }
    if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_A ) /* COV_FRSM_CONFIG_PARAMETER_DUAL_ALWAYS_TRUE */
    {
      (void)FrIf_SetTransceiverMode( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_B, FRTRCV_TRCVMODE_STANDBY );
      /* \trace SPEC-11007 */
    }
  }
#endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

  (void)FrIf_ControllerInit( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
  /* \trace SPEC-11007 */

  FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_READY ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  BswM_FrSM_CurrentState( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), (FrSM_BswM_StateType)( FRSM_BSWM_READY + (uint8)FrSM_EcuPassiveMode ) );
  /* \trace  SPEC-11009 */

}    /* end FrSM_StopTrcvGoToReady() */

/**********************************************************************************************************************
  FrSM_HandleComModeRequest
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_HandleComModeRequest( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{
  ComM_ModeType           FrSM_ComMMode       = COMM_NO_COMMUNICATION;  /* CREQ-105686 */

  /* transitions of the state machine be processed in this context in order to quicken the timing  */
  if ( FrSM_GetRequestedComModeOfVarStruct( FrSM_ClusterIndex ) == COMM_NO_COMMUNICATION )
  {
    SchM_Enter_FrSM_FRSM_EXCLUSIVE_AREA_2( );   /* FrSM_Mainfunction interrupts * T10 T16 T17 FrSM_RequestComMode T14 T09 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */

#if ( FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG == STD_ON )
    FrSM_SetTrcvStbyDelay( FrSM_ClusterIndex, FrSM_GetTrcvStbyDelayOfClusterConfig( FrSM_ClusterIndex ) ); /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#endif /* if ( FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG == STD_ON ) */

    /* Transition T09 (ONLINE to HALT_REQ) Condition: [ reqComMode = NoCom ] */
    if (  ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE )
#if ( FRSM_ALLSLOTS_SUPPORT == STD_ON )
        || ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_KEYSLOT_ONLY )
#endif /* if ( FRSM_ALLSLOTS_SUPPORT == STD_ON ) */
       )
    {
      (void)FrIf_SetState( FrSM_GetFrIfClusterIndexOfClusterConfig( FrSM_ClusterIndex ), FRIF_GOTO_OFFLINE );
      /* \trace SPEC-11007 */
      (void)FrIf_HaltCommunication( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
      /* \trace SPEC-11007 */
      FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_HALT_REQ ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      ComM_BusSM_ModeIndication( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), &FrSM_ComMMode );   /* CREQ-105686 */  /* SBSW_FRSM_COMMMODEINDICATION_CALL */
      BswM_FrSM_CurrentState( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), (FrSM_BswM_StateType)( FRSM_BSWM_HALT_REQ + (uint8)FrSM_EcuPassiveMode ) );
      /* \trace  SPEC-11009 */

    }    /* end if Transition T09 */
    /* Transition T14 (ONLINE_PASSIVE to HALT_REQ) Condition: [ reqComMode = NoCom ] */
    else if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE_PASSIVE )
    {
      (void)FrIf_HaltCommunication( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
      /* \trace SPEC-11007 */
      FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_HALT_REQ ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      BswM_FrSM_CurrentState( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), (FrSM_BswM_StateType)( FRSM_BSWM_HALT_REQ + (uint8)FrSM_EcuPassiveMode ) );
      /* \trace  SPEC-11009 */
#if ( FRSM_DEMEVENTCLUSTERSYNCLOSSOFCLUSTERCONFIG == STD_ON )
      if ( FrSM_IsSync_Loss_Cluster_Prod_Error_DetectOfClusterConfig( FrSM_ClusterIndex ) )   /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
      {
        FrSM_Dem_ReportErrorEvent( FrSM_GetDemEventClusterSyncLossOfClusterConfig( FrSM_ClusterIndex ), DEM_EVENT_STATUS_PASSED );
      }
#endif
      /* no need to set FRSM_Timer_StartUpMonitoringOfVarStruct = FRSM_CANCEL_TIMER, not evaluated in state HALT_REQ  */ /* FRSM_Timer_TillStartUpFail */
    }    /* end if Transition T14 */
    else if (
#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
        ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_WAKEUP ) ||
#endif /* WakeupEcu FRSM_WAKEUPECUOFCLUSTERCONFIG */
        ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_STARTUP )  )
    { /* T12 T13 */
      FrSM_StopTrcvGoToReady( FrSM_ClusterIndex );
#if ( FRSM_DEMEVENTCLUSTERSYNCLOSSOFCLUSTERCONFIG == STD_ON )
      if ( FrSM_IsSync_Loss_Cluster_Prod_Error_DetectOfClusterConfig( FrSM_ClusterIndex ) )   /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
      {
        FrSM_Dem_ReportErrorEvent( FrSM_GetDemEventClusterSyncLossOfClusterConfig( FrSM_ClusterIndex ), DEM_EVENT_STATUS_PASSED );
      }
#endif
    }    /* end if Transition T12 */ /* end if Transition T13 */
    else
    {
      /* impossible */ /* MISRA */
    }

    SchM_Exit_FrSM_FRSM_EXCLUSIVE_AREA_2( );   /* FrSM_Mainfunction interrupts * T10 T16 T17 FrSM_RequestComMode T14 T09 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */
  }    /* end if (RequestedComModeOfVarStruct == NoCom) */

} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */   /* FrSM_HandleComModeRequest */

#if (   ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON )  &&  (  ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) || ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_ON ) )  )
/**********************************************************************************************************************
  FrSM_DetermineWakeupReason
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_DetermineWakeupReason( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{
# if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
  FrTrcv_TrcvWUReasonType     FrSM_TrcvWUReason   = FRTRCV_WU_NOT_SUPPORTED;
# endif
  FrSM_WakeUpTypeOfVarStructType FRSM_WakeUpTypeTmp;

  if ( FrSM_IsCheckWakeupReasonOfClusterConfig( FrSM_ClusterIndex ) ) /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
  { /* determine WUReason */
# if ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_ON )
    (void)FrIf_GetWakeupRxStatus( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ),  &FRSM_WakeUpTypeTmp );   /*  NO 0d; ChA 1d; ChB 2d */  /* CC must NOT deliver an impossible Wakeup channel e.g. SingleCh_A Wakeup B */  /* SBSW_FRSM_FUNCTIONCALL_WITHPOINTERTOLOCALVARIABLE */
    /* \trace SPEC-11007 */
    FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_WakeUpTypeTmp ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# endif

# if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
    if ( FrSM_IsTrcv_HandlingOfClusterConfig( FrSM_ClusterIndex ) )  /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
    {
      if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_B ) /* COV_FRSM_CONFIG_PARAMETER_DUAL_ALWAYS_TRUE */
      {
        (void)FrIf_GetTransceiverWUReason( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_A, &FrSM_TrcvWUReason );  /* SBSW_FRSM_FUNCTIONCALL_WITHPOINTERTOLOCALVARIABLE */
        /* \trace SPEC-11007 */
        (void)FrIf_ClearTransceiverWakeup( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_A );
        /* \trace SPEC-11007 */
        if ( FrSM_TrcvWUReason == FRTRCV_WU_BY_BUS )
        {
          FRSM_WakeUpTypeTmp = FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex );
          FRSM_WakeUpTypeTmp |= FRSM_WU_DETECTED_ON_CHANNEL_A;
          FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_WakeUpTypeTmp ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        }
      } /* if Ch A;  if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_B )  */
      if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_A ) /* COV_FRSM_CONFIG_PARAMETER_DUAL_ALWAYS_TRUE */
      {
        (void)FrIf_GetTransceiverWUReason( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_B, &FrSM_TrcvWUReason );  /* SBSW_FRSM_FUNCTIONCALL_WITHPOINTERTOLOCALVARIABLE */
        /* \trace SPEC-11007 */
        (void)FrIf_ClearTransceiverWakeup( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_B );
        /* \trace SPEC-11007 */
        if ( FrSM_TrcvWUReason == FRTRCV_WU_BY_BUS )
        {
          FRSM_WakeUpTypeTmp = FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex );
          FRSM_WakeUpTypeTmp |= FRSM_WU_DETECTED_ON_CHANNEL_B;
          FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_WakeUpTypeTmp ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        }
      } /* if Ch B;  if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_A )  */
    }
# endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

  } /* end if  FrSMCheckWakeupReason  */
  else
  { /* wakeupType := SingleChannelWakeup  */
    /* FRSM_WakeUpTypeOfVarStruct is already set to FRSM_PERFORM_STANDARD_WAKEUP; */
  }

} /* FrSM_DetermineWakeupReason */
#endif /* ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) (   ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) && (  ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) || ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_ON ) )  ) */

/**********************************************************************************************************************
  FrSM_TimerTriggeredTransitions
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_TimerTriggeredTransitions( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{

  /* transitions triggered by expired timers t1 t2 t3  */
  switch ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) )
  {
    case FRSM_BSWM_STARTUP :
    {
#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
# if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
      SchM_Enter_FrSM_FRSM_EXCLUSIVE_AREA_1( ); /* FrSM_SetEcuPassive interrupts Main T01 T02 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */
# endif /* end if ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */
#endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */
      /* t2 repetition */
      if ( FrSM_GetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex ) == FRSM_RETRY_STARTUP_TIMER_EXPIRED )
      { /* T05 T06 */

#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
        if  (    FrSM_IsWakeupEcuOfClusterConfig( FrSM_ClusterIndex ) && (   (  ( FrSM_GetStartup_CounterOfVarStruct( FrSM_ClusterIndex ) <= FrSM_GetStartupRepetitionsWithWakeupOfClusterConfig( FrSM_ClusterIndex ) )
# if ( FRSM_WAKEUP_UNLIMITEDOFCLUSTERCONFIG == STD_ON )
                || ( FrSM_IsWakeUp_UnlimitedOfClusterConfig( FrSM_ClusterIndex ) )
# endif /* FRSM_WAKEUP_UNLIMITEDOFCLUSTERCONFIG  */
                )
# if (  ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) || ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_ON )  )
              && ( FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex )  != FRSM_PERFORM_NO_WAKEUP )
# endif /*   FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED */
              )    ) /* COV_FRSM_CONFIG_PARAMETER_REPETITION */
        { /* T05 second part */

# if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
          FrSM_StartTrcv( FrSM_ClusterIndex );
# endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */
          (void)FrIf_ControllerInit( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
          /* \trace SPEC-11007 */
          (void)FrIf_SendWUP( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
          /* \trace SPEC-11007 */
# if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON )
          FrSM_SetWakeUpPatternCounterOfVarStruct( FrSM_ClusterIndex, ( FrSM_GetNumWakeupPatternsOfClusterConfig( FrSM_ClusterIndex ) - 1 ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# endif /* if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON ) */
          FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_WAKEUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
          FrSM_IncStartup_CounterOfVarStruct( FrSM_ClusterIndex ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */ /* incrementation after evaluation */

# if ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON )
#  if ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
#   if ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_OFF )
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) ); /* equal T01a */ /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#   else   /* ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_OFF ) */
#    if ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_OFF )
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) ); /* equal T01a */ /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#    else   /* ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_OFF ) */
          /* FrSM_GetWakeUpRxStatusOfClusterConfig is not evaluated, WAKEUP_RX_STATUS_SUPPORT is not culster specific, FrIf/FrIfGeneral/FrIfGetWakeupRxStatusSupport */
          if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_AB )   /* FrSM_IsDual_Channel_SupportOfClusterConfig may be not available */ /* COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL  */
          {
            FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) ); /* equal T01a */ /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
          }
#    endif  /* ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_OFF ) */
#   endif  /* ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_OFF ) */
#  else /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
          if ( FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex ) == FRSM_PERFORM_INITIAL_WAKEUP )  /* 4 */  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
          {
            FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT4OfClusterConfig( FrSM_ClusterIndex ) ); /* start t4 resp. t1 Timer_ColdstartDelayOfVarStruct  */ /* prepare T03d+T04b, dual channel  NO_WU_BY_BUS  */ /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
          }
#  endif /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
# endif /* ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON ) */

        } /* T05 */
        else
#endif /* WakeupEcu FRSM_WAKEUPECUOFCLUSTERCONFIG */
        {
          if (  ( FrSM_GetStartup_CounterOfVarStruct( FrSM_ClusterIndex ) <= FrSM_GetStartupRepetitionsOfClusterConfig( FrSM_ClusterIndex ) )
#if ( FRSM_STARTUP_UNLIMITEDOFCLUSTERCONFIG == STD_ON )
              || ( FrSM_IsStartUp_UnlimitedOfClusterConfig( FrSM_ClusterIndex ) == TRUE )
#endif /* ( FRSM_STARTUP_UNLIMITEDOFCLUSTERCONFIG == STD_ON )  */
             ) /* COV_FRSM_CONFIG_PARAMETER_COMBINATION_4 */
          { /* T06 second part */
# if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
            FrSM_StartTrcv( FrSM_ClusterIndex );
# endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */
            (void)FrIf_ControllerInit( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
            /* \trace SPEC-11007 */
            (void)FrIf_StartCommunication( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
            /* \trace SPEC-11007 */
            FrSM_SetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT2OfClusterConfig( FrSM_ClusterIndex ) ); /* FRSM_Timer_SuperviseStartup */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# if ( FRSM_COLDSTARTECUOFCLUSTERCONFIG == STD_ON )
            if ( FrSM_IsColdstartEcuOfClusterConfig( FrSM_ClusterIndex ) ) /* PRQA S 0715 2 */ /* MD_MSR_1.1 */ /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN_AFTEREFFECT */
            {
              (void)FrIf_AllowColdstart( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
              /* \trace SPEC-11007 */
              FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_COLDSTART_DELAY_TIMER );  /* FRSM_MAX_COLDSTART_DELAY */  /* equal T01a */ /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
            }
# endif /* ( FRSM_COLDSTARTECUOFCLUSTERCONFIG == STD_ON ) */
            if ( FrSM_GetStartup_CounterOfVarStruct( FrSM_ClusterIndex ) < FRSM_MAX_STARTUP_COUNTEROFVARSTRUCT )  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */  /* avoid WUP in case of unlimited FrSMStartupRepetitions */ /* COV_FRSM_VARIABLE_TYPE_RANGE */
            {
              FrSM_IncStartup_CounterOfVarStruct( FrSM_ClusterIndex ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */ /* incrementation after evaluation */
            }
          } /*  repetition withOUT WUP */
        }  /*  no repetition WITH WUP */

      } /* end if ( FRSM_Timer_RetryStartUpOfVarStruct == FRSM_TIMER_EXPIRED ) T05 XOR T06  */
      else
      {

        /* t1 allow CS */
#if ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON )
        if ( FrSM_IsColdstartEcuOfClusterConfig( FrSM_ClusterIndex ) ) /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
        {

          if ( FrSM_GetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex ) == FRSM_COLDSTART_DELAY_TIMER_EXPIRED ) /* PRQA S 0715 2 */ /* MD_MSR_1.1 */  /* union FrSM_GetTimer_ColdstartDelayOfVarStruct FrSM_GetTrcvStbyDelay  */
          {
# if (  ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_ON ) &&  ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_ON ) && ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )  ) /* FrIf_GetWakeupRxStatus */
            /* FR_CHANNEL_AB resp. FrSM_IsDual_Channel_SupportOfClusterConfig checked implicit by WakeUpType DUAL_CHANNEL_WAKEUP */
            /* T04b; CS by AllChannelsAwake if  wakeupType =  DualChannelWakeup  */
            uint8   FrSM_WakeupRxStatus; /* used if GetWakeupRxStatus is used to trigger AllowColdstart */

            FrSM_WakeupRxStatus = FRSM_WU_DETECTED_ON_CHANNEL_B; /* trigger A CS  PartialWu DualChannelWakeup-Forward, or non WakeupEcu  */ /* full external WU no A-CS needed */

            if ( FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex ) == FRSM_PERFORM_DUAL_CHANNEL_WAKEUP )  /* 4 */  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
            { /* initial dual channel wakeup, several A-CS calls are avoided by Timer_ColdstartDelayOfVarStruct  */
              (void)FrIf_GetWakeupRxStatus( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ),  &FrSM_WakeupRxStatus ); /*  NO 0d; ChA 1d; ChB 2d */  /* SBSW_FRSM_FUNCTIONCALL_WITHPOINTERTOLOCALVARIABLE */
              /* \trace SPEC-11007 */
            } /* end if ( FRSM_WakeUpTypeOfVarStruct == FRSM_PERFORM_DUAL_CHANNEL_WAKEUP ) */

            if ( FrSM_WakeupRxStatus == FRSM_WU_DETECTED_ON_CHANNEL_B )  /*  NO 0d; ChA 1d; ChB 2d */ /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
# endif /* FRSM_GET_WAKEUP_RX_STATUS_SUPPORT FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG  FrIf_GetWakeupRxStatus */
            { /* T04 */

              (void)FrIf_AllowColdstart( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
              /* \trace SPEC-11007 */
              FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_COLDSTART_DELAY_TIMER );  /* CANCEL_COLDSTART_DELAY_TIMER */  /* equal T01a */ /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

            } /* Rx received FrSM_WakeupRxStatus */
          } /* end if ( Timer_ColdstartDelayOfVarStruct == FRSM_TIMER_EXPIRED ) */

        } /* end if FrSM_IsColdstartEcuOfClusterConfig( FrSM_ClusterIndex ) */
#endif /* ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON ) */

      } /* t2 running, still in STARTED */

#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
# if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
      SchM_Exit_FrSM_FRSM_EXCLUSIVE_AREA_1( ); /* FrSM_SetEcuPassive interrupts Main T01 T02 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */
# endif /* end if ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */
#endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

    } /* end case FRSM_BSWM_STARTUP  */
#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
    /* fall through */
    case FRSM_BSWM_WAKEUP :   /* PRQA S 2003 */  /* MD_FRSM_15.2 */
#endif /* WakeupEcu FRSM_WAKEUPECUOFCLUSTERCONFIG */
    case FRSM_BSWM_ONLINE_PASSIVE :   /* PRQA S 2003 */  /* MD_FRSM_15.2 */
    {
#if ( FRSM_DEMEVENTCLUSTERSTARTUPOFCLUSTERCONFIG == STD_ON )
      if (  ( FrSM_GetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex ) == FRSM_STARTUP_MONITORING_TIMER_EXPIRED ) && ( FrSM_IsStartup_Cluster_Prod_Error_DetectOfClusterConfig( FrSM_ClusterIndex ) )  ) /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN_AFTEREFFECT_2 */
      {
        FrSM_Dem_ReportErrorEvent( FrSM_GetDemEventClusterStartupOfClusterConfig( FrSM_ClusterIndex ), (uint8)DEM_EVENT_STATUS_FAILED );
      }
#endif
      if (   (  ( FrSM_GetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex ) == FRSM_STARTUP_MONITORING_TIMER_EXPIRED ) || ( FrSM_GetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex ) == FRSM_CANCEL_STARTUP_MONITORING_TIMER ) ) && ( FrSMSyncLossErrorIndicationFctPtr != NULL_PTR )   ) /* COV_FRSM_CONFIG_PARAMETER_FUNCTION_POINTER */
      {
        (*FrSMSyncLossErrorIndicationFctPtr)( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ) ); /* SBSW_FRSM_SYNCLOSS_INDICATION */
        /* \trace SPEC-10977 */
      }
      break;
    }
    default:
    {
      /* MISRA */
    }
  }    /* End switch( FRSM_CurrentStateOfVarStruct ) */

} /* PRQA S 6030, 6050,6080  */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */ /* FrSM_TimerTriggeredTransitions */

/**********************************************************************************************************************
  FrSM_StateReady
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_StateReady( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{

#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
# if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
  SchM_Enter_FrSM_FRSM_EXCLUSIVE_AREA_1( ); /* FrSM_SetEcuPassive interrupts Main T01 T02 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */
# endif /* end if ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */
#endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
  FrSM_StartTrcv( FrSM_ClusterIndex );
#endif /* FRSM_TRCV_HANDLINGOFCLUSTERCONFIG */

#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
  if ( FrSM_IsWakeupEcuOfClusterConfig( FrSM_ClusterIndex ) ) /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
  {
    FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_PERFORM_STANDARD_WAKEUP ); /* 0 ==  FRSM_PERFORM_INITIAL_WAKEUP = FRSM_PERFORM_SINGLE_CHANNEL_WAKEUP  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

# if (  ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_OFF ) && ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_OFF ) )
    /* no WU detection possible */
#  if ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON )
#   if   ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
    FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) );  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#   else /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
    FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT4OfClusterConfig( FrSM_ClusterIndex ) ); /* start t4 resp. t1 Timer_ColdstartDelayOfVarStruct  */ /* prepare T03d+T04b, dual channel  NO_WU_BY_BUS  */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#   endif /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
#  endif /*  FRSM_TRCV_HANDLINGOFCLUSTERCONFIG FRSM_GET_WAKEUP_RX_STATUS_SUPPORT  */
    if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) == FR_CHANNEL_AB )    /* COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL  */
    {
      (void)FrIf_SetWakeupChannel(FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_A );
      /* \trace SPEC-11007 */
    }
    /* no WU detection possible
     * force trigger FrIf_SendWUP  unconditional  */
# else /* FRSM_TRCV_HANDLINGOFCLUSTERCONFIG FRSM_GET_WAKEUP_RX_STATUS_SUPPORT */

    /* ******************************************************************
     * WU detection possible, determine WU type
     * ***************************************************************** */

# if (   ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) && (  ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) || ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_ON ) )  )
    FrSM_DetermineWakeupReason( FrSM_ClusterIndex );
    /* FrSM_IsCheckWakeupReasonOfClusterConfig is checked within function above */
#  endif /* ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) */

#  if ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_ON )
    if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_AB )  /* COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL  */
#  endif   /* if ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_ON ) */
    {
      /* single channel */

#  if ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON )
      /*  check if (  ( FrSM_IsWakeupEcuOfClusterConfig( FrSM_ClusterIndex ) )  is not needed bc FrSM_GetWakeUpTypeOfVarStruct will is set accordingly */
      if ( FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex ) == FRSM_PERFORM_SINGLE_CHANNEL_WAKEUP ) /* 0 FRSM_RX_STATUS_NO_WAKEUP_DETECTED FRSM_PERFORM_STANDARD_WAKEUP */ /* COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL_AFTEREFFECT */
#  endif /* ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) */
      {
#  if ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON )
#   if   ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
        FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) );   /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#   else /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
        FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT4OfClusterConfig( FrSM_ClusterIndex ) ); /* start t4 resp. t1 Timer_ColdstartDelayOfVarStruct  */    /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#   endif /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
#  endif /* FRSM_TIMER_COLDSTARTDELAY_USED */
      }
#  if ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON )
      else
      { /* T02 */
        FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_PERFORM_NO_WAKEUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      }
#  endif /* ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) */

    } /* end Single channel A XOR B */
#  if ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_ON )
    else
    { /*  DualChannel FR_CHANNEL_AB */

      /* 3 NOP; ALL bus, NoWup;
       * 0 initial  => Set ChA==0; t1=cancel
       * 2 WuOn ChB => Set ChA==0; t1=0
       * 1 WuOn ChA => Set ChB==1; t1=0 */
#   if ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON )
      /*  check FrSM_IsCheckWakeupReasonOfClusterConfig  is not needed bc FrSM_GetWakeUpTypeOfVarStruct will is set accordingly within FrSM_DetermineWakeupReason */
      switch (  FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex )  )
      {
        case FRSM_PERFORM_INITIAL_WAKEUP :
        { /* DualCh initial WU XOR WU on ChB forward WuToChA */
#   endif /* ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) */

          /* T01b */
#   if (  ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_ON ) && ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )  )
          FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_PERFORM_DUAL_CHANNEL_WAKEUP ); /* 4 */ /*  AllowCS triggered via  RxStatus   */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#   endif /* FRSM_GET_WAKEUP_RX_STATUS_SUPPORT  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED   */

#   if ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON )
#    if (  ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_OFF ) || ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_ON )  )
          /* trigger T04a even wakeupType =  DualChannelWakeup */
#     if   (  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) );   /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#     else /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT4OfClusterConfig( FrSM_ClusterIndex ) ); /* start t4 resp. t1 Timer_ColdstartDelayOfVarStruct  */    /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#     endif /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */

#    else /* FRSM_GET_WAKEUP_RX_STATUS_SUPPORT FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED */
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_COLDSTART_DELAY_TIMER_EXPIRED ); /* enable AllowCS immediately or according to GetWakeupRxStatus */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#    endif /* FRSM_GET_WAKEUP_RX_STATUS_SUPPORT  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED   */

#   else /*  FRSM_TIMER_COLDSTARTDELAY_USED  */
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_COLDSTART_DELAY_TIMER );  /* FRSM_MAX_COLDSTART_DELAY */  /* equal T01a */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#   endif /*  FRSM_TIMER_COLDSTARTDELAY_USED  */

          (void)FrIf_SetWakeupChannel(FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_A );
          /* \trace SPEC-11007 */

#   if ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON )
          /* wakeup evaluating ==> partial WU possible */
          break;
        } /* end DualChannel Initial WU NO_WU_BY_BUS  */
        case FRSM_WU_DETECTED_ON_CHANNEL_B: /* PRQA S 2003 */  /* MD_FRSM_15.2 */
        { /* DualCh initial WU XOR WU on ChB forward WuToChA */

          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_COLDSTART_DELAY_TIMER_EXPIRED ); /* enable AllowCS immediately or according to GetWakeupRxStatus */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
          (void)FrIf_SetWakeupChannel(FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_A );
          /* \trace SPEC-11007 */
          /* T01c */
          /* FRSM_WakeUpTypeOfVarStruct = FRSM_PERFORM_DUAL_CHANNEL_FOREWARD; */

          break;
        } /* end DualChannel PARTIAL_WU_BY_BUS  on ChB */
        case FRSM_WU_DETECTED_ON_CHANNEL_A:
        { /* WU ECU; DualCh ==> SetWakeupChannel; plain internal XOR partial WU */

          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_COLDSTART_DELAY_TIMER_EXPIRED ); /* enable AllowCS immediately or according to GetWakeupRxStatus */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
          (void)FrIf_SetWakeupChannel(FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_B );
          /* \trace SPEC-11007 */
          /* T01c */
          /* FRSM_WakeUpTypeOfVarStruct = FRSM_PERFORM_DUAL_CHANNEL_FOREWARD; */

          break;
        } /* end DualChannel PARTIAL_WU_BY_BUS  on ChA  */
        default:
        { /* FRSM_WakeUpTypeOfVarStruct = FRSM_PERFORM_NO_WAKEUP;  */ /* == 3 == ALL_WU_BY_BUS  ==> T02 */
          /*  Timer_ColdstartDelayOfVarStruct = FRSM_TIMER_EXPIRED; */ /* CS immediately */
          /* MISRA demands a default branch. */
          break;
        } /* ALL_WU_BY_BUS  */
      }    /* End switch( FRSM_WakeUpTypeOfVarStruct ) */
#   endif /* ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON ) */

    } /*  end  FR_CHANNEL_AB */
#  endif   /* if ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_ON ) */

    /* ******************************************************************
     * END:  WU detection possible, determine WU type
     * ***************************************************************** */

# endif /* FRSM_TRCV_HANDLINGOFCLUSTERCONFIG FRSM_GET_WAKEUP_RX_STATUS_SUPPORT */

  } /* end if FrSM_IsWakeupEcuOfClusterConfig( FrSM_ClusterIndex ) */
  else
#endif /* ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON ) */
  { /* :=PERFORM_NO_WAKEUP */ /* T02 */
    FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_PERFORM_NO_WAKEUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  } /* end else of  if FrSM_IsWakeupEcuOfClusterConfig( FrSM_ClusterIndex ) */

  /* Transition T01 (READY to WAKEUP) */
#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
  /*  check if (  ( FrSM_IsWakeupEcuOfClusterConfig( FrSM_ClusterIndex ) )  is not needed bc FrSM_GetWakeUpTypeOfVarStruct will be set accordingly */
  if ( FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex )  != FRSM_PERFORM_NO_WAKEUP ) /* COV_FRSM_CONFIG_CHECKWAKEUP_NOT_POSSIBLE */
  {
    (void)FrIf_SendWUP( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
    /* \trace SPEC-11007 */
    FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_WAKEUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON )
    FrSM_SetWakeUpPatternCounterOfVarStruct( FrSM_ClusterIndex, ( FrSM_GetNumWakeupPatternsOfClusterConfig( FrSM_ClusterIndex ) - 1 ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# endif /* if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON ) */
  }     /* end if Transition T01 */
#endif /* ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON ) */
  /* Transition T02 (READY to STARTUP) Condition: [ reqComMode = FullCom & ! IsWakeupECU ] */
#if (  ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON ) && ( FRSM_STARTUP_WITHOUT_WAKEUP_POSSIBLE == STD_ON )  )
  else                    /* NO Wakeup ECU */
#endif
#if ( FRSM_STARTUP_WITHOUT_WAKEUP_POSSIBLE == STD_ON )
  {
    (void)FrIf_StartCommunication( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
    /* \trace SPEC-11007 */
    FrSM_SetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT2OfClusterConfig( FrSM_ClusterIndex ) ); /* t2 FRSM_Timer_SuperviseStartup */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
    FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_STARTUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

# if ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
#  if ( FRSM_DELAYSTARTUPWITHOUTWAKEUPOFCLUSTERCONFIG == STD_ON )
    if ( FrSM_IsDelayStartupWithoutWakeupOfClusterConfig( FrSM_ClusterIndex ) ) /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
    {
      /* Rest of T02 is equal to T04 and shift below StateMachine AND delayed by T1 */
      FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) );   /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
    }
    else
#  endif /* ( FRSM_DELAYSTARTUPWITHOUTWAKEUPOFCLUSTERCONFIG == STD_ON ) */
# endif /* FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
    {
      FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_COLDSTART_DELAY_TIMER );  /* FRSM_MAX_COLDSTART_DELAY */   /* equal T01a */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# if ( FRSM_COLDSTARTECUOFCLUSTERCONFIG == STD_ON )
      if ( FrSM_IsColdstartEcuOfClusterConfig( FrSM_ClusterIndex ) ) /* COV_FRSM_CONFIG_PARAMETER_COMBINATION_1 */
      {
        (void)FrIf_AllowColdstart( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
        /* \trace SPEC-11007 */
      } /* end if FrSM_IsColdstartEcuOfClusterConfig( FrSM_ClusterIndex ) */
# endif /* ( FRSM_COLDSTARTECUOFCLUSTERCONFIG == STD_ON ) */

    } /* end if no delay */

  } /* end if Transition T02 */
#endif /* FRSM_STARTUP_WITHOUT_WAKEUP_POSSIBLE*/

#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
# if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
  SchM_Exit_FrSM_FRSM_EXCLUSIVE_AREA_1( ); /* FrSM_SetEcuPassive interrupts Main T01 T02 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */
# endif /* end if ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */
#endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

  FrSM_SetStartup_CounterOfVarStruct( FrSM_ClusterIndex, 1 ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  FrSM_SetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT3OfClusterConfig( FrSM_ClusterIndex ) ); /* start error timer t3 */ /* FRSM_Timer_TillStartUpFail */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

} /* PRQA S 6050 */ /* MD_MSR_STCAL */   /* FrSM_StateReady */

#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
/**********************************************************************************************************************
  FrSM_StateWakeup
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_StateWakeup( FrSM_SizeOfVarStructType FrSM_ClusterIndex, Fr_POCStateType  FrSM_CurrentPocStatusState, Fr_WakeupStateType  FrSM_CurrentPocStatusWakeupStatus  )
{
  /* FrSM_IsWakeupEcuOfClusterConfig is ensured before function called */

  /*  R14 RfC 52244 SREQ-9468
      the wakeup pattern transmission shall be aborted and the wakeupFinished condition shall evaluate to true. */
  if ( FrSM_CurrentPocStatusState == FR_POCSTATE_HALT ) /* contains Freeze implicit */
  { /* handling similar T10 */
    (void)FrIf_ControllerInit( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
    /* \trace SPEC-11007 */
    (void)FrIf_StartCommunication( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
    /* \trace SPEC-11007 */
    FrSM_SetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT2OfClusterConfig( FrSM_ClusterIndex ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
    FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_STARTUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  }
  else if ( FrSM_CurrentPocStatusState == FR_POCSTATE_READY )
  {

#if ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
# if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON )
    if ( FrSM_GetNumWakeupPatternsOfClusterConfig( FrSM_ClusterIndex ) == 1 )   /* PRQA S 0715 2 */ /* MD_MSR_1.1 */ /* COV_FRSM_CONFIG_PARAMETER_CONST_NUMBER */
    {
# endif /* if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON ) */
      /* T03a restart t1 for single channel with single WUP */
      if ( FrSM_GetFrChannelOfClusterConfig( FrSM_ClusterIndex ) != FR_CHANNEL_AB ) /* COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL_NUM_WUP  */ /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
      {
        FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) );   /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      }
#endif /* ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF ) */

#if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON )
      /* FrSM_IsEnable_Consecutive_WupOfClusterConfig implicit checked by NumWakeupPatterns equal to 1    */
# if ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
    }
    else if ( FrSM_CurrentPocStatusWakeupStatus == FR_WAKEUP_TRANSMITTED )  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
    { /* enable AllowCS in T03  */
      FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_COLDSTART_DELAY_TIMER_EXPIRED );   /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
    }

# else  /* FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
    /* FrSM_IsEnable_Consecutive_WupOfClusterConfig irrelevant, special case "==1" implicit correct, WakeUpPatternCounterOfVarStruct is already set to FRSM_MIN_WAKEUPPATTERNCOUNTEROFVARSTRUCT */
    if ( FrSM_CurrentPocStatusWakeupStatus == FR_WAKEUP_TRANSMITTED )  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
    {
      /* proceed initial DualChannelWakeup; if all WUP are triggered, TxWUP is evaluated and T03d will follow  */
    }
# endif /* FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
    else if (  ( FrSM_CurrentPocStatusWakeupStatus == FR_WAKEUP_RECEIVED_HEADER ) || ( FrSM_CurrentPocStatusWakeupStatus == FR_WAKEUP_RECEIVED_WUP )  ) /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
    { /* cancel WUPing all WU variations     and   switch to forwarding in case of DualChannelWU */
      /* enable condition for T03 */
      FrSM_SetWakeUpPatternCounterOfVarStruct( FrSM_ClusterIndex, FRSM_MIN_WAKEUPPATTERNCOUNTEROFVARSTRUCT ); /* WUP elapsed */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
    }
    else  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
    {
      /* MISRA; other values has no impact */
    }

    /* FrSM_IsEnable_Consecutive_WupOfClusterConfig irrelevant, special case "==1" implicit correct, WakeUpPatternCounterOfVarStruct is already set to FRSM_MIN_WAKEUPPATTERNCOUNTEROFVARSTRUCT */
    if ( FrSM_GetWakeUpPatternCounterOfVarStruct( FrSM_ClusterIndex ) > FRSM_MIN_WAKEUPPATTERNCOUNTEROFVARSTRUCT )  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
    {
      (void)FrIf_SendWUP( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
      /* \trace SPEC-11007 */
      FrSM_DecWakeUpPatternCounterOfVarStruct( FrSM_ClusterIndex ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      /* \trace  SPEC-10938 */
    } /* end if proceed consecutive WUP sequence */
    else  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
#else
      FRSM_DUMMY_STATEMENT( FrSM_CurrentPocStatusWakeupStatus ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON ) */
    { /* T03[abcdef] */

#if ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_ON )
      /* Transition T03 (WAKEUP to STARTUP) resp. T03f */
      if (  (  FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex )  != FRSM_PERFORM_INITIAL_WAKEUP ) || ( FrSM_CurrentPocStatusWakeupStatus == FR_WAKEUP_TRANSMITTED )  )  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
      {
#endif /* ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_ON )    */

        /* T03[abcde] */
        /* Transition T03 (WAKEUP to STARTUP) Condition: [ (vPOC!State = Ready) &  ! vPOC!Freeze  &  reqComMode = FullCom ] */
        (void)FrIf_StartCommunication( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
        /* \trace SPEC-11007 */
        FrSM_SetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT2OfClusterConfig( FrSM_ClusterIndex ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_STARTUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

#if ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_ON )
        /* FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED ==> MultiWup ON and bigger 1 */

        if (  FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex )  == FRSM_PERFORM_INITIAL_WAKEUP ) /* PRQA S 0715 3 */ /* MD_MSR_1.1 */
        {  /* T03d         DualChannelWU and WAKEUP_TRANSMITTED,   t1 still active T04b will follow */
          /* start t2 FRSM_Timer_SuperviseStartup see above */
        }
        else
        {  /* T03e         DualChannelWU and  PARTIAL_WU_BY_BUS,   */
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_COLDSTART_DELAY_TIMER_EXPIRED ); /* T04 armed to add CS for T03b resp. T03e */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
          /* start t2 FRSM_Timer_SuperviseStartup see above */
        }
#else /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED */
# if ( ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_OFF ) ||  (  ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_OFF ) && ( FRSM_GET_WAKEUP_RX_STATUS_SUPPORT == STD_OFF ) ) )
#  if ( FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_ON )
#   if ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON )
        /* FR_CHANNEL_AB resp. FrSM_IsDual_Channel_SupportOfClusterConfig checked implicit by WakeUpType  FRSM_PERFORM_STANDARD_WAKEUP == FRSM_PERFORM_SINGLE_CHANNEL_WAKEUP  */
        if ( FrSM_GetWakeUpTypeOfVarStruct( FrSM_ClusterIndex ) != FRSM_PERFORM_STANDARD_WAKEUP ) /*   1 2; DualCh AND Partial WU on A or B  */ /* PRQA S 0715 2 */ /* MD_MSR_1.1 */ /* COV_FRSM_CONFIG_CHECKWAKEUP_NOT_POSSIBLE */
        { /* T03e */
          FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_COLDSTART_DELAY_TIMER_EXPIRED ); /* T04 armed to add CS for T03b resp. T03e */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
          /* No Else, in case of Dual WU_INITIAL Timer not evaluated, */
        }
#   endif /* ( FRSM_TIMER_COLDSTARTDELAY_USED == STD_ON ) */
        /*  else T03c    Single WU  multi WUP;       */ /* FRSM_Timer_SuperviseStartup  FRSM_CANCEL_TIMER above */ /* t2 might be active, START start t2 T08 T09 T11 */ /* end T03[d eb ac] */
#  endif /* FRSM_DUAL_CHANNEL_SUPPORTOFCLUSTERCONFIG == STD_ON ) && ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF  */
# endif /* ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_OFF ) */
#endif /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED */

#if ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_ON )
      } /* Transition T03 (WAKEUP to STARTUP) */ /* PRQA S 0715 3 */ /* MD_MSR_1.1 */
      else
      {  /*  T03f   FRSM_PERFORM_INITIAL_WAKEUP AND ( NoTxWUP OR RxWUP )  */

        FrSM_SetStartup_CounterOfVarStruct( FrSM_ClusterIndex, 1 ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetWakeUpPatternCounterOfVarStruct( FrSM_ClusterIndex, ( FrSM_GetNumWakeupPatternsOfClusterConfig( FrSM_ClusterIndex ) - 1 ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetWakeUpTypeOfVarStruct( FrSM_ClusterIndex, FRSM_WU_DETECTED_ON_CHANNEL_A );  /* wakeupType := DualChannelWakeupForward */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT3OfClusterConfig( FrSM_ClusterIndex ) ); /* start error timer t3 */ /* FRSM_Timer_TillStartUpFail */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

        (void)FrIf_SetWakeupChannel(FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), FR_CHANNEL_B );
        /* \trace SPEC-11007 */
        (void)FrIf_SendWUP( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
        /* \trace SPEC-11007 */

      } /* end T03f */
#endif /* ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_ON )   */

    } /* end if trigger T03 */

  } /* end else if (FR_POCSTATE_READY == FrSM_CurrentPocStatus.State) */
  else
  {
    /* MISRA QAC */
  }

} /* PRQA S 6080 */ /* MD_MSR_STMIF */  /* FrSM_StateWakeup */
#endif /* WakeupEcu FRSM_WAKEUPECUOFCLUSTERCONFIG */

/**********************************************************************************************************************
  FrSM_StateStartOnline
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_StateStartOnline( FrSM_SizeOfVarStructType FrSM_ClusterIndex, Fr_POCStateType  FrSM_CurrentPocStatusState, Fr_SlotModeType FrSM_CurrentPocStatusSlotMode )
{ /* not FRSM_BSWM_READY  not FRSM_BSWM_WAKEUP  not FRSM_BSWM_HALT_REQ */
  ComM_ModeType           FrSM_ComMMode       = COMM_FULL_COMMUNICATION;  /* CREQ-105685 */

  if ( FrSM_CurrentPocStatusState == FR_POCSTATE_NORMAL_ACTIVE )
  {
    /* T08=T108+T101 T15=T115+T101, T101 part will be added below if necessary */
    if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_STARTUP )
    { /* T08 */
#if ( FRSM_DEMEVENTCLUSTERSTARTUPOFCLUSTERCONFIG == STD_ON )
      if (  FrSM_IsStartup_Cluster_Prod_Error_DetectOfClusterConfig( FrSM_ClusterIndex ) )  /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
      {
        FrSM_Dem_ReportErrorEvent( FrSM_GetDemEventClusterStartupOfClusterConfig( FrSM_ClusterIndex ), (uint8)DEM_EVENT_STATUS_PASSED );
      }
#endif
      FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_ONLINE_PASSIVE ); /* T15 / T115 auto follow */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
    }
    if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE_PASSIVE )
    { /* T15 */
#if ( FRSM_DEMEVENTCLUSTERSYNCLOSSOFCLUSTERCONFIG == STD_ON )
      if ( FrSM_IsSync_Loss_Cluster_Prod_Error_DetectOfClusterConfig( FrSM_ClusterIndex ) )  /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
      {
        FrSM_Dem_ReportErrorEvent( FrSM_GetDemEventClusterSyncLossOfClusterConfig( FrSM_ClusterIndex ), DEM_EVENT_STATUS_PASSED );
      }
#endif
      (void)FrIf_SetState( FrSM_GetFrIfClusterIndexOfClusterConfig( FrSM_ClusterIndex ), FRIF_GOTO_ONLINE );

      FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_COLDSTART_DELAY_TIMER );  /* FRSM_MAX_COLDSTART_DELAY */   /* equal T01a */  /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      FrSM_SetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_RETRY_STARTUP_TIMER ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      FrSM_SetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_STARTUP_MONITORING_TIMER ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_KEYSLOT_ONLY ); /* T101 auto follow if valid */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
    }

  } /* end if ( FrSM_CurrentPocStatus.State == FR_POCSTATE_NORMAL_ACTIVE ) */
  else if ( FrSM_CurrentPocStatusState == FR_POCSTATE_NORMAL_PASSIVE )
  {
    if (  ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE ) || ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex )  == FRSM_BSWM_KEYSLOT_ONLY )  )  /* PRQA S 0715 2 */ /* MD_MSR_1.1 */ /* COV_FRSM_CONFIG_PARAMETER_SLOT_MODE_KEY_SLOT */
    { /* T16a T16b */
      FrSM_FrGoOffline( FrSM_ClusterIndex );
    }
  }
  else if ( FrSM_CurrentPocStatusState == FR_POCSTATE_HALT )
  {

    if (  ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE ) || ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex )  == FRSM_BSWM_KEYSLOT_ONLY )  ) /* PRQA S 0715 2 */ /* MD_MSR_1.1 */ /* COV_FRSM_CONFIG_PARAMETER_COMBINATION_3 */
    { /* T20a=T20b = T16a+T20c = T16b+T20c */ /* T10a == T16a+T17=T10b == T16b+T17 */ /* * T20a T20b T20c T10a T10b */
      FrSM_FrGoOffline( FrSM_ClusterIndex );
      /* T10 FRSM_CurrentStateOfVarStruct  FRSM_BSWM_STARTUP
       * else T20. First Part T16 already done FRSM_CurrentStateOfVarStruct  FRSM_BSWM_ONLINE_PASSIVE; second part T20c will follow */
    }
    if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE_PASSIVE ) /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
    {
      (void)FrIf_ControllerInit( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
      /* \trace SPEC-11007 */
      FrSM_SetStartup_CounterOfVarStruct( FrSM_ClusterIndex, 1 ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */

#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
      if (  ( FrSM_IsWakeupEcuOfClusterConfig( FrSM_ClusterIndex ) )
# if ( FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG == STD_ON )
          && ( !FrSM_IsCheckWakeupReasonOfClusterConfig( FrSM_ClusterIndex ) )
# endif /* FRSM_CHECKWAKEUPREASONOFCLUSTERCONFIG  */
         ) /* PRQA S 0715 2 */ /* MD_MSR_1.1 */ /*  COV_FRSM_CONFIG_PARAMETER_COMBINATION_2 */
      { /* * T20a T20b T20c */

        /* T20c  */ /* FE_WAKEUP start t1  */
        (void)FrIf_SendWUP( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
        /* \trace SPEC-11007 */
# if   ( FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED == STD_OFF )
        FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT1OfClusterConfig( FrSM_ClusterIndex ) );   /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# else /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
        FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT4OfClusterConfig( FrSM_ClusterIndex ) ); /* start t4 resp. t1 */    /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# endif /*  FRSM_WAKEUP_ON_BOTH_CHANNELS_ALLOWED  */
        FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_WAKEUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON )
        FrSM_SetWakeUpPatternCounterOfVarStruct( FrSM_ClusterIndex, ( FrSM_GetNumWakeupPatternsOfClusterConfig( FrSM_ClusterIndex ) - 1 ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
# endif /* if ( FRSM_ENABLE_CONSECUTIVE_WUPOFCLUSTERCONFIG == STD_ON ) */

      }
      else /* PRQA S 0715 2 */ /* MD_MSR_1.1 */
#endif /* WakeupEcu FRSM_WAKEUPECUOFCLUSTERCONFIG */
      {
        /* ! (FrSMCheckWakeupReason v ! FrSMIsWakeupEcu )  */
        /* T17 */ /* FE_START start t2 */
        (void)FrIf_StartCommunication( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
        /* \trace SPEC-11007 */
        FrSM_SetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex, FrSM_GetDurationT2OfClusterConfig( FrSM_ClusterIndex ) ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_STARTUP ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      }

    } /* end if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE_PASSIVE ) */

  } /* end of else if ( FrSM_CurrentPocStatus.State == FR_POCSTATE_HALT ) */
  else
  {
    /* MISRA */
  }

  if (  ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_KEYSLOT_ONLY ) && ( FrSM_CurrentPocStatusSlotMode == FR_SLOTMODE_ALL )  )/* PRQA S 0715 3 */ /* MD_MSR_1.1 */ /* COV_FRSM_CONFIG_PARAMETER_SLOT_MODE */
  { /* T101 */ /* FrSM_ComMMode = COMM_FULL_COMMUNICATION; */
    ComM_BusSM_ModeIndication ( FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), &FrSM_ComMMode ); /* CREQ-105685 */ /* SBSW_FRSM_COMMMODEINDICATION_CALL */
    FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_ONLINE );  /* CREQ-105685 */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  }

} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */ /* FrSM_StateStartOnline */

/**********************************************************************************************************************
  FrSM_RunTimer
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FRSM_LOCAL_INLINE FUNC(void, FRSM_CODE) FrSM_RunTimer( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{
  /* run timer; * t1 * t2 * t3 */
#if ( FRSM_RUN_TIMER_CS_TRCV_DELAY == STD_ON )
  if (  ( FrSM_GetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex ) != FRSM_CANCEL_COLDSTART_DELAY_TIMER ) && ( FrSM_GetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex ) != FRSM_COLDSTART_DELAY_TIMER_EXPIRED )  ) /* preserve expired timer during WAKEUP till AllowCS */ /* COV_FRSM_CONFIG_PARAMETER_TIMER_COLDSTART */ /* union FrSM_GetTimer_ColdstartDelayOfVarStruct FrSM_GetTrcvStbyDelay  */
  {
    FrSM_DecTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex ); /* union FrSM_DecTimer_ColdstartDelayOfVarStruct FrSM_DecTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  }
#endif /*  FRSM_RUN_TIMER_CS_TRCV_DELAY  FRSM_COLDSTARTECUOFCLUSTERCONFIG  FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG */

  if ( FrSM_GetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex ) != FRSM_CANCEL_RETRY_STARTUP_TIMER ) /* ( FRSM_Timer_RetryStartUpOfVarStruct != FRSM_TIMER_EXPIRED ) &&  */
  {
    FrSM_DecTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  }

  if ( FrSM_GetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex ) != FRSM_CANCEL_STARTUP_MONITORING_TIMER ) /* ( FRSM_Timer_StartUpMonitoringOfVarStruct != FRSM_TIMER_EXPIRED ) &&  */
  {
    FrSM_DecTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
  }

} /* FrSM_RunTimer */

/***********************************************************************************************************************
 * FUNCTION: FRSM_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC( void, FRSM_CODE ) FrSM_MainFunction( FrSM_SizeOfVarStructType FrSM_ClusterIndex )
{
  /* \trace  SPEC-11042 */
  /* \trace SPEC-10941 */
  Fr_POCStatusType    FrSM_CurrentPocStatus;
  uint8               FrSM_PriorState;
  uint8                       FrSM_DetErrorId = FRSM_E_NO_ERROR;

  if ( !FRSM_IsInitialized )
  {
    /* \trace SPEC-10967 */
  }
#if ( FRSM_DEV_ERROR_DETECT == STD_ON )
  else if ( FrSM_ClusterIndex >= FrSM_GetSizeOfVarStruct() )
  {
      FrSM_DetErrorId = FRSM_E_INV_HANDLE;
  }
#endif /* if (  ( FRSM_DEV_ERROR_DETECT == STD_ON )  ) */
  else  /* else if ( FRSM_IsInitialized == true ) */
  {

    /* \trace SPEC-10970 */
    if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_HALT_REQ )
    {
      /* \trace SPEC-11038 */
      if ( FrIf_GetPOCStatus( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), &FrSM_CurrentPocStatus ) == E_OK )  /* SBSW_FRSM_FUNCTIONCALL_WITHPOINTERTOLOCALVARIABLE */
      {
        if (  ( FrSM_CurrentPocStatus.State == FR_POCSTATE_HALT ) || ( FrSM_CurrentPocStatus.Freeze == TRUE )  )
        {  /* * T11 * */
          FrSM_CurrentPocStatus.State = FR_POCSTATE_HALT;
#if ( FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG == STD_ON )
          if (   (  !( FrSM_IsTransceiver_Standby_DelayOfClusterConfig( FrSM_ClusterIndex ) )  ) || (  ( FrSM_GetTrcvStbyDelay( FrSM_ClusterIndex ) == FRSM_TRCV_STBY_DELAY_TIMER_EXPIRED ) || ( FrSM_GetRequestedComModeOfVarStruct( FrSM_ClusterIndex ) == COMM_FULL_COMMUNICATION )  )   )  /*  union FrSM_GetTimer_ColdstartDelayOfVarStruct FrSM_GetTrcvStbyDelay  */ /* COV_FRSM_CONFIG_PARAMETER_COMBINATION_5 */
          {
#endif /* if ( FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG == STD_ON ) */
            FrSM_StopTrcvGoToReady( FrSM_ClusterIndex );
#if ( FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG == STD_ON )
            /* Cancel Transceiver Standby timer is not necessary because not used in following state and reinitialized before used again, FrSM_GetTimer_ColdstartDelayOfVarStruct will be reinitialized before usage in T01,T02 */
          }
          else
          {

            FrSM_DecTrcvStbyDelay( FrSM_ClusterIndex );  /* SBSW_FRSM_ARRAY_WRITE_ACCESS */ /*  union FrSM_DecTrcvStbyDelay FrSM_DecTimer_ColdstartDelayOfVarStruct  */
          }
#endif /* if ( FRSM_TRANSCEIVER_STANDBY_DELAYOFCLUSTERCONFIG == STD_ON ) */
        }  /* FrSM_CurrentPocStatus.State */
      }   /* end if valid POC state */

    } /* end if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_HALT_REQ ) */
    else if ( FrSM_GetRequestedComModeOfVarStruct( FrSM_ClusterIndex ) == COMM_FULL_COMMUNICATION )
    {
      FrSM_PriorState = FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex );

      if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_READY )
      { /* T01 T02 */

        FrSM_StateReady( FrSM_ClusterIndex );

      } /* end if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_READY ) */
      else
      {

        FrSM_RunTimer( FrSM_ClusterIndex );

        SchM_Enter_FrSM_FRSM_EXCLUSIVE_AREA_0( ); /* FrSM_RequestComMode( NoCom ) T09 T12 T13 T14  interrupts  Main *  FRSM_STATE_ONLINE T10 T16 * T14 vs  FRSM_STATE_ONLINE_PASSIVE  T15 + T17  vs */ /* PRQA S 3109 */ /* MD_MSR_14.3  */
        if ( FrIf_GetPOCStatus( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ), &FrSM_CurrentPocStatus ) == E_OK )  /* SBSW_FRSM_FUNCTIONCALL_WITHPOINTERTOLOCALVARIABLE */
        {

          if ( FrSM_CurrentPocStatus.Freeze == TRUE )
          {
            FrSM_CurrentPocStatus.State = FR_POCSTATE_HALT;
          }

#if ( FRSM_WAKEUPECUOFCLUSTERCONFIG == STD_ON )
          /* FrSM_IsWakeupEcuOfClusterConfig redundant to FRSM_BSWM_WAKEUP */
          if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_WAKEUP ) /* COV_FRSM_MIX_CONFIG_PARAMETER_BOOLEAN_WITH_VAR */
          {
            FrSM_StateWakeup( FrSM_ClusterIndex, FrSM_CurrentPocStatus.State, FrSM_CurrentPocStatus.WakeupStatus );
          } /* end if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_WAKEUP ) */
          else
#endif /* WakeupEcu FRSM_WAKEUPECUOFCLUSTERCONFIG */
          {
#if ( FRSM_ALLSLOTS_SUPPORT == STD_ON )
            FrSM_StateStartOnline( FrSM_ClusterIndex, FrSM_CurrentPocStatus.State, FrSM_CurrentPocStatus.SlotMode );
#else                                                        /* slot mode irrelevant */
            FrSM_StateStartOnline( FrSM_ClusterIndex, FrSM_CurrentPocStatus.State, FR_SLOTMODE_ALL );
#endif /* if ( FRSM_ALLSLOTS_SUPPORT == STD_ON ) */

          } /* end not WAKEUP */

        } /* end if valid POC state */

        FrSM_TimerTriggeredTransitions( FrSM_ClusterIndex );
        /* \trace SPEC-10986 */

        SchM_Exit_FrSM_FRSM_EXCLUSIVE_AREA_0( ); /* FrSM_RequestComMode( NoCom ) T09 T12 T13 T14  interrupts  Main *  FRSM_STATE_ONLINE T10 T16 * T14 vs  FRSM_STATE_ONLINE_PASSIVE  T15 + T17  vs */ /* PRQA S 3109 */ /* MD_MSR_14.3  */

      } /* end else of if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_READY ) */

      if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) != FrSM_PriorState )
      { /* FrSM_PriorState = FRSM_CurrentStateOfVarStruct; */
        BswM_FrSM_CurrentState(  FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), (FrSM_BswM_StateType)( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) + (uint8)FrSM_EcuPassiveMode ) );
        /* \trace  SPEC-11009 */
      }

    } /* end if ( FrSM_GetRequestedComModeOfVarStruct( FrSM_ClusterIndex ) == COMM_FULL_COMMUNICATION ) */
    else
    {
      /*  the else part == NoComReq, handled immediately inside the RequestFunc, and T11 handled above */
    }

  } /* end else if ( FRSM_IsInitialized == true ) */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON ) /*   */
  if ( FrSM_DetErrorId != FRSM_E_NO_ERROR )
  {
    (void)Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_SID_MAINFUNCTION, FrSM_DetErrorId );
  }
#else
  FRSM_DUMMY_STATEMENT( FrSM_DetErrorId ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* end   FRSM_DEV_ERROR_REPORT */

} /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STMIF, MD_MSR_STCAL, MD_MSR_STCYC */ /* end FrSM_MainFunction( const FRSM_ClusterIndexType FRSM_ClusterIdx ) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 ********************************************************************************************************************/
/********************************************************************************************************************
 *  FrSM_InitMemory()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC( void, FRSM_CODE ) FrSM_InitMemory( void )
{
  /* ----- Implementation ----------------------------------------------- */
  FRSM_IsInitialized = FALSE;
#if ( FRSM_USE_INIT_POINTER == STD_ON )
  FrSM_ConfigDataPtr = NULL_PTR;
#endif /* ( FRSM_USE_INIT_POINTER == STD_ON ) */

}    /* end FrSM_InitMemory() */

/**********************************************************************************************************************
 * FUNCTION: FrSM_Init
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC( void, FRSM_CODE ) FrSM_Init( CONSTP2CONST( FrSM_ConfigType, AUTOMATIC, FRSM_INIT_DATA ) ConfigPtr )
{
  /* \trace  SPEC-2181417 */
  /* \trace SPEC-10909 */
  uint8                       FrSM_DetErrorId = FRSM_E_NO_ERROR;
  FrSM_VarStructIterType      FrSM_ClusterIndex;
# if ( FRSM_USE_INIT_POINTER == STD_ON )
  FrSM_ConfigDataPtr = ConfigPtr;
  /* \trace SPEC-11012 */
# endif /* (  FRSM_USE_INIT_POINTER ) */

  /* ----- Development Error Checks ------------------------------------- */

#if (FRSM_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if ( FRSM_IsInitialized == TRUE )
  {
    FrSM_DetErrorId = FRSM_E_ALREADY_INITIALIZED;
  }
# if ( FRSM_USE_INIT_POINTER == STD_ON )
  else if ( FrSM_ConfigDataPtr == NULL_PTR )
  {
    FRSM_IsInitialized = FALSE;
    FrSM_DetErrorId = FRSM_E_NULL_PTR;
    /* \trace SPEC-10948 */
  }
# endif /* FRSM_USE_INIT_POINTER  */
  else
# endif /* FRSM_DEV_ERROR_DETECT  */
  {

#if ( FRSM_USE_INIT_POINTER == STD_ON )
    if ( FrSM_HasClusterConfig() ) /* COV_FRSM_CONFIG_PARAMETER_HAS_CLUSTER_CONFIG */
#endif /* FRSM_USE_INIT_POINTER  */
    {
      for ( FrSM_ClusterIndex = 0; FrSM_ClusterIndex < FrSM_GetSizeOfVarStruct( ); FrSM_ClusterIndex ++ ) /* lint +e442 +e440 */
      {

        /* State variable initialization of the current FR cluster */
        FrSM_SetRequestedComModeOfVarStruct( FrSM_ClusterIndex, COMM_NO_COMMUNICATION ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetTimer_ColdstartDelayOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_COLDSTART_DELAY_TIMER );  /* FRSM_MAX_COLDSTART_DELAY */    /* union FrSM_SetTimer_ColdstartDelayOfVarStruct FrSM_SetTrcvStbyDelay  */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetTimer_RetryStartUpOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_RETRY_STARTUP_TIMER ); /* FRSM_Timer_SuperviseStartup */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        FrSM_SetTimer_StartUpMonitoringOfVarStruct( FrSM_ClusterIndex, FRSM_CANCEL_STARTUP_MONITORING_TIMER );  /* FRSM_Timer_TillStartUpFail */ /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
        /* init of FrSM_GetStartup_CounterOfVarStruct( FrSM_ClusterIndex ) not necessary modified if FRSM_BSWM_READY is left */
        FrSM_SetInternalStateOfVarStruct( FrSM_ClusterIndex, FRSM_BSWM_READY ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
#if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
# if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
        FrSM_EcuPassiveMode           = FALSE;
# endif /* end #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */
#endif /* if ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */

        /* Transition T00 (reset to READY) Condition: [ initialization ] */
        (void)FrIf_ControllerInit( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
        /* \trace SPEC-10909 */
        /* \trace SPEC-11007 */

        FRSM_IsInitialized  = TRUE;
        /* \trace SPEC-10928 */

      } /* for each cluster */

    }  /* FrSM_HasClusterConfig */
  }   /* end if pointer NOT points to NULL */
  /* \trace  SPEC-11022 */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON ) /*   */
  if ( FrSM_DetErrorId != FRSM_E_NO_ERROR )
  {
    (void)Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_SID_INIT, FrSM_DetErrorId );
  }
#else /* FRSM_DEV_ERROR_REPORT */
  FRSM_DUMMY_STATEMENT( FrSM_DetErrorId ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* end   FRSM_DEV_ERROR_REPORT */
#if ( FRSM_USE_INIT_POINTER == STD_OFF ) /*   */
  FRSM_DUMMY_STATEMENT_CONST( ConfigPtr ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* FRSM_USE_INIT_POINTER  */

}  /* end FrSM_Init() */

/********************************************************************************************************************
 * FUNCTION: FrSM_RequestComMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_RequestComMode( NetworkHandleType NetworkHandle, ComM_ModeType ComM_Mode )
{
  /* \trace SPEC-10997 */
  Std_ReturnType            FrSM_StdReturnValue = E_NOT_OK;
  /* \trace SPEC-11003 */
  uint8                     FrSM_DetErrorId     = FRSM_E_NO_ERROR;
  FrSM_SizeOfVarStructType  FrSM_ClusterIndex;

#if ( FRSM_DEV_ERROR_DETECT == STD_ON )
  if ( !FRSM_IsInitialized )
  {
    FrSM_DetErrorId = FRSM_E_UNINIT;
    /* \trace SPEC-10932 */
  } /* FrSM has not been initialized  */
  else if (  ( ComM_Mode  != COMM_FULL_COMMUNICATION ) && ( ComM_Mode != COMM_NO_COMMUNICATION )  )
  { /* parameter ComM_Mode has an invalid value */
    FrSM_DetErrorId = FRSM_E_INV_MODE;
    /* \trace SPEC-10981 */
  }
  else
#endif /* FRSM_DEV_ERROR_DETECT  */
  {

    FrSM_ClusterIndex = FrSM_MapNetworkHandleToLocalIndex( NetworkHandle );
    /* \trace SPEC-812, SPEC-811 */
#if ( FRSM_DEV_ERROR_DETECT == STD_ON )
    if ( FrSM_ClusterIndex >= FrSM_GetSizeOfVarStruct() )
    {
      FrSM_DetErrorId = FRSM_E_INV_HANDLE;
      /* \trace SPEC-11041 */
    }
    else
#endif /* if (  ( FRSM_DEV_ERROR_DETECT == STD_ON )  ) */
    { /* FRSM_E_NO_ERROR */

      FrSM_StdReturnValue   = E_OK;
      FrSM_SetRequestedComModeOfVarStruct( FrSM_ClusterIndex, ComM_Mode ); /* SBSW_FRSM_ARRAY_WRITE_ACCESS */
      /* \trace SPEC-10947 */

      FrSM_HandleComModeRequest( FrSM_ClusterIndex );
      /* \trace SPEC-10955 */

    } /* NetworkHandle index  list ==> NetworkHandle valid */

  } /* FRSM_E_NO_ERROR */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON ) /*   */
  if ( FrSM_DetErrorId != FRSM_E_NO_ERROR )
  {
    (void)Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_SID_REQUESTCOMMODE, FrSM_DetErrorId );
  }
#else
  FRSM_DUMMY_STATEMENT( FrSM_DetErrorId ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
  FRSM_DUMMY_STATEMENT( NetworkHandle ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* end   FRSM_DEV_ERROR_REPORT */

  return FrSM_StdReturnValue;

}     /* end FrSM_RequestComMode() */

/********************************************************************************************************************
 * FUNCTION: FrSM_GetCurrentComMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_GetCurrentComMode( NetworkHandleType NetworkHandle, P2VAR( ComM_ModeType, AUTOMATIC, FRSM_APPL_VAR ) ComM_ModePtr )
{
  /* \trace SPEC-11018 */
  Std_ReturnType            FrSM_StdReturnValue = E_NOT_OK;
  uint8                     FrSM_DetErrorId     = FRSM_E_NO_ERROR;
  FrSM_SizeOfVarStructType  FrSM_ClusterIndex;

#if ( FRSM_DEV_ERROR_DETECT == STD_ON )
  if ( FRSM_IsInitialized != TRUE )
  { /* end if pointer NOT points to NULL_PTR */
    FrSM_DetErrorId = FRSM_E_UNINIT;
    /* \trace SPEC-10996 */
  }
  else if ( ComM_ModePtr == NULL_PTR )
  {
    FrSM_DetErrorId = FRSM_E_NULL_PTR;
    /* \trace SPEC-10950 */
  }
  else
#endif /* FRSM_DEV_ERROR_DETECT  */
  {

    FrSM_ClusterIndex = FrSM_MapNetworkHandleToLocalIndex( NetworkHandle );
    /* \trace SPEC-812 SPEC-811 */
#if ( FRSM_DEV_ERROR_DETECT == STD_ON )
    if ( FrSM_ClusterIndex >= FrSM_GetSizeOfVarStruct() )
    {
      FrSM_DetErrorId = FRSM_E_INV_HANDLE;
      /* \trace SPEC-11041 */
    }
    else
#endif /* if (  ( FRSM_DEV_ERROR_DETECT == STD_ON )  ) */
    { /* FRSM_E_NO_ERROR */

      FrSM_StdReturnValue   = E_OK;

      /* \trace SPEC-11016 */
      if ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex ) == FRSM_BSWM_ONLINE )
      {
        *ComM_ModePtr = COMM_FULL_COMMUNICATION;   /* CREQ-105685 */ /* PRQA S 0505 */ /* MD_FRSM_1.2 */  /* SBSW_FRSM_GETCURRENTCOMMODE_POINTERWRITEACCESS */
        /* \trace SPEC-10957 */
      }
      else                        /* NOT FULL communication */
      {
        *ComM_ModePtr = COMM_NO_COMMUNICATION;   /* CREQ-105686 */ /* PRQA S 0505 */ /* MD_FRSM_1.2 */  /* SBSW_FRSM_GETCURRENTCOMMODE_POINTERWRITEACCESS */
        /* \trace SPEC-10957 */
      }
    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* FRSM_E_NO_ERROR */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON ) /*   */
  if ( FrSM_DetErrorId != FRSM_E_NO_ERROR )
  {
    (void)Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_SID_GETCURRENTCOMMODE, FrSM_DetErrorId );
  }
#else /* FRSM_DEV_ERROR_REPORT */
  FRSM_DUMMY_STATEMENT( FrSM_DetErrorId ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
  FRSM_DUMMY_STATEMENT( NetworkHandle ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* end   FRSM_DEV_ERROR_REPORT */

  return FrSM_StdReturnValue;

}    /* end FrSM_GetCurrentComMode() */

/* \trace SPEC-11043 */
#if ( FRSM_VERSION_INFO_API == STD_ON )
/********************************************************************************************************************
 * FUNCTION: FrSM_GetVersionInfo
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC( void, FRSM_CODE ) FrSM_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, FRSM_APPL_VAR ) versioninfo )
{
  /* \trace SPEC-10962 */
  uint8 FrSM_DetErrorId = FRSM_E_NO_ERROR;

# if ( FRSM_DEV_ERROR_DETECT == STD_ON )
  if ( versioninfo == NULL_PTR )
  {
    FrSM_DetErrorId = FRSM_E_NULL_PTR;
  }
  else                          /* error parameter versioninfo is a NULL pointer */
# endif /* if (  ( FRSM_DEV_ERROR_DETECT == STD_ON )  ) */
  { /* FRSM_E_NO_ERROR */
    (*versioninfo).vendorID         = (uint16)FRSM_VENDOR_ID;    /* SBSW_FRSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*versioninfo).moduleID         = (uint16)FRSM_MODULE_ID;    /* SBSW_FRSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*versioninfo).sw_major_version =  (uint8)FRSM_SW_MAJOR_VERSION;  /* SBSW_FRSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*versioninfo).sw_minor_version =  (uint8)FRSM_SW_MINOR_VERSION;  /* SBSW_FRSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*versioninfo).sw_patch_version =  (uint8)FRSM_SW_PATCH_VERSION;  /* SBSW_FRSM_GETVERSIONINFO_POINTERWRITEACCESS */
    /* \trace SPEC-10983 */
  } /* FRSM_E_NO_ERROR */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON ) /*   */
  if ( FrSM_DetErrorId != FRSM_E_NO_ERROR )
  {
    (void)Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_SID_GETVERSIONINFO, FrSM_DetErrorId );
  }
#else /* FRSM_DEV_ERROR_REPORT */
  FRSM_DUMMY_STATEMENT( FrSM_DetErrorId ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* end   FRSM_DEV_ERROR_REPORT */

}    /* end FrSM_GetVersionInfo() */
#endif

#if ( FRSM_ALLSLOTS_SUPPORT == STD_ON )
/********************************************************************************************************************
 * FUNCTION: FrSM_AllSlots
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* \trace  SPEC-2181484 */
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_AllSlots( NetworkHandleType NetworkHandle )
{
  /* \trace SPEC-10911 */
  Std_ReturnType            FrSM_StdReturnValue = E_NOT_OK;
  uint8                     FrSM_DetErrorId     = FRSM_E_NO_ERROR;
  FrSM_SizeOfVarStructType  FrSM_ClusterIndex;

# if ( FRSM_DEV_ERROR_DETECT == STD_ON )
  if ( FRSM_IsInitialized != TRUE )
  {
    FrSM_DetErrorId = FRSM_E_UNINIT;
    /* \trace SPEC-10935 */
  }
  else
#endif /* FRSM_DEV_ERROR_DETECT  */
  {

    FrSM_ClusterIndex = FrSM_MapNetworkHandleToLocalIndex( NetworkHandle );
    /* \trace SPEC-812 SPEC-811 */
#if ( FRSM_DEV_ERROR_DETECT == STD_ON )
    if ( FrSM_ClusterIndex >= FrSM_GetSizeOfVarStruct() )
    {
      FrSM_DetErrorId = FRSM_E_INV_HANDLE;
      /* \trace SPEC-10959 */
    }
    else
#endif /* if (  ( FRSM_DEV_ERROR_DETECT == STD_ON )  ) */
    { /* FRSM_E_NO_ERROR */

      /* FrSM_StdReturnValue = E_OK; */
      FrSM_StdReturnValue = FrIf_AllSlots( FrSM_GetControllerIndexOfClusterConfig( FrSM_ClusterIndex ) );
      /* \trace SPEC-10921 */
    } /* NetworkHandle index  list ==> NetworkHandle valid */

  } /* FRSM_E_NO_ERROR */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON ) /*   */
  if ( FrSM_DetErrorId != FRSM_E_NO_ERROR )
  {
    (void)Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_SID_ALLSLOTS, FrSM_DetErrorId );
  }
#else /* FRSM_DEV_ERROR_REPORT */
  FRSM_DUMMY_STATEMENT( FrSM_DetErrorId ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
  FRSM_DUMMY_STATEMENT( NetworkHandle ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* end   FRSM_DEV_ERROR_REPORT */

  return FrSM_StdReturnValue;

}  /* end FrSM_AllSlots() */
#endif /* if ( FRSM_ALLSLOTS_SUPPORT == STD_ON ) */

#if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
/********************************************************************************************************************
 * FUNCTION: FrSM_SetEcuPassive
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* \trace  SPEC-2181441 */
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_SetEcuPassive( boolean FrSM_Passive )
{
  /* \trace SPEC-10985 */
  Std_ReturnType              FrSM_StdReturnValue = E_NOT_OK;
  uint8                       FrSM_DetErrorId     = FRSM_E_NO_ERROR;
#if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )
  FrSM_ClusterConfigIterType  FrSM_ClusterIndex;
#endif /* ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */

#if ( FRSM_DEV_ERROR_DETECT == STD_ON )
  if ( FRSM_IsInitialized != TRUE )
  {
    FrSM_DetErrorId = FRSM_E_UNINIT;
    /* \trace SPEC-11015 */
  }
  else
#endif /* if (  ( FRSM_DEV_ERROR_DETECT == STD_ON )  ) */
  { /* FRSM_E_NO_ERROR */
# if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON )

    if ( FrSM_EcuPassiveMode != FrSM_Passive )
    {
      FrSM_EcuPassiveMode = FrSM_Passive;
      /* \trace SPEC-10940 */

      for ( FrSM_ClusterIndex = 0; FrSM_ClusterIndex < FrSM_GetSizeOfVarStruct( ); FrSM_ClusterIndex ++ ) /* lint +e442 +e440 */
      {
        if ( FrSM_IsTrcv_HandlingOfClusterConfig( FrSM_ClusterIndex ) )  /* COV_FRSM_CONFIG_PARAMETER_BOOLEAN */
        {
          FrSM_StdReturnValue = E_OK;

          SchM_Enter_FrSM_FRSM_EXCLUSIVE_AREA_3( );  /* FrSM_Mainfunction * T01 T02   interrupts FrSM_SetEcuPassive T01 T02 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */

          /* \trace SPEC-11019 */
          if (  ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex )  != FRSM_BSWM_READY ) && ( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex )  != FRSM_BSWM_HALT_REQ )  )
          {
            FrSM_StartTrcv( FrSM_ClusterIndex );
          }    /* end if transceiver has to be switched */

          SchM_Exit_FrSM_FRSM_EXCLUSIVE_AREA_3( );   /* FrSM_Mainfunction * T01 T02   interrupts FrSM_SetEcuPassive T01 T02 */ /* PRQA S 3109 */ /* MD_MSR_14.3  */

          BswM_FrSM_CurrentState(  FrSM_GetNetworkHandleOfClusterConfig( FrSM_ClusterIndex ), (FrSM_BswM_StateType)( FrSM_GetInternalStateOfVarStruct( FrSM_ClusterIndex )  + (uint8)FrSM_EcuPassiveMode ) );

        }
      } /* for each cluster */

      /* \trace  SPEC-11009 */

    } /* end if passive mode changed */

# else  /* else #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */
    FRSM_DUMMY_STATEMENT( FrSM_Passive ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* end   else #if ( FRSM_TRCV_HANDLINGOFCLUSTERCONFIG == STD_ON ) */
  } /* FRSM_E_NO_ERROR */

#if ( FRSM_DEV_ERROR_REPORT == STD_ON ) /*   */
  if ( FrSM_DetErrorId != FRSM_E_NO_ERROR )
  {
    (void)Det_ReportError( (uint16)FRSM_MODULE_ID, FRSM_DEFAULT_INSTANCE_ID, FRSM_SID_SETECUPASSIVE, FrSM_DetErrorId );
  }
#else /* FRSM_DEV_ERROR_REPORT */
  FRSM_DUMMY_STATEMENT( FrSM_DetErrorId ); /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* end   FRSM_DEV_ERROR_REPORT */

  return FrSM_StdReturnValue;

}    /* end FrSM_SetEcuPassive() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* end if ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */

#define FRSM_STOP_SEC_CODE
#include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
   MD_FRSM_1.2
Reason:     Null pointer check only active if FRSM_DEV_ERROR_DETECT is activated
Risk:       usage of null pointer
Prevention: System has to be evaluated (with activated FRSM_DEV_ERROR_DETECT).
MD_FRSM_15.2
Reason:     Intentionally switch case with out break statement to proceed the next step immediately
Risk:       none
Prevention: Covered by code review.
*/

/* START_COVERAGE_JUSTIFICATION

   \ID COV_FRSM_CHECKDEFINE
   \ACCEPT TX
   \REASON The condition checks whether a define exists and conditionally assigns a default value.

   \ID COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL
   \ACCEPT TX
   \ACCEPT XF
   \REASON Distinguish dual and single channel

   \ID COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL_AFTEREFFECT
   \ACCEPT TX
   \ACCEPT XX
   \REASON WakeUpType does not change if it is a single channel config without check wakeup reason
   \REASON COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL is XF

   \ID COV_FRSM_CONFIG_PARAMETER_DUAL_ALWAYS_TRUE
   \ACCEPT TX
   \ACCEPT XF
   \REASON Config parameter dual always true

   \ID COV_FRSM_CONFIG_PARAMETER_DUAL_SINGLE_CHANNEL_NUM_WUP
   \ACCEPT TX
   \ACCEPT XF
   \ACCEPT XX
   \REASON Distinguish dual and single channel
   \REASON COV_FRSM_CONFIG_PARAMETER_CONST_NUMBER

   \ID COV_FRSM_CONFIG_PARAMETER_CONST_NUMBER
   \ACCEPT TX
   \ACCEPT XF
   \REASON Parameter may be invariant for a single configuration

   \ID COV_FRSM_CONFIG_CHECKWAKEUP_NOT_POSSIBLE
   \ACCEPT TX
   \ACCEPT XF
   \REASON check wakeup not possible so wake up always performed

   \ID COV_FRSM_CONFIG_PARAMETER_BOOLEAN
   \ACCEPT TX
   \ACCEPT XF
   \REASON Parameter may be invariant for a single configuration

   \ID COV_FRSM_MIX_CONFIG_PARAMETER_BOOLEAN_WITH_VAR
   \ACCEPT TF tx tf
   \REASON Parameter may be invariant for a single configuration

   \ID COV_FRSM_CONFIG_PARAMETER_BOOLEAN_AFTEREFFECT
   \ACCEPT TX
   \ACCEPT XF
   \ACCEPT XX
   \REASON Parameter may be invariant for a single configuration
   \REASON Consequence of COV_FRSM_CONFIG_PARAMETER_COMBINATION_4

   \ID COV_FRSM_CONFIG_PARAMETER_BOOLEAN_AFTEREFFECT_2
   \ACCEPT TF tf tx
   \REASON Parameter may be invariant for a single configuration
   \REASON Consequence of COV_FRSM_CONFIG_PARAMETER_BOOLEAN

   \ID COV_FRSM_CONFIG_PARAMETER_FUNCTION_POINTER
   \ACCEPT TF tf tf tx
   \ACCEPT XF tf tf xf
   \REASON Parameter may be invariant for a single configuration

   \ID COV_FRSM_CONFIG_PARAMETER_HAS_CLUSTER_CONFIG
   \ACCEPT TX
   \ACCEPT XF
   \REASON Parameter is invariant for a single configuration

   \ID COV_FRSM_CONFIG_PARAMETER_SLOT_MODE
   \ACCEPT TF tf tx
   \REASON Slotmode is invariant if all slot mode is disabled

   \ID COV_FRSM_CONFIG_PARAMETER_SLOT_MODE_KEY_SLOT
   \ACCEPT TF tf xf
   \REASON Slotmode is invariant if all slot mode is disabled

   \ID COV_FRSM_CONFIG_PARAMETER_TIMER_COLDSTART
   \ACCEPT TF tf tx
   \ACCEPT XF tf xf
   \REASON If timer FRSM_TIMER_EXPIRED it is always evaluated and set to FRSM_CANCEL_TIMER. Statement keept due to robustness
   \REASON Configuration Value is set to MIN value

   \ID COV_FRSM_CONFIG_PARAMETER_REPETITION
   \ACCEPT XF
   \ACCEPT TF tx tf
   \ACCEPT TF tf tx
   \ACCEPT XF tx xf
   \ACCEPT TF tf tx tf
   \ACCEPT TF tx tf tf
   \ACCEPT TF tx tf tx
   \ACCEPT TF tx tf tx tf
   \ACCEPT TF tf xf tx tf
   \REASON Configuration Value of start up repetitions with wakeup is configured to MIN value
   \REASON Repetitions are set to unlimited

   \ID COV_FRSM_CONFIG_PARAMETER_COMBINATION_1
   \ACCEPT TX
   \ACCEPT XF
   \ACCEPT XX
   \REASON Parameter may be invariant for a single configuration
   \REASON Statement never reached if IsDelayStartupWithoutWakeup is active at all clusters

   \ID COV_FRSM_CONFIG_PARAMETER_COMBINATION_2
   \ACCEPT TX
   \ACCEPT XF
   \ACCEPT TX tx tx
   \ACCEPT XF tx xf
   \ACCEPT TF tx tf
   \ACCEPT XF tf xf
   \REASON Parameter wake up ECU may be invariant for a single configuration
   \REASON Parameter check wake up reason may be invariant for a single configuration

   \ID COV_FRSM_CONFIG_PARAMETER_COMBINATION_3
   \ACCEPT TF tf xf
   \ACCEPT XF xf xf
   \REASON Parameter may be invariant for a single configuration
   \REASON FRSM_InternalStateOfVarStruct FRSM_BSWM_KEYSLOT_ONLY never reached if FRSM_ALLSLOTS_SUPPORT is OFF

   \ID COV_FRSM_CONFIG_PARAMETER_COMBINATION_4
   \ACCEPT XF
   \ACCEPT TX
   \ACCEPT TX xf tx
   \ACCEPT TX tf tx
   \REASON Parameter may be invariant for a single configuration
   \REASON Value StartupRepetitions is zero
   \REASON Value StartupRepetitions is equal to StartupRepetitionsWithWakeup
   \REASON Unlimited repetitions

   \ID COV_FRSM_CONFIG_PARAMETER_COMBINATION_5
   \ACCEPT TF xf tf tf
   \REASON Parameter may be invariant for a single configuration
   \REASON Tranceiverhandling with out additional standby delay

   \ID COV_FRSM_VARIABLE_TYPE_RANGE
   \ACCEPT TX
   \ACCEPT XX
   \REASON Variable type limit not reachable with automate test framework. Correctness is checked by review.

   END_COVERAGE_JUSTIFICATION
   */

/* SBSW_JUSTIFICATION_BEGIN

   \ID SBSW_FRSM_GETCURRENTCOMMODE_POINTERWRITEACCESS
   \DESCRIPTION The function writes to the object referenced by the pointer parameter.
   \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter is valid. [SMI-16]

   \ID SBSW_FRSM_GETVERSIONINFO_POINTERWRITEACCESS
   \DESCRIPTION The function writes to the object referenced by the pointer parameter.
   \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter is valid. [SMI-16]

   \ID SBSW_FRSM_COMMMODEINDICATION_CALL
   \DESCRIPTION   Call to ComM_BusSM_ModeIndication function with network handle and pointer to the communication mode variable.
   \COUNTERMEASURE \N The passed pointer references a local variable and is therefore always valid.

   \ID SBSW_FRSM_FUNCTIONCALL_WITHPOINTERTOLOCALVARIABLE
   \DESCRIPTION The function writes to the object referenced by the pointer parameter.
   \COUNTERMEASURE \N The passed pointer references a local variable and is therefore always valid.

   \ID SBSW_FRSM_SYNCLOSS_INDICATION
   \DESCRIPTION Function call via function pointer.
   \COUNTERMEASURE \S Verify that the function pointer refers to a valid function. SMI-332

   \ID SBSW_FRSM_ARRAY_WRITE_ACCESS
   \DESCRIPTION Access of cluster struct using ComStackLib
   \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

   SBSW_JUSTIFICATION_END
   */

/**********************************************************************************************************************
  END OF FILE: FrSM.c
 *******************************************************************************************************************/

