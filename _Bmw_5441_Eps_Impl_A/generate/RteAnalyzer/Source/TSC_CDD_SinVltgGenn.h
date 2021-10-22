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
 *          File:  TSC_CDD_SinVltgGenn.h
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
Std_ReturnType TSC_CDD_SinVltgGenn_Rte_Read_MotElecMeclPolarity_Val(sint8 *data);

/** Calibration Component Calibration Parameters */
float32  TSC_CDD_SinVltgGenn_Rte_Prm_MotAgSwCalVehSpdThd_Val(void);
float32  TSC_CDD_SinVltgGenn_Rte_Prm_SinVltgGennDthrLpFilCoeff_Val(void);
boolean  TSC_CDD_SinVltgGenn_Rte_Prm_SinVltgGennDthrEna_Logl(void);

/** Per Instance Memories */
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_Fil1OutpPrev(void);
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_Fil2OutpPrev(void);
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaDptOffsA(void);
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaDptOffsB(void);
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaDptOffsC(void);
float32 *TSC_CDD_SinVltgGenn_Rte_Pim_RndNrPrev(void);
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaOnTiSumAPrev(void);
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaOnTiSumBPrev(void);
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PhaOnTiSumCPrev(void);
uint32 *TSC_CDD_SinVltgGenn_Rte_Pim_PwmPerdRng(void);



