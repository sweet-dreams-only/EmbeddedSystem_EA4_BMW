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
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup  Os_Hal_Derivative
 * \{
 *
 * \file
 * \brief  This file contains derivative specific information.
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 *********************************************************************************************************************/

#if !defined (OS_HAL_DERIVATIVE_RH850F1KMINT_H) /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_DERIVATIVE_RH850F1KMINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  RH850F1KM
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/*! INTC1 register base address */
# define OS_HAL_INTC1_BASE   (0xFFFEEA00UL)
/*! INTC2 register base address */
# define OS_HAL_INTC2_BASE   (0xFFFFB000UL)
/*! EIBD1 register base address */
# define OS_HAL_EIBD1_BASE   (0x00000000UL)
/*! EIBD2 register base address */
# define OS_HAL_EIBD2_BASE   (0x00000000UL)
/*! IPIR register base address */
# define OS_HAL_IPIR_BASE   (0x00000000UL)

/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Support of STM timer units. */
# define OS_HAL_CFG_TIMER_STM    (STD_OFF)
/*! Support of OSTM timer units. */
# define OS_HAL_CFG_TIMER_OSTM   (STD_ON)
/*! Support of TAUJ timer units. */
# define OS_HAL_CFG_TIMER_TAUJ   (STD_ON)

/*! OSTM0 timer unit base address */
# define OS_HAL_TIMER_OSTM0_BASE   (0xFFD70000UL)
/*! TAUJ0 timer unit base address */
# define OS_HAL_TIMER_TAUJ0_BASE   (0xFFE50000UL)
/*! TAUJ1 timer unit base address */
# define OS_HAL_TIMER_TAUJ1_BASE   (0xFFE51000UL)
/*! TAUJ2 timer unit base address */
# define OS_HAL_TIMER_TAUJ2_BASE   (0xFFE50100UL)
/*! TAUJ3 timer unit base address */
# define OS_HAL_TIMER_TAUJ3_BASE   (0xFFE51100UL)

/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Number of supported MPU regions (Core0). */
# define OS_HAL_MPU_REGION_COUNT_CORE0    (16UL)

/**********************************************************************************************************************
 *  Interrupt Priority Mask
 *********************************************************************************************************************/
/*! Mask to disable all EI interrupt levels. */
# define OS_HAL_PMR_MASK   (0xFFFFUL)

#endif /* OS_HAL_DERIVATIVE_RH850F1KMINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_RH850F1KMInt.h
 *********************************************************************************************************************/
