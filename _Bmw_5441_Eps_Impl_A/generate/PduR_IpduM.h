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
 *            Module: PduR
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_IpduM.h
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

#if !defined (PDUR_IPDUM_H)
# define PDUR_IPDUM_H

/* PRQA S 3451 EOF */ /* MD_PduR_3451 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Cfg.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* \trace SPEC-629 */

#define PDUR_START_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * PduR_IpduMRxIndication
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the IpduM to indicate the complete reception of a IpduM I-PDU.\n
 *           The PDU Router evaluates the IpduM I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 * \param    RxPduId           ID of the received IpduM I-PDU
 * \param    info        Payload information of the received I-PDU (pointer to data and data length)
 * \return   none
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_IpduMRxIndication calls for the same IpduMRxPduId.
 * \trace    DSGN-PduR_IF_Forwarding
 * \trace    SPEC-666, SPEC-674, SPEC-1096, SPEC-2020085
 * \note     The function is called by IpduM.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_IpduMRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

/**********************************************************************************************************************
 * PduR_IpduMTxConfirmation
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the IpduM to confirm the complete transmission of a IpduM I-PDU.\n
 *           The PDU Router evaluates the IpduM I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 * \param    TxPduId           ID of the transmitted IpduM I-PDU
 * \return   none
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_IpduMTxConfirmation calls for the same IpduMTxPduId.
 * \trace    DSGN-PduR_IF_Forwarding
 * \trace    SPEC-666, SPEC-38455, SPEC-38450
 * \note     The function is called by IpduM.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_IpduMTxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
 * PduR_IpduMTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the IpduM to request the IpduM TX I-PDU before transmission.\n
 *           The PDU Router evaluates the IpduM I-PDU handle and identifies the destination(s) of the PDU.
 *           The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 * \param          TxPduId       ID of the IpduM I-PDU that will be transmitted
 * \param[in,out]  info          Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                               data shall be copied, and the available buffer size in SduLengh.
 *                               On return, the service will indicate the length of the copied SDU
 *                               data in SduLength.
 * \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
 * \return         E_NOT_OK      No data has been copied, because
 *                               PduR is not initialized
 *                               or TxPduId is not valid
 *                               or PduInfoPtr is NULL_PTR
 *                               or SduDataPtr is NULL_PTR
 *                               or SduLength is too small.
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_IpduMTriggerTransmit calls for the same IpduMTxPduId.
 * \trace    DSGN-PduR_IF_Forwarding
 * \trace    SPEC-666, SPEC-1828
 * \note     The function is called by IpduM.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);







/**********************************************************************************************************************
 * PduR_IpduMTransmit
 *********************************************************************************************************************/
/*!
 * \brief    The function serves to request the transmission of an upper layer I-PDU.\n
 *           The PDU Router evaluates the IpduM I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to a lower IF module using the appropriate I-PDU handle of the destination layer.
 * \param    id                ID of the IpduM I-PDU to be transmitted
 * \param    info              Payload information of the I-PDU (pointer to data and data length)
 * \return   Std_ReturnType\n
 *           E_OK              The request was accepted by the PDU Router and by the destination layer.\n
 *           E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
 *                             or the IpduMTxPduId is not valid\n
 *                             or the IpduMTxPduId is not forwarded in this identity\n
 *                             or the info is not valid\n
 *                             or the request was not accepted by the destination layer.\n
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_IpduMTransmit calls for the same IpduMTxPduId.
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-679, SPEC-686, SPEC-1827, SPEC-1096, SPEC-2020085, SPEC-38411
 * \note     The function is called by IpduM.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);






#define PDUR_STOP_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif  /* PDUR_IPDUM_H */


/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/*  module specific MISRA deviations:
    MD_PduR_3451:   MISRA rule: 8.8
    Reason:         The global identifier has been declared in more than one file. the function declaration has to be in
                    the PduR_<Module>.h. Affected APIs are CancelReceive, CancelTransmit and ChangeParameter.
    Risk:           no risk.
    Prevention:     To avoid a duplicate declaration uns the BSW-Module "use-Tag" flag.
*/

/**********************************************************************************************************************
 * END OF FILE: PduR_IpduM.h
 *********************************************************************************************************************/

