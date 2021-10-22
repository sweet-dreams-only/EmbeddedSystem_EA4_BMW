/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_Driver.c                                                */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function definitions of the SPI        */
/* Driver                                                                     */
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
 * V1.0.1:  1-Oct-2012  : As per SCR 021, Following changes are made
 *                        1.Variables ucRxImrMask, ucTxImrMask, ucErrorImrMask,
 *                          ucTxCancelImrMask, ucDmaImrMask, changed to
 *                          usRxImrMask, usTxImrMask, usErrorImrMask,
 *                          usTxCancelImrMask and usDmaImrMask.
 *
 *                        2.Data type of LpIntCntlAddress is changed to uint16.
 *                        3.Pre-compile options are changed in APIs
 *                          Spi_HWDeInit, Spi_InternalWriteIB, Spi_HWActivateCS,
 *                          Spi_HWDeActivateCS, Spi_ProcessSequence.
 *
 *                        4.Typecasting for the pointers LpChannelIB32Bit.
 *                          LpChannelIB16Bit in API Spi_InternalWriteIB is
 *                          changed.
 *
 *                        5.Typecasting for the pointers LpReadPtr32Bit,
 *                          LpReadPtr16Bit in API Spi_HWTransmitSyncJob is
 *                          changed.
 *
 * V1.0.2   19-Oct-2012  : As per SCR 029, following changes are made:
 *                         1.MISRA C RULE VIOLATION(4:0277) is added.
 *                         2.Comments are updated.
 *                         3.Spi_ComErrorISR API data
 *                           consistency, parity, overflow and overrun bit
 *                           settings are changed.
 *
 *                         4.Check for whether hardware unit is CSIH before
 *                           updating Pre-scalar and baud rate is added.
 *                         5.Macro SPI_RELOC_INTR_VECT_MASK added
 *                           for relocating interrupt vector table.
 *
 * V1.0.3   27-Nov-2012  : As per SCR 042, following changes are made:
 *                         1. MISRA C RULE VIOLATION section updated.
 *                         2. MISRA rules violation messages are updated.
 *                         3. Macro SPI_HWUNIT_ASYNCHRONOUS check added.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 072, the following changes are made
 *                         1. APIs Spi_HWInit, Spi_HWInitiateTx,
 *                            Spi_ProcessSequence, Spi_TxDmaConfig, Spi_DmaISR
 *                            are updated for Hardware priority handling
 *                            functionality.
 *                         3. Type casting of Spi_DataType is removed in APIs
 *                            Spi_InternalWriteIB, Spi_HWWriteIB, Spi_HWReadIB,
 *                            Spi_HWTransmitSyncJob, Spi_ProcessChannel,
 *                            Spi_TransmitISR and Spi_ReceiveISR for byte
 *                            alignment implementation.
 *                         4. Copyright information is updated.
 *
 * V1.1.1:  18-Mar-2013  : As per SCR 113 for Mantis issue 5420, the following
 *                         changes are made
 *                         1. Spi_InternalWriteIB() - The internal buffers are
 *                            updated when SPI_HW_PRIORITY_ENABLED is ON as the
 *                            high priority communication works with direct
 *                            access memory mode.
 *                         2. Spi_ProcessChannel() - Take data from the internal
 *                            buffer when high priority sequence is getting
 *                            transmitted.
 *                         3. Spi_ProcessChannel() and Spi_ProcessSequence() -
 *                            Do not update ucMainCTL0 register when the high
 *                            priority communication is under progress.
 *                         4. Spi_ProcessChannel() and Spi_TransmitISR()
 *                            EOJ bit is set only for the last job of the
 *                            sequence which is high priority.
 *                         5. Spi_DmaISR: Spi_ProcessSequence() is called when
 *                            all the transmission of all the channels of the
 *                            current job is completed.
 *                         6. Spi_HWMainFunction_Handling() - LddHWUnit is
 *                            initialised based on the configured H/W units.
 *                         7. New function Spi_HWInitiateHighPrioCommnTx() is
 *                            added to initiate communication of the high
 *                            priority sequence.
 *
 * V1.1.2:  20-May-2013  : As Per SCR 168 for the mantis issue #9319 and #11575,
 *                         following changes are made:
 *                         1.For CSIH, accessing baud rate register usCSIHBRS
 *                           is updated in Api Spi_HWTransmitSyncJob() and
 *                           Spi_HWInitiateTx().
 *                         2.Tx interrupt is enabled when SPI_DMA_MODE_ENABLE is
 *                           STD_ON in Api Spi_ProcessChannel() and the function
 *                           Spi_ProcessSequence() is called when DmaChannel of
 *                           DMA configuration is SPI_ONE in Api Spi_DmaISR().
 *                         3.HW Unit checking is added for CSIH configuration
 *                           register update in Api Spi_HWInitiateTx().
 *
 * V1.1.3:  13-Jun-2013  : As per SCR 181, following changes are made:
 *                         1.For SPI_FIFO_MODE, SPI_DMA_MODE_ENABLE pre-compile
 *                           check is added to clear the interrupts in
 *                           Api Spi_ProcessChannel().
 *                         2.In API Spi_HWActivateCS() CSIG_Check is updated
 *                           to CSIG_Check1
 *                           for SPI_AR_VERSION == SPI_AR_HIGHER_VERSION
 *                         3.In API Spi_HWDeActivateCS() CSIG_Check  is updated
 *                           to CSIG_Check 2
 *                           for SPI_AR_VERSION == SPI_AR_HIGHER_VERSION
 *
 * V1.2.0:  26-Jul-2013  : As per CR 219, for mantis issue #8821, #1290 and
 *                         #12397 all APIs are updated.
 *
 * V1.2.1:  06-Aug-2013  : As per CR 225, Following changes are made:
 *                         1. As part of SVN merge activity the project name and
 *                            environment section is updated.
 *                         2. API Spi_HWTransmitSyncJob() is updated to support
 *                            memory mode.
 *
 * V1.2.2:  03-Sep-2013  : As per CR 243 for the mantis issues #8421 and #12110,
 *                         the following changes are made:
 *                         1. Exit mechanism is added for all hardware while
 *                            loop in Api Spi_HWTransmitSyncJob().
 *                         2. Job end notification functionality section is
 *                            updated in Api Spi_TransmitISR() and Api
 *                            Spi_ReceiveISR().
 *                         3. Job end notification, Sequence end notification
 *                            and Start sequence notification functionalities
 *                            are updated in Api Spi_ProcessSequence().
 *
 * V1.2.3:  23-Oct-2013  : As per CR 256 for the mantis issues #16631, #14088
 *                         and #13117, following changes are made:
 *                         1. In Api Spi_ProcessSequence() pre-compile check is
 *                         added for High Priority functionality and
 *                         also pre-Compile check for LpJobConfig is modified.
 *                         2. All ISR function declaration and definitions
 *                            are modified to SPI_START_SEC_CODE_FAST.
 *
 * V1.2.4:  19-Nov-2013  : As per CR 321 for the mantis issues #16636, in
 *                         Api Spi_TransmitCancelISR() pre-compile check is
 *                         updated.
 *
 * V1.3.0:  15-Jan-2014  : As per CR 330 for the mantis issues #9799, #12397
 *                         1. APIs Spi_TransmitISR() and Spi_ReceiveISR() are
 *                            updated as per 'SLIT' functionality.
 *                         2. API Spi_HWTransmitSyncJob() is updated to support
 *                            'SLIT' functionality.
 *                         3. APIs Spi_TransmitCancelISR(), Spi_ProcessSequence,
 *                            and Spi_HWMainFunction_Handling are updated.
 *                         4. Copyright information is updated.
 *                         5. MISRA C RULE VIOLATION section updated.
 *                         6. MISRA rules violation messages are updated.
 *                         7. Updated as per C coding guideline.
 *
 * V1.3.1:  04-Feb-2014  : As per CR 398 for the mantis issue #19208,
 *                         Source file updated as part of merge activity.
 *
 * V1.3.2:  21-Mar-2014  : As per CR 424 for the mantis issue #19537 and #18651
 *                         following changes are made:
 *                         1. Function headers are updated for Global Variable
 *                            in the following APIs: Spi_HWWriteIB,
 *                            Spi_HWReadIB, Spi_HWUnitStatus,
 *                            Spi_HWTransmitSyncJob, Spi_InitiateJobTx,
 *                            Spi_ProcessChannel, Spi_TransmitISR,
 *                            Spi_TransmitCancelISR, Spi_ReceiveISR,
 *                            Spi_ProcessSequence, Spi_RxDmaConfig,
 *                            Spi_HWMainFunction_Handling and Spi_ComErrorISR.
 *                         2. In API Spi_ProcessSequence critical section
 *                            protection is updated.
 *                         3. In the APIs Spi_ProcessChannel, Spi_TxDmaConfig,
 *                            Spi_RxDmaConfig and Spi_HWCancel, access to
 *                            ICxxx.TBxxx bit of interrupt control register is
 *                            removed.
 *                         4. Pre-compile check is updated for the following
 *                            APIs: Spi_InitiateJobTx, Spi_ReceiveISR,
 *                            Spi_TransmitISR and Spi_ComErrorISR.
 *
 * V1.3.3:  28-Mar-2014  : As per CR 446 for the mantis issue #19104 and #19635,
 *                         following changes are made:
 *                         1. In API 'Spi_HWTransmitSyncJob' software delay is
 *                            added to wait till Chip Select becomes IDLE.
 *                         2. In API 'Spi_InitiateJobTx', critical section
 *                            protection is updated.
 *                         3. Updated as per C coding guideline.
 *
 * V1.3.4: 15-Apr-2014   : As per CR 486 for mantis #19635, software delay to
 *                         wait till Chip Select becomes "IDLE" is removed from
 *                         API "Spi_HWTransmitSyncJob'.
 *
 * V1.3.5: 28-Apr-2014   : As per CR 498 following changes are made:
 *                          1. For mantis #20999 and #21004, API
 *                             Spi_HWTransmitSyncJob() is updated.
 *                          2. Macros RH850_SV_MODE_ICR_AND,
 *                             RH850_SV_MODE_IMR_OR and RH850_SV_MODE_IMR_AND
 *                             are added to write enable/clear registers IMR &
 *                             ICxxx as part of OS merge activity.
 *
 * V1.3.6:  02-Jun-2014  : As per CR 507, following changes are made:
 *                         1. API Spi_LoopBackSelfTest() is added for data
 *                            transmission self test using loop back mode.
 *                         2. For mantis #9799, API Spi_HWTransmitSyncJob()
 *                            is updated to reset 'PWR' bit on job completion.
 *                         3. Exit loop condition is updated to avoid resulting
 *                            of infinite loop.
 *                         4. Description for the following APIs:
 *                            Spi_TransmitISR, Spi_TransmitCancelISR and
 *                            Spi_ReceiveISR are updated.
 *                         5. The macros 'SPI_SELCSIHDMA_ADDR' and
 *                            'SPI_SELCSIHDMA_REG_VAL' are renamed to
 *                             'SPI_SELECT_CSIH_DMA_ADDR' and
 *                             'SPI_SELECT_CSIH_DMA_REG_VAL' respectively.
 *                         6. The variable 'Spi_GucAllQueueSts' is renamed to
 *                            'Spi_GusAllQueueSts' as per C coding guideline.
 *                         7. MISRA C RULE VIOLATION section updated.
 *                         8. MISRA rules violation messages are updated.
 *
 * V1.3.7: 17-Jun-2014   : As per CR 532 for mantis #16991, following changes
 *                         are made:
 *                          1. Spi_ProcessChannel API updated to use "syncp"
 *                             command for access to ICxxx register.
 *                          2. Spi_TxDmaConfig API updated to use "syncp"
 *                             command for access to ICxxx register.
 *                          3. Spi_RxDmaConfig API updated to use "syncp"
 *                             command for access to ICxxx register.
 *                          4. Spi_HWCancel API updated to use "syncp"
 *                             command for access to ICxxx register.
 *                          5. Updated as per C coding guideline.
 *                          6. Memory class for the following APIs are changed
 *                             Spi_HWMainFunction_Handling,
 *                             Spi_HWDisableInterrupts and Spi_HWCancel.
 *
 * V1.3.8: 08-Jul-2014   : As per CR 550 for mantis #22312, #22324, #22213,
 *                         #21502, #22328, #21877, #22212 and #22066 following
 *                         changes are made:
 *                         1. The volatile qualifier is added for pointers
 *                            LpIntCntlAddress and LpDmaTrigFactor.
 *                         2. New macros 'SPI_CSIG_CLR_STS_FLAGS' and
 *                            'SPI_CSIH_CLR_STS_FLAGS' are added to clear status
 *                            registers for CSIG and CISH individually.
 *                         3. Pre-compile check is updated for the following
 *                            APIs: Spi_HWTransmitSyncJob(), Spi_InitiateJobTx()
 *                            Spi_ProcessChannel(), Spi_TransmitISR(),
 *                            Spi_ReceiveISR(), Spi_ProcessSequence(),
 *                            Spi_HWMainFunction_Handling(), Spi_ComErrorISR()
 *                            and Spi_HWReadIB().
 *                         4. Function headers are updated.
 *                         5. Api Spi_LoopBackSelfTest() is updated to perform
 *                            self-test in Direct Access Mode.
 *
 * V1.3.9: 01-Aug-2014   : As per CR 581 for mantis #20712 and #22858, following
 *                         changes are made:
 *                         1. File is updated after spell check.
 *                         2. APIs Spi_RxDmaConfig and Spi_TxDmaConfig are
 *                            updated for declaration of local variable
 *                            "LulDTCTVal".
 *
 * V1.4.0: 24-Aug-2014   : As per CR601 for mantis #21639, #22289 and #22862
 *                         following changes are made:
 *                         1. API Spi_ProcessChannel() is updated for the
 *                            sequence of invoking Spi_RxDmaConfig prior to
 *                            Spi_TxDmaConfig.
 *                         2. API Spi_ProcessChannel() is updated to support
 *                            transmission of more than 128 words in FIFO mode.
 *                         3. API Spi_ProcessSequence(), is updated to reset
 *                            'Spi_GucHWFifoBufferSts' to 'UNINT' before
 *                            transmission of new job starts in FIFO mode.
 *                         4. API Spi_DmaISR(), is updated as per the structure
 *                            'Spi_FifoCurrentCommData' to have separate RX and
 *                            TX pointers.
 *                         5. Spi_TransmitISR() is updated to load the value of
 *                            "ucChipSelect" to Tx0W register for every 16 bit
 *                            transmission in case extended data is transferred.
 *                         6. MISRA C RULE VIOLATION section is updated.
 *                         7. MISRA rules violation messages are updated.
 *
 * V1.4.1: 05-Jan-2015   : Following changes are made
 *                         1. As per mantis #25126 Wrong condition check,
 *                            (SPI_ZERO < LddNoOfChannels) of the do while loop
                              in Spi_HWTransmitSyncJob API is removed.
 *                         2. As per mantis #25111 definition for
 *                            SPI_CHIP_SELECT_PROTECTION and
 *                            SPI_RAM_DATA_PROTECTION are added
 *                         3. As per mantis #25251 critical section is added.
 *                         4. As per mantis #25047 unreachable code removed from
 *                            Spi_ReceiveISR function.
 *                         5. MISRA warning message (4:3138) is added.
 *                         6. Copyright information is updated
 *                         7. As per mantis #22981 LpJobConfig is initialised.
 *                         8. As per mantis #25333, DTCT register is loaded
 *                            with SPI_DMA_32BIT_RX_SETTINGS and
 *                            SPI_DMA_32BIT_TX_SETTINGS for Spidatawidth 32 bit
 *
 * V1.4.2:  10-Feb-2015  : As a part of Merging Activity, for the mantis#26024
 *                         following changes are made:
 *                         1. As per CR 01, for mantis #19850 AUTOSAR SWS
 *                            requirements are mapped for requirements tracing.
 *                         2. File is updated for C coding guidelines.
 *                         3. As per CR 01, for mantis #14360 API
 *                            Spi_HWTransmitSyncJob() is updated to perform
 *                            shift operation for received data before saving
 *                            the data to software buffer when 'blDirection' is
 *                            false.
 *                         4. As per CR 01, for mantis #14360 API Spi_HWReadIB()
 *                            is updated to perform shift operation for received
 *                            data before saving it into software buffer when
 *                            'blDirection' is false.
 * V1.4.3:  18-Mar-2015  : As part of issue fix for mantis #24305
 *                         SPI_SELCSIHDMA_ENABLED check has been added in
 *                         Spi_HWInit function to isolate
 *                         SPI_SELECT_CSIH_DMA_ADDR access to P1x devices only.
 *
 * V1.4.4:  07-May-2015  : Following changes are made
 *                         1. As per mantis #27771, Spi_ReceiveISR API is
 *                            updated to remove compilation warning.
 *                         2. As per mantis #27772, Spi_HwInit API is updated
 *                            for 32 bit DMA settings.
 *
 * V1.4.5:  18-Dec-2015  : As a part of the issue fixing P1x V4.00.05 release,
 *                         Following changes are made
 *                         1.As per Jira#ARDAAAE-1478, Spi_HWTransmitSyncJob,
 *                           Spi_ProcessChannel, Spi_HWDisableInterrupts,.
 *                           Spi_HWMainFunction_Handling and Spi_ComErrorISR
 *                           API's are modified to report Dem Error, in case of
 *                           a Hardware Error is occurred.
 *                         2.As per ticket ARDAAAE-1440, Chip select activation
 *                           for CSIG is moved from 'Spi_InitiateJobTx' function
 *                           to 'Spi_ProcessChannel' function.
 *                         3.As per ticket ARDAAAE-1228, Return value is updated
 *                           to E_NOT_OK in case if DEM error is reported and
 *                           check for LblDemReported is added to break the
 *                           do-while loop in Spi_HWTransmitSyncJob() API.
 *                         4.As per ticket ARDAAAE-1064, compiler check
 *                           SPI_PERSISTENT_HW_CONFIGURATION_ENABLED = STD_OFF
 *                           is added to RESET the power bit of ucMainCTL0
 *                           register in Spi_HWTransmitSyncJob() API.
 *                         5.As per ticket ARDAAAE-1176, the illegal memory
 *                           access of the pointer 'LpPBChannelConfig' is
 *                           corrected by initialising it before the if
 *                           condition inside the API's Spi_TransmitISR() and
 *                           Spi_ProcessChannel().
 *                         6.As per ticket ARDAAAE-1179,the
 *                           initialisation of the local pointer LpJobConfig
 *                           in the API Spi_TransmitISR is done inside
 *                           the switch #if (SPI_FIFO_MODE == STD_ON) before
 *                           the condition if (SPI_FIFO_BUFFER_UNINIT ==
 *                           Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX]).
 *                         7.As per ticket ARDAAAE-1503,Index for accessing
 *                           Spi_GaaSeqQueue is corrected to Spi_GddQueueIndex
 *                           [LddHWUnitNumber + SPI_TWO] in
 *                           Spi_TransmitCancelISR and Spi_ComErrorISR functions
 *                         8.As per ticket ARDAAAE-1515, CSIH Baudrate registers
 *                           are made accessed in 16bits instead of 32bit.
 *                         9.As per Jira#ARDAAAE-1478, Removed STR Register
 *                            check from Spi_HWTransmitSyncJob, since this
 *                            functionality is already taken care in
 *                            Error Flag checking.
 *                         10.As per Jira#ARDAAAE-1514, Spi_StoreErrorInfo and
 *                            Spi_ReportErrorInSyncTx is added and
 *                            Spi_ComErrorISR is modified for internal Diagnosis
 *                            Implementation.
 *                         11.As per Jira#ARDAAAE-1514, Spi_HWTransmitSyncJob is
 *                            modified for internal diagnosis implementation.
 *                         12.As per ticket ARDAAAE-1452, DMA settings for 8 bit
 *                            and 32 bit are removed.
 *                         13.As per Jira#ARDAAAE-1533, return type
 *                            Std_ReturnType is added for Spi_LoopBackSelfTest.
 *                         14.As per Jira#ARDAAAE-1533, Spi_EccSelfTest function
 *                            is added.
 *                         15.As per Jira#ARDAAAE-1478, the declaration and
 *                            definition of LpMainUserBaseAddr is moved under
 *                            the pre compile switch
 *                            SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == OFF.
 *                         16.As per Jira#ARDAAAE-1350, Spi_HWTransmitSyncJob is
 *                            updated to make the settings of CSIHnCTL1.CSRI bit
 *                            based on the user configuration and resetting the
 *                            PWR bit at the end of transmission is removed.
 *                         17.As per ticket ARDAAAE-1488, Write-Verify
 *                           functionality check is added for all the registers.
 *                         18.As per Jira#ARDAAAE-1514, Spi_ReportErrorInSyncTx
 *                            function is updated for clearing the error flags
 *                            after an error is reported.
 *                         19.As per Jira#ARDAAAE-1558 Software metrics
 *                            improvement, following changes are made:
 *                            1.Spi_HwTransmitSyncJob function is split in to
 *                              Spi_SyncProcessData,
 *                              Spi_CsigTxDataAndErrorProcessing,
 *                              Spi_CsihTxDataAndErrorProcessing,
 *                              Spi_GetCsigRxData, Spi_GetCsihRxData,
 *                              Spi_CheckRegEmpty, Spi_CheckErrorInt,
 *                              Spi_GetCurrentRxData and Spi_SyncRegSettings.
 *                            2.Spi_EccSelfTest function is split in to
 *                              Spi_EccAllZeroTest, Spi_EccAllOneTest
 *                              Spi_EccWalkOneTest, Spi_EccTwoBitTest.
 *                            3.Spi_StaticInit function is split in to
 *                              Spi_CsigStaticInit and Spi_CsihStaticInit.
 *                            4.Spi_TransmitISR function is split in to
 *                              Spi_ProcessDirectAcessData, Spi_ProcessCsigData
 *                              Spi_ProcessCsihData, Spi_ProcessFifoData,
 *                              and Spi_ProcessDualBufferData.
 *                            5.Spi_LoopBackSelfTest function is split in to
 *                              Spi_CsigLoopBackSelfTest and
 *                              Spi_CsihLoopBackSelfTest.
 *                            6.Spi_InitDetCheck and Spi_AsyncDetCheck
 *                              functions are created.
 *                            7.Spi_AsyncTransmitInDirectAccessAndFifoMode and
 *                              Spi_SeqJobChannelInit functions are created.
 *                         20.Spi_CsihTxDataAndErrorProcessing,
 *                            Spi_CsigTxDataAndErrorProcessing,
 *                            Spi_SyncProcessData, Spi_SyncRegSettings,
 *                            Spi_StaticInit, Spi_GetCsigRxData,
 *                            Spi_GetCsihRxData, Spi_CheckRegEmpty API's are
 *                            updated to fix compilation and testing issues.
 *                         21.QAC and PolySpace warnings are fixed.
 *                         22.As part of ticket ARDAAAE-1518, Corrected
 *                            critical section protection recursion.
 *                         23.As part of metrics improvement
 *                            Spi_ProcessChannel() function is replaced with
 *                            the following functions
 *                            Spi_AsyncChannelRegSettings,
 *                            Spi_ProcessChannelInFifoMod, Spi_FifoReadData
 *                            and Spi_ProcessChannelInDualOrTxMod.
 *                         24.Spi_FifoWriteData() is called from
 *                            Spi_ProcessChannelInFifoMod function.
 * V1.4.6:  07-Feb-2016  : As part of P1x V4.01.00 Release, following changes
 *                         are made:
 *                         1.As per ticket ARDAAAE-1565,Volatile declaration is
 *                           added to Hardware registers.
 *                         2.As per ticket ARDAAAE-1586, Memory section updated
 *                           for Spi_HWMainFunction_Handling function.
 *                         3.As part of ticket ARDAAAE-1699, the configured port
 *                           pins for CSIG chip select are initialized with the
 *                           default values in function Spi_SeqJobChannelInit.
 *                         4.As part of ticket ARDAAAE-1553, the condition for
 *                           checking ddNoOfRxBuffers is deleted in the else
 *                           condition in Spi_ReceiveISR API.
 *                         5.As per ticket ARDAAAE-1487, SYNCP instruction is
 *                           added.
 *                         6.MISRA violation START and END msgs for Msg(2:3227),
 *                           Msg(2:2814) and  Msg(2:3204)are added at the
 *                           respective places.
 *                         7.As per ARDAAAE-1821, SPI_UT_002 - SPI_UT_027 tag
 *                          is added as part of unit testing.
 * V1.4.7:  10-Aug-2016  : As part of P1x V4.01.01 release, following changes
 *                         are made.
 *                         1.As per JIRA ticket ARDAAAE-1558,
 *                           Software metrics improvement, following
 *                           changes are made:
 *                           1.Spi_ReceiveDirectAcessData  is called from
 *                             Spi_ReceiveISR.
 *                           2.Spi_ProcesSeqInDualOrTxMod is called from
 *                             Spi_ProcessSequence.
 *                           3.Spi_CheckAndInvokeTxIsr and
 *                             Spi_CheckAndInvokeRxIsr are is called from
 *                             Spi_HWMainFunction_Handling.
 *                           4.Spi_SetEojAndCsriBits & Spi_SetEojBit are called
 *                             from Spi_SyncProcessData.
 *                           5.Spi_ProcessTransmission is called from
 *                             Spi_AsyncInDirAccOrFifoMod.
 *                           6.Spi_GetTxRegValue is called from
 *                             Spi_ProcessChannelInDirAccMod.
 *                           7.Spi_CfgRegSettings is called from
 *                             Spi_AsyncChannelRegSettings.
 *                           8.Renamed functions and return types as per the
 *                             coding standards.
 *                         2.As part of Write-verify user interface
 *                           implementation, added APIID to the macros for
 *                           writing to registers and added macros for writing
 *                           in to status clear registers.
 *                         3.Updated the functions Spi_DmaISR,
 *                           Spi_CsihStaticInit to support DMA functionality
 *                           for High priority hardware sequences in
 *                           Tx-Only mode.
 *                         4.Removed unused local variables from the
 *                           Spi_ProcessCsigData function.
 *                         5.Updated the functions Spi_CsigLoopBackSelfTest
 *                           and Spi_CsihLoopBackSelfTest for adding the
 *                           hardware error check in loop back mode as per
 *                           the ticket ARDAAAE-1609.
 *                         6.As part of JIRA ticket ARDAAAE-1541, start
 *                           sequence notification is removed from
 *                           Spi_ProcesSeqInDualOrTxMod function and added in
 *                           Spi_ProcessTransmission function.
 *                         7.As per JIRA ticket ARDAAAE-1568, MBS bit of
 *                           register CSIGnCTL0 is set to one while setting
 *                           PWR bit for CSIG HW unit in the function
 *                           Spi_HWTransmitSyncJob.
 *                         8.As part of JIRA ticket ARDAAAE-1606,
 *                           setting of global variable Spi_GblSyncTx is moved
 *                           from Spi_InitiateSycTransmit function to
 *                           Spi_HWTransmitSyncJob function for correctly
 *                           updating the registers for next job when channel
 *                           properties are same.
 *                         9.As part of JIRA ticket ARDAAAE-1604, condition
 *                           checking for last job is added before
 *                           decrementing the local variable LpJobList
 *                           in Spi_CsihStaticInit function.
 *                        10.As part of JIRA ticket ARDAAAE-1630,
 *                           RH850_SV_MODE_ICR_AND is added
 *                           for 'pErrorIntCntlAddress' and
 *                           'pTxCancelIntCntlAddress' in
 *                           Spi_HWDisableInterrupts function. For
 *                           'pTxCancelIntCntlAddress', RH850_SV_MODE_ICR_AND
 *                           is added for CSIH hardware unit only.
 *                        11.As part of JIRA ticket ARDAAAE-1641,
 *                           global variable 'Spi_GusDataAccess' has been
 *                           split into variables 'Spi_GusSynDataAccess'
 *                           and 'Spi_GusAsynDataAccess' for Synchronous
 *                           and Asynchronous transmission respectively.
 *                        12.As part of JIRA ticket ARDAAAE-1608,
 *                           Null Pointer check is added for
 *                           pPortGrpRegAddress in Spi_HWDeActivateCS and
 *                           Spi_HWActivateCS function.
 *                        13.As part of JIRA ticket ARDAAAE-1643,
 *                           in order to update all
 *                           CSIHnCFGx registers for all configured chip
 *                           selects, do-while loop is added in function
 *                           Spi_CsihStaticInit, Spi_CfgRegSettings
 *                           and Spi_SeqJobChannelInit.
 *                        14.As part of JIRA ticket ARDAAAE-1588,
 *                           Spi_HWTransmitSyncJob function has been updated
 *                           to replace LblDemReported with LenReturnValue to
 *                           improve the code quality.
 *                        15.As part of ARDAAAE-1745,updated functions
 *                           Spi_HWMainFunction_Handling and
 *                           Spi_CheckAndInvokeTxIsr for direct access mode.
 *                        16.As part of JIRA ticket ARDAAAE-1660, added NULL
 *                           pointer check for Spi_GpConfigPtr->pStatusArray
 *                           in Spi_TransmitCancelISR and
 *                           Spi_ChkCancelReqForSeq functions.
 *                        17.As part of JIRA ticket ARDAAAE-1899,
 *                           Spi_ProcessCsihData function has been updated to
 *                           set EOJ bit.
 *                        18.As part of JIRA ticket ARDAAAE-1862,
 *                           Spi_EccSelfTest API has been updated to add a
 *                           against the LenReturnValue in the while loop
 *                           that checks against the maximum HW unit
 *                           configured.
 *                        19.As part of ARDAAAE-1730, Spi_TxDmaConfig function
 *                           has been updated.
 *                        20.Fixed QAC and MISRA warning.
 *                        21.Updated the function
 *                           Spi_ProcessChannelInDirAccMod as part of fixing
 *                           the ticket ARDAAAE-1905.
 *                        22.Updated the functions Spi_ProcessChannelInFifoMod
 *                           and Spi_AsyncChannelRegSettings for handling high
 *                           priority hardware sequences as part of
 *                           ARDAAAE-1905.
 *                        23.As part of JIRA ticket ARDAAAE-1578, updated
 *                           Spi_ProcessChannelInDirAccMod function to add the
 *                           conditional check
 *                           if ((SPI_FALSE == LpJobConfig->blHWUnitDmaMode) \
 *                           || (SPI_ONE < LddNoOfBuffers)).
 *                        24.As part of ARDAAAE-1908,removed AR 3.2.2
 *                           related version checks and DMA_TYPE_ONE related
 *                           code implementation since P1M supports DMA of
 *                           DMA_TYPE_TWO only and removed the switch
 *                           #if (SPI_AR_VERSION == SPI_AR_HIGHER_VERSION)
 *                           and GPIO_CS check if CSIH is configured in
 *                           Spi_HWDeInit function.
 *                        25.Updated Spi_DmaISR function to support high
 *                           priority sequences when TX only mode is
 *                           configured as per ticket ARDAAAE-1904.
 *                        26.Updated the functions Spi_ProcessFifoData and
 *                           Spi_ProcessChannelInFifoMod for handling 128
 *                           bytes FIFO data as part of fixing ticket
 *                           ARDAAAE-1583.
 *                        27.As part of ARDAAAE-1822, updated the function
 *                           header with the list of used registers, global
 *                           variables and function invoked.
 *                        28.As part of ARDAAAE-1828 JIRA ticket fix,
 *                           Spi_HWInit,Spi_HWDeInit functions are
 *                           updated.
 *                        29.As part of ARDAAAE-1743, updated Spi_HWWriteIB
 *                           to set memory mode as Tx only or Dual buffer in
 *                           register CSIHnMCTL0 before writing into CSIHnTX0W
 *                           and CSIHnMRWP0 to avoid setting of bits which are
 *                           prohibited in other memory modes.
 *                        30.As part of ARDAAAE-1701, updated
 *                           Spi_EccAllOneTest,Spi_EccAllZeroTest,
 *                           Spi_EccWalkOneTest and Spi_EccTwoBitTest.
 *                        31.As part of ARDAAAE-1671 fix, invoked
 *                           Spi_CheckErrorInt function after reception
 *                           to check for errors in Spi_GetCsigRxData and
 *                           Spi_GetCsihRxData functions.
 *                        32.Added UD ID's 'SPI_ESDD_UD_xxx' and
 *                           Requirements in respective places.
 *                        33.Updated register write verification
 *                           implementation as part of ARDAAAE-1663.
 *                        34.UT ID TAGs 'SPI_UT_xxx' are added for the
 *                           non-covered parts of the code.
 * V1.4.8:  24-Oct-2016  : The following changes are made:
 *                         1.As part of fixing the ticket ARDAAAE-1968,
 *                           updated Spi_ProcessChannelInFifoMod,
 *                           Spi_ProcessFifoData, Spi_DmaISR and Spi_TxDmaConfig
 *                           functions for permitting more than 128 bytes of
 *                           data when DMA is enabled in FIFO mode.
 *                         2.As part of ARDAAAE-1980, updated
 *                           Spi_CsihStaticInit and Spi_SyncRegSettings to
 *                           remove the compiler switches before the CSIHnMCTL0
 *                           registers are updated so that in direct access
 *                           mode also, the register shall get updated with
 *                           the generated value which is 0.
 *                         3.As part of safety analysis(ARDAAAE-2050), updated
 *                           the write verification of registers involving
 *                           OR/AND operations.
 *                         4.As part of safety analysis(ARDAAAE-2048), updated
 *                           the function Spi_ProcessCsihData to remove the
 *                           setting of EOJ bit and corrected the condition
 *                           check in Spi_ProcessExtendedData function.
 *                         5.MISRA C RULE VIOLATION section is updated for
 *                          (4:2995).
 *                         6.As part of safety analysis(ARDAAAE-2046),
 *                           Spi_HWDeInit is updated for the variables
 *                           LpHWUnitInfo and LpMainOsBaseAddr are initialized
 *                           inside the while loop, so that the addresses will
 *                           be updated for each hardware unit.
 *                         7.Updated Spi_FifoReadData function as part of
 *                           ARDAAAE-2061.
 *                         8.Updated Spi_ComErrorISR function as part of
 *                           ARDAAAE-2067.
 *                         9.Updated Spi_ProcessCsihData function as part of
 *                           ARDAAAE-2071.
 *                        10.Updated Spi_InitiateJobTx and Spi_ReceiveISR
 *                           functions to add the pre compile check for
 *                           Internal buffers as part of ticket ARDAAAE-2072.
 *                        11.Updated Spi_ComErrorISR function to handle the
 *                           other sequences when an error is reported as part
 *                           of ARDAAAE-2068.
 *                        12.As part of ARDAAAE-2059, In Spi_TxDmaConfig
 *                           function,DMA Trigger factor is set as hardware
 *                           trigger for all cases except FIFO mode and when
 *                           number of buffers to be transmitted is one.
 *                        13.As part of ARDAAAE-2093, added null pointer
 *                           check before accessing pTxCancelImrAddress and
 *                           pTxCancelIntCntlAddress in Spi_HWInit,
 *                           Spi_HWDeInit and Spi_HWDisableInterrupts functions.
 *                        14.As part of ARDAAAE-2094, removed the dead code
 *                           "if(SPI_FALSE == LpCurrentCommData->blTxEDL)"
 *                           present in Spi_ProcessCsihData function and
 *                           removed the code related to CSIH HW Unit regarding
 *                           the setting of loop back mode in CSIHnCTL1
 *                           register in Spi_CsigLoopBackSelfTest function.
 *                        15.As part of ARDAAAE-2092, updated Spi_HWDeInit
 *                           function to correct the values written to status
 *                           clear registers.
 *                        16.As part of ARDAAAE-2060, added untraced
 *                           requirements.
 *                        17.As part of ARDAAAE-2107, corrected mask value
 *                           SPI_CSIHMCTL0_MASK_1 to SPI_CSIHMCTL0_MASK
 *                           in Spi_HWWriteIB function and updated the mask
 *                           value while performing the write verification for
 *                           CSIGnCTL1 register.
 *                        18.As part of ARDAAAE-2110, updated
 *                           Spi_CheckAndInvokeTxIsr and
 *                           Spi_HWMainFunction_Handling to correct the
 *                           invocation of Spi_ReceiveISR in case of direct
 *                           access mode.
 * V1.4.9:  15-Feb-2017  : Following changes are made:
 *                         1.As part of ARDAAAE-2257,added condition check
 *                           in the Spi_HWInit and Spi_HWDeInit to clear
 *                           TIJC interrupts.
 *                         2.As part of ARDAAAE-2119,Spi_HWTransmitSyncJob()
 *                           and Spi_InitiateSycTransmit() are updated to set
 *                           the variable 'Spi_GblSyncTx' properly.
 *                         3.As part of ARDAAAE-2116,Spi_HWTransmitSyncJob()
 *                           is updated by removing the setting of
 *                           'Spi_GblSyncTx'.
 *                         4.As part of ARDAAAE-2114,Spi_HWWriteIB()
 *                           is updated to write CSIHMCTL0 in all possible
 *                           combination of Tx-mode and dual buffer mode.
 *                         5.As part of ARDAAAE-2130,MISRA C RULE VIOLATION
 *                           Msg(4:0303),Msg(4:0400) and QAC Warning Msg(2:3416)
 *                           Msg(0:2755) are added at the relevant places.
 *                         6.As part of ARDAAAE-2102,Spi_ReceiveISR() is
 *                           updated by removing the redundant code for 32 bit
 *                           transmission in Tx-only mode.
 *                         7.As a part of ARDAAAE-2252,ARDAAAE-2212 and
 *                           ARDAAAE-2269, following changes are made:
 *                             a. Spi_ProcessSequence function call in
 *                                Spi_ComErrorISRis removed.
 *                             b. In Spi_ProcessTransmission function,
 *                                critical section is modified.
 *                             c. In Spi_ProcessTransmission function,
 *                                LblInitiateTx is assigned with SPI_TRUE
 *                                based on the comparison of queue status
 *                         8.Copyright information is updated.
 *                         9.As part of ARDAAAE-2277,following changes are made:
 *                             a. Re-initialization of the "Spi_GpDmaUnitConfig"
 *                                variable in Spi_HWDeInit() is removed.
 *                             b. Constants are moved to left hand side for
 *                                condition checks at all applicable places.
 *                             c. Naming convention corrected from LucIndex
 *                                to LusIndex
 *                         10.As part of ARDAAAE-2381,job and sequence failed
 *                            condition check is added in
 *                            Spi_ProcessDualBufferData() for dual buffer mode.
 * V1.4.10:  09-Mar-2017  : Following changes are made:
 *                          1. As part of ARDAAAE-2409,Spi_ProcessTransmission()
 *                             is protected entirely in critical section
 *                             to avoid the interruption of queueing mechanism.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Spi_Scheduler.h"
#include "rh850_Types.h"
/* Implements SPI_ESDD_UD_160 */
/* Implements EAAR_PN0034_FSR_0004, EAAR_PN0034_FSR_0003 */
/* Implements EAAR_PN0034_FSR_0002 */
#include "Spi_RegWrite.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define SPI_DRIVER_C_AR_RELEASE_MAJOR_VERSION \
                                  SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_DRIVER_C_AR_RELEASE_MINOR_VERSION \
                                  SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_DRIVER_C_AR_RELEASE_REVISION_VERSION \
                               SPI_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define SPI_DRIVER_C_SW_MAJOR_VERSION    SPI_SW_MAJOR_VERSION_VALUE
#define SPI_DRIVER_C_SW_MINOR_VERSION    SPI_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (SPI_DRIVER_AR_RELEASE_MAJOR_VERSION != \
                                       SPI_DRIVER_C_AR_RELEASE_MAJOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Major Version"
#endif

#if (SPI_DRIVER_AR_RELEASE_MINOR_VERSION != \
                                       SPI_DRIVER_C_AR_RELEASE_MINOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Minor Version"
#endif

#if (SPI_DRIVER_AR_RELEASE_REVISION_VERSION != \
                                       SPI_DRIVER_C_AR_RELEASE_REVISION_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Release Revision Version"
#endif


#if (SPI_DRIVER_SW_MAJOR_VERSION != SPI_DRIVER_C_SW_MAJOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Software Major Version"
#endif /*END of SPI_DRIVER_SW_MAJOR_VERSION */

#if (SPI_DRIVER_SW_MINOR_VERSION != SPI_DRIVER_C_SW_MINOR_VERSION)
  #error "Spi_Scheduler.c : Mismatch in Software Minor Version"
#endif /*END of SPI_DRIVER_SW_MINOR_VERSION */

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To access only the lower byte of the converted values      */
/*                 from the conversion register.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0759)-1 and                           */
/*                 END Msg(4:0759)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified..               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Pointer variable have to be updated to use in the function */
/*                 called.                                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-2 and                           */
/*                 END Msg(4:2982)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) Increment or decrement operation performed on     */
/*               : pointer.                                                   */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To have a better readability of the code which will help   */
/*                 for debugging purpose array indexing is not performed.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-3 and                           */
/*                 END Msg(4:0489)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488)Performing pointer arithmetic.                     */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To have a better readability of the code which will help   */
/*                 for debugging purpose array indexing is not performed.     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-4 and                           */
/*                 END Msg(4:0488)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0317) An expression of type 'pointer-to-void' is being  */
/*                 implicitly converted to a 'pointer-to-object' type.        */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Implicit conversion is performed between a pointer to void */
/*                 to pointer to prevent publishing of internal structure.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg (4:0317)-5  and                         */
/*                 END Msg (4:0317)-5  tags in the code.                      */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always false since */
/*                 only one job is configured. However, when two or more jobs */
/*                 are configured this warning ceases to exist.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-6 and                           */
/*                 END Msg(4:2996)-6 tags in the code.                        */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2993) The value of this 'do - while' loop controlling   */
/*                 expression is always 'false'. The loop will only be        */
/*                 executed once.                                             */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : The result of this logical operation is always false since */
/*                 only one job is configured. However, when two or more jobs */
/*                 are configured this warning ceases to exist.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2993)-7 and                           */
/*                 END Msg(4:2993)-7 tags in the code.                        */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                  type.                                                     */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-8 and                           */
/*                 END Msg(4:0306)-8 tags in the code.                        */
/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0316) Cast from a pointer to void to a pointer to       */
/*                  object.                                                   */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Cast is performed between a pointer to void to pointer to  */
/*                 object type to prevent publishing of internal structure.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-9 and                           */
/*                 END Msg(4:0316)-9 tags in the code.                        */
/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
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
/* Reference     : Look for START Msg(4:2984)-10 and                          */
/*                 END Msg(4:2984)-10 tags in the code.                       */
/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2962) Using value of uninitialized automatic object.    */
/* Rule          : MISRA-C:2004 Rule 9.1                                      */
/* Justification : The object is initialized under pre-compile section, and   */
/*                 the pre-compile macros are generated by generation tool    */
/*                 based on user configuration.                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2962)-11 and                          */
/*                 END Msg(4:2962)-11 tags in the code.                       */
/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2877) This loop will only be executed once and so the   */
/*                 loop mechanism is redundant.                               */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : This operation appears to be redundant because only one    */
/*                 controller is configured.                                  */
/*                 However, when two or more controllers are configured       */
/*                 this warning ceases to exist.                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2877)-12 and                          */
/*                 END Msg(4:2877)-12 tags in the code.                       */
/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0402) An object being modified and accessed between     */
/*                 sequence points - evaluation order unspecified.            */
/* Rule          : MISRA-C:2004 Rule 1.2                                      */
/* Justification : This is a problem due to the improper interpretation of    */
/*                 of priority of operators for bitwiseOR and AND operations  */
/*                 by macro functions. This is already taken care by  proper  */
/*                 use of brackets to determine the order of execution.       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0402)-13 and                          */
/*                 END Msg(4:0402)-13 tags in the code.                       */
/******************************************************************************/

/* 14. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3673)The object addressed by the pointer parameter      */
/*                 is not modified and so the pointer could be of type        */
/*                 'pointer to const'.                                        */
/* Rule          : MISRA-C:2004 Rule 16.7                                     */
/* Justification : pointer variable is used to modify the value at the address*/
/*                 so the pointer cannot be declared as 'pointer to const'    */
/*                 type.                                                      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3673)-14 and                          */
/*                 END Msg(4:3673)-14 tags in the code.                       */
/******************************************************************************/

/* 15. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'.                                                    */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : The result of this logical operation is always false since */
/*                 only one channel is configured. However, when two or more  */
/*                 channels are configured this warning ceases to exist.      */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-15 and                          */
/*                 END Msg(4:2995)-15 tags in the code.                       */
/******************************************************************************/

/* 16. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0303) [I] Cast between a pointer to volatile object     */
/*                 and an integral type.                                      */
/* Rule          : MISRA-C:2004 Rule 3.1 and 11.3                             */
/* Justification : This macro is used to write or read values from hardware   */
/*                 addresses.                                                 */
/* Verification  : However, this part of the code is verified manually and it */
/*                 is not having any impact.                                  */
/* Reference     : Look for START Msg(4:0303)-16 and                          */
/*                 END Msg(4:0303)-16 tags in the code.                       */
/******************************************************************************/

/* 17. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0400) 'Spi_GusAllQueueSts' is modified more than once   */
/*                 between sequence points - evaluation order unspecified.    */
/* Rule          : MISRA-C:2004 Rule 1.2 and Rule 12.2                        */
/* Justification : 'Spi_GusAllQueueSts' is incremented by 4. This is a valid  */
/*                 statement in C                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0400)-17 and                          */
/*                 END Msg(4:0400)-17 tags in the code.                       */
/******************************************************************************/

/* 18. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2991) The value of this 'if' control expression         */
/*                 is always 'true'.                                          */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The value of this 'if' control expression is always true   */
/*                 since variable updating in pre-compile condition.          */
/*                 However, when SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT         */
/*                 is ON or the variable value will be changed if             */
/*                 SPI_LEVEL_DELIVERED is not equal to zero,this warning      */
/*                 ceases to exist.                                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-18 and                          */
/*                 END Msg(4:2991)-18 tags in the code.                       */
/******************************************************************************/

/* 19. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2985) This operation is redundant. The value of the     */
/*                 result is always that of the left-hand operand.            */
/* Rule          : MISRA-C:2004                                               */
/* Justification : The value of the macro SPI_RX_BUFFER_START can have a value*/
/*                 other than 0 based on configuration.                       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2985)-19 and                          */
/*                 END Msg(4:2985)-19 tags in the code.                       */
/******************************************************************************/
/**                         QAC Warnings                                     **/
/******************************************************************************/

/* 16.  QAC Warning:                                                          */
/* Message       : (2:3227) The value of this function parameter is never     */
/*                 modified. It could be declared with the 'const' type       */
/*                 Qualifier.                                                 */
/* Rule          : NA                                                         */
/* Justification : The function parameters of AUTOSAR APIs and Vendor specific*/
/*                 APIs cannot be modified to be made as constant.            */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3227)-16 and                          */
/*                 END Msg(2:3227)-16 tags in the code.                       */
/******************************************************************************/

/* 17.  QAC Warning:                                                          */
/* Message       : (2:2824) Possible: Arithmetic operation on NULL pointer.   */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2824)-17 and                          */
/*                 END Msg(2:2824)-17  tags in the code.                      */
/******************************************************************************/

/* 18. QAC Warning:                                                           */
/* Message       : (3:3352) This 'switch' statement contains only two         */
/*                 execution paths.                                           */
/* Rule          : NA                                                         */
/* Justification : Case statements which used in this functions are executed  */
/*                 only when the Macros are enabled                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(3:3352)-18 and                          */
/*                 END Msg(3:3352)-18 tags in the code.                       */
/******************************************************************************/

/* 19. QAC Warning:                                                           */
/* Message       : (3:3203) The variable 'XXX' is set but never used          */
/* Rule          : NA                                                         */
/* Justification : These variables are used for dummy read of registers       */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(3:3203)-19 and                          */
/*                 END Msg(3:3203)-19 tags in the code.                       */
/******************************************************************************/

/* 20. QAC Warning:                                                           */
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
/* Reference     : NA                                                         */
/******************************************************************************/

/* 21.  QAC Warning:                                                          */
/* Message       : (2:2814) Possible: Dereference of NULL pointer.            */
/* Rule          : NA                                                         */
/* Justification : The Pointers generated using Post Build configurations may */
/*                  not be NULL.                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2814)-20 and                          */
/*                 END Msg(2:2814)-20 tags in the code.                       */
/******************************************************************************/

/* 22.  QAC Warning:                                                          */
/* Message       : (2:3892) The result of this cast is implicitly converted   */
/*                 to another type                                            */
/* Rule          : NA                                                         */
/* Justification : This is done to change the behaviour of  the expression    */
/*                 so as to get the correct value(of similar size) assigned   */
/*                 to the RHS.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3892)-21 and                          */
/*                 END (2:3892)-21 tags in the code.                          */
/******************************************************************************/

/* 23.  QAC Warning:                                                          */
/* Message       : (2:3206)The parameter 'XXX' is not used in this function   */
/* Rule          : NA                                                         */
/* Justification : The parameter is used only when the user interface is      */
/*                 configured for write-verify error notification. Creating   */
/*                 different macros will increase the code complexity, Hence  */
/*                 used the same macro in both the cases.                     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3206)-22 and                          */
/*                 END Msg(2:3206)-22  tags in the code.                      */
/******************************************************************************/

/* 24. QAC Warning:                                                           */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Justification : Logical operation accesses volatile object which is a      */
/*                 register access. All register addresses are generated with */
/*                 volatile qualifier. There is no impact on the functionality*/
/*                 due to this conditional check for mode change.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3416)-24 and END Msg(2:3416)-24       */
/*                 tags in the code.                                          */
/******************************************************************************/

/* 25. QAC Warning:                                                           */
/* Message       : (0:2755) Analysis time of function                         */
/*                 'Spi_ProcessChannelInDirAccMod' has exceeded the           */
/*                 configured maximum: '60000ms'.  Dataflow                   */
/*                 analysis continues with the next function.                 */
/* Rule          : NA                                                         */
/* Justification : Implementation demands usage of all SPI features so it     */
/*                 takes/exceeds the execution time                           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(0:2755)-25 and                          */
/*                 END Msg(0:2755)-25 tags in the code.                       */
/******************************************************************************/

/* 26. QAC Warning:                                                           */
/* Message       : (2:3204) This variable is only set once and so it could    */
/*                 be declared with the 'const' qualifier..                   */
/* Rule          : No Rule                                                    */
/* Justification : The variable value will be changed if  SPI_LEVEL_DELIVERED */
/*                 is not equals to zero.                                     */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.Also this is not a MISRA violation   */
/* Reference     : Look for QAC Warning START Msg(2:3204)-26 and              */
/*                 END Msg(2:3204)-26 tags in the code.                       */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/*******************************************************************************
** Function Name      : Spi_ReportErrorInSyncTx
**
** Service ID         : Not Applicable
**
** Description        : Function to store Hardware Error Details
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpHWUnitInfo - Basic Hardware Register Details
**                      LddSequenceID - Sequence ID
**                      LddJobID - Job ID
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Spi_StoreErrorInfo
**
** Registers Used     : CSIGnSTR0, CSIHnSTR0, CSIGnSTCR0, CSIHnSTCR0
*******************************************************************************/
/* Implements SPI_ESDD_UD_056 */
/* Implements SPI_ESDD_UD_089 */
#if ((SPI_INTERNAL_DIAG_BUFF == STD_ON) &&  \
    ((SPI_LEVEL_DELIVERED == SPI_ZERO) ||   \
     ((SPI_LEVEL_DELIVERED == SPI_TWO) && (SPI_DIRECT_ACCESS_MODE == STD_ON))))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_ReportErrorInSyncTx
           ( P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
                          Spi_SequenceType LddSequenceID, Spi_JobType LddJobID)
/* END Msg(2:3227)-16 */
{
  Spi_CommErrorType LstErrorType;
  uint32 LulErrorValue;
  /* Implements SPI_ESDD_UD_206 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Take the Error value as backup */
  LulErrorValue = LpHWUnitInfo->pHwMainUserBaseAddress->ulMainSTR0;
  /* Copy the Hardware unit Index */
  LstErrorType.HwUnit = LpHWUnitInfo->ucHWUnit;
  /* Copy the Sequence Index */
  LstErrorType.SeqID = LddSequenceID;
  /* Copy the Job Index */
  LstErrorType.JobID = LddJobID;
  /* Check for Over run Error */
  /* QAC Warning: START Msg(2:3892)- 21 */
  if (SPI_OVE_ERR == (LulErrorValue & SPI_OVE_ERR))
  {

    /* Clear the status register */
    SPI_CSIGH_REG_WRITE(LpHWUnitInfo->pHwMainUserBaseAddress->usMainSTCR0,
                                                        (uint16)SPI_OVE_ERR_CLR)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpHWUnitInfo->pHwMainUserBaseAddress->ulMainSTR0, (uint32)SPI_ZERO,
                                   SPI_OVE_ERR_CLR, SPI_SYNCTRANSMIT_SID)

    /* END Msg(2:3892)- 21 */
    /* END Msg(2:2814)-20 */
    LstErrorType.ErrorType = SPI_OVERRUN_ERROR;
    /* Report Error Details */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }
/* Check for Parity Error */
  if (SPI_PE_ERR == (LulErrorValue & SPI_PE_ERR))
  {
    /* Clear the status register */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:3892)- 21 */
    SPI_CSIGH_REG_WRITE(LpHWUnitInfo->pHwMainUserBaseAddress->usMainSTCR0,
                                                        (uint16)SPI_PE_ERR_CLR)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpHWUnitInfo->pHwMainUserBaseAddress->ulMainSTR0,(uint32)SPI_ZERO,
              SPI_PE_ERR_CLR, SPI_SYNCTRANSMIT_SID)
    /* Implements SPI_ESDD_UD_182 */
    /* END Msg(2:3892)- 21 */
    /* END Msg(2:2814)-20*/
    LstErrorType.ErrorType = SPI_PARITY_ERROR;
    /* Report Error Details */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }

  /* Check for Data Consistency Error */
  if (SPI_DCE_ERR == (LulErrorValue & SPI_DCE_ERR))
  {
    /* Clear the status register */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:3892)- 21 */
    SPI_CSIGH_REG_WRITE(LpHWUnitInfo->pHwMainUserBaseAddress->usMainSTCR0,
                                                        (uint16)SPI_DCE_ERR_CLR)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpHWUnitInfo->pHwMainUserBaseAddress->ulMainSTR0,(uint32)SPI_ZERO,
    SPI_DCE_ERR_CLR,SPI_SYNCTRANSMIT_SID)
    /* END Msg(2:3892)- 21 */
    /* END Msg(2:2814)-20 */
    LstErrorType.ErrorType = SPI_DATA_CONSISTENCY_ERROR;
    /* Report Error Details */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
          /* No action required */
  }

  if (SPI_HW_UNIT_CSIG0 != LpHWUnitInfo->ucHWUnit)
  {
    /* Check for Overflow Error */
    if (SPI_OFE_ERR == (LulErrorValue & SPI_OFE_ERR))
    {
      /* Clear the status register */
      /* QAC Warning: START Msg(2:2814)-20 */
      /* END Msg(2:3892)- 21 */

      SPI_CSIGH_REG_WRITE(LpHWUnitInfo->pHwMainUserBaseAddress->usMainSTCR0,
      (uint16)SPI_OFE_ERR_CLR)
      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
      LpHWUnitInfo->pHwMainUserBaseAddress->ulMainSTR0,(uint32)SPI_ZERO,
      SPI_OFE_ERR_CLR,SPI_SYNCTRANSMIT_SID)
      /* END Msg(2:3892)- 21 */
      /* END Msg(2:2814)-20 */
      LstErrorType.ErrorType = SPI_OVERFLOW_ERROR;
      /* Report Error Details */
      Spi_StoreErrorInfo(&LstErrorType);
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
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of ((SPI_INTERNAL_DIAG_BUFF == STD_ON) &&  \
        *        ((SPI_LEVEL_DELIVERED == SPI_ZERO) ||   \
        *        ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
        *        (SPI_DIRECT_ACCESS_MODE == STD_ON))))
        */
/*******************************************************************************
** Function Name      : Spi_StoreErrorInfo
**
** Service ID         : Not Applicable
**
** Description        : Function to store Hardware Error Details
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpErrorDetails - Error Details
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstCommErrorInfo, Spi_GucBufferIndex
**
** Function Invoked   : None
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_057 */
#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_StoreErrorInfo (
          P2CONST(Spi_CommErrorType, AUTOMATIC, SPI_APPL_CONST) LpErrorDetails )
/* END Msg(2:3227)-16 */
{
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Copy the Error details into the Error Buffer */
  Spi_GstCommErrorInfo[Spi_GucBufferIndex] = *LpErrorDetails;
  /* END Msg(2:2814)-20 */
  /* Index Pointing to the next location */
  Spi_GucBufferIndex++;
  /* Spi_GucBufferIndex updating to zero, since it is a cyclic buffer */
  /* QAC Warning: START Msg(2:3416)-24 */
  if (SPI_MAX_ERROR_BUFFER_SIZE  <= Spi_GucBufferIndex)
  /* END Msg(2:3416)-24 */
  {
    Spi_GucBufferIndex = SPI_ZERO;
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* End of (SPI_INTERNAL_DIAG_BUFF == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_HWInit
**
** Service ID         : Not Applicable
**
** Description        : This service initializes the HW Unit
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : Spi_GpDmaUnitConfig, Spi_GstHWUnitInfo,
**                      Spi_GpConfigPtr
**
** Function invoked   : None
**
** Registers Used     : CSIGnCTL0, CSIHnCTL0, DTCTn, IMRn, DDAn, CSIHnMCTL1,
**                      DSAn, CSIGnCTL1, CSIHnCTL1, CSIGnBCTL0, DCSTCn,
**                      CSIHnMCTL2, DCENn, DTFRn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_017 */
#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements AR_PN0063_FR_0035, AR_PN0063_FR_0129, EAAR_PN0034_FR_0023 */
/* Implements EAAR_PN0034_FSR_0001, AR_PN0063_FR_0142, EAAR_PN0034_FR_0067 */
FUNC(void, SPI_PRIVATE_CODE) Spi_HWInit(void)
{

  #if ((((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
         (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) || \
         (SPI_DMA_MODE_ENABLE == STD_ON))

  P2VAR(volatile uint16, AUTOMATIC, SPI_CONFIG_DATA) LpIntCntlAddress;
  #endif
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr;
  Spi_HWUnitType LddHWUnitNumber;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  /* Implements SPI_ESDD_UD_145 */
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) || \
  (SPI_FIFO_MODE == STD_ON))
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  uint8 LucHWMemoryMode;
  #endif
  #endif
  /* Implements SPI_ESDD_UD_090 */
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  P2CONST(Spi_DmaUnitConfig, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;
  P2VAR(Spi_DmaAddrRegs, AUTOMATIC, SPI_CONFIG_DATA) LpDmaRegisters;
  #endif
  Spi_HWUnitType LddHWUnit;
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  uint8 LucLoopCount;
  uint8 LucMaxDmaChannels;
  #endif
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  /* MISRA Violation: START Msg(4:0317)-5 */
  /* QAC Warning: START Msg(2:2824)-17 */
  Spi_GpDmaUnitConfig = Spi_GpConfigPtr->pDMAConfiguration;
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0317)-5 */
  LucMaxDmaChannels = Spi_GpConfigPtr->ucMaxDmaChannels;
  /* END Msg(2:2814)-20 */
  for (LucLoopCount = SPI_ZERO;
                      LucLoopCount < LucMaxDmaChannels; LucLoopCount++)
  {
    /* QAC Warning: START Msg(2:2824)-17 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpDmaConfig = Spi_GpDmaUnitConfig + LucLoopCount;
    /* END Msg(2:2824)-17 */
    /* END Msg(4:0488)-4 */
    /* Implements SPI_ESDD_UD_190 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpDmaRegisters = LpDmaConfig->pDmaCntlRegBase;

    /* Disable the DMA interrupt control register */
    LpIntCntlAddress = LpDmaConfig->pDmaImrIntCntlReg;

    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                                        (uint16)(~(LpDmaConfig->usDmaImrMask)));

    /* Clear the DTS bit */
    /* Disable channel operation */
    /* MISRA Violation: START Msg(4:0402)-13 */
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCSTCn, SPI_DMA_STR_CLEAR)
    SPI_DMA_REG_WRITE_VERIFY_INIT(LpDmaRegisters->ulDCSTn,(uint32)SPI_ZERO,
                                               SPI_DMA_STR_CLEAR, SPI_INIT_SID)

    /* Implements SPI_ESDD_UD_161 */
    SPI_DMA_REG_WRITE( LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_DISABLE)
    SPI_DMA_REG_WRITE_VERIFY_INIT(LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_DISABLE,
                                                   SPI_DCEN_MASK, SPI_INIT_SID)
    /* END Msg(2:2814)-20 */
    if (SPI_ONE == LpDmaConfig->blComDmaChannel)
    {
      /* Implements SPI_ESDD_UD_191 */
      /* DMA channel for reception. Hence load the source address register */

      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDSAn,LpDmaConfig->ulTxRxRegAddress )
      SPI_DMA_REG_WRITE_VERIFY_INIT( LpDmaRegisters->ulDSAn,
      LpDmaConfig->ulTxRxRegAddress, SPI_CTLREG_32_BIT_MASK, SPI_INIT_SID )
      /* Load the transfer control register */

      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDTCTn, SPI_DMA_16BIT_RX_SETTINGS )
      SPI_DMA_REG_WRITE_VERIFY_INIT( LpDmaRegisters->ulDTCTn,
                       SPI_DMA_16BIT_RX_SETTINGS, SPI_DTCT_MASK,SPI_INIT_SID )
    }
    else
    {
      /* DMA channel for transmission. Hence load the destination address */
      /* register */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDDAn,LpDmaConfig->ulTxRxRegAddress)
      SPI_DMA_REG_WRITE_VERIFY_INIT( LpDmaRegisters->ulDDAn,
           LpDmaConfig->ulTxRxRegAddress, SPI_CTLREG_32_BIT_MASK, SPI_INIT_SID)

      /* Load the transfer control register */
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn, SPI_DMA_16BIT_TX_SETTINGS)
      SPI_DMA_REG_WRITE_VERIFY_INIT(LpDmaRegisters->ulDTCTn,
                         SPI_DMA_16BIT_TX_SETTINGS, SPI_DTCT_MASK,SPI_INIT_SID)
    }
    /* Load the trigger factor configured */
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRn,
                                       (uint32)(LpDmaConfig->usDmaDtfrRegValue))

    SPI_DMA_REG_WRITE_VERIFY_INIT(LpDmaRegisters->ulDTFRn,
    (uint32)(LpDmaConfig->usDmaDtfrRegValue),SPI_DTFR_MASK,SPI_INIT_SID)

    /* END Msg(4:0402)-13 */
  }

  #if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_SELCSIHDMA_ENABLED==STD_ON))
  SPI_DMA_REG_WRITE(SPI_SELECT_CSIH_DMA_ADDR,SPI_SELECT_CSIH_DMA_REG_VAL)
  SPI_DMA_REG_WRITE_VERIFY_INIT(SPI_SELECT_CSIH_DMA_ADDR,
      SPI_SELECT_CSIH_DMA_REG_VAL,SPI_SELECT_CSIH_DMA_MASK,SPI_INIT_SID)


  #endif
  #endif /* End of #if (SPI_DMA_MODE_ENABLE == STD_ON) */
  /* Initialize number of HW Unit as zero */
  LddHWUnit = SPI_ZERO;
  /* Check for maximum HW Unit configured */
  /* MISRA Violation: START Msg(4:2877)-12 */
  do
  /* END Msg(4:2877)-12 */
  {
    /* Implements SPI_ESDD_UD_134 */
    /* Get the pointer to the structure of HW Unit information */
    LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
    #if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON))
    /* Check if the HW Unit is CSIH */
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      /* QAC Warning: START Msg(2:2814)-20 */
      LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
      /* END Msg(2:2814)-20 */

      /* Get the main user base address */
      LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
      /* Get the main OS base address */
      LpMainOsBaseAddr = LpHWUnitInfo->pHwMainOsBaseAddress;
      /* Implements SPI_ESDD_UD_160 */
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Reset the PWR bit in main control register 0 */
      SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_ZERO)
      SPI_CSIGH_REG_WRITE_VERIFY_INIT(LpMainUserBaseAddr->ucMainCTL0,
      SPI_ZERO, SPI_CTLREG_8_BIT_MASK, SPI_INIT_SID)
      /* END Msg(2:2814)-20 */

      LunDataAccess1.ulRegData = SPI_ZERO;

      LunDataAccess1.ucRegData4[SPI_ONE] =
                                 Spi_GpConfigPtr->aaChipSelect[LddHWUnitNumber];
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Configure all chip selects with configured polarity */
      SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1,
                                         LunDataAccess1.ulRegData)

      SPI_CSIGH_REG_WRITE_VERIFY_INIT(LpMainOsBaseAddr->ulMainCTL1,
      LunDataAccess1.ulRegData,SPI_CTLREG_32_BIT_MASK,SPI_INIT_SID)
      /* END Msg(2:2814)-20 */
      #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || \
          (SPI_TX_ONLY_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON))
      /* MISRA Violation: START Msg(4:0316)-9 */
      LpCsihUserBaseAddr =
                        (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
      /* END Msg(4:0316)-9 */
      /* Get the configured memory mode for this HW Unit */
      LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];

      if (SPI_DIRECT_ACCESS_MODE_CONFIGURED != LucHWMemoryMode)
      {
        if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
        {
          /* Initialize CSIH memory register */
          /* QAC Warning: START Msg(2:2814)-20 */
          SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMCTL1,
                                                    SPI_CTL_32BIT_REG_VAL)
          SPI_CSIGH_REG_WRITE_VERIFY_INIT
          (LpCsihUserBaseAddr->ulCSIHMCTL1,SPI_CTL_32BIT_REG_VAL,
                                               SPI_CSIHMCTL1_MASK, SPI_INIT_SID)
          /* END Msg(2:2814)-20 */
        }
        else
        {
         /* QAC Warning: START Msg(2:2814)-20 */
         /* Load the MCTL2 register to start the communication */
         SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMCTL2,
                                                         SPI_CTL_32BIT_REG_VAL)
         SPI_CSIGH_REG_WRITE_VERIFY_INIT(LpCsihUserBaseAddr->ulCSIHMCTL2,
                      SPI_CTL_32BIT_REG_VAL,SPI_CSIHMCTL2_MASK,SPI_INIT_SID)
         /* END Msg(2:2814)-20 */
        }
      }
      else
      {
        /* No action Required */
      }
      #endif /*
              * ((SPI_DUAL_BUFFER_MODE == STD_ON) || \
              *  (SPI_TX_ONLY_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON))
              */
    #endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
    }
    #if ((SPI_CSIH_CONFIGURED == STD_ON) &&(SPI_CSIG_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
       /* MISRA Violation: START Msg(4:0316)-9 */
      LpCsigUserBaseAddr =
                       (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
      /* END Msg(4:0316)-9 */
      /* Implements SPI_ESDD_UD_202 */
      /* Load back the value to configuration register */
      /* QAC Warning: START Msg(2:2814)-20 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ucCSIGBCTL0,SPI_BCTL0_SET_SCE)
      SPI_CSIGH_REG_WRITE_VERIFY_INIT(LpCsigUserBaseAddr->ucCSIGBCTL0,
      SPI_BCTL0_SET_SCE,SPI_CSIGBCTL0_MASK,SPI_INIT_SID)
      /* END Msg(2:2814)-20 */
      /* END Msg(2:3892)-21 */
      #endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
    }

    /* Clear the interrupts in asynchronous mode */
    #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
         (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pRxImrAddress;
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                      ((uint16) (~(Spi_GstHWUnitInfo[LddHWUnit].usRxImrMask))));
    /* END Msg(2:2814)-20 */
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxImrAddress;


    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                       ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usTxImrMask))));


    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pErrorImrAddress;

    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                    ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usErrorImrMask))));

    #endif
    #if (((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) \
          && (SPI_CANCEL_API == STD_ON)|| (SPI_HW_PRIORITY_ENABLED == STD_ON))

    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      if (NULL_PTR != Spi_GstHWUnitInfo[LddHWUnit].pTxCancelImrAddress)
      {
        LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxCancelImrAddress;
        /* Disable interrupt processing */
        RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usTxCancelImrMask))));
      }
      else
      {
        /* No Action Required */
      }
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /* No action required */
    }
    #endif
    #endif /*
            * (((SPI_DUAL_BUFFER_MODE == STD_ON) || \
            *      (SPI_TX_ONLY_MODE == STD_ON)) && (SPI_CANCEL_API == STD_ON) \
            *      || (SPI_HW_PRIORITY_ENABLED == STD_ON))
            */

    /* Increment HW Unit index */
    /* MISRA Violation: START Msg(4:2984)-10 */
    LddHWUnit++;
    /* END Msg(4:2984)-10 */
  /* MISRA Violation: START Msg(4:2993)-7 */
  /* MISRA Violation: START Msg (4:2996)-6 */
  } while (SPI_MAX_HW_DETAILS > LddHWUnit);
  /* End of while (SPI_MAX_HW_DETAILS > LddHWUnit) */
  /* END Msg  (4:2996)-6  */
  /* END Msg  (4:2993)-7  */
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_ONE)
            || (SPI_LEVEL_DELIVERED == SPI_TWO)) */

/*******************************************************************************
** Function Name      : Spi_StaticInit
**
** Service ID         : Not Applicable
**
** Description        : This service performs static initialization.
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstSeq, Spi_GpFirstJobList,
**                      Spi_GpFirstJob, Spi_GpConfigPtr, Spi_GpFirstChannel
**
** Function invoked   : Spi_CsigStaticInit, Spi_CsihStaticInit
**
** Registers Used     : CSIGnCTL0, CSIHnCTL0
*******************************************************************************/
/* Implements SPI_ESDD_UD_044 */
/* Implements SPI_ESDD_UD_097 */
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI368, SPI166, SPI263, SPI212_Conf, SPI009, SPI066 */
/* Implements SPI215_Conf */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_StaticInit(uint8 LucApId)
{
/* END Msg(2:3227)-16 */
  /* Declare a local pointer to point to the Sequence Config Data */
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                              LpPBChannelConfig;
  #endif
  Spi_JobType LddJobIndex;
  Spi_HWUnitType LddHWUnit;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_HWUnitType LddHWUnitNumber;
  Spi_JobType LddNoOfJobs;
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) \
                                                 ||(SPI_FIFO_MODE == STD_ON))
  uint8 LucHWMemoryMode;
  #endif
  #endif /*END of SPI_CSIH_CONFIGURED */
  uint8 LucCxCtl0;
  Spi_SequenceType LddNumSeq;

  /* Load the number of sequence configured as zero */
  LddNumSeq = SPI_ZERO;
  while (SPI_MAX_SEQUENCE > LddNumSeq)
  {
    /* QAC Warning: START Msg(2:2824)-17 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpSeqConfig = Spi_GpFirstSeq + LddNumSeq;
    /* Get the pointer to the job list */
    LpJobList = Spi_GpFirstJobList + (LpSeqConfig->ddJobListIndex);
    /* Get the index of the job and sequence */
    LddJobIndex = LpJobList->ddJobIndex;
    /* Get the pointer of the first job linked to this sequence */
    LpJobConfig = Spi_GpFirstJob + LddJobIndex;

    LddHWUnit = LpJobConfig->ddHWUnitIndex;
    /* Get the pointer to the structure of HW Unit information */
    /* END Msg(2:2824)-17 */
    LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
    /* Increment number of sequences configured */
    LddNumSeq++;

    /* END Msg(4:0488)-4 */
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) \
                                                 ||(SPI_FIFO_MODE == STD_ON))
    /* Get the configured memory mode for this HW Unit */
    LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
    #endif
    #endif
    /* Get the main user base address */
    LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;

    /* MISRA Violation: START Msg(4:0402)-13 */
    /* QAC Warning: START Msg(2:3892)- 21 */
    /* Reset the PWR bit since other registers need to be written */
    LucCxCtl0 = (LpMainUserBaseAddr->ucMainCTL0 & SPI_RESET_PWR);
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)
    SPI_CSIGH_REG_WRITE_VERIFY_INIT(LpMainUserBaseAddr->ucMainCTL0,
                                     LucCxCtl0, SPI_CTLREG_8_BIT_MASK, LucApId)
    /* END Msg(2:3892)- 21 */
    /* END Msg(4:0402)-13 */
    /* END Msg(2:2814)-20 */
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      /* QAC Warning: START Msg(2:2824)-17 */
      /* MISRA Violation: START Msg(4:0488)-4 */
      LpPBChannelConfig = Spi_GpFirstChannel + (*(LpJobConfig->pChannelList));
      /* END Msg(4:0488)-4 */
      /* END Msg(2:2824)-17 */
      Spi_CsigStaticInit(LpHWUnitInfo, LpJobConfig, LpPBChannelConfig,
                                       LpMainUserBaseAddr, LucApId );
      #endif /* #if (SPI_CSIG_CONFIGURED == STD_ON) */
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
      if ((SPI_DUAL_BUFFER_MODE_CONFIGURED == LucHWMemoryMode) ||
                            (SPI_TX_ONLY_MODE_CONFIGURED == LucHWMemoryMode))
      {
        /* Get the number of jobs */
        LddNoOfJobs = LpSeqConfig->ddNoOfJobs;
      }
      else
      #endif /*((SPI_DUAL_BUFFER_MODE == STD_ON) ||
               (SPI_TX_ONLY_MODE == STD_ON)) */
      {
        LddNoOfJobs = SPI_ONE;
      }
      Spi_CsihStaticInit(LpHWUnitInfo, LpJobList, LddNoOfJobs,
                                                  LddHWUnitNumber, LucApId );
      #endif /* #if (SPI_CSIH_CONFIGURED == STD_ON) */
    }
    #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) \
                                                 ||(SPI_FIFO_MODE == STD_ON))
    if (SPI_ZERO < LucHWMemoryMode)
    {
      /* QAC Warning: START Msg(2:3892)- 21 */
      /* Load Main CTL0 register, without setting PWR bit */
      SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_MEMORY_ACCESS)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                         SPI_SET_MEMORY_ACCESS, SPI_CTLREG_8_BIT_MASK, LucApId)
      /* END Msg(2:3892)- 21 */

    }
    else
    #endif
    {
      /* QAC Warning: START Msg(2:3892)- 21 */
      /* Load Main CTL0 register, setting PWR bit at the same time */
      SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_DIRECT_ACCESS)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                          SPI_SET_DIRECT_ACCESS, SPI_CTLREG_8_BIT_MASK, LucApId)
      /* END Msg(2:3892)- 21 */
    }
  } /*   while (SPI_MAX_SEQUENCE > LddNumSeq) */

}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if ((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_HWDeInit
**
** Service ID         : Not Applicable
**
** Description        : This service de-initializes the HW Unit
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init should have been invoked.
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpDmaUnitConfig, Spi_GpFirstJob
**                      Spi_GpConfigPtr
**
** Function invoked   : Spi_HWDeActivateCS
**
** Registers Used     : CSIGnCTL0,CSIGnCTL1,CSIGnCTL2,CSIGnSTCR0,CSIGnCFG0,DTSn
**                      CSIHnCTL0,CSIHnCTL1,CSIHnCTL2,CSIHnSTCR0,CSIHnMCTL0,
**                      CSIHnMRWP0,CSIHnCFG0,CSIHnBRSy,DSAn,DDAn,DTCTn,
**                      EICn,IMRn,DTFRRQCn,DCSTCn,DTFRRQn,DCSTn,DTFRn
*******************************************************************************/
/* Implements SPI_ESDD_UD_021 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(void, SPI_PRIVATE_CODE) Spi_HWDeInit(void)
{

  P2VAR(volatile uint16, AUTOMATIC, SPI_CONFIG_DATA) LpIntCntlAddress;

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  #if (((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) || \
  (SPI_FIFO_MODE == STD_ON)) && (SPI_LEVEL_DELIVERED != SPI_ZERO))
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  uint8 LucHWMemoryMode;
  Spi_HWUnitType LddHWUnitNumber;
  #endif
  uint8 LucCount;
  #endif
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2VAR(Spi_CsigOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigOsBaseAddr;
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  #endif
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  Spi_JobType LddNumJobs;
  #endif
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpHwMainUserBaseAddress;
  P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;

  Spi_HWUnitType LddHWUnit;
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  uint8 LucLoopCount;
  uint8 LucMaxDmaChannels;
  P2CONST(Spi_DmaUnitConfig, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;
  P2VAR(Spi_DmaAddrRegs, AUTOMATIC, SPI_CONFIG_DATA) LpDmaRegisters;
  #endif
  /* Set the maximum number of zero */
  LddHWUnit = SPI_ZERO;

  /* Initialize each HW Unit */
  /* MISRA Violation: START Msg(4:2877)-12 */
  while (SPI_MAX_HW_DETAILS > LddHWUnit)
  /* END Msg(4:2877)-12 */
  {
    LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
    /* Get the main OS base address */
    LpMainOsBaseAddr = Spi_GstHWUnitInfo[LddHWUnit].pHwMainOsBaseAddress;
    LpHwMainUserBaseAddress =
                         Spi_GstHWUnitInfo[LddHWUnit].pHwMainUserBaseAddress;
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Initialize control register 0 to zero */

    SPI_CSIGH_REG_WRITE(LpHwMainUserBaseAddress->ucMainCTL0, SPI_ZERO)
    /* END Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2814)-20 */

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpHwMainUserBaseAddress->ucMainCTL0,
    SPI_ZERO,SPI_CTLREG_8_BIT_MASK,SPI_DEINIT_SID)

    /* Implements SPI_ESDD_UD_205 */
    /* Initialize CTL1 register to zero */
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, (uint32)SPI_ZERO)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
      (uint32)SPI_ZERO, SPI_CTLREG_32_BIT_MASK, SPI_DEINIT_SID)

    /* END Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:3892)- 21 */
    /* Initialize CTL2 register to value after reset */
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, SPI_CTL2_16BIT_REG_DEINIT)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
      SPI_CTL2_16BIT_REG_DEINIT, SPI_CTLREG_16_BIT_MASK, SPI_DEINIT_SID)

    /* END Msg(2:3892)- 21 */
    #if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON))
    /* Check if the HW Unit is CSIH */
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {

      #if (SPI_CSIH_CONFIGURED == STD_ON)
      /* MISRA Violation: START Msg(4:0316)-9 */
      /* Initialize STCR0 register to value after reset */
      /* QAC Warning: START Msg(2:3892)- 21 */
      SPI_CSIGH_REG_WRITE(LpHWUnitInfo->pHwMainUserBaseAddress->usMainSTCR0,
                                                       SPI_CSIH_STCR0_VAL)
      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
      LpHWUnitInfo->pHwMainUserBaseAddress->ulMainSTR0,
      SPI_CTL_16BIT_REG_DEINIT, SPI_CSIH_STCR0_VAL, SPI_DEINIT_SID)

      LpCsihOsBaseAddr = (Spi_CsihOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
      /* END Msg(2:3892)- 21 */
      /* END Msg(4:0316)-9 */
      #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || \
          (SPI_TX_ONLY_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON))
      #if (SPI_LEVEL_DELIVERED != SPI_ZERO)
      /* MISRA Violation: START Msg(4:0316)-9 */
      LpCsihUserBaseAddr =
                       (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
      /* END Msg(4:0316)-9 */
      /* QAC Warning: START Msg(2:2814)-20 */
      LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
      /* Get the configured memory mode for this HW Unit */
      LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
      #endif
      if (SPI_DIRECT_ACCESS_MODE_CONFIGURED != LucHWMemoryMode)
      {
        /* QAC Warning: START Msg(2:3892)-21 */
        /* Initialize MCTL0 register to value after reset*/
        SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->usCSIHMCTL0,
                                                     SPI_MCTL0_16BIT_REG_DEINIT)

        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihOsBaseAddr->usCSIHMCTL0,
                  SPI_MCTL0_16BIT_REG_DEINIT, SPI_CSIHMCTL0_MASK,SPI_DEINIT_SID)
        /* END Msg(2:3892)- 21 */
        if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
        {
          /* Initialize MCTL1 register to value after reset */
          SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMCTL1,
                                                    SPI_CTL_32BIT_REG_VAL)
          SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME( LpCsihUserBaseAddr->ulCSIHMCTL1,
                      SPI_CTL_32BIT_REG_VAL, SPI_CSIHMCTL1_MASK, SPI_DEINIT_SID)
         /* END Msg(2:2814)-20 */
        }
        else
        {
          /* QAC Warning: START Msg(2:2814)-20 */
          /* Initialize MCTL2 register to value after reset */
          SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMCTL2,
                                                         SPI_CTL_32BIT_REG_VAL)
          SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihUserBaseAddr->ulCSIHMCTL2,
                     SPI_CTL_32BIT_REG_VAL, SPI_CSIHMCTL2_MASK, SPI_DEINIT_SID)

          /* Initialize MRWP0 register to value after reset */
          SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMRWP0,
                                                        SPI_CTL_32BIT_REG_VAL)
          SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihUserBaseAddr->ulCSIHMRWP0,
                     SPI_CTL_32BIT_REG_VAL, SPI_CSIHMRWP0_MASK, SPI_DEINIT_SID)

           /* END Msg(2:2814)-20 */
        }
      }
      else
      {
        /* No action required */
      }
      #endif /*
              * ((SPI_DUAL_BUFFER_MODE == STD_ON) || \
              *  (SPI_TX_ONLY_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON))
              */
      for(LucCount = SPI_ZERO; LucCount < SPI_CFG_REG_COUNT; LucCount++)
      {
        /* QAC Warning: START Msg(2:2814)-20 */
        /* Initialize CSIH configuration register */
        SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->ulCSIHCFG[LucCount],
                                                       SPI_CTL_32BIT_REG_VAL)
        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
          LpCsihOsBaseAddr->ulCSIHCFG[LucCount],SPI_CTL_32BIT_REG_VAL,
                                         SPI_CSIHCFG_MASK, SPI_DEINIT_SID)
        /* END Msg(2:2814)-20 */
      }

      for(LucCount = SPI_ZERO; LucCount < SPI_BRS_REG_COUNT; LucCount++)
      {
         /* Implements SPI_ESDD_UD_188 */
         /* QAC Warning: START Msg(2:3892)- 21 */
         /* Initialize BRS register to value after reset */
        SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->stCSIHBRS[LucCount].usCSIHBRS,
                                                     SPI_CTL_16BIT_REG_DEINIT)

        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
        LpCsihOsBaseAddr->stCSIHBRS[LucCount].usCSIHBRS,
        SPI_CTL_16BIT_REG_DEINIT, SPI_CSIHBRS_MASK, SPI_DEINIT_SID)
        /* END Msg(2:3892)- 21 */
      }
      #endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
    }
    #if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      /* MISRA Violation: START Msg(4:0316)-9 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      SPI_CSIGH_REG_WRITE(LpHWUnitInfo->pHwMainUserBaseAddress->usMainSTCR0,
                                                       SPI_CSIG_STCR0_VAL)
      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
      LpHWUnitInfo->pHwMainUserBaseAddress->ulMainSTR0,
      SPI_CTL_16BIT_REG_DEINIT, SPI_CSIG_STCR0_VAL, SPI_DEINIT_SID)
      /* END Msg(2:3892)- 21 */
      LpCsigUserBaseAddr =
                        (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
      LpCsigOsBaseAddr = (Spi_CsigOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
      /* END Msg(4:0316)-9 */
      /* Initialize BCTL0 register to value after reset */
      /* QAC Warning: START Msg(2:2814)-20 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ucCSIGBCTL0,SPI_BCTL0_SET_SCE)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigUserBaseAddr->ucCSIGBCTL0,
      SPI_BCTL0_SET_SCE,SPI_CSIGBCTL0_MASK,SPI_DEINIT_SID)

      /* Initialize CSIG configuration register */
      SPI_CSIGH_REG_WRITE(LpCsigOsBaseAddr->ulCSIGCFG0, SPI_CTL_32BIT_REG_VAL)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigOsBaseAddr->ulCSIGCFG0,
        SPI_CTL_32BIT_REG_VAL,SPI_CSIGCFG0_MASK, SPI_DEINIT_SID)
      /* END Msg(2:3892)- 21 */
      /* END Msg(2:2814)-20 */
      #endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
    }
    /* Clear the interrupts in asynchronous mode */
    #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
         (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pRxImrAddress;
    /* Disable interrupt processing */
    /* QAC Warning: START Msg(2:2814)-20 */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                       (uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usRxImrMask)));
    /* END Msg(2:2814)-20 */
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxImrAddress;

    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                     (uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usTxImrMask)));

    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pErrorImrAddress;

    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                     (uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usErrorImrMask)));
    #endif

    #if (((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) &&\
      (SPI_CANCEL_API == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON))

    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      if (NULL_PTR != Spi_GstHWUnitInfo[LddHWUnit].pTxCancelImrAddress)
      {
        LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxCancelImrAddress;
        /* Disable interrupt processing */
        RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                   (uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usTxCancelImrMask)));
      }
      else
      {
        /* No Action Required */
      }
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /* No Action Required */
    }
    #endif
    #endif
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxIntCntlAddress;

    /* Clear Tx pending interrupt */
    /* QAC Warning: START Msg(2:2814)-20 */
    RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));
    /* END Msg(2:2814)-20 */
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pRxIntCntlAddress;
    /* Clear Rx pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));

    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pErrorIntCntlAddress;
    /* Clear Error pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));

    #if (((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) &&\
      (SPI_CANCEL_API == STD_ON))

    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      if (NULL_PTR != Spi_GstHWUnitInfo[LddHWUnit].pTxCancelIntCntlAddress)
      {
        /* Address for transmit cancel interrupt control registers (TIJC) */
        LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxCancelIntCntlAddress;
        /* Clear transmit cancel pending interrupt */
        RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));
      }
      else
      {
        /* No Action Required */
      }
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /* No Action Required */
    }
    #endif
    #endif
    /* MISRA Violation: START Msg(4:2984)-16 */
    LddHWUnit++;
    /* END Msg(4:2984)-16 */
  } /* (LddHWUnit < SPI_MAX_HW_DETAILS) */

  /* Deactivate chip select */
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  LddNumJobs = SPI_ZERO;
  /* Get the pointer of the first job linked to this sequence */
  LpJobConfig = Spi_GpFirstJob;
  while (SPI_MAX_JOB > LddNumJobs)
  {
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
     /* QAC Warning: START Msg(2:2814)-20 */
     LddHWUnit = LpJobConfig->ddHWUnitIndex;
     /* END Msg(2:2814)-20 */
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      if (NULL_PTR != LpJobConfig->pPortGrpRegAddress)
      {
        Spi_HWDeActivateCS(LpJobConfig);
      }
      else
      {
        /* No action required */
      }
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      /* No action required */
    }

    /* MISRA Violation: START Msg(4:0489)-3 */
    LpJobConfig++;
    /* END Msg (4:0489)-3 */
    LddNumJobs++;

  }/* (LddNumJobs < SPI_MAX_JOB) */
  #endif /*(SPI_CSIG_CONFIGURED == STD_ON) */

  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  /* QAC Warning: START Msg(2:2814)-20 */
  LucMaxDmaChannels = Spi_GpConfigPtr->ucMaxDmaChannels;
  /* END Msg(2:2814)-20 */
  for (LucLoopCount = SPI_ZERO; LucLoopCount <
                                              LucMaxDmaChannels; LucLoopCount++)
  {
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpDmaConfig = Spi_GpDmaUnitConfig + LucLoopCount;
    /* END Msg(2:2824)-17 */
    /* END Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpDmaRegisters = LpDmaConfig->pDmaCntlRegBase;
    /* Clear the DTS and TC bit */

    /* MISRA Violation: START Msg(4:0402)-13 */
    /* Disable channel operation */

    /* Implements SPI_ESDD_UD_161 */
    SPI_DMA_REG_WRITE( LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_DISABLE)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                          SPI_DMA_DCEN_DISABLE, SPI_DCEN_MASK, SPI_DEINIT_SID)

    /* END Msg(2:2814)-20 */
    /* Clear DMA Transfer Request */
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRRQCn,SPI_DMA_DRQ_CLEAR)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRRQn,
                     (uint32)SPI_ZERO, SPI_DMA_DRQ_CLEAR, SPI_DEINIT_SID)

    /* Clear Software request flag */

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCSTCn, SPI_DMA_STR_CLEAR)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCSTn,(uint32)SPI_ZERO,
                                            SPI_DMA_STR_CLEAR, SPI_DEINIT_SID)

    /* Initialise the source address register */
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDSAn,SPI_DMA_DEINIT)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDSAn,
                     SPI_DMA_DEINIT,SPI_CTLREG_32_BIT_MASK, SPI_DEINIT_SID)

    /* Initialise the transmission register */
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDDAn,SPI_DMA_DEINIT)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME( LpDmaRegisters->ulDDAn,
           SPI_DMA_DEINIT, SPI_CTLREG_32_BIT_MASK, SPI_DEINIT_SID)

    /* Initialise the transfer control register */
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn,SPI_DMA_DEINIT)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
                                 SPI_DMA_DEINIT, SPI_DTCT_MASK, SPI_DEINIT_SID)

     /* Initialise the trigger factor configured register*/
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRn, SPI_DMA_DEINIT)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRn,
                                   SPI_DMA_DEINIT,SPI_DTFR_MASK,SPI_DEINIT_SID)

    /* END Msg(4:0402)-13 */
  }
  #endif /* #if (SPI_DMA_MODE_ENABLE == STD_ON) */
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Spi_InternalWriteIB
**
** Service ID         : Not Applicable
**
** Description        : This service writes the data into HW Buffer
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Channel - Channel ID
**                      DataBufferPtr - Pointer to source data buffer
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstChannel, Spi_GpConfigPtr
**
** Function Invoked   : Spi_HWWriteIB
**
** Registers Used     : None
*******************************************************************************/
/* Implements SPI_ESDD_UD_023 */
/* Implements SPI_ESDD_UD_092 */
#if (SPI_IB_CONFIGURED == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements SPI023, SPI035, SPI203_Conf, SPI164, SPI112, AR_PN0063_FR_0121 */
/* Implements AR_PN0063_FR_0114, AR_PN0063_FR_0115 AR_PN0063_FR_0117 */
/* Implements AR_PN0063_FR_0116 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE) Spi_InternalWriteIB(Spi_ChannelType Channel,
           P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) LpDataBufferPtr,
           uint8 LucApId)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  /* Implements SPI_ESDD_UD_152 */
  #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && \
       ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) || \
       (SPI_LEVEL_DELIVERED == SPI_ZERO)))
  /* Defining a local pointer to point to the source buffer */
  P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) LpSrcPtr;
  /*
   * Defining a local pointer variable to point to internal buffer of the
   * requested channel
   */
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpChannelIB;
  Spi_NumberOfDataType LddNoOfBuffers;
  #endif

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the post-build structure of the channel */
  LpPBChannelConfig = Spi_GpFirstChannel + Channel;
  /* END Msg (2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Check if the buffer type is internal buffer (not hardware buffer) */
  if ((SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      || (SPI_ONE < LpPBChannelConfig->ucChannelBufferType)
      #endif
      )
  /* END Msg(2:2814)-20 */
  {
    #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && \
         ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) || \
         (SPI_LEVEL_DELIVERED == SPI_ZERO)))

    /* Get the local reference to the source buffer */
    LpSrcPtr = LpDataBufferPtr;
    /* QAC Warning: START Msg(2:2814)-20 */
    LpChannelIB = Spi_GpConfigPtr->pChannelIBWrite;
    /* END Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpChannelIB = LpChannelIB + LpPBChannelConfig->ddBufferIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */
    LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;

    do
    {
      if (NULL_PTR != LpSrcPtr)
      {
        /* Copy the data from the source buffer to the internal buffer */
        *LpChannelIB = *LpSrcPtr;
        /* MISRA Violation: START Msg(4:0489)-3*/
        /* Increment the source pointer */
        LpSrcPtr++;
        /* END Msg (4:0489)-3 */
      }
      else
      {
        *LpChannelIB = LpPBChannelConfig->ddDefaultData;
      }

      /* MISRA Violation: START Msg(4:0489)-3*/
      /* Increment the buffer pointer */
      LpChannelIB++;
      /* END Msg (4:0489)-3 */

      /* Decrement the counter for number of buffers */
      LddNoOfBuffers--;
    } while (SPI_ZERO < LddNoOfBuffers);
    #endif /*
            * ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && \
            * ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) \
            * || (SPI_LEVEL_DELIVERED == SPI_ZERO)))
            */

    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    if (SPI_ONE < LpPBChannelConfig->ucChannelBufferType)
    {
      /* Buffer type is 'hardware buffer' */
      Spi_HWWriteIB(Channel, LpDataBufferPtr, LucApId);
    }
    else
    {
      /* No action required */
    }
    #endif /* (SPI_HW_PRIORITY_ENABLED == STD_ON) */
  } /* End of operations if the buffer type is 'internal buffer' */
  else
  {
    #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    /* Buffer type is 'hardware buffer' */
    Spi_HWWriteIB(Channel, LpDataBufferPtr, LucApId);
    #endif
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name      : Spi_HWWriteIB
**
** Service ID         : Not Applicable
**
** Description        : This service writes the data into HW Buffer
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Channel - Channel ID
**                      DataBufferPtr - Pointer to source data buffer
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstChannel
**
** Function Invoked   : None
**
** Registers Used     : CSIHnMRWP0, CSIHnTX0W, CSIHMCTL0.
**
*******************************************************************************/
/* Implements SPI_ESDD_UD_022 */
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI149, SPI289, SPI290, SPI291, AR_PN0063_FR_0063 */
/* QAC Warning: START Msg(2:3206)-22 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_HWWriteIB(Spi_ChannelType Channel,
           P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) LpDataBufferPtr,
           uint8 LucApId)
/* END Msg(2:3227)-16 */
/* END Msg(2:3206)-22 */
{
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  /* Defining a local pointer to point to structure of HW Unit information */
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  uint16 LusMctlData;
  uint8 Lucflag;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  #if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
  Spi_DataAccess LunDataAccess2;
  #endif
  /* END Msg(4:0759)-1 */
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  uint32 LulShiftData;
  #endif

  Spi_HWUnitType LddHWUnitNumber;
  uint8 LucHWMemoryMode;
  Spi_NumberOfDataType LddNoOfBuffers;
  Spi_HWUnitType LddHWUnit;

  /* Implements SPI_ESDD_UD_184 */
  Spi_DataType LddData;
  Lucflag = SPI_ZERO;

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the post-build structure of the channel */
  LpPBChannelConfig = Spi_GpFirstChannel + Channel;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the index of the HW Unit */
  LddHWUnit = (Spi_HWUnitType)
   ((LpPBChannelConfig->ucChannelBufferType - SPI_TWO) + SPI_MAX_NUM_OF_CSIG);
  /* END Msg(2:2814)-20 */
  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;

  /* Get the OS base address of the HW Unit */
  LpCsihOsBaseAddr = (Spi_CsihOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
  /* END Msg(4:0316)-9 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Implements SPI_ESDD_UD_203 */
  LusMctlData = LpCsihOsBaseAddr->usCSIHMCTL0;
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  /* END Msg(2:2814)-20 */
  LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
  /* If Tx Only or Dual Buffer Mode */
  if (SPI_ZERO == (LusMctlData & SPI_CHECK_BUFFER_MODE))
  {
    if(SPI_TX_ONLY_MODE_CONFIGURED == LucHWMemoryMode)
    {
     /* Initialize CSIH memory register for TX Only Mode */
     SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->usCSIHMCTL0, SPI_TX_ONLY_MODE_SET)

     SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihOsBaseAddr->usCSIHMCTL0,
                              SPI_TX_ONLY_MODE_SET, SPI_CSIHMCTL0_MASK, LucApId)
    }
    else
    {
     /* Initialize CSIH memory register for Dual Buffer Mode */
     SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->usCSIHMCTL0,
                                                    SPI_DUAL_BUFFER_MODE_SET)

     SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihOsBaseAddr->usCSIHMCTL0,
                          SPI_DUAL_BUFFER_MODE_SET, SPI_CSIHMCTL0_MASK, LucApId)
    }
    /* MISRA Violation: START Msg(4:2984)-10 */
    Lucflag++;
    /* END Msg(4:2984)-10 */
  }
  else
  {
    /* No action required */
  }
  /* Read the existing value from the Read-Write pointer register to */
  /* a local variable */
  /* QAC Warning: START Msg(2:2814)-20 */
  LunDataAccess1.ulRegData = LpCsihUserBaseAddr->ulCSIHMRWP0;
  /* END Msg(2:2814)-20 */
  /* Load the local variable with the value of Tx-Buffer Read/Write Pointer */
  LunDataAccess1.usRegData5[SPI_ZERO] = LpPBChannelConfig->ddBufferIndex;

  /* Load back the value of the local variable to Read-Write pointer register */
  SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMRWP0,
                                              LunDataAccess1.ulRegData)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihUserBaseAddr->ulCSIHMRWP0,
                           LunDataAccess1.ulRegData,SPI_CSIHMRWP0_MASK,LucApId)

  /* Get the number of buffers configured for the requested channel */
  LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;

  do
  {
    /* Take a local union variable to construct the value for TX0W register */
    LunDataAccess1.ulRegData = SPI_ZERO;

    LunDataAccess1.Tst_ByteAccess.ucRegData2 = LpPBChannelConfig->ucCSInfo;
    /* Check if the source pointer is NULL pointer */
    if (NULL_PTR == LpDataBufferPtr)
    {
      /* get the configured default value */
      LddData = LpPBChannelConfig->ddDefaultData;
    }
    else
    {
      /* Get the value from the source pointer */
      LddData = *LpDataBufferPtr;
      /* MISRA Violation: START Msg(4:0489)-3*/
      LpDataBufferPtr++;
      /* END Msg (4:0489)-3 */
    }
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /* Data width is maximum 8-bit. Hence, load Tx data portion of the local
     * variable with the 8-bit data to be transmitted
     */
    LunDataAccess1.ucRegData4[SPI_ZERO] = LddData;

    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    /* Implements SPI_ESDD_UD_193 */
    /* Data width is maximum 16-bit. Hence, load Tx data portion of the local
     * variable with the 16-bit data to be transmitted
     */
    LunDataAccess1.Tst_ByteAccess.usRegData1 = LddData;

    #else
    if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
                  (SPI_TRUE != LpPBChannelConfig->blDirection) &&
                  (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                  (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
    {
      LulShiftData = (uint32)LddData;
      LulShiftData = (uint32)(LulShiftData << (SPI_SIXTEEN -
                                        (LpPBChannelConfig->ucDLSSetting)));
      LunDataAccess2.ulRegData = LulShiftData;
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
      (LunDataAccess2.usRegData5[SPI_ZERO] >> (SPI_SIXTEEN -
                                         (LpPBChannelConfig->ucDLSSetting)));
      LunDataAccess2.usRegData5[SPI_ZERO] =
                                   LunDataAccess1.Tst_ByteAccess.usRegData1;
    }
    else
    {
      /* Data width is maximum 32-bit. Tx data needs to be split to
       * LS Byte and MS Byte. Hence, load the Tx data to local union variable
       */
      LunDataAccess2.ulRegData = LddData;
    }
    /* Since data width is maximum 32-bit, check if the the data width of
     * requested channel is more than 16 bits
     */
    if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
    {
      /* Data width is maximum 16-bit. Hence, load LSB portion of the
       * local variable with the 16-bit data to be transmitted
       */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                         LunDataAccess2.usRegData5[SPI_ZERO];
    }
    else
    {
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /* Load Tx data portion of the local variable with LSB first */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
      }
      else
      {
        /* Load Tx data portion of the local variable with MSB first */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                        LunDataAccess2.usRegData5[SPI_ONE];
      }

      /* MISRA Violation: START Msg(4:2984)-10 */
      /* Set the EDL bit in the local union variable */
      LunDataAccess1.Tst_ByteAccess.ucRegData3 =
                      (LunDataAccess1.Tst_ByteAccess.ucRegData3 | SPI_SET_EDL);
      /* END Msg(4:2984)-10 */
      /* Implements SPI_ESDD_UD_204 */
      /* Load the value of the local union variable to TX0W register */
      SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                                       LunDataAccess1.ulRegData)

      /* Decrement the counter for number of buffers */
      LddNoOfBuffers--;
      /* MISRA Violation: START Msg(4:2984)-10 */
      /* Reset the EDL bit in the local union variable */
      LunDataAccess1.Tst_ByteAccess.ucRegData3 =
                    (LunDataAccess1.Tst_ByteAccess.ucRegData3 & SPI_RESET_EDL);
      /* END Msg(4:2984)-10 */

      /* Check the data direction again to load other part of data */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /* Load Tx data portion of the local variable with MSB */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                             LunDataAccess2.usRegData5[SPI_ONE];
      }
      else
      {
        /* Load Tx data portion of the local variable with LSB */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                          LunDataAccess2.usRegData5[SPI_ZERO];
      }
    } /* End of !if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)*/
    #endif /* End of (SPI_8BIT_DATA_WIDTH == STD_ON) */
    /* Check if the buffer is last buffer of the channel */
    if (SPI_ONE == LddNoOfBuffers)
    {
      /* Check if it is last channel in the job */
      if (SPI_ONE == LpPBChannelConfig->ucChannelInfo)
      {
        /* MISRA Violation: START Msg(4:2984)-10 */
        /*
         * Since buffer is last buffer of the job and not last buffer of
         * the sequence, set only EOJ
         */
        LunDataAccess1.Tst_ByteAccess.ucRegData3 =
                       (LunDataAccess1.Tst_ByteAccess.ucRegData3 | SPI_SET_EOJ);
        /* END Msg(4:2984)-10 */
      }
      else if (SPI_TWO == LpPBChannelConfig->ucChannelInfo)
      {
        /* MISRA Violation: START Msg(4:2984)-10 */
        /* Since last buffer of sequence, set both CIRE and EOJ */
        LunDataAccess1.Tst_ByteAccess.ucRegData3 =
                   (LunDataAccess1.Tst_ByteAccess.ucRegData3 | SPI_SET_CIREEOJ);
        /* END Msg(4:2984)-10 */
      }
      else
      {
        /* No action Required */
      }
    } /* End of if (SPI_ONE == LddNoOfBuffers) */
    else
    {
      /* No action required */
    }
    /* Load the value of the local union variable to TX0W register */
    SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                                    LunDataAccess1.ulRegData)

    /* Decrement the counter for number of buffers */
    LddNoOfBuffers--;

  }while (SPI_ZERO < LddNoOfBuffers);
  if (SPI_ZERO != Lucflag)
  {
    /* Reset CSIH memory register */
    /* MISRA Violation: START Msg(4:2984)-10 */
    SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->usCSIHMCTL0, LusMctlData)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihOsBaseAddr->usCSIHMCTL0,
    LusMctlData, SPI_CSIHMCTL0_MASK, LucApId)
    /* END Msg(4:2984)-10 */
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /*
        * End of ((SPI_DUAL_BUFFER_MODE == STD_ON) ||
        * (SPI_TX_ONLY_MODE == STD_ON))
        */

/*******************************************************************************
** Function Name      : Spi_HWReadIB
**
** Service ID         : Not Applicable
**
** Description        : This service reads the data from HW Buffer
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Channel - Channel ID
**                      DataBufferPtr - Pointer to destination data buffer
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstChannel, Spi_GstHWUnitInfo
**
** Function Invoked   : None
**
** Registers Used     : CSIHnRX0W, CSIHnRX0H, CSIHnMRWP0.
*******************************************************************************/
/* Implements SPI_ESDD_UD_024 */
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_HWReadIB(Spi_ChannelType Channel,
           P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_CONST) LpDataBufferPtr)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;

  /* Defining a local pointer variable to hold the destination data */
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpDesPtr;
  Spi_NumberOfDataType LddNoOfBuffers;

  Spi_DataType LddData;


  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  Spi_DataAccess LunDataAccess2;
  /* END Msg(4:0759)-1 */

  Spi_HWUnitType LddHWUnit;

  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  uint32 LulShiftData;
  uint32 LulShiftDataLow;
  uint32 LulShiftDataHigh;
  #endif /* (SPI_EXTENDED_DATA_LENGTH == STD_ON) */

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the post-build structure of the channel */
  LpPBChannelConfig = Spi_GpFirstChannel + Channel;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the index of the HW Unit */
  LddHWUnit = (Spi_HWUnitType)
    ((LpPBChannelConfig->ucChannelBufferType - SPI_TWO) + SPI_MAX_NUM_OF_CSIG);

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(4:0316)-9 */

  /*
   * Read the existing value from the Read-Write pointer register to
   * a local variable
   */
  LunDataAccess1.ulRegData = LpCsihUserBaseAddr->ulCSIHMRWP0;

  /* Load the local variable with the value of Tx-Buffer Read/Write Pointer */
  LunDataAccess1.usRegData5[SPI_ONE] = LpPBChannelConfig->ddBufferIndex;
  /* END Msg(2:2814)-20 */
  /* Load back the value of the local variable to Read-Write pointer register */
  SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMRWP0, LunDataAccess1.ulRegData)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihUserBaseAddr->ulCSIHMRWP0,
                   LunDataAccess1.ulRegData,SPI_CSIHMRWP0_MASK, SPI_READIB_SID)

  /* Copy the destination pointer value to a local pointer variable */
  LpDesPtr = LpDataBufferPtr;

  /* Get the number of buffers configured for the requested channel */
  LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;

  do
  {
    LunDataAccess2.ulRegData = LpCsihUserBaseAddr->ulCSIHRX0W;
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, Receive the data from the
     * Rx register to local union variable
     */

    LddData = LunDataAccess2.ucRegData4[SPI_ZERO];
    /*
     * Data width is maximum 16-bit. Hence, Receive the data from the
     * Rx register to local union variable
     */
    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    /* Load data from union variable to local variable */
    LddData = LunDataAccess2.usRegData5[SPI_ZERO];

    #else
    /* Load data from union variable to local variable */

    /*
     * Data width is maximum 32-bit, Check if the the data width of
     * requested channel is more than 16 bits
     */
    if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
                  (SPI_TRUE != LpPBChannelConfig->blDirection) &&
                  (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                  (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
    {
      LulShiftData =  LunDataAccess1.ulRegData;
      LulShiftDataHigh = LulShiftData & SPI_HIGH_DATA_MASK;
      LulShiftDataLow = LulShiftData & SPI_LOW_DATA_MASK;
      LulShiftDataLow = LulShiftDataLow << (SPI_SIXTEEN -
                                     (LpPBChannelConfig->ucDLSSetting));
      LulShiftData = LulShiftDataHigh | LulShiftDataLow;
      LulShiftData = LulShiftData >> (SPI_SIXTEEN -
                               (LpPBChannelConfig->ucDLSSetting));
      /* MISRA Violation: START Msg(4:2982)-2 */
      LddData  = LulShiftData;
      /* END Msg(4:2982)-2 */
    }
    /*
     * Data width is maximum 32-bit. Hence, Receive the data from the
     * Rx register to local union variable
     */
    else
    {
      /* MISRA Violation: START Msg(4:2982)-2 */
      LddData = LunDataAccess1.ulRegData;
      /* END Msg(4:2982)-2 */
    }
    LddData = LunDataAccess2.usRegData5[SPI_ZERO];

    if (SPI_TRUE == LpPBChannelConfig->blEDLEnabled)
    {
      LddNoOfBuffers--;
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /*
         * Take a local union variable to construct the value from RX0W
         * register
         */
        LunDataAccess2.usRegData5[SPI_ZERO] = (uint16)LddData;
        LunDataAccess2.usRegData5[SPI_ONE] = LpCsihUserBaseAddr->usCSIHRX0H;
      }
      else
      {
        /*
         * Take a local union variable to construct the value from RX0W
         * register
         */
         if (SPI_ZERO != LpPBChannelConfig->ucDLSSetting)
         {
           LunDataAccess2.usRegData5[SPI_ONE] = (uint16)LddData;
           LunDataAccess2.usRegData5[SPI_ZERO] = LpCsihUserBaseAddr->usCSIHRX0H;
           LunDataAccess2.usRegData5[SPI_ZERO] =
           ((LunDataAccess2.usRegData5[SPI_ZERO]) <<
                             (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting)));
           LunDataAccess2.ulRegData = ((LunDataAccess2.ulRegData) >>
                         (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting)));
         }
         else
         {
           LunDataAccess2.usRegData5[SPI_ONE] = (uint16)LddData;
           LunDataAccess2.usRegData5[SPI_ZERO] = LpCsihUserBaseAddr->usCSIHRX0H;
         }
      }
      /* Load data from union variable to local variable */
      LddData = LunDataAccess2.ulRegData;
    }
    else
    {
      /* No action required */
    }
    #endif /* End of (SPI_8BIT_DATA_WIDTH == STD_ON)*/
    /* QAC Warning: START Msg(2:2814)-20 */
    *LpDesPtr = LddData;
    /* MISRA Violation: START Msg(4:0489)-3 */
    LpDesPtr++;
    /* END Msg (4:0489)-3 */
    /* END Msg(2:2814)-20 */

    /* Decrement the counter for number of buffers */
    LddNoOfBuffers--;
  }while (SPI_ZERO < LddNoOfBuffers);
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of ((SPI_DUAL_BUFFER_MODE == STD_ON) || \
        * (SPI_TX_ONLY_MODE == STD_ON))
        */

/*******************************************************************************
** Function Name      : Spi_HWActivateCS
**
** Service ID         : Not Applicable
**
** Description        : This service performs activation of the Chip Select pin
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_JobConfigType *LpJobConfiguration
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : SPI_ENTER_CRITICAL_SECTION,
**                      SPI_EXIT_CRITICAL_SECTION
**
** Registers Used     : PORTPSRx
*******************************************************************************/
/* Implements SPI_ESDD_UD_025 */
#if (SPI_CSIG_CONFIGURED == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements SPI210_Conf, AR_PN0063_FR_0133, AR_PN0063_FR_0092 */
/* Implements EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_HWActivateCS
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST)
                             LpJobConfiguration, uint8 LucLoopCount)
/* END Msg(2:3227)-16 */
{
  /* Defining a local pointer variable to the port group address */
  P2VAR(volatile uint32, AUTOMATIC, SPI_CONFIG_DATA) LpPortGpAdd;
  uint32 LulPinMskVal;
  /* QAC Warning: START Msg(2:2814)-20 */
  if (NULL_PTR != LpJobConfiguration->pPortGrpRegAddress)
  /* END Msg(2:2814)-20 */
  {
    /* Get the port group address */
    LpPortGpAdd = LpJobConfiguration->pPortGrpRegAddress;
    /* Get the pin mask value */
    LulPinMskVal = LpJobConfiguration->ulPortPinMask;

    /* Wait till counter reaches zero */
    while (SPI_ZERO < LucLoopCount)
    {
      LucLoopCount--;
    }

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_CHIP_SELECT_PROTECTION);
    #endif

    /* If Chip select polarity is configured as active High */
    if (SPI_ONE == LpJobConfiguration->blCsPolarity)
    {
      /* Load the port register */
      *LpPortGpAdd = LulPinMskVal;
    }
    else /* If Chip select polarity is configured as active Low */
    {
      /* Load the port register */
      *LpPortGpAdd = LulPinMskVal & SPI_PORT_REG_MASK;
    }

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_CHIP_SELECT_PROTECTION);
    #endif
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (SPI_CSIG_CONFIGURED == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_HWDeActivateCS
**
** Service ID         : Not Applicable
**
** Description        : This service performs de-activation of the Chip Select
**                      pin.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_JobConfigType *LpJobConfiguration
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : SPI_ENTER_CRITICAL_SECTION,
**                      SPI_EXIT_CRITICAL_SECTION
**
** Registers Used     : PORTPSRx
*******************************************************************************/
/* Implements SPI_ESDD_UD_026 */
/* Implements SPI370, EAAR_PN0034_FR_0061 */
#if (SPI_CSIG_CONFIGURED == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_HWDeActivateCS
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfiguration)
/* END Msg(2:3227)-16 */
{
  P2VAR(volatile uint32, AUTOMATIC, SPI_CONFIG_DATA) LpPortGpAdd;
  uint32 LulPinMskVal;
  /* QAC Warning: START Msg(2:2814)-20 */
  if (NULL_PTR != LpJobConfiguration->pPortGrpRegAddress)
  /* END Msg(2:2814)-20 */
  {
    /* Get the port group address */
    LpPortGpAdd = LpJobConfiguration->pPortGrpRegAddress;
    /* Get the pin mask value */
    LulPinMskVal = LpJobConfiguration->ulPortPinMask;

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_CHIP_SELECT_PROTECTION);
    #endif

    /* If Chip select polarity is configured as active High */
    if (SPI_ONE == LpJobConfiguration->blCsPolarity)
    {
      /* Load the port register */
      *LpPortGpAdd = LulPinMskVal & SPI_PORT_REG_MASK;
    }
    /* If Chip select polarity is configured as active Low */
    else
    {
      /* Load the port register */
      *LpPortGpAdd = LulPinMskVal;
    }

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_CHIP_SELECT_PROTECTION);
    #endif
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (SPI_CSIG_CONFIGURED == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_HWUnitStatus
**
** Service ID         : Not Applicable
**
** Description        : This service gets the Hardware unit status
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType HWUnit
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Spi_StatusType (SPI_IDLE/SPI_BUSY)
**
** Preconditions      : Spi_Init should have been invoked.
**
** Global Variable    : Spi_GstHWUnitInfo
**
** Function invoked   : None
**
** Registers Used     : CSIGnSTR0, CSIHnSTR0
*******************************************************************************/
/* Implements SPI_ESDD_UD_032 */
#if (SPI_HW_STATUS_API == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements SPI349, SPI029 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Spi_StatusType, SPI_PRIVATE_CODE) Spi_HWUnitStatus
                                                     (Spi_HWUnitType HWUnit)
/* END Msg(2:3227)-16 */
{
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;

  Spi_StatusType LddHWUnitSts;

  LpMainUserBaseAddr = (Spi_GstHWUnitInfo[HWUnit]).pHwMainUserBaseAddress;

  /* QAC Warning: START Msg(2:2814)-20 */
  /* Is bit TSF = 1 */
  if (SPI_CSIG_CSIH_BUSY ==
                        ((LpMainUserBaseAddr->ulMainSTR0) & SPI_CSIG_CSIH_BUSY))
  /* END Msg(2:2814)-20 */
  {
    LddHWUnitSts = SPI_BUSY;
  }
  else /* Is bit TSF = 0 */
  {
    LddHWUnitSts = SPI_IDLE;
  }

  return(LddHWUnitSts);
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (SPI_HW_STATUS_API == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_HWTransmitSyncJob
**
** Service ID         : Not Applicable
**
** Description        : This service is used for transmitting the sequences
**                      synchronously
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_JobConfigType *LpJobConfiguration
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions      : None
**
** Global Variables   : Spi_GstHWUnitInfo, Spi_GpFirstChannel, Spi_GpConfigPtr,
**                      Spi_GblSyncTx
**
** Function Invoked   : Spi_HWActivateCS, Spi_SyncRegSettings
**                      Spi_HWDeActivateCS, Spi_SyncProcessData
**
** Registers Used     : CSIGnCTL0, CSIGnCFG0, CSIHnCTL0, CSIHnCFG, EICn
*******************************************************************************/
/* Implements SPI_ESDD_UD_027 */
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* Implements AR_PN0063_FR_0089 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_HWTransmitSyncJob
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
                          Spi_SequenceType LddSequenceID, Spi_JobType LddJobID)
/* END Msg(2:3227)-16 */
#else
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_HWTransmitSyncJob
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig)
/* END Msg(2:3227)-16 */
#endif
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  uint8 LucCxCtl0;
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  /* Defining a local pointer variable to hold the OS base address of CSIG */
  P2VAR(Spi_CsigOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigOsBaseAddr;
  #endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Defining a local pointer variable to hold the OS base address of CSIH */
  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  /* Declare a local pointer to point to the Configured chip select of job */
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpChipSelect;
  uint8 LucVar;
  #endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg (4:0759)-1 */
  #endif /* (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) */

  /* Declare a local pointer to point to the channel Config Data */
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  /* Declare a local pointer to point to the channel list */
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_PRIVATE_CONST) LpChannelList;
  Spi_ChannelType LddNoOfChannels;
  Std_ReturnType LenReturnValue;
  Spi_HWUnitType LddHWUnit;
  /* MISRA Violation: START Msg(4:2982)-2 */
  LenReturnValue = E_OK;
  /* END Msg(4:2982)-2 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the HW Unit index */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;
  /* END Msg(2:2814)-20 */
  /* Get the number of channels */
  LddNoOfChannels = LpJobConfig->ddNoOfChannels;
  LpChannelList = LpJobConfig->pChannelList;
  /* Get the base address of the HW Unit */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* Get the main user base address */
  LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
  /* do the Cfg and Cntl register settings */
  Spi_SyncRegSettings(LpJobConfig);
  #endif /* #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED) */

  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
  #endif
  {
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    /* Activate the chip select */
    /* QAC Warning: START Msg(2:2814)-20 */
    Spi_HWActivateCS(LpJobConfig, (LpJobConfig->ucClk2CsLoopCnt));
    /* END Msg(2:2814)-20 */
    #endif
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  {

  }
  #endif
  /* Clear Interrupt flags */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                                        (SPI_CLR_INT_REQ));
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                                        (SPI_CLR_INT_REQ));
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                                        (SPI_CLR_INT_REQ));
  do
  {
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the channel linked to the job */
    LpPBChannelConfig = Spi_GpFirstChannel + (*LpChannelList);
    /* END Msg(2:2824)-17 */
    /* END Msg(2:2814)-20 */
    /* END Msg (4:0488)-4 */

    #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
    if (((LddNoOfChannels == LpJobConfig->ddNoOfChannels) ||
                            (SPI_FALSE == LpJobConfig->blIsChannelPropSame)))
    {
      /* Clear pending interrupts when channel properties not same */
       RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                               (SPI_CLR_INT_REQ));
       RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                               (SPI_CLR_INT_REQ));
       RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                               (SPI_CLR_INT_REQ));
      #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
      if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
      #endif
      {
        #if (SPI_CSIG_CONFIGURED == STD_ON)
        /* MISRA Violation: START Msg(4:0316)-9 */
        /* Get the base address of the HW Unit */
        LpCsigOsBaseAddr = (Spi_CsigOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
        /* END Msg(4:0316)-9 */
        /* Implements SPI_ESDD_UD_201 */
        /* QAC Warning: START Msg(2:2814)-20 */
        /*
         * To load configuration register, read the existing value to
         * local union variable
         */
        LunDataAccess1.ulRegData = LpCsigOsBaseAddr->ulCSIGCFG0;
        /* END Msg(2:2814)-20 */
        /* Load the local variable with data width */
        LunDataAccess1.ucRegData4[SPI_THREE] =
                          LunDataAccess1.ucRegData4[SPI_THREE] & SPI_DLS_MASK;
        /* QAC Warning: START Msg(2:2814)-20 */
        LunDataAccess1.ucRegData4[SPI_THREE] =
                       (LunDataAccess1.ucRegData4[SPI_THREE] |
                                             LpPBChannelConfig->ucDLSSetting);
        /* END Msg(2:2814)-20 */
        /* Load the local variable with configured direction */
        if (SPI_TRUE == LpPBChannelConfig->blDirection)
        {
          /* Direction is LSB, set DIR bit */
          LunDataAccess1.ucRegData4[SPI_TWO] =
                         LunDataAccess1.ucRegData4[SPI_TWO] | SPI_SET_DIR_LSB;
        }
        else
        {
          /* Direction is MSB, reset DIR bit */
          LunDataAccess1.ucRegData4[SPI_TWO] =
                       LunDataAccess1.ucRegData4[SPI_TWO] & SPI_RESET_DIR_LSB;
        }
        /* QAC Warning: START Msg(2:2814)-20 */
        /* MISRA Violation: START Msg(4:0402)-13 */
        /* Reset the PWR bit since other registers need to be written */
        LucCxCtl0 =  (LpMainUserBaseAddr->ucMainCTL0 & SPI_RESET_PWR);
        SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)
        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                        LucCxCtl0, SPI_CTLREG_8_BIT_MASK, SPI_SYNCTRANSMIT_SID)
        /* END Msg(4:0402)-13 */
        /* END Msg(2:2814)-20 */
        /* Load back the value to configuration register */

        SPI_CSIGH_REG_WRITE(LpCsigOsBaseAddr->ulCSIGCFG0,
                                                  LunDataAccess1.ulRegData)
        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigOsBaseAddr->ulCSIGCFG0,
        LunDataAccess1.ulRegData, SPI_CSIGCFG0_MASK, SPI_SYNCTRANSMIT_SID)
        /* Set the PWR bit */
        /* MISRA Violation: START Msg(4:0402)-13 */
        /* QAC Warning: START Msg(2:3892)- 21 */
        LucCxCtl0 = ((LpMainUserBaseAddr->ucMainCTL0 | SPI_SET_PWR) |
                                                                   SPI_SET_MBS);
        SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)

        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                        LucCxCtl0, SPI_CTLREG_8_BIT_MASK, SPI_SYNCTRANSMIT_SID)
        /* END Msg(4:0402)-13 */
        /* END Msg(2:3892)- 21 */
        /* Set the memory mode */

        SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0,
                                                          SPI_SET_DIRECT_ACCESS)
        /* QAC Warning: START Msg(2:3892)- 21 */
        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
             SPI_SET_DIRECT_ACCESS, SPI_CTLREG_8_BIT_MASK, SPI_SYNCTRANSMIT_SID)
        /* END Msg(2:3892)- 21 */
        #endif
      }
      #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
      else
      #endif
      {
        #if (SPI_CSIH_CONFIGURED == STD_ON)
        /* MISRA Violation: START Msg(4:0316)-9 */
        /* Get the OS base address of the HW Unit */
        LpCsihOsBaseAddr = (Spi_CsihOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
        /* END Msg(4:0316)-9 */
        /* QAC Warning: START Msg(2:2814)-20 */
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* Get the value for multiple chip selects configured  */
        LpChipSelect = (Spi_GpConfigPtr->pCSArray) +
                                                  (LpJobConfig->ucCSArrayIndex);
        /* END Msg(4:0488)-4 */
        /* END Msg(2:2814)-20 */

        /* MISRA Violation: START Msg(4:0488)-4 */
        /* QAC Warning: START Msg(2:2814)-20 */
        /*
         * To load configuration register, read the existing value to
         * local union variable
         */
        LunDataAccess1.ulRegData = LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect];
        /* END Msg(2:2814)-20 */
        /* END Msg (4:0488)-4 */
        /* Load the local variable with data width */
        LunDataAccess1.ucRegData4[SPI_THREE] =
                 (LunDataAccess1.ucRegData4[SPI_THREE] & SPI_DLS_MASK);
        LunDataAccess1.ucRegData4[SPI_THREE] =
       (LunDataAccess1.ucRegData4[SPI_THREE] | LpPBChannelConfig->ucDLSSetting);
        /* Load the local variable with configured direction */
        if (SPI_TRUE == LpPBChannelConfig->blDirection)
        {
          /* Direction is LSB, set DIR bit */
          LunDataAccess1.ucRegData4[SPI_TWO] =
                        (LunDataAccess1.ucRegData4[SPI_TWO] | SPI_SET_DIR_LSB);
        }
        else
        {
          /* Direction is MSB, reset DIR bit */
          LunDataAccess1.ucRegData4[SPI_TWO] =
                  (LunDataAccess1.ucRegData4[SPI_TWO] & SPI_RESET_DIR_LSB);
        }

        /* Load the number of chip selects */
        LucVar = LpJobConfig->ucNoOfCS;
        /* MISRA Violation: START Msg(4:0402)-13 */
        /* Reset the PWR bit since other registers need to be written */
        LucCxCtl0 = (LpMainUserBaseAddr->ucMainCTL0 & SPI_RESET_PWR);
        SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)
        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                         LucCxCtl0, SPI_CTLREG_8_BIT_MASK, SPI_SYNCTRANSMIT_SID)

        /* END Msg(4:0402)-13 */
        do
        {
          /* Initialize CSIH configuration register */
          SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
                                                       LunDataAccess1.ulRegData)

          SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
          LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],LunDataAccess1.ulRegData,
                                         SPI_CSIHCFG_MASK, SPI_SYNCTRANSMIT_SID)

          /* Decrement number of chip selects */
          LucVar--;
          /* MISRA Violation: START Msg(4:0489)-3 */
          LpChipSelect++;
          /* END Msg (4:0489)-3 */
        }while (SPI_ZERO < LucVar);
        /* MISRA Violation: START Msg(4:0402)-13 */
        LucCxCtl0 = (LpMainUserBaseAddr->ucMainCTL0 | SPI_SET_PWR);
        SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)

        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                         LucCxCtl0, SPI_CTLREG_8_BIT_MASK, SPI_SYNCTRANSMIT_SID)

        /* END Msg(4:0402)-13 */
        #endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
      }
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF ) */
   /* Set the data to transmit and Read the receive data */
    #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
    LenReturnValue = Spi_SyncProcessData(LpJobConfig, LpPBChannelConfig,
                                     LddNoOfChannels, LddSequenceID, LddJobID );
    #else
    LenReturnValue = Spi_SyncProcessData(LpJobConfig, LpPBChannelConfig,
                                                               LddNoOfChannels);
    #endif
    /* Increment the pointer to the channel */
    /* MISRA Violation: START Msg(4:0489)-3 */
    LpChannelList++;
    /* END Msg (4:0489)-3 */

    /* Decrement the counter for number of channels */
    LddNoOfChannels--;

  }while ((SPI_ZERO < LddNoOfChannels) && (E_OK == LenReturnValue));

  if (E_NOT_OK != LenReturnValue)
  {
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      Spi_HWDeActivateCS(LpJobConfig);
      #endif /* End of #if (SPI_CSIG_CONFIGURED == STD_ON)*/
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {

    }
    #endif
  }
  else
  {
    /* No action required */
  }
  return(LenReturnValue);
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of ((SPI_LEVEL_DELIVERED == SPI_ZERO) ||
        *  ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
        *  (SPI_DIRECT_ACCESS_MODE == STD_ON)))
        */

/*******************************************************************************
** Function Name      : Spi_InitiateJobTx
**
** Service ID         : Not Applicable
**
** Description        : This service initiates the SPI transmission. This is
**                      common for all modes of asynchronous transmission
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_JobType LddJobListIndex
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstSeq, Spi_GpFirstJob, Spi_GpFirstJobList,
**                      Spi_GpConfigPtr, Spi_GaaHighPriorityCommActive
**                      Spi_GddDriverStatus, Spi_GpFirstChannel
**                      Spi_GstCurrentCommData, Spi_GstDualBufferCurrentCommData
**                      Spi_GaaSeqCurrentHWUnit, Spi_GblInitiateJobTx
**
** Function Invoked   : Spi_HWActivateCS, Spi_ProcessChannelInDirAccMod,
**                      Spi_ProcessChannelInFifoMod,
**                      Spi_ProcessChannelInDualOrTxMod.
**                      SPI_EXIT_CRITICAL_SECTION, SPI_ENTER_CRITICAL_SECTION
**
** Registers Used    :  None
*******************************************************************************/
/* Implements SPI_ESDD_UD_028, SPI_ESDD_UD_199 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
     (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI234_Conf, SPI233_Conf, SPI116, EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_InitiateJobTx(Spi_JobType LddJobListIndex)
/* END Msg(2:3227)-16 */
{
  /* Declare a local pointer to point to the Job Config Structure */
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;

  Spi_JobType LddJobIndex;
  Spi_HWUnitType LddHWUnit;
  uint8 LucHWMemoryMode;
  #if (((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))\
           || (SPI_DUAL_BUFFER_MODE == STD_ON) ||(SPI_CANCEL_API == STD_ON))
  /* Defining a local variable to hold to index of the sequence */
  Spi_SequenceType LddSeqIndex;
  #endif

  #if (SPI_DIRECT_ACCESS_MODE == STD_ON)
  P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData;
  #endif

  #if ((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))
  /* Defining a local variable to hold to index of the buffer */
  Spi_NumberOfDataType LddBufferIndex;
  /* Declare a local pointer to point to the channel Config Data */
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, PI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  P2VAR(Spi_TxOnlyCurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
                                                LpTxOnlyCurrentCommData;
  #endif

  #if (SPI_DUAL_BUFFER_MODE == STD_ON)
  P2VAR(Spi_DualBufferCurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
                                                LpDualBufferCurrentCommData;
  #endif

  #if (((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))\
                                        || (SPI_DUAL_BUFFER_MODE == STD_ON))
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  #endif

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_HWUnitType LddHWUnitNumber;
  #endif

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the respective job list index */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the index of the job */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)-20 */

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */

  #if (((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))\
           || (SPI_DUAL_BUFFER_MODE == STD_ON) ||(SPI_CANCEL_API == STD_ON))
  /* Get the index of the sequence */
  LddSeqIndex = LpJobList->ddSequenceIndex;
  #endif

  #if (((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))\
                                        || (SPI_DUAL_BUFFER_MODE == STD_ON))
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the sequence structure */
  LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  #endif

  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif

  /* Update driver status as busy */
  Spi_GddDriverStatus = SPI_BUSY;

  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts */
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the HW Unit index of the any of the job in the sequence */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;
  /* END Msg(2:2814)-20 */

  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
  #endif
  {
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20 */
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    /* END Msg(2:2814)-20 */
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
    #endif
    {
      /* Get the configured memory mode for this HW Unit */
      LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
    }
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    else
    {
      /* Since High priority communication is active, memory mode is DAM */
      LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
    }
    #endif /* End of #if (SPI_HW_PRIORITY_ENABLED == STD_ON) */

    #endif /* End of #if (SPI_CSIH_CONFIGURED == STD_ON) */
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  #endif
  {
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    /* Since HW Unit is CSIG, memory mode is DIRECT ACCESS by default */
    LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
    #endif
  }

  #if (SPI_DIRECT_ACCESS_MODE == STD_ON)
  /* MISRA Violation: START Msg(4:2995)-15 */
  if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode)
  /* END Msg(4:2995)-15 */
  {
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      /* MISRA Violation: START Msg(4:2962)-11 */
      if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
      /* END Msg(4:2962)-11 */
      #endif
      {
        LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
      }
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      else
      {
        LpCurrentCommData =
                         &(Spi_GstCurrentCommData[SPI_ONE + LddHWUnitNumber]);
      }
      #endif
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
      #endif
    }

    /*
     * Store the index of the current HW Unit in the RAM area to be
     * used by the ISR
     */
    LpCurrentCommData->ddHWUnitIndex = LddHWUnit;

    /* Save the current channel list to be transmitted */
    LpCurrentCommData->pCurrentTxChannelList = (LpJobConfig->pChannelList);

    /* Save the current channel list to be received */
    LpCurrentCommData->pCurrentRxChannelList = (LpJobConfig->pChannelList);

    /* Save the number of channels yet to be transmitted */
    LpCurrentCommData->ddNoOfTxChannels = (LpJobConfig->ddNoOfChannels);

    /* Save the number of channels yet to be received */
    LpCurrentCommData->ddNoOfRxChannels = (LpJobConfig->ddNoOfChannels);

    #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    /* Reset the flag for indicating EDL */
    LpCurrentCommData->blTxEDL = SPI_FALSE;

    /* Reset the flag for indicating EDL */
    LpCurrentCommData->blRxEDL = SPI_FALSE;
    #endif
  }
  else
  {
    /* No action required */
  }
  #endif /* End of #if (SPI_DIRECT_ACCESS_MODE == STD_ON) */

  #if ((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))
  if (SPI_TX_ONLY_MODE_CONFIGURED == LucHWMemoryMode)
  {
    LpTxOnlyCurrentCommData =
     &Spi_GstTxOnlyCurrentCommData
                 [Spi_GpConfigPtr->aaHWUnitCurrentCommDataIndex[LddHWUnit]];
    /* QAC Warning: START Msg(2:2824)-17 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpPBChannelConfig = Spi_GpFirstChannel + (*(LpJobConfig->pChannelList));
    /* END Msg (4:0488)-4 */
    /* END Msg(2:2824)-17 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Get the buffer index value */
    LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
    /* END Msg(2:2814)-20 */
    /* Implements SPI_ESDD_UD_195 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* MISRA Violation: START Msg(4:2985)-19 */
    LpTxOnlyCurrentCommData->pCurrentRxData = (Spi_GpConfigPtr->pChannelIBRead +
                                        (LddBufferIndex + SPI_RX_BUFFER_START));
    /* END Msg (4:0488)-4 */
    /* END Msg(4:2985)-19 */

    /* Get the pointer to the post-build structure of the channel */
    LpTxOnlyCurrentCommData->ddChannelIndex = *(LpJobConfig->pChannelList);
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Save the number of buffers to be received */
    LpTxOnlyCurrentCommData->ddNoOfBuffers = LpSeqConfig->ddNoOfBuffers;
    /* END Msg(2:2814)-20 */
    /* Save the number of buffers received */
    LpTxOnlyCurrentCommData->ddNoOfBuffersRcvd = SPI_ZERO;

    /* MISRA Violation: START Msg(4:0488)-4 */
    /* Save the number of buffers to be received before a notification */
    LpTxOnlyCurrentCommData->ddNoOfNxtNotifyBuffersIdx =
             (Spi_GpConfigPtr->pJobNotifyIndex) + LpSeqConfig->ddNxtNotifyIndex;
    /* END Msg (4:0488)-4 */
  }
  else
  {
    /* No action required */
  }
  #endif /* End of #if (SPI_TX_ONLY_MODE == STD_ON) */

  #if (SPI_DUAL_BUFFER_MODE == STD_ON)
  if (SPI_DUAL_BUFFER_MODE_CONFIGURED == LucHWMemoryMode)
  {
    LpDualBufferCurrentCommData = &Spi_GstDualBufferCurrentCommData
                    [Spi_GpConfigPtr->aaHWUnitCurrentCommDataIndex[LddHWUnit]];

    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx =
      (Spi_GpConfigPtr->pJobNotifyIndex) + (LpSeqConfig->ddNxtNotifyIndex);
    /* END Msg(4:0488)-4 */
    /* END Msg(2:2814)-20 */


    LpDualBufferCurrentCommData->ddNoOfBuffersTxtd =
                *(LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx);
  }
  else
  {
    /* No action required */
  }
  #endif

  #if (SPI_CANCEL_API == STD_ON)
  Spi_GaaSeqCurrentHWUnit[LddSeqIndex] = LddHWUnit;
  #endif

  /*
   * Global boolean variable to avoid copy of properties repeatedly if
   * properties of all channels are same. This boolean allows copying channel
   * properties once. This boolean will be reset immediately after its use
   */
  Spi_GblInitiateJobTx = SPI_TRUE;
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
  #endif
  {
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    /* Activate the chip select */
    /* QAC Warning: START Msg(2:2814)-20 */
    Spi_HWActivateCS(LpJobConfig, (LpJobConfig->ucClk2CsLoopCnt));
    /* END Msg(2:2814)-20 */
    #endif
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  {
  }
  #endif
  #endif/*#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)*/
 if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode)
 {
 #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON))|| \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
 Spi_ProcessChannelInDirAccMod(LddHWUnit, LucHWMemoryMode);
 #endif
 }
 #if (SPI_FIFO_MODE == STD_ON)
 else if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
 {
   Spi_ProcessChannelInFifoMod(LddHWUnit, LucHWMemoryMode);
 }
 #endif
 #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
 else if ((SPI_DUAL_BUFFER_MODE_CONFIGURED == LucHWMemoryMode) ||
                               (SPI_TX_ONLY_MODE_CONFIGURED == LucHWMemoryMode))
{
  Spi_ProcessChannelInDualOrTxMod(LddHWUnit, LucHWMemoryMode);
}
#endif
else
{
  /* no action required */
}
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /*
        * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        * (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
        */


/*******************************************************************************
** Function Name      : Spi_TransmitISR
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the TIC ISR for processing
**                      communication status interrupt request
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit
**                      uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Spi_ProcessDirectAcessData, Spi_ProcessFifoData
**                      Spi_ProcessDualBufferData
**
** Registers Used     : None
*******************************************************************************/
/* Implements SPI_ESDD_UD_040 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
      (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON))

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE) Spi_TransmitISR
                             (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{

  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON)) \
                                        && (SPI_DUAL_BUFFER_MODE == STD_ON))
  if (SPI_TWO > LucHWMemoryMode)
  #endif
  {
    if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode)
    {
      #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                    (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
      Spi_ProcessDirectAcessData(LddHWUnit, LucHWMemoryMode);
      #endif
    } /* End of if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode) */
    else
    {
      #if (SPI_FIFO_MODE == STD_ON)
      Spi_ProcessFifoData(LddHWUnit, LucHWMemoryMode);
      #endif
    }
  }
  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON)) \
      && (SPI_DUAL_BUFFER_MODE == STD_ON))
  else
  #endif
  {
    #if (SPI_DUAL_BUFFER_MODE == STD_ON)
    if (SPI_DUAL_BUFFER_MODE_CONFIGURED == LucHWMemoryMode)
    {
      Spi_ProcessDualBufferData(LddHWUnit, LucHWMemoryMode);
    }
    else
    {
        /* No action required */
    }
    #endif /* End of (SPI_DUAL_BUFFER_MODE == STD_ON) */
  } /* End of else loop of LucHWMemoryMode < SPI_TWO */
}

#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* End of #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        * (SPI_DUAL_BUFFER_MODE == STD_ON) ||
        * (SPI_HW_PRIORITY_ENABLED == STD_ON))
        */

/*******************************************************************************
** Function Name      : Spi_TransmitCancelISR
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the TIJC ISR for processing
**                      job completion interrupt request

**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit
**                      uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GaaSeqQueue, Spi_GaaSeqResult,
**                      Spi_GpFirstSeq, Spi_GddQueueIndex, Spi_GpConfigPtr
**
** Function Invoked   : Spi_ProcessSequence
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_039 */
#if (((SPI_CANCEL_API == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON)) && \
    ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE) Spi_TransmitCancelISR
                 (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_CONST) LpStsByteValue;
  P2VAR(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpStsByte;
  uint8 LucVar;
  #endif
  Spi_SequenceType LddSeqIndex;
  Spi_HWUnitType LddHWUnitNumber;
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  /* END Msg(2:2814)-20 */
  LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  /* Disable transmit cancel interrupt control */
  RH850_SV_MODE_IMR_OR(16, (LpHWUnitInfo->pTxCancelImrAddress),
                                ((uint16)(~(LpHWUnitInfo->usTxCancelImrMask))));
  /* Update sequence result as CANCELLED */
  Spi_GaaSeqResult[LddSeqIndex] = SPI_SEQ_CANCELLED;
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the pointer to status bytes ROM value for the sequence */
  LpStsByteValue = (Spi_GpConfigPtr->pStsValueArray) +
                                  (LpSeqConfig->usStsValueStartByteIdx);
  /* END Msg(2:2814)-20 */
  /* END Msg(4:0488)-4 */

  /* Get the number of status byte ROM value */
  LucVar = LpSeqConfig->ucNoOfStsByteValue;
  /* MISRA Violation: START Msg(4:0488)-4 */
  if (NULL_PTR != Spi_GpConfigPtr->pStatusArray)
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Get the pointer to the start byte of RAM area */
    LpStsByte = (Spi_GpConfigPtr->pStatusArray) +
                                (LpSeqConfig->usStsUpdateStartByteIdx);
    /* END Msg(2:2814)-20 */
  /* END Msg(4:0488)-4 */
  }
  else
  {
    LpStsByte = NULL_PTR;
  }
  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts to protect this critical section */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif

  while ((SPI_ZERO < LucVar) && (NULL_PTR != LpStsByte))
  {

    /*
     * Reset the status bit of the requested sequence and the sequences
     * that have jobs shared with the requested sequence
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    *LpStsByte = (*LpStsByte & ((uint8)(~(*LpStsByteValue))));


    /* END Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0489)-3 */
    LpStsByte++;
    /* END Msg(4:0489)-3 */

    /* MISRA Violation: START Msg(4:0489)-3 */
    LpStsByteValue++;
    /* END Msg(4:0489)-3 */

    LucVar--;
  } /* End of while ( SPI_ZERO < LucVar) */

  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts to protect this critical section */
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif
  #endif
  Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
}

#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* End of #if (((SPI_CANCEL_API == STD_ON) ||
        * (SPI_HW_PRIORITY_ENABLED == STD_ON)) && \
        * ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
        */

/*******************************************************************************
** Function Name      : Spi_ReceiveISR
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the TIR ISR for processing
**                      receive status interrupt request
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstChannel, Spi_GpFirstJob,
**                      Spi_GaaSeqQueue, Spi_GaaJobResult, Spi_GaaSeqResult,
**                      Spi_GstTxOnlyCurrentCommData, Spi_GpConfigPtr
**                      Spi_GpFirstJobList, Spi_GddQueueIndex
**                      Spi_GusAsynDataAccess
**
** Function Invoked   : Spi_ProcessSequence, Spi_ReceiveDirectAcessData
**
** Registers Used     : CSIHnRX0H, CSIGnRX0.
*******************************************************************************/

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements SPI_ESDD_UD_169 */
/* Implements SPI118, SPI071, SPI054, SPI218_Conf, SPI295 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE) Spi_ReceiveISR
       (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{

  #if ((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  #endif
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpTxOnlyRxData;
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobListTmptr;
  P2VAR(Spi_TxOnlyCurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
                                                LpTxOnlyCurrentCommData;
  Spi_JobType LddNoOfJobs;
  Spi_SequenceType LddSeqIndex;
  Spi_DataType LddData;
  Spi_HWUnitType LddHWUnitNumber;
  Spi_JobType LddJobIndex;
  /* START Msg(3:3203)-19 */
  volatile uint16 Lus16BitData;
  /* END Msg(3:3203)-19 */
  #endif

  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
  if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode)
  {
    Spi_ReceiveDirectAcessData(LddHWUnit, LucHWMemoryMode);
  }
  else
  {
    /* No action required */
  }
  #endif /*
          * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
          *                 (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
          *                                 (SPI_HW_PRIORITY_ENABLED == STD_ON))
          */
   #if ((SPI_TX_ONLY_MODE == STD_ON) && (SPI_INTERNAL_RW_BUFFERS == STD_ON))
  if (SPI_TX_ONLY_MODE_CONFIGURED == LucHWMemoryMode)
  {

    /* Get the pointer to the structure of HW Unit information */
    LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
    /* QAC Warning: START Msg(2:2814)-20 */
    LpTxOnlyCurrentCommData =
     &Spi_GstTxOnlyCurrentCommData
            [Spi_GpConfigPtr->aaHWUnitCurrentCommDataIndex[LddHWUnit]];
    /* END Msg(2:2814)-20 */
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];

    /* MISRA Violation: START Msg(4:0316)-9 */
    /* Get the base address of the HW Unit */
    LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
    /* END Msg(4:0316)-9 */
    /* Implements SPI_ESDD_UD_198 */
    LpTxOnlyRxData = LpTxOnlyCurrentCommData->pCurrentRxData;

    if (NULL_PTR != LpTxOnlyRxData)
    {
      #if (SPI_8BIT_DATA_WIDTH == STD_ON)
      /*
       * Data width is maximum 8-bit. Hence, Receive the data from the
       * Rx register to local union variable
       */
      /* QAC Warning: START Msg(2:2814)-20 */
      LddData = (uint8) LpCsihUserBaseAddr->usCSIHRX0H;
      /* END Msg(2:2814)-20 */
      #else
      /* Data width is maximum 16-bit */
      /* QAC Warning: START Msg(2:2814)-20 */
      LddData = LpCsihUserBaseAddr->usCSIHRX0H;
      /* END Msg(2:2814)-20 */
      #endif
    }
    else
    {
      Lus16BitData = LpCsihUserBaseAddr->usCSIHRX0H;
    }
    if (NULL_PTR != LpTxOnlyRxData)
    {
      /* MISRA Violation: START Msg(4:2962)-11 */
      *LpTxOnlyRxData = LddData;
      /* END Msg (4:2962)-11*/

      /* MISRA Violation: START Msg(4:0489)-3 */
      LpTxOnlyRxData++;
      /* END Msg (4:0489)-3 */

      LpTxOnlyCurrentCommData->pCurrentRxData = LpTxOnlyRxData;
    }
    else
    {
      /* no action required */
    }
    /* Get the sequence index from the queue for normal operation */
    LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];
    /* QAC Warning: START Msg(2:2824)-17 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
    /* END Msg (4:0488)-4 */
    /* END Msg(2:2824)-17 */

    (LpTxOnlyCurrentCommData->ddNoOfBuffersRcvd)++;
    /* QAC Warning: START Msg(2:2814)-20 */
    if ((LpTxOnlyCurrentCommData->ddNoOfBuffersRcvd) <
                                                  LpSeqConfig->ddNoOfBuffers)
    {
      /* END Msg(2:2814)-20 */
      if ((LpTxOnlyCurrentCommData->ddNoOfBuffersRcvd) >=
                     *(LpTxOnlyCurrentCommData->ddNoOfNxtNotifyBuffersIdx))
      {
        /* MISRA Violation: START Msg(4:0489)-3 */
        /* Increment the notify index value */
        (LpTxOnlyCurrentCommData->ddNoOfNxtNotifyBuffersIdx)++;
        /* END Msg (4:0489)-3 */
        /* QAC Warning: START Msg(2:2814)-20 */
        LddJobIndex =
         (Spi_JobType)(*(LpTxOnlyCurrentCommData->ddNoOfNxtNotifyBuffersIdx));
        /* END Msg(2:2814)-20 */
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* QAC Warning: START Msg(2:2824)-17 */
        /* Check if notification is configured */
        if (NULL_PTR != ((Spi_GpFirstJob + LddJobIndex)->pSpiJobNotification))
        {
          (Spi_GpFirstJob + LddJobIndex)->pSpiJobNotification();
          /* END Msg(2:2824)-17 */
          /* END Msg(4:0488)-4 */
        }
        else
        {
          /* No action required */
        }

        /* MISRA Violation: START Msg(4:0489)-3 */
        /* Increment the notify index value */
        (LpTxOnlyCurrentCommData->ddNoOfNxtNotifyBuffersIdx)++;
        /* END Msg (4:0489)-3 */
      }
      else
      {
        /* No action required */
      }
    }
    else
    {
      /*
       * All channels are transmitted and received. Hence the sequence is
       * completed
       */

      /* Update sequence result as OK */
      Spi_GaaSeqResult[LddSeqIndex] = SPI_SEQ_OK;

      /* MISRA Violation: START Msg(4:0488)-4 */
      /* QAC Warning: START Msg(2:2824)-17 */
      /* Load Job List pointer to temporary variable */
      LpJobListTmptr = Spi_GpFirstJobList + (LpSeqConfig->ddJobListIndex);
      /* END Msg(2:2824)-17 */
      /* END Msg (4:0488)-4 */

      /* Load total number of Jobs in current sequence to local variable */
      LddNoOfJobs = LpSeqConfig->ddNoOfJobs;

      do
      {
        /* QAC Warning: START Msg(2:2814)-20 */
        /* Update the job result variable */
        Spi_GaaJobResult[LpJobListTmptr->ddJobIndex] = SPI_JOB_OK;
        /* END Msg(2:2814)-20 */
        /* MISRA Violation: START Msg(4:0489)-3 */
        /* Increment local pointer to the job list */
        LpJobListTmptr++;
        /* END Msg (4:0489)-3 */

        LddNoOfJobs--;
      }
      while (SPI_ZERO < LddNoOfJobs);

      Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
    }
  }
  else
  {
    /* No action required */
  }
  #endif /* End of #if (SPI_TX_ONLY_MODE == STD_ON) */
}

#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /*
        * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        *  (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_TX_ONLY_MODE == STD_ON))
        */

/*******************************************************************************
** Function Name      : Spi_ProcessSequence
**
** Service ID         : Not Applicable
**
** Description        : This function is to process remaining jobs in
**                      the sequence to be transmitted
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit
**                      uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpConfigPtr, Spi_GpFirstJobList,
**                      Spi_GaaJobQueue, Spi_GddQueueIndex,
**                      Spi_GaaHighPriorityCommActive, Spi_GstCurrentCommData
**                      Spi_GaaJobResult, Spi_GpFirstJob,
**                      Spi_GucHWFifoBufferSts.
**
** Function Invoked   : Spi_HWDeActivateCS, Spi_ProcessChannelInDirAccMod
**                      Spi_PopFromQueue, Spi_ProcesSeqInDualOrTxMod
**
** Registers Used     : IMRn
*******************************************************************************/
/* Implements SPI_ESDD_UD_034 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
      (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements SPI292, SPI350, SPI118, SPI119, SPI088, SPI071, SPI054 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessSequence
                   (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{
  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  #endif
  #endif

  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_CONFIG_CONST) LpHWUnitInfo;

  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
  P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData;
  #endif

  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  Spi_HWUnitType LddHWUnitNumber;
  #endif

  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
  Spi_JobType LddJobIndex;
  #endif

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON)) \
        && ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
  if (SPI_TWO > LucHWMemoryMode)
  #endif
  {
    #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON)\
                                         || (SPI_HW_PRIORITY_ENABLED == STD_ON))

    #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20 */
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    /* END Msg(2:2814)-20 */

    if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
    #endif
    {
      LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
    }
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    else
    {
      LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ONE + LddHWUnitNumber]);
    }
    #endif
    if ((SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode) &&
                            (SPI_ZERO < LpCurrentCommData->ddNoOfRxChannels))
    {
      /* More channels to be transmitted. Hence transmit next channel */
      Spi_ProcessChannelInDirAccMod(LddHWUnit, LucHWMemoryMode);
    }
    else
    #endif /*
            * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
            *                   (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
            *                               (SPI_HW_PRIORITY_ENABLED == STD_ON))
            */
    {
      /* QAC Warning: START Msg(2:2824)-17 */
      /* MISRA Violation: START Msg(4:0488)-4 */
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      LpJobList = Spi_GpFirstJobList +
                        Spi_GaaJobQueue[Spi_GddQueueIndex[(LddHWUnitNumber +
                                         SPI_MAX_CSIH_HW_INDEX + SPI_TWO)]];
      #else

      LpJobList = Spi_GpFirstJobList +
                        Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
      /* END Msg(2:2824)-17 */
      /* END Msg (4:0488)-4 */
      #endif

      /* Get the index of the first job linked to this sequence */
      /* QAC Warning: START Msg(2:2814)-20 */
      LddJobIndex = LpJobList->ddJobIndex;
      /* END Msg(2:2814)-20 */

      #if (SPI_CSIG_CONFIGURED == STD_ON)
      /* MISRA Violation: START Msg(4:0488)-4 */
      /* QAC Warning: START Msg(2:2824)-17 */
      /* Get the pointer to the job structure */
      LpJobConfig = Spi_GpFirstJob + LddJobIndex;
      /* END Msg (2:2824)-17 */
      /* END Msg (4:0488)-4 */
      #endif

      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
      #endif
      {

        /* Disable transmit interrupt control */
        RH850_SV_MODE_IMR_OR(16, (LpHWUnitInfo->pTxImrAddress),
                                     ((uint16) (~(LpHWUnitInfo->usTxImrMask))));

        /* Disable receive interrupt control */
        RH850_SV_MODE_IMR_OR(16, (LpHWUnitInfo->pRxImrAddress),
                                    ((uint16)(~(LpHWUnitInfo->usRxImrMask))));

      }
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      else
      #endif
      {
        /* No action required */
      }

      #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
      if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
      #endif
      {
        #if (SPI_CSIG_CONFIGURED == STD_ON)
          /* MISRA Violation: START Msg(4:0488)-4 */
          Spi_HWDeActivateCS(LpJobConfig);
          /* END Msg (4:0488)-4 */
        #endif /* #if (SPI_CSIG_CONFIGURED == STD_ON */
      }
      #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
      else
      #endif
      {
        /* No action required */
      }

      if (SPI_JOB_FAILED != Spi_GaaJobResult[LddJobIndex])
      {
        /* Update the RAM area for job sequence */
        Spi_GaaJobResult[LddJobIndex] = SPI_JOB_OK;
      }
      else
      {
        /* No action required */
      }

      /* Check if the notification function is configured */
      /* MISRA Violation: START Msg(4:0488)-4 */
      /* QAC Warning: START Msg(2:2824)-17 */
      if (NULL_PTR != (Spi_GpFirstJob + LddJobIndex)->pSpiJobNotification)
      {
        /* END Msg(2:2824)-17 */
        /* Invoke the notification function */
        (Spi_GpFirstJob + LddJobIndex)->pSpiJobNotification();
        /* END Msg (4:0488)-4 */
      }
      else
      {
        /* No action required */
      }
      #if (SPI_FIFO_MODE == STD_ON)
      /* QAC Warning: START Msg(2:3892)-21 */
      /* Reset the Buffer status to UNINT */
      Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] = SPI_FIFO_BUFFER_UNINIT;
      Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX] = SPI_FIFO_BUFFER_UNINIT;
      /* END Msg (2:3892)-21 */
      #endif
      /* Pop next job in the queue */
      Spi_PopFromQueue(LddHWUnit, LucHWMemoryMode);

    } /* End of checking memory modes */
    #endif /*
            * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
            * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON)\
            *                            || (SPI_HW_PRIORITY_ENABLED == STD_ON))
            */
  }
  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON)) \
      && ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
  else
  #endif
  {
    #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

    Spi_ProcesSeqInDualOrTxMod(LpHWUnitInfo, LddHWUnit);

    #endif /* End of ((SPI_DUAL_BUFFER_MODE == STD_ON)
                   || (SPI_TX_ONLY_MODE == STD_ON))*/
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        * (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
        */

/*******************************************************************************
** Function Name      : Spi_TxDmaConfig
**
** Service ID         : Not Applicable
**
** Description        : This function is to set the attributes for DMA transfer
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpJobConfig, LpTxData, LddNoOfBuffers
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpDmaUnitConfig, Spi_GddDmaData
**
** Function Invoked   : None
**
** Registers Used     : DCSTCn, DCSTn, DSAn, DTCTn, DTFRn, DTCn, DCENn, DTFRRQn,
**                      CSIHTX0W, DCSTSn, IMRn, EICn, DTFRRQCn
*******************************************************************************/
/* Implements SPI_ESDD_UD_042 */
/* Implements AR_PN0063_FR_0031 */
#if (SPI_DMA_MODE_ENABLE == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_TxDmaConfig
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
 P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_CONST) LpTxData,
 Spi_NumberOfDataType LddNoOfBuffers)
/* END Msg(2:3227)-16 */
{

  P2CONST(Spi_DmaUnitConfig, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;
  P2VAR(Spi_DmaAddrRegs, AUTOMATIC, SPI_CONFIG_DATA) LpDmaRegisters;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  uint16 LusTotalNoOfBuffers;
  /* MISRA Violation: START Msg(4:0759)-1 */
  volatile Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  #endif

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_HWUnitType LddHWUnit;
  Spi_HWUnitType LddHWUnitNumber;
  #endif
  uint32 LulDTCTVal;
  uint8 LucHWMemoryMode;
  uint8 LucIndex;
  uint32 LulDmaDtct;
  /* QAC Warning: START Msg(2:2814)-20*/
  /* Get the Tx DMA index for this HW Unit */
  LucIndex = LpJobConfig->ucTxDmaDeviceIndex;
  /* END Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:2982)-2 */
  /* Initialize memory mode as DIRECT ACCESS */
  LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
  /* END Msg(4:2982)-2 */

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Get the Hardware Unit index */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;
  /* Store the number of buffers in a temp variable. */
  LusTotalNoOfBuffers = LddNoOfBuffers;
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* MISRA Violation: START Msg(4:0316)-9 */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(4:0316)-9 */
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  /* Check if the HW Unit is CSIH */
  if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
  #endif
  {
    /* QAC Warning: START Msg(2:2814)-20*/
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    /* END Msg(2:2814)-20 */

    /* Get the configured memory mode for this HW Unit */
    LucHWMemoryMode =  Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
  }
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  #endif

  if (SPI_INVALID_DMAUNIT != LucIndex)
  {

    /* To set Chip Select configuration in TX0W register in FIFO mode for DMA */
    if ((SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode) &&
                                      (LddNoOfBuffers > SPI_ONE ))
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      LunDataAccess1.ulRegData = SPI_ZERO;

      /* Set chip select in the local union variable */
      LunDataAccess1.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;

      if (NULL_PTR == LpTxData)
      {
         LunDataAccess1.Tst_ByteAccess.usRegData1 = Spi_GddDmaData;
      }
      else
      {
        LunDataAccess1.Tst_ByteAccess.usRegData1 = *LpTxData;
        /* MISRA Violation: START Msg(4:0489)-3 */
        LpTxData++;
        /* END Msg (4:0489)-3 */
      }
      LddNoOfBuffers--;
      #endif
    }
    else
    {
      /* No action required */
    }

    /* Set the parameters for Tx DMA Unit */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Set the DMA channel control register value */
    LpDmaConfig = Spi_GpDmaUnitConfig + LucIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpDmaRegisters = LpDmaConfig->pDmaCntlRegBase;
    /* MISRA Violation: START Msg(4:0402)-13 */
    /*Clear the software transfer request flag*/

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCSTCn, SPI_DMA_STR_CLEAR)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCSTn,(uint32)SPI_ZERO,
                                      SPI_DMA_STR_CLEAR, SPI_ASYNCTRANSMIT_SID)

    /* END Msg(2:2814)-20 */
    if (NULL_PTR == LpTxData)
    {
      /* MISRA Violation: START Msg(4:0306)-8 */
      /* MISRA Violation: START Msg(4:0303)-16 */
      /* QAC Warning: START Msg(2:3416)-24 */
      /* Load the source register with pointer to default value */
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDSAn,(uint32)(&Spi_GddDmaData))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDSAn,
       (uint32)(&Spi_GddDmaData), SPI_CTLREG_32_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
      /* END Msg(4:0306)-8 */
      /* END Msg(4:0303)-16 */
      /* END Msg(2:3416)-24 */
      LulDTCTVal = SPI_DMA_FIXED_TX_SETTINGS;
      #if (SPI_FIFO_MODE == STD_ON)
      if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
      {
        /* MISRA Violation: START Msg(4:2984)-10 */
        /* Load the control register with Block Transfer 1 settings */
        LulDTCTVal = LulDTCTVal | SPI_DMA_BLOCK_SETTINGS;
        /* END Msg(4:2984)-10 */
      }
      else
      {
        /* No Action Required */
      }
      #endif /* End of #if (SPI_FIFO_MODE == STD_ON) */
      /* Load the control register with fixed settings */
      /* MISRA Violation: START Msg(4:0402)-13 */
      LulDmaDtct = (LpDmaRegisters->ulDTCTn | LulDTCTVal);
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn, LulDmaDtct)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
                              LulDmaDtct, SPI_DTCT_MASK, SPI_ASYNCTRANSMIT_SID)
      /* END Msg(4:0402)-13 */
    }
    else
    {
      if ((SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode) ||
                                                    (SPI_ONE == LddNoOfBuffers))
      {
        /* MISRA Violation: START Msg(4:0306)-8 */
        SPI_DMA_REG_WRITE(LpDmaRegisters->ulDSAn, (uint32)LpTxData)

        SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDSAn,
               (uint32)LpTxData, SPI_CTLREG_32_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
        /* END Msg(4:0306)-8 */
      }
      else
      {
        /* MISRA Violation: START Msg(4:0306)-8 */
        /* MISRA Violation: START Msg(4:0489)-3 */
        SPI_DMA_REG_WRITE(LpDmaRegisters->ulDSAn, (uint32)(LpTxData + SPI_ONE))

        SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDSAn,
        (uint32)(LpTxData + SPI_ONE), SPI_CTLREG_32_BIT_MASK,
                                                         SPI_ASYNCTRANSMIT_SID)

        /* END Msg(4:0489)-3 */
        /* END Msg(4:0306)-8 */
      }
      #if (SPI_FIFO_MODE == STD_ON)
      if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
      {
        /* Load the control register with Block Transfer 1 settings */
        /* MISRA Violation: START Msg(4:0402)-13 */
        LulDmaDtct = (LpDmaRegisters->ulDTCTn | SPI_DMA_BLOCK_SETTINGS);
        SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn, LulDmaDtct)

        SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
                              LulDmaDtct, SPI_DTCT_MASK, SPI_ASYNCTRANSMIT_SID)

      }
      else
      {
        /* No Action Required */
      }
      #endif /* End of #if (SPI_FIFO_MODE == STD_ON) */
      /* MISRA Violation: START Msg(4:0402)-13 */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn,
                          ((LpDmaRegisters->ulDTCTn) & SPI_DMA_INV_TX_SETTINGS))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
      (uint32)SPI_ZERO, ~SPI_DMA_INV_TX_SETTINGS, SPI_ASYNCTRANSMIT_SID)
      /* END Msg(4:0402)-13 */
    }

    if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
    {
      /* Load the trigger factor configured */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRn, (uint32)SPI_ZERO)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRn,(uint32)SPI_ZERO,
                                          SPI_DTFR_MASK, SPI_ASYNCTRANSMIT_SID)

      /* Load the transfer count value to the DMA register */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCn, LddNoOfBuffers)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCn, LddNoOfBuffers,
                                  SPI_CTLREG_32_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
    }
    else if (SPI_ONE == LddNoOfBuffers)
    {

      /* Load the transfer count value to the DMA register */
      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDTCn, LddNoOfBuffers)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCn, LddNoOfBuffers,
                                  SPI_CTLREG_32_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
      /* Disable the trigger factor configured */
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRn, (uint32)SPI_ZERO)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRn,
                        (uint32)SPI_ZERO, SPI_DTFR_MASK, SPI_ASYNCTRANSMIT_SID)

    }
    else
    {
      /* Load the trigger factor configured */

      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDTFRn,
                                       (uint32)(LpDmaConfig->usDmaDtfrRegValue))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRn,
      (uint32)(LpDmaConfig->usDmaDtfrRegValue), SPI_DTFR_MASK,
                                                          SPI_ASYNCTRANSMIT_SID)

      /* Load the transfer count value to the DMA register */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCn,
                                 ((uint32)((uint16)(LddNoOfBuffers - SPI_ONE))))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCn,
      ((uint32)((uint16)(LddNoOfBuffers - SPI_ONE))), SPI_CTLREG_32_BIT_MASK,
                                                          SPI_ASYNCTRANSMIT_SID)

    }
    /* Clear the MLE bit for data transfer once */
    /* MISRA Violation: START Msg(4:0402)-13 */

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn,
          ((LpDmaRegisters->ulDTCTn & SPI_DMA_ONCE) | SPI_DMA_HARDWARE_TRIGGER))

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
    SPI_DMA_HARDWARE_TRIGGER, ~SPI_DMA_DRS_MLE_MASK, SPI_ASYNCTRANSMIT_SID)
    /* END Msg(4:0402)-13 */
    /* Disable channel operation */
    SPI_DMA_REG_WRITE( LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_DISABLE)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                       SPI_DMA_DCEN_DISABLE,SPI_DCEN_MASK,SPI_ASYNCTRANSMIT_SID)

    /* Clear DMA Transfer Request */

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRRQCn, SPI_DMA_DRQ_CLEAR)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRRQn,
                     (uint32)SPI_ZERO, SPI_DMA_DRQ_CLEAR, SPI_ASYNCTRANSMIT_SID)

    if ((SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode) ||
                                               (SPI_ONE == LddNoOfBuffers))
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      if ((SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode) &&
                                      (LusTotalNoOfBuffers > SPI_ONE ))
      {
        /* QAC Warning: START Msg(2:2814)-20 */

        SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                                      LunDataAccess1.ulRegData)

        /* END Msg(2:2814)-20 */
      }
      else
      {
        /* No action required */
      }
      #endif
      /* DMA transfer enable  */
      /* MISRA Violation: START Msg(4:0402)-13 */
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn, (LpDmaRegisters->ulDTCTn &
                                                             SPI_DMA_STR_REQ))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
      (uint32)SPI_ZERO, ~SPI_DMA_STR_REQ, SPI_ASYNCTRANSMIT_SID)
      /* END Msg(4:0402)-13 */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCSTSn, SPI_DMA_STR)

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_ENABLE)
      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                     SPI_DMA_DCEN_ENABLE, SPI_DCEN_MASK, SPI_ASYNCTRANSMIT_SID)

    }
    else
    {
      /* DMA transfer enable  */
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_ENABLE)
      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                      SPI_DMA_DCEN_ENABLE, SPI_DCEN_MASK, SPI_ASYNCTRANSMIT_SID)

    }
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (SPI_DMA_MODE_ENABLE == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_RxDmaConfig
**
** Service ID         : Not Applicable
**
** Description        : This function is to set the attributes for DMA transfer
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpJobConfig, LpRxData, LddNoOfBuffers
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpDmaUnitConfig, Spi_GddDmaRxData
**
** Function Invoked   : None
**
** Registers Used     : DCENn, DCSTCn, DDAn, DTCTn, DTCn,
**                      EICn, IMRn, DTFRn, DTFRRQCn, DCSTSn, DTFRRQn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_038 */
#if (SPI_DMA_MODE_ENABLE == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
/* Implements EAAR_PN0034_FR_0068, EAAR_PN0034_FR_0061 */
FUNC(void, SPI_PRIVATE_CODE) Spi_RxDmaConfig
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
 P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpRxData,
 Spi_NumberOfDataType LddNoOfBuffers)

 /* END Msg(2:3227)-16 */
{
  P2CONST(Spi_DmaUnitConfig, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;
  P2VAR(Spi_DmaAddrRegs, AUTOMATIC, SPI_CONFIG_DATA) LpDmaRegisters;
  P2VAR(volatile uint16, AUTOMATIC, SPI_CONFIG_DATA) LpIntpCntrlReg;
  uint32 LulDTCTVal;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_HWUnitType LddHWUnit;
  Spi_HWUnitType LddHWUnitNumber;
  #endif
  uint32 LulDmaDtct;
  uint8 LucHWMemoryMode;
  uint8 LucIndex;
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the Rx DMA index for this HW Unit */
  LucIndex = LpJobConfig->ucRxDmaDeviceIndex;
  /* END Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:2982)-2 */
  /* Initialize memory mode as DIRECT ACCESS */
  LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
  /* END Msg(4:2982)-2 */
  /* Get the configured memory mode for this HW Unit */
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Get the Hardware Unit index */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;

  #if (SPI_CSIG_CONFIGURED == STD_ON)
  /* Check if the HW Unit is CSIH */
  if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
  #endif
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    /* END Msg(2:2814)-20 */

    /* Get the configured memory mode for this HW Unit */
    LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
  }
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  #endif

  if (SPI_INVALID_DMAUNIT != LucIndex)
  {
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Set the DMA channel control register value */
    LpDmaConfig = Spi_GpDmaUnitConfig + LucIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpDmaRegisters = LpDmaConfig->pDmaCntlRegBase;

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_DISABLE)
    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                     SPI_DMA_DCEN_DISABLE, SPI_DCEN_MASK, SPI_ASYNCTRANSMIT_SID)

    /* END Msg(2:2814)-20 */
    /*Clear the software transfer request flag*/
    /* MISRA Violation: START Msg(4:0402)-13 */

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCSTCn, SPI_DMA_STR_CLEAR)
    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCSTn,(uint32)SPI_ZERO,
                                      SPI_DMA_STR_CLEAR, SPI_ASYNCTRANSMIT_SID)

    /* END Msg(4:0402)-13 */
    if (NULL_PTR == LpRxData)
    {
      /* MISRA Violation: START Msg(4:0306)-8 */
      /* Load the source register with pointer to default value */

      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDDAn,((uint32)(&Spi_GddDmaRxData)))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDDAn,
      ((uint32)(&Spi_GddDmaRxData)), SPI_CTLREG_32_BIT_MASK,
                                                          SPI_ASYNCTRANSMIT_SID)

      /* END Msg(4:0306)-8 */
      LulDTCTVal = SPI_DMA_FIXED_RX_SETTINGS;
      #if (SPI_FIFO_MODE == STD_ON)
      if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
      {
        /* Load the control register with Block Transfer 1 settings */
        /* MISRA Violation: START Msg(4:2984)-10 */
        LulDTCTVal = LulDTCTVal | SPI_DMA_BLOCK_SETTINGS;
        /* END Msg(4:2984)-10 */
      }
      else
      {
        /* No Action Required */
      }
      #endif /* End of #if (SPI_FIFO_MODE == STD_ON) */
      /* MISRA Violation: START Msg(4:0402)-13 */
      LulDmaDtct =  (LpDmaRegisters->ulDTCTn | LulDTCTVal);
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn, LulDmaDtct)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn, LulDmaDtct,
                                          SPI_DTCT_MASK, SPI_ASYNCTRANSMIT_SID)

      /* END Msg(4:0402)-13 */
    }
    else
    {
      /* MISRA Violation: START Msg(4:0306)-9 */
      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDDAn,((uint32)LpRxData))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDDAn,
      ((uint32)LpRxData), SPI_CTLREG_32_BIT_MASK, SPI_ASYNCTRANSMIT_SID)

      /* END Msg(4:0306)-8 */
      #if (SPI_FIFO_MODE == STD_ON)
      if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
      {
        /* Load the control register with Block Transfer 1 settings */
        /* MISRA Violation: START Msg(4:0402)-13 */
        LulDmaDtct = (LpDmaRegisters->ulDTCTn | SPI_DMA_BLOCK_SETTINGS);
        SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn, LulDmaDtct)

        SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
                              LulDmaDtct, SPI_DTCT_MASK, SPI_ASYNCTRANSMIT_SID)
        /* END Msg(4:0402)-13 */
      }
      else
      {
        /* No Action Required */
      }
      #endif /* End of #if (SPI_FIFO_MODE == STD_ON) */
      /* MISRA Violation: START Msg(4:0402)-13 */
      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn,
                           (LpDmaRegisters->ulDTCTn & SPI_DMA_INV_RX_SETTINGS))
      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
      (uint32)SPI_ZERO, ~SPI_DMA_INV_RX_SETTINGS, SPI_ASYNCTRANSMIT_SID)

      /* END Msg(4:0402)-13 */
    }
    /* Load the transfer count value to the DMA register */

    SPI_DMA_REG_WRITE( LpDmaRegisters->ulDTCn, LddNoOfBuffers)
    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCn, LddNoOfBuffers,
                               SPI_CTLREG_32_BIT_MASK, SPI_ASYNCTRANSMIT_SID)

    /* Clear the MLE bit for data transfer once */
    /* MISRA Violation: START Msg(4:0402)-13 */

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn,
                           (LpDmaRegisters->ulDTCTn & SPI_DMA_ONCE))

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
                   (uint32)SPI_ZERO, ~SPI_DMA_ONCE, SPI_ASYNCTRANSMIT_SID)

    /* END Msg(4:0402)-13 */
    /* Clear the pending interrupts */
    RH850_SV_MODE_ICR_AND(16, (LpDmaConfig->pDmaIntCntlReg), (SPI_CLR_INT_REQ));
    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpDmaConfig->pDmaIntCntlReg), (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    /* Enable the DMA interrupt control register */
    LpIntpCntrlReg = LpDmaConfig->pDmaImrIntCntlReg;
    /* QAC Warning: START Msg(2:2814)-20 */
    RH850_SV_MODE_IMR_AND(16, (LpIntpCntrlReg), (LpDmaConfig->usDmaImrMask));
    /* END Msg(2:2814)-20 */
    if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
    {
      /* Disable the trigger factor configured */
          /* Load the trigger factor configured */
    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRn,(uint32)SPI_ZERO)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRn,
                         (uint32)SPI_ZERO, SPI_DTFR_MASK, SPI_ASYNCTRANSMIT_SID)

    }
    else
    {
      /* No action required */
    }
    /* Disable channel operation */
    SPI_DMA_REG_WRITE( LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_DISABLE)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                     SPI_DMA_DCEN_DISABLE, SPI_DCEN_MASK, SPI_ASYNCTRANSMIT_SID)

    /* Clear DMA Transfer Request */

    SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTFRRQCn,SPI_DMA_DRQ_CLEAR)

    SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTFRRQn,
                     (uint32)SPI_ZERO, SPI_DMA_DRQ_CLEAR, SPI_ASYNCTRANSMIT_SID)

    if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
    {

      /* DMA transfer enable  */
      /* MISRA Violation: START Msg(4:0402)-13 */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDTCTn,
                           (LpDmaRegisters->ulDTCTn & SPI_DMA_STR_REQ))

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDTCTn,
                  (uint32)SPI_ZERO, ~SPI_DMA_STR_REQ, SPI_ASYNCTRANSMIT_SID)
      /* END Msg(4:0402)-13 */

      SPI_DMA_REG_WRITE(LpDmaRegisters->ulDCSTSn, SPI_DMA_STR)

      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_ENABLE)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                      SPI_DMA_DCEN_ENABLE, SPI_DCEN_MASK, SPI_ASYNCTRANSMIT_SID)
    }
    else
    {
      /* DMA transfer enable  */
      SPI_DMA_REG_WRITE( LpDmaRegisters->ulDCENn, SPI_DMA_DCEN_ENABLE)

      SPI_DMA_REG_WRITE_VERIFY_RUNTIME(LpDmaRegisters->ulDCENn,
                      SPI_DMA_DCEN_ENABLE, SPI_DCEN_MASK, SPI_ASYNCTRANSMIT_SID)
    }
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (SPI_DMA_MODE_ENABLE == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_DmaISR
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the DMA ISR for processing
**                      DMA request
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : uint8 LddDmaUnit
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstChannel, Spi_GpFirstJob,
**                      Spi_GpDmaUnitConfig, Spi_GaaChannelEBData,
**                      Spi_GaaHighPriorityCommActive, Spi_GddDmaData
**                      Spi_GstFifoCurrentCommData
**
** Function Invoked   : Spi_ProcessSequence, Spi_RxDmaConfig, Spi_TxDmaConfig
**
** Registers Used     : None
*******************************************************************************/
/* Implements SPI_ESDD_UD_030 */
#if (SPI_DMA_MODE_ENABLE == STD_ON)

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements AR_PN0063_FR_0038 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE) Spi_DmaISR (uint8 LucDmaUnit)
/* END Msg (2:3227)-16*/
{
  Spi_HWUnitType LddHWUnit;
  uint8 LucHWMemoryMode;

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_HWUnitType LddHWUnitNumber;
  #endif

  #if (SPI_FIFO_MODE == STD_ON)
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpChannelList;
  P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;

  Spi_ChannelType LddNoOfChannels;
  Spi_NumberOfDataType LddNoOfBuffers;
  Spi_NumberOfDataType LddBufferIndex;
  Spi_JobType LddJobIndex;
  uint8 LucCxCtl0;
  #endif

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnit = *((Spi_GpConfigPtr->pDmaSpiHWUnitMap) + LucDmaUnit);
  /* END Msg (2:2814)-20 */
  /* END Msg (4:0488)-4 */

  #if ((SPI_CSIH_CONFIGURED == STD_ON) && (SPI_LEVEL_DELIVERED != SPI_ZERO))
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  /* Check if the HW Unit is CSIH */
  if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
  #endif
  {
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];

    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
    #endif
    {
    /* Get the configured memory mode for this HW Unit */
    LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
    }
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    else
    {
      /* Since High priority communication is active, memory mode is DAM */
      LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
    }
    #endif
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


  #if (SPI_FIFO_MODE == STD_ON)
  if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
  {
    /* Get the current job index */
    LddJobIndex = Spi_GstFifoCurrentCommData.ddJobIndex;
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the job structure */
    LpJobConfig = Spi_GpFirstJob + LddJobIndex;
    /* END Msg(2:2824)-17 */
    /* Get the HW Unit index */
    /* QAC Warning: START Msg(2:2814)-20 */
    LddHWUnit = LpJobConfig->ddHWUnitIndex;
    /* END Msg(2:2814)-20 */
    /* Get the base address of the HW Unit */
    LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

    /* Get the main user base address */
    LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
    /* Check if the Receive buffer is full */
    /* QAC Warning: START Msg(2:3892)- 21 */
    if (SPI_FIFO_BUFFER_FULL == Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX])
    /* END Msg(2:3892)- 21 */
    {
      /* QAC Warning: START Msg(2:2824)-17 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      /* Update the RAM data since a Reception is completed */
      Spi_GstFifoCurrentCommData.pCurrentRxData =
                     Spi_GstFifoCurrentCommData.pCurrentRxData + SPI_FIFO_SIZE;
      Spi_GstFifoCurrentCommData.ddNoOfRxBuffers =
                  Spi_GstFifoCurrentCommData.ddNoOfRxBuffers - SPI_FIFO_SIZE;
      /* END Msg(2:2824)-17 */
      /* END Msg(2:3892)- 21 */
    }
    /* END Msg (4:0488)-4 */
    else
    {
      if (SPI_ZERO < Spi_GstFifoCurrentCommData.ddNoOfRxChannels)
      {
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* MISRA Violation: START Msg(4:0489)-3 */
        /* QAC Warning: START Msg(2:2824)-17 */
        /* Increment the channel list to point to next channel */
        Spi_GstFifoCurrentCommData.pCurrentRxChannelList++;
        /* END Msg(4:0489)-3 */
        /* Decrement the number of channels */
        Spi_GstFifoCurrentCommData.ddNoOfRxChannels--;
        /* END Msg (4:0488)-4 */
        /* END Msg(2:2824)-17 */
      }
      else
      {
        /* No action required */
      }
    }
    /* Check if the Tx buffer status is Empty to initiate next transmission */
    /* QAC Warning: START Msg(2:3892)- 21 */
    if (SPI_FIFO_BUFFER_EMPTY == Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] )
    /* END Msg(2:3892)- 21 */
    {
      if (SPI_ZERO < Spi_GstFifoCurrentCommData.ddNoOfTxChannels)
      {
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* MISRA Violation: START Msg(4:0489)-3 */
        /* QAC Warning: START Msg(2:2824)-17 */
        /* Increment the channel list to point to next channel */
        Spi_GstFifoCurrentCommData.pCurrentTxChannelList++;
        /* Decrement the number of channels */
        Spi_GstFifoCurrentCommData.ddNoOfTxChannels--;
        /* END Msg (4:0488)-4 */
        LpChannelList = Spi_GstFifoCurrentCommData.pCurrentTxChannelList;
        LddNoOfChannels = Spi_GstFifoCurrentCommData.ddNoOfTxChannels;
        /* END Msg(4:0489)-3 */
        /* END Msg(2:2824)-17 */
      }
      else
      {
        /* No channels to transmit */
        LddNoOfChannels = SPI_ZERO;
      }
    }
    else
    {
      LpChannelList = Spi_GstFifoCurrentCommData.pCurrentTxChannelList;
      LddNoOfChannels = Spi_GstFifoCurrentCommData.ddNoOfTxChannels;
    }

    if (SPI_ZERO < LddNoOfChannels)
    {
       /* MISRA Violation: START Msg(4:0488)-4 */
       /* QAC Warning: START Msg(2:2814)-20 */
       /* QAC Warning: START Msg(2:2824)-17 */
       /* MISRA Violation: START Msg(4:2962)-11 */
       /* Get the pointer to the post-build structure of the channel */
      LpPBChannelConfig = Spi_GpFirstChannel + (*LpChannelList);
      /* END Msg(4:0488)-4 */
      /* END Msg(2:2814)-20 */
      /* END Msg(2:2824)-17 */
      /* END Msg(4:2962)-11 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      if (SPI_FIFO_BUFFER_FULL != Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX])
      {
        /* END Msg(2:3892)- 21 */
        /* QAC Warning: START Msg(2:2814)-20 */
        LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
        /* END Msg(2:2814)-20 */
        #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
        /* Check if the buffer type is internal buffer */
        if (SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
        #endif
        {
          #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
          /* MISRA Violation: START Msg(4:0488)-4 */
          /* QAC Warning: START Msg(2:2814)-20 */
          /* Update the RAM variable for Tx pointer with channel IB index */
          LpNextTxData = (Spi_GpConfigPtr->pChannelIBWrite) + LddBufferIndex;
          /* END Msg (4:0488)-4 */
          /* Update the RAM variable for number of buffers of the channel */
          LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;
          /* END Msg (2:2814)-20 */
          #endif
        }
        #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
        else
        #endif
        {
          #if (SPI_EB_CONFIGURED == STD_ON)
          /*
           * Update the RAM variable for Tx pointer with channel EB source
           * pointer
           */
          LpNextTxData = Spi_GaaChannelEBData[LddBufferIndex].pSrcPtr;

          /* Update the local counter with number of buffers of the channel */
          LddNoOfBuffers = Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
          #endif
        }
      }
      else
      {
        /* Load the data from RAM */
        LpNextTxData = Spi_GstFifoCurrentCommData.pNextTxData;
        LddNoOfBuffers = Spi_GstFifoCurrentCommData.ddNoOfTxBuffers;
      }
      /* QAC Warning: START Msg(2:3892)- 21 */
      if (SPI_FIFO_SIZE < LddNoOfBuffers )
      {
        /* QAC Warning: START Msg(2:2824)-17 */
        /* Set the flag to indicate Buffer is FULL */
        Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] = SPI_FIFO_BUFFER_FULL;
        /* Save the current status in RAM */
        /* MISRA Violation: START Msg(4:0488)-4 */
        Spi_GstFifoCurrentCommData.pNextTxData = LpNextTxData + SPI_FIFO_SIZE;
        Spi_GstFifoCurrentCommData.ddNoOfTxBuffers =
                                              (LddNoOfBuffers - SPI_FIFO_SIZE);
        /* Update the number of transfer bytes to max size */
        LddNoOfBuffers = SPI_FIFO_SIZE;
        /* END Msg(4:0488)-4 */
        /* END Msg(2:2824)-17 */
        /* END Msg(2:3892)- 21 */
      }
      else
      {
        /* Set the flag to indicate Buffer is Empty */
        /* QAC Warning: START Msg(2:3892)- 21 */
        Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] = SPI_FIFO_BUFFER_EMPTY;
        /* END Msg(2:3892)- 21 */
      }

      Spi_GddDmaData = LpPBChannelConfig->ddDefaultData;
      /* MISRA Violation: START Msg(4:2962)-11 */
      Spi_TxDmaConfig(LpJobConfig, LpNextTxData, LddNoOfBuffers);

    }
    else
    {
      if (SPI_TRUE == LpJobConfig->blCSRIMasked)
      {
        /* MISRA Violation: START Msg(4:0402)-13 */
        /* QAC Warning: START Msg(2:2814)-20 */
        /* Reset the PWR bit to make CS inactive since CSRI settings masked */
        LucCxCtl0 = (LpMainUserBaseAddr->ucMainCTL0 & SPI_RESET_PWR);
        SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)

        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                       LucCxCtl0, SPI_CTLREG_8_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
        /* END Msg(4:0402)-13 */
        /* END Msg(2:2814)-20 */
      }
      else
      {
        /* No action required */
      }
      /* Update the sequence status */
      Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
    }
  }
  else
  #endif /* #if (SPI_FIFO_MODE == STD_ON) */
  {
    /* Update the sequence status */
    Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
  }
}

#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* End of (SPI_DMA_MODE_ENABLE == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_HWCancel
**
** Service ID         : NA
**
** Description        : This service is for setting the JOBE bit of the
**                      HW Unit to cancel an on-going sequence
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : Sequence - Sequence ID
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init should have been invoked.
**
** Global Variable    : Spi_GstHWUnitInfo
**
** Function invoked   : None
**
** Registers Used     : CSIHnCTL0, EICn, IMRn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_031 */

#if ((((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) && \
        (SPI_CANCEL_API == STD_ON)) || (SPI_HW_PRIORITY_ENABLED == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE) Spi_HWCancel(uint8 LucIndex, uint8 LucApId)
{
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  uint8 LucCxCtl0;
  #endif
  /* Get the base address of the HW Unit */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LucIndex];

  /* Get the main base address */
  LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
  /* QAC Warning: START Msg(2:2814)-20 */
  if (SPI_ZERO != ((LpMainUserBaseAddr->ucMainCTL0) & SPI_CHECK_PWR))
  {
  /* END Msg(2:2814)-20 */
    /* Clear the pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxCancelIntCntlAddress),
                         (SPI_CLR_INT_REQ));

    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxCancelIntCntlAddress),
                         (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    /* Enable transmit cancel interrupt control */
    RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pTxCancelImrAddress),
                         (LpHWUnitInfo->usTxCancelImrMask));
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    /* Set JOBE bit of the HW Unit */
    if (SPI_MAX_NUM_OF_CSIG <= LucIndex)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      /* Set JOBE bit of the HW Unit */
      /* MISRA Violation: START Msg(4:0402)-13 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      LucCxCtl0 = (LpMainUserBaseAddr->ucMainCTL0 | SPI_SET_JOBE);
      SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                                    SPI_ZERO, (uint8)(~SPI_SET_JOBE), LucApId)

      /* END Msg(2:3892)- 21 */
      /* END Msg (4:0402)-13 */
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /* No action required */
    }
    #endif
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of ((((SPI_DUAL_BUFFER_MODE == STD_ON) ||
        * (SPI_TX_ONLY_MODE == STD_ON)) && \
        * (SPI_CANCEL_API == STD_ON)) || (SPI_HW_PRIORITY_ENABLED == STD_ON))
        */

/*******************************************************************************
** Function Name      : Spi_HWDisableInterrupts
**
** Service ID         : NA
**
** Description        : This service is for disabling all interrupts in case
**                      of polling mode
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo
**
** Function invoked   : None
**
** Registers Used     : IMRn, EICn.
**
*******************************************************************************/
/* Implements SPI_ESDD_UD_020 */
#if (SPI_LEVEL_DELIVERED == SPI_TWO)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(void, SPI_PRIVATE_CODE) Spi_HWDisableInterrupts(void)
{
  P2VAR(volatile uint16, AUTOMATIC, SPI_CONFIG_DATA) LpIntCntlAddress;
  Spi_HWUnitType LddHWUnit;

  /* Initialize number of HW Unit as zero */
  LddHWUnit = SPI_ZERO;
  /* Check for maximum HW Unit configured */
  /* MISRA Violation: START Msg(4:2877)-12 */
  do
  /* END Msg(4:2877)-12 */
  {
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pRxImrAddress;
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                       ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usRxImrMask))));
    /* END Msg(2:2814)-20 */

    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxImrAddress;



    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                       ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usTxImrMask))));


    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pErrorImrAddress;


    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                  ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usErrorImrMask))));


    #if ((((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) &&\
        (SPI_CANCEL_API == STD_ON)) || (SPI_HW_PRIORITY_ENABLED == STD_ON))
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      if (NULL_PTR != Spi_GstHWUnitInfo[LddHWUnit].pTxCancelImrAddress)
      {
        LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxCancelImrAddress;

        /* Disable interrupt processing */
        RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                 (uint16)((~(Spi_GstHWUnitInfo[LddHWUnit].usTxCancelImrMask))));
      }
      else
      {
        /* No action required */
      }
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /* No Action Required */
    }
    #endif
    #endif
    LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxIntCntlAddress;


    /* Clear Tx pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));

     LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pRxIntCntlAddress;
    /* Clear Rx pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));

     LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pErrorIntCntlAddress;
    /* Clear Error pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));


    #if ((((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) &&\
      (SPI_CANCEL_API == STD_ON)) || (SPI_HW_PRIORITY_ENABLED == STD_ON))
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      if (NULL_PTR != Spi_GstHWUnitInfo[LddHWUnit].pTxCancelIntCntlAddress)
      {
        /* Address for transmit cancel interrupt control registers (TIJC) */
        LpIntCntlAddress = Spi_GstHWUnitInfo[LddHWUnit].pTxCancelIntCntlAddress;
        /* Clear Error pending interrupt */
        RH850_SV_MODE_ICR_AND(16, (LpIntCntlAddress), (SPI_CLR_INT_REQ));
      }
      else
      {
        /* No action required */
      }
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /* No Action Required */
    }
    #endif
    #endif

    /* Increment HW Unit index */
    /* MISRA Violation: START Msg(4:2984)-10 */
    LddHWUnit++;
    /* END Msg(4:2984)-10 */
  /* MISRA Violation: START Msg(4:2993)-7 */
  /* MISRA Violation: START Msg (4:2996)-6 */
  }  while (SPI_MAX_HW_DETAILS > LddHWUnit);
  /* End of while (SPI_MAX_HW_DETAILS > LddHWUnit) */
  /* END Msg  (4:2993)-7  */
  /* END Msg  (4:2996)-6 */
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of (SPI_LEVEL_DELIVERED == SPI_TWO) */

/*******************************************************************************
** Function Name      : Spi_HWMainFunction_Handling
**
** Service ID         : Not Applicable
**
** Description        : This function is HW specific function for
**                      Spi_MainFunction_Driving API
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpConfigPtr
**
** Function Invoked   : Spi_CheckAndInvokeTxIsr, Spi_CheckAndInvokeRxIsr,
**                      Spi_ComErrorISR
**
** Registers Used     : CSIGnCTL0, CSIHnCTL0, EICn, IMRn, PORTPSRx
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
             (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements SPI_ESDD_UD_172 */
/* QAC Warning: START Msg(0:2755)-25 */
FUNC(void, SPI_PRIVATE_CODE) Spi_HWMainFunction_Handling(void)
/* END Msg(0:2755)-25 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;

  Spi_HWUnitType LddHWUnit;
  uint8 LucHWMemoryMode;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_HWUnitType LddHWUnitNumber;
  #endif

  LddHWUnit = SPI_ZERO;

  do
  {
    /* Check if the HW Unit configured */
    if (SPI_FALSE == Spi_GstHWUnitInfo[LddHWUnit].blIsSynchronous)
    {
      #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
      if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
      #endif
      {
        #if (SPI_CSIH_CONFIGURED == STD_ON)
        /* QAC Warning: START Msg(2:2814)-20 */
        LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
        /* Get the configured memory mode for this HW Unit */
        LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
        /* END Msg(2:2814)-20 */
        #endif
      }
      #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
      else
      #endif
      {
        #if (SPI_CSIG_CONFIGURED == STD_ON)
        /* Since HW Unit is CSIG, memory mode is DIRECT ACCESS by default */
        LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
        #endif
      }

      /* Get the pointer to the structure of HW Unit information */
      LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

      /* Get the main base address */
      LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
      /* QAC Warning: START Msg(2:2814)-20 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      /* Check if the HWUnit is ON */
      if (SPI_SET_PWR ==
                        (uint8)((LpMainUserBaseAddr->ucMainCTL0) & SPI_SET_PWR))
      /* END Msg(2:3892)- 21 */
      /* END Msg(2:2814)-20 */
      {
        /* START Msg(3:3352)-18 */
        /* Check if the HWUnit is busy */
        switch (LucHWMemoryMode)
        {
          #if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                          (SPI_HWUNIT_ASYNCHRONOUS == STD_ON))
        case SPI_DIRECT_ACCESS_MODE_CONFIGURED:

              Spi_CheckAndInvokeTxIsr(LpHWUnitInfo, LddHWUnit, LucHWMemoryMode);
              Spi_CheckAndInvokeRxIsr(LpHWUnitInfo, LddHWUnit, LucHWMemoryMode);
              break;
          #endif

          #if (SPI_FIFO_MODE == STD_ON)
        case SPI_FIFO_MODE_CONFIGURED:

              Spi_CheckAndInvokeTxIsr(LpHWUnitInfo, LddHWUnit, LucHWMemoryMode);

              break;
          #endif

          #if (SPI_DUAL_BUFFER_MODE == STD_ON)
        case SPI_DUAL_BUFFER_MODE_CONFIGURED:

             Spi_CheckAndInvokeTxIsr(LpHWUnitInfo, LddHWUnit, LucHWMemoryMode);

              break;
          #endif

          #if (SPI_TX_ONLY_MODE == STD_ON)
        case SPI_TX_ONLY_MODE_CONFIGURED:

             Spi_CheckAndInvokeRxIsr(LpHWUnitInfo, LddHWUnit, LucHWMemoryMode);

              break;
          #endif
        default:
             /* Dummy write operation to avoid QAC warning */
             LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
        break;
        }
        /* END Msg(3:3352)-18 */
        /* QAC Warning: START Msg(2:3892)- 21 */
        /* Check for Error Interrupt flag */
        if (SPI_INT_FLAG_MASK ==
            (uint16)((*LpHWUnitInfo->pErrorIntCntlAddress) & SPI_INT_FLAG_MASK))
        /* END Msg(2:3892)- 21 */
        {
          /* Clear the interrupt flag */
          RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                                    (SPI_CLR_INT_REQ));
          /* Invoke communication error function */
          Spi_ComErrorISR(LddHWUnit, LucHWMemoryMode);
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
    }
    #if (SPI_LEVEL_DELIVERED == SPI_TWO)
    else
    {
      /* No action required */
    }
    #endif
    /* MISRA Violation: START Msg(4:2984)-10 */
    LddHWUnit++;
    /* END Msg(4:2984)-10 */
    /* MISRA Violation: START Msg(4:2877)-12 */
    /* MISRA Violation: START Msg(4:2993)-7 */
    /* MISRA Violation: START Msg (4:2996)-6 */
  } while (SPI_MAX_HW_DETAILS > LddHWUnit);
  /* END Msg(4:2877)-12 */
  /* END Msg  (4:2993)-7  */
  /* END Msg  (4:2996)-6 */
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of ((#if ((SPI_LEVEL_DELIVERED == SPI_ONE) ||
        * ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
        * (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        * (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))))
        */

/*******************************************************************************
** Function Name      : Spi_ComErrorISR
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the TIRE ISR for processing
**                      communication error interrupt request
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit
**                      uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GaaJobResult, Spi_GpFirstJobList
**                      Spi_GaaSeqResult, Spi_GaaSeqQueue, Spi_GaaJobQueue
**                      Spi_GddQueueIndex, Spi_GpConfigPtr
**
** Function Invoked   : Dem_ReportErrorStatus, Spi_StoreErrorInfo,
**                      Spi_PopFromQueue
**
** Registers Used     : CSIGnSTR0, CSIHnSTR0, CSIGnSTCR0, CSIHnSTCR0
*******************************************************************************/
/* Implements SPI_ESDD_UD_029 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
            (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements SPI191, SPI006, SPI293, SPI174, SPI158, SPI097, SPI195 */
/* Implements AR_PN0063_FR_0093 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE) Spi_ComErrorISR
                 (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  /* If Internal Diagnosis Error Buffer size is Greater than Zero */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  Spi_CommErrorType LstErrorType;
  uint32 LulErrorValue;
  #endif

  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  Spi_JobType LddJobIndex;

  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  Spi_HWUnitType LddHWUnitNumber;
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  Spi_JobType LddJobListIndex;
  #endif

  Spi_SequenceType LddSeqIndex;

  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

   /* Get the main base address */
  LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
  /* If Internal Diagnosis Error Buffer size is Greater than Zero */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Take the Error value as backup */
  LulErrorValue = LpMainUserBaseAddr->ulMainSTR0;
  #endif

  if ((uint32)SPI_ZERO != (LpMainUserBaseAddr->ulMainSTR0 & SPI_PARITY_DCC_ERR))
  {
    /* QAC Warning: START Msg(2:3892)- 21 */

        /* Clear the status register */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                            (uint16)(~(SPI_PARITY_DCC_ERR_CLR)))
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
              (uint32)((uint16)(~SPI_PARITY_DCC_ERR_CLR)),SPI_ASYNCTRANSMIT_SID)

    /* END Msg(2:3892)- 21 */
    /* END Msg(2:2814)-20 */
    /* Implements SPI_ESDD_UD_122 */
    /*Report error to DEM*/
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    /* No action required */
  }

  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON)) \
        && ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
  if (SPI_TWO > LucHWMemoryMode)
  #endif
  {
    #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
          (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON))
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpJobList = Spi_GpFirstJobList +
                 Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Get the index of the first job linked to this sequence */
    LddJobIndex = LpJobList->ddJobIndex;
    /* END Msg(2:2814)-20 */
    /* Get the index of the sequence */
    LddSeqIndex = LpJobList->ddSequenceIndex;

    #if ((SPI_FIFO_MODE == STD_ON) && (SPI_DEV_ERROR_DETECT == STD_ON))
    if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
    {
      /* Check if overrun error has occurred */
      if ((uint32)SPI_ZERO !=
                       (LpMainUserBaseAddr->ulMainSTR0 & SPI_OVRFLW_OVRRUN_ERR))
      {
        /* QAC Warning: START Msg(2:2814)-20 */
        SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                         (uint16)(~(SPI_OVRFLW_OVRRUN_ERR_CLR)))
        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
        LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
           (uint32)((uint16)(~SPI_OVRFLW_OVRRUN_ERR_CLR)),SPI_ASYNCTRANSMIT_SID)

        /* END Msg(2:2814)-20 */
        /* Report error to DEM */
        Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
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
    #endif /* End of #if ((SPI_FIFO_MODE == STD_ON) &&
            * (SPI_DEV_ERROR_DETECT == STD_ON))
            */
    #endif /* End of #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
            * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON))
            */
  }
  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON)) \
      && ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)))
  else
  #endif
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    /* QAC Warning: START Msg(2:2824)-17 */
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */
    /* Get the job list index of the last job of the sequence */
    LddJobListIndex = LpSeqConfig->ddJobListIndex;
    /* Get the index of the job list for the first job of the sequence */
    LddJobListIndex = LddJobListIndex + ((LpSeqConfig->ddNoOfJobs) - SPI_ONE);
    /* Get the pointer to the respective job list index  */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* MISRA Violation: START Msg(4:2962)-11 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpJobList = Spi_GpFirstJobList + LddJobListIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg (4:2962)-11 */
    /* END Msg (4:0488)-4 */
    /* Get the index of the job */
    LddJobIndex = LpJobList->ddJobIndex;
    #endif
    /* END Msg(2:2814)-20 */
  }
  /* If Internal Diagnosis Error Buffer size is Greater than Zero */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  /* Copy the Hardware unit Index */
  LstErrorType.HwUnit = LpHWUnitInfo->ucHWUnit;
  /* Copy the Sequence Index */
  LstErrorType.SeqID = LddSeqIndex;
  /* Copy the Job Index */
  /* MISRA Violation: START Msg(4:2962)-11 */
  LstErrorType.JobID = LddJobIndex;
  /* END Msg(4:2962)-11 */
  /* Check for Over run Error */
  if (SPI_OVE_ERR == (LulErrorValue & SPI_OVE_ERR))
  {
    LstErrorType.ErrorType = SPI_OVERRUN_ERROR;
    /* Report Error Details */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }
  /* Check for Parity Error */
  if (SPI_PE_ERR == (LulErrorValue & SPI_PE_ERR))
  {
    LstErrorType.ErrorType = SPI_PARITY_ERROR;
    /* Report Error Details */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }
  /* Check for Data Consistency Error */
  if (SPI_DCE_ERR == (LulErrorValue & SPI_DCE_ERR))
  {
    LstErrorType.ErrorType = SPI_DATA_CONSISTENCY_ERROR;
    /* Report Error Details */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }
  /* Check for Overflow Error */
  if (SPI_OFE_ERR == (LulErrorValue & SPI_OFE_ERR))
  {
    LstErrorType.ErrorType = SPI_OVERFLOW_ERROR;
    /* Report Error Details */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }
 #endif
   /* Job is failed. Update job result as FAILED */
  Spi_GaaJobResult[LddJobIndex] = SPI_JOB_FAILED;
  /* Sequence is failed. Update sequence result as FAILED */
  Spi_GaaSeqResult[LddSeqIndex] = SPI_SEQ_FAILED;
}

#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* End of #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        * (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
        * (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
        */

/*******************************************************************************
** Function Name      : Spi_LoopBackSelfTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data transmission self test
**                      using loop back mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo
**
** Function Invoked   : Spi_CsigLoopBackSelfTest, Spi_CsihLoopBackSelfTest,
**                      Dem_ReportErrorStatus
**
** Registers Used     : CSIGnCTL0, CSIHnCTL0, IMRn, EICn
*******************************************************************************/
/* Check if LooP back self test is configured for calling it in Init or
                                                                    Run time */
/* Implements SPI_ESDD_UD_018 */
/* Implements SPI_ESDD_UD_098 */
 #if (SPI_LOOPBACK_SELFTEST == SPI_ONE ||SPI_LOOPBACK_SELFTEST == SPI_TWO )
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements AR_PN0063_FSR_0211, AR_PN0063_FSR_0202, EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0068 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_LoopBackSelfTest(void)
{
  Std_ReturnType LenReturnValue;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr;
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  P2VAR(volatile uint16, AUTOMATIC, SPI_CONFIG_DATA) LpIntCntlAddress;
  #endif
  Spi_HWUnitType LddHWUnit;
  uint8  LucData;
  /* Initialize Return Value */
  LenReturnValue = E_OK;
  /* Initialize number of HW Unit as zero */
  LddHWUnit = SPI_ZERO;
  /* Check for maximum HW Unit configured */
  /* MISRA Violation: START Msg(4:2877)-12 */
  while ((SPI_MAX_HW_DETAILS > LddHWUnit) && (LenReturnValue == E_OK))
  /* END Msg(4:2877)-12 */
  {
    /* Get the pointer to the structure of HW Unit information */
    LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

    #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
    /* Clear pending interrupts */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                                             (SPI_CLR_INT_REQ));
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                                             (SPI_CLR_INT_REQ));
    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                                             (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    LpIntCntlAddress = LpHWUnitInfo->pRxImrAddress;

    /* QAC Warning: START Msg(2:2814)-20 */
    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                      ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usRxImrMask))));
    /* END Msg(2:2814)-20 */
    LpIntCntlAddress = LpHWUnitInfo->pTxImrAddress;

    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                       ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usTxImrMask))));

    LpIntCntlAddress = LpHWUnitInfo->pErrorImrAddress;

    /* Disable interrupt processing */
    RH850_SV_MODE_IMR_OR(16, (LpIntCntlAddress),
                    ((uint16)(~(Spi_GstHWUnitInfo[LddHWUnit].usErrorImrMask))));

    #endif
    /* Get the main user base address */
    LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
    /* Get the main OS base address */
    LpMainOsBaseAddr = LpHWUnitInfo->pHwMainOsBaseAddress;
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Reset the PWR bit since other registers need to be written */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_ZERO)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
                            SPI_ZERO,SPI_CTLREG_8_BIT_MASK,SPI_SELFTEST_SID)

    /* END Msg(2:2814)-20 */
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
        LucData = Spi_CsigLoopBackSelfTest(LpHWUnitInfo,
                                          LpMainUserBaseAddr, LpMainOsBaseAddr);
      #endif /* #if (SPI_CSIG_CONFIGURED == STD_ON) */
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      LucData = Spi_CsihLoopBackSelfTest(LpHWUnitInfo,
                                         LpMainUserBaseAddr, LpMainOsBaseAddr);
      #endif /* #if (SPI_CSIH_CONFIGURED == STD_ON) */
    }
    if (SPI_LOOPBACK_DATA != LucData)
    {
      Dem_ReportErrorStatus(SPI_E_LOOPBACK_SELFTEST_FAILURE,
                                                   DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
       /* No action required */
    }
    /* Increment HW Unit index */
    /* MISRA Violation: START Msg(4:2984)-10 */
    LddHWUnit++;
    /* END Msg(4:2984)-10 */
  }/* End of while (SPI_MAX_HW_DETAILS > LddHWUnit) */
  return LenReturnValue;
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of #if (SPI_LOOPBACK_SELFTEST == SPI_ONE
                                       ||SPI_LOOPBACK_SELFTEST == SPI_TWO )*/
/*******************************************************************************
** Function Name      : Spi_EccSelfTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc self test
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo
**
** Function Invoked   : Spi_EccAllZeroTest, Spi_EccAllOneTest,
**                      Spi_EccWalkOneTest, Spi_EccTwoBitTest
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTMC.
*******************************************************************************/
/* Implements SPI_ESDD_UD_019    */
/* Implements SPI_ESDD_UD_099    */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_EccSelfTest(void)
{
  P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  Spi_HWUnitType LddHWUnit;
  Std_ReturnType LenReturnValue;
  uint8 LucTestPattern;
  LenReturnValue = E_OK;
  LddHWUnit = SPI_ZERO;
  LucTestPattern = SPI_ZERO;
  /* Check for maximum HW Unit configured */
  /* MISRA Violation: START Msg(4:2877)-12 */
  while ((SPI_MAX_HW_DETAILS > LddHWUnit) && (LenReturnValue == E_OK))
  /* END Msg(4:2877)-12 */
  {
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Get the pointer to the structure of HW Unit information */
      LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
      /* Get the ECC Base Address */
      LpEccBaseAddr = LpHWUnitInfo->pEccBaseAddress;
      /* Set ECREIS, ECDCS, ECTRRS, ECTMCE AND ETMA[1:0] bits of TMC register */
      LpEccBaseAddr->usEccTmc = (uint16)(LpEccBaseAddr->usEccTmc| SET_TMC_BITS);
      /* Enable one bit and 2 bit error detection */
      LpEccBaseAddr->ulEccCTL = (uint32)SET_EC1EDIC_EC2EDIC;
      /* END Msg(2:2814)-20 */
      do
      {
        switch (LucTestPattern)
        {
        case SPI_ZERO :  /* All-0 Test Pattern */
                       LenReturnValue = Spi_EccAllZeroTest(LpEccBaseAddr);
                       break;
        case SPI_ONE :  /* All ONE test pattern */
                      LenReturnValue = Spi_EccAllOneTest(LpEccBaseAddr);
                      break;
        case SPI_TWO :  /* Walk One Test Pattern */
                      LenReturnValue = Spi_EccWalkOneTest(LpEccBaseAddr);
                      break;
        case SPI_THREE :  /* Two Bit test pattern */
                         LenReturnValue = Spi_EccTwoBitTest(LpEccBaseAddr);
                         break;
        /*Start : SPI_UT_003*/
        default:  /* Dummy assigning of return value */
                  LenReturnValue = E_NOT_OK;
                break;
        /* End : SPI_UT_003 */
        }
      LucTestPattern++;
      }while ((SPI_THREE >= LucTestPattern) && (E_NOT_OK != LenReturnValue));

    /* Set ECTMCE =0 in TMC register */
    LpEccBaseAddr->usEccTmc = SET_TEST_DISABLE;
    }
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    else
    {
      /*No action required */
    }
    #endif
    /* Iterate through all the CSIH HwUnits configured */
    LddHWUnit++;
    /* Reset the test pattern to continue ECC self test for next Hw unit */
    LucTestPattern = SPI_ZERO;
  }

  /* Return test status */
  return LenReturnValue;
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of #if (SPI_ECC_SELFTEST == SPI_ONE
                                      || SPI_ECC_SELFTEST == SPI_TWO) */
#endif

/*******************************************************************************
** Function Name      : Spi_InitDetCheck
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Det checks of Spi_Init Api.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST)
**                                                                     ConfigPtr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : boolean
**
** Preconditions      : None
**
** Global Variable    : Spi_GddDriverStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_043 */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI233, SPI246, SPI029, SPI007, EAAR_PN0034_FR_0064 */
/* Implements SPI_ESDD_UD_106 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(boolean, SPI_PRIVATE_CODE) Spi_InitDetCheck
                  (P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr)
/* END Msg(2:3227)-16 */
{
  boolean LblErrorFlag;

  LblErrorFlag = SPI_FALSE;
  /* Implements SPI_ESDD_UD_116 */
  /* Check if SPI configuration pointer is a NULL Pointer */
  if (NULL_PTR == ConfigPtr)
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                              SPI_INIT_SID, SPI_E_PARAM_CONFIG);
    LblErrorFlag = SPI_TRUE;
  }
  else
  {
    /* Implements SPI_ESDD_UD_095 */
    /* Implements SPI_ESDD_UD_115 */
    #if (SPI_ALREADY_INIT_DET_CHECK == STD_ON)
    /* QAC Warning: START Msg(2:3416)-24 */
    if (SPI_UNINIT != Spi_GddDriverStatus)
    /* END Msg(2:3416)-24 */
    {
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                    SPI_INIT_SID, SPI_E_ALREADY_INITIALIZED);
      LblErrorFlag = SPI_TRUE;
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (SPI_ALREADY_INIT_DET_CHECK == STD_ON) */
  }
  return LblErrorFlag;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name      : Spi_AsyncDetCheck
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Det checks in
**                      Spi_AsyncTransmit Api.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_SequenceType Sequence
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : Spi_GddDriverStatus, Spi_GpFirstSeq, Spi_GpFirstJobList
**                      Spi_GpFirstJob, Spi_GaaSeqResult, Spi_GstHWUnitInfo
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_047 */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI046, SPI032, SPI055, SPI081, SPI243, SPI266 */
/* Implements EAAR_PN0034_FR_0064 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_AsyncDetCheck
                                                    (Spi_SequenceType Sequence)
/* END Msg(2:3227)-16 */
{
  #if (SPI_LEVEL_DELIVERED == SPI_TWO)
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;

  Spi_JobType LddJobListIndex;

  #endif /* (SPI_LEVEL_DELIVERED == SPI_TWO) */
  Std_ReturnType LenReturnValue;

  LenReturnValue = E_OK;
  /* Check if SPI Driver is initialized */
  /* QAC Warning: START Msg(2:3416)-24 */
  if (SPI_UNINIT == Spi_GddDriverStatus)
  /* END Msg(2:3416)-24 */
  {
    /* Report to DET */
    (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                           SPI_ASYNCTRANSMIT_SID, SPI_E_UNINIT);
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
                                        SPI_ASYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET error has occurred to check other DET errors */
  if (E_OK == LenReturnValue)
  {
    #if (SPI_LEVEL_DELIVERED == SPI_TWO)
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the sequence structure */
    LpSeqConfig = Spi_GpFirstSeq + Sequence;
    /* END Msg(2:2824)-17 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Get the job list index of the last job of the sequence */
    LddJobListIndex = LpSeqConfig->ddJobListIndex;
    /* END Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the job list */
    LpJobList = Spi_GpFirstJobList + LddJobListIndex;
    /* Get the pointer of the last job linked to this sequence */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpJobConfig = Spi_GpFirstJob + (LpJobList->ddJobIndex);
    /* END Msg(4:0488)-4 */
    /* END Msg(2:2814)-20 */
    /* END Msg(2:2824)-17 */
    #endif
    /* Check if the requested sequence already pending */
    if (SPI_SEQ_PENDING == Spi_GaaSeqResult[Sequence])
    {
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                                    SPI_ASYNCTRANSMIT_SID, SPI_E_SEQ_PENDING);
      LenReturnValue = E_NOT_OK;
    }

    #if (SPI_LEVEL_DELIVERED == SPI_TWO)
    /*
     * Check if the HW Unit of the job is configured for synchronous
     * transmission
     */
    /* Implements SPI_ESDD_UD_110 */
    /* QAC Warning: START Msg(2:2814)-20 */
    else if (SPI_TRUE ==
                (Spi_GstHWUnitInfo[LpJobConfig->ddHWUnitIndex].blIsSynchronous))
    /* END Msg(2:2814)-20 */
    {
      /* Report to DET */
      (void)Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID,
                               SPI_ASYNCTRANSMIT_SID, SPI_E_PARAM_SEQ);
      LenReturnValue = E_NOT_OK;
    }
    #endif /* (SPI_LEVEL_DELIVERED == SPI_TWO) */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }
    return LenReturnValue;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_SyncRegSettings
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform register settings in
**                      HwTransmitSyncJob function.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                   LpJobConfig
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpConfigPtr
**
** Function Invoked   : None
**
** Registers Used     : CSIHnMCTL0, CSIGnCTL0, CSIGnCFG0, CSIHnCTL0, CSIGnSTCR0,
**                      CSIHnSTCR0, CSIGnCTL1, CSIHnCTL1, CSIGnCTL2, CSIHnCTL2,
**                      CSIHnCFGx, CSIHnBRSy, CSIGnSTR0, CSIHnSTR0.
*******************************************************************************/
/* Implements SPI_ESDD_UD_059 */
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* Implements SPI213_Conf, SPI211_Conf, AR_PN0063_FR_0029, SPI208_Conf */
/* Implements AR_PN0063_FR_0009 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE)Spi_SyncRegSettings
          (P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr;
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  /* Defining a local pointer variable to hold the OS base address of CSIG */
  P2VAR(Spi_CsigOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigOsBaseAddr;
  #endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpChipSelect;
  /* Defining a local pointer variable to hold the OS base address of CSIH */
  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  /* Declare a local pointer to point to the Configured chip select of job */
  Spi_HWUnitType LddHWUnitNumber;
  uint8 LucVar;
  uint32 LulBRSRegIndex;
  uint16 LusCxCtl2;
  #endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
  uint32 LulCxCTL1;
  uint8 LucCxCtl0;
  Spi_HWUnitType LddHWUnit;
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;
  /* END Msg(2:2814)-20 */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* Get the main user base address */
  LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
  /* Get the main OS base address */
  LpMainOsBaseAddr = LpHWUnitInfo->pHwMainOsBaseAddress;
  /* MISRA Violation: START Msg(4:0402)-13 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Reset the PWR bit since other registers need to be written */

  LucCxCtl0 = (LpMainUserBaseAddr->ucMainCTL0 & SPI_RESET_PWR);
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
   LucCxCtl0, SPI_CTLREG_8_BIT_MASK, SPI_SYNCTRANSMIT_SID)
  /* END Msg(2:2814)-20 */
  /* END Msg(4:0402)-13 */
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
  #endif /* ((SPI_CSIG_CONFIGURED == STD_ON) &&
          * (SPI_CSIH_CONFIGURED == STD_ON))
          */
  {
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:3892)-21 */
    /* Clear the status register */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0, SPI_CSIG_CLR_STS_FLAGS)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME( LpMainUserBaseAddr->ulMainSTR0,
    (uint32)SPI_ZERO, (uint32)(SPI_CSIG_CLR_STS_FLAGS), SPI_SYNCTRANSMIT_SID)

    /* MISRA Violation: START Msg(4:0316)-9 */
    LpCsigOsBaseAddr = (Spi_CsigOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
    /* END Msg (4:0316)-9*/
    /*Load the control register 1 with Ctl1 register value of current Job */
    LulCxCTL1 = (LpJobConfig->ulMainCtl1Value & SPI_CSIG_CTLREG_MASK);

    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
                     LulCxCTL1, SPI_CSIG_CTLREG_MASK, SPI_SYNCTRANSMIT_SID)
    /* END Msg(2:2814)-20 */
    /* Set the SLIT bit */
    /* MISRA Violation: START Msg(4:0402)-13 */
    LulCxCTL1 =  (LpMainOsBaseAddr->ulMainCTL1 | SPI_SET_SLIT);
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
                       LulCxCTL1, SPI_CTLREG_32_BIT_MASK, SPI_SYNCTRANSMIT_SID)

    /* END Msg(4:0402)-13 */
    /* Update the Baud rate and Pre-scalar values from control register2 */
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, LpJobConfig->usCtl2Value)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
      LpJobConfig->usCtl2Value, SPI_CTLREG_16_BIT_MASK, SPI_SYNCTRANSMIT_SID)
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Load the values for configuring chip select */
    SPI_CSIGH_REG_WRITE(LpCsigOsBaseAddr->ulCSIGCFG0,
                                                LpJobConfig->ulConfigRegValue)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigOsBaseAddr->ulCSIGCFG0,
    LpJobConfig->ulConfigRegValue, SPI_CSIGCFG0_MASK, SPI_SYNCTRANSMIT_SID)

    /* END Msg(2:2814)-20 */
    /* Load the control register 0 value, setting PWR bit at the same time */

    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_DIRECT_ACCESS)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
    SPI_SET_DIRECT_ACCESS, SPI_CTLREG_8_BIT_MASK,  SPI_SYNCTRANSMIT_SID)
    /* END Msg(2:3892)-21 */
    #endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  #endif /* ((SPI_CSIG_CONFIGURED == STD_ON) &&
          *  (SPI_CSIH_CONFIGURED == STD_ON))
          */
  {
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* Clear the status register */
    /* QAC Warning: START Msg(2:2814)-20 */

    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0, SPI_CSIH_CLR_STS_FLAGS)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME( LpMainUserBaseAddr->ulMainSTR0,
    (uint32)SPI_ZERO, (uint32)(SPI_CSIH_CLR_STS_FLAGS), SPI_SYNCTRANSMIT_SID)

    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    /* END Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0316)-9 */
    /* Get the CSIH base address */
    LpCsihOsBaseAddr = (Spi_CsihOsRegs *)(LpHWUnitInfo->pHwOsBufferAddress);
    /* END Msg (4:0316)-9*/
    /*
     * Load the local union variable with Ctl1 register value of current Job
     * with CSRI bit masked
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess1.ulRegData = LpJobConfig->ulMainCtl1Value & SPI_CSRI_AND_MASK;
    /* Write the value with configured polarity of all chip selects */
    LunDataAccess1.ucRegData4[SPI_ONE] =
                            Spi_GpConfigPtr->aaChipSelect[LddHWUnitNumber];
    /* END Msg(2:2814)-20 */
    /* Load the control register 1 with the value of local union variable */
    /* QAC Warning: START Msg(2:2814)-20 */
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LunDataAccess1.ulRegData)
    /* END Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:3892)-21 */
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
    LunDataAccess1.ulRegData, SPI_CTLREG_32_BIT_MASK, SPI_SYNCTRANSMIT_SID)

    /* Set the SLIT bit */
    LulCxCTL1 =  (LpMainOsBaseAddr->ulMainCTL1 | SPI_SET_SLIT);
    /* MISRA Violation: START Msg(4:0402)-13 */
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
                        LulCxCTL1, SPI_CTLREG_32_BIT_MASK, SPI_SYNCTRANSMIT_SID)
    /* END Msg (4:0402)-13 */
    /* Update the Pre-scalar value from control register2 */
    LusCxCtl2 = ((LpJobConfig->usCtl2Value) & SPI_CSIH_PRE_MASK);
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, LusCxCtl2)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
                        LusCxCtl2, SPI_CTLREG_16_BIT_MASK, SPI_SYNCTRANSMIT_SID)

    /* QAC Warning: START Msg(2:2814)-20 */
    /* Initialize CSIH memory register */
    SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->usCSIHMCTL0,
                                                      LpJobConfig->usMCtl0Value)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihOsBaseAddr->usCSIHMCTL0,
    LpJobConfig->usMCtl0Value, SPI_CSIHMCTL0_MASK, SPI_SYNCTRANSMIT_SID)

    LulBRSRegIndex = (((LpJobConfig->ulConfigRegValue) &
                                      SPI_CSIH_BRS_SELECT_MASK) >> SPI_THIRTY);
    /* Update the Baud rate value from control register2 */
    LusCxCtl2 = ((LpJobConfig->usCtl2Value) & SPI_CSIH_BRS_MASK);
    SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->stCSIHBRS[LulBRSRegIndex].usCSIHBRS,
                                                                      LusCxCtl2)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpCsihOsBaseAddr->stCSIHBRS[LulBRSRegIndex].usCSIHBRS, LusCxCtl2,
                                         SPI_CSIHBRS_MASK, SPI_SYNCTRANSMIT_SID)

    /* END Msg(2:2814)-20 */
    /* END Msg(2:3892)-21 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* Get the value for multiple chip selects configured  */
    LpChipSelect = (Spi_GpConfigPtr->pCSArray) + (LpJobConfig->ucCSArrayIndex);
    /* END Msg (4:0488)-4 */

    /* Load the number of chip selects */
    LucVar = LpJobConfig->ucNoOfCS;
    do
    {
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Initialize CSIH configuration register */
      SPI_CSIGH_REG_WRITE( LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
                          LpJobConfig->ulConfigRegValue)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
      LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
      LpJobConfig->ulConfigRegValue, SPI_CSIHCFG_MASK, SPI_SYNCTRANSMIT_SID)

      /* END Msg(2:2814)-20 */
      /* Decrement the number of chip selects */
      LucVar--;

      /* MISRA Violation: START Msg(4:0489)-3 */
      LpChipSelect++;
      /* END Msg (4:0489)-3 */
    }while (SPI_ZERO < LucVar);

    /* Load Main CTL0 register, setting PWR bit at the same time */

    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_DIRECT_ACCESS)
    /* QAC Warning: START Msg(2:3892)-21 */
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
    SPI_SET_DIRECT_ACCESS, SPI_CTLREG_8_BIT_MASK, SPI_SYNCTRANSMIT_SID)
    /* END Msg(2:3892)-21 */
    #endif /*#if (SPI_CSIH_CONFIGURED == STD_ON)*/
  }
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_SyncProcessData
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data processing of channel
**                      in Synchronous transmission.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** Input Parameters   : P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpJobConfig,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                      Spi_ChannelType LddNoOfChannels
**
** Output Parameters  : None
**
** Return parameter   : boolean
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpConfigPtr, Spi_GaaChannelEBData
**
** Function Invoked   : Spi_GetCsigRxData, Spi_GetCsihRxData, Spi_SetEojBit
**                      Spi_GetCurrentRxData, Spi_CsihTxDataAndErrorProcessing
**                      Spi_CsigTxDataAndErrorProcessing,
**                      Spi_SetEojAndCsriBits/Spi_SetEojBit,
**
** Registers Used     : None
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* Implements SPI_ESDD_UD_174 */
/* Implements SPI165, SPI224_Conf */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC( Std_ReturnType, SPI_PRIVATE_CODE)Spi_SyncProcessData
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_ChannelType LddNoOfChannels,Spi_SequenceType LddSequenceID,
                                                           Spi_JobType LddJobID)
/* END Msg(2:3227)-16 */
#else
/* QAC Warning: START Msg(2:3227)-16 */
FUNC( Std_ReturnType, SPI_PRIVATE_CODE)Spi_SyncProcessData
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_ChannelType LddNoOfChannels)
/* END Msg(2:3227)-16 */
#endif
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr;
  #endif
  #endif
  #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) || (SPI_EB_CONFIGURED == STD_ON))
  P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData;
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData;
  Spi_NumberOfDataType LddBufferIndex;
  #if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  #endif

  Std_ReturnType LenReturnValue;

  #endif
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess2;
  /* END Msg(4:0759)-1 */

  Spi_DataType LddData;

  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  uint32 LulShiftData;
  #endif
  Spi_DataAndErrorFlag Spi_SyncDataFlag;
  Spi_NumberOfDataType LddNoOfTxBuffers;
  Spi_NumberOfDataType LddNoOfRxBuffers;
  Spi_HWUnitType LddHWUnit;
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;
  /* END Msg(2:2814)-20 */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  LpDataAndDemFlag = &Spi_SyncDataFlag;

  #if ((SPI_EB_CONFIGURED == STD_ON) || (SPI_INTERNAL_RW_BUFFERS == STD_ON))
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the buffer index value */
  LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
  /* END Msg(2:2814)-20 */
  #endif
  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  /* Check if the buffer type is internal buffer */
  if (SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
  #endif
  {
    #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Update the RAM variable for Tx pointer with channel IB index */
    LpNextTxData = Spi_GpConfigPtr->pChannelIBWrite;
    /* END Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpNextTxData = LpNextTxData + LddBufferIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */
    /* Update the RAM variable for number of buffers of the channel */
    LddNoOfTxBuffers = LpPBChannelConfig->ddNoOfBuffers;
    #endif
  }
  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  else
  #endif
  {
    #if (SPI_EB_CONFIGURED == STD_ON)
    /*
    * Update the RAM variable for Tx pointer with channel EB
    * source pointer
    */
    LpNextTxData = Spi_GaaChannelEBData[LddBufferIndex].pSrcPtr;
    /* Update the local counter with number of buffers of the channel */
    LddNoOfTxBuffers = Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
    #endif
  }

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  LpCurrentRxData = Spi_GetCurrentRxData
                 (LpPBChannelConfig->ucChannelBufferType, LddBufferIndex);
  #else
  LpCurrentRxData = Spi_GetCurrentRxData(LddBufferIndex);
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* Get the main OS base address */
  LpMainOsBaseAddr = LpHWUnitInfo->pHwMainOsBaseAddress;
  #endif
  #endif
  #if ((SPI_EB_CONFIGURED == STD_ON) || (SPI_INTERNAL_RW_BUFFERS == STD_ON))
  /* MISRA Violation: START Msg(4:2962)-11 */
  LddNoOfRxBuffers = LddNoOfTxBuffers;
  /* END Msg(4:2962)-11 */
  #endif
  do
  {
    /*
     * Take a local union variable to construct the value for TX0W
     * register
     */
    LunDataAccess2.ulRegData = SPI_ZERO;
    #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) || (SPI_EB_CONFIGURED == STD_ON))
    /* Check if the source pointer is NULL pointer */
    if (NULL_PTR == LpNextTxData)
    #endif /* ((SPI_INTERNAL_RW_BUFFERS == STD_ON) ||
            *  (SPI_EB_CONFIGURED == STD_ON))
            */
    {
      /* Get the configured default value */
      LddData = LpPBChannelConfig->ddDefaultData;
    }
    #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) || (SPI_EB_CONFIGURED == STD_ON))
    else
    {
      /* Get the value from the source pointer */
      LddData = *LpNextTxData;
      /* MISRA Violation: START Msg(4:0489)-3*/
      LpNextTxData++;
      /* END Msg (4:0489)-3 */
    }
    #endif

    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      /* Set the EOJ bit & CSRI bit to inactive state before the last job */
      #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
      Spi_SetEojAndCsriBits( LpJobConfig, LpMainOsBaseAddr,
                           &LunDataAccess2, LddNoOfTxBuffers, LddNoOfChannels );
      #else
      Spi_SetEojBit(&LunDataAccess2, LddNoOfTxBuffers, LddNoOfChannels);
      #endif
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /*No action required since EOJ and CSRI bits are not valid for CSIG H/W */
    }
    #endif

    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, load Tx data portion of the
     * local variable with the 8-bit data to be transmitted
     */
    LunDataAccess2.Tst_ByteAccess.usRegData1 = (uint16)LddData;
    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 16-bit. Hence, load Tx data portion of the
     * local variable with the 16-bit data to be transmitted
     */
    LunDataAccess2.Tst_ByteAccess.usRegData1 = LddData;
    #else
    if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
        (SPI_TRUE != LpPBChannelConfig->blDirection) &&
        (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
        (SPI_ONE <= LpPBChannelConfig->ucDLSSetting)
       )
    {
      LulShiftData = (uint32)LddData;
      LulShiftData = (uint32)(LulShiftData << (SPI_SIXTEEN -
                                        (LpPBChannelConfig->ucDLSSetting)));
      LunDataAccess2.ulRegData = LulShiftData;
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
      LunDataAccess2.usRegData5[SPI_ZERO] >> (SPI_SIXTEEN -
                                         (LpPBChannelConfig->ucDLSSetting));
      LunDataAccess2.usRegData5[SPI_ZERO] =
                                       LunDataAccess1.Tst_ByteAccess.usRegData1;
    }
    else
    {
      /*
       * Data width is maximum 32-bit. Tx data needs to be split to
       * LS Byte and MS Byte. Hence, load the Tx data to local union variable
       */
      LunDataAccess2.ulRegData = LddData;
    }
    #endif /* End of (SPI_8BIT_DATA_WIDTH == STD_ON) */
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
      LenReturnValue = Spi_CsigTxDataAndErrorProcessing(LpHWUnitInfo,
                    LpPBChannelConfig, LunDataAccess2, LddSequenceID, LddJobID);
      #else
      LenReturnValue = Spi_CsigTxDataAndErrorProcessing(LpHWUnitInfo,
                                             LpPBChannelConfig, LunDataAccess2);
      #endif
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
      LenReturnValue = Spi_CsihTxDataAndErrorProcessing(LpJobConfig,
                    LpPBChannelConfig, LunDataAccess2, LddSequenceID, LddJobID);
      #else
      LenReturnValue = Spi_CsihTxDataAndErrorProcessing(LpJobConfig,
                                             LpPBChannelConfig, LunDataAccess2);
      #endif
      #endif
       /* End of #if (SPI_CSIH_CONFIGURED == STD_ON)*/
    }
    /* Checking of Dem error for exit time out for HW status Registers */
    if (E_OK == LenReturnValue)
    {
      LddNoOfTxBuffers--;

      if (SPI_ZERO < LddNoOfRxBuffers)
      {
        #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
        if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
        #endif
        {
          #if (SPI_CSIG_CONFIGURED == STD_ON)
          #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
          Spi_GetCsigRxData(LpHWUnitInfo, LpPBChannelConfig,
                                     LpDataAndDemFlag, LddSequenceID, LddJobID);
          #else
          Spi_GetCsigRxData(LpHWUnitInfo, LpPBChannelConfig, LpDataAndDemFlag);
          #endif
          #endif
        }
        #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
        else
        #endif
        {
          #if (SPI_CSIH_CONFIGURED == STD_ON)
          #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
          Spi_GetCsihRxData(LpHWUnitInfo, LpPBChannelConfig,
                                     LpDataAndDemFlag, LddSequenceID, LddJobID);
          #else
          Spi_GetCsihRxData(LpHWUnitInfo, LpPBChannelConfig, LpDataAndDemFlag);
          #endif
          #endif
        }
        LenReturnValue = LpDataAndDemFlag->ddReturnValue;
        if (E_OK == LenReturnValue)
        {
          /* Decrement the number of buffers received */
          LddNoOfRxBuffers--;
          #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) || \
                                                  (SPI_EB_CONFIGURED == STD_ON))
          if (NULL_PTR != LpCurrentRxData)
          {
            *LpCurrentRxData = LpDataAndDemFlag->ddData;
            /* MISRA Violation: START Msg(4:0489)-3 */
            LpCurrentRxData++;
            /* END Msg (4:0489)-3 */
          }
          else
          {
            /* No Action Required */
          }
          #endif
        }
        else
        {
          /* No Action Required */
        }
      }
      /*Start : SPI_UT_009*/
      else
      {
        /* No Action Required */
      }
      /* End : SPI_UT_009 */
    }
    else
    {
      /* No Action Required */
    }
  }while ((E_OK == LenReturnValue) && ((SPI_ZERO < LddNoOfTxBuffers) ||
                            ((SPI_ZERO < LddNoOfRxBuffers) &&
                            (SPI_TRUE == LpJobConfig->blIsChannelPropSame))));
  return LenReturnValue;

}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name      : Spi_CsigTxDataAndErrorProcessing
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data processing for CSIG H/W
**                      in Synchronous transmission.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpHWUnitInfo,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                      Spi_DataAccess LunDataAccess2
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : boolean
**
** Preconditions      : None
**
** Global Variable    : Spi_GusSynDataAccess
**
** Function Invoked   : Spi_CheckRegEmpty, Spi_CheckErrorInt
**
** Registers Used     : CSIGnTX0W, CSIGnRX0.
*******************************************************************************/
/* Implements SPI_ESDD_UD_061 */
#if ((SPI_CSIG_CONFIGURED == STD_ON)&&((SPI_LEVEL_DELIVERED == SPI_ZERO) || \
     ((SPI_LEVEL_DELIVERED == SPI_TWO) &&(SPI_DIRECT_ACCESS_MODE == STD_ON))))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* Implements SPI_ESDD_UD_200 */
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
/* MISRA Violation: START Msg(4:0759)-1 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsigTxDataAndErrorProcessing
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2, Spi_SequenceType LddSequenceID,
                                                           Spi_JobType LddJobID)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
#else
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsigTxDataAndErrorProcessing
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
#endif
/* END Msg(4:0759)-1 */
{
  /* Defining a local pointer variable to hold the user address of CSIG */
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;

  Std_ReturnType LenReturnValue;

  #if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  #endif
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess3;
  /* END Msg(4:0759)-1 */
  #endif
   LenReturnValue = E_OK;
  #if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
    /*
   * Since data width is maximum 32-bit, check if the the data width of
   * requested channel is more than 16 bits
   */
  /* QAC Warning: START Msg(2:2814)-20 */
  if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
  /* END Msg(2:2814)-20 */
  {
    /*
     * Data width is maximum 16-bit. Hence, load LSB portion of the
     * local variable with the 16-bit data to be transmitted
     */
    LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                           LunDataAccess2.usRegData5[SPI_ZERO];
  }
  else
  {
    /* Check if the configured data direction is LSB first */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Load Tx data portion of the local variable with LSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
    }
    else
    {
      /* Load Tx data portion of the local variable with MSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                             LunDataAccess2.usRegData5[SPI_ONE];
    }

    /* Set the EDL bit in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_EDL;
    LunDataAccess3.ulRegData = LunDataAccess1.ulRegData;

    /*
     * Check the configured data direction again to load other
     * part of data
     */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Load Tx data portion of the local variable with MSB */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ONE];
    }
    else
    {
      /* Load Tx data portion of the local variable with LSB */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                          LunDataAccess2.usRegData5[SPI_ZERO];
    }
    /* MISRA Violation: START Msg(4:2984)-10 */
    /* Reset the EDL bit in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData3 =
                  (LunDataAccess1.Tst_ByteAccess.ucRegData3 & SPI_RESET_EDL);
    /* END Msg(4:2984)-10 */
  } /* End of !if ( SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */
  #endif

  /* QAC Warning: START Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the user base address of the HW Unit */
  LpCsigUserBaseAddr = (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/
  /* END Msg (2:2814)-20*/

  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /*
   * Since data width is maximum 32-bit, check if the the data width of
   * requested channel is more than 16 bits
   */
  if (SPI_TRUE == LpPBChannelConfig->blEDLEnabled)
  {
        /* Clear pending Tx interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    /* Clear pending Error interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Load the value of the local union variable to TX0W register */
    SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ulCSIGTX0W,
                                                       LunDataAccess3.ulRegData)

    /* END Msg(2:2814)-20 */

    LenReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo, LenReturnValue, SPI_TX);

    #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
    LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue,
                                                   LddSequenceID, LddJobID);
    #else
    LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue);
    #endif
    if (E_OK == LenReturnValue)
    {
       /* Wait till Rx0 register is full */
      LenReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo, LenReturnValue, SPI_RX);
      /* Check for Error interrupt flag */
      #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
      LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                                      LenReturnValue, LddSequenceID, LddJobID);
      #else
      LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue);
      #endif

      /* Clear pending Rx interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* Clear pending Rx interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                              (SPI_CLR_INT_REQ));

      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* SYNCP execution */
      EXECUTE_SYNCP();
      #endif

       /* Save the received data to a variable */
      Spi_GusSynDataAccess = LpCsigUserBaseAddr->usCSIGRX0;
    }
    else
    {
           /* No action required */
    }
    if (E_OK == LenReturnValue)
    {
      /* Clear pending Tx interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* Clear pending Error interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* Register dummy read-write  */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* SYNCP execution */
      EXECUTE_SYNCP();
      #endif
      /* Load the value of the local union variable to TX0W register */
      SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ulCSIGTX0W,
                                                 LunDataAccess1.ulRegData)

    }
    else
    {
      /* No action required */
    }

  }
  else
  {
    /* Clear pending Tx interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                             (SPI_CLR_INT_REQ));
    /* Clear pending Error interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                             (SPI_CLR_INT_REQ));
    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                             (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    /* Load the value of the local union variable to TX0W register */
    SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ulCSIGTX0W,
                                                 LunDataAccess2.ulRegData)

  }
  #else
  /* Clear pending Tx interrupt */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Clear pending Error interrupt */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                          (SPI_CLR_INT_REQ));
   /* Register dummy read-write  */
   #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
   RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
   /* SYNCP execution */
   EXECUTE_SYNCP();
   #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Load the value of the local union variable to TX0W register */
  SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ulCSIGTX0W,
                                                 LunDataAccess2.ulRegData)

  /* END Msg(2:2814)-20 */
  #endif
  /* Wait for Tx0 register to get empty */
   LenReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo, LenReturnValue, SPI_TX);
  /* Check for Error interrupt flag */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue,
                                                   LddSequenceID, LddJobID);
  #else
  LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,LenReturnValue);
  #endif
  return LenReturnValue;
 }
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_CsihTxDataAndErrorProcessing
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data processing for CSIH H/W
**                      in Synchronous transmission.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                  LpJobConfig,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                      Spi_DataAccess LunDataAccess2
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GusSynDataAccess
**
** Function Invoked   : Spi_CheckRegEmpty, Spi_CheckErrorInt
**
** Registers Used     : CSIHnRX0H, CSIHnTX0W, EICn
*******************************************************************************/
/* Implements SPI_ESDD_UD_062 */
#if ((SPI_CSIH_CONFIGURED == STD_ON)&&((SPI_LEVEL_DELIVERED == SPI_ZERO) || \
     ((SPI_LEVEL_DELIVERED == SPI_TWO) &&(SPI_DIRECT_ACCESS_MODE == STD_ON))))
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* MISRA Violation: START Msg(4:0759)-1 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsihTxDataAndErrorProcessing
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2, Spi_SequenceType LddSequenceID,
                                                           Spi_JobType LddJobID)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
#else
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CsihTxDataAndErrorProcessing
(P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
Spi_DataAccess LunDataAccess2)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */

#endif
/* MISRA Violation: START Msg(4:0759)-1 */
{
  /* Defining a local pointer variable to hold the user address of CSIG */
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;

  Std_ReturnType LenReturnValue;

  Spi_HWUnitType LddHWUnit;
  #if (SPI_8BIT_DATA_WIDTH == STD_OFF && SPI_16BIT_DATA_WIDTH == STD_OFF)
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  #endif
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess3;
  /* END Msg(4:0759)-1 */
  #endif
  LenReturnValue = E_OK;
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;
  /* END Msg(2:2814)-20 */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  #if (SPI_8BIT_DATA_WIDTH == STD_OFF && SPI_16BIT_DATA_WIDTH == STD_OFF)
  /*
   * Since data width is maximum 32-bit, check if the the data width of
   * requested channel is more than 16 bits
  */
  /* QAC Warning: START Msg(2:2814)-20 */
  if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
  /* END Msg(2:2814)-20 */
  {
    /*
     * Data width is maximum 16-bit. Hence, load LSB portion of the
     * local variable with the 16-bit data to be transmitted
     */
    LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
  }
  else
  {
    /* Check if the configured data direction is LSB first */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Load Tx data portion of the local variable with LSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
    }
    else
    {
      /* Load Tx data portion of the local variable with MSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                             LunDataAccess2.usRegData5[SPI_ONE];
    }
    /* Set the EDL bit in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_EDL;
    LunDataAccess3.ulRegData = LunDataAccess1.ulRegData;
    /*
     * Check the configured data direction again to load other
     * part of data
     */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Load Tx data portion of the local variable with MSB */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ONE];
    }
    else
    {
      /* Load Tx data portion of the local variable with LSB */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
    }
    /* MISRA Violation: START Msg(4:2984)-10 */
    /* Reset the EDL bit in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData3 =
                  (LunDataAccess1.Tst_ByteAccess.ucRegData3 & SPI_RESET_EDL);
    /* END Msg(4:2984)-10 */
  } /* End of !if ( SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */
  #endif
  /* Set chip select in the local union variable */
  LunDataAccess2.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the user base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(4:0316)-9 */
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /*
   * Since data width is maximum 32-bit, check if the the data width of
   * requested channel is more than 16 bits
  */
  if (SPI_TRUE == LpPBChannelConfig->blEDLEnabled)
  {
    /* Set chip select in the local union variable */
    LunDataAccess3.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
    /* Set chip select in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
    /* Clear pending Tx interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    /* Clear pending Error interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                             (SPI_CLR_INT_REQ));
    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    /* QAC Warning: START Msg(2:2814)-20 */
    SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                          LunDataAccess3.ulRegData)

    /* END Msg(2:2814)-20 */
    /* Wait for Tx0 register to get empty */
    LenReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo, LenReturnValue, SPI_TX);
    /* Check for Error interrupt flag */
    #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
    LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue,
                                                     LddSequenceID, LddJobID);
    #else
    LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue);
    #endif
    if (E_OK == LenReturnValue)
    {
      /* Wait till Rx0 register is full */
      LenReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo, LenReturnValue, SPI_RX);
      /* Check for Error interrupt flag */
      #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
      LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue,
                                                       LddSequenceID, LddJobID);
      #else
      LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue);
      #endif
      /* Clear pending Rx interrupt */
      RH850_SV_MODE_ICR_AND(16,(LpHWUnitInfo->pRxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* Clear pending Error interrupt */
      RH850_SV_MODE_ICR_AND(16,(LpHWUnitInfo->pErrorIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* SYNCP execution */
      EXECUTE_SYNCP();
      #endif
      /* Save the received data to a variable */
      Spi_GusSynDataAccess = LpCsihUserBaseAddr->usCSIHRX0H;
    }
    else
    {
      /* No action required */
    }
    if (E_OK == LenReturnValue)
    {
      /* Clear pending Tx interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* Clear pending Error interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* Register dummy read-write  */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* SYNCP execution */
      EXECUTE_SYNCP();
      #endif
      /* Load the value of the local union variable to TX0W register */
      SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                          LunDataAccess1.ulRegData)

      /* Decrement the number of buffers to be transmitted  */
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
     /* Clear pending Tx interrupt */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Clear pending Error interrupt */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Register dummy read-write  */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                          (SPI_CLR_INT_REQ));
  /* SYNCP execution */
  EXECUTE_SYNCP();
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Load the value of the local union variable to TX0W register */

  SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W, LunDataAccess2.ulRegData)

  /* END Msg(2:2814)-20 */
  }

  #else
  {
     /* Clear pending Tx interrupt */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                          (SPI_CLR_INT_REQ));
  /* Clear pending Error interrupt */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                          (SPI_CLR_INT_REQ));
  /* Register dummy read-write  */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* SYNCP execution */
  EXECUTE_SYNCP();
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Load the value of the local union variable to TX0W register */
  SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W, LunDataAccess2.ulRegData)

  /* END Msg(2:2814)-20 */
  }
  /* Decrement the number of buffers to be transmitted  */
  #endif /* End of #if (SPI_EXTENDED_DATA_LENGTH == STD_ON) */
  /* Wait for Tx0 register to get empty */
  LenReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo, LenReturnValue, SPI_TX);
  /* Check for Error interrupt flag */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue,
                                                   LddSequenceID, LddJobID);
  #else
  LenReturnValue = Spi_CheckErrorInt(LpHWUnitInfo, LenReturnValue);
  #endif

  return LenReturnValue;

 }
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_GetCsigRxData
**
** Service ID         : Not Applicable
**
** Description        : This function returns the receive data for CSIG H/W unit
**                      in Synchronous transmission.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpHWUnitInfo,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                      Spi_SequenceType LddSequenceID, Spi_JobType LddJobID
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Spi_DataType
**
** Preconditions      : None
**
** Global Variable    : Spi_GusSynDataAccess
**
** Function Invoked   : Spi_CheckRegEmpty, Spi_CheckErrorInt
**
** Registers Used     : CSIGnRX0, EICn
*******************************************************************************/
/* Implements SPI_ESDD_UD_063 */
#if (SPI_CSIG_CONFIGURED == STD_ON)
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsigRxData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag,
Spi_SequenceType LddSequenceID, Spi_JobType LddJobID)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
#else
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsigRxData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */

#endif
 {
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA)LpCsigUserBaseAddr;

  /* Defining a local pointer variable to hold the user address of CSIG */
  #if (SPI_8BIT_DATA_WIDTH == STD_OFF && SPI_16BIT_DATA_WIDTH == STD_OFF)
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  #endif

  /* QAC Warning: START Msg(2:2814)-20 */
  LpDataAndDemFlag->ddReturnValue = E_OK;
  /* END Msg(2:2814)-20 */
  LpDataAndDemFlag->ddData = SPI_ZERO;
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* QAC Warning: START Msg(2:2814)-20 */
  LpCsigUserBaseAddr = (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(2:2814)-20 */
  /* END Msg(4:0316)-9 */
  /* Wait till Rx0 register is full */
  LpDataAndDemFlag->ddReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo,
                                      LpDataAndDemFlag->ddReturnValue, SPI_RX);
  /* Check for Error interrupt flag */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                     LpDataAndDemFlag->ddReturnValue, LddSequenceID, LddJobID);
  #else
  LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                                              LpDataAndDemFlag->ddReturnValue);
  #endif
  if (E_OK == LpDataAndDemFlag->ddReturnValue)
  {
    /* Clear the pending Rx interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
    /* Clear the pending Error interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                         (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    /* QAC Warning: START Msg(2:2814)-20 */
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, Receive the data from the
     * Rx register to local union variable
    */
    LpDataAndDemFlag->ddData = (uint8)LpCsigUserBaseAddr->usCSIGRX0;
    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    LpDataAndDemFlag->ddData = LpCsigUserBaseAddr->usCSIGRX0;
    /* END Msg(2:2814)-20 */

    #else
    /*
     * Data width is maximum 32-bit, Check if the the data width of
     * requested channel is more than 16 bits
    */
    /* QAC Warning: START Msg(2:2814)-20 */
    if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
    {
      /*
      * Data width is maximum 8-bit. Hence, Receive the data from the
      * Rx register to local union variable
      */
      LpDataAndDemFlag->ddData = LpCsigUserBaseAddr->usCSIGRX0;
    /* END Msg(2:2814)-20 */
    }
    else
    {
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /* Store the received data */
        LunDataAccess1.usRegData5[SPI_ONE] =
                                      (uint16)LpCsigUserBaseAddr->usCSIGRX0;
        LunDataAccess1.usRegData5[SPI_ZERO] = Spi_GusSynDataAccess;
      }
      else
      {
        if (SPI_ZERO != LpPBChannelConfig->ucDLSSetting)
        {
          LunDataAccess1.usRegData5[SPI_ZERO] =
          (uint16)LpCsigUserBaseAddr->usCSIGRX0;
          LunDataAccess1.usRegData5[SPI_ZERO] =
          LunDataAccess1.usRegData5[SPI_ZERO] <<
                             (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting));
          LunDataAccess1.usRegData5[SPI_ONE] = Spi_GusSynDataAccess;
          LunDataAccess1.ulRegData = LunDataAccess1.ulRegData >>
                             (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting));
        }
        else
        {
          LunDataAccess1.usRegData5[SPI_ZERO] =
                                       (uint16)LpCsigUserBaseAddr->usCSIGRX0;
          LunDataAccess1.usRegData5[SPI_ONE] = Spi_GusSynDataAccess;
        }
      }/* End of if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */

      /* Return the received data */
      LpDataAndDemFlag->ddData = LunDataAccess1.ulRegData;
    }
    #endif
    /* Check for Error interrupt flag */
    #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
    LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                      LpDataAndDemFlag->ddReturnValue, LddSequenceID, LddJobID);
    #else
    LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                                               LpDataAndDemFlag->ddReturnValue);
    #endif
  }
  else
  {
    /*Do nothing*/
  }
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name      : Spi_GetCsihRxData
**
** Service ID         : Not Applicable
**
** Description        : This function returns the receive data for CSIH H/W unit
**                      in Synchronous transmission.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpHWUnitInfo,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                      Spi_SequenceType LddSequenceID, Spi_JobType LddJobID
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Spi_DataType
**
** Preconditions      : Spi_CheckRegEmpty, Spi_CheckErrorInt
**
** Global Variable    : Spi_GusSynDataAccess
**
** Function Invoked   : None
**
** Registers Used     : CSIHnRX0H, EICn
*******************************************************************************/
/* Implements SPI_ESDD_UD_064 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsihRxData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag,
Spi_SequenceType LddSequenceID, Spi_JobType LddJobID)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
#else
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE)Spi_GetCsihRxData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_DataAndErrorFlag, AUTOMATIC, SPI_CONFIG_DATA) LpDataAndDemFlag)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */

#endif
{
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA)LpCsihUserBaseAddr;
  /* Defining a local pointer variable to hold the user address of CSIG */
  #if (SPI_8BIT_DATA_WIDTH == STD_OFF && SPI_16BIT_DATA_WIDTH == STD_OFF)
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  #endif

  /* QAC Warning: START Msg(2:2814)-20 */
  LpDataAndDemFlag->ddReturnValue = E_OK;
  LpDataAndDemFlag->ddData = SPI_ZERO;
  /* MISRA Violation: START Msg(4:0316)-9 */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(4:0316)-9 */
  /* END Msg(2:2814)-20 */
  /* Wait till Rx register is full */
  LpDataAndDemFlag->ddReturnValue = Spi_CheckRegEmpty(LpHWUnitInfo,
                                      LpDataAndDemFlag->ddReturnValue, SPI_RX);
   /* Check for Error interrupt flag */
  #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
  LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                     LpDataAndDemFlag->ddReturnValue, LddSequenceID, LddJobID);
  #else
  LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                                              LpDataAndDemFlag->ddReturnValue);
  #endif
  if (E_OK == LpDataAndDemFlag->ddReturnValue)
  {
    /* Clear the pending Rx interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                                             (SPI_CLR_INT_REQ));
    /* Clear the pending Error interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                                             (SPI_CLR_INT_REQ));
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                         (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif
    /* QAC Warning: START Msg(2:2814)-20 */
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, Receive the data from the
     * Rx register to local union variable
     */
    LpDataAndDemFlag->ddData = (uint8)LpCsihUserBaseAddr->usCSIHRX0H;
    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    LpDataAndDemFlag->ddData = LpCsihUserBaseAddr->usCSIHRX0H;
    /* END Msg(2:2814)-20 */
    #else
    /*
     * Data width is maximum 32-bit, Check if the the data width of
     * requested channel is more than 16 bits
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
    {
      /*
       * Data width is maximum 8-bit. Hence, Receive the data from the
       * Rx register to local union variable
       */
       LpDataAndDemFlag->ddData = LpCsihUserBaseAddr->usCSIHRX0H;
    /* END Msg(2:2814)-20 */
    }
    else
    {
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /* Store the received data */
        LunDataAccess1.usRegData5[SPI_ONE] =
                                       (uint16)LpCsihUserBaseAddr->usCSIHRX0H;
        LunDataAccess1.usRegData5[SPI_ZERO] = Spi_GusSynDataAccess;
      }
      else
      {
        LunDataAccess1.usRegData5[SPI_ZERO] =
                                         (uint16)LpCsihUserBaseAddr->usCSIHRX0H;
        LunDataAccess1.usRegData5[SPI_ZERO] =
        LunDataAccess1.usRegData5[SPI_ZERO] <<
                    (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting));
        LunDataAccess1.usRegData5[SPI_ONE] = Spi_GusSynDataAccess;
        LunDataAccess1.ulRegData = LunDataAccess1.ulRegData >>
                    (SPI_SIXTEEN - (LpPBChannelConfig->ucDLSSetting));
      }
       /* Return the received data */
       LpDataAndDemFlag->ddData = LunDataAccess1.ulRegData;
    } /* End of if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */
    #endif
    /* Check for Error interrupt flag */
    #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
    LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                     LpDataAndDemFlag->ddReturnValue, LddSequenceID, LddJobID);
    #else
    LpDataAndDemFlag->ddReturnValue = Spi_CheckErrorInt(LpHWUnitInfo,
                                              LpDataAndDemFlag->ddReturnValue);
    #endif
  }
  else
  {
    /* No action required */
  }
 }
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name      : Spi_CheckRegEmpty
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data processing of channel
**                      in Synchronous transmission.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : boolean
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : EICn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_066 */
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CheckRegEmpty
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo ,
 Std_ReturnType LenReturnValue, uint8 Lucflag)
/* END Msg(2:3227)-16 */
{
  uint16 LusIndex;
  LusIndex = SPI_ZERO;
  /* wait for Tx or Rx Reg empty/full */
  if (SPI_TX == Lucflag)
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:3892)- 21 */
    while ((SPI_INT_FLAG_MASK != (uint16)(*(LpHWUnitInfo->pTxIntCntlAddress)
                       & SPI_INT_FLAG_MASK)) && (E_OK == LenReturnValue))
    /* END Msg(2:3892)- 21 */
    /* END Msg(2:2814)-20 */
   {

    LusIndex++;
    /* Implements SPI_ESDD_UD_141 */
    /* Raise production error */
    /* Report error to DEM    */
    if (SPI_LOOP_TIMEOUT <= LusIndex)
    {
      Dem_ReportErrorStatus(SPI_E_DATA_TX_TIMEOUT_FAILURE,
                                                  DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  }
  else
  {
    /* QAC Warning: START Msg(2:3892)- 21 */
    while ((SPI_INT_FLAG_MASK != (uint16)(*(LpHWUnitInfo->pRxIntCntlAddress)
                       & SPI_INT_FLAG_MASK)) && (E_OK == LenReturnValue))
    /* END Msg(2:3892)- 21 */
  {

    LusIndex++;
    /* Implements SPI_ESDD_UD_140 */
    /* Raise production error */
    /* Report error to DEM    */
    if (SPI_LOOP_TIMEOUT <= LusIndex)
    {
      Dem_ReportErrorStatus(SPI_E_DATA_TX_TIMEOUT_FAILURE,
                                                  DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }

  }
  return LenReturnValue;
 }
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_CheckErrorInt
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform the check for any
**                      reported hardware errors
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : boolean
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus, Spi_ReportErrorInSyncTx
**
** Registers Used     : EICn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_058 */
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
#if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
/* Implements SPI_ESDD_UD_183 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CheckErrorInt
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Std_ReturnType LenReturnValue, Spi_SequenceType LddSequenceID,
                                                        Spi_JobType LddJobID)
/* END Msg(2:3227)-16 */
#else
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CheckErrorInt
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Std_ReturnType LenReturnValue)
/* END Msg(2:3227)-16 */
#endif
{
  /* check for any hardware errors */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  if ((SPI_INT_FLAG_MASK == (uint16)(*(LpHWUnitInfo->pErrorIntCntlAddress) &
                      SPI_INT_FLAG_MASK)) && (E_OK == LenReturnValue))
  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  {
    /* Raise production error */
    /* Report error to DEM    */
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR,
                                          DEM_EVENT_STATUS_FAILED);
    LenReturnValue = E_NOT_OK;
    #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
    Spi_ReportErrorInSyncTx(LpHWUnitInfo, LddSequenceID, LddJobID);
    #endif
  }
  else
  {
    /* No action required */
  }

    return LenReturnValue;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_GetCurrentRxData
**
** Service ID         : Not Applicable
**
** Description        : This function is to return the pointer to current Rxdata
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : uint8 LucChannelBufferType
**                      Spi_NumberOfDataType LddBufferIndex
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Spi_DataType
**
** Preconditions      : None
**
** Global Variable    : Spi_GaaChannelEBData, Spi_GpConfigPtr
**
** Function Invoked   : None
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_065 */
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))
#if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) || (SPI_EB_CONFIGURED == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"

#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA), SPI_PRIVATE_CODE)
Spi_GetCurrentRxData(uint8 LucChannelBufferType,
                                            Spi_NumberOfDataType LddBufferIndex)
#else
FUNC(P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA), SPI_PRIVATE_CODE)
Spi_GetCurrentRxData(Spi_NumberOfDataType LddBufferIndex)
#endif
/* END Msg(2:3227)-16 */
{
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData;
  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  /* Check if the buffer type is internal buffer */
  if (SPI_ZERO == LucChannelBufferType)
  #endif
  {
    #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Update the RAM variable for Rx pointer with channel IB index */
    LpCurrentRxData = Spi_GpConfigPtr->pChannelIBRead;
    /* END Msg (2:2814)-20 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpCurrentRxData = LpCurrentRxData + LddBufferIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */

    #endif
  }
  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  else
  #endif
  {
    #if (SPI_EB_CONFIGURED == STD_ON)
    /* Update the RAM variable for Rx pointer with channel EB index */
    LpCurrentRxData = Spi_GaaChannelEBData[LddBufferIndex].pDestPtr;
    #endif
  }
  /* MISRA Violation: START Msg(4:2962)-11 */
  return LpCurrentRxData;
  /* END Msg(4:2962)-11 */
 }
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name      : Spi_CsigStaticInit
**
** Service ID         : Not Applicable
**
** Description        : This service performs static initialization for CSIG
**                                                               hardware unit.
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpHWUnitInfo,
**                      P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST)
**                                                                  LpJobConfig,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                      P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                           LpMainUserBaseAddr,
**                      P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                              LpMainOsBaseAddr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function invoked   : None
**
** Registers Used     : CSIGCFG0, CSIGnSTCR0, CSIGnCTL1,
**                      CSIGnSTR0, CSIGnCTL2
*******************************************************************************/
/* Implements SPI_ESDD_UD_045 */
#if (SPI_CSIG_CONFIGURED == STD_ON)

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                            (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE) Spi_CsigStaticInit
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr,
uint8 LucApId )
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
{
  uint32 LulCxCTL1;
  P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr;
  P2VAR(Spi_CsigOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigOsBaseAddr;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  /* Clear the status register */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */

  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0, SPI_CSIG_CLR_STS_FLAGS)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
  LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
                 (uint32)(SPI_CSIG_CLR_STS_FLAGS),LucApId)

  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the OS base address of the HW Unit */
  LpCsigOsBaseAddr = (Spi_CsigOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;

  /* END Msg(4:0316)-9 */
  /* END Msg(2:2814)-20 */
  /* Get the main OS base address */
  LpMainOsBaseAddr = LpHWUnitInfo->pHwMainOsBaseAddress;
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Load the control register 1 with Ctl1 reg value of current Job */
  LulCxCTL1 = (LpJobConfig->ulMainCtl1Value & SPI_CSIG_CTLREG_MASK);

  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
  LulCxCTL1, SPI_CSIG_CTLREG_MASK, LucApId)

  /* END Msg(2:2814)-20 */

  /* Set the SLIT bit */
  LulCxCTL1 = (LpMainOsBaseAddr->ulMainCTL1 | SPI_SET_SLIT);
  /* MISRA Violation: START Msg(4:0402)-13 */
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
                                     LulCxCTL1, SPI_CTLREG_32_BIT_MASK, LucApId)

  /* END Msg(4:0402)-13 */
  /* Update the Baud rate and Pre-scalar values from control register2
   */
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, LpJobConfig->usCtl2Value)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
          LpJobConfig->usCtl2Value, SPI_CTLREG_16_BIT_MASK, LucApId)

  /*
   * To load configuration register, read the existing communication
   * type values to a local union variable
   */
  /* MISRA Violation: START Msg(4:0306)-8 */
  LunDataAccess1.ulRegData = LpJobConfig->ulConfigRegValue;
  /* END Msg(4:0306)-8 */
  /* Load the local variable with data width */
  /* QAC Warning: START Msg(2:2814)-20 */
  LunDataAccess1.ucRegData4[SPI_THREE] =
                            LunDataAccess1.ucRegData4[SPI_THREE] & SPI_DLS_MASK;

  LunDataAccess1.ucRegData4[SPI_THREE] =
        LunDataAccess1.ucRegData4[SPI_THREE] | LpPBChannelConfig->ucDLSSetting;
  /* END Msg(2:2814)-20 */
  /* Load the local variable with configured direction */
  if (SPI_TRUE == LpPBChannelConfig->blDirection)
  {
    /* Direction is LSB, set DIR bit */
    LunDataAccess1.ucRegData4[SPI_TWO] =
                      LunDataAccess1.ucRegData4[SPI_TWO] | SPI_SET_DIR_LSB;
  }
  else
  {
    /* Direction is MSB, reset DIR bit */
    LunDataAccess1.ucRegData4[SPI_TWO] =
                      LunDataAccess1.ucRegData4[SPI_TWO] & SPI_RESET_DIR_LSB;
  }
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Load back the value to configuration register */

  SPI_CSIGH_REG_WRITE(LpCsigOsBaseAddr->ulCSIGCFG0,
                                            LunDataAccess1.ulRegData)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigOsBaseAddr->ulCSIGCFG0,
  LunDataAccess1.ulRegData, SPI_CSIGCFG0_MASK, LucApId)

  /* END Msg(2:2814)-20 */
  }
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if ((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON) */
#endif

/*******************************************************************************
** Function Name      : Spi_CsihStaticInit
**
** Service ID         : Not Applicable
**
** Description        : This service performs static initialization for CSIH
**                      hardware unit.
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** InOut Parameters   : None
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpHWUnitInfo,
**                      P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST)
**                                                                  LpJobConfig,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                      P2CONST(Spi_SequenceConfigType, AUTOMATIC,
**                                                SPI_CONFIG_CONST) LpSeqConfig,
**                                                Spi_HWUnitType LddHWUnitNumber
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstJob, Spi_GpFirstChannel
**                      Spi_GaaHighPriorityCommActive, Spi_GstCurrentCommData
**
** Function invoked   : None
**
** Registers Used     : CSIHnCTL1, CSIHnSTCR0, CSIHnCTL2, CSIHnMCTL0, CSIHnBRSy,
**                      CSIHnCFGx, CSIHnSTR0
*******************************************************************************/
/* Implements SPI_ESDD_UD_046 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if ((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON) ||\
    ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                      (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
    (SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) || \
                                      (SPI_TX_ONLY_MODE == STD_ON))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements AR_PN0063_FR_0081, AR_PN0063_FR_0080 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE)Spi_CsihStaticInit
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList,
Spi_JobType LddNoOfJobs, Spi_HWUnitType LddHWUnitNumber, uint8 LucApId )
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfigCSConfig;
  /* Declare a local pointer to point to the Configured chip select of job */
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpChipSelect;
  #if (SPI_DIRECT_ACCESS_MODE == STD_ON && \
                        (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF))
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentTxChannelList;
  P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData;
  #endif
  #if (SPI_DIRECT_ACCESS_MODE == STD_ON)
  uint32 LulCxCTL1;
  #endif
  uint16 LusCxCtl2;
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                              LpPBChannelConfig;

  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;

  Spi_JobType LddJobIndexCSConfig;
  Spi_JobType LddJobIndex;
  uint32 LulBRSRegIndex;
  /* MISRA Violation: START Msg(4:0759)-4 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-4 */
  uint8 LucVar;
  /* QAC Warning: START Msg(2:3204)-26 */
  uint8 LucHWMemoryMode;
  /* END Msg(2:3204)-26 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the index of the job and sequence */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)-20 */

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer of the first job linked to this sequence */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0488)-4 */
  #if (SPI_LEVEL_DELIVERED != SPI_ZERO)
  /* QAC Warning: START Msg(2:2814)-20 */
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
  #endif
  {
    /* Get the configured memory mode for this HW Unit */
    LucHWMemoryMode = Spi_GpConfigPtr->aaHWMemoryMode[LddHWUnitNumber];
  }
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  else
  {
    /* Get the configured memory mode for this HW Unit */
    LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED ;
  }
  #endif
  /* END Msg(2:2814)-20 */
  #else
  LucHWMemoryMode = SPI_DIRECT_ACCESS_MODE_CONFIGURED;
  #endif /*
          * ((SPI_CSIH_CONFIGURED == STD_ON) &&
          *                               (SPI_LEVEL_DELIVERED != SPI_ZERO))
          */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the main user base address */
  LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
  /* END Msg(2:2814)-20 */
  /* Get the main OS base address */
  LpMainOsBaseAddr = LpHWUnitInfo->pHwMainOsBaseAddress;
  /* Clear the status register */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */

  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0, SPI_CSIH_CLR_STS_FLAGS)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ulMainSTR0,
                     (uint32)SPI_ZERO, (uint32)(SPI_CSIH_CLR_STS_FLAGS),LucApId)

  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the OS base address of the HW Unit */
  LpCsihOsBaseAddr = (Spi_CsihOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
  /* END Msg(4:0316)-9 */
  /* Load the local union variable with Ctl1 reg value of current Job */
  /* QAC Warning: START Msg(2:2814)-20 */
  LunDataAccess1.ulRegData = LpJobConfig->ulMainCtl1Value;
  /* END Msg(2:2814)-20 */
  /* Write the value with configured polarity of all chip selects */
  /* QAC Warning: START Msg(2:2814)-20 */
  LunDataAccess1.ucRegData4[SPI_ONE] =
                             Spi_GpConfigPtr->aaChipSelect[LddHWUnitNumber];
  /* END Msg(2:2814)-20 */
  /* Load the control register 1 with the value of local union variable */
  /* QAC Warning: START Msg(2:2814)-20 */

  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LunDataAccess1.ulRegData)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
                      LunDataAccess1.ulRegData, SPI_CTLREG_32_BIT_MASK, LucApId)

  /* END Msg(2:2814)-20 */
  #if (SPI_DIRECT_ACCESS_MODE == STD_ON)
  /* MISRA Violation: START Msg(4:2991)-18 */
  /* MISRA Violation: START Msg(4:2995)-15 */
  if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode)
  /* END Msg(4:2991)-18 */
  /* END Msg(4:2995)-15 */
  {
    #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
    #endif
    {
      LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
    }
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    else
    {
      LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ONE + LddHWUnitNumber]);
    }
    #endif

    LpCurrentTxChannelList = LpCurrentCommData->pCurrentTxChannelList;

    /* Get the pointer to the post-build structure of the channel */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentTxChannelList);
    /* END Msg(2:2814)-20 */
    #else

    LpPBChannelConfig = Spi_GpFirstChannel + (*(LpJobConfig->pChannelList));
    #endif
    /* MISRA Violation: START Msg(4:0402)-13 */
    /* Set the SLIT bit */
    LulCxCTL1 = (LpMainOsBaseAddr->ulMainCTL1 | SPI_SET_SLIT);
    SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1,
                                                SPI_CTLREG_32_BIT_MASK, LucApId)

    /* END Msg(4:0402)-13 */
    /* END Msg(2:2824)-17 */
    /* END Msg(4:0488)-4 */
  }
  else
  {
    /* No action required */
  }
  #endif /* (SPI_DIRECT_ACCESS_MODE == STD_ON) */
  /* Update the Pre-scalar value from control register2 */
  LusCxCtl2 = ((LpJobConfig->usCtl2Value) & SPI_CSIH_PRE_MASK);
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, LusCxCtl2)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
                                     LusCxCtl2, SPI_CTLREG_16_BIT_MASK, LucApId)
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Initialize CSIH memory register */

    SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->usCSIHMCTL0,
                                                     LpJobConfig->usMCtl0Value)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihOsBaseAddr->usCSIHMCTL0,
    LpJobConfig->usMCtl0Value, SPI_CSIHMCTL0_MASK, LucApId)

    /* END Msg(2:2814)-20 */

  do
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    LddJobIndexCSConfig = LpJobList->ddJobIndex;
    /* END Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpJobConfigCSConfig = Spi_GpFirstJob + LddJobIndexCSConfig;
    /* END Msg(2:2824)-17 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Get the value for multiple chip selects configured */
    LpChipSelect = (Spi_GpConfigPtr->pCSArray) +
                                          (LpJobConfigCSConfig->ucCSArrayIndex);
    /* END Msg(2:2814)-20 */
    /* END Msg(4:0488)-4 */
    #if ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) \
                                       || (SPI_TX_ONLY_MODE == STD_ON))
    if (SPI_DIRECT_ACCESS_MODE_CONFIGURED != LucHWMemoryMode)
    {
      /* QAC Warning: START Msg(2:2824)-17 */
      /* MISRA Violation: START Msg(4:0488)-4 */
      /* Get the pointer to the post-build structure of the channel */
      LpPBChannelConfig = Spi_GpFirstChannel +
                                  (*LpJobConfigCSConfig->pChannelList);
      /* END Msg(4:0488)-4 */
      /* END Msg(2:2824)-17 */
    }
    else
    {
      /* No action required */
    }
    #endif /*
            * ((SPI_FIFO_MODE == STD_ON) || \
            *         (SPI_DUAL_BUFFER_MODE == STD_ON) || \
            *                               (SPI_TX_ONLY_MODE == STD_ON))
            */

    /*
     * To load configuration register, read the existing communication
     * type values  to a local union variable
     */
    LunDataAccess1.ulRegData = LpJobConfigCSConfig->ulConfigRegValue;
    /* Load the local variable with data width */
    LunDataAccess1.ucRegData4[SPI_THREE] =
                            LunDataAccess1.ucRegData4[SPI_THREE] & SPI_DLS_MASK;
    /* MISRA Violation: START Msg(4:2962)-11 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess1.ucRegData4[SPI_THREE] =
         LunDataAccess1.ucRegData4[SPI_THREE] | LpPBChannelConfig->ucDLSSetting;
    /* END Msg(2:2814)-20 */
    /* END Msg(4:2962)-11 */
    /* Load the local variable with configured direction */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Direction is LSB, set DIR bit */
      LunDataAccess1.ucRegData4[SPI_TWO] = LunDataAccess1.ucRegData4[SPI_TWO] |
                                           SPI_SET_DIR_LSB;
    }
    else
    {
      /* Direction is MSB, reset DIR bit */
      LunDataAccess1.ucRegData4[SPI_TWO] =
                     LunDataAccess1.ucRegData4[SPI_TWO] & SPI_RESET_DIR_LSB;
    }

    /* Get the index of the baud rate register */
    LulBRSRegIndex = (((LpJobConfigCSConfig->ulConfigRegValue) &
                                       SPI_CSIH_BRS_SELECT_MASK) >> SPI_THIRTY);
    /* Update the Baud rate value from control register2 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LusCxCtl2 = ((LpJobConfigCSConfig->usCtl2Value) & SPI_CSIH_BRS_MASK);
    SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->stCSIHBRS[LulBRSRegIndex].usCSIHBRS,
                                                                      LusCxCtl2)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpCsihOsBaseAddr->stCSIHBRS[LulBRSRegIndex].usCSIHBRS, LusCxCtl2,
                                                      SPI_CSIHBRS_MASK, LucApId)
    /* END Msg(2:2814)-20 */

    /* Load the number of chip selects */
    LucVar = LpJobConfigCSConfig->ucNoOfCS;
    do
    {
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Initialize CSIH configuration register */
      SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
                                                   LunDataAccess1.ulRegData)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
      LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],LunDataAccess1.ulRegData,
                                         SPI_CSIHCFG_MASK, LucApId)

      /* END Msg(2:2814)-20 */
      /* Decrement number of chip selects */
      LucVar--;
      /* MISRA Violation: START Msg(4:0489)-3 */
      LpChipSelect++;
      /* END Msg(4:0489)-3 */
    }while (SPI_ZERO < LucVar);

    /* Implements SPI_ESDD_UD_207 */
    /* MISRA Violation: START Msg(4:0489)-3 */
    if (SPI_TRUE != LpJobList->blIsLastJob)
    {
      LpJobList--;
    }
    else
    {
      /* No action required */
    }
    /* END Msg(4:0489)-3 */
    LddNoOfJobs--;
  /* MISRA Violation: START Msg(4:2877)-12 */
  }while (SPI_ZERO < LddNoOfJobs);
  /* END Msg(4:2877)-12 */
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* #if ((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON) */
#endif

/*******************************************************************************
** Function Name      : Spi_CsigLoopBackSelfTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data transmission self test
**                      using loop back mode in CSIG hardware unit.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                LpHWUnitInfo,
**                      P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                           LpMainUserBaseAddr,
**                      P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                              LpMainOsBaseAddr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : uint8
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : CSIGnCTL0, CSIGnCTL1, CSIGnCTL2, CSIGCFG0, CSIGnSTCR0,
**                      CSIGnSTR0, CSIGnRX0, CSIGnTX0H, EICn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_048 */
#if (SPI_LOOPBACK_SELFTEST == SPI_ONE ||SPI_LOOPBACK_SELFTEST == SPI_TWO )
#if (SPI_CSIG_CONFIGURED == STD_ON)
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(uint8, SPI_PRIVATE_CODE)Spi_CsigLoopBackSelfTest
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainUserBaseAddr,
P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainOsBaseAddr)
/* END Msg(2:3227)-16 */
{
  P2VAR(Spi_CsigOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigOsBaseAddr;
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  Std_ReturnType LenReturnValue;
  uint16 LusIndex;
  uint8  LucData;
  LucData = SPI_ZERO;
  LenReturnValue = E_OK;
 /* Clear the status register */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */

  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0, SPI_CSIG_CLR_STS_FLAGS)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
                   (uint32)(SPI_CSIG_CLR_STS_FLAGS),SPI_SELFTEST_SID)
  /* END Msg(2:3892)- 21 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the OS base address of the HW Unit */
  LpCsigOsBaseAddr = (Spi_CsigOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
  /* END Msg(4:0316)-9 */
  /* Load the control register 1 to enable loop back mode */
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, SPI_CSIG_LOOPBACK_ENABLE)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
            SPI_CSIG_LOOPBACK_ENABLE, SPI_LOOPBACK_CSIG_MASK, SPI_SELFTEST_SID)
  /* Update the Baud rate and Pre-scalar values from control register2 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, SPI_LOOPBACK_CNTRL2_VALUE)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
        SPI_LOOPBACK_CNTRL2_VALUE, SPI_CTLREG_16_BIT_MASK, SPI_SELFTEST_SID)
  /* END Msg(2:3892)- 21 */
  /* Load back the value to configuration register */

  SPI_CSIGH_REG_WRITE(LpCsigOsBaseAddr->ulCSIGCFG0, SPI_LOOPBACK_DLS_SETTING)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigOsBaseAddr->ulCSIGCFG0,
        SPI_LOOPBACK_DLS_SETTING, SPI_CSIGCFG0_MASK, SPI_SELFTEST_SID)
  /* QAC Warning: START Msg(2:3892)- 21 */
  /* Load the control register 0 value, setting PWR bit at the same time*/
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_DIRECT_ACCESS)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
  SPI_SET_DIRECT_ACCESS, SPI_CTLREG_8_BIT_MASK, SPI_SELFTEST_SID)
  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the user base address of the HW Unit */
  LpCsigUserBaseAddr = (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(4:0316)-9 */

  /* Clear pending interrupts */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                          (SPI_CLR_INT_REQ));
  /* Register dummy read-write  */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* SYNCP execution */
  EXECUTE_SYNCP();
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  /* Load the loop back test dummy data to TX0W register */
  SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->usCSIGTX0H, SPI_LOOPBACK_DATA)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigUserBaseAddr->usCSIGTX0H,
  SPI_LOOPBACK_DATA, SPI_CTLREG_16_BIT_MASK, SPI_SELFTEST_SID)


  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  LusIndex = SPI_ZERO;
  /* Wait in the loop until the communication is stopped */
  while ((SPI_HW_BUSY == (LpMainUserBaseAddr->ulMainSTR0 & SPI_HW_BUSY))
                                           && (E_OK == LenReturnValue))
  {
    LusIndex++;
    /* Raise production error */
    /* Report error to DEM    */
    if (SPI_LOOP_TIMEOUT <= LusIndex)
    {
      Dem_ReportErrorStatus(SPI_E_DATA_TX_TIMEOUT_FAILURE,
                                                DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  if (E_OK == LenReturnValue)
  {
    /* Save the received data to a variable */
    LucData = (uint8) LpCsigUserBaseAddr->usCSIGRX0;
  }
  else
  {
    /*no action required */
  }

   /* Check for any Parity error */
   if ((uint32)SPI_ZERO != (LpMainUserBaseAddr->ulMainSTR0 & SPI_PE_ERR))
  {
    /*Clear the status bit */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:3892)- 21 */

    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                                        (uint16)SPI_PE_ERR_CLR)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
                                               SPI_PE_ERR_CLR,SPI_SELFTEST_SID)

    /* END Msg(2:2814)-20 */
    /* END Msg(2:3892)- 21 */
    /*Report error to DEM*/
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
    /*Set invalid data */
    LucData = SPI_LOOPBACK_ERROR;
  }
  else
  {
    /* No action required */
  }
  /* Clear pending interrupts */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Clear pending interrupts */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Reset all registers */
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
  SPI_ZERO, SPI_CTLREG_8_BIT_MASK, SPI_SELFTEST_SID)

  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, (uint32)SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
            (uint32)SPI_ZERO, SPI_CTLREG_32_BIT_MASK, SPI_SELFTEST_SID)
  /* QAC Warning: START Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, (uint16)SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
                    (uint16)SPI_ZERO, SPI_CTLREG_16_BIT_MASK, SPI_SELFTEST_SID)
  /* END Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpCsigOsBaseAddr->ulCSIGCFG0, (uint32)SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigOsBaseAddr->ulCSIGCFG0,
        (uint32)SPI_ZERO, SPI_CSIGCFG0_MASK, SPI_SELFTEST_SID)

  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                                        SPI_CSIG_CLR_STS_FLAGS)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpMainUserBaseAddr->ulMainSTR0, (uint32)SPI_ZERO,
                   (uint32)(SPI_CSIG_CLR_STS_FLAGS),SPI_SELFTEST_SID)
  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  return LucData;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* End of #if SPI_CSIG_CONFIGURED == STD_ON */
#endif /* End of #if (SPI_LOOPBACK_SELFTEST == SPI_ONE \
                                         ||SPI_LOOPBACK_SELFTEST == SPI_TWO ) */

/*******************************************************************************
** Function Name      : Spi_CsihLoopBackSelfTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data transmission self test
**                      using loop back mode in CSIH hardware unit.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                LpHWUnitInfo,
**                      P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                           LpMainUserBaseAddr,
**                      P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                              LpMainOsBaseAddr
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : uint8
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     :  CSIHnCTL0, CSIHnCTL1, CSIHnCTL2, CSIHnSTCR0, EICn,
**                       CSIHnBRS, CSIHCFG0, CSIHnTX0W, CSIHnRX0H, CSIHnSTR0.
*******************************************************************************/
/* Implements SPI_ESDD_UD_049 */
#if (SPI_LOOPBACK_SELFTEST == SPI_ONE ||SPI_LOOPBACK_SELFTEST == SPI_TWO )
#if (SPI_CSIH_CONFIGURED == STD_ON)
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(uint8, SPI_PRIVATE_CODE)Spi_CsihLoopBackSelfTest
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo,
P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainUserBaseAddr,
P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)LpMainOsBaseAddr)
/* END Msg(2:3227)-16 */
{
  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  Std_ReturnType LenReturnValue;
  uint16 LusIndex;
  uint8  LucData;
  LucData = SPI_ZERO;
  LenReturnValue = E_OK;
  /* Clear the status register */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0, SPI_CSIH_CLR_STS_FLAGS)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME( LpMainUserBaseAddr->ulMainSTR0,
             (uint32)SPI_ZERO,(uint32)(SPI_CSIH_CLR_STS_FLAGS),SPI_SELFTEST_SID)

  /* END Msg(2:3892)- 21 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the OS base address of the HW Unit */
  LpCsihOsBaseAddr = (Spi_CsihOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
  /* Get the user base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(4:0316)-9 */
  /* Load the control register 1 with the value of LoopBack enable */
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, SPI_CSIH_LOOPBACK_ENABLE)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
            SPI_CSIH_LOOPBACK_ENABLE, SPI_CTLREG_32_BIT_MASK, SPI_SELFTEST_SID)
  /* Update the Pre-scalar value from control register2 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2,
                                                SPI_LOOPBACK_CSIH_CNTRL2_VALUE)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
      SPI_LOOPBACK_CSIH_CNTRL2_VALUE, SPI_CTLREG_16_BIT_MASK, SPI_SELFTEST_SID)
  /* Implements SPI_ESDD_UD_187 */
  /* Update the Baud rate value from BRS register */
  SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->stCSIHBRS[SPI_ZERO].usCSIHBRS,
                                              SPI_LOOPBACK_CSIH_BRS0_VALUE)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
              LpCsihOsBaseAddr->stCSIHBRS[SPI_ZERO].usCSIHBRS,
              SPI_LOOPBACK_CSIH_BRS0_VALUE, SPI_CSIHBRS_MASK, SPI_SELFTEST_SID)
  /* END Msg(2:3892)- 21 */
  /* Initialize CSIH configuration register */
  SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->ulCSIHCFG[SPI_ZERO],
                                               SPI_LOOPBACK_DLS_SETTING)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
  LpCsihOsBaseAddr->ulCSIHCFG[SPI_ZERO],SPI_LOOPBACK_DLS_SETTING,
                                            SPI_CSIHCFG_MASK, SPI_SELFTEST_SID)

  /* Load Main CTL0 register, setting PWR bit at the same time */
  /* QAC Warning: START Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_DIRECT_ACCESS)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
               SPI_SET_DIRECT_ACCESS, SPI_CTLREG_8_BIT_MASK, SPI_SELFTEST_SID)
  /* END Msg(2:3892)- 21 */
  /* Clear pending interrupts */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Register dummy read-write  */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                          (SPI_CLR_INT_REQ));
  /* SYNCP execution */
  EXECUTE_SYNCP();
  #endif
  /* QAC Warning: START Msg(2:3892)- 21 */
  /* Load the loop back test dummy data to TX0W register */

  SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W, SPI_LOOPBACK_DATA)

  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */

  LusIndex = SPI_ZERO;
  /* Wait in the loop until the communication is stopped */
  while ((SPI_HW_BUSY == (LpMainUserBaseAddr->ulMainSTR0 & SPI_HW_BUSY))
                                                  && (E_OK == LenReturnValue))
  {
    LusIndex++;
    /* Raise production error */
       if (SPI_LOOP_TIMEOUT <= LusIndex)
    {
      Dem_ReportErrorStatus(SPI_E_DATA_TX_TIMEOUT_FAILURE,
                                                       DEM_EVENT_STATUS_FAILED);
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  if (E_OK == LenReturnValue)
  {
    /* Save the received data to a variable */
    LucData = (uint8) LpCsihUserBaseAddr->usCSIHRX0H;
  }
  else
  {
    /*no action required */
  }
  /* QAC Warning: START Msg(2:3892)- 21 */
  /* Check for any Parity error */
   if ((uint32)SPI_ZERO != (LpMainUserBaseAddr->ulMainSTR0 & SPI_PE_ERR))
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    /*Clear the status bit */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                                        (uint16)SPI_PE_ERR_CLR)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
                                                SPI_PE_ERR_CLR,SPI_SELFTEST_SID)
    /* END Msg(2:2814)-20 */
    /* END Msg(2:3892)- 21 */
    /*Report error to DEM*/
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
    /*Set invalid data */
    LucData = SPI_LOOPBACK_ERROR;
  }
  else
  {
    /* No action required */
  }
  /* Clear pending interrupts */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Clear pending interrupts */
  RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                           (SPI_CLR_INT_REQ));
  /* Reset all registers */
  /* QAC Warning: START Msg(2:3892)- 21 */
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
  SPI_ZERO, SPI_CTLREG_8_BIT_MASK, SPI_SELFTEST_SID)

  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, (uint32)SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
            (uint32)SPI_ZERO, SPI_CTLREG_32_BIT_MASK, SPI_SELFTEST_SID)

  SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->usMainCTL2, SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->usMainCTL2,
                   (uint16)SPI_ZERO, SPI_CTLREG_16_BIT_MASK, SPI_SELFTEST_SID)

  SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->stCSIHBRS[SPI_ZERO].usCSIHBRS,
                                                                      SPI_ZERO)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
  LpCsihOsBaseAddr->stCSIHBRS[SPI_ZERO].usCSIHBRS, SPI_ZERO, SPI_CSIHBRS_MASK,
                                                              SPI_SELFTEST_SID)

  SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->ulCSIHCFG[SPI_ZERO],
                                             (uint32)SPI_ZERO)

  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
  LpCsihOsBaseAddr->ulCSIHCFG[SPI_ZERO], (uint32)SPI_ZERO, SPI_CSIHCFG_MASK,
                                                              SPI_SELFTEST_SID)
  /* QAC Warning: START Msg(2:2814)-20 */
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                                        SPI_CSIH_CLR_STS_FLAGS)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
                   (uint32)(SPI_CSIH_CLR_STS_FLAGS),SPI_SELFTEST_SID)
  /* END Msg(2:2814)-20 */
  /* END Msg(2:3892)- 21 */
  return LucData;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* End of #if SPI_CSIH_CONFIGURED == STD_ON */
#endif /* End of #if (SPI_LOOPBACK_SELFTEST == SPI_ONE \
                      ||SPI_LOOPBACK_SELFTEST == SPI_TWO ) */

/*******************************************************************************
** Function Name      : Spi_EccAllZeroTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc one bit error test
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** Input Parameters   : P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                                 LpEccBaseAddr
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC.
*******************************************************************************/
/* Implements SPI_ESDD_UD_050 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllZeroTest
(P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr)
/* END Msg(2:3227)-16 */
{
  Std_ReturnType LenReturnValue;
  LenReturnValue = E_OK;
  /* Initialize RAM */
  /* QAC Warning: START Msg(2:2814)-20 */
  LpEccBaseAddr->ulEccTed = (uint32)RAM_INITIALIZE;
  /* END Msg(2:2814)-20 */
  /* Check ECEMF of CTL register is SET */
  if ((uint32)SPI_ZERO ==(LpEccBaseAddr->ulEccCTL & ECC_CTL_ECEMF_SET))
  {
    /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
    LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL |
                                               ECC_CTL_ECER1F_ECER2F_CLEAR);
  }
  else
  {
    /* No action required */
  }

  /* Write All zero test pattern to RAM */
  LpEccBaseAddr->ulEccTed = (uint32)ALL_ZERO_PATTERN;
  /* Implements SPI_ESDD_UD_189 */
  /* Write to ECC bits */
  LpEccBaseAddr->stEccTrc.ucErdb = (uint8)TRC_ERDB_INITIALIZE;
  /* Dummy Read value from RAM */
  if ((uint32)SPI_ZERO == LpEccBaseAddr->ulEccTed)
  {
    /*no action required, dummy read */
  }
  /*Start : SPI_UT_002*/
  else
  {
    /* No action required */
  }
  /* End : SPI_UT_002 */
  /* Check any error flag is set */
  if ((uint32)SPI_ZERO != (LpEccBaseAddr->ulEccCTL & CTL_ERR_FLAG))
  {
    /* Report to DEM */
    Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Clear Error flags */
    LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL|
                                                            CTL_ERRCLR_FLAG);
    /* Set Return value */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  return LenReturnValue;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of #if (SPI_ECC_SELFTEST == SPI_ONE
                                           || SPI_ECC_SELFTEST == SPI_TWO) */
#endif

/*******************************************************************************
** Function Name      : Spi_EccAllOneTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc one bit error test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                                 LpEccBaseAddr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC.
*******************************************************************************/
/* Implements SPI_ESDD_UD_051 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllOneTest
(P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr)
/* END Msg(2:3227)-16 */
{
  Std_ReturnType LenReturnValue ;
  LenReturnValue = E_OK;
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Initialize RAM */
  LpEccBaseAddr->ulEccTed = (uint32)RAM_INITIALIZE;
  /* END Msg(2:2814)-20 */
  /* Check ECEMF of CTL register is SET */
  if ((uint32)SPI_ZERO == (LpEccBaseAddr->ulEccCTL & ECC_CTL_ECEMF_SET))
  {
    /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
    LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL |
                                             ECC_CTL_ECER1F_ECER2F_CLEAR);
  }
  else
  {
    /* No action required */
  }
  /* Write All ONE test pattern to RAM */
  LpEccBaseAddr->ulEccTed = (uint32)ALL_ONE_PATTERN;
  /* write to ECC bits */
  LpEccBaseAddr->stEccTrc.ucErdb = (uint8)TRC_ERDB_INITIALIZE ;
  /* Dummy Read value from RAM */
  /*Start : SPI_UT_001*/
  if ((uint32)SPI_ZERO == LpEccBaseAddr->ulEccTed)
  {
    /*no action required */
  }
  /* End : SPI_UT_001 */
  else
  {
    /*no action required */
  }
  /* Check any error flag is set */
  if ((uint32)SPI_ZERO != ((LpEccBaseAddr->ulEccCTL)& (CTL_ERR_FLAG)))
  {
    /* Report DEM */
    Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Clear Error flags */
    LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL|
                                                               CTL_ERRCLR_FLAG);
    /* Set Return value */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No Action required */
  }
  return LenReturnValue;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of #if (SPI_ECC_SELFTEST == SPI_ONE
                                         || SPI_ECC_SELFTEST == SPI_TWO) */
#endif

/*******************************************************************************
** Function Name      : Spi_EccWalkOneTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc one bit error test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                                 LpEccBaseAddr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC.
*******************************************************************************/
/* Implements SPI_ESDD_UD_052 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccWalkOneTest
(P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr)
/* END Msg(2:3227)-16 */
{
  Std_ReturnType LenReturnValue ;
  uint8 LucCount;
  LenReturnValue = E_OK;
  LucCount = SPI_ZERO;
  do
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Initialize RAM */
    LpEccBaseAddr->ulEccTed = (uint32)RAM_INITIALIZE;
    /* END Msg(2:2814)-20 */
    /* Check ECEMF of CTL register is SET */
    if ((uint32)SPI_ZERO == (LpEccBaseAddr->ulEccCTL & ECC_CTL_ECEMF_SET))
    {
      /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
      LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL |
                                              ECC_CTL_ECER1F_ECER2F_CLEAR);
    }
    else
    {
        /* No action required */
    }
    /* A single data bit is set to 1 and "walked" through the
    entire code word and Other bits are set to "0" */
    LpEccBaseAddr->ulEccTed = (uint32)((uint32)SPI_ONE << LucCount);
    LpEccBaseAddr->stEccTrc.ucErdb = (uint8)TRC_ERDB_INITIALIZE ;
    /* Dummy Read of the value from RAM */
    /*Start : SPI_UT_005*/
    if ((uint32)SPI_ZERO == LpEccBaseAddr->ulEccTed)
    {
      /*no action required */
    }
    /* End : SPI_UT_005 */
    else
    {
        /* No action required */
    }
    if ( (uint32)SPI_ZERO == (LpEccBaseAddr->ulEccCTL& CTL_1BIT_ERR_FLAG))
    /* Check any error flag is set - Expected 1 bit error */
    {
      /* Report DEM */
      Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
                                           DEM_EVENT_STATUS_FAILED);
      /* Set Return value */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      LucCount++;
      /* Clear the one bit error flag by setting ECER1C bit of CTL Register */
      LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL|
                                                     CTL_1BIT_ERRCLR_FLAG);
    }
  }while ((SPI_DATAWORDLENGTH >= LucCount) && (E_NOT_OK != LenReturnValue) );

  return LenReturnValue;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* End of #if (SPI_ECC_SELFTEST == SPI_ONE \
                                              || SPI_ECC_SELFTEST == SPI_TWO) */
#endif

/*******************************************************************************
** Function Name      : Spi_EccTwoBitTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc two bit error test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                                 LpEccBaseAddr
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC.
*******************************************************************************/
/* Implements SPI_ESDD_UD_053 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccTwoBitTest
(P2VAR(Spi_EccRegs, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr)
/* END Msg(2:3227)-16 */
{
  Std_ReturnType LenReturnValue ;
  LenReturnValue = E_OK;
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Initialize RAM */
  LpEccBaseAddr->ulEccTed = (uint32)RAM_INITIALIZE;
  /* END Msg(2:2814)-20 */
  /* Check ECEMF of CTL register is SET */
  if ((uint32)SPI_ZERO == (LpEccBaseAddr->ulEccCTL & ECC_CTL_ECEMF_SET))
  {
    /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
    LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL |
                                               ECC_CTL_ECER1F_ECER2F_CLEAR);
  }
  else
  {
      /* No action required */
  }
  /* Write two bit test pattern to RAM */
  LpEccBaseAddr->ulEccTed = (uint32)TWO_BIT_PATTERN;
  LpEccBaseAddr->stEccTrc.ucErdb = (uint8)TRC_ERDB_INITIALIZE ;
  /* Dummy Read value from RAM */
  /*Start : SPI_UT_004*/
  if ((uint32)SPI_ZERO == LpEccBaseAddr->ulEccTed)
  {
    /*no action required */
  }
  /* End : SPI_UT_004 */
  else
  {
    /* No action required */
  }
  /* Check any error flag is set - Expected 2 bit error */
  if ((uint32)SPI_ZERO == ((LpEccBaseAddr->ulEccCTL)& (CTL_2BIT_ERR_FLAG)))
  {
    /* Report DEM */
    Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
                                            DEM_EVENT_STATUS_FAILED);
    /* Set Return value */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* Clear the one bit error flag by setting ECER2C bit of
                                                       CTL Register */
    LpEccBaseAddr->ulEccCTL = (uint32)(LpEccBaseAddr->ulEccCTL|
                                                    CTL_2BIT_ERRCLR_FLAG);
  }

  return LenReturnValue;
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* End of #if (SPI_ECC_SELFTEST == SPI_ONE
                                            || SPI_ECC_SELFTEST == SPI_TWO) */
#endif


/*******************************************************************************
** Function Name      : Spi_ProcessDirectAcessData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the Transmit ISR for
**                      processing the data in direct access mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit
**                      uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstJob,
**                      Spi_GaaChannelEBData, Spi_GpFirstChannel,
**                      Spi_GaaJobQueue, Spi_GpFirstJobList, Spi_GddQueueIndex,
**                      Spi_GpConfigPtr, Spi_GstCurrentCommData,
**                      Spi_GaaHighPriorityCommActive
**
** Function Invoked   : Spi_ProcessExtendedData, Spi_ProcessCsigData,
**                      Spi_ProcessCsihData
**
** Registers Used     : CSIGTX0H.
*******************************************************************************/

/* Implements SPI_ESDD_UD_067 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                   (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3206)-22 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE)Spi_ProcessDirectAcessData
                               (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
/* END Msg(2:3206)-22 */
{
  P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA)      LpNextTxData;
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpTxCurrentChannelList;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData;
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  #if ((SPI_8BIT_DATA_WIDTH == STD_ON) || (SPI_16BIT_DATA_WIDTH == STD_ON))
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  #endif
  #endif
  Spi_JobType LddJobIndex;
  Spi_NumberOfDataType LddBufferIndex;

  Spi_DataType LddData;
  Spi_JobType LddJobListIndex;

  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
   Spi_HWUnitType LddHWUnitNumber;
  #endif
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
  #endif
  {
    LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
  }
  /* END Msg(2:2814)-20 */
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  else
  {
    LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ONE + LddHWUnitNumber]);
  }
  #endif
  LpTxCurrentChannelList = LpCurrentCommData->pCurrentTxChannelList;
  /* MISRA Violation: START Msg(4:0489)-3*/
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Decrement the source pointer */
  LpTxCurrentChannelList--;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0489)-3 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the post-build structure of the channel */
  LpPBChannelConfig = Spi_GpFirstChannel + (*LpTxCurrentChannelList);
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* Get the pointer to the next data to be transmitted */
  LpNextTxData = LpCurrentCommData->pNextTxData;
  /* Get the index of job list for the current job from the job queue */
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[(LddHWUnitNumber
                                   + SPI_MAX_CSIH_HW_INDEX + SPI_TWO)]];
  #else
  LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
  #endif
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the respective job list index  */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* Get the index of the job */
  /* QAC Warning: START Msg(2:2814)-20 */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */

  /* QAC Warning: START Msg(2:2814)-20 */
  /* Update RAM with next channel, if channel properties are same */
  if ((SPI_ZERO == LpCurrentCommData->ddNoOfTxBuffers) &&
            (SPI_TRUE == LpJobConfig->blIsChannelPropSame) &&
                (SPI_ZERO < LpCurrentCommData->ddNoOfTxChannels)
                        #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
                        && (SPI_FALSE == LpCurrentCommData->blTxEDL)
                        #endif
     )
  /* END Msg(2:2814)-20 */
  {
    /* MISRA Violation: START Msg(4:0489)-3 */
    /* Increment the source pointer */
    LpTxCurrentChannelList++;
    /* END Msg (4:0489)-3 */
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
    /* MISRA Violation: START Msg(4:0489)-3 */
    (LpCurrentCommData->pCurrentTxChannelList)++;
    /* END Msg (4:0489)-3 */
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* Get the pointer to the post-build structure of the channel */
    LpPBChannelConfig = Spi_GpFirstChannel +
                                         (*LpTxCurrentChannelList);
    /* END Msg (4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
    /* END Msg(2:2814)-20 */
    /* Update the RAM for next channel */
    #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
    /* Check if the buffer type is internal buffer */
    if ((SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      || ((SPI_TRUE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
      && (SPI_ONE != LpPBChannelConfig->ucChannelBufferType))
      #endif
         )
    #endif
    {
      #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
      /* QAC Warning: START Msg(2:2814)-20 */
      LpNextTxData = Spi_GpConfigPtr->pChannelIBWrite;
      /* END Msg(2:2814)-20 */
      /* MISRA Violation: START Msg(4:0488)-4 */
      /* QAC Warning: START Msg(2:2824)-17 */
      LpNextTxData = LpNextTxData + LddBufferIndex;
      /* END Msg(2:2824)-17 */
      /* END Msg (4:0488)-4 */
      LpCurrentCommData->ddNoOfTxBuffers = LpPBChannelConfig->ddNoOfBuffers;
      #endif
    }
    #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
    else if (SPI_ONE == LpPBChannelConfig->ucChannelBufferType)
    #endif
    {
      #if (SPI_EB_CONFIGURED == STD_ON)
      LpNextTxData = Spi_GaaChannelEBData[LddBufferIndex].pSrcPtr;
      LpCurrentCommData->ddNoOfTxBuffers =
                            Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
      #endif
    }
    #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
    else
    {
      /* No action required */
    }
    #endif
    /* MISRA Violation: START Msg(4:2962)-11 */
    if (NULL_PTR != LpNextTxData)
    /* END Msg (4:2962)-11 */
    {
      /* MISRA Violation: START Msg(4:0489)-3 */
      LpNextTxData--;
      /* END Msg (4:0489)-3 */
    }
    else
    {
      /* No action required */
    }
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
    /* Save the pointer to next data to be transmitted */
    LpCurrentCommData->pNextTxData = LpNextTxData;
    (LpCurrentCommData->ddNoOfTxChannels)--;
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
  }
  else
  {
    /* No action required */
  }
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  if (SPI_TRUE == LpCurrentCommData->blTxEDL)
  {
    /* Reset the flag for indicating EDL */
    LpCurrentCommData->blTxEDL = SPI_FALSE;
    Spi_ProcessExtendedData(LddHWUnit, LpJobConfig, LpPBChannelConfig,
                                       LpCurrentCommData, LpNextTxData );
  }
  else
  #endif
  {
    /* Check if all buffers in the channel are transmitted */
    if (SPI_ZERO < LpCurrentCommData->ddNoOfTxBuffers)
    {
      if (NULL_PTR == LpNextTxData)
      {
        /* MISRA Violation: START Msg(4:0489)-3 */
        /* Get the configured default value */
        LddData = LpPBChannelConfig->ddDefaultData;
        /* END Msg (4:0489) -3 */
      }
      else
      {
        /* MISRA Violation: START Msg(4:0489)-3  */
        /* Get the value from the source pointer */
        LpNextTxData++;
        /* END Msg (4:0489)-3 */
        LddData = *LpNextTxData;
        LpCurrentCommData->pNextTxData = LpNextTxData;
      }

      /* MISRA Violation: START Msg(4:0489)-3 */
      /* Decrement the number of buffers to be transmitted */
      (LpCurrentCommData->ddNoOfTxBuffers)--;
      /* END Msg (4:0489)-3 */

      #if ((SPI_CSIG_CONFIGURED == STD_ON) && \
           (SPI_CSIH_CONFIGURED == STD_ON))
      if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
      #endif
      {
        #if (SPI_CSIG_CONFIGURED == STD_ON)
        #if ((SPI_8BIT_DATA_WIDTH == STD_ON) || \
                                               (SPI_16BIT_DATA_WIDTH == STD_ON))
        /* QAC Warning: START Msg(2:2814)-20 */
        /* Get the pointer to the structure of HW Unit information */
        LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
        /* MISRA Violation: START Msg(4:0316)-9 */
        /* Get the base address of the HW Unit */
        LpCsigUserBaseAddr =
                         (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;

        /* END Msg (4:0316)-9*/
        /* QAC Warning: START Msg(2:3892)- 21 */
        SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->usCSIGTX0H, (uint16)LddData)

        SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigUserBaseAddr->usCSIGTX0H,
        (uint16)LddData, SPI_CTLREG_16_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
        /* END Msg(2:3892)- 21 */
        #else
        Spi_ProcessCsigData(LddHWUnit, LpPBChannelConfig, LpCurrentCommData,
                                                                       LddData);
        #endif
        /* END Msg(2:2814)-20 */
        #endif
      }
      #if ((SPI_CSIG_CONFIGURED == STD_ON) && \
           (SPI_CSIH_CONFIGURED == STD_ON))
      else
      #endif
      {
        #if (SPI_CSIH_CONFIGURED == STD_ON)
        #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
        Spi_ProcessCsihData(LddHWUnit, LpJobConfig, LpPBChannelConfig,
                                               LpCurrentCommData, LddData );
        #else
         Spi_ProcessCsihData(LddHWUnit, LpJobConfig, LpCurrentCommData,
                                                                    LddData );
        #endif
        #endif
      }
    }
    else
    {
      /* No action required */
    }
  }
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif /*
          * End of (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
          *      (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
          *                          (SPI_HW_PRIORITY_ENABLED == STD_ON))
          */

/*******************************************************************************
** Function Name      : Spi_ProcessCsigData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the transmit ISR for
**                      processing Csig data.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit,
**                      P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST)
**                                                                  LpJobConfig,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                          SPI_CONFIG_CONST) LpPBChannelConfig,
**                      P2VAR(Spi_CurrentCommData, AUTOMATIC,
**                                           SPI_CONFIG_DATA) LpCurrentCommData,
**                      Spi_DataType LddData
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo
**
** Function Invoked   : None
**
** Registers Used     : CSIGnTX0W, CSIGnTX0H
*******************************************************************************/
/* Implements SPI_ESDD_UD_070 */

#if ((SPI_CSIG_CONFIGURED == STD_ON) && ((SPI_8BIT_DATA_WIDTH == STD_OFF) && \
                                         (SPI_16BIT_DATA_WIDTH == STD_OFF)))
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                   (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE)Spi_ProcessCsigData(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentCommData,
Spi_DataType LddData)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  /* MISRA Violation: START Msg(4:0759)-1  */
  Spi_DataAccess LunDataAccess1;
  Spi_DataAccess LunDataAccess2;
  /* END Msg(4:0759)-1 */
  uint32 LulShiftData;

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the base address of the HW Unit */
  LpCsigUserBaseAddr = (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/
  /*
   * Take a local union variable to construct the value for TX0W
   * register
   */
  LunDataAccess1.ulRegData = SPI_ZERO;

  /* QAC Warning: START Msg(2:2814)-20 */
  if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
  /* END Msg(2:2814)-20 */
                (SPI_TRUE != LpPBChannelConfig->blDirection) &&
                (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
  {
    LulShiftData = (uint32)LddData;
    LulShiftData = (uint32)(LulShiftData << (SPI_SIXTEEN -
                                            (LpPBChannelConfig->ucDLSSetting)));
    LunDataAccess2.ulRegData = LulShiftData;
    LunDataAccess1.Tst_ByteAccess.usRegData1 =
    LunDataAccess2.usRegData5[SPI_ZERO] >> (SPI_SIXTEEN -
                                             (LpPBChannelConfig->ucDLSSetting));
    LunDataAccess2.usRegData5[SPI_ZERO] =
                                       LunDataAccess1.Tst_ByteAccess.usRegData1;
  }
  else
  {
    /*
     * Data width is maximum 32-bit. Tx data needs to be split to
     * LS Byte and MS Byte. Hence, load the Tx data to local variable
     */
    LunDataAccess2.ulRegData = LddData;
  }
  if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
  {
    /*
     * Data width is maximum 16-bit. Hence, load LSB portion of the
     * local variable with the 16-bit data to be transmitted
     */
   /* QAC Warning: START Msg(2:2814)-20 */
   SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->usCSIGTX0H,
                                      LunDataAccess2.usRegData5[SPI_ZERO])

   SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigUserBaseAddr->usCSIGTX0H,
   LunDataAccess2.usRegData5[SPI_ZERO], SPI_CTLREG_16_BIT_MASK,
                                                          SPI_ASYNCTRANSMIT_SID)

   /* END Msg(2:2814)-20 */
  }
  else
  {
    /* Check if the configured data direction is LSB first */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Load Tx data portion of the local variable with LSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                           LunDataAccess2.usRegData5[SPI_ZERO];
    }
    else
    {
      /* Load Tx data portion of the local variable with MSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                        LunDataAccess2.usRegData5[SPI_ONE];
    }

    /* Set the EDL bit in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_EDL;
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Set the flag for indicating EDL */
    LpCurrentCommData->blTxEDL = SPI_TRUE;
    /* END Msg(2:2814)-20 */
    /* Load the value of the local union variable to TX0W register */
    SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ulCSIGTX0W,
                                                      LunDataAccess1.ulRegData)

  }
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name      : Spi_ProcessCsihData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the transmit ISR for
**                      processing Csih data
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit,
**                      P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST)
**                                                                  LpJobConfig,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                          SPI_CONFIG_CONST) LpPBChannelConfig,
**                      P2VAR(Spi_CurrentCommData, AUTOMATIC,
**                                           SPI_CONFIG_DATA) LpCurrentCommData,
**                      Spi_DataType LddData
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpConfigPtr,
**                      Spi_GaaHighPriorityCommRequest
**
** Function Invoked   : None
**
** Registers Used     : CSIHnTX0H, CSIHnTX0W
*******************************************************************************/

/* Implements SPI_ESDD_UD_071 */
 #if (SPI_CSIH_CONFIGURED == STD_ON)
 #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                   (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3673)-14  */
/* QAC Warning: START Msg(2:3227)-16 */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
FUNC(void, SPI_FAST_CODE)Spi_ProcessCsihData(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_DataType LddData)
#else
FUNC(void, SPI_FAST_CODE)Spi_ProcessCsihData(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_DataType LddData)
#endif
/* END Msg(2:3227)-16 */
/* END Msg(4:3673)-14 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  /* MISRA Violation: START Msg(4:0759)-1  */
  Spi_DataAccess LunDataAccess1;
  #if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
  Spi_DataAccess LunDataAccess2;
  /* END Msg(4:0759)-1 */
  uint32 LulShiftData;
  #else
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
   Spi_HWUnitType LddHWUnitNumber;
  #endif
  #endif

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/

  #if (SPI_8BIT_DATA_WIDTH == STD_ON) || \
                                     (SPI_16BIT_DATA_WIDTH == STD_ON)
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  /* END Msg(2:2814)-20 */
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Check if the buffer is last buffer of the channel */
  if (SPI_ZERO == LpCurrentCommData->ddNoOfTxBuffers)
  /* END Msg(2:2814)-20 */
  {
    /* Check if it is last channel in the job */
    if ((SPI_ZERO == LpCurrentCommData->ddNoOfTxChannels)
        #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
        && (SPI_FALSE ==  Spi_GaaHighPriorityCommRequest[LddHWUnitNumber])
        #endif
       )
    {
      /*
      * Data width is maximum 16-bit. Hence, load Tx data portion
      * of the local variable with the data to be transmitted
      */
      LunDataAccess1.Tst_ByteAccess.usRegData1 = LddData;
      /* Set chip select in the local union variable */
      /* QAC Warning: START Msg(2:2814)-20 */
      LunDataAccess1.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
      /* END Msg(2:2814)-20 */
      /* Since buffer is last buffer of the job set EOJ */
      LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_EOJ;
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Load the value of the local union variable to TX0W
       * register
       */
      SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                          LunDataAccess1.ulRegData)

      /* END Msg(2:2814)-20 */
    }
    else
    {
      /* Load the value of the local union variable to TX0H
       * register
       */

       SPI_CSIGH_REG_WRITE( LpCsihUserBaseAddr->usCSIHTX0H, (uint16)LddData)
       /* QAC Warning: START Msg(2:3892)- 21 */
       SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihUserBaseAddr->usCSIHTX0H,
        (uint16)LddData, SPI_CTLREG_16_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
       /* END Msg(2:3892)- 21 */
    }
  }
  else
  {
    /* Load the value of the local union variable to TX0H
    * register
    */
    SPI_CSIGH_REG_WRITE( LpCsihUserBaseAddr->usCSIHTX0H, (uint16)LddData)
    /* QAC Warning: START Msg(2:3892)- 21 */
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihUserBaseAddr->usCSIHTX0H,
        (uint16)LddData, SPI_CTLREG_16_BIT_MASK, SPI_ASYNCTRANSMIT_SID)
    /* END Msg(2:3892)- 21 */
  }
  #else
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Take a local union variable to construct the value for TX0W
   * register
   */
  LunDataAccess1.ulRegData = SPI_ZERO;
  if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
  /* END Msg(2:2814)-20 */
               (SPI_TRUE != LpPBChannelConfig->blDirection) &&
               (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
               (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
  {
    LulShiftData = (uint32) LddData;
    LulShiftData = (LulShiftData << (SPI_SIXTEEN -
                                            (LpPBChannelConfig->ucDLSSetting)));
    LunDataAccess2.ulRegData = LulShiftData;
    LunDataAccess1.Tst_ByteAccess.usRegData1 =
    LunDataAccess2.usRegData5[SPI_ZERO] >> (SPI_SIXTEEN -
                                             (LpPBChannelConfig->ucDLSSetting));
    LunDataAccess2.usRegData5[SPI_ZERO] =
                                      LunDataAccess1.Tst_ByteAccess.usRegData1;
  }
  else
  {
    /* Data width is maximum 32-bit. Tx data needs to be split to
    * LS Byte and MS Byte. Hence, load the Tx data to local variable
    */
    LunDataAccess2.ulRegData = LddData;
  }

   if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Check if the buffer is last buffer of the channel */
    if ((SPI_ZERO == LpCurrentCommData->ddNoOfTxBuffers) &&
                (SPI_ZERO == LpCurrentCommData->ddNoOfTxChannels))
    {
      /* Set chip select in the local union variable */
      LunDataAccess2.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
      /* Since buffer is last buffer of the job set EOJ */
      LunDataAccess2.Tst_ByteAccess.ucRegData3 = SPI_SET_EOJ;

      /* Load the value of the local union to TX0W register */
      SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                                     LunDataAccess2.ulRegData)

    }
    else
    {
      /* Data width is maximum 16-bit. Hence, load LSB portion of the
       * local variable with the 16-bit data to be transmitted
       */
      SPI_CSIGH_REG_WRITE( LpCsihUserBaseAddr->usCSIHTX0H,
                                            LunDataAccess2.usRegData5[SPI_ZERO])
      /* QAC Warning: START Msg(2:3892)- 21 */
      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsihUserBaseAddr->usCSIHTX0H,
        LunDataAccess2.usRegData5[SPI_ZERO], SPI_CTLREG_16_BIT_MASK,
                                                          SPI_ASYNCTRANSMIT_SID)
      /* END Msg(2:3892)- 21 */

    }

    /* END Msg(2:2814)-20 */
  }
  else
  {
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Load Tx data portion of the local variable with LSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                          LunDataAccess2.usRegData5[SPI_ZERO];
    }
    else
    {
      /* Load Tx data portion of the local variable with MSB first */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                           LunDataAccess2.usRegData5[SPI_ONE];
    }
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Set chip select in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
    /* END Msg(2:2814)-20 */

    /* Set the EDL bit in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_EDL;

    /* QAC Warning: START Msg(2:2814)-20 */
    /* Set the flag for indicating EDL */
    LpCurrentCommData->blTxEDL = SPI_TRUE;
    /* END Msg(2:2814)-20 */

    /* Load the value of the local union variable to TX0W register */
    SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                                     LunDataAccess1.ulRegData)

  }
  #endif
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name      : Spi_ProcessExtendedData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in SPI_DIRECT_ACCESS_MODE to
**                      process the data grater than 16-bit.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit
**                      P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST)
**                                                                  LpJobConfig
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                          SPI_CONFIG_CONST) LpPBChannelConfig,
**                      P2VAR(Spi_CurrentCommData, AUTOMATIC,
**                                           SPI_CONFIG_DATA) LpCurrentCommData,
**                      P2CONST(Spi_DataType, AUTOMATIC,
**                                                 SPI_CONFIG_DATA) LpNextTxData
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo
**
** Function Invoked   : None
**
** Registers Used     : CSIGnTX0W, CSIHnTX0W
*******************************************************************************/

/* Implements SPI_ESDD_UD_072 */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                   (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"

/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE)Spi_ProcessExtendedData(Spi_HWUnitType LddHWUnit,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2CONST(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData )
{
  /* END Msg(2:3227)-16 */
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  #endif
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  #endif
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  Spi_DataAccess LunDataAccess2;
  /* END Msg(4:0759)-1 */

  Spi_DataType LddData;


  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  /* MISRA Violation: START Msg(4:2962)-11 */
  if (NULL_PTR == LpNextTxData)
  /* END Msg (4:2962)-11 */
  {
  /* QAC Warning: START Msg(2:2814)-20 */
    LddData = LpPBChannelConfig->ddDefaultData;
  /* END Msg(2:2814)-20 */
  }
  else
  {
    LddData = *LpNextTxData;
  }

  /* Take a local union variable to construct the value for TX0W
   * register
   */
  LunDataAccess1.ulRegData = SPI_ZERO;
  /* Data width is maximum 32-bit. Tx data needs to be split to
   * LS Byte and MS Byte. Hence, load the Tx data to local variable
   */
  LunDataAccess2.ulRegData = LddData;

  /* Check if the configured data direction is LSB first */
  if (SPI_TRUE == LpPBChannelConfig->blDirection)
  {
    /* Load Tx data portion of the local variable with LSB first */
    LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                             LunDataAccess2.usRegData5[SPI_ONE];
  }
  else
  {
    /* Load Tx data portion of the local variable with MSB first */
    LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
  #endif
  {
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Set chip select in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
    /* END Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Check if the buffer is last buffer of the Job */
    if ((SPI_ZERO == LpCurrentCommData->ddNoOfTxBuffers) &&
    /* END Msg(2:2814)-20 */
                  (SPI_ZERO == LpCurrentCommData->ddNoOfTxChannels))
    {
      /* Since buffer is last buffer of the job set EOJ */
      LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_EOJ;
    }
    else
    {
      /* No action required */
    }

    #endif
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  {
    /* No action required */
  }
  #endif

  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
  #endif
  {
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    /* MISRA Violation: START Msg(4:0316)-9 */
    /* Get the base address of the HW Unit */
    LpCsigUserBaseAddr = (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
    /* END Msg(4:0316)-9 */

    /* QAC Warning: START Msg(2:2814)-20 */
    /* Load the value of the local union variable to TX0W register */
    SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ulCSIGTX0W,
                                                      LunDataAccess1.ulRegData)

    /* END Msg(2:2814)-20 */
    #endif
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  #endif
  {
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* MISRA Violation: START Msg(4:0316)-9 */
    /* Get the base address of the HW Unit */
    LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
    /* END Msg(4:0316)-9 */
    /* Load the value of the local union variable to TX0W register */
    /* QAC Warning: START Msg(2:2814)-20 */

    SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                                     LunDataAccess1.ulRegData)

    /* END Msg(2:2814)-20 */
    #endif
  }
 }
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name      : Spi_ProcessFifoData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the TIC ISR for processing
**                      communication status interrupt request in Fifo mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GddAsyncMode, Spi_GpFirstJob,
**                      Spi_GaaChannelEBData, Spi_GpFirstChannel,
**                      Spi_GaaJobQueue, Spi_GpFirstJobList, Spi_GddQueueIndex,
**                      Spi_GstFifoCurrentCommData, Spi_GpConfigPtr,
**                      Spi_GddDmaData, Spi_GucHWFifoBufferSts
**
** Function Invoked   : Spi_ProcessSequence, Spi_RxDmaConfig, Spi_FifoReadData,
**                      Spi_ProcessChannelInFifoMod.
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_068 */
#if (SPI_FIFO_MODE == STD_ON)
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements AR_PN0063_FR_0073, AR_PN0063_FR_0075, AR_PN0063_FR_0079 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE)Spi_ProcessFifoData(Spi_HWUnitType LddHWUnit,
                                                          uint8 LucHWMemoryMode)
/* END Msg (2:3227)-16 */

{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentRxChannelList;
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData;
  Spi_JobType LddJobIndex;
  Spi_NumberOfDataType LddBufferIndex;
  Spi_NumberOfDataType LddNoOfBuffers;
  Spi_ChannelType LddNoOfChannels;

  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* QAC Warning: START Msg(2:2824)-17 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  LpJobList = Spi_GpFirstJobList +
                            Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
  /* END Msg Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */

  /* Get the index of the first job linked to this sequence */
  /* QAC Warning: START Msg(2:2814)-20 */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg (4:0488)-4 */
  /* END Msg(2:2824)-17 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  if (SPI_FIFO_BUFFER_UNINIT ==
                               (uint8)Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX])
  /* END Msg(2:3892)- 21 */
  {
    /* QAC Warning: START Msg(2:2814)- 20 */
    Spi_GstFifoCurrentCommData.pCurrentRxChannelList =
                                                      LpJobConfig->pChannelList;
    /* END Msg(2:2814)- 20 */
    Spi_GstFifoCurrentCommData.ddNoOfRxChannels = LpJobConfig->ddNoOfChannels;
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    Spi_GstFifoCurrentCommData.ddJobIndex = LddJobIndex;
    #endif
  }
  else
  {
    /* No Action Required */
  }
  Spi_GstFifoCurrentCommData.usBufferCount = SPI_ZERO;
  do
  {
    LpCurrentRxChannelList = Spi_GstFifoCurrentCommData.pCurrentRxChannelList;

    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the post-build structure of the channel */
    LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentRxChannelList);
    /* END Msg (2:2824)-17 */
    /* END Msg (4:0488)-4 */

    /* QAC Warning: START Msg(2:3892)- 21 */
    if (SPI_FIFO_BUFFER_FULL !=
                               (uint8)Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX])
    /* END Msg(2:3892)- 21 */
    {
      LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
      /* END Msg (2:2814)-20 */

      #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
      /* Check if the buffer type is internal buffer */
      if (SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
      #endif
      {
        #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
        /* QAC Warning: START Msg(2:2814)-20 */
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* Update the RAM variable for Rx pointer with channel IB index */
        LpCurrentRxData = (Spi_GpConfigPtr->pChannelIBRead) + LddBufferIndex;
        /* END Msg (2:2814)-20 */
        /* END Msg (4:0488)-4 */

        /* Update the RAM variable for number of buffers of the channel */
        LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;
        #endif
      }

      #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
      else
      #endif
      {
        #if (SPI_EB_CONFIGURED == STD_ON)
        /* Update the RAM variable for Rx pointer */
        LpCurrentRxData = Spi_GaaChannelEBData[LddBufferIndex].pDestPtr;

        /* Update the local counter with number of buffers of the channel */
        LddNoOfBuffers = Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
        #endif
      }
    }
    else
    {
      /* Load data from the RAM */
      LpCurrentRxData = Spi_GstFifoCurrentCommData.pCurrentRxData;
      LddNoOfBuffers = Spi_GstFifoCurrentCommData.ddNoOfRxBuffers;
    }

    /* If the selected asynchronous mode is DMA mode */
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    /* MISRA Violation: START Msg(4:2962)-11 */
    if ((SPI_INTERRUPT_MODE == Spi_GddAsyncMode) &&
                (SPI_INVALID_DMAUNIT == LpJobConfig->ucRxDmaDeviceIndex))
    /* END Msg(4:2962)-11 */
    #endif
    {
      Spi_FifoReadData(LpHWUnitInfo, LpPBChannelConfig,
                                              LpCurrentRxData, LddNoOfBuffers);
    }
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    else
    {
      /* QAC Warning: START Msg(2:3892)- 21 */
      /* Check the number of buffers to be transmitted */
      if (SPI_FIFO_SIZE < LddNoOfBuffers)
      {
        /* Set the flag as the number of buffers are more than Fifo size */
        Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX] = SPI_FIFO_BUFFER_FULL;
        /* Save the current details in RAM */
        Spi_GstFifoCurrentCommData.pCurrentRxData = LpCurrentRxData;
        Spi_GstFifoCurrentCommData.ddNoOfRxBuffers = LddNoOfBuffers;
        /* Update the number of buffers to Max size */
        LddNoOfBuffers = SPI_FIFO_SIZE;
        /* END Msg(2:3892)- 21 */
      }
      else
      {
        /* QAC Warning: START Msg(2:3892)-21 */
        Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX] = SPI_FIFO_BUFFER_EMPTY;
        /* END Msg(2:3892)-21 */
      }
      Spi_GstFifoCurrentCommData.ucDmaDeviceIndex =
                                                LpJobConfig->ucRxDmaDeviceIndex;
      Spi_GddDmaData = LpPBChannelConfig->ddDefaultData;

      /* MISRA Violation: START Msg(4:2962)-11 */
      Spi_RxDmaConfig(LpJobConfig, LpCurrentRxData, LddNoOfBuffers);
      /* END Msg(4:2962)-11 */
    }
    #endif

      /* If the selected asynchronous mode is DMA mode */
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    /* MISRA Violation: START Msg(4:2962)-11 */
    if (SPI_INVALID_DMAUNIT == LpJobConfig->ucRxDmaDeviceIndex)
    /* END Msg(4:2962)-11 */
    #endif
    {
      /* QAC Warning: START Msg(2:3892)- 21 */
      if ((SPI_FIFO_BUFFER_EMPTY ==
                          (uint8)Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX]) &&
                       (SPI_ZERO < Spi_GstFifoCurrentCommData.ddNoOfRxChannels))
      /* END Msg(2:3892)- 21 */
      {
        /* MISRA Violation: START Msg(4:0489)-3 */
        /* QAC Warning: START Msg(2:2824)-17 */
        Spi_GstFifoCurrentCommData.pCurrentRxChannelList++;
        /* END Msg (4:0489)-3 */
        /* END Msg (2:2824)-17 */
        /* Decrement the counter for number of channels */
        Spi_GstFifoCurrentCommData.ddNoOfRxChannels--;
        /* QAC Warning: START Msg(2:3892)-21 */
        if (SPI_FIFO_SIZE <= Spi_GstFifoCurrentCommData.usBufferCount)
        /* END Msg(2:3892)- 21 */
        {
          /* Break the loop */
          LddNoOfChannels = SPI_ZERO;
        }
        else
        {
          /* Get the remaining number of channels */
          LddNoOfChannels = Spi_GstFifoCurrentCommData.ddNoOfRxChannels;
        }
      }
      else
      {
        /* Break the loop */
        LddNoOfChannels = SPI_ZERO;
        Spi_GstFifoCurrentCommData.usBufferCount = SPI_ZERO;
      }
    }
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    else
    {
      /* Break the loop in case of DMA mode*/
      LddNoOfChannels = SPI_ZERO;
    }
    #endif
  }while (SPI_ZERO < LddNoOfChannels);
  /* If the selected asynchronous mode is DMA mode */
  #if (SPI_DMA_MODE_ENABLE == STD_ON)

  if ((SPI_INTERRUPT_MODE == Spi_GddAsyncMode) &&
                (SPI_INVALID_DMAUNIT == LpJobConfig->ucRxDmaDeviceIndex))
  #endif
  {
    /* QAC Warning: START Msg(2:3892)- 21 */
    if ((SPI_FIFO_BUFFER_EMPTY ==
                              (uint8)Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX])
        && (SPI_FIFO_SIZE > Spi_GstFifoCurrentCommData.usBufferCount ))
     /* END Msg(2:3892)- 21 */
    {
      /* All channels are transmitted. Hence the job is transmitted */
      Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
    }
    else
    {
      /* Reset the buffer count as the Fifo is full */
      Spi_GstFifoCurrentCommData.usBufferCount = SPI_ZERO;
      /* Process the remaining data */
      Spi_ProcessChannelInFifoMod(LddHWUnit, LucHWMemoryMode);
    }
  }
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_ProcessDualBufferData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked in the TIC ISR for processing
**                      communication status interrupt request in Dual buffer
**                      mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit
**                      uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstJob,
**                      Spi_GaaJobResult, Spi_GaaSeqResult, Spi_GaaSeqQueue,
**                      Spi_GpFirstJobList, Spi_GddQueueIndex, Spi_GpConfigPtr
**                      Spi_GpFirstSeq, Spi_GstDualBufferCurrentCommData
**
** Function Invoked   : Spi_ProcessSequence.
**
** Registers Used     : CSIHnMCTL2.
*******************************************************************************/
/* Implements SPI_ESDD_UD_069 */
#if (SPI_DUAL_BUFFER_MODE == STD_ON)
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements SPI118, SPI071, SPI054 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE)Spi_ProcessDualBufferData(Spi_HWUnitType LddHWUnit,
                          uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobListTmptr;
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  P2VAR(Spi_DualBufferCurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
                                                LpDualBufferCurrentCommData;
  Spi_JobType LddJobIndex;
  Spi_NumberOfDataType LddBufferIndex;
  Spi_NumberOfDataType LddNoOfBuffers;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  Spi_JobType LddNoOfJobs;
  Spi_SequenceType LddSeqIndex;
  Spi_HWUnitType LddHWUnitNumber;

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* QAC Warning: START Msg(2:2814)-20 */
  LpDualBufferCurrentCommData = &Spi_GstDualBufferCurrentCommData
                     [Spi_GpConfigPtr->aaHWUnitCurrentCommDataIndex[LddHWUnit]];
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  /* END Msg(2:2814)-20 */
  /* Get the index of the sequence */
  LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];

  /* QAC Warning: START Msg(2:2824)-17 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
  /* END Msg (4:0488)-4 */
  /* END Msg(2:2824)-17 */
  /* Get the buffer index value */
  LddBufferIndex = *(LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx);

  /* MISRA Violation: START Msg(4:0489)-3 */
  /* Increment the notify index value */
  (LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx)++;
  /* END Msg (4:0489)-3 */
  /* Get the index of the job and sequence */
  LddJobIndex =
       (Spi_JobType)(*(LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx));
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(4:0316)-9 */

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* Check if notification is configured */
  /* QAC Warning: START Msg(2:2824)-17 */
  if (NULL_PTR != ((Spi_GpFirstJob + LddJobIndex)->pSpiJobNotification))
  /* END Msg (4:0488)-4 */
  {
    /* END Msg(2:2824)-17 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    (Spi_GpFirstJob + LddJobIndex)->pSpiJobNotification();
    /* END Msg (4:0488)-4 */
  }
  else
  {
    /* No action required */
  }
  /* QAC Warning: START Msg(2:2814)-20 */
  if ((LpDualBufferCurrentCommData->ddNoOfBuffersTxtd) <
                                                     LpSeqConfig->ddNoOfBuffers)
  {
  /* END Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0489)-3 */
    /* Increment the notify index value */
    (LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx)++;
    /* END Msg (4:0489)-3 */
    /* Get the number of buffers configured for the requested channel */
    LddNoOfBuffers = (*(LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx)
                                                         - LddBufferIndex);

    LpDualBufferCurrentCommData->ddNoOfBuffersTxtd =
                LpDualBufferCurrentCommData->ddNoOfBuffersTxtd + LddNoOfBuffers;

    /*
     * Take a local union variable to construct the value for MCTL2
     * register and load the local union variable with SOP value
     */
    LunDataAccess1.Tst_ByteAccess.usRegData1 = LddBufferIndex;

    /* Load the local union variable with number of data */
    LunDataAccess1.Tst_ByteAccess.ucRegData2 = (uint8)LddNoOfBuffers;

    /* Set BTST bit */
    LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_BTST;

    /* QAC Warning: START Msg(2:2814)-20 */
    /* Load the MCTL2 register to start the communication */
    SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMCTL2,
                                                       LunDataAccess1.ulRegData)

    /* END Msg(2:2814)-20 */
  }
  else
  {
    /*
     * All channels are transmitted and received. Hence the sequence is
     * completed
     */
    /* Update sequence result as OK if sequence is not failed*/
    if (SPI_SEQ_FAILED != Spi_GaaSeqResult[LddSeqIndex])
    {
        Spi_GaaSeqResult[LddSeqIndex] = SPI_SEQ_OK;
    }
    else
    {
      /*Do nothing*/
    }
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Load Job List pointer to temporary variable */
    LpJobListTmptr = Spi_GpFirstJobList + (LpSeqConfig->ddJobListIndex);
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */

    /* Load total number of Jobs in current sequence to local variable */
    LddNoOfJobs = LpSeqConfig->ddNoOfJobs;

    do
    {
      /* Update job result as OK if job is not failed*/
      if (SPI_JOB_FAILED != Spi_GaaJobResult[LpJobListTmptr->ddJobIndex])
      {
        /* QAC Warning: START Msg(2:2814)-20 */
        /* Update the job result variable */
        Spi_GaaJobResult[LpJobListTmptr->ddJobIndex] = SPI_JOB_OK;
        /* END Msg(2:2814)-20 */
      }
      else
      {
        /*Do nothing*/
      }
      /* MISRA Violation: START Msg(4:0489)-3 */
      /* Increment local pointer to the job list */
      LpJobListTmptr++;
      /* END Msg (4:0489)-3 */
      LddNoOfJobs--;
    }
    while (SPI_ZERO < LddNoOfJobs);
    /* All channels are transmitted. Hence the job is transmitted */
    Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
  }
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name       : Spi_SeqJobChannelInit
**
** Service ID          : 0x00
**
** Description         : This service performs initialization of the SPI Driver
**                       Sequence results, job results and channel data.
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
** Return parameter    : None
**
** Preconditions       : None
**
** Global Variable     : Spi_GaaJobResult, Spi_GpFirstSeq, Spi_GpFirstJobList
**                       Spi_GpFirstJob, Spi_GstHWUnitInfo, Spi_GpConfigPtr
**                       Spi_GpFirstChannel, Spi_GaaChannelEBData,
**                       Spi_GddAsyncMode, Spi_GaaSeqCancel
**
** Function Invoked    : Spi_InternalWriteIB, Spi_HWInit.
**
** Registers Used      : None
*******************************************************************************/
/* Implements SPI_ESDD_UD_054 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI015, SPI154, SPI151 */
FUNC(void, SPI_PRIVATE_CODE)Spi_SeqJobChannelInit(void)

{
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                              LpPBChannelConfig;
  #if ((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) && \
                                   (SPI_HW_PRIORITY_ENABLED == STD_ON))
  /* Declare a local pointer to point to the Sequence Config Data */
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Declare a local pointer to point to the Configured chipselect of job */
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpChipSelect;
  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  uint8 LucCSCount;
  #endif /*END of SPI_CSIH_CONFIGURED */
  Spi_JobType LddJobIndex;
  #endif /*END of SPI_HW_PRIORITY_ENABLED */
  #if (((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) && \
                                   (SPI_HW_PRIORITY_ENABLED == STD_ON)) || \
          ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON)))
  Spi_HWUnitType LddHWUnit;
  #endif
  #if (((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) && \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON)) ||\
                                        (SPI_CSIG_CONFIGURED == STD_ON))
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  #endif
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, SPI_CONFIG_DATA) LpPortGpAdd;
  uint32 LulPinMskVal;
  #endif
  #if (SPI_EB_CONFIGURED == STD_ON)
  Spi_NumberOfDataType LddNoOfBuffers;
  #endif
  #if (SPI_CANCEL_API == STD_ON)
  uint8 LucVar;
  #endif
  Spi_JobType LddNumJobs;
  Spi_SequenceType LddNumSeq;
  Spi_ChannelType LddNumChannel;

  LddNumJobs = SPI_ZERO;
  /* MISRA Violation: START Msg(4:2877)-12 */
  while (SPI_MAX_JOB > LddNumJobs)
  /* END Msg(4:2877)-12 */
  {
    /* Update contents of Job result pointer */
    Spi_GaaJobResult[LddNumJobs] = SPI_JOB_OK;
    /* Default value settings for the configured pins in case of CSIG*/
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:2824)-17 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:3892)- 21 */
    LpJobConfig = Spi_GpFirstJob + LddNumJobs;
    /* END Msg(2:3892)- 21 */
    /* END Msg (4:0488)-4 */
    /* END Msg(2:2824)-17 */
    #endif
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
     /* QAC Warning: START Msg(2:2814)-20 */
     LddHWUnit = LpJobConfig->ddHWUnitIndex;
     /* END Msg(2:2814)-20 */
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      if (NULL_PTR != LpJobConfig->pPortGrpRegAddress)
      {
        /* Get the port group address */
        LpPortGpAdd = LpJobConfig->pPortGrpRegAddress;
        /* Get the pin mask value */
        LulPinMskVal = LpJobConfig->ulPortPinMask;
        /* If Chip select polarity is configured as active High */
        if (SPI_ONE == LpJobConfig->blCsPolarity)
        {
          /* QAC Warning: START Msg(2:2814)-20 */
          /* set the default level as Low */
          *LpPortGpAdd = (LulPinMskVal & SPI_PORT_REG_MASK);
          /* END Msg(2:2814)-20 */
        }
        else /* If Chip select polarity is configured as active Low */
        {
          /* set the default level as High */
          *LpPortGpAdd  =  LulPinMskVal;
        }
      }
      else
      {
        /* No action required */
      }
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    {
      /* No action required */
    }
    #endif

        /* MISRA Violation: START Msg(4:2984)-10 */
    /* Increment number of jobs configured */
    LddNumJobs++;
    /* END Msg(4:2984)-10 */
  }

  /* Load the number of sequence configured as zero */
  LddNumSeq = SPI_ZERO ;
  /* MISRA Violation: START Msg(4:2877)-12 */
  while (SPI_MAX_SEQUENCE > LddNumSeq)
  /* END Msg(4:2877)-12 */
  {
    /* Update contents of Sequence result pointer */
    Spi_GaaSeqResult[LddNumSeq] = SPI_SEQ_OK;

    #if ((SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) && \
                                   (SPI_HW_PRIORITY_ENABLED == STD_ON))
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpSeqConfig = Spi_GpFirstSeq + LddNumSeq;
    /* END Msg(4:0488)-4 */
    /* END Msg(2:2824)-17 */
    /* QAC Warning: START Msg(2:2814)-20 */
    if (SPI_TRUE == LpSeqConfig->blIsHighPriority)
    {
      /* MISRA Violation: START Msg(4:0488)-4 */
      /* QAC Warning: START Msg(2:2824)-17 */
      /* Get the pointer to the job list */
      LpJobList = Spi_GpFirstJobList + (LpSeqConfig->ddJobListIndex);
      /* END Msg(4:0488)-4 */
      /* END Msg(2:2824)-17 */
      /* Get the index of the job and sequence */
      LddJobIndex = LpJobList->ddJobIndex;
      /* END Msg(2:2814)-20*/

      /* MISRA Violation: START Msg(4:0488)-4 */
      /* Get the pointer of the first job linked to this sequence */
      LpJobConfig = Spi_GpFirstJob + LddJobIndex;
      /* END Msg(4:0488)-4 */

      LddHWUnit = LpJobConfig->ddHWUnitIndex;

      /* Get the pointer to the structure of HW Unit information */
      LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

      #if ((SPI_CSIG_CONFIGURED == STD_ON) && \
                                       (SPI_CSIH_CONFIGURED == STD_ON))
      if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
      #endif /*
              * (SPI_CSIG_CONFIGURED == STD_ON) && \
              *                       (SPI_CSIH_CONFIGURED == STD_ON)
              */
      {
        #if (SPI_CSIH_CONFIGURED == STD_ON)
        /* Get the CSIH base address */
        /* MISRA Violation: START Msg(4:0316)-9 */
        LpCsihOsBaseAddr = (Spi_CsihOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;

        /* MISRA Violation: START Msg(4:0488)-4 */
        /* END Msg(4:0316)-9 */
        /* QAC Warning: START Msg(2:2814)-20 */
        /* Get the value for multiple chip selects configured */
        LpChipSelect =
                    (Spi_GpConfigPtr->pCSArray) + (LpJobConfig->ucCSArrayIndex);
        /* END Msg(4:0488)-4 */
        LucCSCount = LpJobConfig->ucNoOfCS;
       do
       {
         /* Initialize CSIH configuration register */
         SPI_CSIGH_REG_WRITE( LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
                             LpJobConfig->ulConfigRegValue)
         SPI_CSIGH_REG_WRITE_VERIFY_INIT(
         LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
         LpJobConfig->ulConfigRegValue,SPI_CSIHCFG_MASK, SPI_INIT_SID)

         LucCSCount--;
         /* END Msg(2:2814)-20 */
         /* MISRA Violation: START Msg(4:0489)-3*/
         LpChipSelect++;
         /* END Msg(4:0489)-3*/
      }while (SPI_ZERO < LucCSCount);

        #endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
      }
      #if ((SPI_CSIG_CONFIGURED == STD_ON) && \
                                     (SPI_CSIH_CONFIGURED == STD_ON))
      else
      #endif /*
              * (SPI_CSIG_CONFIGURED == STD_ON) && \
              *                       (SPI_CSIH_CONFIGURED == STD_ON)
              */
      {
        /* No Action Required */
      }
    }
    else
    {
      /* No action required */
    }
    #endif /*
            * (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) && \
            *                       (SPI_HW_PRIORITY_ENABLED == STD_ON)
            */
    /* MISRA Violation: START Msg(4:2984)-10 */
    /* Increment number of sequences configured */
    LddNumSeq++;
    /* END Msg(4:2984)-10 */
  }
  /* Get the number of channels configured */
  LddNumChannel = SPI_ZERO;
  /* Get the pointer to the post-build structure of channel */
  LpPBChannelConfig = Spi_GpFirstChannel;

  while (SPI_MAX_CHANNEL > LddNumChannel)
  {
    #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
    /* QAC Warning: START Msg(2:2814)-20 */
    if (SPI_ONE == LpPBChannelConfig->ucChannelBufferType)
    /* END Msg(2:2814)-20 */
    #endif
    {
      #if (SPI_EB_CONFIGURED == STD_ON)
      /* QAC Warning: START Msg(2:2814)-20 */
      LddNoOfBuffers = LpPBChannelConfig->ddBufferIndex;
      /* END Msg(2:2814)-20 */
      /* Length of external buffer in RAM area of EB */
      Spi_GaaChannelEBData[LddNoOfBuffers].ddEBLength =
                                            (LpPBChannelConfig->ddNoOfBuffers);

      /*
       * Copy the source pointer to RAM area allocated for the external
       * buffer attributes of the channel
       */
      Spi_GaaChannelEBData[LddNoOfBuffers].pSrcPtr = NULL_PTR;
      /*
       * Copy the destination pointer value to a local pointer
       * variable
       */
      Spi_GaaChannelEBData[LddNoOfBuffers].pDestPtr = NULL_PTR;

      #endif /* (SPI_EB_CONFIGURED == STD_ON) */
    }
    #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
    else
    #endif /* (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO) */
    {
      #if (SPI_IB_CONFIGURED == STD_ON)
      Spi_InternalWriteIB(LddNumChannel, NULL_PTR, SPI_INIT_SID);
      #endif /* (SPI_IB_CONFIGURED == STD_ON) */
    }

    /* MISRA Violation: START Msg(4:0489)-3 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpPBChannelConfig++;
    /* END Msg(4:0489)-3*/
    /* END Msg(2:2824)-17 */
    /* Increment the number of channels */
    LddNumChannel++;
  } /* End of while (SPI_MAX_CHANNEL > LddNumChannel) */
  #if (SPI_LEVEL_DELIVERED == SPI_TWO)
  /*Global variable for asynchronous mode is polling mode */
  Spi_GddAsyncMode = SPI_POLLING_MODE;
  #else
  /* Set default asynchronous transmit mode as interrupt mode */
  Spi_GddAsyncMode = SPI_INTERRUPT_MODE;
  #endif /* (SPI_LEVEL_DELIVERED == SPI_TWO) */

  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || \
                                        (SPI_LEVEL_DELIVERED == SPI_TWO))
  Spi_HWInit();
  #endif

  #if (SPI_CANCEL_API == STD_ON)
  /* Initialize the counter as zero */
  LucVar = SPI_ZERO;
  /* Implements SPI_ESDD_UD_162 */
  /* MISRA Violation: START Msg(4:2877)-12 */
  while ((uint8)SPI_MAX_CANCEL_BYTES > LucVar)
  /* END Msg  (4:2877)-12 */
  {
    /* Initialize the cancel status byte as zero */
    Spi_GaaSeqCancel[LucVar] = SPI_ZERO;
    /* MISRA Violation: START Msg(4:2984)-10 */
    /* Increment number of cancel status bytes */
    LucVar++;
    /* END Msg  (4:2984)-10 */
  }
  #endif /* (SPI_CANCEL_API == STD_ON) */

}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name       : Spi_AsyncInDirAccOrFifoMod
**
** Service ID          : NA
**
** Description         : This service for transmitting data asynchronously in
**                       Direct access and FIFO mode.
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
** Return parameter    : void
**
** Preconditions       : None
**
** Global Variable     : Spi_GpFirstSeq, Spi_GpFirstJob, Spi_GpConfigPtr,
**                       Spi_GpFirstJobList, Spi_GblQueueStatus,
**                       Spi_GddQueueIndex, Spi_GucHwUnitStatus,
**                       Spi_GaaHighPriorityCommRequestAtIdle,
**                       Spi_GaaHighPriorityCommActive,
**                       Spi_GaaHighPriorityCommRequest,
**                       Spi_GaaHighPrioritySequence.
**
** Function invoked    : Spi_ProcessTransmission,
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : None
*******************************************************************************/

/* Implements SPI_ESDD_UD_173 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI055, EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE)Spi_AsyncInDirAccOrFifoMod
                                                     (Spi_SequenceType Sequence)
/* END Msg(2:3227)-16 */
{

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  Spi_HWUnitType LddHWUnit;
  Spi_HWUnitType LddHWUnitNumber;

  Spi_JobType LddJobListIndex;
  #endif
  Spi_JobType LddLowestQueueIndex;
  boolean LblInitiateTx;
  uint8 LucQueueIndex;
  uint8 LucHWMemoryMode;

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the sequence structure */
  LpSeqConfig = Spi_GpFirstSeq + Sequence;
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the job list index of the last job of the sequence */
  LddJobListIndex = LpSeqConfig->ddJobListIndex;
  /* END Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the job list */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0488)-4 */
  /* Get the pointer of the last job linked to this sequence */
  /* QAC Warning: START Msg(2:2814)-20  */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpJobConfig = Spi_GpFirstJob + (LpJobList->ddJobIndex);
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0488)-4 */
  /* END Msg(2:2814)-20  */
  /* QAC Warning: START Msg(2:2814)-20  */
  LddHWUnit = LpJobConfig->ddHWUnitIndex;
  /* END Msg(2:2814)-20  */
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  /* Check if the HW Unit is CSIH */
  if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
  #endif
  {
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20  */
    LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
    /* END Msg(2:2814)-20  */
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

  /* MISRA Violation: START Msg(4:2995)-15 */
  if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode)
  /* END Msg(4:2995)-15 */
  {
    LddLowestQueueIndex = SPI_ZERO;
  }
  /* MISRA Violation: START Msg(4:2992)-16 */
  /* MISRA Violation: START Msg(4:2996)-6 */
  else if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
  /* END Msg(4:2992)-16 */
  /* END Msg(4:2996)-6 */
  {
    LddLowestQueueIndex = Spi_GpConfigPtr->ddDirectAccessQueueSize;
  }
  else
  {
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    LddLowestQueueIndex =
                  Spi_GpConfigPtr->aaHighprioirtyJobQueueIndex[LddHWUnitNumber];
    #else
    LddLowestQueueIndex = SPI_ZERO;
    #endif
  }

  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  if (SPI_FALSE == LpSeqConfig->blIsHighPriority)
  #endif
  {
    LucQueueIndex = LucHWMemoryMode;
  }
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  else
  {
    /* QAC Warning: START Msg(2:3892)- 21 */
    /* MISRA Violation: START Msg(4:2962)-11 */
    LucQueueIndex = (uint8)LddHWUnitNumber + SPI_MAX_CSIH_HW_INDEX + SPI_TWO;
    /* END Msg(4:2962)-11 */
    /* END Msg(2:3892)- 21 */
  }
  #endif

  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif

  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  if (SPI_FALSE == LpSeqConfig->blIsHighPriority)
  #endif
  {
    /* QAC Warning: START Msg(2:3892)-21 */
    /* MISRA Violation: START Msg(4:2962)-11 */
    if ((SPI_QUEUE_EMPTY == (Spi_GblQueueStatus[LucQueueIndex])) ||
         ((SPI_QUEUE_FILLED == (Spi_GblQueueStatus[LucQueueIndex])) &&
            (Spi_GddQueueIndex[LucQueueIndex] == LddLowestQueueIndex)))
    /* END Msg (4:2962)-11 */
    {
      /* END Msg(2:3892)-21 */
      /* Proceed with the communication */
      LblInitiateTx = SPI_TRUE;
    }
    else
    {
      /* Do not Proceed with the communication */
      LblInitiateTx = SPI_FALSE;
    }

  }
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  else
  {

    if (SPI_ZERO == (Spi_GucHwUnitStatus &
                                ((Spi_HWUnitType)(SPI_ONE << LddHWUnitNumber))))
    {
      /* Updating the status of the hardware */
      /* MISRA Violation: START Msg(4:0400)-17 */
      Spi_GucHwUnitStatus = (Spi_GucHwUnitStatus |
                                ((Spi_HWUnitType)(SPI_ONE << LddHWUnitNumber)));
      /* END Msg(4:0400)-17 */

      Spi_GaaHighPriorityCommRequestAtIdle[LddHWUnitNumber] = SPI_TRUE;
      Spi_GaaHighPriorityCommActive[LddHWUnitNumber] = SPI_TRUE;
      Spi_GaaHighPriorityCommRequest[LddHWUnitNumber] = SPI_TRUE;
      /* Proceed with the communication */
      LblInitiateTx = SPI_TRUE;
    }
    else
    {
      if ((SPI_FALSE == Spi_GaaHighPriorityCommRequest[LddHWUnitNumber])
         && (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber]))
      {
        Spi_GaaHighPriorityCommRequest[LddHWUnitNumber] = SPI_TRUE;
        Spi_GaaHighPrioritySequence[LddHWUnitNumber] = Sequence;
        Spi_HWCancel(LddHWUnit, SPI_ASYNCTRANSMIT_SID);
        Spi_GddQueueIndex[LucQueueIndex] = LddLowestQueueIndex;
      }
      else
      {
        /* No action required */
      }
      /* Do not Proceed with the communication */
      LblInitiateTx = SPI_FALSE;
    }
  }
  #endif /* (SPI_HW_PRIORITY_ENABLED == STD_ON) */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts */
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif
  Spi_ProcessTransmission(Sequence, LblInitiateTx, LucQueueIndex,
  LucHWMemoryMode, LddLowestQueueIndex);
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name       : Spi_ProcessChannelInDirAccMod
**
** Service ID          : NA
**
** Description         : This function is to process remaining channels to be
**                       transmitted in Direct access mode.
**
** Sync/Async          : Asynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : void
**
** Preconditions       : Spi_Init should have been invoked.
**
** Global Variable     : Spi_GpFirstChannel, Spi_GpConfigPtr,
**                       Spi_GaaJobQueue, Spi_GddQueueIndex, Spi_GddDmaData
**                       Spi_GpFirstJobList,Spi_GpFirstJob, Spi_GstHWUnitInfo
**                       Spi_GaaChannelEBData, Spi_GstCurrentCommData
**                       Spi_GaaHighPriorityCommActive, Spi_GddAsyncMode
**
** Function invoked    : Spi_AsyncChannelRegSettings, Spi_TxDmaConfig,
**                       Spi_RxDmaConfig, SPI_ENTER_CRITICAL_SECTION,
**                       SPI_EXIT_CRITICAL_SECTION, Spi_GetTxRegValue
**
** Registers Used      : CSIGnTX0W, CSIHnTX0W, EICn and IMRn
*******************************************************************************/
/* Implements SPI_ESDD_UD_081 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON))|| \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0030, EAAR_PN0034_FR_0013, EAAR_PN0034_FR_0061 */
/* Implements EAAR_PN0034_FR_0068 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessChannelInDirAccMod
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  Spi_JobType LddJobIndex;

  Spi_JobType LddJobListIndex;

  P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData;
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentTxChannelList;

  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  /* Declare a local pointer variable to hold Rx data */
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData;
  P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData;

  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  #endif
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  Spi_NumberOfDataType LddBufferIndex;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess;
  /* END Msg (4:0759)-1 */
  P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST) LpDataAccess;
  Spi_NumberOfDataType LddNoOfBuffers;

  Spi_DataType LddData;

  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  Spi_HWUnitType LddHWUnitNumber;
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  /* END Msg(2:2814)-20 */
  if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
  #endif
  {
    LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
  }
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  else
  {
    LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ONE + LddHWUnitNumber]);
  }
  #endif

  LpCurrentTxChannelList = LpCurrentCommData->pCurrentTxChannelList;

  /* Get the pointer to the post-build structure of the channel */
  /* QAC Warning: START Msg(2:2814)-20*/
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentTxChannelList);
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
  /* END Msg(2:2814)-20 */

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
  /* Check if the buffer type is internal buffer */
  if ((SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      || ((SPI_TRUE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
      && (SPI_ONE != LpPBChannelConfig->ucChannelBufferType))
      #endif
      )
  {
    #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20*/
    /* Update the RAM variable for Tx pointer with channel IB index */
    LpNextTxData = Spi_GpConfigPtr->pChannelIBWrite;
    /* END Msg(2:2814)-20  */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpNextTxData = (LpNextTxData + LddBufferIndex);
    /* END Msg(2:2824)-17 */
    /* Update the RAM variable for Rx pointer with channel IB index */
    LpCurrentRxData = Spi_GpConfigPtr->pChannelIBRead;
    /* QAC Warning: START Msg(2:2824)-17 */
    LpCurrentRxData = (LpCurrentRxData + LddBufferIndex);
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */
      /*Start : SPI_UT_006*/
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
     if ((SPI_TRUE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
                       && (SPI_ONE != LpPBChannelConfig->ucChannelBufferType))
    {
      /* End : SPI_UT_006 */
      /* MISRA Violation: START Msg(4:0488)-4 */
      LpCurrentRxData = (LpCurrentRxData + SPI_RX_BUFFER_START);
      /* END Msg (4:0488)-4 */
    }
    else
    {
      /* No action required */
    }
    #endif
    /* Update the RAM variable for number of buffers of the channel */
    LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;
    #endif
  }
  else
  {
    #if (SPI_EB_CONFIGURED == STD_ON)
    /*
     * Update the RAM variable for Tx pointer with channel EB
     * source pointer
     */
    LpNextTxData = Spi_GaaChannelEBData[LddBufferIndex].pSrcPtr;

    /* Update the RAM variable for Rx pointer */
    LpCurrentRxData = Spi_GaaChannelEBData[LddBufferIndex].pDestPtr;

    /* Update the local counter with number of buffers of the channel */
    LddNoOfBuffers = Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
    #endif
  }
  #elif (SPI_INTERNAL_RW_BUFFERS == STD_ON)

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Update the RAM variable for Tx pointer with channel IB index */
  LpNextTxData = Spi_GpConfigPtr->pChannelIBWrite;
  LpNextTxData = (LpNextTxData + LddBufferIndex);
  /* Update the RAM variable for Rx pointer with channel IB index */
  LpCurrentRxData = Spi_GpConfigPtr->pChannelIBRead;
  LpCurrentRxData = (LpCurrentRxData + LddBufferIndex);
  /* END Msg (4:0488)-4 */
  /* END Msg(2:2824)-17 */
  /* END Msg(2:2814)-20 */
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  if ((SPI_TRUE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
                   && (SPI_ONE != LpPBChannelConfig->ucChannelBufferType))
  {
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpCurrentRxData = (LpCurrentRxData + SPI_RX_BUFFER_START);
    /* END Msg (4:0488)-4 */
  }
  else
  {
    /* No action required */
  }
  #endif

  /* Update the RAM variable for number of buffers of the channel */
  LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;

  #else
   /*
   * Update the RAM variable for Tx pointer with channel EB
   * source pointer
   */
  #if (SPI_EB_CONFIGURED == STD_ON)
  LpNextTxData = Spi_GaaChannelEBData[LddBufferIndex].pSrcPtr;

  /* Update the RAM variable for Rx pointer */
  LpCurrentRxData = Spi_GaaChannelEBData[LddBufferIndex].pDestPtr;

  /* Update the local counter with number of buffers of the channel */
  LddNoOfBuffers = Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
  #endif

  #endif
  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

  /* Disable relevant interrupts to protect this critical section */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

  #endif

  /* MISRA Violation: START Msg(4:2962)-11 */
  /* Save the pointer to data to be received */
  LpCurrentCommData->pCurrentRxData = LpCurrentRxData;
  /* Get the data to be transmitted */
  if (NULL_PTR == LpNextTxData)
  /* END Msg (4:2962)-11 */
  {
    /* Get the configured default value */
    LddData = LpPBChannelConfig->ddDefaultData;
  }
  else
  {
    /* Get the value from the source pointer */
    LddData = *LpNextTxData;
  }

  /* Save the pointer to next data to be transmitted */
  LpCurrentCommData->pNextTxData = LpNextTxData;

  /* MISRA Violation: START Msg(4:2962)-11 */
  /* Save and decrement the number of buffers */
  LpCurrentCommData->ddNoOfTxBuffers = LddNoOfBuffers;
  /* END Msg (4:2962)-11 */

  LpCurrentCommData->ddNoOfRxBuffers = LddNoOfBuffers;

  (LpCurrentCommData->ddNoOfTxBuffers)--;
  (LpCurrentCommData->ddNoOfRxBuffers)--;

  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

  /* Enable relevant interrupts */
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

  #endif

  /* Get the index of job list for the current job from the job queue */
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[(LddHWUnitNumber
                                   + SPI_MAX_CSIH_HW_INDEX + SPI_TWO)]];
  #else
  LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
  #endif /* End of #if (SPI_HW_PRIORITY_ENABLED == STD_ON) */

  /* Get the pointer to the respective job list index  */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the index of the job */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)-20 */

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  #if (SPI_CSIG_CONFIGURED == STD_ON)
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the user base address of the HW Unit */
  LpCsigUserBaseAddr = (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the user base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/
  #endif
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* call function for settings */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3416)-24 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  if (((SPI_TRUE == Spi_GblInitiateJobTx) ||
                            (SPI_FALSE == LpJobConfig->blIsChannelPropSame))
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      && (SPI_FALSE == (Spi_GaaHighPriorityCommActive[LddHWUnitNumber]
      ^ Spi_GaaHighPriorityCommRequestAtIdle[LddHWUnitNumber]))
      #endif /* End of #if (SPI_HW_PRIORITY_ENABLED == STD_ON)*/
      )
  /* END Msg(2:2814)-20 */
  /* END Msg(2:3416)-24 */
  /* END Msg(2:3892)- 21 */
  {
    Spi_AsyncChannelRegSettings( LddHWUnit, LucHWMemoryMode);
  }
  else
  {

  }
  #endif

  /* MISRA Violation: START Msg(4:0489)-3 */
  (LpCurrentCommData->pCurrentTxChannelList)++;
  (LpCurrentCommData->pCurrentRxChannelList)++;
  /* END Msg (4:0489)-3 */

  /* Decrement the number of channels yet to be transmitted  */
  (LpCurrentCommData->ddNoOfTxChannels)--;
  (LpCurrentCommData->ddNoOfRxChannels)--;
  /* QAC Warning: START Msg(2:2814)-20 */
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  if (SPI_TRUE != LpJobConfig->blHWUnitDmaMode)
  #endif
  /* END Msg(2:2814)-20 */
  {
  if (SPI_INTERRUPT_MODE == Spi_GddAsyncMode)
  {
    /* Clear the pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                            (SPI_CLR_INT_REQ));

    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif

    RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pTxImrAddress),
                                            (LpHWUnitInfo->usTxImrMask));
    RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pRxImrAddress),
                                            (LpHWUnitInfo->usRxImrMask));
    RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pErrorImrAddress),
                                            (LpHWUnitInfo->usErrorImrMask));
   }
  else
  {
    /* No action required */
  }
  }
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  else
  {
    if (SPI_INTERRUPT_MODE == Spi_GddAsyncMode)
    {
      /* MISRA Violation: START Msg(4:2962)-11 */
      /* If the selected asynchronous mode is DMA mode */
      Spi_GddDmaData = LpPBChannelConfig->ddDefaultData;
      Spi_RxDmaConfig(LpJobConfig, LpCurrentCommData->pCurrentRxData,
                                   LddNoOfBuffers);
      /* END Msg (4:2962)-11 */
      Spi_TxDmaConfig(LpJobConfig, LpNextTxData, LddNoOfBuffers);
    }
    else
    {
      /* No action required */
    }
  }
  #endif
  /* Take a local union variable to construct the value for TX0W register */

  LpDataAccess = &LunDataAccess;

  /* QAC Warning: START Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:2982)-2 */
  /* Take a local union variable to construct the value for TX0W register */
  LpDataAccess->ulRegData = SPI_ZERO;
  /* END Msg(4:2982)-2 */
  /* END Msg(2:2814)-20 */
  #if (SPI_8BIT_DATA_WIDTH == STD_ON)
  /*
   * Data width is maximum 8-bit. Hence, load Tx data portion of the local
   * variable with the 8-bit data to be transmitted
   */
  LpDataAccess->usRegData5[SPI_ZERO] = LddData;
  #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
  /* Data width is maximum 16-bit. Hence, load Tx data portion of the local
   * variable with the 16-bit data to be transmitted
   */
  LpDataAccess->Tst_ByteAccess.usRegData1 = LddData;
  #else

  Spi_GetTxRegValue(LpPBChannelConfig, LpDataAccess,
                                                    LpCurrentCommData, LddData);
  #endif

  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG <= LddHWUnit)
  #endif
  {

    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Set chip select in the local union variable */
    LpDataAccess->Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
    /* END Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:2962)-11 */
    /* Check if the buffer is last buffer of the channel */
    if ((SPI_ONE == LddNoOfBuffers) &&
        ((SPI_ZERO == (LpCurrentCommData->ddNoOfTxChannels))
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
          && (SPI_FALSE == Spi_GaaHighPriorityCommRequest[LddHWUnitNumber])
      #endif
      #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
          && (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
      #endif
      ))
      {
        /* MISRA Violation: START Msg(4:2984)-10 */
        /* Since buffer is last buffer of the job set EOJ */
        LpDataAccess->Tst_ByteAccess.ucRegData3 =
                    (LpDataAccess->Tst_ByteAccess.ucRegData3 | SPI_SET_EOJ);
        /* END Msg (4:2984)-10 */
      }
      else
      {
        /* No action required */
      }

    #endif /* End of #if (SPI_CSIH_CONFIGURED == STD_ON) */
  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  #endif
  {
    /* No action required */
  }

  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  if ((SPI_FALSE == LpJobConfig->blHWUnitDmaMode) || (SPI_ONE < LddNoOfBuffers))
  #endif
  {
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Load the value of the local union variable to TX0W register */

      SPI_CSIGH_REG_WRITE(LpCsigUserBaseAddr->ulCSIGTX0W,
                                                       LpDataAccess->ulRegData)

      /* END Msg(2:2814)-20 */
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Load the value of the local union variable to TX0W register */

      SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                          LpDataAccess->ulRegData)


      /* END Msg(2:2814)-20 */
      #endif
    }
  }
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  else
  #endif
  {
    /* No action required */
  }/* End of (SPI_DMA_MODE_ENABLE == STD_ON) */
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name       : Spi_AsyncChannelRegSettings
**
** Service ID          : NA
**
** Description         : This service for setting the registers dynamically
**                       during Asynchronous transmission.
**
** Sync/Async          : Asynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : void
**
** Preconditions       : None
**
** Global Variable     : Spi_GpConfigPtr, Spi_GaaHighPriorityCommActive,
**                       Spi_GpFirstSeq, Spi_GaaJobResult, Spi_GddQueueIndex,
**                       Spi_GstCurrentCommData, Spi_GpFirstChannel,
**                       Spi_GaaJobQueue, Spi_GpFirstJobList, Spi_GaaSeqQueue,
**                       Spi_GblInitiateJobTx, Spi_GstHWUnitInfo, Spi_GpFirstJob
**
** Function invoked    : Spi_CsigStaticInit, Spi_CsihStaticInit,
**                       Spi_HWActivateCS, Spi_CfgRegSettings
**
** Registers Used      : CSIGnCTL0, CSIHnCTL0, CSIHnSTCR0, CSIGnSTCR0,
**                       CSIHnSTR0, CSIGnSTR0.
*******************************************************************************/
/* Implements SPI_ESDD_UD_078 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
     (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI157 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(0:2755)-25 */
 FUNC(void, SPI_PRIVATE_CODE) Spi_AsyncChannelRegSettings
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
/* END Msg(0:2755)-25 */
 {

  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  uint8 LucCxCtl0;
  #if ((SPI_DIRECT_ACCESS_MODE == STD_ON)&& \
     ((SPI_HWUNIT_ASYNCHRONOUS == STD_ON) || SPI_HW_PRIORITY_ENABLED == STD_ON))
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentTxChannelList;
  P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData;
  #endif

  #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
  ((SPI_HWUNIT_ASYNCHRONOUS == STD_ON) || SPI_HW_PRIORITY_ENABLED == STD_ON)) \
                                 || (SPI_FIFO_MODE == STD_ON))
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                              LpPBChannelConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  #endif
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  Spi_SequenceType LddSeqIndex;
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  Spi_JobType LddNoOfJobs;
  Spi_HWUnitType LddHWUnitNumber;
  #endif
  Spi_JobType LddJobIndex;

  Spi_JobType LddJobListIndex;

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  /* MISRA Violation: START Msg(4:2982)-2 */
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  /* END Msg(2:2814)-20 */
  /* END Msg(4:2982)-2 */
  #endif

  #if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
     ((SPI_HWUNIT_ASYNCHRONOUS == STD_ON) || SPI_HW_PRIORITY_ENABLED == STD_ON))
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  if (SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode )
  #endif
  {
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
    #endif
    {
      /* MISRA Violation: START Msg(4:2982)-2 */
      LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
      LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
      /* END Msg(4:2982)-2 */
    }
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    else
    {
      LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ONE + LddHWUnitNumber]);
      /* MISRA Violation: START Msg(4:2982)-2 */
      LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[(LddHWUnitNumber
                                         + SPI_MAX_CSIH_HW_INDEX + SPI_TWO)]];
      /* END Msg(4:2982)-2 */
    }
    #endif

    LpCurrentTxChannelList = LpCurrentCommData->pCurrentTxChannelList;

    /* Get the pointer to the post-build structure of the channel */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentTxChannelList);
    /* END Msg(2:2824)-17 */
    /* END Msg (2:2814)-20 */
    /* END Msg (4:0488)-4 */
  }
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  else
  {

  }
  #endif
  #endif

  #if ((SPI_FIFO_MODE == STD_ON) || \
               (SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  if (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)
  {
    #if (SPI_FIFO_MODE == STD_ON)
    LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
    #endif
  }
  else
  {
    #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];
    /* QAC Warning: START Msg(2:2824)-17 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
    /* END Msg (4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Get the job list index of the last job of the sequence */
    LddJobListIndex = LpSeqConfig->ddJobListIndex;
    /* END Msg(2:2814)-20 */
    /* Get the index of the job list for the first job of the sequence */
    LddJobListIndex = LddJobListIndex + ((LpSeqConfig->ddNoOfJobs) - SPI_ONE);
    #endif
  }
  #endif
  /* Get the pointer to the respective job list index  */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* MISRA Violation: START Msg(4:2962)-11 */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:2962)-11 */
  /* END Msg (4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the index of the job */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)-20 */
  #if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
   ((SPI_HWUNIT_ASYNCHRONOUS == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON))\
                                        || (SPI_FIFO_MODE == STD_ON))
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */
  #endif
    /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* Get the main user base address */
  LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;
  /* MISRA Violation: START Msg(4:0402)-13 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  /* Implements SPI_ESDD_UD_217 */
  /* Reset the PWR bit since other registers need to be written */
  /* QAC Warning: START Msg(2:3892)- 21 */
  LucCxCtl0 = (LpMainUserBaseAddr->ucMainCTL0 & SPI_RESET_PWR);
  SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, LucCxCtl0)
  SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
   LucCxCtl0, SPI_CTLREG_8_BIT_MASK, SPI_ASYNCTRANSMIT_SID)

  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  /* END Msg(2:3892)- 21 */
  /* END Msg(4:0402)-13 */
  /* QAC Warning: START Msg(2:3416)-24 */
  if (SPI_TRUE == Spi_GblInitiateJobTx)
  /* END Msg(2:3416)-24 */
  {
    Spi_GblInitiateJobTx = SPI_FALSE;
    Spi_GaaJobResult[LddJobIndex] = SPI_JOB_PENDING;
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      #if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON))

      /* Perform the initial settings of all registers */
      /* MISRA Violation: START Msg(4:2962)-11 */
      Spi_CsigStaticInit(LpHWUnitInfo, LpJobConfig, LpPBChannelConfig,
                                   LpMainUserBaseAddr, SPI_ASYNCTRANSMIT_SID);
      /* END Msg(4:2962)-11 */
      #endif /* End of #if (SPI_CSIG_CONFIGURED == STD_ON) */
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)

      LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
      #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
      if ((SPI_DUAL_BUFFER_MODE_CONFIGURED == LucHWMemoryMode) ||
                             (SPI_TX_ONLY_MODE_CONFIGURED == LucHWMemoryMode))
      {
        /* Get the number of jobs */
        LddNoOfJobs = LpSeqConfig->ddNoOfJobs;
      }
      else
      #endif
      /*((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))*/
      {
        LddNoOfJobs = SPI_ONE;
      }
      /* Perform the initial settings of all registers */
      Spi_CsihStaticInit(LpHWUnitInfo, LpJobList, LddNoOfJobs,
                                       LddHWUnitNumber, SPI_ASYNCTRANSMIT_SID);
      #endif
     }
  }
  else
  {
    #if (SPI_FIFO_MODE == STD_ON)
    if (SPI_DIRECT_ACCESS_MODE_CONFIGURED != LucHWMemoryMode)
    {
      /* QAC Warning: START Msg(2:2824)-17 */
      /* QAC Warning: START Msg(2:2814)-20 */
      /* MISRA Violation: START Msg(4:0488)-4 */
      /* Get the pointer to the post-build structure of the channel */
      LpPBChannelConfig = Spi_GpFirstChannel + (*LpJobConfig->pChannelList);
      /* END Msg (4:0488)-4 */
      /* END Msg(2:2814)-20 */
      /* END Msg(2:2824)-17 */
    }
    else
    {
      /* No action required */
    }
    #endif
    #if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
   ((SPI_HWUNIT_ASYNCHRONOUS == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON))\
                                        || (SPI_FIFO_MODE == STD_ON))
    /* MISRA Violation: START Msg(4:2962)-11 */
    /* Perform the configuration register settings */
    Spi_CfgRegSettings(LpPBChannelConfig, LpJobConfig, LddHWUnit);
    /* END Msg(4:2962)-11 */
    #endif

  }
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) \
                                                 ||(SPI_FIFO_MODE == STD_ON))

  if (SPI_ZERO < LucHWMemoryMode)
  {
     /* QAC Warning: START Msg(2:3892)- 21 */
     /* QAC Warning: START Msg(2:2814)-20 */

     /* Clear the status register */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,SPI_CSIH_CLR_STS_FLAGS)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ulMainSTR0,
                (uint32)SPI_ZERO,SPI_CSIH_CLR_STS_FLAGS,SPI_ASYNCTRANSMIT_SID)


    /* END Msg(2:2814)-20 */
    /* END Msg(2:3892)- 21 */
    /* Load Main CTL0 register, without setting PWR bit */
    /* QAC Warning: START Msg(2:3892)- 21 */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_MEMORY_ACCESS)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
      SPI_SET_MEMORY_ACCESS,SPI_CTLREG_8_BIT_MASK,SPI_ASYNCTRANSMIT_SID)
    /* END Msg(2:3892)- 21 */
  }
  else
  #endif
  {
   /* Activate CS for CSIG or CSIH if SPI_GPIO_CS is configured. */
   #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
   if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
   #endif
   {
     #if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                           (SPI_HWUNIT_ASYNCHRONOUS == STD_ON))
     #if (SPI_CSIG_CONFIGURED == STD_ON)
     /* Activate the chip select */
     /* QAC Warning: START Msg(2:2814)-20 */
     Spi_HWActivateCS(LpJobConfig, (LpJobConfig->ucClk2CsLoopCnt));
     /* END Msg(2:2814)-20 */
     #endif
     #endif
   }
   #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
   else
   #endif
   {

   }
    /* Load Main CTL0 register, setting PWR bit at the same time */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->ucMainCTL0, SPI_SET_DIRECT_ACCESS)
    /* QAC Warning: START Msg(2:3892)- 21 */
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ucMainCTL0,
      SPI_SET_DIRECT_ACCESS,SPI_CTLREG_8_BIT_MASK,SPI_ASYNCTRANSMIT_SID)
    /* END Msg(2:3892)- 21 */
  }
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_ProcessChannelInFifoMod
**
** Service ID         : Not Applicable
**
** Description        : This function is to process remaining channels
**                      to be transmitted in FIFO mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstChannel,
**                      Spi_GpFirstJobList, Spi_GaaChannelEBData,
**                      Spi_GddAsyncMode, Spi_GpFirstJob, Spi_GddDmaData,
**                      Spi_GaaJobQueue, Spi_GpConfigPtr
**
** Function Invoked   : Spi_AsyncChannelRegSettings, Spi_TxDmaConfig,
**                      Spi_FifoWriteData, SPI_ENTER_CRITICAL_SECTION,
**                      SPI_EXIT_CRITICAL_SECTION.
**
** Registers Used     : EICn, IMRn
*******************************************************************************/
/* Implements SPI_ESDD_UD_083 */
#if (SPI_FIFO_MODE == STD_ON)

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessChannelInFifoMod
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
{
/* END Msg(2:3227)-16 */
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  Spi_JobType LddJobIndex;

  Spi_JobType LddJobListIndex;

  P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData;
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentTxChannelList;
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;

  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;

  Spi_NumberOfDataType LddBufferIndex;

  Spi_NumberOfDataType LddNoOfBuffers;

  Spi_ChannelType LddNoOfChannels;

   /* Get the pointer to the respective job list index  */
  LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* MISRA Violation: START Msg(4:2962)-11 */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg (4:2962)-11 */
  /* END Msg (4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Get the index of the job */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg (4:0488)-4 */
  /* END Msg(2:2824)-17 */

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* QAC Warning: START Msg(2:2814)-20 */
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* QAC Warning: START Msg(2:3416)-24 */
  if ((SPI_TRUE == Spi_GblInitiateJobTx) ||
                            (SPI_FALSE == LpJobConfig->blIsChannelPropSame))
  /* END Msg(2:3416)-24 */
  {
    /* END Msg(2:2814)-20 */
    Spi_AsyncChannelRegSettings( LddHWUnit, LucHWMemoryMode);
  }
  else
  {
    /* No Action required */
  }
  #endif

  if (SPI_INTERRUPT_MODE == Spi_GddAsyncMode)
  {
    /* Clear the pending interrupt */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                            (SPI_CLR_INT_REQ));

    /* Register dummy read-write  */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                            (SPI_CLR_INT_REQ));
    /* SYNCP execution */
    EXECUTE_SYNCP();
    #endif

    /* Enable transmit interrupt */
    RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pTxImrAddress),
                                            (LpHWUnitInfo->usTxImrMask));
    /* Enable Error interrupt */
    RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pErrorImrAddress),
                                            (LpHWUnitInfo->usErrorImrMask));
  }
  else
  {
    /* No action required */
  }
  /* QAC Warning: START Msg(2:3892)- 21 */
  if (SPI_FIFO_BUFFER_UNINIT == Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX])
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    Spi_GstFifoCurrentCommData.pCurrentTxChannelList =
                                                    LpJobConfig->pChannelList;
    Spi_GstFifoCurrentCommData.ddNoOfTxChannels = LpJobConfig->ddNoOfChannels;
    /* END Msg(2:2814)-20 */
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    /* Save JobIndex to refer to the ongoing job */
    Spi_GstFifoCurrentCommData.ddJobIndex = LddJobIndex;
    #endif
  }
  /* END Msg(2:3892)- 21 */
  else
  {
    /* No Action Required */
  }
  Spi_GstFifoCurrentCommData.usBufferCount = SPI_ZERO;
  do
  {
    LpCurrentTxChannelList = Spi_GstFifoCurrentCommData.pCurrentTxChannelList;
    LddNoOfChannels = Spi_GstFifoCurrentCommData.ddNoOfTxChannels;

    /* QAC Warning: START Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the post-build structure of the channel */
    LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentTxChannelList);
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */
    /* QAC Warning: START Msg(2:3892)- 21 */
    if (SPI_FIFO_BUFFER_FULL != Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX])
    {
      /* END Msg(2:3892)- 21 */
      LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
      #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
      /* Check if the buffer type is internal buffer */
      if (SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
      #endif
      {
        #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* Update the RAM variable for Tx pointer with channel IB index */
        LpNextTxData = (Spi_GpConfigPtr->pChannelIBWrite) + LddBufferIndex;
        /* END Msg (4:0488)-4 */
        /* END Msg (2:2814)-20 */

        /* Update the RAM variable for number of buffers of the channel */
        LddNoOfBuffers = LpPBChannelConfig->ddNoOfBuffers;
        #endif
      }

      #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
      else
      #endif
      {
        #if (SPI_EB_CONFIGURED == STD_ON)
        /*
         * Update the RAM variable for Tx pointer with channel EB source
         * pointer
         */
        LpNextTxData = Spi_GaaChannelEBData[LddBufferIndex].pSrcPtr;

        /* Update the local counter with number of buffers of the channel */
        LddNoOfBuffers = Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
        #endif
      }
    }
    else
    {
      /* Load the data from RAM */
      LpNextTxData = Spi_GstFifoCurrentCommData.pNextTxData;
      LddNoOfBuffers = Spi_GstFifoCurrentCommData.ddNoOfTxBuffers;
    }
    /* If the selected asynchronous mode is DMA mode */
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    if ((SPI_INTERRUPT_MODE == Spi_GddAsyncMode) &&
                  (SPI_INVALID_DMAUNIT == LpJobConfig->ucTxDmaDeviceIndex))
    #endif
    {
      /* Critical section protection is added as per #25251 */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

      /* Disable relevant interrupts to protect this critical section */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

      #endif
      Spi_FifoWriteData(LpHWUnitInfo, LpJobList, LddNoOfChannels,
                                                 LddNoOfBuffers, LpNextTxData);
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

      /* Enable relevant interrupts */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

      #endif
    }
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    else if (SPI_TRUE == LpJobConfig->blHWUnitDmaMode)
    {
      /* QAC Warning: START Msg(2:3892)- 21 */
      /* Check the number of buffers to be transmitted */
      if (SPI_FIFO_SIZE < LddNoOfBuffers)
      {
        /* Set the flag as the number of buffers are more than Fifo size */
        Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] = SPI_FIFO_BUFFER_FULL;
      /* END Msg(2:3892)- 21 */
        /* Save the current status in RAM */
        /* QAC Warning: START Msg(2:3892)- 21 */
        /* QAC Warning: START Msg(2:2824)-17 */
        /* MISRA Violation: START Msg(4:0488)-4 */
        Spi_GstFifoCurrentCommData.pNextTxData = (LpNextTxData + SPI_FIFO_SIZE);
        Spi_GstFifoCurrentCommData.ddNoOfTxBuffers =
                                               (LddNoOfBuffers - SPI_FIFO_SIZE);
        /* Update the number of buffers to Max size */
        LddNoOfBuffers = SPI_FIFO_SIZE;
        /* END Msg(2:3892)- 21 */
        /* END Msg(2:2824)-17 */
        /* END Msg(4:0488)-4 */
      }
      else
      {
        /* Set the flag to indicate Buffer is Empty */
        /* QAC Warning: START Msg(2:3892)- 21 */
        Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] = SPI_FIFO_BUFFER_EMPTY;
        /* END Msg(2:3892)- 21 */
      }
      Spi_GddDmaData = LpPBChannelConfig->ddDefaultData;

      Spi_GstFifoCurrentCommData.ucDmaDeviceIndex =
                                              LpJobConfig->ucTxDmaDeviceIndex;
      /* MISRA Violation: START Msg(4:2962)-11 */
      Spi_TxDmaConfig(LpJobConfig, LpNextTxData, LddNoOfBuffers);
      /* END Msg (4:2962)-11 */
    }
    else
    {
      /* No actions required */
    }
    #endif
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    if (SPI_TRUE != LpJobConfig->blHWUnitDmaMode)
    #endif
    {
      /* QAC Warning: START Msg(2:3892)-21 */
      if ((SPI_FIFO_BUFFER_EMPTY ==
                    (uint8) Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX])
                   && (SPI_ZERO < Spi_GstFifoCurrentCommData.ddNoOfTxChannels))
      /* END Msg (2:3892)-21 */
      {
        /* MISRA Violation: START Msg(4:0489)-3 */
        /* QAC Warning: START Msg(2:2824)-17 */
        /* Increment the pointer to the next channel */
        Spi_GstFifoCurrentCommData.pCurrentTxChannelList++;
        /* END Msg(2:2824)-17 */
        /* END Msg (4:0489)-3 */

        /* Decrement the counter for number of channels */
        Spi_GstFifoCurrentCommData.ddNoOfTxChannels--;
        /* QAC Warning: START Msg(2:3892)-21 */

        if (SPI_FIFO_SIZE <= Spi_GstFifoCurrentCommData.usBufferCount)
        /* END Msg(2:3892)- 21 */
        {
          /* Break the loop */
          LddNoOfChannels = SPI_ZERO;
          /* Reset the buffer count */
          Spi_GstFifoCurrentCommData.usBufferCount = SPI_ZERO;
        }

        else
        {
          /* Get the remaining number of channels */
          LddNoOfChannels = Spi_GstFifoCurrentCommData.ddNoOfTxChannels;
        }
      }
      else
      {
        /* Break the loop */
        LddNoOfChannels = SPI_ZERO;
        /* Reset the buffer count */
        Spi_GstFifoCurrentCommData.usBufferCount = SPI_ZERO;
      }
    }
    #if (SPI_DMA_MODE_ENABLE == STD_ON)
    else
    {
       /* Break the loop */
      LddNoOfChannels = SPI_ZERO;
    }
    #endif
  }while (SPI_ZERO < LddNoOfChannels);
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_ProcessChannelInDualOrTxMod
**
** Service ID         : Not Applicable
**
** Description        : This function is to process remaining channels
**                      to be transmitted in Dual buffer mode or TX Only mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstChannel,
**                      Spi_GpFirstJobList, Spi_GpConfigPtr, Spi_GpFirstSeq,
**                      Spi_GddAsyncMode, Spi_GpFirstJob, Spi_GddQueueIndex,
**                      Spi_GaaSeqQueue
**
** Function Invoked   : Spi_AsyncChannelRegSettings, Spi_RxDmaConfig
**
** Registers Used     : CSIHnMCTL2, EICn, IMRn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_082 */
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061, EAAR_PN0034_FR_0068 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessChannelInDualOrTxMod
(Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  #if (SPI_DUAL_BUFFER_MODE == STD_ON)
  P2VAR(Spi_DualBufferCurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
                                              LpDualBufferCurrentCommData;
  #endif
  #if (SPI_TX_ONLY_MODE == STD_ON)
  /* Declare a local pointer variable to hold Tx only communication data */
  P2VAR(Spi_TxOnlyCurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
                                               LpTxOnlyCurrentCommData;
  #endif

  Spi_HWUnitType LddHWUnitNumber;
  Spi_NumberOfDataType LddBufferIndex;
  Spi_SequenceType LddSeqIndex;
  Spi_JobType LddJobIndex;
  Spi_JobType LddJobListIndex;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg (4:0759)-1 */

  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];

  LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];
  /* QAC Warning: START Msg(2:2824)-17 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
  /* END Msg (4:0488)-4 */
  /* Get the job list index of the last job of the sequence */
  LddJobListIndex = LpSeqConfig->ddJobListIndex;

  /* Get the index of the job list for the first job of the sequence */
  LddJobListIndex = LddJobListIndex + ((LpSeqConfig->ddNoOfJobs) - SPI_ONE);
  /* Get the pointer to the respective job list index  */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* MISRA Violation: START Msg(4:2962)-11 */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg (4:2962)-11 */
  /* END Msg (4:0488)-4 */

  /* Get the index of the job */
  LddJobIndex = LpJobList->ddJobIndex;

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg (4:0488)-4 */

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the user base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* QAC Warning: START Msg(2:3416)-24 */
  if (((SPI_TRUE == Spi_GblInitiateJobTx) ||
                            (SPI_FALSE == LpJobConfig->blIsChannelPropSame))
  /* END Msg(2:3416)-24 */
      /* QAC Warning: START Msg(2:3892)- 21 */
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      && (SPI_FALSE == (Spi_GaaHighPriorityCommActive[LddHWUnitNumber]
      ^ Spi_GaaHighPriorityCommRequestAtIdle[LddHWUnitNumber]))
      #endif /* End of #if (SPI_HW_PRIORITY_ENABLED == STD_ON)*/
      )
      /* END Msg(2:3892)- 21 */
  {
    Spi_AsyncChannelRegSettings( LddHWUnit, LucHWMemoryMode);
  }
  else
  {
    /* No action required */
  }
  #endif
  /* MISRA Violation: START Msg(4:0488)-4 */
  LpPBChannelConfig = Spi_GpFirstChannel + (*(LpJobConfig->pChannelList));
  /* END Msg (4:0488)-4 */
  LddBufferIndex = LpPBChannelConfig->ddBufferIndex;

  /*
   * Take a local union variable to construct the value for MCTL2
   * register and load the local union variable with SOP value
   */
  LunDataAccess1.Tst_ByteAccess.usRegData1 = LddBufferIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg(2:2814)-20 */
  if (SPI_DUAL_BUFFER_MODE_CONFIGURED == LucHWMemoryMode)
  {
    #if (SPI_DUAL_BUFFER_MODE == STD_ON)
    LpDualBufferCurrentCommData = &Spi_GstDualBufferCurrentCommData
                 [Spi_GpConfigPtr->aaHWUnitCurrentCommDataIndex[LddHWUnit]];

    LunDataAccess1.Tst_ByteAccess.ucRegData2 =
         (uint8)(*(LpDualBufferCurrentCommData->ddNoOfNxtNotifyBuffersIdx));

    if (SPI_INTERRUPT_MODE == Spi_GddAsyncMode)
    {
      /* Clear the pending interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      /* Register dummy read-write  */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                                               (SPI_CLR_INT_REQ));
      /* SYNCP execution */
      EXECUTE_SYNCP();
      #endif
      RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pTxImrAddress),
                                               (LpHWUnitInfo->usTxImrMask));
      RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pErrorImrAddress),
                                              (LpHWUnitInfo->usErrorImrMask));
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (SPI_DUAL_BUFFER_MODE == STD_ON) */
  }
  else
  {
    #if (SPI_TX_ONLY_MODE == STD_ON)
    LpTxOnlyCurrentCommData = &Spi_GstTxOnlyCurrentCommData
                     [Spi_GpConfigPtr->aaHWUnitCurrentCommDataIndex[LddHWUnit]];

    LunDataAccess1.Tst_ByteAccess.ucRegData2 =
                          (uint8)(LpTxOnlyCurrentCommData->ddNoOfBuffers);

    if (SPI_INTERRUPT_MODE == Spi_GddAsyncMode)
    {
      #if (SPI_DMA_MODE_ENABLE == STD_ON)
      if (SPI_TRUE == LpJobConfig->blHWUnitDmaMode)
      {
        Spi_RxDmaConfig(LpJobConfig, LpTxOnlyCurrentCommData->pCurrentRxData,
                                     LpTxOnlyCurrentCommData->ddNoOfBuffers);
      }
      else
      {
        /* Clear the pending interrupt */
        RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                                (SPI_CLR_INT_REQ));
        RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                                (SPI_CLR_INT_REQ));

        /* Register dummy read-write  */
        #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
        RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                                (SPI_CLR_INT_REQ));
        /* SYNCP execution */
        EXECUTE_SYNCP();
        #endif
        RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pRxImrAddress),
                                                (LpHWUnitInfo->usRxImrMask));
        RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pErrorImrAddress),
                                                (LpHWUnitInfo->usErrorImrMask));
      }
      #else
      /* Clear the pending interrupt */
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                               (SPI_CLR_INT_REQ));

      /* Register dummy read-write  */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
      RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pErrorIntCntlAddress),
                                               (SPI_CLR_INT_REQ));
      /* SYNCP execution */
      EXECUTE_SYNCP();
      #endif
      RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pRxImrAddress),
                                              (LpHWUnitInfo->usRxImrMask));
      RH850_SV_MODE_IMR_AND(16, (LpHWUnitInfo->pErrorImrAddress),
                                              (LpHWUnitInfo->usErrorImrMask));
      #endif /* End of #if (SPI_DMA_MODE_ENABLE == STD_ON) */
    }
    else
    {
      /* No action required */
    }
    #endif /* End of #if (SPI_TX_ONLY_MODE == STD_ON) */
  }


  LunDataAccess1.Tst_ByteAccess.ucRegData3 = SPI_SET_BTST;
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Load the MCTL2 register to start the communication */
  SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHMCTL2, LunDataAccess1.ulRegData)

  /* END Msg(2:2814)-20 */

}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_FifoWriteData
**
** Service ID         : Not Applicable
**
** Description        : This function is to write the data in to FIFO buffer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                      LpHWUnitInfo,
**                      P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST)
**                      LpJobList, Spi_ChannelType LddNoOfChannels,
**                      Spi_NumberOfDataType LddNoOfBuffers,
**                      P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA)
**                      LpNextTxData.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstJob, Spi_GpFirstChannel,
**                      Spi_GstFifoCurrentCommData, Spi_GucHWFifoBufferSts
**
** Function Invoked   : None.
**
** Registers Used     : CSIHnTX0W
*******************************************************************************/
/* Implements SPI_ESDD_UD_080 */
#if (SPI_FIFO_MODE == STD_ON)
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE) Spi_FifoWriteData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList,
  Spi_ChannelType LddNoOfChannels, Spi_NumberOfDataType LddNoOfBuffers,
  P2CONST(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpNextTxData)
/* END Msg (2:3227)-16 */
{

  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentTxChannelList;
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                             LpPBChannelConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg (4:0759)-1 */
  Spi_JobType LddJobIndex;
  #if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))

  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess2;
  /* END Msg (4:0759)-1 */
  uint32 LulShiftData;
  #endif

  Spi_DataType LddData;
  /* QAC Warning: START Msg(2:2814)- 20 */
   /* Get the index of the job */
  LddJobIndex = LpJobList->ddJobIndex;
  /* END Msg(2:2814)- 20 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* QAC Warning: START Msg(2:2814)- 20 */
  /* Get the pointer to the job structure */
  LpJobConfig = Spi_GpFirstJob + LddJobIndex;
  /* END Msg(2:2814)- 20 */
  /* END Msg (2:2824)-17*/
  /* END Msg (4:0488)-4 */

  /* MISRA Violation: START Msg(4:0316)-9 */
  /* QAC Warning: START Msg(2:2814)- 20 */
  /* Get the user base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(2:2814)- 20 */
  /* END Msg (4:0316)-9*/
  LpCurrentTxChannelList = Spi_GstFifoCurrentCommData.pCurrentTxChannelList;
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2814)- 20 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the post-build structure of the channel */
  LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentTxChannelList);
  /* END Msg(2:2824)-17 */
  /* END Msg(2:2814)- 20 */
  /* END Msg (4:0488)-4 */
  do
  {
    /* Get the data to be transmitted */
    if (NULL_PTR == LpNextTxData)
    {
      /* QAC Warning: START Msg(2:2814)- 20 */
      /* Get the pointer to the configured default value */
      LddData = LpPBChannelConfig->ddDefaultData;
      /* END Msg(2:2814)- 20 */
    }
    else
    {
      /* Get the value from the source pointer */
      LddData = *LpNextTxData;
      /* MISRA Violation: START Msg(4:0489)-3 */
      LpNextTxData++;
      /* END Msg (4:0489)-3 */
    }

    /*
     * Take a local union variable to construct the value for TX0W
     * register
     */
    LunDataAccess1.ulRegData = SPI_ZERO;
    /* QAC Warning: START Msg(2:2814)- 20 */
    /* Set chip select in the local union variable */
    LunDataAccess1.Tst_ByteAccess.ucRegData2 = LpJobConfig->ucChipSelect;
    /* END Msg(2:2814)- 20 */
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, load Tx data portion of
     * the local variable with the 8-bit data to be transmitted
     */
    LunDataAccess1.Tst_ByteAccess.usRegData1 = (uint16)LddData;
    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 16-bit. Hence, load Tx data portion of
     * the local variable with the 16-bit data to be transmitted
     */
    LunDataAccess1.Tst_ByteAccess.usRegData1 = LddData;
    #else
    if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
                    (SPI_TRUE != LpPBChannelConfig->blDirection) &&
                    (SPI_SIXTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                    (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
    {
      LulShiftData = (uint32)LddData;
      LulShiftData = (LulShiftData << (SPI_SIXTEEN -
                                    (LpPBChannelConfig->ucDLSSetting)));
      LunDataAccess2.ulRegData = LulShiftData;
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
      LunDataAccess2.usRegData5[SPI_ZERO] >> (SPI_SIXTEEN -
                                    (LpPBChannelConfig->ucDLSSetting));
      LunDataAccess2.usRegData5[SPI_ZERO] =
                                     LunDataAccess1.Tst_ByteAccess.usRegData1;

    }
    else
    {
      /*
       * Data width is maximum 32-bit. Tx data needs to be split to
       * LS Byte and MS Byte. Hence, load the Tx data to local union
       * variable
      */
      LunDataAccess2.ulRegData = LddData;
    }
    /*
     * Since data width is maximum 32-bit, check if the the data
     * of requested channel is more than 16 bits
     */
    if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
    {
      /*
       * Data width is maximum 16-bit. Hence, load LSB portion of the
       * width local variable with the 16-bit data to be transmitted
       */
      LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
    }
    else
    {
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /* Load Tx data portion of the local variable with LSB first */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
      }
      else
      {
        /* Load Tx data portion of the local variable with MSB first */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ONE];
      }
      /* MISRA Violation: START Msg(4:2984)-10 */
      /* Set the EDL bit in the local union variable */
      LunDataAccess1.Tst_ByteAccess.ucRegData3 =
                (LunDataAccess1.Tst_ByteAccess.ucRegData3 | SPI_SET_EDL);
      /* END Msg(4:2984)-10 */
      /* QAC Warning: START Msg(2:2814)- 20 */
      /* Load the value of the local union variable to TX0W register */

      SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                          LunDataAccess1.ulRegData)


      /* END Msg(2:2814)- 20 */
      /* MISRA Violation: START Msg(4:2984)-10 */
      /* Reset the EDL bit in the local union variable */
      LunDataAccess1.Tst_ByteAccess.ucRegData3 =
              (LunDataAccess1.Tst_ByteAccess.ucRegData3 & SPI_RESET_EDL);
      /* END Msg(4:2984)-10 */

      /*
       * Check the configured data direction again to load other part
       * of data
       */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /* Load Tx data portion of the local variable with MSB */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                           LunDataAccess2.usRegData5[SPI_ONE];
      }
      else
      {
        /* Load Tx data portion of the local variable with LSB */
        LunDataAccess1.Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
      }
    } /* End of !if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */
    #endif /* End of (SPI_8BIT_DATA_WIDTH == STD_ON) */

    /* MISRA Violation: START Msg(4:2962)-11 */
    /* Check if the buffer is last buffer of the channel */
    if ((SPI_ONE == LddNoOfBuffers) && (SPI_ONE == LddNoOfChannels))
    /* END Msg (4:2962)-11 */
    {
      if (SPI_TRUE == LpJobList->blIsLastJob)
      {
        /* MISRA Violation: START Msg(4:2984)-10 */
        /* Since buffer is the last buffer of sequence, set both CIRE and
         * EOJ
         */
        LunDataAccess1.Tst_ByteAccess.ucRegData3 =
              (LunDataAccess1.Tst_ByteAccess.ucRegData3 | SPI_SET_CIREEOJ);
        /* END Msg(4:2984)-10 */
      }
      else
      {
        /* MISRA Violation: START Msg(4:2984)-10 */
        /*
         * Since buffer is last buffer of the job and not last buffer
         * of the sequence, set only EOJ
         */
        LunDataAccess1.Tst_ByteAccess.ucRegData3 =
            (LunDataAccess1.Tst_ByteAccess.ucRegData3 | SPI_SET_EOJ);
        /* END Msg(4:2984)-10 */
      }
    }
    else
    {
      /* No action required */
    }
    /*
      * End of if ((SPI_ONE == LddNoOfBuffers) &&
      *           (SPI_ONE == LddNoOfChannels))
      */
    /* Load the value of the local union variable to TX0W register */
    /* QAC Warning: START Msg(2:2814)-20 */
    SPI_CSIGH_REG_WRITE(LpCsihUserBaseAddr->ulCSIHTX0W,
                                        LunDataAccess1.ulRegData)
    /* END Msg(2:2814)-20*/
    /* Decrement the counter for number of buffers */
    LddNoOfBuffers--;
    /* Increment the counter for number of buffers transmitted */
    Spi_GstFifoCurrentCommData.usBufferCount++;
    /* Check all buffers are transmitted */
    if (SPI_ZERO == LddNoOfBuffers)
    {
      /* QAC Warning: START Msg(2:3892)- 21 */
      Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] = SPI_FIFO_BUFFER_EMPTY;
    }
    /* Check number of buffers do not exceed H/W Buffer size */
    else if (SPI_FIFO_SIZE <= Spi_GstFifoCurrentCommData.usBufferCount)
    {
      /* Set the flag to indicate Buffer is FULL */
      Spi_GucHWFifoBufferSts[SPI_FIFO_TX_INDEX] = SPI_FIFO_BUFFER_FULL;
      /* END Msg(2:3892)- 21 */
      /* Save the current status in RAM */
      Spi_GstFifoCurrentCommData.pNextTxData = LpNextTxData;
      Spi_GstFifoCurrentCommData.ddNoOfTxBuffers = LddNoOfBuffers;
      /* Break the loop */
      LddNoOfBuffers = SPI_ZERO;
    }
    else
    {
      /* No Action Required */
    }
   }while (SPI_ZERO < LddNoOfBuffers);
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_FifoReadData
**
** Service ID         : Not Applicable
**
** Description        : This function is to read the data from FIFO buffer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                      LpHWUnitInfo,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                      SPI_CONFIG_CONST) LpPBChannelConfig,
**                      P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA)
**                      LpCurrentRxData,
**                      Spi_NumberOfDataType LddNoOfBuffers
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstFifoCurrentCommData, Spi_GucHWFifoBufferSts
**
** Function Invoked   : SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used     : CSIHnRX0W, CSIHnRX0H
*******************************************************************************/
/* Implements SPI_ESDD_UD_079 */
#if (SPI_FIFO_MODE == STD_ON)

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_FAST_CODE) Spi_FifoReadData
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData,
Spi_NumberOfDataType LddNoOfBuffers)
/* END Msg (2:3227)-16 */
/* END Msg(2:3206)-22 */
{
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess2;
  /* END Msg (4:0759)-1 */
  #if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))
  uint32 LulShiftData;
  uint32 LulShiftDataLow;
  uint32 LulShiftDataHigh;
  #endif
  Spi_DataType LddData;
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* QAC Warning: START Msg(2:2814)- 20 */
  /* Get the base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg(2:2814)- 20 */
  /* END Msg(4:0316)-9 */

  do
  {
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, Receive the data from the
     * Rx register to local union variable
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess2.ulRegData = LpCsihUserBaseAddr->ulCSIHRX0W;
    /* END Msg(2:2814)-20*/
    LddData = LunDataAccess2.ucRegData4[SPI_ZERO];

    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess2.ulRegData = LpCsihUserBaseAddr->ulCSIHRX0W;
    /* Load the value from union variable to local variable */
    /* END Msg(2:2814)-20 */
    LddData = LunDataAccess2.usRegData5[SPI_ZERO];

    #else
    /*
     * Data width is maximum 32-bit, Check if the the data width of
     * requested channel is more than 16 bits
     */
     /* QAC Warning: START Msg(2:2814)- 20 */
    if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
    {
      LunDataAccess2.ulRegData = LpCsihUserBaseAddr->ulCSIHRX0W;

      LddData = LunDataAccess2.usRegData5[SPI_ZERO];
    }
    /* END Msg(2:2814)- 20 */
    else
    {
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /*
         * Take a local union variable to construct the value from
         * RX0W register
         */
        LunDataAccess2.ulRegData = LpCsihUserBaseAddr->ulCSIHRX0W;
        LunDataAccess2.usRegData5[SPI_ONE] = LpCsihUserBaseAddr->usCSIHRX0H;
      }
      else
      {
        /*
         * Take a local union variable to construct the value from
         * RX0W register
         */
        LunDataAccess2.ulRegData = LpCsihUserBaseAddr->ulCSIHRX0W;
        LunDataAccess2.usRegData5[SPI_ONE] =
                                         LunDataAccess2.usRegData5[SPI_ZERO];
        LunDataAccess2.usRegData5[SPI_ZERO] = LpCsihUserBaseAddr->usCSIHRX0H;
      }

      LddData = LunDataAccess2.ulRegData;
    }
    #endif /* End of (SPI_8BIT_DATA_WIDTH == STD_ON)*/
    if (NULL_PTR != LpCurrentRxData)
    {
      #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      /* MISRA Violation: START Msg(4:2962)-11 */
      if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
             (SPI_TRUE != LpPBChannelConfig->blDirection) &&
              (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
      /* END Msg(4:2962)-11 */
      {
        LulShiftData =  LunDataAccess2.ulRegData;
        LulShiftDataHigh = LulShiftData & SPI_HIGH_DATA_MASK;
        LulShiftDataLow = LulShiftData & SPI_LOW_DATA_MASK;
        LulShiftDataLow = (uint32)(LulShiftDataLow << (SPI_SIXTEEN -
                                         (LpPBChannelConfig->ucDLSSetting)));
        LulShiftData = LulShiftDataHigh | LulShiftDataLow;
        LulShiftData = LulShiftData >> (SPI_SIXTEEN -
                                         (LpPBChannelConfig->ucDLSSetting));
        *LpCurrentRxData = (Spi_DataType)LulShiftData;
      }
      else
      #endif
      {
        *LpCurrentRxData = LddData;
      }
      /* MISRA Violation: START Msg(4:0489)-3 */
      LpCurrentRxData++;
      /* END Msg (4:0489)-3 */
    }
    else
    {
      /* No Action Required */
    }
    /* Decrement the counter for number of buffers */
    LddNoOfBuffers--;
    /* Increment the counter for number of buffers transmitted */
    Spi_GstFifoCurrentCommData.usBufferCount++;
    /* Check all buffers are transmitted */
    if (SPI_ZERO == LddNoOfBuffers)
    {
      /* QAC Warning: START Msg(2:3892)-21 */
      Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX] = SPI_FIFO_BUFFER_EMPTY;
      /* END Msg(2:3892)-21 */
    }
    /* QAC Warning: START Msg(2:3892)-21 */
    /* Check number of buffers do not exceed H/W Buffer size */
    else if (SPI_FIFO_SIZE <= Spi_GstFifoCurrentCommData.usBufferCount)
     /* END Msg(2:3892)-21 */
    {
      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts to protect this critical section */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif

      /* Set a flag to indicate PAUSE of transfer */
      /* QAC Warning: START Msg(2:3892)-21 */
      Spi_GucHWFifoBufferSts[SPI_FIFO_RX_INDEX] = SPI_FIFO_BUFFER_FULL;
      /* END Msg(2:3892)-21 */
      /* Save the current status in RAM */
      Spi_GstFifoCurrentCommData.pCurrentRxData = LpCurrentRxData;
      Spi_GstFifoCurrentCommData.ddNoOfRxBuffers = LddNoOfBuffers;

      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif

      /* Break the loop */
      LddNoOfBuffers = SPI_ZERO;
    }
    else
    {
      /* No Action Required */
    }
  }while (SPI_ZERO < LddNoOfBuffers);
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_ReceiveDirectAcessData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked from the ReceiveIsr function
**                      for processing the received data in direct Access mode.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GstHWUnitInfo, Spi_GpFirstChannel, Spi_GpFirstJob,
**                      Spi_GaaJobQueue, Spi_GpFirstJobList, Spi_GddQueueIndex
**                      Spi_GpConfigPtr, pi_GaaHighPriorityCommActive
**                      Spi_GstCurrentCommData, Spi_GusAsynDataAccess
**
** Function Invoked   : Spi_ReceiveCsigData, Spi_ReceiveCsihData,
**                      Spi_ReceiveChannelPropSame, Spi_ProcessSequence
**
** Registers Used     : CSIHnRX0H, CSIGnRX0
*******************************************************************************/

 #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* Implements SPI_ESDD_UD_170 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_FAST_CODE)Spi_ReceiveDirectAcessData
                               (Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
/* END Msg(2:3227)-16 */
{

  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData;
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)LpHWUnitInfo;
  Spi_JobType LddJobIndex;
  Spi_JobType LddJobListIndex;
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  #endif

  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  #endif

  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                             LpPBChannelConfig;

  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentRxChannelList;
  #endif

  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  Spi_HWUnitType LddHWUnitNumber;
  #endif

  /* Get the pointer to the structure of HW Unit information */
  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];

  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  /* QAC Warning: START Msg(2:2814)-20 */
  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];
  /* END Msg(2:2814)-20 */
  if (SPI_FALSE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
  #endif
  {
    LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ZERO]);
  }
  #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
  else
  {
    LpCurrentCommData = &(Spi_GstCurrentCommData[SPI_ONE + LddHWUnitNumber]);
  }
  #endif
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  LpCurrentRxChannelList = LpCurrentCommData->pCurrentRxChannelList;
  /* MISRA Violation: START Msg(4:0489)-3*/
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Decrement the source pointer */
  LpCurrentRxChannelList--;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0489)-3 */

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentRxChannelList);
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */

  if (SPI_TRUE == LpCurrentCommData->blRxEDL)
  {
    /* Reset the flag for indicating EDL */
    LpCurrentCommData->blRxEDL = SPI_FALSE;

    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      /* MISRA Violation: START Msg(4:0316)-9 */
      /* Get the base address of the HW Unit */
      LpCsigUserBaseAddr =
                       (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
      /* END Msg (4:0316)-9*/

      /* QAC Warning: START Msg(2:2814)-20 */
      /* Store the received data in a variable */
      Spi_GusAsynDataAccess = LpCsigUserBaseAddr->usCSIGRX0;
      /* END Msg(2:2814)-20 */
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      /* MISRA Violation: START Msg(4:0316)-9 */
      /* Get the base address of the HW Unit */
      LpCsihUserBaseAddr =
                   (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
      /* END Msg (4:0316)-9*/
      /* QAC Warning: START Msg(2:2814)-20 */
      /* Store the received data in a variable */
      Spi_GusAsynDataAccess = LpCsihUserBaseAddr->usCSIHRX0H;
      /* END Msg(2:2814)-20 */
      #endif
    }
  }
  else
  #endif /* End of #if (SPI_EXTENDED_DATA_LENGTH == STD_ON) */
  {
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
    #endif
    {
      #if (SPI_CSIG_CONFIGURED == STD_ON)
      #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      Spi_ReceiveCsigData(LpHWUnitInfo, LpPBChannelConfig, LpCurrentCommData);
      #else
      Spi_ReceiveCsigData(LpHWUnitInfo, LpCurrentCommData);
      #endif
      #endif
    }
    #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
    else
    #endif
    {
      #if (SPI_CSIH_CONFIGURED == STD_ON)
      #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      Spi_ReceiveCsihData(LpHWUnitInfo, LpPBChannelConfig, LpCurrentCommData);
      #else
      Spi_ReceiveCsihData(LpHWUnitInfo, LpCurrentCommData);
      #endif
      #endif
    }


    /* Get the index of job list for the current job from the job queue */
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[(LddHWUnitNumber
                                        + SPI_MAX_CSIH_HW_INDEX + SPI_TWO)]];
    #else
    LddJobListIndex = Spi_GaaJobQueue[Spi_GddQueueIndex[LucHWMemoryMode]];
    #endif


    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the respective job list index  */
    LpJobList = Spi_GpFirstJobList + LddJobListIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */

    /* Get the index of the job */
    /* QAC Warning: START Msg(2:2814)-20 */
    LddJobIndex = LpJobList->ddJobIndex;
    /* END Msg(2:2814)-20 */

    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the job structure */
    LpJobConfig = Spi_GpFirstJob + LddJobIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */
    /* QAC Warning: START Msg(2:2814)-20 */
    if (SPI_TRUE == LpJobConfig->blIsChannelPropSame)
    /* END Msg(2:2814)-20 */
    {

      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      Spi_ReceiveChannelPropSame(LpCurrentCommData, LddHWUnit, LucHWMemoryMode,
                                                              LddHWUnitNumber);
      #else
      Spi_ReceiveChannelPropSame(LpCurrentCommData, LddHWUnit, LucHWMemoryMode);
      #endif
    }
    else
    {
      /* Check if all buffers in the channel are transmitted */
      if (SPI_ZERO < LpCurrentCommData->ddNoOfRxBuffers)
      {
        /* Decrement the number of buffers to be transmitted */
        (LpCurrentCommData->ddNoOfRxBuffers)--;
      }
      else
      {
        #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
        /* QAC Warning: START Msg(2:2814)-20 */
        if (SPI_TRUE == LpPBChannelConfig->blEDLEnabled)
        {
           LpCurrentCommData->blRxEDL = SPI_FALSE;
        /* END Msg(2:2814)-20 */
        }
        else
        {
           /* No action required */
        }
        #endif
        /* All channels are transmitted. Hence the job is transmitted */
        Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
      }
    }
  }
}

#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name      : Spi_ReceiveCsigData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked from Spi_ReceiveDirectAcessData
**                      for processing the received data for CSIG hardware unit
**                      in Direct Access Mode.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpHWUnitInfo,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                          SPI_CONFIG_CONST) LpPBChannelConfig,
**                      P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)
**                                                            LpCurrentCommData
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GusAsynDataAccess
**
** Function Invoked   : None
**
** Registers Used     : CSIGnRX0
*******************************************************************************/
/* Implements SPI_ESDD_UD_167 */
#if (SPI_CSIG_CONFIGURED == STD_ON)
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                    (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsigData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData)
#else
FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsigData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData)
#endif
/* END Msg(2:3227)-16 */
{

  P2VAR(Spi_CsigUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigUserBaseAddr;
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData;
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  uint32 LulShiftData;
  uint32 LulShiftDataLow;
  uint32 LulShiftDataHigh;
  #endif
  /* START Msg(3:3203)-19 */
  volatile uint16 Lus16BitData;
  /* END Msg (3:3203)-19*/

  Spi_DataType LddData;

  /* QAC Warning: START Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the base address of the HW Unit */
  LpCsigUserBaseAddr =
      (Spi_CsigUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/

  LpCurrentRxData = LpCurrentCommData->pCurrentRxData;
  /* END Msg(2:2814)-20 */
  if (NULL_PTR != LpCurrentRxData)
  {
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, Receive the data from the
     * Rx register to local union variable
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    LddData = (uint8)LpCsigUserBaseAddr->usCSIGRX0;
    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    LddData = LpCsigUserBaseAddr->usCSIGRX0;
    /* END Msg(2:2814)-20 */
    #else
    /* Data width is maximum 32-bit, check if the the data width of
     * requested channel is more than 16 bits
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
    {
      LddData = LpCsigUserBaseAddr->usCSIGRX0;
    }
    /* END Msg(2:2814)-20 */
    else
    {
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /*
         * Take a local union variable to construct the value from RX0W
         * register
         */
        LunDataAccess1.usRegData5[SPI_ONE] = LpCsigUserBaseAddr->usCSIGRX0;
        LunDataAccess1.usRegData5[SPI_ZERO] = Spi_GusAsynDataAccess;
      }
      else
      {
        /*
         * Take a local union variable to construct the value from RX0W
         * register
         */
        LunDataAccess1.usRegData5[SPI_ZERO] = LpCsigUserBaseAddr->usCSIGRX0;
        LunDataAccess1.usRegData5[SPI_ONE] = Spi_GusAsynDataAccess;

      } /* End of if (SPI_TRUE == LpPBChannelConfig->blDirection) */
      /* MISRA Violation: START Msg(4:2995)-15 */
      /*Start : SPI_UT_007*/
      if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
                    (SPI_TRUE != LpPBChannelConfig->blDirection) &&
                    (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                    (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
      /* End : SPI_UT_007 */
      {
        /* END Msg(4:2995)-15 */
        LulShiftData =  LunDataAccess1.ulRegData;
        LulShiftDataHigh = LulShiftData & SPI_HIGH_DATA_MASK;
        LulShiftDataLow = LulShiftData & SPI_LOW_DATA_MASK;
        LulShiftDataLow = LulShiftDataLow << (SPI_SIXTEEN -
                                       (LpPBChannelConfig->ucDLSSetting));
        LulShiftData = LulShiftDataHigh | LulShiftDataLow;
        LulShiftData = LulShiftData >> (SPI_SIXTEEN -
                                 (LpPBChannelConfig->ucDLSSetting));
        LddData  = LulShiftData;
      }
      else
      {
        LddData = LunDataAccess1.ulRegData;
      }

      LpCurrentCommData->blRxEDL = SPI_TRUE;
    } /* End of if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */
    #endif /*End of #if (SPI_8BIT_DATA_WIDTH == STD_ON) */

    *LpCurrentRxData = LddData;

    /* MISRA Violation: START Msg(4:0489)-3 */
    LpCurrentRxData++;
    /* END Msg (4:0489)- 3 */

    LpCurrentCommData->pCurrentRxData = LpCurrentRxData;

  }
  else
  {
    Lus16BitData = LpCsigUserBaseAddr->usCSIGRX0;
    #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    if (SPI_TRUE == LpPBChannelConfig->blEDLEnabled)
    {
      LpCurrentCommData->blRxEDL = SPI_TRUE;
    }
    else
    {
      /* No action required */
    }
    #endif
  }
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif
#endif

/*******************************************************************************
** Function Name      : Spi_ReceiveCsihData
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked from Spi_ReceiveDirectAcessData
**                      for processing the received data for CSIH hardware unit
**                      in Direct Access Mode.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpHWUnitInfo,
**                      P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                          SPI_CONFIG_CONST) LpPBChannelConfig,
**                      P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)
**                                                            LpCurrentCommData
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GusAsynDataAccess
**
** Function Invoked   : None
**
** Registers Used     : CSIHnRX0H
*******************************************************************************/
/* Implements SPI_ESDD_UD_168 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                    (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))

#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsihData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData)
#else
FUNC(void, SPI_FAST_CODE)Spi_ReceiveCsihData(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_CONST)LpCurrentCommData)
#endif
{
/* END Msg(2:3227)-16 */
  P2VAR(Spi_CsihUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihUserBaseAddr;
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData;
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  uint32 LulShiftData;
  uint32 LulShiftDataLow;
  uint32 LulShiftDataHigh;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg(4:0759)-1 */
  #endif
  Spi_DataType LddData;
  /* START Msg(3:3203)-19 */
  volatile uint16 Lus16BitData;
  /* END Msg (3:3203)-19 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:0316)-9 */
  /* Get the base address of the HW Unit */
  LpCsihUserBaseAddr = (Spi_CsihUserRegs *)LpHWUnitInfo->pHwUserBufferAddress;
  /* END Msg (4:0316)-9*/

  LpCurrentRxData = LpCurrentCommData->pCurrentRxData;
  /* END Msg(2:2814)-20 */
  if (NULL_PTR != LpCurrentRxData)
  {
    #if (SPI_8BIT_DATA_WIDTH == STD_ON)
    /*
     * Data width is maximum 8-bit. Hence, Receive the data from the
     * Rx register to local union variable
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    LddData = (uint8) LpCsihUserBaseAddr->usCSIHRX0H;
    /* END Msg(2:2814)-20 */
    #elif (SPI_16BIT_DATA_WIDTH == STD_ON)
    /* QAC Warning: START Msg(2:2814)-20 */
    LddData = LpCsihUserBaseAddr->usCSIHRX0H;
    /* END Msg(2:2814)-20 */
    #else
    /*
     * Data width is maximum 32-bit, check if the the data width of
     * requested channel is more than 16 bits
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
    {
      LddData = LpCsihUserBaseAddr->usCSIHRX0H;
    }
    /* END Msg(2:2814)-20 */
    else
    {
      /* Check if the configured data direction is LSB first */
      if (SPI_TRUE == LpPBChannelConfig->blDirection)
      {
        /*
         * Take a local union variable to construct the value from RX0W
         * register
         */
        LunDataAccess1.usRegData5[SPI_ONE] = LpCsihUserBaseAddr->usCSIHRX0H;
        LunDataAccess1.usRegData5[SPI_ZERO] = Spi_GusAsynDataAccess;
      }
      else
      {
        /*
         * Take a local union variable to construct the value from RX0W
         * register
         */
        LunDataAccess1.usRegData5[SPI_ZERO] = LpCsihUserBaseAddr->usCSIHRX0H;
        LunDataAccess1.usRegData5[SPI_ONE] = Spi_GusAsynDataAccess;

      } /* End of if (SPI_TRUE == LpPBChannelConfig->blDirection) */
      /*Start : SPI_UT_008*/
      /* MISRA Violation: START Msg(4:2995)-15 */
      if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
                    (SPI_TRUE != LpPBChannelConfig->blDirection) &&
                    (SPI_FIFTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                    (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
      /* End : SPI_UT_008 */
      {
        /* END Msg(4:2995)-15 */
        LulShiftData =  LunDataAccess1.ulRegData;
        LulShiftDataHigh = LulShiftData & SPI_HIGH_DATA_MASK;
        LulShiftDataLow = LulShiftData & SPI_LOW_DATA_MASK;
        LulShiftDataLow = LulShiftDataLow << (SPI_SIXTEEN -
                                     (LpPBChannelConfig->ucDLSSetting));
        LulShiftData = LulShiftDataHigh | LulShiftDataLow;
        LulShiftData = LulShiftData >> (SPI_SIXTEEN -
                                 (LpPBChannelConfig->ucDLSSetting));
        LddData  = LulShiftData;
      }
      else
      {
        LddData = LunDataAccess1.ulRegData;
      }
      LpCurrentCommData->blRxEDL = SPI_TRUE;
    } /* End of if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */
    #endif

    *LpCurrentRxData = LddData;

    /* MISRA Violation: START Msg(4:0489)-3 */
    LpCurrentRxData++;
    /* END Msg (4:0489)- 3 */

    LpCurrentCommData->pCurrentRxData = LpCurrentRxData;

  }
  else
  {
    Lus16BitData = LpCsihUserBaseAddr->usCSIHRX0H;
    #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
     if (SPI_TRUE == LpPBChannelConfig->blEDLEnabled)
     {
        LpCurrentCommData->blRxEDL = SPI_TRUE;
     }
     else
     {
        /* No action required */
     }
    #endif
  }
}

#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif
#endif

/*******************************************************************************
** Function Name      : Spi_ReceiveChannelPropSame
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked from Spi_ReceiveDirectAcessData
**                      for processing the remaining buffers when channel
**                      properties are same.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
**                                                             LpCurrentCommData
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstChannel,
**                      Spi_GaaHighPriorityCommActive[], Spi_GpConfigPtr,
**                      Spi_GaaChannelEBData.
**
** Function Invoked   : SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION,
**                      Spi_ProcessSequence
**
** Registers Used     : None.
*******************************************************************************/
/* Implements SPI_ESDD_UD_037 */
 #if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                            (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
/* Implements EAAR_PN0034_FR_0061 */
#define SPI_START_SEC_CODE_FAST
#include "MemMap.h"
#if (SPI_HW_PRIORITY_ENABLED == STD_ON)
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(0:2755)-25 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_FAST_CODE)Spi_ReceiveChannelPropSame(
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode, Spi_HWUnitType LddHWUnitNumber)
#else
FUNC(void, SPI_FAST_CODE)Spi_ReceiveChannelPropSame(
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode)
#endif
/* END Msg(2:3227)-16 */
/* END Msg(0:2755)-25 */
/* END Msg(2:3206)-22 */
{

  P2CONST(Spi_ChannelType, AUTOMATIC, SPI_CONFIG_CONST) LpCurrentRxChannelList;
  P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)
                                                            LpPBChannelConfig;
  Spi_NumberOfDataType LddBufferIndex;
  P2VAR(Spi_DataType, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentRxData;
  /* QAC Warning: START Msg(2:2814)-20 */
  if ((SPI_ZERO < LpCurrentCommData->ddNoOfRxChannels) &&
                        (SPI_ZERO == LpCurrentCommData->ddNoOfRxBuffers))
  {

    LpCurrentRxChannelList = LpCurrentCommData->pCurrentRxChannelList;
    /* Get the pointer to the post-build structure of the channel */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    LpPBChannelConfig = Spi_GpFirstChannel + (*LpCurrentRxChannelList);
    /* END Msg(2:2824)-17 */
    /* END Msg (4:0488)-4 */

    LddBufferIndex = LpPBChannelConfig->ddBufferIndex;
  /* END Msg(2:2814)-20 */
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif

    /* MISRA Violation: START Msg(4:0489)-3 */
    (LpCurrentCommData->pCurrentRxChannelList)++;
    /* END Msg (4:0489)-3 */

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif


    #if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO)
    /* Check if the buffer type is internal buffer */
    if ((SPI_ZERO == LpPBChannelConfig->ucChannelBufferType)
      #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
      || ((SPI_TRUE == Spi_GaaHighPriorityCommActive[LddHWUnitNumber])
      && (SPI_ONE != LpPBChannelConfig->ucChannelBufferType))
      #endif
      )
    {
      #if (SPI_INTERNAL_RW_BUFFERS == STD_ON)
      /* Update the RAM variable for Rx pointer with channel IB index */
      /* QAC Warning: START Msg(2:2814)-20 */
      LpCurrentRxData = Spi_GpConfigPtr->pChannelIBRead;
      /* END Msg(2:2814)-20 */
      /* QAC Warning: START Msg(2:2824)-17 */
      /* MISRA Violation: START Msg(4:0488)-4 */
      LpCurrentRxData = LpCurrentRxData + LddBufferIndex;
      /* END Msg (4:0488)-4 */
      /* END Msg(2:2824)-17 */
      LpCurrentCommData->ddNoOfRxBuffers = LpPBChannelConfig->ddNoOfBuffers;
      #endif
    }
    else
    {
      #if (SPI_EB_CONFIGURED == STD_ON)
      /* Update the RAM variable for Rx pointer */
      LpCurrentRxData = Spi_GaaChannelEBData[LddBufferIndex].pDestPtr;
      /* Update counter with number of buffers of the channel */
      LpCurrentCommData->ddNoOfRxBuffers =
                                Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
      #endif
    }
    #elif (SPI_INTERNAL_RW_BUFFERS == STD_ON)

    /* Update the RAM variable for Rx pointer with channel IB index */
    /* QAC Warning: START Msg(2:2814)-20 */
    LpCurrentRxData = Spi_GpConfigPtr->pChannelIBRead;
    /* END Msg(2:2814)-20 */

    /* QAC Warning: START Msg(2:2824)-17 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpCurrentRxData = LpCurrentRxData + LddBufferIndex;
    /* END Msg (4:0488)-4 */
    /* END Msg(2:2824)-17 */

    LpCurrentCommData->ddNoOfRxBuffers = LpPBChannelConfig->ddNoOfBuffers;
    #else
     /*
     * Update the RAM variable for Tx pointer with channel EB
     * source pointer
     */
    #if (SPI_EB_CONFIGURED == STD_ON)
    /* Update the RAM variable for Rx pointer */
    LpCurrentRxData = Spi_GaaChannelEBData[LddBufferIndex].pDestPtr;
    /* Update counter with number of buffers of the channel */
    LpCurrentCommData->ddNoOfRxBuffers =
                                Spi_GaaChannelEBData[LddBufferIndex].ddEBLength;
    #endif
    #endif

    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
    (LpCurrentCommData->ddNoOfRxChannels)--;
    /* MISRA Violation: START Msg(4:2962)-11 */
    /* Save the pointer to data to be received */
    LpCurrentCommData->pCurrentRxData = LpCurrentRxData;
    /* END Msg(4:2962)-11 */
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
  }
  else
  {
    /* No action required */
  }
  /* Check if all buffers in the channel are transmitted */
  if (SPI_ZERO < LpCurrentCommData->ddNoOfRxBuffers)
  {
    /* Decrement the number of buffers to be transmitted */
    (LpCurrentCommData->ddNoOfRxBuffers)--;
  }
  /* Check if all buffers in the channel are transmitted */
  else if (SPI_ZERO == LpCurrentCommData->ddNoOfRxChannels)
  {
    /* All channels are transmitted. Hence the job is transmitted */
    Spi_ProcessSequence(LddHWUnit, LucHWMemoryMode);
  }
  else
  {
    /* No action required */
  }
}
#define SPI_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name      : Spi_ProcesSeqInDualOrTxMod
**
** Service ID         : Not Applicable
**
** Description        : This function is to process remaining jobs in
**                      the sequence to be transmitted in Dual buffer mode or
**                      Tx only mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_CONFIG_CONST)
**                      LpHWUnitInfo, Spi_HWUnitType LddHWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstSeq, Spi_GstSeqProcess, Spi_GpConfigPtr,
**                      Spi_GddDriverStatus, Spi_GaaSeqCancel, Spi_GaaSeqQueue,
**                      Spi_GddQueueIndex, Spi_GblQueueStatus,
**                      Spi_GucHwUnitStatus, Spi_GusAllQueueSts.
**
** Function Invoked   : Spi_InitiateJobTx, Spi_ChkCancelReqForSeq
**                      SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION.
**
** Registers Used     : IMRn
*******************************************************************************/
/* Implements SPI_ESDD_UD_166 */
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI073, SPI120, SPI264, AR_PN0063_FR_0110, SPI075, SPI163 */
/* Implements EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE)Spi_ProcesSeqInDualOrTxMod(
P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_CONFIG_CONST) LpHWUnitInfo,
Spi_HWUnitType LddHWUnit)
{
  /*END Msg(2:3227)-16 */
  Spi_HWUnitType LddHWUnitNumber;
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  #if (SPI_CANCEL_API == STD_ON)
  uint8 LucStatusMask;
  uint8 LucVar;
  uint8 LucMask;
  #endif
  Spi_JobType LddNoOfJobs;
  Spi_JobType LddJobListIndex;
  Spi_JobType LddReqJobListIndex;

  Spi_SequenceType LddSeqIndex;
  Spi_SequenceType LddLowestQueueIndex;

  #if (SPI_CANCEL_API == STD_ON)
  /* MISRA Violation: START Msg(4:2982)-2 */
  LucStatusMask = SPI_ZERO;
  /* END Msg(4:2982)-2 */
  #endif
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Disable transmit interrupt control */
  RH850_SV_MODE_IMR_OR(16, (LpHWUnitInfo->pTxImrAddress),
                      ((uint16)(~(LpHWUnitInfo->usTxImrMask))));

  /* Disable receive interrupt control */
  RH850_SV_MODE_IMR_OR(16, (LpHWUnitInfo->pRxImrAddress),
                      ((uint16)(~(LpHWUnitInfo->usRxImrMask))));


  LddHWUnitNumber = Spi_GpConfigPtr->aaHWUnitNumber[LddHWUnit];

  LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* Get the pointer to the post-build sequence structure */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg (4:0488)-4 */

  #if (SPI_LEVEL_DELIVERED != SPI_ZERO)
  /* Check if the notification function is configured */
  if (NULL_PTR != LpSeqConfig->pSpiSeqEndNotification)
  {
    /* END Msg(2:2814)-20 */
    /* Invoke the notification function */
    LpSeqConfig->pSpiSeqEndNotification();
  }
  else
  {
    /* No action required */
  }
  #endif

  LddLowestQueueIndex = Spi_GpConfigPtr->aaHWUnitQueueIndex[LddHWUnit];

  if ( (Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]) == LddLowestQueueIndex)
  {
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif

    Spi_GblQueueStatus[LddHWUnitNumber + SPI_TWO] = SPI_QUEUE_EMPTY;

    /*
     * Changing the hardware status after completing the sequence
     * transmission
     */
    /* QAC Warning: START Msg(2:3892)- 21 */
    /* MISRA Violation: START Msg(4:0400)-17 */
    Spi_GucHwUnitStatus = (Spi_GucHwUnitStatus ^
                              ((Spi_HWUnitType)(SPI_ONE << LddHWUnitNumber)));
    Spi_GusAllQueueSts = (Spi_GusAllQueueSts & ((Spi_HWUnitType)
             (~((Spi_HWUnitType)(SPI_ONE << (LddHWUnitNumber + SPI_TWO))))));
    /* END Msg(4:0400)-17 */
    /* END Msg(2:3892)- 21 */
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Enable relevant interrupts to protect this critical section */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
    /* QAC Warning: START Msg(2:3416)-24 */
    if (SPI_ZERO == Spi_GusAllQueueSts)
    /* END Msg(2:3416)-24 */
    {
      /* Update driver status as idle */
      Spi_GddDriverStatus = SPI_IDLE;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    #if (SPI_CANCEL_API == STD_ON)
    LucStatusMask = Spi_ChkCancelReqForSeq
                                         (LddHWUnitNumber, LddLowestQueueIndex);

    if (SPI_ZERO == LucStatusMask)
    #endif
    {
      #if (SPI_CANCEL_API == STD_OFF)
      Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]--;
      #endif
      LddSeqIndex =
                  Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];


      /* MISRA Violation: START Msg(4:0488)-4 */
      /* Get the pointer to the post-build sequence structure */
      LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
      /* END Msg (4:0488)-4 */

      /* Get the job list index of the last job of the sequence */
      LddJobListIndex = LpSeqConfig->ddJobListIndex;

      /* Get the number of jobs configured for the requested sequence */
      LddNoOfJobs = LpSeqConfig->ddNoOfJobs;

      /* Get the index of the job list for the first job of the sequence */
      LddReqJobListIndex = LddJobListIndex + (LddNoOfJobs - SPI_ONE);

      #if (SPI_CANCEL_API == STD_ON)
      /* Get the cancel byte offset for the requested sequence  */
      LucVar = Spi_GstSeqProcess[LddSeqIndex].ucCancelOffset;
      /* Get the cancel byte mask */
      LucMask = Spi_GstSeqProcess[LddSeqIndex].ucCancelMask;

      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

      /* Disable relevant interrupts to protect this critical section */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

      #endif


      /* Reset the cancel bit array for this sequence */
      Spi_GaaSeqCancel[LucVar] =
                             (Spi_GaaSeqCancel[LucVar] & ((uint8)(~LucMask)));


      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

      /* Enable relevant interrupts to protect this critical section */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

      #endif
      #endif /* End of (SPI_CANCEL_API == STD_ON) */

      /* Check if start sequence notification is enabled */
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
      #endif /*if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON)*/

      /* Initiate the transmission for that sequence */
      Spi_InitiateJobTx(LddReqJobListIndex);
    } /* End of if (SPI_ZERO != Spi_GddQueueIndex[LucHWMemoryMode]) */
    #if (SPI_CANCEL_API == STD_ON)
    else
    {
      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

      /* Disable relevant interrupts to protect this critical section */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

      #endif
      /* QAC Warning: START Msg(2:3892)- 21 */
      /* MISRA Violation: START Msg(4:0400)-17 */
      Spi_GblQueueStatus[LddHWUnitNumber + SPI_TWO] = SPI_QUEUE_EMPTY;

      Spi_GusAllQueueSts = (Spi_GusAllQueueSts & ((Spi_HWUnitType)
              (~((Spi_HWUnitType)(SPI_ONE << (LddHWUnitNumber + SPI_TWO))))));
      /* END Msg(4:0400)-17 */
      /* END Msg(2:3892)- 21 */

      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

      /* Enable relevant interrupts to protect this critical section */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

      #endif
      /* QAC Warning: START Msg(2:3416)-24 */
      if (SPI_ZERO == Spi_GusAllQueueSts)
      /* END Msg(2:3416)-24 */
      {
        /* Update driver status as idle */
        Spi_GddDriverStatus = SPI_IDLE;
      }
      else
      {
        /* No action required */
      }
    }
    #endif /* End of (SPI_CANCEL_API == STD_ON) */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* End of ((SPI_DUAL_BUFFER_MODE == STD_ON)
                                             || (SPI_TX_ONLY_MODE == STD_ON))*/

/*******************************************************************************
** Function Name      : Spi_ChkCancelReqForSeq
**
** Service ID         : Not Applicable
**
** Description        : This function is to check for the cancel requests during
**                      the processing of the sequence in Dual buffer or TX only
**                      modes and is called from Spi_ProcesSeqInDualOrTxMod.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : Spi_HWUnitType LddHWUnitNumber,
**                      Spi_SequenceType LddLowestQueueIndex.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : uint8 LucStatusMask
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstSeq, Spi_GstSeqProcess, Spi_GpConfigPtr,
**                      Spi_GaaSeqCancel, Spi_GaaSeqQueue, Spi_GaaSeqResul
**                      Spi_GddQueueIndex
**
** Function Invoked   : SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION.
**
** Registers Used     : None
*******************************************************************************/
/* Implements SPI_ESDD_UD_035 */
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
#if (SPI_CANCEL_API == STD_ON)
/* Implements EAAR_PN0034_FR_0061 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(uint8, SPI_PRIVATE_CODE)Spi_ChkCancelReqForSeq(
           Spi_HWUnitType LddHWUnitNumber, Spi_SequenceType LddLowestQueueIndex)
{
/* END Msg(2:3227)-16 */
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_CONST) LpStsByteValue;
  P2VAR(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpStsByte;
  Spi_SequenceType LddSeqIndex;
  uint8 LucStatusOffset;
  uint8 LucStatusMask;
  uint8 LucVar;

  do
  {
    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Disable relevant interrupts to protect this critical section */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif

    Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]--;

    /* Check if critical section protection is required */
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

    /* Enable relevant interrupts to protect this critical section */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

    #endif
    /* QAC Warning: START Msg(2:2824)-17 */
    LddSeqIndex = Spi_GaaSeqQueue[Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO]];
    /* MISRA Violation: START Msg(4:0488)-4 */
    LpSeqConfig = Spi_GpFirstSeq + LddSeqIndex;
    /* END Msg (4:0488)-4 */
    /* END Msg(2:2824)-17 */
    /* Get the cancel byte mask */
    LucStatusMask = Spi_GstSeqProcess[LddSeqIndex].ucCancelMask;
    if (SPI_SEQ_CANCELLED != Spi_GaaSeqResult[LddSeqIndex])
    {
      /* Get the cancel byte offset for the requested sequence  */
      LucStatusOffset = Spi_GstSeqProcess[LddSeqIndex].ucCancelOffset;

      /* Get the cancel status for this sequence */
      LucStatusMask = LucStatusMask & Spi_GaaSeqCancel[LucStatusOffset];
      if (SPI_ZERO != LucStatusMask)
      {
        Spi_GaaSeqResult[LddSeqIndex] = SPI_SEQ_CANCELLED;
        #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || \
                                           (SPI_LEVEL_DELIVERED == SPI_TWO))
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* QAC Warning: START Msg(2:2814)-20 */
        /* Get the pointer to status bytes ROM value for the sequence */
        LpStsByteValue = (Spi_GpConfigPtr->pStsValueArray) +
                                    (LpSeqConfig->usStsValueStartByteIdx);
        /* END Msg(2:2814)-20 */
        /* END Msg(4:0488)-4 */
        /* Get the number of status byte ROM value */
        LucVar = LpSeqConfig->ucNoOfStsByteValue;
        /* MISRA Violation: START Msg(4:0488)-4 */
        if (NULL_PTR != Spi_GpConfigPtr->pStatusArray)
        {
          /* Get the pointer to the start byte of RAM area */
          LpStsByte = (Spi_GpConfigPtr->pStatusArray) +
                                    (LpSeqConfig->usStsUpdateStartByteIdx);
        /* END Msg(4:0488)-4 */
        }
        else
        {
          LpStsByte = NULL_PTR;
        }
        /* Check if critical section protection is required */
        #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

        /* Disable relevant interrupts to protect this critical section */
        SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

        #endif

        while ((SPI_ZERO < LucVar) && (NULL_PTR != LpStsByte))
        {

          /*
           * Reset the status bit of the requested sequence and the
           * sequences that have jobs shared with the requested sequence
           */
          /* QAC Warning: START Msg(2:2814)-20 */
          *LpStsByte = (*LpStsByte & ((uint8)(~(*LpStsByteValue))));
          /* END Msg(2:2814)-20 */
          /* MISRA Violation: START Msg(4:0489)-3 */
          LpStsByte++;
          /* END Msg(4:0489)-3 */
          /* MISRA Violation: START Msg(4:0489)-3 */
          LpStsByteValue++;
          /* END Msg(4:0489)-3 */
          LucVar--;
        } /* End of while (SPI_ZERO < LucVar) */

        /* Check if critical section protection is required */
        #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)

        /* Enable relevant interrupts to protect this critical section */
        SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);

        #endif
        #endif
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
  }while ((SPI_SEQ_CANCELLED == Spi_GaaSeqResult[LddSeqIndex]) &&
          (Spi_GddQueueIndex[LddHWUnitNumber + SPI_TWO] >
                                                    LddLowestQueueIndex));

  return LucStatusMask;
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif
#endif


/*******************************************************************************
** Function Name       : Spi_InitiateSyncTransmit
**
** Service ID          : NA
**
** Description         : This function is called from Spi_SyncTransmit API to
**                       initiate the synchronous transmission of the sequence.
**
** Sync/Async          : Synchronous.
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
** Preconditions       : None
**
** Global Variable     : Spi_GpFirstSeq,  Spi_GblSyncTx, Spi_GpFirstJobList,
**                       Spi_GaaSeqResult, Spi_GpFirstJob, Spi_GaaJobResult,
**                       Spi_GddSyncDriverStatus, Spi_GusHwStatus.
**
** Function invoked    : Dem_ReportErrorStatus,
**                       Spi_HWTransmitSyncJob, SPI_EXIT_CRITICAL_SECTION,
**                       SPI_ENTER_CRITICAL_SECTION
**
** Registers Used      : None
*******************************************************************************/
/* Implements SPI_ESDD_UD_007 */
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI285, SPI134, SPI286, SPI328, SPI254, SPI265 */
/* Implements SPI191, SPI006, SPI114, SPI073, SPI054, SPI281, SPI264 */
/* Implements SPI223_Conf, AR_PN0063_FR_0107, EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_InitiateSycTransmit
                                                     (Spi_SequenceType Sequence)
{
  /* END Msg(2:3227)-16 */
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig;
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  Spi_JobType LddNoOfJobs;
  Spi_JobType LddJobIndex;
  Spi_JobType LddJobListIndex;
  Std_ReturnType LenReturnValue;
  uint8 LucVar;
  /* Initialize Return Value */
  LenReturnValue = E_OK;
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the requested structure */
  LpSeqConfig = Spi_GpFirstSeq + Sequence;
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0488)-4 */

  /* Update the Global status variable */
  Spi_GddSyncDriverStatus = SPI_BUSY;

  /* Update the sequence result variable to SPI_SEQ_PENDING */
  Spi_GaaSeqResult[Sequence] = SPI_SEQ_PENDING;

  #if ((SPI_LEVEL_DELIVERED == SPI_TWO) || \
                                          (SPI_LEVEL_DELIVERED == SPI_ZERO))
  /*
   * Global boolean variable to avoid copy of properties repeatedly if
   * properties of all channels are same. This boolean allows copying channel
   * properties once. This boolean will be reset immediately after its use
   */
  Spi_GblSyncTx = SPI_TRUE;
  #endif

  /* Get the number of jobs */
  /* QAC Warning: START Msg(2:2814)-20 */
  LddNoOfJobs = LpSeqConfig->ddNoOfJobs;
  /* END Msg(2:2814)-20 */

  /* Get the index of the job list for the requested sequence */
  LddJobListIndex = (LpSeqConfig->ddJobListIndex) + (LddNoOfJobs - SPI_ONE);

  /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0488)-4 */
  /* Implements SPI_ESDD_UD_094 */
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
  #endif /* #if (SPI_SEQ_STARTNOTIFICATION_ENABLED == STD_ON) */

  while (SPI_ZERO < LddNoOfJobs)
  {
    /* QAC Warning: START Msg(2:2814)-20 */
    LddJobIndex = LpJobList->ddJobIndex;
    /* END Msg(2:2814)-20 */
    LucVar = LpJobList->ucJobCount;
    LucVar++;

    /* MISRA Violation: START Msg(4:0488)-4 */
    /* QAC Warning: START Msg(2:2824)-17 */
    /* Get the pointer to the job of the sequence */
    LpJobConfig = Spi_GpFirstJob + LddJobIndex;
    /* END Msg(2:2824)-17 */
    /* END Msg(4:0488)-4 */

    /* Update the job result variable */
    Spi_GaaJobResult[LddJobIndex] = SPI_JOB_PENDING;

    do
    {
      #if (SPI_INTERNAL_DIAG_BUFF == STD_ON)
      /* Invoke the lower layer function to synchronously transmit */
      LenReturnValue =
                    Spi_HWTransmitSyncJob(LpJobConfig, Sequence, LddJobIndex);
      #else
      /* Invoke the lower layer function to synchronously transmit */
      LenReturnValue = Spi_HWTransmitSyncJob(LpJobConfig);
      #endif

      if (E_OK != LenReturnValue)
      {
        /* Update the job result variable */
        Spi_GaaJobResult[LddJobIndex] = SPI_JOB_FAILED;
        /* Break the loops */
        LucVar = SPI_ZERO;
        LddNoOfJobs = SPI_ONE;
      }
      else
      {
        /* Decrement the job count */
        LucVar--;
      }
    }while (SPI_ZERO < LucVar);

    if (SPI_JOB_FAILED != Spi_GaaJobResult[LddJobIndex])
    {
      /* Update the job result variable */
      Spi_GaaJobResult[LddJobIndex] = SPI_JOB_OK;
    }
    else
    {
      /* No action required */
    }

    /* MISRA Violation: START Msg(4:0489)-1 */
    /* Decrement the pointer to the job list */
    LpJobList--;
    /* END Msg(4:0489)-1 */

    /* Decrement the number of jobs */
    LddNoOfJobs--;
  }

  if (E_OK == LenReturnValue)
  {
    /* Update the sequence result variable to SPI_SEQ_OK */
    Spi_GaaSeqResult[Sequence] = SPI_SEQ_OK;
  }
  else
  {
    /* Update the sequence result variable to SPI_SEQ_FAILED */
    Spi_GaaSeqResult[Sequence] = SPI_SEQ_FAILED;

    /* Raise production error */
    /* Report error to DEM    */
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
  }

    #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
       /* Disable relevant interrupts */
    SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    #endif

    /*
     * Changing the hardware status after completing the sequence
     * transmission
     */
    Spi_GusHwStatus = (Spi_GusHwStatus ^ (LpSeqConfig->usHWListIndex));

    #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* Enable relevant interrupts */
    SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
    #endif
  if (SPI_ZERO == Spi_GusHwStatus)
  #endif /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON) */
  {
    Spi_GddSyncDriverStatus = SPI_IDLE;
  }
  #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  #if ((SPI_LEVEL_DELIVERED == SPI_TWO) || \
                                            (SPI_LEVEL_DELIVERED == SPI_ZERO))
  /* MISRA Violation: START Msg(4:2995)-15 */
  /* MISRA Violation: START Msg(4:2991)-18 */
  if(SPI_IDLE == Spi_GddSyncDriverStatus)
  {
  /* END Msg(4:2995)-15 */
  /* END Msg(4:2991)-18 */
    /* Reset the Synchronous transmit flag */
    Spi_GblSyncTx = SPI_FALSE;
  }
  else
  {
    /* Do nothing */
  }
  #endif
  /* Implements SPI_ESDD_UD_101 */
  #if ((SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED == STD_ON) && \
                         ((SPI_LEVEL_DELIVERED == SPI_ZERO) || \
                               (SPI_LEVEL_DELIVERED == SPI_TWO)))
  /* Check if the notification function is configured */
  if (NULL_PTR != LpSeqConfig->pSpiSyncSeqEndNotification)
  {
    /* Invoke the notification function */
    LpSeqConfig->pSpiSyncSeqEndNotification();
  }
  else
  {
    /* No action required */
  }
  #endif /*
          * ((SPI_SYNC_SEQ_ENDNOTIFICATION_ENABLED == STD_ON) && \
          *                       ((SPI_LEVEL_DELIVERED == SPI_ZERO) || \
          *                                (SPI_LEVEL_DELIVERED == SPI_TWO)))
          */
  return LenReturnValue;
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name       : Spi_GetTxRegValue
**
** Service ID          : NA
**
** Description         : This service is called from
**                       Spi_ProcessChannelInDirAccMod to get the data to be
**                       written in to Tx register.
**
** Sync/Async          : Asynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST)
**                                                                  LpJobConfig,
**                       P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                           SPI_CONFIG_CONST)LpPBChannelConfig,
**                       P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpDataAccess,
**                       P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA)
**                                                            LpCurrentCommData,
**                       Spi_DataType LddData
**
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : void
**
** Preconditions       : None
**
** Global Variable     : None
**
** Function invoked    : None
**
** Registers Used      : None
*******************************************************************************/

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
                                        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON))|| \
                                        (SPI_HW_PRIORITY_ENABLED == STD_ON))

#if ((SPI_8BIT_DATA_WIDTH == STD_OFF) && (SPI_16BIT_DATA_WIDTH == STD_OFF))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI_ESDD_UD_178 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE)Spi_GetTxRegValue(
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST)LpPBChannelConfig,
P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST)LpDataAccess,
P2VAR(Spi_CurrentCommData, AUTOMATIC, SPI_CONFIG_DATA) LpCurrentCommData,
Spi_DataType LddData)
/* END Msg(2:3206)-22 */
/* END Msg(2:3227)-16 */
{

  uint32 LulShiftData;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess2;
  /* END Msg(4:0759)-1 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* MISRA Violation: START Msg(4:2962)-11 */
  if ((SPI_TRUE == LpPBChannelConfig->blEDLEnabled) &&
                     (SPI_TRUE != LpPBChannelConfig->blDirection) &&
                     (SPI_SIXTEEN >= LpPBChannelConfig->ucDLSSetting) &&
                     (SPI_ONE <= LpPBChannelConfig->ucDLSSetting))
  /* END Msg (4:2962)-11 */
  /* END Msg(2:2814)-20 */
  {
    LulShiftData = (uint32)LddData;
    LulShiftData = (uint32)(LulShiftData << (SPI_SIXTEEN -
                                            (LpPBChannelConfig->ucDLSSetting)));
    LunDataAccess2.ulRegData = LulShiftData;
    /* QAC Warning: START Msg(2:2814)-20 */
    LpDataAccess->Tst_ByteAccess.usRegData1 =
              LunDataAccess2.usRegData5[SPI_ZERO] >> (SPI_SIXTEEN -
                                             (LpPBChannelConfig->ucDLSSetting));
    /* END Msg(2:2814)-20 */
    LunDataAccess2.usRegData5[SPI_ZERO] =
                                        LpDataAccess->Tst_ByteAccess.usRegData1;
  }
  else
  {
    /*
     * Data width is maximum 32-bit. Tx data needs to be split to
     * LS Byte and MS Byte. Hence, load the Tx data to local union variable
     */
    LunDataAccess2.ulRegData = LddData;
  }

  /* Since data width is maximum 32-bit, check if the the data width of
   * requested channel is more than 16 bits
   */
  if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled)
  {
    /* Data width is maximum 16-bit. Hence, load LSB portion of the
     * local variable with the 16-bit data to be transmitted
     */
    LpDataAccess->Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
  }
  else
  {
    /* Check if the configured data direction is LSB first */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Load Tx data portion of the local variable with LSB first */
      LpDataAccess->Tst_ByteAccess.usRegData1 =
                                            LunDataAccess2.usRegData5[SPI_ZERO];
    }
    else
    {
      /* Load Tx data portion of the local variable with MSB first */
      LpDataAccess->Tst_ByteAccess.usRegData1 =
                                             LunDataAccess2.usRegData5[SPI_ONE];
    }

    /* Set the EDL bit in the local union variable */
    LpDataAccess->Tst_ByteAccess.ucRegData3 = SPI_SET_EDL;
    /* QAC Warning: START Msg(2:2814)-20 */
    /* Set the flag for indicating EDL */
    LpCurrentCommData->blTxEDL = SPI_TRUE;
    /* END Msg(2:2814)-20 */
    LpCurrentCommData->blRxEDL = SPI_TRUE;

  } /* End of !if (SPI_TRUE != LpPBChannelConfig->blEDLEnabled) */

}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name       : Spi_ProcessTransmission
**
** Service ID          : NA
**
** Description         : This service is called from Spi_AsyncInDirAccOrFifoMod
**                       to initiate job transmission or to Push the sequence in
**                       Queue in case for ongoing transmission.
**
** Sync/Async          : Asynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : Spi_SequenceType Sequence, boolean LblInitiateTx,
**                       uint8 LucQueueIndex, uint8 LucHWMemoryMode,
**                       Spi_JobType LddLowestQueueIndex
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : void
**
** Preconditions       : None.
**
** Global Variable     :
**                       Spi_GpFirstSeq, Spi_GpFirstJob, Spi_GaaJobResult,
**                       Spi_GaaJobQueue, Spi_GpFirstJobList,
**                       Spi_GblQueueStatus, Spi_GaaJobCount,
**                       Spi_GddQueueIndex, Spi_GusAllQueueSts.
**
** Function invoked    : Spi_InitiateJobTx, Spi_PushToQueue,
**                       SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used      : None
*******************************************************************************/

/* Implements SPI_ESDD_UD_055 */
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI194, AR_PN0063_FR_0077, AR_PN0063_FR_0078 */
/* Implements EAAR_PN0034_FR_0061 */
/* QAC Warning: START Msg(2:3227)-16 */
/* QAC Warning: START Msg(2:3206)-22 */
FUNC(void, SPI_PRIVATE_CODE) Spi_ProcessTransmission
(Spi_SequenceType Sequence, boolean LblInitiateTx, uint8 LucQueueIndex,
uint8 LucHWMemoryMode, Spi_JobType LddLowestQueueIndex)
/* END Msg(2:3227)-16 */
/* END Msg(2:3206)-22 */
{
  P2CONST(Spi_JobListType, AUTOMATIC, SPI_CONFIG_CONST) LpJobList;
  P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpSeqConfig;

  Spi_JobType LddJobListIndex;
  Spi_JobType LddReqJobListIndex;
  Spi_JobType LddCntrForJobsReq;
  Spi_JobType LddJob;
  /* QAC Warning: START Msg(2:2824)-17 */
  /* MISRA Violation: START Msg(4:0488)-4 */
  /* Get the pointer to the sequence structure */
  LpSeqConfig = Spi_GpFirstSeq + Sequence;
  /* END Msg(4:0488)-4 */
  /* END Msg(2:2824)-17 */
  /* Implements SPI_ESDD_UD_181 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* Copy a counter with number of jobs configured for the requested sequence */
  LddCntrForJobsReq = LpSeqConfig->ddNoOfJobs;
   /* END Msg(2:2814)-20 */
  /* Get the job list index of the last job of the sequence */
  LddJobListIndex = LpSeqConfig->ddJobListIndex;
   /* MISRA Violation: START Msg(4:0488)-4 */
  /* QAC Warning: START Msg(2:2824)-17 */
  /* Get the pointer to the job list */
  LpJobList = Spi_GpFirstJobList + LddJobListIndex;
  /* END Msg(2:2824)-17 */
  /* END Msg(4:0488)-4 */
  /* Get the index of the job list for the first job of the sequence */
  LddReqJobListIndex = LddJobListIndex + (LddCntrForJobsReq - SPI_ONE);

  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Disable relevant interrupts */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif

  if (((SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode) ||
      (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode)) &&
      ((SPI_QUEUE_EMPTY == (Spi_GblQueueStatus[LucQueueIndex])) ||
      ((SPI_QUEUE_FILLED == (Spi_GblQueueStatus[LucQueueIndex])) &&
      (Spi_GddQueueIndex[LucQueueIndex] == LddLowestQueueIndex))))
  {
    LblInitiateTx = SPI_TRUE;
  }
  else if((SPI_DIRECT_ACCESS_MODE_CONFIGURED == LucHWMemoryMode) ||
      (SPI_FIFO_MODE_CONFIGURED == LucHWMemoryMode))
  {
    LblInitiateTx = SPI_FALSE;
  }
  else
  {
    /* Do nothing */
  }

  if (SPI_TRUE == LblInitiateTx)
  {
    Spi_GddQueueIndex[LucQueueIndex] = LddLowestQueueIndex;

    if (SPI_QUEUE_EMPTY != Spi_GblQueueStatus[LucQueueIndex])
    {
      LddJob = Spi_GaaJobQueue[Spi_GddQueueIndex[LucQueueIndex]];
    }
    else
    {
      /* No action required */
    }
    do
    {
      /* Push the job list index into the queue */
      Spi_GaaJobQueue[Spi_GddQueueIndex[LucQueueIndex]] = LddJobListIndex;
      /* Set the Job status as SPI_JOB_QUEUED*/
      /* QAC Warning: START Msg(2:2814)-20 */
      Spi_GaaJobResult[LpJobList->ddJobIndex] = SPI_JOB_QUEUED;
      /* END Msg(2:2814)-20 */
      /* Push the job count into RAM */
      Spi_GaaJobCount[LpJobList->ddJobIndex] = LpJobList->ucJobCount;
      /* Increment the job list index */
      LddJobListIndex++;
      /* MISRA Violation: START Msg(4:0489)-3 */
      /*Increment the job list*/
      LpJobList++;
      /* END Msg(4:0489)-3 */
      Spi_GddQueueIndex[LucQueueIndex]++;
      /* Decrement the number of jobs */
      LddCntrForJobsReq--;
    }while (SPI_ZERO < LddCntrForJobsReq);


    if (SPI_QUEUE_EMPTY != Spi_GblQueueStatus[LucQueueIndex])
    {

      /* MISRA Violation: START Msg(4:2962)-11 */
      Spi_GaaJobQueue[Spi_GddQueueIndex[LucQueueIndex]] = LddJob;
      /* END Msg(4:2962)-11 */
    }
    else
    {
      Spi_GblQueueStatus[LucQueueIndex] = SPI_QUEUE_FILLED;

      /* MISRA Violation: START Msg(4:1891)-11 */
      /* MISRA Violation: START Msg(4:2984)-10 */
      /* MISRA Violation: START Msg(4:0400)-17 */
      Spi_GusAllQueueSts = (Spi_GusAllQueueSts |
                                 ((uint16)((uint8)(SPI_ONE << LucQueueIndex))));
      /* END Msg(4:1891)-11 */
      /* END Msg(4:2984)-10 */
      /* END Msg(4:0400)-17 */
      /* Point to the index of the last job pushed to the queue */
      Spi_GddQueueIndex[LucQueueIndex]--;

      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Enable relevant interrupts */
      SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif
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
       /* Initiate the transmission for that sequence */
      Spi_InitiateJobTx(LddReqJobListIndex);
      /* Check if critical section protection is required */
      #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
      /* Disable relevant interrupts */
      SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
      #endif
    }
  } /* End of queue is empty */
  else
  {
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    if (SPI_FALSE == LpSeqConfig->blIsHighPriority)
    #endif
    {
      Spi_PushToQueue(Sequence, LucHWMemoryMode);
    }
    #if (SPI_HW_PRIORITY_ENABLED == STD_ON)
    else
    {
      Spi_PushToQueue(Sequence, SPI_DIRECT_ACCESS_MODE_CONFIGURED);
      /* Change the queue status as FILLED */

      Spi_GblQueueStatus[LucQueueIndex] = SPI_QUEUE_FILLED;

    }
    #endif
  } /* End of Queue is not empty */
  /* Check if critical section protection is required */
  #if (SPI_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* Enable relevant interrupts */
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  #endif
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name       : Spi_CfgRegSettings
**
** Service ID          : NA
**
** Description         : This service is called from Spi_AsyncChannelRegSettings
**                       function for setting the configuration register when
**                       Spi_GblInitiateJobTx is false during the Asynchronous
**                       transmission.
**
** Sync/Async          : Asynchronous.
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : P2CONST(Spi_ChannelPBConfigType, AUTOMATIC,
**                                          SPI_CONFIG_CONST) LpPBChannelConfig,
**                       P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST)
**                                                                  LpJobConfig,
**                       Spi_HWUnitType LddHWUnit
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : void
**
** Preconditions       : None
**
** Global Variable     : Spi_GstHWUnitInfo, Spi_GpConfigPtr.
**
** Function invoked    : None
**
** Registers Used      : CSIGnSTCR0, CSIHnSTCR0, CSIGnCFG0, CSIHnCFG0,
**                     : CSIGnSTR0, CSIHnSTR0.
*******************************************************************************/

#if ((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
   ((SPI_HWUNIT_ASYNCHRONOUS == STD_ON) || (SPI_HW_PRIORITY_ENABLED == STD_ON))\
                                        || (SPI_FIFO_MODE == STD_ON))
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI_ESDD_UD_176 */
/* QAC Warning: START Msg(2:3227)-16 */
FUNC(void, SPI_PRIVATE_CODE)Spi_CfgRegSettings(
P2CONST(Spi_ChannelPBConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpPBChannelConfig,
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_CONST) LpJobConfig,
Spi_HWUnitType LddHWUnit)
/* END Msg(2:3227)-16 */
{
  P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo;
  P2VAR(Spi_MainUserRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainUserBaseAddr;
  #if (SPI_CSIG_CONFIGURED == STD_ON)
  P2VAR(Spi_CsigOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsigOsBaseAddr;
  #endif
  #if (SPI_CSIH_CONFIGURED == STD_ON)
  P2VAR(Spi_CsihOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpCsihOsBaseAddr;
  P2CONST(uint8, AUTOMATIC, SPI_CONFIG_DATA) LpChipSelect;
  uint8 LucVar;
  #endif
  /* MISRA Violation: START Msg(4:0759)-1 */
  Spi_DataAccess LunDataAccess1;
  /* END Msg (4:0759)-1 */

  LpHWUnitInfo = &Spi_GstHWUnitInfo[LddHWUnit];
  /* Get the main user base address */
  LpMainUserBaseAddr = LpHWUnitInfo->pHwMainUserBaseAddress;

  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  if (SPI_MAX_NUM_OF_CSIG > LddHWUnit)
  #endif
  {
    #if (SPI_CSIG_CONFIGURED == STD_ON)
    /* Clear the status register */
    /* QAC Warning: START Msg(2:3892)- 21 */
    /* QAC Warning: START Msg(2:2814)-20 */
    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                                      SPI_CSIG_CLR_STS_FLAGS)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainUserBaseAddr->ulMainSTR0,
      (uint32)SPI_ZERO, (uint32)(SPI_CSIG_CLR_STS_FLAGS),SPI_ASYNCTRANSMIT_SID)

    /* END Msg(2:2814)-20 */
    /* END Msg(2:3892)- 21 */
    /* MISRA Violation: START Msg (4:0316)-9*/
    /* Get the OS base address of the HW Unit */
    LpCsigOsBaseAddr = (Spi_CsigOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
    /* END Msg  (4:0316)-9*/

    /* To load configuration register, read the existing value to  */
    /* local union variable */
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess1.ulRegData = LpCsigOsBaseAddr->ulCSIGCFG0;
    /* END Msg(2:2814)-20 */

    /* Load the local variable with data width */
    LunDataAccess1.ucRegData4[SPI_THREE] =
                        (LunDataAccess1.ucRegData4[SPI_THREE] & SPI_DLS_MASK);
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess1.ucRegData4[SPI_THREE] =
     (LunDataAccess1.ucRegData4[SPI_THREE] | LpPBChannelConfig->ucDLSSetting);
    /* END Msg(2:2814)-20 */

    /* Load the local variable with configured direction */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Direction is LSB, set DIR bit */
      LunDataAccess1.ucRegData4[SPI_TWO] = (LunDataAccess1.ucRegData4[SPI_TWO]
                                           | SPI_SET_DIR_LSB);
    }
    else
    {
      /* Direction is MSB, reset DIR bit */
      LunDataAccess1.ucRegData4[SPI_TWO] = (LunDataAccess1.ucRegData4[SPI_TWO]
                                            & SPI_RESET_DIR_LSB);
    }
    /* Load back the value to configuration register */
    SPI_CSIGH_REG_WRITE(LpCsigOsBaseAddr->ulCSIGCFG0,
                                                LunDataAccess1.ulRegData)

    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpCsigOsBaseAddr->ulCSIGCFG0,
            LunDataAccess1.ulRegData,SPI_CSIGCFG0_MASK,SPI_ASYNCTRANSMIT_SID)

    #endif

  }
  #if ((SPI_CSIG_CONFIGURED == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON))
  else
  #endif
  {
    #if (SPI_CSIH_CONFIGURED == STD_ON)
    /* Clear the status register */
    /* QAC Warning: START Msg(2:3892)- 21 */
    /* QAC Warning: START Msg(2:2814)-20 */

    SPI_CSIGH_REG_WRITE(LpMainUserBaseAddr->usMainSTCR0,
                                                      SPI_CSIH_CLR_STS_FLAGS)
    SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
    LpMainUserBaseAddr->ulMainSTR0,(uint32)SPI_ZERO,
                 (uint32)(SPI_CSIH_CLR_STS_FLAGS),SPI_ASYNCTRANSMIT_SID)

    /* END Msg(2:2814)-20 */
    /* END Msg(2:3892)- 21 */
    /* MISRA Violation: START Msg (4:0316)-9*/
    /* Get the OS base address of the HW Unit */
    LpCsihOsBaseAddr = (Spi_CsihOsRegs *)LpHWUnitInfo->pHwOsBufferAddress;
    /* END Msg  (4:0316)-9*/
    /* QAC Warning: START Msg(2:2814)-20 */
    /* MISRA Violation: START Msg(4:0488)-4 */
    /* Get the value for multiple chip selects configured */
    LpChipSelect = (Spi_GpConfigPtr->pCSArray) + (LpJobConfig->ucCSArrayIndex);
    /* END Msg (4:0488)-4 */
    /* END Msg(2:2814)-20 */
    /* Load the number of chip selects */
    LucVar = LpJobConfig->ucNoOfCS;
    /*
     * To load configuration register, read the existing value to
     * local union variable
     */
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess1.ulRegData = LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect];
    /* END Msg(2:2814)-20 */

    /* Load the local variable with data width */
    LunDataAccess1.ucRegData4[SPI_THREE] =
                        (LunDataAccess1.ucRegData4[SPI_THREE] & SPI_DLS_MASK);
    /* MISRA Violation: START Msg(4:2962)-11 */
    /* QAC Warning: START Msg(2:2814)-20 */
    LunDataAccess1.ucRegData4[SPI_THREE] =
     (LunDataAccess1.ucRegData4[SPI_THREE] | LpPBChannelConfig->ucDLSSetting);
    /* END Msg (2:2814)-20 */
    /* END Msg (4:2962)-11 */
    /* Load the local variable with configured direction */
    if (SPI_TRUE == LpPBChannelConfig->blDirection)
    {
      /* Direction is LSB, set DIR bit */
      LunDataAccess1.ucRegData4[SPI_TWO] = (LunDataAccess1.ucRegData4[SPI_TWO]
                                                           | SPI_SET_DIR_LSB);
    }
    else
    {
      /* Direction is MSB, reset DIR bit */
      LunDataAccess1.ucRegData4[SPI_TWO] = (LunDataAccess1.ucRegData4[SPI_TWO]
                                                        & SPI_RESET_DIR_LSB);
    }
    do
    {
      /* Initialize CSIH configuration register */
      SPI_CSIGH_REG_WRITE(LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
                                                       LunDataAccess1.ulRegData)

      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(
      LpCsihOsBaseAddr->ulCSIHCFG[*LpChipSelect],
               LunDataAccess1.ulRegData,SPI_CSIHCFG_MASK, SPI_ASYNCTRANSMIT_SID)
      LucVar--;
      /* MISRA Violation: START Msg(4:0489)-3 */
      LpChipSelect++;
      /* END Msg(4:0489)-3 */
   }while (SPI_ZERO < LucVar);

    #endif /* End of #if (SPI_CSIH_CONFIGURED == STD_ON) */
  }
}
#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name      : Spi_CheckAndInvokeTxIsr
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked from
**                      Spi_HWMainFunction_Handling to check the Tx interrupt
**                      flag in polling mode and invoke Spi_TransmitISR function
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC,
**                                              SPI_PRIVATE_CONST) LpHWUnitInfo,
**                      Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Spi_TransmitISR, Spi_CheckAndInvokeRxIsr
**
** Registers Used     : EICn.
*******************************************************************************/

#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
                                             (SPI_DUAL_BUFFER_MODE == STD_ON)))
/* QAC Warning: START Msg(2:3227)-16 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* Implements SPI_ESDD_UD_171 */
FUNC(void, SPI_PRIVATE_CODE) Spi_CheckAndInvokeTxIsr
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode )
{
  /* END Msg(2:3227)-16 */
  /* QAC Warning: START Msg(2:2814)-20 */
  /* QAC Warning: START Msg(2:3892)- 21 */
  if (SPI_INT_FLAG_MASK ==
           ((*LpHWUnitInfo->pTxIntCntlAddress) & SPI_INT_FLAG_MASK))
  {

    /* Clear the interrupt flag */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pTxIntCntlAddress),
                         (SPI_CLR_INT_REQ));
    /* Transmit next data */
    Spi_TransmitISR(LddHWUnit, LucHWMemoryMode);
  /* END Msg(2:3892)- 21 */
  /* END Msg(2:2814)-20 */
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name      : Spi_CheckAndInvokeRxIsr
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked from
**                      Spi_HWMainFunction_Handling to check the Rx interrupt
**                      flag in polling mode and invoke Spi_ReceiveISR function.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : P2CONST(Spi_HWUnitInfo, AUTOMATIC,
**                                              SPI_PRIVATE_CONST) LpHWUnitInfo,
**                      Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : Spi_ReceiveISR
**
** Registers Used     : EICn.
*******************************************************************************/
/* Implements SPI_ESDD_UD_041 */
#if ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
     (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
        (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_TX_ONLY_MODE == STD_ON)))
/* QAC Warning: START Msg(2:3227)-16 */
#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
FUNC(void, SPI_PRIVATE_CODE) Spi_CheckAndInvokeRxIsr
(P2CONST(Spi_HWUnitInfo, AUTOMATIC, SPI_PRIVATE_CONST) LpHWUnitInfo,
Spi_HWUnitType LddHWUnit, uint8 LucHWMemoryMode )
{
/* END Msg(2:3227)-16 */
  /* QAC Warning: START Msg(2:2814)-20 */
  if (SPI_INT_FLAG_MASK ==
               (uint16)((*LpHWUnitInfo->pRxIntCntlAddress) & SPI_INT_FLAG_MASK))
  {
  /* END Msg(2:2814)-20 */
    /* Clear the interrupt flag */
    RH850_SV_MODE_ICR_AND(16, (LpHWUnitInfo->pRxIntCntlAddress),
                                              (SPI_CLR_INT_REQ));
    /* Read received data */
    Spi_ReceiveISR(LddHWUnit, LucHWMemoryMode);
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
** Function Name      : Spi_SetEojAndCsriBits
**
** Service ID         : Not Applicable
**
** Description        : This function is to Set the EOJ bit & CSRI bit to
**                      inactive state before the last job.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** Input Parameters   : P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                  LpJobConfig,
**                      P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA)
**                                                             LpMainOsBaseAddr,
**                      P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST)
**                                                                 LpDataAccess,
**                      Spi_NumberOfDataType LddNoOfTxBuffers,
**                      Spi_ChannelType LddNoOfChannels
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : None
**
** Registers Used     : CSIHnCTL1.
*******************************************************************************/
/* Implements SPI_ESDD_UD_060 */
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if ((SPI_LEVEL_DELIVERED == SPI_ZERO) || ((SPI_LEVEL_DELIVERED == SPI_TWO) && \
                                            (SPI_DIRECT_ACCESS_MODE == STD_ON)))

#define SPI_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/* QAC Warning: START Msg(2:3227)-16 */
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
FUNC(void, SPI_PRIVATE_CODE) Spi_SetEojAndCsriBits(
P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_PRIVATE_CONST) LpJobConfig,
P2VAR(Spi_MainOsRegs, AUTOMATIC, SPI_CONFIG_DATA) LpMainOsBaseAddr,
P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST) LpDataAccess,
Spi_NumberOfDataType LddNoOfTxBuffers, Spi_ChannelType LddNoOfChannels)
#else
FUNC(void, SPI_PRIVATE_CODE) Spi_SetEojBit(
P2VAR(Spi_DataAccess, AUTOMATIC, SPI_PRIVATE_CONST) LpDataAccess,
Spi_NumberOfDataType LddNoOfTxBuffers, Spi_ChannelType LddNoOfChannels)
#endif
/* END Msg(2:3227)-16 */
{ /* QAC Warning: START Msg(2:2814)-20 */
  #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  uint32 LulCxCTL1;
  #endif /* (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) */
  if ((SPI_ONE == LddNoOfTxBuffers) && (SPI_ONE == LddNoOfChannels))
  {
    LpDataAccess->Tst_ByteAccess.ucRegData3 = SPI_SET_EOJ;
    #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
    /* QAC Warning: START Msg(2:3892)- 21 */
    /* Check if CSIHnCSRI bit is configured true  */
    if (SPI_CSRI_FLAG_MASK == (uint8)(LpJobConfig->ulMainCtl1Value
                                      & SPI_CSRI_FLAG_MASK))
    /* END Msg(2:3892)- 21 */
    {
      /* Set CSRI bit of CSIHnCTL1 register before the last job */
      /* MISRA Violation: START Msg(4:0402)-13 */
      LulCxCTL1 = (LpMainOsBaseAddr->ulMainCTL1 | (~SPI_CSRI_AND_MASK));
      SPI_CSIGH_REG_WRITE(LpMainOsBaseAddr->ulMainCTL1, LulCxCTL1)


      SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(LpMainOsBaseAddr->ulMainCTL1,
          LulCxCTL1, SPI_CTLREG_32_BIT_MASK, SPI_SYNCTRANSMIT_SID)

      /* END Msg(4:0402)-13 */
  /* END Msg(2:2814)-20 */
    }
    else
    {
      /* No action required */
    }
    #endif /* #if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF ) */
  }
  else
  {
    /* No action required */
  }
}

#define SPI_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif
#endif

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
