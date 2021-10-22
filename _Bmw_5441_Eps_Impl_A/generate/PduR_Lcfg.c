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
 *              File: PduR_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:08
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

#define PDUR_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0612 EOF */ /* MD_MSR_1.1 */


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"

#if(PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/* Include headers with callbacks */
#include "PduR_Com.h"
#include "PduR_FrIf.h"
#include "PduR_IpduM.h"
#include "PduR_FrTp.h"
#include "PduR_Dcm.h"


/**********************************************************************************************************************
 * LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
/* \trace SPEC-663, SPEC-661 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_CopyRxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_CopyRxDataFctPtr
  \brief  Transport protocol CopyRxData function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_CopyRxDataFctPtrType, PDUR_CONST) PduR_CopyRxDataFctPtr[1] = {
  /* Index     CopyRxDataFctPtr      Referable Keys */
  /*     0 */ Dcm_CopyRxData      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_CopyTxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_CopyTxDataFctPtr
  \brief  Transport protocol CopyTxData function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_CopyTxDataFctPtrType, PDUR_CONST) PduR_CopyTxDataFctPtr[1] = {
  /* Index     CopyTxDataFctPtr      Referable Keys */
  /*     0 */ Dcm_CopyTxData      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfRoutingStateTable
**********************************************************************************************************************/
/** 
  \var    PduR_IfRoutingStateTable
  \brief  Contains state transition for Communication Interface routings
  \details
  Element                                   Description
  NextState_For_Init_If_Routing_State   
  NextState_For_Wait_For_RxIndication   
  NextState_For_Wait_For_TriggerTransmit
  NextState_For_Wait_For_TxConfirmation 
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_IfRoutingStateTableType, PDUR_CONST) PduR_IfRoutingStateTable[4] = {
    /* Index    NextState_For_Init_If_Routing_State                                                     NextState_For_Wait_For_RxIndication                                                     NextState_For_Wait_For_TriggerTransmit                                                     NextState_For_Wait_For_TxConfirmation                                                    */
  { /*     0 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                       0UL,                                                                                      0UL },
  { /*     1 */ PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE,                                                                                      0UL },
  { /*     2 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE },
  { /*     3 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                       0UL,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_IfRxIndicationFctPtr
  \brief  Upper layer communication interface Rx indication function pointers.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_IfRxIndicationType, PDUR_CONST) PduR_IfRxIndicationFctPtr[2] = {
  /* Index     IfRxIndicationFctPtr      Referable Keys */
  /*     0 */ Com_RxIndication     ,  /* [/ActiveEcuC/PduR/Com] */
  /*     1 */ IpduM_RxIndication      /* [/ActiveEcuC/PduR/IpduM] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfTriggerTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_IfTriggerTransmitFctPtr
  \brief  Upper layer trigger transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TriggerTransmitFctPtrType, PDUR_CONST) PduR_IfTriggerTransmitFctPtr[2] = {
  /* Index     IfTriggerTransmitFctPtr      Referable Keys */
  /*     0 */ Com_TriggerTransmit     ,  /* [/ActiveEcuC/PduR/Com] */
  /*     1 */ IpduM_TriggerTransmit      /* [/ActiveEcuC/PduR/IpduM] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfTxConfirmationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_IfTxConfirmationFctPtr
  \brief  Upper layer communication interface Tx confimation function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_IfTxConfirmationFctPtrType, PDUR_CONST) PduR_IfTxConfirmationFctPtr[2] = {
  /* Index     IfTxConfirmationFctPtr      Referable Keys */
  /*     0 */ Com_TxConfirmation     ,  /* [/ActiveEcuC/PduR/Com] */
  /*     1 */ IpduM_TxConfirmation      /* [/ActiveEcuC/PduR/IpduM] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxIf2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxIf2Dest
  \brief  This table contains all routing information to perform the Rx handling of an interface routing. Used in the &lt;LLIf&gt;_RxIndication
  \details
  Element                    Description
  DestHnd                    Handle to be used as parameter for the RxIndication function call.
  IfRxIndicationFctPtrIdx    the index of the 1:1 relation pointing to PduR_IfRxIndicationFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RxIf2DestType, PDUR_CONST) PduR_RxIf2Dest[29] = {
    /* Index    DestHnd                                                IfRxIndicationFctPtrIdx        Referable Keys */
  { /*     0 */                   ComConf_ComIPdu_ANFRAGE_fbd80461_In,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ANFRAGE_fbd80461_In/SRC_ANFRAGE_fbd80461_In] */
  { /*     1 */               ComConf_ComIPdu_ACLNY_MASSCNTR_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ACLNY_MASSCNTR_55c86d41/SRC_Fr_pduTrig_ACLNY_MASSCNTR_55c86d41] */
  { /*     2 */                  ComConf_ComIPdu_AVL_RPM_WHL_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_AVL_RPM_WHL_55c86d41/SRC_Fr_pduTrig_AVL_RPM_WHL_55c86d41] */
  { /*     3 */                       ComConf_ComIPdu_A_TEMP_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_A_TEMP_55c86d41/SRC_Fr_pduTrig_A_TEMP_55c86d41] */
  { /*     4 */                      ComConf_ComIPdu_CON_VEH_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_CON_VEH_55c86d41/SRC_Fr_pduTrig_CON_VEH_55c86d41] */
  { /*     5 */            ComConf_ComIPdu_CTR_DIAG_OBD_DRDY_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_CTR_DIAG_OBD_DRDY_55c86d41/SRC_Fr_pduTrig_CTR_DIAG_OBD_DRDY_55c86d41] */
  { /*     6 */ ComConf_ComIPdu_CTR_VIB_STW_DISP_EXMI_SP2015_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_CTR_VIB_STW_DISP_EXMI_SP2015_55c86d41/SRC_Fr_pduTrig_CTR_VIB_STW_DISP_EXMI_SP2015_55c86d41] */
  { /*     7 */                 ComConf_ComIPdu_DIAG_OBD_ENG_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_DIAG_OBD_ENG_55c86d41/SRC_Fr_pduTrig_DIAG_OBD_ENG_55c86d41] */
  { /*     8 */               ComConf_ComIPdu_ENERG_DGR_DRDY_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ENERG_DGR_DRDY_55c86d41/SRC_Fr_pduTrig_ENERG_DGR_DRDY_55c86d41] */
  { /*     9 */                     ComConf_ComIPdu_ENSU_SFY_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ENSU_SFY_55c86d41/SRC_Fr_pduTrig_ENSU_SFY_55c86d41] */
  { /*    10 */                    ComConf_ComIPdu_ERRM_BN_U_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ERRM_BN_U_55c86d41/SRC_Fr_pduTrig_ERRM_BN_U_55c86d41] */
  { /*    11 */            ComConf_ComIPdu_FAHRGESTELLNUMMER_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_FAHRGESTELLNUMMER_55c86d41/SRC_Fr_pduTrig_FAHRGESTELLNUMMER_55c86d41] */
  { /*    12 */                       ComConf_ComIPdu_FZZSTD_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_FZZSTD_55c86d41/SRC_Fr_pduTrig_FZZSTD_55c86d41] */
  { /*    13 */               ComConf_ComIPdu_KILOMETERSTAND_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_KILOMETERSTAND_55c86d41/SRC_Fr_pduTrig_KILOMETERSTAND_55c86d41] */
  { /*    14 */                ComConf_ComIPdu_OFFS_QUAD_EPS_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_OFFS_QUAD_EPS_55c86d41/SRC_Fr_pduTrig_OFFS_QUAD_EPS_55c86d41] */
  { /*    15 */                  ComConf_ComIPdu_RELATIVZEIT_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_RELATIVZEIT_55c86d41/SRC_Fr_pduTrig_RELATIVZEIT_55c86d41] */
  { /*    16 */       ComConf_ComIPdu_SECU_FAHRGESTELLNUMMER_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_SECU_FAHRGESTELLNUMMER_55c86d41/SRC_Fr_pduTrig_SECU_FAHRGESTELLNUMMER_55c86d41] */
  { /*    17 */                    ComConf_ComIPdu_SECU_RESP_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_SECU_RESP_55c86d41/SRC_Fr_pduTrig_SECU_RESP_55c86d41] */
  { /*    18 */                    ComConf_ComIPdu_STEA_OFFS_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_STEA_OFFS_55c86d41/SRC_Fr_pduTrig_STEA_OFFS_55c86d41] */
  { /*    19 */                      ComConf_ComIPdu_ST_CENG_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ST_CENG_55c86d41/SRC_Fr_pduTrig_ST_CENG_55c86d41] */
  { /*    20 */                 ComConf_ComIPdu_ST_ENERG_GEN_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ST_ENERG_GEN_55c86d41/SRC_Fr_pduTrig_ST_ENERG_GEN_55c86d41] */
  { /*    21 */                  ComConf_ComIPdu_ST_STAB_DSC_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ST_STAB_DSC_55c86d41/SRC_Fr_pduTrig_ST_STAB_DSC_55c86d41] */
  { /*    22 */              ComConf_ComIPdu_SU_CLE_DRDY_DXP_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_SU_CLE_DRDY_DXP_55c86d41/SRC_Fr_pduTrig_SU_CLE_DRDY_DXP_55c86d41] */
  { /*    23 */           ComConf_ComIPdu_TAR_ESTP_VIRT_FTAX_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_TAR_ESTP_VIRT_FTAX_55c86d41/SRC_Fr_pduTrig_TAR_ESTP_VIRT_FTAX_55c86d41] */
  { /*    24 */            ComConf_ComIPdu_TAR_QTA_STRMOM_DV_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_TAR_QTA_STRMOM_DV_55c86d41/SRC_Fr_pduTrig_TAR_QTA_STRMOM_DV_55c86d41] */
  { /*    25 */             ComConf_ComIPdu_TAR_STMOM_DV_ACT_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_TAR_STMOM_DV_ACT_55c86d41/SRC_Fr_pduTrig_TAR_STMOM_DV_ACT_55c86d41] */
  { /*    26 */                     ComConf_ComIPdu_VYAW_VEH_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_VYAW_VEH_55c86d41/SRC_Fr_pduTrig_VYAW_VEH_55c86d41] */
  { /*    27 */                        ComConf_ComIPdu_V_VEH_19255f18,                     0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_V_VEH_55c86d41/SRC_Fr_pduTrig_V_VEH_55c86d41] */
  { /*    28 */   IpduMConf_IpduMRxIndication_pduTrig_SVC_fbd80461_In,                     1UL }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SVC_fbd80461_In/SRC_SVC_fbd80461_In] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2Dest
  \brief  This table contains all routing information to perform the Rx handling of a Tp Routing. Used in the PduR_&lt;LLTp&gt;_StartOfReception, PduR_&lt;LLTp&gt;_CopyRxData and PduR_&lt;LLTp&gt;_RxIndication.
  \details
  Element                      Description
  DestHnd                      handle to be used as parameter for the StartOfReception, CopyRxData or RxIndication function call.
  StartOfReceptionFctPtrIdx    the index of the 1:1 relation pointing to PduR_StartOfReceptionFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RxTp2DestType, PDUR_CONST) PduR_RxTp2Dest[28] = {
    /* Index    DestHnd                                            StartOfReceptionFctPtrIdx        Referable Keys */
  { /*     0 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF0_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF0/SRC_Dcm_BRC_FR_32_0xF0] */
  { /*     1 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF1_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF1/SRC_Dcm_BRC_FR_32_0xF1] */
  { /*     2 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF2_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF2/SRC_Dcm_BRC_FR_32_0xF2] */
  { /*     3 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF3_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF3/SRC_Dcm_BRC_FR_32_0xF3] */
  { /*     4 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF4_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF4/SRC_Dcm_BRC_FR_32_0xF4] */
  { /*     5 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF5_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF5/SRC_Dcm_BRC_FR_32_0xF5] */
  { /*     6 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF6_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF6/SRC_Dcm_BRC_FR_32_0xF6] */
  { /*     7 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF7_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF7/SRC_Dcm_BRC_FR_32_0xF7] */
  { /*     8 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF8_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF8/SRC_Dcm_BRC_FR_32_0xF8] */
  { /*     9 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF9_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xF9/SRC_Dcm_BRC_FR_32_0xF9] */
  { /*    10 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFA_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xFA/SRC_Dcm_BRC_FR_32_0xFA] */
  { /*    11 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFB_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xFB/SRC_Dcm_BRC_FR_32_0xFB] */
  { /*    12 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFC_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xFC/SRC_Dcm_BRC_FR_32_0xFC] */
  { /*    13 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFD_fu,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_BRC_FR_32_0xFD/SRC_Dcm_BRC_FR_32_0xFD] */
  { /*    14 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF0_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF0/SRC_Dcm_GW_TRNSM_FR_254_0xF0] */
  { /*    15 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF1_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF1/SRC_Dcm_GW_TRNSM_FR_254_0xF1] */
  { /*    16 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF2_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF2/SRC_Dcm_GW_TRNSM_FR_254_0xF2] */
  { /*    17 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF3_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF3/SRC_Dcm_GW_TRNSM_FR_254_0xF3] */
  { /*    18 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF4_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF4/SRC_Dcm_GW_TRNSM_FR_254_0xF4] */
  { /*    19 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF5_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF5/SRC_Dcm_GW_TRNSM_FR_254_0xF5] */
  { /*    20 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF6_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF6/SRC_Dcm_GW_TRNSM_FR_254_0xF6] */
  { /*    21 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF7_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF7/SRC_Dcm_GW_TRNSM_FR_254_0xF7] */
  { /*    22 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF8_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF8/SRC_Dcm_GW_TRNSM_FR_254_0xF8] */
  { /*    23 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xF9_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xF9/SRC_Dcm_GW_TRNSM_FR_254_0xF9] */
  { /*    24 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFA_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xFA/SRC_Dcm_GW_TRNSM_FR_254_0xFA] */
  { /*    25 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFB_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xFB/SRC_Dcm_GW_TRNSM_FR_254_0xFB] */
  { /*    26 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFC_ph,                       0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xFC/SRC_Dcm_GW_TRNSM_FR_254_0xFC] */
  { /*    27 */ DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0xFD_ph,                       0UL }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_GW_TRNSM_FR_254_0xFD/SRC_Dcm_GW_TRNSM_FR_254_0xFD] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_StartOfReceptionFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_StartOfReceptionFctPtr
  \brief  Transport protocol StartOfReception function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_StartOfReceptionFctPtrType, PDUR_CONST) PduR_StartOfReceptionFctPtr[1] = {
  /* Index     StartOfReceptionFctPtr      Referable Keys */
  /*     0 */ Dcm_StartOfReception      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TpRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TpRxIndicationFctPtr
  \brief  Transport protocol TpRxIndication function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TpRxIndicationFctPtrType, PDUR_CONST) PduR_TpRxIndicationFctPtr[1] = {
  /* Index     TpRxIndicationFctPtr      Referable Keys */
  /*     0 */ Dcm_TpRxIndication      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TpTxConfirmationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TpTxConfirmationFctPtr
  \brief  Transport protocol TpTxConfimation function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TpTxConfirmationFctPtrType, PDUR_CONST) PduR_TpTxConfirmationFctPtr[1] = {
  /* Index     TpTxConfirmationFctPtr      Referable Keys */
  /*     0 */ Dcm_TpTxConfirmation      /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TransmitFctPtr
  \brief  Lower layer transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TransmitFctPtrType, PDUR_CONST) PduR_TransmitFctPtr[3] = {
  /* Index     TransmitFctPtr      Referable Keys */
  /*     0 */ FrIf_Transmit  ,  /* [/ActiveEcuC/PduR/FrIf] */
  /*     1 */ IpduM_Transmit ,  /* [/ActiveEcuC/PduR/IpduM] */
  /*     2 */ FrTp_Transmit     /* [/ActiveEcuC/PduR/FrTp] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all informations to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element              Description
  DestHnd              Handle to be used as parameter for the Transmit function call.
  TransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_TransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[30] = {
    /* Index    DestHnd                                                         TransmitFctPtrIdx        Referable Keys */
  { /*     0 */                  IpduMConf_IpduMTxDynamicPart_ANFRAGE_19255f18,               1UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ANFRAGE_fbd80461_Out/SRC_ANFRAGE_fbd80461_Out] */
  { /*     1 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF0,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF0/SRC_Dcm_ECU_TRNSM_FR_32_0xF0] */
  { /*     2 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF1,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF1/SRC_Dcm_ECU_TRNSM_FR_32_0xF1] */
  { /*     3 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF2,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF2/SRC_Dcm_ECU_TRNSM_FR_32_0xF2] */
  { /*     4 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF3,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF3/SRC_Dcm_ECU_TRNSM_FR_32_0xF3] */
  { /*     5 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF4,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF4/SRC_Dcm_ECU_TRNSM_FR_32_0xF4] */
  { /*     6 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF5,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF5/SRC_Dcm_ECU_TRNSM_FR_32_0xF5] */
  { /*     7 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF6,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF6/SRC_Dcm_ECU_TRNSM_FR_32_0xF6] */
  { /*     8 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF7,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF7/SRC_Dcm_ECU_TRNSM_FR_32_0xF7] */
  { /*     9 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF8,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF8/SRC_Dcm_ECU_TRNSM_FR_32_0xF8] */
  { /*    10 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xF9,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xF9/SRC_Dcm_ECU_TRNSM_FR_32_0xF9] */
  { /*    11 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFA,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xFA/SRC_Dcm_ECU_TRNSM_FR_32_0xFA] */
  { /*    12 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFB,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xFB/SRC_Dcm_ECU_TRNSM_FR_32_0xFB] */
  { /*    13 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFC,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xFC/SRC_Dcm_ECU_TRNSM_FR_32_0xFC] */
  { /*    14 */                    FrTpConf_FrTpTxSdu_FrTpTxSduEcuTrnsm32_0xFD,               2UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Dcm_ECU_TRNSM_FR_32_0xFD/SRC_Dcm_ECU_TRNSM_FR_32_0xFD] */
  { /*    15 */                      FrIfConf_FrIfTxPdu_FrIfTxPdu_AVL_FORC_GRD,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_AVL_FORC_GRD_55c86d41/SRC_Fr_pduTrig_AVL_FORC_GRD_55c86d41] */
  { /*    16 */                        FrIfConf_FrIfTxPdu_FrIfTxPdu_AVL_PO_EPS,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_AVL_PO_EPS_55c86d41/SRC_Fr_pduTrig_AVL_PO_EPS_55c86d41] */
  { /*    17 */                  FrIfConf_FrIfTxPdu_FrIfTxPdu_AVL_STMOM_DV_ACT,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_AVL_STMOM_DV_ACT_55c86d41/SRC_Fr_pduTrig_AVL_STMOM_DV_ACT_55c86d41] */
  { /*    18 */   IpduMConf_IpduMTxDynamicPart_DBG_EPS_BS_MOD_58_BYTE_19255f18,               1UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_DBG_EPS_BS_MOD_58_BYTE_55c86d41/SRC_Fr_pduTrig_DBG_EPS_BS_MOD_58_BYTE_55c86d41] */
  { /*    19 */ IpduMConf_IpduMTxDynamicPart_DBG_EPS_MOD_EXT_120_BYTE_19255f18,               1UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_DBG_EPS_MOD_EXT_120_BYTE_55c86d41/SRC_Fr_pduTrig_DBG_EPS_MOD_EXT_120_BYTE_55c86d41] */
  { /*    20 */                       FrIfConf_FrIfTxPdu_FrIfTxPdu_DISP_CC_EPS,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_DISP_CC_EPS_55c86d41/SRC_Fr_pduTrig_DISP_CC_EPS_55c86d41] */
  { /*    21 */                            FrIfConf_FrIfTxPdu_FrIfTxPdu_DT_EST,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_DT_EST_55c86d41/SRC_Fr_pduTrig_DT_EST_55c86d41] */
  { /*    22 */                       FrIfConf_FrIfTxPdu_FrIfTxPdu_ENGTORQ_EPS,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ENGTORQ_EPS_55c86d41/SRC_Fr_pduTrig_ENGTORQ_EPS_55c86d41] */
  { /*    23 */                        FrIfConf_FrIfTxPdu_FrIfTxPdu_FR_DBG_EPS,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_FR_DBG_EPS_55c86d41/SRC_Fr_pduTrig_FR_DBG_EPS_55c86d41] */
  { /*    24 */              IpduMConf_IpduMTxDynamicPart_RQ_STG_EFAN_19255f18,               1UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_RQ_STG_EFAN_55c86d41/SRC_Fr_pduTrig_RQ_STG_EFAN_55c86d41] */
  { /*    25 */                IpduMConf_IpduMTxDynamicPart_SECU_CHAL_19255f18,               1UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_SECU_CHAL_55c86d41/SRC_Fr_pduTrig_SECU_CHAL_55c86d41] */
  { /*    26 */                FrIfConf_FrIfTxPdu_FrIfTxPdu_ST_DIAG_OBD_3_DRDY,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ST_DIAG_OBD_3_DRDY_55c86d41/SRC_Fr_pduTrig_ST_DIAG_OBD_3_DRDY_55c86d41] */
  { /*    27 */                            FrIfConf_FrIfTxPdu_FrIfTxPdu_ST_EST,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_ST_EST_55c86d41/SRC_Fr_pduTrig_ST_EST_55c86d41] */
  { /*    28 */                            FrIfConf_FrIfTxPdu_FrIfTxPdu_SU_EPS,               0UL },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Fr_pduTrig_SU_EPS_55c86d41/SRC_Fr_pduTrig_SU_EPS_55c86d41] */
  { /*    29 */                               FrIfConf_FrIfTxPdu_FrIfTxPdu_SVC,               0UL }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SVC_fbd80461_Out/SRC_SVC_fbd80461_Out] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2Up
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2Up
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element                       Description
  DestHnd                       handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
  IfTriggerTransmitFctPtrIdx    the index of the 0:1 relation pointing to PduR_IfTriggerTransmitFctPtr
  IfTxConfirmationFctPtrIdx     the index of the 0:1 relation pointing to PduR_IfTxConfirmationFctPtr
  MaskedBits                    contains bitcoded the boolean data of PduR_IfTriggerTransmitFctPtrUsedOfTxIf2Up, PduR_IfTxConfirmationFctPtrUsedOfTxIf2Up
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[16] = {
    /* Index    DestHnd                                               IfTriggerTransmitFctPtrIdx  IfTxConfirmationFctPtrIdx                   MaskedBits        Referable Keys */
  { /*     0 */                 ComConf_ComIPdu_ANFRAGE_fbd80461_Out,                        0UL,                                        0UL,      0x03U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/ANFRAGE_fbd80461_Out] */
  { /*     1 */    IpduMConf_IpduMTxRequest_pduTrig_SVC_fbd80461_Out,                        1UL,                                        1UL,      0x03U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SVC_fbd80461_Out] */
  { /*     2 */                ComConf_ComIPdu_AVL_FORC_GRD_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_AVL_FORC_GRD_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*     3 */                  ComConf_ComIPdu_AVL_PO_EPS_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_AVL_PO_EPS_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*     4 */            ComConf_ComIPdu_AVL_STMOM_DV_ACT_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_AVL_STMOM_DV_ACT_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*     5 */      ComConf_ComIPdu_DBG_EPS_BS_MOD_58_BYTE_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_DBG_EPS_BS_MOD_58_BYTE_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*     6 */    ComConf_ComIPdu_DBG_EPS_MOD_EXT_120_BYTE_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_DBG_EPS_MOD_EXT_120_BYTE_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*     7 */                 ComConf_ComIPdu_DISP_CC_EPS_19255f18,                        0UL,                                        0UL,      0x03U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_DISP_CC_EPS_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*     8 */                      ComConf_ComIPdu_DT_EST_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_DT_EST_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*     9 */                 ComConf_ComIPdu_ENGTORQ_EPS_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_ENGTORQ_EPS_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*    10 */ IpduMConf_IpduMTxRequest_pduTrig_FR_DBG_EPS_55c86d41,                        1UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_FR_DBG_EPS_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*    11 */                 ComConf_ComIPdu_RQ_STG_EFAN_19255f18,                        0UL, PDUR_NO_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP,      0x02U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_RQ_STG_EFAN_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*    12 */                   ComConf_ComIPdu_SECU_CHAL_19255f18,                        0UL,                                        0UL,      0x03U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_SECU_CHAL_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*    13 */          ComConf_ComIPdu_ST_DIAG_OBD_3_DRDY_19255f18,                        0UL,                                        0UL,      0x03U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_ST_DIAG_OBD_3_DRDY_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*    14 */                      ComConf_ComIPdu_ST_EST_19255f18,                        0UL,                                        0UL,      0x03U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_ST_EST_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
  { /*    15 */                      ComConf_ComIPdu_SU_EPS_19255f18,                        0UL,                                        0UL,      0x03U }   /* [/ActiveEcuC/EcuC/EcucPduCollection/pduTrig_SU_EPS_pduPort_EPS_A_FlexRay_OUT_55c86d41_4f391dd1] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxTp2Src
**********************************************************************************************************************/
/** 
  \var    PduR_TxTp2Src
  \brief  This table contains all routing information to perform the Tx handling of a transport protocol routing, Used in the &lt;LoTp&gt;_CopyTxData and &lt;LoTp&gt;_TxConfirmation
  \details
  Element                      Description
  TpTxConfirmationFctPtrIdx    the index of the 1:1 relation pointing to PduR_TpTxConfirmationFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TxTp2SrcType, PDUR_CONST) PduR_TxTp2Src[14] = {
    /* Index    TpTxConfirmationFctPtrIdx        Referable Keys */
  { /*     0 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF0] */
  { /*     1 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF1] */
  { /*     2 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF2] */
  { /*     3 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF3] */
  { /*     4 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF4] */
  { /*     5 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF5] */
  { /*     6 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF6] */
  { /*     7 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF7] */
  { /*     8 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF8] */
  { /*     9 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xF9] */
  { /*    10 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xFA] */
  { /*    11 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xFB] */
  { /*    12 */                       0UL },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xFC] */
  { /*    13 */                       0UL }   /* [/ActiveEcuC/EcuC/EcucPduCollection/Dcm_ECU_TRNSM_FR_32_0xFD] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized = FALSE;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define PDUR_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Upper Layer Interface APIs */

/**********************************************************************************************************************
 * PduR_ComTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_IpduMTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_DcmTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}


/* Communication Interface APIs */

/**********************************************************************************************************************
 * PduR_FrIfRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_FrIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_INVALID_REQUEST);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_FrIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general communication interface TxConfirmation function.
 * \endinternal
 *********************************************************************************************************************/
/* PRQA S 6080 PDUR_LLIF_TXCONFIRMATION */ /* MD_MSR_STMIF */
FUNC(void, PDUR_CODE) PduR_FrIfTxConfirmation(PduIdType TxPduId) /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_LoIfTxConfirmation(TxPduId); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}



/**********************************************************************************************************************
 * PduR_IpduMRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_IpduMRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_INVALID_REQUEST);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_IpduMTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general communication interface TxConfirmation function.
 * \endinternal
 *********************************************************************************************************************/
/* PRQA S 6080 PDUR_LLIF_TXCONFIRMATION */ /* MD_MSR_STMIF */
FUNC(void, PDUR_CODE) PduR_IpduMTxConfirmation(PduIdType TxPduId) /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_LoIfTxConfirmation(TxPduId); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}




/**********************************************************************************************************************
 * PduR_FrIfTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general TriggerTransmit function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_FrIfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  return PduR_LoIfTriggerTransmit(TxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}


/**********************************************************************************************************************
 * PduR_IpduMTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general TriggerTransmit function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  return PduR_LoIfTriggerTransmit(TxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}


/* Transport Protocol APIs */

/**********************************************************************************************************************
 * PduR_FrTpStartOfReception
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call transport protocoll StartOfReception function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_SOR, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_FrTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyRxData.
 * \endinternal
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_PduR_3673_AsrProto */
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyRxData(id, info, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYRX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_FrTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyTxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_FrTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  
#if(PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyTxData(id, info, retry, availableDataPtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYTX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_FrTpRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp RxIndication function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_FrTpRxIndication(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpRxIndication(id, result); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TPRXIND, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_FrTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp TxConfirmation function 
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_FrTpTxConfirmation(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpTxConfirmation(id, result); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TPTXCFM, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}


/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */

/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


#define PDUR_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \N The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       The pointer is provided by the lower layer and is assumed to be valid. It is passed as is to the corresponding function. 

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \R The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       
  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY
    \DESCRIPTION    The API call is forwarded to an internal function.
    \COUNTERMEASURE \N The parameter are checked in the called function.

 SBSW_JUSTIFICATION_END */
 
 /* COV_JUSTIFICATION_BEGIN
 
  \ID COV_PDUR_WRAPPER_FUNC
    \ACCEPT X
    \REASON Each neighbouring module call the same internal function. The call is covered by an other module. 
    
  \ID COV_PDUR_RX_OR_TX_ONLY_CONFIG
    \ACCEPT TX
    \REASON The API is mandatory if this Bsw module exists. In case of Rx or Tx only configs the API call is not forwarded to the internal function. 
 
 COV_JUSTIFICATION_END */
 

/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.c
 *********************************************************************************************************************/

