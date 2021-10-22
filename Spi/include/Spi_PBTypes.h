/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions for post-build time parameters     */
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
 * V1.0.0:  29-Aug-2012  : Initial Version.
 *
 * V1.0.1:  21-Sep-2012  : As per SCR 021,
 *                         1.IMR register mask value changed from
 *                           uint8 to uint16.
 *                         2.Boolean to specify whether the Hardware unit
 *                           is CSIG or CSIH is added in structure
 *                           Spi_JobConfigType
 * V1.0.2:  27-Nov-2012  : As per SCR 042, type declaration for element
 *                         blHwunit_type changed in STag_Spi_JobConfigType
 *                         structure.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 072, following changes are made
 *                         1.Pointer pDefaultData is replaced with variable
 *                           ddDefaultData in STag_Spi_ChannelPBConfigType
 *                           structure
 *                         2.Pre-compile condition SPI_HW_PRIORITY_ENABLED is
 *                           added for structure element blIsHighPriority and
 *                           copyright information is updated.
 *
 * V1.1.1:  13-Jun-2013  : As per SCR 181, SchM_Enter_SPI_##Exclusive_Area()
 *                         is updated to SchM_Enter_Spi_##Exclusive_Area() for
 *                         SPI_AR_VERSION  == SPI_AR_HIGHER_VERSION.
 * V1.2.0:  26-Jul-2013  : As per CR 219, for mantis issue #8821, #1290 and
 *                         #12397 following changes are made:
 *                          1. Pre compile check
 *                             'SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED' is added.
 *
 * V1.2.1:  06-Aug-2013  : As per CR 225, As part of SVN merge activity the
 *                         project name and environment section is updated.
 *
 * v1.2.2:  05-Sep-2013  : As per CR 243 for the mantis issue #8421, the
 *                         following changes are made:
 *                          1. The call back header file is added in include
 *                             section.
 *                          2. The element 'pSpiJobNotification' is added in
 *                             structure 'STag_Spi_JobConfigType'.
 *                          3. The elements 'pSpiSeqEndNotification',
 *                             'pSpiSyncSeqEndNotification' and
 *                             'pSpiSeqStartNotification' are added in structure
 *                             'STag_Spi_SequenceConfigType'.
 *
 * V1.2.3:  23-Oct-2013  : As per CR 256 for the mantis issue #16631, the
 *                         following changes are made:
 *                          1. Pre-compile checks are updated for
 *                             'Spi_GaaChannelIBRead' and
 *                             'Spi_GaaChannelIBWrite'.
 *
 * V1.2.4:  15-Jan-2014  : As per CR 330 for mantis issue #17168, following
 *                         changes are made:
 *                          1. The structure STag_Spi_ChannelPBConfigType is
 *                             updated for 'ucChannelInfo'.
 *                          2. Updated as per C coding guideline.
 *
 * V1.2.5:  05-Feb-2014  : As per CR 398 for the mantis issue #19208,
 *                         Header file updated as part of merge activity.
 *
 * V1.2.6:  02-Jun-2014  : As per CR 507, file is updated as per C coding
 *                         guideline.
 *
 * V1.2.7:  08-Jul-2014  : As per CR 550, for mantis #22328 following changes
 *                         are made:
 *                         1. Pointers 'pDmaIntCntlReg', 'pDmaDTFRRegAddr' and
 *                            'ulTxRxRegAddress' are declared as volatile.
 *                         2. Pre-compile check is added for the structure
 *                            element 'blHWUnitDmaMode' in 'Spi_JobConfigType'
 *                            structure.
 *                         3. Structure STag_Spi_DmaRegs is updated to remove
 *                            usDSCn, usDDCn, usDNSAnL, usDNSAnH and replaced
 *                            with the aaReserved1, aaReserved3, aaReserved4
 *                            aaReserved5, aaReserved6, aaReserved7 and
 *                            aaReserved8.
 *
 * V1.2.8  09-Sep-2014  : As per CR 601, following changes are made:
 *                         1. 'Spi_JobConfigType', 'Spi_ChannelPBConfigType'
 *                            structure is aligned to prevent
 *                            slack bytes.
 *                         2. MISRA C RULE VIOLATION section is added.
 *                         3. MISRA rules violation messages are added.
 *
 * V1.2.9  31-Dec-2014  :  Updated as per mantis #24187:  Error in Critical
 *                           Section Macros during Static Analysis by PC-Lint
 *                           is fixed
 *
 * V1.2.10:   10-Feb-2015 : As a part of Merging Activity, for the mantis#26024
 *                         following changes are made:
 *                         1. As per CR 01, for mantis #19850 AUTOSAR SWS
 *                            requirements are mapped for requirements tracing.
 *                         2. File is updated for C coding guidelines.
 *                         3. Copyright Information is Updated.
 * V1.2.11:   18-Mar-2015 : As part of issue fix for mantis #24305
 *                          Memory mapping of 'Spi_GaaChannelIBRead' and
 *                          'Spi_GaaChannelIBWrite' has been updated.
 * V1.2.12:  19-Nov-2015 : As part of P1x V4.00.05 Release, following changes
 *                         are made:
 *                         1.As per ticket ARDAAAE-1435,
 *                           Renamed the memory section names from
 *                           SPI_START_DATA_LOC_RAM1 and SPI_STOP_DATA_LOC_RAM1
 *                           to SPI_START_SEC_DATA_LOC_RAM1 and
 *                           SPI_STOP_SEC_DATA_LOC_RAM1 according to the
 *                           requirement MEMMAP022.
 *                         2.As part of Jira#ARDAAAE-1558 Metrics improvement,
 *                           Added structure STag_Spi_JobDetails.
 *                         3.STag_Spi_DataFlag structure is created to fix
 *                           testing issues.
 *                         4.Updated names as per coding guidelines.
 * V1.2.13:  07-Feb-2016 : As part of P1x V4.01.00 Release, following changes
 *                         are made:
 *                         1.As per ticket ARDAAAE-1565, Volatile declaration is
 *                           added to Hardware registers.
 *                         2.As per ticket ARDAAAE-1486,storage specifier
 *                           is modified from AUTOMATIC to TYPEDEF for
 *                           Config Data which is allocated in ROM.
 *                         3.Mapping of memory section for global or static
 *                           variables are updated as per AUTOSAR requirement
 *                           MEMMAP022 as per ticket ARDAAAE-1672.
 *                         4.As part of ARDAAAE-1908,removed AR 3.2.2
 *                           related version checks, removed the
 *                           the switch
 *                           #if(SPI_AR_VERSION == SPI_AR_HIGHER_VERSION) and
 *                           removed structure related to DMA_TYPE_ONE.
 *                         5.As part of ARDAAAE-1672, updated INIT policy
 *                           of memory sections from NOINIT to NO_INIT.
 * V1.2.14:  02-Sep-2016 : The following changes are made:
 *                         1.As part of fixing the ticket ARDAAAE-1968,
 *                           added the parameter blCSRIMasked to
 *                           Spi_GstJobConfig structure.
 */
/******************************************************************************/

#ifndef SPI_PBTYPES_H
#define SPI_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
/* Included for Spi type declarations */
#include "Spi_Types.h"
#include "SchM_Spi.h"
#include "Spi_Cbk.h"
#if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Spi.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */

#define SPI_PBTYPES_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_PBTYPES_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                              SPI_AR_RELEASE_REVISION_VERSION


/* File version information */
#define SPI_PBTYPES_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_PBTYPES_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : The macros are used to differentiate the SchM functions    */
/*                 for common Autosar R3.2 and R4.0 implementation.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-1 and                           */
/*                 END Msg(4:3453)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      SchM Critical Section Protection Macros               **
*******************************************************************************/
/* MISRA Violation: START Msg(4:3453)-1 */
#define SPI_ENTER_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Enter_Spi_##Exclusive_Area()

#define SPI_EXIT_CRITICAL_SECTION(Exclusive_Area) \
      SchM_Exit_Spi_##Exclusive_Area()

/* END Msg(4:3453)-1 */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Definition of chip select type */

typedef enum ETagSpi_CSType
{
  SPI_DISABLE_CS = 0,
  SPI_GPIO_CS,
  SPI_PERIPHERAL_ENGINE_CS
} Spi_CSType;


/* Structure for channel configuration */
typedef struct STag_Spi_ChannelPBConfigType
{
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* Default value of the channel */
  Spi_DataType ddDefaultData;
  /* Index of the buffer */
  Spi_NumberOfDataType ddBufferIndex;
  /* Number of IB or maximum size of EB */
  Spi_NumberOfDataType ddNoOfBuffers;
  #else
  /* Index of the buffer */
  Spi_NumberOfDataType ddBufferIndex;
  /* Number of IB or maximum size of EB */
  Spi_NumberOfDataType ddNoOfBuffers;
  /* Default value of the channel */
  Spi_DataType ddDefaultData;
  #endif
  uint8 ucDLSSetting;
  /*
   * Type of the data according to data width; SPI_TYPE_UINT8 for uint8,
   * 1 for SPI_TYPE_UINT16 or 2 for SPI_TYPE_UINT32
   */
  uint8 ucDataType;
  /*
   * Channel buffer type - '0' for IB, '1' for EB, >1 for HW Buffer
   * For values greater than 1, the value is 2 + the index
   * of HW Unit (CSIH) in Spi_HWUnitInfo type structure.CSIG does
   * not have hardware buffers
   */
  uint8 ucChannelBufferType;
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) || \
                                   (SPI_HW_PRIORITY_ENABLED == STD_ON))
  /*
   * Value to check if the channel is last channel in the job (0x01) or
   * last channel (0x02) in the sequence
   */
  uint8 ucChannelInfo;
  /* Value of chip select of the corresponding job */
  uint8 ucCSInfo;
  #endif
  /* Data direction - SPI_TRUE for LSB and SPI_FALSE for MSB */
  boolean blDirection;
  /* Value to check if data length is greater than 16 bits */
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  boolean blEDLEnabled;
  #endif
} Spi_ChannelPBConfigType;

/* Structure for job configuration */
typedef struct STag_Spi_JobConfigType
{
  /* Pointer to list of channels */
  P2CONST(Spi_ChannelType, TYPEDEF, SPI_CONFIG_CONST)pChannelList;
  /* Address of the port group for chip select */
  P2VAR(volatile uint32, TYPEDEF, SPI_CONFIG_DATA)pPortGrpRegAddress;
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Pointer to callback notification */
  P2FUNC(void, SPI_APPL_CODE, pSpiJobNotification)(void);
  #endif
  /* Initialization value for main control register 1 without SLIT */
  uint32 ulMainCtl1Value;
  /* Mask for the port pin */
  uint32 ulPortPinMask;
  /* Value for configuration register (for both CSIG and CSIH) */
  uint32 ulConfigRegValue;
  #if (SPI_FIFO_MODE == STD_ON)
  /* Total number of buffers in the job */
  Spi_NumberOfDataType ddNoOfBuffers;
  #endif
  /* Value for control register 2 */
  uint16 usCtl2Value;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Value for memory Ctrl Register 0 */
  uint16 usMCtl0Value;
  #endif
  /* Number of channels in the list */
  Spi_ChannelType ddNoOfChannels;
  /* Offset of Hardware unit structure */
  Spi_HWUnitType ddHWUnitIndex;

  /*
   * To check if the chip select is using external port pins (GPIO)
   * or using CS_VIA_PERIPHERAL_ENGINE or CS is not at all used
   */
  /* TRACE [R4, SPI239_Conf] */
  Spi_CSType ddCSType;
  /* Loop count for clock to CS */
  uint8 ucClk2CsLoopCnt;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  uint8 ucCSArrayIndex;
  /* Chip Select Index */
  uint8 ucNoOfCS;
  uint8 ucChipSelect;
  #endif
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  uint8 ucTxDmaDeviceIndex;
  uint8 ucRxDmaDeviceIndex;
  #endif
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Job priority */
  uint8 ucJobPriority;
  #endif
  /* Polarity of chip select */
  boolean blCsPolarity;
  /* All Channels properties for CSIH are same*/
  boolean blIsChannelPropSame;
  /*
   * Whether the HW Unit is using  DMA mode (SPI_TRUE) or
   * Normal mode (SPI_FALSE) if DMA is enabled
   */
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  boolean blHWUnitDmaMode;
  #if (SPI_FIFO_MODE == STD_ON)
  boolean blCSRIMasked;
  #endif
  #endif
} Spi_JobConfigType;

/* Structure for sequence configuration */
typedef struct STag_Spi_SequenceConfigType
{
  #if (SPI_LEVEL_DELIVERED != SPI_ZERO)
  /* Pointer to start sequence callback notification */
  P2FUNC(void, SPI_APPL_CODE, pSpiSeqEndNotification)(void);
  #endif
  #if ((SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED == STD_ON) && \
                           ((SPI_LEVEL_DELIVERED == SPI_ZERO) || \
                           (SPI_LEVEL_DELIVERED == SPI_TWO)))
  /* Pointer to start sequence callback notification */
  P2FUNC(void, SPI_APPL_CODE, pSpiSyncSeqEndNotification)(void);
  #endif
  #if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)
  /* Pointer to start sequence callback notification */
  P2FUNC(void, SPI_APPL_CODE, pSpiSeqStartNotification)(void);
  #endif
  /* Number of jobs in the list */
  Spi_JobType ddNoOfJobs;
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) || \
       (SPI_FIFO_MODE == STD_ON))
  /* Total number of buffers in the sequence */
  Spi_NumberOfDataType ddNoOfBuffers;
  #endif
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  Spi_NumberOfDataType ddNxtNotifyIndex;
  #endif
  /* Index of job list of the first job */
  Spi_JobType ddJobListIndex;
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Index of the status byte value (ROM area) */
  uint16 usStsValueStartByteIdx;
  /* Index of the status byte RAM area */
  uint16 usStsCheckByteIdx;
  /* Index of start byte of RAM area from which status has to be updated */
  uint16 usStsUpdateStartByteIdx ;
  #endif
  /* HW Unit details of jobs in the sequence */
  uint16 usHWListIndex;
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Number of status byte value */
  uint8 ucNoOfStsByteValue;
  /* Status byte mask value */
  uint8 ucStsByteMask;
  #endif

  #if ((SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON) && \
       ((SPI_LEVEL_DELIVERED == SPI_ONE) || \
        (SPI_LEVEL_DELIVERED == SPI_TWO)))
  /* Sequence to be interrupted or not */
  boolean blInterruptibleSequence;
  #endif
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  /*
   * Whether the sequence is high priority; If sequence is high priority, the
   * value is SPI_TRUE
   */
  boolean blIsHighPriority;
  #endif
} Spi_SequenceConfigType;

/* Structure for job configuration */
typedef struct STag_Spi_JobListType
{
  /* Job Index */
  Spi_JobType ddJobIndex;
  /* Index of sequence in which the job is configured */
  Spi_SequenceType ddSequenceIndex;
  /* Counter for number of repeated jobs */
  uint8 ucJobCount;
  /* Flag to know if this is last job in the sequence */
  boolean blIsLastJob;
} Spi_JobListType;

/*******************************************************************************
** Structure for DMAC Registers, which are used to read or write              **
** the status or configured values for proper working of the DMAC             **
*******************************************************************************/
#if (SPI_DMA_MODE_ENABLE == STD_ON)
typedef struct STag_Spi_DmaRegs
{
  /* Source Address Register */
  uint32 volatile ulDSAn;
  /* Destination Address Register */
  uint32 volatile ulDDAn;
  /* Transfer Count Register */
  uint32 volatile ulDTCn;
  /* Transfer Control Register */
  uint32 volatile ulDTCTn;
  /* Reload Source Address Register */
  uint32 volatile ulDRSAn;
  /* Reload Destination Address Register */
  uint32 volatile ulDRDAn;
  /* Reload Transfer Count Register */
  uint32 volatile ulDRTCn;
  /* Transfer Count Compare Register */
  uint32 volatile ulDTCCn;
  /* Channel Operation Enable Setting Register */
  uint32 volatile ulDCENn;
  /* Transfer Status Register */
  uint32 volatile ulDCSTn;
  /* Transfer Status Set Register */
  uint32 volatile ulDCSTSn;
  /* Transfer Status Clear Register */
  uint32 volatile ulDCSTCn;
  /* Trigger factor Setting Register */
  uint32 volatile ulDTFRn;
  /* Transfer Request Status Register */
  uint32 volatile ulDTFRRQn;
  /* Transfer Request Clear Register*/
  uint32 volatile ulDTFRRQCn;
} Spi_DmaAddrRegs;
#endif

/* Structure for DMA channel configuration */
#if (SPI_DMA_MODE_ENABLE == STD_ON)
typedef struct STag_Spi_DmaUnitConfig
{
  /* Address for DMA control registers */
  P2VAR(Spi_DmaAddrRegs, TYPEDEF, SPI_CONFIG_DATA)pDmaCntlRegBase;
  /* Address for DMA interrupt control registers */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pDmaImrIntCntlReg;
  /* Clear the Pending interrupts */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pDmaIntCntlReg;
  /* Tx Register address */
  volatile uint32 ulTxRxRegAddress;
  /* DTFR register value */
  uint32 usDmaDtfrRegValue;

  /* Mask for IMR register */
  uint16 usDmaImrMask;
  /* will be 0 if Tx channel, 1 if Rx channel */
  boolean blComDmaChannel;
} Spi_DmaUnitConfig;
#endif

typedef struct STag_Spi_JobDetails
{
  P2CONST(Spi_JobListType, TYPEDEF, SPI_CONFIG_CONST) pReqJobList;
  Spi_JobType ddJobCount;
  Spi_JobType ddCntrForJobsReq;
  Spi_JobType ddLowestQueueIndex;
  Spi_JobType ddReqJobListIndex;
  #if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
  Spi_JobType ddJobListIndex;
  Spi_JobType ddCntrForJobsOnGoing;
  #endif
}Spi_JobDetails;

typedef struct STag_Spi_DataFlag
{
  Spi_DataType ddData;
  Std_ReturnType ddReturnValue;
}Spi_DataAndErrorFlag;
/*******************************************************************************
**                      Global Declarations                                   **
*******************************************************************************/


#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array of Channel structure array */
extern CONST(Spi_ChannelPBConfigType, SPI_CONST) Spi_GstChannelConfig[];

/* Global array of Job structure array */
extern CONST(Spi_JobConfigType, SPI_CONST) Spi_GstJobConfig[];

/* Global array of Sequence structure array */
extern CONST(Spi_SequenceConfigType, SPI_CONST) Spi_GstSeqConfig[];

/* Global array of Channel list */
extern CONST(Spi_ChannelType, SPI_CONST) Spi_GaaChannelList[];

/* Global array of Job list */
extern CONST(Spi_JobListType, SPI_CONST) Spi_GstJobList[];
/* END Msg (4:3684)-1 */

#if (SPI_DMA_MODE_ENABLE == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for DMA unit configuration */
extern CONST(Spi_DmaUnitConfig, SPI_CONST) Spi_GstDmaUnitConfig[];

/* Global array for DMA mapping to the SPI HW Unit instance */
extern CONST(uint8, SPI_CONST) Spi_GaaDmaHwUnitList[];
/* END Msg (4:3684)-1 */
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Sequence status value array */
extern CONST(uint8, SPI_CONST)Spi_GaaSeqStatusValue[];
/* END Msg (4:3684)-1 */
#endif

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array of job notification index */
extern CONST(Spi_NumberOfDataType, SPI_CONST) Spi_GaaNxtNotifyBuffer[];
/* END Msg (4:3684)-1 */
#endif

#if (SPI_CSIH_CONFIGURED == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(uint8, SPI_CONST) Spi_GaaCsIndex[];
/* END Msg (4:3684)-1 */
#endif

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM bit array for status of sequences */
extern VAR(uint8, SPI_NOINIT_DATA) Spi_GaaSeqStatusBitArray[];
/* END Msg (4:3684)-1 */
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && \
    ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) \
                                                  || (SPI_FIFO_MODE == STD_ON)))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for internal read buffer data of channels */
extern VAR(Spi_DataType, SPI_INIT_DATA) Spi_GaaChannelIBRead[];
/* END Msg (4:3684)-1 */
#endif

#if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && \
    ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) \
                                        || (SPI_HW_PRIORITY_ENABLED == STD_ON)))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for internal write buffer data of channels */
extern VAR(Spi_DataType, SPI_INIT_DATA) Spi_GaaChannelIBWrite[];
/* END Msg (4:3684)-1 */
#endif

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* SPI_PBTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
