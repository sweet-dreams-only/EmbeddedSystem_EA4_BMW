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
 *              File: Os_Scheduler_Lcfg.c
 *   Generation Time: 2018-07-30 19:49:09
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

#define OS_SCHEDULER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Scheduler_Cfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Scheduler.h"

/* Os kernel module dependencies */
#include "Os_BitArray.h"
#include "Os_Common.h"
#include "Os_Deque.h"

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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Dynamic scheduler data: OsCore_CORE0 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore_CORE0_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore_CORE0_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore_CORE0 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue9_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes9_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE9_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue10_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes10_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE10_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue11_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes11_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE11_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue12_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes12_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE12_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue13_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes13_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE13_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue14_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes14_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE14_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue15_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes15_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE15_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue16_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes16_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE16_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue17_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes17_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE17_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue18_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes18_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE18_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue19_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes19_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE19_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue20_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes20_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE20_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue21_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes21_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE21_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue22_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes22_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE22_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue23_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes23_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE23_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue24_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes24_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE24_OSCORE_CORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue25_OsCore_CORE0_Dyn;
OS_LOCAL VAR(Os_FifoPtrNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes25_OsCore_CORE0_Dyn[OS_CFG_NUM_TASKQUEUE25_OSCORE_CORE0_SLOTS];

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Task queues configuration data: OsCore_CORE0 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore_CORE0_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes0_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue0_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue0_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes0_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS
    }
  },
  /* [1] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes1_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue1_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue1_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes1_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS
    }
  },
  /* [2] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes2_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue2_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue2_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes2_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS
    }
  },
  /* [3] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes3_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue3_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue3_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes3_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS
    }
  },
  /* [4] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes4_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue4_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue4_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes4_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS
    }
  },
  /* [5] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes5_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue5_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue5_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes5_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS
    }
  },
  /* [6] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes6_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue6_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue6_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes6_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS
    }
  },
  /* [7] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue7_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue7_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes7_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue7_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue7_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes7_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE0_SLOTS
    }
  },
  /* [8] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue8_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue8_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes8_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE8_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue8_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue8_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes8_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE8_OSCORE_CORE0_SLOTS
    }
  },
  /* [9] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue9_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue9_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes9_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE9_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue9_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue9_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes9_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE9_OSCORE_CORE0_SLOTS
    }
  },
  /* [10] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue10_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue10_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes10_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE10_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue10_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue10_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes10_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE10_OSCORE_CORE0_SLOTS
    }
  },
  /* [11] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue11_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue11_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes11_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE11_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue11_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue11_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes11_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE11_OSCORE_CORE0_SLOTS
    }
  },
  /* [12] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue12_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue12_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes12_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE12_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue12_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue12_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes12_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE12_OSCORE_CORE0_SLOTS
    }
  },
  /* [13] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue13_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue13_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes13_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE13_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue13_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue13_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes13_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE13_OSCORE_CORE0_SLOTS
    }
  },
  /* [14] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue14_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue14_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes14_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE14_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue14_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue14_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes14_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE14_OSCORE_CORE0_SLOTS
    }
  },
  /* [15] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue15_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue15_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes15_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE15_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue15_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue15_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes15_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE15_OSCORE_CORE0_SLOTS
    }
  },
  /* [16] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue16_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue16_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes16_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE16_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue16_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue16_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes16_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE16_OSCORE_CORE0_SLOTS
    }
  },
  /* [17] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue17_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue17_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes17_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE17_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue17_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue17_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes17_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE17_OSCORE_CORE0_SLOTS
    }
  },
  /* [18] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue18_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue18_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes18_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE18_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue18_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue18_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes18_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE18_OSCORE_CORE0_SLOTS
    }
  },
  /* [19] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue19_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue19_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes19_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE19_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue19_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue19_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes19_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE19_OSCORE_CORE0_SLOTS
    }
  },
  /* [20] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue20_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue20_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes20_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE20_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue20_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue20_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes20_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE20_OSCORE_CORE0_SLOTS
    }
  },
  /* [21] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue21_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue21_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes21_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE21_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue21_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue21_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes21_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE21_OSCORE_CORE0_SLOTS
    }
  },
  /* [22] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue22_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue22_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes22_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE22_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue22_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue22_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes22_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE22_OSCORE_CORE0_SLOTS
    }
  },
  /* [23] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue23_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue23_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes23_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE23_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue23_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue23_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes23_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE23_OSCORE_CORE0_SLOTS
    }
  },
  /* [24] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue24_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue24_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes24_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE24_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue24_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue24_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes24_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE24_OSCORE_CORE0_SLOTS
    }
  },
  /* [25] = */
  {
    /* .FifoRead  = */
    {
      /* .Dyn   = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue25_OsCore_CORE0_Dyn),
      /* .Write = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue25_OsCore_CORE0_Dyn),
      /* .Data  = */ OsCfg_TaskQueueNodes25_OsCore_CORE0_Dyn,
      /* .Size  = */ OS_CFG_NUM_TASKQUEUE25_OSCORE_CORE0_SLOTS
    },
    /* .FifoWrite = */
    {
      /* .Dyn  = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRWRITE(OsCfg_TaskQueue25_OsCore_CORE0_Dyn),
      /* .Read = */ OS_DEQUE_CASTDYN_DEQUE_2_FIFOPTRREAD(OsCfg_TaskQueue25_OsCore_CORE0_Dyn),
      /* .Data = */ OsCfg_TaskQueueNodes25_OsCore_CORE0_Dyn,
      /* .Size = */ OS_CFG_NUM_TASKQUEUE25_OSCORE_CORE0_SLOTS
    }
  }
};

/*! Scheduler configuration data: OsCore_CORE0 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore_CORE0 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore_CORE0_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore_CORE0_BitField_Dyn,
    /* .Size      = */ OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore_CORE0_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore_CORE0_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
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
 *  END OF FILE: Os_Scheduler_Lcfg.c
 *********************************************************************************************************************/
