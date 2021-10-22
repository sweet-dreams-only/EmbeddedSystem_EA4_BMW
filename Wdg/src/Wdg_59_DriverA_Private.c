/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Private.c                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Driver code of the Internal Watchdog Driver A Component                    */
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
 * V1.0.1:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.2:  12-Sep-2013    : As per CR 232 for mantis issue13035,
 *                           following changes are made:
 *                           1. Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           2. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.3:  20-May-2014    : As per CR 490 for mantis issue 21269, following
 *                           changes are made:
 *                           1. Register read back is implemented in API
 *                           "Wdg_59_DriverA_TriggerFunc" and Dem.h is included.
 *                           2. LucVacReadback variable added for read-back
 *                              value checking when VAC enabled.
 *
 * V1.0.4:  10-Sep-2014    : As per CR 560, MISRA message number "(4:0303)-1" is
 *                           updated as per QAC 8.1.1.
 *
 * V1.0.5:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.
 *
 * V1.0.6:  16-Mar-2016    : As part of P1x V4.01.00 release,the following
 *                           changes are made,
 *                           1.As per JIRA ticket ARDAAAE-1512, new internal
 *                             function Wdg_59_DriverA_InitDetCheck added.
 *                           2.MISRA violation START and END msgs for
 *                             Msg(2:3227),Msg(2:3892),Msg(2:1476) and
 *                             Msg(2:0862) are added at the respective places.
 *                           3.Copyright information is updated.
 *
 * V1.0.7:  18-Oct-2016    : Following changes are made:
 *                           1.As per ARDAAAE-1838,
 *                           new Header file "Wdg_59_DriverA_RegWrite.h" and
 *                           rh850_Types.h included to support Write verify
 *                           functionality  .
 *                           2.New API Wdg_59_DriverA_SetModeDetCheck
 *                           added.
 *                           3.Wdg_59_DriverA_TriggerFunc API updated to
 *                           implement write verify, Read back functionality
 *                           is removed as it is not supported.
 *                           4.As per ARDAAAE-1942,Wdg_59_DriverA_InitDetCheck
 *                           API is updated to to remove NULL_PTR DET check.
 *                           5.Added QAC warning justification for Msg(2:3227)
 *                           and Msg(2:2814).
 *                           6.As per ARDAAAE-1908,Dead code removed.
 *                           7.UT ID TAG added for the non-covered parts of the
 *                           code
 *                           8.As per ARDAAAE-1936,'WDG_ESDD_UD_XXX' and
 *                            Req ID Tags are added.
 *                           9.As per ARDAAAE-2090,Wdg_59_DriverA_InitDetCheck
 *                            API is updated to add uint16 typecast to
 *                            WDG_59_DRIVERA_ZERO macro.
 *                           10.As per ARDAAAE-2060,requirements are mapped
 *                            to code.
 *                           11.As per ARDAAAE-2096,Wdg_59_DriverA_InitDetCheck
 *                            and Wdg_59_DriverA_SetModeDetCheck API updated to
 *                            remove compilation warning and UT ID TAG.
 *
 * V1.0.8:  15-Feb-2017   : Following changes are made:
 *                         1. As part of JIRA ID ARDAAAE-2121,added QAC warning
 *                            justification for Msg(2:3416) and Msg tags in
 *                            Wdg_59_DriverA_SetModeDetCheck API.
 *                         2. Copyright information is updated.
 *                         3. As part of JIRA ID ARDAAAE-2355
 *                            The naming convention has changed from
 *                            uiApiId to ucApiId
 *                         4. As part of JIRA ID ARDAAAE-2278 The value of
 *                            function parameter is declared
 *                            with the 'const' type Qualifier. To avoid QAC
 *                            warning Msg(2:3227).
 *                         5. As part of JIRA ID ARDAAAE-2278 For
 *                            Wdg_59_DriverA_TriggerFunc Re-entrancy is
 *                            corrected
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R3, WDG061] */
/* Implements EAAR_PN0034_NR_0001,EAAR_PN0034_FR_0081,EAAR_PN0034_FR_0030 */
/* Implements EAAR_PN0034_FR_0019,EAAR_PN0034_FR_0023,EAAR_PN0034_NR_0045 */
/* Implements EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0026 */
/* Implements EAAR_PN0034_NR_0002,EAAR_PN0034_NR_0018,EAAR_PN0034_NR_0056 */

/* Included for type definitions and macros */
#include "Wdg_59_DriverA_PBTypes.h"
/* Header file inclusion */
#include "Wdg_59_DriverA_Private.h"
/* Included for RAM variable declarations */
#include "Wdg_59_DriverA_Ram.h"
/* Included for declaration of the SV enabled registers write operation */
#include "rh850_Types.h"
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif
/* TRACE [R4, WDG080] */
/* TRACE [R3, WDG080] */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Include for declaration for write verify*/
#include"Wdg_59_DriverA_RegWrite.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MAJOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MINOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_REVISION_VERSION \
                                WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define WDG_59_DRIVERA_PRIVATE_C_SW_MAJOR_VERSION \
                                           WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_SW_MINOR_VERSION \
                                           WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MAJOR_VERSION != \
                              WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MINOR_VERSION != \
                              WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_REVISION_VERSION != \
                           WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Revision Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_SW_MAJOR_VERSION != \
                                     WDG_59_DRIVERA_PRIVATE_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_SW_MINOR_VERSION != \
                                      WDG_59_DRIVERA_PRIVATE_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Software Minor Version"
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

/*******************************************************************************
**                                QAC WARNING                                 **
*******************************************************************************/
/* 1. QAC WARNING:                                                            */
/* Message       : (2:3892) The result of this cast is implicitly converted to*/
/*                 another type.                                              */
/* Rule          : NA                                                         */
/*                 REFERENCE - ISO:C90-6.3.2.1 Semantics                      */
/* Justification : This is to get the value to pointer.                       */
/* Verification  : However, this part of the code is verified  manually and   */
/*                 it is not having any impact.                               */
/* Reference     : Look for QAC warning: START Msg(2:3892)-1 and              */
/*                 END Msg(2:3892)-1 tags in the code.                        */

/******************************************************************************/

/* 2. QAC WARNING:                                                            */
/* Message       :(2:0862) This #include "%s" directive is redundant.         */
/* Rule          : NA                                                         */
/* Justification : All the #include "%s" files contains C function            */
/*                 declarations or macro definitions to be shared between     */
/*                 several source files. This violation is an approved        */
/*                 exception without side effects.                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */

/******************************************************************************/

/* 3. QAC WARNING:                                                            */
/* Message       : (2:3206) The parameter 'ucApiId' is not used in this       */
/*                 function.                                                  */
/* Rule          : NA                                                         */
/* Justification : The  parameter is used to identify the source for WDG      */
/*                 trigger.                                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-3 and                           */
/*                 END Msg(2:3206)-3 tags in the code.                        */

/******************************************************************************/
/* 4. QAC WARNING:                                                            */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated by Post Build configurations shall  */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:2814)-4 and              */
/*                 END Msg(2:2814)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC WARNING:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Rule          : NA                                                         */
/* Justification : Logical operation accesses global objects as per AUTOSAR   */
/*                 requirement WDG017.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC warning: START Msg(2:3416)-5 and              */
/*                 END Msg(2:3416)-5 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_TriggerFunc
**
** Service ID            : Not Applicable
**
** Description           : This service is used to trigger the Watchdog timer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : ucApiId - API Service Id
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState.
**
** Functions Invoked     : WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION
**
** Registers Used        : WDTAnWDTE, WDTAnEVAC, WDTAnREF.
*******************************************************************************/

#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

/* TRACE [R4, WDG144] */
/* Implements WDG_ESDD_UD_025 */
/* Implements WDG_ESDD_UD_004 */
/* Implements WDG093,WDG094,WDG095 */
/* Implements AR_PN0064_FR_0001,AR_PN0064_FR_0008,AR_PN0064_FR_0029 */
/* Implements AR_PN0064_FR_0053,AR_PN0064_FR_0006,AR_PN0064_FR_0007 */
/* Implements AR_PN0064_FR_0031 */
/* Implements EAAR_PN0034_FSR_0002,EAAR_PN0034_FSR_0003,EAAR_PN0034_FSR_0004 */
/* Implements EAAR_PN0034_FR_0061,EAAR_PN0034_FR_0049 */
/* QAC Warning: START Msg(2:3206)-3 */
FUNC(void, WDG_59_DRIVERA_FAST_CODE) Wdg_59_DriverA_TriggerFunc
                                     (CONST(uint8,AUTOMATIC) ucApiId)
{
/* END Msg(2:3206)-3 */
  /* Variable to store VAC write value for read-back */
  #if (WDG_59_DRIVERA_VAC_ALLOWED == STD_ON)
  uint8 LucVacTrigVal ;
  #endif

  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Implements WDG_ESDD_UD_029 */
  /* Set the state of Watchdog as busy */
  Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
  #endif /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */

  /* Check if critical section protection is required */
  /* TRACE [R4, WDG040] */
  /* TRACE [R3, WDG040] */
  /* Implements WDG_ESDD_UD_013 */
  #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
  WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
  #endif

  /* Implements WDG_ESDD_UD_011 */
  /* Check whether Varying Activation Code is enabled */
  #if (WDG_59_DRIVERA_VAC_ALLOWED == STD_OFF)
  /* MISRA Violation: START Msg(4:0303)-1 */
  /* QAC warning: START Msg(2:3892)-1 */
  /* Implements WDG_ESDD_UD_008 */
  /* Implements WDG_ESDD_UD_007 */
  /* Implements WDG_ESDD_UD_014 */
  /* Initialize the register with preconfigured value */
  WDG_59_DRIVERA_REG_WRITE(WDG_59_DRIVERA_WDTAWDTE_ADDRESS,
                                                       WDG_59_DRIVERA_RESTART)

  /* Implements WDG_ESDD_UD_018 */
  /* Implements WDG_ESDD_UD_027 */
  /* Implements WDG_ESDD_UD_014 */
  WDG_59_DRIVERA_REG_WRITE_VERIFY_RUNTIME(WDG_59_DRIVERA_WDTAWDTE_ADDRESS,
           WDG_59_DRIVERA_RESTART, WDG_59_DRIVERA_WDTAWDTE_MASK, ucApiId)

  /* END Msg(2:3892)-1 */
  /* END Msg(4:0303)-1 */
  #else

   /* MISRA Violation: START Msg(4:0303)-1 */
   /* Implements WDG_ESDD_UD_008 */
   /* Implements WDG_ESDD_UD_016 */
  LucVacTrigVal = (WDG_59_DRIVERA_RESTART - WDG_59_DRIVERA_WDTAREF_ADDRESS);

  /* Implements WDG_ESDD_UD_008 */
  /* Implements WDG_ESDD_UD_007 */
  /* Implements WDG_ESDD_UD_015 */
  /* Initialize VAC register */
  WDG_59_DRIVERA_REG_WRITE(WDG_59_DRIVERA_WDTAEVAC_ADDRESS,LucVacTrigVal)

  /* Implements WDG_ESDD_UD_018 */
  /* Implements WDG_ESDD_UD_027 */
  /* Implements WDG_ESDD_UD_015 */
  WDG_59_DRIVERA_REG_WRITE_VERIFY_RUNTIME(WDG_59_DRIVERA_WDTAEVAC_ADDRESS,
        LucVacTrigVal, WDG_59_DRIVERA_WDTAEVAC_MASK, ucApiId)

  /* END Msg(4:0303)-1 */
  #endif /* WDG_59_DRIVERA_VAC_ALLOWED == STD_OFF */

  /* Check if critical section protection is required */
  /* TRACE [R4, WDG040] */
  /* TRACE [R3, WDG040] */
  /* Implements WDG_ESDD_UD_013 */
  #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
  WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
  #endif

  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Implements WDG_ESDD_UD_029 */
  /* Set the state of Watchdog as idle */
  Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
  #endif
  /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */
}
#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_InitDetCheck
**
** Service ID            : Not Applicable
**
** Description           : This function checks DET errors during WDG
**                         initialisation.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : ConfigPtr Pointer to the configuration
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK or E_NOT_OK
**
** Preconditions         : DET error detection shall be enabled
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
#include "MemMap.h"


 /* The pointer ConfigPtr is used as per the AUTOSAR requirement WDG106.
 * The Null check for the ConfigPtr has been done in
 * the DET check.
 */
  /* Implements WDG_ESDD_UD_006 */
  /* Implements WDG_ESDD_UD_009 */
  /* Implements WDG_ESDD_UD_022 */
  /* Implements EAAR_PN0034_FR_0064,EAAR_PN0034_FR_0049 */
FUNC(Std_ReturnType, WDG_59_DRIVERA_PRIVATE_CODE) Wdg_59_DriverA_InitDetCheck
(CONSTP2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
  ConfigPtr)
{
  Std_ReturnType LenReturnStatus ;
  LenReturnStatus = E_OK;

  /* QAC warning: START Msg(2:2814)-4 */
  /* Check if WDG default mode is out of range*/
  if ((WDGIF_OFF_MODE  != ConfigPtr->ddWdtamdDefaultMode ) &&
      (WDGIF_SLOW_MODE  != ConfigPtr->ddWdtamdDefaultMode ) &&
      (WDGIF_FAST_MODE  != ConfigPtr->ddWdtamdDefaultMode ))
  /* END Msg(2:2814)-4 */
  {
    LenReturnStatus = E_NOT_OK;
  }
  /* QAC warning: START Msg(2:3892)-1 */
  /* Implements WDG_ESDD_UD_008 */
  /* Check If 75% interrupt (WIE bit-field) is disabled */
  else if (((((ConfigPtr->ucWdtamdDefaultValue & (uint16)WDTAMD_WIE_MASK)
          >> WDG_59_DRIVERA_THREE) == (uint16)WDG_59_DRIVERA_ZERO)
          &&(ConfigPtr->ucWdtamdDefaultValue != (uint8)WDGIF_OFF_MODE))||
          (((ConfigPtr->ucWdtamdSlowValue & (uint16)WDTAMD_WIE_MASK)
          >> WDG_59_DRIVERA_THREE) == (uint16)WDG_59_DRIVERA_ZERO)   ||
          (((ConfigPtr->ucWdtamdFastValue & (uint16)WDTAMD_WIE_MASK)
          >> WDG_59_DRIVERA_THREE) == (uint16)WDG_59_DRIVERA_ZERO))
  {
    /* END Msg(2:3892)-1 */
    LenReturnStatus = E_NOT_OK;
  }
  else
  {
    /* No error */
  }
  return LenReturnStatus;
}

#define WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_SetModeDetCheck
**
** Service ID            : Not Applicable
**
** Description           : This function checks DET errors during WDG
**                         mode setting.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : Mode   Mode to be set for WDG
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK or E_NOT_OK
**
** Preconditions         : DET error detection shall be enabled
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_59_DRIVERA_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements WDG_ESDD_UD_009 */
/* Implements WDG_ESDD_UD_032 */
/* Implements EAAR_PN0034_FR_0064,EAAR_PN0034_FR_0049 */

FUNC(Std_ReturnType, WDG_59_DRIVERA_PRIVATE_CODE)
Wdg_59_DriverA_SetModeDetCheck(CONST(WdgIf_ModeType,AUTOMATIC) Mode)
{
  /* Variable to store the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* Implements WDG_ESDD_UD_023 */
  /* Report Error to DET, if state of Watchdog is not idle */
  /* QAC warning: START Msg(2:3416)-5 */
  if (WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState)
  {
    /* QAC warning: END Msg(2:3416)-5 */

    /* TRACE [R4, WDG010] */
    /* TRACE [R3, WDG010] */
    /* Report Error to DET */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                  WDG_59_DRIVERA_SETMODE_SID, WDG_59_DRIVERA_E_DRIVER_STATE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether input parameter 'Mode' is within the range */
  /* Implements WDG_ESDD_UD_023 */

  if ((WDGIF_OFF_MODE != Mode) && (WDGIF_SLOW_MODE != Mode)
                                               && (WDGIF_FAST_MODE != Mode))
  {
    /* TRACE [R4, WDG091] */
    /* TRACE [R3, WDG091] */
    /* TRACE [R4, WDG092] */
    /* TRACE [R3, WDG092] */
    /* Report Error to DET, if the parameter mode is not within the range */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                  WDG_59_DRIVERA_SETMODE_SID, WDG_59_DRIVERA_E_PARAM_MODE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;

  }
  else
  {
    /* No action required */
  }

  return(LenReturnValue);
}
#define WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
