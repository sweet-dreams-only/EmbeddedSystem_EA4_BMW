
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
 *  -------------------------------------------------------------------------------------------------------------------
 * \file    FrSM.h
 * \brief   Public header of the FlexRay State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Mark A. Fingerle              MFi           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-04-13  MFi     ESCAN00058511 Create Ccl_Asr4SmFr Implementation according to ASR 4.0.3
 *  01.01.00  2013-03-13  MFi     ESCAN00062540 FrIf_AllowColdstart is called several times in sequence
 *                                ESCAN00066690 Adapt FrSM to new BswM header structure Include  "BswM_FrSM.h" instead  "BswM.h"
 *                                ESCAN00066936 Correct compiler abstraction and memory mapping
 *                                ESCAN00067082 SetWakeupChannel not called in case of an internal dual channel wake up
 *  01.02.00  2013-09-23  MFi     ESCAN00069426 Memory Mapping not possible for variable FRSM_WakeUpType, FRSM_StartupCounter and FRSM_WakeUpPatternCounter
 *  01.03.00  2014-01-23  MFi     ESCAN00071806 ECU communication not set to "ECU passive mode" (FRTRCV_TRCVMODE_RECEIVEONLY)
 *                                ESCAN00073139 Unlimited Startup repetitions also repeats wake-up (REPETITIONS_WITH_WAKEUP)
 *  01.04.00  2014-09-23  MFi     ESCAN00078750 Post-Build Selectable (Identity Manager)
 *                                ESCAN00075457 Add support for delayed FlexRay communication cluster shutdown
 *  01.04.01  2014-11-21  MFi     ESCAN00079315 FrSM stays in state HALT_REQ (Freeze not evaluated)
 *  01.05.00  2015-05-13  MFi     ESCAN00083893 Allow Wake Up Attempts On Both Channels
 *  02.00.00  2015-09-13  MFi     ESCAN00080304 FEAT-427: SafeBSW Step I
 *                                ESCAN00085151 FEAT-1527: SafeBSW Step 3
 *                                ESCAN00084385 Only a single wakeup pattern is transmitted (even FrSMNumWakeupPatterns is greater one). Start FRSM_WakeUpPatternCounter also in T20, resp. T20c
 *                                ESCAN00085133 Compiler error: API Det_ReportError missing
 *                                ESCAN00086137 The main function raises a Det error (FRSM_SID_MAINFUNCTION, FRSM_E_UNINIT) (BSW00450)
 *                                ESCAN00086153 MISRA deviation: MISRA-C:2004 Rule 8.8 (external linkage of FrSM_ConfigPtr)
 *  02.01.00  2016-02-13  MFi     ESCAN00087808 FEAT-1688: SafeBSW Step 4
 *  02.02.00  2017-01-13  MFi     FEATC-1079     Multi Fr Cluster
 *  02.02.01  2017-11-23  MFi     ESCAN00097415 FlexRay communication not possible at  non wakeup cluster (multi cluster system, with mixed wakeup and non wakeup clusters, with deactivated check wake up reason)
 *********************************************************************************************************************/


#if !defined (FRSM_H)
# define FRSM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


# include "FrSM_Cfg.h"
/* \trace SPEC-11026 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/* Vendor and module identification */
# define FRSM_VENDOR_ID                                               (0x001Eu)
/* \trace SPEC-11040 */
# define FRSM_MODULE_ID                                               (0x8Eu)
/* \trace SPEC-11040 */


/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmFr CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMFR_VERSION                                          0x0202
# define CCL_ASR4SMFR_RELEASE_VERSION                                  0x00



/* disables the one-shot timer if it elapsed or has to be canceled */
# define FRSM_CANCEL_COLDSTART_DELAY_TIMER                            (FRSM_MAX_TIMER_COLDSTARTDELAYOFVARSTRUCT)
# define FRSM_CANCEL_RETRY_STARTUP_TIMER                              (FRSM_MAX_TIMER_RETRYSTARTUPOFVARSTRUCT)
# define FRSM_CANCEL_STARTUP_MONITORING_TIMER                         (FRSM_MAX_TIMER_STARTUPMONITORINGOFVARSTRUCT)

# define FRSM_COLDSTART_DELAY_TIMER_EXPIRED                            (FRSM_MIN_TIMER_COLDSTARTDELAYOFVARSTRUCT)
# define FRSM_TRCV_STBY_DELAY_TIMER_EXPIRED                            (FRSM_MIN_TIMER_COLDSTARTDELAYOFVARSTRUCT)
# define FRSM_RETRY_STARTUP_TIMER_EXPIRED                              (FRSM_MIN_TIMER_RETRYSTARTUPOFVARSTRUCT)
# define FRSM_STARTUP_MONITORING_TIMER_EXPIRED                         (FRSM_MIN_TIMER_STARTUPMONITORINGOFVARSTRUCT)


/* AUTOSAR FlexRay State Manager version */
# define FRSM_AR_RELEASE_MAJOR_VERSION                                (0x04u)                                /* Major version number of AUTOSAR specification on which the appropriate implementation is based on. */
/* \trace SPEC-11040 */
# define FRSM_AR_RELEASE_MINOR_VERSION                                (0x00u)                               /* Minor version number of AUTOSAR specification on which the appropriate implementation is based on. */
/* \trace SPEC-11040 */
# define FRSM_AR_RELEASE_REVISION_VERSION                             (0x03u)                              /* Patch level version number of AUTOSAR specification on which the appropriate implementation is based on. */
/* \trace SPEC-11040  */
/* \trace SPEC-11010 */

# define FRSM_SW_MAJOR_VERSION                                        (CCL_ASR4SMFR_VERSION >> 8)         /* Major version number of the vendor specific implementation of the module. */
/* \trace SPEC-11040 */
# define FRSM_SW_MINOR_VERSION                                        (CCL_ASR4SMFR_VERSION &  0x00FFu)  /* Minor version number of the vendor specific implementation of the module. */
/* \trace SPEC-11040 */
# define FRSM_SW_PATCH_VERSION                                        (CCL_ASR4SMFR_RELEASE_VERSION)    /* Patch level version number of the vendor specific implementation of the module. */
/* \trace SPEC-11040 */
/* \trace SPEC-11010 */



# define FRSM_DEFAULT_INSTANCE_ID                                     (0x00u)


# define FRSM_INITIAL                                                 (0xEEu)


/* ----- API service IDs ----- */
# define FRSM_SID_INIT                                         (0x01u)
# define FRSM_SID_REQUESTCOMMODE                               (0x02u)
# define FRSM_SID_GETCURRENTCOMMODE                            (0x03u)
# define FRSM_SID_GETVERSIONINFO                               (0x04u)
# define FRSM_SID_ALLSLOTS                                     (0x05u)
# define FRSM_SID_SETECUPASSIVE                                (0x06u)
# define FRSM_SID_MAINFUNCTION                                (0x80u)

/* \trace SPEC-10937 */
/* ----- Error codes ----- */
# define FRSM_E_NO_ERROR                          (0x00u) /*!< used to check if no error occurred - use a value unequal to any error code */
# define FRSM_E_NULL_PTR                          (0x01u) /*!< Error code: API service used with invalid pointer parameter (NULL) */
# define FRSM_E_INV_HANDLE                        (0x02u) /*!< Error Code: API service used with an invalid channel identifier or channel was not configured for the functionality of the calling API */
# define FRSM_E_UNINIT                            (0x03u) /*!< Error code: API service used without module initialization */
# define FRSM_E_INV_MODE                          (0x04u) /*!< Error code: API service used with invalid mode parameter */
# define FRSM_E_ALREADY_INITIALIZED               (0x11u) /*!< Error code: The service FrSM_Init() is called while the module is already initialized  */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



#define FRSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST ( FrSMSyncLossErrorIndicationFctPtrType, FRSM_CONST )FrSMSyncLossErrorIndicationFctPtr;

#define FRSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define FRSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/********************************************************************************************************************
 *  FrSM_InitMemory()
 **********************************************************************************************************************/
/*! \brief       Function for *_INIT_*-variable initialization
 *  \details     Service to initialize module global variables at power up. This function can be used to initialize the
 *               Variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre         Module must not be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       -
 **********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSM_InitMemory( void );

/**********************************************************************************************************************
 * FrSM_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     This function initializes the module. It initializes all variables and sets the module state to READY.
 *  \param[in]   ConfigPtr               Configuration structure for initializing the module
 *  \pre         Interrupts are disabled.
 *  \pre         FrSM_InitMemory has been called unless FRSM_Initialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-105677
 *********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSM_Init( CONSTP2CONST( FrSM_ConfigType, AUTOMATIC, FRSM_CONST ) ConfigPtr );

/**********************************************************************************************************************
 *  FrSM_RequestComMode()
 *********************************************************************************************************************/
/*! \brief       Initiates the sequence to reach the requested communication mode
 *  \details     This API function is used by the ComM to startup or shutdown the communication on a FlexRay cluster.
 *  \param[in]   NetworkHandle                 FlexRay cluster for which a communication mode is requested
 *  \param[in]   ComM_Mode        Requested communication mode (Range: COMM_NO_COMMUNICATION, COMM_FULL_COMMUNICATION)
 *  \return      E_NOT_OK - function has been called with invalid parameters
 *  \return      E_OK - request accepted
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous FALSE
 *  \trace       -
 *********************************************************************************************************************/
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_RequestComMode( NetworkHandleType NetworkHandle, ComM_ModeType ComM_Mode );

/********************************************************************************************************************
 * FrSM_GetCurrentComMode
 **********************************************************************************************************************/
/*! \brief       Reports the communication mode
 *  \details     Reports the last communication mode which has been passed to the ComM
 *  \param[in]   NetworkHandle       FlexRay cluster for which a communication mode is requested
 *  \param[out]  ComM_ModePtr        Pointer to the memory location where the current communication mode shall be stored
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       -
 *  \trace       CREQ-105678
 **********************************************************************************************************************/
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_GetCurrentComMode( NetworkHandleType NetworkHandle, P2VAR( ComM_ModeType, AUTOMATIC, FRSM_APPL_VAR ) ComM_ModePtr );

# if ( FRSM_VERSION_INFO_API  == STD_ON )
/**********************************************************************************************************************
 *  FrSM_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     Returns the software version, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo             Pointer to version information. Parameter must not be NULL (BSW00407).
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      FRSM_VERSION_INFO_API
 *  \trace       CREQ-105679
 *********************************************************************************************************************/
FUNC( void, FRSM_CODE ) FrSM_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, FRSM_APPL_VAR ) versioninfo );
# endif


#if ( FRSM_ALLSLOTS_SUPPORT == STD_ON )
/********************************************************************************************************************
 * FrSM_AllSlots
 **********************************************************************************************************************/
/*! \brief       Calls the all slot function
 *  \details     Forwarding the function call to the FrIf
 *  \param[in]   NetworkHandle        FlexRay cluster for which a communication mode is requested
 *  \return      E_OK                Request was successful
 *  \return      E_NOT_OK            Request was not successful, any error occurred
 *  \pre         FrSM initialization
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      FRSM_ALLSLOTS_SUPPORT
 *  \trace       -
 **********************************************************************************************************************/
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_AllSlots( NetworkHandleType NetworkHandle );

# endif /* if ( FRSM_ALLSLOTS_SUPPORT == STD_ON ) */



# if ( FRSM_ECU_PASSIVE_MODE == STD_ON )
/********************************************************************************************************************
 * FrSM_SetEcuPassive
 **********************************************************************************************************************/
/*! \brief       This API function notifies the FrSM if ECU has to be set in passive mode
 *  \details     Transceiver is set to mode receive only if passive mode is activated
 *  \param[in]   FrSM_Passive              parameter is true if Ecu Mode should be passive
 *  \return      E_OK                Request was successful
 *  \return      E_NOT_OK            Request was not successful, any error occurred
 *  \pre         FrSM initialization
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      FRSM_ECU_PASSIVE_MODE
 *  \trace       -
 **********************************************************************************************************************/
FUNC( Std_ReturnType, FRSM_CODE ) FrSM_SetEcuPassive( boolean FrSM_Passive );


# endif /* end if ( FRSM_ECU_PASSIVE_MODE == STD_ON ) */
 /* \trace  SPEC-10998 */


# define FRSM_STOP_SEC_CODE
# include "MemMap.h"     /* PRQA S 5087 */ /* MD_MSR_19.1 */


/*
 * \exclusivearea FRSM_EXCLUSIVE_AREA_0
 * \protects FRSM_InternalState, FRSM_WakeUpType, FRSM_WakeUpPatternCounter, FrSM_RequestedComMode
 * \usedin FrSM_MainFunction_x
 * \length  LONG This exclusive area covers calls to several sub-functions.
 * \exclude FrSM_RequestComMode
 * \endexclusivearea

 * \exclusivearea FRSM_EXCLUSIVE_AREA_1
 * \protects TransceiverMode
 * \usedin FrSM_MainFunction_x
 * \length LONG This exclusive area covers calls to several sub-functions.
 * \exclude FrSM_SetEcuPassive()
 * \endexclusivearea

 * \exclusivearea FRSM_EXCLUSIVE_AREA_2
 * \protects FRSM_InternalState, FrSM_RequestedComMode
 * \usedin FrSM_RequestComMode
 * \length LONG This exclusive area covers calls to several sub-functions.
 * \exclude FrSM_SetEcuPassive() or FrSM_MainFunction_x
 * \endexclusivearea

 * \exclusivearea FRSM_EXCLUSIVE_AREA_3
 * \protects TransceiverMode
 * \usedin FrSM_SetEcuPassive
 * \length MEDIUM This exclusive area covers calls to a few sub-functions.
 * \exclude  FrSM_RequestComMode
 * \endexclusivearea
 */

#endif /* FRSM_H */
/**********************************************************************************************************************
  END OF FILE: FrSM.h
 **********************************************************************************************************************/

