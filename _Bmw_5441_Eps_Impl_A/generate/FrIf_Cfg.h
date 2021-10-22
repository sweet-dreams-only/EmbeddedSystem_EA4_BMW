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
 *            Module: FrIf
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrIf_Cfg.h
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



/**        \file  FrIf_Cfg.h
 *        \brief  FrIf Cfg header file
 *
 *      \details  Cfg header file of the AUTOSAR FlexRay Interface, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/
 
#if !defined(FRIF_CFG_H)
#define FRIF_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

#include "Platform_Types.h"

#include "FrTrcv_30_Tja1082.h"
#include "FrTrcv_30_Tja1082_Cbk.h"


/* -----------------------------------------------------------------------------
    &&&~ Linktime / Precompile CRC
 ----------------------------------------------------------------------------- */

#define FRIF_CRC_CHECK                       		STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Defines
 ----------------------------------------------------------------------------- */

/*  Version information  */
#define FRIF_CFG_MAJOR_VERSION               4U 
#define FRIF_CFG_MINOR_VERSION               1U
#define FRIF_CFG_PATCH_VERSION               2U

#define FRIF_SYNC_THRESHOLD         (uint16) 100U
#define FRIF_FILL_PATTERN           (uint8)  0x00U
#define FRIF_FILL_PATTERN_DWORD     (uint32) 0x00000000UL

#ifndef FRIF_USE_DUMMY_FUNCTIONS
#define FRIF_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef FRIF_USE_DUMMY_STATEMENT
#define FRIF_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef FRIF_DUMMY_STATEMENT
#define FRIF_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRIF_DUMMY_STATEMENT_CONST
#define FRIF_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef FRIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FRIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FRIF_ATOMIC_VARIABLE_ACCESS
#define FRIF_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FRIF_PROCESSOR_RH850_1363
#define FRIF_PROCESSOR_RH850_1363
#endif
#ifndef FRIF_COMP_GREENHILLS
#define FRIF_COMP_GREENHILLS
#endif
#ifndef FRIF_GEN_GENERATOR_MSR
#define FRIF_GEN_GENERATOR_MSR
#endif
#ifndef FRIF_CPUTYPE_BITORDER_LSB2MSB
#define FRIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef FRIF_CONFIGURATION_VARIANT_PRECOMPILE
#define FRIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FRIF_CONFIGURATION_VARIANT_LINKTIME
#define FRIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FRIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FRIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FRIF_CONFIGURATION_VARIANT
#define FRIF_CONFIGURATION_VARIANT FRIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FRIF_POSTBUILD_VARIANT_SUPPORT
#define FRIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#ifndef FRIF_DEV_ERROR_DETECT
# define FRIF_DEV_ERROR_DETECT      STD_ON /* /MICROSAR/FrIf/FrIfGeneral/FrIfSafeBswChecks || /MICROSAR/FrIf/FrIfGeneral/FrIfDevErrorDetect */
#endif
#ifndef FRIF_DEV_ERROR_REPORT
# define FRIF_DEV_ERROR_REPORT      STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfDevErrorDetect */
#endif

/* -----------------------------------------------------------------------------
    &&&~ Symbolic Name Value Defines
 ----------------------------------------------------------------------------- */

/* FrIfClstIdx */



/**
 * \defgroup FrIfHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrIfConf_FrIfCluster_A_FlexRay                                0
/**\} */

/* FrIfCtrlIdx */



/**
 * \defgroup FrIfHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrIfConf_FrIfController_EPS_A_FlexRay                         0
/**\} */

/* FrIfLPduIdx */



/**
 * \defgroup FrIfHandleIdsFrIfAllLPdus/ActiveEcuC/FrIf/FrIfConfig/A_FlexRay/EPS_A_FlexRay Handle IDs of handle space FrIfAllLPdus /ActiveEcuC/FrIf/FrIfConfig/A_FlexRay/EPS_A_FlexRay.
 * \brief Single Tx/Rx LPdu handle space of /ActiveEcuC/FrIf/FrIfConfig/A_FlexRay/EPS_A_FlexRay
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrIfConf_FrIfLPdu_LPdu_frTrig_801_S_8_B_0_R_1_ChA_OUT         23
#define FrIfConf_FrIfLPdu_LPdu_frTrig_901_S_9_B_0_R_1_ChA_OUT         22
#define FrIfConf_FrIfLPdu_LPdu_frTrig_1001_S_10_B_0_R_1_ChA_OUT       21
#define FrIfConf_FrIfLPdu_LPdu_frTrig_1101_S_11_B_0_R_1_ChA_OUT       20
#define FrIfConf_FrIfLPdu_LPdu_frTrig_1201_S_12_B_0_R_1_ChA_OUT       19
#define FrIfConf_FrIfLPdu_LPdu_frTrig_4601_S_46_B_0_R_1_ChA_IN        68
#define FrIfConf_FrIfLPdu_LPdu_frTrig_4712_S_47_B_1_R_2_ChA_IN        67
#define FrIfConf_FrIfLPdu_LPdu_frTrig_4902_S_49_B_0_R_2_ChA_OUT       18
#define FrIfConf_FrIfLPdu_LPdu_frTrig_4912_S_49_B_1_R_2_ChA_OUT       17
#define FrIfConf_FrIfLPdu_LPdu_frTrig_5102_S_51_B_0_R_2_ChA_OUT       16
#define FrIfConf_FrIfLPdu_LPdu_frTrig_5338_S_53_B_3_R_8_ChA_IN        66
#define FrIfConf_FrIfLPdu_LPdu_frTrig_5502_S_55_B_0_R_2_ChA_IN        64
#define FrIfConf_FrIfLPdu_LPdu_frTrig_5534_S_55_B_3_R_4_ChA_IN        65
#define FrIfConf_FrIfLPdu_LPdu_frTrig_5602_S_56_B_0_R_2_ChA_IN        63
#define FrIfConf_FrIfLPdu_LPdu_frTrig_6512_S_65_B_1_R_2_ChA_IN        62
#define FrIfConf_FrIfLPdu_LPdu_frTrig_6802_S_68_B_0_R_2_ChA_IN        60
#define FrIfConf_FrIfLPdu_LPdu_frTrig_6812_S_68_B_1_R_2_ChA_IN        61
#define FrIfConf_FrIfLPdu_LPdu_frTrig_10401_S_104_B_0_R_1_ChA_IN      59
#define FrIfConf_FrIfLPdu_LPdu_frTrig_10701_S_107_B_0_R_1_ChA_IN      58
#define FrIfConf_FrIfLPdu_LPdu_frTrig_10802_S_108_B_0_R_2_ChA_IN      57
#define FrIfConf_FrIfLPdu_LPdu_frTrig_11702_S_117_B_0_R_2_ChA_IN      56
#define FrIfConf_FrIfLPdu_LPdu_frTrig_11912_S_119_B_1_R_2_ChA_IN      55
#define FrIfConf_FrIfLPdu_LPdu_frTrig_12112_S_121_B_1_R_2_ChA_IN      54
#define FrIfConf_FrIfLPdu_LPdu_frTrig_14701_S_147_B_0_R_1_ChA_IN      53
#define FrIfConf_FrIfLPdu_LPdu_frTrig_18301_S_183_B_0_R_1_ChA_OUT     15
#define FrIfConf_FrIfLPdu_LPdu_frTrig_20901_S_209_B_0_R_1_ChA_IN      52
#define FrIfConf_FrIfLPdu_LPdu_frTrig_21001_S_210_B_0_R_1_ChA_IN      51
#define FrIfConf_FrIfLPdu_LPdu_frTrig_21101_S_211_B_0_R_1_ChA_IN      50
#define FrIfConf_FrIfLPdu_LPdu_frTrig_21201_S_212_B_0_R_1_ChA_IN      49
#define FrIfConf_FrIfLPdu_LPdu_frTrig_21301_S_213_B_0_R_1_ChA_IN      48
#define FrIfConf_FrIfLPdu_LPdu_frTrig_21434_S_214_B_3_R_4_ChA_IN      47
#define FrIfConf_FrIfLPdu_LPdu_frTrig_21901_S_219_B_0_R_1_ChA_IN      34
#define FrIfConf_FrIfLPdu_LPdu_frTrig_22001_S_220_B_0_R_1_ChA_OUT     13
#define FrIfConf_FrIfLPdu_LPdu_frTrig_23212_S_232_B_1_R_2_ChA_IN      33
#define FrIfConf_FrIfLPdu_LPdu_frTrig_23412_S_234_B_1_R_2_ChA_OUT     12
#define FrIfConf_FrIfLPdu_LPdu_frTrig_24404_S_244_B_0_R_4_ChA_IN      32
#define FrIfConf_FrIfLPdu_LPdu_frTrig_24702_S_247_B_0_R_2_ChA_IN      30
#define FrIfConf_FrIfLPdu_LPdu_frTrig_24712_S_247_B_1_R_2_ChA_IN      31
#define FrIfConf_FrIfLPdu_LPdu_frTrig_25214_S_252_B_1_R_4_ChA_IN      29
#define FrIfConf_FrIfLPdu_LPdu_frTrig_26924_S_269_B_2_R_4_ChA_IN      28
#define FrIfConf_FrIfLPdu_LPdu_frTrig_27408_S_274_B_0_R_8_ChA_OUT     10
#define FrIfConf_FrIfLPdu_LPdu_frTrig_27424_S_274_B_2_R_4_ChA_OUT     9
#define FrIfConf_FrIfLPdu_LPdu_frTrig_27518_S_275_B_1_R_8_ChA_IN      26
#define FrIfConf_FrIfLPdu_LPdu_frTrig_27578_S_275_B_7_R_8_ChA_IN      27
#define FrIfConf_FrIfLPdu_LPdu_frTrig_27628_S_276_B_2_R_8_ChA_IN      24
#define FrIfConf_FrIfLPdu_LPdu_frTrig_27648_S_276_B_4_R_8_ChA_IN      25
#define FrIfConf_FrIfLPdu_LPdu_frTrig_29401_S_294_B_0_R_1_ChA_OUT     8
#define FrIfConf_FrIfLPdu_LPdu_frTrig_29501_S_295_B_0_R_1_ChA_OUT     7
#define FrIfConf_FrIfLPdu_LPdu_frTrig_29601_S_296_B_0_R_1_ChA_OUT     6
#define FrIfConf_FrIfLPdu_LPdu_frTrig_29701_S_297_B_0_R_1_ChA_OUT     5
#define FrIfConf_FrIfLPdu_LPdu_frTrig_29801_S_298_B_0_R_1_ChA_OUT     4
#define FrIfConf_FrIfLPdu_LPdu_frTrig_29901_S_299_B_0_R_1_ChA_OUT     3
#define FrIfConf_FrIfLPdu_LPdu_frTrig_30001_S_300_B_0_R_1_ChA_OUT     2
#define FrIfConf_FrIfLPdu_LPdu_frTrig_30101_S_301_B_0_R_1_ChA_OUT     1
#define FrIfConf_FrIfLPdu_LPdu_frTrig_31501_S_315_B_0_R_1_ChA_OUT     0
#define FrIfConf_FrIfLPdu_LPdu_frTrig_215216_S_215_B_2_R_16_ChA_IN    42
#define FrIfConf_FrIfLPdu_LPdu_frTrig_215516_S_215_B_5_R_16_ChA_IN    43
#define FrIfConf_FrIfLPdu_LPdu_frTrig_215616_S_215_B_6_R_16_ChA_IN    44
#define FrIfConf_FrIfLPdu_LPdu_frTrig_215916_S_215_B_9_R_16_ChA_IN    45
#define FrIfConf_FrIfLPdu_LPdu_frTrig_216616_S_216_B_6_R_16_ChA_IN    35
#define FrIfConf_FrIfLPdu_LPdu_frTrig_216716_S_216_B_7_R_16_ChA_IN    36
#define FrIfConf_FrIfLPdu_LPdu_frTrig_216916_S_216_B_9_R_16_ChA_OUT   14
#define FrIfConf_FrIfLPdu_LPdu_frTrig_2151016_S_215_B_10_R_16_ChA_IN  46
#define FrIfConf_FrIfLPdu_LPdu_frTrig_2161016_S_216_B_10_R_16_ChA_IN  37
#define FrIfConf_FrIfLPdu_LPdu_frTrig_2161216_S_216_B_12_R_16_ChA_IN  38
#define FrIfConf_FrIfLPdu_LPdu_frTrig_2161316_S_216_B_13_R_16_ChA_IN  39
#define FrIfConf_FrIfLPdu_LPdu_frTrig_2161416_S_216_B_14_R_16_ChA_IN  40
#define FrIfConf_FrIfLPdu_LPdu_frTrig_2161516_S_216_B_15_R_16_ChA_IN  41
#define FrIfConf_FrIfLPdu_LPdu_frTrig_2481032_S_248_B_10_R_32_ChA_OUT 11
/**\} */

/* -----------------------------------------------------------------------------
    &&&~ Rx PDU Handles
 ----------------------------------------------------------------------------- */

#define FrIfConf_FrIfRxPdu_FrIfRxPdu_RELATIVZEIT 0U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_KILOMETERSTAND 1U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_FZZSTD 2U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_FAHRGESTELLNUMMER 3U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_CTR_VIB_STW_DISP_EXMI_SP2015 4U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_A_TEMP 5U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_CTR_DIAG_OBD_DRDY 6U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_DIAG_OBD_ENG 7U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_SECU_FAHRGESTELLNUMMER 8U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_ST_ENERG_GEN 9U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_dummy32bmaster 10U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_SVC_In 11U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_TL_BRC_FR_32 12U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_TL_MST_GW_TRNSM_FR_254 13U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_CON_VEH 14U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_ENSU_SFY 15U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_ST_CENG 16U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_STEA_OFFS 17U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_OFFS_QUAD_EPS 18U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_ERRM_BN_U 19U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_TAR_QTA_STRMOM_DV 20U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_TAR_STMOM_DV_ACT 21U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_ENERG_DGR_DRDY 22U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_TAR_ESTP_VIRT_FTAX 23U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_VYAW_VEH 24U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_ACLNY_MASSCNTR 25U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_V_VEH 26U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_SU_CLE_DRDY_DXP 27U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_ST_STAB_DSC 28U 
#define FrIfConf_FrIfRxPdu_FrIfRxPdu_AVL_RPM_WHL 29U 


/* -----------------------------------------------------------------------------
    &&&~ Tx PDU Handles
 ----------------------------------------------------------------------------- */



/**
 * \defgroup FrIfHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_AVL_FORC_GRD                     20
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_AVL_PO_EPS                       16
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_AVL_STMOM_DV_ACT                 19
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_DISP_CC_EPS                      9
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_DT_EST                           18
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_ENGTORQ_EPS                      17
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_FR_DBG_EPS                       0
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_ST_DIAG_OBD_3_DRDY               11
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_ST_EST                           12
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_SU_EPS                           10
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_SVC                              14
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_TL_ECU_TRNSM_FR_32               15
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_dummy16bstatic                   21
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_dummy32bslave                    13
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_1                  8
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_2                  7
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_3                  6
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_4                  5
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_5                  4
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_6                  3
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_7                  2
#define FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_8                  1
/**\} */

/* -----------------------------------------------------------------------------
    &&&~ Upper Layer PDU Handles
 ----------------------------------------------------------------------------- */
#define FRIF_TX_ulFR_DBG_EPS PduRConf_PduRDestPdu_DST_Fr_pduTrig_FR_DBG_EPS_55c86d41 
#define FRIF_TX_ulxcpdynamic254_8 XcpConf_XcpTxPdu_xcpdynamic254_8_19255f18 
#define FRIF_TX_ulxcpdynamic254_7 XcpConf_XcpTxPdu_xcpdynamic254_7_19255f18 
#define FRIF_TX_ulxcpdynamic254_6 XcpConf_XcpTxPdu_xcpdynamic254_6_19255f18 
#define FRIF_TX_ulxcpdynamic254_5 XcpConf_XcpTxPdu_xcpdynamic254_5_19255f18 
#define FRIF_TX_ulxcpdynamic254_4 XcpConf_XcpTxPdu_xcpdynamic254_4_19255f18 
#define FRIF_TX_ulxcpdynamic254_3 XcpConf_XcpTxPdu_xcpdynamic254_3_19255f18 
#define FRIF_TX_ulxcpdynamic254_2 XcpConf_XcpTxPdu_xcpdynamic254_2_19255f18 
#define FRIF_TX_ulxcpdynamic254_1 XcpConf_XcpTxPdu_xcpdynamic254_1_19255f18 
#define FRIF_TX_ulDISP_CC_EPS PduRConf_PduRDestPdu_DST_Fr_pduTrig_DISP_CC_EPS_55c86d41 
#define FRIF_TX_ulSU_EPS PduRConf_PduRDestPdu_DST_Fr_pduTrig_SU_EPS_55c86d41 
#define FRIF_TX_ulST_DIAG_OBD_3_DRDY PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_DIAG_OBD_3_DRDY_55c86d41 
#define FRIF_TX_ulST_EST PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_EST_55c86d41 
#define FRIF_TX_uldummy32bslave XcpConf_XcpTxPdu_dummy32bslave_19255f18 
#define FRIF_TX_ulSVC_Out PduRConf_PduRDestPdu_DST_SVC_fbd80461_Out 
#define FRIF_TX_ulTL_ECU_TRNSM_FR_32 FrTpConf_FrTpTxPdu_FrTpTxPduTRNSM 
#define FRIF_TX_ulAVL_PO_EPS PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_PO_EPS_55c86d41 
#define FRIF_TX_ulENGTORQ_EPS PduRConf_PduRDestPdu_DST_Fr_pduTrig_ENGTORQ_EPS_55c86d41 
#define FRIF_TX_ulDT_EST PduRConf_PduRDestPdu_DST_Fr_pduTrig_DT_EST_55c86d41 
#define FRIF_TX_ulAVL_STMOM_DV_ACT PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_STMOM_DV_ACT_55c86d41 
#define FRIF_TX_ulAVL_FORC_GRD PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_FORC_GRD_55c86d41 
#define FRIF_TX_uldummy16bstatic XcpConf_XcpTxPdu_dummy16bstatic_19255f18 
#define FRIF_RX_ulRELATIVZEIT PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_RELATIVZEIT_55c86d41 
#define FRIF_RX_ulKILOMETERSTAND PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_KILOMETERSTAND_55c86d41 
#define FRIF_RX_ulFZZSTD PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FZZSTD_55c86d41 
#define FRIF_RX_ulFAHRGESTELLNUMMER PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FAHRGESTELLNUMMER_55c86d41 
#define FRIF_RX_ulCTR_VIB_STW_DISP_EXMI_SP2015 PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CTR_VIB_STW_DISP_EXMI_SP2015_55c86d41 
#define FRIF_RX_ulA_TEMP PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_A_TEMP_55c86d41 
#define FRIF_RX_ulCTR_DIAG_OBD_DRDY PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CTR_DIAG_OBD_DRDY_55c86d41 
#define FRIF_RX_ulDIAG_OBD_ENG PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DIAG_OBD_ENG_55c86d41 
#define FRIF_RX_ulSECU_FAHRGESTELLNUMMER PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SECU_FAHRGESTELLNUMMER_55c86d41 
#define FRIF_RX_ulST_ENERG_GEN PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_ENERG_GEN_55c86d41 
#define FRIF_RX_uldummy32bmaster XcpConf_XcpRxPdu_dummy32bmaster_19255f18 
#define FRIF_RX_ulSVC_In PduRConf_PduRSrcPdu_SRC_SVC_fbd80461_In 
#define FRIF_RX_ulTL_BRC_FR_32 FrTpConf_FrTpRxPdu_FrTpRxPduBRC 
#define FRIF_RX_ulTL_MST_GW_TRNSM_FR_254 FrTpConf_FrTpRxPdu_FrTpRxPduTRNSM 
#define FRIF_RX_ulCON_VEH PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CON_VEH_55c86d41 
#define FRIF_RX_ulENSU_SFY PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENSU_SFY_55c86d41 
#define FRIF_RX_ulST_CENG PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_CENG_55c86d41 
#define FRIF_RX_ulSTEA_OFFS PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_STEA_OFFS_55c86d41 
#define FRIF_RX_ulOFFS_QUAD_EPS PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_OFFS_QUAD_EPS_55c86d41 
#define FRIF_RX_ulERRM_BN_U PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ERRM_BN_U_55c86d41 
#define FRIF_RX_ulTAR_QTA_STRMOM_DV PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_QTA_STRMOM_DV_55c86d41 
#define FRIF_RX_ulTAR_STMOM_DV_ACT PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_STMOM_DV_ACT_55c86d41 
#define FRIF_RX_ulENERG_DGR_DRDY PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENERG_DGR_DRDY_55c86d41 
#define FRIF_RX_ulTAR_ESTP_VIRT_FTAX PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_ESTP_VIRT_FTAX_55c86d41 
#define FRIF_RX_ulVYAW_VEH PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_VYAW_VEH_55c86d41 
#define FRIF_RX_ulACLNY_MASSCNTR PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ACLNY_MASSCNTR_55c86d41 
#define FRIF_RX_ulV_VEH PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_V_VEH_55c86d41 
#define FRIF_RX_ulSU_CLE_DRDY_DXP PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SU_CLE_DRDY_DXP_55c86d41 
#define FRIF_RX_ulST_STAB_DSC PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_STAB_DSC_55c86d41 
#define FRIF_RX_ulAVL_RPM_WHL PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_RPM_WHL_55c86d41 


/* -----------------------------------------------------------------------------
    &&&~ Precompile config
 ----------------------------------------------------------------------------- */

#define FRIF_USE_FRTRCV_API                         STD_ON
#define FRIF_API_AS_MACRO                           STD_OFF  /* /MICROSAR/FrIf/FrIfGeneral/FrIfWrapperAPIsAsMacro */
#define FRIF_RELATIVE_ALARM_ENABLE                  STD_OFF
#define FRIF_PROD_ERROR_DETECT                      STD_OFF
#define FRIF_CHANNEL_STATUS_ENABLE                  STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfGetGetChannelStatusSupport */
#define FRIF_SET_EXT_SYNC_DISABLE                   STD_ON
#define FRIF_ASR40FRTRCVAPISUPPORT                  STD_ON
#define FRIF_READCCCONFIGSUPPORT                    STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfReadCCConfigApi */
#define FRIF_ABSOLUTE_TIMER_API_DISABLE             STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfAbsTimerIdx */ 
#define FRIF_GETNUMSTARTUPFRAMESSUPPORT             STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfGetNumOfStartupFramesSupport */
#define FRIF_ALLSLOTSSUPPORT                        STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfAllSlotsSupport */
#define FRIF_GETWAKEUPRXSTATUSSUPPORT               STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfGetWakeupRxStatusSupport */
#define FRIF_AMD_RUNTIME_MEASUREMENT                STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfRuntimeMeasurementSupport */ 
#define FRIF_SUPPRESS_PROTECTED_RANGE_CHECK         STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfSuppressProtectedRangeCheck */ 
#define FRIF_VERSION_INFO_API                       STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfVersionInfoApi */
#define FRIF_ENABLE_PREPARE_LPDU                    STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfEnablePrepareLpdu */
#define FRIF_CTRL_ENABLE_API_OPTIMIZATION           STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfSingleChannelAPI */
#define FRIF_UNIFORMUPDATEBYTEPOS                   STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfUniformUpdateBytePos */
#define FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfGlobalUniformUpdateBytePos */
#define FRIF_MEASURE_JLETASKTIMES                   STD_OFF
#define FRIF_PDUDIRTYBYTE_USAGE                     STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfPduDirtyByteUsage */
#define FRIF_JOB_CONCATENATION_ENABLE               STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfJobConcatenationEnable */
#define FRIF_DIRECT_BUFFER_ACCESS_ENABLE            STD_OFF /* /MICROSAR/Fr/FrGeneral/FrDirectBufferAccessEnable */
#define FRIF_FIFO_SUPPORT_ENABLE                    STD_OFF /* /MICROSAR/Fr/FrGeneral/FrFIFOSupport */
#define FRIF_CLOCK_CORRECTION_ENABLE                STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfGetClockCorrectionSupport */
#define FRIF_ABORT_COMMUNICATION_DISABLE            STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfAbortCommunicationDisable */
#define FRIF_SET_WAKEUP_CHANNEL_DISABLE             STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfSetWakeupChannelDisable */
#define FRIF_REQUEST_COUNTER_HANDLING_DISABLE       STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfCounterLimitDisable */
#define FRIF_CANCELTRANSMITSUPPORT                  STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfCancelTransmitSupport */
#define FRIF_DELAYEDTXCONFSUPPORT                   STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfDelayedTxConfirmationSupport */
#define FRIF_FREEOPCALLBACKSUPPORT                  STD_OFF
#define FRIF_RECONFIGLPDUSUPPORT                    STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfReconfigLPduSupport */
#define FRIF_DISABLELPDUSUPPORT                     STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfDisableLPduSupport */
#define FRIF_GETSYNCFRAMELISTSUPPORT                STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfGetSyncFrameListSupport */
#define FRIF_NMVECTORSUPPORT                        STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfGetNmVectorSupport */
#define FRIF_DUALCHANNELREDUNDANCYSUPPORT           STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIfDualChannelRedundancySupport */
#define FRIF_SILENT_CHECK                           STD_OFF
#define FRIF_NOREQUESTCOUNTERINITMEMORY             STD_ON 
#define FRIF_3RD_PARTY_DRIVER_SUPPORT               STD_OFF /* /MICROSAR/FrIf/FrIfGeneral/FrIf3rdPartyDriverSupport */


/* -----------------------------------------------------------------------------
    &&&~ Typedefs
 ----------------------------------------------------------------------------- */

typedef uint8 FrIf_FLEIdxType; 
typedef uint8 FrIf_NumberOfPduType;

/* -----------------------------------------------------------------------------
    &&&~ Precompile Defines
 ----------------------------------------------------------------------------- */
 
#define FRIF_AUTOSARVERSION4
#define FrIf_InvalidTxPduHandle                     22U
#define FrIf_NumberOfChannels                       1U
#define FrIf_NumberOfFrTrcvs                        1
#define FrIf_CommonMaxNumberOfControllers           1U
#define FrIf_CommonMaxNumberOfClusters              1U

/* -----------------------------------------------------------------------------
    &&&~ FrIf EcuC Global Configuration Container Name
 ----------------------------------------------------------------------------- */

#define FrIfConfig                                   FrIf_Config


#endif /* FRIF_CFG_H */

