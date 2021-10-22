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
 *              File: Os_Hal_Interrupt_Lcfg.c
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

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: AlgnErrIrq */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_AlgnErrIrq =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0UL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0UL,
  /* .IntChannel  = */ (uint32)12UL,
  /* .IntLevel    = */ (uint32)0UL,
  /* .IntMask     = */ (uint32)0UL,
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: CounterIsr_OsCounter */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_OsCounter =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*74)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*74)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)74UL,
  /* .IntLevel    = */ (uint32)4UL,
  /* .IntMask     = */ (uint32)(0x0000FFF0UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: FpuErrIrq */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_FpuErrIrq =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0UL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0UL,
  /* .IntChannel  = */ (uint32)7UL,
  /* .IntLevel    = */ (uint32)0UL,
  /* .IntMask     = */ (uint32)0UL,
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: Fr_IrqLine0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Fr_IrqLine0 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*194)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*194)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)194UL,
  /* .IntLevel    = */ (uint32)8UL,
  /* .IntMask     = */ (uint32)(0x0000FF00UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: Fr_IrqTimer0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Fr_IrqTimer0 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*196)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*196)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)196UL,
  /* .IntLevel    = */ (uint32)10UL,
  /* .IntMask     = */ (uint32)(0x0000FC00UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: MCU_ECM_EIC_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_ECM_EIC_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (2*8)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (4*8)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)8UL,
  /* .IntLevel    = */ (uint32)3UL,
  /* .IntMask     = */ (uint32)(0x0000FFF8UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: MCU_FEINT_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MCU_FEINT_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0UL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0UL,
  /* .IntChannel  = */ (uint32)14UL,
  /* .IntLevel    = */ (uint32)0UL,
  /* .IntMask     = */ (uint32)0UL,
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: MotCtrlMgrIrq */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_MotCtrlMgrIrq =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (2*16)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (4*16)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)16UL,
  /* .IntLevel    = */ (uint32)1UL,
  /* .IntMask     = */ (uint32)(0x0000FFFEUL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: ResdOperIrq */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ResdOperIrq =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0UL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0UL,
  /* .IntChannel  = */ (uint32)6UL,
  /* .IntLevel    = */ (uint32)0UL,
  /* .IntMask     = */ (uint32)0UL,
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: SPI_CSIG0_TIC_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIG0_TIC_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*175)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*175)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)175UL,
  /* .IntLevel    = */ (uint32)14UL,
  /* .IntMask     = */ (uint32)(0x0000C000UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: SPI_CSIG0_TIRE_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIG0_TIRE_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*174)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*174)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)174UL,
  /* .IntLevel    = */ (uint32)14UL,
  /* .IntMask     = */ (uint32)(0x0000C000UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: SPI_CSIG0_TIR_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIG0_TIR_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*176)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*176)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)176UL,
  /* .IntLevel    = */ (uint32)14UL,
  /* .IntMask     = */ (uint32)(0x0000C000UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: SPI_CSIH2_TIC_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH2_TIC_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*100)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*100)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)100UL,
  /* .IntLevel    = */ (uint32)14UL,
  /* .IntMask     = */ (uint32)(0x0000C000UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: SPI_CSIH2_TIRE_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH2_TIRE_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*98)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*98)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)98UL,
  /* .IntLevel    = */ (uint32)14UL,
  /* .IntMask     = */ (uint32)(0x0000C000UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: SPI_CSIH2_TIR_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH2_TIR_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (2*99)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (4*99)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)99UL,
  /* .IntLevel    = */ (uint32)14UL,
  /* .IntMask     = */ (uint32)(0x0000C000UL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: SysErrIrq */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SysErrIrq =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0UL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0UL,
  /* .IntChannel  = */ (uint32)1UL,
  /* .IntLevel    = */ (uint32)0UL,
  /* .IntMask     = */ (uint32)0UL,
  /* .CoreID      = */ (uint32)0UL
};

/*! HAL ISR configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WDG_59_DRIVERA_TRIGGERFUNCTION_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (2*9)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (4*9)),           /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  /* .IntChannel  = */ (uint32)9UL,
  /* .IntLevel    = */ (uint32)2UL,
  /* .IntMask     = */ (uint32)(0x0000FFFCUL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0UL
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
