/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  ClsdLoopHys.c
 *        Config:  EPS.dpa
 *     SW-C Type:  ClsdLoopHys
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <ClsdLoopHys>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * s4p11
 *   
 *
 * u15p1
 *   
 *
 * u2p14
 *   
 *
 * u4p12
 *   
 *
 * u6p10
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_ClsdLoopHys.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_ClsdLoopHys.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s4p11: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u15p1: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s4p11_7: Array with 7 element(s) of type s4p11
 * Ary1D_u15p1_4: Array with 4 element(s) of type u15p1
 * Ary1D_u2p14_2: Array with 2 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u2p14_7: Array with 7 element(s) of type u2p14
 * Ary1D_u4p12_5: Array with 5 element(s) of type u4p12
 * Ary1D_u6p10_12: Array with 12 element(s) of type u6p10
 * Ary1D_u6p10_2: Array with 2 element(s) of type u6p10
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary2D_u2p14_12_4: Array with 12 element(s) of type Ary1D_u2p14_4
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_IntgtrSt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_ClsdLoopHysHwAgBlndFac_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysPolarity_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(void)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(void)
 *   u6p10 *Rte_Prm_ClsdLoopHysDeltaY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysGainY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u6p10 *Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u15p1 *Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(void)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_4
 *   u2p14 *Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_12_4
 *   u6p10 *Rte_Prm_ClsdLoopHysRhoY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u9p7 *Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u4p12 *Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_5
 *   s4p11 *Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(void)
 *     Returnvalue: s4p11* is of type Ary1D_s4p11_7
 *   u2p14 *Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_7
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define ClsdLoopHys_START_SEC_CODE
#include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopHysInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysInit1
 *********************************************************************************************************************/

  float32 PimIntgtrSt;

  float32 ClsdLoopHysHwAgBlndFac_Val_data;
  float32 ClsdLoopHysPolarity_Val_data;
  float32 ClsdLoopHysSteerInHwAgNegLowrLim_Val_data;
  float32 ClsdLoopHysSteerInHwAgNegUpprLim_Val_data;
  float32 ClsdLoopHysSteerInHwAgPosLowrLim_Val_data;
  float32 ClsdLoopHysSteerInHwAgPosUpprLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgNegLowrLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgNegUpprLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgPosLowrLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgPosUpprLim_Val_data;
  Ary1D_u6p10_12 ClsdLoopHysDeltaY_Ary1D_data;
  Ary1D_u6p10_12 ClsdLoopHysGainY_Ary1D_data;
  Ary1D_u6p10_2 ClsdLoopHysHwAgQuadBlndX_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwAgQuadBlndY_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwAgQuadQlfrX_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwAgQuadQlfrY_Ary1D_data;
  Ary1D_u6p10_2 ClsdLoopHysHwVelQuadBlndX_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwVelQuadBlndY_Ary1D_data;
  Ary1D_u15p1_4 ClsdLoopHysRackFFacX_Ary1D_data;
  Ary2D_u2p14_12_4 ClsdLoopHysRackFFacY_Ary2D_data;
  Ary1D_u6p10_12 ClsdLoopHysRhoY_Ary1D_data;
  Ary1D_u9p7_5 ClsdLoopHysSysFricOffsLimX_Ary1D_data;
  Ary1D_u4p12_5 ClsdLoopHysSysFricOffsLimY_Ary1D_data;
  Ary1D_s4p11_7 ClsdLoopHysSysFricScaX_Ary1D_data;
  Ary1D_u2p14_7 ClsdLoopHysSysFricScaY_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimIntgtrSt = *TSC_ClsdLoopHys_Rte_Pim_IntgtrSt();
  *TSC_ClsdLoopHys_Rte_Pim_IntgtrSt() = PimIntgtrSt;

  ClsdLoopHysHwAgBlndFac_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgBlndFac_Val();
  ClsdLoopHysPolarity_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysPolarity_Val();
  ClsdLoopHysSteerInHwAgNegLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val();
  ClsdLoopHysSteerInHwAgNegUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val();
  ClsdLoopHysSteerInHwAgPosLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val();
  ClsdLoopHysSteerInHwAgPosUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val();
  ClsdLoopHysSteerOutHwAgNegLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val();
  ClsdLoopHysSteerOutHwAgNegUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val();
  ClsdLoopHysSteerOutHwAgPosLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val();
  ClsdLoopHysSteerOutHwAgPosUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val();
  (void)memcpy(ClsdLoopHysDeltaY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysDeltaY_Ary1D(), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysGainY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysGainY_Ary1D(), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysHwAgQuadBlndX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(), sizeof(Ary1D_u6p10_2));
  (void)memcpy(ClsdLoopHysHwAgQuadBlndY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwAgQuadQlfrX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwAgQuadQlfrY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwVelQuadBlndX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(), sizeof(Ary1D_u6p10_2));
  (void)memcpy(ClsdLoopHysHwVelQuadBlndY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysRackFFacX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(), sizeof(Ary1D_u15p1_4));
  (void)memcpy(ClsdLoopHysRackFFacY_Ary2D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(), sizeof(Ary2D_u2p14_12_4));
  (void)memcpy(ClsdLoopHysRhoY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRhoY_Ary1D(), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysSysFricOffsLimX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(), sizeof(Ary1D_u9p7_5));
  (void)memcpy(ClsdLoopHysSysFricOffsLimY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(), sizeof(Ary1D_u4p12_5));
  (void)memcpy(ClsdLoopHysSysFricScaX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(), sizeof(Ary1D_s4p11_7));
  (void)memcpy(ClsdLoopHysSysFricScaY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(), sizeof(Ary1D_u2p14_7));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopHysPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdEffort_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysFricOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdHys_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ClsdLoopHys_CODE) ClsdLoopHysPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopHysPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwAg_Val;
  float32 Read_HwTq_Val;
  float32 Read_HwTqCmdEffort_Val;
  float32 Read_HwVel_Val;
  float32 Read_RackFEstimd_Val;
  float32 Read_SysFricOffs_Val;
  float32 Read_VehSpd_Val;

  float32 PimIntgtrSt;

  float32 ClsdLoopHysHwAgBlndFac_Val_data;
  float32 ClsdLoopHysPolarity_Val_data;
  float32 ClsdLoopHysSteerInHwAgNegLowrLim_Val_data;
  float32 ClsdLoopHysSteerInHwAgNegUpprLim_Val_data;
  float32 ClsdLoopHysSteerInHwAgPosLowrLim_Val_data;
  float32 ClsdLoopHysSteerInHwAgPosUpprLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgNegLowrLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgNegUpprLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgPosLowrLim_Val_data;
  float32 ClsdLoopHysSteerOutHwAgPosUpprLim_Val_data;
  Ary1D_u6p10_12 ClsdLoopHysDeltaY_Ary1D_data;
  Ary1D_u6p10_12 ClsdLoopHysGainY_Ary1D_data;
  Ary1D_u6p10_2 ClsdLoopHysHwAgQuadBlndX_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwAgQuadBlndY_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwAgQuadQlfrX_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwAgQuadQlfrY_Ary1D_data;
  Ary1D_u6p10_2 ClsdLoopHysHwVelQuadBlndX_Ary1D_data;
  Ary1D_u2p14_2 ClsdLoopHysHwVelQuadBlndY_Ary1D_data;
  Ary1D_u15p1_4 ClsdLoopHysRackFFacX_Ary1D_data;
  Ary2D_u2p14_12_4 ClsdLoopHysRackFFacY_Ary2D_data;
  Ary1D_u6p10_12 ClsdLoopHysRhoY_Ary1D_data;
  Ary1D_u9p7_5 ClsdLoopHysSysFricOffsLimX_Ary1D_data;
  Ary1D_u4p12_5 ClsdLoopHysSysFricOffsLimY_Ary1D_data;
  Ary1D_s4p11_7 ClsdLoopHysSysFricScaX_Ary1D_data;
  Ary1D_u2p14_7 ClsdLoopHysSysFricScaY_Ary1D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimIntgtrSt = *TSC_ClsdLoopHys_Rte_Pim_IntgtrSt();
  *TSC_ClsdLoopHys_Rte_Pim_IntgtrSt() = PimIntgtrSt;

  ClsdLoopHysHwAgBlndFac_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgBlndFac_Val();
  ClsdLoopHysPolarity_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysPolarity_Val();
  ClsdLoopHysSteerInHwAgNegLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val();
  ClsdLoopHysSteerInHwAgNegUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val();
  ClsdLoopHysSteerInHwAgPosLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val();
  ClsdLoopHysSteerInHwAgPosUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val();
  ClsdLoopHysSteerOutHwAgNegLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val();
  ClsdLoopHysSteerOutHwAgNegUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val();
  ClsdLoopHysSteerOutHwAgPosLowrLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val();
  ClsdLoopHysSteerOutHwAgPosUpprLim_Val_data = TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val();
  (void)memcpy(ClsdLoopHysDeltaY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysDeltaY_Ary1D(), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysGainY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysGainY_Ary1D(), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysHwAgQuadBlndX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(), sizeof(Ary1D_u6p10_2));
  (void)memcpy(ClsdLoopHysHwAgQuadBlndY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwAgQuadQlfrX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwAgQuadQlfrY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwVelQuadBlndX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(), sizeof(Ary1D_u6p10_2));
  (void)memcpy(ClsdLoopHysHwVelQuadBlndY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysRackFFacX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(), sizeof(Ary1D_u15p1_4));
  (void)memcpy(ClsdLoopHysRackFFacY_Ary2D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(), sizeof(Ary2D_u2p14_12_4));
  (void)memcpy(ClsdLoopHysRhoY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysRhoY_Ary1D(), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysSysFricOffsLimX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(), sizeof(Ary1D_u9p7_5));
  (void)memcpy(ClsdLoopHysSysFricOffsLimY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(), sizeof(Ary1D_u4p12_5));
  (void)memcpy(ClsdLoopHysSysFricScaX_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(), sizeof(Ary1D_s4p11_7));
  (void)memcpy(ClsdLoopHysSysFricScaY_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(), sizeof(Ary1D_u2p14_7));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_ClsdLoopHys_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  fct_status = TSC_ClsdLoopHys_Rte_Read_HwAg_Val(&Read_HwAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_ClsdLoopHys_Rte_Read_HwTq_Val(&Read_HwTq_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_ClsdLoopHys_Rte_Read_HwTqCmdEffort_Val(&Read_HwTqCmdEffort_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_ClsdLoopHys_Rte_Read_HwVel_Val(&Read_HwVel_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_ClsdLoopHys_Rte_Read_RackFEstimd_Val(&Read_RackFEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_ClsdLoopHys_Rte_Read_SysFricOffs_Val(&Read_SysFricOffs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_ClsdLoopHys_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_ClsdLoopHys_Rte_Write_HwTqCmdHys_Val(Rte_InitValue_HwTqCmdHys_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ClsdLoopHys_STOP_SEC_CODE
#include "ClsdLoopHys_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
