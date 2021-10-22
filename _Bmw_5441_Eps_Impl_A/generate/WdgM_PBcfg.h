/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: WdgM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_PBcfg.h
 *   Generation Time: 2018-07-30 19:49:07
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (WDGM_PBCFG_H)
# define WDGM_PBCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Cfg.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/

#define WDGM_PBCFG_MAJOR_VERSION (2u) 
#define WDGM_PBCFG_MINOR_VERSION (1u) 
#define WDGM_PBCFG_PATCH_VERSION (1u) 

/* Check the version of WdgM Cfg header file */
#if ( (WDGM_CFG_TYPES_HDR_MAJOR_VERSION != (5u)) \
   || (WDGM_CFG_TYPES_HDR_MINOR_VERSION != (2u)) )
# error "Version numbers of WdgM_PBcfg.h and WdgM_Cfg.h are inconsistent!"
#endif

# define WDGM_NR_OF_CHECKPOINTS           (31u) 
# define WDGM_NR_OF_ENTITIES              (15u) 
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u) 
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (1u) 
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (15u) 
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u) 
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u) 

/* Checkpoints for supervised entity 'SE_2msA_Appl10' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_2msA_Appl10_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_2msA_Appl10_End (1u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_GblFinal (2u) 
/* Checkpoints for supervised entity 'SE_4ms_Appl10' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl10_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl10_End (1u) 
/* Checkpoints for supervised entity 'SE_100ms_Appl10' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl10_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl10_End (1u) 
/* Checkpoints for supervised entity 'SE_10ms_Appl10' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_End (1u) 
/* Checkpoints for supervised entity 'SE_10msBsw_Appl10' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_End (1u) 
/* Checkpoints for supervised entity 'SE_2ms_Appl9' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl9_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl9_End (1u) 
/* Checkpoints for supervised entity 'SE_10ms_Appl9' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl9_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl9_End (1u) 
/* Checkpoints for supervised entity 'SE_100ms_Appl9' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl9_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl9_End (1u) 
/* Checkpoints for supervised entity 'SE_2ms_Appl8' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl8_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl8_End (1u) 
/* Checkpoints for supervised entity 'SE_10ms_Appl8' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl8_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl8_End (1u) 
/* Checkpoints for supervised entity 'SE_2ms_Appl7' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl7_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl7_End (1u) 
/* Checkpoints for supervised entity 'SE_10ms_Appl7' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl7_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl7_End (1u) 
/* Checkpoints for supervised entity 'SE_4ms_Appl7' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl7_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl7_End (1u) 
/* Checkpoints for supervised entity 'SE_100ms_Appl7' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl7_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl7_End (1u) 
/* Checkpoints for supervised entity 'SE_2msB_Appl10' */ 
# define WdgMConf_WdgMCheckpoint_ChkPt_2msB_Appl10_Strt (0u) 
# define WdgMConf_WdgMCheckpoint_ChkPt_2msB_Appl10_End (1u) 
 

# define WdgMConf_WdgMSupervisedEntity_SE_2msA_Appl10 (0u) 
# define WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl10 (1u) 
# define WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl10 (2u) 
# define WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl10 (3u) 
# define WdgMConf_WdgMSupervisedEntity_SE_10msBsw_Appl10 (4u) 
# define WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl9 (5u) 
# define WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl9 (6u) 
# define WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl9 (7u) 
# define WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl8 (8u) 
# define WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl8 (9u) 
# define WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl7 (10u) 
# define WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl7 (11u) 
# define WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl7 (12u) 
# define WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl7 (13u) 
# define WdgMConf_WdgMSupervisedEntity_SE_2msB_Appl10 (14u) 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0; 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define WDGM_START_SEC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* 
 * No status reporting enabled. 
 * 
 * WdgMStatusReportingMechanism is configured to WDGM_USE_NO_STATUS_REPORTING. 
 * 
 * To enable status reporting set WdgMStatusReportingMechanism to WDGM_USE_NOTIFICATIONS or WDGM_USE_MODE_SWITCH_PORTS. 
 */ 

#define WDGM_STOP_SEC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* WDGM_PBCFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_PBcfg.h
 *********************************************************************************************************************/

