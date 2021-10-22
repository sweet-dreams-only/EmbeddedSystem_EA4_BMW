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
/*! \addtogroup Dem_ClientData
 *  \{
 *  \file       Dem_ClientData_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
 *  \details    -
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

#if !defined (DEM_CLIENTDATA_IMPLEMENTATION_H)
#define DEM_CLIENTDATA_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_ClientData_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Cfg_Definitions.h"

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
 *  SUBCOMPONENT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \addtogroup Dem_ClientData_Properties
 * \{
 */

/* ****************************************************************************
 % Dem_ClientData_GetDTCSelector()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCSelector_HandleType, DEM_CODE)
Dem_ClientData_GetDTCSelector(
  CONST(uint8, AUTOMATIC)  ClientId
  )
{
  Dem_DTCSelector_HandleType lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_CFG_DTCSELECTORTABLE == STD_ON)
  if (ClientId < Dem_Cfg_GetSizeOfClientTable())
  {
    lReturnValue = (Dem_DTCSelector_HandleType) Dem_Cfg_GetSelectorIndexOfClientTable(ClientId);
  }
  else
#endif
  {
    lReturnValue = DEM_CFG_DTCSELECTOR_INVALID;
  }

  return lReturnValue;
}

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_ClientData_GetFilterId()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_FilterData_HandleType, DEM_CODE)
Dem_ClientData_GetFilterId(
  CONST(uint8, AUTOMATIC)  ClientId
  )
{
  Dem_FilterData_HandleType lReturnValue;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */

# if (DEM_CFG_FILTERINFOTABLE == STD_ON)
  if (ClientId < Dem_Cfg_GetSizeOfClientTable())
  {
    lReturnValue = (Dem_FilterData_HandleType) Dem_Cfg_GetFilterIndexOfClientTable(ClientId);
  }
  else
# endif
  {
    lReturnValue = DEM_CFG_FILTER_INVALID;
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_ClientData_GetFreezeFrameIteratorId
*****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_FreezeFrameIterator_HandleType, DEM_CODE)
Dem_ClientData_GetFreezeFrameIteratorId(
  CONST(uint8, AUTOMATIC)  ClientId
  )
{
  Dem_FreezeFrameIterator_HandleType lReturnValue;

# if (DEM_CFG_FILTERINFOTABLE == STD_ON)
  if (ClientId < Dem_Cfg_GetSizeOfClientTable())
  {
    lReturnValue = (Dem_FreezeFrameIterator_HandleType)Dem_Cfg_GetFreezeFrameIteratorIndexOfClientTable(ClientId);
  }
  else
# endif
  {
    lReturnValue = DEM_CFG_FREEZEFRAMEITERATOR_INVALID;
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_ClientData_GetReadoutBufferId()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_DTCReadoutBuffer_HandleType, DEM_CODE)
Dem_ClientData_GetReadoutBufferId(
  CONST(uint8, AUTOMATIC)  ClientId
  )
{
  Dem_DTCReadoutBuffer_HandleType lReturnValue;

# if (DEM_CFG_READOUTBUFFERINDEXOFCLIENTTABLE == STD_ON)
  if (ClientId < Dem_Cfg_GetSizeOfClientTable())
  {
    lReturnValue = (Dem_DTCReadoutBuffer_HandleType) Dem_Cfg_GetReadoutBufferIndexOfClientTable(ClientId);
  }
  else
# endif
  {
    lReturnValue = DEM_CFG_READOUTBUFFER_INVALID;
  }

  return lReturnValue;
}
#endif

/* ****************************************************************************
 % Dem_ClientData_GetClearDTCStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_ClearDTC_HandleType, DEM_CODE)
Dem_ClientData_GetClearDTCStatus(
  CONST(uint8, AUTOMATIC)  ClientId
  )
{
  Dem_ClearDTC_HandleType lReturnValue;

#if (DEM_CFG_CLEARDTCINDEXOFCLIENTTABLE == STD_ON)
  if (ClientId < Dem_Cfg_GetSizeOfClientTable())
  {
    lReturnValue = (Dem_ClearDTC_HandleType)Dem_Cfg_GetClearDTCIndexOfClientTable(ClientId);
  }
  else
#endif
  {
    lReturnValue = DEM_CLEARDTC_HANDLE_INVALID;
  }

  return lReturnValue;
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* DEM_CLIENTDATA_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ClientData_Implementation.h
 *********************************************************************************************************************/
