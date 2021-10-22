/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Configuration header file of module Srv.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015
*
*  \version     3.1.0
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : artt 2.0.2.0
*
*  GENERATION TIME : 30.07.2018 19:57:35
*
------------------------------------------------------------------------------*/

#ifndef SRV_CFG_H
#define SRV_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/
#include "Srv_Version.h"             /* Own version header file                */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Srv_CHECK_VERSION(3,1,0))
   #error "Version of Srv_Cfg.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                        Configuration Section
------------------------------------------------------------------------------*/

/**
 * This parameter determines whether the hardware can and should handle
 * ECC errors in RAM.
 */
#define SRV_HANDLE_ECC_RAM           STD_ON

/**
 * This parameter determines whether the hardware can and should handle
 * ECC errors in ROM.
 */
#define SRV_HANDLE_ECC_ROM           STD_ON

/**
 * This parameter selects, whether this ECU is a multi CPU ECU.
 * If enabled, some modules like Dlog and Prog require additional
 * user defined functions to handle communication with slave CPUs.
 * STD_ON  : ECU is a multi CPU ECU
 * STD_OFF : ECU is a single CPU ECU
 */
#define SRV_MULTI_CPU_ENABLE               STD_OFF


/** Minimum feature set for Blu */
#define SRV_BM_DISABLED     0x10
/** Reduced feature set for Bootmanager */
#define SRV_BM_ENABLED      0x20
/** Full feature set */
#define SRV_BM_ENABLED_DCM  0x30

/**
 * This parameter selects, which feature set shall be activated.
 */
#define SRV_FEATURE_BOOTMODE SRV_BM_ENABLED_DCM

/**
 * Defines the format identifiers for address, length and address and length format.
 *
 * \remark According to FP5_5871 the ECUs shall only support one valid addess and
 *         lengh format identifier
 */
typedef enum {
   SRV_ADDRESS_FORMAT_IDENTIFIER = 0x04u,
   SRV_LENGTH_FORMAT_IDENTIFIER  = 0x40u,
   SRV_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER = SRV_ADDRESS_FORMAT_IDENTIFIER | SRV_LENGTH_FORMAT_IDENTIFIER
} Srv_FormatIdentifier;

#define SRV_SIZEOF_OF_ADDRESS_PARAM                                           \
                (SRV_ADDRESS_FORMAT_IDENTIFIER)
#define SRV_SIZEOF_OF_LENGTH_PARAM                                            \
                (SRV_LENGTH_FORMAT_IDENTIFIER >> 0x04u)
#define SRV_SIZEOF_OF_ADDRESS_AND_LENGTH_PARAMS                               \
                (SRV_SIZEOF_OF_ADDRESS_PARAM + SRV_SIZEOF_OF_LENGTH_PARAM)

#endif /* SRV_CFG_H */


/*** End of file **************************************************************/
