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
 *          File:  TSC_CDD_McuDiagc.h
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
Std_ReturnType TSC_CDD_McuDiagc_Rte_Read_FastLoopCntr_Val(uint16 *data);
Std_ReturnType TSC_CDD_McuDiagc_Rte_Read_SlowLoopCntr_Val(uint16 *data);
Std_ReturnType TSC_CDD_McuDiagc_Rte_Read_SysSt_Val(SysSt1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_McuDiagc_Rte_Write_LoopCntr2MilliSec_Val(uint16 data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_McuDiagc_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
uint16  TSC_CDD_McuDiagc_Rte_Prm_McuDiagc2MilliSecCntrCompThd_Val(void);
uint16  TSC_CDD_McuDiagc_Rte_Prm_McuDiagcFltFailStep_Val(void);
uint16  TSC_CDD_McuDiagc_Rte_Prm_McuDiagcFltPassStep_Val(void);

/** Per Instance Memories */
uint16 *TSC_CDD_McuDiagc_Rte_Pim_FastLoopCntrPrev(void);
uint16 *TSC_CDD_McuDiagc_Rte_Pim_LoopCntr2MilliSecStore(void);
uint16 *TSC_CDD_McuDiagc_Rte_Pim_LoopCntrPrev(void);
uint16 *TSC_CDD_McuDiagc_Rte_Pim_dMcuDiagcFastLoopCntrMax(void);
uint16 *TSC_CDD_McuDiagc_Rte_Pim_dMcuDiagcFastLoopCntrMin(void);
uint16 *TSC_CDD_McuDiagc_Rte_Pim_dMcuDiagcLoopCntr2MilliSecMotCtrlDif(void);
uint8 *TSC_CDD_McuDiagc_Rte_Pim_FastLoopCntrDiagcCfgd(void);



