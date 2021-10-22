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
 *            Module: Xcp
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FrXcp_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:07
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


	
#define FRXCP_LCFG_SOURCE
  	
#include "FrXcp_Lcfg.h"

#include "FrIf.h" /* for FrIf symbolic name value defines */


#define FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

VAR(uint8, FRXCP_VAR_NOINIT) FrXcpPduDescriptorLinkTab[FRXCP_NUM_TX_LPDUIDS];
VAR(FrXcp_AlignedFrameCacheType, FRXCP_VAR_NOINIT) FrXcp_TransmitFrameCache[FRXCP_NUMBER_OF_TRANSMITFRAMECACHE];
VAR(PduLengthType, FRXCP_VAR_NOINIT) FrXcp_AggregatedLength[FRXCP_NUMBER_OF_TRANSMITFRAMECACHE];
VAR(FrXcp_TimeoutTimerType, FRXCP_VAR_NOINIT) FrXcp_ConfTimeoutTimer[FRXCP_NUMBER_OF_TRANSMITFRAMECACHE];
VAR(FrXcp_AlignedFrameCacheType, FRXCP_VAR_NOINIT) FrXcp_ReceiveFrameCache[FRXCP_NUM_RX_LPDUIDS];
VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_ReceiveFrameSignal[FRXCP_NUM_RX_LPDUIDS];
VAR(tXcpDaqTl, FRXCP_VAR_NOINIT) FrXcp_RtConfig[FRXCP_NUM_TX_LPDUIDS + FRXCP_NUM_RX_LPDUIDS];

#define FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

 
/* -----------------------------------------------------------------------------
    &&&~ FrXcp_PduDescriptorList - 
 ----------------------------------------------------------------------------- */
#define FRXCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

CONST(FrXcp_PduDescriptorType, FRXCP_CONST) FrXcp_PduDescriptorList[11U] = 
{
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_8, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_5, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_2, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_3, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_1, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_4, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_7, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_dummy16bstatic, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    16U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_dummy32bslave, 
    FRXCP_LPDU_TYPE_RES /*  Type flags of this buffer  */ , 
    32U /*  Buffer length [Bytes]  */ , 
    0U /*  IsReconfigurable  */ , 
    1U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    FrIfConf_FrIfTxPdu_FrIfTxPdu_xcpdynamic254_6, 
    FRXCP_LPDU_TYPE_VARIABLE /*  Type flags of this buffer  */ , 
    254U /*  Buffer length [Bytes]  */ , 
    1U /*  IsReconfigurable  */ , 
    0U /*  IsInitialized  */ 
  } /*  PDU ID  */ , 
  {
    XcpConf_XcpRxPdu_dummy32bmaster_19255f18, 
    FRXCP_LPDU_TYPE_CMD /*  Type flags of this buffer  */ , 
    32U /*  Buffer length [Bytes]  */ , 
    0U /*  IsReconfigurable  */ , 
    1U /*  IsInitialized  */ 
  } /*  PDU ID  */ 
};
 
CONST(PduIdType, FRXCP_CONST) FrXcp_TxPduTranslationTable[10U] =
{
  0U /*  xcpdynamic254_8_19255f18  */ , 
  1U /*  xcpdynamic254_5_19255f18  */ , 
  2U /*  xcpdynamic254_2_19255f18  */ , 
  3U /*  xcpdynamic254_3_19255f18  */ , 
  4U /*  xcpdynamic254_1_19255f18  */ , 
  5U /*  xcpdynamic254_4_19255f18  */ , 
  6U /*  xcpdynamic254_7_19255f18  */ , 
  7U /*  dummy16bstatic_19255f18  */ , 
  8U /*  dummy32bslave_19255f18  */ , 
  9U /*  xcpdynamic254_6_19255f18  */ 
};

CONST(PduIdType, FRXCP_CONST) FrXcp_RxPduTranslationTable[1U] =
{
  0U /*  dummy32bmaster_19255f18  */ 
};

/* -----------------------------------------------------------------------------
    &&&~ FrXcp_Config - 
 ----------------------------------------------------------------------------- */

CONST(FrXcp_ConfigType, FRXCP_CONST) FrXcp_Config = 
{
  &FrXcp_PduDescriptorList[0], /* Descriptor List */
  &FrXcp_TxPduTranslationTable[0], /* Translation Table */
  &FrXcp_RxPduTranslationTable[0], /* Translation Table */
  &FrXcp_TransmitFrameCache[0], /* Transmit Buffer */
  &FrXcp_AggregatedLength[0], /* Transmit Length */
  &FrXcp_ConfTimeoutTimer[0], /* Timeout Timer Counter */
  &FrXcp_ReceiveFrameCache[0], /* Receive Buffer */
  &FrXcp_ReceiveFrameSignal[0], /* Receive Flag */
  &FrXcp_RtConfig[0], /* PDU Filter */
  48, /* FrXcpNax */
  8, /* ConfTimeoutReload */
  11U, /* FrXcpPduDescriptorListSize */
  10U, /* NumberOfTransmitFC */
  10U, /* FrXcpNumberOfTxPdus */
  1U, /* FrXcpNumberOfRxPdus */
  10U, /* FrXcpMaxTxPduID */
  1U /* FrXcpMaxRxPduID */
};

#define FRXCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


