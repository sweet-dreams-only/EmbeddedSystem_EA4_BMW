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
 *              File: FrXcp_Lcfg.h
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


	
#include "FrXcp_Types.h"	

#define FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern VAR(uint8, FRXCP_VAR_NOINIT) FrXcpPduDescriptorLinkTab[FRXCP_NUM_TX_LPDUIDS];
extern VAR(FrXcp_AlignedFrameCacheType, FRXCP_VAR_NOINIT) FrXcp_TransmitFrameCache[FRXCP_NUMBER_OF_TRANSMITFRAMECACHE];
extern VAR(PduLengthType, FRXCP_VAR_NOINIT) FrXcp_AggregatedLength[FRXCP_NUMBER_OF_TRANSMITFRAMECACHE];
extern VAR(FrXcp_TimeoutTimerType, FRXCP_VAR_NOINIT) FrXcp_ConfTimeoutTimer[FRXCP_NUMBER_OF_TRANSMITFRAMECACHE];
extern VAR(FrXcp_AlignedFrameCacheType, FRXCP_VAR_NOINIT) FrXcp_ReceiveFrameCache[FRXCP_NUM_RX_LPDUIDS];
extern VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_ReceiveFrameSignal[FRXCP_NUM_RX_LPDUIDS];
extern VAR(tXcpDaqTl, FRXCP_VAR_NOINIT) FrXcp_RtConfig[FRXCP_NUM_TX_LPDUIDS + FRXCP_NUM_RX_LPDUIDS];

#define FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

 
#define FRXCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FrXcp_PduDescriptorList - 
 ----------------------------------------------------------------------------- */

extern CONST(FrXcp_PduDescriptorType, FRXCP_CONST) FrXcp_PduDescriptorList[11U];

extern CONST(PduIdType, FRXCP_CONST) FrXcp_TxPduTranslationTable[10U];
extern CONST(PduIdType, FRXCP_CONST) FrXcp_RxPduTranslationTable[1U];

/* -----------------------------------------------------------------------------
    &&&~ FrXcp_Config - 
 ----------------------------------------------------------------------------- */

extern CONST(FrXcp_ConfigType, FRXCP_CONST) FrXcp_Config;

#define FRXCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


