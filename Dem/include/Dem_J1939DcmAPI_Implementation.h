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
/*! \addtogroup Dem_J1939DcmAPI
 *  \{
 *  \file       Dem_J1939DcmAPI_Implementation.h
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

#if !defined (DEM_J1939DCMAPI_IMPLEMENTATION_H)
#define DEM_J1939DCMAPI_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_J1939DcmAPI_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Esm_Implementation.h"

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

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) \
   || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) \
   || (DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON) )
/*! Filter data for J1939Dcm filter requests */
DEM_LOCAL VAR(Dem_J1939_FilterInfoType, DEM_VAR_NOINIT) Dem_J1939Dcm_FilterInfo;
#endif

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_J1939DcmAPI_Public
 * \{
 */

                                                       /* J1939DCM Interface */
/* ------------------------------------------------------------------------- */

#if ( (DEM_CFG_SUPPORT_J1939 == STD_ON) \
   && ((DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON)) )
/* ****************************************************************************
 % Dem_J1939Dcm_FilterForEventMatch
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
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939Dcm_FilterForEventMatch(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Std_ReturnType lEventMatch;
  uint8 lFilterCriteria;

  lEventMatch = E_NOT_OK;
  lFilterCriteria = Dem_J1939Dcm_FilterGetCriteria();

  /* Does the event support a J1939Dtc */
  if (Dem_Cfg_EventJ1939Dtc(EventId) != DEM_CFG_DTC_J1939_INVALID)
  {
# if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
    /* don't match dependent combined events */
    if (Dem_Cfg_GetMasterEvent(EventId) == EventId)
# endif
    {
      if (Dem_DTC_TestDtcSuppressed(EventId) == FALSE)
      {
        uint8 lEventStatus;
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)                                                                                     /* COV_MSR_UNSUPPORTED XF */
        Dem_Cfg_EventJ1939NodeIterType lNodeIter;

        /* filter event only if it is linked to the requested node */
        for (Dem_Cfg_EventJ1939NodeIterInit(EventId, &lNodeIter);                                                                /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == TRUE;                                                               /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_EventJ1939NodeIterNext(&lNodeIter))                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          if (Dem_J1939Dcm_FilterDtcGetNodeId() == Dem_Cfg_EventJ1939NodeIterGet(&lNodeIter))                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
          {
            break;
          }
        }
        if (Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == TRUE)
# endif
        {
          lEventStatus = Dem_DTC_ApplyExternalOnlyStatus(EventId, Dem_DTC_GetDTCStatus(EventId));

          switch (lFilterCriteria)
          {
          case DEM_J1939DCM_FILTER_ACTIVE:
            if (DEM_DTC_TEST_J1939_STATUS_ADTC(lEventStatus) == TRUE)
            {
              lEventMatch = E_OK;
            }
            break;

          case DEM_J1939DCM_FILTER_PREVIOUSLY_ACTIVE:
            if (DEM_DTC_TEST_J1939_STATUS_PADTC(lEventStatus) == TRUE)
            {
              lEventMatch = E_OK;
            }
            break;

          case DEM_J1939DCM_FILTER_PENDING:
            if (Dem_UDSStatus_Test_PDTC(lEventStatus) == TRUE)
            {
              lEventMatch = E_OK;
            }
            break;

          case DEM_J1939DCM_FILTER_CURRENTLY_ACTIVE:
            if (Dem_UDSStatus_Test_TF(lEventStatus) == TRUE)
            {
              lEventMatch = E_OK;
            }
            break;

          default:
            /* lEventMatch == E_NOT_OK already set */
            break;
          }
        }
      }
    }
  }

  return lEventMatch;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_J1939 == STD_ON) && (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) || (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 % Dem_J1939Dcm_GetNextDTCwithLampStatus
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939Dcm_GetNextDTCwithLampStatus(
  CONSTP2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_J1939DCM_DATA)  LampStatus,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lEventId = Dem_J1939Dcm_FilterDtcGetEventIndex();

  /* if last EventId is not valid or was still analyzed skip the filtering */
  if (lEventId != DEM_EVENT_INVALID)
  {
    Dem_EventIdType lEventIdLast;

    lEventIdLast = Dem_Cfg_GlobalPrimaryLast();
    /* iterate through the EventIds and check filter criteria */
    for (; lEventId <= lEventIdLast; lEventId++)
    {
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)                                                                                     /* COV_MSR_UNSUPPORTED XF */
      Dem_Cfg_EventJ1939NodeIterType lNodeIter;
# endif

      if (Dem_Cfg_EventJ1939Dtc(lEventId) == DEM_CFG_DTC_J1939_INVALID)
      { /* Don't match non-J1939 events */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
      if (Dem_DTC_TestDtcSuppressed(lEventId) == TRUE)
      { /* Don't match suppressed events */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
      if (lEventId != Dem_Cfg_GetMasterEvent(lEventId))
      { /* Don't match dependent combined events */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# endif
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)                                                                                     /* COV_MSR_UNSUPPORTED XF */
      for (Dem_Cfg_EventJ1939NodeIterInit(lEventId, &lNodeIter);                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == TRUE;                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_EventJ1939NodeIterNext(&lNodeIter))                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        if (Dem_J1939Dcm_FilterDtcGetNodeId() == Dem_Cfg_EventJ1939NodeIterGet(&lNodeIter))                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          break;
        }
      }
      if (Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == FALSE)
      { /* Don't match events not belonging to the requested node */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
# endif

      /* Get OCC, LampStatus and DTC */
      *J1939DTC = Dem_Cfg_EventJ1939Dtc(lEventId);
      *OccurenceCounter = Dem_Util_J1939OccurrenceCounter(lEventId);

# if (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON)
      if (Dem_Cfg_EventSpecialIndicator(lEventId) != DEM_CFG_SPECIAL_INDICATOR_NONE)
      {
        uint8 lEventStatus;
        uint16 lSpecialIndicatorStatus;
        uint8  lSpecialIndicator;

        lEventStatus = Dem_DTC_ApplyExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));

        if (Dem_UDSStatus_Test_WIR(lEventStatus) == TRUE)
        { /* indicator requested/active */
          lSpecialIndicatorStatus = Dem_Util_J1939IndicatorStatus(Dem_Cfg_EventSpecialIndicatorState(lEventId));
        }
        else
        {
          lSpecialIndicatorStatus = DEM_DATA_J1939_INDICATOR_OFF;
        }

        lSpecialIndicator = Dem_Cfg_EventSpecialIndicator(lEventId);

#  if (DEM_FEATURE_NEED_OBD == STD_ON)
        if (lSpecialIndicator == Dem_Cfg_GlobalMilIndicator())
        {
          *LampStatus = (Dem_J1939DcmLampStatusType)((DEM_DATA_J1939_RSL_NA | DEM_DATA_J1939_AWL_NA | DEM_DATA_J1939_PL_NA) | (lSpecialIndicatorStatus << 6));
        }
        else
#  endif
        if (lSpecialIndicator == Dem_Cfg_GlobalRslIndicator())
        {
          *LampStatus = (Dem_J1939DcmLampStatusType)((DEM_DATA_J1939_MIL_NA | DEM_DATA_J1939_AWL_NA | DEM_DATA_J1939_PL_NA) | (lSpecialIndicatorStatus << 4));
        }
        else if (lSpecialIndicator == Dem_Cfg_GlobalAwlIndicator())
        {
          *LampStatus = (Dem_J1939DcmLampStatusType)((DEM_DATA_J1939_MIL_NA | DEM_DATA_J1939_RSL_NA | DEM_DATA_J1939_PL_NA) | (lSpecialIndicatorStatus << 2));
        }
        else if (lSpecialIndicator == Dem_Cfg_GlobalPlIndicator())
        {
          *LampStatus = (Dem_J1939DcmLampStatusType)((DEM_DATA_J1939_MIL_NA | DEM_DATA_J1939_RSL_NA | DEM_DATA_J1939_AWL_NA) | (lSpecialIndicatorStatus));
        }
        else
        {
          Dem_Error_ReportError(DEM_INTERNAL_APIID, DEM_E_PARAM_CONFIG);
        }
      }
      else
# endif /* (DEM_FEATURE_NEED_SPECIAL_INDICATORS == STD_ON) */
      { /* No special indicator available for this event */
        *LampStatus = DEM_DATA_J1939_MIL_NA | DEM_DATA_J1939_RSL_NA | DEM_DATA_J1939_AWL_NA | DEM_DATA_J1939_PL_NA; /* All lamps are set to not applicable */
      }

      lReturnValue = E_OK;
      break;
    }

    if (lEventId > lEventIdLast)
    { /* last EventId has been processed */
      Dem_J1939Dcm_FilterDtcSetEventIndex(DEM_EVENT_INVALID);
    }
    else
    { /* write back the EventId (which was raised by 1 for the next repetition) */
      Dem_J1939Dcm_FilterDtcSetEventIndex(lEventId + 1);
    }
  } /* (lEventId != DEM_EVENT_INVALID) */
  /* else return value DEM_FILTERED_NO_MATCHING_ELEMENT initially set */

  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_J1939 == STD_ON) && (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) */

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939Dcm_GetNextFF_FindNextEvent
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
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_J1939Dcm_GetNextFF_FindNextEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  LastEventId,
  CONST(uint8, AUTOMATIC)  FreezeFrameKind
  )
{
  Dem_EventIdType lEventId;

  for (lEventId = LastEventId; lEventId <= Dem_Cfg_GlobalPrimaryLast(); lEventId++)
  {
    if (Dem_DTC_TestDtcSuppressed(lEventId) == TRUE)
    { /* Don't match suppressed events */
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
    if (Dem_DTCInternalStatus_GetStoredStatus(Dem_DTC_GetInternalStatus(lEventId)) == Dem_DTCInternalStatus_StoredStatus_None)
    { /* only consider stored events */
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }

    if ( ((FreezeFrameKind == DEM_J1939DCM_FREEZEFRAME) && (Dem_Cfg_EventJ1939FFExists(lEventId) == FALSE))                      /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || ((FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME) && (Dem_Cfg_EventJ1939ExpFFExists(lEventId) == FALSE)) )
    { /* the event does not support the requested data (also: no J1939 DTC) */
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }

# if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
    if (lEventId != Dem_Cfg_GetMasterEvent(lEventId))
    { /* Don't match dependent combined events, only the group event */
      continue;                                                                                                                  /* PRQA S 0770 */ /* MD_DEM_14.5 */
    }
# endif

# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
    {
      Dem_Cfg_EventJ1939NodeIterType lNodeIter;

      for (Dem_Cfg_EventJ1939NodeIterInit(lEventId, &lNodeIter);                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == TRUE;                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_EventJ1939NodeIterNext(&lNodeIter))                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */

      {
        if (Dem_J1939Dcm_FilterDataGetNodeId() == Dem_Cfg_EventJ1939NodeIterGet(&lNodeIter))                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          break;
        }
      }
      if (Dem_Cfg_EventJ1939NodeIterExists(&lNodeIter) == FALSE)
      { /* The DTC is not supported on the requested node */
        continue;                                                                                                                /* PRQA S 0770 */ /* MD_DEM_14.5 */
      }
    }
# endif

    /* Found a candidate */
    break;
  }

  if (lEventId > Dem_Cfg_GlobalPrimaryLast())
  { /* Did not find a candidate */
    lEventId = DEM_EVENT_INVALID;
  }

  return lEventId;
}                                                                                                                                /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
#endif

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939Dcm_GetNextFreezeFrame
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
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939Dcm_GetNextFreezeFrame(
  CONSTP2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  DestBuffer,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;
  uint8 lFreezeFrameKind;

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lEventId = Dem_J1939Dcm_FilterDataGetEventId();
  lFreezeFrameKind = Dem_J1939Dcm_FilterDataGetKind();

  if (lEventId != DEM_EVENT_INVALID)
  {
    boolean lCopyData;

    lCopyData = FALSE;
    if (Dem_J1939Dcm_FilterDataGetState() == DEM_PENDING)
    { /* process event again if still stored. This event is already the
       * combined group event in case of combination, so no aditional check
       * in this context */
      if (Dem_DTCInternalStatus_GetStoredStatus(Dem_DTC_GetInternalStatus(lEventId)) != Dem_DTCInternalStatus_StoredStatus_None)
      {
        lCopyData = TRUE;
      }
      else
      { /* proceed with next EventId */
        lEventId = lEventId + 1;
        Dem_J1939Dcm_FilterDataSetState(DEM_J1939DCM_FILTERDATA_IDLE);
      }
    }

    if (Dem_J1939Dcm_FilterDataGetState() == DEM_J1939DCM_FILTERDATA_IDLE)
    { /* Search the next/first J1939DTC which is currently stored */
      lEventId = Dem_J1939Dcm_GetNextFF_FindNextEvent(lEventId, lFreezeFrameKind);

      if (lEventId == DEM_EVENT_INVALID)
      { /* primary EventId range exceeded, finish processing */
        Dem_J1939Dcm_FilterDataSetEventId(DEM_EVENT_INVALID);
        Dem_J1939Dcm_FilterDataSetState(DEM_J1939DCM_FILTERDATA_IDLE);
      }
      else
      {
        lCopyData = TRUE;
      }
    }

    if (lCopyData == TRUE)
    {
      Dem_Mem_MemoryInfoPtrType lMemoryInfo;
      Dem_Cfg_MemoryIndexType lMemoryIndex;
      uint8 lUpdateState;
      boolean lModificationDetected;

      lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_PRIMARY);
      lMemoryIndex = Dem_MemStorageManager_MemoryFindIndex(lMemoryInfo, lEventId);                                                             /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

      if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
      {
        lUpdateState = Dem_Mem_MemoryUpdateGetState(lMemoryIndex);
        lModificationDetected = FALSE;

        /* check for concurrent access to the memory entry */
        if (Dem_Mem_UpdateTestInProgress(lUpdateState) == FALSE)
        {
          Dem_MemoryEntry_HandleType lMemoryEntryId;
          uint8* lFreezeFramePtr;
          uint8  lSize;
          Dem_Data_OccurrenceCounterType lOccurrenceCounter;

          lMemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lMemoryIndex);
          /* set the source buffer offset and the size to copy */
# if (DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON) && (DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON)
          if (lFreezeFrameKind == DEM_J1939DCM_FREEZEFRAME)
          {
            lFreezeFramePtr = Dem_MemoryEntry_GetJ1939FreezeFramePtr(lMemoryEntryId, 0);
            lSize = (uint8)Dem_Cfg_GlobalJ1939FFRawSize();
          }
          else
          {
            lFreezeFramePtr = Dem_MemoryEntry_GetJ1939FreezeFramePtr(lMemoryEntryId, Dem_Cfg_GlobalJ1939FFRawSize());
            lSize = (uint8)Dem_Cfg_GlobalJ1939ExpFFRawSize();
          }
# else
          lFreezeFramePtr = Dem_MemoryEntry_GetJ1939FreezeFramePtr(lMemoryEntryId, 0);

          if (lFreezeFrameKind == DEM_J1939DCM_FREEZEFRAME)
          {
            lSize = (uint8)Dem_Cfg_GlobalJ1939FFRawSize();
          }
          else
          {
            lSize = (uint8)Dem_Cfg_GlobalJ1939ExpFFRawSize();
          }
# endif
          if (*BufSize >= lSize)
          {
            Dem_MemCpy(DestBuffer, lFreezeFramePtr, lSize);                                                                      /* PRQA S 0602, 3109 */ /* MD_DEM_20.2, MD_MSR_14.3 */

            *BufSize = lSize;
            *J1939DTC = Dem_Cfg_EventJ1939Dtc(lEventId);
# if (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
            lOccurrenceCounter = Dem_MemoryEntry_GetOccurrenceCounter2Byte(lMemoryEntryId);
# else
            lOccurrenceCounter = Dem_MemoryEntry_GetOccurrenceCounter(lMemoryEntryId);
# endif

            if (lOccurrenceCounter > 0x7eU)
            { /* Occurrence counter > 126 shall be reported as 126 */
              lOccurrenceCounter = 0x7eU;
            }

            *OccurenceCounter = (uint8)lOccurrenceCounter;

            if (lUpdateState != Dem_Mem_MemoryUpdateGetState(lMemoryIndex))
            { /* concurrent access to memory entry during copy process */
              lModificationDetected = TRUE;
            }
          }
          else
          {
            lReturnValue = DEM_BUFFER_TOO_SMALL;
          }
        }
        else
        { /* concurrent access detected */
          lModificationDetected = TRUE;
        }

        if (lModificationDetected == TRUE)
        { /* retry next call of this interface */
          Dem_J1939Dcm_FilterDataSetEventId(lEventId);
          Dem_J1939Dcm_FilterDataSetState(DEM_PENDING);

          lReturnValue = DEM_PENDING;
        }
        else if (lReturnValue != DEM_BUFFER_TOO_SMALL)
        { /* copy finished */
          Dem_J1939Dcm_FilterDataSetEventId(lEventId + 1);
          Dem_J1939Dcm_FilterDataSetState(DEM_J1939DCM_FILTERDATA_IDLE);

          lReturnValue = E_OK;
        }
        else
        {
          /* Return DEM_BUFFER_TOO_SMALL */
        }
      }
    }
  }
  /* else processing finished lReturnValue = DEM_NO_SUCH_ELEMENT initially set */

  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON */

                                                       /* J1939DCM Interface */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_SUPPORT_J1939 == STD_ON) && (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)                                              /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 % Dem_J1939Dcm_FilterMemory
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(Dem_EventIdType, DEM_CODE)
Dem_J1939Dcm_FilterMemory(
  void
  )
{
  Dem_EventIdType lEventId;

  lEventId = Dem_J1939Dcm_FilterDtcGetEventIndex();

  /* if last EventId is not valid or was still analyzed skip the filtering */
  if (DEM_EVENT_INVALID != lEventId)
  {
    Dem_Mem_MemoryInfoPtrType lMemoryInfo;
    Dem_EventIdType lEventIdLast;

    lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_J1939Dcm_FilterDtcGetMemoryId());
    lEventIdLast = Dem_MemStorageManager_MemoryGetLastEvent(lMemoryInfo);                                                                      /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

    /* iterate through the EventIds and check filter criteria */
    for (; lEventId <= lEventIdLast; ++lEventId)
    {
      if (E_OK == Dem_J1939Dcm_FilterForEventMatch(lEventId))
      {
        /* identified an Event which matches the filter criteria */
        break;
      }
    }

    if (lEventId > lEventIdLast)
    { /* last EventId has been processed */
      Dem_J1939Dcm_FilterDtcSetEventIndex(DEM_EVENT_INVALID);
      lEventId = DEM_EVENT_INVALID;
    }
    else
    { /* write back the EventId ( which was raised by 1 for the next repetition) */
      Dem_J1939Dcm_FilterDtcSetEventIndex(lEventId + 1);
    }
  }
  /* else lReturnValue = DEM_EVENT_INVALID initially set */

  return lEventId;
}
#endif /* (DEM_CFG_SUPPORT_J1939 == STD_ON) && (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) */

                                                 /* J1939Dcm <-> Dem : J1939 */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON)                                                                                  /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmClearDTC
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
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmClearDTC(
  Dem_J1939DcmSetClearFilterType DTCTypeFilter,
  Dem_DTCOriginType DTCOrigin,
  uint8 NodeAddress                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)
  lReturnValue = E_NOT_OK;
# endif
  DEM_IGNORE_UNUSED_ARGUMENT(DTCOrigin)
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTCTypeFilter >= DEM_J1939_CLEAR_FILTER_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) >= DEM_CFG_J1939_NODE_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if ((DTCOrigin == 0) || (DTCOrigin >= DEM_DTC_ORIGIN_INVALID))
  {
    lReturnValue = DEM_WRONG_DTCORIGIN;
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */    
    lReturnValue = Dem_ClientAccess_J1939ClearDTC(DemConf_DemClient_DemClient_J1939, DTCTypeFilter, NodeAddress, DTCOrigin);
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMCLEARDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_J1939_CLEAR_DTC == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) || (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 % Dem_J1939DcmFirstDTCwithLampStatus
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
FUNC(void, DEM_CODE)
Dem_J1939DcmFirstDTCwithLampStatus(
  uint8 NodeAddress                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Dem_Det_ErrorRegisterDefine()

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) >= DEM_CFG_J1939_NODE_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
# if (DEM_CFG_SUPPORT_J1939_NODES != STD_ON)
    DEM_IGNORE_UNUSED_ARGUMENT(NodeAddress)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
# endif

    Dem_J1939Dcm_FilterDtcSetEventIndex(Dem_Cfg_GlobalPrimaryFirst());
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
    Dem_J1939Dcm_FilterDtcSetNodeId(Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress));
# endif
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif
}
#endif /* (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) || (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)
/* ****************************************************************************
 % Dem_J1939DcmGetNextDTCwithLampStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextDTCwithLampStatus(
  P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_J1939DCM_DATA)  LampStatus,
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)
    lReturnValue = DEM_NO_SUCH_ELEMENT;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (LampStatus == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (J1939DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (OccurenceCounter == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_J1939Dcm_GetNextDTCwithLampStatus(LampStatus, J1939DTC, OccurenceCounter);                                /* SBSW_DEM_POINTER_FORWARD_API */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) || (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) */

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmSetFreezeFrameFilter
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
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmSetFreezeFrameFilter(
  Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,
  uint8 NodeAddress                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (FreezeFrameKind >= DEM_J1939_FILTER_FREEZEFRAME_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) >= DEM_CFG_J1939_NODE_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
# if (DEM_CFG_SUPPORT_J1939_NODES != STD_ON)
    DEM_IGNORE_UNUSED_ARGUMENT(NodeAddress)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
# endif

# if (DEM_CFG_SUPPORT_J1939_FREEZEFRAME == STD_ON)
    if (FreezeFrameKind == DEM_J1939DCM_FREEZEFRAME)
    {
      Dem_J1939Dcm_FilterDataSetKind(DEM_J1939DCM_FREEZEFRAME);
      Dem_J1939Dcm_FilterDataSetEventId(Dem_Cfg_GlobalPrimaryFirst());
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
      Dem_J1939Dcm_FilterDataSetNodeId(Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress));
#  endif
      Dem_J1939Dcm_FilterDataSetState(DEM_J1939DCM_FILTERDATA_IDLE);

      lReturnValue = E_OK;
    }
    else
# endif
# if (DEM_CFG_SUPPORT_J1939_EXPANDED_FREEZEFRAME == STD_ON)
    if (FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME)
    {
      Dem_J1939Dcm_FilterDataSetKind(DEM_J1939DCM_EXPANDED_FREEZEFRAME);
      Dem_J1939Dcm_FilterDataSetEventId(Dem_Cfg_GlobalPrimaryFirst());
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
      Dem_J1939Dcm_FilterDataSetNodeId(Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress));
#  endif
      Dem_J1939Dcm_FilterDataSetState(DEM_J1939DCM_FILTERDATA_IDLE);

      lReturnValue = E_OK;
    }
    else
# endif
    {
      /* At least DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME is not supported
         as this is completely handled by J1939DCM */
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON */

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF xf xf */
/* ****************************************************************************
 % Dem_J1939DcmGetNextFreezeFrame
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextFreezeFrame(
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurenceCounter,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  DestBuffer,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)
  lReturnValue = DEM_NO_SUCH_ELEMENT;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (J1939DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (OccurenceCounter == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (DestBuffer == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (BufSize == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if ( (Dem_J1939Dcm_FilterDataGetKind() != DEM_J1939DCM_FREEZEFRAME)
    && (Dem_J1939Dcm_FilterDataGetKind() != DEM_J1939DCM_EXPANDED_FREEZEFRAME))
  { /* API Dem_J1939DcmSetFreezeFrameFilter must be called before this, selecting (expanded) freeze frame */
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_J1939Dcm_GetNextFreezeFrame(J1939DTC, OccurenceCounter, DestBuffer, BufSize);                             /* SBSW_DEM_POINTER_FORWARD_API */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON */

#if (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON)                                                                               /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmGetNextSPNInFreezeFrame
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextSPNInFreezeFrame(
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  SPNSupported,                                                                     /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  SPNDataLength                                                                      /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (SPNSupported == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (SPNDataLength == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Dem_J1939Dcm_FilterDataGetKind() != DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME)
  { /* API Dem_J1939DcmSetFreezeFrameFilter must be called before this, selecting spn in freeze frame */
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    DEM_IGNORE_UNUSED_ARGUMENT(SPNSupported)                                                                                     /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(SPNDataLength)                                                                                    /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMGETNEXTSPNINFREEZEFRAME_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif /* DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON */

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmSetDTCFilter
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
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmSetDTCFilter(
  Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
  Dem_DTCKindType DTCKind,
  Dem_DTCOriginType DTCOrigin,
  uint8 NodeAddress,                                                                                                             /* PRQA S 3206 */ /* MD_DEM_3206 */
  P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_J1939DCM_DATA)  LampStatus
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTCStatusFilter >= DEM_J1939_FILTER_DTC_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (DTCKind >= DEM_DTC_KIND_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if ((DTCOrigin == 0) || (DTCOrigin >= DEM_DTC_ORIGIN_INVALID))
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (LampStatus == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
    uint8 DEM_J1939_NODE_ID;
# endif

    /* ----- Implementation ------------------------------------------------ */
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
    DEM_J1939_NODE_ID = Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress);

#  if (DEM_DEV_ERROR_DETECT == STD_ON)
    if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) >= DEM_CFG_J1939_NODE_INVALID)
    {
      Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
    }
    else
#  endif
# else
    DEM_IGNORE_UNUSED_ARGUMENT(NodeAddress)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
# endif
    if (DTCKind == DEM_DTC_KIND_ALL_DTCS)
    {
      uint8 lFilterCriteria;

      /* Set the first index dependent on the requested DTC status and configuration */
      switch (DTCStatusFilter)
      {
        case DEM_J1939DTC_PENDING:
          lFilterCriteria = DEM_J1939DCM_FILTER_PENDING;
          lReturnValue = E_OK;
          break;
        case DEM_J1939DTC_ACTIVE:
          lFilterCriteria = DEM_J1939DCM_FILTER_ACTIVE;
          lReturnValue = E_OK;
          break;
        case DEM_J1939DTC_PREVIOUSLY_ACTIVE:
          lFilterCriteria = DEM_J1939DCM_FILTER_PREVIOUSLY_ACTIVE;
          lReturnValue = E_OK;
          break;
        case DEM_J1939DTC_CURRENTLY_ACTIVE:
          lFilterCriteria = DEM_J1939DCM_FILTER_CURRENTLY_ACTIVE;
          lReturnValue = E_OK;
          break;
        default:
          lFilterCriteria = 0;
          lReturnValue = E_NOT_OK;
          break;
      }

      if (lReturnValue == E_OK)
      {
        Dem_J1939Dcm_FilterSetCriteria(lFilterCriteria);
        /* Dispatch the Event target */
        switch (DTCOrigin)
        {
        case DEM_DTC_ORIGIN_PRIMARY_MEMORY:
          Dem_J1939Dcm_FilterDtcSetMemoryId(DEM_CFG_MEMORYID_PRIMARY);
          Dem_J1939Dcm_FilterDtcSetEventIndex(Dem_Cfg_GlobalPrimaryFirst());
          break;

# if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
        case DEM_DTC_ORIGIN_SECONDARY_MEMORY:
          Dem_J1939Dcm_FilterDtcSetMemoryId(DEM_CFG_MEMORYID_SECONDARY);
          Dem_J1939Dcm_FilterDtcSetEventIndex(Dem_Cfg_GlobalSecondaryFirst());
          break;
# endif

        default:
          lReturnValue = E_NOT_OK;
          break;
        }
# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
        Dem_J1939Dcm_FilterDtcSetNodeId(DEM_J1939_NODE_ID);
# endif
        /* calculate node related lamp status */
        *LampStatus = (Dem_J1939DcmLampStatusType)( Dem_Cfg_J1939NodeIndicatorReadiness(DEM_J1939_NODE_ID)                       /* SBSW_DEM_POINTER_WRITE_API */
# if (DEM_CFG_SUPPORT_MIL == STD_ON)
          | (Dem_Util_J1939IndicatorStatus(Dem_Cfg_GlobalSpecialIndicatorStates[Dem_Cfg_GlobalMilIndicator()][DEM_J1939_NODE_ID]) << 6)
# endif
# if (DEM_CFG_SUPPORT_RSL == STD_ON)
          | (Dem_Util_J1939IndicatorStatus(Dem_Cfg_GlobalSpecialIndicatorStates[Dem_Cfg_GlobalRslIndicator()][DEM_J1939_NODE_ID]) << 4)
# endif
# if (DEM_CFG_SUPPORT_AWL == STD_ON)
          | (Dem_Util_J1939IndicatorStatus(Dem_Cfg_GlobalSpecialIndicatorStates[Dem_Cfg_GlobalAwlIndicator()][DEM_J1939_NODE_ID]) << 2)
# endif
# if (DEM_CFG_SUPPORT_PL == STD_ON)
          | (Dem_Util_J1939IndicatorStatus(Dem_Cfg_GlobalSpecialIndicatorStates[Dem_Cfg_GlobalPlIndicator()][DEM_J1939_NODE_ID]))
# endif
          );
      }
    }
    else
    { /* Wrong filter */ }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMSETDTCFILTER_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmGetNumberOfFilteredDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNumberOfFilteredDTC(
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  NumberOfFilteredDTC
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (NumberOfFilteredDTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    Dem_Mem_MemoryInfoPtrType lMemoryInfo;
    uint16 lNumberOfFilteredDTC;
    Dem_EventIdType lEventId;

    /* ----- Implementation ------------------------------------------------ */
    lMemoryInfo = Dem_MemStorageManager_MemoryInfoInit(Dem_J1939Dcm_FilterDtcGetMemoryId());
    lNumberOfFilteredDTC = 0;

    /* iterate through the EventIds and check filter criteria */
    for (lEventId = Dem_MemStorageManager_MemoryGetFirstEvent(lMemoryInfo);                                                                    /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
         lEventId <= Dem_MemStorageManager_MemoryGetLastEvent(lMemoryInfo);                                                                    /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
         lEventId++)
    {
      if (Dem_J1939Dcm_FilterForEventMatch(lEventId) == E_OK)
      {
        lNumberOfFilteredDTC++;
      }
    }

    *NumberOfFilteredDTC = lNumberOfFilteredDTC;                                                                                 /* SBSW_DEM_POINTER_WRITE_API */
    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON)                                                                                   /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmGetNextFilteredDTC
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
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextFilteredDTC(
  P2VAR(uint32, AUTOMATIC, DEM_J1939DCM_DATA)  J1939DTC,
  P2VAR(uint8, AUTOMATIC, DEM_J1939DCM_DATA)  OccurrenceCounter
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (J1939DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (OccurrenceCounter == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    Dem_EventIdType lEventId;

    /* ----- Implementation ------------------------------------------------ */
    lEventId = Dem_J1939Dcm_FilterMemory();

    /* Get return values only if valid EventId was returned, otherwise DEM_FILTERED_NO_MATCHING_ELEMENT is returned */
    if (lEventId != DEM_EVENT_INVALID)
    {
      /* Only EventIds with a valid DTC number should be processed here, so the EventId->DTC mapping will return always a valid DTC number */
      *J1939DTC = Dem_Cfg_EventJ1939Dtc(lEventId);                                                                               /* SBSW_DEM_POINTER_WRITE_API */
      *OccurrenceCounter = Dem_Util_J1939OccurrenceCounter(lEventId);                                                            /* SBSW_DEM_POINTER_WRITE_API */

      lReturnValue = E_OK;
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMGETNEXTFILTEREDDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_RATIO == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmSetRatioFilter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmSetRatioFilter(
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  IgnitionCycleCounter,                                                             /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  OBDMonitoringConditionsEncountered,                                               /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  uint8 NodeAddress                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (IgnitionCycleCounter == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (OBDMonitoringConditionsEncountered == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) >= DEM_CFG_J1939_NODE_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    DEM_IGNORE_UNUSED_ARGUMENT(IgnitionCycleCounter)                                                                             /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(OBDMonitoringConditionsEncountered)                                                               /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(NodeAddress)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMSETRATIOFILTER_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_RATIO == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_RATIO == STD_ON)                                                                                      /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmGetNextFilteredRatio
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmGetNextFilteredRatio(
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  SPN,                                                                              /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  Numerator,                                                                        /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_J1939DCM_DATA)  Denominator                                                                       /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (SPN == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Numerator == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Denominator == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    DEM_IGNORE_UNUSED_ARGUMENT(SPN)                                                                                              /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(Numerator)                                                                                        /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(Denominator)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMGETNEXTFILTEREDRATIO_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_RATIO == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmReadDiagnosticReadiness1
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
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmReadDiagnosticReadiness1(
  P2VAR(Dem_J1939DcmDiagnosticReadiness1Type, AUTOMATIC, DEM_J1939DCM_DATA)  DataValue,                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  uint8 NodeAddress                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DataValue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) >= DEM_CFG_J1939_NODE_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  endif
# endif
  {
    uint8 lFilterCriteria;
    uint8 lNumberOfFilteredDTC;
    Dem_EventIdType lEventId;
    DEM_IGNORE_UNUSED_ARGUMENT(NodeAddress)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

    /* ----- Implementation ------------------------------------------------ */
    DataValue->OBDCompliance = Dem_Cfg_GlobalObdRequirements();                                                                  /* SBSW_DEM_POINTER_WRITE_API */
    DataValue->ContinuouslyMonitoredSystemsSupport_Status = 0;                                                                   /* SBSW_DEM_POINTER_WRITE_API */
    DataValue->NonContinuouslyMonitoredSystemsSupport = 0;                                                                       /* SBSW_DEM_POINTER_WRITE_API */
    DataValue->NonContinuouslyMonitoredSystemsStatus = 0;                                                                        /* SBSW_DEM_POINTER_WRITE_API */

    /* set DTC filter for active DTCs */
    lFilterCriteria = DEM_J1939DCM_FILTER_ACTIVE;
    Dem_J1939Dcm_FilterSetCriteria(lFilterCriteria);

# if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
    Dem_J1939Dcm_FilterDtcSetNodeId(Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress));
# endif

    /* get number of active DTCs */
    lNumberOfFilteredDTC = 0;
    for (lEventId = Dem_Cfg_GlobalPrimaryFirst();
         lEventId <= Dem_Cfg_GlobalPrimaryLast();
         ++lEventId)
    {
      if (Dem_J1939Dcm_FilterForEventMatch(lEventId) == E_OK)
      {
        lNumberOfFilteredDTC += 1;
        if (lNumberOfFilteredDTC == 250)
        {
          break;
        }
      }
    }
    DataValue->ActiveTroubleCodes = lNumberOfFilteredDTC;                                                                        /* SBSW_DEM_POINTER_WRITE_API */

    /* set DTC filter for previously active DTCs */
    lFilterCriteria = DEM_J1939DCM_FILTER_PREVIOUSLY_ACTIVE;
    Dem_J1939Dcm_FilterSetCriteria(lFilterCriteria);

    /* get number of previously active DTCs */
    lNumberOfFilteredDTC = 0;
    for (lEventId = Dem_Cfg_GlobalPrimaryFirst();
         lEventId <= Dem_Cfg_GlobalPrimaryLast();
         ++lEventId)
    {
      if (Dem_J1939Dcm_FilterForEventMatch(lEventId) == E_OK)
      {
        lNumberOfFilteredDTC += 1;
        if (lNumberOfFilteredDTC == 250)
        {
          break;
        }
      }
    }
    DataValue->PreviouslyActiveDiagnosticTroubleCodes = lNumberOfFilteredDTC;                                                    /* SBSW_DEM_POINTER_WRITE_API */
    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMREADDIAGNOSTICREADINESS1_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif
  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_J1939_READINESS1 == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_READINESS2 == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmReadDiagnosticReadiness2
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmReadDiagnosticReadiness2(                                                                                            /* PRQA S 0777 */ /* MD_DEM_5.1 */
  P2VAR(Dem_J1939DcmDiagnosticReadiness2Type, AUTOMATIC, DEM_J1939DCM_DATA)  DataValue,                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  uint8 NodeAddress                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DataValue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) >= DEM_CFG_J1939_NODE_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    DEM_IGNORE_UNUSED_ARGUMENT(DataValue)                                                                                        /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(NodeAddress)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMREADDIAGNOSTICREADINESS2_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif
  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_READINESS2 == STD_ON) */

#if (DEM_CFG_SUPPORT_J1939_READINESS3 == STD_ON)                                                                                 /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_J1939DcmReadDiagnosticReadiness3
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_J1939DcmReadDiagnosticReadiness3(                                                                                            /* PRQA S 0777 */ /* MD_DEM_5.1 */
  P2VAR(Dem_J1939DcmDiagnosticReadiness3Type, AUTOMATIC, DEM_J1939DCM_DATA)  DataValue,                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  uint8 NodeAddress                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DataValue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_J1939_NODES == STD_ON)
  if (Dem_Cfg_FindJ1939NodeFromNmNode(NodeAddress) <= DEM_CFG_J1939_NODE_INVALID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    DEM_IGNORE_UNUSED_ARGUMENT(DataValue)                                                                                        /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(NodeAddress)                                                                                      /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_J1939DCMREADDIAGNOSTICREADINESS3_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif
  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_READINESS3 == STD_ON) */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_J1939DCMAPI_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_J1939DcmAPI_Implementation.h
 *********************************************************************************************************************/
