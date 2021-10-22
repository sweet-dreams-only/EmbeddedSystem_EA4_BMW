/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CmplncErr.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CmplncErr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CmplncErr>
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
 * u1p15
 *   
 *
 * u5p11
 *   
 *
 * u8p8
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CmplncErr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CmplncErr.h"


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
 * u1p15: Integer in interval [0...65535]
 * u5p11: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u1p15_6: Array with 6 element(s) of type u1p15
 * Ary1D_u5p11_6: Array with 6 element(s) of type u5p11
 * Ary1D_u8p8_6: Array with 6 element(s) of type u8p8
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
 *   u1p15 *Rte_Prm_CmplncErrHwAgNonLinCmplncDepTblY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_6
 *   u5p11 *Rte_Prm_CmplncErrHwAgNonLinCmplncIndTblX_Ary1D(void)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_6
 *   u8p8 *Rte_Prm_CmplncErrMotAgNonLinCmplncDepTblY_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u5p11 *Rte_Prm_CmplncErrMotAgNonLinCmplncIndTblX_Ary1D(void)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_6
 *
 *********************************************************************************************************************/


#define CmplncErr_START_SEC_CODE
#include "CmplncErr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmplncErrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CmplncErrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CmplncErr_CODE) CmplncErrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CmplncErrInit1
 *********************************************************************************************************************/

  Ary1D_u1p15_6 CmplncErrHwAgNonLinCmplncDepTblY_Ary1D_data;
  Ary1D_u5p11_6 CmplncErrHwAgNonLinCmplncIndTblX_Ary1D_data;
  Ary1D_u8p8_6 CmplncErrMotAgNonLinCmplncDepTblY_Ary1D_data;
  Ary1D_u5p11_6 CmplncErrMotAgNonLinCmplncIndTblX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memcpy(CmplncErrHwAgNonLinCmplncDepTblY_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrHwAgNonLinCmplncDepTblY_Ary1D(), sizeof(Ary1D_u1p15_6));
  (void)memcpy(CmplncErrHwAgNonLinCmplncIndTblX_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrHwAgNonLinCmplncIndTblX_Ary1D(), sizeof(Ary1D_u5p11_6));
  (void)memcpy(CmplncErrMotAgNonLinCmplncDepTblY_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrMotAgNonLinCmplncDepTblY_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(CmplncErrMotAgNonLinCmplncIndTblX_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrMotAgNonLinCmplncIndTblX_Ary1D(), sizeof(Ary1D_u5p11_6));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmplncErrPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdCrf_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CmplncErrMotToPinion_Val(float32 data)
 *   Std_ReturnType Rte_Write_CmplncErrPinionToHw_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CmplncErrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CmplncErr_CODE) CmplncErrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CmplncErrPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  float32 Read_MotTqCmdCrf_Val;

  Ary1D_u1p15_6 CmplncErrHwAgNonLinCmplncDepTblY_Ary1D_data;
  Ary1D_u5p11_6 CmplncErrHwAgNonLinCmplncIndTblX_Ary1D_data;
  Ary1D_u8p8_6 CmplncErrMotAgNonLinCmplncDepTblY_Ary1D_data;
  Ary1D_u5p11_6 CmplncErrMotAgNonLinCmplncIndTblX_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memcpy(CmplncErrHwAgNonLinCmplncDepTblY_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrHwAgNonLinCmplncDepTblY_Ary1D(), sizeof(Ary1D_u1p15_6));
  (void)memcpy(CmplncErrHwAgNonLinCmplncIndTblX_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrHwAgNonLinCmplncIndTblX_Ary1D(), sizeof(Ary1D_u5p11_6));
  (void)memcpy(CmplncErrMotAgNonLinCmplncDepTblY_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrMotAgNonLinCmplncDepTblY_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(CmplncErrMotAgNonLinCmplncIndTblX_Ary1D_data, TSC_CmplncErr_Rte_Prm_CmplncErrMotAgNonLinCmplncIndTblX_Ary1D(), sizeof(Ary1D_u5p11_6));

  fct_status = TSC_CmplncErr_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_CmplncErr_Rte_Read_MotTqCmdCrf_Val(&Read_MotTqCmdCrf_Val);
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

  fct_status = TSC_CmplncErr_Rte_Write_CmplncErrMotToPinion_Val(Rte_InitValue_CmplncErrMotToPinion_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CmplncErr_Rte_Write_CmplncErrPinionToHw_Val(Rte_InitValue_CmplncErrPinionToHw_Val);
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


#define CmplncErr_STOP_SEC_CODE
#include "CmplncErr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
