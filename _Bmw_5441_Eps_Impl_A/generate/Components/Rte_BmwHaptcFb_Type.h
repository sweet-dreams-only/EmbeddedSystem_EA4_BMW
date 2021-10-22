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
 *          File:  Rte_BmwHaptcFb_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <BmwHaptcFb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWHAPTCFB_TYPE_H
# define _RTE_BMWHAPTCFB_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef BMWHAPTCFBINTENNR_INTEN0
#   define BMWHAPTCFBINTENNR_INTEN0 (0U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN1
#   define BMWHAPTCFBINTENNR_INTEN1 (1U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN2
#   define BMWHAPTCFBINTENNR_INTEN2 (2U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN3
#   define BMWHAPTCFBINTENNR_INTEN3 (3U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN4
#   define BMWHAPTCFBINTENNR_INTEN4 (4U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN5
#   define BMWHAPTCFBINTENNR_INTEN5 (5U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN6
#   define BMWHAPTCFBINTENNR_INTEN6 (6U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN7
#   define BMWHAPTCFBINTENNR_INTEN7 (7U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN8
#   define BMWHAPTCFBINTENNR_INTEN8 (8U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN9
#   define BMWHAPTCFBINTENNR_INTEN9 (9U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN10
#   define BMWHAPTCFBINTENNR_INTEN10 (10U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN11
#   define BMWHAPTCFBINTENNR_INTEN11 (11U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INTEN12
#   define BMWHAPTCFBINTENNR_INTEN12 (12U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_RESD1
#   define BMWHAPTCFBINTENNR_RESD1 (13U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_RESD2
#   define BMWHAPTCFBINTENNR_RESD2 (14U)
#  endif

#  ifndef BMWHAPTCFBINTENNR_INVLDSIG
#   define BMWHAPTCFBINTENNR_INVLDSIG (15U)
#  endif

#  ifndef BMWHAPTCFBPATNR_NOHAPTCWARN
#   define BMWHAPTCFBPATNR_NOHAPTCWARN (0U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT1
#   define BMWHAPTCFBPATNR_PAT1 (1U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT2
#   define BMWHAPTCFBPATNR_PAT2 (2U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT3
#   define BMWHAPTCFBPATNR_PAT3 (3U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT4
#   define BMWHAPTCFBPATNR_PAT4 (4U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT5
#   define BMWHAPTCFBPATNR_PAT5 (5U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT6
#   define BMWHAPTCFBPATNR_PAT6 (6U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT7
#   define BMWHAPTCFBPATNR_PAT7 (7U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT8
#   define BMWHAPTCFBPATNR_PAT8 (8U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT9
#   define BMWHAPTCFBPATNR_PAT9 (9U)
#  endif

#  ifndef BMWHAPTCFBPATNR_PAT10
#   define BMWHAPTCFBPATNR_PAT10 (10U)
#  endif

#  ifndef BMWHAPTCFBPATNR_FCTIFNOTAVL
#   define BMWHAPTCFBPATNR_FCTIFNOTAVL (13U)
#  endif

#  ifndef BMWHAPTCFBPATNR_FCTRPRTERR
#   define BMWHAPTCFBPATNR_FCTRPRTERR (14U)
#  endif

#  ifndef BMWHAPTCFBPATNR_INVLDSIG
#   define BMWHAPTCFBPATNR_INVLDSIG (15U)
#  endif

#  ifndef HAPTCFBST_FCTAVLNOTACTV
#   define HAPTCFBST_FCTAVLNOTACTV (1U)
#  endif

#  ifndef HAPTCFBST_ERR
#   define HAPTCFBST_ERR (6U)
#  endif

#  ifndef HAPTCFBST_FCTAVLACTV
#   define HAPTCFBST_FCTAVLACTV (9U)
#  endif

#  ifndef HAPTCFBST_FCTNOTAVL
#   define HAPTCFBST_FCTNOTAVL (14U)
#  endif

#  ifndef HAPTCFBST_INVLDSIG
#   define HAPTCFBST_INVLDSIG (15U)
#  endif

#  ifndef STSSTEERASSI_OFF
#   define STSSTEERASSI_OFF (0U)
#  endif

#  ifndef STSSTEERASSI_ON
#   define STSSTEERASSI_ON (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWHAPTCFB_TYPE_H */
