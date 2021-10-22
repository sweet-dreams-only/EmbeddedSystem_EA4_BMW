/**
 * \file
 *
 * \brief       Coding Concurrency Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_CONCADAPTER_H_
#define CODING_CONCADAPTER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding_Version.h"  /* Coding Version                                */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_ConcAdapter.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern void Coding_CritSect_Data_Enter(void);

extern void Coding_CritSect_Data_Exit(void);

extern void Coding_CritSect_State_Enter(void);

extern void Coding_CritSect_State_Exit(void);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_CONCADAPTER_H_ */
