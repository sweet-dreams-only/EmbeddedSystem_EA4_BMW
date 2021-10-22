/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Dlog Version Information
*
*  This file is a generated version header file
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [yes/no]
*
*  \copyright   BMW AG 2015 - 2016
*
*  \version     5.1.1
*
*  \remarks     ---
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:40.813169
*
------------------------------------------------------------------------------*/

#ifndef DLOG_VERSION_H
#define DLOG_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Dlog header major version
 */
#define Dlog_MAJOR_VERSION        (5u)

/**
 * \brief Dlog header minor version
 */
#define Dlog_MINOR_VERSION        (1u)

/**
 * \brief Dlog header patch version
 */
#define Dlog_PATCH_VERSION        (1u)


/* PRQA S 3453 2 */ /* Macro used for precompile version check */
#define Dlog_CHECK_VERSION(major,minor,patch) \
 (((major) == Dlog_MAJOR_VERSION) && ((minor) == Dlog_MINOR_VERSION) && ((patch) == Dlog_PATCH_VERSION))


#endif /* DLOG_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
