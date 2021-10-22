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
 *            Module: IpduM
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IpduM_Lcfg.h
 *   Generation Time: 2018-07-30 19:49:09
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


#if !defined (IPDUM_LCFG_H)
# define IPDUM_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Platform_Types.h"
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCDataSwitches  IpduM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define IPDUM_CONTAINERRXBUFFER                                       STD_OFF  /**< Deactivateable: 'IpduM_ContainerRxBuffer' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXBUFFER                                       STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxBuffer' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUID                                     STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxConfBuId' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUINLEN                                  STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxConfBuInLen' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUF                                      STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxConfBuf' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFLAID                                     STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxConfLaId' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFLAST                                     STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxConfLast' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXLIBBUFFER                                    STD_OFF  /**< Deactivateable: 'IpduM_ContainerTxLIBBuffer' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_DYNAMICPDUIDX                                           STD_ON
#define IPDUM_FINALMAGICNUMBER                                        STD_OFF  /**< Deactivateable: 'IpduM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITDATAHASHCODE                                        STD_OFF  /**< Deactivateable: 'IpduM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITIALIZED                                             STD_ON
#define IPDUM_JITUPDATEBUFFER                                         STD_ON
#define IPDUM_RXBUFFER                                                STD_ON
#define IPDUM_RXCONTAINEDPDU                                          STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINEDPDUREFOFRXCONTAINEDPDU                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.ContainedPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_HEADERIDOFRXCONTAINEDPDU                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.HeaderId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUIDXOFRXCONTAINEDPDU                       STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.RxContainerPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDUUSEDOFRXCONTAINEDPDU                      STD_OFF  /**< Deactivateable: 'IpduM_RxContainedPdu.RxContainerPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERBUFFERIDXINFO                                STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINEDPDUREADIDXOFRXCONTAINERBUFFERIDXINFO           STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo.ContainedPduReadIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINEDPDUWRITEIDXOFRXCONTAINERBUFFERIDXINFO          STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo.ContainedPduWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERPDUSENDTIMEOUTOFRXCONTAINERBUFFERIDXINFO       STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo.ContainerPduSendTimeout' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERREADCOUNTOFRXCONTAINERBUFFERIDXINFO            STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo.ContainerReadCount' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERREADIDXOFRXCONTAINERBUFFERIDXINFO              STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo.ContainerReadIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERWRITECOUNTOFRXCONTAINERBUFFERIDXINFO           STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo.ContainerWriteCount' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERWRITEIDXOFRXCONTAINERBUFFERIDXINFO             STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferIdxInfo.ContainerWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERBUFFERINFO                                   STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_COUNTOFRXCONTAINERBUFFERINFO                            STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferInfo.Count' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LENGTHOFRXCONTAINERBUFFERINFO                           STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferInfo.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_STARTPOSOFRXCONTAINERBUFFERINFO                         STD_OFF  /**< Deactivateable: 'IpduM_RxContainerBufferInfo.StartPos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERPDU                                          STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_ACCEPTALLPDUSOFRXCONTAINERPDU                           STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.AcceptAllPdus' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_IMMEDIATEPROCESSINGOFRXCONTAINERPDU                     STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.ImmediateProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LONGHEADERSOFRXCONTAINERPDU                             STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.LongHeaders' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_QUEUESIZEOFRXCONTAINERPDU                               STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.QueueSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXCONTAINERBUFFERINFOIDXOFRXCONTAINERPDU                STD_OFF  /**< Deactivateable: 'IpduM_RxContainerPdu.RxContainerBufferInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_RXDYNPDU                                                STD_ON
#define IPDUM_MINDLCOFRXDYNPDU                                        STD_ON
#define IPDUM_RXSELECTORPATTERNENDIDXOFRXDYNPDU                       STD_ON
#define IPDUM_RXSELECTORPATTERNSTARTIDXOFRXDYNPDU                     STD_ON
#define IPDUM_SEGMENTENDIDXOFRXDYNPDU                                 STD_ON
#define IPDUM_SEGMENTSTARTIDXOFRXDYNPDU                               STD_ON
#define IPDUM_ULPDUREFOFRXDYNPDU                                      STD_ON
#define IPDUM_RXINFO                                                  STD_ON
#define IPDUM_PATHWAYTYPEOFRXINFO                                     STD_ON
#define IPDUM_RXPATHWAYINDIDXOFRXINFO                                 STD_ON
#define IPDUM_RXMUXPDU                                                STD_ON
#define IPDUM_INVALIDHNDOFRXMUXPDU                                    STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.InvalidHnd' Reason: 'the value of IpduM_InvalidHndOfRxMuxPdu is always 'false' due to this, the array is deactivated.' */
#define IPDUM_RXDYNPDUENDIDXOFRXMUXPDU                                STD_ON
#define IPDUM_RXDYNPDUSTARTIDXOFRXMUXPDU                              STD_ON
#define IPDUM_RXMUXBUFFERIDXOFRXMUXPDU                                STD_ON
#define IPDUM_RXSTATICPDUIDXOFRXMUXPDU                                STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxStaticPduIdx' Reason: 'the optional indirection is deactivated because RxStaticPduUsedOfRxMuxPdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_RXSTATICPDUUSEDOFRXMUXPDU                               STD_OFF  /**< Deactivateable: 'IpduM_RxMuxPdu.RxStaticPduUsed' Reason: 'the optional indirection is deactivated because RxStaticPduUsedOfRxMuxPdu is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_SELECTORFIELDBYTEPOSITIONOFRXMUXPDU                     STD_ON
#define IPDUM_SELECTORFIELDSTARTBITOFRXMUXPDU                         STD_ON
#define IPDUM_RXSELECTORPATTERN                                       STD_ON
#define IPDUM_SELECTORFIELDSUBMASKOFRXSELECTORPATTERN                 STD_ON
#define IPDUM_SELECTORFIELDSUBPATTERNOFRXSELECTORPATTERN              STD_ON
#define IPDUM_RXSTATICPDU                                             STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_MINDLCOFRXSTATICPDU                                     STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.MinDLC' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTENDIDXOFRXSTATICPDU                              STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.SegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENTSTARTIDXOFRXSTATICPDU                            STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.SegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_ULPDUREFOFRXSTATICPDU                                   STD_OFF  /**< Deactivateable: 'IpduM_RxStaticPdu.UlPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SEGMENT                                                 STD_ON
#define IPDUM_BITINBYTEPOSOFSEGMENT                                   STD_ON
#define IPDUM_ENDBYTEMASKCLEAROFSEGMENT                               STD_ON
#define IPDUM_ENDBYTEMASKWRITEOFSEGMENT                               STD_ON
#define IPDUM_FIRSTBYTEPOSOFSEGMENT                                   STD_ON
#define IPDUM_FIRSTFULLBYTEPOSOFSEGMENT                               STD_ON
#define IPDUM_FULLBYTESPRESENTOFSEGMENT                               STD_ON
#define IPDUM_LASTBYTEPOSOFSEGMENT                                    STD_ON
#define IPDUM_LASTFULLBYTEPOSOFSEGMENT                                STD_ON
#define IPDUM_LENGTHOFSEGMENT                                         STD_ON
#define IPDUM_PARTIALENDBYTEOFSEGMENT                                 STD_OFF  /**< Deactivateable: 'IpduM_Segment.PartialEndByte' Reason: 'the value of IpduM_PartialEndByteOfSegment is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PARTIALSTARTBYTEOFSEGMENT                               STD_OFF  /**< Deactivateable: 'IpduM_Segment.PartialStartByte' Reason: 'the value of IpduM_PartialStartByteOfSegment is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PDUBYTEPOSOFSEGMENT                                     STD_ON
#define IPDUM_STARTBYTEMASKCLEAROFSEGMENT                             STD_ON
#define IPDUM_STARTBYTEMASKWRITEOFSEGMENT                             STD_ON
#define IPDUM_SIZEOFDYNAMICPDUIDX                                     STD_ON
#define IPDUM_SIZEOFJITUPDATEBUFFER                                   STD_ON
#define IPDUM_SIZEOFRXBUFFER                                          STD_ON
#define IPDUM_SIZEOFRXDYNPDU                                          STD_ON
#define IPDUM_SIZEOFRXINFO                                            STD_ON
#define IPDUM_SIZEOFRXMUXPDU                                          STD_ON
#define IPDUM_SIZEOFRXSELECTORPATTERN                                 STD_ON
#define IPDUM_SIZEOFSEGMENT                                           STD_ON
#define IPDUM_SIZEOFTRIGGERTRANSMITBUFFER                             STD_ON
#define IPDUM_SIZEOFTXBUFFER                                          STD_ON
#define IPDUM_SIZEOFTXCONFTIMEOUTCNT                                  STD_ON
#define IPDUM_SIZEOFTXINITVALUES                                      STD_ON
#define IPDUM_SIZEOFTXLOINFO                                          STD_ON
#define IPDUM_SIZEOFTXPART                                            STD_ON
#define IPDUM_SIZEOFTXPARTIND                                         STD_ON
#define IPDUM_SIZEOFTXPATHWAY                                         STD_ON
#define IPDUM_SIZEOFTXUPINFO                                          STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFER                                   STD_ON
#define IPDUM_TXBUFFER                                                STD_ON
#define IPDUM_TXCONFTIMEOUTCNT                                        STD_ON
#define IPDUM_TXCONTAINEDPDU                                          STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_HEADERIDOFTXCONTAINEDPDU                                STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.HeaderId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_INVALIDHNDOFTXCONTAINEDPDU                              STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LASTISBESTOFTXCONTAINEDPDU                              STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.LastIsBest' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTIMEOUTOFTXCONTAINEDPDU                             STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.SendTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTODEFOFTXCONTAINEDPDU                               STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.SendToDef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU                          STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxConfirmation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINEDPDUREFOFTXCONTAINEDPDU                       STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxContainedPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUIDXOFTXCONTAINEDPDU                       STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxContainerPduIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXPDUTRIGGEROFTXCONTAINEDPDU                            STD_OFF  /**< Deactivateable: 'IpduM_TxContainedPdu.TxPduTrigger' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERBUFFERIDXINFO                                STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINEDPDUREADIDXOFTXCONTAINERBUFFERIDXINFO           STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo.ContainedPduReadIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINEDPDUWRITEIDXOFTXCONTAINERBUFFERIDXINFO          STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo.ContainedPduWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERPDUSENDTIMEOUTOFTXCONTAINERBUFFERIDXINFO       STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo.ContainerPduSendTimeout' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERREADCOUNTOFTXCONTAINERBUFFERIDXINFO            STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo.ContainerReadCount' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERREADIDXOFTXCONTAINERBUFFERIDXINFO              STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo.ContainerReadIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERWRITECOUNTOFTXCONTAINERBUFFERIDXINFO           STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo.ContainerWriteCount' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERWRITEIDXOFTXCONTAINERBUFFERIDXINFO             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferIdxInfo.ContainerWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERBUFFERINFO                                   STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_COUNTOFTXCONTAINERBUFFERINFO                            STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferInfo.Count' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LENGTHOFTXCONTAINERBUFFERINFO                           STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferInfo.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_STARTPOSOFTXCONTAINERBUFFERINFO                         STD_OFF  /**< Deactivateable: 'IpduM_TxContainerBufferInfo.StartPos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDU                                          STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define IPDUM_CONTAINERTXCONFBUIDENDIDXOFTXCONTAINERPDU               STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfBuIdEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUIDSTARTIDXOFTXCONTAINERPDU             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfBuIdStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUINLENENDIDXOFTXCONTAINERPDU            STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfBuInLenEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUINLENSTARTIDXOFTXCONTAINERPDU          STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfBuInLenStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUFENDIDXOFTXCONTAINERPDU                STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfBufEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFBUFSTARTIDXOFTXCONTAINERPDU              STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfBufStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFLAIDIDXOFTXCONTAINERPDU                  STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfLaIdIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFLASTENDIDXOFTXCONTAINERPDU               STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfLastEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTXCONFLASTSTARTIDXOFTXCONTAINERPDU             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerTxConfLastStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_CONTAINERTYPEOFTXCONTAINERPDU                           STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_FIRSTCONTAINEDPDUTRIGGEROFTXCONTAINERPDU                STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.FirstContainedPduTrigger' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_LONGHEADERSOFTXCONTAINERPDU                             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.LongHeaders' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_QUEUESIZEOFTXCONTAINERPDU                               STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.QueueSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTIMEOUTOFTXCONTAINERPDU                             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.SendTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_SENDTODEFOFTXCONTAINERPDU                               STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.SendToDef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU                         STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TriggerTransmit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU                   STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TxConfirmationTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERBUFFERINFOENDIDXOFTXCONTAINERPDU             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TxContainerBufferInfoEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERBUFFERINFOSTARTIDXOFTXCONTAINERPDU           STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TxContainerBufferInfoStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXCONTAINERPDUREFOFTXCONTAINERPDU                       STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TxContainerPduRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOIDXOFTXCONTAINERPDU                             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TxLoInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXLOINFOUSEDOFTXCONTAINERPDU                            STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TxLoInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXSIZETHRESHOLDOFTXCONTAINERPDU                         STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.TxSizeThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_TXINITVALUES                                            STD_ON
#define IPDUM_TXLOINFO                                                STD_ON
#define IPDUM_INVALIDHNDOFTXLOINFO                                    STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfo.InvalidHnd' Reason: 'the value of IpduM_InvalidHndOfTxLoInfo is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PATHWAYTYPEOFTXLOINFO                                   STD_ON
#define IPDUM_TXCONFTIMEOUTCNTIDXOFTXLOINFO                           STD_ON
#define IPDUM_TXCONTAINERPDUIDXOFTXLOINFO                             STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfo.TxContainerPduIdx' Reason: 'the optional indirection is deactivated because TxContainerPduUsedOfTxLoInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXCONTAINERPDUUSEDOFTXLOINFO                            STD_OFF  /**< Deactivateable: 'IpduM_TxLoInfo.TxContainerPduUsed' Reason: 'the optional indirection is deactivated because TxContainerPduUsedOfTxLoInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXPATHWAYIDXOFTXLOINFO                                  STD_ON
#define IPDUM_TXPATHWAYUSEDOFTXLOINFO                                 STD_ON
#define IPDUM_TXPART                                                  STD_ON
#define IPDUM_INVALIDHNDOFTXPART                                      STD_OFF  /**< Deactivateable: 'IpduM_TxPart.InvalidHnd' Reason: 'the value of IpduM_InvalidHndOfTxPart is always 'false' due to this, the array is deactivated.' */
#define IPDUM_JITUPDATEOFTXPART                                       STD_ON
#define IPDUM_MASKEDBITSOFTXPART                                      STD_ON
#define IPDUM_SEGMENTENDIDXOFTXPART                                   STD_ON
#define IPDUM_SEGMENTSTARTIDXOFTXPART                                 STD_ON
#define IPDUM_TRIGGEREVENTOFTXPART                                    STD_ON
#define IPDUM_TXCONFIRMATIONOFTXPART                                  STD_ON
#define IPDUM_TXPATHWAYIDXOFTXPART                                    STD_ON
#define IPDUM_ULPDUREFOFTXPART                                        STD_ON
#define IPDUM_TXPARTIND                                               STD_ON
#define IPDUM_TXPATHWAY                                               STD_ON
#define IPDUM_DYNAMICPDUIDXIDXOFTXPATHWAY                             STD_ON
#define IPDUM_LENGTHOFTXPATHWAY                                       STD_ON
#define IPDUM_LLPDUREFOFTXPATHWAY                                     STD_ON
#define IPDUM_TXBUFFERIDXOFTXPATHWAY                                  STD_ON
#define IPDUM_TXCONFIRMATIONTIMEOUTOFTXPATHWAY                        STD_OFF  /**< Deactivateable: 'IpduM_TxPathway.TxConfirmationTimeout' Reason: 'the value of IpduM_TxConfirmationTimeoutOfTxPathway is always '0' due to this, the array is deactivated.' */
#define IPDUM_TXLOINFOIDXOFTXPATHWAY                                  STD_OFF  /**< Deactivateable: 'IpduM_TxPathway.TxLoInfoIdx' Reason: 'the optional indirection is deactivated because TxLoInfoUsedOfTxPathway is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXLOINFOUSEDOFTXPATHWAY                                 STD_OFF  /**< Deactivateable: 'IpduM_TxPathway.TxLoInfoUsed' Reason: 'the optional indirection is deactivated because TxLoInfoUsedOfTxPathway is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXPARTINDENDIDXOFTXPATHWAY                              STD_ON
#define IPDUM_TXPARTINDSTARTIDXOFTXPATHWAY                            STD_ON
#define IPDUM_TXPARTINITIALDYNPARTIDXOFTXPATHWAY                      STD_ON
#define IPDUM_TXPARTSTATICPARTIDXOFTXPATHWAY                          STD_OFF  /**< Deactivateable: 'IpduM_TxPathway.TxPartStaticPartIdx' Reason: 'the optional indirection is deactivated because TxPartStaticPartUsedOfTxPathway is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXPARTSTATICPARTUSEDOFTXPATHWAY                         STD_OFF  /**< Deactivateable: 'IpduM_TxPathway.TxPartStaticPartUsed' Reason: 'the optional indirection is deactivated because TxPartStaticPartUsedOfTxPathway is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define IPDUM_TXSTATICPDUREFOFTXPATHWAY                               STD_OFF  /**< Deactivateable: 'IpduM_TxPathway.TxStaticPduRef' Reason: 'the value of IpduM_TxStaticPduRefOfTxPathway is always 'IPDUM_NO_TXSTATICPDUREFOFTXPATHWAY' due to this, the array is deactivated.' */
#define IPDUM_TXSTATICPDUREFUSEDOFTXPATHWAY                           STD_OFF  /**< Deactivateable: 'IpduM_TxPathway.TxStaticPduRefUsed' Reason: 'the value of IpduM_TxStaticPduRefUsedOfTxPathway is always 'false' due to this, the array is deactivated.' */
#define IPDUM_UNUSEDAREASDEFAULTOFTXPATHWAY                           STD_ON
#define IPDUM_TXUPINFO                                                STD_ON
#define IPDUM_INVALIDHNDOFTXUPINFO                                    STD_OFF  /**< Deactivateable: 'IpduM_TxUpInfo.InvalidHnd' Reason: 'the value of IpduM_InvalidHndOfTxUpInfo is always 'false' due to this, the array is deactivated.' */
#define IPDUM_PATHWAYTYPEOFTXUPINFO                                   STD_ON
#define IPDUM_TXUPINDIDXOFTXUPINFO                                    STD_ON
#define IPDUM_PCCONFIG                                                STD_ON
#define IPDUM_DYNAMICPDUIDXOFPCCONFIG                                 STD_ON
#define IPDUM_FINALMAGICNUMBEROFPCCONFIG                              STD_OFF  /**< Deactivateable: 'IpduM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITDATAHASHCODEOFPCCONFIG                              STD_OFF  /**< Deactivateable: 'IpduM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define IPDUM_INITIALIZEDOFPCCONFIG                                   STD_ON
#define IPDUM_JITUPDATEBUFFEROFPCCONFIG                               STD_ON
#define IPDUM_RXBUFFEROFPCCONFIG                                      STD_ON
#define IPDUM_RXDYNPDUOFPCCONFIG                                      STD_ON
#define IPDUM_RXINFOOFPCCONFIG                                        STD_ON
#define IPDUM_RXMUXPDUOFPCCONFIG                                      STD_ON
#define IPDUM_RXSELECTORPATTERNOFPCCONFIG                             STD_ON
#define IPDUM_SEGMENTOFPCCONFIG                                       STD_ON
#define IPDUM_SIZEOFDYNAMICPDUIDXOFPCCONFIG                           STD_ON
#define IPDUM_SIZEOFJITUPDATEBUFFEROFPCCONFIG                         STD_ON
#define IPDUM_SIZEOFRXBUFFEROFPCCONFIG                                STD_ON
#define IPDUM_SIZEOFRXDYNPDUOFPCCONFIG                                STD_ON
#define IPDUM_SIZEOFRXINFOOFPCCONFIG                                  STD_ON
#define IPDUM_SIZEOFRXMUXPDUOFPCCONFIG                                STD_ON
#define IPDUM_SIZEOFRXSELECTORPATTERNOFPCCONFIG                       STD_ON
#define IPDUM_SIZEOFSEGMENTOFPCCONFIG                                 STD_ON
#define IPDUM_SIZEOFTRIGGERTRANSMITBUFFEROFPCCONFIG                   STD_ON
#define IPDUM_SIZEOFTXBUFFEROFPCCONFIG                                STD_ON
#define IPDUM_SIZEOFTXCONFTIMEOUTCNTOFPCCONFIG                        STD_ON
#define IPDUM_SIZEOFTXINITVALUESOFPCCONFIG                            STD_ON
#define IPDUM_SIZEOFTXLOINFOOFPCCONFIG                                STD_ON
#define IPDUM_SIZEOFTXPARTINDOFPCCONFIG                               STD_ON
#define IPDUM_SIZEOFTXPARTOFPCCONFIG                                  STD_ON
#define IPDUM_SIZEOFTXPATHWAYOFPCCONFIG                               STD_ON
#define IPDUM_SIZEOFTXUPINFOOFPCCONFIG                                STD_ON
#define IPDUM_TRIGGERTRANSMITBUFFEROFPCCONFIG                         STD_ON
#define IPDUM_TXBUFFEROFPCCONFIG                                      STD_ON
#define IPDUM_TXCONFTIMEOUTCNTOFPCCONFIG                              STD_ON
#define IPDUM_TXINITVALUESOFPCCONFIG                                  STD_ON
#define IPDUM_TXLOINFOOFPCCONFIG                                      STD_ON
#define IPDUM_TXPARTINDOFPCCONFIG                                     STD_ON
#define IPDUM_TXPARTOFPCCONFIG                                        STD_ON
#define IPDUM_TXPATHWAYOFPCCONFIG                                     STD_ON
#define IPDUM_TXUPINFOOFPCCONFIG                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCMinNumericValueDefines  IpduM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define IPDUM_MIN_DYNAMICPDUIDX                                       0U
#define IPDUM_MIN_JITUPDATEBUFFER                                     0U
#define IPDUM_MIN_RXBUFFER                                            0U
#define IPDUM_MIN_TRIGGERTRANSMITBUFFER                               0U
#define IPDUM_MIN_TXBUFFER                                            0U
#define IPDUM_MIN_TXCONFTIMEOUTCNT                                    0U
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCMaxNumericValueDefines  IpduM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define IPDUM_MAX_DYNAMICPDUIDX                                       65535U
#define IPDUM_MAX_JITUPDATEBUFFER                                     255U
#define IPDUM_MAX_RXBUFFER                                            255U
#define IPDUM_MAX_TRIGGERTRANSMITBUFFER                               255U
#define IPDUM_MAX_TXBUFFER                                            255U
#define IPDUM_MAX_TXCONFTIMEOUTCNT                                    65535U
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCNoReferenceDefines  IpduM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define IPDUM_NO_TXPATHWAYIDXOFTXLOINFO                               255U
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEnumExistsDefines  IpduM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFRXINFO                          STD_ON
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFRXINFO                    STD_OFF
#define IPDUM_EXISTS_QUEUED_CONTAINERTYPEOFTXCONTAINERPDU             STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_LAST_IS_BEST_CONTAINERTYPEOFTXCONTAINERPDU       STD_OFF  /**< Deactivateable: 'IpduM_TxContainerPdu.ContainerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXLOINFO                        STD_ON
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXLOINFO                  STD_OFF
#define IPDUM_EXISTS_MUX_PATHWAYTYPEOFTXUPINFO                        STD_ON
#define IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFTXUPINFO                  STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEnumDefines  IpduM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define IPDUM_MUX_PATHWAYTYPEOFRXINFO                                 0x00U
#define IPDUM_MUX_PATHWAYTYPEOFTXLOINFO                               0x00U
#define IPDUM_MUX_PATHWAYTYPEOFTXUPINFO                               0x00U
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCMaskedBitDefines  IpduM Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define IPDUM_JITUPDATEOFTXPART_MASK                                  0x04U
#define IPDUM_TRIGGEREVENTOFTXPART_MASK                               0x02U
#define IPDUM_TXCONFIRMATIONOFTXPART_MASK                             0x01U
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIsReducedToDefineDefines  IpduM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define IPDUM_ISDEF_MINDLCOFRXDYNPDU                                  STD_OFF
#define IPDUM_ISDEF_RXSELECTORPATTERNENDIDXOFRXDYNPDU                 STD_OFF
#define IPDUM_ISDEF_RXSELECTORPATTERNSTARTIDXOFRXDYNPDU               STD_OFF
#define IPDUM_ISDEF_SEGMENTENDIDXOFRXDYNPDU                           STD_OFF
#define IPDUM_ISDEF_SEGMENTSTARTIDXOFRXDYNPDU                         STD_OFF
#define IPDUM_ISDEF_ULPDUREFOFRXDYNPDU                                STD_OFF
#define IPDUM_ISDEF_PATHWAYTYPEOFRXINFO                               STD_OFF
#define IPDUM_ISDEF_RXPATHWAYINDIDXOFRXINFO                           STD_OFF
#define IPDUM_ISDEF_RXDYNPDUENDIDXOFRXMUXPDU                          STD_OFF
#define IPDUM_ISDEF_RXDYNPDUSTARTIDXOFRXMUXPDU                        STD_OFF
#define IPDUM_ISDEF_RXMUXBUFFERIDXOFRXMUXPDU                          STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDBYTEPOSITIONOFRXMUXPDU               STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDSTARTBITOFRXMUXPDU                   STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDSUBMASKOFRXSELECTORPATTERN           STD_OFF
#define IPDUM_ISDEF_SELECTORFIELDSUBPATTERNOFRXSELECTORPATTERN        STD_OFF
#define IPDUM_ISDEF_BITINBYTEPOSOFSEGMENT                             STD_OFF
#define IPDUM_ISDEF_ENDBYTEMASKCLEAROFSEGMENT                         STD_OFF
#define IPDUM_ISDEF_ENDBYTEMASKWRITEOFSEGMENT                         STD_OFF
#define IPDUM_ISDEF_FIRSTBYTEPOSOFSEGMENT                             STD_OFF
#define IPDUM_ISDEF_FIRSTFULLBYTEPOSOFSEGMENT                         STD_OFF
#define IPDUM_ISDEF_FULLBYTESPRESENTOFSEGMENT                         STD_OFF
#define IPDUM_ISDEF_LASTBYTEPOSOFSEGMENT                              STD_OFF
#define IPDUM_ISDEF_LASTFULLBYTEPOSOFSEGMENT                          STD_OFF
#define IPDUM_ISDEF_LENGTHOFSEGMENT                                   STD_OFF
#define IPDUM_ISDEF_PDUBYTEPOSOFSEGMENT                               STD_OFF
#define IPDUM_ISDEF_STARTBYTEMASKCLEAROFSEGMENT                       STD_OFF
#define IPDUM_ISDEF_STARTBYTEMASKWRITEOFSEGMENT                       STD_OFF
#define IPDUM_ISDEF_TXINITVALUES                                      STD_OFF
#define IPDUM_ISDEF_PATHWAYTYPEOFTXLOINFO                             STD_OFF
#define IPDUM_ISDEF_TXCONFTIMEOUTCNTIDXOFTXLOINFO                     STD_OFF
#define IPDUM_ISDEF_TXPATHWAYIDXOFTXLOINFO                            STD_OFF
#define IPDUM_ISDEF_TXPATHWAYUSEDOFTXLOINFO                           STD_OFF
#define IPDUM_ISDEF_JITUPDATEOFTXPART                                 STD_OFF
#define IPDUM_ISDEF_MASKEDBITSOFTXPART                                STD_OFF
#define IPDUM_ISDEF_SEGMENTENDIDXOFTXPART                             STD_OFF
#define IPDUM_ISDEF_SEGMENTSTARTIDXOFTXPART                           STD_OFF
#define IPDUM_ISDEF_TRIGGEREVENTOFTXPART                              STD_OFF
#define IPDUM_ISDEF_TXCONFIRMATIONOFTXPART                            STD_OFF
#define IPDUM_ISDEF_TXPATHWAYIDXOFTXPART                              STD_OFF
#define IPDUM_ISDEF_ULPDUREFOFTXPART                                  STD_OFF
#define IPDUM_ISDEF_TXPARTIND                                         STD_OFF
#define IPDUM_ISDEF_DYNAMICPDUIDXIDXOFTXPATHWAY                       STD_OFF
#define IPDUM_ISDEF_LENGTHOFTXPATHWAY                                 STD_OFF
#define IPDUM_ISDEF_LLPDUREFOFTXPATHWAY                               STD_OFF
#define IPDUM_ISDEF_TXBUFFERIDXOFTXPATHWAY                            STD_OFF
#define IPDUM_ISDEF_TXPARTINDENDIDXOFTXPATHWAY                        STD_OFF
#define IPDUM_ISDEF_TXPARTINDSTARTIDXOFTXPATHWAY                      STD_OFF
#define IPDUM_ISDEF_TXPARTINITIALDYNPARTIDXOFTXPATHWAY                STD_OFF
#define IPDUM_ISDEF_UNUSEDAREASDEFAULTOFTXPATHWAY                     STD_OFF
#define IPDUM_ISDEF_PATHWAYTYPEOFTXUPINFO                             STD_OFF
#define IPDUM_ISDEF_TXUPINDIDXOFTXUPINFO                              STD_OFF
#define IPDUM_ISDEF_DYNAMICPDUIDXOFPCCONFIG                           STD_ON
#define IPDUM_ISDEF_INITIALIZEDOFPCCONFIG                             STD_ON
#define IPDUM_ISDEF_JITUPDATEBUFFEROFPCCONFIG                         STD_ON
#define IPDUM_ISDEF_RXBUFFEROFPCCONFIG                                STD_ON
#define IPDUM_ISDEF_RXDYNPDUOFPCCONFIG                                STD_ON
#define IPDUM_ISDEF_RXINFOOFPCCONFIG                                  STD_ON
#define IPDUM_ISDEF_RXMUXPDUOFPCCONFIG                                STD_ON
#define IPDUM_ISDEF_RXSELECTORPATTERNOFPCCONFIG                       STD_ON
#define IPDUM_ISDEF_SEGMENTOFPCCONFIG                                 STD_ON
#define IPDUM_ISDEF_TRIGGERTRANSMITBUFFEROFPCCONFIG                   STD_ON
#define IPDUM_ISDEF_TXBUFFEROFPCCONFIG                                STD_ON
#define IPDUM_ISDEF_TXCONFTIMEOUTCNTOFPCCONFIG                        STD_ON
#define IPDUM_ISDEF_TXINITVALUESOFPCCONFIG                            STD_ON
#define IPDUM_ISDEF_TXLOINFOOFPCCONFIG                                STD_ON
#define IPDUM_ISDEF_TXPARTINDOFPCCONFIG                               STD_ON
#define IPDUM_ISDEF_TXPARTOFPCCONFIG                                  STD_ON
#define IPDUM_ISDEF_TXPATHWAYOFPCCONFIG                               STD_ON
#define IPDUM_ISDEF_TXUPINFOOFPCCONFIG                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCEqualsAlwaysToDefines  IpduM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define IPDUM_EQ2_MINDLCOFRXDYNPDU                                    
#define IPDUM_EQ2_RXSELECTORPATTERNENDIDXOFRXDYNPDU                   
#define IPDUM_EQ2_RXSELECTORPATTERNSTARTIDXOFRXDYNPDU                 
#define IPDUM_EQ2_SEGMENTENDIDXOFRXDYNPDU                             
#define IPDUM_EQ2_SEGMENTSTARTIDXOFRXDYNPDU                           
#define IPDUM_EQ2_ULPDUREFOFRXDYNPDU                                  
#define IPDUM_EQ2_PATHWAYTYPEOFRXINFO                                 
#define IPDUM_EQ2_RXPATHWAYINDIDXOFRXINFO                             
#define IPDUM_EQ2_RXDYNPDUENDIDXOFRXMUXPDU                            
#define IPDUM_EQ2_RXDYNPDUSTARTIDXOFRXMUXPDU                          
#define IPDUM_EQ2_RXMUXBUFFERIDXOFRXMUXPDU                            
#define IPDUM_EQ2_SELECTORFIELDBYTEPOSITIONOFRXMUXPDU                 
#define IPDUM_EQ2_SELECTORFIELDSTARTBITOFRXMUXPDU                     
#define IPDUM_EQ2_SELECTORFIELDSUBMASKOFRXSELECTORPATTERN             
#define IPDUM_EQ2_SELECTORFIELDSUBPATTERNOFRXSELECTORPATTERN          
#define IPDUM_EQ2_BITINBYTEPOSOFSEGMENT                               
#define IPDUM_EQ2_ENDBYTEMASKCLEAROFSEGMENT                           
#define IPDUM_EQ2_ENDBYTEMASKWRITEOFSEGMENT                           
#define IPDUM_EQ2_FIRSTBYTEPOSOFSEGMENT                               
#define IPDUM_EQ2_FIRSTFULLBYTEPOSOFSEGMENT                           
#define IPDUM_EQ2_FULLBYTESPRESENTOFSEGMENT                           
#define IPDUM_EQ2_LASTBYTEPOSOFSEGMENT                                
#define IPDUM_EQ2_LASTFULLBYTEPOSOFSEGMENT                            
#define IPDUM_EQ2_LENGTHOFSEGMENT                                     
#define IPDUM_EQ2_PDUBYTEPOSOFSEGMENT                                 
#define IPDUM_EQ2_STARTBYTEMASKCLEAROFSEGMENT                         
#define IPDUM_EQ2_STARTBYTEMASKWRITEOFSEGMENT                         
#define IPDUM_EQ2_TXINITVALUES                                        
#define IPDUM_EQ2_PATHWAYTYPEOFTXLOINFO                               
#define IPDUM_EQ2_TXCONFTIMEOUTCNTIDXOFTXLOINFO                       
#define IPDUM_EQ2_TXPATHWAYIDXOFTXLOINFO                              
#define IPDUM_EQ2_TXPATHWAYUSEDOFTXLOINFO                             
#define IPDUM_EQ2_JITUPDATEOFTXPART                                   
#define IPDUM_EQ2_MASKEDBITSOFTXPART                                  
#define IPDUM_EQ2_SEGMENTENDIDXOFTXPART                               
#define IPDUM_EQ2_SEGMENTSTARTIDXOFTXPART                             
#define IPDUM_EQ2_TRIGGEREVENTOFTXPART                                
#define IPDUM_EQ2_TXCONFIRMATIONOFTXPART                              
#define IPDUM_EQ2_TXPATHWAYIDXOFTXPART                                
#define IPDUM_EQ2_ULPDUREFOFTXPART                                    
#define IPDUM_EQ2_TXPARTIND                                           
#define IPDUM_EQ2_DYNAMICPDUIDXIDXOFTXPATHWAY                         
#define IPDUM_EQ2_LENGTHOFTXPATHWAY                                   
#define IPDUM_EQ2_LLPDUREFOFTXPATHWAY                                 
#define IPDUM_EQ2_TXBUFFERIDXOFTXPATHWAY                              
#define IPDUM_EQ2_TXPARTINDENDIDXOFTXPATHWAY                          
#define IPDUM_EQ2_TXPARTINDSTARTIDXOFTXPATHWAY                        
#define IPDUM_EQ2_TXPARTINITIALDYNPARTIDXOFTXPATHWAY                  
#define IPDUM_EQ2_UNUSEDAREASDEFAULTOFTXPATHWAY                       
#define IPDUM_EQ2_PATHWAYTYPEOFTXUPINFO                               
#define IPDUM_EQ2_TXUPINDIDXOFTXUPINFO                                
#define IPDUM_EQ2_DYNAMICPDUIDXOFPCCONFIG                             IpduM_DynamicPduIdx.raw
#define IPDUM_EQ2_INITIALIZEDOFPCCONFIG                               IpduM_Initialized
#define IPDUM_EQ2_JITUPDATEBUFFEROFPCCONFIG                           IpduM_JitUpdateBuffer
#define IPDUM_EQ2_RXBUFFEROFPCCONFIG                                  IpduM_RxBuffer
#define IPDUM_EQ2_RXDYNPDUOFPCCONFIG                                  IpduM_RxDynPdu
#define IPDUM_EQ2_RXINFOOFPCCONFIG                                    IpduM_RxInfo
#define IPDUM_EQ2_RXMUXPDUOFPCCONFIG                                  IpduM_RxMuxPdu
#define IPDUM_EQ2_RXSELECTORPATTERNOFPCCONFIG                         IpduM_RxSelectorPattern
#define IPDUM_EQ2_SEGMENTOFPCCONFIG                                   IpduM_Segment
#define IPDUM_EQ2_TRIGGERTRANSMITBUFFEROFPCCONFIG                     IpduM_TriggerTransmitBuffer
#define IPDUM_EQ2_TXBUFFEROFPCCONFIG                                  IpduM_TxBuffer
#define IPDUM_EQ2_TXCONFTIMEOUTCNTOFPCCONFIG                          IpduM_TxConfTimeoutCnt.raw
#define IPDUM_EQ2_TXINITVALUESOFPCCONFIG                              IpduM_TxInitValues
#define IPDUM_EQ2_TXLOINFOOFPCCONFIG                                  IpduM_TxLoInfo
#define IPDUM_EQ2_TXPARTINDOFPCCONFIG                                 IpduM_TxPartInd
#define IPDUM_EQ2_TXPARTOFPCCONFIG                                    IpduM_TxPart
#define IPDUM_EQ2_TXPATHWAYOFPCCONFIG                                 IpduM_TxPathway
#define IPDUM_EQ2_TXUPINFOOFPCCONFIG                                  IpduM_TxUpInfo
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSymbolicInitializationPointers  IpduM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define IpduM_Config_Ptr                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'IpduM' */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCInitializationSymbols  IpduM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define IpduM_Config                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'IpduM */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGeneral  IpduM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define IPDUM_CHECK_INIT_POINTER                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define IPDUM_FINAL_MAGIC_NUMBER                                      0x341EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of IpduM */
#define IPDUM_INDIVIDUAL_POSTBUILD                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'IpduM' is not configured to be postbuild capable. */
#define IPDUM_INIT_DATA                                               IPDUM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define IPDUM_INIT_DATA_HASH_CODE                                     -1987164154L  /**< the precompile constant to validate the initialization structure at initialization time of IpduM with a hashcode. The seed value is '0x341EU' */
#define IPDUM_USE_ECUM_BSW_ERROR_HOOK                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define IPDUM_USE_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer IpduM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  IpduMLTDataSwitches  IpduM Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define IPDUM_LTCONFIG                                                STD_OFF  /**< Deactivateable: 'IpduM_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCGetConstantDuplicatedRootDataMacros  IpduM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define IpduM_GetDynamicPduIdxOfPCConfig()                            IpduM_DynamicPduIdx.raw  /**< the pointer to IpduM_DynamicPduIdx */
#define IpduM_GetInitializedOfPCConfig()                              IpduM_Initialized  /**< the pointer to IpduM_Initialized */
#define IpduM_GetJitUpdateBufferOfPCConfig()                          IpduM_JitUpdateBuffer  /**< the pointer to IpduM_JitUpdateBuffer */
#define IpduM_GetRxBufferOfPCConfig()                                 IpduM_RxBuffer  /**< the pointer to IpduM_RxBuffer */
#define IpduM_GetRxDynPduOfPCConfig()                                 IpduM_RxDynPdu  /**< the pointer to IpduM_RxDynPdu */
#define IpduM_GetRxInfoOfPCConfig()                                   IpduM_RxInfo  /**< the pointer to IpduM_RxInfo */
#define IpduM_GetRxMuxPduOfPCConfig()                                 IpduM_RxMuxPdu  /**< the pointer to IpduM_RxMuxPdu */
#define IpduM_GetRxSelectorPatternOfPCConfig()                        IpduM_RxSelectorPattern  /**< the pointer to IpduM_RxSelectorPattern */
#define IpduM_GetSegmentOfPCConfig()                                  IpduM_Segment  /**< the pointer to IpduM_Segment */
#define IpduM_GetSizeOfJitUpdateBufferOfPCConfig()                    140U  /**< the number of accomplishable value elements in IpduM_JitUpdateBuffer */
#define IpduM_GetSizeOfRxBufferOfPCConfig()                           8U  /**< the number of accomplishable value elements in IpduM_RxBuffer */
#define IpduM_GetSizeOfRxDynPduOfPCConfig()                           2U  /**< the number of accomplishable value elements in IpduM_RxDynPdu */
#define IpduM_GetSizeOfRxInfoOfPCConfig()                             1U  /**< the number of accomplishable value elements in IpduM_RxInfo */
#define IpduM_GetSizeOfRxMuxPduOfPCConfig()                           1U  /**< the number of accomplishable value elements in IpduM_RxMuxPdu */
#define IpduM_GetSizeOfRxSelectorPatternOfPCConfig()                  2U  /**< the number of accomplishable value elements in IpduM_RxSelectorPattern */
#define IpduM_GetSizeOfSegmentOfPCConfig()                            2U  /**< the number of accomplishable value elements in IpduM_Segment */
#define IpduM_GetSizeOfTriggerTransmitBufferOfPCConfig()              140U  /**< the number of accomplishable value elements in IpduM_TriggerTransmitBuffer */
#define IpduM_GetSizeOfTxBufferOfPCConfig()                           140U  /**< the number of accomplishable value elements in IpduM_TxBuffer */
#define IpduM_GetSizeOfTxConfTimeoutCntOfPCConfig()                   2U  /**< the number of accomplishable value elements in IpduM_TxConfTimeoutCnt */
#define IpduM_GetSizeOfTxInitValuesOfPCConfig()                       140U  /**< the number of accomplishable value elements in IpduM_TxInitValues */
#define IpduM_GetSizeOfTxLoInfoOfPCConfig()                           2U  /**< the number of accomplishable value elements in IpduM_TxLoInfo */
#define IpduM_GetSizeOfTxPartIndOfPCConfig()                          5U  /**< the number of accomplishable value elements in IpduM_TxPartInd */
#define IpduM_GetSizeOfTxPartOfPCConfig()                             5U  /**< the number of accomplishable value elements in IpduM_TxPart */
#define IpduM_GetSizeOfTxPathwayOfPCConfig()                          2U  /**< the number of accomplishable value elements in IpduM_TxPathway */
#define IpduM_GetSizeOfTxUpInfoOfPCConfig()                           5U  /**< the number of accomplishable value elements in IpduM_TxUpInfo */
#define IpduM_GetTriggerTransmitBufferOfPCConfig()                    IpduM_TriggerTransmitBuffer  /**< the pointer to IpduM_TriggerTransmitBuffer */
#define IpduM_GetTxBufferOfPCConfig()                                 IpduM_TxBuffer  /**< the pointer to IpduM_TxBuffer */
#define IpduM_GetTxConfTimeoutCntOfPCConfig()                         IpduM_TxConfTimeoutCnt.raw  /**< the pointer to IpduM_TxConfTimeoutCnt */
#define IpduM_GetTxInitValuesOfPCConfig()                             IpduM_TxInitValues  /**< the pointer to IpduM_TxInitValues */
#define IpduM_GetTxLoInfoOfPCConfig()                                 IpduM_TxLoInfo  /**< the pointer to IpduM_TxLoInfo */
#define IpduM_GetTxPartIndOfPCConfig()                                IpduM_TxPartInd  /**< the pointer to IpduM_TxPartInd */
#define IpduM_GetTxPartOfPCConfig()                                   IpduM_TxPart  /**< the pointer to IpduM_TxPart */
#define IpduM_GetTxPathwayOfPCConfig()                                IpduM_TxPathway  /**< the pointer to IpduM_TxPathway */
#define IpduM_GetTxUpInfoOfPCConfig()                                 IpduM_TxUpInfo  /**< the pointer to IpduM_TxUpInfo */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDuplicatedRootDataMacros  IpduM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define IpduM_GetSizeOfDynamicPduIdxOfPCConfig()                      IpduM_GetSizeOfTxPathwayOfPCConfig()  /**< the number of accomplishable value elements in IpduM_DynamicPduIdx */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDataMacros  IpduM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define IpduM_GetDynamicPduIdx(Index)                                 (IpduM_GetDynamicPduIdxOfPCConfig()[(Index)])
#define IpduM_IsInitialized()                                         ((IpduM_GetInitializedOfPCConfig()) != FALSE)
#define IpduM_GetJitUpdateBuffer(Index)                               (IpduM_GetJitUpdateBufferOfPCConfig()[(Index)])
#define IpduM_GetRxBuffer(Index)                                      (IpduM_GetRxBufferOfPCConfig()[(Index)])
#define IpduM_GetSegmentEndIdxOfRxDynPdu(Index)                       (IpduM_GetRxDynPduOfPCConfig()[(Index)].SegmentEndIdxOfRxDynPdu)
#define IpduM_GetUlPduRefOfRxDynPdu(Index)                            (IpduM_GetRxDynPduOfPCConfig()[(Index)].UlPduRefOfRxDynPdu)
#define IpduM_GetSelectorFieldSubMaskOfRxSelectorPattern(Index)       (IpduM_GetRxSelectorPatternOfPCConfig()[(Index)].SelectorFieldSubMaskOfRxSelectorPattern)
#define IpduM_GetSelectorFieldSubPatternOfRxSelectorPattern(Index)    (IpduM_GetRxSelectorPatternOfPCConfig()[(Index)].SelectorFieldSubPatternOfRxSelectorPattern)
#define IpduM_GetEndByteMaskClearOfSegment(Index)                     (IpduM_GetSegmentOfPCConfig()[(Index)].EndByteMaskClearOfSegment)
#define IpduM_IsFullBytesPresentOfSegment(Index)                      ((IpduM_GetSegmentOfPCConfig()[(Index)].FullBytesPresentOfSegment) != FALSE)
#define IpduM_GetLastFullBytePosOfSegment(Index)                      (IpduM_GetSegmentOfPCConfig()[(Index)].LastFullBytePosOfSegment)
#define IpduM_GetLengthOfSegment(Index)                               (IpduM_GetSegmentOfPCConfig()[(Index)].LengthOfSegment)
#define IpduM_GetStartByteMaskWriteOfSegment(Index)                   (IpduM_GetSegmentOfPCConfig()[(Index)].StartByteMaskWriteOfSegment)
#define IpduM_GetTriggerTransmitBuffer(Index)                         (IpduM_GetTriggerTransmitBufferOfPCConfig()[(Index)])
#define IpduM_GetTxBuffer(Index)                                      (IpduM_GetTxBufferOfPCConfig()[(Index)])
#define IpduM_GetTxConfTimeoutCnt(Index)                              (IpduM_GetTxConfTimeoutCntOfPCConfig()[(Index)])
#define IpduM_GetTxInitValues(Index)                                  (IpduM_GetTxInitValuesOfPCConfig()[(Index)])
#define IpduM_GetPathwayTypeOfTxLoInfo(Index)                         (IpduM_GetTxLoInfoOfPCConfig()[(Index)].PathwayTypeOfTxLoInfo)
#define IpduM_GetMaskedBitsOfTxPart(Index)                            (IpduM_GetTxPartOfPCConfig()[(Index)].MaskedBitsOfTxPart)
#define IpduM_GetSegmentStartIdxOfTxPart(Index)                       (IpduM_GetTxPartOfPCConfig()[(Index)].SegmentStartIdxOfTxPart)
#define IpduM_GetTxPathwayIdxOfTxPart(Index)                          (IpduM_GetTxPartOfPCConfig()[(Index)].TxPathwayIdxOfTxPart)
#define IpduM_GetUlPduRefOfTxPart(Index)                              (IpduM_GetTxPartOfPCConfig()[(Index)].UlPduRefOfTxPart)
#define IpduM_GetTxPartInd(Index)                                     (IpduM_GetTxPartIndOfPCConfig()[(Index)])
#define IpduM_GetLengthOfTxPathway(Index)                             (IpduM_GetTxPathwayOfPCConfig()[(Index)].LengthOfTxPathway)
#define IpduM_GetLlPduRefOfTxPathway(Index)                           (IpduM_GetTxPathwayOfPCConfig()[(Index)].LlPduRefOfTxPathway)
#define IpduM_GetTxBufferIdxOfTxPathway(Index)                        (IpduM_GetTxPathwayOfPCConfig()[(Index)].TxBufferIdxOfTxPathway)
#define IpduM_GetTxPartIndEndIdxOfTxPathway(Index)                    (IpduM_GetTxPathwayOfPCConfig()[(Index)].TxPartIndEndIdxOfTxPathway)
#define IpduM_GetTxPartIndStartIdxOfTxPathway(Index)                  (IpduM_GetTxPathwayOfPCConfig()[(Index)].TxPartIndStartIdxOfTxPathway)
#define IpduM_GetTxPartInitialDynPartIdxOfTxPathway(Index)            (IpduM_GetTxPathwayOfPCConfig()[(Index)].TxPartInitialDynPartIdxOfTxPathway)
#define IpduM_GetUnusedAreasDefaultOfTxPathway(Index)                 (IpduM_GetTxPathwayOfPCConfig()[(Index)].UnusedAreasDefaultOfTxPathway)
#define IpduM_GetPathwayTypeOfTxUpInfo(Index)                         (IpduM_GetTxUpInfoOfPCConfig()[(Index)].PathwayTypeOfTxUpInfo)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetBitDataMacros  IpduM Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define IpduM_IsTriggerEventOfTxPart(Index)                           (IPDUM_TRIGGEREVENTOFTXPART_MASK == (IpduM_GetMaskedBitsOfTxPart(Index) & IPDUM_TRIGGEREVENTOFTXPART_MASK))  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxTriggerMode */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetDeduplicatedDataMacros  IpduM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define IpduM_GetMinDLCOfRxDynPdu(Index)                              ((IpduM_MinDLCOfRxDynPduType)((IpduM_GetSegmentEndIdxOfRxDynPdu(Index) + 7U)))  /**< the minimum DLC derived from the maximum end bit of the related segments. */
#define IpduM_GetRxSelectorPatternEndIdxOfRxDynPdu(Index)             ((IpduM_RxSelectorPatternEndIdxOfRxDynPduType)(((Index) + 1U)))  /**< the end index of the 1:n relation pointing to IpduM_RxSelectorPattern */
#define IpduM_GetRxSelectorPatternStartIdxOfRxDynPdu(Index)           ((IpduM_RxSelectorPatternStartIdxOfRxDynPduType)((Index)))  /**< the start index of the 1:n relation pointing to IpduM_RxSelectorPattern */
#define IpduM_GetSegmentStartIdxOfRxDynPdu(Index)                     ((IpduM_SegmentStartIdxOfRxDynPduType)((IpduM_GetSegmentEndIdxOfRxDynPdu(Index) - 1U)))  /**< the start index of the 1:n relation pointing to IpduM_Segment */
#define IpduM_GetPathwayTypeOfRxInfo(Index)                           ((IpduM_PathwayTypeOfRxInfoType)((Index)))  /**< The type of the pathway. */
#define IpduM_GetRxPathwayIndIdxOfRxInfo(Index)                       ((IpduM_RxPathwayIndIdxOfRxInfoType)((Index)))  /**< the index of the 1:1 relation pointing to one of IpduM_RxMuxPdu,IpduM_RxContainerPdu */
#define IpduM_GetRxDynPduEndIdxOfRxMuxPdu(Index)                      ((IpduM_RxDynPduEndIdxOfRxMuxPduType)(((Index) + 2U)))  /**< the end index of the 1:n relation pointing to IpduM_RxDynPdu */
#define IpduM_GetRxDynPduStartIdxOfRxMuxPdu(Index)                    ((IpduM_RxDynPduStartIdxOfRxMuxPduType)((Index)))  /**< the start index of the 1:n relation pointing to IpduM_RxDynPdu */
#define IpduM_GetRxMuxBufferIdxOfRxMuxPdu(Index)                      ((IpduM_RxMuxBufferIdxOfRxMuxPduType)((Index)))  /**< the bitmask to extract the selector value. */
#define IpduM_GetSelectorFieldBytePositionOfRxMuxPdu(Index)           ((IpduM_SelectorFieldBytePositionOfRxMuxPduType)((Index)))  /**< the byte position of the selector value in the PDU. */
#define IpduM_GetSelectorFieldStartBitOfRxMuxPdu(Index)               ((IpduM_SelectorFieldStartBitOfRxMuxPduType)((Index)))  /**< the bit position of the selector value in the byte position. */
#define IpduM_GetBitInBytePosOfSegment(Index)                         IpduM_GetEndByteMaskClearOfSegment(Index)  /**< the bit position of the segment in the byte position. */
#define IpduM_GetEndByteMaskWriteOfSegment(Index)                     IpduM_GetStartByteMaskWriteOfSegment(Index)  /**< Mask for the partial end byte: writing. */
#define IpduM_GetFirstBytePosOfSegment(Index)                         IpduM_GetEndByteMaskClearOfSegment(Index)  /**< Byte position of the first byte of this segment. */
#define IpduM_GetFirstFullBytePosOfSegment(Index)                     IpduM_GetEndByteMaskClearOfSegment(Index)  /**< Byte position of the first full byte. */
#define IpduM_GetLastBytePosOfSegment(Index)                          IpduM_GetLastFullBytePosOfSegment(Index)  /**< Byte position of the last byte of this segment. */
#define IpduM_GetPduBytePosOfSegment(Index)                           IpduM_GetEndByteMaskClearOfSegment(Index)  /**< the byte position of the segment in the PDU. */
#define IpduM_GetStartByteMaskClearOfSegment(Index)                   IpduM_GetEndByteMaskClearOfSegment(Index)  /**< Mask for the partial start byte: clearing. */
#define IpduM_GetSizeOfDynamicPduIdx()                                IpduM_GetSizeOfDynamicPduIdxOfPCConfig()
#define IpduM_GetSizeOfJitUpdateBuffer()                              IpduM_GetSizeOfJitUpdateBufferOfPCConfig()
#define IpduM_GetSizeOfRxBuffer()                                     IpduM_GetSizeOfRxBufferOfPCConfig()
#define IpduM_GetSizeOfRxDynPdu()                                     IpduM_GetSizeOfRxDynPduOfPCConfig()
#define IpduM_GetSizeOfRxInfo()                                       IpduM_GetSizeOfRxInfoOfPCConfig()
#define IpduM_GetSizeOfRxMuxPdu()                                     IpduM_GetSizeOfRxMuxPduOfPCConfig()
#define IpduM_GetSizeOfRxSelectorPattern()                            IpduM_GetSizeOfRxSelectorPatternOfPCConfig()
#define IpduM_GetSizeOfSegment()                                      IpduM_GetSizeOfSegmentOfPCConfig()
#define IpduM_GetSizeOfTriggerTransmitBuffer()                        IpduM_GetSizeOfTriggerTransmitBufferOfPCConfig()
#define IpduM_GetSizeOfTxBuffer()                                     IpduM_GetSizeOfTxBufferOfPCConfig()
#define IpduM_GetSizeOfTxConfTimeoutCnt()                             IpduM_GetSizeOfTxConfTimeoutCntOfPCConfig()
#define IpduM_GetSizeOfTxInitValues()                                 IpduM_GetSizeOfTxInitValuesOfPCConfig()
#define IpduM_GetSizeOfTxLoInfo()                                     IpduM_GetSizeOfTxLoInfoOfPCConfig()
#define IpduM_GetSizeOfTxPart()                                       IpduM_GetSizeOfTxPartOfPCConfig()
#define IpduM_GetSizeOfTxPartInd()                                    IpduM_GetSizeOfTxPartIndOfPCConfig()
#define IpduM_GetSizeOfTxPathway()                                    IpduM_GetSizeOfTxPathwayOfPCConfig()
#define IpduM_GetSizeOfTxUpInfo()                                     IpduM_GetSizeOfTxUpInfoOfPCConfig()
#define IpduM_GetTxConfTimeoutCntIdxOfTxLoInfo(Index)                 ((IpduM_TxConfTimeoutCntIdxOfTxLoInfoType)((Index)))  /**< the index of the 1:1 relation pointing to IpduM_TxConfTimeoutCnt */
#define IpduM_GetTxPathwayIdxOfTxLoInfo(Index)                        ((IpduM_TxPathwayIdxOfTxLoInfoType)((Index)))  /**< the index of the 0:1 relation pointing to IpduM_TxPathway */
#define IpduM_IsTxPathwayUsedOfTxLoInfo(Index)                        (((boolean)(IpduM_GetTxPathwayIdxOfTxLoInfo(Index) != IPDUM_NO_TXPATHWAYIDXOFTXLOINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to IpduM_TxPathway */
#define IpduM_IsJitUpdateOfTxPart(Index)                              IpduM_IsTriggerEventOfTxPart(Index)  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMJitUpdate or DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart/IpduMJitUpdate */
#define IpduM_GetSegmentEndIdxOfTxPart(Index)                         ((IpduM_SegmentEndIdxOfTxPartType)((IpduM_GetSegmentStartIdxOfTxPart(Index) + 1U)))  /**< the end index of the 1:n relation pointing to IpduM_Segment */
#define IpduM_IsTxConfirmationOfTxPart(Index)                         (((boolean)(IpduM_GetMaskedBitsOfTxPart(Index) == 0x07U)) != FALSE)  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMTxStaticConfirmation or DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart/IpduMTxDynamicConfirmation */
#define IpduM_GetDynamicPduIdxIdxOfTxPathway(Index)                   ((IpduM_DynamicPduIdxIdxOfTxPathwayType)((Index)))  /**< the index of the 1:1 relation pointing to IpduM_DynamicPduIdx */
#define IpduM_GetTxUpIndIdxOfTxUpInfo(Index)                          ((IpduM_TxUpIndIdxOfTxUpInfoType)((Index)))  /**< the index of the 1:1 relation pointing to one of IpduM_TxPart,IpduM_TxContainedPdu */
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSetDataMacros  IpduM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define IpduM_SetDynamicPduIdx(Index, Value)                          IpduM_GetDynamicPduIdxOfPCConfig()[(Index)] = (Value)
#define IpduM_SetInitialized(Value)                                   IpduM_GetInitializedOfPCConfig() = (Value)
#define IpduM_SetJitUpdateBuffer(Index, Value)                        IpduM_GetJitUpdateBufferOfPCConfig()[(Index)] = (Value)
#define IpduM_SetRxBuffer(Index, Value)                               IpduM_GetRxBufferOfPCConfig()[(Index)] = (Value)
#define IpduM_SetTriggerTransmitBuffer(Index, Value)                  IpduM_GetTriggerTransmitBufferOfPCConfig()[(Index)] = (Value)
#define IpduM_SetTxBuffer(Index, Value)                               IpduM_GetTxBufferOfPCConfig()[(Index)] = (Value)
#define IpduM_SetTxConfTimeoutCnt(Index, Value)                       IpduM_GetTxConfTimeoutCntOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCGetAddressOfDataMacros  IpduM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define IpduM_GetAddrJitUpdateBuffer(Index)                           &IpduM_GetJitUpdateBuffer(Index)
#define IpduM_GetAddrRxBuffer(Index)                                  &IpduM_GetRxBuffer(Index)
#define IpduM_GetAddrTriggerTransmitBuffer(Index)                     &IpduM_GetTriggerTransmitBuffer(Index)
#define IpduM_GetAddrTxBuffer(Index)                                  &IpduM_GetTxBuffer(Index)
#define IpduM_GetAddrTxInitValues(Index)                              &IpduM_GetTxInitValues(Index)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCHasMacros  IpduM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define IpduM_HasDynamicPduIdx()                                      (TRUE != FALSE)
#define IpduM_HasInitialized()                                        (TRUE != FALSE)
#define IpduM_HasJitUpdateBuffer()                                    (TRUE != FALSE)
#define IpduM_HasRxBuffer()                                           (TRUE != FALSE)
#define IpduM_HasRxDynPdu()                                           (TRUE != FALSE)
#define IpduM_HasMinDLCOfRxDynPdu()                                   (TRUE != FALSE)
#define IpduM_HasRxSelectorPatternEndIdxOfRxDynPdu()                  (TRUE != FALSE)
#define IpduM_HasRxSelectorPatternStartIdxOfRxDynPdu()                (TRUE != FALSE)
#define IpduM_HasSegmentEndIdxOfRxDynPdu()                            (TRUE != FALSE)
#define IpduM_HasSegmentStartIdxOfRxDynPdu()                          (TRUE != FALSE)
#define IpduM_HasUlPduRefOfRxDynPdu()                                 (TRUE != FALSE)
#define IpduM_HasRxInfo()                                             (TRUE != FALSE)
#define IpduM_HasPathwayTypeOfRxInfo()                                (TRUE != FALSE)
#define IpduM_HasRxPathwayIndIdxOfRxInfo()                            (TRUE != FALSE)
#define IpduM_HasRxMuxPdu()                                           (TRUE != FALSE)
#define IpduM_HasRxDynPduEndIdxOfRxMuxPdu()                           (TRUE != FALSE)
#define IpduM_HasRxDynPduStartIdxOfRxMuxPdu()                         (TRUE != FALSE)
#define IpduM_HasRxMuxBufferIdxOfRxMuxPdu()                           (TRUE != FALSE)
#define IpduM_HasSelectorFieldBytePositionOfRxMuxPdu()                (TRUE != FALSE)
#define IpduM_HasSelectorFieldStartBitOfRxMuxPdu()                    (TRUE != FALSE)
#define IpduM_HasRxSelectorPattern()                                  (TRUE != FALSE)
#define IpduM_HasSelectorFieldSubMaskOfRxSelectorPattern()            (TRUE != FALSE)
#define IpduM_HasSelectorFieldSubPatternOfRxSelectorPattern()         (TRUE != FALSE)
#define IpduM_HasSegment()                                            (TRUE != FALSE)
#define IpduM_HasBitInBytePosOfSegment()                              (TRUE != FALSE)
#define IpduM_HasEndByteMaskClearOfSegment()                          (TRUE != FALSE)
#define IpduM_HasEndByteMaskWriteOfSegment()                          (TRUE != FALSE)
#define IpduM_HasFirstBytePosOfSegment()                              (TRUE != FALSE)
#define IpduM_HasFirstFullBytePosOfSegment()                          (TRUE != FALSE)
#define IpduM_HasFullBytesPresentOfSegment()                          (TRUE != FALSE)
#define IpduM_HasLastBytePosOfSegment()                               (TRUE != FALSE)
#define IpduM_HasLastFullBytePosOfSegment()                           (TRUE != FALSE)
#define IpduM_HasLengthOfSegment()                                    (TRUE != FALSE)
#define IpduM_HasPduBytePosOfSegment()                                (TRUE != FALSE)
#define IpduM_HasStartByteMaskClearOfSegment()                        (TRUE != FALSE)
#define IpduM_HasStartByteMaskWriteOfSegment()                        (TRUE != FALSE)
#define IpduM_HasSizeOfDynamicPduIdx()                                (TRUE != FALSE)
#define IpduM_HasSizeOfJitUpdateBuffer()                              (TRUE != FALSE)
#define IpduM_HasSizeOfRxBuffer()                                     (TRUE != FALSE)
#define IpduM_HasSizeOfRxDynPdu()                                     (TRUE != FALSE)
#define IpduM_HasSizeOfRxInfo()                                       (TRUE != FALSE)
#define IpduM_HasSizeOfRxMuxPdu()                                     (TRUE != FALSE)
#define IpduM_HasSizeOfRxSelectorPattern()                            (TRUE != FALSE)
#define IpduM_HasSizeOfSegment()                                      (TRUE != FALSE)
#define IpduM_HasSizeOfTriggerTransmitBuffer()                        (TRUE != FALSE)
#define IpduM_HasSizeOfTxBuffer()                                     (TRUE != FALSE)
#define IpduM_HasSizeOfTxConfTimeoutCnt()                             (TRUE != FALSE)
#define IpduM_HasSizeOfTxInitValues()                                 (TRUE != FALSE)
#define IpduM_HasSizeOfTxLoInfo()                                     (TRUE != FALSE)
#define IpduM_HasSizeOfTxPart()                                       (TRUE != FALSE)
#define IpduM_HasSizeOfTxPartInd()                                    (TRUE != FALSE)
#define IpduM_HasSizeOfTxPathway()                                    (TRUE != FALSE)
#define IpduM_HasSizeOfTxUpInfo()                                     (TRUE != FALSE)
#define IpduM_HasTriggerTransmitBuffer()                              (TRUE != FALSE)
#define IpduM_HasTxBuffer()                                           (TRUE != FALSE)
#define IpduM_HasTxConfTimeoutCnt()                                   (TRUE != FALSE)
#define IpduM_HasTxInitValues()                                       (TRUE != FALSE)
#define IpduM_HasTxLoInfo()                                           (TRUE != FALSE)
#define IpduM_HasPathwayTypeOfTxLoInfo()                              (TRUE != FALSE)
#define IpduM_HasTxConfTimeoutCntIdxOfTxLoInfo()                      (TRUE != FALSE)
#define IpduM_HasTxPathwayIdxOfTxLoInfo()                             (TRUE != FALSE)
#define IpduM_HasTxPathwayUsedOfTxLoInfo()                            (TRUE != FALSE)
#define IpduM_HasTxPart()                                             (TRUE != FALSE)
#define IpduM_HasJitUpdateOfTxPart()                                  (TRUE != FALSE)
#define IpduM_HasMaskedBitsOfTxPart()                                 (TRUE != FALSE)
#define IpduM_HasSegmentEndIdxOfTxPart()                              (TRUE != FALSE)
#define IpduM_HasSegmentStartIdxOfTxPart()                            (TRUE != FALSE)
#define IpduM_HasTriggerEventOfTxPart()                               (TRUE != FALSE)
#define IpduM_HasTxConfirmationOfTxPart()                             (TRUE != FALSE)
#define IpduM_HasTxPathwayIdxOfTxPart()                               (TRUE != FALSE)
#define IpduM_HasUlPduRefOfTxPart()                                   (TRUE != FALSE)
#define IpduM_HasTxPartInd()                                          (TRUE != FALSE)
#define IpduM_HasTxPathway()                                          (TRUE != FALSE)
#define IpduM_HasDynamicPduIdxIdxOfTxPathway()                        (TRUE != FALSE)
#define IpduM_HasLengthOfTxPathway()                                  (TRUE != FALSE)
#define IpduM_HasLlPduRefOfTxPathway()                                (TRUE != FALSE)
#define IpduM_HasTxBufferIdxOfTxPathway()                             (TRUE != FALSE)
#define IpduM_HasTxPartIndEndIdxOfTxPathway()                         (TRUE != FALSE)
#define IpduM_HasTxPartIndStartIdxOfTxPathway()                       (TRUE != FALSE)
#define IpduM_HasTxPartInitialDynPartIdxOfTxPathway()                 (TRUE != FALSE)
#define IpduM_HasUnusedAreasDefaultOfTxPathway()                      (TRUE != FALSE)
#define IpduM_HasTxUpInfo()                                           (TRUE != FALSE)
#define IpduM_HasPathwayTypeOfTxUpInfo()                              (TRUE != FALSE)
#define IpduM_HasTxUpIndIdxOfTxUpInfo()                               (TRUE != FALSE)
#define IpduM_HasPCConfig()                                           (TRUE != FALSE)
#define IpduM_HasDynamicPduIdxOfPCConfig()                            (TRUE != FALSE)
#define IpduM_HasInitializedOfPCConfig()                              (TRUE != FALSE)
#define IpduM_HasJitUpdateBufferOfPCConfig()                          (TRUE != FALSE)
#define IpduM_HasRxBufferOfPCConfig()                                 (TRUE != FALSE)
#define IpduM_HasRxDynPduOfPCConfig()                                 (TRUE != FALSE)
#define IpduM_HasRxInfoOfPCConfig()                                   (TRUE != FALSE)
#define IpduM_HasRxMuxPduOfPCConfig()                                 (TRUE != FALSE)
#define IpduM_HasRxSelectorPatternOfPCConfig()                        (TRUE != FALSE)
#define IpduM_HasSegmentOfPCConfig()                                  (TRUE != FALSE)
#define IpduM_HasSizeOfDynamicPduIdxOfPCConfig()                      (TRUE != FALSE)
#define IpduM_HasSizeOfJitUpdateBufferOfPCConfig()                    (TRUE != FALSE)
#define IpduM_HasSizeOfRxBufferOfPCConfig()                           (TRUE != FALSE)
#define IpduM_HasSizeOfRxDynPduOfPCConfig()                           (TRUE != FALSE)
#define IpduM_HasSizeOfRxInfoOfPCConfig()                             (TRUE != FALSE)
#define IpduM_HasSizeOfRxMuxPduOfPCConfig()                           (TRUE != FALSE)
#define IpduM_HasSizeOfRxSelectorPatternOfPCConfig()                  (TRUE != FALSE)
#define IpduM_HasSizeOfSegmentOfPCConfig()                            (TRUE != FALSE)
#define IpduM_HasSizeOfTriggerTransmitBufferOfPCConfig()              (TRUE != FALSE)
#define IpduM_HasSizeOfTxBufferOfPCConfig()                           (TRUE != FALSE)
#define IpduM_HasSizeOfTxConfTimeoutCntOfPCConfig()                   (TRUE != FALSE)
#define IpduM_HasSizeOfTxInitValuesOfPCConfig()                       (TRUE != FALSE)
#define IpduM_HasSizeOfTxLoInfoOfPCConfig()                           (TRUE != FALSE)
#define IpduM_HasSizeOfTxPartIndOfPCConfig()                          (TRUE != FALSE)
#define IpduM_HasSizeOfTxPartOfPCConfig()                             (TRUE != FALSE)
#define IpduM_HasSizeOfTxPathwayOfPCConfig()                          (TRUE != FALSE)
#define IpduM_HasSizeOfTxUpInfoOfPCConfig()                           (TRUE != FALSE)
#define IpduM_HasTriggerTransmitBufferOfPCConfig()                    (TRUE != FALSE)
#define IpduM_HasTxBufferOfPCConfig()                                 (TRUE != FALSE)
#define IpduM_HasTxConfTimeoutCntOfPCConfig()                         (TRUE != FALSE)
#define IpduM_HasTxInitValuesOfPCConfig()                             (TRUE != FALSE)
#define IpduM_HasTxLoInfoOfPCConfig()                                 (TRUE != FALSE)
#define IpduM_HasTxPartIndOfPCConfig()                                (TRUE != FALSE)
#define IpduM_HasTxPartOfPCConfig()                                   (TRUE != FALSE)
#define IpduM_HasTxPathwayOfPCConfig()                                (TRUE != FALSE)
#define IpduM_HasTxUpInfoOfPCConfig()                                 (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIncrementDataMacros  IpduM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define IpduM_IncDynamicPduIdx(Index)                                 IpduM_GetDynamicPduIdx(Index)++
#define IpduM_IncJitUpdateBuffer(Index)                               IpduM_GetJitUpdateBuffer(Index)++
#define IpduM_IncRxBuffer(Index)                                      IpduM_GetRxBuffer(Index)++
#define IpduM_IncTriggerTransmitBuffer(Index)                         IpduM_GetTriggerTransmitBuffer(Index)++
#define IpduM_IncTxBuffer(Index)                                      IpduM_GetTxBuffer(Index)++
#define IpduM_IncTxConfTimeoutCnt(Index)                              IpduM_GetTxConfTimeoutCnt(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCDecrementDataMacros  IpduM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define IpduM_DecDynamicPduIdx(Index)                                 IpduM_GetDynamicPduIdx(Index)--
#define IpduM_DecJitUpdateBuffer(Index)                               IpduM_GetJitUpdateBuffer(Index)--
#define IpduM_DecRxBuffer(Index)                                      IpduM_GetRxBuffer(Index)--
#define IpduM_DecTriggerTransmitBuffer(Index)                         IpduM_GetTriggerTransmitBuffer(Index)--
#define IpduM_DecTxBuffer(Index)                                      IpduM_GetTxBuffer(Index)--
#define IpduM_DecTxConfTimeoutCnt(Index)                              IpduM_GetTxConfTimeoutCnt(Index)--
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCIterableTypes  IpduM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate IpduM_JitUpdateBuffer */
typedef uint8_least IpduM_JitUpdateBufferIterType;

/**   \brief  type used to iterate IpduM_RxBuffer */
typedef uint8_least IpduM_RxBufferIterType;

/**   \brief  type used to iterate IpduM_RxDynPdu */
typedef uint8_least IpduM_RxDynPduIterType;

/**   \brief  type used to iterate IpduM_RxInfo */
typedef uint8_least IpduM_RxInfoIterType;

/**   \brief  type used to iterate IpduM_RxMuxPdu */
typedef uint8_least IpduM_RxMuxPduIterType;

/**   \brief  type used to iterate IpduM_RxSelectorPattern */
typedef uint8_least IpduM_RxSelectorPatternIterType;

/**   \brief  type used to iterate IpduM_Segment */
typedef uint8_least IpduM_SegmentIterType;

/**   \brief  type used to iterate IpduM_TriggerTransmitBuffer */
typedef uint8_least IpduM_TriggerTransmitBufferIterType;

/**   \brief  type used to iterate IpduM_TxBuffer */
typedef uint8_least IpduM_TxBufferIterType;

/**   \brief  type used to iterate IpduM_TxConfTimeoutCnt */
typedef uint8_least IpduM_TxConfTimeoutCntIterType;

/**   \brief  type used to iterate IpduM_TxInitValues */
typedef uint8_least IpduM_TxInitValuesIterType;

/**   \brief  type used to iterate IpduM_TxLoInfo */
typedef uint8_least IpduM_TxLoInfoIterType;

/**   \brief  type used to iterate IpduM_TxPart */
typedef uint8_least IpduM_TxPartIterType;

/**   \brief  type used to iterate IpduM_TxPartInd */
typedef uint8_least IpduM_TxPartIndIterType;

/**   \brief  type used to iterate IpduM_TxPathway */
typedef uint8_least IpduM_TxPathwayIterType;

/**   \brief  type used to iterate IpduM_TxUpInfo */
typedef uint8_least IpduM_TxUpInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCIterableTypesWithSizeRelations  IpduM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate IpduM_DynamicPduIdx */
typedef IpduM_TxPathwayIterType IpduM_DynamicPduIdxIterType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCValueTypes  IpduM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for IpduM_DynamicPduIdx */
typedef uint16 IpduM_DynamicPduIdxType;

/**   \brief  value based type definition for IpduM_Initialized */
typedef boolean IpduM_InitializedType;

/**   \brief  value based type definition for IpduM_JitUpdateBuffer */
typedef uint8 IpduM_JitUpdateBufferType;

/**   \brief  value based type definition for IpduM_RxBuffer */
typedef uint8 IpduM_RxBufferType;

/**   \brief  value based type definition for IpduM_MinDLCOfRxDynPdu */
typedef uint8 IpduM_MinDLCOfRxDynPduType;

/**   \brief  value based type definition for IpduM_RxSelectorPatternEndIdxOfRxDynPdu */
typedef uint8 IpduM_RxSelectorPatternEndIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_RxSelectorPatternStartIdxOfRxDynPdu */
typedef uint8 IpduM_RxSelectorPatternStartIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_SegmentEndIdxOfRxDynPdu */
typedef uint8 IpduM_SegmentEndIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_SegmentStartIdxOfRxDynPdu */
typedef uint8 IpduM_SegmentStartIdxOfRxDynPduType;

/**   \brief  value based type definition for IpduM_UlPduRefOfRxDynPdu */
typedef uint8 IpduM_UlPduRefOfRxDynPduType;

/**   \brief  value based type definition for IpduM_PathwayTypeOfRxInfo */
typedef uint8 IpduM_PathwayTypeOfRxInfoType;

/**   \brief  value based type definition for IpduM_RxPathwayIndIdxOfRxInfo */
typedef uint8 IpduM_RxPathwayIndIdxOfRxInfoType;

/**   \brief  value based type definition for IpduM_RxDynPduEndIdxOfRxMuxPdu */
typedef uint8 IpduM_RxDynPduEndIdxOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_RxDynPduStartIdxOfRxMuxPdu */
typedef uint8 IpduM_RxDynPduStartIdxOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_RxMuxBufferIdxOfRxMuxPdu */
typedef uint8 IpduM_RxMuxBufferIdxOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SelectorFieldBytePositionOfRxMuxPdu */
typedef uint8 IpduM_SelectorFieldBytePositionOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SelectorFieldStartBitOfRxMuxPdu */
typedef uint8 IpduM_SelectorFieldStartBitOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SelectorFieldSubMaskOfRxSelectorPattern */
typedef uint8 IpduM_SelectorFieldSubMaskOfRxSelectorPatternType;

/**   \brief  value based type definition for IpduM_SelectorFieldSubPatternOfRxSelectorPattern */
typedef uint8 IpduM_SelectorFieldSubPatternOfRxSelectorPatternType;

/**   \brief  value based type definition for IpduM_BitInBytePosOfSegment */
typedef uint8 IpduM_BitInBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_EndByteMaskClearOfSegment */
typedef uint8 IpduM_EndByteMaskClearOfSegmentType;

/**   \brief  value based type definition for IpduM_EndByteMaskWriteOfSegment */
typedef uint8 IpduM_EndByteMaskWriteOfSegmentType;

/**   \brief  value based type definition for IpduM_FirstBytePosOfSegment */
typedef uint8 IpduM_FirstBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_FirstFullBytePosOfSegment */
typedef uint8 IpduM_FirstFullBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_FullBytesPresentOfSegment */
typedef boolean IpduM_FullBytesPresentOfSegmentType;

/**   \brief  value based type definition for IpduM_LastBytePosOfSegment */
typedef uint8 IpduM_LastBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_LastFullBytePosOfSegment */
typedef uint8 IpduM_LastFullBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_LengthOfSegment */
typedef uint16 IpduM_LengthOfSegmentType;

/**   \brief  value based type definition for IpduM_PduBytePosOfSegment */
typedef uint8 IpduM_PduBytePosOfSegmentType;

/**   \brief  value based type definition for IpduM_StartByteMaskClearOfSegment */
typedef uint8 IpduM_StartByteMaskClearOfSegmentType;

/**   \brief  value based type definition for IpduM_StartByteMaskWriteOfSegment */
typedef uint8 IpduM_StartByteMaskWriteOfSegmentType;

/**   \brief  value based type definition for IpduM_SizeOfDynamicPduIdx */
typedef uint8 IpduM_SizeOfDynamicPduIdxType;

/**   \brief  value based type definition for IpduM_SizeOfJitUpdateBuffer */
typedef uint8 IpduM_SizeOfJitUpdateBufferType;

/**   \brief  value based type definition for IpduM_SizeOfRxBuffer */
typedef uint8 IpduM_SizeOfRxBufferType;

/**   \brief  value based type definition for IpduM_SizeOfRxDynPdu */
typedef uint8 IpduM_SizeOfRxDynPduType;

/**   \brief  value based type definition for IpduM_SizeOfRxInfo */
typedef uint8 IpduM_SizeOfRxInfoType;

/**   \brief  value based type definition for IpduM_SizeOfRxMuxPdu */
typedef uint8 IpduM_SizeOfRxMuxPduType;

/**   \brief  value based type definition for IpduM_SizeOfRxSelectorPattern */
typedef uint8 IpduM_SizeOfRxSelectorPatternType;

/**   \brief  value based type definition for IpduM_SizeOfSegment */
typedef uint8 IpduM_SizeOfSegmentType;

/**   \brief  value based type definition for IpduM_SizeOfTriggerTransmitBuffer */
typedef uint8 IpduM_SizeOfTriggerTransmitBufferType;

/**   \brief  value based type definition for IpduM_SizeOfTxBuffer */
typedef uint8 IpduM_SizeOfTxBufferType;

/**   \brief  value based type definition for IpduM_SizeOfTxConfTimeoutCnt */
typedef uint8 IpduM_SizeOfTxConfTimeoutCntType;

/**   \brief  value based type definition for IpduM_SizeOfTxInitValues */
typedef uint8 IpduM_SizeOfTxInitValuesType;

/**   \brief  value based type definition for IpduM_SizeOfTxLoInfo */
typedef uint8 IpduM_SizeOfTxLoInfoType;

/**   \brief  value based type definition for IpduM_SizeOfTxPart */
typedef uint8 IpduM_SizeOfTxPartType;

/**   \brief  value based type definition for IpduM_SizeOfTxPartInd */
typedef uint8 IpduM_SizeOfTxPartIndType;

/**   \brief  value based type definition for IpduM_SizeOfTxPathway */
typedef uint8 IpduM_SizeOfTxPathwayType;

/**   \brief  value based type definition for IpduM_SizeOfTxUpInfo */
typedef uint8 IpduM_SizeOfTxUpInfoType;

/**   \brief  value based type definition for IpduM_TriggerTransmitBuffer */
typedef uint8 IpduM_TriggerTransmitBufferType;

/**   \brief  value based type definition for IpduM_TxBuffer */
typedef uint8 IpduM_TxBufferType;

/**   \brief  value based type definition for IpduM_TxConfTimeoutCnt */
typedef uint16 IpduM_TxConfTimeoutCntType;

/**   \brief  value based type definition for IpduM_TxInitValues */
typedef uint8 IpduM_TxInitValuesType;

/**   \brief  value based type definition for IpduM_PathwayTypeOfTxLoInfo */
typedef uint8 IpduM_PathwayTypeOfTxLoInfoType;

/**   \brief  value based type definition for IpduM_TxConfTimeoutCntIdxOfTxLoInfo */
typedef uint8 IpduM_TxConfTimeoutCntIdxOfTxLoInfoType;

/**   \brief  value based type definition for IpduM_TxPathwayIdxOfTxLoInfo */
typedef uint8 IpduM_TxPathwayIdxOfTxLoInfoType;

/**   \brief  value based type definition for IpduM_TxPathwayUsedOfTxLoInfo */
typedef boolean IpduM_TxPathwayUsedOfTxLoInfoType;

/**   \brief  value based type definition for IpduM_JitUpdateOfTxPart */
typedef boolean IpduM_JitUpdateOfTxPartType;

/**   \brief  value based type definition for IpduM_MaskedBitsOfTxPart */
typedef uint8 IpduM_MaskedBitsOfTxPartType;

/**   \brief  value based type definition for IpduM_SegmentEndIdxOfTxPart */
typedef uint8 IpduM_SegmentEndIdxOfTxPartType;

/**   \brief  value based type definition for IpduM_SegmentStartIdxOfTxPart */
typedef uint8 IpduM_SegmentStartIdxOfTxPartType;

/**   \brief  value based type definition for IpduM_TriggerEventOfTxPart */
typedef boolean IpduM_TriggerEventOfTxPartType;

/**   \brief  value based type definition for IpduM_TxConfirmationOfTxPart */
typedef boolean IpduM_TxConfirmationOfTxPartType;

/**   \brief  value based type definition for IpduM_TxPathwayIdxOfTxPart */
typedef uint8 IpduM_TxPathwayIdxOfTxPartType;

/**   \brief  value based type definition for IpduM_UlPduRefOfTxPart */
typedef uint8 IpduM_UlPduRefOfTxPartType;

/**   \brief  value based type definition for IpduM_TxPartInd */
typedef uint8 IpduM_TxPartIndType;

/**   \brief  value based type definition for IpduM_DynamicPduIdxIdxOfTxPathway */
typedef uint8 IpduM_DynamicPduIdxIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_LengthOfTxPathway */
typedef uint8 IpduM_LengthOfTxPathwayType;

/**   \brief  value based type definition for IpduM_LlPduRefOfTxPathway */
typedef uint8 IpduM_LlPduRefOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxBufferIdxOfTxPathway */
typedef uint8 IpduM_TxBufferIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartIndEndIdxOfTxPathway */
typedef uint8 IpduM_TxPartIndEndIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartIndStartIdxOfTxPathway */
typedef uint8 IpduM_TxPartIndStartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_TxPartInitialDynPartIdxOfTxPathway */
typedef uint8 IpduM_TxPartInitialDynPartIdxOfTxPathwayType;

/**   \brief  value based type definition for IpduM_UnusedAreasDefaultOfTxPathway */
typedef uint8 IpduM_UnusedAreasDefaultOfTxPathwayType;

/**   \brief  value based type definition for IpduM_PathwayTypeOfTxUpInfo */
typedef uint8 IpduM_PathwayTypeOfTxUpInfoType;

/**   \brief  value based type definition for IpduM_TxUpIndIdxOfTxUpInfo */
typedef uint8 IpduM_TxUpIndIdxOfTxUpInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  IpduMPCStructTypes  IpduM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in IpduM_RxDynPdu */
typedef struct sIpduM_RxDynPduType
{
  IpduM_SegmentEndIdxOfRxDynPduType SegmentEndIdxOfRxDynPdu;  /**< the end index of the 1:n relation pointing to IpduM_Segment */
  IpduM_UlPduRefOfRxDynPduType UlPduRefOfRxDynPdu;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMOutgoingDynamicPduRef */
} IpduM_RxDynPduType;

/**   \brief  type used in IpduM_RxInfo */
typedef struct sIpduM_RxInfoType
{
  uint8 IpduM_RxInfoNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} IpduM_RxInfoType;

/**   \brief  type used in IpduM_RxMuxPdu */
typedef struct sIpduM_RxMuxPduType
{
  uint8 IpduM_RxMuxPduNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} IpduM_RxMuxPduType;

/**   \brief  type used in IpduM_RxSelectorPattern */
typedef struct sIpduM_RxSelectorPatternType
{
  IpduM_SelectorFieldSubMaskOfRxSelectorPatternType SelectorFieldSubMaskOfRxSelectorPattern;  /**< One byte of the mask the pattern is masked with for the selector field as it is transmitted. */
  IpduM_SelectorFieldSubPatternOfRxSelectorPatternType SelectorFieldSubPatternOfRxSelectorPattern;  /**< One byte of the masked pattern for the selector field as it is transmitted - calculated from position and length. */
} IpduM_RxSelectorPatternType;

/**   \brief  type used in IpduM_Segment */
typedef struct sIpduM_SegmentType
{
  IpduM_LengthOfSegmentType LengthOfSegment;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMSegment/IpduMSegmentLength. */
  IpduM_FullBytesPresentOfSegmentType FullBytesPresentOfSegment;  /**< True if full bytes exist in this segment. */
  IpduM_EndByteMaskClearOfSegmentType EndByteMaskClearOfSegment;  /**< Mask for the partial end byte: clearing. */
  IpduM_LastFullBytePosOfSegmentType LastFullBytePosOfSegment;  /**< Byte position of the last full byte. */
  IpduM_StartByteMaskWriteOfSegmentType StartByteMaskWriteOfSegment;  /**< Mask for the partial start byte: writing. */
} IpduM_SegmentType;

/**   \brief  type used in IpduM_TxLoInfo */
typedef struct sIpduM_TxLoInfoType
{
  IpduM_PathwayTypeOfTxLoInfoType PathwayTypeOfTxLoInfo;  /**< The type of the pathway. */
} IpduM_TxLoInfoType;

/**   \brief  type used in IpduM_TxPart */
typedef struct sIpduM_TxPartType
{
  IpduM_MaskedBitsOfTxPartType MaskedBitsOfTxPart;  /**< contains bitcoded the boolean data of IpduM_JitUpdateOfTxPart, IpduM_TriggerEventOfTxPart, IpduM_TxConfirmationOfTxPart */
  IpduM_SegmentStartIdxOfTxPartType SegmentStartIdxOfTxPart;  /**< the start index of the 1:n relation pointing to IpduM_Segment */
  IpduM_TxPathwayIdxOfTxPartType TxPathwayIdxOfTxPart;  /**< the index of the 1:1 relation pointing to IpduM_TxPathway */
  IpduM_UlPduRefOfTxPartType UlPduRefOfTxPart;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMTxStaticPduRef or DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart/IpduMTxDynamicPduRef */
} IpduM_TxPartType;

/**   \brief  type used in IpduM_TxPathway */
typedef struct sIpduM_TxPathwayType
{
  IpduM_LengthOfTxPathwayType LengthOfTxPathway;  /**< the DefinitionRef: /[ANY]/EcuC/EcucPduCollection/Pdu/PduLength */
  IpduM_LlPduRefOfTxPathwayType LlPduRefOfTxPathway;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMOutgoingPduRef */
  IpduM_TxBufferIdxOfTxPathwayType TxBufferIdxOfTxPathway;  /**< the tx buffer index of the IpduMTxPathway. */
  IpduM_TxPartIndEndIdxOfTxPathwayType TxPartIndEndIdxOfTxPathway;  /**< the end index of the 1:n relation pointing to IpduM_TxPartInd */
  IpduM_TxPartIndStartIdxOfTxPathwayType TxPartIndStartIdxOfTxPathway;  /**< the start index of the 1:n relation pointing to IpduM_TxPartInd */
  IpduM_TxPartInitialDynPartIdxOfTxPathwayType TxPartInitialDynPartIdxOfTxPathway;  /**< the index of the 1:1 relation pointing to IpduM_TxPart */
  IpduM_UnusedAreasDefaultOfTxPathwayType UnusedAreasDefaultOfTxPathway;  /**< the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMIPduUnusedAreasDefault */
} IpduM_TxPathwayType;

/**   \brief  type used in IpduM_TxUpInfo */
typedef struct sIpduM_TxUpInfoType
{
  IpduM_PathwayTypeOfTxUpInfoType PathwayTypeOfTxUpInfo;  /**< The type of the pathway. */
} IpduM_TxUpInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCSymbolicStructTypes  IpduM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to IpduM_DynamicPduIdx */
typedef struct IpduM_DynamicPduIdxStructSTag
{
  IpduM_DynamicPduIdxType pduTrig_FR_DBG_EPS_55c86d41[1];
  IpduM_DynamicPduIdxType pduTrig_SVC_fbd80461_Out[1];
} IpduM_DynamicPduIdxStructSType;

/**   \brief  type to be used as symbolic data element access to IpduM_TxConfTimeoutCnt */
typedef struct IpduM_TxConfTimeoutCntStructSTag
{
  IpduM_TxConfTimeoutCntType pduTrig_FR_DBG_EPS_55c86d41[1];
  IpduM_TxConfTimeoutCntType pduTrig_SVC_fbd80461_Out[1];
} IpduM_TxConfTimeoutCntStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCUnionIndexAndSymbolTypes  IpduM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access IpduM_DynamicPduIdx in an index and symbol based style. */
typedef union IpduM_DynamicPduIdxUTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  IpduM_DynamicPduIdxType raw[2];
  IpduM_DynamicPduIdxStructSType str;
} IpduM_DynamicPduIdxUType;

/**   \brief  type to access IpduM_TxConfTimeoutCnt in an index and symbol based style. */
typedef union IpduM_TxConfTimeoutCntUTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  IpduM_TxConfTimeoutCntType raw[2];
  IpduM_TxConfTimeoutCntStructSType str;
} IpduM_TxConfTimeoutCntUType;

/** 
  \}
*/ 

/** 
  \defgroup  IpduMPCRootValueTypes  IpduM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in IpduM_PCConfig */
typedef struct sIpduM_PCConfigType
{
  uint8 IpduM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} IpduM_PCConfigType;

typedef IpduM_PCConfigType IpduM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  IpduM_RxDynPdu
**********************************************************************************************************************/
/** 
  \var    IpduM_RxDynPdu
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart
  \details
  Element          Description
  SegmentEndIdx    the end index of the 1:n relation pointing to IpduM_Segment
  UlPduRef         the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMOutgoingDynamicPduRef
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_RxDynPduType, IPDUM_CONST) IpduM_RxDynPdu[2];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxSelectorPattern
**********************************************************************************************************************/
/** 
  \var    IpduM_RxSelectorPattern
  \brief  Selector patterns for single- and multi-byte selector value matching. This table is sorted for ascending byte number within one DynPdu.
  \details
  Element                    Description
  SelectorFieldSubMask       One byte of the mask the pattern is masked with for the selector field as it is transmitted.
  SelectorFieldSubPattern    One byte of the masked pattern for the selector field as it is transmitted - calculated from position and length.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_RxSelectorPatternType, IPDUM_CONST) IpduM_RxSelectorPattern[2];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Segment
**********************************************************************************************************************/
/** 
  \var    IpduM_Segment
  \brief  all IpduMSegments
  \details
  Element               Description
  Length                the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMSegment/IpduMSegmentLength.
  FullBytesPresent      True if full bytes exist in this segment.
  EndByteMaskClear      Mask for the partial end byte: clearing.
  LastFullBytePos       Byte position of the last full byte.
  StartByteMaskWrite    Mask for the partial start byte: writing.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_SegmentType, IPDUM_CONST) IpduM_Segment[2];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxInitValues
**********************************************************************************************************************/
/** 
  \var    IpduM_TxInitValues
  \brief  Initial values for tx buffer.
*/ 
#define IPDUM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_TxInitValuesType, IPDUM_CONST) IpduM_TxInitValues[140];
#define IPDUM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxLoInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_TxLoInfo
  \brief  all DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainerTxPdu with DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxConfirmationPduId
  \details
  Element        Description
  PathwayType    The type of the pathway.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_TxLoInfoType, IPDUM_CONST) IpduM_TxLoInfo[2];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxPart
**********************************************************************************************************************/
/** 
  \var    IpduM_TxPart
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart
  \details
  Element            Description
  MaskedBits         contains bitcoded the boolean data of IpduM_JitUpdateOfTxPart, IpduM_TriggerEventOfTxPart, IpduM_TxConfirmationOfTxPart
  SegmentStartIdx    the start index of the 1:n relation pointing to IpduM_Segment
  TxPathwayIdx       the index of the 1:1 relation pointing to IpduM_TxPathway
  UlPduRef           the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart/IpduMTxStaticPduRef or DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart/IpduMTxDynamicPduRef
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_TxPartType, IPDUM_CONST) IpduM_TxPart[5];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxPartInd
**********************************************************************************************************************/
/** 
  \var    IpduM_TxPartInd
  \brief  the indexes of the 1:1 sorted relation pointing to IpduM_TxPart
*/ 
#define IPDUM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_TxPartIndType, IPDUM_CONST) IpduM_TxPartInd[5];
#define IPDUM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxPathway
**********************************************************************************************************************/
/** 
  \var    IpduM_TxPathway
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway
  \details
  Element                    Description
  Length                     the DefinitionRef: /[ANY]/EcuC/EcucPduCollection/Pdu/PduLength
  LlPduRef                   the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMOutgoingPduRef
  TxBufferIdx                the tx buffer index of the IpduMTxPathway.
  TxPartIndEndIdx            the end index of the 1:n relation pointing to IpduM_TxPartInd
  TxPartIndStartIdx          the start index of the 1:n relation pointing to IpduM_TxPartInd
  TxPartInitialDynPartIdx    the index of the 1:1 relation pointing to IpduM_TxPart
  UnusedAreasDefault         the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMIPduUnusedAreasDefault
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_TxPathwayType, IPDUM_CONST) IpduM_TxPathway[2];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxUpInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_TxUpInfo
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxDynamicPart, DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMTxPathway/IpduMTxRequest/IpduMTxStaticPart, DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainedTxPdu for transmission.
  \details
  Element        Description
  PathwayType    The type of the pathway.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(IpduM_TxUpInfoType, IPDUM_CONST) IpduM_TxUpInfo[5];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_DynamicPduIdx
**********************************************************************************************************************/
/** 
  \var    IpduM_DynamicPduIdx
  \brief  records the last transmission requested of a dynamic part.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(IpduM_DynamicPduIdxUType, IPDUM_VAR_NOINIT) IpduM_DynamicPduIdx;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define IPDUM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Initialized
**********************************************************************************************************************/
/** 
  \var    IpduM_Initialized
  \brief  Initialization state of the IpduM. TRUE, if IpduM_Init() has been called, else FALSE.
*/ 
#define IPDUM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(IpduM_InitializedType, IPDUM_VAR_ZERO_INIT) IpduM_Initialized;
#define IPDUM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_JitUpdateBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_JitUpdateBuffer
  \brief  buffer for updating a PDU by just-in-time update initiated by upper layer transmission.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(IpduM_JitUpdateBufferType, IPDUM_VAR_NOINIT) IpduM_JitUpdateBuffer[140];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_RxBuffer
  \brief  buffer to de-multiplex and forward RX static and dynamic parts from the received multiplex I-PDU.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(IpduM_RxBufferType, IPDUM_VAR_NOINIT) IpduM_RxBuffer[8];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TriggerTransmitBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_TriggerTransmitBuffer
  \brief  buffer for updating a PDU by just-in-time update initiated by lower layer triggered transmission.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(IpduM_TriggerTransmitBufferType, IPDUM_VAR_NOINIT) IpduM_TriggerTransmitBuffer[140];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_TxBuffer
  \brief  buffer to multiplex and forward static and dynamic TX parts whose transmission is requested.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(IpduM_TxBufferType, IPDUM_VAR_NOINIT) IpduM_TxBuffer[140];
#define IPDUM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_TxConfTimeoutCnt
**********************************************************************************************************************/
/** 
  \var    IpduM_TxConfTimeoutCnt
  \brief  I-PDU based TX confirmation timeout counters.
*/ 
#define IPDUM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(IpduM_TxConfTimeoutCntUType, IPDUM_VAR_NOINIT) IpduM_TxConfTimeoutCnt;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define IPDUM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* IPDUM_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: IpduM_Lcfg.h
**********************************************************************************************************************/

