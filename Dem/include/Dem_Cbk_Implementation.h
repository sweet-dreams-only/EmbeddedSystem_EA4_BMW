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
/*! \addtogroup Dem_Cbk
 *  \{
 *  \file       Dem_Cbk_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    
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

#if !defined (DEM_CBK_IMPLEMENTATION_H)
#define DEM_CBK_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Cbk_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_CONST_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Cbk_Properties
 * \{
 */

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
 * \addtogroup Dem_Cbk_Private
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Cbk_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Cbk_DtcStatusChanged
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_DtcStatusChanged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusOld,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusNew,
  CONST(uint8, AUTOMATIC)  NotificationReason
  )
{
  Dem_Cbk_DtcStatusChanged_Internal(
    EventId,
    Dem_DTC_ApplyExternalOnlyStatus(EventId, EventUdsStatusOld),
    Dem_DTC_ApplyExternalOnlyStatus(EventId, EventUdsStatusNew),
    NotificationReason
  );
}

/* ****************************************************************************
 % Dem_Cbk_EventDataChanged
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_EventDataChanged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  if (Dem_Cfg_EventCbkData(EventId) != NULL_PTR)
  {
    (void)(*Dem_Cfg_EventCbkData(EventId))();                                                                                    /* SBSW_DEM_EVENTCBKDATA_FPTR */
  }
  if (Dem_Cfg_GlobalCbkData() != NULL_PTR)
  {
    (void)(*Dem_Cfg_GlobalCbkData())(EventId);                                                                                   /* SBSW_DEM_GLOBALCBKEVENTDATA_FPTR */
  }
}

/* ****************************************************************************
 % Dem_Cbk_InitMonitorForEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_InitMonitorForEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_InitMonitorReasonType, AUTOMATIC)  InitReason
  )
{
  Dem_InitMonitorForEventFPtrType lpInitMonitorForEventFunc;

  lpInitMonitorForEventFunc = Dem_Cfg_EventCbkInitMonitor(EventId);

  if (lpInitMonitorForEventFunc != NULL_PTR)
  {
    (void)(*lpInitMonitorForEventFunc)(InitReason);                                                                              /* SBSW_DEM_INITMONITORFOREVENT_FPTR */
  }
}

/* ****************************************************************************
 % Dem_Cbk_InitMonitorForFunction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Cbk_InitMonitorForFunction(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Cfg_EventCbkInitFuncIterType lIter;

  for (Dem_Cfg_EventCbkInitFuncIterInit(EventId, &lIter);                                                                        /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
       Dem_Cfg_EventCbkInitFuncIterExists(&lIter) == TRUE;                                                                       /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
       Dem_Cfg_EventCbkInitFuncIterNext(&lIter))                                                                                 /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
  {
    Dem_InitMonitorForFuncFPtrType lpInitMonitorForFuncFunc;

    lpInitMonitorForFuncFunc = Dem_Cfg_EventCbkInitFuncIterGet(&lIter);                                                          /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
    if (lpInitMonitorForFuncFunc != NULL_PTR)
    {
      (void)(lpInitMonitorForFuncFunc());                                                                                        /* SBSW_DEM_INITMONITORFORFUNCTION_FPTR */
    }
  }
}

#if (DEM_CFG_NOTIFY_CLEAR_ALLOWED == STD_ON)
/* ****************************************************************************
 % Dem_Util_CallClearEventAllowed
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Util_CallClearEventAllowed(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  boolean lClearAllowed;
  Dem_ClearEventAllowedFPtrType lpClearAllowedFunc;

  lClearAllowed = TRUE;
  lpClearAllowedFunc = Dem_Cfg_EventCbkClearAllowed(EventId);
  if (lpClearAllowedFunc != NULL_PTR)
  {
    if ((*lpClearAllowedFunc)(&lClearAllowed) != E_OK)                                                                           /* SBSW_DEM_CLEARALLOWED_FPTR */
    { /* Make sure a failed call does not influence lDoClear */
      lClearAllowed = TRUE;
    }
  }
  return lClearAllowed;
}
#endif

/* ****************************************************************************
 % Dem_Cbk_DtcStatusChanged_Internal
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
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Cbk_DtcStatusChanged_Internal(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  DtcStatusOld,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  DtcStatusNew,
  CONST(uint8, AUTOMATIC)  NotificationReason                                                                                    /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(NotificationReason)                                                                           /* PRQA S 3112 */ /* MD_DEM_14.2 */

  if (Dem_DTC_TestDtcSuppressed(EventId) == FALSE)
  {
    uint8 lDtcStatusOld;
    uint8 lDtcStatusNew;

    lDtcStatusOld = (uint8)(DtcStatusOld & Dem_Cfg_GlobalStatusMask());
    lDtcStatusNew = (uint8)(DtcStatusNew & Dem_Cfg_GlobalStatusMask());

    if ((lDtcStatusOld ^ lDtcStatusNew) != 0)
    { /* DTC Status has changed */
      uint32 lUdsDtc;

      lUdsDtc = Dem_Cfg_EventUdsDtc(EventId);

      if (lUdsDtc != DEM_CFG_DTC_UDS_INVALID)
      {
        Dem_Cfg_GlobalCbkDtcIterType lIter;
        for (Dem_Cfg_GlobalCbkDtcIterInit(&lIter);                                                                               /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
             Dem_Cfg_GlobalCbkDtcIterExists(&lIter) == TRUE;                                                                     /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
             Dem_Cfg_GlobalCbkDtcIterNext(&lIter))                                                                               /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
        {
          Dem_DtcStatusChangedFPtrType lpDtcStatusFunc;
          lpDtcStatusFunc = Dem_Cfg_GlobalCbkDtcIterGet(&lIter);                                                                 /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
          if (lpDtcStatusFunc != NULL_PTR)
          {
            (void)lpDtcStatusFunc(lUdsDtc, lDtcStatusOld, lDtcStatusNew);                                                        /* SBSW_DEM_GLOBALCBKDTCSTATUS_FPTR */
          }
        }

#if (DEM_CFG_NOTIFY_DCM == STD_ON)
        if (NotificationReason != DEM_CBK_DTC_CLEAR)
        {
          /* Call Dcm Dtc status change callback */
          (void)Dcm_DemTriggerOnDTCStatus(lUdsDtc, lDtcStatusOld, lDtcStatusNew);
        }
#endif
      } /* if (DEM_CFG_DTC_UDS_INVALID != lUdsDtc) */

    } /* if DTC Status has changed */
  } /* if DTC is not suppressed */
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Cbk_StatusChanged
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Cbk_StatusChanged(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusOld,
  CONST(Dem_UdsStatusByteType, AUTOMATIC)  EventUdsStatusNew
  )
{
#if (DEM_CFG_NOTIFY_FIM == STD_ON)
  /* Call FiM event status change callback */
  (void)FiM_DemTriggerOnEventStatus(EventId, EventUdsStatusOld, EventUdsStatusNew);
#endif

#if (DEM_CFG_NOTIFY_DLT == STD_ON)
  /* Call Dlt event status change callback */
  Dlt_DemTriggerOnEventStatus(EventId, EventUdsStatusOld, EventUdsStatusNew);
#endif

  {
    Dem_Cfg_EventCbkStatusIterType lIter;
    /* Call all configured status change callbacks for this event */
    for (Dem_Cfg_EventCbkStatusIterInit(EventId, &lIter);                                                                        /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
         Dem_Cfg_EventCbkStatusIterExists(&lIter) == TRUE;                                                                       /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
         Dem_Cfg_EventCbkStatusIterNext(&lIter))                                                                                 /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
    {
      Dem_EventStatusChangedFPtrType lpEventCbkStatusFunc;
      lpEventCbkStatusFunc = Dem_Cfg_EventCbkStatusIterGet(&lIter);                                                              /* SBSW_DEM_CALL_FUNCPTR_ITERATOR_POINTER */
      if (lpEventCbkStatusFunc != NULL_PTR)
      {
        (void)(lpEventCbkStatusFunc(EventUdsStatusOld, EventUdsStatusNew));                                                      /* SBSW_DEM_EVENTCBKSTATUS_FPTR */
      }
    }
  }

  /* Call general event status changed callback */
  if (Dem_Cfg_GlobalCbkStatus() != NULL_PTR)
  {
    (void)(Dem_Cfg_GlobalCbkStatus()(EventId, EventUdsStatusOld, EventUdsStatusNew));                                            /* SBSW_DEM_GLOBALCBKEVENTSTATUS_FPTR */
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_CBK_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Cbk_Implementation.h
 *********************************************************************************************************************/
