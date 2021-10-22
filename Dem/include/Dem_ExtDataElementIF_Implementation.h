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
/*! \addtogroup Dem_ExtDataElementIF
 *  \{
 *  \file       Dem_ExtDataElementIF_Implementation.h
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

#if !defined (DEM_EXTDATAELEMENTIF_IMPLEMENTATION_H)
#define DEM_EXTDATAELEMENTIF_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_ExtDataElementIF_Interface.h"

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
 * \addtogroup Dem_ExtDataElementIF_Properties
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
 * \addtogroup Dem_ExtDataElementIF_Private
 * \{
 */
#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectUserData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectUserData(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ( (DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                         /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || ( (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_CBK)
      &&   (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_UINT8_N) )
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR) )
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      if ((*((Dem_ReadDataStandardFPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(                                                     /* PRQA S 0313 */ /* MD_DEM_11.1 */ /* SBSW_DEM_CALL_DIDINFO_DESTINATIONBUFFER */
                &CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex]) == E_NOT_OK)
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
                   DEM_EXTDATAELEMENTIF_INVALID_DATA_PATTERN,
                   Dem_Cfg_DataSize(DataIndex));                                                                                 /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectCSDataWithEventId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectCSDataWithEventId(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ( (DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                         /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_CBK_WITH_EVENTID)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      if ((*((Dem_ReadDataExtendedFPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(                                                     /* PRQA S 0313 */ /* MD_DEM_11.1 */ /* SBSW_DEM_CALL_DIDINFO_DESTINATIONBUFFER */
                CollectDidInfoPtr->EventId,
                &CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex]) == E_NOT_OK)
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
                   DEM_EXTDATAELEMENTIF_INVALID_DATA_PATTERN,
                   Dem_Cfg_DataSize(DataIndex));                                                                                 /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Boolean
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
Dem_ExtDataElementIF_CollectSRData_Boolean(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_BOOLEAN)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      boolean lData;
      if ((*((Dem_ReadDataSRBooleanFPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_EXTDATAELEMENTIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = (uint8)lData;
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Sint8
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
Dem_ExtDataElementIF_CollectSRData_Sint8(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_SINT8)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      sint8 lData;
      if ((*((Dem_ReadDataSRSint8FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                  /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_EXTDATAELEMENTIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = (uint8)lData;
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Uint8
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
Dem_ExtDataElementIF_CollectSRData_Uint8(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_UINT8)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      uint8 lData;
      if ((*((Dem_ReadDataStandardFPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_EXTDATAELEMENTIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = lData;
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Sint16
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
Dem_ExtDataElementIF_CollectSRData_Sint16(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_SINT16)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      sint16 lData;
      if ((*((Dem_ReadDataSRSint16FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_EXTDATAELEMENTIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetLoByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Sint16_Intel
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
Dem_ExtDataElementIF_CollectSRData_Sint16_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_SINT16_INTEL)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      sint16 lData;
      if ((*((Dem_ReadDataSRSint16FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_EXTDATAELEMENTIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetHiByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Uint16
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
Dem_ExtDataElementIF_CollectSRData_Uint16(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_UINT16)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      uint16 lData;
      if ((*((Dem_ReadDataSRUint16FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_DATASTORAGEIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetLoByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Uint16_Intel
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
Dem_ExtDataElementIF_CollectSRData_Uint16_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_UINT16_INTEL)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      uint16 lData;
      if ((*((Dem_ReadDataSRUint16FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_DATASTORAGEIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetHiByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Sint32
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
Dem_ExtDataElementIF_CollectSRData_Sint32(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_SINT32)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      sint32 lData;
      if ((*((Dem_ReadDataSRSint32FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_DATASTORAGEIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetHiHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetHiLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 2] = Dem_GetLoHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 3] = Dem_GetLoLoByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Sint32_Intel
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
Dem_ExtDataElementIF_CollectSRData_Sint32_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_SINT32_INTEL)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      sint32 lData;
      if ((*((Dem_ReadDataSRSint32FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_DATASTORAGEIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetLoLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetLoHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 2] = Dem_GetHiLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 3] = Dem_GetHiHiByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_STATISTICAL_DATA == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Uint32
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
Dem_ExtDataElementIF_CollectSRData_Uint32(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_UINT32)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      uint32 lData;
      if ((*((Dem_ReadDataSRUint32FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_DATASTORAGEIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetHiHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetHiLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 2] = Dem_GetLoHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 3] = Dem_GetLoLoByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 % Dem_Dem_ExtDataElementIF_CollectSRData_Uint32_Intel
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
Dem_Dem_ExtDataElementIF_CollectSRData_Uint32_Intel(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_UINT32_INTEL)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      uint32 lData;
      if ((*((Dem_ReadDataSRUint32FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(&lData) == E_NOT_OK)                                 /* PRQA S 0313 */ /* MD_DEM_11.1 */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_DATASTORAGEIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      else
      {
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex] = Dem_GetLoLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetLoHiByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 2] = Dem_GetHiLoByte(lData);
        CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 3] = Dem_GetHiHiByte(lData);
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectSRData_Sint8_N
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectSRData_Sint8_N(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  if ((CollectDidInfoPtr->WriteIndex + Dem_Cfg_DataSize(DataIndex)) <= CollectDidInfoPtr->BufferSize)
  {
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
    if ((DataIndex >= Dem_Cfg_GlobalDataElementCount())                                                                          /* PRQA S 3415 */ /* MD_DEM_12.4_cf */
      || (Dem_Cfg_DataCallbackType(DataIndex) != DEM_CFG_DATA_FROM_SR_PORT_SINT8_N)
      || (Dem_Cfg_DataCbkRead(DataIndex) == NULL_PTR))
    {
      Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
    }
    else
# endif
    {
      if ((*((Dem_ReadDataSRSint8FPtrType)Dem_Cfg_DataCbkRead(DataIndex)))(                                                      /* PRQA S 0313 */ /* MD_DEM_11.1 */
        (Dem_SignedNvDataPtrType)(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex])) == E_NOT_OK)            /* PRQA S 0310 */ /* MD_DEM_11.4_sr */
      { /* In case the function failed, fill with padding bytes */
        Dem_MemSet(&CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex],                                         /* PRQA S 0602 */ /* MD_DEM_20.2 */ /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
          DEM_DATASTORAGEIF_INVALID_DATA_PATTERN,
          Dem_Cfg_DataSize(DataIndex));                                                                                          /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
      CollectDidInfoPtr->WriteIndex += Dem_Cfg_DataSize(DataIndex);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}
#endif

#if ( ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
     || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
     || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
     || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
     || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) ) \
   && (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectRootCauseEventId
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_CollectRootCauseEventId(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr
  )
{
  if ((CollectDidInfoPtr->WriteIndex + 2) <= CollectDidInfoPtr->BufferSize)
  {
    /* ROOTCAUSE_EVENTID: store configuration element in environmental data array */
    CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 0] = Dem_GetHiByte(CollectDidInfoPtr->EventId);         /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CollectDidInfoPtr->DestinationBuffer[CollectDidInfoPtr->WriteIndex + 1] = Dem_GetLoByte(CollectDidInfoPtr->EventId);         /* SBSW_DEM_WRITE_DIDINFO_DESTINATIONBUFFER */
    CollectDidInfoPtr->WriteIndex += 2;                                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
}
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
 * \addtogroup Dem_ExtDataElementIF_Public
 * \{
 */
#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
% Dem_DataReportIF_CopyCurrentDataElement
*****************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_ExtDataElementIF_InitCollectDidInfo(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_SharedDataPtrType, AUTOMATIC)  DestinationBuffer,
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(uint16, AUTOMATIC) BufferSize)
{
  CollectDidInfoPtr->MemoryEntryId = DEM_MEMORYENTRY_HANDLE_INVALID;
  CollectDidInfoPtr->SourceBuffer = (Dem_ConstSharedDataPtrType)NULL_PTR;
  CollectDidInfoPtr->DestinationBuffer = DestinationBuffer;
  CollectDidInfoPtr->EventId = EventId;
  CollectDidInfoPtr->BufferSize = BufferSize;
  CollectDidInfoPtr->WriteIndex = 0;
  CollectDidInfoPtr->ReadIndex = 0;
}
#endif

#if ( (DEM_CFG_SUPPORT_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
% Dem_DataReportIF_CopyCurrentDataElement
*****************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
DEM_LOCAL FUNC(boolean, DEM_CODE)
Dem_ExtDataElementIF_CollectDataElement(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DataIndexType, AUTOMATIC)  DataIndex
  )
{
  boolean lReturnValue;

  lReturnValue = TRUE;

  switch (Dem_Cfg_DataCallbackType(DataIndex))
  {
  case DEM_CFG_DATA_FROM_CBK:
  case DEM_CFG_DATA_FROM_SR_PORT_UINT8_N:
    Dem_ExtDataElementIF_CollectUserData(CollectDidInfoPtr, DataIndex);                                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_CBK_WITH_EVENTID:
    Dem_ExtDataElementIF_CollectCSDataWithEventId(CollectDidInfoPtr, DataIndex);                                                 /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_BOOLEAN:
    Dem_ExtDataElementIF_CollectSRData_Boolean(CollectDidInfoPtr, DataIndex);                                                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_SINT8:
    Dem_ExtDataElementIF_CollectSRData_Sint8(CollectDidInfoPtr, DataIndex);                                                      /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_UINT8:
    Dem_ExtDataElementIF_CollectSRData_Uint8(CollectDidInfoPtr, DataIndex);                                                      /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_SINT16:
    Dem_ExtDataElementIF_CollectSRData_Sint16(CollectDidInfoPtr, DataIndex);                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_SINT16_INTEL:
    Dem_ExtDataElementIF_CollectSRData_Sint16_Intel(CollectDidInfoPtr, DataIndex);                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_UINT16:
    Dem_ExtDataElementIF_CollectSRData_Uint16(CollectDidInfoPtr, DataIndex);                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_UINT16_INTEL:
    Dem_ExtDataElementIF_CollectSRData_Uint16_Intel(CollectDidInfoPtr, DataIndex);                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_SINT32:
    Dem_ExtDataElementIF_CollectSRData_Sint32(CollectDidInfoPtr, DataIndex);                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_SINT32_INTEL:
    Dem_ExtDataElementIF_CollectSRData_Sint32_Intel(CollectDidInfoPtr, DataIndex);                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_UINT32:
    Dem_ExtDataElementIF_CollectSRData_Uint32(CollectDidInfoPtr, DataIndex);                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_UINT32_INTEL:
    Dem_Dem_ExtDataElementIF_CollectSRData_Uint32_Intel(CollectDidInfoPtr, DataIndex);                                           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

  case DEM_CFG_DATA_FROM_SR_PORT_SINT8_N:
    Dem_ExtDataElementIF_CollectSRData_Sint8_N(CollectDidInfoPtr, DataIndex);                                                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;

# if (DEM_CFG_DATA_ROOTCAUSE_EVENTID == STD_ON)
  case DEM_CFG_DATA_FROM_ROOTCAUSE_EVENTID:
    Dem_ExtDataElementIF_CollectRootCauseEventId(CollectDidInfoPtr);                                                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    break;
# endif

  default:
    lReturnValue = FALSE;
    break;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
#endif

#if ( (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) \
   || (DEM_CFG_SUPPORT_SRECS == STD_ON) \
   || (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
   || (DEM_FEATURE_NEED_J1939_FREEZEFRAME == STD_ON) \
   || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) )
/* ****************************************************************************
 % Dem_ExtDataElementIF_CollectStoredDid
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
Dem_ExtDataElementIF_CollectStoredDid(
  CONST(Dem_ExtDataElementIF_CollectDidInfoPtrType, AUTOMATIC)  CollectDidInfoPtr,
  CONST(Dem_Cfg_DidIndexType, AUTOMATIC)  DidIndex
  )
{
  Dem_Cfg_DidDataIterType lDataIter;

  /* Each DID consists of 1-* data elements. */
  for (Dem_Cfg_DidDataIterInit(DidIndex, &lDataIter);                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_DidDataIterExists(&lDataIter) == TRUE;                                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_DidDataIterNext(&lDataIter))                                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_DataIndexType lDataIndex;

    lDataIndex = Dem_Cfg_DidDataIterGet(&lDataIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Cfg_DataIsStoredInNV(lDataIndex) == TRUE)
    {
      (void) Dem_ExtDataElementIF_CollectDataElement(CollectDidInfoPtr, lDataIndex);
    }
  }
}                                                                                                                                /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
#endif
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EXTDATAELEMENTIF_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ExtDataElementIF_Implementation.h
 *********************************************************************************************************************/
