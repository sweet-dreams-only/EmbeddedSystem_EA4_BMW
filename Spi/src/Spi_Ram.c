/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Ram.c                                                   */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains global variable definitions of SPI Driver               */
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
 * V1.1.0:  16-Jan-2013  : As per SCR 072, pointer GpDmaData is replaced with
 *                         variable GddDmaData and copyright information is
 *                         updated.
 *
 * V1.1.1:  18-Mar-2013  : As per SCR 113 for Mantis issue 5420, the following
 *                         change is made:
 *                         New global variable Spi_GblHighPrioritySequenceOn
 *                         is added to indicate whether high priority sequence
 *                         is getting transmitted or not.
 *
 * V1.1.2:  13-Jun-2013  : As per SCR 113, SPI_RAM_C_AR_RELEASE_PATCH_VERSION
 *                         is updated to SPI_RAM_C_AR_RELEASE_REVISION_VERSION
 *                         for SPI_AR_VERSION  == SPI_AR_HIGHER_VERSION.
 *
 * V1.2.0:  26-Jul-2013  : As per CR 219 for mantis issue #8821, #1290 and
 *                         #12397 global variables are added for High Priority
 *                         Mode, Tx Only Mode, Dual Buffer Mode and DMA.
 *
 * V1.2.1:  06-Aug-2013  : As per CR 225, as part of SVN merge activity the
 *                         project name and environment section is updated.
 *
 * V1.2.2:  29-Aug-2013  : As per CR 243 for the mantis #12996, the following
 *                         changes are made:
 *                         1.Memory class is changed for the second parameter
 *                           of the P2CONST fromSPI_CONST to SPI_VAR.
 *                         2.Variable Spi_GaaHighPriorityCommRequestAtIdle is
 *                           added in global data section.
 *
 * V1.2.3:  15-Jan-2014  : As per CR 330 for mantis #9799, following changes are
 *                         made:
 *                         1. Pre-compile check is updated for boolean variable
 *                            "Spi_GblSyncTx".
 *                         2. Copyright information is updated.
 *                         3. Updated as part of C coding guideline.
 *
 * V1.2.4:  28-May-2014  : As per CR 507 for mantis #21647, following changes
 *                         are made:
 *                         1. The following variables:
 *                            Spi_GblQueueStatus, Spi_GblInitiateJobTx,
 *                            Spi_GaaHighPriorityCommRequest,
 *                            Spi_GaaHighPriorityCommActive,
 *                            Spi_GaaHighPriorityCommRequestAtIdle and
 *                            Spi_GaaHighPrioritySequence are moved to
 *                            'SPI_START_SEC_VAR_NOINIT_BOOLEAN' section
 *                         2. The variables Spi_GusAllQueueSts and
 *                            and Spi_GddQueueIndex are moved to
 *                            'SPI_START_SEC_VAR_NOINIT_16' section.
 *                         3. The variable Spi_GucHwUnitStatus is moved to
 *                            'SPI_START_SEC_VAR_NOINIT_8' section.
 *                         4. The variable 'Spi_GucAllQueueSts' is renamed to
 *                            'Spi_GusAllQueueSts' as per C coding guideline.
 *
 * V1.2.5:  08-Jun-2014  : As per CR 550 for mantis #22213 and #22212, following
 *                         changes are made:
 *                         1. Enum "Spi_GddSyncDriverStatus" is added to hold
 *                            the status of the driver in sync mode.
 *                         2. Spi_GaaHighPrioritySequence is moved to
 *                            'SPI_START_SEC_VAR_NOINIT_8' section.
 *
 * V1.2.6:  01-Aug-2014  : As per CR 581 for mantis #20712 and #22858,
 *                         file is updated after spell check.
 *
 * V1.2.7:  24-Aug-2014  : As per CR 601 for mantis #22289, array
 *                         'Spi_GucHWFifoBufferSts' is added.
 *
 * V1.2.8:  28-Mar-2015  : As part of fix for Mantis#26660, memory mapping of
 *                         Spi_GddDmaRxData, Spi_GpDmaUnitConfig and
 *                         Spi_GddDmaData have been changes to
 *                         local CPU RAM area.
 *
 * V1.2.9:  18-Dec-2015  : As a part of the issue fixing P1x 4.00.05 release,
 *                         Following changes are made
 *                         1.As per Jira#ARDAAAE-1514, Spi_GstCommErrorInfo
 *                           and Spi_GucBufferIndex is added for internal
 *                           Diagnosis implementation.
 *                         2.As per ticket ARDAAAE-1435,
 *                           Renamed the memory section names from
 *                           SPI_START_DATA_LOC_RAM1 and SPI_STOP_DATA_LOC_RAM1
 *                           to SPI_START_SEC_DATA_LOC_RAM1 and
 *                           SPI_STOP_SEC_DATA_LOC_RAM1 according to the
 *                           requirement MEMMAP022.
 * V1.2.10: 18-Mar-2016  : As a part P1x 4.01.00 Release,
 *                         Following changes are made
 *                         1.Mapping of memory section for global or static
 *                           variables are updated as per AUTOSAR requirement
 *                           MEMMAP022 as per ticket ARDAAAE-1672.
 *                         2.Fixed and justified QAC and MISRA warnings.
 * V1.2.11: 24-Oct-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made :
 *                         1.As part of JIRA ticket ARDAAAE-1641,
 *                           declaration of global variable 'Spi_GusDataAccess'
 *                           has been split into variables
 *                           'Spi_GusSynDataAccess' and 'Spi_GusAsynDataAccess'
 *                           for Synchronous and Asynchronous transmission
 *                           respectively.
 *                         2.As part of ARDAAAE-1908 removed AR 3.2.2
 *                           related version checks and memory section
 *                           definitions.
 *                         3.As part of ARDAAAE-1672, updated INIT policy
 *                           of memory sections from NOINIT to NO_INIT.
 *                         4.Added UD ID's 'SPI_ESDD_UD_xxx' and Requirements
 *                           in respective places.
 *                         5.Added volatile qualifier for global variables
 *                           as part of JIRA ticket fix ARDAAAE-2075.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for version check macro definitions and type definitions */
#include "Spi.h"
/* Included for macro definitions and structure declarations */
#include "Spi_PBTypes.h"
/* Implements SPI_ESDD_UD_192 */
/* Included for extern declarations of global variables */
#include "Spi_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define SPI_RAM_C_AR_RELEASE_MAJOR_VERSION SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_RAM_C_AR_RELEASE_MINOR_VERSION SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_RAM_C_AR_RELEASE_REVISION_VERSION \
                                         SPI_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define SPI_RAM_C_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION_VALUE
#define SPI_RAM_C_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (SPI_RAM_AR_RELEASE_MAJOR_VERSION != SPI_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Major Version"
#endif

#if (SPI_RAM_AR_RELEASE_MINOR_VERSION != SPI_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Minor Version"
#endif

#if (SPI_RAM_AR_RELEASE_REVISION_VERSION != \
                                         SPI_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Revision Version"
#endif


#if (SPI_RAM_SW_MAJOR_VERSION != SPI_RAM_C_SW_MAJOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Software Major Version"
#endif

#if (SPI_RAM_SW_MINOR_VERSION != SPI_RAM_C_SW_MINOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message      : (4:0857) Number of macro definitions exceeds 1024 - program */
/*                does not conform strictly to ISO:C90.                       */
/* Rule         : MISRA-C:2004 Rule 1.1                                       */
/* Justification: The program requires these macro definitions and cannot be  */
/*                avoided.                                                    */
/* Verification : However, part of the code is verified                       */
/*                manually and it is not having any impact                    */
/* Reference    : Look for START Msg(4:0857)-1 and                            */
/*                END Msg(4:0857)-1 tags in the code.                         */
/*******************************************************************************
**                         QAC Warnings                                       **
*******************************************************************************/
/* 2. QAC Warning:                                                            */
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
/* 3. QAC Warning:                                                            */
/* Message       :(2:2022) A tentative definition is being used. Is it        */
/*                 appropriate to include an explicit initializer ?           */
/* Rule          : NA                                                         */
/* Justification : The Global RAM variables are defined in this translation   */
/*                 unit and after initializing it is used in the other files. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-3 and                           */
/*                 END Msg(2:2022)-3 tags in the code.                        */
/******************************************************************************/
/* 4. QAC Warning:                                                            */
/* Message       :(2:3211) Cast between a pointer to volatile object and      */
/*                 an integral type.                                          */
/* Rule          : NA                                                         */
/* Justification : The Global Post Build variables are defined in this        */
/*                 translation unit and is used in the other files.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-4 and                           */
/*                 END Msg(2:3211)-4 tags in the code.                        */
/******************************************************************************/

#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))

/* Global RAM array for current status of SPI Communication for Direct Access */
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
VAR(Spi_CurrentCommData, SPI_NOINIT_DATA)
            Spi_GstCurrentCommData[SPI_MAX_CSIH_HW_INDEX + SPI_ONE];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if (SPI_TX_ONLY_MODE == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global RAM array for current status of SPI Communication for Tx-Only */
VAR(Spi_TxOnlyCurrentCommData, SPI_NOINIT_DATA)
                    Spi_GstTxOnlyCurrentCommData[SPI_MAX_NUM_OF_TX_ONLY_CSIH];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if (SPI_DUAL_BUFFER_MODE == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global RAM array for current status of SPI Communication for Tx-Only */
VAR(Spi_DualBufferCurrentCommData, SPI_NOINIT_DATA)
            Spi_GstDualBufferCurrentCommData[SPI_MAX_NUM_OF_DUAL_BUFFER_CSIH];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if (SPI_FIFO_MODE == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
VAR(volatile Spi_FifoCurrentCommData, SPI_NOINIT_DATA)
                                                     Spi_GstFifoCurrentCommData;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global variable to store the asynchronous transmission mechanism */
VAR(Spi_AsyncModeType, SPI_NOINIT_DATA) Spi_GddAsyncMode;
/* END Msg(2:3211)-4 */
/* END Msg(2:2022)-3 */

/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global variable to store config pointer */
P2CONST(Spi_ConfigType, SPI_VAR, SPI_CONFIG_CONST) Spi_GpConfigPtr;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global variable to store first channel structure */
P2CONST(Spi_ChannelPBConfigType, SPI_VAR, SPI_CONFIG_CONST)
                                                       Spi_GpFirstChannel;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global variable to store first job structure */
P2CONST(Spi_JobConfigType, SPI_VAR, SPI_CONFIG_CONST) Spi_GpFirstJob;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global variable to store first sequence structure */
P2CONST(Spi_SequenceConfigType, SPI_VAR, SPI_CONFIG_CONST) Spi_GpFirstSeq;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global variable to store first sequence structure */
P2CONST(Spi_JobListType, SPI_VAR, SPI_CONFIG_CONST) Spi_GpFirstJobList;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

/* If Internal Diagnosis Error Buffer size is Greater than Zero */
 #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Structure Array to store hardware error details */
VAR(volatile Spi_CommErrorType, SPI_NOINIT_DATA)
                                Spi_GstCommErrorInfo[SPI_MAX_ERROR_BUFFER_SIZE];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Stores the current status of queue */
VAR(volatile boolean, SPI_NOINIT_DATA) Spi_GblQueueStatus[SPI_MAX_QUEUE];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if (SPI_HW_PRIORITY_ENABLED == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
VAR(volatile boolean, SPI_NOINIT_DATA)
                        Spi_GaaHighPriorityCommRequest[SPI_MAX_CSIH_HW_INDEX];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
VAR(volatile boolean, SPI_NOINIT_DATA)
                        Spi_GaaHighPriorityCommActive[SPI_MAX_CSIH_HW_INDEX];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
VAR(volatile boolean, SPI_NOINIT_DATA)
                    Spi_GaaHighPriorityCommRequestAtIdle[SPI_MAX_CSIH_HW_INDEX];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if (SPI_HW_PRIORITY_ENABLED == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
VAR(volatile Spi_SequenceType, SPI_NOINIT_DATA)
                        Spi_GaaHighPrioritySequence[SPI_MAX_CSIH_HW_INDEX];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Stores the index of the queue */
VAR(volatile Spi_JobType, SPI_NOINIT_DATA) Spi_GddQueueIndex[SPI_MAX_QUEUE];
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

#if (SPI_DMA_MODE_ENABLE == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global pointer variable for HW group configuration */
P2CONST(Spi_DmaUnitConfig, SPI_VAR, SPI_CONFIG_CONST)Spi_GpDmaUnitConfig;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif
#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"


#define SPI_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || \
                                            (SPI_LEVEL_DELIVERED == SPI_TWO))
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Status for on-going synchronous transmission */
VAR(boolean, SPI_NOINIT_DATA) Spi_GblSyncTx;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Stores whether new job transmission is initiated */
VAR(volatile boolean, SPI_NOINIT_DATA) Spi_GblInitiateJobTx;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define SPI_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global RAM Variable To Check HWUnit Status of CSIH hardware units*/
VAR(volatile uint8, SPI_NOINIT_DATA) Spi_GucHwUnitStatus;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif
/* If Internal Diagnosis Error Buffer size is Greater than Zero */
#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Index to point the Error Info location next to be filled */
VAR(volatile uint8, SPI_NOINIT_DATA) Spi_GucBufferIndex;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"


#define SPI_START_SEC_VAR_NO_INIT_16
/* MISRA Violation: START Msg(4:0857)-1 */
#include "MemMap.h"
/* END Msg(4:0857)-1 */
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global variable to store the status of all queues */
VAR(volatile uint16, SPI_NOINIT_DATA) Spi_GusAllQueueSts;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */

#if ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_LEVEL_DELIVERED == SPI_ZERO) \
      || (SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) || \
      (SPI_TX_ONLY_MODE == STD_ON))
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
VAR(uint16, SPI_NOINIT_DATA) Spi_GusSynDataAccess;
VAR(volatile uint16, SPI_NOINIT_DATA) Spi_GusAsynDataAccess;

/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
/* START Msg(2:2022)-3 */
/* START Msg(2:3211)-4 */
/* Global RAM Variable To Check HW Unit Status*/
VAR(uint16, SPI_NOINIT_DATA) Spi_GusHwStatus;
/* END Msg(2:2022)-3 */
/* END Msg(2:3211)-4 */
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store the status of SPI Driver */
/* START Msg(2:3211)-4 */
VAR(volatile Spi_StatusType, SPI_INIT_DATA) Spi_GddDriverStatus = SPI_UNINIT;
/* END Msg(2:3211)-4 */
/* START Msg(2:3211)-4 */
VAR(Spi_StatusType, SPI_INIT_DATA) Spi_GddSyncDriverStatus = SPI_UNINIT;
/* END Msg(2:3211)-4 */
/* START Msg(2:3211)-4 */
VAR(volatile uint8, SPI_INIT_DATA) Spi_GucHWFifoBufferSts[SPI_TWO] =
                            {SPI_FIFO_BUFFER_UNINIT, SPI_FIFO_BUFFER_UNINIT};
/* END Msg(2:3211)-4 */
#if (SPI_DMA_MODE_ENABLE == STD_ON)
/* START Msg(2:3211)-4 */
VAR(volatile Spi_DataType, SPI_INIT_DATA) Spi_GddDmaData = SPI_ZERO;
/* END Msg(2:3211)-4 */
#endif

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_VAR_INIT_16
#include "MemMap.h"

#if (SPI_DMA_MODE_ENABLE == STD_ON)
/* START Msg(2:3211)-4 */
VAR(uint16, SPI_INIT_DATA) Spi_GddDmaRxData = SPI_ZERO;
/* END Msg(2:3211)-4 */
#endif

#define SPI_STOP_SEC_VAR_INIT_16
#include "MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
