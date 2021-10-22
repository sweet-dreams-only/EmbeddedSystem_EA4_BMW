/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the configuration header file of the module StdDiag
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.0
*
*  \remarks     The StdDiag module is responsible for BMW specific session
*               handling and handles a number of BMW specific diagnostic requests.
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:43.234411
*
------------------------------------------------------------------------------*/


#ifndef STDDIAG_CFG_H
#define STDDIAG_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiag_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiag_CHECK_VERSION(5,3,0))
   #error "Version of StdDiag_Cfg.h does not match the version of the module!"
#endif


/**
 * \brief development error detection
 *
 * This parameter determines whether development error tracing is
 * enabled or disabled.
 * STD_ON  : development error tracing is enabled
 * STD_OFF : development error tracing is disabled
 */
#define STDDIAG_DEV_ERROR_DETECT          STD_OFF

/**
 * \brief user establish intrinsic safety
 *
 * This parameter determines whether a user specific function for establishing
 * intrinsic safety is used.
 * STD_ON  : user specific function is used
 * STD_OFF : no user specific function is used
 */
#define STDDIAG_USER_ESTABLISH_INTRINSIC_SAFETY      STD_OFF

/**
 * \brief user programming precondition check
 *
 * This parameter determines whether a user specific function for checking
 * programming preconditions is used.
 * STD_ON  : user specific function is used
 * STD_OFF : no user specific function is used
 */
#define STDDIAG_USRPRECONDITIONCHECK      STD_OFF

/**
 * \brief the maximum number of checked preconditions
 *
 * This parameter determines the maximum number of checked programming preconditions.
 * StdDiag always checks PWF state, further preconditions have to be provided
 * by an application.
 */
#define STDDIAG_MAX_NUMBER_PRECOND 1

/**
 * \brief active session state support
 *
 * This parameter determines whether the StdDiag module provides a callout to get the
 * active session state for the UDS service 0x22 F1 00.
 * STD_ON  : callout is provided
 * STD_OFF : callout is not provided
 */
#define STDDIAG_USER_ACTIVE_SESSION_STATE  STD_ON

/**
 * \brief IDRL function (recovering the individual data) support
 *
 * This parameter determines whether the StdDiag module provides an implementation
 * for IDRL function (recovering the individual data).
 * STD_ON  : IDRL function is provided
 * STD_OFF : IDRL function is not provided
 */
#define STDDIAG_IDRL_SUPPORT              STD_OFF


#endif /* STDDIAG_CFG_H */
