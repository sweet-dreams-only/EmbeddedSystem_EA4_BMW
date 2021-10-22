/**
 * \file
 *
 * \brief       Coding ErrMem Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_ERRMEMADAPTER_H_
#define CODING_ERRMEMADAPTER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_Version.h"            /* Coding Version         */
#include "BUtil/GenericErrMemTypes.h"  /* BMW Error Memory Types */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_ErrMemAdapter.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern ErrMem_ResultType Coding_ErrMem_ClearEventAllowedNotCoded(ErrMem_ClearEventAllowedType clearEventAllowed);

extern ErrMem_ResultType Coding_ErrMem_SetEventStatusNotCoded(ErrMem_EventStatusType eventStatus);

extern ErrMem_ResultType Coding_ErrMem_SetEventStatusWrongVehicle(ErrMem_EventStatusType eventStatus);

extern ErrMem_ResultType Coding_ErrMem_SetEventStatusUnqualifiedData(ErrMem_EventStatusType eventStatus);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_ERRMEMADAPTER_H_ */
