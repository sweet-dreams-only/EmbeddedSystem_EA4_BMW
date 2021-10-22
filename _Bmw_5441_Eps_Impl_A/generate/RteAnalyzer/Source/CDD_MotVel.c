/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_MotVel.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_MotVel
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_MotVel>
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
 * u0p16
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CDD_MotVel.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_MotVel.h"


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
 * sint8: Integer in interval [-128...127] (standard type)
 * u0p16: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u0p16_8: Array with 8 element(s) of type u0p16
 * Ary1D_u32_8: Array with 8 element(s) of type uint32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_dMotVelAvrgTi(void)
 *   float32 *Rte_Pim_dMotVelTiStampRef(void)
 *   u0p16 *Rte_Pim_dMotVelMotAgRef(void)
 *   uint8 *Rte_Pim_MotAgBufIdxPrev(void)
 *   uint8 *Rte_Pim_MotAgBufIdxPrim(void)
 *   uint8 *Rte_Pim_MotVelIninCntr(void)
 *   u0p16 *Rte_Pim_MotAgBufPrev(void)
 *     Returnvalue: u0p16* is of type Ary1D_u0p16_8
 *   uint32 *Rte_Pim_MotAgTiBufPrev(void)
 *     Returnvalue: uint32* is of type Ary1D_u32_8
 *
 *********************************************************************************************************************/


#define CDD_MotVel_START_SEC_CODE
#include "CDD_MotVel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotVelInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotVel_CODE) MotVelInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelInit1
 *********************************************************************************************************************/

  float32 PimdMotVelAvrgTi;
  float32 PimdMotVelTiStampRef;
  u0p16 PimdMotVelMotAgRef;
  uint8 PimMotAgBufIdxPrev;
  uint8 PimMotAgBufIdxPrim;
  uint8 PimMotVelIninCntr;
  Ary1D_u0p16_8 PimMotAgBufPrev;
  Ary1D_u32_8 PimMotAgTiBufPrev;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotVelAvrgTi = *TSC_CDD_MotVel_Rte_Pim_dMotVelAvrgTi();
  *TSC_CDD_MotVel_Rte_Pim_dMotVelAvrgTi() = PimdMotVelAvrgTi;
  PimdMotVelTiStampRef = *TSC_CDD_MotVel_Rte_Pim_dMotVelTiStampRef();
  *TSC_CDD_MotVel_Rte_Pim_dMotVelTiStampRef() = PimdMotVelTiStampRef;
  PimdMotVelMotAgRef = *TSC_CDD_MotVel_Rte_Pim_dMotVelMotAgRef();
  *TSC_CDD_MotVel_Rte_Pim_dMotVelMotAgRef() = PimdMotVelMotAgRef;
  PimMotAgBufIdxPrev = *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrev();
  *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrev() = PimMotAgBufIdxPrev;
  PimMotAgBufIdxPrim = *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrim();
  *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrim() = PimMotAgBufIdxPrim;
  PimMotVelIninCntr = *TSC_CDD_MotVel_Rte_Pim_MotVelIninCntr();
  *TSC_CDD_MotVel_Rte_Pim_MotVelIninCntr() = PimMotVelIninCntr;

  (void)memcpy(PimMotAgBufPrev, TSC_CDD_MotVel_Rte_Pim_MotAgBufPrev(), sizeof(Ary1D_u0p16_8));
  (void)memcpy(TSC_CDD_MotVel_Rte_Pim_MotAgBufPrev(), PimMotAgBufPrev, sizeof(Ary1D_u0p16_8));


  (void)memcpy(PimMotAgTiBufPrev, TSC_CDD_MotVel_Rte_Pim_MotAgTiBufPrev(), sizeof(Ary1D_u32_8));
  (void)memcpy(TSC_CDD_MotVel_Rte_Pim_MotAgTiBufPrev(), PimMotAgTiBufPrev, sizeof(Ary1D_u32_8));



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotVelPer2
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
 *   Std_ReturnType Rte_Read_MotAgBuf_Ary1D(u0p16 *data)
 *     Argument data: u0p16* is of type Ary1D_u0p16_8
 *   Std_ReturnType Rte_Read_MotAgBufIdx_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotAgMeclIdptSig_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotAgTiBuf_Ary1D(uint32 *data)
 *     Argument data: uint32* is of type Ary1D_u32_8
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotVelCrf_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotVelMrf_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotVelVld_Logl(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelPer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotVel_CODE) MotVelPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotVelPer2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  sint8 Read_AssiMechPolarity_Val;
  Ary1D_u0p16_8 Read_MotAgBuf_Ary1D;
  uint8 Read_MotAgBufIdx_Val;
  uint8 Read_MotAgMeclIdptSig_Val;
  Ary1D_u32_8 Read_MotAgTiBuf_Ary1D;

  float32 PimdMotVelAvrgTi;
  float32 PimdMotVelTiStampRef;
  u0p16 PimdMotVelMotAgRef;
  uint8 PimMotAgBufIdxPrev;
  uint8 PimMotAgBufIdxPrim;
  uint8 PimMotVelIninCntr;
  Ary1D_u0p16_8 PimMotAgBufPrev;
  Ary1D_u32_8 PimMotAgTiBufPrev;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotVelAvrgTi = *TSC_CDD_MotVel_Rte_Pim_dMotVelAvrgTi();
  *TSC_CDD_MotVel_Rte_Pim_dMotVelAvrgTi() = PimdMotVelAvrgTi;
  PimdMotVelTiStampRef = *TSC_CDD_MotVel_Rte_Pim_dMotVelTiStampRef();
  *TSC_CDD_MotVel_Rte_Pim_dMotVelTiStampRef() = PimdMotVelTiStampRef;
  PimdMotVelMotAgRef = *TSC_CDD_MotVel_Rte_Pim_dMotVelMotAgRef();
  *TSC_CDD_MotVel_Rte_Pim_dMotVelMotAgRef() = PimdMotVelMotAgRef;
  PimMotAgBufIdxPrev = *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrev();
  *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrev() = PimMotAgBufIdxPrev;
  PimMotAgBufIdxPrim = *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrim();
  *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrim() = PimMotAgBufIdxPrim;
  PimMotVelIninCntr = *TSC_CDD_MotVel_Rte_Pim_MotVelIninCntr();
  *TSC_CDD_MotVel_Rte_Pim_MotVelIninCntr() = PimMotVelIninCntr;

  (void)memcpy(PimMotAgBufPrev, TSC_CDD_MotVel_Rte_Pim_MotAgBufPrev(), sizeof(Ary1D_u0p16_8));
  (void)memcpy(TSC_CDD_MotVel_Rte_Pim_MotAgBufPrev(), PimMotAgBufPrev, sizeof(Ary1D_u0p16_8));


  (void)memcpy(PimMotAgTiBufPrev, TSC_CDD_MotVel_Rte_Pim_MotAgTiBufPrev(), sizeof(Ary1D_u32_8));
  (void)memcpy(TSC_CDD_MotVel_Rte_Pim_MotAgTiBufPrev(), PimMotAgTiBufPrev, sizeof(Ary1D_u32_8));


  fct_status = TSC_CDD_MotVel_Rte_Read_AssiMechPolarity_Val(&Read_AssiMechPolarity_Val);
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

  fct_status = TSC_CDD_MotVel_Rte_Read_MotAgBuf_Ary1D(Read_MotAgBuf_Ary1D);
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

  fct_status = TSC_CDD_MotVel_Rte_Read_MotAgBufIdx_Val(&Read_MotAgBufIdx_Val);
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

  fct_status = TSC_CDD_MotVel_Rte_Read_MotAgMeclIdptSig_Val(&Read_MotAgMeclIdptSig_Val);
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

  fct_status = TSC_CDD_MotVel_Rte_Read_MotAgTiBuf_Ary1D(Read_MotAgTiBuf_Ary1D);
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

  fct_status = TSC_CDD_MotVel_Rte_Write_MotVelCrf_Val(Rte_InitValue_MotVelCrf_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_MotVel_Rte_Write_MotVelMrf_Val(Rte_InitValue_MotVelMrf_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CDD_MotVel_Rte_Write_MotVelVld_Logl(Rte_InitValue_MotVelVld_Logl);
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


#define CDD_MotVel_STOP_SEC_CODE
#include "CDD_MotVel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
