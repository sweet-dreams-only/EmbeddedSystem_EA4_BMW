/**
 * \file
 *
 * \brief       The functions declared here have to be implemented by the user.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.3.1
 *
 */

#ifndef DLOG_USER_H_
#define DLOG_USER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "DlogClassic_Cfg.h"

#if ( DLOG_ENABLE_RTE == STD_ON )
#include <Rte_Dlog_Type.h>
#else
#include "Dlog_Rte2C.h"
#include "Dcm_Types.h"               /* DCM Types                             */
#include "Dlog_Swe.h"     /* for Dlog_SweProgDepStateType */
#endif


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_User.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#if (DLOG_ENABLE_MULTI_CPU == STD_ON)

#if ( DLOG_ENABLE_ECU == STD_ON )
/*----------------------------------------------------------------------------*/
/**
 *  Reads the development info field of a user XWE.
 *
 *  \param[in]  SgbmId                 The SGBM-ID of the user XWE
 *  \param[in]  UserOpStatus           See DCM specification
 *  \param[out] UserData               The development info field
 *  \param[out] UserDataLength         The length of the development info field
 *  \param[out] UserErrorCode          Error Code in case E_NOT_OK is returned
 *
 *  \return E_OK                 Development info field returned successfully.
 *  \return DCM_E_PENDING        In progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserReadDevelopmentInfoField
                      (
                         const uint8* SgbmId,
                         Dcm_OpStatusType UserOpStatus,
                         uint8* UserData,
                         uint16* UserDataLength,
                         Dcm_NegativeResponseCodeType* UserErrorCode
                      );
#endif

#if ( DLOG_ENABLE_SVK_CURRENT == STD_ON )
/*----------------------------------------------------------------------------*/
/**
 *  Gets the number of current user SVK entries.
 *
 *  \param[in]  UserOpStatus           See DCM specification
 *  \param[out] UserNumberOfSvkEntries The number of user SVK history entries
 *
 *  \return E_OK                 Number of current user SVK entries returned successfully.
 *  \return DCM_E_PENDING        In progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserNumberOfSvkCurrent
                      (
                         Dcm_OpStatusType UserOpStatus,
                         uint16* UserNumberOfSvkEntries
                      );

/*----------------------------------------------------------------------------*/
/**
 *  Reads the current user SVK entries.
 *
 *  \param[in]  UserOpStatus           See DCM specification
 *  \param[out] UserData               The list of current user SVK entries (one entry should be exactly 8 bytes)
 *  \param[out] UserNumberOfSvkEntries The number of current user SVK entries
 *
 *  \return E_OK                 Number of user SVK history entries returned successfully.
 *  \return DCM_E_PENDING        In progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserReadSvkCurrent
                      (
                         Dcm_OpStatusType UserOpStatus,
                         uint8* UserData,
                         uint16* UserNumberOfSvkEntries
                      );

/*----------------------------------------------------------------------------*/
/**
 *  Gets the programming dependency state of the user SWEs.
 *
 *  \param[out] ProgDepState           The programming dependency state
 *
 *  \return E_OK                 Development info field returned successfully.
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserGetProgDepState
                      (
                         Dlog_UserSweProgDepStateType* ProgDepState
                      );

#if ( DLOG_ENABLE_SVK_HISTORY == STD_ON )
/*----------------------------------------------------------------------------*/
/**
 *  Gets the number of user SVK history entries.
 *
 *  \param[in]  UserHistoryIndex       Selects the history memory. Will be one of DLOG_HISTORY_SYSTEMSUPPLIER,
 *                                     DLOG_HISTORY_PLANT or DLOG_HISTORY_BACKUP_<x>
 *  \param[in]  UserOpStatus           See DCM specification
 *  \param[out] UserNumberOfSvkEntries The number of user SVK history entries
 *
 *  \return E_OK                 Number of user SVK history entries returned successfully.
 *  \return DCM_E_PENDING        In progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserNumberOfSvkHistory
                      (
                         Dlog_HistoryType UserHistoryIndex,
                         Dcm_OpStatusType UserOpStatus,
                         uint16* UserNumberOfSvkEntries
                      );

/*----------------------------------------------------------------------------*/
/**
 *  Reads the user SVK history entries.
 *
 *  \param[in]  UserHistoryIndex       Selects the history memory. Will be one of DLOG_HISTORY_SYSTEMSUPPLIER,
 *                                     DLOG_HISTORY_PLANT or DLOG_HISTORY_BACKUP_<x>
 *  \param[in]  UserOpStatus           See DCM specification
 *  \param[out] UserData               The list of user SVK history entries (one entry should be exactly 8 bytes)
 *  \param[out] UserNumberOfSvkEntries The number of user SVK history entries
 *
 *  \return E_OK                 Number of user SVK history entries returned successfully.
 *  \return DCM_E_PENDING        In progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserReadSvkHistory
                      (
                         Dlog_HistoryType UserHistoryIndex,
                         Dcm_OpStatusType UserOpStatus,
                         uint8* UserData,
                         uint16* UserNumberOfSvkEntries
                      );

/*----------------------------------------------------------------------------*/
/**
 *  Write the current user SVK to user SVK history memory.
 *
 *  \param[in] UserHistoryIndex  Selects the history memory to be written. Will be one of
 *                               DLOG_HISTORY_SYSTEMSUPPLIER, DLOG_HISTORY_PLANT or DLOG_HISTORY_BACKUP_0
 *  \param[in] UserOpStatus      See DCM specification
 *
 *  \return E_OK                 User history memory written successfully.
 *  \return DCM_E_PENDING        Write in progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserWriteSvkHistory
                      (
                         Dlog_HistoryType UserHistoryIndex,
                         Dcm_OpStatusType UserOpStatus
                      );

#endif /* #if ( DLOG_ENABLE_SVK_HISTORY == STD_ON ) */

#endif /* #if ( DLOG_ENABLE_SVK_CURRENT == STD_ON ) */

#if ( DLOG_ENABLE_MEMSEGTABLE_READ == STD_ON )
/*----------------------------------------------------------------------------*/
/**
 *  Gets the number of user memory segmentation table entries.
 *
 *  \param[in]  UserOpStatus                               See DCM specification
 *  \param[out] UserNumberOfMemorySegmentationTableEntries The number of user memory segmentation entries
 *
 *  \return E_OK                 Number of user memory segmentation entries returned successfully.
 *  \return DCM_E_PENDING        In progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserNumberOfMemorySegmentationTableEntries
                      (
                         Dcm_OpStatusType UserOpStatus,
                         uint16* UserNumberOfMemorySegmentationTableEntries
                      );

/*----------------------------------------------------------------------------*/
/**
 *  Reads the user memory segmentation table.
 *
 *  The memory segmentation table is a list of memory segmentation table entries, each of the following format:
 *
 *  Size | Description
 *  ---- | --------------------
 *   4   | start address
 *   4   | size of each segment
 *   2   | number of segments
 *
 *  All values shall be in big endian byte order.
 *
 *  \param[in]  UserOpStatus           See DCM specification
 *  \param[out] UserData               The user memory segmentation table (one entry should be exactly 10 bytes)
 *  \param[out] UserNumberOfMemorySegmentationTableEntries The number of user memory segmentation entries
 *
 *  \return E_OK                 Number of user SVK history entries returned successfully.
 *  \return DCM_E_PENDING        In progress. The function will be called again with UserOpStatus=DCM_PENDING
 *  \return E_NOT_OK             Error
 *
 */
/*----------------------------------------------------------------------------*/
extern Std_ReturnType Dlog_UserReadMemorySegmentationTable
                      (
                         Dcm_OpStatusType UserOpStatus,
                         uint8* UserData,
                         uint16* UserNumberOfMemorySegmentationTableEntries
                      );
#endif

#endif /* #if (DLOG_ENABLE_MULTI_CPU == STD_ON) */

/*----------------------------------------------------------------------------*/
/**
 * Called to trigger an ECC check. On CPUs, where an ECC error does not directly lead
 * to an exception, this function shall check whether an ECC error occurred and call
 * Dlog_RomAccessExceptionHandler if necessary. On other CPUs,  Dlog_RomAccessExceptionHandler
 * should be called directly in the context of the exception, and this function can be left empty.
 *
 * \param[in] sweId SWE that has just been checked
 *
 * \remark The sweId might be needed, if the address of the ECC error cannot be determined.
 *
 */
/*----------------------------------------------------------------------------*/
extern void Dlog_UserTriggerEccCheck(uint8 sweId);

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif /* DLOG_USER_H_ */
