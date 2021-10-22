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
/*!
 *  \addtogroup Dem_DcmAPI
 *  \{
 *  \file       Dem_DcmAPI_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
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

#if !defined (DEM_DCMAPI_IMPLEMENTATION_H)
#define DEM_DCMAPI_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DcmAPI_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Dcm_Implementation.h"
#include "Dem_InitState_Implementation.h"
#include "Dem_Cfg_Definitions.h"
#include "Dem_DtrIF_Implementation.h"
#include "Dem_ClientAccess_Implementation.h"
#include "Dem_EnableCondition_Implementation.h"

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
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DcmAPI_Public
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_SetDTCFilter
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
Dem_SetDTCFilter(
  uint8  ClientId,
  uint8  DTCStatusMask,
  Dem_DTCFormatType  DTCFormat,                                                                                                  /* PRQA S 3206 */ /* MD_DEM_3206 */
  Dem_DTCOriginType  DTCOrigin,
  boolean  FilterWithSeverity,                                                                                                   /* PRQA S 3206 */ /* MD_DEM_3206 */
  Dem_DTCSeverityType  DTCSeverityMask,                                                                                          /* PRQA S 3206 */ /* MD_DEM_3206 */
  boolean  FilterForFaultDetectionCounter
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX tx tx */
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if ((DTCFormat != DEM_DTC_FORMAT_UDS) && (DTCFormat != DEM_DTC_FORMAT_OBD))
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if ((DTCOrigin == 0) || (DTCOrigin >= DEM_DTC_ORIGIN_INVALID))
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (FilterWithSeverity > TRUE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (FilterForFaultDetectionCounter > TRUE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (Dem_ClientAccess_TestFilterValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
#  if (DEM_FEATURE_NEED_OBD != STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX tf tf tx */
  if (DTCFormat == DEM_DTC_FORMAT_OBD)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_CONFIG);
  }
  else
#  endif
# endif /*DEM_DEV_ERROR_DETECT*/
    {
      /* ----- Implementation ------------------------------------------------ */
      /* Returns E_NOT_OK if function arguments does not match configuration. */
      lReturnValue = Dem_ClientAccess_SetDTCFilter(ClientId,
                                                   DTCStatusMask,
                                                   DTCFormat,
                                                   DTCOrigin,
                                                   FilterWithSeverity,
                                                   DTCSeverityMask,
                                                   FilterForFaultDetectionCounter);

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
      if (lReturnValue == E_NOT_OK)
      {
        Dem_Det_ErrorRegisterSet(DEM_E_PARAM_CONFIG);
      }
# endif
    }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_SETDTCFILTER_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6010, 6030, 6050, 6060, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetNumberOfFilteredDTC
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
Dem_GetNumberOfFilteredDTC(
  uint8 ClientId,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  NumberOfFilteredDTC
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)        
  lReturnValue = E_NOT_OK;
#endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
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
  if (Dem_ClientAccess_TestFilterValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_TestDTCFilterSet(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    *NumberOfFilteredDTC = Dem_ClientAccess_FilterNumberMemory(ClientId);                                                        /* SBSW_DEM_POINTER_WRITE_API */
    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETNUMBEROFFILTEREDDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetNextFilteredDTC
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
Dem_GetNextFilteredDTC(
  uint8 ClientId,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX tx tx */
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (DTCStatus == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Dem_ClientAccess_TestFilterValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_TestDTCFilterSet(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    Dem_FilterData_ResultType  lFilterResult;
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_ClientAccess_GetNextFilteredDTC(ClientId, &lFilterResult);

    if (lReturnValue == E_OK)
    { /* Set out parameter only if a filtered DTC was found*/
      *DTC = lFilterResult.DTC;                                                                                                  /* SBSW_DEM_POINTER_WRITE_API */
      *DTCStatus = lFilterResult.DTCStatus;                                                                                      /* SBSW_DEM_POINTER_WRITE_API */
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETNEXTFILTEREDDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetNextFilteredDTCAndFDC
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
Dem_GetNextFilteredDTCAndFDC(
  uint8 ClientId,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,
  P2VAR(sint8, AUTOMATIC, DEM_DCM_DATA)  DTCFaultDetectionCounter
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX tx tx */
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (DTCFaultDetectionCounter == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Dem_ClientAccess_TestFilterValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_TestDTCFilterWithFDCSet(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    Dem_FilterData_ResultType  lFilterResult;
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_ClientAccess_GetNextFilteredDTC(ClientId, &lFilterResult);

    if (lReturnValue == E_OK)
    { /* Set out parameter only if a filtered DTC was found*/
      *DTC = lFilterResult.DTC;                                                                                                  /* SBSW_DEM_POINTER_WRITE_API */
      *DTCFaultDetectionCounter = lFilterResult.FDC;                                                                             /* SBSW_DEM_POINTER_WRITE_API */
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETNEXTFILTEREDDTCANDFDC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetNextFilteredDTCAndSeverity
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
Dem_GetNextFilteredDTCAndSeverity(
  uint8 ClientId,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,                                                                                   /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus,                                                                              /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity,                                                              /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit                                                                       /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX tx tx */
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (DTCStatus == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (DTCSeverity == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (DTCFunctionalUnit == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Dem_ClientAccess_TestFilterValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_TestDTCFilterWithSeveritySet(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    Dem_FilterData_ResultType  lFilterResult;
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_ClientAccess_GetNextFilteredDTC(ClientId, &lFilterResult);

    if (lReturnValue == E_OK)
    { /* Set out parameter only if a filtered DTC was found*/
      *DTC = lFilterResult.DTC;                                                                                                  /* SBSW_DEM_POINTER_WRITE_API */
      *DTCStatus = lFilterResult.DTCStatus;                                                                                      /* SBSW_DEM_POINTER_WRITE_API */
      *DTCSeverity = lFilterResult.Severity;                                                                                     /* SBSW_DEM_POINTER_WRITE_API */
      *DTCFunctionalUnit = lFilterResult.FunctionalUnit;                                                                         /* SBSW_DEM_POINTER_WRITE_API */
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETNEXTFILTEREDDTCANDSEVERITY_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_SetFreezeFrameRecordFilter
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
Dem_SetFreezeFrameRecordFilter(
  uint8                                   ClientId,
  Dem_DTCFormatType                       DTCFormat,                                                                             /* PRQA S 3206 */ /* MD_DEM_3206 */
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  NumberOfFilteredRecords
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX tx tx */
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (Dem_ClientAccess_TestFreezeFrameIteratorValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if ( (DTCFormat != DEM_DTC_FORMAT_UDS)
#  if (DEM_CFG_SUPPORT_OBDII == STD_ON)                                                                                          /* COV_MSR_UNSUPPORTED XF */
    && (DTCFormat != DEM_DTC_FORMAT_OBD)
#  endif
#  if (DEM_CFG_SUPPORT_J1939 == STD_ON)
    && (DTCFormat != DEM_DTC_FORMAT_J1939)
#  endif
    )
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (NumberOfFilteredRecords == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
    lReturnValue = Dem_ClientAccess_StartFreezeFrameIterator(ClientId, DTCFormat, NumberOfFilteredRecords);

# else
    DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                         /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(DTCFormat)                                                                                        /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    *NumberOfFilteredRecords = 0;                                                                                                /* SBSW_DEM_POINTER_WRITE_API */
    lReturnValue = E_OK;
# endif /* (DEM_CFG_SUPPORT_SRECS == STD_ON) */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_SETFREEZEFRAMERECORDFILTER_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetNextFilteredRecord
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
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetNextFilteredRecord(
  uint8                                   ClientId,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,                                                                                   /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)   RecordNumber                                                                           /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX tx tx */
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (Dem_ClientAccess_TestFreezeFrameIteratorValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (RecordNumber == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_TestFreezeFrameFilterSet(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */

# if (DEM_CFG_SUPPORT_SRECS == STD_OFF)
    DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                         /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(DTC)                                                                                              /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(RecordNumber)                                                                                     /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
# else
    if (Dem_ClientAccess_GetNextFreezeFrameRecord(ClientId, DTC, RecordNumber) == TRUE)
    {
      lReturnValue = E_OK;
    }
    else
# endif
    {
      lReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETNEXTFILTEREDRECORD_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 2006, 6030, 6080 */ /* MD_DEM_14.7, MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetStatusOfDTC
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
Dem_GetStatusOfDTC(
  uint8  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTCStatus == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    Dem_DTCSelector_ResultType lSelectionResult;

    lSelectionResult = Dem_ClientAccess_GetSelectionResult(ClientId);
    switch (lSelectionResult)
    {
    case DEM_DTCSELECTOR_SELECTION_DTC:
      lReturnValue = Dem_Dcm_GetStatusOfSelectedDTC(ClientId, DTCStatus);
      break;

    case DEM_DTCSELECTOR_SELECTION_GROUP:
    case DEM_DTCSELECTOR_SELECTION_ALL_DTCS:
    case DEM_DTCSELECTOR_SELECTION_NO_MATCH:
      lReturnValue = DEM_WRONG_DTC;
      break;

    case DEM_DTCSELECTOR_SELECTION_WRONG_ORIGIN:
      lReturnValue = DEM_WRONG_DTCORIGIN;
      break;

    case DEM_DTCSELECTOR_SELECTION_INIT:
      /* E_NOT_OK */
      Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION);
      break;

    default:
      /* MISRA case */
      /* E_NOT_OK */
      break;
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETSTATUSOFDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetDTCStatusAvailabilityMask
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
Dem_GetDTCStatusAvailabilityMask(
  uint8  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatusMask
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                           /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (DTCStatusMask == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    *DTCStatusMask = Dem_Cfg_GlobalStatusMask();                                                                                 /* SBSW_DEM_POINTER_WRITE_API */
    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETDTCSTATUSAVAILABILITYMASK_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetDTCByOccurrenceTime
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
Dem_GetDTCByOccurrenceTime(
  uint8                                   ClientId,
  Dem_DTCRequestType                      DTCRequest,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                           /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

# if (DEM_DEV_ERROR_DETECT == STD_ON) 
  lReturnValue = E_NOT_OK;
#endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if ( (DTCRequest != DEM_FIRST_FAILED_DTC)
    && (DTCRequest != DEM_MOST_RECENT_FAILED_DTC)
    && (DTCRequest != DEM_FIRST_DET_CONFIRMED_DTC)
    && (DTCRequest != DEM_MOST_REC_DET_CONFIRMED_DTC))
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (DTC == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    boolean lSuccess;
    lSuccess = Dem_ClientAccess_GetDTCByOccurrenceTime(DTCRequest, DTC);

    if (lSuccess == TRUE)
    {
      lReturnValue = E_OK;
    }
    else
    {
      lReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETDTCBYOCCURRENCETIME_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetTranslationType
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
FUNC(Dem_DTCTranslationFormatType, DEM_CODE)
Dem_GetTranslationType(
  uint8 ClientId
  )
{
  Dem_DTCTranslationFormatType lTranslationFormat;

  Dem_Det_ErrorRegisterDefine()

  DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                           /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
    lTranslationFormat = 0;
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
    lTranslationFormat = 0;
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
    lTranslationFormat = 0;
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    lTranslationFormat = Dem_Cfg_GlobalDtcFormat();
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETTRANSLATIONTYPE_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lTranslationFormat;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetSeverityOfDTC
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
Dem_GetSeverityOfDTC(
  uint8  ClientId,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity                                                               /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTCSeverity == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    Dem_DTCSelector_ResultType lSelectionResult;

    lSelectionResult = Dem_ClientAccess_GetSelectionResult(ClientId);
    switch (lSelectionResult)
    {
    case DEM_DTCSELECTOR_SELECTION_DTC:
      lReturnValue = Dem_Dcm_GetSeverityOfSelectedDTC(ClientId, DTCSeverity);
      break;

    case DEM_DTCSELECTOR_SELECTION_GROUP:
    case DEM_DTCSELECTOR_SELECTION_ALL_DTCS:
    case DEM_DTCSELECTOR_SELECTION_NO_MATCH:
      lReturnValue = DEM_WRONG_DTC;
      break;

    case DEM_DTCSELECTOR_SELECTION_WRONG_ORIGIN:
      lReturnValue = DEM_WRONG_DTCORIGIN;
      break;

    case DEM_DTCSELECTOR_SELECTION_INIT:
      /* E_NOT_OK */
      Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION);
      break;

    default:
      /* MISRA case */
      /* E_NOT_OK */
      break;
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETSEVERITYOFDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetDTCSeverityAvailabilityMask
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
Dem_GetDTCSeverityAvailabilityMask(
  uint8  ClientId,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverityMask
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                           /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
  if (DTCSeverityMask == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    *DTCSeverityMask = Dem_Cfg_GlobalSeverityMask();                                                                             /* SBSW_DEM_POINTER_WRITE_API */
    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETDTCSEVERITYAVAILABILITYMASK_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetFunctionalUnitOfDTC
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
Dem_GetFunctionalUnitOfDTC(
  uint8  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (DTCFunctionalUnit == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    Dem_DTCSelector_ResultType lSelectionResult;

    lSelectionResult = Dem_ClientAccess_GetSelectionResult(ClientId);
    switch (lSelectionResult)
    {
    case DEM_DTCSELECTOR_SELECTION_DTC:
      lReturnValue = Dem_Dcm_GetFunctionalUnitOfSelectedDTC(ClientId, DTCFunctionalUnit);
      break;

    case DEM_DTCSELECTOR_SELECTION_GROUP:
    case DEM_DTCSELECTOR_SELECTION_ALL_DTCS:
    case DEM_DTCSELECTOR_SELECTION_NO_MATCH:
      lReturnValue = DEM_WRONG_DTC;
      break;

    case DEM_DTCSELECTOR_SELECTION_WRONG_ORIGIN:
      lReturnValue = DEM_WRONG_DTCORIGIN;
      break;

    case DEM_DTCSELECTOR_SELECTION_INIT:
      /* E_NOT_OK */
      Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION);
      break;

    default:
      /* MISRA case */
      /* E_NOT_OK */
      break;
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETFUNCTIONALUNITOFDTC_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DisableDTCRecordUpdate
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
Dem_DisableDTCRecordUpdate(
  uint8  ClientId
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)     
  lReturnValue = E_NOT_OK;
#endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (Dem_ClientAccess_TestReadoutBufferValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_GetSelectionResult(ClientId) == DEM_DTCSELECTOR_SELECTION_INIT)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_ClientAccess_DisableDTCRecordUpdate(ClientId);

    if (lReturnValue == E_NOT_OK)
    {
      /* new request with different parameters than ongoing request */
#  if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED TX */
      Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
#  endif
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_DISABLEDTCRECORDUPDATE_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_EnableDTCRecordUpdate
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
FUNC(Std_ReturnType, DEM_CODE)
Dem_EnableDTCRecordUpdate(
  uint8  ClientId
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)     
  lReturnValue = E_NOT_OK;
#endif
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (Dem_ClientAccess_TestReadoutBufferValid(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_ClientAccess_EnableDTCRecordUpdate(ClientId);
    
#  if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                           /* COV_MSR_UNSUPPORTED TX */
    if (lReturnValue == E_NOT_OK)
    {
      Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
    }
#  endif
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_ENABLEDTCRECORDUPDATE_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_SelectFreezeFrameData
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
Dem_SelectFreezeFrameData(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONST(uint8, AUTOMATIC)  RecordNumber
)
{
  Std_ReturnType lReturnValue;

  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_GetSelectionResult(ClientId) == DEM_DTCSELECTOR_SELECTION_INIT)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestDTCRecordUpdateRequested(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    Dem_Dcm_SnapshotDataRecord_SnapshotSelect(ClientId, RecordNumber);

    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_SELECTFREEZEFRAMEDATA_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetNextFreezeFrameData
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
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetNextFreezeFrameData(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
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
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_GetSelectionResult(ClientId) == DEM_DTCSELECTOR_SELECTION_INIT)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestDTCRecordUpdateRequested(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestSnapshotRecordSelected(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    if (Dem_ClientAccess_TestDTCRecordUpdateDisabled(ClientId) == FALSE)
    {
      lReturnValue = DEM_PENDING;
    }
    else
    {
      lReturnValue = Dem_Dcm_SnapshotDataRecord_ReadNext(ClientId, DestBuffer, BufSize);
    }
  }
  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETNEXTFREEZEFRAMEDATA_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetSizeOfFreezeFrameSelection
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
Dem_GetSizeOfFreezeFrameSelection(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

    /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (SizeOfFreezeFrame == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_GetSelectionResult(ClientId) == DEM_DTCSELECTOR_SELECTION_INIT)
  {
    /* missing prior call to Dem_SelectDTC() */
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestDTCRecordUpdateRequested(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestSnapshotRecordSelected(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    if (Dem_ClientAccess_TestDTCRecordUpdateDisabled(ClientId) == FALSE)
    {
      lReturnValue = DEM_PENDING;
    }
    else
    {
      lReturnValue = Dem_Dcm_GetSizeOfFreezeFrameSelection(ClientId, SizeOfFreezeFrame);
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETSIZEOFFREEZEFRAMESELECTION_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_SelectExtendedDataRecord
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
Dem_SelectExtendedDataRecord(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONST(uint8, AUTOMATIC)  ExtendedDataNumber
  )
{
  Std_ReturnType lReturnValue;

  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_TestDTCRecordUpdateRequested(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    Dem_Dcm_ExtendedDataRecord_RecordSelect(ClientId, ExtendedDataNumber);

    lReturnValue = E_OK;
  }
  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_SELECTEXTENDEDDATARECORD_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetNextExtendedDataRecord
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
Dem_GetNextExtendedDataRecord(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,                                                                             /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize                                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
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
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_GetSelectionResult(ClientId) == DEM_DTCSELECTOR_SELECTION_INIT)
  {
    /* missing prior call to Dem_SelectDTC() */
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestDTCRecordUpdateRequested(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestExtendedRecordSelected(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    if (Dem_ClientAccess_TestDTCRecordUpdateDisabled(ClientId) == FALSE)
    {
      lReturnValue = DEM_PENDING;
    }
    else
    {
      lReturnValue = Dem_Dcm_ExtendedDataRecord_ReadNext(ClientId, DestBuffer, BufSize);
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETNEXTEXTENDEDDATARECORD_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_GetSizeOfExtendedDataRecordSelection
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
Dem_GetSizeOfExtendedDataRecordSelection(
  CONST(uint8, AUTOMATIC) ClientId,                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfExtendedDataRecord                                                               /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  lReturnValue = E_NOT_OK;
# endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (SizeOfExtendedDataRecord == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
  if (Dem_ClientAccess_GetSelectionResult(ClientId) == DEM_DTCSELECTOR_SELECTION_INIT)
  {
    /* missing prior call to Dem_SelectDTC() */
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestDTCRecordUpdateRequested(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
  if (Dem_ClientAccess_TestExtendedRecordSelected(ClientId) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    if (Dem_ClientAccess_TestDTCRecordUpdateDisabled(ClientId) == FALSE)
    {
      lReturnValue = DEM_PENDING;
    }
    else
    {
      lReturnValue = Dem_Dcm_ExtendedDataRecord_GetSize(ClientId,
                                                        SizeOfExtendedDataRecord);                                               /* SBSW_DEM_POINTER_FORWARD_API */
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_GETSIZEOFEXTENDEDDATARECORDSELECTION_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DisableDTCSetting
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
FUNC(Std_ReturnType, DEM_CODE)
Dem_DisableDTCSetting(
  uint8  ClientId
  )
{
  Std_ReturnType lReturnValue;

  Dem_Det_ErrorRegisterDefine()

  DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                           /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

# if (DEM_DEV_ERROR_DETECT == STD_ON)     
  lReturnValue = E_NOT_OK;
#endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    Dem_EnableCondition_ResetEnableConditionFulfilled(DEM_ENABLECONDITION_CONTROLDTCSETTING);

    if (Dem_Cfg_GlobalCbkControlDtcSetting() != NULL_PTR)
    {
      (void)(Dem_Cfg_GlobalCbkControlDtcSetting()(FALSE));
    }

    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_DISABLEDTCSETTING_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_EnableDTCSetting
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
FUNC(Std_ReturnType, DEM_CODE)
Dem_EnableDTCSetting(
  uint8  ClientId
  )
{
  Std_ReturnType lReturnValue;

  Dem_Det_ErrorRegisterDefine()

  DEM_IGNORE_UNUSED_ARGUMENT(ClientId)                                                                                           /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

# if (DEM_DEV_ERROR_DETECT == STD_ON)    
  lReturnValue = E_NOT_OK;
#endif

  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (ClientId >= Dem_ClientAccess_GlobalClientCount())
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_DATA)
  }
  else
#  if (DEM_CFG_SUPPORT_MULTIPLE_SATELLITES == STD_ON)
  if (GetCurrentApplicationID() != DEM_CFG_MASTER_APPLICATION_ID)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_WRONG_CONDITION)
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    Dem_EnableCondition_SetEnableConditionFulfilled(DEM_ENABLECONDITION_CONTROLDTCSETTING);

    if (Dem_Cfg_GlobalCbkControlDtcSetting() != NULL_PTR)
    {
      (void)(Dem_Cfg_GlobalCbkControlDtcSetting()(TRUE));
    }

    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_ENABLEDTCSETTING_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

                                                    /* Dcm <-> Dem : OBD DTR */
/* ------------------------------------------------------------------------- */

#if (DEM_CFG_SUPPORT_DTR == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DcmGetDTRData
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
Dem_DcmGetDTRData(
  uint8 Obdmid,
  uint8 TIDindex,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA) TIDvalue,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA) UaSID,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) Testvalue,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) Lowlimvalue,
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) Upplimvalue
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
  if (TIDvalue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (UaSID == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Testvalue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Lowlimvalue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (Upplimvalue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_DtrIF_GetDataAndTidOfMid(Obdmid, TIDindex, TIDvalue, UaSID, Testvalue, Lowlimvalue, Upplimvalue);
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_DCMGETDTRDATA, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6060, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
#endif

                                                   /* Dcm <-> Dem : OBD MIDs */
/* ------------------------------------------------------------------------- */
#if (DEM_CFG_SUPPORT_DTR == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DcmGetAvailableOBDMIDs
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
Dem_DcmGetAvailableOBDMIDs(
  uint8 Obdmid,
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  Obdmidvalue
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
  if (Obdmidvalue == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    uint32 lMidValue;
    if (Dem_DtrIF_GetSupportedMidValue(Obdmid, &lMidValue) == TRUE)
    {
      *Obdmidvalue = lMidValue;
      lReturnValue = E_OK;
    }
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_DCMGETAVAILABLEOBDMIDS, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DTR == STD_ON) && (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DcmGetNumTIDsOfOBDMID
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
Dem_DcmGetNumTIDsOfOBDMID(
  uint8 Obdmid,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA) numberOfTIDs
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
  if (numberOfTIDs == NULL_PTR)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    /* ----- Implementation ------------------------------------------------ */
    lReturnValue = Dem_DtrIF_GetTidCountOfMid(Obdmid, numberOfTIDs);
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_DCMGETNUMTIDSOFOBDMID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_DcmGetOBDFreezeFrameData
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
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmGetOBDFreezeFrameData(
  P2VAR(uint32, AUTOMATIC, DEM_DCM_DATA)  DTC,                                                                                   /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DestBuffer,                                                                             /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  P2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  BufSize                                                                                /* PRQA S 3206, 3673 */ /* MD_DEM_3206, MD_DEM_16.7 */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Det_ErrorRegisterDefine()

  lReturnValue = E_NOT_OK;
  Dem_Det_ErrorRegisterSet(DEM_E_NO_ERROR)

  /* ----- Development Error Checks ---------------------------------------- */
# if (DEM_DEV_ERROR_DETECT == STD_ON)                                                                                            /* COV_MSR_UNSUPPORTED TX */
  if (Dem_InitState_TestMasterInState(DEM_INITSTATE_INITIALIZED) == FALSE)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_UNINIT)
  }
  else
  if (NULL_PTR == DTC)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (NULL_PTR == DestBuffer)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
  if (NULL_PTR == BufSize)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    DEM_IGNORE_UNUSED_ARGUMENT(DTC)                                                                                              /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(DestBuffer)                                                                                       /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */
    DEM_IGNORE_UNUSED_ARGUMENT(BufSize)                                                                                          /* PRQA S 3112, 3199 */ /* MD_DEM_14.2, MD_DEM_3199 */

    /* ----- Implementation ------------------------------------------------ */
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_DCMGETOBDFREEZEFRAMEDATA_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

                                                   /* Dcm <-> Dem : OBD VIDs */
/* ------------------------------------------------------------------------- */
                                                   /* Dcm <-> Dem : OBD PIDs */
/* ------------------------------------------------------------------------- */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID21 == STD_ON)                     /* COV_MSR_UNSUPPORTED XF tf xf xf */
/* ****************************************************************************
 % Dem_DcmReadDataOfPID21
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
 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_DcmReadDataOfPID21(
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID21value                                                                              /* PRQA S 1330 */ /* MD_DEM_16.4_dcm */
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
  if (NULL_PTR == PID21value)
  {
    Dem_Det_ErrorRegisterSet(DEM_E_PARAM_POINTER)
  }
  else
# endif
  {
    uint32  lOdometerValue;
    uint32  lStoredOdometerValue;

    /* ----- Implementation ------------------------------------------------ */
    /* If the Distance travelled with MIL on is latched due to inactive MIL, the mileage can be taken directly.
       If the MIL is active, the difference between the stored value and the current odometer value is calculated */

/* >>>> -------------------------------- Enter Critical Section: DcmApi */
    Dem_EnterCritical_DcmApi();                                                                                                  /* PRQA S 3109 */ /* MD_MSR_14.3 */

    lStoredOdometerValue = Dem_Mem_GetOdometerMilOn();

    Dem_LeaveCritical_DcmApi();                                                                                                  /* PRQA S 3109 */ /* MD_MSR_14.3 */
/* <<<< -------------------------------- Leave Critical Section: DcmApi */

    if (DEM_MEM_TEST_ODOMETER_ISINVALID(lStoredOdometerValue) == FALSE)
    {
      if (Dem_Indicator_TestMilIsActive() == TRUE)
      { /* MIL is considered active, get current Odometer value */
        if (Dem_Data_GetObdOdometer(&lOdometerValue) != E_OK)
        { /* application currently can't provide a valid odometer */
          lOdometerValue = DEM_DATA_MAX_OBD_ODOMETER;
        }
        else
        {
          lOdometerValue = lOdometerValue - lStoredOdometerValue;
        }
      }
      else
      { /* MIL is considered inactive */
        lOdometerValue = lStoredOdometerValue;
      }

      /* The Odometer shall be latched at 0xFFFF */
      if (lOdometerValue > DEM_DATA_MAX_OBD_ODOMETER)
      {
        lOdometerValue = DEM_DATA_MAX_OBD_ODOMETER;
      }
    }
    else
    { /* currently no odometer available */
      lOdometerValue = DEM_DATA_MAX_OBD_ODOMETER;
    }

    PID21value[0] = Dem_GetLoHiByte(lOdometerValue);                                                                             /* SBSW_DEM_POINTER_WRITE_API */
    PID21value[1] = Dem_GetLoLoByte(lOdometerValue);                                                                             /* SBSW_DEM_POINTER_WRITE_API */
    lReturnValue = E_OK;
  }

  /* ----- Development Error Report ---------------------------------------- */
# if (DEM_DEV_ERROR_REPORT == STD_ON)
  if (Dem_Det_ErrorRegisterGet() != DEM_E_NO_ERROR)
  {
    Dem_Error_ReportError(DEM_DCMREADDATAOFPID21_APIID, Dem_Det_ErrorRegisterGet());
  }
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID21 == STD_ON) */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DCMAPI_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_DcmAPI_Implementation.h
 *********************************************************************************************************************/
