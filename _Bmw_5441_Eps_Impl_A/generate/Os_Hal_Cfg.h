/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR BAC 4.x (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M R7F701363EAFP
 *    License Scope : The usage is restricted to CBD1700369_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Cfg.h
 *   Generation Time: 2018-07-30 19:49:08
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1700369_D04
 *      Tool Version: DaVinci Configurator (beta) 5.16.35 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (OS_HAL_CFG_H)                                                          /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2U)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (11U)

/* ISR core and level definitions */
# define OS_ISR_ALGNERRIRQ_CORE      (0)
# define OS_ISR_ALGNERRIRQ_LEVEL     (0)
# define OS_ISR_COUNTERISR_OSCOUNTER_CORE      (0)
# define OS_ISR_COUNTERISR_OSCOUNTER_LEVEL     (4)
# define OS_ISR_FPUERRIRQ_CORE      (0)
# define OS_ISR_FPUERRIRQ_LEVEL     (0)
# define OS_ISR_FR_IRQLINE0_CORE      (0)
# define OS_ISR_FR_IRQLINE0_LEVEL     (8)
# define OS_ISR_FR_IRQTIMER0_CORE      (0)
# define OS_ISR_FR_IRQTIMER0_LEVEL     (10)
# define OS_ISR_MCU_ECM_EIC_CAT2_ISR_CORE      (0)
# define OS_ISR_MCU_ECM_EIC_CAT2_ISR_LEVEL     (3)
# define OS_ISR_MCU_FEINT_ISR_CORE      (0)
# define OS_ISR_MCU_FEINT_ISR_LEVEL     (0)
# define OS_ISR_MOTCTRLMGRIRQ_CORE      (0)
# define OS_ISR_MOTCTRLMGRIRQ_LEVEL     (1)
# define OS_ISR_RESDOPERIRQ_CORE      (0)
# define OS_ISR_RESDOPERIRQ_LEVEL     (0)
# define OS_ISR_SPI_CSIG0_TIC_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIG0_TIC_CAT2_ISR_LEVEL     (14)
# define OS_ISR_SPI_CSIG0_TIRE_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIG0_TIRE_CAT2_ISR_LEVEL     (14)
# define OS_ISR_SPI_CSIG0_TIR_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIG0_TIR_CAT2_ISR_LEVEL     (14)
# define OS_ISR_SPI_CSIH2_TIC_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIH2_TIC_CAT2_ISR_LEVEL     (14)
# define OS_ISR_SPI_CSIH2_TIRE_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIH2_TIRE_CAT2_ISR_LEVEL     (14)
# define OS_ISR_SPI_CSIH2_TIR_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIH2_TIR_CAT2_ISR_LEVEL     (14)
# define OS_ISR_SYSERRIRQ_CORE      (0)
# define OS_ISR_SYSERRIRQ_LEVEL     (0)
# define OS_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_ISR_CORE      (0)
# define OS_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_ISR_LEVEL     (2)

/* Hardware counter timing macros */

/* Counter timing macros and constants: OsCounter */
# define OSMAXALLOWEDVALUE_OsCounter     (2147483647UL) /* 0x7FFFFFFFUL */
# define OSMINCYCLE_OsCounter            (1UL)
# define OSTICKSPERBASE_OsCounter        (80000UL)
# define OSTICKDURATION_OsCounter        (1000000UL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_OsCounter)
# define OSMINCYCLE            (OSMINCYCLE_OsCounter)
# define OSTICKSPERBASE        (OSTICKSPERBASE_OsCounter)
# define OSTICKDURATION        (OSTICKDURATION_OsCounter)

/*! Macro OS_NS2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2NS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_US2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2US_OsCounter was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_MS2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2MS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_SEC2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2SEC_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */








/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
