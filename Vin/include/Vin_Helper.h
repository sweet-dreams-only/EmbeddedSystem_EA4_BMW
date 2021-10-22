/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file contains helper macros for checking the VIN.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     3.5.0
*
*  \remarks     -
*
*/
/*----------------------------------------------------------------------------*/

#ifndef VIN_HELPER_H_
#define VIN_HELPER_H_

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*
 * MISRA-C:2004 Rule 19.7: C90 does not support fully specify inline functions.
 * See PRQA 3453. */

/*
 * MISRA-C:2004 Rule 19.12: The order of evaluation of the ## operators is irrelevant.
 * See PRQA 0881. */

/*
 * MISRA-C:2004 Rule 19.13: The ## operator is necessary.
 * See PRQA 0342. */



/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Vin_Version.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_Helper.h does not match the version of the module!"
#endif


/**
 * Check the given VIN qualifier
 *
 * \param[in] qualifier The qualifier of Vin_VinType
 * \param[in] check     This can be one of
 *                       - VIN_CQ_VIN_RECEIVED  The VIN has been received
 *                       - VIN_CQ_VIN_SECURE    The VIN is secure
 *                       - VIN_CQ_VIN_UNSAFE    Only plain VIN in a unsafe environment
 *
 */
/* PRQA S 0342,0881 1 */
#define VIN_CHECKQUALIFIER(qualifier, check) VIN_CHECKQUALIFIER_INT(qualifier, check##_POS, check##_NEG)

/* PRQA S 3453 1 */
#define VIN_CHECKQUALIFIER_INT(qualifier, poscheck, negcheck) ((((qualifier) & (poscheck)) == (poscheck)) && (((qualifier) & (negcheck)) == 0u))


#define VIN_CQ_VIN_RECEIVED_POS VIN_QUAL_RECEIVED
#define VIN_CQ_VIN_RECEIVED_NEG 0u

#define VIN_CQ_VIN_SECURE_POS (VIN_QUAL_RECEIVED | VIN_QUAL_SECURE_FINISHED | VIN_QUAL_SECURE_OK)
#define VIN_CQ_VIN_SECURE_NEG VIN_QUAL_SECURE_PENDING

#define VIN_CQ_VIN_UNSAFE_POS VIN_QUAL_RECEIVED
#define VIN_CQ_VIN_UNSAFE_NEG (VIN_QUAL_SECURE_PENDING | VIN_QUAL_SECURE_FINISHED | VIN_QUAL_SECURE_OK)

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#endif /* VIN_HELPER_H_ */

/*--- End of file ------------------------------------------------------------*/
