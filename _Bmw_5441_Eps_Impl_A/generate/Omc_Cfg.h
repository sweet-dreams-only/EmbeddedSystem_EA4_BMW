/**
*  \file
*
*  \brief       Omc Configuration
*
*  Configuration file for Omc
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.0
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.350023
*
------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

#ifndef OMC_CFG_H
#define OMC_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h" /* BMW standard types                         */
#include "Omc_Version.h"        /* Omc Version                                */

#ifdef __cplusplus
extern "C" {
#endif
/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!Omc_CHECK_VERSION(5,1,0))
   #error "Version of Omc_Cfg.h does not match the version of the module!"
#endif

#define OMC_DEV_ERROR_DETECT   STD_OFF

#define OMC_OPMODECALLOUT       STD_OFF
#define OMC_EXTOPMODECALLOUT    STD_OFF
#ifdef __cplusplus
}
#endif

#endif /* OMC_CFG_H */

/*--- End of file ------------------------------------------------------------*/
