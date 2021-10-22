/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwPwrPrkgDampg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwPwrPrkgDampg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwPwrPrkgDampg>
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

#include "Rte_BmwPwrPrkgDampg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwPwrPrkgDampg.h"


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
 * u12p4: Integer in interval [0...65535]
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
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_DampgCmdPwrPrkgStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwPwrPrkgDampgMaxRate_Val(void)
 *   float32 Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val(void)
 *   boolean Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl(void)
 *   u5p11 *Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(void)
 *     Returnvalue: u5p11* is of type Ary2D_u5p11_9_9
 *   u6p10 *Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_9
 *   u12p4 *Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u9p7 *Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_11
 *   u1p15 *Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_11
 *
 *********************************************************************************************************************/


#define BmwPwrPrkgDampg_START_SEC_CODE
#include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwPwrPrkgDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgInit1
 *********************************************************************************************************************/

  float32 PimDampgCmdPwrPrkgStVari;

  float32 BmwPwrPrkgDampgMaxRate_Val_data;
  float32 BmwPwrPrkgDampgMinPinionAgConf_Val_data;
  boolean BmwPwrPrkgDampgDiScadDampg_Logl_data;
  Ary2D_u5p11_9_9 BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D_data;
  Ary1D_u6p10_9 BmwPwrPrkgDampgHwVelTblX_Ary1D_data;
  Ary1D_u12p4_9 BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D_data;
  Ary1D_u9p7_11 BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D_data;
  Ary1D_u1p15_11 BmwPwrPrkgDampgVehSpdScaFacY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDampgCmdPwrPrkgStVari = *TSC_BmwPwrPrkgDampg_Rte_Pim_DampgCmdPwrPrkgStVari();
  *TSC_BmwPwrPrkgDampg_Rte_Pim_DampgCmdPwrPrkgStVari() = PimDampgCmdPwrPrkgStVari;

  BmwPwrPrkgDampgMaxRate_Val_data = TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgMaxRate_Val();
  BmwPwrPrkgDampgMinPinionAgConf_Val_data = TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val();
  BmwPwrPrkgDampgDiScadDampg_Logl_data = TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl();
  (void)memcpy(BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(), sizeof(Ary2D_u5p11_9_9));
  (void)memcpy(BmwPwrPrkgDampgHwVelTblX_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(), sizeof(Ary1D_u6p10_9));
  (void)memcpy(BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(), sizeof(Ary1D_u12p4_9));
  (void)memcpy(BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(), sizeof(Ary1D_u9p7_11));
  (void)memcpy(BmwPwrPrkgDampgVehSpdScaFacY_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(), sizeof(Ary1D_u1p15_11));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwPwrPrkgDampgPer1
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
 *   Std_ReturnType Rte_Read_DampgCmdBas_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DampgCmdPwrPrkgEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DampgCmdPwrPrkg_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwPwrPrkgDampgPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_DampgCmdBas_Val;
  boolean Read_DampgCmdPwrPrkgEna_Logl;
  float32 Read_HwVel_Val;
  float32 Read_PinionAg_Val;
  float32 Read_PinionAgConf_Val;
  float32 Read_VehSpd_Val;

  float32 PimDampgCmdPwrPrkgStVari;

  float32 BmwPwrPrkgDampgMaxRate_Val_data;
  float32 BmwPwrPrkgDampgMinPinionAgConf_Val_data;
  boolean BmwPwrPrkgDampgDiScadDampg_Logl_data;
  Ary2D_u5p11_9_9 BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D_data;
  Ary1D_u6p10_9 BmwPwrPrkgDampgHwVelTblX_Ary1D_data;
  Ary1D_u12p4_9 BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D_data;
  Ary1D_u9p7_11 BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D_data;
  Ary1D_u1p15_11 BmwPwrPrkgDampgVehSpdScaFacY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDampgCmdPwrPrkgStVari = *TSC_BmwPwrPrkgDampg_Rte_Pim_DampgCmdPwrPrkgStVari();
  *TSC_BmwPwrPrkgDampg_Rte_Pim_DampgCmdPwrPrkgStVari() = PimDampgCmdPwrPrkgStVari;

  BmwPwrPrkgDampgMaxRate_Val_data = TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgMaxRate_Val();
  BmwPwrPrkgDampgMinPinionAgConf_Val_data = TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val();
  BmwPwrPrkgDampgDiScadDampg_Logl_data = TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl();
  (void)memcpy(BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(), sizeof(Ary2D_u5p11_9_9));
  (void)memcpy(BmwPwrPrkgDampgHwVelTblX_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(), sizeof(Ary1D_u6p10_9));
  (void)memcpy(BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(), sizeof(Ary1D_u12p4_9));
  (void)memcpy(BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(), sizeof(Ary1D_u9p7_11));
  (void)memcpy(BmwPwrPrkgDampgVehSpdScaFacY_Ary1D_data, TSC_BmwPwrPrkgDampg_Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(), sizeof(Ary1D_u1p15_11));

  fct_status = TSC_BmwPwrPrkgDampg_Rte_Read_DampgCmdBas_Val(&Read_DampgCmdBas_Val);
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

  fct_status = TSC_BmwPwrPrkgDampg_Rte_Read_DampgCmdPwrPrkgEna_Logl(&Read_DampgCmdPwrPrkgEna_Logl);
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

  fct_status = TSC_BmwPwrPrkgDampg_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_BmwPwrPrkgDampg_Rte_Read_PinionAg_Val(&Read_PinionAg_Val);
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

  fct_status = TSC_BmwPwrPrkgDampg_Rte_Read_PinionAgConf_Val(&Read_PinionAgConf_Val);
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

  fct_status = TSC_BmwPwrPrkgDampg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwPwrPrkgDampg_Rte_Write_DampgCmdPwrPrkg_Val(Rte_InitValue_DampgCmdPwrPrkg_Val);
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


#define BmwPwrPrkgDampg_STOP_SEC_CODE
#include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
