/**
*  \file
*
*  \brief       BMW SWC Stm_Cfg
*
*  Configuration file for Stm
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.2.0
*
*  \remarks     File is generated with PAGe
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:44.005488
*
------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef STM_CFG_H
#define STM_CFG_H

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "StmClassic_Version.h"        /* Stm Version  */
#include "BUtil/PlatformTypes.h"    /* BMW standard types */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of Stm_Cfg.h does not match the Classic adapter version!"
#endif


#define STM_CENTRAL_ERROR_LOCK_ENABLED    ( STD_ON )
#endif /* STM_CFG_H */

/*--- End of file ------------------------------------------------------------*/
