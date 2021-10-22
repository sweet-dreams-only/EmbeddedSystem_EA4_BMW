/**
 * \file
 *
 * \brief       Dlog UDS adapter.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2016
 *
 * \version     5.1.1
 *
 */

#ifndef BPS_DLOG_UDSADAPTER_H
#define BPS_DLOG_UDSADAPTER_H

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
#error "Version of Dlog_UDSAdapter.h does not match the version of the module!"
#endif


#ifdef __cplusplus
extern "C" {
#endif

void Dlog_UDS_ReadDataSvkCurrent_ResultOk(const uint8* responseData, size_t resDataLength);
void Dlog_UDS_ReadDataSvkCurrent_ResultError(UDS_ErrorCodeType errorCode);

void Dlog_UDS_ReadDataSvkHistory_ResultOk(const uint8* responseData, size_t resDataLength);
void Dlog_UDS_ReadDataSvkHistory_ResultError(UDS_ErrorCodeType errorCode);

void Dlog_UDS_RoutineControlReadDevelopmentInfo_ResultOk(const uint8* responseData, size_t resDataLength);
void Dlog_UDS_RoutineControlReadDevelopmentInfo_ResultError(UDS_ErrorCodeType errorCode);

#ifdef __cplusplus
}
#endif


#endif /* BPS_DLOG_UDSADAPTER_H */
