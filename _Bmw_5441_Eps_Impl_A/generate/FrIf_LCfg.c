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
 *              File: FrIf_LCfg.c
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


#define FRIF_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */
 
 #include "FrIf_Priv.h"
 #include "FrTp_Cbk.h"
 
 #include "PduR_FrIf.h"
 #include "FrXcp_Cbk.h"
 
  

 /* -----------------------------------------------------------------------------
    &&&~ Constants and Variables
 ----------------------------------------------------------------------------- */


#define FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

static VAR(FrIf_NumberOfPduType, FRIF_VAR_NOINIT) FrIf_TxPduWasSentFlags_0[24];
static VAR(uint32, FRIF_VAR_NOINIT) FrIf_FrameBuffer_0[64];
static VAR(uint8, FRIF_VAR_NOINIT) FrIf_TxPduDirtyBits_0[3];
static VAR(uint8, FRIF_VAR_NOINIT) FrIf_TxPduTxRequestCounters_0[1];

#define FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ TriggerTransmit
 ----------------------------------------------------------------------------- */


#ifndef PDUR_FRIFTRIGGERTRANSMIT
#define PDUR_FRIFTRIGGERTRANSMIT                PduR_FrIfTriggerTransmit
#endif
#ifndef FRNM_TRIGGERTRANSMIT					 
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRNM_TRIGGERTRANSMIT(PduId, Payload)	E_NOT_OK
#endif
#ifndef FRTP_TRIGGERTRANSMIT
#define FRTP_TRIGGERTRANSMIT                    FrTp_TriggerTransmit
#endif
#ifndef FRXCP_TRIGGERTRANSMIT
#define FRXCP_TRIGGERTRANSMIT                   Xcp_FrIfTriggerTransmit
#endif
#ifndef FRTSYN_TRIGGERTRANSMIT					 
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRTSYN_TRIGGERTRANSMIT(PduId, Payload)	E_NOT_OK
#endif
#ifndef FRARTP_TRIGGERTRANSMIT					 
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRARTP_TRIGGERTRANSMIT(PduId, Payload)	E_NOT_OK
#endif


/* -----------------------------------------------------------------------------
    &&&~ Rx Indication
 ----------------------------------------------------------------------------- */

#ifndef PDUR_FRIFRXINDICATION
#define PDUR_FRIFRXINDICATION				PduR_FrIfRxIndication
#endif
#ifndef FRNM_RXINDICATION					 
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRNM_RXINDICATION(PduId, Payload)
#endif
#ifndef FRTP_RXINDICATION
#define FRTP_RXINDICATION					FrTp_RxIndication
#endif
#ifndef FRXCP_RXINDICATION
#define FRXCP_RXINDICATION					Xcp_FrIfRxIndication
#endif
#ifndef FRTSYN_RXINDICATION					 
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRTSYN_RXINDICATION(PduId, Payload)
#endif
#ifndef FRARTP_RXINDICATION					 
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRARTP_RXINDICATION(PduId, Payload)
#endif


/* -----------------------------------------------------------------------------
    &&&~ Tx Confirmation
 ----------------------------------------------------------------------------- */


#ifndef PDUR_FRIFTXCONFIRMATION
#define PDUR_FRIFTXCONFIRMATION                 PduR_FrIfTxConfirmation
#endif
#ifndef FRNM_TXCONFIRMATION
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRNM_TXCONFIRMATION(PduId)
#endif
#ifndef FRTP_TXCONFIRMATION
#define FRTP_TXCONFIRMATION                     FrTp_TxConfirmation
#endif
#ifndef FRXCP_TXCONFIRMATION
#define FRXCP_TXCONFIRMATION                    Xcp_FrIfTxConfirmation
#endif
#ifndef FRARTP_TXCONFIRMATION
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define FRARTP_TXCONFIRMATION(PduId)
#endif

#define FRIF_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ FrTransceiver function arrays
 ----------------------------------------------------------------------------- */
CONST(FrTrcv_CheckWakeupByTransceiverFctType, FRIF_CONST) FrTrcv_CheckWakeupByTransceiverFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_CheckWakeupByTransceiver
};

CONST(FrTrcv_ClearTransceiverWakeupFctType, FRIF_CONST) FrTrcv_ClearTransceiverWakeupFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_ClearTransceiverWakeup
};

CONST(FrTrcv_DisableTransceiverBranchFctType, FRIF_CONST) FrTrcv_DisableTransceiverBranchFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_DisableTransceiverBranch
};

CONST(FrTrcv_EnableTransceiverBranchFctType, FRIF_CONST) FrTrcv_EnableTransceiverBranchFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_EnableTransceiverBranch
};

CONST(FrTrcv_GetTransceiverErrorFctType, FRIF_CONST) FrTrcv_GetTransceiverErrorFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_GetTransceiverError
};

CONST(FrTrcv_GetTransceiverModeFctType, FRIF_CONST) FrTrcv_GetTransceiverModeFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_GetTransceiverMode
};

CONST(FrTrcv_GetTransceiverWUReasonFctType, FRIF_CONST) FrTrcv_GetTransceiverWUReasonFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_GetTransceiverWUReason
};

CONST(FrTrcv_SetTransceiverModeFctType, FRIF_CONST) FrTrcv_SetTransceiverModeFctMap[FrIf_NumberOfFrTrcvs] =
{
  FrTrcv_30_Tja1082_SetTransceiverMode
};


#define FRIF_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define FRIF_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  FrIf_CheckChannelStatus()
**********************************************************************************************************************/
/*! \brief       
 *  \details     
 *  \pre         
 *  \context     
 *  \reentrant   
 *  \synchronous 
 *********************************************************************************************************************/

FUNC(void, FRIF_CODE) FrIf_CheckChannelStatus(uint8 ClstIdx, Fr_ChannelType FrChannel, uint16 ChannelStatus)
{
# if (FRIF_PROD_ERROR_DETECT == STD_ON)
  Dem_EventIdType ErrorId_Acs = 0;
  Dem_EventIdType ErrorId_Nit = 0;
  Dem_EventIdType ErrorId_Sw = 0;



  if (1 /* Bit0: (vSS!ValidFrame) */ >= ChannelStatus) /* ESCAN00066846 */
  {
    if (ErrorId_Acs != 0) /* PRQA S 3356, 3359 */ /* MD_FrIf_3356 */
    { /* PRQA S 3201 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */    
      Dem_ReportErrorStatus(ErrorId_Acs, DEM_EVENT_STATUS_PASSED);
    }
    if (ErrorId_Nit != 0) /* PRQA S 3356, 3359 */ /* MD_FrIf_3356 */
    { /* PRQA S 3201 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */    
      Dem_ReportErrorStatus(ErrorId_Nit, DEM_EVENT_STATUS_PASSED);
    }
    if (ErrorId_Sw != 0) /* PRQA S 3356, 3359 */ /* MD_FrIf_3356 */
    { /* PRQA S 3201 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */    
      Dem_ReportErrorStatus(ErrorId_Sw, DEM_EVENT_STATUS_PASSED);
    }
  }
  else
  {
    if (ErrorId_Nit != 0) /* PRQA S 3356, 3359 */ /* MD_FrIf_3356 */
    { /* PRQA S 3201 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */    
      /* FRIF_E_NIT */
      if (   ((ChannelStatus & FRIF_NIT_SYNTAX_ERROR) == FRIF_NIT_SYNTAX_ERROR )
          || ((ChannelStatus & FRIF_NIT_B_VIOLATION)  == FRIF_NIT_B_VIOLATION  )
         ) 
      {
        /* \trace SPEC-30130, SPEC-30035 */
        Dem_ReportErrorStatus(ErrorId_Nit, DEM_EVENT_STATUS_FAILED);
      }
    }
    
    if (ErrorId_Sw != 0) /* PRQA S 3356, 3359 */ /* MD_FrIf_3356 */
    { /* PRQA S 3201 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */    
      /* FRIF_E_SW */
      if (   ((ChannelStatus & FRIF_SW_SYNTAX_ERROR) == FRIF_SW_SYNTAX_ERROR)
          || ((ChannelStatus & FRIF_SW_B_VIOLATION)  == FRIF_SW_B_VIOLATION )
          || ((ChannelStatus & FRIF_SW_TX_CONFLICT)  == FRIF_SW_TX_CONFLICT )
         )
      {
        /* \trace SPEC-30084, SPEC-29889 */
        Dem_ReportErrorStatus(ErrorId_Sw, DEM_EVENT_STATUS_FAILED);
      }
    }
    
    if (ErrorId_Acs != 0) /* PRQA S 3356, 3359 */ /* MD_FrIf_3356 */
    { /* PRQA S 3201 1 */ /* MD_MSR_14.1 */ /*lint -e{506} */    
      /* FRIF_E_ACS */
      if (   ((ChannelStatus & FRIF_ACS_SYNTAX_ERROR) == FRIF_ACS_SYNTAX_ERROR ) 
          || ((ChannelStatus & FRIF_ACS_CONTENT_ERROR)== FRIF_ACS_CONTENT_ERROR) 
          || ((ChannelStatus & FRIF_ACS_B_VIOLATION)  == FRIF_ACS_B_VIOLATION  )  
          || ((ChannelStatus & FRIF_ACS_TX_CONFLICT)  == FRIF_ACS_TX_CONFLICT  )
         ) 
      {
        /* \trace SPEC-29861, SPEC-29933 */
        Dem_ReportErrorStatus(ErrorId_Acs, DEM_EVENT_STATUS_FAILED);
      }
    }
  }
#else
  FRIF_DUMMY_STATEMENT(ClstIdx);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  FRIF_DUMMY_STATEMENT(FrChannel);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  FRIF_DUMMY_STATEMENT(ChannelStatus); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif  
} /* FrIf_CheckChannelStatus() */ /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

/* -----------------------------------------------------------------------------
    &&&~ upperlayer wrapper functions
 ----------------------------------------------------------------------------- */

FUNC(Std_ReturnType,FRIF_CODE) FrIf_TriggerTransmitFunctions(uint8 PduOwner, PduIdType FrTxPduId, P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload, P2VAR(PduLengthType, AUTOMATIC, FRIF_VAR_NOINIT) Length)
{
    Std_ReturnType Result = E_OK;
    PduInfoType PduInfo;
    PduInfo.SduDataPtr = (uint8*) Payload;
    PduInfo.SduLength = *Length;

    switch(PduOwner)
    {
        /* PRQA S 3109 TRIGTRANSMIT */ /* MD_MSR_14.3 */
        case 0: Result = PDUR_FRIFTRIGGERTRANSMIT(FrTxPduId, &PduInfo); break;         /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 1: Result = FRNM_TRIGGERTRANSMIT(FrTxPduId, &PduInfo); break;             /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 2: Result = FRTP_TRIGGERTRANSMIT(FrTxPduId, &PduInfo); break;             /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 3: Result = FRXCP_TRIGGERTRANSMIT(FrTxPduId, &PduInfo); break;            /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 4: Result = E_NOT_OK; break; /* Pdu with PduOwner 'None' -> return E_NOT_OK to prevent Pdu transmission (do nothing) */
        case 5: Result = FRTSYN_TRIGGERTRANSMIT(FrTxPduId, &PduInfo); break;           /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 6: Result = FRARTP_TRIGGERTRANSMIT(FrTxPduId, &PduInfo); break;           /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        default:  Result = E_NOT_OK;
        /* PRQA L:TRIGTRANSMIT *//* MD_MSR_14.3 */
    }
    *Length = PduInfo.SduLength;                                                        /* SBSW_FRIF_PTR_WRT_UNCHANGED */
    return Result;
} /* FrIf_TriggerTransmitFunctions() */ /* PRQA S 6030 */ /* MD_MSR_STCYC */

FUNC(void,FRIF_CODE) FrIf_TxConfirmationFunctions(uint8 PduOwner, PduIdType FrTxPduId)
{
    switch(PduOwner)
    {
        /* PRQA S 3109 TXCONF */ /* MD_MSR_14.3 */
        case 0: PDUR_FRIFTXCONFIRMATION(FrTxPduId); break;
        case 1: FRNM_TXCONFIRMATION(FrTxPduId); break;
        case 2: FRTP_TXCONFIRMATION(FrTxPduId); break;
        case 3: FRXCP_TXCONFIRMATION(FrTxPduId); break;
        case 4: break; /* Pdu with PduOwner 'None' -> do nothing */
        case 5: break; /* Pdu with PduOwner 'FrTSyn' -> do nothing */
        case 6: FRARTP_TXCONFIRMATION(FrTxPduId); break;
        default:  break;
        /* PRQA L:TXCONF *//* MD_MSR_14.3 */
    }
} /* FrIf_TxConfirmationFunctions() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(void,FRIF_CODE) FrIf_RxIndicationFunctions(uint8 PduOwner, PduIdType FrRxPduId, P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload, PduLengthType Length)
{
    PduInfoType PduInfo;
    PduInfo.SduDataPtr = (uint8*) Payload;
     PduInfo.SduLength = Length;

    switch(PduOwner)
    {
        /* PRQA S 3109 RXINDICATE */ /* MD_MSR_14.3 */
        case 0: PDUR_FRIFRXINDICATION(FrRxPduId, &PduInfo); break;                     /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 1: FRNM_RXINDICATION(FrRxPduId, &PduInfo); break;                         /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 2: FRTP_RXINDICATION(FrRxPduId, &PduInfo); break;                         /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 3: FRXCP_RXINDICATION(FrRxPduId, &PduInfo); break;                        /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 4: break; /* Pdu with PduOwner 'None' -> do nothing */
        case 5: FRTSYN_RXINDICATION(FrRxPduId, &PduInfo); break;                       /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        case 6: FRARTP_RXINDICATION(FrRxPduId, &PduInfo); break;                       /* SBSW_FRIF_FCT_CALL_PTR2PDUINFO */
        default:  break;
        /* PRQA L:RXINDICATE *//* MD_MSR_14.3 */
    }
} /* FrIf_RxIndicationFunctions() */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

#define FRIF_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define FRIF_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ Tx PDU Translation Table
 ----------------------------------------------------------------------------- */

CONST(FrIf_TxPduTranslationTupleType, FRIF_CONST) FrIf_TxPduTranslationTable[] =
{
  {0U, 0U} /*  FrIfTxPdu_FR_DBG_EPS, TX INVALID HANDLE  */ , 
  {1U, 0U} /*  FrIfTxPdu_xcpdynamic254_8, TX INVALID HANDLE  */ , 
  {2U, 0U} /*  FrIfTxPdu_xcpdynamic254_7, TX INVALID HANDLE  */ , 
  {3U, 0U} /*  FrIfTxPdu_xcpdynamic254_6, TX INVALID HANDLE  */ , 
  {4U, 0U} /*  FrIfTxPdu_xcpdynamic254_5, TX INVALID HANDLE  */ , 
  {5U, 0U} /*  FrIfTxPdu_xcpdynamic254_4, TX INVALID HANDLE  */ , 
  {6U, 0U} /*  FrIfTxPdu_xcpdynamic254_3, TX INVALID HANDLE  */ , 
  {7U, 0U} /*  FrIfTxPdu_xcpdynamic254_2, TX INVALID HANDLE  */ , 
  {8U, 0U} /*  FrIfTxPdu_xcpdynamic254_1, TX INVALID HANDLE  */ , 
  {9U, 0U} /*  FrIfTxPdu_DISP_CC_EPS, TX INVALID HANDLE  */ , 
  {10U, 0U} /*  FrIfTxPdu_SU_EPS, TX INVALID HANDLE  */ , 
  {11U, 0U} /*  FrIfTxPdu_ST_DIAG_OBD_3_DRDY, TX INVALID HANDLE  */ , 
  {12U, 0U} /*  FrIfTxPdu_ST_EST, TX INVALID HANDLE  */ , 
  {13U, 0U} /*  FrIfTxPdu_dummy32bslave, TX INVALID HANDLE  */ , 
  {14U, 0U} /*  FrIfTxPdu_SVC, TX INVALID HANDLE  */ , 
  {15U, 0U} /*  FrIfTxPdu_TL_ECU_TRNSM_FR_32, TX INVALID HANDLE  */ , 
  {16U, 0U} /*  FrIfTxPdu_AVL_PO_EPS, TX INVALID HANDLE  */ , 
  {17U, 0U} /*  FrIfTxPdu_ENGTORQ_EPS, TX INVALID HANDLE  */ , 
  {18U, 0U} /*  FrIfTxPdu_DT_EST, TX INVALID HANDLE  */ , 
  {19U, 0U} /*  FrIfTxPdu_AVL_STMOM_DV_ACT, TX INVALID HANDLE  */ , 
  {20U, 0U} /*  FrIfTxPdu_AVL_FORC_GRD, TX INVALID HANDLE  */ , 
  {21U, 0U} /*  FrIfTxPdu_dummy16bstatic, TX INVALID HANDLE  */ 
};

/* -----------------------------------------------------------------------------
    &&&~ Tx Pdu Descriptors
 ----------------------------------------------------------------------------- */
 
static CONST(FrIf_TxPduDescriptorType, FRIF_CONST) FrIf_TxPduDescriptors_0[] = 
{
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_FR_DBG_EPS_55c86d41, 58U, 0x00U} /*  FR_DBG_EPS, Index: 0, FrIfTxPduId: 0  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_8_19255f18, 254U, 0x13U} /*  xcpdynamic254_8, Index: 1, FrIfTxPduId: 1  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_7_19255f18, 254U, 0x13U} /*  xcpdynamic254_7, Index: 2, FrIfTxPduId: 2  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_6_19255f18, 254U, 0x13U} /*  xcpdynamic254_6, Index: 3, FrIfTxPduId: 3  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_5_19255f18, 254U, 0x13U} /*  xcpdynamic254_5, Index: 4, FrIfTxPduId: 4  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_4_19255f18, 254U, 0x13U} /*  xcpdynamic254_4, Index: 5, FrIfTxPduId: 5  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_3_19255f18, 254U, 0x13U} /*  xcpdynamic254_3, Index: 6, FrIfTxPduId: 6  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_2_19255f18, 254U, 0x13U} /*  xcpdynamic254_2, Index: 7, FrIfTxPduId: 7  */ , 
  {0UL, XcpConf_XcpTxPdu_xcpdynamic254_1_19255f18, 254U, 0x13U} /*  xcpdynamic254_1, Index: 8, FrIfTxPduId: 8  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_DISP_CC_EPS_55c86d41, 5U, 0x10U} /*  DISP_CC_EPS, Index: 9, FrIfTxPduId: 9  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_SU_EPS_55c86d41, 8U, 0x10U} /*  SU_EPS, Index: 10, FrIfTxPduId: 10  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_DIAG_OBD_3_DRDY_55c86d41, 8U, 0x10U} /*  ST_DIAG_OBD_3_DRDY, Index: 11, FrIfTxPduId: 11  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_ST_EST_55c86d41, 5U, 0x10U} /*  ST_EST, Index: 12, FrIfTxPduId: 12  */ , 
  {0UL, XcpConf_XcpTxPdu_dummy32bslave_19255f18, 32U, 0x13U} /*  dummy32bslave, Index: 13, FrIfTxPduId: 13  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_SVC_fbd80461_Out, 8U, 0x10U} /*  SVC_Out, Index: 14, FrIfTxPduId: 14  */ , 
  {0UL, FrTpConf_FrTpTxPdu_FrTpTxPduTRNSM, 32U, 0x12U} /*  TL_ECU_TRNSM_FR_32, Index: 15, FrIfTxPduId: 15  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_PO_EPS_55c86d41, 8U, 0x00U} /*  AVL_PO_EPS, Index: 16, FrIfTxPduId: 16  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_ENGTORQ_EPS_55c86d41, 8U, 0x00U} /*  ENGTORQ_EPS, Index: 17, FrIfTxPduId: 17  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_DT_EST_55c86d41, 16U, 0x00U} /*  DT_EST, Index: 18, FrIfTxPduId: 18  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_STMOM_DV_ACT_55c86d41, 4U, 0x00U} /*  AVL_STMOM_DV_ACT, Index: 19, FrIfTxPduId: 19  */ , 
  {0UL, PduRConf_PduRDestPdu_DST_Fr_pduTrig_AVL_FORC_GRD_55c86d41, 5U, 0x00U} /*  AVL_FORC_GRD, Index: 20, FrIfTxPduId: 20  */ , 
  {0UL, XcpConf_XcpTxPdu_dummy16bstatic_19255f18, 16U, 0x13U} /*  dummy16bstatic, Index: 21, FrIfTxPduId: 21  */ 
};

/* -----------------------------------------------------------------------------
    &&&~ Tx Frame Layout Elements
 ----------------------------------------------------------------------------- */

static CONST(FrIf_FrameLayoutElementType, FRIF_CONST) FrIf_TxFrameLayoutElements_0[] = 
{
  {0UL, 0U, 0U, 0x00U} /*  p2fmap_FR_DBG_EPS  */ , 
  {1UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_8  */ , 
  {2UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_7  */ , 
  {3UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_6  */ , 
  {4UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_5  */ , 
  {5UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_4  */ , 
  {6UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_3  */ , 
  {7UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_2  */ , 
  {8UL, 0U, 0U, 0x00U} /*  p2fmap_xcpdynamic254_1  */ , 
  {9UL, 0U, 0U, 0x00U} /*  p2fmap_DISP_CC_EPS  */ , 
  {10UL, 0U, 0U, 0x00U} /*  p2fmap_SU_EPS  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_ST_DIAG_OBD_3_DRDY  */ , 
  {12UL, 0U, 0U, 0x00U} /*  p2fmap_ST_EST  */ , 
  {13UL, 0U, 0U, 0x00U} /*  p2fmap_dummy32bslave  */ , 
  {14UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {15UL, 0U, 0U, 0x00U} /*  p2fmap_TL_ECU_TRNSM_FR_32  */ , 
  {16UL, 0U, 0U, 0x00U} /*  p2fmap_AVL_PO_EPS  */ , 
  {17UL, 8U, 0U, 0x00U} /*  p2fmap_ENGTORQ_EPS  */ , 
  {18UL, 0U, 0U, 0x00U} /*  p2fmap_DT_EST  */ , 
  {19UL, 0U, 0U, 0x00U} /*  p2fmap_AVL_STMOM_DV_ACT  */ , 
  {20UL, 8U, 0U, 0x00U} /*  p2fmap_AVL_FORC_GRD  */ , 
  {21UL, 0U, 0U, 0x00U} /*  p2fmap_dummy16bstatic  */ , 
  {21UL, 0U, 0U, 0x00U} /*  p2fmap_dummy16bstatic  */ , 
  {21UL, 0U, 0U, 0x00U} /*  p2fmap_dummy16bstatic  */ , 
  {21UL, 0U, 0U, 0x00U} /*  p2fmap_dummy16bstatic  */ , 
  {21UL, 0U, 0U, 0x00U} /*  p2fmap_dummy16bstatic  */ 
};


/* -----------------------------------------------------------------------------
    &&&~ Tx Frame Descriptors
 ----------------------------------------------------------------------------- */
static CONST(FrIf_FrameDescriptorType, FRIF_CONST) FrIf_TxFrameDescriptors_0[] = 
{
  {0U, 1U, 58U, 0x00U} /*  frTrig_31501_S_315_B_0_R_1_ChA_OUT  */ , 
  {1U, 1U, 254U, 0x01U} /*  frTrig_30101_S_301_B_0_R_1_ChA_OUT  */ , 
  {2U, 1U, 254U, 0x01U} /*  frTrig_30001_S_300_B_0_R_1_ChA_OUT  */ , 
  {3U, 1U, 254U, 0x01U} /*  frTrig_29901_S_299_B_0_R_1_ChA_OUT  */ , 
  {4U, 1U, 254U, 0x01U} /*  frTrig_29801_S_298_B_0_R_1_ChA_OUT  */ , 
  {5U, 1U, 254U, 0x01U} /*  frTrig_29701_S_297_B_0_R_1_ChA_OUT  */ , 
  {6U, 1U, 254U, 0x01U} /*  frTrig_29601_S_296_B_0_R_1_ChA_OUT  */ , 
  {7U, 1U, 254U, 0x01U} /*  frTrig_29501_S_295_B_0_R_1_ChA_OUT  */ , 
  {8U, 1U, 254U, 0x01U} /*  frTrig_29401_S_294_B_0_R_1_ChA_OUT  */ , 
  {9U, 1U, 6U, 0x01U} /*  frTrig_27424_S_274_B_2_R_4_ChA_OUT  */ , 
  {10U, 1U, 8U, 0x01U} /*  frTrig_27408_S_274_B_0_R_8_ChA_OUT  */ , 
  {11U, 1U, 8U, 0x01U} /*  frTrig_2481032_S_248_B_10_R_32_ChA_OUT  */ , 
  {12U, 1U, 6U, 0x01U} /*  frTrig_23412_S_234_B_1_R_2_ChA_OUT  */ , 
  {13U, 1U, 32U, 0x01U} /*  frTrig_22001_S_220_B_0_R_1_ChA_OUT  */ , 
  {14U, 1U, 8U, 0x01U} /*  frTrig_216916_S_216_B_9_R_16_ChA_OUT  */ , 
  {15U, 1U, 32U, 0x01U} /*  frTrig_18301_S_183_B_0_R_1_ChA_OUT  */ , 
  {16U, 2U, 16U, 0x00U} /*  frTrig_5102_S_51_B_0_R_2_ChA_OUT  */ , 
  {18U, 1U, 16U, 0x00U} /*  frTrig_4912_S_49_B_1_R_2_ChA_OUT  */ , 
  {19U, 2U, 16U, 0x00U} /*  frTrig_4902_S_49_B_0_R_2_ChA_OUT  */ , 
  {21U, 1U, 16U, 0x01U} /*  frTrig_1201_S_12_B_0_R_1_ChA_OUT  */ , 
  {22U, 1U, 16U, 0x01U} /*  frTrig_1101_S_11_B_0_R_1_ChA_OUT  */ , 
  {23U, 1U, 16U, 0x01U} /*  frTrig_1001_S_10_B_0_R_1_ChA_OUT  */ , 
  {24U, 1U, 16U, 0x01U} /*  frTrig_901_S_9_B_0_R_1_ChA_OUT  */ , 
  {25U, 1U, 16U, 0x01U} /*  frTrig_801_S_8_B_0_R_1_ChA_OUT  */ 
};

/* -----------------------------------------------------------------------------
    &&&~ Rx Pdu Descriptors
 ----------------------------------------------------------------------------- */

static CONST(FrIf_RxPduDescriptorType, FRIF_CONST) FrIf_RxPduDescriptors_0[] = 
{
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_RELATIVZEIT_55c86d41, 6U, 0x00U} /*  RELATIVZEIT  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_KILOMETERSTAND_55c86d41, 8U, 0x00U} /*  KILOMETERSTAND  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FZZSTD_55c86d41, 8U, 0x00U} /*  FZZSTD  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_FAHRGESTELLNUMMER_55c86d41, 7U, 0x00U} /*  FAHRGESTELLNUMMER  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CTR_VIB_STW_DISP_EXMI_SP2015_55c86d41, 8U, 0x00U} /*  CTR_VIB_STW_DISP_EXMI_SP2015  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_A_TEMP_55c86d41, 2U, 0x00U} /*  A_TEMP  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CTR_DIAG_OBD_DRDY_55c86d41, 2U, 0x00U} /*  CTR_DIAG_OBD_DRDY  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_DIAG_OBD_ENG_55c86d41, 7U, 0x00U} /*  DIAG_OBD_ENG  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SECU_FAHRGESTELLNUMMER_55c86d41, 8U, 0x00U} /*  SECU_FAHRGESTELLNUMMER  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_ENERG_GEN_55c86d41, 8U, 0x00U} /*  ST_ENERG_GEN  */ , 
  {XcpConf_XcpRxPdu_dummy32bmaster_19255f18, 32U, 0x03U} /*  dummy32bmaster  */ , 
  {PduRConf_PduRSrcPdu_SRC_SVC_fbd80461_In, 8U, 0x00U} /*  SVC_In  */ , 
  {FrTpConf_FrTpRxPdu_FrTpRxPduBRC, 32U, 0x02U} /*  TL_BRC_FR_32  */ , 
  {FrTpConf_FrTpRxPdu_FrTpRxPduTRNSM, 254U, 0x02U} /*  TL_MST_GW_TRNSM_FR_254  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_CON_VEH_55c86d41, 8U, 0x00U} /*  CON_VEH  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENSU_SFY_55c86d41, 8U, 0x00U} /*  ENSU_SFY  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_CENG_55c86d41, 8U, 0x00U} /*  ST_CENG  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_STEA_OFFS_55c86d41, 8U, 0x00U} /*  STEA_OFFS  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_OFFS_QUAD_EPS_55c86d41, 5U, 0x00U} /*  OFFS_QUAD_EPS  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ERRM_BN_U_55c86d41, 2U, 0x00U} /*  ERRM_BN_U  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_QTA_STRMOM_DV_55c86d41, 8U, 0x00U} /*  TAR_QTA_STRMOM_DV  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_STMOM_DV_ACT_55c86d41, 8U, 0x00U} /*  TAR_STMOM_DV_ACT  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ENERG_DGR_DRDY_55c86d41, 8U, 0x00U} /*  ENERG_DGR_DRDY  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_TAR_ESTP_VIRT_FTAX_55c86d41, 8U, 0x00U} /*  TAR_ESTP_VIRT_FTAX  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_VYAW_VEH_55c86d41, 6U, 0x00U} /*  VYAW_VEH  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ACLNY_MASSCNTR_55c86d41, 6U, 0x00U} /*  ACLNY_MASSCNTR  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_V_VEH_55c86d41, 5U, 0x00U} /*  V_VEH  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_SU_CLE_DRDY_DXP_55c86d41, 8U, 0x00U} /*  SU_CLE_DRDY_DXP  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_ST_STAB_DSC_55c86d41, 8U, 0x00U} /*  ST_STAB_DSC  */ , 
  {PduRConf_PduRSrcPdu_SRC_Fr_pduTrig_AVL_RPM_WHL_55c86d41, 12U, 0x00U} /*  AVL_RPM_WHL  */ 
};


/* -----------------------------------------------------------------------------
    &&&~ Rx Frame Layout Elements
 ----------------------------------------------------------------------------- */

static CONST(FrIf_FrameLayoutElementType, FRIF_CONST) FrIf_RxFrameLayoutElements_0[] = 
{
  {0UL, 0U, 0U, 0x00U} /*  p2fmap_RELATIVZEIT  */ , 
  {1UL, 0U, 0U, 0x00U} /*  p2fmap_KILOMETERSTAND  */ , 
  {2UL, 0U, 0U, 0x00U} /*  p2fmap_FZZSTD  */ , 
  {3UL, 0U, 0U, 0x00U} /*  p2fmap_FAHRGESTELLNUMMER  */ , 
  {4UL, 0U, 0U, 0x00U} /*  p2fmap_CTR_VIB_STW_DISP_EXMI_SP2015  */ , 
  {5UL, 0U, 0U, 0x00U} /*  p2fmap_A_TEMP  */ , 
  {6UL, 0U, 0U, 0x00U} /*  p2fmap_CTR_DIAG_OBD_DRDY  */ , 
  {7UL, 0U, 0U, 0x00U} /*  p2fmap_DIAG_OBD_ENG  */ , 
  {8UL, 0U, 0U, 0x00U} /*  p2fmap_SECU_FAHRGESTELLNUMMER  */ , 
  {9UL, 0U, 0U, 0x00U} /*  p2fmap_ST_ENERG_GEN  */ , 
  {10UL, 0U, 0U, 0x00U} /*  p2fmap_dummy32bmaster  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {11UL, 0U, 0U, 0x00U} /*  p2fmap_SVC  */ , 
  {12UL, 0U, 0U, 0x00U} /*  p2fmap_TL_BRC_FR_32  */ , 
  {12UL, 0U, 0U, 0x00U} /*  p2fmap_TL_BRC_FR_32  */ , 
  {12UL, 0U, 0U, 0x00U} /*  p2fmap_TL_BRC_FR_32  */ , 
  {12UL, 0U, 0U, 0x00U} /*  p2fmap_TL_BRC_FR_32  */ , 
  {12UL, 0U, 0U, 0x00U} /*  p2fmap_TL_BRC_FR_32  */ , 
  {13UL, 0U, 0U, 0x00U} /*  p2fmap_TL_MST_GW_TRNSM_FR_254  */ , 
  {14UL, 0U, 0U, 0x00U} /*  p2fmap_CON_VEH  */ , 
  {15UL, 0U, 0U, 0x00U} /*  p2fmap_ENSU_SFY  */ , 
  {16UL, 0U, 0U, 0x00U} /*  p2fmap_ST_CENG  */ , 
  {17UL, 0U, 0U, 0x00U} /*  p2fmap_STEA_OFFS  */ , 
  {18UL, 0U, 0U, 0x00U} /*  p2fmap_OFFS_QUAD_EPS  */ , 
  {19UL, 0U, 0U, 0x00U} /*  p2fmap_ERRM_BN_U  */ , 
  {20UL, 0U, 0U, 0x00U} /*  p2fmap_TAR_QTA_STRMOM_DV  */ , 
  {21UL, 8U, 0U, 0x00U} /*  p2fmap_TAR_STMOM_DV_ACT  */ , 
  {22UL, 0U, 0U, 0x00U} /*  p2fmap_ENERG_DGR_DRDY  */ , 
  {23UL, 0U, 0U, 0x00U} /*  p2fmap_TAR_ESTP_VIRT_FTAX  */ , 
  {24UL, 8U, 0U, 0x00U} /*  p2fmap_VYAW_VEH  */ , 
  {25UL, 8U, 0U, 0x00U} /*  p2fmap_ACLNY_MASSCNTR  */ , 
  {26UL, 0U, 0U, 0x00U} /*  p2fmap_V_VEH  */ , 
  {27UL, 0U, 0U, 0x00U} /*  p2fmap_SU_CLE_DRDY_DXP  */ , 
  {28UL, 0U, 0U, 0x00U} /*  p2fmap_ST_STAB_DSC  */ , 
  {29UL, 0U, 0U, 0x00U} /*  p2fmap_AVL_RPM_WHL  */ 
};


/* -----------------------------------------------------------------------------
    &&&~ Rx Frame Descriptors
 ----------------------------------------------------------------------------- */

static CONST(FrIf_FrameDescriptorType, FRIF_CONST) FrIf_RxFrameDescriptors_0[] = 
{
  {0U, 1U, 6U, 0x00U} /*  frTrig_27628_S_276_B_2_R_8_ChA_IN  */ , 
  {1U, 1U, 8U, 0x00U} /*  frTrig_27648_S_276_B_4_R_8_ChA_IN  */ , 
  {2U, 1U, 8U, 0x00U} /*  frTrig_27518_S_275_B_1_R_8_ChA_IN  */ , 
  {3U, 1U, 8U, 0x00U} /*  frTrig_27578_S_275_B_7_R_8_ChA_IN  */ , 
  {4U, 1U, 16U, 0x00U} /*  frTrig_26924_S_269_B_2_R_4_ChA_IN  */ , 
  {5U, 1U, 2U, 0x00U} /*  frTrig_25214_S_252_B_1_R_4_ChA_IN  */ , 
  {6U, 1U, 2U, 0x00U} /*  frTrig_24702_S_247_B_0_R_2_ChA_IN  */ , 
  {7U, 1U, 8U, 0x00U} /*  frTrig_24712_S_247_B_1_R_2_ChA_IN  */ , 
  {8U, 1U, 8U, 0x00U} /*  frTrig_24404_S_244_B_0_R_4_ChA_IN  */ , 
  {9U, 1U, 8U, 0x00U} /*  frTrig_23212_S_232_B_1_R_2_ChA_IN  */ , 
  {10U, 1U, 32U, 0x00U} /*  frTrig_21901_S_219_B_0_R_1_ChA_IN  */ , 
  {11U, 1U, 8U, 0x00U} /*  frTrig_216616_S_216_B_6_R_16_ChA_IN  */ , 
  {12U, 1U, 8U, 0x00U} /*  frTrig_216716_S_216_B_7_R_16_ChA_IN  */ , 
  {13U, 1U, 8U, 0x00U} /*  frTrig_2161016_S_216_B_10_R_16_ChA_IN  */ , 
  {14U, 1U, 8U, 0x00U} /*  frTrig_2161216_S_216_B_12_R_16_ChA_IN  */ , 
  {15U, 1U, 8U, 0x00U} /*  frTrig_2161316_S_216_B_13_R_16_ChA_IN  */ , 
  {16U, 1U, 8U, 0x00U} /*  frTrig_2161416_S_216_B_14_R_16_ChA_IN  */ , 
  {17U, 1U, 8U, 0x00U} /*  frTrig_2161516_S_216_B_15_R_16_ChA_IN  */ , 
  {18U, 1U, 8U, 0x00U} /*  frTrig_215216_S_215_B_2_R_16_ChA_IN  */ , 
  {19U, 1U, 8U, 0x00U} /*  frTrig_215516_S_215_B_5_R_16_ChA_IN  */ , 
  {20U, 1U, 8U, 0x00U} /*  frTrig_215616_S_215_B_6_R_16_ChA_IN  */ , 
  {21U, 1U, 8U, 0x00U} /*  frTrig_215916_S_215_B_9_R_16_ChA_IN  */ , 
  {22U, 1U, 8U, 0x00U} /*  frTrig_2151016_S_215_B_10_R_16_ChA_IN  */ , 
  {23U, 1U, 8U, 0x00U} /*  frTrig_21434_S_214_B_3_R_4_ChA_IN  */ , 
  {24U, 1U, 32U, 0x00U} /*  frTrig_21301_S_213_B_0_R_1_ChA_IN  */ , 
  {25U, 1U, 32U, 0x00U} /*  frTrig_21201_S_212_B_0_R_1_ChA_IN  */ , 
  {26U, 1U, 32U, 0x00U} /*  frTrig_21101_S_211_B_0_R_1_ChA_IN  */ , 
  {27U, 1U, 32U, 0x00U} /*  frTrig_21001_S_210_B_0_R_1_ChA_IN  */ , 
  {28U, 1U, 32U, 0x00U} /*  frTrig_20901_S_209_B_0_R_1_ChA_IN  */ , 
  {29U, 1U, 254U, 0x00U} /*  frTrig_14701_S_147_B_0_R_1_ChA_IN  */ , 
  {30U, 1U, 8U, 0x00U} /*  frTrig_12112_S_121_B_1_R_2_ChA_IN  */ , 
  {31U, 1U, 8U, 0x00U} /*  frTrig_11912_S_119_B_1_R_2_ChA_IN  */ , 
  {32U, 1U, 8U, 0x00U} /*  frTrig_11702_S_117_B_0_R_2_ChA_IN  */ , 
  {33U, 1U, 8U, 0x00U} /*  frTrig_10802_S_108_B_0_R_2_ChA_IN  */ , 
  {34U, 1U, 6U, 0x00U} /*  frTrig_10701_S_107_B_0_R_1_ChA_IN  */ , 
  {35U, 1U, 2U, 0x00U} /*  frTrig_10401_S_104_B_0_R_1_ChA_IN  */ , 
  {36U, 2U, 16U, 0x00U} /*  frTrig_6802_S_68_B_0_R_2_ChA_IN  */ , 
  {38U, 1U, 8U, 0x00U} /*  frTrig_6812_S_68_B_1_R_2_ChA_IN  */ , 
  {39U, 1U, 8U, 0x00U} /*  frTrig_6512_S_65_B_1_R_2_ChA_IN  */ , 
  {40U, 1U, 14U, 0x00U} /*  frTrig_5602_S_56_B_0_R_2_ChA_IN  */ , 
  {41U, 1U, 14U, 0x00U} /*  frTrig_5502_S_55_B_0_R_2_ChA_IN  */ , 
  {42U, 1U, 16U, 0x00U} /*  frTrig_5534_S_55_B_3_R_4_ChA_IN  */ , 
  {43U, 1U, 16U, 0x00U} /*  frTrig_5338_S_53_B_3_R_8_ChA_IN  */ , 
  {44U, 1U, 16U, 0x00U} /*  frTrig_4712_S_47_B_1_R_2_ChA_IN  */ , 
  {45U, 1U, 12U, 0x00U} /*  frTrig_4601_S_46_B_0_R_1_ChA_IN  */ 
};


/* -----------------------------------------------------------------------------
    &&&~ Transceiver Descriptors
 ----------------------------------------------------------------------------- */
 
CONST(FrIf_TransceiverDescriptorType, FRIF_CONST) FrIf_TransceiverDescriptors[] = 
{
  {0U, 0U} /*  /ActiveEcuC/FrTrcv/FrTrcvChannel  */ , 
  {255U, 255U} /*  Dummy FrTrcvDescriptor for ChB  */ 
};


/* -----------------------------------------------------------------------------
    &&&~ Task Schedule Data
 ----------------------------------------------------------------------------- */

static CONST(FrIf_JobDescriptorType, FRIF_CONST) FrIf_JobDescriptors_0[] = 
{
  {
    17U /*  StartTimeInMacroTicks  */ , 
    1848U /*  StartTimeProtectedRange  */ , 
    3628U /*  EndTimeProtectedRange  */ , 
    1363U /*  MaxDelay  */ , 
    0U /*  MinColumnNumber  */ , 
    15U /*  MaxColumnNumber  */ , 
    1U /*  MinTxConfJobNo  */ , 
    1U /*  MaxTxConfJobNo  */ , 
    20U /*  JobConfig  */ 
  } /*  FrIf_RxJob_02  */ , 
  {
    455U /*  StartTimeInMacroTicks  */ , 
    1848U /*  StartTimeProtectedRange  */ , 
    3628U /*  EndTimeProtectedRange  */ , 
    909U /*  MaxDelay  */ , 
    0U /*  MinColumnNumber  */ , 
    12U /*  MaxColumnNumber  */ , 
    255U /*  MinTxConfJobNo  */ , 
    254U /*  MaxTxConfJobNo  */ , 
    0U /*  JobConfig  */ 
  } /*  FrIf_TxJob_02  */ , 
  {
    1842U /*  StartTimeInMacroTicks  */ , 
    24U /*  StartTimeProtectedRange  */ , 
    1824U /*  EndTimeProtectedRange  */ , 
    1363U /*  MaxDelay  */ , 
    16U /*  MinColumnNumber  */ , 
    21U /*  MaxColumnNumber  */ , 
    3U /*  MinTxConfJobNo  */ , 
    3U /*  MaxTxConfJobNo  */ , 
    4U /*  JobConfig  */ 
  } /*  FrIf_RxJob_01  */ , 
  {
    2273U /*  StartTimeInMacroTicks  */ , 
    24U /*  StartTimeProtectedRange  */ , 
    1824U /*  EndTimeProtectedRange  */ , 
    909U /*  MaxDelay  */ , 
    13U /*  MinColumnNumber  */ , 
    19U /*  MaxColumnNumber  */ , 
    255U /*  MinTxConfJobNo  */ , 
    254U /*  MaxTxConfJobNo  */ , 
    0U /*  JobConfig  */ 
  } /*  FrIf_TxJob_01  */ 
};


/* -----------------------------------------------------------------------------
    &&&~ Rx Handle tables
 ----------------------------------------------------------------------------- */

/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_0[] = 
{
  29U /*  frTrig_14701_S_147_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_1[] = 
{
  28U /*  frTrig_20901_S_209_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_2[] = 
{
  27U /*  frTrig_21001_S_210_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_3[] = 
{
  26U /*  frTrig_21101_S_211_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_4[] = 
{
  25U /*  frTrig_21201_S_212_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_5[] = 
{
  24U /*  frTrig_21301_S_213_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_6[] = 
{
  17U /*  frTrig_2161516_S_216_B_15_R_16_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  18U /*  frTrig_215216_S_215_B_2_R_16_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  19U /*  frTrig_215516_S_215_B_5_R_16_ChA_IN  */ , 
  11U /*  frTrig_216616_S_216_B_6_R_16_ChA_IN  */ , 
  12U /*  frTrig_216716_S_216_B_7_R_16_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  21U /*  frTrig_215916_S_215_B_9_R_16_ChA_IN  */ , 
  22U /*  frTrig_2151016_S_215_B_10_R_16_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  14U /*  frTrig_2161216_S_216_B_12_R_16_ChA_IN  */ , 
  15U /*  frTrig_2161316_S_216_B_13_R_16_ChA_IN  */ , 
  16U /*  frTrig_2161416_S_216_B_14_R_16_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_7[] = 
{
  3U /*  frTrig_27578_S_275_B_7_R_8_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  2U /*  frTrig_27518_S_275_B_1_R_8_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  1U /*  frTrig_27648_S_276_B_4_R_8_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  20U /*  frTrig_215616_S_215_B_6_R_16_ChA_IN  */ , 
  3U /*  frTrig_27578_S_275_B_7_R_8_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  2U /*  frTrig_27518_S_275_B_1_R_8_ChA_IN  */ , 
  13U /*  frTrig_2161016_S_216_B_10_R_16_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  1U /*  frTrig_27648_S_276_B_4_R_8_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  45U /*  RX INVALID HANDLE  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_8[] = 
{
  23U /*  frTrig_21434_S_214_B_3_R_4_ChA_IN  */ , 
  8U /*  frTrig_24404_S_244_B_0_R_4_ChA_IN  */ , 
  5U /*  frTrig_25214_S_252_B_1_R_4_ChA_IN  */ , 
  0U /*  frTrig_27628_S_276_B_2_R_8_ChA_IN  */ , 
  23U /*  frTrig_21434_S_214_B_3_R_4_ChA_IN  */ , 
  8U /*  frTrig_24404_S_244_B_0_R_4_ChA_IN  */ , 
  5U /*  frTrig_25214_S_252_B_1_R_4_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_9[] = 
{
  31U /*  frTrig_11912_S_119_B_1_R_2_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  31U /*  frTrig_11912_S_119_B_1_R_2_ChA_IN  */ , 
  4U /*  frTrig_26924_S_269_B_2_R_4_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_10[] = 
{
  30U /*  frTrig_12112_S_121_B_1_R_2_ChA_IN  */ , 
  6U /*  frTrig_24702_S_247_B_0_R_2_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_11[] = 
{
  7U /*  frTrig_24712_S_247_B_1_R_2_ChA_IN  */ , 
  32U /*  frTrig_11702_S_117_B_0_R_2_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_12[] = 
{
  9U /*  frTrig_23212_S_232_B_1_R_2_ChA_IN  */ , 
  33U /*  frTrig_10802_S_108_B_0_R_2_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_13[] = 
{
  10U /*  frTrig_21901_S_219_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_14[] = 
{
  34U /*  frTrig_10701_S_107_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_15[] = 
{
  35U /*  frTrig_10401_S_104_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_16[] = 
{
  39U /*  frTrig_5602_S_56_B_0_R_2_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  39U /*  frTrig_5602_S_56_B_0_R_2_ChA_IN  */ , 
  42U /*  frTrig_5338_S_53_B_3_R_8_ChA_IN  */ , 
  39U /*  frTrig_5602_S_56_B_0_R_2_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  39U /*  frTrig_5602_S_56_B_0_R_2_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ 
} /*  FrIf_RxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_17[] = 
{
  40U /*  frTrig_5502_S_55_B_0_R_2_ChA_IN  */ , 
  45U /*  RX INVALID HANDLE  */ , 
  40U /*  frTrig_5502_S_55_B_0_R_2_ChA_IN  */ , 
  41U /*  frTrig_5534_S_55_B_3_R_4_ChA_IN  */ 
} /*  FrIf_RxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_18[] = 
{
  36U /*  frTrig_6802_S_68_B_0_R_2_ChA_IN  */ , 
  43U /*  frTrig_4712_S_47_B_1_R_2_ChA_IN  */ 
} /*  FrIf_RxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_19[] = 
{
  45U /*  RX INVALID HANDLE  */ , 
  38U /*  frTrig_6512_S_65_B_1_R_2_ChA_IN  */ 
} /*  FrIf_RxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_20[] = 
{
  45U /*  RX INVALID HANDLE  */ , 
  37U /*  frTrig_6812_S_68_B_1_R_2_ChA_IN  */ 
} /*  FrIf_RxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_RxHandleType, FRIF_CONST) RxHandles_0_21[] = 
{
  44U /*  frTrig_4601_S_46_B_0_R_1_ChA_IN  */ 
} /*  FrIf_RxJob_01  */ ;


/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONSTP2CONST(FrIf_RxHandleType, FRIF_CONST, FRIF_CONST) FrIf_RxHandles_0[] = 
{
  RxHandles_0_0
  ,RxHandles_0_1
  ,RxHandles_0_2
  ,RxHandles_0_3
  ,RxHandles_0_4
  ,RxHandles_0_5
  ,RxHandles_0_6
  ,RxHandles_0_7
  ,RxHandles_0_8
  ,RxHandles_0_9
  ,RxHandles_0_10
  ,RxHandles_0_11
  ,RxHandles_0_12
  ,RxHandles_0_13
  ,RxHandles_0_14
  ,RxHandles_0_15
  ,RxHandles_0_16
  ,RxHandles_0_17
  ,RxHandles_0_18
  ,RxHandles_0_19
  ,RxHandles_0_20
  ,RxHandles_0_21
};


/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_CycleMaskType, FRIF_CONST) FrIf_RxCycleMasks_0[] = 
{
  0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 15U
  , 15U
  , 7U
  , 3U
  , 1U
  , 1U
  , 1U
  , 0U
  , 0U
  , 0U
  , 7U
  , 3U
  , 1U
  , 1U
  , 1U
  , 0U
};


/* -----------------------------------------------------------------------------
    &&&~ Tx Handle tables
 ----------------------------------------------------------------------------- */

/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_0[] = 
{
  15U /*  frTrig_18301_S_183_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_1[] = 
{
  10U /*  frTrig_27408_S_274_B_0_R_8_ChA_OUT  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  10U /*  frTrig_27408_S_274_B_0_R_8_ChA_OUT  */ , 
  14U /*  frTrig_216916_S_216_B_9_R_16_ChA_OUT  */ , 
  11U /*  frTrig_2481032_S_248_B_10_R_32_ChA_OUT  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  10U /*  frTrig_27408_S_274_B_0_R_8_ChA_OUT  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  10U /*  frTrig_27408_S_274_B_0_R_8_ChA_OUT  */ , 
  14U /*  frTrig_216916_S_216_B_9_R_16_ChA_OUT  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ , 
  24U /*  TX INVALID HANDLE  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_2[] = 
{
  24U /*  TX INVALID HANDLE  */ , 
  12U /*  frTrig_23412_S_234_B_1_R_2_ChA_OUT  */ , 
  9U /*  frTrig_27424_S_274_B_2_R_4_ChA_OUT  */ , 
  12U /*  frTrig_23412_S_234_B_1_R_2_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_3[] = 
{
  13U /*  frTrig_22001_S_220_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_4[] = 
{
  0U /*  frTrig_31501_S_315_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_5[] = 
{
  3U /*  frTrig_29901_S_299_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_6[] = 
{
  5U /*  frTrig_29701_S_297_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_7[] = 
{
  4U /*  frTrig_29801_S_298_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_8[] = 
{
  6U /*  frTrig_29601_S_296_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_9[] = 
{
  2U /*  frTrig_30001_S_300_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_10[] = 
{
  7U /*  frTrig_29501_S_295_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_11[] = 
{
  8U /*  frTrig_29401_S_294_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_12[] = 
{
  1U /*  frTrig_30101_S_301_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_02  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_13[] = 
{
  17U /*  frTrig_4912_S_49_B_1_R_2_ChA_OUT  */ , 
  18U /*  frTrig_4902_S_49_B_0_R_2_ChA_OUT  */ 
} /*  FrIf_TxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_14[] = 
{
  24U /*  TX INVALID HANDLE  */ , 
  16U /*  frTrig_5102_S_51_B_0_R_2_ChA_OUT  */ 
} /*  FrIf_TxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_15[] = 
{
  19U /*  frTrig_1201_S_12_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_16[] = 
{
  21U /*  frTrig_1001_S_10_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_17[] = 
{
  23U /*  frTrig_801_S_8_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_18[] = 
{
  22U /*  frTrig_901_S_9_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_01  */ ;
/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_TxHandleType, FRIF_CONST) TxHandles_0_19[] = 
{
  20U /*  frTrig_1101_S_11_B_0_R_1_ChA_OUT  */ 
} /*  FrIf_TxJob_01  */ ;


/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONSTP2CONST(FrIf_TxHandleType, FRIF_CONST, FRIF_CONST) FrIf_TxHandles_0[] = 
{ 
  TxHandles_0_0
  ,TxHandles_0_1
  ,TxHandles_0_2
  ,TxHandles_0_3
  ,TxHandles_0_4
  ,TxHandles_0_5
  ,TxHandles_0_6
  ,TxHandles_0_7
  ,TxHandles_0_8
  ,TxHandles_0_9
  ,TxHandles_0_10
  ,TxHandles_0_11
  ,TxHandles_0_12
  ,TxHandles_0_13
  ,TxHandles_0_14
  ,TxHandles_0_15
  ,TxHandles_0_16
  ,TxHandles_0_17
  ,TxHandles_0_18
  ,TxHandles_0_19
};


/* PRQA S 3408 1 */ /* MD_FrIf_3408 */
CONST(FrIf_CycleMaskType, FRIF_CONST) FrIf_TxCycleMasks_0[] = 
{
  0U
  , 31U
  , 3U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
  , 1U
  , 1U
  , 0U
  , 0U
  , 0U
  , 0U
  , 0U
};


#define FRIF_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#define FRIF_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ Constants
 ----------------------------------------------------------------------------- */

CONST(FrIf_ConfigType, FRIF_CONST) FrIf_Config = 0u;


CONSTP2CONST(FrIf_TxPduDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2TxPduDescriptors[] =
{
  FrIf_TxPduDescriptors_0 /*  EPS_A_FlexRay  */ 
};


CONSTP2CONST(FrIf_RxPduDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2RxPduDescriptors[] =
{
  FrIf_RxPduDescriptors_0 /*  EPS_A_FlexRay  */ 
};


CONSTP2CONST(FrIf_FrameLayoutElementType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2TxFrameLayoutElements[] =
{
  FrIf_TxFrameLayoutElements_0 /*  EPS_A_FlexRay  */ 
};


CONSTP2CONST(FrIf_FrameLayoutElementType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2RxFrameLayoutElements[] =
{
  FrIf_RxFrameLayoutElements_0 /*  EPS_A_FlexRay  */ 
};


CONSTP2CONST(FrIf_FrameDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2TxFrameDescriptors[] =
{
  FrIf_TxFrameDescriptors_0 /*  EPS_A_FlexRay  */ 
};


CONSTP2CONST(FrIf_FrameDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Ctrl2RxFrameDescriptors[] =
{
  FrIf_RxFrameDescriptors_0 /*  EPS_A_FlexRay  */ 
};


CONST(PduIdType, FRIF_CONST) FrIf_Ctrl2MaxTxPduId[] = 
{
  21U /*  EPS_A_FlexRay  */ 
};


CONST(FrIf_TxHandleType, FRIF_CONST) FrIf_Ctrl2MaxTxFrameId[] = 
{
  23U /*  EPS_A_FlexRay  */ 
};


CONST(FrIf_TxHandleType, FRIF_CONST) FrIf_Ctrl2InvalidTxHandle[] = 
{
  24U /*  EPS_A_FlexRay  */ 
};


CONST(FrIf_RxHandleType, FRIF_CONST) FrIf_Ctrl2InvalidRxHandle[] = 
{
  45U /*  EPS_A_FlexRay  */ 
};


CONSTP2VAR(FrIf_NumberOfPduType, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2TxPduWasSentFlags[] = 
{
  FrIf_TxPduWasSentFlags_0 /*  EPS_A_FlexRay  */ 
};


CONST(PduIdType, FRIF_CONST) FrIf_Ctrl2NumberOfTxRequestCounters[] = 
{
  0U /*  EPS_A_FlexRay  */ 
};


CONSTP2VAR(uint32, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2FrameBuffer[] =
{
  FrIf_FrameBuffer_0 /*  EPS_A_FlexRay  */ 
};




CONSTP2VAR(uint8, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2TxPduDirtyBits[] =
{
  FrIf_TxPduDirtyBits_0 /*  EPS_A_FlexRay  */ 
};

CONSTP2VAR(uint8, FRIF_CONST, FRIF_VAR_NOINIT) FrIf_Ctrl2TxPduTxRequestCounters[] =
{
  FrIf_TxPduTxRequestCounters_0 /*  EPS_A_FlexRay  */ 
};


CONSTP2CONST(FrIf_JobDescriptorType, FRIF_CONST, FRIF_CONST) FrIf_Clst2JobDescriptors[] =
{
  FrIf_JobDescriptors_0 /*  A_FlexRay  */ 
};


CONSTP2CONST(FrIf_TxHandlePtrType, FRIF_CONST, FRIF_CONST) FrIf_Clst2TxComHandleTable[] =
{
  FrIf_TxHandles_0 /*  A_FlexRay  */ 
};


CONSTP2CONST(FrIf_RxHandlePtrType, FRIF_CONST, FRIF_CONST) FrIf_Clst2RxComHandleTable[] =
{
  FrIf_RxHandles_0 /*  A_FlexRay  */ 
};


CONSTP2CONST(FrIf_CycleMaskType, FRIF_CONST, FRIF_CONST) FrIf_Clst2TxCycleMasks[] =
{
  FrIf_TxCycleMasks_0 /*  A_FlexRay  */ 
};


CONSTP2CONST(FrIf_CycleMaskType, FRIF_CONST, FRIF_CONST) FrIf_Clst2RxCycleMasks[] =
{
  FrIf_RxCycleMasks_0 /*  A_FlexRay  */ 
};


CONST(uint16, FRIF_CONST) FrIf_Clst2MacroTicksPerCycle[] = 
{
  3636U /*  A_FlexRay  */ 
};


CONST(uint16, FRIF_CONST) FrIf_Clst2MacroTickLengthInNanoSeconds[] = 
{
  1375U /*  A_FlexRay  */ 
};


CONST(uint8, FRIF_CONST) FrIf_Clst2NumberOfJobs[] = 
{
  4U /*  A_FlexRay  */ 
};



#define FRIF_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

