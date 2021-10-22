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
/*! \ingroup    Dem_Memory
 *  \defgroup   Dem_MemState Memory State Manager
 *  \{
 *  \file       Dem_MemState_Interface.h
 *  \brief      Encapsulate global data stored for an event memory.
 *  \details    All global data not stored in an event specific memory entry:
 *              - how much entries are stored,
 *              - what is the first, the last one,
 *              - chronology,
 *              - ... .
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

#if !defined (DEM_MEMSTATE_INTERFACE_H)
#define DEM_MEMSTATE_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_MemState_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_MemState_Properties Properties
 * \{
 */

/* ****************************************************************************
 * Dem_MemState_SetPrimaryCurrentCount
 *****************************************************************************/
/*!
 * \brief         Set the count of allocated primary entries
 *
 * \details       Set the count of allocated primary entries
 *
 * \param[in]     CurrentCount
 *                The current count of allocated primary entries
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_MemState_SetPrimaryCurrentCount(
  uint8 CurrentCount
  );

/* ****************************************************************************
 * Dem_MemState_GetPrimaryCurrentCount
 *****************************************************************************/
/*!
 * \brief         Get the count of allocated primary entries
 *
 * \details       Get the count of allocated primary entries
 *
 * \return        The current count of allocated primary entries
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemState_GetPrimaryCurrentCount(
  void
  );

#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
/* ****************************************************************************
 * Dem_MemState_SetSecondaryCurrentCount
 *****************************************************************************/
/*!
 * \brief         Set the count of allocated secondary entries
 *
 * \details       Set the count of allocated secondary entries
 *
 * \param[in]     CurrentCount
 *                The current count of allocated secondary entries
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_SECONDARY == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_MemState_SetSecondaryCurrentCount(
  uint8 CurrentCount
  );
#endif

#if (DEM_CFG_SUPPORT_SECONDARY == STD_ON)
/* ****************************************************************************
 * Dem_MemState_GetSecondaryCurrentCount
 *****************************************************************************/
/*!
 * \brief         Get the count of allocated secondary entries
 *
 * \details       Get the count of allocated secondary entries
 *
 * \return        The current count of allocated secondary entries
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_SECONDARY == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_MemState_GetSecondaryCurrentCount(
  void
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_MemState_Private Private Methods
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_MemState_Public Public Methods
 * \{
 */




/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_MEMSTATE_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemState_Interface.h
 *********************************************************************************************************************/
