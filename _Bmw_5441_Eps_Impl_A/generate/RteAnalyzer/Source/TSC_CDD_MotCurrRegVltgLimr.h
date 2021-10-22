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
 *          File:  TSC_CDD_MotCurrRegVltgLimr.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Calibration Component Calibration Parameters */
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegCfgMotRVirtDax_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegCfgMotRVirtQax_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrCurrLoaScarSlewRate_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrDaxAntiWdupCoeff_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrFETLoaScarSlewRate_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotCurrPredTi_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupCoeff_Val(void);
float32  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotRefMdlIvtrDeadTiBrdgVltgSca_Val(void);
boolean  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegCfgCurrLoopSecOrderTrfFctEna_Logl(void);
boolean  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotCurrPredEna_Logl(void);
boolean  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotCurrQaxRefMdfnRplEna_Logl(void);
boolean  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgFilEna_Logl(void);
boolean  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfFilEna_Logl(void);
boolean  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl(void);
boolean  TSC_CDD_MotCurrRegVltgLimr_Rte_Prm_MotRefMdlFbCtrlDi_Logl(void);

/** Per Instance Memories */
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_AntiWdupCmdScaDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_AntiWdupCmdScaQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_CurrLoaScarPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_DualEcuLoaScarPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_FETLoaScarPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_IvtrLoaScarPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotCtrlMotVltgDaxPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotCtrlMotVltgQaxPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgIntglCmdDaxPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgIntglCmdQaxPrev(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrAntiWdupCmdScaQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdErrQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotCurrCmdScaQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgBrdgFild(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdFinal(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgCmdPreLim(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDampgQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxFb(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDaxIntglPreLim(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDecoupldFbQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgDircFbQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPreLimQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdDax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgPropCmdQax(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFb(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxFfFild(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgQaxIntglPreLim(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnIvsRat(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrMotVltgSatnRat(void);
float32 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_dMotCurrRegVltgLimrPhaAdvPreDly(void);
FilLpRec1 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgBrdgLpFil(void);
FilLpRec1 *TSC_CDD_MotCurrRegVltgLimr_Rte_Pim_MotVltgQaxFfLpFil(void);



