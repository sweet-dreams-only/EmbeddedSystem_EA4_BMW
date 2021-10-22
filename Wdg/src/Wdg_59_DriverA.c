/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA.c                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Driver code of the Watchdog Driver A Component                             */
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
 * V1.0.0:  28-Aug-2012    : Initial Version
 *
 * V1.0.1:  29-Sep-2012    : As per SCR 020, all condition checks are modified.
 *
 * V1.0.2:  23-Jan-2013    : As per SCR 068, software version macros are
 *                           hard coded.
 *
 * V1.0.3:  07-Mar-2013    : As per SCR 109 for mantis issue 9625, following
 *                           change is made:
 *                           Mode register 'WDG_59_DRIVERA_WDTAMD_ADDRESS' is
 *                           updated for not disturbing 75% interrupt bit in
 *                           the API's Wdg_59_DriverA_Init and
 *                           Wdg_59_DriverA_SetMode.
 *
 * V1.0.4:  24-Apr-2013    : As per SCR 148 for mantis issue #9729, following
 *                           change is made:
 *                           Mode register 'WDG_59_DRIVERA_WDTAMD_ADDRESS' is
 *                           updated for not disturbing 75% interrupt bit,
 *                           NMI and Reset mode in the API's Wdg_59_DriverA_Init
 *                           and Wdg_59_DriverA_SetMode.
 *
 * V1.0.5:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.6:  27-Aug-2013    : As per CR 232 for mantis issue 12123, backslash
 *                           removed for ANSI C code.
 *
 * V1.0.7:  14-Oct-2013    : As per CR 263, WDG_59_DRIVERA_ENB_INTVECTAB_MODE
 *                           macro added in Wdg_59_DriverA_Init API for 75%
 *                           interrupt.
 *
 * V1.0.8:  05-Mar-2014    : As per CR 422 for mantis issue 18651, following
 *                           change is made:
 *                           1. critical section is added in
 *                           Wdg_59_DriverA_Init, Wdg_59_DriverA_SetMode and
 *                           Wdg_59_DriverA_SetTriggerCondition API's.
 *                           2. WDG_59_DRIVERA_ENB_INTVECTAB_MODE macro removed
 *                           in Wdg_59_DriverA_Init API.
 *
 * V1.0.9:  24-Apr-2014    : As per CR 490 for mantis #21269, #17424 and 20814
 *                           following changes are made:
 *                           1. Updated the write operation of supervisor
 *                           mode(SV)write enabled Register IMR and
 *                           rh850_Types.h is included.
 *                           2. Register read-back is implemented in API's
 *                           "Wdg_59_DriverA_Init" and "Wdg_59_DriverA_SetMode".
 *                           3. Redundant macro WDG_59_DRIVERA_ENB_NMI_INT is
 *                           removed from Wdg_59_DriverA_Init API.
 *                           4. The mode check (Mode > WDGIF_FAST_MODE) is
 *                           replaced with (Mode > WDGIF_FAST_MODE ||
 *                           (Mode < WDGIF_OFF_MODE) in Wdg_59_DriverA_SetMode
 *                            API.
 *                           5. MISRA violation comments have been updated for
 *                              MISRA Msg "(7:0872)-5".
 *
 * V1.0.10:  16-Jun-2014   : As per CR 520, following changes are made:
 *                           1. Wdg_59_DriverA_RegReadBack.h is added in include
 *                              section.
 *                           2. WDG_59_DRIVERA_READBACKTEST_IMR macro is added
 *                              in initialization API.
 *
 * V1.0.11:  10-Sep-2014   : As per CR 560 for mantis #22421, following changes
 *                           are made:
 *                           1. Renesas C coding guidelines for Equivalence
 *                           Test is taken care in comparing the variable with
 *                           constant, constant should be left hand side in all
 *                           API.
 *                           2. In Wdg_59_DriverA_SetMode API critical section
 *                           is added.
 *                           3. Macro WDG_59_DRIVERA_DEM_TYPE added in
 *                           Wdg_59_DriverA_SetMode for the removal of MISRA
 *                           violation with V8.1.1.
 *                           4. Redundant MISRA C rule violations message are
 *                           removed.
 *                           5. MISRA message number "(4:0303)-1" is updated as
 *                           per QAC 8.1.1.
 *                           6. MISRA message number "(4:4397)-2" is updated as
 *                           per QAC 8.1.1.
 *
 * V1.0.12:  03-Feb-2015   : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 * V1.0.13:  18-Feb-2016   : As part of P1x V4.01.00 release,the following
 *                           changes are made,
 *                           1.As part of JIRA ticket ARDAAAE-1315,
 *                             Wdg_59_DriverA_SetMode function is updated to
 *                             check if DEM error occurs only if required mode
 *                             is 'WDGIF_OFF_MODE' and 'WdgDisableAllowed' is
 *                             true.
 *                           2.As part of JIRA ticket ARDAAAE-1512,
 *                             Wdg_59_DriverA_Init function is updated to add
 *                             DET checks when the WDG Init is called with
 *                             invalid hardware specific parameters in the
 *                             config set.
 *                           3.Copyright information is updated.
 *                           4.MISRA violation START and END msgs for
 *                             Msg(2:2814),Msg(2:2995),Msg(2:3416),Msg(2:3227),
 *                             Msg(2:0862) are added at the respective places.
 *
 * V1.0.14:  18-Oct-2016   : Following changes are made:
 *                           1.As per ARDAAAE-1838,
 *                           new Header file "Wdg_59_DriverA_RegWrite.h" is
 *                           included to support Write verify functionality
 *                           2.New macros WDG_59_DRIVERA_REG_WRITE ,
 *                           WDG_59_DRIVERA_REG_WRITE_VERIFY_INIT and
 *                           WDG_59_DRIVERA_REG_WRITE_VERIFY_RUNTIME are added.
 *                           3.As per ARDAAAE-811,
 *                           Wdg_59_DriverA_GetVersionInfo API is added
 *                           4.As per ARDAAAE-1752, Wdg_59_DriverA_SetMode
 *                           API is updated to add pre compile check to enable
 *                           or disable E_MODE_FAILED and E_DISABLE_REJECTED
 *                           DEM reporting.
 *                           5.As per ARDAAAE-1877, Wdg_59_DriverA_SetMode,
 *                           Wdg_59_DriverA_SetTriggerCondition and
 *                           Wdg_59_DriverA_Init APIs  are updated to remove
 *                           implementation of 'WDG_59_DRIVERA_DISABLE_ALLOWED'
 *                           macro.
 *                           6.As per ARDAAAE-1910,
 *                           Wdg_59_DriverA_GetVersionInfo and
 *                           Wdg_59_DriverA_Init APIs are updated to add
 *                           proper justifications for pointer usage.
 *                           7.As per ARDAAAE-1908,Wdg_59_DriverA_Trigger
 *                           API is removed as it is applicable in Autosar
 *                           lower version only, dead code removed
 *                           8.As per ARDAAAE-1819,Wdg_59_DriverA_SetMode and
 *                           Wdg_59_DriverA_SetTriggerCondition APIs are updated
 *                           where usFastTimeValue and usSlowTimeValue are used
 *                           to calculate Trigger counter and the check if these
 *                           time values will be ZERO is removed.
 *                           9.As per ARDAAAE-1942,Wdg_59_DriverA_Init API
 *                           is updated to add DET reporting for
 *                           WDG_E_PARAM_POINTER.
 *                           10. As per ARDAAAE-1936,'WDG_ESDD_UD_XXX' and
 *                            Req ID Tags are added.
 *                           11.As per ARDAAAE-2090,Wdg_59_DriverA_SetMode
 *                            API is updated for updating
 *                            Wdg_59_DriverA_GusTiggerCounter value.
 *                           12.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 * V1.0.15:  15-Feb-2017  : Following changes are made:
 *                         1. As part of JIRA ID ARDAAAE-2121,Tag Message
 *                            Msg(2:3416) in Wdg_59_DriverA_SetTriggerCondition
 *                            is added.
 *                         2. Copyright information is updated.
 *                         3. As part of JIRA ID ARDAAAE-2355
 *                            Followed naming conventions are changed,
 *                            usInitTimerCountValue to ulInitTimerCountValue
 *                            usSlowTimeValue to ulSlowTimeValue
 *                            usFastTimeValue to ulFastTimeValue
 *                            Wdg_59_DriverA_GusTiggerCounter to
 *                            Wdg_59_DriverA_GulTiggerCounter
 *                         4. As part of JIRA ID ARDAAAE-2189
 *                            Wdg_59_DriverA_SetMode is updated to intialize the
 *                            return value when requested mode and current mode
 *                            are same.
 *                         5. As part of JIRA ID ARDAAAE-2355 redundant
 *                            assignment is deleted. The value of this
 *                            object is never used before being modified.
 *                            To avoid QAC warning Msg(4:2982).
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R4, WDG061] */
/* TRACE [R3, WDG061] */
/* TRACE [R4, WDG169] */
/* TRACE [R4, WDG161] */
/* Implements WDG061,WDG170,WDG045,WDG064,WDG065,WDG066,WDG105 */
/* Implements AR_PN0064_FR_0004,AR_PN0064_NR_0001,AR_PN0064_NR_0004 */
/* Implements AR_PN0064_NR_0008,AR_PN0064_NR_0009,AR_PN0064_FR_0041 */
/* Implements EAAR_PN0034_NR_0001,EAAR_PN0034_FR_0081,EAAR_PN0034_FR_0013 */
/* Implements EAAR_PN0034_FR_0030,EAAR_PN0034_FR_0019,EAAR_PN0034_FR_0021 */
/* Implements EAAR_PN0034_FR_0023,EAAR_PN0034_NR_0045,EAAR_PN0034_NR_0069 */
/* Implements  EAAR_PN0034_NR_0026,EAAR_PN0034_NR_0001 */
/* Implements EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */

/* Included for Wdg_59_DriverA.h inclusion and macro definitions */
#include "Wdg_59_DriverA_PBTypes.h"

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* Implements WDG111 */
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
/* TRACE [R4, WDG080] */
/* TRACE [R3, WDG080] */
/* TRACE [R4, WDG062] */
/* TRACE [R3, WDG062] */
/* TRACE [R4, WDG110] */
/* TRACE [R3, WDG110] */
/* Implements WDG080,WDG040,WDG062,WDG063,WDG110 */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for RAM variable declarations */
#include "Wdg_59_DriverA_Ram.h"
/* Included for declaration of the function Wdg_59_DriverA_TriggerFunc() */
#include "Wdg_59_DriverA_Private.h"
/* Included for declaration of the SV enabled registers write operation */
#include "rh850_Types.h"
#include "Wdg_59_DriverA_RegWrite.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_C_AR_RELEASE_MAJOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_RELEASE_MINOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_RELEASE_REVISION_VERSION \
                                WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define WDG_59_DRIVERA_C_SW_MAJOR_VERSION  1
#define WDG_59_DRIVERA_C_SW_MINOR_VERSION  0
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION != \
                                      WDG_59_DRIVERA_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION != \
                                      WDG_59_DRIVERA_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION != \
                                   WDG_59_DRIVERA_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Revision Version"
#endif

#if (WDG_59_DRIVERA_SW_MAJOR_VERSION != WDG_59_DRIVERA_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_SW_MINOR_VERSION != WDG_59_DRIVERA_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) [I] Cast between a pointer to volatile object and */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex bitwise*/
/*                 operations.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-2 and                           */
/*                 END Msg(4:4397)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 13.7                                          */
/* Justification : The result of this logical operation is always is true     */
/*                 because of the variable updated in pre-compile condition.  */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(4:2995)-3 and                           */
/*                 END Msg(4:2995)-3 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                                QAC WARNING                                 **
*******************************************************************************/
/* 1. QAC WARNING:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated by Post Build configurations shall  */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:2814)-1 and              */
/*                 END Msg(2:2814)-1 tags in the code.                        */

/******************************************************************************/

/* 2. QAC WARNING:                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR APIs cannot be modified */
/*                 to be made as constant.                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:3227)-2 and              */
/*                 END Msg(2:3227)-2 tags in the code.                        */

/******************************************************************************/

/* 3. QAC WARNING:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Rule          : NA                                                         */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access. All register addresses are generated with */
/*                 volatile qualifier. There is no impact on the functionality*/
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:3416)-3 and              */
/*                 END Msg(2:3416)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       :(2:0862) This #include "%s" directive is redundant.         */
/* Rule          : NA                                                         */
/* Justification : All the #include "%s" files contains C function            */
/*                 declarations or macro definitions to be shared between     */
/*                 several source files. This violation is an approved        */
/*                 exception without side effects.                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */

/******************************************************************************/

/* 5. QAC WARNING:                                                            */
/* Message       :(2:2834)   Possible: Division by zero                       */
/* Rule          : NA                                                         */
/* Justification : As per ARDAAAE-1819,the generated values of ulSlowTimeValue*/
/*                 and ulFastTimeValue shall never be zero                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:2834)-5 and              */
/*                 END Msg(2:2834)-5 tags in the code.                        */

/******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* Implements EAAR_PN0034_NR_0002 */
/*******************************************************************************
** Function Name         : Wdg_59_DriverA_Init
**
** Service ID            : 0x00
**
** Description           : This service initialize the Watchdog hardware.
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
** Global Variables Used : Wdg_59_DriverA_GpConfigPtr,
**                         Wdg_59_DriverA_GulTiggerCounter,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GddDriverState,
**
** Functions Invoked     : Det_ReportError,
**                         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION,
**                         Wdg_59_DriverA_TriggerFunc,
**                         Wdg_59_DriverA_InitDetCheck
**
** Registers Used        : IMRn, WDTAnMD,WDTAnEVAC,WDTAnWDTE,WDTAnREF
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, WDG106] */
/* TRACE [R3, WDG106] */
/*
 * The pointer ConfigPtr is used as per the AUTOSAR requirement WDG106.
 * The Null check for the ConfigPtr has been done as part of
 * the DET check. In addition to that a data base check also carried out in the
 * code to make sure the validity of the ConfigPtr
 */
/* QAC warning: START Msg(2:3227)-2 */
/* Implements WDG_ESDD_UD_013 */
/* Implements WDG_ESDD_UD_022 */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG_ESDD_UD_001 */
/* Implements WDG161,WDG172,WDG106,WDG001,WDG100,WDG101,WDG089,WDG090,WDG019 */
/* Implements WDG051,WDG115_Conf,WDG130_Conf,WDG120_Conf */
/* Implements AR_PN0064_FR_0001,AR_PN0064_FR_0008,AR_PN0064_FR_0029 */
/* Implements AR_PN0064_FR_0010,EAAR_PN0034_FR_0067,EAAR_PN0034_FR_0049 */
/* Implements EAAR_PN0034_NR_0020,EAAR_PN0034_FR_0025,EAAR_PN0034_FSR_0001 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0064 */
FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_Init
(P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
  ConfigPtr)
{
  /* END Msg(2:3227)-2 */
  /* TRACE [R4, WDG065] */
  /* TRACE [R3, WDG065] */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R4, WDG089] */
  /* TRACE [R3, WDG089] */

  /* Implements WDG_ESDD_UD_009 */
  /* Check for NULL Pointer*/
  if (NULL_PTR == ConfigPtr)
  {

    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
             WDG_59_DRIVERA_INIT_SID, WDG_59_DRIVERA_E_PARAM_POINTER);
  }

  /* Implements WDG_ESDD_UD_009 */
  /* Implements WDG_ESDD_UD_023 */
  /* QAC warning: START Msg(2:3416)-3 */
  else if (E_NOT_OK == Wdg_59_DriverA_InitDetCheck(ConfigPtr))

  {
    /* END Msg(2:3416)-3 */
    /* TRACE [R4, WDG111] */
    /* TRACE [R3, WDG111] */
    /* Report Error to DET */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
               WDG_59_DRIVERA_INIT_SID, WDG_59_DRIVERA_E_PARAM_CONFIG);
  }
  else
  #endif /* (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether the existing database is correct */
    /* MISRA Violation: START Msg(4:4397)-2 */
    /* QAC warning: START Msg(2:2814)-1 */
    if ((uint32)(WDG_59_DRIVERA_DBTOC_VALUE) == (ConfigPtr->ulStartOfDbToc))
    /* END Msg(2:2814)-1 */
    /* END Msg(4:4397)-2 */
    {
      /*
       * The ConfigPtr shall hold the address of the  Structure for Watchdog
       * Driver Init configuration. The same is  assigned to the global pointer
       * Wdg_59_DriverA_GpConfigPtr which is declared as pointer to constant
       * and hence its values shall not be further modified by other API's
       */
      /* Assign the config pointer value to global pointer */
      Wdg_59_DriverA_GpConfigPtr = ConfigPtr;

      /* TRACE [R4, WDG040] */
      /* TRACE [R3, WDG040] */

      /* Check if critical section protection is required */
      #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
      WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
      #endif

      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Implements WDG_ESDD_UD_008 */
      /* Implements WDG_ESDD_UD_007 */
      /* Implements WDG_ESDD_UD_020 */
      /* Implements WDG_ESDD_UD_021 */
      /* Enable the 75 percent interrupt output */
      RH850_SV_MODE_IMR_AND(32, WDG_59_DRIVERA_INTWDTIMR_ADDR,
                                                 WDG_59_DRIVERA_INTWDTIMR_MASK);
      /* END Msg(4:0303)-1 */
      /* Check if critical section protection is required */
      /* TRACE [R4, WDG040] */
      /* TRACE [R3, WDG040] */
      /* Implements EAAR_PN0034_FR_0061 */
      #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
      WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
      #endif

      /* To check whether the default mode is not OFF mode */
      /* QAC warning: START Msg(2:2814)-1 */
      if (WDGIF_OFF_MODE != Wdg_59_DriverA_GpConfigPtr->ddWdtamdDefaultMode)
      /* END Msg(2:2814)-1 */
      {
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* MISRA Violation: START Msg(4:0303)-1 */
        /* TRACE [R4, WDG001] */
        /* TRACE [R3, WDG001] */
        /* TRACE [R4, WDG101] */
        /* TRACE [R3, WDG101] */
        /* Implements WDG_ESDD_UD_008 */
        /* Implements WDG_ESDD_UD_007 */
        /* Implements WDG_ESDD_UD_030 */
        /* Implements WDG_ESDD_UD_017 */
        /* Set Default mode value to Mode register */
        WDG_59_DRIVERA_REG_WRITE(WDG_59_DRIVERA_WDTAMD_ADDRESS,
        (Wdg_59_DriverA_GpConfigPtr->ucWdtamdDefaultValue |
            (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)))

        /* Implements WDG_ESDD_UD_033 */
        /* Implements WDG_ESDD_UD_018 */
        /* Implements WDG_ESDD_UD_027 */
        WDG_59_DRIVERA_REG_WRITE_VERIFY_INIT(WDG_59_DRIVERA_WDTAMD_ADDRESS,
        ((Wdg_59_DriverA_GpConfigPtr->ucWdtamdDefaultValue) |
        (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)),
         (WDG_59_DRIVERA_WDTAMD_MASK), (WDG_59_DRIVERA_INIT_API_ID))


        /* END Msg(4:0303)-1 */
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* Implements WDG_ESDD_UD_026 */
        /* Set the Initial trigger counter value */
        Wdg_59_DriverA_GulTiggerCounter =
                     Wdg_59_DriverA_GpConfigPtr->ulInitTimerCountValue;

        /* Call the Trigger Function which restarts the Watchdog hardware */
        Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_INIT_API_ID);
      }
      else
      {
        /* Default Mode is OFF,No action required */
      }

      /* Set current mode */
      Wdg_59_DriverA_GddCurrentMode =
                              Wdg_59_DriverA_GpConfigPtr->ddWdtamdDefaultMode;

      /* Check if WDG_59_DRIVERA_DEV_ERROR_DETECT is enabled */
      #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
      /* TRACE [R4, WDG019] */
      /* TRACE [R3, WDG019] */
      /* Implements WDG_ESDD_UD_029 */
      /* Set the state of Watchdog as idle */
      Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
      #endif
    } /* end of if (WDG_59_DRIVERA_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))*/
    /* Implements WDG_ESDD_UD_009 */
    /* Implements WDG_ESDD_UD_023 */
    else
    {
      #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
      /* TRACE [R4, WDG090] */
      /* TRACE [R3, WDG090] */
      /* Report Error to DET */
      (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID,
      WDG_59_DRIVERA_INSTANCE_ID, WDG_59_DRIVERA_INIT_SID,
      WDG_59_DRIVERA_E_INVALID_DATABASE);
      #endif
    } /* End of Check to check database */

  }
}

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_SetMode
**
** Service ID            : 0x01
**
** Description           : This service change the mode of the Watchdog timer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : WdgIf_ModeType  Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK or E_NOT_OK
**
** Preconditions         : Wdg_59_DriverA_Init must be called before this
**                         function.
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GulTiggerCounter,
**                         Wdg_59_DriverA_GpConfigPtr.
**
** Functions Invoked     :
**                         Dem_ReportErrorStatus,
**                         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION,
**                         Wdg_59_DriverA_TriggerFunc,
**                         Wdg_59_DriverA_SetModeDetCheck.
**
** Registers Used        : WDTAnMD,WDTAnEVAC,WDTAnWDTE,WDTAnREF
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, WDG107] */
/* TRACE [R3, WDG107] */
/* TRACE [R4, WDG160] */
/* TRACE [R3, WDG102] */
/* Implements WDG031,WDG107,WDG160 */
/* Implements WDG_ESDD_UD_013 */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG_ESDD_UD_026 */
/* Implements WDG_ESDD_UD_002 */
/* Implements WDG172,WDG145,WDG103,WDG016,WDG026,WDG091,WDG092,WDG017,WDG018 */
/* Implements WDG150_Conf,WDG149_Conf,WDG115_Conf,WDG121_Conf,WDG123_Conf  */
/* Implements AR_PN0064_FR_0001,AR_PN0064_FR_0008,AR_PN0064_FR_0029 */
/* Implements AR_PN0064_FR_0010,AR_PN0064_FR_0005,EAAR_PN0034_FR_0049 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
/* Implements EAAR_PN0034_FR_0061 */

/* QAC warning: START Msg(2:3227)-2 */
FUNC(Std_ReturnType,  WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetMode
  (WdgIf_ModeType Mode)
{
  /* END Msg(2:3227)-2 */
  /* TRACE [R4, WDG105] */
  /* TRACE [R3, WDG105] */
  /* Variable to store the return value */
  Std_ReturnType LenReturnValue;
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R4, WDG017] */
  /* TRACE [R3, WDG017] */
  /* Implements WDG_ESDD_UD_009 */
  /* Report Error to DET, if state of Watchdog is not idle */
  LenReturnValue = Wdg_59_DriverA_SetModeDetCheck(Mode);
  /* Check if any DET error was reported */
  if (E_OK == LenReturnValue)
  #endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, WDG018] */
    /* TRACE [R3, WDG018] */
    /* Implements WDG_ESDD_UD_029 */
    /* Set the state of Watchdog as busy */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
    #endif

    /* Check for request mode is OFF */
    if ((WDGIF_OFF_MODE != Wdg_59_DriverA_GddCurrentMode) &&
                                                     (WDGIF_OFF_MODE == Mode))
    {
      /* TRACE [R3, WDG012] */
      /* TRACE [R4, WDG025] */
      /* TRACE [R3, WDG025] */
      /* TRACE [R4, WDG026] */
      /* TRACE [R3, WDG026] */
      /* Implements WDG_ESDD_UD_035 */
      /* Implements WDG_ESDD_UD_027 */
      /* Check whether error reporting is allowed */
      #if (WDG_59_DRIVERA_E_DISABLE_REJECTED_REPORTING == STD_ON)
      /* Report Error to DEM */
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_DISABLE_REJECTED,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
      #endif
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }

    /* Switching the Watchdog Mode from OFF to SLOW or FAST mode */
    else if ((WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode) &&
                                                     (WDGIF_OFF_MODE != Mode))
    {

      /* Switching the Watchdog Mode from OFF to SLOW */
      if (WDGIF_SLOW_MODE == Mode)
      {
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        /* Implements EAAR_PN0034_FR_0061 */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* MISRA Violation: START Msg(4:0303)-1 */
        /* QAC warning: START Msg(2:2814)-1 */
        /* Implements WDG_ESDD_UD_008 */
        /* Implements WDG_ESDD_UD_007 */
        /* Implements WDG_ESDD_UD_022 */
        /* Implements WDG_ESDD_UD_017 */
        /* Set configured slow mode value to Mode register */
        WDG_59_DRIVERA_REG_WRITE(WDG_59_DRIVERA_WDTAMD_ADDRESS,
        (Wdg_59_DriverA_GpConfigPtr->ucWdtamdSlowValue |
        (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)))


        /* Implements WDG_ESDD_UD_018 */
        /* Implements WDG_ESDD_UD_022 */
        /* Implements WDG_ESDD_UD_027 */
        WDG_59_DRIVERA_REG_WRITE_VERIFY_RUNTIME(WDG_59_DRIVERA_WDTAMD_ADDRESS,
        (Wdg_59_DriverA_GpConfigPtr->ucWdtamdSlowValue |
        (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)),
        (WDG_59_DRIVERA_WDTAMD_MASK), (WDG_59_DRIVERA_SETMODE_API_ID))

        /* END Msg(2:2814)-1 */
        /* END Msg(4:0303)-1 */

        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        /* Implements EAAR_PN0034_FR_0061 */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* TRACE [R4, WDG145] */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif

        /* Set the trigger counter value considering the slow mode
         * multiply by thousand as ulSlowTimeValue is in microseconds
         */
        /* QAC warning: START Msg(2:2834)-5 */
        /* Implements WDG_ESDD_UD_008 */
        /* Implements WDG_ESDD_UD_026 */
        Wdg_59_DriverA_GulTiggerCounter =
        (( WDG_59_DRIVERA_INITIAL_TIMEOUT * WDG_59_DRIVERA_THOUSAND ) /
                                   Wdg_59_DriverA_GpConfigPtr->ulSlowTimeValue);

        /* END Msg(2:2834)-5 */

        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif

      }
      /* Switching the Watchdog Mode from OFF to FAST */
      else
      {
        /* Check if critical section protection is required */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* MISRA Violation: START Msg(4:0303)-1 */
        /* Implements WDG_ESDD_UD_008 */
        /* Implements WDG_ESDD_UD_007 */
        /* Implements WDG_ESDD_UD_022 */
        /* Implements WDG_ESDD_UD_017 */
        /* Set configured fast mode value to Mode register */
        WDG_59_DRIVERA_REG_WRITE(WDG_59_DRIVERA_WDTAMD_ADDRESS,
        (Wdg_59_DriverA_GpConfigPtr->ucWdtamdFastValue |
        (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)))


        /* Implements WDG_ESDD_UD_018 */
        /* Implements WDG_ESDD_UD_027 */
        WDG_59_DRIVERA_REG_WRITE_VERIFY_RUNTIME(WDG_59_DRIVERA_WDTAMD_ADDRESS,
        (Wdg_59_DriverA_GpConfigPtr->ucWdtamdFastValue |
        (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)),
        (WDG_59_DRIVERA_WDTAMD_MASK), (WDG_59_DRIVERA_SETMODE_API_ID))

        /* END Msg(4:0303)-1 */
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif

        /* Set the trigger counter value considering the fast mode
         * Multiply by thousand as ulFastTimeValue is in microseconds
         */
        /* QAC warning: START Msg(2:2834)-5 */
        /* Implements WDG_ESDD_UD_008 */
        /* Implements WDG_ESDD_UD_022 */
        /* Implements WDG_ESDD_UD_026 */
        Wdg_59_DriverA_GulTiggerCounter =
        (( WDG_59_DRIVERA_INITIAL_TIMEOUT * WDG_59_DRIVERA_THOUSAND ) /
                                   Wdg_59_DriverA_GpConfigPtr->ulFastTimeValue);
        /* END Msg(2:2834)-5 */

        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif

      }
       /* Check if critical section protection is required */
       #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
       WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
       #endif

      /* Set the current mode */
      Wdg_59_DriverA_GddCurrentMode = Mode;

      /* Check if critical section protection is required */
      #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
      WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
      #endif

      LenReturnValue = E_OK;

      /* Call the Trigger Function which restarts the Watchdog hardware */
      Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_SETMODE_API_ID);
    } /* end of else if (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode) */

    /* MISRA Violation: START Msg(4:2995)-3 */
    /* Requested and current mode are different i.e FAST->SLOW/SLOW->FAST  */
    else if ((Mode != Wdg_59_DriverA_GddCurrentMode))
      /* END Msg(4:2995)-3 */
    {
      /* TRACE [R4, WDG013] */
      /* TRACE [R3, WDG013] */
      /* TRACE [R4, WDG173] */
      /* TRACE [R3, WDG016] */
      /* TRACE [R4, WDG016] */
      /* TRACE [R3, WDG012] */
      /* Implements WDG_ESDD_UD_034 */
      /* Implements WDG_ESDD_UD_028 */
      /* Check whether error reporting is allowed */
      #if (WDG_59_DRIVERA_E_MODE_FAILED_REPORTING == STD_ON)
      /* Report Error to DEM */
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_MODE_FAILED,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
      #endif

      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    /* Requested Mode is the same as Current Mode
     * FAST->FAST
     * SLOW->SLOW
     * OFF->OFF
     */
    else
    {
      LenReturnValue = E_OK;
    }

    /* Implements WDG_ESDD_UD_029 */
    /* Set Watchdog Driver State to IDLE after Mode Switch operation */
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as idle */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
    #endif
    /* (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  } /* End of if (E_OK == LenReturnValue) */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  return(LenReturnValue);
}

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_SetTriggerCondition
**
** Service ID            : 0x03
**
** Description           : This service is used to initialize the trigger
**                         counter.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : timeout
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Wdg_59_DriverA_Init must be called before this
**                         function.
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GulTiggerCounter,
**                         Wdg_59_DriverA_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION.
**
** Registers Used        : None
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, WDG155] */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG_ESDD_UD_026 */
/* Implements WDG_ESDD_UD_003 */
/* Implements WDG172,WDG155,WDG136,WDG138,WDG139,WDG140,WDG146,WDG131_Conf */
/* Implements AR_PN0064_FR_0001,AR_PN0064_FR_0008,AR_PN0064_FR_0032 */
/* Implements AR_PN0064_FR_0036,EAAR_PN0034_FR_0049,EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0064 */

/* QAC warning: START Msg(2:3227)-2 */
FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetTriggerCondition
                                                            (uint16 timeout)
{
  /* END Msg(2:3227)-2 */
  /* Check if DET is enabled */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value */
  Std_ReturnType LenReturnValue;
  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* Implements WDG_ESDD_UD_009 */
  /* Implements WDG_ESDD_UD_023 */
  /* Implements WDG_ESDD_UD_029 */
  /* QAC warning: START Msg(2:3416)-3 */
  /* Check whether Watchdog Driver is initialized */
  if ((WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState) ||
                              (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode))
  {
    /* QAC warning: END Msg(2:3416)-3 */
    /* Report to DET, if Watchdog is not in idle state */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
         WDG_59_DRIVERA_SETTRIGGERCONDITION_SID, WDG_59_DRIVERA_E_DRIVER_STATE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

   /* Implements WDG_ESDD_UD_008 */
   /*
   * Check whether timeout value requested is more than the maximum timeout
   * value configured
   */
   /* Implements WDG_ESDD_UD_023 */
   /* Implements WDG_ESDD_UD_024 */
   /* Implements WDG_ESDD_UD_019 */
  if (timeout > WDG_59_DRIVERA_MAXIMUM_TIMEOUT)
  {
    /* TRACE [R4, WDG146] */
    /* Report to DET, if Watchdog is not in idle state */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
    WDG_59_DRIVERA_SETTRIGGERCONDITION_SID, WDG_59_DRIVERA_E_PARAM_TIMEOUT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET error was reported */
  if (E_OK == LenReturnValue)
  #endif
  {
    /* Implements WDG_ESDD_UD_013 */
    /* Check if critical section protection is required */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
    #endif

    /* Check if the current mode is slow */
    if (WDGIF_SLOW_MODE == Wdg_59_DriverA_GddCurrentMode)
    {

      /* Set the trigger counter value considering the slow mode
       * Multiply by thousand as ulSlowTimeValue is in microseconds
       */
      /* QAC warning: START Msg(2:2834)-5 */
      /* QAC warning: START Msg(2:2814)-1 */
      /* Implements WDG_ESDD_UD_008 */
      /* Implements WDG_ESDD_UD_022 */
      Wdg_59_DriverA_GulTiggerCounter = ((timeout * WDG_59_DRIVERA_THOUSAND)
                                / Wdg_59_DriverA_GpConfigPtr->ulSlowTimeValue );
      /* END Msg(2:2814)-1 */
      /* END Msg(2:2834)-5 */

    }
    else if (WDGIF_FAST_MODE == Wdg_59_DriverA_GddCurrentMode)
    {

      /* Set the trigger counter value considering the fast mode
       * Multiply by thousand as ulFastTimeValue is in microseconds
       */
      /* QAC warning: START Msg(2:2834)-5 */
      /* Implements WDG_ESDD_UD_008 */
      /* Implements WDG_ESDD_UD_022 */
      Wdg_59_DriverA_GulTiggerCounter = ((timeout * WDG_59_DRIVERA_THOUSAND)
                                 / Wdg_59_DriverA_GpConfigPtr->ulFastTimeValue);
      /* END Msg(2:2834)-5 */

    }
    else
    {
      /* The trigger counter need not be set for off mode */
    }

    /* Implements WDG_ESDD_UD_013 */
    /* Check if critical section protection is required */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
    #endif
  }
  /* Check if DET is enabled */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
}
#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Wdg_59_DriverA_GetVersionInfo
**
** Service ID           : 0x04
**
** Description          : This service returns the version information of this
**                        module.
**
** Sync/Async           : Synchronous
**
** Re-entrancy          : Re-entrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : versioninfo
**
** Return parameter     : None
**
** Preconditions        : None
**
** Global Variables Used : None
**
** Functions Invoked     : Det_ReportError.
**
** Registers Used        : None
**
*******************************************************************************/
#if (WDG_59_DRIVERA_VERSION_INFO_API == STD_ON)

#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/*
 * The pointer versioninfo is used as per the AUTOSAR requirement WDG109.
 * The Null check for the versioninfo has been done as part of
 * the DET check.
 */

 /* Implements WDG_ESDD_UD_010 */
 /* Implements WDG_ESDD_UD_031 */
 /* Implements WDG172,WDG109,WDG067,WDG068,WDG099,WDG174,WDG119_Conf */
 /* Implements AR_PN0064_FR_0001,AR_PN0064_FR_0008,EAAR_PN0034_FR_0049 */

 /* QAC warning: START Msg(2:3227)-2 */
FUNC(void,WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_GetVersionInfo(P2VAR
       (Std_VersionInfoType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST) versioninfo)
{
  /* END Msg(2:3227)-2 */

  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Implements WDG_ESDD_UD_009 */
  /* Implements WDG_ESDD_UD_023 */
  /* Implements EAAR_PN0034_FR_0064 */

  /* Report to DET, if versioninfo pointer is equal to Null */
  if (NULL_PTR == versioninfo)

  {
    /* Report to DET  */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
              WDG_59_DRIVERA_GETVERSIONINFO_SID,WDG_59_DRIVERA_E_PARAM_POINTER);
  }
  else
  #endif /*#if(WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  {
    /* QAC warning: START Msg(2:2814)-1 */
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)WDG_59_DRIVERA_VENDOR_ID;
    /* END Msg(2:2814)-1 */

    /* Copy the module Id */
    versioninfo->moduleID = (uint16)WDG_59_DRIVERA_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = WDG_59_DRIVERA_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = WDG_59_DRIVERA_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = WDG_59_DRIVERA_SW_PATCH_VERSION;
  }
}
#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif  /*(WDG_59_DRIVERA_VERSION_INFO_API == STD_ON)*/

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
