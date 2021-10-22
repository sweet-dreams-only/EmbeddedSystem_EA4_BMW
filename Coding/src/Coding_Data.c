/**
 * \file
 *
 * \brief       Coding Data
 *
 * This file contains the RAM mirror of Coding data.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Coding.h"          /* Coding_DataType */
#include "Coding_Data.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Coding_CHECK_VERSION(5, 2, 1))
#error "Version of Coding_Data.c does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

#define Coding_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */

/**
 * \brief Stores the coding data.
 *
 * \lhref COD_091
 *
 */
Coding_DataType Coding_CodingData;

#define Coding_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Coding_MemMap.h" /* PRQA S 5087 */
