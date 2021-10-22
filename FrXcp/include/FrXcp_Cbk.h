/**************************************************************************************************
   Project Name: AUTOSAR XCP on FlexRay Transport Layer
      File Name: FrXcp_CbkS.h

    Description: Callback header of the XCP on FlexRay Transport Layer

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

#if !defined(__FRXCP_CBK_H__)
#define __FRXCP_CBK_H__

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "Std_Types.h"            /* Include standard types */
#include "FrXcp.h"

/**************************************************************************************************
* Version check
**************************************************************************************************/
#if defined ( __FRXCP_H__ )
  #if ( CP_XCPONFRASR_VERSION != 0x0400u )
    #error "The header versions of FrXcp.h and FrXcp_Cbk.h are incompatible."
  #endif
  #if ( CP_XCPONFRASR_RELEASE_VERSION != 0x01u )
    #error "The release versions of FrXcp.h and FrXcp_Cbk.h are incompatible."
  #endif
#endif

/**************************************************************************************************
* Prototypes of callback functions
**************************************************************************************************/

/*------------------ XCP on FlexRay services called by FlexRay IF ------------------*/

#define FRXCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* This function is called by the FlexRay Interface after a XcpOnFr L-PDU has been transmitted. */
extern FUNC(void, FRXCP_CODE) Xcp_FrIfTxConfirmation( PduIdType XcpTxPduId );

/* This function is called by the FlexRay Interface after a XcpOnFr L-PDU has been received. */
extern FUNC(void, FRXCP_CODE) Xcp_FrIfRxIndication
(
  PduIdType XcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, FRXCP_APPL_DATA) PduInfoPtr
);

/* This function is called by the FlexRay Interface if a XcpOnFr L-PDU transmission is pending. */
extern FUNC(Std_ReturnType, FRXCP_CODE) Xcp_FrIfTriggerTransmit
(
  PduIdType XcpTxPduId,
  P2VAR(PduInfoType, AUTOMATIC, FRXCP_APPL_DATA) PduInfoPtr
);

#define FRXCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif
  /* __FRXCP_CBK_H__ */
