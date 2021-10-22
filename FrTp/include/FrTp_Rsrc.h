/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!
 *        \file   FrTp_Rsrc.h
 *        \brief  Header file of the FrTp sub-module Rsrc.
 *
 *      \details  Declares those functions of the sub-module Rsrc that are called by other modules of the FrTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK in file FrTp.c
 *********************************************************************************************************************/

#if !defined (FRTP_RSRC_H)
#define FRTP_RSRC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrTp_GlobCfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FRTP_RSRC_SW_MAJOR_VERSION                     (2u)
# define FRTP_RSRC_SW_MINOR_VERSION                     (4u)
# define FRTP_RSRC_SW_PATCH_VERSION                     (4u)
/* ----- API service IDs ----- */

/* ----- Error codes ----- */

/* ----- Modes ----- */

/* ----- Component specific stuff ----- */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  FrTp_Rsrc_FindTxSm()
**********************************************************************************************************************/
/*!
 * \brief       Searches and returns the next free tx-state-machine.
 * \details     FrTp_Rsrc_FindTxSm is used by the FrTp itself
 * \return      uint8 number of the next free channel if found, otherwise FrTp_NoSm
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpStateMachineHandling
 *********************************************************************************************************************/
extern FUNC(uint8, FRTP_CODE) FrTp_Rsrc_FindTxSm(
  void
);

/**********************************************************************************************************************
  FrTp_Rsrc_FindRxSm()
**********************************************************************************************************************/
/*!
 * \brief       Searches and returns the next free rx-state-machine
 * \details     FrTp_Rsrc_FindRxSm is used by the FrTp itself. The function can be called on interrupt and task level. 
 * \return      uint8 number of the next free channel if found, otherwise FrTp_NoSm
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpStateMachineHandling
 *********************************************************************************************************************/
extern FUNC(uint8, FRTP_CODE) FrTp_Rsrc_FindRxSm(
  void
);

/**********************************************************************************************************************
  FrTp_Rsrc_AllocateRxSm()
**********************************************************************************************************************/
/*!
 * \brief       Initializes a new, free rx-state-machine to operate the given connection.
 * \details     Initializes a new, free rx-state-machine to operate the given connection by setting CurrPCI, FPL, timer 
 *              and state to process the next reception step.
 * \param[in]   P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg: Value used to initialize the rx-state-machine member 
 * \param[in]   uint16 ML: Value used to initialize the rx-state-machine member DataLength.
 * \param[in]   uint16 newTimer: Value used to initialize the rx-state-machine member Timer.
 *                               PRE_FRTP_VALID_RX_STATE_TIMER
 * \param[in]   uint8 rxSmIdx: Index of the rx-state machine that shall be allocated in the generated array FrTp_RxState[]
 *                             PRE_FRTP_VALID_RX_SM_IDX rxSmIdx
 * \param[in]   uint8 FPL: Value used to initialize the rx-state-machine member ReceivedPduLen.
 * \param[in]   uint8 currPCI: Value used to initialize the rx-state-machine member CurrPCI.
 *                             PRE_FRTP_VALID_STATE_CURR_PCI
 * \param[in]   uint8 newState: Value used to initialize the tx-state-machine member State.
 *                              PRE_FRTP_VALID_RX_STATE_PARAM
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpStateMachineHandling
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Rsrc_AllocateRxSm(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  PduLengthType ML,
  uint16 newTimer,
  uint8 rxSmIdx,
  uint8 FPL,
  uint8 currPCI,
  uint8 newState
);

 /**********************************************************************************************************************
  FrTp_Rsrc_AllocateTxSm()
**********************************************************************************************************************/
/*!
 * \brief       Initializes a new, free tx-state-machine to operate the given connection.
 * \details     Initializes a new, free tx-state-machine to operate the given connection by setting requestedTxLen, timer and currMNPC.
 * \param[in]   P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg: Value used to initialize the tx-state-machine member ConnCfgPtr.
 *                                                                             PRE_FRTP_VALID_P_CONN_CFG pConnCfg
 * \param[in]   uint16 ML: Value used to initialize the tx-state-machine member DataLength.
 * \param[in]   uint16 newTimer: Value used to initialize the tx-state-machine member Timer.
 *                               PRE_FRTP_VALID_TX_STATE_TIMER
 * \param[in]   uint8 txSmIdx: Index of the tx-state machine that shall be allocated in the generated array FrTp_TxState[]
 *                             PRE_FRTP_VALID_TX_SM_IDX txSmIdx
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpStateMachineHandling
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Rsrc_AllocateTxSm(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  PduLengthType ML,
  uint16 newTimer,
  uint8 txSmIdx
);

/**********************************************************************************************************************
  FrTp_Rsrc_ReleaseRxSm()
**********************************************************************************************************************/
/*!
 * \brief       Initializes the receiver part of the channel specified by parameter rxSmIdx
 * \details     Calls rx-indication of application if valid notify-code is given, otherwise just resets the channel.
 *              The function is called by FrTp itself on interrupt and task level.
 *              In case of error (!= FRTP_NTFRSLT_OK) only the FrIf-Rx-Pdus used by the connection
 *              in the channel to be initialized are reset.
 *              Because of this even full-duplex operation should be possible.
 *              Only caveat for full-duplex-operation is this:
 *              "FC-Pdu": There usually is only one FC-Pdu which may be used by both Rx- and
 *              Rx-part of a channel in case of FRTP_HAVE_TC=ON
 * \param[in]   uint8 smIdx : Index of the rx-state-machine that shall be released and initialized.
 * \param[in]   Std_ReturnType notifyCode to be given to application
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpStateMachineHandling, DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Rsrc_ReleaseRxSm(
  uint8 rxSmIdx,
  Std_ReturnType notifyCode
);

/**********************************************************************************************************************
  FrTp_Rsrc_ReleaseTxSm()
**********************************************************************************************************************/
/*!
 * \brief       Initializes the transmitter part of the channel specified by parameter txSmIdx
 * \details     Calls tx-confirmation of application if valid notify-code is given, otherwise just resets the channel.
 *              The function is called by FrTp itself on interrupt and task level.
 * \pre         PRE_FRTP_SM_ACCESS
 *              In case of error (!= FRTP_NTFRSLT_OK) only the FrIf-Tx-Pdus used by the connection
 *              in the channel to be initialized are reset.
 *              Because of this even full-duplex operation should be possible.
 *              Only caveat for full-duplex-operation is this:
 *              "FC-Pdu": There usually is only one FC-Pdu which may be used by both Rx- and
 *              Tx-part of a channel in case of FRTP_HAVE_TC=STD_ON
 * \param[in]   uint8 txSmIdx : Index of the tx-state-machine that shall be released and initialized.
 * \param[in]   Std_ReturnType notifyCode to be given to application
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpStateMachineHandling, DSGN-FrTpGenericPduRTPinterface
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Rsrc_ReleaseTxSm(
  uint8 txSmIdx,
  Std_ReturnType notifyCode
);

/**********************************************************************************************************************
  FrTp_Rsrc_InitAllSms()
**********************************************************************************************************************/
/*!
 * \brief       Resets all statemachines (i.e. "Channels") that are currently busy.
 * \details     This method is used by FrTp_Init and conducts the initialization of ALL Tx- and Rx-statemachines.
 *              The caller (FrTp_Init) determines the actions by parameter "result".
 *              The function is called by FrTp itself on interrupt and task level.
 *              Callers are FrTp_Init() and FrTp_Shutdown()
 *              Refer to called functions FrTp_Rsrc_ReleaseRxSm and FrTp_Rsrc_ReleaseTxSm for further details.
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpInitialization
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Rsrc_InitAllSms(
  void
);

/**********************************************************************************************************************
  FrTp_Rsrc_InitAllConns()
**********************************************************************************************************************/
/*!
 * \brief       Initializes connection-specific runtime-values for all connections
 * \details     Initializes all links from connections to statemachines 
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpInitialization
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Rsrc_InitAllConns(
  void
);

#define FRTP_STOP_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* FRTP_RSRC_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Rsrc.h
 *********************************************************************************************************************/


