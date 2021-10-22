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
*  GENERATION TIME : 2018-07-30 19:57:44.044492
*
------------------------------------------------------------------------------*/


#ifndef SYSTIME_CFG_H
#define SYSTIME_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "SysTime_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!SysTime_CHECK_VERSION(5,0,3))
   #error "Version of SysTime_Cfg.h does not match the version of the module!"
#endif


/**
 * \brief development error detection
 *
 * This parameter determines whether development error tracing is
 * enabled or disabled.
 * STD_ON  : development error tracing is enabled
 * STD_OFF : development error tracing is disabled
 */
#define SYSTIME_DEV_ERROR_DETECT          STD_OFF

/**
 * \brief task cycle of the main function
 *
 * This parameter determines the cycle rate in milliseconds, in which the
 * SysTime_MainFunction() is triggered.
 */
#define SYSTIME_MAINTASKCYCLE    10u

/**
 * \brief initial timeout value
 *
 * This parameter determines the initial timeout value milliseconds, after which the
 * system time is set to 0xFFFFFFFF.
 */
#define SYSTIME_INITIALTIMEOUT   5000u

#endif /* SYSTIME_CFG_H */
