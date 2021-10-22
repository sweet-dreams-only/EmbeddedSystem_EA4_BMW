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
 *          File:  TSC_MotCurrPeakEstimn.h
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
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_DualEcuMotCtrlMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrDax_Val(float32 *data);
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrDaxCmd_Val(float32 *data);
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrQax_Val(float32 *data);
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrQaxCmd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Write_MotCurrPeakEstimd_Val(float32 data);
Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Write_MotCurrPeakEstimdFild_Val(float32 data);

/** Explicit inter-runnable variables */
void TSC_MotCurrPeakEstimn_Rte_IrvWrite_MotCurrPeakEstimnPer1_MotCurrEstimd(float32);
float32 TSC_MotCurrPeakEstimn_Rte_IrvRead_MotCurrPeakEstimnPer2_MotCurrEstimd(void);

/** Calibration Component Calibration Parameters */
float32  TSC_MotCurrPeakEstimn_Rte_Prm_MotCurrPeakEstimnCurrFilFrq_Val(void);
float32  TSC_MotCurrPeakEstimn_Rte_Prm_MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val(void);

/** Per Instance Memories */
float32 *TSC_MotCurrPeakEstimn_Rte_Pim_dMotCurrPeakEstimnMotCurrDaxFil(void);
float32 *TSC_MotCurrPeakEstimn_Rte_Pim_dMotCurrPeakEstimnMotCurrQaxFil(void);
FilLpRec1 *TSC_MotCurrPeakEstimn_Rte_Pim_MotCurrDaxFil(void);
FilLpRec1 *TSC_MotCurrPeakEstimn_Rte_Pim_MotCurrPeakEstimdFil(void);
FilLpRec1 *TSC_MotCurrPeakEstimn_Rte_Pim_MotCurrQaxFil(void);



