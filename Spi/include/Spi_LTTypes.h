/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_LTTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions for link time parameters           */
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
 * V1.0.1:  21-Sep-2012  : As per SCR 021, IMR register address pointers and
 *                         mask values changed from uint8 to uint16.
 *
 * V1.0.2:  27-Nov-2012  : As per SCR 042, macro SPI_HWUNIT_ASYNCHRONOUS check
 *                         is added.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 072, the following changes are made
 *                         1.Pre-compile condition SPI_HW_PRIORITY_ENABLED is
 *                           added for structure elements
 *                           pTxCancelIntCntlAddress, pTxCancelImrAddress.
 *                         2.Macros SPI_DLS_MASK,  SPI_NO_JOB, SPI_NO_SEQ
 *                           SPI_SET_JOBE are added and pre-compile conditions
 *                           are updated.
 *                         3.Copyright is updated.
 *
 * V1.1.1:  20-May-2013  : As Per SCR 168 for the mantis issue #9319, the
 *                         following change is made:
 *                         1.CSIH structure STag_Spi_CsihOsRegs is updated for
 *                           baud rate registers.
 *                         2.Macro SPI_CSIH_BRS_SELECT_MASK is added for
 *                           baud rate selection.
 *
 * V1.2.0:  26-Jul-2013  : As per CR 219, for mantis issue #8821, #1290 and
 *                         #12397 following changes are made:
 *                          1. New structures 'Spi_DualBufferCurrentCommData',
 *                             Spi_SyncSeqEndFuncType are added for Dual Buffer
 *                             Mode and Synchronous End Notification.
 *
 * V1.2.1:  06-Aug-2013  : As per CR 225, Following changes are made:
 *                          1. As part of SVN merge activity the project name
 *                             and environment section is updated.
 *                          2. Structure STag_Spi_CsihUserRegs and
 *                             STag_Spi_CsihOsRegs are updated.
 *
 * V1.2.2:  05-Sep-2013  : As per CR 243 for the mantis issue #8421, the
 *                         following changes are made:
 *                          1. The structures STag_Spi_JobFuncType,
 *                             STag_Spi_SeqEndFuncType,
 *                             STag_Spi_SyncSeqEndFuncType and
 *                             STag_Spi_SeqStartFuncType are removed from
 *                             Global data Types section.
 *                          2. The Global data Spi_GstJobFunc,
 *                             Spi_GstSeqEndFunc, Spi_GstSyncSeqEndFunc
 *                             and Spi_GstSeqStartFunc are removed from Extern
 *                             declarations for Global Data section.
 *
 * V1.2.3:  23-Oct-2013  : As per CR 256 for the mantis issue #16631, the
 *                         following changes are made:
 *                          1. Pre-compile check is updated for
 *                             'Spi_GaaJobQueue'.
 *
 * V1.2.4:  15-Jan-2014  : As per CR 330 for the mantis issue #9799, the
 *                         following changes are made:
 *                          1. The Structure STag_Spi_HWUnitInfo is updated.
 *                          2. Copyright information is updated.
 *                          3. Updated as per C coding guideline.
 *
 * V1.2.5:  05-Feb-2014  : As per CR 398 for the mantis issue #19208,
 *                         Header file updated as part of merge activity.
 *
 * V1.2.6:  28-Mar-2014  : As per CR 424 for the mantis issue #18651 and #20316,
 *                         following macros are removed: SPI_INVALID_HWUNIT,
 *                         SPI_MAX_HW_UNIT, SPI_TX_RX_BUFFER_PTR and
 *                         'RELOC_INTR_VECT_MASK'.
 *
 * V1.2.7:  05-May-2014  : As per CR 507 for mantis issues #20849, 21647 and
 *                         #9799 following changes are made:
 *                         1. The macro 'SPI_CSRI_FLAG_MASK' is added to mask
 *                            the CSIHnCSRI bit of CTL1 register.
 *                         2. The macro 'SPI_DMA_BLOCK_SETTINGS' is added to
 *                            switch DMA type two to Block mode when the
 *                            configured mode is FIFO.
 *                         3. The macros 'SPI_LOOPBACK_ENABLE',
 *                            'SPI_LOOPBACK_CNTRL2_VALUE',
 *                            'SPI_LOOPBACK_CSIH_CNTRL2_VALUE',
 *                            'SPI_LOOPBACK_DLS_SETTING',
 *                            'SPI_LOOPBACK_MEMORY_SETTING',
 *                            'SPI_LOOPBACK_CSIH_BRS0_VALUE',
 *                            'SPI_LOOPBACK_ERROR_MASK',
 *                            'SPI_LOOPBACK_SET_MEMORY_ACCESS',
 *                            'SPI_LOOPBACK_DATA' and
 *                            'SPI_LOOPBACK_VALIDATE_MASK' are added for self
 *                             test functionality.
 *                         4. Value of macro 'SPI_CSIG_CSIH_BUSY' is updated.
 *                         5. Pre-compile check SPI_LOOPBACK_SELFTEST == STD_ON
 *                            is updated for the structure Spi_CsihOsRegs to
 *                            support loop back functionality.
 *                         6. Macro SPI_CLEAR_PENDING_INTR_MASK is deleted.
 *                         7. Updated as per C coding guideline.
 *                         8. The values of following Macros:
 *                            'SPI_DMA_BLOCK_SETTINGS',
 *                            'SPI_TYPE_UINT8 SPI_TYPE_UINT16',
 *                            'SPI_DIRECT_ACCESS_MODE_CONFIGURED',
 *                            'SPI_FIFO_MODE_CONFIGURED',
 *                            'SPI_DUAL_BUFFER_MODE_CONFIGURED',
 *                            'SPI_TX_ONLY_MODE_CONFIGURED',
 *                            'SPI_LOOPBACK_CNTRL2_VALUE',
 *                            'SPI_LOOPBACK_CSIH_CNTRL2_VALUE' and
 *                            'SPI_LOOPBACK_MEMORY_SETTING' are updated as per
 *                             its data width.
 *
 * V1.2.8:  08-Jul-2014  : As per CR 550 for mantis issues #22312, #22324 and
 *                         #22328 following changes are made:
 *                         1. Pointers to registers addresses are declared with
 *                            volatile declaration.
 *                         2. New macros 'SPI_CSIG_CLR_STS_FLAGS' and
 *                            'SPI_CSIH_CLR_STS_FLAGS' are added to access to
 *                            the registers CSIGnSTCR0 and CSIHnSTCR0.
 *                         3. Pre-compile check is updated for structure
 *                            'STag_Spi_CsihUserRegs' and Spi_GaaJobQueue.
 *                         4. Following macro are removed:
 *                            SPI_LOOPBACK_MEMORY_SETTING,
 *                            SPI_LOOPBACK_ERROR_MASK,
 *                            SPI_LOOPBACK_SET_MEMORY_ACCESS and
 *                            SPI_LOOPBACK_VALIDATE_MASK.
 *
 * V1.2.9:  24-Aug-2014  : As per CR 601 for mantis issues #22289 following
 *                         changes are made:
 *                         1. New macros 'SPI_FIFO_BUFFER_EMPTY',
 *                            'SPI_FIFO_BUFFER_FULL', 'SPI_FIFO_BUFFER_UNINIT',
 *                            'SPI_FIFO_TX_INDEX', 'SPI_FIFO_RX_INDEX' and
 *                            'SPI_FIFO_SIZE'.
 *                         2. New structure element 'pCurrentRxData',
 *                            'pNextTxData', 'pCurrentRxChannelList'
 *                            'pCurrentTxChannelList', 'ddNoOfTxBuffers',
 *                            'ddNoOfRxBuffers', 'ddNoOfRxChannels'and
 *                            'ddNoOfTxChannels' are added in
 *                            'Spi_FifoCurrentCommData'.
 *                         3. Suffix 'U' is added for all scalar values.
 *                         4. MISRA C RULE VIOLATION section is added.
 *                         5. MISRA rules violation messages are added.
 *                         6. As per mantis #25333, definition for
 *                            SPI_DMA_32BIT_RX_SETTINGS and
 *                            SPI_DMA_32BIT_TX_SETTINGS added.
 *
 * V1.2.10:   10-Feb-2015 : As a part of Merging Activity, for the mantis#26024
 *                          following changes are made:
 *                          1. As per CR 01, for mantis #19850 AUTOSAR SWS
 *                            requirements are mapped for requirements tracing.
 *                          2. File is updated for C coding guidelines.
 *                          3. Copyright Information is Updated.
 *
 * V1.2.11:   07-May-2015 : As per mantis #27772, definition for
 *                          SPI_DMA_32BIT_RX_SETTINGS and
 *                          SPI_DMA_32BIT_TX_SETTINGS are added.
 * V1.2.12:   18-Dec-2015 : As part of P1x V4.00.05 Release,
 *                          Following changes are made
 *                          1.As per ticket ARDAAAE-1515, added a new structure
 *                            'STag_Spi_CsihBrsRegs' and updated
 *                            STag_Spi_CsihOsRegs structure for the declaration
 *                            of usCSIHBRS registers in order make baudrate
 *                             registers access in 16bits instead of 32bits.
 *                          2. As per Jira#ARDAAAE-1514, Pre Compile directives
 *                             for errors are added as a part of internal
 *                             Diagnosis implementation.
 *                          3. As per Jira#ARDAAAE-1514, ucHWUnit is added in
 *                             Spi_HWUnitInfo structure for Hardware unit
 *                             identification, as a part of internal Diagnosis
 *                             implementation.
 *                          4.As per ticket ARDAAAE-1452, DMA settings for 8 bit
 *                            and 32 bit are removed.
 *                          5.As per Jira#ARDAAAE-1533, structures and macros
 *                            required for self test are added.
 *                          6.As per Jira#ARDAAAE-1514, Added the macros for
 *                            clearing the hardware errors.
 *                          7.As per Jira#ARDAAAE-1558, For software metrics
 *                            improvement, added SPI_IB_MODE Macro.
 *                          8.SPI_IB_MODE declaration updated to fix compilation
 *                            errors.
 *                          9.Added usBufferCount to the Spi_FifoCurrentCommData
 *                            structure as part of metrics improvement.
 * V1.2.13:   07-Feb-2016 : As part of P1x V4.01.00 Release, following changes
 *                          are made:
 *                          1.As per ticket ARDAAAE-1565,Volatile declaration is
 *                            added to Hardware registers.
 *                          2.As per ticket ARDAAAE-1486,storage specifier
 *                            is modified from AUTOMATIC to TYPEDEF for
 *                            Config Data which is allocated in ROM
 *                          3.Mapping of memory section for global or static
 *                            variables are updated as per AUTOSAR requirement
 *                            MEMMAP022 as per ticket ARDAAAE-1672.
 *                          4.The value of Macro SPI_NO_SEQ is modified to uint8
 *                            value(0xFF) to fix QAC warning.
 * V1.2.14:  24-Oct-2016 : As part of P1x V4.01.01 release, following changes
 *                         are made.
 *                         1.Updated the type of MACRO definitions to fix
 *                           QAC warnings.
 *                         2.Updates the value of SPI_LOOPBACK_DLS_SETTING macro
 *                           for specify the parity and added macro
 *                           SPI_LOOPBACK_ERROR as per ticket ARDAAAE-1609.
 *                         3.As per JIRA ticket ARDAAAE-1568, macro SPI_SET_MBS
 *                           is added to set MBS bit of register CSIGnCTL0 is
 *                           set to one.
 *                         4.Updated macro definitions to fix QAC warnings.
 *                         5.As part of ARDAAAE-1908,removed AR 3.2.2
 *                           related version checks, removed the
 *                           the switch
 *                           #if(SPI_AR_VERSION == SPI_AR_HIGHER_VERSION) and
 *                           removed macros related to DMA_TYPE_ONE.
 *                         6.As part of ARDAAAE-1672, updated INIT policy
 *                           of memory sections from NOINIT to NO_INIT.
 *                         7.Removed unnecessary macro(SPI_HUNDRED).
 *                         8.As part of ARDAAAE-1828 JIRA ticket fix,
 *                           added macros SPI_CTL_32BIT_REG_VAL,
 *                           SPI_CTL_16BIT_REG_DEINIT,SPI_CTL_8BIT_REG_MASK
 *                           SPI_CTL2_16BIT_REG_DEINIT,
 *                           SPI_MCTL0_16BIT_REG_DEINIT,SPI_DMA_DEINIT.
 *                         9.Removed unused type definition of
 *                           STag_Spi_BitPattern.
 *                         10.As part of ARDAAAE-1701, updated the
 *                            macro value ECC_CTL_ECER1F_ECER2F_CLEAR.
 *                         11.Added macros SPI_CFG_REG_COUNT, SPI_BRS_REG_COUNT.
 *                         12.Added mask values for registers as part of
 *                            ARDAAAE-1663.
 *                         13.As part of ARDAAAE-1980, removed the compiler
 *                            switches above the structure element usCSIHMCTL0
 *                            for generation of its address in all memory
 *                            modes.
 *                         14.As part of ARDAAAE-2059, macros
 *                            SPI_DMA_HARDWARE_TRIGGER and SPI_DMA_DRS_MLE_MASK
 *                            are added.
 *                         15.As part of ARDAAAE-2092, renamed SPI_STCR0_VAL to
 *                            SPI_CSIH_STCR0_VAL and added SPI_CSIG_STCR0_VAL.
 *                         16.As part of ARDAAAE-2107, removed the macro
 *                            SPI_CSIHMCTL0_MASK_1 and added
 *                            SPI_CSIG_CTLREG_MASK.
 * V1.2.15:  15-Feb-2017 : Following changes are made:
 *                         1.As part of ARDAAAE-2277,following changes are made:
 *                              a. Structure tag is added for Tst_DmaAddr
 *                                 and Tst_ByteAccess.
 *                              b. 'U' is appended for MACRO definitions
 *                                 wherever applicable.
 *                              c. Naming convention corrected from
 *                                 usReserved1 to ulReserved1
 *                         2.Copyright information is updated.
 */
/******************************************************************************/

#ifndef SPI_LTTYPES_H
#define SPI_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Spi.h"
#include "Spi_Cbk.h"
#include "RH850_Types.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Release version information */

#define SPI_LTTYPES_AR_RELEASE_MAJOR_VERSION   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_LTTYPES_AR_RELEASE_MINOR_VERSION   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_LTTYPES_AR_RELEASE_REVISION_VERSION SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_LTTYPES_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_LTTYPES_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
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

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0750)  A union type specifier has been define           */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : To access the lower and higher order byte individually and */
/*                 read/write the values to register.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0750)-2 and                           */
/*                 END Msg(4:0750)-2 tags in the code.                        */
/******************************************************************************/
/**                         QAC Warnings                                     **/
/******************************************************************************/

/* 1.  QAC Warning:                                                           */
/* Message       : (2:1314) A struct or union tag has been defined within the */
/*                 definition of another struct or union.                     */
/* Rule          : NA                                                         */
/* Justification : Spi_DataAccess and  Spi_DmaAddr are union type.In code, for*/
/*                 better efficiency,optimization and accessibility the       */
/*                 registers access is split as 8-bit,16-bit.                 */
/*                 Hence the structure defined inside union cannot            */
/*                 be avoided.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:1314)-1 and                           */
/*                 END Msg(2:1314)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Macros to avoid hard-coded numbers */

#define SPI_DBTOC_VALUE (uint32)(((uint32)SPI_VENDOR_ID_VALUE << 22U) | \
                                  ((uint32)SPI_MODULE_ID_VALUE << 14U) | \
                                  ((uint32)SPI_SW_MAJOR_VERSION_VALUE << 8U) | \
                                  ((uint32)SPI_SW_MINOR_VERSION_VALUE << 3U))

#define SPI_INVALID_DMAUNIT           (uint8)0xFFU
#define SPI_CSIG_CSIH_BUSY            (uint32)0x00000080UL
#define SPI_PORT_REG_MASK             (uint32)0xFFFF0000UL
#define SPI_CTL_32BIT_REG_VAL         (uint32)0x00000000UL
#define SPI_CTL_16BIT_REG_DEINIT      (uint16)0x0000U
#define SPI_BCTL0_SET_SCE             (uint8)0x00U
#define SPI_CTL2_16BIT_REG_DEINIT     (uint16)0xE000U
#define SPI_MCTL0_16BIT_REG_DEINIT    (uint16)0x001FU

/* Mask for 32 bit control Register */
#define SPI_CTLREG_32_BIT_MASK        (uint32)0xFFFFFFFFUL
#define SPI_CTLREG_8_BIT_MASK         (uint8)0xE1U
#define SPI_CSIHMCTL1_MASK            (uint32)0x007F007FUL
#define SPI_CSIHMCTL2_MASK            (uint32)0x80FF007FUL
#define SPI_CSIGBCTL0_MASK            (uint8)0x01U
#define SPI_CSIHMRWP0_MASK            (uint32)0x007F007FUL
#define SPI_CSIHTX0W_MASK             (uint32)0xE0FFFFFFUL
/* Mask for CSIHMCTL0 Register */
#define SPI_CSIHMCTL0_MASK            (uint16)0x031FU
#define SPI_CSIGCFG0_MASK             (uint32)0x3F050000UL
#define SPI_CSIHCFG_MASK              (uint32)0xFF0FFFFFUL
#define SPI_CTLREG_16_BIT_MASK        (uint16)0xFFFFU
#define SPI_CSIGTX0W_MASK             (uint32)0x2000FFFFUL
#define SPI_CSIHBRS_MASK              (uint16)0x0FFFU
#define SPI_LOOPBACK_CSIG_MASK        (uint32)0xFFFFFFBFUL
#define SPI_LOOPBACK_CSIH_MASK        (uint32)0xFFFFFFFFUL
#define SPI_CSIGHSTR0_VAL             (uint32)0x00000010UL
#define SPI_CSIGHSTR0_MASK            (uint32)0xFFFFFF90UL
#define SPI_CSIH_STCR0_VAL            (uint16)0x400BU
#define SPI_CSIG_STCR0_VAL            (uint16)0x000BU
#define SPI_CSIG_CTLREG_MASK          (uint32)0x000300AEUL
/* Macro for DMA transmission */
#if (SPI_DMA_MODE_ENABLE == STD_ON)

/* Mask for SELCSIHDMA Register */
#define SPI_SELECT_CSIH_DMA_MASK      (uint8)0x0FU
/* Mask for DTFR Register */
#define SPI_DTFR_MASK                 (uint32)0x000000FFUL
/* Mask for DTCT Register */
#define SPI_DTCT_MASK                 (uint32)0x0C1FFFFFUL
/* Mask for DCEN Register */
#define SPI_DCEN_MASK                 (uint32)0x00000001UL
#define SPI_DMA_DEINIT                (uint32)0x00000000UL
#define SPI_DMA_DCEN_ENABLE           (uint32)0x00000001UL
#define SPI_DMA_DCEN_DISABLE          (uint32)0x00000000UL
#define SPI_DMA_16BIT_RX_SETTINGS     (uint32)0x04004044UL
#define SPI_DMA_16BIT_TX_SETTINGS     (uint32)0x04004104UL
#define SPI_DMA_STR                   (uint32)0x00000001UL
#define SPI_DMA_STR_REQ               (uint32)0xFBFFFFFFUL
#define SPI_DMA_DISABLE               (uint32)0x00000000UL
#define SPI_DMA_DRQ_CLEAR             (uint32)0x00000001UL
#define SPI_DMA_STR_CLEAR             (uint32)0x00000010UL
#define SPI_DMA_FIXED_TX_SETTINGS     (uint32)0x00000040UL
#define SPI_DMA_INV_TX_SETTINGS       (uint32)0xFFFFFFBFUL
#define SPI_DMA_FIXED_RX_SETTINGS     (uint32)0x00000100UL
#define SPI_DMA_INV_RX_SETTINGS       (uint32)0xFFFFFEFFUL
#define SPI_DMA_ONCE                  (uint32)0xFFFFDFFFUL
#define SPI_DMA_TC_CLEAR              (uint32)0x00000010UL
#define SPI_DMA_HARDWARE_TRIGGER      (uint32)0x04000000UL
#define SPI_DMA_DRS_MLE_MASK          (uint32)0xFBFFDFFFUL
#if (SPI_FIFO_MODE == STD_ON)
#define SPI_DMA_BLOCK_SETTINGS        (uint32)0x00000001UL
#endif
#endif

/* Macros to avoid hard-coded numbers */
#define SPI_SET_BTST                  (uint8)0x80U
#define SPI_SET_EDL                   (uint8)0x20U
#define SPI_RESET_EDL                 (uint8)0xDFU
#define SPI_SET_EOJ                   (uint8)0x40U
#define SPI_SET_CIREEOJ               (uint8)0xC0U
#define SPI_SET_PWR                   (uint8)0x80U
#define SPI_SET_MBS                   (uint8)0x01U
#define SPI_CHECK_PWR                 (uint8)0x80U
#define SPI_SET_JOBE                  (uint8)0x02U
#define SPI_SET_DIR_LSB               (uint8)0x04U
#define SPI_RESET_DIR_LSB             (uint8)0xFBU
#define SPI_RESET_PWR                 (uint8)0x7FU
#define SPI_SET_DIRECT_ACCESS         (uint8)0xE1U
#define SPI_SET_MEMORY_ACCESS         (uint8)0xE0U
#define SPI_NO_SEQ_NOTIFICATION       (uint8)0xFFU
#define SPI_NO_JOB_NOTIFICATION       (uint16)0xFFFFU
#define SPI_INT_FLAG_MASK             (uint16)0x1000U
#define SPI_CSIG_CLR_STS_FLAGS        (uint16)0x000BU
#define SPI_CSIH_CLR_STS_FLAGS        (uint16)0xC10BU
#define SPI_TSF_SET                   (uint32)0x00000080UL
#define SPI_SET_SLIT                  (uint32)0x00010000UL
/* Macro for clearing pending interrupt */
#define SPI_CLR_INT_REQ               (uint16)0xEFFFU
#define SPI_CSRI_MASK                 (uint32)0x00000010UL
#define SPI_CSRI_AND_MASK             (uint32)0xFFFFFFEFUL
#define SPI_CSIH_PRE_MASK             (uint16)0xE000U
#define SPI_CSIH_BRS_MASK             (uint16)0x0FFFU
#define SPI_CSRI_FLAG_MASK            (uint8)0x10U



#define SPI_TYPE_UINT8                (uint8)0x00U
#define SPI_TYPE_UINT16               (uint8)0x01U

/* Queue status macros */
#define SPI_QUEUE_EMPTY               (boolean)0
#define SPI_QUEUE_FILLED              (boolean)1

#define SPI_HW_BUSY                   (uint32)0x00000080UL
#define SPI_ERROR_MASK                (uint32)0x0000000BUL
#define SPI_EDL_MASK                  (unit8)0xEFU

#define SPI_DIRECT_ACCESS_MODE_CONFIGURED (uint8)0x00U
#define SPI_FIFO_MODE_CONFIGURED          (uint8)0x01U
#define SPI_DUAL_BUFFER_MODE_CONFIGURED   (uint8)0x02U
#define SPI_TX_ONLY_MODE_CONFIGURED       (uint8)0x03U

 #if ((SPI_INTERNAL_RW_BUFFERS == STD_ON) && \
      ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) || \
      (SPI_LEVEL_DELIVERED == SPI_ZERO)))
   #define SPI_IB_MODE STD_ON
#else
   #define SPI_IB_MODE STD_OFF
#endif

#define SPI_OVE_ERR                       (uint32)0x00000001UL
#define SPI_PE_ERR                        (uint32)0x00000002UL
#define SPI_DCE_ERR                       (uint32)0x00000008UL
#define SPI_OFE_ERR                       (uint32)0x00004000UL

#define SPI_OVE_ERR_CLR                  (uint32)0x00000001UL
#define SPI_PE_ERR_CLR                   (uint32)0x00000002UL
#define SPI_DCE_ERR_CLR                  (uint32)0x00000008UL
#define SPI_OFE_ERR_CLR                  (uint32)0x00004000UL

#define SPI_PARITY_DCC_ERR                (uint32)0x0000000AUL
#define SPI_PARITY_DCC_ERR_CLR            (uint16)0x0000FFF5U
#define SPI_OVRFLW_OVRRUN_ERR             (uint32)0x00004001UL
#define SPI_OVRFLW_OVRRUN_ERR_CLR         (uint16)0x0000BFFEU

#define SPI_CFG_REG_COUNT                 (uint8)0x08U
#define SPI_BRS_REG_COUNT                 (uint8)0x04U
/* Macro for Relocating interrupt vector table */
#define SPI_DLS_MASK                      (uint8) 0xF0U
#define SPI_NO_JOB                        (Spi_JobType)0xFFFF
#define SPI_NO_SEQ                        (Spi_SequenceType)0xFF

/* Macro for select baud rate register */
#define SPI_CSIH_BRS_SELECT_MASK          (uint32)0xC0000000UL

/* Received data status macros */
#define SPI_RX_DATA_NORMAL                    (boolean)0
#define SPI_RX_DATA_QUEUED                    (boolean)1

#define SPI_CSIH_LOOPBACK_ENABLE          (uint32)0x00000048UL
#define SPI_CSIG_LOOPBACK_ENABLE          (uint32)0x00000008UL
#define SPI_LOOPBACK_DLS_SETTING          (uint32)0x18000000UL
#define SPI_LOOPBACK_CNTRL2_VALUE         (uint16)0x2640U
#define SPI_LOOPBACK_CSIH_CNTRL2_VALUE    (uint16)0x2000U
#define SPI_LOOPBACK_CSIH_BRS0_VALUE      (uint16)0x0640U
#define SPI_LOOPBACK_DATA                 (uint8)0xA5U
#define SPI_LOOPBACK_ERROR                (uint8)0xFFU

/* Macros for Extended FIFO Transmission */
#define SPI_FIFO_BUFFER_EMPTY         (uint8)0x0U
#define SPI_FIFO_BUFFER_FULL          (uint8)0x1U
#define SPI_FIFO_BUFFER_UNINIT        (uint8)0x2U

#define SPI_FIFO_TX_INDEX             (uint8)0x0U
#define SPI_FIFO_RX_INDEX             (uint8)0x1U
#define SPI_FIFO_SIZE                 (uint8)0x80U

#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)
#define SET_EC1EDIC_EC2EDIC          0x18U
#define SET_TMC_BITS                 0x8093U
#define SET_TEST_DISABLE             0x8000U
#define CTL_ERR_FLAG                 (uint32)0x6UL
#define CTL_1BIT_ERR_FLAG            (uint32)0x2UL
#define CTL_2BIT_ERR_FLAG            (uint32)0x4UL
#define CTL_1BIT_ERRCLR_FLAG         (uint32)0x200UL
#define CTL_2BIT_ERRCLR_FLAG         (uint32)0x400UL
#define CTL_ERRCLR_FLAG              (uint32)0x600UL
#define RAM_INITIALIZE               0x0U
#define TRC_ERDB_INITIALIZE          0x0U
#define ALL_ZERO_PATTERN             0x0U
#define ALL_ONE_PATTERN              0xFFFFFFFFU
#define TWO_BIT_PATTERN              0x3U
#define ECC_CTL_ECEMF_SET            0x1UL
#define ECC_CTL_ECER1F_ECER2F_CLEAR  0x00000600UL
#define SPI_DATAWORDLENGTH            0x20U
#endif
#endif
/* Structure for main hardware user registers */
typedef struct STag_Spi_MainUserRegs
{
  uint8  volatile ucMainCTL0;
  uint8  volatile ucReserved1;
  uint16 volatile usReserved2;
  uint32 volatile ulMainSTR0;
  uint16 volatile usMainSTCR0;
} Spi_MainUserRegs;

/* Structure for main hardware OS registers */
typedef struct STag_Spi_MainOsRegs
{
  uint32 volatile ulMainCTL1;
  uint16 volatile usMainCTL2;
} Spi_MainOsRegs;

#if (SPI_CSIH_CONFIGURED == STD_ON)
/* Structure for CSIH hardware user registers */
typedef struct STag_Spi_CsihUserRegs
{
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) || \
                                                   (SPI_FIFO_MODE == STD_ON))
  uint32 volatile ulCSIHMCTL1;
  uint32 volatile ulCSIHMCTL2;
  #endif
  uint32 volatile ulCSIHTX0W;
  uint16 volatile usCSIHTX0H;
  uint16 volatile usReserved1;
  uint32 volatile ulCSIHRX0W;
  uint16 volatile usCSIHRX0H;
  uint16 volatile usReserved2;
  #if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) || \
                                                      (SPI_FIFO_MODE == STD_ON))
  uint32 volatile ulCSIHMRWP0;
  #endif
} Spi_CsihUserRegs;

/* Structure for CSIH Baudrate registers */
typedef struct STag_Spi_CsihBrsRegs
{
 uint16 volatile usCSIHBRS;
 uint16 volatile usReserved1;
 }Spi_CsihBrsRegs;

/* Structure for CSIH hardware OS registers */
typedef struct STag_Spi_CsihOsRegs
{
  uint16 volatile usCSIHMCTL0;
  uint16 volatile usReserved4;
  uint32 volatile ulCSIHCFG[SPI_EIGHT];
  uint32 volatile ulReserved1;
  Spi_CsihBrsRegs stCSIHBRS[SPI_FOUR];
} Spi_CsihOsRegs;

/* Structure for  hardware ECC registers */
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)
typedef struct STag_Spi_TrcReg
{
  uint8 volatile  ucSynd;
  uint8 volatile  ucHord;
  uint8 volatile  ucEcrd;
  uint8 volatile  ucErdb;
}Spi_EccTrcReg;

typedef struct STag_Spi_EccRegs
{
  uint32  volatile ulEccCTL;
  uint16 volatile usEccTmc;
  uint16 volatile usReserved1;
  Spi_EccTrcReg stEccTrc;
  uint32 volatile ulEccTed;
} Spi_EccRegs;
#endif
#endif

#if (SPI_CSIG_CONFIGURED == STD_ON)
/* Structure for CSIG hardware user registers */
typedef struct STag_Spi_CsigUserRegs
{
  uint8  volatile ucCSIGBCTL0;
  uint8  volatile ucReserved1;
  uint16 volatile usReserved2;
  uint32 volatile ulCSIGTX0W;
  uint16 volatile usCSIGTX0H;
  uint16 volatile usReserved3;
  uint16 volatile usCSIGRX0;
} Spi_CsigUserRegs;

/* Structure for CSIG hardware OS registers */
typedef struct STag_Spi_CsigOsRegs
{
  uint32 volatile ulCSIGCFG0;
} Spi_CsigOsRegs;
#endif

/* Structure for hardware unit information */
typedef struct STag_Spi_HWUnitInfo
{
  /* User Base address of common registers */
  P2VAR(Spi_MainUserRegs, TYPEDEF, SPI_CONFIG_DATA)pHwMainUserBaseAddress;
  /* OS Base address of common registers */
  P2VAR(Spi_MainOsRegs, TYPEDEF, SPI_CONFIG_DATA)pHwMainOsBaseAddress;
#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ONE || SPI_ECC_SELFTEST == SPI_TWO)
  P2VAR(Spi_EccRegs, TYPEDEF, SPI_CONFIG_DATA)pEccBaseAddress;
#endif
#endif
  P2VAR(void, TYPEDEF, SPI_CONFIG_DATA)pHwUserBufferAddress;
  P2VAR(void, TYPEDEF, SPI_CONFIG_DATA)pHwOsBufferAddress;
  /* Address for receive interrupt control registers (TIR) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pRxIntCntlAddress;
  /* Address for transmit interrupt control registers (TIC) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pTxIntCntlAddress;
  /* Address for transmit interrupt control registers (TIRE) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pErrorIntCntlAddress;
  #if ((((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) && \
        (SPI_CANCEL_API == STD_ON)) || (SPI_HW_PRIORITY_ENABLED == STD_ON))
  /* Address for transmit cancel interrupt control registers (TIJC) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pTxCancelIntCntlAddress;
  /* Address for transmit cancel IMR registers (TIJC) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pTxCancelImrAddress;
  #endif
  #if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
  /* Address for receive IMR registers (TIR) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pRxImrAddress;
  /* Address for transmit IMR registers (TIC) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pTxImrAddress;
  /* Address for error IMR registers (TIRE) */
  P2VAR(volatile uint16, TYPEDEF, SPI_CONFIG_DATA)pErrorImrAddress;
  /* Mask for receive IMR register */
  uint16 usRxImrMask;
  /* Mask for transmit IMR register */
  uint16 usTxImrMask;
  /* Mask for error IMR register */
  uint16 usErrorImrMask;
  #endif
  #if ((((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON)) && \
        (SPI_CANCEL_API == STD_ON)) || (SPI_HW_PRIORITY_ENABLED == STD_ON))
  /* Mask for transmit cancel IMR register */
  uint16 usTxCancelImrMask;
  #endif
  /* Hardware unit Configured */
  uint8 ucHWUnit;
  /* Whether the HW Unit is synchronous (SPI_TRUE) or
     asynchronous (SPI_FALSE) */
  #if (SPI_LEVEL_DELIVERED == SPI_TWO)
  boolean blIsSynchronous;
  #endif
} Spi_HWUnitInfo;

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
/* Structure for storing current status of SPI communication */
typedef struct STag_Spi_CurrentCommData
{
  /* Pointer to current data to be received */
  P2VAR(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA) pCurrentRxData;
  /* Pointer to next data to be transmitted */
  P2CONST(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA) pNextTxData;
  /* Pointer to the current channel list to be transmitted */
  P2CONST(Spi_ChannelType, TYPEDEF, SPI_CONFIG_CONST) pCurrentTxChannelList;
  /* Pointer to the current channel list to be received */
  P2CONST(Spi_ChannelType, TYPEDEF, SPI_CONFIG_CONST) pCurrentRxChannelList;

  /* Number of buffers yet to be transmitted */
  Spi_NumberOfDataType ddNoOfTxBuffers;
  /* Number of buffers yet to be received */
  Spi_NumberOfDataType ddNoOfRxBuffers;
  /* Number of channels yet to be transmitted */
  Spi_ChannelType ddNoOfTxChannels;
  /* Number of channels yet to be received */
  Spi_ChannelType ddNoOfRxChannels;
  /* Index of the current hardware unit */
  Spi_HWUnitType ddHWUnitIndex;
  #if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* Tx data status of on-going transmission */
  boolean  blTxEDL;
  /* Rx data status of on-going transmission */
  boolean  blRxEDL;
  #endif
} Spi_CurrentCommData;
#endif

#if (SPI_FIFO_MODE == STD_ON)
/* Structure for storing current status of SPI communication for FIFO mode */
typedef struct STag_Spi_FifoCurrentCommData
{
  /* Pointer to current data received */
  P2VAR(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA) pCurrentRxData;
  /* Pointer to next data to be transmitted */
  P2CONST(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA) pNextTxData;
  /* Pointer to the current RX channel list */
  P2CONST(Spi_ChannelType, TYPEDEF, SPI_CONFIG_CONST) pCurrentRxChannelList;
  /* Pointer to the next TX channel list */
  P2CONST(Spi_ChannelType, TYPEDEF, SPI_CONFIG_CONST) pCurrentTxChannelList;
  /* Number of buffers yet to be transmitted */
  Spi_NumberOfDataType ddNoOfTxBuffers;
  /* Number of buffers yet to be received */
  Spi_NumberOfDataType ddNoOfRxBuffers;
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  /* Job Index */
  Spi_JobType ddJobIndex;
  #endif
  /* Number of RX channels */
  Spi_ChannelType ddNoOfRxChannels;
  /* Number of TX channels */
  Spi_ChannelType ddNoOfTxChannels;
  #if (SPI_DMA_MODE_ENABLE == STD_ON)
  /* Index of current DMA HW unit */
  uint8 ucDmaDeviceIndex;
  #endif
  uint16 usBufferCount;
} Spi_FifoCurrentCommData;
#endif

#if (SPI_TX_ONLY_MODE == STD_ON)
/* Structure for storing current status of SPI communication */
typedef struct STag_Spi_TxOnlyCurrentCommData
{
  /* Pointer to current data to be received */
  P2VAR(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA) pCurrentRxData;
  /* Pointer to current notification index array */
  P2CONST(Spi_NumberOfDataType, TYPEDEF, SPI_CONFIG_DATA) pCurrentNotifyIdx;
  /* Number of buffers yet to be transmitted */
  Spi_NumberOfDataType ddNoOfBuffers;
  /* Number of buffers received */
  Spi_NumberOfDataType ddNoOfBuffersRcvd;
  /* Number of buffers next job notification */
  P2CONST(Spi_NumberOfDataType, TYPEDEF, SPI_CONFIG_DATA)
                                                      ddNoOfNxtNotifyBuffersIdx;
    /* Index of first channel of the sequence */
  Spi_ChannelType ddChannelIndex;
} Spi_TxOnlyCurrentCommData;
#endif

#if (SPI_DUAL_BUFFER_MODE == STD_ON)
/* Structure for storing current status of SPI communication */
typedef struct STag_Spi_DualBufferCurrentCommData
{
  /* Number of buffers to be transmitted */
  Spi_NumberOfDataType ddNoOfBuffers;
  /* Number of buffers transmitted */
  Spi_NumberOfDataType ddNoOfBuffersTxtd;
  /* Number of buffers next job notification */
  P2CONST(Spi_NumberOfDataType, TYPEDEF, SPI_CONFIG_DATA)
                                                      ddNoOfNxtNotifyBuffersIdx;
} Spi_DualBufferCurrentCommData;
#endif

#if (SPI_CANCEL_API == STD_ON)
/* Structure of processing sequence */
typedef struct STag_Spi_SeqProcessType
{
  /* Position of the cancel byte */
  uint8 ucCancelOffset;
  /* Mask for cancel byte */
  uint8 ucCancelMask;
} Spi_SeqProcessType;
#endif

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ONE) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO))
/* Structure for storing external buffer attributes */
typedef struct STag_Spi_EBData
{
  /* Pointer to external buffer source data */
  P2CONST(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA)pSrcPtr;
  /* Pointer to external buffer destination data */
  P2VAR(Spi_DataType, TYPEDEF, SPI_CONFIG_DATA)pDestPtr;
  /* Length of external buffer */
  Spi_NumberOfDataType ddEBLength;
} Spi_EBData;
#endif

/* MISRA Violation: START Msg(4:0750)-2 */
/* Structure for Data access */
typedef union UTag_Spi_DataAccess
{
/* END Msg (4:0750)-2 */
  /* QAC Warning: START Msg(2:1314)-1 */
  struct STag_Tst_ByteAccess
  {
  /* END Msg (2:1314)-1 */
    /* Values for first 16-bits */
    uint16 usRegData1;
    /* Values for second 8-bits */
    uint8 ucRegData2;
    /* Value for next 8-bits */
    uint8 ucRegData3;
  } Tst_ByteAccess;

  uint32 ulRegData;

  uint16 usRegData5[SPI_TWO];

  uint8 ucRegData4[SPI_FOUR];
} Spi_DataAccess;

#if (SPI_DMA_MODE_ENABLE == STD_ON)
/* MISRA Violation: START Msg(4:0750)-2 */
/* Structure for DMA address */
typedef union UTag_Spi_DmaAddr
{
  Spi_DataType volatile *pDmaRegAddr;
/* END Msg (4:0750)-2 */
  /* QAC Warning: START Msg(2:1314)-1 */
  struct STag_Tst_DmaAddr
  {
  /* END Msg (2:1314)-1 */
    /* Lower DMA address */
    volatile uint16 usDmaRegAddrLow;
    /* Higher DMA address */
    volatile uint16 usDmaRegAddrHigh;
  } Tst_DmaAddr;
} Spi_DmaAddr;
#endif

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (SPI_CANCEL_API == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for SPI Sequence Callback functions Configuration */
extern CONST(Spi_SeqProcessType, SPI_CONST) Spi_GstSeqProcess[];
/* END Msg (4:3684)-1 */
#endif

/* MISRA Violation: START Msg(4:3684)-1 */
/* Declaration for HW unit configuration */
extern CONST(Spi_HWUnitInfo, SPI_CONST) Spi_GstHWUnitInfo[];
/* END Msg (4:3684)-1 */
#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM Area for Job result */
extern VAR(Spi_JobResultType, SPI_NOINIT_DATA) Spi_GaaJobResult[];

/* Global RAM Area for Sequence result */
extern VAR(Spi_SeqResultType, SPI_NOINIT_DATA) Spi_GaaSeqResult[];
/* END Msg (4:3684)-1 */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_ONE) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_TWO))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM array for storing external buffer attributes */
extern VAR(Spi_EBData, SPI_NOINIT_DATA) Spi_GaaChannelEBData[];
/* END Msg (4:3684)-1 */
#endif

#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) && \
       (SPI_HWUNIT_ASYNCHRONOUS == STD_ON)) || (SPI_FIFO_MODE == STD_ON) || \
                                            (SPI_HW_PRIORITY_ENABLED == STD_ON))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM area for job queue for both direct access mode and FIFO mode */
extern VAR(Spi_JobType, SPI_NOINIT_DATA) Spi_GaaJobQueue[];
/* END Msg (4:3684)-1 */
#endif

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM area for sequence queue for Dual buffer mode and Tx Only mode */
extern VAR(Spi_SequenceType, SPI_NOINIT_DATA) Spi_GaaSeqQueue[];
/* END Msg (4:3684)-1 */
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if (SPI_CANCEL_API == STD_ON)
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM bit array for cancel status of sequences */
extern VAR(uint8, SPI_NOINIT_DATA) Spi_GaaSeqCancel[];
/* Global RAM byte array for current HW Unit of the sequence */
extern VAR(uint8, SPI_NOINIT_DATA) Spi_GaaSeqCurrentHWUnit[];
/* END Msg (4:3684)-1 */
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_ONE) || (SPI_LEVEL_DELIVERED == SPI_TWO))
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global RAM area to count repeated jobs */
extern VAR(uint8, SPI_NOINIT_DATA) Spi_GaaJobCount[];
/* END Msg (4:3684)-1 */
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* SPI_LTTYPES_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
