/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Dio Driver                             */
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
 * V1.0.2:  17-Sep-2013  : As per CR 241 and mantis 12996, memory class for
 *                         P2CONST is updated.
 *
 * V1.0.3:  06-Feb-2014  : As per CR 394 the Copyright information is updated.
 *
 * V1.0.4:  23-May-2014  : As per CR 488 and mantis 21315, Global Data Types
 *                         section is updated for memory mapping.
 *
 * V1.0.5:  28-Jul-2014  : As per CR 564, version information section is updated
 *                         for lower version check.
 *
 * V1.0.6:  25-Aug-2014  : As per CR 569, Extra space present before ==
 *                         is removed.
 * V1.0.7:  16-Jan-2015  : Precompile options for global variables
 *                         Dio_GpPortGroup,Dio_GpPortChannel are added to
 *                         avoid MISRA warnings.
 * V1.0.8:  22-Feb-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made:
 *                         1.As per the ticket ARDAAAE-1053, variable
 *                           Dio_GusNoOfChannelGroups is renamed as
 *                           Dio_GusChannelGroupsOffset.
 *                         2.MISRA justifications 2:2022, 2:3211 and 2:0862
 *                           are added.
 * V1.0.9:  28-Jun-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made:
 *                         1. As per ARDAAAE-1908, removed dead code.
 *                         2. As per ARDAAAE-1672,Memory sections
 *                            SEC_VAR_NOINIT_UNSPECIFIED and
 *                            SEC_VAR_NOINIT_16 changed to
 *                            SEC_VAR_NO_INIT_UNSPECIFIED and SEC_VAR_NO_INIT_16
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for module version information and other types declarations */
#include "Dio.h"
/* Included for macro definitions and structure declarations */
#include "Dio_PBTypes.h"
/* Included for RAM variable declarations */
#include "Dio_Ram.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define DIO_RAM_C_AR_RELEASE_MAJOR_VERSION   DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_RAM_C_AR_RELEASE_MINOR_VERSION   DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_RAM_C_AR_RELEASE_REVISION_VERSION \
                                          DIO_AR_RELEASE_REVISION_VERSION_VALUE

/* Module Software version information  */
#define DIO_RAM_C_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION_VALUE
#define DIO_RAM_C_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (DIO_RAM_AR_RELEASE_MAJOR_VERSION != DIO_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Release Major Version"
#endif

#if (DIO_RAM_AR_RELEASE_MINOR_VERSION != DIO_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Release Minor Version"
#endif

#if (DIO_RAM_AR_RELEASE_REVISION_VERSION != \
                                         DIO_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio_Ram.c : Mismatch in Release Revision Version"
#endif

#if (DIO_RAM_SW_MAJOR_VERSION != DIO_RAM_C_SW_MAJOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Software Major Version"
#endif

#if (DIO_RAM_SW_MINOR_VERSION != DIO_RAM_C_SW_MINOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define DIO_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* QAC Warning: START Msg(2:3211)-2 */
/* Global variable to store the Dio driver initialization state */
VAR(boolean, DIO_INIT_DATA) Dio_GblDriverStatus = DIO_UNINITIALIZED;
/* END Msg(2:3211)-2 */
#endif

#define DIO_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#define DIO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* QAC Warning: START Msg(2:2022)-1 */
/* QAC Warning: START Msg(2:3211)-2 */
/* Global variable to store pointer to Configuration */
P2CONST(Dio_PortGroup, DIO_VAR, DIO_CONFIG_CONST)Dio_GpPortGroup;

#if (DIO_CHANNEL_CONFIGURED == STD_ON)
/* Global variable to store pointer to Configuration */
P2CONST(Dio_PortChannel, DIO_VAR, DIO_CONFIG_CONST)Dio_GpPortChannel;
#endif
/* END Msg(2:2022)-1 */
/* END Msg(2:3211)-2 */
#define DIO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define DIO_START_SEC_VAR_NO_INIT_16
#include "MemMap.h"

#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channel groups starting for the
 * corresponding configuration set in the array Dio_GstChannelGroupData[].
 */
/* QAC Warning: START Msg(2:2022)-1 */
/* QAC Warning: START Msg(2:3211)-2 */
VAR(uint16, DIO_CONFIG_CONST) Dio_GusChannelGroupsOffset;
/* END Msg(2:2022)-1 */
/* END Msg(2:3211)-2 */
#endif

#define DIO_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h"
/*******************************************************************************
**                      QAC Warnings                                          **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       :(2:2022) A tentative definition is being used. Is it        */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : MISRA-C:2004 Message 2022                                  */
/* Justification : The Global RAM variables are defined in this translation   */
/*                 unit and after initializing it is used in the other files. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-1 and                           */
/*                 END Msg(2:2022)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       :(2:3211) Cast between a pointer to volatile object and      */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Message 3211                                  */
/* Justification : The Global Post Build variables are defined in this        */
/*                 translation unit and is used in the other files.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-2 and                           */
/*                 END Msg(2:3211)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
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
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
