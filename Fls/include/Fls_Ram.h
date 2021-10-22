/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Fls_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Global variable declarations of FLS Driver              */
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
 * V1.0.1:  20-Mar-2016  : As part of P1x V4.01.00 release, following changes
 *                         are made :
 *                         1. As part of ARDAAAE-1597, removed the DET switch of
 *                            the extern declaration of global variable
 *                            Fls_GblInitStatus.
 *                         2. As part of ARDAAAE-1631, added extern declaration
 *                            of Fls_GblJobSuspendRequest flag.
 *                         3. As part of ARDAAAE-1672, renamed the memory
 *                            section FLS_START_SEC_VAR_UNSPECIFIED and
 *                            FLS_STOP_SEC_VAR_UNSPECIFIED to
 *                            FLS_START_SEC_VAR_INIT_UNSPECIFIED and
 *                            FLS_STOP_SEC_VAR_INIT_UNSPECIFIED respectively and
 *                            renamed the section FLS_START_SEC_VAR_BOOLEAN
 *                            and FLS_STOP_SEC_VAR_BOOLEAN to
 *                            FLS_START_SEC_VAR_INIT_BOOLEAN and
 *                            FLS_STOP_SEC_VAR_INIT_BOOLEAN respectively.
 *                         4. Removed the extern declaration of
 *                            global pointers Fls_GpFACIRegPtr and
 *                            Fls_GpECCRegPtr.
 *                         5. Renamed the global variable Fls_VerifyCompletedJob
 *                            to Fls_GblVerifyCompletedJob.
 * V1.0.2:  21-Jun-2016  : As part of P1x V4.01.01 release, following change
 *                         is made :
 *                         1. As per JIRA ID ARDAAAE-1908, removed dead code.
 * V1.0.3:  07-Sep-2016  : Following change is made:
 *                         1. As per JIRA ID ARDAAAE-2038, global variables
 *                            which are accessed in ISR is declared as Volatile.
 *                         2. Removed MISRA warning Msg(4:0828) from MISRA list
 *                            of deviations.
 * V1.0.4:  31-Jan-2017  : Following changes are made:
 *                         1. As per JIRA ID ARDAAAE-2053, Fls_GbIntrRqstFlag
 *                            changed to Fls_GblIntrRqstFlag.
 *                         2. Copyright information is updated.
 *                         3. Comments added to justify usage of Global
 *                            variables.
 * V1.0.5:  24-Apr-2017  : Following change is made:
 *                         1. As per JIRA ID ARDAAAE-2437, A global variable
 *                           'Fls_GblDemStatusFlag' to indicate potential HW
 *                            failure has been added.
 *                         2. Removed the duplicate extern declaration of
 *                            Fls_FcuGstVar.
 */
/******************************************************************************/
#ifndef FLS_RAM_H
#define FLS_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fls_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */
#define FLS_RAM_AR_RELEASE_MAJOR_VERSION      FLS_AR_RELEASE_MAJOR_VERSION
#define FLS_RAM_AR_RELEASE_MINOR_VERSION      FLS_AR_RELEASE_MINOR_VERSION
#define FLS_RAM_AR_RELEASE_REVISION_VERSION   FLS_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define FLS_RAM_SW_MAJOR_VERSION   FLS_SW_MAJOR_VERSION
#define FLS_RAM_SW_MINOR_VERSION   FLS_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/* Global Structure variable that contains FCU  internal data required for
 * FLS operation.
 */
extern VAR(Fls_FcuDataType, FLS_VAR_NOINIT)Fls_FcuGstVar;

/* Global variable to store pointer to Post build Configuration */
extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_CONFIG_CONST) Fls_GpConfigPtr;

/* Structure variable that contains FLS Global variables required for
 * FLS operation.
 */
extern VAR(Fls_GstVarProperties, FLS_VAR_NOINIT) Fls_GstVar;


#if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
/* Structure variable to Back Up Global Variables in case of Job Suspend */
extern VAR(Fls_GstVarProperties, FLS_VAR_NOINIT) Fls_GstBackUpVar;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/* Variable to store the job result */
extern VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_GenJobResult;

/* Variable to store the driver state */
extern VAR(volatile MemIf_StatusType, FLS_VAR) Fls_GenState;

/* Variable to Hold the Current Mode during Read operation*/
extern VAR(MemIf_ModeType, FLS_VAR) Fls_GenCurrentMode;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define FLS_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/* Variable that stores the module initialization status */
extern VAR(boolean, FLS_VAR) Fls_GblInitStatus;
#if (FLS_TIMEOUT_MONITORING == STD_ON)
/* Variable to monitor the occurrence of Timeout  */
extern VAR(boolean, FLS_VAR) Fls_GblTimeOutMonitor;
#endif
/* Global variable to indicate potential HW failure when executing
 * Fls_FcuClearCache(), and report to DEM */
extern VAR(boolean, FLS_VAR) Fls_GblDemStatusFlag;

#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#if (FLS_FHVE_REGS == SUPPORTED)
/* Variable to store the flash enable / protection off status */
extern VAR(boolean, FLS_VAR_NOINIT) Fls_GblFlashEnable;
#endif /* end of #if (FLS_FHVE_REGS == SUPPORTED) */

#if ((FLS_SUSPEND_API == STD_ON) || (FLS_RESUME_API == STD_ON))
/* Variable to store the Job Suspended state */
extern VAR(volatile boolean, FLS_VAR_NOINIT) Fls_GblJobSuspended;
#endif
#if (FLS_SUSPEND_API == STD_ON)
/* Variable to store the Job Suspended request status */
extern VAR(volatile boolean, FLS_VAR_NOINIT) Fls_GblJobSuspendRequest;
#endif

#if (FLS_DEV_ERROR_DETECT == STD_ON)
/* Variable to monitor successful Erase operation by doing BlankCheck after
 * erase completion.
 */
extern VAR(volatile boolean, FLS_VAR_NOINIT) Fls_GblVerifyCompletedJob;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#if (FLS_TIMEOUT_MONITORING == STD_ON)
/* Variable to store the Time out value to be used for generating Timeout  */
extern VAR(uint32, FLS_VAR_NOINIT) Fls_GulTimeOutCounter;
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"


#if (FLS_INTERRUPT_MODE == STD_ON)

#define FLS_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

/* Variable to store the Interrupt request flag status */
extern VAR(boolean, FLS_VAR) Fls_GblIntrRqstFlag;

#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"

#endif /* #if (FLS_INTERRUPT_MODE == STD_ON) */
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif  /* FLS_RAM_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
