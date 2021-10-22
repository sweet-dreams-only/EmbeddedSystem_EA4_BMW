/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Global variable definitions for Flash Wrapper Component.      */
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
 * V1.0.0:  15-Feb-2016  : Initial Version
 * V1.0.1:  21-Mar-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made :
 *                         1. As part of ARDAAAE-1597, removed the DET switch of
 *                            the global variable Fls_GblInitStatus.
 *                         2. As part of ARDAAAE-1631, added
 *                            Fls_GblJobSuspendRequest flag.
 *                         3. As part of ARDAAAE-1672, renamed the memory
 *                            section FLS_START_SEC_VAR_UNSPECIFIED and
 *                            FLS_STOP_SEC_VAR_UNSPECIFIED to
 *                            FLS_START_SEC_VAR_INIT_UNSPECIFIED and
 *                            FLS_STOP_SEC_VAR_INIT_UNSPECIFIED respectively and
 *                            renamed the section FLS_START_SEC_VAR_BOOLEAN
 *                            and FLS_STOP_SEC_VAR_BOOLEAN to
 *                            FLS_START_SEC_VAR_INIT_BOOLEAN and
 *                            FLS_STOP_SEC_VAR_INIT_BOOLEAN respectively.
 *                         4. Removed the global pointers Fls_GpFACIRegPtr and
 *                            Fls_GpECCRegPtr.
 *                         5. Renamed the global variable Fls_VerifyCompletedJob
 *                            to Fls_GblVerifyCompletedJob.
 *                         6. QAC Warning START and END msgs for Msg(2:2022)
 *                            Msg(2:3211),Msg(2:0862) are added.
 * V1.0.2:  21-Jun-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made :
 *                         1. As per ARDAAAE-1908, removed dead code.
 * V1.0.3:  07-Sep-2016  : Following change is made:
 *                         1. As per JIRA ID ARDAAAE-2038, global variables
 *                            which are accessed in ISR is declared as Volatile.
 * V1.0.4:  31-Jan-2017  : Following changes are made:
 *                         1. As per JIRA ID ARDAAAE-2053, Fls_GbIntrRqstFlag
 *                            changed to Fls_GblIntrRqstFlag.
 *                         2. Copyright information is updated.
 *                         3. As part of JIRA ID ARDAAAE-2274
 *                            comments added to justify usage of Global
 *                            variables.
 * V1.0.5:  24-Apr-2017  : Following change is made:
 *                         As per JIRA ID ARDAAAE-2437, A global variable
 *                         'Fls_GblDemStatusFlag' to indicate potential HW
 *                         failure  has been added.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for macro definitions and API prototypes */
#include "Fls.h"
/* Included for RAM variable declarations */
#include "Fls_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define FLS_RAM_C_AR_RELEASE_MAJOR_VERSION    FLS_AR_RELEASE_MAJOR_VERSION_VALUE
#define FLS_RAM_C_AR_RELEASE_MINOR_VERSION    FLS_AR_RELEASE_MINOR_VERSION_VALUE
#define FLS_RAM_C_AR_RELEASE_REVISION_VERSION \
                                           FLS_AR_RELEASE_REVISION_VERSION_VALUE
/* File version information */
#define FLS_RAM_C_SW_MAJOR_VERSION    FLS_SW_MAJOR_VERSION_VALUE
#define FLS_RAM_C_SW_MINOR_VERSION    FLS_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Implements FLS364 */
#if (FLS_RAM_AR_RELEASE_MAJOR_VERSION != FLS_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Fls_Ram.c : Mismatch in Release Major Version"
#endif

#if (FLS_RAM_AR_RELEASE_MINOR_VERSION != FLS_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Fls_Ram.c : Mismatch in Release Minor Version"
#endif

#if (FLS_RAM_AR_RELEASE_REVISION_VERSION != \
                                        FLS_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Fls_Ram.c : Mismatch in Release Revision Version"
#endif

#if (FLS_RAM_SW_MAJOR_VERSION != FLS_RAM_C_SW_MAJOR_VERSION)
  #error "Fls_Ram.c : Mismatch in Software Major Version"
#endif

#if (FLS_RAM_SW_MINOR_VERSION != FLS_RAM_C_SW_MINOR_VERSION)
  #error "Fls_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         QAC Warning                                        **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message      : (2:2022) This is a tentative definition and according to    */
/*                the ISO:C Standard, the object will automatically be        */
/*                initialized to zero.                                        */
/* Justification: The object's initialisation to zero will not affect the     */
/*                functionality.                                              */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:2022)-1 and                            */
/*                END Msg(2:2022)-1 tags in the code.                         */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message      : (2:3211) The global identifier 'Fls_GpConfigPtr' is defined */
/*                here but is not used in this translation unit.              */
/* Justification: As per AUTOSAR, all global variables extern declaration     */
/*                shall be given in Fls_Ram.h                                 */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(2:3211)-2 and                            */
/*                END Msg(2:3211)-2 tags in the code.                         */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:0862) #include "MemMap.h" directive is redundant.       */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without side effects.                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*                                                                            */
/******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* Implements FLS302,FLS318_Conf,FLS355 */
/* QAC Warning: START Msg(2:2022)-1 */
/* QAC Warning: START Msg(2:3211)-2 */

/* Global Structure variable that contains FCU  internal data required for
 * FLS operation.
 */
VAR(Fls_FcuDataType, FLS_VAR_NOINIT)Fls_FcuGstVar;

/* Global variable to store pointer to Post build Configuration */
P2CONST(Fls_ConfigType, FLS_VAR, FLS_CONFIG_CONST)Fls_GpConfigPtr;

/* Structure variable that contains FLS Global variables required for
 * FLS operation.
 */
VAR(Fls_GstVarProperties, FLS_VAR_NOINIT) Fls_GstVar;

#if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
/* Structure variable to Back Up Global Variables in case of Job Suspend */
VAR(Fls_GstVarProperties, FLS_VAR_NOINIT) Fls_GstBackUpVar;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/* Variable to store the job result */
VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_GenJobResult = MEMIF_JOB_OK;

/* Variable to store the driver state */
VAR(volatile MemIf_StatusType, FLS_VAR) Fls_GenState = MEMIF_UNINIT;

/* Variable to Hold the Current Mode during Read operation*/
VAR(MemIf_ModeType, FLS_VAR) Fls_GenCurrentMode = MEMIF_MODE_SLOW;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/* Variable to store the module initialization status */
VAR(boolean, FLS_VAR) Fls_GblInitStatus = FLS_UNINITIALIZED;
#if (FLS_TIMEOUT_MONITORING == STD_ON)
/* Variable to monitor the occurrence of Timeout  */
VAR(boolean, FLS_VAR) Fls_GblTimeOutMonitor = FLS_FALSE;
#endif
/* Global variable to indicate potential HW failure when executing
 * Fls_FcuClearCache(), and report to DEM */
VAR(boolean, FLS_VAR) Fls_GblDemStatusFlag = FLS_FALSE;

#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#if (FLS_FHVE_REGS == SUPPORTED)
/* Variable to store the flash enable / protection off status */
VAR(boolean, FLS_VAR_NOINIT) Fls_GblFlashEnable;
#endif /* end of #if (FLS_FHVE_REGS == SUPPORTED) */

#if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
/* Variable to store the Job Suspended state */
VAR(volatile boolean, FLS_VAR_NOINIT) Fls_GblJobSuspended;
#endif
#if (FLS_SUSPEND_API == STD_ON)
/* Variable to store the Job Suspended request status */
VAR(volatile boolean, FLS_VAR_NOINIT) Fls_GblJobSuspendRequest;
#endif
#if (FLS_DEV_ERROR_DETECT == STD_ON)
/* Variable to monitor successful Erase operation by doing BlankCheck after
 * erase completion.
 */
VAR(volatile boolean, FLS_VAR_NOINIT) Fls_GblVerifyCompletedJob;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#if (FLS_TIMEOUT_MONITORING == STD_ON)
/* Variable to store the Time out value to be used for generating Timeout  */
VAR(uint32, FLS_VAR_NOINIT) Fls_GulTimeOutCounter;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#if (FLS_INTERRUPT_MODE == STD_ON)
#define FLS_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/* Variable to store the Interrupt request flag status */
VAR(boolean, FLS_VAR) Fls_GblIntrRqstFlag = FLS_ZERO;
/* END Msg(2:3211)-2 */
/* END Msg(2:2022)-1 */

#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
