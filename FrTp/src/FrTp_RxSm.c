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
 *        \file   FrTp_RxSm.c
 *        \brief  Source file of the FrTp sub-module RxSm.
 *
 *      \details  Source file containing the internal service functions of the sub-module RxSm of the FrTp.
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

#define FRTP_RXSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FrTp_Common.h"
#include "PduR_FrTp.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FrTp header file */
#if (  (FRTP_RXSM_SW_MAJOR_VERSION != (2u)) \
    || (FRTP_RXSM_SW_MINOR_VERSION != (4u)) \
    || (FRTP_RXSM_SW_PATCH_VERSION != (4u)) )
# error "Vendor specific version numbers of FrTp_RxSm.c and FrTp.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (FRTP_CFG_MAJOR_VERSION != (2u)) \
    || (FRTP_CFG_MINOR_VERSION != (4u)) )
# error "Version numbers of FrTp_RxSm.c and FrTp_Cfg.h are inconsistent!"
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
  FrTp_RxSm_TolerateRxIndEarlierThanTxConf()
**********************************************************************************************************************/
/*!
 * \brief       Conducts all actions required to tolerate the inversion of rx-indication & tx-confirmation from FrIf.
 * \details     Call the internal tx-confirmation function to trigger the expected WaitForFCConfIsr event in case the 
 *              rx-state-machine is currently waiting for the tx-confirmation of a FC.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm: Ptr. to the rx-state-machine
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_RX_IND_EARLIER_THAN_TX_CONF == STD_ON
 * \trace       DSGN-FrTpVariousJLE, DSGN-FrTpGenericFrIfInterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_RxSm_TolerateRxIndEarlierThanTxConf(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
);
#endif

/**********************************************************************************************************************
  FrTp_RxSm_ReceivedSTF()
**********************************************************************************************************************/
/*!
 * \brief       Processes the reception of STFU-pdus internally.
 * \details     The function is called by FrTp (FrTp_FrIf_RxIndication) itself on interrupt and task level.
 * \param[in]   P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg: Pointer to the connection the FrTp-pdu received belongs to.
 * \param[in]   P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr:
 *              Pointer to payload of pdu _past_ the address-bytes
 * \param[in]   uint16 ML: ML field from the STF-pdu received
 * \param[in]   uint8 FPL: FPL field from the STF-pdu received
 * \param[in]   uint8 rxSmIdx: index of the rx-state-machined the reception is currently running on.
 *              PRE_FRTP_VALID_RX_SM_IDX rxSmIdx
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpImplicitRxCancellation, DSGN-FrTpBroadcastConnections
 * \trace       CREQ-109463
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_ReceivedSTF(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint16 ML,
  uint8 FPL,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_ReceivedLF()
**********************************************************************************************************************/
/*!
 * \brief       Checks if the reception is to be terminated success or error
 * \details     Terminate the transmission with success or with error depending on whether the FPL is as expected according 
 *              to the txn-status and the ML in the LF is correct or not.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   uint16 ML: ML field from the LF-pdu received
 * \param[in]   uint8 FPL: FPL field from the LF-pdu received
 * \param[in]   uint8 desiredFPL: FPL as calculated based on the current rx-state-machines' status
 * \param[in]   uint8 rxSmIdx: index of the rx-state-machined the reception is currently running on.
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_RxSm_ReceivedLF(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint16 ML,
  uint8 FPL,
  uint8 desiredFPL,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_RequestAvailRxBufAndTryToCopy()
**********************************************************************************************************************/
/*!
 * \brief       Retrieves the size of available rx-data-buffer from PduR and copies current pdu if buffer is available.
 * \details     Try to copy the last pdu received to the PduR in case PduR has provided the current size and the size is 
 *              larger zero.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm: Pointer to the affected rx-state-machine
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that currently operates a segm. reception
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \return      uint8
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   TRUE with different pRxSm and rxSmIdx
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL FUNC(uint8, FRTP_CODE) FrTp_RxSm_RequestAvailRxBufAndTryToCopy(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_WaitForBufferUnsegmRxn()
**********************************************************************************************************************/
/*!
 * \brief       Asks the PduR for rx-data-buffer in case an unsegmented reception is active.
 * \details     Try to retrieve the available rx-buffer from the PduR and evaluate the latest bReq-status from the PduR 
 *              in a STF-segmented-specific way.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm: Pointer to the affected rx-state-machine
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   boolean isTimeout: If true then this is the last try to retrieve rx-data-buffer from the PduR
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that currently operates an unsegm. reception
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \return      sint8: Return value of PduR_FrTp[StartOfReception|CopyRxData]
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   TRUE with different pRxSm and rxSmIdx
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_WaitForBufferUnsegmRxn(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  boolean isTimeout,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_WaitForBufferSegmRxn()
**********************************************************************************************************************/
/*!
 * \brief       Asks the PduR for rx-data-buffer in case a segmented reception is active.
 * \details     Try to retrieve the available rx-buffer from the PduR and evaluate the latest bReq-status from the PduR 
 *              in a STF-segmented-specific way.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm: Pointer to the affected rx-state-machine
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   boolean isTimeout: If true then this is the last try to retrieve rx-data-buffer from the PduR
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that currently operates an segm. reception
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \return      sint8: Return value of PduR_FrTp[StartOfReception|CopyRxData]
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   TRUE with different pRxSm and rxSmIdx
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
 FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_WaitForBufferSegmRxn(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  boolean isTimeout,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_PrepareAllSms()
**********************************************************************************************************************/
/*!
 * \brief       Finds and counts the active rx-state-machines and decrements their member 'Timer'.
 * \details     For each rx-state-machine that is active check whether the (countdown-)timer is not 0, and if so decrease 
 *              the timer of the current rx-state-machine. Increase the active state-machines counter in order to prepare 
 *              the round-robin.
 * \return      sint16_least: Number of active rx-state-machines.
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpMainFunction
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint16_least, FRTP_CODE) FrTp_RxSm_PrepareAllSms(
  void
);

/**********************************************************************************************************************
  FrTp_RxSm_ReceivedSegmPdu()
**********************************************************************************************************************/
/*!
 * \brief       Do the reception of a CF1, CF_EOB or LF
 * \details     The available rx-buffer-space has been communicated to the sending peer using a FC-pdu.
 *              That value has to be obeyed by the sending peer in any case.
 *              It is not allowed (and unlikely) that the PduR will reduce the value of that buffer, afterwards.
 *              Nevertheless it is checked that whether the PduR has reduced the size of that buffer.
 *              The function is called by FrTp (FrTp_FrIf_RxIndication) itself on interrupt and task level.
 * \param[in]   P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
 *              Pointer to payload of pdu _past_ the address-bytes
 * \param[in]   uint16 ML: ML value retrieved when the caller parsed the frame
 * \param[in]   uint8 FPL: FPL value retrieved when the caller parsed the frame
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that currently operates a segm. reception
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \param[in]   uint8 currPCI: Protocol control information retrieved when the caller parsed the frame
 * \param[in]   uint8 lengthOk: Result of the generic length checks done by the caller
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception, DSGN-FrTpVariousJLE
 * \trace       CREQ-109463
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_ReceivedSegmPdu(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint16 ML,
  uint8 FPL,
  uint8 rxSmIdx,
  uint8 currPCI,
  uint8 lengthOk
);

/**********************************************************************************************************************
  FrTp_RxSm_EvalBufReqRetVal()
**********************************************************************************************************************/
/*!
 * \brief       Evaluates the given return code of the PduR_FrTpCopyRxData
 * \details     static (Called from 6 different locations)
 *              The return value of PduR_FrTpCopyRxData is referenced to as 'bReq' in the following lines:
 * \param[in]   P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr: Pointer to TP-payload in pdu just received
 * \param[in]   uint16 newTimer: Timer-value to load in rx-state-machine in case the reception is not finished
 *              PRE_FRTP_VALID_RX_STATE_TIMER newTimer
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that has just called PduR_FrTpCopyRxData()
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \param[in]   uint8 bReq: Return value of the call to PduR_FrTpCopyRxData()
 * \param[in]   uint8 newStateOk: New state of the rx-state machines in case bReq is BUFREQ_OK
 *              PRE_FRTP_VALID_RX_STATE_PARAM newStateOk
 * \param[in]   uint8 newStateWt: New state of the rx-state machines in case bReq is FrTp_OkButNotEnoughBuffer
 *              PRE_FRTP_VALID_RX_STATE_PARAM newStateWt
 * \param[in]   uint8 newStateAbt: New state of the rx-state machines in case bReq is BUFREQ_E_NOT_OK
 *              PRE_FRTP_VALID_RX_STATE_PARAM newStateAbt
 * \param[in]   uint8 newStateOver: New state of the rx-state machines in case bReq is BUFREQ_E_OVFL
 *              PRE_FRTP_VALID_RX_STATE_PARAM newStateOver
 * \param[in]   uint8 newCurrPCI: Value of CurrPCI to load in rx-state-machine in case the reception is not finished
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0)
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_EvalBufReqRetVal(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint16 newTimer,
  uint8 rxSmIdx,
  uint8 bReq,
  uint8 newStateOk,
  uint8 newStateWt,
  uint8 newStateAbt,
  uint8 newStateOver,
  uint8 newCurrPCI
);

/**********************************************************************************************************************
  FrTp_RxSm_CalcBfsValue()
**********************************************************************************************************************/
/*!
 * \brief       Calculates the BfsValue to be sent in a FC.CTS-pdu.
 * \details     The size of the rx-buffer available at the 
 *              The function is called by FrTp itself on interrupt and task level.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm: current rx-state-machine pointer
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl: of the rx-state-machines connection
 * \return      uint16 BfsValue according to the current status of the reception and the rx-state-machine.
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception, DSGN-FrTpGenericPduRTPinterface, DSGN-FrTpPduPools
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint16, FRTP_CODE) FrTp_RxSm_CalcBfsValue(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl
);

/**********************************************************************************************************************
  FrTp_RxSm_ActionOf()
**********************************************************************************************************************/
/*!
 * \brief       Conducts the action that is related to a particular state of the rx-state-machine.
 * \details     Prepare a FC-pdu or wait for a free rx-pdu to prepare a FC-pdu
 *              Transmits a single FrTp-pdu according to the current Rx-status of the given rx-state-machine.
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm: current rx-state-machine pointer
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that currently operates a [segm.|unsegm.] reception
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \return      sint8 deltaActiveSms: Delta to be applied to activeSms counter. May only be:
 *                                    FrTp_DropOut (-1), FrTp_StayIn (0).
 * \context     TASK|ISR
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         According to the impl. of FrTp_RxIndication() the pPoolCfg and pPoolDataUsed is checked THERE, 
                and thus the macros to get pduPool-Config and Data WITHOUT the checks may be used, here.
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpActionAndTimeoutHandling, DSGN-FrTpMainFunction, DSGN-FrTpWaitFrameHandling
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_ActionOf(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_TimeoutOf()
**********************************************************************************************************************/
/*!
 * \brief       Takes state-specific actions in case the Timer of the rx-state-machine has dropped to 0
 * \details     inline (Called from 1 location)
 * \param[in]   volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm: current rx-state-machine pointer
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_PTR pRxSm
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that currently operates a [segm.|unsegm.] reception
 *              PRE_FRTP_VALID_ACTIVE_RX_SM_IDX rxSmIdx
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpActionAndTimeoutHandling, DSGN-FrTpMainFunction
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_TimeoutOf(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_CopyRxData()
**********************************************************************************************************************/
/*!
 * \brief       Requests copying of data received from the upper layer and handles CounterWft centrally.
 * \details     Call PduR_FrTpStartOfReception() to inform application about the start of reception. Prepare an PduInfoType 
 *              and copy ReceivedPduLen to the PduR and update the DataIndex and ReceivedPduLen of the rx-state-machine.
 * \param[in]   P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr: Pointer TO THE PAYLOAD
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that PduR_FrTpCopyRxData shall be called for.
 *                             PRE_FRTP_VALID_ACTIVE_RX_SM_IDX
 * \return      uint8 bReq: Return value of the call to PduR_FrTpCopyRxData
 * \pre         PRE_FRTP_INIT
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_RxSm_CopyRxData(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint8 rxSmIdx
);

/**********************************************************************************************************************
  FrTp_RxSm_FrIfTransmit()
**********************************************************************************************************************/
/*!
 * \brief       Passes the FrTps request to transmit a data pdu on the underlying bus system to the FrIf.
 * \details     The function is called by FrTp (FrTp_FrIf_RxIndication) itself on interrupt and task level.
 * \param[in]   P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) TPCI: 
 *              Pointer and length of the FrTp-generated TPCI
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine that FrIf_Transmit shall be called for.
 *                             PRE_FRTP_VALID_ACTIVE_RX_SM_IDX
 * \return      Return code: FrTp_TxReturnType: Preprocessed return code of the FrIf_Transmit()-call.
 *              FrTp_TxOkContinue: Continue consuming bandwidth
 *              FrTp_TxOkStop: Stop consuming bandwidth
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \pre         Pointer parameter pTPCI has to point to a valid variable of type PduInfoType.
 *              The members of that PduInfoType have to be initialized like this:
 *              SduLength: Has to contain the length of the PCI (of the FrTp-pdu to be sent) which has to be in the range of [1..(FrTp_TPCIMaxLength - 1)]
 *              SduDataPtr: Has to point to an array of uint8 containing the PCI of the FrTp-pdu to be sent.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface
 ********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(FrTp_TxReturnType, FRTP_CODE) FrTp_RxSm_FrIfTransmit(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI, 
  uint8 rxSmIdx
);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FrTp_RxSm_FrIfTransmit()
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
FRTP_LOCAL_INLINE FUNC(FrTp_TxReturnType, FRTP_CODE) FrTp_RxSm_FrIfTransmit(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI,
  uint8 rxSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Retrieve pointer to the configuration of the connection operated in that state-machine
   *          Retrieve index of the next free tx-pdu planned by that state-machine
   *          Retrieve pointer to the admin data of the pool that is used by the connection
   *          Retrieve pointer to the configuration of the tx-pdu used by the rx-state-machine */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);
  uint8 intTxPduIdx = FrTp_RxSm_Item(pRxSm, NxtFreePduIdx);
  P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu = FrTp_CCfg_FrIfTxPdus(intTxPduIdx);
  PduInfoType payload;
  FrTp_TxReturnType retVal = FrTp_TxOkStop;

  /* ----- Implementation ----------------------------------------------- */
  payload.SduDataPtr = NULL_PTR;
  payload.SduLength = 0u;
  /* #20 In case the FrIf accepts the transmit-request
         Update the admin data of state-machine and pdu after successful transmit-request
         Set the rx-part of the pending-flag-arrays
         Indicate that there is no next free pdu */
  if(FrTp_FrIf_TransmitPduForConn(FrTp_RxSm_Item(pRxSm, ConnCfgPtr), pFrIfTxPdu, pTPCI, &payload) == E_OK) /* SBSW_FRTP_FRIF_TRANSMIT_PDU_FOR_RX_CONN */
  {
    FrTp_FrIf_ExpectTxConfForTxPduOfRxSm(intTxPduIdx, rxSmIdx); /* SBSW_FRTP_STORE_VALID_RXSM_IDX_FROM_CALLER */
    FrTp_FrIf_DecreaseNumFreePdusOverlapped(pFrIfTxPdu); /* SBSW_FRTP_VALID_FRIF_TXPDU_IN_RXSM */
    FrTp_RxSm_Item(pRxSm, NxtFreePduIdx) = FrTp_NoPdu; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
  }
  else
  /* #40 Otherwise:
         Indicate the rejection of the transmit-request to the caller.
         Set the retVal apropriately to indicate 'not ok' */
  {
    retVal = FrTp_TxNotOk;
  }
  return retVal;
} /* FrTp_RxSm_FrIfTransmit */

/**********************************************************************************************************************
  FrTp_RxSm_ReceivedSTF()
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
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_ReceivedSTF(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint16 ML,
  uint8 FPL,
  uint8 rxSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);
  sint8 deltaActiveSms = FrTp_DropOut;
  uint8 bReq;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the rx-state-machine is busy and the incoming pdu is of the same connection then restart that connection */
  if(    (FrTp_RxSm_Idle != FrTp_RxSm_Item(pRxSm, State))
      && (FrTp_RxSm_Item(pRxSm, ConnCfgPtr) == pConnCfg)
    )
  {
    FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
  }
  /* #20 Calculate the start of the payload of the pdu which is common for both STF-types
   *          Do the decision whether the reception is segmented or not */
  dataPtr = &dataPtr[FrTp_GetFmtOffsetFromPci(FrTp_PCISTF)];
  /* #30 In case FPL == ML:
   *          Start the unsegmented reception by allocating an rx-state-machine
   *          Copy the data received to PduR */
  if(FPL == ML)
  {
    FrTp_Rsrc_AllocateRxSm(pConnCfg, ML, FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeBr), rxSmIdx, FPL, /* SBSW_FRTP_ALLOCATE_RXTX_SM */
                           FrTp_PCISTFunseg, FrTp_RxSm_WaitForSTFunsegmBuffer);
    bReq = FrTp_RxSm_CopyRxData(dataPtr, rxSmIdx); /* SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF */
    /* In the SWS FrTp of AR-release 4.2.1 there is no clear statement how often the copying of received data shall be retried for unsegmented reception */
    /* #40 For unsegmented reception ask the PduR to copy the received data as often as for segmented reception */
    deltaActiveSms = FrTp_RxSm_EvalBufReqRetVal( /* SBSW_FRTP_EVAL_COPYRXDATA */
      dataPtr,
      FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeBr),
      rxSmIdx,
      bReq,
      /* newStateOk= */FrTp_RxSm_Idle,
      /* newStateWt= */FrTp_RxSm_WaitForSTFunsegmBuffer,
      /* newStateAbt= */FrTp_RxSm_Idle,
      /* newStateOver= */FrTp_RxSm_Idle,
      FrTp_PCISTFunseg
    );
  }
  else
  {
    /* #50 Otherwise the STF might start a segmented reception:
     *            In case ML is larger than FPL and segmentation is allowed according to the configuration of the given connection */
    if(    (ML > FPL) 
        && (pConnCfg->MultRec == FALSE)
      )
    {
      /* #60 It could be a segmented reception: By retrieving the poolOffset
       *              check whether the tx-pdu-pool configuration allows the sending of a FC-pdu.
       *              Retrieve pointers pPoolDataUsed and pPoolCfg */
      uint8 poolOffset = FrTp_ConnGetTxPoolOffset(pConnCfg);
      P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA) pPoolDataUsed = FrTp_FrIf_GetTxPduPoolDataPtrByCheckedOffset(poolOffset);
      P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg = FrTp_FrIf_GetTxPduPoolPtrByCheckedOffset(poolOffset);

      /* #70 In case pPoolCfg and pPoolDataUsed are not NULL:
       *              Start the segmented reception by allocating an rx-state-machine
       *              Do items that are specific for segmented reception
       *              Copy the data received to PduR */
      if((pPoolCfg != NULL_PTR) && (pPoolDataUsed != NULL_PTR))
      {
        FrTp_Rsrc_AllocateRxSm(pConnCfg, ML, FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeBr), rxSmIdx, FPL,
                               FrTp_PCISTFseg, FrTp_RxSm_WaitForSTFsegmBuffer); /* SBSW_FRTP_ALLOCATE_RXTX_SM */
        FrTp_RxSm_Item(pRxSm, ExpectedSN) = FrTp_SNVeryFirstCF; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
        FrTp_RxSm_Item(pRxSm, ReceivedPduLen) = FPL; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
        bReq = FrTp_RxSm_CopyRxData(dataPtr, rxSmIdx); /* SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF */
        deltaActiveSms = FrTp_RxSm_EvalBufReqRetVal( /* SBSW_FRTP_EVAL_COPYRXDATA */
          dataPtr,
          FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeBr), 
          rxSmIdx,
          bReq,
          /* newStateOk= */FrTp_RxSm_WaitForTxnNonBurstFC_CTS,
          /* newStateWt= */FrTp_RxSm_WaitForTxnNonBurstFC_WT,
          /* newStateAbt= */FrTp_RxSm_WaitForTxnNonBurstFC_ABT,
          /* newStateOver= */FrTp_RxSm_WaitForTxnNonBurstFC_OVER,
          FrTp_PCISTFseg
        );
      }
    }
  }

  return deltaActiveSms;
} /* FrTp_RxSm_ReceivedSTF */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
  FrTp_RxSm_ReceivedLF()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 3673 7 */ /* MD_FrTp_3673 */
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_RxSm_ReceivedLF(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint16 ML,
  uint8 FPL,
  uint8 desiredFPL,
  uint8 rxSmIdx
)
{
  /* #10 In case the FPL is as expected according to the txn-status and the ML in the LF is correct:
   *          Terminate the transmission with success
   *          Otherwise terminate the transmission with error */
  if((FPL == desiredFPL) && (ML == FrTp_RxSm_Item(pRxSm, DataLength)))
  {
    FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_OK);
  }
  else
  {
    FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
  }
} /* FrTp_RxSm_ReceivedLF */

/**********************************************************************************************************************
  FrTp_RxSm_ReceivedSegmPdu()
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
 *
 *
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_ReceivedSegmPdu(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint16 ML,
  uint8 FPL,
  uint8 rxSmIdx,
  uint8 currPCI,
  uint8 lengthOk
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Retrieve pointer to rx-state-machine
   *          Retrieve pointer to the connection-control structure of the curren connection
   *          Extract the sequence number from the payload received from FrIf */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);
  sint8 deltaActiveSms = FrTp_DropOut;

  /* ----- Implementation ----------------------------------------------- */
#if( FRTP_RX_IND_EARLIER_THAN_TX_CONF == STD_ON )
  FrTp_RxSm_TolerateRxIndEarlierThanTxConf(pRxSm, rxSmIdx); /* SBSW_FRTP_RX_IND_EARLIER_THAN_TX_CONF */
#endif
  /* #20 In case
   *          FPL + DataIndex < DataLength but the pdu is a LF (the contrary condition is ok, as a LF with FPL=0 is valid)
   *          then:
   *          Ignore the pdu received
   *          Note: The implementation below uses inverted logic */
  if(    ((FrTp_RxSm_Item(pRxSm, DataIndex) + FPL) >= FrTp_RxSm_Item(pRxSm, DataLength))
      || (currPCI != FrTp_PCILF)
    )
  {
    /* #30 In case a segmented pdu is NOT expected
     *            or the contents of the pdu fit into the current reception context, i.e.:
     *            FPL is larger than RemainingBytesInBlock and block-mode is active or
     *            FPL is larger that the remaining bytes of the overall transmission or
     *            FPL is larger than there is rx-buffer-space
     *            FPL is equal to RemainingBytesInBlock but CurrPCI is not CF_EOB
     *            FPL is zero, transmission is at its end but CurrPCI is not LF
     *            then:
     *            Terminate the reception with error */
    if(    (FrTp_RxSm_Item(pRxSm, State) != FrTp_RxSm_WaitForSegmPdu)
        || (    ((FrTp_RxSm_Item(pRxSm, RemainingBytesInBlock)) > 0)
             && (FPL > FrTp_RxSm_Item(pRxSm, RemainingBytesInBlock))
           )
        || (    (FPL == FrTp_RxSm_Item(pRxSm, RemainingBytesInBlock))
             && (currPCI != FrTp_PCICFEOB)
             && (FPL != 0u)
           )
        || (FPL > FrTp_RxSm_CalcRemainingBytes(pRxSm))
        || (    (FrTp_RxSm_Item(pRxSm, AvailableRxBuffer) > 0u)
             && (FPL > FrTp_RxSm_Item(pRxSm, AvailableRxBuffer))
           )
        || (lengthOk != 1u)
      )
    {
      FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
    }
    else
    /* #40 Otherwise context and contents of the pdu received are ok */
    {
      uint8 SNinFrame = (uint8)((*dataPtr) & FrTp_SNMask);
      uint8 lExpectedSN = (currPCI == FrTp_PCILF)? 0 : FrTp_RxSm_Item(pRxSm, ExpectedSN);
      /* #50 In case the 'SNinFrame' is not equal to the expected SN:
       *              Terminate the reception with error */
      if(SNinFrame != (uint8)(lExpectedSN))
      {
        FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
      }
      else
      {
        P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_RxSm_Item(pRxSm, ConnCfgPtr);
        uint8 lState;
        uint8 bReq;
        /* #60 Otherwise in case there is payload in the segm. pdu then the frame is finally valid, i.e.:
         *                Take over the currPCI into the rx-state-machines status data
         *                Determine the next state-machine state for copying data to the PduR */
        if(FPL != 0u)
        {
          FrTp_RxSm_Item(pRxSm, CurrPCI) = currPCI; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
          switch(currPCI)
          {
            case FrTp_PCILF:
              FrTp_RxSm_Item(pRxSm, State) = FrTp_RxSm_WaitForLFbuffer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
              break;
            case FrTp_PCICF1:
              FrTp_RxSm_Item(pRxSm, State) = FrTp_RxSm_WaitForCFbuffer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
              break;
            case FrTp_PCICFEOB:
              FrTp_RxSm_Item(pRxSm, State) = FrTp_RxSm_WaitForCF_EOBbuffer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
              break;
            default:
              break;
          }
          /* #70 Prepare copying and actually copy the received data:
           *                  Store the FPL in the state-machine-variable ReceivedDataLen
           *                  Store the pointer to the payload in the state-machine variable DataPtr */
          FrTp_RxSm_Item(pRxSm, ReceivedPduLen) = FPL; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
          dataPtr = &dataPtr[FrTp_GetFmtOffsetFromPci(FrTp_RxSm_Item(pRxSm, CurrPCI))];
          if(FrTp_RxSm_Item(pRxSm, AvailableRxBuffer) > 0u)
          {
            bReq = FrTp_RxSm_CopyRxData(dataPtr, rxSmIdx); /* SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF */
          }
          else
          {
            bReq = FrTp_RxSm_RequestAvailRxBufAndTryToCopy(pRxSm, rxSmIdx); /* SBSW_FRTP_RETRIEVE_AVAIL_RX_BUFFER */
          }
          lState = FrTp_RxSm_Item(pRxSm, State);

          /* #75 In case of block-mode decrease the RemainingBytesInBlock */
          if((bReq == BUFREQ_OK) && (FrTp_RxSm_Item(pRxSm, RemainingBytesInBlock) > 0))
          {
            FrTp_RxSm_Item(pRxSm, RemainingBytesInBlock) = (PduLengthType)(FrTp_RxSm_Item(pRxSm, RemainingBytesInBlock) - FPL); /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
          }
          /* #80 In case the DataIndex has reached the expected DataLength
           *                  the transmission is close to finalization, i.e. at least enough data was transferred
           *                  However a LF or CF_EOB with 0 bytes FPL is still allowed to come in */
          FrTp_RxSm_Item(pRxSm, ExpectedSN) = (   (FrTp_RxSm_Item(pRxSm, ExpectedSN) + 1) /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
                                                & FrTp_SNMask);
          /* #90 In case the CurrPCI is */
          switch(FrTp_RxSm_Item(pRxSm, CurrPCI))
          {
            case FrTp_PCICF1:
              /* #100 of value FrTp_PCICF1 then it is a CF (it is now mandatory that a LF with FPL=0 follows this CF) */
              /* no break; */
            case FrTp_PCICFEOB:
            /* #120 of value FrTp_PCICFEOB */
            /* #130 It is a CF_EOB: Even that pdu-type shall be tolerated at the end of the reception, for reasons of robustness */
              /* #150 Set timer to TimeoutAr as timeout for that state
                *                        Set the rx-state-machine to state FrTp_RxSm_WaitForTxnNonBurstFC_CTS */
              deltaActiveSms = FrTp_RxSm_EvalBufReqRetVal( /* SBSW_FRTP_EVAL_COPYRXDATA */
                dataPtr,
                ((lState == FrTp_RxSm_WaitForCFbuffer) ? FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeoutCr) : FrTp_GetConnCtrlItem(pConnCfg->ConnCtrlPtr, TimeoutAr)),
                rxSmIdx,
                bReq,
                ((lState == FrTp_RxSm_WaitForCFbuffer) ? FrTp_RxSm_WaitForSegmPdu : FrTp_RxSm_WaitForTxnNonBurstFC_CTS),
                FrTp_RxSm_WaitForTxnNonBurstFC_WT,
                FrTp_RxSm_WaitForTxnNonBurstFC_ABT,
                FrTp_RxSm_WaitForTxnNonBurstFC_OVER,
                FrTp_RxSm_Item(pRxSm, CurrPCI)
              );
              break;
            case FrTp_PCILF:
            /* #160 of value FrTp_PCILF then check if the reception is to be terminated success or error */
              if(FrTp_RxSm_Item(pRxSm, DataIndex) == FrTp_RxSm_Item(pRxSm, DataLength))
              {
                FrTp_RxSm_ReceivedLF(pRxSm, ML, FPL, FPL, rxSmIdx); /* SBSW_FRTP_RECEIVED_LF */
              }
              /* #170 Otherwise there are still data bytes to come in this transmission */
              break;
            default:
              /* #180 Pdus containing all other PCI bytes (e.g. CF2) are not processed */
              break;
          }
        }
        else
        /* #230 Otherwise it has to be a LF with FPL 0 because ISO10681-2 forbids FPL == 0 for CF1, CF2 and CF_EOB (This condition was checked, above, already) */
        {
          FrTp_RxSm_ReceivedLF(pRxSm, ML, 0u, FPL, rxSmIdx); /* SBSW_FRTP_RECEIVED_LF */
        }
      }
    }
  }
  return deltaActiveSms;
} /* FrTp_RxSm_ReceivedSegmPdu */ /* PRQA S 6030, 6060, 6080 */ /* MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

#if( FRTP_RX_IND_EARLIER_THAN_TX_CONF == STD_ON )
/**********************************************************************************************************************
  FrTp_RxSm_TolerateRxIndEarlierThanTxConf()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673 4 */ /* MD_FrTp_3673 */
FRTP_LOCAL_INLINE FUNC(void, FRTP_CODE) FrTp_RxSm_TolerateRxIndEarlierThanTxConf(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
)
{
  /* #10 In case the rx-state-machine is currently waiting for the tx-confirmation of a FC:
   *     Call the internal tx-confirmation function to trigger the expected WaitForFCConfIsr event */
  if(FrTp_RxSm_Item(pRxSm, State) == FrTp_RxSm_WaitForTxConfFC_CTS)
  {
    FrTp_RxSm_FrIfTxConfirmation(rxSmIdx);
  }
}
#endif

/**********************************************************************************************************************
  FrTp_RxSm_RequestAvailRxBufAndTryToCopy()
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
FRTP_LOCAL FUNC(uint8, FRTP_CODE) FrTp_RxSm_RequestAvailRxBufAndTryToCopy(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
)
{
  PduInfoType applPduInfo;
  PduLengthType availableRxBuffer = 0u;
  uint8 bReq;

  /* #10 Retrieve the current size of the rx-data-buffer from the PduR.
   *     In case the PduR has provided the current size:
   *       In case the size is larger zero:
   *         Recognize the available rx buffer in the rx-state-machines' data
   *         Try to copy the last pdu received to the PduR.
   *       Otherwise:
   *         In case the reception is not at its end and current provided size is zero do not try to copy the received pdu. */
  applPduInfo.SduLength = 0u;
  bReq = PduR_FrTpCopyRxData( /* SBSW_FRTP_RETRIEVE_AVAIL_RX_BUFFER_FROM_PDUR */
    /*PduIdType id=*/FrTp_RxSm_Item(pRxSm, ConnCfgPtr)->FrTpSduRxId,
    /*PduInfoType* info=*/&applPduInfo,
    /*PduLengthType* availableDataPtr=*/&availableRxBuffer
  );
  if(bReq == BUFREQ_OK)
  {
    if((availableRxBuffer < FrTp_RxSm_Item(pRxSm, ReceivedPduLen)) && (FrTp_RxSm_CalcRemainingBytes(pRxSm) > 0u)) 
    {
      bReq = FrTp_OkButNotEnoughBuffer;
    }
    else
    {
      FrTp_RxSm_Item(pRxSm, AvailableRxBuffer) = availableRxBuffer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      bReq = FrTp_RxSm_CopyRxData(FrTp_VCfg_RxBuf(rxSmIdx), rxSmIdx); /* SBSW_FRTP_PDUR_COPYRXDATA_AVAIL_BUF */
    }
  }
  return bReq;
} /* FrTp_RxSm_RequestAvailRxBufAndTryToCopy */

/**********************************************************************************************************************
  FrTp_RxSm_WaitForBufferUnsegmRxn()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_WaitForBufferUnsegmRxn(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  boolean isTimeout,
  uint8 rxSmIdx
)
{
  /* #10 Try to retrieve the available rx-buffer from the PduR.
   *          Evaluate the latest bReq-status from the PduR in a STF-segmented-specific way. */
  uint8 bReq = FrTp_RxSm_RequestAvailRxBufAndTryToCopy(pRxSm, rxSmIdx); /* SBSW_FRTP_RETRIEVE_AVAIL_RX_BUFFER */
  sint8 deltaActiveSms = FrTp_RxSm_EvalBufReqRetVal( /* SBSW_FRTP_EVAL_COPYRXDATA */
    NULL_PTR,
    ((isTimeout == TRUE) ? FrTp_TimerInIdle : FrTp_RxSm_Item(pRxSm, Timer)),
    rxSmIdx,
    bReq,
    /* newStateOk= */FrTp_RxSm_Idle,
    /* newStateWt= */((isTimeout == TRUE) ? FrTp_RxSm_Idle : FrTp_RxSm_Item(pRxSm, State)),
    /* newStateAbt= */FrTp_RxSm_Idle,
    /* newStateOver= */FrTp_RxSm_Idle,
    FrTp_PCISTFunseg
  );
  return deltaActiveSms;
} /* FrTp_RxSm_WaitForBufferUnsegmRxn */

/**********************************************************************************************************************
  FrTp_RxSm_WaitForBufferSegmRxn()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_WaitForBufferSegmRxn(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  boolean isTimeout,
  uint8 rxSmIdx
)
{
  /* #10 Try to retrieve the available rx-buffer from the PduR.
   *          Evaluate the latest bReq-status from the PduR in a STF-segmented-specific way. */
  uint8 bReq = FrTp_RxSm_RequestAvailRxBufAndTryToCopy(pRxSm, rxSmIdx); /* SBSW_FRTP_RETRIEVE_AVAIL_RX_BUFFER */
  sint8 deltaActiveSms = FrTp_RxSm_EvalBufReqRetVal( /* SBSW_FRTP_EVAL_COPYRXDATA */
    NULL_PTR,
    ((isTimeout == TRUE) ? FrTp_GetConnCtrlItem(FrTp_RxSm_Item(pRxSm, ConnCfgPtr)->ConnCtrlPtr, TimeoutAr) : FrTp_RxSm_Item(pRxSm, Timer)),
    rxSmIdx,
    bReq,
    FrTp_RxSm_WaitForTxnNonBurstFC_CTS,
    ((isTimeout == TRUE) ? FrTp_RxSm_WaitForTxnNonBurstFC_WT : FrTp_RxSm_WaitForNxtFC_WT),
    FrTp_RxSm_WaitForTxnNonBurstFC_ABT,
    FrTp_RxSm_WaitForTxnNonBurstFC_OVER,
    FrTp_RxSm_Item(pRxSm, CurrPCI)
  );
  return deltaActiveSms;
} /* FrTp_RxSm_WaitForBufferSegmRxn */

/**********************************************************************************************************************
  FrTp_RxSm_PrepareAllSms()
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
FRTP_LOCAL_INLINE FUNC(sint16_least, FRTP_CODE) FrTp_RxSm_PrepareAllSms(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  sint16_least activeSms = 0;
  uint8_least rxSmIdx;
  
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Loop all rx-state-machines
           For each rx-state-machine that is active check whether the (countdown-)timer is not 0, and if so:
             Decrease the timer of the current rx-state-machine
             In order to prepare round-robin conducted of the succeeding parts of the rx-part of the FrTp_MainFunction()
             Increase the active state-machines counter in order to prepare the round-robin */
  for(rxSmIdx = (uint8)0u; rxSmIdx < FrTp_CCfg_NumRxChan(); rxSmIdx++)
  {
    volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState((uint8)rxSmIdx);

    if(FrTp_RxSm_Item(pRxSm, Timer) != 0u)
    {
      FrTp_RxSm_Item(pRxSm, Timer)--; /* SBSW_FRTP_RXSM_PTR_FROM_VALIDLIY_INDEXED_LOOP */
      activeSms++;
    }
  }
  return activeSms;
} /* FrTp_RxSm_PrepareAllSms */

/**********************************************************************************************************************
  FrTp_RxSm_TimeoutOf()
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
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_TimeoutOf(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  sint8 deltaActiveSms = FrTp_DropOut;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the state-machine-state is */
  switch(FrTp_RxSm_Item(pRxSm, State))
  {
  case FrTp_RxSm_WaitForTxnNonBurstFC_ABT:
    /* no break; */
  case FrTp_RxSm_WaitForTxnNonBurstFC_OVER:
    /* no break; */
  case FrTp_RxSm_WaitForTxnNonBurstFC_CTS:
    /* no break; */
  case FrTp_RxSm_WaitForTxnNonBurstFC_WT:
    /* #11 of value FrTp_RxSm_WaitForTxnNonBurstFC_ABT,
              or of value FrTp_RxSm_WaitForTxnNonBurstFC_OVER
              or of value FrTp_RxSm_WaitForTxnNonBurstFC_CTS
              or of value FrTp_RxSm_WaitForTxnNonBurstFC_WT
              Try to send the desired FC-pdu for the last time */
    deltaActiveSms = FrTp_RxSm_ActionOf(pRxSm, rxSmIdx); /* SBSW_FRTP_VALID_WRAPPED_RXSM_IDX */
    break;
  case FrTp_RxSm_WaitForSegmPdu:
    /* no break; */
  case FrTp_RxSm_WaitForTxConfFC_CTS:
    /* no break; */
  case FrTp_RxSm_WaitForTxConfFC_WT:
    /* no break; */
  case FrTp_RxSm_WaitForTxConfFC_OVER:
    /* no break; */
  case FrTp_RxSm_WaitForSTFsegmBuffer:
    /* no break; */
  case FrTp_RxSm_WaitForCFbuffer:
    /* no break; */
  case FrTp_RxSm_WaitForCF_EOBbuffer:
    /* no break; */
  case FrTp_RxSm_WaitForLFbuffer:
    /* no break */
  case FrTp_RxSm_WaitForTxConfFC_ABT:
    /* #20 of value FrTp_RxSm_WaitForSegmPdu
              or of value FrTp_RxSm_WaitForTxConfFC_CTS
              or of value FrTp_RxSm_WaitForTxConfFC_WT
              or of value FrTp_RxSm_WaitForTxConfFC_OVER
              or of value FrTp_RxSm_WaitForSTFsegmBuffer
              or of value FrTp_RxSm_WaitForCFbuffer
              or of value FrTp_RxSm_WaitForCF_EOBbuffer
              or of value FrTp_RxSm_WaitForLFbuffer:
              or of value FrTp_RxSm_WaitForTxConfFC_ABT:
              Terminate the reception with error */
    FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
    break;
  case FrTp_RxSm_WaitForSTFunsegmBuffer:
    /* #40 of value FrTp_RxSm_WaitForSTFunsegmBuffer then:
     *            Ask for buffer one last time before (potentially) terminating the reception with error */
    deltaActiveSms = FrTp_RxSm_WaitForBufferUnsegmRxn(pRxSm, /*isTimeout=*/TRUE, rxSmIdx); /* SBSW_FRTP_WAIT_BUF_UNSEGM */
    break;
  case FrTp_RxSm_WaitForNxtFC_WT:
  /* #50 of value FrTp_RxSm_WaitForNxtFC_WT then:
   *          Ask for buffer one last time before (potentially) sending a FC.WT */
    deltaActiveSms = FrTp_RxSm_WaitForBufferSegmRxn(pRxSm, /*isTimeout=*/TRUE, rxSmIdx); /* SBSW_FRTP_WAIT_BUF_SEGM */
    break;
  case FrTp_RxSm_Idle:
    break;
  /* no default: */
  default:
    break;
  }
  /* switch(FrTp_RxSm_Item(pRxSm, State)) */
  return deltaActiveSms;
} /* FrTp_RxSm_TimeoutOf */

/**********************************************************************************************************************
  FrTp_RxSm_CalcBfsValue()
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
/* PRQA S 3673 5 */ /* MD_FrTp_3673 */
FRTP_LOCAL_INLINE FUNC(uint16, FRTP_CODE) FrTp_RxSm_CalcBfsValue(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 BfsValue = FrTp_MaxTransferLenSegm;
  uint16 maxBfS = FrTp_GetConnCtrlItem(pConnCtrl, MaxBfs);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the type of AvailableRxBuffer (i.e. PduLengthType) is uint32 this statement will not be false, always:  */
  if(((uint32)(FrTp_RxSm_Item(pRxSm, AvailableRxBuffer))) <= FrTp_MaxTransferLenSegm) /* PRQA S 3355, 3358 */ /* MD_FrTp_3355, MD_FrTp_3358 */
  {
    /* #20 AvailableRxBuffer is smaller or equal 64k: */
    BfsValue = (uint16)(FrTp_RxSm_Item(pRxSm, AvailableRxBuffer));
  }
  /* else: Deal with situation where 64k are transferred and application gives more buffer than required 
     BfsValue can only be 16-bit even when provided data length is larger, internally:
     Leave BfsValue on 64kByte (initialized, above) */

  /* #50 The limitation via configuration-parameter maxBfs is only applicable for FC-pdus */
  /* PRQA S 3201 15 */ /* MD_MSR_14.1 */
  /* #60 In case there is a Bfs-limitation limit the BfsValue prepared for the FC to the configured maxBfs-limit */
  if(    (0u != maxBfS)
      /* #70 and the BfsValue planned for the FC is too large */
      && (BfsValue > maxBfS)
    )
  {
    BfsValue = maxBfS;
  }
  else
  /* #80 Otherwise there is no limitation applicable */
  {
    /* #90 In case the BfsValue prepared for the FC is larger than the remaining data bytes of the reception
     *            give a 'final go' to the sender by setting BfsValue to 0 */
    if(BfsValue >= (uint16)FrTp_RxSm_CalcRemainingBytes(pRxSm))
    {
      BfsValue = 0u;
    }
  }
  return BfsValue;
} /* FrTp_RxSm_CalcBfsValue */

/**********************************************************************************************************************
  FrTp_RxSm_ActionOf()
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
 *
 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_ActionOf(
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm,
  uint8 rxSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Retrieve pointers to connection-config. and -control, pPoolDataUsed and pPoolCfg */
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_RxSm_Item(pRxSm, ConnCfgPtr);
  uint8 tpciBuffer[FrTp_TPCIMaxLength];
  PduInfoType TPCI;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Assemble the FC-pdu, i.e.:
   *          Initialize the PduInfoType with buffer the to hold the FC-pdu and set its length to an initial 0
   *          Set PCI-bytes' lower nibble to default value '0'
   *          Write BC to the FCs payload */
  uint8 newState = FrTp_RxSm_Idle;
  TPCI.SduDataPtr = tpciBuffer;
  TPCI.SduLength = 0u;
  FrTp_Util_WriteBC(tpciBuffer, FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrBC); /* SBSW_FRTP_ASSEMBLE_TPCI_RX */
  /* #30 In case the state-machine-state is */
  switch(FrTp_RxSm_Item(pRxSm, State)) 
  {
    case FrTp_RxSm_WaitForTxnNonBurstFC_CTS:
    {
      uint16 BfsValue = FrTp_RxSm_CalcBfsValue(pRxSm, pConnCfg->ConnCtrlPtr); /* SBSW_CALC_BFS_VALUE */
      /* #40 of value FrTp_RxSm_WaitForTxnNonBurstFC_CTS then:
       *               Initialize the block-mode by setting RemainingBytesInBlock to the BfsValue to be written to the FC-pdu
       *               Write the BfsValue to the buffer of the FC-pdu
       *               Set the length of the PCI-bytes in the TP-pdu to FrTp_TPCILengthFCCTS
       *               Set the PCI-byte in the buffer to FrTp_PCIFC | FrTp_FCCTS */
      FrTp_RxSm_Item(pRxSm, RemainingBytesInBlock) = ((PduLengthType)BfsValue); /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_RxSm_Item(pRxSm, CounterWft) = 0u; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_Util_WriteML(tpciBuffer, BfsValue); /* SBSW_FRTP_ASSEMBLE_TPCI_RX */
      TPCI.SduLength = FrTp_TPCILengthFCCTS;
      tpciBuffer[FrTp_FmtOffsetFrameType] = FrTp_PCIFC | FrTp_FCCTS; /* SBSW_FRTP_ASSEMBLE_TPCI_RX */
      newState = FrTp_RxSm_WaitForTxConfFC_CTS;
      break;
    }
    case FrTp_RxSm_WaitForTxnNonBurstFC_OVER:
    /* #50 of value FrTp_RxSm_WaitForTxnNonBurstFC_OVER then:
     *             Set the length of the PCI-bytes in the TP-pdu to FrTp_TPCILengthFCOVER
     *             Set the PCI-byte in the buffer to FrTp_PCIFC | FrTp_FCOVER */
      TPCI.SduLength = FrTp_TPCILengthFCOVER;
      tpciBuffer[FrTp_FmtOffsetFrameType] = FrTp_PCIFC | FrTp_FCOVER; /* SBSW_FRTP_ASSEMBLE_TPCI_RX */
      newState = FrTp_RxSm_WaitForTxConfFC_OVER;
      break;
    case FrTp_RxSm_WaitForTxnNonBurstFC_WT:
    /* #60 of value FrTp_RxSm_WaitForTxnNonBurstFC_WT then:
     *             Set the length of the PCI-bytes in the TP-pdu to FrTp_TPCILengthFCWT
     *             Set the PCI-byte in the buffer to FrTp_PCIFC | FrTp_FCWT */
      TPCI.SduLength = FrTp_TPCILengthFCWT;
      tpciBuffer[FrTp_FmtOffsetFrameType] = FrTp_PCIFC | FrTp_FCWT; /* SBSW_FRTP_ASSEMBLE_TPCI_RX */
      newState = FrTp_RxSm_WaitForTxConfFC_WT;
      break;
    case FrTp_RxSm_WaitForTxnNonBurstFC_ABT:
    /* #70 of value FrTp_RxSm_WaitForTxnNonBurstFC_ABT then:
     *             Set the length of the PCI-bytes in the TP-pdu to FrTp_TPCILengthFCABT
     *             Set the PCI-byte in the buffer to FrTp_PCIFC | FrTp_FCABT */
      TPCI.SduLength = FrTp_TPCILengthFCABT;
      tpciBuffer[FrTp_FmtOffsetFrameType] = FrTp_PCIFC | FrTp_FCABT; /* SBSW_FRTP_ASSEMBLE_TPCI_RX */
      newState = FrTp_RxSm_WaitForTxConfFC_ABT;
      break;
    case FrTp_RxSm_WaitForSTFunsegmBuffer:
      /* #80 of value FrTp_RxSm_WaitForSTFunsegmBuffer then:
       *               Ask for buffer (once each FR-cycle): */
      (void)FrTp_RxSm_WaitForBufferUnsegmRxn(pRxSm, /*isTimeout=*/FALSE, rxSmIdx); /* SBSW_FRTP_WAIT_BUF_UNSEGM */
      break;
    case FrTp_RxSm_WaitForNxtFC_WT:
      /* #90 of value FrTp_RxSm_WaitForNxtFC_WT then:
       *               Ask for buffer (once each FR-cycle): */
      (void)FrTp_RxSm_WaitForBufferSegmRxn(pRxSm, /*isTimeout=*/FALSE, rxSmIdx); /* SBSW_FRTP_WAIT_BUF_SEGM */
      break;
    default:
      break;
  }

  /* #100 In case TPCI.SduLength has been set to a non-zero (i.e. valid) value, above:
   *          Prepare finding a free FrIf-tx-pdu to send the FC-pdu, i.e.:
   *          Determine the pool data and configuration of the current connection
   *          Determine next free tx-pdu index in the pool used, according to the connections BandwidthLimitation flag */
  if(TPCI.SduLength > 0u)
  {
    uint8 poolOffset = FrTp_ConnGetTxPoolOffset(pConnCfg);
    P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA) pPoolDataUsed = FrTp_FrIf_GetTxPduPoolDataPtrByOffset(poolOffset);
    P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg = FrTp_FrIf_GetTxPduPoolPtrByOffset(poolOffset);

    FrTp_RxSm_Item(pRxSm, NxtFreePduIdx) = FrTp_FrIf_FindFreeTxPdu( /* SBSW_FRTP_FIND_FREE_TX_PDU_FOR_RXSM */
      pPoolCfg,
      pPoolDataUsed,
      (uint8)((pConnCfg->FrTpBandwidthLimitation != 0u) ? 1u : 0u)
    ); /* SBSW_FRTP_FIND_FREE_TX_PDU_FOR_RXSM */
    /* #120 In case the rx-state-machine has been assigned a tx-pdu to use:
     *            Initialize the required payload-parameter to indicate that there is no payload (in a rx-related pdu)
     *            Actually pass the parts of the pdu to the internal helper function which calls FrIf_Transmit() */
    if(FrTp_RxSm_Item(pRxSm, NxtFreePduIdx) != FrTp_NoPdu) /* SBSW_FRTP_TXPDU_AVAIL_FOR_RXSM */
    {
      FrTp_TxReturnType txResult = FrTp_RxSm_FrIfTransmit(&TPCI, rxSmIdx); /* SBSW_FRTP_RXSM_FRIF_TRANSMIT */
      /* #130 In case the helper function was able to pass the pdu to the FrIf:
       *              Set the timer to track that the tx-confirmation from FrIf comes in, in time.
       *              Set the state of the rx-state-machine as prepared, above.
       *              Otherwise: terminate the reception with error */
      if(txResult != FrTp_TxNotOk)
      {
        FrTp_RxSm_Item(pRxSm, Timer) = FrTp_GetConnCtrlItem(FrTp_RxSm_Item(pRxSm, ConnCfgPtr)->ConnCtrlPtr, TimeoutAr); /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
        FrTp_RxSm_Item(pRxSm, State) = newState; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      }
      else
      {
        FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
      }
    }
    else
    {
      /* #140 Otherwise store the index of this state-machine as the next one to retrieve bandwidth at the next execution of FrTp_MainFunction() */
      if(*FrTp_LCfg_RxCurrRoundRobChan() == FrTp_NoSm)
      {
        *FrTp_LCfg_RxCurrRoundRobChan() = rxSmIdx; /* SBSW_FRTP_LCFG_ACCESS */
      }
      if(FrTp_RxSm_Item(pRxSm, Timer) == FrTp_TimerInIdle)
      {
        FrTp_RxSm_Item(pRxSm, Timer) = FrTp_TimerMinimum; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      }
    }
  }
  return FrTp_DropOut;
} /* FrTp_RxSm_ActionOf */ /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
  FrTp_RxSm_EvalBufReqRetVal()
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
 */
/* PRQA S 3673 11 */ /* MD_FrTp_3673 */
FRTP_LOCAL_INLINE FUNC(sint8, FRTP_CODE) FrTp_RxSm_EvalBufReqRetVal(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint16 newTimer,
  uint8 rxSmIdx,
  uint8 bReq,
  uint8 newStateOk,
  uint8 newStateWt,
  uint8 newStateAbt,
  uint8 newStateOver,
  uint8 newCurrPCI
)
{
  /* #10 Retrieve pointer to rx-state-machine */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);
  sint8 deltaActiveSms = FrTp_DropOut;

  /* #20 In case the return value from PduR is */
  switch(bReq)
  {
    case BUFREQ_OK:
      /* #30 of value BUFREQ_OK:
       *              Buffer is there, TimeBr is running: Set the rx-state-machines':
       *                Timer to newTimer,
       *                State to newState,
       *                CurrPCI to newPduType */
      FrTp_RxSm_Item(pRxSm, CurrPCI) = newCurrPCI; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_RxSm_Item(pRxSm, State) = newStateOk; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_RxSm_Item(pRxSm, Timer) = newTimer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      /* #40 In case the data of an unsegmented reception has been copied
       *              Terminate the reception with success
       *              Otherwise: Check if the received pdu is a CF_EOB or a STFseg: In this case indicate to the caller to stay in the round-robin in order to send a FC.CTS */
      if(newCurrPCI == FrTp_PCISTFunseg)
      {
        FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_OK);
      }
      else
      {
        if((newCurrPCI == FrTp_PCICFEOB) || (newCurrPCI == FrTp_PCISTFseg))
        {
          deltaActiveSms = FrTp_StayIn;
        }
      }
      break;
    case BUFREQ_E_NOT_OK:
      /* #50 of value BUFREQ_E_NOT_OK:
       *              The PduR does not want to continue the reception at all:
       *              Set state and timer as given by the caller for this case */
      FrTp_RxSm_Item(pRxSm, State) = newStateAbt; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_RxSm_Item(pRxSm, Timer) = newTimer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      /* #60 In case this happens after an STFunseg or after an LF then no FC.ABT may ever be sent by this ECU, so directly terminate the reception depending on the pdu-type:
       *              In case the pdu received is an unsegmented STF:
       *              Terminate the reception without notification to the PduR in case the reception has not yet been officially accepted by PduR, otherwise: Terminate the reception with error.
       *              In case the pdu received is a LF:
       *              Terminate the reception with error */
      if(newCurrPCI == FrTp_PCISTFunseg) 
      {
        FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
      }
      if(newCurrPCI == FrTp_PCILF)
      {
        FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
      }
      break;
    case FrTp_OkButNotEnoughBuffer:
      /* #70 of value FrTp_OkButNotEnoughBuffer:
       *              Leave state as it is, i.e. ask for buffer, again, in the next FrTp_MainFunction() call - timeout at this state is handled there
       *              In case a fresh rx-pdus' payload is given in dataPtr:
       *              Copy the payload from the driver to the frtp-internal buffer */
      if((dataPtr != NULL_PTR) && (FrTp_RxSm_Item(pRxSm, ReceivedPduLen) > 0u))
      {
        VStdLib_MemCpy(FrTp_VCfg_RxBuf(rxSmIdx), dataPtr, FrTp_RxSm_Item(pRxSm, ReceivedPduLen)); /* SBSW_FRTP_EVAL_BUFREQ_RET_VAL */
      }
      /* #80 In case the PduR has not copied rx-data for a long time:
       *              Terminate the reception with error
       *              Otherwise: Take over the newState and newTimer given by the caller */
      if((FrTp_RxSm_Item(pRxSm, Timer) == 0u) && (newCurrPCI == FrTp_PCISTFunseg))
      {
        FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
      }
      else
      {
        FrTp_RxSm_Item(pRxSm, State) = newStateWt; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
        FrTp_RxSm_Item(pRxSm, Timer) = newTimer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      }
      break;
    case BUFREQ_E_OVFL:
      /* #90 of value BUFREQ_E_OVFL:
       *              The PduR is currently unable to process the reception due to the ML-field:
       *              Set state and timer as given by the caller for this case */
      FrTp_RxSm_Item(pRxSm, State) = newStateOver; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_RxSm_Item(pRxSm, Timer) = newTimer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      /* #100 In case this happens after an STFunseg or after an LF then no FC.OVER may ever be sent by this ECU, so directly:
       *              Terminate the reception with error.
       *              Otherwise it is a segmented reception and the FC-pdu can be sent immediately, so indicated the staying in the round-robin */
      if((newCurrPCI == FrTp_PCISTFunseg) || (newCurrPCI == FrTp_PCILF))
      {
        FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
      }
      else
      {
        deltaActiveSms = FrTp_StayIn;
      }
      break;
    default:
      /* #110 of an invalid value: Terminate reception with error */
      FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
      break;
  }
  return deltaActiveSms;
} /* FrTp_RxSm_EvalBufReqRetVal */ /* PRQA S 6030, 6060, 6080 */ /* MD_MSR_STCYC, MD_MSR_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
  FrTp_RxSm_CopyRxData()
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
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_RxSm_CopyRxData(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  uint8 rxSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg = FrTp_RxSm_Item(pRxSm, ConnCfgPtr);
  uint8 bReq = BUFREQ_E_NOT_OK;
  PduIdType id = pConnCfg->FrTpSduRxId;
  PduLengthType availableRxBuffer;
  PduInfoType applPduInfo;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the PduR has not yet been informed about the start of reception
   *          Inform application about the start of reception
   *          Use applPduInfo to let the upper layer have a look at the payload of the STF
   *          Call PduR_FrTpStartOfReception() */
  if(FrTp_RxSm_Item(pRxSm, RxStartedAtUpperLayer) == FALSE)
  {
    availableRxBuffer = 0u;
#if (FRTP_FULL_AR421 == STD_ON) /* COV_FRTP_UNSUPPORTED_SAFEBSW_FEATURE */
    applPduInfo.SduLength = FrTp_RxSm_Item(pRxSm, ReceivedPduLen);
    applPduInfo.SduDataPtr = dataPtr;
#endif
    bReq = (uint8)PduR_FrTpStartOfReception( /* SBSW_FRTP_START_OF_RECEPTION */
      /*PduIdType id=*/id,
# if (FRTP_FULL_AR421 == STD_ON) /* COV_FRTP_UNSUPPORTED_SAFEBSW_FEATURE */
      /*const PduInfoType* info=*/&applPduInfo,
# else
      /*const PduInfoType* info=*/NULL_PTR,
# endif
      /*PduLengthType TpSduLength=*/FrTp_RxSm_Item(pRxSm, DataLength),
      /*PduLengthType* bufferSizePtr=*/&availableRxBuffer
    );
    /* #20 In case the PduR has indicated a value that is not BUFREQ_E_NOT_OK and that is also a valid value
     *            Set the flag that the reception is officially started, also in the upper-layers' state-machine
     *            Recognize, how much rx-buffer there is.
     *            In any case evaluate the AvailableRxBuffer and bReq */
    /* PRQA S 3355 4 */ /* MD_FrTp_3355 */
    if(    (bReq == BUFREQ_OK)
        || (bReq == BUFREQ_E_OVFL)
      )
    {
      FrTp_RxSm_Item(pRxSm, RxStartedAtUpperLayer) = TRUE; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_RxSm_Item(pRxSm, AvailableRxBuffer) = availableRxBuffer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
    }
    if((availableRxBuffer < FrTp_RxSm_Item(pRxSm, ReceivedPduLen)) && (bReq == BUFREQ_OK))
    {
      bReq = FrTp_OkButNotEnoughBuffer;
    }
  }
  /* #30 In case the PduR has accepted the reception and the AvailableRxBuffer is > 0u
   *          Prepare an PduInfoType and copy ReceivedPduLen to the PduR */
  if((FrTp_RxSm_Item(pRxSm, RxStartedAtUpperLayer) == TRUE) && (FrTp_RxSm_Item(pRxSm, AvailableRxBuffer) >= FrTp_RxSm_Item(pRxSm, ReceivedPduLen)))
  {
    availableRxBuffer = FrTp_RxSm_Item(pRxSm, AvailableRxBuffer);
    applPduInfo.SduDataPtr = dataPtr;
    applPduInfo.SduLength = FrTp_RxSm_Item(pRxSm, ReceivedPduLen);
    bReq = (uint8)PduR_FrTpCopyRxData( /* SBSW_FRTP_PDUR_COPYRXDATA_ACTUALLY_COPY */
      /*PduIdType id=*/id,
      /*PduInfoType* info=*/&applPduInfo,
      /*PduLengthType* availableDataPtr=*/&availableRxBuffer
    ); /* SBSW_FRTP_PDUR_COPYRXDATA_ACTUALLY_COPY */
    /* #40 In case bReq is valid and the PduR has not rejected the reception:
     *            Recognize how much rx-buffer there is.
     *            In case copying the ReceivedPduLen to the PduR was successful
     *            Update the DataIndex and ReceivedPduLen of the rx-state-machine. */
    switch(bReq)
    {
      case BUFREQ_OK:
        FrTp_RxSm_Item(pRxSm, DataIndex) = (PduLengthType)(FrTp_RxSm_Item(pRxSm, DataIndex) + FrTp_RxSm_Item(pRxSm, ReceivedPduLen)); /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
        FrTp_RxSm_Item(pRxSm, ReceivedPduLen) = 0u; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */

        if((availableRxBuffer == 0u) && (FrTp_RxSm_CalcRemainingBytes(pRxSm) > 0u))
        {
          bReq = FrTp_OkButNotEnoughBuffer;
        }
        FrTp_RxSm_Item(pRxSm, AvailableRxBuffer) = availableRxBuffer; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
        break;
      case BUFREQ_E_OVFL:
        break;
      default:
        bReq = BUFREQ_E_NOT_OK;
        break;
    }
  }
  return bReq;
} /* FrTp_RxSm_CopyRxData */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FrTp_RxSm_FrIfTxConfirmation()
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
 */
FUNC(void, FRTP_CODE) FrTp_RxSm_FrIfTxConfirmation(
  uint8 rxSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2CONST(FrTp_ConnCtrlType, AUTOMATIC, FRTP_CONST) pConnCtrl;
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Retrieve pointer to the rx-state-machine provided by the caller */
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm = FrTp_VCfg_RxState(rxSmIdx);

  /* #20 Retrieve pointer to the connection configuration of the rx-state-machine */
  pConnCfg = FrTp_RxSm_Item(pRxSm, ConnCfgPtr);
  /*! Is is assumed that the internal method for FrTp_TxConfirmation is called only in case of a valid FrIf_Transmit-call, before.
      This is assured by the FrIf-Pending-flag-arrays administered by the FrTp. Thus this (internal) DET-check is superfluous:
  FrTp_CheckDetErrorReturnVoid((NULL_PTR)!= pConnCfg, FrTp_TxConfirmation_ServiceId, FRTP_E_NULL_PTR) */
  /* #30 Retrieve pointer to the connection-control structure of the connection */
  pConnCtrl = pConnCfg->ConnCtrlPtr;
  /*! Is is assumed that the internal method for FrTp_TxConfirmation is called only in case of a valid FrIf_Transmit-call, before.
      This is assured by the FrIf-Pending-flag-arrays administered by the FrTp. Thus this (internal) DET-check is superfluous:
  FrTp_CheckDetErrorReturnVoid((NULL_PTR)!= pConnCtrl, FrTp_TxConfirmation_ServiceId, FRTP_E_NULL_PTR) */
  /* #40 In case the state-machine-state is */
  switch(FrTp_RxSm_Item(pRxSm, State))
  {
  case FrTp_RxSm_WaitForTxConfFC_CTS:
  /* #50 of value FrTp_RxSm_WaitForTxConfFC_CTS */
    /* #60 Set timer to TimeoutCr as timeout for that state */
    FrTp_RxSm_Item(pRxSm, Timer) = FrTp_GetConnCtrlItem(pConnCtrl, TimeoutCr); /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
    /* #70 Set the rx-state-machine to state FrTp_RxSm_WaitForSegmPdu */
    FrTp_RxSm_Item(pRxSm, State) = FrTp_RxSm_WaitForSegmPdu; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
    break;
  case FrTp_RxSm_WaitForTxConfFC_ABT:
    /* no break; */
  case FrTp_RxSm_WaitForTxConfFC_OVER:
  /* #90 of value FrTp_RxSm_WaitForTxConfFC_ABT */
  /* #100 or of value FrTp_RxSm_WaitForTxConfFC_OVER */
    /* #110 Terminate the reception with error */
    FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK);
    break;
  case FrTp_RxSm_WaitForTxConfFC_WT:
    /* #120 of value FrTp_RxSm_WaitForTxConfFC_WT then a FC.WT has been transmitted successfully. After that:
     *            Set the state-machine-state to FrTp_RxSm_WaitForTxnNonBurstFC_WT
     *            Set timer to TimeBuffer as timeout for that state */
    FrTp_RxSm_Item(pRxSm, CounterWft)++; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
    if(FrTp_RxSm_Item(pRxSm, CounterWft) < FrTp_GetConnCtrlItem(pConnCtrl, MaxWft)) /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
    {
      /* #130 After the first FC.WT has been tx-confirmed: Wait for the next FC.WT. At the same time continue asking for buffer */
      FrTp_RxSm_Item(pRxSm, State) = FrTp_RxSm_WaitForNxtFC_WT; /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
      FrTp_RxSm_Item(pRxSm, Timer) = FrTp_GetConnCtrlItem(pConnCtrl, TimeBr); /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
    }
    else
    {
      /* #140 Too many FC.WT have been sent: End the reception */
      FrTp_Rsrc_ReleaseRxSm(rxSmIdx, E_NOT_OK); /* SBSW_FRTP_RXSM_PTR_FROM_VALID_IDX */
    }
    break;
  default:
    break;
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
/* FrTp_RxSm_FrIfTxConfirmation */

/**********************************************************************************************************************
 FrTp_RxSm_FrIfRxIndication()
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
 */
FUNC(void, FRTP_CODE) FrTp_RxSm_FrIfRxIndication(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  PduIdType FrIfRxPduId,
  uint8 rxSmIdx
)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Retrieve pointer to the position of the PCI in the pdu */
  CONST(SduDataPtrType, AUTOMATIC) dataPtr = &FrIf_PduInfoPtr->SduDataPtr[FrTp_Util_OffsetTPCI];

  /* ----- Implementation ----------------------------------------------- */
  /* #20 In case there is a RxSdu configured for the connection provided by the caller */
  if(pConnCfg->FrTpSduRxId != FRTP_INVALID_SNV) /* PRQA S 3355, 3358 */ /* MD_FrTp_3355, MD_FrTp_3358 */
  {
    /* ----- Local Variables ---------------------------------------------- */
    uint8 pduSubType = (uint8)(dataPtr[0] & FrTp_PduSubTypeMask);
    uint8 lCurrPCI = (uint8)(dataPtr[0] & FrTp_PduTypeMask);
    uint8 FPL = FrTp_Util_ReadFPL(dataPtr);
    uint16 ML = FrTp_Util_ReadML(dataPtr);

    uint8 maxCfgedRxPayloadLen = FrTp_RxGetPduPayloadLen(FrIfRxPduId, FrTp_PCICF1);
    uint8 rxedSduPayloadLen = ((uint8)FrIf_PduInfoPtr->SduLength);
    uint8 rxedSduPayloadLenCF = FrTp_CalcPduPayloadLen(rxedSduPayloadLen, FrTp_PCICF1);
    uint8 lengthOk;
    
    /* #30 In the flag lengthOk, verify that either the FPL is >0 or a LF has been received
     *                                         that the FPL is not larger than configured according to the rx-pdu
     *                                         that the FPL is not larger than the max. possible CF-length calculated based on the length indicated by FrIf
     *                                         that values calculated for the former two conditions (from whose one is determined based on an external parameter) are fit to each other */
    lengthOk = (uint8)(    (    (FPL > 0u)
                             || (lCurrPCI == FrTp_PCILF)
                           )
                        && (maxCfgedRxPayloadLen >= FPL)
                        && (rxedSduPayloadLenCF >= FPL)
                        && (maxCfgedRxPayloadLen >= rxedSduPayloadLenCF)
                      );
    /* #40 In case lCurrPCI is */
    switch(lCurrPCI)
    {
      case FrTp_PCISTF:
        /* #50 of value FrTp_PCISTF then
         *                Check for the pdu to be an STFU. STFA-pdus are ignored. */
        if(pduSubType == FrTp_STFU)
        {
          /* #60 Retrieve pdu-length according to the FrIfRxPduId indicated by FrIf
           *                  Calculate the max. allowed payload-length based on the pdu-length indicated by FrIf
           *                  Set the lengthOk flag to true
           *                  in case FPL > 0u
           *                  and ML > 0u (i.e. no unknown message length transmission)
           *                  and the FPL is not larger than the max. FPL in the given pdu
           *                  and FPL is not larger than the max. FPL based on the given pdu-length
           *                  and the pdu and the pdu-length fit together */
          maxCfgedRxPayloadLen = FrTp_RxGetPduPayloadLen(FrIfRxPduId, FrTp_PCISTF);
          rxedSduPayloadLen = FrTp_CalcPduPayloadLen(rxedSduPayloadLen, FrTp_PCISTF);
          lengthOk = (uint8)(    (FPL > 0u)
                              && (ML > 0u)
                              && (FPL <= maxCfgedRxPayloadLen)
                              && (rxedSduPayloadLen >= FPL)
                              && (maxCfgedRxPayloadLen >= rxedSduPayloadLen)
                            );
          /* #70 In case the length is ok:
           *                  Process the received STFU-pdu */
          if(lengthOk == 1u)
          {
            (void)FrTp_RxSm_ReceivedSTF(pConnCfg, dataPtr, ML, FPL, rxSmIdx); /* SBSW_FRTP_RECEIVED_STF */
          }
        }
        break;
      case FrTp_PCICFEOB:
        /* no break; */
      case FrTp_PCICF1:
        /* no break; */
      case FrTp_PCILF:
      /* #80 of value FrTp_PCICFEOB, FrTp_PCICF1 or FrTp_PCILF: Process the received CF, CF_EOB or LF in case the connection is currently active. */
        if(FrTp_VCfg_ConnState(pConnCfg->ConnIdx)->CurrRxSmIdx != FrTp_NoSm)
        {
          (void)FrTp_RxSm_ReceivedSegmPdu(dataPtr, ML, FPL, rxSmIdx, lCurrPCI, lengthOk); /* SBSW_FRTP_RECEIVED_SEGM_PDU */
        }
        break;
      default:
      /* #90 of an invalid value then the pdu has to be ignored according ISO10681-2 */
        break;
    }
  }
} /* FrTp_RxSm_FrIfRxIndication() */

/**********************************************************************************************************************
  FrTp_RxSm_TriggerTransmit()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, FRTP_CODE) FrTp_RxSm_TriggerTransmit(
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxPduInfoPtr,
  PduIdType FrIfTxPduId
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  P2VAR(FrTp_DecoupPduAdminType, AUTOMATIC, FRTP_APPL_DATA) pDecoupAdminData = &FrTp_FrIf_GetDecoupAdminById(FrIfTxPduId);
  PduIdType connIdx = pDecoupAdminData->ConnCfgPtr->ConnIdx;
  P2VAR(FrTp_ConnStateType, AUTOMATIC, FRTP_APPL_DATA) pConnState = FrTp_VCfg_ConnState(connIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 In case the length the FrIf wants to trigger is in the range of pdu-length that the FrTp is able to provide (both, for Rx and Tx)
         Assemble the pdu */
  if(    (    (pDecoupAdminData->PduInfoPayload.SduLength + pDecoupAdminData->PduLengthTPCI) 
           <= (FrTpTxPduInfoPtr->SduLength)
         )
      && (pConnState->CurrRxSmIdx != FrTp_NoSm)
    )
  {
    PduInfoType TPCI;

    TPCI.SduLength = pDecoupAdminData->PduLengthTPCI;
    TPCI.SduDataPtr = pDecoupAdminData->TPCIData;

    FrTpTxPduInfoPtr->SduLength = FrTp_Util_AssemblePdu( /* SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU */
      pDecoupAdminData->ConnCfgPtr,
      &TPCI,
      &(pDecoupAdminData->PduInfoPayload),
      FrTpTxPduInfoPtr->SduDataPtr
    ); /* SBSW_FRTP_ASSEMBLE_TRIGRD_RXSM_PDU */
    retVal = E_OK;
  }
  return retVal;
} /* FrTp_RxSm_TriggerTransmit */

/**********************************************************************************************************************
  FrTp_RxSm_OperateAllSms()
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
 */
FUNC(void, FRTP_CODE) FrTp_RxSm_OperateAllSms(
  void
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least iter;
  volatile P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pRxSm;
  sint16_least activeSms;
  uint8 rxSmIdx = *FrTp_LCfg_RxCurrRoundRobChan();

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter FRTP_EXCLUSIVE_AREA_0*/
  FrTp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* #20 Decrease the timers of all rx-state-machines, i.e. loop all rx-state-machines and
   *          Retrieve pointer to rx-state-machine
   *          Process the rx-state-machines timeout- and/or state-action */
  activeSms = FrTp_RxSm_PrepareAllSms();
  *FrTp_LCfg_RxCurrRoundRobChan() = FrTp_NoSm; /* SBSW_FRTP_LCFG_ACCESS */
  for(iter = 0u; ((iter < *FrTp_LCfg_RxSm_MaxIterations()) && (activeSms > 0)); iter++)
  {
    sint8 deltaActiveSms = FrTp_StayIn;

    pRxSm = FrTp_VCfg_RxState(rxSmIdx);
    /* #21 In case the state-machine is not idle process its current state */
    if(FrTp_RxSm_Item(pRxSm, State) != FrTp_RxSm_Idle)
    {
      /* #30 In case the timer of the rx-state-machine is 0 A timeout of the rx-state-machine has happened:
       *             Call the timeout-handling function of the rx-state-machine */
      if(FrTp_RxSm_Item(pRxSm, Timer) == 0u)
      {
        deltaActiveSms = FrTp_RxSm_TimeoutOf(pRxSm, rxSmIdx); /* SBSW_FRTP_VALID_WRAPPED_RXSM_IDX */
      }
      /* #40 In case the timer is [still] not [yet] '0' the state-machine is in normal operation:
       *             Call the action-handling function of the rx-state-machine */
      if(    (deltaActiveSms == FrTp_StayIn)
          && (FrTp_RxSm_Item(pRxSm, Timer) != 0u)
        )
      {
        deltaActiveSms = FrTp_RxSm_ActionOf(pRxSm, rxSmIdx); /* SBSW_FRTP_VALID_WRAPPED_RXSM_IDX */
      }
      /* #50 Apply the deltaActiveSms returned by the handler-functions onto the number of activeSms
       *            Increase the rxSmIdx and check its value for wrap-around */
      activeSms = activeSms + deltaActiveSms;
    }
    rxSmIdx = rxSmIdx + 1u;
    if(rxSmIdx >= FrTp_CCfg_NumRxChan()) /* SBSW_FRTP_RXSM_IDX_WRAP_AROUND_CHECK */
    {
      rxSmIdx = 0u;
    }
  }
  /* #51 In case the distribution of tx-pdus has ended with at least one state-machine that has gotten no tx-pdu although it wanted to:
   *     Store that state-machines index to start with it when distributing tx-pdus again in the next call to FrTp_MainFunction()
   *     Otherwise all state-machines are 'happy', i.e..
   *     Store the index of the last tx-state-machine that sent data for the next call to FrTp_MainFunction() */
  if(*FrTp_LCfg_RxCurrRoundRobChan() == FrTp_NoSm)
  {
    *FrTp_LCfg_RxCurrRoundRobChan() = rxSmIdx; /* SBSW_FRTP_LCFG_ACCESS */
  }
  /* #60 Leave FRTP_EXCLUSIVE_AREA_0 */
  FrTp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
} /* FrTp_RxSm_OperateAllSms */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

#define FRTP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_RxSm.c
 *********************************************************************************************************************/

