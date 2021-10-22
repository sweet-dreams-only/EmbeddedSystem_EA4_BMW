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
 *              File: Os_Hal_MemoryProtection_Lcfg.c
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

#define OS_HAL_MEMORYPROTECTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_MemoryProtection_Cfg.h"
#include "Os_Hal_MemoryProtection_Lcfg.h"
#include "Os_Hal_MemoryProtection.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


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

/*! HAL memory protection configuration data: OsCore_CORE0 */
CONST(Os_Hal_MpCoreConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore_CORE0 =
{
  /* MaxDynAppRegions    = 2 */
  /* MaxDynThreadRegions = 0 */

  /* Regions = */ (uint32)(OS_HAL_MPU_REGION_COUNT_CORE0-1),
  /* ASID    = */ (uint32)0x03FFUL,

  {
    /* MPU region 0: dynamic region for stack */
    /* start address = */ (uint32)0x0UL,
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  },
  {
    /* MPU region 1: dynamic region for application data */
    /* start address = */ (uint32)0x0UL,    
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  },   
  {
    /* MPU region 2: dynamic region for application data */
    /* start address = */ (uint32)0x0UL,    
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  },   
  {
    /* MPU region 3: static region {SUPERVISOR=[X, R], USER=[X, R]} */
    /* start address = */ (uint32)0x0UL,                                                    
    /* end address   = */ (uint32)0x1FFFFFUL,                                                      
    /* access rights = */ (uint32)0x000000EDUL 
  }, 
  {
    /* MPU region 4: static region {SUPERVISOR=[W, R], USER=[R]} */
    /* start address = */ (uint32)GeneralRam_StartAddr,                                                    /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* end address   = */ (uint32)GeneralRam_EndAddr,                                                      /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* access rights = */ (uint32)0x000000D9UL 
  }, 
  {
    /* MPU region 5: static region {SUPERVISOR=[W, R], USER=[W, R]} */
    /* start address = */ (uint32)OS_GLOBALSHARED_VAR_START,                                                    /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* end address   = */ (uint32)OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT_END,                                                      /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* access rights = */ (uint32)0x000000DBUL 
  }, 
  {
    /* MPU region 6: static region {SUPERVISOR=[W, R], USER=[W, R]} */
    /* start address = */ (uint32)0xFF000000UL,                                                    
    /* end address   = */ (uint32)0xFFFFFFFFUL,                                                      
    /* access rights = */ (uint32)0x000000DBUL 
  }, 
  {
    /* MPU region 7: static region {SUPERVISOR=[R], USER=[R]} */
    /* start address = */ (uint32)StackRam_StartAddr,                                                    /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* end address   = */ (uint32)StackRam_EndAddr,                                                      /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* access rights = */ (uint32)0x000000C9UL 
  }, 
  {
    /* MPU region 8: static region {SUPERVISOR=[W, R], USER=[W, R]} */
    /* start address = */ (uint32)0x10020000UL,                                                    
    /* end address   = */ (uint32)0x10020847UL,                                                      
    /* access rights = */ (uint32)0x000000DBUL 
  }, 
  {
    /* MPU region 9: not used */
    (uint32)0x0UL,
    (uint32)0x0UL,
    (uint32)0x0UL
  }, 
  {
    /* MPU region 10: not used */
    (uint32)0x0UL,
    (uint32)0x0UL,
    (uint32)0x0UL
  }, 
  {
    /* MPU region 11: not used */
    (uint32)0x0UL,
    (uint32)0x0UL,
    (uint32)0x0UL
  }, 
  {
    /* MPU region 12: not used */
    (uint32)0x0UL,
    (uint32)0x0UL,
    (uint32)0x0UL
  }, 
  {
    /* MPU region 13: not used */
    (uint32)0x0UL,
    (uint32)0x0UL,
    (uint32)0x0UL
  }, 
  {
    /* MPU region 14: not used */
    (uint32)0x0UL,
    (uint32)0x0UL,
    (uint32)0x0UL
  }, 
  {
    /* MPU region 15: not used */
    (uint32)0x0UL,
    (uint32)0x0UL,
    (uint32)0x0UL
  }
};

/*! HAL memory protection configuration data: Appl0 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_Appl0 =
{
  /* Regions = */ (uint32)0,
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Appl10 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_Appl10 =
{
  /* Regions = */ (uint32)2,
  /* ASID    = */ (uint32)0x000003FFUL,
  {
    /* start address = */ (uint32)0x0UL,
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  },
  {
    /* start address = */ (uint32)OS_Appl10_VAR_ALL_START,                                              /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* end address   = */ (uint32)ModifiedEndAddrForBAC_Appl10,                                                /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* access rights = */ (uint32)0x000000C2UL
  }, 
  {
    /* start address = */ (uint32)0xFEBFE800UL,                                              
    /* end address   = */ (uint32)0xFEBFEFFFUL,                                                
    /* access rights = */ (uint32)0x000000DBUL
  }, 
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Appl7 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_Appl7 =
{
  /* Regions = */ (uint32)2,
  /* ASID    = */ (uint32)0x000003FFUL,
  {
    /* start address = */ (uint32)0x0UL,
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  },
  {
    /* start address = */ (uint32)OS_Appl7_VAR_ALL_START,                                              /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* end address   = */ (uint32)OS_Appl7_VAR_ALL_END,                                                /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* access rights = */ (uint32)0x000000C2UL
  }, 
  {
    /* start address = */ (uint32)0x0UL,    
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  }
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Appl8 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_Appl8 =
{
  /* Regions = */ (uint32)2,
  /* ASID    = */ (uint32)0x000003FFUL,
  {
    /* start address = */ (uint32)0x0UL,
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  },
  {
    /* start address = */ (uint32)OS_Appl8_VAR_ALL_START,                                              /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* end address   = */ (uint32)OS_Appl8_VAR_ALL_END,                                                /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* access rights = */ (uint32)0x000000C2UL
  }, 
  {
    /* start address = */ (uint32)0x0UL,    
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  }
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Appl9 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_Appl9 =
{
  /* Regions = */ (uint32)2,
  /* ASID    = */ (uint32)0x000003FFUL,
  {
    /* start address = */ (uint32)0x0UL,
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  },
  {
    /* start address = */ (uint32)OS_Appl9_VAR_ALL_START,                                              /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* end address   = */ (uint32)OS_Appl9_VAR_ALL_END,                                                /* PRQA S 0306, 0685 */ /* MD_Os_Hal_0306, MD_Os_Hal_0685_MpuRegionAddress */
    /* access rights = */ (uint32)0x000000C2UL
  }, 
  {
    /* start address = */ (uint32)0x0UL,    
    /* end address   = */ (uint32)0x0UL,
    /* access rights = */ (uint32)0x0UL
  }
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: SystemApplication */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_SystemApplication =
{
  /* Regions = */ (uint32)0,
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: CounterIsr_OsCounter */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CounterIsr_OsCounter =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Fr_IrqLine0 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Fr_IrqLine0 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Fr_IrqTimer0 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Fr_IrqTimer0 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: MCU_ECM_EIC_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_MCU_ECM_EIC_CAT2_ISR =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: SPI_CSIG0_TIC_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIG0_TIC_CAT2_ISR =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: SPI_CSIG0_TIRE_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIG0_TIRE_CAT2_ISR =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: SPI_CSIG0_TIR_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIG0_TIR_CAT2_ISR =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: SPI_CSIH2_TIC_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIH2_TIC_CAT2_ISR =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: SPI_CSIH2_TIRE_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIH2_TIRE_CAT2_ISR =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: SPI_CSIH2_TIR_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIH2_TIR_CAT2_ISR =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: IdleTask_OsCore_CORE0 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IdleTask_OsCore_CORE0 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_100ms_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_100ms_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_100ms_Appl7 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_100ms_Appl7 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_100ms_Appl9 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_100ms_Appl9 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_10msBsw_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_10msBsw_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_10ms_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_10ms_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_10ms_Appl7 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_10ms_Appl7 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_10ms_Appl8 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_10ms_Appl8 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_10ms_Appl9 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_10ms_Appl9 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_2msA_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_2msA_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_2msB_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_2msB_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_2msTmplMonr_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_2msTmplMonr_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_2ms_Appl7 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_2ms_Appl7 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_2ms_Appl8 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_2ms_Appl8 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_2ms_Appl9 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_2ms_Appl9 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_4msBsw_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_4msBsw_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_4ms_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_4ms_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_4ms_Appl7 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_4ms_Appl7 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_5msBsw_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_5msBsw_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_Coding_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_Coding_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_ComBsw_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_ComBsw_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_InitBsw_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_InitBsw_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_Init_Appl10 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_Init_Appl10 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_Init_Appl7 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_Init_Appl7 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_Init_Appl8 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_Init_Appl8 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

/*! HAL memory protection configuration data: Task_Init_Appl9 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Task_Init_Appl9 =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL memory protection configuration data: SystemMpu */
CONST(Os_Hal_MpSystemConfigType, OS_CONST) OsCfg_Hal_Mp_SystemMpu =
{  
  0 /* not used because no system MPU */
};

/*! HAL memory protection configuration data: EmptyThread */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EmptyThread =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFUL,
} /* PRQA S 703 */ /* MD_Os_Hal_0703_OptimizeArray */;

#define OS_STOP_SEC_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_MemoryProtection_Lcfg.c
 *********************************************************************************************************************/
