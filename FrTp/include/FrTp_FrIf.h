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
 *        \file   FrTp_FrIf.h
 *        \brief  Header file of the FrTp sub-module FrIf.
 *
 *      \details  Declares those functions of the sub-module FrIf that are called by other modules of the FrTp.
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

#if !defined (FRTP_FRIF_H)
# define FRTP_FRIF_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Compiler.h"
# include "FrTp_Cfg.h"
# include "FrTp_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FRTP_FRIF_SW_MAJOR_VERSION                     (2u)
# define FRTP_FRIF_SW_MINOR_VERSION                     (4u)
# define FRTP_FRIF_SW_PATCH_VERSION                     (4u)
/* ----- API service IDs ----- */

/* ----- Error codes ----- */

/* ----- Modes ----- */

/* ----- Component specific stuff ----- */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 FUNCTION_LIKE_MACROS */ /* MD_MSR_19.7 */
/*!< Query for which state-machine a tx-confirmation is expected for a FrIf-tx-pdu with given index pduIdx independent of direction [Rx|Tx] */
#define FrTp_FrIf_GetSmIdxOfExpectedTxConfOfTxPdu(pduIdx) \
  (uint8)(FrTp_FrIf_IsTxConfExpectedForRxSmUsingTxPdu(pduIdx)?(*FrTp_VCfg_RxFrIfPending((pduIdx))):\
         (FrTp_FrIf_IsTxConfExpectedForTxSmUsingTxPdu(pduIdx)?(*FrTp_VCfg_TxFrIfPending((pduIdx))):FrTp_NoSm))
/*!< Query which rx-state-machine expects a tx-confirmation for a FrIf-tx-pdu to be used when it is clear that a rx-state-machines uses the affected tx-pdu */
#define FrTp_FrIf_GetRxSmIdxOfExpectedTxConfOfTxPdu(pduIdx) (*FrTp_VCfg_RxFrIfPending((pduIdx)))
/*!< Query which tx-state-machine expects a tx-confirmation for a FrIf-tx-pdu to be used when it is clear that a tx-state-machines uses the affected tx-pdu */
#define FrTp_FrIf_GetTxSmIdxOfExpectedTxConfOfTxPdu(pduIdx) (*FrTp_VCfg_TxFrIfPending((pduIdx)))
/*!< Query whether tx-confirmation is expected for a FrIf-tx-pdu with given index pduIdx depending on the direction [Rx|Tx] */
#define FrTp_FrIf_IsTxConfExpectedForRxSmUsingTxPdu(pduIdx)     (FrTp_NoSm!=(uint8)(*FrTp_VCfg_RxFrIfPending((pduIdx))))
#define FrTp_FrIf_IsTxConfExpectedForTxSmUsingTxPdu(pduIdx)     (FrTp_NoSm!=(uint8)(*FrTp_VCfg_TxFrIfPending((pduIdx))))
/*!< Set the flag to indicate that a tx-confirmation is expected for a FrIf-tx-pdu with given pduIdx */
#define FrTp_FrIf_ExpectTxConfForTxPduOfRxSm(pduIdx, smIdx) (*FrTp_VCfg_RxFrIfPending((pduIdx))=(smIdx))
#define FrTp_FrIf_ExpectTxConfForTxPduOfTxSm(pduIdx, smIdx) (*FrTp_VCfg_TxFrIfPending((pduIdx))=(smIdx))
/*!< Reset the flag to indicated that a tx-confirmation has come in for a FrIf-tx-pdu with given pduIdx */
#define FrTp_FrIf_TxConfirmationForRxSmUsingTxPdu(pduIdx)       (*FrTp_VCfg_RxFrIfPending((pduIdx))=FrTp_NoSm)
#define FrTp_FrIf_TxConfirmationForTxSmUsingTxPdu(pduIdx)       (*FrTp_VCfg_TxFrIfPending((pduIdx))=FrTp_NoSm)
/*!< Query, whether tx-confirmation is expected for a FrIf-tx-pdu with given index pduIdx independent of direction [Rx|Tx] */
#define FrTp_FrIf_IsTxConfExpectedForPdu(pduIdx)       ( \
     FrTp_FrIf_IsTxConfExpectedForRxSmUsingTxPdu(pduIdx) \
  || FrTp_FrIf_IsTxConfExpectedForTxSmUsingTxPdu(pduIdx) \
)

/*!< Access to configuration of FrIf-Tx-Pdus used by FrTp */

/*!< TX-PDU-POOL-MACROS PART I */
#define FrTp_FrIf_GetTxPduPoolDataItemByPtr(pPoolDataUsed, item)  (pPoolDataUsed)->item /* PRQA S 3410 */ /* MD_FrTp_3410 */
#define FrTp_FrIf_GetTxPduPoolDataItem(poolIdx, item)             FrTp_VCfg_PoolData(poolIdx)->item /* PRQA S 3410 */ /* MD_FrTp_3410 */

/*!< TX-PDU-POOL-MACROS PART II */
#define FrTp_FrIf_IsDecoupPdu(pduInfo) (((pduInfo).DecoupPduAdminDataOffset) < (FrTp_CCfg_NumDecoupPdus()))

#define FrTp_FrIf_GetDecoupAdmin(pduInfo) (*FrTp_VCfg_DecoupPduAdminData(((pduInfo).DecoupPduAdminDataOffset)))
#define FrTp_FrIf_GetDecoupAdminById(frIfPduId) (FrTp_FrIf_GetDecoupAdmin(*(FrTp_CCfg_FrIfTxPdus(frIfPduId))))

#define FrTp_FrIf_GetTxPduPoolPtrByOffset(offset) (FrTp_CCfg_TxPduPools(offset))
#define FrTp_FrIf_GetTxPduPoolPtrByCheckedOffset(offset) (((offset) < (FrTp_CCfg_NumTxPools())) \
                                           ? (FrTp_CCfg_TxPduPools(offset)) \
                                           : ((P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST))NULL_PTR))

#define FrTp_FrIf_GetTxPduPoolDataPtrByOffset(offset) (FrTp_VCfg_PoolData(offset))
#define FrTp_FrIf_GetTxPduPoolDataPtrByCheckedOffset(offset) (((offset) < (FrTp_CCfg_NumTxPools())) \
                                               ? (FrTp_VCfg_PoolData(offset)) \
                                               : ((P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA))NULL_PTR))

/*!< Tx-pdu administration */
#define FrTp_FrIf_DirRx               0x01u
#define FrTp_FrIf_DirTx               0x02u

/* PRQA L:FUNCTION_LIKE_MACROS */ 

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
  FrTp_FrIf_RxIndication()
**********************************************************************************************************************/
/*!
 * \brief       Processes the RxIndication after the TP-connection has been found by FrTp_RxIndication.
 * \details     Determines whether the rx-indication is related to a rx- or tx-state-machine and forwards the call.
 *              The function is called by FrTp (FrTp_FrIf_RxIndication) itself on interrupt and task level.
 * \param[in]   P2CONST(uint8, AUTOMATIC, FRTP_APPL_DATA) dataPtr: Ptr to payload of pdu _past_ the address-bytes
 *              PRE_FRTP_VALID_PDU_INFO_TYPE FrIf_PduInfoPtr
 *              The members of that PduInfoType have to be initialized like this:
 *              SduLength: Has to contain the length of the complete FrTp-pdu received, which has to be in the range of 
 *                         [1..(MAX(of all values of member Length in generated array FrTp_FrIfRxPdus[]) - 1)].
 *              SduDataPtr: Has to point to an array of uint8 containing the complete FrTp-pdu received.
 * \param[in]   PduIdType FrIfRxPduId: Internal index of the FrTp-pdu received in generated array FrTp_FrIfRxPdus[]
 * \param[in]   uint8 tpConn: Internal index of the FrTp_Connection that is affected by the FrTp-pdu received.
 *              PRE_FRTP_VALID_CONN_IDX tpConn
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       CREQ-106180
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_FrIf_RxIndication(
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrIf_PduInfoPtr,
  PduIdType FrIfRxPduId,
  PduIdType tpConn
);

/**********************************************************************************************************************
  FrTp_FrIf_ProcessTxConfirmations()
**********************************************************************************************************************/
/*!
 * \brief       Updates the number of free tx-pdus in the tx-pdu-pools
 * \details     For all tx-pdu-pools configured the freeTxPdus-count is updated taking into account the fact that
 *              pools might be configured overlapping.
 *              To be called by FrTp_MainFunction() only inline (1 caller)
 * \pre         PRE_FRTP_INIT
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTxConfirmationHandling
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_FrIf_ProcessTxConfirmations(
  void
);

/**********************************************************************************************************************
  FrTp_FrIf_ResetTxPduPending()
**********************************************************************************************************************/
/*!
 * \brief       Initializes all FrIf-pending flags that are currently used by the given channel with index smIdx.
 * \details     Initializes all FrIf-pending flags that are currently used by the given channel with index smIdx.
 *              Whether an rx- or tx-statemachine is affected is given by parameter smDir.
 * \param[in]   uint8 smIdx: Index of the [rx|tx]-state-machine the FrIf-tx-pdus tx-pending-flags shall be reset for.
 *                           PRE_FRTP_VALID_ACTIVE_RX_SM_IDX smIdx in case smDir is FrTp_FrIf_DirRx.
 *                           PRE_FRTP_VALID_ACTIVE_TX_SM_IDX smIdx in case smDir is FrTp_FrIf_DirTx.
 *              uint8 smDir: 0x01u / FrTp_FrIf_DirRx: Reset Pending-Flags of the Rx-operation, only
 *                           0x02u / FrTp_FrIf_DirTx: Reset Pending-Flags of the Tx-operation, only
 *                           Parameter smDir has to have a value of range [FrTp_FrIf_DirRx|FrTp_FrIf_DirTx].
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpOverlappingPduPools, DSGN-FrTpTxConfirmationHandling, DSGN-FrTpGenericFrIfInterface
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_FrIf_ResetTxPduPending(
  uint8 smIdx,
  uint8 smDir
);

/**********************************************************************************************************************
  FrTp_FrIf_IncreaseNumTxConfOverlapped()
**********************************************************************************************************************/
/*!
 * \brief       Increases the 'received tx-confirmations'-counter of all pools that contain the given tx-pdu by '1'.
 * \details     The value of that counter is processed, once and centrally, in the FrTp_MainFunction()
 *              The function is called by FrTp itself on interrupt and task level.
 * \param[in]   uint8_least FrIfTxPduId
 *              PRE_FRTP_VALID_FRIF_TX_PDU_IDX FrIfTxPduId
 * \pre         The configuration tool has to assure that there are not more than 254 Pools (uint8 poolIdx is used)
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpOverlappingPduPools, DSGN-FrTpTxConfirmationHandling, DSGN-FrTpGenericFrIfInterface
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_FrIf_IncreaseNumTxConfOverlapped(
  uint8_least FrIfTxPduId
);

/**********************************************************************************************************************
  FrTp_FrIf_Init
**********************************************************************************************************************/
/*!
 * \brief       Initializes the admin data of the FrIf-tx-pdus and tx-pdu-pools used by FrTp.
 * \details     Initializes the the decoupled-pdu's and pools runtime-data of all FrIf-tx-pdus and tx-pdu-pools.
 * \pre         PRE_FRTP_SM_ACCESS
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-FrTpOverlappingPduPools, DSGN-FrTpTxConfirmationHandling
 *********************************************************************************************************************/
 extern FUNC(void, FRTP_CODE) FrTp_FrIf_Init(
  void
);

/**********************************************************************************************************************
  FrTp_FrIf_DecreaseNumFreePdusOverlapped()
**********************************************************************************************************************/
/*!
 * \brief       Decreases the number of free pdus in all tx-pdu-pools the given FrIf-tx-pdu is contained in.
 * \details     This is the one and only, central location where the action described above is done!
 *              In case of overlapping pools the TxConfirmations counter of each Pool containing the
 *              Tx Pdu has to be increased, too, in order to have the freeFrIfPdus counter incremented
 *              during the next execution of the FrTp_MainFunction().
 * \param[in]   P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu: Pointer to the FrIf-tx-pdu the action shall be conducted on.
 *                                                                             PRE_FRTP_VALID_FRIF_TX_PDU_PTR pFrIfTxPdu
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpOverlappingPduPools, DSGN-FrTpRoundRobin, DSGN-FrTpBurstMode, DSGN-FrTpGenericFrIfInterface
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_FrIf_DecreaseNumFreePdusOverlapped(
  P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu
);

/**********************************************************************************************************************
  FrTp_FrIf_FindFreeTxPdu
**********************************************************************************************************************/
/*!
 * \brief       Extracts the next free Tx-Pdu from the pool of the connection that is active in the given channel.
 * \details     The Pdu extracted is actually not(!) set "pending"! (as if FrIf_Transmit would have been called).
 *              No admin data is modified. I.e. the next call to this function will return the same Tx-Pdu.
 *              No decrementing while-loop is used, because THE SEARCH HAS TO GO FROM SMALL TO LARGER INDICES.
 *              The function is called by FrTp (FrTp_FrIf_RxIndication) itself on interrupt and task level.
 * \param[in]   pPoolCfg: Pointer to configuration data of a tx-pdu-pool a pdu shall be extracted from.
 *                        Pointer pPoolCfg has to point to a valid constant of type FrTp_TxPduPoolType which is a member of generated array FrTp_TxPduPools[].
 * \param[in]   pPoolData: Pointer to administration data of a tx-pdu-pool a pdu shall be extraced from
 *                         Pointer pPoolData has to point to a valid constant of type FrTp_TxPduPoolDataType which is a member of generated array FrTp_PoolData[].
 * \param[in]   uint8 poolLimit: Number of tx-pdus the given pool shall be limited to ==> A value of '0' means 'no limit'
 *                               PRE_FRTP_VALID_FRIF_TX_PDU_IDX poolLimit
 * \return      uint8: 0xff in case no Pdu has been found, otherwise the index of the tx-pdu reserved in the global tx-pdu-array of the FrTpIso
 * \pre         PRE_FRTP_SM_ACCESS
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpRoundRobin, DSGN-FrTpPduPools, DSGN-FrTpBandwidthLimitation, DSGN-FrTpGenericFrIfInterface
 *********************************************************************************************************************/
extern FUNC(uint8, FRTP_CODE) FrTp_FrIf_FindFreeTxPdu(
  CONSTP2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pPoolCfg,
  CONSTP2CONST(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_CONST) pPoolData,
  uint8 poolLimit
);

/**********************************************************************************************************************
  FrTp_FrIf_TransmitPduForConn
**********************************************************************************************************************/
/*!
 * \brief       Prepares and actually calls FrIf_Transmit depending on the tx-pdus transmission type.
 * \details     Prepares and actually calls FrIf_Transmit depending on whether the tx-pdus are either 'decoupled' or 
 *              'immediate'.
 * \param[in]   pConnCfg: Configuration of the connection that requires the FrIf_Transmit() call. 
 *                        PRE_FRTP_VALID_P_CONN_CFG pConnCfg
 * \param[in]   pFrIfTxPdu: Configuration of the tx-pdu that shall be transmitted
 *                          PRE_FRTP_VALID_FRIF_TX_PDU_PTR pFrIfTxPdu
 * \param[in]   pTPCI: Pointer to PduInfoType determining the first part of the content of the pdu, i.e. the PCI
 *                     PRE_FRTP_TPCI_PTR pTPCI
 *                     The members of that PduInfoType have to be initialized like this:
 *                     SduLength: PRE_FRTP_SDU_LENGTH_PCI_PDU_TO_BE_SENT
 *                     SduDataPtr: Has to point to an array of uint8 containing the PCI of the FrTp-pdu to be sent.
 * \param[in]   pPayload: Pointer to PduInfoType determining the second part of the content of the pdu, i.e. the payload
 *                        PRE_FRTP_PAYLOAD_PTR pPayload
 *                        The members of that PduInfoType have to be initialized like this:
 *                        SduLength:  Has to contain the length of the payload (of the FrTp-pdu to be sent) which has to be
 *                                    in the range of [0..(MAX(All members 'Length' of generated array FrTp_FrIfTxPdus[]) - 1)]
 *                        SduDataPtr: Has to point to an array of uint8 containing the payload of the FrTp-pdu to be sent or 
 *                                    NULL in case SduLength (above) has the value 0.
 * \return      Std_ReturnType: Return value of the call to FrIf_Transmit()
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpRoundRobin
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_FrIf_TransmitPduForConn(
  P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pConnCfg,
  P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pFrIfTxPdu,
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pTPCI, 
  P2CONST(PduInfoType, AUTOMATIC, FRTP_CONST) pPayload
);

#define FRTP_STOP_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* FRTP_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_FrIf.h
 *********************************************************************************************************************/

