/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  AAACalRegn02Rt01GroupA_Dummy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  AAACalRegn02Rt01GroupA_Dummy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <AAACalRegn02Rt01GroupA_Dummy>
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
 * u12p4
 *   
 *
 * u16p0
 *   
 *
 * u1p15
 *   
 *
 * u5p11
 *   
 *
 * u6p10
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_AAACalRegn02Rt01GroupA_Dummy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_AAACalRegn02Rt01GroupA_Dummy.h"


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
 * u12p4: Integer in interval [0...65535]
 * u16p0: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u5p11: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u12p4_9: Array with 9 element(s) of type u12p4
 * Ary1D_u1p15_11: Array with 11 element(s) of type u1p15
 * Ary1D_u5p11_9: Array with 9 element(s) of type u5p11
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u9p7_11: Array with 11 element(s) of type u9p7
 * Ary2D_u5p11_9_9: Array with 9 element(s) of type Ary1D_u5p11_9
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
 *   float32 Rte_Prm_BmwStReqMgrHwTqThd_Val(Rte_Instance self)
 *   float32 Rte_Prm_BmwStReqMgrOperRampRate_Val(Rte_Instance self)
 *   float32 Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val(Rte_Instance self)
 *   float32 Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val(Rte_Instance self)
 *   u16p0 Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val(Rte_Instance self)
 *   u5p11 *Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(Rte_Instance self)
 *     Returnvalue: u5p11* is of type Ary2D_u5p11_9_9
 *   u6p10 *Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(Rte_Instance self)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_9
 *   u12p4 *Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(Rte_Instance self)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u9p7 *Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(Rte_Instance self)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_11
 *   u1p15 *Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(Rte_Instance self)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_11
 *
 *********************************************************************************************************************/


#define AAACalRegn02Rt01GroupA_Dummy_START_SEC_CODE
#include "AAACalRegn02Rt01GroupA_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CalRegn02Rt01GroupADummyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn02Rt01GroupADummyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, AAACalRegn02Rt01GroupA_Dummy_CODE) CalRegn02Rt01GroupADummyInit1(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CalRegn02Rt01GroupADummyInit1
 *********************************************************************************************************************/

  float32 BmwStReqMgrHwTqThd_Val_data;
  float32 BmwStReqMgrOperRampRate_Val_data;
  float32 BmwStReqMgrSwtOffSpdLim_Val_data;
  float32 BmwStReqMgrSysProtnRednFacThd_Val_data;
  u16p0 BmwStReqMgrDrvrActvTmrThd_Val_data;
  Ary2D_u5p11_9_9 BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D_data;
  Ary1D_u6p10_9 BmwPwrPrkgDampgHwVelTblX_Ary1D_data;
  Ary1D_u12p4_9 BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D_data;
  Ary1D_u9p7_11 BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D_data;
  Ary1D_u1p15_11 BmwPwrPrkgDampgVehSpdScaFacY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  BmwStReqMgrHwTqThd_Val_data = TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwStReqMgrHwTqThd_Val(self);
  BmwStReqMgrOperRampRate_Val_data = TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwStReqMgrOperRampRate_Val(self);
  BmwStReqMgrSwtOffSpdLim_Val_data = TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val(self);
  BmwStReqMgrSysProtnRednFacThd_Val_data = TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val(self);
  BmwStReqMgrDrvrActvTmrThd_Val_data = TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val(self);
  (void)memcpy(BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D_data, TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(self), sizeof(Ary2D_u5p11_9_9));
  (void)memcpy(BmwPwrPrkgDampgHwVelTblX_Ary1D_data, TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(self), sizeof(Ary1D_u6p10_9));
  (void)memcpy(BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D_data, TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(self), sizeof(Ary1D_u12p4_9));
  (void)memcpy(BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D_data, TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(self), sizeof(Ary1D_u9p7_11));
  (void)memcpy(BmwPwrPrkgDampgVehSpdScaFacY_Ary1D_data, TSC_AAACalRegn02Rt01GroupA_Dummy_Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(self), sizeof(Ary1D_u1p15_11));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define AAACalRegn02Rt01GroupA_Dummy_STOP_SEC_CODE
#include "AAACalRegn02Rt01GroupA_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
