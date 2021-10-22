/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi.c                                                       */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the implementations AUTOSAR specified APIs for SPI      */
/* handler.                                                                   */
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
 * V1.0.0:  29-Aug-2012  : Initial Version
 *
 * V1.0.1:  19-Oct-2012  : As per SCR 029, In API Spi_ReadIB pre-compile
 *                         condition SPI_EXTENDED_DATA_LENGTH is added.
 *
 * V1.0.2:  27-Nov-2012  : As per SCR 042, macro SPI_HWUNIT_ASYNCHRONOUS check
 *                         is added for APIs Spi_AsyncTransmit and
 *                         Spi_MainFunction_Handling.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 072, the following changes are made
 *                         1. Version macros are updated.
 *                         2. APIs Spi_Init, Spi_AsyncTransmit are updated for
 *                            Hardware priority handling functionality.
 *                         3. Type casting of Spi_DataType is removed in APIs
 *                            Spi_ReadIB, Spi_SetupEB for byte alignment
 *                            implementation.
 *                         4. Copyright information is updated.
 *
 * V1.1.1:  18-Mar-2013  : As per SCR 113 for Mantis issue 5420, the following
 *                         changes are made
 *                         1. Spi_Init() - The configuration registers are
 *                            updated for the jobs in high priority sequences.
 *                         2. Spi_AsyncTransmit() - Enable transmit cancel
 *                            interrupt when there is a request for high
 *                            priority sequence communication.
 *                         3. In SPI Spi_Init, condition check of DET error
 *                            'SPI_E_ALREADY_INITIALIZED' is put under
 *                            pre-compile option 'SPI_ALREADY_INIT_DET_CHECK'.
 *                         4. File version information is updated with the new
 *                            macro 'SPI_C_SW_PATCH_VERSION'.
 *
 * V1.1.2:  22-Apr-2013  : As per SCR 145, following change is made:
 *                         Software Patch version macro SPI_C_SW_PATCH_VERSION
 *                         is removed in Version Information header.
 *
 * V1.1.3:  13-Jun-2013  : As per SCR 181, following changes are made:
 *                         In SPI Spi_AsyncTransmit() conditional check
 *                         for SPI_HW_PRIORITY_ENABLED is added.
 *
 * V1.2.0:  26-Jul-2013  : As per CR 219, for mantis issue #8821, #1290 and
 *                         #12397 following changes are made:
 *                         1. Spi_Init() function is updated to support
 *                            configurable static HW unit configuration where
 *                            all common HW unit registers are initialized
 *                            during Spi_Init() function and not during each
 *                            transmission.
 *                         2. 'SPI_SEQ_STARTNOTIFICATION_ENABLED' pre-compile
 *                            check is added for asynchronous mode.
 *                         3. SPI_C_SW_MINOR_VERSION macro is updated.
 *
 * V1.2.1:  06-Aug-2013  : As per CR 225, As part of SVN merge activity the
 *                         project name and environment section is updated.
 *
 * V1.2.2:  03-Sep-2013  : As per CR 243 for the mantis issues #13806 and #8421,
 *                         the following changes are made:
 *                         1. Spi_Cancel() Api is updated.
 *                         2. Sequence start notification functionality part is
 *                            updated in Api Spi_AsyncTransmit().
 *                         3. Sequence start notification  and  synchronous
 *                            end notification sequence functionality part are
 *                            updated in Api Spi_SyncTransmit().
 *
 * V1.3.0:  15-Jan-2014  : As per CR 330 for the mantis issues #12397, following
 *                         changes are made:
 *                         1. APIs Spi_AsyncTransmit(), Spi_Cancel() are
 *                            updated.
 *                         2. Pre-compile condition
 *                            SPI_LEVEL_DELIVERED == SPI_ZERO is added for
 *                            boolean variable 'Spi_GblSyncTx'.
 *                         3. Copyright information is updated.
 *                         4. Updated as per C coding guideline.
 *
 * V1.4.0:  21-Mar-2014  : As per CR 424 for the mantis issues #19537, following
 *                         changes are made:
 *                         1. Function headers are updated for Global Variable
 *                            in the following APIs: Spi_Init, Spi_WriteIB,
 *                            Spi_AsyncTransmit, Spi_ReadIB, Spi_SyncTransmit
 *                            and Spi_Cancel.
 *                         2. Critical Section Protection is updated for
 *                            'Spi_GaaSeqCancel' in the APIs Spi_AsyncTransmit
 *                            and Spi_Cancel.
 *                         3. SPI_C_SW_MINOR_VERSION macro is updated.
 *
 * V1.5.0:  02-Jun-2014  : As per CR 507, for the mantis issue #21647 following
 *                         changes are made:
 *                         1. API Spi_Init is updated for the
 *                            'SPI_PERSISTENT_HW_CONFIGURATION_ENABLED'
 *                            pre-compile check and Spi_LoopBackSelfTest.
 *                         2. In API Spi_WriteIB pre-compile check is updated
 *                            for SPI_IB_CONFIGURED == STD_ON.
 *                         3. MISRA C RULE VIOLATION section updated.
 *                         4. MISRA rules violation messages are updated.
 *                         5. Comments are updated.
 *                         6. SPI_C_SW_MINOR_VERSION macro is updated.
 *                         7. The variable 'Spi_GucAllQueueSts' is renamed to
 *                            'Spi_GusAllQueueSts' as per C coding guideline.
 *
 * V1.5.1: 08-Jul-2014   : As per CR 550 for mantis #22312, #22324, #22213,
 *                         #21502, #22328, #21877, #22212 and #22066 following
 *                         changes are made:
 *                         1. New macros 'SPI_CSIG_CLR_STS_FLAGS' and
 *                            'SPI_CSIH_CLR_STS_FLAGS' are added to clear status
 *                            registers for CSIG and CISH individually.
 *                         2. API Spi_SyncTransmit is updated for the following:
 *                             1. To support multiple Async and sync HW units at
 *                                the same time.
 *                             2. Det check is updated for the following DETs:
 *                                'SPI_E_PARAM_SEQ' and 'SPI_E_SEQ_IN_PROCESS'.
 *                         3. All function headers are updated.
 *                         4. Pre-compile check is updated for the following
 *                            APIs: Spi_SyncTransmit(), Spi_AsyncTransmit(),
 *                            and Spi_MainFunction_Handling().
 *                         5. Comments are updated for #endif
 *
 * V1.5.2: 01-Aug-2014   : As per CR 581 for mantis #20712 and #22858,
 *                         file is updated after spell check.
 *
 * V1.5.3  09-Sep-2014   : As per CR 601, following changes are made:
 *                         1. MISRA C RULE VIOLATION section is updated.
 *                         2. MISRA rules violation messages are updated.
 *                         3. Spi_GetJobResult(), Spi_GetSequenceResult() and
 *                            Spi_GetHWUnitStatus() APIs are updated to avoid
 *                            MISRA warnings for redundant assignment of
 *                            variabes and redundant updation of same variable
 *                            multiple times with same value.
 *                         4. In Spi_ReadIB() Api type casting is done for
 *                            "LpTxOnlyData" variable to avoid MISRA warnings.
 *
 * V1.5.4: 07-Jan-2015   : Following changes are done
 *                         1. As per mantis #25125 compilation error is fixed
 *                         2. As per mantis #25111 definition for
 *                            SPI_RAM_DATA_PROTECTION is added
 *                         3. MISRA warning message (4:3138) is added.
 *                         4. Copyright information is updated.
 *                         5. As per mantis #25125, condition check of switch
 *                            for declaration and assignment of "LpJobConfig"
 *                            has been updated.
 *
 * V1.5.5:  10-Feb-2015  : As a part of Merging Activity, for the mantis#26024
 *                         following changes are made:
 *                         1. As per CR 01, for mantis #19850 AUTOSAR SWS
 *                            requirements are mapped for requirements tracing.
 *                         2. File is updated for C coding guidelines.
 *                         3. As per CR 01, for mantis #14360 API Spi_ReadIB()
 *                            is updated to perform shift operation for received
 *                            data before saving it into software buffer when
 *                            SPI_TX_ONLY_MODE_CONFIGURED and blEDLEnabled are
 *                            true.
 *
 * V1.5.6:  28-Mar-2015  : Software Minor Version has been updated.
 *
 * V1.5.7:  19-Nov-2015  : As part of P1x V4.00.05 Release, following changes
 *                         are made:
 *                         1.As per ticket ARDAAAE-1419 and ARDAAAE-1327,
 *                           SPI_MAINFUNCTION_HANDLING is updated for adding a
 *                           new Det in case if the function is called in
 *                           interrupt mode and calling this function is
 *                           disabled when level delivered is one.
 *                         2.As per ticket ARDAAAE-1086, 'Spi_GusHwStatus' flag
 *                           is cleared in 'Spi_SyncTransmit()' function if
 *                           either sequence is SPI_SEQ_OK or SPI_SEQ_FAILED.
 *                         3.As per ticket ARDAAAE-1515, CSIH Baudrate registers
 *                           are made accessed in 16bits instead of 32bits.
 *                         4.As per Jira#ARDAAAE-1514, Spi_Init is modified
 *                           to clear Spi_GstCommErrorInfo Buffer.
 *                         5.As per Jira#ARDAAAE-1514, arguments passing to
 *                           Spi_HWTransmitSyncJob is modified.
 *                         6.As per Jira#ARDAAAE-1514, new public API
 *                           Spi_GetErrorInfo, is added for internal Diagnosis.
 *                         7.As per Jira#ARDAAAE-1533, new public API
 *                           Spi_SelfTest, is added for internal Diagnosis.
 *                         8.As per ticket ARDAAAE-1533, Loopback and Ecc self
 *                           tests are performed in Spi_Init and Spi_SelfTest
 *                           Api is modified to perform these tests based on
 *                           the user call.
 *                         9.As per ticket ARDAAAE-1488, Write-Verify
 *                           functionality check is added for all the
 *                           registers.
 *                        10.As per Jira#ARDAAAE-1558 Software metrics
 *                           improvement, following changes are made:
 *                           1.Spi_StaticInit, Spi_SeqJobChannelInit and
 *                             Spi_InitDetCheck are called from Spi_Init
 *                             function.
 *                           2.Spi_AsyncDetCheck and
 *                             Spi_AsyncTransmitInDirectAccessAndFifoMode
 *                             functions are called from Spi_AsyncTransmit
 *                             function.
 *                           3.Spi_Init and Spi_AsyncTransmit are updated for
 *                             variable declarations to fix compilation errors.
 *                        11.Fixed QAC and PolySpace warnings.
 *                        12.As part of ticket ARDAAAE-1518, Corrected critical
 *                           section protection recursion.
 * V1.5.8:  11-Mar-2016  : As part of P1x V4.01.00 Release, following changes
 *                         are made:
 *                         1.Updated Spi_Init function as part of ARDAAAE-1580.
 *                         2.MISRA violation START and END msgs for Msg(2:3227),
 *                           Msg(2:2814) and  Msg(2:3204)are added at the
 *                           respective places.
 *                         3.A check for driver status is added in
 *                           Spi_MainFunction_Handling function as part of
 *                           ticket ARDAAAE-1597.
 *                         4.A check for driver status is added in Spi_SelfTest
 *                           Api for calling the Spi_StaticInit function.
 *                         5.As per ARDAAAE-1821, SPI_UT_001 tag
 *                          is added as part of unit testing.
 * V1.5.9:  10-Aug-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made.
 *                         1.Updated Spi_SyncTransmit function as part of
 *                           metrics improvement activity.
 *                         2.As part of Write-verify implementation, added APIID
 *                           as argument for Spi_StaticInit, Spi_InternalWriteIB
 *                           Spi_HWCancel functions.
 *                         3.Updated Spi_SetAsyncMode and Spi_GetErrorInfo
 *                           functions to fix DFMEA findings.
 *                         4.As part of JIRA ticket ARDAAAE-1863, updated
 *                           Spi_GetErrorInfo API to perform the checking
 *                           if SPI driver is initialized or not.
 *                         5.As part of JIRA ticket ARDAAAE-1900, removed the
 *                           compiler switch #if (SPI_MAX_CSIH_HW_INDEX !=
 *                           SPI_ONE) from Spi_Init API.
 *                         6.As part of JIRA ticket ARDAAAE-1660, added NULL
 *                           pointer check for Spi_GpConfigPtr->pStatusArray in
 *                           Spi_Init and Spi_AsyncTransmit APIs.
 *                         7.Fixed QAC and MISRA warning.
 *                         8.Added the justifications for the pointers as part
 *                           of pointer analysis activity.
 *                         9.As part of ARDAAAE-1651, Spi_GetErrorInfo and
 *                           Spi_SetAsyncMode  APis are updated to do range
 *                           check for input parameters
 *                        10.As part of JIRA ticket ARDAAAE-1541,
 *                           Spi_AsyncTransmit API is updated
 *                           for start sequence notification.
 *                        11.As part of JIRA ticket ARDAAAE-1484,
 *                           Spi_GetVersionInfo API is implemented as a function
 *                        12.As part of ARDAAAE-1908,removed AR 3.2.2
 *                           related version checks and removed the switch
 *                           #if(SPI_AR_VERSION == SPI_AR_HIGHER_VERSION)
 *                        13.Updated the check for maximum buffer size based on
 *                           user configured value in function Spi_GetErrorInfo.
 *                        14.As part of ARDAAAE-1822, updated the function
 *                           header with the list of used registers, global
 *                           variables and function invoked.
 *                        15.A check for driver status is added in Spi_SelfTest
 *                           API for calling the Spi_StaticInit function as part
 *                           of testing activity.
 *                        16.Added UD ID's 'SPI_ESDD_UD_xxx' and Requirements
 *                           in respective places.
 * V1.5.10:  24-Oct-2016  : Following changes are made:
 *                        1. As part of safety analysis(ARDAAAE-2049),added
 *                           conditional check against the LenReturnValue
 *                           in Spi_SetupEB API for the DET check
 *                           SPI_E_PARAM_LENGTH.
 *                        2. Updated the function Spi_SelfTest to return the
 *                           correct status when invalid mode is passed as an
 *                           input parameter as part of ARDAAAE-2074.
 *                        3. As part of ARDAAAE-2094, removed the unwanted
 *                           multiple declaration of the local variable LucVar.
 *                        4. Updated Spi_SelfTest API to perform the
 *                           Spi_GddDriverStatus busy check even when DET is off
 *                           as per the ticket ARDAAAE-2104.
 *                        5. Updated Spi_ReadIB API to put the accessing of
 *                           Spi_GpConfigPtr->pChannelIBRead under correct
 *                           pre-compile switch as part of ticket ARDAAAE-2109.
 *                        6. As part of ARDAAAE-2060, added untraced
 *                           requirements.
 * V1.5.11:  15-Feb-2017  : Following changes are made:
 *                          1. As part of ARDAAAE-2130,QAC warning justification
 *                             added at relevant places.
 *                          2. As part of ARDAAAE-2106,a new check is added in
 *                             Spi_AsyncTransmit() to ensure the array element
 *                             accessed from Spi_GaaSeqQueue[] is within
 *                             the defined array size.
 *                          3. As part of ARDAAAE-2277,following changes are
 *                             made:
 *                              a. Constants are moved to left hand side
 *                                 for condition checks at all applicable places
 *                              b. 'U' is appended for MACRO definitions
 *                                 wherever applicable.
 *                              c. Declaration and initialization of
 *                                 LucNoOfErrorsCopied is separated in
 *                                 Spi_GetErrorInfo API.
 *                              d. Removed unwanted requirement mapping comments
 *                          4. Copyright information is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Implements SPI092, SPI272, SPI273 */
#include "Spi.h"
#include "Spi_Scheduler.h"
#include "Spi_Ram.h"
#include "Spi_Driver.h"
#include "Dem.h"

#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Implements SPI369, SPI069 */
/* AUTOSAR release version information */
#define SPI_C_AR_RELEASE_MAJOR_VERSION \
                                  SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_C_AR_RELEASE_MINOR_VERSION \
                                  SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_C_AR_RELEASE_REVISION_VERSION \
                               SPI_AR_RELEASE_REVISION_VERSION_VALUE


/* File version information */
#define SPI_C_SW_MAJOR_VERSION    1U
#define SPI_C_SW_MINOR_VERSION    6U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/


#if (SPI_AR_RELEASE_MAJOR_VERSION != SPI_C_AR_RELEASE_MAJOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Major Version"
#endif

#if (SPI_AR_RELEASE_MINOR_VERSION != SPI_C_AR_RELEASE_MINOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Minor Version"
#endif

#if (SPI_AR_RELEASE_REVISION_VERSION != SPI_C_AR_RELEASE_REVISION_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Revision Version"
#endif


#if (SPI_SW_MAJOR_VERSION != SPI_C_SW_MAJOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Software Major Version"
#endif /* END of SPI_SW_MAJOR_VERSION */

#if (SPI_SW_MINOR_VERSION != SPI_C_SW_MINOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Software Minor Version"
#endif /* END of SPI_SW_MINOR_VERSION */

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message      : (4:0489) Increment or decrement operation performed         */
/*                on pointer                                                  */
/* Rule         : MISRA-C:2004 Rule 17.4                                      */
/* Justification: To access these pointers in optimized                       */
/*                way in this function                                        */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(4:0489)-1 and                            */
/*                END Msg(4:0489)-1 tags in the code.                         */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/*                 pointer.                                                   */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Pointer arithmetic is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-2 and                           */
/*                 END Msg(4:0488)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0316) Cast from a pointer to void to a pointer to       */
/*                  object.                                                   */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Cast is performed between a pointer to void to pointer to  */
/*                 object type to prevent publishing of internal structure.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-3 and                           */
/*                 END Msg(4:0316)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To access only the lower byte of the converted values      */
/*                 from the conversion register.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0759)-4 and                           */
/*                 END Msg(4:0759)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2985) This operation is redundant. The value of the     */
/*                 result is always that of the left-hand operand.            */
/* Rule          : MISRA-C:2004                                               */
/* Justification : The value of the macro SPI_RX_BUFFER_START can have a value*/
/*                 other than 0 based on configuration.                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2985)-5 and                           */
/*                 END Msg(4:2985)-5 tags in the code.                        */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0400) An object is modified more than once              */
/*                 between sequence points - evaluation order unspecified.    */
/* Rule          : MISRA-C:2004 Rule 1.2 and Rule 12.2                        */
/* Justification : 'Spi_GusAllQueueSts' and 'Spi_GucHwUnitStatus' are         */
/*                 assigned with the result after the bitwise operation where */
/*                 the right hand side value is unchanged.This is a valid     */
/*                 statement in C.                                            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0400)-6 and                           */
/*                 END Msg(4:0400)-6 tags in the code.                        */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                 result is always '0' or '1'.                               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The value of the object is based on the user configuration.*/
/*                 Hence this warning ceases to exist in case multiple        */
/*                 sequence/job/channels are configured. Increment operation  */
/*                 is done based on a conditional check which shall be        */
/*                 executed only under certain configurations. Based on this  */
/*                 value another operation shall be executed.                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-7 and                           */
/*                 END Msg(4:2984)-7 tags in the code.                        */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2992) The value of this 'if' controlling expression is  */
/*                 always 'false'.                                            */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is false because */
/*                 of the variable SPI_TX_DUAL_SEQ_SIZE. The value of the     */
/*                 variable is configuration dependant                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2992)-8 and                           */
/*                 END Msg(4:2992)-8 tags in the code.                        */
/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : Since SPI_TX_DUAL_SEQ_SIZE is declared a value that is     */
/*                 equal to LddSeqCounterBottom in some configurations, it    */
/*                 occurs. The value is configuration dependant               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-9 and                           */
/*                 END Msg(4:2996)-9 tags in the code.                        */
/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always true since  */
/*                 the variable SPI_LOOPBACK_SELFTEST is enabled for some     */
/*                 configurations and disabled for some.                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-10 and                          */
/*                 END Msg(4:2995)-10 tags in the code.                       */
/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2991) The value of this 'if' control expression         */
/*                 is always 'true'.                                          */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is always true   */
/*                 since variable updating in pre-compile ON condition.       */
/*                 However, when SPI_LOOPBACK_SELFTEST is other than SPI_ZERO */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-11 and                          */
/*                 END Msg(4:2991)-11 tags in the code.                       */
/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2880) This code is unreachable.                         */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : The conditions will be satisfied based on configurations   */
/*                 and there is a possibility for that part of the code to    */
/*                 execute when SPI_TX_DUAL_SEQ_SIZE is greater than 1.       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2880)-12 and                          */
/*                 END Msg(4:2880)-12 tags in the code.                       */
/******************************************************************************
**                         QAC Warnings                                       **
*******************************************************************************/
/* 1. QAC Warning:                                                            */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR APIs and Vendor specific*/
/*                 APIs cannot be modified to be made as constant.            */
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
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-3 and                           */
/*                 END Msg(2:2824)-3  tags in the code.                       */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:0862) This #include "U:/temp/MemMap.h" directive is     */
/*                 redundant.                                                 */
/* Rule          : NA                                                         */
/* Justification : As per requirement [MEMMAP003],the inclusion of the memory */
/*                 mapping header files within the code is a MISRA violation. */
/*                 As neither executable code nor symbols are included        */
/*                 (only pragmas) this violation is an approved exception     */
/*                 without  side effects.                                     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */

/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:1476) Range of possible enum values suggests this test  */
/*                 is always false.                                           */
/* Rule          : NA                                                         */
/* Justification : This check is added to ensure that user shall not pass     */
/*                 invalid mode value.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:1476)-5 and                           */
/*                 END Msg(2:1476)-5  tags in the code.                       */

/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (2:3206) The parameter 'x' is not used in this function.   */
/* Rule          : NA                                                         */
/* Justification : These parameters are used when SPI_EB_CONFIGURED is STD_ON.*/
/*                 Since these are passed as arguments, pre-compile switch    */
/*                 cannot be added.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-6 and                           */
/*                 END Msg(2:3206)-6  tags in the code.                       */

/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access. All register addresses are generated with */
/*                 volatile qualifier. There is no impact on the functionality*/
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3416)-7 and END Msg(2:3416)-7         */
/*                 tags in the code.                                          */

/******************************************************************************/

/* 8. QAC Warning:                                                            */
/* Message       : (3:3352) This 'switch' statement contains only two         */
/*                 execution paths.                                           */
/* Rule          : NA                                                         */
/* Justification : Case statements which used in this functions are executed  */
/*                 only when the Macros are enabled. (SPI_LOOPBACK_SELFTEST is*/
/*                 configured as 0 for this configuration)                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(3:3352)-8 and                           */
/*                 END Msg(3:3352)-8 tags in the code.                        */

/******************************************************************************/
/* Implements AR_PN0063_NR_0009, AR_PN0063_FR_0010, EAAR_PN0034_FR_0066 */
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name       : Spi_Init
**
** Service ID          : 0x00
**
** Description         : This service performs initialization of the SPI Driver
**                       component
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : const Spi_ConfigType *ConfigPtr
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : None
**
** Global Variable     : Spi_GddDriverStatus,Spi_GpFirstJobList,
**                       Spi_GpConfigPtr, Spi_GpFirstChannel, Spi_GpFirstJob
**                       Spi_GpFirstSeq,Spi_GddQueueIndex, Spi_GblQueueStatus
**                       Spi_GusAllQueueSts,Spi_GstCommErrorInfo,
**                       Spi_GucBufferIndex, Spi_GaaHighPriorityCommRequest
**                       Spi_GblSyncTx, Spi_GusHwStatus
**
** Function Invoked    : Det_ReportError, Spi_StaticInit, Spi_LoopBackSelfTest
**                       Spi_EccSelfTest, Spi_SeqJobChannelInit,
**                       Spi_InitDetCheck
**
** Registers Used      : CSIHnCTL0, CSIHnCTL1, CSIHnCTL2, CSIHnSTCR0, EICn,
**                       CSIHnBRSy, CSIHnCFGx, CSIHnTX0W, CSIHnRX0H, CSIHnSTR0,
**                       CSIGnCTL0, CSIGnCTL1, CSIGnCTL2, CSIGCFG0, CSIGnSTCR0,
**                       CSIGnSTR0, CSIGnRX0, CSIGnTX0H ,ECCCSIHnTRC,
**                       ECCCSIHnTMC, ECCCSIHnCTL, ECCCSIHnTED, DTCTn,
**                       IMRn, DDAn, DSAn, SELCSIHnDMA, CSIGnBCTL0,
**                       CSIHnMCTL1, CSIHnMCTL2, DCENn, DTFRn, DCSTCn
*******************************************************************************/
#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements SPI_ESDD_UD_001 */
/* Implements SPI_ESDD_UD_123 */
/* Implements SPI298, SPI013, SPI082, SPI128, SPI010, SPI008, SPI359, SPI344 */
/* Implements SPI299, SPI015, SPI283, SPI225_Conf, SPI064, AR_PN0063_FR_0005*/
/* Implements SPI175, SPI091_Conf, SPI103_Conf, SPI106_Conf,AR_PN0063_FR_0090 */
/* Implements SPI005, SPI100, SPI228_Conf, SPI249, SPI250, AR_PN0063_FR_0001 */
/* Implements SPI235, SPI234, EAAR_PN0034_FR_0025, EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(void, SPI_PUBLIC_CODE) Spi_Init
(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-1 */
{
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  boolean LblErrorFlag;
  #endif /*END of SPI_DEV_ERROR_DETECT */

  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Defining a local pointer for the status byte */
  P2VAR(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpStatusPtr;
  #endif /*
          * END of ((SPI_LEVEL_DELIVERED == SPI_ONE) ||
          *        (SPI_LEVEL_DELIVERED == SPI_TWO))
          */

  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || \
                                        (SPI_LEVEL_DELIVERED == SPI_TWO))
  uint8 LucVar;
  #endif
  /* Implements SPI_ESDD_UD_159 */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  Spi_CommErrorType LstErrorType;
  uint8 LucVariable;
  #endif

  #if (SPI_LOOPBACK_SELFTEST == SPI_ONE || SPI_LOOPBACK_SELFTEST == SPI_TWO || \
       SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO )
  Std_ReturnType LenReturnValue;
  #if (SPI_LOOPBACK_SELFTEST == SPI_ZERO)
  LenReturnValue = E_OK;
  #endif
  #endif

  /* Loop back self test for configured HW units */
  #if (SPI_LOOPBACK_SELFTEST == SPI_ONE || SPI_LOOPBACK_SELFTEST == SPI_TWO)
    LenReturnValue = Spi_LoopBackSelfTest();
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  #if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO )
    /* MISRA Violation: START Msg(4:2995)-10 */
    /* MISRA Violation: START Msg(4:2991)-11 */
    if (E_OK == LenReturnValue)
    /* END Msg(4:2995)-10 */
    /* END Msg(4:2991)-11 */
    {
      LenReturnValue = Spi_EccSelfTest();
    }
    else
    {
      /* No action required */
    }
  #endif
  #endif

  #if (SPI_LOOPBACK_SELFTEST == SPI_ONE || SPI_LOOPBACK_SELFTEST == SPI_TWO || \
       SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO )
  if (E_OK == LenReturnValue)
  #endif
  {
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Check for NULL Pointer and Already Init Det errors */
    LblErrorFlag = Spi_InitDetCheck(ConfigPtr);
    /* If no DET errors, continue */
    if (SPI_FALSE == LblErrorFlag)
    #endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
    {
      /* Implements SPI_ESDD_UD_117 */
      /* QAC Warning: START Msg(2:2814)-2 */
      /* Initialize the module only if Database is present */
      if (SPI_DBTOC_VALUE != ConfigPtr->ulStartOfDbToc)
      /* END Msg(2:2814)-2 */
      {
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Implements SPI_ESDD_UD_091 */
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                          SPI_INIT_SID, SPI_E_INVALID_DATABASE);
        #endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
      }
      else /* SPI_DBTOC_VALUE == ConfigPtr->ulStartOfDbToc */
      {
        /* Implements SPI_ESDD_UD_185 */

        /* Load ConfigPtr to Global pointer variable  */
        Spi_GpConfigPtr = ConfigPtr;

        /* MISRA Violation: START Msg(4:0316)-3 */
        /* Implements SPI_ESDD_UD_109 */
        /* QAC Warning: START Msg(2:2814)-2 */
        /* Load first channel to Global pointer variable */
        Spi_GpFirstChannel =
         (P2CONST(Spi_ChannelPBConfigType, SPI_DATA, SPI_PRIVATE_CONST))
                                                Spi_GpConfigPtr->pFirstChannel;
        /* END Msg(2:2814)-2 */

        /* Load first job to Global pointer variable*/
        Spi_GpFirstJob =
         (P2CONST(Spi_JobConfigType, SPI_DATA, SPI_PRIVATE_CONST))
                                                   Spi_GpConfigPtr->pFirstJob;

        /* Implements SPI_ESDD_UD_108 */
        /*  Load first sequence to Global pointer variable */
        Spi_GpFirstSeq =
          (P2CONST(Spi_SequenceConfigType, SPI_DATA, SPI_PRIVATE_CONST))
                                                   Spi_GpConfigPtr->pFirstSeq;

        /*  Load first job to Global pointer variable */
        Spi_GpFirstJobList =
          (P2CONST(Spi_JobListType, SPI_DATA, SPI_PRIVATE_CONST))
                                                   Spi_GpConfigPtr->pJobList;
        /* END Msg(4:0316)-3 */
        #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
        /* Clear the Hardware unit Index */
        LstErrorType.HwUnit = SPI_ZERO;
        /* Clear the Sequence Index */
        LstErrorType.SeqID = SPI_ZERO;
        /* Clear the Job Index */
        LstErrorType.JobID = SPI_ZERO;
        /* Clear the Error */
        LstErrorType.ErrorType = SPI_NO_ERROR;

        LucVariable = SPI_ZERO;
        /* Implements SPI_ESDD_UD_159 */
        while (SPI_MAX_ERROR_BUFFER_SIZE > LucVariable)
        {
          /* Initialise the Error Information buffer with no error */
          Spi_GstCommErrorInfo[LucVariable] = LstErrorType;
          LucVariable++;
        }
        /* Initialise the Error index with zero */
        Spi_GucBufferIndex = SPI_ZERO;
        #endif
         /* Invoke the function for initializing Spi sequence results,
                 Job results and channel data. */
        Spi_SeqJobChannelInit();

        #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || \
                                              (SPI_LEVEL_DELIVERED == SPI_TWO))
        /* Initialize the counter as zero */
        LucVar = SPI_ZERO;

        LpStatusPtr = Spi_GpConfigPtr->pStatusArray;

        while ((Spi_GpConfigPtr->ucNoofStatusByte > LucVar) &&
                            (NULL_PTR != LpStatusPtr))
        {

          /* Initialize the status byte as zero */
          *LpStatusPtr = SPI_ZERO;
          /* MISRA Violation: START Msg(4:0489)-1 */
          /* Increment the pointer to status byte */
          LpStatusPtr++;
          /* END Msg (4:0489)-1 */

          /* Increment the counter */
          LucVar++;
        }

        /* Initialize the queue elements with zero */
        /* Initialize the counter as zero */
        LucVar = SPI_ZERO;
        /* Implements SPI_ESDD_UD_154 */
        while (SPI_MAX_QUEUE > LucVar)
        {
          Spi_GblQueueStatus[LucVar] = SPI_QUEUE_EMPTY;
          Spi_GddQueueIndex[LucVar] = SPI_ZERO;

          /* Increment number of jobs configured */
          LucVar++;
        }
        #endif /*
                * #if ((SPI_LEVEL_DELIVERED == SPI_ONE) ||
                *                         (SPI_LEVEL_DELIVERED == SPI_TWO))
                */

        #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
        Spi_GucHwUnitStatus = SPI_ZERO;
        #endif

        #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
        /* Initialize the queue elements with zero */
        /* Initialize the counter as zero */
        LucVar = SPI_ZERO;
        /* Implements SPI_ESDD_UD_153 */
        while ((uint8)SPI_MAX_CSIH_HW_INDEX > LucVar)
        {
          Spi_GaaHighPriorityCommRequest[LucVar] = SPI_FALSE;
          Spi_GaaHighPriorityCommActive[LucVar] = SPI_FALSE;
          Spi_GaaHighPriorityCommRequestAtIdle[LucVar] = SPI_FALSE;
          Spi_GaaHighPrioritySequence[LucVar] = SPI_NO_SEQ;
          /* Increment number of jobs configured */
          LucVar++;
        }
        #endif /* (SPI_HW_PRIORITY_ENABLED == STD_ON) */

        #if ((SPI_LEVEL_DELIVERED == SPI_TWO) || \
                                              (SPI_LEVEL_DELIVERED == SPI_ZERO))
        Spi_GblSyncTx = SPI_FALSE;
        #endif
        /* Implements SPI_ESDD_UD_157 */
        #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
        Spi_GusHwStatus = SPI_ZERO;
        #endif
        Spi_GusAllQueueSts = SPI_ZERO;
        /* Global Status variable is SPI_IDLE */
        Spi_GddDriverStatus = SPI_IDLE;

        /*Initialization when Persistent hardware configuration is
                                                               configured ON */
        #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
        Spi_StaticInit(SPI_INIT_SID);
        #endif
      } /* End of SPI_DBTOC_VALUE != ConfigPtr->ulStartOfDbToc */
    }
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    else
    #endif
    {
      /* No action required */
    }
  }
  #if (SPI_LOOPBACK_SELFTEST == SPI_ONE || SPI_LOOPBACK_SELFTEST == SPI_TWO || \
       SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO )
  else
  {
    /* No action required */
  }
  #endif
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name       : Spi_DeInit
**
** Service ID          : 0x01
**
** Description         : This service is used for de-initialization of this
**                       module.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : None
**
** Global Variable     : Spi_GddDriverStatus
**
** Function invoked    : Det_ReportError, Spi_HWDeInit
**
** Registers Used      : CSIGnCTL0,CSIGnCTL1,CSIGnCTL2,CSIGnSTCR0,CSIGCFG0, DTSn
**                       CSIHnCTL0,CSIHnCTL1,CSIHnCTL2,CSIHnSTCR0,CSIHnMCTL0,
**                       CSIHnMRWP0,CSIHnCFG0,CSIHnTX0W,CSIHnBRSy,
**                       DSAn,DDAn,DTCTn,EICn,IMRn,PORTPSRx,DTFRRQCn,DCSTCn,
**                       DTFRRQn,DCSTn,DTFRn
*******************************************************************************/

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI_ESDD_UD_002 */
/* Implements SPI021, SPI300, SPI301, SPI302, SPI046, SPI242 */
/* Implements SPI252, SPI253, SPI022, SPI176, SPI303, EAAR_PN0034_FR_0058 */
/* Implements EAAR_PN0034_FR_0064 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_DeInit(void)
{
  Std_ReturnType LenReturnValue;

  LenReturnValue = E_NOT_OK;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_DEINIT_SID, SPI_E_UNINIT);
  }

  else
  #endif
  {
    /* Check if Global status variable is SPI_BUSY */
    /* QAC Warning: START Msg(2:3416)-7 */
    if (SPI_BUSY != Spi_GddDriverStatus)
    /* END Msg(2:3416)-7 */
    {
      Spi_HWDeInit();
      LenReturnValue = E_OK;

      /* Update the SPI driver status as uninitialized */
      Spi_GddDriverStatus = SPI_UNINIT;
    }
    else
    {
      /* No action required */
    }
  }
  /* Return the value */
  return(LenReturnValue);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name       : Spi_WriteIB
**
** Service ID          : 0x02
**
** Description         : This service for writing one or more data to an
**                       IB SPI Handler/Driver channel specified
**                       by parameter.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Channel - Channel ID
**                       DataBufferPtr - Pointer to source data buffer
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GpFirstChannel
**
** Function invoked    : Det_ReportError, Spi_InternalWriteIB
**
** Registers Used      : CSIHnMRWP0, CSIHnTX0W, CSIHMCTL0
*******************************************************************************/
/* Implements SPI_ESDD_UD_003 */
/* Implements SPI_ESDD_UD_218 */

#if (((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)) && (SPI_IB_CONFIGURED == STD_ON))

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements SPI177, SPI018, SPI306, SPI004, SPI031, SPI305, SPI024, SPI098 */
/* Implements SPI356, SPI111, SPI115, SPI117, SPI137, SPI227_Conf, SPI279 */
/* Implements SPI356, SPI201_Conf, SPI197_Conf, AR_PN0063_FR_0045, SPI173 */
/* Implements AR_PN0063_FR_0046, AR_PN0063_FR_0054, AR_PN0063_FR_0058, SPI307 */
/* Implements SPI304, EAAR_PN0034_FR_0064 */

/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_WriteIB(Spi_ChannelType Channel,
           P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) DataBufferPtr)
/* END Msg(2:3227)-1 */
{
  #if ((SPI_DEV_ERROR_DETECT == STD_ON) && \
       (SPI_CHANNEL_BUFFERS_ALLOWED != SPI_ZERO))
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  #endif
  /* QAC Warning: START Msg(2:3204)-9 */
  Std_ReturnType LenReturnValue;
  /* END Msg(2:3204)-9 */
  LenReturnValue = E_OK;
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_WRITEIB_SID,
                                                          SPI_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements SPI_ESDD_UD_103 */
  /* Implements SPI_ESDD_UD_135 */
  /* Check if the channel ID passed, is valid */
  if (SPI_MAX_CHANNEL <= Channel)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                         SPI_WRITEIB_SID, SPI_E_PARAM_CHANNEL);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  /* Check for no DET errors */
  if (E_OK == LenReturnValue)
  {
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer to the post-build structure of the requested channel */
    LpPBChannelConfig = Spi_GpFirstChannel + Channel;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */

    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check if the channel is configured with external buffer */
    if (SPI_ONE == LpPBChannelConfig->ucChannelBufferType)
    /* END Msg(2:2814)-2 */
    {
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                          SPI_WRITEIB_SID, SPI_E_PARAM_CHANNEL);
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
  #endif /* End of (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO) */

  /* Check if any DET error has occurred */
  if (E_OK == LenReturnValue)
  #endif /* End of (SPI_DEV_ERROR_DETECT == STD_ON) */
  {

    #if (SPI_IB_CONFIGURED == STD_ON)
    Spi_InternalWriteIB(Channel, DataBufferPtr, SPI_WRITEIB_SID);
    #endif /* End of (SPI_IB_CONFIGURED == STD_ON) */
  } /* End of all operations if there is no DET error */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  return(LenReturnValue);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /*
        * End of ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO) ||
        * (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO))
        */

/*******************************************************************************
** Function Name       : Spi_AsyncTransmit
**
** Service ID          : 0x03
**
** Description         : This service for transmitting data asynchronously
**
** Sync/Async          : Asynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GaaSeqResult,
**                       Spi_GpFirstSeq, Spi_GpFirstJob, Spi_GucHwUnitStatus
**                       Spi_GaaSeqCancel, Spi_GaaSeqQueue, Spi_GusAllQueueSts
**                       Spi_GpFirstJobList,Spi_GpConfigPtr, Spi_GddQueueIndex
**                       Spi_GblQueueStatus, Spi_GstSeqProcess
**
** Function invoked    : Det_ReportError, Spi_InitiateJobTx, Spi_AsyncDetCheck
**                       Spi_AsyncInDirAccOrFifoMod, SPI_ENTER_CRITICAL_SECTION
**                       SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : CSIGnTX0W, CSIHnTX0W, CSIGnCTL0, CSIHnCTL0, CSIHnSTCR0,
**                       CSIHnSTR0, CSIGnSTR0, CSIGnCTL1, CSIHnCTL1, CSIGnCTL2
**                       CSIHnCTL2, CSIHnMCTL0, CSIHnBRSy, CSIHnCFGx, CSIGnCFG0,
**                       DCSTCn, DCSTn, DSAn, DTCTn, DTFRn, DTCn, DCENn,
**                       DCSTSn, IMRn, EICn, DDAn, DTFRRQCn, CSIHnTX0H
**                       CSIGnSTCR0, DTFRRQn, CSIHnMCTL2, CSIGnTX0H
**                       CSIHnRX0H, CSIGnRX0, CSIHnRX0W, PORTPSRx
*******************************************************************************/
/* Implements SPI_ESDD_UD_006 */
/* Implements SPI_ESDD_UD_144 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI178, SPI086, SPI308, SPI310, SPI309, SPI055, SPI081, SPI243 */
/* Implements SPI020, SPI167, SPI357, SPI359, SPI169, SPI217_Conf, SPI133 */
/* Implements SPI216_Conf, SPI219_Conf, SPI226_Conf, SPI311 */
/* Implements AR_PN0063_FR_0003, AR_PN0063_FR_0030, AR_PN0063_FR_0021 */
/* Implements AR_PN0063_FR_0022, AR_PN0063_FR_0027, AR_PN0063_FR_0106 */
/* Implements AR_PN0063_FR_0109, AR_PN0063_FR_0070, AR_PN0063_FR_0072 */
/* Implements SPI085, SPI036, SPI014, SPI002, SPI236, SPI262 */
/* Implements AR_PN0063_NR_0013, AR_PN0063_FR_0118, SPI221_Conf */
/* Implements AR_PN0063_FR_0084, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_AsyncTransmit
                                               (Spi_SequenceType Sequence)
/* END Msg(2:3227)-1 */
{
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  /* Implements SPI_ESDD_UD_194 */
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  #endif
  /*
   * Declare a local pointer to point to status bytes ROM value for the
   * sequence
   */
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_CONST) LpStsByteValue;
  /* Declare a local pointer to point to the start byte of RAM area */
  P2VAR(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpStsByte;
  Std_ReturnType LenReturnValue;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_HWUnitType LddHWUnit;
  Spi_HWUnitType LddHWUnitNumber;
  /* Implements SPI_ESDD_UD_131 */
  Spi_JobType LddJobListIndex;
  #endif

  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  Spi_JobType LddSeqCounterBottom;
  Spi_JobType LddLowestQueueIndex;
  Spi_JobType LddReqJobListIndex;
  uint8 LucQueueIndex;
  Spi_JobType LddNoOfJobs;
  #endif
  uint8 LucHWMemoryMode;
  uint8 LucVar;
  uint8 LucMask;

  #if (SPI_DEV_ERROR_DETECT == STD_OFF)
  LenReturnValue = E_OK;
  #endif

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  LenReturnValue = Spi_AsyncDetCheck(Sequence);
  /* Check if any DET error has occurred */
  if (E_OK == LenReturnValue)
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {

    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer to the sequence structure */
    LpSeqConfig = Spi_GpFirstSeq + Sequence;
    /* END Msg(2:2824)-3 */
    /* END Msg(4:0488)-2 */

    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get the job list index of the last job of the sequence */
    /* Implements SPI_ESDD_UD_107 */
    LddJobListIndex = LpSeqConfig->ddJobListIndex;

    /* END Msg(2:2814)-2 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer to the job list */
    LpJobList = Spi_GpFirstJobList + LddJobListIndex;
    /* END Msg(2:2824)-3 */

    /* QAC Warning: START Msg(2:2814)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer of the last job linked to this sequence */
    LpJobConfig = Spi_GpFirstJob + (LpJobList->ddJobIndex);
    /* END Msg(2:2824)-3 */
    /* END Msg(2:2814)-2 */
    /* END Msg(4:0488)-2 */
    #endif
    /* Get the status byte mask for the requested sequence */
    LucMask = LpSeqConfig->ucStsByteMask;

    /* QAC Warning: START Msg(2:2814)-2 */
    if ((SPI_ZERO != LucMask) && (NULL_PTR != Spi_GpConfigPtr->pStatusArray))
    {
    /* END Msg(2:2814)-2 */
      /* Implements SPI_ESDD_UD_177 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      LucVar =
        *((Spi_GpConfigPtr->pStatusArray) + (LpSeqConfig->usStsCheckByteIdx));
      /* END Msg(4:0488)-2 */

      LucVar = LucVar & LucMask;
    }
    else
    {
      LucVar = SPI_ZERO;
    }

    /*
     * Check if status byte mask is zero. This is to check if the requested
     * sequence shares any job with on - going sequence. If status byte mask
     * zero, check if any sequence with shared job in progress
     */
    if ((SPI_ZERO != LucMask) && (SPI_ZERO != LucVar))
    {
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      /*
       * The sequence sharing job with requested sequence is in progress
       * so, report to DET
       */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                  SPI_ASYNCTRANSMIT_SID, SPI_E_SEQ_PENDING);
      #endif
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      #if (SPI_CANCEL_API == STD_ON)
      /* Implements SPI_ESDD_UD_196 */
      /* Get the cancel byte offset for the requested sequence  */
      LucVar = Spi_GstSeqProcess[Sequence].ucCancelOffset;
      /* Get the cancel byte mask */
      LucMask = Spi_GstSeqProcess[Sequence].ucCancelMask;
      /* Implements SPI_ESDD_UD_096 */
      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif
      /* Reset the cancel bit array for this sequence */
      Spi_GaaSeqCancel[LucVar] =
                               (Spi_GaaSeqCancel[LucVar] & ((uint8)(~LucMask)));

      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif
      #endif /* End loop of (SPI_CANCEL_API == STD_ON) */
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* Get the pointer to status bytes ROM value for the sequence */
      LpStsByteValue = (Spi_GpConfigPtr->pStsValueArray) +
                                        (LpSeqConfig->usStsValueStartByteIdx);
      /* END Msg(4:0488)-2 */
      /* Get the number of status byte ROM value */
      LucVar = LpSeqConfig->ucNoOfStsByteValue;
      /* MISRA Violation: START Msg(4:0488)-2 */
      if (NULL_PTR != Spi_GpConfigPtr->pStatusArray)
      {
        /* Get the pointer to the start byte of RAM area */
        LpStsByte = (Spi_GpConfigPtr->pStatusArray) +
                                        (LpSeqConfig->usStsUpdateStartByteIdx);
      }
      else
      {
        LpStsByte = NULL_PTR;
      }
      /* END Msg(4:0488)-2 */

      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif
      /* Update driver status as busy */
      Spi_GddDriverStatus = SPI_BUSY;
      /*
       * Since no errors are reported, accept the sequence for transmission
       * Update the sequence result as SPI_SEQ_PENDING
       */
      Spi_GaaSeqResult[Sequence] = SPI_SEQ_PENDING;

      while ((SPI_ZERO < LucVar) && (NULL_PTR != LpStsByte))
      {
        /*
         * Update the status bit of the requested sequence and the sequences
         * that have jobs shared with the requested sequence
         */
        /* QAC Warning: START Msg(2:2814)-2 */
        *LpStsByte = (*LpStsByte | *LpStsByteValue);
        /* END Msg(2:2814)-2 */
        /* MISRA Violation: START Msg(4:0489)-1 */
        LpStsByte++;
        LpStsByteValue++;
        /* END Msg(4:0489)-1 */

        LucVar--;
      }
      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif

      #if (SPI_CSIH_CONFIGURED == STD_ON)

      #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
            /* Get the number of jobs configured for the requested sequence */
      LddNoOfJobs = LpSeqConfig->ddNoOfJobs;
      #endif
      /* QAC Warning: START Msg(2:2814)-2 */
      /* Get the HW Unit index of the any of the job in the sequence */
      LddHWUnit = LpJobConfig->ddHWUnitIndex;
      /* END Msg(2:2814)-2 */
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      /* Implements SPI_ESDD_UD_156 */
      /* Check if the HW Unit is CSIH */
      if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
      #endif
      {
        #if (SPI_CSIH_CONFIGURED == STD_ON)
        LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];

        /* Get the configured memory mode for this HW Unit */
        LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
        #endif
      }
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      else
      #endif
      #endif
      {
        #if (SPI_CSIG_CONFIGURED == STD_ON)
        /* Since HW Unit is CSIG, memory mode is DIRECT ACCESS by default */
        LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
        #endif
      }
      /* Implements SPI_ESDD_UD_158 */
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      if ((SPI_TWO > LucHWMemoryMode) ||
                               (SPI_TRUE == LpSeqConfig->blIsHighPriority))
      #else
      if (SPI_TWO > LucHWMemoryMode)
      #endif /* (SPI_HW_PRIORITY_ENABLED == STD_ON) */
      {
        #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON)\
                                         || (SPI_HW_PRIORITY_ENABLED == STD_ON))
        Spi_AsyncInDirAccOrFifoMod(Sequence);
        #endif /*
                * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                *           (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                *                   (SPI_FIFO_MODE == STD_ON) || \
                *                           (SPI_HW_PRIORITY_ENABLED == STD_ON))
                */
      }
      else
      {
        #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
        /* Get the index of the job list for the first job of the sequence */
        LddReqJobListIndex = LddJobListIndex + (LddNoOfJobs - SPI_ONE);
        /* Implements SPI_ESDD_UD_133 */
        /* Check the value of Global variable for Hardware status */
        if (SPI_ZERO == (Spi_GucHwUnitStatus &
                                ((Spi_HWUnitType)(SPI_ONE << LddHWUnitNumber))))

        {
          /* Check if Start sequence macro is enabled*/
          #if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
          /* Check if the notification function is configured */
          if (NULL_PTR != LpSeqConfig->pSpiSeqStartNotification)
          {
            /* Invoke the start sequence notification function */
            LpSeqConfig->pSpiSeqStartNotification();
          }
          else
          {
            /* No action required */
          }
          #endif/* #if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON) */
          #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Disable relevant interrupts */
          SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
          #endif

          LucQueueIndex = LddHWUnitNumber + SPI_TWO;

          /* Updating the status of the hardware */
          /* MISRA Violation: START Msg(4:0400)-6 */
          Spi_GucHwUnitStatus = (Spi_GucHwUnitStatus |
                                ((Spi_HWUnitType)(SPI_ONE << LddHWUnitNumber)));
          /* END Msg(4:0400)-6 */


          Spi_GddQueueIndex[LucQueueIndex] =
                   Spi_GpConfigPtr->aaHWUnitQueueIndex[LddHWUnit];

          /* Change the queue status as FILLED */
          Spi_GblQueueStatus[LucQueueIndex] = SPI_QUEUE_FILLED;
          /* MISRA Violation: START Msg(4:0400)-6 */
          Spi_GusAllQueueSts = (Spi_GusAllQueueSts |
                               ((uint16)((uint8)(SPI_ONE << (LucQueueIndex)))));
          /* Put the sequence in the queue */
          /* END Msg(4:0400)-6 */
          Spi_GaaSeqQueue[Spi_GddQueueIndex[LucQueueIndex]] = Sequence;

         #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Enable relevant interrupts */
          SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

          #endif
          /* Initiate the transmission for that sequence */
          Spi_InitiateJobTx(LddReqJobListIndex);
        }
        else
        {
          LucQueueIndex = LddHWUnitNumber + SPI_TWO;

          LddLowestQueueIndex = Spi_GpConfigPtr->aaHWUnitQueueIndex[LddHWUnit];

          /* Check if critical section protection is required */
          #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
          /*
           * Disable relevant interrupts to protect this critical
           * section
           */
          SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

          #endif
          /*
           * Place the sequence at the bottom of the queue by shifting
           * the sequences already in the queue by one position
           */
          LddSeqCounterBottom = Spi_GddQueueIndex[LucQueueIndex] + SPI_ONE;

          /* Load back the queue index to the bottom most element */
          Spi_GddQueueIndex[LucQueueIndex] = LddSeqCounterBottom;

          while(LddSeqCounterBottom > LddLowestQueueIndex )
          {
            /*MISRA Violation: START Msg(4:2996)-9 */
            /*MISRA Violation: START Msg(4:2992)-8 */
            /* Implements SPI_ESDD_UD_220 */
            /* Check whether the array index is within the array size. */
            if (SPI_TX_DUAL_SEQ_SIZE > LddSeqCounterBottom)
            /* END Msg(4:2996)-9 */
            /* END Msg(4:2992)-8 */
            {
             /* MISRA Violation: START Msg(4:2984)-7 */
             /* QAC Warning: START Msg(3:3352)-8 */
             /* MISRA Violation: START Msg(4:2880)-12 */
             /* Move the sequence entry one up in the queue */
             Spi_GaaSeqQueue[LddSeqCounterBottom] =
                            Spi_GaaSeqQueue[LddSeqCounterBottom - SPI_ONE];
             /* END Msg(4:2984)-7 */
             /* END Msg(3:3352)-8 */
             /* END Msg(4:2880)-12 */
            }
            else
            {
              /*Do nothing*/
            }
            /* Decrement the pointer */
            LddSeqCounterBottom--;
          }
          /* Place the requested sequence index at the top */
          Spi_GaaSeqQueue[LddSeqCounterBottom] = Sequence;

          /* Check if critical section protection is required */
          #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
          /* Disable relevant interrupts to protect this critical section */
          SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

          #endif
        }
        #endif /*
                * End of ((SPI_DUAL_BUFFER_MODE == STD_ON) || \
                *                           (SPI_TX_ONLY_MODE == STD_ON))
                */
      } /* End of else loop of checking if the job queue is empty */
    } /* End of else loop of checking for sequences sharing jobs */
  } /* End of the check if any DET error has occurred */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  return(LenReturnValue);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /*
        * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        *   (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
        */

/*******************************************************************************
** Function Name       : Spi_ReadIB
**
** Service ID          : 0x04
**
** Description         : This service for reading one or more data from an
**                       IB SPI Handler/Driver channel specified by
**                       parameter
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Channel - Channel ID
**                       DataBufferPointer - Pointer to destination data
**                       buffer
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GpFirstChannel,
**                       Spi_GpConfigPtr
**
** Function invoked    : Det_ReportError, Spi_HWReadIB
**
** Registers Used      : CSIHnRX0W, CSIHnRX0H, CSIHnMRWP0.
*******************************************************************************/
/* Implements SPI_ESDD_UD_004 */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO))

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI138, SPI312, SPI313, SPI314, SPI179, SPI027, SPI016, SPI315 */
/* Implements SPI004, SPI031, SPI063, SPI104_Conf, SPI204_Conf, SPI205_Conf */
/* Implements SPI202_Conf, SPI206_Conf, SPI149, AR_PN0063_FR_0019, SPI173 */
/* Implements SPI065, SPI034, EAAR_PN0034_FR_0064 */
/*
 * DataBufferPointer is the Pointer to destination data buffer in RAM.
 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_ReadIB
               (Spi_ChannelType Channel, P2VAR(Spi_DataType, AUTOMATIC,
                                          SPI_APPL_DATA) DataBufferPointer)
/* END Msg(2:3227)-1 */
{
     #if (((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO) && \
      (SPI_DEV_ERROR_DETECT == STD_ON)) || (SPI_IB_MODE == STD_ON)|| \
      ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_ZERO)))

  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  #endif

  #if ((SPI_IB_MODE == STD_ON) ||  ((SPI_TX_ONLY_MODE == STD_ON) && \
                                          (SPI_INTERNAL_RW_BUFFERS == STD_ON)))
  /* Defining a local pointer variable to hold the destination data */
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpDesPtr;
  /* Implements SPI_ESDD_UD_128 */
  Spi_NumberOfDataType LddNoOfBuffers;
  #endif

  #if (SPI_IB_MODE == STD_ON)
  /*
   * Defining a local pointer variable to point to internal buffer of the
   * requested channel
   */
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpChannelIB;
  #endif
  /* Implements SPI_ESDD_UD_147 */
  #if ((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))
  /* Defining a local pointer variable to hold the Tx data of requested IB */
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpTxOnlyData;
  /* Implements SPI_ESDD_UD_150 */
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* MISRA Violation: START Msg(4:0759)-4 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-4 */
  #endif
  /* Implements SPI_ESDD_UD_127 */
  Spi_DataType LddData;
  #endif /* #if (SPI_TX_ONLY_MODE == STD_ON) */
  #if ((SPI_IB_MODE == STD_ON) || ((SPI_CSIH_CONFIGURED == STD_ON)\
                                   && (SPI_LEVEL_DELIVERED != SPI_ZERO)))
  uint8 LucChannelBufferType;
  #endif
  /* QAC Warning: START Msg(2:3204)-9 */
  Std_ReturnType LenReturnValue;
  /* END Msg(2:3204)-9 */

  LenReturnValue = E_OK;
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_READIB_SID,
                                                         SPI_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements SPI_ESDD_UD_113 */
  /* Check if the channel ID passed, is valid */
  if (SPI_MAX_CHANNEL <= Channel)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                         SPI_READIB_SID, SPI_E_PARAM_CHANNEL);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Implements SPI_ESDD_UD_119 */
  /* Check if the data buffer pointer passed, is NULL pointer */
  if (NULL_PTR == DataBufferPointer)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                         SPI_READIB_SID, SPI_E_PARAM_POINTER);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  /* Check for no DET errors */
  if (E_OK == LenReturnValue)
  {
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer to the post-build structure of the requested channel */
    LpPBChannelConfig = Spi_GpFirstChannel + Channel;
    /* END Msg(2:2824)-3 */
    /* END Msg(4:0488)-2 */

    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check if the channel is configured with external buffer */
    if (SPI_ONE == (LpPBChannelConfig->ucChannelBufferType))
    /* END Msg(2:2814)-2 */
    {
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                          SPI_READIB_SID, SPI_E_PARAM_CHANNEL);
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
  #endif /* End of (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO) */

  /* Check if any DET error has occurred */
  if (E_OK == LenReturnValue)
  #endif /* End of SPI_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    #if ((SPI_IB_MODE == STD_ON)|| ((SPI_CSIH_CONFIGURED == STD_ON) \
                                    && (SPI_LEVEL_DELIVERED != SPI_ZERO)))
    /* Get the pointer to the post-build structure of the channel */
    LpPBChannelConfig = Spi_GpFirstChannel + Channel;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get the the type of the channel */
    LucChannelBufferType = LpPBChannelConfig->ucChannelBufferType;
    /* END Msg(2:2814)-2 */
    #endif

    #if ((SPI_IB_MODE == STD_ON) || ((SPI_TX_ONLY_MODE == STD_ON) && \
                                     (SPI_INTERNAL_RW_BUFFERS == STD_ON)))
    /*
     * DataBufferPtr is the Pointer to destination data buffer in RAM.
     */
    /* Copy the destination pointer value to a local pointer variable */
    LpDesPtr = DataBufferPointer;
    /* Implements SPI_ESDD_UD_186 */
    /* Get the number of buffers configured for the requested channel */
    LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;
    #endif

    #if (SPI_IB_MODE == STD_ON)
    /* Check if the buffer type is internal buffer and not hardware buffer */
    if (SPI_TWO > LucChannelBufferType)
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* QAC Warning: START Msg(2:2814)-2 */
      /* Get the pointer to the internal buffer of the requested channel */
      LpChannelIB = Spi_GpConfigPtr->pChannelIBRead;
      /* END Msg(2:2814)-2 */
      /* Implements SPI_ESDD_UD_208 */
      /* QAC Warning: START Msg(2:2824)-3 */
      LpChannelIB = LpChannelIB + LpPBChannelConfig->ddBufferIndex;
      /* END Msg(2:2824)-3 */
      /* END Msg(4:0488)-2 */

      do
      {
        /*
         * Copy the data from the internal buffer to the destination data
         * buffer
         */
        /* Data width is maximum 8-bit */
        /* QAC Warning: START Msg(2:2814)-2 */
        *LpDesPtr = *LpChannelIB;
        /* END Msg(2:2814)-2 */

        /* MISRA Violation: START Msg(4:0489)-1*/
        /* Increment the internal buffer pointer */
        LpChannelIB++;

        /* Increment the destination pointer */
        LpDesPtr++;
        /* END Msg(4:0489)-1*/

        /* Decrement the counter for number of buffers */
        LddNoOfBuffers--;
      } while (SPI_ZERO < LddNoOfBuffers);
    } /* End of operations if the buffer type is 'internal buffer' */
    else
    #endif /*
            * End of ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && \
            * ((SPI_DIRECT_ACCESS_MODE == STD_ON) || \
            * (SPI_FIFO_MODE == STD_ON) || (SPI_LEVEL_DELIVERED == SPI_ZERO)))
            */
    {
      #if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_ZERO))
      if (SPI_TX_ONLY_MODE_CONFIGURED ==
             (Spi_GpConfigPtr->aaHWMemoryMode[LucChannelBufferType - SPI_TWO]))
      {
       #if ((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))

        /* Get the pointer to the internal buffer of the requested channel */
        /* MISRA Violation: START Msg(4:0488)-2 */
        /* MISRA Violation: START Msg(4:2985)-5 */
        LpTxOnlyData = Spi_GpConfigPtr->pChannelIBRead +
                     ((LpPBChannelConfig->ddBufferIndex) + SPI_RX_BUFFER_START);
        /* END Msg(4:0488)-2 */
        /* END Msg(4:2985)-5 */
        do
        {
          #if (SPI_8BIT_DATA_WIDTH == STD_ON)
          /*
           * Data width is maximum 8-bit. Hence, Receive the data from the Rx
           * register to local union variable
           */
          /* QAC Warning: START Msg(2:2814)-2 */
          LddData = (uint8)(*LpTxOnlyData);
          /* END Msg(2:2814)-2 */

          #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
          /* QAC Warning: START Msg(2:2814)-2 */
          LddData = *LpTxOnlyData;
          /* END Msg(2:2814)-2 */

          #else
          /*
           * Data width is maximum 32-bit, check if the the data width of
           * requested channel is more than 16 bits
           */
          /* QAC Warning: START Msg(2:2814)-2 */
          LddData = *LpTxOnlyData;
          /* END Msg(2:2814)-2 */
          if (SPI_TRUE == LpPBChannelConfig->blEDLEnabled)
          {
            /* MISRA Violation: START Msg(4:0489)-1 */
            LpTxOnlyData++;
            /* END Msg(4:0489)-1 */

            LddNoOfBuffers--;
            /* Check if the configured data direction is LSB first */
            if (SPI_TRUE == LpPBChannelConfig->blDirection)
            {
              /*
               * Take a local union variable to construct the value from RX0W
               * register
               */
              LddData = ((LddData) >> (SPI_SIXTEEN ));
              LunDataAccess1.usRegData5[0] = (uint16)LddData;
              (*LpTxOnlyData ) = ((*LpTxOnlyData) >> (SPI_SIXTEEN));
              LunDataAccess1.usRegData5[1] = (uint16)(*LpTxOnlyData);
            }
            else
            {
              /*
               * Take a local union variable to construct the value from RX0W
               * register
               */
               if (SPI_ZERO != LpPBChannelConfig->ucDLSSetting)
               {
                 LunDataAccess1.usRegData5[1] = (uint16)LddData;
                 LunDataAccess1.usRegData5[0] = (uint16)*LpTxOnlyData;
                 LunDataAccess1.usRegData5[0] = LunDataAccess1.usRegData5[0] <<
                             (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting));
                 LunDataAccess1.ulRegData  = LunDataAccess1.ulRegData >>
                             (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting));
               }
               else
               {
                 LunDataAccess1.usRegData5[1] = (uint16)LddData;
                 LunDataAccess1.usRegData5[0] = (uint16)*LpTxOnlyData;
               }
            } /* End of if (SPI_TRUE == LpPBChannelConfig->blDirection) */
            LddData = LunDataAccess1.ulRegData;
          }
          else
          {
            /* No action required */
          }
          #endif /* End of (SPI_8BIT_DATA_WIDTH == STD_ON)*/

          *LpDesPtr = LddData;
          /* MISRA Violation: START Msg(4:0489)-1 */
          LpTxOnlyData++;
          /* Increment the destination pointer */
          LpDesPtr++;
          /* END Msg(4:0489)-1 */

          /* Decrement the counter for number of buffers */
          LddNoOfBuffers--;
        } while (SPI_ZERO < LddNoOfBuffers);
        #endif /* (SPI_TX_ONLY_MODE == STD_ON) */
      } /*
         *#if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_LEVEL_DELIVERED !=
         * SPI_ZERO))
         */
      else
      {
        #if (SPI_DUAL_BUFFER_MODE == STD_ON)
        /* Memory mode is 'Dual Buffer Mode' */
        Spi_HWReadIB(Channel, DataBufferPointer);
        #endif /* (SPI_DUAL_BUFFER_MODE == STD_ON) */
      }
      #endif /* End of ((SPI_CSIH_CONFIGURED == STD_ON) &&
                                      (SPI_LEVEL_DELIVERED != SPI_ZERO))*/
    }
  }
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  return(LenReturnValue);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO) || \
                     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)) */

/*******************************************************************************
** Function Name       : Spi_SetupEB
**
** Service ID          : 0x05
**
** Description         : This service for setting the buffers and the length
**                       of data for the external buffer of the channel
**                       specified.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Channel - Channel ID
**                       SrcDataBufferPtr - Pointer to source data buffer
**                       DesDataBufferPtr - Pointer to destination data
**                       buffer in RAM Length - Length of the data
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GpConfigPtr,
**                       Spi_GaaChannelEBData, Spi_GpFirstChannel
**
* Function invoked     : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/
/* Implements SPI_ESDD_UD_005, SPI_ESDD_UD_102 */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ONE) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO))

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/*
 * SrcDataBufferPtr is the pointer to the source data buffer and
 * DesDataBufferPtr is the Pointer to destination data buffer in RAM.
 */
/* Implements SPI180, SPI028, SPI058, SPI030, SPI317, SPI316, SPI318, SPI139 */
/* Implements SPI067, SPI046, SPI004, SPI031, SPI060, SPI258, SPI240, SPI355 */
/* Implements AR_PN0063_FR_0020, AR_PN0063_FR_0043, AR_PN0063_FR_0044*/
/* Implements EAAR_PN0034_FR_0064*/
/* Implements SPI_ESDD_UD_129, SPI078, SPI077, SPI037, SPI173 */
/* QAC Warning: START Msg(2:3227)-1 */
/* QAC Warning: START Msg(2:3206)-6 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetupEB
    (Spi_ChannelType Channel,
     P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
     P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
     Spi_NumberOfDataType Length)
/* END Msg(2:3227)-1 */
/* END Msg(2:3206)-6 */
{
  #if ((SPI_DEV_ERROR_DETECT == STD_ON) || \
      ((SPI_EB_CONFIGURED == STD_ON) && (SPI_DEV_ERROR_DETECT == STD_OFF)))
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  #endif
  /* Implements SPI_ESDD_UD_093 */
  #if (SPI_EB_CONFIGURED == STD_ON)
  /*
   * Defining a local pointer variable to point to buffer of the
   * requested channel
   */
  P2VAR(Spi_EBData, AUTOMATIC, SPI_CONFIG_DATA) LpChannelEB;
  #endif
  /* QAC Warning: START Msg(2:3204)-9 */
  Std_ReturnType LenReturnValue;
  /* END Msg(2:3204)-9 */

  LenReturnValue = E_OK;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  {
  /* END Msg(2:3416)-7 */
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETUPEB_SID,
                                                            SPI_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {

  }
  /* Check if the channel ID passed, is valid */
  if (SPI_MAX_CHANNEL <= Channel)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                      SPI_SETUPEB_SID, SPI_E_PARAM_CHANNEL);
    LenReturnValue = E_NOT_OK;
  }
  /* If it is valid channel ID, check if the length passed is valid */
  else
  {
    if (E_OK == LenReturnValue)
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      /* QAC Warning: START Msg(2:2824)-3 */
      /* Get the pointer to the channel link-time structure */
      LpPBChannelConfig = Spi_GpFirstChannel + Channel;
      /* END Msg(2:2824)-3 */
      /* END Msg(4:0488)-2 */

      /*
       * Check if the 'length' parameter is greater than configured length and
       * if length is equal to zero
       */
      /* QAC Warning: START Msg(2:2814)-2 */
      if ((SPI_ZERO == Length) || (Length > (LpPBChannelConfig->ddNoOfBuffers)))
      /* END Msg(2:2814)-2 */
      {
        /* Implements SPI_ESDD_UD_118 */
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                           SPI_SETUPEB_SID, SPI_E_PARAM_LENGTH);
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
      /* Check if the requested channel is configured for internal buffer */
      if (SPI_ONE != (LpPBChannelConfig->ucChannelBufferType))
      {
        /* Report to DET */
        (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                          SPI_SETUPEB_SID, SPI_E_PARAM_CHANNEL);
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* No action required */
      }
      #endif /* (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO) */
    }
    else
    {
      /* No action required */
    }
  }

  /* Check if any DET error has occurred */
  if (E_OK == LenReturnValue)
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    #if (SPI_EB_CONFIGURED == STD_ON)
    #if (SPI_DEV_ERROR_DETECT == STD_OFF)
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* Get the pointer to the requested structure */
    /* QAC Warning: START Msg(2:2824)-3 */
    LpPBChannelConfig = Spi_GpFirstChannel + Channel;
    /* END Msg(2:2824)-3 */
    /* END Msg(4:0488)-2 */
    #endif
    /* Get the pointer to the buffer of the requested channel */
    /* QAC Warning: START Msg(2:2814)-2 */
    LpChannelEB = &Spi_GaaChannelEBData[LpPBChannelConfig->ddBufferIndex];
    /* END Msg(2:2814)-2 */
    /*
     * Copy the source pointer to RAM area allocated for the external
     * buffer attributes of the channel
     */
    LpChannelEB->pSrcPtr = SrcDataBufferPtr;
    /* Copy the destination pointer value to a local pointer variable */
    LpChannelEB->pDestPtr = DesDataBufferPtr;
    /* Implements SPI_ESDD_UD_197 */
    /* Copy length for that channel */
    LpChannelEB->ddEBLength = Length;
    #endif  /* End of (SPI_EB_CONFIGURED == STD_ON) */
  } /* End of all operations if there is no DET error */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  return(LenReturnValue);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ONE ||
                    SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO) */

/*******************************************************************************
** Function Name       : Spi_GetStatus
**
** Service ID          : 0x06
**
** Description         : This service is for getting the status of SPI
**                       Driver Component
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_StatusType (SPI_UNINIT/SPI_IDLE/SPI_BUSY)
**
** Preconditions       : None
**
** Global Variable     : Spi_GddDriverStatus
**
** Function Invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI_ESDD_UD_009 */
/* Implements SPI181, SPI025, SPI319, SPI345, SPI320, SPI347, SPI046, SPI259 */
/* Implements EAAR_PN0034_FR_0064 */

FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetStatus(void)
{
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                 SPI_GETSTATUS_SID, SPI_E_UNINIT);
  }
  else
  {
    /* No action required */
  }
  #endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
  return(Spi_GddDriverStatus);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name       : Spi_GetJobResult
**
** Service ID          : 0x07
**
** Description         : This service is for getting result of the
**                       specified job
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Job - Job ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_JobResultType
**                       (SPI_JOB_OK/SPI_JOB_PENDING/SPI_JOB_FAILED)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GaaJobResult
**
** Function invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* QAC Warning: START Msg(2:3227)-1 */
/* Implements SPI_ESDD_UD_011 */
/* Implements SPI026, SPI038, SPI182, SPI321, SPI322, SPI046, SPI032, SPI350 */
/* Implements SPI237, SPI062, SPI012, SPI261, SPI198_Conf, SPI256, SPI267 */
/* Implements EAAR_PN0034_FR_0064 */
FUNC(Spi_JobResultType, SPI_PUBLIC_CODE)
                       Spi_GetJobResult(Spi_JobType Job)
/* END Msg(2:3227)-1 */
{
  /* Implements SPI_ESDD_UD_125 */
  Spi_JobResultType LddJobResult;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_GETJOBRESULT_SID, SPI_E_UNINIT);
    LddJobResult = SPI_JOB_FAILED;
  }
  else
  {
    LddJobResult = SPI_JOB_OK;
  }
  /* Implements SPI_ESDD_UD_104 */
  /* Implements SPI_ESDD_UD_112 */
  /* Implements SPI_ESDD_UD_136 */
  /* Check if the job ID passed, is valid */
  if (SPI_MAX_JOB <= Job)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_GETJOBRESULT_SID, SPI_E_PARAM_JOB);
    if (SPI_JOB_OK == LddJobResult)
    {
      LddJobResult = SPI_JOB_FAILED;
    }
    else
    {
      /* No Action Required */
    }
  }
  else
  {
    /* No Action Required */
  }

  if (SPI_JOB_OK == LddJobResult)
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    LddJobResult = Spi_GaaJobResult[Job];
  }
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  return(LddJobResult);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name       : Spi_GetSequenceResult
**
** Service ID          : 0x08
**
** Description         : This service is for getting result of the specified
**                       sequence
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_SeqResultType
**                       (SPI_SEQ_OK/SPI_SEQ_PENDING/SPI_SEQ_FAILED/
**                        SPI_SEQ_CANCELLED)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GaaSeqResult
**
** Function invoked    : Det_ReportError
**
** Registers Used      : None
*******************************************************************************/

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI_ESDD_UD_012 */
/* Implements SPI_ESDD_UD_126 */
/* Implements SPI183, SPI042, SPI324, SPI353, SPI354, SPI251, SPI323, SPI046 */
/* Implements SPI032, SPI039, SPI017, SPI019, SPI351, SPI199_Conf */
/* Implements EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Spi_SeqResultType, SPI_PUBLIC_CODE)
                       Spi_GetSequenceResult(Spi_SequenceType Sequence)
/* END Msg(2:3227)-1 */
{
  Spi_SeqResultType LddSeqResult;
  /* Implements SPI_ESDD_UD_139 */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                  SPI_GETSEQUENCERESULT_SID, SPI_E_UNINIT);
    LddSeqResult = SPI_SEQ_FAILED;
  }
  else
  {
    LddSeqResult = SPI_SEQ_OK;
  }
  /* Implements SPI_ESDD_UD_105 */
  /* Implements SPI_ESDD_UD_114 */
  /* Implements SPI_ESDD_UD_137 */
  /* Check if the Sequence ID passed, is valid */
  if (SPI_MAX_SEQUENCE <= Sequence)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                  SPI_GETSEQUENCERESULT_SID, SPI_E_PARAM_SEQ);
    if (SPI_SEQ_OK == LddSeqResult)
    {
      LddSeqResult = SPI_SEQ_FAILED;
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

  if (SPI_SEQ_OK == LddSeqResult)
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    LddSeqResult = Spi_GaaSeqResult[Sequence];
  }
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  return(LddSeqResult);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name       : Spi_SyncTransmit
**
** Service ID          : 0x0A
**
** Description         : This service is for transmitting data synchronously
**
** Sync/Async          : Aynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GpFirstSeq,
**                       Spi_GpFirstJob, Spi_GddSyncDriverStatus,
**                       Spi_GstHWUnitInfo, Spi_GpFirstJobList, Spi_GusHwStatus.
**
** Function invoked    : Det_ReportError, Spi_InitiateSycTransmit
**                       SPI_EXIT_CRITICAL_SECTION, SPI_ENTER_CRITICAL_SECTION
**
** Registers Used      : CSIGnCTL0, CSIHnCTL0, CSIHnCFG, EICn, CSIHnMCTL0,
**                       CSIGnCFG0, CSIGnSTCR0, CSIHnSTCR0, CSIGnCTL1, PORTPSRx
**                       CSIGnCTL2, CSIHnCTL2, CSIHnBRSy, CSIGnSTR0, CSIHnSTR0,
**                       CSIHnTX0W, CSIGnTX0W, CSIHnRX0H, CSIGnRX0, CSIHnCTL1.
*******************************************************************************/
/* Implements SPI_ESDD_UD_165 */
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI_ESDD_UD_132 */
/* Implements SPI185, SPI327, SPI329, SPI046, SPI032, SPI135, SPI238_Conf */
/* Implements SPI109, SPI110, SPI136, SPI160, SPI162, SPI231_Conf */
/* Implements SPI237_Conf, AR_PN0063_FR_0131, AR_PN0063_FR_0132, SPI140 */
/* Implements AR_PN0063_FR_0027, AR_PN0063_FR_0108, SPI330, AR_PN0063_NR_0014 */
/* Implements EAAR_PN0034_FSR_0011, SPI130, SPI129, EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SyncTransmit
                                                (Spi_SequenceType Sequence)
/* END Msg(2:3227)-1 */
{
  #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON || \
          ( (SPI_DEV_ERROR_DETECT == STD_ON) && SPI_LEVEL_DELIVERED == SPI_TWO))
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  #endif
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  #if (SPI_LEVEL_DELIVERED == SPI_TWO)
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  Spi_JobType LddJobIndex;
  #endif
  #endif
  Std_ReturnType LenReturnValue;

  LenReturnValue = E_OK;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-7 */
  /* Check if SPI Driver is initialized */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  {
  /* END Msg(2:3416)-7 */
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_SYNCTRANSMIT_SID, SPI_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if the sequence ID passed, is valid */
  if (SPI_MAX_SEQUENCE <= Sequence)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_SYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    #if (SPI_LEVEL_DELIVERED == SPI_TWO)
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer to the sequence structure */
    LpSeqConfig = Spi_GpFirstSeq + Sequence;
    /* QAC Warning: START Msg(2:2814)-2 */
    LpJobList = Spi_GpFirstJobList + (LpSeqConfig->ddJobListIndex);
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */
    /* END Msg(2:2814)-2 */
    /* QAC Warning: START Msg(2:2814)-2 */
    LddJobIndex = LpJobList->ddJobIndex;
    /* END Msg(2:2814)-2 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer of the first job linked to this sequence */
    LpJobConfig = Spi_GpFirstJob + LddJobIndex;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */
    /* Implements SPI_ESDD_UD_111 */
    /* QAC Warning: START Msg(2:2814)-2 */
    if (SPI_FALSE ==
                (Spi_GstHWUnitInfo[LpJobConfig->ddHWUnitIndex].blIsSynchronous))
    /* END Msg(2:2814)-2 */
    {
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                       SPI_SYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
    #endif /* (SPI_LEVEL_DELIVERED == SPI_TWO) */
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    /* Check if the concurrent sync transmit is enabled */

    #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)

    #if ((SPI_DEV_ERROR_DETECT == STD_OFF) || (SPI_LEVEL_DELIVERED != SPI_TWO))
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer to the sequence structure */
    LpSeqConfig = Spi_GpFirstSeq + Sequence;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */
    #endif
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Check the value of Global variable for Hardware status */
    if (SPI_ZERO == (Spi_GusHwStatus & (LpSeqConfig->usHWListIndex)))
    /* END Msg(2:2814)-2 */
    {
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif

      /* Updating the status of the hardware */
      Spi_GusHwStatus = (Spi_GusHwStatus | (LpSeqConfig->usHWListIndex));

      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif
    }
    else
    {
      /* Report to DET */
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                    SPI_SYNCTRANSMIT_SID, SPI_E_SEQ_IN_PROCESS);
      #endif

      LenReturnValue = E_NOT_OK;
    }
    #else
    /* Check if the SPI Driver is transmitting a sequence */
    if (SPI_BUSY == Spi_GddSyncDriverStatus)
    {
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                    SPI_SYNCTRANSMIT_SID, SPI_E_SEQ_IN_PROCESS);
      #endif

      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
    #endif /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON) */
  }
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    LenReturnValue = Spi_InitiateSycTransmit(Sequence);
  }
  else
  {
    /* No action required */
  }

   return(LenReturnValue);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of ((SPI_LEVEL_DELIVERED == SPI_ZERO) || \
        * ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
        *                                 (SPI_DIRECT_ACCESS_MODE == STD_ON)))
        */

/*******************************************************************************
** Function Name       : Spi_GetHWUnitStatus
**
** Service ID          : 0x0B
**
** Description         : This service is getting the status of the SPI
**                       Hardware micro-controller peripheral
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : HWUnit - ID of CSIG/CSIH Hardware Unit
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Spi_StatusType (SPI_UNINIT/SPI_IDLE/SPI_BUSY)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus
**
** Function invoked    : Det_ReportError, Spi_HWUnitStatus
**
** Registers Used      : CSIGnSTR0, CSIHnSTR0
*******************************************************************************/

#if (SPI_HW_STATUS_API == STD_ON)

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* QAC Warning: START Msg(2:3227)-1 */
/* Implements SPI_ESDD_UD_010 */
/* Implements SPI_ESDD_UD_084 */
/* Implements SPI_ESDD_UD_124 */
/* Implements SPI186, SPI141, SPI288, SPI331, SPI332, SPI287, SPI046, SPI143 */
/* Implements SPI241, SPI061, SPI011, SPI348, SPI346, SPI367, SPI275, SPI142 */
/* Implements EAAR_PN0034_FR_0064 */
/* Implements SPI229_Conf, SPI260 */
FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetHWUnitStatus
                                                 (Spi_HWUnitType HWUnit)
/* END Msg(2:3227)-1 */
{
  Spi_StatusType LddHWUnitSts;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_GETHWUNITSTATUS_SID, SPI_E_UNINIT);
    LddHWUnitSts = SPI_UNINIT;
  }
  else
  {
    LddHWUnitSts = SPI_IDLE;
  }
  /* Implements SPI_ESDD_UD_155 */
  if (SPI_MAX_HW_DETAILS <= HWUnit)
  {
    /* Implements SPI_ESDD_UD_120 */
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                    SPI_GETHWUNITSTATUS_SID, SPI_E_PARAM_UNIT);
    if (SPI_IDLE == LddHWUnitSts)
    {
      LddHWUnitSts = SPI_UNINIT;
    }
    else
    {
      /* No Action Required */
    }
  }
  else
  {
    /* No Action Required */
  }
  if (SPI_IDLE == LddHWUnitSts)
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
    LddHWUnitSts = Spi_HWUnitStatus(HWUnit);
  }
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  return(LddHWUnitSts);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* End of (SPI_HW_STATUS_API == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_Cancel
**
** Service ID          : 0x0C
**
** Description         : This service is for cancelling a on-going sequence
**
** Sync/Async          : Asynchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Sequence - Sequence ID
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GaaSeqCancel,
**                       Spi_GpFirstSeq, Spi_GpFirstJob, Spi_GstHWUnitInfo,
**                       Spi_GpFirstJobList, Spi_GstSeqProcess,
**                       Spi_GaaSeqCurrentHWUnit, Spi_GpConfigPtr
**
** Function invoked    : Det_ReportError, Spi_HWCancel
**
** Registers Used      : CSIHnCTL0, EICn, IMRn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_008 */
/* Implements SPI_ESDD_UD_086 */
#if (SPI_CANCEL_API == STD_ON)

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI145, SPI187, SPI333, SPI334, SPI046, SPI032, SPI144, SPI238 */
/* Implements SPI105_Conf, SPI146, EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(void, SPI_PUBLIC_CODE) Spi_Cancel(Spi_SequenceType Sequence)
/* END Msg(2:3227)-1 */
{
  #if ((SPI_LEVEL_DELIVERED == SPI_TWO) && (SPI_DEV_ERROR_DETECT == STD_ON))
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  Spi_JobType LddJobListIndex;
  #endif
  #if ((SPI_LEVEL_DELIVERED == SPI_TWO) && (SPI_DEV_ERROR_DETECT == STD_ON))
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  #endif
  uint8 LucStatusOffset;
  uint8 LucStatusMask;

  #if (((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) && \
        (SPI_CANCEL_API == STD_ON))
  uint8 LucIndex;
  Spi_HWUnitType LddHWUnitNumber;
  #endif
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  boolean LblErrorValue;
  #endif

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  LblErrorValue = SPI_FALSE;

  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_CANCEL_SID, SPI_E_UNINIT);
    LblErrorValue = SPI_TRUE;
  }
  else
  {
    /* No action required */
  }
  /* Check if the sequence ID passed, is valid */
  if (SPI_MAX_SEQUENCE <= Sequence)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                     SPI_CANCEL_SID, SPI_E_PARAM_SEQ);
    LblErrorValue = SPI_TRUE;
  }
  else
  {
    /* No action required */
  }

  #if (SPI_LEVEL_DELIVERED == SPI_TWO)
  if (SPI_FALSE == LblErrorValue)
  {
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* Get the pointer to the sequence structure */
    LpSeqConfig = Spi_GpFirstSeq + Sequence;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get the job list index of the last job of the sequence */
    LddJobListIndex = LpSeqConfig->ddJobListIndex;
    /* END Msg(2:2814)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* Get the pointer to the job list */
    LpJobList = Spi_GpFirstJobList + LddJobListIndex;
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */
    /* MISRA Violation: START Msg(4:0488)-2 */
    /* QAC Warning: START Msg(2:2824)-3 */
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Get the pointer of the last job linked to this sequence */
    LpJobConfig = Spi_GpFirstJob + (LpJobList->ddJobIndex);
    /* END Msg(4:0488)-2 */
    /* END Msg(2:2824)-3 */
    /* END Msg(2:2814)-2 */

    /* QAC Warning: START Msg(2:2814)-2 */
    /*
     * Check if the HW Unit of the job is configured for synchronous
     * transmission
     */
    if (SPI_TRUE ==
                (Spi_GstHWUnitInfo[LpJobConfig->ddHWUnitIndex].blIsSynchronous))
    /* END Msg(2:2814)-2 */
    {
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                               SPI_CANCEL_SID, SPI_E_PARAM_SEQ);

      LblErrorValue = SPI_TRUE;
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
  #endif /* (SPI_LEVEL_DELIVERED == SPI_TWO) */

  if (SPI_FALSE == LblErrorValue)
  #endif /* End of SPI_DEV_ERROR_DETECT == STD_ON */
  {
    /* Get the cancel byte offset for the requested sequence */
    LucStatusOffset = Spi_GstSeqProcess[Sequence].ucCancelOffset;

    /* Get the cancel byte mask */
    LucStatusMask = Spi_GstSeqProcess[Sequence].ucCancelMask;

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    #endif

    /* Update the cancel bit array for this sequence */
    Spi_GaaSeqCancel[LucStatusOffset] =
                            Spi_GaaSeqCancel[LucStatusOffset] | LucStatusMask;

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    #endif
    /* Implements SPI_ESDD_UD_146 */
    #if (((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) && \
        (SPI_CANCEL_API == STD_ON))
    LucIndex = Spi_GaaSeqCurrentHWUnit[Sequence];
    /* Implements SPI_ESDD_UD_149 */
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    if (SPI_MAX_NUM_OF_CSIG <= LucIndex)
    #endif
    {
      /* QAC Warning: START Msg(2:2814)-2 */
      LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LucIndex];
      /* END Msg(2:2814)-2 */

      if (SPI_ONE < Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber])
      {
        Spi_HWCancel(LucIndex, SPI_CANCEL_SID);
      }
      else
      {
        /* No action required */
      }
    }
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    else
    #endif
    {
      /* No action required */
    }
    #endif /*
            * (((SPI_DUAL_BUFFER_MODE == STD_ON) || \
            *                   (SPI_TX_ONLY_MODE == STD_ON)) && \
            *                                     (SPI_CANCEL_API == STD_ON))
            */
  }
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif  /* End of (SPI_CANCEL_API == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_SetAsyncMode
**
** Service ID          : 0x0D
**
** Description         : This service is for setting the asynchronous mode
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Non-Reentrant
**
** Input Parameters    : Mode - New Mode Required
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GddDriverStatus, Spi_GddAsyncMode, Spi_GblSyncTx
**
** Function invoked    : Det_ReportError, Spi_HWDisableInterrupts
**
** Registers Used      : IMRn, EICn.
*******************************************************************************/

/* Implements SPI_ESDD_UD_013 */
#if (SPI_LEVEL_DELIVERED == SPI_TWO)

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Implements SPI_ESDD_UD_130 */
/* Implements SPI150, SPI170, SPI172, SPI337, SPI335, SPI336, SPI156, SPI188*/
/* Implements SPI152, SPI360, SPI171, SPI155, AR_PN0063_FR_0030, SPI338 */
/* Implements SPI362, SPI361, EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetAsyncMode(Spi_AsyncModeType Mode)
/* END Msg(2:3227)-1 */
{
  Std_ReturnType LenReturnValue;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* QAC Warning: START Msg(2:3416)-7 */
  /* Check if SPI Driver is initialized */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  {
  /* END Msg(2:3416)-7 */
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SPI_SETAYNCMODE_SID,
                                                                 SPI_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  {
        /* QAC Warning: START Msg(2:1476)-5 */
        /* QAC Warning: START Msg(2:3416)-7 */
        if (((SPI_BUSY == Spi_GddDriverStatus) && (SPI_FALSE == Spi_GblSyncTx))
         || (Mode > SPI_INTERRUPT_MODE))
        /* END Msg(2:1476)-5 */
        /* END Msg(2:3416)-7 */
    {
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      Spi_GddAsyncMode = Mode;
      LenReturnValue = E_OK;
      if (SPI_POLLING_MODE == Mode)
      {
        Spi_HWDisableInterrupts();
      }
      else
      {
        /* No action required */
      }
    }
  }
  return(LenReturnValue);
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif  /* End of (SPI_LEVEL_DELIVERED == SPI_TWO) */


/*******************************************************************************
** Function Name            : Spi_GetVersionInfo
**
** Service ID               : 0x09
**
** Description              : This API returns the version information of
**                            this module.
**
** Sync/Async               : Synchronous
**
** Reentrancy               : Re-entrant
**
** Input Parameters         : None
**
** InOut Parameters         : None
**
** Output Parameters        : versioninfo - Pointer to where to store the
**                            version information of this module.
**
** Return parameter         : None
**
** Preconditions            : None
**
** Global Variables Used    : None
**
** Function(s) invoked      : Det_ReportError
**
** Registers Used           : None
*******************************************************************************/

/* Implements SPI_ESDD_UD_085 */
#if (SPI_VERSION_INFO_API == STD_ON)
#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements SPI_ESDD_UD_219 */
/* Implements SPI_ESDD_UD_142 */
/* Implements SPI232_Conf, SPI278, SPI184, SPI325, SPI326, SPI296, SPI371 */
/* Implements SPI102, SPI101 */
/* Implements SPI089, EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(void, SPI_PUBLIC_CODE) Spi_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA)versioninfo)
/* END Msg(2:3227)-1 */
{
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if parameter passed is equal to Null pointer */
  if (NULL_PTR == versioninfo)
  {
    /* Report to DET  */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                 SPI_GETVERSIONINFO_SID, SPI_E_PARAM_POINTER);
  }
  else
  #endif /* #if (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
    /* QAC Warning: START Msg(2:2814)-2 */
    /* Copy the vendor Id */
    versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
    /* Copy the module Id */
    versioninfo->moduleID = (uint16)SPI_MODULE_ID;
    /* Copy Software Major Version */
    versioninfo->sw_major_version = SPI_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    versioninfo->sw_minor_version = SPI_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    versioninfo->sw_patch_version = SPI_SW_PATCH_VERSION;
    /* END Msg(2:2814)-2 */
  }
}/* End of API Spi_GetVersionInfo */
#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (SPI_VERSION_INFO_API == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_MainFunction_Handling
**
** Service ID          : 0x10
**
** Description         : This function is to be invoked in the scheduler
**                       loop for asynchronous transmission in polling mode
**
** Sync/Async          : NA
**
** Re-entrancy         : Non Reentrant
**
** Input Parameters    : None
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : This function should be invoked only when polling
**                       mechanism is selected by Spi_SetAsyncMode API
**
** Global Variable     : Spi_GddDriverStatus, Spi_GddAsyncMode
**
** Function Invoked    : Det_ReportError, Spi_HWMainFunction_Handling
**
** Registers Used      : CSIGnTX0W, CSIHnTX0W, CSIGnCTL0, CSIHnCTL0, CSIHnSTCR0,
**                       CSIHnSTR0, CSIGnSTR0, CSIG0CFG0, CSIGnCTL1, CSIHnCTL1,
**                       CSIHnCTL2, CSIHnMCTL0, CSIHnBRSy, CSIHnCFGx, DTFRRQn,
**                       DCSTCn, DCSTn, DSAn, DTCTn, DTFRn, DTCn, DCENn,
**                       DCSTSn, IMRn, EICn, DDAn, DTFRRQCn, CSIHnMCTL2,
**                       CSIGnSTCR0, CSIGnTX0H, CSIHnTX0H, CSIHnRX0W,
**                       CSIHnRX0H, CSIGnRX0, PORTPSRx.
*******************************************************************************/
/* Implements SPI_ESDD_UD_016 */
#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
            (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))

#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements SPI189, SPI046, EAAR_PN0034_FR_0064 */
FUNC(void, SPI_PUBLIC_CODE) Spi_MainFunction_Handling (void)
{

  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                          SPI_MAINFUNCTION_HANDLING_SID, SPI_E_UNINIT);
    #endif
  }
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Implements SPI_ESDD_UD_164 */
  /* Check if Main function is called in Interrupt Mode */
  else if (SPI_INTERRUPT_MODE == Spi_GddAsyncMode)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                          SPI_MAINFUNCTION_HANDLING_SID,
                          SPI_E_MAINFUNCTION_HANDLING_INVALIDMODE );
  }
  #endif /* SPI_DEV_ERROR_DETECT == STD_ON */
  else
  {
    Spi_HWMainFunction_Handling();
  }
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /*
        * ((SPI_LEVEL_DELIVERED == SPI_ONE) || \
        * (((SPI_LEVEL_DELIVERED == SPI_TWO) && \
        *  (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        *    (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
        *      (SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) \
        *                                   || (SPI_TX_ONLY_MODE == STD_ON))))
        */

/*******************************************************************************
** Function Name      : Spi_SelfTest
**
** Service ID         : 0x11
**
** Description        : Function to Execute SPI Self Test
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LucTestFeature
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LenReturnTestStatus
**
** Preconditions      : None
**
** Global Variable    : Spi_GddDriverStatus
**
** Function Invoked   : Det_ReportError, Spi_LoopBackSelfTest, Spi_EccSelfTest
**                      Spi_StaticInit
**
** Registers Used     : CSIHnCTL0, CSIHnCTL1, CSIHnCTL2, CSIHnSTCR0, EICn,
**                      CSIHnBRSy, CSIHnCFGx, CSIHnTX0W, CSIHnRX0H, CSIHnSTR0,
**                      CSIGnCTL0, CSIGnCTL1, CSIGnCTL2, CSIGnCFG0, CSIGnSTCR0,
**                      CSIGnSTR0, CSIGnRX0, CSIGnTX0H ,ECCCSIHnTRC,
**                      ECCCSIHnTMC, ECCCSIHnCTL, ECCCSIHnTED, IMRn
*******************************************************************************/
/* Implements SPI_ESDD_UD_015 */
/* Implements SPI_ESDD_UD_100 */
#if (SPI_SELF_TEST_API == STD_ON)
#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements SPI_ESDD_UD_179 */
/* Implements SPI_ESDD_UD_180 */
/* Implements SPI245, EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(Spi_ReturnStatus, SPI_PUBLIC_CODE) Spi_SelfTest
                              (Spi_SelfTestType LucTestFeature)
/* END Msg(2:3227)-1 */
{
  Spi_ReturnStatus LenReturnTestStatus;
  Std_ReturnType LenReturnValue;

  /* Check if SPI Driver is Busy */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_BUSY == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                        SPI_SELFTEST_SID, SPI_E_SEQ_IN_PROCESS);
    #endif /* #if (SPI_DEV_ERROR_DETECT == STD_ON) */
    LenReturnTestStatus = SPI_SELFTEST_DRIVERBUSY;
  }
  else
  {
    /* Call Self Test API */
    switch (LucTestFeature)
    {
    #if (SPI_LOOPBACK_SELFTEST == SPI_TWO && SPI_ECC_SELFTEST == SPI_TWO)
    case SPI_ALL_SELF_TEST:
    {
      /* Call Loop Back Self Test API */
      LenReturnValue = Spi_LoopBackSelfTest();
      /* Call ECC Self Test API */
      if (E_OK == LenReturnValue)
      {
        LenReturnValue = Spi_EccSelfTest();
      }
      else
      {
        /* No action required */
      }
      if (E_OK == LenReturnValue)
      {
         LenReturnTestStatus = SPI_SELFTEST_PASS;
      }
      else
      {
         LenReturnTestStatus = SPI_SELFTEST_FAILED;
      }
      /* Retain the static register settings */
      #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
      /* QAC Warning: START Msg(2:3416)-7 */
      if(SPI_UNINIT != Spi_GddDriverStatus)
      /* END Msg(2:3416)-7 */
      {
        Spi_StaticInit(SPI_SELFTEST_SID);
      }
      else
      {
        /* No action required */
      }
      #endif
      break;
    }
    #endif
    /* Implements SPI_ESDD_UD_148 */
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    #if (SPI_ECC_SELFTEST == SPI_TWO)
    case SPI_ECC_SELF_TEST:
    {
      /* Call ECC Self Test API */
      LenReturnValue = Spi_EccSelfTest();
      if (E_OK == LenReturnValue)
      {
         LenReturnTestStatus = SPI_SELFTEST_PASS;
      }
      else
      {
         LenReturnTestStatus = SPI_SELFTEST_FAILED;
      }
      break;
    }
    #endif
    #endif
    #if (SPI_LOOPBACK_SELFTEST == SPI_TWO)
    case SPI_LOOP_BACK_SELF_TEST:
    {
      /* Call Loop Back Self Test API */
      LenReturnValue = Spi_LoopBackSelfTest();
       if (E_OK == LenReturnValue)
      {
         LenReturnTestStatus = SPI_SELFTEST_PASS;
      }
      else
      {
         LenReturnTestStatus = SPI_SELFTEST_FAILED;
      }
      /* Retain the static register settings */
      #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
      /* QAC Warning: START Msg(2:3416)-7 */
      if(SPI_UNINIT != Spi_GddDriverStatus)
      /* END Msg(2:3416)-7 */
      {
      Spi_StaticInit(SPI_SELFTEST_SID);
      }
      else
      {
        /* No action required */
      }
      #endif
      break;
    }
    #endif
    default :
      /* Set the status to invalid mode */
      LenReturnTestStatus = SPI_SELFTEST_INVALID_MODE;
      break;
    /* START Msg(3:3352)-8 */
    }
    /* END Msg(3:3352)-8 */
   }

   return LenReturnTestStatus;
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* #if (SPI_SELF_TEST_API == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_GetErrorInfo
**
** Service ID         : 0x12
**
** Description        : Function to Copy Hardware Error Details to User Buffer
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpUserBuffer - User Buffer pointer
**                      LucBufferSize - Number of Errors To be copied
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : LucNoOfErrorsCopied - Number of Errors Copied
**
** Preconditions      : None
**
** Global Variable    : Spi_GddDriverStatus, Spi_GucBufferIndex,
**                      Spi_GstCommErrorInfo
**
** Function Invoked   : None
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_014 */
#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* Implements SPI046, AR_PN0063_FSR_0094, AR_PN0063_FR_0215 */
/* Implements AR_PN0063_FR_0216, AR_PN0063_FR_0217, AR_PN0063_FR_0218 */
/* Implements EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-1 */
FUNC(uint8, SPI_PUBLIC_CODE) Spi_GetErrorInfo (
              P2VAR(Spi_CommErrorType, AUTOMATIC, SPI_CONFIG_DATA) LpUserBuffer,
              uint8 LucBufferSize )
/* END Msg(2:3227)-1 */
{
  /* Variable to count the number of errors copied to the user buffer */
  uint8  LucNoOfErrorsCopied;
  /* variable to hold Error Buffer index */
  uint8  LucBuffIndex;
  LucNoOfErrorsCopied = SPI_ZERO;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-7 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-7 */
  {
    /* Implements SPI_ESDD_UD_121 */
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                         SPI_GETERRORINFO_SID, SPI_E_UNINIT);
  }
  else
  #endif
  {
    if ((NULL_PTR != LpUserBuffer) &&
                                 (LucBufferSize <= SPI_MAX_ERROR_BUFFER_SIZE))
    {
      /* Copy the Error Buffer index */
      LucBuffIndex = Spi_GucBufferIndex;
      /* Don't Access currently updating Error Location */
      if (SPI_ZERO != LucBuffIndex)
      {
        LucBuffIndex--;
      }
      else
      {
        LucBuffIndex = SPI_MAX_ERROR_BUFFER_SIZE - SPI_ONE;
      }

      while ( (SPI_MAX_ERROR_BUFFER_SIZE > LucNoOfErrorsCopied) && \
                (LucNoOfErrorsCopied < LucBufferSize) && \
             (SPI_NO_ERROR != Spi_GstCommErrorInfo[LucBuffIndex].ErrorType))
      {
        /* Copy the Error Details in to user buffer */
        *LpUserBuffer =  Spi_GstCommErrorInfo[LucBuffIndex];
        /* Increment the User Buffer Location */
        LucNoOfErrorsCopied++;
        /* MISRA Violation: START Msg(4:0489)-1 */
        LpUserBuffer++;
        /* END Msg(4:0489)-1 */
        /*
         * since The Error Buffer is a cyclic one, update the Buffer Index with
         * Maximum Buffer size if reaches zero
         */
        if (SPI_ZERO == LucBuffIndex)
        {
          LucBuffIndex = SPI_MAX_ERROR_BUFFER_SIZE - SPI_ONE;
        }
        else
        {
          LucBuffIndex--;
        }
      }
    }
    else
    {
       /* No action required */
    }
  }
  return LucNoOfErrorsCopied;
}

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* End of (SPI_INTERNAL_DIAG_BUFF == STD_ON) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
