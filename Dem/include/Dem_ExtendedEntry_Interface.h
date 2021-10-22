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
/*! \ingroup    Dem_MemoryEntry
 *  \defgroup   Dem_ExtendedEntry ExtendedEntry
 *  \{
 *  \file       Dem_ExtendedEntry_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Encapsulates the list of extended data record buffers stored in the memory entry
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

#if !defined (DEM_EXTENDEDENTRY_INTERFACE_H)
#define DEM_EXTENDEDENTRY_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_ExtendedEntry_Types.h"
/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */
/*!
 * \defgroup Dem_ExtendedEntry_Properties Properties
 * \{
 */

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
 * \defgroup Dem_ExtendedEntry_Private Private Methods
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
 * \defgroup Dem_ExtendedEntry_Public Public Methods
 * \{
 */

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorInit
 *****************************************************************************/
/*!
 * \brief         Initializes the extended entry iterator
 *
 * \details       Initializes the iterator to enumerate extended entries in 
 *                an memory entry
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 * \param[out]    ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorInit(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONSTP2VAR(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorNext
 *****************************************************************************/
/*!
 * \brief         Move the extended entry iterator to the next element
 *
 * \details       Move the extended entry iterator to the next element
 *
 * \param[in,out] ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \pre           ExtendedEntryIter has been initialized
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorNext(
  CONSTP2VAR(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorExists
 *****************************************************************************/
/*!
 * \brief         Test if the extended entry iterator points to a valid element
 *
 * \details       Test if the extended entry iterator points to a valid element
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \return        TRUE
 *                ExtendedEntryIter points to a valid element
 * \return        FALSE
 *                ExtendedEntryIter doesn't point to a valid element
 *
 * \pre           ExtendedEntryIter has been initialized
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_ExtendedEntry_IteratorExists(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorSetMemoryEntryHandle
 *****************************************************************************/
/*!
 * \brief         Set the memory entry handle 
 *
 * \details       Set the memory entry handle pointed to by the iterator
 *
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \pre           ExtendedEntryIter has been initialized
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorSetMemoryEntryHandle(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId,
  CONSTP2VAR(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorGetExtendedRecordIndex
 *****************************************************************************/
/*!
 * \brief         Get the extended record index 
 *
 * \details       Get the extended record index pointed to by the iterator
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \return        Handle to the extended record descriptor table
 *
 * \pre           ExtendedEntryIter has been initialized
 * \config        DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_Cfg_ERecIndexType, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedRecordIndex(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON) && (DEM_DEV_RUNTIME_CHECKS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorGetExtendedEntryIndex
 *****************************************************************************/
/*!
 * \brief         Get the extended entry index
 *
 * \details       Get the extended entry index pointed to by the iterator
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \return        Index of the extended data buffer in the memory entry
 *
 * \pre           ExtendedEntryIter has been initialized
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON &&
 *                DEM_DEV_RUNTIME_CHECKS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedEntryIndex(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorGetExtendedRecordDataPtr
 *****************************************************************************/
/*!
 * \brief         Get the extended data buffer
 *
 * \details       Get the extended data buffer at the index pointed to by the 
 *                iterator
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \return        Pointer to the extended data buffer
 *
 * \pre           ExtendedEntryIter has been initialized
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_SharedDataPtrType, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedRecordDataPtr(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorGetExtendedRecordDataConstPtr
 *****************************************************************************/
/*!
 * \brief         Get the extended data buffer
 *
 * \details       Get the extended data buffer at the index pointed to by the 
 *                iterator
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the Extended entry iterator
 *
 * \return        Pointer to the unmodifiable (const) extended data buffer
 *
 * \pre           ExtendedEntryIter has been initialized
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_ConstSharedDataPtrType, DEM_CODE)
Dem_ExtendedEntry_IteratorGetExtendedRecordDataConstPtr(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );                                                                                                                             /* PRQA S 0779 */ /* MD_MSR_5.1_779 */
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorIsExtendedRecordStored
 *****************************************************************************/
/*!
 * \brief         Tests whether an extended record is currently stored
 *
 * \details       Tests whether an extended record pointed to by the iterator 
 *                is currently stored
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \return        TRUE
 *                The extended record is stored
 * \return        FALSE
 *                The extended record is not stored
 *
 * \pre           ExtendedEntryIter->MemoryEntryId must be inside valid range
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_ExtendedEntry_IteratorIsExtendedRecordStored(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_IteratorUpdateExtendedEntry
 *****************************************************************************/
/*!
 * \brief         Set the 'stored' flag for an extended entry
 *
 * \details       Set the corresponding bit in the extended header of the
 *                memory entry
 *
 * \param[in]     ExtendedEntryIter
 *                Pointer to the extended entry iterator
 *
 * \pre           ExtendedEntryIter->MemoryEntryId must be inside valid range
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_IteratorUpdateExtendedEntry(
  CONSTP2CONST(Dem_ExtendedEntry_IterType, AUTOMATIC, AUTOMATIC)  ExtendedEntryIter
  );
#endif

#if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_ExtendedEntry_ResetStoredExtendedRecords
 *****************************************************************************/
/*!
 * \brief         Reset the stored extended records in a memory entry
 *
 * \details       Reset the stored extended records in a memory entry
 *
 * \param[in]     MemoryEntryId
 *                The memory entry handle
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_USER_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_ExtendedEntry_ResetStoredExtendedRecords(
  CONST(Dem_MemoryEntry_HandleType, AUTOMATIC)  MemoryEntryId
  );
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DEM_EXTENDEDENTRY_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ExtendedEntry_Interface.h
 *********************************************************************************************************************/
