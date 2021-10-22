/**
*  \file
*
*  \brief       BMW SWC StmClassic_Cfg
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
*  GENERATION TIME : 2018-07-30 19:57:43.938482
*
------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef STMCLASSIC_CFG_H
#define STMCLASSIC_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "StmClassic_Version.h"        /* Stm Version */
#include "BUtil/PlatformTypes.h"       /* BMW standard types */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief check version of the module
 */
#if (!StmClassic_CHECK_VERSION(5,2,0))
   #error "Version of StmClassic_Cfg.h does not match the Classic adapter version!"
#endif


#define STM_ENERGY_STATE_ENABLED          ( STD_ON )
#define STM_VEHICLE_STATE_ENABLED  ( STD_OFF )
/**
 * \brief Distinguish between Ethernet and Can/Flexray for different timeout handling
 */
#define STM_COM_VARIANT_FIELDS STD_OFF


/**
 * \brief Timeout time for CEL level 1 timeout in ms
 * \lhref  DMA_PA_8466
 */
#define STM_CEL_LVL_1_TIMEOUT_TIME  6000u

/**
 * \brief Timeout time for CEL level 2 timeout in ms
 *  \lhref  DMA_PA_8466
 */
#define STM_CEL_LVL_2_TIMEOUT_TIME  21000u

/**
 * \brief Post Build Option active
 */
#define STM_MULTIPLE_CONFIG_SETS_EXIST    ( STD_OFF )
/**
 * \brief Option to activate Code in PostBuild File
 */
#define STM_PBCFG_ENABLED STM_MULTIPLE_CONFIG_SETS_EXIST

#endif /* STMCLASSIC_CFG_H */

/*--- End of file ------------------------------------------------------------*/
