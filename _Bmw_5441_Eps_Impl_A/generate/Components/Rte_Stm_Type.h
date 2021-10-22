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
 *          File:  Rte_Stm_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <Stm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_STM_TYPE_H
# define _RTE_STM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef STM_CEL_UNLOCKED
#   define STM_CEL_UNLOCKED (0U)
#  endif

#  ifndef STM_CEL_LOCKED
#   define STM_CEL_LOCKED (1U)
#  endif

#  ifndef STM_CEL_INVALID
#   define STM_CEL_INVALID (3U)
#  endif

#  ifndef STM_ENERGY_GOOD
#   define STM_ENERGY_GOOD (0U)
#  endif

#  ifndef STM_ENERGY_OK
#   define STM_ENERGY_OK (1U)
#  endif

#  ifndef STM_ENERGY_SHORTAGE
#   define STM_ENERGY_SHORTAGE (2U)
#  endif

#  ifndef STM_ENERGY_SEVERE_SHORTAGE
#   define STM_ENERGY_SEVERE_SHORTAGE (3U)
#  endif

#  ifndef STM_ENERGY_INVALID
#   define STM_ENERGY_INVALID (15U)
#  endif

#  ifndef STM_VEHICLE_STATE_PARKING_BN_NOK
#   define STM_VEHICLE_STATE_PARKING_BN_NOK (1U)
#  endif

#  ifndef STM_VEHICLE_STATE_PARKING_BN_OK
#   define STM_VEHICLE_STATE_PARKING_BN_OK (2U)
#  endif

#  ifndef STM_VEHICLE_STATE_CUSTOMER_ABSENT
#   define STM_VEHICLE_STATE_CUSTOMER_ABSENT (3U)
#  endif

#  ifndef STM_VEHICLE_STATE_LIVING
#   define STM_VEHICLE_STATE_LIVING (5U)
#  endif

#  ifndef STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS
#   define STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS (7U)
#  endif

#  ifndef STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT
#   define STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT (8U)
#  endif

#  ifndef STM_VEHICLE_STATE_DRIVE
#   define STM_VEHICLE_STATE_DRIVE (10U)
#  endif

#  ifndef STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP
#   define STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP (12U)
#  endif

#  ifndef STM_VEHICLE_STATE_UNAVAILABLE
#   define STM_VEHICLE_STATE_UNAVAILABLE (14U)
#  endif

#  ifndef STM_VEHICLE_STATE_INVALID
#   define STM_VEHICLE_STATE_INVALID (15U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_ErrorMemoryLockSignalReceptionMode
#  define RTE_MODETYPE_ErrorMemoryLockSignalReceptionMode
typedef uint8 Rte_ModeType_ErrorMemoryLockSignalReceptionMode;
# endif
# ifndef RTE_MODETYPE_Stm_CentralErrorLockMode
#  define RTE_MODETYPE_Stm_CentralErrorLockMode
typedef Stm_CentralErrorLockType Rte_ModeType_Stm_CentralErrorLockMode;
# endif
# ifndef RTE_MODETYPE_Stm_EnergyStateMode
#  define RTE_MODETYPE_Stm_EnergyStateMode
typedef Stm_EnergyStateType Rte_ModeType_Stm_EnergyStateMode;
# endif
# ifndef RTE_MODETYPE_Stm_VehicleStateMode
#  define RTE_MODETYPE_Stm_VehicleStateMode
typedef Stm_VehicleStateType Rte_ModeType_Stm_VehicleStateMode;
# endif

# ifndef RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE
#  define RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_NOT_RECEIVABLE (0U)
# endif
# ifndef RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE
#  define RTE_MODE_ErrorMemoryLockSignalReceptionMode_EM_LOCK_RECEIVABLE (1U)
# endif
# ifndef RTE_TRANSITION_ErrorMemoryLockSignalReceptionMode
#  define RTE_TRANSITION_ErrorMemoryLockSignalReceptionMode (2U)
# endif

# ifndef RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID
#  define RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_INVALID (0U)
# endif
# ifndef RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED
#  define RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_LOCKED (1U)
# endif
# ifndef RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED
#  define RTE_MODE_Stm_CentralErrorLockMode_STM_CEL_UNLOCKED (2U)
# endif
# ifndef RTE_TRANSITION_Stm_CentralErrorLockMode
#  define RTE_TRANSITION_Stm_CentralErrorLockMode (3U)
# endif

# ifndef RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD
#  define RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_GOOD (0U)
# endif
# ifndef RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID
#  define RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_INVALID (1U)
# endif
# ifndef RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK
#  define RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_OK (2U)
# endif
# ifndef RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE
#  define RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SEVERE_SHORTAGE (3U)
# endif
# ifndef RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE
#  define RTE_MODE_Stm_EnergyStateMode_STM_ENERGY_SHORTAGE (4U)
# endif
# ifndef RTE_TRANSITION_Stm_EnergyStateMode
#  define RTE_TRANSITION_Stm_EnergyStateMode (5U)
# endif

# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CHECK_ANALYS_DIAGNOSTICS (0U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CUSTOMER_ABSENT
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_CUSTOMER_ABSENT (1U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_DRIVE
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_DRIVE (2U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_INVALID (3U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_LIVING
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_LIVING (4U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_NOK
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_NOK (5U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_OK
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_PARKING_BN_OK (6U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_INIT (7U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_READINESS_TO_DRIVE_STOP (8U)
# endif
# ifndef RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_UNAVAILABLE
#  define RTE_MODE_Stm_VehicleStateMode_STM_VEHICLE_STATE_UNAVAILABLE (9U)
# endif
# ifndef RTE_TRANSITION_Stm_VehicleStateMode
#  define RTE_TRANSITION_Stm_VehicleStateMode (10U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_STM_TYPE_H */
