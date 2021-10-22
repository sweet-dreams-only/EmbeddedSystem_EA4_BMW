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
 *          File:  TSC_BmwSplyCurrLim.h
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
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwMaxCurrLimr_Val(float32 *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwMaxCurrLimrSts_Val(BmwMaxCurrLimrSts1 *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwStrtStopLim_Val(float32 *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwStrtStopMsgActv_Logl(boolean *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BrdgVltg_Val(float32 *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_MaxCurrAtHiSpd_Val(float32 *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_MaxCurrAtLoSpd_Val(float32 *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_RemCtrlPrkgEna_Logl(boolean *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_SysMotTqCmdSca_Val(float32 *data);
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Write_SplyCurrLim_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val(void);
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val(void);
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D(void);
Ary1D_u8p8_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D(void);
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D(void);
Ary1D_u8p8_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D(void);
Ary1D_u9p7_6 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D(void);
Ary1D_u8p8_6 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D(void);
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D(void);
Ary1D_u16p0_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D(void);
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D(void);
Ary1D_u16p0_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_BmwSplyCurrLim_Rte_Pim_BmwMaxCurrLimGrdt(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_SplyCurrLimGrdt(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_VltgDptCurrLimGrdt(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimCurrLim(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimCurrLimPrel(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimGlbLim(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimSplyCurrLim(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim(void);
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim(void);



