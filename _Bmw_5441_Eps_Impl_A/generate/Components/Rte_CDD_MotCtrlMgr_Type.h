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
 *          File:  Rte_CDD_MotCtrlMgr_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <CDD_MotCtrlMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTCTRLMGR_TYPE_H
# define _RTE_CDD_MOTCTRLMGR_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define Ag8_LowerLimit (-2147483647 - 1)
#  define Ag8_UpperLimit (2147483647)

#  ifndef IVTRFETFLTPHA_NOPHASNGFETFLT
#   define IVTRFETFLTPHA_NOPHASNGFETFLT (0U)
#  endif

#  ifndef IVTRFETFLTPHA_PHAASNGFETFLT
#   define IVTRFETFLTPHA_PHAASNGFETFLT (1U)
#  endif

#  ifndef IVTRFETFLTPHA_PHABSNGFETFLT
#   define IVTRFETFLTPHA_PHABSNGFETFLT (2U)
#  endif

#  ifndef IVTRFETFLTPHA_PHACSNGFETFLT
#   define IVTRFETFLTPHA_PHACSNGFETFLT (4U)
#  endif

#  ifndef IVTRFETFLTTYP_NOFETFLT
#   define IVTRFETFLTTYP_NOFETFLT (0U)
#  endif

#  ifndef IVTRFETFLTTYP_LOWRFETFLT
#   define IVTRFETFLTTYP_LOWRFETFLT (1U)
#  endif

#  ifndef IVTRFETFLTTYP_UPPRFETFLT
#   define IVTRFETFLTTYP_UPPRFETFLT (2U)
#  endif

#  ifndef IVTRFETFLTTYP_MPLFETFLT
#   define IVTRFETFLTTYP_MPLFETFLT (4U)
#  endif

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

#  ifndef PHADISCNCTPWMVECT_NOCMD
#   define PHADISCNCTPWMVECT_NOCMD (0U)
#  endif

#  ifndef PHADISCNCTPWMVECT_PHAACMD
#   define PHADISCNCTPWMVECT_PHAACMD (1U)
#  endif

#  ifndef PHADISCNCTPWMVECT_PHABCMD
#   define PHADISCNCTPWMVECT_PHABCMD (2U)
#  endif

#  ifndef PHADISCNCTPWMVECT_PHACCMD
#   define PHADISCNCTPWMVECT_PHACCMD (4U)
#  endif

#  ifndef SIGQLFR_NORES
#   define SIGQLFR_NORES (0U)
#  endif

#  ifndef SIGQLFR_PASSD
#   define SIGQLFR_PASSD (1U)
#  endif

#  ifndef SIGQLFR_FAILD
#   define SIGQLFR_FAILD (2U)
#  endif

#  ifndef SYSST_DI
#   define SYSST_DI (0U)
#  endif

#  ifndef SYSST_OFF
#   define SYSST_OFF (1U)
#  endif

#  ifndef SYSST_ENA
#   define SYSST_ENA (2U)
#  endif

#  ifndef SYSST_WRMININ
#   define SYSST_WRMININ (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTCTRLMGR_TYPE_H */
