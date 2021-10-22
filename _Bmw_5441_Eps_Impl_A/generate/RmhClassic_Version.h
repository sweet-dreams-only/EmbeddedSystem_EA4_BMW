/**
*  \file
*
*  \brief
*
*  Version Check for RmhClassic Module
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.0.0
*
*  \remarks     File is generated with PAGe
*
*/

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:39.494037
*
------------------------------------------------------------------------------*/

#ifndef RMH_CLASSIC_VERSION_H
#define RMH_CLASSIC_VERSION_H

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
 * Violation of MISRA-C:2004 Rule 19.7:
 * Reason: this macro is only used in preprocessor directive,
 * no function possible. See PRQA 3453
 */

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief ModuleName header major version
 */
#define RmhClassic_MAJOR_VERSION        (5u)

/**
 * \brief ModuleName header minor version
 */
#define RmhClassic_MINOR_VERSION        (0u)

/**
 * \brief ModuleName header patch version
 */
#define RmhClassic_PATCH_VERSION        (0u)


/* PRQA S 3453 2 */
#define RmhClassic_CHECK_VERSION(major,minor,patch) \
 (((major) == RmhClassic_MAJOR_VERSION) && ((minor) == RmhClassic_MINOR_VERSION) && ((patch) == RmhClassic_PATCH_VERSION))


#endif /* RMH_CLASSIC_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
