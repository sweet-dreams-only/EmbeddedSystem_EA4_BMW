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
 *          File:  Rte_MotCurrRegCfg_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <MotCurrRegCfg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MOTCURRREGCFG_TYPE_H
# define _RTE_MOTCURRREGCFG_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef MCECS_OFFSCMDSTRT
#   define MCECS_OFFSCMDSTRT (0U)
#  endif

#  ifndef MCECS_OFFSCMDHI
#   define MCECS_OFFSCMDHI (1U)
#  endif

#  ifndef MCECS_OFFSCMDLO
#   define MCECS_OFFSCMDLO (2U)
#  endif

#  ifndef MCECS_OFFSCMDZERO
#   define MCECS_OFFSCMDZERO (3U)
#  endif

#  ifndef MCECS_OFFSCMDEND
#   define MCECS_OFFSCMDEND (4U)
#  endif

#  ifndef MCECS_GAINCMDAD
#   define MCECS_GAINCMDAD (5U)
#  endif

#  ifndef MCECS_GAINCMDBE
#   define MCECS_GAINCMDBE (6U)
#  endif

#  ifndef MCECS_GAINCMDCF
#   define MCECS_GAINCMDCF (7U)
#  endif

#  ifndef MCECS_CMDSAFEST
#   define MCECS_CMDSAFEST (8U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MOTCURRREGCFG_TYPE_H */
