/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_PBcfg.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
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
 * V1.0.0:  27-Aug-2012  : Initial Version
 * V1.0.1:  05-Mar-2013  : As per SCR 090, SW version is updated.
 * V1.0.2:  08-Aug-2013  : As per CR 225, F1x is renamed to X1x.
 * V1.0.3:  17-Mar-2014  : As per CR 413, copyright information is updated.
 * V1.0.4:  28-Apr-2014  : As per CR 488, Mask ucmodemask is renamed to
 *                         ulmodemask in Dio_GstPortGroup Structure.
 * V1.0.5:  27-Jun-2014  : As per CR 103 and 563, copyright information is
 *                         updated and  order of structural elements in
 *                         Dio_GstPortGroup Structure is updated.
 * V1.0.6:  02-Sep-2014  : As per CR 569, following changes are made:
 *                         1. MISRA C Rule Violation is added.
 *                         2. Changes are made at all relevant places
 *                         accordingly to append U or UL after numeric values.
 * V1.0.7:  02-Feb-2015  : As part of merging activity(mantis #26024)
 *                         following changes are made:
 *                         1. pPortAddress is updated in Dio_GstPortGroup
 *                            Structure
 *                         2. Copyright information is updated.
 * V1.0.8:  22-Mar-2016  : As part of P1x V4.01.00 release, justification
 *                         provided for the MISRA warning 2:0862.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.0.19
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Component\FAAR_WE_Synergy\Dio\generate\R403_DIO_P1x_BSWMDT.arxml
 *                C:\Users\tzyksv\AppData\Local\Temp\DaVinci\Cfg-3240631\Generation\Cfg_Gen-1532993252944-0\AutosarFiles_ValGen-1532994905284-0\Dio_ECUC_4706985623408333761.arxml
 * GENERATED ON:  30 Jul 2018 - 19:58:08
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dio.h"
#include "Dio_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define DIO_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define DIO_PBCFG_C_AR_RELEASE_MINOR_VERSION  0U
#define DIO_PBCFG_C_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define DIO_PBCFG_C_SW_MAJOR_VERSION   1U
#define DIO_PBCFG_C_SW_MINOR_VERSION   0U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Void pointer is used inorder to typecast to different      */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */

/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:3211) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Message 3211                                  */
/* Justification : The Global Post Build variables are defined in this        */
/*                 translation unit and is used in the other files.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-2 and                           */
/*                 END Msg(2:3211)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       :(2:0862) #include MemMap.h directive is redundant.          */
/* Rule          : MISRA-C:2004 Message 0862                                  */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */

/******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (DIO_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
         DIO_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (DIO_PBTYPES_AR_RELEASE_MINOR_VERSION != \
         DIO_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (DIO_PBTYPES_AR_RELEASE_REVISION_VERSION != \
         DIO_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (DIO_PBTYPES_SW_MAJOR_VERSION != DIO_PBCFG_C_SW_MAJOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (DIO_PBTYPES_SW_MINOR_VERSION != DIO_PBCFG_C_SW_MINOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for DIO Driver Init configuration */
/* MISRA Violation: START Msg(2:3211)-2 */
CONST(Dio_ConfigType, DIO_CONFIG_CONST)
                              Dio_GstConfiguration[DIO_CONFIG_ARRAY_SIZE] =
{
  /* Index: 0 - DioConfig */
  {
    /* ulStartOfDbToc */
    0x0EDE0100UL,

    /* pPortGroup */
    &Dio_GstPortGroup[0],

    /* pPortChannel */
    &Dio_GstPortChannel[0]
  }
};


/* END Msg(2:3211)-2 */

/* MISRA Violation: START Msg(2:3211)-2 */
/* Structure of DIO Port Group Configuration */
CONST (Dio_PortGroup, DIO_CONST)
                                   Dio_GstPortGroup[DIO_PORT_ARRAY_SIZE] =
{
  /* Index: 0 - Port0 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(uint32 volatile, TYPEDEF, DIO_CONFIG_DATA))0xFFC10004UL,
    /* END Msg(4:0303)-1 */

    /* ulModeMask */
    0xFFFF8000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 1 - Port2 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(uint32 volatile, TYPEDEF, DIO_CONFIG_DATA))0xFFC10084UL,
    /* END Msg(4:0303)-1 */

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 2 - Port3 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(uint32 volatile, TYPEDEF, DIO_CONFIG_DATA))0xFFC100C4UL,
    /* END Msg(4:0303)-1 */

    /* ulModeMask */
    0xFFFF8000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 3 - Port4 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(uint32 volatile, TYPEDEF, DIO_CONFIG_DATA))0xFFC10104UL,
    /* END Msg(4:0303)-1 */

    /* ulModeMask */
    0xFFFF8000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 4 - Port5 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0303)-1 */
    (P2VAR(uint32 volatile, TYPEDEF, DIO_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-1 */

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x02U
  }
};


/* END Msg(2:3211)-2 */

/* Data Structure of DIO Port Channel Configuration */
/* MISRA Violation: START Msg(2:3211)-2 */
CONST(Dio_PortChannel, DIO_CONST)
                               Dio_GstPortChannel[DIO_CHANNEL_ARRAY_SIZE] =
{
  /* Index: 0 - PhaFbB */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 1 - DebPin0 */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 2 - DebPin1 */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 3 - PwrTurnOffCtrl */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 4 - PhaDiscnctC */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 5 - GateDrv0Diagc */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 6 - SysFlt2A */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 7 - MotAg2Mosi */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 8 - MotAg2Miso */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 9 - MotAg2Clk */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 10 - MotAg0Mosi */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 11 - MotAg0Clk */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 12 - FrCs */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 13 - DebPin2 */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 14 - DebPin3 */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 15 - FrErr */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 16 - MotAg0Miso */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 17 - PhaCUpprCmd */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 18 - PhaCLowrCmd */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 19 - PhaBLowrCmd */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 20 - PhaBUpprCmd */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 21 - PhaALowrCmd */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 22 - PhaAUpprCmd */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 23 - PwrOutpEnaFb */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 24 - GateDrv0Rst */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 25 - MotAg2Cs */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 26 - FrMosi */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 27 - FrClk */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 28 - PhaFbC */
  {
    /* usMask */
    0x0800U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 29 - MotAg0Cs */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 30 - FrTxData */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 31 - FrRxData */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 32 - FrTxEna */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 33 - FrStb */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 34 - MotAg3_ENCA_I */
  {
    /* usMask */
    0x0004U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 35 - MotAg4_ENCA_I */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 36 - PwrSplyMiso */
  {
    /* usMask */
    0x0001U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 37 - PwrSplyMosi */
  {
    /* usMask */
    0x0002U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 38 - PwrSplyClk */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 39 - PwrSplyNotFlt */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 40 - McuEna */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 41 - PwrSplyCs */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 42 - TmplMonrWdg */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 43 - PhaDiscnctA */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 44 - PhaDiscnctB */
  {
    /* usMask */
    0x8000U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 45 - PhaFbA */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x04U
  }
};


/* END Msg(2:3211)-2 */

/* Data Structure of DIO Port Channel Group Configuration */
/* MISRA Violation: START Msg(2:3211)-2 */
/* CONST(Dio_ChannelGroupType, DIO_CONST)
                     Dio_GstChannelGroupData[DIO_CHANNEL_GROUP_ARRAY_SIZE]; */
/* END Msg(2:3211)-2 */

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
