/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Driver.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2016 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the external declarations of global SPI Driver functions*/
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
 * V1.0.1:  27-Nov-2012  : As per SCR 042, macro SPI_HWUNIT_ASYNCHRONOUS check
 *                         is added.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 072, Extern declaration variable are
 *                         changed APIs Spi_ReceiveISR, Spi_ProcessChannel,
 *                         Spi_TransmitISR.
 * V1.1.1:  18-Mar-2013  : As per SCR 113 for Mantis issue 5420, the following
 *                         change is made:
 *                         Extern declaration of the new function
 *                         Spi_HWInitiateHighPrioCommnTx() is added.
 *
 * V1.1.2:  13-Jun-2013  : As per SCR 181, CSIG_Check is updated to CSIG_Check1
 *                         for SPI_AR_VERSION  == SPI_AR_HIGHER_VERSION.
 *
 * V1.2.0:  26-Jul-2013  : As per CR 219, for mantis issue #8821, #1290 and
 *                         #12397 following changes are made:
 *                          1. 'Spi_HWInitiateTx' is renamed to
 *                             'Spi_InitiateJobTx' and 'LucCommDataIndex'.
 *                          2. Spi_ProcessChannel, Spi_ReceiveISR functions are
 *                             updated.
 *
 * V1.2.1:  06-Aug-2013  : As per CR 225, As part of SVN merge activity the
 *                         project name and environment section is updated.
 *
 * V1.2.2:  23-Oct-2013  : As per CR 256, for the mantis issues #16631 and
 *                         #13117, following changes are made:
 *                         1.All ISR function declaration and definitions
 *                           are modified to SPI_START_SEC_CODE_FAST.
 *
 * V1.2.3:  19-Nov-2013  :  As per CR 321 for the mantis issues #16636, in
 *                          Api Spi_TransmitCancelISR() pre-compile check is
 *                          updated.
 *
 * V1.2.4:  15-Jan-2014  :  As per CR 330, following changes are made:
 *                          1. Updated as per C coding guideline.
 *                          2. Copyright information is updated.
 *
 * V1.2.5:  28-Mar-2014  : As per CR 424 for the mantis issues #19537, following
 *                         changes are made:
 *                         1. Pre-compile check is updated for the following
 *                            APIs: Spi_InitiateJobTx, Spi_ReceiveISR,
 *                            Spi_TransmitISR and Spi_ComErrorISR.
 *
 * V1.2.6:  28-May-2014  : As per CR 507, extern declaration of API
 *                         Spi_LoopBackSelfTest is added under pre-compile
 *                         'SPI_LOOPBACK_SELFTEST' check.
 *
 * V1.2.7: 26-Jun-2014   : As per CR 532, Memory class for the following APIs
 *                         are changed: Spi_HWMainFunction_Handling,
 *                         Spi_HWDisableInterrupts and Spi_HWCancel.
 *
 * V1.2.8: 15-Jul-2014   : As per CR 550, pre-compile checks for extern
 *                         declarations for the following APIs are updated:
 *                         Spi_HWTransmitSyncJob, Spi_InitiateJobTx,
 *                         Spi_ReceiveISR, Spi_ProcessSequence, Spi_ComErrorISR,
 *                         Spi_TransmitISR, Spi_HWMainFunction_Handling,
 *                         Spi_HWActivateCS(), Spi_HWDeActivateCS(),
 *                         Spi_DmaISR() and Spi_TransmitCancelISR().
 *
 * V1.2.9:   10-Feb-2015 : As a part of Merging Activity, for the mantis#26024
 *                         following changes are made:
 *                         1. As per CR 01, for mantis #19850 AUTOSAR SWS
 *                            requirements are mapped for requirements tracing.
 *                         2. Copyright Information is Updated.
 *
 * V1.2.10:  18-Dec-2015 : As part of P1x V4.00.05 Release,
 *                         Following changes are made
 *                         1. As per Jira#ARDAAAE-1514, arguments passing to
 *                            Spi_HWTransmitSyncJob is modified and added
 *                            declarations for Spi_StoreErrorInfo and
 *                            Spi_ReportErrorInSyncTx functions.
 *                         2. As per Jira#ARDAAAE-1533, return type
 *                            Std_ReturnType is added for Spi_LoopBackSelfTest.
 *                         3. As per Jira#ARDAAAE-1533, conditional switches are
 *                            added for the declarations.
 *                         4. As per Jira#ARDAAAE-1558, function declaration
 *                            added for
*                             Spi_SyncProcessData,
 *                            Spi_CsigTxDataAndErrorProcessing,
 *                            Spi_CsihTxDataAndErrorProcessing,
 *                            Spi_GetCsigRxData, Spi_GetCsihRxData,
 *                            Spi_CheckRegEmpty, Spi_CheckErrorInt,
 *                            Spi_GetCurrentRxData and Spi_SyncRegSettings,
 *                            Spi_EccAllZeroTest, Spi_EccAllOneTest,
 *                            Spi_EccWalkOneTest, Spi_EccTwoBitTest,
 *                            SpiStaticInit, Spi_CsigStaticInit,
 *                            Spi_CsihStaticInit, Spi_InitDetCheck,
 *                            Spi_AsyncDetCheck, Spi_ProcessDirectAcessData,
 *                            Spi_ProcessCsigData, Spi_ProcessCsihData,
 *                            Spi_ProcessFifoData, Spi_ProcessDualBufferData
 *                            Spi_CsigLoopBackSelfTest,
 *                            Spi_CsihLoopBackSelfTest,
 *                            Spi_AsyncTransmitInDirectAccessAndFifoMode and
 *                            Spi_SeqJobChannelInit functions.
 *                         5. Spi_CheckRegEmpty, Spi_GetCsihRxData,
 *                            Spi_GetCsigRxData API declarations are updated to
 *                            fix compilation and testing issues.
 *                         6. As part of Metrics improvement, declarations for
 *                            the following functions are added.
 *                            Spi_AsyncChannelRegSettings,
 *                            Spi_ProcessChannelInFifoMod, Spi_FifoWriteData,
 *                            Spi_FifoReadData, Spi_ProcessChannelInDualOrTxMod.
 * V1.2.11:  18-Mar-2016 : As part of P1x V4.01.00 Release, following changes
 *                         are made:
 *                         1. As per ticket ARDAAAE-1593,Updated the function
 *                            definition to avoid the inconsistent memory map
 *                            declaration.
 * V1.2.12:  10-Aug-2016 : As part of P1x V4.01.01 release, following changes
 *                         are made.
 *                         1.Function declarations are added for newly added
 *                           functions.
 *                         2.As part of Write-verify implementation, added APIID
 *                           as argument for the required functions.
 *                         3.Fixed QAC and MISRA warning.
 *                         4.Spi_CfgRegSettings function is made available when
 *                           High priority hardware is enabled as part of ticket
 *                           ARDAAAE-1905.
 *                         5.As part of ARDAAAE-1908,removed AR 3.2.2
 *                           related version checks and removed the switch
 *                           #if(SPI_AR_VERSION == SPI_AR_HIGHER_VERSION)
 */
/******************************************************************************/
#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "Spi_PBTypes.h"
#include "Spi_Ram.h"
#if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Spi.h"
#endif
#include "Dem.h"
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */

#define SPI_DRIVER_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_DRIVER_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_DRIVER_AR_RELEASE_REVISION_VERSION \
                                              SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_DRIVER_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_DRIVER_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWInit(void);
#endif
extern FUNC(void, SPI_PRIVATE_CODE) Spi_SeqJobChannelInit(void);
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_StaticInit(uint8 LucApId);
#else

extern FUNC(void, SPI_PRIVATE_CODE)Spi_SyncRegSettings
         (P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig);
#endif
extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWDeInit(void);

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWWriteIB(Spi_ChannelType Channel,
P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) LpDataBufferPtr,uint8 LucApId);

extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWReadIB(Spi_ChannelType Channel,
           P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) LpDataBufferPtr);
#endif

#if (SPI_IB_CONFIGURED == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_InternalWriteIB(Spi_ChannelType Channel
, P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) LpDataBufferPtr,
  uint8 LucApId);
#endif

#if ((SPI_CSIG_CONFIGURED == STD_ON) || \
     (SPI_CSIH_CONFIGURED == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWActivateCS
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST)
                             LpJobConfiguration, uint8 LucLoopCount);

extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWDeActivateCS
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST)
                                                  LpJobConfiguration);
#endif

#if (SPI_HW_STATUS_API == STD_ON)
extern FUNC(Spi_StatusType, SPI_PRIVATE_CODE) Spi_HWUnitStatus
                                                     (Spi_HWUnitType HWUnit);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))

extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CheckRegEmpty
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo ,
 Std_ReturnType LenReturnValue, uint8 Lucflag);

extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_InitiateSycTransmit
                                                   (Spi_SequenceType Sequence);
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_SetEojAndCsriBits(
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr,
P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST) LpDataAccess,
Spi_NumberOfDataType LddNoOfTxBuffers, Spi_ChannelType LddNoOfChannels);
#else
extern FUNC(void, SPI_PRIVATE_CODE) Spi_SetEojBit(
P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST) LpDataAccess,
Spi_NumberOfDataType LddNoOfTxBuffers, Spi_ChannelType LddNoOfChannels);
#endif
#endif

 #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) || (SPI_EB_CONFIGURED == STD_ON))
 #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
 extern FUNC(P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA), SPI_PRIVATE_CODE)
 Spi_GetCurrentRxData(uint8 LucChannelBufferType,
                                           Spi_NumberOfDataType LddBufferIndex);
 #else
 extern FUNC(P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA), SPI_PRIVATE_CODE)
  Spi_GetCurrentRxData(Spi_NumberOfDataType LddBufferIndex);
 #endif
 #endif

#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_HWTransmitSyncJob
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
                          Spi_SequenceType LddSequenceID, Spi_JobType LddJobID);

extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_SyncProcessData
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
Spi_ChannelType LddNoOfChannels,Spi_SequenceType LddSequenceID,
                                                          Spi_JobType LddJobID);
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CheckErrorInt
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Std_ReturnType LenReturnValue, Spi_SequenceType LddSequenceID,
                                                        Spi_JobType LddJobID);

 #if (SPI_CSIG_CONFIGURED == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsigTxDataAndErrorProcessing
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2, Spi_SequenceType LddSequenceID,
                                                         Spi_JobType LddJobID);
extern FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsigRxData
 (P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
 P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
 P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag,
  Spi_SequenceType LddSequenceID, Spi_JobType LddJobID);
#endif
 #if (SPI_CSIH_CONFIGURED == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsihTxDataAndErrorProcessing
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2, Spi_SequenceType LddSequenceID,
                                                         Spi_JobType LddJobID);
extern FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsihRxData
 (P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
 P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
 P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag,
 Spi_SequenceType LddSequenceID, Spi_JobType LddJobID);

#endif

#else

extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_HWTransmitSyncJob
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig);

extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_SyncProcessData
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
Spi_ChannelType LddNoOfChannels );

extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CheckErrorInt
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Std_ReturnType LenReturnValue);

  #if (SPI_CSIG_CONFIGURED == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsigTxDataAndErrorProcessing
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2);

extern FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsigRxData
 (P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
 P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
 P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag);
#endif
#if (SPI_CSIH_CONFIGURED == STD_ON)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsihTxDataAndErrorProcessing
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2);

extern FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsihRxData
 (P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
 P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
 P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag);

#endif
#endif
#endif

#if (SPI_DMA_MODE_ENABLE == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_TxDmaConfig
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
 P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpTxData,
 Spi_NumberOfDataType LddNoOfBuffers);

extern FUNC(void, SPI_PRIVATE_CODE) Spi_RxDmaConfig
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
 P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpRxData,
 Spi_NumberOfDataType LddNoOfBuffers);

#endif

/* If Internal Diagnosis Error Buffer size is Greater than Zero */
#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* Function to store Hardware Error Details */
extern FUNC(void, SPI_PRIVATE_CODE) Spi_StoreErrorInfo (
         P2CONST(Spi_CommErrorType, AUTOMATIC, SPI_APPL_CONST) LpErrorDetails );
#endif
#if ((SPI_INTERNAL_DIAG_BUFF == STD_ON) &&  \
    ((SPI_LEVEL_DELIVERED == SPI_ZERO) ||   \
     ((SPI_LEVEL_DELIVERED == SPI_TWO) && (SPI_DIRECT_ACCESS_MODE == STD_ON))))
/* Function to report error in Synchronous Transmission*/
extern FUNC(void, SPI_PRIVATE_CODE) Spi_ReportErrorInSyncTx
           ( P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
                          Spi_SequenceType LddSequenceID, Spi_JobType LddJobID);
#endif

/* Internal APIs for enhanced (Synchronous/Asynchronous) SPI Handler/Driver */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
       (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

extern FUNC(void, SPI_PRIVATE_CODE) Spi_InitiateJobTx
                                                 (Spi_JobType LddJobListIndex);

extern FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessSequence
                   (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE)Spi_AsyncInDirAccOrFifoMod
                                                    (Spi_SequenceType Sequence);
extern FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessTransmission
(Spi_SequenceType Sequence, boolean LblInitiateTx, uint8 LucQueueIndex,
uint8 LucHWMemoryMode, Spi_JobType LddLowestQueueIndex);
#endif


#if ((((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) && \
        (SPI_CANCEL_API == STD_ON)) || (SPI_HW_PRIORITY_ENABLED == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWCancel(uint8 LucIndex, uint8 LucApId);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
             (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWMainFunction_Handling(void);

#endif

#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
             (SPI_DUAL_BUFFER_MODE == STD_ON)))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CheckAndInvokeTxIsr
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_TX_ONLY_MODE == STD_ON)))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CheckAndInvokeRxIsr
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);

#endif

#if (SPI_LEVEL_DELIVERED == SPI_TWO)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_HWDisableInterrupts(void);
#endif

#if (SPI_LOOPBACK_SELFTEST == SPI_ONE || SPI_LOOPBACK_SELFTEST == SPI_TWO)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_LoopBackSelfTest(void);

#if (SPI_CSIG_CONFIGURED == STD_ON)
extern FUNC(uint8, SPI_PRIVATE_CODE)Spi_CsigLoopBackSelfTest
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainUserBaseAddr,
P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainOsBaseAddr);
#endif

#if (SPI_CSIH_CONFIGURED == STD_ON)
extern FUNC(uint8, SPI_PRIVATE_CODE)Spi_CsihLoopBackSelfTest
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainUserBaseAddr,
P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainOsBaseAddr);
#endif

#endif

#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_EccSelfTest(void);
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllZeroTest
         (P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr);
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllOneTest
         (P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr);
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccWalkOneTest
         (P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr);
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccTwoBitTest
         (P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr);

#endif
#endif
#if (SPI_DEV_ERROR_DETECT == STD_ON)
extern FUNC(boolean, SPI_PRIVATE_CODE) Spi_InitDetCheck
                 (P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr);
extern FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_AsyncDetCheck
                                                    (Spi_SequenceType Sequence);
#endif

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
     (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

extern FUNC(void, SPI_PRIVATE_CODE) Spi_AsyncChannelRegSettings
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);

#endif

#if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
  ((SPI_HWUNIT_ASYNCHRONOUS == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON))\
                                        || (SPI_FIFO_MODE == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE)Spi_CfgRegSettings(
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
Spi_HWUnitType LddHWUnit);
#endif

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON))|| \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessChannelInDirAccMod
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);

#if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
extern FUNC(void, SPI_PRIVATE_CODE)Spi_GetTxRegValue(
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST)LpDataAccess,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_DataType LddData);
#endif

#endif
#if (SPI_FIFO_MODE == STD_ON)
extern FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessChannelInFifoMod
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

extern FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessChannelInDualOrTxMod
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);

extern FUNC(void, SPI_PRIVATE_CODE)Spi_ProcesSeqInDualOrTxMod(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_CONFIG_CONST) LpHWUnitInfo,
Spi_HWUnitType LddHWUnit);

#if (SPI_CANCEL_API == STD_ON)
extern FUNC(uint8, SPI_PRIVATE_CODE)Spi_ChkCancelReqForSeq(
          Spi_HWUnitType LddHWUnitNumber, Spi_SequenceType LddLowestQueueIndex);
#endif

#endif

#if(SPI_CSIG_CONFIGURED == STD_ON)

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                            (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE) Spi_CsigStaticInit
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr,
uint8 LucApId );
#endif
#endif
#if(SPI_CSIH_CONFIGURED == STD_ON)
#if ((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON) ||\
    ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                      (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
    (SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) || \
                                      (SPI_TX_ONLY_MODE == STD_ON))
extern FUNC(void, SPI_PRIVATE_CODE)Spi_CsihStaticInit
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList,
Spi_JobType LddNoOfJobs, Spi_HWUnitType LddHWUnitNumber, uint8 LucApId );
#endif
#endif
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
      (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON))
extern FUNC(void, SPI_FAST_CODE) Spi_TransmitISR
     (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

#if (((SPI_CANCEL_API == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON)) && \
    ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
extern FUNC(void, SPI_FAST_CODE) Spi_TransmitCancelISR
                 (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_TX_ONLY_MODE == STD_ON))
extern FUNC(void, SPI_FAST_CODE) Spi_ReceiveISR
      (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                    (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
#if (SPI_HW_PRIORITY_ENABLED == STD_ON)
extern FUNC(void, SPI_FAST_CODE)Spi_ReceiveChannelPropSame(
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode,Spi_HWUnitType LddHWUnitNumber);
#else
extern FUNC(void, SPI_FAST_CODE)Spi_ReceiveChannelPropSame(
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

extern FUNC(void, SPI_FAST_CODE)Spi_ProcessDirectAcessData
  (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);

extern FUNC(void, SPI_FAST_CODE)Spi_ReceiveDirectAcessData
                              (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
extern FUNC(void, SPI_FAST_CODE)Spi_ProcessExtendedData
(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2CONST(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData );
#endif
 #if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
extern FUNC(void, SPI_FAST_CODE)Spi_ProcessCsihData(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_DataType LddData);

extern FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsihData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData);
#else
extern FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsihData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData);

extern FUNC(void, SPI_FAST_CODE)Spi_ProcessCsihData(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_DataType LddData);
#endif

#endif
 #if (SPI_CSIG_CONFIGURED == STD_ON)
#if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
extern FUNC(void, SPI_FAST_CODE)Spi_ProcessCsigData(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_DataType LddData);
#endif
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
extern FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsigData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData);
#else
extern FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsigData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData);
#endif

#endif
 #endif

 #if (SPI_DUAL_BUFFER_MODE == STD_ON)
extern FUNC(void, SPI_FAST_CODE)Spi_ProcessDualBufferData
                             (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif

#if (SPI_FIFO_MODE == STD_ON)
 extern FUNC(void, SPI_FAST_CODE)Spi_ProcessFifoData(Spi_HWUnitType LddHWUnit,
                          uint8 LucHWMemoryMode);
extern FUNC(void, SPI_PRIVATE_CODE) Spi_FifoWriteData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList,
  Spi_ChannelType LddNoOfChannels, Spi_NumberOfDataType LddNoOfBuffers,
  P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData);
extern FUNC(void, SPI_FAST_CODE) Spi_FifoReadData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData,
Spi_NumberOfDataType LddNoOfBuffers);
#endif

#if (SPI_DMA_MODE_ENABLE == STD_ON)
extern FUNC(void, SPI_FAST_CODE) Spi_DmaISR(uint8 LucDmaUnit);
#endif

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
       (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
extern FUNC(void, SPI_FAST_CODE) Spi_ComErrorISR
                 (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode);
#endif


#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* SPI_DRIVER_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
