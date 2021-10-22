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
 *          File:  Rte_WdgM_Appl8_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <WdgM_Appl8>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_WDGM_APPL8_TYPE_H
# define _RTE_WDGM_APPL8_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef WDGM_LOCAL_STATUS_OK
#   define WDGM_LOCAL_STATUS_OK (0U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_FAILED
#   define WDGM_LOCAL_STATUS_FAILED (1U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_EXPIRED
#   define WDGM_LOCAL_STATUS_EXPIRED (2U)
#  endif

#  ifndef WDGM_LOCAL_STATUS_DEACTIVATED
#   define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_WDGM_APPL8_TYPE_H */
