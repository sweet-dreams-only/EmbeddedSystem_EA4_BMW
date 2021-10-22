/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_ClsdLoopDampg_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <ClsdLoopDampg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CLSDLOOPDAMPG_TYPE_H
# define _RTE_CLSDLOOPDAMPG_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef EOTST_DISAD
#   define EOTST_DISAD (0U)
#  endif

#  ifndef EOTST_NORM
#   define EOTST_NORM (1U)
#  endif

#  ifndef EOTST_ENTR
#   define EOTST_ENTR (2U)
#  endif

#  ifndef EOTST_EXIT
#   define EOTST_EXIT (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CLSDLOOPDAMPG_TYPE_H */
