/**
*  \file
*
*  \brief
*
*  Version Check for Stm Module
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2017
*
*  \version     5.2.0
*
*/

/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/
/*
 * Violation of MISRA-C:2004 Rule 19.7:
 * Reason: this macro is only used in preprocessor directive,
 * no function possible. See PRQA 3453
 */


#ifndef STM_VERSION_H
#define STM_VERSION_H

/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/**
 * \brief ModuleName header major version
 */
#define Stm_MAJOR_VERSION        (5u)

/**
 * \brief ModuleName header minor version
 */
#define Stm_MINOR_VERSION        (2u)

/**
 * \brief ModuleName header patch version
 */
#define Stm_PATCH_VERSION        (0u)


/* PRQA S 3453 2 */
#define Stm_CHECK_VERSION(major,minor,patch) \
 (((major) == Stm_MAJOR_VERSION) && ((minor) == Stm_MINOR_VERSION) && ((patch) == Stm_PATCH_VERSION))


#endif /* STM_VERSION_H */

/*--- End of file ------------------------------------------------------------*/
