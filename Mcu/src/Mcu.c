/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of MCU Driver              */
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
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  02-Sep-2013 : Initial Version.
 *
 * V1.0.1:  16-Apr-2014 : As per CR83 and mantis #18031 and #19850,
 *                        Following changes are made,
 *                        1. Mcu_ProtectedWrite and Mcu_ReadBackDiagTest
 *                           functions are implemented as macros
 *                        2. As part of safety measure in conditional checks,
 *                           macros are placed on the left side
 *                        3. LucProtTypeAndWriteSize is removed since
 *                           Mcu_ProtectedWrite is implemented as a macro
 *                        4. Mcu_LockStepSelfDiagnosticTest is implemented as
 *                           per new requirement EAAR_PN0079_FR_0092
 *                        5. Initialization of ECM is updated in Mcu_init() and
 *                           Mcu_InitRamSection() as given in the device manual
 *                        6. All APIs are updated for the initialization of
 *                           local variables to avoid garbage values
 *                        7. MCU_ENTER_CRITICAL_SECTION and
 *                           MCU_EXIT_CRITICAL_SECTION areas are invoked
 *                        8. Mcu_ClmaSelfDiagnosticTest() is invoked in
 *                           Mcu_InitClock() instead of Mcu_init()
 *                        9. Mcu_GetResetReason is updated since an internal
 *                           function 'Mcu_SaveResetReason()' will updated the
 *                           latest reset reason occurred
 *                        10. Mcu_GetResetRawValue is updated since an internal
 *                            function 'Mcu_SaveResetReason()' will updated the
 *                            reset raw value
 *                        11. Mcu_GetRamState() is updated for addition of
 *                            CRITICAL_SECTION
 *                        12. Mcu_ClmaSelfDiagnosticTest() prototype is changed
 *                            for passing calculated delay count for two
 *                            sampling cycles also Mcu_CvmSelfDiagnosticTest()
 *                            is updated for providing 12us delay
 *                        13. MCU_EIC8L is replaced with MCU_IMR0EIMK8 register
 *                            to enable interrupt through IMR register
 *                        14. MCU_RAM_SECTOR_SETTING_CONFIGURED precompile
 *                            option is added for Mcu_InitRamSection API
 *
 * V1.0.2:  12-May-2014 : As per CR99 and mantis #21334,
 *                        Following changes are made,
 *                        1. 'MISRA C Rule Violations' section is updated for
 *                           Justification of misra rule 7:0505
 *
 * V1.0.3:  26-Sep-2014 : As per CR008 and mantis #19850,
 *                        Following changes are made,
 *                        1. Mcu_Init API is updated for changing 8 bit register
 *                           access to 32 bit and ECM delay timer start settings
 *                           are added
 *                        2. Mcu_GetResetReason API is updated to remove
 *                           unreferenced variables
 *                        3. Mcu_PerformReset and Mcu_SaveResetReason APIs are
 *                           updated to add Mcu_ProtectedWriteRetNone macro
 *                           instead of Mcu_ProtectedWrite macro
 *                        4. Mcu_EcmSelfDiagnosticTest API is updated for
 *                           ERROROUT generation for ECM source 29 and 8 bit
 *                           register access to 32 bit
 *                        5. Trace marking is added throughout the file
 *                        6. Mcu_Init and Mcu_SaveResetReason APIs are updated
 *                           to configure, check and store CVM reset status
 *                        7. Mcu_Init and Mcu_EcmSelfDiagnosticTest APIs are
 *                           updated to remove Nesting of control structures
 *                           exceeds 15 QAC warning
 *                        8. Mcu_ClearEcmErrorOutput API added to remove
 *                           QAC warning in Mcu_EcmSelfDiagnosticTest API
 *
 * V1.0.4:  09-Dec-2014 : As per CR076 and mantis #18031 and #17005
 *                        Following changes are made,
 *                        1. As per coding rule constants are moved towards
 *                           left side of the respective operands.
 *                        2. Unwanted QAC comments are removed from Mcu_Init
 *                           API.
 *                        3. End comment is added for QAC in Mcu_Init API.
 *                        4. SYNCP instruction execution is implemented when
 *                           IMR register is accessed in between DI and EI
 *                           instructions.
 *
 * V1.0.5:  11-Feb-2014 : As per mantis #26305 ,following changes are made:
 *                        1. REG_DATA_PROTECTION is renamed to
 *                           MCU_REGISTER_PROTECTION.
 *                        2. Copyright information is updated.
 *
 * V1.0.6:  25-Mar-2015 : 1. As per mantis #26418 ,following change is made:
 *                             MCU_SW_RST is corrected with name MCU_SW_RESET ,
 *                             MCU_WDT_RST is corrected with name
 *                             MCU_WATCHDOG_RESET ,
 *                             MCU_POWER_ON_CLEAR_RST is corrected with name
 *                             MCU_POWER_ON_RESET
 *                        2. Added code comments as per MO Review in Mantis
 *                             #27515
 *                        3. Justifications for QAC warnings Msg(4:0857),
 *                           Msg(4:2983), Msg(4:4499), Msg(4:2991), Msg(4:2982),
 *                           Msg(4:2992), Msg(4:2996), Msg(4:0400).
 *
 * V1.0.7:  09-Nov-2015 : Following changes are done as part of P1M 4.00.05
 *                        ASILD release -
 *                        1.As per ARDAAAE-1481, Added internal function
 *                          Mcu_SelectAdcClock to configure ADC clock, which
 *                          is called from Mcu_InitClock API.
 *                        2.As per ARDAAAE-1466, MCU_REGISTER_PROTECTION is
 *                          replaced with VARIABLE_PROTECTION in
 *                          API Mcu_GetRamState.
 *                        3.As per ARDAAAE-1464, introduced functions
 *                          Mcu_IdentifyEcmErrorSource, Mcu_ClearEcmErrorStatus,
 *                          Mcu_ConfigureClockMonitor, Mcu_ClockOutputSelect,
 *                          Mcu_ClockOutputSetDivider, Mcu_ConfigureLvi,
 *                          Mcu_EcmErrorOutputClear, Mcu_ConfigureEcm
 *                          Mcu_DisableEcmError29, Mcu_ConfigureEcmDelayTimer
 *                          and Mcu_ConfigureEcmRamErrors.
 *                        4.Added internal function Mcu_StartUPTest to implement
 *                          the requirements EAAR_PN0079_FSR_0099,
 *                          EAAR_PN0079_FSR_0100 and EAAR_PN0079_FSR_0101.
 *                        5.Added API Mcu_EcmReleaseErrorOutPin() as per the
 *                          requirement EAAR_PN0079_FSR_0043.
 *                        6.Updated internal function Mcu_EcmErrorOutputClear
 *                          for initial notification as per requirement
 *                          EAAR_PN0079_FSR_0102.
 *                        7. Removed two functions Mcu_EcmErrorOutputClear and
 *                           Mcu_DisableEcmError29.
 *                        8. Added new static function
 *                           Mcu_EcmErrorInitialNotification.
 *                        9. Acceptance comments(QAC comments) are fixed.
 *                        10. As per ARDAAAE-1464, following APIs are
 *                            introduced. Mcu_HardWareInit, Mcu_LviRegSettings,
 *                            Mcu_ConfigureEcmRegSettings,
 *                            Mcu_EcmDelayTimerRegisterSetting,
 *                            Mcu_CvmSelfDiagnosticSetting,
 *                            Mcu_EcmSelfDiagnosticFirstTest,
 *                            Mcu_EcmSelfDiagnosticSecondTest,
 *                            Mcu_ConfigureEcmRamErrorsSetting,
 *                            Mcu_EcmClearStatusRegister
 * V1.0.8:  29-Feb-2016 : Following changes are done as part of P1M 4.01.00
 *                        release
 *                        1. As per ticket ARDAAAE-1486, the local pointers
 *                           and variable are declared with memory class
 *                           AUTOMATIC
 *                        2. As per ticket ARDAAAE-1624, API Mcu_GetVersionInfo
 *                           is made as function and added null pointer
 *                           checking.
 *                        3. As per ticket ARDAAAE-1603, the function
 *                           Mcu_ClockOutputSelect() is updated to avoid
 *                           pointer accessing if ExternalClockIndex is
 *                           greater than 1.
 *                        4. As per ticket ARDAAAE-1593, the code section is
 *                           updated for APIs.
 *                        5. QAC warnings are fixed and justified.
 *                        6. UT ID TAG added for the non-covered parts of the
 *                           code.
 *                        7. As per REE MO review comments, the function
 *                           Mcu_ClockOutputSelect and Mcu_ClockOutputSetDivider
 *                           are updated.
 * V1.0.9:  24-Oct-2016 : Following changes are done
 *                        1. Mcu_CvmNormalModeSetting API added to meet
 *                           software metrics requirements.
 *                        2. As per ticket ARDAAAE-1686 added Write verify for
 *                           all registers and updated the macro
 *                           MCU_REG_WRITE_VERIFY.
 *                        3. As part of ticket ARDAAAE-1762 updated API
 *                           Mcu_HWInit and Mcu_ConfigureCvm
 *                        4. As per ticket ARDAAAE-1748 updated API
 *                           Mcu_ClmaSelfDiagnosticTest
 *                        5. As per REE MO review comments,
 *                           a) Changed function name Mcu_HardWareInit to
 *                              Mcu_HWInit
 *                           b) Moved global variables Mcu_GblDriverStatus,
 *                           Mcu_GblResetStatusSaved, Mcu_GulMcuSavedResfStatus,
 *                           Mcu_GulLastResetReasonStatus to Mcu.c file.
 *                           c) Updated function Mcu_ConfigureEcm and
 *                           Mcu_ClearEcmErrorOutput.
 *                           d) Added functions Mcu_StartUPEcmTest and
 *                              Mcu_StartUPSwTest
 *                        6. As per ticket ARDAAAE-1909, warranty disclaimer
 *                           updated.
 *                        7. As per ARDAAAE-1936 design requirement IDs,
 *                           MCU_ESDD_UD_xxx Ids added and trace IDs removed.
 *                        8. VARIABLE_PROTECTION renamed to
 *                           MCU_VARIABLE_PROTECTION.
 *                        9. MISRA messages 2992,2996,2880,2983,4499 removed
 *                           and added 4391,0317,1881,3218.
 *                       10. As per ticket ARDAAAE-2027, updated
 *                           Mcu_ConfigureCvm for verifying cvm self diag
 *                           locking functionality.
 *                       11. MCU_UT_00X tag added for the non-covered parts of
 *                           the code.
 *                       12. As per safety analysis updated function
 *                           Mcu_ConfigureEcmDelayTimer by adding critical
 *                           section and updated Mcu_CvmNormalModeSetting for
 *                           correct status checking.
 *                       13. As per ticket ARDAAAE-2060, unmapped design
 *                           requirements mapped.
 *                       14. As per ticket ARDAAAE-2103, updated write
 *                           verification of RESF registers.
 *                       15. Following MISRA warnings messages added:
 *                           Msg(4:2986), Msg(4:2983).
 * V1.0.10:  11-Jan-2017 : Following changes are done
 *                         1. As per ARDAAAE-2125 following changes are made:
 *                            a. Updated Mcu_Init for initialisation of Global
 *                               variables.
 *                            b. Removed multiple declarations in same line from
 *                               Mcu_HWInit.
 *                            c. Removed justification for MISRA Msg(4:0857) and
 *                               Msg(4:3218) and updated Mcu_StartUPTest for
 *                               fixing MISRA warnings.
 *                         2. As per ARDAAAE-2358, following changes are done:
 *                            a. Modified naming of local variable in function
 *                               Mcu_GetResetRawValue.
 *                            b. Declaration of local variables are changed for
 *                               using macros.
 *                            c. Updated macros MCU_PROTECTEDWRITE and
 *                               MCU_PROTECTEDWRITERETNONE as per naming
 *                               convention.
 *                            d. Values move to LHS during comparison and proper
 *                               spacing provided as per coding guidelines.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0021, EAAR_PN0034_NR_0001 */
/* Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0018, EAAR_PN0034_NR_0056 */
/* Implements EAAR_PN0034_NR_0045, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0044 */
/* Included for Post-build Time Parameters */
#include "Mcu_PBTypes.h"
/* Included for RAM variable declarations */
#include "Mcu_Ram.h"
/* Implements MCU013, MCU163, MCU166_Conf, MCU016, MCU012, MCU112 */
/* Implements EAAR_PN0034_FR_0061 */
/* Implements MCU_ESDD_UD_052 */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

/* Included for declaration of the function Dem_ReportErrorStatus() */
/* Implements MCU102, MCU109, MCU152, MCU111, MCU226 */
#include "Dem.h"
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0013
*/
/* Implements MCU_ESDD_UD_058 */
#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* Included for Register access */
#include "Mcu_Reg.h"
/* Implements MCU108 */
/* Included for module version information */
#include "Mcu.h"
/* Implements MCU219 */
#include "Mcu_Cbk.h"
#include "Mcu_RegWrite.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*Implements EAAR_PN0034_FR_0055*/
/* AUTOSAR release version information */
#define MCU_C_AR_RELEASE_MAJOR_VERSION     MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_MINOR_VERSION     MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_REVISION_VERSION  MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_C_SW_MAJOR_VERSION     1
#define MCU_C_SW_MINOR_VERSION     0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu.c : Mismatch in Release Major Version"
#endif /* (MCU_AR_RELEASE_MAJOR_VERSION != MCU_C_AR_RELEASE_MAJOR_VERSION) */

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu.c : Mismatch in Release Minor Version"
#endif /* (MCU_AR_RELEASE_MINOR_VERSION != MCU_C_AR_RELEASE_MINOR_VERSION) */

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu.c : Mismatch in Release Revision Version"
#endif /* (MCU_AR_RELEASE_REVISION_VERSION !=
*                                MCU_C_AR_RELEASE_REVISION_VERSION)
*/

#if (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION)
  #error "Mcu.c : Mismatch in Software Major Version"
#endif /* (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION) */

#if (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION)
  #error "Mcu.c : Mismatch in Software Minor Version"
#endif /* (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION) */
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/*Implements EAAR_PN0034_NR_0026*/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0316)Cast from a pointer to void to a pointer to object */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the     */
/*                 type to the upper layer.                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-1 and                           */
/*                 END Msg(4:0316)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-2 and                           */
/*                 END Msg(4:0303)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Pointer arithmetic is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-3 and                           */
/*                 END Msg(4:0488)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4464) A constant expression of 'essentially unsigned'   */
/*                 type is being converted to narrower unsigned type,         */
/*                 'unsigned char' on assignment.                             */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : The 8-bit write protected register is written with 32-bit  */
/*                 value as this is the constant value to be written in       */
/*                 sequence.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4464)-4 and                           */
/*                 END Msg (4:4464)-4 tags in the code.                       */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified                 */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The return value is updated in the macro.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-5 and                           */
/*                 END Msg(4:2982)-5 tags in the code.                        */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4391) A composite expression of 'essentially unsigned'  */
/*                 type (unsigned char) is being cast to a wider unsigned     */
/*                 type, 'unsigned long'.                                     */
/* Rule          : MISRA-C:2004 Rule 10.7                                     */
/* Justification : The unsigned char is used to save memory.However the value */
/*                 stored is ASCI format of numeric digits. When this is      */
/*                 typecast, 0 will be padded to left of the digit. This wont */
/*                 change the original value.                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4391)-6  and                          */
/*                 END Msg(4:4391)-6  tags in the code.                       */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0317)Implicit conversion from a pointer to void to a    */
/*                  pointer to object type.                                   */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the type*/
/*                 to the upper layer.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for MISRA Violation: START Msg(4:0317)-7 and          */
/*                 END Msg(4:0317)-7 tags in the code.                        */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0400) 'LulEcmConfigAddress' is modified more than once  */
/*                 between sequence points - evaluation order unspecified.    */
/* Rule          : MISRA-C:2004 Rule 1.2 and Rule 12.2                        */
/* Justification : 'LulEcmConfigAddress' is incremented by 4. This is a valid */
/*                 statement in C                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0400)-8 and                           */
/*                 END Msg(4:0400)-8 tags in the code.                        */
/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2962) Using value of uninitialized automatic object '%s'*/
/* Rule          : MISRA-C:2004 Rule 9.1                                      */
/* Justification : The variable will be initialized in the switch-case before.*/
/*                 Initialization can't be moved out of switch case since     */
/*                 different values are assigned depending on function        */
/*                 argument.                                                  */
/* Verification  : However, it is verified that only values expected by       */
/*                 switch-case is passed as function argument and default case*/
/*                 will never be executed. Hence this variable will always be */
/*                 initialized.                                               */
/* Reference     : Look for START Msg(4:2962)-9 and                           */
/*                 END Msg(4:2962)-9 tags in the code.                        */
/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0489) The integer value 1 is being added or subtracted  */
/*                 from a pointer.                                            */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Pointer arithmetic is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-10 and                          */
/*                 END Msg(4:0489)-10 tags in the code.                       */
/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0491) An array subscript operator is being used to      */
/*                 subscript an expression which is not of array type.        */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This pointer addresses an array element                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-11 and                          */
/*                 END Msg(4:0491)-11 tags in the code.                       */
/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:1881) The operands of this equality operator are        */
/*                 expressions of different 'essential type' categories       */
/*                 (unsigned and enum).                                       */
/* Rule          : MISRA-C:2004 Rule 10.1.                                    */
/* Justification : The condition is  comparing the value stored in those      */
/*                 variables of different data types. The possible values are */
/*                 one digit numeric values which is  stored as LSB.          */
/*                 This dont affect the operations to be performed whatever   */
/*                 the datatype  is at left and right of operator.            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1881)-12 and                          */
/*                 END Msg(4:1881)-12 tags in the code.                       */
/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2986)This operation is redundant. The value of the      */
/*                 result is always that of the right-hand operand.           */
/* Rule          : MISRA-C:2004 Rule 21.1.                                    */
/* Justification : The value of the variable changes with respect to different*/
/*                 configurations.The value of the result will not be the same*/
/*                 always.                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2986)-13 and                          */
/*                 END Msg(4:2986)-13 tags in the code.                       */
/******************************************************************************/

/* 14. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2983)TThis assignment is redundant. The value of this   */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1.                                    */
/* Justification : Dummy operation on variable is required for testing purpose*/
/*                 of Lockstep functionality.                                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-14 and                          */
/*                 END Msg(4:2983)-14 tags in the code.                       */
/******************************************************************************/


/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR  and vendor             */
/*                 specific Api's cannot be modified to be made as constant.  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-1 and                           */
/*                 END Msg(2:3227)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-2 and                           */
/*                 END Msg(2:2814)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty.*/
/* Rule          : NA                                                         */
/* Justification : No action is required for default statements. Hence it is  */
/*                 left empty.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2016)-3 and                           */
/*                 END Msg(2:2016)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:3204) This variable is only set once and so it could    */
/*                        be declared with the 'const' qualifier..            */
/* Rule          : NA                                                         */
/* Justification : The variable can be set twice if different configurations  */
/*                 are used.Hence it will not declared with 'const' qualifier */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3204)-4 and                           */
/*                 END Msg(2:3204)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                  to another type                                           */
/* Rule          : NA                                                         */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This implicit conversion is done to access the data from   */
/*                  the post build configuration                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-5 and                           */
/*                 END Msg(2:3892)-5 tags in the code.                        */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files is done within the code.              */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:4342) An expression of 'essentially unsigned' type      */
/*                 (unsigned char) is being cast to enum type                 */
/* Rule          : NA                                                         */
/* Justification : This implicit conversion is done to access the global data */
/*                 with different data type to enum type since the size of    */
/*                 variable should be declared  before using it.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:4342)-7  and                          */
/*                 END Msg(2:4342)-7  tags in the code.                       */
/******************************************************************************/

/* 8. QAC Warning:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Rule          : NA                                                         */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access. All register addresses are generated with */
/*                 volatile qualifier. There is no impact on the functionality*/
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3416)-8  and                          */
/*                 END Msg(2:3416)-8  tags in the code.                       */
/******************************************************************************/

/* 9. QAC Warning:                                                            */
/* Message       : (2:2881) The code in 'default' statement of switch case    */
/*                 is unreachable.                                            */
/* Rule          : NA                                                         */
/* Justification : Implementation do not demands the codes in 'default'       */
/*                 statement of switch case since all expressions are handled */
/*                 with constant-expression cases                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2881)-9  and                          */
/*                 END Msg(2:2881)-9  tags in the code.                       */
/******************************************************************************/

/* 10. QAC Warning:                                                           */
/* Message       : (2:3206) The parameter 'AREGUMENT' is not used in this     */
/*                 function.                                                  */
/* Rule          : NA                                                         */
/* Justification : Implementation do not demands the use of parameter         */
/*                 since function is dummy and controller does not support the*/
/*                 feature                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-10 and                          */
/*                 END Msg(2:3206)-10 tags in the code.                       */
/******************************************************************************/

/* 11. QAC Warning:                                                           */
/* Message       : (2:2755) Analysis time of function 'Mcu_HWInit' has        */
/*                  exceeded the configured maximum: '60000ms'.  Dataflow     */
/*                 analysis continues with the next function.                 */
/* Rule          : NA                                                         */
/* Justification : Implementation demands usage of all MCU features so it     */
/*                 takes/exceeds the execution time                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(0:2755)-11 and                          */
/*                 END Msg(0:2755)-11 tags in the code.                       */
/******************************************************************************/

/* 12. QAC Warning:                                                           */
/* Message       : (3:3203) The variable 'Parameter' is set but never used.   */
/* Rule          : NA                                                         */
/* Justification : Parameter is used with pointer access method. Hence cannot */
/*                 be avoided. However part of this code has no impact on     */
/*                 functionality.                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(3:3203)-12 and                          */
/*                 END Msg(3:3203)-12 tags in the code.                       */
/******************************************************************************/

/* 13. QAC Warning:                                                           */
/* Message       : Msg(2:2022)  A tentative definition is being used.         */
/*                   Is it appropriate to include an explicit initializer ?   */
/* Rule          : NA                                                         */
/* Justification : As per coding guidelines, initialization and declaration   */
/*                 should be in different lines.These variable is initialized */
/*                 in Mcu_Init                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-13 and                          */
/*                 END Msg(2:2022)-13 tags in the code.                       */

/*******************************************************************************
**             Internal Function Prototypes                                   **
*******************************************************************************/
/*Implements EAAR_PN0034_FR_0052 */
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_HWInit(void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureCvm(void);
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_SaveResetReason (void);
STATIC FUNC(Mcu_ResetType, MCU_PRIVATE_CODE) Mcu_IdentifyEcmErrorSource (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureLvi (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_LviRegSettings
    (CONST(uint32, MCU_VAR) LulCntValue, CONST(boolean, MCU_VAR)  WriteVerify);
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_EcmErrorInitialNotification (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcm (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmRegSettings
                                                                         (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmDelayTimer (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmDelayTimerRegisterSetting
                                                                         (void);

/* Implements MCU_ESDD_UD_059 */
/* Implements EAAR_PN0079_FSR_0022 */
#if (MCU_CLMA_OPERATION == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureClockMonitor (void);
#endif /* (MCU_CLMA_OPERATION == STD_ON) */

/* Implements MCU_ESDD_UD_063 */
#if (MCU_CLMA_SELFDIAGNOSTIC_TEST == STD_ON)
/* Implements MCU_ESDD_UD_108 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClmaSelfDiagnosticTest
(P2CONST(Mcu_ClockMonitorConf, AUTOMATIC, MCU_CONFIG_CONST)
LpClmaConfigPtr);
#endif /* (MCU_CLMA_SELFDIAGNOSTIC_TEST == STD_ON) */

/* Implements MCU_ESDD_UD_060 */
/* Implements EAAR_PN0079_FSR_0023 */
#if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmSelfDiagnosticTest (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmSelfDiagnosticSetting
                                                                        (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmNormalModeSetting(void);
#endif /* (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON) */

/* Implements MCU_ESDD_UD_061 */
#if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticTest (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticFirstTest
                                                                        (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticSecondTest
                                                                        (void);
#endif /* (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON) */

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClearEcmErrorOutput
   (const uint8 ApiId);

/*Implements EAAR_PN0079_FSR_0093*/
/* Implements MCU_ESDD_UD_064 */
#if (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
                                        Mcu_LockStepSelfDiagnosticTest (void);
#endif /* (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON) */

/* Implements MCU_ESDD_UD_066 */
/* Implements MCU182_Conf, MCU210 */
#if (MCU_INIT_CLOCK == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_SelectAdcClock (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClockOutputSelect
                                  (CONST(uint8, MCU_VAR) ExternalClockIndex);


STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClockOutputSetDivider
                              (CONST(uint32, MCU_VAR)  ExternalClockDivider);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmRamErrors (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmRamErrorsSetting
     (CONST(uint32, MCU_VAR) ConfigMaskRegvalue,
      CONST(uint32, MCU_VAR) RAMMaskMacroValue,
      CONST(uint8, MCU_VAR) Offset,
      CONST(uint8, MCU_VAR) Index);

/* Implements MCU_ESDD_UD_081 */
#if ((MCU_SW_STARTUP_TEST == STD_ON) || (MCU_ECM_STARTUP_TEST == STD_ON))
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_StartUPTest(void);

#if (MCU_ECM_STARTUP_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_StartUPEcmTest(void);
#endif

#if (MCU_SW_STARTUP_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_StartUPSwTest(void);
#endif
#endif /* (MCU_SW_STARTUP_TEST == STD_ON) || (MCU_ECM_STARTUP_TEST == STD_ON) */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmClearStatusRegister
                                                        (const uint8 ApiId);

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*To use VAR_BOOLEAN section in the Memory*/
#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/*START Msg(2:2022)-13*/
/* Implements MCU_ESDD_UD_090 */
/* Global variable to store Initialization status of MCU Driver */
VAR(STATIC boolean, MCU_INIT_DATA) Mcu_GblDriverStatus;
/* Implements MCU_ESDD_UD_091 */
VAR(STATIC boolean, MCU_INIT_DATA)Mcu_GblResetStatusSaved;
/*Exit VAR_BOOLEAN section in the Memory*/
#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/*To use VAR_32 section in the Memory*/
#define MCU_START_SEC_VAR_INIT_32
#include "MemMap.h"
/* START Msg(2:3211)-13 */
/* START Msg(2:3892)-5 */
/* Implements MCU_ESDD_UD_091 */
/* Global variable to store Last Reset reason status of MCU Driver */
VAR(STATIC uint32, MCU_INIT_DATA)Mcu_GulLastResetReasonStatus;

/* Implements MCU_ESDD_UD_091 */
/* Global variable to save RESF status of MCU Driver */
VAR(STATIC uint32, MCU_INIT_DATA)Mcu_GulMcuSavedResfStatus;
/* END Msg(2:3211)-13 */
/* END Msg(2:3892)-5 */
/* END Msg(2:2022)-13*/
/*Implements EAAR_PN0079_FR_0002, EAAR_PN0034_FR_0013*/
/*To use VAR_32 section in the Memory*/
#define MCU_STOP_SEC_VAR_INIT_32
#include "MemMap.h"
/*******************************************************************************
**             Function Definitions                                           **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Mcu_Init
**
** Service ID         : 0x00
**
** Description        : This service performs initialization of the MCU Driver
**                      component.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ConfigPtr - Pointer to MCU Driver Configuration set
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GblDriverStatus,
**                      Mcu_GblResetStatusSaved, Mcu_GulLastResetReasonStatus,
**                      Mcu_GulMcuSavedResfStatus
**
** Function Invoked   : Mcu_HWInit
**
** Registers Used     : None
*******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements MCU153, MCU026, MCU163, MCU166_Conf, MCU018 */
/* Implements MCU017, EAAR_PN0034_FR_0025 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0064 */
/* Implements MCU_ESDD_UD_001 */

/* START Msg(2:3227)-1 */
FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
                (P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-1 */
{
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the config pointer is NULL pointer */
  if (NULL_PTR == ConfigPtr)
  {
    /* Implements MCU_ESDD_UD_044 */
    /* Implements MCU_ESDD_UD_072 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_INIT_SID, MCU_E_PARAM_CONFIG);
  }
  /* Check if the database is present */
  else if (MCU_DBTOC_VALUE != (ConfigPtr->ulStartOfDbToc))
  {
    /* Implements MCU_ESDD_UD_050 */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_SID,
    MCU_E_INVALID_DATABASE);
  } /* End of (MCU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc)) */
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Assign the global pointer with the config pointer */
    Mcu_GpConfigPtr = ConfigPtr;

    /*Initialising global variables*/
    Mcu_GblDriverStatus = MCU_UNINITIALIZED;
    Mcu_GblResetStatusSaved = MCU_FALSE;
    Mcu_GulLastResetReasonStatus = MCU_LONG_WORD_ZERO;
    Mcu_GulMcuSavedResfStatus = MCU_LONG_WORD_ZERO;

    /* Configure Mcu Hardware settings */
    (void)Mcu_HWInit();
  }
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"


/*******************************************************************************
** Function Name      : Mcu_InitRamSection
**
** Service ID         : 0x01
**
** Description        : This function initializes the RAM section as provided
**                      from the configuration structure.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : RamSection - Id for RAM section
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpConfigPtr
**
** Function Invoked   : Mcu_ConfigureEcmRamErrors, MCU_ENTER_CRITICAL_SECTION,
**                      MCU_EXIT_CRITICAL_SECTION, MCU_PROTECTEDWRITE,
**
** Registers Used     : ECMMESSTR0, ECMESSTC0, ECMPCMD1, ECMPS, ECMMESSTR1,
**                      ECMESSTC1
*******************************************************************************/
#if (MCU_RAM_SECTOR_SETTING_CONFIGURED == STD_ON)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements MCU154, MCU239, MCU136, MCU011, MCU017, EAAR_PN0034_FSR_0004 */
/* Implements EAAR_PN0079_FR_0012, MCU152, MCU166_Conf, EAAR_PN0034_FSR_0001 */
/* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0003, EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0013, MCU172_Conf, MCU021*/
/* Implements MCU125, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0049, MCU125 */
/* Implements EAAR_PN0034_NR_0020*/
/* START Msg(2:3227)-1 */
/* Implements MCU_ESDD_UD_002 */
/* Implements MCU_ESDD_UD_080 */
/* Implements MCU_ESDD_UD_079 */
/* Implements MCU_ESDD_UD_078 */
/* Implements MCU_ESDD_UD_077 */
/* Implements MCU_ESDD_UD_076 */
/* Implements MCU_ESDD_UD_095 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
                                                (Mcu_RamSectionType RamSection)
/* END Msg(2:3227)-1 */
{
  /* Implements MCU_ESDD_UD_102 */
  /* Pointer to Ram setting */
  P2CONST(Mcu_RamSetting, AUTOMATIC, MCU_CONFIG_CONST) LpRamSetting;

  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(volatile uint32, AUTOMATIC) LulRamStartAddress;
  VAR(uint32, AUTOMATIC) LulNoOfByte;
  VAR(uint8, AUTOMATIC) LucDataByte;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  /* Initialize return value with E_OK */
  LenReturnValue = E_OK;
  /* Initialize to false */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    /* Implements MCU_ESDD_UD_072 */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                         MCU_INITRAMSECTION_SID, MCU_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements MCU_ESDD_UD_074 */
  /* Report to DET, if RamSetting Id is out of range */
  if (MCU_MAX_RAMSETTING <= RamSection)
  {
    /* Implements MCU_ESDD_UD_047 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                               MCU_INITRAMSECTION_SID, MCU_E_PARAM_RAMSECTION);
    /* Set return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if any development error occurred */
  if (E_OK == LenReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:0316)-1 */
    /* START Msg(2:2814)-2 */
    /* Get the pointer to the RAM structure */
    LpRamSetting = (((P2CONST(Mcu_RamSetting, AUTOMATIC, MCU_CONFIG_CONST))
                                   Mcu_GpConfigPtr->pRamSetting) + RamSection);
    /* END Msg(2:2814)-2 */
    /* END Msg(4:0316)-1 */
    /* END Msg(4:0488)-3 */

    /* START Msg(2:2814)-2 */
    /* Get the start address of the RAM section */
    LulRamStartAddress = LpRamSetting->ulRamSectionBaseAddress;
    /* END Msg(2:2814)-2 */

    /* Get the size of RAM section */
    LulNoOfByte = LpRamSetting->ulRamSectionSize;

    /* Get initial value */
    LucDataByte = (uint8)LpRamSetting->ulRamDefaultValue;
    while (MCU_LONG_WORD_ZERO != LulNoOfByte)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Write configured data to memory address */
      *((volatile uint8*)LulRamStartAddress) = LucDataByte;
      /* END Msg(4:0303)-2 */

      /* Decrement the size */
      LulNoOfByte--;

      /* Increment the pointer of RAM Section address */
      LulRamStartAddress++;
    }

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Check and clear if any ECM ram error during initialization */
    if ((MCU_ECMMESSTR0 & MCU_RAM_MASK0_VALUE) != MCU_LONG_WORD_ZERO)
    /* END Msg(4:0303)-2 */
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

      /* Implements MCU_ESDD_UD_071 */
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Implements MCU_ESDD_UD_083 */
      /* Clear the ECM ram error */
      MCU_PROTECTEDWRITE (MCU_ECMESSTC0, MCU_RAM_MASK0_VALUE, MCU_ECMPCMD1,
      MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* START Msg(2:3416)-8  */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_RUNTIME(MCU_ECMMESSTR0, MCU_LONG_WORD_ZERO,
      MCU_FULL_MASK, MCU_INITRAMSECTION_SID)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3416)-8  */

      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    else
    {
      /* No action required  */
    }

    /* Check whether Dem reported or not */
    if (E_OK == LenReturnValue)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Check and clear if any ECM ram error during initialization */
      if ((MCU_ECMMESSTR1 & MCU_RAM_MASK1_VALUE) != MCU_LONG_WORD_ZERO)
      /* END Msg(4:0303)-2 */
      {
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
        #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

        /* Initialize the retry count to config value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* MISRA Violation: START Msg(4:2982)-5 */

        /* Clear the ECM ram error */
        MCU_PROTECTEDWRITE (MCU_ECMESSTC1, MCU_RAM_MASK1_VALUE, MCU_ECMPCMD1,
        MCU_ECMPS, LucRetryCount, LenReturnValue)
        /* END Msg(4:2982)-5 */
        /* END Msg(4:0303)-2 */
        /* START Msg(2:3416)-8  */
        /* MISRA Violation: START Msg(4:0303)-2 */
        MCU_REG_WRITE_VERIFY_RUNTIME(MCU_ECMMESSTR1, MCU_LONG_WORD_ZERO,
        MCU_FULL_MASK, MCU_INITRAMSECTION_SID)
        /* END Msg(4:0303)-2 */
        /* END Msg(2:3416)-8  */
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
        #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      else
      {
        /* No action required  */
      }
      LenReturnValue = Mcu_ConfigureEcmRamErrors();
    }
    else
    {
      /* No action required */
    }
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Set return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  #endif /* if (MCU_DEV_ERROR_DETECT == STD_ON) */

  return (LenReturnValue);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_RAM_SECTOR_SETTING_CONFIGURED == STD_ON) */


/*******************************************************************************
** Function Name      : Mcu_InitClock
**
** Service ID         : 0x02
**
** Description        : This service initializes the PLL and other MCU specific
**                      clock options.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ClockSetting - Id for Clock setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpClockSetting, Mcu_GpConfigPtr
**
** Function Invoked   : Mcu_ClockOutputSelect, Mcu_SelectAdcClock,
**                      Mcu_ConfigureClockMonitor, Det_ReportError,
**
** Registers Used     : None
*******************************************************************************/
/* Implements MCU_ESDD_UD_066 */
#if (MCU_INIT_CLOCK == STD_ON)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements MCU155, MCU137, MCU183_Conf, MCU139, MCU210, MCU248 */
/* Implements MCU232, MCU152, MCU166_Conf, MCU017, MCU232, MCU019 */
/* Implements MCU125, MCU138, MCU182_Conf, EAAR_PN0079_FSR_0022 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0064 */

/* START Msg(2:3227)-1 */
/* Implements MCU_ESDD_UD_003, MCU_ESDD_UD_096 */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting)
/* END Msg(2:3227)-1 */
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  /* MISRA Violation: START Msg(4:2982)-5 */
  /* Initialize to default values */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_INITCLOCK_SID, MCU_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Report to DET, if clock setting Id is invalid */
  /* Implements MCU_ESDD_UD_070 */
  if (MCU_MAX_CLK_SET <= ClockSetting)
  {
    /* Implements MCU_ESDD_UD_045 */
    /* Implements MCU_ESDD_UD_072 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
    MCU_INITCLOCK_SID, MCU_E_PARAM_CLOCK);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if any development error occurred */
  if (E_OK == LenReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Violation: START Msg(4:0316)-1 */
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* START Msg(2:2814)-2 */
    /* Store the pointer to the configured clock structure  */
    Mcu_GpClockSetting =
    (((P2CONST(Mcu_ClockSetting, AUTOMATIC, MCU_CONFIG_CONST))
    Mcu_GpConfigPtr->pClockSetting) + ClockSetting);
    /* END Msg(2:2814)-2  */
    /* END Msg(4:0488)-3 */
    /* END Msg(4:0316)-1 */

    LenReturnValue = Mcu_ClockOutputSelect(MCU_ZERO);
    if (E_OK == LenReturnValue)
    {
      LenReturnValue = Mcu_ClockOutputSelect(MCU_ONE);
    }
    else
    {

    }

    if (E_OK == LenReturnValue)
    {
      /* Select ADC clock */
      LenReturnValue = Mcu_SelectAdcClock();
    }
    else
    {
      /* No action required */
    }

    /* Implements MCU_ESDD_UD_059 */
    /* Implements EAAR_PN0079_FSR_0022 */
    #if (MCU_CLMA_OPERATION == STD_ON)
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Check if No Dem error occurred */
    if (E_OK == LenReturnValue)
    /* END Msg(4:0303)-2 */
    {
      /* Configure Clock monitor unit */
      LenReturnValue = Mcu_ConfigureClockMonitor();
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_CLMA_OPERATION == STD_ON) */
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  return (LenReturnValue);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*******************************************************************************
** Function Name      : Mcu_DistributePllClock
**
** Service ID         : 0x03
**
** Description        : This service activates the PLL clock to the MCU clock
**                      distribution
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_GetPllStatus, Det_ReportError
**
** Registers Used     : None
*******************************************************************************/
/* Implements MCU_ESDD_UD_065 */
#if (MCU_NO_PLL == STD_OFF)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements MCU_ESDD_UD_004 */
/* Implements MCU156, MCU140, MCU141, MCU056, MCU142, MCU205 */
/* Implements MCU166_Conf, MCU017, MCU125, MCU180_Conf, EAAR_PN0034_FR_0049 */
/* Implements EAAR_PN0034_FR_0064 */
FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void)
{
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Implements MCU_ESDD_UD_093 */
  VAR(Mcu_PllStatusType, AUTOMATIC) LddPllLockStatus;

  /* Get the PLL status */
  LddPllLockStatus = Mcu_GetPllStatus();

  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                  MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_UNINIT);
  }
  else
  {
    /* No action required */
  }

  /* Get the PLL status and if PLL status is not 'LOCKED', report to DET */
  if (MCU_PLL_UNLOCKED == LddPllLockStatus)
  {
    /* Implements MCU_ESDD_UD_048 */
    /* Report to DET */
    /* Implements MCU_ESDD_UD_072 */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                            MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_PLL_NOT_LOCKED);
  }
  /* If no DET error, continue */
  else
  {
    /* No action required */
  }
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_NO_PLL == STD_OFF) */
/*******************************************************************************
** Function Name      : Mcu_GetPllStatus
**
** Service ID         : 0x04
**
** Description        : This service provides the lock status of the PLL
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_PllStatusType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
*******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_005 */
/* Implements MCU008 , MCU230, MCU142, MCU132, MCU206, MCU017 */
/* Implements MCU166_Conf, MCU125, MCU157, MCU180_Conf, EAAR_PN0034_FR_0049 */
/* Implements EAAR_PN0034_FR_0064 */

FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void)
{
  /* START Msg(2:3204)-4 */
  VAR(Mcu_PllStatusType, AUTOMATIC) LddPllLockStatus;
  /* Set PLL status to undefined */
  LddPllLockStatus = MCU_PLL_STATUS_UNDEFINED;
  /* END Msg(2:3204)-4 */

  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                          MCU_GETPLLSTATUS_SID, MCU_E_UNINIT);
    #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    /* Implements MCU_ESDD_UD_065 */
    #if (MCU_NO_PLL == STD_OFF)
    /* PLL is locked */
    LddPllLockStatus = MCU_PLL_LOCKED;
    #endif /* (MCU_NO_PLL == STD_OFF) */
  }
  return(LddPllLockStatus);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_GetResetReason
**
** Service ID         : 0x05
**
** Description        : The function reads the reset type from the hardware
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_ResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GulLastResetReasonStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
*******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_006 */
/* Implements MCU005, MCU133, MCU158, EAAR_PN0079_FSR_0017, MCU125 */
/* Implements MCU166_Conf, MCU052, EAAR_PN0079_FSR_0016, MCU017 */
/* Implements EAAR_PN0079_FSR_0003, EAAR_PN0079_FSR_0017 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0064 */
/* Implements EAAR_PN0079_FSR_0086 */

FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason (void)
{
  VAR(Mcu_ResetType, AUTOMATIC) LddResetSource;

  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                        MCU_GETRESETREASON_SID, MCU_E_UNINIT);
    #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    /* Set Reset status to undefined */
    LddResetSource = MCU_RESET_UNDEFINED;
  }
  else
  {
    /* START Msg(2:4342)-7  */
    /* return the last reset reason status */
    LddResetSource = (Mcu_ResetType)Mcu_GulLastResetReasonStatus;
    /* END Msg(2:4342)-7  */
  }

  return (LddResetSource);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_GetResetRawValue
**
** Service ID         : 0x06
**
** Description        : The service return reset type value from the hardware
**                      register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_RawResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GulMcuSavedResfStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_007 */
/* Implements MCU_ESDD_UD_098 */
/* Implements MCU006, MCU135, MCU159, EAAR_PN0079_FSR_0017 */
/* Implements MCU166_Conf, MCU017, MCU125, EAAR_PN0079_FSR_0086 */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0064 */

FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void)
{
  VAR(uint32, AUTOMATIC) LulResetValue;

  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                    MCU_GETRESETRAWVAULE_SID, MCU_E_UNINIT);
    #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    /* Set RESET status to uninitialized */
    LulResetValue = MCU_RESET_UNINIT;
  }
  else
  {
    /* Return the last clear reset raw status */
    LulResetValue = Mcu_GulMcuSavedResfStatus;
  }

  return(LulResetValue);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_PerformReset
**
** Service ID         : 0x07
**
** Description        : This service provides microcontroller reset by accessing
**                      the Software reset register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : MCU_RESET_CALLOUT, Det_ReportError,
**                      MCU_PROTECTEDWRITERETNONE
**
** Registers Used     : SWRESA, PROT1PHCMD, PROT1PS
******************************************************************************/
/* Implements MCU_ESDD_UD_054 */
#if (MCU_PERFORM_RESET_API == STD_ON)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements MCU_ESDD_UD_008 */
/* Implements MCU143, MCU144, MCU145, MCU146, MCU160, MCU125, MCU055 */
/* Implements EAAR_PN0079_FSR_0013, MCU167_Conf, EAAR_PN0079_FSR_0014, MCU017 */
/* Implements EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0064, EAAR_PN0034_NR_0020 */

FUNC (void, MCU_PUBLIC_CODE) Mcu_PerformReset (void)
{
  /* Implements MCU_ESDD_UD_055 */
  #if (MCU_SW_RESET_CALL_API == STD_OFF)
  VAR(uint8, AUTOMATIC) LucSWRESCount;
  /* Implements MCU_ESDD_UD_071 */
  LucSWRESCount = MCU_LOOPCOUNT;
  #endif /* (MCU_SW_RESET_CALL_API == STD_OFF) */

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Implements MCU_ESDD_UD_072 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                        MCU_PERFORMRESET_SID, MCU_E_UNINIT);
  }
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Implements MCU_ESDD_UD_055 */
    #if (MCU_SW_RESET_CALL_API == STD_ON)
    /* invoke the reset call API */
    /*Implements EAAR_PN0079_FSR_0014*/
    MCU_RESET_CALLOUT();
    #else

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3892)-5 */
    /* Write value to SWRESA register */
    MCU_PROTECTEDWRITERETNONE(MCU_SWRESA, MCU_RES_CORRECT_VAL, MCU_PROT1PHCMD,
    MCU_PROT1PS, LucSWRESCount)
    /* END Msg(2:3892)-5 */
    /* END Msg(4:0303)-2 */

    #endif /* (MCU_SW_RESET_CALL_API == STD_ON) */
  }
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_PERFORMRESET_API == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_SetMode
**
** Service ID         : 0x08
**
** Description        : This service activates the MCU power modes
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : McuMode - Id for power mode setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* START Msg(2:3227)-1 */
/* START Msg(2:3206)-10 */
/* Implements MCU_ESDD_UD_009, MCU_ESDD_UD_100 */
/* Implements MCU017, MCU125, MCU161, MCU237, MCU148, EAAR_PN0034_FR_0049 */
/* Implements EAAR_PN0034_FR_0064, EAAR_PN0034_NR_0020 */
FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode)
/* END Msg(2:3206)-10 */
/* END Msg(2:3227)-1 */
{
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                              MCU_SETMODE_SID, MCU_E_UNINIT);
  }
  else
  {
    /* No action required */
  }

  if (MCU_MAX_MODESETTING <= McuMode )
  {
    /* Implements MCU_ESDD_UD_046 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                          MCU_SETMODE_SID, MCU_E_PARAM_MODE);
  }
  else
  {
    /* No action required */
  }

  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Mcu_GetRamState
**
** Service ID           : 0x0A
**
** Description          : This service provides the actual status of the
**                        microcontroller RAM area
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Mcu_RamStateType
**                        (MCU_RAMSTATE_INVALID, MCU_RAMSTATE_VALID)
**
** Preconditions        : MCU Driver component must be initialized
**
** Global Variables     : Mcu_GblDriverStatus, Mcu_GblRAMInitStatus
**
** Functions Invoked    : Det_ReportError, MCU_ENTER_CRITICAL_SECTION,
**                        MCU_EXIT_CRITICAL_SECTION
**
** Registers Used       : None
*******************************************************************************/

/* Implements MCU_ESDD_UD_056 */
/* Implements EAAR_PN0079_FR_0070*/
#if (MCU_GET_RAM_STATE_API == STD_ON)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_010, MCU_ESDD_UD_097 */
/* Implements EAAR_PN0079_FR_0071, MCU207, MCU208, MCU209, MCU125 */
/* Implements MCU166_Conf, MCU181_Conf, EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0013, MCU017, EAAR_PN0034_FR_0013, MCU181_Conf */
/* Implements EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0030 */

FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState (void)
{
  VAR(Mcu_RamStateType, AUTOMATIC) LddRamStatus;

  LddRamStatus = MCU_RAMSTATE_INVALID;
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                        MCU_GETRAMSTATE_SID, MCU_E_UNINIT);
  }
  /* if no development error occurred */
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* START Msg(2:4342)-7  */
    /* Store the current variable value to the return value */
    LddRamStatus = (Mcu_RamStateType) Mcu_GblRAMInitStatus;
    /* END Msg(2:4342)-7  */

    /* Clear the global variable status to default state */
    Mcu_GblRAMInitStatus = (boolean) MCU_RAMSTATE_VALID;

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_VARIABLE_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }

  return (LddRamStatus);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */


/*******************************************************************************
** Function Name        : Mcu_GetVersionInfo
**
** Service ID           : 0x09
**
** Description          : This service returns the version information of this
**                        module.
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : Std_VersionInfoType* versioninfo
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables     : None
**
** Functions Invoked    : Det_ReportError,
**
** Registers Used       : None
*******************************************************************************/

/* Implements MCU_ESDD_UD_053 */
#if (MCU_VERSION_INFO_API == STD_ON)
/* MISRA Violation: START Msg(4:3458)-1 */
/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* START Msg(2:3227)-1 */
/* Implements MCU_ESDD_UD_043 */
/* Implements MCU103, MCU104, MCU162, MCU125 */
/* Implements MCU204, MCU166_Conf, MCU168_Conf, MCU125, MCU017, MCU149 */
/* Implements EAAR_PN0034_FR_0051, EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0064 */

FUNC(void, MCU_PUBLIC_CODE) Mcu_GetVersionInfo
          (P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) versioninfo)
/* END Msg(2:3227)-1 */
{

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (NULL_PTR == versioninfo)
  {
    /* Implements MCU_ESDD_UD_051 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                              MCU_GETVERSIONINFO_SID, MCU_E_PARAM_POINTER);
  }
  else
  #endif
  {
    /* START Msg(2:2814)-2 */
    (versioninfo)->vendorID = (uint16)MCU_VENDOR_ID;
    (versioninfo)->moduleID = (uint16)MCU_MODULE_ID;
    (versioninfo)->sw_major_version = MCU_SW_MAJOR_VERSION;
    (versioninfo)->sw_minor_version = MCU_SW_MINOR_VERSION;
    (versioninfo)->sw_patch_version = MCU_SW_PATCH_VERSION;
    /* END Msg(2:2814)-2 */
  }
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/* END Msg(4:3458)-1 */
#endif /* (MCU_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
** Function Name        : Mcu_EcmReleaseErrorOutPin
**
** Service ID           : 0x0B
**
** Description          : This service will release the errorout pin
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : None
**
** Preconditions        : MCU Driver component must be initialized
**
** Global Variables     : Mcu_GblDriverStatus,
**
** Functions Invoked    : Det_ReportError, Mcu_ClearEcmErrorOutput
**
** Registers Used       : None
*******************************************************************************/
/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_018 */
/* Implements EAAR_PN0079_FSR_0043, MCU166_Conf, MCU017, MCU125, MCU208 */
/* Implements EAAR_PN0034_FR_0064 */

FUNC(void, MCU_PUBLIC_CODE) Mcu_EcmReleaseErrorOutPin(void)
{

  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Implements MCU_ESDD_UD_049 */
    /* Report to DET */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                   MCU_RELEASEERROROUTPIN_SID, MCU_E_UNINIT);
  }
  else
  #endif
  {
    /* Call the function to release pin ERROROUT*/
    (void)Mcu_ClearEcmErrorOutput(MCU_RELEASEERROROUTPIN_SID);

  }

}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"



/*******************************************************************************
** Function Name      : Mcu_HWInit
**
** Service ID         : None
**
** Description        : This service performs initialization of the MCU Driver
**                      component.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GpEcmSetting, Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_StartUPTest, Mcu_EcmErrorInitialNotification
**                      Mcu_SaveResetReason, Mcu_LockStepSelfDiagnosticTest,
**                      Mcu_EcmSelfDiagnosticTest, Mcu_CvmSelfDiagnosticTest,
**                      Mcu_ConfigureLvi, Mcu_ConfigureEcm,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION,
**                      Mcu_ConfigureEcmRamErrors, Mcu_ClearEcmErrorOutput,
**                      MCU_PROTECTEDWRITE, Det_ReportError
**
** Registers Used     : ECMIRCFG0, ECMPCMD1, ECMPS, ECMEPCTL
*******************************************************************************/
/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements MCU116, MCU245, EAAR_PN0079_FSR_0034, EAAR_PN0079_FSR_0101 */
/* Implements EAAR_PN0034_FR_0018, EAAR_PN0034_NR_0020 */

/* Implements MCU_ESDD_UD_039 */
/* START Msg(0:2755)-11 */
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_HWInit(void)
/* END Msg(0:2755)-11 */
{
  /* START Msg(2:3204)-4 */
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue1;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue2;
  /* END Msg(2:3204)-4 */
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  /* Initialize to default values */
  LenReturnValue = E_OK;
  LenReturnValue1= E_OK;
  LenReturnValue2 = E_OK;
  /* Initialize the index value */
  LucIndex = MCU_ZERO;


  /* Implements MCU_ESDD_UD_105 */
  /* MISRA Violation: START Msg(4:0316)-1 */
  /* Load the Ecm config array start address to global pointer */
  Mcu_GpEcmSetting =
  (P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST))
                                            (Mcu_GpConfigPtr->pEcmSetting);
  /* END Msg(4:0316)-1 */
  /* Implements MCU_ESDD_UD_081 */
  #if ((MCU_SW_STARTUP_TEST == STD_ON) || (MCU_ECM_STARTUP_TEST == STD_ON))
  /* MISRA Violation: START Msg(4:0303)-2 */
  if (MCU_POF_RST == MCU_POF)
  {
    /* END Msg(4:0303)-2 */
    /* To test the SW reset and ECM reset*/
    LenReturnValue = Mcu_StartUPTest();
  }
  else
  {

  }
  if (E_OK == LenReturnValue)
  #endif
  {
    /* Initialize wait count value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_PROTECTEDWRITE (MCU_ECMIRCFG0, MCU_IRCFG0_INIT_VALUE, MCU_ECMPCMD1,
    MCU_ECMPS, LucRetryCount, LenReturnValue)

    MCU_REG_WRITE_VERIFY_INIT(MCU_ECMIRCFG0, MCU_IRCFG0_INIT_VALUE,
    MCU_FULL_MASK, MCU_INIT_SID)
    /* END Msg(4:0303)-2 */
    /* Save the reset reason from  hardware registers */
    Mcu_SaveResetReason();
  }
  /* Implements MCU_ESDD_UD_081 */
  #if ((MCU_SW_STARTUP_TEST == STD_ON) || (MCU_ECM_STARTUP_TEST == STD_ON))
  else
  {
    /* No action required */
  }
  #endif

  if (E_OK == LenReturnValue)
  {
    /* Configure LVI */
    LenReturnValue = Mcu_ConfigureLvi();
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* Set Ecm Error output pin as inactive level initially */
    Mcu_EcmErrorInitialNotification();
    /* Clear ECm error status */
    (void)Mcu_ClearEcmErrorOutput(MCU_INIT_SID);
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* Implements MCU_ESDD_UD_064 */
    #if (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON)
    /* Self diagnostic test of lock step unit */
    LenReturnValue = Mcu_LockStepSelfDiagnosticTest();
    #endif /* (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON) */

    /* Implements MCU_ESDD_UD_061 */
    #if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)
    /* Self diagnostic test of Ecm unit */
    LenReturnValue1 = Mcu_EcmSelfDiagnosticTest();
    #endif /* (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON) */

    /* Implements MCU_ESDD_UD_060 */
    #if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)
    /* MISRA Violation: START Msg(4:1881)-12 */
    if (Mcu_GulLastResetReasonStatus == MCU_POWER_ON_RESET)
    {
      /* END Msg(4:1881)-12 */
      /* Self diagnostic test of Cvm unit */
      LenReturnValue2 = Mcu_CvmSelfDiagnosticTest();
    }
    else
    #endif /* (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON) */
    {
      /* No action required */
    }
    if (E_OK == LenReturnValue2)
    {
      /* Configure Cvm unit */
      LenReturnValue2 = Mcu_ConfigureCvm();
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

  /* Check whether Dem reported or not */
  if ((E_OK == LenReturnValue) && (E_OK == LenReturnValue1) &&
                                                  (E_OK == LenReturnValue2))
  {
    /* If Dynamic mode selected, set the timer as OSTM or
    * Channel 15 TAUD1 as per configuration.
    */
    /* Implements MCU_ESDD_UD_068 */
    LucIndex = MCU_ECM_ERROUT_MODE;
    if (MCU_ONE == LucIndex)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Implements MCU_ESDD_UD_069 */
      /* Load the Error out timer value to the register. */
      MCU_ECMEPCTL = MCU_ECM_ERROUT_TIMER;
      /* START Msg(2:3892)-5 */
      MCU_REG_WRITE_VERIFY_INIT(MCU_ECMEPCTL, MCU_ECM_ERROUT_TIMER,
      MCU_8BIT_MASK, MCU_INIT_SID)
      /* END Msg(2:3892)-5 */
      /* END Msg(4:0303)-2 */
    }
    else
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Load the Error out default timer value to the register. */
      MCU_ECMEPCTL = MCU_ZERO;
      /* START Msg(2:3892)-5 */
      MCU_REG_WRITE_VERIFY_INIT(MCU_ECMEPCTL, MCU_ZERO,MCU_8BIT_MASK,
      MCU_INIT_SID)
      /* END Msg(2:3892)-5 */
      /* END Msg(4:0303)-2 */
    }

    /* Configure ECM unit */
    LenReturnValue = Mcu_ConfigureEcm();

    if (E_OK == LenReturnValue)
    {
      #if (MCU_RAM_SECTOR_SETTING_CONFIGURED == STD_OFF)
      LenReturnValue = Mcu_ConfigureEcmRamErrors();
      #endif
      /* Implements MCU_ESDD_UD_090 */
      /* Set the Global Status */
      Mcu_GblDriverStatus = MCU_INITIALIZED;
    } /* End of (MCU_FALSE == LblDemReported) */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }
}
/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/*******************************************************************************
** Function Name      : Mcu_ConfigureCvm
**
** Service ID         : None
**
** Description        : This service configure Cvm of Mcu Module
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : MCU_PROTECTEDWRITE, MCU_REG_WRITE_VERIFY
**
** Registers Used     : CVMREN, PROTCMDCVM, PROTSCVM,
CVMDEW, CVMDE, CVMFC, CVMF
*******************************************************************************/
/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0079_FSR_0103, MCU152, EAAR_PN0034_FSR_0011 */
/* Implements EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0004*/
/* Implements EAAR_PN0079_FSR_0023, EAAR_PN0079_FSR_0024 */
/* Implements EAAR_PN0079_FSR_0072, EAAR_PN0079_FR_0077, MCU186_Conf */
/* Implements EAAR_PN0034_FR_0018, EAAR_PN0034_FSR_0012, EAAR_PN0079_FSR_0074 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_NR_0020, EAAR_PN0079_FSR_0114 */
/* Implements EAAR_PN0079_FSR_0115, EAAR_PN0079_FSR_0117 */
/* Implements MCU_ESDD_UD_032 */
STATIC FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_ConfigureCvm(void)
{
  VAR(uint32, AUTOMATIC) LulCntValue;
  VAR(uint16, AUTOMATIC) LusLoopCount;
  VAR(uint8, AUTOMATIC) LucCVMCntValue;
  #if(MCU_WV_DISABLE != MCU_WRITE_VERIFY )
  VAR(uint8, AUTOMATIC) LucCVMCntValueWV;
  #endif
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucCVMFCData;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;

  /* Initialize to default values */
  LenReturnValue = E_OK;
  /* MISRA Violation: START Msg(4:1881)-12 */
  if (Mcu_GulLastResetReasonStatus == MCU_POWER_ON_RESET)
  {
    /* END Msg(4:1881)-12 */
    /* Get the configured CVM control value  */
    /* START Msg(2:2814)-2 */
    LucCVMCntValue = Mcu_GpConfigPtr->ucCvmIndicationReg;
    /* END Msg(2:2814)-2  */

    /* Implements MCU_ESDD_UD_071 */
    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3892)-5 */
    MCU_PROTECTEDWRITERETNONE(MCU_CVMDEW, LucCVMCntValue, MCU_PROTCMDCVM,
    MCU_PROTSCVM, LucRetryCount)
    /* END Msg(2:3892)-5 */
    /* END Msg(4:0303)-2 */
    /* Implements MCU_ESDD_UD_062 */
    /* START Msg(2:3416)-8  */
    /* MISRA Violation: START Msg(4:0303)-2 */
    #if(MCU_WV_DISABLE != MCU_WRITE_VERIFY )
    LucCVMCntValueWV = MCU_ZERO;
    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:2986)-13 */
    LucCVMCntValueWV |= (uint8)((LucCVMCntValue & MCU_FOUR) << MCU_TWO);
    LucCVMCntValueWV |= (uint8)((LucCVMCntValue & MCU_TWENTYFOUR) >> MCU_ONE);
    /* END Msg(4:2986)-13 */
    /* END Msg(2:3892)-5 */
    #endif
    MCU_REG_WRITE_VERIFY_INIT(MCU_CVMDE, LucCVMCntValueWV, MCU_CVMDE_WV_MASK,
    MCU_INIT_SID)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3416)-8  */
    /*To verify Self Diag locking functionality */
    #if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)
    /* START Msg(2:3892)-5 */
    if ((LucCVMCntValue & MCU_CVM_DIAG_LOCK_MASK) == MCU_CVM_DIAG_LOCK_MASK)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_PROTECTEDWRITERETNONE(MCU_CVMDEW, MCU_ZERO, MCU_PROTCMDCVM,
      MCU_PROTSCVM, LucRetryCount)
      if ((MCU_CVMDE & MCU_FOUR) != MCU_FOUR)
      {
        /* END Msg(2:3892)-5 */
        /* END Msg(4:0303)-2 */
        Dem_ReportErrorStatus(MCU_E_CVM_SELFDIAG_FAILURE,
        DEM_EVENT_STATUS_FAILED);
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
  }
  else
  {
    /* No action required */
  }

  /* Get the configured CVM reset enable control value  */
  LulCntValue = Mcu_GpConfigPtr->ulCvmResetEnableReg;
  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* MISRA Violation: START Msg(4:0303)-2 */
  /* START Msg(2:3892)-5 */
  MCU_PROTECTEDWRITERETNONE(MCU_CVMREN, LulCntValue, MCU_PROTCMDCVM,
  MCU_PROTSCVM, LucRetryCount)
  /* END Msg(2:3892)-5 */
  /* END Msg(4:0303)-2 */

  /* Initialize the loop count value */
  LusLoopCount = MCU_CVM_DELAY_CNT;
  /* Wait for idle time after shifting to normal mode*/
  do
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_ZERO != MCU_CVMF)
    /* END Msg(4:0303)-2 */
    {
      /* Initialize the loop count value */
      LucRetryCount = MCU_LOOPCOUNT;

      LucCVMFCData = MCU_CVM_FACTOR_CLEAR;

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Write the value to the CVM factor clear register  */
      MCU_PROTECTEDWRITE(MCU_CVMFC, LucCVMFCData, MCU_PROTCMDCVM,
      MCU_PROTSCVM, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5  */
    }
    else
    {
      /* No action required */
    }

    LusLoopCount--;
    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
  } while ((MCU_ZERO != MCU_CVMF) && (LusLoopCount > MCU_ZERO));
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3892)-5 */
  /* Implements MCU_ESDD_UD_062 */
  /* START Msg(2:3416)-8  */
  /* START Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_INIT(MCU_CVMF, MCU_ZERO, MCU_8BIT_MASK, MCU_INIT_SID)
  /* END Msg(2:3892)-5 */
  /* END Msg(4:0303)-2  */
  /* END Msg(2:3416)-8  */
  return LenReturnValue;
}
/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_CvmSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check CVM self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : MCU_PROTECTEDWRITE, Mcu_CvmSelfDiagnosticSetting
**
** Registers Used     : CVMDMASK, PROTCMDCVM, PROTSCVM,CVMFC, CVMF
******************************************************************************/
/* Implements MCU_ESDD_UD_060 */
/* Implements EAAR_PN0079_FSR_0080, MCU152, EAAR_PN0034_FSR_0011 */
/* Implements EAAR_PN0079_FSR_0079, EAAR_PN0079_FSR_0073, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FSR_0012, EAAR_PN0034_NR_0020,  */

#if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_014 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmSelfDiagnosticTest (void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint16, AUTOMATIC) LusLoopCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucCVMFCData;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* START Msg(2:3892)-5 */
  /* START Msg(2:2814)-2 */
  /* Check if CVM output mask is configured */
  if (MCU_CVM_DIAG_MASK == (Mcu_GpConfigPtr->ucCvmDiagMask))
  /* END Msg(2:2814)-2  */
  /* END Msg(2:3892)-5 */
  {
    /* Implements MCU_ESDD_UD_071 */
    /* START Msg(2:3892)-5 */
    /* Initialize the loop count value */
    LucRetryCount = MCU_LOOPCOUNT;
    /* END Msg(2:3892)-5 */

    /* LucCVMFStatus = MCU_CVM_MASK_ERROR_CHECK; */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3892)-5 */
    /* Mask CVMOUT output in self diagnosis mode */
    MCU_PROTECTEDWRITE(MCU_CVMDMASK, MCU_ONE, MCU_PROTCMDCVM, MCU_PROTSCVM,
    LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* Implements MCU_ESDD_UD_062 */
    /* START Msg(2:3416)-8  */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_CVMDMASK, MCU_ONE, MCU_CVM_DIAG_MASK,
    MCU_INIT_SID)
    /* END Msg(4:0303)-2  */
    /* END Msg(2:3416)-8  */
    /* END Msg(2:3892)-5  */
  }
  else
  {
    /* No action required */
  }

  /* START Msg(2:3892)-5 */
  /* Initialize the loop count value */
  LusLoopCount = MCU_LOOPCOUNT;
  /* END Msg(2:3892)-5 */

  /* Clear all the error flags before starting the self diagnostic testing */
  do
    {
    /* MISRA Violation: START Msg(4:0303)-2 */
    if ((MCU_CVMF != MCU_ZERO) && (E_OK == LenReturnValue))
    /* END Msg(4:0303)-2 */
    {
      /* Initialize the loop count value */
      LucRetryCount = MCU_LOOPCOUNT;

      LucCVMFCData = MCU_CVM_FACTOR_CLEAR;

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Write the value to the CVM factor clear register  */
      MCU_PROTECTEDWRITE(MCU_CVMFC, LucCVMFCData, MCU_PROTCMDCVM,
      MCU_PROTSCVM, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5  */
    }
    else
    {
      /* No action required */
    }

    LusLoopCount--;
    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
  } while ((MCU_ZERO != MCU_CVMF) && (LusLoopCount > MCU_ZERO));
  /* END Msg(4:0303)-2 */
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_INIT(MCU_CVMF, MCU_ZERO, MCU_8BIT_MASK, MCU_INIT_SID)
  /* END Msg(4:0303)-2  */
  /* END Msg(2:3416)-8  */
  /* END Msg(2:3892)-5  */
  /* Generate CVM low and high voltage error condition using DIAG registers
  * and check the status registers accordingly
  */
  if (E_OK == LenReturnValue)
  {
    /* Setting Cvm Self Diagonistic related registers  */
    LenReturnValue = Mcu_CvmSelfDiagnosticSetting();
  }
  else
  {
    /* No action required */
  }

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON) */


/******************************************************************************
** Function Name      : Mcu_CvmSelfDiagnosticSetting
**
** Service ID         : None
**
** Description        : This service is to set CVM self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : Dem_ReportErrorStatus, MCU_PROTECTEDWRITE,
**                      Mcu_CvmNormalModeSetting
**
** Registers Used     : CVMDIAG, PROTCMDCVM, PROTSCVM, CVMF
******************************************************************************/
/* Implements MCU_ESDD_UD_060 */
#if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements MCU152,EAAR_PN0034_FSR_0011, MCU017, MCU166 */
/* Implements EAAR_PN0079_FSR_0116 */
/* Implements EAAR_PN0034_FR_0018, EAAR_PN0034_FSR_0012, EAAR_PN0034_NR_0020 */
/* Implements MCU_ESDD_UD_035 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmSelfDiagnosticSetting(void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint16, AUTOMATIC) LusLoopCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  /* Initialize the return value */
  /* MISRA Violation: START Msg(4:2982)-5 */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */

  /* Implements MCU_ESDD_UD_071 */
  /* Initialize the loop count value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* START Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Write the value to shift to diagnosis mode */
  /* Implements MCU_ESDD_UD_083 */
  MCU_PROTECTEDWRITE(MCU_CVMDIAG, MCU_TWELVE, MCU_PROTCMDCVM,
  MCU_PROTSCVM, LucRetryCount, LenReturnValue)
  /* END Msg(4:0303)-2 */
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_INIT(MCU_CVMDIAG, MCU_TWELVE, MCU_8BIT_MASK,MCU_INIT_SID)
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3416)-8  */
  /* END Msg(2:3892)-5 */
  /* Check whether Dem reported or not */
  if (E_OK == LenReturnValue)
  {
    LusLoopCount = MCU_CVM_DELAY_CNT;

    /* check error status register until idle wait time 12 us
    */
    do
    {
      ASM_NOP();

      LusLoopCount--;

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
    }while ((MCU_CVMF != MCU_CVM_MASK_ERROR_CHECK) &&
                                                  (MCU_ZERO < LusLoopCount));
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3892)-5 */
    /* Check the status of CVM Error in Factor register  */
    if ((MCU_CVMF & MCU_CVM_MASK_ERROR_CHECK) != MCU_CVM_MASK_ERROR_CHECK)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */
    {
      /* Self Diagnostic test for CVM is failed.*/
      /* Implements MCU_ESDD_UD_084 */
      Dem_ReportErrorStatus(MCU_E_CVM_SELFDIAG_FAILURE,
      DEM_EVENT_STATUS_FAILED);

      /* Set LenReturnValue to E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* Initialize the loop count value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:2982)-5 */
      /* Write the value to shift to normal mode */
      MCU_PROTECTEDWRITE(MCU_CVMDIAG, MCU_ZERO, MCU_PROTCMDCVM,
      MCU_PROTSCVM, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(4:2982)-5 */
      /* START Msg(2:3416)-8  */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_INIT(MCU_CVMDIAG, MCU_ZERO, MCU_8BIT_MASK,
      MCU_INIT_SID)
      /* END Msg(4:0303)-2  */
      /* END Msg(2:3416)-8  */
      /* END Msg(2:3892)-5  */
      LenReturnValue = Mcu_CvmNormalModeSetting();
    }
  }
  else
  {
    /* No action required */
  }

  return LenReturnValue;
}
/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON) */


/******************************************************************************
** Function Name      : Mcu_ClmaSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check CLMA self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, MCU_PROTECTEDWRITE
**
** Registers Used     : CLMATESTS, CLMATEST, PROT1PHCMD, PROT1PS
******************************************************************************/
/* Implements MCU_ESDD_UD_063 */
#if (MCU_CLMA_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_012 */
/* Implements MCU_ESDD_UD_108 */
/* Implements MCU_ESDD_UD_099 */
/* Implements MCU152, EAAR_PN0079_FSR_0081, EAAR_PN0079_FSR_0082, MCU166 */
/* Implements EAAR_PN0034_FR_0018, EAAR_PN0034_NR_0020, EAAR_PN0079_FSR_0123 */
/* START Msg(2:3227)-1 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClmaSelfDiagnosticTest
(P2CONST(Mcu_ClockMonitorConf, AUTOMATIC, MCU_CONFIG_CONST)
                                                            LpClmaConfigPtr)
/* END Msg(2:3227)-1*/
{
  /* Implements MCU_ESDD_UD_109 */
  P2VAR(Mcu_ClmaRegisters, AUTOMATIC, MCU_CONFIG_CONST)
  LpClmaRegBaseAddress;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC)LulClmaXTestValue;
  VAR(uint8, AUTOMATIC) LucClmaDiagIndex;
  VAR(uint32, AUTOMATIC) LulClmaCount;
  VAR(Mcu_ClmaIndexType, AUTOMATIC)LenClmaXIndex;
  VAR(uint8, AUTOMATIC)LucRetryCount;
  VAR(boolean, AUTOMATIC) LblDemReported;
  VAR(uint8, AUTOMATIC) LucRegisterValueU8;
  /* Initialize Clock monitor index */
  LucClmaDiagIndex = MCU_ZERO;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  LblDemReported = MCU_FALSE;

  LulClmaXTestValue = (uint32)MCU_ZERO;
  /* START Msg(2:2814)-2 */
  LenClmaXIndex = LpClmaConfigPtr->enClmaIdx;
  /* END Msg(2:2814)-2 */
  LpClmaRegBaseAddress = LpClmaConfigPtr->pClmaRegBaseAddress;
  /* START Msg(2:2814)-2 */
  LucRegisterValueU8 = LpClmaRegBaseAddress->ucCLMAnCTL0;
  /* END Msg(2:2814)-2 */
  do
  {
    switch (LucClmaDiagIndex)
    {
    case MCU_ZERO:
      /* START Msg(2:3892)-5 */
      if ((LucRegisterValueU8 & MCU_ONE) == MCU_ZERO)
      {
        /* Set the Higher threshold value for frequency limit to zero in
        * the compare register to generate error
        */
        LpClmaRegBaseAddress->usCLMAnCMPH = MCU_ZERO;
        MCU_REG_WRITE_VERIFY_RUNTIME(LpClmaRegBaseAddress->usCLMAnCMPH,
        MCU_ZERO, MCU_16BIT_MASK, MCU_INITCLOCK_SID)
        /* END Msg(2:3892)-5 */
        /* Update return variable as E_OK */
        LenReturnValue = E_OK;
      }
      else
      {

      }
      /* Set the value to enable the Self testing for CLMAn and mask the error
      * notification to ECM.
      */
      /* START Msg(2:3892)-5 */
      LulClmaXTestValue = ((CLMA_SELF_TEST_VALUE << LenClmaXIndex) | MCU_FOUR);
      /* END Msg(2:3892)-5 */
    break;

    case MCU_ONE:
      /* Check the clock monitor status bit for error detection */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* START Msg(2:3892)-5 */
      if (((uint8)MCU_CLMATESTS & (uint8)(MCU_ONE << LenClmaXIndex)) ==
      MCU_ZERO)
      /* END Msg(4:0303)-2 */
      {
        LulClmaXTestValue = (LulClmaXTestValue | MCU_FOUR);
        /* END Msg(2:3892)-5 */
      }
      else
      {
        LenReturnValue = E_NOT_OK;
      }
    break;

    case MCU_TWO:
      /* Implements MCU_ESDD_UD_071 */
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;
      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:4464)-4 */
      /* Write data to protected CLMA0 control register */
      /* Implements MCU_ESDD_UD_083 */
      MCU_PROTECTEDWRITE(LpClmaRegBaseAddress->ucCLMAnCTL0,
      MCU_ONE, LpClmaRegBaseAddress->ucCLMAnPCMD,
      LpClmaRegBaseAddress->ucCLMAnPS, LucRetryCount,
      LenReturnValue)
      /* END Msg(4:4464)-4 */
      /* START Msg(2:3416)-8  */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_RUNTIME(LpClmaRegBaseAddress->ucCLMAnCTL0, MCU_ONE,
      MCU_CLMACTL_WV_MASK, MCU_INITCLOCK_SID)
      /* END Msg(4:0303)-2  */
      /* END Msg(2:3416)-8  */
      /* END Msg(2:3892)-5  */
      /* maximum wait delay count value */
      LulClmaCount = LpClmaConfigPtr->ulClmaDelayCount;

      /* wait for sampling cycles to set corresponding error status */
      do
      {
        LulClmaCount--;
        /* START Msg(2:3892)-5 */
        /* MISRA Violation: START Msg(4:0303)-2 */
      }while ((((uint8)MCU_CLMATESTS & (uint8)(MCU_ONE << LenClmaXIndex)) !=
      (uint8)(MCU_ONE << LenClmaXIndex)) && (LulClmaCount > MCU_ZERO));
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Check the clock monitor status bit for error detection */
      if (((uint8)MCU_CLMATESTS & (uint8)(MCU_ONE << LenClmaXIndex))
      != (uint8)(MCU_ONE << LenClmaXIndex))
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */
      {
        /* Self Diagnostic test for CLMA is failed.*/
        /* Implements MCU_ESDD_UD_086 */
        Dem_ReportErrorStatus(MCU_E_CLM_SELFDIAG_FAILURE,
        DEM_EVENT_STATUS_FAILED);

        /* Set the flag to true value */
        LblDemReported = MCU_TRUE;
      }
      else
      {
        /* No action required */
      }

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Set the value to clear the error generated by self-diagnosis */
      LulClmaXTestValue = (MCU_CLMATEST | MCU_ONE);
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */
    break;

    case MCU_THREE:
      /* START Msg(2:3892)-5 */
      /*Set the value to terminate self-diagnosis by writing zero */
      LulClmaXTestValue = MCU_ZERO;
      /* END Msg(2:3892)-5 */
    break;
      /* Start: MCU_UT_002 */
      /* START Msg(2:2881)-9  */
    default:
      /* END Msg(2:2881)-9  */
      /* Set the value so that it exits the loop */
      LucClmaDiagIndex = MCU_FOUR;
    break;
      /* End: MCU_UT_002 */
    }
    if (LenReturnValue == E_OK)
    {
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_PROTECTEDWRITE(MCU_CLMATEST, LulClmaXTestValue, MCU_PROT1PHCMD,
      MCU_PROT1PS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */
      /* START Msg(2:3416)-8  */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_RUNTIME(MCU_CLMATEST, LulClmaXTestValue,
      MCU_FULL_MASK, MCU_INITCLOCK_SID)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3416)-8  */
      /* Increase the index */
      LucClmaDiagIndex++;
    }
    else
    {
      /* No action required */
    }
  } while ((LucClmaDiagIndex < MCU_FOUR) && (E_OK == LenReturnValue));

  /* Check self test failed */
  if (MCU_TRUE == LblDemReported)
  {
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_CLMA_SELFDIAGNOSTIC_TEST == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_EcmSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check Ecm self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_PROTECTEDWRITE,
**                      Mcu_EcmSelfDiagnosticFirstTest,
**                      Mcu_EcmSelfDiagnosticSecondTest
**
** Registers Used     : ECMEMK0, ECMEMK1, ECMPCMD1, ECMPS
******************************************************************************/
/* Implements MCU_ESDD_UD_061 */
#if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_013 */
/* Implements MCU152, EAAR_PN0079_FSR_0083, EAAR_PN0079_FSR_0084 */
/* Implements EAAR_PN0034_FR_0018, EAAR_PN0034_NR_0020 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticTest (void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  /* Implements MCU_ESDD_UD_071 */
  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* MISRA Violation: START Msg(4:2982)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Disable Error Output by setting the ECMIE029 bit of the
  * ECMEMK0 register to disabled.
  */
  MCU_PROTECTEDWRITE(MCU_ECMEMK0, MCU_ECMEMK0_FULL_MASK,
  MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
  /* END Msg(4:0303)-2 */
  /* END Msg(4:2982)-5 */
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_INIT(MCU_ECMEMK0, MCU_ECMEMK0_FULL_MASK, MCU_FULL_MASK,
  MCU_INIT_SID)
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3416)-8  */
  if (E_OK == LenReturnValue)
  {
    /* MISRA Violation: START Msg(4:2982)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_PROTECTEDWRITE(MCU_ECMEMK1, MCU_ECMEMK1_FULL_MASK,
    MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* END Msg(4:2982)-5 */
    /* START Msg(2:3416)-8  */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_ECMEMK1, MCU_ECMEMK1_FULL_MASK, MCU_FULL_MASK,
    MCU_INIT_SID)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3416)-8  */
    if (E_OK == LenReturnValue)
    {
      /* Check diagnostic test on each ECM error source (0-31)*/
      LenReturnValue = Mcu_EcmSelfDiagnosticFirstTest();

      /* Check whether Dem reported or not */
      if (E_OK == LenReturnValue)
      {
        /* Check diagnostic test on each ECM error source (32-63)*/
        LenReturnValue = Mcu_EcmSelfDiagnosticSecondTest();
      }
      else
      {
        /* No action required */
      }
    }
    /* Start: MCU_UT_003 */
    else
    {
      /* No action required */
    }
    /* End: MCU_UT_003 */
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON) */



/******************************************************************************
** Function Name      : Mcu_EcmSelfDiagnosticFirstTest
**
** Service ID         : None
**
** Description        : This service is used to test the ECM self diagnostic
**                      for first set of error sources.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_ClearEcmErrorOutput
**
** Registers Used     : ECMEMK0, ECMPCMD1, ECMPS, ECMMESSTR0, ECMMESSTR1,
**                      ECMESSTC0, ECMPE0, ECMCESSTR0
**
******************************************************************************/

/* Implements MCU_ESDD_UD_061 */
#if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements MCU152, MCU017, MCU166, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0081*/
/* Implements EAAR_PN0034_NR_0020, EAAR_PN0079_FSR_0122 */
/* Implements MCU_ESDD_UD_037 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticFirstTest
                                                                      (void)
{
  P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST) LpEcmSetting;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulEcmPseudoData;
  /* START Msg(2:3204)-4 */
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  /* END Msg(2:3204)-4 */
  VAR(uint8, AUTOMATIC) LucEcmDiagCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  /* MISRA Violation: START Msg(4:0317)-7 */
  /* START Msg(2:2814)-2 */
  LpEcmSetting = Mcu_GpConfigPtr->pEcmSetting;
  /* END Msg(2:2814)-2 */
  /* END Msg(4:0317)-7 */
  LenReturnValue = E_OK;
  /* START Msg(2:3892)-5 */

  /* Perform Ecm diagnostic test on register 0 */
  /* load ECM pseudo error trigger register 0 address */
  LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMPE0_OFFSET;
  /* END Msg(2:3892)-5 */

  /* Check diagnostic test on each ECM error source */

  for (LucEcmDiagCount = MCU_ZERO;
  (LucEcmDiagCount < MCU_THIRTYTWO) && (E_OK == LenReturnValue);
  LucEcmDiagCount++)
  {
    /* Skip unused bits in the config reg */
    if ((MCU_TWO != LucEcmDiagCount) && (MCU_THREE != LucEcmDiagCount)
    && (MCU_THIRTEEN != LucEcmDiagCount) && (MCU_TWENTYFIVE != LucEcmDiagCount))
    {
      /* Write the value for generating the ECM error */
      LulEcmPseudoData = ((uint32)MCU_ONE << LucEcmDiagCount);

      /* START Msg(2:2814)-2 */
      if ((uint32)MCU_ZERO !=
      (LulEcmPseudoData & LpEcmSetting->ulEcmMaskInterReg0value))
      /* END Msg(2:2814)-2 */
      {
        if (MCU_TWENTYNINE == LucEcmDiagCount)
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;
          /* MISRA Violation: START Msg(4:2982)-5 */
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Unmask the ERROROUT bit for ECM error source 29 */
          MCU_PROTECTEDWRITE(MCU_ECMEMK0,
          (MCU_ECMEMK0 & (~MCU_ECM029_MASK_VALUE)),
          MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */
          /* END Msg(4:2982)-5 */
          /* START Msg(2:3416)-8 */
          /* MISRA Violation: START Msg(4:0303)-2 */
          MCU_REG_WRITE_VERIFY_INIT(MCU_ECMEMK0,
          (MCU_ECMEMK0 & (~MCU_ECM029_MASK_VALUE)), MCU_FULL_MASK, MCU_INIT_SID)
          /* END Msg(4:0303)-2 */
          /* END Msg(2:3416)-8  */
        }
        else
        {
          /* No action required */
        }

        /* Initialize the retry count to config value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Generate the error using ECMPE0 register */
        MCU_PROTECTEDWRITE(*(volatile uint32 *)LulEcmConfigAddress,
        LulEcmPseudoData, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount,
        LenReturnValue)
        /* END Msg(4:0303)-2 */

        /* Check whether Dem reported or not */
        if (E_OK == LenReturnValue)
        {
          /* START Msg(2:3892)-5 */
          /* MISRA Violation: START Msg(4:0303)-2 */
          if ((MCU_ZERO != (MCU_ECMMESSTR0 & LulEcmPseudoData)) &&
          (MCU_ZERO != (MCU_ECMCESSTR0 & LulEcmPseudoData)) )
          /* END Msg(4:0303)-2 */
          /* END Msg(2:3892)-5 */
          {
            /* START Msg(2:3892)-5 */
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Check error out put status as low
            * MCU_ERROROUT_STATUS = 0x80000000
            */
            if ((MCU_TWENTYNINE == LucEcmDiagCount) &&
            ( MCU_ZERO ==(MCU_ECMMESSTR1 & MCU_ERROROUT_STATUS)))
            /* END Msg(4:0303)-2 */
            /* END Msg(2:3892)-5 */
            {
              LenReturnValue = Mcu_ClearEcmErrorOutput(MCU_INIT_SID);
            }
            else if (MCU_TWENTYNINE != LucEcmDiagCount)
            {
              /* Initialize the retry count to config value */
              LucRetryCount = MCU_LOOPCOUNT;

              /* MISRA Violation: START Msg(4:0303)-2 */
              /* write the value to ECMESSTC0 register */
              MCU_PROTECTEDWRITE(MCU_ECMESSTC0, LulEcmPseudoData,
                      MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
              /* END Msg(4:0303)-2 */
            }
            else
            {
              /* Self Diagnostic test for ECM is failed.*/
              Dem_ReportErrorStatus(MCU_E_ECM_SELFDIAG_FAILURE,
                                                    DEM_EVENT_STATUS_FAILED);

              /* Set LenReturnValue to E_NOT_OK */
              LenReturnValue = E_NOT_OK;
            }
          }
          else
          {
            /* Self Diagnostic test for ECM is failed.*/
            Dem_ReportErrorStatus(MCU_E_ECM_SELFDIAG_FAILURE,
            DEM_EVENT_STATUS_FAILED);

            /* Set LenReturnValue to E_NOT_OK */
            LenReturnValue = E_NOT_OK;

          }
        } /* End of (E_OK == LenReturnValue) */
        else
        {
        /* No action required */
        }
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
  }
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_INIT(MCU_ECMMESSTR0,(uint32)MCU_ZERO, MCU_FULL_MASK,
  MCU_INIT_SID)
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3416)-8  */
  return LenReturnValue;

}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* MCU_ECM_SELFDIAGNOSTIC_TEST */


/******************************************************************************
** Function Name      : Mcu_EcmSelfDiagnosticSecondTest
**
** Service ID         : None
**
** Description        : This service is used to test the ECM self diagnostic
**                      for second set of error sources.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, MCU_PROTECTEDWRITE
**
** Registers Used     : ECMMESSTR1, ECMESSTC1, ECMPCMD1, ECMCESSTR1
**                      ECMPS, ECMPE1, ECMCESSTR1
******************************************************************************/
/* Implements MCU_ESDD_UD_061 */
#if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_038 */
/* Implements MCU152, MCU017, EAAR_PN0034_FR_0018, EAAR_PN0079_FSR_0122 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticSecondTest
                                                                        (void)
{
  P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST) LpEcmSetting;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulEcmPseudoData;
  /* START Msg(2:3204)-4 */
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  /* END Msg(2:3204)-4 */
  VAR(uint8, AUTOMATIC) LucEcmDiagCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  LenReturnValue = E_OK;
  /* START Msg(2:2814)-2 */
  /* MISRA Violation: START Msg(4:0317)-7 */
  LpEcmSetting = Mcu_GpConfigPtr->pEcmSetting;
  /* END Msg(4:0317)-7 */
  /* END Msg(2:2814)-2 */
  /* Perform Ecm diagnostic test on register 1 */
  /* START Msg(2:3892)-5 */
  /* load ECM pseudo error trigger register 1 address */
  LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMPE1_OFFSET;
  /* END Msg(2:3892)-5 */

  for (LucEcmDiagCount = MCU_ZERO;
  (LucEcmDiagCount < MCU_THIRTYTWO) && (E_OK == LenReturnValue);
  LucEcmDiagCount++)
  {
    if (((LucEcmDiagCount < MCU_ELEVEN) && (LucEcmDiagCount != MCU_THREE)) ||
    (MCU_TWENTYNINE == LucEcmDiagCount))
    {

      LulEcmPseudoData = ((uint32)MCU_ONE << LucEcmDiagCount);
      /* START Msg(2:2814)-2 */
      if ((uint32)MCU_ZERO !=
                    (LulEcmPseudoData & LpEcmSetting->ulEcmMaskInterReg1value))
      /* END Msg(2:2814)-2 */
      {
        /* Implements MCU_ESDD_UD_071 */
        /* Initialize the retry count to config value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Generate the error using ECMPE1 register */
        MCU_PROTECTEDWRITE(*(volatile uint32 *)LulEcmConfigAddress,
        LulEcmPseudoData, MCU_ECMPCMD1, MCU_ECMPS,
        LucRetryCount, LenReturnValue)
        /* END Msg(4:0303)-2 */

        /* Check whether Dem reported or not */
        if (E_OK == LenReturnValue)
        {
          /* START Msg(2:3892)-5 */
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Check error out put status as low
          * MCU_ERROROUT_STATUS = 0x80000000
          */
          if ((MCU_ZERO != (MCU_ECMMESSTR1 & LulEcmPseudoData)) &&
          (MCU_ZERO != (MCU_ECMCESSTR1 & LulEcmPseudoData)))
          /* END Msg(4:0303)-2 */
          /* END Msg(2:3892)-5 */
          {
            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;
            /* MISRA Violation: START Msg(4:0303)-2 */
            MCU_PROTECTEDWRITE(MCU_ECMESSTC1, LulEcmPseudoData,
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
            /* END Msg(4:0303)-2 */

          }
          else
          {
            /* Self Diagnostic test for ECM is failed.*/
            /* Implements MCU_ESDD_UD_084 */
            /* Implements MCU_ESDD_UD_085 */
            Dem_ReportErrorStatus(MCU_E_ECM_SELFDIAG_FAILURE,
            DEM_EVENT_STATUS_FAILED);
            /* Set LenReturnValue to E_NOT_OK */
            LenReturnValue = E_NOT_OK;
          }
        } /* (LenReturnValue == E_OK) */
        else
        {
          /* No action required*/
        }
      }
      else
      {
        /* No action required*/
      }
    }
    else
    {
    /* No action required */
    }
  }
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_INIT(MCU_ECMMESSTR1, MCU_ERROROUT_STATUS, MCU_FULL_MASK,
                                                    MCU_INIT_SID)
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3416)-8  */
  return LenReturnValue;
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* MCU_ECM_SELFDIAGNOSTIC_TEST */

/******************************************************************************
** Function Name      : Mcu_LockStepSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check lockstep self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_EXIT_CRITICAL_SECTION, MCU_ENTER_CRITICAL_SECTION,
**                      MCU_PROTECTEDWRITE
**
** Registers Used     : TESTCOMPREG1, TESTCOMPREG0, ECMMESSTR0, ECMESSTC0,
**                      ECMPCMD1, ECMPS
******************************************************************************/
/* Implements MCU_ESDD_UD_064 */
#if (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_015 */
/* Implements MCU152, MCU017, EAAR_PN0079_FSR_0092, EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_NR_0020, EAAR_PN0079_FSR_0118 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
Mcu_LockStepSelfDiagnosticTest (void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulTestCompValue;
  VAR(uint8, AUTOMATIC) LucLoopCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  /* Initialize the return value */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Write the arbitrary value to register TESTCOMPREG0 */
  MCU_TESTCOMPREG0 = MCU_LOCKSTEP_DUMMY_VALUE;

  /* Write the different value to register TESTCOMPREG0 */
  MCU_TESTCOMPREG1 = (~MCU_LOCKSTEP_DUMMY_VALUE);

  /* Read the TESTCOMPREG0 value so that different values will be given
  * to master and checker core, As a result lockstep error status will be set
  */
  LulTestCompValue = MCU_TESTCOMPREG0;
  /* MISRA Violation: START Msg(4:2983)-14 */
  /* Dummy operation on variable */
  LulTestCompValue++;
  /* END Msg(4:2983)-14 */
  /* END Msg(4:0303)-2  */
  /* Implements MCU_ESDD_UD_071 */
  /* Initialize the loop count value */
  LucLoopCount = MCU_LOOPCOUNT;

  /* MISRA Violation: START Msg(4:0303)-2 */
  /* check lock step compare error status */
  do
  {
    LucLoopCount--;
    /* START Msg(2:3892)-5 */
  } while ((MCU_ZERO == (MCU_ECMMESSTR0 & MCU_TWO)) &&
  (LucLoopCount > MCU_ZERO));
  if (MCU_TWO == (MCU_ECMMESSTR0 & MCU_TWO))
  {
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3892)-5 */
    /* Clear the ECM lock step compare error */
    /* Implements MCU_ESDD_UD_083 */
    MCU_PROTECTEDWRITE (MCU_ECMESSTC0, (uint32)MCU_TWO, MCU_ECMPCMD1,
    MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(2:3892)-5 */
    /* END Msg(4:0303)-2 */
    /* START Msg(2:3416)-8  */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_ECMMESSTR0, (uint32)MCU_ZERO, MCU_FULL_MASK,
    MCU_INIT_SID)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3416)-8  */

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  else
  {
    /* Implements MCU_ESDD_UD_087 */
    Dem_ReportErrorStatus(MCU_E_LOCKSTEP_SELFDIAG_FAILURE,
    DEM_EVENT_STATUS_FAILED);
    LenReturnValue = E_NOT_OK;
  }

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_SaveResetReason
**
** Service ID         : NA
**
** Description        : The function reads the reset type from the hardware
**                      and saved for the usage of get reset reason and
**                      get reset raw value API's
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GulMcuSavedResfStatus, Mcu_GpConfigPtr
**                      Mcu_GulLastResetReasonStatus, Mcu_GblResetStatusSaved
**
** Function Invoked   : Mcu_IdentifyEcmErrorSource, MCU_PROTECTEDWRITERETNONE
**
** Registers Used     : POF, POFC, RESF, RESFC, CVMFC, CVMF PROTCMDCVM, PROTSCVM
*******************************************************************************/

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_011 */
/* Implements MCU005, MCU052, EAAR_PN0079_FSR_0016, MCU235 */
/* Implements EAAR_PN0034_NR_0020, EAAR_PN0034_FR_0018 */
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_SaveResetReason (void)
{
  /* Implements MCU_ESDD_UD_094 */
  VAR(Mcu_ResetType, AUTOMATIC) LddResetSource;
  VAR(uint32, AUTOMATIC) LulResfStatus;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucWriteData;

  /* Initialize to default values */
  LddResetSource = MCU_RESET_UNKNOWN;

  /* Check whether reset reason saved already, if yes no action required */
  if (MCU_FALSE == Mcu_GblResetStatusSaved)
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_POF_RST == MCU_POF)
    /* END Msg(4:0303)-2 */
    {
      /* Get the reset reason value for power on reset */
      LddResetSource = MCU_POWER_ON_RESET;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear Reset factor register */
      MCU_POFC = MCU_POF_CLEAR;
      /* START Msg(2:3892)-5 */
      MCU_REG_WRITE_VERIFY_INIT(MCU_POF, MCU_ZERO, MCU_POF_WV_MASK,MCU_INIT_SID)
      /* END Msg(4:0303)-2 */
    }
    /* MISRA Violation: START Msg(4:0303)-2 */
    else if (MCU_ZERO != MCU_RESF)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Get the resf register status */
      LulResfStatus = MCU_RESF;
      /* END Msg(4:0303)-2 */

      switch (LulResfStatus)
      {
      case MCU_PINRST:
        /* Pin reset */
        LddResetSource = MCU_PIN_RST;
      break;

      case MCU_ECM:
        /* Call function to identify ECM error source */
        LddResetSource = Mcu_IdentifyEcmErrorSource();
      break;

      case MCU_SWR:
        /* Software reset */
        LddResetSource = MCU_SW_RESET;
      break;

      default:
        /* Reset is due to unknown source */
        LddResetSource = MCU_RESET_UNKNOWN;
      break;
      }

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Save the RESF register before clearing, for next call */
      Mcu_GulMcuSavedResfStatus = (uint32)MCU_RESF;
      /* END Msg(4:0303)-2 */

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear Reset factor register */
      MCU_RESFC = MCU_RESF_CLEAR;
    /*START Msg(2:3892)-5*/
      MCU_REG_WRITE_VERIFY_INIT(MCU_RESF, MCU_ZERO, MCU_FULL_MASK,
      MCU_INIT_SID)
      /* END Msg(4:0303)-2 */
    }
    /* START Msg(2:2814)-2 */
    else if (MCU_THREE == Mcu_GpConfigPtr->ulCvmResetEnableReg)
    /* END Msg(2:2814)-2  */
    /* END Msg(2:3892)-5 */
    {
      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /*Check CVMF status for low or high voltage detection */
      if (MCU_ZERO != (MCU_CVMF & MCU_THREE))
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */
      {
        /* Get the reset reason value for power on reset */
        LddResetSource = MCU_CVM_RST;

        /* Implements MCU_ESDD_UD_071 */
        /* Initialize the retry count to config value */
        LucRetryCount = MCU_LOOPCOUNT;
        LucWriteData = MCU_CVM_CLEAR;

        /* START Msg(2:3892)-5 */
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Clear CVMF status*/
        MCU_PROTECTEDWRITERETNONE(MCU_CVMFC, LucWriteData,
        MCU_PROTCMDCVM, MCU_PROTSCVM, LucRetryCount)
        MCU_REG_WRITE_VERIFY_INIT(MCU_CVMF, MCU_CVM_CLEAR, MCU_8BIT_MASK,
                                                             MCU_INIT_SID)
        /* END Msg(2:3892)-5 */
        /* END Msg(4:0303)-2 */
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

    /* Save the reset status */
    Mcu_GulLastResetReasonStatus = (uint32) LddResetSource;

    /* Update reset saved status to true */
    Mcu_GblResetStatusSaved = MCU_TRUE;
  }
  else
  {
    /* No action required */
  }
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/******************************************************************************
** Function Name      : Mcu_IdentifyEcmErrorSource
**
** Service ID         : None
**
** Description        : This service is identify the ECM error source which
**                      caused internal reset.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Mcu_ResetType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : None
**
** Registers Used     : ECMMESSTR0, ECMMESSTR1
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/*Implements EAAR_PN0034_FR_0018*/
/* Implements MCU_ESDD_UD_016 */
STATIC FUNC(Mcu_ResetType, MCU_PRIVATE_CODE) Mcu_IdentifyEcmErrorSource (void)
{
  /* Implements MCU_ESDD_UD_106 */
  P2CONST (Mcu_EcmResetReasonMap, AUTOMATIC, MCU_CONFIG_CONST)
  LpEcmResetReasonMap;
  P2CONST (Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST)
  LpEcmSetting;
  /* Implements MCU_ESDD_UD_094 */
  VAR(Mcu_ResetType, AUTOMATIC) LddResetSource;
  VAR(uint32, AUTOMATIC) LulEcmStatusData[MCU_TWO];
  VAR(uint32, AUTOMATIC) LulEcmErrSourceMask;
  VAR(uint8, AUTOMATIC) LucErrorSourceCount;
  VAR(uint8, AUTOMATIC) LucResetReasonCount;
  VAR(uint8, AUTOMATIC) LucRstSrcCnt;
  VAR(uint8, AUTOMATIC) LucRegIndex;

  /* Initialise reset reason count as zero */
  LucResetReasonCount = MCU_ZERO;

  /* Initialize reset reason as MCU_RESET_UNKNOWN */
  LddResetSource = MCU_RESET_UNKNOWN;
  /* MISRA Violation: START Msg(4:0316)-1 */
  /* START Msg(2:2814)-2 */
  /* Get the pointer to ECM Setting configuration structure */
  LpEcmSetting = (P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST))
  Mcu_GpConfigPtr->pEcmSetting;
  /* END Msg(2:2814)-2  */
  /* Get the pointer to reset reason map structure */
  LpEcmResetReasonMap =
  (P2CONST(Mcu_EcmResetReasonMap, AUTOMATIC, MCU_CONFIG_CONST))
                                      Mcu_GpConfigPtr->pEcmResetReasonMap;
  /* END Msg(4:0316)-1 */
  /* Get the count of reset capable error sources */
  LucRstSrcCnt = Mcu_GpConfigPtr->ucResetErrSrcCnt;

  /* START Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* START Msg(2:2814)-2 */
  /* Read error status registers */
  LulEcmStatusData[MCU_ZERO] = MCU_ECMMESSTR0 &
  LpEcmSetting->ulEcmInternalResetReg0value;
  LulEcmStatusData[MCU_ONE] = MCU_ECMMESSTR1 &
  LpEcmSetting->ulEcmInternalResetReg1value;
  /* END Msg(2:2814)-2  */
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3892)-5 */

  /* Check if any error sources are configured */
  if (LpEcmResetReasonMap != NULL_PTR)
  {
    /* Initialise loop variable as zero */
    LucErrorSourceCount = MCU_ZERO;

    /* loop through all error sources unless multiple error sources are
    detected */
    do
    {
      /* Get the mask value for corresponding error source */
      LulEcmErrSourceMask = LpEcmResetReasonMap->ulErrorSrcMask;
      /* Get error source register index */
      LucRegIndex = LpEcmResetReasonMap->ucErrSrcRegIdx;
      /* Check whether error source is set */
      if ((LulEcmStatusData[LucRegIndex] & LulEcmErrSourceMask) ==
      LulEcmErrSourceMask)
      {
        /* Count the number of reset reasons */
        LucResetReasonCount++;
        /* Update the respective reset reason */
        LddResetSource = LpEcmResetReasonMap->enResetReason;
      }
      else
      {
        /* No action required */
      }
      /* Increment error source count */
      LucErrorSourceCount++;
      /* MISRA Violation: START Msg(4:0489)-10 */
      /* Increment the pointer to next Error Source Status Register structure */
      LpEcmResetReasonMap++;
      /* END Msg(4:0489)-10 */
    }while ((LucErrorSourceCount < LucRstSrcCnt) &&
    (LucResetReasonCount < MCU_TWO));

    /* Update reset reason as unknown if multiple reset are detected */
    if (LucResetReasonCount > MCU_ONE)
    {
      LddResetSource = MCU_RESET_UNKNOWN;
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

  /* Return reset reason */
  return(LddResetSource);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_EcmErrorInitialNotification
**
** Service ID         : None
**
** Description        : This service is used to notify upper layer if any
**                      error is present before initialisation .
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : none
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : None
**
** Registers Used     : ECMMESSTR0, ECMMESSTR1
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_019 */
/* Implements EAAR_PN0079_FSR_0102, EAAR_PN0034_FR_0018 */
STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_EcmErrorInitialNotification (void)
{
  /* To store Ecm error status data */
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(uint8, AUTOMATIC) LucTotalErrSrcCnt;

  /* Implements MCU_ESDD_UD_107 */
  P2CONST (Mcu_EcmNotifMap, AUTOMATIC, MCU_CONFIG_CONST)
  LpEcmInitialNotifMap;

  /* START Msg(2:2814)-2 */
  if ((NULL_PTR != Mcu_GpConfigPtr->pEcmInitNotifyMap) &&
  (MCU_ZERO != Mcu_GpConfigPtr->ucInitNotiyErrSrcCnt))
  /* END Msg(2:2814)-2  */
  {
    /* MISRA Violation: START Msg(4:0316)-1 */
    /* Load the Initial notification array start address to local pointer */
    LpEcmInitialNotifMap =
    (P2CONST(Mcu_EcmNotifMap, AUTOMATIC, MCU_CONFIG_CONST))
    (Mcu_GpConfigPtr->pEcmInitNotifyMap);
    /* END Msg(4:0316)-1 */

    /* Get the total number of error sources configured */
    LucTotalErrSrcCnt = Mcu_GpConfigPtr->ucInitNotiyErrSrcCnt;

    /*Loop for total number of error count*/
    for (LucIndex= MCU_ZERO; LucIndex < LucTotalErrSrcCnt; LucIndex++)
    {
      /*Checking whether error occurred in ECMMESSTR0*/
      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0491)-11 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((MCU_ZERO == LpEcmInitialNotifMap[LucIndex].ucErrSrcRegIdx) &&
      ( MCU_ZERO != (MCU_ECMMESSTR0 &
      LpEcmInitialNotifMap[LucIndex].ulErrorSrcMask)))
      /* END Msg(4:0303)-2 */
      /* END Msg(4:0491)-11 */
      /* END Msg(2:3892)-5 */
      {
        /*Call back for initial notification*/
        /* MISRA Violation: START Msg(4:0491)-11 */
        LpEcmInitialNotifMap[LucIndex].pNotiFuncPtr();
        /* END Msg(4:0491)-11 */
      }
      /*Checking whether error occurred in ECMMESSTR1*/
      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0491)-11 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      else if ((MCU_ONE == LpEcmInitialNotifMap[LucIndex].ucErrSrcRegIdx) &&
      ( MCU_ZERO != (MCU_ECMMESSTR1 &
      LpEcmInitialNotifMap[LucIndex].ulErrorSrcMask)))
      /* END Msg(4:0303)-2 */
      /* END Msg(4:0491)-11 */
      /* END Msg(2:3892)-5 */
      {
        /*Call back for initial notification*/
        /* MISRA Violation: START Msg(4:0491)-11 */
        LpEcmInitialNotifMap[LucIndex].pNotiFuncPtr();
        /* END Msg(4:0491)-11 */
      }
      else
      {

      }
    }
  }
  else
  {
  /* Do nothing */
  }

}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_ConfigureEcm
**
** Service ID         : None
**
** Description        : This service configure ECM.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpEcmSetting
**
** Function Invoked   : Mcu_ConfigureEcmDelayTimer, Mcu_ConfigureEcmRegSettings
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : EIBD8, IMR0EIMK8, ECMEPCFG, ECMPCMD1, ECMPS
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_020 */
/* Implements MCU152, EAAR_PN0034_FR_0067, EAAR_PN0034_FR_0068 */
/* Implements EAAR_PN0079_FSR_0034, EAAR_PN0079_FSR_0034, EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0023, EAAR_PN0034_FR_0067 */
/* Implements EAAR_PN0034_NR_0020 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcm (void)
{
  /* Pointer to Ecm configuration */
  P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST) LpEcmSetting;
  /* Local variable to hold Ecm configuration registers address */
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;

  /* Load the Ecm config start address  */
  LpEcmSetting = Mcu_GpEcmSetting;

  LenReturnValue = Mcu_ConfigureEcmRegSettings();

  /* check whether Dem is reported or not */
  if (E_OK == LenReturnValue)
  {
    /* Configuring Ecm Dealy Timer */
    LenReturnValue = Mcu_ConfigureEcmDelayTimer();
  }
  else
  {
    /* No action required */
  }

  /* Check Dem reported.*/
  if (E_OK == LenReturnValue)
  {
    /* Check if any error source of ECM is configured for
    * maskable interrupt
    */
    /* START Msg(2:2814)-2 */
    if ((MCU_LONG_WORD_ZERO != LpEcmSetting->ulEcmMaskInterReg0value) ||
    (MCU_LONG_WORD_ZERO != LpEcmSetting->ulEcmMaskInterReg1value))
    /* END Msg(2:2814)-2  */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Setting to bound Interrupts to the CPU1 */
      MCU_EIBD8 =  MCU_EIBD08_CPU1_VALUE;
      /* END Msg(4:0303)-2 */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Enable the ECM maskable Interrupt */
      RH850_SV_MODE_IMR_AND(16, &MCU_IMR0EIMK8,
      (uint16)(~MCU_ENABLE_INTERRUPT));
      /* Register dummy read-write  */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      RH850_SV_MODE_IMR_AND(16, &MCU_IMR0EIMK8,
      (uint16)(~MCU_ENABLE_INTERRUPT));
      /* SYNCP execution */
      EXECUTE_SYNCP();
      #endif
      /* END Msg(4:0303)-2 */
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    else
    {
      /* No action required */
    }
    /* START Msg(2:3892)-5 */
    /* Set Ecm error pulse register to select dynamic or non-dynamic */
    /* Get the Ecm base address (Error Pulse Configuration Register) */
    LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMEPCFG_OFFSET;
    /* END Msg(2:3892)-5 */

    /* START Msg(2:3892)-5 */
    /* Implements MCU_ESDD_UD_071 */
    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;
    /* END Msg(2:3892)-5 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Implements MCU_ESDD_UD_068 */
    /* Load Ecm error pulse config register to select dynamic or
    * non-dynamic
    */
    MCU_PROTECTEDWRITE((*(volatile uint8 *)LulEcmConfigAddress),
    MCU_ECM_ERROUT_MODE, MCU_ECMPCMD1, MCU_ECMPS,
    LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3892)-5 */
    /* START Msg(2:3416)-8  */
    /* Implements MCU_ESDD_UD_068 */
    /* Read back the Ecm error pulse register*/
    MCU_REG_WRITE_VERIFY_INIT(*(volatile uint8 *)LulEcmConfigAddress,
    MCU_ECM_ERROUT_MODE, MCU_8BIT_MASK, MCU_INIT_SID)
    /* END Msg(2:3416)-8  */
    /* END Msg(2:3892)-5 */
    /* END Msg(4:0303)-2 */
  }
  else
  {
    /* Do nothing */
  }

return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_ConfigureEcmRegSettings
**
** Service ID         : None
**
** Description        : This service configure ECM.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpEcmSetting
**
** Function Invoked   : MCU_PROTECTEDWRITE, MCU_REG_WRITE_VERIFY
**
** Registers Used     : ECMMICFG0, ECMMICFG1, ECMNMICFG0, ECMNMICFG1,
**                      ECMIRCFG0, ECMIRCFG1, ECMEMK0, ECMEMK1, ECMPCMD1
**                      ECMPS
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_034 */
/* Implements MCU152,EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0079_FSR_0042, EAAR_PN0079_FSR_0039*/
/* Implements EAAR_PN0034_FR_0018,EAAR_PN0034_NR_0020, EAAR_PN0034_FSR_0004 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmRegSettings (void)
{
  /* Pointer to Ecm configuration */
  P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST) LpEcmSetting;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  /* Local variable to hold Ecm configuration registers address */
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  VAR(uint32, AUTOMATIC) LulEcmwordvalue;
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5  */
  /* Load the Ecm config start address  */
  LpEcmSetting = Mcu_GpEcmSetting;

  /* Initialize the index value */
  LucIndex = MCU_ZERO;

  do
  {
    /* START Msg(2:2814)-2 */
    /* START Msg(2:3892)-5 */
    switch (LucIndex)
    {
    case MCU_ZERO:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMMICFG0_OFFSET);

      /* Load Ecm maskable interrupt reg0 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmMaskInterReg0value &
      (~MCU_RAM_MASK0_VALUE));
    break;

    case MCU_ONE:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMMICFG1_OFFSET);

      /* Load Ecm maskable interrupt reg1 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmMaskInterReg1value &
      (~MCU_RAM_MASK1_VALUE));
    break;

    case MCU_TWO:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMNMICFG0_OFFSET);

      /* Load Ecm non maskable interrupt reg0 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmNonMaskInterReg0value &
      (~MCU_RAM_MASK0_VALUE));
    break;

    case MCU_THREE:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMNMICFG1_OFFSET);

      /* Load Ecm non maskable interrupt reg1 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmNonMaskInterReg1value &
      (~MCU_RAM_MASK1_VALUE));
    break;

    case MCU_FOUR:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMIRCFG0_OFFSET);

      /* Load Ecm internal reset reg0 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmInternalResetReg0value &
      (~MCU_RAM_MASK0_VALUE));
    break;

    case MCU_FIVE:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMIRCFG1_OFFSET);

      /* Load Ecm internal reset reg1 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmInternalResetReg1value &
      (~MCU_RAM_MASK1_VALUE));
    break;

    case MCU_SIX:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMEMK0_OFFSET);

      /* Load Ecm error mask reg0 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmErrorMaskReg0Value |
      (MCU_RAM_MASK0_VALUE));
    break;

    case MCU_SEVEN:
      /* Update the Ecm base address to maskable interrupt reg */
      LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMEMK1_OFFSET);

      /* Load Ecm error mask reg1 configuration value */
      LulEcmwordvalue = (LpEcmSetting->ulEcmErrorMaskReg1Value |
      (MCU_RAM_MASK1_VALUE));
    break;

      /* START Msg(2:2016)-3 */
      /* START Msg(2:2881)-9  */
      /* Start: MCU_UT_007 */
    default:
      /* END Msg(2:2881)-9  */

      /*  Do nothing */
    break;
      /* End: MCU_UT_007 */
      /* END Msg(2:2814)-2  */
      /* END Msg(2:3892)-5 */
    }
    /* END Msg(2:2016)-3 */
    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* write the value the particular register address */
    MCU_PROTECTEDWRITE((*(volatile uint32 *)LulEcmConfigAddress),
    LulEcmwordvalue, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount,
    LenReturnValue)
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3416)-8  */
    /* Read back the Ecm error pulse register*/
    MCU_REG_WRITE_VERIFY_INIT(*(volatile uint32 *) LulEcmConfigAddress,
    LulEcmwordvalue, MCU_FULL_MASK, MCU_INIT_SID)
    /* END Msg(2:3416)-8  */
    /* END Msg(4:0303)-2 */

    /* Increment the index */
    LucIndex++;
  }while ((MCU_MAX_ECM_CONFIG > LucIndex) &&
  (E_OK == LenReturnValue));


  return LenReturnValue;
}
/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_ConfigureEcmDelayTimer
**
** Service ID         : None
**
** Description        : This service configure ECM delay timer level as per
**                      configuration.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpEcmSetting
**
** Function Invoked   : MCU_PROTECTEDWRITERETNONE, MCU_PROTECTEDWRITE,
**                      Mcu_EcmDelayTimerRegisterSetting,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION
**
** Registers Used     : ECMDTMCTL, ECMPCMD1, ECMPS, ECMDTMCMP
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_021 */
/* Implements MCU152, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0030 */
/* Implements EAAR_PN0034_FR_0013, EAAR_PN0079_FSR_0033, EAAR_PN0079_FSR_0040 */
/* Implements EAAR_PN0079_FSR_0041, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0081 */
/* Implements EAAR_PN0034_NR_0020 */

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmDelayTimer (void)
{

  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  /* Local variable to hold Ecm configuration registers address */
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  /* To store Ecm error status data */
  VAR(uint32, AUTOMATIC) LulEcmStatusData;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* Stop ECM delay timer and initialize the counter to zero
  * using control register
  */
  /* START Msg(2:3892)-5 */
  LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMDTMCTL_OFFSET;
  /* END Msg(2:3892)-5 */

  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* MISRA Violation: START Msg(4:0303)-2 */
  /* write the value to ECMDTMCTL register */
  MCU_PROTECTEDWRITERETNONE((*(volatile uint8 *) LulEcmConfigAddress),
  MCU_ECM_DELAY_TIMER_STOP, MCU_ECMPCMD1, MCU_ECMPS,
  LucRetryCount)
  /* END Msg(4:0303)-2 */

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* START Msg(2:3892)-5 */
  /* Update the Ecm base address to delay timer compare register */
  LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMDTMCMP_OFFSET;
  /* END Msg(2:3892)-5 */

  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;
  /* START Msg(2:3892)-5 */
  /* Implements MCU_ESDD_UD_067 */
  LulEcmStatusData = MCU_ECM_DLYTIMER_VALUE;
  /* END Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Load configured ECM delay timer value */
  MCU_PROTECTEDWRITE((*(volatile uint16 *)LulEcmConfigAddress),
  (uint16)(LulEcmStatusData), MCU_ECMPCMD1, MCU_ECMPS,
  LucRetryCount, LenReturnValue)
  /* END Msg(4:0303)-2 */

  /* MISRA Violation: START Msg(4:0303)-2 */
  /* START Msg(2:3416)-8  */
  /* START Msg(2:3892)-5 */
  /* Implements MCU_ESDD_UD_067 */
  /* Read back the ECM delay timer register */
  MCU_REG_WRITE_VERIFY_INIT(*(volatile uint16 *)LulEcmConfigAddress,
  MCU_ECM_DLYTIMER_VALUE, MCU_16BIT_MASK, MCU_INIT_SID)
  /* END Msg(2:3416)-8  */
  /* END Msg(4:0303)-2  */
  /* END Msg(2:3892)-5  */
  /* Check Dem reported */
  if (E_OK == LenReturnValue)
  {
    /* Configure Ecm Delay Register setting */
    LenReturnValue = Mcu_EcmDelayTimerRegisterSetting();

  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    /* Configure control register to start ECM delay timer once
    * interrupt occurs.
    */
    /* START Msg(2:3892)-5 */
    LulEcmConfigAddress =
    MCU_ECM_BASE_ADDRESS + MCU_ECMDTMCTL_OFFSET;
    /* END Msg(2:3892)-5 */

    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* write the value to ECMDTMCTL register */
    MCU_PROTECTEDWRITE((*(volatile uint8 *) LulEcmConfigAddress),
                                      MCU_ONE, MCU_ECMPCMD1, MCU_ECMPS,
                                              LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  else
  {
    /* No action required */
  }

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_EcmDelayTimerRegisterSetting
**
** Service ID         : None
**
** Description        : This service configure ECM delay timer level as per
**                      configuration.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpEcmSetting
**
** Function Invoked   : MCU_REG_WRITE_VERIFY,  MCU_PROTECTEDWRITE
**
** Registers Used     : ECMPCMD1, ECMPS, ECMDTMCFG0, ECMDTMCFG1, ECMDTMCFG2,
**                      ECMDTMCFG3
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_036 */
/* Implements MCU152, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0079_FSR_0041, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_NR_0020, EAAR_PN0034_FSR_0004 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmDelayTimerRegisterSetting
                                                                        (void)
{
  /* Pointer to Ecm configuration */
  P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST) LpEcmSetting;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  /* Local variable to hold Ecm configuration registers address */
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  VAR(uint32, AUTOMATIC) LulEcmwordvalue;
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  /* Load the Ecm config start address  */
  LpEcmSetting = Mcu_GpEcmSetting;

  /* START Msg(2:3892)-5 */
  /* Update the Ecm base address to delay timer config register */
  LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMDTMCFG0_OFFSET);
  /* END Msg(2:3892)-5 */

  /* Initialize the index value */
  LucIndex = MCU_ZERO;

  /* Load ECM delay timer configuration reg 0, 1, 2, 3  */
  do
  {
    /* START Msg(2:2814)-2 */
    switch (LucIndex)
    {
    case MCU_ZERO:
      /* Assign the configured delay values */
      LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg0Value;
    break;

    case MCU_ONE:
      /* Assign the configured delay values */
      LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg1Value;
    break;

    case MCU_TWO:
      /* Assign the configured delay values */
      LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg2Value;
    break;

    case MCU_THREE:
      /* Assign the configured delay values */
      LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg3Value;
    break;
      /* START Msg(2:2881)-9  */
      /* START Msg(2:2016)-3 */
      /* Start: MCU_UT_009 */
    default:

      /* END Msg(2:2881)-9  */
      /* No action required */
    break;
      /* End: MCU_UT_009 */
      /* END Msg(2:2814)-2  */
    }
    /* END Msg(2:2016)-3 */

    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* write the value to ECMDTMCFGn register */
    MCU_PROTECTEDWRITE((*(volatile uint32 *)LulEcmConfigAddress),
    LulEcmwordvalue, MCU_ECMPCMD1, MCU_ECMPS,
    LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */

    /* Implements MCU_ESDD_UD_062 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* START Msg(2:3416)-8  */
    /*Read back the ECM delay timer configuration register 0 */
    MCU_REG_WRITE_VERIFY_INIT(*(volatile uint32 *)
    LulEcmConfigAddress, LulEcmwordvalue, MCU_FULL_MASK, MCU_INIT_SID)
    /* END Msg(2:3416)-8  */
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0400)-8 */
    /* START Msg(2:3892)-5 */
    /* Increment to next ECM reg address */
    LulEcmConfigAddress = (LulEcmConfigAddress + MCU_FOUR);
    /* END Msg(2:3892)-5 */
    /* END Msg(4:0400)-8 */
    /* Increment the index */
    LucIndex++;
  }while ((MCU_MAX_ECMDLY_CONFIG > LucIndex) &&
  (E_OK == LenReturnValue));

  return LenReturnValue;
}
/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_ConfigureLvi
**
** Service ID         : None
**
** Description        : This service configure LVI detection level as per
**                      configuration.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_LviRegSettings
**
** Registers Used     : LVICNT
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_022 */
/* Implements MCU152, EAAR_PN0079_FR_0075, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_NR_0020 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureLvi (void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulCntValue;
  VAR(uint16, AUTOMATIC) LusLoopCount;
  VAR(boolean, AUTOMATIC) WriteVerify;

  /* Initialize to default values */
  LenReturnValue = E_OK;
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Check LVI error is masked. otherwise mask first */
  if ((MCU_LVICNT & MCU_LVI_MASK) != MCU_LVI_MASK)
  /* END Msg(4:0303)-2 */
  {
    LulCntValue = MCU_LVI_MASK;

    WriteVerify = MCU_TRUE;

    LenReturnValue = Mcu_LviRegSettings (LulCntValue, WriteVerify);

  } /* End of if ((MCU_LVICNT & MCU_LVI_MASK) != MCU_LVI_MASK) */
  else
  {
    /* No action required */
  }

  /* Check the Dem reported flag set or not */
  if (E_OK == LenReturnValue)
  {
    /* Get the configured LVI detection level value */
    /* START Msg(2:2814)-2 */
    LulCntValue =
    (uint32)(Mcu_GpConfigPtr->ulLVIindicationReg & (uint32)MCU_THREE);
    /* END Msg(2:2814)-2  */
    LulCntValue = (uint32) (LulCntValue | MCU_LVI_MASK);

    WriteVerify = MCU_TRUE;

    LenReturnValue = Mcu_LviRegSettings (LulCntValue, WriteVerify);
  }

  else
  {
    /* No action required */
  }

  /* Check whether Dem reported or not */
  if (E_OK == LenReturnValue)
  {
    /* Initialize wait count value */
    LusLoopCount = MCU_LVI_DELAY_CNT;

    /* START Msg(2:3892)-5 */
    /* Wait for LVI stabilization time 80 us  */
    while (LusLoopCount > MCU_ZERO)
    /* END Msg(2:3892)-5 */
    {
      LusLoopCount--;
    }

    /* Check LVI error is not masked */
    if ((uint32)MCU_ZERO == (Mcu_GpConfigPtr->ulLVIindicationReg
    & MCU_LVI_MASK))
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      LulCntValue = (uint32) (MCU_LVICNT & (~MCU_LVI_MASK));
      /* END Msg(4:0303)-2 */

      WriteVerify = MCU_FALSE;

      LenReturnValue = Mcu_LviRegSettings (LulCntValue, WriteVerify);

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

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_LviRegSettings
**
** Service ID         : None
**
** Description        : This service configure LVI detection level as per
**                      configuration.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_REG_WRITE_VERIFY, MCU_PROTECTEDWRITE
**
** Registers Used     : LVICNT, PROT1PHCMD, PROT1PS
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements MCU_ESDD_UD_042 */
/* Implements EAAR_PN0034_FSR_0004 */
/* Implements MCU152, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0079_FR_0076, EAAR_PN0034_FR_0018 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_LviRegSettings
                                  (CONST(uint32, MCU_VAR) LulCntValue,
                                      CONST(boolean, MCU_VAR)  WriteVerify)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  /* MISRA Violation: START Msg(4:2982)-5 */
  /* Initialize return value with E_OK */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  /* Initialize retry count value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* START Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Set LVI error mask as per configuration*/
  MCU_PROTECTEDWRITE(MCU_LVICNT, LulCntValue, MCU_PROT1PHCMD,
  MCU_PROT1PS, LucRetryCount, LenReturnValue)
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3892)-5 */
  if (MCU_TRUE == WriteVerify)
  {
    /* Implements MCU_ESDD_UD_062 */
    /* Check whether Dem reported or not */
    /* Start: MCU_UT_013 */
    if (E_OK == LenReturnValue)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* START Msg(2:3416)-8  */
      /* Check whether value is written successfully to the register. */
      MCU_REG_WRITE_VERIFY_INIT(MCU_LVICNT, LulCntValue, MCU_FULL_MASK,
      MCU_INIT_SID)
      /* END Msg(2:3416)-8  */
      /* END Msg(4:0303)-2 */
    }
    /* End: MCU_UT_013 */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }

  return LenReturnValue;
}
/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_ConfigureEcmRamErrors
**
** Service ID         : None
**
** Description        : This service configure ECM errors of RAM.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpEcmSetting
**
** Function Invoked   : Mcu_ConfigureEcmRamErrorsSetting
**
** Registers Used     : ECMMICFG0,ECMMICFG1, ECMNMICFG0, ECMNMICFG1,
**                      ECMIRCFG0, ECMIRCFG1, ECMEMK0, ECMEMK1
******************************************************************************/

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_023 */
/* Implements MCU152, EAAR_PN0034_FR_0018 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmRamErrors (void)
{
  /* Implements MCU_ESDD_UD_105 */
  /* Pointer to Ecm setting */
  P2CONST(Mcu_EcmSetting, AUTOMATIC, MCU_CONFIG_CONST) LpEcmSetting;

  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulEcmwordvalue;
  VAR(uint8, AUTOMATIC) LucIndex;

  /* Initialize the index value */
  LucIndex = MCU_ZERO;

  /* Load the Ecm config start address  */
  LpEcmSetting = Mcu_GpEcmSetting;

  do
  {
    /* START Msg(2:2814)-2 */
    switch (LucIndex)
    {
    case MCU_ZERO:

      LulEcmwordvalue = LpEcmSetting->ulEcmMaskInterReg0value;
      /* ECM maskable interrupt configuration 0 for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting( LulEcmwordvalue,
      MCU_RAM_MASK0_VALUE, MCU_ECMMICFG0_OFFSET, MCU_ZERO);
    break;

    case MCU_ONE:

      LulEcmwordvalue = LpEcmSetting->ulEcmMaskInterReg1value;
      /* ECM maskable interrupt configuration 1 for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting(LulEcmwordvalue,
      MCU_RAM_MASK1_VALUE, MCU_ECMMICFG1_OFFSET, MCU_ONE);

    break;

    case MCU_TWO:

      LulEcmwordvalue = LpEcmSetting->ulEcmNonMaskInterReg0value;
      /* ECM maskable interrupt configuration 0 for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting(LulEcmwordvalue,
      MCU_RAM_MASK0_VALUE, MCU_ECMNMICFG0_OFFSET, MCU_TWO);

    break;

    case MCU_THREE:

      LulEcmwordvalue = LpEcmSetting->ulEcmNonMaskInterReg1value;
      /* ECM maskable interrupt configuration 1 for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting(LulEcmwordvalue,
      MCU_RAM_MASK1_VALUE, MCU_ECMNMICFG1_OFFSET, MCU_THREE);

    break;

    case MCU_FOUR:

      LulEcmwordvalue = LpEcmSetting->ulEcmInternalResetReg0value;
      /* ECM maskable interrupt configuration for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting(LulEcmwordvalue,
      MCU_RAM_MASK0_VALUE, MCU_ECMIRCFG0_OFFSET, MCU_FOUR);

    break;

    case MCU_FIVE:

      LulEcmwordvalue = LpEcmSetting->ulEcmInternalResetReg1value;
      /* ECM maskable interrupt configuration for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting(LulEcmwordvalue,
      MCU_RAM_MASK1_VALUE, MCU_ECMIRCFG1_OFFSET, MCU_FIVE);

    break;

    case MCU_SIX:

      LulEcmwordvalue = LpEcmSetting->ulEcmErrorMaskReg0Value;
      /* ECM error mask reg0 configuration for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting(LulEcmwordvalue,
      MCU_RAM_MASK0_VALUE, MCU_ECMEMK0_OFFSET, MCU_SIX);

    break;

    case MCU_SEVEN:

      LulEcmwordvalue = LpEcmSetting->ulEcmErrorMaskReg1Value;
      /* ECM error mask reg0 configuration for RAM */
      LenReturnValue = Mcu_ConfigureEcmRamErrorsSetting(LulEcmwordvalue,
      MCU_RAM_MASK1_VALUE, MCU_ECMEMK1_OFFSET, MCU_SEVEN);

    break;
      /* START Msg(2:2881)-9  */
      /* START Msg(2:2016)-3 */
      /* Start: MCU_UT_006 */
    default:

      /* END Msg(2:2881)-9  */

      /* Do nothing */
    break;
      /* End: MCU_UT_006 */
      /* END Msg(2:2814)-2 */
    }
    /* END Msg(2:2016)-3 */
    /* Increment the Index value */
    LucIndex++;

  }while ((MCU_MAX_ECMRAM_CONFIG > LucIndex) &&
  (E_OK == LenReturnValue));

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_ConfigureEcmRamErrorsSetting
**
** Service ID         : None
**
** Description        : This service configure ECM errors of RAM.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ConfigMaskRegvalue, RAMMaskMacroValue, Offset
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_PROTECTEDWRITE, MCU_REG_WRITE_VERIFY
**
** Registers Used     : ECMPCMD1, ECMPS
**
******************************************************************************/

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements MCU_ESDD_UD_033*/
/* Implements EAAR_PN0034_FSR_0004 */
/* Implements MCU152,EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0081 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureEcmRamErrorsSetting
          ( CONST(uint32, MCU_VAR) ConfigMaskRegvalue,
                  CONST(uint32, MCU_VAR) RAMMaskMacroValue,
                                  CONST(uint8, MCU_VAR) Offset,
                                          CONST(uint8, MCU_VAR) Index)
{
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint32, AUTOMATIC) LulEcmwordvalue;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;


  /* Initialize return value with E_OK */
  LenReturnValue = E_OK;
  /* initialize the variable */
  LulEcmConfigAddress = (uint32)MCU_ZERO;

  if (MCU_SIX > Index)
  {
    /* Load MI reg0 word value to do Ecm byte writing */
    LulEcmwordvalue = ConfigMaskRegvalue;
  }
  else
  {
    /* Load MI reg0 word value to do Ecm byte writing */
    LulEcmwordvalue = ~ConfigMaskRegvalue;

  }

  if (MCU_LONG_WORD_ZERO != (LulEcmwordvalue & RAMMaskMacroValue))
  {
    /* Update the Ecm base address to maskable interrupt reg */
    LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + Offset;

    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Write the value to the corresponding register */
    MCU_PROTECTEDWRITE((*(volatile uint32 *)LulEcmConfigAddress),
    ConfigMaskRegvalue, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount,
    LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* Implements MCU_ESDD_UD_062 */
    /* Check status of the protection write operation */
    if (E_OK == LenReturnValue)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* START Msg(2:3416)-8  */
      /* Check if the flag is true */
      /* Read back the Ecm error pulse register*/
      MCU_REG_WRITE_VERIFY_RUNTIME(*(volatile uint32 *) LulEcmConfigAddress,
                             ConfigMaskRegvalue, MCU_FULL_MASK, MCU_INIT_SID)
      /* END Msg(2:3416)-8  */
      /* END Msg(4:0303)-2 */
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /*No action required */
  }

  return LenReturnValue;
}
/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_SelectAdcClock
**
** Service ID         : None
**
** Description        : This service configure ADC clock source.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ADCKSC0CTL, ADCKSC0STAT, PROT1PHCMD, PROT1PS
******************************************************************************/
/* Implements MCU_ESDD_UD_066 */
#if (MCU_INIT_CLOCK == STD_ON)
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_024 */
/* Implements MCU152, MCU017, MCU053, MCU182_Conf, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FSR_0004*/
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_SelectAdcClock (void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulRegValue;
  VAR(uint16, AUTOMATIC) LusCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  LenReturnValue = E_OK;
  /* Get ADC clock selection value */
  /* START Msg(2:2814)-2 */
  LulRegValue = (uint32)Mcu_GpClockSetting->ucAdcClkSelectCtrlRegValue;
  /* END Msg(2:2814)-2  */

  /* Check configured clock is already selected, if no select it */
  /* MISRA Violation: START Msg(4:0303)-2 */
  if ((MCU_ADCKSC0STAT & LulRegValue) !=  LulRegValue)
  /* END Msg(4:0303)-2 */
  {
    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load source clock selection for ADC clock in control reg */
    MCU_PROTECTEDWRITE(MCU_ADCKSC0CTL,
    LulRegValue, MCU_PROT1PHCMD, MCU_PROT1PS, LucRetryCount,
    LenReturnValue)

    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */

    /* Check if any DEM error occurred */
    if (E_OK == LenReturnValue)
    {
      /* Implements MCU_ESDD_UD_062 */
      /* Read back to Clock selection Control register */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_RUNTIME(MCU_ADCKSC0CTL,
      LulRegValue, MCU_FULL_MASK, MCU_INITCLOCK_SID)
      /* END Msg(4:0303)-2 */
      /* Initialize maximum 12us Delay count value */
      LusCount = MCU_ADCCLKSEL_DELAY_CNT;

      /* Check clock selection happened successfully  */
      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Start: MCU_UT_014 */
      while (((MCU_ADCKSC0STAT &
                                (LulRegValue | MCU_CLOCK_ACTIVE)) !=
                                (LulRegValue | MCU_CLOCK_ACTIVE)) &&
                                (LusCount > MCU_ZERO))
      /* End: MCU_UT_014 */
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */

      {
        LusCount--;
      }

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((MCU_ADCKSC0STAT &
      (LulRegValue | MCU_CLOCK_ACTIVE)) !=
      (LulRegValue | MCU_CLOCK_ACTIVE))
      {
        /* END Msg(2:3892)-5 */
        /* END Msg(4:0303)-2 */
        /* ADC Clock selection failed and report production error */
        /* Implements MCU_ESDD_UD_082 */
        Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
        /* Set the return value to  E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      /* Start: MCU_UT_015 */
      else
      {
        /* No action required */
      }
    /* End: MCU_UT_015 */
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

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/******************************************************************************
** Function Name      : Mcu_ConfigureClockMonitor
**
** Service ID         : None
**
** Description        : This service configure Clock Monitor.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GstClockMonitorConf
**
** Function Invoked   : Mcu_ClmaSelfDiagnosticTest, MCU_REG_WRITE_VERIFY
**
** Registers Used     : CLMAnCTL0, CLMAnCMPH, CLMAnCMPL, CLMAnPCMD, CLMAnPS
**                      n = 0,1,2,3
******************************************************************************/
/* Implements MCU_ESDD_UD_059 */
/* Implements EAAR_PN0079_FSR_0022 */
#if(MCU_CLMA_OPERATION == STD_ON)
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_025 */
/* Implements MCU152, MCU017, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0079_FSR_0064, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FSR_0004*/
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ConfigureClockMonitor (void)
{
  /* Implements MCU_ESDD_UD_108 */
  P2CONST(Mcu_ClockMonitorConf, AUTOMATIC, MCU_CONFIG_CONST)
  LpClmaConfigPtr;
  /* Implements MCU_ESDD_UD_109 */
  P2VAR(Mcu_ClmaRegisters, AUTOMATIC, MCU_CONFIG_CONST)
  LpClmaRegBaseAddress;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(volatile uint8, AUTOMATIC) LucRegisterValueU8;
  VAR(volatile uint16, AUTOMATIC) LusRegisterValueU16;
  VAR(uint8, AUTOMATIC) LucClmaCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  /* Initialize loop variable */
  LucClmaCount = MCU_ZERO;
  /* Initialize return variable */
  LenReturnValue = E_NOT_OK;

  do
  {
    LpClmaConfigPtr = &Mcu_GstClockMonitorConf[LucClmaCount];

    /* Implements MCU_ESDD_UD_063 */
    #if (MCU_CLMA_SELFDIAGNOSTIC_TEST == STD_ON)
    if (MCU_TRUE == LpClmaConfigPtr->blClmaSelfDiagTest)
    {
      LenReturnValue =
      Mcu_ClmaSelfDiagnosticTest(LpClmaConfigPtr);
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_CLMA_SELFDIAGNOSTIC_TEST == STD_ON) */
    /* Get the pointer to CLMA register base address */
    /* START Msg(2:2814)-2 */
    LpClmaRegBaseAddress = LpClmaConfigPtr->pClmaRegBaseAddress;
    LucRegisterValueU8 = LpClmaRegBaseAddress->ucCLMAnCTL0;
    /* END Msg(2:2814)-2  */
    /* START Msg(2:3892)-5 */
    if ((LucRegisterValueU8 & MCU_ONE) == MCU_ZERO)
    /* END Msg(2:3892)-5 */
    {
      LusRegisterValueU16 = LpClmaConfigPtr->usCLMAnCMPHValue;
      /* Set the Higher threshold value for frequency limit in
      * the compare register
      */
      LpClmaRegBaseAddress->usCLMAnCMPH = LusRegisterValueU16;
      /* Update return variable as E_OK */
      LenReturnValue = E_OK;
      /* Implements MCU_ESDD_UD_062 */
      /* START Msg(2:3416)-8  */
      /* Read back to Higher threshold value compare register */
      MCU_REG_WRITE_VERIFY_RUNTIME(LpClmaRegBaseAddress->usCLMAnCMPH,
      LusRegisterValueU16, MCU_16BIT_MASK, MCU_INITCLOCK_SID)
      /* END Msg(2:3416)-8  */
    }
    else
    {
      /* No action required */
    }

    if (E_OK == LenReturnValue)
    {
      LusRegisterValueU16 = LpClmaConfigPtr->usCLMAnCMPLValue;
      /* Set the Lower threshold value for frequency limit in
      * the compare register
      */
      LpClmaRegBaseAddress->usCLMAnCMPL = LusRegisterValueU16;

      /* Implements MCU_ESDD_UD_062 */
      /* START Msg(2:3416)-8  */
      /* Read back to Lower threshold value compare register */
      MCU_REG_WRITE_VERIFY_RUNTIME(LpClmaRegBaseAddress->usCLMAnCMPL,
      LusRegisterValueU16, MCU_16BIT_MASK, MCU_INITCLOCK_SID)
      /* END Msg(2:3416)-8  */
    }
    else
    {
      /* No action required */
    }

    if (E_OK == LenReturnValue)
    {
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;
      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:4464)-4 */
      /* Write data to protected CLMA0 control register */
      MCU_PROTECTEDWRITE(LpClmaRegBaseAddress->ucCLMAnCTL0,
      MCU_ONE, LpClmaRegBaseAddress->ucCLMAnPCMD,
      LpClmaRegBaseAddress->ucCLMAnPS, LucRetryCount,
      LenReturnValue)
      /* END Msg(4:4464)-4 */
      /* END Msg(2:3892)-5 */

      /* Implements MCU_ESDD_UD_062 */
      if (E_OK == LenReturnValue)
      {
        /* START Msg(2:3416)-8  */
        /* START Msg(2:3892)-5 */
        /* Read back to CLMA0 Control register 0 */
        MCU_REG_WRITE_VERIFY_RUNTIME(LpClmaRegBaseAddress->ucCLMAnCTL0,
        MCU_ONE, MCU_CLMACTL_WV_MASK, MCU_INITCLOCK_SID)
        /* END Msg(2:3892)-5 */
        /* END Msg(2:3416)-8  */
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
    /* Increment loop variable */
    LucClmaCount++;
    /* Implements MCU_ESDD_UD_075 */
  } while ((E_OK == LenReturnValue) && (TOTAL_CLMA_CONFIGURED > LucClmaCount));
  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if(MCU_CLMA_OPERATION == STD_ON) */


/******************************************************************************
** Function Name      : Mcu_ClockOutputSelect
**
** Service ID         : None
**
** Description        : This service configure Clock Output function.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Mcu_ClockOutputSetDivider, Dem_ReportErrorStatus
**                      MCU_PROTECTEDWRITE, MCU_REG_WRITE_VERIFY
**
** Registers Used     : CLKD0DIV, CKSC0CTL, CSC0STAT, CLKD0STAT, CLKD1DIV,
**                      CKSC1CTL, CSC1STAT, CLKD1STAT, PROT1PHCMD, PROT1PS
******************************************************************************/
/* Implements MCU_ESDD_UD_066 */
#if (MCU_INIT_CLOCK == STD_ON)
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0079_FR_0004, MCU152, EAAR_PN0034_FSR_0001, MCU053 */
/* Implements EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0003, EAAR_PN0079_FR_0078 */
/* Implements MCU182_Conf, MCU188_Conf, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FSR_0004*/
/* Implements MCU_ESDD_UD_026 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClockOutputSelect
(CONST(uint8, MCU_VAR) ExternalClockIndex)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucExtClkSrcClk;
  VAR(uint16, AUTOMATIC) LusCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint32, AUTOMATIC) LulExternaClkDivider;
  VAR(uint32, AUTOMATIC) ulClkSelStatus;

  LenReturnValue = E_OK;

  switch (ExternalClockIndex)
  {
  case MCU_ZERO:
    /* START Msg(2:2814)-2 */
    /* Get the value of the selected source clock for extclk 0 */
    LucExtClkSrcClk = Mcu_GpClockSetting->ucExtClk0SelectedSrcClock;
    /* END Msg(2:2814)-2 */

    /* Get the value of the divider for extclk 0 */
    LulExternaClkDivider = Mcu_GpClockSetting->ulExternalClk0Divider;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CLKD0DIV register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtClkDiv = &MCU_CLKD0DIV;
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CKSC0CTL register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtCkscCtl = &MCU_CKSC0CTL;
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CSC0STAT register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtCkscStat = &MCU_CKSC0STAT;
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CLKD0STAT register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtClkDivStat = &MCU_CLKD0STAT;
    /* END Msg(4:0303)-2 */

  break;
  case MCU_ONE:
    /* START Msg(2:2814)-2 */
    /* Get the value of the selected source clock for extclk 1 */
    LucExtClkSrcClk = Mcu_GpClockSetting->ucExtClk1SelectedSrcClock;
    /* END Msg(2:2814)-2 */

    /* Get the value of the divider for extclk 0 */
    LulExternaClkDivider = Mcu_GpClockSetting->ulExternalClk1Divider;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CLKD1DIV register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtClkDiv = &MCU_CLKD1DIV;
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CKSC1CTL register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtCkscCtl = &MCU_CKSC1CTL;
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CSC1STAT register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtCkscStat = &MCU_CKSC1STAT;
    /* END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Load the address of CLKD1STAT register to the pointer structure */
    Mcu_GpExtnClkSettingReg.pMcuExtClkDivStat = &MCU_CLKD1STAT;
    /* END Msg(4:0303)-2 */

  break;
  /* START Msg(2:2016)-3 */
  default:
    /*do nothing*/
  break;

  }
  /* END Msg(2:2016)-3 */
  /* MISRA Violation: START Msg(4:2962)-9 */
  /* START Msg(2:2814)-2 */
  if (LucExtClkSrcClk != (*Mcu_GpExtnClkSettingReg.pMcuExtCkscCtl))
  {
    /* END Msg(2:2814)-2 */
    /* END Msg(4:2962)-9 */
    /*Stop the external clock by setting the divider to zero*/
    LenReturnValue = Mcu_ClockOutputSetDivider(NO_CLK_OUTPUT);


    if (E_NOT_OK != LenReturnValue)
    {
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Load source clock selection for external clock in control reg */
      MCU_PROTECTEDWRITE((*Mcu_GpExtnClkSettingReg.pMcuExtCkscCtl),
      (uint32)LucExtClkSrcClk, MCU_PROT1PHCMD, MCU_PROT1PS, LucRetryCount,
      LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */

      /* Implements MCU_ESDD_UD_062 */
      /* Check if any DEM error occurred */
      if (E_NOT_OK != LenReturnValue)
      {
        /* START Msg(2:3416)-8  */
        /* Read back to Clock selection Control register 0 */
        MCU_REG_WRITE_VERIFY_RUNTIME(*Mcu_GpExtnClkSettingReg.pMcuExtCkscCtl,
        LucExtClkSrcClk, MCU_FULL_MASK, MCU_INITCLOCK_SID)
        /* END Msg(2:3416)-8  */

        /* Check if any development error occurred and
        * external clock selected is not NO_OUTPUT */

        if (MCU_ZERO != LucExtClkSrcClk)
        {
          /* Initialize maximum 12us Delay count value */
          LusCount = MCU_EXTCLKSEL_DELAY_CNT;
          /* MISRA Violation: START Msg(4:4391)-6 */
          ulClkSelStatus = (uint32)(LucExtClkSrcClk | MCU_CLOCK_ACTIVE);
          /* END Msg(4:4391)-6 */
          /* START Msg(2:3892)-5 */
          /* START Msg(2:2814)-2 */
          /* Check clock selection happened successfully  */
          while ((((*Mcu_GpExtnClkSettingReg.pMcuExtCkscStat) &
          ulClkSelStatus) != ulClkSelStatus) && (LusCount > MCU_ZERO))
          /* END Msg(2:2814)-2 */
          /* END Msg(2:3892)-5 */
          {
            LusCount--;
          }
          /* START Msg(2:3892)-5 */
          if (((*Mcu_GpExtnClkSettingReg.pMcuExtCkscStat) & ulClkSelStatus) !=
          ulClkSelStatus)
          /* END Msg(2:3892)-5 */
          {
            /* Clock selection failed and report production error */
            /* Implements MCU_ESDD_UD_082 */
            Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
            DEM_EVENT_STATUS_FAILED);
            /* Set the return value to  E_NOT_OK */
            LenReturnValue = E_NOT_OK;
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
        /* Implements MCU_ESDD_UD_062 */
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
  }
  else
  {
    /* No action required */
  }
  /* Set the divider value as per configuration if the external clock selected
  is not NO_OUTPUT */
  if ((E_NOT_OK != LenReturnValue) && (MCU_ZERO != LucExtClkSrcClk))
  {
    /* Delay before configuration divider if HSINT oscillation clock selected */
    if (MCU_HSINT_OSC == LucExtClkSrcClk)
    {
      /* Initialize maximum 12 us delay count value */
      LusCount = MCU_EXTCLKSEL_DELAY_CNT;
      /* START Msg(2:3892)-5 */
      while ((LusCount > MCU_ZERO))
      /* END Msg(2:3892)-5 */
      {
        /* Decrement the counter */
        LusCount--;
      }
    }
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:2962)-9 */
    LenReturnValue = Mcu_ClockOutputSetDivider(LulExternaClkDivider);
    /* END Msg(4:2962)-9 */
  }
  else
  {
    /* No action required */
  }
  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if(MCU_INIT_CLOCK == STD_ON) */



/******************************************************************************
** Function Name      : Mcu_ClockOutputSetDivider
**
** Service ID         : None
**
** Description        : This service configure Clock Output function.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpClockSetting
**
** Function Invoked   : Dem_ReportErrorStatus, MCU_REG_WRITE_VERIFY
**
** Registers Used     : CLKD0DIV, CLKD0STAT, CLKD1DIV, CLKD1STAT
******************************************************************************/
/* Implements MCU_ESDD_UD_066 */
#if (MCU_INIT_CLOCK == STD_ON)
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* START Msg(3:3203)-12 */
/* Implements MCU_ESDD_UD_027 */
/* Implements MCU152, EAAR_PN0079_FR_0078, MCU053, MCU188_Conf */
/* Implements EAAR_PN0034_FR_0018 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClockOutputSetDivider
                              (CONST(uint32, MCU_VAR)  ExternalClockDivider)
{
  /* END Msg(3:3203)-12 */
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint16, AUTOMATIC) LusCount;
  VAR(uint32, AUTOMATIC) ulClkStatus;

  /* START Msg(2:3892)-5 */
  /* Initialize to default values */
  LenReturnValue = E_OK;
  LusCount = MCU_LOOPCOUNT;
  /* END Msg(2:3892)-5 */
  /* START Msg(2:2814)-2 */
  if ((uint32)MCU_ONE == (*Mcu_GpExtnClkSettingReg.pMcuExtClkDivStat &
                        (uint32)MCU_ONE))
  {
    /* MISRA Violation: START Msg(4:2962)-9 */
    if (*(Mcu_GpExtnClkSettingReg.pMcuExtClkDiv) != ExternalClockDivider)
    {
      /* Load the divider value as per configuration */
      *(Mcu_GpExtnClkSettingReg.pMcuExtClkDiv) = ExternalClockDivider;
      /* END Msg(4:2962)-9 */
      /* END Msg(2:2814)-2 */
      /* Implements MCU_ESDD_UD_062 */
      /* MISRA Violation: START Msg(4:2962)-9 */
      /* START Msg(2:3416)-8  */
      /* Read back divider Control register  */
      MCU_REG_WRITE_VERIFY_RUNTIME(*(Mcu_GpExtnClkSettingReg.pMcuExtClkDiv),
                      ExternalClockDivider, MCU_FULL_MASK, MCU_INITCLOCK_SID)
      /* END Msg(2:3416)-8  */
      /* END Msg(4:2962)-9 */
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    LenReturnValue = E_NOT_OK;
  }

  /* Check if any DEM error occurred */
  if (E_NOT_OK != LenReturnValue)
  {
    if (NO_CLK_OUTPUT != ExternalClockDivider)
    {
      ulClkStatus = (uint32)MCU_THREE;
    }
    else
    {
      ulClkStatus = (uint32)MCU_ONE;
    }

    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:2962)-9 */
    /* START Msg(2:2814)-2 */
    /* Check clock selection happened successfully  */
    while ((ulClkStatus  !=
    ((*Mcu_GpExtnClkSettingReg.pMcuExtClkDivStat) &
    ulClkStatus)) && (LusCount > MCU_ZERO))
    /* END Msg(4:2962)-9 */
    /* END Msg(2:3892)-5 */
    /* END Msg(2:2814)-2 */
    {
      /* Decrement the counter */
      LusCount--;
    }
    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:2962)-9 */
    if (ulClkStatus != ((*Mcu_GpExtnClkSettingReg.pMcuExtClkDivStat)
    & ulClkStatus))
    /* END Msg(4:2962)-9 */
    /* END Msg(2:3892)-5 */
    {
      /* PLL0 Clock selection failed and report production error */
      /* Implements MCU_ESDD_UD_082 */
      Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
      DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {

  }

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if(MCU_INIT_CLOCK == STD_ON) */


/******************************************************************************
** Function Name      : Mcu_ClearEcmErrorOutput
**
** Service ID         : None
**
** Description        : This service is used to make error out put as inactive
**                      during the ECM self diagnostic function call
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_PROTECTEDWRITE, Mcu_EcmClearStatusRegister
**
** Registers Used     : ECMMECLR, ECMMPCMD0, ECMPS, ECMCECLR,  ECMCPCMD0,
**                      ECMESSTC0, ECMPCMD1, ECMMESSTR0, ECMEMK0, ECMMICFG0,
**                      ECMNMICFG0, ECMIRCFG0
******************************************************************************/

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_031 */
/* Implements MCU152, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FR_0018 */
/* Implements EAAR_PN0034_FSR_0004 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClearEcmErrorOutput
                                                        (const uint8 ApiId)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucIndex;
  VAR(uint32, AUTOMATIC) LulEcmMaskValue;
  P2VAR(volatile uint32, AUTOMATIC, MCU_CONFIG_CONST) LulEcmConfigAddress;

  /* MISRA Violation: START Msg(4:2982)-5 */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */

  /* Setting or clearing the error output via the ECMmECLR or ECMmESET
  * register will generate the error. Therefore, the following has to be
  * set in advance.
  */

  /* Setting the error signal from the error pin to the high level
  * (inactive) for next test
  */

  LenReturnValue= Mcu_EcmClearStatusRegister(ApiId);
  LucIndex = MCU_ONE;
  do
  {
    switch (LucIndex)
    {
    case MCU_ONE:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable Error Output by setting the ECMIE029 bit of the
      * ECMEMK0 register to disabled.
      */
      LulEcmConfigAddress = &MCU_ECMEMK0;
      LulEcmMaskValue = (MCU_ECMEMK0 | MCU_ECM029_MASK_VALUE);
      /* END Msg(4:0303)-2 */
    break;

    case MCU_TWO:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable MI by setting the ECMIE029 bit of the ECMMICFG0
      * register to disabled.
      */
      LulEcmConfigAddress = &MCU_ECMMICFG0;
      LulEcmMaskValue =  (MCU_ECMMICFG0 & (~MCU_ECM029_MASK_VALUE));
      /* END Msg(4:0303)-2 */
    break;

    case MCU_THREE:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable NMI by setting the ECNMIE029 bit of the ECMNMICFG0
      * reg to disabled.
      */
      LulEcmConfigAddress = &MCU_ECMNMICFG0;
      LulEcmMaskValue =  (MCU_ECMNMICFG0 & (~MCU_ECM029_MASK_VALUE));
      /* END Msg(4:0303)-2 */
    break;

    case MCU_FOUR:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable an internal reset by setting the ECMIRE029 bit of
      * the ECMIRCFG0 register to disabled.
      */
      LulEcmConfigAddress = &MCU_ECMIRCFG0;
      LulEcmMaskValue =  (MCU_ECMIRCFG0 & (~MCU_ECM029_MASK_VALUE));
      /* END Msg(4:0303)-2 */
    break;

    case MCU_FIVE:

      /* Set the output level from the error pin to the inactive
      * (high) level
      */
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:2982)-5 */
      MCU_PROTECTEDWRITE(MCU_ECMMECLR, MCU_ONE, MCU_ECMMPCMD0,
      MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(4:2982)-5 */
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_PROTECTEDWRITE(MCU_ECMCECLR, MCU_ONE, MCU_ECMCPCMD0,
      MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* START Msg(2:3416)-8  */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_RUNTIME(MCU_ECMMESSTR1, MCU_ERROROUT_STATUS,
      MCU_FULL_MASK, ApiId)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3416)-8  */
    break;

    case MCU_SIX:

      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear error flags by setting the ECMCLSSE029 bit of the
      * ECMESSTC0 register
      */
      MCU_PROTECTEDWRITE(MCU_ECMESSTC0, MCU_ECM029_MASK_VALUE,
      MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */

      /* Implements MCU_ESDD_UD_062 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_RUNTIME(MCU_ECMMESSTR0, (uint32)MCU_ZERO,
      MCU_FULL_MASK, ApiId)
      /* END Msg(4:0303)-2 */

    break;
      /* START Msg(2:2881)-26 */
      /* Start: MCU_UT_001 */
    default:
      /* END Msg(2:2881)-26 */
      LenReturnValue = E_NOT_OK;
    break;
      /* End: MCU_UT_001 */
    }

    if (MCU_FIVE > LucIndex)
    {
      /* Load Loop count value */
      LucRetryCount = MCU_LOOPCOUNT;
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Updated write protect register */
      MCU_PROTECTEDWRITE(*LulEcmConfigAddress, LulEcmMaskValue,
      MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* Implements MCU_ESDD_UD_062 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* START Msg(2:3416)-8  */
      /* Read back the Ecm error pulse register*/
      MCU_REG_WRITE_VERIFY_RUNTIME(*(volatile uint32 *) LulEcmConfigAddress,
      LulEcmMaskValue, MCU_FULL_MASK, MCU_INIT_SID)
      /* END Msg(2:3416)-8  */
      /* END Msg(4:0303)-2 */
    }
    else
    {
      /* No action required */
    }
    /* Increment switch case count */
    LucIndex++;
  } while ((LucIndex < MCU_SEVEN) && (E_OK == LenReturnValue));

  return(LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_EcmClearStatusRegister
**
** Service ID         : None
**
** Description        : This service is used to do clear the status
**                      register of ECM
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, MCU_PROTECTEDWRITE
**                      MCU_REG_WRITE_VERIFY
**
** Registers Used     : ECMMESSTR0, ECMESSTC0, ECMMESSTR1,ECMESSTC1
**                      ECMPCMD1, ECMPS
******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_017 */
/* Implements MCU152, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0003, EAAR_PN0034_FR_0018 */
/* START Msg(2:3206)-10 */
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmClearStatusRegister
                                                           (const uint8 ApiId)
/* END Msg(2:3206)-10 */
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  LenReturnValue = E_OK;
  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;
  /* START Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Clear the status register */
  if (MCU_ZERO != (MCU_ECMMESSTR0 & MCU_ECMMESSTR0_FULL_MASK))
  /* END Msg(2:3892)-5 */
  {
    MCU_PROTECTEDWRITE(MCU_ECMESSTC0, MCU_ECMMESSTR0_FULL_MASK,
    MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* Implements MCU_ESDD_UD_062 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_ECMMESSTR0, (uint32)MCU_ZERO, MCU_FULL_MASK,
    ApiId)
    /* END Msg(4:0303)-2 */
  }
  else
  {
    /* No action required */
  }
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* START Msg(2:3892)-5 */
  if (MCU_ZERO != (MCU_ECMMESSTR1 & MCU_ECMMESSTR1_FULL_MASK))
  /* END Msg(2:3892)-5 */
  {
    MCU_PROTECTEDWRITE(MCU_ECMESSTC1, MCU_ECMMESSTR1_FULL_MASK,
    MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* Implements MCU_ESDD_UD_062 */
    /* START Msg(2:3416)-8  */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_ECMMESSTR1, (uint32)MCU_ZERO, MCU_FULL_MASK,
    ApiId)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3416)-8  */
  }
  else
  {
    /* No action required */
  }
  return LenReturnValue;
}
/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"


/******************************************************************************
** Function Name      : Mcu_StartUPTest
**
** Service ID         : None
**
** Description        : This service is used to do startup test for SW Reset and
**                      ECM Reset to ensure its correctness.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, MCU_PROTECTEDWRITE
**
** Registers Used     : RESF, BRAMDAT0, ECMIRCFG0, SWRESA, PROT1PHCMD,
PROT1PS, ECMPS, ECMPE0,  ECMPCMD1, RESFC, ECMMESSTR0,
ECMESSTC0
******************************************************************************/
/* Implements MCU_ESDD_UD_081 */
/* Implements EAAR_PN0079_FSR_0119 */
#if ((MCU_SW_STARTUP_TEST == STD_ON) || (MCU_ECM_STARTUP_TEST == STD_ON))

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_030 */
/* Implements MCU152, EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002 */
/* Implements EAAR_PN0034_FSR_0001, EAAR_PN0079_FSR_0099, EAAR_PN0034_FSR_0004*/
/* Implements EAAR_PN0079_FSR_0101, EAAR_PN0034_FR_0018, EAAR_PN0034_FR_0081 */
/* Implements EAAR_PN0079_FSR_0100, EAAR_PN0079_FSR_0120, EAAR_PN0079_FSR_0121*/
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_StartUPTest(void)
{
  #if (MCU_ECM_STARTUP_TEST == STD_ON)
  VAR(uint8, AUTOMATIC) LucRetryCount;
  #endif
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  /* MISRA Violation: START Msg(4:2982)-5 */
  /* Initialize the return value */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  if ((MCU_BURAM_SIGN1 != MCU_BRAMDAT0) && (MCU_BURAM_SIGN2 != MCU_BRAMDAT0))
  {
    MCU_BRAMDAT0 = MCU_BURAM_SIGN_INIT;
    /* END Msg(4:0303)-2 */
  }
  else
  {
    /* No action required */
  }
  #if (MCU_SW_STARTUP_TEST == STD_ON)
  LenReturnValue = Mcu_StartUPSwTest();

  if (LenReturnValue == E_OK)
  #endif
  {
    #if (MCU_ECM_STARTUP_TEST == STD_ON)
    LenReturnValue = Mcu_StartUPEcmTest();
    #endif
  }
  #if (MCU_SW_STARTUP_TEST == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

  /* START Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */

  #if ((MCU_ECM_STARTUP_TEST == STD_ON)&&(MCU_SW_STARTUP_TEST == STD_ON))
  if ((MCU_BURAM_SIGN2 == MCU_BRAMDAT0) && (MCU_THREE == MCU_RESF) &&
                                                      (E_OK == LenReturnValue))
  #elif (MCU_SW_STARTUP_TEST == STD_ON)
  if ((MCU_BURAM_SIGN1 == MCU_BRAMDAT0) && (MCU_ONE == MCU_RESF) &&
                                                      (E_OK == LenReturnValue))
  #else
  if ((MCU_BURAM_SIGN2 == MCU_BRAMDAT0) && (MCU_TWO == MCU_RESF) &&
                                                      (E_OK == LenReturnValue))
  #endif
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3892)-5 */
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Clear Reset factor register */
    MCU_RESFC = MCU_RESF_CLEAR;
     /* START Msg(2:3892)-5 */
    /* Implements MCU_ESDD_UD_062 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_RESF, MCU_ZERO, MCU_FULL_MASK,
    MCU_INIT_SID)

    /*Clear BackUp ram*/
    MCU_BRAMDAT0 = MCU_LONG_WORD_ZERO;
    /* END Msg(4:0303)-2 */

    #if (MCU_ECM_STARTUP_TEST == STD_ON)
    /* Clear the status register */

    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_ZERO != (MCU_ECMMESSTR0 & (MCU_LONG_WORD_ONE << MCU_TWENTYNINE)))
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */
    {
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;
      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_PROTECTEDWRITE(MCU_ECMESSTC0, (MCU_LONG_WORD_ONE << MCU_TWENTYNINE),
      MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3892)-5 */
      /* Implements MCU_ESDD_UD_062 */
      /* START Msg(2:3416)-8  */
      /* MISRA Violation: START Msg(4:0303)-2 */
      MCU_REG_WRITE_VERIFY_INIT(MCU_ECMMESSTR0, (uint32)MCU_ZERO, MCU_FULL_MASK,
      MCU_INIT_SID)
      /* END Msg(4:0303)-2 */
      /* END Msg(2:3416)-8  */
     /* END Msg(2:3892)-5 */
    }
    else
    {
      /* No action required */
    }
    #endif
  }
  else
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Clear BackUp ram */
    MCU_BRAMDAT0 = MCU_LONG_WORD_ZERO;

    /* Clear Reset factor register */
    MCU_RESFC = MCU_RESF_CLEAR;
    /* START Msg(2:3892)-5 */
    /* Implements MCU_ESDD_UD_062 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_RESF, MCU_ZERO, MCU_FULL_MASK,
                                                                MCU_INIT_SID)
    /* END Msg(4:0303)-2 */
  /* END Msg(2:3892)-5 */
    /* Implements MCU_ESDD_UD_088 */
    /* Reporting DEM error */
    Dem_ReportErrorStatus(MCU_E_RESETCONTROLLER_STARTUP_FAILURE,
                                                    DEM_EVENT_STATUS_FAILED);
    LenReturnValue = E_NOT_OK;
  }
  return LenReturnValue;
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /*((MCU_SW_STARTUP_TEST == STD_ON) || (MCU_ECM_STARTUP_TEST == STD_ON))*/

/******************************************************************************
** Function Name      : Mcu_StartUPSwTest
**
** Service ID         : None
**
** Description        : This service is used to do startup test for SW Reset
**                      to ensure its correctness.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_PROTECTEDWRITE
**
** Registers Used     : RESF, BRAMDAT0, SWRESA, PROT1PHCMD, PROT1PS, ECMPCMD1
******************************************************************************/
/* Implements MCU_ESDD_UD_114 */
#if (MCU_SW_STARTUP_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_StartUPSwTest(void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  LenReturnValue = E_OK;
  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* START Msg(2:3892)-5 */
  /* MISRA Violation: START Msg(4:0303)-2 */
  if ((MCU_ZERO == MCU_RESF) && (MCU_BURAM_SIGN_INIT == MCU_BRAMDAT0))
  /* END Msg(4:0303)-2 */
  /* END Msg(2:3892)-5 */
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    /*Update BackUp ram*/
    MCU_BRAMDAT0 = MCU_BURAM_SIGN1;
    /* END Msg(4:0303)-2 */

    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_PROTECTEDWRITE(MCU_SWRESA, MCU_RES_CORRECT_VAL,
    MCU_PROT1PHCMD, MCU_PROT1PS, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */

    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_ZERO == MCU_RESF)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */
    {
      LenReturnValue = E_NOT_OK;
    }
    /* Start: MCU_UT_017 */
    else
    {
      /*To do nothing*/
    }
    /* End: MCU_UT_017 */
  }
  else
  {
    /*To do nothing*/
  }
  return LenReturnValue;
}
#endif

/******************************************************************************
** Function Name      : Mcu_StartUPEcmTest
**
** Service ID         : None
**
** Description        : This service is used to do startup test for ECM Reset
**                      to ensure its correctness.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_PROTECTEDWRITE
**
** Registers Used     : RESF, BRAMDAT0, ECMIRCFG0, PROT1PHCMD, PROT1PS, ECMPS,
**                      ECMPE0,  ECMPCMD1, ECMMESSTR0
******************************************************************************/
/* Implements MCU_ESDD_UD_113 */
#if (MCU_ECM_STARTUP_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_StartUPEcmTest(void)
{
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  VAR(uint32, AUTOMATIC) LulEcmPseudoData;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  LenReturnValue = E_OK;
  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  #if (MCU_SW_STARTUP_TEST == STD_ON)
  /* MISRA Violation: START Msg(4:0303)-2 */
  /* START Msg(2:3892)-5 */
  if ((MCU_BURAM_SIGN1 == MCU_BRAMDAT0) && (MCU_ONE == MCU_RESF))
  #else
  if ((MCU_BRAMDAT0 != MCU_BURAM_SIGN2) && (MCU_TWO != MCU_RESF))
  #endif
  /* END Msg(2:3892)-5 */
  {
    /*Update BackUp ram*/
    MCU_BRAMDAT0 = MCU_BURAM_SIGN2;
    /* END Msg(4:0303)-2 */

    /* ECM Reset*/
    /* START Msg(2:3892)-5 */
    LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMPE0_OFFSET;
    /* END Msg(2:3892)-5 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* MISRA Violation: START Msg(4:2982)-5 */
    /* Enable an internal reset by setting the ECMIRE029 bit of */
    /* the ECMIRCFG0 register.*/
    MCU_PROTECTEDWRITE(MCU_ECMIRCFG0, MCU_ECM029_MASK_VALUE, MCU_ECMPCMD1,
    MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(4:2982)-5 */
    /* END Msg(2:3892)-5 */
    /* Implements MCU_ESDD_UD_062 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_ECMIRCFG0, MCU_ECM029_MASK_VALUE,
    MCU_FULL_MASK, MCU_INIT_SID)
    /* END Msg(4:0303)-2 */
    /* START Msg(2:3892)-5 */
    /* Write the value for generating the ECM error */
    LulEcmPseudoData = (MCU_LONG_WORD_ONE << MCU_TWENTYNINE);
    /* END Msg(2:3892)-5 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Generate the error using ECMPE0 register */
    MCU_PROTECTEDWRITE(*(volatile uint32 *)LulEcmConfigAddress,
    LulEcmPseudoData, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* START Msg(2:3416)-8  */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_ECMMESSTR0, (uint32)MCU_ZERO, MCU_FULL_MASK,
    MCU_INIT_SID)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3416)-8  */
    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_ONE == MCU_RESF)
    /* END Msg(4:0303)-2 */
    /* END Msg(2:3892)-5 */
    {
      LenReturnValue = E_NOT_OK;
    }
    else
    {
    /*To do nothing*/
    }
  }
  else
  {
    /*To do nothing*/
  }
  return LenReturnValue;
}
#endif
/******************************************************************************
** Function Name      : Mcu_CvmNormalModeSetting
**
** Service ID         : None
**
** Description        : This service is used to do set normal functionality
**                      from Cvm diagnostic mode.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, MCU_PROTECTEDWRITE
**
** Registers Used     : CVMFC, CVMF, CVMDMASK, PROTCMDCVM, PROTSCVM
******************************************************************************/

/* Implements MCU_ESDD_UD_060 */
#if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements MCU_ESDD_UD_110 */
/* Implements MCU152, EAAR_PN0034_FSR_0011, EAAR_PN0079_FSR_0023 */
/* Implements EAAR_PN0079_FSR_0024, EAAR_PN0034_FR_0018, EAAR_PN0034_FSR_0012 */

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmNormalModeSetting(void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint16, AUTOMATIC) LusLoopCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucCVMFCData;

  /* Initialize the loop count value */
  LusLoopCount = MCU_CVM_DELAY_CNT;
  /* Wait for idle time after shifting to normal mode*/
  do
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_ZERO != MCU_CVMF)
    /* END Msg(4:0303)-2 */
    {
      /* Initialize the loop count value */
      LucRetryCount = MCU_LOOPCOUNT;

      LucCVMFCData = MCU_CVM_FACTOR_CLEAR;

      /* START Msg(2:3892)-5 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:2982)-5 */
      /* Write the value to the CVM factor clear register  */
      MCU_PROTECTEDWRITE(MCU_CVMFC, LucCVMFCData, MCU_PROTCMDCVM,
      MCU_PROTSCVM, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      /* END Msg(4:2982)-5 */
      /* END Msg(2:3892)-5  */
    }
    else
    {
      /* No action required */
    }
    LusLoopCount--;
    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
  } while ((MCU_ZERO != MCU_CVMF) && (LusLoopCount > MCU_ZERO));
  /* END Msg(4:0303)-2 */
  /* Implements MCU_ESDD_UD_062 */
  /* START Msg(2:3416)-8  */
  /* MISRA Violation: START Msg(4:0303)-2 */
  MCU_REG_WRITE_VERIFY_INIT(MCU_CVMF, MCU_ZERO, MCU_8BIT_MASK, MCU_INIT_SID)
  /* END Msg(2:3416)-8  */
  /* END Msg(2:3892)-5 */
  if (MCU_ZERO == MCU_CVMF)
  {
    /* END Msg(4:0303)-2  */
    /* Initialize the loop count value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* START Msg(2:3892)-5 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Write the value to unmask CVMOUT output in diagnosis mode */
    MCU_PROTECTEDWRITE(MCU_CVMDMASK, MCU_ZERO, MCU_PROTCMDCVM,
                                  MCU_PROTSCVM, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
    /* Implements MCU_ESDD_UD_062 */
    /* START Msg(2:3416)-8  */
    /* MISRA Violation: START Msg(4:0303)-2 */
    MCU_REG_WRITE_VERIFY_INIT(MCU_CVMDMASK, MCU_ZERO, MCU_8BIT_MASK,
                                                                  MCU_INIT_SID)
    /* END Msg(4:0303)-2  */
    /* END Msg(2:3416)-8  */
    /* END Msg(2:3892)-5  */
  }
  else
  {
    LenReturnValue = E_NOT_OK;
  }
  return LenReturnValue;
}
/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
