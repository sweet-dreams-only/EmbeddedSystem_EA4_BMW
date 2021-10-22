/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post Build time Parameters      */
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
 * V1.0.0:  23-Aug-2012  : Initial Version
 *
 * V1.0.1:  08-Aug-2013  : As per CR 225, Copyright information, Device name and
 *                         Project name are updated as part of merge activity.
 *
 * V1.0.2:  17-Sep-2013  : As per CR 241, DIO_PPR_OFFSET and DIO_PNOT_OFFSET
 *                         macros are removed from Global symbol section.
 *
 * V1.0.3:  04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.4:  06-Mar-2014  : As per CR 428, SchM critical section protection
 *                         macros are added.
 *
 * V1.0.5:  08-Apr-2014  : As per CR 475, definition is updated for macro
 *                         DIO_ZERO.
 *
 * V1.0.6:  24-Apr-2014  : As per CR 488, variable name ucModeMask is updated as
 *                         ulModeMask.
 *
 * V1.0.7:  28-Jul-2014  : As per CR 564 and mantis #21425, DIO_SHIFT_SIXTEEN
 *                          macro is added.
 *
 * V1.0.8:  06-Aug-2014  : Following changes are made:
 *                         1.As per mantis #22811, Order of declaration Of
 *                         structure elements ulModeMask and ucPortType are
 *                         interchanged to avoid structure padding.
 *
 * V1.0.9:  20-Aug-2014  : As per CR 569, following changes are done:
 *                         1.DIO_MSB_MASK macro is deleted.
 *                         2.Precompile option is added for Extern declarations
 *                           for Global Data.
 *                         3.MISRA C rule violation comment is added for
 *                           (4:3684)-1 and (4:0750)-2.
 *
 * V1.0.10: 22-Sep-2014  : As per CR 629, Precompile option is deleted for
 *                         Extern declarations for Global Data.
 *
 * V1.0.11: 30-Aug-2014  : As per mantis #23838, Precompile option is deleted
 *                         for SchM Critical Section Protection Macros.
 * V1.0.12: 02-Feb-2015  : As part of merging activity(mantis #26024)
 *                         following changes are made:
 *                         1. Volatile declaration is added for LpPortAddress
 *                            to consider the compiler optimization.
 *                         2. Copyright information is updated.
 * V1.0.13: 18-Feb-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made:
 *                         1. As per the ticket ARDAAAE-1052, the Macro
 *                            DIO_ONE is added.
 *                         2. As per the ticket ARDAAAE-1486,  the storage
 *                            specifier is changed for the variables to TYPEDEF.
 *                         3. The Macros 'DIO_PORT_ARRAY_SIZE',
 *                            'DIO_CHANNEL_ARRAY_SIZE' and the compiler switch
 *                            is added to remove the MISRA violations.
 * V1.0.14: 18-Apr-2016  : Following changes are made:
 *                         1. Typecasting added for macro "DIO_DBTOC_VALUE".
 * V1.0.15: 07-Feb-2017  : Following changes are made:
 *                         1. As per ARDAAAE-2191, requirement tag
 *                            'implements' changed to 'DIO_H_00x :'.
 *                         2. As per ARDAAAE-2273,Numeric values are appended
 *                            with 'U' for macro definitions.
 *                         3. Copyright information is updated.
 */
/******************************************************************************/
/* DIO_H_003: EAAR_PN0034_FR_0001 */
#ifndef DIO_PBTYPES_H
#define DIO_PBTYPES_H

/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define DIO_PBTYPES_AR_RELEASE_MAJOR_VERSION  DIO_AR_RELEASE_MAJOR_VERSION
#define DIO_PBTYPES_AR_RELEASE_MINOR_VERSION  DIO_AR_RELEASE_MINOR_VERSION
#define DIO_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                              DIO_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define DIO_PBTYPES_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION
#define DIO_PBTYPES_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.2                                      */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0750) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : For accessing 32-bit PSR register separately for lower     */
/*                 16-bit data and upper 16-bit mask.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0750)-2 and                           */
/*                 END Msg(4:0750)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* General defines */
#define DIO_DBTOC_VALUE  ((((uint32)DIO_VENDOR_ID) << 22) |  \
                          (((uint32)DIO_MODULE_ID) << 14) | \
                          (((uint32)DIO_SW_MAJOR_VERSION) << 8) | \
                          (((uint32)DIO_SW_MINOR_VERSION) << 3))

#define DIO_NORMALPORT                      (Dio_PortType)2U
#define DIO_JTAGPORT                        (Dio_PortType)1U
#define DIO_INPUTPORT                       (Dio_PortType)0U
#define DIO_ZERO                            (uint16)0x0000U
#define DIO_ONE                            (uint16)0x0001U
#define DIO_SHIFT_SIXTEEN                   (uint8)0x10U

/* Driver status Macros */
#define DIO_INITIALIZED               (boolean)0U
#define DIO_UNINITIALIZED             (boolean)1U


/*******************************************************************************
**               SchM Critical Section Protection Macros                      **
*******************************************************************************/
#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)

#define DIO_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                   SchM_Enter_Dio_##Exclusive_Area()
#define DIO_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                   SchM_Exit_Dio_##Exclusive_Area()
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Structure for Dio Port Group */
typedef struct STag_Dio_PortGroup
{
  /* Address of the port */
  P2VAR(uint32 volatile, TYPEDEF, DIO_CONFIG_DATA) pPortAddress;
  uint32 ulModeMask;
  /* Type Of the port group,
     0 = Input port,
     1 = Jtag port,
     2 = Numeric/Alphabetic/ Analog port */
  uint8 ucPortType;
} Dio_PortGroup;

/* Structure for Dio Channel */
typedef struct STag_Dio_PortChannel
{
  uint16 usMask;
  /* PortGroup Index in the array Dio_GstPortChannel[] with respect to the
     pointer Dio_GpPortChannel of the corresponding configuration */
  uint8 ucPortIndex;
} Dio_PortChannel;

/* Union for accessing 32 bit PSR register */
/* MISRA Violation: START Msg(4:0750)-2 */
typedef union UTag_Dio_PortData
{
  uint32 ulLongWord;
  struct
  {
    uint16 usLSWord;
    uint16 usMSWord;
  }Tst_WordValue;
} Dio_PortData;
/* END Msg(4:0750)-2 */

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Dio_PortGroup, DIO_CONST) Dio_GstPortGroup[DIO_PORT_ARRAY_SIZE];
/* END Msg(4:3684)-1 */

#if (STD_ON == DIO_CHANNEL_CONFIGURED)
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Dio_PortChannel, DIO_CONST)
                                    Dio_GstPortChannel[DIO_CHANNEL_ARRAY_SIZE];
/* END Msg(4:3684)-1 */
#endif
#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif
/* DIO_PBTTYPES_H */

/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/
