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
 *          File:  TSC_BmwTqOvrlCdngAndDrvgDynFac.h
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
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynDampgFacReq_Val(float32 *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynEffortFacReq_Val(float32 *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynRtnFacReq_Val(float32 *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwOutpTqOvrlCmdEna_Logl(boolean *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwTarSteerTqDrvrActr_Val(float32 *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynActv_Logl(boolean *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynFacEna_Logl(boolean *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_OutpTqOvrlRampInEna_Logl(boolean *data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_BmwOutpTqOvrlCmd_Val(float32 data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_DampgCmdSca_Val(float32 data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_EffortCmdSca_Val(float32 data);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_RtnCmdSca_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val(void);
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val(void);
Ary1D_u11p5_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(void);
Ary2D_u1p15_12_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(void);
Ary1D_u4p12_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(void);
Ary2D_u2p14_12_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(void);
Ary1D_u4p12_10 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(void);
Ary1D_u9p7_10 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(void);
Ary1D_u9p7_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdStVari(void);
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_DampgCmdScaRateLimrStVari(void);
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_EffortCmdScaRateLimrStVari(void);
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznBmwTarSteerTqDrvrActr(void);
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_LimdCdndTqOvrl(void);
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RtnCmdScaRateLimrStVari(void);
uint32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_MsgCycTmr(void);
DrvgDynIfSt1 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynIfSt(void);
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdRampCmpl(void);
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznSigActv(void);
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDampgSlewInProgs(void);
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynActv(void);
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevEffortSlewInProgs(void);
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevRtnSlewInProgs(void);
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RampToZeroEnad(void);
FilLpRec1 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari(void);



