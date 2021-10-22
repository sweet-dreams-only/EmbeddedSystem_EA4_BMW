/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_Trap
 *  \{
 *
 *  \file       Os_Hal_Trap.c
 *  \brief      Contains the implementation of the trap module.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_TRAP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Trap.h"

/* Os module dependencies */
#include "Os_Cfg.h"
#include "Os_Kernel.h"

/* Os HAL dependencies */
#include "Os_Hal_Compiler.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_SystemTrap()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
  Os_Hal_SECTION(".OS_CODE");                                                                                           /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_ALIGN("4");                                                                                                    /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_LABEL("Os_Hal_SystemTrap");                                                                                    /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  /* #10 Trigger trap Os_Hal_TrapHandler. */
  Os_Hal_ASM("trap  1");                                                                                                /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */

/***********************************************************************************************************************
 *  Os_Hal_TrapHandler()
 **********************************************************************************************************************/
  /*!
   * Internal comment removed.
 *
 *
   */
  Os_Hal_SECTION(".OS_CODE");                                                                                           /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_ALIGN("4");                                                                                                    /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_LABEL("Os_Hal_TrapHandler");                                                                                   /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  /* #10 Call Os_TrapHandler with EI level interrupts disabled. */
  Os_Hal_ASM("mov   _Os_TrapHandler, r11");                                                                             /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_ASM("ldsr  r11, EIPC");                                                                                        /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_ASM("mov   0x00018020, r11");                                                                                  /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_ASM("ldsr  r11, EIPSW");                                                                                       /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */
  Os_Hal_ASM("eiret");                                                                                                  /* PRQA S 0605 */ /* MD_Os_Hal_0605_AssemblerStub */

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Trap.c
 **********************************************************************************************************************/
 
