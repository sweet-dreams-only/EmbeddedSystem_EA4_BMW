/**
 * \file
 *
 * \brief       Configuration header file of module Dlog.
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2015 - 2017
 *
 * \version     5.1.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.538042
*
------------------------------------------------------------------------------*/


#ifndef BPS_DLOG_CFG_H
#define BPS_DLOG_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "Dlog_Version.h"
#include "BUtil/PlatformTypes.h"


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Dlog_CHECK_VERSION(5,1,1))
#error "Version of Dlog_Cfg.h does not match the version of the module!"
#endif

#define DLOG_MAX_NUMBER_OF_SWE_GROUPS 8u


/**
 * This parameter determines whether development error tracing is
 * enabled or disabled.
 * STD_ON  : development error tracing is enabled
 * STD_OFF : development error tracing is disabled
 */
#define DLOG_DEV_ERROR_DETECT           STD_OFF

#define DLOG_ENABLE_ECU              STD_ON

#define DLOG_ENABLE_SVK_CURRENT      STD_ON


#define DLOG_ENABLE_SVK_WRITE        STD_ON
#define DLOG_ENABLE_SVK_HISTORY      STD_ON
#define DLOG_NUMBEROFSVKBACKUPS      0u
#define DLOG_MAXNUMBEROFSVKSGBMIDS   6u



#endif /* BPS_DLOG_CFG_H */
