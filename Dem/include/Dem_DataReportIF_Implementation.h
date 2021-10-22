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
/*! \addtogroup Dem_DataReportIF
 *  \{
 *  \file       Dem_DataReportIF_Implementation.h
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

#if !defined (DEM_DATAREPORTIF_IMPLEMENTATION_H)
#define DEM_DATAREPORTIF_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DataReportIF_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_SnapshotEntry_Implementation.h"
#include "Dem_ExtendedEntry_Implementation.h"
#include "Dem_MemStorageManager_Implementation.h"
#include "Dem_ExtDataElementIF_Implementation.h"

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

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DataReportIF_Properties
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
 * \addtogroup Dem_DataReportIF_Private
 * \{
 */

#if ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 % Dem_DataReportIF_SkipDid
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DataReportIF_SkipDid(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  )
{
  Dem_Cfg_DidDataIterType lDataIter;

  /* Iterate all data elements in the DID */
  for (Dem_Cfg_DidDataIterInit(DidIndex, &lDataIter);                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_DidDataIterExists(&lDataIter) == TRUE;                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_DidDataIterNext(&lDataIter))                                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DataIndexType lDataIndex;
    lDataIndex = Dem_Cfg_DidDataIterGet(&lDataIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Cfg_DataIsStoredInNV(lDataIndex) == TRUE)
    {
      switch (Dem_Cfg_DataCallbackType(lDataIndex))
      {
      case DEM_CFG_DATA_FROM_ROOTCAUSE_EVENTID:
      case DEM_CFG_DATA_FROM_CBK:
      case DEM_CFG_DATA_FROM_CBK_WITH_EVENTID:
      case DEM_CFG_DATA_FROM_SR_PORT_BOOLEAN:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT8:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT8:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT16:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT16_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT16:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT16_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT32:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT32_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT32:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT32_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT8_N:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT8_N:
            CopyDidInfoPtr->ReadIndex += Dem_Cfg_DataSize(lDataIndex);                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        break;

      default:
        break;
      }
    }
  }
}
#endif /* (DEM_CFG_SUPPORT_SRECS == STD_ON) || (DEM_CFG_SUPPORT_OBDII == STD_ON) || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) */

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_DataReportIF_CopyReplacementBytes
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyReplacementBytes(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CopyDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CopyDidInfoPtr->BufferSize)
  {
    Dem_MemSet(&CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex],                                                   /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
                DEM_DATAREPORTIF_INVALID_DATA_PATTERN,
                Dem_Cfg_DataSize(DataIndex));
    CopyDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif

/* ------------------------------------------------------------------------- */
#if (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON)
/* ****************************************************************************
% Dem_DataReportIF_CopyStoredUserData
*****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyStoredUserData(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  Dem_Internal_AssertReturnValue(CopyDidInfoPtr->SourceBuffer != NULL_PTR, DEM_E_INCONSISTENT_STATE, FALSE)

  if ((CopyDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CopyDidInfoPtr->BufferSize)
  {
    Dem_MemCpy(&CopyDidInfoPtr->DestinationBuffer[CopyDidInfoPtr->WriteIndex],                                                   /* PRQA S 0311, 0602*/ /* MD_DEM_11.5, MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
               &CopyDidInfoPtr->SourceBuffer[CopyDidInfoPtr->ReadIndex],
               Dem_Cfg_DataSize(DataIndex));                                                                                     /* PRQA S 3109 */ /* MD_MSR_14.3 */
    CopyDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    CopyDidInfoPtr->ReadIndex += Dem_Cfg_DataSize(DataIndex);                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return TRUE;
}
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 % Dem_DataReportIF_CopyStoredDataElement
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
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyStoredDataElement(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  boolean lReturnValue;

  switch (Dem_Cfg_DataCallbackType(DataIndex))
  {
# if (DEM_CFG_DATA_AGINGCTR == STD_ON)
  case DEM_CFG_DATA_FROM_AGINGCTR:
    lReturnValue = Dem_Data_CopyUpwardsAgingCounter(CopyDidInfoPtr);                                                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_OCCCTR == STD_ON)
  case DEM_CFG_DATA_FROM_OCCCTR:
    lReturnValue = Dem_Data_Copy1ByteOccurrenceCounter(CopyDidInfoPtr);                                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_OCCCTR_2BYTE == STD_ON)
  case DEM_CFG_DATA_FROM_OCCCTR_2BYTE:
    lReturnValue = Dem_Data_Copy2ByteOccurrenceCounter(CopyDidInfoPtr);                                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_OVFLIND == STD_ON)
  case DEM_CFG_DATA_FROM_OVFLIND:
    lReturnValue = Dem_Data_CopyOverflowIndication(CopyDidInfoPtr);                                                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_SIGNIFICANCE == STD_ON)
  case DEM_CFG_DATA_FROM_SIGNIFICANCE:
    lReturnValue = Dem_Data_CopyEventSignificance(CopyDidInfoPtr);                                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_PRIORITY == STD_ON)
  case DEM_CFG_DATA_FROM_PRIORITY:
    lReturnValue = Dem_Data_CopyEventPriority(CopyDidInfoPtr);                                                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_AGINGCTR_INVERTED == STD_ON)
  case DEM_CFG_DATA_FROM_AGINGCTR_INVERTED:
    lReturnValue = Dem_Data_CopyDownwardsAgingCounter(CopyDidInfoPtr);                                                           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_MAX_FDC_SINCE_LAST_CLEAR == STD_ON)
  case DEM_CFG_DATA_FROM_MAX_FDC_SINCE_LAST_CLEAR:
    lReturnValue = Dem_Data_CopyMaxFdcSinceLastClear(CopyDidInfoPtr);                                                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_MAX_FDC_DURING_CURRENT_CYCLE == STD_ON)
  case DEM_CFG_DATA_FROM_MAX_FDC_DURING_CURRENT_CYCLE:
    lReturnValue = Dem_Data_CopyMaxFdcThisCycle(CopyDidInfoPtr);                                                                 /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_CYCLES_SINCE_LAST_FAILED == STD_ON)
  case DEM_CFG_DATA_FROM_CYCLES_SINCE_LAST_FAILED:
    lReturnValue = Dem_Data_CopyCyclesSinceLastFailed(CopyDidInfoPtr);                                                           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_CYCLES_SINCE_FIRST_FAILED == STD_ON)
  case DEM_CFG_DATA_FROM_CYCLES_SINCE_FIRST_FAILED:
    lReturnValue = Dem_Data_CopyCyclesSinceFirstFailed(CopyDidInfoPtr);                                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_FAILED_CYCLES == STD_ON)
  case DEM_CFG_DATA_FROM_FAILED_CYCLES:
    lReturnValue = Dem_Data_CopyFailedCycles(CopyDidInfoPtr);                                                                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_CONSECUTIVE_FAILED_CYCLES == STD_ON)
  case DEM_CFG_DATA_FROM_CONSECUTIVE_FAILED_CYCLES:
    lReturnValue = Dem_Data_CopyConsecutiveFailedCycles(CopyDidInfoPtr);                                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_CYCLES_TESTED_SINCE_FIRST_FAILED == STD_ON)
  case DEM_CFG_DATA_FROM_CYCLES_TESTED_SINCE_FIRST_FAILED:
    lReturnValue = Dem_Data_CopyCyclesTestedSinceFirstFailed(CopyDidInfoPtr);                                                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_CYCLES_TESTED_SINCE_LAST_FAILED == STD_ON)
  case DEM_CFG_DATA_FROM_CYCLES_TESTED_SINCE_LAST_FAILED:
    lReturnValue = Dem_Data_CopyCyclesTestedSinceLastFailed(CopyDidInfoPtr);                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_HEALINGCTR_DOWNCNT == STD_ON)
  case DEM_CFG_DATA_FROM_HEALINGCTR_DOWNCNT:
    lReturnValue = Dem_Data_CopyHealingCounterDownwards(CopyDidInfoPtr);                                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON)
  case DEM_CFG_DATA_FROM_ROOTCAUSE_EVENTID:
    lReturnValue = Dem_Data_CopyRootCauseEventId(CopyDidInfoPtr);                                                                /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_OBDDTC == STD_ON)
  case DEM_CFG_DATA_FROM_OBDDTC:
    lReturnValue = Dem_Data_CopyEventObdDtc(CopyDidInfoPtr);                                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_OBDDTC_3BYTE == STD_ON)
  case DEM_CFG_DATA_FROM_OBDDTC_3BYTE:
    lReturnValue = Dem_Data_CopyEventObdDtc_3Byte(CopyDidInfoPtr);                                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_OBD_RATIO == STD_ON)
  case DEM_CFG_DATA_FROM_OBD_RATIO:
    lReturnValue = Dem_Data_CopyEventObdRatio(CopyDidInfoPtr);                                                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

# if (DEM_CFG_DATA_CURRENT_FDC == STD_ON)
  case DEM_CFG_DATA_FROM_CURRENT_FDC:
    lReturnValue = Dem_Data_CopyCurrentFdc(CopyDidInfoPtr);                                                                      /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

  case DEM_CFG_DATA_FROM_CBK:
  case DEM_CFG_DATA_FROM_CBK_WITH_EVENTID:
  case DEM_CFG_DATA_FROM_SR_PORT_BOOLEAN:
  case DEM_CFG_DATA_FROM_SR_PORT_SINT8:
  case DEM_CFG_DATA_FROM_SR_PORT_UINT8:
  case DEM_CFG_DATA_FROM_SR_PORT_SINT16:
  case DEM_CFG_DATA_FROM_SR_PORT_SINT16_INTEL:
  case DEM_CFG_DATA_FROM_SR_PORT_UINT16:
  case DEM_CFG_DATA_FROM_SR_PORT_UINT16_INTEL:
  case DEM_CFG_DATA_FROM_SR_PORT_SINT32:
  case DEM_CFG_DATA_FROM_SR_PORT_SINT32_INTEL:
  case DEM_CFG_DATA_FROM_SR_PORT_UINT32:
  case DEM_CFG_DATA_FROM_SR_PORT_UINT32_INTEL:
  case DEM_CFG_DATA_FROM_SR_PORT_SINT8_N:
  case DEM_CFG_DATA_FROM_SR_PORT_UINT8_N:
    lReturnValue = Dem_DataReportIF_CopyStoredUserData(CopyDidInfoPtr, DataIndex);                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  default:
    lReturnValue = FALSE;
    break;
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 % Dem_DataReportIF_CopyDid
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyDid(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  )
{
  boolean lReturnValue;
  Dem_Cfg_DidDataIterType lDataIter;

  lReturnValue = TRUE;
  for (Dem_Cfg_DidDataIterInit(DidIndex, &lDataIter);                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Cfg_DidDataIterExists(&lDataIter) == TRUE;                                                                               /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Cfg_DidDataIterNext(&lDataIter))                                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DataIndexType lDataIndex;
    lDataIndex = Dem_Cfg_DidDataIterGet(&lDataIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Cfg_DataIsStoredInNV(lDataIndex) == TRUE)
    {
      lReturnValue = (boolean)(Dem_DataReportIF_CopyStoredDataElement(CopyDidInfoPtr, lDataIndex) & lReturnValue);               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
    else
    {
      lReturnValue = (boolean)(Dem_ExtDataElementIF_CollectDataElement(CopyDidInfoPtr, lDataIndex) & lReturnValue);              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_DataReportIF_CopyDid_NoInternalData
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
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyDid_NoInternalData(
  CONST(Dem_DataReportIF_CopyDidInfoPtrType, AUTOMATIC)  CopyDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  )
{
  boolean lReturnValue;
  Dem_Cfg_DidDataIterType lDataIter;

  lReturnValue = TRUE;

  for (Dem_Cfg_DidDataIterInit(DidIndex, &lDataIter);                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Cfg_DidDataIterExists(&lDataIter) == TRUE;                                                                               /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Cfg_DidDataIterNext(&lDataIter))                                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DataIndexType lDataIndex;
    lDataIndex = Dem_Cfg_DidDataIterGet(&lDataIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Cfg_DataIsStoredInNV(lDataIndex) == TRUE)
    {
      switch (Dem_Cfg_DataCallbackType(lDataIndex))
      {
      case DEM_CFG_DATA_FROM_CBK:
      case DEM_CFG_DATA_FROM_CBK_WITH_EVENTID:
      case DEM_CFG_DATA_FROM_SR_PORT_BOOLEAN:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT8:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT8:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT16:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT16_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT16:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT16_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT32:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT32_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT32:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT32_INTEL:
      case DEM_CFG_DATA_FROM_SR_PORT_SINT8_N:
      case DEM_CFG_DATA_FROM_SR_PORT_UINT8_N:
        lReturnValue = (boolean)(Dem_DataReportIF_CopyStoredUserData(CopyDidInfoPtr, lDataIndex) & lReturnValue);                /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        break;

      default:
        lReturnValue = (boolean)(Dem_DataReportIF_CopyReplacementBytes(CopyDidInfoPtr, lDataIndex) & lReturnValue);              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        break;
      }
    }
    else
    {
      lReturnValue = (boolean)(Dem_ExtDataElementIF_CollectDataElement(CopyDidInfoPtr, lDataIndex) & lReturnValue);              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

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
 * \addtogroup Dem_DataReportIF_Public
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && ((DEM_CFG_SUPPORT_SRECS == STD_ON) || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 % Dem_DataReportIF_SRecCopyData
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DataReportIF_SRecCopyData(
  CONST(Dem_SharedDataPtrType, AUTOMATIC)  DestBuffer,
  CONST(Dem_ConstSharedDataPtrType, AUTOMATIC)  SourceBuffer,
  CONST(uint16, AUTOMATIC)  BufferSize,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  )
{
  if (BufferSize > 0)
  {
    uint16 lDidCount;
    Dem_Cfg_EventDidIterType lDidIter;
    Dem_DataReportIF_CopyDidInfoType lCopyDidInfo;

    /* Initialize a CopyDid Context. */
    lCopyDidInfo.DestinationBuffer = DestBuffer;
    lCopyDidInfo.BufferSize        = BufferSize;
    lCopyDidInfo.WriteIndex        = 1;
    lCopyDidInfo.SourceBuffer      = SourceBuffer;
    lCopyDidInfo.ReadIndex         = 0;
    lCopyDidInfo.MemoryEntryId     = MemoryEntryId;
    lCopyDidInfo.EventId           = EventId;

    /* Initialize number of DIDs */
    lDidCount = 0;
    for (Dem_Cfg_EventDidIterInit(EventId, &lDidIter);                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_EventDidIterExists(&lDidIter) == TRUE;                                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_EventDidIterNext(&lDidIter))                                                                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      if (lCopyDidInfo.BufferSize > (lCopyDidInfo.WriteIndex + DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID))
      {
        Dem_Cfg_DidIndexType lDidIndex;
        lDidIndex = Dem_Cfg_EventDidIterGet(&lDidIter);                                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */

        ++lDidCount;

        lCopyDidInfo.DestinationBuffer[lCopyDidInfo.WriteIndex + 0] = Dem_GetHiByte(Dem_Cfg_DidNumber(lDidIndex));               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        lCopyDidInfo.DestinationBuffer[lCopyDidInfo.WriteIndex + 1] = Dem_GetLoByte(Dem_Cfg_DidNumber(lDidIndex));               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        lCopyDidInfo.WriteIndex += DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID;

        {
          (void)Dem_DataReportIF_CopyDid(&lCopyDidInfo, lDidIndex);                                                              /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
        }
      }
    }

    /* Set the DID count to 0 in case of more than 255 DIDs. */
    if (lDidCount > 255)
    {
      lCopyDidInfo.DestinationBuffer[0] = 0;                                                                                     /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    }
    else
    {
      lCopyDidInfo.DestinationBuffer[0] = Dem_GetLoByte(lDidCount);                                                              /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                        /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 % Dem_DataReportIF_WWHOBDFreezeFrameCopyData
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
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DataReportIF_WWHOBDFreezeFrameCopyData(
  CONST(Dem_SharedDataPtrType, AUTOMATIC)  DestBuffer,
  CONST(Dem_ConstSharedDataPtrType, AUTOMATIC)  SourceBuffer,
  CONST(uint16, AUTOMATIC)  BufferSize,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId)
{
  if (BufferSize > 0)
  {
    uint16 lDidCount;
    Dem_Cfg_EventObdDidIterType lDidIter;
    Dem_DataReportIF_CopyDidInfoType lCopyDidInfo;

    /* Initialize a CopyDid Context. */
    lCopyDidInfo.DestinationBuffer = DestBuffer;
    lCopyDidInfo.BufferSize        = BufferSize;
    lCopyDidInfo.WriteIndex        = 1;
    lCopyDidInfo.SourceBuffer      = SourceBuffer;
    lCopyDidInfo.ReadIndex         = 0;
    lCopyDidInfo.MemoryEntryId     = MemoryEntryId;
    lCopyDidInfo.EventId           = EventId;

    lDidCount = 0;
     
    for (Dem_Cfg_EventObdDidIterInit(EventId, &lDidIter);                                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_EventObdDidIterExists(&lDidIter) == TRUE;                                                                       /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_EventObdDidIterNext(&lDidIter))                                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      if (lCopyDidInfo.BufferSize > (lCopyDidInfo.WriteIndex + DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID))
      {
        Dem_Cfg_DidIndexType lDidIndex;
        lDidIndex = Dem_Cfg_EventObdDidIterGet(&lDidIter);                                                                       /* SBSW_DEM_CALL_ITERATOR_POINTER */

        ++lDidCount;

        lCopyDidInfo.DestinationBuffer[lCopyDidInfo.WriteIndex + 0] = Dem_GetHiByte(Dem_Cfg_DidNumber(lDidIndex));               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        lCopyDidInfo.DestinationBuffer[lCopyDidInfo.WriteIndex + 1] = Dem_GetLoByte(Dem_Cfg_DidNumber(lDidIndex));               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        lCopyDidInfo.WriteIndex += DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID;
        (void)Dem_DataReportIF_CopyDid(&lCopyDidInfo, lDidIndex);                                                                /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
      }
    }

    /* Set the DID count to 0 in case of more than 255 DIDs. */
    if (lDidCount > 255)
    {
      lCopyDidInfo.DestinationBuffer[0] = 0;                                                                                     /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    }
    else
    {
      lCopyDidInfo.DestinationBuffer[0] = Dem_GetLoByte(lDidCount);                                                              /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    }
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                         /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 % Dem_DataReportIF_ObdIIFreezeFrameCopyPidData
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_ObdIIFreezeFrameCopyPidData(
  CONST(uint8, AUTOMATIC)  FreezeFrameIndex,
  CONST(uint8, AUTOMATIC)  Pid,
  CONST(uint8, AUTOMATIC)  DataElementIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  Buffer,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  BufSize
  )
{
  uint16_least              lSrcBufferOffset;
  Dem_Cfg_GlobalPidIterType lPidIter;
  Std_ReturnType            lReturnValue;

  lSrcBufferOffset = 0;
  lReturnValue     = E_NOT_OK;

  for (Dem_Cfg_GlobalPidIterInit(&lPidIter);                                                                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_GlobalPidIterExists(&lPidIter) == TRUE;                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_GlobalPidIterNext(&lPidIter))                                                                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */
  { /* look for the requested PID */
    Dem_Cfg_DidIndexType lDidIndex;
    lDidIndex = Dem_Cfg_GlobalPidIterGet(&lPidIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

    /* Check for the requested PID -> the PID value stored in the configuration is from type uint16 with a
       leading 0xF4 which is only used from UDS services */
    if (Pid == Dem_GetLoByte(Dem_Cfg_DidNumber(lDidIndex)))
    {
      /* This is the requested PID, now find the requested data element */
      Dem_Cfg_DidDataIterType lDataIter;
      uint8 lDataElementIndex;

      /* Each DID consists of 1-* data elements. */
      lDataElementIndex = 0;
      for (Dem_Cfg_DidDataIterInit(lDidIndex, &lDataIter);                                                                       /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_DidDataIterExists(&lDataIter) == TRUE;                                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_DidDataIterNext(&lDataIter))                                                                                  /* SBSW_DEM_CALL_ITERATOR_POINTER */
      { /* look for the requested data element of the PID */
        Dem_Cfg_DataIndexType lDataIndex;
        uint8 lElementSize;

        lDataIndex = Dem_Cfg_DidDataIterGet(&lDataIter);                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
        lElementSize = Dem_Cfg_DataSize(lDataIndex);
        if (DataElementIndex == lDataElementIndex)
        {
          /* This is the requested element index, check if data fits into the provided buffer */
          if (lElementSize <= *BufSize)
          {
            uint8* lObdFreezeFrameDataPtr;

            lObdFreezeFrameDataPtr = Dem_Mem_FreezeFrameObdIIGetDataPtr(FreezeFrameIndex);

            Dem_MemCpy(Buffer, &lObdFreezeFrameDataPtr[lSrcBufferOffset], lElementSize);                                         /* PRQA S 0602, 3109 */ /* MD_DEM_20.2, MD_MSR_14.3 */
            *BufSize = lElementSize;

            lReturnValue = E_OK;
          }
          /* data element of PID identified, leave loop */
          break;
        }
        ++lDataElementIndex;
        lSrcBufferOffset = (uint16_least)(lSrcBufferOffset + lElementSize);
      }
      /* PID identified, leave loop */
      break;
    }
    lSrcBufferOffset = (uint16_least)(lSrcBufferOffset + Dem_Cfg_DidSize(lDidIndex));
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                         /* COV_MSR_UNSUPPORTED XF tf xf */
/* ****************************************************************************
 % Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData
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
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData(
  CONST(uint8, AUTOMATIC)  FreezeFrameIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  Buffer,
  CONST(uint16, AUTOMATIC)  BufferSize
  )
{
  if (BufferSize > 0)
  {
    uint16 lDidCount;
    Dem_Cfg_GlobalPidIterType lPidIter;
    Dem_DataReportIF_CopyDidInfoType  lCopyDidInfo;

    /* Initialize a CopyDid Context. Reserve one byte at the start for the DID count. */
    lCopyDidInfo.DestinationBuffer = Buffer;
    lCopyDidInfo.BufferSize = BufferSize;
    lCopyDidInfo.WriteIndex = 1;
    lCopyDidInfo.SourceBuffer = (Dem_ConstSharedDataPtrType)Dem_Mem_FreezeFrameObdIIGetDataPtr(FreezeFrameIndex);
    lCopyDidInfo.ReadIndex = 0;
    lCopyDidInfo.MemoryEntryId = DEM_MEMORYENTRY_HANDLE_INVALID;
    lCopyDidInfo.EventId = DEM_EVENT_INVALID;

    /* initialize PID counter */
    lDidCount = 0;

    for (Dem_Cfg_GlobalPidIterInit(&lPidIter);                                                                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_GlobalPidIterExists(&lPidIter) == TRUE;                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_GlobalPidIterNext(&lPidIter))                                                                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      Dem_Cfg_DidIndexType lDidIndex;
      lDidIndex = Dem_Cfg_GlobalPidIterGet(&lPidIter);                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */

      /* Count the PIDs */
      ++lDidCount;

      if (lCopyDidInfo.BufferSize > (lCopyDidInfo.WriteIndex + DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID))
      {
        /* Store the UDS DID number 0xF4 <PID> into the destination buffer */
        lCopyDidInfo.DestinationBuffer[lCopyDidInfo.WriteIndex + 0] = 0xf4U;                                                     /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        lCopyDidInfo.DestinationBuffer[lCopyDidInfo.WriteIndex + 1] = Dem_GetLoByte(Dem_Cfg_DidNumber(lDidIndex));               /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
        lCopyDidInfo.WriteIndex += DEM_DATAREPORTIF_ADDITIONAL_BYTES_PER_DID;

        /* Copy the PID data into the destination buffer */
        (void)Dem_DataReportIF_CopyDid(&lCopyDidInfo, lDidIndex);                                                                /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
      }
    }
    /* Store the number of PIDs to the first byte of the destination buffer.
     * Set the DID count to 0 in case of more than 255 DIDs. */
    if (lDidCount > 255)
    {
      lCopyDidInfo.DestinationBuffer[0] = 0;                                                                                     /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    }
    else
    {
      lCopyDidInfo.DestinationBuffer[0] = Dem_GetLoByte(lDidCount);                                                              /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    }
  }
}
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON) */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_DataReportIF_CopyExtendedDataRecord
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_DataReportIF_CopyExtendedDataRecord(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize
  )
{
  boolean lReturnValue;
  uint8 lERecType;
  Dem_Cfg_ERecIndexType lCfgERecIndex;
  Dem_DataReportIF_CopyDidInfoType lCopyDidInfo;
  
  lCfgERecIndex = Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(ExtendedEntryIter);
  lERecType = Dem_Cfg_ERecType(lCfgERecIndex);

  lCopyDidInfo.DestinationBuffer = DestBuffer;
  lCopyDidInfo.BufferSize = *BufSize;
  lCopyDidInfo.WriteIndex = 0;
  lCopyDidInfo.EventId = ExtendedEntryIter->EventId;
  lCopyDidInfo.ReadIndex = 0;

  /* prepare negative result */
  *BufSize = 0;                                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  lReturnValue =  FALSE;

# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
  if (lERecType == DEM_CFG_EREC_TYPE_USER)
  {
    lCopyDidInfo.SourceBuffer = Dem_ExtendedEntry_IteratorGetExtendedRecordDataConstPtr(ExtendedEntryIter);
    lCopyDidInfo.MemoryEntryId = ExtendedEntryIter->MemoryEntryId;
  }
  else
# endif
  if (lERecType == DEM_CFG_EREC_TYPE_INTERNAL)
  {
    lCopyDidInfo.SourceBuffer = (Dem_ConstSharedDataPtrType)NULL_PTR;
    lCopyDidInfo.MemoryEntryId = ExtendedEntryIter->MemoryEntryId;
  }
  else
  {/*lERecType == DEM_CFG_EREC_TYPE_GLOBAL*/
    lCopyDidInfo.SourceBuffer = (Dem_ConstSharedDataPtrType)NULL_PTR;
    lCopyDidInfo.MemoryEntryId = DEM_MEMORYENTRY_HANDLE_INVALID;
  }

  if (Dem_DataReportIF_CopyDid(&lCopyDidInfo, Dem_Cfg_ERecDid(lCfgERecIndex)) == TRUE)                                           /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
  {
    *BufSize = Dem_Cfg_DidSize(Dem_Cfg_ERecDid(lCfgERecIndex));                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = TRUE;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
% Dem_DataReportIF_CopyDidFromWwhObdFreezeFrame
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_CopyDidFromWwhObdFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint16, AUTOMATIC)  DataId,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC) MemoryIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_EventObdDidIterType   lDidIter;
  Dem_DataReportIF_CopyDidInfoType lCopyDidInfo;
  lCopyDidInfo.DestinationBuffer = DestBuffer;
  lCopyDidInfo.BufferSize = *BufSize;
  lCopyDidInfo.ReadIndex = 0;

  *BufSize = 0;                                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  lReturnValue = DEM_NO_SUCH_ELEMENT;

  for (Dem_Cfg_EventObdDidIterInit(EventId, &lDidIter);                                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Cfg_EventObdDidIterExists(&lDidIter) == TRUE;                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Cfg_EventDidIterNext(&lDidIter))                                                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DidIndexType lDidIndex;
    lDidIndex = Dem_Cfg_EventDidIterGet(&lDidIter);                                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Cfg_DidNumber(lDidIndex) == DataId)
    {
      if (Dem_Cfg_DidSize(lDidIndex) <= lCopyDidInfo.BufferSize)
      {
        lCopyDidInfo.WriteIndex = 0;
        lCopyDidInfo.MemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(MemoryIndex);
        lCopyDidInfo.SourceBuffer = (Dem_ConstSharedDataPtrType)Dem_MemoryEntry_GetWwhObdFreezeFrameDataPtr(lCopyDidInfo.MemoryEntryId);
        lCopyDidInfo.EventId = EventId;

        (void)Dem_DataReportIF_CopyDid(&lCopyDidInfo, lDidIndex);                                                                /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
        *BufSize = Dem_Cfg_DidSize(lDidIndex);                                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = E_OK;
      }
      else
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      break;
    }
    else
    { /* not the requested DID */
      Dem_DataReportIF_SkipDid(&lCopyDidInfo, lDidIndex);                                                                        /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
    }
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_DataReportIF_CopyDidTimeSeriesSRec
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
Dem_DataReportIF_CopyDidTimeSeriesSRec(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  Entry,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_EventDidIterType lDidIter;
  Dem_DataReportIF_CopyDidInfoType lCopyDidInfo;
  uint8 lPrimaryIndex;

  lPrimaryIndex = Dem_MemStorageManager_MemoryFindIndex(
    Dem_MemStorageManager_MemoryInfoInit(DEM_CFG_MEMORYID_PRIMARY),
    Entry->EventId
    );                                                                                                                           /* SBSW_DEM_CALL_MEMORYINFO_POINTER */

  /* Initialize a CopyDid Context. */
  lCopyDidInfo.DestinationBuffer = DestBuffer;
  lCopyDidInfo.BufferSize = *BufSize;
  lCopyDidInfo.WriteIndex = 0;

  if (RecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST)
  {
    lCopyDidInfo.SourceBuffer = 
      Dem_Mem_TimeSeriesEntryGetNormalConstDataPtr(Entry, RecordNumber - DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST);           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
# if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
  else
  {
    lCopyDidInfo.SourceBuffer = 
      Dem_Mem_TimeSeriesEntryGetFastConstDataPtr(Entry, RecordNumber - DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST);               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
# endif
  lCopyDidInfo.ReadIndex = 0;

  if (lPrimaryIndex == DEM_MEM_INVALID_MEMORY_INDEX)
  {
    lCopyDidInfo.MemoryEntryId = DEM_MEMORYENTRY_HANDLE_INVALID;
    lCopyDidInfo.EventId = DEM_EVENT_INVALID;
  }
  else
  {
    lCopyDidInfo.MemoryEntryId = Dem_MemStorageManager_GetMemoryEntryId(lPrimaryIndex);
    lCopyDidInfo.EventId = Entry->EventId;
  }
  *BufSize = 0;                                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  lReturnValue = DEM_NO_SUCH_ELEMENT;

  for (Dem_Cfg_EventDidIterInit(Entry->EventId, &lDidIter);                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_EventDidIterExists(&lDidIter) == TRUE;                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_EventDidIterNext(&lDidIter))                                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DidIndexType lDidIndex;
    lDidIndex = Dem_Cfg_EventDidIterGet(&lDidIter);                                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Cfg_DidNumber(lDidIndex) == DataId)
    {
      uint16 DataSize;
      DataSize = Dem_Cfg_DidSize(lDidIndex);
      if (DataSize <= lCopyDidInfo.BufferSize)
      {
        if (lCopyDidInfo.EventId == DEM_EVENT_INVALID)
        {                                                                                                                        /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
          (void)Dem_DataReportIF_CopyDid_NoInternalData(&lCopyDidInfo, lDidIndex);                                               /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
        }
        else
        {                                                                                                                        /* PRQA S 0715 */ /* MD_MSR_1.1_715 */
          (void)Dem_DataReportIF_CopyDid(&lCopyDidInfo, lDidIndex);                                                              /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
        }
        *BufSize = DataSize;                                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = E_OK;
      }
      else
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      break;
    }
    else
    { /* not the requested DID */
      Dem_DataReportIF_SkipDid(&lCopyDidInfo, lDidIndex);                                                                        /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_SRECS == STD_ON)
/* ****************************************************************************
 % Dem_DataReportIF_CopyDidSRec
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_CopyDidSRec(
  CONSTP2CONST(Dem_SnapshotEntry_IterType, AUTOMATIC, AUTOMATIC)  SnapshotEntry,
  CONST(uint16, AUTOMATIC)  DataId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;

  Dem_Cfg_EventDidIterType lDidIter;
  Dem_DataReportIF_CopyDidInfoType lCopyDidInfo;

  lCopyDidInfo.DestinationBuffer = DestBuffer;
  lCopyDidInfo.BufferSize        = *BufSize;
  lCopyDidInfo.WriteIndex        = 0;
  lCopyDidInfo.SourceBuffer      = Dem_SnapshotEntry_IteratorGetSnapshotRecordDataConstPtr(SnapshotEntry);
  lCopyDidInfo.ReadIndex         = 0;
  lCopyDidInfo.MemoryEntryId     = Dem_SnapshotEntry_IteratorGetMemoryEntryHandle(SnapshotEntry);
  lCopyDidInfo.EventId           = Dem_MemoryEntry_GetEventId(lCopyDidInfo.MemoryEntryId);
  *BufSize = 0;                                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  lReturnValue = DEM_NO_SUCH_ELEMENT;

  for (Dem_Cfg_EventDidIterInit(lCopyDidInfo.EventId, &lDidIter);                                                                /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_EventDidIterExists(&lDidIter) == TRUE;                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_EventDidIterNext(&lDidIter))                                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DidIndexType lDidIndex;
    lDidIndex = Dem_Cfg_EventDidIterGet(&lDidIter);                                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Cfg_DidNumber(lDidIndex) == DataId)
    {
      uint16 DataSize;
      DataSize = Dem_Cfg_DidSize(lDidIndex);
      if (DataSize <= lCopyDidInfo.BufferSize)
      {
        (void)Dem_DataReportIF_CopyDid(&lCopyDidInfo, lDidIndex);                                                                /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
        *BufSize = DataSize;                                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = E_OK;
      }
      else
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_err */
    }
    else
    { /* not the requested DID */
      Dem_DataReportIF_SkipDid(&lCopyDidInfo, lDidIndex);                                                                        /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED XF */
/* ****************************************************************************
 % Dem_DataReportIF_CopyPidFromObdIIFreezeFrame
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
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DataReportIF_CopyPidFromObdIIFreezeFrame(
  CONST(uint16, AUTOMATIC)  DataId,
  CONST(Dem_ConstSharedDataPtrType, AUTOMATIC)  SourceBuffer,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_GlobalPidIterType  lPidIter;
  Dem_DataReportIF_CopyDidInfoType lCopyDidInfo;

  lCopyDidInfo.DestinationBuffer = DestBuffer;
  lCopyDidInfo.BufferSize        = *BufSize;
  lCopyDidInfo.WriteIndex        = 0;
  lCopyDidInfo.SourceBuffer      = SourceBuffer;
  lCopyDidInfo.ReadIndex         = 0;
  lCopyDidInfo.MemoryEntryId     = DEM_MEMORYENTRY_HANDLE_INVALID;
  lCopyDidInfo.EventId           = DEM_EVENT_INVALID;
  *BufSize = 0;                                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  lReturnValue = DEM_NO_SUCH_ELEMENT;

  for (Dem_Cfg_GlobalPidIterInit(&lPidIter);                                                                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */
        Dem_Cfg_GlobalPidIterExists(&lPidIter) == TRUE;                                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
        Dem_Cfg_GlobalPidIterNext(&lPidIter))                                                                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DidIndexType lDidIndex;
    lDidIndex = Dem_Cfg_GlobalPidIterGet(&lPidIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_GetLoByte(Dem_Cfg_DidNumber(lDidIndex)) == Dem_GetLoByte(DataId))
    {
      uint16 DataSize;
      DataSize = Dem_Cfg_DidSize(lDidIndex);
      if (DataSize <= lCopyDidInfo.BufferSize)
      {
        (void)Dem_DataReportIF_CopyDid(&lCopyDidInfo, lDidIndex);                                                                /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
        *BufSize = DataSize;                                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = E_OK;
      }
      else
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_err */
    }
    else
    { /* not the requested DID */
      Dem_DataReportIF_SkipDid(&lCopyDidInfo, lDidIndex);                                                                        /* SBSW_DEM_POINTER_LOCAL_COPYDIDINFO */
    }
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_OBDII == STD_ON) */

/* ------------------------------------------------------------------------- */
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DATAREPORTIF_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DataReportIF_Implementation.h
 *********************************************************************************************************************/
