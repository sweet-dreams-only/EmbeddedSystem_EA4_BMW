/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn02Rt01GroupD_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn02Rt01GroupD_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn02Rt01GroupD_Dummy>
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
 * u10p6
 *   
 *
 * u15p1
 *   
 *
 * u1p15
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

#include "Rte_AAACalRegn02Rt01GroupD_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn02Rt01GroupD_Dummy.h"


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
 * u10p6: Integer in interval [0...65535]
 * u15p1: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s4p11_7: Array with 7 element(s) of type s4p11
 * Ary1D_u10p6_4: Array with 4 element(s) of type u10p6
 * Ary1D_u15p1_24: Array with 24 element(s) of type u15p1
 * Ary1D_u15p1_4: Array with 4 element(s) of type u15p1
 * Ary1D_u15p1_9: Array with 9 element(s) of type u15p1
 * Ary1D_u1p15_4: Array with 4 element(s) of type u1p15
 * Ary1D_u1p15_9: Array with 9 element(s) of type u1p15
 * Ary1D_u2p14_2: Array with 2 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u2p14_7: Array with 7 element(s) of type u2p14
 * Ary1D_u4p12_24: Array with 24 element(s) of type u4p12
 * Ary1D_u4p12_5: Array with 5 element(s) of type u4p12
 * Ary1D_u4p12_9: Array with 9 element(s) of type u4p12
 * Ary1D_u6p10_12: Array with 12 element(s) of type u6p10
 * Ary1D_u6p10_2: Array with 2 element(s) of type u6p10
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary2D_u15p1_10_24: Array with 10 element(s) of type Ary1D_u15p1_24
 * Ary2D_u15p1_12_9: Array with 12 element(s) of type Ary1D_u15p1_9
 * Ary2D_u1p15_12_9: Array with 12 element(s) of type Ary1D_u1p15_9
 * Ary2D_u2p14_12_4: Array with 12 element(s) of type Ary1D_u2p14_4
 * Ary2D_u4p12_10_24: Array with 10 element(s) of type Ary1D_u4p12_24
 * Ary2D_u4p12_12_9: Array with 12 element(s) of type Ary1D_u4p12_9
 * Ary2D_u6p10_12_9: Array with 12 element(s) of type Ary1D_u6p10_9
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_ClsdLoopHysHwAgBlndFac_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysPolarity_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(Rte_Instance self)
 *   u10p6 *Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(Rte_Instance self)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u1p15 *Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_4
 *   u10p6 *Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(Rte_Instance self)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u1p15 *Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_4
 *   u6p10 *Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_9
 *   u4p12 *Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_9
 *   u15p1 *Rte_Prm_ClsdLoopDampgRackFX_Ary2D(Rte_Instance self)
 *     Returnvalue: u15p1* is of type Ary2D_u15p1_12_9
 *   u1p15 *Rte_Prm_ClsdLoopDampgRackFY_Ary2D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_12_9
 *   u6p10 *Rte_Prm_ClsdLoopHysDeltaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysGainY_Ary1D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u6p10 *Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u6p10 *Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_2
 *   u2p14 *Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_2
 *   u15p1 *Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(Rte_Instance self)
 *     Returnvalue: u15p1* is of type Ary1D_u15p1_4
 *   u2p14 *Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_12_4
 *   u6p10 *Rte_Prm_ClsdLoopHysRhoY_Ary1D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_12
 *   u9p7 *Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u4p12 *Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_5
 *   s4p11 *Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(Rte_Instance self)
 *     Returnvalue: s4p11* is of type Ary1D_s4p11_7
 *   u2p14 *Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(Rte_Instance self)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_7
 *   u15p1 *Rte_Prm_EffortRackFX_Ary2D(Rte_Instance self)
 *     Returnvalue: u15p1* is of type Ary2D_u15p1_10_24
 *   u4p12 *Rte_Prm_EffortRackFY_Ary2D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_10_24
 *   u9p7 *Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *
 *********************************************************************************************************************/


#define AAACalRegn02Rt01GroupD_Dummy_START_SEC_CODE
#include "AAACalRegn02Rt01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn02Rt01GroupDDummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn02Rt01GroupDDummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn02Rt01GroupD_Dummy_CODE) CalRegn02Rt01GroupDDummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn02Rt01GroupDDummyInit1
 *********************************************************************************************************************/

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
  Ary1D_u10p6_4 ClsdLoopDampgEotEntrX_Ary1D_data;
  Ary1D_u1p15_4 ClsdLoopDampgEotEntrY_Ary1D_data;
  Ary1D_u10p6_4 ClsdLoopDampgEotExitX_Ary1D_data;
  Ary1D_u1p15_4 ClsdLoopDampgEotExitY_Ary1D_data;
  Ary2D_u6p10_12_9 ClsdLoopDampgPinionVelX_Ary2D_data;
  Ary2D_u4p12_12_9 ClsdLoopDampgPinionVelY_Ary2D_data;
  Ary2D_u15p1_12_9 ClsdLoopDampgRackFX_Ary2D_data;
  Ary2D_u1p15_12_9 ClsdLoopDampgRackFY_Ary2D_data;
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
  Ary2D_u15p1_10_24 EffortRackFX_Ary2D_data;
  Ary2D_u4p12_10_24 EffortRackFY_Ary2D_data;
  Ary1D_u9p7_10 EffortVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  ClsdLoopHysHwAgBlndFac_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysHwAgBlndFac_Val(self);
  ClsdLoopHysPolarity_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysPolarity_Val(self);
  ClsdLoopHysSteerInHwAgNegLowrLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val(self);
  ClsdLoopHysSteerInHwAgNegUpprLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val(self);
  ClsdLoopHysSteerInHwAgPosLowrLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val(self);
  ClsdLoopHysSteerInHwAgPosUpprLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val(self);
  ClsdLoopHysSteerOutHwAgNegLowrLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(self);
  ClsdLoopHysSteerOutHwAgNegUpprLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(self);
  ClsdLoopHysSteerOutHwAgPosLowrLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(self);
  ClsdLoopHysSteerOutHwAgPosUpprLim_Val_data = TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(self);
  (void)memcpy(ClsdLoopDampgEotEntrX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(self), sizeof(Ary1D_u10p6_4));
  (void)memcpy(ClsdLoopDampgEotEntrY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(self), sizeof(Ary1D_u1p15_4));
  (void)memcpy(ClsdLoopDampgEotExitX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(self), sizeof(Ary1D_u10p6_4));
  (void)memcpy(ClsdLoopDampgEotExitY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(self), sizeof(Ary1D_u1p15_4));
  (void)memcpy(ClsdLoopDampgPinionVelX_Ary2D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(self), sizeof(Ary2D_u6p10_12_9));
  (void)memcpy(ClsdLoopDampgPinionVelY_Ary2D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(self), sizeof(Ary2D_u4p12_12_9));
  (void)memcpy(ClsdLoopDampgRackFX_Ary2D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgRackFX_Ary2D(self), sizeof(Ary2D_u15p1_12_9));
  (void)memcpy(ClsdLoopDampgRackFY_Ary2D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopDampgRackFY_Ary2D(self), sizeof(Ary2D_u1p15_12_9));
  (void)memcpy(ClsdLoopHysDeltaY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysDeltaY_Ary1D(self), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysGainY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysGainY_Ary1D(self), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysHwAgQuadBlndX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(self), sizeof(Ary1D_u6p10_2));
  (void)memcpy(ClsdLoopHysHwAgQuadBlndY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(self), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwAgQuadQlfrX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(self), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwAgQuadQlfrY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(self), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysHwVelQuadBlndX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(self), sizeof(Ary1D_u6p10_2));
  (void)memcpy(ClsdLoopHysHwVelQuadBlndY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(self), sizeof(Ary1D_u2p14_2));
  (void)memcpy(ClsdLoopHysRackFFacX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(self), sizeof(Ary1D_u15p1_4));
  (void)memcpy(ClsdLoopHysRackFFacY_Ary2D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(self), sizeof(Ary2D_u2p14_12_4));
  (void)memcpy(ClsdLoopHysRhoY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysRhoY_Ary1D(self), sizeof(Ary1D_u6p10_12));
  (void)memcpy(ClsdLoopHysSysFricOffsLimX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(self), sizeof(Ary1D_u9p7_5));
  (void)memcpy(ClsdLoopHysSysFricOffsLimY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(self), sizeof(Ary1D_u4p12_5));
  (void)memcpy(ClsdLoopHysSysFricScaX_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(self), sizeof(Ary1D_s4p11_7));
  (void)memcpy(ClsdLoopHysSysFricScaY_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(self), sizeof(Ary1D_u2p14_7));
  (void)memcpy(EffortRackFX_Ary2D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_EffortRackFX_Ary2D(self), sizeof(Ary2D_u15p1_10_24));
  (void)memcpy(EffortRackFY_Ary2D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_EffortRackFY_Ary2D(self), sizeof(Ary2D_u4p12_10_24));
  (void)memcpy(EffortVehSpdBilnrSeln_Ary1D_data, TSC_AAACalRegn02Rt01GroupD_Dummy_Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(self), sizeof(Ary1D_u9p7_10));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn02Rt01GroupD_Dummy_STOP_SEC_CODE
#include "AAACalRegn02Rt01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
