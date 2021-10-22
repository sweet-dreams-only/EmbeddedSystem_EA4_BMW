/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Types.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
 * V1.0.0:  29-Aug-2012  : Initial Version
 *
 * V1.0.1:  19-Oct-2012  : As per SCR 029 macros SPI_NINE and SPI_TEN added
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 072, pre-compile conditions added for
 *                         type definition of Spi_DataType
 *
 * V1.1.1:  20-MAy-2013  : As per SCR 168 for mantis #9319, following change is
 *                         made:
 *                         Macro SPI_THIRTY is added.
 * V1.1.2:  28-Jun-2013  : As per mantis #12518, following change is
 *                         made:
 *                         Macros are added to support DMA channels from
 *                         11 to 15.
 * V1.2.0:  26-Jul-2013  : As per CR 219, for mantis issue #8821, #1290 and
 *                         #12397 following changes are made:
 *                          1. 'SPI_HIGH_DATA_MASK' and 'SPI_LOW_DATA_MASK'
 *                              macros are added.
 *                          2. Pre-compile condition SPI_HW_PRIORITY_ENABLED is
 *                             added for variable aaHighprioirtyJobQueueIndex
 *                          3. New Variables aaHWUnitInfoIndex, aaHWUnitNumber
 *                             are added.
 *
 * V1.2.1:  06-Aug-2013  : As per CR 225, As part of SVN merge activity the
 *                         project name and environment section is updated.
 *
 * V1.2.2:  23-Oct-2013  : As per CR 256, for mantis issue #16631 following
 *                         changes are made:
 *                          1. Pre-compile conditions are updated for
 *                             'pChannelIBRead' and 'pChannelIBWrite'.
 *
 * V1.2.3:  15-Jan-2014  : As per CR 330, following changes are made:
 *                          1. Updated as per C coding guideline.
 *                          2. Copyright is updated.
 *
 * V1.2.4:  05-Feb-2014  : As per CR 398 for the mantis issue #19208,
 *                         Header file updated as part of merge activity.
 *
 * V1.2.5:  28-Mar-2014  : As per CR 424 for the mantis issue #19537, file is
 *                         updated as per C coding guideline.
 *
 * V1.2.6:  26-Aug-2014  : As per CR 601, following changes are made:
 *                         1. Suffix 'U' is added for all scalar values.
 *
 * V1.2.7:   10-Feb-2015 : As a part of Merging Activity, for the mantis#26024
 *                         following changes are made:
 *                         1. As per CR 01, for mantis #19850 AUTOSAR SWS
 *                            requirements are mapped for requirements tracing.
 *                         2. File is updated for C coding guidelines.
 *                         3. Copyright Information is Updated.
 * V1.2.8:   18-Dec-2015 : As part of P1x V4.00.05 Release,
 *                         Following changes are made
 *                          1.As per Jira#ARDAAAE-1533, structures and macros
 *                            required for self test are added.
 *                          2.As per ticket ARDAAAE-1488, Macros are added for
 *                           implementing register write and write-verify check.
 *                          3.As part of software metrics improvement ticket
 *                            ARDAAAE-1558, created macros SPI_TX and SPI_RX.
 * V1.2.9:   18-Mar-2016 : As part of P1x V4.01.00 Release, following changes
 *                         are made:
 *                         1. As per ticket ARDAAAE-1486,storage specifier
 *                            is modified from AUTOMATIC to TYPEDEF for
 *                            Config Data which is allocated in ROM.
 *                         2. Macro definitions are corrected to fix QAC
 *                            warnings.
 * V1.2.10:  24-Oct-2016 : As part of P1x V4.01.01 release, following changes
 *                         are made.
 *                         1.MISRA justifications are added.
 *                         2.As part of Write-verify user interface
 *                           implementation, updated the macros for calling the
 *                           error notification function when
 *                           SPI_USE_WV_ERROR_INTERFACE is ON and also added
 *                           macros for writing in to status clear registers.
 *                         3.Updated macro definitions to fix QAC warnings.
 *                         4.As part of ARDAAAE-1859, added SPI_DMAUNIT_EIGHT
 *                           and SPI_DMAUNIT_NINE macros.
 *                         5.As part of ARDAAAE-1908,removed AR 3.2.2
 *                           related version checks, removed the
 *                           the switch
 *                           #if(SPI_AR_VERSION == SPI_AR_HIGHER_VERSION).
 *                         6.Write verification functionality updated to
 *                           support enumeration parameter as per the ticket
 *                           ARDAAAE-1685.
 *                         7.As part of ARDAAAE-1743,added the macros
 *                           SPI_TX_ONLY_MODE_SET,SPI_DUAL_BUFFER_MODE_SET,
 *                           SPI_CHECK_BUFFER_MODE.
 *                         8.Created file Spi_RegWrite.h to move all the macros
 *                           related to register write functionality.
 *                         9.Changed the type defines of Spi_AsyncModeType,
 *                           Spi_JobResultType and Spi_SeqResultType to
 *                           enumeration.
 *                        10.Updated pre compile switches for the declaration of
 *                           Spi_GaaChannelIBWrite as part of ARDAAAE-2073.
 * V1.2.11:  15-Feb-2017 : Following changes are made:
 *                         1. As part of ARDAAAE-2277,'U' is appended at
 *                            relevant places.
 *                         2. Copyright information updated.
 */
/******************************************************************************/
#ifndef SPI_TYPES_H
#define SPI_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Included for pre-compile options */
#include "Spi_Cfg.h"

/* AUTOSAR standard types */
#include "Std_Types.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

/* AUTOSAR Release version information */
#define SPI_TYPES_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_TYPES_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_TYPES_AR_RELEASE_REVISION_VERSION \
                                            SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_TYPES_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_TYPES_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define SPI_ZERO                      0x00U
#define SPI_ONE                       0x01U
#define SPI_TWO                       0x02U
#define SPI_THREE                     0x03U
#define SPI_FOUR                      0x04U
#define SPI_FIVE                      0x05U
#define SPI_SIX                       0x06U
#define SPI_SEVEN                     0x07U
#define SPI_EIGHT                     0x08U
#define SPI_NINE                      0x09U
#define SPI_TEN                       0x0AU
#define SPI_ELEVEN                    0x0BU
#define SPI_TWELVE                    0x0CU
#define SPI_THIRTEEN                  0x0DU
#define SPI_FOURTEEN                  0x0EU
#define SPI_FIFTEEN                   0x0FU
#define SPI_SIXTEEN                   0x10U
#define SPI_THIRTY                    0x1EU
#define SPI_THIRTYTWO                 0x20U

#define SPI_ADDRESS_OFFSET_ONE        0X01U
#define SPI_ADDRESS_OFFSET_TWO        0X02U
#define SPI_ADDRESS_OFFSET_SEVEN      0X07U
#define SPI_ADDRESS_OFFSET_THREE      0X03U

#define SPI_DMAUNIT_ZERO                      0x00U
#define SPI_DMAUNIT_ONE                       0x01U
#define SPI_DMAUNIT_TWO                       0x02U
#define SPI_DMAUNIT_THREE                     0x03U
#define SPI_DMAUNIT_FOUR                      0x04U
#define SPI_DMAUNIT_FIVE                      0x05U
#define SPI_DMAUNIT_SIX                       0x06U
#define SPI_DMAUNIT_SEVEN                     0x07U
#define SPI_DMAUNIT_EIGHT                     0x08U
#define SPI_DMAUNIT_NINE                      0x09U
#define SPI_DMAUNIT_TEN                       0x0AU
#define SPI_DMAUNIT_ELEVEN                    0x0BU
#define SPI_DMAUNIT_TWELVE                    0x0CU
#define SPI_DMAUNIT_THIRTEEN                  0x0DU
#define SPI_DMAUNIT_FOURTEEN                  0x0EU
#define SPI_DMAUNIT_FIFTEEN                   0x0FU

#define SPI_TRUE                      (uint8)0x01U
#define SPI_FALSE                     (uint8)0x00U

#define SPI_HIGH_DATA_MASK            0xFFFF0000UL
#define SPI_LOW_DATA_MASK             0x0000FFFFUL

#define SPI_DMA_TYPE_ONE              0x01U
#define SPI_DMA_TYPE_TWO              0x02U

#define SPI_TX          (uint8)0X00U
#define SPI_RX          (uint8)0X01U

#define SPI_TX_ONLY_MODE_SET          0x200U
#define SPI_DUAL_BUFFER_MODE_SET      0x100U
#define SPI_CHECK_BUFFER_MODE         0x300U


/*******************************************************************************
**                      SPI TYPE DEFINITION                                   **
*******************************************************************************/

/* Definition of status type */
typedef enum ETagSpi_StatusType
{
  SPI_UNINIT = 0,
  SPI_IDLE,
  SPI_BUSY
} Spi_StatusType;

#if (SPI_SELF_TEST_API == STD_ON)
/* Declaration of Self test return types */
typedef enum ETagSpi_ReturnStatus
{
  SPI_SELFTEST_INVALID_MODE = 0,
  SPI_SELFTEST_DRIVERBUSY,
  SPI_SELFTEST_PASS,
  SPI_SELFTEST_FAILED
} Spi_ReturnStatus;
#endif
/* Definition of Job Result type */

typedef enum ETagSpi_JobResultType
{
  SPI_JOB_OK = 0,
  SPI_JOB_PENDING,
  SPI_JOB_FAILED ,
  SPI_JOB_QUEUED
} Spi_JobResultType;

/* Definition of Sequence Result type */
typedef enum ETagSpi_SeqResultType
{
  SPI_SEQ_OK = 0,
  SPI_SEQ_PENDING,
  SPI_SEQ_FAILED,
  SPI_SEQ_CANCELLED
} Spi_SeqResultType;

/* Definition of type for asynchronous mode */
typedef enum ETagSpi_AsyncModeType
{
  SPI_POLLING_MODE = 0,
  SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

/* Definition of type for application data buffer elements */
#if (SPI_8BIT_DATA_WIDTH == STD_ON)
typedef uint8 Spi_DataType;
#elif (SPI_16BIT_DATA_WIDTH == STD_ON)
typedef uint16 Spi_DataType;
#else
typedef uint32 Spi_DataType;
#endif

/* Definition of type for number of data elements */
typedef uint16 Spi_NumberOfDataType;

/* Definition of type for channel ID */
typedef uint8 Spi_ChannelType;

/* Definition of type for job ID */
typedef uint16 Spi_JobType;

/* Definition of type for sequence ID */
typedef uint8 Spi_SequenceType;

/* Definition of type for hardware unit ID */
typedef uint8 Spi_HWUnitType;

/* Definition of type for self test */
typedef uint8 Spi_SelfTestType;
/*******************************************************************************
**                      Structure declarations                                **
*******************************************************************************/

/* Data Structure for SPI Handler/Driver initialization */
typedef struct STag_Spi_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Pointer to first Channel configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_CONST) pFirstChannel;
  /* Pointer to first Job configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_CONST) pFirstJob;
  /* Pointer to first Sequence configuration */
  P2CONST(void, TYPEDEF, SPI_CONFIG_CONST) pFirstSeq;
  /* Pointer to the job list array */
  P2CONST(void, TYPEDEF, SPI_CONFIG_CONST) pJobList;
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  /* Pointer to the structure of DMA configuration array */
  P2CONST(void, TYPEDEF, SPI_CONFIG_DATA) pDMAConfiguration;
  /* Pointer to DMA to SPI Hardware Unit mapping array */
  P2CONST(uint8, TYPEDEF, SPI_CONFIG_DATA) pDmaSpiHWUnitMap;
  #endif
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  /* Pointer to job notify index */
  P2CONST(Spi_NumberOfDataType, TYPEDEF, SPI_CONFIG_DATA) pJobNotifyIndex;
  #endif
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Pointer to the status array */
  P2VAR(uint8, TYPEDEF, SPI_CONFIG_DATA) pStatusArray;
  /* Pointer to the status byte value */
  P2CONST(uint8, TYPEDEF, SPI_CONFIG_CONST) pStsValueArray;
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Pointer to the chipselect array */
  P2CONST(uint8, TYPEDEF, SPI_CONFIG_DATA) pCSArray;
  #endif
  #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && ((SPI_FIFO_MODE == STD_ON) || \
        (SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) || \
          (SPI_LEVEL_DELIVERED == SPI_ZERO)))
  /* Pointer to the internal Read buffer  */
  P2VAR(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA) pChannelIBRead;
  #endif
  #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && ((SPI_FIFO_MODE == STD_ON) || \
            (SPI_DIRECT_ACCESS_MODE == STD_ON)  || \
                               (SPI_TX_ONLY_MODE == STD_ON) || \
                                           (SPI_LEVEL_DELIVERED == SPI_ZERO)))
  /* Pointer to the internal Write buffer  */
  P2VAR(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA) pChannelIBWrite;
  #endif
  #if ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON))
  Spi_JobType ddDirectAccessQueueSize;
  #endif
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  /*
   * Hardware unit queue index of CSIH HW units with Tx-only or DB mode
   * If CSIG/Direct access/FIFO mode/Not used, Value = 0xFF
   */
  Spi_SequenceType aaHWUnitQueueIndex[SPI_MAX_HW_DETAILS];
  /*
   * Data structure index of CSIH HW units with Tx-only or DB mode
   * If CSIG/Direct access/FIFO mode/Not used, Value = 0xFF
   */
  Spi_HWUnitType aaHWUnitCurrentCommDataIndex[SPI_MAX_HW_DETAILS];
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  /*
   * High priority job queue index of CSIH HW units
   * If Direct access/FIFO mode/Not used, Value = 0xFF
   */
  Spi_JobType aaHighprioirtyJobQueueIndex[SPI_MAX_CSIH_HW_INDEX];
  #endif
  #endif
  #if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_ZERO))
  /* Configured memory mode for all CSIH HW units */
  uint8 aaHWMemoryMode[SPI_MAX_CSIH_HW_INDEX];
  /*
   * The index of HW Unit (CSIH) in Spi_HWUnitInfo type structure
   * Value = 0xFF, if particular CSIH hardware unit is not used
   */
  Spi_HWUnitType aaHWUnitInfoIndex[SPI_MAX_CSIH_HW_INDEX];
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /*
   * Hardware unit number info. If CSIG, value = 0xFF
   * For CSIH0 = 0, CSIH1 = 1, ....
   */
  Spi_HWUnitType aaHWUnitNumber[SPI_MAX_HW_DETAILS];
  /* Configured chip select for all CSIH HW units */
  uint8 aaChipSelect[SPI_MAX_CSIH_HW_INDEX];
  #endif
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Number of status bytes */
  uint8 ucNoofStatusByte;
  #endif
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  /* Max number of DMA channel Ids configured in corresponding configuration */
  uint8 ucMaxDmaChannels;
  #endif
} Spi_ConfigType;


#endif /* SPI_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
