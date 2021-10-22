/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Fr_Irq.c
 *        \brief  FlexRay Driver IRQ source file
 *
 *      \details  Implementation of FlexRay Driver Interrupt functions according to:
 *                AUTOSAR FlexRay Driver, AUTOSAR Release 4.0
 *
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define FR_IRQ_SOURCE

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0303 EOF */ /* MD_Fr_0306 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Fr.h"

#if (FR_CFG_ISR_TYPE == FR_ISR_CAT2)  /* COV_FR_UNSUPPORTED_ISR_TYPE */
# include "Os.h"
#endif

#if (FR_CFG_APPL_CALLBACK_TIMER0 == STD_OFF)
# include "FrIf.h"
#endif

/* PRQA S 1503 EOF */ /* MD_MSR_14.1 */

/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check consistency of source and header file. */
#if ((FR_SW_MAJOR_VERSION != 0x5u) || (FR_SW_MINOR_VERSION != 0x00u) || (FR_SW_PATCH_VERSION != 0x01u))
# error "Fr_Irq.c: Source and Header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FR_START_SEC_CODE_ISR
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

# if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON) /* COV_FR_TESTSUITE_INSTRUMENTATION */
#  if (FR_CFG_ISR_TYPE == FR_ISR_CAT1) || (FR_CFG_ISR_TYPE == FR_ISR_VOID)  /* COV_FR_UNSUPPORTED_ISR_TYPE */
#   if(FR_CFG_STATUS_ISR_LINE == 0) /* COV_FR_UNSUPPORTED_ISR_TYPE */
/***********************************************************************************************************************
 *  Fr_IrqLine0
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FR_CODE_ISR) Fr_IrqLine0(void)
#   else
/***********************************************************************************************************************
 *  Fr_IrqLine1
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FR_CODE_ISR) Fr_IrqLine1(void)
#   endif
#  else
#   if(FR_CFG_STATUS_ISR_LINE == 0)
/***********************************************************************************************************************
 *  Fr_IrqLine0
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
ISR(Fr_IrqLine0)  /* PRQA S 3408 */ /* MD_Fr_3408 */
#   else
/***********************************************************************************************************************
 *  Fr_IrqLine1
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
ISR(Fr_IrqLine1)  /* PRQA S 3408 */ /* MD_Fr_3408 */
#   endif
#  endif
{
  /* #10 Call the status handling ISR of the FR driver to handle a cycle start interrupt. */
  Fr_ISR_Status(FR_COM_CONTROLLER_0);
}

#  if (FR_NUM_CTRL_USED > 1)
#   if (FR_CFG_ISR_TYPE == FR_ISR_CAT1) || (FR_CFG_ISR_TYPE == FR_ISR_VOID)  /* COV_FR_UNSUPPORTED_ISR_TYPE */
#    if(FR_CFG_STATUS_ISR_LINE_1 == 0) /* COV_FR_UNSUPPORTED_ISR_TYPE */
/***********************************************************************************************************************
 *  Fr_IrqLine0_1
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FR_CODE_ISR) Fr_IrqLine0_1(void)
#    else
/***********************************************************************************************************************
 *  Fr_IrqLine1_1
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, FR_CODE_ISR) Fr_IrqLine1_1(void)
#    endif
#   else
#    if(FR_CFG_STATUS_ISR_LINE_1 == 0)
/***********************************************************************************************************************
 *  Fr_IrqLine0_1
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
ISR(Fr_IrqLine0_1)  /* PRQA S 3408 */ /* MD_Fr_3408 */
#    else
/***********************************************************************************************************************
 *  Fr_IrqLine1_1
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
ISR(Fr_IrqLine1_1)  /* PRQA S 3408 */ /* MD_Fr_3408 */
#    endif
#   endif
{
  /* #10 Call the status handling ISR of the FR driver to handle a cycle start interrupt. */
  Fr_ISR_Status(FR_COM_CONTROLLER_1);
}
#  endif

# endif

/***********************************************************************************************************************
 *  Fr_IrqTimer0
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
#  if (FR_CFG_ISR_TYPE == FR_ISR_CAT1) || (FR_CFG_ISR_TYPE == FR_ISR_VOID)  /* COV_FR_UNSUPPORTED_ISR_TYPE */
void Fr_IrqTimer0(void)
#  else
ISR(Fr_IrqTimer0)  /* PRQA S 3408 */ /* MD_Fr_3408 */
#  endif
{
  /* #10 Clear the Timer Interrupt 0 flag (TI0) of the Status Interrupt Register (SIR) to acknowledge the absolute timer. */
  Fr_VCCClearIrqStatusFlag(FR_COM_CONTROLLER_0, FR_SIR_TI0); /* SBSW_FR_WriteHwReg */
#   if (defined FR_CPU_RH850) /* COV_FR_EQUIVALENT_HARDWARE */
  Fr_VCCWriteValue(FR_COM_CONTROLLER_0, FR_FROS, FR_FROS_T0IS); /* SBSW_FR_WriteHwReg */
#   endif
  /* #20 If FR_CFG_APPL_CALLBACK_TIMER0 is enabled:
   *      Call the Timer0 application callback. */
#  if (FR_CFG_APPL_CALLBACK_TIMER0 == STD_ON)
  ApplFr_ISR_Timer0();
#  else
  /* #30 Otherwise:
           Call the Timer0 application callback. */
  FrIf_JobListExec_0();
#  endif
}

#if (FR_NUM_CTRL_USED > 1)
/***********************************************************************************************************************
 *  Fr_IrqTimer0_1
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
#  if (FR_CFG_ISR_TYPE == FR_ISR_CAT1) || (FR_CFG_ISR_TYPE == FR_ISR_VOID)  /* COV_FR_UNSUPPORTED_ISR_TYPE */
void Fr_IrqTimer0_1(void)
#  else
ISR(Fr_IrqTimer0_1)  /* PRQA S 3408 */ /* MD_Fr_3408 */
#  endif
{
  /* #10 Clear the Timer Interrupt 0 flag (TI0) of the Status Interrupt Register (SIR) to acknowledge the absolute timer. */
  Fr_VCCClearIrqStatusFlag(FR_COM_CONTROLLER_1, FR_SIR_TI0); /* SBSW_FR_WriteHwReg */
#   if (defined FR_CPU_RH850) /* COV_FR_EQUIVALENT_HARDWARE */
  Fr_VCCWriteValue(FR_COM_CONTROLLER_1, FR_FROS, FR_FROS_T0IS); /* SBSW_FR_WriteHwReg */
#   endif
  /* #20 If FR_CFG_APPL_CALLBACK_TIMER0 is enabled:
   *      Call the Timer0 application callback. */
#  if (FR_CFG_APPL_CALLBACK_TIMER0 == STD_ON)
  ApplFr_ISR_Timer0_1();
#  else
  /* #30 Otherwise:
           Call the Timer0 application callback. */
  FrIf_JobListExec_1();
#  endif
}
# endif

#define FR_STOP_SEC_CODE_ISR
#include "MemMap.h" /* PRQA S 5087 */ /*  MD_MSR_19.1 */ /*lint -e{451} */

/**********************************************************************************************************************
 *  END OF FILE: Fr_Irq.c
 *********************************************************************************************************************/
