/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SysKineAndEff.c
 *        Config:  EPS.dpa
 *     SW-C Type:  SysKineAndEff
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <SysKineAndEff>
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
 * s18p13
 *   
 *
 * s2p13
 *   
 *
 * s8p7
 *   
 *
 * u1p15
 *   
 *
 * u4p12
 *   
 *
 * u5p11
 *   
 *
 *
 * Component Types:
 * ================
 * SysKineAndEff
 *   
 *
 *
 * Port Prototypes:
 * ================
 * CmplncErrPinionToHw
 *
 * HwAg
 *
 * HwVel
 *
 * MotAgCumvAlgndMrf
 *
 * MotAgToRackPosnInstsRat
 *
 * MotToRackFInstsRat
 *
 * MotToRackInstsEff
 *
 * MotVelCrf
 *
 * PinionAg
 *
 * PinionAgToRackInstsEff
 *
 * PinionAgToRackPosnInstsRat
 *
 * PinionTqToRackFInstsRat
 *
 * PinionVel
 *
 * RackPosn
 *
 * RackVel
 *
 * RoadWhlAg
 *
 * SteerArmLen
 *
 * SysAssiTqRat
 *
 * SysKineRat
 *
 * SysTqRat
 *
 *
 * Runnable Entities:
 * ==================
 * SysKineAndEffInit1
 *   
 *
 * SysKineAndEffPer1
 *   
 *
 *
 * Per-Instance Memory:
 * ====================
 * CmplncErrDerivtvPrev
 *   
 *
 * CmplncErrPinionToHwPrev
 *   
 *
 *********************************************************************************************************************/

#include "Rte_SysKineAndEff.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_SysKineAndEff.h"


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
 * s18p13: Integer in interval [-2147483648...2147483647]
 * s2p13: Integer in interval [-32768...32767]
 * s8p7: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * u1p15: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u5p11: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_s15p0_21: Array with 21 element(s) of type s15p0
 * Ary1D_s2p13_21: Array with 21 element(s) of type s2p13
 * Ary1D_s8p7_21: Array with 21 element(s) of type s8p7
 * Ary1D_u1p15_21: Array with 21 element(s) of type u1p15
 * Ary1D_u4p12_21: Array with 21 element(s) of type u4p12
 * Ary1D_u5p11_21: Array with 21 element(s) of type u5p11
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_CmplncErrDerivtvPrev(void)
 *   float32 *Rte_Pim_CmplncErrPinionToHwPrev(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val(void)
 *   s15p0 *Rte_Prm_SysKineAndEffMotAgScaX_Ary1D(void)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_21
 *   u4p12 *Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_21
 *   u1p15 *Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *   u5p11 *Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(void)
 *     Returnvalue: u5p11* is of type Ary1D_u5p11_21
 *   u1p15 *Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *   s8p7 *Rte_Prm_SysKineAndEffRackPosScaY_Ary1D(void)
 *     Returnvalue: s8p7* is of type Ary1D_s8p7_21
 *   s2p13 *Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(void)
 *     Returnvalue: s2p13* is of type Ary1D_s2p13_21
 *   u1p15 *Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_21
 *
 *********************************************************************************************************************/


#define SysKineAndEff_START_SEC_CODE
#include "SysKineAndEff_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SysKineAndEffInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SysKineAndEffInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SysKineAndEff_CODE) SysKineAndEffInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SysKineAndEffInit1
 *********************************************************************************************************************/

  float32 PimCmplncErrDerivtvPrev;
  float32 PimCmplncErrPinionToHwPrev;

  float32 SysKineAndEffCmplncErrDerivtvCutOffFrq_Val_data;
  Ary1D_s15p0_21 SysKineAndEffMotAgScaX_Ary1D_data;
  Ary1D_u4p12_21 SysKineAndEffMotAgToRackPosRatScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffMotToRackEffScaY_Ary1D_data;
  Ary1D_u5p11_21 SysKineAndEffPinionAgToRackPosRatScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffPinionToRackEffScaY_Ary1D_data;
  Ary1D_s8p7_21 SysKineAndEffRackPosScaY_Ary1D_data;
  Ary1D_s2p13_21 SysKineAndEffRoadWhlFromRackPosScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmplncErrDerivtvPrev = *TSC_SysKineAndEff_Rte_Pim_CmplncErrDerivtvPrev();
  *TSC_SysKineAndEff_Rte_Pim_CmplncErrDerivtvPrev() = PimCmplncErrDerivtvPrev;
  PimCmplncErrPinionToHwPrev = *TSC_SysKineAndEff_Rte_Pim_CmplncErrPinionToHwPrev();
  *TSC_SysKineAndEff_Rte_Pim_CmplncErrPinionToHwPrev() = PimCmplncErrPinionToHwPrev;

  SysKineAndEffCmplncErrDerivtvCutOffFrq_Val_data = TSC_SysKineAndEff_Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val();
  (void)memcpy(SysKineAndEffMotAgScaX_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotAgScaX_Ary1D(), sizeof(Ary1D_s15p0_21));
  (void)memcpy(SysKineAndEffMotAgToRackPosRatScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(), sizeof(Ary1D_u4p12_21));
  (void)memcpy(SysKineAndEffMotToRackEffScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D(), sizeof(Ary1D_u1p15_21));
  (void)memcpy(SysKineAndEffPinionAgToRackPosRatScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(), sizeof(Ary1D_u5p11_21));
  (void)memcpy(SysKineAndEffPinionToRackEffScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(), sizeof(Ary1D_u1p15_21));
  (void)memcpy(SysKineAndEffRackPosScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffRackPosScaY_Ary1D(), sizeof(Ary1D_s8p7_21));
  (void)memcpy(SysKineAndEffRoadWhlFromRackPosScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(), sizeof(Ary1D_s2p13_21));
  (void)memcpy(SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(), sizeof(Ary1D_u1p15_21));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SysKineAndEffPer1
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
 *   Std_ReturnType Rte_Read_CmplncErrPinionToHw_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAg_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwVel_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotAgToRackPosnInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotToRackFInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotToRackInstsEff_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAgToRackInstsEff_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAgToRackPosnInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionTqToRackFInstsRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionVel_Val(float32 data)
 *   Std_ReturnType Rte_Write_RackPosn_Val(float32 data)
 *   Std_ReturnType Rte_Write_RackVel_Val(float32 data)
 *   Std_ReturnType Rte_Write_RoadWhlAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_SteerArmLen_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysAssiTqRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysKineRat_Val(float32 data)
 *   Std_ReturnType Rte_Write_SysTqRat_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SysKineAndEffPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SysKineAndEff_CODE) SysKineAndEffPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SysKineAndEffPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_CmplncErrPinionToHw_Val;
  s18p13 Read_MotAgCumvAlgndMrf_Val;
  float32 Read_MotVelCrf_Val;
  float32 Read_PinionAg_Val;

  float32 PimCmplncErrDerivtvPrev;
  float32 PimCmplncErrPinionToHwPrev;

  float32 SysKineAndEffCmplncErrDerivtvCutOffFrq_Val_data;
  Ary1D_s15p0_21 SysKineAndEffMotAgScaX_Ary1D_data;
  Ary1D_u4p12_21 SysKineAndEffMotAgToRackPosRatScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffMotToRackEffScaY_Ary1D_data;
  Ary1D_u5p11_21 SysKineAndEffPinionAgToRackPosRatScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffPinionToRackEffScaY_Ary1D_data;
  Ary1D_s8p7_21 SysKineAndEffRackPosScaY_Ary1D_data;
  Ary1D_s2p13_21 SysKineAndEffRoadWhlFromRackPosScaY_Ary1D_data;
  Ary1D_u1p15_21 SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimCmplncErrDerivtvPrev = *TSC_SysKineAndEff_Rte_Pim_CmplncErrDerivtvPrev();
  *TSC_SysKineAndEff_Rte_Pim_CmplncErrDerivtvPrev() = PimCmplncErrDerivtvPrev;
  PimCmplncErrPinionToHwPrev = *TSC_SysKineAndEff_Rte_Pim_CmplncErrPinionToHwPrev();
  *TSC_SysKineAndEff_Rte_Pim_CmplncErrPinionToHwPrev() = PimCmplncErrPinionToHwPrev;

  SysKineAndEffCmplncErrDerivtvCutOffFrq_Val_data = TSC_SysKineAndEff_Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val();
  (void)memcpy(SysKineAndEffMotAgScaX_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotAgScaX_Ary1D(), sizeof(Ary1D_s15p0_21));
  (void)memcpy(SysKineAndEffMotAgToRackPosRatScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(), sizeof(Ary1D_u4p12_21));
  (void)memcpy(SysKineAndEffMotToRackEffScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D(), sizeof(Ary1D_u1p15_21));
  (void)memcpy(SysKineAndEffPinionAgToRackPosRatScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(), sizeof(Ary1D_u5p11_21));
  (void)memcpy(SysKineAndEffPinionToRackEffScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(), sizeof(Ary1D_u1p15_21));
  (void)memcpy(SysKineAndEffRackPosScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffRackPosScaY_Ary1D(), sizeof(Ary1D_s8p7_21));
  (void)memcpy(SysKineAndEffRoadWhlFromRackPosScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(), sizeof(Ary1D_s2p13_21));
  (void)memcpy(SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D_data, TSC_SysKineAndEff_Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(), sizeof(Ary1D_u1p15_21));

  fct_status = TSC_SysKineAndEff_Rte_Read_CmplncErrPinionToHw_Val(&Read_CmplncErrPinionToHw_Val);
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

  fct_status = TSC_SysKineAndEff_Rte_Read_MotAgCumvAlgndMrf_Val(&Read_MotAgCumvAlgndMrf_Val);
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

  fct_status = TSC_SysKineAndEff_Rte_Read_MotVelCrf_Val(&Read_MotVelCrf_Val);
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

  fct_status = TSC_SysKineAndEff_Rte_Read_PinionAg_Val(&Read_PinionAg_Val);
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

  fct_status = TSC_SysKineAndEff_Rte_Write_HwAg_Val(Rte_InitValue_HwAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_HwVel_Val(Rte_InitValue_HwVel_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_MotAgToRackPosnInstsRat_Val(Rte_InitValue_MotAgToRackPosnInstsRat_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_MotToRackFInstsRat_Val(Rte_InitValue_MotToRackFInstsRat_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_MotToRackInstsEff_Val(Rte_InitValue_MotToRackInstsEff_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_PinionAgToRackInstsEff_Val(Rte_InitValue_PinionAgToRackInstsEff_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_PinionAgToRackPosnInstsRat_Val(Rte_InitValue_PinionAgToRackPosnInstsRat_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_PinionTqToRackFInstsRat_Val(Rte_InitValue_PinionTqToRackFInstsRat_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_PinionVel_Val(Rte_InitValue_PinionVel_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_RackPosn_Val(Rte_InitValue_RackPosn_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_RackVel_Val(Rte_InitValue_RackVel_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_RoadWhlAg_Val(Rte_InitValue_RoadWhlAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_SteerArmLen_Val(Rte_InitValue_SteerArmLen_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_SysAssiTqRat_Val(Rte_InitValue_SysAssiTqRat_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_SysKineRat_Val(Rte_InitValue_SysKineRat_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_SysKineAndEff_Rte_Write_SysTqRat_Val(Rte_InitValue_SysTqRat_Val);
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


#define SysKineAndEff_STOP_SEC_CODE
#include "SysKineAndEff_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
