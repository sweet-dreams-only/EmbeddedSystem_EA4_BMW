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
 *        \file   FrTp_Rsrc.c
 *        \brief  Source file of the FrTp sub-module Rsrc.
 *
 *      \details  Source file containing the internal service functions of the sub-module Rsrc of the FrTp.
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

#define FRTP_RSRC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FrTp_Common.h"
#include "PduR_FrTp.h"
#if(FRTP_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#if(FRTP_DEV_ERROR_REPORT == STD_ON)
# include "FrTp.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrTp header file */
#if (  (FRTP_RSRC_SW_MAJOR_VERSION != (2u)) \
    || (FRTP_RSRC_SW_MINOR_VERSION != (4u)) \
    || (FRTP_RSRC_SW_PATCH_VERSION != (4u)) )
# error "Vendor specific version numbers of FrTp_Rsrc.c and FrTp.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (FRTP_CFG_MAJOR_VERSION != (2u)) \
    || (FRTP_CFG_MINOR_VERSION != (4u)) )
# error "Version numbers of FrTp_Rsrc.c and FrTp_Cfg.h are inconsistent!"
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

#define FRTP_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/* PRQA S 3218 18 */ /* MD_FrTp_3218 */
/*!< Local static constant constant to initialize a rx-state-machine */
FRTP_LOCAL CONST(FrTp_RxStateType, FRTP_CONST) FrTp_Rsrc_RxSmInitConst =
{
  (P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST)) NULL_PTR, /* P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) pConnCfg; */
  (PduLengthType)0u, /* PduLengthType DataIndex; */
  (PduLengthType)0u, /* PduLengthType DataLength; */
  (PduLengthType)0u, /* PduLengthType AvailableRxBuffer; */
  (PduLengthType)0u, /* PduLengthType RemainingBytesInBlock; */
  (FrTp_ChanTimerType)0u, /* FrTp_ChanTimerType Timer; */
  (FrTp_BufReqTimerType)0u, /* FrTp_BufReqTimerType CounterWft; */
  FrTp_PCIinvalid, /* uint8 CurrPCI; */
  FrTp_RxSm_Idle, /* uint8 State; */
  (uint8)0u, /* uint8 ExpectedSN; */
  (uint8)FALSE, /* uint8 RxStartedAtUpperLayer; */
  (uint8)0u, /* uint8 ReceivedPduLen; */
  FrTp_NoPdu /* (uint8) NxtFreePduIdx; */
};
/* FrTp_Rsrc_RxSmInitConst */

/* PRQA S 3218 25 */ /* MD_FrTp_3218 */
/*!< Local static constant constant to initialize a tx-state-machine */
FRTP_LOCAL CONST(FrTp_TxStateType, FRTP_CONST) FrTp_Rsrc_TxSmInitConst = 
{
  (P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST)) NULL_PTR, /* P2CONST(FrTp_ConnCfgType, FRTP_CONST, FRTP_CONST) pConnCfg; */
  (PduLengthType)0u, /* PduLengthType DataIndex; */
  (PduLengthType)0u, /* PduLengthType DataLength; */
  (PduLengthType)0u, /* PduLengthType AvailableTxData; */
  (PduLengthType)0u, /* PduLengthType CurrDecTxDataPending; */
  (PduLengthType)0u, /* PduLengthType RemainingBytesInBlock; */
  (FrTp_ChanTimerType)0u, /* FrTp_ChanTimerType Timer; */
  FrTp_PCIinvalid, /* uint8 CurrPCI; */
  FrTp_TxSm_Idle, /* uint8 State; */
  (uint8)0u, /* uint8 SeqNumber; */
  (uint8)FALSE, /* uint8 RobsRound; */
  (uint8)0u, /* uint8 CounterMNPC:6; */
  (uint8)FrTp_MNPCDefault, /* uint8 CurrMNPC; */
  (uint8)0u, /* uint8 TimerVal4CurrSC; */
  (uint8)0u, /* uint8 CounterWT; */
  (uint8)0u, /* uint8 CopiedTxDataLen; */
  (uint8)0u, /* uint8 PendingTxConfs; */
  FrTp_NoPdu, /* (uint8) NxtFreePduIdx; */
  (uint8)0u, /* uint8 IsBlockMode */
  (uint8)0u /* uint8 CurrDecPdusPending */
};
/* FrTp_Rsrc_TxSmInitConst */

#define FRTP_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

 /***********************************************************************************************************************
 * FrTp_Rsrc_FindTxSm()
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
FUNC(uint8, FRTP_CODE) FrTp_Rsrc_FindTxSm(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least txSmIdx;
  uint8_least freeTxSmIdx = FrTp_NoSm;
  uint8 errorId = FRTP_E_NO_ERROR;
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Loop all tx-state-machines
   *          For each tx-state-machine:
   *          Retrieve pointer to tx-state-machine
   *          Check, whether the tx-state-machine is idle:
   *          In case connCfgPtr of tx-state-machine is NULL (i.e. tx-state-machine is unused)
   *          Store the txSmIdx as 'freeTxSmIdx' and break loop */
  for(txSmIdx = 0u; txSmIdx < FrTp_CCfg_NumTxChan(); txSmIdx++)
  {
    pTxSm = FrTp_VCfg_TxState((uint8)txSmIdx);
    if(FrTp_TxSm_Item(pTxSm, ConnCfgPtr) == NULL_PTR)
    {
      freeTxSmIdx = txSmIdx;
      break;
    }
  }
  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(freeTxSmIdx == FrTp_NoSm)
  {
    errorId = FRTP_E_NO_CHANNEL;
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_Transmit_ServiceId, errorId);
  }
#endif
  /* #20 Return 'freeTxSmIdx' as index of next free tx-state-machine */
  return (uint8)freeTxSmIdx;
} /* FrTp_Rsrc_FindTxSm */

/***********************************************************************************************************************
 * FrTp_Rsrc_FindRxSm()
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
FUNC(uint8, FRTP_CODE) FrTp_Rsrc_FindRxSm(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least rxSmIdx;
  uint8_least freeRxSmIdx = FrTp_NoSm;
  uint8 errorId = FRTP_E_NO_ERROR;
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Loop all rx-state-machines
   *          For each rx-state-machine:
   *          Retrieve pointer to rx-state-machine
   *          Check, whether the rx-state-machine is idle:
   *          In case connCfgPtr of rx-state-machine is NULL (i.e. rx-state-machine is unused)
   *          Store the rxSmIdx as 'freeRxSmIdx' and break loop */
  for(rxSmIdx = 0u; rxSmIdx < FrTp_CCfg_NumRxChan(); rxSmIdx++)
  {
    pRxSm = FrTp_VCfg_RxState((uint8)rxSmIdx);
    if(FrTp_RxSm_Item(pRxSm, ConnCfgPtr) == NULL_PTR)
    {
      freeRxSmIdx = rxSmIdx;
      break;
    }
  }
  /* ----- Development Error Checks ------------------------------------- */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if(freeRxSmIdx == FrTp_NoSm)
  {
    errorId = FRTP_E_NO_CHANNEL;
  }
#else
  FRTP_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  /* ----- Development Error Report --------------------------------------- */
#if (FRTP_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FRTP_E_NO_ERROR)
  {
    (void)Det_ReportError(FRTP_MODULE_ID, FRTP_INSTANCE_ID_DET, FrTp_RxIndication_ServiceId, errorId);
  }
#endif
  /* #20 Return 'freeRxSmIdx' as index of next free rx-state-machine */
  return (uint8)freeRxSmIdx;
} /* FrTp_Rsrc_FindRxSm */

/***********************************************************************************************************************
 * FrTp_Rsrc_AllocateTxSm()
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
FUNC(void, FRTP_CODE) FrTp_Rsrc_AllocateTxSm(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  PduLengthType ML,
  uint16 newTimer,
  uint8 txSmIdx
)
{
  /* #10 Retrieve pointer to tx-state-machine */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
  /* #20 Initialize the tx-state-machine with pConnCfg
   *          Set DataLength to requestedTxLen
   *          Set timer to retrieve buffer for the next TimeCs FlexRay-cycles
   *          Set the channel ID in the connections runtime data for quicker lookup
   *          Set currMNPC according the FrTpBandwidthLimitation-flag in order to start the transfer on the correct FrIf-Tx-Pdu. */
  FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_WaitForDataSTF; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  FrTp_TxSm_Item(pTxSm, ConnCfgPtr) = pConnCfg; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  FrTp_TxSm_Item(pTxSm, DataLength) = ML; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  FrTp_TxSm_Item(pTxSm, Timer) = newTimer; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrTxSmIdx = txSmIdx; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX_CONNSTATE */
  /* #30 Select the first fo all available FrTp Tx-Pdus in case the BW-limitation flag is set */
  if(pConnCfg->FrTpBandwidthLimitation != 0u)
  {
    FrTp_TxSm_Item(pTxSm, CurrMNPC) = 1u; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  }
} /* FrTp_Rsrc_AllocateTxSm */

/***********************************************************************************************************************
 * FrTp_Rsrc_AllocateRxSm()
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
FUNC(void, FRTP_CODE) FrTp_Rsrc_AllocateRxSm(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  PduLengthType ML,
  uint16 newTimer,
  uint8 rxSmIdx,
  uint8 FPL,
  uint8 currPCI,
  uint8 newState
)
{
  /* #10 Retrieve pointer to rx-state-machine */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);
  /* #20 It is an [un]segmented reception: Handle the [un]segmented STF, i.e.
   *           Store the FPL in the channel-variable ReceivedDataLen
   *           Link the rx-state-machine to the connection from the STF-pdu
   *           Initialize the rx-state-machine for unsegmented reception
   *           Set CurrPCI of rx-state-machine
   *           Set the rx-state-machine to state 'newState'
   *           Set timer to process the next reception step in minimum time */
  FrTp_RxSm_Item(pRxSm, ReceivedPduLen) = FPL; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
  FrTp_RxSm_Item(pRxSm, ConnCfgPtr) = pConnCfg; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
  FrTp_RxSm_Item(pRxSm, DataLength) = ML; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
  FrTp_RxSm_Item(pRxSm, CurrPCI) = currPCI; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
  FrTp_RxSm_Item(pRxSm, State) = newState; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
  FrTp_RxSm_Item(pRxSm, Timer) = newTimer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
  FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrRxSmIdx = rxSmIdx; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX_CONNSTATE */
} /* FrTp_Rsrc_AllocateRxSm */ /* PRQA S 6060 */ /* MD_MSR_STPAR */

/***********************************************************************************************************************
 * FrTp_Rsrc_ReleaseTxSm()
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
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_Rsrc_ReleaseTxSm(
  uint8 txSmIdx, 
  Std_ReturnType notifyCode)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Given the pConnCfg has not yet been set
         Then it is an internal initialization
         And thus the notifyCode is set as required to "not indicate anything" */
  if(pConnCfg == NULL_PTR)
  {
    notifyCode = FrTp_NoResultNotification;
  }

  /* #30 In case the PduR shall be informed by a notification code
         Reset the Tx state of the connection runtime data
         Reset the pending flags of the Tx-Pdus used by the channel
         Re-initialize the channel completely
         Call the tx-confirmation-function of the upper layer */
  if(notifyCode != FrTp_NoResultNotification)
  {
    FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrTxSmIdx = FrTp_NoSm; /* SBSW_FRTP_RELEASE_TXSM_CONNSTATE */
    FrTp_FrIf_ResetTxPduPending(txSmIdx, FrTp_FrIf_DirTx);
    *pTxSm = FrTp_Rsrc_TxSmInitConst; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    PduR_FrTpTxConfirmation(pConnCfg->FrTpSduTxId, notifyCode);
  }
  else
  {
    /* #80 Otherwise the application shall not be informed.
           In case the pConnCfg is not NULL_PTR
           Reset the Tx channel number of the connection runtime data */
    if(pConnCfg != NULL_PTR)
    {
      FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrTxSmIdx = FrTp_NoSm; /* SBSW_FRTP_RELEASE_TXSM_CONNSTATE */
    }
    /* #110 In case the channel is busy reset the tx-confirmation-pending-flags
            Reset all pending tx-confirmation-flags of the affected pool */
    if(FrTp_TxSm_Item(pTxSm, State) != FrTp_TxSm_Idle)
    {
      FrTp_FrIf_ResetTxPduPending(txSmIdx, FrTp_FrIf_DirTx);
    }
    /* #130 Re-initialize the channel completely */
    *pTxSm = FrTp_Rsrc_TxSmInitConst; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  }
} /* FrTp_Rsrc_ReleaseTxSm */

/***********************************************************************************************************************
 * FrTp_Rsrc_ReleaseRxSm()
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
 *
 */
FUNC(void, FRTP_CODE) FrTp_Rsrc_ReleaseRxSm(
  uint8 rxSmIdx,
  Std_ReturnType notifyCode)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_RxSm_Item(pRxSm, ConnCfgPtr);
  
  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the upper layer has been informed about the reception, already
         Set the notifyCode to not indicate anything to the upper layer */
  if(((uint8)FrTp_RxSm_Item(pRxSm, RxStartedAtUpperLayer)) == FALSE)
  {
    notifyCode = FrTp_NoResultNotification;
  }
  /* #30 In case the PduR shall be informed
         Reset the Rx state of the connection runtime data
         Reset the pending flags of the Tx-Pdus used by the channel
         Re-initialize the channel completely
         Call the rx-indication-function of the upper layer */
  if(notifyCode != FrTp_NoResultNotification) 
  {
    FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrRxSmIdx = FrTp_NoSm; /* SBSW_FRTP_RELEASE_RXSM_CONNSTATE */
    FrTp_FrIf_ResetTxPduPending(rxSmIdx, FrTp_FrIf_DirRx);
    *pRxSm = FrTp_Rsrc_RxSmInitConst; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    PduR_FrTpRxIndication(pConnCfg->FrTpSduRxId, notifyCode);
  }
  else
  {
    /* #80 Otherwise the application shall not be informed:
           In case the pConnCfg is NULL_PTR
           Reset the Rx channel number of the connection runtime data */
    if(pConnCfg != NULL_PTR)
    {
      FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrRxSmIdx = FrTp_NoSm; /* SBSW_FRTP_RELEASE_RXSM_CONNSTATE */
    }
    /* #110 In case the channel is busy
            Reset the tx-confirmation-pending-flags */
    if(FrTp_RxSm_Item(pRxSm, State) != FrTp_RxSm_Idle)
    {
      FrTp_FrIf_ResetTxPduPending(rxSmIdx, FrTp_FrIf_DirRx);
    }
    /* #130 Re-initialize the channel completely */
    *pRxSm = FrTp_Rsrc_RxSmInitConst; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* FrTp_Rsrc_ReleaseRxSm */

/***********************************************************************************************************************
 * FrTp_Rsrc_InitAllSms()
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
 */
FUNC(void, FRTP_CODE) FrTp_Rsrc_InitAllSms(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm;
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm;
  uint8_least smIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate all rx-state-machines and for each item
         Retrieve pointer to rx-state-machine
         Initialize connCfgPtr and State
         Set the rx-state-machine to state FrTp_RxSm_Idle
         Re-initialize the rx-state-machine completely */
  for(smIdx = 0u; smIdx < (uint8_least)(FrTp_CCfg_NumRxChan()); smIdx++)
  {
    pRxSm = FrTp_VCfg_RxState((uint8)smIdx);
    FrTp_RxSm_Item(pRxSm, ConnCfgPtr) = (FrTp_ConnCfgType*)NULL_PTR; /* SBSW_FRTP_INIT_RXSM */
    FrTp_RxSm_Item(pRxSm, State) = FrTp_RxSm_Idle; /* SBSW_FRTP_INIT_RXSM */
    FrTp_Rsrc_ReleaseRxSm((uint8)(smIdx), FrTp_NoResultNotification); 
  }
  /* smIdx is PduIdType and used as counter of range uint8 --> ok */
  /* #60 Iterate all rx-state-machines and for each item
         Retrieve pointer to tx-state-machine
         Initialize connCfgPtr and State
         Set the tx-state-machine to state FrTp_TxSm_Idle
         Re-initialize the rx-state-machine completely */
  for(smIdx = 0u; smIdx < (uint8_least)(FrTp_CCfg_NumTxChan()); smIdx++)
  {
    pTxSm = FrTp_VCfg_TxState((uint8)smIdx);
    FrTp_TxSm_Item(pTxSm, ConnCfgPtr) = (FrTp_ConnCfgType*)NULL_PTR; /* SBSW_FRTP_INIT_TXSM */
    FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_Idle; /* SBSW_FRTP_INIT_TXSM */
    FrTp_Rsrc_ReleaseTxSm((uint8)(smIdx), FrTp_NoResultNotification);
  }
} /* FrTp_Rsrc_InitAllSms */

/***********************************************************************************************************************
 * FrTp_Rsrc_InitAllConns()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_Rsrc_InitAllConns(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  PduIdType connIdx;
  /* #10 Loop all connections - for each item:
         Retrieve a pointer to the connection-control of the connection
         Assign the configured BC value to the connections-runtime-data */
  for(connIdx = 0u; connIdx < FrTp_CCfg_NumConn(); connIdx++)
  {
    P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl = FrTp_CCfg_ConnCfg(connIdx)->ConnCtrlPtr;

    FrTp_VCfg_ConnState(connIdx)->CurrBC = FrTp_GetConnCtrlItem(pConnCtrl, BandwidthCtrl); /* SBSW_FRTP_INIT_CONNSTATE */
    FrTp_VCfg_ConnState(connIdx)->CurrRxSmIdx = FrTp_NoSm; /* SBSW_FRTP_INIT_CONNSTATE */
    FrTp_VCfg_ConnState(connIdx)->CurrTxSmIdx = FrTp_NoSm; /* SBSW_FRTP_INIT_CONNSTATE */
  }
} /* FrTp_Rsrc_InitAllConns */

#define FRTP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Rsrc.c
 *********************************************************************************************************************/

