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
 *            Module: Com
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:09
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


/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA S 0342 EOF */ /* MD_Com_0342 */
/* PRQA S 0612 EOF */ /* MD_Com_0612 */
/* PRQA S 0639 EOF */ /* MD_MSR_1.1_639 */
/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 2006 EOF */ /* MD_MSR_14.7 */
/* PRQA S 3109 EOF */ /* MD_MSR_14.3 */
/* PRQA S 3453 EOF */ /* MD_CSL_3453 */
/* PRQA S 3458 EOF */ /* MD_MSR_19.4 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"

#include "Rte_Cbk.h"

#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkRxTOutFuncPtr
  \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(ComCbkRxTOutType, COM_CONST) Com_CbkRxTOutFuncPtr[17] = {
  /* Index     CbkRxTOutFuncPtr                                          Referable Keys */
  /*     0 */ Rte_COMCbkRxTOut_sigGroup_ACLNY_MASSCNTR_461c64b1    ,  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     1 */ Rte_COMCbkRxTOut_sigGroup_CON_VEH_675e7344           ,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*     2 */ Rte_COMCbkRxTOut_CTR_WARN_DIR_VIB_EPS_66c73f8f       ,  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*     3 */ Rte_COMCbkRxTOut_CTR_WARN_ILVL_VIB_EPS_66c73f8f      ,  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*     4 */ Rte_COMCbkRxTOut_CTR_WARN_PTRN_VIB_EPS_66c73f8f      ,  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*     5 */ Rte_COMCbkRxTOut_sigGroup_ENERG_DGR_DRDY_3f76efd3    ,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*     6 */ Rte_COMCbkRxTOut_ST_ENERG_FZM_e7ce1a0c               ,  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*     7 */ Rte_COMCbkRxTOut_ST_ILK_ERRM_FZM_e7ce1a0c            ,  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*     8 */ Rte_COMCbkRxTOut_MILE_KM_a6dd5496                    ,  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*     9 */ Rte_COMCbkRxTOut_sigGroup_OFFS_QUAD_EPS_cc150a52     ,  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    10 */ Rte_COMCbkRxTOut_AVL_STEA_PNI_OFFS_9678c0e9          ,  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*    11 */ Rte_COMCbkRxTOut_FACT_MO_STE_SO_DXP_59dc6376         ,  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*    12 */ Rte_COMCbkRxTOut_SU_CLU_STMOM_SFE_DXP_59dc6376       ,  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*    13 */ Rte_COMCbkRxTOut_sigGroup_TAR_QTA_STRMOM_DV_231dfb08 ,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    14 */ Rte_COMCbkRxTOut_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3  ,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*    15 */ Rte_COMCbkRxTOut_sigGroup_VYAW_VEH_fc66be94          ,  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*    16 */ Rte_COMCbkRxTOut_sigGroup_V_VEH_2fe00c20                /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueArrayBased
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueArrayBasedType, COM_CONST) Com_ConstValueArrayBased[1] = {
  /* Index     ConstValueArrayBased      Referable Keys */
  /*     0 */                 0x00U   /* [/ActiveEcuC/Com/ComConfig/NO_VECH_1_13b7b7e4InitValue, /ActiveEcuC/Com/ComConfig/NO_VECH_2_13b7b7e4InitValue, /ActiveEcuC/Com/ComConfig/NO_VECH_3_13b7b7e4InitValue, /ActiveEcuC/Com/ComConfig/NO_VECH_4_13b7b7e4InitValue, /ActiveEcuC/Com/ComConfig/NO_VECH_5_13b7b7e4InitValue, /ActiveEcuC/Com/ComConfig/NO_VECH_6_13b7b7e4InitValue, /ActiveEcuC/Com/ComConfig/NO_VECH_7_13b7b7e4InitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[4] = {
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x0FFFU,  /* [/ActiveEcuC/Com/ComConfig/TRGG_ENGTORQ_EPS_4e565a26InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_c0f3c255InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/OFFS_GRD_MID_EPS_4bf7fe20InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_3ef6286eInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/TOT_STR_EPS_f544de28InvValue] */
  /*     1 */           0xFFFFU,  /* [/ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_InInvValue, /ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_OutInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_EPS_4bf7fe20InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_IDX_EPS_4bf7fe20InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/NO_CC_EPS_8a192f9aInvValue] */
  /*     2 */           0x0000U,  /* [/ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9InitValue, /ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_InInitValue, /ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_InRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/QU_FN_FDR_d5c7d03cInitValue, /ActiveEcuC/Com/ComConfig/QU_FN_FDR_d5c7d03cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_1311692dInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_1311692dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_ERR_AMP_1311692dInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_ERR_AMP_1311692dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/AVL_PO_IDX_ICM_1a5f7888InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/AVL_PO_IDX_ICM_1a5f7888RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STMOM_DV_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STMOM_DV_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_56e1c987RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_ERR_AMP_dc9eeb12InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_ERR_AMP_dc9eeb12RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dc9eeb12InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dc9eeb12RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_COG_579a99a0InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_COG_579a99a0RxDataTimeoutSubstitutionValue] */
  /*     3 */           0x0001U   /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_InInitValue, /ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_InRxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[4] = {
  /* Index     ConstValueUInt32      Referable Keys */
  /*     0 */      0x0FFFFFFFUL,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9bInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9bRxDataTimeoutSubstitutionValue] */
  /*     1 */      0x000FFFFFUL,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9bInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_32_51_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_32_51_56e1c987RxDataTimeoutSubstitutionValue] */
  /*     2 */      0xFFFFFFFFUL,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_32_63_db9b6687InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_32_63_db9b6687RxDataTimeoutSubstitutionValue] */
  /*     3 */      0x00000000UL   /* [/ActiveEcuC/Com/ComConfig/COU_BS_RESP_d377025eInitValue, /ActiveEcuC/Com/ComConfig/COU_BS_RESP_d377025eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496InitValue, /ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/STU_RESP_d377025eInitValue, /ActiveEcuC/Com/ComConfig/STU_RESP_d377025eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/T_SEC_COU_REL_0b27fbfeInitValue, /ActiveEcuC/Com/ComConfig/T_SEC_COU_REL_0b27fbfeRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_FKTN_PRTNT_c1ae6ae9InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_FKTN_PRTNT_c1ae6ae9RxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt64
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt64
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT64)
*/ 
#define COM_START_SEC_CONST_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt64Type, COM_CONST) Com_ConstValueUInt64[2] = {
  /* Index     ConstValueUInt64           Referable Keys */
  /*     0 */  0x0000000000000000ULL,  /* [/ActiveEcuC/Com/ComConfig/STU_8_BYTE_347be560InitValue, /ActiveEcuC/Com/ComConfig/STU_8_BYTE_347be560RxDataTimeoutSubstitutionValue] */
  /*     1 */  0x000000FFFFFFFFFFULL   /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_5fff8d6bInvValue] */
};
#define COM_STOP_SEC_CONST_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[7] = {
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x01U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_dummy_39_39_579a99a0InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_dummy_39_39_579a99a0RxDataTimeoutSubstitutionValue] */
  /*     1 */            0x03U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/IDX_TORQ_SEN_4bf7fe20InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/UN_PO_EPS_4bf7fe20InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_CC_EPS_8a192f9aInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_IDC_CC_EPS_8a192f9aInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/UN_TOT_STR_EPS_f544de28InvValue] */
  /*     2 */            0xF7U,  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_ID2_d377025eInitValue, /ActiveEcuC/Com/ComConfig/SECU_RESP_ID2_d377025eRxDataTimeoutSubstitutionValue] */
  /*     3 */            0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ID_FN_RQ_STG_EFAN_862c1b6dInvValue, /ActiveEcuC/Com/ComConfig/SSS_IDENT_CHAL_5fff8d6bInvValue, /ActiveEcuC/Com/ComConfig/SSV_IDENT_CHAL_5fff8d6bInvValue, /ActiveEcuC/Com/ComConfig/TEMP_CPO_HET_MNG_862c1b6dInvValue, /ActiveEcuC/Com/ComConfig/TEMP_EX_4b857050InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_PWR_EL_EPS_COOD_c0f3c255InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CON_VEH_dummy_56_63_c1ae6ae9InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CON_VEH_dummy_56_63_c1ae6ae9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/AVL_I_ACT_EST_dcba517dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_EST_eef8e21dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_SER_STMOM_DV_ACT_eef8e21dInvValue] */
  /*     4 */            0x3FU,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_1_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_2_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_3_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_4_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_5_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_6_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_7_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_8_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_IMME_MUX_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_MAX_MUX_65e49c1bInvValue] */
  /*     5 */            0x0FU,  /* [/ActiveEcuC/Com/ComConfig/ALIV_ST_DIAG_OBD_3_DRDY_65e49c1bInvValue, /ActiveEcuC/Com/ComConfig/ID_TEMP_CPO_HET_MNG_862c1b6dInvValue, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_862c1b6dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_MASSCNTR_dummy_12_15_1311692dInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_MASSCNTR_dummy_12_15_1311692dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/ALIV_AVL_FORC_GRD_c0f3c255InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/QU_AVL_FORC_GRD_c0f3c255InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/ALIV_AVL_PO_EPS_4bf7fe20InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/QU_AVL_PO_EPS_4bf7fe20InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_dummy_12_15_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_dummy_12_15_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bfInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/ALIV_AVL_STMOM_DV_ACT_3ef6286eInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/QU_AVL_STMOM_DV_ACT_3ef6286eInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ALIV_DISP_CC_EPS_8a192f9aInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CHL_DISP_CC_EPS_8a192f9aInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/TRANF_CC_EPS_8a192f9aInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ALIV_DT_EST_dcba517dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/QU_AVL_I_ACT_EST_dcba517dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ST_CULI_EST_dcba517dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_DGR_DRDY_dummy_12_15_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_DGR_DRDY_dummy_12_15_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_28_31_db9b6687InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_28_31_db9b6687RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ALIV_ST_EST_FTAX_eef8e21dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_VIB_EPS_eef8e21dInvValue, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/ALIV_SU_EPS_f544de28InvValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_12_15_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_12_15_56e1c987RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dummy_12_15_dc9eeb12InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dummy_12_15_dc9eeb12RxDataTimeoutSubstitutionValue] */
  /*     6 */            0x00U   /* [/ActiveEcuC/Com/ComConfig/ALIV_ST_CENG_43f592b4InitValue, /ActiveEcuC/Com/ComConfig/ALIV_ST_CENG_43f592b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CTR_ERRM_BN_U_d46c15e6InitValue, /ActiveEcuC/Com/ComConfig/CTR_ERRM_BN_U_d46c15e6RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8fInitValue, /ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8fInitValue, /ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8fInitValue, /ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8fRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376InitValue, /ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/RQ_RST_OBD_DIAG_DRDY_85fd80d4InitValue, /ActiveEcuC/Com/ComConfig/RQ_RST_OBD_DIAG_DRDY_85fd80d4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SSV_IDENT_RESP_d377025eInitValue, /ActiveEcuC/Com/ComConfig/SSV_IDENT_RESP_d377025eRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_ANO_MSA_ENG_STOP_43f592b4InitValue, /ActiveEcuC/Com/ComConfig/ST_ANO_MSA_ENG_STOP_43f592b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_CENG_DRV_43f592b4InitValue, /ActiveEcuC/Com/ComConfig/ST_CENG_DRV_43f592b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0cInitValue, /ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_ENERG_SUPY_43f592b4InitValue, /ActiveEcuC/Com/ComConfig/ST_ENERG_SUPY_43f592b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0cInitValue, /ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0cRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_LDREL_GEN_3319a82aInitValue, /ActiveEcuC/Com/ComConfig/ST_LDREL_GEN_3319a82aRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_MOT_DRV_43f592b4InitValue, /ActiveEcuC/Com/ComConfig/ST_MOT_DRV_43f592b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_OBD_CYC_f0d11ff9InitValue, /ActiveEcuC/Com/ComConfig/ST_OBD_CYC_f0d11ff9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_SEP_STOR_3319a82aInitValue, /ActiveEcuC/Com/ComConfig/ST_SEP_STOR_3319a82aRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/ST_UDP_43f592b4InitValue, /ActiveEcuC/Com/ComConfig/ST_UDP_43f592b4RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376InitValue, /ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/TEMP_EX_4b857050InitValue, /ActiveEcuC/Com/ComConfig/TEMP_EX_4b857050RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ALIV_ACLNY_COG_1311692dInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ALIV_ACLNY_COG_1311692dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/CRC_ACLNY_COG_1311692dInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/CRC_ACLNY_COG_1311692dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/QU_ACLNY_COG_1311692dInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/QU_ACLNY_COG_1311692dRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/CRC_AVL_RPM_WHL_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/CRC_AVL_RPM_WHL_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bfInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bfRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ALIV_CON_VEH_c1ae6ae9InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ALIV_CON_VEH_c1ae6ae9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CRC_CON_VEH_c1ae6ae9InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CRC_CON_VEH_c1ae6ae9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_BS_PRTNT_c1ae6ae9InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_BS_PRTNT_c1ae6ae9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/QU_ST_CON_VEH_c1ae6ae9InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/QU_ST_CON_VEH_c1ae6ae9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ST_CON_VEH_c1ae6ae9InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ST_CON_VEH_c1ae6ae9RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ALIV_ENERG_DGR_DRDY_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ALIV_ENERG_DGR_DRDY_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/CRC_ENERG_DGR_DRDY_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/CRC_ENERG_DGR_DRDY_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_AVAI_ARS_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_AVAI_ARS_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_LD_SPEC_ARS_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_LD_SPEC_ARS_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_RECUP_SPEC_ARS_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_RECUP_SPEC_ARS_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_BAX_STE_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_BAX_STE_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_EPS_6d50c911InitValue, 
              /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_EPS_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/QU_DGR_AISP_ENERG_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/QU_DGR_AISP_ENERG_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/RQ_CULI_EST_SFY_6d50c911InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/RQ_CULI_EST_SFY_6d50c911RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CRC_ENSU_SFY_db9b6687InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CRC_ENSU_SFY_db9b6687RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ALIV_OFFS_QUAD_EPS_1a5f7888InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ALIV_OFFS_QUAD_EPS_1a5f7888RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/CRC_OFFS_QUAD_EPS_1a5f7888InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/CRC_OFFS_QUAD_EPS_1a5f7888RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/OFFS_QUAD_RTR_EPS_1a5f7888InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/OFFS_QUAD_RTR_EPS_1a5f7888RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ST_OFFS_QUAD_EPS_1a5f7888InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ST_OFFS_QUAD_EPS_1a5f7888RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9bInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9bInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/CRC_TAR_ESTP_VIRT_FTAX_0f46fe9bInitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/CRC_TAR_ESTP_VIRT_FTAX_0f46fe9bRxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/ALIV_TAR_QTA_STMOM_DV_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/ALIV_TAR_QTA_STMOM_DV_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CRC_TAR_QTA_STMOM_DV_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CRC_TAR_QTA_STMOM_DV_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CTR_DEAC_EPS_FNS_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CTR_DEAC_EPS_FNS_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_ASS_STMOM_FTAX_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_ASS_STMOM_FTAX_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_CTRR_STMOM_FTAX_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_CTRR_STMOM_FTAX_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_DMPNG_STMOM_FTAX_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_DMPNG_STMOM_FTAX_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_FACT_STMOM_FTAX_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_FACT_STMOM_FTAX_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_QTA_STMOM_DV_54d7ae59InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_QTA_STMOM_DV_54d7ae59RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/ALIV_TAR_STMOM_DV_ACT_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/ALIV_TAR_STMOM_DV_ACT_56e1c987RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/CRC_TAR_STMOM_DV_ACT_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/CRC_TAR_STMOM_DV_ACT_56e1c987RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_STMOM_DV_ACT_56e1c987InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_STMOM_DV_ACT_56e1c987RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/ALIV_VYAW_VEH_dc9eeb12InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/ALIV_VYAW_VEH_dc9eeb12RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/CRC_VYAW_VEH_dc9eeb12InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/CRC_VYAW_VEH_dc9eeb12RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/QU_VYAW_VEH_dc9eeb12InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/QU_VYAW_VEH_dc9eeb12RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ALIV_V_VEH_579a99a0InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ALIV_V_VEH_579a99a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/CRC_V_VEH_579a99a0InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/CRC_V_VEH_579a99a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/DVCO_VEH_579a99a0InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/DVCO_VEH_579a99a0RxDataTimeoutSubstitutionValue, 
              /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/QU_V_VEH_COG_579a99a0InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/QU_V_VEH_COG_579a99a0RxDataTimeoutSubstitutionValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ST_V_VEH_NSS_579a99a0InitValue, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ST_V_VEH_NSS_579a99a0RxDataTimeoutSubstitutionValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[13] = {
  /* Index     PduGrpVector      Referable Keys */
  /*     0 */         0x80U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*     1 */         0x40U,  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*     2 */         0x20U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*     3 */         0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*     4 */         0x04U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18, /ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*     5 */         0x00U,  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18] */
  /*     6 */         0x02U,  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18, /ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*     7 */         0x00U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*     8 */         0x01U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*     9 */         0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /*    10 */         0x10U,  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/A_TEMP_19255f18, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18, /ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18, /ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*    11 */         0x00U,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*    12 */         0x08U   /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18, /ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18, /ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                                  Description
  InitValueUsed                            TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxSigBufferArrayBasedBufferUsed          TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigBufferArrayBased
  ShdBufferUsed                            TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  ApplType                                 Application data type.
  BitLength                                Bit length of the signal or group signal.
  BitPosition                              Little endian bit position of the signal or group signal within the I-PDU.
  BufferIdx                                the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  BusAcc                                   BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                               Byte length of the signal or group signal.
  ConstValueArrayBasedInitValueEndIdx      the end index of the 0:n relation pointing to Com_ConstValueArrayBased
  ConstValueArrayBasedInitValueStartIdx    the start index of the 0:n relation pointing to Com_ConstValueArrayBased
  InvValueIdx                              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxDataTimeoutSubstitutionValueIdx        the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  RxPduInfoIdx                             the index of the 1:1 relation pointing to Com_RxPduInfo
  RxSigBufferArrayBasedBufferEndIdx        the end index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  RxSigBufferArrayBasedBufferStartIdx      the start index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  RxTOutInfoIdx                            the index of the 0:1 relation pointing to Com_RxTOutInfo
  ShdBufferIdx                             the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64
  StartByteInPduPosition                   Start Byte position of the signal or group signal within the I-PDU.
  TmpBufferIdx                             the index of the 0:1 relation pointing to Com_TmpRxShdBufferUInt8,Com_TmpRxShdBufferUInt16,Com_TmpRxShdBufferUInt32,Com_TmpRxShdBufferUInt64,Com_TmpRxShdBufferSInt8,Com_TmpRxShdBufferSInt16,Com_TmpRxShdBufferSInt32,Com_TmpRxShdBufferSInt64
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[119] = {
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ShdBufferUsed  ApplType                            BitLength  BitPosition  BufferIdx                       BusAcc                                ByteLength  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       InvValueIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferEndIdx                       RxSigBufferArrayBasedBufferStartIdx                       RxTOutInfoIdx                       ShdBufferIdx                       StartByteInPduPosition  TmpBufferIdx                             Referable Keys */
  { /*     0 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         16U,                             0U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,           0U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 0U,                                1U,                     2U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  { /*     1 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         32U,                             2U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,           0U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 0U,                                3U,                     4U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_ERR_AMP_1311692d, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  { /*     2 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                             0U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     5U,           0U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 0U,                                1U,                     1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_MASSCNTR_dummy_12_15_1311692d, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  { /*     3 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         32U,                             2U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          23U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                                3U,                     4U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9b, /ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  { /*     4 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                             4U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           0U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 0U,                                5U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ALIV_ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  { /*     5 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                             6U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                                7U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*     6 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                             8U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           4U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 1U,                                9U,                     1U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ALIV_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*     7 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         52U,                            10U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               11U,                     6U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ALIV_ENERG_DGR_DRDY_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*     8 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            12U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           9U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               13U,                     1U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  { /*     9 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            14U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          14U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 6U,                               15U,                     1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ALIV_OFFS_QUAD_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  { /*    10 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            16U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          19U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     1U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ALIV_ST_CENG_43f592b4, /ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    11 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            17U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          23U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               18U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9b, /ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  { /*    12 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            19U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                               20U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/ALIV_TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    13 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            21U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                               22U,                     1U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/ALIV_TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*    14 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            23U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          26U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                11U,                               24U,                     1U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/ALIV_VYAW_VEH_dc9eeb12, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  { /*    15 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                            25U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          27U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                12U,                               26U,                     1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ALIV_V_VEH_579a99a0, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  { /*    16 */          TRUE,                           FALSE,         FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,        8U,          0U,                             4U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     3U,           1U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_In, /ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  { /*    17 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         24U,                             5U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          14U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 6U,                                6U,                     3U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/AVL_PO_IDX_ICM_1a5f7888, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  { /*    18 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         48U,                             7U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               1U,                                                     2U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                                8U,                     6U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    19 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         64U,                             9U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               1U,                                                     2U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               10U,                     8U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    20 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         16U,                            11U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               1U,                                                     2U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               12U,                     2U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    21 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         32U,                            13U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               1U,                                                     2U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               14U,                     4U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    22 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                            27U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     5U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               28U,                     1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_dummy_12_15_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    23 */          TRUE,                           FALSE,         FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         36U,                            15U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          18U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 7U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     4U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  { /*    24 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                            29U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           9U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               30U,                     1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  { /*    25 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         56U,                            31U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     3U,           4U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 1U,                               32U,                     7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CON_VEH_dummy_56_63_c1ae6ae9, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*    26 */          TRUE,                           FALSE,         FALSE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       24U,         16U,                             0U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     3U,          17U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     2U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/COU_BS_RESP_d377025e, /ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    27 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            33U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           0U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 0U,                               34U,                     0U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/CRC_ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  { /*    28 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            35U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               36U,                     0U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/CRC_AVL_RPM_WHL_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    29 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            37U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           4U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 1U,                               38U,                     0U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CRC_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*    30 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         56U,                            39U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               40U,                     7U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/CRC_ENERG_DGR_DRDY_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    31 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            41U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           9U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               42U,                     0U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CRC_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  { /*    32 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            43U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          14U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 6U,                               44U,                     0U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/CRC_OFFS_QUAD_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  { /*    33 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            45U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          23U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               46U,                     0U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/CRC_TAR_ESTP_VIRT_FTAX_0f46fe9b, /ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  { /*    34 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            47U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                               48U,                     0U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CRC_TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    35 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            49U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                               50U,                     0U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/CRC_TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*    36 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            51U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          26U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                11U,                               52U,                     0U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/CRC_VYAW_VEH_dc9eeb12, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  { /*    37 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            53U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          27U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                12U,                               54U,                     0U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/CRC_V_VEH_579a99a0, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  { /*    38 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                            55U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           4U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 1U,                               56U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_BS_PRTNT_c1ae6ae9, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*    39 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         60U,                            57U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                               58U,                     7U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CTR_DEAC_EPS_FNS_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    40 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,          0U,                            59U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          10U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/CTR_ERRM_BN_U_d46c15e6, /ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18] */
  { /*    41 */          TRUE,                           FALSE,          TRUE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         16U,                             1U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     3U,           4U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 1U,                                2U,                     2U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_FKTN_PRTNT_c1ae6ae9, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*    42 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         54U,                            60U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           6U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 2U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     6U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  { /*    43 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         56U,                            61U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           6U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 2U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     7U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  { /*    44 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         36U,                            62U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           6U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 2U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     4U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  { /*    45 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3U,         36U,                            63U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          27U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                12U,                               64U,                     4U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/DVCO_VEH_579a99a0, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  { /*    46 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         40U,                            65U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               66U,                     5U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_AVAI_ARS_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    47 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                            67U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     5U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               68U,                     1U,                                8U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_DGR_DRDY_dummy_12_15_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    48 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         28U,                            69U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     5U,           9U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               70U,                     3U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_28_31_db9b6687, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  { /*    49 */          TRUE,                           FALSE,          TRUE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,         32U,                             3U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,           9U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                                4U,                     4U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_32_63_db9b6687, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ShdBufferUsed  ApplType                            BitLength  BitPosition  BufferIdx                       BusAcc                                ByteLength  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       InvValueIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferEndIdx                       RxSigBufferArrayBasedBufferStartIdx                       RxTOutInfoIdx                       ShdBufferIdx                       StartByteInPduPosition  TmpBufferIdx                             Referable Keys */
  { /*    50 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         48U,                            71U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                               72U,                     6U,                                7U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_ASS_STMOM_FTAX_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    51 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         32U,                            73U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                               74U,                     4U,                                8U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_CTRR_STMOM_FTAX_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    52 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         56U,                            75U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                               76U,                     7U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*    53 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         40U,                            77U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                               78U,                     5U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_DMPNG_STMOM_FTAX_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    54 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,                            79U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          22U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 8U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     2U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  { /*    55 */          TRUE,                           FALSE,         FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,          8U,                            16U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               1U,                                                     2U,           1U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     1U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_In, /ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  { /*    56 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         24U,                            80U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               81U,                     3U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_LD_SPEC_ARS_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    57 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         32U,                            82U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               83U,                     4U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_RECUP_SPEC_ARS_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    58 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,                            84U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               85U,                     2U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_BAX_STE_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    59 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                            86U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                               87U,                     0U,                                7U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_EPS_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    60 */          TRUE,                           FALSE,         FALSE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       24U,          0U,                             5U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     3U,          13U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 5U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  { /*    61 */         FALSE,                            TRUE,         FALSE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,        8U,          0U, COM_NO_BUFFERIDXOFRXACCESSINFO, COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         1U,                                                       1U,                                                         0U, COM_NO_INVVALUEIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          11U,                                                     1U,                                                       0U, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_1_13b7b7e4, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    62 */         FALSE,                            TRUE,         FALSE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,        8U,          8U, COM_NO_BUFFERIDXOFRXACCESSINFO, COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         1U,                                                       1U,                                                         0U, COM_NO_INVVALUEIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          11U,                                                     2U,                                                       1U, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     1U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_2_13b7b7e4, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    63 */         FALSE,                            TRUE,         FALSE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,        8U,         16U, COM_NO_BUFFERIDXOFRXACCESSINFO, COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         1U,                                                       1U,                                                         0U, COM_NO_INVVALUEIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          11U,                                                     3U,                                                       2U, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     2U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_3_13b7b7e4, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    64 */         FALSE,                            TRUE,         FALSE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,        8U,         24U, COM_NO_BUFFERIDXOFRXACCESSINFO, COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         1U,                                                       1U,                                                         0U, COM_NO_INVVALUEIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          11U,                                                     4U,                                                       3U, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     3U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_4_13b7b7e4, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    65 */         FALSE,                            TRUE,         FALSE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,        8U,         32U, COM_NO_BUFFERIDXOFRXACCESSINFO, COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         1U,                                                       1U,                                                         0U, COM_NO_INVVALUEIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          11U,                                                     5U,                                                       4U, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     4U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_5_13b7b7e4, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    66 */         FALSE,                            TRUE,         FALSE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,        8U,         40U, COM_NO_BUFFERIDXOFRXACCESSINFO, COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         1U,                                                       1U,                                                         0U, COM_NO_INVVALUEIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          11U,                                                     6U,                                                       5U, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     5U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_6_13b7b7e4, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    67 */         FALSE,                            TRUE,         FALSE, COM_UINT8_N_APPLTYPEOFRXACCESSINFO,        8U,         48U, COM_NO_BUFFERIDXOFRXACCESSINFO, COM_ARRAY_BASED_BUSACCOFRXACCESSINFO,         1U,                                                       1U,                                                         0U, COM_NO_INVVALUEIDXOFRXACCESSINFO, COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO,          11U,                                                     7U,                                                       6U, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     6U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_7_13b7b7e4, /ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    68 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,                            88U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          14U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 6U,                               89U,                     2U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/OFFS_QUAD_RTR_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  { /*    69 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         44U,                            90U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           0U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 0U,                               91U,                     5U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/QU_ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  { /*    70 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         88U,                            92U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               93U,                    11U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    71 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         92U,                            94U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               95U,                    11U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    72 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         80U,                            96U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               97U,                    10U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    73 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         84U,                            98U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           2U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               99U,                    10U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bf, /ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*    74 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         48U,                           100U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                              101U,                     6U,                                9U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/QU_DGR_AISP_ENERG_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    75 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         16U,                           102U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               3U,                                                     6U,           9U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                              103U,                     2U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  { /*    76 */          TRUE,                           FALSE,         FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         16U,                            17U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          21U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     2U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/QU_FN_FDR_d5c7d03c, /ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  { /*    77 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         52U,                           104U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           4U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 1U,                              105U,                     6U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/QU_ST_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*    78 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         52U,                           106U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                              107U,                     6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*    79 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         56U,                           108U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                              109U,                     7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_FACT_STMOM_FTAX_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    80 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         28U,                           110U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                              111U,                     3U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*    81 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         28U,                           112U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                              113U,                     3U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*    82 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         44U,                           114U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          26U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                11U,                              115U,                     5U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/QU_VYAW_VEH_dc9eeb12, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  { /*    83 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         32U,                           116U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          27U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                12U,                              117U,                     4U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/QU_V_VEH_COG_579a99a0, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  { /*    84 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                           118U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           8U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 3U,                              119U,                     1U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/RQ_CULI_EST_SFY_6d50c911, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*    85 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         24U,                           120U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               5U,                                                     6U,           9U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                              121U,                     3U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687, /ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  { /*    86 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,          2U,                           122U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           5U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/RQ_RST_OBD_DIAG_DRDY_85fd80d4, /ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18] */
  { /*    87 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                           123U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          17U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_ID2_d377025e, /ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    88 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          8U,                           124U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          17U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     1U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/SSV_IDENT_RESP_d377025e, /ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    89 */          TRUE,                           FALSE,         FALSE,  COM_UINT64_APPLTYPEOFRXACCESSINFO,       64U,          0U,                             0U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         8U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     0U,          16U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/STU_8_BYTE_347be560, /ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  { /*    90 */          TRUE,                           FALSE,         FALSE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       24U,         40U,                             6U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     3U,          17U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     5U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/STU_RESP_d377025e, /ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    91 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         34U,                           125U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          19U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     4U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_ANO_MSA_ENG_STOP_43f592b4, /ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    92 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         16U,                           126U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          19U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     2U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_DRV_43f592b4, /ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    93 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         48U,                           127U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           4U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 1U,                              128U,                     6U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ST_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*    94 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         16U,                           129U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          12U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 4U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     2U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0c, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  { /*    95 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,         24U,                           130U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          19U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     3U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_SUPY_43f592b4, /ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    96 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         56U,                           131U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          12U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 4U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     7U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0c, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  { /*    97 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         56U,                           132U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          20U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     7U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_LDREL_GEN_3319a82a, /ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  { /*    98 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         32U,                           133U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          19U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     4U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_MOT_DRV_43f592b4, /ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    99 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        6U,          0U,                           134U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,           7U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_OBD_CYC_f0d11ff9, /ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
    /* Index    InitValueUsed  RxSigBufferArrayBasedBufferUsed  ShdBufferUsed  ApplType                            BitLength  BitPosition  BufferIdx                       BusAcc                                ByteLength  ConstValueArrayBasedInitValueEndIdx                       ConstValueArrayBasedInitValueStartIdx                       InvValueIdx                       RxDataTimeoutSubstitutionValueIdx                       RxPduInfoIdx  RxSigBufferArrayBasedBufferEndIdx                       RxSigBufferArrayBasedBufferStartIdx                       RxTOutInfoIdx                       ShdBufferIdx                       StartByteInPduPosition  TmpBufferIdx                             Referable Keys */
  { /*   100 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                           135U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          14U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 6U,                              136U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ST_OFFS_QUAD_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  { /*   101 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2U,         40U,                           137U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          20U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     5U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_SEP_STOR_3319a82a, /ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  { /*   102 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         20U,                           138U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          19U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     2U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_UDP_43f592b4, /ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*   103 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                           139U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          27U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                12U,                              140U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ST_V_VEH_NSS_579a99a0, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  { /*   104 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,          8U,                           141U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     6U,          22U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 8U, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     1U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  { /*   105 */          TRUE,                           FALSE,          TRUE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       20U,         12U,                             7U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     1U,          23U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                                8U,                     1U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9b, /ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  { /*   106 */          TRUE,                           FALSE,          TRUE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       28U,         36U,                             9U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         3U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     0U,          23U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO,                               10U,                     4U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9b, /ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  { /*   107 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         16U,                            18U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                               19U,                     2U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*   108 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                           142U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     5U,          24U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                 9U,                              143U,                     1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*   109 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         16U,                            20U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                               21U,                     2U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*   110 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                           144U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     5U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                              145U,                     1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_12_15_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*   111 */          TRUE,                           FALSE,          TRUE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       20U,         32U,                            11U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     1U,          25U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                10U,                               12U,                     4U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_32_51_56e1c987, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*   112 */          TRUE,                           FALSE,         FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8U,          0U,                           146U,        COM_BYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO,                               3U,                                                     6U,           3U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/TEMP_EX_4b857050, /ActiveEcuC/Com/ComConfig/A_TEMP_19255f18] */
  { /*   113 */          TRUE,                           FALSE,         FALSE,  COM_UINT32_APPLTYPEOFRXACCESSINFO,       32U,          0U,                            13U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         4U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     3U,          15U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO, COM_NO_RXTOUTINFOIDXOFRXACCESSINFO, COM_NO_SHDBUFFERIDXOFRXACCESSINFO,                     0U, COM_NO_TMPBUFFERIDXOFRXACCESSINFO },  /* [/ActiveEcuC/Com/ComConfig/T_SEC_COU_REL_0b27fbfe, /ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  { /*   114 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12U,         32U,                            22U,   COM_NBITNBYTE_BUSACCOFRXACCESSINFO,         1U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          26U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                11U,                               23U,                     4U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_ERR_AMP_dc9eeb12, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  { /*   115 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         16U,                            24U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          26U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                11U,                               25U,                     2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dc9eeb12, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  { /*   116 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        4U,         12U,                           147U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     5U,          26U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                11U,                              148U,                     1U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dummy_12_15_dc9eeb12, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  { /*   117 */          TRUE,                           FALSE,          TRUE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16U,         16U,                            26U,       COM_NBYTE_BUSACCOFRXACCESSINFO,         2U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     2U,          27U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                12U,                               27U,                     2U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_COG_579a99a0, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  { /*   118 */          TRUE,                           FALSE,          TRUE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1U,         39U,                           149U,        COM_NBIT_BUSACCOFRXACCESSINFO,         0U, COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO, COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO, COM_NO_INVVALUEIDXOFRXACCESSINFO,                                                     0U,          27U, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO, COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO,                                12U,                              150U,                     4U,                                5U }   /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_dummy_39_39_579a99a0, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoGrpSigInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoGrpSigInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoGrpSigIndType, COM_CONST) Com_RxAccessInfoGrpSigInd[82] = {
  /* Index     RxAccessInfoGrpSigInd      Referable Keys */
  /*     0 */                     0U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  /*     1 */                     1U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  /*     2 */                     2U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  /*     3 */                     4U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  /*     4 */                    27U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  /*     5 */                    69U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  /*     6 */                     5U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*     7 */                    18U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*     8 */                    19U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*     9 */                    20U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    10 */                    21U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    11 */                    22U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    12 */                    28U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    13 */                    70U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    14 */                    71U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    15 */                    72U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    16 */                    73U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  /*    17 */                     6U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  /*    18 */                    25U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  /*    19 */                    29U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  /*    20 */                    38U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  /*    21 */                    41U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  /*    22 */                    77U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  /*    23 */                    93U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  /*    24 */                     7U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    25 */                    30U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    26 */                    46U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    27 */                    47U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    28 */                    56U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    29 */                    57U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    30 */                    58U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    31 */                    59U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    32 */                    74U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    33 */                    84U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  /*    34 */                     8U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  /*    35 */                    24U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  /*    36 */                    31U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  /*    37 */                    48U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  /*    38 */                    49U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  /*    39 */                    75U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  /*    40 */                    85U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  /*    41 */                     9U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  /*    42 */                    17U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  /*    43 */                    32U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  /*    44 */                    68U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  /*    45 */                   100U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  /*    46 */                     3U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  /*    47 */                    11U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  /*    48 */                    33U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  /*    49 */                   105U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  /* Index     RxAccessInfoGrpSigInd      Referable Keys */
  /*    50 */                   106U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  /*    51 */                    12U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    52 */                    34U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    53 */                    39U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    54 */                    50U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    55 */                    51U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    56 */                    53U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    57 */                    79U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    58 */                    80U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    59 */                   107U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    60 */                   108U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  /*    61 */                    13U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    62 */                    35U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    63 */                    52U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    64 */                    78U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    65 */                    81U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    66 */                   109U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    67 */                   110U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    68 */                   111U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  /*    69 */                    14U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  /*    70 */                    36U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  /*    71 */                    82U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  /*    72 */                   114U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  /*    73 */                   115U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  /*    74 */                   116U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  /*    75 */                    15U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  /*    76 */                    37U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  /*    77 */                    45U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  /*    78 */                    83U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  /*    79 */                   103U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  /*    80 */                   117U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
  /*    81 */                   118U   /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[119] = {
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */               0U,  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     1 */               1U,  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     2 */               2U,  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     3 */               4U,  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     4 */              27U,  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     5 */              69U,  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     6 */              16U,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*     7 */              55U,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*     8 */               5U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*     9 */              18U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    10 */              19U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    11 */              20U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    12 */              21U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    13 */              22U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    14 */              28U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    15 */              70U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    16 */              71U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    17 */              72U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    18 */              73U,  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    19 */             112U,  /* [/ActiveEcuC/Com/ComConfig/A_TEMP_19255f18] */
  /*    20 */               6U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    21 */              25U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    22 */              29U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    23 */              38U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    24 */              41U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    25 */              77U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    26 */              93U,  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    27 */              86U,  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18] */
  /*    28 */              42U,  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    29 */              43U,  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    30 */              44U,  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    31 */              99U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*    32 */               7U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    33 */              30U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    34 */              46U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    35 */              47U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    36 */              56U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    37 */              57U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    38 */              58U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    39 */              59U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    40 */              74U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    41 */              84U,  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    42 */               8U,  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    43 */              24U,  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    44 */              31U,  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    45 */              48U,  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    46 */              49U,  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    47 */              75U,  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    48 */              85U,  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    49 */              40U,  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*    50 */              61U,  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    51 */              62U,  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    52 */              63U,  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    53 */              64U,  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    54 */              65U,  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    55 */              66U,  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    56 */              67U,  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    57 */              94U,  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    58 */              96U,  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    59 */              60U,  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    60 */               9U,  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    61 */              17U,  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    62 */              32U,  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    63 */              68U,  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    64 */             100U,  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    65 */             113U,  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /*    66 */              89U,  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*    67 */              26U,  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*    68 */              87U,  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*    69 */              88U,  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*    70 */              90U,  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*    71 */              23U,  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*    72 */              10U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*    73 */              91U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*    74 */              92U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*    75 */              95U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*    76 */              98U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*    77 */             102U,  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*    78 */              97U,  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*    79 */             101U,  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*    80 */              76U,  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*    81 */              54U,  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*    82 */             104U,  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*    83 */               3U,  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*    84 */              11U,  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*    85 */              33U,  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*    86 */             105U,  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*    87 */             106U,  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*    88 */              12U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    89 */              34U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    90 */              39U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    91 */              50U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    92 */              51U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    93 */              53U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    94 */              79U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    95 */              80U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    96 */             107U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    97 */             108U,  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    98 */              13U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*    99 */              35U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   100 */              52U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   101 */              78U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   102 */              81U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   103 */             109U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   104 */             110U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   105 */             111U,  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   106 */              14U,  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   107 */              36U,  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   108 */              82U,  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   109 */             114U,  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   110 */             115U,  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   111 */             116U,  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   112 */              15U,  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   113 */              37U,  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   114 */              45U,  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   115 */              83U,  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   116 */             103U,  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   117 */             117U,  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   118 */             118U   /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxCbkFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxCbkFuncPtr
  \brief  Function pointer table containing configured notification and invalid notifications function pointer for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(ComRxCbkType, COM_CONST) Com_RxCbkFuncPtr[19] = {
  /* Index     RxCbkFuncPtr                                        Referable Keys */
  /*     0 */ Rte_COMCbk_ANFRAGE_ID2_fbd80461_In             ,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_InAck] */
  /*     1 */ Rte_COMCbk_CTR_WARN_DIR_VIB_EPS_66c73f8f       ,  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8fAck] */
  /*     2 */ Rte_COMCbk_CTR_WARN_ILVL_VIB_EPS_66c73f8f      ,  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8fAck] */
  /*     3 */ Rte_COMCbk_CTR_WARN_PTRN_VIB_EPS_66c73f8f      ,  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8fAck] */
  /*     4 */ Rte_COMCbk_ST_ENERG_FZM_e7ce1a0c               ,  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0cAck] */
  /*     5 */ Rte_COMCbk_ST_ILK_ERRM_FZM_e7ce1a0c            ,  /* [/ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0cAck] */
  /*     6 */ Rte_COMCbk_MILE_KM_a6dd5496                    ,  /* [/ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496Ack] */
  /*     7 */ Rte_COMCbk_T_SEC_COU_REL_0b27fbfe              ,  /* [/ActiveEcuC/Com/ComConfig/T_SEC_COU_REL_0b27fbfeAck] */
  /*     8 */ Rte_COMCbk_AVL_STEA_PNI_OFFS_9678c0e9          ,  /* [/ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9Ack] */
  /*     9 */ Rte_COMCbk_FACT_MO_STE_SO_DXP_59dc6376         ,  /* [/ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376Ack] */
  /*    10 */ Rte_COMCbk_SU_CLU_STMOM_SFE_DXP_59dc6376       ,  /* [/ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376Ack] */
  /*    11 */ Rte_COMCbk_sigGroup_ACLNY_MASSCNTR_461c64b1    ,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1Ack] */
  /*    12 */ Rte_COMCbk_sigGroup_CON_VEH_675e7344           ,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344Ack] */
  /*    13 */ Rte_COMCbk_sigGroup_ENERG_DGR_DRDY_3f76efd3    ,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3Ack] */
  /*    14 */ Rte_COMCbk_sigGroup_OFFS_QUAD_EPS_cc150a52     ,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52Ack] */
  /*    15 */ Rte_COMCbk_sigGroup_TAR_QTA_STRMOM_DV_231dfb08 ,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08Ack] */
  /*    16 */ Rte_COMCbk_sigGroup_TAR_STMOM_DV_ACT_9a7b28d3  ,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3Ack] */
  /*    17 */ Rte_COMCbk_sigGroup_VYAW_VEH_fc66be94          ,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94Ack] */
  /*    18 */ Rte_COMCbk_sigGroup_V_VEH_2fe00c20                /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20Ack] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[28] = {
    /* Index    PduGrpVectorEndIdx  PduGrpVectorStartIdx */
  { /*     0 */                 7U,                   6U },
  { /*     1 */                 5U,                   4U },
  { /*     2 */                13U,                  12U },
  { /*     3 */                11U,                  10U },
  { /*     4 */                 3U,                   2U },
  { /*     5 */                 2U,                   1U },
  { /*     6 */                 2U,                   1U },
  { /*     7 */                 1U,                   0U },
  { /*     8 */                 9U,                   7U },
  { /*     9 */                 2U,                   1U },
  { /*    10 */                 7U,                   5U },
  { /*    11 */                13U,                  12U },
  { /*    12 */                11U,                  10U },
  { /*    13 */                11U,                  10U },
  { /*    14 */                13U,                  12U },
  { /*    15 */                11U,                  10U },
  { /*    16 */                13U,                  12U },
  { /*    17 */                11U,                  10U },
  { /*    18 */                 7U,                   6U },
  { /*    19 */                 5U,                   3U },
  { /*    20 */                 7U,                   6U },
  { /*    21 */                13U,                  12U },
  { /*    22 */                13U,                  12U },
  { /*    23 */                13U,                  12U },
  { /*    24 */                13U,                  12U },
  { /*    25 */                13U,                  12U },
  { /*    26 */                13U,                  12U },
  { /*    27 */                13U,                  12U }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                    Description
  RxAccessInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  RxSigInfoUsed              TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo
  RxTOutInfoUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  RxAccessInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxAccessInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoInd
  RxDefPduBufferEndIdx       the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx     the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxSigGrpInfoInd
  RxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxSigGrpInfoInd
  RxSigInfoEndIdx            the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx          the start index of the 0:n relation pointing to Com_RxSigInfo
  RxTOutInfoIndEndIdx        the end index of the 0:n relation pointing to Com_RxTOutInfoInd
  RxTOutInfoIndStartIdx      the start index of the 0:n relation pointing to Com_RxTOutInfoInd
  Type                       Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[28] = {
    /* Index    RxAccessInfoIndUsed  RxSigInfoUsed  RxTOutInfoUsed  RxAccessInfoIndEndIdx  RxAccessInfoIndStartIdx  RxDefPduBufferEndIdx  RxDefPduBufferStartIdx  RxSigGrpInfoIndEndIdx                    RxSigGrpInfoIndStartIdx                    RxSigInfoEndIdx                    RxSigInfoStartIdx                    RxTOutInfoIndEndIdx                    RxTOutInfoIndStartIdx                    Type                              Referable Keys */
  { /*     0 */                TRUE,         FALSE,           TRUE,                    6U,                      0U,                   6U,                     0U,                                      1U,                                        0U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                    1U,                                      0U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup] */
  { /*     1 */                TRUE,          TRUE,          FALSE,                    8U,                      6U,                  14U,                     6U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                                2U,                                  0U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup2] */
  { /*     2 */                TRUE,         FALSE,          FALSE,                   19U,                      8U,                  26U,                    14U,                                      2U,                                        1U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*     3 */                TRUE,          TRUE,          FALSE,                   20U,                     19U,                  28U,                    26U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                                3U,                                  2U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/A_TEMP_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  { /*     4 */                TRUE,         FALSE,           TRUE,                   27U,                     20U,                  36U,                    28U,                                      3U,                                        2U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                    2U,                                      1U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup5] */
  { /*     5 */                TRUE,          TRUE,          FALSE,                   28U,                     27U,                  38U,                    36U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                                4U,                                  3U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup6] */
  { /*     6 */                TRUE,          TRUE,           TRUE,                   31U,                     28U,                  46U,                    38U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                                7U,                                  4U,                                    3U,                                      2U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup6] */
  { /*     7 */                TRUE,          TRUE,          FALSE,                   32U,                     31U,                  53U,                    46U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                                8U,                                  7U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup7] */
  { /*     8 */                TRUE,         FALSE,           TRUE,                   42U,                     32U,                  61U,                    53U,                                      4U,                                        3U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                    4U,                                      3U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup8] */
  { /*     9 */                TRUE,         FALSE,          FALSE,                   49U,                     42U,                  69U,                    61U,                                      5U,                                        4U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup6] */
  { /*    10 */                TRUE,          TRUE,          FALSE,                   50U,                     49U,                  71U,                    69U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                                9U,                                  8U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup9] */
  { /*    11 */                TRUE,          TRUE,          FALSE,                   57U,                     50U,                  78U,                    71U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               16U,                                  9U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    12 */                TRUE,          TRUE,           TRUE,                   59U,                     57U,                  86U,                    78U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               18U,                                 16U,                                    5U,                                      4U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  { /*    13 */                TRUE,          TRUE,           TRUE,                   60U,                     59U,                  94U,                    86U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               19U,                                 18U,                                    6U,                                      5U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  { /*    14 */                TRUE,         FALSE,           TRUE,                   65U,                     60U,                  99U,                    94U,                                      6U,                                        5U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                    7U,                                      6U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    15 */                TRUE,          TRUE,          FALSE,                   66U,                     65U,                 105U,                    99U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               20U,                                 19U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  { /*    16 */                TRUE,          TRUE,          FALSE,                   67U,                     66U,                 113U,                   105U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               21U,                                 20U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    17 */                TRUE,          TRUE,          FALSE,                   71U,                     67U,                 121U,                   113U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               25U,                                 21U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  { /*    18 */                TRUE,          TRUE,           TRUE,                   72U,                     71U,                 129U,                   121U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               26U,                                 25U,                                    8U,                                      7U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup] */
  { /*    19 */                TRUE,          TRUE,          FALSE,                   78U,                     72U,                 137U,                   129U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               32U,                                 26U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup10] */
  { /*    20 */                TRUE,          TRUE,          FALSE,                   80U,                     78U,                 145U,                   137U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               34U,                                 32U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup] */
  { /*    21 */                TRUE,          TRUE,          FALSE,                   81U,                     80U,                 153U,                   145U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               35U,                                 34U, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    22 */                TRUE,          TRUE,           TRUE,                   83U,                     81U,                 161U,                   153U, COM_NO_RXSIGGRPINFOINDENDIDXOFRXPDUINFO, COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO,                               37U,                                 35U,                                    9U,                                      8U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    23 */                TRUE,         FALSE,          FALSE,                   88U,                     83U,                 169U,                   161U,                                      7U,                                        6U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO, COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    24 */                TRUE,         FALSE,           TRUE,                   98U,                     88U,                 177U,                   169U,                                      8U,                                        7U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                   10U,                                      9U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    25 */                TRUE,         FALSE,           TRUE,                  106U,                     98U,                 185U,                   177U,                                      9U,                                        8U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                   11U,                                     10U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    26 */                TRUE,         FALSE,           TRUE,                  112U,                    106U,                 191U,                   185U,                                     10U,                                        9U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                   12U,                                     11U, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  { /*    27 */                TRUE,         FALSE,           TRUE,                  119U,                    112U,                 196U,                   191U,                                     11U,                                       10U, COM_NO_RXSIGINFOENDIDXOFRXPDUINFO, COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO,                                   13U,                                     12U, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigGrpInfo
  \brief  Contains all relevant information for Rx signal groups.
  \details
  Element                          Description
  InvEvent                         Boolean flag indicating if any invalid action is configured for the signal group.
  RxTOutInfoUsed                   TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  ShdBufferRequired            
  RxAccessInfoGrpSigIndEndIdx      the end index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd
  RxAccessInfoGrpSigIndStartIdx    the start index of the 0:n relation pointing to Com_RxAccessInfoGrpSigInd
  RxCbkFuncPtrAckIdx               the index of the 0:1 relation pointing to Com_RxCbkFuncPtr
  RxPduInfoIdx                     the index of the 1:1 relation pointing to Com_RxPduInfo
  RxTOutInfoIdx                    the index of the 0:1 relation pointing to Com_RxTOutInfo
  StartBytePosition                Least significant byte position of first group signal within the ComIPdu.
  ValidDlc                         Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxSigGrpInfoType, COM_CONST) Com_RxSigGrpInfo[11] = {
    /* Index    InvEvent  RxTOutInfoUsed  ShdBufferRequired  RxAccessInfoGrpSigIndEndIdx  RxAccessInfoGrpSigIndStartIdx  RxCbkFuncPtrAckIdx                       RxPduInfoIdx  RxTOutInfoIdx                       StartBytePosition  ValidDlc        Referable Keys */
  { /*     0 */    FALSE,           TRUE,              TRUE,                          6U,                            0U,                                     11U,           0U,                                 0U,               0UL,       6U },  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1] */
  { /*     1 */     TRUE,          FALSE,              TRUE,                         17U,                            6U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO,           2U, COM_NO_RXTOUTINFOIDXOFRXSIGGRPINFO,               0UL,      12U },  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07] */
  { /*     2 */    FALSE,           TRUE,              TRUE,                         24U,                           17U,                                     12U,           4U,                                 1U,               0UL,       8U },  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344] */
  { /*     3 */    FALSE,           TRUE,              TRUE,                         34U,                           24U,                                     13U,           8U,                                 3U,               0UL,       8U },  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3] */
  { /*     4 */     TRUE,          FALSE,              TRUE,                         41U,                           34U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO,           9U, COM_NO_RXTOUTINFOIDXOFRXSIGGRPINFO,               0UL,       8U },  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36] */
  { /*     5 */    FALSE,           TRUE,              TRUE,                         46U,                           41U,                                     14U,          14U,                                 6U,               0UL,       5U },  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52] */
  { /*     6 */    FALSE,          FALSE,              TRUE,                         51U,                           46U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO,          23U, COM_NO_RXTOUTINFOIDXOFRXSIGGRPINFO,               0UL,       8U },  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c] */
  { /*     7 */    FALSE,           TRUE,              TRUE,                         61U,                           51U,                                     15U,          24U,                                 9U,               0UL,       8U },  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08] */
  { /*     8 */    FALSE,           TRUE,              TRUE,                         69U,                           61U,                                     16U,          25U,                                10U,               0UL,       8U },  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3] */
  { /*     9 */    FALSE,           TRUE,              TRUE,                         75U,                           69U,                                     17U,          26U,                                11U,               0UL,       6U },  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94] */
  { /*    10 */    FALSE,           TRUE,              TRUE,                         82U,                           75U,                                     18U,          27U,                                12U,               0UL,       5U }   /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element               Description
  RxAccessInfoIdx       the index of the 1:1 relation pointing to Com_RxAccessInfo
  RxCbkFuncPtrAckIdx    the index of the 0:1 relation pointing to Com_RxCbkFuncPtr
  RxTOutInfoIdx         the index of the 0:1 relation pointing to Com_RxTOutInfo
  SignalProcessing  
  ValidDlc              Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[37] = {
    /* Index    RxAccessInfoIdx  RxCbkFuncPtrAckIdx                    RxTOutInfoIdx                    SignalProcessing                          ValidDlc        Referable Keys */
  { /*     0 */             16U,                                   0U, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  { /*     1 */             55U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  { /*     2 */            112U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/A_TEMP_19255f18] */
  { /*     3 */             86U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18] */
  { /*     4 */             42U,                                   1U,                              2U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  { /*     5 */             43U,                                   2U,                              2U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  { /*     6 */             44U,                                   3U,                              2U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  { /*     7 */             99U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  { /*     8 */             40U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18] */
  { /*     9 */             61U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    10 */             62U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    11 */             63U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    12 */             64U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    13 */             65U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    14 */             66U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    15 */             67U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7U },  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  { /*    16 */             94U,                                   4U,                              4U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  { /*    17 */             96U,                                   5U,                              4U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  { /*    18 */             60U,                                   6U,                              5U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  { /*    19 */            113U,                                   7U, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  { /*    20 */             89U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  { /*    21 */             26U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    22 */             87U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1U },  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    23 */             88U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    24 */             90U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  { /*    25 */             23U,                                   8U,                              7U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  { /*    26 */             10U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    27 */             91U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    28 */             92U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    29 */             95U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    30 */             98U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5U },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    31 */            102U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  { /*    32 */             97U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8U },  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  { /*    33 */            101U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6U },  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  { /*    34 */             76U, COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO, COM_NO_RXTOUTINFOIDXOFRXSIGINFO, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4U },  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  { /*    35 */             54U,                                   9U,                              8U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3U },  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  { /*    36 */            104U,                                  10U,                              8U, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2U }   /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutInfo
  \brief  Contains all relevant information for signal based and I-PDu based Rx deadline monitoring.
  \details
  Element                        Description
  Factor                         Deadline monitoring timeout factor.
  CbkRxTOutFuncPtrIndEndIdx      the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  CbkRxTOutFuncPtrIndStartIdx    the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd
  FirstFactor                    Timeout factor for first deadline monitoring.
  RxPduInfoIdx                   the index of the 1:1 relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_RxTOutInfoType, COM_CONST) Com_RxTOutInfo[13] = {
    /* Index    Factor  CbkRxTOutFuncPtrIndEndIdx  CbkRxTOutFuncPtrIndStartIdx  FirstFactor  RxPduInfoIdx        Referable Keys */
  { /*     0 */    4UL,                        1U,                          0U,         0UL,           0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18PduBased] */
  { /*     1 */   23UL,                        2U,                          1U,         0UL,           4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18PduBased] */
  { /*     2 */  111UL,                        5U,                          2U,         0UL,           6U },  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18PduBased, /ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8f] */
  { /*     3 */    4UL,                        6U,                          5U,         0UL,           8U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18PduBased] */
  { /*     4 */ 4201UL,                        8U,                          6U,         0UL,          12U },  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0c, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18PduBased, /ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0c] */
  { /*     5 */ 2201UL,                        9U,                          8U,         0UL,          13U },  /* [/ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18PduBased] */
  { /*     6 */  221UL,                       10U,                          9U,         0UL,          14U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18PduBased] */
  { /*     7 */   23UL,                       11U,                         10U,         0UL,          18U },  /* [/ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18PduBased] */
  { /*     8 */   10UL,                       13U,                         11U,         0UL,          22U },  /* [/ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18PduBased, /ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376] */
  { /*     9 */    4UL,                       14U,                         13U,         0UL,          24U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18PduBased] */
  { /*    10 */    4UL,                       15U,                         14U,         0UL,          25U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18PduBased] */
  { /*    11 */    4UL,                       16U,                         15U,         0UL,          26U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18PduBased] */
  { /*    12 */    5UL,                       17U,                         16U,         0UL,          27U }   /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18PduBased] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterInitValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterInitValueUInt16
  \brief  Contains the initial values used for initialization of the old value to evaluate the filter algorithm. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxFilterInitValueUInt16Type, COM_CONST) Com_TxFilterInitValueUInt16[1] = {
  /* Index     TxFilterInitValueUInt16      Referable Keys */
  /*     0 */                  0x0000U   /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/NO_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterInitValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterInitValueUInt8
  \brief  Contains the initial values used for initialization of the old value to evaluate the filter algorithm. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxFilterInitValueUInt8Type, COM_CONST) Com_TxFilterInitValueUInt8[20] = {
  /* Index     TxFilterInitValueUInt8      Referable Keys */
  /*     0 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/ALIV_ST_DIAG_OBD_3_DRDY_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     1 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ALIV_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*     2 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CHL_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*     3 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/CRC_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*     4 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_1_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     5 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_2_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     6 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_3_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     7 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_4_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     8 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_5_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     9 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_6_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    10 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_7_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    11 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_8_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    12 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_EST_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*    13 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_VIB_EPS_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*    14 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_SER_STMOM_DV_ACT_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*    15 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*    16 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_IMME_MUX_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    17 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_MAX_MUX_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    18 */                   0x00U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_IDC_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*    19 */                   0x00U   /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/TRANF_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element                                Description
  TxModeTrueUsed                         TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxModeTrue
  MinimumDelay                           Minimum delay factor of the Tx I-PDU.
  TxModeTrueIdx                          the index of the 0:1 relation pointing to Com_TxModeTrue
  TxSigInfoFilterInitValueIndEndIdx      the end index of the 0:n relation pointing to Com_TxSigInfoFilterInitValueInd
  TxSigInfoFilterInitValueIndStartIdx    the start index of the 0:n relation pointing to Com_TxSigInfoFilterInitValueInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[14] = {
    /* Index    TxModeTrueUsed  MinimumDelay  TxModeTrueIdx  TxSigInfoFilterInitValueIndEndIdx                     TxSigInfoFilterInitValueIndStartIdx                           Referable Keys */
  { /*     0 */           TRUE,         101U,            7U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  { /*     1 */           TRUE,           0U,            6U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  { /*     2 */           TRUE,           0U,            6U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  { /*     3 */           TRUE,           0U,            6U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18] */
  { /*     4 */           TRUE,           0U,            5U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*     5 */           TRUE,           0U,            4U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  { /*     6 */           TRUE,          13U,            3U,                                                   5U,                                                     0U },  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  { /*     7 */           TRUE,           0U,            6U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  { /*     8 */           TRUE,           0U,            6U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  { /*     9 */           TRUE,           0U,            2U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  { /*    10 */           TRUE,          11U,            7U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO },  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  { /*    11 */           TRUE,          33U,            7U,                                                  16U,                                                     5U },  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  { /*    12 */           TRUE,          11U,            1U,                                                  21U,                                                    16U },  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  { /*    13 */           TRUE,         101U,            0U, COM_NO_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO, COM_NO_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO }   /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
  Direct        TRUE if transmission mode contains a direct part.
  RepCnt        Repetition count for replication of transmission requests plus one initial transmit.
  RepPeriod     Repetition period factor for replication of transmission requests.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[8] = {
    /* Index    TimePeriod  Direct  RepCnt  RepPeriod        Referable Keys */
  { /*     0 */      1000U,   TRUE,     3U,      100U },  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  { /*     1 */       100U,   TRUE,     0U,        0U },  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  { /*     2 */       200U,  FALSE,     0U,        0U },  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  { /*     3 */        64U,   TRUE,     0U,        0U },  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  { /*     4 */         1U,  FALSE,     0U,        0U },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  { /*     5 */         4U,  FALSE,     0U,        0U },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*     6 */         2U,  FALSE,     0U,        0U },  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  { /*     7 */         0U,   TRUE,     0U,        0U }   /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[14] = {
    /* Index    PduGrpVectorEndIdx  PduGrpVectorStartIdx */
  { /*     0 */                13U,                  11U },
  { /*     1 */                11U,                   9U },
  { /*     2 */                11U,                   9U },
  { /*     3 */                11U,                   9U },
  { /*     4 */                11U,                   9U },
  { /*     5 */                11U,                   9U },
  { /*     6 */                11U,                   9U },
  { /*     7 */                11U,                   9U },
  { /*     8 */                11U,                   9U },
  { /*     9 */                11U,                   9U },
  { /*    10 */                 9U,                   8U },
  { /*    11 */                11U,                   9U },
  { /*    12 */                11U,                   9U },
  { /*    13 */                11U,                   9U }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                    Description
  TxPduInitValueUsed         TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  ExternalId                 External ID used to call PduR_ComTransmit().
  MetaDataLength             Length of MetaData.
  TxBufferLength             the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx       the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx     the start index of the 0:n relation pointing to Com_TxPduInitValue
  TxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd
  TxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[14] = {
    /* Index    TxPduInitValueUsed  ExternalId                                                            MetaDataLength  TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx  TxSigGrpInfoIndEndIdx                    TxSigGrpInfoIndStartIdx                          Referable Keys */
  { /*     0 */               TRUE,                         PduRConf_PduRSrcPdu_SRC_ANFRAGE_fbd80461_Out,             0U,             8U,                   8U,                     0U, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  { /*     1 */               TRUE,             PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_FORC_GRD_55c86d41,             0U,             5U,                  13U,                     8U,                                      1U,                                        0U },  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     2 */               TRUE,               PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_PO_EPS_55c86d41,             0U,             8U,                  21U,                    13U,                                      2U,                                        1U },  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     3 */               TRUE,         PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_STMOM_DV_ACT_55c86d41,             0U,             4U,                  25U,                    21U,                                      3U,                                        2U },  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     4 */               TRUE,   PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DBG_EPS_BS_MOD_58_BYTE_55c86d41,             0U,            58U,                  83U,                    25U, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     5 */               TRUE, PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DBG_EPS_MOD_EXT_120_BYTE_55c86d41,             0U,            58U,                 141U,                    83U, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     6 */               TRUE,              PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DISP_CC_EPS_55c86d41,             0U,             5U,                 146U,                   141U,                                      4U,                                        3U },  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     7 */               TRUE,                   PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DT_EST_55c86d41,             0U,            16U,                 162U,                   146U,                                      5U,                                        4U },  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     8 */               TRUE,              PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENGTORQ_EPS_55c86d41,             0U,             8U,                 170U,                   162U, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*     9 */               TRUE,              PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_RQ_STG_EFAN_55c86d41,             0U,             8U,                 178U,                   170U, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*    10 */               TRUE,                PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SECU_CHAL_55c86d41,             0U,             8U,                 186U,                   178U, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  { /*    11 */               TRUE,       PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_DIAG_OBD_3_DRDY_55c86d41,             0U,             8U,                 194U,                   186U, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*    12 */               TRUE,                   PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_EST_55c86d41,             0U,             5U,                 199U,                   194U,                                      6U,                                        5U },  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  { /*    13 */               TRUE,                   PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SU_EPS_55c86d41,             0U,             8U,                 207U,                   199U,                                      7U,                                        6U }   /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[207] = {
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x01U,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     1 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     2 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     3 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     4 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     5 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     6 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     7 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     8 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  /*     9 */           0xF0U,  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  /*    10 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  /*    11 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  /*    12 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  /*    13 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    14 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    15 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    16 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    17 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    18 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    19 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    20 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  /*    21 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18] */
  /*    22 */           0xF0U,  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18] */
  /*    23 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18] */
  /*    24 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18] */
  /*    25 */           0x01U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    26 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    27 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    28 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    29 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    30 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    31 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    32 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    33 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    34 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    35 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    36 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    37 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    38 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    39 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    40 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    41 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    42 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    43 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    44 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    45 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    46 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    47 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    48 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    49 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /* Index     TxPduInitValue      Referable Keys */
  /*    50 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    51 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    52 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    53 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    54 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    55 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    56 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    57 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    58 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    59 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    60 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    61 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    62 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    63 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    64 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    65 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    66 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    67 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    68 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    69 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    70 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    71 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    72 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    73 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    74 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    75 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    76 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    77 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    78 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    79 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    80 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    81 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    82 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    83 */           0x02U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    84 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    85 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    86 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    87 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    88 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    89 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    90 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    91 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    92 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    93 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    94 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    95 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    96 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    97 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    98 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    99 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   100 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   101 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   102 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   103 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   104 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   105 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   106 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   107 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   108 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   109 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   110 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   111 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   112 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   113 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   114 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   115 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   116 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   117 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   118 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   119 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   120 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   121 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   122 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   123 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   124 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   125 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   126 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   127 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   128 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   129 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   130 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   131 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   132 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   133 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   134 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   135 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   136 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   137 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   138 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   139 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   140 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   141 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*   142 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*   143 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*   144 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*   145 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*   146 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   147 */           0xF0U,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   148 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   149 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   150 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   151 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   152 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   153 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   154 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   155 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   156 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   157 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   158 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   159 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   160 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   161 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  /*   162 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   163 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   164 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   165 */           0xF0U,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   166 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   167 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   168 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   169 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   170 */           0x15U,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   171 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   172 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   173 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   174 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   175 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   176 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   177 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   178 */           0xF8U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   179 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   180 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   181 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   182 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   183 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   184 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   185 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  /*   186 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   187 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   188 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   189 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   190 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   191 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   192 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   193 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*   194 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*   195 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*   196 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*   197 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*   198 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*   199 */           0x00U,  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   200 */           0xC0U,  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /*   201 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /*   202 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /*   203 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /*   204 */           0xFFU,  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /*   205 */           0x0FU,  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  /*   206 */           0x00U   /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpInfo
  \brief  Contains all relevant information for Tx Signal Groups.
  \details
  Element                           Description
  TxBufferEndIdx                    the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx                  the start index of the 0:n relation pointing to Com_TxBuffer
  TxSigGrpMaskUsed                  TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask
  TransferProperty              
  TxBufferSigGrpInTxIPDUEndIdx      the end index of the 1:n relation pointing to Com_TxBuffer
  TxBufferSigGrpInTxIPDUStartIdx    the start index of the 1:n relation pointing to Com_TxBuffer
  TxPduInfoIdx                      the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigInfoInvValueIndEndIdx        the end index of the 0:n relation pointing to Com_TxSigInfoInvValueInd
  TxSigInfoInvValueIndStartIdx      the start index of the 0:n relation pointing to Com_TxSigInfoInvValueInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigGrpInfoType, COM_CONST) Com_TxSigGrpInfo[7] = {
    /* Index    TxBufferEndIdx  TxBufferStartIdx  TxSigGrpMaskUsed  TransferProperty                            TxBufferSigGrpInTxIPDUEndIdx  TxBufferSigGrpInTxIPDUStartIdx  TxPduInfoIdx  TxSigInfoInvValueIndEndIdx  TxSigInfoInvValueIndStartIdx        Referable Keys */
  { /*     0 */           212U,             207U,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                          13U,                             8U,           1U,                         4U,                           0U },  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/CRC_AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_dummy_12_15_c0f3c255, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_PWR_EL_EPS_COOD_c0f3c255, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/ALIV_AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/QU_AVL_FORC_GRD_c0f3c255] */
  { /*     1 */           220U,             212U,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                          21U,                            13U,           2U,                        11U,                           4U },  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/IDX_TORQ_SEN_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/CRC_AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/OFFS_GRD_MID_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_IDX_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/QU_AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/ALIV_AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/UN_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_EPS_4bf7fe20] */
  { /*     2 */           224U,             220U,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                          25U,                            21U,           3U,                        14U,                          11U },  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_dummy_12_15_3ef6286e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/QU_AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/CRC_AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/ALIV_AVL_STMOM_DV_ACT_3ef6286e] */
  { /*     3 */           229U,             224U,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                         146U,                           141U,           6U,                        20U,                          14U },  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_IDC_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/NO_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/TRANF_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ALIV_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CRC_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CHL_DISP_CC_EPS_8a192f9a] */
  { /*     4 */           245U,             229U,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                         162U,                           146U,           7U,                        24U,                          20U },  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/QU_AVL_I_ACT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/AVL_I_ACT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_16_47_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ALIV_DT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_12_15_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/CRC_DT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ST_CULI_EST_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_64_95_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_96_127_dcba517d] */
  { /*     5 */           250U,             245U,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                         199U,                           194U,          12U,                        28U,                          24U },  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ALIV_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_EST_eef8e21d, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ST_EST_dummy_16_23_eef8e21d, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_VIB_EPS_eef8e21d, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_SER_STMOM_DV_ACT_eef8e21d, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/CRC_ST_EST_FTAX_eef8e21d] */
  { /*     6 */           258U,             250U,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                         207U,                           199U,          13U,                        31U,                          28U }   /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/TOT_STR_EPS_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/UN_TOT_STR_EPS_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_20_51_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/ALIV_SU_EPS_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_14_19_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/CRC_SU_EPS_f544de28] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpMask
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpMask
  \brief  Signal group mask needed to copy interlaced signal groups to the Tx PDU buffer.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigGrpMaskType, COM_CONST) Com_TxSigGrpMask[16] = {
  /* Index     TxSigGrpMask      Referable Keys */
  /*     0 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2] */
  /*     1 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2] */
  /*     2 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2] */
  /*     3 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2] */
  /*     4 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16] */
  /*     5 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6] */
  /*     6 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6] */
  /*     7 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6] */
  /*     8 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
  /*     9 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
  /*    10 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
  /*    11 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
  /*    12 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
  /*    13 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
  /*    14 */         0xFFU,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
  /*    15 */         0xFFU   /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  OnChangeUsed              TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_FilterInfo_UInt8,Com_FilterInfo_SInt8,Com_FilterInfo_UInt16,Com_FilterInfo_SInt16,Com_FilterInfo_UInt32,Com_FilterInfo_SInt32,Com_FilterInfo_UInt64,Com_FilterInfo_SInt64,Com_FilterInfo_UInt8_N
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  FilterInitValueIdx        the index of the 0:1 relation pointing to Com_TxFilterInitValueUInt8,Com_TxFilterInitValueUInt16,Com_TxFilterInitValueUInt32,Com_TxFilterInitValueUInt64,Com_TxFilterInitValueSInt8,Com_TxFilterInitValueSInt16,Com_TxFilterInitValueSInt32,Com_TxFilterInitValueSInt64
  InvValueIdx               the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64
  OnChangeIdx               the index of the 0:1 relation pointing to Com_FilterInfo_UInt8,Com_FilterInfo_SInt8,Com_FilterInfo_UInt16,Com_FilterInfo_SInt16,Com_FilterInfo_UInt32,Com_FilterInfo_SInt32,Com_FilterInfo_UInt64,Com_FilterInfo_SInt64,Com_FilterInfo_UInt8_N
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigGrpInfoIdx           the index of the 0:1 relation pointing to Com_TxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[87] = {
    /* Index    TxBufferEndIdx  TxBufferStartIdx  OnChangeUsed  ApplType                        BitLength  BitPosition  BusAcc                           ByteLength  FilterInitValueIdx                    InvValueIdx                    OnChangeIdx                    StartByteInPduPosition  TxPduInfoIdx  TxSigGrpInfoIdx                          Referable Keys */
  { /*     0 */           209U,             208U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/ALIV_AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  { /*     1 */           214U,             213U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/ALIV_AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  { /*     2 */           222U,             221U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           3U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/ALIV_AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2InvValue] */
  { /*     3 */           226U,             225U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ALIV_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue] */
  { /*     4 */           231U,             230U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ALIV_DT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  { /*     5 */           187U,             186U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          0U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                   0U,                            5U,                            0U,                     0U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ALIV_ST_DIAG_OBD_3_DRDY_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*     6 */           247U,             246U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                   1U,                            5U,                            0U,                     1U,          12U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ALIV_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  { /*     7 */           257U,             256U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         52U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     6U,          13U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/ALIV_SU_EPS_f544de28, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6InvValue] */
  { /*     8 */             1U,               0U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           0U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_Out, /ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  { /*     9 */           211U,             209U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       12U,         16U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            0U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  { /*    10 */           209U,             208U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_dummy_12_15_c0f3c255, /ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  { /*    11 */           236U,             235U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         48U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            3U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     6U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/AVL_I_ACT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  { /*    12 */           216U,             214U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         16U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            1U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  { /*    13 */           218U,             216U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         32U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            1U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     4U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_IDX_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  { /*    14 */           212U,             211U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         32U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            3U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     4U,           1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_PWR_EL_EPS_COOD_c0f3c255, /ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  { /*    15 */           224U,             222U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       12U,         16U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            0U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           3U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2InvValue] */
  { /*    16 */           222U,             221U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           3U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_dummy_12_15_3ef6286e, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18] */
  { /*    17 */            31U,              29U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         32U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     4U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/BATT_VLTG_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    18 */           226U,             225U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                   2U,                            5U,                            0U,                     1U,           6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CHL_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  { /*    19 */           208U,             207U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/CRC_AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18] */
  { /*    20 */           213U,             212U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/CRC_AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18] */
  { /*    21 */           221U,             220U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           3U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/CRC_AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18] */
  { /*    22 */           225U,             224U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CRC_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  { /*    23 */           230U,             229U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/CRC_DT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  { /*    24 */           246U,             245U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U,                                   3U, COM_NO_INVVALUEIDXOFTXSIGINFO,                            0U,                     0U,          12U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/CRC_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  { /*    25 */           258U,             257U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         56U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     7U,          13U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/CRC_SU_EPS_f544de28, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  { /*    26 */            26U,              25U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_ID2_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    27 */            85U,              84U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          8U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           5U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_58e47270, /ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  { /*    28 */            84U,              83U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           5U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_ID2_58e47270, /ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  { /*    29 */           189U,             188U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         16U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                   4U,                            4U,                            0U,                     2U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_1_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    30 */           190U,             188U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         22U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         0U,                                   5U,                            4U,                            0U,                     2U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_2_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    31 */           191U,             189U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         28U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         0U,                                   6U,                            4U,                            0U,                     3U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_3_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    32 */           191U,             190U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         34U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                   7U,                            4U,                            0U,                     4U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_4_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    33 */           192U,             191U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         40U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                   8U,                            4U,                            0U,                     5U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_5_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    34 */           193U,             191U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         46U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         0U,                                   9U,                            4U,                            0U,                     5U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_6_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    35 */           194U,             192U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         52U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         0U,                                  10U,                            4U,                            0U,                     6U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_7_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    36 */           194U,             193U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         58U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                  11U,                            4U,                            0U,                     7U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_8_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    37 */           231U,             230U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_12_15_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  { /*    38 */           235U,             231U,        FALSE, COM_UINT32_APPLTYPEOFTXSIGINFO,       32U,         16U,     COM_NBYTE_BUSACCOFTXSIGINFO,         4U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_16_47_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  { /*    39 */           241U,             237U,        FALSE, COM_UINT32_APPLTYPEOFTXSIGINFO,       32U,         64U,     COM_NBYTE_BUSACCOFTXSIGINFO,         4U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     8U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_64_95_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  { /*    40 */           245U,             241U,        FALSE, COM_UINT32_APPLTYPEOFTXSIGINFO,       32U,         96U,     COM_NBYTE_BUSACCOFTXSIGINFO,         4U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    12U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_96_127_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18] */
  { /*    41 */            41U,              40U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,        120U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    15U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ECU_TEMP_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    42 */            34U,              31U,        FALSE, COM_UINT32_APPLTYPEOFTXSIGINFO,       24U,         48U,     COM_NBYTE_BUSACCOFTXSIGINFO,         3U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     6U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ESTIMD_PEAK_MOT_CURR_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    43 */           220U,             219U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         60U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            1U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     7U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/IDX_TORQ_SEN_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  { /*    44 */             3U,               1U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,          8U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            1U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           0U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_Out, /ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  { /*    45 */           172U,             171U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          8U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            3U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           9U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ID_FN_RQ_STG_EFAN_862c1b6d, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  { /*    46 */           173U,             172U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         20U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           9U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ID_TEMP_CPO_HET_MNG_862c1b6d, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  { /*    47 */            42U,              41U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,        128U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    16U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/MOT_FET_TEMP_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    48 */            43U,              42U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,        136U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    17U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/MOT_MAG_TEMP_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    49 */            47U,              45U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,        160U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    20U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/MOT_TQ_CMD_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
    /* Index    TxBufferEndIdx  TxBufferStartIdx  OnChangeUsed  ApplType                        BitLength  BitPosition  BusAcc                           ByteLength  FilterInitValueIdx                    InvValueIdx                    OnChangeIdx                    StartByteInPduPosition  TxPduInfoIdx  TxSigGrpInfoIdx                          Referable Keys */
  { /*    50 */            38U,              36U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         88U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    11U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/MOT_TQ_CMD_LIMD_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    51 */            36U,              34U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         72U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     9U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/MOT_VEL_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    52 */            45U,              43U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,        144U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    18U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/MOT_WIDG_TEMP_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    53 */           228U,             226U,         TRUE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         16U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U,                                   0U,                            1U,                            0U,                     2U,           6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/NO_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  { /*    54 */           220U,             218U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       12U,         48U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            0U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     6U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/OFFS_GRD_MID_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  { /*    55 */            39U,              38U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,        104U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    13U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/PRIM_HW_TQ_SNSR_VLTG_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    56 */           211U,             210U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         28U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     3U,           1U,                                0U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/QU_AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  { /*    57 */           237U,             236U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         60U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     7U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/QU_AVL_I_ACT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  { /*    58 */           214U,             213U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/QU_AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  { /*    59 */           224U,             223U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         28U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     3U,           3U,                                2U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/QU_AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2InvValue] */
  { /*    60 */           250U,             249U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         32U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U,                                  12U,                            3U,                            0U,                     4U,          12U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_EST_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  { /*    61 */           247U,             246U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                  13U,                            5U,                            0U,                     1U,          12U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_VIB_EPS_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  { /*    62 */           249U,             248U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         24U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U,                                  14U,                            3U,                            0U,                     3U,          12U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_SER_STMOM_DV_ACT_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  { /*    63 */           173U,             172U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         16U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           9U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_862c1b6d, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  { /*    64 */           171U,             170U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,           9U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_ID2_862c1b6d, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  { /*    65 */            40U,              39U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,        112U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                    14U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/SECDRY_HW_TQ_SNSR_VLTG_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    66 */           186U,             181U,        FALSE, COM_UINT64_APPLTYPEOFTXSIGINFO,       40U,         24U,     COM_NBYTE_BUSACCOFTXSIGINFO,         5U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            1U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     3U,          10U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_5fff8d6b, /ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  { /*    67 */           179U,             178U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          0U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,          10U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_ID2_5fff8d6b, /ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  { /*    68 */           181U,             180U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         16U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            3U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,          10U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/SSS_IDENT_CHAL_5fff8d6b, /ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  { /*    69 */           180U,             179U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,          8U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            3U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,          10U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/SSV_IDENT_CHAL_5fff8d6b, /ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18] */
  { /*    70 */           229U,             228U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         32U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                  15U,                            1U,                            0U,                     4U,           6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  { /*    71 */            27U,              26U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_CON_VEH_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    72 */           237U,             236U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         56U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            5U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     7U,           7U,                                4U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ST_CULI_EST_dcba517d, /ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  { /*    73 */           188U,             187U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         10U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                  16U,                            4U,                            0U,                     1U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_IMME_MUX_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    74 */           188U,             186U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,          4U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         0U,                                  17U,                            4U,                            0U,                     0U,          11U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_MAX_MUX_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  { /*    75 */           248U,             247U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         16U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,          12U,                                5U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ST_EST_dummy_16_23_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  { /*    76 */           229U,             228U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         38U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                  18U,                            1U,                            0U,                     4U,           6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_IDC_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  { /*    77 */           253U,             251U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        6U,         14U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,          13U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_14_19_f544de28, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  { /*    78 */           257U,             252U,        FALSE, COM_UINT32_APPLTYPEOFTXSIGINFO,       32U,         20U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         4U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,          13U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_20_51_f544de28, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18] */
  { /*    79 */            27U,              26U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,          8U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/SYS_ST_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*    80 */           174U,             173U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        8U,         24U,      COM_BYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            3U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     3U,           9U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/TEMP_CPO_HET_MNG_862c1b6d, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  { /*    81 */           252U,             250U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       12U,          0U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            0U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     0U,          13U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/TOT_STR_EPS_f544de28, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6InvValue] */
  { /*    82 */           229U,             228U,         TRUE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        4U,         34U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U,                                  19U,                            5U,                            0U,                     4U,           6U,                                3U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/TRANF_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  { /*    83 */           166U,             164U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       12U,         16U, COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            0U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           8U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/TRGG_ENGTORQ_EPS_4e565a26, /ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  { /*    84 */           220U,             219U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         62U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            1U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     7U,           2U,                                1U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/UN_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  { /*    85 */           252U,             251U,        FALSE,  COM_UINT8_APPLTYPEOFTXSIGINFO,        2U,         12U,      COM_NBIT_BUSACCOFTXSIGINFO,         0U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO,                            1U, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     1U,          13U,                                6U },  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/UN_TOT_STR_EPS_f544de28, /ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6InvValue] */
  { /*    86 */            29U,              27U,        FALSE, COM_UINT16_APPLTYPEOFTXSIGINFO,       16U,         16U,     COM_NBYTE_BUSACCOFTXSIGINFO,         2U, COM_NO_FILTERINITVALUEIDXOFTXSIGINFO, COM_NO_INVVALUEIDXOFTXSIGINFO, COM_NO_ONCHANGEIDXOFTXSIGINFO,                     2U,           4U, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO }   /* [/ActiveEcuC/Com/ComConfig/VEH_SPD_EPS_df324712, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfoFilterInitValueInd
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfoFilterInitValueInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_TxSigInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigInfoFilterInitValueIndType, COM_CONST) Com_TxSigInfoFilterInitValueInd[21] = {
  /* Index     TxSigInfoFilterInitValueInd      Referable Keys */
  /*     0 */                          18U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  /*     1 */                          53U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  /*     2 */                          70U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  /*     3 */                          76U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  /*     4 */                          82U,  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18TxFilterInitValue] */
  /*     5 */                           5U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*     6 */                          29U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*     7 */                          30U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*     8 */                          31U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*     9 */                          32U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*    10 */                          33U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*    11 */                          34U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*    12 */                          35U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*    13 */                          36U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*    14 */                          73U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*    15 */                          74U,  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18TxFilterInitValue] */
  /*    16 */                           6U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  /*    17 */                          24U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  /*    18 */                          60U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  /*    19 */                          61U,  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
  /*    20 */                          62U   /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18TxFilterInitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfoInvValueInd
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfoInvValueInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_TxSigInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Com_TxSigInfoInvValueIndType, COM_CONST) Com_TxSigInfoInvValueInd[31] = {
  /* Index     TxSigInfoInvValueInd      Referable Keys */
  /*     0 */                    0U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  /*     1 */                    9U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  /*     2 */                   14U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  /*     3 */                   56U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fInvValue] */
  /*     4 */                    1U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  /*     5 */                   12U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  /*     6 */                   13U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  /*     7 */                   43U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  /*     8 */                   54U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  /*     9 */                   58U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  /*    10 */                   84U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eInvValue] */
  /*    11 */                    2U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2InvValue] */
  /*    12 */                   15U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2InvValue] */
  /*    13 */                   59U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2InvValue] */
  /*    14 */                    3U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue] */
  /*    15 */                   18U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue] */
  /*    16 */                   53U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue] */
  /*    17 */                   70U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue] */
  /*    18 */                   76U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue] */
  /*    19 */                   82U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aInvValue] */
  /*    20 */                    4U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  /*    21 */                   11U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  /*    22 */                   57U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  /*    23 */                   72U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35InvValue] */
  /*    24 */                    6U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue] */
  /*    25 */                   60U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue] */
  /*    26 */                   61U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue] */
  /*    27 */                   62U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16InvValue] */
  /*    28 */                    7U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6InvValue] */
  /*    29 */                   81U,  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6InvValue] */
  /*    30 */                   85U   /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6InvValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/A_TEMP_19255f18] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleTxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleTxPduDeferred
  \brief  Flag array used for deferred Tx confirmation handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_HandleTxPduDeferredType, COM_VAR_NOINIT) Com_HandleTxPduDeferred[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/A_TEMP_19255f18] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/A_TEMP_19255f18] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    98 */  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /* Index        Referable Keys  */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   114 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   115 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   130 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   131 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*   146 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*   147 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /* Index        Referable Keys  */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18] */
  /*   153 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   154 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   155 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   156 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   157 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   158 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   160 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18] */
  /*   161 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   162 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   163 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   164 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   165 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   166 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   167 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   168 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18] */
  /*   169 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   170 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   171 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   172 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   173 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   174 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   175 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   176 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18] */
  /*   177 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   178 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   179 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   180 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   181 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   182 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   183 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   184 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18] */
  /*   185 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   186 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   187 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   188 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   189 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   190 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18] */
  /*   191 */  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   192 */  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   193 */  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   194 */  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */
  /*   195 */  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredFctPtrCache
**********************************************************************************************************************/
/** 
  \var    Com_RxDeferredFctPtrCache
  \brief  Cache for deferred Rx (invalid) notification.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeferredFctPtrCacheType, COM_VAR_NOINIT) Com_RxDeferredFctPtrCache[3];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduDmState
**********************************************************************************************************************/
/** 
  \var    Com_RxPduDmState
  \brief  Rx I-PDU based deadline monitoring state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxPduDmStateType, COM_VAR_NOINIT) Com_RxPduDmState[13];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18PduBased] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18PduBased] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18PduBased, /ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8f] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18PduBased] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0c, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18PduBased, /ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0c] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18PduBased] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18PduBased] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18PduBased] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18PduBased, /ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18PduBased] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18PduBased] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18PduBased] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18PduBased] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[28];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_In, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_RPM_WHL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/A_TEMP_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup5] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/CTR_DIAG_OBD_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup6] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup6] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_OBD_ENG_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup7] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup8] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/ENSU_SFY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup6] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/ERRM_BN_U_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup9] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/FAHRGESTELLNUMMER_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/FZZSTD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/RELATIVZEIT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/SECU_FAHRGESTELLNUMMER_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup4] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup10] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_GEN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/ST_STAB_DSC_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/TAR_ESTP_VIRT_FTAX_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/EPS_IN_PduGroup3] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferArrayBased
  \brief  Rx Signal and Group Signal Buffer. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferArrayBasedType, COM_VAR_NOINIT) Com_RxSigBufferArrayBased[7];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_1_13b7b7e4, /ActiveEcuC/Com/ComConfig/NO_VECH_1_13b7b7e4_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_2_13b7b7e4, /ActiveEcuC/Com/ComConfig/NO_VECH_2_13b7b7e4_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_3_13b7b7e4, /ActiveEcuC/Com/ComConfig/NO_VECH_3_13b7b7e4_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_4_13b7b7e4, /ActiveEcuC/Com/ComConfig/NO_VECH_4_13b7b7e4_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_5_13b7b7e4, /ActiveEcuC/Com/ComConfig/NO_VECH_5_13b7b7e4_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_6_13b7b7e4, /ActiveEcuC/Com/ComConfig/NO_VECH_6_13b7b7e4_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/NO_VECH_7_13b7b7e4, /ActiveEcuC/Com/ComConfig/NO_VECH_7_13b7b7e4_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[28];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_1311692d] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_1311692d_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_1311692d_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_ERR_AMP_1311692d] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_ERR_AMP_1311692d_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_ERR_AMP_1311692d_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_In, /ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_In_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/AVL_PO_IDX_ICM_1a5f7888] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/AVL_PO_IDX_ICM_1a5f7888_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/AVL_PO_IDX_ICM_1a5f7888_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bf] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bf_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bf] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bf_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bf] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bf_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bf] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bf_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9, /ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_In, /ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_In_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/QU_FN_FDR_d5c7d03c, /ActiveEcuC/Com/ComConfig/QU_FN_FDR_d5c7d03c_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STMOM_DV_54d7ae59] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STMOM_DV_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STMOM_DV_54d7ae59_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_56e1c987] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_56e1c987_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_ERR_AMP_dc9eeb12] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_ERR_AMP_dc9eeb12_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_ERR_AMP_dc9eeb12_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dc9eeb12] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dc9eeb12_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dc9eeb12_RxSignalBufferRouting] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_COG_579a99a0] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_COG_579a99a0_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_COG_579a99a0_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/COU_BS_RESP_d377025e, /ActiveEcuC/Com/ComConfig/COU_BS_RESP_d377025e_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_FKTN_PRTNT_c1ae6ae9] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_FKTN_PRTNT_c1ae6ae9_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_FKTN_PRTNT_c1ae6ae9_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_32_63_db9b6687] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_32_63_db9b6687_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_32_63_db9b6687_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496, /ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/STU_RESP_d377025e, /ActiveEcuC/Com/ComConfig/STU_RESP_d377025e_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9b] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9b_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9b_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9b] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9b_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9b_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_32_51_56e1c987] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_32_51_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_32_51_56e1c987_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/T_SEC_COU_REL_0b27fbfe, /ActiveEcuC/Com/ComConfig/T_SEC_COU_REL_0b27fbfe_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt64
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt64
  \brief  Rx Signal and Group Signal Buffer. (UINT64)
*/ 
#define COM_START_SEC_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt64Type, COM_VAR_NOINIT) Com_RxSigBufferUInt64[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/STU_8_BYTE_347be560, /ActiveEcuC/Com/ComConfig/STU_8_BYTE_347be560_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[151];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_MASSCNTR_dummy_12_15_1311692d] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_MASSCNTR_dummy_12_15_1311692d_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_MASSCNTR_dummy_12_15_1311692d_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9b] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9b_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9b_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ALIV_ACLNY_COG_1311692d] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ALIV_ACLNY_COG_1311692d_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ALIV_ACLNY_COG_1311692d_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bf] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bf_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ALIV_CON_VEH_c1ae6ae9] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ALIV_CON_VEH_c1ae6ae9_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ALIV_CON_VEH_c1ae6ae9_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ALIV_ENERG_DGR_DRDY_6d50c911] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ALIV_ENERG_DGR_DRDY_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ALIV_ENERG_DGR_DRDY_6d50c911_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ALIV_OFFS_QUAD_EPS_1a5f7888] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ALIV_OFFS_QUAD_EPS_1a5f7888_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ALIV_OFFS_QUAD_EPS_1a5f7888_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/ALIV_ST_CENG_43f592b4, /ActiveEcuC/Com/ComConfig/ALIV_ST_CENG_43f592b4_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9b] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9b_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9b_RxSignalBufferRouting] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/ALIV_TAR_QTA_STMOM_DV_54d7ae59] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/ALIV_TAR_QTA_STMOM_DV_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/ALIV_TAR_QTA_STMOM_DV_54d7ae59_RxSignalBufferRouting] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/ALIV_TAR_STMOM_DV_ACT_56e1c987] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/ALIV_TAR_STMOM_DV_ACT_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/ALIV_TAR_STMOM_DV_ACT_56e1c987_RxSignalBufferRouting] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/ALIV_VYAW_VEH_dc9eeb12] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/ALIV_VYAW_VEH_dc9eeb12_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/ALIV_VYAW_VEH_dc9eeb12_RxSignalBufferRouting] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ALIV_V_VEH_579a99a0] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ALIV_V_VEH_579a99a0_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ALIV_V_VEH_579a99a0_RxSignalBufferRouting] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_dummy_12_15_c59967bf] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_dummy_12_15_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_dummy_12_15_c59967bf_RxSignalBufferRouting] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687_RxSignalBufferRouting] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CON_VEH_dummy_56_63_c1ae6ae9] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CON_VEH_dummy_56_63_c1ae6ae9_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CON_VEH_dummy_56_63_c1ae6ae9_RxSignalBufferRouting] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/CRC_ACLNY_COG_1311692d] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/CRC_ACLNY_COG_1311692d_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/CRC_ACLNY_COG_1311692d_RxSignalBufferRouting] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/CRC_AVL_RPM_WHL_c59967bf] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/CRC_AVL_RPM_WHL_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/CRC_AVL_RPM_WHL_c59967bf_RxSignalBufferRouting] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CRC_CON_VEH_c1ae6ae9] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CRC_CON_VEH_c1ae6ae9_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CRC_CON_VEH_c1ae6ae9_RxSignalBufferRouting] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/CRC_ENERG_DGR_DRDY_6d50c911] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/CRC_ENERG_DGR_DRDY_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/CRC_ENERG_DGR_DRDY_6d50c911_RxSignalBufferRouting] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CRC_ENSU_SFY_db9b6687] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CRC_ENSU_SFY_db9b6687_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CRC_ENSU_SFY_db9b6687_RxSignalBufferRouting] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/CRC_OFFS_QUAD_EPS_1a5f7888] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/CRC_OFFS_QUAD_EPS_1a5f7888_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/CRC_OFFS_QUAD_EPS_1a5f7888_RxSignalBufferRouting] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/CRC_TAR_ESTP_VIRT_FTAX_0f46fe9b] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/CRC_TAR_ESTP_VIRT_FTAX_0f46fe9b_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/CRC_TAR_ESTP_VIRT_FTAX_0f46fe9b_RxSignalBufferRouting] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CRC_TAR_QTA_STMOM_DV_54d7ae59] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CRC_TAR_QTA_STMOM_DV_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CRC_TAR_QTA_STMOM_DV_54d7ae59_RxSignalBufferRouting] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/CRC_TAR_STMOM_DV_ACT_56e1c987] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/CRC_TAR_STMOM_DV_ACT_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/CRC_TAR_STMOM_DV_ACT_56e1c987_RxSignalBufferRouting] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/CRC_VYAW_VEH_dc9eeb12] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/CRC_VYAW_VEH_dc9eeb12_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/CRC_VYAW_VEH_dc9eeb12_RxSignalBufferRouting] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/CRC_V_VEH_579a99a0] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/CRC_V_VEH_579a99a0_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/CRC_V_VEH_579a99a0_RxSignalBufferRouting] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_BS_PRTNT_c1ae6ae9] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_BS_PRTNT_c1ae6ae9_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_BS_PRTNT_c1ae6ae9_RxSignalBufferRouting] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CTR_DEAC_EPS_FNS_54d7ae59] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CTR_DEAC_EPS_FNS_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CTR_DEAC_EPS_FNS_54d7ae59_RxSignalBufferRouting] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/CTR_ERRM_BN_U_d46c15e6, /ActiveEcuC/Com/ComConfig/CTR_ERRM_BN_U_d46c15e6_RxSignalBufferRouting] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8f_RxSignalBufferRouting] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8f_RxSignalBufferRouting] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8f_RxSignalBufferRouting] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/DVCO_VEH_579a99a0] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/DVCO_VEH_579a99a0_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/DVCO_VEH_579a99a0_RxSignalBufferRouting] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_AVAI_ARS_6d50c911] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_AVAI_ARS_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_AVAI_ARS_6d50c911_RxSignalBufferRouting] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_DGR_DRDY_dummy_12_15_6d50c911] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_DGR_DRDY_dummy_12_15_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_DGR_DRDY_dummy_12_15_6d50c911_RxSignalBufferRouting] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_28_31_db9b6687] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_28_31_db9b6687_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_28_31_db9b6687_RxSignalBufferRouting] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_ASS_STMOM_FTAX_54d7ae59] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_ASS_STMOM_FTAX_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_ASS_STMOM_FTAX_54d7ae59_RxSignalBufferRouting] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_CTRR_STMOM_FTAX_54d7ae59] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_CTRR_STMOM_FTAX_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_CTRR_STMOM_FTAX_54d7ae59_RxSignalBufferRouting] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987_RxSignalBufferRouting] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_DMPNG_STMOM_FTAX_54d7ae59] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_DMPNG_STMOM_FTAX_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_DMPNG_STMOM_FTAX_54d7ae59_RxSignalBufferRouting] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376, /ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376_RxSignalBufferRouting] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_LD_SPEC_ARS_6d50c911] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_LD_SPEC_ARS_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_LD_SPEC_ARS_6d50c911_RxSignalBufferRouting] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_RECUP_SPEC_ARS_6d50c911] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_RECUP_SPEC_ARS_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_RECUP_SPEC_ARS_6d50c911_RxSignalBufferRouting] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_BAX_STE_6d50c911] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_BAX_STE_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_BAX_STE_6d50c911_RxSignalBufferRouting] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_EPS_6d50c911] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_EPS_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_EPS_6d50c911_RxSignalBufferRouting] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/OFFS_QUAD_RTR_EPS_1a5f7888] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/OFFS_QUAD_RTR_EPS_1a5f7888_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/OFFS_QUAD_RTR_EPS_1a5f7888_RxSignalBufferRouting] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/QU_ACLNY_COG_1311692d] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/QU_ACLNY_COG_1311692d_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/QU_ACLNY_COG_1311692d_RxSignalBufferRouting] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bf] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bf_RxSignalBufferRouting] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bf] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bf_RxSignalBufferRouting] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bf] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bf_RxSignalBufferRouting] */
  /*    98 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bf] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bf_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bf_RxSignalBufferRouting] */
  /* Index        Referable Keys  */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/QU_DGR_AISP_ENERG_6d50c911] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/QU_DGR_AISP_ENERG_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/QU_DGR_AISP_ENERG_6d50c911_RxSignalBufferRouting] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687_RxSignalBufferRouting] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/QU_ST_CON_VEH_c1ae6ae9] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/QU_ST_CON_VEH_c1ae6ae9_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/QU_ST_CON_VEH_c1ae6ae9_RxSignalBufferRouting] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987_RxSignalBufferRouting] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_FACT_STMOM_FTAX_54d7ae59] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_FACT_STMOM_FTAX_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_FACT_STMOM_FTAX_54d7ae59_RxSignalBufferRouting] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_QTA_STMOM_DV_54d7ae59] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_QTA_STMOM_DV_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_QTA_STMOM_DV_54d7ae59_RxSignalBufferRouting] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_STMOM_DV_ACT_56e1c987] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_STMOM_DV_ACT_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_STMOM_DV_ACT_56e1c987_RxSignalBufferRouting] */
  /*   114 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/QU_VYAW_VEH_dc9eeb12] */
  /*   115 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/QU_VYAW_VEH_dc9eeb12_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/QU_VYAW_VEH_dc9eeb12_RxSignalBufferRouting] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/QU_V_VEH_COG_579a99a0] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/QU_V_VEH_COG_579a99a0_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/QU_V_VEH_COG_579a99a0_RxSignalBufferRouting] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/RQ_CULI_EST_SFY_6d50c911] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/RQ_CULI_EST_SFY_6d50c911_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/RQ_CULI_EST_SFY_6d50c911_RxSignalBufferRouting] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687_RxSignalBufferRouting] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/RQ_RST_OBD_DIAG_DRDY_85fd80d4, /ActiveEcuC/Com/ComConfig/RQ_RST_OBD_DIAG_DRDY_85fd80d4_RxSignalBufferRouting] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/SECU_RESP_ID2_d377025e, /ActiveEcuC/Com/ComConfig/SECU_RESP_ID2_d377025e_RxSignalBufferRouting] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/SSV_IDENT_RESP_d377025e, /ActiveEcuC/Com/ComConfig/SSV_IDENT_RESP_d377025e_RxSignalBufferRouting] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/ST_ANO_MSA_ENG_STOP_43f592b4, /ActiveEcuC/Com/ComConfig/ST_ANO_MSA_ENG_STOP_43f592b4_RxSignalBufferRouting] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/ST_CENG_DRV_43f592b4, /ActiveEcuC/Com/ComConfig/ST_CENG_DRV_43f592b4_RxSignalBufferRouting] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ST_CON_VEH_c1ae6ae9] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ST_CON_VEH_c1ae6ae9_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ST_CON_VEH_c1ae6ae9_RxSignalBufferRouting] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0c, /ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0c_RxSignalBufferRouting] */
  /*   130 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_SUPY_43f592b4, /ActiveEcuC/Com/ComConfig/ST_ENERG_SUPY_43f592b4_RxSignalBufferRouting] */
  /*   131 */  /* [/ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0c, /ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0c_RxSignalBufferRouting] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/ST_LDREL_GEN_3319a82a, /ActiveEcuC/Com/ComConfig/ST_LDREL_GEN_3319a82a_RxSignalBufferRouting] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/ST_MOT_DRV_43f592b4, /ActiveEcuC/Com/ComConfig/ST_MOT_DRV_43f592b4_RxSignalBufferRouting] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/ST_OBD_CYC_f0d11ff9, /ActiveEcuC/Com/ComConfig/ST_OBD_CYC_f0d11ff9_RxSignalBufferRouting] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ST_OFFS_QUAD_EPS_1a5f7888] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ST_OFFS_QUAD_EPS_1a5f7888_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ST_OFFS_QUAD_EPS_1a5f7888_RxSignalBufferRouting] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/ST_SEP_STOR_3319a82a, /ActiveEcuC/Com/ComConfig/ST_SEP_STOR_3319a82a_RxSignalBufferRouting] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/ST_UDP_43f592b4, /ActiveEcuC/Com/ComConfig/ST_UDP_43f592b4_RxSignalBufferRouting] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ST_V_VEH_NSS_579a99a0] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ST_V_VEH_NSS_579a99a0_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ST_V_VEH_NSS_579a99a0_RxSignalBufferRouting] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376, /ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376_RxSignalBufferRouting] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59_RxSignalBufferRouting] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_12_15_56e1c987] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_12_15_56e1c987_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_12_15_56e1c987_RxSignalBufferRouting] */
  /*   146 */  /* [/ActiveEcuC/Com/ComConfig/TEMP_EX_4b857050, /ActiveEcuC/Com/ComConfig/TEMP_EX_4b857050_RxSignalBufferRouting] */
  /*   147 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dummy_12_15_dc9eeb12] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dummy_12_15_dc9eeb12_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dummy_12_15_dc9eeb12_RxSignalBufferRouting] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_dummy_39_39_579a99a0] */
  /* Index        Referable Keys  */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_dummy_39_39_579a99a0_RxGroupSignalShadowBuffer, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_dummy_39_39_579a99a0_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutCnt
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutCnt
  \brief  This array holds timeout counters for all Rx timeout objects.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_RxTOutCntType, COM_VAR_NOINIT) Com_RxTOutCnt[13];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18, /ActiveEcuC/Com/ComConfig/ACLNY_MASSCNTR_19255f18PduBased] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18, /ActiveEcuC/Com/ComConfig/CON_VEH_19255f18PduBased] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/CTR_WARN_DIR_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18, /ActiveEcuC/Com/ComConfig/CTR_VIB_STW_DISP_EXMI_SP2015_19255f18PduBased, /ActiveEcuC/Com/ComConfig/CTR_WARN_ILVL_VIB_EPS_66c73f8f, /ActiveEcuC/Com/ComConfig/CTR_WARN_PTRN_VIB_EPS_66c73f8f] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ENERG_DGR_DRDY_19255f18PduBased] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ST_ENERG_FZM_e7ce1a0c, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18, /ActiveEcuC/Com/ComConfig/FZZSTD_19255f18PduBased, /ActiveEcuC/Com/ComConfig/ST_ILK_ERRM_FZM_e7ce1a0c] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MILE_KM_a6dd5496, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18, /ActiveEcuC/Com/ComConfig/KILOMETERSTAND_19255f18PduBased] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18, /ActiveEcuC/Com/ComConfig/OFFS_QUAD_EPS_19255f18PduBased] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STEA_PNI_OFFS_9678c0e9, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18, /ActiveEcuC/Com/ComConfig/STEA_OFFS_19255f18PduBased] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/FACT_MO_STE_SO_DXP_59dc6376, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18, /ActiveEcuC/Com/ComConfig/SU_CLE_DRDY_DXP_19255f18PduBased, /ActiveEcuC/Com/ComConfig/SU_CLU_STMOM_SFE_DXP_59dc6376] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18, /ActiveEcuC/Com/ComConfig/TAR_QTA_STRMOM_DV_19255f18PduBased] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/TAR_STMOM_DV_ACT_19255f18PduBased] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18, /ActiveEcuC/Com/ComConfig/VYAW_VEH_19255f18PduBased] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18, /ActiveEcuC/Com/ComConfig/V_VEH_19255f18PduBased] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_SigGrpEventFlag
**********************************************************************************************************************/
/** 
  \var    Com_SigGrpEventFlag
  \brief  Flag is set if a group signal write access caused a triggered event.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_SigGrpEventFlagType, COM_VAR_NOINIT) Com_SigGrpEventFlag[7];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxBuffer
  \brief  Temporary buffer for Rx UINT8_N and UINT8_DYN signals.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TmpRxBufferType, COM_VAR_NOINIT) Com_TmpRxBuffer[8];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt16
  \brief  Temporary Rx Group Signal Shadow Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TmpRxShdBufferUInt16Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt16[4];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RRH_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/AVL_PO_IDX_ICM_1a5f7888, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_ERR_AMP_dc9eeb12, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_COG_579a99a0] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_COG_ERR_AMP_1311692d, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FLH_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dc9eeb12] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_FRH_c59967bf] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_RLH_c59967bf] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt32
  \brief  Temporary Rx Group Signal Shadow Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TmpRxShdBufferUInt32Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt32[2];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_FKTN_PRTNT_c1ae6ae9, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_32_63_db9b6687, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_36_63_0f46fe9b, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_32_51_56e1c987] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/TAR_ESTP_VIRT_FTAX_dummy_12_31_0f46fe9b] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxShdBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxShdBufferUInt8
  \brief  Temporary Rx Group Signal Shadow Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TmpRxShdBufferUInt8Type, COM_VAR_NOINIT) Com_TmpRxShdBufferUInt8[10];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ACLNY_MASSCNTR_dummy_12_15_1311692d, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/AVL_RPM_WHL_dummy_12_15_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CRC_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_BAX_STE_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CHL_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ALIV_OFFS_QUAD_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/CRC_TAR_ESTP_VIRT_FTAX_0f46fe9b, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/TAR_QTA_STRMOM_DV_dummy_12_15_54d7ae59, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/TAR_STMOM_DV_ACT_dummy_12_15_56e1c987, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/CRC_VYAW_VEH_dc9eeb12, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ALIV_V_VEH_579a99a0] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/ALIV_ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/ALIV_AVL_RPM_WHL_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CTR_BS_PRTNT_c1ae6ae9, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_RECUP_SPEC_ARS_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/CRC_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/ST_OFFS_QUAD_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ALIV_TAR_ESTP_VIRT_FTAX_0f46fe9b, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/ALIV_TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/QU_VYAW_VEH_dc9eeb12, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/ST_V_VEH_NSS_579a99a0] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/CRC_ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/CRC_AVL_RPM_WHL_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ST_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ALIV_ENERG_DGR_DRDY_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/QU_FN_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/CRC_OFFS_QUAD_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_ESTP_VIRT_FTAX_7f6c789c/ACTVN_FN_ESTP_VIRT_FTAX_0f46fe9b, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/FACT_DMPNG_ADDON_STMOM_FTAX_56e1c987, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/ALIV_VYAW_VEH_dc9eeb12, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/DVCO_VEH_579a99a0] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ACLNY_MASSCNTR_461c64b1/QU_ACLNY_COG_1311692d, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FRH_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/ALIV_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/CRC_ENERG_DGR_DRDY_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/RQ_CULI_db9b6687, /ActiveEcuC/Com/ComConfig/sigGroup_OFFS_QUAD_EPS_cc150a52/OFFS_QUAD_RTR_EPS_1a5f7888, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CRC_TAR_QTA_STMOM_DV_54d7ae59, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/QU_TAR_DMPNG_ADDON_STMOM_FTAX_56e1c987, /ActiveEcuC/Com/ComConfig/sigGroup_VYAW_VEH_fc66be94/VYAW_VEH_dummy_12_15_dc9eeb12, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/CRC_V_VEH_579a99a0] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_FLH_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/CON_VEH_dummy_56_63_c1ae6ae9, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_AVAI_ARS_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ALIV_ENSU_SFY_db9b6687, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/QU_TAR_FACT_STMOM_FTAX_54d7ae59, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/CRC_TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/QU_V_VEH_COG_579a99a0] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RLH_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_CON_VEH_675e7344/QU_ST_CON_VEH_c1ae6ae9, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/RQ_CULI_EST_SFY_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_ENSU_SFY_dfa36b36/ENSU_SFY_dummy_28_31_db9b6687, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_DMPNG_STMOM_FTAX_54d7ae59, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_STMOM_DV_ACT_9a7b28d3/ALIV_TAR_STMOM_DV_ACT_56e1c987, /ActiveEcuC/Com/ComConfig/sigGroup_V_VEH_2fe00c20/V_VEH_dummy_39_39_579a99a0] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_RPM_WHL_eba9ae07/QU_AVL_RPM_WHL_RRH_c59967bf, /ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_LD_SPEC_ARS_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/CTR_DEAC_EPS_FNS_54d7ae59] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/MAX_I_SPEC_EPS_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_ASS_STMOM_FTAX_54d7ae59] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/ENERG_DGR_DRDY_dummy_12_15_6d50c911, /ActiveEcuC/Com/ComConfig/sigGroup_TAR_QTA_STRMOM_DV_231dfb08/FACT_CTRR_STMOM_FTAX_54d7ae59] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ENERG_DGR_DRDY_3f76efd3/QU_DGR_AISP_ENERG_6d50c911] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[258];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/ANFRAGE_ID2_fbd80461_Out] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_Out] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/ID_FN_INQY_fbd80461_Out] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fSigGrpInTxIPDU] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fSigGrpInTxIPDU] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fSigGrpInTxIPDU] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fSigGrpInTxIPDU] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3fSigGrpInTxIPDU] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6eSigGrpInTxIPDU] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2SigGrpInTxIPDU] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2SigGrpInTxIPDU] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2SigGrpInTxIPDU] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2SigGrpInTxIPDU] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_ID2_df324712] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/ST_CON_VEH_EPS_df324712, /ActiveEcuC/Com/ComConfig/SYS_ST_EPS_df324712] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/VEH_SPD_EPS_df324712] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/VEH_SPD_EPS_df324712] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/BATT_VLTG_EPS_df324712] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/BATT_VLTG_EPS_df324712] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/ESTIMD_PEAK_MOT_CURR_EPS_df324712] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/ESTIMD_PEAK_MOT_CURR_EPS_df324712] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/ESTIMD_PEAK_MOT_CURR_EPS_df324712] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_VEL_EPS_df324712] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_VEL_EPS_df324712] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_TQ_CMD_LIMD_EPS_df324712] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_TQ_CMD_LIMD_EPS_df324712] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/PRIM_HW_TQ_SNSR_VLTG_EPS_df324712] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/SECDRY_HW_TQ_SNSR_VLTG_EPS_df324712] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/ECU_TEMP_EPS_df324712] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_FET_TEMP_EPS_df324712] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_MAG_TEMP_EPS_df324712] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_WIDG_TEMP_EPS_df324712] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_WIDG_TEMP_EPS_df324712] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_TQ_CMD_EPS_df324712] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/MOT_TQ_CMD_EPS_df324712] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_ID2_58e47270] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_58e47270] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    98 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /* Index        Referable Keys  */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   114 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   115 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   130 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   131 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aSigGrpInTxIPDU] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aSigGrpInTxIPDU] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aSigGrpInTxIPDU] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aSigGrpInTxIPDU] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0aSigGrpInTxIPDU] */
  /*   146 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   147 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /* Index        Referable Keys  */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   153 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   154 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   155 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   156 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   157 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   158 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   160 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   161 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35SigGrpInTxIPDU] */
  /*   162 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   163 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   164 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/TRGG_ENGTORQ_EPS_4e565a26] */
  /*   165 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/TRGG_ENGTORQ_EPS_4e565a26] */
  /*   166 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   167 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   168 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   169 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18] */
  /*   170 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_ID2_862c1b6d] */
  /*   171 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/ID_FN_RQ_STG_EFAN_862c1b6d] */
  /*   172 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/ID_TEMP_CPO_HET_MNG_862c1b6d, /ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_862c1b6d] */
  /*   173 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/TEMP_CPO_HET_MNG_862c1b6d] */
  /*   174 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   175 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   176 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   177 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18] */
  /*   178 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SECU_CHAL_ID2_5fff8d6b] */
  /*   179 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SSV_IDENT_CHAL_5fff8d6b] */
  /*   180 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SSS_IDENT_CHAL_5fff8d6b] */
  /*   181 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SECU_CHAL_5fff8d6b] */
  /*   182 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SECU_CHAL_5fff8d6b] */
  /*   183 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SECU_CHAL_5fff8d6b] */
  /*   184 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SECU_CHAL_5fff8d6b] */
  /*   185 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/SECU_CHAL_5fff8d6b] */
  /*   186 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ALIV_ST_DIAG_OBD_3_DRDY_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_MAX_MUX_65e49c1b] */
  /*   187 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_IMME_MUX_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_MAX_MUX_65e49c1b] */
  /*   188 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_1_65e49c1b, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_2_65e49c1b] */
  /*   189 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_2_65e49c1b, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_3_65e49c1b] */
  /*   190 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_3_65e49c1b, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_4_65e49c1b] */
  /*   191 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_5_65e49c1b, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_6_65e49c1b] */
  /*   192 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_6_65e49c1b, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_7_65e49c1b] */
  /*   193 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_7_65e49c1b, /ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_8_65e49c1b] */
  /*   194 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16SigGrpInTxIPDU] */
  /*   195 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16SigGrpInTxIPDU] */
  /*   196 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16SigGrpInTxIPDU] */
  /*   197 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16SigGrpInTxIPDU] */
  /*   198 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16SigGrpInTxIPDU] */
  /*   199 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /* Index        Referable Keys  */
  /*   200 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /*   201 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /*   202 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /*   203 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /*   204 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /*   205 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /*   206 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6SigGrpInTxIPDU] */
  /*   207 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/CRC_AVL_FORC_GRD_c0f3c255] */
  /*   208 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_dummy_12_15_c0f3c255, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/ALIV_AVL_FORC_GRD_c0f3c255] */
  /*   209 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_c0f3c255] */
  /*   210 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_FORC_GRD_c0f3c255, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/QU_AVL_FORC_GRD_c0f3c255] */
  /*   211 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_FORC_GRD_19621f3f/AVL_PWR_EL_EPS_COOD_c0f3c255] */
  /*   212 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/CRC_AVL_PO_EPS_4bf7fe20] */
  /*   213 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/QU_AVL_PO_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/ALIV_AVL_PO_EPS_4bf7fe20] */
  /*   214 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_EPS_4bf7fe20] */
  /*   215 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_EPS_4bf7fe20] */
  /*   216 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_IDX_EPS_4bf7fe20] */
  /*   217 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/AVL_PO_IDX_EPS_4bf7fe20] */
  /*   218 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/OFFS_GRD_MID_EPS_4bf7fe20] */
  /*   219 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/IDX_TORQ_SEN_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/OFFS_GRD_MID_EPS_4bf7fe20, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_PO_EPS_290f0f6e/UN_PO_EPS_4bf7fe20] */
  /*   220 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/CRC_AVL_STMOM_DV_ACT_3ef6286e] */
  /*   221 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_dummy_12_15_3ef6286e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/ALIV_AVL_STMOM_DV_ACT_3ef6286e] */
  /*   222 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_3ef6286e] */
  /*   223 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/QU_AVL_STMOM_DV_ACT_3ef6286e, /ActiveEcuC/Com/ComConfig/sigGroup_AVL_STMOM_DV_ACT_744f32e2/AVL_STMOM_DV_ACT_3ef6286e] */
  /*   224 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CRC_DISP_CC_EPS_8a192f9a] */
  /*   225 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ALIV_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CHL_DISP_CC_EPS_8a192f9a] */
  /*   226 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/NO_CC_EPS_8a192f9a] */
  /*   227 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/NO_CC_EPS_8a192f9a] */
  /*   228 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_IDC_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/TRANF_CC_EPS_8a192f9a] */
  /*   229 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/CRC_DT_EST_dcba517d] */
  /*   230 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ALIV_DT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_12_15_dcba517d] */
  /*   231 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_16_47_dcba517d] */
  /*   232 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_16_47_dcba517d] */
  /*   233 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_16_47_dcba517d] */
  /*   234 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_16_47_dcba517d] */
  /*   235 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/AVL_I_ACT_EST_dcba517d] */
  /*   236 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/QU_AVL_I_ACT_EST_dcba517d, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/ST_CULI_EST_dcba517d] */
  /*   237 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_64_95_dcba517d] */
  /*   238 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_64_95_dcba517d] */
  /*   239 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_64_95_dcba517d] */
  /*   240 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_64_95_dcba517d] */
  /*   241 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_96_127_dcba517d] */
  /*   242 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_96_127_dcba517d] */
  /*   243 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_96_127_dcba517d] */
  /*   244 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35, /ActiveEcuC/Com/ComConfig/sigGroup_DT_EST_68b5ac35/DT_EST_dummy_96_127_dcba517d] */
  /*   245 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/CRC_ST_EST_FTAX_eef8e21d] */
  /*   246 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ALIV_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_VIB_EPS_eef8e21d] */
  /*   247 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ST_EST_dummy_16_23_eef8e21d] */
  /*   248 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_SER_STMOM_DV_ACT_eef8e21d] */
  /*   249 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16, /ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_EST_eef8e21d] */
  /* Index        Referable Keys  */
  /*   250 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/TOT_STR_EPS_f544de28] */
  /*   251 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/TOT_STR_EPS_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/UN_TOT_STR_EPS_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_14_19_f544de28] */
  /*   252 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_20_51_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_14_19_f544de28] */
  /*   253 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_20_51_f544de28] */
  /*   254 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_20_51_f544de28] */
  /*   255 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_20_51_f544de28] */
  /*   256 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/SU_EPS_dummy_20_51_f544de28, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/ALIV_SU_EPS_f544de28] */
  /*   257 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6, /ActiveEcuC/Com/ComConfig/sigGroup_SU_EPS_fe4f71c6/CRC_SU_EPS_f544de28] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterOldValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterOldValueUInt16
  \brief  This buffer holds the old signal values for filter MASKED_NEW_DIFFERS_MASKED_OLD and for transfer property TRIGGERED_ON_CHANGE_* evaluation. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxFilterOldValueUInt16Type, COM_VAR_NOINIT) Com_TxFilterOldValueUInt16[1];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/NO_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxFilterOldValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_TxFilterOldValueUInt8
  \brief  This buffer holds the old signal values for filter MASKED_NEW_DIFFERS_MASKED_OLD and for transfer property TRIGGERED_ON_CHANGE_* evaluation. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxFilterOldValueUInt8Type, COM_VAR_NOINIT) Com_TxFilterOldValueUInt8[20];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ALIV_ST_DIAG_OBD_3_DRDY_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/ALIV_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/CHL_DISP_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/CRC_ST_EST_FTAX_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_1_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_2_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_3_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_4_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_5_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_6_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_7_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/DIAG_ST_OBD_3_DRDY_8_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_EST_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_FN_VIB_EPS_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_ST_EST_76669e16/QU_SER_STMOM_DV_ACT_eef8e21d, /ActiveEcuC/Com/ComConfig/ST_EST_19255f18] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_IMME_MUX_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_MAX_MUX_65e49c1b, /ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/ST_IDC_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/sigGroup_DISP_CC_EPS_ad160a0a/TRANF_CC_EPS_8a192f9a, /ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Com_WaitingForConfirmation
**********************************************************************************************************************/
/** 
  \var    Com_WaitingForConfirmation
  \brief  Flag array used for Tx error notification handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Com_WaitingForConfirmationType, COM_VAR_NOINIT) Com_WaitingForConfirmation[14];
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ANFRAGE_fbd80461_Out, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/AVL_FORC_GRD_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/AVL_PO_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AVL_STMOM_DV_ACT_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/DBG_EPS_MOD_EXT_120_BYTE_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/DISP_CC_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/DT_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ENGTORQ_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/RQ_STG_EFAN_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SECU_CHAL_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup3] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/ST_DIAG_OBD_3_DRDY_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/ST_EST_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/SU_EPS_19255f18, /ActiveEcuC/Com/ComConfig/EPS_OUT_PduGroup2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

