/**
*  \file
*
*  \brief       BUtil Version Information
*
*  This file is a generated version header file
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
*  GENERATOR       : <#= GeneratorName #> <#= GeneratorVersion #>
*
*  GENERATION TIME : <#= DateTime.Now.ToString("dd.MM.yyyy HH:mm:ss") #>
*
------------------------------------------------------------------------------*/

#ifndef BUTIL_VERSION_H
#define BUTIL_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief BUtil header major version
 */
#define BUtil_MAJOR_VERSION        (5u)

/**
 * \brief BUtil header minor version
 */
#define BUtil_MINOR_VERSION        (0u)

/**
 * \brief BUtil header patch version
 */
#define BUtil_PATCH_VERSION        (3u)


/* PRQA S 3453 2 */ /* Macro used for precompile version check */
#define BUtil_CHECK_VERSION(major,minor,patch) \
 (((major) == BUtil_MAJOR_VERSION) && ((minor) == BUtil_MINOR_VERSION) && ((patch) == BUtil_PATCH_VERSION))


#endif /* BUTIL_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
