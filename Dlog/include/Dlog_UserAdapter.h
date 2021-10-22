/**
 * \file
 *
 * \brief       Dlog User adapter.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2016
 *
 * \version     5.1.1
 *
 */

#ifndef BPS_DLOG_USERADAPTER_H
#define BPS_DLOG_USERADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_Version.h"

#include "BUtil/PlatformTypes.h"
#include "BUtil/GenericUDSTypes.h"

#include <stddef.h>


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_UserAdapter.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Reads the current user SVK entries.
 *
 * \param data        The list of current user SVK entries (one entry should be exactly 8 bytes)
 * \param numberOfSvk The number of current user SVK entries
 * \retval UDS_DIAG_JOB_FINISHED_OK Current user SVK entries read successfully.
 */
UDS_ReturnType Dlog_User_ReadSvkCurrent(uint8* data, uint16* numberOfSvk);

/**
 *
 * \param historyIndex 0=SysSupp, 1=Plant, 2...n=Backup1...n-1
 * \param data         SVK data
 * \param numberOfSvk  number of SVK entries in data
 * \retval UDS_DIAG_JOB_FINISHED_OK User SVK history entries read successfully.
 */
UDS_ReturnType Dlog_User_ReadSvkHistory(uint8 historyIndex, uint8* data, uint16* numberOfSvk);

/**
 * Reads the Development Info Field of a user SWE
 *
 * \param[in]  sgbmId
 * \param[out] developmentInfoField
 * \param[in]  developmentInfoFieldLength
 * \retval UDS_DIAG_JOB_FINISHED_OK User SWE Development Info Field read successfully.
 */
UDS_ReturnType Dlog_User_ReadDevelopmentInfoField(
    const uint8* sgbmId,
    uint8* developmentInfoField,
    size_t* developmentInfoFieldLength);

#ifdef __cplusplus
}
#endif

#endif /* BPS_DLOG_USERADAPTER_H */
