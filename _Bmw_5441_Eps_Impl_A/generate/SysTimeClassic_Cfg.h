/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file is the configuration header file of the module SysTime
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.0.3
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:44.017490
*
------------------------------------------------------------------------------*/


#ifndef SYSTIMECLASSIC_CFG_H
#define SYSTIMECLASSIC_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "SysTimeClassic_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTimeClassic_CHECK_VERSION(5,0,3))
   #error "Version of SysTimeClassic_Cfg.h does not match the version of the module!"
#endif

/**
 * \brief Service Interface
 *
 * This parameter determines whether a Service Interface is used.
 * STD_ON  : Service Interface is used to receive system time
 * STD_OFF : Signal is used to receive system time
 */
#define SYSTIME_SERVICE_INTERFACE          STD_OFF

#endif /* SYSTIMECLASSIC_CFG_H */
