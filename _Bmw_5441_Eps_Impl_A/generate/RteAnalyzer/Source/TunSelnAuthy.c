/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TunSelnAuthy.c
 *        Config:  EPS.dpa
 *     SW-C Type:  TunSelnAuthy
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <TunSelnAuthy>
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

#include "Rte_TunSelnAuthy.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_TunSelnAuthy.h"


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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u4p12_6: Array with 6 element(s) of type u4p12
 * Ary1D_u6p10_6: Array with 6 element(s) of type u6p10
 * Ary1D_u9p7_6: Array with 6 element(s) of type u9p7
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
 *   boolean Rte_Prm_TunSelnAuthyTunSelnRtDiCmd_Logl(void)
 *   u4p12 *Rte_Prm_TunSelnAuthyHwTqY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_6
 *   u6p10 *Rte_Prm_TunSelnAuthyHwVelY_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_6
 *   u9p7 *Rte_Prm_TunSelnAuthyVehSpdX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *
 *********************************************************************************************************************/


#define TunSelnAuthy_START_SEC_CODE
#include "TunSelnAuthy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RtCalChgReq_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RtCalChgReq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TunSelnRtDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RtCalChgReq_Oper(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RtCalChgReq_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RtCalChgReq_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, TunSelnAuthy_CODE) RtCalChgReq_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RtCalChgReq_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  float32 Read_HwVel_Val;
  boolean Read_TunSelnRtDi_Logl;
  float32 Read_VehSpd_Val;

  boolean TunSelnAuthyTunSelnRtDiCmd_Logl_data;
  Ary1D_u4p12_6 TunSelnAuthyHwTqY_Ary1D_data;
  Ary1D_u6p10_6 TunSelnAuthyHwVelY_Ary1D_data;
  Ary1D_u9p7_6 TunSelnAuthyVehSpdX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TunSelnAuthyTunSelnRtDiCmd_Logl_data = TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyTunSelnRtDiCmd_Logl();
  (void)memcpy(TunSelnAuthyHwTqY_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyHwTqY_Ary1D(), sizeof(Ary1D_u4p12_6));
  (void)memcpy(TunSelnAuthyHwVelY_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyHwVelY_Ary1D(), sizeof(Ary1D_u6p10_6));
  (void)memcpy(TunSelnAuthyVehSpdX_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyVehSpdX_Ary1D(), sizeof(Ary1D_u9p7_6));

  fct_status = TSC_TunSelnAuthy_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_TunSelnAuthy_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_TunSelnAuthy_Rte_Read_TunSelnRtDi_Logl(&Read_TunSelnRtDi_Logl);
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

  fct_status = TSC_TunSelnAuthy_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TunSelnAuthyInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TunSelnAuthyInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TunSelnAuthy_CODE) TunSelnAuthyInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TunSelnAuthyInit1
 *********************************************************************************************************************/

  boolean TunSelnAuthyTunSelnRtDiCmd_Logl_data;
  Ary1D_u4p12_6 TunSelnAuthyHwTqY_Ary1D_data;
  Ary1D_u6p10_6 TunSelnAuthyHwVelY_Ary1D_data;
  Ary1D_u9p7_6 TunSelnAuthyVehSpdX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TunSelnAuthyTunSelnRtDiCmd_Logl_data = TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyTunSelnRtDiCmd_Logl();
  (void)memcpy(TunSelnAuthyHwTqY_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyHwTqY_Ary1D(), sizeof(Ary1D_u4p12_6));
  (void)memcpy(TunSelnAuthyHwVelY_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyHwVelY_Ary1D(), sizeof(Ary1D_u6p10_6));
  (void)memcpy(TunSelnAuthyVehSpdX_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyVehSpdX_Ary1D(), sizeof(Ary1D_u9p7_6));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: XcpCalChgReq_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <XcpCalChgReq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType XcpCalChgReq_Oper(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_XcpCalChgReq_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: XcpCalChgReq_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, TunSelnAuthy_CODE) XcpCalChgReq_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: XcpCalChgReq_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_VehSpd_Val;

  boolean TunSelnAuthyTunSelnRtDiCmd_Logl_data;
  Ary1D_u4p12_6 TunSelnAuthyHwTqY_Ary1D_data;
  Ary1D_u6p10_6 TunSelnAuthyHwVelY_Ary1D_data;
  Ary1D_u9p7_6 TunSelnAuthyVehSpdX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TunSelnAuthyTunSelnRtDiCmd_Logl_data = TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyTunSelnRtDiCmd_Logl();
  (void)memcpy(TunSelnAuthyHwTqY_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyHwTqY_Ary1D(), sizeof(Ary1D_u4p12_6));
  (void)memcpy(TunSelnAuthyHwVelY_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyHwVelY_Ary1D(), sizeof(Ary1D_u6p10_6));
  (void)memcpy(TunSelnAuthyVehSpdX_Ary1D_data, TSC_TunSelnAuthy_Rte_Prm_TunSelnAuthyVehSpdX_Ary1D(), sizeof(Ary1D_u9p7_6));

  fct_status = TSC_TunSelnAuthy_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define TunSelnAuthy_STOP_SEC_CODE
#include "TunSelnAuthy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
