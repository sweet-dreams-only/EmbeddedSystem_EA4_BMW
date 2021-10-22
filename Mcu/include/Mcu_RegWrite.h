/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macro definitions for the registers write and           */
/* register write verification.                                               */
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
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  20-Jul-2016 : Initial Version
 *
 * V1.0.1:  11-Jan-2017 : Following changes are done
 *                        1. As per ARDAAAE-2125, added justification for MISRA
 *                           Msg(4:0857).
 *                        2. As per ARDAAAE-2358, added subfix for macros
 */
/******************************************************************************/

#ifndef MCU_REG_WRITE_H
#define MCU_REG_WRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

#if( MCU_USE_WRITE_VERIFY_ERROR_INTERFACE == STD_ON )
#include "Mcu_Cbk.h"
#endif

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* MCU_H_024: EAAR_PN0034_FR_0055, EAAR_PN0034_NR_0056, EAAR_PN0034_NR_0045 */
/* MCU_H_025: EAAR_PN0034_NR_0069, EAAR_PN0034_NR_0001, EAAR_PN0034_NR_0002 */
/* MCU_H_026: EAAR_PN0034_NR_0018 */
/* AUTOSAR release version information */
#define MCU_REGWRITE_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_REGWRITE_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_REGWRITE_AR_RELEASE_REVISION_VERSION \
                                     MCU_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_REGWRITE_SW_MAJOR_VERSION    MCU_SW_MAJOR_VERSION
#define MCU_REGWRITE_SW_MINOR_VERSION    MCU_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognized code-fragment       */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-1 and                           */
/*                 END Msg(4:3412)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024          */
/*                 - program does not conform strictly to ISO:C99.            */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-2 and                           */
/*                 END Msg(4:0857)-2 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* MISRA Violation: START Msg(4:0857)-2 */
/* Macro for Register readback disable */
#define MCU_WV_DISABLE                      0U
/* Macro for Register readback INIT_ONLY*/
#define MCU_WV_INIT_ONLY                    1U
/* Macro for Register readback INIT_RUNTIME */
#define MCU_WV_INIT_RUNTIME                 2U

#define MCU_FULL_MASK                   (uint32) 0xFFFFFFFFUL

#define MCU_CVMDE_WV_MASK               (uint8) 0x1C

#define MCU_8BIT_MASK                   (uint8) 0xFF

#define MCU_16BIT_MASK                  (uint16) 0xFFFF

#define MCU_CLMACTL_WV_MASK             (uint8) 0x01

#define MCU_POF_WV_MASK                 (uint32) 0x00000001UL

/* Macros for DEM */
#define MCU_DEM_TYPE Dem_EventStatusType

/*******************************************************************************
** Macro Name            : MCU_REG_WRITE_VERIFY_INIT
**
** Description           : This macro is to do the write verify for the port
**                         registers during initialize API.
**
** Input Parameters      : WriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/*MCU_H_027: EAAR_PN0034_FSR_0001, EAAR_PN0034_FSR_0002, EAAR_PN0034_FSR_0003 */

/* MISRA Violation: START Msg(4:3412)-1 */
#if((MCU_WV_INIT_ONLY == MCU_WRITE_VERIFY ) || \
      (MCU_WV_INIT_RUNTIME == MCU_WRITE_VERIFY ))
#define MCU_REG_WRITE_VERIFY_INIT(WriteRegAddr,uiCheckValue, \
                                         uiWCMaskValue, uiApiId) \
  MCU_REG_WRITE_VERIFY(WriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId);
#else
#define MCU_REG_WRITE_VERIFY_INIT(WriteRegAddr,uiCheckValue, \
                                         uiWCMaskValue, uiApiId) \
  { \
  }
#endif
/* MISRA Violation: END Msg(4:3412)-1 */
/*******************************************************************************
** Macro Name            : MCU_REG_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the port
**                         registers during runtime.
**
** Input Parameters      : WriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3412)-1 */
#if(MCU_WV_INIT_RUNTIME == MCU_WRITE_VERIFY )
#define MCU_REG_WRITE_VERIFY_RUNTIME(WriteRegAddr,uiCheckValue,\
                                         uiWCMaskValue, uiApiId) \
    MCU_REG_WRITE_VERIFY(WriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId);
#else
#define MCU_REG_WRITE_VERIFY_RUNTIME(WriteRegAddr, uiCheckValue, \
                                      uiWCMaskValue, uiApiId) \
  { \
  }
#endif
/* MISRA Violation: END Msg(4:3412)-1 */
/*******************************************************************************
** Macro Name            : MCU_REG_WRITE_VERIFY
**
** Description           : This macro is to do call the error report macro if
**                         the register write-verify fails
**
** Input Parameters      : WriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3412)-1 */
#define MCU_REG_WRITE_VERIFY(WriteRegAddr,uiCheckValue,\
                                            uiWCMaskValue,uiApiId) \
  if((uiCheckValue) != ((WriteRegAddr) & (uiWCMaskValue)))\
  { \
      MCU_WV_REPORT_ERROR(MCU_E_REG_WRITE_VERIFY, \
                           DEM_EVENT_STATUS_FAILED, uiApiId); \
  } \
  else \
  { \
  }
/* MISRA Violation: END Msg(4:3412)-1 */
/*******************************************************************************
** Macro Name            : MCU_WV_REPORT_ERROR
**
** Description           : This macro is to do the write verify for the port
**                         registers
**
** Input Parameters      : REG, VAL,uiApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : None
*******************************************************************************/
/* MISRA Violation: START Msg(4:3412)-1 */
/* MCU_H_028: EAAR_PN0034_FSR_0004 */
#if ( MCU_USE_WRITE_VERIFY_ERROR_INTERFACE == STD_ON )
#define MCU_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                MCU_WRITE_VERIFY_ERROR_NOTIFICATION(WVErrId, uiApiId);
#else
#define MCU_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            Dem_ReportErrorStatus(WVErrId, \
                                   (MCU_DEM_TYPE) (ErrStat));
#endif
/* MISRA Violation: END Msg(4:3412)-1 */
/* MISRA Violation: END Msg(4:0857)-2 */
#endif /*  MCU_REG_WRITE_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
