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
 *        \file   FrTp_TxSm.h
 *        \brief  Header file of the FrTp sub-module TxSm.
 *
 *      \details  Declares those functions of the sub-module TxSm that are called by other modules of the FrTp.
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

#if !defined (FRTP_TXSM_H)
#define FRTP_TXSM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrTp_GlobCfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FRTP_TXSM_SW_MAJOR_VERSION                     (2u)
# define FRTP_TXSM_SW_MINOR_VERSION                     (4u)
# define FRTP_TXSM_SW_PATCH_VERSION                     (4u)
/* ----- API service IDs ----- */

/* ----- Error codes ----- */

/* ----- Modes ----- */

/* ----- Component specific stuff ----- */
/*!< Bandwidth Control (BC) */
#define FrTp_SCexpMask            ((uint8)0x07u)
#define FrTp_MNPCMask             ((uint8)0xf8u)
#define FrTp_MNPCMaskNoShift      ((uint8)0x1fu)
#define FrTpIsoMNPCBitPos         ((uint8_least)0x03u)

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

/***********************************************************************************************************************
 FrTp_TxSm_TriggerTransmit()
 **********************************************************************************************************************/
/*!
 * \brief       Assembles tx-related TP-pdus during FrTp_TriggerTransmit()-calls.
 * \details     Checks the validity of the FrTp_TriggerTransmit()-call prior to the assembly. Called by FrIf
 * \param[in]   PduIdType FrIfTxPduId: TxPduId of a FlexRay-pdu of the FrIf
 *              PRE_FRTP_VALID_TX_PDU_ID_TRIG_TX
 * \param[in]   PduInfoType FrTpTxPduInfoPtr 
 *              N-PDU Information Structure which contains
 *              a) pointer to where the FrTp Tx N-PDU shall be copied to
 *              b) the length of the FrTp Tx N-PDU
 *              PRE_FRTP_VALID_PDU_INFO_TYPE FrTpTxPduInfoPtr
 * \param[out]  P2VAR(uint8, AUTOMATIC) pErrorId
 *              Pointer parameter pErrorId has to point to a variable of type uint8.
 * \return      Std_ReturnType: E_OK: The request has been accepted, i.e. payload of a FrTp-pdu to be sent has been provided.
 *                              E_NOT_OK: The request has not been accepted.
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_TxSm_TriggerTransmit(
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxPduInfoPtr,
  PduIdType FrIfTxPduId,
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pErrorId
);

/**********************************************************************************************************************
  FrTp_TxSm_FrIfTxConfirmation()
**********************************************************************************************************************/
/*!
 * \brief       Handles the confirmation by FrIf that a tx-related TP-pdu has been transmitted successfully.
 * \details     The function is called by FrTp itself (e.g. FrTp_FrIf_RxIndication (+followers), 
 *              FrTp_TxConfirmation) on interrupt and task level.
 *              This is a function that is used by both, Rx- and Tx-part of a Tp-Channel.
 *              I.e. the given index can be for Rx and Tx !
 * \param[in]   uint8 txSmIdx: Index of the tx-state-machine the function FrTp_TxConfirmation has been called for by FrIf.
 *                             PRE_FRTP_VALID_ACTIVE_TX_SM_IDX
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpBandwidthControl
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_TxSm_FrIfTxConfirmation(
  uint8 txSmIdx
);

/**********************************************************************************************************************
  FrTp_TxSm_OperateAllSms()
**********************************************************************************************************************/
/*!
 * \brief       Operates all tx-channels.
 * \details     Those tx-channels are operated that are active transmitting data. This includes Surveying timeouts.
 *              The number of active connections can change by calls to FrTp_Transmit().
 *              Thus the function uses the critical section to count the number of active tx-statemachines correctly.
 * \pre         PRE_FRTP_INIT
 * \context     ISR|TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpMainFunction
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_TxSm_OperateAllSms(
  void
);

/**********************************************************************************************************************
 FrTp_TxSm_FrIfRxIndication()
**********************************************************************************************************************/
/*! 
 * \brief       Handles the FrIf's call to FrTp_RxIndication() for the affected rx-channels.
 * \details     Handles the FrIf's call to FrTp_RxIndication() for the affected rx-channels. 
 *              In case the state-machine-state is of a value that is different from "expecting a FC" OR different from 
 *              state required for the "tolerate early FC"-feature: The FC.CTS is ignored.
 * \param[in]   P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
 *              Pointer parameter dataPtr has to point to an array of type uint8 whose length is in the range [1..FrTp_TPCIMaxLength].
 * \param[in]   volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_PTR pTxSm
 * \param[in]   uint8 txSmIdx
 *              PRE_FRTP_VALID_ACTIVE_TX_SM_IDX txSmIdx
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     ISR|TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpVariousJLE
 * \trace       CREQ-109463
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_TxSm_FrIfRxIndication(
  P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr,
  volatile P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pTxSm,
  uint8 txSmIdx
);

#define FRTP_STOP_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* FRTP_TXSM_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_TxSm.h
 *********************************************************************************************************************/


