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
 *          File:  Rte_StdDiag_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <StdDiag>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_STDDIAG_TYPE_H
# define _RTE_STDDIAG_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DARH_ROE_STOPPED
#   define DARH_ROE_STOPPED (0U)
#  endif

#  ifndef DARH_ROE_STARTED
#   define DARH_ROE_STARTED (1U)
#  endif

#  ifndef DARH_ROE_UNKNOWN
#   define DARH_ROE_UNKNOWN (2U)
#  endif

#  ifndef DCM_RES_POS_OK
#   define DCM_RES_POS_OK (0U)
#  endif

#  ifndef DCM_RES_POS_NOT_OK
#   define DCM_RES_POS_NOT_OK (1U)
#  endif

#  ifndef DCM_RES_NEG_OK
#   define DCM_RES_NEG_OK (2U)
#  endif

#  ifndef DCM_RES_NEG_NOT_OK
#   define DCM_RES_NEG_NOT_OK (3U)
#  endif

#  ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#   define DCM_E_BRAKESWITCH_NOTCLOSED (143U)
#  endif

#  ifndef DCM_E_BUSYREPEATREQUEST
#   define DCM_E_BUSYREPEATREQUEST (33U)
#  endif

#  ifndef DCM_E_CONDITIONSNOTCORRECT
#   define DCM_E_CONDITIONSNOTCORRECT (34U)
#  endif

#  ifndef DCM_E_ENGINEISNOTRUNNING
#   define DCM_E_ENGINEISNOTRUNNING (132U)
#  endif

#  ifndef DCM_E_ENGINEISRUNNING
#   define DCM_E_ENGINEISRUNNING (131U)
#  endif

#  ifndef DCM_E_ENGINERUNTIMETOOLOW
#   define DCM_E_ENGINERUNTIMETOOLOW (133U)
#  endif

#  ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#   define DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
#  endif

#  ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#   define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
#  endif

#  ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#   define DCM_E_GENERALPROGRAMMINGFAILURE (114U)
#  endif

#  ifndef DCM_E_GENERALREJECT
#   define DCM_E_GENERALREJECT (16U)
#  endif

#  ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#   define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
#  endif

#  ifndef DCM_E_INVALIDKEY
#   define DCM_E_INVALIDKEY (53U)
#  endif

#  ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#   define DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
#  endif

#  ifndef DCM_E_REQUESTOUTOFRANGE
#   define DCM_E_REQUESTOUTOFRANGE (49U)
#  endif

#  ifndef DCM_E_REQUESTSEQUENCEERROR
#   define DCM_E_REQUESTSEQUENCEERROR (36U)
#  endif

#  ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#   define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
#  endif

#  ifndef DCM_E_RESPONSETOOLONG
#   define DCM_E_RESPONSETOOLONG (20U)
#  endif

#  ifndef DCM_E_RPMTOOHIGH
#   define DCM_E_RPMTOOHIGH (129U)
#  endif

#  ifndef DCM_E_RPMTOOLOW
#   define DCM_E_RPMTOOLOW (130U)
#  endif

#  ifndef DCM_E_SECURITYACCESSDENIED
#   define DCM_E_SECURITYACCESSDENIED (51U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTED
#   define DCM_E_SERVICENOTSUPPORTED (17U)
#  endif

#  ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
#  endif

#  ifndef DCM_E_SHIFTERLEVERNOTINPARK
#   define DCM_E_SHIFTERLEVERNOTINPARK (144U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#   define DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
#  endif

#  ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#   define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOHIGH
#   define DCM_E_TEMPERATURETOOHIGH (134U)
#  endif

#  ifndef DCM_E_TEMPERATURETOOLOW
#   define DCM_E_TEMPERATURETOOLOW (135U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#   define DCM_E_THROTTLE_PEDALTOOHIGH (138U)
#  endif

#  ifndef DCM_E_THROTTLE_PEDALTOOLOW
#   define DCM_E_THROTTLE_PEDALTOOLOW (139U)
#  endif

#  ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#   define DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
#  endif

#  ifndef DCM_E_TRANSFERDATASUSPENDED
#   define DCM_E_TRANSFERDATASUSPENDED (113U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#   define DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
#  endif

#  ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#   define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
#  endif

#  ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#   define DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOHIGH
#   define DCM_E_VEHICLESPEEDTOOHIGH (136U)
#  endif

#  ifndef DCM_E_VEHICLESPEEDTOOLOW
#   define DCM_E_VEHICLESPEEDTOOLOW (137U)
#  endif

#  ifndef DCM_E_VOLTAGETOOHIGH
#   define DCM_E_VOLTAGETOOHIGH (146U)
#  endif

#  ifndef DCM_E_VOLTAGETOOLOW
#   define DCM_E_VOLTAGETOOLOW (147U)
#  endif

#  ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#   define DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
#  endif

#  ifndef DCM_E_VMSCNC_0
#   define DCM_E_VMSCNC_0 (240U)
#  endif

#  ifndef DCM_E_VMSCNC_1
#   define DCM_E_VMSCNC_1 (241U)
#  endif

#  ifndef DCM_E_VMSCNC_2
#   define DCM_E_VMSCNC_2 (242U)
#  endif

#  ifndef DCM_E_VMSCNC_3
#   define DCM_E_VMSCNC_3 (243U)
#  endif

#  ifndef DCM_E_VMSCNC_4
#   define DCM_E_VMSCNC_4 (244U)
#  endif

#  ifndef DCM_E_VMSCNC_5
#   define DCM_E_VMSCNC_5 (245U)
#  endif

#  ifndef DCM_E_VMSCNC_6
#   define DCM_E_VMSCNC_6 (246U)
#  endif

#  ifndef DCM_E_VMSCNC_7
#   define DCM_E_VMSCNC_7 (247U)
#  endif

#  ifndef DCM_E_VMSCNC_8
#   define DCM_E_VMSCNC_8 (248U)
#  endif

#  ifndef DCM_E_VMSCNC_9
#   define DCM_E_VMSCNC_9 (249U)
#  endif

#  ifndef DCM_E_VMSCNC_A
#   define DCM_E_VMSCNC_A (250U)
#  endif

#  ifndef DCM_E_VMSCNC_B
#   define DCM_E_VMSCNC_B (251U)
#  endif

#  ifndef DCM_E_VMSCNC_C
#   define DCM_E_VMSCNC_C (252U)
#  endif

#  ifndef DCM_E_VMSCNC_D
#   define DCM_E_VMSCNC_D (253U)
#  endif

#  ifndef DCM_E_VMSCNC_E
#   define DCM_E_VMSCNC_E (254U)
#  endif

#  ifndef DCM_INITIAL
#   define DCM_INITIAL (0U)
#  endif

#  ifndef DCM_PENDING
#   define DCM_PENDING (1U)
#  endif

#  ifndef DCM_CANCEL
#   define DCM_CANCEL (2U)
#  endif

#  ifndef DCM_FORCE_RCRRP_OK
#   define DCM_FORCE_RCRRP_OK (3U)
#  endif

#  ifndef DCM_DEFAULT_SESSION
#   define DCM_DEFAULT_SESSION (1U)
#  endif

#  ifndef DCM_PROGRAMMING_SESSION
#   define DCM_PROGRAMMING_SESSION (2U)
#  endif

#  ifndef DCM_EXTENDED_DIAGNOSTIC_SESSION
#   define DCM_EXTENDED_DIAGNOSTIC_SESSION (3U)
#  endif

#  ifndef DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION
#   define DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION (4U)
#  endif

#  ifndef DCM_CODING_SESSION
#   define DCM_CODING_SESSION (65U)
#  endif

#  ifndef DCM_SWT_SESSION
#   define DCM_SWT_SESSION (66U)
#  endif

#  ifndef DEM_DTC_FORMAT_OBD
#   define DEM_DTC_FORMAT_OBD (0U)
#  endif

#  ifndef DEM_DTC_FORMAT_UDS
#   define DEM_DTC_FORMAT_UDS (1U)
#  endif

#  ifndef DEM_DTC_FORMAT_J1939
#   define DEM_DTC_FORMAT_J1939 (2U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PRIMARY_MEMORY
#   define DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
#  endif

#  ifndef DEM_DTC_ORIGIN_MIRROR_MEMORY
#   define DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
#  endif

#  ifndef DEM_DTC_ORIGIN_PERMANENT_MEMORY
#   define DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
#  endif

#  ifndef DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory
#   define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BMWSecondaryErrorMemory (4U)
#  endif

#  ifndef DISABLE_RX_AND_TX_NORMAL
#   define DISABLE_RX_AND_TX_NORMAL (0U)
#  endif

#  ifndef DISABLE_RX_ENABLE_TX_NORMAL
#   define DISABLE_RX_ENABLE_TX_NORMAL (1U)
#  endif

#  ifndef ENABLE_RX_AND_TX_NORMAL
#   define ENABLE_RX_AND_TX_NORMAL (2U)
#  endif

#  ifndef ENABLE_RX_DISABLE_TX_NORMAL
#   define ENABLE_RX_DISABLE_TX_NORMAL (3U)
#  endif

#  ifndef OMC_MODE_EXTENSION_NORMAL
#   define OMC_MODE_EXTENSION_NORMAL (0U)
#  endif

#  ifndef OMC_MODE_EXTENSION_1
#   define OMC_MODE_EXTENSION_1 (1U)
#  endif

#  ifndef OMC_MODE_EXTENSION_2
#   define OMC_MODE_EXTENSION_2 (2U)
#  endif

#  ifndef OMC_MODE_EXTENSION_3
#   define OMC_MODE_EXTENSION_3 (3U)
#  endif

#  ifndef OMC_MODE_EXTENSION_4
#   define OMC_MODE_EXTENSION_4 (4U)
#  endif

#  ifndef OMC_MODE_EXTENSION_5
#   define OMC_MODE_EXTENSION_5 (5U)
#  endif

#  ifndef OMC_MODE_EXTENSION_6
#   define OMC_MODE_EXTENSION_6 (6U)
#  endif

#  ifndef OMC_MODE_EXTENSION_7
#   define OMC_MODE_EXTENSION_7 (7U)
#  endif

#  ifndef OMC_MODE_EXTENSION_8
#   define OMC_MODE_EXTENSION_8 (8U)
#  endif

#  ifndef OMC_MODE_EXTENSION_9
#   define OMC_MODE_EXTENSION_9 (9U)
#  endif

#  ifndef OMC_MODE_EXTENSION_10
#   define OMC_MODE_EXTENSION_10 (10U)
#  endif

#  ifndef OMC_MODE_EXTENSION_11
#   define OMC_MODE_EXTENSION_11 (11U)
#  endif

#  ifndef OMC_MODE_EXTENSION_12
#   define OMC_MODE_EXTENSION_12 (12U)
#  endif

#  ifndef OMC_MODE_EXTENSION_13
#   define OMC_MODE_EXTENSION_13 (13U)
#  endif

#  ifndef OMC_MODE_EXTENSION_14
#   define OMC_MODE_EXTENSION_14 (14U)
#  endif

#  ifndef OMC_MODE_EXTENSION_SAVE_ENERGY
#   define OMC_MODE_EXTENSION_SAVE_ENERGY (15U)
#  endif

#  ifndef OMC_MODE_EXTENSION_INVALID
#   define OMC_MODE_EXTENSION_INVALID (255U)
#  endif

#  ifndef OMC_MODE_NORMAL
#   define OMC_MODE_NORMAL (0U)
#  endif

#  ifndef OMC_MODE_ASSEMBLY
#   define OMC_MODE_ASSEMBLY (1U)
#  endif

#  ifndef OMC_MODE_TRANSPORT
#   define OMC_MODE_TRANSPORT (2U)
#  endif

#  ifndef OMC_MODE_BMW_FLASH
#   define OMC_MODE_BMW_FLASH (3U)
#  endif

#  ifndef STDDIAG_INITIALIZED
#   define STDDIAG_INITIALIZED (0U)
#  endif

#  ifndef STDDIAG_RUNNING
#   define STDDIAG_RUNNING (1U)
#  endif

#  ifndef STDDIAG_STOPPED
#   define STDDIAG_STOPPED (2U)
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
# ifndef RTE_MODETYPE_OmcExtendedOperatingMode
#  define RTE_MODETYPE_OmcExtendedOperatingMode
typedef Omc_ExtendedOperatingModeType Rte_ModeType_OmcExtendedOperatingMode;
# endif
# ifndef RTE_MODETYPE_OmcOperatingMode
#  define RTE_MODETYPE_OmcOperatingMode
typedef Omc_OperatingModeType Rte_ModeType_OmcOperatingMode;
# endif
# ifndef RTE_MODETYPE_StdDiag_LifeCycle
#  define RTE_MODETYPE_StdDiag_LifeCycle
typedef StdDiag_LifeCycleRequestType Rte_ModeType_StdDiag_LifeCycle;
# endif
# ifndef RTE_MODETYPE_StdDiag_NormalCommunicationModeGroup
#  define RTE_MODETYPE_StdDiag_NormalCommunicationModeGroup
typedef NormalCommunicationModeType Rte_ModeType_StdDiag_NormalCommunicationModeGroup;
# endif
# ifndef RTE_MODETYPE_StdDiag_SessionModeGroup
#  define RTE_MODETYPE_StdDiag_SessionModeGroup
typedef uint8 Rte_ModeType_StdDiag_SessionModeGroup;
# endif
# ifndef RTE_MODETYPE_Stm_VehicleStateMode
#  define RTE_MODETYPE_Stm_VehicleStateMode
typedef Stm_VehicleStateType Rte_ModeType_Stm_VehicleStateMode;
# endif

# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_NORMAL (0U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_1
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_1 (1U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_2
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_2 (2U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_3
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_3 (3U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_4
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_4 (4U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_5
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_5 (5U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_6
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_6 (6U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_7
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_7 (7U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_8
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_8 (8U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_9
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_9 (9U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_10
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_10 (10U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_11
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_11 (11U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_12
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_12 (12U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_13
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_13 (13U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_14
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_14 (14U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_SAVE_ENERGY
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_SAVE_ENERGY (15U)
# endif
# ifndef RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_INVALID
#  define RTE_MODE_OmcExtendedOperatingMode_OMC_MODE_EXTENSION_INVALID (255U)
# endif
# ifndef RTE_TRANSITION_OmcExtendedOperatingMode
#  define RTE_TRANSITION_OmcExtendedOperatingMode (254U)
# endif

# ifndef RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL
#  define RTE_MODE_OmcOperatingMode_OMC_MODE_NORMAL (0U)
# endif
# ifndef RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY
#  define RTE_MODE_OmcOperatingMode_OMC_MODE_ASSEMBLY (1U)
# endif
# ifndef RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT
#  define RTE_MODE_OmcOperatingMode_OMC_MODE_TRANSPORT (2U)
# endif
# ifndef RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH
#  define RTE_MODE_OmcOperatingMode_OMC_MODE_BMW_FLASH (3U)
# endif
# ifndef RTE_TRANSITION_OmcOperatingMode
#  define RTE_TRANSITION_OmcOperatingMode (255U)
# endif

# ifndef RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED
#  define RTE_MODE_StdDiag_LifeCycle_STDDIAG_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING
#  define RTE_MODE_StdDiag_LifeCycle_STDDIAG_RUNNING (1U)
# endif
# ifndef RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED
#  define RTE_MODE_StdDiag_LifeCycle_STDDIAG_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_StdDiag_LifeCycle
#  define RTE_TRANSITION_StdDiag_LifeCycle (3U)
# endif

# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_AND_TX_NORMAL (0U)
# endif
# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_DISABLE_RX_ENABLE_TX_NORMAL (1U)
# endif
# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_AND_TX_NORMAL (2U)
# endif
# ifndef RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL
#  define RTE_MODE_StdDiag_NormalCommunicationModeGroup_ENABLE_RX_DISABLE_TX_NORMAL (3U)
# endif
# ifndef RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup
#  define RTE_TRANSITION_StdDiag_NormalCommunicationModeGroup (4U)
# endif

# ifndef RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION
#  define RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_DEFAULT_SESSION (0U)
# endif
# ifndef RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_OTHER_SESSION
#  define RTE_MODE_StdDiag_SessionModeGroup_STDDIAG_OTHER_SESSION (1U)
# endif
# ifndef RTE_TRANSITION_StdDiag_SessionModeGroup
#  define RTE_TRANSITION_StdDiag_SessionModeGroup (2U)
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

#endif /* _RTE_STDDIAG_TYPE_H */
