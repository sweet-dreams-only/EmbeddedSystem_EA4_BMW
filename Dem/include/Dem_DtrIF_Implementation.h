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
/*! \addtogroup Dem_DtrIF
 *  \{
 *  \file       Dem_DtrIF_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
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

#if !defined (DEM_DTRIF_IMPLEMENTATION_H)
#define DEM_DTRIF_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_DtrIF_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Dtr_Implementation.h"
#include "Dem_MidLookup_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 * SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 * SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_DtrIF_Public
 * \{
 */

/* ****************************************************************************
 % Dem_DtrIF_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_Init(
  void
  )
{
  Dem_Dtr_Init();
  Dem_MidLookup_Init();
}

/* ****************************************************************************
 % Dem_DtrIF_PreInit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_PreInit(
  void
  )
{
  Dem_Dtr_PreInit();
  Dem_MidLookup_PreInit();
}

/* ****************************************************************************
 % Dem_DtrIF_MainFunction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_MainFunction(
  void
  )
{
  Dem_Dtr_MainFunction();
}

/* ****************************************************************************
 % Dem_DtrIF_Shutdown
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_Shutdown(
  void
  )
{
  Dem_Dtr_Shutdown();
}

/* ****************************************************************************
 % Dem_DtrIF_ClearDtrOfEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_ClearDtrOfEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_Dtr_ClearDtrOfEvent(EventId);
}

/* ****************************************************************************
 % Dem_DtrIF_SetDtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DtrIF_SetDtr(
  CONST(uint16, AUTOMATIC) DTRId,
  CONST(sint32, AUTOMATIC) TestResult,
  CONST(sint32, AUTOMATIC) LowerLimit,
  CONST(sint32, AUTOMATIC) UpperLimit,
  CONST(Dem_DTRControlType, AUTOMATIC) Ctrlval
  )
{
  return Dem_Dtr_SetDtr(DTRId, TestResult, LowerLimit, UpperLimit, Ctrlval);
}

/* ****************************************************************************
 % Dem_DtrIF_UpdateMidVisibility
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_DtrIF_UpdateMidVisibility(
  void
  )
{
  Dem_MidLookup_UpdateMidVisibility();
}

/* ****************************************************************************
 % Dem_DtrIF_GetSupportedMidValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_DtrIF_GetSupportedMidValue(                                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(uint8, AUTOMATIC)  Mid,
  CONSTP2VAR(uint32, AUTOMATIC, AUTOMATIC)  MidValue
  )
{
  boolean lReturnValue;
  if (Dem_MidLookup_IsSupportedMid(Mid) == TRUE)
  {
    *MidValue = Dem_MidLookup_GetSupportedMidValue(Mid);
    lReturnValue = TRUE;
  }
  else
  {
    lReturnValue = FALSE;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_DtrIF_GetTidCountOfMid
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DtrIF_GetTidCountOfMid(                                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(uint8, AUTOMATIC)  Mid,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  TidCount
  )
{
  return Dem_MidLookup_GetTidCountOfMid(Mid, TidCount);
}

/* ****************************************************************************
 % Dem_DtrIF_GetDataAndTidOfMid
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_DtrIF_GetDataAndTidOfMid(                                                                                                    /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(uint8, AUTOMATIC) Mid,
  CONST(uint8, AUTOMATIC) TidIndex,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  Tid,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  UaSid,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) TestResult,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) LowerLimit,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA) UpperLimit
)
{
  uint8 lTid;
  uint16 lDtrId;
  Std_ReturnType lReturnValue;

  lDtrId = Dem_MidLookup_FindDtrId(Mid, TidIndex, &lTid);
  if (Dem_Dtr_IsValidHandle(lDtrId) == TRUE)
  {
    *Tid = lTid;
    *UaSid = Dem_Dtr_GetUaSId(lDtrId);

    /* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */

    *TestResult = Dem_Dtr_GetTestValue(lDtrId);
    *LowerLimit = Dem_Dtr_GetLowerLimit(lDtrId);
    *UpperLimit = Dem_Dtr_GetUpperLimit(lDtrId);

    Dem_LeaveCritical_DiagMonitor();                                                                                               /* PRQA S 3109 */ /* MD_MSR_14.3 */
    /* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
    
    lReturnValue = E_OK;
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6060 */ /* MD_MSR_STCAL, MD_MSR_STPAR */

/*!
 * \}
 */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_DTRIF_IMPLEMENTATION_H */
/*!
 * \}
 */
/* *********************************************************************************************************************
 *  END OF FILE: Dem_DtrIF_Implementation.h
 **********************************************************************************************************************/
