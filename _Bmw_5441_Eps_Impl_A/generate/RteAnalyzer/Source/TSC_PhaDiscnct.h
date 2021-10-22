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
 *          File:  TSC_PhaDiscnct.h
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
Std_ReturnType TSC_PhaDiscnct_Rte_Read_DiagcStsIvtr1Inactv_Logl(boolean *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrCorrdA_Val(float32 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrCorrdB_Val(float32 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrCorrdC_Val(float32 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_MotCurrQlfr1_Val(SigQlfr1 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_StrtUpSt_Val(uint8 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_IvtrFetFltPha_Val(IvtrFetFltPha1 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_IvtrFetFltTyp_Val(IvtrFetFltTyp1 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_StrtUpSt_Val(uint8 *data);
Std_ReturnType TSC_PhaDiscnct_Rte_Read_SysSt_Val(SysSt1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctDiagcActv_Logl(boolean data);
Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctDiagcPwmVect_Val(PhaDiscnctPwmVect1 data);
Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctInactv_Logl(boolean data);
Std_ReturnType TSC_PhaDiscnct_Rte_Write_PhaDiscnctWrmIninTestCmpl_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctA_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctB_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_PhaDiscnct_Rte_Call_IoHwAb_SetGpioPhaDiscnctC_Oper(boolean PinSt_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestCurrTestVal_Val(void);
uint32  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctFixdPhaOnTi_Val(void);
uint32  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctFixdPwmPerd_Val(void);
uint16  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctClsDlyTi_Val(void);
uint16  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctOpenDlyTi_Val(void);
uint8  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestFailScanMax_Val(void);
uint8  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestIninScan_Val(void);
uint8  TSC_PhaDiscnct_Rte_Prm_PhaDiscnctTestScanCnt_Val(void);

/** Per Instance Memories */
uint32 *TSC_PhaDiscnct_Rte_Pim_DiscnctClsTmr(void);
uint32 *TSC_PhaDiscnct_Rte_Pim_DiscnctOpenTmr(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagCurrComp(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagFailScan(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagFltSts(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagItrn(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagSt(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctDiagTestScan(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctFltPrm(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_DiscnctSt(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_PrevDiscnctCmd(void);
uint8 *TSC_PhaDiscnct_Rte_Pim_dPhaDiscnctCmd(void);
boolean *TSC_PhaDiscnct_Rte_Pim_WrmIninTestCmpl(void);
boolean *TSC_PhaDiscnct_Rte_Pim_dPhaDiscnctActvd(void);



