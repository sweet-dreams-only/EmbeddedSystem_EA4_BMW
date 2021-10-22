/**
 * \file
 *
 * \brief       Coding Data
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

#ifndef CODING_DATA_H_
#define CODING_DATA_H_

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding.h"          /* Coding_DataType */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_Data.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Stores the coding data.
 *
 * \lhref COD_091
 *
 */
extern Coding_DataType Coding_CodingData;

#define Coding_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

#define Coding_START_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Stores the coding data default.
 *
 * \lhref COD_091
 *
 */
extern const Coding_DataType Coding_CodingDataDefault;

#define Coding_STOP_SEC_CONST_SAVED_RECOVERY_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_DATA_H_ */
