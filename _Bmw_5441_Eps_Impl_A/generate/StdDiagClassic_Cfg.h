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
*  \version     5.4.0
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
*  GENERATION TIME : 2018-07-30 19:57:43.130401
*
------------------------------------------------------------------------------*/


#ifndef STDDIAGCLASSIC_CFG_H
#define STDDIAGCLASSIC_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"
#include "StdDiagClassic_Version.h"

/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!StdDiagClassic_CHECK_VERSION(5,4,0))
   #error "Version of StdDiagClassic_Cfg.h does not match the version of the module!"
#endif


/**
 * \brief Definition of groupOfDTC for all DTCs according to ISO14229-1 Annex D.1
 */
#define STDDIAG_DTCGROUP_ALL_DTCS       0xFFFFFFu

/**
 * \brief clear secondary error memory
 *
 * This parameter determines whether clearing of the secondary error memory shall be supported
 * STD_ON  : clearing of the secondary error memory shall be supported
 * STD_OFF : clearing of the secondary error memory shall not be supported
 */
#define STDDIAG_CLEAR_SEC_ERROR_MEMORY  STD_ON

/**
 * \brief User defined memory name
 *
 * This parameter determines the value to address the user defined memory
 * representing the BMW secondary error memory.
 */
#define STDDIAG_SECONDARY_ERROR_MEMORY DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory

/**
 * \brief Diagnostic Log and Trace support
 *
 * This parameter determines whether the StdDiag module provides an implementation
 * for Diagnostic Log and Trace support.
 * STD_ON  : DLT support is provided
 * STD_OFF : DLT support is not provided
 */
#define STDDIAG_DLT_SUPPORT  STD_OFF

/**
 * \brief Application Data Transfer support
 *
 * This parameter determines whether the StdDiag module provides support
 * for Application Data Transfer.
 * STD_ON  : ADT support is provided
 * STD_OFF : ADT support is not provided
 */
#define STDDIAG_ADT_SUPPORT  STD_OFF

#endif /* STDDIAGCLASSIC_CFG_H */


