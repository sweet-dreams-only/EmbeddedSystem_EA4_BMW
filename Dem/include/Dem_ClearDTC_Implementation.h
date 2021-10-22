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
/*! \addtogroup Dem_ClearDTC
 *  \{
 *  \file       Dem_ClearDTC_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of ClearDTC subcomponent
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

#if !defined (DEM_CLEARDTC_IMPLEMENTATION_H)
#define DEM_CLEARDTC_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_ClearDTC_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_ClearTask_Implementation.h"
#include "Dem_DTCSelector_Implementation.h"
#include "Dem_DTC_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */

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

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_ClearDTC_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_ClearDTC_GetClearStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_ClearDTC_StatusType, DEM_CODE) 
Dem_ClearDTC_GetClearStatus(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle
  )
{
  return Dem_Cfg_GetClearDTCTable(ClearDTCHandle).ClearDTCStatus;
}

/* ****************************************************************************
 % Dem_ClearDTC_TestClearWwhObdAllDTCsAllowed()
*****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE) 
Dem_ClearDTC_TestClearWwhObdAllDTCsAllowed(
  void
  )
{
#if (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) || (DEM_CFG_CLEAR_WWHOBD_GROUP_DTCS == STD_OFF)
  return FALSE;
#else   
  return TRUE;
#endif
}

/* ****************************************************************************
 % Dem_ClearDTC_TestClearObdAllDTCsAllowed()
*****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE) 
Dem_ClearDTC_TestClearObdAllDTCsAllowed(
  void
  )
{
#if (DEM_CFG_SUPPORT_OBDII == STD_OFF) || (DEM_CFG_CLEAR_OBDII_GROUP_DTCS == STD_OFF)
  return FALSE;
#else   
  return TRUE;
#endif
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
 * \addtogroup Dem_ClearDTC_Private
 * \{
 */

/* ****************************************************************************
 % Dem_ClearDTC_SetClearStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearDTC_SetClearStatus(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle,
  CONST(Dem_ClearDTC_StatusType, AUTOMATIC)  ClearDTCStatus
  )
{
  Dem_Cfg_GetClearDTCTable(ClearDTCHandle).ClearDTCStatus = ClearDTCStatus;
}

/* ****************************************************************************
 % Dem_ClearDTC_GetClearSelector()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCSelector_HandleType, DEM_CODE)
Dem_ClearDTC_GetClearSelector(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle
  )
{
  return Dem_Cfg_GetClearDTCTable(ClearDTCHandle).DTCSelector;
}

/* ****************************************************************************
 % Dem_ClearDTC_SetClearSelector()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearDTC_SetClearSelector(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)  DTCSelector
  )
{
  Dem_Cfg_GetClearDTCTable(ClearDTCHandle).DTCSelector = DTCSelector;
}

/* ****************************************************************************
 % Dem_ClearDTC_CallStartNotificationFunctions()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearDTC_CallStartNotificationFunctions(
  CONST(uint32, AUTOMATIC)  DTC,
  CONST(Dem_DTCFormatType, AUTOMATIC)  DTCFormat,
  CONST(Dem_DTCOriginType, AUTOMATIC)  DTCOrigin
  )
{
#if (DEM_CFG_CLEARDTCNOTIFICATIONSTARTTABLE == STD_ON)
  Dem_SimpleIterType lClearNotificationIter;
#endif

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTC)                                                                                          /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCFormat)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCOrigin)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_CLEARDTCNOTIFICATIONSTARTTABLE == STD_ON)
  for (lClearNotificationIter = 0;
       lClearNotificationIter < Dem_Cfg_GetSizeOfClearDtcNotificationStartTable();
       ++lClearNotificationIter)
  {
    (*(Dem_Cfg_GetClearDtcNotificationStartTable(lClearNotificationIter)))(
      DTC,
      DTCFormat,
      DTCOrigin);
  }
#endif
}

/* ****************************************************************************
 % Dem_ClearDTC_CallStartNotifications()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ClearDTC_CallStartNotifications(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle
  )
{
  Dem_DTCSelector_HandleType lDTCSelector;
  Dem_DTCSelector_RequestType lSelectionRequest;

  lDTCSelector = Dem_ClearDTC_GetClearSelector(ClearDTCHandle);
  lSelectionRequest = Dem_DTCSelector_GetSelectionArguments(lDTCSelector);
  Dem_ClearDTC_CallStartNotificationFunctions(
    lSelectionRequest.DTC,
    lSelectionRequest.DTCFormat,
    lSelectionRequest.DTCOrigin);
}

/* ****************************************************************************
 % Dem_ClearDTC_CallEndNotificationFunctions()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_ClearDTC_CallEndNotificationFunctions(
  CONST(uint32, AUTOMATIC)  DTC,
  CONST(Dem_DTCFormatType, AUTOMATIC)  DTCFormat,
  CONST(Dem_DTCOriginType, AUTOMATIC)  DTCOrigin
  )
{
#if (DEM_CFG_CLEARDTCNOTIFICATIONSTARTTABLE == STD_ON)
  Dem_SimpleIterType lClearNotificationIter;
#endif

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTC)                                                                                          /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCFormat)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCOrigin)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_CLEARDTCNOTIFICATIONSTARTTABLE == STD_ON)
  for (lClearNotificationIter = 0;
       lClearNotificationIter < Dem_Cfg_GetSizeOfClearDtcNotificationFinishTable();
       ++lClearNotificationIter)
  {
    (*(Dem_Cfg_GetClearDtcNotificationFinishTable(lClearNotificationIter)))(
      DTC,
      DTCFormat,
      DTCOrigin);
  }
#endif
}

/* ****************************************************************************
 % Dem_ClearDTC_CallEndNotifications()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ClearDTC_CallEndNotifications(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle
  )
{
  Dem_DTCSelector_HandleType lDTCSelector;
  Dem_DTCSelector_RequestType lSelectionRequest;

  lDTCSelector = Dem_ClearDTC_GetClearSelector(ClearDTCHandle);
  lSelectionRequest = Dem_DTCSelector_GetSelectionArguments(lDTCSelector);
  Dem_ClearDTC_CallEndNotificationFunctions(
    lSelectionRequest.DTC,
    lSelectionRequest.DTCFormat,
    lSelectionRequest.DTCOrigin);
  Dem_DTCSelector_ReleaseSelectDTC(lDTCSelector);
}

/* ****************************************************************************
 % Dem_ClearDTC_StartClearOperation()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_ClearDTC_StartClearOperation(
  CONST(Dem_ClearTask_ClearRequestConstPtrType, AUTOMATIC)  ClearRequest,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)  DTCSelector
  )
{
  Std_ReturnType lReturnValue;
  boolean lClearStarted;

  Dem_ClearDTC_SetClearStatus(ClearRequest->ClearClient, DEM_CLEARDTC_STATUS_PENDING);
  Dem_ClearDTC_SetClearSelector(ClearRequest->ClearClient, DTCSelector);
  lClearStarted = Dem_ClearTask_TryNewClear(ClearRequest);

  if (lClearStarted == TRUE)
  {
    Dem_DTCSelector_LockSelectDTC(DTCSelector);
    lReturnValue = DEM_PENDING;
  }
  else
  {
    Dem_ClearDTC_SetClearStatus(ClearRequest->ClearClient, DEM_CLEARDTC_STATUS_IDLE);
    lReturnValue = DEM_CLEAR_BUSY;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_ClearDTC_StartClearEvent()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_ClearDTC_StartClearEvent(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)  DTCSelector
  )
{
  Std_ReturnType lReturnValue;
#if (DEM_CFG_CLEAR_SINGLE_DTCS == STD_ON)
  Dem_EventIdType lEventId;
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClearDTCHandle)                                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCSelector)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
#endif

#if (DEM_CFG_CLEAR_SINGLE_DTCS == STD_ON)
  lEventId = Dem_DTCSelector_GetEventId(DTCSelector);
  if (Dem_DTC_TestDtcSuppressed(lEventId) == FALSE)
  {
    Dem_ClearTask_ClearRequestType lClearRequest;

    lClearRequest.ClearClient = ClearDTCHandle;
    lClearRequest.ClearEventId = lEventId;
    lClearRequest.ClearGroup = DEM_CFG_GROUPMASK_NONE;
    lClearRequest.ClearCode = 0xffU;
    lClearRequest.ClearMask = 0x00U;
    lClearRequest.ClearMemoryId = Dem_DTCSelector_GetMemoryId(DTCSelector);
    lClearRequest.ClearNode = 0x00;
    lReturnValue = Dem_ClearDTC_StartClearOperation(&lClearRequest, DTCSelector);
  }
  else
  {
    lReturnValue = DEM_WRONG_DTC;
  }
#else
  lReturnValue = DEM_WRONG_DTC;
#endif
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_ClearDTC_StartClearGroup()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_ClearDTC_StartClearGroup(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)  DTCSelector
  )
{
  Std_ReturnType lReturnValue;

#if (DEM_CFG_CLEAR_GROUP_DTCS == STD_ON)
  Dem_ClearTask_ClearRequestType lClearRequest;

  lClearRequest.ClearClient = ClearDTCHandle;
  lClearRequest.ClearEventId = DEM_EVENT_INVALID;
  lClearRequest.ClearGroup = Dem_DTCSelector_GetGroupMask(DTCSelector);
  lClearRequest.ClearCode = 0xffU;
  lClearRequest.ClearMask = 0x00U;
  lClearRequest.ClearMemoryId = Dem_DTCSelector_GetMemoryId(DTCSelector);
  lClearRequest.ClearNode = 0x00;
  lReturnValue = Dem_ClearDTC_StartClearOperation(&lClearRequest, DTCSelector);
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClearDTCHandle)                                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DTCSelector)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lReturnValue = DEM_WRONG_DTC;
#endif

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_ClearDTC_StartClearAllDTCs()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_ClearDTC_StartClearAllDTCs(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)  DTCSelector
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_DTCSelector_GetGroupId(DTCSelector) == DEM_DTCSELECTOR_GROUP_WWH_OBD_ALL_DTC)
  {
    if ((Dem_ClearDTC_TestClearWwhObdAllDTCsAllowed() == TRUE)                                                                   /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_DTCSelector_GetMemoryId(DTCSelector) == DEM_CFG_MEMORYID_PRIMARY))
    {
      lReturnValue = E_OK;
    }
    else
    {
      lReturnValue = DEM_WRONG_DTC;
    }
  }
  else
  if (Dem_DTCSelector_GetGroupId(DTCSelector) == DEM_DTCSELECTOR_GROUP_EMISSION_RELATED)
  {
    if ((Dem_ClearDTC_TestClearObdAllDTCsAllowed() == TRUE)                                                                      /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      && (Dem_DTCSelector_GetMemoryId(DTCSelector) == DEM_CFG_MEMORYID_PRIMARY))
    {
      lReturnValue = E_OK;
    }
    else
    {
      lReturnValue = DEM_WRONG_DTC;
    }
  }
  else
  {
    lReturnValue = E_OK;
  }

  if (lReturnValue == E_OK)
  {
    Dem_ClearTask_ClearRequestType lClearRequest;
    lClearRequest.ClearClient = ClearDTCHandle;
    lClearRequest.ClearEventId = DEM_EVENT_INVALID;
    lClearRequest.ClearGroup = DEM_CFG_GROUPMASK_ALLDTCS;
    lClearRequest.ClearCode = 0xffU;
    lClearRequest.ClearMask = 0x00U;
    lClearRequest.ClearMemoryId = Dem_DTCSelector_GetMemoryId(DTCSelector);
    lClearRequest.ClearNode = 0x00;
    lReturnValue = Dem_ClearDTC_StartClearOperation(&lClearRequest, DTCSelector);
  }

  return lReturnValue;
}

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
 * \addtogroup Dem_ClearDTC_Public
 * \{
 */

/* ****************************************************************************
 % Dem_ClearDTC_Init()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) Dem_ClearDTC_Init(
  void
  )
{
  Dem_ClearDTC_HandleType lClearClient;
  
  for (lClearClient = 0;
       lClearClient < Dem_Cfg_GetSizeOfClearDTCTable();
       ++lClearClient)
  {
    Dem_ClearDTC_SetClearStatus(lClearClient, DEM_CLEARDTC_STATUS_IDLE);
  }
}

#if (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON)
/* ****************************************************************************
 % Dem_ClearDTC_StartClearJ1939()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_ClearDTC_StartClearJ1939(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)  DTCSelector,
  CONST(uint8, AUTOMATIC)  DTCTypeFilter,
  CONST(uint8, AUTOMATIC)  NodeAddress
  )
{
  Dem_ClearTask_ClearRequestType lClearRequest;
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_OFF)
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(NodeAddress)                                                                                  /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif
  lClearRequest.ClearClient = ClearDTCHandle;
  lClearRequest.ClearEventId = DEM_EVENT_INVALID;
  lClearRequest.ClearGroup = DEM_CFG_GROUPMASK_ALLDTCS;

  if (DTCTypeFilter == DEM_J1939DTC_CLEAR_ALL)
  { /* Clear all active DTCs */
    lClearRequest.ClearCode = (uint8)(DEM_UDS_STATUS_CDTC | DEM_UDS_STATUS_TF);
    lClearRequest.ClearMask = (uint8)(DEM_UDS_STATUS_CDTC | DEM_UDS_STATUS_TF);
  }
  else if (DTCTypeFilter == DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE)
  { /* Clear previously active DTCs */
    lClearRequest.ClearCode = (uint8)(DEM_UDS_STATUS_CDTC);
    lClearRequest.ClearMask = (uint8)(DEM_UDS_STATUS_CDTC | DEM_UDS_STATUS_TF);
  }
  else
  { /* Clear active and previously active DTCs */
    lClearRequest.ClearCode = (uint8)(DEM_UDS_STATUS_CDTC);
    lClearRequest.ClearMask = (uint8)(DEM_UDS_STATUS_CDTC);
  }

  lClearRequest.ClearMemoryId = Dem_DTCSelector_GetMemoryId(DTCSelector);
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  lClearRequest.ClearNode = Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress);
# else
  lClearRequest.ClearNode = 0x00;
# endif
  return Dem_ClearDTC_StartClearOperation(&lClearRequest, DTCSelector);
}
#endif

/* ****************************************************************************
 % Dem_ClearDTC_StartClear()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE) Dem_ClearDTC_StartClear(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle,
  CONST(Dem_DTCSelector_HandleType, AUTOMATIC)  DTCSelector
  )
{
  Std_ReturnType lReturnValue;
  
  switch (Dem_DTCSelector_GetSelectionResult(DTCSelector))
  {
  case DEM_DTCSELECTOR_SELECTION_DTC:
    lReturnValue = Dem_ClearDTC_StartClearEvent(ClearDTCHandle, DTCSelector);
    break;
  case DEM_DTCSELECTOR_SELECTION_GROUP:
    lReturnValue = Dem_ClearDTC_StartClearGroup(ClearDTCHandle, DTCSelector);
    break;
  case DEM_DTCSELECTOR_SELECTION_ALL_DTCS:
    lReturnValue = Dem_ClearDTC_StartClearAllDTCs(ClearDTCHandle, DTCSelector);
    break;
  case DEM_DTCSELECTOR_SELECTION_NO_MATCH:
  case DEM_DTCSELECTOR_SELECTION_WRONG_ORIGIN:
  case DEM_DTCSELECTOR_SELECTION_INIT:
  default:
    /* cannot reach: cases already handled by caller */
    lReturnValue = DEM_CLEAR_FAILED;
    break;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_ClearDTC_ResetClearStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) Dem_ClearDTC_ResetClearStatus(
  CONST(Dem_ClearDTC_HandleType, AUTOMATIC)  ClearDTCHandle
  )
{
  if (Dem_ClearDTC_GetClearStatus(ClearDTCHandle) != DEM_CLEARDTC_STATUS_PENDING)
  {
    Dem_ClearDTC_SetClearStatus(ClearDTCHandle, DEM_CLEARDTC_STATUS_IDLE);
  }
}

/* ****************************************************************************
 % Dem_ClearDTC_NotifyClearResult()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) Dem_ClearDTC_NotifyClearResult(
  CONST(uint8, AUTOMATIC)  QueueClearState
  )
{
  Dem_ClearDTC_HandleType lClearHandle;
  lClearHandle = Dem_ClearTask_GetClearClient();
  if (Dem_ClearDTC_GetClearStatus(lClearHandle) != DEM_CLEARDTC_STATUS_IDLE)
  {
    switch (QueueClearState)
    {
    case DEM_CLEARTASK_INPROGRESS:
      Dem_ClearDTC_CallStartNotifications(lClearHandle);
      break;

    case DEM_CLEARTASK_DONE:
      Dem_ClearDTC_CallEndNotifications(lClearHandle);
      Dem_ClearDTC_SetClearStatus(lClearHandle, DEM_CLEARDTC_STATUS_DONE);
      break;
    case DEM_CLEARTASK_FAILED:
      Dem_ClearDTC_CallEndNotifications(lClearHandle);
      Dem_ClearDTC_SetClearStatus(lClearHandle, DEM_CLEARDTC_STATUS_FAILED);
      break;
    case DEM_CLEARTASK_NVERROR:
      Dem_ClearDTC_CallEndNotifications(lClearHandle);
      Dem_ClearDTC_SetClearStatus(lClearHandle, DEM_CLEARDTC_STATUS_NV_ERROR);
      break;
    case DEM_CLEARTASK_IDLE:
    default:
      /* no update */
      break;
    }
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_CLEARDTC_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ClearDTC_Implementation.h
 *********************************************************************************************************************/
