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
 *              File: WdgM_PBcfg.c
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

#define WDGM_PBCFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "WdgM.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/

#define WDGM_PBCFG_C_MAJOR_VERSION (2u) 
#define WDGM_PBCFG_C_MINOR_VERSION (1u) 
#define WDGM_PBCFG_C_PATCH_VERSION (1u) 

/* Check the version of WdgM header file */
#if ( (WDGM_SW_MAJOR_VERSION != (5u)) \
   || (WDGM_SW_MINOR_VERSION != (2u)) )
# error "Version numbers of WdgM_PBcfg.c and WdgM.h are inconsistent!"
#endif

/* Check the version of WdgM PBCfg header file */
#if ( (WDGM_PBCFG_MAJOR_VERSION != WDGM_PBCFG_C_MAJOR_VERSION) \
   || (WDGM_PBCFG_MINOR_VERSION != WDGM_PBCFG_C_MINOR_VERSION) \
   || (WDGM_PBCFG_PATCH_VERSION != WDGM_PBCFG_C_PATCH_VERSION) )
# error "Version numbers of WdgM_PBcfg.c and WdgM_PBcfg.h are inconsistent!"
#endif

#if !defined (WDGM_LOCAL) /* COV_WDGM_COMPATIBILITY */
# define WDGM_LOCAL static
#endif

#define WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for global shared data */ 
WDGM_LOCAL VAR(WdgM_DataGSType, WDGM_VAR_NOINIT) StatusGS_core0; 
WDGM_LOCAL VAR(WdgM_EntityGSType, WDGM_VAR_NOINIT) EntityGS [WDGM_NR_OF_ENTITIES]; 
WDGM_LOCAL VAR(WdgM_GlobalTransitionFlagGSType, WDGM_VAR_NOINIT) GlobalTransitionFlagsGS [WDGM_NR_OF_GLOBAL_TRANSITIONS]; 
#define WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 


#define WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_2msA_Appl10' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_0; 
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE0_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* Local Alive Counters for checkpoint 'ChkPt_2msA_Appl10_End' in 'SE_2msA_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_0; 
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE1_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_4ms_Appl10' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_1; 
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE1_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* Local Alive Counters for checkpoint 'ChkPt_4ms_Appl10_End' in 'SE_4ms_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_1; 
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE2_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_100ms_Appl10' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_2; 
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE2_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* Local Alive Counters for checkpoint 'ChkPt_100ms_Appl10_End' in 'SE_100ms_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_2; 
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE3_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_10ms_Appl10' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_3; 
#define WDGM_SE3_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE4_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_10msBsw_Appl10' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_4; 
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE4_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* Local Alive Counters for checkpoint 'ChkPt_10msBsw_Appl10_End' in 'SE_10msBsw_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_3; 
#define WDGM_SE4_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE5_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_2ms_Appl9' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_5; 
#define WDGM_SE5_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE6_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_10ms_Appl9' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_6; 
#define WDGM_SE6_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE7_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_100ms_Appl9' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_7; 
#define WDGM_SE7_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE8_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_2ms_Appl8' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_8; 
#define WDGM_SE8_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE9_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_10ms_Appl8' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_9; 
#define WDGM_SE9_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE10_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_2ms_Appl7' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_10; 
#define WDGM_SE10_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE11_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_10ms_Appl7' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_11; 
#define WDGM_SE11_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE12_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_4ms_Appl7' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_12; 
#define WDGM_SE12_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE13_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_100ms_Appl7' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_13; 
#define WDGM_SE13_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
#define WDGM_SE14_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
/* RAM section for supervisedEntity 'SE_2msB_Appl10' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_14; 
#define WDGM_SE14_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
 
#define WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 
 
/* Global Status for Supervised Entities */ 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_0; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_1; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_2; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_3; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_4; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_5; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_6; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_7; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_8; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_9; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_10; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_11; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_12; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_13; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_14; 
 
/* Global Alive Counters for checkpoint 'ChkPt_2msA_Appl10_End' in supervised entity 'SE_2msA_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_0; 
 
/* Global Alive Counters for checkpoint 'ChkPt_4ms_Appl10_End' in supervised entity 'SE_4ms_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_1; 
 
/* Global Alive Counters for checkpoint 'ChkPt_100ms_Appl10_End' in supervised entity 'SE_100ms_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_2; 
 
/* Global Alive Counters for checkpoint 'ChkPt_10msBsw_Appl10_End' in supervised entity 'SE_10msBsw_Appl10' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_3; 
 
/* RAM section for Global Status */ 
WDGM_LOCAL VAR(WdgM_DataGType, WDGM_VAR_NOINIT) StatusG_core0; 
 
/* Global variables */ 
WDGM_LOCAL VAR(WdgM_GlobalVariablesType, WDGM_VAR_NOINIT) GlobalVariables_core0; 
 
#define WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */ 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

WDGM_LOCAL CONST(WdgM_TransitionType, WDGM_CONST) WdgMTransition[WDGM_NR_OF_LOCAL_TRANSITIONS] =
{
  {
    WdgMConf_WdgMSupervisedEntity_SE_2msA_Appl10 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2msA_Appl10_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl10 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl10_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl10 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl10_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [2]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl10 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [3]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10msBsw_Appl10 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [4]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl9 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl9_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [5]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl9 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl9_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [6]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl9 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl9_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [7]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl8 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl8_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [8]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl8 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl8_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [9]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl7 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl7_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [10]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl7 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl7_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [11]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl7 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl7_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [12]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl7 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl7_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [13]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2msB_Appl10 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2msB_Appl10_Strt /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ 
  } /*  [14]  */ 
};

WDGM_LOCAL CONST(WdgM_GlobalTransitionType, WDGM_CONST) WdgMGlobalTransition[WDGM_NR_OF_GLOBAL_TRANSITIONS] =
{
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl10 /*  EntitySourceId  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_End /*  CheckpointSourceId  */ , 
    0u /*  WdgMDeadlineMin  */ , 
    0u /*  WdgMDeadlineMax  */ , 
    0u /*  GlobalTransitionFlagId  */ 
  } /*  [0]  */ 
};

WDGM_LOCAL CONST(WdgM_TransitionIdType, WDGM_CONST) StartsGlobalTransition_SE_10ms_Appl10_ChkPt_10ms_Appl10_End[1] = /* PRQA S 0779 */ /* MD_WdgM_0779 */ 
{
  0u /*  [0]  */ 
}; 


WDGM_LOCAL CONST(WdgM_CheckPointType, WDGM_CONST) WdgMCheckPoint[WDGM_NR_OF_CHECKPOINTS] =
{
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2msA_Appl10_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2msA_Appl10_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    2u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    1u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_0 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_0 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[0] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_GblFinal /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    TRUE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [2]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl10_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [3]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl10_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    1u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    1u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_1 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_1 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[1] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [4]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl10_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [5]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl10_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    1u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    25u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_2 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_2 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[2] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [6]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [7]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[3] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    TRUE /*  WdgMStartsAGlobalTransition  */ , 
    1u /*  NrOfStartedGlobalTransitions  */ , 
    StartsGlobalTransition_SE_10ms_Appl10_ChkPt_10ms_Appl10_End /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [8]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    1u /*  NrOfGlobalTransitions  */ , 
    &WdgMGlobalTransition[0] /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [9]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    2u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    5u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_3 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_3 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[4] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [10]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl9_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [11]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl9_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[5] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [12]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl9_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [13]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl9_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[6] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [14]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl9_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [15]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl9_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[7] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [16]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl8_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [17]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl8_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[8] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [18]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl8_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [19]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl8_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[9] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [20]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl7_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [21]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl7_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[10] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [22]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl7_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [23]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl7_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[11] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [24]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl7_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [25]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl7_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[12] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [26]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl7_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [27]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl7_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[13] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [28]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2msB_Appl10_Strt /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [29]  */ , 
  {
    WdgMConf_WdgMCheckpoint_ChkPt_2msB_Appl10_End /*  WdgMCheckpointId  */ , 
    TRUE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    0u /*  WdgMExpectedAliveIndications  */ , 
    0u /*  WdgMMinMargin  */ , 
    0u /*  WdgMMaxMargin  */ , 
    0u /*  WdgMSupervisionReferenceCycle  */ , 
    NULL_PTR /*  WdgMAliveLRef  */ , 
    NULL_PTR /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    1u /*  NrOfLocalTransitions  */ , 
    &WdgMTransition[14] /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [30]  */ 
};


WDGM_LOCAL CONST(WdgM_SupervisedEntityType, WDGM_CONST) WdgMSupervisedEntity[WDGM_NR_OF_ENTITIES] =
{
  {
    WdgMConf_WdgMSupervisedEntity_SE_2msA_Appl10 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2msA_Appl10_Strt /*  WdgMCheckpointLocInitialId  */ , 
    3u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[0] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_0 /*  EntityStatusLRef  */ , 
    &EntityStatusG_0 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl10 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl10_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[3] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_1 /*  EntityStatusLRef  */ , 
    &EntityStatusG_1 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl10 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl10_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[5] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_2 /*  EntityStatusLRef  */ , 
    &EntityStatusG_2 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [2]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl10 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[7] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_3 /*  EntityStatusLRef  */ , 
    &EntityStatusG_3 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [3]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10msBsw_Appl10 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10msBsw_Appl10_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[9] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_4 /*  EntityStatusLRef  */ , 
    &EntityStatusG_4 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [4]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl9 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl9_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[11] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_5 /*  EntityStatusLRef  */ , 
    &EntityStatusG_5 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [5]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl9 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl9_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[13] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_6 /*  EntityStatusLRef  */ , 
    &EntityStatusG_6 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [6]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl9 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl9_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[15] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_7 /*  EntityStatusLRef  */ , 
    &EntityStatusG_7 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [7]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl8 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl8_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[17] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_8 /*  EntityStatusLRef  */ , 
    &EntityStatusG_8 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [8]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl8 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl8_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[19] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_9 /*  EntityStatusLRef  */ , 
    &EntityStatusG_9 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [9]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2ms_Appl7 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2ms_Appl7_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[21] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_10 /*  EntityStatusLRef  */ , 
    &EntityStatusG_10 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [10]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl7 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl7_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[23] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_11 /*  EntityStatusLRef  */ , 
    &EntityStatusG_11 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [11]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_4ms_Appl7 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_4ms_Appl7_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[25] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_12 /*  EntityStatusLRef  */ , 
    &EntityStatusG_12 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [12]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_100ms_Appl7 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_100ms_Appl7_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[27] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_13 /*  EntityStatusLRef  */ , 
    &EntityStatusG_13 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [13]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_SE_2msB_Appl10 /*  WdgMSupervisedEntity  */ , 
    TRUE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_ChkPt_2msB_Appl10_Strt /*  WdgMCheckpointLocInitialId  */ , 
    2u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[29] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    0u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    TRUE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    NULL_PTR /*  WdgM_LocalStateChangeCbk  */ , 
    NULL_PTR /*  WdgM_StatusReportToRte  */ , 
    &EntityStatusL_14 /*  EntityStatusLRef  */ , 
    &EntityStatusG_14 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [14]  */ 
};


WDGM_LOCAL CONST(WdgM_TriggerModeType, WDGM_CONST) WdgMTriggerMode_core0[WDGM_NR_OF_WATCHDOGS_CORE0 * WDGM_NR_OF_TRIGGER_MODES_CORE0] = 
{
  {
    2u /*  WdgMTriggerWindowStart  */ , 
    1u /*  WdgMTicksPerSecond[Hz]=250 , WdgMTriggerWindowStartTicks  */ , 
    7u /*   (condition value)  WdgMTriggerTimeout  */ , 
    2u /*  WdgMTicksPerSecond[Hz]=250 , WdgMTriggerTimeoutTicks  */ , 
    WDGIF_SLOW_MODE /*  WdgMWatchdogMode  */ , 
    0u /*  WdgMDeviceIndex  */ 
  } /*  WdgMTriggerModeId 0  */ 
}; 
 
WDGM_LOCAL CONST(WdgM_WatchdogDeviceType, WDGM_CONST) WdgMWatchdogDevice0[WDGM_NR_OF_WATCHDOGS_CORE0] = 
{
  {
    &WdgMTriggerMode_core0[0] /*  WdgMTriggerModeRef  */ 
  } /*  [0]  */ 
}; 


WDGM_LOCAL CONST(WdgM_CallersType, WDGM_CONST) WdgMAllowedCallers[WDGM_NR_OF_ALLOWED_CALLERS] =
{
  {
    0u /*  WdgMAllowedCaller  */ 
  } /*  [0]  */ 
};


CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0 = 
{
  5u /*  WdgMConfigMajorVersion  */ , 
  2u /*  WdgMConfigMinorVersion  */ , 
  0u /*  WdgMConfigId  */ , 
  0u /*  WdgMInitialTriggerModeId  */ , 
  0u /*  WdgMExpiredSupervisionCycleTol  */ , 
  WdgMConf_WdgMSupervisedEntity_SE_10ms_Appl10 /*  WdgMGlobInitialEntityId  */ , 
  WdgMConf_WdgMCheckpoint_ChkPt_10ms_Appl10_End /*  WdgMGlobInitialCheckpointId  */ , 
  WDGM_NR_OF_GLOBAL_TRANSITIONS /*  NrOfGlobalTransitions  */ , 
  WdgMGlobalTransition /*  WdgMGlobalTransitions  */ , 
  WDGM_NR_OF_WATCHDOGS_CORE0 /*  NrOfWatchdogDevices  */ , 
  WDGM_NR_OF_TRIGGER_MODES_CORE0 /*  NrOfTriggerModes  */ , 
  WdgMWatchdogDevice0 /*  WdgMWatchdogDeviceRef  */ , 
  WDGM_NR_OF_ALLOWED_CALLERS /*  NrOfAllowedCallers  */ , 
  WdgMAllowedCallers /*  WdgMCallersRef  */ , 
  WDGM_NR_OF_ENTITIES /*  NrOfSupervisedEntities  */ , 
  WdgMSupervisedEntity /*  WdgMSupervisedEntityRef  */ , 
  &StatusG_core0 /*  DataGRef  */ , 
  &StatusGS_core0 /*  DataGSRef  */ , 
  EntityGS /*  EntityGSRef  */ , 
  GlobalTransitionFlagsGS /*  GlobalTransitionFlagsGSRef  */ , 
  NULL_PTR /*  WdgM_GlobalStateChangeCbk  */ , 
  NULL_PTR /*  WdgM_StatusReportToRte  */ , 
  &GlobalVariables_core0 /*  WdgMGlobalVariables  */ , 
  0u /*  WdgMModeCoreAssignment  */ , 
  0 /*  WdgMOsCounter  */ , 
  206u /*  WdgMConfigChecksum  */ 
}; 
 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  END OF FILE: WdgM_PBcfg.c
 *********************************************************************************************************************/

