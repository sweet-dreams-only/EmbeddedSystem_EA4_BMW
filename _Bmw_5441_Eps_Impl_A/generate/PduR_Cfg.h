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
 *            Module: PduR
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
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

#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_FUNCTIONS
#define PDUR_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_RH850_1363
#define PDUR_PROCESSOR_RH850_1363
#endif
#ifndef PDUR_COMP_GREENHILLS
#define PDUR_COMP_GREENHILLS
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define PDUR_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

 #define PDUR_ERROR_NOTIFICATION STD_OFF


#define PduR_PBConfigIdType uint32

#define PDUR_INVALID_VARARRAYIDX                                      ((uint16)0xFFFF) /**< Invalid VarArray element */

 /*  DET Error define list  */ 
#define PDUR_FCT_COMTX 0x89U 
#define PDUR_FCT_FRIFRXIND 0x31U 
#define PDUR_FCT_FRIFTX 0x39U 
#define PDUR_FCT_FRIFTXCFM 0x32U 
#define PDUR_FCT_FRIFTT 0x33U 
#define PDUR_FCT_IPDUMRXIND 0xA1U 
#define PDUR_FCT_IPDUMTX 0xA9U 
#define PDUR_FCT_IPDUMTXCFM 0xA2U 
#define PDUR_FCT_IPDUMTT 0xA3U 
#define PDUR_FCT_FRTPRXIND 0x35U 
#define PDUR_FCT_FRTPTX 0x39U 
#define PDUR_FCT_FRTPTXCFM 0x38U 
#define PDUR_FCT_FRTPSOR 0x36U 
#define PDUR_FCT_FRTPCPYRX 0x34U 
#define PDUR_FCT_FRTPCPYTX 0x37U 
#define PDUR_FCT_DCMTX 0x99U 
 /*   PduR_ComTransmit  PduR_FrIfIfRxIndication  PduR_FrIfTransmit  PduR_FrIfTxConfirmation  PduR_FrIfTriggerTransmit  PduR_IpduMIfRxIndication  PduR_IpduMTransmit  PduR_IpduMTxConfirmation  PduR_IpduMTriggerTransmit  PduR_FrTpTpRxIndication  PduR_FrTpTransmit  PduR_FrTpTxConfirmation  PduR_FrTpStartOfReception  PduR_FrTpCopyRxData  PduR_FrTpCopyTxData  PduR_DcmTransmit  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_ANFRAGE_fbd80461_In                  0
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ACLNY_MASSCNTR_55c86d41   2
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_RPM_WHL_55c86d41      3
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_A_TEMP_55c86d41           4
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_CON_VEH_55c86d41          5
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_CTR_DIAG_OBD_DRDY_55c86d41 6
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_CTR_VIB_STW_DISP_EXMI_SP2015_55c86d41 7
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_DIAG_OBD_ENG_55c86d41     8
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ENERG_DGR_DRDY_55c86d41   9
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ENSU_SFY_55c86d41         10
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ERRM_BN_U_55c86d41        11
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_FAHRGESTELLNUMMER_55c86d41 12
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_FZZSTD_55c86d41           13
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_KILOMETERSTAND_55c86d41   14
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_OFFS_QUAD_EPS_55c86d41    15
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_RELATIVZEIT_55c86d41      16
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_SECU_FAHRGESTELLNUMMER_55c86d41 17
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_SECU_RESP_55c86d41        18
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_STEA_OFFS_55c86d41        19
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_CENG_55c86d41          20
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_ENERG_GEN_55c86d41     21
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_STAB_DSC_55c86d41      22
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_SU_CLE_DRDY_DXP_55c86d41  23
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_TAR_ESTP_VIRT_FTAX_55c86d41 24
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_TAR_QTA_STRMOM_DV_55c86d41 25
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_TAR_STMOM_DV_ACT_55c86d41 26
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_VYAW_VEH_55c86d41         27
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_V_VEH_55c86d41            28
#define PduRConf_PduRDestPdu_DST_SVC_fbd80461_In                      1
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_SRC_ANFRAGE_fbd80461_In                   0
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ACLNY_MASSCNTR_55c86d41    1
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_RPM_WHL_55c86d41       2
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_A_TEMP_55c86d41            3
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CON_VEH_55c86d41           4
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CTR_DIAG_OBD_DRDY_55c86d41 5
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CTR_VIB_STW_DISP_EXMI_SP2015_55c86d41 6
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DIAG_OBD_ENG_55c86d41      7
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENERG_DGR_DRDY_55c86d41    8
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENSU_SFY_55c86d41          9
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ERRM_BN_U_55c86d41         10
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FAHRGESTELLNUMMER_55c86d41 11
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FZZSTD_55c86d41            12
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_KILOMETERSTAND_55c86d41    13
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_OFFS_QUAD_EPS_55c86d41     14
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_RELATIVZEIT_55c86d41       15
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SECU_FAHRGESTELLNUMMER_55c86d41 16
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SECU_RESP_55c86d41         17
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_STEA_OFFS_55c86d41         18
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_CENG_55c86d41           19
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_ENERG_GEN_55c86d41      20
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_STAB_DSC_55c86d41       21
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SU_CLE_DRDY_DXP_55c86d41   22
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_ESTP_VIRT_FTAX_55c86d41 23
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_QTA_STRMOM_DV_55c86d41 24
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_STMOM_DV_ACT_55c86d41  25
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_VYAW_VEH_55c86d41          26
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_V_VEH_55c86d41             27
#define PduRConf_PduRSrcPdu_SRC_SVC_fbd80461_In                       28
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_SRC_ANFRAGE_fbd80461_Out                  0
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF0              1
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF1              2
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF2              3
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF3              4
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF4              5
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF5              6
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF6              7
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF7              8
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF8              9
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xF9              10
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFA              11
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFB              12
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFC              13
#define PduRConf_PduRSrcPdu_SRC_Dcm_ECU_TRNSM_FR_32_0xFD              14
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_FORC_GRD_55c86d41      15
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_PO_EPS_55c86d41        16
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_STMOM_DV_ACT_55c86d41  17
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DBG_EPS_BS_MOD_58_BYTE_55c86d41 18
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DBG_EPS_MOD_EXT_120_BYTE_55c86d41 19
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DISP_CC_EPS_55c86d41       20
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DT_EST_55c86d41            21
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENGTORQ_EPS_55c86d41       22
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FR_DBG_EPS_55c86d41        23
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_RQ_STG_EFAN_55c86d41       24
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SECU_CHAL_55c86d41         25
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_DIAG_OBD_3_DRDY_55c86d41 26
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_EST_55c86d41            27
#define PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SU_EPS_55c86d41            28
#define PduRConf_PduRSrcPdu_SRC_SVC_fbd80461_Out                      29
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_ANFRAGE_fbd80461_Out                 0
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_FORC_GRD_55c86d41     2
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_PO_EPS_55c86d41       3
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_STMOM_DV_ACT_55c86d41 4
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_DBG_EPS_BS_MOD_58_BYTE_55c86d41 5
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_DBG_EPS_MOD_EXT_120_BYTE_55c86d41 6
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_DISP_CC_EPS_55c86d41      7
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_DT_EST_55c86d41           8
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ENGTORQ_EPS_55c86d41      9
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_FR_DBG_EPS_55c86d41       10
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_RQ_STG_EFAN_55c86d41      11
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_SECU_CHAL_55c86d41        12
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_DIAG_OBD_3_DRDY_55c86d41 13
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_EST_55c86d41           14
#define PduRConf_PduRDestPdu_DST_Fr_pduTrig_SU_EPS_55c86d41           15
#define PduRConf_PduRDestPdu_DST_SVC_fbd80461_Out                     1
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF0                   0
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF1                   1
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF2                   2
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF3                   3
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF4                   4
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF5                   5
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF6                   6
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF7                   7
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF8                   8
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xF9                   9
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xFA                   10
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xFB                   11
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xFC                   12
#define PduRConf_PduRDestPdu_DST_Dcm_BRC_FR_32_0xFD                   13
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF0             14
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF1             15
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF2             16
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF3             17
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF4             18
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF5             19
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF6             20
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF7             21
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF8             22
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xF9             23
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xFA             24
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xFB             25
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xFC             26
#define PduRConf_PduRDestPdu_DST_Dcm_GW_TRNSM_FR_254_0xFD             27
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF0                    0
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF1                    1
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF2                    2
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF3                    3
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF4                    4
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF5                    5
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF6                    6
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF7                    7
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF8                    8
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xF9                    9
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFA                    10
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFB                    11
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFC                    12
#define PduRConf_PduRSrcPdu_SRC_Dcm_BRC_FR_32_0xFD                    13
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF0              14
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF1              15
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF2              16
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF3              17
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF4              18
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF5              19
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF6              20
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF7              21
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF8              22
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xF9              23
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFA              24
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFB              25
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFC              26
#define PduRConf_PduRSrcPdu_SRC_Dcm_GW_TRNSM_FR_254_0xFD              27
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF0             0
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF1             1
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF2             2
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF3             3
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF4             4
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF5             5
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF6             6
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF7             7
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF8             8
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xF9             9
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFA             10
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFB             11
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFC             12
#define PduRConf_PduRDestPdu_DST_Dcm_ECU_TRNSM_FR_32_0xFD             13
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

