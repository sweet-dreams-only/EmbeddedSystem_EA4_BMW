/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!
 *        \file   FrTp_FrIf.c
 *        \brief  Source file of the FrTp sub-module FrIf.
 *
 *      \details  Source file containing the internal service functions of the sub-module FrIf of the FrTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define FRTP_FRIF_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FrTp_Common.h"
#include "vstdlib.h"
#include "FrIf.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrTp header file */
#if (  (FRTP_FRIF_SW_MAJOR_VERSION != (2u)) \
    || (FRTP_FRIF_SW_MINOR_VERSION != (4u)) \
    || (FRTP_FRIF_SW_PATCH_VERSION != (4u)) )
# error "Vendor specific version numbers of FrTp_FrIf.c and FrTp.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (FRTP_CFG_MAJOR_VERSION != (2u)) \
    || (FRTP_CFG_MINOR_VERSION != (4u)) )
# error "Version numbers of FrTp_FrIf.c and FrTp_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
  FrTp_FrIf_RxIndicationRxSm()
**********************************************************************************************************************/
/*!
 * \brief       Processes the RxSm-related RxIndication after the TP-connection has been found by FrTp_RxIndication.
 * \details     Process the pdu received as rx-pdu in case a free rx-state-machine has been found, or in case a rx-state-machine 
 *              is busy with the connection provided by the caller.            
 * \param[in]   P2CONST(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr: Ptr to payload of pdu _past_ the address-bytes
 *              PRE_FRTP_VALID_PDU_INFO_TYPE FrIf_PduInfoPtr
 *              The members of that PduInfoType have to be initialized like this:
 *              SduLength: Has to contain the length of the complete FrTp-pdu received, which has to be in the range of
 *              [1..(MAX(of all values of member Length in generated array FrTp_FrIfRxPdus[]) - 1)].
 *              SduDataPtr: Has to point to an array of uint8 containing the complete FrTp-pdu received.
 * \param[in]   PduIdType FrIfRxPduId: Internal index of the FrTp-pdu received in generated array FrTp_FrIfRxPdus[]
 * \param[in]   uint8 tpConn: Internal index of the FrTp_Connection that is affected by the FrTp-pdu received.
 *              PRE_FRTP_VALID_CONN_IDX tpConn
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       CREQ-106180
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_FrIf_RxIndicationRxSm(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  PduIdType FrIfRxPduId,
  PduIdType tpConn
);

 /**********************************************************************************************************************
   FrTp_FrIf_RxIndicationTxSm()
 **********************************************************************************************************************/
 /*!
 * \brief       Processes the TxSm-related RxIndication after the TP-connection has been found by FrTp_RxIndication.
 * \details     Process the pdu received as tx-pdu in case a valid tx-channel has been found that is busy with the 
 *              connection provided by the caller. Otherwise initialize the tx-state-pointer with NULL_PTR to indicate 
 *              the absence of a tx-channel that is operating the connection provided by the caller.
 * \param[in]   P2CONST(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr: Ptr to payload of pdu _past_ the address-bytes
 *              PRE_FRTP_VALID_PDU_INFO_TYPE FrIf_PduInfoPtr
 *              The members of that PduInfoType have to be initialized like this:
 *              SduLength: Has to contain the length of the complete FrTp-pdu received, which has to be in the range of
 *              [1..(MAX(of all values of member Length in generated array FrTp_FrIfRxPdus[]) - 1)].
 *              SduDataPtr: Has to point to an array of uint8 containing the complete FrTp-pdu received.
 * \param[in]   uint8 tpConn: Internal index of the FrTp_Connection that is affected by the FrTp-pdu received.
 *              PRE_FRTP_VALID_CONN_IDX tpConn
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       CREQ-106180
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_FrIf_RxIndicationTxSm(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  PduIdType tpConn
);

/***********************************************************************************************************************
 * FrTp_FrIf_RxIndicationRxSm()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_FrIf_RxIndicationRxSm(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  PduIdType FrIfRxPduId,
  PduIdType tpConn
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Retrieve rx-channel index from the runtime data of the connection provided by the caller */
  uint8 rxSmIdx = FrTp_VCfg_ConnState(tpConn)->CurrRxSmIdx;

  /* ----- Implementation ----------------------------------------------- */

  /* #50 In case there is no rx-state-machine operating the connection provided by the caller
   *     get the index of the next free rx-state-machine. */
  if(rxSmIdx == FrTp_NoSm)
  {
    rxSmIdx = FrTp_Rsrc_FindRxSm();
  }

  /* #90 In case a free rx-state-machine has been found, or in case a rx-state-machine is busy with the connection provided by the caller
   *          Process the pdu received as rx-pdu */
  if(rxSmIdx != FrTp_NoSm)
  {
    /* #91 Use a pointer to the configuration of the connection provided by the caller as parameter pConnCfg */
    FrTp_RxSm_FrIfRxIndication(FrIf_PduInfoPtr, FrTp_CCfg_ConnCfg(tpConn), FrIfRxPduId, rxSmIdx); /* SBSW_FRTP_RXSM_RXINDICATION */
  }
}

/***********************************************************************************************************************
 * FrTp_FrIf_RxIndicationTxSm()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_FrIf_RxIndicationTxSm(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  PduIdType tpConn
)
{
  /* #10 Retrieve tx-channel index from the runtime data of the connection provided by the caller */
  uint8 txSmIdx = FrTp_VCfg_ConnState(tpConn)->CurrTxSmIdx;

  /* #70 In case a valid tx-channel has been found that is busy with the connection provided by the caller
   *          initialize a pointer to its state-machine,
   *          otherwise initialize the tx-state-pointer with NULL_PTR to indicate the absence of a tx-channel that is operating the connection provided by the caller */
  if(txSmIdx != FrTp_NoSm)
  /*! This condition is obeyed by the FrTp_Rsrc_FindTxSm()-method: && (txSmIdx < FrTp_CCfg_NumTxChan())) */
  {
    volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);

    /* #100 In case a tx-channel is busy with the connection provided by the caller
     *          Process the pdu received as tx-pdu */
    if((pTxSm != NULL_PTR) && (pTxSm->ConnCfgPtr != NULL_PTR))
    {
      /* #110 When calling the TxSm-specific RxIndication method: Retrieve pointer to the position of the PCI in the pdu */
      FrTp_TxSm_FrIfRxIndication(&FrIf_PduInfoPtr->SduDataPtr[FrTp_Util_OffsetTPCI], pTxSm, txSmIdx); /* SBSW_FRTP_TXSM_RXINDICATION */
    }
  }
}

/***********************************************************************************************************************
 * FrTp_FrIf_RxIndication()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_FrIf_RxIndication(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  PduIdType FrIfRxPduId,
  PduIdType tpConn
)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter FRTP_EXCLUSIVE_AREA_0 */
  FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  /* #20 Process Rx Indication for Rx state machine */
  FrTp_FrIf_RxIndicationRxSm(FrIf_PduInfoPtr, FrIfRxPduId, tpConn); /* SBSW_FRTP_FRIF_RXINDICATION_RXTXSM */
  /* #30 Process Rx Indication for Tx state machine */
  FrTp_FrIf_RxIndicationTxSm(FrIf_PduInfoPtr, tpConn); /* SBSW_FRTP_FRIF_RXINDICATION_RXTXSM */

  /* #40 Leave FRTP_EXCLUSIVE_AREA_0 */
  FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* FrTp_FrIf_RxIndication */

/***********************************************************************************************************************
 * FrTp_FrIf_ProcessTxConfirmations()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_FrIf_ProcessTxConfirmations(
  void
)
{
  uint8 index;
  /* #10 Enter FRTP_EXCLUSIVE_AREA_0 */
  FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* #20 Take over the Tx-confirmations 'once per cycle', for all pools: */
  for(index = 0; index < FrTp_CCfg_NumTxPools(); index++)
  {
    /* #30 Take over the Tx-confirmations for pool with index [index]: */
    FrTp_FrIf_GetTxPduPoolDataItem(index, NumFreePdus) = /* SBSW_FRTP_UPDATE_FREE_TX_PDUS */
      (uint8)(    FrTp_FrIf_GetTxPduPoolDataItem(index, NumFreePdus)
                + FrTp_FrIf_GetTxPduPoolDataItem(index, NumTxConfs));
    /* #40 Reset the number of Tx-confirmations that has come in for pool with index [index] in the last cycle: */
    FrTp_FrIf_GetTxPduPoolDataItem(index, NumTxConfs) = 0u; /* SBSW_FRTP_RESET_TX_CONFS */
  }
  /* #50 Leave FRTP_EXCLUSIVE_AREA_0 */
  FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

/***********************************************************************************************************************
 * FrTp_FrIf_ResetTxPduPending()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_FrIf_ResetTxPduPending(
  uint8 smIdx, 
  uint8 smDir
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least FrIfTxPdu;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Iterate _all_ tx-pdus of the FrTp because of to the possibility to have overlapping tx-pdu pools */
  for(FrIfTxPdu = 0u; FrIfTxPdu < FrTp_CCfg_NumFrIfTxPdus(); FrIfTxPdu++)
  {
    /* #30 In case the tx-pdu is used by THIS rx-state-machine:
     *            Reset the rx-part of the pending-flag-arrays
     *            Tell all pools that contain the tx-pdu that the pdu has been tx-confirmed */
    uint8 pendingSmIdx = *FrTp_VCfg_RxFrIfPending((uint8)FrIfTxPdu);
    if(    ((FrTp_FrIf_DirRx & smDir) != 0)
        && (smIdx == pendingSmIdx)
      )
    {
      FrTp_FrIf_TxConfirmationForRxSmUsingTxPdu((uint8)FrIfTxPdu); /* SBSW_FRTP_RESET_RX_FRIF_PENDING */
      FrTp_FrIf_IncreaseNumTxConfOverlapped((uint8)FrIfTxPdu);
    }
    /* #40 In case the tx-pdu is used by THIS tx-channel:
     *            Reset the tx-part of the pending-flag-arrays
     *            Tell all pools that contain the tx-pdu that the pdu has been tx-confirmed */
    pendingSmIdx = *FrTp_VCfg_TxFrIfPending((uint8)FrIfTxPdu);
    if(    ((FrTp_FrIf_DirTx & smDir) != 0)
        && (smIdx == pendingSmIdx)
      )
    {
      FrTp_FrIf_TxConfirmationForTxSmUsingTxPdu((uint8)FrIfTxPdu); /* SBSW_FRTP_RESET_TX_FRIF_PENDING */
      FrTp_FrIf_IncreaseNumTxConfOverlapped((uint8)FrIfTxPdu);
    }
  }
} /* FrTp_FrIf_ResetTxPduPending */

/***********************************************************************************************************************
 * FrTp_FrIf_IncreaseNumTxConfOverlapped()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_FrIf_IncreaseNumTxConfOverlapped(uint8_least FrIfTxPduId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least poolIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each pool this Tx-Pdu belongs to:
   *          Increase the number of tx-confirmations to be applied to that pool */
  for(poolIdx = 0u; poolIdx < FrTp_CCfg_FrIfTxPdus((uint8)FrIfTxPduId)->NumPools; poolIdx++)
  {
    FrTp_FrIf_GetTxPduPoolDataItemByPtr(FrTp_FrIf_GetTxPduPoolDataPtrByOffset(FrTp_CCfg_FrIfTxPdus((uint8)FrIfTxPduId)->PoolOffsetsPtr[poolIdx]), NumTxConfs)++; /* SBSW_FRTP_INCREASE_TX_CONFS */
  }
} /* FrTp_FrIf_IncreaseNumTxConfOverlapped */

/***********************************************************************************************************************
 * FrTp_FrIf_DecreaseNumFreePdusOverlapped()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_FrIf_DecreaseNumFreePdusOverlapped(
  P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least poolIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 For each pool this Tx-Pdu belongs to:
   *            Decrease the number of free FrIf-tx-pdus of that pool */
  for(poolIdx = 0u; poolIdx < pFrIfTxPdu->NumPools; poolIdx++)
  { 
    FrTp_FrIf_GetTxPduPoolDataItem((pFrIfTxPdu->PoolOffsetsPtr)[poolIdx], NumFreePdus)--; /* SBSW_FRTP_DECREASE_FREE_PDUS */
  }
} /* FrTp_FrIf_DecreaseNumFreePdusOverlapped */

/***********************************************************************************************************************
 * FrTp_FrIf_Init()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_FrIf_Init(
  void
)
{
  uint8_least index;
  /* #10 Loop all FrIf-Tx-Pdus */
  for(index = 0u; index < FrTp_CCfg_NumFrIfTxPdus(); index++)
  {
    /* PRQA S 3201 15 */ /* MD_MSR_14.1 */
    /* #20 Check if the pdu is a decoupled pdu */
    if(FrTp_FrIf_IsDecoupPdu(*(FrTp_CCfg_FrIfTxPdus((uint8)index)))) /* PRQA S 3356 */ /* MD_FrTp_3356 */
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      /* #30 Reset the decoupled-pdu's runtime-data */
      FrTp_FrIf_GetDecoupAdmin(*FrTp_CCfg_FrIfTxPdus((uint8)index)).ConnCfgPtr = NULL_PTR; /* SBSW_FRTP_INIT_DECOUP_ADMIN_DATA */ /* P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) pConnCfg; */
      FrTp_FrIf_GetDecoupAdmin(*FrTp_CCfg_FrIfTxPdus((uint8)index)).PduInfoPayload.SduDataPtr = NULL_PTR; /* SBSW_FRTP_INIT_DECOUP_ADMIN_DATA */ /* PduInfoType PduInfoPayload.SduDataPtr; */
      FrTp_FrIf_GetDecoupAdmin(*FrTp_CCfg_FrIfTxPdus((uint8)index)).PduInfoPayload.SduLength = (PduLengthType)0; /* SBSW_FRTP_INIT_DECOUP_ADMIN_DATA */ /* PduInfoType PduInfoPayload.SduLength; */
      FrTp_FrIf_GetDecoupAdmin(*FrTp_CCfg_FrIfTxPdus((uint8)index)).PduLengthTPCI = (PduLengthType)0; /* SBSW_FRTP_INIT_DECOUP_ADMIN_DATA */ /* PduLengthType PduLengthTPCI; */
      VStdLib_MemSet(FrTp_FrIf_GetDecoupAdmin(*FrTp_CCfg_FrIfTxPdus((uint8)index)).TPCIData, 0, FrTp_TPCIMaxLength); /* SBSW_FRTP_INIT_DECOUP_ADMIN_DATA */ /* uint8 TPCIData[FrTp_TPCIMaxLength]; */
    }
    /* #40 Reset the Rx- and Tx-related usage-flags of the pdu */
    *FrTp_VCfg_RxFrIfPending((uint8)index) = FrTp_NoSm; /* SBSW_FRTP_INIT_RXTX_FRIF_PENDING */
    *FrTp_VCfg_TxFrIfPending((uint8)index) = FrTp_NoSm; /* SBSW_FRTP_INIT_RXTX_FRIF_PENDING */
  }
  /* #50 Loop all Tx-Pdu-pools */
  for(index = 0; index < FrTp_CCfg_NumTxPools(); index++)
  {
    /* #60 Initialize the pools runtime-data */
    FrTp_FrIf_GetTxPduPoolDataItem((uint8)index, NumTxConfs) = (uint8)0u; /* SBSW_FRTP_INIT_POOL_DATA */
    FrTp_FrIf_GetTxPduPoolDataItem((uint8)index, NumFreePdus) = (uint8)(FrTp_CCfg_TxPduPools((uint8)index)->NumPdus); /* SBSW_FRTP_INIT_POOL_DATA */
  }
} /* FrTp_FrIf_Init */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/***********************************************************************************************************************
 * FrTp_FrIf_FindFreeTxPdu()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(uint8, FRTP_CODE) FrTp_FrIf_FindFreeTxPdu(
   CONSTP2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg
  ,CONSTP2CONST(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_CONST) pPoolData
  ,uint8 poolLimit
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least pduIdx = FrTp_NoPdu;
  uint8_least pdu;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case there are free Tx-Pdus in the pool */
  if(0 < FrTp_FrIf_GetTxPduPoolDataItemByPtr(pPoolData, NumFreePdus))
  {
    /* #20 In case no poolLimit is given:
     *            The caller has not given a limit: Set poolLimit to the size of the pool.
     *            Otherwise the caller has given a limit: Optionally reduce the limit to the size of the pool */
    if(poolLimit == 0u)
    {
      poolLimit = pPoolCfg->NumPdus;
    }
    else
    {
      poolLimit = (uint8)FrTp_Min(poolLimit, pPoolCfg->NumPdus);
    }

    /* #30 Iterate all pdus of the pool up to the given limit.
     *            For each pdu look up the FrTp-global index in the FrTps overall tx-pdu-array.
     *            In case the tx-pdu at this index is currently unused:
     *            Recognize the index as return value and exit the loop. */
    for(pdu = 0u; pdu < poolLimit; pdu++)
    {
      uint8 tmpIdx = pPoolCfg->PduOffsetsPtr[pdu];
      uint8 isTxConfExp = FrTp_FrIf_IsTxConfExpectedForPdu(tmpIdx); /* PRQA S 3415 */ /* MD_FrTp_3415 */
      if(!isTxConfExp)
      {
        pduIdx = tmpIdx;
        break;
      }
    }
  }
  return (uint8)pduIdx;
} /* FrTp_FrIf_FindFreeTxPdu */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
  FrTp_FrIf_TransmitPduForConn()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTP_CODE) FrTp_FrIf_TransmitPduForConn(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu,
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI, 
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pPayload
)
{
  PduInfoType FrIfPduInfo;
  Std_ReturnType ret = E_NOT_OK;

  /* #10 Initialize the pdu-info-struct that will be passed to FrIf_Transmit() with the pointer to the assembly buffer */
  FrIfPduInfo.SduDataPtr = FrTp_VCfg_FrIfTxBuf();
  /* PRQA S 3201 NOT_UNREACHABLE_CODE */ /* MD_MSR_14.1 */
  /* #20 In case the pdu is 'decoupled' */
  if(FrTp_FrIf_IsDecoupPdu(*pFrIfTxPdu)) /* PRQA S 3356 */ /* MD_FrTp_3356 */
  { /* PRQA S 3201 */ /* MD_FrTp_3201 */
    /* #30 Retrieve pointer to the decoupled admin data using the pdu configuration.
     *            Store the payload-info in the decoupled admin data, in order to assemble the pdu in FrTp_TriggerTransmit(), later on.
     *            The SduDataPtr can only point to the payload of FC-pdus (STF and CF data is copied in the context of FrTp_TriggerTransmit().
     *            Store the pdu-info of the PCI in the decoupled admin data, in order to assemble the pdu in FrTp_TriggerTransmit(), later on.
     *            (The cast to uint8, below, is safe because TPCI and also any FlexRay-pdu is always smaller than 255.)
     *            Store the connection that is the sender of the pdu in the decoupled admin data, in order to assemble the pdu in FrTp_TriggerTransmit(), later on. */
    P2VAR(FrTp_DecoupPduAdminType, AUTOMATIC, FRTP_APPL_DATA) pDecoupAdminData = &FrTp_FrIf_GetDecoupAdmin(*pFrIfTxPdu);
    pDecoupAdminData->PduInfoPayload.SduLength = pPayload->SduLength; /* SBSW_FRTP_UPDATE_DECOUP_PDU_ADMIN */
    pDecoupAdminData->PduInfoPayload.SduDataPtr = pPayload->SduDataPtr; /* SBSW_FRTP_UPDATE_DECOUP_PDU_ADMIN */
    pDecoupAdminData->PduLengthTPCI = (uint8)(pTPCI->SduLength); /* SBSW_FRTP_UPDATE_DECOUP_PDU_ADMIN */
    pDecoupAdminData->ConnCfgPtr = pConnCfg; /* SBSW_FRTP_UPDATE_DECOUP_PDU_ADMIN */
    VStdLib_MemCpy(pDecoupAdminData->TPCIData, pTPCI->SduDataPtr, pTPCI->SduLength); /* SBSW_FRTP_UPDATE_DECOUP_PDU_ADMIN */
    /* #40 Insert the actual length of the pdu into the pdu-info struct that is passed to FrIf_Transmit(), later on. */
    FrIfPduInfo.SduLength = (PduLengthType)(pTPCI->SduLength + pPayload->SduLength + (PduLengthType)FrTp_Util_OffsetTPCI);
  }
  /* PRQA L:NOT_UNREACHABLE_CODE */ 
  else
  {
    /* #50 Otherwise transmission-type is 'immediate' i.e. the pdu is assembled prior to FrIf_Transmit */
    FrIfPduInfo.SduLength = (PduLengthType)FrTp_Util_AssemblePdu(pConnCfg, pTPCI, pPayload, FrIfPduInfo.SduDataPtr); /* SBSW_FRTP_TX_ASSEMBLE_IMMEDIATE_TX_PDU */
  }

  /* #60 In case the length of the tx-pdu to transmit conforms to the configured tx-pdu-length: 
         Call FrIf_Transmit() to initiate the transmission of the pdu */
  if(FrIfPduInfo.SduLength <= pFrIfTxPdu->Length)
  {
    ret = FrIf_Transmit(pFrIfTxPdu->PduId, &FrIfPduInfo); /* SBSW_FRTP_TX_FRIF_TRANSMIT */
  }
  return ret;
} /* FrTp_FrIf_TransmitPduForConn */

#define FRTP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_FrIf.c
 *********************************************************************************************************************/

