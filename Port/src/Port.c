/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port.c                                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* API function implementations of PORT Driver                                */
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

/*Implements EAAR_PN0034_NR_0045*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.0.1:  27-Sep-2012  : As per SCR 018, following changes are made:
 *                         1. Port_InitConfig API is updated to correct PPCMD
 *                            register size.
 *                         2. Port_SetPinMode API is updated to remove the
 *                            condition check of 'INPUT' PortType for DET Error
 *                            Reporting.
 *                         3. Port_SetPinMode API is updated to remove condition
 *                            check for mode range.
 *                         4. Port_SetPinDirection API is updated to remove the
 *                            condition check of 'INPUT' PortType for DET Error
 *                            Reporting.
 *                         5. Port_InitConfig API is updated to remove condition
 *                            check for LenReturnValue which is not necessary.
 *                         6. Comments are updated.
 *
 * V1.0.2:  17-Oct-2012  : As per SCR 027, following changes are made:
 *                         1. Port_Init API is updated to invoke
 *                            Port_FilterConfig() API for configuration of
 *                            filter registers.
 *                         2. Port_FilterConfig() API is added.
 *                         3. Port_Filter prototype is added under Function
 *                            Prototypes section.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, the following changes are made:
 *                         1.In API Port_Init, PORT_PIN_STATUS_BACKUP
 *                           Pre-compile option and DeepStop mode features are
 *                           updated.
 *                         2.In API Port_InitConfig, Restore registers variable
 *                           are updated with pre-compile option.
 *                         3. Copyright information is updated.
 *
 * V1.2.0:  11-Mar-2013  : As per SCR 091 for mantis #9240, following changes
 *                         are made:
 *                         1. Two APIs 'Port_SetToDioMode' and
 *                            'Port_SetToAlternateMode' are added.
 *                         2. Internal functions Port_SetToDioOrAltMode and
 *                            Port_SearchDioAltModePin are added.
 *
 * V1.2.1:  26-Apr-2013  : As per SCR 155 for mantis #6426,
 *                         PORT_DEM_ERROR_DETECT pre-compile check is added for
 *                         DEM error.
 *
 * V1.2.2:  12-Jun-2013  : As per SCR 177, Pre-compile options updated  while
 *                         merging with R4.0
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11895 and #11215, following changes
 *                         are made:
 *                         1. Port_InitConfig API is updated for the following
 *                            changes:
 *                            a. PUCC register is added.
 *                            b. PPCMD_32BIT_REG_AVAILABLE Pre-compile option is
 *                               added to support PPCMDn register bit size.
 *                         2. Header and Environment sections are updated to
 *                            change the device name.
 *                         3. Port_FilterConfig API is updated for the following
 *                            changes:
 *                            a. Pre-compile option PORT_EDGE_DETECT_CONTROL is
 *                               added to have digital Noise filter edge detect
 *                               control functionality.
 *                            b. Pre-compile option PORT_DNFAEN_REG_AVAILABLE is
 *                               added to have DNFAnEN register for F1x variant.
 *                         4. Port_Init API is updated to add Pre-compile option
 *                            PORT_IOHOLD_FUNC_AVAILABLE for IOHOLD
 *                            functionality.
 *
 * V1.4.0:  06-Sep-2013  : As per CR 236 for mantis #12110 and #12602, following
 *                         changes are made:
 *                         1. PORT_E_WRITE_FAILURE is changed to
 *                            PORT_E_WRITE_TIMEOUT_FAILURE for DEM error
 *                            reporting.
 *                         2. Port_InitConfig API is updated to add PUCC and
 *                            PINV registers.
 *                         3. Port_SetPinDirection API is updated to add
 *                            Pre-compile option 'PORT_PINV_REG_AVAILABLE' to
 *                            have Port pin level inversion functionality.
 *                         4. Endless loop exit is implemented using macro
 *                            PORT_LOOP_TIMEOUT.
 *
 * V1.4.1:  18-Nov-2013  : As per CR 295, Port_SetPinDirection API is updated
 *                         to remove PORT_OS_BASE_ADDRESS_ANALOG from Analog
 *                         port group.
 *
 * V1.4.2:  09-Dec-2013  : As per CR 338, Following changes are made:
 *                         1. Misra C violation is updated for Cast between a
 *                            pointer to volatile object and an integral type.
 *                         2. Endif comments added for PORT_PINV_REG_AVAILABLE
 *                            and PORT_DEV_ERROR_DETECT.
 *
 * V1.4.3:  27-Jan-2014  : As per CR 369, Comment modified for value of Mode
 *                         from adding 6 to 0x0E.
 *
 * V1.4.4:  04-Feb-2014  : As per CR 378 for mantis #19208, as part of merging
 *                         activity following changes are made:
 *                         1. File version information is updated.
 *                         2. Port_Init API is updated to correct conditional
 *                            check for PORT_DBTOC_VALUE.
 *
 * V1.5.0:  21-Feb-2014  : As per CR 419 for mantis #19676, following changes
 *                         are made:
 *                         1. Two APIs 'Port_SetPinDefaultDirection' and
 *                            'Port_SetPinDefaultMode' are added.
 *                         2. PORT_CRITICAL_SECTION_PROTECTION is added for
 *                            Port_SetPinDirection, Port_InitConfig,
 *                            Port_RefreshPortInternal, Port_SetToDioOrAltMode.
 *
 * V1.5.1:  29-Apr-2014  : As per CR 491 for mantis #20657, #21388 and #21668,
 *                         following changes are made:
 *                         1. End comment for Port_SetPinDefaultMode is updated
 *                            from Port_SetPinMode.
 *                         2. Typos with the code comments and alignment are
 *                            updated.
 *                         3. Critical Section Protection for
 *                            Port_SetToDioOrAltMode is updated.
 *
 * V1.5.2:  03-Jul-2014  : As per CR 543 for mantis #22125 and 22038, following
 *                         changes are made:
 *                         1. In Port_SetToDioOrAltMode API, PORT_PUBLIC_CODE is
 *                            updated to PORT_PRIVATE_CODE.
 *                         2. In API Port_InitConfig, pre-compile check
 *                            PORT_PIN_STATUS_BACKUP is added for
 *                            PORT_JTAG_PORT_GROUPS_AVAILABLE and
 *                            PORT_INPUT_PORT_GROUPS_AVAILABLE.
 *                         3. Tab space is removed.
 *
 * V1.5.3:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, following changes are made:
 *                         1. Equivalence Test is carried out throughout the
 *                            file to have a constants on the left hand side of
 *                            the check.
 *                         2. AUTOSAR violations and SWS Requirements are
 *                            mapped.
 *                         3. Port_FilterConfig API is updated to add
 *                            Pre-compile option PORT_DNF_CLK_SRC_AVAILABLE to
 *                            have digital Noise filter clock source
 *                            functionality.
 *                         4. Code is updated for Hardware Register Access
 *                            using volatile pointer.
 *
 * V1.5.4:  22-Aug-2014  : As per CR 570, following changes are made:
 *                         1. Port_SetPinDefaultMode and
 *                            Port_SetPinDefaultDirection API's are modified to
 *                            update the register functionality.
 *                         2. MISRA C Rule Violations are updated as per QAC
 *                            8.1.1.
 *                         3. Global Variable is updated for
 *                            Port_SetToDioOrAltMode.
 *
 * V1.5.5:  10-Oct-2014  : As per CR 638, following changes are made:
 *                         1. Msg(4:2986) has been removed from MISRA C Rule
 *                            Violations and from the file.
 *                         2. PORT_ALPHA_PORT_GROUPS_AVAILABLE for type casting.
 *                         3. Msg(4:1891) has been added in respective places.
 *                         4. Port_SetPinDefaultDirection description has been
 *                            updated.
 *
 * V1.5.6:  28-Jan-2015  : As per Mantis #25131,#24335,#25147,#23322,#25484
 *                         #24138,#23493,#24167 following changes are made:
 *                         1. Port_SetPinMode API is modified to update the
 *                            PIPC and PSR register functionality.
 *                         2. Port_SetToDioOrAltMode API is modified to add
 *                            checks for availability of ANALOG and INPUT Port
 *                            groups and PIPC register functionality.
 *                         3. Port_InitConfig() API is modified to add
 *                            'LenReturnValue' check in while-loop processing.
 *                            Register initialization sequence is updated.
 *                         4. Port_SetPinDirection API is updated to check for
 *                            requested and current direction.
 *                         5. Port_SetPinDirection and Port_Init API are
 *                            updated for  DEM error checks
 *                         6. Copyright information is updated.
 *                         7. Port_FilterConfig API is updated to add delay
 *                            after enabling the digital filter.
 *                         8. Port_InitConfig() API is modified for register
 *                            initialization sequence
 *                         9. Port_SetPinDefaultMode API is updated to check for
 *                            mode and direction before updating PSR register.
 *
 * V1.5.7     12-Feb-2015   As per merge activity(#26024), following changes are
 *                         adapted from R1x and P1x.
 *                         1. Port_SetInitialValue() API is added.
 *                         2. PPROTS_32BIT_REG_AVAILABLE Pre-compile option is
 *                            added to support PPROTSn register size in API's
 *                            Port_InitConfig() and Port_SetPinDirection().
 *                         3. volatile is added for variables which holds
 *                            register addresses.
 *                         4. Port_InitConfig() API is modified to add
 *                            'LenReturnValue' check in while-loop processing.
 *                         5. Port_InitConfig() API is updated to add PIBC, PU,
 *                            PBDC, PIS, PIPC register values.
 *                         6. Port_SetPinDefaultMode() API is updated to change
 *                            the order of register setting.
 *
 * V1.5.8     25-Mar-2015   Following Changes are made:
 *                          1.Static Analysis done and all Misra violations are
 *                            justified.
 *                          2.To justify the misra violation, Ecode is updated
 *                            form "LpPMSRReg = PORT_ZERO" to
 *                            "LpPMSRReg = NULL_PTR".
 * V1.5.9     09-Apr-2015   Following Changes are made:
 *                          1.Datatype of local variables LucNoOfRegs and
 *                            LblJtag changed from "volatile uint" to "uint".
 *                          2."Else" statement is added for following "If"
 *                          statement
 *                          "if (PORT_REG_NOTAVAILABLE !=
 *                                     LpSetPinModeGroupStruct->ucPIPCRegIndex)"
 *                          in "Port_SetPinMode" API.
 * V1.5.10:  12-Apr-2016  : Following changes are done
 *                         1.Copyright information is updated.
 *                         2.As per ARDAAAE-1173, Port_InitConfig API is
 *                           modified to  move PINV initialization before
 *                          (PFC,PFCE,PFCAE),right after (PODC, PODCE, PDSC and
 *                          PUCC).
 *                         3.As per ARDAAAE-1395, Port_FilterConfig API is
 *                           modified to declare "LpFCLAReg" pointer outside of
 *                           "PORT_DNFA_REG_CONFIG" precompile switch.
 *                         4.As per ARDAAAE-1089, Port_SetToDioOrAltMode API
 *                           updated to initialize LpFuncCtrlReg variable. Also
 *                           conditional check 'if(NULL_PTR != LpFuncCtrlReg)'
 *                           is added to avoid access to uninitialized local
 *                           variables.
 *                         5.As per ARDAAAE-1373, Port_SetPinDefaultDirection
 *                           and Port_SetPinMode  Apis are updated to add
 *                           check for PMSR register availability before
 *                           accessing the register.
 *                         6.As per ARDAAAE-1018,
 *                           Port_SetPinMode  Api is updated for proper
 *                           handling of PSR register and Port_SetPinDefaultMode
 *                           Api is updated for handling PFC,PFCE,PFCAE and PMSR
 *                           reg and PSR handling is removed.
 *                         7.As per ARDAAAE-1368, Port_SetPinDirection  and
 *                           Port_InitConfig APIs are modified to correct the
 *                           implementation  Register write protection sequence
 *                         8.As per ARDAAAE-1759, Port_SetPinDefaultMode  and
 *                           Port_SetToDioOrAltMode APIs are modified  to handle
 *                           the PIPC register.
 *                         9.As per ARDAAAE-1465, Port_SetPinDefaultMode  and
 *                           Port_SetToDioOrAltMode APIs are modified to add
 *                           check for register availability before updating
 *                           the PIPC register.
 *                         10. The justifications are provided for the MISRA
 *                            violations and messages
 *                            2:3227, 2:8214, 2:3892, 2:3204, 2:2824,
 *                            2:0862, 4:2991,4:2995 are added.
 *                            2:4397 changed to 4:4397
 *                         11.As per ARDAAAE-1565, 'volatile' keyword is added
 *                            in all apis where hardware registers are accessed.
 *                         12.As per ARDAAAE-1821 added PORT_UT_001 Start and
 *                            End tags after Unit testing.
 * V1.5.11:  08-Aug-2016 : As Part of V4.01.01 release,Following changes
 *                         are done
 *                        1.Internal functions Port_HWInitConfig,
 *                          Port_OpenDrainCtrlRegInit,Port_DriveUnivCtrlRegInit,
 *                          Port_PinModeDetCheck,Port_OutputLevelInvRegInit,
 *                          Port_PinDirectionDetCheck,
 *                          Port_PinModeHWRegSet,Port_PinModeCtrlRegSet,
 *                          Port_PinModeFuncRegSet,Port_PinDefModeFuncRegSet and
 *                          Port_PinDefModeDetCheck are added for software
 *                          metrics improvement.
 *                        2.As per ARDAAAE-1950,PORT_DEM_ERROR_DETECT macro has
 *                          been removed.
 *                        3.As per ARDAAAE-1663,All Apis are updated to
 *                          implement the Fusa requirements
 *                          EAAR_PN0034_FSR_0001,0002,0003 and 0004
 *                        4.As per ARDAAAE-1873, function Port_SetInitialValue
 *                          is removed.
 *                        5.MISRA warning 4:4397 is removed.
 *                        6.QAC warning messages are given under separate
 *                          section and all the warning messages are
 *                          re-numbered.
 *                        7.As per ARDAAAE-1484, Port_GetVersionInfo is
 *                          implemented as a function.
 *                        8.As per ARDAAAE-912, usDNFAEN is changed to ucDNFAENL
 *                           in the function Port_FilterConfig.
 *                        9.As per ARDAAAE-1836,Enter and Exit of critical
 *                          section protection is corrected in
 *                          Port_SetPinDefaultDirection API.
 *                        10.As per ARDAAAE-1835,accessing the pointer
 *                           LulOsBaseAddress before initialization is corrected
 *                           in Port_InitConfig() function.
 *                        11.PORT_UT_001 Start and End tags are removed from
 *                           Port_RefreshPortInternal and Port_InitConfig after
 *                           Unit testing.
 *                        12. As per ARDAAAE-1908, ASR3.2.2 version information
 *                            is removed and the functions Port_FilterConfig,
 *                            Port_DriveUnivCtrlRegInit,Port_SetPinDirection,
 *                            Port_OutputLevelInvRegInit, Port_GetVersionInfo
 *                            Port_InitConfig and Port_OpenDrainCtrlRegInit
 *                            are updated.
 *                        13. As per ARDAAAE-1936,unit design ID and requirement
 *                            tags are added at applicable places.
 * V1.5.12:  31-Aug-2016: 1.As per ARDAAAE-2018,return type of Port_InitConfig
 *                          is made Std_ReturnType.Port_Init()is updated.
 *                          Protected registers inside the functions
 *                          Port_OutputLevelInvRegInit,Port_SetPinDirection,
 *                          Port_DriveUnivCtrlRegInit, Port_OpenDrainCtrlRegInit
 *                          are written using the macro Port_ProtectedWrite.
 * V1.5.13:  01-Feb-2017: Following changes are made as per ARDAAAE-2276
 *                        1.Write verify check on PSR register is updated in
 *                          the function Port_PinModeHWRegSet.
 *                        2.Missing UD IDs are added
 *                        3.Macro Port_ProtectedWrite is changed to upper case
 *                        4.Typecasting to PORT_DEM_TYPE is removed in the
 *                          Dem_ReportErrorStatus call
 *                        5.Port_SetToDioOrAltMode() is updated
 *                        6.Multiplication operator is replaced with AND in
 *                          the functions Port_DriveUnivCtrlRegInit
 *                          Port_SetPinDirection and Port_OpenDrainCtrlRegInit
 *                        7.Unwanted MISRA violations (4:2962) and (4:1891) are
 *                          removed
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Port.h inclusion and macro definitions */
/*Implements PORT131, EAAR_PN0034_FR_0052, EAAR_PN0034_FR_0065, PORT129*/
/*Implements EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0012, EAAR_PN0034_NR_0018*/
/*Implements EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0020*/
/*Implements AR_PN0062_FR_0005, AR_PN0062_NR_0004, AR_PN0062_NR_0003*/
/*Implements AR_PN0062_NR_0002, AR_PN0062_NR_0001, EAAR_PN0034_FR_0018*/
/*Implements EAAR_PN0034_FR_0021, EAAR_PN0034_FR_0064, EAAR_PN0034_NR_0007*/
/*Implements PORT207*/
#include "Port.h"
#include "Port_PBTypes.h"
#include "Port_RegWrite.h"
/*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
/*Implements PORT130, PORT131*/
#include "Det.h"
#endif

/*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
/*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
/*Implements PORT_ESDD_UD_005*/
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */

/*Implements PORT130, PORT131, PORT075*/
#include "SchM_Port.h"
#endif
/*Implements PORT204, PORT115*/
/* Included for declaration of the function Dem_ReportErrorStatus() */
/*Implements PORT115, PORT116*/
#include "Dem.h"
/* Included for RAM variable declarations */
#include "Port_Ram.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/*Implements PORT114*/
/* AUTOSAR release version information */
#define PORT_C_AR_RELEASE_MAJOR_VERSION     PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_C_AR_RELEASE_MINOR_VERSION     PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_C_AR_RELEASE_REVISION_VERSION \
                                         PORT_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define PORT_C_SW_MAJOR_VERSION    1U
#define PORT_C_SW_MINOR_VERSION    5U
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/*Implements PORT114, EAAR_PN0034_FR_0055*/
#if (PORT_AR_RELEASE_MAJOR_VERSION != PORT_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port.c : Mismatch in Release Major Version"
#endif
#if (PORT_AR_RELEASE_MINOR_VERSION != PORT_C_AR_RELEASE_MINOR_VERSION)
  #error "Port.c : Mismatch in Release Minor Version"
#endif
#if (PORT_AR_RELEASE_REVISION_VERSION != PORT_C_AR_RELEASE_REVISION_VERSION)
  #error "Port.c : Mismatch in Release Revision Version"
#endif

#if (PORT_SW_MAJOR_VERSION != PORT_C_SW_MAJOR_VERSION)
  #error "Port.c : Mismatch in Software Major Version"
#endif
#if (PORT_SW_MINOR_VERSION != PORT_C_SW_MINOR_VERSION)
  #error "Port.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*Implements EAAR_PN0034_NR_0002, EAAR_PN0034_NR_0026*/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : Data access of larger data types is used to achieve        */
/*                 better throughput.                                         */
/* Verification  : However, part of the code is verified manually and         */
/*                 it is not having any impact.                               */
/* Reference     : Look for MISRA Violation: START Msg(4:0759)-1 and          */
/*                 MISRA Violation: END Msg(4:0759)-1 tags in the code.       */

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
/* Reference     : Look for MISRA Violation: START Msg(4:0303)-2 and          */
/*                 MISRA Violation: END Msg(4:0303)-2 tags in the code.       */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) [I] Cast between a pointer to object and an       */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for MISRA Violation: START Msg(4:0306)-3 and          */
/*                 MISRA Violation: END Msg(4:0306)-3 tags in the code.       */

/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:0488) Performing Pointer arithmetic.                    */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : This is to get the ID in the data structure in the code.   */
/*Verification   : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/*Reference      : Look for MISRA Violation: START Msg(4:0488)-6 and          */
/*                 MISRA Violation: END Msg(4:0488)-6  tags in the code.      */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) The integer value 1 is being added or             */
/*                  subtracted from a pointer.                                */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Increment operator is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for MISRA Violation: START Msg(4:0489)-7 and          */
/*                 MISRA Violation: END Msg(4:0489)-7 tags in the code.       */

/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                  result is always '0'.                                     */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : The value of the result will be calculated based on the    */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for MISRA Violation: START Msg(4:2984)-8 and          */
/*                 MISRA Violation: END Msg(4:2984)-8 tags in the code.       */
/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for MISRA Violation: START Msg(4:0857)-9 and          */
/*                 MISRA Violation: END Msg(4:0857)-9 tags in the code.       */
/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3393) Extra parentheses recommended. An arithmetic      */
/*                 operation (* / + -) is the operand of a different operator */
/*                 with the same precedence.                                  */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : parentheses is applied to calculate the register address   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for MISRA Violation: START Msg(4:3393)-10 and         */
/*                 MISRA Violation: END Msg(4:3393)-10 tags in the code.      */

/******************************************************************************/
/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2991) The value of this 'if' controlling expression     */
/*                 is always 'true'.                                          */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The if condition is present to check for incorrect input   */
/*                 paramter and condition shall be false for invalid parameter*/
/*                 and also depends on configuration                          */
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for START Message(4:2991)-12 and                      */
/*                 END Message(4:2991)-12 tags in the code.                   */

/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The if condition is present to check for incorrect input   */
/*                 paramter and condition shall be false for invalid parameter*/
/*                 and also depends on configuration                          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-13 and                          */
/*                 END Msg(4:2995)-13 tags in the code.                       */

/******************************************************************************/
/*Implements EAAR_PN0034_NR_0060*/
/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       :(2:0862) #include "MemMap.h" directive is redundant.        */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/******************************************************************************/
/* 2. QAC Warning:                                                            */
/* Message       : (2:2824) Arithmetic operation on NULL pointer.             */
/* Rule          : NA                                                         */
/* Justification : The Pointers are initialized with values from generated    */
/*                 Post Build files which depends on configurations and       */
/*                 therefore are not NULL pointers.                           */
/* Verification  : The part of the code is verified manually and it is        */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2824)-2 and              */
/*                 QAC Warning: END Msg(2:2824)-2  tags in the code.          */
/******************************************************************************/
/* 3. QAC Warning:                                                            */
/* Message       : (2:2814) Dereference of NULL pointer.                      */
/* Rule          : NA                                                         */
/* Justification : The Pointers are assigned to values generated using        */
/*                 configurations in Post Build files and hence dereferencing */
/*                 of NULL pointer shall never occur.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:2814)-3 and              */
/*                 QAC Warning: END Msg(2:2814)-3 tags in the code.           */

/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Rule          : NA                                                         */
/* Justification : This is done to change the behaviour of  the expression    */
/*                 so as to get the correct value(of similar size) assigned   */
/*                 to the RHS.                                                */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for QAC Warning: START Msg(2:3892)-4 and              */
/*                 QAC Warning: END Msg(2:3892)-4 tags in the code.           */

/******************************************************************************/
/* 5. QAC Warning:                                                            */
/* Message       : (2:3227) The parameter of the function is never            */
/*                 modified and so it could be declared with the 'const'      */
/*                 qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR APIs and Vendor specific*/
/*                 APIs cannot be modified to be made as constant as it would */
/*                 against the requirements                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning: START Msg(2:3227)-5 and              */
/*                 QAC Warning: END Msg(2:3227)-5 tags in the code.           */
/******************************************************************************/

/*******************************************************************************
**                  Function Prototypes                                       **
*******************************************************************************/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
     (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_InitConfig
                        (CONST(Port_GroupType,AUTOMATIC) LenGroupType);
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_HWInitConfig
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType);
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_OpenDrainCtrlRegInit
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType);
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_DriveUnivCtrlRegInit
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType);

#endif

#if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_OutputLevelInvRegInit
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType);

#endif
#if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_FilterConfig(void);
#endif

/*Implements PORT100, PORT107, PORT211, AR_PN0062_FR_0043*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON) || \
                         (PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON)
STATIC
FUNC(P2CONST(Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST),
    PORT_PRIVATE_CODE) Port_SearchDirChangeablePin(CONST(Port_PinType,
    AUTOMATIC) LddPinNumber, CONSTP2CONST(Port_PinsDirChangeable, AUTOMATIC,
    PORT_CONFIG_CONST)LpStartPtr, CONST(uint8, AUTOMATIC) Lucsize);
#endif

STATIC FUNC (void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
                             (CONST(Port_GroupType, AUTOMATIC) LenGroupType);

#if ((PORT_SET_PIN_MODE_API == STD_ON) || \
                              (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON))
STATIC
FUNC(P2CONST(Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
    PORT_PRIVATE_CODE) Port_SearchModeChangeablePin(CONST(Port_PinType,
    AUTOMATIC) LddPinNumber, CONSTP2CONST(Port_PinModeChangeableDetails,
    AUTOMATIC, PORT_CONFIG_CONST)LpStartPtr, CONST(uint8, AUTOMATIC) Lucsize);
#endif

#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
STATIC
FUNC(P2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
  PORT_PRIVATE_CODE) Port_SearchDioAltModePin(CONST(Port_PinType, AUTOMATIC)
  LddPinNumber, CONSTP2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC,
  PORT_CONFIG_CONST) LpStartPtr, CONST(uint8, AUTOMATIC) Lucsize);

STATIC FUNC (void, PORT_PRIVATE_CODE) Port_SetToDioOrAltMode
(CONST(Port_PinType,AUTOMATIC) Pin,
 CONST(boolean,AUTOMATIC) LblDioMode);
#endif

/*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#if (PORT_SET_PIN_MODE_API == STD_ON)
STATIC FUNC (Std_ReturnType, PORT_PRIVATE_CODE) Port_PinModeDetCheck
     (CONST(Port_PinType, AUTOMATIC) Pin,
      CONST(Port_PinModeType, AUTOMATIC ) Mode);
#endif /*#if (PORT_SET_PIN_MODE_API == STD_ON)*/
/*Implements AR_PN0062_FR_0043*/
#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))
STATIC FUNC (Std_ReturnType, PORT_PRIVATE_CODE) Port_PinDefModeDetCheck
     (CONST(Port_PinType, AUTOMATIC) Pin);
#endif /*#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
STATIC FUNC (Std_ReturnType, PORT_PRIVATE_CODE) Port_PinDirectionDetCheck
(CONST(Port_PinType,AUTOMATIC) Pin );
#endif /*#if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/
#endif /*#if (PORT_DEV_ERROR_DETECT == STD_ON)*/


#if (PORT_SET_PIN_MODE_API == STD_ON)
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinModeHWRegSet
  (CONST(Port_PinType, AUTOMATIC) Pin,
   CONST(Port_PinModeType, AUTOMATIC) Mode);
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinModeCtrlRegSet
  (CONST(Port_PinType, AUTOMATIC) Pin,
   CONST(Port_PinModeType, AUTOMATIC) LucMode);
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinModeFuncRegSet
   (CONST(Port_PinType, AUTOMATIC) Pin,
   CONST(Port_PinModeType, AUTOMATIC) LucMode);
#endif /*#if (PORT_SET_PIN_MODE_API == STD_ON)*/


#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinDefModeFuncRegSet
   (CONST(Port_PinType, AUTOMATIC) Pin);
#endif /*#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))*/

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
**                  Function Definitions                                      **
*******************************************************************************/
/*Implements PORT005, PORT140, PORT071, AR_PN0062_FR_0044, PORT128_Conf*/
/*Implements PORT129_Conf, PORT130_Conf, EAAR_PN0034_FR_0037*/
/*Implements EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0049, EAAR_PN0034_FR_0063*/
/*******************************************************************************
** Function Name         : Port_Init
**
** Service ID            : 0x00
**
** Description           : This service performs initialization of the PORT
**                         Driver components.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : ConfigPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError, Port_InitConfig, Port_FilterConfig.
**
** Registers Used        : None
*******************************************************************************/
/*Implements PORT131 */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Initialize the Port Driver module */

/*Implements PORT_ESDD_UD_009, PORT_ESDD_UD_002, PORT004, PORT079, PORT081*/
/*Implements PORT001, PORT041, PORT078, PORT042, PORT213, PORT003*/

/* QAC Warning: START Msg(2:3227)-5 */
FUNC (void, PORT_PUBLIC_CODE) Port_Init
(P2CONST (Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr)
{
  /* QAC Warning: END Msg(2:3227)-5 */

  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
     (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
  /* Variable to store the return value */
  Std_ReturnType LenReturnValue;
  #endif
  /*If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions */

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Implements PORT077, PORT105, PORT121*/
  /* Report to DET, if the config pointer value is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /*Implements  PORT087,PORT146 */
    /* Report to DET */
    (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                            PORT_E_PARAM_CONFIG);
  } /* End of ConfigPtr == NULL_PTR */
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    if ((uint32)PORT_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    /* QAC Warning: END Msg(2:2814)-3 */
    {
      /* Assign the config pointer value to global pointer */
      /*Implements PORT_ESDD_UD_073*/
      Port_GpConfigPtr = ConfigPtr;

      #if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
      /* Invoking Port_FilterConfig() for configuration of filter registers */
      /*Implements PORT043*/
      Port_FilterConfig ();
      #endif /* End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
              * (PORT_FCLA_REG_CONFIG == STD_ON) */

      /* Check for available Port Group Type(Numeric Port) */
      /*Implements PORT_ESDD_UD_102*/
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Numeric Port Group data */
      LenReturnValue = Port_InitConfig (PORT_GROUP_NUMERIC);
      if (E_OK == LenReturnValue)
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        /* Check for available Port Group Type(JTag Port) */
        /*Implements PORT_ESDD_UD_088*/
        /*Implements AR_PN0062_FR_0023*/
        #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
        /* Invoking Port_InitConfig() API with JTag Port Group data */
        LenReturnValue = Port_InitConfig (PORT_GROUP_JTAG);
        if (E_OK == LenReturnValue)
        #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          /* If DET is enabled, the API parameter checking shall be performed
          * according to the respective functions  */

          /*Implements PORT_ESDD_UD_106*/
          #if (PORT_DEV_ERROR_DETECT == STD_ON)
          /* Set the Port status to initialized */
          Port_GblDriverStatus = PORT_INITIALIZED;
          #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
        }
        #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
        else
        #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          /* No action required */
        }
      }
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      else
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        /* No action required */
      }
    }
    /*If there is no valid database is present */
    else
    {
      /* If DET is enabled, the API parameter checking shall be performed
       * according to the respective functions */

      /*Implements PORT_ESDD_UD_106*/
      /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /*Implements PORT038, PORT077, PORT146, AR_PN0062_FR_0008*/
      /* Report to DET */
      (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                          PORT_E_INVALID_DATABASE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    }
  }
} /* End of API Port_Init */
/*Implements PORT131, PORT137, PORT138*/
#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT141, PORT054, PORT063, PORT131_Conf, AR_PN0062_FR_0041*/
/*Implements PORT125_Conf, PORT126_Conf, PORT134_Conf, AR_PN0062_FR_0048*/
/*Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049, AR_PN0062_FR_0004*/
/*Implements AR_PN0062_FR_0006, AR_PN0062_FR_0021*/
/*******************************************************************************
** Function Name         : Port_SetPinDirection
**
** Service ID            : 0x01
**
** Description           : This service sets the port pin direction during
**                         runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Direction - Port Pin Direction
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_Init().
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : SchM_Enter_Port_PORT_SET_PIN_DIR_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_DIR_PROTECTION,
**                         Port_SearchDirChangeablePin,
**                         Port_PinDirectionDetCheck,
**                         Dem_ReportErrorStatus
**
** Registers Used        : PSRn,JPSR0,PMSRn,PINVn,JPMSR0,PPCMDn,PPROTSn.
*******************************************************************************/
/* The function Port_SetPinDirection shall be available if the pre-compile
 * parameter PortSetPinDirectionApi is set to TRUE
 */
/*Implements PORT086*/
/*Implements PORT_ESDD_UD_082*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/*Implements PORT131*/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_087, PORT079*/

/* QAC Warning: START Msg(2:3227)-5 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDirection
(Port_PinType Pin, Port_PinDirectionType Direction)
{
/* QAC Warning: END Msg(2:3227)-5 */
  P2CONST(volatile Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
                                                           LpChangeablePinDet;
  /*Implements PORT_ESDD_UD_014*/
  #if (PORT_PINV_REG_AVAILABLE == STD_ON)
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPROTSRegAdd;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpFourByteRegAddress;
  uint32 LulNumeric;
  uint32 LulJtag;
  uint32 LulOsBaseAddress;
  uint8 LucLoopCount;
  uint8 LucPortGroupIndex;
  uint32 LulPINVRegValue;
  #endif /* End of (PORT_PINV_REG_AVAILABLE == STD_ON) */

  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;
  /* MISRA Violation: END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint16 LusCurrentDirection;

  /* Variable to store the return value */
  Std_ReturnType LenReturnValue;
  /*Initialize with Zero*/
  LulNumeric = PORT_LONG_WORD_ZERO;
  LulJtag = PORT_LONG_WORD_ZERO;

  /* If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions */

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  LenReturnValue = Port_PinDirectionDetCheck(Pin);
  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);
    /* QAC Warning: END Msg(2:2814)-3 */
    if (NULL_PTR != LpChangeablePinDet  )
    {
      /* Get the base address of the corresponding Port Type */
      /*Implements PORT_ESDD_UD_088*/
      /*Implements PORT_ESDD_UD_102*/
      /*Implements AR_PN0062_FR_0023*/
      #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
      if ((uint8)PORT_GROUP_NUMERIC == LpChangeablePinDet->ucPortType)
      {
        /* Get the Base address of Numeric Port */
        /*Implements AR_PN0062_FR_0026*/
        /*Implements PORT_ESDD_UD_016*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
        /*Implements PORT_ESDD_UD_014*/
        #if (PORT_PINV_REG_AVAILABLE == STD_ON)
        /* Get the pointer to the Numeric Port registers */
        LpPortReg = Port_GpConfigPtr->pPortNumRegs;
        /* Get the Base address of Numeric Port */
        /*Implements PORT_ESDD_UD_017*/
        LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
        LulNumeric = PORT_SET_LONG_WORD;
        #endif /* End of PORT_PINV_REG_AVAILABLE == STD_ON */
      }
      else
      {
        /* Get the Base address of JTag Port */
        /*Implements PORT_ESDD_UD_018*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        /*Implements PORT_ESDD_UD_014*/
        #if (PORT_PINV_REG_AVAILABLE == STD_ON)
        /* Get the pointer to the JTag Port registers */
        LpPortReg = Port_GpConfigPtr->pPortJRegs;
        /* Get the Base address of JTag Port */
        /*Implements PORT_ESDD_UD_019*/
        LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
        LulJtag = PORT_SET_LONG_WORD;
        #endif /* End of PORT_PINV_REG_AVAILABLE == STD_ON */
      }
      /*Implements AR_PN0062_FR_0023*/
      #endif /* #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
                   (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */

      /* Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
       * variable to 1 of the configured pin whose Direction has to be changed
       */
      LunSRRegContent.Tst_Port_Word.usMSWord = LpChangeablePinDet->usOrMaskVal;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /*Get the current direction*/
      LusCurrentDirection = (uint16) (*((volatile uint32 *)
         (LulBaseAddress + LpChangeablePinDet->usPMSRRegAddrOffset)));
      /* MISRA Violation: END Msg(4:0303)-2 */

      /*Check if requested direction is OUTPUT and current direction is INPUT*/
      if ((PORT_PIN_OUT == Direction ) &&
          ((LusCurrentDirection & LpChangeablePinDet->usOrMaskVal) ==
           LpChangeablePinDet->usOrMaskVal))
      {
        /*Set the return value to E_OK*/
        LenReturnValue = E_OK;
        /*Implements PORT082, AR_PN0062_FR_0048*/
        /* AUTOSAR IMPL R4.0.3, PORT082 RULE VIOLATION: As per
         * requirement AR_PN0062_FR_0048 Level inversion is implemented to
         * invert the output level of a pin when the pin is in output mode*/
        /*Implements PORT_ESDD_UD_014*/
        #if (PORT_PINV_REG_AVAILABLE == STD_ON)
        LucPortGroupIndex = LpChangeablePinDet->ucPortGroupIndex;

        /* Check if pin level inversion is supported for port group */
        if ((PORT_INV_NOT_CFG != (LpChangeablePinDet->usPINVRegAddrOffset))&&
           (PORT_INV_NOT_CFG != (LpChangeablePinDet->usPortinversionVal)))
        {
          /* Initialize the loop count to ten */
          /*Implements EAAR_PN0034_FSR_0011, EAAR_PN0034_FSR_0012 */
          /*Implements EAAR_PN0034_FSR_0013 */
          /*Implements PORT_ESDD_UD_068*/
          LucLoopCount = PORT_LOOP_TIMEOUT;
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Get the register address by adding the offset to the Base address
          */
          LpFourByteRegAddress = (volatile uint32 *)
              (LpChangeablePinDet->usPINVRegAddrOffset + LulBaseAddress);
          /* MISRA Violation: END Msg(4:0303)-2 */

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:3393)-10 */
          /* MISRA Violation: START Msg(4:0488)-6 */
          /* QAC Warning: START Msg(2:2824)-2 */
          /*Implements PORT_ESDD_UD_056*/
          /*Implements PORT_ESDD_UD_059*/
          /*Implements PORT_ESDD_UD_063*/
          /*Implements PORT_ESDD_UD_066*/
          /*Implements PORT_ESDD_UD_067*/
          /* Get the address of the corresponding PPROTS register */
          LpPPROTSRegAdd = (volatile uint32 *)
              (((uint32)((LpPortReg + LucPortGroupIndex)->usRegAddrOffset) -
               (((uint32)(PORT_NUM_PINV_REG_ADD_OFFSET +
               PORT_OS_BASE_ADDRESS_OFFSET) & LulNumeric) +
               ((uint32)(PORT_JTAG_PINV_REG_ADD_OFFSET +
               PORT_OS_BASE_ADDRESS_OFFSET) & LulJtag)) + LulOsBaseAddress) +
               ((uint32)PORT_NUM_PPROTS_REG_ADD_OFFSET & LulNumeric) +
               ((uint32)PORT_JTAG_PPROTS_REG_ADD_OFFSET & LulJtag));

          /* MISRA Violation: END Msg(4:3393)-10 */
          /* MISRA Violation: END Msg(4:0303)-2 */
          /* QAC Warning: END Msg(2:2824)-2 */
          /* MISRA Violation: END Msg(4:0488)-6 */

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:3393)-10 */
          /* MISRA Violation: START Msg(4:0488)-6 */

          /* Get the address of the corresponding PPCMD register */
          /*Implements PORT_ESDD_UD_057*/
          /*Implements PORT_ESDD_UD_059*/
          /*Implements PORT_ESDD_UD_064*/
          /*Implements PORT_ESDD_UD_067*/
          LpPPCMDRegAdd = (volatile uint32 *)
              (((uint32)((LpPortReg + LucPortGroupIndex)->usRegAddrOffset) -
               (((uint32)(PORT_NUM_PINV_REG_ADD_OFFSET +
               PORT_OS_BASE_ADDRESS_OFFSET) & LulNumeric) +
               ((uint32)(PORT_JTAG_PINV_REG_ADD_OFFSET +
               PORT_OS_BASE_ADDRESS_OFFSET) & LulJtag)) + LulOsBaseAddress) +
               ((uint32)PORT_NUM_PPCMD_REG_ADD_OFFSET & LulNumeric) +
               ((uint32)PORT_JTAG_PPCMD_REG_ADD_OFFSET & LulJtag));

          /* MISRA Violation: END Msg(4:3393)-10 */
          /* MISRA Violation: END Msg(4:0303)-2 */
          /* MISRA Violation: END Msg(4:0488)-6 */

          /* QAC Warning: START Msg(2:2814)-3 */
          LulPINVRegValue = ((*LpFourByteRegAddress) |
              ((LpChangeablePinDet->usPortinversionVal) & (~PORT_MSB_MASK)));
          /* QAC Warning: END Msg(2:2814)-3 */
          /* An atomic access to Microcontroller registers by the use of an
             exclusive area         */
          /*Implements PORT075*/
          /* Enter critical section */

          /*Implements PORT_ESDD_UD_005*/
          /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
          /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DIR_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

          /*Implements PORT_ESDD_UD_051*/
          /* QAC Warning: START Msg(2:2814)-3 */
          PORT_PROTECTEDWRITE(*LpFourByteRegAddress, LulPINVRegValue,
                      *LpPPCMDRegAdd, *LpPPROTSRegAdd, LucLoopCount)
          /* QAC Warning: END Msg(2:2814)-3 */

          /* Exit critical section */
          /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
          /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DIR_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

          /* Check if the loop has exited because of failure of writing to
             register  */
          if (PORT_LONG_WORD_ONE == *LpPPROTSRegAdd)
          {
            /*Implements PORT037, PORT139, PORT146 */
            /* Report write failure production error */
            Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                            DEM_EVENT_STATUS_FAILED);
            /* Set Return Value as E_NOT_OK */
            LenReturnValue = E_NOT_OK;
          } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
          else
          {
              /* No action required */
          }
        } /* End of ((LpChangeablePinDet->usPortinversionVal) != PORT_HIGH)  &&
                 ((LpChangeablePinDet->usPortinversionVal) != PORT_HIGH)*/
        else
        {
          /* No action required */
        }
        #endif /* End of (PORT_PINV_REG_AVAILABLE == STD_ON) */

        if (E_OK == LenReturnValue)
        {
          /*Implements PORT138*/
          /* Write the Lower word contents with configured Pin Level Value */
          LunSRRegContent.Tst_Port_Word.usLSWord =
                                    LpChangeablePinDet->usChangeableConfigVal;

          /* An atomic access to Microcontroller registers by the use of an
             exclusive area         */
          /* Enter critical section */

          /*Implements PORT_ESDD_UD_005*/
          /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
          /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DIR_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Write the configured value into the register */
          PORT_REG_WRITE(*((volatile uint32 *)(LulBaseAddress +
          LpChangeablePinDet->usPSRRegAddrOffset)),LunSRRegContent.ulRegContent)
          /* MISRA Violation: END Msg(4:0303)-2 */

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* QAC Warning: START Msg(2:3892)-4 */
          /* Write verify check for PSR Register */
          PORT_REG_WRITE_VERIFY_RUNTIME(*((volatile uint32 *)(LulBaseAddress +
          LpChangeablePinDet->usPSRRegAddrOffset)),
          (LunSRRegContent.ulRegContent &
          (uint32)LpChangeablePinDet->usChangeableConfigVal),
          (LunSRRegContent.ulRegContent >> PORT_SIXTEEN), PORT_SET_PIN_DIR_SID)
          /* QAC Warning: END Msg(2:3892)-4 */
          /* MISRA Violation: END Msg(4:0303)-2 */

          /* Set the requested direction */
          LunSRRegContent.Tst_Port_Word.usLSWord =
                                           ~LpChangeablePinDet->usOrMaskVal;

          /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
           * Bit value of Lower 16 bits (15-0) of PMSR register = Configured
           * value for the corresponding pin position */
          /* MISRA Violation: START Msg(4:0303)-2 */
          PORT_REG_WRITE(*((volatile uint32 *)(LulBaseAddress +
          LpChangeablePinDet->usPMSRRegAddrOffset)),
                                   LunSRRegContent.ulRegContent)
          /*  MISRA Violation: END Msg(4:0303)-2 */

          /* Exit critical section */
          /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
          /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
          #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
          PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DIR_PROTECTION);
          #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

          /*Write verify on PMSR register*/
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* QAC Warning: START Msg(2:3892)-4 */
          PORT_REG_WRITE_VERIFY_RUNTIME(*((volatile uint32 *)(LulBaseAddress +
          LpChangeablePinDet->usPMSRRegAddrOffset)),
          (LunSRRegContent.ulRegContent &
          (uint32)LpChangeablePinDet->usOrMaskVal),
          (LunSRRegContent.ulRegContent >> PORT_SIXTEEN),PORT_SET_PIN_DIR_SID)
          /* QAC Warning: END Msg(2:3892)-4 */
          /* MISRA Violation: END Msg(4:0303)-2 */
        }
        else
        {

        }
      } /* End of Direction == PORT_PIN_OUT */
      /* Requested direction is INPUT */
      else if (PORT_PIN_IN == Direction)
      {
        LunSRRegContent.Tst_Port_Word.usLSWord =
                                      LpChangeablePinDet->usOrMaskVal;

        /* An atomic access to Microcontroller registers by the use of an
           exclusive area         */
        /* Enter critical section */

        /*Implements PORT_ESDD_UD_005*/
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DIR_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
         * Bit value of Lower 16 bits (15-0) of PMSR register = Configured
         * value for the corresponding pin position */
        PORT_REG_WRITE(*((volatile uint32 *)(LulBaseAddress +
        LpChangeablePinDet->usPMSRRegAddrOffset)),LunSRRegContent.ulRegContent)
        /* MISRA Violation: END Msg(4:0303)-2 */

        /* Exit critical section */
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DIR_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*Write verify on PMSR register*/
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* QAC Warning: START Msg(2:3892)-4 */
        PORT_REG_WRITE_VERIFY_RUNTIME(*((volatile uint32 *)(LulBaseAddress +
        LpChangeablePinDet->usPMSRRegAddrOffset)),(LunSRRegContent.ulRegContent
        & (uint32)(LpChangeablePinDet->usOrMaskVal)),
        (LunSRRegContent.ulRegContent >> PORT_SIXTEEN),PORT_SET_PIN_DIR_SID)
        /* QAC Warning: END Msg(2:3892)-4 */
        /* MISRA Violation: END Msg(4:0303)-2 */
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
  } /* End of LenReturnValue == E_OK */

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* End of (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetPinDirection */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */
/*Implements PORT066, PORT142, EAAR_PN0034_FR_0049*/
/*******************************************************************************
** Function Name         : Port_RefreshPortDirection
**
** Service ID            : 0x02
**
** Description           : This service shall refresh the direction of all
**                         configured ports to the configured direction.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError, Port_RefreshPortInternal.
**
** Registers Used        : None
*******************************************************************************/
/*Implements PORT131*/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_010*/

/*Implements PORT060*/
FUNC (void, PORT_PUBLIC_CODE) Port_RefreshPortDirection (void)
{
  /* If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions */

  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  /*Implements PORT_ESDD_UD_106*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Implements PORT077*/
  /* Check whether the PORT module is initialized */
  /*Implements PORT087*/
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
  /*Implements PORT146*/
    /* Report to DET  */
    (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
               PORT_REFRESH_PORT_DIR_SID, PORT_E_UNINIT);
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /*Implements PORT_ESDD_UD_102*/
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with Numeric Group data */
      Port_RefreshPortInternal (PORT_GROUP_NUMERIC);
    }
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
    /*Implements AR_PN0062_FR_0023*/
    /*Implements PORT_ESDD_UD_088*/
    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with JTag Group data */
      Port_RefreshPortInternal (PORT_GROUP_JTAG);
    }
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
  }
} /* End of API Port_RefreshPortDirection */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT145, AR_PN0062_FR_0041, PORT132_Conf, EAAR_PN0034_FR_0049*/
/*Implements AR_PN0062_FR_0002, AR_PN0062_FR_0013, AR_PN0062_FR_0036, PORT128*/
/*******************************************************************************
** Function Name         : Port_SetPinMode
**
** Service ID            : 0x04
**
** Description           : This function used to set the mode of a port pin
**                         during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Mode - New mode to be set on port pin.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : Port_PinModeHWRegSet,
**                         SchM_Enter_Port_PORT_SET_PIN_MODE_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_MODE_PROTECTION,
**                         Port_PinModeDetCheck,
**                         Dem_ReportErrorStatus,
**                         Port_SearchModeChangeablePin.
** Registers Used        : PIPCn.
*******************************************************************************/
/*Implements PORT_ESDD_UD_008*/
#if (PORT_SET_PIN_MODE_API == STD_ON)

/*Implements PORT131*/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_012*/

/*Implements PORT124, PORT212, PORT004, PORT079, PORT125*/
/* QAC Warning: START Msg(2:3227)-5 */
/* The type Port_PinModeType used with the function call Port_SetPinMode */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinMode
     (Port_PinType Pin, Port_PinModeType Mode)
/* QAC Warning: END Msg(2:3227)-5 */
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpModeChangeablePin;
  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;
  /* Pointer to Port Registers Data structure */
  P2CONST (volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;
  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST)LpTwoByteRegAddr;
  uint32 LulBaseAddress;

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;
  /*If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions */
  LenReturnValue = Port_PinModeDetCheck(Pin, Mode);
  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the Pin is mode changeable at run time */
    /* QAC Warning: START Msg(2:2814)-3*/
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);
    /* QAC Warning: END Msg(2:2814)-3*/
    if (NULL_PTR != LpModeChangeablePin )
    {
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the pointer to the Set Mode group list */
      LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                      + (LpModeChangeablePin->ucSetModeIndex));
      /* MISRA Violation: END Msg(4:0488)-6 */
      /* If the Pin group is of Numeric type */

      /*Implements PORT_ESDD_UD_088*/
      /*Implements PORT_ESDD_UD_102*/
      /*Implements AR_PN0062_FR_0023*/
      #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
      if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
      {
        LpPortReg = Port_GpConfigPtr->pPortNumRegs;
        /*Implements AR_PN0062_FR_0026*/
        /*Implements PORT_ESDD_UD_016*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
      } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
      else
      {
        LpPortReg = Port_GpConfigPtr->pPortJRegs;
        /*Implements PORT_ESDD_UD_018*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
      }
      #endif /* #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )      */

      /* QAC Warning: START Msg(2:2814)-3 */
      if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPIPCRegIndex)
      /* QAC Warning: END Msg(2:2814)-3 */
      {
        /* Get the PIPC register Address */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* QAC Warning: START Msg(2:2824)-2 */
        /*Implements PORT_ESDD_UD_067*/
        LpTwoByteRegAddr = (volatile uint16 *)((uint32)((LpPortReg +
                LpSetPinModeGroupStruct->ucPIPCRegIndex)->usRegAddrOffset) +
                (uint32)PORT_OS_BASE_ADDRESS_OFFSET + LulBaseAddress);
        /* QAC Warning: END Msg(2:2824)-2 */
        /* MISRA Violation: END Msg(4:0488)-6 */
        /* MISRA Violation: END Msg(4:0303)-2 */

        /* An atomic access to Microcontroller registers by the use of an
           exclusive area */
        /* Enter critical section */

        /*Implements PORT_ESDD_UD_005*/
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        if (SET_PIPC_MIN_MODE <= Mode)
        {
          /* QAC Warning: START Msg(2:2814)-3 */
          /* If bit needs to be set, OR the register contents with usOrMask */
          PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) |
                            ((uint16)LpModeChangeablePin->usOrMask)))
          /* QAC Warning: END Msg(2:2814)-3 */

          /*Write verify check on PIPC register*/
          PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,
          ((*LpTwoByteRegAddr) |((uint16)LpModeChangeablePin->usOrMask)),
                                   PORT_SET_WORD,PORT_SET_PIN_MODE_SID)

          Mode = Mode & PORT_MODE_MASK;
        }
        else
        {
          /* QAC Warning: START Msg(2:2814)-3 */
          /* If bit needs to be reset, AND  with inverted usOrMask */
          PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) &
                    ((uint16)(~LpModeChangeablePin->usOrMask))))
          /* QAC Warning: END Msg(2:2814)-3 */

          /*Write verify check on PIPC register*/
          PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,
          ((*LpTwoByteRegAddr) & ((uint16)(~LpModeChangeablePin->usOrMask))),
                                       PORT_SET_WORD,PORT_SET_PIN_MODE_SID)
        }

        /* Exit critical section */
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
      }
      else
      {
        /* No action required */
      }

      /*To change the PMSR,PMCSR,PSR and Function control register setting */
      Port_PinModeHWRegSet(Pin,Mode);

    } /* End of if(LpModeChangeablePin != NULL_PTR)*/
    else
    {
        /* No action required */
    }
  } /* End of LenReturnValue == E_NOT_OK */

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Port_SetPinMode */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* PORT_SET_PIN_MODE_API == STD_ON */

/*Implements AR_PN0062_FR_0043, EAAR_PN0034_FR_0049, AR_PN0062_FR_0038*/
/*Implements AR_PN0062_FR_0068*/
/*******************************************************************************
** Function Name         : Port_SetToDioMode
**
** Service ID            : 0x05
**
** Description           : This function used to set the mode of a port pin
**                         to DIO mode during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus
**
** Functions Invoked     : Det_ReportError, Port_SetToDioOrAltMode.
**
** Registers Used        : None
*******************************************************************************/

/*Implements PORT_ESDD_UD_047*/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/*Implements PORT131*/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_007*/
/* QAC Warning: START Msg(2:3227)-5 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetToDioMode (Port_PinType Pin)
/* QAC Warning: END Msg(2:3227)-5 */
{

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_TO_DIO_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  /*Implements PORT_ESDD_UD_081*/
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_TO_DIO_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  if (E_OK == LenReturnValue)
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke the internal function to set the requested pin to DIO mode */
    Port_SetToDioOrAltMode(Pin, PORT_TRUE);
  }

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetToDioMode */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*Implements EAAR_PN0034_FR_0049, AR_PN0062_FR_0039, AR_PN0062_FR_0067*/
/*******************************************************************************
** Function Name         : Port_SetToAlternateMode
**
** Service ID            : 0x06
**
** Description           : This function used to set the mode of a port pin
**                         to alternate mode during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus
**
** Functions Invoked     : Det_ReportError, Port_SetToDioOrAltMode.
**
** Registers Used        : None
*******************************************************************************/
/*Implements PORT_ESDD_UD_047*/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/*Implements PORT131*/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_006*/
/* QAC Warning: START Msg(2:3227)-5 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetToAlternateMode (Port_PinType Pin)
/* QAC Warning: END Msg(2:3227)-5 */
{
  /* If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions  */

  /*Implements PORT_ESDD_UD_106*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /*Implements PORT077*/
  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_TO_ALT_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  /*Implements PORT_ESDD_UD_081*/
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_TO_ALT_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  if (E_OK == LenReturnValue)
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke the internal function to set the requested pin to alternate
     * mode */
    Port_SetToDioOrAltMode(Pin, PORT_FALSE);
  }

  /*Implements PORT_ESDD_UD_106*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetToAlternateMode */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*Implements EAAR_PN0034_FR_0049, AR_PN0062_FR_0004, AR_PN0062_FR_0013*/
/*Implements AR_PN0062_FR_0069*/
/*******************************************************************************
** Function Name         : Port_SetToDioOrAltMode
**
** Service ID            : NA
**
** Description           : This function used to set the mode of a port pin
**                         during runtime to either DIO or Alternate mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number, boolean - Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Det_ReportError,Dem_ReportErrorStatus
**                         SchM_Enter_Port_PORT_SET_TO_DIO_ALT_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_TO_DIO_ALT_PROTECTION,
**                         Port_SearchDioAltModePin.
**
** Registers Used        : PMCSRn, PIPCn, JPMCSR0.
*******************************************************************************/
/*Implements PORT_ESDD_UD_047, EAAR_PN0034_FR_0049*/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/*Implements PORT131*/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_083*/
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_SetToDioOrAltMode
(CONST(Port_PinType,AUTOMATIC) Pin,
 CONST(boolean,AUTOMATIC) LblDioMode)
{
  P2CONST (Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinDioAltMode;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                              LpFuncCtrlReg;
  /* Pointer to Port Registers Data structure */
  P2CONST (volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;
  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST)LpRegAddr;
  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST)LpTwoByteRegAddr;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_DioOrAltMode LunSRRegContent;
  /* MISRA Violation: END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint8 LucPortGroupIndex;

  /*QAC Warning: START Msg(2:2814)-3 */
  /*Check whether the Pin is in Dio or Alternate mode changeable at run time */
  LpSetPinDioAltMode = Port_SearchDioAltModePin (Pin,
                             Port_GpConfigPtr->pPinDioAltModeDetails,
                             Port_GpConfigPtr->ucNoOfPinsDioAltModeChangeable);
  /* QAC Warning: END Msg(2:2814)-3 */
  if (NULL_PTR != LpSetPinDioAltMode)
  {
    /*Implements PORT_ESDD_UD_088*/
    /*Implements PORT_ESDD_UD_102*/
    /*Implements AR_PN0062_FR_0023*/
    #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
    if ((uint8)PORT_GROUP_NUMERIC == LpSetPinDioAltMode->ucPortType)
    {
      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      /*Implements AR_PN0062_FR_0026*/
      /*Implements PORT_ESDD_UD_016*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    } /* End of LpSetPinDioAltMode->ucPortType == PORT_GROUP_NUMERIC */
    else
    {
      LpPortReg = Port_GpConfigPtr->pPortJRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
      /*Implements PORT_ESDD_UD_018*/
      /*Implements AR_PN0062_FR_0023*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    }
    #endif /* #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) ||
             (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */
    /* Search for the Pin and get the index in the array
    * Port_GstSetDioAltPinDetails[]   */
    LucPortGroupIndex = LpSetPinDioAltMode->ucPortGroupIndex;

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* QAC Warning: START Msg(2:2824)-2 */
    LpRegAddr = (volatile uint32 *)
    (((LpFuncCtrlReg + LucPortGroupIndex)->usRegAddrOffset) + LulBaseAddress);
    /* QAC Warning: END Msg(2:2824)-2 */
    /* MISRA Violation: END Msg(4:0303)-2 */
    /* MISRA Violation: END Msg(4:0488)-6 */

    /* Set the bit position in the upper 16 bits (31-16) of the PMCSR
       variable to 1 of the configured pin whose Mode has to be changed */
    LunSRRegContent.Tst_Port_DioOrAlt_Word.usMSWord =
                                          LpSetPinDioAltMode->usOrMask;

    /* Write the requested direction into Lower word of PMCSR variable
    *  by using OR mask   */
    if (PORT_TRUE == LblDioMode)
    {
      LunSRRegContent.Tst_Port_DioOrAlt_Word.usLSWord =
                                        ~LpSetPinDioAltMode->usOrMask;
    }
    else
    {
      LunSRRegContent.Tst_Port_DioOrAlt_Word.usLSWord =
                                         LpSetPinDioAltMode->usOrMask;
    }

    /* Enter critical section */
    /*Implements PORT_ESDD_UD_005*/
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_SET_TO_DIO_ALT_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* QAC Warning: START Msg(2:2814)-3 */
    /* Write the corresponding 32 bit value to the PMCSR register */
    PORT_REG_WRITE (*LpRegAddr,LunSRRegContent.ulRegContent)
    /* QAC Warning: END Msg(2:2814)-3 */

    /*Write verify check on PMCSR register*/
    if (PORT_TRUE == LblDioMode)
    {
      /* QAC Warning: START Msg(2:3892)-4 */
      PORT_REG_WRITE_VERIFY_RUNTIME(*LpRegAddr,(LunSRRegContent.ulRegContent &
      LpSetPinDioAltMode->usOrMask),(LunSRRegContent.ulRegContent >>
      PORT_SIXTEEN), PORT_SET_TO_DIO_MODE_SID)
      /* QAC Warning: END Msg(2:3892)-4 */
    }
    else
    {
      /* QAC Warning: START Msg(2:3892)-4 */
      PORT_REG_WRITE_VERIFY_RUNTIME(*LpRegAddr,(LunSRRegContent.ulRegContent &
      LpSetPinDioAltMode->usOrMask),(LunSRRegContent.ulRegContent >>
      PORT_SIXTEEN), PORT_SET_TO_ALT_MODE_SID)
      /* QAC Warning: END Msg(2:3892)-4 */
    }
    /* Write PIPC register.Check for PIPC register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinDioAltMode->ucPortPIPCIndex )
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* QAC Warning: START Msg(2:2824)-2 */
      /*Implements PORT_ESDD_UD_067*/
      LpTwoByteRegAddr = (volatile uint16 *)((uint32)((LpPortReg +
          LpSetPinDioAltMode->ucPortPIPCIndex)->usRegAddrOffset) +
          (uint32)PORT_OS_BASE_ADDRESS_OFFSET + LulBaseAddress);
      /* QAC Warning: END Msg(2:2824)-2 */
      /* MISRA Violation: END Msg(4:0303)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */

      if (PORT_TRUE == LblDioMode)
      {
        /* QAC Warning: START Msg(2:2814)-3 */
        PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) &
                 ((uint16)(~LpSetPinDioAltMode->usOrMask))))
        /* QAC Warning: END Msg(2:2814)-3 */

        /*Write verify check on PIPC register*/
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) &
                 ((uint16)(~LpSetPinDioAltMode->usOrMask))), PORT_SET_WORD,
                                                   PORT_SET_TO_DIO_MODE_SID)
      }
      else
      {
        /* MISRA Violation: START Msg(4:0488)-6 */
        PORT_REG_WRITE(*LpTwoByteRegAddr,(((*LpTwoByteRegAddr)&
        (uint16)(~LpSetPinDioAltMode->usOrMask)) |(((uint16)
        (LpPortReg + LpSetPinDioAltMode->ucPortPIPCIndex)->usInitModeRegVal)&
                                              LpSetPinDioAltMode->usOrMask)))
        /* MISRA Violation: END Msg(4:0488)-6 */

        /* MISRA Violation: START Msg(4:0488)-6 */
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,(((*LpTwoByteRegAddr)&
        (uint16)(~LpSetPinDioAltMode->usOrMask)) |(((uint16)
        (LpPortReg + LpSetPinDioAltMode->ucPortPIPCIndex)->usInitModeRegVal)&
        LpSetPinDioAltMode->usOrMask)),PORT_SET_WORD,PORT_SET_TO_ALT_MODE_SID)
        /* MISRA Violation: END Msg(4:0488)-6 */
      }
    }
    else
    {
      /* do nothing*/
    }
    /* Exit critical section */
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_SET_TO_DIO_ALT_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
  }
  else
  {
    /*If DET is enabled, the API parameter checking shall be performed
    * according to the respective functions */

    /*Implements PORT_ESDD_UD_106*/
    /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /*Implements PORT077*/
    if (PORT_TRUE == LblDioMode)
    {
      /*Implements PORT146*/
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                    PORT_SET_TO_DIO_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    else
    {
      /*Implements PORT146*/
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_TO_ALT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    #endif /* (PORT_DEV_ERROR_DETECT = = STD_ON) */
  }

} /* End of API Port_SetToDioOrAltMode */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*Implements AR_PN0062_FR_0062*/
/*******************************************************************************
** Function Name         : Port_SearchDioAltModePin
**
** Service ID            : Not Applicable
**
** Description           : This function used to verify whether the given pin
**                         is Mode changeable as DIO or ALTERNATE mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPinNumber - Port Pin number
**                         LpStartPtr - Start pointer to the Changeable pin
**                         structures.
**                         Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Pointer to Mode Changeable Pin structure - if given
**                         pin number matches.
**                         NULL - If Pin number does not match.
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
/*Implements PORT_ESDD_UD_047*/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/*Implements PORT131, EAAR_PN0034_FR_0049*/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_003*/

STATIC
FUNC(P2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
  PORT_PRIVATE_CODE) Port_SearchDioAltModePin(CONST(Port_PinType, AUTOMATIC)
  LddPinNumber, CONSTP2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC,
  PORT_CONFIG_CONST) LpStartPtr, CONST(uint8, AUTOMATIC) Lucsize)
{
  P2CONST (Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_DATA)
                                                              LpRetPtr;
  uint8 LucLow;
  uint8 LucHigh;
  uint8 LucMid;
  uint16 LusListSearchId;
  LucHigh = Lucsize - PORT_ONE;
  LucLow = PORT_ONE;
  LpRetPtr = NULL_PTR;
  if (NULL_PTR != LpStartPtr )
  {
    /* QAC Warning: START Msg(2:2814)-3*/
    /* Get the lower limit of Search ID */
    LusListSearchId = LpStartPtr->ddPinId;
    /* QAC Warning: END Msg(2:2814)-3 */

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Check whether search Search-ID is in range */
    if ((LddPinNumber >= LusListSearchId) &&
       (LddPinNumber <= ((LpStartPtr + LucHigh)->ddPinId)))
    /* MISRA Violation: END Msg(4:0488)-6 */
    {
      /* Check whether requested Search-ID is same as first Search-ID
       * of the list */
      if (LddPinNumber != LusListSearchId)
      {
        do
        {
          /* QAC Warning: START Msg(2:3892)-4 */
          /* Get the middle index number */
          LucMid = (LucHigh + LucLow) >> PORT_ONE;
          /* QAC Warning: END Msg(2:3892)-4 */

          /* MISRA Violation: START Msg(4:0488)-6 */
          /* Get the Search-ID of the mid IDs */
          LusListSearchId = ((LpStartPtr + LucMid)->ddPinId);
          /* MISRA Violation: END Msg(4:0488)-6 */

          /* Compare Search-ID with the requested one */
          if (LusListSearchId == LddPinNumber)
          {
            /* MISRA Violation: START Msg(4:0488)-6 */
            /* Update the return pointer with the pin number structure */
            LpRetPtr = (LpStartPtr + LucMid);
            /* MISRA Violation: END Msg(4:0488)-6 */

            /* Set LucHigh to zero to break the loop */
            LucHigh = PORT_ZERO;
          } /* End of LusListSearchId == LddPinNumber */
          else
          {
            /* Compare the Search-ID with the requested one */
            if (LddPinNumber < LusListSearchId)
            {
              /* If the priority is lower, update LucHigh */
              LucHigh = LucMid - PORT_ONE;
            }
            else
            {
              /* If the priority is higher, update LucLow */
              LucLow = LucMid + PORT_ONE;
            }
          }
        } while (LucLow <= LucHigh);
      } /* End of LddPinNumber != LusListSearchId */
      else
      {
        /*Update the return pointer with start pointer (Matches with first Id)*/
        LpRetPtr = LpStartPtr;
      }
    } /* End of (LddPinNumber >= LusListSearchId) &&
       * (LddPinNumber <= ((LpStartPtr + LucHigh)->ddPinId))  */
    else
    {
      /* No action required */
    }
  }
  else
  {

  }
  return (LpRetPtr);
} /* End of Port_SearchDioAltModePin */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*Implements AR_PN0062_FR_0051, EAAR_PN0034_FR_0049, AR_PN0062_FR_0010*/
/*Implements AR_PN0062_FR_0064*/
/*******************************************************************************
** Function Name         : Port_SearchModeChangeablePin
**
** Service ID            : Not Applicable
**
** Description           : This function used to verify whether the given pin
**                         is Mode changeable.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPinNumber - Port Pin number
**                         LpStartPtr - Start pointer to the Changeable pin
**                         structures.
**                         Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Pointer to Mode Changeable Pin structure - if given
**                         pin number matches.
**                         NULL - If Pin number does not match.
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
/*Implements PORT_ESDD_UD_008*/
#if ((PORT_SET_PIN_MODE_API == STD_ON) || \
                              (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON))

/*Implements PORT131*/
/* MISRA Violation: START Msg(4:0857)-9 */
#define PORT_START_SEC_PRIVATE_CODE
/* MISRA Violation: END Msg(4:0857)-9 */
#include "MemMap.h"

/*Implements PORT_ESDD_UD_015*/
/*Implements AR_PN0062_FR_0010*/

STATIC
FUNC(P2CONST(Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
    PORT_PRIVATE_CODE) Port_SearchModeChangeablePin(CONST(Port_PinType,
    AUTOMATIC) LddPinNumber, CONSTP2CONST(Port_PinModeChangeableDetails,
    AUTOMATIC, PORT_CONFIG_CONST)LpStartPtr, CONST(uint8, AUTOMATIC) Lucsize)
{
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_DATA)
                                                            LpRetPtr;
  uint8 LucLow;
  uint8 LucHigh;
  uint8 LucMid;
  uint16 LusListSearchId;
  LucHigh = Lucsize - PORT_ONE;
  LucLow = PORT_ONE;
  LpRetPtr = NULL_PTR;
  if (NULL_PTR != LpStartPtr )
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Get the lower limit of Search ID */
    LusListSearchId = LpStartPtr->ddPinId;
    /*  QAC Warning: END Msg(2:2814)-3 */

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Check whether search Search-ID is in range */
    if ((LddPinNumber >= LusListSearchId) &&
       (LddPinNumber <= ((LpStartPtr + LucHigh)->ddPinId)))
    /* MISRA Violation: END Msg(4:0488)-6 */
    {
      /*
       * Check whether requested Search-ID is same as first Search-ID
       * of the list
       */
      if (LddPinNumber != LusListSearchId)
      {
        do
        {
          /* QAC Warning: START Msg(2:3892)-4 */
          /* Get the middle index number */
          LucMid = (LucHigh + LucLow) >> PORT_ONE;
          /*  QAC Warning: END Msg(2:3892)-4 */

          /* MISRA Violation: START Msg(4:0488)-6 */
          /* Get the Search-ID of the mid IDs */
          LusListSearchId = ((LpStartPtr + LucMid)->ddPinId);
          /* MISRA Violation: END Msg(4:0488)-6 */

          /* Compare Search-ID with the requested one */
          if (LusListSearchId == LddPinNumber)
          {
            /* MISRA Violation: START Msg(4:0488)-6 */
            /* Update the return pointer with the pin number structure */
            LpRetPtr = (LpStartPtr + LucMid);
            /* MISRA Violation: END Msg(4:0488)-6 */
            /* Set LucHigh to zero to break the loop */
            LucHigh = PORT_ZERO;
          } /* End of LusListSearchId == LddPinNumber */
          else
          {
            /* Compare the Search-ID with the requested one */
            if (LddPinNumber < LusListSearchId)
            {
              /* If the priority is lower, update LucHigh */
              LucHigh = LucMid - PORT_ONE;
            }
            else
            {
              /* If the priority is higher, update LucLow */
              LucLow = LucMid + PORT_ONE;
            }
          }
        } while (LucLow <= LucHigh);
      } /* End of LddPinNumber != LusListSearchId */
      else
      {
        /*Update the return pointer with start pointer (Matches with first Id)*/
        LpRetPtr = LpStartPtr;
      }
    } /*
       * End of (LddPinNumber >= LusListSearchId) &&
       * (LddPinNumber <= ((LpStartPtr + LucHigh)->ddPinId))
       */
    else
    {
      /* No action required */
    }
  }
  else
  {

  }

  return (LpRetPtr);
} /* End of Port_SearchModeChangeablePin */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */

/*Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049, AR_PN0062_FR_0004*/
/*Implements AR_PN0062_FR_0004, AR_PN0062_FR_0060*/
/*******************************************************************************
** Function Name         : Port_InitConfig
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the registers of
**                         numeric and JTag ports.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Port_HWInitConfig,Port_OpenDrainCtrlRegInit,
**                         SchM_Enter_Port_PORT_INIT_CONFIG_PROTECTION
**                         SchM_Exit_Port_PORT_INIT_CONFIG_PROTECTION,
**                         Dem_ReportErrorStatus
**
** Registers Used        : PFCEn, PFCn, PFCAEn, PMCSRn, PMSRn,
**                         JPFCE0,JPMCSR0, JPMSR0.
*******************************************************************************/
/*Implements PORT131*/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_088*/
/*Implements PORT_ESDD_UD_102*/
#if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
     (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))
/* The function Port_Init shall initialize all controller registers */
/*Implements PORT113, PORT002*/

/*Implements PORT_ESDD_UD_001*/
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_InitConfig
                        (CONST(Port_GroupType,AUTOMATIC) LenGroupType)
{
  P2CONST(volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                      LpPortPMCSRReg;
  P2CONST(volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       LpFuncCtrlReg;
  P2CONST(volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)LpPMSRReg;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpFourByteRegAddress;
  P2VAR(volatile uint16, AUTOMATIC, PORT_CONFIG_DATA) LpTwoByteRegAddress;
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) LpOneByteRegAddress;
  #endif
  uint32 LulUserBaseAddress;
  uint8 LucNoOfRegs;
  uint8 LucNoOfPMCSRRegs;
  uint8 LucNoOfFuncCtrlRegs;
  uint8 LucNoOfPMSRRegs;
  Std_ReturnType LenReturnValue;
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  boolean LblJtag = PORT_FALSE;
  #endif

  /*Implements PORT_ESDD_UD_088*/
  /*Implements PORT_ESDD_UD_102*/
  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /* Get the pointer to the Numeric Function Control registers */
    /* QAC Warning: START Msg(2:2814)-3 */
    LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
    /* QAC Warning: END Msg(2:2814)-3 */

    /* Get the pointer to the Numeric PMSR registers */
    LpPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    /* Get the total number of Numeric PMCSR registers */
    /*Implements PORT_ESDD_UD_038*/
    LucNoOfPMCSRRegs = PORT_NUM_PMCSR_REGS;
    /* Get the total number of Numeric Function Control registers */
    /*Implements PORT_ESDD_UD_045*/
    LucNoOfFuncCtrlRegs = PORT_NUM_FUNC_CTRL_REGS;
    /* Get the Base address of Numeric Port */
    /*Implements AR_PN0062_FR_0026*/
    /*Implements PORT_ESDD_UD_016*/
    LulUserBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    /* Get the total number of Numeric PMSR registers */
    LucNoOfPMSRRegs = PORT_NUM_PMSR_REGS;

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /* Get the pointer to the Numeric PMCSR registers */
    /*Implements PORT_ESDD_UD_113*/
    /*Implements PORT_ESDD_UD_114*/
    /*Implements PORT_ESDD_UD_132*/
    LpPortPMCSRReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs
                    + (PORT_NUM_PFCE_REGS + PORT_NUM_PFC_REGS
                    + PORT_NUM_PFCAE_REGS);
    /* QAC Warning: END Msg(2:3892)-4 */
    /* MISRA Violation: END Msg(4:0488)-6 */

  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  {
    /* Get the pointer to the JTag Function Control registers */
    LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
    /* Get the pointer to the JTag PMSR registers */
    LpPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
    /* Get the total number of JTAG PMCSR registers */
    /*Implements PORT_ESDD_UD_030*/
    LucNoOfPMCSRRegs = PORT_JTAG_PMCSR_REGS;
    /* Get the total number of JTag Function Control registers */
    /*Implements PORT_ESDD_UD_046*/
    LucNoOfFuncCtrlRegs = PORT_JTAG_FUNC_CTRL_REGS;
    /* Get the Base address of JTag Port */
    /*Implements PORT_ESDD_UD_018*/
    LulUserBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    /* Get the total number of JTAG PMSR registers */
    /*Implements PORT_ESDD_UD_124*/
    LucNoOfPMSRRegs = PORT_JTAG_PMSR_REGS;

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /* Get the pointer to the JTAG PMSR registers */
    /*Implements PORT_ESDD_UD_121*/
    LpPortPMCSRReg = Port_GpConfigPtr->pPortJFuncCtrlRegs +
                     PORT_JTAG_PFCE_REGS ;
    /* QAC Warning: END Msg(2:3892)-4 */
    /* MISRA Violation: END Msg(4:0488)-6 */
    /* Update the local variable as one */
    LblJtag = PORT_TRUE;
  }
  #endif /* #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )*/
  /*Invoke the internal function to initialize Set/Reset,Input Buffer,
  Bi-direction control,Pull-Up/Down Option,Input buffer selection registers
  of Numeric and JTag ports*/
  Port_HWInitConfig(LenGroupType);
  /*Invoke the internal function to initialize Port open-drain control,
  Universal control, output level inversion, Drive strength contorl register
  of Numeric and JTag ports*/
  LenReturnValue = Port_OpenDrainCtrlRegInit(LenGroupType);
  if (E_OK==LenReturnValue)
  {
    /* Get the count of total number of Function Control registers */
    LucNoOfRegs = LucNoOfFuncCtrlRegs;

    /*Implements PORT_ESDD_UD_005*/
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    while (PORT_ZERO < LucNoOfRegs )
    {
      /*Implements PORT_ESDD_UD_088*/
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Check JTAG port */
      if (PORT_TRUE == LblJtag)
      {

        /* QAC Warning: START Msg(2:2814)-3*/
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Get the pointer to the function control registers */
        LpOneByteRegAddress = (volatile uint8 *)
                        (LpFuncCtrlReg->usRegAddrOffset + LulUserBaseAddress);
        /* MISRA Violation: END Msg(4:0303)-2 */

        /* Write the register value to the corresponding register */
        PORT_REG_WRITE (*LpOneByteRegAddress,
                        ((uint8)LpFuncCtrlReg->usInitModeRegVal))
        /* QAC Warning: END Msg(2:2814)-3 */

        /* QAC Warning: START Msg(2:3892)-4 */
        /* Write Verify Check for corresponding Register*/
        PORT_REG_WRITE_VERIFY_INIT(*LpOneByteRegAddress,
        ((uint8)LpFuncCtrlReg->usInitModeRegVal),PORT_SET_BYTE,PORT_INIT_SID)
        /* QAC Warning: END Msg(2:3892)-4 */
      }
      else
      #endif
      {
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Get the pointer to the function control registers */
        LpTwoByteRegAddress = (volatile uint16 *)
                        (LpFuncCtrlReg->usRegAddrOffset + LulUserBaseAddress);
        /* MISRA Violation: END Msg(4:0303)-2 */

        /* QAC Warning: START Msg(2:2814)-3*/
        /* Write the register value to the corresponding register */
        PORT_REG_WRITE(*LpTwoByteRegAddress,LpFuncCtrlReg->usInitModeRegVal)
        /* QAC Warning: END Msg(2:2814)-3 */

        /* Write Verify Check for corresponding Register*/
        PORT_REG_WRITE_VERIFY_INIT(*LpTwoByteRegAddress,
        LpFuncCtrlReg->usInitModeRegVal,PORT_SET_WORD,PORT_INIT_SID)
      }
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpFuncCtrlReg++;
      /* MISRA Violation: END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */
    /* Get the count of total number of Function Control SR registers */
    LucNoOfRegs = LucNoOfPMCSRRegs;
    while (PORT_ZERO < LucNoOfRegs )
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Get the pointer to the function control registers */
      LpFourByteRegAddress = (volatile uint32 *)
          (LpPortPMCSRReg->usRegAddrOffset + LulUserBaseAddress);
      /* QAC Warning: END Msg(2:2814)-3 */
      /* MISRA Violation: END Msg(4:0303)-2 */

      /* Write the register value to the corresponding register */
      /* QAC Warning: START Msg(2:2814)-3 */
      PORT_REG_WRITE(*LpFourByteRegAddress,
                ((uint32)(LpPortPMCSRReg->usInitModeRegVal | PORT_MSB_MASK)))
      /* QAC Warning: END Msg(2:2814)-3 */

      /* Write Verify Check for PMCSR Register */
      PORT_REG_WRITE_VERIFY_INIT(*LpFourByteRegAddress,
                ((uint32)LpPortPMCSRReg->usInitModeRegVal),PORT_SET_LONG_WORD,
                                                                PORT_INIT_SID)
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortPMCSRReg++;
      /* MISRA Violation: END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */
    /* Get the count of total number of PMSR registers */
    LucNoOfRegs = LucNoOfPMSRRegs;
    while (PORT_ZERO < LucNoOfRegs )
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Get the pointer to the PMSR registers */
      LpFourByteRegAddress =
      (volatile uint32 *)(LpPMSRReg->usRegAddrOffset + LulUserBaseAddress);

      /* QAC Warning: END Msg(2:2814)-3 */
      /* MISRA Violation: END Msg(4:0303)-2 */
      /* Write the register value to the corresponding register */
      PORT_REG_WRITE(*LpFourByteRegAddress,
                   ((uint32)(LpPMSRReg->usInitModeRegVal | PORT_MSB_MASK)))
      /* Write Verify Check for PMSR Register */
      PORT_REG_WRITE_VERIFY_INIT(*LpFourByteRegAddress,
      ((uint32)LpPMSRReg->usInitModeRegVal), PORT_SET_LONG_WORD, PORT_INIT_SID)
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPMSRReg++;
      /* MISRA Violation: END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */
    /* Exit critical section */

    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
  }
  else
  {

  }
  /*Return LenReturnValue*/
  return (LenReturnValue);
} /* End of API Port_InitConfig */
#endif
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements EAAR_PN0034_FR_0049, AR_PN0062_FR_0063*/
/*******************************************************************************
** Function Name         : Port_SearchDirChangeablePin
**
** Service ID            : Not Applicable
**
** Description           : This function used to verify whether the given pin is
**                         Direction changeable.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPinNumber - Port Pin number
**                         LpStartPtr - Start pointer to the Changeable pin
**                         structures.
**                         Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Pointer to Direction Changeable Pin structure - if
**                         given pin number matches.
**                         NULL - If Pin number does not match.
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
/*Implements PORT_ESDD_UD_082*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/*Implements PORT131*/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_084*/
STATIC
FUNC(P2CONST(Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST),
    PORT_PRIVATE_CODE) Port_SearchDirChangeablePin(CONST(Port_PinType,
    AUTOMATIC) LddPinNumber, CONSTP2CONST(Port_PinsDirChangeable, AUTOMATIC,
    PORT_CONFIG_CONST)LpStartPtr, CONST(uint8, AUTOMATIC) Lucsize)

{
  /* Initializing Direction Control Registers Pointer to Null pointer */
  P2CONST (Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_DATA) LpRetPtr;

  uint8 LucLow;
  uint8 LucHigh;
  uint8 LucMid;
  uint16 LusListSearchId;
  LucHigh = Lucsize - PORT_ONE;
  LucLow = PORT_ONE;
  LpRetPtr = NULL_PTR;

  if (NULL_PTR != LpStartPtr )
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Get the lower limit of Search ID */
    LusListSearchId = LpStartPtr->ddPinId;
    /* QAC Warning: END Msg(2:2814)-3 */

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Check whether search Search-ID is in range */
    if ((LddPinNumber >= LusListSearchId) &&
       (LddPinNumber <= ((LpStartPtr + LucHigh)->ddPinId)))
    /* MISRA Violation: END Msg(4:0488)-6 */
    {
      /*
       *Check whether requested Search-ID is same as first Search-ID of the list
       */
      if (LddPinNumber != LusListSearchId)
      {
        do
        {

          /* QAC Warning: START Msg(2:3892)-4 */
          /* Get the middle index number */
          LucMid = (LucHigh + LucLow) >> PORT_ONE;
          /* QAC Warning: END Msg(2:3892)-4 */

          /* MISRA Violation: START Msg(4:0488)-6 */
          /* Get the Search-ID of the mid IDs */
          LusListSearchId = ((LpStartPtr + LucMid)->ddPinId);
          /* MISRA Violation: END Msg(4:0488)-6 */
          /* Compare Search-ID with the requested one */
          if (LusListSearchId == LddPinNumber)
          {
            /* MISRA Violation: START Msg(4:0488)-6 */
            /* Update the return pointer with the pin number structure */
            LpRetPtr = (LpStartPtr + LucMid);
            /* MISRA Violation: END Msg(4:0488)-6 */
            /* Set LucHigh to zero to break the loop */
            LucHigh = PORT_ZERO;
          } /* End of LusListSearchId == LddPinNumber */
          else
          {
            /* Compare the Search-ID with the requested one */
            if (LddPinNumber < LusListSearchId)
            {
              /* If the priority is lower, update LucHigh */
              LucHigh = LucMid - PORT_ONE;
            } /* End of LddPinNumber < LusListSearchId */
            else
            {
              /* If the priority is higher, update LucLow */
              LucLow = LucMid + PORT_ONE;
            }
          }
        } while (LucLow <= LucHigh);

      } /* End of LddPinNumber != LusListSearchId */
      else
      {
        /*Update the return pointer with start pointer (Matches with first Id)*/
        LpRetPtr = LpStartPtr;
      }
    } /*
       * (LddPinNumber >= LusListSearchId) &&
       * (LddPinNumber <= ((LpStartPtr + LucHigh)->ddPinId))
       */
    else
    {
      /* No action required */
    }
  }
  else
  {

  }
  return (LpRetPtr);
} /* End of API Port_SearchDirChangeablePin */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

/*Implements EAAR_PN0034_FR_0049, AR_PN0062_FR_0004, AR_PN0062_FR_0061*/
/*******************************************************************************
** Function Name         : Port_RefreshPortInternal
**
** Service ID            : Not Applicable
**
** Description           : This service shall refresh the direction of all
**                         configured ports to the configured direction.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port Group Type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : SchM_Enter_Port_PORT_REFRESHPORT_INTERNAL_PROTECTION,
**                         SchM_Exit_Port_PORT_REFRESHPORT_INTERNAL_PROTECTION,
**                         Dem_ReportErrorStatus
**
** Registers Used        : PMSRn, JPMSR0.
*******************************************************************************/
/*Implements PORT131*/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_104*/
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
                       (CONST(Port_GroupType, AUTOMATIC) LenGroupType)
{
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)LpPMSRReg;
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPMSRRegAddress;
  uint32 LulBaseAddress;
  uint8 LucNoOfRegs;

  /*Implements AR_PN0062_FR_0023, PORT075*/
  /*Implements PORT_ESDD_UD_088*/
  /*Implements PORT_ESDD_UD_102*/
  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Get the pointer to 32Bit Numeric PMSR register structure */
    LpPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    /* QAC Warning: END Msg(2:2814)-3 */

    /* Get the count of 32Bit Numeric PMSR registers */
    /*Implements PORT_ESDD_UD_037*/
    LucNoOfRegs = PORT_NUM_PSR_REGS;
    /* Get the Numeric base address */
    /*Implements AR_PN0062_FR_0026*/
    /*Implements PORT_ESDD_UD_016*/
    LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  {
    /* Get the pointer to 32Bit JTAG PMSR register structure */
    LpPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
    /* Get the count of 32Bit JTAG PMSR registers */
    /*Implements PORT_ESDD_UD_029*/
    LucNoOfRegs = PORT_JTAG_PSR_REGS;
    /* Get the JTAG base address */
    /*Implements PORT_ESDD_UD_018*/
    /*Implements AR_PN0062_FR_0026*/
    LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
  } /* End of PORT_GROUP_NUMERIC == LenGroupType */
  #endif /*   #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */

  /* Enter critical section */
  /*Implements PORT_ESDD_UD_005*/
  /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
  /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  PORT_ENTER_CRITICAL_SECTION(PORT_REFRESHPORT_INTERNAL_PROTECTION);
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  while (PORT_ZERO < LucNoOfRegs)
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* QAC Warning: START Msg(2:2814)-3*/
    /* Get the contents of the register */
    /*Implements AR_PN0062_FR_0025*/
    LpPMSRRegAddress = (volatile uint32 *)(LpPMSRReg->usRegAddrOffset +
                                                LulBaseAddress);
    /* QAC Warning: END Msg(2:2814)-3 */
    /* MISRA Violation: END Msg(4:0303)-2 */
    /*Implements PORT061, PORT066*/

    /* QAC Warning: START Msg(2:2814)-3 */
    /* Write the initial value to the pins which are Directional unchangeable
       and retain the values of those pins which are Directional changeable  */
    PORT_REG_WRITE(*LpPMSRRegAddress, LpPMSRReg->ulMaskAndConfigValue)
    /* QAC Warning: END Msg(2:2814)-3 */

    /*Verify the register write on PMSR register*/
    /* QAC Warning: START Msg(2:3892)-4 */
    PORT_REG_WRITE_VERIFY_RUNTIME(*LpPMSRRegAddress,
    (LpPMSRReg->ulMaskAndConfigValue &
    (LpPMSRReg->ulMaskAndConfigValue >> PORT_SIXTEEN)),
    (LpPMSRReg->ulMaskAndConfigValue >> PORT_SIXTEEN),PORT_REFRESH_PORT_DIR_SID)
    /* QAC Warning: END Msg(2:3892)-4 */

    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPMSRReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* Exit critical section */
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  PORT_EXIT_CRITICAL_SECTION(PORT_REFRESHPORT_INTERNAL_PROTECTION);
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

} /* End of API Port_RefreshPortInternal */
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049, AR_PN0062_FR_0031*/
/*Implements AR_PN0062_FR_0032 AR_PN0062_FR_0033, AR_PN0062_FR_0034*/
/*Implements AR_PN0062_FR_0035*/
/*******************************************************************************
** Function Name         : Port_FilterConfig
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the registers of
**                         filter configuration.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : Dem_ReportErrorStatus
**
** Registers Used        : DNFAnCTL, DNFAnENL, DNFCKSnC, FCLAnCTL.
*******************************************************************************/
/*Implements PORT_ESDD_UD_020*/
#if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))

/*Implements PORT131*/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/*Implements PORT_ESDD_UD_013*/
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_FilterConfig(void)
{
  /* Pointer to digital filter DNFA register data structure */
  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  P2CONST(volatile Port_DNFARegs, AUTOMATIC, PORT_CONFIG_DATA) LpDNFAReg;

  /* Pointer to digital filter DNFCKS register data structure */
  #if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
  P2CONST(volatile Port_DNFCKSRegs, AUTOMATIC, PORT_CONFIG_DATA) LpDNFCKSReg;
  #endif /* End of PORT_DNF_CLK_SRC_AVAILABLE == STD_ON */

  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

  /* Pointer to analog filter FCLA register data structure */
  #if (PORT_FCLA_REG_CONFIG == STD_ON)
  P2CONST(volatile Port_FCLARegs, AUTOMATIC, PORT_CONFIG_DATA) LpFCLAReg;
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */

  uint32 LulBaseAddress;
  uint8 LucNoOfRegs;
  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
  uint16 LusCount;
  LusCount = PORT_WORD_ZERO;
  #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
  #endif

  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  /* Get the base address for DNFA Noise Elimination Registers */
  /*Implements PORT_ESDD_UD_025*/
  LulBaseAddress = PORT_DNFA_BASE_ADDRESS;

  /* QAC Warning: START Msg(2:2814)-3 */
  /* Get the pointer to the details of DNFA Noise Elimination Registers */
  LpDNFAReg = Port_GpConfigPtr->pPortDNFARegs;
  /* QAC Warning: END Msg(2:2814)-3 */
  /* Get the count for total number of DNFA Noise Elimination Registers */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfDNFARegs;
  while (PORT_ZERO < LucNoOfRegs)
  {

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Write the DNFAnCTL register value to the corresponding register */
    PORT_REG_WRITE(*((volatile uint8 *)(LulBaseAddress +
            (uint32)LpDNFAReg->usDNFARegAddrOffset)),LpDNFAReg->ucDNFACTL)
    /* QAC Warning: END Msg(2:2814)-3 */
    /* MISRA Violation: END Msg(4:0303)-2 */

    /*Write verify check on DNFAnCTL register*/
    /* MISRA Violation: START Msg(4:0306)-3 */
    PORT_REG_WRITE_VERIFY_INIT(*((uint8 *)(LulBaseAddress +
            (uint32)LpDNFAReg->usDNFARegAddrOffset)),LpDNFAReg->ucDNFACTL,
                                       PORT_SET_BYTE,PORT_INIT_SID)
    /* MISRA Violation: END Msg(4:0306)-3 */

    /*Implements PORT_ESDD_UD_021*/
    #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Write the DNFAnENL register value to the corresponding register */
    /*Implements PORT_ESDD_UD_127*/
    PORT_REG_WRITE(*((volatile uint8 *)(LulBaseAddress +
    (uint32)LpDNFAReg->usDNFARegAddrOffset + PORT_DNFAENL_ADDRESS_OFFSET)),
                                                      LpDNFAReg->ucDNFAENL)
    /* MISRA Violation: END Msg(4:0303)-2 */

    /*Write verify check on DNFAnENL register*/
    /* MISRA Violation: START Msg(4:0306)-3 */
    PORT_REG_WRITE_VERIFY_INIT(*((uint8 *)(LulBaseAddress +
    (uint32)LpDNFAReg->usDNFARegAddrOffset + PORT_DNFAENL_ADDRESS_OFFSET)),
                       LpDNFAReg->ucDNFAENL,PORT_SET_BYTE, PORT_INIT_SID )
    /* MISRA Violation: END Msg(4:0306)-3 */

    while (LusCount < (LpDNFAReg->usDELAY))
    {
      ASM_NOP();
      LusCount++;
    }
    LusCount = PORT_WORD_ZERO;
    #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */

    /* MISRA Violation: START Msg(4:0489)-7 */
    /* Increment the pointer to get the value of next structure */
    LpDNFAReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    /* Decrement the count for total number of DNFA Registers */
    LucNoOfRegs--;

  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

  /*Implements PORT_ESDD_UD_023*/
  #if (PORT_FCLA_REG_CONFIG == STD_ON)
  /* Get the base address for FCLA Noise Elimination Registers */
  /*Implements PORT_ESDD_UD_024*/
  LulBaseAddress = PORT_FCLA_BASE_ADDRESS;
  /* Get the pointer to the details of FCLA Noise Elimination Registers */
  LpFCLAReg = Port_GpConfigPtr->pPortFCLARegs;
  /* Get the count for total number of FCLA Noise Elimination Registers */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfFCLARegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Write the FCLAnCTL register value to the corresponding register */
    PORT_REG_WRITE(*((volatile uint8 *)(LulBaseAddress +
             (uint32)LpFCLAReg->usFCLARegAddrOffset)),LpFCLAReg->ucFCLACTL)
    /* MISRA Violation: END Msg(4:0303)-2 */
    /* QAC Warning: END Msg(2:2814)-3 */

    /*Write verify check on FCLAnCTL register*/
    /* MISRA Violation: START Msg(4:0306)-3 */
    PORT_REG_WRITE_VERIFY_INIT(*((uint8 *)(LulBaseAddress +
             (uint32)LpFCLAReg->usFCLARegAddrOffset)),LpFCLAReg->ucFCLACTL,
                                           PORT_SET_BYTE, PORT_INIT_SID)
    /* MISRA Violation: END Msg(4:0306)-3 */

    /* MISRA Violation: START Msg(4:0489)-7 */
    /* Increment the pointer to get the value of next structure */
    LpFCLAReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */

    /* Decrement the count for total number of FCLA Registers */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */

  /*Implements PORT_ESDD_UD_022*/
  #if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
  /* Get the base address for DNFCKS Noise Elimination Registers */
  /*Implements PORT_ESDD_UD_027*/
  LulBaseAddress = PORT_DNFCKS_BASE_ADDRESS;

  /* Get the pointer to the details of DNFA Noise Elimination Registers */
  LpDNFCKSReg = Port_GpConfigPtr->pPortDNFCKSRegs;

  /* Get the count for total number of DNFA Noise Elimination Registers */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfDNFCKSRegs;
  while (PORT_ZERO < LucNoOfRegs)
  {

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Write the DNFCKS register value to the corresponding register */
    PORT_REG_WRITE(*((volatile uint32 *)(LulBaseAddress +
           (uint32)LpDNFCKSReg->usDNFCKSRegAddrOffset)),LpDNFCKSReg->ulDNFCKS)
    /* QAC Warning: END Msg(2:2814)-3 */
    /* MISRA Violation: END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0306)-3 */
    /*Write verify check on DNFCKS register*/
    PORT_REG_WRITE_VERIFY_INIT(*((uint32 *)(LulBaseAddress +
           (uint32)LpDNFCKSReg->usDNFCKSRegAddrOffset)),LpDNFCKSReg->ulDNFCKS,
                                           PORT_SET_LONG_WORD, PORT_INIT_SID)
    /* MISRA Violation: END Msg(4:0306)-3 */

    /* MISRA Violation: START Msg(4:0489)-7 */
    /* Increment the pointer to get the value of next structure */
    LpDNFCKSReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */

    /* Decrement the count for total number of DNFA Registers */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_DNF_CLK_SRC_AVAILABLE == STD_ON */

} /* End of API Port_FilterConfig */
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /*
        * End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
        * (PORT_FCLA_REG_CONFIG == STD_ON)
        */
/*Implements AR_PN0062_FR_0043, EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049*/
/*Implements AR_PN0062_FR_0004, AR_PN0062_FR_0066*/
/*******************************************************************************
** Function Name         : Port_SetPinDefaultMode
**
** Service ID            : 0x07
**
** Description           : This function used to set the mode of a port pin
**                         during runtime. The PORT Driver module allows
**                         changing the mode of the pin to default mode set by
**                         the configuration at the time of Port_Init().
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : SchM_Enter_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION,
**                         Port_SearchModeChangeablePin,Dem_ReportErrorStatus
**                         Port_PinDefModeFuncRegSet,Port_PinDefModeDetCheck.
**
** Registers Used        : PMCSRn, PMSRn, PIPCn, JPMCSR0, JPMSR0.
*******************************************************************************/
/*Implements PORT_ESDD_UD_125*/
#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))

/*Implements PORT131*/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_086*/

/* QAC Warning: START Msg(2:3227)-5 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDefaultMode (Port_PinType Pin)
/* QAC Warning: END Msg(2:3227)-5 */
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                 LpModeChangeablePin;
  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;
  /* Pointer to Port Registers Data structure */
  P2CONST (volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                     LpFuncCtrlReg;
  /* Pointer to Direction Control Registers Data structure */
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST) LpPortPMSRReg;
  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST) LpRegAddr;
  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST) LpTwoByteRegAddr;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;
  /* MISRA Violation: END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint16 LusOrMask;
  uint16 LusPIPCInitMode;
  uint16 LusInitMode;

  /*Implements PORT_ESDD_UD_106*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

  LusPIPCInitMode = (uint16)PORT_MODE_DIO;
  LusInitMode = (uint16)PORT_MODE_DIO;

  /*Implements PORT_ESDD_UD_106*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions  */
  LenReturnValue = Port_PinDefModeDetCheck(Pin);
  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check whether the Pin is mode changeable at run time */
    /* QAC Warning: START Msg(2:2814)-3 */
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);
    /* QAC Warning: END Msg(2:2814)-3 */
    if (NULL_PTR != LpModeChangeablePin)
    {
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the pointer to the Set Mode group list */
      LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                      + (LpModeChangeablePin->ucSetModeIndex));
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* If the Pin group is of Numeric type */
      /*Implements PORT_ESDD_UD_088*/
      /*Implements PORT_ESDD_UD_102*/
      #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
      if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
      {
        LpPortReg = Port_GpConfigPtr->pPortNumRegs;
        LpPortPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
        LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
        /*Implements PORT_ESDD_UD_016*/
        /*Implements AR_PN0062_FR_0026*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
      } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
      else
      {
        LpPortReg = Port_GpConfigPtr->pPortJRegs;
        LpPortPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
        LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
        /*Implements PORT_ESDD_UD_018*/
        /*Implements AR_PN0062_FR_0026*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
      } /* End of PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType */
      #endif /*   #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */
      /*Assign OrMask value to local variable*/
      LusOrMask = LpModeChangeablePin->usOrMask;
      /* Set the bit position in the upper 16 bits (31-16) of the PMCSR or PMSR
      * variable to 1 of the configured pin whose Mode has to be changed */
      LunSRRegContent.Tst_Port_Word.usMSWord = LusOrMask;

      /* QAC Warning: START Msg(2:2814)-3 */
      /* Write PMCSR register. Check for register availability */
      if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMCSRRegIndex)
      /* QAC Warning: END Msg(2:2814)-3 */
      {

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* QAC Warning: START Msg(2:2824)-2 */
        /* Get the address of PMCSR register */
        LpRegAddr = (volatile uint32 *)((LpFuncCtrlReg +
                    LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
        /* QAC Warning: END Msg(2:2824)-2 */
        /* MISRA Violation: END Msg(4:0488)-6 */
        /* MISRA Violation: END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0488)-6 */
        LusInitMode = ((LpFuncCtrlReg +
              LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usInitModeRegVal) &
                                                                  LusOrMask;
        /* MISRA Violation: END Msg(4:0488)-6 */

        /* Write the requested direction into Lower word of PMCSR variable
         * by using OR mask */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LunSRRegContent.Tst_Port_Word.usLSWord = LusInitMode;
        /* MISRA Violation: END Msg(4:0488)-6 */

        /* An atomic access to Microcontroller registers by the use of an
           exclusive area */
        /*Implements PORT075*/
        /* Enter critical section */
        /*Implements PORT_ESDD_UD_005*/
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /* QAC Warning: START Msg(2:2814)-3 */
        /* Write the corresponding 32 bit value to the PMCSR register */
        PORT_REG_WRITE(*LpRegAddr,LunSRRegContent.ulRegContent)
        /* QAC Warning: END Msg(2:2814)-3 */

        /* Exit critical section */
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /* QAC Warning: START Msg(2:3892)-4 */
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpRegAddr,(LunSRRegContent.ulRegContent &
        LusOrMask),(LunSRRegContent.ulRegContent >> PORT_SIXTEEN),
        PORT_SET_PIN_DEFAULT_MODE_SID)
        /* QAC Warning: END Msg(2:3892)-4 */

      } /* End of Write PMCSR register */
      else
      {
        /* No action required */
      }
      if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPIPCRegIndex)
      {
        /* QAC Warning: START Msg(2:2824)-2 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Get initial PIPC register value */
        LusPIPCInitMode = ((LpPortReg +
                LpSetPinModeGroupStruct->ucPIPCRegIndex)->usInitModeRegVal) &
                                                                 LusOrMask;
        /* MISRA Violation: END Msg(4:0488)-6 */
        /* QAC Warning: END Msg(2:2824)-2 */

        /* MISRA Violation: START Msg(4:0488)-6 */
        /* MISRA Violation: START Msg(4:0303)-2 */
        /*Implements PORT_ESDD_UD_067*/
        LpTwoByteRegAddr = (volatile uint16 *)((uint32)((LpPortReg +
                LpSetPinModeGroupStruct->ucPIPCRegIndex)->usRegAddrOffset) +
                (uint32)PORT_OS_BASE_ADDRESS_OFFSET + LulBaseAddress);
        /* MISRA Violation: END Msg(4:0303)-2 */
        /* MISRA Violation: END Msg(4:0488)-6 */

        /* Enter critical section */
        /*Implements PORT_ESDD_UD_005*/
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /* If bit needs to be set, OR the register contents with OrMask */
        /* QAC Warning: START Msg(2:2814)-3 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        PORT_REG_WRITE(*LpTwoByteRegAddr,
          (((*LpTwoByteRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpPortReg +
                LpSetPinModeGroupStruct->ucPIPCRegIndex)->usInitModeRegVal) &
                                                                LusOrMask)) )
        /* MISRA Violation: END Msg(4:0488)-6 */
        /* QAC Warning: END Msg(2:2814)-3 */

        /* Exit critical section */
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*Write verify check on PIPC register*/
        /* MISRA Violation: START Msg(4:0488)-6 */
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,
          (((*LpTwoByteRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpPortReg +
                LpSetPinModeGroupStruct->ucPIPCRegIndex)->usInitModeRegVal) &
                LusOrMask)), PORT_SET_WORD, PORT_SET_PIN_DEFAULT_MODE_SID )
        /* MISRA Violation: END Msg(4:0488)-6 */
      }   /* End of Write PIPC register */
      else
      {
          /*do nothing */
      }
      /* Check initial Mode of requested PortPin is DIO mode or alternative
          mode in PMCSR Reg  and proceed only if Alternate mode */
      if ((uint16)PORT_MODE_DIO != LusInitMode)
      {
        Port_PinDefModeFuncRegSet(Pin);

        /* Check if pin direction is controlled by Port module or
           alternate function and update PMSR reg if controlled by Port */
        /* QAC Warning: START Msg(2:3892)-4 */
        if ((uint16)PORT_MODE_DIO == LusPIPCInitMode)
        /* QAC Warning: END Msg(2:3892)-4 */
        {
          /* Write PMSR register.Check for PMSR register availability */
          if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMSRRegIndex)
          {
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* MISRA Violation: START Msg(4:0488)-6 */
            /* QAC Warning: START Msg(2:2824)-2 */
            /* Get the PMSR register Address */
            LpRegAddr = (volatile uint32 *)((LpPortPMSRReg +
                       LpSetPinModeGroupStruct->ucPMSRRegIndex)->usRegAddrOffset
                            + LulBaseAddress);
            /* QAC Warning: END Msg(2:2824)-2 */
            /* MISRA Violation: END Msg(4:0303)-2 */
            /* MISRA Violation: END Msg(4:0488)-6 */

            /* MISRA Violation: START Msg(4:0488)-6 */
            LunSRRegContent.Tst_Port_Word.usLSWord = ((LpPortPMSRReg +
                 LpSetPinModeGroupStruct->ucPMSRRegIndex)->usInitModeRegVal) &
                                                                LusOrMask;
            /* MISRA Violation: END Msg(4:0488)-6 */

            /* Enter critical section */
            /*Implements PORT_ESDD_UD_005*/
            /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
            /* Write the contents of Lower word and Upper word of PMSR variable
               into the PMSR register address */
            PORT_REG_WRITE (*LpRegAddr,LunSRRegContent.ulRegContent)

            /* Exit critical section */
            /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
            /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
            #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
            PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
            #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

            /*Write verify check on PMSR register*/
            /* QAC Warning: START Msg(2:3892)-4 */
            PORT_REG_WRITE_VERIFY_RUNTIME(*LpRegAddr,
            (LunSRRegContent.ulRegContent
            & LusOrMask),(LunSRRegContent.ulRegContent >> PORT_SIXTEEN),
            PORT_SET_PIN_DEFAULT_MODE_SID)
            /* QAC Warning: END Msg(2:3892)-4 */
          }
          else
          {
          /* No action required */
          }
        }
        else
        {
           /* do nothing */
        } /* End of if((uint16)PORT_MODE_DIO == LusPIPCInitMode) */
      }
      else
      {
        /* do nothing */
      } /* End of if(LusInitMode != PORT_MODE_DIO) */
    } /*End of if(LpModeChangeablePin != NULL_PTR)*/
    else
    {
        /* do nothing */
    }
  } /* End of LenReturnValue == E_NOT_OK */

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
} /* End of API Port_SetPinDefaultMode */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) */
/*Implements AR_PN0062_FR_0004, AR_PN0062_FR_0065*/
/*******************************************************************************
** Function Name         : Port_SetPinDefaultDirection
**
** Service ID            : 0x08
**
** Description           : This service sets the port pin direction during
**                         runtime. The PORT Driver module allows changing the
**                         direction of the pin to configured direction set by
**                         the configuration at the time of Port_Init().
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be  initialized by calling Port_Init().
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,Dem_ReportErrorStatus
**                         SchM_Enter_Port_PORT_SET_PIN_DEFAULT_DIR_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_DEFAULT_DIR_PROTECTION,
**                         Port_SearchDirChangeablePin.
**
** Registers Used        : PMSRn, JPMSR0
*******************************************************************************/
/*Implements PORT_ESDD_UD_082*/
/*Implements PORT_ESDD_UD_126*/
#if ((PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON) && \
                     (PORT_SET_PIN_DIRECTION_API == STD_ON))

/*Implements PORT131, EAAR_PN0034_FR_0049*/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_004*/

/* QAC Warning: START Msg(2:3227)-5 */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDefaultDirection (Port_PinType Pin)
/* QAC Warning: END Msg(2:3227)-5 */
{
  P2CONST(volatile Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
                                                       LpChangeablePinDet;
  /* Pointer to Direction Control Registers Data structure */
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST) LpPortPMSRReg;
  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST) LpRegAddr;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;
  /* MISRA Violation: END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint16 LusOrMask;

  /*Implements PORT_ESDD_UD_106*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

  /* If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions */

  /*Implements PORT_ESDD_UD_106*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Implements PORT077*/
  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                               PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  /*Implements PORT_ESDD_UD_081*/
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                            PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);
    /* QAC Warning: END Msg(2:2814)-3 */

    /* Return value LpChangeablePinDet - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpChangeablePinDet)
    {
      /*Implements PORT146*/
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                 PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
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
  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /*Implements PORT_ESDD_UD_106*/
    /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
    #if (PORT_DEV_ERROR_DETECT == STD_OFF)
    /* Check whether the Pin direction is changeable at run time */
    /* QAC Warning: START Msg(2:2814)-3 */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);
    /* QAC Warning: END Msg(2:2814)-3 */
    #endif /* End of PORT_DEV_ERROR_DETECT == STD_OFF */

    /* MISRA violation : START Msg(4:2995)-13 */
    /* MISRA violation : START Msg(4:2991)-12 */
    if (NULL_PTR != LpChangeablePinDet)
    /* MISRA violation : END Msg(4:2991)-12 */
    /* MISRA violation : END Msg(4:2995)-13 */
    {
      /* Get the base address of the corresponding Port Type */
      /*Implements PORT_ESDD_UD_088*/
      /*Implements PORT_ESDD_UD_102*/
      #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
             (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
      if ((uint8)PORT_GROUP_NUMERIC == LpChangeablePinDet->ucPortType)
      {
        /* Get the Base address of Numeric Port */
        /*Implements PORT_ESDD_UD_016*/
        /*Implements AR_PN0062_FR_0026*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
        LpPortPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
      }
      else
      {
        /* Get the Base address of JTag Port */
        /*Implements PORT_ESDD_UD_018*/
        /*Implements AR_PN0062_FR_0026*/
        LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        LpPortPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
      } /*End of ((uint8)PORT_GROUP_NUMERIC == LpChangeablePinDet->ucPortType)*/
      #endif /* #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
             (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */

      /*Assign the maskvalue to local variable*/
      LusOrMask = LpChangeablePinDet->usOrMaskVal;

      /* Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
         variable to 1 of the configured pin whose Direction has to be changed*/
      LunSRRegContent.Tst_Port_Word.usMSWord =
                                         (LpChangeablePinDet->usOrMaskVal);

       /*Check for PMSR register availability */
      if (PORT_REG_NOTAVAILABLE != LpChangeablePinDet->ucPMSRRegIndex)
      {
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Get the PMSR register Address */
        LpRegAddr = (volatile uint32 *)((LpPortPMSRReg +
                      LpChangeablePinDet->ucPMSRRegIndex)->usRegAddrOffset
                                                             + LulBaseAddress);
        /* MISRA Violation: END Msg(4:0303)-2 */
        /* MISRA Violation: END Msg(4:0488)-6 */

        /* Write the contents of Lower word of PMSR variable into the PMSR
         * register address */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LunSRRegContent.Tst_Port_Word.usLSWord = ((LpPortPMSRReg +
            LpChangeablePinDet->ucPMSRRegIndex)->usInitModeRegVal) & LusOrMask;
        /* MISRA Violation: END Msg(4:0488)-6 */

        /* An atomic access to Microcontroller registers by the use of an.
           exclusive area  */
        /*Implements PORT075*/
        /* Enter critical section */
        /*Implements PORT_ESDD_UD_005*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_DIR_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /* QAC Warning: START Msg(2:2814)-3 */
        /* Write the contents of Lower word and upper word of PMSR variable
         * into the PMSR register address   */
        PORT_REG_WRITE(*LpRegAddr,LunSRRegContent.ulRegContent)
        /* QAC Warning: END Msg(2:2814)-3 */

        /* Exit critical section */
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_DIR_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*Verify the register write on PMSR register*/
        /* QAC Warning: START Msg(2:3892)-4 */
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpRegAddr,(LunSRRegContent.ulRegContent &
        LpChangeablePinDet->usOrMaskVal),(LunSRRegContent.ulRegContent >>
        PORT_SIXTEEN),PORT_SET_PIN_DEFAULT_DIR_SID)
        /* QAC Warning: END Msg(2:3892)-4 */
      }
      else
      {
          /* do nothing */
      }
    }
    else
    {
        /* do nothing */
    }
  } /* End of LenReturnValue == E_OK */

  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* End of (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetPinDefaultDirection */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON) */
/*******************************************************************************
** Function Name         : Port_PinModeDetCheck
**
** Service ID            : NA
**
** Description           : This function used to check the DET error conditions
**                         of Port_SetPinMode() Api
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Mode - New mode to be set on port pin.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : Port_SetPinMode() Api should be called
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         Port_SearchModeChangeablePin.
**
** Registers Used        : None.
*******************************************************************************/
/* Implements PORT131*/
/*Implements PORT_ESDD_UD_008*/
/*Implements PORT_ESDD_UD_106*/
/*Implements PORT100, PORT107, PORT211, PORT123_Conf, EAAR_PN0034_FR_0049*/
#if ((PORT_DEV_ERROR_DETECT == STD_ON) && \
    (PORT_SET_PIN_MODE_API == STD_ON))

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_096*/
STATIC FUNC (Std_ReturnType, PORT_PRIVATE_CODE) Port_PinModeDetCheck
     (CONST(Port_PinType, AUTOMATIC) Pin,
      CONST(Port_PinModeType, AUTOMATIC ) Mode)
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpModeChangeablePin;
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  /*Implements PORT087*/
  /*Check if the driver is initialized or not*/
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                                PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }
  /*Implements PORT087*/
  /* Check whether the requested PIN number is invalid */
  /*Implements PORT_ESDD_UD_081*/
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  /*Implements PORT087*/
  /* Check whether the requested mode is invalid
     In case of PortIpControl ON user will pass mode value ORed with 0x80,
     so this is to be masked while checking against the max mode */
  /* QAC Warning: START Msg(2:3892)-4 */
  /*Implements PORT_ESDD_UD_048*/
  if ((PORT_MAX_MODE < (Mode & PORT_MODE_MASK)) && (Mode < SET_PIPC_MIN_MODE))
  /* QAC Warning: END Msg(2:3892)-4 */
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                  PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of (Mode > PORT_MAX_MODE) */
  else
  {
    /* No action required */
  }
  if (E_OK == LenReturnValue)
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Check whether the Pin mode is changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                              Port_GpConfigPtr->pPinModeChangeableDetails,
                              Port_GpConfigPtr->ucNoOfPinsModeChangeable);
    /* QAC Warning: END Msg(2:2814)-3 */

    /*Implements PORT087*/
    /*Implements PORT223*/
    /* Return value LpModeChangeablePin - Changeable,
                    NULL                - Unchangeable */
    if (NULL_PTR == LpModeChangeablePin)
    {
      /*Implements PORT146*/
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of LpModeChangeablePin == NULL_PTR */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  } /* End of LenReturnValue == E_NOT_OK */
  /*Return LenReturnValue*/
  return(LenReturnValue);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /*#if ((PORT_DEV_ERROR_DETECT == STD_ON) && \
    (PORT_SET_PIN_MODE_API == STD_ON))*/


/*Implements EAAR_PN0034_FR_0049, AR_PN0062_FR_0004*/
/*******************************************************************************
** Function Name         : Port_PinModeHWRegSet
**
** Service ID            : NA
**
** Description           : This is the internal function called from
**                         Port_SetPinMode to access the mode set/reset,
**                         mode control set/reset, port set/reset registers
**                         for changing the mode of a pin during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Mode - New mode to be set on port pin.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**                         Port_SetPinMode should be called.
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : Port_SearchModeChangeablePin,
**                         Port_PinModeCtrlRegSet,Dem_ReportErrorStatus
**                         SchM_Enter_Port_PORT_SET_PIN_MODE_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_MODE_PROTECTION,
** Registers Used        : PMSRn,PMCSRn,PSRn,JPMSRn,JPMCSR0,JPSR0
*******************************************************************************/
/*Implements PORT_ESDD_UD_008*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_097*/
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinModeHWRegSet
  (CONST(Port_PinType, AUTOMATIC) Pin,
   CONST(Port_PinModeType, AUTOMATIC) Mode)
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpModeChangeablePin;
  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       LpFuncCtrlReg;
  /* Pointer to Port Registers Data structure */
  P2CONST (volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;
  /* Pointer to Direction Control Registers Data structure */
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST) LpPortPMSRReg;
  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST)LpRegAddr;
  /*Local variable to hold the baseAddress*/
  uint32 LulBaseAddress;

  /* MISRA Violation: START Msg(4:0759)-1 */
  /*Local variable to refer the 32-bit word of PMCSR register*/
  Port_Pin_Direction LunSRRegContent;
  /* MISRA Violation: END Msg(4:0759)-1 */

  /* Variable for revised mode */
  /*Implements PORT212*/
  Port_PinModeType LucMode;
  /*Initialize direction and mode value */
  uint16 LusCurrentDirection;
  uint16 LusCurrentMode;

  /*Initialize direction and mode value */
  LusCurrentDirection = PORT_SET_WORD;
  LusCurrentMode = PORT_SET_WORD;

  /* QAC Warning: START Msg(2:2814)-3 */
  /* Check whether the Pin is mode changeable at run time */
  LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);
  /* QAC Warning: END Msg(2:2814)-3 */

  if (NULL_PTR != LpModeChangeablePin)
  {
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Get the pointer to the Set Mode group list */
    LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                    + (LpModeChangeablePin->ucSetModeIndex));
    /* MISRA Violation: END Msg(4:0488)-6 */

    /* If the Pin group is of Numeric type */
    /*Implements PORT_ESDD_UD_088*/
    /*Implements PORT_ESDD_UD_102*/
    #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
    if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
    {
      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      LpPortPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      /*Implements PORT_ESDD_UD_016*/
      /*Implements AR_PN0062_FR_0026*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
    else
    {
      LpPortReg = Port_GpConfigPtr->pPortJRegs;
      LpPortPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
      /*Implements PORT_ESDD_UD_018*/
      /*Implements AR_PN0062_FR_0026*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    } /*End of ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)*/
    #endif /*     #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */
    /* Check if the value of Mode passed is greater than 1 */
    if (PORT_DIO_IN < Mode)
    {
      /* Value of Mode passed is greater than 1. Hence add 14 to the value */
      LucMode = Mode + PORT_MODE_ADJUST;
    }
    else
    {
      /* Keep the same value of Mode */
      LucMode = Mode;
    }

    /* Set the bit position in the upper 16 bits (31-16) of the PSR
     * variable to 1 of the configured pin whose Mode has to be changed */
    LunSRRegContent.Tst_Port_Word.usMSWord = LpModeChangeablePin->usOrMask;

    /*Check for PMSR register availability */
    /* QAC Warning: START Msg(2:2814)-3 */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMSRRegIndex)
    /* QAC Warning: END Msg(2:2814)-3 */
    {
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* QAC Warning: START Msg(2:2824)-2 */
      /* Get the PMSR register Address */
      LpRegAddr = ( volatile uint32 *)((LpPortPMSRReg +
                    LpSetPinModeGroupStruct->ucPMSRRegIndex)->usRegAddrOffset
                      + LulBaseAddress);
      /* QAC Warning: END Msg(2:2824)-2 */
      /* MISRA Violation: END Msg(4:0303)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* QAC Warning: START Msg(2:2814)-3 */
      /* Get the current direction on the requested pin, Input or Output */
      LusCurrentDirection = (((uint16)(*LpRegAddr)) &
                              LpModeChangeablePin->usOrMask);
      /* QAC Warning: END Msg(2:2814)-3 */
    }
    else
    {
       /*no action required */
    }
    /*Check for PMCSR register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMCSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* QAC Warning: START Msg(2:2824)-2 */

      /* Get the PMCSR register Address */
      LpRegAddr = (volatile uint32 *)((LpFuncCtrlReg +
                      LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usRegAddrOffset
                      + LulBaseAddress);
      /* QAC Warning: END Msg(2:2824)-2 */
      /* MISRA Violation: END Msg(4:0303)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* Get the current mode on the pin, Alternate or Dio */
      LusCurrentMode = (((uint16)(*LpRegAddr)) &
                             LpModeChangeablePin->usOrMask);
    }
    else
    {
       /*no action required */
    }

    /* Update the PSR register to initial values only if requested mode is
       DIO_OUT and current mode on the pin is not DIO_OUT */
    if ((PORT_DIO_OUT == Mode) &&
      ((LusCurrentMode | LusCurrentDirection) == LpModeChangeablePin->usOrMask))
    {
      /* Check for PSR register availability */
      if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPSRRegIndex)
      {
        /* QAC Warning: START Msg(2:2824)-2 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Write Initial mode register value into Lower word of PSR variable */
        LunSRRegContent.Tst_Port_Word.usLSWord = (LpPortReg +
                LpSetPinModeGroupStruct->ucPSRRegIndex)->usInitModeRegVal;
        /* QAC Warning: END Msg(2:2824)-2 */
        /* MISRA Violation: END Msg(4:0488)-6 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Get the PSR register Address */
        LpRegAddr = (volatile uint32 *)((LpPortReg +
                    LpSetPinModeGroupStruct->ucPSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
        /* MISRA Violation: END Msg(4:0488)-6 */
        /* MISRA Violation: END Msg(4:0303)-2 */

        /*An atomic access to Microcontroller registers by the use of an
          exclusive area */
        /*Implements PORT075*/
        /* Enter critical section */
        /*Implements PORT_ESDD_UD_005*/
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*Implements PORT138*/
        /* Bit value of Upper 16 bits (31-16) of PSR register is to set 1
           Bit value of Lower 16 bits (15-0) of PSR register = Initial value
           for the corresponding pin position */
        PORT_REG_WRITE(*LpRegAddr,LunSRRegContent.ulRegContent)

        /* Exit critical section */
        /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
        /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
        #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
        PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
        #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

        /*Write verify on PSR register*/
        /* QAC Warning: START Msg(2:3892)-4 */
        PORT_REG_WRITE_VERIFY_RUNTIME( *LpRegAddr,
        (LunSRRegContent.ulRegContent & LpModeChangeablePin->usOrMask),
        (LunSRRegContent.ulRegContent >>
        PORT_SIXTEEN),PORT_SET_PIN_MODE_SID)
        /* QAC Warning: END Msg(2:3892)-4 */
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
    Port_PinModeCtrlRegSet(Pin, LucMode);
  }/* End of if(LpModeChangeablePin != NULL_PTR)*/
  else
  {
    /*no action required */
  }
}

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* #if (PORT_SET_PIN_MODE_API == STD_ON)*/

/*Implements EAAR_PN0034_FR_0049, AR_PN0062_FR_0004*/
/*******************************************************************************
** Function Name         : Port_PinModeCtrlRegSet
**
** Service ID            : NA
**
** Description           : This is the internal function called from
**                         Port_PinModeHWRegSet to access the mode set/reset,
**                         mode control set/reset registers for changing the
**                         mode of a pin during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         LucMode - New mode to be set on port pin.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**                         Port_SetPinMode should be called.
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : Port_SearchModeChangeablePin,Dem_ReportErrorStatus
**                         SchM_Enter_Port_PORT_SET_PIN_MODE_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_MODE_PROTECTION,
**                         Port_PinModeFuncRegSet
**
** Registers Used        : PMSRn,PMCSRn,JPMSR0,JPMCSR0
*******************************************************************************/
/*Implements PORT_ESDD_UD_008*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_098*/
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinModeCtrlRegSet
   (CONST(Port_PinType, AUTOMATIC) Pin,
   CONST(Port_PinModeType, AUTOMATIC) LucMode)
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpModeChangeablePin;
  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       LpFuncCtrlReg;
  /* Pointer to Direction Control Registers Data structure */
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST) LpPortPMSRReg;
  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST)LpRegAddr;
  /*Local variable to hold the baseAddress*/
  uint32 LulBaseAddress;
  /*Local variable to refer the 32-bit word of PMCSR register*/
  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;
  /* MISRA Violation: END Msg(4:0759)-1 */

  /* QAC Warning: START Msg(2:2814)-3 */
  /* Check whether the Pin is mode changeable at run time */
  LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);
  /* QAC Warning: END Msg(2:2814)-3 */

  if (NULL_PTR != LpModeChangeablePin)
  {
    /* Get the pointer to the Set Mode group list */
    /* MISRA Violation: START Msg(4:0488)-6 */
    LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                    + (LpModeChangeablePin->ucSetModeIndex));
    /* MISRA Violation: END Msg(4:0488)-6 */

    /* If the Pin group is of Numeric type */
    /*Implements PORT_ESDD_UD_088*/
    /*Implements PORT_ESDD_UD_102*/
    #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
            (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
    if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
    {
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      LpPortPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
      /*Implements PORT_ESDD_UD_016*/
      /*Implements AR_PN0062_FR_0026*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
    else
    {
      LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
      LpPortPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
      /*Implements PORT_ESDD_UD_018*/
      /*Implements AR_PN0062_FR_0026*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    } /* End of (PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)*/
    #endif /* End of ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
            (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */

    /* Set the bit position in the upper 16 bits (31-16) of the PMCSR or PMSR
       variable to 1 of the configured pin whose Mode has to be changed */
    LunSRRegContent.Tst_Port_Word.usMSWord = LpModeChangeablePin->usOrMask;

    /* Check for PMSR register availability */
    /* QAC Warning: START Msg(2:2814)-3 */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMSRRegIndex)
    /* QAC Warning: END Msg(2:2814)-3 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* QAC Warning: START Msg(2:2824)-2 */
      /* Get the PMSR register Address */
      LpRegAddr = (volatile uint32 *)((LpPortPMSRReg +
                    LpSetPinModeGroupStruct->ucPMSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
      /* QAC Warning: END Msg(2:2824)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */
      /* MISRA Violation: END Msg(4:0303)-2 */

      /* QAC Warning: START Msg(2:3892)-4 */
      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT0_MASK))
      /* QAC Warning: END Msg(2:3892)-4 */
      {
        /* Write the requested direction into Lower word of PMSR variable
         * by using inverse of OR mask  */
        LunSRRegContent.Tst_Port_Word.usLSWord = ~LpModeChangeablePin->usOrMask;
      } /* End of (Mode & PORT_BIT0_MASK) == PORT_ZERO */
      else
      {
        /* Write the requested direction into Lower word of PMSR variable
         * by using OR mask */
        LunSRRegContent.Tst_Port_Word.usLSWord = LpModeChangeablePin->usOrMask;
      }
      /*An atomic access to Microcontroller registers by the use of an
        exclusive area */
      /*Implements PORT075*/
      /* Enter critical section */
      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* Write the contents of Lower word and Upper word of PMSR variable
      * into the PMSR register address  */
      /* QAC Warning: START Msg(2:2814)-3 */
      PORT_REG_WRITE(*LpRegAddr,LunSRRegContent.ulRegContent)
      /* QAC Warning: END Msg(2:2814)-3 */

      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*Write verify check on PMSR register*/
      /* QAC Warning: START Msg(2:3892)-4 */
      PORT_REG_WRITE_VERIFY_RUNTIME(*LpRegAddr,(LunSRRegContent.ulRegContent &
      LpModeChangeablePin->usOrMask),(LunSRRegContent.ulRegContent >>
      PORT_SIXTEEN),PORT_SET_PIN_MODE_SID)
      /* QAC Warning: END Msg(2:3892)-4 */
    }
    else
    {
      /* No action required */
    }
    Port_PinModeFuncRegSet(Pin, LucMode);
    /* Write PMCSR register. Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMCSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* QAC Warning: START Msg(2:2824)-2 */
      /* Get the address of PMCSR register */
      LpRegAddr = (volatile uint32 *)((LpFuncCtrlReg +
                  LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usRegAddrOffset
                  + LulBaseAddress);
      /* QAC Warning: END Msg(2:2824)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */
      /* MISRA Violation: END Msg(4:0303)-2 */

      /* QAC Warning: START Msg(2:3892)-4 */
      if (PORT_ZERO == (LucMode & PORT_BIT4_MASK))
      /* QAC Warning: END Msg(2:3892)-4 */
      {
        /* Write the requested direction into Lower word of PMCSR variable
         * by using inverse of OR mask */
        LunSRRegContent.Tst_Port_Word.usLSWord = ~LpModeChangeablePin->usOrMask;
      } /* End of (Mode & PORT_BIT4_MASK) == PORT_ZERO */
      else
      {
        /* Write the requested direction into Lower word of PMCSR variable
         * by using OR mask */
        LunSRRegContent.Tst_Port_Word.usLSWord = LpModeChangeablePin->usOrMask;
      }

      /*An atomic access to Microcontroller registers by the use of an
        exclusive area */
      /*Implements PORT075*/
      /* Enter critical section */

      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* QAC Warning: START Msg(2:2814)-3 */
      /* Write the corresponding 32 bit value to the PMCSR register */
      PORT_REG_WRITE(*LpRegAddr,LunSRRegContent.ulRegContent)
      /* QAC Warning: END Msg(2:2814)-3 */

      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*Write verify check on PMCSR register*/
      /* QAC Warning: START Msg(2:3892)-4 */
      PORT_REG_WRITE_VERIFY_RUNTIME(*LpRegAddr,(LunSRRegContent.ulRegContent &
      LpModeChangeablePin->usOrMask),(LunSRRegContent.ulRegContent >>
      PORT_SIXTEEN),PORT_SET_PIN_MODE_SID)
      /* QAC Warning: END Msg(2:3892)-4 */

    } /* End of Write PMCSR register */
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
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if (PORT_SET_PIN_MODE_API == STD_ON)*/

/*Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049*/
/*******************************************************************************
** Function Name         : Port_PinModeFuncRegSet
**
** Service ID            : NA
**
** Description           : This is the internal function called from
**                         Port_PinModeCtrlRegSet to access the port function
**                         control register for changing the mode of a
**                         pin during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         LucMode - New mode to be set on port pin.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**                         Port_SetPinMode should be called.
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : Port_SearchModeChangeablePin,Dem_ReportErrorStatus
**                         SchM_Enter_Port_PORT_SET_PIN_MODE_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_MODE_PROTECTION,
**
** Registers Used        : PFCEn,PFCn,PFCAEn,JPFCE0.
*******************************************************************************/
/*Implements PORT_ESDD_UD_008*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_099*/
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinModeFuncRegSet
   (CONST(Port_PinType, AUTOMATIC) Pin,
   CONST(Port_PinModeType, AUTOMATIC) LucMode)
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                          LpModeChangeablePin;
  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                                LpFuncCtrlReg;
  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST) LpTwoByteRegAddr;
  uint32 LulBaseAddress;

  /* Check whether the Pin is mode changeable at run time */
  /* QAC Warning: START Msg(2:2814)-3 */
  LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                        Port_GpConfigPtr->pPinModeChangeableDetails,
                        Port_GpConfigPtr->ucNoOfPinsModeChangeable);
  /* QAC Warning: END Msg(2:2814)-3 */

  /*Check if the LpModeChangeablePin points to NULL POINTER*/
  if (NULL_PTR != LpModeChangeablePin)
  {
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Get the pointer to the Set Mode group list */
    LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                    + (LpModeChangeablePin->ucSetModeIndex));
    /* MISRA Violation: END Msg(4:0488)-6 */

    /* If the Pin group is of Numeric type */
    /*Implements PORT_ESDD_UD_088*/
    /*Implements PORT_ESDD_UD_102*/
    #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
    if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
    {
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      /*Implements PORT_ESDD_UD_016*/
      /*Implements AR_PN0062_FR_0026*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    }
    else
    {
      LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
      /*Implements PORT_ESDD_UD_018*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */

    #endif /* #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )  */

    /* Write PFCE register.Check for register availability */
    /* QAC Warning: START Msg(2:2814)-3 */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCERegIndex)
    /* QAC Warning: END Msg(2:2814)-3 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* QAC Warning: START Msg(2:2824)-2 */
      LpTwoByteRegAddr = (volatile uint16 *)((LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCERegIndex)->usRegAddrOffset +
               LulBaseAddress);
      /* QAC Warning: END Msg(2:2824)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */
      /* MISRA Violation: END Msg(4:0303)-2 */

      /*An atomic access to Microcontroller registers by the use of an
        exclusive area */
      /*Implements PORT075*/
      /* Enter critical section */

      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* QAC Warning: START Msg(2:3892)-4 */
      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT2_MASK))
      /* QAC Warning: END Msg(2:3892)-4 */
      {
        /* QAC Warning: START Msg(2:2814)-3 */
        /*If bit needs to reset, AND the register contents with
        Inverse of OrMask */
        PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr)&
                   ((uint16)(~LpModeChangeablePin->usOrMask))))
        /* QAC Warning: END Msg(2:2814)-3 */

        /* Write Verify Check for PFCE register*/
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr, ((*LpTwoByteRegAddr) &
                   ((uint16)(~LpModeChangeablePin->usOrMask))),PORT_SET_WORD,
                                                     PORT_SET_PIN_MODE_SID)
      }
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) |
                      ((uint16)LpModeChangeablePin->usOrMask)))

        /* Write Verify Check for PFCE register*/
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) |
                  ((uint16)LpModeChangeablePin->usOrMask)),PORT_SET_WORD,
                                                  PORT_SET_PIN_MODE_SID )
      }
      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    } /* End of Write PFCE register */
    else
    {
      /* No action required */
    }
    /* Write PFC register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCRegIndex)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      LpTwoByteRegAddr = (volatile uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCRegIndex)->usRegAddrOffset +
                 LulBaseAddress);
      /* MISRA Violation: END Msg(4:0488)-6 */
      /* MISRA Violation: END Msg(4:0303)-2 */

      /*An atomic access to Microcontroller registers by the use of an
         exclusive area */
      /*Implements PORT075*/
      /* Enter critical section */

      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* QAC Warning: START Msg(2:3892)-4 */
      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT1_MASK))
      /* QAC Warning: END Msg(2:3892)-4 */
      {
        /* If bit needs to be reset, AND the register contents with OrMask */
        PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) &
                              ((uint16)(~LpModeChangeablePin->usOrMask))))
        /* Write Verify Check for PFC register*/
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) &
               ((uint16)(~LpModeChangeablePin->usOrMask))), PORT_SET_WORD,
                                                    PORT_SET_PIN_MODE_SID)
      } /* End of (Mode & PORT_BIT1_MASK) == PORT_ZERO */
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) |
                 ((uint16)LpModeChangeablePin->usOrMask)))
        /* Write Verify Check for PFC register*/
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) |
        ((uint16)LpModeChangeablePin->usOrMask)), PORT_SET_WORD,
                                                    PORT_SET_PIN_MODE_SID)
      }
      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    }
    else
    {
      /* No action required */
    }
    /* Write PFCAE register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCAERegIndex)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      LpTwoByteRegAddr = (volatile uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCAERegIndex)->usRegAddrOffset
                 + LulBaseAddress);
      /* MISRA Violation: END Msg(4:0488)-6 */
      /* MISRA Violation: END Msg(4:0303)-2 */


      /*An atomic access to Microcontroller registers by the use of an
         exclusive area */
      /*Implements PORT075*/
      /* Enter critical section */

      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* QAC Warning: START Msg(2:3892)-4 */
      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT3_MASK))
      /* QAC Warning: END Msg(2:3892)-4 */
      {
        /* If bit needs to be reset, AND the register contents with OrMask */
        PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) &
                               ((uint16)(~LpModeChangeablePin->usOrMask))))
        /* Write Verify Check for PFCAE register*/
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) &
               ((uint16)(~LpModeChangeablePin->usOrMask))), PORT_SET_WORD,
                                                    PORT_SET_PIN_MODE_SID)
      } /* End of (Mode & PORT_BIT3_MASK) == PORT_ZERO */
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        PORT_REG_WRITE(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) |
                       ((uint16)LpModeChangeablePin->usOrMask)))
        /* Write Verify Check for PFCAE register*/
        PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,((*LpTwoByteRegAddr) |
        ((uint16)LpModeChangeablePin->usOrMask)), PORT_SET_WORD,
                                                    PORT_SET_PIN_MODE_SID)
      }
      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    } /* End of Write PFCAE register */
    else
    {
      /* No action required */
    }
  }/* End of if(LpModeChangeablePin != NULL_PTR)*/
  else
  {
    /* No action required */
  }
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif  /*#if (PORT_SET_PIN_MODE_API == STD_ON))*/
/*******************************************************************************
** Function Name         : Port_PinDefModeDetCheck
**
** Service ID            : NA
**
** Description           : This function used to check the DET error conditions
**                         of Port_SetPinDefaultMode() Api
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : Port_SetPinDefaultMode() Api should be called
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         Port_SearchModeChangeablePin.
**
** Registers Used        : None.
*******************************************************************************/
/*Implements PORT_ESDD_UD_106*/
/*Implements PORT100, PORT107, PORT211, PORT123_Conf, EAAR_PN0034_FR_0049*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/*Implements PORT_ESDD_UD_008*/
/*Implements PORT_ESDD_UD_125*/
#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_100*/
STATIC FUNC (Std_ReturnType, PORT_PRIVATE_CODE) Port_PinDefModeDetCheck
     (CONST(Port_PinType, AUTOMATIC) Pin)
{
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                          LpModeChangeablePin;
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  /*Implements PORT077*/
  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }
  /* Check whether the requested PIN number is invalid */
  /*Implements PORT_ESDD_UD_081*/
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  if (E_OK == LenReturnValue)
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Check whether the Pin mode is changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                              Port_GpConfigPtr->pPinModeChangeableDetails,
                              Port_GpConfigPtr->ucNoOfPinsModeChangeable);
    /* QAC Warning: END Msg(2:2814)-3 */

    /* Return value LpModeChangeablePin - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpModeChangeablePin)
    {
      /*Implements PORT146*/
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                   PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of LpModeChangeablePin == NULL_PTR */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  } /* End of LenReturnValue == E_NOT_OK */
  return(LenReturnValue);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif  /*#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))*/
#endif /*#if (PORT_DEV_ERROR_DETECT == STD_ON)*/
/*Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049*/
/*******************************************************************************
** Function Name         : Port_PinDefModeFuncRegSet
**
** Service ID            : NA
**
** Description           : This function will set the function control registers
**                         to change the mode of a port pin during runtime. It
**                         will change the mode of the pin to default mode set
**                         by the configuration at the time of Port_Init()
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**                         Port_SetPinDefaultMode() should be invoked during
**                         runtime.
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : Port_SearchModeChangeablePin,Dem_ReportErrorStatus
**                         SchM_Enter_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION,
**                         SchM_Exit_Port_PORT_SET_PIN_DEFAULT_MODE_PROTECTION,
**
** Registers Used        : PFCEn,PFCn,PFCAEn,JPFCE0.
*******************************************************************************/
/*Implements PORT_ESDD_UD_008*/
/*Implements PORT_ESDD_UD_125*/
#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_101*/
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_PinDefModeFuncRegSet
   (CONST(Port_PinType, AUTOMATIC) Pin)
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                          LpModeChangeablePin;
  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                                LpFuncCtrlReg;
  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST) LpTwoByteRegAddr;
  uint32 LulBaseAddress;
  uint16 LusOrMask;

  /* QAC Warning: START Msg(2:2814)-3 */
  /* Check whether the Pin is mode changeable at run time */
  LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                        Port_GpConfigPtr->pPinModeChangeableDetails,
                        Port_GpConfigPtr->ucNoOfPinsModeChangeable);
  /* QAC Warning: END Msg(2:2814)-3 */

  /*Check if the LpModeChangeablePin points to NULL POINTER*/
  if (NULL_PTR != LpModeChangeablePin)
  {
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Get the pointer to the Set Mode group list */
    LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                    + (LpModeChangeablePin->ucSetModeIndex));
    /* MISRA Violation: END Msg(4:0488)-6 */

    /* If the Pin group is of Numeric type */
    /*Implements PORT_ESDD_UD_088*/
    /*Implements PORT_ESDD_UD_102*/
    /*Implements AR_PN0062_FR_0023*/
    #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
         (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
    if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
    {
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      /*Implements PORT_ESDD_UD_016*/
      /*Implements AR_PN0062_FR_0026*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
    else
    {
      LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
      /*Implements PORT_ESDD_UD_018*/
      /*Implements AR_PN0062_FR_0026*/
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_JTAG */
    #endif /*  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
           (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */

    /*Get the OrMaskValue*/
    LusOrMask = LpModeChangeablePin->usOrMask;

    /* QAC Warning: START Msg(2:2814)-3 */
    /* Write PFCE register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCERegIndex)
    /* QAC Warning: END Msg(2:2814)-3 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* QAC Warning: START Msg(2:2824)-2 */
      LpTwoByteRegAddr = (volatile uint16 *)((LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCERegIndex)->usRegAddrOffset +
                                                          LulBaseAddress);
      /* QAC Warning: END Msg(2:2824)-2 */
      /* MISRA Violation: END Msg(4:0303)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* Enter critical section */
      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* QAC Warning: START Msg(2:2814)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* If bit needs to be set, OR the register contents with OrMask */
       PORT_REG_WRITE(*LpTwoByteRegAddr,(((*LpTwoByteRegAddr)&
         (uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
         LpSetPinModeGroupStruct->ucPFCERegIndex)->usInitModeRegVal) &
                                                          LusOrMask)))
      /* QAC Warning: END Msg(2:2814)-3 */
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*Write verify check on PFCE register*/
      /* MISRA Violation: START Msg(4:0488)-6 */
      PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,(((*LpTwoByteRegAddr)&
         (uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
         LpSetPinModeGroupStruct->ucPFCERegIndex)->usInitModeRegVal) &
           LusOrMask)),PORT_SET_WORD, PORT_SET_PIN_DEFAULT_MODE_SID )
      /* MISRA Violation: END Msg(4:0488)-6 */

    } /* End of Write PFCE register */
    else
    {
      /* No action required */
    }
    /* Write PFC register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCRegIndex)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      LpTwoByteRegAddr = (volatile uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCRegIndex)->usRegAddrOffset +
                                                           LulBaseAddress);
      /* MISRA Violation: END Msg(4:0303)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* Enter critical section */
      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* MISRA Violation: START Msg(4:0488)-6 */
      /* If bit needs to be set, OR the register contents with OrMask */
      PORT_REG_WRITE(*LpTwoByteRegAddr,
       (((*LpTwoByteRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCRegIndex)->usInitModeRegVal) &
                                                                   LusOrMask)))
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*Write verify check on PFC register*/
      /* MISRA Violation: START Msg(4:0488)-6 */
      PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,
       (((*LpTwoByteRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCRegIndex)->usInitModeRegVal) &
                   LusOrMask)), PORT_SET_WORD, PORT_SET_PIN_DEFAULT_MODE_SID )
      /* MISRA Violation: END Msg(4:0488)-6 */
    } /* End of Write PFC register */
    else
    {
      /* No action required */
    }
    /* Write PFCAE register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCAERegIndex)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      LpTwoByteRegAddr = (volatile uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCAERegIndex)->usRegAddrOffset
                                                          + LulBaseAddress);
      /* MISRA Violation: END Msg(4:0303)-2 */
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* Enter critical section */
      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* MISRA Violation: START Msg(4:0488)-6 */
      /* If bit needs to be set, OR the register contents with OrMask */
      PORT_REG_WRITE(*LpTwoByteRegAddr,
      (((*LpTwoByteRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
            LpSetPinModeGroupStruct->ucPFCAERegIndex)->usInitModeRegVal) &
                                                                   LusOrMask)))
      /* MISRA Violation: END Msg(4:0488)-6 */

      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_SET_PIN_DEFAULT_MODE_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*Write verify check on PFCAE register*/
      /* MISRA Violation: START Msg(4:0488)-6 */
      PORT_REG_WRITE_VERIFY_RUNTIME(*LpTwoByteRegAddr,
      (((*LpTwoByteRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
            LpSetPinModeGroupStruct->ucPFCAERegIndex)->usInitModeRegVal) &
            LusOrMask)),PORT_SET_WORD, PORT_SET_PIN_DEFAULT_MODE_SID  )
      /* MISRA Violation: END Msg(4:0488)-6 */

    } /* End of Write PFCAE register */
    else
    {
      /* No action required */
    }
  }/*End of if(LpModeChangeablePin != NULL_PTR)*/
  else
  {
      /* No action required */
  }
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif  /*#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))*/

/*Implements PORT100, PORT107, PORT211, PORT123_Conf, EAAR_PN0034_FR_0049*/
/*******************************************************************************
** Function Name         : Port_PinDirectionDetCheck
**
** Service ID            : NA
**
** Description           : This service check the DET error condition of
**                         Port_SetPinDirection API.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Direction - Port Pin Direction
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : Ports should be initialized by calling Port_Init().
**                         Port_SetPinDirection should be called
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         Port_SearchDirChangeablePin
**
** Registers Used        : None
*******************************************************************************/
/*Implements PORT086*/
/*Implements PORT_ESDD_UD_082*/
/*Implements PORT_ESDD_UD_106*/

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/*Implements PORT131*/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_095*/
STATIC FUNC (Std_ReturnType, PORT_PRIVATE_CODE) Port_PinDirectionDetCheck
(CONST(Port_PinType,AUTOMATIC) Pin )
{
  P2CONST(volatile Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
                                                       LpChangeablePinDet;
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  /* Check whether the PORT module is initialized */
  /*Implements PORT087*/
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                               PORT_SET_PIN_DIR_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /*Implements PORT087*/
  /* Check whether the requested PIN number is invalid */
  /*Implements PORT_ESDD_UD_081*/
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /*Implements PORT146*/
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                            PORT_SET_PIN_DIR_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);
    /* QAC Warning: END Msg(2:2814)-3 */
    /* Return value LpChangeablePinDet - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpChangeablePinDet)
    {
      /*Implements PORT087*/
      /*Implements PORT146*/
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                 PORT_SET_PIN_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
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
  return(LenReturnValue);
}

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* #if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/
#endif /*#if (PORT_DEV_ERROR_DETECT == STD_ON)*/

/*Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049, AR_PN0062_FR_0004*/
/*Implements AR_PN0062_FR_0011, AR_PN0062_FR_0013*/
/*******************************************************************************
** Function Name         : Port_HWInitConfig
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize the Set/Reset,
**                         Input Buffer control, IP Control,Pull-Up/Down
**                         Option,Input buffer selection registers and
**                         Bi-direction control of Numeric and JTag ports
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : SchM_Enter_Port_PORT_INIT_CONFIG_PROTECTION,
**                         SchM_Exit_Port_PORT_INIT_CONFIG_PROTECTION,
**                         Dem_ReportErrorStatus
**
** Registers Used        : PSRn,JPSR0,PISAn,JPISA0,PIBCn,JPIBC0,PIPCn,PUn,JPU0,
**                         PDn,JPD0,PBDCn,JPBDC0
*******************************************************************************/
/*Implements PORT_ESDD_UD_088*/
/*Implements PORT_ESDD_UD_102*/
#if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
     (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_091*/
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_HWInitConfig
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType)
{
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortReg;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpFourByteRegAddress;
  P2VAR(volatile uint16, AUTOMATIC, PORT_CONFIG_DATA) LpTwoByteRegAddress;
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) LpOneByteRegAddress;
  #endif
  uint32 LulUserBaseAddress;
  uint32 LulOsBaseAddress;
  uint8 LucNoOfRegs;
  uint8 LucNoOfPSRRegs;
  uint8 LucNoOfOther16BitRegs;
  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  boolean LblJtag = PORT_FALSE;
  #endif

  /*Implements PORT_ESDD_UD_088*/
  /*Implements PORT_ESDD_UD_102*/
  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
         (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /* Get the pointer to the Numeric Port registers */
    /* QAC Warning: START Msg(2:2814)-3 */
    LpPortReg = Port_GpConfigPtr->pPortNumRegs;
    /* QAC Warning: END Msg(2:2814)-3 */

    /* Get the total number of Numeric PSR registers */
    /*Implements PORT_ESDD_UD_037*/
    LucNoOfPSRRegs = PORT_NUM_PSR_REGS;
    /* Get the total number of Numeric Other 16 Bit registers */
    /*Implements PORT_ESDD_UD_039*/
    LucNoOfOther16BitRegs = PORT_NUM_OTHER_16BIT_REGS;
    /* Get the Base address of Numeric Port */
    /*Implements PORT_ESDD_UD_016*/
    /*Implements AR_PN0062_FR_0026*/
    LulUserBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    /* Get the Base address of Numeric Port */
    /*Implements PORT_ESDD_UD_017*/
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  {
    /* Get the pointer to the JTag Port registers */
    LpPortReg = Port_GpConfigPtr->pPortJRegs;
    /* Get the total number of JTAG PSR registers */
    /*Implements PORT_ESDD_UD_029*/
    LucNoOfPSRRegs = PORT_JTAG_PSR_REGS;
    /* Get the total number of JTag Other 8 Bit registers */
    /*Implements PORT_ESDD_UD_031*/
    LucNoOfOther16BitRegs = PORT_JTAG_OTHER_8BIT_REGS;
    /* Get the Base address of JTag Port */
    /*Implements PORT_ESDD_UD_018*/
    /*Implements AR_PN0062_FR_0026*/
    LulUserBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
    /* Get the Base address of JTag Port */
    /*Implements PORT_ESDD_UD_019*/
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
    /* Update the local variable as one */
    LblJtag = PORT_TRUE;
  } /* End of LenGroupType == PORT_GROUP_JTAG */
  #endif /*  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
         (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */

  /*Implements PORT_ESDD_UD_005*/
  /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
  /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  PORT_ENTER_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  /* Get the count of total number of PSR registers */
  LucNoOfRegs = LucNoOfPSRRegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Get the register address by adding the offset with the Base address */
    LpFourByteRegAddress =
          (volatile uint32 *)(LpPortReg->usRegAddrOffset + LulUserBaseAddress);
    /* QAC Warning: END Msg(2:2814)-3 */
    /* MISRA Violation: END Msg(4:0303)-2 */

    /*Implements PORT055*/
    /* QAC Warning: START Msg(2:2814)-3 */
    /* Write the register value to the corresponding register */
    PORT_REG_WRITE(*LpFourByteRegAddress,
              ((uint32)LpPortReg->usInitModeRegVal | PORT_MSB_MASK))
    /* QAC Warning: END Msg(2:2814)-3 */

    /*Write verify check on PSR registers*/
    PORT_REG_WRITE_VERIFY_INIT(*LpFourByteRegAddress,
    ((uint32)LpPortReg->usInitModeRegVal), PORT_SET_LONG_WORD, PORT_INIT_SID)

    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* Get the count of total number of Other 16Bit registers
    (PISAn,JPISA0,PIBCn,JPIBC0,PIPCn,PUn,JPU0,PDn,JPD0,PBDCn,JPBDC0)*/
  LucNoOfRegs = LucNoOfOther16BitRegs;

  while (PORT_ZERO < LucNoOfRegs)
  {
    /*Implements PORT_ESDD_UD_088*/
    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    if (PORT_TRUE == LblJtag )
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Get the register address by adding the offset to the Base address */
      LpOneByteRegAddress =
             (volatile uint8 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
      /* MISRA Violation: END Msg(4:0303)-2 */

      /* Write the register value to the corresponding register */
      /* QAC Warning: START Msg(2:2814)-3 */
      PORT_REG_WRITE(*LpOneByteRegAddress,((uint8)LpPortReg->usInitModeRegVal))
      /* QAC Warning: END Msg(2:2814)-3 */

      /* QAC Warning: START Msg(2:3892)-4 */
      PORT_REG_WRITE_VERIFY_INIT(*LpOneByteRegAddress,
      ((uint8)LpPortReg->usInitModeRegVal),PORT_SET_BYTE ,PORT_INIT_SID)
      /* QAC Warning: END Msg(2:3892)-4 */
    }
    else
    #endif
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Get the register address by adding the offset to the Base address */
      LpTwoByteRegAddress =
          (volatile uint16 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
      /* MISRA Violation: END Msg(4:0303)-2 */

      /* QAC Warning: START Msg(2:2814)-3 */
      /* Write the register value to the corresponding register */
      PORT_REG_WRITE(*LpTwoByteRegAddress,LpPortReg->usInitModeRegVal)
      /* QAC Warning: END Msg(2:2814)-3 */

      /*Write verify check on corresponding register*/
      PORT_REG_WRITE_VERIFY_INIT(*LpTwoByteRegAddress,
      LpPortReg->usInitModeRegVal, PORT_SET_WORD, PORT_INIT_SID)
    }

    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
  /* Exit critical section */
  /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
  /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  PORT_EXIT_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
}

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*Implements EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049, AR_PN0062_FR_0006*/
/*Implements AR_PN0062_FR_0021*/
/*******************************************************************************
** Function Name         : Port_OpenDrainCtrlRegInit
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the PODC,PODCE
**                         registers of numeric and JTag ports.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : SchM_Enter_Port_PORT_INIT_CONFIG_PROTECTION,
**                         SchM_Exit_Port_PORT_INIT_CONFIG_PROTECTION,
**                         Port_DriveUnivCtrlRegInit,Dem_ReportErrorStatus
**
** Registers Used        : JPPROTS0,JPPCMD0,PODCn,JPODC0,PODCEn,PPCMDn,PPROTSn
*******************************************************************************/
/*Implements PORT_ESDD_UD_088*/
/*Implements PORT_ESDD_UD_102*/
#if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
     (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_092*/
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_OpenDrainCtrlRegInit
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType)
{
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpFourByteRegAddress;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPODCReg;
  uint32 LulOsBaseAddress;
  uint32 LulProtectedRegValue;
  uint32 LulNumeric;
  uint32 LulJtag;
  uint8 LucNoOfRegs;
  uint8 LucNoOfPODCRegs;
  uint8 LucNoOfPODCERegs;
  uint8 LucLoopCount;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPROTSRegAdd;
  Std_ReturnType LenReturnValue = E_OK;
  /*Initialize with Zero*/
  LulNumeric = PORT_LONG_WORD_ZERO;
  LulJtag = PORT_LONG_WORD_ZERO;

  /*Implements PORT_ESDD_UD_088*/
  /*Implements PORT_ESDD_UD_102*/
  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
         (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /* Get the pointer to the Numeric Port registers */
    /* QAC Warning: START Msg(2:2814)-3 */
    LpPortReg = Port_GpConfigPtr->pPortNumRegs;
    /* QAC Warning: END Msg(2:2814)-3 */
    /* Get the Base address of Numeric Port */
    /*Implements PORT_ESDD_UD_017*/
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
    /* Get the total number of Numeric PODC registers */
    /*Implements PORT_ESDD_UD_040*/
    LucNoOfPODCRegs = PORT_NUM_PODC_REGS;
    /* Get the total number of Numeric PODCE registers */
    /*Implements PORT_ESDD_UD_041*/
    LucNoOfPODCERegs = PORT_NUM_PODCE_REGS;
    /* Get the pointer to the Numeric PODC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /* QAC Warning: START Msg(2:2824)-2 */
    /*Implements PORT_ESDD_UD_037*/
    /*Implements PORT_ESDD_UD_115*/
    /*Implements PORT_ESDD_UD_128*/
    /*Implements PORT_ESDD_UD_129*/
    /*Implements PORT_ESDD_UD_130*/
    /*Implements PORT_ESDD_UD_131*/
    LpPortPODCReg = LpPortReg + (PORT_NUM_PSR_REGS + PORT_NUM_PISA_REGS
                  + PORT_NUM_PIBC_REGS + PORT_NUM_PIPC_REGS
                  + PORT_NUM_PU_REGS + PORT_NUM_PD_REGS
                  + PORT_NUM_PBDC_REGS);
    /* QAC Warning: END Msg(2:2824)-2 */
    /* QAC Warning: END Msg(2:3892)-4 */
    /* MISRA Violation: END Msg(4:0488)-6 */
    LulNumeric = PORT_SET_LONG_WORD;
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  {
    /* Get the pointer to the JTag Port registers */
    LpPortReg = Port_GpConfigPtr->pPortJRegs;
    /* Get the Base address of JTag Port */
    /*Implements PORT_ESDD_UD_019*/
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
    /* Get the total number of JTag PODC registers */
    /*Implements PORT_ESDD_UD_032*/
    LucNoOfPODCRegs = PORT_JTAG_PODC_REGS;
    /* Get the total number of JTag PODCE registers */
    /*Implements PORT_ESDD_UD_035*/
    LucNoOfPODCERegs = PORT_JTAG_PODCE_REGS;
    /* Get the pointer to the JTAG PODC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /*Implements PORT_ESDD_UD_029*/
    /*Implements PORT_ESDD_UD_116*/
    /*Implements PORT_ESDD_UD_117*/
    /*Implements PORT_ESDD_UD_118*/
    /*Implements PORT_ESDD_UD_119*/
    /*Implements PORT_ESDD_UD_123*/
    LpPortPODCReg = LpPortReg + (PORT_JTAG_PSR_REGS + PORT_JTAG_PISA_REGS
                + PORT_JTAG_PIBC_REGS + PORT_JTAG_PU_REGS + PORT_JTAG_PD_REGS
                + PORT_JTAG_PBDC_REGS);
    /* QAC Warning: END Msg(2:3892)-4 */
    /* MISRA Violation: END Msg(4:0488)-6 */
    /* Update the local variable as one */
    LulJtag = PORT_SET_LONG_WORD;
  } /* End of LenGroupType == PORT_GROUP_JTAG */
  #endif /* End of  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
         (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */
  /* Get the count of total number of 32Bit PODC registers */
  LucNoOfRegs = LucNoOfPODCRegs;
  /* Get the pointer of PODC register top */
  LpPortReg = LpPortPODCReg;
  while ((PORT_ZERO < LucNoOfRegs ) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    /*Implements EAAR_PN0034_FSR_0011, EAAR_PN0034_FSR_0012 */
    /*Implements EAAR_PN0034_FSR_0013 */
    /*Implements PORT_ESDD_UD_068*/
    LucLoopCount = PORT_LOOP_TIMEOUT;
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Get the register address by adding the offset with the Base address */
    LpFourByteRegAddress =
          (volatile uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* MISRA Violation: END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:2984)-8 */
    /* Get the address of the corresponding PPROTS register */
    /*Implements PORT_ESDD_UD_053*/
    /*Implements PORT_ESDD_UD_056*/
    /*Implements PORT_ESDD_UD_060*/
    /*Implements PORT_ESDD_UD_063*/
    /*Implements AR_PN0062_FR_0025*/
    LpPPROTSRegAdd = (volatile uint32 *)
                     (((uint32)(LpPortReg->usRegAddrOffset) -
                      (((uint32)PORT_NUM_PODC_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PODC_REG_ADD_OFFSET & LulJtag)) +
                      LulOsBaseAddress) +
                      ((uint32)PORT_NUM_PPROTS_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PPROTS_REG_ADD_OFFSET & LulJtag));

    /* Get the address of the corresponding PPCMD register */
    /*Implements PORT_ESDD_UD_057*/
    /*Implements PORT_ESDD_UD_060*/
    /*Implements PORT_ESDD_UD_064*/
    /*Implements AR_PN0062_FR_0025*/
    LpPPCMDRegAdd = (volatile uint32 *)
                    (((uint32)(LpPortReg->usRegAddrOffset) -
                     (((uint32)PORT_NUM_PODC_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PODC_REG_ADD_OFFSET & LulJtag)) +
                     LulOsBaseAddress) +
                     ((uint32)PORT_NUM_PPCMD_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PPCMD_REG_ADD_OFFSET & LulJtag));
    /* MISRA Violation: END Msg(4:2984)-8 */
    /* MISRA Violation: END Msg(4:3393)-10 */
    /* MISRA Violation: END Msg(4:0303)-2 */
    LulProtectedRegValue = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

    /*Implements PORT_ESDD_UD_005*/
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*Implements PORT_ESDD_UD_051*/
    /* QAC Warning: START Msg(2:2814)-3 */
    PORT_PROTECTEDWRITE(*LpFourByteRegAddress, LulProtectedRegValue,
                      *LpPPCMDRegAdd, *LpPPROTSRegAdd, LucLoopCount)
    /* QAC Warning: END Msg(2:2814)-3 */

    /* Exit critical section */
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*Check if the loop has exited because of failure of writing to register */
    if (PORT_LONG_WORD_ONE == *LpPPROTSRegAdd)
    {
      /*Implements PORT037, PORT139, PORT146 */
      /* Report write failure production error */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                              DEM_EVENT_STATUS_FAILED);
      /* Set the Dem error flag */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) */

  /* Get the count of total number of 32Bit PODCE registers */
  LucNoOfRegs = LucNoOfPODCERegs;
  while ((PORT_ZERO < LucNoOfRegs) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    /*Implements EAAR_PN0034_FSR_0011, EAAR_PN0034_FSR_0012 */
    /*Implements EAAR_PN0034_FSR_0013 */
    /*Implements PORT_ESDD_UD_068*/
    LucLoopCount = PORT_LOOP_TIMEOUT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Get the register address by adding the offset with the Base address */
    LpFourByteRegAddress =
       (volatile uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* MISRA Violation: END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* MISRA Violation: START Msg(4:2984)-8 */
    /* MISRA Violation: START Msg(4:3393)-10 */

    /*Implements PORT_ESDD_UD_056*/
    /*Implements PORT_ESDD_UD_058*/
    /*Implements PORT_ESDD_UD_063*/
    /*Implements PORT_ESDD_UD_065*/
    /*Implements AR_PN0062_FR_0025*/
    /* Get the address of the corresponding PPROTS register */
    LpPPROTSRegAdd = (volatile uint32 *)
                     (((uint32)(LpPortReg->usRegAddrOffset) -
                      (((uint32)PORT_NUM_PODCE_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PODCE_REG_ADD_OFFSET & LulJtag)) +
                      LulOsBaseAddress) +
                      ((uint32)PORT_NUM_PPROTS_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PPROTS_REG_ADD_OFFSET & LulJtag));

    /* Get the address of the corresponding PPCMD register */
    /*Implements PORT_ESDD_UD_057*/
    /*Implements PORT_ESDD_UD_058*/
    /*Implements PORT_ESDD_UD_064*/
    /*Implements AR_PN0062_FR_0025*/
    LpPPCMDRegAdd = (volatile uint32 *)
                    (((uint32)(LpPortReg->usRegAddrOffset) -
                     (((uint32)PORT_NUM_PODCE_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PODCE_REG_ADD_OFFSET & LulJtag)) +
                     LulOsBaseAddress) +
                     ((uint32)PORT_NUM_PPCMD_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PPCMD_REG_ADD_OFFSET & LulJtag));
    /* MISRA Violation: END Msg(4:3393)-10 */
    /* MISRA Violation: END Msg(4:2984)-8 */
    /* MISRA Violation: END Msg(4:0303)-2 */

    LulProtectedRegValue = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

    /*Implements PORT_ESDD_UD_005*/
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*Implements PORT_ESDD_UD_051*/
    PORT_PROTECTEDWRITE(*LpFourByteRegAddress, LulProtectedRegValue,
                      *LpPPCMDRegAdd, *LpPPROTSRegAdd, LucLoopCount)

    /* Exit critical section */
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*Check if the loop has exited because of failure of writing to register */
    if (PORT_LONG_WORD_ONE == *LpPPROTSRegAdd)
    {
      /*Implements PORT037, PORT139, PORT146 */
      /* Report write failure production error */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);
      /* Set the Dem error flag */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) */
  if (E_OK == LenReturnValue)
  {
    LenReturnValue = Port_DriveUnivCtrlRegInit(LenGroupType);
  }
  else
  {
      /*Do nothing*/
  }
  return (LenReturnValue);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*Implements AR_PN0062_FR_0050, EAAR_PN0034_FR_0049, AR_PN0062_FR_0006*/
/*Implements AR_PN0062_FR_0021*/
/*******************************************************************************
** Function Name         : Port_DriveUnivCtrlRegInit
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the PDSC,PUCC
**                         registers of numeric and JTag ports.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Port_OpenDrainCtrlRegInit should be called
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : SchM_Enter_Port_PORT_INIT_CONFIG_PROTECTION
**                         SchM_Exit_Port_PORT_INIT_CONFIG_PROTECTION,
**                         Port_OutputLevelInvRegInit, Dem_ReportErrorStatus
**
** Registers Used        : JPPROTS0,JPPCMD0,PDSCn,PUCCn,JPDSC0,JPUCC0,PPCMDn,
**                         PPROTSn.
*******************************************************************************/
/*Implements PORT_ESDD_UD_088*/
/*Implements PORT_ESDD_UD_102*/
#if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
     (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON))

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/*Implements PORT_ESDD_UD_093*/
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_DriveUnivCtrlRegInit
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType)
{
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpFourByteRegAddress;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPDSCReg;
  uint32 LulOsBaseAddress;
  uint32 LulProtectedRegValue;
  uint32 LulNumeric;
  uint32 LulJtag;
  uint8 LucNoOfRegs;
  uint8 LucNoOfPDSCRegs;
  uint8 LucNoOfPUCCRegs;
  uint8 LucLoopCount;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPROTSRegAdd;
  Std_ReturnType LenReturnValue;
  LenReturnValue = E_OK;

  /*Initialize with Zero*/
  LulNumeric = PORT_LONG_WORD_ZERO;
  LulJtag = PORT_LONG_WORD_ZERO;

  /*Implements PORT_ESDD_UD_088*/
  /*Implements PORT_ESDD_UD_102*/
  /*Implements AR_PN0062_FR_0023*/
  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
         (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) )
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /* Get the pointer to the Numeric Port registers */
    /* QAC Warning: START Msg(2:2814)-3 */
    LpPortReg = Port_GpConfigPtr->pPortNumRegs;
    /* QAC Warning: END Msg(2:2814)-3 */

    /* Get the Base address of Numeric Port */
    /*Implements PORT_ESDD_UD_017*/
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
    /*Get the total number of Numeric PDSC registers */
    /*Implements PORT_ESDD_UD_043*/
    LucNoOfPDSCRegs = PORT_NUM_PDSC_REGS;
    /*Get the total number of Numeric PUCC registers */
    /*Implements PORT_ESDD_UD_044*/
    LucNoOfPUCCRegs = PORT_NUM_PUCC_REGS;

    /* Get the pointer to the Numeric PDSC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /* QAC Warning: START Msg(2:2824)-2 */
    /*Implements PORT_ESDD_UD_037*/
    /*Implements PORT_ESDD_UD_040*/
    /*Implements PORT_ESDD_UD_041*/
    /*Implements PORT_ESDD_UD_115*/
    /*Implements PORT_ESDD_UD_128*/
    /*Implements PORT_ESDD_UD_129*/
    /*Implements PORT_ESDD_UD_130*/
    /*Implements PORT_ESDD_UD_131*/
    LpPortPDSCReg = LpPortReg + (PORT_NUM_PSR_REGS + PORT_NUM_PISA_REGS
                  + PORT_NUM_PIBC_REGS + PORT_NUM_PIPC_REGS
                  + PORT_NUM_PU_REGS + PORT_NUM_PD_REGS
                  + PORT_NUM_PBDC_REGS + PORT_NUM_PODC_REGS
                  + PORT_NUM_PODCE_REGS);
    /* MISRA Violation: END Msg(4:0488)-6 */
    /* QAC Warning: END Msg(2:3892)-4 */
    /* QAC Warning: END Msg(2:2824)-2 */

    /*Assign LONG_WORD to local variable*/
    LulNumeric = PORT_SET_LONG_WORD;
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  {
    /* Get the pointer to the JTag Port registers */
    LpPortReg = Port_GpConfigPtr->pPortJRegs;
    /* Get the Base address of JTag Port */
    /*Implements PORT_ESDD_UD_019*/
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
    /* Get the total number of JTag PDSC registers */
    /*Implements PORT_ESDD_UD_033*/
    LucNoOfPDSCRegs = PORT_JTAG_PDSC_REGS;
    /* Get the total number of JTag PUCC registers */
    /*Implements PORT_ESDD_UD_034*/
    LucNoOfPUCCRegs = PORT_JTAG_PUCC_REGS;

    /* Get the pointer to the JTAG PDSC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /*Implements PORT_ESDD_UD_029*/
    /*Implements PORT_ESDD_UD_032*/
    /*Implements PORT_ESDD_UD_035*/
    /*Implements PORT_ESDD_UD_116*/
    /*Implements PORT_ESDD_UD_117*/
    /*Implements PORT_ESDD_UD_118*/
    /*Implements PORT_ESDD_UD_119*/
    /*Implements PORT_ESDD_UD_123*/
    LpPortPDSCReg = LpPortReg + (PORT_JTAG_PSR_REGS + PORT_JTAG_PISA_REGS
                + PORT_JTAG_PIBC_REGS + PORT_JTAG_PU_REGS + PORT_JTAG_PD_REGS
                + PORT_JTAG_PBDC_REGS + PORT_JTAG_PODC_REGS
                + PORT_JTAG_PODCE_REGS);
    /* MISRA Violation: END Msg(4:0488)-6 */
    /* QAC Warning: END Msg(2:3892)-4 */

    /*Assign LONG_WORD to local variable*/
    LulJtag = PORT_SET_LONG_WORD;
  } /* End of LenGroupType == PORT_GROUP_JTAG */
  #endif /*   #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) || \
       (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON) ) */
  /* Get the pointer of PDSC register top */
  LpPortReg = LpPortPDSCReg;
  /* Get the count of total number of 32Bit PDSC registers */
  LucNoOfRegs = LucNoOfPDSCRegs;
  while ((PORT_ZERO < LucNoOfRegs) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    /*Implements EAAR_PN0034_FSR_0011, EAAR_PN0034_FSR_0012 */
    /*Implements EAAR_PN0034_FSR_0013 */
    /*Implements PORT_ESDD_UD_068*/
    LucLoopCount = PORT_LOOP_TIMEOUT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Get the register address by adding the offset with the Base address */
    LpFourByteRegAddress =
         (volatile uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* MISRA Violation: END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:2984)-8 */
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* Get the address of the corresponding PPROTS register */
    /*Implements PORT_ESDD_UD_054*/
    /*Implements PORT_ESDD_UD_056*/
    /*Implements PORT_ESDD_UD_061*/
    /*Implements PORT_ESDD_UD_063*/
    /*Implements AR_PN0062_FR_0025*/
    LpPPROTSRegAdd = (volatile uint32 *)
                     (((uint32)(LpPortReg->usRegAddrOffset) -
                      (((uint32)PORT_NUM_PDSC_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PDSC_REG_ADD_OFFSET & LulJtag)) +
                      LulOsBaseAddress) +
                      ((uint32)PORT_NUM_PPROTS_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PPROTS_REG_ADD_OFFSET & LulJtag));

    /* Get the address of the corresponding PPCMD register */
    /*Implements PORT_ESDD_UD_057*/
    /*Implements PORT_ESDD_UD_061*/
    /*Implements PORT_ESDD_UD_064*/
    /*Implements AR_PN0062_FR_0025*/
    LpPPCMDRegAdd = (volatile uint32 *)
                    (((uint32)(LpPortReg->usRegAddrOffset) -
                     (((uint32)PORT_NUM_PDSC_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PDSC_REG_ADD_OFFSET & LulJtag)) +
                     LulOsBaseAddress) +
                     ((uint32)PORT_NUM_PPCMD_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PPCMD_REG_ADD_OFFSET & LulJtag));
    /* MISRA Violation: END Msg(4:3393)-10 */
    /* MISRA Violation: END Msg(4:0303)-2 */
    /* MISRA Violation: END Msg(4:2984)-8 */

    LulProtectedRegValue = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

    /*Implements PORT_ESDD_UD_005*/
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*Implements PORT_ESDD_UD_051*/
    /*QAC Warning: START Msg(2:2814)-3 */
    PORT_PROTECTEDWRITE(*LpFourByteRegAddress, LulProtectedRegValue,
                      *LpPPCMDRegAdd, *LpPPROTSRegAdd, LucLoopCount)
    /*QAC Warning: END Msg(2:2814)-3 */

    /* Exit critical section */
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* Check if the loop has exited because of failure of writing to register */
    if (PORT_LONG_WORD_ONE == *LpPPROTSRegAdd)
    {
      /*Implements PORT037, PORT139, PORT146 */
      /* Report write failure production error */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                              DEM_EVENT_STATUS_FAILED);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) && (LenReturnValue == E_NOT_OK) */

  /* Get the count of total number of 32Bit PUCC registers */
  LucNoOfRegs = LucNoOfPUCCRegs;
  while ((PORT_ZERO < LucNoOfRegs) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    /*Implements EAAR_PN0034_FSR_0011, EAAR_PN0034_FSR_0012 */
    /*Implements EAAR_PN0034_FSR_0013 */
    /*Implements PORT_ESDD_UD_068*/
    LucLoopCount = PORT_LOOP_TIMEOUT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Get the register address by adding the offset with the Base address */
    LpFourByteRegAddress =
          (volatile uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* MISRA Violation: END Msg(4:0303)-2 */

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:2984)-8 */
    /* Get the address of the corresponding PPROTS register */
    /*Implements PORT_ESDD_UD_055*/
    /*Implements PORT_ESDD_UD_056*/
    /*Implements PORT_ESDD_UD_062*/
    /*Implements PORT_ESDD_UD_063*/
    /*Implements AR_PN0062_FR_0025*/
    LpPPROTSRegAdd = (volatile uint32 *)
                     (((uint32)(LpPortReg->usRegAddrOffset) -
                      (((uint32)PORT_NUM_PUCC_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PUCC_REG_ADD_OFFSET & LulJtag)) +
                      LulOsBaseAddress) +
                      ((uint32)PORT_NUM_PPROTS_REG_ADD_OFFSET & LulNumeric) +
                      ((uint32)PORT_JTAG_PPROTS_REG_ADD_OFFSET & LulJtag));

    /*Implements PORT_ESDD_UD_057*/
    /*Implements PORT_ESDD_UD_062*/
    /*Implements PORT_ESDD_UD_064*/
    /*Implements AR_PN0062_FR_0025*/
    /* Get the address of the corresponding PPCMD register */
    LpPPCMDRegAdd = (volatile uint32 *)
                    (((uint32)(LpPortReg->usRegAddrOffset) -
                     (((uint32)PORT_NUM_PUCC_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PUCC_REG_ADD_OFFSET & LulJtag)) +
                     LulOsBaseAddress) +
                     ((uint32)PORT_NUM_PPCMD_REG_ADD_OFFSET & LulNumeric) +
                     ((uint32)PORT_JTAG_PPCMD_REG_ADD_OFFSET & LulJtag));
    /* MISRA Violation: END Msg(4:2984)-8 */
    /* MISRA Violation: END Msg(4:3393)-10 */
    /* MISRA Violation: END Msg(4:0303)-2 */

    LulProtectedRegValue = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

    /*Implements PORT_ESDD_UD_005*/
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*Implements PORT_ESDD_UD_051*/
    PORT_PROTECTEDWRITE(*LpFourByteRegAddress, LulProtectedRegValue,
                      *LpPPCMDRegAdd, *LpPPROTSRegAdd, LucLoopCount)

    /* Exit critical section */
    /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
    /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* Check if the loop has exited because of failure of writing to register */
    if (PORT_LONG_WORD_ONE == *LpPPROTSRegAdd)
    {
      /*Implements PORT037, PORT139, PORT146 */
      /* Report write failure production error */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);

      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* MISRA Violation: END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) && (LenReturnValue == E_NOT_OK) */

  /*Implements PORT_ESDD_UD_102*/
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if (E_OK == LenReturnValue )
  {
    LenReturnValue = Port_OutputLevelInvRegInit(LenGroupType);
  }
  else
  {
      /*Do nothing*/
  }
  #endif
  return (LenReturnValue);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*Implements AR_PN0062_FR_0048, EAAR_PN0034_FR_0081, EAAR_PN0034_FR_0049*/
/*Implements AR_PN0062_FR_0006, AR_PN0062_FR_0023,*/
/*******************************************************************************
** Function Name         : Port_OutputLevelInvRegInit
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize the PINV registers
**                         of numeric ports.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType
**
** Preconditions         : Port_DriveUnivCtrlRegInit should be called
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : SchM_Enter_Port_PORT_INIT_CONFIG_PROTECTION
**                         SchM_Exit_Port_PORT_INIT_CONFIG_PROTECTION,
**                         Dem_ReportErrorStatus
**
** Registers Used        : PINVn,PPCMDn,PPROTSn
*******************************************************************************/
/*Implements PORT_ESDD_UD_102*/
#if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/*Implements PORT_ESDD_UD_094*/
STATIC FUNC(Std_ReturnType, PORT_PRIVATE_CODE) Port_OutputLevelInvRegInit
 (CONST(Port_GroupType,AUTOMATIC) LenGroupType)
{
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpFourByteRegAddress;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortINVReg;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPROTSRegAdd;
  uint32 LulProtectedRegValue;
  uint8 LucNoOfPINVRegs;
  uint8 LucLoopCount;
  Std_ReturnType LenReturnValue = E_OK;
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /*Get the total number of Numeric PINV registers */
    /*Implements PORT_ESDD_UD_042*/
    LucNoOfPINVRegs = PORT_NUM_PINV_REGS;

    /* Get the pointer to the Numeric PINV registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* QAC Warning: START Msg(2:3892)-4 */
    /* QAC Warning: START Msg(2:2814)-3 */
    /*Implements PORT_ESDD_UD_037*/
    /*Implements PORT_ESDD_UD_040*/
    /*Implements PORT_ESDD_UD_041*/
    /*Implements PORT_ESDD_UD_043*/
    /*Implements PORT_ESDD_UD_044*/
    /*Implements PORT_ESDD_UD_115*/
    /*Implements PORT_ESDD_UD_128*/
    /*Implements PORT_ESDD_UD_129*/
    /*Implements PORT_ESDD_UD_130*/
    /*Implements PORT_ESDD_UD_131*/
    LpPortINVReg = Port_GpConfigPtr->pPortNumRegs + (PORT_NUM_PSR_REGS
                  + PORT_NUM_PISA_REGS
                  + PORT_NUM_PIBC_REGS + PORT_NUM_PIPC_REGS
                  + PORT_NUM_PU_REGS + PORT_NUM_PD_REGS
                  + PORT_NUM_PBDC_REGS + PORT_NUM_PODC_REGS
                  + PORT_NUM_PODCE_REGS + PORT_NUM_PDSC_REGS
                  + PORT_NUM_PUCC_REGS);
    /* MISRA Violation: END Msg(4:0488)-6 */
    /* QAC Warning: END Msg(2:3892)-4 */
    /* QAC Warning: END Msg(2:2814)-3 */

    /* AUTOSAR IMPL R4.0.3 PORT082 RULE VIOLATION: As per
    * requirement AR_PN0062_FR_0048 Level inversion is implemented to invert
    * the output level of a pin when the pin is in output mode  */
    while ((PORT_ZERO < LucNoOfPINVRegs) && (E_OK == LenReturnValue))
    {
      /* Initialize the loop count to ten */
      /*Implements EAAR_PN0034_FSR_0011, EAAR_PN0034_FSR_0012 */
      /*Implements EAAR_PN0034_FSR_0013 */
      /*Implements PORT_ESDD_UD_068*/
      LucLoopCount = PORT_LOOP_TIMEOUT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* QAC Warning: START Msg(2:2814)-3 */
      /* Get the register address by adding the offset with the Base address */
      LpFourByteRegAddress =
      (volatile uint32 *)(LpPortINVReg->usRegAddrOffset +
                          PORT_USER_BASE_ADDRESS_NUMERIC);
      /* QAC Warning: END Msg(2:2814)-3 */
      /* MISRA Violation: END Msg(4:0303)-2 */


      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:3393)-10 */
      /* Get the address of the corresponding PPROTS register */

      /*Implements PORT_ESDD_UD_017*/
      /*Implements PORT_ESDD_UD_056*/
      /*Implements PORT_ESDD_UD_059*/
      /*Implements PORT_ESDD_UD_067*/
      /*Implements AR_PN0062_FR_0025*/
      LpPPROTSRegAdd = (volatile uint32 *)
                       ((uint32)(LpPortINVReg->usRegAddrOffset) -
                        (uint32)(PORT_NUM_PINV_REG_ADD_OFFSET +
                        PORT_OS_BASE_ADDRESS_OFFSET)+
                        PORT_OS_BASE_ADDRESS_NUMERIC +
                        (uint32)(PORT_NUM_PPROTS_REG_ADD_OFFSET));

      /* MISRA Violation: END Msg(4:3393)-10 */
      /* MISRA Violation: END Msg(4:0303)-2 */

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* MISRA Violation: START Msg(4:3393)-10 */
      /* Get the address of the corresponding PPCMD register */

      /*Implements PORT_ESDD_UD_017*/
      /*Implements PORT_ESDD_UD_057*/
      /*Implements PORT_ESDD_UD_059*/
      /*Implements PORT_ESDD_UD_067*/
      /*Implements AR_PN0062_FR_0025*/
      /*Implements AR_PN0062_FR_0025*/
      LpPPCMDRegAdd = (volatile uint32 *)
                      ((uint32)(LpPortINVReg->usRegAddrOffset) -
                       (uint32)(PORT_NUM_PINV_REG_ADD_OFFSET +
                       PORT_OS_BASE_ADDRESS_OFFSET) +
                       PORT_OS_BASE_ADDRESS_NUMERIC +
                       (uint32)(PORT_NUM_PPCMD_REG_ADD_OFFSET));

      /* MISRA Violation: END Msg(4:3393)-10 */
      /* MISRA Violation: END Msg(4:0303)-2 */
      LulProtectedRegValue = LpPortINVReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /*Implements PORT_ESDD_UD_005*/
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_ENTER_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*Implements PORT_ESDD_UD_051*/
      /*QAC Warning: START Msg(2:2814)-3 */
      PORT_PROTECTEDWRITE(*LpFourByteRegAddress, LulProtectedRegValue,
                        *LpPPCMDRegAdd, *LpPPROTSRegAdd, LucLoopCount)
      /*QAC Warning: END Msg(2:2814)-3 */

      /* Exit critical section */
      /*Implements EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0030*/
      /*Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0066*/
      #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
      PORT_EXIT_CRITICAL_SECTION(PORT_INIT_CONFIG_PROTECTION);
      #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /*Check if the loop has exited because of failure of writing to register*/
      if (PORT_LONG_WORD_ONE == *LpPPROTSRegAdd)
      {
        /*Implements PORT037, PORT139, PORT146 */
        /* Report write failure production error */
        Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                                   DEM_EVENT_STATUS_FAILED);
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortINVReg++;
      /* MISRA Violation: END Msg(4:0489)-7 */
      LucNoOfPINVRegs--;
    } /* End of (LucNoOfRegs > PORT_ZERO) && (LenReturnValue == E_NOT_OK) */
  }
  else
  {
      /*Do nothing*/
  }
  return (LenReturnValue);
}
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*Implements PORT103, PORT143, PORT133_Conf, EAAR_PN0034_FR_0051*/
/*Implements EAAR_PN0034_FR_0049*/
/*Implements PORT_ESDD_UD_085*/
#if (PORT_VERSION_INFO_API == STD_ON)
/*******************************************************************************
** Function Name             : Port_GetVersionInfo
**
** Service ID                : 0x03
**
** Description               : This API will store the version information of
**                             this module in the pointer versioninfo.
**
** Sync/Async                : Synchronous
**
** Reentrancy                : Non Reentrant
**
** Input Parameters          : None
**
** InOut Parameters          : None
**
** Output Parameters         : VersioninfoPtr - Pointer to where to store the
**                             version information of this module.
**
** Return parameter          : None
**
** Preconditions             : None
**
** Global Variables Used     : None
**
** Function(s) invoked       : Det_ReportError
**
** Registers Used            : None
*******************************************************************************/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*Implements PORT_ESDD_UD_090*/
/* QAC Warning : START Msg(2:3227)-5 */
FUNC(void, PORT_PUBLIC_CODE) Port_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA)versioninfo)
/* QAC Warning : END Msg(2:3227)-5 */
{
  /*Implements PORT_ESDD_UD_106*/
  /*Implements PORT100, PORT107, PORT211, PORT123_Conf*/
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /*Implements PORT225*/
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                          PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
  }
  else
  #endif /* End of #if (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /*Implements PORT102*/
    /* Copy the vendor Id */
    /* QAC Warning: START Msg(2:2814)-3 */
    versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
    /* QAC Warning: END Msg(2:2814)-3 */
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
  }
}/* End of API Port_GetVersionInfo */
#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* End of #if (PORT_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
