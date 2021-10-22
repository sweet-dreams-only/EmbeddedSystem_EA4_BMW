/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_RegWrite.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016-2017 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is to have macro definitions for the registers write             */
/* functionality verification.                                                */
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
 * V1.0.0:  07-Jul-2016 : Initial Version
 * V1.0.1:  15-Feb-2017 : Following changes are made:
 *                        1. As per ARDAAAE-2191, requirement tag
 *                           'implements' changed to 'DIO_H_00x :'.
 *                        2. Copyright information 'Copyright(c) 2017'
 *                           corrected to 'Copyright(c) 2016-2017'.
 *                        3. As per ARDAAAE-2273,removed macro 'DIO_DEM_TYPE'.
 */
/******************************************************************************/
/* DIO_H_005: EAAR_PN0034_FR_0001 */
#ifndef DIO_REGWRITE_H
#define DIO_REGWRITE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/


#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "Dio_Cbk.h"


/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/

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

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                     Macro Definitions                                      **
*******************************************************************************/
/* Macro for Register readback disable */
#define DIO_WV_DISABLE                          0U

/* Macro for Register readback INIT_RUNTIME */
#define DIO_WV_INIT_RUNTIME                     2U

/*******************************************************************************
**                      API Service Id Macros                                 **
*******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (uint8)0x10

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/* Service ID for DIO GetVersion Info */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO Masked Write Channel */
#define DIO_MASKED_WRITE_PORT_SID      (uint8)0x13

/*******************************************************************************
** Macro Name            : DIO_REG_WRITE
**
** Description           : This Macro performs register direct writing
**                         operation.
**
** Input Parameters      : REG, VAL
**                         REG  : Variable mapped to register memory.
**                         VAL  : Value to be written to the register.
*******************************************************************************/
/* MISRA Violation: START Msg(4:3412)-1 */
#define DIO_REG_WRITE(REG, VAL)         (REG) = (VAL);
/* END Msg(4:3412)-1 */

/*******************************************************************************
** Macro Name            : DIO_REG_WRITE_VERIFY_RUNTIME
**
** Description           : This macro is to do the write verify for the dio
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
#if(DIO_WV_INIT_RUNTIME == DIO_WRITE_VERIFY )
#define DIO_REG_WRITE_VERIFY_RUNTIME(WriteRegAddr,uiCheckValue,\
                                         uiWCMaskValue, uiApiId) \
    DIO_REG_WRITE_VERIFY(WriteRegAddr,uiCheckValue,uiWCMaskValue,uiApiId);
#else
#define DIO_REG_WRITE_VERIFY_RUNTIME(WriteRegAddr, uiCheckValue, \
                                      uiWCMaskValue, uiApiId) \
  { \
  }
#endif
/* MISRA Violation: END Msg(4:3412)-1 */

/*******************************************************************************
** Macro Name            : DIO_REG_WRITE_VERIFY
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
/* DIO_H_006: DIO067 */
/* MISRA Violation: START Msg(4:3412)-1 */
#define DIO_REG_WRITE_VERIFY(WriteRegAddr,uiCheckValue,\
                                            uiWCMaskValue,uiApiId) \
  if((uiCheckValue) != ((WriteRegAddr) & (uiWCMaskValue)))\
  { \
      DIO_WV_REPORT_ERROR(DIO_E_REG_WRITE_VERIFY, \
                           DEM_EVENT_STATUS_FAILED, uiApiId); \
  } \
  else \
  { \
  }
/* MISRA Violation: END Msg(4:3412)-1 */

/*******************************************************************************
** Macro Name            : DIO_WV_REPORT_ERROR
**
** Description           : This macro is to do the write verify for the dio
**                         registers
**
** Input Parameters      : WVErrId,ErrStat,uiApiId
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
/* DIO_H_007: DIO067 */
/* MISRA Violation: START Msg(4:3412)-1 */
#if ( DIO_USE_WV_ERROR_INTERFACE == STD_ON )
#define DIO_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                DIO_ERROR_NOTIFICATION(WVErrId, uiApiId);
#else
#define DIO_WV_REPORT_ERROR(WVErrId, ErrStat, uiApiId) \
                            Dem_ReportErrorStatus(WVErrId, \
                                          ErrStat);
#endif
/* MISRA Violation: END Msg(4:3412)-1 */
#endif /*  DIO_REGWRITE_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
