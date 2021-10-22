
/**************************************************************************************************
   Project Name: AUTOSAR XCP on FlexRay Transport Layer
      File Name: FrXcpS.c

    Description: XCP on FlexRay Transport Layer implementation

  -------------------------------------------------------------------------------------------------
       C O P Y R I G H T
  -------------------------------------------------------------------------------------------------
       Copyright (c) 2017 by Vctr Informatik GmbH. All rights reserved.

       This software is copyright protected and proporietary to Vctr Informatik GmbH.
       Vctr Informatik GmbH grants to you only those rights as set out in the
       license conditions. All other rights remain with Vctr Informatik GmbH.

       Use of this source code is subject to the License Agreement "license.txt"
       distributed with this file. You may not use this source code unless you
       agree to the terms of the License Agreement.

       REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.

  -------------------------------------------------------------------------------------------------
                 A U T H O R   I D E N T I T Y
  -------------------------------------------------------------------------------------------------
   Initials     Name                      Company
   --------     ---------------------     ---------------------------------------------------------
   hr           Andreas Herkommer         Vctr Informatik GmbH
   ore          Oliver Reineke            Vctr Informatik GmbH
  -------------------------------------------------------------------------------------------------
                 R E V I S I O N   H I S T O R Y
  -------------------------------------------------------------------------------------------------
   Date         Ver      Author  Description
   ----------   -------  ------  ------------------------------------------------------------------
   2006-09-01   2.00.00  hr      Complete Rework for Gen2 - Supports FrIf now
   2007-03-31   2.01.00  hr      Adaptation to D4 requirements: New API
   2007-05-07   2.01.01  hr      ISS001 - Buffer reconfig API includes and type usage reworked to
                                          prevent compile error if not used
                                 ISS002 - Usage of Compiler.h is not mandatory anymore
   2007-05-08   2.02.00  hr      Implementation of features described in XCP_Client_V1.1
   2007-07-23   2.02.01  hr      Minor updates
   2007-07-09   2.03.00  hr      Support AUTOSAR Memory Mapping
   2007-09-03   2.03.01  hr      Unified as Single Source
   2007-10-05   2.04.00  hr      ISS024 - XcpAppl_DaqTlResume had a wrong prototype
                                 ISS027 - Support of AUTOSAR GetVersion API
                                 ISS030 - PDU buffer ordering changed
                                 ISS032 - The XCP_ACTIVATE and XCP_DEACTIVATE macros are missing
   2007-12-07   2.05.00  hr      ISS045 - Reception of concatenated frames may lead to
                                          misinterpretation of random data as xcp frame in case
                                          PDU is smaller than MAX_PDU_SIZE
                                 ISS046 - Only CTOs are flushed by the Protocol Layer
   2008-02-07   2.06.00  hr      ISS051 - XCP_ENABLE and XCP_DISABLE have intermixed values
                                 ISS052 - FrXcp_TLService missing length check of new assigned buffer
                                 ISS053 - PDU Reservation shoould happen before FrIf_Transmit as
                                          this might cause race conditions on certain FlexRay Stacks
                                 ISS054 - Copy of XCP PDUs can now also be done during Tx_Confirmation
                                          to detect displacement in the non guaranteed dynamic segment
   2008-03-20   2.07.00  hr      Added various type casts for MISRA compliance
   2008-08-27   2.08.00  hr      Update for ASR 3.0
   2009-03-16   2.09.00  hr      ESCAN00033909: Update due to 
                                                Anforderungsdokument_EA_XCP-Client_Spezifikation_V1_1.PDF
   2009-08-03   2.09.01  hr      ESCAN00036838: Race condition with XCP_FREE_PDU and Event Assign
   2009-09-07   2.09.02  hr      ESCAN00037599: Missing memmap.h and compiler_cfg.h
   2009-09-12   2.10.00  hr      ESCAN00038374: No FrXcp_InitMemory function
   2009-10-13                    ESCAN00038410: Wrong variable section for compiler abstraction
   2009-11-24            hr      ESCAN00039363: Support FrIf_Transmit with E_PENDING
   2009-12-03            hr      ESCAN00039560: Compiler Warning by ON/OFF pre-processor statements
   2009-12-09            hr      ESCAN00039641: FrXcp does not use SchM for Interrupt locks
   2010-02-02   2.10.01  hr      ESCAN00040602: Frame end detection with concatenation is one byte to long.
                                 ESCAN00040124: Support MISRA2004 checks
                                 ESCAN00040810: wrong "component version" define
   2010-08-17   2.10.02  hr      ESCAN00044142: Compiler error occurs when compiling function FrXcp_GetFreePdu
   2010-08-24                    ESCAN00044840: Compiler warning "Invalid pointer cast" might occur
   2010-11-04   2.10.03  hr      ESCAN00046457: Transport Layer not activated in Protocol Layer if frame concatenation is enabled
                                 ESCAN00046235: Adapt AUTOSAR version check
                                 ESCAN00046412: Compiler warning: variable "FrXcp_PduState" was set but never used
                                 ESCAN00046819: Add support for XCP measurement during bus off phases
   2010-12-14   2.10.04  hr      ESCAN00047672: Resume Mode Callbacks do not use Compiler abstraction
                                 ESCAN00047641: Compiler warning: FrXcp.h", line 307: warning (dcc:1479): comma at end of enumerator list ignored
   2011-01-04   2.11.00  hr      ESCAN00046310: AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
                                 ESCAN00047330: Adapt MainFunction for usage with IdentityManagerConfig
   2011-03-03   2.11.01  hr      ESCAN00049062: The SetPduMode shall be pre-compile time configurable
   2011-05-13   2.12.00  hr      ESCAN00050177: Support MultiConfig
   2011-08-17   2.12.01  hr      ESCAN00052817: Compiler error "maxlength" is undefined
   2011-09-23   2.12.02  ore     ESCAN00053780: No declaration for Post Build configs
   2011-11-30   2.13.00  hr      ESCAN00053658: AR3-1482: Support new Xcp delivery structure
                                 ESCAN00053423: AR3-2069: Remove non-SchM code for critical section handling
                                 ESCAN00054036: Compiler warning: variable "FrXcp_FrameOverrun" was set but never used
                                 ESCAN00055492: AR3-1482: Support variant legacy file names
   2011-07-17   2.13.01  hr      ESCAN00060168: Compile error if GENy option "Set PduMode Support" is disabled
   2012-07-19            hr      ESCAN00060209: Cfg5 compile error: FrXcp makes use of CANbedded classifier   
   2012-10-18   2.14.00  hr      ESCAN00062361: Add module specific define
                                 ESCAN00060585: AR3-2446: Implement all necessary countermeasures for SilentBSW
                                 ESCAN00060553: AR3-2443: Implement Silent Checks in BSW module code
                                 ESCAN00057332: AR3-2374: Implement Silent BSW
                                 ESCAN00061040: AR3-2378: Implement AMD timemeasurement support
   2013-01-21   2.15.00  hr      ESCAN00064393: Create AUTOSAR 4.0 branch
   2013-02-11   2.16.00  hr      ESCAN00065006: FLX_ASSIGN returns an error code if FRXCP_IDX_XCP_PACKET_TYPE is VARIABLE
                                 ESCAN00065892: Critical section lock time in FrXcp_MainFunctionTx to long
                                 ESCAN00066150: Compiler warning: unused parameter 'XcpFlushTypeSel'
                                 ESCAN00066258: Missing interrupt release in CMD_FLX_ACTIVATE/DEACTIVATE
                                 ESCAN00065883: Compiler warning: [10348] cast increases required alignment of target type
   2013-02-11   2.16.01  hr      ESCAN00067506: Compiler error: undefined macros STD_TYPES_AR_MAJOR_VERSION and FRXCP_TRANSMIT_WITHIN_CONFIRMATION
   2013-07-19   2.16.02  hr      ESCAN00068957: Pdu buffers not reset when component is deactivated.
                                 ESCAN00069332: Global Reset of Variable Buffers stops xcp communication
   2013-09-11   2.17.00  hr      ESCAN00067656: Compiler warning: conversion from 'PduLengthType' to 'uint8', possible loss of data
                                 ESCAN00070207: Optimization - 32bit copy
   2013-11-08   2.17.01  hr      ESCAN00071234: Compiler warning: FrXcp.c: narrowing or signed-to-unsigned type conversion found
                                 ESCAN00066822: The MISRA justifications are not implemented according WI_MISRAC2004_PES.pdf
                                 ESCAN00072645: Race condition during frame reception
   2014-03-18   2.17.02  hr      ESCAN00074340: Compiler error: Xcp.h: FRXCP_ENABLE_CONTROL' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
   2014-03-18   2.17.03  hr      ESCAN00074246: Resume Mode - RES PDU buffer blocked, no CMD/RES communication possible after Resume mode initialized
   2014-08-26   2.18.00  hr      ESCAN00075850: Support flexible RAM Management for Post Build support
                         hr      ESCAN00078873: Compiler warning: possible truncation at implicit conversion to type "unsigned char"
                         hr      ESCAN00071562: ApplXcpDaqTlResume provides a return value which is not used
   2015-04-28   3.00.00  hr      ESCAN00082733: Support TxConfirmation timeout timer
                                 ESCAN00083372: Undefined return value when invalid PDU ID is used with FrXcp_TriggerTransmit
                                 ESCAN00078874: Compiler warning: dead assignment to "FrXcp_InitializationState" eliminated
                                 ESCAN00082741: Remove AR3 Features
   2015-11-20   3.00.01  hr      ESCAN00086396: FEAT-1357: SafeXCP
                                 ESCAN00086649: Flush of pdus not covered by critical section
                                 ESCAN00083447: Compiler error: FrXcp.c doesn't compile if GENy option "Optimized 32bit Copy" is selected.
                                 ESCAN00087161: Pdu Id mapping in Pre-Compile and Link Time configs not correct in Multi-TL use cases
   2016-02-03   3.00.02  hr      ESCAN00087999: Missing PB memory section in FrXcp_MemMap.inc
   2016-02-08   3.00.03  hr      ESCAN00088153: Compiler error: SchM macro calls do not use ;
   2016-10-05   4.00.00  hr      ESCAN00092188: FEAT-1980: Add Multi Client / Multi Connection support
                                 ESCAN00092187: Safe deactivation does not consider FrXcp_Init
                                 ESCAN00092186: Safe deactivation shall be performed before DET checks or anything
   2017-02-28   4.00.01  hr      ESCAN00094191: Removed version checks DET, FrIf, Mem Access, Send Queue
**************************************************************************************************/

#define FRXCP_SOURCE

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "FrXcp.h"
#include "FrXcp_Cbk.h"

#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  #include "Det.h"              /* Include Diagnostic Event Manager */
#endif

#include "FrIf.h"               /* Include FrIf APIs */
#include "SchM_Xcp.h"

#if defined ( FRXCP_AMD_RUNTIME_MEASUREMENT ) && ( FRXCP_AMD_RUNTIME_MEASUREMENT == STD_ON )
#  include "Rtm.h"
#endif

/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/

/* Check consistency of source and header file. */
#if defined ( CP_XCPONFRASR_VERSION )
  #if ( CP_XCPONFRASR_VERSION != 0x0400u )
    #error "Source and Header file are inconsistent!"
  #endif
  #if ( CP_XCPONFRASR_RELEASE_VERSION != 0x01u )
    #error "Source and Header file are inconsistent!"
  #endif
#endif

/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/

/* Initialization status of FRXCP. */
#define FRXCP_UNINIT 0   /* The FRXCP is not initialized and is not usable. */
#define FRXCP_INIT   1   /* The FRXCP is initialized and is usable. */

/* Defines for optional commands */
#define FRXCP_CMD_FLX_ASSIGN              0xFFu
#define FRXCP_CMD_FLX_ACTIVATE            0xFEu
#define FRXCP_CMD_FLX_DEACTIVATE          0xFDu
#define FRXCP_CMD_GET_DAQ_FLX_LPDU_ID     0xFCu
#define FRXCP_CMD_SET_DAQ_FLX_LPDU_ID     0xFBu

#define FRXCP_IDX_TL_CMD                  0x01u
#define FRXCP_IDX_FLX_BUF                 0x02u
#define FRXCP_IDX_XCP_PACKET_TYPE         0x03u
#define FRXCP_IDX_FLX_SLOT_ID             0x04u
#define FRXCP_IDX_CYCLE_COUNTER_OFFSET    0x06u
#define FRXCP_IDX_CYCLE_COUNTER_REPET     0x07u
#define FRXCP_IDX_FLX_CHANNEL             0x08u
#define FRXCP_IDX_MAX_FLX_LEN_BUF         0x09u
#define FRXCP_IDX_HEADER_CRC              0x0Au

/* The following XCP PIDs represent the equivalent XCP-Frame Types */
#define FRXCP_PID_TYPE_DAQ                0xFBu
#define FRXCP_PID_TYPE_STIM               0xBFu
#define FRXCP_PID_TYPE_CMD                0xC0u
#define FRXCP_PID_TYPE_RES                0xFFu
#define FRXCP_PID_TYPE_ERR                0xFEu
#define FRXCP_PID_TYPE_EV                 0xFDu
#define FRXCP_PID_TYPE_SERV               0xFCu

/* Some bordering values */
#define FRXCP_MAX_OFFSET                  63u
#define FRXCP_MAX_CYCLE_REPETITION        64u

/* Offset of NAX in FlexRay PDU */
#define FRXCP_NAX_FRAME_OFFSET 0
/* This constant defines the overflow flag */
#define FRXCP_OVERFLOW_INDICATION_FLAG 0x80u
/* Position of PID in XCP-Frame */
#define FRXCP_PID_OFFSET 0x00u
/* Defined range of filter attributes */
#define FRXCP_PACKET_FILTER_MASK 0x1Fu

#if defined ( FRXCP_FRAME_ALIGNMENT_8BIT )
  #if defined ( FRXCP_FRAME_ALIGNMENT_16BIT ) || defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
    #error "XCP consistency error: Select either FRXCP_FRAME_ALIGNMENT_8BIT or 16- or 32BIT."
  #endif
  #define XCP_ALIGNMENT_MASK 0u
  #define HEADER_FILL_SIZE 0u
  #if ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 1u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 1u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 1u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 1u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 2u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 2u
  #else
    #error "FrXcp.c: consistency error, either FRXCP_FRAME_PACKING or FRXCP_SEQUENCE_COUNTER not defined within range!"
  #endif
#endif

#if defined ( FRXCP_FRAME_ALIGNMENT_16BIT )
  #if defined ( FRXCP_FRAME_ALIGNMENT_8BIT ) || defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
    #error "XCP consistency error: Select either FRXCP_FRAME_ALIGNMENT_8BIT or 16- or 32BIT."
  #endif
  #define XCP_ALIGNMENT_MASK 1u
  #if ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 2u
    #define HEADER_FILL_SIZE 1u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 1u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 1u
    #define HEADER_FILL_SIZE 0u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 2u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 2u
    #define HEADER_FILL_SIZE 0u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 3u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 3u
    #define HEADER_FILL_SIZE 1u
  #else
    #error "FrXcp.c: consistency error, either FRXCP_FRAME_PACKING or FRXCP_SEQUENCE_COUNTER not defined within range!"
  #endif
#endif

#if defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
  #if defined ( FRXCP_FRAME_ALIGNMENT_8BIT ) || defined ( FRXCP_FRAME_ALIGNMENT_16BIT )
    #error "XCP consistency error: Select either FRXCP_FRAME_ALIGNMENT_8BIT or 16- or 32BIT."
  #endif
  #define XCP_ALIGNMENT_MASK 3u
  #if ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 4u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 4u
    #define HEADER_FILL_SIZE 3u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_OFF )
    #define XCP_FRAME_START 3u
    #define CTR_FRAME_OFFSET 0u
    #define HEADER_SIZE 3u
    #define HEADER_FILL_SIZE 2u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_OFF ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 4u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 4u
    #define HEADER_FILL_SIZE 2u
  #elif ( FRXCP_FRAME_CONCATENATION == STD_ON ) && ( FRXCP_SEQUENCE_COUNTER == STD_ON )
    #define XCP_FRAME_START 3u
    #define CTR_FRAME_OFFSET 1u
    #define HEADER_SIZE 3u
    #define HEADER_FILL_SIZE 1u
  #else
    #error "FrXcp.c: consistency error, either FRXCP_FRAME_PACKING or FRXCP_SEQUENCE_COUNTER not defined within range!"
  #endif
#endif

#if !defined ( FRXCP_FRAME_ALIGNMENT_8BIT ) && \
    !defined ( FRXCP_FRAME_ALIGNMENT_16BIT ) && \
    !defined ( FRXCP_FRAME_ALIGNMENT_32BIT )
  #error "FrXcp.c: consistency error, usage of Transport Layer alignment not specified!"
#endif

/* Define AUTOSAR types if not defined yet */
#if defined ( STATIC )
#else
# define STATIC static
#endif

/****************************************************************************/
/* 16 Bit Constants for export                                              */
/****************************************************************************/
#define FRXCP_START_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint16, FRXCP_CONST) FRXCP_VENDOR_ID = (uint16)FRXCP_VENDOR_ID_DEFINITION; /* Vector = 30 */

#define FRXCP_STOP_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/****************************************************************************/
/* 8 Bit Constants for export                                               */
/****************************************************************************/
#define FRXCP_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint8, FRXCP_CONST) FRXCP_MODULE_ID     = (uint8)FRXCP_MODULE_ID_DEFINITION;    /* XCP on FlexRay = 211 */
CONST(uint8, FRXCP_CONST) FRXCP_MAJOR_VERSION = (uint8)(CP_XCPONFRASR_VERSION >> 8u); /* Major version number */
CONST(uint8, FRXCP_CONST) FRXCP_MINOR_VERSION = (uint8)(CP_XCPONFRASR_VERSION & 0xFF);/* Minor version number */
CONST(uint8, FRXCP_CONST) FRXCP_PATCH_VERSION = (uint8)CP_XCPONFRASR_RELEASE_VERSION; /* Patch level version number */

STATIC CONST(uint8, FRXCP_CONST) LPDU_LOOKUP[4] = /* PRQA S 3218 */ /* MD_FrXcp_3218 */
  { (uint8)FRXCP_LPDU_TYPE_RES, (uint8)FRXCP_LPDU_TYPE_RES, (uint8)FRXCP_LPDU_TYPE_EV, (uint8)FRXCP_LPDU_TYPE_EV };

#if ( FRXCP_FRAME_CONCATENATION == STD_ON )
STATIC CONST(uint8, FRXCP_CONST) LPDU_TYPES[3] = /* PRQA S 3218 */ /* MD_FrXcp_3218 */
  { (uint8)FRXCP_LPDU_TYPE_RES, (uint8)FRXCP_LPDU_TYPE_EV, (uint8)FRXCP_LPDU_TYPE_DAQ };
#endif

#if ( FRXCP_USE_DECOUPLED_MODE == STD_ON )
#else
STATIC CONST(uint8, FRXCP_CONST) LPDU_TO_BUFFER[8] = 
{ (uint8)0u, (uint8)0u, (uint8)1u, (uint8)1u, (uint8)2u, (uint8)2u, (uint8)2u, (uint8)2u };
#endif

#define FRXCP_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**************************************************************************************************
* Macros
**************************************************************************************************/
/* Configuration access (depending on configuration variant)*/
/* PRQA S 3453 73 */ /* MD_MSR_19.7 */

#if ( FrXcp_IsPostbuild() )
#define FrXcp_CfgGetNAX()                     (FrXcp_PBCfgPtr->NAX)
#define FrXcp_CfgGetConfTimeoutReload()       (FrXcp_PBCfgPtr->ConfTimeoutReload)
#define FrXcp_CfgGetNumberRxLpduIds()         (FrXcp_PBCfgPtr->NumberOfRxPdus)
#define FrXcp_CfgGetNumberTxLpduIds()         (FrXcp_PBCfgPtr->NumberOfTxPdus)
#define FrXcp_CfgGetMaxRxPduId()              (FrXcp_PBCfgPtr->MaxRxPduID)
#define FrXcp_CfgGetMaxTxPduId()              (FrXcp_PBCfgPtr->MaxTxPduID)
#define FrXcp_CfgGetDescriptorListSize()      (FrXcp_PBCfgPtr->PduDescriptorListSize)
#define FrXcp_CfgGetNumberOfTransmitFC()      (FrXcp_PBCfgPtr->NumberOfTransmitFC)

#define FrXcp_GetTransmitFC()                 (FrXcp_PBCfgPtr->TransmitFrameCachePtr)
#define FrXcp_GetAggregatedLength()           (FrXcp_PBCfgPtr->AggregatedLengthPtr)
#define FrXcp_GetConfTimeoutTimer()           (FrXcp_PBCfgPtr->ConfTimeoutTimerPtr)
#define FrXcp_GetReceiveFrameCache()          (FrXcp_PBCfgPtr->ReceiveFrameCachePtr)
#define FrXcp_GetReceiveFrameSignal()         (FrXcp_PBCfgPtr->ReceiveFrameSignalPtr)
#define FrXcp_GetRtConfig()                   (FrXcp_PBCfgPtr->RtConfigPtr)

#define FrXcp_CfgGetXcpPduId(idx)             (FrXcp_PBCfgPtr->PduDescriptorListPtr[idx].XcpPduId)
#define FrXcp_CfgGetXcpPacketFilter(idx)      (FrXcp_PBCfgPtr->PduDescriptorListPtr[idx].XcpPacketFilter)
#define FrXcp_CfgGetLpduIdx(idx)              (FrXcp_PBCfgPtr->PduDescriptorListPtr[idx].LpduIdx)
#define FrXcp_CfgGetMaxFlxLenBuf(idx)         (FrXcp_PBCfgPtr->PduDescriptorListPtr[idx].MaxFlxLenBuf)
#define FrXcp_CfgGetIsReconfigurable(idx)     (FrXcp_PBCfgPtr->PduDescriptorListPtr[idx].IsReconfigurable)
#define FrXcp_CfgGetIsInitialized(idx)        (FrXcp_PBCfgPtr->PduDescriptorListPtr[idx].IsInitialized)
#define FrXcp_CfgGetTxPduTranslation(idx)     (FrXcp_PBCfgPtr->TxPduTranslationTable[idx])
#define FrXcp_CfgGetRxPduTranslation(idx)     (FrXcp_PBCfgPtr->RxPduTranslationTable[idx])

#elif ( FRXCP_CONFIG_VARIANT == 2 )
#define FrXcp_CfgGetNAX()                     (FrXcp_Config.NAX)
#define FrXcp_CfgGetTimeoutReload()           (FrXcp_Config.ConfTimeoutReload)
#define FrXcp_CfgGetNumberRxLpduIds()         (FrXcp_Config.NumberOfRxPdus)
#define FrXcp_CfgGetNumberTxLpduIds()         (FrXcp_Config.NumberOfTxPdus)
#define FrXcp_CfgGetDescriptorListSize()      (FrXcp_Config.PduDescriptorListSize)
#define FrXcp_CfgGetNumberOfTransmitFC()      (FrXcp_Config.NumberOfTransmitFC)
#define FrXcp_GetTransmitFC()                 (FrXcp_TransmitFrameCache)
#define FrXcp_GetAggregatedLength()           (FrXcp_AggregatedLength)
#define FrXcp_GetConfTimeoutTimer()           (FrXcp_ConfTimeoutTimer)
#define FrXcp_GetReceiveFrameCache()          (FrXcp_ReceiveFrameCache)
#define FrXcp_GetReceiveFrameSignal()         (FrXcp_ReceiveFrameSignal)
#define FrXcp_GetRtConfig()                   (FrXcp_RtConfig)

#define FrXcp_CfgGetXcpPduId(idx)             (FrXcp_PduDescriptorList[idx].XcpPduId)
#define FrXcp_CfgGetXcpPacketFilter(idx)      (FrXcp_PduDescriptorList[idx].XcpPacketFilter)
#define FrXcp_CfgGetLpduIdx(idx)              (FrXcp_PduDescriptorList[idx].LpduIdx)
#define FrXcp_CfgGetMaxFlxLenBuf(idx)         (FrXcp_PduDescriptorList[idx].MaxFlxLenBuf)
#define FrXcp_CfgGetIsReconfigurable(idx)     (FrXcp_PduDescriptorList[idx].IsReconfigurable)
#define FrXcp_CfgGetIsInitialized(idx)        (FrXcp_PduDescriptorList[idx].IsInitialized)
#define FrXcp_CfgGetTxPduTranslation(idx)     (FrXcp_TxPduTranslationTable[idx])
#define FrXcp_CfgGetRxPduTranslation(idx)     (FrXcp_RxPduTranslationTable[idx])

#elif ( FRXCP_CONFIG_VARIANT == 1 )
#define FrXcp_CfgGetNAX()                     (FRXCP_NODE_ADDRESS)
#define FrXcp_CfgGetConfTimeoutReload()       (FRXCP_CONF_TIMEOUT)
#define FrXcp_CfgGetNumberRxLpduIds()         (FRXCP_NUM_RX_LPDUIDS)
#define FrXcp_CfgGetNumberTxLpduIds()         (FRXCP_NUM_TX_LPDUIDS)
#define FrXcp_CfgGetDescriptorListSize()      ((FRXCP_NUM_RX_LPDUIDS) + (FRXCP_NUM_TX_LPDUIDS))
#define FrXcp_CfgGetNumberOfTransmitFC()      (FRXCP_NUMBER_OF_TRANSMITFRAMECACHE)
#define FrXcp_GetTransmitFC()                 (FrXcp_TransmitFrameCache)
#define FrXcp_GetAggregatedLength()           (FrXcp_AggregatedLength)
#define FrXcp_GetConfTimeoutTimer()           (FrXcp_ConfTimeoutTimer)
#define FrXcp_GetReceiveFrameCache()          (FrXcp_ReceiveFrameCache)
#define FrXcp_GetReceiveFrameSignal()         (FrXcp_ReceiveFrameSignal)
#define FrXcp_GetRtConfig()                   (FrXcp_RtConfig)

#define FrXcp_CfgGetXcpPduId(idx)             (FrXcp_PduDescriptorList[idx].XcpPduId)
#define FrXcp_CfgGetXcpPacketFilter(idx)      (FrXcp_PduDescriptorList[idx].XcpPacketFilter)
#define FrXcp_CfgGetLpduIdx(idx)              (FrXcp_PduDescriptorList[idx].LpduIdx)
#define FrXcp_CfgGetMaxFlxLenBuf(idx)         (FrXcp_PduDescriptorList[idx].MaxFlxLenBuf)
#define FrXcp_CfgGetIsReconfigurable(idx)     (FrXcp_PduDescriptorList[idx].IsReconfigurable)
#define FrXcp_CfgGetIsInitialized(idx)        (FrXcp_PduDescriptorList[idx].IsInitialized)
#define FrXcp_CfgGetTxPduTranslation(idx)     (FrXcp_TxPduTranslationTable[idx])
#define FrXcp_CfgGetRxPduTranslation(idx)     (FrXcp_RxPduTranslationTable[idx])

#else
  #error "FrXcp.c: invalid or missing FRXCP_CONFIG_VARIANT, (value 1, 2 or 3 expected in config file)"
#endif
  /* FRXCP_CONFIG_VARIANT */

#define FRXCP_TRANSMIT(FrXcpTxPduId, PduInfoPtr) FrIf_Transmit(FrXcpTxPduId, PduInfoPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#if !defined ( FRXCP_COPY )
  #if defined ( XCP_ENABLE_ALIGNED_DTO )
    #define FRXCP_COPY(dest, src, length) FrXcp_FastCopy( (DAQBYTEPTR)(dest), (ROMDAQBYTEPTR)(src), (uint16)(length) ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  #else
    #define FRXCP_COPY(dest, src, length) (void)Xcp_MemCpy( (DAQBYTEPTR)(dest), (ROMDAQBYTEPTR)(src), (uint8)(length) ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  #endif
#endif
#if !defined ( FRXCP_MEMSET )
  #define FRXCP_MEMSET(dest, length, value) Xcp_MemSet( (BYTEPTR)(dest), (uint16)(length), (uint8)(value) ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/* Adjust according to alignment requirements */
#if ((XCP_ALIGNMENT_MASK) > 0u)
  #define XCP_ALIGN(idx) ((idx) | (uint8)XCP_ALIGNMENT_MASK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
  #define XCP_ALIGN(idx) (idx) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/* Macro for platform independent 16Bit access */
#if ( CPU_BYTE_ORDER == HIGH_BYTE_FIRST ) /* Avoid WORD access */
  #define GET_ARCHITECTURE_DEPENDANT_UI16(pt, idx) (((uint16)((pt)[(idx)+0u]) << 8u) | (uint16)((pt)[(idx)+1u])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
  #define GET_ARCHITECTURE_DEPENDANT_UI16(pt, idx) (((uint16)((pt)[(idx)+1u]) << 8u) | (uint16)((pt)[(idx)+0u])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/* Macro for determining xcp frame type */
#define XCP_GET_XCP_FRAME_TYPE(frame) (((frame)[FRXCP_PID_OFFSET] > (uint8)FRXCP_PID_TYPE_DAQ) ? LPDU_LOOKUP[(uint8)(~msg[FRXCP_PID_OFFSET])] : (uint8)FRXCP_LPDU_TYPE_DAQ) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Sequence counter handling */
#if ( CTR_FRAME_OFFSET > 0 )
  #define EMBOSS_TFC_SEQUENCE_COUNTER(PduHandle) ((FrXcp_GetTransmitFC()[FRXCP_TFC_IDX(PduHandle)]).fc[CTR_FRAME_OFFSET] = FrXcp_GlobalSequenceCounter) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  #define INCREMENT_SEQUENCE_COUNTER() FrXcp_GlobalSequenceCounter++
#else
  #define EMBOSS_TFC_SEQUENCE_COUNTER(PduHandle)
  #define INCREMENT_SEQUENCE_COUNTER()
#endif

/* Overrun handling */
#define XCP_MEMORIZE_OVERRUN()
#define XCP_TRANSFER_OVERRUN(PduHandle, Position)

/* Frame concatenation handling */
#if ( FRXCP_FRAME_CONCATENATION == STD_ON )
#define INSERT_TFC_XCP_FRAME(PduHandle, msg, len) do { \
                                                       FrXcp_GetTransmitFC()[FRXCP_TFC_IDX(PduHandle)].fc[FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)]] = (len); \
                                                       FRXCP_COPY(&(FrXcp_GetTransmitFC()[FRXCP_TFC_IDX(PduHandle)].fc[FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)]+(uint8)1u]), msg, len); \
                                                       XCP_TRANSFER_OVERRUN(PduHandle, FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)]+1u); \
                                                       FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] += ((len) + (uint8)1u); \
                                                       FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] = XCP_ALIGN(FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)]); \
                                                     } while(0)
#define FINALIZE_TFC(PduHandle)                   do { \
                                                       FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] += (uint8)1u; \
                                                       if((FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] > XCP_GET_CURRENT_MAX_FLX_LEN_BUF(PduHandle)) \
                                                       || ((uint8)0u == FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)])) \
                                                       { FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] = XCP_GET_CURRENT_MAX_FLX_LEN_BUF(PduHandle); } \
                                                       else \
                                                       { FrXcp_GetTransmitFC()[FRXCP_TFC_IDX(PduHandle)].fc[FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)]-(uint8)1u] = (uint8)0u; } \
                                                     } while(0)
#else
#define INSERT_TFC_XCP_FRAME(PduHandle, msg, len) do { FRXCP_COPY(&(FrXcp_GetTransmitFC()[FRXCP_TFC_IDX(PduHandle)].fc[XCP_FRAME_START]), msg, len); \
                                                       FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] += (len); \
                                                       XCP_TRANSFER_OVERRUN(PduHandle, XCP_FRAME_START); \
                                                     } while(0)
#define FINALIZE_TFC(PduHandle)
#endif

#define CREATE_TFC_HEADER(PduHandle) do { EMBOSS_TFC_SEQUENCE_COUNTER(PduHandle); \
                                          FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] = (uint8)HEADER_SIZE; \
                                        } while(0)
#define GET_TFC_PTR(PduHandle) ((P2VAR(uint8, AUTOMATIC, FRXCP_VAR_NOINIT))&(FrXcp_GetTransmitFC()[FRXCP_TFC_IDX(PduHandle)].fc[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define GET_TFC_LENGTH(PduHandle) FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define SET_TFC_LENGTH(PduHandle, Length) FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] = (Length) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if ( FRXCP_USE_DECOUPLED_MODE == STD_ON )
  #define XCP_RESERVE_PDU(PduHandle) FrXcp_GetRtConfig()[PduHandle].FrXcpPduAttributes |= (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_BUSY /* PRQA S 3453 */ /* MD_MSR_19.7 */
  #define XCP_FREE_PDU(PduHandle) do { FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] = (uint8)0u; \
                                       FrXcp_GetRtConfig()[PduHandle].FrXcpPduAttributes &= (FrXcp_XcpPacketType)~FRXCP_LPDU_TYPE_BUSY; \
                                     } while(0)
#else
  #define XCP_RESERVE_PDU(PduHandle) do { FrXcp_GetRtConfig()[PduHandle].FrXcpPduAttributes |= (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_BUSY; \
                                          FrXcp_GetAggregatedLength()[FRXCP_TFC_IDX(PduHandle)] = (uint8)0; \
                                        } while(0)
  #define XCP_FREE_PDU(PduHandle) FrXcp_GetRtConfig()[PduHandle].FrXcpPduAttributes &= (FrXcp_XcpPacketType)~FRXCP_LPDU_TYPE_BUSY
#endif

#define XCP_GET_CURRENT_MAX_FLX_LEN_BUF(PduHandle) FrXcp_GetRtConfig()[PduHandle].FrXcpPduLength /* PRQA S 3453 */ /* MD_MSR_19.7 */

#if ( FRXCP_USE_DECOUPLED_MODE == STD_ON )
  #define FRXCP_TFC_IDX(Index) (Index) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
  #define FRXCP_TFC_IDX(Index) LPDU_TO_BUFFER[(FrXcp_GetRtConfig()[Index].FrXcpPduAttributes >> 2u) & 0x07] /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/***************************************************************************************************/
/* General definition of checking macros */
# define FrXcp_CheckErrorReturnVoid(cond, api, err)        \
{ if(!(cond)){                                           \
    FrXcp_CallDetReportError((api), (err));                \
    return;                                              \
}} /* PRQA S 3458 */ /* MD_MSR_19.4 */

# define FrXcp_CheckErrorReturnValue(cond, api, err, ret)  \
{ if(!(cond)){                                           \
    FrXcp_CallDetReportError((api), (err));                \
    return(ret);                                         \
}} /* PRQA S 3458 */ /* MD_MSR_19.4 */

# define FrXcp_CheckErrorContinue(cond, api, err)          \
{ if(!(cond)){                                           \
    FrXcp_CallDetReportError((api), (err));                \
}} /* PRQA S 3458 */ /* MD_MSR_19.4 */

/***************************************************************************************************/
/* PRQA S 3453 12 */ /* MD_MSR_19.7 */
/* Macros for DET abstraction */
#if(FRXCP_DEV_ERROR_DETECT == STD_ON)
  # define FrXcp_CheckDetErrorReturnVoid(cond, api, err)       FrXcp_CheckErrorReturnVoid((cond), (api), (err))
  # define FrXcp_CheckDetErrorReturnValue(cond, api, err, ret) FrXcp_CheckErrorReturnValue((cond), (api), (err), (ret))
  # define FrXcp_CheckDetErrorContinue(cond, api, err)         FrXcp_CheckErrorContinue((cond), (api), (err))
  # define FrXcp_CallDetReportError(api, err)                  (void)Det_ReportError(FRXCP_MODULE_ID, 0u, (api), (err))
#else
  # define FrXcp_CheckDetErrorReturnVoid(cond, api, err)
  # define FrXcp_CheckDetErrorReturnValue(cond, api, err, ret)
  # define FrXcp_CheckDetErrorContinue(cond, api, err)
  # define FrXcp_CallDetReportError(api, err)
#endif

/***************************************************************************************************/
/* Macros for SBSW check abstraction */
#if(FRXCP_SILENT_CHECK == STD_ON)
  # define FrXcp_SilentBswCheckErrorReturnVoid(cond, api, err)       FrXcp_CheckErrorReturnVoid( (cond), (api), (err)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define FrXcp_SilentBswCheckErrorReturnValue(cond, api, err, ret) FrXcp_CheckErrorReturnValue( (cond), (api), (err), (ret)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
  # define FrXcp_SilentBswCheckErrorReturnVoid(cond, api, err)                \
  FrXcp_CheckDetErrorReturnVoid( (cond), (api), (err) ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define FrXcp_SilentBswCheckErrorReturnValue(cond, api, err, ret)          \
  FrXcp_CheckDetErrorReturnValue( (cond), (api), (err), (ret) ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/***************************************************************************************************/
/* Macros for AMD abstraction */
#if defined ( FRXCP_AMD_RUNTIME_MEASUREMENT ) && ( FRXCP_AMD_RUNTIME_MEASUREMENT == STD_ON )
  #define FrXcp_Rtm_Start(Xcp_Channel) Rtm_Start(RtmConf_RtmMeasurementPoint_##Xcp_Channel)
  #define FrXcp_Rtm_Stop(Xcp_Channel) Rtm_Stop(RtmConf_RtmMeasurementPoint_##Xcp_Channel)
#else
  #define FrXcp_Rtm_Start(Xcp_Channel)
  #define FrXcp_Rtm_Stop(Xcp_Channel)
#endif

/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/

/**************************************************************************************************
* Data definitions
**************************************************************************************************/

/******************************************************************************/
/* Local Data definitions with unspecified size                               */
/******************************************************************************/
#define FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( FrXcp_IsPostbuild() )
STATIC P2CONST(FrXcp_ConfigType, FRXCP_VAR_NOINIT, FRXCP_PBCFG) FrXcp_PBCfgPtr;
#endif

#if ( FRXCP_USE_PDUMODE == STD_ON )
STATIC VAR(FrXcp_PduSetModeType, FRXCP_VAR_NOINIT) FrXcp_PduState;
#endif

#define FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/******************************************************************************/
/* Local Data definitions with 8Bit size                                      */
/******************************************************************************/
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
# define FRXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* TL Enable/Disable state */
VAR(uint8, FRXCP_VAR_INIT) FrXcp_ControlState = kXcponFr_Control_Enable;

# define FRXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

#define FRXCP_START_SEC_VAR_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile STATIC VAR(uint8, FRXCP_VAR_INIT) FrXcp_InitializationState = FRXCP_UNINIT;

#if ( FRXCP_ENABLE_CONTROL == STD_ON )
VAR(uint8, FRXCP_VAR_INIT) FrXcp_ControlDeniedCount = 0; /* PRQA S 3408 */ /* MD_Xcp_3408 */
#endif

#define FRXCP_STOP_SEC_VAR_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FRXCP_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( CTR_FRAME_OFFSET > 0 )
/* The global Sequence Counter, incremented after each L-PDU */
STATIC VAR(uint8, FRXCP_VAR_NOINIT) FrXcp_GlobalSequenceCounter;
#endif

/* Send Queue Variables */
STATIC VAR(uint8, FRXCP_VAR_NOINIT) sq_len;
STATIC P2CONST(uint8, FRXCP_VAR_NOINIT, FRXCP_APPL_DATA) sq_msg;

#define FRXCP_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/
#define FRXCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC FUNC(void, FRXCP_CODE) FrXcp_FastCopy( P2VAR(uint8, AUTOMATIC, FRXCP_VAR_NOINIT) dest, P2CONST(uint8, AUTOMATIC, FRXCP_VAR_NOINIT) src, uint16 len );
STATIC FUNC(uint8, FRXCP_CODE) FrXcp_SendHandling( uint8 len, P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA) msg );
STATIC FUNC(uint8, FRXCP_CODE) FrXcp_GetFreePdu( FrXcp_XcpPacketType pduFilter, P2VAR(uint8, AUTOMATIC, FRXCP_VAR_NOINIT) pduIndex );

#define FRXCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**************************************************************************************************
*  Implementation
**************************************************************************************************/
#define FRXCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if defined ( XCP_ENABLE_ALIGNED_DTO )
/**************************************************************************************************
   Function name    : FrXcp_FastCopy
   ------------------------------------------------------------------------------------------------
   Description      : Fast 32 bit copy routine
   ------------------------------------------------------------------------------------------------
   Called by        : FrXcp
   ------------------------------------------------------------------------------------------------
   Parameter        : dest, src, len
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
STATIC FUNC(void, FRXCP_CODE) FrXcp_FastCopy( P2VAR(uint8, AUTOMATIC, FRXCP_VAR_NOINIT) dest, P2CONST(uint8, AUTOMATIC, FRXCP_VAR_NOINIT) src, uint16 len )
{
  while( len >= 4 )
  {
    *(P2VAR(uint32, AUTOMATIC, FRXCP_VAR_NOINIT))dest = *(P2CONST(uint32, AUTOMATIC, FRXCP_VAR_NOINIT))src; /* PRQA S 0310 */ /* MD_FrXcp_0310 */
    dest = &dest[4];
    src = &src[4];
    len -= 4;
  }
  while( len > 0 )
  {
    *(P2VAR(uint8, AUTOMATIC, FRXCP_VAR_NOINIT))dest = *(P2CONST(uint8, AUTOMATIC, FRXCP_VAR_NOINIT))src;
    dest = &dest[1];
    src = &src[1];
    len -= 1;
  }
}
#endif

/**************************************************************************************************
   Function name    : FrXcp_GetFreePdu
   ------------------------------------------------------------------------------------------------
   Description      : Returns a buffer that can be used for frame assembly
   ------------------------------------------------------------------------------------------------
   Called by        : FrXcp
   ------------------------------------------------------------------------------------------------
   Parameter        : pduFilter
                      pduIndex
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
STATIC FUNC(uint8, FRXCP_CODE) FrXcp_GetFreePdu( FrXcp_XcpPacketType pduFilter, P2VAR(uint8, AUTOMATIC, FRXCP_VAR_NOINIT) pduIndex )
{
  uint8_least i;
  for( i=0; i<FrXcp_CfgGetNumberTxLpduIds(); i++ )
  {
    if( (FrXcp_GetRtConfig()[i].FrXcpPduAttributes & (pduFilter | (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_BUSY)) == pduFilter )
    {
      if( ((pduFilter & (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EV) == (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EV) )
      {
        if ((FrXcp_GetRtConfig()[i].FrXcpPduAttributes & (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EVTBLOCKED) != (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EVTBLOCKED)
        {
          *pduIndex = (uint8)i;
          return((uint8)FRXCP_E_OK);
        }
      }
      else
      {
        *pduIndex = (uint8)i;
        return((uint8)FRXCP_E_OK);
      }
    }
  }
  return((uint8)FRXCP_E_NOT_OK);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**************************************************************************************************
   Function name    : FrXcp_TxConfirmation
   ------------------------------------------------------------------------------------------------
   Description      : This function is called by a lower layer if the respective L-PDU has been
                      transmitted
   ------------------------------------------------------------------------------------------------
   Called by        : Lower Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpTxPduId - ID of XCP L-PDU that has been transmitted
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) Xcp_FrIfTxConfirmation( PduIdType XcpTxPduId )
{
  PduIdType translatedTxPduId;
  /* Will not be interrupted by other functions, is normally called in interrupt context itself */

  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  /* Check of initialization. */
  FrXcp_CheckDetErrorReturnVoid( (uint8)FRXCP_UNINIT != FrXcp_InitializationState,
                                 FRXCP_TXCONFIRMATION_SERVICE_ID, FRXCP_E_NOT_INITIALIZED )
  
  translatedTxPduId = FrXcp_CfgGetTxPduTranslation(XcpTxPduId);
#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  if(FRXCP_INVALID_HANDLE == translatedTxPduId)
  {
    FrXcp_CallDetReportError(FRXCP_TXCONFIRMATION_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return;
  }
  /* Check PDU Range */
  if(translatedTxPduId >= (PduIdType)FrXcp_CfgGetNumberTxLpduIds())
  {
    FrXcp_CallDetReportError(FRXCP_TXCONFIRMATION_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return;
  }
#endif

  /* Return this PDU to our pool */
  XCP_FREE_PDU((uint8)translatedTxPduId);
  FrXcp_GetConfTimeoutTimer()[translatedTxPduId] = 0u;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**************************************************************************************************
   Function name    : FrXcp_RxIndication
   ------------------------------------------------------------------------------------------------
   Description      : This function is called by a lower layer if a XCP L-PDU has been received
   ------------------------------------------------------------------------------------------------
   Called by        : Lower Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpRxPduId - ID of the L-PDU that has been received
                      lSduDataPtr - Pointer to received L-PDU
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) Xcp_FrIfRxIndication
(
  PduIdType XcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, FRXCP_APPL_DATA) PduInfoPtr
)
{
  PduLengthType maxLength;
  PduIdType translatedRxPduId;
  /* Will not be interrupted by other functions, is normally called in interrupt context itself */

  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  /* Check of initialization. */
  FrXcp_CheckDetErrorReturnVoid( (uint8)FRXCP_UNINIT != FrXcp_InitializationState,
                                 FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_NOT_INITIALIZED )

  translatedRxPduId = FrXcp_CfgGetRxPduTranslation(XcpRxPduId);
#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  if(FRXCP_INVALID_HANDLE == translatedRxPduId)
  {
    FrXcp_CallDetReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return;
  }
  /* Check PDU Range */
  if(translatedRxPduId >= (PduIdType)FrXcp_CfgGetNumberRxLpduIds())
  {
    FrXcp_CallDetReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return;
  }
  /* Check for NULL pointer */
  if(PduInfoPtr->SduDataPtr == (P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA))NULL_PTR)
  {
    FrXcp_CallDetReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_NULL_POINTER);
    return;
  }
#endif

  maxLength = PduInfoPtr->SduLength;
  #if ( FRXCP_DEV_ERROR_DETECT == STD_ON )    
    if( maxLength > XCP_GET_CURRENT_MAX_FLX_LEN_BUF(translatedRxPduId + FrXcp_CfgGetNumberTxLpduIds()) )
    {
      FrXcp_CallDetReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_RX_INVALID_LENGTH);
      return;
    }
  #endif

  /* Is this PDU addressed for us? */
  if( FrXcp_CfgGetNAX() == PduInfoPtr->SduDataPtr[FRXCP_NAX_FRAME_OFFSET] )
  {
    /* Check if reception overflow happened */
    if( FrXcp_GetReceiveFrameSignal()[translatedRxPduId] > (uint8)0u )
    {
      #if( FRXCP_DEV_ERROR_DETECT == STD_ON )
      FrXcp_CallDetReportError(FRXCP_RXINDICATION_SERVICE_ID, FRXCP_E_RX_BUFFER_OVERFLOW);
      #endif
      return;
    }
    else
    {
       /* Copy the received frame to a temporary buffer */
       FRXCP_COPY( &(FrXcp_GetReceiveFrameCache()[translatedRxPduId].fc[0]), &PduInfoPtr->SduDataPtr[0], maxLength );
       /* And memorize reception */
       FrXcp_GetReceiveFrameSignal()[translatedRxPduId] = (uint8)1u;
    }  
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */ /* PRQA S 6010 */ /* MD_MSR_STPTH */

/**************************************************************************************************
   Function name    : FrXcp_TriggerTransmit
   ------------------------------------------------------------------------------------------------
   Description      : This function is called by a lower layer when a L-PDU has to be transmitted
   ------------------------------------------------------------------------------------------------
   Called by        : Lower Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpTxPduId - ID of L-PDU that has been triggered
                      SduDataPtr - Pointer to triggered L-PDU ID
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
extern FUNC(Std_ReturnType, FRXCP_CODE) Xcp_FrIfTriggerTransmit
(
  PduIdType XcpTxPduId,
  P2VAR(PduInfoType, AUTOMATIC, FRXCP_APPL_DATA) PduInfoPtr
)
{
  PduIdType translatedTxPduId;
  /* Will not be interrupted by other functions, is normally called in interrupt context itself */

  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return(E_NOT_OK);
  }
#endif

  /* Check of initialization. */
  FrXcp_CheckDetErrorReturnValue( (uint8)FRXCP_UNINIT != FrXcp_InitializationState,
                                   FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_NOT_INITIALIZED, (uint8)E_NOT_OK )

  translatedTxPduId = FrXcp_CfgGetTxPduTranslation(XcpTxPduId);
#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
  if(FRXCP_INVALID_HANDLE == translatedTxPduId)
  {
    FrXcp_CallDetReportError(FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return(E_NOT_OK);
  }
  /* Check PDU Range */
  if(translatedTxPduId >= (PduIdType)FrXcp_CfgGetNumberTxLpduIds())
  {
    FrXcp_CallDetReportError(FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_INV_PDU_ID);
    return(E_NOT_OK);
  }
  /* Check for NULL pointer */
  if(PduInfoPtr->SduDataPtr == (P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA))NULL_PTR)
  {
    FrXcp_CallDetReportError(FRXCP_TRIGGERTRANSMIT_SERVICE_ID, FRXCP_E_NULL_POINTER);
    return(E_NOT_OK);
  }
#endif

  FRXCP_COPY(PduInfoPtr->SduDataPtr, GET_TFC_PTR(translatedTxPduId), GET_TFC_LENGTH(translatedTxPduId));
  PduInfoPtr->SduLength = GET_TFC_LENGTH(translatedTxPduId);
  return(E_OK);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if defined ( XCP_ENABLE_DAQ ) && defined ( XCP_ENABLE_DAQ_RESUME )
/**************************************************************************************************
   Function name    : FrXcp_DaqResumeStore
   ------------------------------------------------------------------------------------------------
   Description      : This function is called in order to trigger storage of configuration data
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_DaqResumeStore( void )
{
  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  XcpAppl_DaqTlResumeStore( &FrXcp_GetRtConfig()[0] );
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**************************************************************************************************
   Function name    : FrXcp_DaqResumeClear
   ------------------------------------------------------------------------------------------------
   Description      : This function is called in order to clear stored configuration data
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_DaqResumeClear( void )
{
  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  XcpAppl_DaqTlResumeClear();
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/**************************************************************************************************
   Function name    : FrXcp_InitMemory
   ------------------------------------------------------------------------------------------------
   Description      : Initialize the XCP on FlexRay Transport Layer variables
   ------------------------------------------------------------------------------------------------
   Called by        : Application
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_InitMemory( void )
{
  FrXcp_InitializationState = (uint8)FRXCP_UNINIT;

#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  FrXcp_ControlState = kXcponFr_Control_Enable;
  FrXcp_ControlDeniedCount = 0; /* PRQA S 3408 */ /* MD_Xcp_3408 */
#endif

}

/**************************************************************************************************
   Function name    : FrXcp_Init
   ------------------------------------------------------------------------------------------------
   Description      : Initialize the XCP on FlexRay Transport Layer
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_Init( P2CONST(FrXcp_ConfigType, AUTOMATIC, FRXCP_PBCFG) CfgPtr )
{
  uint8_least i;

  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  FrXcp_InitializationState = (uint8)FRXCP_UNINIT;

#if ( FrXcp_IsPostbuild() )
  FrXcp_SilentBswCheckErrorReturnVoid( (P2CONST(void, AUTOMATIC, FRXCP_PBCFG))NULL_PTR != CfgPtr,
                                       FRXCP_INIT_SERVICE_ID, FRXCP_E_NULL_POINTER )

  FrXcp_PBCfgPtr = CfgPtr;
#else
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  CfgPtr = CfgPtr;
  #endif
#endif

  /* Initialize volatile Pdu filter list */
  i = (uint8_least)FrXcp_CfgGetDescriptorListSize();
  while( i > (uint8_least)0u )
  {
    i--;
    FrXcp_GetRtConfig()[i].FrXcpPduAttributes = FrXcp_CfgGetXcpPacketFilter(i);
    FrXcp_GetRtConfig()[i].FrXcpPduLength = FrXcp_CfgGetMaxFlxLenBuf(i);
  }

  i = (uint8_least)FrXcp_CfgGetNumberOfTransmitFC();
  while( i > (uint8_least)0u )
  {
    i--;
    FrXcp_GetTransmitFC()[i].fc[FRXCP_NAX_FRAME_OFFSET] = FrXcp_CfgGetNAX();
    FrXcp_GetAggregatedLength()[i] = (uint8)0u;
    FrXcp_GetConfTimeoutTimer()[i] = (FrXcp_TimeoutTimerType)0u;
  }

  i = (uint8_least)FrXcp_CfgGetNumberRxLpduIds();
  while( i > (uint8_least)0u )
  {
    i--;
    FrXcp_GetReceiveFrameSignal()[i] = (uint8)0u;
  }

  /* Check if we have to use Resume Mode */
#if defined ( XCP_ENABLE_DAQ )
  #if defined ( XCP_ENABLE_DAQ_RESUME )
    (void)XcpAppl_DaqTlResume( &FrXcp_GetRtConfig()[0] ); /* ESCAN00071562 */
    i = (uint8_least)FrXcp_CfgGetDescriptorListSize();
    /* Clear BUSY flags upon PDU information restore */
    while( i > (uint8_least)0u )
    {
      i--;
      FrXcp_GetRtConfig()[i].FrXcpPduAttributes &= (FrXcp_XcpPacketType)~FRXCP_LPDU_TYPE_BUSY;
    }
  #endif
#endif

#if (CTR_FRAME_OFFSET > 0)
  FrXcp_GlobalSequenceCounter = (uint8)0u;
#endif

  sq_len = (uint8)0u;
  sq_msg = (P2CONST(uint8, FRXCP_VAR_NOINIT, FRXCP_APPL_DATA))NULL_PTR;

#if ( FRXCP_USE_PDUMODE == STD_ON )
  FrXcp_PduState = FRXCP_SET_OFFLINE;
#endif

  FrXcp_InitializationState = (uint8)FRXCP_INIT;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**************************************************************************************************
   Function name    : FrXcp_TLService
   ------------------------------------------------------------------------------------------------
   Description      : This function handles custom, Transport Layer specific commands which are:
                      FRXCP_CMD_FLX_ASSIGN
                      FRXCP_CMD_FLX_ACTIVATE
                      FRXCP_CMD_FLX_DEACTIVATE
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : pCmd: Pointer to cmd string
   ------------------------------------------------------------------------------------------------
   Returncode       : error code
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(uint8, FRXCP_CODE) FrXcp_TLService( uint8 Xcp_Channel, P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA) pCmd )
{
  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return(XCP_CMD_DENIED);
  }
#endif

  /* Null ptr check is omitted as the Vector protocol layer never calls this service with a null pointer */
  FrXcp_CheckDetErrorReturnValue( (uint8)FRXCP_UNINIT != FrXcp_InitializationState,
                                   FRXCP_TL_SERVICE_ID, FRXCP_E_NOT_INITIALIZED, (uint8)XCP_CMD_DENIED )

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  Xcp_Channel = Xcp_Channel;
#endif

  switch( pCmd[FRXCP_IDX_TL_CMD] )
  {
    /* ------------------------- FRXCP_CMD_FLX_ASSIGN ------------------------- */
    case (uint8)FRXCP_CMD_FLX_ASSIGN : 
    {
      /*---------------------------------------------------------------------------*/
      /* FLX_ASSIGN Frame plausibility checks */
      if( ((uint8)0xFFu == pCmd[FRXCP_IDX_FLX_BUF]) &&
          ((uint8)FRXCP_LPDU_TYPE_VARIABLE == pCmd[FRXCP_IDX_XCP_PACKET_TYPE]) )
      { /* We have to perform a complete reset */
        uint8_least i;
        /* Initialize volatile Pdu filter list */
        i = (uint8_least)FrXcp_CfgGetDescriptorListSize();
        while( i > (uint8_least)0u )
        {
          i--;
          FrXcp_GetRtConfig()[i].FrXcpPduAttributes = FrXcp_CfgGetXcpPacketFilter(i);
          FrXcp_GetRtConfig()[i].FrXcpPduLength = FrXcp_CfgGetMaxFlxLenBuf(i);
        }
        return((uint8)XCP_CMD_OK);
      }
      else
      if( pCmd[FRXCP_IDX_FLX_BUF] >= FrXcp_CfgGetDescriptorListSize() )
      { /* If the buffer index is out of range, we return XCP_CMD_OUT_OF_RANGE error */
        return((uint8)XCP_CMD_OUT_OF_RANGE);
      }
      else
      {
        ; /* Concluding else */
      }

      if( pCmd[FRXCP_IDX_MAX_FLX_LEN_BUF] > FrXcp_CfgGetMaxFlxLenBuf(pCmd[FRXCP_IDX_FLX_BUF]) )
      {
        return((uint8)XCP_CMD_OUT_OF_RANGE);
      }

      /*---------------------------------------------------------------------------*/
      /* Reconfigure Buffer */
      if( 1 == FrXcp_CfgGetIsReconfigurable(pCmd[FRXCP_IDX_FLX_BUF]) )
      {
        FrXcp_InterruptDisableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
        /* Store new buffer length */
        FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduLength = pCmd[FRXCP_IDX_MAX_FLX_LEN_BUF];

        if( (uint8)FRXCP_LPDU_TYPE_VARIABLE == pCmd[FRXCP_IDX_XCP_PACKET_TYPE] )
        { /* We have to reset our current PDU to its initial setting */
          FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduAttributes = FrXcp_CfgGetXcpPacketFilter(pCmd[FRXCP_IDX_FLX_BUF]);
          FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduLength = FrXcp_CfgGetMaxFlxLenBuf(pCmd[FRXCP_IDX_FLX_BUF]);
        }

        FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduAttributes = (pCmd[FRXCP_IDX_XCP_PACKET_TYPE] & (FrXcp_XcpPacketType)FRXCP_PACKET_FILTER_MASK)
                                                                                                      | (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EVTBLOCKED;
        FrXcp_InterruptEnableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
      }
      else
      {
        return((uint8)XCP_CMD_DENIED);
      }
      return((uint8)XCP_CMD_OK);
    }

    /* ------------------------- FRXCP_CMD_FLX_ACTIVATE ------------------------- */
    case (uint8)FRXCP_CMD_FLX_ACTIVATE :
    {
      /* SBSW_XcpOnFrAsr_012 */
      if( pCmd[FRXCP_IDX_FLX_BUF] >= FrXcp_CfgGetDescriptorListSize() )
      { /* If the buffer index is out of range, we return XCP_CMD_OUT_OF_RANGE error */
        return((uint8)XCP_CMD_OUT_OF_RANGE);
      }
      FrXcp_InterruptDisableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
      if((FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduAttributes & (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EV) > (FrXcp_XcpPacketType)0u)
      {
        FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduAttributes &= (FrXcp_XcpPacketType)~FRXCP_LPDU_TYPE_EVTBLOCKED;
        FrXcp_InterruptEnableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
        return((uint8)XCP_CMD_OK);
      }
      FrXcp_InterruptEnableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
      return((uint8)XCP_CMD_OUT_OF_RANGE);
    }

    /* ------------------------- FRXCP_CMD_FLX_DEACTIVATE ------------------------- */
    case (uint8)FRXCP_CMD_FLX_DEACTIVATE :
    {
      /* SBSW_XcpOnFrAsr_012 */
      if( pCmd[FRXCP_IDX_FLX_BUF] >= FrXcp_CfgGetDescriptorListSize() )
      { /* If the buffer index is out of range, we return XCP_CMD_OUT_OF_RANGE error */
        return((uint8)XCP_CMD_OUT_OF_RANGE);
      }
      FrXcp_InterruptDisableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
      if((FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduAttributes & (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EV) > (FrXcp_XcpPacketType)0u)
      {
        FrXcp_GetRtConfig()[pCmd[FRXCP_IDX_FLX_BUF]].FrXcpPduAttributes |= (FrXcp_XcpPacketType)FRXCP_LPDU_TYPE_EVTBLOCKED;
        FrXcp_InterruptEnableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
        return((uint8)XCP_CMD_OK);
      }
      FrXcp_InterruptEnableRx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
      return((uint8)XCP_CMD_OUT_OF_RANGE);
    }

    default :
    {
      ;
    }
  }

  return((uint8)XCP_CMD_UNKNOWN);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */ /* PRQA S 6030 */ /* MD_MSR_STCYC */ /* PRQA S 6010 */ /* MD_MSR_STPTH */

/**************************************************************************************************
   Function name    : FrXcp_Send
   ------------------------------------------------------------------------------------------------
   Description      : Prepare transmission of the referenced frame
   ------------------------------------------------------------------------------------------------
   Called by        : XCP Protocol Layer
   ------------------------------------------------------------------------------------------------
   Parameter        : len: length of message to send
                      msg: pointer to message
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_Send( uint8 Xcp_Channel, uint8 len, P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA) msg )
{
  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  Xcp_Channel = Xcp_Channel;
#endif

  sq_msg = msg;
  sq_len = len;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**************************************************************************************************
   Function name    : FrXcp_SendHandling
   ------------------------------------------------------------------------------------------------
   Description      : Internal handling of frame assembly
   ------------------------------------------------------------------------------------------------
   Called by        : internal
   ------------------------------------------------------------------------------------------------
   Parameter        : len: length of message to send
                      msg: pointer to message
   ------------------------------------------------------------------------------------------------
   Returncode       : FRXCP_TP_OK Frame was processed successfully
                      FRXCP_TP_BUSY Frame could not be inserted in frame buffer
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
STATIC FUNC(uint8, FRXCP_CODE) FrXcp_SendHandling( uint8 len, P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA) msg )
{
  FrXcp_XcpPacketType PacketFilter;
  uint8 TxPduHandle;
  uint8 result;

  result = (uint8)FRXCP_TP_OK;

#if ( FRXCP_USE_PDUMODE == STD_ON )
  if( FRXCP_SET_OFFLINE == FrXcp_PduState )
  { /* We are in offline mode, return and keep message */
      return( (uint8)FRXCP_TP_BUSY );
  }
#endif

  /* Determine type of current XCP frame */
  PacketFilter = XCP_GET_XCP_FRAME_TYPE(msg);

#if ( FRXCP_FRAME_CONCATENATION == STD_OFF )

  if( (uint8)FRXCP_E_OK == FrXcp_GetFreePdu( PacketFilter, &TxPduHandle ) )
  {
    PduInfoType PduInfoStruct;

    CREATE_TFC_HEADER(TxPduHandle);
    /* The Sequence Counter is incremented individually with each XCP-Frame passed on by the Protocol Layer */
    INCREMENT_SEQUENCE_COUNTER();

    /* SBSW_XcpOnFrAsr_015 */
    if( len > XCP_GET_CURRENT_MAX_FLX_LEN_BUF(TxPduHandle))
    {
      len = (uint8)XCP_GET_CURRENT_MAX_FLX_LEN_BUF(TxPduHandle); /* ESCAN00078873 */
    }
    INSERT_TFC_XCP_FRAME(TxPduHandle, msg, len);

    FINALIZE_TFC(TxPduHandle);
    PduInfoStruct.SduDataPtr = GET_TFC_PTR(TxPduHandle);
    PduInfoStruct.SduLength  = (PduLengthType)GET_TFC_LENGTH(TxPduHandle);
    XCP_RESERVE_PDU(TxPduHandle);
    FrXcp_GetConfTimeoutTimer()[TxPduHandle] = FrXcp_CfgGetConfTimeoutReload();
    if((Std_ReturnType)E_NOT_OK == FRXCP_TRANSMIT(FrXcp_CfgGetXcpPduId(TxPduHandle), &PduInfoStruct))
    {  /* Transmit error happened */
      XCP_FREE_PDU(TxPduHandle);
      FrXcp_GetConfTimeoutTimer()[TxPduHandle] = 0u;
      result = (uint8)FRXCP_TP_BUSY;
    }
  }
  else
  {
    XCP_MEMORIZE_OVERRUN();
    result = (uint8)FRXCP_TP_BUSY;
  }

#else /* ( FRXCP_FRAME_CONCATENATION == STD_ON ) */

  if( (uint8)FRXCP_E_OK == FrXcp_GetFreePdu( PacketFilter, &TxPduHandle ) )
  {
    if( (uint8)0u == GET_TFC_LENGTH(TxPduHandle) )
    {
      CREATE_TFC_HEADER(TxPduHandle);
      /* The Sequence Counter is incremented individually with each newly allocated PDU buffer */
      INCREMENT_SEQUENCE_COUNTER();
    }

    if((GET_TFC_LENGTH(TxPduHandle) + len + (uint8)1u) <= XCP_GET_CURRENT_MAX_FLX_LEN_BUF(TxPduHandle))
    {
      INSERT_TFC_XCP_FRAME(TxPduHandle, msg, len);
    }
    else
    {
      PduInfoType PduInfoStruct;
      FINALIZE_TFC(TxPduHandle);
      PduInfoStruct.SduDataPtr = GET_TFC_PTR(TxPduHandle);
      PduInfoStruct.SduLength  = (PduLengthType)GET_TFC_LENGTH(TxPduHandle);
      XCP_RESERVE_PDU(TxPduHandle);
      FrXcp_GetConfTimeoutTimer()[TxPduHandle] = FrXcp_CfgGetConfTimeoutReload();
      if((Std_ReturnType)E_NOT_OK == FRXCP_TRANSMIT(FrXcp_CfgGetXcpPduId(TxPduHandle), &PduInfoStruct))
      { /* Transmit error happened */
        XCP_FREE_PDU(TxPduHandle);
        FrXcp_GetConfTimeoutTimer()[TxPduHandle] = 0u;
        result = (uint8)FRXCP_TP_BUSY;
      }

      if( (uint8)FRXCP_E_OK == FrXcp_GetFreePdu( PacketFilter, &TxPduHandle ) )
      {
        CREATE_TFC_HEADER(TxPduHandle);
        /* The Sequence Counter is incremented individually with each XCP-Frame passed on by the Protocol Layer */
        INCREMENT_SEQUENCE_COUNTER();
        INSERT_TFC_XCP_FRAME(TxPduHandle, msg, len);
      }
      else
      {
        if( (uint8)FRXCP_LPDU_TYPE_EV != PacketFilter )
        {
          XCP_MEMORIZE_OVERRUN();
          result = (uint8)FRXCP_TP_BUSY;
        }
      }
    }
  }
  else
  {
    if( (uint8)FRXCP_LPDU_TYPE_EV != PacketFilter )
    {
      XCP_MEMORIZE_OVERRUN();
      result = (uint8)FRXCP_TP_BUSY;
    }
  }
#endif

  return( result );
} /* PRQA S 2006 */ /* MD_MSR_14.7 */ /* PRQA S 6010 */ /* MD_MSR_STPTH */ /* PRQA S 6030 */ /* MD_MSR_STCYC */

/**************************************************************************************************
   Function name    : FrXcp_SendFlush
   ------------------------------------------------------------------------------------------------
   Description      : Purge the current Frame Cache.
                      Only needed, when frame concatenation is enabled
   ------------------------------------------------------------------------------------------------
   Called by        : Application: after all Xcp_Events per cycle happened before actual transmission
                    : XCP Protocol Layer: when a transmission requires immediate attention (RES/EV)
   ------------------------------------------------------------------------------------------------
   Parameter        : XcpFlushTypeSel: determines which type of xcp frames are flushed
                                       XCP_FLUSH_CTO: Only CTOs are flushed
                                       XCP_FLUSH_DTO: Only DTOs are flushed
                                       XCP_FLUSH_ALL: CTOs and DTOs are flushed
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_SendFlush( uint8 Xcp_Channel, uint8 XcpFlushTypeSel )
{
#if ( FRXCP_FRAME_CONCATENATION == STD_ON )
  PduInfoType PduInfoStruct;
  uint8       TxPduHandle;
  uint8       i;
  uint8       last;

  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  FrXcp_CheckDetErrorReturnVoid( (uint8)FRXCP_UNINIT != FrXcp_InitializationState,
                                 FRXCP_SENDFLUSH_SERVICE_ID, FRXCP_E_NOT_INITIALIZED )

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  Xcp_Channel = Xcp_Channel;
#endif

#if ( FRXCP_USE_PDUMODE == STD_ON )
  if( FRXCP_SET_OFFLINE == FrXcp_PduState )
  { /* We are in offline mode, return and keep message */
    return;
  }
#endif

  i = (uint8)0u;
  last = (uint8)sizeof(LPDU_TYPES);
  if(XcpFlushTypeSel == (uint8)XCP_FLUSH_CTO)
  {
    last--;
  }
  else
  if(XcpFlushTypeSel == (uint8)XCP_FLUSH_DTO)
  {
    i += (uint8)2u;
  }
  else
  {
    ; /* Concluding else */
  }

  /* Check all PDUs */
  for(; i<last; i++)
  {
    FrXcp_InterruptDisableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
    if( (uint8)FRXCP_E_OK == FrXcp_GetFreePdu( LPDU_TYPES[i], &TxPduHandle ) )
    {
      if( GET_TFC_LENGTH(TxPduHandle) > (uint8)0u )
      {
        FINALIZE_TFC(TxPduHandle);
        PduInfoStruct.SduDataPtr = GET_TFC_PTR(TxPduHandle);
        PduInfoStruct.SduLength  = (PduLengthType)GET_TFC_LENGTH(TxPduHandle);
        XCP_RESERVE_PDU(TxPduHandle);
        FrXcp_InterruptEnableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
        FrXcp_GetConfTimeoutTimer()[TxPduHandle] = FrXcp_CfgGetConfTimeoutReload();
        if((Std_ReturnType)E_NOT_OK == FRXCP_TRANSMIT(FrXcp_CfgGetXcpPduId(TxPduHandle), &PduInfoStruct))
        { /* Transmit error happened */
          XCP_FREE_PDU(TxPduHandle);
          FrXcp_GetConfTimeoutTimer()[TxPduHandle] = 0u;
        }
      }
      else
      {
        FrXcp_InterruptEnableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
      }
    }
    else
    {
      FrXcp_InterruptEnableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
    }
  }
#else
  /* Activation control */
# if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
# endif

  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  XcpFlushTypeSel = XcpFlushTypeSel;
  #endif
#endif /* FRXCP_FRAME_CONCATENATION */
} /* PRQA S 2006 */ /* MD_MSR_14.7 */ /* PRQA S 6010 */ /* MD_MSR_STPTH */ /* PRQA S 6030 */ /* MD_MSR_STCYC */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

#if ( FRXCP_VERSION_INFO_API == STD_ON )
/**************************************************************************************************
   Function name    : FrXcp_GetVersionInfo
   ------------------------------------------------------------------------------------------------
   Description      : Returns version information of module
   ------------------------------------------------------------------------------------------------
   Called by        : Application
   ------------------------------------------------------------------------------------------------
   Parameter        : FrXcpVerInfoPtr: Pointer to location at which version information
                                       shall be stored at
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, FRXCP_APPL_DATA) FrXcpVerInfoPtr
)
{
  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  /* Since this service only access non-volatile data and no channel parameter is passed,
     checking of the channel handle and initialization is omitted. */
  FrXcp_SilentBswCheckErrorReturnVoid( (P2CONST(void, AUTOMATIC, FRXCP_APPL_DATA))NULL_PTR != FrXcpVerInfoPtr,
                                        FRXCP_GETVERSIONINFO_SERVICE_ID, FRXCP_E_NULL_POINTER )
  FrXcpVerInfoPtr->vendorID = FRXCP_VENDOR_ID;
  FrXcpVerInfoPtr->moduleID = (uint8)FRXCP_MODULE_ID;
  FrXcpVerInfoPtr->sw_major_version = FRXCP_MAJOR_VERSION;
  FrXcpVerInfoPtr->sw_minor_version = FRXCP_MINOR_VERSION;
  FrXcpVerInfoPtr->sw_patch_version = FRXCP_PATCH_VERSION;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif
  /* FRXCP_VERSION_INFO_API */

/**************************************************************************************************
   Function name    : FrXcp_MainFunctionRx
   ------------------------------------------------------------------------------------------------
   Description      : Cyclic task, must be called for reception processing
   ------------------------------------------------------------------------------------------------
   Called by        : Application
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_MainFunctionRx( void )
{
  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  FrXcp_Rtm_Start(FrXcp_MainFunctionRx);
  {
    uint8_least pduIdx;

    if( (uint8)FRXCP_INIT == FrXcp_InitializationState )
    {
      for( pduIdx = (uint8_least)0u; pduIdx < (uint8_least)FrXcp_CfgGetNumberRxLpduIds(); pduIdx++ )
      {
        if( FrXcp_GetReceiveFrameSignal()[pduIdx] > (uint8)0u )
        {
          #if ( FRXCP_FRAME_CONCATENATION == STD_OFF )
            /* Process command */
            if(0xff == FrXcp_GetReceiveFrameCache()[pduIdx].fc[XCP_FRAME_START])
            { /* In case of connect we set this as active TL */
              Xcp_SetActiveTl(XCP_TRANSPORT_LAYER_FR, kFrXcpMaxCTO, kFrXcpMaxDTO, XCP_TRANSPORT_LAYER_FR);
            }
            if( XCP_TRANSPORT_LAYER_FR == Xcp_GetActiveTl(XCP_TRANSPORT_LAYER_FR) )
            {
              Xcp_Command(XCP_TRANSPORT_LAYER_FR, (P2CONST(uint32, AUTOMATIC, FRXCP_APPL_DATA))(uint32)&FrXcp_GetReceiveFrameCache()[pduIdx].fc[XCP_FRAME_START]); /* PRQA S 0306 */ /* MD_FrXcp_0306 */
            }
          #else
            {
              uint16 frame_idx;
              frame_idx = (uint16)XCP_FRAME_START;

              while((FrXcp_GetReceiveFrameCache()[pduIdx].fc[frame_idx] > (uint8)0u) && /* Is the length > 0? */
                    ((frame_idx + (uint16)FrXcp_GetReceiveFrameCache()[pduIdx].fc[frame_idx] + (uint16)1)
                    <= (uint16)XCP_GET_CURRENT_MAX_FLX_LEN_BUF(pduIdx + FrXcp_CfgGetNumberTxLpduIds())) ) /* Is it within PDU size? */
              {
                /* Process command */
                if(0xff == FrXcp_GetReceiveFrameCache()[pduIdx].fc[frame_idx + 1u])
                { /* In case of connect we set this as active TL */
                  Xcp_SetActiveTl(XCP_TRANSPORT_LAYER_FR, kFrXcpMaxCTO, kFrXcpMaxDTO, XCP_TRANSPORT_LAYER_FR);
                }
                if( XCP_TRANSPORT_LAYER_FR == Xcp_GetActiveTl(XCP_TRANSPORT_LAYER_FR) )
                {
                  Xcp_Command(XCP_TRANSPORT_LAYER_FR, (P2CONST(uint32, AUTOMATIC, FRXCP_APPL_DATA))(uint32)&FrXcp_GetReceiveFrameCache()[pduIdx].fc[frame_idx + 1u]); /* PRQA S 0306 */ /* MD_FrXcp_0306 */
                }

                /* Move to next possible xcp-frame */
                frame_idx += ((uint16)FrXcp_GetReceiveFrameCache()[pduIdx].fc[frame_idx] + (uint16)1u);
                /* Adjust according to alignment requirements */
                frame_idx = XCP_ALIGN(frame_idx);
              }
            }
          #endif
          /* Release Rx buffer */
          FrXcp_GetReceiveFrameSignal()[pduIdx] = (uint8)0u;
        }
      }
    }
  }
  FrXcp_Rtm_Stop(FrXcp_MainFunctionRx);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**************************************************************************************************
   Function name    : FrXcp_MainFunctionTx
   ------------------------------------------------------------------------------------------------
   Description      : Cyclic task, must be called for transmission processing
   ------------------------------------------------------------------------------------------------
   Called by        : XcpPl
   ------------------------------------------------------------------------------------------------
   Parameter        : none
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_MainFunctionTx( void )
{
  uint8_least i;

  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  FrXcp_Rtm_Start(FrXcp_MainFunctionTx);

  if( (uint8)FRXCP_INIT == FrXcp_InitializationState )
  {
    FrXcp_InterruptDisableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
    /* PRQA S 3415 1 */ /* MISRA-C:2004 Rule 12.4, The side effects are wanted for optimization */
    while( (sq_len > (uint8)0u) && ((uint8)FRXCP_TP_OK == FrXcp_SendHandling(sq_len, sq_msg)) ) /* PRQA S 3415 */ /* MD_FrXcp_3415 */
    {
      /* sq_len is set by FrXcp_Send */
      sq_len  = (uint8)0u;
      (void)Xcp_SendCallBack(XCP_TRANSPORT_LAYER_FR);
    }
    FrXcp_SendFlush(XCP_TRANSPORT_LAYER_FR, (uint8)XCP_FLUSH_ALL);
    FrXcp_InterruptEnableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
  }

  /* Check for Tx Confirmation timeouts */
  for( i = 0; i < (uint8_least)FrXcp_CfgGetNumberOfTransmitFC(); i++ )
  {
    FrXcp_InterruptDisableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
    if( FrXcp_GetConfTimeoutTimer()[i] > 0u)
    {
      FrXcp_GetConfTimeoutTimer()[i]--;
      FrXcp_InterruptEnableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
      if( 0u == FrXcp_GetConfTimeoutTimer()[i] )
      {
        /* Timeout happened, release PDU */
        XCP_FREE_PDU(i);
      }
    }
    else
    {
      FrXcp_InterruptEnableTx(); /* PRQA S 3109 */ /* MD_FrXcp_3109 */
    }
  }

  FrXcp_Rtm_Stop(FrXcp_MainFunctionTx);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if ( FRXCP_USE_PDUMODE == STD_ON )
/**************************************************************************************************
   Function name    : FrXcp_SetPduMode
   ------------------------------------------------------------------------------------------------
   Description      : Enable or disable the component
   ------------------------------------------------------------------------------------------------
   Called by        : State Manager
   ------------------------------------------------------------------------------------------------
   Parameter        : command: FRXCP_SET_ONLINE - Activate Transport Layer
                               FRXCP_SET_OFFLINE - Deactivate Transport Layer
   ------------------------------------------------------------------------------------------------
   Returncode       : none
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRXCP_CODE) FrXcp_SetPduMode( NetworkHandleType XcpNwH, FrXcp_PduSetModeType PduMode )
{
  /* Activation control */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
  if ( FrXcp_ControlState == kXcponFr_Control_Disable )
  {
    FrXcp_ControlDeniedCount++;
    return;
  }
#endif

  FrXcp_CheckDetErrorReturnVoid( (uint8)FRXCP_UNINIT != FrXcp_InitializationState,
                                 FRXCP_PDUMODE_SERVICE_ID, FRXCP_E_NOT_INITIALIZED )

  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  XcpNwH = XcpNwH;
  #endif

  FrXcp_PduState = PduMode;
}
#endif

#define FRXCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*****************************************************************************/
/* Consistency checks ( XCP Transport Layer on FLX specific )                */
/*****************************************************************************/

/* Check consistency of Transport Layer configuration */
#if defined ( XCP_TRANSPORT_LAYER_TYPE_FLEXRAY_ASR )
#else
  #error "FrXcp.c: Configuration for Transport Layer on FlexRay doesn't exist!"
#endif

/* Check range of kXcpMaxCTO and kXcpMaxDTO */
#if (kFrXcpMaxCTO >= 12)
#else
  #error "FrXcp.c: consistency error, MAX_CTO must be at least 12."
#endif

#if(kFrXcpMaxDTO <= (FRXCP_PDU_SIZE - HEADER_SIZE))
#else
  #error "FrXcp.c: consistency error, MAX_DTO must not be greater than: "(FRXCP_PDU_SIZE - HEADER_SIZE)
#endif
#if(kFrXcpMaxCTO <= (FRXCP_PDU_SIZE - HEADER_SIZE))
#else
  #error "FrXcp.c: consistency error, MAX_CTO must not be greater than: "(FRXCP_PDU_SIZE - HEADER_SIZE)
#endif

#if ( FRXCP_FRAME_CONCATENATION != STD_ON ) && ( FRXCP_FRAME_CONCATENATION != STD_OFF )
  #error "FrXcp.c: consistency error, set FRXCP_FRAME_CONCATENATION either to STD_ON or STD_OFF."
#endif

#if ( FRXCP_SEQUENCE_COUNTER != STD_ON ) && ( FRXCP_SEQUENCE_COUNTER != STD_OFF )
  #error "FrXcp.c: consistency error, set FRXCP_SEQUENCE_COUNTER either to STD_ON or STD_OFF."
#endif

#if ( FRXCP_USE_DECOUPLED_MODE != STD_ON ) && ( FRXCP_USE_DECOUPLED_MODE != STD_OFF )
  #error "FrXcp.c: consistency error, set FRXCP_USE_DECOUPLED_MODE either to STD_ON or STD_OFF."
#endif

/* module specific MISRA deviations:
  MD_FrXcp_0306:  Rule 11.3
      Reason:     Proper alignement guaranteed by union.
      Risk:       There is no risk as the proper alignment is guaranteed by the union.
      Prevention: Covered by code review.
  MD_FrXcp_0310:  Rile 11.4
      Reason:     Optimization of copy operation
      Risk:       Parameters pointing to not aligned arrays
      Prevention: The function is used internally only. All passed parameters are guaranteed to be aligned.
  MD_FrXcp_3109:  Rule 14.3
      Reason:     Macro is in external module and could be function instead
      Risk:       No Risk
      Prevention: Covered by code review.
  MD_FrXcp_3218:  Rule 8.7
      Reason:     In order to use AUTOSAR Memory Mapping these constants are defined in a global scope.
      Risk:       There is no risk as global definition does not influence functionality.
      Prevention: Covered by code review.
  MD_Xcp_3408:    Rule 8.8
      Reason:     The variable is not defined as static to be accessible for debugging. No prototype is required for this.
      Risk:       There is no risk as this variable is not accessed externally.
      Prevention: Covered by code review.
  MD_FrXcp_3415:  Rule 12.4
      Reason:     For optimization reasons the side effects during the wile loop are taken into consideration.
      Risk:       There is no risk as the conditions are executed sequentially.
      Prevention: Covered by code review.
*/

