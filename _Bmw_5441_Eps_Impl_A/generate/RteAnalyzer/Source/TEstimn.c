/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TEstimn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  TEstimn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <TEstimn>
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

#include "Rte_TEstimn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_TEstimn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void TEstimn_TestDefines(void);


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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Array Types:
 * ============
 * Ary1D_f32_3: Array with 3 element(s) of type float32
 * Ary1D_logl_3: Array with 3 element(s) of type boolean
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 * TFilStValRec1: Record with elements
 *   FilSiLpStVal of type float32
 *   FilMagLpStVal of type float32
 *   FilCuLpStVal of type float32
 *   FilAssisMechLpStVal of type float32
 *   FilSiLLStVal of type float32
 *   FilMagLLStVal of type float32
 *   FilCuLLStVal of type float32
 *   FilAssisMechLLStVal of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_AssiMechTEstimnPrev(void)
 *   float32 *Rte_Pim_AssiMechTSlewLimPrev(void)
 *   float32 *Rte_Pim_CuTEstimnPrev(void)
 *   float32 *Rte_Pim_FilAssiMechLLValPwrUp(void)
 *   float32 *Rte_Pim_FilAssiMechLpValPwrUp(void)
 *   float32 *Rte_Pim_FilCuLLValPwrUp(void)
 *   float32 *Rte_Pim_FilCuLpValPwrUp(void)
 *   float32 *Rte_Pim_FilMagLLValPwrUp(void)
 *   float32 *Rte_Pim_FilMagLpValPwrUp(void)
 *   float32 *Rte_Pim_FilSiLLValPwrUp(void)
 *   float32 *Rte_Pim_FilSiLpValPwrUp(void)
 *   float32 *Rte_Pim_MagTEstimnPrev(void)
 *   float32 *Rte_Pim_RepInitCntrVal(void)
 *   float32 *Rte_Pim_SiTEstimnPrev(void)
 *   float32 *Rte_Pim_dTEstimnAmbPwr(void)
 *   float32 *Rte_Pim_dTEstimnAssiMechCorrn(void)
 *   float32 *Rte_Pim_dTEstimnAssiMechDampgSca(void)
 *   float32 *Rte_Pim_dTEstimnAssiMechFil(void)
 *   float32 *Rte_Pim_dTEstimnCuCorrn(void)
 *   float32 *Rte_Pim_dTEstimnMagCorrn(void)
 *   float32 *Rte_Pim_dTEstimnScadAmbT(void)
 *   float32 *Rte_Pim_dTEstimnScadEngT(void)
 *   float32 *Rte_Pim_dTEstimnSiCorrn(void)
 *   float32 *Rte_Pim_dTEstimnWghtAvrgT(void)
 *   uint8 *Rte_Pim_TEstimnFltMtgtnCalIdx(void)
 *   boolean *Rte_Pim_AmbTVldPrev(void)
 *   boolean *Rte_Pim_AssiMechTInitEna(void)
 *   boolean *Rte_Pim_DualEcuFltMtgtnPrev(void)
 *   boolean *Rte_Pim_EngOilTVldPrev(void)
 *   boolean *Rte_Pim_FetMtgtnEnaPrev(void)
 *   boolean *Rte_Pim_RepInitCntrFlg(void)
 *   FilLpRec1 *Rte_Pim_AssiMechFilLp(void)
 *   FilLpRec1 *Rte_Pim_CuFilLp(void)
 *   FilLpRec1 *Rte_Pim_MagFilLp(void)
 *   FilLpRec1 *Rte_Pim_SiFilLp(void)
 *   TFilStValRec1 *Rte_Pim_TFilStVal(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val(void)
 *   float32 Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val(void)
 *   float32 Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val(void)
 *   float32 Rte_Prm_TEstimnCuAmbLpFilFrq_Val(void)
 *   float32 Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val(void)
 *   float32 Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val(void)
 *   float32 Rte_Prm_TEstimnIgnOffMsgWaitTi_Val(void)
 *   float32 Rte_Prm_TEstimnMagAmbLpFilFrq_Val(void)
 *   float32 Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val(void)
 *   float32 Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val(void)
 *   float32 Rte_Prm_TEstimnSiAmbLpFilFrq_Val(void)
 *   float32 Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val(void)
 *   float32 Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val(void)
 *   boolean Rte_Prm_TEstimnIgnOffCtrlEna_Logl(void)
 *   float32 *Rte_Prm_TEstimnAmbPwrMplr_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAmbTSca_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechDftT_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnAssiMechSlew_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTCu_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTMag_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCorrnTSi_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuAmbMplr_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuCorrnLim_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnEngTSca_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagAmbMplr_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagCorrnLim_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiAmbMplr_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiCorrnLim_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauAssiMech_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauCu_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauMag_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   float32 *Rte_Prm_TEstimnTauSi_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_3
 *   boolean *Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(void)
 *     Returnvalue: boolean* is of type Ary1D_logl_3
 *
 *********************************************************************************************************************/


#define TEstimn_START_SEC_CODE
#include "TEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TEstimnInit1
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
 *   Std_ReturnType Rte_Read_AmbT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_AmbTVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_EcuTFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EngOilT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EngOilTVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_IgnTiOff_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_VehTiVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AssiMechT_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotFetT_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotMagT_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotWidgT_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_TEstimnInit1_FilStVariRepInitFlg(boolean data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_TFilStVal_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_TFilStVal_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TEstimnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TEstimn_CODE) TEstimnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TEstimnInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_AmbT_Val;
  boolean Read_AmbTVld_Logl;
  boolean Read_DualEcuFltMtgtnEna_Logl;
  float32 Read_EcuTFild_Val;
  float32 Read_EngOilT_Val;
  boolean Read_EngOilTVld_Logl;
  uint32 Read_IgnTiOff_Val;
  uint8 Read_MotAndThermProtnLoaMod_Val;
  boolean Read_VehTiVld_Logl;

  float32 PimAssiMechTEstimnPrev;
  float32 PimAssiMechTSlewLimPrev;
  float32 PimCuTEstimnPrev;
  float32 PimFilAssiMechLLValPwrUp;
  float32 PimFilAssiMechLpValPwrUp;
  float32 PimFilCuLLValPwrUp;
  float32 PimFilCuLpValPwrUp;
  float32 PimFilMagLLValPwrUp;
  float32 PimFilMagLpValPwrUp;
  float32 PimFilSiLLValPwrUp;
  float32 PimFilSiLpValPwrUp;
  float32 PimMagTEstimnPrev;
  float32 PimRepInitCntrVal;
  float32 PimSiTEstimnPrev;
  float32 PimdTEstimnAmbPwr;
  float32 PimdTEstimnAssiMechCorrn;
  float32 PimdTEstimnAssiMechDampgSca;
  float32 PimdTEstimnAssiMechFil;
  float32 PimdTEstimnCuCorrn;
  float32 PimdTEstimnMagCorrn;
  float32 PimdTEstimnScadAmbT;
  float32 PimdTEstimnScadEngT;
  float32 PimdTEstimnSiCorrn;
  float32 PimdTEstimnWghtAvrgT;
  uint8 PimTEstimnFltMtgtnCalIdx;
  boolean PimAmbTVldPrev;
  boolean PimAssiMechTInitEna;
  boolean PimDualEcuFltMtgtnPrev;
  boolean PimEngOilTVldPrev;
  boolean PimFetMtgtnEnaPrev;
  boolean PimRepInitCntrFlg;
  FilLpRec1 PimAssiMechFilLp;
  FilLpRec1 PimCuFilLp;
  FilLpRec1 PimMagFilLp;
  FilLpRec1 PimSiFilLp;
  TFilStValRec1 PimTFilStVal;

  float32 TEstimnAssiMechAmbLpFilFrq_Val_data;
  float32 TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnCuAmbLpFilFrq_Val_data;
  float32 TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnCuAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnIgnOffMsgWaitTi_Val_data;
  float32 TEstimnMagAmbLpFilFrq_Val_data;
  float32 TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnMagAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnSiAmbLpFilFrq_Val_data;
  float32 TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnSiAmbLpFilFrqFetMtgtnEna_Val_data;
  boolean TEstimnIgnOffCtrlEna_Logl_data;
  Ary1D_f32_3 TEstimnAmbPwrMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnAmbTSca_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechCorrLim_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechDampgSca_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechDftT_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechSlew_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTAssiMech_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTCu_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTMag_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTSi_Ary1D_data;
  Ary1D_f32_3 TEstimnCuAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnCuCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnEngTSca_Ary1D_data;
  Ary1D_f32_3 TEstimnMagAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnMagCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnSiAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnSiCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnTauAssiMech_Ary1D_data;
  Ary1D_f32_3 TEstimnTauCu_Ary1D_data;
  Ary1D_f32_3 TEstimnTauMag_Ary1D_data;
  Ary1D_f32_3 TEstimnTauSi_Ary1D_data;
  Ary1D_logl_3 TEstimnWghtAvrgTDi_Ary1D_data;

  NvM_RequestResultType Call_TFilStVal_GetErrorStatus_ErrorStatus_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAssiMechTEstimnPrev = *TSC_TEstimn_Rte_Pim_AssiMechTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_AssiMechTEstimnPrev() = PimAssiMechTEstimnPrev;
  PimAssiMechTSlewLimPrev = *TSC_TEstimn_Rte_Pim_AssiMechTSlewLimPrev();
  *TSC_TEstimn_Rte_Pim_AssiMechTSlewLimPrev() = PimAssiMechTSlewLimPrev;
  PimCuTEstimnPrev = *TSC_TEstimn_Rte_Pim_CuTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_CuTEstimnPrev() = PimCuTEstimnPrev;
  PimFilAssiMechLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilAssiMechLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilAssiMechLLValPwrUp() = PimFilAssiMechLLValPwrUp;
  PimFilAssiMechLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilAssiMechLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilAssiMechLpValPwrUp() = PimFilAssiMechLpValPwrUp;
  PimFilCuLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilCuLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilCuLLValPwrUp() = PimFilCuLLValPwrUp;
  PimFilCuLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilCuLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilCuLpValPwrUp() = PimFilCuLpValPwrUp;
  PimFilMagLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilMagLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilMagLLValPwrUp() = PimFilMagLLValPwrUp;
  PimFilMagLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilMagLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilMagLpValPwrUp() = PimFilMagLpValPwrUp;
  PimFilSiLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilSiLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilSiLLValPwrUp() = PimFilSiLLValPwrUp;
  PimFilSiLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilSiLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilSiLpValPwrUp() = PimFilSiLpValPwrUp;
  PimMagTEstimnPrev = *TSC_TEstimn_Rte_Pim_MagTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_MagTEstimnPrev() = PimMagTEstimnPrev;
  PimRepInitCntrVal = *TSC_TEstimn_Rte_Pim_RepInitCntrVal();
  *TSC_TEstimn_Rte_Pim_RepInitCntrVal() = PimRepInitCntrVal;
  PimSiTEstimnPrev = *TSC_TEstimn_Rte_Pim_SiTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_SiTEstimnPrev() = PimSiTEstimnPrev;
  PimdTEstimnAmbPwr = *TSC_TEstimn_Rte_Pim_dTEstimnAmbPwr();
  *TSC_TEstimn_Rte_Pim_dTEstimnAmbPwr() = PimdTEstimnAmbPwr;
  PimdTEstimnAssiMechCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechCorrn() = PimdTEstimnAssiMechCorrn;
  PimdTEstimnAssiMechDampgSca = *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechDampgSca();
  *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechDampgSca() = PimdTEstimnAssiMechDampgSca;
  PimdTEstimnAssiMechFil = *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechFil();
  *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechFil() = PimdTEstimnAssiMechFil;
  PimdTEstimnCuCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnCuCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnCuCorrn() = PimdTEstimnCuCorrn;
  PimdTEstimnMagCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnMagCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnMagCorrn() = PimdTEstimnMagCorrn;
  PimdTEstimnScadAmbT = *TSC_TEstimn_Rte_Pim_dTEstimnScadAmbT();
  *TSC_TEstimn_Rte_Pim_dTEstimnScadAmbT() = PimdTEstimnScadAmbT;
  PimdTEstimnScadEngT = *TSC_TEstimn_Rte_Pim_dTEstimnScadEngT();
  *TSC_TEstimn_Rte_Pim_dTEstimnScadEngT() = PimdTEstimnScadEngT;
  PimdTEstimnSiCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnSiCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnSiCorrn() = PimdTEstimnSiCorrn;
  PimdTEstimnWghtAvrgT = *TSC_TEstimn_Rte_Pim_dTEstimnWghtAvrgT();
  *TSC_TEstimn_Rte_Pim_dTEstimnWghtAvrgT() = PimdTEstimnWghtAvrgT;
  PimTEstimnFltMtgtnCalIdx = *TSC_TEstimn_Rte_Pim_TEstimnFltMtgtnCalIdx();
  *TSC_TEstimn_Rte_Pim_TEstimnFltMtgtnCalIdx() = PimTEstimnFltMtgtnCalIdx;
  PimAmbTVldPrev = *TSC_TEstimn_Rte_Pim_AmbTVldPrev();
  *TSC_TEstimn_Rte_Pim_AmbTVldPrev() = PimAmbTVldPrev;
  PimAssiMechTInitEna = *TSC_TEstimn_Rte_Pim_AssiMechTInitEna();
  *TSC_TEstimn_Rte_Pim_AssiMechTInitEna() = PimAssiMechTInitEna;
  PimDualEcuFltMtgtnPrev = *TSC_TEstimn_Rte_Pim_DualEcuFltMtgtnPrev();
  *TSC_TEstimn_Rte_Pim_DualEcuFltMtgtnPrev() = PimDualEcuFltMtgtnPrev;
  PimEngOilTVldPrev = *TSC_TEstimn_Rte_Pim_EngOilTVldPrev();
  *TSC_TEstimn_Rte_Pim_EngOilTVldPrev() = PimEngOilTVldPrev;
  PimFetMtgtnEnaPrev = *TSC_TEstimn_Rte_Pim_FetMtgtnEnaPrev();
  *TSC_TEstimn_Rte_Pim_FetMtgtnEnaPrev() = PimFetMtgtnEnaPrev;
  PimRepInitCntrFlg = *TSC_TEstimn_Rte_Pim_RepInitCntrFlg();
  *TSC_TEstimn_Rte_Pim_RepInitCntrFlg() = PimRepInitCntrFlg;
  PimAssiMechFilLp = *TSC_TEstimn_Rte_Pim_AssiMechFilLp();
  *TSC_TEstimn_Rte_Pim_AssiMechFilLp() = PimAssiMechFilLp;
  PimCuFilLp = *TSC_TEstimn_Rte_Pim_CuFilLp();
  *TSC_TEstimn_Rte_Pim_CuFilLp() = PimCuFilLp;
  PimMagFilLp = *TSC_TEstimn_Rte_Pim_MagFilLp();
  *TSC_TEstimn_Rte_Pim_MagFilLp() = PimMagFilLp;
  PimSiFilLp = *TSC_TEstimn_Rte_Pim_SiFilLp();
  *TSC_TEstimn_Rte_Pim_SiFilLp() = PimSiFilLp;
  PimTFilStVal = *TSC_TEstimn_Rte_Pim_TFilStVal();
  *TSC_TEstimn_Rte_Pim_TFilStVal() = PimTFilStVal;

  TEstimnAssiMechAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val();
  TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnCuAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrq_Val();
  TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnCuAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnIgnOffMsgWaitTi_Val_data = TSC_TEstimn_Rte_Prm_TEstimnIgnOffMsgWaitTi_Val();
  TEstimnMagAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrq_Val();
  TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnMagAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnSiAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrq_Val();
  TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnSiAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnIgnOffCtrlEna_Logl_data = TSC_TEstimn_Rte_Prm_TEstimnIgnOffCtrlEna_Logl();
  (void)memcpy(TEstimnAmbPwrMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAmbPwrMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAmbTSca_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAmbTSca_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechCorrLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechDampgSca_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechDftT_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechDftT_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechSlew_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechSlew_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTAssiMech_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTCu_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTCu_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTMag_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTMag_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTSi_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTSi_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuCorrnLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuCorrnLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnEngTSca_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnEngTSca_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagCorrnLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagCorrnLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiCorrnLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiCorrnLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauAssiMech_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauAssiMech_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauCu_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauCu_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauMag_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauMag_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauSi_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauSi_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnWghtAvrgTDi_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(), sizeof(Ary1D_logl_3));

  fct_status = TSC_TEstimn_Rte_Read_AmbT_Val(&Read_AmbT_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_AmbTVld_Logl(&Read_AmbTVld_Logl);
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

  fct_status = TSC_TEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(&Read_DualEcuFltMtgtnEna_Logl);
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

  fct_status = TSC_TEstimn_Rte_Read_EcuTFild_Val(&Read_EcuTFild_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_EngOilT_Val(&Read_EngOilT_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_EngOilTVld_Logl(&Read_EngOilTVld_Logl);
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

  fct_status = TSC_TEstimn_Rte_Read_IgnTiOff_Val(&Read_IgnTiOff_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(&Read_MotAndThermProtnLoaMod_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_VehTiVld_Logl(&Read_VehTiVld_Logl);
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

  fct_status = TSC_TEstimn_Rte_Write_AssiMechT_Val(Rte_InitValue_AssiMechT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TEstimn_Rte_Write_MotFetT_Val(Rte_InitValue_MotFetT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TEstimn_Rte_Write_MotMagT_Val(Rte_InitValue_MotMagT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TEstimn_Rte_Write_MotWidgT_Val(Rte_InitValue_MotWidgT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  TSC_TEstimn_Rte_IrvWrite_TEstimnInit1_FilStVariRepInitFlg(FALSE);

  fct_status = TSC_TEstimn_Rte_Call_TFilStVal_GetErrorStatus(&Call_TFilStVal_GetErrorStatus_ErrorStatus_Arg);
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
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_TEstimn_Rte_Call_TFilStVal_SetRamBlockStatus(FALSE);
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
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }

  TEstimn_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TEstimnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AmbT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_AmbTVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_AssiMechTEstimnDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_EcuTFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EngOilT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EngOilTVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_IgnTiOff_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotCurrPeakEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehTiVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AssiMechT_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotFetT_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotMagT_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotWidgT_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   boolean Rte_IrvRead_TEstimnPer1_FilStVariRepInitFlg(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_TFilStVal_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TEstimnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TEstimn_CODE) TEstimnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TEstimnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_AmbT_Val;
  boolean Read_AmbTVld_Logl;
  boolean Read_AssiMechTEstimnDi_Logl;
  boolean Read_DualEcuFltMtgtnEna_Logl;
  float32 Read_EcuTFild_Val;
  float32 Read_EngOilT_Val;
  boolean Read_EngOilTVld_Logl;
  float32 Read_HwVel_Val;
  uint32 Read_IgnTiOff_Val;
  uint8 Read_MotAndThermProtnLoaMod_Val;
  float32 Read_MotCurrPeakEstimd_Val;
  boolean Read_VehTiVld_Logl;

  float32 PimAssiMechTEstimnPrev;
  float32 PimAssiMechTSlewLimPrev;
  float32 PimCuTEstimnPrev;
  float32 PimFilAssiMechLLValPwrUp;
  float32 PimFilAssiMechLpValPwrUp;
  float32 PimFilCuLLValPwrUp;
  float32 PimFilCuLpValPwrUp;
  float32 PimFilMagLLValPwrUp;
  float32 PimFilMagLpValPwrUp;
  float32 PimFilSiLLValPwrUp;
  float32 PimFilSiLpValPwrUp;
  float32 PimMagTEstimnPrev;
  float32 PimRepInitCntrVal;
  float32 PimSiTEstimnPrev;
  float32 PimdTEstimnAmbPwr;
  float32 PimdTEstimnAssiMechCorrn;
  float32 PimdTEstimnAssiMechDampgSca;
  float32 PimdTEstimnAssiMechFil;
  float32 PimdTEstimnCuCorrn;
  float32 PimdTEstimnMagCorrn;
  float32 PimdTEstimnScadAmbT;
  float32 PimdTEstimnScadEngT;
  float32 PimdTEstimnSiCorrn;
  float32 PimdTEstimnWghtAvrgT;
  uint8 PimTEstimnFltMtgtnCalIdx;
  boolean PimAmbTVldPrev;
  boolean PimAssiMechTInitEna;
  boolean PimDualEcuFltMtgtnPrev;
  boolean PimEngOilTVldPrev;
  boolean PimFetMtgtnEnaPrev;
  boolean PimRepInitCntrFlg;
  FilLpRec1 PimAssiMechFilLp;
  FilLpRec1 PimCuFilLp;
  FilLpRec1 PimMagFilLp;
  FilLpRec1 PimSiFilLp;
  TFilStValRec1 PimTFilStVal;

  float32 TEstimnAssiMechAmbLpFilFrq_Val_data;
  float32 TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnCuAmbLpFilFrq_Val_data;
  float32 TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnCuAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnIgnOffMsgWaitTi_Val_data;
  float32 TEstimnMagAmbLpFilFrq_Val_data;
  float32 TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnMagAmbLpFilFrqFetMtgtnEna_Val_data;
  float32 TEstimnSiAmbLpFilFrq_Val_data;
  float32 TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val_data;
  float32 TEstimnSiAmbLpFilFrqFetMtgtnEna_Val_data;
  boolean TEstimnIgnOffCtrlEna_Logl_data;
  Ary1D_f32_3 TEstimnAmbPwrMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnAmbTSca_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechCorrLim_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechDampgSca_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechDftT_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnAssiMechSlew_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTAssiMech_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTCu_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTMag_Ary1D_data;
  Ary1D_f32_3 TEstimnCorrnTSi_Ary1D_data;
  Ary1D_f32_3 TEstimnCuAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnCuCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnCuLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnEngTSca_Ary1D_data;
  Ary1D_f32_3 TEstimnMagAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnMagCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnMagLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnSiAmbMplr_Ary1D_data;
  Ary1D_f32_3 TEstimnSiCorrnLim_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffA1_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffB0_Ary1D_data;
  Ary1D_f32_3 TEstimnSiLLFilCoeffB1_Ary1D_data;
  Ary1D_f32_3 TEstimnTauAssiMech_Ary1D_data;
  Ary1D_f32_3 TEstimnTauCu_Ary1D_data;
  Ary1D_f32_3 TEstimnTauMag_Ary1D_data;
  Ary1D_f32_3 TEstimnTauSi_Ary1D_data;
  Ary1D_logl_3 TEstimnWghtAvrgTDi_Ary1D_data;

  boolean TEstimnPer1_FilStVariRepInitFlg;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimAssiMechTEstimnPrev = *TSC_TEstimn_Rte_Pim_AssiMechTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_AssiMechTEstimnPrev() = PimAssiMechTEstimnPrev;
  PimAssiMechTSlewLimPrev = *TSC_TEstimn_Rte_Pim_AssiMechTSlewLimPrev();
  *TSC_TEstimn_Rte_Pim_AssiMechTSlewLimPrev() = PimAssiMechTSlewLimPrev;
  PimCuTEstimnPrev = *TSC_TEstimn_Rte_Pim_CuTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_CuTEstimnPrev() = PimCuTEstimnPrev;
  PimFilAssiMechLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilAssiMechLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilAssiMechLLValPwrUp() = PimFilAssiMechLLValPwrUp;
  PimFilAssiMechLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilAssiMechLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilAssiMechLpValPwrUp() = PimFilAssiMechLpValPwrUp;
  PimFilCuLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilCuLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilCuLLValPwrUp() = PimFilCuLLValPwrUp;
  PimFilCuLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilCuLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilCuLpValPwrUp() = PimFilCuLpValPwrUp;
  PimFilMagLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilMagLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilMagLLValPwrUp() = PimFilMagLLValPwrUp;
  PimFilMagLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilMagLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilMagLpValPwrUp() = PimFilMagLpValPwrUp;
  PimFilSiLLValPwrUp = *TSC_TEstimn_Rte_Pim_FilSiLLValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilSiLLValPwrUp() = PimFilSiLLValPwrUp;
  PimFilSiLpValPwrUp = *TSC_TEstimn_Rte_Pim_FilSiLpValPwrUp();
  *TSC_TEstimn_Rte_Pim_FilSiLpValPwrUp() = PimFilSiLpValPwrUp;
  PimMagTEstimnPrev = *TSC_TEstimn_Rte_Pim_MagTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_MagTEstimnPrev() = PimMagTEstimnPrev;
  PimRepInitCntrVal = *TSC_TEstimn_Rte_Pim_RepInitCntrVal();
  *TSC_TEstimn_Rte_Pim_RepInitCntrVal() = PimRepInitCntrVal;
  PimSiTEstimnPrev = *TSC_TEstimn_Rte_Pim_SiTEstimnPrev();
  *TSC_TEstimn_Rte_Pim_SiTEstimnPrev() = PimSiTEstimnPrev;
  PimdTEstimnAmbPwr = *TSC_TEstimn_Rte_Pim_dTEstimnAmbPwr();
  *TSC_TEstimn_Rte_Pim_dTEstimnAmbPwr() = PimdTEstimnAmbPwr;
  PimdTEstimnAssiMechCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechCorrn() = PimdTEstimnAssiMechCorrn;
  PimdTEstimnAssiMechDampgSca = *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechDampgSca();
  *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechDampgSca() = PimdTEstimnAssiMechDampgSca;
  PimdTEstimnAssiMechFil = *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechFil();
  *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechFil() = PimdTEstimnAssiMechFil;
  PimdTEstimnCuCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnCuCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnCuCorrn() = PimdTEstimnCuCorrn;
  PimdTEstimnMagCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnMagCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnMagCorrn() = PimdTEstimnMagCorrn;
  PimdTEstimnScadAmbT = *TSC_TEstimn_Rte_Pim_dTEstimnScadAmbT();
  *TSC_TEstimn_Rte_Pim_dTEstimnScadAmbT() = PimdTEstimnScadAmbT;
  PimdTEstimnScadEngT = *TSC_TEstimn_Rte_Pim_dTEstimnScadEngT();
  *TSC_TEstimn_Rte_Pim_dTEstimnScadEngT() = PimdTEstimnScadEngT;
  PimdTEstimnSiCorrn = *TSC_TEstimn_Rte_Pim_dTEstimnSiCorrn();
  *TSC_TEstimn_Rte_Pim_dTEstimnSiCorrn() = PimdTEstimnSiCorrn;
  PimdTEstimnWghtAvrgT = *TSC_TEstimn_Rte_Pim_dTEstimnWghtAvrgT();
  *TSC_TEstimn_Rte_Pim_dTEstimnWghtAvrgT() = PimdTEstimnWghtAvrgT;
  PimTEstimnFltMtgtnCalIdx = *TSC_TEstimn_Rte_Pim_TEstimnFltMtgtnCalIdx();
  *TSC_TEstimn_Rte_Pim_TEstimnFltMtgtnCalIdx() = PimTEstimnFltMtgtnCalIdx;
  PimAmbTVldPrev = *TSC_TEstimn_Rte_Pim_AmbTVldPrev();
  *TSC_TEstimn_Rte_Pim_AmbTVldPrev() = PimAmbTVldPrev;
  PimAssiMechTInitEna = *TSC_TEstimn_Rte_Pim_AssiMechTInitEna();
  *TSC_TEstimn_Rte_Pim_AssiMechTInitEna() = PimAssiMechTInitEna;
  PimDualEcuFltMtgtnPrev = *TSC_TEstimn_Rte_Pim_DualEcuFltMtgtnPrev();
  *TSC_TEstimn_Rte_Pim_DualEcuFltMtgtnPrev() = PimDualEcuFltMtgtnPrev;
  PimEngOilTVldPrev = *TSC_TEstimn_Rte_Pim_EngOilTVldPrev();
  *TSC_TEstimn_Rte_Pim_EngOilTVldPrev() = PimEngOilTVldPrev;
  PimFetMtgtnEnaPrev = *TSC_TEstimn_Rte_Pim_FetMtgtnEnaPrev();
  *TSC_TEstimn_Rte_Pim_FetMtgtnEnaPrev() = PimFetMtgtnEnaPrev;
  PimRepInitCntrFlg = *TSC_TEstimn_Rte_Pim_RepInitCntrFlg();
  *TSC_TEstimn_Rte_Pim_RepInitCntrFlg() = PimRepInitCntrFlg;
  PimAssiMechFilLp = *TSC_TEstimn_Rte_Pim_AssiMechFilLp();
  *TSC_TEstimn_Rte_Pim_AssiMechFilLp() = PimAssiMechFilLp;
  PimCuFilLp = *TSC_TEstimn_Rte_Pim_CuFilLp();
  *TSC_TEstimn_Rte_Pim_CuFilLp() = PimCuFilLp;
  PimMagFilLp = *TSC_TEstimn_Rte_Pim_MagFilLp();
  *TSC_TEstimn_Rte_Pim_MagFilLp() = PimMagFilLp;
  PimSiFilLp = *TSC_TEstimn_Rte_Pim_SiFilLp();
  *TSC_TEstimn_Rte_Pim_SiFilLp() = PimSiFilLp;
  PimTFilStVal = *TSC_TEstimn_Rte_Pim_TFilStVal();
  *TSC_TEstimn_Rte_Pim_TFilStVal() = PimTFilStVal;

  TEstimnAssiMechAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val();
  TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnCuAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrq_Val();
  TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnCuAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnIgnOffMsgWaitTi_Val_data = TSC_TEstimn_Rte_Prm_TEstimnIgnOffMsgWaitTi_Val();
  TEstimnMagAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrq_Val();
  TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnMagAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnSiAmbLpFilFrq_Val_data = TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrq_Val();
  TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val_data = TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val();
  TEstimnSiAmbLpFilFrqFetMtgtnEna_Val_data = TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val();
  TEstimnIgnOffCtrlEna_Logl_data = TSC_TEstimn_Rte_Prm_TEstimnIgnOffCtrlEna_Logl();
  (void)memcpy(TEstimnAmbPwrMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAmbPwrMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAmbTSca_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAmbTSca_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechCorrLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechDampgSca_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechDftT_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechDftT_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnAssiMechSlew_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnAssiMechSlew_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTAssiMech_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTCu_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTCu_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTMag_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTMag_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCorrnTSi_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCorrnTSi_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuCorrnLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuCorrnLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnCuLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnEngTSca_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnEngTSca_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagCorrnLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagCorrnLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnMagLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiAmbMplr_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiAmbMplr_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiCorrnLim_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiCorrnLim_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffA1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffB0_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnSiLLFilCoeffB1_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauAssiMech_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauAssiMech_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauCu_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauCu_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauMag_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauMag_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnTauSi_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnTauSi_Ary1D(), sizeof(Ary1D_f32_3));
  (void)memcpy(TEstimnWghtAvrgTDi_Ary1D_data, TSC_TEstimn_Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(), sizeof(Ary1D_logl_3));

  fct_status = TSC_TEstimn_Rte_Read_AmbT_Val(&Read_AmbT_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_AmbTVld_Logl(&Read_AmbTVld_Logl);
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

  fct_status = TSC_TEstimn_Rte_Read_AssiMechTEstimnDi_Logl(&Read_AssiMechTEstimnDi_Logl);
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

  fct_status = TSC_TEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(&Read_DualEcuFltMtgtnEna_Logl);
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

  fct_status = TSC_TEstimn_Rte_Read_EcuTFild_Val(&Read_EcuTFild_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_EngOilT_Val(&Read_EngOilT_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_EngOilTVld_Logl(&Read_EngOilTVld_Logl);
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

  fct_status = TSC_TEstimn_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_IgnTiOff_Val(&Read_IgnTiOff_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(&Read_MotAndThermProtnLoaMod_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_MotCurrPeakEstimd_Val(&Read_MotCurrPeakEstimd_Val);
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

  fct_status = TSC_TEstimn_Rte_Read_VehTiVld_Logl(&Read_VehTiVld_Logl);
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

  fct_status = TSC_TEstimn_Rte_Write_AssiMechT_Val(Rte_InitValue_AssiMechT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TEstimn_Rte_Write_MotFetT_Val(Rte_InitValue_MotFetT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TEstimn_Rte_Write_MotMagT_Val(Rte_InitValue_MotMagT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_TEstimn_Rte_Write_MotWidgT_Val(Rte_InitValue_MotWidgT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  TEstimnPer1_FilStVariRepInitFlg = TSC_TEstimn_Rte_IrvRead_TEstimnPer1_FilStVariRepInitFlg();

  fct_status = TSC_TEstimn_Rte_Call_TFilStVal_SetRamBlockStatus(FALSE);
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
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define TEstimn_STOP_SEC_CODE
#include "TEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void TEstimn_TestDefines(void)
{
  /* Enumeration Data Types */

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;
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
