/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_TEstimn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_TEstimn_Rte_Read_AmbT_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_AmbTVld_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_EcuTFild_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_EngOilT_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_EngOilTVld_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_IgnTiOff_Val(uint32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_VehTiVld_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_AmbT_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_AmbTVld_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_AssiMechTEstimnDi_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_EcuTFild_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_EngOilT_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_EngOilTVld_Logl(boolean *data);
Std_ReturnType TSC_TEstimn_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_IgnTiOff_Val(uint32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_MotCurrPeakEstimd_Val(float32 *data);
Std_ReturnType TSC_TEstimn_Rte_Read_VehTiVld_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_TEstimn_Rte_Write_AssiMechT_Val(float32 data);
Std_ReturnType TSC_TEstimn_Rte_Write_MotFetT_Val(float32 data);
Std_ReturnType TSC_TEstimn_Rte_Write_MotMagT_Val(float32 data);
Std_ReturnType TSC_TEstimn_Rte_Write_MotWidgT_Val(float32 data);
Std_ReturnType TSC_TEstimn_Rte_Write_AssiMechT_Val(float32 data);
Std_ReturnType TSC_TEstimn_Rte_Write_MotFetT_Val(float32 data);
Std_ReturnType TSC_TEstimn_Rte_Write_MotMagT_Val(float32 data);
Std_ReturnType TSC_TEstimn_Rte_Write_MotWidgT_Val(float32 data);

/** Service interfaces */
Std_ReturnType TSC_TEstimn_Rte_Call_TFilStVal_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_TEstimn_Rte_Call_TFilStVal_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_TEstimn_Rte_Call_TFilStVal_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Explicit inter-runnable variables */
void TSC_TEstimn_Rte_IrvWrite_TEstimnInit1_FilStVariRepInitFlg(boolean);
boolean TSC_TEstimn_Rte_IrvRead_TEstimnPer1_FilStVariRepInitFlg(void);

/** Calibration Component Calibration Parameters */
float32  TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrq_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnIgnOffMsgWaitTi_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrq_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrq_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val(void);
float32  TSC_TEstimn_Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val(void);
boolean  TSC_TEstimn_Rte_Prm_TEstimnIgnOffCtrlEna_Logl(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAmbPwrMplr_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAmbTSca_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechDftT_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnAssiMechSlew_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTCu_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTMag_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCorrnTSi_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuAmbMplr_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuCorrnLim_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnEngTSca_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagAmbMplr_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagCorrnLim_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiAmbMplr_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiCorrnLim_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauAssiMech_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauCu_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauMag_Ary1D(void);
Ary1D_f32_3 * TSC_TEstimn_Rte_Prm_TEstimnTauSi_Ary1D(void);
Ary1D_logl_3 * TSC_TEstimn_Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_TEstimn_Rte_Pim_AssiMechTEstimnPrev(void);
float32 *TSC_TEstimn_Rte_Pim_AssiMechTSlewLimPrev(void);
float32 *TSC_TEstimn_Rte_Pim_CuTEstimnPrev(void);
float32 *TSC_TEstimn_Rte_Pim_FilAssiMechLLValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_FilAssiMechLpValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_FilCuLLValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_FilCuLpValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_FilMagLLValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_FilMagLpValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_FilSiLLValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_FilSiLpValPwrUp(void);
float32 *TSC_TEstimn_Rte_Pim_MagTEstimnPrev(void);
float32 *TSC_TEstimn_Rte_Pim_RepInitCntrVal(void);
float32 *TSC_TEstimn_Rte_Pim_SiTEstimnPrev(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAmbPwr(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechCorrn(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechDampgSca(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnAssiMechFil(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnCuCorrn(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnMagCorrn(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnScadAmbT(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnScadEngT(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnSiCorrn(void);
float32 *TSC_TEstimn_Rte_Pim_dTEstimnWghtAvrgT(void);
uint8 *TSC_TEstimn_Rte_Pim_TEstimnFltMtgtnCalIdx(void);
boolean *TSC_TEstimn_Rte_Pim_AmbTVldPrev(void);
boolean *TSC_TEstimn_Rte_Pim_AssiMechTInitEna(void);
boolean *TSC_TEstimn_Rte_Pim_DualEcuFltMtgtnPrev(void);
boolean *TSC_TEstimn_Rte_Pim_EngOilTVldPrev(void);
boolean *TSC_TEstimn_Rte_Pim_FetMtgtnEnaPrev(void);
boolean *TSC_TEstimn_Rte_Pim_RepInitCntrFlg(void);
FilLpRec1 *TSC_TEstimn_Rte_Pim_AssiMechFilLp(void);
FilLpRec1 *TSC_TEstimn_Rte_Pim_CuFilLp(void);
FilLpRec1 *TSC_TEstimn_Rte_Pim_MagFilLp(void);
FilLpRec1 *TSC_TEstimn_Rte_Pim_SiFilLp(void);
TFilStValRec1 *TSC_TEstimn_Rte_Pim_TFilStVal(void);



