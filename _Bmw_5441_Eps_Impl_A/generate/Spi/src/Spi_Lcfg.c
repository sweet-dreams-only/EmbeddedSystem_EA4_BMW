/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Lcfg.c                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains post-build time parameters.                             */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 *  V1.0.0:  31-Aug-2012  : Initial version
 *
 *  V1.1.0:  29-Jan-2013  : As per SCR 072, condition for generating element
 *                          'pTxCancelIntCntlAddress', 'pTxCancelImrAddress'
 *                          and 'usTxCancelImrMask' in 'Spi_GstHWUnitInfo'
 *                          structure is updated.
 *  V1.1.1:  01-Aug-2013  : As per CR 219 for the mantis issues #9002 and
 *                          #9003 following changes are made,
 *                          1. %BswLSrcTpl::Template_Hash hash is updated.
 *                          2. Spi_GstSyncSeqEndFunc is added in
 *                          %BswLSrcTpl::Template_Hash hash.
 *  V1.1.2:  08-Aug-2013  : As per CR 225, following changes are made:
 *                          1. Document is updated as per new template
 *                             attached in mantis #11710.
 *  V1.1.3:  30-Sep-2013  : As per CR 243, for the mantis issue #8421 following
 *                          changes are made:
 *                          1. %BswLSrcTpl::Template_Hash hash is updated by
 *                          removing the structure elements Spi_GstJobFunc,
 *                          Spi_GstSeqEndFunc, Spi_GstSyncSeqEndFunc and
 *                          Spi_GstSeqStartFunc.
 *                          2. %BswLSrcTpl::LSrc_Details hash is updated by
 *                          removing the elements Spi_GstJobFunc,
 *                          Spi_GstSeqEndFunc, Spi_GstSyncSeqEndFunc and
 *                          Spi_GstSeqStartFunc.
 *  V1.1.4:  02-Jan-2014  : As per CR 330, for the mantis issue #15705,
 *                          Copyright information is updated.
 *  V1.1.5:  28-Aug-2014  : As per CR 601, for the mantis 22252,
 *                          Changes are made at all relevant places
 *                          accordingly to append U or UL after numeric values
 *                          and to add MISRA C Rule Violation.
 *  V1.1.6:  05-Apr-2016  : As part of P1x V4.01.00 Release, following changes
 *                          are made::
 *                          1.Justification added for MISRA warnings 3211,3132,
 *                          3674, 0862.
 *                          2.Copyright information updated.
 *  V1.1.7:  06-Jul-2016  : As part of P1x V4.01.01 issue fixing, following
 *                          changes are made
 *                          1.As part of ARDAAAE-1672, updated INIT policy of
 *                            memory sections from NOINIT to NO_INIT.
 *                          2.Justification added for MISRA warning 0303.
 *  V1.1.8:  15-Feb-2017  : Following changes are made:
 *                          1.As part of ARDAAAE-2106,array size of
 *                            Spi_GaaSeqQueue[] is generated as a macro
 *                            SPI_TX_DUAL_SEQ_SIZE.
 *                          2.As part ARDAAAE-2277,MISRA justification
 *                            added for warning,4:0857.
 *                          3.Copyright information updated.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.2.17
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

 /*
 * INPUT FILE:    C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Spi_ECUC_9161016338772377939.arxml
 *                C:\Component\FAAR_WE_Synergy\Spi\generate\R403_SPI_P1x_BSWMDT.arxml
 * GENERATED ON:  30 Jul 2018 - 19:59:38
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi.h"
#include "Spi_PBTypes.h"
#include "Spi_LTTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define SPI_LCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define SPI_LCFG_C_AR_RELEASE_MINOR_VERSION  0U
#define SPI_LCFG_C_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define SPI_LCFG_C_SW_MAJOR_VERSION  1U
#define SPI_LCFG_C_SW_MINOR_VERSION  6U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/


#if (SPI_LTTYPES_AR_RELEASE_MAJOR_VERSION != \
         SPI_LCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Release Major Version"
#endif

#if (SPI_LTTYPES_AR_RELEASE_MINOR_VERSION != \
         SPI_LCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Release Minor Version"
#endif

#if (SPI_LTTYPES_AR_RELEASE_REVISION_VERSION != \
         SPI_LCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Release Revision Version"
#endif

#if (SPI_LTTYPES_SW_MAJOR_VERSION != SPI_LCFG_C_SW_MAJOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Software Major Version"
#endif

#if (SPI_LTTYPES_SW_MINOR_VERSION != SPI_LCFG_C_SW_MINOR_VERSION)
  #error "Spi_Lcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                  type.                                                     */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-1 and                           */
/*                 END Msg(4:0306)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object         */
/*                 and an integral type.                                      */
/* Rule          : MISRA-C:2004 Rule 3.1 and 11.3                             */
/* Justification : This macro is used to write or read values from hardware   */
/*                 addresses.                                                 */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(4:0303)-2 and                           */
/*                 END Msg(4:0303)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message      : (4:0857) Number of macro definitions exceeds 1024 - program */
/*                does not conform strictly to ISO:C90.                       */
/* Rule         : MISRA-C:2004 Rule 1.1                                       */
/* Justification: The program requires these macro definitions and cannot be  */
/*                avoided.                                                    */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(4:0857)-3 and                            */
/*                END Msg(4:0857)-3 tags in the code.                         */
/*******************************************************************************
**                      QAC Warnings                                          **
*******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       :(2:2022) A tentative definition is being used. Is it        */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : NA                                                         */
/* Justification : The Global RAM variables are defined in this translation   */
/*                 unit and after initializing it is used in the other files. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-2 and                           */
/*                 END Msg(2:2022)-2 tags in the code.                        */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier is defined here but is not   */
/*                 used in this translation unit.                             */
/* Rule         : NA                                                          */
/* Justification: As per AUTOSAR, all global variables extern declaration     */
/*                shall be given in header file.                              */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-3 and                            */
/*                END Msg(2:3211)-3 tags in the code.                         */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:3132) Hard coded 'magic' number, '', used to define the */
/*                 size of an array.                                          */
/* Rule          : NA                                                         */
/* Justification : Hard coded Numbers are added instead of macros for better  */
/*                 readability.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3132)-4 and                           */
/*                 END Msg(2:3132)-4 tags in the code.                        */
/******************************************************************************/
/* 5. QAC Warning:                                                            */
/* Message       : (2:3674) Array size defined implicitly by the number of    */
/*                 initializers.                                              */
/* Rule          : NA                                                         */
/* Justification : Array size vary in different configurations.               */
/*                 So giving fixed array size is not possible.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3674)-5 and                           */
/*                 END Msg(2:3674)-5 tags in the code.                        */
/******************************************************************************/
/* 6. QAC Warning:                                                            */
/* Message       :(2:0862) #include MemMap.h directive is redundant.          */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files is done within the code.              */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/* START Msg(2:2022)-2 */
/* START Msg(2:3211)-3 */
/* MISRA Violation: START Msg(4:0857)-3 */
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* Global RAM bit array for cancel status of sequences */
VAR(uint8, SPI_NOINIT_DATA) Spi_GaaSeqCancel[4];
/* START Msg(2:3132)-4 */
/* Global RAM bit array for cancel status of sequences */
VAR(uint8, SPI_NOINIT_DATA) Spi_GaaSeqCurrentHWUnit[27];

/* Global RAM area to count repeated jobs */
VAR(uint8, SPI_NOINIT_DATA) Spi_GaaJobCount[27];

/* Global RAM area for sequence queue for Dual buffer mode and Tx Only mode */
/*VAR(Spi_SequenceType, SPI_NOINIT_DATA) Spi_GaaSeqQueue
      *[SPI_TX_DUAL_SEQ_SIZE]; */

/* Global RAM Area for Job result */
VAR(Spi_JobResultType, SPI_CONFIG_DATA) Spi_GaaJobResult[27];

/* Global RAM Area for Sequence result */
VAR(Spi_SeqResultType, SPI_CONFIG_DATA) Spi_GaaSeqResult[27];

/* Global RAM area for job queue for both direct access mode and FIFO mode */
VAR(Spi_JobType, SPI_NOINIT_DATA) Spi_GaaJobQueue[27];


#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* END Msg(2:2022)-2 */
/* END Msg(2:3211)-3 */
/* END Msg(2:3132)-4 */
/* START Msg(2:3674)-5 */
/* START Msg(2:3132)-4 */
/* START Msg(2:3211)-3 */
#define SPI_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* Array for hardware unit information */
CONST(Spi_HWUnitInfo, SPI_CONST) Spi_GstHWUnitInfo[] =
{
  /* Index: 0 - CSIG0 */
  {
    /* *pHwMainUserBaseAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(Spi_MainUserRegs, TYPEDEF, SPI_CONFIG_DATA))0xFFD8A000UL,
    /* END Msg(4:0306)-1 */

    /* *pHwMainOsBaseAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(Spi_MainOsRegs, TYPEDEF,SPI_CONFIG_DATA))0xFFD8A010UL,
    /* END Msg(4:0306)-1 */

    /* *pHwUserBufferAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(void, TYPEDEF, SPI_CONFIG_DATA))0xFFD8B000UL,
    /* END Msg(4:0306)-1 */

    /* *pHwOsBufferAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(void, TYPEDEF, SPI_CONFIG_DATA))0xFFD8B010UL,
    /* END Msg(4:0306)-1 */

    /* *pRxIntCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB160UL,
    /* END Msg(4:0303)-2 */

    /* *pTxIntCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB15EUL,
    /* END Msg(4:0303)-2 */

    /* *pErrorIntCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB15CUL,
    /* END Msg(4:0303)-2 */

    /* pRxImrAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB414UL,
    /* END Msg(4:0303)-2 */

    /* pTxImrAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB416UL,
    /* END Msg(4:0303)-2 */

    /* pErrorImrAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB414UL,
    /* END Msg(4:0303)-2 */

    /* usRxImrMask */
    0x7FFFU,

    /* usTxImrMask */
    0xFFFEU,

    /* usErrorImrMask */
    0xBFFFU,

    /* ucHWUnit */
    SPI_HW_UNIT_CSIG0
  },

  /* Index: 1 - CSIH2 */
  {
    /* *pHwMainUserBaseAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(Spi_MainUserRegs, TYPEDEF, SPI_CONFIG_DATA))0xFFD84000UL,
    /* END Msg(4:0306)-1 */

    /* *pHwMainOsBaseAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(Spi_MainOsRegs, TYPEDEF,SPI_CONFIG_DATA))0xFFD84010UL,
    /* END Msg(4:0306)-1 */

    /* *pHwUserBufferAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(void, TYPEDEF, SPI_CONFIG_DATA))0xFFD85008UL,
    /* END Msg(4:0306)-1 */

    /* *pHwOsBufferAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     (P2VAR(void, TYPEDEF, SPI_CONFIG_DATA))0xFFD85040UL,
    /* END Msg(4:0306)-1 */

    /* *pRxIntCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB0C6UL,
    /* END Msg(4:0303)-2 */

    /* *pTxIntCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB0C8UL,
    /* END Msg(4:0303)-2 */

    /* *pErrorIntCntlAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB0C4UL,
    /* END Msg(4:0303)-2 */

    /* pRxImrAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB40CUL,
    /* END Msg(4:0303)-2 */

    /* pTxImrAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB40CUL,
    /* END Msg(4:0303)-2 */

    /* pErrorImrAddress */
    /* MISRA Violation: START Msg(4:0303)-2 */
     (P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA))0xFFFFB40CUL,
    /* END Msg(4:0303)-2 */

    /* usRxImrMask */
    0xFFF7U,

    /* usTxImrMask */
    0xFFEFU,

    /* usErrorImrMask */
    0xFFFBU,

    /* ucHWUnit */
    SPI_HW_UNIT_CSIH2
  }
};



/* Array structure for Sequence cancel */
CONST(Spi_SeqProcessType, SPI_CONST) Spi_GstSeqProcess[] =
{
  /* Index: 0 - GateDrv0Cfg8Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x01U
  },

  /* Index: 1 - GateDrv0Cfg9Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x02U
  },

  /* Index: 2 - GateDrv0Cfg10Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x04U
  },

  /* Index: 3 - GateDrv0Cfg11Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x08U
  },

  /* Index: 4 - GateDrv0Cfg12Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x10U
  },

  /* Index: 5 - GateDrv0Cfg13Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x20U
  },

  /* Index: 6 - GateDrv0VrfyCmd0Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x40U
  },

  /* Index: 7 - GateDrv0VrfyCmd1Seq */
  {
    /* ucCancelOffset */
    0x00U,

    /* ucCancelMask */
    0x80U
  },

  /* Index: 8 - GateDrv0VrfyCmd2Seq */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x01U
  },

  /* Index: 9 - TmplMonrSeq1 */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x02U
  },

  /* Index: 10 - TmplMonrSeq2 */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x04U
  },

  /* Index: 11 - TmplMonrSeq3 */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x08U
  },

  /* Index: 12 - TmplMonrSeq4 */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x10U
  },

  /* Index: 13 - TmplMonrSeq5 */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x20U
  },

  /* Index: 14 - PwrSplySeq1 */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x40U
  },

  /* Index: 15 - PwrSplySeq2 */
  {
    /* ucCancelOffset */
    0x01U,

    /* ucCancelMask */
    0x80U
  },

  /* Index: 16 - PwrSplySeq3 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x01U
  },

  /* Index: 17 - PwrSplySeq4 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x02U
  },

  /* Index: 18 - PwrSplySeq5 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x04U
  },

  /* Index: 19 - PwrSplySeq6 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x08U
  },

  /* Index: 20 - PwrSplySeq7 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x10U
  },

  /* Index: 21 - PwrSplySeq8 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x20U
  },

  /* Index: 22 - PwrSplySeq9 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x40U
  },

  /* Index: 23 - PwrSplySeq10 */
  {
    /* ucCancelOffset */
    0x02U,

    /* ucCancelMask */
    0x80U
  },

  /* Index: 24 - GateDrv0AllCfgSeq */
  {
    /* ucCancelOffset */
    0x03U,

    /* ucCancelMask */
    0x01U
  },

  /* Index: 25 - GateDrv0CmnDiagSeq */
  {
    /* ucCancelOffset */
    0x03U,

    /* ucCancelMask */
    0x02U
  },

  /* Index: 26 - GateDrv0CtrlSeq */
  {
    /* ucCancelOffset */
    0x03U,

    /* ucCancelMask */
    0x04U
  }
};


#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* END Msg(2:3211)-3 */
/* END Msg(2:3132)-4 */
/* END Msg(2:3674)-5 */
/* END Msg(4:0857)-3 */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
