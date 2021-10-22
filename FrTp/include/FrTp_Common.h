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
 *        \file   FrTp_Common.h
 *        \brief  Common header file of all sub-modules of the FrTp.
 *
 *      \details  Defines internal constants of all sub-modules of the FrTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK in file Tp_Iso10681.c
 *********************************************************************************************************************/

#if !defined FRTP_COMMON_H
#define FRTP_COMMON_H

/* lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/* lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "FrTp_Types.h"
#include "SchM_FrTp.h"

#include "FrTp_XCfg.h"
#include "FrTp_RxSm.h"
#include "FrTp_TxSm.h"
#include "FrTp_Rsrc.h"
#include "FrTp_FrIf.h"
#include "FrTp_Util.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FRTP_COMMON_SW_MAJOR_VERSION                   (2u)
# define FRTP_COMMON_SW_MINOR_VERSION                   (4u)
# define FRTP_COMMON_SW_PATCH_VERSION                   (4u)

/* ----- API service IDs ----- */

/* ----- Error codes ----- */

/* ----- Modes ----- */

/* ----- Component specific stuff ----- */
/*!< PCI definitions according to ISO 10681-2 */
#define FrTp_FCCTS       ((uint8)(0x03u)) /*!< PCI-Nibble meaning "clear to send". */
#define FrTp_FCWT        ((uint8)(0x05u)) /*!< PCI-Nibble meaning "wait". */
#define FrTp_FCABT       ((uint8)(0x06u)) /*!< PCI-Nibble meaning "abort". */
#define FrTp_FCOVER      ((uint8)(0x07u)) /*!< PCI-Nibble meaning "overflow". */

#define FrTp_PCISTF      ((uint8)(0x40u)) /*!< PCI-Byte meaning "Start Frame". */
#define FrTp_PCISTFunseg ((uint8)(0x41u)) /*!< FrTp-internal PCI-Byte meaning "Unsegmented Start Frame". */
#define FrTp_PCISTFseg   ((uint8)(0x42u)) /*!< FrTp-internal PCI-Byte meaning "Segmented Start Frame". */
#define FrTp_PCICF1      ((uint8)(0x50u)) /*!< PCI-Byte meaning "Consecutive Frame 1". */
#define FrTp_PCICF2      ((uint8)(0x60u)) /*!< PCI-Byte meaning "Consecutive Frame 2". */
#define FrTp_PCICFEOB    ((uint8)(0x70u)) /*!< PCI-Byte meaning "Consecutive Frame End Of Block". */
#define FrTp_PCIFC       ((uint8)(0x80u)) /*!< PCI-Byte meaning "Flow Control" (Frame). */
#define FrTp_PCILF       ((uint8)(0x90u)) /*!< PCI-Byte meaning "Last Frame". */
#define FrTp_PCIinvalid  ((uint8)(0xA0u)) /*!< FrTp-internal code for all invalid PCI-Bytes. */

#define FrTp_STFU        ((uint8)(0x00u)) /*!< PCI sub-type for STF Pdus starting unacknowledged transfers. */
#define FrTp_STFA        ((uint8)(0x01u)) /*!< PCI sub-type for STF Pdus starting acknowledged transfers. */

#define FrTp_DropOut       (-1) /*!< Indicator of the helper functions called in the context of FrTp_MainFunction() to indicate: Nothing else to do in this main function call. */
#define FrTp_StayIn        (0) /*!< Indicator of the helper functions called in the context of FrTp_MainFunction() to indicate: Still sth. to do in this main function call. */

#define FrTp_MNPCDefault   ((uint8)0x00u) /*!< Default-value to be used to initialize the MNPC-field of each tx-state-machine. */

#define FrTp_IterationsPerPdu (2u) /*!< Number of iterations required in the FrTp_MainFunction() in order to distribute all tx-pdus to all rx- and tx-state-machines. */

#define FrTp_NoSm        ((uint8)0xFFu) /*!< Magic number for "Connection is not active in any state-machine". */
#define FrTp_NoPool      ((uint8)0xFFu) /*!< Magic number for "No pool is configured for this connection". */
#define FrTp_NoPdu       ((uint8)0xFFu) /*!< Magic number for "No free pdu is available for the affected pdu-pool" (Tx). */

/*!< States of the Tx-state-machine */
#define FrTp_TxSm_Idle                          ((uint8)0x00u) /*!< Tx-statemachine is in state "Idle". */
#define FrTp_TxSm_WaitFC                        ((uint8)0x01u) /*!< Tx-statemachine is in state of waiting for the receiver to send a FC Pdu. */
#define FrTp_TxSm_WaitForDataSTF                ((uint8)0x03u) /*!< Tx-statemachine is in state of waiting for the PduR to provide tx-data to assemble a STF-Pdu in a segmented or unsegmented connection. */
#define FrTp_TxSm_WaitForDataCF                 ((uint8)0x04u) /*!< Tx-statemachine is in state of waiting for the PduR to provide tx-data to assemble a CF[_EOB] or LF-Pdu in a segmented connection. */
#define FrTp_TxSm_WaitForTxnNonBurstSTFunseg    ((uint8)0x06u) /*!< Tx-statemachine is in state of waiting for the transmission of an STF Pdu in an unsegmented connection, after tx-data was received from PduR. */
#define FrTp_TxSm_WaitForTxnNonBurstSTFseg      ((uint8)0x07u) /*!< Tx-statemachine is in state of waiting for the transmission of an STF Pdu in a segmented connection, after tx-data was received from PduR. */
#define FrTp_TxSm_WaitForTxConfNonBurstSTFunseg ((uint8)0x09u) /*!< Tx-statemachine is in state of waiting for the tx-confirmation of an STF Pdu in an unsegmented connection. */
#define FrTp_TxSm_WaitForTxConfNonBurstSTFseg   ((uint8)0x0Au) /*!< Tx-statemachine is in state of waiting for the tx-confirmation of an STF Pdu in a segmented connection. */
#define FrTp_TxSm_WaitForTxConfBurstCF          ((uint8)0x0Bu) /*!< Tx-statemachine is in state of waiting for the tx-confirmation of a CF Pdu in a segmented connection. */
#define FrTp_TxSm_WaitForTxConfBurstCFIntrnl    ((uint8)0x0Cu) /*!< Tx-statemachine is in state of waiting for the FrTp-internal tx-confirmation of a CF Pdu when a burst of CF Pdus is sent in one (1) FrTp_MainFunction() call. */
#define FrTp_TxSm_WaitForEndOfBurstCF           ((uint8)0x0Du) /*!< Tx-statemachine is in state of waiting for the actuall tx-confirmation from the FrIf of the last CF Pdu of a burst of CF Pdus. */
#define FrTp_TxSm_WaitForBCexpiry               ((uint8)0x0Eu) /*!< Tx-statemachine is in state of waiting for the expiry of the time-span indicated by the receiver using the FC's BC-value. */

/*!< States of the Rx-state-machine */
#define FrTp_RxSm_Idle                      ((uint8)0x00u) /*!< Rx-statemachine is in state "Idle". */
#define FrTp_RxSm_WaitForSegmPdu            ((uint8)0x01u) /*!< Rx-statemachine is in state of waiting the next "segmented pdu" (The types CF1, CF_EOB and LF are "typical" for segmented transmissions). */
#define FrTp_RxSm_WaitForSTFsegmBuffer      ((uint8)0x02u) /*!< Rx-statemachine is in state of waiting copying rx-data to the PduR after reception of a STFsegm Pdu. */
#define FrTp_RxSm_WaitForSTFunsegmBuffer    ((uint8)0x03u) /*!< Rx-statemachine is in state of waiting copying rx-data to the PduR after reception of a STFunsegm Pdu. */
#define FrTp_RxSm_WaitForCFbuffer           ((uint8)0x04u) /*!< Rx-statemachine is in state of waiting copying rx-data to the PduR after reception of a CF Pdu. */
#define FrTp_RxSm_WaitForCF_EOBbuffer       ((uint8)0x05u) /*!< Rx-statemachine is in state of waiting copying rx-data to the PduR after reception of a CF_EOB Pdu. */
#define FrTp_RxSm_WaitForLFbuffer           ((uint8)0x06u) /*!< Rx-statemachine is in state of waiting copying rx-data to the PduR after reception of a LF Pdu. */
#define FrTp_RxSm_WaitForNxtFC_WT           ((uint8)0x07u) /*!< Rx-statemachine is in state of waiting asking for a non-zero amoung of free rx-buffer to be able to sent a valid FC.CTS Pdu. */
#define FrTp_RxSm_WaitForTxnNonBurstFC_CTS  ((uint8)0x08u) /*!< Rx-statemachine is in state of waiting for the transmission of an FC.CTS Pdu in a segmented reception. */
#define FrTp_RxSm_WaitForTxnNonBurstFC_WT   ((uint8)0x09u) /*!< Rx-statemachine is in state of waiting for the transmission of an FC.WT Pdu in a segmented reception. */
#define FrTp_RxSm_WaitForTxnNonBurstFC_ABT  ((uint8)0x0Au) /*!< Rx-statemachine is in state of waiting for the transmission of an FC.ABT Pdu in a segmented reception. */
#define FrTp_RxSm_WaitForTxnNonBurstFC_OVER ((uint8)0x0Bu) /*!< Rx-statemachine is in state of waiting for the transmission of an FC.OVER Pdu in a segmented reception. */
#define FrTp_RxSm_WaitForTxConfFC_CTS       ((uint8)0x0Cu) /*!< Rx-statemachine is in state of waiting for the tx-confirmation of an FC.CTS Pdu in a segmented reception. */
#define FrTp_RxSm_WaitForTxConfFC_WT        ((uint8)0x0Du) /*!< Rx-statemachine is in state of waiting for the tx-confirmation of an FC.WT Pdu in a segmented reception. */
#define FrTp_RxSm_WaitForTxConfFC_ABT       ((uint8)0x0Eu) /*!< Rx-statemachine is in state of waiting for the tx-confirmation of an FC.ABT Pdu in a segmented reception. */
#define FrTp_RxSm_WaitForTxConfFC_OVER      ((uint8)0x0Fu) /*!< Rx-statemachine is in state of waiting for the tx-confirmation of an FC.OVER Pdu in a segmented reception. */

/*!< Definitions for the FrTp-internal function that wraps the FrIf_Transmit()-API and that does the bandwidth administration */
typedef uint8 FrTp_TxReturnType;
/*!< Return values of the FrTp-internal function that wraps the FrIf_Transmit()-API: */
#define FrTp_TxOkContinue         ((uint8)0u) /*!< Further Tx-Pdus are available in the affected pool AND may be sent according to the current ISO 10681-2 Pdu type. */
#define FrTp_TxOkStop             ((uint8)1u) /*!< NO further Tx-Pdus are available in the affected pool AND may be sent according to the current ISO 10681-2 Pdu type. */
#define FrTp_TxNotOk              ((uint8)2u) /*!< FrIf_Transmit() has returned E_NOT_OK or another FrTp-internal error has occurred and the transfer has to be stopped. */

/*!< SN-Administration */
#define FrTp_SNMask        ((uint8)(0x0Fu)) /*!< Mask to parse the SN from a FrTp Pdu. */
#define FrTp_SNMax         ((uint8)(0x10u)) /*!< Value used to do the wrap around of the SN field during a segmented transfer of a FrTp message. */
#define FrTp_SNVeryFirstCF ((uint8)(0x01u)) /*!< Value used to assemble the expected SN field of a rx-state-machine. */
#define FrTp_SNInitial     ((uint8)(0x00u)) /*!< Value used to initialize the current SN field of a tx-state-machine. */

/*!< Legacy: Internal error tracking using equivalents to former NotifResultType */
#define FrTp_NoResultNotification ((Std_ReturnType)(E_NOT_OK + 1u)) /*!< FrTp-internal return code to initialize a rx- or tx-state-machine without informing the PduR. */

/*!< Frame-type-assembly */
#define FrTp_PduTypeMask       ((uint8)(0xf0u)) /*!< Mask to parse the Pdu type from a FrTp Pdu. */
#define FrTp_PduSubTypeMask    ((uint8)(0x0fu)) /*!< Mask to parse the Pdu subtype from a FrTp Pdu. */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define FrTp_EnterCritical()  SchM_Enter_FrTp_FRTP_EXCLUSIVE_AREA_0() /*!< This macro is used to request access to the Rx- & Tx-StateMachines (SM) of the FrTp: */
#define FrTp_LeaveCritical()  SchM_Exit_FrTp_FRTP_EXCLUSIVE_AREA_0() /*!< This macro is used to release access to the Rx- & Tx-StateMachines (SM) of the FrTp: */ 

/*!< Helper constants for FrTp-pdus' */

/*!< Length values of PCI ytes of Flow Control Pdus */
#define FrTp_TPCILengthFCWT      ((uint8)(1u)) /*!< Length of the PCI bytes of a Flow Control Wait Pdu. */
#define FrTp_TPCILengthFCABT     ((uint8)(1u)) /*!< Length of the PCI bytes of a Flow Control Abort Pdu. */
#define FrTp_TPCILengthFCOVER    ((uint8)(1u)) /*!< Length of the PCI bytes of a Flow Control Overflow Pdu. */
#define FrTp_TPCILengthFCCTS     ((uint8)(4u)) /*!< Length of the PCI bytes of a Flow Control Clear to send. */

/*!< Mask, offset and shift-values, used to calculate the format offset of a FrTp Pdus payload from the PCI-byte in that FrTp Pdu. */
#define FrTp_PCI2OffsetMask   0xf0 /*!< Mask-value used to easily get from the PCI-byte-code to the offset of the payload in a FrTp-Pdu with that PCI-byte (refer to the usage of this value for more details). */
#define FrTp_PCI2OffsetOffset 0x04 /*!< Offset-value used to easily get from the PCI-byte-code to the offset of the payload in a FrTp-Pdu with that PCI-byte (refer to the usage of this value for more details). */
#define FrTp_PCI2OffsetRShift 0x04 /*!< Shift-value used to easily get from the PCI-byte-code to the offset of the payload in a FrTp-Pdu with that PCI-byte (refer to the usage of this value for more details). */

/**********************************************************************************************************************
  FrTp_GetFmtOffsetFromPci()
**********************************************************************************************************************/
/*!
 * fn           FrTp_GetFmtOffsetFromPci(pci)
 * \brief       Calculates the offset in bytes where the payload starts for a given ISO10681-2 PCI-byte.
 * \details     The calculation is done by masking and shifting the PCI-byte value. Therefor the constants
 *              FrTp_PCI2OffsetMask, FrTp_PCI2OffsetRShift and FrTp_PCI2OffsetOffset are used.
 *              Thus the array FrTp_FmtOffset[] has to carefully fit to the calculation conducted by this macro!!!
 * \param[in]   uint8 PCI-byte of a FrTp Pdu
 * \return      Offset in bytes where the payload starts for a given ISO10681-2 PCI-byte.
 * \pre         The value of the given parameter PCI-byte has to be valid according to ISO10681-2.
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception, DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_GetFmtOffsetFromPci(pci) (FrTp_FmtOffset[(((pci) & FrTp_PCI2OffsetMask) >> FrTp_PCI2OffsetRShift) - FrTp_PCI2OffsetOffset]) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
  FrTp_CalcPduPayloadLen()
**********************************************************************************************************************/
/*!
 * fn           FrTp_CalcPduPayloadLen(pduBaseLen, pci)
 * \brief       Calculates the payload a FrTp pdu is able to transport.
 * \details     The calculation is done based on the overall length of the Pdu and the ISO10681-2 PCI-byte.
 * \param[in]   uint8 overall length of the FrTp Pdu (configured at FrIf).
 * \param[in]   uint8 PCI-byte of a FrTp Pdu
 * \return      Payload a FrTp pdu is able to transport according to the given ISO10681-2 PCI-byte.
 * \pre         The value of the given parameter PCI-byte has to be valid according to ISO10681-2.
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception, DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_CalcPduPayloadLen(pduBaseLen, pci) ((uint8)(   (pduBaseLen)\
                                                          - (FrTp_Util_OffsetTPCI)\
                                                          - FrTp_GetFmtOffsetFromPci(pci))) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
  FrTp_RxGetPduPayloadLen()
**********************************************************************************************************************/
/*!
 * fn           FrTp_RxGetPduPayloadLen(idx, pci)
 * \brief       Calculates the payload a particular FrTp-RX pdu is able to transport.
 * \details     The calculation is done based on the global index in the overall temporally sorted list of all RX-Pdus,
 *              and on the ISO10681-2 PCI-byte.
 * \param[in]   uint8 Global index in the overall temporally sorted list of all RX-Pdus.
 * \param[in]   uint8 PCI-byte of a FrTp Pdu.
 * \return      Payload a FrTp pdu is able to transport according to the given ISO10681-2 PCI-byte.
 * \pre         The value of the given parameter PCI-byte has to be valid according to ISO10681-2.
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpReception
 *********************************************************************************************************************/
#define FrTp_RxGetPduPayloadLen(idx, pci) ((uint8)(FrTp_CalcPduPayloadLen(FrTp_CCfg_FrIfRxPdus(idx)-> Length, (pci)))) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
  FrTp_TxGetPduPayloadLen()
**********************************************************************************************************************/
/*!
 * fn           FrTp_TxGetPduPayloadLen(idx, pci)
 * \brief       Calculates the payload a particular FrTp-TX pdu is able to transport.
 * \details     The calculation is done based on the global index in the overall temporally sorted list of all TX-Pdus,
 *              and on the ISO10681-2 PCI-byte.
 * \param[in]   uint8 Global index in the overall temporally sorted list of all TX-Pdus.
 * \param[in]   uint8 PCI-byte of a FrTp Pdu.
 * \return      Payload a FrTp pdu is able to transport according to the given ISO10681-2 PCI-byte.
 * \pre         The value of the given parameter PCI-byte has to be valid according to ISO10681-2.
 * \context     TASK|ISR
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission
 *********************************************************************************************************************/
#define FrTp_TxGetPduPayloadLen(idx, pci) ((uint8)(FrTp_CalcPduPayloadLen(FrTp_CCfg_FrIfTxPdus(idx)->Length, (pci)))) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define FrTp_ConnGetRxPoolOffset(pConnCfg) ((pConnCfg)->RxPduPoolOffset) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define FrTp_ConnGetTxPoolOffset(pConnCfg) ((pConnCfg)->TxPduPoolOffset) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define FrTp_Min(val1, val2) (((val1) < (val2)) ? (val1) : (val2)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define FrTp_Max(val1, val2) (((val1) > (val2)) ? (val1) : (val2)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define FrTp_SeqNumSubtract(sn, value) ((uint8)((((uint8)(((sint8)(sn)) - ((sint8)((value) & FrTp_SNMask))) + ((sint8)FrTp_SNMax))) & FrTp_SNMask)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#define FrTp_GetConnCtrlItem(pConnCtrl, item) (pConnCtrl)->item /* PRQA S 3453, 3410 */ /* MD_MSR_19.7, MD_FrTp_3410 */

#define FrTp_RxSm_Item(statemachine, item)  (statemachine)->item /* PRQA S 3453, 3410 */ /* MD_MSR_19.7, MD_FrTp_3410 */
#define FrTp_TxSm_Item(statemachine, item)  (statemachine)->item /* PRQA S 3453, 3410 */ /* MD_MSR_19.7, MD_FrTp_3410 */

#define FrTp_RxSm_CalcRemainingBytes(pRxSm) (FrTp_RxSm_Item((pRxSm), DataLength) - FrTp_RxSm_Item((pRxSm), DataIndex)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define FrTp_TxSm_CalcRemainingBytes(pTxSm) (FrTp_TxSm_Item((pTxSm), DataLength) - FrTp_TxSm_Item((pTxSm), DataIndex)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*!< Constants for [rx|tx]-channels' state-machines */
#define FrTp_TimerMinimum  ((FrTp_ChanTimerType)1u)
#define FrTp_TimerInIdle   ((FrTp_ChanTimerType)0u)

/*!< ISO10681-2 specific constants */
#define FrTp_MaxTransferLenSegm  ((PduLengthType)65535u)

/*!< FrTp DET error IDs. */
#define FRTP_E_NO_ERROR             (0xffu) /*!< Initializer value to be used for local errorId variables. */
#define FRTP_E_NOT_INIT             (0x01u) /*!< The FrTp component has not been initialized by a call to FrTp_Init(). */
#define FRTP_E_NULL_PTR             (0x02u) /*!< A NULL_PTR has been passed as a parameter to the current FrTp API where no NULL_PTR was allowed. */
#define FRTP_E_INVALID_PDU_SDU_ID   (0x03u) /*!< An invalid Pdu or Sdu ID has been passed as a parameter to the current FrTp API where only valid IDs were allowed. */
#define FRTP_E_INVALID_PARAMETER    (0x04u) /*!< OBSOLETE - STILL THERE FOR COMPATIBILITY REASONS - An invalid value has been passed as parameter to the current FrTp API where only valid values were allowed. */
#define FRTP_WRONG_PARAM_VAL        (0x04u) /*!< An invalid value has been passed as parameter to the current FrTp API where only valid values were allowed. */
#define FRTP_E_SEG_ERROR            (0x05u) /*!< A segmented FrTp message transfer was requested by a call to FrTp_Transmit() for a FrTpConnection that has the FrTpMultipleReceiver flag set to '1'. */
#define FRTP_E_UMSG_LENGTH_ERROR    (0x06u) /*!< A FrTp message transfer was requested by a call to FrTp_Transmit() with "Unknown Message Length", which is not supported by the FrTp. */
#define FRTP_E_NO_CHANNEL           (0x07u) /*!< A FrTp message transfer is about to start, but no free rx- or tx-state-machine has been found. */

#define FRTP_INSTANCE_ID_DET        (0u) /*!< Instance ID of the FrTp. */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* FRTP_COMMON_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_Common.h
 *********************************************************************************************************************/


