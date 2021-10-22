/**
 * \file
 *
 * \brief       Coding Application Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_APPLADAPTER_H_
#define CODING_APPLADAPTER_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_ApplAdapter.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern Coding_ReturnType Coding_Appl_CheckPlausibility(void);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_APPLADAPTER_H_ */
