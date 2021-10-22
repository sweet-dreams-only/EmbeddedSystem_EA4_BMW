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
 *          File:  TSC_CDD_DmaCfgAndUse.h
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
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Read_MotAg0SnsrCfgAdr_Val(uint32 *data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper(void);
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_ReadErrInjReg_Oper(uint32 *ErrId_Arg);
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_StrtErrInjCntr_Oper(void);
Std_ReturnType TSC_CDD_DmaCfgAndUse_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Per Instance Memories */
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcMaxDmaTrfTi(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0ReadPtrRst(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0SnsrCfgAdrStord(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg0TrsmStrt(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1ReadPtrRst(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1SnsrCfgAdrStord(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_MotAg1TrsmStrt(void);
uint32 *TSC_CDD_DmaCfgAndUse_Rte_Pim_d2MilliSecAdcActDmaTrfTi(void);



