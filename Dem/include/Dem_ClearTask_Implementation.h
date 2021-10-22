/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*! \addtogroup Dem_ClearTask
 *  \{
 *  \file       Dem_ClearTask_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of ClearTask subcomponent
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vctr Informatik GmbH
 *  Anna Bosch                    visanh        Vctr Informatik GmbH
 *  Stefan Huebner                vishrs        Vctr Informatik GmbH
 *  Thomas Dedler                 visdth        Vctr Informatik GmbH
 *  Alexander Ditte               visade        Vctr Informatik GmbH
 *  Matthias Heil                 vismhe        Vctr Informatik GmbH
 *  Erik Jeglorz                  visejz        Vctr Informatik GmbH
 *  Friederike Schulze            visfrs        Vctr Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vctr Informatik GmbH
 *  Fabian Wild                   viszfa        Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_CLEARTASK_IMPLEMENTATION_H)
#define DEM_CLEARTASK_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_ClearTask_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Scheduler_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_Nvm_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_ClearDTC_Interface.h"
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! State of clear requests */
DEM_LOCAL volatile VAR(uint8, DEM_VAR_NOINIT)    Dem_ClearTask_ClearState;
/*! Flag to indicate write errors during clear */
DEM_LOCAL VAR(boolean, DEM_VAR_NOINIT)           Dem_ClearTask_ClearWriteErrors;                                                 /* PRQA S 3218 */ /* MD_DEM_8.7 */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (DEM_CFG_SUPPORT_CLEAR_DTC_RUNTIME_LIMIT == STD_ON)
/*! Run-time limitation state for clear requests */
DEM_LOCAL VAR(uint16, DEM_VAR_NOINIT)            Dem_ClearTask_ClearEventIterator;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! ClearRequest data */
DEM_LOCAL VAR(Dem_ClearTask_ClearRequestType, DEM_VAR_NOINIT)  Dem_ClearTask_ClearRequest;

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PROPERTY FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
* \addtogroup Dem_ClearTask_Properties
* \{
*/

/* ****************************************************************************
 % Dem_ClearTask_GetClearClient()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE) 
Dem_ClearTask_GetClearClient(
  void
  )
{
  return Dem_ClearTask_ClearRequest.ClearClient;
}

/*!
* \}
*/
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
* \addtogroup Dem_ClearTask_Private
* \{
*/

/* ****************************************************************************
 % Dem_ClearTask_GetClearMemoryId()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE) 
Dem_ClearTask_GetClearMemoryId(
  void
  )
{
  return Dem_ClearTask_ClearRequest.ClearMemoryId;
}

/* ****************************************************************************
 % Dem_ClearTask_SetClearMemory()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearTask_SetClearMemory(                                                                                                    /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(uint8, AUTOMATIC) MemoryId
  )
{
  Dem_ClearTask_ClearRequest.ClearMemoryId = MemoryId;
}

/* ****************************************************************************
 % Dem_ClearTask_GetClearGroup()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE) 
Dem_ClearTask_GetClearGroup(
  void
  )
{
  return Dem_ClearTask_ClearRequest.ClearGroup;
}

/* ****************************************************************************
 % Dem_ClearTask_GetClearEvent()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE) 
Dem_ClearTask_GetClearEvent(
  void
  )
{
  return Dem_ClearTask_ClearRequest.ClearEventId;
}

/* ****************************************************************************
 % Dem_ClearTask_SetClearEvent()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearTask_SetClearEvent(                                                                                                     /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(Dem_EventIdType, AUTOMATIC) EventId
  )
{
  Dem_ClearTask_ClearRequest.ClearEventId = EventId;
}

/* ****************************************************************************
 % Dem_ClearTask_GetClearCode()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE) 
Dem_ClearTask_GetClearCode(                                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
  )
{
  return Dem_ClearTask_ClearRequest.ClearCode;
}

/* ****************************************************************************
 % Dem_ClearTask_GetClearMask()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE) 
Dem_ClearTask_GetClearMask(                                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
  )
{
  return Dem_ClearTask_ClearRequest.ClearMask;
}

/* ****************************************************************************
 % Dem_ClearTask_GetClearNodeIndex()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE) 
Dem_ClearTask_GetClearNodeIndex(                                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
  )
{
  return Dem_ClearTask_ClearRequest.ClearNode;
}

# if (DEM_CFG_CLEAR_NV_END_RESPONSE == STD_ON)
/* ****************************************************************************
 % Dem_ClearTask_TestClearWriteErrors()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE) 
Dem_ClearTask_TestClearWriteErrors(                                                                                              /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
  )
{
  return Dem_ClearTask_ClearWriteErrors;
}
#endif

# if (DEM_CFG_CLEAR_NV_END_RESPONSE == STD_ON)
/* ****************************************************************************
 % Dem_ClearTask_SetClearWriteErrors()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearTask_SetClearWriteErrors(                                                                                               /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
  )
{
  Dem_ClearTask_ClearWriteErrors = TRUE;
}
#endif

/* ****************************************************************************
 % Dem_ClearTask_ResetClearWriteErrors()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearTask_ResetClearWriteErrors(                                                                                             /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
  )
{
  Dem_ClearTask_ClearWriteErrors = FALSE;
}

/* ****************************************************************************
 % Dem_ClearTask_GetClearState()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE) 
Dem_ClearTask_GetClearState(                                                                                                     /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  void
  )
{
  return Dem_ClearTask_ClearState;
}

/* ****************************************************************************
 % Dem_ClearTask_SetClearState()
 *****************************************************************************/
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
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearTask_SetClearState(
  CONST(uint8, AUTOMATIC) State
  )
{
  switch (State)
  {
  case DEM_CLEARTASK_IDLE:
    Dem_ClearTask_ResetClearWriteErrors();
    Dem_Scheduler_DisableTask(Dem_Scheduler_Task_ClearTask);
    break;

  case DEM_CLEARTASK_NEW:
    Dem_Scheduler_EnableTask(Dem_Scheduler_Task_ClearTask);
    break;

  default:
    break;
  }

  Dem_ClearDTC_NotifyClearResult(State);
  Dem_ClearTask_ClearState = (State);
}

/* ****************************************************************************
 % Dem_ClearTask_ProcessClearSingleDtc
 *****************************************************************************/
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
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_ClearTask_ProcessClearSingleDtc(
  void
  )
{
  boolean lReturnValue;

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Dem_ClearTask_GetClearMemoryId() != Dem_Cfg_EventDestination(Dem_ClearTask_GetClearEvent()))
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
#endif
  
  lReturnValue = Dem_DTC_Cleared(Dem_ClearTask_GetClearEvent());
  
#if (DEM_CFG_NOTIFY_CLEAR_ALLOWED == STD_ON)
  if (lReturnValue == FALSE)
  {
    Dem_ClearTask_SetClearState(DEM_CLEARTASK_FAILED);
  }
#endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_ClearTask_ProcessClearDtcGroup
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_ClearTask_ProcessClearDtcGroup(
  CONST(uint16, AUTOMATIC)  FirstEventId,
  CONST(uint16, AUTOMATIC)  LastEventId
  )
{
  if (FirstEventId != DEM_EVENT_INVALID)
  {
    uint8 lGroupMask;
    uint16 lEventIterator;

    lGroupMask = Dem_ClearTask_GetClearGroup();
    lEventIterator = LastEventId;

    while (FirstEventId <= lEventIterator)
    { /* Event must match the group */
      if (( (lGroupMask == DEM_CFG_GROUPMASK_ALLDTCS)                                                                           /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
#if (DEM_CFG_CLEAR_GROUP_DTCS == STD_ON)
          || ((Dem_Cfg_EventGroupMask(lEventIterator) & lGroupMask) != 0)
#endif
          )
      /* Do not test for suppression: suppressed DTCs are not exempt from ClearGroupOfDTC */
        && (Dem_DTC_TestDtcAvailableInVariant(lEventIterator) == TRUE)
        && (Dem_EventInternalStatus_TestEventDisconnected(Dem_DTC_GetInternalStatus(lEventIterator)) == FALSE)
        )

      { /* For combined events, only clear each event once */
#if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
        if (lEventIterator == Dem_Cfg_GetMasterEvent(lEventIterator))
#endif
        {
          (void)Dem_DTC_Cleared(lEventIterator);
        }
      }
      --lEventIterator;
    }
  }
}

#if (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON)                                                                                  /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_ClearTask_ProcessClearJ1939Dtc
 *****************************************************************************/
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
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_ClearTask_ProcessClearJ1939Dtc(
  CONST(uint16, AUTOMATIC)  FirstEventId,
  CONST(uint16, AUTOMATIC)  LastEventId
  )
{
  if (FirstEventId != DEM_EVENT_INVALID)
  {
    uint16 lEventIterator;

    for (lEventIterator = LastEventId;
         FirstEventId <= lEventIterator;
         --lEventIterator)
    { /* Event must be a J1939 related and match the ClearCode */
      if (Dem_Cfg_EventJ1939Dtc(lEventIterator) == DEM_CFG_DTC_J1939_INVALID)
      { /* only match events that support J1939 */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# if (DEM_CFG_ISCONST_AVAILABLEINVARIANT != STD_ON)
      if (Dem_DTC_TestDtcAvailableInVariant(lEventIterator) == FALSE)
      {
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# endif
      if (Dem_EventInternalStatus_TestEventDisconnected(Dem_DTC_GetInternalStatus(lEventIterator)) == TRUE)
      { /* Event must be connected */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
      if (lEventIterator != Dem_Cfg_GetMasterEvent(lEventIterator))
      { /* do not match depentend combined events */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# endif
      if ((Dem_DTC_GetDTCStatus(lEventIterator) & (Dem_ClearTask_GetClearMask())) != Dem_ClearTask_GetClearCode())
      { /* DTC status needs to match the request */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
      {
        Dem_Cfg_EventJ1939NodeIterType lNodeIter;

        for (Dem_Cfg_EventJ1939NodeIterInit(lEventIterator, &lNodeIter);                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == TRUE;                                                               /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_EventJ1939NodeIterNext(&lNodeIter))                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          if (Dem_ClearTask_GetClearNodeIndex() == Dem_Cfg_EventJ1939NodeIterGet(&lNodeIter))                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
          {
            break;
          }
        }
        if (Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == FALSE)
        { /* clear event only if it is linked to the requested node */
          continue;                                                                                                              /* PRQA S 0770 */ /* MD_DEM_14.5 */
        }
      }
# endif

      (void)Dem_DTC_Cleared(lEventIterator);
    }
  }
}                                                                                                                                /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON) */

/* ****************************************************************************
 % Dem_ClearTask_ProcessClearDtc
 *****************************************************************************/
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
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ClearTask_ProcessClearDtc(
  void
  )
{
  Dem_Mem_MemoryInfoPtrType lMemoryInfo;
#if (DEM_CFG_SUPPORT_CLEAR_DTC_RUNTIME_LIMIT == STD_ON)
  uint16 lEventLowerLimit;
#endif
  boolean lClearSuccess;

  lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_ClearTask_GetClearMemoryId());

  if (Dem_ClearTask_GetClearEvent() != DEM_EVENT_INVALID)
  { /* Clear single event */
    lClearSuccess = Dem_ClearTask_ProcessClearSingleDtc();
  }
  else
  { /* Clear group of events */
#if (DEM_CFG_SUPPORT_CLEAR_DTC_RUNTIME_LIMIT == STD_ON)
    if (Dem_ClearTask_ClearEventIterator == DEM_EVENT_INVALID)
    { /* Not yet started */
      Dem_ClearTask_ClearEventIterator = Dem_MemStorageManager_MemoryGetLastEvent(lMemoryInfo);                                  /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

# if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON)                                    /* COV_MSR_UNSUPPORTED XF xf xf */
      if (Dem_ClearTask_GetClearGroup() == DEM_CFG_GROUPMASK_ALLDTCS)
      {
        Dem_Esm_PreOnClear_AllDtc(Dem_ClearTask_GetClearMemoryId());
      }
# endif
    }

    if (Dem_ClearTask_ClearEventIterator < Dem_Cfg_GlobalClearDtcRuntimeLimit())
    { /* At most delete all events to prevent overflow */
      lEventLowerLimit = (uint16)(Dem_MemStorageManager_MemoryGetFirstEvent(lMemoryInfo) - 1);                                   /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    }
    else
    {
      lEventLowerLimit = (uint16)(Dem_ClearTask_ClearEventIterator - Dem_Cfg_GlobalClearDtcRuntimeLimit());
# if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
      if (lEventLowerLimit < Dem_MemStorageManager_MemoryGetFirstEvent(lMemoryInfo))                                             /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
      {
        lEventLowerLimit = (uint16)(Dem_MemStorageManager_MemoryGetFirstEvent(lMemoryInfo) - 1);                                 /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
      }
# endif
    }

# if (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED XF */
    if (Dem_ClearTask_GetClearClient() == DemConf_DemClient_DemClient_J1939)
    {
      /* Attention: lEventLowerLimit is numerically smaller than current iterator */
      Dem_ClearTask_ProcessClearJ1939Dtc(lEventLowerLimit + 1, Dem_ClearTask_ClearEventIterator);
    }
    else
# endif
    {
      /* Attention: lEventLowerLimit is numerically smaller than current iterator */
      Dem_ClearTask_ProcessClearDtcGroup(lEventLowerLimit + 1, Dem_ClearTask_ClearEventIterator);
    }
    Dem_ClearTask_ClearEventIterator = lEventLowerLimit;
#else
# if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON)                                    /* COV_MSR_UNSUPPORTED XF xf xf */
    if (Dem_ClearTask_GetClearGroup() == DEM_CFG_GROUPMASK_ALLDTCS)
    {
      Dem_Esm_PreOnClear_AllDtc(Dem_ClearTask_GetClearMemoryId());
    }
# endif
# if (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED XF */
    if (Dem_ClearTask_GetClearClient() == DemConf_DemClient_DemClient_J1939)
    {
      /* Attention: lEventLowerLimit is numerically smaller than current iterator */
      Dem_ClearTask_ProcessClearJ1939Dtc(Dem_MemStorageManager_MemoryGetFirstEvent(lMemoryInfo), Dem_MemStorageManager_MemoryGetLastEvent(lMemoryInfo));     /* SBSW_DEM_CALL_MEMORYINFO_POINTER */ /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    }
    else
# endif
    {
      /* Attention: lEventLowerLimit is numerically smaller than current iterator */
      Dem_ClearTask_ProcessClearDtcGroup(Dem_MemStorageManager_MemoryGetFirstEvent(lMemoryInfo), Dem_MemStorageManager_MemoryGetLastEvent(lMemoryInfo));     /* SBSW_DEM_CALL_MEMORYINFO_POINTER */ /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    }
#endif
#if (DEM_CFG_SUPPORT_CLEAR_DTC_RUNTIME_LIMIT == STD_ON)
    if (Dem_ClearTask_ClearEventIterator >= Dem_MemStorageManager_MemoryGetFirstEvent(lMemoryInfo))                              /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    {
      lClearSuccess = FALSE;
    }
    else
#endif
    {
      lClearSuccess = TRUE;
    }
  } /* Clear group of events */

  if (lClearSuccess == TRUE)
  {
#if (DEM_CFG_SUPPORT_CLEAR_DTC_RUNTIME_LIMIT== STD_ON)
    Dem_ClearTask_ClearEventIterator = DEM_EVENT_INVALID;
#endif

#if (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON)                                                                                  /* COV_MSR_UNSUPPORTED XF */
    if (Dem_ClearTask_GetClearClient() != DemConf_DemClient_DemClient_J1939)
#endif
    {
      if (Dem_ClearTask_GetClearGroup() == DEM_CFG_GROUPMASK_ALLDTCS)
      {
        Dem_Esm_PostOnClear_AllDtc(Dem_ClearTask_GetClearMemoryId());
      }
    }
    Dem_Esm_PostOnClear_Always(Dem_ClearTask_GetClearMemoryId());

# if (DEM_CFG_USE_NVM == STD_ON) && (DEM_CFG_CLEAR_NV_END_RESPONSE == STD_ON)
    Dem_ClearTask_SetClearState(DEM_CLEARTASK_NV_INPROGRESS);
# else
    Dem_ClearTask_SetClearState(DEM_CLEARTASK_DONE);
# endif
    Dem_Nvm_SetBlockState(DEM_NVM_BLOCKTYPE_STATUS, DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);
  }
}                                                                                                                                /* PRQA S 6010, 6050, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STCYC, MD_MSR_STMIF */

/*!
* \}
*/
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PUBLIC FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
* \addtogroup Dem_ClearTask_Public
* \{
*/

/* ****************************************************************************
 % Dem_ClearTask_Init()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ClearTask_Init(
  void
  )
{
  Dem_ClearTask_SetClearState(DEM_CLEARTASK_IDLE);
#if (DEM_CFG_SUPPORT_CLEAR_DTC_RUNTIME_LIMIT == STD_ON)
  Dem_ClearTask_ClearEventIterator = DEM_EVENT_INVALID;
#endif
}

/* ****************************************************************************
 * Dem_ClearTask_MainFunction()
 *****************************************************************************/
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
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ClearTask_MainFunction(
  void
  )
{
  switch (Dem_ClearTask_GetClearState())
  {
  case DEM_CLEARTASK_NEW:
    Dem_ClearTask_SetClearState(DEM_CLEARTASK_INPROGRESS);
    /* FALL THROUGH */
  case DEM_CLEARTASK_INPROGRESS:                                                                                                 /* PRQA S 2003 */ /* MD_DEM_15.2 */
    Dem_ClearTask_ProcessClearDtc();
    if (Dem_ClearTask_GetClearState() == DEM_CLEARTASK_DONE)
    {
      Dem_ClearTask_SetClearState(DEM_CLEARTASK_IDLE);
    }
    break;
  
  case DEM_CLEARTASK_DONE:
  case DEM_CLEARTASK_FAILED:
  case DEM_CLEARTASK_NVERROR:
    Dem_ClearTask_SetClearState(DEM_CLEARTASK_IDLE);
    break;

  default:
    /* nothing to do */
    break;
  }
}

/* ****************************************************************************
 % Dem_ClearTask_TryNewClear()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_ClearTask_TryNewClear(
  CONST(Dem_ClearTask_ClearRequestConstPtrType, AUTOMATIC)  ClearRequest
  )
{
  boolean lReturnValue;

  if (Dem_ClearTask_GetClearState() == DEM_CLEARTASK_IDLE)
  {
/* >>>> -------------------------------- Enter Critical Section: DcmApi */
    Dem_EnterCritical_DcmApi();                                                                                                  /* PRQA S 3109 */ /* MD_MSR_14.3 */

    if (Dem_ClearTask_GetClearState() == DEM_CLEARTASK_IDLE)
    {
      Dem_ClearTask_ClearRequest = *ClearRequest;
      Dem_ClearTask_SetClearState(DEM_CLEARTASK_NEW);
      lReturnValue = TRUE;
    }
    else
    {
      lReturnValue = FALSE;
    }
    Dem_LeaveCritical_DcmApi();                                                                                                  /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DcmApi */
  }
  else
  {
    lReturnValue = FALSE;
  }

  return lReturnValue;
}

# if (DEM_CFG_USE_NVM == STD_ON) && (DEM_CFG_CLEAR_NV_END_RESPONSE == STD_ON)
/* ****************************************************************************
 % Dem_ClearTask_NotifyClearCompleted()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ClearTask_NotifyClearCompleted(
  void
  )
{
  if (Dem_ClearTask_GetClearState() == DEM_CLEARTASK_NV_INPROGRESS)
  {
    if (Dem_ClearTask_TestClearWriteErrors() == TRUE)
    {
      Dem_ClearTask_SetClearState(DEM_CLEARTASK_NVERROR);
    }
    else
    {
      Dem_ClearTask_SetClearState(DEM_CLEARTASK_DONE);
    }
  }
}
#endif

# if (DEM_CFG_USE_NVM == STD_ON) && (DEM_CFG_CLEAR_NV_END_RESPONSE == STD_ON)
/* ****************************************************************************
 % Dem_ClearTask_NotifyClearWriteError()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ClearTask_NotifyClearWriteError(
  void
  )
{
  Dem_ClearTask_SetClearWriteErrors();
}
#endif

/*!
* \}
*/
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_CLEARTASK_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ClearTask_Implementation.h
 *********************************************************************************************************************/
