/**
*  \file
*
*  \brief       BMW SWC SysTime
*
*  This file is the generated version header file of the SysTime module
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
*  GENERATION TIME : 2018-07-30 19:57:44.108499
*
------------------------------------------------------------------------------*/

#ifndef SYSTIME_VERSION_H
#define SYSTIME_VERSION_H


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief SysTime header major version
 */
#define SysTime_MAJOR_VERSION        (5u)

/**
 * \brief SysTime header minor version
 */
#define SysTime_MINOR_VERSION        (0u)

/**
 * \brief SysTime header patch version
 */
#define SysTime_PATCH_VERSION        (3u)


/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 2 */
#define SysTime_CHECK_VERSION(major,minor,patch) \
 (((major) == SysTime_MAJOR_VERSION) && ((minor) == SysTime_MINOR_VERSION) && ((patch) == SysTime_PATCH_VERSION))

#endif /* SYSTIME_VERSION_H */
