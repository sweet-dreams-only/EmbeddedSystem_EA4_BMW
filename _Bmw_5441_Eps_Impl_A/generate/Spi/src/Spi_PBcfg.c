/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_PBcfg.c                                                 */
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
 *  V1.1.0:  29-Jan-2013  : As per SCR 072, following chanegs are made
 *                          1. Spi_GaaDefaultValue id deleted from structure.
 *                          2. Element 'blisHighPriority' is added in
 *                             'Spi_GstSeqConfig' structure for the hardware
 *                             priority implementation and this element
 *                             will be generated only if the macro
 *                             'SPI_HW_PRIORITY_ENABLED' is STD_ON.
 *                          3. Elements 'ddNoOfBuffers' and 'ddNoOfBuffers' is
 *                             updated in 'Spi_GstChannelConfig' structure for
 *                             the byte allignment issue.
 *                          4. Element 'ulMainCtl1Value' is updated in
 *                             'Spi_GstJobConfig' structure for the hardware
 *                             priority implementation.
 *
 *  V1.1.1:  18-Mar-2013  : As per SCR 113 for the mantis issue #5420,
 *                          value of ulMainCtl1Value in Spi_GstJobConfig
 *                          is updated if SpiHwPriorityEnable is TRUE and
 *                          SpiHighPriorityHwHandlingEnable is set to TRUE
 *                          in any of SpiSequences.
 *
 *  V1.1.2:  08-Aug-2013  : As per CR 225, following changes are made:
 *                          1. Document is updated as per new template
 *                             attached in mantis #11710.
 *
 *  V1.1.3:  02-Jan-2014  : As per CR 330, for the mantis issue #15705,
 *                          Copyright information is updated.
 *
 *  V1.1.4:  28-Aug-2014  : As per CR 601, for the mantis 22252,
 *                          Changes are made at all relevant places
 *                          accordingly to append U or UL after numeric values
 *                          and to add MISRA C Rule Violation.
 *
 *  V1.1.5:  31-Dec-2014  : As per the mantis #25122, type specifier template
 *                          is added for Spi_GaaNxtNotifyBuffer.
 *
 *  V1.1.6:  18-Mar-2015  : As part of fix for Mantis#24305,
 *                          memory specifier for Spi_GaaChannelIBWrite and
 *                          Spi_GaaChannelIBRead has been modified.
 *
 *  V1.1.7:  01-Dec-2015  : As part of P1x V4.00.05 Release, following changes
 *                          are made:
 *                          1.As per ticket ARDAAAE-1435,
 *                            Renamed the memory section names from
 *                            SPI_START_DATA_LOC_RAM1 and SPI_STOP_DATA_LOC_RAM1
 *                            to SPI_START_SEC_DATA_LOC_RAM1 and
 *                            SPI_STOP_SEC_DATA_LOC_RAM1 according to the
 *                            requirement MEMMAP022.
 *                          2.Copyright information updated.
 *
 *  V1.1.8:  05-Apr-2016  : As part of P1x V4.01.00 Release, following changes
 *                          are made::
 *                          1.Justification added for  MISRA warnings 3211,3132,
 *                          3674, 0862, 0315.
 *                          2.Copyright information updated.
 *  V1.1.9:  06-Jul-2016    As part of P1x V4.01.01 issue fixing, following
 *                          changes are made
 *                          1.As part of ARDAAAE-1672, updated INIT policy of
 *                            memory sections from NOINIT to NO_INIT.
 *                          2.Justification added for MISRA warning 0303.
 *  V1.1.10: 09-Sep-2016   Following change is made:
 *                         1. Justification added for MISRA warning 2022.
 *  V1.1.11  15-Feb-2017   Following changes are made:
 *                         1.As part of ARDAAAE-2251, array
 *                           Spi_GaaDmaHwUnitList[] is limited to one single
 *                           set in case of multiple configuration as well.
 *                         2.As part of ARDAAAE-2193, generation of CKP bit
 *                           in ulConfigRegValue and CKR bit in
 *                           ulMainCtl1Value are updated.
 *                         3.Copyright information updated
 */
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

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION  0U
#define SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define SPI_PBCFG_C_SW_MAJOR_VERSION  1U
#define SPI_PBCFG_C_SW_MINOR_VERSION  6U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/


#if (SPI_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
         SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (SPI_PBTYPES_AR_RELEASE_MINOR_VERSION != \
         SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (SPI_PBTYPES_AR_RELEASE_REVISION_VERSION != \
         SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (SPI_PBTYPES_SW_MAJOR_VERSION != SPI_PBCFG_C_SW_MAJOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (SPI_PBTYPES_SW_MINOR_VERSION != SPI_PBCFG_C_SW_MINOR_VERSION)
  #error "Spi_PBcfg.c : Mismatch in Software Minor Version"
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
/* Message       : (4:3635) Function name is not followed by parentheses and  */
/*                 so, rather than being a function call, it is interpreted   */
/*                 as an expression of pointer type                           */
/* Rule          : MISRA-C:2004 Rule 16.9                                     */
/* Justification : This is a callback function. The intended behaviour is to  */
/*                 interpret expression as pointer type.                      */
/* Verification  : The function name is not preceded with an '&' operator to  */
/*                 ensure the name of the callback function is used as        */
/*                 configured by the user. However part of the code is        */
/*                 verified manually and it is not having any impact.         */
/* Reference     : Look for START Msg(4:3635)-2 and                           */
/*                 END Msg(4:3635)-2 tags in the code.                        */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object         */
/*                 and an integral type.                                      */
/* Rule          : MISRA-C:2004 Rule 3.1 and 11.3                             */
/* Justification : This macro is used to write or read values from hardware   */
/*                 addresses.                                                 */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(4:0303)-3 and                           */
/*                 END Msg(4:0303)-3 tags in the code.                        */

/*******************************************************************************
**                      QAC Warning                                           **
*******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:3132) Hard coded 'magic' number, '', used to define the */
/*                 size of an array.                                          */
/* Rule          : NA                                                         */
/* Justification : Hard coded Numbers are added instead of macros for better  */
/*                 readability.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3132)-3 and                           */
/*                 END Msg(2:3132)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier '' is defined                */
/*                here but is not used in this translation unit.              */
/* Rule         : NA                                                          */
/* Justification: Global identifiers extern declaration                       */
/*                shall be given in header file                               */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-4 and                            */
/*                END Msg(2:3211)-4 tags in the code.                         */
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
/* Message       : (2:0315) An expression of type 'pointer-to-object' is      */
/*                 being implicitly converted to type 'pointer-to-void'.      */
/* Rule          : NA                                                         */
/* Justification : The expression has no reliance on the effects of integral  */
/*                 promotion.                                                 */
/* Verification  : However, part of the code is verified manually and         */
/*                 it is not having any impact                                */
/* Reference     : Look for START Msg(2:0315)-6 and                           */
/*                 END Msg(2:0315)-6 tags in the code.                        */
/******************************************************************************/
/* 7. QAC Warning:                                                            */
/* Message       :(2:0862) #include MemMap.h directive is redundant.          */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files is done within the code.              */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/
/* 8. QAC Warning:                                                            */
/* Message       :(2:2022) A tentative definition is being used. Is it        */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : NA                                                         */
/* Justification : The Global RAM variables are defined in this translation   */
/*                 unit and after initializing it is used in the other files. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-7 and                           */
/*                 END Msg(2:2022)-7 tags in the code.                        */
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/* START Msg(2:3132)-3 */
/* Global array for internal read buffer data of channels */
VAR(Spi_DataType, SPI_INIT_DATA) Spi_GaaChannelIBRead[82] = {SPI_ZERO};

/* Global array for internal write buffer data of channels */
VAR(Spi_DataType, SPI_INIT_DATA) Spi_GaaChannelIBWrite[82] = {SPI_ZERO};
/* END Msg(2:3132)-3 */

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"



#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* START Msg(2:3132)-3 */
/* START Msg(2:2022)-7 */
/* Global RAM bit array for status of sequences */
/* VAR(uint8, SPI_NOINIT_DATA) Spi_GaaSeqStatusBitArray[]; */
/* END Msg(2:3132)-3 */
/* END Msg(2:2022)-7 */
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* START Msg(2:0315)-6 */
/* START Msg(2:3211)-4 */
/* START Msg(2:3674)-5 */
/* Structure for SPI Init configuration */
CONST(Spi_ConfigType, SPI_CONST) Spi_GstConfiguration[] =
{
  /* Index: 0 - SpiDriver */
  {
    /* ulStartOfDbToc */
    0xED4C130UL,

    /* pFirstChannel */
    &Spi_GstChannelConfig[0],

    /* pFirstJob  */
    &Spi_GstJobConfig[0],

    /* pFirstSeq */
    &Spi_GstSeqConfig[0],

    /* pJobList */
    &Spi_GstJobList[0],

    /* pStatusArray */
    NULL_PTR,

    /* pStsValueArray */
    NULL_PTR,

    /* pCSArray */
    &Spi_GaaCsIndex[0],

    /* pChannelIBRead */
    &Spi_GaaChannelIBRead[0],

    /* pChannelIBWrite */
    &Spi_GaaChannelIBWrite[0],

    /* ddDirectAccessQueueSize */
    27U,

    /*aaHWMemoryMode*/
    {
      0x00U, 0x00U, 0x00U
    },

    /*aaHWUnitInfoIndex*/
    {
      0xFFU, 0xFFU, 0x01U
    },

    /*aaHWUnitNumber*/
    {
      0xFFU, 0x02U
    },

    /* aaChipSelect */
    {
      0x00U, 0x00U, 0x00U
    },

    /* ucNoofStatusByte */
    0x00U
  }
};

/* END Msg(2:3211)-4 */

/* This array contains configuration details for Channels */
CONST(Spi_ChannelPBConfigType, SPI_CONST) Spi_GstChannelConfig[] =
{
  /* Index: 0 - GateDrv0Cfg0Ch */
  {
    /* ddBufferIndex */
    0x0000U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 1 - GateDrv0Cfg1Ch */
  {
    /* ddBufferIndex */
    0x0001U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 2 - GateDrv0Cfg2Ch */
  {
    /* ddBufferIndex */
    0x0002U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 3 - GateDrv0Cfg3Ch */
  {
    /* ddBufferIndex */
    0x0003U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 4 - GateDrv0Cfg4Ch */
  {
    /* ddBufferIndex */
    0x0004U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 5 - GateDrv0Cfg5Ch */
  {
    /* ddBufferIndex */
    0x0005U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 6 - GateDrv0Cfg6Ch */
  {
    /* ddBufferIndex */
    0x0006U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 7 - GateDrv0Cfg7Ch */
  {
    /* ddBufferIndex */
    0x0007U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 8 - GateDrv0Cfg8Ch */
  {
    /* ddBufferIndex */
    0x0008U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 9 - GateDrv0Cfg9Ch */
  {
    /* ddBufferIndex */
    0x0009U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 10 - GateDrv0Cfg10Ch */
  {
    /* ddBufferIndex */
    0x000AU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 11 - GateDrv0Cfg11Ch */
  {
    /* ddBufferIndex */
    0x000BU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 12 - GateDrv0Cfg12Ch */
  {
    /* ddBufferIndex */
    0x000CU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 13 - GateDrv0Cfg13Ch */
  {
    /* ddBufferIndex */
    0x000DU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 14 - GateDrv0VrfyCmd0Ch */
  {
    /* ddBufferIndex */
    0x000EU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 15 - GateDrv0VrfyCmd1Ch */
  {
    /* ddBufferIndex */
    0x000FU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 16 - GateDrv0VrfyCmd2Ch */
  {
    /* ddBufferIndex */
    0x0010U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 17 - GateDrv0VrfyRes0Ch */
  {
    /* ddBufferIndex */
    0x0011U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 18 - GateDrv0VrfyRes1Ch */
  {
    /* ddBufferIndex */
    0x0012U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 19 - GateDrv0Mask0Ch */
  {
    /* ddBufferIndex */
    0x0013U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 20 - GateDrv0Mask1Ch */
  {
    /* ddBufferIndex */
    0x0014U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 21 - GateDrv0Mask2Ch */
  {
    /* ddBufferIndex */
    0x0015U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 22 - GateDrv0Diag0Ch */
  {
    /* ddBufferIndex */
    0x0016U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 23 - GateDrv0Diag1Ch */
  {
    /* ddBufferIndex */
    0x0017U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 24 - GateDrv0Diag2Ch */
  {
    /* ddBufferIndex */
    0x0018U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 25 - GateDrv0CtrlCh */
  {
    /* ddBufferIndex */
    0x0019U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 26 - TmplMonrCh1 */
  {
    /* ddBufferIndex */
    0x001AU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 27 - TmplMonrCh2 */
  {
    /* ddBufferIndex */
    0x001BU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 28 - TmplMonrCh3 */
  {
    /* ddBufferIndex */
    0x001CU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 29 - TmplMonrCh4 */
  {
    /* ddBufferIndex */
    0x001DU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 30 - TmplMonrCh5 */
  {
    /* ddBufferIndex */
    0x001EU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 31 - PwrSplyCh1 */
  {
    /* ddBufferIndex */
    0x001FU,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 32 - PwrSplyCh2 */
  {
    /* ddBufferIndex */
    0x0020U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 33 - PwrSplyCh3 */
  {
    /* ddBufferIndex */
    0x0021U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 34 - PwrSplyCh4 */
  {
    /* ddBufferIndex */
    0x0022U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 35 - PwrSplyCh5 */
  {
    /* ddBufferIndex */
    0x0023U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 36 - PwrSplyCh6 */
  {
    /* ddBufferIndex */
    0x0024U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 37 - PwrSplyCh7 */
  {
    /* ddBufferIndex */
    0x0025U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 38 - PwrSplyCh8 */
  {
    /* ddBufferIndex */
    0x0026U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 39 - PwrSplyCh9 */
  {
    /* ddBufferIndex */
    0x0027U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  },

  /* Index: 40 - PwrSplyCh10 */
  {
    /* ddBufferIndex */
    0x0028U,

    /* ddNoOfBuffers */
    0x0001U,

    /* ddDefaultData */
    0x0U,

    /* ucDLSSetting */
    0x0FU,

    /* ucDataType */
    1U,

    /* ucChannelBufferType */
    0x00U,

    /* blDirection */
    SPI_FALSE
  }
};



/* This array contains configuration details for Jobs */
CONST(Spi_JobConfigType, SPI_CONST) Spi_GstJobConfig[] =
{
  /* Index: 0 - GateDrv0Cfg8Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[0],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x00U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 1 - GateDrv0Cfg9Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[1],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x01U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 2 - GateDrv0Cfg10Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[2],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x02U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 3 - GateDrv0Cfg11Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[3],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x03U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 4 - GateDrv0Cfg12Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[4],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x04U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 5 - GateDrv0Cfg13Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[5],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x05U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 6 - GateDrv0VrfyCmd0Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[6],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x06U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 7 - GateDrv0VrfyCmd1Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[7],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x07U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 8 - GateDrv0VrfyCmd2Job */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[8],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x08U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 9 - GateDrv0CtrlJob */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[9],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x09U,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 10 - TmplMonrJob1 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[10],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 11 - TmplMonrJob2 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[11],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 12 - TmplMonrJob3 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[12],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 13 - TmplMonrJob4 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[13],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 14 - TmplMonrJob5 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[14],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 15 - PwrSplyJob1 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[15],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 16 - PwrSplyJob2 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[16],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 17 - PwrSplyJob3 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[17],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 18 - PwrSplyJob4 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[18],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 19 - PwrSplyJob5 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[19],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 20 - PwrSplyJob6 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[20],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 21 - PwrSplyJob7 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[21],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 22 - PwrSplyJob8 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[22],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 23 - PwrSplyJob9 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[23],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 24 - PwrSplyJob10 */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[24],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0303)-3 */
     (P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0303)-3 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x00000020UL,

    /* ulPortPinMask */
    0x02000200UL,

    /* ulConfigRegValue */
    0x20000000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0001U,

    /* ddHWUnitIndex */
    0x00U,

    /* ddCSType */
    SPI_GPIO_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0xFFU,

    /* ucNoOfCS */
    0x00U,

    /* ucChipSelect */
    0x00U,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 25 - GateDrv0AllCfgJob */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[25],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x000BU,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x0AU,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  },

  /* Index: 26 - GateDrv0CmnDiagJob */
  {
    /* *pChannelList */
    &Spi_GaaChannelList[36],

    /* *pPortGrpRegAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
     NULL_PTR,
    /* END Msg(4:0306)-1 */

    /* *pSpiJobNotification */
    /* MISRA Violation: START Msg(4:3635)-1 */
     NULL_PTR,
    /* END Msg(4:3635)-1 */

    /* ulMainCtl1Value */
    0x0000FE70UL,

    /* ulPortPinMask */
    0x00000000UL,

    /* ulConfigRegValue */
    0x2000C000UL,

    /* usCtl2Value */
    0x400AU,

    /* usMCtl0Value */
    0x0000U,

    /* ddNoOfChannels */
    0x0006U,

    /* ddHWUnitIndex */
    0x01U,

    /* ddCSType */
    SPI_PERIPHERAL_ENGINE_CS,

    /* ucClk2CsLoopCnt */
    0x05U,

    /* ucCSArrayIndex */
    0x0BU,

    /* ucNoOfCS */
    0x01U,

    /* ucChipSelect */
    0xFEU,

    /* ucJobPriority */
    0x03U,

    /* blCsPolarity */
    SPI_FALSE,

    /* blIsChannelPropSame */
    SPI_TRUE
  }
};



/* This array contains configuration details for Sequences */
CONST(Spi_SequenceConfigType, SPI_CONST) Spi_GstSeqConfig[] =
{
  /* Index: 0 - GateDrv0Cfg8Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0000U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 1 - GateDrv0Cfg9Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0001U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 2 - GateDrv0Cfg10Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0002U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 3 - GateDrv0Cfg11Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0003U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 4 - GateDrv0Cfg12Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0004U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 5 - GateDrv0Cfg13Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0005U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 6 - GateDrv0VrfyCmd0Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0006U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 7 - GateDrv0VrfyCmd1Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0007U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 8 - GateDrv0VrfyCmd2Seq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0008U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 9 - TmplMonrSeq1 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0009U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 10 - TmplMonrSeq2 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x000AU,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 11 - TmplMonrSeq3 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x000BU,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 12 - TmplMonrSeq4 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x000CU,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 13 - TmplMonrSeq5 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x000DU,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 14 - PwrSplySeq1 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x000EU,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 15 - PwrSplySeq2 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x000FU,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 16 - PwrSplySeq3 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0010U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 17 - PwrSplySeq4 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0011U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 18 - PwrSplySeq5 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0012U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 19 - PwrSplySeq6 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0013U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 20 - PwrSplySeq7 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0014U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 21 - PwrSplySeq8 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0015U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 22 - PwrSplySeq9 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0016U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 23 - PwrSplySeq10 */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0017U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0001U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 24 - GateDrv0AllCfgSeq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0018U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 25 - GateDrv0CmnDiagSeq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x0019U,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  },

  /* Index: 26 - GateDrv0CtrlSeq */
  {
    /* *pSpiSeqEndNotification */
    /* MISRA Violation: START Msg(4:3635)-2 */
     NULL_PTR,
    /* END Msg(4:3635)-2 */

    /* ddNoOfJobs */
    0x0001U,

    /* ddJobListIndex */
    0x001AU,

    /* usStsValueStartByteIdx */
    0x0000U,

    /* usStsCheckByteIdx */
    0x0000U,

    /* usStsUpdateStartByteIdx */
    0x0000U,

    /* usHWListIndex */
    0x0002U,

    /* ucNoOfStsByteValue */
    0x00U,

    /* ucStsByteMask */
    0x00U
  }
};



/* Pointer to the structure of DMA configuration array */
/* CONST(Spi_DmaUnitConfig, SPI_CONST) Spi_GstDmaUnitConfig[]; */

/* Channel list */
CONST(Spi_ChannelType, SPI_CONST) Spi_GaaChannelList[] =
{
  /* Linked channels for job: 0 - GateDrv0Cfg8Job */
    0x0008U,

  /* Linked channels for job: 1 - GateDrv0Cfg9Job */
    0x0009U,

  /* Linked channels for job: 2 - GateDrv0Cfg10Job */
    0x000AU,

  /* Linked channels for job: 3 - GateDrv0Cfg11Job */
    0x000BU,

  /* Linked channels for job: 4 - GateDrv0Cfg12Job */
    0x000CU,

  /* Linked channels for job: 5 - GateDrv0Cfg13Job */
    0x000DU,

  /* Linked channels for job: 6 - GateDrv0VrfyCmd0Job */
    0x000EU,

  /* Linked channels for job: 7 - GateDrv0VrfyCmd1Job */
    0x000FU,

  /* Linked channels for job: 8 - GateDrv0VrfyCmd2Job */
    0x0010U,

  /* Linked channels for job: 9 - GateDrv0CtrlJob */
    0x0019U,

  /* Linked channels for job: 10 - TmplMonrJob1 */
    0x001AU,

  /* Linked channels for job: 11 - TmplMonrJob2 */
    0x001BU,

  /* Linked channels for job: 12 - TmplMonrJob3 */
    0x001CU,

  /* Linked channels for job: 13 - TmplMonrJob4 */
    0x001DU,

  /* Linked channels for job: 14 - TmplMonrJob5 */
    0x001EU,

  /* Linked channels for job: 15 - PwrSplyJob1 */
    0x001FU,

  /* Linked channels for job: 16 - PwrSplyJob2 */
    0x0020U,

  /* Linked channels for job: 17 - PwrSplyJob3 */
    0x0021U,

  /* Linked channels for job: 18 - PwrSplyJob4 */
    0x0022U,

  /* Linked channels for job: 19 - PwrSplyJob5 */
    0x0023U,

  /* Linked channels for job: 20 - PwrSplyJob6 */
    0x0024U,

  /* Linked channels for job: 21 - PwrSplyJob7 */
    0x0025U,

  /* Linked channels for job: 22 - PwrSplyJob8 */
    0x0026U,

  /* Linked channels for job: 23 - PwrSplyJob9 */
    0x0027U,

  /* Linked channels for job: 24 - PwrSplyJob10 */
    0x0028U,

  /* Linked channels for job: 25 - GateDrv0AllCfgJob */
    0x0000U,   0x0001U,   0x0002U,   0x0003U,   0x0004U,   0x0005U,   0x0006U,   0x0007U,   0x0019U,   0x0014U,   0x0015U,

  /* Linked channels for job: 26 - GateDrv0CmnDiagJob */
    0x0013U,   0x0016U,   0x0017U,   0x0018U,   0x0011U,   0x0012U
};



/* Job list */
CONST(Spi_JobListType, SPI_CONST) Spi_GstJobList[] =
{
  /* Index: 0 - GateDrv0Cfg8Job */
  {
    /* ddJobIndex */
    0x0000U,

    /* ddSequenceIndex */
    0x0000U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 1 - GateDrv0Cfg9Job */
  {
    /* ddJobIndex */
    0x0001U,

    /* ddSequenceIndex */
    0x0001U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 2 - GateDrv0Cfg10Job */
  {
    /* ddJobIndex */
    0x0002U,

    /* ddSequenceIndex */
    0x0002U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 3 - GateDrv0Cfg11Job */
  {
    /* ddJobIndex */
    0x0003U,

    /* ddSequenceIndex */
    0x0003U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 4 - GateDrv0Cfg12Job */
  {
    /* ddJobIndex */
    0x0004U,

    /* ddSequenceIndex */
    0x0004U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 5 - GateDrv0Cfg13Job */
  {
    /* ddJobIndex */
    0x0005U,

    /* ddSequenceIndex */
    0x0005U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 6 - GateDrv0VrfyCmd0Job */
  {
    /* ddJobIndex */
    0x0006U,

    /* ddSequenceIndex */
    0x0006U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 7 - GateDrv0VrfyCmd1Job */
  {
    /* ddJobIndex */
    0x0007U,

    /* ddSequenceIndex */
    0x0007U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 8 - GateDrv0VrfyCmd2Job */
  {
    /* ddJobIndex */
    0x0008U,

    /* ddSequenceIndex */
    0x0008U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 9 - TmplMonrJob1 */
  {
    /* ddJobIndex */
    0x000AU,

    /* ddSequenceIndex */
    0x0009U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 10 - TmplMonrJob2 */
  {
    /* ddJobIndex */
    0x000BU,

    /* ddSequenceIndex */
    0x000AU,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 11 - TmplMonrJob3 */
  {
    /* ddJobIndex */
    0x000CU,

    /* ddSequenceIndex */
    0x000BU,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 12 - TmplMonrJob4 */
  {
    /* ddJobIndex */
    0x000DU,

    /* ddSequenceIndex */
    0x000CU,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 13 - TmplMonrJob5 */
  {
    /* ddJobIndex */
    0x000EU,

    /* ddSequenceIndex */
    0x000DU,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 14 - PwrSplyJob1 */
  {
    /* ddJobIndex */
    0x000FU,

    /* ddSequenceIndex */
    0x000EU,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 15 - PwrSplyJob2 */
  {
    /* ddJobIndex */
    0x0010U,

    /* ddSequenceIndex */
    0x000FU,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 16 - PwrSplyJob3 */
  {
    /* ddJobIndex */
    0x0011U,

    /* ddSequenceIndex */
    0x0010U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 17 - PwrSplyJob4 */
  {
    /* ddJobIndex */
    0x0012U,

    /* ddSequenceIndex */
    0x0011U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 18 - PwrSplyJob5 */
  {
    /* ddJobIndex */
    0x0013U,

    /* ddSequenceIndex */
    0x0012U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 19 - PwrSplyJob6 */
  {
    /* ddJobIndex */
    0x0014U,

    /* ddSequenceIndex */
    0x0013U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 20 - PwrSplyJob7 */
  {
    /* ddJobIndex */
    0x0015U,

    /* ddSequenceIndex */
    0x0014U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 21 - PwrSplyJob8 */
  {
    /* ddJobIndex */
    0x0016U,

    /* ddSequenceIndex */
    0x0015U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 22 - PwrSplyJob9 */
  {
    /* ddJobIndex */
    0x0017U,

    /* ddSequenceIndex */
    0x0016U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 23 - PwrSplyJob10 */
  {
    /* ddJobIndex */
    0x0018U,

    /* ddSequenceIndex */
    0x0017U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 24 - GateDrv0AllCfgJob */
  {
    /* ddJobIndex */
    0x0019U,

    /* ddSequenceIndex */
    0x0018U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 25 - GateDrv0CmnDiagJob */
  {
    /* ddJobIndex */
    0x001AU,

    /* ddSequenceIndex */
    0x0019U,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  },

  /* Index: 26 - GateDrv0CtrlJob */
  {
    /* ddJobIndex */
    0x0009U,

    /* ddSequenceIndex */
    0x001AU,

    /* ucJobCount */
    0x00U,

    /* blIsLastJob */
    SPI_TRUE
  }
};



/* Pointer to DMA to SPI Hardware Unit mapping array */
/* CONST(uint8, SPI_CONST) Spi_GaaDmaHwUnitList[]; */

/* next Notification buffer */
/* CONST(Spi_NumberOfDataType, SPI_CONST) Spi_GaaNxtNotifyBuffer[]; */

/* Cs Index array */
CONST(uint8, SPI_CONST) Spi_GaaCsIndex[] =
{
  /* Index: 0 - GateDrv0Cfg8Job */
  0x00U,

  /* Index: 1 - GateDrv0Cfg9Job */
  0x00U,

  /* Index: 2 - GateDrv0Cfg10Job */
  0x00U,

  /* Index: 3 - GateDrv0Cfg11Job */
  0x00U,

  /* Index: 4 - GateDrv0Cfg12Job */
  0x00U,

  /* Index: 5 - GateDrv0Cfg13Job */
  0x00U,

  /* Index: 6 - GateDrv0VrfyCmd0Job */
  0x00U,

  /* Index: 7 - GateDrv0VrfyCmd1Job */
  0x00U,

  /* Index: 8 - GateDrv0VrfyCmd2Job */
  0x00U,

  /* Index: 9 - GateDrv0CtrlJob */
  0x00U,

  /* Index: 10 - GateDrv0AllCfgJob */
  0x00U,

  /* Index: 11 - GateDrv0CmnDiagJob */
  0x00U
};



/* Sequence status value array */
/* CONST(uint8, SPI_CONST) Spi_GaaSeqStatusValue[]; */

/* END Msg(2:0315)-6 */
/* END Msg(2:3674)-5 */
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
