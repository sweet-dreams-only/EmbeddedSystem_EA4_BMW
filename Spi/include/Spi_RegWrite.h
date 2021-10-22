/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 - 2017 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is to have macro definitions for the register write verification.*/
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
 * V1.0.0:  20-Jul-2016  : Initial Version
 * V1.0.1:  15-Feb-2017  : Following changes are made:
 *                         1.As part of ARDAAAE-2277,following changes are made:
 *                              a. SPI_DEM_TYPE is removed.
 *                              b. 'U' is appended for MACRO definitions
 *                                 wherever applicable.
 *                         2.Copyright information is updated.
 */
/******************************************************************************/
#ifndef SPI_REGWRITE_H
#define SPI_REGWRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Included for pre-compile options */
#include "Spi_Cfg.h"

/* AUTOSAR standard types */
#include "Std_Types.h"

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognised code-fragment       */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Semicolon is added to avoid compilation warnings and       */
/*                 additional QAC warning.                                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

/* AUTOSAR Release version information */
#define SPI_REGWRITE_H_AR_RELEASE_MAJOR_VERSION   \
                                                   SPI_AR_RELEASE_MAJOR_VERSION
#define SPI_REGWRITE_H_AR_RELEASE_MINOR_VERSION   \
                                                   SPI_AR_RELEASE_MINOR_VERSION
#define SPI_REGWRITE_H_AR_RELEASE_REVISION_VERSION \
                                                SPI_AR_RELEASE_REVISION_VERSION

/* File version information */
#define SPI_REGWRITE_SW_MAJOR_VERSION  SPI_SW_MAJOR_VERSION
#define SPI_REGWRITE_SW_MINOR_VERSION  SPI_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Macro for Register readback disable */
#define SPI_WV_DISABLE                       0x0U
/* Macro for Register readback INIT_ONLY */
#define SPI_WV_INIT_ONLY                     0x1U
/* Macro for Register readback INIT_RUNTIME */
#define SPI_WV_INIT_RUNTIME                  0x2U

/*******************************************************************************
** Macro Name            : SPI_CSIGH_REG_WRITE
**
** Description           : This Macro performs direct writing
**                         operation into CSIXxxx registers.
**
** Input Parameters      : REG : CSIXxxx Register address
**                         VAL : Value written to the register.
** Output Parameters     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3412)-1 */
#define SPI_CSIGH_REG_WRITE(REG, VAL)         (REG) = (VAL);

/*******************************************************************************
** Macro Name            : SPI_DMA_REG_WRITE
**
** Description           : This Macro performs DMAxxxx register
**                         direct writing.
**
** Input Parameters      : REG : DMA Register address
**                         VAL : Value written to the register.
** Output Parameters     : None
*******************************************************************************/

#define SPI_DMA_REG_WRITE(REG, VAL)         (REG) = (VAL);

/*******************************************************************************
** Macro Name            : SPI_WV_REPORT_ERROR
**
** Description           : This macro is to report the error to respective
**                         interface.
**
** Input Parameters      : WVErrId, ErrStat, uiApiId
**
** Output Parameters     : None
*******************************************************************************/

#if (SPI_USE_WV_ERROR_INTERFACE == STD_ON )
#define SPI_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                SPI_ERROR_NOTIFICATION(WVErrId, uiApiId);
#else
#define SPI_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            Dem_ReportErrorStatus(WVErrId, \
                                   (Dem_EventStatusType) (ErrStat));
#endif

/*******************************************************************************
** Macro Name            : SPI_CSIGH_REG_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the SPI
**                         CSIXxxx registers during initialize API.
**
** Input Parameters      : pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** Output Parameters     : None
*******************************************************************************/

#if((SPI_WV_INIT_ONLY == SPI_CSIGH_WRITE_VERIFY) || \
      (SPI_WV_INIT_RUNTIME == SPI_CSIGH_WRITE_VERIFY))
#define SPI_CSIGH_REG_WRITE_VERIFY_INIT(pWriteRegAddr,uiCheckValue, \
                                         uiWCMaskValue, uiApiId) \
  SPI_CHECK_WRITE_VERIFY(pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId);
#else
#define SPI_CSIGH_REG_WRITE_VERIFY_INIT(pWriteRegAddr,uiCheckValue, \
                                         uiWCMaskValue, uiApiId) \
  { \
  }
#endif

/*******************************************************************************
** Macro Name            : SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the SPI
**                         CSIXxxx registers during runtime.
**
** Input Parameters      : pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** Output Parameters     : None
*******************************************************************************/
#if(SPI_WV_INIT_RUNTIME == SPI_CSIGH_WRITE_VERIFY)
#define SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(pWriteRegAddr,uiCheckValue,\
                                         uiWCMaskValue, uiApiId) \
  SPI_CHECK_WRITE_VERIFY(pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId);
#else
#define SPI_CSIGH_REG_WRITE_VERIFY_RUNTIME(pWriteRegAddr, uiCheckValue, \
                                      uiWCMaskValue, uiApiId) \
  { \
  }
#endif

/*******************************************************************************
** Macro Name            : SPI_CHECK_WRITE_VERIFY
**
** Description           : This macro is to call the error report macro if
**                         the register write-verify for CSIXxxx and DMA
**                         registers fails
**
** Input Parameters      : pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** Output Parameters     : None
*******************************************************************************/

#define SPI_CHECK_WRITE_VERIFY(pWriteRegAddr,uiCheckValue,\
                                            uiWCMaskValue,uiApiId) \
  if((uiCheckValue) != ((pWriteRegAddr) & (uiWCMaskValue)))\
  { \
      SPI_WV_REPORT_ERROR(SPI_E_REG_WRITE_VERIFY, \
                           DEM_EVENT_STATUS_FAILED, uiApiId); \
  } \
  else \
  { \
  }

/*******************************************************************************
** Macro Name            : SPI_DMA_REG_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the SPI
**                         DMA registers during initialize API.
**
** Input Parameters      : pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** Output Parameters     : None
*******************************************************************************/

#if((SPI_WV_INIT_ONLY == SPI_DMA_WRITE_VERIFY) || \
      (SPI_WV_INIT_RUNTIME == SPI_DMA_WRITE_VERIFY))
#define SPI_DMA_REG_WRITE_VERIFY_INIT(pWriteRegAddr,uiCheckValue, \
                                         uiWCMaskValue, uiApiId) \
  SPI_CHECK_WRITE_VERIFY(pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId);
#else
#define SPI_DMA_REG_WRITE_VERIFY_INIT(pWriteRegAddr,uiCheckValue, \
                                         uiWCMaskValue, uiApiId) \
  { \
  }
#endif

/*******************************************************************************
** Macro Name            : SPI_DMA_REG_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the SPI
**                         DMA registers during runtime.
**
** Input Parameters      : pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** Output Parameters     : None
*******************************************************************************/
#if(SPI_WV_INIT_RUNTIME == SPI_DMA_WRITE_VERIFY)
#define SPI_DMA_REG_WRITE_VERIFY_RUNTIME(pWriteRegAddr,uiCheckValue,\
                                         uiWCMaskValue, uiApiId) \
  SPI_CHECK_WRITE_VERIFY(pWriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId);
#else
#define SPI_DMA_REG_WRITE_VERIFY_RUNTIME(pWriteRegAddr, uiCheckValue, \
                                      uiWCMaskValue, uiApiId) \
  { \
  }
#endif
/* END Msg(4:3412)-1 */
#endif /* SPI_REGWRITE_H */
/* End of write verification macro definitions. */
/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
