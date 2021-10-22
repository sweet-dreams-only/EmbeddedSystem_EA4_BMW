/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn01Inin01GroupC_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn01Inin01GroupC_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn01Inin01GroupC_Dummy>
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

#include "Rte_AAACalRegn01Inin01GroupC_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn01Inin01GroupC_Dummy.h"


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
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s4p11_13: Array with 13 element(s) of type s4p11
 * Ary1D_u4p12_20: Array with 20 element(s) of type u4p12
 * Ary1D_u6p10_20: Array with 20 element(s) of type u6p10
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary2D_s4p11_10_13: Array with 10 element(s) of type Ary1D_s4p11_13
 * Ary2D_u4p12_12_20: Array with 12 element(s) of type Ary1D_u4p12_20
 * Ary2D_u6p10_12_20: Array with 12 element(s) of type Ary1D_u6p10_20
 * Ary2D_u6p10_5_9: Array with 5 element(s) of type Ary1D_u6p10_9
 *
 * Record Types:
 * =============
 * FilNotchGainRec1: Record with elements
 *   FilGainB0 of type float32
 *   FilGainB1 of type float32
 *   FilGainB2 of type float32
 *   FilGainA1 of type float32
 *   FilGainA2 of type float32
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
 *   float32 Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnOffsSlewThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnOffsThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(Rte_Instance self)
 *   u6p10 *Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_5_9
 *   u6p10 *Rte_Prm_FalbckAssiAssiX_Ary2D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_20
 *   u4p12 *Rte_Prm_FalbckAssiAssiY_Ary2D(Rte_Instance self)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_20
 *   s4p11 *Rte_Prm_GlbLimrBndX_Ary2D(Rte_Instance self)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   s4p11 *Rte_Prm_GlbLimrBndY_Ary2D(Rte_Instance self)
 *     Returnvalue: s4p11* is of type Ary2D_s4p11_10_13
 *   u9p7 *Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *   FilNotchGainRec1 *Rte_Prm_FalbckAssiNotchFil_Rec(Rte_Instance self)
 *   FilNotchGainRec1 *Rte_Prm_GlbLimrNotchFilStruct_Rec(Rte_Instance self)
 *
 *********************************************************************************************************************/


#define AAACalRegn01Inin01GroupC_Dummy_START_SEC_CODE
#include "AAACalRegn01Inin01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn01Inin01GroupCDummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01GroupCDummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn01Inin01GroupC_Dummy_CODE) CalRegn01Inin01GroupCDummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn01Inin01GroupCDummyInit1
 *********************************************************************************************************************/

  float32 CtrldVelRtnDesVelLpFilFrq_Val_data;
  float32 CtrldVelRtnHwTqLpFilFrq_Val_data;
  float32 CtrldVelRtnHwTqScaSelnSlewHiLim_Val_data;
  float32 CtrldVelRtnHwTqScaSelnSlewLoLim_Val_data;
  float32 CtrldVelRtnHwTqScaSelnTqThd_Val_data;
  float32 CtrldVelRtnHwTqScaSelnVelThd_Val_data;
  float32 CtrldVelRtnOffsSlewThd_Val_data;
  float32 CtrldVelRtnOffsThd_Val_data;
  float32 CtrldVelRtnScaLpFilFrq_Val_data;
  Ary2D_u6p10_5_9 CtrldVelRtnIntgrLimY_Ary2D_data;
  Ary2D_u6p10_12_20 FalbckAssiAssiX_Ary2D_data;
  Ary2D_u4p12_12_20 FalbckAssiAssiY_Ary2D_data;
  Ary2D_s4p11_10_13 GlbLimrBndX_Ary2D_data;
  Ary2D_s4p11_10_13 GlbLimrBndY_Ary2D_data;
  Ary1D_u9p7_10 GlbLimrVehSpdBilnrSeln_Ary1D_data;
  FilNotchGainRec1 FalbckAssiNotchFil_Rec_data;
  FilNotchGainRec1 GlbLimrNotchFilStruct_Rec_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  CtrldVelRtnDesVelLpFilFrq_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(self);
  CtrldVelRtnHwTqLpFilFrq_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(self);
  CtrldVelRtnHwTqScaSelnSlewHiLim_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(self);
  CtrldVelRtnHwTqScaSelnSlewLoLim_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(self);
  CtrldVelRtnHwTqScaSelnTqThd_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(self);
  CtrldVelRtnHwTqScaSelnVelThd_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(self);
  CtrldVelRtnOffsSlewThd_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnOffsSlewThd_Val(self);
  CtrldVelRtnOffsThd_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnOffsThd_Val(self);
  CtrldVelRtnScaLpFilFrq_Val_data = TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(self);
  (void)memcpy(CtrldVelRtnIntgrLimY_Ary2D_data, TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(self), sizeof(Ary2D_u6p10_5_9));
  (void)memcpy(FalbckAssiAssiX_Ary2D_data, TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_FalbckAssiAssiX_Ary2D(self), sizeof(Ary2D_u6p10_12_20));
  (void)memcpy(FalbckAssiAssiY_Ary2D_data, TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_FalbckAssiAssiY_Ary2D(self), sizeof(Ary2D_u4p12_12_20));
  (void)memcpy(GlbLimrBndX_Ary2D_data, TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_GlbLimrBndX_Ary2D(self), sizeof(Ary2D_s4p11_10_13));
  (void)memcpy(GlbLimrBndY_Ary2D_data, TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_GlbLimrBndY_Ary2D(self), sizeof(Ary2D_s4p11_10_13));
  (void)memcpy(GlbLimrVehSpdBilnrSeln_Ary1D_data, TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(self), sizeof(Ary1D_u9p7_10));
  FalbckAssiNotchFil_Rec_data = *TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_FalbckAssiNotchFil_Rec(self);
  GlbLimrNotchFilStruct_Rec_data = *TSC_AAACalRegn01Inin01GroupC_Dummy_Rte_Prm_GlbLimrNotchFilStruct_Rec(self);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn01Inin01GroupC_Dummy_STOP_SEC_CODE
#include "AAACalRegn01Inin01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
