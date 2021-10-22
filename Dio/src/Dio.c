/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/*                                                                            */
/* This file contains API implementations of Dio Driver Component.            */
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
 * V1.0.0:  23-Aug-2012  : Initial Version.
 *
 * V1.0.1:  17-Sep-2012  : As per SCR 013, following changes are made.
 *                         1. Updated the pointer assignment for INPUT port
 *                           groups for API's Dio_ReadPort,  Dio_ReadChannel
 *                           and Dio_ReadChannelGroup.
 *                         2. Det Error report is updated for the API's
 *                           Dio_WriteChannel, Dio_FlipChannel,
 *                           Dio_WriteChannelGroup, Dio_ReadChannelGroup.
 *                         3. Added the Pre-compile option
 *                           'DIO_MASKED_WRITE_PORT_API' for API
 *                           Dio_MaskedWritePort.
 *                         4. Updated the Alignment
 *
 * V1.0.2:  20-Oct-2012  : As per SCR 025, following change is made.
 *                         1.INPUT Port is checked with PortTypes instead of
 *                           PortId in API Dio_MaskedWritePort and
 *                           Dio_WritePort.
 *                         2.Precompilation option is corrected for port
 *                           pointer variable in API Dio_MaskedWritePort
 *                           and Dio_WritePort.
 *
 * V1.0.3:  06-Mar-2013  : As per SCR 095, the following changes are made.
 *                         1.Software version macros are hardcoded
 *                            and software patch version is updated.
 *                         2.Copyright information is updated.
 *
 * V1.0.4:  15-Apr-2013  : As per SCR 139 and mantis #9729 and #8153, the
 *                         following changes are made.
 *                         1.Removed the Pre-compile option
 *                            for API Dio_MaskedWritePort.
 *                         2.Removed the macro DIO_C_SW_PATCH_VERSION.
 *                         3.Version check information comment is updated
 *                            for lower version.
 *
 * V1.0.5:  13-Jun-2013  : As per SCR 184, the following changes are made.
 *                         1.#endif is corrected for precompile option
 *                           DIO_CHANNEL_CONFIGURED == STD_ON for
 *                           Dio_FlipChannel API.
 *
 * V1.0.6:  31-Jul-2013  : As per CR 224 and Mantis #13447, the following
 *                         changes are made.
 *                         1.MISRA C rule violation comment is added for
 *                           Msg(7:3347)-3.
 *
 * V1.0.7:  08-Aug-2013  : As per CR 225, Device name and Project name are
 *                         updated as part of merge activity.
 *
 * V1.0.8:  17-Sep-2013  : As per CR 241 and mantis 12996, memory class for
 *                         P2CONST is updated.
 *
 * V1.0.9:  28-Oct-2013  : As per CR 286 and mantis #14560, backslash is
 *                         removed from code.
 *
 * V1.0.10: 04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.11: 05-Mar-2014  : As per CR 428, following changes are made.
 *                         1.Critical section protection is added.
 *                         2.Function header is updated.
 *                         3.Dio_FlipChannel, Dio_WriteChannel, Dio_WritePort
 *                           Dio_MaskedWritePort and Dio_WriteChannelGroup API
 *                           are updated to add channel mode check.
 *                         4.MISRA C rule violation comment is added for
 *                           (4:3792)-4.
 *
 * V1.0.12: 14-May-2014 :  As per CR 488, following changes are done.
 *                         1.Variable name ucModeMask is updated as ulModeMask.
 *                         2.Initialization is done for variable LddPortLevel
 *                           in Dio_FlipChannel API to fix polyspace warning.
 *                         3.MISRA C rule violation comment is removed for
 *                           Msg(7:3347)-3 and (4:3792)-4.
 *                         4.Dio_WritePort and Dio_MaskedWritePort API are
 *                           updated for channel mode check.
 *
 * V1.0.13: 19-Jun-2014 :  As per CR 519, comments are provided to check channel
 *                         is output channel.
 *
 * V1.0.14: 10-Jul-2014 :  As per CR 545 and mantis 21387, Alignment is
 *                         corrected and no operation required is replaced by
 *                         No Action Required.
 *
 * V1.0.15: 28-Jul-2014  : As per CR 564 and mantis #21425, Dio_MaskedWritePort
 *                         and Dio_WritePort API are updated for write operation
 *                         to PSR register.
 *
 * V1.0.16: 06-Aug-2014  : As per mantis #22811, following changes are made.
 *                         1.Dio_ReadChannelGroup and Dio_WriteChannelGroup
 *                           API's are updated for DET error with
 *                           DIO_E_PARAM_INVALID_GROUP_ID Error.
 *                         2.Code is updated for Renesas C coding Guidelines.
 *
 * V1.0.17: 20-Aug-2014  : As per mantis #22624 and CR569 following changes are
 *                         made:
 *                         1.Dio_ReadPort, Dio_ReadChannel, Dio_ReadChannelGroup
 *                           and Dio_FlipChannel API's are updated for
 *                           typecasting.
 *                         2.Dio_FlipChannel API is updated to make PNOT and
 *                           JPNOT registers as read only.
 *                         3.Extra space present before == is removed.
 *                         4.MISRA C rule violation comment is added for
 *                           (4:0491)-3, (4:0317), (4:4397) and (4:2982)-4.
 *
 * V1.0.18: 08-Oct-2014  : As per mantis #23838, following changes are made:
 *                         1. MISRA C rule violation comment is added for
 *                            (4:0492)-6.
 *                         2. MISRA C rule violation comment is deleted for
 *                            (4:2982)-4.
 *                         3. DET Pre compile check is added for
 *                            "LddPortLevel = DIO_ZERO" in Dio_ReadPort and
 *                            Dio_ReadChannelGroup.
 *
 * V1.0.19: 19-Dec-2014  : As per mantis #24331,#24772,#23962,#25154,#25111
 *                         following changes are made:
 *                         1. Dio_WriteChannelGroup(),Dio_WriteChannel() are
 *                            updated by removing local variable 'LusMask'.
 *                         2. Dio_ReadChannelGroup and Dio_WriteChannelGroup
 *                            is updated by adding NULL check.
 *                         3. Functions Dio_WritePort, Dio_WriteChannel,
 *                            Dio_WriteChannelGroup, Dio_MaskedWritePort are
 *                            Updated for JTAG address calculation.
 *                         4. Dio_WriteChannelGroup() is updated for the
 *                            requirement DIO040.
 *                         5. 'REGISTER_PROTECTION' is Changed to
 *                            'DIO_REGISTER_PROTECTION'.
 * V1.0.20: 02-Feb-2015  : As part of merging activity(mantis #26024)
 *                         following changes are made:
 *                         1. Volatile declaration is added for LpPortAddress
 *                            to consider the compiler optimization.
 *                         2. Copyright information is updated.
 * V1.0.21: 25-Feb-2015  : As per the Mantis ticket #26450,the following changes
 *                         are made:
 *                         1.Critical section protection is extended for
 *                         Dio_WritePort(),Dio_WriteChannel(),Dio_FlipChannel(),
 *                         Dio_WriteChannelGroup()and Dio_MaskedWritePort().
 *                         2. MISRA justfications added.
 *                         3. Fixed the MISRA warning.
 * V1.0.22: 18-Feb-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made:
 *                         1. As per the ticket ARDAAAE-1073, the apis
 *                            Dio_WriteChannel() and Dio_WriteChannelGroup() are
 *                            modified.
 *                         2. Copyright information is updated.
 *                         3. As per ARDAAAE-962, initialization DET Check is
 *                            implemented for Dio_MaskedWritePort() Api.
 *                         4. As per the ticket ARDAAAE-1052, the
 *                            Dio_ReadChannelGroup and Dio_WriteChannelGroup
 *                            APIs are modified to validate the channel group.
 *                         5. As per the ticket ARDAAAE-1053,
 *                            The variables usNoofChannelGroups and
 *                            Dio_GusNoOfChannelGroups are renamed as
 *                            usChannelGroupsOffset and
 *                            Dio_GusChannelGroupsOffset respectively.
 *                         6. As per ARDAAAE-1186, removed unreachable code
 *                            section from Dio_ReadChannelGroup API.
 *                         7. The justifications are provided for the MISRA
 *                            violations and messages. The MISRA justifications
 *                            for 4:0317, 4:0318, 4:2985 are removed and 4:0306,
 *                            2:2922, 4:2880, 2:3227, 2:2824, 2:2814, 4:2991,
 *                            4:2995, 2:1252, 2:0862, 4:2982, 4:2996, 4:2992,
 *                            2:3204, 2:3206 are added.
 * V1.0.23: 20-Sep-2016  : Following changes are made:
 *                         1. File Dio_Cbk.h is included.
 *                         2. As per ARDAAAE-1726,The macro DIO_REG_WRITE and
 *                            DIO_REG_WRITE_VERIFY_RUNTIME are introduced in
 *                            APIs Dio_WritePort, Dio_WriteChannel,
 *                            Dio_FlipChannel,Dio_WriteChannelGroup,
 *                            Dio_MaskedWritePort.
 *                         3. As per ARDAAAE-1484,Dio_GetVersionInfo API is
 *                            added.
 *                         4. Removed MISRA justifications for 4:4397.
 *                         5. As per ARDAAAE-1908, removed dead code.
 *                         6. As per ARDAAAE-1403,'DIO_UT_001' Tag added for the
 *                            non-covered parts of the code.
 *                         7. DET Pre compile check is removed from
 *                            "LddPortLevel = DIO_ZERO" in Dio_ReadPort.
 *                         8. Variable LunPSRContent is initialized as DIO_ZERO
 *                            in Dio_WriteChannel API.
 *                         9. As per ARDAAAE-1936,'DIO_ESDD_UD_XXX' and
 *                            Req ID Tags are added.
 *                        10. Variable "LddPortModeLevel" is renamed as
 *                            "LulPortModeLevel".
 *                        11. Inclusion of "Dio_Cbk.h" is removed as part of
 *                            acceptance.
 * V1.0.24: 07-Feb-2017  : Following changes are made:
 *                         1. As per ARDAAAE-2191,removed unnecessary
 *                            Requirement tag 'EAAR_PN0034_FR_0017' and
 *                            corrected requirement 'DIO140' in Dio_WritePort.
 *                         2. Copyright information is updated.
 *                         3. As per ARDAAAE-2273,added inclusion of
 *                            "Dio_RegWrite.h".
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0053 , DIO117 , DIO169, DIO161, DIO162 */
/* Implements EAAR_PN0034_NR_0029, EAAR_PN0034_NR_0045 */
/* Implements EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0025 */

/* Included for macro definitions and API prototypes */
#include "Dio.h"
/* Implements EAAR_PN0034_FSR_0002 */
/* Included for Register Write Verify options */
#include "Dio_RegWrite.h"
/* Included for RAM variable declarations */
#include "Dio_Ram.h"
/* Implements DIO_ESDD_UD_003 */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* Included for declaration of the function Dem_ReportErrorStatus() */
/* Implements DIO194 */
#include "Det.h"
#endif
/* Implements DIO_ESDD_UD_012 */
#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Dio.h"
#endif

/* Implements  EAAR_PN0034_NR_0056 */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Implements DIO106 */
/* AUTOSAR release version information */
#define DIO_C_AR_RELEASE_MAJOR_VERSION     DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_C_AR_RELEASE_MINOR_VERSION     DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_C_AR_RELEASE_REVISION_VERSION  DIO_AR_RELEASE_REVISION_VERSION_VALUE

/* Software version information */
#define DIO_C_SW_MAJOR_VERSION    1
#define DIO_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (DIO_AR_RELEASE_MAJOR_VERSION != DIO_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Release Major Version"
#endif

#if (DIO_AR_RELEASE_MINOR_VERSION != DIO_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio.c : Mismatch in Release Minor Version"
#endif

#if (DIO_AR_RELEASE_REVISION_VERSION != DIO_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio.c : Mismatch in Release Revision Version"
#endif

#if (DIO_SW_MAJOR_VERSION != DIO_C_SW_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Software Major Version"
#endif

#if (DIO_SW_MINOR_VERSION != DIO_C_SW_MINOR_VERSION)
  #error "Dio.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Implements EAAR_PN0034_NR_0026 */
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : For accessing 32-bit PSR register separately for lower     */
/*                 16-bit data and upper 16-bit mask.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0759)-1 and                           */
/*                 END Msg(4:0759)-1 tags in the code.                        */
/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
 /* Message       : (4:0310) Casting to different object pointer type.        */
 /* Rule          : MISRA-C:2004 Rule 11.4                                    */
 /*                 REFERENCE - ISO-6.3.4 Cast Operators                      */
 /* Justification : For accessing 8-bit and 16-bit PNOT, PPR JTAG and JPNOT,  */
 /*                 PPR JTAG register respectively, the 32-bit pointer is     */
 /*                 typecasted.                                               */
 /* Verification  : However, part of the code is verified manually and it is  */
 /*                 not having any impact.                                    */
 /* Reference     : Look for START Msg(4:0310)-2 and                          */
 /*                 END Msg(4:0310)-2 tags in the code.                       */
/******************************************************************************/
/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-3 and                           */
/*                 END Msg(4:0491)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0492) Array subscripting applied to a function parameter*/
/*                 declared as a pointer.                                     */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0492)-4 and                           */
/*                 END Msg(4:0492)-4 tags in the code.                        */
/******************************************************************************/
/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                  type.                                                     */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : The difference between two addresses are calculated after  */
/*                 typecasting the pointer to the integer.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-5 and                           */
/*                 END Msg(4:0306)-5 tags in the code.                        */
/******************************************************************************/
/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2880) This code is unreachable.                         */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : The conditions will be satisfied based on configurations   */
/*                 and there is a possibility for that part of the code to    */
/*                 execute with different configurations.                     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2880)-6 and                           */
/*                 END Msg(4:2880)-6 tags in the code.                        */
/******************************************************************************/
/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2991) The value of this 'if' controlling expression is  */
/*                 always 'true'.                                             */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always true since  */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-7 and                           */
/*                 END Msg(4:2991)-7 tags in the code.                        */
/******************************************************************************/
/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always true since  */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-8 and                           */
/*                 END Msg(4:2995)-8 tags in the code.                        */
/******************************************************************************/
/* 9.  MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2982)This assignment is redundant. The value of this    */
/*                 object is never used before being modified.                */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The variable needs to be initialized before using it.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-9 and                           */
/*                 END Msg(4:2982)-9 tags in the code.                        */
/******************************************************************************/
/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Since e-num type is used it is not possible to provide     */
/*                 out of range value but as per AUTOSAR all the input        */
/*                 parameters of an API have to be verified.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-10 and                          */
/*                 END Msg(4:2996)-10 tags in the code.                       */
/******************************************************************************/
/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2992) The value of this 'if' controlling expression is  */
/*                 always 'false'.                                            */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is false because */
/*                 of the variable updated in pre-compile condition. The      */
/*                 variable can be configured at pre-compile for true value   */
/*                 in If condition                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2992)-11 and                          */
/*                 END Msg(4:2992)-11 tags in the code.                       */
/******************************************************************************/

/*******************************************************************************
**                      QAC Warnings                                          **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type.                                           */
/* Rule          : MISRA-C:2004 Message 3892                                  */
/* Justification : To access the various sized registers using the base       */
/*                 address, typecasting is done.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-1 and                           */
/*                 END Msg(2:3892)-1 tags in the code.                        */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       : (2:2922) Left shift operation on expression of unsigned    */
/*                 type results in loss of high order bits.                   */
/* Rule          : MISRA-C:2004 Message 2922                                  */
/* Justification :  Left shift is done as part of masking to load the Lower   */
/*                  Order bits into the Higher Order bits.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2922)-2 and                           */
/*                 END Msg(2:2922)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : MISRA-C:2004 Message 3227                                  */
/* Justification : The function parameters of AUTOSAR APIs and Vendor specific*/
/*                 APIs cannot be modified to be made as constant.            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-3 and                           */
/*                 END Msg(2:3227)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : MISRA-C:2004 Message 2824                                  */
/* Justification : The Pointers are generated using Post Build configurations.*/
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-4 and                           */
/*                 END Msg(2:2824)-4 tags in the code.                        */
/******************************************************************************/
/* 5. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : MISRA-C:2004 Message 2814                                  */
/* Justification : The Pointers are generated using Post Build configurations,*/
/*                 these pointers are pointed to specific parameters.         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-5 and                           */
/*                 END Msg(2:2814)-5 tags in the code.                        */

/******************************************************************************/
/* 6. QAC Warning:                                                            */
/* Message       : (2:1252) Suffixed integer constant implicitly converted to */
/*                 different integer type.                                    */
/* Rule          : MISRA-C:2004 Message 1252                                  */
/* Justification : The result of this logical operation is always true since  */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:1252)-6 and                           */
/*                 END Msg(2:1252)-6 tags in the code.                        */
/******************************************************************************/
/* 7. QAC Warning:                                                            */
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
/* 8. QAC Warning:                                                            */
/* Message       : (2:3204) The variable is only set once and so it could be  */
/*                 declared with the 'const' qualifier.                       */
/* Rule          : MISRA-C:2004 Message 3204                                  */
/* Justification : The variable is set more than once when                    */
/*                 DIO_CHANNELGROUP_CONFIGURED switch is enabled.Hence cannot */
/*                 be declared with 'const' qualifier.                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3204)-8 and                           */
/*                 END Msg(2:3204)-8 tags in the code.                        */
/******************************************************************************/
/* 9. QAC Warning:                                                            */
/* Message       : (2:3206) The parameter is not used in this function.       */
/* Rule          : MISRA-C:2004 Message 3206                                  */
/* Justification : The parameter is used in this function when                */
/*                 DIO_CHANNELGROUP_CONFIGURED switch is enabled.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-9 and                           */
/*                 END Msg(2:3206)-9 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_Init
**
** Service ID            : 0x10
**
** Description           : This service initialize the DIO driver.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : ConfigPtr Pointer to the configuration
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Dio_GusChannelGroupsOffset, Dio_GpPortGroup,
**                         Dio_GpPortChannel, Dio_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"

 /* QAC Warning: START Msg(2:3227)-3 */
 /* Implementation Of Dio_Init API */
 /* Implements DIO_ESDD_UD_048 , DIO_ESDD_UD_022, DIO_ESDD_UD_038 */
 /* Implements DIO171,DIO165, DIO167, DIO166, DIO164, DIO187, DIO176, DIO140  */
 /* Implements EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0063,EAAR_PN0034_FR_0049 */
 /* Implements EAAR_PN0034_NR_0069, DIO179, DIO066 */
FUNC(void, DIO_PUBLIC_CODE) Dio_Init
(P2CONST(Dio_ConfigType, DIO_VAR, DIO_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-3 */
{

  /* Report Error to DET, if the config pointer value is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /* Implements DIO_ESDD_UD_003 */
    #if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_027 */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
     DIO_E_PARAM_CONFIG);

    #endif
  }
  else

  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether the existing database is correct */
    if ((uint32)DIO_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    {
      /* Initialize the Port group configuration global pointer */
      /* Implements DIO_ESDD_UD_042 */
      Dio_GpPortGroup = ConfigPtr->pPortGroup;

      #if (DIO_CHANNEL_CONFIGURED == STD_ON)
      /* Initialize the Port channel configuration global pointer */
      /* Implements DIO_ESDD_UD_041 */
      Dio_GpPortChannel = ConfigPtr->pPortChannel;
      #endif
      /* Implements DIO_ESDD_UD_008 */
      #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

      /* Initialize the config pointer value to global pointer */
      /* Implements DIO_ESDD_UD_040 */
      Dio_GusChannelGroupsOffset = ConfigPtr->usChannelGroupsOffset;
      #endif
      #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* Set the state of DIO Driver as initialized */
      /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
      Dio_GblDriverStatus = DIO_INITIALIZED;
      #endif
    }

    else
    {
      #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* Report Error to DET */
      /* Implements DIO_ESDD_UD_028 */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
       DIO_E_INVALID_DATABASE);
      #endif
    } /* End of Check to check database */
  }
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_ReadPort
**
** Service ID            : 0x02
**
** Description           : This service returns the level of all channels of
**                         given Port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : PortId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Returns the value of physical level of the channels
**                         that form the Port.
**
** Preconditions         : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GpPortGroup.
**                         Dio_GblDriverStatus
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : PPRn, JPPRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements DIO_ESDD_UD_044 */
/* QAC Warning: START Msg(2:3227)-3 */
/* Implementation Of Dio_ReadPort API */
/* Implements DIO_ESDD_UD_049 */
/* Implements DIO171, DIO053, DIO026, DIO118, DIO186, DIO013, DIO012, DIO135*/
/* Implements DIO104, DIO103, DIO060, DIO051, DIO075, DIO183, DIO024,  DIO140 */
/* Implements DIO031, DIO070, DIO005, DIO177, EAAR_PN0034_NR_0002,  DIO179 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0081, DIO066 */
/* Implements EAAR_PN0034_NR_0069 */
 FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadPort(Dio_PortType PortId)
/* END Msg(2:3227)-3 */
{
  /* Implements DIO_ESDD_UD_023 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  /* Implements DIO_ESDD_UD_045 */
  Dio_PortLevelType LddPortLevel;
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif
  /* Initialize the return value to 0 */
  /* Implements DIO_ESDD_UD_002 */
  /* MISRA Violation: START Msg(4:2982)-9 */
  LddPortLevel = DIO_ZERO;
  /* END Msg(4:2982)-9 */
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  /* Implements DIO_ESDD_UD_003 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  LenDetErrFlag = E_NOT_OK;
  /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {

    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_030*/
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_READ_PORT_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether the Port Id is out of range */
  /* Implements DIO_ESDD_UD_013 */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_031*/
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if no DET error was reported */
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the required Port */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    /* QAC Warning: START Msg(2:2814)-5 */
    /* Get the PSRn or JPSRn address for the required port */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */

    /* Check if the required port is Numeric/ AlphaNumeric/ Analog port */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
     /*
      * Read the port value from PPR register by adding offset to
      * PSR register address of Numeric/Alphabetic/ Analog Port
      */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_045 , DIO_ESDD_UD_001 */
      LddPortLevel =
              (Dio_PortLevelType)
                        (*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]));
      /* END Msg(2:3892)-1 */
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */
    }
    /* Check if the required port is JTAG port */
    /* Implements DIO_ESDD_UD_002 */
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
     /*
      * Read the port value from JPPR register by adding offset to
      * PSR register address of JTAG Port
      */
       /* MISRA Violation: START Msg(4:0310)-2 */
       /* MISRA Violation: START Msg(4:0491)-3 */
       /* QAC Warning: START Msg(2:3892)-1 */
       /* Implements DIO_ESDD_UD_045 , DIO_ESDD_UD_001 */
      LddPortLevel =
               (Dio_PortLevelType)
               (*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
       /* END Msg(2:3892)-1 */
       /* END Msg(4:0310)-2 */
       /* END Msg(4:0491)-3 */
    }
    else
    {
      /* Read the port value from IPPR register  */
      /* MISRA Violation: START Msg(4:0310)-2 */
      LddPortLevel =
                    (Dio_PortLevelType)
                    (*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                     LpPortAddress));
      /* END Msg(4:0310)-2 */
    }
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  /* Return the Port Level */
  return(LddPortLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_WritePort
**
** Service ID            : 0x03
**
** Description           : This service writes the specified level to all the
**                         channels in given Port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : PortId and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : DIO Driver must be initialized.
**
** Global Variables Used :  Dio_GpPortGroup.
**                          Dio_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, PMSRn ,JPMSRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
 /* MISRA Violation: START Msg(2:3227)-3 */
 /* Implementation of the Dio_WritePort API */
 /* Implements DIO_ESDD_UD_044, DIO_ESDD_UD_006, DIO_ESDD_UD_050 */
 /* Implements DIO171, DIO053, DIO004, DIO007, DIO119, DIO018, DIO020, DIO183 */
 /* Implements DIO005, DIO060, DIO075, DIO070, DIO051, DIO186, DIO103, DIO140 */
 /* Implements DIO108, DIO105, DIO035, DIO034, DIO026, DIO136, DIO024, DIO066 */
 /* Implements EAAR_PN0034_FR_0023, EAAR_PN0034_FSR_0001, EAAR_PN0034_FR_0013 */
 /* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004, EAAR_PN0034_FR_0052*/
 /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0081, EAAR_PN0034_NR_0002 */
 /* Implements EAAR_PN0034_NR_0069, DIO067 */
FUNC(void, DIO_PUBLIC_CODE) Dio_WritePort
(Dio_PortType PortId, Dio_PortLevelType Level)
/* END Msg(2:3227)-3 */
{
  /* Implements DIO_ESDD_UD_023 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LulPortModeLevel;
  /* Implements DIO_ESDD_UD_003 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  #endif
  /* Implements DIO_ESDD_UD_003 */
  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
     /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_030*/
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_WRITE_PORT_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether the Port Id is out of range */
  /* Implements DIO_ESDD_UD_013 */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_031*/
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                             DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    LenDetErrFlag = E_OK;
  }
   else
  {
     /* No action required */
  }
  /* Check whether the PortType is INPUT port */
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the required Port */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(4:0491)-3 */
    /* ENDMsg(2:2824)-4 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    /* END Msg(2:2814)-5 */
    {
      /* Report Error to DET */
      /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_031*/
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                             DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
     /* No action required */
  }

  if (E_NOT_OK == LenDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Port */
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */
    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */
    /* QAC Warning: START Msg(2:2814)-5 */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                        &LpPortAddress[DIO_PMSR_OFFSET_JTAG])) |
                                                      (LpPortGroup->ulModeMask);
        /* END Msg(2:3892)-1 */
        /* END Msg(2:2824)-4 */
        /* END Msg(4:0491)-3 */
    }
    /* Implements DIO_ESDD_UD_002 */
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
        /* MISRA Violation: START Msg(4:0491)-3 */
        /* QAC Warning: START Msg(2:3892)-1 */
        /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                     &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG])) |
                                                      (LpPortGroup->ulModeMask);
        /* END Msg(2:3892)-1 */
        /* END Msg(4:0491)-3 */
    }
    else
    {   /* Implements DIO_ESDD_UD_002 */
        LulPortModeLevel = (uint32)DIO_ZERO;
    }
    /* If the requested channel is an output Channel */
    /* Implements DIO_ESDD_UD_002 */
    if ((uint32)DIO_ZERO != (~LulPortModeLevel))
    {
     /*
     * Write the Port value using 32-bit PSR register
     * Enable upper 16-bits using mask to effectively write to lower 16-bits
     */
     /* QAC Warning: START Msg(2:3892)-1 */
     /* QAC Warning: START Msg(2:2922)-2 */
     /* Implements DIO_ESDD_UD_002 , DIO_ESDD_UD_016 ,DIO_ESDD_UD_017 */
     /* Implements DIO_ESDD_UD_035 */
     DIO_REG_WRITE(*(LpPortGroup->pPortAddress),
           (uint32)(Level | (~(LulPortModeLevel) << DIO_SHIFT_SIXTEEN)))

     DIO_REG_WRITE_VERIFY_RUNTIME(*(LpPortGroup->pPortAddress),
         (((uint32)Level & (~LulPortModeLevel))),((uint32)(~LulPortModeLevel)),
                                                  DIO_WRITE_PORT_SID)
     /* END Msg(2:2922)-2 */
     /* END Msg(2:3892)-1 */
    }
    else
    {
      /* No action required */
    }
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_ReadChannel
**
** Service ID            : 0x00
**
** Description           : This service returns the value of the specified
**                         DIO Channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Dio_LevelType - STD_HIGH/STD_LOW depending on the
**                         physical level of the Pin
**
** Preconditions         : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GblDriverStatus, Dio_GpPortChannel,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : PPRn, JPPRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
 /* QAC Warning: START Msg(2:3227)-3 */
 /* QAC Warning: START Msg(2:3206)-9 */
 /* Implementation of the Dio_ReadChannel API */
 /* Implements DIO_ESDD_UD_051 */
 /* Implements DIO_ESDD_UD_046, DIO_ESDD_UD_047, DIO_ESDD_UD_019 */
 /* Implements DIO171 ,DIO128, DIO060, DIO023, DIO182, DIO118, DIO013, DIO089 */
 /* Implements DIO011, DIO133, DIO185, DIO005, DIO026, DIO103, DIO015, DIO017 */
 /* Implements DIO027, DIO051, DIO083, DIO084, DIO074, DIO175, DIO140, DIO179 */
 /* Implements EAAR_PN0034_FR_0049, EAAR_PN0061_FR_0002, EAAR_PN0034_FR_0052 */
 /* Implements EAAR_PN0034_NR_0069, DIO066 */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannel(Dio_ChannelType ChannelId)
/* END Msg(2:3206)-9 */
/* END Msg(2:3227)-3 */
{
  /* Implements DIO_ESDD_UD_011 , DIO_ESDD_UD_039 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Implements DIO_ESDD_UD_023 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
   /* Implements DIO_ESDD_UD_025 */
  P2CONST(Dio_PortChannel, DIO_VAR, DIO_PRIVATE_CONST) LpPortChannel;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  Dio_PortLevelType LddPortLevel;
  #endif
  /* QAC Warning: START Msg(2:3204)-8 */
  /* Implements DIO_ESDD_UD_047 */
  Dio_LevelType LddLevel;
  /* END Msg(2:3204)-8 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* MISRA Violation: START Msg(4:2982)-9 */
  LenDetErrFlag = E_NOT_OK;
  /* END Msg(4:2982)-9 */
  #endif

  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
  /* MISRA Violation: START Msg(4:2982)-9 */
    LenDetErrFlag = E_OK;
  /* END Msg(4:2982)-9 */
  }
  else
  {
    /* No action required */
  }
  /* Implements DIO_ESDD_UD_011 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether the Channel Id is out of range */
  /* Implements DIO_ESDD_UD_007 */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  #endif
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_034 */
    (void) Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    LenDetErrFlag = E_OK;
  }
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  /* MISRA Violation: START Msg(4:2996)-10 */
  /* MISRA Violation: START Msg(4:2992)-11 */
  if (E_NOT_OK == LenDetErrFlag)
  /* END Msg(4:2992)-11 */
  /* END Msg(4:2996)-10 */
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if at least one Channel is configured */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the required Channel */
    /* Implements DIO_ESDD_UD_041 */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Get the Port Address from Port to which the Channel belongs */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(2:2814)-5 */
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    /* QAC Warning: START Msg(2:2814)-5 */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */

    /* Check if the required port is JTAG port */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
     /*
      * Read the port value from JPPR register by adding offset to
      * PSR register address of JTAG Port
      */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_045, DIO_ESDD_UD_001 */
      LddPortLevel =
      (Dio_PortLevelType)(*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
      /* END Msg(2:3892)-1 */
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0491)-3 */
      /* END Msg(4:0310)-2 */

    }
    /* Implements DIO_ESDD_UD_002 */
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
     /*
      * Read the port value from PPR register by adding offset to
      * PSR register address of Numeric/Alphabetic/Analog Port
      */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements  DIO_ESDD_UD_001 */
      LddPortLevel =
     (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                      &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]));
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0491)-3 */
      /* END Msg(4:0310)-2 */
    }
    else
    {
      /* Read the port value from IPPR register */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* Implements DIO_ESDD_UD_045 */
      LddPortLevel =
             (Dio_PortLevelType)
                      (*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                                                LpPortAddress));
      /* END Msg(4:0310)-2 */
    }
    /*
     * Mask the port level value for required Channel bit position and
     * clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpPortChannel->usMask);

    /* Check whether value is not equal to zero */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_ZERO != LddPortLevel)
    {
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
      /* No action required */
    }
    #endif
    /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  /* Return the Channel Level */
  return LddLevel;
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_WriteChannel
**
** Service ID            : 0x01
**
** Description           : This service writes the given value into the
**                         specified DIO Channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelId and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GblDriverStatus, Dio_GpPortChannel,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, PMSRn, JPMSRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
 /* QAC Warning: START Msg(2:3227)-3 */
 /* QAC Warning: START Msg(2:3206)-9 */
 /* Implementation of the Dio_WriteChannel API */
 /* Implements DIO_ESDD_UD_052 */
 /* Implements DIO_ESDD_UD_046, DIO_ESDD_UD_019, DIO_ESDD_UD_039 */
 /* Implements DIO171, DIO128, DIO060, DIO006, DIO134, DIO182, DIO051*/
 /* Implements DIO023, DIO015, DIO017, DIO119, DIO079, DIO089,DIO066  */
 /* Implements DIO070, DIO074, DIO005, DIO026, DIO028, DIO029, DIO175, DIO067 */
 /* Implements EAAR_PN0061_FR_0006, EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0001 */
 /* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004, EAAR_PN0034_FR_0013*/
 /* Implements EAAR_PN0034_NR_0069 */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannel
(Dio_ChannelType ChannelId, Dio_LevelType Level)
/* END Msg(2:3206)-9 */
/* END Msg(2:3227)-3 */
{
   /* Implements DIO_ESDD_UD_011 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Implements DIO_ESDD_UD_023 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  /* Implements DIO_ESDD_UD_025 */
  P2CONST(Dio_PortChannel, DIO_VAR, DIO_PRIVATE_CONST) LpPortChannel;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LulPortModeLevel;
  /* MISRA Violation: START Msg(4:0759)-1 */
  /* Implements DIO_ESDD_UD_024 */
  Dio_PortData LunPSRContent;

  /* END Msg(4:0759)-1 */

  #endif
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* MISRA Violation: START Msg(4:2982)-9 */
  LenDetErrFlag = E_NOT_OK;
  /* END Msg(4:2982)-9 */
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
  /* MISRA Violation: START Msg(4:2982)-9 */
    LenDetErrFlag = E_OK;
  /* END Msg(4:2982)-9 */
  }
  else
  {
    /* No action required */
  }
  /* Implements DIO_ESDD_UD_011 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether the Channel Id is out of range */
  /* Implements DIO_ESDD_UD_007 */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  #endif
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_034 */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    LenDetErrFlag = E_OK;
  }
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  if (E_NOT_OK == LenDetErrFlag)
  {
    LunPSRContent.ulLongWord = ((uint32)DIO_ZERO);
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the Port Channel */
    /* Implements DIO_ESDD_UD_041 */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to port group to which the channel belongs */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(2:2824)-4 */
    /* END Msg(2:2814)-5 */
    /* END Msg(4:0491)-3 */

    /* QAC Warning: START Msg(2:2814)-5 */
    /* Check if the required port is INPUT port */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    /* END Msg(2:2814)-5 */
    {
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }
  #endif
  /* MISRA Violation: START Msg(4:2996)-10 */
  /* MISRA Violation: START Msg(4:2992)-11 */
  if (E_NOT_OK == LenDetErrFlag)
  /* END Msg(4:2992)-11 */
  /* END Msg(4:2996)-10 */
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if at least one Channel is configured */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the Port Channel */
    /* Implements DIO_ESDD_UD_041 */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Get the pointer to port group to which the channel belongs */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(2:2814)-5 */
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */
    /* QAC Warning: START Msg(2:2814)-5 */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
   /* Implements DIO_ESDD_UD_002 */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PMSR_OFFSET_JTAG]))
                                       & LpPortChannel->usMask;
      /* END Msg(2:3892)-1 */
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0491)-3 */
    }
    /* Implements DIO_ESDD_UD_002 */
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG]))
                                       & LpPortChannel->usMask;
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0491)-3 */
    }
    else
    {   /* Implements DIO_ESDD_UD_002 */
        LulPortModeLevel = (uint32)DIO_ZERO;
    }

    /* If the specified channel is configured as an output channel */
    if ((uint32)DIO_ZERO == LulPortModeLevel)
    {
     /*
      * Enable appropriate Channel position by writing
      * upper 16bits of PSR register
      */
      LunPSRContent.Tst_WordValue.usMSWord = LpPortChannel->usMask;

      /* Check if the input level value is ZERO */
      if (STD_LOW == Level)
      {
       /*
        * Make the Channel value as ZERO by writing
        * lower 16-bits of PSR register
        */
        /* Implements DIO_ESDD_UD_002 */
        LunPSRContent.Tst_WordValue.usLSWord = DIO_ZERO;
      }
      else
      {
        /*
        * Make the Channel value as ONE by writing
        * lower 16-bits of PSR register
        */
        LunPSRContent.Tst_WordValue.usLSWord = LpPortChannel->usMask;
      }

      /* Load 32 bit value to PSR register */
      /* Implements DIO_ESDD_UD_016 ,DIO_ESDD_UD_017 ,DIO_ESDD_UD_035 */
      DIO_REG_WRITE(*(LpPortGroup->pPortAddress),LunPSRContent.ulLongWord)

      DIO_REG_WRITE_VERIFY_RUNTIME(*(LpPortGroup->pPortAddress),
        ((uint32)(LunPSRContent.ulLongWord & LpPortChannel->usMask)),
                    ((uint32)(LpPortChannel->usMask)), DIO_WRITE_CHANNEL_SID)

    }
    else
    {
      /* No action required */
    }
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif

    #endif
    /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_FlipChannel
**
** Service ID            : 0x11
**
** Description           : This service flip the level of a channel and return
**                         the level of the channel after flip.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Dio_LevelType - STD_HIGH/STD_LOW depending on the
**                         physical level of the Pin.
**
** Preconditions         : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GblDriverStatus, Dio_GpPortChannel,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PNOTn, JPNOTn, PPRn, JPPRn, PMSRn, JPMSR.
*******************************************************************************/
/* Implements DIO_ESDD_UD_010 */
#if (DIO_FLIP_CHANNEL_API == STD_ON)

#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-3 */
/* QAC Warning: START Msg(2:3206)-9 */
/* Implementation Of Dio_FlipChannel API */
/* Implements DIO_ESDD_UD_053, DIO_ESDD_UD_009, DIO_ESDD_UD_046 */
/* Implements DIO171, DIO128, DIO005, DIO119, DIO153_Conf, DIO026, DIO191 */
/* Implements DIO089, DIO193, DIO190, DIO192, DIO175,  DIO140, DIO066, DIO067 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0001, EAAR_PN0034_FR_0013 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004, EAAR_PN0034_FR_0030 */
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0081, EAAR_PN0034_NR_0002 */
/* Implements EAAR_PN0034_NR_0069 */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_FlipChannel(Dio_ChannelType ChannelId)
/* END Msg(2:3206)-9 */
/* END Msg(2:3227)-3 */
{
  /* Implements DIO_ESDD_UD_011 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Implements DIO_ESDD_UD_023 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  /* Implements DIO_ESDD_UD_025 */
  P2CONST(Dio_PortChannel, DIO_VAR, DIO_PRIVATE_CONST) LpPortChannel;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  Dio_PortLevelType LddPortLevel;
  uint32 LulPortModeLevel;
  #endif
  /* QAC Warning: START Msg(2:3204)-8 */
  /* Implements DIO_ESDD_UD_047 */
  Dio_LevelType LddLevel;
  /* END Msg(2:3204)-8 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* MISRA Violation: START Msg(4:2982)-9 */
  LenDetErrFlag = E_NOT_OK;
  /* END Msg(4:2982)-9 */
  #endif

  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;
  /* Implements DIO_ESDD_UD_011*/
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  LddPortLevel = STD_LOW;
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Implements DIO_ESDD_UD_043 ,DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    (void) Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether the Channel Id is out of range */
  /* Implements DIO_ESDD_UD_007 */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  #endif
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_034 */
    (void) Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    LenDetErrFlag = E_OK;
  }
  /* Implements DIO_ESDD_UD_011 */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }

  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the Port Channel */
    /* Implements DIO_ESDD_UD_041 */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to port group to which the channel belongs */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(2:2824)-4 */
    /* END Msg(2:2814)-5 */
    /* END Msg(4:0491)-3 */

    /* QAC Warning: START Msg(2:2814)-5 */
    /* Check if the required port is INPUT port */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    /* END Msg(2:2814)-5 */
    {
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }

  #endif
  /* MISRA Violation: START Msg(4:2996)-10 */
  /* MISRA Violation: START Msg(4:2992)-11 */
  if (E_NOT_OK == LenDetErrFlag)
  /* END Msg(4:2992)-11 */
  /* END Msg(4:2996)-10 */
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if at least one Channel is configured */
    /* Implements DIO_ESDD_UD_011 */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* Check whether DIO_DEV_ERROR_DETECT is enabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the required Channel */
    /* Implements DIO_ESDD_UD_041 */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Get the Port Address in which the Channel is configured */
    /* Implements DIO_ESDD_UD_042*/
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(2:2814)-5 */
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */

    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */
    /* QAC Warning: START Msg(2:2814)-5 */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif

    /* Check if the required port is JTAG port */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                         &LpPortAddress[DIO_PMSR_OFFSET_JTAG]))
                                   & LpPortChannel->usMask;
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0491)-3 */
      /* END Msg(2:2824)-4 */

      /* Check if the Direction of the Channel is output */
      /* Implements DIO_ESDD_UD_002 */
      if ((uint32)DIO_ZERO == LulPortModeLevel)
      {
         /*
          * Write the PNOT register by adding offset to PSR register address
          * for JTAG Port
          */
          /* MISRA Violation: START Msg(4:0310)-2 */
          /* MISRA Violation: START Msg(4:0491)-3 */
          /* QAC Warning: START Msg(2:3892)-1 */
          /* QAC Warning: START Msg(4:2982)-9 */
          /* Implements DIO_ESDD_UD_001 */
          /* Implements DIO_ESDD_UD_016 ,DIO_ESDD_UD_017 ,DIO_ESDD_UD_035 */
          LddPortLevel =
           (Dio_PortLevelType)(*(P2VAR(uint8 volatile,
             AUTOMATIC, DIO_PRIVATE_DATA))&LpPortAddress[DIO_PPR_OFFSET_JTAG]);

          DIO_REG_WRITE(*((volatile uint8 *)
           &LpPortAddress[DIO_PNOT_OFFSET_JTAG]),(uint8)(LpPortChannel->usMask))


          DIO_REG_WRITE_VERIFY_RUNTIME((*((volatile uint8 *)
                  (LpPortGroup->pPortAddress))),((uint8)(LpPortChannel->usMask)
                  & (uint8)(~LddPortLevel)),(uint8)(LpPortChannel->usMask),
                  DIO_FLIP_CHANNEL_SID)
         /* END Msg(4:2982)-9 */
         /* END Msg(2:3892)-1 */
         /* END Msg(4:0491)-3 */
         /* END Msg(4:0310)-2 */


      }
      else
      {
        /* No action required */
      }

      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for JTAG Port
       */

      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_045 ,DIO_ESDD_UD_001 */
      LddPortLevel =
      (Dio_PortLevelType)(*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */

     }
     /* Implements DIO_ESDD_UD_002 */
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
       /* MISRA Violation: START Msg(4:0491)-3 */
       /* QAC Warning: START Msg(2:3892)-1 */
       /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =  (uint32)
                        (*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
         &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG]))& LpPortChannel->usMask;
       /* END Msg(2:3892)-1 */
       /* END Msg(4:0491)-3 */

       /* To check channel is output channel*/
       if ((uint32)DIO_ZERO == LulPortModeLevel)
       {
          /*
           * Write the PNOT register by adding offset to PSR register address
           * for for Numeric/Alphabetic Port
           */
           /* QAC Warning: START Msg(4:2982)-9 */
           /* QAC Warning: START Msg(2:3892)-1 */
           /* MISRA Violation: START Msg(4:0491)-3 */
           /* MISRA Violation: START Msg(4:0310)-2 */
           /* Implements DIO_ESDD_UD_016 ,DIO_ESDD_UD_017 ,DIO_ESDD_UD_035 */
           LddPortLevel =
            (Dio_PortLevelType)(*(P2VAR(uint16 volatile, AUTOMATIC,
                    DIO_PRIVATE_DATA)) &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]);

           DIO_REG_WRITE(
                *((volatile uint16 *)&LpPortAddress[DIO_PNOT_OFFSET_NONJTAG]),
                                               (uint16)(LpPortChannel->usMask))

           DIO_REG_WRITE_VERIFY_RUNTIME((*((volatile uint16 *)
                 (LpPortGroup->pPortAddress))),((uint16)(LpPortChannel->usMask)
                & (uint16)(~LddPortLevel)),(uint16)(LpPortChannel->usMask),
                DIO_FLIP_CHANNEL_SID)
           /* END Msg(4:0310)-2 */
           /* END Msg(4:0491)-3 */
           /* END Msg(2:3892)-1 */
           /* END Msg(4:2982)-9 */
       }
       else
       {
         /* No action required */
       }
      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for Numeric/Alphabetic Port
       */

      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_045 */
      LddPortLevel =
     (Dio_PortLevelType)(*(P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]);
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */
    }
    else
    {
      /* No Action Required */
    }
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /*
     * Mask the port value for required Channel bit position and
     * clear other bit positions
     */

    LddPortLevel = LddPortLevel & (LpPortChannel->usMask);

    /* Check whether value is not equal to zero */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_ZERO != LddPortLevel)
    {
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
      /* No action required */
    }
    #endif
    /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  /* Return the Channel Level */
  return(LddLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif
/* (STD_ON == DIO_FLIP_CHANNEL_API) */
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_ReadChannelGroup
**
** Service ID            : 0x04
**
** Description           : This service returns the value of the ChannelGroup
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelGroupIdPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Returns the value of physical level of the Channels
**                         that form the ChannelGroup
**
** Preconditions         : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GusChannelGroupsOffset, Dio_GblDriverStatus,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : PPRn, JPPRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
 /* QAC Warning: START Msg(2:3227)-3 */
 /* QAC Warning: START Msg(2:3206)-9 */
 /* Implementation of the Dio_ReadChannelGroup API */
 /* Implements DIO_ESDD_UD_054 */
 /* Implements DIO171, DIO128, DIO056, DIO060, DIO021, DIO092, DIO093, DIO118 */
 /* Implements DIO137, DIO014, DIO024, DIO184, DIO022, DIO051, DIO084*/
 /* Implements DIO114, DIO005, DIO026, DIO037, DIO083, DIO186, DIO178, DIO188 */
 /* Implements EAAR_PN0034_FR_0049, EAAR_PN0061_FR_0002, EAAR_PN0034_FR_0081 */
 /* Implements EAAR_PN0034_NR_0069, DIO066, DIO067 */
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup
(P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_CONFIG_CONST) ChannelGroupIdPtr)
/* END Msg(2:3206)-9 */
/* END Msg(2:3227)-3 */
{
  /* Implements DIO_ESDD_UD_008 , DIO_ESDD_UD_014 ,DIO_ESDD_UD_015 */
  /* ImplementsDIO_ESDD_UD_036 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  /* Implements DIO_ESDD_UD_023 , DIO_ESDD_UD_037 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  /* Implements DIO_ESDD_UD_021 */
  P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_PRIVATE_CONST) LpChannelGroupPtr;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  #endif
  /* QAC Warning: START Msg(2:3204)-8 */
  /* Implements DIO_ESDD_UD_045 */
  Dio_PortLevelType LddPortLevel;
  /* END Msg(2:3204)-8 */
  /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  uint32 LulChGrpPtrValue;
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  /* MISRA Violation: START Msg(4:2982)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  LulChGrpPtrValue = DIO_ZERO;
  /* END Msg(2:3892)-1 */
  /* END Msg(4:2982)-9 */
  LpChannelGroupPtr = NULL_PTR;
  #endif
  #endif
  /* MISRA Violation: START Msg(4:2982)-9 */
  /* Set the return value to 0 */
  LddPortLevel = DIO_ZERO;
  /* END Msg(4:2982)-9 */
  /* Check if at least one ChannelGroup is configured */
   /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_READ_CHANNEL_GROUP_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  if (NULL_PTR == ChannelGroupIdPtr)
  {
      /* Report Error to DET */
       /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_029 */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                     DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
      LenDetErrFlag = E_OK;
  }
  else
  {
    /* QAC Warning: START Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:0306)-5 */
    LulChGrpPtrValue = (((uint32)(ChannelGroupIdPtr)) -
                        ((uint32)(&Dio_GstChannelGroupData[DIO_ZERO])));
    /* END Msg(4:0306)-5 */
    /* Implements DIO_ESDD_UD_002 */
    if ( DIO_ZERO != LulChGrpPtrValue)
     {
       /* MISRA Violation: START Msg(4:2991)-7 */
       /* MISRA Violation: START Msg(4:2995)-8 */
       /* QAC Warning: START Msg(2:1252)-6 */
       /* MISRA Violation: START Msg(4:2880)-6 */
       /* Start DIO_UT_001 */
       /*Implements DIO_ESDD_UD_002 */
       if ((DIO_ZERO != (LulChGrpPtrValue &
                        ((uint32)(DIO_SIZE_OF_CHGRP_STRUCT - DIO_ONE)))) ||
                           (DIO_NO_OF_CHGRP_PER_CFGSET <=
                             (LulChGrpPtrValue / DIO_SIZE_OF_CHGRP_STRUCT)))
       /* End DIO_UT_001 */
       /* END Msg(4:2880)-6 */
       /* END Msg(2:1252)-6 */
       /* END Msg(4:2995)-8 */
       /* END Msg(4:2991)-7 */
       {
        /* Report Error to DET */
        /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_032 */
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
         LenDetErrFlag = E_OK;
      }
      else
      {
        /* Get the pointer to corresponding index in the
          array Dio_GstChannelGroupData */

        /* MISRA Violation: START Msg(4:0492)-4 */
        /* Implements DIO_ESDD_UD_040 */
        LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusChannelGroupsOffset];
        /* END Msg(4:0492)-4 */
      }
     }
     /* END Msg(2:3892)-1 */
    else
    {
        /* No action required */
    }
    if (E_NOT_OK == LenDetErrFlag)
    {
      /* Get the pointer to corresponding index in the array
      Dio_GstChannelGroupData */

      /* MISRA Violation: START Msg(4:0492)-4 */
      /* Implements DIO_ESDD_UD_040 */
      LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusChannelGroupsOffset];
      /* END Msg(4:0492)-4 */
    }
    else
    {
        /* No action required */
    }
  }
  #elif(DIO_DEV_ERROR_DETECT == STD_OFF)

  /* Get the pointer to corresponding index in the
  array Dio_GstChannelGroupData */

  /* MISRA Violation: START Msg(4:0492)-4 */
  /* QAC Warning: START Msg(2:2824)-4 */
  /* Implements DIO_ESDD_UD_040 */
  LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusChannelGroupsOffset];
  /* END Msg(2:2824)-4 */
  /* END Msg(4:0492)-4 */
  #endif
  #if(DIO_DEV_ERROR_DETECT == STD_ON)

  if (E_NOT_OK == LenDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Get the Port Address in which the Channel is configured */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[LpChannelGroupPtr->ucPortIndex];
    /* END Msg(2:2814)-5 */
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */
    /* QAC Warning: START Msg(2:2814)-5 */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */

    /* Check if the required port is JTAG port */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* Read the port value from PPR register by adding offset to */
      /* PSR register address for JTAG Port
      */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_045 */
      LddPortLevel =
      (Dio_PortLevelType)(*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
      /* END Msg(2:3892)-1 */
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */

    }
    /* Implements DIO_ESDD_UD_002 */
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* Read the port value from PPR register by adding offset to */
      /* PSR register address for Numeric/Alphabetic Port          */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_045 , DIO_ESDD_UD_001 */
      LddPortLevel =
     (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]));
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */
    }
    else
    {
      /* Read the port value from IPPR register  */
      /* MISRA Violation: START Msg(4:0310)-2 */
      LddPortLevel =
              (Dio_PortLevelType)
              (*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                                                LpPortAddress));
      /* END Msg(4:0310)-2 */
    }
    /*
     * Mask the port value for required ChannelGroup related bit positions
     * and clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpChannelGroupPtr->usMask);
    /* Rotate right to get the corresponding ChannelGroup value */
    LddPortLevel = LddPortLevel >> (LpChannelGroupPtr->ucOffset);
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  /* Report Error to DET */
  /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_032 */
  (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                       DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
  #endif
  /* #if (DIO_DEV_ERROR_DETECT == STD_ON) */

  #endif
  /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */

  /* Return the ChannelGroup Level */
  return(LddPortLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_WriteChannelGroup
**
** Service ID            : 0x05
**
** Description           : This service writes specified level to the
**                         ChannelGroup
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelGroupIdPtr and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GusChannelGroupsOffset, Dio_GblDriverStatus,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, PMSRn, JPMSRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
 /* QAC Warning: START Msg(2:3227)-3 */
 /* QAC Warning: START Msg(2:3206)-9 */
 /* Implementation of the Dio_WriteChannelGroup API */
 /* Implements DIO_ESDD_UD_055 */
 /* Implements DIO171, DIO128, DIO056, DIO060, DIO008, DIO090, DIO066, DIO067 */
 /* Implements DIO138, DIO005, DIO114, DIO026, DIO039, DIO040, DIO186 */
 /* Implements DIO091, DIO070, DIO119, DIO051, DIO184, DIO024,  DIO140 */
 /* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0001, EAAR_PN0034_FR_0013 */
 /* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004 */
 /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0030 */
 /* Implements EAAR_PN0034_NR_0069 */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup
(P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_CONFIG_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level)
 /* END Msg(2:3206)-9 */
 /* END Msg(2:3227)-3 */
{
  /* Implements DIO_ESDD_UD_008 , DIO_ESDD_UD_014 ,DIO_ESDD_UD_015 */
  /* Implements DIO_ESDD_UD_036 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  /* Implements DIO_ESDD_UD_023 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  /* Implements DIO_ESDD_UD_021 */
  P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_PRIVATE_CONST) LpChannelGroupPtr;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LulPortModeLevel;
  /* Implements DIO_ESDD_UD_003 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  uint32 LulChGrpPtrValue;
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  LpChannelGroupPtr = NULL_PTR;
  /* MISRA Violation: START Msg(4:2982)-9 */
  /* QAC Warning: START Msg(2:3892)-1 */
  LulChGrpPtrValue = DIO_ZERO;
  /* END Msg(2:3892)-1 */
  /* END Msg(4:2982)-9 */
  #endif
  #endif

  /* Check if at least one ChannelGroup is configured */
  /* Implements DIO_ESDD_UD_008 */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  /* Implements DIO_ESDD_UD_003 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  if (NULL_PTR == ChannelGroupIdPtr)
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_029 */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* QAC Warning: START Msg(2:3892)-1 */
    /* MISRA Violation: START Msg(4:0306)-5 */
    LulChGrpPtrValue = (((uint32)(ChannelGroupIdPtr)) -
                        ((uint32)(&Dio_GstChannelGroupData[DIO_ZERO])));
    /* END Msg(4:0306)-5 */
    /* Implements DIO_ESDD_UD_002 */
    if ( DIO_ZERO != LulChGrpPtrValue)
     {
       /* MISRA Violation: START Msg(4:2991)-7 */
       /* MISRA Violation: START Msg(4:2995)-8 */
       /* QAC Warning: START Msg(2:1252)-6 */
       /* MISRA Violation: START Msg(4:2880)-6 */
       /* Start DIO_UT_001 */
       /* Implements DIO_ESDD_UD_002 */
       if ((DIO_ZERO != (LulChGrpPtrValue &
                        ((uint32)(DIO_SIZE_OF_CHGRP_STRUCT - DIO_ONE)))) ||
                           (DIO_NO_OF_CHGRP_PER_CFGSET <=
                             (LulChGrpPtrValue / DIO_SIZE_OF_CHGRP_STRUCT)))
       /* End DIO_UT_001 */
       /* END Msg(4:2880)-6 */
       /* END Msg(2:1252)-6 */
       /* END Msg(4:2995)-8 */
       /* END Msg(4:2991)-7 */
      {
        /* Report Error to DET */
        /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_032 , DIO_ESDD_UD_033 */
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
         LenDetErrFlag = E_OK;
      }
      else
      {
        /* MISRA Violation: START Msg(4:0492)-4 */
        /* Implements DIO_ESDD_UD_040 */
        LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusChannelGroupsOffset];
        /* END Msg(4:0492)-4 */
      }
     }
     /* END Msg(2:3892)-1 */
    else
    {
        /* No action required */
    }
    if (E_NOT_OK == LenDetErrFlag)
    {
       /* MISRA Violation: START Msg(4:0492)-4 */
       /* Implements DIO_ESDD_UD_040 */
       LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusChannelGroupsOffset];
       /* END Msg(4:0492)-4 */
    }
    else
    {
        /* No action required */
    }
  }

  #elif(DIO_DEV_ERROR_DETECT == STD_OFF)

  /* Get the pointer to corresponding index in the
  array Dio_GstChannelGroupData */

  /* MISRA Violation: START Msg(4:0492)-4 */
  /* QAC Warning: START Msg(2:2824)-4 */
  /* Implements DIO_ESDD_UD_040 */
  LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusChannelGroupsOffset];
  /* END Msg(2:2824)-4 */
  /* END Msg(4:0492)-4 */

  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
   /* Implements DIO_ESDD_UD_003 */
  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  if (E_NOT_OK == LenDetErrFlag)

  {
    /* QAC Warning: START Msg(2:2814)-5 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the Port Address in which the Channel group is configured */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[LpChannelGroupPtr->ucPortIndex];
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */

    /* Check if the required port is not INPUT port */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    /* END Msg(2:2814)-5 */
    {
      /* Report Error to DET */
      /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_031*/
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }

  if (E_NOT_OK == LenDetErrFlag)
  #endif
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    /* Implements DIO_ESDD_UD_003 */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Get the pointer to port group to which the channel belongs */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[LpChannelGroupPtr->ucPortIndex];
    /* END Msg(2:2814)-5 */
    /* END Msg(4:0491)-3 */
    /* END Msg(2:2824)-4 */

    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    /* Get the Port Address in which the Channel group is configured */
    /* QAC Warning: START Msg(2:2814)-5 */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* QAC Warning: START Msg(2:2824)-4 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(~(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
            &LpPortAddress[DIO_PMSR_OFFSET_JTAG])))& (~(LpPortGroup->ulModeMask)
                                                   & LpChannelGroupPtr->usMask);
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0491)-3 */
      /* END Msg(2:2824)-4 */
    }
    /* Implements DIO_ESDD_UD_002 */
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(~(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
         &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG])))& (~(LpPortGroup->ulModeMask)
                                                   & LpChannelGroupPtr->usMask);
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0491)-3 */
    }
    else
    {
        LulPortModeLevel = (uint32)DIO_ZERO;
    }

    /* To check channel is output channel*/
    if ((uint32)DIO_ZERO != LulPortModeLevel)
    {
      /* Rotate left the input level to get the value to be written to port */
      Level = Level << (LpChannelGroupPtr->ucOffset);

      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_002 */
      /* Implements DIO_ESDD_UD_016 ,DIO_ESDD_UD_017 ,DIO_ESDD_UD_035 */
      DIO_REG_WRITE( *(LpPortGroup->pPortAddress),(Level |
     ((uint32)((LulPortModeLevel& LpChannelGroupPtr->usMask) <<
                                                          DIO_SHIFT_SIXTEEN))))

     DIO_REG_WRITE_VERIFY_RUNTIME( *(LpPortGroup->pPortAddress),
     ((uint32)Level & ((uint32)(LulPortModeLevel
                & ((uint32)(LpChannelGroupPtr->usMask))))),
                ((((uint32)LpChannelGroupPtr->usMask) & LulPortModeLevel)),
                DIO_WRITE_CHANNEL_GROUP_SID)

      /* END Msg(2:3892)-1 */
    }
    else
    {
      /* No action required */
    }
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  /* Implements DIO_ESDD_UD_003 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #else
  /* Implements DIO_ESDD_UD_003 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_032 , DIO_ESDD_UD_033 */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
  #endif
  /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */
  #endif
}
#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_MaskedWritePort
**
** Service ID            : 0x13
**
** Description           : This service writes the specified level to all the
**                         channels that are Masked in given Port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : PortId, Mask and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used :  Dio_GpPortGroup.
**                          R4.0 : Dio_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, PMSRn, JPMSRn.
*******************************************************************************/
 /* Implements DIO_ESDD_UD_005 */
#if (DIO_MASKED_WRITE_PORT_API == STD_ON)
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
 /* QAC Warning: START Msg(2:3227)-3 */
 /* Implementation of the Dio_MaskedWritePort interface */
 /* Implements DIO_ESDD_UD_056 */
 /* Implements DIO171, DIO053, DIO060, DIO064, DIO070, DIO119, DIO026, DIO067 */
 /* Implements DIO103, DIO183, DIO020, DIO005, DIO051, DIO109,  DIO179 */
 /* Implements EAAR_PN0061_FR_0015, EAAR_PN0061_FR_0001, EAAR_PN0061_FR_0022 */
 /* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FSR_0001, EAAR_PN0034_FR_0013*/
 /* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FSR_0004, EAAR_PN0034_FR_0030*/
 /* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0081, EAAR_PN0034_NR_0001 */
 /* Implements EAAR_PN0034_NR_0069, DIO066  */
FUNC(void, DIO_PUBLIC_CODE) Dio_MaskedWritePort
(Dio_PortType PortId,
 Dio_PortLevelType Level,
 Dio_PortLevelType  Mask)
 /* END Msg(2:3227)-3 */
{
   /* Implements DIO_ESDD_UD_023 , DIO_ESDD_UD_018 */
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LulPortModeLevel;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  /* Implements DIO_ESDD_UD_003 */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Implements DIO_ESDD_UD_043 , DIO_ESDD_UD_002 */
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_MASKED_WRITE_PORT_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check whether the Port Id is out of range */
  /* Implements DIO_ESDD_UD_013 */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* Report Error to DET */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_030*/
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_MASKED_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Get the pointer to the required Port */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    /* END Msg(2:2814)-5 */
    {
      /* Report Error to DET */
      /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_030*/
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_MASKED_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }

  if (E_NOT_OK == LenDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Port */
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* QAC Warning: START Msg(2:2824)-4 */
    /* Implements DIO_ESDD_UD_042 */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(2:2824)-4 */
    /* END Msg(4:0491)-3 */
    #endif
    /* QAC Warning: START Msg(2:2814)-5 */
    LpPortAddress = LpPortGroup->pPortAddress;
    /* END Msg(2:2814)-5 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /* Implements DIO_ESDD_UD_002 */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:2824)-4 */
      /* QAC Warning: START Msg(2:3892)-1 */
      /* Implements DIO_ESDD_UD_001 */
      LulPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PMSR_OFFSET_JTAG]))
                                                    | (LpPortGroup->ulModeMask);
      /* END Msg(2:3892)-1 */
      /* END Msg(2:2824)-4 */
      /* END Msg(4:0491)-3 */
    }
    /* Implements DIO_ESDD_UD_002 */
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* QAC Warning: START Msg(2:3892)-1 */
      LulPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG]))
                                                | (LpPortGroup->ulModeMask);
      /* END Msg(2:3892)-1 */
      /* END Msg(4:0491)-3 */
    }
    else
    {
        LulPortModeLevel = (uint32)DIO_ZERO;
    }

    /* Check if the channels which are configured as output */
    if ((uint32)DIO_ZERO != (~LulPortModeLevel))

    {
      /* QAC Warning: START Msg(2:3892)-1 */
      /*Load 32 bit value to PSR register*/
      /* Implements DIO_ESDD_UD_002 */
      /* Implements DIO_ESDD_UD_016 ,DIO_ESDD_UD_017 ,DIO_ESDD_UD_035 */
      DIO_REG_WRITE( *(LpPortGroup->pPortAddress), (Level |
                ((uint32)((~(LulPortModeLevel)) & Mask) << DIO_SHIFT_SIXTEEN)))

      DIO_REG_WRITE_VERIFY_RUNTIME( *(LpPortGroup->pPortAddress),
                        ((uint32)(Level & (((~LulPortModeLevel) & Mask)))),
             ((uint32)((~LulPortModeLevel) & Mask)), DIO_MASKED_WRITE_PORT_SID)

      /* END Msg(2:3892)-1 */
    }
    else
    {
      /* No action required */
    }
    /* Implements DIO_ESDD_UD_012 */
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif
/* (STD_ON == DIO_MASKED_WRITE_PORT_API) */
/* Implements EAAR_PN0034_NR_0020 */
/*******************************************************************************
** Function Name         : Dio_GetVersionInfo
**
** Service ID            : 0x12
**
** Description           : This API returns the version information of DIO
**                         driver component.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : VersionInfo
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables      : None
**
** Functions invoked     : Det_ReportError
**
** Registers Used        : None
**
*******************************************************************************/
/* Implements DIO_ESDD_UD_004 */
#if (DIO_VERSION_INFO_API == STD_ON)
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
 /* QAC Warning: START Msg(2:3227)-3 */
 /* Implementation of the Dio_WriteChannelGroup API */
 /* Implements DIO_ESDD_UD_026 */
 /* Implements DIO171, DIO106, DIO139, DIO143_Conf, EAAR_PN0034_NR_0001 */
 /* Implements DIO123, DIO126, DIO124, DIO189, DIO179 */
 /* Implements EAAR_PN0034_NR_0069, DIO066  */
FUNC(void, DIO_PUBLIC_CODE) Dio_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA)versioninfo)
/* END Msg(2:3227)-3 */
{
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    /* Implements DIO_ESDD_UD_020 , DIO_ESDD_UD_029 */
    (void) Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                           DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
  }
  else
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* QAC Warning: START Msg(2:2814)-5 */
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)DIO_VENDOR_ID;
    /* END Msg(2:2814)-5 */
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)DIO_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = DIO_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = DIO_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = DIO_SW_PATCH_VERSION;
  }
}
#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* (DIO_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
