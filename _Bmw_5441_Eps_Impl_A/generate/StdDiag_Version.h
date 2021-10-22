/**
*  \file
*
*  \brief       BMW SWC StdDiag
*
*  This file is the generated version header file of the StdDiag module
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.0
*
*  \remarks     --
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:43.534441
*
------------------------------------------------------------------------------*/

#ifndef StdDiag_VERSION_H
#define StdDiag_VERSION_H


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief StdDiag header major version
 */
#define StdDiag_MAJOR_VERSION        (5u)

/**
 * \brief StdDiag header minor version
 */
#define StdDiag_MINOR_VERSION        (3u)

/**
 * \brief StdDiag header patch version
 */
#define StdDiag_PATCH_VERSION        (0u)


/*
   MISRA-C:2004 Rule 19.7: this macro is only used in preprocessor directive, no function possible
*/
/* PRQA S 3453 2 */
#define StdDiag_CHECK_VERSION(major,minor,patch) \
 (((major) == StdDiag_MAJOR_VERSION) && ((minor) == StdDiag_MINOR_VERSION) && ((patch) == StdDiag_PATCH_VERSION))

#endif /* StdDiag_VERSION_H */
