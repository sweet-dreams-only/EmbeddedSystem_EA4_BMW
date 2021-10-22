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
 *            Module: IpduM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IpduM_Lcfg.c
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


#define IPDUM_LCFG_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "IpduM_Lcfg.h"
#include "IpduM_Cfg.h"

/* include headers with symbolic name values */
# include "PduR_Cfg.h"
# include "Com_Cbk.h"

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
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  IpduM_RxDynPdu
**********************************************************************************************************************/
/** 
  \var    IpduM_RxDynPdu
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart
  \details
  Element          Description
  SegmentEndIdx    the end index of the 1:n relation pointing to IpduM_Segment
  UlPduRef         the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMOutgoingDynamicPduRef
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_RxDynPduType, IPDUM_CONST) IpduM_RxDynPdu[2] = {
    /* Index    SegmentEndIdx  UlPduRef                                   Referable Keys */
  { /*     0 */            1U,  ComConf_ComIPdu_SECU_RESP_19255f18 },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_In/pduTrig_SVC_fbd80461_In] */
  { /*     1 */            1U, ComConf_ComIPdu_ANFRAGE_fbd80461_In }   /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_In/pduTrig_SVC_fbd80461_In] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxSelectorPattern
**********************************************************************************************************************/
/** 
  \var    IpduM_RxSelectorPattern
  \brief  Selector patterns for single- and multi-byte selector value matching. This table is sorted for ascending byte number within one DynPdu.
  \details
  Element                    Description
  SelectorFieldSubMask       One byte of the mask the pattern is masked with for the selector field as it is transmitted.
  SelectorFieldSubPattern    One byte of the masked pattern for the selector field as it is transmitted - calculated from position and length.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_RxSelectorPatternType, IPDUM_CONST) IpduM_RxSelectorPattern[2] = {
    /* Index    SelectorFieldSubMask  SelectorFieldSubPattern        Referable Keys */
  { /*     0 */                0xFFU,                   0xF7U },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_In/pduTrig_SVC_fbd80461_In/SECU_RESP_19255f18] */
  { /*     1 */                0xFFU,                   0x01U }   /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_In/pduTrig_SVC_fbd80461_In/ANFRAGE_19255f18] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Segment
**********************************************************************************************************************/
/** 
  \var    IpduM_Segment
  \brief  all IpduMSegments
  \details
  Element               Description
  Length                the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMSegment/IpduMSegmentLength.
  FullBytesPresent      True if full bytes exist in this segment.
  EndByteMaskClear      Mask for the partial end byte: clearing.
  LastFullBytePos       Byte position of the last full byte.
  StartByteMaskWrite    Mask for the partial start byte: writing.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_SegmentType, IPDUM_CONST) IpduM_Segment[2] = {
    /* Index    Length  FullBytesPresent  EndByteMaskClear  LastFullBytePos  StartByteMaskWrite        Referable Keys */
  { /*     0 */    64U,             TRUE,            0x00U,              7U,              0xFFU },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_In/pduTrig_SVC_fbd80461_In/ANFRAGE_19255f18, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_In/pduTrig_SVC_fbd80461_In/SECU_RESP_19255f18, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out/ANFRAGE_19255f18, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out/RQ_STG_EFAN_19255f18, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out/SECU_CHAL_19255f18] */
  { /*     1 */   464U,             TRUE,            0x00U,             57U,              0xFFU }   /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41/DBG_EPS_BS_MOD_58_BYTE_19255f18, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxInitValues
**********************************************************************************************************************/
/** 
  \var    IpduM_TxInitValues
  \brief  Initial values for tx buffer.
*/ 
#define IPDUM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_TxInitValuesType, IPDUM_CONST) IpduM_TxInitValues[140] = {
  /* Index     TxInitValues  */
  /*     0 */         0x01U,
  /*     1 */         0x00U,
  /*     2 */         0x00U,
  /*     3 */         0x00U,
  /*     4 */         0x00U,
  /*     5 */         0x00U,
  /*     6 */         0x00U,
  /*     7 */         0x00U,
  /*     8 */         0x00U,
  /*     9 */         0x00U,
  /*    10 */         0x00U,
  /*    11 */         0x00U,
  /*    12 */         0x00U,
  /*    13 */         0x00U,
  /*    14 */         0x00U,
  /*    15 */         0x00U,
  /*    16 */         0x00U,
  /*    17 */         0x00U,
  /*    18 */         0x00U,
  /*    19 */         0x00U,
  /*    20 */         0x00U,
  /*    21 */         0x00U,
  /*    22 */         0xFFU,
  /*    23 */         0xFFU,
  /*    24 */         0xFFU,
  /*    25 */         0xFFU,
  /*    26 */         0xFFU,
  /*    27 */         0xFFU,
  /*    28 */         0xFFU,
  /*    29 */         0xFFU,
  /*    30 */         0xFFU,
  /*    31 */         0xFFU,
  /*    32 */         0xFFU,
  /*    33 */         0xFFU,
  /*    34 */         0xFFU,
  /*    35 */         0xFFU,
  /*    36 */         0xFFU,
  /*    37 */         0xFFU,
  /*    38 */         0xFFU,
  /*    39 */         0xFFU,
  /*    40 */         0xFFU,
  /*    41 */         0xFFU,
  /*    42 */         0xFFU,
  /*    43 */         0xFFU,
  /*    44 */         0xFFU,
  /*    45 */         0xFFU,
  /*    46 */         0xFFU,
  /*    47 */         0xFFU,
  /*    48 */         0xFFU,
  /*    49 */         0xFFU,
  /* Index     TxInitValues  */
  /*    50 */         0xFFU,
  /*    51 */         0xFFU,
  /*    52 */         0xFFU,
  /*    53 */         0xFFU,
  /*    54 */         0xFFU,
  /*    55 */         0xFFU,
  /*    56 */         0xFFU,
  /*    57 */         0xFFU,
  /*    58 */         0x01U,
  /*    59 */         0x00U,
  /*    60 */         0x00U,
  /*    61 */         0xFFU,
  /*    62 */         0xFFU,
  /*    63 */         0xFFU,
  /*    64 */         0xFFU,
  /*    65 */         0xFFU,
  /*    66 */         0x00U,
  /*    67 */         0x00U,
  /*    68 */         0x00U,
  /*    69 */         0x00U,
  /*    70 */         0x00U,
  /*    71 */         0x00U,
  /*    72 */         0x00U,
  /*    73 */         0x00U,
  /*    74 */         0x00U,
  /*    75 */         0x00U,
  /*    76 */         0x00U,
  /*    77 */         0x00U,
  /*    78 */         0x00U,
  /*    79 */         0x00U,
  /*    80 */         0x00U,
  /*    81 */         0x00U,
  /*    82 */         0x00U,
  /*    83 */         0x00U,
  /*    84 */         0x00U,
  /*    85 */         0x00U,
  /*    86 */         0x00U,
  /*    87 */         0x00U,
  /*    88 */         0x00U,
  /*    89 */         0x00U,
  /*    90 */         0x00U,
  /*    91 */         0x00U,
  /*    92 */         0x00U,
  /*    93 */         0x00U,
  /*    94 */         0x00U,
  /*    95 */         0x00U,
  /*    96 */         0x00U,
  /*    97 */         0x00U,
  /*    98 */         0x00U,
  /*    99 */         0x00U,
  /* Index     TxInitValues  */
  /*   100 */         0x00U,
  /*   101 */         0x00U,
  /*   102 */         0x00U,
  /*   103 */         0x00U,
  /*   104 */         0x00U,
  /*   105 */         0x00U,
  /*   106 */         0x00U,
  /*   107 */         0x00U,
  /*   108 */         0x00U,
  /*   109 */         0x00U,
  /*   110 */         0x00U,
  /*   111 */         0x00U,
  /*   112 */         0x00U,
  /*   113 */         0x00U,
  /*   114 */         0x00U,
  /*   115 */         0x00U,
  /*   116 */         0x00U,
  /*   117 */         0x00U,
  /*   118 */         0x00U,
  /*   119 */         0x00U,
  /*   120 */         0x00U,
  /*   121 */         0x00U,
  /*   122 */         0x00U,
  /*   123 */         0x00U,
  /*   124 */         0x00U,
  /*   125 */         0x00U,
  /*   126 */         0x00U,
  /*   127 */         0x00U,
  /*   128 */         0x00U,
  /*   129 */         0x00U,
  /*   130 */         0x00U,
  /*   131 */         0x00U,
  /*   132 */         0x00U,
  /*   133 */         0x00U,
  /*   134 */         0x00U,
  /*   135 */         0x00U,
  /*   136 */         0x00U,
  /*   137 */         0x00U,
  /*   138 */         0x00U,
  /*   139 */         0x00U
};
#define IPDUM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxLoInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_TxLoInfo
  \brief  all DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainerTxPdu with DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxConfirmationPduId
  \details
  Element        Description
  PathwayType    The type of the pathway.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_TxLoInfoType, IPDUM_CONST) IpduM_TxLoInfo[2] = {
    /* Index    PathwayType                            Referable Keys */
  { /*     0 */ IPDUM_MUX_PATHWAYTYPEOFTXLOINFO },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41] */
  { /*     1 */ IPDUM_MUX_PATHWAYTYPEOFTXLOINFO }   /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxPart
**********************************************************************************************************************/
/** 
  \var    IpduM_TxPart
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart
  \details
  Element            Description
  MaskedBits         contains bitcoded the boolean data of IpduM_JitUpdateOfTxPart, IpduM_TriggerEventOfTxPart, IpduM_TxConfirmationOfTxPart
  SegmentStartIdx    the start index of the 1:n relation pointing to IpduM_Segment
  TxPathwayIdx       the index of the 1:1 relation pointing to IpduM_TxPathway
  UlPduRef           the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMTxStaticPduRef or DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart/IpduMTxDynamicPduRef
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_TxPartType, IPDUM_CONST) IpduM_TxPart[5] = {
    /* Index    MaskedBits  SegmentStartIdx  TxPathwayIdx  UlPduRef                                                 Referable Keys */
  { /*     0 */      0x07U,              0U,           1U,              ComConf_ComIPdu_ANFRAGE_fbd80461_Out },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out/ANFRAGE_19255f18] */
  { /*     1 */      0x06U,              1U,           0U,   ComConf_ComIPdu_DBG_EPS_BS_MOD_58_BYTE_19255f18 },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41/DBG_EPS_BS_MOD_58_BYTE_19255f18] */
  { /*     2 */      0x06U,              1U,           0U, ComConf_ComIPdu_DBG_EPS_MOD_EXT_120_BYTE_19255f18 },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41/DBG_EPS_MOD_EXT_120_BYTE_19255f18] */
  { /*     3 */      0x06U,              0U,           1U,              ComConf_ComIPdu_RQ_STG_EFAN_19255f18 },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out/RQ_STG_EFAN_19255f18] */
  { /*     4 */      0x07U,              0U,           1U,                ComConf_ComIPdu_SECU_CHAL_19255f18 }   /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out, /ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out/SECU_CHAL_19255f18] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxPartInd
**********************************************************************************************************************/
/** 
  \var    IpduM_TxPartInd
  \brief  the indexes of the 1:1 sorted relation pointing to IpduM_TxPart
*/ 
#define IPDUM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_TxPartIndType, IPDUM_CONST) IpduM_TxPartInd[5] = {
  /* Index     TxPartInd      Referable Keys */
  /*     0 */         1U,  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41] */
  /*     1 */         2U,  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41] */
  /*     2 */         0U,  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out] */
  /*     3 */         3U,  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out] */
  /*     4 */         4U   /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out] */
};
#define IPDUM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxPathway
**********************************************************************************************************************/
/** 
  \var    IpduM_TxPathway
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway
  \details
  Element                    Description
  Length                     the DefinitionRef: /[ANY]/EcuC/EcucPduCollection/Pdu/PduLength
  LlPduRef                   the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMOutgoingPduRef
  TxBufferIdx                the tx buffer index of the IpduMTxPathway.
  TxPartIndEndIdx            the end index of the 1:n relation pointing to IpduM_TxPartInd
  TxPartIndStartIdx          the start index of the 1:n relation pointing to IpduM_TxPartInd
  TxPartInitialDynPartIdx    the index of the 1:1 relation pointing to IpduM_TxPart
  UnusedAreasDefault         the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMIPduUnusedAreasDefault
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_TxPathwayType, IPDUM_CONST) IpduM_TxPathway[2] = {
    /* Index    Length  LlPduRef                                                TxBufferIdx  TxPartIndEndIdx  TxPartIndStartIdx  TxPartInitialDynPartIdx  UnusedAreasDefault        Referable Keys */
  { /*     0 */    58U, PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FR_DBG_EPS_55c86d41,          0U,              2U,                0U,                      1U,               255U },  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41] */
  { /*     1 */     8U,               PduRConf_PduRSrcPdu_SRC_SVC_fbd80461_Out,         58U,              5U,                2U,                      0U,               255U }   /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxUpInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_TxUpInfo
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart, DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart, DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainedTxPdu for transmission.
  \details
  Element        Description
  PathwayType    The type of the pathway.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(IpduM_TxUpInfoType, IPDUM_CONST) IpduM_TxUpInfo[5] = {
    /* Index    PathwayType                     */
  { /*     0 */ IPDUM_MUX_PATHWAYTYPEOFTXUPINFO },
  { /*     1 */ IPDUM_MUX_PATHWAYTYPEOFTXUPINFO },
  { /*     2 */ IPDUM_MUX_PATHWAYTYPEOFTXUPINFO },
  { /*     3 */ IPDUM_MUX_PATHWAYTYPEOFTXUPINFO },
  { /*     4 */ IPDUM_MUX_PATHWAYTYPEOFTXUPINFO }
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_DynamicPduIdx
**********************************************************************************************************************/
/** 
  \var    IpduM_DynamicPduIdx
  \brief  records the last transmission requested of a dynamic part.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(IpduM_DynamicPduIdxUType, IPDUM_VAR_NOINIT) IpduM_DynamicPduIdx;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41] */
  /*     1 */  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out] */

#define IPDUM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Initialized
**********************************************************************************************************************/
/** 
  \var    IpduM_Initialized
  \brief  Initialization state of the IpduM. TRUE, if IpduM_Init() has been called, else FALSE.
*/ 
#define IPDUM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(IpduM_InitializedType, IPDUM_VAR_ZERO_INIT) IpduM_Initialized = FALSE;
#define IPDUM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_JitUpdateBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_JitUpdateBuffer
  \brief  buffer for updating a PDU by just-in-time update initiated by upper layer transmission.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(IpduM_JitUpdateBufferType, IPDUM_VAR_NOINIT) IpduM_JitUpdateBuffer[140];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_RxBuffer
  \brief  buffer to de-multiplex and forward RX static and dynamic parts from the received multiplex I-PDU.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(IpduM_RxBufferType, IPDUM_VAR_NOINIT) IpduM_RxBuffer[8];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TriggerTransmitBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_TriggerTransmitBuffer
  \brief  buffer for updating a PDU by just-in-time update initiated by lower layer triggered transmission.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(IpduM_TriggerTransmitBufferType, IPDUM_VAR_NOINIT) IpduM_TriggerTransmitBuffer[140];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_TxBuffer
  \brief  buffer to multiplex and forward static and dynamic TX parts whose transmission is requested.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(IpduM_TxBufferType, IPDUM_VAR_NOINIT) IpduM_TxBuffer[140];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxConfTimeoutCnt
**********************************************************************************************************************/
/** 
  \var    IpduM_TxConfTimeoutCnt
  \brief  I-PDU based TX confirmation timeout counters.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(IpduM_TxConfTimeoutCntUType, IPDUM_VAR_NOINIT) IpduM_TxConfTimeoutCnt;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_FR_DBG_EPS_55c86d41/pduTrig_FR_DBG_EPS_55c86d41] */
  /*     1 */  /* [/ActiveEcuC/IpduM/IpduMConfig/pduTrig_SVC_fbd80461_Out/pduTrig_SVC_fbd80461_Out] */

#define IPDUM_STOP_SEC_VAR_NOINIT_16BIT
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
  END OF FILE: IpduM_Lcfg.c
**********************************************************************************************************************/

