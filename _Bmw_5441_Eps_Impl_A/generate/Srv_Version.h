/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       Srv Version Information
*
*  This file is a generated version header file
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW AG 2015
*
*  \version     3.1.0
*
*  \remarks     ---
*
*/
/*----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : artt 2.0.2.0
*
*  GENERATION TIME : 30.07.2018 19:57:38
*
------------------------------------------------------------------------------*/

#ifndef SRV_VERSION_H
#define SRV_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief Srv header major version
 */
#define Srv_MAJOR_VERSION        (3u)

/**
 * \brief Srv header minor version
 */
#define Srv_MINOR_VERSION        (1u)

/**
 * \brief Srv header patch version
 */
#define Srv_PATCH_VERSION        (0u)


/* PRQA S 3453 2 */ /* Macro used for precompile version check */
#define Srv_CHECK_VERSION(major,minor,patch) \
 (((major) == Srv_MAJOR_VERSION) && ((minor) == Srv_MINOR_VERSION) && ((patch) == Srv_PATCH_VERSION))


#endif /* SRV_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
