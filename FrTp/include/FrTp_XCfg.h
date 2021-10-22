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
 *        \file   FrTp_XCfg.h
 *        \brief  Header file of the FrTp sub-module XCfg that offers transparent access to all L and PB Cfg-items.
 *
 *      \details  Declares and defines the functions of the sub-module XCfg, called by other modules of the FrTp.
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

#ifndef FrTp_XCfg_H
#define FrTp_XCfg_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FrTp_GlobCfg.h"
#include "FrTp_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Component Version Information */
#define FRTP_XCFG_MAJOR_VERSION                         (2u)
#define FRTP_XCFG_MINOR_VERSION                         (4u)
#define FRTP_XCFG_PATCH_VERSION                         (4u)
 
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

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  FrTp_CCfg_TxSduSnv2ConnIdx()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the constant configuration element FrTp_TxSduSnv2ConnIdx[] at index FrTpTxSduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_TxSduSnv2ConnIdx)[FrTpTxSduId]
 * \param[in]   PduIdType FrTpTxSduId: Symbolic name value of the FrTp-connection to be cancelled.
 *                                     PRE_FRTP_VALID_TX_SDU_ID
 * \return      P2CONST(PduIdType, AUTOMATIC, FRTP_CONST) pointer to FrTp_TxSduSnv2ConnIdx[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2CONST(PduIdType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_TxSduSnv2ConnIdx(PduIdType FrTpTxSduId);

/**********************************************************************************************************************
  FrTp_CCfg_RxSduSnv2ConnIdx()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the constant configuration element FrTp_RxSduSnv2ConnIdx[] at index FrTpRxSduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_RxSduSnv2ConnIdx)[FrTpRxSduId]
 * \param[in]   PduIdType FrTpRxSduId: Symbolic name value of the FrTp-connection to be cancelled
 *                                     PRE_FRTP_VALID_RX_SDU_ID
 * \return      P2CONST(PduIdType, AUTOMATIC, FRTP_CONST) pointer to FrTp_RxSduSnv2ConnIdx[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2CONST(PduIdType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_RxSduSnv2ConnIdx(PduIdType FrTpRxSduId);

/**********************************************************************************************************************
  FrTp_CCfg_ConnCfg()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the constant configuration element FrTp_ConnCfg[] at index FrTpTxSduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_ConnCfg)[FrTpTxSduId]
 * \param[in]   PduIdType FrTpTxSduId: Symbolic name value of the FrTp-connection to be cancelled.
 *                                     PRE_FRTP_VALID_TX_SDU_ID
 * \return      P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST) pointer to FrTp_ConnCfg[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_ConnCfg(PduIdType FrTpTxSduId);

/**********************************************************************************************************************
  FrTp_CCfg_NumTxPools()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the value of the constant configuration element FrTp_NumTxPools.
 * \details     Used to be: FrTp_CfgStruct(FrTp_NumTxPools).
 * \return      uint8 FrTp_NumTxPools 
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumTxPools(void);

/**********************************************************************************************************************
  FrTp_CCfg_FrIfRxPdus()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the constant configuration element FrTp_FrIfRxPdus[] at index .
 * \details     Used to be: FrTp_CfgStruct(FrTp_FrIfRxPdus)[(idx)].
 *              Access to configuration of FrIf-Rx-Pdus used by FrTp.
 * \param[in]   PduIdType FrIfRxPduId: Internal index of the FrTp-pdu received in the generated array FrTp_FrIfRxPdus[].
 *              PRE_FRTP_VALID_FRIF_RX_PDU_IDX FrIfRxPduId
 * \return      P2CONST(FrTp_RxPduInfoType, AUTOMATIC, FRTP_CONST) pointer to FrTp_FrIfRxPdus[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_RxPduInfoType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_FrIfRxPdus(PduIdType FrIfRxPduId);

/**********************************************************************************************************************
  FrTp_CCfg_FrIfTxPdus()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the constant configuration element FrTp_FrIfTxPdus[] at index FrTpTxPduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_FrIfTxPdus)
 * \param[in]   PduIdType FrIfTxPduId: TxPduId of a FlexRay-pdu of the FrIf
 *              PRE_FRTP_VALID_TX_PDU_ID_TRIG_TX
 * \return      P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST) pointer to FrTp_FrIfTxPdus[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_FrIfTxPdus(PduIdType FrTpTxPduId);

/**********************************************************************************************************************
  FrTp_CCfg_TxPduSnv2TxPduIdx()
**********************************************************************************************************************/
/*! 
 * \brief       FrTp_TxPduSnv2TxPduIdx[] at index 
 * \details     Used to be: FrTp_CfgStruct(FrTp_TxPduSnv2TxPduIdx)
 * \param[in]   PduIdType FrIfTxPduId: TxPduId of a FlexRay-pdu of the FrIf
 *              PRE_FRTP_VALID_TX_PDU_ID_TRIG_TX
 * \return      PduIdType FrTp_TxPduSnv2TxPduIdx[] 
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_TxPduSnv2TxPduIdx(PduIdType FrIfTxPduId);

/**********************************************************************************************************************
  FrTp_CCfg_RxPduSnv2RxPduIdx()
**********************************************************************************************************************/
/*! 
 * \brief       FrTp_RxPduSnv2RxPduIdx[] at index 
 * \details     Used to be: FrTp_CfgStruct(FrTp_RxPduSnv2RxPduIdx)
 * \param[in]   PduIdType FrIfRxPduId: Internal index of the FrTp-pdu received in the generated array FrTp_FrIfRxPdus[].
 *              PRE_FRTP_VALID_FRIF_RX_PDU_IDX FrIfRxPduId
 * \return      PduIdType FrTp_RxPduSnv2RxPduIdx[] 
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_RxPduSnv2RxPduIdx(PduIdType FrIfRxPduId);

/**********************************************************************************************************************
  FrTp_CCfg_TxPduPools()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the constant configuration element FrTp_TxPduPools[] at index 
 * \details     Used to be: FrTp_CfgStruct(FrTp_TxPduPools)
 * \return      P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST) pointer to FrTp_TxPduPools[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_TxPduPools(uint8 poolId);

/**********************************************************************************************************************
  FrTp_CCfg_NumConn()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_NumConn.
 * \details     Used to be: FrTp_CfgStruct(FrTp_NumConn)
 * \return      PduIdType FrTp_NumConn
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_NumConn(void);

/**********************************************************************************************************************
  FrTp_CCfg_NumDecoupPdus()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_NumDecoupPdus.
 * \details     Used to be: FrTp_CfgStruct(FrTp_NumDecoupPdus)
 * \return      uint8 FrTp_NumDecoupPdus
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumDecoupPdus(void);

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  FrTp_CCfg_MaxTxSduId()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_MaxTxSduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_MaxTxSduId)
 * \return      PduIdType: Max. value of all SNVs of all configured TxSdus.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_DEV_ERROR_DETECT == STD_ON
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxTxSduId(void);

/**********************************************************************************************************************
  FrTp_CCfg_MaxRxSduId()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_MaxRxSduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_MaxRxSduId)
 * \return      PduIdType: Max. value of all SNVs of all configured RxSdus.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_DEV_ERROR_DETECT == STD_ON
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxRxSduId(void);
#endif

/**********************************************************************************************************************
  FrTp_CCfg_NumRxChan()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_NumRxChan.
 * \details     Used to be: FrTp_CfgStruct(FrTp_NumRxChan)
 * \return      uint8 FrTp_NumRxChan
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumRxChan(void);

/**********************************************************************************************************************
  FrTp_CCfg_NumTxChan()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_NumTxChan.
 * \details     Used to be: FrTp_CfgStruct(FrTp_NumTxChan)
 * \return      uint8 FrTp_NumTxChan
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumTxChan(void);

/**********************************************************************************************************************
  FrTp_CCfg_NumFrIfTxPdus()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_NumFrIfTxPdus.
 * \details     Used to be: FrTp_CfgStruct(FrTp_NumFrIfTxPdus)
 * \return      uint8: Size of array FrTp_FrIfTxPdus[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumFrIfTxPdus(void);

/**********************************************************************************************************************
  FrTp_CCfg_NumFrIfRxPdus()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_NumFrIfRxPdus.
 * \details     Used to be: FrTp_CfgStruct(FrTp_NumFrIfRxPdus)
 * \return      uint8: Size of array FrTp_FrIfRxPdus[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumFrIfRxPdus(void);

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  FrTp_CCfg_MaxFrIfTxPduId()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_MaxFrIfTxPduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_MaxFrIfTxPduId)
 * \return      PduIdType FrTp_MaxFrIfTxPduId
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_DEV_ERROR_DETECT == STD_ON
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxFrIfTxPduId(void);

/**********************************************************************************************************************
  FrTp_CCfg_MaxFrIfRxPduId()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the constant configuration element FrTp_MaxFrIfRxPduId.
 * \details     Used to be: FrTp_CfgStruct(FrTp_MaxFrIfRxPduId)
 * \return      PduIdType FrTp_MaxFrIfRxPduId 
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_DEV_ERROR_DETECT == STD_ON
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxFrIfRxPduId(void);
#endif

/**********************************************************************************************************************
  FrTp_VCfg_ConnState()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_ConnState[] at index FrTpTxSduId.
 * \details     Used to be: FrTp_VarLData(FrTp_ConnState)
 * \param[in]   PduIdType FrTpTxSduId: Symbolic name value of the FrTp-connection to be cancelled.
 *                                     PRE_FRTP_VALID_TX_SDU_ID
 * \return      P2VAR(FrTp_ConnStateType, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_ConnState[] 
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_ConnStateType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_ConnState(PduIdType FrTpTxSduId);

/**********************************************************************************************************************
  FrTp_VCfg_TxState()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_TxState[] at index txSmIdx.
 * \details     Used to be: FrTp_VarLData(FrTp_TxState)[txSmIdx]
 * \param[in]   uint8 txSmIdx: Index of the tx-state-machine.
 *                             PRE_FRTP_VALID_TX_SM_IDX txSmIdx
 * \return      P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_TxState[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_TxState(uint8 txSmIdx);

/**********************************************************************************************************************
  FrTp_VCfg_RxFrIfPending()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_RxFrIfPending[] at index FrIfTxPdu.
 * \details     Used to be: FrTp_VarLData(FrTp_RxFrIfPending)
 * \param[in]   PduIdType FrIfTxPdu: Index of an tx-pdu in the overall (temporally sorted) array of tx-pdus.
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_RxFrIfPending[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_RxFrIfPending(PduIdType FrIfTxPdu);

/**********************************************************************************************************************
  FrTp_VCfg_TxFrIfPending()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_TxFrIfPending[] at index FrIfTxPdu.
 * \details     Used to be: FrTp_VarLData(FrTp_TxFrIfPending)
 * \param[in]   PduIdType FrIfTxPdu: Index of an tx-pdu in the overall (temporally sorted) array of tx-pdus.
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_TxFrIfPending[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_TxFrIfPending(PduIdType FrIfTxPdu);

/**********************************************************************************************************************
  FrTp_VCfg_FrIfTxBuf()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_FrIfTxBuf.
 * \details     Used to be: FrTp_VarLData(FrTp_FrIfTxBuf)
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_FrIfTxBuf
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_FrIfTxBuf(void);

/**********************************************************************************************************************
  FrTp_VCfg_PoolData()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_PoolData[] at index poolIdx.
 * \details     Used to be: FrTp_VarLData(FrTp_PoolData)
 * \return      P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_PoolData[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_PoolData(uint8 poolIdx);

/**********************************************************************************************************************
  FrTp_VCfg_DecoupPduAdminData()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_DecoupPduAdminData[] at index poolIdx.
 * \details     Used to be: FrTp_VarLData(FrTp_DecoupPduAdminData)
 * \return      P2VAR(FrTp_DecoupPduAdminType, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_DecoupPduAdminData[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_DecoupPduAdminType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_DecoupPduAdminData(uint8 poolIdx);

/**********************************************************************************************************************
  FrTp_VCfg_RxState()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_RxState[] at index rxSmIdx.
 * \details     Used to be: FrTp_VarLData(FrTp_RxState)
 * \param[in]   uint8 rxSmIdx: Index of a rx-state-machine.
 *              PRE_FRTP_VALID_RX_SM_IDX rxSmIdx
 * \return      P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_RxState[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_RxState(uint8 rxSmIdx);

/**********************************************************************************************************************
  FrTp_VCfg_RxBuf()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_RxBuf[] at index rxSmIdx.
 * \details     Used to be: FrTp_VarLData(FrTp_RxBuf)
 * \param[in]   uint8 rxSmIdx: Index of a rx-state-machine.
 *              PRE_FRTP_VALID_RX_SM_IDX rxSmIdx
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_RxBuf[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_RxBuf(uint8 rxSmIdx);

/**********************************************************************************************************************
  FrTp_VCfg_TxBuf()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_TxBuf[] at index txSmIdx.
 * \details     Used to be: FrTp_VarLData(FrTp_TxBuf)
 * \param[in]   uint8 txSmIdx: Index of the tx-state-machine.
 *                             PRE_FRTP_VALID_TX_SM_IDX txSmIdx
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_TxBuf[]
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_TxBuf(uint8 txSmIdx);

/**********************************************************************************************************************
  FrTp_LCfg_InitState()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_InitState.
 * \details     Used to be: FrTp_LData(FrTp_InitState)
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_InitState
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_InitState(void);

#if (FrTp_IsPostbuild())
/**********************************************************************************************************************
  FrTp_LCfg_CfgPtr()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_CfgPtr.
 * \details     Used to be: FrTp_CfgPtr
 * \return      P2VAR(FrTp_ConfigPtrType, AUTOMATIC, FRTP_INIT_DATA) pointer to FrTp_CfgPtr
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FrTp_IsPostbuild() == TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_ConfigPtrType, AUTOMATIC, FRTP_INIT_DATA), FRTP_CODE) FrTp_LCfg_CfgPtr(void);
#endif

/**********************************************************************************************************************
  FrTp_LCfg_RxCurrRoundRobChan()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_RxCurrRoundRobChan.
 * \details     Used to be: FrTp_LData(FrTp_RxCurrRoundRobChan)
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_RxCurrRoundRobChan
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_RxCurrRoundRobChan(void);

/**********************************************************************************************************************
  FrTp_LCfg_TxCurrRoundRobChan()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_TxCurrRoundRobChan.
 * \details     Used to be: FrTp_LData(FrTp_TxCurrRoundRobChan)
 * \return      P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_TxCurrRoundRobChan
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_TxCurrRoundRobChan(void);

/**********************************************************************************************************************
  FrTp_LCfg_RxSm_MaxIterations()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_RxSm_MaxIterations.
 * \details     Used to be: FrTp_LData(FrTp_RxSm_MaxIterations)
 * \return      P2VAR(uint16_least, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_RxSm_MaxIterations
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint16_least, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_RxSm_MaxIterations(void);

/**********************************************************************************************************************
  FrTp_LCfg_TxSm_MaxIterations()
**********************************************************************************************************************/
/*! 
 * \brief       Returns the pointer to the flexible RAM configuration element FrTp_TxSm_MaxIterations.
 * \details     Used to be: FrTp_LData(FrTp_TxSm_MaxIterations)
 * \return      P2VAR(uint16_least, AUTOMATIC, FRTP_APPL_DATA) pointer to FrTp_TxSm_MaxIterations
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpConfigurationAccess
 *********************************************************************************************************************/
FRTP_LOCAL_INLINE FUNC(P2VAR(uint16_least, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_TxSm_MaxIterations(void);

#define FRTP_STOP_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#ifndef FRTP_UNIT_TEST /* COV_FRTP_TESTSUITE_INSTRUMENTATION */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  FrTp_CCfg_TxSduSnv2ConnIdx()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2CONST(PduIdType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_TxSduSnv2ConnIdx(PduIdType FrTpTxSduId)
{
    /* #10 Given FrTp_IsPostbuild() Then return &((FrTp_CfgPtr->FrTp_TxSduSnv2ConnIdx)[FrTpTxSduId]) Else return &FrTp_TxSduSnv2ConnIdx[FrTpTxSduId] */
    #if (FrTp_IsPostbuild())
        return &((FrTp_CfgPtr->FrTp_TxSduSnv2ConnIdx)[FrTpTxSduId]);
    #else 
        return &FrTp_TxSduSnv2ConnIdx[FrTpTxSduId];
    #endif
} /* FrTp_CCfg_TxSduSnv2ConnIdx */

/**********************************************************************************************************************
  FrTp_CCfg_RxSduSnv2ConnIdx()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2CONST(PduIdType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_RxSduSnv2ConnIdx(PduIdType FrTpRxSduId)
{
    /* #10 Given FrTp_IsPostbuild() Then return &((FrTp_CfgPtr->FrTp_RxSduSnv2ConnIdx)[FrTpRxSduId]) Else return &(FrTp_RxSduSnv2ConnIdx[FrTpRxSduId]) */
    #if (FrTp_IsPostbuild())
        return &((FrTp_CfgPtr->FrTp_RxSduSnv2ConnIdx)[FrTpRxSduId]);
    #else 
        return &(FrTp_RxSduSnv2ConnIdx[FrTpRxSduId]);
    #endif
} /* FrTp_CCfg_RxSduSnv2ConnIdx */

/**********************************************************************************************************************
  FrTp_CCfg_ConnCfg()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_ConnCfgType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_ConnCfg(PduIdType FrTpTxSduId)
{
    /* #10 Given FrTp_IsPostbuild() Then return &((FrTp_CfgPtr->FrTp_ConnCfg)[FrTpTxSduId]) Else return &(FrTp_ConnCfg[FrTpTxSduId]) */
    #if (FrTp_IsPostbuild())
        return &((FrTp_CfgPtr->FrTp_ConnCfg)[FrTpTxSduId]);
    #else 
        return &(FrTp_ConnCfg[FrTpTxSduId]);
    #endif
} /* FrTp_CCfg_ConnCfg */

/**********************************************************************************************************************
  FrTp_CCfg_NumTxPools()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumTxPools(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return ((FrTp_CfgPtr->FrTp_NumTxPools)) Else return FrTp_NumTxPools */
    #if (FrTp_IsPostbuild())
        return ((FrTp_CfgPtr->FrTp_NumTxPools));
    #else 
        return FrTp_NumTxPools;
    #endif
} /* FrTp_CCfg_NumTxPools */

/**********************************************************************************************************************
  FrTp_CCfg_FrIfRxPdus()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_RxPduInfoType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_FrIfRxPdus(PduIdType FrIfRxPduId)
{
    /* #10 Given FrTp_IsPostbuild() Then return &((FrTp_CfgPtr->FrTp_FrIfRxPdus)[FrIfRxPduId]) Else return &FrTp_FrIfRxPdus[FrIfRxPduId] */
    #if (FrTp_IsPostbuild())
        return &((FrTp_CfgPtr->FrTp_FrIfRxPdus)[FrIfRxPduId]);
    #else
        return &FrTp_FrIfRxPdus[FrIfRxPduId];
    #endif
} /* FrTp_CCfg_FrIfRxPdus */

/**********************************************************************************************************************
  FrTp_CCfg_FrIfTxPdus()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_TxPduInfoType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_FrIfTxPdus(PduIdType FrTpTxPduId)
{
    /* #10 Given FrTp_IsPostbuild() Then return &((FrTp_CfgPtr->FrTp_FrIfTxPdus)[FrTpTxPduId]) Else return &FrTp_FrIfTxPdus[FrTpTxPduId] */
    #if (FrTp_IsPostbuild())
        return &((FrTp_CfgPtr->FrTp_FrIfTxPdus)[FrTpTxPduId]);
    #else 
        return &FrTp_FrIfTxPdus[FrTpTxPduId];
    #endif
} /* FrTp_CCfg_FrIfTxPdus */

/**********************************************************************************************************************
  FrTp_CCfg_TxPduSnv2TxPduIdx()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_TxPduSnv2TxPduIdx(PduIdType FrIfTxPduId)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_TxPduSnv2TxPduIdx)[FrIfTxPduId] Else return FrTp_TxPduSnv2TxPduIdx[FrIfTxPduId] */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_TxPduSnv2TxPduIdx)[FrIfTxPduId];
    #else 
        return FrTp_TxPduSnv2TxPduIdx[FrIfTxPduId];
    #endif
} /* FrTp_CCfg_TxPduSnv2TxPduIdx */

/**********************************************************************************************************************
  FrTp_CCfg_RxPduSnv2RxPduIdx()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_RxPduSnv2RxPduIdx(PduIdType FrIfRxPduId)
{
    /* #10 Given FrTp_IsPostbuild() Then return ((FrTp_CfgPtr->FrTp_RxPduSnv2RxPduIdx)[FrIfRxPduId]) Else return FrTp_RxPduSnv2RxPduIdx[FrIfRxPduId] */
    #if (FrTp_IsPostbuild())
        return ((FrTp_CfgPtr->FrTp_RxPduSnv2RxPduIdx)[FrIfRxPduId]);
    #else 
        return FrTp_RxPduSnv2RxPduIdx[FrIfRxPduId];
    #endif
} /* FrTp_CCfg_RxPduSnv2RxPduIdx */

/**********************************************************************************************************************
  FrTp_CCfg_TxPduPools()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2CONST(FrTp_TxPduPoolType, AUTOMATIC, FRTP_CONST), FRTP_CODE) FrTp_CCfg_TxPduPools(uint8 poolId)
{
    /* #10 Given FrTp_IsPostbuild() Then return &((FrTp_CfgPtr->FrTp_TxPduPools)[poolId]) Else return &FrTp_TxPduPools[poolId] */
    #if (FrTp_IsPostbuild())
        return &((FrTp_CfgPtr->FrTp_TxPduPools)[poolId]);
    #else 
        return &FrTp_TxPduPools[poolId];
    #endif
} /* FrTp_CCfg_TxPduPools */

/*!< CONSTANTS */

/**********************************************************************************************************************
  FrTp_CCfg_NumConn()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_NumConn(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_NumConn) Else return FrTp_NumConn */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_NumConn);
    #else
        return FrTp_NumConn;
    #endif
} /* FrTp_CCfg_NumConn */

/**********************************************************************************************************************
  FrTp_CCfg_NumDecoupPdus()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumDecoupPdus(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_NumDecoupPdus) Else return FrTp_NumDecoupPdus */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_NumDecoupPdus);
    #else
        return FrTp_NumDecoupPdus;
    #endif
} /* FrTp_CCfg_NumDecoupPdus */

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  FrTp_CCfg_MaxTxSduId()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxTxSduId(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_MaxTxSduId) Else return FrTp_MaxTxSduId */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_MaxTxSduId);
    #else
        return FrTp_MaxTxSduId;
    #endif
} /* FrTp_CCfg_MaxTxSduId */

/**********************************************************************************************************************
  FrTp_CCfg_MaxRxSduId()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxRxSduId(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_MaxRxSduId) Else return FrTp_MaxRxSduId */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_MaxRxSduId);
    #else
        return FrTp_MaxRxSduId;
    #endif
} /* FrTp_CCfg_MaxRxSduId */
#endif

/**********************************************************************************************************************
  FrTp_CCfg_NumRxChan()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumRxChan(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_NumRxChan) Else return FrTp_NumRxChan */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_NumRxChan);
    #else
        return FrTp_NumRxChan;
    #endif
} /* FrTp_CCfg_NumRxChan */

/**********************************************************************************************************************
  FrTp_CCfg_NumTxChan()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumTxChan(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_NumTxChan) Else return FrTp_NumTxChan */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_NumTxChan);
    #else
        return FrTp_NumTxChan;
    #endif
} /* FrTp_CCfg_NumTxChan */

/**********************************************************************************************************************
  FrTp_CCfg_NumFrIfTxPdus()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumFrIfTxPdus(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_NumFrIfTxPdus) Else return FrTp_NumFrIfTxPdus */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_NumFrIfTxPdus);
    #else
        return FrTp_NumFrIfTxPdus;
    #endif
} /* FrTp_CCfg_NumFrIfTxPdus */

/**********************************************************************************************************************
  FrTp_CCfg_NumFrIfRxPdus()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(uint8, FRTP_CODE) FrTp_CCfg_NumFrIfRxPdus(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_NumFrIfRxPdus) Else return FrTp_NumFrIfRxPdus */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_NumFrIfRxPdus);
    #else
        return FrTp_NumFrIfRxPdus;
    #endif
} /* FrTp_CCfg_NumFrIfRxPdus */

#if (FRTP_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  FrTp_CCfg_MaxFrIfRxPduId()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxFrIfRxPduId(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_MaxFrIfRxPduId) Else return FrTp_MaxFrIfRxPduId */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_MaxFrIfRxPduId);
    #else
        return FrTp_MaxFrIfRxPduId;
    #endif
} /* FrTp_CCfg_MaxFrIfRxPduId */

/**********************************************************************************************************************
  FrTp_CCfg_MaxFrIfTxPduId()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(PduIdType, FRTP_CODE) FrTp_CCfg_MaxFrIfTxPduId(void)
{
    /* #10 Given FrTp_IsPostbuild() Then return (FrTp_CfgPtr->FrTp_MaxFrIfTxPduId) Else return FrTp_MaxFrIfTxPduId */
    #if (FrTp_IsPostbuild())
        return (FrTp_CfgPtr->FrTp_MaxFrIfTxPduId);
    #else 
        return FrTp_MaxFrIfTxPduId;
    #endif
} /* FrTp_CCfg_MaxFrIfTxPduId */ 
#endif
/*!< End of the FrTp_CfgStruct Abstractions */

/*!< FrTp_VarLData Abstractions
Postbuild:
# define FrTp_VarLData(Item) FrTp_CfgStruct(Item##Ptr)
Not postbuild:
#define FrTp_VarLData(Item) (Item)
*/

/**********************************************************************************************************************
  FrTp_VCfg_ConnState()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_ConnStateType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_ConnState(PduIdType FrTpTxSduId)
{
    /* #10 Given configuration variant is postbuild Then return &(FrTp_CfgPtr->FrTp_ConnStatePtr[FrTpTxSduId]) Else return &(FrTp_ConnState[FrTpTxSduId]) */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return &(FrTp_CfgPtr->FrTp_ConnStatePtr[FrTpTxSduId]);
    #else
        return &(FrTp_ConnState[FrTpTxSduId]);
    #endif
} /* FrTp_VCfg_ConnState */

/**********************************************************************************************************************
  FrTp_VCfg_TxState()
**********************************************************************************************************************/

/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_TxStateType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_TxState(uint8 txSmIdx)
{
    /* #10 Given configuration variant is postbuild Then  Else  */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return &(FrTp_CfgPtr->FrTp_TxStatePtr[txSmIdx]);
    #else
        return &(FrTp_TxState[txSmIdx]);
    #endif
} /* FrTp_VCfg_TxState */

/**********************************************************************************************************************
  FrTp_VCfg_RxFrIfPending()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_RxFrIfPending(PduIdType FrIfTxPdu)
{
    /* #10 Given configuration variant is postbuild Then return &(FrTp_CfgPtr->FrTp_RxFrIfPendingPtr[FrIfTxPdu]) Else return &(FrTp_RxFrIfPending[FrIfTxPdu]) */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return &(FrTp_CfgPtr->FrTp_RxFrIfPendingPtr[FrIfTxPdu]);
    #else
        return &(FrTp_RxFrIfPending[FrIfTxPdu]);
    #endif
} /* FrTp_VCfg_RxFrIfPending */

/**********************************************************************************************************************
  FrTp_VCfg_TxFrIfPending()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_TxFrIfPending(PduIdType FrIfTxPdu)
{
    /* #10 Given configuration variant is postbuild Then return &(FrTp_CfgPtr->FrTp_TxFrIfPendingPtr[FrIfTxPdu]) Else return &(FrTp_TxFrIfPending[FrIfTxPdu]) */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return &(FrTp_CfgPtr->FrTp_TxFrIfPendingPtr[FrIfTxPdu]);
    #else
        return &(FrTp_TxFrIfPending[FrIfTxPdu]);
    #endif
} /* FrTp_VCfg_TxFrIfPending */

/**********************************************************************************************************************
  FrTp_VCfg_FrIfTxBuf()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_FrIfTxBuf(void)
{
    /* #10 Given configuration variant is postbuild Then return (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))(FrTp_CfgPtr->FrTp_FrIfTxBufPtr) Else return (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))(FrTp_FrIfTxBuf) */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))(FrTp_CfgPtr->FrTp_FrIfTxBufPtr); /* PRQA S 0310 */ /* MD_FrTp_0310 */
    #else
        return (P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA))(FrTp_FrIfTxBuf); /* PRQA S 0310 */ /* MD_FrTp_0310 */
    #endif
} /* FrTp_VCfg_FrIfTxBuf */

/**********************************************************************************************************************
  FrTp_VCfg_PoolData()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_TxPduPoolDataType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_PoolData(uint8 poolIdx)
{
    /* #10 Given configuration variant is postbuild Then return &(FrTp_CfgPtr->FrTp_PoolDataPtr[poolIdx]) Else return &(FrTp_PoolData[poolIdx]) */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return &(FrTp_CfgPtr->FrTp_PoolDataPtr[poolIdx]);
    #else
        return &(FrTp_PoolData[poolIdx]);
    #endif
} /* FrTp_VCfg_PoolData */

/**********************************************************************************************************************
  FrTp_VCfg_DecoupPduAdminData()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_DecoupPduAdminType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_DecoupPduAdminData(uint8 poolIdx)
{
    /* #10 Given configuration variant is postbuild Then return &(FrTp_CfgPtr->FrTp_DecoupPduAdminDataPtr[poolIdx]) Else return &(FrTp_DecoupPduAdminData[poolIdx]) */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return &(FrTp_CfgPtr->FrTp_DecoupPduAdminDataPtr[poolIdx]);
    #else
        return &(FrTp_DecoupPduAdminData[poolIdx]);
    #endif
} /* FrTp_VCfg_DecoupPduAdminData */

/**********************************************************************************************************************
  FrTp_VCfg_RxState()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_RxStateType, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_RxState(uint8 rxSmIdx)
{
    /* #10 Given configuration variant is postbuild Then return &(FrTp_CfgPtr->FrTp_RxStatePtr[rxSmIdx]) Else return &(FrTp_RxState[rxSmIdx]) */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return &(FrTp_CfgPtr->FrTp_RxStatePtr[rxSmIdx]);
    #else
        return &(FrTp_RxState[rxSmIdx]);
    #endif
} /* FrTp_VCfg_RxState */

/**********************************************************************************************************************
  FrTp_VCfg_RxBuf()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_RxBuf(uint8 rxSmIdx)
{
    /* #10 Given configuration variant is postbuild Then return FrTp_CfgPtr->FrTp_RxBufPtr[rxSmIdx] Else return FrTp_RxBuf[rxSmIdx] */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return FrTp_CfgPtr->FrTp_RxBufPtr[rxSmIdx];
    #else
        return FrTp_RxBuf[rxSmIdx];
    #endif
} /* FrTp_VCfg_RxBuf */

/**********************************************************************************************************************
  FrTp_VCfg_TxBuf()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_VCfg_TxBuf(uint8 txSmIdx)
{
    /* #10 Given configuration variant is postbuild Then return FrTp_CfgPtr->FrTp_TxBufPtr[txSmIdx] Else return FrTp_TxBuf[txSmIdx] */
    #if (FRTP_CONFIGURATION_VARIANT == 3)
        return FrTp_CfgPtr->FrTp_TxBufPtr[txSmIdx];
    #else
        return FrTp_TxBuf[txSmIdx];
    #endif
} /* FrTp_VCfg_TxBuf */

/*!< End of FrTp_VarLData Abstractions */

/**********************************************************************************************************************
  FrTp_LCfg_InitState()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_InitState(void)
{
    /* #10 return &FrTp_InitState */
    return &FrTp_InitState;
} /* FrTp_LCfg_InitState */

/**********************************************************************************************************************
  FrTp_LCfg_CfgPtr()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
#if (FrTp_IsPostbuild())
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(FrTp_ConfigPtrType, AUTOMATIC, FRTP_INIT_DATA), FRTP_CODE) FrTp_LCfg_CfgPtr(void)
{
    /* #10 return &FrTp_CfgPtr */
    return &FrTp_CfgPtr;
} /* FrTp_LCfg_CfgPtr */
#endif

/**********************************************************************************************************************
  FrTp_LCfg_RxCurrRoundRobChan()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_RxCurrRoundRobChan(void)
{
    /* #10 return &FrTp_RxCurrRoundRobChan */
    return &FrTp_RxCurrRoundRobChan;
} /* FrTp_LCfg_RxCurrRoundRobChan */

/**********************************************************************************************************************
  FrTp_LCfg_TxCurrRoundRobChan()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint8, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_TxCurrRoundRobChan(void)
{
    /* #10 return &FrTp_TxCurrRoundRobChan */
    return &FrTp_TxCurrRoundRobChan;
} /* FrTp_LCfg_TxCurrRoundRobChan */

/**********************************************************************************************************************
  FrTp_LCfg_RxSm_MaxIterations()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint16_least, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_RxSm_MaxIterations(void)
{
    /* #10 return &FrTp_RxSm_MaxIterations */
    return &FrTp_RxSm_MaxIterations;
} /* FrTp_LCfg_RxSm_MaxIterations */

/**********************************************************************************************************************
  FrTp_LCfg_TxSm_MaxIterations()
**********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */ /* MD_MSR_14.1 */
FRTP_LOCAL_INLINE FUNC(P2VAR(uint16_least, AUTOMATIC, FRTP_APPL_DATA), FRTP_CODE) FrTp_LCfg_TxSm_MaxIterations(void)
{
    /* #10 return &FrTp_TxSm_MaxIterations */
    return &FrTp_TxSm_MaxIterations;
} /* FrTp_LCfg_TxSm_MaxIterations */

/* End of FrTp_LData Abstractions */

#define FRTP_STOP_SEC_CODE 
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* FRTP_UNIT_TEST */
#endif /* FrTp_XCfg_H */

/**********************************************************************************************************************
 *  END OF FILE: FrTp_XCfg.h
 *********************************************************************************************************************/

