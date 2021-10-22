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
 *        \file   FrTp_RxSm.h
 *        \brief  Header file of the FrTp sub-module RxSm.
 *
 *      \details  Declares those functions of the sub-module RxSm that are called by other modules of the FrTp.
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

#if !defined (FRTP_RXSM_H)
# define FRTP_RXSM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrTp_GlobCfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FRTP_RXSM_SW_MAJOR_VERSION                     (2u)
# define FRTP_RXSM_SW_MINOR_VERSION                     (4u)
# define FRTP_RXSM_SW_PATCH_VERSION                     (4u)
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
 FrTp_RxSm_OperateAllSms()
**********************************************************************************************************************/
/*!
 * \brief       Operates all rx-channels that are active receiving data and surveys rx-timing conditions of the channels.
 * \details     This is a function called cyclically (e.g. every FlexRay-cycle - 5ms).
 *              This function works with a while loop over all rx-state-machines:
 *              Each channel loops at max. 2 times. "2 times" happens when it tries to transmit a tx-pdu:
 *              1st time to copy-rx-data
 *              2nd time to call FrIf_Transmit
 *              Thus the max. number of iterations is num(rx-channels) * num(all tx-pdus) * 2
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpMainFunction
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_RxSm_OperateAllSms(
  void
);

/**********************************************************************************************************************
 FrTp_RxSm_FrIfTxConfirmation()
**********************************************************************************************************************/
/*!
 * \brief       Handles the confirmation by FrIf that a rx-related TP-pdu has been transmitted successfully.
 * \details     This is a function that is used by both, rx- and tx-part-state-machine.
 *              I.e. the given index can be for Rx and Tx!
 *              The function is called by FrTp itself (e.g. FrTp_FrIf_RxIndication+followers, FrTp_TxConfirmation)
 * \param[in]   uint8 rxSmIdx: Index of the rx-state-machine the function FrTp_TxConfirmation has been called for by FrIf.
 *                             PRE_FRTP_VALID_ACTIVE_RX_SM_IDX
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   TRUE with different rxSmIdx
 * \synchronous TRUE
 * \trace       DSGN-FrTpBandwidthControl, DSGN-FrTpWaitFrameHandling, DSGN-FrTpTxConfirmationHandling
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_RxSm_FrIfTxConfirmation(
  uint8 rxSmIdx
);

/**********************************************************************************************************************
 FrTp_RxSm_FrIfRxIndication
 **********************************************************************************************************************/
/*!
 * \brief       Processes the reception of pdu-types STF, CF, CF_EOB and LF Pdus internally.
 * \details     As each and every of the pdu-types listed above contains a FPL parameter, prior to the parsing of the pdu-type
 *              a length check is done. Then the pdu-type is parsed and checked to fit the current reception-context.
 * \param[in]   P2CONST(uint8, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr: Pointer to payload of pdu _past_ the address-bytes
 *              PRE_FRTP_VALID_PDU_INFO_TYPE FrIf_PduInfoPtr
 * \param[in]   P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg: Pointer to the connection the FrTp-pdu received belongs to.
 *              PRE_FRTP_VALID_P_CONN_CFG pConnCfg
 * \param[in]   PduIdType FrIfRxPduId: Internal index of the FrTp-pdu received in the generated array FrTp_FrIfRxPdus[].
 *              PRE_FRTP_VALID_FRIF_RX_PDU_IDX FrIfRxPduId
 * \param[in]   uint8 rxSmIdx: Index of a newly selected or an active rx-state-machine in the generated array FrTp_RxState[].
 *              PRE_FRTP_VALID_RX_SM_IDX rxSmIdx
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   TRUE with different rxSmIdx
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface
 * \trace       CREQ-109463
 **********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_RxSm_FrIfRxIndication(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  PduIdType FrIfRxPduId,
  uint8 rxSmIdx
);

/***********************************************************************************************************************
 FrTp_RxSm_TriggerTransmit()
 **********************************************************************************************************************/
/*!
 * \brief       Assembles rx-related TP-pdus during FrTp_TriggerTransmit()-calls.
 * \details     Checks the validity of the FrTp_TriggerTransmit()-call prior to the assembly.
 *              This function is not reentrant, because PduR_FrTpCopyTxData() is called here:
 *              PduR_FrTpCopyTxData() has to be called "one by one" in the correct temporal order --> no reentrance.
 * \param[in]   PduIdType FrIfTxPduId: TxPduId of a FlexRay-pdu of the FrIf
 *              PRE_FRTP_VALID_FRIF_TX_PDU_IDX FrIfTxPduId
 * \param[in]   PduInfoType FrTpTxPduInfoPtr 
 *              PRE_FRTP_VALID_PDU_INFO_TYPE FrTpTxPduInfoPtr
 *              N-PDU Information Structure which contains
 *              a) pointer to where the FrTp Tx N-PDU shall be copied to
 *              b) the length of the FrTp Tx N-PDU
 * \return      Std_ReturnType: E_OK: The request has been accepted
 *                              E_NOT_OK: The request has not been accepted, 
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_RxSm_TriggerTransmit(
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxPduInfoPtr,
  PduIdType FrIfTxPduId
);


#define FRTP_STOP_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* FRTP_RXSM_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_RsSm.h
 *********************************************************************************************************************/


