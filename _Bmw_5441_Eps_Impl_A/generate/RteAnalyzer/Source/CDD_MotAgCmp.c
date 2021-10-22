/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_MotAgCmp.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_MotAgCmp
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_MotAgCmp>
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
 * s15p16
 *   
 *
 * s18p13
 *   
 *
 * u0p16
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CDD_MotAgCmp.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_MotAgCmp.h"


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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s15p16: Integer in interval [-2147483648...2147483647]
 * s18p13: Integer in interval [-2147483648...2147483647]
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * u0p16: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_DigMotHwPosn(void)
 *   s15p16 *Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev(void)
 *   s15p16 *Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev(void)
 *   u0p16 *Rte_Pim_MotAgCmpMotAgBackEmf(void)
 *   uint8 *Rte_Pim_CmpEnaCntr(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   u0p16 Rte_CData_MotAgCmpMotAgBackEmfDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint8 Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
 *
 *********************************************************************************************************************/


#define CDD_MotAgCmp_START_SEC_CODE
#include "CDD_MotAgCmp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpBackEmfRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAgCmpBackEmfRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAgCmpBackEmfRead_Oper(u0p16 *MotAgBackEmfRead_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpBackEmfRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpBackEmfRead_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAGCMP_APPL_VAR) MotAgBackEmfRead_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpBackEmfRead_Oper
 *********************************************************************************************************************/

  float32 PimDigMotHwPosn;
  s15p16 PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  s15p16 PimMotAgCmpMotCtrlMotAgMeclPrev;
  u0p16 PimMotAgCmpMotAgBackEmf;
  uint8 PimCmpEnaCntr;

  u0p16 MotAgCmpMotAgBackEmfDft_data;

  float32 SysGlbPrmSysKineRat_Val_data;
  uint8 SysGlbPrmMotPoleCnt_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDigMotHwPosn = *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn();
  *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn() = PimDigMotHwPosn;
  PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev() = PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  PimMotAgCmpMotCtrlMotAgMeclPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev() = PimMotAgCmpMotCtrlMotAgMeclPrev;
  PimMotAgCmpMotAgBackEmf = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf() = PimMotAgCmpMotAgBackEmf;
  PimCmpEnaCntr = *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr();
  *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr() = PimCmpEnaCntr;

  MotAgCmpMotAgBackEmfDft_data = TSC_CDD_MotAgCmp_Rte_CData_MotAgCmpMotAgBackEmfDft();

  SysGlbPrmSysKineRat_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmMotPoleCnt_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmMotPoleCnt_Val();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpBackEmfWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAgCmpBackEmfWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAgCmpBackEmfWr_Oper(u0p16 MotAgCmpBackEmfWrData_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpBackEmfWr_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpBackEmfWr_Oper(u0p16 MotAgCmpBackEmfWrData_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpBackEmfWr_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimDigMotHwPosn;
  s15p16 PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  s15p16 PimMotAgCmpMotCtrlMotAgMeclPrev;
  u0p16 PimMotAgCmpMotAgBackEmf;
  uint8 PimCmpEnaCntr;

  u0p16 MotAgCmpMotAgBackEmfDft_data;

  float32 SysGlbPrmSysKineRat_Val_data;
  uint8 SysGlbPrmMotPoleCnt_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDigMotHwPosn = *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn();
  *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn() = PimDigMotHwPosn;
  PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev() = PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  PimMotAgCmpMotCtrlMotAgMeclPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev() = PimMotAgCmpMotCtrlMotAgMeclPrev;
  PimMotAgCmpMotAgBackEmf = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf() = PimMotAgCmpMotAgBackEmf;
  PimCmpEnaCntr = *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr();
  *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr() = PimCmpEnaCntr;

  MotAgCmpMotAgBackEmfDft_data = TSC_CDD_MotAgCmp_Rte_CData_MotAgCmpMotAgBackEmfDft();

  SysGlbPrmSysKineRat_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmMotPoleCnt_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmMotPoleCnt_Val();

  fct_status = TSC_CDD_MotAgCmp_Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpInit1
 *********************************************************************************************************************/

  float32 PimDigMotHwPosn;
  s15p16 PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  s15p16 PimMotAgCmpMotCtrlMotAgMeclPrev;
  u0p16 PimMotAgCmpMotAgBackEmf;
  uint8 PimCmpEnaCntr;

  u0p16 MotAgCmpMotAgBackEmfDft_data;

  float32 SysGlbPrmSysKineRat_Val_data;
  uint8 SysGlbPrmMotPoleCnt_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDigMotHwPosn = *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn();
  *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn() = PimDigMotHwPosn;
  PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev() = PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  PimMotAgCmpMotCtrlMotAgMeclPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev() = PimMotAgCmpMotCtrlMotAgMeclPrev;
  PimMotAgCmpMotAgBackEmf = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf() = PimMotAgCmpMotAgBackEmf;
  PimCmpEnaCntr = *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr();
  *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr() = PimCmpEnaCntr;

  MotAgCmpMotAgBackEmfDft_data = TSC_CDD_MotAgCmp_Rte_CData_MotAgCmpMotAgBackEmfDft();

  SysGlbPrmSysKineRat_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmMotPoleCnt_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmMotPoleCnt_Val();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpPer2
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
 *   Std_ReturnType Rte_Read_AssiMechPolarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrfRev_Val(s15p16 *data)
 *   Std_ReturnType Rte_Read_MotAgCumvInid_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndCrf_Val(s18p13 data)
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndMrf_Val(s18p13 data)
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndVld_Logl(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpPer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpPer2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  sint8 Read_AssiMechPolarity_Val;
  s15p16 Read_MotAgCumvAlgndMrfRev_Val;
  boolean Read_MotAgCumvInid_Logl;

  float32 PimDigMotHwPosn;
  s15p16 PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  s15p16 PimMotAgCmpMotCtrlMotAgMeclPrev;
  u0p16 PimMotAgCmpMotAgBackEmf;
  uint8 PimCmpEnaCntr;

  u0p16 MotAgCmpMotAgBackEmfDft_data;

  float32 SysGlbPrmSysKineRat_Val_data;
  uint8 SysGlbPrmMotPoleCnt_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimDigMotHwPosn = *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn();
  *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn() = PimDigMotHwPosn;
  PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev() = PimMotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev;
  PimMotAgCmpMotCtrlMotAgMeclPrev = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev() = PimMotAgCmpMotCtrlMotAgMeclPrev;
  PimMotAgCmpMotAgBackEmf = *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf();
  *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf() = PimMotAgCmpMotAgBackEmf;
  PimCmpEnaCntr = *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr();
  *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr() = PimCmpEnaCntr;

  MotAgCmpMotAgBackEmfDft_data = TSC_CDD_MotAgCmp_Rte_CData_MotAgCmpMotAgBackEmfDft();

  SysGlbPrmSysKineRat_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmSysKineRat_Val();
  SysGlbPrmMotPoleCnt_Val_data = TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmMotPoleCnt_Val();

  fct_status = TSC_CDD_MotAgCmp_Rte_Read_AssiMechPolarity_Val(&Read_AssiMechPolarity_Val);
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

  fct_status = TSC_CDD_MotAgCmp_Rte_Read_MotAgCumvAlgndMrfRev_Val(&Read_MotAgCumvAlgndMrfRev_Val);
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

  fct_status = TSC_CDD_MotAgCmp_Rte_Read_MotAgCumvInid_Logl(&Read_MotAgCumvInid_Logl);
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

  fct_status = TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndCrf_Val(Rte_InitValue_MotAgCumvAlgndCrf_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndMrf_Val(Rte_InitValue_MotAgCumvAlgndMrf_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndVld_Logl(Rte_InitValue_MotAgCumvAlgndVld_Logl);
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


#define CDD_MotAgCmp_STOP_SEC_CODE
#include "CDD_MotAgCmp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
