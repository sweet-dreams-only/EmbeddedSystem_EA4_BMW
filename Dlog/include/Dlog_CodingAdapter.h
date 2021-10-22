/**
 * \file
 *
 * \brief       Dlog Coding adapter.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2016
 *
 * \version     5.1.1
 *
 */

#ifndef BPS_DLOG_CODINGADAPTER_H
#define BPS_DLOG_CODINGADAPTER_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_Version.h"
#include "BUtil/PlatformTypes.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_Data.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get the CAF IDs from Coding module
 *
 * \param[out] data            the CAF IDs
 * \param[out] numberOfCafIds  number of CAF IDs written to data
 */
void Dlog_Coding_GetCafIds(uint8* data, uint16* numberOfCafIds);

#ifdef __cplusplus
}
#endif

#endif /* BPS_DLOG_CODINGADAPTER_H */