


/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Vin
*
*  This file is a template for the structure of the generated version header file
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user: no
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     3.5.0
*
*  \remarks     The content of this file only serves as an example. If this
*               file is platform dependent, this shall be mentioned here.
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : artt 2.0.2.0
*
*  GENERATION TIME : 30.07.2018 19:57:44
*
------------------------------------------------------------------------------*/

#ifndef VIN_VERSION_H
#define VIN_VERSION_H


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Vin header major version
 */
#define Vin_MAJOR_VERSION        (3u)

/**
 * \brief Vin header minor version
 */
#define Vin_MINOR_VERSION        (5u)

/**
 * \brief Vin header patch version
 */
#define Vin_PATCH_VERSION        (0u)

/**
 * \brief Omc check version macro
 *
 * MISRAC:2004 Rule 19.7: The macro is used in compile time to check the version of all SW-C files.
 *                        This macro can not be replaced with a function.
 */
/* PRQA S 3453 2 */
#define Vin_CHECK_VERSION(major,minor,patch) \
 (((major) == Vin_MAJOR_VERSION) && ((minor) == Vin_MINOR_VERSION) && ((patch) == Vin_PATCH_VERSION))

#endif /* VIN_VERSION_H */
/*--- End of file ------------------------------------------------------------*/
