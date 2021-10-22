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
 *          File:  TSC_BmwTrfcJamAssiDampg.h
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
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(float32 *data);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean *data);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_TrfcJamAssiCmdEna_Logl(boolean *data);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Write_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 data);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Write_TrfcJamAssiCmd_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val(void);
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val(void);
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val(void);
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val(void);
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val(void);
uint16  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val(void);
Ary1D_u11p5_10 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(void);
Ary1D_u4p12_10 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(void);
Ary1D_u11p5_12 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(void);
Ary2D_u4p12_12_12 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(void);
Ary1D_u9p7_12 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_BmwTrfcJamAssiDampg_Rte_Pim_BmwTrfcJamAssiDampgScaStVari(void);
uint32 *TSC_BmwTrfcJamAssiDampg_Rte_Pim_LimExcddFltRefTi(void);
uint8 *TSC_BmwTrfcJamAssiDampg_Rte_Pim_TmpBmwTrfcJamAssiDampgSt(void);
boolean *TSC_BmwTrfcJamAssiDampg_Rte_Pim_PrevLimExcddFlt(void);



