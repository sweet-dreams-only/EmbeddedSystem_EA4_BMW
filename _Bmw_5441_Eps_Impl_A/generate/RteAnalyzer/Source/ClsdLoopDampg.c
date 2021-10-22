/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  ClsdLoopDampg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  ClsdLoopDampg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <ClsdLoopDampg>
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
 * EotSt1
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

#include "Rte_ClsdLoopDampg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_ClsdLoopDampg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void ClsdLoopDampg_TestDefines(void);


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
 * u10p6: Integer in interval [0...65535]
 * u15p1: Integer in interval [0...65535]
 * u1p15: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * EotSt1: Enumeration of integer in interval [0...255] with enumerators
 *   EOTST_DISAD (0U)
 *   EOTST_NORM (1U)
 *   EOTST_ENTR (2U)
 *   EOTST_EXIT (3U)
 *
 * Array Types:
 * ============
 * Ary1D_u10p6_4: Array with 4 element(s) of type u10p6
 * Ary1D_u15p1_9: Array with 9 element(s) of type u15p1
 * Ary1D_u1p15_4: Array with 4 element(s) of type u1p15
 * Ary1D_u1p15_9: Array with 9 element(s) of type u1p15
 * Ary1D_u4p12_9: Array with 9 element(s) of type u4p12
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u9p7_12: Array with 12 element(s) of type u9p7
 * Ary2D_u15p1_12_9: Array with 12 element(s) of type Ary1D_u15p1_9
 * Ary2D_u1p15_12_9: Array with 12 element(s) of type Ary1D_u1p15_9
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
 *   u10p6 *Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(void)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u1p15 *Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_4
 *   u10p6 *Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(void)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u1p15 *Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_4
 *   u6p10 *Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_9
 *   u4p12 *Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_9
 *   u15p1 *Rte_Prm_ClsdLoopDampgRackFX_Ary2D(void)
 *     Returnvalue: u15p1* is of type Ary2D_u15p1_12_9
 *   u1p15 *Rte_Prm_ClsdLoopDampgRackFY_Ary2D(void)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_12_9
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


#define ClsdLoopDampg_START_SEC_CODE
#include "ClsdLoopDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopDampgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopDampgInit1
 *********************************************************************************************************************/

  Ary1D_u10p6_4 ClsdLoopDampgEotEntrX_Ary1D_data;
  Ary1D_u1p15_4 ClsdLoopDampgEotEntrY_Ary1D_data;
  Ary1D_u10p6_4 ClsdLoopDampgEotExitX_Ary1D_data;
  Ary1D_u1p15_4 ClsdLoopDampgEotExitY_Ary1D_data;
  Ary2D_u6p10_12_9 ClsdLoopDampgPinionVelX_Ary2D_data;
  Ary2D_u4p12_12_9 ClsdLoopDampgPinionVelY_Ary2D_data;
  Ary2D_u15p1_12_9 ClsdLoopDampgRackFX_Ary2D_data;
  Ary2D_u1p15_12_9 ClsdLoopDampgRackFY_Ary2D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memcpy(ClsdLoopDampgEotEntrX_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(), sizeof(Ary1D_u10p6_4));
  (void)memcpy(ClsdLoopDampgEotEntrY_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(), sizeof(Ary1D_u1p15_4));
  (void)memcpy(ClsdLoopDampgEotExitX_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(), sizeof(Ary1D_u10p6_4));
  (void)memcpy(ClsdLoopDampgEotExitY_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(), sizeof(Ary1D_u1p15_4));
  (void)memcpy(ClsdLoopDampgPinionVelX_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(), sizeof(Ary2D_u6p10_12_9));
  (void)memcpy(ClsdLoopDampgPinionVelY_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(), sizeof(Ary2D_u4p12_12_9));
  (void)memcpy(ClsdLoopDampgRackFX_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgRackFX_Ary2D(), sizeof(Ary2D_u15p1_12_9));
  (void)memcpy(ClsdLoopDampgRackFY_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgRackFY_Ary2D(), sizeof(Ary2D_u1p15_12_9));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  ClsdLoopDampg_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopDampgPer1
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
 *   Std_ReturnType Rte_Read_DampgCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EotCtrlSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EotDeltaAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EotSt_Val(EotSt1 *data)
 *   Std_ReturnType Rte_Read_PinionVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdDampg_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopDampgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClsdLoopDampgPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_DampgCmdSca_Val;
  float32 Read_EotCtrlSca_Val;
  float32 Read_EotDeltaAg_Val;
  EotSt1 Read_EotSt_Val;
  float32 Read_PinionVel_Val;
  float32 Read_RackFEstimd_Val;
  float32 Read_VehSpd_Val;

  Ary1D_u10p6_4 ClsdLoopDampgEotEntrX_Ary1D_data;
  Ary1D_u1p15_4 ClsdLoopDampgEotEntrY_Ary1D_data;
  Ary1D_u10p6_4 ClsdLoopDampgEotExitX_Ary1D_data;
  Ary1D_u1p15_4 ClsdLoopDampgEotExitY_Ary1D_data;
  Ary2D_u6p10_12_9 ClsdLoopDampgPinionVelX_Ary2D_data;
  Ary2D_u4p12_12_9 ClsdLoopDampgPinionVelY_Ary2D_data;
  Ary2D_u15p1_12_9 ClsdLoopDampgRackFX_Ary2D_data;
  Ary2D_u1p15_12_9 ClsdLoopDampgRackFY_Ary2D_data;
  Ary1D_u9p7_12 SysGlbPrmVehSpdBilnrSeln_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memcpy(ClsdLoopDampgEotEntrX_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(), sizeof(Ary1D_u10p6_4));
  (void)memcpy(ClsdLoopDampgEotEntrY_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(), sizeof(Ary1D_u1p15_4));
  (void)memcpy(ClsdLoopDampgEotExitX_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(), sizeof(Ary1D_u10p6_4));
  (void)memcpy(ClsdLoopDampgEotExitY_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(), sizeof(Ary1D_u1p15_4));
  (void)memcpy(ClsdLoopDampgPinionVelX_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(), sizeof(Ary2D_u6p10_12_9));
  (void)memcpy(ClsdLoopDampgPinionVelY_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(), sizeof(Ary2D_u4p12_12_9));
  (void)memcpy(ClsdLoopDampgRackFX_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgRackFX_Ary2D(), sizeof(Ary2D_u15p1_12_9));
  (void)memcpy(ClsdLoopDampgRackFY_Ary2D_data, TSC_ClsdLoopDampg_Rte_Prm_ClsdLoopDampgRackFY_Ary2D(), sizeof(Ary2D_u1p15_12_9));
  (void)memcpy(SysGlbPrmVehSpdBilnrSeln_Ary1D_data, TSC_ClsdLoopDampg_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_12));

  fct_status = TSC_ClsdLoopDampg_Rte_Read_DampgCmdSca_Val(&Read_DampgCmdSca_Val);
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

  fct_status = TSC_ClsdLoopDampg_Rte_Read_EotCtrlSca_Val(&Read_EotCtrlSca_Val);
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

  fct_status = TSC_ClsdLoopDampg_Rte_Read_EotDeltaAg_Val(&Read_EotDeltaAg_Val);
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

  fct_status = TSC_ClsdLoopDampg_Rte_Read_EotSt_Val(&Read_EotSt_Val);
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

  fct_status = TSC_ClsdLoopDampg_Rte_Read_PinionVel_Val(&Read_PinionVel_Val);
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

  fct_status = TSC_ClsdLoopDampg_Rte_Read_RackFEstimd_Val(&Read_RackFEstimd_Val);
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

  fct_status = TSC_ClsdLoopDampg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_ClsdLoopDampg_Rte_Write_HwTqCmdDampg_Val(Rte_InitValue_HwTqCmdDampg_Val);
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


#define ClsdLoopDampg_STOP_SEC_CODE
#include "ClsdLoopDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void ClsdLoopDampg_TestDefines(void)
{
  /* Enumeration Data Types */

  EotSt1 Test_EotSt1_V_1 = EOTST_DISAD;
  EotSt1 Test_EotSt1_V_2 = EOTST_NORM;
  EotSt1 Test_EotSt1_V_3 = EOTST_ENTR;
  EotSt1 Test_EotSt1_V_4 = EOTST_EXIT;
}

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
