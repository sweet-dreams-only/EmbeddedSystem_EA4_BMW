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
 *          File:  TSC_SysFricLrng.h
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
Std_ReturnType TSC_SysFricLrng_Rte_Read_AssiMechT_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_FricLrngCustEna_Logl(boolean *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_FricLrngDi_Logl(boolean *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_HwAgAuthy_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_MotTqCmdCrf_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_VehLatA_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_SysFricLrng_Rte_Read_VehSpdVld_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_SysFricLrng_Rte_Write_SysFricOffs_Val(float32 data);
Std_ReturnType TSC_SysFricLrng_Rte_Write_MaxLrndFric_Val(float32 data);
Std_ReturnType TSC_SysFricLrng_Rte_Write_SysFricEstimd_Val(float32 data);
Std_ReturnType TSC_SysFricLrng_Rte_Write_SysFricOffs_Val(float32 data);
Std_ReturnType TSC_SysFricLrng_Rte_Write_SysSatnFricEstimd_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_SysFricLrng_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_SysFricLrng_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_SysFricLrng_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg);
Std_ReturnType TSC_SysFricLrng_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_SysFricLrng_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_SysFricLrng_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_SysFricLrng_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_SysFricLrng_Rte_Call_FricNonLrngData_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_SysFricLrng_Rte_Call_FricLrngData_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngAvrgFricFrq_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineEolFric_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngEolFricDifHiLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngEolFricDifLoLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngEolFricDifScagFac_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricDiagcThd_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffs_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffsHiLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffsLoLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngGain_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHiFricDiagcThd_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwPosnAuthyThd_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwVelConstrLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwVelHiLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwVelLoLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngIgnCycFricChgLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngIgnCycFricOffs_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngLatAHiLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngLatALoLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngTHiLim_Val(void);
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngTLoLim_Val(void);
uint32  TSC_SysFricLrng_Rte_Prm_SysFricLrngThd_Val(void);
uint16  TSC_SysFricLrng_Rte_Prm_SysFricLrngDebStep_Val(void);
uint16  TSC_SysFricLrng_Rte_Prm_SysFricLrngHiFricDebStep_Val(void);
uint16  TSC_SysFricLrng_Rte_Prm_SysFricLrngRngCntrThd_Val(void);
Ary1D_f32_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineFric_Ary1D(void);
Ary2D_f32_8_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineHys_Ary2D(void);
Ary2D_u16_8_3 * TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D(void);
Ary1D_f32_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngFricChgWght_Ary1D(void);
Ary1D_f32_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D(void);
Ary1D_u11p5_10 * TSC_SysFricLrng_Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D(void);
Ary1D_u6p10_10 * TSC_SysFricLrng_Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D(void);
Ary1D_boolean_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngMaskVehSpd_Ary1D(void);
Ary2D_f32_4_2 * TSC_SysFricLrng_Rte_Prm_SysFricLrngVehSpd_Ary2D(void);

/** SW-C local Calibration Parameters */
SysFricDataRec1 * TSC_SysFricLrng_Rte_CData_FricLrngDataDft(void);
SysFricNonLrngDataRec1 * TSC_SysFricLrng_Rte_CData_FricNonLrngDataDft(void);

/** Per Instance Memories */
float32 *TSC_SysFricLrng_Rte_Pim_EstimdFric(void);
float32 *TSC_SysFricLrng_Rte_Pim_FricOffs(void);
float32 *TSC_SysFricLrng_Rte_Pim_PrevMaxRawAvrgFric(void);
float32 *TSC_SysFricLrng_Rte_Pim_SatnEstimdFric(void);
uint32 *TSC_SysFricLrng_Rte_Pim_RefTmrLrngConstr(void);
SysFricLrngOperMod1 *TSC_SysFricLrng_Rte_Pim_FricLrngOperModPrev(void);
boolean *TSC_SysFricLrng_Rte_Pim_FricLrngRunOneTi(void);
boolean *TSC_SysFricLrng_Rte_Pim_FricOffsOutpDi(void);
float32 *TSC_SysFricLrng_Rte_Pim_ColTqAry(void);
float32 *TSC_SysFricLrng_Rte_Pim_FilAvrgFric(void);
float32 *TSC_SysFricLrng_Rte_Pim_HwAgBuf(void);
float32 *TSC_SysFricLrng_Rte_Pim_HwVelBuf(void);
float32 *TSC_SysFricLrng_Rte_Pim_RawAvrgFric(void);
float32 *TSC_SysFricLrng_Rte_Pim_SatnAvrgFric(void);
float32 *TSC_SysFricLrng_Rte_Pim_VehBasLineFric(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AssiMechTLpFil(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil1(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil2(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil3(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil4(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_ColTqLpFil(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_FricChgLpFil(void);
SysFricDataRec1 *TSC_SysFricLrng_Rte_Pim_FricLrngData(void);
SysFricNonLrngDataRec1 *TSC_SysFricLrng_Rte_Pim_FricNonLrngData(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_HwAgAuthyLpFil(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_HwAgLpFil(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_HwVelLpFil(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_LatALpFil(void);
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_VehSpdLpFil(void);



