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
 *          File:  Rte_Vin_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <Vin>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_VIN_TYPE_H
# define _RTE_VIN_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef VIN_INITIALIZED
#   define VIN_INITIALIZED (0U)
#  endif

#  ifndef VIN_RUNNING
#   define VIN_RUNNING (1U)
#  endif

#  ifndef VIN_STOPPED
#   define VIN_STOPPED (2U)
#  endif

#  ifndef VIN_QUAL_INIT
#   define VIN_QUAL_INIT (0U)
#  endif

#  ifndef VIN_QUAL_RECEIVED
#   define VIN_QUAL_RECEIVED (1U)
#  endif

#  ifndef VIN_QUAL_EQ_INTERNAL
#   define VIN_QUAL_EQ_INTERNAL (2U)
#  endif

#  ifndef VIN_QUAL_SECURE_PENDING
#   define VIN_QUAL_SECURE_PENDING (4U)
#  endif

#  ifndef VIN_QUAL_SECURE_FINISHED
#   define VIN_QUAL_SECURE_FINISHED (8U)
#  endif

#  ifndef VIN_QUAL_SECURE_OK
#   define VIN_QUAL_SECURE_OK (16U)
#  endif

#  ifndef VIN_QUAL_SECURE_MASK
#   define VIN_QUAL_SECURE_MASK (28U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_Vin_ChangeIndicator
#  define RTE_MODETYPE_Vin_ChangeIndicator
typedef uint8 Rte_ModeType_Vin_ChangeIndicator;
# endif
# ifndef RTE_MODETYPE_Vin_LifeCycle
#  define RTE_MODETYPE_Vin_LifeCycle
typedef Vin_LifeCycleRequestType Rte_ModeType_Vin_LifeCycle;
# endif
# ifndef RTE_MODETYPE_Vin_VinComMode
#  define RTE_MODETYPE_Vin_VinComMode
typedef uint8 Rte_ModeType_Vin_VinComMode;
# endif

# ifndef RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT
#  define RTE_MODE_Vin_ChangeIndicator_VIN_CI_INIT (0U)
# endif
# ifndef RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE
#  define RTE_MODE_Vin_ChangeIndicator_VIN_CI_NOCHANGE (1U)
# endif
# ifndef RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED
#  define RTE_MODE_Vin_ChangeIndicator_VIN_CI_CHANGED (2U)
# endif
# ifndef RTE_TRANSITION_Vin_ChangeIndicator
#  define RTE_TRANSITION_Vin_ChangeIndicator (5U)
# endif

# ifndef RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED
#  define RTE_MODE_Vin_LifeCycle_VIN_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_Vin_LifeCycle_VIN_RUNNING
#  define RTE_MODE_Vin_LifeCycle_VIN_RUNNING (1U)
# endif
# ifndef RTE_MODE_Vin_LifeCycle_VIN_STOPPED
#  define RTE_MODE_Vin_LifeCycle_VIN_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_Vin_LifeCycle
#  define RTE_TRANSITION_Vin_LifeCycle (3U)
# endif

# ifndef RTE_MODE_Vin_VinComMode_VIN_VINCOMON
#  define RTE_MODE_Vin_VinComMode_VIN_VINCOMON (0U)
# endif
# ifndef RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF
#  define RTE_MODE_Vin_VinComMode_VIN_VINCOMOFF (1U)
# endif
# ifndef RTE_TRANSITION_Vin_VinComMode
#  define RTE_TRANSITION_Vin_VinComMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_VIN_TYPE_H */
