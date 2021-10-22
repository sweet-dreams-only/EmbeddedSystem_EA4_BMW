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
 *        \file   FrTp_TxSm.c
 *        \brief  Source file of the FrTp sub-module TxSm.
 *
 *      \details  Source file containing the internal service functions of the sub-module TxSm of the FrTp.
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

#define FRTP_TXSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FrTp_Common.h"
#include "PduR_FrTp.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrTp header file */
#if (  (FRTP_TXSM_SW_MAJOR_VERSION != (2u)) \
    || (FRTP_TXSM_SW_MINOR_VERSION != (4u)) \
    || (FRTP_TXSM_SW_PATCH_VERSION != (4u)) )
# error "Vendor specific version numbers of FrTp_TxSm.c and FrTp.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (FRTP_CFG_MAJOR_VERSION != (2u)) \
    || (FRTP_CFG_MINOR_VERSION != (4u)) )
# error "Version numbers of FrTp_TxSm.c and FrTp_Cfg.h are inconsistent!"
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

#if( FRTP_RX_IND_EARLIER_THAN_TX_CONF == STD_ON)
/**********************************************************************************************************************
  FrTp_TxSm_TolerateRxIndEarlierThanTxConf()
**********************************************************************************************************************/
/*!
 * \brief       Conducts all actions required to tolerate the inversion of rx-indication & tx-confirmation from FrIf.
 * \details     Call the internal tx-confirmation function bring the state machine to the expected state in case the 
 *              rx-state-machine is currently waiting for the tx-confirmation of a STF or CF.
 *              Otherwise Call the TxConfirmation() of the affected tx-state-machine to correct the inversion of rx-
 *              indication and tx-confirmation.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm: Ptr. to the tx-state-machine
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_PTR pTxSm
 * \param[in]   uint8 txSmIdx: Index of the tx-state-machine
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_IDX txSmIdx
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_RX_IND_EARLIER_THAN_TX_CONF == STD_ON
 * \trace       DSGN-FrTpVariousJLE, DSGN-FrTpGenericFrIfInterface
 *********************************************************************************************************************/
/* PRQA S 3673 4 */ /* MD_FrTp_3673 */
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_TxSm_TolerateRxIndEarlierThanTxConf(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
);
#endif

/**********************************************************************************************************************
 FrTp_TxSm_EvalBufReqRetVal()
**********************************************************************************************************************/
/*!
 * \brief       Evaluates the return value of the call to PduR_FrTpCopyTxData.
 * \details     Depending on the return value of the call to PduR_FrTpCopyTxData either:
 *                 BUFREQ_OK:     keep the state-machine in the FrTp_MainFunctions' round-robin.
 *                 BUFREQ_E_BUSY: Leave state as it is, i.e. ask for buffer, again, in the next FrTp_MainFunction() call.
 *                 BUFREQ_E_OVFL: Terminate transmission with error.
 * \param[in]   uint8 txSmIdx: Index of the tx-state machine the call of function PduR_FrTpCopyTxData shall be evaluated for.
 *                             PRE_FRTP_VALID_ACTIVE_TX_SM_IDX txSmIdx
 * \param[in]   uint8 bReq:    Return value of the last call to PduR_FrTpCopyTxData.
 * \param[in]   uint8 newState: New state to be set in case the transmission is not stopped (i.e. bReq != BUFREQ_E_NOT_OK).
 *                              PRE_FRTP_VALID_TX_STATE_PARAM newState
 * \param[in]   uint8 newCurrPCI: New current PCI byte stored in the tx-state-machine in case the transmsision is not stopped (i.e. bReq != BUFREQ_E_NOT_OK).
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_EvalBufReqRetVal(
  uint8 txSmIdx,
  uint8 bReq,
  uint8 newState,
  uint8 newCurrPCI
);

/**********************************************************************************************************************
 FrTp_TxSm_CFTxConfirmation()
**********************************************************************************************************************/
/*!
 * \brief       Handles the FrIf's call to FrTp_TxConfirmation() for a tx-state-machine sending CF-pdus.
 * \details     It is used for these scenarios:
 *              1. Real tx-confirmation
 *              2. Pumping several CFs within one cycle
 *              This function is used internally for the transmission of several PDUs per cycle 
 *              (Burst-mode with MNPC > 1). The FrTp_TxSm_OperateAllSms will to call this function each time a
 *              FrTpChannel is willing to send more than one CF-pdu per FlexRay cycle.
 * \param[in]   uint8 txSmIdx
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_IDX txSmIdx
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTxConfirmationHandling, DSGN-FrTpBurstMode, DSGN-FrTpGenericFrIfInterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_CFTxConfirmation(
  uint8 txSmIdx
);

/**********************************************************************************************************************
 FrTp_TxSm_ActionOf()
**********************************************************************************************************************/
/*!
 * \brief       Conducts the action that is related to a particular state of the tx-state-machine.
 * \details     Transmits a single FrTp-pdu according to the current state of the given tx-state-machine.
 *              This function transmits a single(!) pdu, i.e. for transmission of several PDUs per cycle 
 *              (Burst-mode with MNPC > 1) the FrTp_TxSm_OperateAllSms has to call this function several times.
 *              In case the tx-state-machine is still active after the call then its member Timer will be >0.
 * \param[in]   volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm: current tx-state-machine pointer
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_PTR
 *              Variable NxtFreePduIdx of pointer parameter pTxSm has to be set to a value != FrTp_NoPdu
 * \param[in]   uint8 txSmIdx
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_IDX txSmIdx
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_TX_SM_IDX_OF_PTR
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpActionAndTimeoutHandling, DSGN-FrTpMainFunction
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_ActionOf(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
);

/**********************************************************************************************************************
 FrTp_TxSm_RequestAvailableTxData()
**********************************************************************************************************************/
/*!
 * \brief       Requests the number of bytes of tx-data that are available.
 * \details     In case the PduR provides 0 bytes but returns BUFREQ_OK this is corrected to BUFREQ_E_BUSY.
 * \param[in]   P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg: FrTp-connection for transmission related callbacks/callouts to PduR-functions.
 * \param[in]   P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) pApplPduInfo: Parameter to be passed to PduR_FrTpCopyTxData().
 *                                                                          Its member SduLength is overwritten in order to ask the PduR for the amount of TP-data available for tranmission.
 *                                                                          PRE_FRTP_VALID_PDU_INFO_TYPE pApplPduInfo
 * \param[out]  P2VAR(PduLengthType, AUTOMATIC, FRTP_APPL_DATA) pAvailableTxData: Amount of TP-data the PduR is able to provide for transmission.
 *                                                                                PRE_FRTP_VALID_PDU_LENGTH_TYPE_PTR
 * \return      BufReq_ReturnType: Return value of function PduR_FrTpCopyTxData with SduLength 0 (ask how much TP-data is available for transmission).
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(BufReq_ReturnType, FRTP_CODE) FrTp_TxSm_RequestAvailableTxData(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) pApplPduInfo,
  P2VAR(PduLengthType, AUTOMATIC, FRTP_APPL_DATA) pAvailableTxData,
  PduLengthType requiredLength
);

/**********************************************************************************************************************
 FrTp_TxSm_CopyPayloadOnePdu()
**********************************************************************************************************************/
/*!
 * \brief       Copies the payload of the next tx-pdu in case it is immediate.
 * \details     Prepares the copying in FrTp_TriggerTransmit in case the pdu is decoupled.
 * \param[in]   pTxSm: PRE_FRTP_VALID_ACTIVE_TX_SM_PTR
 * \param[in]   P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) pApplPduInfo: Parameter to be passed to PduR_FrTpCopyTxData().
 *                                                                          Its member SduLength is overwritten in order to ask the PduR for the amount of TP-data available for tranmission.
 *                                                                          PRE_FRTP_VALID_PDU_INFO_TYPE pApplPduInfo
 * \param[out]  P2VAR(PduLengthType, AUTOMATIC, FRTP_APPL_DATA) pAvailableTxData: Amount of TP-data the PduR is able to provide for transmission.
 *                                                                                PRE_FRTP_VALID_PDU_LENGTH_TYPE_PTR
 * \return      Number of payload bytes that has been copied for the affected tx-pdu
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(BufReq_ReturnType, AUTOMATIC) FrTp_TxSm_CopyPayloadOnePdu(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) pApplPduInfo,
  P2VAR(PduLengthType, AUTOMATIC, FRTP_APPL_DATA) pAvailableTxData
);

/**********************************************************************************************************************
 FrTp_TxSm_CopyTxData()
**********************************************************************************************************************/
/*!
 * \brief       Requests copying of data to be sent from the upper layer and handles CounterWft centrally.
 * \details     This function is used in all buffer-getting-contexts. Possible contexts are:
 *              1. We are just trying to get our very first buffer 
 *              2. It is a follow-up buffer during txn 
 *              This method initiates the next transmission request regarding FrIf, i.e. when this method is called
 *              It has to be clear whether segmentation is done or not. In addition the "Reserve-FrIf-Pdu"-Method must
 *              have been called and must have reserved a FrIf-Pdu successfully.
 *              When returning the availableTxData is topical and (in case data was copied by PduR) copiedTxData also.
 *
 *              Note:
 *              During the call to FrTp_MainFunction the availableTxData-value should not change, because all
 *              interrupts are locked, i.e. not even CanTp_RxIndication can increase availableTxData).
 *              Question: What, if only FR-interrupts are locked: Then the value should also be ok because it is only 
 *              increasing and FrTp_TxSm_CopyPayloadOnePdu shall store the payload-length values of the particular
 *              'virtual' copy actions in the admin-data of the particular decoupled tx-pdu.
 *              Assumption also is, that for one state-machine / tx-pdu-pool the transmission type is 'all the same' i.e.
 *              either decoupled or immediate.
 *              In case the tx-state-machine is still active after the call then its member Timer will be >0.
 * \param[in]   uint8 txSmIdx: PRE_FRTP_VALID_ACTIVE_TX_SM_IDX txSmIdx
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_CopyTxData(
  uint8 txSmIdx
);
 
/**********************************************************************************************************************
 FrTp_TxSm_EvalFrIfTransmitRetVal()
**********************************************************************************************************************/
/*!
 * \brief       Evaluates the return value of FrTp_TxSm_FrIfTransmit.
 * \details     Update all byte-positions of the tx-state-machine, reset 'CopiedTxDataLen' and set timer to TimeoutAs as 
 *              timeout for that state and indicate to either stay or drop out of the round robin process.
 * \param[in]   volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm: PRE_FRTP_VALID_ACTIVE_TX_SM_PTR pTxSm
 * \param[in]   uint8 txResult: Return value of FrTp_TxSm_FrIfTransmit
 * \param[in]   uint8 newStateStop: New state of the tx-state-machine in case bandwidth consumption shall be stopped.
 *                                  PRE_FRTP_VALID_TX_STATE_PARAM newStateStop
 * \param[in]   uint8 newStateContinue: New state of the tx-state-machine in case bandwidth consumption shall be continued.
 *                                      PRE_FRTP_VALID_TX_STATE_PARAM newStateContinue
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpFrIfErrorHandling
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, AUTOMATIC) FrTp_TxSm_EvalFrIfTransmitRetVal(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txResult,
  uint8 newStateStop,
  uint8 newStateContinue
);

/**********************************************************************************************************************
  FrTp_TxSm_PrepareNxtCFaccordingBC()
**********************************************************************************************************************/
/*!
 * \brief       Decides whether to send a CF pdu immediately or after waiting SC cycles.
 * \details     Used by: FrTp_TxSm_CFTxConfirmation
 *              It shall be possible to call this function as often as desired by internal FrTpIso callers.
 * \param[in]   uint8 txSmIdx: PRE_FRTP_VALID_ACTIVE_TX_SM_IDX
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpBandwidthControl
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_PrepareNxtCFaccordingBC(
  uint8 txSmIdx
);

/**********************************************************************************************************************
  FrTp_TxSm_FrIfTransmit()
**********************************************************************************************************************/
/*!
 * \brief       Passes the FrTps request to transmit a data pdu on the underlying bus system to the FrIf.
 * \details     Whether burst mode is possible can be determined by looking at pdu type.
 * \param[in]   P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) TPCI: Pointer and length of the FrTp-generated TPCI
 * \param[in]   P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) payload: Pointer and length to the fragment of the payload 
 *              the PduR wants to transmit via TP.
 * \param[in]   uint8 txSmIdx: PRE_FRTP_VALID_ACTIVE_TX_SM_IDX
 * \return      Return code: FrTp_TxReturnType: Preprocessed return code of the FrIf_Transmit()-call.
 * \return      FrTp_TxOkContinue: This value means the tx-state-machine shall continue consuming bandwidth.
 * \return      FrTp_TxOkStop: This value means the tx-state-machine shall stop consuming bandwidth.
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface
 ********************************************************************************************************************/
FRTP_LOCAL FUNC(FrTp_TxReturnType, FRTP_CODE) FrTp_TxSm_FrIfTransmit(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI, 
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pPayload, 
  uint8 txSmIdx
);

/**********************************************************************************************************************
  FrTp_TxSm_PrepareAllSms()
**********************************************************************************************************************/
/*! 
 * \brief       Decreases the variable 'Timer' and resets the 'CounterMNPC' of each active tx-state-machine.
 * \details     Decrement timers and reset MNPC only once per FrTp_MainFunction-call.
 *              This correlates to the condition that FrTp_MainFunction() shall be called exactly once per FR-cycle
 * \return      sint16_least activeSms: Number of state-machines found active operating a connection
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpMainFunction
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint16_least, AUTOMATIC) FrTp_TxSm_PrepareAllSms(
  void
);

/**********************************************************************************************************************
  FrTp_TxSm_TimeoutOf()
**********************************************************************************************************************/
/*!
 * \brief       Evaluates the tx-state-machines state-machine in case the Timer has reached the value of 0.
 * \details     Decrement timers and reset MNPC only once per FrTp_MainFunction-call.
 *              This correlates to the condition that FrTp_MainFunction() shall be called exactly once per FR-cycle
 *              In case the tx-state-machine is still active after the call then its member Timer will be >0.
 * \param[in]   P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl: of the tx-state-machines connection
 * \param[in]   volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm: current tx-state-machine pointer
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_PTR pTxSm
 * \param[in]   uint8 txSmIdx: Index of the tx-state-machine that currently operates a segm. transmission
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_IDX txSmIdx
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpActionAndTimeoutHandling, DSGN-FrTpMainFunction
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_TimeoutOf(
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl,
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FrTp_TxSm_TriggerTransmit()
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
FUNC(Std_ReturnType, FRTP_CODE) FrTp_TxSm_TriggerTransmit(
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxPduInfoPtr,
  PduIdType FrIfTxPduId,
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pErrorId
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  P2VAR(FrTp_DecoupPduAdminType, AUTOMATIC, FRTP_APPL_DATA) pDecoupAdminData = &FrTp_FrIf_GetDecoupAdminById(FrIfTxPduId);
  PduIdType connIdx = pDecoupAdminData->ConnCfgPtr->ConnIdx;
  P2VAR(FrTp_ConnStateType, AUTOMATIC, FRTP_APPL_DATA) pConnState = FrTp_VCfg_ConnState(connIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the affected connection is indeed busy transmitting data:
   *          Retrieve pointer to tx-state-machine */
  if(pConnState->CurrTxSmIdx != FrTp_NoSm)
  {  
    volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(pConnState->CurrTxSmIdx);
    
    /* #20 In case the tx-state-machine expects at least one FrTp-TriggerTransmit-call:
     *            Set return value of the FrTp_TriggerTransmit-call to E_OK */
    if(FrTp_TxSm_Item(pTxSm, CurrDecPdusPending) > 0u)
    {
      /* #30 In case the length the FrIf wants to trigger is larger or equal than the pdu-length planned by FrTp:
       *              Prepare copying the tx-data from the PduR */
      if(    (pDecoupAdminData->PduInfoPayload.SduLength + pDecoupAdminData->PduLengthTPCI) 
          <= (FrTpTxPduInfoPtr->SduLength)
        )
      {
        /* #40 In case at least one byte of payload shall be contained in the pdu:
         *                It is a pdu of a tx-state-machine that expects data to be triggered */
        if(FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) != 0u)
        {
          /* #50 In case that pdu will contain at least as many payload-bytes as planned by the tx-state-machine:
           *                  Actually tx-data is copied _late_ from PduR to the state-machine-specific tx-data buffer, using PduR_FrTpCopyTxData() */
          if(FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) >= pDecoupAdminData->PduInfoPayload.SduLength)
          {
            PduInfoType applPduInfo;
            PduLengthType availableTxData = 0u;
            PduLengthType pduLen = pDecoupAdminData->PduInfoPayload.SduLength;
            uint8 txSmIdx = FrTp_VCfg_ConnState(pDecoupAdminData->ConnCfgPtr->ConnIdx)->CurrTxSmIdx;

            /* #60 Initialize the applPduInfo to let it point to the state-machine-specific tx-data buffer and length.
             *                    Call PduR_FrTpCopyTxData().
             *                    Decrease the tx-state-machines byte-counter of payload still to be fetched by FrTp_TriggerTransmit()-calls */
            applPduInfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))FrTp_VCfg_TxBuf(txSmIdx);
            /* PRQA L:REQUIRED_TO_PASS_16_BIT_ALIGNED_INTERNAL_PTR_TO_ASR_COMPONENTS */
            applPduInfo.SduLength = pduLen;
            if(PduR_FrTpCopyTxData(
               /*PduIdType id=*/pDecoupAdminData->ConnCfgPtr->FrTpSduTxId, /* SBSW_FRTP_PDUR_COPYTXDATA_ACTUALLY_COPY */
               /*PduInfoType* info=*/&applPduInfo,
               /*RetryInfoType* retry=*/(RetryInfoType*)NULL_PTR,
               /*PduLengthType* availableDataPtr=*/&availableTxData
                                  ) == BUFREQ_OK) /* SBSW_FRTP_PDUR_COPYTXDATA_ACTUALLY_COPY */
            {
              FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) = /* SBSW_FRTP_TXSM_PTR_FROM_VALID_CONN_DATA */
                (PduLengthType)(FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) - pduLen); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_CONN_DATA */
              retVal = E_OK;
            }
          }
        }
        else
        /* #70 Otherwise it is a tx-pdu that contains no data, i.e. a LF with 0 bytes:
         *                Indicate via variable retVal that the '0 bytes' of data required for an LF are all there */
        {
          retVal = E_OK;
        }
        
        /* #80 Update the number of decoupled pdus of that connection that still have to be copied by FrIf */
        FrTp_TxSm_Item(pTxSm, CurrDecPdusPending)--; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_CONN_DATA */

        /* #90 In case either:
         *                All pending pdus of the tx-state-machines have now been fetched by FrTp_TriggerTransmit() or
         *                there are BOTH bytes AND pdus to be fetched by FrTp_TriggerTransmit() or
         *                there still is a LF with 0 bytes to come, i.e. there are NO bytes but STILL ONE pdu to be fetched by FrTp_TriggerTransmit():
         *                Then the retVal to be returned to and by FrTp_TriggerTransmit() is set to E_OK.
         *                Otherwise errorId of FrTp_TriggerTransmit() is set (via pErrorId) to indicate an error. */
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
        if(    (!(    (FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) == 0u)
                   && (FrTp_TxSm_Item(pTxSm, CurrDecPdusPending) == 0u)
                 )
               )
            &&
               (!(    (FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) > 0u)
                   && (FrTp_TxSm_Item(pTxSm, CurrDecPdusPending) > 0u)
                 )
               )
            &&
               (!(    (FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) == 0u)
                   && (FrTp_TxSm_Item(pTxSm, CurrDecPdusPending) == 1u)
                 )
               )
          )
        {
          retVal = E_NOT_OK;
          *pErrorId = FRTP_WRONG_PARAM_VAL; /* SBSW_FRTP_ERRORID_PTR */
        }
#endif
      }
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
      else
      {
        *pErrorId = FRTP_WRONG_PARAM_VAL; /* SBSW_FRTP_ERRORID_PTR */
      }
#endif
      /* #100 In case retVal is E_OK (which indicates "no payload-data required" for rx-state-machines or "payload-data is there as required" for tx-state-machines)
       *              and all consistency checks, above, were ok:
       *              Assemble the pdu. */
      if(retVal == E_OK)
      {
        PduInfoType TPCI;

        TPCI.SduLength = pDecoupAdminData->PduLengthTPCI;
        TPCI.SduDataPtr = pDecoupAdminData->TPCIData;
        FrTpTxPduInfoPtr->SduLength = FrTp_Util_AssemblePdu( /* SBSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU */
          pDecoupAdminData->ConnCfgPtr,
          &TPCI,
          &(pDecoupAdminData->PduInfoPayload),
          FrTpTxPduInfoPtr->SduDataPtr
        ); /* SBSW_FRTP_ASSEMBLE_TRIGRD_TXSM_PDU */
      }
    }
  }
#if (FRTP_DEV_ERROR_DETECT == STD_OFF)
  FRTP_DUMMY_STATEMENT(pErrorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  return retVal;
} /* FrTp_TxSm_TriggerTransmit */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
  FrTp_TxSm_FrIfTransmit()
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
FRTP_LOCAL FUNC(FrTp_TxReturnType, FRTP_CODE) FrTp_TxSm_FrIfTransmit(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI, 
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pPayload, 
  uint8 txSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  FrTp_TxReturnType retVal = FrTp_TxNotOk;
  /* #10 Retrieve pointer to the configuration of the connection operated in that state-machine
   *          Retrieve pointer to the configuration of the tx-pdu used by the tx-state-machine
   *          Retrieve index of the next free tx-pdu planned by that state-machine
   *          Retrieve pointer to the admin data of the pool that is used by the connection */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
  P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA) pPoolDataUsed = FrTp_FrIf_GetTxPduPoolDataPtrByOffset(FrTp_ConnGetTxPoolOffset(pConnCfg));
  uint8 intTxPduIdx = FrTp_TxSm_Item(pTxSm, NxtFreePduIdx);
  P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu = FrTp_CCfg_FrIfTxPdus(intTxPduIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 The decision about Tx-Pdu being the last in cycle or not depends on the currPCI
   *          In case currPCI is */
  switch(FrTp_TxSm_Item(pTxSm, CurrPCI))
  {
    case FrTp_PCILF:
      /* no break; */
    case FrTp_PCICFEOB:
      /* no break; */
    case FrTp_PCISTFunseg:
      /* no break; */
    case FrTp_PCISTFseg:
    /* #30 of value FrTp_PCILF
     *            or of value FrTp_PCICFEOB
     *            or of value  FrTp_PCISTFunseg
     *            or of value FrTp_PCISTFseg then it is the very last pdu of this state-machine in this FR-cycle */
      retVal = FrTp_TxOkStop;
      break;
    case FrTp_PCICF1:
    /* #40 of value FrTp_PCICF1 then it can possibly be followed by other pdus in this FR-cycle (set retVal accordingly) */
    {
      uint8 mnpc = (uint8)(FrTp_TxSm_Item(pTxSm, CurrMNPC));

      retVal = FrTp_TxOkStop;
      /* #50 In case the current MNPC value is ineffective
       *              or not exceeded by the state-machines CounterMNPC
       *              and there is tx-data available:
       *              Set retVal to indicate that burst mode is possible */
      if(    (    (mnpc == 0u)
               || (    (mnpc > 1)
                    && ((((uint8)FrTp_TxSm_Item(pTxSm, CounterMNPC)) + 1) < mnpc)
                  )
             )
          && (FrTp_TxSm_Item(pTxSm, AvailableTxData) > 0u)
        )
      {
        retVal = FrTp_TxOkContinue;
      }
      break;
    }
    default:
      break;
  }
  /* #60 In case the NumFreePdus counter of pool admin data is one or less:
   *     Indicate that it is the last pdu in this FR-cycle by setting CounterMNPC to CurrMNPC-1 (in case there is a mnpc limitation) */
  if(FrTp_FrIf_GetTxPduPoolDataItemByPtr(pPoolDataUsed, NumFreePdus) <= 1)
  {
    uint8 mnpc = (uint8)FrTp_TxSm_Item(pTxSm, CurrMNPC);
    FrTp_TxSm_Item(pTxSm, CounterMNPC) = (uint8)(FrTp_MNPCMaskNoShift & /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
                                                 (uint8)((0u == mnpc) ? FrTp_TxSm_Item(pTxSm, CounterMNPC) : (mnpc - 1))); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    retVal = FrTp_TxOkStop;
  }

  /* #70 In case the FrIf accepts the transmit-request: Update the admin data of state-machine and pdu */
  if(FrTp_FrIf_TransmitPduForConn(pConnCfg, pFrIfTxPdu, pTPCI, pPayload) == E_OK) /* SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_TX_CONN */
  {
    /* #80 In case the tx-pdu is 'decoupled': Update the number of decoupled pdus still to be copied by FrIf */
    if(FrTp_FrIf_IsDecoupPdu(*pFrIfTxPdu)) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359*/
    { /* PRQA S 3201 */ /* MD_FrTp_3201 */
      FrTp_TxSm_Item(pTxSm, CurrDecPdusPending)++; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    }
    /* #90 Set the tx-part of the pending-flag-arrays
     *            Increment the number of pending FrIf-Tx-Confirmations
     *            Indicate that there is no next free pdu
     *            Increment the counter that tracks the pdus per cycle
     *            Decrement the number of free tx-pdus in all pools affected */
    FrTp_FrIf_ExpectTxConfForTxPduOfTxSm(intTxPduIdx, txSmIdx); /* SBSW_FRTP_STORE_VALID_TXSM_IDX_FROM_CALLER */
    (FrTp_TxSm_Item(pTxSm, PendingTxConfs))++; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    FrTp_TxSm_Item(pTxSm, NxtFreePduIdx) = FrTp_NoPdu; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    FrTp_TxSm_Item(pTxSm, CounterMNPC)++; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    FrTp_FrIf_DecreaseNumFreePdusOverlapped(pFrIfTxPdu); /* SBSW_FRTP_VALID_FRIF_TXPDU_IN_TXSM */
  }
  else
  /* #100 Otherwise the transmit-request failed: Set retVal to 'not ok' */
  {
    retVal = FrTp_TxNotOk;
  }
  return retVal;
} /* FrTp_TxSm_FrIfTransmit */

/**********************************************************************************************************************
  FrTp_TxSm_FrIfTxConfirmation()
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
FUNC(void, FRTP_CODE) FrTp_TxSm_FrIfTxConfirmation(
  uint8 txSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Retrieve pointers to tx-state-machine, connCfg, connCtrl */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl = pConnCfg->ConnCtrlPtr;

  /* ----- Implementation ----------------------------------------------- */
  FrTp_TxSm_Item(pTxSm, PendingTxConfs) = (uint8)(FrTp_TxSm_Item(pTxSm, PendingTxConfs) - 1u); /* SBSW_FRTP_RXTX_PENDING_VALUES */
  /* #15 In case PendingTxConfs of the tx-state-machine is 0
   *                  Inform all affected channels of the TxConfirmation
   *                  In any case inform all affected pools of the TxConfirmation */
  if(0u == (FrTp_TxSm_Item(pTxSm, PendingTxConfs)))
  {
    /* #20 In case the state-machine-state is */
    switch(FrTp_TxSm_Item(pTxSm, State))
    {
      case FrTp_TxSm_WaitForTxConfNonBurstSTFunseg:
      /* #40 of value FrTp_TxSm_WaitForTxConfNonBurstSTFunseg then the STF is unsegmented:
       *            Inform the PduR that the transmission has been finished successfully: */
        FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_OK);
        break;
      case FrTp_TxSm_WaitForTxConfNonBurstSTFseg:
      /* #50 In case PendingTxConfs of the tx-state-machine is 0
       *                  Inform all affected channels of the TxConfirmation
       *                  In any case inform all affected pools of the TxConfirmation */
        FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_WaitFC; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(pConnCtrl, TimeoutBs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        break;
      case FrTp_TxSm_WaitForTxConfBurstCF:
      /* #60 of value FrTp_TxSm_WaitForTxConfBurstCF then (a | one of the) CF(s) has been confirmed:
       *            Confirm the CF at the affected tx-state-machine */
        (void)FrTp_TxSm_CFTxConfirmation(txSmIdx);
        break;
      default:
        break;
    }
  }
} /* FrTp_TxSm_FrIfTxConfirmation */ /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if( FRTP_RX_IND_EARLIER_THAN_TX_CONF == STD_ON )
/**********************************************************************************************************************
  FrTp_TxSm_TolerateRxIndEarlierThanTxConf()
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
/* PRQA S 3673 4 */ /* MD_FrTp_3673 */
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_TxSm_TolerateRxIndEarlierThanTxConf(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
)
{
  /* #10 In case the rx-state-machine is currently waiting for the tx-confirmation of a STF or CF:
   *     Call the internal tx-confirmation function bring the state machine to the expected state */
  switch(FrTp_TxSm_Item(pTxSm, State)) 
  {
    case FrTp_TxSm_WaitForTxConfNonBurstSTFseg:
      /* no break; */
    case FrTp_TxSm_WaitForTxConfBurstCF:
      /* #20 of value FrTp_TxSm_WaitForTxConfNonBurstSTFseg or FrTp_TxSm_WaitForTxConfBurstCF:
       *              In case the tx-state-machine has no FrTp_TriggerTransmit()-calls pending:
       *              Call the TxConfirmation() of the affected tx-state-machine to correct the inversion of rx-indication and tx-confirmation  */
      if(FrTp_TxSm_Item(pTxSm, CurrDecPdusPending) == 0u)
      {
        FrTp_TxSm_FrIfTxConfirmation(txSmIdx);
      }
      break;
    default:
      /* #30 of any other value (i.e. not expecting a tx-confirmation: Do nothing */
      break;
  }
} /* FrTp_TxSm_TolerateRxIndEarlierThanTxConf */
#endif

/**********************************************************************************************************************
  FrTp_TxSm_FrIfRxIndication()
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
/* PRQA S 3673 5 */ /* MD_FrTp_3673 */
FUNC(void, FRTP_CODE) FrTp_TxSm_FrIfRxIndication(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl = pConnCfg->ConnCtrlPtr;
  
  /* ----- Implementation ----------------------------------------------- */
#if( FRTP_RX_IND_EARLIER_THAN_TX_CONF == STD_ON )
  FrTp_TxSm_TolerateRxIndEarlierThanTxConf(pTxSm, txSmIdx); /* SBSW_FRTP_RX_IND_EARLIER_THAN_TX_CONF */
#endif
  /* #10 In case the state-machine-state is of value FrTp_TxSm_WaitFC (i.e. the pdu is expected) AND the PCI-byte of the Pdu is of type FC */
  if(    (FrTp_TxSm_Item(pTxSm, State) == FrTp_TxSm_WaitFC)
      && ((uint8)(dataPtr[0] & FrTp_PduTypeMask) == FrTp_PCIFC)
    )
  {
    /* #50 In case the pduSubType is */
    switch((dataPtr[0] & FrTp_PduSubTypeMask))
    {
      case FrTp_FCCTS:
      /* #60 of value FrTp_FCCTS then a FC is awaited
        *                  Read BC parameter from pdu
        *                  Extract MNPC from BC
        *                  Read Bfs parameter from pdu
        *                  Calculate remainingBytes of this transmission */
      {
        uint8 BChelper = FrTp_Util_ReadBC(dataPtr);
        uint8 MNPChelper = (uint8)((BChelper & FrTp_MNPCMask) >> FrTpIsoMNPCBitPos);
        uint16 BfsValue = FrTp_Util_ReadBfS(dataPtr);
        uint16 remainingBytes = (uint16)FrTp_TxSm_CalcRemainingBytes(pTxSm);
        P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg = FrTp_FrIf_GetTxPduPoolPtrByOffset(FrTp_ConnGetTxPoolOffset(pConnCfg));

        /* #70 Extract SC and corresponding timer-value from BC
          *                    Limit MNPC to the number of tx-pdus configured for the connection
          *                    Store that final MNPC value in the state-machine-variable CurrMNPC
          *                    Reset counterMNPC to start anew after a FC.CTS */
        FrTp_TxSm_Item(pTxSm, TimerVal4CurrSC) = FrTp_TxSm_GetSepCyclesFor[(BChelper & FrTp_SCexpMask)]; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        MNPChelper = (uint8)FrTp_Min(MNPChelper, pPoolCfg->NumPdus);
        FrTp_TxSm_Item(pTxSm, CurrMNPC) = MNPChelper; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        FrTp_TxSm_Item(pTxSm, CounterMNPC) = 0U; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */

        /* #80 In case the BfS indicated by receiver is larger than the length of the data to transfer:
          *                    Set BfsValue to 0u (which is equivalent to 'plenty of space')
          *                    Otherwise leave BfsValue on the value indicated by the receiver and:
          *                    In case BfsValue is non-zero:
          *                    Recognize that block-mode is currently active */
        if(BfsValue >= remainingBytes)
        {
          BfsValue = 0u;
          FrTp_TxSm_Item(pTxSm, IsBlockMode) = FALSE; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        }
        else
        {
          FrTp_TxSm_Item(pTxSm, IsBlockMode) = (uint8)((BfsValue != 0u) ? TRUE : FALSE); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        }

        /* #90 Store the BfsValue in the tx-state-machines' runtime-data
          *                    Set the current pdu-type to CF, always, because:
          *                    1. a FC.CTS after CF_EOB has to result in a change of currPCI to CF1, and
          *                    2. a CF comes after a STF which requires a change of currPCI to CF1, also
          *                    Set timer to retrieve the data for the next pdu within performance requirement FrTpTimeCs
          *                    Set the tx-state-machine to state FrTp_TxSm_WaitForDataCF */
        FrTp_TxSm_Item(pTxSm, RemainingBytesInBlock) = ((PduLengthType)BfsValue); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        FrTp_TxSm_Item(pTxSm, CurrPCI) = FrTp_PCICF1; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeCs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_WaitForDataCF; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        break;
      }
      case FrTp_FCWT:
      /* #100 of value FrTp_FCWT then the receiver wants additional waiting time:
        *                  Set the timer to its initial value, again */
          FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(pConnCtrl, TimeoutBs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        break;
      case FrTp_FCOVER:
        /* no break; */
      case FrTp_FCABT:
        /* no break; */
      default:
      /* #110 of value FrTp_FCOVER then the receiver reported an Overrun
        *     or of value FrTp_FCABT then the receiver reported "abort"
        *     or of an invalid value, i.e. Receiver sent an invalid flow status:
        *     Terminate transmission with error */
        FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_NOT_OK);
        break;
    }
  }
  /* #120 In case the state-machine-state is of a value that is different from "expecting a FC" OR different from state required for the "tolerate early FC"-feature: The FC.CTS is ignored */
} /* FrTp_TxSm_FrIfRxIndication() */

/**********************************************************************************************************************
  FrTp_TxSm_PrepareAllSms()
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
 */
FRTP_LOCAL_INLINE FUNC(sint16_least, AUTOMATIC) FrTp_TxSm_PrepareAllSms(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  sint16_least activeSms = 0;
  uint8_least txSmIdx;
  
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Loop all tx-state-machines */
  for(txSmIdx = (uint8)0u; txSmIdx< FrTp_CCfg_NumTxChan(); txSmIdx++)
  {
    volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState((uint8)txSmIdx);

    /* #20 In case the (countdown-)timer is not yet 0:
     *            Decrease the timer of the current tx-state-machine */
    if(FrTp_TxSm_Item(pTxSm, Timer) != 0u)
    {
      FrTp_TxSm_Item(pTxSm, Timer)--; /* SBSW_FRTP_TXSM_PTR_FROM_VALIDLIY_INDEXED_LOOP */
      /* #30 In case at least the last real external tx-confirmation has come in
       *              and the Timer is 0 when state-machine-state is FrTp_TxSm_WaitForDataCF:
       *              Reset the CounterMNPC at the beginning of each FrTp_MainFunction() (i.e. once each FR-cycle) */
      if(    (FrTp_TxSm_Item(pTxSm, State) == FrTp_TxSm_WaitForTxConfBurstCF)
          || (    (FrTp_TxSm_Item(pTxSm, State) == FrTp_TxSm_WaitForBCexpiry)
               && (FrTp_TxSm_Item(pTxSm, Timer) > 0)
             )      
        )
      {
      }
      else
      {
        FrTp_TxSm_Item(pTxSm, CounterMNPC) = 0u; /* SBSW_FRTP_TXSM_PTR_FROM_VALIDLIY_INDEXED_LOOP */
      }
      /* #40 In oder to prepare round-robin conducted of the succeeding parts of the tx-part of the FrTp_MainFunction()
       *              Indicate that the tx-state-machine is allowed to take part in the round-robin
       *              Increase the active state-machines counter in order to prepare the round-robin */
      FrTp_TxSm_Item(pTxSm, RobsRound) = TRUE; /* SBSW_FRTP_TXSM_PTR_FROM_VALIDLIY_INDEXED_LOOP */
      activeSms++;
    }
  }
  return activeSms;
} /* FrTp_TxSm_PrepareAllSms */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
  FrTp_TxSm_TimeoutOf()
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
 *
 *
 *
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_TimeoutOf(
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl,
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
) 
{
  sint8 deltaActiveSms = FrTp_DropOut;
  /* #10 In case the state-machine-state is */
  switch(FrTp_TxSm_Item(pTxSm, State))
  {
    case FrTp_TxSm_WaitForBCexpiry:
    /* #20 of value FrTp_TxSm_WaitForBCexpiry:
     *            'SC cycles' have passed by.
     *            Reset CounterMNPC in order to allow transmitting the next pdu or pdu-burst
     *            Set timer to TimeoutAs as timeout for that state
     *            Set the tx-state-machine to state FrTp_TxSm_WaitForDataCF */
      FrTp_TxSm_Item(pTxSm, CounterMNPC) = 0u; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(pConnCtrl, TimeCs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_WaitForDataCF; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      deltaActiveSms = FrTp_StayIn;
      break;
    case FrTp_TxSm_WaitForDataSTF:
      /* no break; */
    case FrTp_TxSm_WaitForDataCF:
    /* #30 of value FrTp_TxSm_WaitForDataSTF
     *            or of value FrTp_TxSm_WaitForDataCF:
     *            No FrTp_TriggerTransmit call of decoupled tx-pdus of that connection may be pending when new buffer is retrieved
     *            In case the number of decoupled tx-pdus pending for that tx-state-machine is 0
     *            Ask for new tx-data by calling CopyTxData for the very last time. */
      if(FrTp_TxSm_Item(pTxSm, CurrDecPdusPending) == 0u)
      {
        deltaActiveSms = FrTp_TxSm_CopyTxData(txSmIdx);
      }
      /* #40 In case the PduR has decided to end transmission:
       *              Terminate transmission with error */
      if(deltaActiveSms == FrTp_DropOut)
      {
        FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_NOT_OK);
      }
      break;
    case FrTp_TxSm_WaitForTxConfNonBurstSTFunseg:
      /* no break; */
    case FrTp_TxSm_WaitForTxConfNonBurstSTFseg:
      /* no break; */
    case FrTp_TxSm_WaitForTxConfBurstCF:
      /* no break; */
    case FrTp_TxSm_WaitForTxConfBurstCFIntrnl:
      /* no break; */
    case FrTp_TxSm_WaitFC:
      /* no break; */
    default:
    /* #50 of value FrTp_TxSm_WaitForTxConfNonBurstSTFunseg
     *            or of value FrTp_TxSm_WaitForTxConfNonBurstSTFseg
     *            or of value FrTp_TxSm_WaitForTxConfBurstCF
     *            or of value FrTp_TxSm_WaitForTxConfBurstCFIntrnl
     *            or of value FrTp_TxSm_WaitFC
     *            or of an invalid value
     *            Terminate transmission with error */
      FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_NOT_OK);
      break;
  }
  return deltaActiveSms;
} /* FrTp_TxSm_TimeoutOf */

/**********************************************************************************************************************
  FrTp_TxSm_OperateAllSms()
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
 *
 *
 *
 *
 *
 */
FUNC(void, FRTP_CODE) FrTp_TxSm_OperateAllSms(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least iter;
  sint16_least activeSms;
  uint8 firstSmWithoutPdu = FrTp_NoSm;
  uint8 txSmIdx = *FrTp_LCfg_TxCurrRoundRobChan();
  
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter FRTP_EXCLUSIVE_AREA_0 */
  FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* #20 Decrease timers and reset MNPC of all tx-state-machines.
   *          As long as activeSms > 0 iterate the activeSms but at max as many times as are required to transmit all tx-pdus */
  activeSms = FrTp_TxSm_PrepareAllSms();
  for(iter = 0u; ((iter < *FrTp_LCfg_TxSm_MaxIterations()) && (activeSms > 0)); iter++)
  {
    /* #30 In the body of the loop operate the tx-state-machine determined by txSmIdx
     *            In case the tx-state-machine is not idle
     *            and is still taking part in the round robin (i.e. still has tx-data to transmit) */
    if(    (FrTp_TxSm_Idle != FrTp_VCfg_TxState(txSmIdx)->State)
        && (FrTp_VCfg_TxState(txSmIdx)->RobsRound == TRUE)
      )
    {
      /* #40 Operate the active tx-state-machine
       *              Retrieve a pointer to the tx-state-machine to operate */
      volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
      P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
      P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl = pConnCfg->ConnCtrlPtr;
      uint8 poolOffset = FrTp_ConnGetTxPoolOffset(pConnCfg);
      P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA) pPoolDataUsed = FrTp_FrIf_GetTxPduPoolDataPtrByOffset(poolOffset);
      P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg = FrTp_FrIf_GetTxPduPoolPtrByOffset(poolOffset);
      sint8 deltaActiveSms = FrTp_StayIn;
      uint8 locNxtPduIdx;

      /* #50 Get the the next free tx-pdu index in the pool used, according to the connections BandwidthLimitation flag:
       *              Passing a pdu-limit of 0 means that no limitation is done, otherwise the state-machines CurrMNPC is used as pdu-limit */
      locNxtPduIdx = FrTp_FrIf_FindFreeTxPdu( /* SBSW_FRTP_FIND_FREE_TX_PDU_FOR_TXSM */
        pPoolCfg,
        pPoolDataUsed,
        (uint8)((pConnCfg->FrTpBandwidthLimitation != 0u) ? FrTp_TxSm_Item(pTxSm, CurrMNPC) : 0u)
      ); /* SBSW_FRTP_FIND_FREE_TX_PDU_FOR_TXSM */
      /* #60 In case at this time there has not yet a state-machine run out of tx-pdus to send
       *              and the pool used by the connection currently operated has no more free tx-pdus:
       *              Store that state-machine in 'firstSmWithoutPdu' */
      if(    (firstSmWithoutPdu == FrTp_NoSm)
          && (locNxtPduIdx == FrTp_NoPdu)
        )
      {
        firstSmWithoutPdu = txSmIdx;
      }
      /* #70 Assign the NxtFreePduIdx to the tx-state-machine that is currently operated */
      FrTp_TxSm_Item(pTxSm, NxtFreePduIdx) = locNxtPduIdx; /* SBSW_FRTP_VALID_WRAPPED_TXSM_IDX */
      /* #80 In case the tx-state-machines Timer is 0u:
       *              evaluate the timeout that has happened according to the state-machine-state: */
      if(FrTp_TxSm_Item(pTxSm, Timer) == 0u)
      {
        deltaActiveSms = FrTp_TxSm_TimeoutOf(pConnCtrl, pTxSm, txSmIdx); /* SBSW_FRTP_TIMEOUT_AND_ACTION_OF_TXSM */
      }
      /* #90 In case the timer is non-zero after the timeout-handling (i.e. the tx-state-machine is still busy)
       *              and the tx-state-machine had no other reason for droping out of the round-robin:
       *              Continue operation by conducting the action that is related to the current state of the tx-state-machine */
      if(    (deltaActiveSms == FrTp_StayIn)
          && (FrTp_TxSm_Item(pTxSm, Timer) != 0)
        )
      {
        /* #100 In case there is a tx-pdu available for the current tx-state-machine:
         *                Conduct the action that is related to the current state, e.g.:
         *                Prepare the transmission of the next tx-pdu to be sent by the current tx-state-machine */
        if(FrTp_TxSm_Item(pTxSm, NxtFreePduIdx) != FrTp_NoPdu) /* SBSW_FRTP_VALID_FREE_TXPDU */
        {
          deltaActiveSms = FrTp_TxSm_ActionOf(pTxSm, txSmIdx); /* SBSW_FRTP_TIMEOUT_AND_ACTION_OF_TXSM */
          /* #110 In case the state-machine decided to drop out of round-robin:
           *                  Reset the robin-flag: */
          if(deltaActiveSms == FrTp_DropOut)
          {
            FrTp_TxSm_Item(pTxSm, RobsRound) = FALSE; /* SBSW_FRTP_VALID_WRAPPED_TXSM_IDX */
          }
        }
        else
        /* #120 Otherwise no tx-pdu is available, so the round-robin ends for that state-machine.
                At this moment round-robin might also be finished for all other tx-state-machines that use the affected tx-pdu-pool */
        {
          deltaActiveSms = FrTp_DropOut;
          FrTp_TxSm_Item(pTxSm, RobsRound) = FALSE; /* SBSW_FRTP_VALID_WRAPPED_TXSM_IDX */
        }
      }
      activeSms = activeSms + deltaActiveSms;
    }
    /* #130 Increase the index of the tx-state-machine (txSmIdx) to operate */
    txSmIdx++;
    /* #140 In case the txSmIdx is larger or equal than the number of tx-state-machines configured:
     *            Do a 'wrap around' by resetting its value to 0u */
    if(txSmIdx >= FrTp_CCfg_NumTxChan()) /* PRQA S 3355, 3358 */ /* MD_FrTp_3355, MD_FrTp_3358 */ /* SBSW_FRTP_TXSM_IDX_WRAP_AROUND_CHECK */
    {
      txSmIdx = 0u;
    }
  }
  /* #150 In case the distribution of tx-pdus has ended with at least one state-machine that has gotten no tx-pdu although it wanted to:
   *          Store that state-machines index to start with it when distributing tx-pdus again in the next call to FrTp_MainFunction()
   *          Otherwise all state-machines are 'happy', i.e..
   *          Store the index of the last tx-state-machine that sent data for the next call to FrTp_MainFunction() */
  if(firstSmWithoutPdu != FrTp_NoSm)
  {
    *FrTp_LCfg_TxCurrRoundRobChan() = firstSmWithoutPdu; /* SBSW_FRTP_LCFG_ACCESS */
  }
  else
  {
    *FrTp_LCfg_TxCurrRoundRobChan() = txSmIdx; /* SBSW_FRTP_LCFG_ACCESS */
  }
  /* #160 Leave FRTP_EXCLUSIVE_AREA_0 */
  FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* FrTp_TxSm_OperateAllSms */ /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
  FrTp_TxSm_EvalBufReqRetVal()
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
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_EvalBufReqRetVal(
  uint8 txSmIdx,
  uint8 bReq,
  uint8 newState,
  uint8 newCurrPCI
)
{
  sint8 deltaActiveSms = FrTp_DropOut;
  /* #10 In case the return value from PduR is */
  switch(bReq)
  {
    case BUFREQ_OK:
    /* #20 of value BUFREQ_OK:
     *            Buffer is there, but TimeCs is running: Thus assure that the next action will be done,
     *            set the tx-state-machine to state newState,
     *            set the currPCI to state newPduType and
     *            keep the state-machine in the FrTp_MainFunctions' round-robin. */
    {
      volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
      if(FrTp_TxSm_Item(pTxSm, Timer) == FrTp_TimerInIdle)
      {
        FrTp_TxSm_Item(pTxSm, Timer) = FrTp_TimerMinimum; /* SBSW_FRTP_VALID_TXSM_IDX_FROM_CALLER */
      }
      FrTp_TxSm_Item(pTxSm, CurrPCI) = newCurrPCI; /* SBSW_FRTP_VALID_TXSM_IDX_FROM_CALLER */
      FrTp_TxSm_Item(pTxSm, State) = newState; /* SBSW_FRTP_VALID_TXSM_IDX_FROM_CALLER */
      deltaActiveSms = FrTp_StayIn;
      break;
    }
    case BUFREQ_E_BUSY:
    /* #30 of value BUFREQ_E_BUSY:
     *            Leave state as it is, i.e. ask for buffer, again, in the next FrTp_MainFunction() call */
      break;
    case BUFREQ_E_OVFL:
      /* no break; */
    case BUFREQ_E_NOT_OK:
      /* no break; */
    default:
    /* #40 of value BUFREQ_E_OVFL
     *            or of value BUFREQ_E_NOT_OK
     *            or of an invalid value:
     *            Terminate transmission with error */
      FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_NOT_OK);
      break;
  }
  return deltaActiveSms;
} /* FrTp_TxSm_EvalBufReqRetVal */

/**********************************************************************************************************************
  FrTp_TxSm_CopyPayloadOnePdu()
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
FRTP_LOCAL_INLINE FUNC(BufReq_ReturnType, AUTOMATIC) FrTp_TxSm_CopyPayloadOnePdu(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) pApplPduInfo,
  P2VAR(PduLengthType, AUTOMATIC, FRTP_APPL_DATA) pAvailableTxData
)
{
  BufReq_ReturnType bReq;
  uint8 intTxPduIdx = FrTp_TxSm_Item(pTxSm, NxtFreePduIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
  P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu = FrTp_CCfg_FrIfTxPdus(intTxPduIdx);

  /* #10 In case the pdu is of transmission type 'decoupled':
   *          Do !not! copy any Tx-data into the internal buffer, as this is done, later, in the call to FrTp_TriggerTransmit().
   *          Store the payload-info in the decoupled admin data, in order to assemble the pdu in FrTp_TriggerTransmit(), later on.
   *          Initialize the SduDataPtr to make clear that there is no payload at the moment:
   *          Set flags, as if the copying has been done successfully */
  if(FrTp_FrIf_IsDecoupPdu(*pFrIfTxPdu)) /* PRQA S 3356, 3359 */ /* MD_FrTp_3356, MD_FrTp_3359*/
  { /* PRQA S 3201 */ /* MD_FrTp_3201 */
    P2VAR(FrTp_DecoupPduAdminType, AUTOMATIC, FRTP_APPL_DATA) pDecoupAdminData = &FrTp_FrIf_GetDecoupAdmin(*pFrIfTxPdu);
    pDecoupAdminData->PduInfoPayload.SduLength = FrTp_TxSm_Item(pTxSm, CopiedTxDataLen); /* SBSW_FRTP_INITIALIZE_DECOUP_ADMIN_DATA */
    pDecoupAdminData->PduInfoPayload.SduDataPtr = (SduDataPtrType)(NULL_PTR); /* SBSW_FRTP_INITIALIZE_DECOUP_ADMIN_DATA */
    bReq = BUFREQ_OK;
    FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) = /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      (PduLengthType)(FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) + pApplPduInfo->SduLength);
    *pAvailableTxData = *pAvailableTxData - pApplPduInfo->SduLength; /* SBSW_FRTP_STRUCT_WRT_UNCHANGED */
  }
  else
  /* #20 In case the pdu is of transmission type 'immediate':
   *          Copy Tx-data into the internal buffer, at once. */
  {
    bReq = PduR_FrTpCopyTxData( /* SBSW_FRTP_PDUR_COPYTXDATA_OPTIONALLY_COPY */
      /*PduIdType id=*/pConnCfg->FrTpSduTxId,
      /*PduInfoType* info=*/pApplPduInfo,
      /*RetryInfoType* retry=*/(RetryInfoType*)NULL_PTR,
      /*PduLengthType* availableDataPtr=*/pAvailableTxData
      ); /* SBSW_FRTP_PDUR_COPYTXDATA_OPTIONALLY_COPY */
  }
  return bReq;
} /* FrTp_TxSm_CopyPayloadOnePdu */

/**********************************************************************************************************************
  FrTp_TxSm_RequestAvailableTxData()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(BufReq_ReturnType, FRTP_CODE) FrTp_TxSm_RequestAvailableTxData(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) pApplPduInfo,
  P2VAR(PduLengthType, AUTOMATIC, FRTP_APPL_DATA) pAvailableTxData,
  PduLengthType requiredLength
)
{
  BufReq_ReturnType bReq;
  pApplPduInfo->SduLength = 0u; /* SBSW_FRTP_STRUCT_WRT_UNCHANGED */
  /* #10 Ask the application how many bytes of tx-data are available, at the moment */
  bReq = PduR_FrTpCopyTxData( /* SBSW_FRTP_PDUR_COPYTXDATA_AVAIL_BUF */
    /*PduIdType id=*/pConnCfg->FrTpSduTxId,
    /*PduInfoType* info=*/pApplPduInfo,
    /*RetryInfoType* retry=*/(RetryInfoType*)NULL_PTR,
    /*PduLengthType* availableDataPtr=*/pAvailableTxData
  ); /* SBSW_FRTP_PDUR_COPYTXDATA_AVAIL_BUF */
  if((((requiredLength != 0u) && (*pAvailableTxData < requiredLength)) || (*pAvailableTxData == 0u)) && (bReq == BUFREQ_OK))
  {
    bReq = BUFREQ_E_BUSY;
  }
  return bReq;
} /* FrTp_TxSm_RequestAvailableTxData */

/**********************************************************************************************************************
  FrTp_TxSm_CopyTxData()
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
 *
 *
 *
 *
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_CopyTxData(
  uint8 txSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
  PduLengthType availableTxData = FrTp_TxSm_Item(pTxSm, AvailableTxData);
  P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg = FrTp_FrIf_GetTxPduPoolPtrByOffset(FrTp_ConnGetTxPoolOffset(pConnCfg));
  PduLengthType currFPL = (uint8)(FrTp_CalcPduPayloadLen(pPoolCfg->MinPduLen, FrTp_PCISTFunseg));
  uint8 bReq;
  sint8 deltaActiveSms = FrTp_DropOut;
  PduInfoType applPduInfo;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Try to get tx-data from the PduR depending on the state of the tx-state-machine.
   *          In case the state is: */
  applPduInfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))FrTp_VCfg_TxBuf(txSmIdx);
  switch(FrTp_TxSm_Item(pTxSm, State))
  {
    /* #20 of value FrTp_TxSm_WaitForDataSTF:
     *            For functional connections, prepare getting tx-data of full length ML (i.e. DataLength)
     *            Actually call PduR_FrTpCopyTxData() */
    case FrTp_TxSm_WaitForDataSTF:
      /* #30 Ask the PduR how many tx-bytes are available, taking DataLength as minimum required length for functional connections, 0 otherwise: */
      bReq = FrTp_TxSm_RequestAvailableTxData(pConnCfg, &applPduInfo, &availableTxData, (uint8)((pConnCfg->MultRec == TRUE) ? FrTp_TxSm_Item(pTxSm, DataLength) : 0u)); /* SBSW_FRTP_RETRIEVE_AVAIL_TX_DATA */

      /* #40 In case the PduR does not cancel the transmission (i.e. the info about available data has been retrieved)
             Copy as much data as possible for a STF.
             In order to do that: Limit the data length to be copied to the MinPduLen of the tx-pdu-pool
             Actually copy the tx-data to the internal buffer */
      if(bReq == BUFREQ_OK)
      {
        FrTp_TxSm_Item(pTxSm, CopiedTxDataLen) = (uint8)((pConnCfg->MultRec == TRUE) ? FrTp_TxSm_Item(pTxSm, DataLength) : FrTp_Min(availableTxData, currFPL)); /* SBSW_FRTP_WRITE_TX_SM_PTR_FROM_VALID_ACTIVE_TX_SM_IDX */
        applPduInfo.SduLength = FrTp_TxSm_Item(pTxSm, CopiedTxDataLen);
        bReq = FrTp_TxSm_CopyPayloadOnePdu(pTxSm, &applPduInfo, &availableTxData); /* SBSW_FRTP_CALL_COPY_PAYLOAD_ONE_PDU */
      }
      FrTp_TxSm_Item(pTxSm, AvailableTxData) = availableTxData; /* SBSW_FRTP_WRITE_TX_SM_PTR_FROM_VALID_ACTIVE_TX_SM_IDX */
      /* #50 For functional communication there is no decision of segmentation because the required length of the STF is == DataLength:
             Note: Due to the above condition, the value of CopiedTxDataLen is always == DataLength, too. */

      if(FrTp_TxSm_Item(pTxSm, CopiedTxDataLen) < FrTp_TxSm_Item(pTxSm, DataLength))
      {
        deltaActiveSms = FrTp_TxSm_EvalBufReqRetVal(txSmIdx, bReq, FrTp_TxSm_WaitForTxnNonBurstSTFseg, FrTp_PCISTFseg);
      }
      else
      {
        deltaActiveSms = FrTp_TxSm_EvalBufReqRetVal(txSmIdx, bReq, FrTp_TxSm_WaitForTxnNonBurstSTFunseg, FrTp_PCISTFunseg);
      }
      break;
    
    case FrTp_TxSm_WaitForDataCF:
    {
      /* #100 of value FrTp_TxSm_WaitForDataCF:
       *              Calculate remainingBytesInTxn to check, whether it's the end of the transmission.
       *              Determine the currFPL of the pool of the connection.
       *              In case the transmission is at its end limit the currFPL to the remainingBytesInTxn */
      PduLengthType remainingBytesInTxn = FrTp_TxSm_CalcRemainingBytes(pTxSm);
      uint8 currPCI = FrTp_PCICF1;
      currFPL = (uint8)(FrTp_CalcPduPayloadLen(pPoolCfg->MinPduLen, currPCI));

      /* #110 In case the transmission is at its end:
       *              Limit the currFPL to the remainingBytesInTxn. */
      if(remainingBytesInTxn < currFPL)
      {
        currFPL = remainingBytesInTxn;
        /* #120 In case the currFPL at this very end of transmission does fit into a LF:
         *                Set the currPCI to FrTp_PCILF.
         *                Otherwise no LF is possible, yet: Leave currPCI at FrTp_PCICF1 */
        if(FrTp_CalcPduPayloadLen(pPoolCfg->MinPduLen, FrTp_PCILF) >= currFPL)
        {
          currPCI = FrTp_PCILF;
        }
      }

      /* #130 In case blockmode is active and the FPL would violate the blocksize: Limit the FPL and set currPCI back to CF_EOB */
      if(    (FrTp_TxSm_Item(pTxSm, IsBlockMode) == TRUE)
          && (FrTp_TxSm_Item(pTxSm, RemainingBytesInBlock) <= currFPL)
        )
      {
        currFPL = FrTp_TxSm_Item(pTxSm, RemainingBytesInBlock);
        currPCI = FrTp_PCICFEOB;
      }

      /* #140 Check, whether availableTxData is smaller than the [possibly limited] currFPL.
       *              In case the rest of the tx-data available is below the size of the pools tx-pdus to fill */
      if(availableTxData < currFPL)
      {
        /* #150 In case no pdus have been scheduled in this FrTp_MainFunction():
         *                Try to update the AvailableTxData value in order to [maybe] fill the tx-pdu with more bytes than the it would have been, before.
         *                Do this by asking how much tx-data is available, NOW (maybe more than last time)
         *                Otherwise leave availableTxData unchanged (i.e. work with that value during the remaining runtime of FrTp_Main*/
        if(FrTp_TxSm_Item(pTxSm, CurrDecTxDataPending) == 0)
        {
          bReq = FrTp_TxSm_RequestAvailableTxData(pConnCfg, &applPduInfo, &availableTxData, 0u); /* SBSW_FRTP_RETRIEVE_AVAIL_TX_DATA */
        }
        else
        {
          bReq = BUFREQ_OK;
        }
      }
      else
      {
        /* #160 AvailableTxData is sufficient to fill a pdu with a FPL of 'currFPL' bytes */
        bReq = BUFREQ_OK;
      }
      if(bReq == BUFREQ_OK)
      {
        if(    (availableTxData < currFPL)
            && (currPCI == FrTp_PCILF)
          )
        {
          /* #170 There is STILL FEWER data there than required ...
           *                  1. for the current status of the transmission according to the protocol rules
           *                  2. for the planned currPCI
           *                  ==> Set currPCI back to FrTp_PCICF1 */
          currPCI = FrTp_PCICF1;
        }
        /* #180 Try to copy as much data as possible but limit the length to be copied to the limited(!) FPL */
        FrTp_TxSm_Item(pTxSm, CopiedTxDataLen) = (uint8)FrTp_Min(availableTxData, currFPL); /* SBSW_FRTP_WRITE_TX_SM_PTR_FROM_VALID_ACTIVE_TX_SM_IDX */
        /* #190 Actually copy the tx-data to the internal buffer */
        applPduInfo.SduLength = FrTp_TxSm_Item(pTxSm, CopiedTxDataLen);
        bReq = FrTp_TxSm_CopyPayloadOnePdu(pTxSm, &applPduInfo, &availableTxData); /* SBSW_FRTP_CALL_COPY_PAYLOAD_ONE_PDU */
      }
      FrTp_TxSm_Item(pTxSm, AvailableTxData) = availableTxData; /* SBSW_FRTP_WRITE_TX_SM_PTR_FROM_VALID_ACTIVE_TX_SM_IDX */
      deltaActiveSms = FrTp_TxSm_EvalBufReqRetVal(txSmIdx, bReq, FrTp_TxSm_WaitForEndOfBurstCF, currPCI);
      
      break;
    }
    default:
      /* #200 A different state is not allowed, here */
      FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_NOT_OK);
  }
  return deltaActiveSms;
} /* FrTp_TxSm_CopyTxData */ /* PRQA S 6030 */ /* MD_MSR_STCYC */

/**********************************************************************************************************************
  FrTp_TxSm_EvalFrIfTransmitRetVal()
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
FRTP_LOCAL_INLINE FUNC(sint8, AUTOMATIC) FrTp_TxSm_EvalFrIfTransmitRetVal(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txResult,
  uint8 newStateStop,
  uint8 newStateContinue
)
{
  sint8 deltaActiveSms = FrTp_DropOut;
  switch(txResult)
  {
    /* #10 For all txResults != 'not ok':
     *            Update all byte-positions of the tx-state-machine
     *            After that, make clear that the data has been passed to FrIf, i.e. reset 'CopiedTxDataLen'
     *            Set timer to TimeoutAs as timeout for that state.
     *            For txResult 'continue' indicate to stay in the round robin process
     *            For txResult 'stop' indicate to drop out of the round robin process
     *            For txResult 'not ok' terminate transmission with error */
    case FrTp_TxOkContinue:
      FrTp_TxSm_Item(pTxSm, DataIndex) = (PduLengthType)(FrTp_TxSm_Item(pTxSm, DataIndex) + FrTp_TxSm_Item(pTxSm, CopiedTxDataLen)); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      FrTp_TxSm_Item(pTxSm, State) = newStateContinue; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(FrTp_TxSm_Item(pTxSm, ConnCfgPtr)->ConnCtrlPtr, TimeoutAs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      deltaActiveSms = FrTp_StayIn;
      break;
    case FrTp_TxOkStop:
      FrTp_TxSm_Item(pTxSm, DataIndex) = (PduLengthType)(FrTp_TxSm_Item(pTxSm, DataIndex) + FrTp_TxSm_Item(pTxSm, CopiedTxDataLen)); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      FrTp_TxSm_Item(pTxSm, State) = newStateStop; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(FrTp_TxSm_Item(pTxSm, ConnCfgPtr)->ConnCtrlPtr, TimeoutAs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      break;
    case FrTp_TxNotOk:
      FrTp_Rsrc_ReleaseTxSm(FrTp_VCfg_ConnState(FrTp_TxSm_Item(pTxSm, ConnCfgPtr)->ConnIdx)->CurrTxSmIdx, E_NOT_OK);
      break;
    default:
      break;
  }
  return deltaActiveSms;
} /* FrTp_TxSm_EvalFrIfTransmitRetVal */

/**********************************************************************************************************************
  FrTp_TxSm_ActionOf()
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
 *
 *
 *
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_ActionOf(
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  FrTp_TxReturnType txResult;
  PduInfoType payload;
  PduInfoType TPCI;
  uint8 tpciBuffer[FrTp_TPCIMaxLength];
  sint8 deltaActiveSms = FrTp_DropOut;
  /* ----- Implementation ----------------------------------------------- */
  TPCI.SduDataPtr = tpciBuffer;
  /* #10 In case the tx-state-machines' state is */
  switch(FrTp_TxSm_Item(pTxSm, State))
  {
    case FrTp_TxSm_WaitForDataSTF:
      /* no break; */
    case FrTp_TxSm_WaitForDataCF:
    /* #20 of value FrTp_TxSm_WaitForDataSTFfunc
     *            or of value FrTp_TxSm_WaitForDataSTFphys
     *            or of value FrTp_TxSm_WaitForDataCF:
     *            Try to copy data for the next tx-pdu from PduR */
      deltaActiveSms = FrTp_TxSm_CopyTxData(txSmIdx);
      break;
    case FrTp_TxSm_WaitForTxnNonBurstSTFseg:
      /* no break; */
    case FrTp_TxSm_WaitForTxnNonBurstSTFunseg:
    /* #30 of value FrTp_TxSm_WaitForTxnNonBurstSTFseg
     *            or of value FrTp_TxSm_WaitForTxnNonBurstSTFunseg
     *            Prepare transmission of an STF-pdu, i.e.:
     *            Initialize internal field expectedSN
     *            Write ML- and FPL-field
     *            Prepare the PduInfoType for the tx-pdus' payload */
      FrTp_TxSm_Item(pTxSm, SeqNumber) = FrTp_SNInitial; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      payload.SduDataPtr = (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))FrTp_VCfg_TxBuf(txSmIdx);
      payload.SduLength = (PduLengthType)FrTp_TxSm_Item(pTxSm, CopiedTxDataLen);
      FrTp_Util_WriteML(tpciBuffer, (uint16)(FrTp_TxSm_Item(pTxSm, DataLength))); /* SBSW_FRTP_ASSEMBLE_TPCI_TX */
      FrTp_Util_WriteFPL(tpciBuffer, FrTp_TxSm_Item(pTxSm, CopiedTxDataLen)); /* SBSW_FRTP_ASSEMBLE_TPCI_TX */
      tpciBuffer[FrTp_FmtOffsetFrameType] = FrTp_PCISTF; /* SBSW_FRTP_WRITE_TPCI_ARRAY */
      TPCI.SduLength = FrTp_GetFmtOffsetFromPci(FrTp_PCISTF);
      /* #40 Finally transmit the tx-pdu just assembled.
       *              Based on the current state decide, whether the tx-state-machine shall drop out or stay in the round-robin */
      txResult = FrTp_TxSm_FrIfTransmit(&TPCI, &payload, txSmIdx); /* SBSW_FRTP_TXSM_FRIF_TRANSMIT */
      /* #50 In case the tx-state-machines' state is */
      if(FrTp_TxSm_Item(pTxSm, State) == FrTp_TxSm_WaitForTxnNonBurstSTFseg)
      {
        /* #70 of value FrTp_TxSm_WaitForTxnNonBurstSTFseg:
         *                Set state to FrTp_TxSm_WaitForTxConfNonBurstSTFseg in case the burst shall stop for this call of FrTp_MainFunction()
         *                Set state to FrTp_TxSm_WaitForTxConfNonBurstSTFseg in case the burst can continue for this call of FrTp_MainFunction()
         *                Otherwise terminate transmission with error */
          deltaActiveSms = FrTp_TxSm_EvalFrIfTransmitRetVal(pTxSm, txResult, FrTp_TxSm_WaitForTxConfNonBurstSTFseg, FrTp_TxSm_WaitForTxConfNonBurstSTFseg); /* SBSW_FRTP_EVAL_FRIF_TRANSMIT_RETVAL */
      }
      else
      {
        /* #80 of value FrTp_TxSm_WaitForTxnNonBurstSTFunseg
         *                Set state to FrTp_TxSm_WaitForTxConfNonBurstSTFunseg in case the burst shall stop for this call of FrTp_MainFunction()
         *                Set state to FrTp_TxSm_WaitForTxConfNonBurstSTFunseg in case the burst can continue for this call of FrTp_MainFunction()
         *                Otherwise terminate transmission with error */
          deltaActiveSms = FrTp_TxSm_EvalFrIfTransmitRetVal(pTxSm, txResult, FrTp_TxSm_WaitForTxConfNonBurstSTFunseg, FrTp_TxSm_WaitForTxConfNonBurstSTFunseg); /* SBSW_FRTP_EVAL_FRIF_TRANSMIT_RETVAL */
      }
      break;
    case FrTp_TxSm_WaitForEndOfBurstCF:
    /* #90 of value FrTp_TxSm_WaitForEndOfBurstCF:
     *            Assemble CF1, CFEOB or LF (no CF2 is supported due to missing AckRt support)
     *            Write the FPL- and PCI-field to achive the common pdu-layout for all segmented tx-pdus */
      payload.SduDataPtr = (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))FrTp_VCfg_TxBuf(txSmIdx);
      payload.SduLength = FrTp_TxSm_Item(pTxSm, CopiedTxDataLen);
      FrTp_Util_WriteFPL(tpciBuffer, FrTp_TxSm_Item(pTxSm, CopiedTxDataLen)); /* SBSW_FRTP_ASSEMBLE_TPCI_TX */
      tpciBuffer[FrTp_FmtOffsetFrameType] = FrTp_TxSm_Item(pTxSm, CurrPCI); /* SBSW_FRTP_WRITE_TPCI_ARRAY */
      /* #100 In case the next tx-pdu to be sent is a LF.
       *              Write the ML-field to the LF */
      if(FrTp_TxSm_Item(pTxSm, CurrPCI) == FrTp_PCILF)
      { 
        FrTp_Util_WriteML(tpciBuffer, (uint16)FrTp_TxSm_Item(pTxSm, DataLength)); /* SBSW_FRTP_ASSEMBLE_TPCI_TX */
      }
      else
      /* #110 Otherwise: Do things that are common for all tx-pdus that are not a LF:
       *              Increase the sequence number
       *              Write the sequence number to the PCI-buffer */
      {
        FrTp_TxSm_Item(pTxSm, SeqNumber) = (FrTp_TxSm_Item(pTxSm, SeqNumber) + 1) & FrTp_SNMask; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
        tpciBuffer[FrTp_FmtOffsetFrameType] = (uint8)(tpciBuffer[FrTp_FmtOffsetFrameType] | (FrTp_TxSm_Item(pTxSm, SeqNumber))); /* SBSW_FRTP_WRITE_TPCI_ARRAY */
      }
      /* #120 Do things that are common for all segmented tx-pdus:
       *              Determine the length of the PCI
       *              Actually transmit the current tx-state-machine related tx-pdu */
      TPCI.SduLength = FrTp_GetFmtOffsetFromPci(FrTp_TxSm_Item(pTxSm, CurrPCI));
      txResult = FrTp_TxSm_FrIfTransmit(&TPCI, &payload, txSmIdx); /* SBSW_FRTP_TXSM_FRIF_TRANSMIT */
      deltaActiveSms = FrTp_TxSm_EvalFrIfTransmitRetVal(pTxSm, txResult, FrTp_TxSm_WaitForTxConfBurstCF, FrTp_TxSm_WaitForTxConfBurstCFIntrnl); /* SBSW_FRTP_EVAL_FRIF_TRANSMIT_RETVAL */
      break;
    case FrTp_TxSm_WaitForTxConfBurstCFIntrnl:
    /* #130 of value FrTp_TxSm_WaitForTxConfBurstCFIntrnl:
     *            Give the internal tx-confirmation to the tx-state-machine */
      deltaActiveSms = FrTp_TxSm_CFTxConfirmation(txSmIdx);
      break;
    default:
      break;
  }
  return deltaActiveSms;
} /* FrTp_TxSm_ActionOf */

/**********************************************************************************************************************
  FrTp_TxSm_PrepareNxtCFaccordingBC()
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
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_PrepareNxtCFaccordingBC(
  uint8 txSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl = pConnCfg->ConnCtrlPtr;
  uint8 mnpc = (uint8)FrTp_TxSm_Item(pTxSm, CurrMNPC);
  sint8 deltaActiveSms = FrTp_DropOut;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the state-machines MNPC is 0u or its CounterMNPC does not exceed MNPC:
   *          Burst mode is possible according to BC: Prepare next transmission by asking for tx-data:
   *          Set timer to TimeCs as timeout for that state
   *          Set the tx-state-machine to state FrTp_TxSm_WaitForDataCF */
  if((mnpc == 0u) || (FrTp_TxSm_Item(pTxSm, CounterMNPC) < mnpc))
  {
    FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(pConnCtrl, TimeCs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_WaitForDataCF; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    deltaActiveSms = FrTp_StayIn;
  }
  else
  /* #20 Otherwise burst-mode is not possible at all or is now finished:
   *          Set the tx-state-machine to state FrTp_TxSm_WaitForBCexpiry
   *          Set timer to TimerVal4CurrSC as timeout for that state */
  {
    FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_WaitForBCexpiry; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    FrTp_TxSm_Item(pTxSm, Timer) = (uint8)(FrTp_TxSm_Item(pTxSm, TimerVal4CurrSC)); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
  }
  return deltaActiveSms;
} /* FrTp_TxSm_PrepareNxtCFaccordingBC */

/**********************************************************************************************************************
  FrTp_TxSm_CFTxConfirmation()
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
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_TxSm_CFTxConfirmation(
  uint8 txSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm = FrTp_VCfg_TxState(txSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_TxSm_Item(pTxSm, ConnCfgPtr);
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl = pConnCfg->ConnCtrlPtr;
  sint8 deltaActiveSms = FrTp_DropOut;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case DataIndex < DataLength the transmission is not finished: Transmit next CF */
  if(FrTp_TxSm_Item(pTxSm, DataIndex) < FrTp_TxSm_Item(pTxSm, DataLength))
  {
    /* #20 In case RemainingBytesInBlock is not 0 (i.e. block-mode is active because the receiver has indicated a BfS != 0)
     *            Subtract the FPL of the pdu that is tx-confirmed right now from the RemainingBytesInBlock */
    if(FrTp_TxSm_Item(pTxSm, RemainingBytesInBlock) > 0)
    {
      FrTp_TxSm_Item(pTxSm, RemainingBytesInBlock) = (PduLengthType)(FrTp_TxSm_Item(pTxSm, RemainingBytesInBlock) - FrTp_TxSm_Item(pTxSm, CopiedTxDataLen)); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    }
    FrTp_TxSm_Item(pTxSm, CopiedTxDataLen) = 0u; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */

    /* #30 In case the type of the tx-confirmed pdu is CF_EOB then its, after all, a 'blockwise transmission' where the block is at its end: Expect a FC-pdu:
     *            Set timer to TimeoutBs as timeout for that state
     *            Set the tx-state-machine to state FrTp_TxSm_WaitFC
     *            Otherwise it is a standard CF (or LF) which does not have to be followed by a FC - simply continue sending:
     *            Call the 'central' 'check-and-continue' routine to prepare sending the next CF */
    if(FrTp_TxSm_Item(pTxSm, CurrPCI) == FrTp_PCICFEOB)
    {      
      FrTp_TxSm_Item(pTxSm, Timer) = FrTp_GetConnCtrlItem(pConnCtrl, TimeoutBs); /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
      FrTp_TxSm_Item(pTxSm, State) = FrTp_TxSm_WaitFC; /* SBSW_FRTP_TXSM_PTR_FROM_VALID_IDX */
    }
    else 
    {      
      deltaActiveSms = FrTp_TxSm_PrepareNxtCFaccordingBC(txSmIdx);
    } 
  }
  else
  {
    /* #40 Otherwise there is no more data left to transmit:
     *            In case the CurrPCI of the tx-state-machine is CF transmit a LF with 0 bytes now
     *            Otherwise terminate transmission with success */
    if(FrTp_TxSm_Item(pTxSm, CurrPCI) == FrTp_PCICF1)
    {  
      deltaActiveSms = FrTp_TxSm_PrepareNxtCFaccordingBC(txSmIdx);
    }
    else
    {
      FrTp_Rsrc_ReleaseTxSm(txSmIdx, E_OK);
    }
  }
  return deltaActiveSms;
} /* FrTp_TxSm_CFTxConfirmation */

#define FRTP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_TxSm.c
 *********************************************************************************************************************/

