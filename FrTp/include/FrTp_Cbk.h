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
 *        \file     FrTp_Cbk.h
 *        \brief    Callback header file of the FrTp.
 *
 *        \details  Declares callback functions called from lower layers. Here the only lower layer is the FrIf.
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

#if !defined FRTP_CBK_H
#define FRTP_CBK_H
/* lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/* lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "FrTp_GlobCfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Component Version Information */
#define FRTP_CBK_MAJOR_VERSION                          (2u)
#define FRTP_CBK_MINOR_VERSION                          (4u)
#define FRTP_CBK_PATCH_VERSION                          (4u)
 
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
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/***********************************************************************************************************************
 * FrTp_RxIndication()
 **********************************************************************************************************************/
/*!
 * \brief       Indicates the reception of an FrTp-pdu at the FrIf.
 * \details     Processes the pdu in case the Pdu:
 *              a) belongs to a channel configured for this ECU
 *              b) has the correct target address (== local address of one of the connections configured for this ECU)
 *              Called by FrIf
 * \param[in]   PduIdType FrIfRxPduId: Zero-based FrIfRxPduId of a received FrTp-pdu from the FrIf
 * \param[in]   P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr: 
 * \param[in]   Pointer to struct of the payload of the pdu
 * \pre         FrTp has to be initialized by a call to FrTp_Init()
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface, DSGN-FrTpReception, DSGN-FrTpAddressFiltering
 **********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_RxIndication(
  PduIdType FrIfRxPduId,
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr
);

/***********************************************************************************************************************
 FrTp_TxConfirmation()
 **********************************************************************************************************************/
/*!
 * \brief       Indicates the actual transmission of a FrTp-pdu on the FlexRay-bus.
 * \details     Processes the tx-confirmation 
 *              coming from the FrIf in case the Pdu confirmed is:
 *              a) the only FrIf-Pdu of the FrTp-channel or 
 *              b) the last FrIf-Pdu of the FrTp-channel or
 *              c) the FC-Pdu of the FrTp-channel.
 *              Called by FrIf
 *              This function counts its calls in order to determine whether a burst of pdus was sent on FR-bus fully.
 * \param[in]   PduIdType FrIfTxPduId: Upper-layer PduId of the FrIf of a transmitted Pdu
 * \pre         FrTp has to be initialized by a call to FrTp_Init()
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface
 **********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_TxConfirmation(
  PduIdType FrIfTxPduId
);

 /***********************************************************************************************************************
 FrTp_TriggerTransmit()
 **********************************************************************************************************************/
/*!
 * \brief       Offers the asynchronous transmission of FrTp-pdus through the FrIf.
 * \details     This is done by 
 *              a) assembling the tx-pdu from these infos: TPCI and AddressInformation of the connection the FrTp-pdu.
 *              b) copying tx-data "just in time" from the upper layers in order to have no FrTp-internal payload-buffers.
 *              Called by FrIf
 * \param[in]   PduIdType FrTxPduId: TxPduId of a FlexRay-pdu of the FrIf
 * \param[in]   PduInfoType FrTpTxPduInfoPtr 
 *              N-PDU Information Structure which contains
 *              a) pointer to where the FrTp Tx N-PDU shall be copied to
 *              b) the length of the FrTp Tx N-PDU
 *              uint8 *FrSduPtr: Location to copy the complete, assembled pdu to
 * \param[out]  Std_ReturnType: E_OK: The request has been accepted
 *                              E_NOT_OK: The request has not been accepted,
 *                                        e. g. parameter check has failed or cancellation is requested.
 * \pre         FrTp has to be initialized by a call to FrTp_Init()
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpGenericFrIfInterface
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_TriggerTransmit(
  PduIdType FrIfTxPduId,
  P2VAR(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxPduInfoPtr
);

#define FRTP_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#endif  /* FRTP_CBK_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Cbk.h
 *********************************************************************************************************************/


