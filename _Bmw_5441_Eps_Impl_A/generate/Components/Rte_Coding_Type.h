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
 *          File:  Rte_Coding_Type.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application types header file for SW-C <Coding>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CODING_TYPE_H
# define _RTE_CODING_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CODING_INITIALIZED
#   define CODING_INITIALIZED (0U)
#  endif

#  ifndef CODING_RUNNING
#   define CODING_RUNNING (1U)
#  endif

#  ifndef CODING_STOPPED
#   define CODING_STOPPED (2U)
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

#  ifndef DEM_EVENT_STATUS_PASSED
#   define DEM_EVENT_STATUS_PASSED (0U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED
#   define DEM_EVENT_STATUS_FAILED (1U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED
#   define DEM_EVENT_STATUS_PREPASSED (2U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED
#   define DEM_EVENT_STATUS_PREFAILED (3U)
#  endif

#  ifndef DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED
#   define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
#  endif

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
# ifndef RTE_MODETYPE_Coding_BusComMode
#  define RTE_MODETYPE_Coding_BusComMode
typedef uint8 Rte_ModeType_Coding_BusComMode;
# endif
# ifndef RTE_MODETYPE_Coding_ConditionMode
#  define RTE_MODETYPE_Coding_ConditionMode
typedef uint8 Rte_ModeType_Coding_ConditionMode;
# endif
# ifndef RTE_MODETYPE_Coding_DataMode
#  define RTE_MODETYPE_Coding_DataMode
typedef uint8 Rte_ModeType_Coding_DataMode;
# endif
# ifndef RTE_MODETYPE_Coding_LifeCycle
#  define RTE_MODETYPE_Coding_LifeCycle
typedef Coding_LifeCycleRequestType Rte_ModeType_Coding_LifeCycle;
# endif
# ifndef RTE_MODETYPE_Coding_SessionMode
#  define RTE_MODETYPE_Coding_SessionMode
typedef uint8 Rte_ModeType_Coding_SessionMode;
# endif

# ifndef RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF
#  define RTE_MODE_Coding_BusComMode_CODING_BUSCOMOFF (0U)
# endif
# ifndef RTE_MODE_Coding_BusComMode_CODING_BUSCOMON
#  define RTE_MODE_Coding_BusComMode_CODING_BUSCOMON (1U)
# endif
# ifndef RTE_TRANSITION_Coding_BusComMode
#  define RTE_TRANSITION_Coding_BusComMode (2U)
# endif

# ifndef RTE_MODE_Coding_ConditionMode_CODING_ALLOWED
#  define RTE_MODE_Coding_ConditionMode_CODING_ALLOWED (0U)
# endif
# ifndef RTE_MODE_Coding_ConditionMode_CODING_NOT_ALLOWED
#  define RTE_MODE_Coding_ConditionMode_CODING_NOT_ALLOWED (1U)
# endif
# ifndef RTE_TRANSITION_Coding_ConditionMode
#  define RTE_TRANSITION_Coding_ConditionMode (2U)
# endif

# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS
#  define RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS (0U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT
#  define RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT (1U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED
#  define RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED (2U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED
#  define RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED (3U)
# endif
# ifndef RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED
#  define RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED (4U)
# endif
# ifndef RTE_TRANSITION_Coding_DataMode
#  define RTE_TRANSITION_Coding_DataMode (5U)
# endif

# ifndef RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED
#  define RTE_MODE_Coding_LifeCycle_CODING_INITIALIZED (0U)
# endif
# ifndef RTE_MODE_Coding_LifeCycle_CODING_RUNNING
#  define RTE_MODE_Coding_LifeCycle_CODING_RUNNING (1U)
# endif
# ifndef RTE_MODE_Coding_LifeCycle_CODING_STOPPED
#  define RTE_MODE_Coding_LifeCycle_CODING_STOPPED (2U)
# endif
# ifndef RTE_TRANSITION_Coding_LifeCycle
#  define RTE_TRANSITION_Coding_LifeCycle (3U)
# endif

# ifndef RTE_MODE_Coding_SessionMode_CODING_SESSION_ACTIVE
#  define RTE_MODE_Coding_SessionMode_CODING_SESSION_ACTIVE (0U)
# endif
# ifndef RTE_MODE_Coding_SessionMode_CODING_SESSION_INACTIVE
#  define RTE_MODE_Coding_SessionMode_CODING_SESSION_INACTIVE (1U)
# endif
# ifndef RTE_TRANSITION_Coding_SessionMode
#  define RTE_TRANSITION_Coding_SessionMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CODING_TYPE_H */
