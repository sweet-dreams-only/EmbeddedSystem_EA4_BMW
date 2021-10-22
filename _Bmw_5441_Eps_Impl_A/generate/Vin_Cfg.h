


/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file contains the implementation of the BMW SWC Vin
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user: no
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     3.5.0
*
*  \remarks     --
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : artt 2.0.2.0
*
*  GENERATION TIME : 30.07.2018 19:57:42
*
------------------------------------------------------------------------------*/

#ifndef VIN_CFG_H
#define VIN_CFG_H



/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include <Std_Types.h>               /* AUTOSAR standard types */
#include "Vin_Version.h"            /* Own version header file */


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Vin_CHECK_VERSION(3,5,0))
   #error "Version of Vin_Cfg.h does not match the version of the module!"
#endif


/** The instance ID of the Vin module for usage in the DET */
#define VIN_DET_INSTANCE_ID 0U

#define VIN_RANDOM_NUMBER_GENERATOR_API_ID     1U
#define VIN_RTE_API_ID                         2U
#define VIN_NVM_API_ID                         3U
#define VIN_INTERNAL_API_ID                   99U

/**
 * \brief Switch for development error detection
 *
 * Activation of development error detection
 *
 * \remarks This macro depends on configuration parameter VinDevErrorDetect
 *
 */

#define Vin_DEV_ERROR_DETECT   STD_OFF

#define Vin_Assert(condition, apiId, errorCode) do {} while(0)



/**
 * If set to STD_ON, the Fscsm module will be used to receive and check the
 * secure VIN.
 */

#define Vin_ENABLE_SECURE_VIN   STD_OFF



#define Vin_ENABLE_SI_ADAPTER   STD_OFF



/**
 * The ID to be used to request the VIN signal
 */
#define VIN_VINREQUEST_MESSAGE_IDENTIFIER 32771u

/**
 * Timeout between init an first VIN request in 100ms => 3=300ms
 */
#define VIN_TIMEOUT_INIT        3u

/**
 * Timeout between a request and the next request in 100ms => 10=1s
 */
#define VIN_TIMEOUT_REQUEST     10u

/**
 * Maximum number of VIN requests.
 */
#define VIN_MAX_NUMBER_REQUESTS 4u

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Function Declarations
------------------------------------------------------------------------------*/

#endif /* VIN_CFG_H */

/*--- End of file ------------------------------------------------------------*/
