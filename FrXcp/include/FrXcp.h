/**************************************************************************************************
   Project Name: AUTOSAR XCP on FlexRay Transport Layer
      File Name: FrXcpS.h

    Description: XCP on FlexRay Transport Layer Header File

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
#ifndef __FRXCP_H__
#define __FRXCP_H__

/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "ComStack_Types.h"
#include "FrXcp_Cfg.h"
#include "FrXcp_Types.h"
#include "Xcp.h"

/**************************************************************************************************
* Version
**************************************************************************************************/
/* BCD coded version number */
/* ##V_CFG_MANAGEMENT ##CQProject : Cp_XcpOnFrAsr CQComponent : Implementation */
#define CP_XCPONFRASR_VERSION         0x0400u
#define CP_XCPONFRASR_RELEASE_VERSION 0x01u

/**************************************************************************************************
* Global defines
**************************************************************************************************/
/* Vendor ID for Vctr Informatik */
#define FRXCP_VENDOR_ID_DEFINITION      30u
 /* FlexRay XCP ID */
#define FRXCP_MODULE_ID_DEFINITION      211u

/* The controller index is always 0 atm */
#define FRXCP_CONTROLLER_IDX			0u

/* Interrupt enable and disable functions */
#if defined ( ApplXcpInterruptDisable )
#else
# define ApplXcpInterruptDisable()            SchM_Enter_Xcp_FRXCP_EXCLUSIVE_AREA_0()
#endif
#define FrXcp_InterruptDisableRx()            SchM_Enter_Xcp_FRXCP_EXCLUSIVE_AREA_1()
#define FrXcp_InterruptDisableTx()            SchM_Enter_Xcp_FRXCP_EXCLUSIVE_AREA_2()

#if defined ( ApplXcpInterruptEnable )
#else
# define ApplXcpInterruptEnable()             SchM_Exit_Xcp_FRXCP_EXCLUSIVE_AREA_0()
#endif
#define FrXcp_InterruptEnableRx()             SchM_Exit_Xcp_FRXCP_EXCLUSIVE_AREA_1()
#define FrXcp_InterruptEnableTx()             SchM_Exit_Xcp_FRXCP_EXCLUSIVE_AREA_2()

#if !defined ( FRXCP_USE_PDUMODE )
#  define FRXCP_USE_PDUMODE STD_OFF
#endif

#if !defined ( FRXCP_RECONFIG_LPDU )
# define FRXCP_RECONFIG_LPDU STD_OFF
#endif

#if !defined ( FRXCP_VERSION_INFO_API )
# define FRXCP_VERSION_INFO_API STD_OFF
#endif

#if !defined ( FRXCP_AMD_RUNTIME_MEASUREMENT )
# define FRXCP_AMD_RUNTIME_MEASUREMENT STD_OFF
#endif

#define FRXCP_E_NOT_OK    1u
#define FRXCP_E_OK        0u

#define FRXCP_TP_BUSY     1u
#define FRXCP_TP_OK       0u

/* Development errors */
#if ( FRXCP_DEV_ERROR_DETECT == STD_ON )
/* Definition of the API ID */
  #define FRXCP_INIT_SERVICE_ID                   0u
  #define FRXCP_TL_SERVICE_ID                     1u
  #define FRXCP_SENDCTO_SERVICE_ID                2u
  #define FRXCP_SENDDTO_SERVICE_ID                3u
  #define FRXCP_SENDFLUSH_SERVICE_ID              4u
  #define FRXCP_CONTROL_SERVICE_ID                5u
  #define FRXCP_GETVERSIONINFO_SERVICE_ID         6u
  #define FRXCP_PDUMODE_SERVICE_ID                7u
  #define FRXCP_TXCONFIRMATION_SERVICE_ID       101u
  #define FRXCP_RXINDICATION_SERVICE_ID         102u
  #define FRXCP_TRIGGERTRANSMIT_SERVICE_ID      103u
  #define FRXCP_MAINFUNCTIONRX_SERVICE_ID       200u
  #define FRXCP_MAINFUNCTIONTX_SERVICE_ID       201u

/* Definition of errors/exceptions */
  #define FRXCP_E_NOT_INITIALIZED                 1u
  #define FRXCP_E_INV_PDU_ID                      2u
  #define FRXCP_E_NULL_POINTER                    3u
  #define FRXCP_E_RX_BUFFER_OVERFLOW              4u
  #define FRXCP_E_WRONG_CONTROL_COMMAND           5u
  #define FRXCP_E_RX_INVALID_LENGTH               6u
#endif

#if defined ( XCP_GEN_GENERATOR_MSR )
  #define FrXcp_IsPostbuild() ((3u == FRXCP_CONFIG_VARIANT) || (XCP_POSTBUILD_VARIANT_SUPPORT == STD_ON))
#else
  #define FrXcp_IsPostbuild() (3u == FRXCP_CONFIG_VARIANT)
#endif

/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/
/* must be included here otherwise the typedef is missing in the extern declaration of the post-build root struct in FrXcp_Lcfg.h */
#include "FrXcp_Lcfg.h"
#include "FrXcp_PBcfg.h"

/* En- or disable the Xcp Protocol Layer globally */
#if ( FRXCP_ENABLE_CONTROL == STD_ON )
# define FRXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* TL Enable/Disable state */
extern VAR(uint8, FRXCP_VAR_INIT) FrXcp_ControlState;

# define FRXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# define kXcponFr_Control_Disable 0x00u
# define kXcponFr_Control_Enable  0x01u
#endif

/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/
#define FRXCP_START_SEC_CODE
#include "MemMap.h"

/* Initialize the XCP on FlexRay Transport Layer */
extern FUNC(void, FRXCP_CODE) FrXcp_InitMemory( void );
extern FUNC(void, FRXCP_CODE) FrXcp_Init( P2CONST(FrXcp_ConfigType, AUTOMATIC, FRXCP_PBCFG) CfgPtr );

/* This function handles custom, Transport Layer specific commands. */
extern FUNC(uint8, FRXCP_CODE) FrXcp_TLService( uint8 Xcp_Channel, P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA) pCmd );

/* Transmit the given frame */
#define FrXcp_SendCTO FrXcp_Send
#define FrXcp_SendDTO FrXcp_Send
extern FUNC(void, FRXCP_CODE) FrXcp_Send( uint8 Xcp_Channel, uint8 len, P2CONST(uint8, AUTOMATIC, FRXCP_APPL_DATA) msg );

/* Purge the current frame cache. */
extern FUNC(void, FRXCP_CODE) FrXcp_SendFlush( uint8 Xcp_Channel, uint8 XcpFlushTypeSel );

#if defined ( XCP_ENABLE_DAQ ) && defined ( XCP_ENABLE_DAQ_RESUME )
  extern FUNC(void, FRXCP_CODE)  FrXcp_DaqResumeStore( void );
  extern FUNC(void, FRXCP_CODE)  FrXcp_DaqResumeClear( void );
  extern FUNC(void, FRXCP_CODE)  XcpAppl_DaqTlResumeClear( void );
  extern FUNC(void, FRXCP_CODE)  XcpAppl_DaqTlResumeStore( P2CONST(tXcpDaqTl, AUTOMATIC, FRXCP_APPL_DATA) rtConfigPt );
  extern FUNC(uint8, FRXCP_CODE) XcpAppl_DaqTlResume( P2VAR(tXcpDaqTl, AUTOMATIC, FRXCP_APPL_DATA) rtConfigPt );
#endif

#if ( FRXCP_VERSION_INFO_API == STD_ON )
extern FUNC(void, FRXCP_CODE) FrXcp_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, FRXCP_APPL_DATA) FrXcpVerInfoPtr
);
#endif

/* Main Tasks */
extern FUNC(void, FRXCP_CODE) FrXcp_MainFunctionRx( void );
extern FUNC(void, FRXCP_CODE) FrXcp_MainFunctionTx( void );

#if ( FRXCP_USE_PDUMODE == STD_ON )
  extern FUNC(void, FRXCP_CODE) FrXcp_SetPduMode( NetworkHandleType XcpNwH, FrXcp_PduSetModeType PduMode );
#else
  #define FrXcp_SetPduMode(XcpNwH, PduMode)
#endif

#define FRXCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**************************************************************************************************
* Prototypes of external variables
**************************************************************************************************/

/****************************************************************************/
/* 16 Bit Constants for export                                              */
/****************************************************************************/
#define FRXCP_START_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(uint16, FRXCP_CONST) FRXCP_VENDOR_ID; /* Vector = 30 */

#define FRXCP_STOP_SEC_CONST_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/****************************************************************************/
/* 8 Bit Constants for export                                               */
/****************************************************************************/
#define FRXCP_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(uint8, FRXCP_CONST) FRXCP_MODULE_ID;     /* XCP on FlexRay = 211 */
extern CONST(uint8, FRXCP_CONST) FRXCP_MAJOR_VERSION; /* Major version number */
extern CONST(uint8, FRXCP_CONST) FRXCP_MINOR_VERSION; /* Minor version number */
extern CONST(uint8, FRXCP_CONST) FRXCP_PATCH_VERSION; /* Patch level version number */

#define FRXCP_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***** end of header file ************************************************************************/
#endif
  /* __FRXCP_H__ */
