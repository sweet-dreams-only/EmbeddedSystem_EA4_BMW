/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  HiLoadStallLimr.c
 *        Config:  EPS.dpa
 *     SW-C Type:  HiLoadStallLimr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <HiLoadStallLimr>
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
 * u8p8
 *   
 *
 *********************************************************************************************************************/

#include "Rte_HiLoadStallLimr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_HiLoadStallLimr.h"


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
 * u8p8: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_f32_2: Array with 2 element(s) of type float32
 * Ary1D_u8p8_6: Array with 6 element(s) of type u8p8
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_StallMotTqLimFetMtgtnPrev(void)
 *   float32 *Rte_Pim_StallMotTqLimPrev(void)
 *   float32 *Rte_Pim_dHiLoadStallLimrStallMotTqCmd(void)
 *   float32 *Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild(void)
 *   float32 *Rte_Pim_dHiLoadStallLimrStallMotTqLim(void)
 *   uint8 *Rte_Pim_FetLoaMtgtnCalIdx(void)
 *   FilLpRec1 *Rte_Pim_StallMotTqCmdFetMtgtnFil(void)
 *   FilLpRec1 *Rte_Pim_StallMotTqCmdFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val(void)
 *   float32 Rte_Prm_HiLoadStallLimrMotTqCmdFilFrq_Val(void)
 *   float32 Rte_Prm_HiLoadStallLimrStallThermLimSca_Val(void)
 *   float32 *Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_2
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   u8p8 *Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_6
 *   float32 *Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_2
 *
 *********************************************************************************************************************/


#define HiLoadStallLimr_START_SEC_CODE
#include "HiLoadStallLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HiLoadStallLimrInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: HiLoadStallLimrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, HiLoadStallLimr_CODE) HiLoadStallLimrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HiLoadStallLimrInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint8 Read_MotAndThermProtnLoaMod_Val;

  float32 PimStallMotTqLimFetMtgtnPrev;
  float32 PimStallMotTqLimPrev;
  float32 PimdHiLoadStallLimrStallMotTqCmd;
  float32 PimdHiLoadStallLimrStallMotTqCmdFild;
  float32 PimdHiLoadStallLimrStallMotTqLim;
  uint8 PimFetLoaMtgtnCalIdx;
  FilLpRec1 PimStallMotTqCmdFetMtgtnFil;
  FilLpRec1 PimStallMotTqCmdFil;

  float32 HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val_data;
  float32 HiLoadStallLimrMotTqCmdFilFrq_Val_data;
  float32 HiLoadStallLimrStallThermLimSca_Val_data;
  Ary1D_f32_2 HiLoadStallLimrMotVelMgnThd_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdLimX_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdLimY_Ary1D_data;
  Ary1D_f32_2 HiLoadStallLimrStallMotTqLimSlewRate_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimStallMotTqLimFetMtgtnPrev = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimFetMtgtnPrev();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimFetMtgtnPrev() = PimStallMotTqLimFetMtgtnPrev;
  PimStallMotTqLimPrev = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimPrev();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimPrev() = PimStallMotTqLimPrev;
  PimdHiLoadStallLimrStallMotTqCmd = *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmd();
  *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmd() = PimdHiLoadStallLimrStallMotTqCmd;
  PimdHiLoadStallLimrStallMotTqCmdFild = *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild();
  *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild() = PimdHiLoadStallLimrStallMotTqCmdFild;
  PimdHiLoadStallLimrStallMotTqLim = *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqLim();
  *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqLim() = PimdHiLoadStallLimrStallMotTqLim;
  PimFetLoaMtgtnCalIdx = *TSC_HiLoadStallLimr_Rte_Pim_FetLoaMtgtnCalIdx();
  *TSC_HiLoadStallLimr_Rte_Pim_FetLoaMtgtnCalIdx() = PimFetLoaMtgtnCalIdx;
  PimStallMotTqCmdFetMtgtnFil = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFetMtgtnFil();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFetMtgtnFil() = PimStallMotTqCmdFetMtgtnFil;
  PimStallMotTqCmdFil = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFil();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFil() = PimStallMotTqCmdFil;

  HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val_data = TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val();
  HiLoadStallLimrMotTqCmdFilFrq_Val_data = TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFilFrq_Val();
  HiLoadStallLimrStallThermLimSca_Val_data = TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallThermLimSca_Val();
  (void)memcpy(HiLoadStallLimrMotVelMgnThd_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(), sizeof(Ary1D_f32_2));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdLimX_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdLimY_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqLimSlewRate_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(), sizeof(Ary1D_f32_2));

  fct_status = TSC_HiLoadStallLimr_Rte_Read_MotAndThermProtnLoaMod_Val(&Read_MotAndThermProtnLoaMod_Val);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HiLoadStallLimrPer1
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
 *   Std_ReturnType Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdLimdPreStall_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_StallMotTqLimDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_StallMotTqLim_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: HiLoadStallLimrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, HiLoadStallLimr_CODE) HiLoadStallLimrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HiLoadStallLimrPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_DualEcuFltMtgtnEna_Logl;
  uint8 Read_MotAndThermProtnLoaMod_Val;
  float32 Read_MotTqCmdLimdPreStall_Val;
  float32 Read_MotVelCrf_Val;
  boolean Read_StallMotTqLimDi_Logl;

  float32 PimStallMotTqLimFetMtgtnPrev;
  float32 PimStallMotTqLimPrev;
  float32 PimdHiLoadStallLimrStallMotTqCmd;
  float32 PimdHiLoadStallLimrStallMotTqCmdFild;
  float32 PimdHiLoadStallLimrStallMotTqLim;
  uint8 PimFetLoaMtgtnCalIdx;
  FilLpRec1 PimStallMotTqCmdFetMtgtnFil;
  FilLpRec1 PimStallMotTqCmdFil;

  float32 HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val_data;
  float32 HiLoadStallLimrMotTqCmdFilFrq_Val_data;
  float32 HiLoadStallLimrStallThermLimSca_Val_data;
  Ary1D_f32_2 HiLoadStallLimrMotVelMgnThd_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdLimX_Ary1D_data;
  Ary1D_u8p8_6 HiLoadStallLimrStallMotTqCmdLimY_Ary1D_data;
  Ary1D_f32_2 HiLoadStallLimrStallMotTqLimSlewRate_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimStallMotTqLimFetMtgtnPrev = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimFetMtgtnPrev();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimFetMtgtnPrev() = PimStallMotTqLimFetMtgtnPrev;
  PimStallMotTqLimPrev = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimPrev();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimPrev() = PimStallMotTqLimPrev;
  PimdHiLoadStallLimrStallMotTqCmd = *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmd();
  *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmd() = PimdHiLoadStallLimrStallMotTqCmd;
  PimdHiLoadStallLimrStallMotTqCmdFild = *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild();
  *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild() = PimdHiLoadStallLimrStallMotTqCmdFild;
  PimdHiLoadStallLimrStallMotTqLim = *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqLim();
  *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqLim() = PimdHiLoadStallLimrStallMotTqLim;
  PimFetLoaMtgtnCalIdx = *TSC_HiLoadStallLimr_Rte_Pim_FetLoaMtgtnCalIdx();
  *TSC_HiLoadStallLimr_Rte_Pim_FetLoaMtgtnCalIdx() = PimFetLoaMtgtnCalIdx;
  PimStallMotTqCmdFetMtgtnFil = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFetMtgtnFil();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFetMtgtnFil() = PimStallMotTqCmdFetMtgtnFil;
  PimStallMotTqCmdFil = *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFil();
  *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFil() = PimStallMotTqCmdFil;

  HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val_data = TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val();
  HiLoadStallLimrMotTqCmdFilFrq_Val_data = TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFilFrq_Val();
  HiLoadStallLimrStallThermLimSca_Val_data = TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallThermLimSca_Val();
  (void)memcpy(HiLoadStallLimrMotVelMgnThd_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(), sizeof(Ary1D_f32_2));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdLimX_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqCmdLimY_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(), sizeof(Ary1D_u8p8_6));
  (void)memcpy(HiLoadStallLimrStallMotTqLimSlewRate_Ary1D_data, TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(), sizeof(Ary1D_f32_2));

  fct_status = TSC_HiLoadStallLimr_Rte_Read_DualEcuFltMtgtnEna_Logl(&Read_DualEcuFltMtgtnEna_Logl);
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

  fct_status = TSC_HiLoadStallLimr_Rte_Read_MotAndThermProtnLoaMod_Val(&Read_MotAndThermProtnLoaMod_Val);
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

  fct_status = TSC_HiLoadStallLimr_Rte_Read_MotTqCmdLimdPreStall_Val(&Read_MotTqCmdLimdPreStall_Val);
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

  fct_status = TSC_HiLoadStallLimr_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_HiLoadStallLimr_Rte_Read_StallMotTqLimDi_Logl(&Read_StallMotTqLimDi_Logl);
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

  fct_status = TSC_HiLoadStallLimr_Rte_Write_StallMotTqLim_Val(Rte_InitValue_StallMotTqLim_Val);
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


#define HiLoadStallLimr_STOP_SEC_CODE
#include "HiLoadStallLimr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
