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
 *          File:  Rte_SysTime_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <SysTime>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SYSTIME_TYPE_H
# define _RTE_SYSTIME_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef SYSTIME_INITIALIZED
#   define SYSTIME_INITIALIZED (0U)
#  endif

#  ifndef SYSTIME_RUNNING
#   define SYSTIME_RUNNING (1U)
#  endif

#  ifndef SYSTIME_STOPPED
#   define SYSTIME_STOPPED (2U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_SysTime_LifeCycle
#  define RTE_MODETYPE_SysTime_LifeCycle
typedef SysTime_LifeCycleRequestType Rte_ModeType_SysTime_LifeCycle;
# endif

# ifndef RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED
#  define RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING
#  define RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING (1U)
# endif
# ifndef RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED
#  define RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_SysTime_LifeCycle
#  define RTE_TRANSITION_SysTime_LifeCycle (3U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_SYSTIME_TYPE_H */
