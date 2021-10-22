/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Effort.c
 *        Config:  EPS.dpa
 *     SW-C Type:  Effort
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <Effort>
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
 * s15p0
 *   
 *
 * u15p1
 *   
 *
 * u1p15
 *   
 *
 * u4p12
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Effort.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Effort.h"


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
 * s15p0: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * u15p1: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s15p0_10: Array with 10 element(s) of type s15p0
 * Ary1D_u15p1_24: Array with 24 element(s) of type u15p1
 * Ary1D_u1p15_10: Array with 10 element(s) of type u1p15
 * Ary1D_u4p12_24: Array with 24 element(s) of type u4p12
 * Ary1D_u9p7_10: Array with 10 element(s) of type u9p7
 * Ary2D_u15p1_10_24: Array with 10 element(s) of type Ary1D_u15p1_24
 * Ary2D_u4p12_10_24: Array with 10 element(s) of type Ary1D_u4p12_24
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
 *   float32 Rte_Prm_EffortScaRackFThd_Val(void)
 *   u15p1 *Rte_Prm_EffortRackFX_Ary2D(void)
 *     Returnvalue: u15p1* is of type Ary2D_u15p1_10_24
 *   u4p12 *Rte_Prm_EffortRackFY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_10_24
 *   s15p0 *Rte_Prm_EffortScaBlndX_Ary1D(void)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_10
 *   u1p15 *Rte_Prm_EffortScaBlndY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_10
 *   u9p7 *Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *
 *********************************************************************************************************************/


#define Effort_START_SEC_CODE
#include "Effort_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EffortInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EffortInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Effort_CODE) EffortInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EffortInit1
 *********************************************************************************************************************/

  float32 EffortScaRackFThd_Val_data;
  Ary2D_u15p1_10_24 EffortRackFX_Ary2D_data;
  Ary2D_u4p12_10_24 EffortRackFY_Ary2D_data;
  Ary1D_s15p0_10 EffortScaBlndX_Ary1D_data;
  Ary1D_u1p15_10 EffortScaBlndY_Ary1D_data;
  Ary1D_u9p7_10 EffortVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  EffortScaRackFThd_Val_data = TSC_Effort_Rte_Prm_EffortScaRackFThd_Val();
  (void)memcpy(EffortRackFX_Ary2D_data, TSC_Effort_Rte_Prm_EffortRackFX_Ary2D(), sizeof(Ary2D_u15p1_10_24));
  (void)memcpy(EffortRackFY_Ary2D_data, TSC_Effort_Rte_Prm_EffortRackFY_Ary2D(), sizeof(Ary2D_u4p12_10_24));
  (void)memcpy(EffortScaBlndX_Ary1D_data, TSC_Effort_Rte_Prm_EffortScaBlndX_Ary1D(), sizeof(Ary1D_s15p0_10));
  (void)memcpy(EffortScaBlndY_Ary1D_data, TSC_Effort_Rte_Prm_EffortScaBlndY_Ary1D(), sizeof(Ary1D_u1p15_10));
  (void)memcpy(EffortVehSpdBilnrSeln_Ary1D_data, TSC_Effort_Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_10));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EffortPer1
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
 *   Std_ReturnType Rte_Read_EffortCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdEffort_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EffortPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Effort_CODE) EffortPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EffortPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_EffortCmdSca_Val;
  float32 Read_RackFEstimd_Val;
  float32 Read_VehSpd_Val;

  float32 EffortScaRackFThd_Val_data;
  Ary2D_u15p1_10_24 EffortRackFX_Ary2D_data;
  Ary2D_u4p12_10_24 EffortRackFY_Ary2D_data;
  Ary1D_s15p0_10 EffortScaBlndX_Ary1D_data;
  Ary1D_u1p15_10 EffortScaBlndY_Ary1D_data;
  Ary1D_u9p7_10 EffortVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  EffortScaRackFThd_Val_data = TSC_Effort_Rte_Prm_EffortScaRackFThd_Val();
  (void)memcpy(EffortRackFX_Ary2D_data, TSC_Effort_Rte_Prm_EffortRackFX_Ary2D(), sizeof(Ary2D_u15p1_10_24));
  (void)memcpy(EffortRackFY_Ary2D_data, TSC_Effort_Rte_Prm_EffortRackFY_Ary2D(), sizeof(Ary2D_u4p12_10_24));
  (void)memcpy(EffortScaBlndX_Ary1D_data, TSC_Effort_Rte_Prm_EffortScaBlndX_Ary1D(), sizeof(Ary1D_s15p0_10));
  (void)memcpy(EffortScaBlndY_Ary1D_data, TSC_Effort_Rte_Prm_EffortScaBlndY_Ary1D(), sizeof(Ary1D_u1p15_10));
  (void)memcpy(EffortVehSpdBilnrSeln_Ary1D_data, TSC_Effort_Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_10));

  fct_status = TSC_Effort_Rte_Read_EffortCmdSca_Val(&Read_EffortCmdSca_Val);
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

  fct_status = TSC_Effort_Rte_Read_RackFEstimd_Val(&Read_RackFEstimd_Val);
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

  fct_status = TSC_Effort_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_Effort_Rte_Write_HwTqCmdEffort_Val(Rte_InitValue_HwTqCmdEffort_Val);
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


#define Effort_STOP_SEC_CODE
#include "Effort_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
