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
/*! \addtogroup Dem_Communication
 *  \{
 *  \file       Dem_Com_Implementation.h
 *  \brief      Implementation file for the MICROSAR Dem
 *  \details    Implementation of communication subcomponent
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

#if !defined (DEM_COM_IMPLEMENTATION_H)
#define DEM_COM_IMPLEMENTATION_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Com_Interface.h"

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
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \addtogroup Dem_Communication_Private
 * \{
 */

/* ****************************************************************************
 % Dem_Com_GetBitfieldWordIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_HandleType, DEM_CODE)
Dem_Com_GetBitfieldWordIndex(
  CONST(Dem_Com_ProcessorWordType, AUTOMATIC) BitPosition
  )
{
  Dem_HandleType lReturnValue;

  lReturnValue = (Dem_HandleType)(BitPosition / DEM_COM_BITS_PER_WORD);

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Com_GetBitfieldBitIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Com_GetBitfieldBitIndex(
  CONST(Dem_Com_ProcessorWordType, AUTOMATIC) BitPosition
  )
{
  uint8 lReturnValue;

  lReturnValue = (uint8)(BitPosition % DEM_COM_BITS_PER_WORD);

  return lReturnValue;
}

#if (DEM_CFG_SUPPORT_USER_CAS == STD_OFF)
/* ****************************************************************************
 % Dem_Com_DefaultSyncCompareAndSwap
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Com_DefaultSyncCompareAndSwap(
 volatile CONSTP2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) AddressPtr,
 CONST(Dem_Com_ProcessorWordType, AUTOMATIC) OldValue,
 CONST(Dem_Com_ProcessorWordType, AUTOMATIC) NewValue
 )
{
  boolean lReturnValue;

/* >>>> -------------------------------- Enter Critical Section: CrossCoreComm */
  Dem_EnterCritical_CrossCoreComm();

  if (*AddressPtr == OldValue)
  {
    *AddressPtr = NewValue;
    lReturnValue = TRUE;
  }
  else
  {
    lReturnValue = FALSE;
  }

  Dem_LeaveCritical_CrossCoreComm();
/* <<<< -------------------------------- Leave Critical Section: CrossCoreComm */

  return lReturnValue;
}
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \addtogroup Dem_Communication_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Com_SyncCompareAndSwap
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Com_SyncCompareAndSwap(
  volatile CONSTP2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) AddressPtr,
  CONST(Dem_Com_ProcessorWordType, AUTOMATIC) OldValue,
  CONST(Dem_Com_ProcessorWordType, AUTOMATIC) NewValue
  )
{
#if (DEM_CFG_SUPPORT_USER_CAS == STD_ON)
  return ApplDem_SyncCompareAndSwap(AddressPtr, OldValue, NewValue);
#else
  return Dem_Com_DefaultSyncCompareAndSwap(AddressPtr, OldValue, NewValue);
#endif
}

/* ****************************************************************************
 % Dem_Com_TestBitInBitfield
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Com_TestBitInBitfield(                                                                                                       /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  volatile CONSTP2CONST(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) BitfieldPtr,
  CONST(Dem_HandleType, AUTOMATIC) BitPosition
  )
{
  Dem_Com_ProcessorWordType lBitMask;
  lBitMask = DEM_BIT(Dem_Com_GetBitfieldBitIndex(BitPosition));

  return (boolean)((BitfieldPtr[Dem_Com_GetBitfieldWordIndex(BitPosition)] & lBitMask) != 0);
}

/* ****************************************************************************
 % Dem_Com_SyncSetBitInBitfield
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Com_SyncSetBitInBitfield(
  volatile CONSTP2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) BitfieldPtr,
  CONST(Dem_HandleType, AUTOMATIC) BitfieldSize,
  CONST(Dem_HandleType, AUTOMATIC) BitPosition
  )
{
  volatile P2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) lWordPtr;
  Dem_Com_ProcessorWordType lOldValue;
  Dem_Com_ProcessorWordType lNewValue;
  Dem_Com_ProcessorWordType lBitMask;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(BitfieldSize)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Dem_Com_GetBitfieldWordIndex(BitPosition) >= BitfieldSize)
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    lWordPtr = &BitfieldPtr[Dem_Com_GetBitfieldWordIndex(BitPosition)];
    lBitMask = DEM_BIT(Dem_Com_GetBitfieldBitIndex(BitPosition));
    do
    {
      lOldValue = *lWordPtr;
      lNewValue = (lOldValue | lBitMask);
    }
    while (Dem_Com_SyncCompareAndSwap(lWordPtr, lOldValue, lNewValue) == FALSE);
  }
}

/* ****************************************************************************
 % Dem_Com_SyncResetBitInBitfield
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Com_SyncResetBitInBitfield(
  volatile CONSTP2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) BitfieldPtr,
  CONST(Dem_HandleType, AUTOMATIC) BitfieldSize,
  CONST(Dem_HandleType, AUTOMATIC) BitPosition
  )
{
  volatile P2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) lWordPtr;
  Dem_Com_ProcessorWordType lOldValue;
  Dem_Com_ProcessorWordType lNewValue;
  Dem_Com_ProcessorWordType lBitMask;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(BitfieldSize)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Dem_Com_GetBitfieldWordIndex(BitPosition) >= BitfieldSize)
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    lWordPtr = &BitfieldPtr[Dem_Com_GetBitfieldWordIndex(BitPosition)];
    lBitMask = (Dem_Com_ProcessorWordType) (~(DEM_BIT(Dem_Com_GetBitfieldBitIndex(BitPosition))));
    do
    {
      lOldValue = *lWordPtr;
      lNewValue = (lOldValue & lBitMask);
    } while (Dem_Com_SyncCompareAndSwap(lWordPtr, lOldValue, lNewValue) == FALSE);
  }
}

/* ****************************************************************************
 % Dem_Com_SetBitInBitfield
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Com_SetBitInBitfield(                                                                                                        /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  volatile CONSTP2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) BitfieldPtr,
  CONST(Dem_HandleType, AUTOMATIC) BitfieldSize,
  CONST(Dem_HandleType, AUTOMATIC) BitPosition
  )
{
  Dem_Com_ProcessorWordType lBitMask;
  volatile P2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) lWordPtr;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(BitfieldSize)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Dem_Com_GetBitfieldWordIndex(BitPosition) >= BitfieldSize)
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    lBitMask = DEM_BIT(Dem_Com_GetBitfieldBitIndex(BitPosition));
    lWordPtr = &BitfieldPtr[Dem_Com_GetBitfieldWordIndex(BitPosition)];
    *lWordPtr |= lBitMask;
  }
}

/* ****************************************************************************
 % Dem_Com_ResetBitInBitfield
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Com_ResetBitInBitfield(                                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  volatile CONSTP2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) BitfieldPtr,
  CONST(Dem_HandleType, AUTOMATIC) BitfieldSize,
  CONST(Dem_HandleType, AUTOMATIC) BitPosition
  )
{
  Dem_Com_ProcessorWordType lBitMask;
  volatile P2VAR(Dem_Com_ProcessorWordType, DEM_VAR_UNCACHED, AUTOMATIC) lWordPtr;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(BitfieldSize)                                                                                 /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Dem_Com_GetBitfieldWordIndex(BitPosition) >= BitfieldSize)
  {
    Dem_Error_RunTimeCheckFailed(__FILE__, __LINE__);
  }
  else
#endif
  {
    lBitMask = (Dem_Com_ProcessorWordType) (~(DEM_BIT(Dem_Com_GetBitfieldBitIndex(BitPosition))));
    lWordPtr = &BitfieldPtr[Dem_Com_GetBitfieldWordIndex(BitPosition)];
    *lWordPtr &= lBitMask;
  }
}

/*!
 * \}
 */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_COM_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Com_Implementation.h
 *********************************************************************************************************************/
