/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, SPI type definitions, structure data types and  */
/* API function prototypes of SPI Driver                                      */
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
 * V1.1.0:  16-Jan-2013  : As per SCR 072, version information and include
 *                         section is updated.
 *
 * V1.1.1:  20-May-2013  : As per SCR 168, header file Spi_Debug is removed.
 *
 * V1.1.2:  06-Aug-2013  : As per CR 225, As part of SVN merge activity the
 *                         project name and environment section is updated.
 *
 * V1.1.3:  15-Jul-2014  : As per CR 550, for mantis issue #22328, following
 *                         changes are made:
 *                         1. Pre-compile checks are updated for the following
 *                            APIs: Spi_AsyncTransmit(), Spi_SyncTransmit(), and
 *                            Spi_MainFunction_Handling().
 *                         2. Copyright information is updated.
 *
 * V1.1.4: 26-Aug-2014   : As per CR 601, following changes are made:
 *                         1. File is updated after spell check.
 *                         2. MISRA C RULE VIOLATION section is updated.
 *                         3. MISRA rules violation messages are updated.
 *
 * V1.1.5:   10-Feb-2015 : As a part of Merging Activity, for the mantis#26024
 *                         following changes are made:
 *                         1. As per CR 01, for mantis #19850 AUTOSAR SWS
 *                            requirements are mapped for requirements tracing.
 *                         2. Copyright Information is Updated.
 * V1.1.6:   20-Nov-2015 : As part of P1x V4.00.05 Release, following changes
 *                         are made:
 *                         1.As per ticket ARDAAAE-1419, New macro
 *                           SPI_E_MAINFUNCTION_HANDLING_INVALIDMODE for
 *                           reporting Det is added.
 *                         2. As per Jira#ARDAAAE-1514, PreProcessor Directive
 *                            for Different hardware devices are added for
 *                            internal diagnosis.
 *                         3. As per Jira#ARDAAAE-1514, new public API
 *                            Spi_GetErrorInfo, is added for internal Diagnosis
 *                         4. As per Jira#ARDAAAE-1514, Spi_CommErrorType and
 *                            Spi_HWErrorsType, added for internal Diagnosis
 *                         5. As per ticket ARDAAAE-1327,
 *                           SPI_MAINFUNCTION_HANDLING declaration is updated to
 *                           remove the pre compiler switch
 *                           SPI_LEVEL_DELIVERED == SPI_ONE.
 *                         6. As per Jira#ARDAAAE-1533, SPI_SELFTEST_SID,
 *                            SPI_ALL_SELF_TEST, SPI_ECC_SELF_TEST and
 *                            SPI_LOOP_BACK_SELF_TEST is added
 *                         7. As per Jira#ARDAAAE-1533, conditional switches are
 *                            added for the declarations.
 *                         8. NULL_PTR check is implemented for GetVersionInfo
 *                            API.
 * V1.1.7:   18-Mar-2016 : As a part P1x 4.01.00 issue fixing,
 *                         Following changes are made
 *                         1.Mapping of memory section for global or static
 *                           variables are updated as per AUTOSAR requirement
 *                           MEMMAP022 as per ticket ARDAAAE-1672.
 * V1.1.8:   10-Aug-2016 : As a part P1x V4.01.01 release, following
 *                          changes are made
 *                         1.Added SID for Spi_GetErrorInfo API as part DFMEA
 *                           fixing.
 *                         2.As part of JIRA ticket fix ARDAAAE-1484, removed
 *                           the macro function definition
 *                           Spi_GetVersionInfo() API and added the extern
 *                           declaration of Spi_GetVersionInfo() API.
 *                         3.As part of ARDAAAE-1908,removed AR 3.2.2
 *                           related version checks and removed the switch
 *                           #if(SPI_AR_VERSION == SPI_AR_HIGHER_VERSION)
 * V1.1.9:   15-Feb-2017 : Following changes are made:
 *                         1.As part of ARDAAAE-2277,'U' is appended for MACRO
 *                           definitions wherever applicable.
 *                         2.Copyright information is updated
 */
/******************************************************************************/
#ifndef SPI_H
#define SPI_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi_Cfg.h"
#include "Spi_Types.h"      /* Included for Spi Type declaration */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define SPI_INSTANCE_ID           SPI_INSTANCE_ID_VALUE

/* Version identification */
#define SPI_VENDOR_ID              SPI_VENDOR_ID_VALUE
#define SPI_MODULE_ID              SPI_MODULE_ID_VALUE

/* AUTOSAR specification version information */

#define SPI_AR_RELEASE_MAJOR_VERSION       4U
#define SPI_AR_RELEASE_MINOR_VERSION       0U
#define SPI_AR_RELEASE_REVISION_VERSION    3U

/* File version information */
#define SPI_SW_MAJOR_VERSION       SPI_SW_MAJOR_VERSION_VALUE
#define SPI_SW_MINOR_VERSION       SPI_SW_MINOR_VERSION_VALUE
#define SPI_SW_PATCH_VERSION       SPI_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Arrays used are verified in the file which are only        */
/*                 declarations and size is configuration dependent.          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


/*******************************************************************************
**                     Service IDs                                            **
*******************************************************************************/
/* Service ID for Spi_Init() */
#define SPI_INIT_SID                  (uint8)0x00U
/* Service ID for Spi_DeInit() */
#define SPI_DEINIT_SID                (uint8)0x01U
/* Service ID for Spi_WriteIB() */
#define SPI_WRITEIB_SID               (uint8)0x02U
/* Service ID for Spi_AsyncTransmit() */
#define SPI_ASYNCTRANSMIT_SID         (uint8)0x03U
/* Service ID for Spi_ReadIB() */
#define SPI_READIB_SID                (uint8)0x04U
/* Service ID for Spi_SetupEB() */
#define SPI_SETUPEB_SID               (uint8)0x05U
/* Service ID for Spi_GetStatus() */
#define SPI_GETSTATUS_SID             (uint8)0x06U
/* Service ID for Spi_GetJobResult() */
#define SPI_GETJOBRESULT_SID          (uint8)0x07U
/* Service ID for Spi_GetSequenceResult() */
#define SPI_GETSEQUENCERESULT_SID     (uint8)0x08U
/* Service ID for Spi_GetVersionInfo() */
#define SPI_GETVERSIONINFO_SID        (uint8)0x09U
/* Service ID for Spi_SyncTransmit() */
#define SPI_SYNCTRANSMIT_SID          (uint8)0x0AU
/* Service ID for Spi_GetHWUnitStatus() */
#define SPI_GETHWUNITSTATUS_SID       (uint8)0x0BU
/* Service ID for Spi_Cancel() */
#define SPI_CANCEL_SID                (uint8)0x0CU
/* Service ID for Spi_SetAyncMode() */
#define SPI_SETAYNCMODE_SID           (uint8)0x0DU
/* Service ID for Spi_MainFunction_Driving() */
#define SPI_MAINFUNCTION_HANDLING_SID (uint8)0x10U
/* Service ID for Spi_SelfTest() */
#define SPI_SELFTEST_SID              (uint8)0x11U
/* Service ID for Spi_GetErrorInfo() */
#define SPI_GETERRORINFO_SID          (uint8)0x12U

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/

/* API services invoked with invalid channel ID */
#define SPI_E_PARAM_CHANNEL           (uint8)0x0AU
/* API services invoked with invalid job ID */
#define SPI_E_PARAM_JOB               (uint8)0x0BU
/* API services invoked with invalid sequence ID */
#define SPI_E_PARAM_SEQ               (uint8)0x0CU
/* Spi_SetupEB API invoked with length greater than configured length */
#define SPI_E_PARAM_LENGTH            (uint8)0x0DU
/* Spi_GetHWUnitStatus API invoked with invalid hardware unit ID */
#define SPI_E_PARAM_UNIT              (uint8)0x0EU
/* API services invoked before the initialization of SPI Driver */
#define SPI_E_UNINIT                  (uint8)0x1AU
/* API services invoked in a wrong sequence */
#define SPI_E_SEQ_PENDING             (uint8)0x2AU
/* Spi_SyncTransmit API invoked at wrong time */
#define SPI_E_SEQ_IN_PROCESS          (uint8)0x3AU
/* Spi_init API service called while the Spi driver has already been
 * initialized
 */
#define SPI_E_ALREADY_INITIALIZED     (uint8)0x4AU
/* Spi_Init API service invoked with null config pointer */
#define SPI_E_PARAM_CONFIG            (uint8)0xEEU
/* Spi_Init API invoked with pointer to invalid database */
#define SPI_E_INVALID_DATABASE        (uint8)0xEFU

/* Spi_MainFunction_Handling() invoked in interrupt mode */
#define SPI_E_MAINFUNCTION_HANDLING_INVALIDMODE (uint8)0xF0U

/* Spi_GetVersionInfo API invoked with invalid pointer */

#define SPI_E_PARAM_POINTER           (uint8)0x10U

/* hardware unit CSIG0 */
#define SPI_HW_UNIT_CSIG0             (uint8)0x00U
/* hardware unit CSIG1 */
#define SPI_HW_UNIT_CSIG1             (uint8)0x01U
/* hardware unit CSIG2 */
#define SPI_HW_UNIT_CSIG2             (uint8)0x02U
/* hardware unit CSIG3 */
#define SPI_HW_UNIT_CSIG3             (uint8)0x03U
/* hardware unit CSIG4 */
#define SPI_HW_UNIT_CSIG4             (uint8)0x04U
/* hardware unit CSIG5 */
#define SPI_HW_UNIT_CSIG5             (uint8)0x05U
/* hardware unit CSIG6 */
#define SPI_HW_UNIT_CSIG6             (uint8)0x06U
/* hardware unit CSIG7 */
#define SPI_HW_UNIT_CSIG7             (uint8)0x07U

/* hardware unit CSIH0 */
#define SPI_HW_UNIT_CSIH0             (uint8)0x80U
/* hardware unit CSIH1 */
#define SPI_HW_UNIT_CSIH1             (uint8)0x81U
/* hardware unit CSIH2 */
#define SPI_HW_UNIT_CSIH2             (uint8)0x82U
/* hardware unit CSIH3 */
#define SPI_HW_UNIT_CSIH3             (uint8)0x83U
/* hardware unit CSIH4 */
#define SPI_HW_UNIT_CSIH4             (uint8)0x84U
/* hardware unit CSIH5 */
#define SPI_HW_UNIT_CSIH5             (uint8)0x85U
/* hardware unit CSIH6 */
#define SPI_HW_UNIT_CSIH6             (uint8)0x86U
/* hardware unit CSIH7 */
#define SPI_HW_UNIT_CSIH7             (uint8)0x87U

#if (SPI_SELF_TEST_API == STD_ON)
#if (SPI_LOOPBACK_SELFTEST == SPI_TWO && SPI_ECC_SELFTEST == SPI_TWO)
/* ECC & Loop back Self test */
#define SPI_ALL_SELF_TEST             (uint8)0x00U
#endif
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_TWO)
/* ECC Self test */
#define SPI_ECC_SELF_TEST             (uint8)0x01U
#endif
#endif
#if (SPI_LOOPBACK_SELFTEST == SPI_TWO)
/* Loop Back Self Test */
#define SPI_LOOP_BACK_SELF_TEST       (uint8)0x02U
#endif
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* If Internal Diagnosis Error Buffer size is Greater than Zero */
#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* Type of Different Hardware Errors */
typedef enum  ETag_Spi_HWErrorsType
{
  /* No Hardware Error */
  SPI_NO_ERROR = 0,
  /* Over Run Error */
  SPI_OVERRUN_ERROR,
  /* Parity Error */
  SPI_PARITY_ERROR,
  /* Data Consistency Error */
  SPI_DATA_CONSISTENCY_ERROR,
  /* Overflow Error */
  SPI_OVERFLOW_ERROR,
  /* 1 Bit ECC Error */
  SPI_ECC_1BIT_ERROR
}Spi_HWErrorsType;

/* Structure for Hardware Error Reporting */
typedef struct STag_Spi_CommErrorType
{
  /* Type of the Hardware Error */
  Spi_HWErrorsType ErrorType;
  /* HW unit in which error is reported */
  Spi_HWUnitType HwUnit;
  /* Sequence id for which error is reported */
  Spi_SequenceType SeqID;
  /* Job id for which error is reported */
  Spi_JobType JobID;
}Spi_CommErrorType;
#endif
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define SPI_START_SEC_PUBLIC_CODE
#include "MemMap.h"

extern FUNC(void, SPI_PUBLIC_CODE) Spi_Init
(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr);


extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_DeInit(void);

#if (((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)) && (SPI_IB_CONFIGURED == STD_ON))
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_WriteIB
               (Spi_ChannelType Channel, P2CONST(Spi_DataType, AUTOMATIC,
                                             SPI_APPL_CONST) DataBufferPtr);
#endif /* (((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO) || \
          (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)) && \
          (SPI_IB_CONFIGURED == STD_ON)) */

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_AsyncTransmit
                                               (Spi_SequenceType Sequence);
#endif /* (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        * (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
        */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO))
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_ReadIB
               (Spi_ChannelType Channel, P2VAR(Spi_DataType, AUTOMATIC,
                                             SPI_APPL_DATA) DataBufferPointer);
#endif /* SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ZERO ||
          SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ONE) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO))
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetupEB
    (Spi_ChannelType Channel,
     P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
     P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
     Spi_NumberOfDataType Length);
#endif /* SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ONE ||
          SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO */


extern FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetStatus(void);

extern FUNC(Spi_JobResultType, SPI_PUBLIC_CODE)
                       Spi_GetJobResult(Spi_JobType Job);

extern FUNC(Spi_SeqResultType, SPI_PUBLIC_CODE)
                       Spi_GetSequenceResult(Spi_SequenceType Sequence);

#if (SPI_VERSION_INFO_API == STD_ON)
extern FUNC(void, SPI_PUBLIC_CODE) Spi_GetVersionInfo
(P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA)versioninfo);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SyncTransmit
                                                  (Spi_SequenceType Sequence);
#endif

#if (SPI_HW_STATUS_API == STD_ON)
extern FUNC(Spi_StatusType, SPI_PUBLIC_CODE) Spi_GetHWUnitStatus
                                                 (Spi_HWUnitType HWUnit);
#endif

#if (SPI_CANCEL_API == STD_ON)
extern FUNC(void, SPI_PUBLIC_CODE) Spi_Cancel(Spi_SequenceType Sequence);
#endif

#if (SPI_LEVEL_DELIVERED == SPI_TWO)
extern FUNC(Std_ReturnType, SPI_PUBLIC_CODE) Spi_SetAsyncMode
                                                  (Spi_AsyncModeType Mode);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
            (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
extern FUNC(void, SPI_PUBLIC_CODE) Spi_MainFunction_Handling(void);
#endif

#if (SPI_SELF_TEST_API == STD_ON)
extern FUNC(Spi_ReturnStatus, SPI_PUBLIC_CODE) Spi_SelfTest (
                                              Spi_SelfTestType LucTestFeature );
#endif

#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
extern FUNC(uint8, SPI_PUBLIC_CODE) Spi_GetErrorInfo (
        P2VAR(Spi_CommErrorType, AUTOMATIC, SPI_CONFIG_DATA) LpUserBuffer,
        uint8 LucBufferSize );
#endif

#define SPI_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* MISRA Violation: START Msg(4:3684)-1 */
/* Structure for SPI Init configuration */
extern CONST(Spi_ConfigType, SPI_CONST) Spi_GstConfiguration[];
/* END Msg(4:3684)-1 */
#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
#endif /* SPI_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
