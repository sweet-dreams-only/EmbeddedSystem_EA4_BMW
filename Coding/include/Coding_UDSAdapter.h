/**
 * \file
 *
 * \brief       Coding Uds Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_UDSADAPTER_H_
#define CODING_UDSADAPTER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil/GenericUDSTypes.h"     /* BMW Generic UDS Types */
#include "Coding.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_DlogAdapter.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern void Coding_UDS_RoutineControlcheckNCD_Start_ResultOk(Coding_ResultType result);

extern void Coding_UDS_RoutineControlcheckNCD_Start_ResultError(UDS_ErrorCodeType errorCode);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_UDSADAPTER_H_ */
