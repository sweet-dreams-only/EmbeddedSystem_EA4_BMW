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
 *        \file    FrTp.h
 *        \brief   Header file of the FrTp main-module.
 *
 *        \details Declares all API functions of the FrTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Knut Winkelbach               Wnk           Vctr Informatik GmbH
 *  Klaus Bergdolt                Ber           Vctr Informatik GmbH
 *  Oliver Reineke                Ore           Vctr Informatik GmbH
 *  Patrick Junger                Pju           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2008-07-08  Wnk     n/a           Initial creation
 *  01.00.01  2008-08-19  Wnk     n/a           Concurrent Rx/Tx now possible, fixed CFEOB + LF, 
 *                                              Fixed pending TxConfirmation Pdu-administration
 *  01.00.02  2008-08-21  Wnk     n/a           Fixed CFEOB decision in case CFEOB exactly fills the remaining
 *                                              Rx-buffer
 *  01.00.03  2008-08-25  Wnk     n/a           Fixed assembly of FC frames (BfS) and tracking of remaining bytes
 *  01.00.04  2008-08-26  Wnk     n/a           Corrected internal Blocksize handling (Rx-RemainingDataBytes)
 *  01.00.05  2008-09-01  Wnk     n/a           Added support for INVALID_FS
 *  01.00.06  2008-09-02  Wnk     n/a           Integration with GENy-Generator-made GenData
 *  01.00.07  2008-09-04  Wnk     n/a           Moved implementation of TOS and LC from GENy-tool to embedded component
 *                                              Fixed indication to application for invalid STFUnseg (FPL > ML)
 *  01.00.08  2008-09-05  Wnk     n/a           Fixed number of WFT in case RxBufferProvision returns BUFREQ_E_BUSY
 *                                              Fixed dead RxChannel after max. number of RxBuffer requests
 *                                              Support instanceID in function FrTp
 *  01.00.09  2008-09-05  Wnk     n/a           New release because of new GENy-component (Had to change GUI) 
 *                                              Corrected _RELEASE_VERSION-information (was 0x00, had to be 0x09) 
 *                                              Corrected _AR_ version info for FrTp_GetVersionInfo (has to be 2.2.0)
 *  01.00.10  2008-09-17  Ber     n/a           Fixed compilation problems on S12X/COSMIC
 *  01.01.00  2008-10-08  Wnk     ESCAN00030527 Corrected wrong influence of STmin onto CF-frameType CF_EOB
 *                                ESCAN00030378 FrTp_GetVersionInfo shall _not_ return BCD coded version numbers
 *                                ESCAN00030286 Removed "reason" internally from transmit cancellation mechanism
 *            2008-10-23  Wnk     ESCAN00030287 Corrected missing confirmation after changing parameter values
 *                                ESCAN00030672 Corrected compiler errors in case of single-channel-optimiziation
 *  01.02.00  2008-10-28  Wnk     ESCAN00030941, ESCAN00031781 Corrected compiler errors in case of "multi purpose tp"
 *                                Continued implementation of ACKRT-feature
 *            2008-11-12  Wnk     Applied Vector AUTOSAR subset of MISRA 2004
 *                                ESCAN00031409 Removed unused variables (also during MISRA)                
 *            2008-11-13  Wnk     ESCAN00031276 Incorrect start/stop memmap leads to compiler errors in MemMap.h
 *            2008-11-19  Wnk     ESCAN00031407 Lock RxIndication/TxConfirmation to not be issued before BufferRequest
 *            2008-12-04  Wnk     ESCAN00032116 64kByte Message Length
   *                                ESCAN00032117 Removal of TOS and LC
 *                                ESCAN00032118 Use of BC instead of STMin
 *            2009-01-09  Wnk     n/a           Incorporated results of code inspection
 *                                ESCAN00030268 PreCompile and Linktime Crc Check
 *                                ESCAN00032312 Tp_Iso10681 will continue asking for TxBuffer in case application 
 *                                              indicates an invalid length and buffer-status combination
 *            2009-01-14  Wnk     ESCAN00032385 Tp_Iso10681 asks 1x too few for buffer and then uses wrong RxIndication
 *                                ESCAN00032390 Tp_Iso10681 does not show reactions demanded by ISO after ML mismatch
 *                                ESCAN00030289 Incorrect handling of unexpected arrival of a last frame
 *                                ESCAN00031801 Many 1:n STFs prevent answering to diagnostic requests on 1:1 channels
 *                                ESCAN00030147 Incorrect error handling of unexpected arrival of a consecutive frame
 *  01.03.00  2009-01-22  Wnk     n/a           Fixed Tp_Iso10681_MemMap.inc
 *                                n/a           Fixed check of TP_ISO10681_SW_MINOR_VERSION
 *  01.04.00  2009-01-28  Wnk     ESCAN00032553 Rx-Buffer handling for receiver-application returning BUFREQ_E_NOT_OK
 *                                ESCAN00032581 Editorial: Removal of unused function FrTp_TxCheckSliceForNxtFrame
 *  01.05.00  2009-01-28  Wnk     ESCAN00032577 Failed change of BC-Values
 *                                n/a           Corrected revision history above, where ES CAN 000 30289, 
 *                                              ES CAN 000 31801 and ES CAN 000 30147 were missing
 *  01.06.00  2009-01-30  Wnk     ESCAN00032691 Multiple Txns may have bad performance in case of a channels PPC limits
 *            2009-02-24  Wnk     ESCAN00033065 FrTp_Transmit() rejects in case connection is active _receiving_
 *                                ESCAN00033791 AckRt (straight forward cases)
 *                                ESCAN00033671 Version shall be BCD coded
 *            2009-02-27  Wnk     ESCAN00033457 Compiler warnings in FrTp_TxSm_HandleFC(), FrTp_FrIf_RxIndication()
 *            2009-03-16  Wnk     ESCAN00033434 Not all pointers in embedded code supported compiler abstraction
 *            2009-03-19  Wnk     ESCAN00034007 FrTp_GetVersionInfo shall not check the initstate of the FrTp component
 *                                ESCAN00034089 Call of the FrTpTransmit(X) fails when reception is active in conn X
 *            2009-03-27  Wnk     ESCAN00034139 Segm. Txn. fails with FrTpTxConf(FRIF_ERROR) in CAN-FR-TP-GW use-case
 *                                ESCAN00034213 pduLen is unnecessarily calculated in FrTp_TxSm_CopyTxData
 *            2009-03-28  Wnk     ESCAN00034039 Removed compiler warnings at the extended version checks in FrTp_Init
 *                                ESCAN00034033 Include Lcfg.h and Pbcfg.h only when FrTp_Init has no config pointer
 *  01.07.00  2009-03-30  Wnk     ESCAN00034254 In case Tx or Rx is ended unsucessfully Tp_Iso10681 causes Ecu to hang
 *                                ESCAN00034247 Wrong compiler abstr.of pApplPduInfo pointer (should be AUTOMATIC)
 *  01.08.00  2009-04-02  Wnk     ESCAN00034337 Compile Error: ";" missing: due to diff.integr.environment in testbench
 *  01.09.00  2009-04-03  Wnk     n/a           New release
 *  01.10.00  2009-05-18  Wnk     ESCAN00035261 No LF is sent in case last CF is completely full and LF would be empty
 *            2009-05-26  Wnk     ESCAN00035362 Codesize: Single ConnCtrl+TxPduPool, Variant Precomp., Have decoup.Tx.
 *                                E SCA N00034192 FrIf-retry not disabled: Segm.Txn fails w. FRTP_NTFRSLT_E_FR_FRIF_ERROR
 *                                ESCAN00035729 FrIf-retry not independent of Buffer-Requests
 *            2009-05-28  Wnk     ESCAN00035412 TimeBuffer is not obeyed
 *            2009-06-15  Wnk     ESCAN00035718 Support AUTOSAR 4.0 Prototype of FrTp_TriggerTransmit
 *            2009-06-17  Wnk     ESCAN00033584 Implement the signatures of FrTp callback functions acc. to AUTOSAR 4.0
 *            2009-06-29  Wnk     ESCAN00036026 DET assertion prevents use of complete group of decoupled FrIf-TxPdus
 *                                Corrected rev. history in order to the following ES CANs in here - no change in code!
 *                                ESCAN00034259 Compiler Err. possible: Missing comp. abstr. for PduInfoPtr parameter.
 *                                ESCAN00036051 No error: Compiler Warnings in Tp_Iso10681.c
 *                                and in order to remove these ES CANs: 31285, 30984
 *            2009-07-03  Wnk     MISRA check + added PRQA comments
 *            2009-07-03  Wnk     ESCAN00036131 pre-processor checks for building the library
 *            2009-07-04  Wnk     MISRA check + added PRQA comments + Incorporated review results
 *  01.11.00  2009-08-04  Wnk     ESCAN00036363 Invalid memory access in FrTp_Init
 *            2009-08-10  Wnk     ESCAN00036964 Compiler Warnings in *Cbk.h due to missing inclusion of *Cfg.h
 *  01.12.00  2009-09-18  Wnk     First RC for Release R8
 *            2009-10-12  Wnk     Renamed non-disjunctive to overlapping Tx-Pdu-Pools
 *            2009-10-28  Wnk     ESCAN00038639 Support FrIf_Transmit with E_PENDING
 *            2009-11-09  Wnk     ESCAN00039021 Features extended version and lib check cause probls on some compilers
 *            2009-11-18  Wnk     ESCAN00037120 Code Size Optimization by disabling segmented transmission
 *                                ESCAN00037155 Preprocessor makros to measure runtimes and interrupt locking times
 *                                ESCAN00037119 Variant where FrTp_Shutdown, FrTp_ChangeParameter are disabled
 *                                ESCAN00037111 Ext. BW Ctrl I: AUTOSAR 4.0 feature "Non-disjunctive Tx-Pdu-Pools"
 *                                ESCAN00037112 Ext. BW Ctrl II: Use new AUTOSAR 4.0 param "FrTpBandwidthLimitation"
 *                                ESCAN00037117 Single Tx Pdu Per Pool Optimization
 *                                ESCAN00037118 Single Tx Pdu Optimization as ext. of Single Tx Pdu Pool Optimization
 *                                ESCAN00035707 Similar DET Usage in embedded code
 *                                ESCAN00034002 Request the retry of txn by rxing awaited CF2 w/o SN errs
 *                                ESCAN00033437 ML/FPL Error Handling for acknowledged known message transmission
 *                                ESCAN00034001 Switching consecutive frames does not work correctly
 *                                ESCAN00038762 Change signatures of FrTp callback funcs acc. AUTOSAR 4.0
 *                                ESCAN00038612 Remove TP_ISO10681_HAVE_ONE_CONN_CTRL_AND_HAVE_ACKRT_PRECOMPILE
 *            2009-12-01  Wnk     Incorporated review results
 *            2009-12-04  Wnk     Corrected review result implementation
 *            2010-02-26  Wnk     ESCAN00040136 Selection of prototype of FrTp_Init by preprocessor switch
 *  01.12.01  2010-04-16  Wnk     ESCAN00042326 Memory curruption of adjacent components (V850, GHS 5.1.6, -O, -OSpace)
 *  01.13.00  2010-02-17  Wnk     ESCAN00040811 wrong "component version" define
 *                                ESCAN00040407 Speed up RX of unsegm. STF by getting buffer & RxIndicating all at once
 *            2010-02-26  Wnk     ESCAN00040302 Switch Parameters SCexp, MNCP at runtime by FrTp_ChangeParameter
 *            2010-03-19  Wnk     ESCAN00034201 Add support for multiple configuration 
 *            2010-04-10  Wnk     ESCAN00042326 Memory curruption of adjacent components (V850, GHS 5.1.6, -O, -OSpace)
 *            2010-04-15  Wnk     ESCAN00042239 Introducd.supp.to accept slow,runtime-intense CF_EOB before LF w 0 byte
 *                                ESCAN00036858 Usage of >127 channels.leads 2 malfunction due incorrect memory access
 *            2010-05-04  Wnk     MISRA Check + correction of revision history
 *            2010-05-06  Wnk     Applied review results
 *  01.14.00  2010-05-20  Wnk     ESCAN00043098 Ask for Rx-Buffer space fast & twice after STF-segm for fast TP-Routing
 *            2010-08-18  Wnk     ESCAN00044776 Crit.sect. in FrTp_TriggerTransmit() now symmetric / correct.
 *  01.14.01  2010-12-17  Wnk     ESCAN00047755 After FC with BfS '0' the FrTp as sender uses CF_EOB in the 
 *                                              transmission which contradicts to ISO10681-2 in one part
 *  01.14.02  2010-12-21  Wnk     ESCAN00047820 MNPC counter is not reset properly at sender in case FC.CTS with 
 *                                              MNPC != 0 is sent by receiver
 *  01.14.03  2010-12-20  Wnk     ESCAN00047964 Speed up reception of CFs to free chunk earlier in PduR
 *                                ESCAN00047963 Speed up buffer retrieval of after FC.CTS to free chunk earlier in PduR
 *                                              Both E SCA Ns triggered by TP_ISO10681_HAVE_FAST_BUF_RETRIEVAL
 *  01.15.00  2010-11-25  Wnk     ESCAN00047182 Rxn of CF-Frames fastened up by copying data to PduR in IRQ context
 *                                ESCAN00047172 Adapt AUTOSAR version check
 *            2010-12-01  Wnk     ESCAN00047308 Adapt MainFunction for usage with IdentityManagerConfig
 *            2010-12-14  Wnk     ESCAN00045618 Removed: Compiler warnings: condition is always true
 *            2011-01-20  Wnk     ESCAN00048129 Compiler errors in FrIf in case dec. txn 'off' & Asr4 FrTp-Cbks 'on'
 *            2011-01-25  Wnk     ESCAN00048193 Compiler warning: possible redundant expression
 *            2011-01-26  Wnk     ESCAN00048219 Pointer FrTpIso_CfgPtr in Tp_Iso10681_Lcfg.h has wrong memory qualifier for area it's pointing to (should be PbCfgRoot)
 *            2011-02-02  Wnk     ESCAN00048142 Compiler warning: statement is unreachable
 *                                ESCAN00048374 Compile error due redefinition of  prototype of FrTp_TriggerTransmit
 *            2011-02-03  Wnk     ESCAN00048404 SCexp given by receivers FC will be violated in case NUM(TxPdus) < MNPC
 *                                ESCAN00048436 Internal ConnIdx limit of uint8 leads to inter-connective disturbance
 *            2011-02-07  Wnk     ESCAN00048484 Unsegm. STFrames are not ignored in variant ASR4 FrIf callbacks
 *            2011-02-16  Wnk     ESCAN00048570 Support AckRt without CF_EOBs when FC with BfS '0' is signalled
 *            2011-05-02  Wnk     ESCAN00050552 PduR_FrTpRxIndication & PduR_FrTpTxConfirmation called w. disabled IRQs
 *  01.15.01  2011-03-28  Wnk     ESCAN00049604 FrTp issues TIMEOUT_BS even if FC.CTS frame arrives at FrTp, in time,
 *                                              or TIMEOUT_AS even if a CF-frames' TxConfirmation comes in, in time.
 *            2011-03-29  Wnk     ESCAN00049631 FrTp does not end transfer at once w.FRTP_NTFRSLT_E_NO_BUFFER i.case Tx-buf.
 *                                              prov. returns BUFREQ_E_NOT_OK,BUFREQ_E_OVFL or inv.code
 *            2011-03-31  Wnk     ESCAN00049712 Critical section is unlocked without lock in FrTp_FrIf_RxIndication()
 *  01.15.02  2011-04-26  Wnk     ESCAN00050361 Wrong brackets set in FrTp_Transmit() in variant FULL_EXT_VECTOR + 
 *                                              TP_ISO10681_HAVE_ONE_TX_PDU_PER_POOL
 *                                ESCAN00050367 Swapped position and changed type of ConnIdx in FrTp_ConnCfgType
 *            2011-04-27  Wnk     ESCAN00050415 Invalid STF-Frames containing FPL 0 lead to Null-Ptr-exception in FrTp
 *  01.15.03  2011-05-05  Wnk     Adapted version check to make code work with GENy DLLs both 1.19.xx and 1.17.xx
 *  01.15.04  2011-06-24  Wnk     ESCAN00051843 FrTp continues to send after an CF_EOB.
 *            2011-07-05  Wnk     ESCAN00052020 Tp_Iso10681 violates SC / SCexp in some Integration scenarios
 *            2011-07-06  Wnk     ESCAN00052033 FrTp runs into exception after no Tx-Data has been provided
 *            2011-07-10  Wnk     ESCAN00052087 With decoupled Pdus payload gets corrupted during some FrTp-Txns
 *  01.15.05  2011-07-12  Wnk     ESCAN00052120 Txns with SUM(FPLsOfTransmission) != FPL(inSTF) error do not Rcv FC.ABT
 *  01.15.06  2011-11-15  Wnk     ESCAN00054842 FrTp conducts invalid transmission starting with CF
 *                                ESCAN00056626 TIMEOUT_BS instead of reception of Flow Control Frame
 *            2012-02-29  Wnk     ESCAN00057229 Duplicate defines in Tp_Iso10681_TYPES.h and ComStack_Types.h
 *  01.16.00  2011-03-01  Wnk     ESCAN00049020 Ask more than twice for Rx-buffer in case lots of Rx-space are avail.
 *            2011-03-03  Wnk     ESCAN00049057 #include "Std_Types.h" is not included by FrTp as demanded by Asr 3.X
 *            2011-03-11  Wnk     ESCAN00049219 Length of PduInfoType given is not checked to fit the given PduId
 *            2011-05-09  Wnk     ESCAN00050756 AR3-1330: Remove E_PENDING
 *            2011-06-17  Wnk     ESCAN00051157 RxIndication & TriggerTransmit Prototypes as specified in ASR 3.2.1
 *            2011-06-21  Wnk     ESCAN00051517 Remove the AUTOSAR Release Version Check
 *            2011-07-04  Wnk     ESCAN00051642 Implement TP APIs as specified in ASR3.2.1
 *            2011-07-12  Wnk     ESCAN00052134 Fast TxBuf retrieval after every FC.CTS (not only after first FC.CTS)
 *  01.16.01  2011-07-29  Wnk     ESCAN00052462 Reveicer-given MNPC might be violated for >30 Pdus assigned Tx-PduPool
 *            2011-08-16  Wnk     ESCAN00052780 Compile Warnings in Tp_Iso10681.c for compiler DiabData 5.6.1
 *            2011-08-22  Wnk     Enhanced compatibilty to Vector Coding Rules
 *            2011-08-29  Wnk     ESCAN00053109 Compiler warning: Double definition of TPPARAMTYPE_* in ComStackTypes.h
 *            2011-09-01  Wnk     ESCAN00053189 Compile error in case critical section is used from VstdLib
 *            2011-10-05  Wnk     ESCAN00054039 Compiler Warning: Miscellaneous
 *            2011-11-23  Wnk     ESCAN00053413 AR3-2069: Remove non-SchM code for critical section handling
 *            2011-12-05  Wnk     ESCAN00040608 DET check for exceeding max. Pdu length in FrTp_RxIndic. does not work 
 *                                ESCAN00050500 Unexpected FC.CTS might lead to incorrect transmission
 *            2011-12-07  Wnk     ESCAN00053470 Early use of FrTp_CancelTransmit can lead to blocking of FrTpChannel
 *  01.16.02  2012-02-10  Wnk     ESCAN00056739 Support usage of symbolic name values
 *            2012-02-14  Wnk     ESCAN00052574 Remove #include "std_Types.h" from Tp_Iso10681_Types.h 
 *  01.16.03  2012-03-09  Wnk     ESCAN00057396 FrTp does not use all FrIf-Tx-Pdus even though enough Tx-Data is available
 *  01.16.04  2012-05-07  Wnk     ESCAN00058516 Payload data received is written by FrTp despite of BUFREQ_E_BUSY
 *            2012-05-21  Wnk     ESCAN00059023 SCexp != 0 violated in Tx buffer retrieval after cycle using full MNPC
 *            2012-06-15  Wnk     ESCAN00059439 Support AR4 FrTpSduTxId and invalid SNVs for Rx and Tx
 *            2012-06-19  Wnk     ESCAN00059503 Support crit.sect., remove MainFunc extern-decl. for FRTP_AUTOSARVERSION4_COMMENT
 *            2012-06-20  Wnk     ESCAN00059557 Support ASR4 Service IDs as alternative to ASR3 Service IDs
 *            2012-07-09  Wnk     ESCAN00059997 Implement AR4 buffer retrieval API - Std Ecu usecase
 *                        Wnk     n/a           Moved FrTp.c-local macro definitions to FrTp_Common.h
 *            2012-07-13  Wnk     ESCAN00060139 Set NxtFreePduIdx prior to optimized buffer retrieval during burst mode
 *            2012-07-23  Wnk     ESCAN00060296 Achieve ASR 3.2.2 compliance - Private values for Std_ReturnType should be removed
 *            2012-07-25  Wnk     ESCAN00060336 Prototype of FrTp_RxIndication was changed to be ASR 4.0.0 Rev.3 compliant
 *                        Wnk     ESCAN00060355 PduR_FrTpChangeParameterConfirmation called w wrong RxSduId after FrTp_ChangeParameter
 *            2012-07-27  Wnk     ESCAN00060415 Extract all const-sections from code-sections
 *            2012-08-08  Wnk     ESCAN00060689 Compiler warning: 'TP_ISO10681_CRC_CHECK' is not defined
 *            2012-08-15  Wnk     ESCAN00060814 AR4 / CFG5 only: FRTP_INVALID_SNV should be #defined max(PduIdType) but is #defined 2 bytes too small (regarding sizeof)
 *                        Wnk     ESCAN00060819 Remove feature "Extended Version Check" for variant AR4
 *            2012-08-28  Wnk     ESCAN00061002 After retry FrTp sends CF1 in CF2 block in case CF is not filled to its max.
 *                        Wnk     ESCAN00061071 AckRt only: Feature TP_ISO10681_TOLERATE_EARLY_FC not implemented
 *  01.16.05  2012-09-19  Wnk     ESCAN00061532 FRTP_INVALID_SNV now also defined for AR3-CFG5 use case.
 *            2012-10-08  Wnk     ESCAN00061947 Compiler error: Items connRange and connOffset not defined for Multi Config
 *            2012-10-11  Ore     n/a           Fixed PRQA justification to be Vector compliant
 *            2011-10-12  Wnk     ESCAN00062128 AR4 only: Tp_Iso101681 stops segm.reception in case unsegm.STF was rejected by upper layer, before.
 *            2012-10-15  Wnk     ESCAN00062213 AR4 only: Tp_Iso101681 stops unsegm.transmission in case segm.STF was rejected by upper layer, before and pool has 1 Tx pdu
 *  01.16.06  2012-10-22  Wnk     ESCAN00062454 AR4 only: FrTp calls CopyRxData with 0 bytes SduLength
 *                        Wnk     ESCAN00062462 FRTP_INVALID_SNV now generated by generator of CFG5
 *            2012-11-22  Wnk     ESCAN00063222 Compiler warning: variable "FrTp_ConvAsr4ResultToAsr3" was declared but never referenced
 *            2012-11-26  Wnk     ESCAN00063296 Compiler error: 'numResetPdus' : undeclared identifier
 *            2012-11-28  Wnk     ESCAN00063406 FrTp_Init() dereferences uninitialized pointers (Changed FrTp_InitMemory)
 *            2013-01-15  Wnk     ESCAN00064162 Internally call FrTp_Rx/TxInit with CRITICAL_SECTION_0 locked
 *            2013-01-17  Wnk     ESCAN00064277 AR4 only: Transfer stops too early or wrong data is used in case data is routed from a slower bus
 *            2013-01-23  Wnk     ESCAN00064482 AR4 only: Return value BUFREQ_E_BUSY from PduR_FrTpProvideTxBuffer leads to stop of transmission when length=0 is used
 *            2013-01-30  Wnk     ESCAN00064678 LF missing in a FrTp transmission when FC from receiver is indicated too early
 *  01.17.00  2013-02-01  Wnk     ESCAN00063222 Compiler warning: variable "FrTp_ConvAsr4ResultToAsr3" was declared but never referenced
 *            2013-02-06  Wnk     ESCAN00064860 AckRt only Intrnl. method FrTp_Rsrc_RxInit called 2x after error i.an AckRt Rxn (runtime can be saved, no appl.error visible)
 *                        Wnk     ESCAN00064869 AR4 only: ProvidedDataLength used in a wrong way
 *                        Wnk     ESCAN00064872 AckRt only: CF_EOB is not accepted as start of a block of retried CF-frames
 *            2013-02-07  Wnk     ESCAN00064896 AR4 only: Compiler error: Undefined variable subFrameRetries = 0u; in function FrTp_RxSm_CopyRxData for FRTP_HAVE_RC == STD_ON
 *            2013-02-15  Wnk     ESCAN00065132 AR4 only: Support setting Rx-connections "on hold" by temporarily providing zero buffer after 1st or 2nd pdu rxed
 *            2013-02-15  Wnk     ESCAN00065190 Transmission ends up with FRTP_NTFRSLT_E_NOT_OK with FrIf-Retry STD_ON in a burst mode scenario
 *            2013-02-22  Wnk     ESCAN00065341 AR4 only: Cancel Rx/Tx and ChangeParameter do not work in case FRTP_HAVE_SNV is STD_ON
 *                        Wnk     ESCAN00065018 AR4 only: Implement Rx-Buffer handling according to draft of AR SWs FrTp from AR-Release 4.1.1
 *            2013-03-07  Wnk     ESCAN00065671 Compiler error: 'pRxSm' : undeclared identifier
 *            2013-03-21  Wnk     ESCAN00066125 DET check of FrIf-IDs FrTp_RxIndication, FrTp_TxConfirmation, FrTp_TriggerTransmit
 *            2013-03-26  Wnk     ESCAN00066242 AR4 only: FrTp does not finalize receptions in case they are not straight forward (e.g. they have 0 bytes avail. data)
 *            2013-04-08  Wnk     ESCAN00066425 MISRA deviation: MISRA-C:2004 Rule 19.6 in MSN_MemMap.inc 
 *            2013-04-10  Wnk     ESCAN00064326 AR4-325: Implement Post-Build Loadable
 *            2013-04-19  Wnk     ESCAN00066784 Define all DET error codes in FrTp.h specified by AUTOSAR 4 SWS
 *            2013-04-25  Wnk     ESCAN00066905 Compiler warning: AR3 features not filtered for AR4 causes warnings for AR4.PB + other warnings
 *                        Wnk     ESCAN00066916 Possible Compile/Link error: Variable declaration section declared inline in functions in file Tp_Iso10681.c
 *                        Wnk     ESCAN00064867 PB only: FrTp_Init() dereferences uninitialized pointers.
 *                        Wnk     ESCAN00066939 Generated data misses initializers when used with no startup code and no memory mapping
 *                        Wnk     ESCAN00066948 PB only: In variant postbuild call to Det_ReportError due to not being initialized leads to nullptr-access
 *            2013-04-26  Wnk     ESCAN00066113 AR3-2494: Implement AMD timemeasurement support
 *            2013-05-06  Wnk     ESCAN00067188 Compiler warning: A value of type "uint16 *" cannot be used to initialize an entity of type "uint8 *const"
 *            2013-05-15  Wnk     ESCAN00067384 FrTp transmits invalid data in case PduR or other upper layer reduces available Tx-data-length erroneously during operation
 *            2013-05-17  Wnk     ESCAN00063356 AR4 only: Tp_Iso10681 sends corrupt data in GW use case with slower source bus
 *  01.18.00  2013-07-30  Wnk     ESCAN00067761 Removed code in comments
 *            2013-07-31  Wnk     ESCAN00068269 AR4-447: Implement (post-build loadable) flexible RAM management
 *            2013-08-07  Wnk     ESCAN00069619 AR4 only: Payload of a transmission might get corrupted in case of FlexRay-Bus-Problems or transmission fails
 *            2013-08-08  Wnk     ESCAN00069666 PduR_FrTpCopyTxData is called with 0 bytes copy-length at the end of a txn. for decoupled Tx-Pdus and LF with FPL '0'
 *            2013-08-19  Wnk     ESCAN00069901 At sending segmented data MNPC might be not obeyed in case MNPC != 0 is sent in a FC.CTS and miscfg.ered FrTp_TxConfirmation
 *            2013-08-20  Wnk     ESCAN00069863 Compiler warning: 'FrTpParameterValue' : unreferenced formal parameter
 *            2013-08-21  Wnk     ESCAN00069935 FrTp_Transmit conducts unnecessary internal check that has been conducted in the codelines above, already
 *            2013-08-22  Wnk     ESCAN00069961 Internal DET check in FrTp_Rsrc_FindTxSm issues FrTp_MainFunction_ServiceId instead of FrTp_Transmit_ServiceId
 *            2013-08-30  Wnk     ESCAN00070125 ToDos FrTp_ChangeParameter
 *            2013-10-02  Wnk     ESCAN00070868 AR4 only: FrTp_CancelTransmit influences a different connection than identified by parameter FrTpSduTxId
 *            2013-10-10  Wnk     ESCAN00071025 AR4 only: Compile error in case of SingleTxPdu-Optimization and variant precompile
 *            2013-10-11  Wnk     ESCAN00071055 Compiler warning: warning C4255: 'FrTp_TxSm_CopyTxData' : no function prototype given: converting '()' to '(void)'
 *            2013-10-24  Wnk     ESCAN00071443 AR4 only: FrTp communication fails when config variant changed from LTIME to PB and PduIdType changed to UINT8
 *                        Wnk     ESCAN00071457 AR4 only: FrTp_ChangeParameter & FrTp_CancelReceive expect the SduIDs of the upper layer instead of those of the Tp_Iso10681
 *  01.19.00  2013-11-08  Wnk     ESCAN00071715 AR4 only: Compiler warning: Misc. warnings for decoupled transmission and AR4 Sdu-Id mapping
 *                        Wnk     ESCAN00071719 Shutdown all active connections in a call to FrTp_Shutdown()
 *            2013-11-13  Wnk     ESCAN00071823 AR4 only: Feature TP_ISO10681_HAVE_FAST_BUF_RETRIEVAL was removed for variant AUTOSAR 4
 *            2013-11-18  Wnk     ESCAN00072016 The number of tx-buffer requests exceeds TimeCs if it is configured to 255 (at max. 254 is possible)
 *            2013-11-28  Wnk     ESCAN00072324 FRTP_E_SEG_ERROR not supported by FrTp_Transmit
 *                        Wnk     ESCAN00072325 FRTP_E_UMSG_LENGTH_ERROR not supported by FrTp_Transmit
 *            2013-12-02  Wnk     ESCAN00072386 FRTP_E_NO_CHANNEL not supported by FrTp_Transmit / FrTp_RxIndication
 *            2013-12-13  Wnk     ESCAN00072647 AR4-only: In GW case a reception routed from Tp_Iso10681 to CanTp ends with E_NOT_OK at Tp_Iso10681
 *                        Wnk     ESCAN00072659 BfS communicated by receiver is violated in a transfer with CF_EOB for PduIdType defined as uint8
 *            2013-12-19  Wnk     ESCAN00072726 Compiler warning: Unreachable code in FrTp_TriggerTransmit
 *            2013-12-20  Wnk     ESCAN00072005 AR3-2605: Support ChangeParameter without Confirmation (synchron API according ASR 3.2.1)
 *            2014-01-09  Wnk     ESCAN00072858 Compile Error: FrTp_ConfigType not defined for variant "precompile" when FrTp_Init with init-cfg-ptr is used
 *            2014-01-20  Wnk     ESCAN00072383 [AR3 only] Values of DET-error definitions are not AR-compliant
 *            2014-01-22  Wnk     ESCAN00073135 Remove multiline preprocessor commands and if-statements and function prototypes that depend on preprocessor switches
 *            2014-02-10  Wnk     ESCAN00073566 AR4 only: Compiler error: enum from AR4.0.3 ComStack_Types.h is not supported by FrTp_ChangeParameter-API
 *  01.19.01  2014-03-13  Wnk     ESCAN00074259 Compiler error: C1012: unmatched parenthesis : missing '('
 *  01.20.00  2014-05-13  Wnk     ESCAN00071716 AR4-619: Support the StartOfReception API (with the PduInfoType), TxConfirmation and RxIndication according ASR4.1.2
 *            2014-05-16  Wnk     ESCAN00075649 Increase robustness: Do not unlock critical sections for callouts to PduR or other upper layers
 *            2014-06-02  Wnk     ESCAN00074453 AR4-650: Support ChangeParameter without Confirmation (synchron API according Autosar) and ReadParameter
 *            2014-06-04  Wnk     ESCAN00076083 Compiler error in FrTp_Init due to inclusion of memmap.h in the code-range of FrTp_Init()
 *            2014-06-06  Wnk     ESCAN00076148 Compiler warning: conversion from 'volatile PduLengthType' to 'uint16', possible loss of data / signed/unsigned mismatch
 *            2014-06-16  Wnk     ESCAN00076287 Compiler error: 'FrTp_TxGetSepCyclesFor' : undeclared identifier
 *            2015-02-06  Wnk     ESCAN00081097 Timeout A for FC.WAIT leads to notifyResult-code E_NOT_OK instead of TIMEOUT_A
 *  02.00.00  2014-07-16  Wnk     ESCAN00077110 AR3 variant was removed from this package
 *                        Wnk     ESCAN00078484 AR4-698: Post-Build Selectable (Identity Manager)
 *                        Wnk     ESCAN00075493 In the emb. GenData introduce mapping of FrTpConnections to the Rx-Pdu-Pools configured for them in the EcuC
 *            2014-09-23  Wnk     ESCAN00078271 All authors in the revision history can now be looked up in the authors list in the start-comment of all source files of the Tp_Iso10681
 *            2014-09-23  Wnk     ESCAN00078401 Set parameter "retry" given to PduR in PduR_FrTpCopyTxData to NULL_PTR because retry-functionality is not supported
 *            2014-10-10  Wnk     ESCAN00056108 Adapt codestructure of FrTp_Rsrc_RxInit to FrTp_Rsrc_TxInit
 *            2014-10-24  Wnk     ESCAN00079124 Enable complex "Identity Manager" configurations: Allow calling of FrTp_MainFunction without DET error (but do nothing) when FrTp/Tp_Iso10681 is not initialized
 *            2014-11-06  Wnk     ESCAN00079416 AR4 only: Compiler error:  Undefined function FrTp_FrIf_IsDecoupPdu and Undefined symbol pFrIfTxPdu
 *  02.00.01  2014-11-11  Wnk     ESCAN00079481 FrTp_TriggerTransmit is not robust regarding the usage of FrIf_TxPdus that are not used anymore after PB-L reflashing or on case the FrIf works wrong in a PB-S use case
 *            2014-11-14  Wnk     ESCAN00079612 Compiler error:  ...: 'ECUM_BSWERROR_NULLPTR' : undeclared identifier
 *            2014-11-21  Wnk     ESCAN00079755 Compiler error: Section not closed using Autosar-like memory-mapping 
 *  02.00.02  2014-11-25  Wnk     ESCAN00079809 DET error call in FrTp_CancelReceive in case of wrong RxSduId is called with service ID of FrTp_CancelTransmit
 *            2014-12-09  Wnk     ESCAN00080084 FrTp_ReadParameter might read a parameter of a different connection, FrTp_ChangeParameter might lead to DET in case of IdentityMgr. configs
 *            2014-12-18  Wnk     ESCAN00080354 If called with invalid RxPduId (FrIf-malfunction) FrTp_RxIndication() might accept too large (i,e, corrupt) frames or not accept valid frames.
 *                        Wnk     ESCAN00080368 If called with invalid TxPduId (FrIf-malfunction) FrTp_TxConfirmation() might lead to overwriting of memory of neighboured components
 *  02.01.00  2015-01-27  Wnk     ESCAN00080301 FEAT-427: SafeBSW Step I
 *            2014-02-09  Wnk     ESCAN00081142 Remove FrTpAr, FrTpAs from GenData because these values are not used in the implementation, anymore
 *            2015-02-23  Wnk     ESCAN00081356 Transmission ends unsuccessful  in case LF with FPL=0 is contained and the sender has DET active
 *  02.02.00  2015-04-24  Wnk     ESCAN00081788 FEAT-1275: SafeBSW Step 2
 *            2015-04-28  Wnk     ESCAN00082269 FEAT-1379: Optimized copy operation for large data
 *            2015-05-13  Wnk     ESCAN00081178 Wrong data is received in case PduR_FrTpStartOfReception() or PduR_FrTpCopyRxData returns BUFREQ_E_BUSY at the STF-reception
 *            2015-06-19  Wnk     ESCAN00083426 No changes in all files.
 *            2015-07-09  Wnk     ESCAN00075493 [AR4 only] Introduce relation between FrTpConnections to the Rx-Pdus and their Pools configured in the EcuC
 *  02.02.01  2015-12-18  Wnk     ESCAN00087227 FrTp stops receiving during gateway operation when routing segmented data on a slow CanTp
 *                        Wnk     ESCAN00087252 FrTp as a receiver stops transfer with error after FrTpMaxWft FC.WT-pdus have occurred in the transfer even though FC.CTS-pdus have been sent inbetween
 *            2015-12-21  Wnk     ESCAN00087263 FrTp as a receiver sends a flow control clear to send pdu in case the upper layer has violated CopyRxData-calling-conventions (malbehavior of UL)
 *  02.03.00  2015-12-10  Wnk     ESCAN00087080 MISRA deviation: MISRA-C:2004 Rules 781, 3673, 3109, 6030, 6010, 6050
 *            2016-01-28  Wnk     ESCAN00087806 FEAT-1688: SafeBSW Step 4
 *                        Wnk     ESCAN00087893 Feature "Multi Purpose Tp" was removed from embedded code.
 *                        Wnk     ESCAN00087896 FrTp asks for rx-buffer for a time of FrTp_TimeoutAr instead of FrTp_TimeBr after rxn. of a STF Pdu.
 *            2016-02-02  Wnk     ESCAN00087959 Bandwidth Limitation mechanism might not work on transmitter side of TP-data in case the tx-pdu-pool has >1 Pdus and other transfers are running (GW only)
 *                        Wnk     ESCAN00085038 API FrTp_ReadParameter was removed to achive AUTOSAR 4.2.1-compliance
 *            2016-02-12  Wnk     ESCAN00087806 FEAT-1688: SafeBSW Step 4
 *            2016-02-15  Wnk     ESCAN00088289 For direction Tx feature FrTpRxIndEarlierThanTxConf does not work but leads to a non functioning communication
 *            2016-03-01  Wnk     ESCAN00088631 After reception of an unsegmented STF the FrTp asks for copying the received data for too long.
 *            2016-03-22  Wnk     ESCAN00084544 Use only one critical section in Tp_Iso10681
 *  02.04.00  2016-04-19  Pju     ESCAN00089585 Change CfgStruct and VarLData Macros in a way to be able to use Ceedling, CMock, etc.
 *            2016-05-04  Wnk     ESCAN00089817 "Do not deliver" message occurs when FrTp_memmap.inc is used to create memmap.h
 *            2016-05-23  Wnk     ESCAN00090137 Unreachable code was removed.
 *            2016-05-24  Wnk     ESCAN00090167 Wrong initalization of the FrTp, done by the EcuM, is not detected in variant postbuild.
 *  02.04.01  2016-08-19  Wnk     ESCAN00091537 FrTp asks for tx-data for TimeoutAs instead of TimeBs in case of configured SCexp
 *  02.04.02  2016-09-26  Wnk     ESCAN00092029 Compiler error: FrTp_XCfg.h: error: syntax error : missing '{' before '*'
 *                        Wnk     ESCAN00092034 Compiler warning: C4242: 'function' : conversion from 'uint8_least' to 'uint8', possible loss of data
 *  02.04.03  2016-11-07  Wnk     ESCAN00092665 MISRA deviation: MISRA-C:2004 Rule 3355, 3358 (Condition is always true/false)
 *                        Wnk     ESCAN00092666 Source #define TP_ISO10681_*_H was adapted to correct MSN "FRTP" --> e.g. FRTP_*_H in FrTp_Cbk.h, FrTp.h
 *                        Wnk     ESCAN00092668 Header version check was added for FrTp_Cbk.h, FrTp_XCfg.h
 *                        Wnk     ESCAN00092857 Flow control frame is not sent in case TimeBr is <2 FrTp_MainFunction()-cycles
 *            2017-02-16  Wnk     ESCAN00094033 [Error] PostBuildXmlGen50009 - Symbol FrTp_FrIf_DecoupPduAdminInitState not accessible via root structure(s) (missing references).
 *            2017-02-23  Wnk     ESCAN00094154 Under certain conditions FrTp does not transmit FrIf-Tx-Pdus at all, using the FrIf-API.
 *  02.04.04  2017-04-11  Wnk     ESCAN00089581 Functional STF-Pdus contain obsolete or invalid data in case the upper layer does not provide their payload in the call to PduR_FrTpCopyTxData() (i.e. UL will return BUFREQ_E_BUSY)
 *            2017-04-19  Wnk     ESCAN00094809 Implement findings of PrcCheck of overall package 4.03.00 (achieve error-free traceability in VSF-report FrTp.html)
 *            2017-10-16  Wnk     ESCAN00097034 Tp_Iso10681 violates calling convention with PduR when a connection that was rejected by PduR, before, is restarted by another STF-Pdu
 *********************************************************************************************************************/

#if !defined (FRTP_H)
#define FRTP_H

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */
/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "FrTp_GlobCfg.h"

# define FRTP_GENERATOR_COMPATIBILITY_VERSION   0x0302
# define FRTP_FINAL_MAGICNUMBER                 0x2442

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
#define FRTP_VENDOR_ID                  (30u)
#define FRTP_MODULE_ID                  (36u)
#define TP_ISO10681_VENDOR_ID           (30u)
#define TP_ISO10681_MODULE_ID           (36u)

/* AUTOSAR Software Specification Version Information */
#define FRTP_AR_RELEASE_MAJOR_VERSION   (4)
#define FRTP_AR_RELEASE_MINOR_VERSION   (2)
#define FRTP_AR_RELEASE_PATCH_VERSION   (2)
/* LEGACY */
/* PRQA S 3453 4 */ /* MD_MSR_19.7 */
#define TP_ISO10681_AR_MAJOR_VERSION    FRTP_AR_MAJOR_VERSION
#define TP_ISO10681_AR_MINOR_VERSION    FRTP_AR_MINOR_VERSION
#define TP_ISO10681_AR_PATCH_VERSION    FRTP_AR_PATCH_VERSION

/* Component Version Information */
#define FRTP_SW_MAJOR_VERSION                         (2u)
#define FRTP_SW_MINOR_VERSION                         (4u)
#define FRTP_SW_PATCH_VERSION                         (4u)

/* LEGACY */
/* PRQA S 3453 4 */ /* MD_MSR_19.7 */
#define TP_ISO10681_SW_MAJOR_VERSION    FRTP_SW_MAJOR_VERSION
#define TP_ISO10681_SW_MINOR_VERSION    FRTP_SW_MINOR_VERSION
#define TP_ISO10681_SW_PATCH_VERSION    FRTP_SW_PATCH_VERSION
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
#define TP_ISO10681_VERSION             0x0204
#define TP_ISO10681_RELEASE_VERSION     0x04
#define FRTP_VERSION                    0x0204
#define FRTP_RELEASE_VERSION            0x04

/* Definition of API-Ids. */
#define FrTp_Init_ServiceId             0x00u
#define FrTp_Shutdown_ServiceId         0x01u
#define FrTp_Transmit_ServiceId         0x02u
#if (FRTP_HAVE_TC == STD_ON)
# define FrTp_CancelTransmit_ServiceId  0x03u
#endif
#define FrTp_ChangeParameter_ServiceId  0x04u
#define FrTp_RxIndication_ServiceId     0x42u
#define FrTp_TxConfirmation_ServiceId   0x40u
#define FrTp_TriggerTransmit_ServiceId  0x41u
#if (FRTP_HAVE_RC == STD_ON)
# define FrTp_CancelReceive_ServiceId   0x08u
#endif
#define FrTp_MainFunction_ServiceId     0x10u
#define FrTp_GetVersionInfo_ServiceId   0x27u
#define FrTp_ReadParameter_ServiceId    0x81u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/*!< Legacy */
extern CONST(uint8, FRTP_CONST) FrTp_MainVersion;
extern CONST(uint8, FRTP_CONST) FrTp_SubVersion;
extern CONST(uint8, FRTP_CONST) FrTp_ReleaseVersion;

#define FRTP_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRTP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

 /***********************************************************************************************************************
 * FrTp_Init
 **********************************************************************************************************************/
/*!
 * \brief       Initializes the runtime data of the FrTp.
 * \details     Initializes all:
 *              - channels (i.e. StateMachines)
 *              - decoupled-PDU-runtime-data of each pdu
 *              - Rx- and Tx-related usage-flags of pdu pdu
 *              - Tx-pools' runtime data
 *              Sets the state to 'initialized.
 *              The function is called by AUTOSAR EcuM.
 * \param[in]   P2CONST(FrTp_ConfigType, AUTOMATIC, FRTP_INIT_DATA) CfgPtr: Pointer to overall configuration structure of FrTp, located in ROM/Flash.
 *              Pointer parameter CfgPtr has to point to a constant of type FrTp_ConfigType containing the FrTp-configuration.
 * \pre         In case the startup-code does not initialize memory then FrTp_InitMemory() should be called, before.
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpInitialization
 **********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Init(
  P2CONST(FrTp_ConfigType, AUTOMATIC, FRTP_INIT_DATA) CfgPtr
);

/**********************************************************************************************************************
  FrTp_Shutdown
**********************************************************************************************************************/
/*!
 * \brief       Shuts down the FrTp by initializing its runtime data.
 * \details     In case the FrTp never was initialized before the function does nothing. Called by AUTOSAR EcuM.
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpInitialization
 **********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_Shutdown(
  void
);

/**********************************************************************************************************************
  FrTp_Transmit()
**********************************************************************************************************************/
/*!
 * \brief       Initiates a transmission of data.
 * \details     The function is called by Pdu-Router or maybe an application like e.g. diagnostics
 *              Called by AUTOSAR PduR, AUTOSAR DCM, diagnostic or other application
 *              This method tries to initiate a transmission of the given FrTp-connection / given Sdu-Id.
 *              Will return E_OK in case the transmit-request was accepted and will be executed during the next FrTp_MainFunction()
 *              or E_NOT_OK in case the request was invalid or the affected channel was busy.
 * \param[in]   PduIdType FrTpTxSduId: Symbolic name value of the FrTp-connection that shall be activated to transmit TP-data.
 *                                     PRE_FRTP_VALID_TX_SDU_ID
 * \param[in]   P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) PduInfoPtr: Pointer to struct whereas its member SduLength 
 *              provides the length of TP-data to be transmitted.
 *              PRE_FRTP_VALID_PDU_INFO_TYPE PduInfoPtr
 *              Member SduLength of the C-struct pointed to by PduInfoPtr has to be in the range of [1..65535]
 * \return      Std_ReturnType: E_OK for acceptance
 *                              E_NOT_OK for rejection
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpTransmission, DSGN-FrTpFullduplexAndSimplex, DSGN-FrTpBroadcastConnections, DSGN-FrTpGenericPduRTPinterface
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_Transmit(
  PduIdType FrTpTxSduId,
  P2CONST(PduInfoType, AUTOMATIC, FRTP_APPL_DATA) FrTpTxSduInfoPtr
);

/***********************************************************************************************************************
 *  FrTp_MainFunction()
 **********************************************************************************************************************/
/*!
 * \fn          void FrTp_MainFunction(void)
 * \brief       Operates all rx|tx-state-machines that are active receiving|transmitting data.
 * \details     Handles all timers, counters and their timeouts and overflows. 
 *              This is the main function of the AUTOSAR FlexRay Transport Protocol.
 *              Called by OS Task cyclically each FlexRay-cycle
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpActionAndTimeoutHandling, DSGN-FrTpReception, DSGN-FrTpTransmission, DSGN-FrTpMainFunction, DSGN-FrTpStateMachineHandling, DSGN-FrTpRoundRobin, DSGN-FrTpBurstMode, DSGN-FrTpTxConfirmationHandling
 * \note        Function declaration is provided by header files generated by SchM/Rte
 **********************************************************************************************************************/
/* Function declaration is provided by header files generated by EcuM */

#if(FRTP_HAVE_TC == STD_ON)
/**********************************************************************************************************************
  FrTp_CancelTransmit
**********************************************************************************************************************/
/*!
 * \brief       Requests the cancellation of a running / active transmission of FrTp-data from the FrTp.
 * \details     Can be called for a transmission only.
 *              Called by AUTOSAR PduR, AUTOSAR DCM, diagnostic or other application
 * \param[in]   PduIdType FrTpTxSduId: Symbolic name value of the FrTp-connection to be cancelled.
 *                                     PRE_FRTP_VALID_TX_SDU_ID
 * \return      Std_ReturnType: E_OK in case the channel is busy with a segmented transmission,
 *                                   and the cancellation-request was processed sucessfully,
 *                              E_NOT_OK otherwise.
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_HAVE_TC == STD_ON
 * \trace       DSGN-FrTpTxCancellation
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_CancelTransmit
(
  PduIdType FrTpTxSduId
);
#endif

#if(FRTP_HAVE_RC == STD_ON)
/**********************************************************************************************************************
  FrTp_CancelReceive
**********************************************************************************************************************/
/*!
 * \brief       Requests the cancellation of a running / active reception of FrTp-data from the FrTp.
 * \details     Can be called for a receptions only.
 *              Called by AUTOSAR PduR, AUTOSAR DCM, diagnostic or other application
 * \param[in]   PduIdType FrTpRxSduId: Symbolic name value of the FrTp-connection to be cancelled
 *                                     PRE_FRTP_VALID_RX_SDU_ID
 * \return      Std_ReturnType: E_OK in case the channel is busy with a segmented reception, 
 *                                   and the cancellation-request was processed sucessfully,
 * \return                      E_NOT_OK otherwise.
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_HAVE_RC == STD_ON
 * \trace       DSGN-FrTpRxCancellation
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_CancelReceive(
  PduIdType FrTpRxSduId
);
#endif

/**********************************************************************************************************************
  FrTp_ChangeParameter
**********************************************************************************************************************/
/*!
 * \brief       Requests the change of the BC parameter for the given FrTpSduId.
 * \details     BC is indicated by the receiver in a FC-pdu after the first received pdu (STF-Seg).
 *              It shall not be changed by the sender after this indication. 
 *              Hence this method is to change the BC-value on the receiver side!!!
 *              Called by AUTOSAR PduR, AUTOSAR DCM, diagnostic or other application
 *              No reception may be active when the parameter shall actually be changed, because all change-able parameters are rx-related.
 * \param[in]   PduIdType FrTpRxSduId: Symbolic name value of the connection whose BC parameter shall be changed
 *                                     PRE_FRTP_VALID_RX_SDU_ID
 * \param[in]   VAR(TPParameterType, AUTOMATIC) FrTpParameterType: Type of the parameter to be changed
 * \param[in]   FrTp_ParameterValueType parameterValue: New value of the parameter defined by parameterType
 * \return      Std_ReturnType: E_OK in no reception active on the given FrTpRxSduId
 *                                   and the given parameter value is valid,
 *                              E_NOT_OK otherwise.
 * \pre         PRE_FRTP_INIT
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       CREQ-876
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FRTP_CODE) FrTp_ChangeParameter(
  VAR(PduIdType, AUTOMATIC) FrTpRxSduId,
  VAR(TPParameterType, AUTOMATIC) FrTpParameterType,
  VAR(uint16, AUTOMATIC) FrTpParameterValue
);

#if(FRTP_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  FrTp_GetVersionInfo
**********************************************************************************************************************/
/*!
 * \brief       AUTOSAR compliant API to retrieve its version from the FrTp component
 * \details     The function is called by any non-FrTp software-unit 
 * \param[out]  Std_VersionInfoType *pVersionInfo: Ptr to struct to the store version info in
 *                                                 Pointer pVersionInfo has to point to a constant of type Std_VersionInfoType.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Available only in case FRTP_VERSION_INFO_API == STD_ON
 * \trace       DSGN-FrTpProvidePublishedInformation
 *********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_GetVersionInfo(
  Std_VersionInfoType *pVersionInfo
);
#endif
/* #if(FRTP_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
  FrTp_InitMemory
**********************************************************************************************************************/
/*!
 * \brief       Initializes static variables of the FrTp component in case the startup-code does not do so.
 * \details     The function is called by AUTOSAR EcuM.
 * \pre         -
 * \context     TASK|ISR
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       DSGN-FrTpInitialization
 **********************************************************************************************************************/
extern FUNC(void, FRTP_CODE) FrTp_InitMemory(
  void
);

#define FRTP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

#endif /* FRTP_H */

/* \PRE PRE_FRTP_VALID_P_CONN_CFG
        Pointer parameter <name given after the tag PRE_FRTP_VALID_P_CONN_CFG> has to point to a constant of type FrTp_ConnCfgType. 
        This constant has to be an element of the generated array FrTp_ConnCfg[].  */

/* \PRE PRE_FRTP_VALID_CONN_IDX
        Parameter tpConn has to be in the range of [0..(FrTp_NumConn - 1)]. */

/* \PRE PRE_FRTP_INIT
        FrTp must have been initialized by a call to FrTp_Init(<valid configuration pointer>). */

/* \PRE PRE_FRTP_VALID_RX_SM_IDX
        Parameter <name given after the tag PRE_FRTP_VALID_RX_SM_IDX> has to have a value in the range of [0..(FrTp_NumRxChan - 1)]. */

/* \PRE PRE_FRTP_VALID_TX_SM_IDX
        Parameter <name given after the tag PRE_FRTP_VALID_TX_SM_IDX> has to have a value in the range of [0..(FrTp_NumTxChan - 1)]. */

/* \PRE PRE_FRTP_VALID_ACTIVE_RX_SM_IDX
        This precondition includes PRE_FRTP_VALID_RX_SM_IDX <name given after the tag PRE_FRTP_VALID_ACTIVE_RX_SM_IDX>. 
        In addition the rx-state-machine determined by parameter rxSmIdx has to be active receiving TP-data, i.e. its members are 
        initialized as described in PRE_FRTP_VALID_ACTIVE_SM */

/* \PRE PRE_FRTP_VALID_ACTIVE_TX_SM_IDX
        This precondition includes PRE_FRTP_VALID_TX_SM_IDX <name given after the tag PRE_FRTP_VALID_ACTIVE_TX_SM_IDX>. 
        In addition the tx-state-machine determined by parameter txSmIdx has to be active transmitting TP-data, i.e. its members are 
        initialized as described in PRE_FRTP_VALID_ACTIVE_SM */

/* \PRE PRE_FRTP_VALID_ACTIVE_SM
        The affected state-machine is active with a TP-data-transfer and thus these state-machine-members are initialized as follows:
        1. ConnCfgPtr: PRE_FRTP_VALID_P_CONN_CFG ConnCfgPtr + the connection is the one that is active transferring TP-data using this state-machine.
        2. NxtFreePduIdx: The value has to comply to PRE_FRTP_VALID_FRIF_TX_PDU_IDX NxtFreePduIdx.
        3. DataLength: a) The value has to be non-zero, i.e. it indicates that a transfer of TP-data is active in the state-machine.
                       b) The value has to fit into the smallest [rx|tx]-pdu configured for the FrTp_Connection pointed to by ConnCfgPtr in case 
                          i) it is a [reception|transmission] 
                          ii) in case the pdu is used as FrTp-pdu (i.e. address-information and PCI-bytes also fit into the pdu, together with 'DataLength' bytes of payload) and
                          iii) in case the FrTp_Connection is configured to be 1:n (ConnCfgPtr->MultRec == TRUE)
                       c) The value has to be in the range of [1..65535] in case the condititions described in b) are FALSE.
        4. In case of an tx-state-machine: CopiedDataLength: The value is <= than the length of the the tx-pdu-buffer pointed to by FrTp_TxBuf[txSmIdx]
        5. In case of a rx-state-machine: ReceivedDataLength: The value is <= than the length of the the rx-pdu-buffer pointed to by FrTp_RxBuf[rxSmIdx]
        6. CurrPCI: The value has to have a value in the range as described in PRE_FRTP_VALID_STATE_CURR_PCI.
*/

/* \PRE PRE_FRTP_TX_SM_IDX_OF_PTR
        The index txSmIdx has to be the index of the adjacent pTxSm pointer to an element from the generated array FrTp_TxState[]. */

/* \PRE PRE_FRTP_RX_SM_IDX_OF_PTR
        The index rxSmIdx has to be the index of the adjacent pRxSm pointer to an element from the generated array FrTp_RxState[]. */

/* \PRE PRE_FRTP_VALID_RX_SM_PTR
        Pointer parameter pRxSm has to point to a rx-state-machine, retrieved from the generated array FrTp_RxState[]. */

/* \PRE PRE_FRTP_VALID_TX_SM_PTR
        Pointer parameter pTxSm has to point to a tx-state-machine, retrieved from the generated array FrTp_TxState[]. */

/* \PRE PRE_FRTP_VALID_ACTIVE_RX_SM_PTR
        This precondition includes PRE_FRTP_VALID_RX_SM_PTR. In addition the rx-state-machine determined by parameter pRxSm has to be 
        active receiving TP-data, i.e. its members are initialized as described in PRE_FRTP_VALID_ACTIVE_SM */

/* \PRE PRE_FRTP_VALID_ACTIVE_TX_SM_PTR
        This precondition includes PRE_FRTP_VALID_TX_SM_PTR. In addition the tx-state-machine determined by parameter pTxSm has to be 
        active receiving TP-data, i.e. its members are initialized as described in PRE_FRTP_VALID_ACTIVE_SM */

/* \PRE PRE_FRTP_VALID_TX_SDU_ID
        Parameter FrTpTxSduId has to be in the range of [0..(FrTp_MaxTxSduId - 1)] */

/* \PRE PRE_FRTP_VALID_RX_SDU_ID
        Parameter FrTpRxSduId has to be in the range of [0..(FrTp_MaxRxSduId - 1)] */

/* \PRE PRE_FRTP_VALID_FRIF_RX_PDU_IDX
        Parameter <name given after the tag PRE_FRTP_VALID_FRIF_RX_PDU_IDX> has to
        a) have a value of range [0..(FrTp_NumFrIfRxPdus - 1)] and
        b) be of a value != FrTp_NoPdu. */

/* \PRE PRE_FRTP_VALID_FRIF_TX_PDU_IDX
        Parameter <name given after the tag PRE_FRTP_VALID_FRIF_TX_PDU_IDX> has to
        a) have a value of range [0..(FrTp_NumFrIfTxPdus - 1)] and
        b) be of a value != FrTp_NoPdu. */

/* \PRE PRE_FRTP_VALID_FRIF_TX_PDU_PTR
        Parameter <name given after the tag PRE_FRTP_VALID_FRIF_TX_PDU_PTR> has to point to a constant of type FrTp_TxPduInfoType which is 
        a) a member of generated array FrTp_FrIfTxPdus[] and is
        b) located in that array at an index that complies to PRE_FRTP_VALID_FRIF_TX_PDU_IDX <name given after the tag PRE_FRTP_VALID_FRIF_TX_PDU_PTR> */

/* \PRE PRE_FRTP_VALID_PDU_INFO_TYPE
        Pointer parameter <name given after the tag PRE_FRTP_VALID_PDU_INFO_TYPE> has to point to a constant of type PduInfoType. */

/* \PRE PRE_FRTP_VALID_PDU_LENGTH_TYPE_PTR
        Pointer parameter pAvailableTxData has to point to a variable of type PduLengthType. */

/* \PRE PRE_FRTP_TPCI_PTR
        Pointer parameter <name given after the tag PRE_FRTP_TPCI_PTR> has to point to a variable of type PduInfoType. */

/* \PRE PRE_FRTP_PAYLOAD_PTR
        Pointer parameter pPayload has to point to a variable of type PduInfoType. */

/* \PRE PRE_FRTP_SM_ACCESS
        This function expects the critical section of the FrTp to be active. */

/* \PRE PRE_FRTP_VALID_TX_STATE_PARAM
        Parameter <name given after the tag PRE_FRTP_VALID_TX_STATE_PARAM> has to be in the range of these values
        FrTp_TxSm_Idle
        FrTp_TxSm_WaitFC
        FrTp_TxSm_WaitForDataSTFfunc
        FrTp_TxSm_WaitForDataSTFphys
        FrTp_TxSm_WaitForDataCF
        FrTp_TxSm_WaitForTxnNonBurstSTFunseg
        FrTp_TxSm_WaitForTxnNonBurstSTFseg
        FrTp_TxSm_WaitForTxConfNonBurstSTFunseg
        FrTp_TxSm_WaitForTxConfNonBurstSTFseg
        FrTp_TxSm_WaitForTxConfBurstCF
        FrTp_TxSm_WaitForTxConfBurstCFIntrnl
        FrTp_TxSm_WaitForEndOfBurstCF
        FrTp_TxSm_WaitForBCexpiry */

/* \PRE PRE_FRTP_VALID_RX_STATE_PARAM
        Parameter <name given after the tag PRE_FRTP_VALID_RX_STATE_PARAM> has to be in the range of these values
        FrTp_RxSm_Idle
        FrTp_RxSm_WaitForSegmPdu
        FrTp_RxSm_WaitForSTFsegmBuffer
        FrTp_RxSm_WaitForSTFunsegmBuffer
        FrTp_RxSm_WaitForCFbuffer
        FrTp_RxSm_WaitForCF_EOBbuffer
        FrTp_RxSm_WaitForLFbuffer
        FrTp_RxSm_WaitForNxtFC_WT
        FrTp_RxSm_WaitForTxnNonBurstFC_CTS
        FrTp_RxSm_WaitForTxnNonBurstFC_WT
        FrTp_RxSm_WaitForTxnNonBurstFC_ABT
        FrTp_RxSm_WaitForTxnNonBurstFC_OVER
        FrTp_RxSm_WaitForTxConfFC_CTS
        FrTp_RxSm_WaitForTxConfFC_WT
        FrTp_RxSm_WaitForTxConfFC_ABT
        FrTp_RxSm_WaitForTxConfFC_OVER */

/* \PRE PRE_FRTP_VALID_STATE_CURR_PCI
        Parameter currPCI has to be in the range of these values
        FrTp_PCISTF
        FrTp_PCISTFunseg
        FrTp_PCISTFseg
        FrTp_PCICF1
        FrTp_PCICF2
        FrTp_PCICFEOB
        FrTp_PCIFC
        FrTp_PCILF
        FrTp_PCIinvalid
*/

/* \PRE PRE_FRTP_VALID_RX_STATE_TIMER
        Parameter newTimer has to be in the range of [1..65535] */

/* \PRE PRE_FRTP_VALID_TX_STATE_TIMER
        Parameter newTimer has to be in the range of [1..65535] */

/* \PRE PRE_FRTP_VALID_TX_PDU_ID_TRIG_TX
        Parameter FrIfTxPduId has to:
        a) be in the range of [0..FrTp_NumDecoupPdus - 1].
        b) be the index of a tx-pdu in generated array FrTp_FrIfTxPdus[] that has transmission type 'decoupled'
        c) lead to a position in generated array FrTp_DecoupPduAdminData[] that is properly initialized, i.e. its member:
           i)  ConnCfgPtr has to point to a FrTp_Connection in generated array FrTp_ConnCfg[] that is currently busy transmitting FrTp-data
           ii) PduInfoPayload has to have its member SduLength initialized to the length of the payload to transmit
           iii) PduLengthTPCI has to be initialized to a length value that indicates the length of the PCI found in member:
           iv) TPCIData[] */

/*
Documentation of critical section SM_ACCESS of the FrTp:
(FrTp_EnterCritical, FrTp_LeaveCritical)
\exclusivearea   FRTP_EXCLUSIVE_AREA_0 (aka SM_ACCESS)
\protects        Access to:
                 - all state-machines (i.e. C-struct containing the status variables of a state-machine)
                 - all connection-runtime data (i.e. C-struct containing the status variables of a connection that is run in a state-machine)
                 handled by the FrTp
\usedin          FrTp_MainFunction,
                 FrTp_RxIndication,
                 FrTp_TxConfirmation,
                 FrTp_TriggerTransmit,
                 FrTp_ChangeParameter,
                 FrTp_CancelReceive,
                 FrTp_CancelTransmit,
                 and callees.
\exclude         Refer to the functions listed in section 'usedin'
\length          LONG
\endexclusivearea
*/

/**********************************************************************************************************************
 *  END OF FILE: FrTp.h
 *********************************************************************************************************************/


