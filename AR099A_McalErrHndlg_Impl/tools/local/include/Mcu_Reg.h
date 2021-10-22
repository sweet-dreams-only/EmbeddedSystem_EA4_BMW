/***********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name   : Mcu_Reg.h
* Module Description : MCU registers contract header for McalErrHndlg component
* Project            : CBD
* Author             : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:         2 %
* %derived_by:      cz7lt6 %
*-----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  ----------
* 05/26/17  1        JWJ       Initial version                                                                EA4#
************************************************************************************************************************/

/******************************************* Multiple Include Protection **********************************************/
#ifndef MCU_REG_H
#define MCU_REG_H

#include "Std_Types.h"
#include "Mcu_Cfg.h"
#include "Dem.h"


/*********************************************** Exported Declarations ************************************************/
/* Define this register as an external variable so that QAC understands that it's okay to write a uint32 value to it. */
extern VAR(uint32, AUTOMATIC) SYSRESFC;

#define MCU_LOOPCOUNT  5U
#define MCU_SWRESA           (*((volatile uint32  *)0xFFF8AC18UL))
#define MCU_RES_CORRECT_VAL  (uint32)0x00000001UL
#define MCU_PROT1PHCMD       (*((volatile uint32  *)0xFFF8B000UL))
#define MCU_PROT1PS          (*((volatile uint32  *)0xFFF8B004UL))
#define MCU_WRITE_DATA                    (uint32)0x000000A5UL
#define MCU_ONE                           (uint8)0x01

/* The following Macro is from Mcu.h. It requires register access which will be flagged 
 * in Bug Finder and Code Prover. Since the code is from a 3rd party there is no need 
 * to justify the deviation. */
#define MCU_PROTECTEDWRITERETNONE(reg, value, preg, sreg, loopcount) \
  do  \
  { \
    (preg) = MCU_WRITE_DATA;  \
    (reg) = (value);  \
    (reg) = ~(value); \
    (reg) = (value);  \
    (loopcount) = (loopcount) - MCU_ONE;  \
  }while ((MCU_ONE == (sreg)) && ((loopcount) > MCU_ONE));  \
  if (MCU_ONE == (sreg))  \
  { \
    Dem_ReportErrorStatus \
                       (MCU_E_WRITE_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED); \
  } \
  else  \
  { \
  }


#endif /* MCU_REG_H */