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
 *          File:  TSC_MotCtrlPrmEstimn.h
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
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotCurrDaxCmd_Val(float32 *data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotCurrQaxCmd_Val(float32 *data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotFetT_Val(float32 *data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotMagT_Val(float32 *data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Read_MotWidgT_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotBackEmfConEstimd_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimd_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimd_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotREstimd_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotBackEmfConEstimd_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimd_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimdIvs_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimd_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimdIvs_Val(float32 data);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Write_MotREstimd_Val(float32 data);

/** Service interfaces */
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Explicit inter-runnable variables */
float32 TSC_MotCtrlPrmEstimn_Rte_IrvRead_MotCtrlPrmEstimnPer1_MotBackEmfConFf(void);
void TSC_MotCtrlPrmEstimn_Rte_IrvWrite_MotCtrlPrmEstimnPer2_MotBackEmfConFf(float32);

/** Calibration Component Calibration Parameters */
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val(void);
float32  TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnTNom_Val(void);
Ary1D_u9p7_16 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(void);
Ary1D_u2p14_16 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(void);
Ary1D_u9p7_6 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(void);
Ary1D_u9p7_7 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(void);
Ary2D_u2p14_6_7 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(void);
Ary2D_u2p14_6_7 * TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(void);

/** Per Instance Memories */
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax(void);
float32 *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd(void);
MotPrmNomEolRec3 *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom(void);



