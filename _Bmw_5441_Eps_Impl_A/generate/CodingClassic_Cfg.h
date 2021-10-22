/**
 * \file
 *
 * \brief       Configuration file for Coding Classic Adapter
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.394027
*
------------------------------------------------------------------------------*/

#ifndef CODINGADAPTER_CFG_H
#define CODINGADAPTER_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"     /* BMW Platform Types             */
#include "CodingClassic_Version.h"   /* Coding Classic Adapter Version */

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!CodingClassic_CHECK_VERSION(5,2,1))
   #error "Version of CodingClassic_Cfg.h does not match the Classic adapter version!"
#endif

/* in Hz */
#define CODING_TIMER_FREQ                        10u


#endif /* CODINGADAPTER_CFG_H */
