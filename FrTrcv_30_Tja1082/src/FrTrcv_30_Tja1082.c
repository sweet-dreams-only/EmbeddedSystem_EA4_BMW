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
 *  \file  FrTrcv_30_Tja1082.c
 *  \brief  MICROSAR FR Transceiver Driver
 *
 *  \details  FlexRay transceiver driver implementation
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
 *********************************************************************************************************************/

#define FRTRCV_30_TJA1082_SOURCE

/**************************************************************************************************
* Include files
**************************************************************************************************/
/* FlexRay transceiver driver declarations */
#include "FrTrcv_30_Tja1082.h"
#include "FrTrcv_30_Tja1082_Cbk.h"

#if ( FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON )
#  include "Det.h"
#endif

/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
/* Check consistency of source and header file. */
#if defined ( DRVTRANS_TJA1082FRASR_VERSION )
# if ( DRVTRANS_TJA1082FRASR_VERSION != 0x0200u )
#  error "Source and Header file are inconsistent!"
# endif
# if ( DRVTRANS_TJA1082FRASR_RELEASE_VERSION != 0x01u )
#  error "Source and Header file are inconsistent!"
# endif
#endif

/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/

/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/
typedef uint8 FrTrcv_30_Tja1082_InitStatusType; /* PRQA S 3448 */ /* MD_FRTRCV_3448 */

/**************************************************************************************************
* Macros
**************************************************************************************************/
/* FrTrcv051:, FrTrcv061:, FrTrcv037: */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
# define FrTrcv_30_Tja1082_CallDetReportError( API_ID, ERROR_CODE ) (void)Det_ReportError( FRTRCV_30_TJA1082_MODULE_ID, FRTRCV_30_TJA1082_INSTANCE_ID, (API_ID), (ERROR_CODE)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define FrTrcv_30_Tja1082_CallDetReportError( API_ID, ERROR_CODE ) 
#endif

/* FrTrcv052: */
#if ( FRTRCV_30_TJA1082_PROD_ERROR_DETECT == STD_ON )
# if ( FRTRCV_30_TJA1082_TRCV_DEM_CALLBACK == STD_ON )
    /* PRQA S 3453 12 */ /* MD_MSR_19.7 */
#  define FrTrcv_DemReportErrorPreFailed(eventId) Appl_FrTrcv_30_Tja1082_ReportErrorStatusPreFailed(eventId)
#  define FrTrcv_DemReportErrorPrePassed(eventId) Appl_FrTrcv_30_Tja1082_ReportErrorStatusPrePassed(eventId)
# else
#  define FrTrcv_DemReportErrorPreFailed(eventId) ((void)Dem_ReportErrorStatus((Dem_EventIdType)(eventId), (uint8)(DEM_EVENT_STATUS_PREFAILED)))
#  define FrTrcv_DemReportErrorPrePassed(eventId) ((void)Dem_ReportErrorStatus((Dem_EventIdType)(eventId), (uint8)(DEM_EVENT_STATUS_PREPASSED)))
# endif
#else
#  define FrTrcv_DemReportErrorPreFailed(eventId)
#  define FrTrcv_DemReportErrorPrePassed(eventId)
#endif

#define FrTrcv_30_Tja1082_EnterCritical() SchM_Enter_FrTrcv_30_Tja1082_FRTRCV_30_TJA1082_EXCLUSIVE_AREA_0()
#define FrTrcv_30_Tja1082_LeaveCritical() SchM_Exit_FrTrcv_30_Tja1082_FRTRCV_30_TJA1082_EXCLUSIVE_AREA_0()

#define FRTRCV_30_TJA1082_UNINIT  (FrTrcv_30_Tja1082_InitStatusType)0u /* The FrTrcv is not initialized and is not usable. */
#define FRTRCV_30_TJA1082_INIT    (FrTrcv_30_Tja1082_InitStatusType)1u /* The FrTrcv is initialized and is usable. */

/* Keyword macros */
# if !defined (STATIC)                                  /* COV_FRTRCV_30_TJA1082_MSR_COMPATIBILITY */
#  define STATIC static
# endif

# if !defined (INLINE)                                  /* COV_FRTRCV_30_TJA1082_MSR_COMPATIBILITY */
#  define INLINE
# endif

# if !defined (LOCAL_INLINE)                            /* COV_FRTRCV_30_TJA1082_MSR_COMPATIBILITY */
#  define LOCAL_INLINE INLINE STATIC
# endif

# if !defined (FRTRCV_30_TJA1082_LOCAL)                 /* COV_FRTRCV_30_TJA1082_MSR_COMPATIBILITY */
#  define FRTRCV_30_TJA1082_LOCAL STATIC
# endif

# if !defined (FRTRCV_30_TJA1082_LOCAL_INLINE)          /* COV_FRTRCV_30_TJA1082_MSR_COMPATIBILITY */
#  define FRTRCV_30_TJA1082_LOCAL_INLINE LOCAL_INLINE
# endif

/**************************************************************************************************
* Data definitions
**************************************************************************************************/

/******************************************************************************/
/* Local Data definitions                                                     */
/******************************************************************************/
#define FRTRCV_30_TJA1082_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

volatile VAR( FrTrcv_30_Tja1082_InitStatusType, FRTRCV_30_TJA1082_VAR_ZERO_INIT ) FrTrcv_30_Tja1082_IsInitialized = FRTRCV_30_TJA1082_UNINIT; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */

#define FRTRCV_30_TJA1082_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

#define FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

VAR( FrTrcv_TrcvWUReasonType, FRTRCV_30_TJA1082_VAR_NOINIT ) FrTrcv_30_Tja1082_TrcvWUReason[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES]; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */

#define FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

#define FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

VAR( uint8, FRTRCV_30_TJA1082_VAR_NOINIT ) FrTrcv_30_Tja1082_WakeupDetected[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES]; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */

#define FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

#define FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

VAR( uint32, FRTRCV_30_TJA1082_VAR_NOINIT ) FrTrcv_30_Tja1082_BusErrorState[FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES]; /* PRQA S 3408 */ /* MD_FRTRCV_3408 */

#define FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

#define FRTRCV_30_TJA1082_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/
/**********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTrcvState()
 *********************************************************************************************************************/
/*! 
 *  \brief       Read back the current Trcv state.
 *  \details     Reads back the current Trcv state by reading the STBN and ERRN Pin.
 *  \param[in]   FrTrcv_TrcvIdx    The selected FlexRay bus transceiver.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \return      The current Trcv state.
 **********************************************************************************************************************/
FRTRCV_30_TJA1082_LOCAL_INLINE FUNC(uint8, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTrcvState(uint8 FrTrcv_TrcvIdx);

/**************************************************************************************************
*  Implementation
**************************************************************************************************/

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_InitMemory
 **********************************************************************************************************************/
/*! 
 * Internal comment removed.
 *
 *
 */
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_InitMemory( void )
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set module to uninitialized state. */
  FrTrcv_30_Tja1082_IsInitialized = FRTRCV_30_TJA1082_UNINIT;
}

/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_Init
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_Init( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 i;

  /* ----- Implementation ----------------------------------------------- */
  FrTrcv_30_Tja1082_IsInitialized = FRTRCV_30_TJA1082_INIT;
  /* #10 Iterate over all configured channels. */
  for (i = 0; i < FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES; i++)
  {
    /* #20 Initialize variables to initial/default values */
    FrTrcv_30_Tja1082_WakeupDetected[i] = 0u;                              /* SBSW_FRTRCV_TRCVIDXLOOPCONDITION */
    FrTrcv_30_Tja1082_TrcvWUReason[i]   = FRTRCV_WU_NOT_SUPPORTED;         /* SBSW_FRTRCV_TRCVIDXLOOPCONDITION */
    FrTrcv_30_Tja1082_BusErrorState[i]  = FRTRCV_30_TJA1082_ERROR_NONE;    /* SBSW_FRTRCV_TRCVIDXLOOPCONDITION */
    if (FrTrcv_30_Tja1082_Config[i].FrTrcv_ChannelUsed != 0u)
    {
      /* #30 Check for pending wakeup events if wake up detection is enabled */
      if (FrTrcv_30_Tja1082_Config[i].FrTrcv_WakeupSupported > 0u)
      {
        FrTrcv_30_Tja1082_TrcvWUReason[i] = FRTRCV_WU_RESET;                /* SBSW_FRTRCV_TRCVIDXLOOPCONDITION */
        /* Check for pending wake up */
        if (E_OK != FrTrcv_30_Tja1082_SetTransceiverMode(i, FRTRCV_TRCVMODE_STANDBY))
        {
          FrTrcv_30_Tja1082_CallDetReportError( FRTRCV_30_TJA1082_SID_TRCVINIT, FRTRCV_30_TJA1082_E_FR_NO_CONTROL_TRCV );
        }
# if ( FRTRCV_30_TJA1082_IMMEDIATE_WAKEUP_CHECK == STD_OFF )
        FrTrcv_30_Tja1082_CheckWakeupByTransceiver(i);
# endif
      }

      /* #40 Set the transceiver to a default state */
      if (E_OK != FrTrcv_30_Tja1082_SetTransceiverMode(i, FrTrcv_30_Tja1082_Config[i].FrTrcv_InitState))
      {
        FrTrcv_30_Tja1082_CallDetReportError( FRTRCV_30_TJA1082_SID_TRCVINIT, FRTRCV_30_TJA1082_E_FR_NO_CONTROL_TRCV );
      }
    }
  }
}

/* FrTrcv330: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_MainFunction( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 trcvChannel;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Only if initialized... */
  if (FRTRCV_30_TJA1082_INIT == FrTrcv_30_Tja1082_IsInitialized)
  {
    /* #20 Iterate over all configured channels. */
    for (trcvChannel = 0u; trcvChannel < FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES; trcvChannel++ )
    {
      /* #30 ...and if polling is used: check for pending wakeup events if wake up detection is enabled, throw DEM error if diagnosis is enabled. */
      if( (0 != FrTrcv_30_Tja1082_Config[trcvChannel].FrTrcv_WakeupPolling) &&
          (0 != FrTrcv_30_Tja1082_Config[trcvChannel].FrTrcv_ChannelUsed) )
      {
        /* Check for pending wakeup events and bus errors */
        FrTrcv_30_Tja1082_CheckWakeupByTransceiver(trcvChannel);
      }
    }
  }
}

/* FrTrcv339: */
#if ( FRTRCV_30_TJA1082_VERSION_INFO_API == STD_ON )
/* FrTrcv326: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetVersionInfo
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTRCV_30_TJA1082_E_FR_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check versioninfo for NULL pointer. Note: no uninit check is performed. */
  if (versioninfo == NULL_PTR)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_TRCV_NULL_PTR;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* FrTrcv285: */
    /* #20 Set versioninfo with corresponding macros from component header. */
    versioninfo->vendorID         = (uint16)FRTRCV_30_TJA1082_VENDOR_ID;            /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->moduleID         = (uint8)FRTRCV_30_TJA1082_MODULE_ID;             /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->sw_major_version = (uint8)FRTRCV_30_TJA1082_SW_MAJOR_VERSION;      /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->sw_minor_version = (uint8)FRTRCV_30_TJA1082_SW_MINOR_VERSION;      /* SBSW_FRTRCV_PARAM_GETVERSION */
    versioninfo->sw_patch_version = (uint8)FRTRCV_30_TJA1082_SW_PATCH_VERSION;      /* SBSW_FRTRCV_PARAM_GETVERSION */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRTRCV_30_TJA1082_E_FR_NO_ERROR)
  {
    FrTrcv_30_Tja1082_CallDetReportError(FRTRCV_30_TJA1082_SID_GETVERSIONINFO, errorId);
  }
#else
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
}
#endif

/* FrTrcv323: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_SetTransceiverMode
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
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_SetTransceiverMode(uint8 FrTrcv_TrcvIdx, FrTrcv_TrcvModeType FrTrcv_TrcvMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  FrTrcv_TrcvModeType FrTrcv_ActualTrcvMode;
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1082_E_FR_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check channel index and initialization state */
  if (FrTrcv_30_Tja1082_IsInitialized == FRTRCV_30_TJA1082_UNINIT)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_UNINIT;
  }
  else
  if (FrTrcv_TrcvIdx >= FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
  if (FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_ChannelUsed == 0u)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    /* #20 Determine if valid mode (normal, standby, sleep, receiveonly) is requested and set mode */
    switch (FrTrcv_TrcvMode)
    {
      case FRTRCV_TRCVMODE_NORMAL :
      case FRTRCV_TRCVMODE_RECEIVEONLY :
      {
        /* #30 Map unsupported states to supported ones */
        FrTrcv_TrcvMode = FRTRCV_TRCVMODE_NORMAL;
        FrTrcv_30_Tja1082_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        Dio_WriteChannel(FrTrcv_30_Tja1082_Channel[FrTrcv_TrcvIdx].TrcvPinSTBN, STD_HIGH);
        /* #40 Wait time to counter delay of STBN */
        Appl_FrTrcv_30_Tja1082_Wait(kFrTrcv_30_Tja1082_SetMode);
        FrTrcv_30_Tja1082_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        Appl_FrTrcv_30_Tja1082_Wait(kFrTrcv_30_Tja1082_ModeChange);
      } break;

      case FRTRCV_TRCVMODE_STANDBY :
      case FRTRCV_TRCVMODE_SLEEP :
      {
        /* #30 Map unsupported states to supported ones */
        FrTrcv_TrcvMode = FRTRCV_TRCVMODE_STANDBY;
        FrTrcv_30_Tja1082_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        Dio_WriteChannel(FrTrcv_30_Tja1082_Channel[FrTrcv_TrcvIdx].TrcvPinSTBN, STD_LOW);
        /* #40 Wait time to counter delay of STBN */
        Appl_FrTrcv_30_Tja1082_Wait(kFrTrcv_30_Tja1082_SetMode);
        FrTrcv_30_Tja1082_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        Appl_FrTrcv_30_Tja1082_Wait(kFrTrcv_30_Tja1082_ModeChange);
      } break;
      
      default :
      {
        /* #60 If invalid mode is requested, provide DET error */
        errorId = FRTRCV_30_TJA1082_E_FR_INVALID_MODE;
      }
    }

    if( errorId == FRTRCV_30_TJA1082_E_FR_NO_ERROR )
    {
      retVal = E_OK;
      /* FrTrcv237: */
      (void)FrTrcv_30_Tja1082_GetTransceiverMode(FrTrcv_TrcvIdx, &FrTrcv_ActualTrcvMode); /* SBSW_FRTRCV_CALL_GETTRANSCEIVERMODE */
      if (FrTrcv_ActualTrcvMode != FrTrcv_TrcvMode)
      {
# if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
        if (FrTrcv_TrcvMode == FRTRCV_TRCVMODE_NORMAL)
        {
          FrTrcv_30_Tja1082_CallDetReportError( FRTRCV_30_TJA1082_SID_SETTRANSCEIVERMODE, FRTRCV_30_TJA1082_E_FR_TRCV_NOT_NORMAL );
        }
        else
        {
          FrTrcv_30_Tja1082_CallDetReportError( FRTRCV_30_TJA1082_SID_SETTRANSCEIVERMODE, FRTRCV_30_TJA1082_E_FR_TRCV_NOT_STANDBY );
        }
# endif
        retVal = E_NOT_OK;
      }

      /* #70 Perform immediate detection of possible wake up event */
# if ( FRTRCV_30_TJA1082_IMMEDIATE_WAKEUP_CHECK == STD_ON )
      if (FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_WakeupSupported > 0u)
      {
        /* FrTrcv375: */
        FrTrcv_30_Tja1082_CheckWakeupByTransceiver(FrTrcv_TrcvIdx);
      }
# endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRTRCV_30_TJA1082_E_FR_NO_ERROR)
  {
    FrTrcv_30_Tja1082_CallDetReportError(FRTRCV_30_TJA1082_SID_SETTRANSCEIVERMODE, errorId);
  }
#else
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
  /* PRQA S 6030 2 */ /* MD_MSR_STCYC */
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
}

/* FrTrcv324: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTransceiverMode
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTransceiverMode(uint8 FrTrcv_TrcvIdx, P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) FrTrcv_TrcvModePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1082_E_FR_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check parameters and initialization state */
#if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
  if (FrTrcv_30_Tja1082_IsInitialized == FRTRCV_30_TJA1082_UNINIT)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_UNINIT;
  }
  else
  if (FrTrcv_TrcvIdx >= FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
  if (FrTrcv_TrcvModePtr == NULL_PTR)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_TRCV_NULL_PTR;
  }
  else
  if (FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_ChannelUsed == 0u)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    retVal = E_OK;
    /* #20 Get current mode from Trcv */
    if (STD_HIGH == Dio_ReadChannel(FrTrcv_30_Tja1082_Channel[FrTrcv_TrcvIdx].TrcvPinSTBN))
    {
      *FrTrcv_TrcvModePtr = FRTRCV_TRCVMODE_NORMAL;         /* SBSW_FRTRCV_PARAM_TRCVMODE */
    }
    else
    {
      *FrTrcv_TrcvModePtr = FRTRCV_TRCVMODE_STANDBY;        /* SBSW_FRTRCV_PARAM_TRCVMODE */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRTRCV_30_TJA1082_E_FR_NO_ERROR)
  {
    FrTrcv_30_Tja1082_CallDetReportError(FRTRCV_30_TJA1082_SID_GETTRANSCEIVERMODE, errorId);
  }
#else
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
  /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
}

/* FrTrcv325: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTransceiverWUReason
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTransceiverWUReason(uint8 FrTrcv_TrcvIdx, P2VAR(FrTrcv_TrcvWUReasonType, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) FrTrcv_TrcvWUReasonPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1082_E_FR_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check parameters and initialization state */
#if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
  if (FrTrcv_30_Tja1082_IsInitialized == FRTRCV_30_TJA1082_UNINIT)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_UNINIT;
  }
  else
  if (FrTrcv_TrcvIdx >= FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
  if (FrTrcv_TrcvWUReasonPtr == NULL_PTR)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_TRCV_NULL_PTR;
  }
  else
  if (FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_ChannelUsed == 0u)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    retVal = E_OK;
    /* #20 Return last wake up reason, determined in FrTrcv_CheckWakeupEvent */
    *FrTrcv_TrcvWUReasonPtr = FrTrcv_30_Tja1082_TrcvWUReason[FrTrcv_TrcvIdx];       /* SBSW_FRTRCV_PARAM_TRCVWUREASON */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRTRCV_30_TJA1082_E_FR_NO_ERROR)
  {
    FrTrcv_30_Tja1082_CallDetReportError(FRTRCV_30_TJA1082_SID_GETTRANSCEIVERWUREASON, errorId);
  }
#else
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
}

/* FrTrcv329: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_ClearTransceiverWakeup
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_ClearTransceiverWakeup(uint8 FrTrcv_TrcvIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1082_E_FR_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check parameters and initialization state */
#if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
  if (FrTrcv_30_Tja1082_IsInitialized == FRTRCV_30_TJA1082_UNINIT)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_UNINIT;
  }
  else
  if (FrTrcv_TrcvIdx >= FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
  if (FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_ChannelUsed == 0u)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    retVal = E_OK;
    /* #20 Clear wake up state and set initial wake up reason */
    FrTrcv_30_Tja1082_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    FrTrcv_30_Tja1082_WakeupDetected[FrTrcv_TrcvIdx] = 0u;                      /* SBSW_FRTRCV_TRCVIDX */
    FrTrcv_30_Tja1082_TrcvWUReason[FrTrcv_TrcvIdx]   = FRTRCV_WU_RESET;         /* SBSW_FRTRCV_TRCVIDX */
    FrTrcv_30_Tja1082_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRTRCV_30_TJA1082_E_FR_NO_ERROR)
  {
    FrTrcv_30_Tja1082_CallDetReportError(FRTRCV_30_TJA1082_SID_CLEARTRANSCEIVERWAKEUP, errorId);
  }
#else
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
}

/* FrTrcv442: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_DisableTransceiverBranch
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_DisableTransceiverBranch(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx)
{
  /* #10 Empty function due to the fact that the Tja1082 does not have branches */
  /* avoid compiler warning due to unused parameters */
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(FrTrcv_TrcvIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(FrTrcv_BranchIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return (E_NOT_OK);
}

/* FrTrcv443: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_EnableTransceiverBranch
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_EnableTransceiverBranch(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx)
{
  /* #10 Empty function due to the fact that the Tja1082 does not have branches */
  /* avoid compiler warning due to unused parameters */
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(FrTrcv_TrcvIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(FrTrcv_BranchIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return (E_OK);
}

/* FrTrcv419: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTransceiverError
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTransceiverError(uint8 FrTrcv_TrcvIdx, uint8 FrTrcv_BranchIdx, P2VAR(uint32, AUTOMATIC, FRTRCV_30_TJA1082_APPL_DATA) FrTrcv_BusErrorStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = FRTRCV_30_TJA1082_E_FR_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check parameters and initialization state */
#if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
  if (FrTrcv_30_Tja1082_IsInitialized == FRTRCV_30_TJA1082_UNINIT)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_UNINIT;
  }
  else
  if (FrTrcv_TrcvIdx >= FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
  if (FrTrcv_BusErrorStatePtr == NULL_PTR)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_TRCV_NULL_PTR;
  }
  else
  if (FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_ChannelUsed == 0u)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  {
    retVal = E_OK;
    /* #20 Return last transceiver error */
    FrTrcv_30_Tja1082_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    *FrTrcv_BusErrorStatePtr = FrTrcv_30_Tja1082_BusErrorState[FrTrcv_TrcvIdx];     /* SBSW_FRTRCV_PARAM_BUSERRORSTATE */
    FrTrcv_30_Tja1082_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    FRTRCV_30_TJA1082_DUMMY_STATEMENT(FrTrcv_BranchIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRTRCV_30_TJA1082_E_FR_NO_ERROR)
  {
    FrTrcv_30_Tja1082_CallDetReportError(FRTRCV_30_TJA1082_SID_GETTRANSCEIVERERROR, errorId);
  }
#else
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif

  return(retVal);
}

/**********************************************************************************************************************
 *  FrTrcv_30_Tja1082_GetTrcvState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FRTRCV_30_TJA1082_LOCAL_INLINE FUNC(uint8, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_GetTrcvState(uint8 FrTrcv_TrcvIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 trcvState;

  /* ----- Implementation ----------------------------------------------- */
  trcvState = 0;
  /* #10 Read current Trcv state by evaluating STBN and ERRN Pin */
  FrTrcv_30_Tja1082_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if (STD_HIGH == Dio_ReadChannel(FrTrcv_30_Tja1082_Channel[FrTrcv_TrcvIdx].TrcvPinERRN))
  {
    trcvState = 0x01;
  }
  if (STD_HIGH == Dio_ReadChannel(FrTrcv_30_Tja1082_Channel[FrTrcv_TrcvIdx].TrcvPinSTBN))
  {
    trcvState |= 0x02;
  }
  FrTrcv_30_Tja1082_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return (trcvState);
}

/* FrTrcv331: */
/***********************************************************************************************************************
 *  FrTrcv_30_Tja1082_CheckWakeupByTransceiver
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
FUNC(void, FRTRCV_30_TJA1082_CODE) FrTrcv_30_Tja1082_CheckWakeupByTransceiver(uint8 FrTrcv_TrcvIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FRTRCV_30_TJA1082_E_FR_NO_ERROR;
  uint8 trcvState;

  /* ----- Development Error Checks ------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_DETECT == STD_ON)
  if (FrTrcv_TrcvIdx >= FRTRCV_30_TJA1082_MAX_NUM_OF_BTR_BUSSES)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
  if (FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_ChannelUsed == 0u)
  {
    errorId = FRTRCV_30_TJA1082_E_FR_INVALID_TRCVIDX;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If this function is called before the module is initialized, do nothing */
  if (FrTrcv_30_Tja1082_IsInitialized == FRTRCV_30_TJA1082_INIT)
  {
    /* #20 Otherwise: Perform wake up or bus error diagnosis check if enabled */
    
    /* #30 Read current Trcv state */
    trcvState = FrTrcv_30_Tja1082_GetTrcvState(FrTrcv_TrcvIdx);
    /* #40 Evaluate Trcv state and check whether wake up or error condition happened */
    switch (trcvState)
    {
      case 0x00: /* ERRN lo, STBN lo */
        { /* wakeup detected */
          FrTrcv_30_Tja1082_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
          FrTrcv_30_Tja1082_TrcvWUReason[FrTrcv_TrcvIdx]   = FRTRCV_WU_BY_BUS;              /* SBSW_FRTRCV_TRCVIDX */
          FrTrcv_30_Tja1082_WakeupDetected[FrTrcv_TrcvIdx] = 1u;                            /* SBSW_FRTRCV_TRCVIDX */
          FrTrcv_30_Tja1082_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        } break;
      case 0x01: /* ERRN hi, STBN lo */
        { /* no event */
        } break;
      case 0x02: /* ERRN lo, STBN hi */
        { /* Error condition detected */
          FrTrcv_30_Tja1082_BusErrorState[FrTrcv_TrcvIdx] = FRTRCV_30_TJA1082_BDE_GLOBAL_ERROR | FRTRCV_30_TJA1082_BDE_GENERAL_FAULT; /* SBSW_FRTRCV_TRCVIDX */
          FrTrcv_DemReportErrorPreFailed(FrTrcv_30_Tja1082_DEM_E_Fr_Error_Channel[FrTrcv_TrcvIdx]);
        } break;
      case 0x03: /* ERRN hi, STBN hi */
        { /* Error condition cleared */
          FrTrcv_30_Tja1082_BusErrorState[FrTrcv_TrcvIdx] = FRTRCV_30_TJA1082_ERROR_NONE;   /* SBSW_FRTRCV_TRCVIDX */
          FrTrcv_DemReportErrorPrePassed(FrTrcv_30_Tja1082_DEM_E_Fr_Error_Channel[FrTrcv_TrcvIdx]);
        } break;
    } /* PRQA S 2002 */ /* MD_FRTRCV_2002 */

    /* FrTrcv369: */
    if ( (1u == FrTrcv_30_Tja1082_WakeupDetected[FrTrcv_TrcvIdx])
      && (1u == FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_WakeupSupported) )
    { /* #50 If wakeup callbacks enabled inform EcuM */
      FrTrcv_30_Tja1082_WakeupDetected[FrTrcv_TrcvIdx] = 0u;                                /* SBSW_FRTRCV_TRCVIDX */
      EcuM_SetWakeupEvent(FrTrcv_30_Tja1082_Config[FrTrcv_TrcvIdx].FrTrcv_WakeupSourceRef);
    }
  }
  else
  {
    /* concluding else */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (FRTRCV_30_TJA1082_DEV_ERROR_REPORT == STD_ON)
  if (errorId != FRTRCV_30_TJA1082_E_FR_NO_ERROR)
  {
    FrTrcv_30_Tja1082_CallDetReportError(FRTRCV_30_TJA1082_SID_CHECKWAKEUPBYTRANSCEIVER, errorId);
  }
#else
  FRTRCV_30_TJA1082_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
#endif
  /* PRQA S 6010 2 */ /* MD_MSR_STPTH */
  /* PRQA S 6030 1 */ /* MD_MSR_STCYC */
}

#define FRTRCV_30_TJA1082_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ /* lint -e{451} */

/* module specific MISRA deviations:
  MD_FRTRCV_2002: Rule 15.3
      Reason:     Default path can never be reached due to the fact that the input value is set to only
                  the values checked in the switch/case.
      Risk:       No Risk.
      Prevention: Covered by code review.
  MD_FRTRCV_3408: Rule 8.8
      Reason:     Make variables available for debugging
      Risk:       No Risk.
      Prevention: Covered by code review.
  MD_FRTRCV_3448: Rule 5.3
      Reason:     The type is only used internally.
      Risk:       No Risk.
      Prevention: Covered by code review.
*/

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_FRTRCV_PARAM_TRCVMODE
  \DESCRIPTION    The function FrTrcv_30_Tja1082_GetTransceiverMode writes to the 'FrTrcv_TrcvModePtr' pointer parameter.
                  Only a single definition value is written. The calling module must provide a valid pointer.
  \COUNTERMEASURE \N The calling function is a vector function and provides a valid pointer.

  \ID SBSW_FRTRCV_PARAM_TRCVWUREASON
  \DESCRIPTION    The function FrTrcv_30_Tja1082_GetTransceiverWUReason writes to the 'FrTrcv_TrcvWUReasonPtr' pointer parameter.
                  Only a single definition value is written. The calling module must provide a valid pointer.
  \COUNTERMEASURE \N The calling function is a vector function and provides a valid pointer.

  \ID SBSW_FRTRCV_PARAM_BUSERRORSTATE
  \DESCRIPTION    The function FrTrcv_30_Tja1082_GetTransceiverError writes to the 'FrTrcv_BusErrorStatePtr' pointer parameter.
                  Only a single definition value is written. The calling module must provide a valid pointer.
  \COUNTERMEASURE \N The calling function is a vector function and provides a valid pointer.

  \ID SBSW_FRTRCV_TRCVIDX
  \DESCRIPTION Array write access; access might exceed array bounds. Correct index is expected.
  \COUNTERMEASURE \M Array index is checked against definition size by DET check [SBSW_CM_FRTRCV_CONFIGPARAMETER_CHECK]

  \ID SBSW_FRTRCV_TRCVIDXLOOPCONDITION
  \DESCRIPTION Array write access; access might exceed array bounds. Index must be within bounds.
  \COUNTERMEASURE \N The definition of the accessed arrays has the same size as the for loop condition (same define).
                     No countermeasure required.

  \ID SBSW_FRTRCV_PARAM_GETVERSION
  \DESCRIPTION    The FrTrcv_GetVersionInfo writes to the 'versioninfo' pointer parameter. It is checked against NULL,
                  but this does not guarantee that the referenced memory is valid. The calling module must provide a valid pointer.
  \COUNTERMEASURE \S Add constraint to the safety manual. [SBSW_CM_FRTRCV_API_POINTER]

  \ID SBSW_FRTRCV_CALL_GETTRANSCEIVERMODE
  \DESCRIPTION    The function FrTrcv_30_Tja1082_GetTransceiverMode is called with two parameters, an FrTrcv_TrcvIdx and a
                  pointer FrTrcv_ActualTrcvMode
                  - The FrTrcv_TrcvIdx is checked in the calling function by DET check against the size of the array definition.
                  - The FrTrcv_TrcvIdx is not used for write access in the called function.
                  - The pointer is a reference to a locally defined variable of the same type.
  \COUNTERMEASURE \M DET must be enabled. [SBSW_CM_FRTRCV_CONFIGPARAMETER_CHECK]

  \ID SBSW_CM_FRTRCV_CONFIGPARAMETER_CHECK
  \DESCRIPTION    Verify configuration parameters to be enabled.
  \COUNTERMEASURE \M The switch FRTRCV_30_TJA1082_DEV_ERROR_DETECT must be enabled.

  \ID SBSW_CM_FRTRCV_API_POINTER
  \DESCRIPTION    Pointers passed to FRTRCV API must point to a valid memory range.
  \COUNTERMEASURE \N Caller ensures valid pointers [SMI-16].

SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: FrTrcv_30_Tja1082.c
 *********************************************************************************************************************/
