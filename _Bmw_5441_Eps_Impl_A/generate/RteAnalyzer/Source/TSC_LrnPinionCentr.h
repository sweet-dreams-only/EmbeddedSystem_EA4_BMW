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
 *          File:  TSC_LrnPinionCentr.h
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
Std_ReturnType TSC_LrnPinionCentr_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_LrnPinionCentr_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_LrnPinionCentr_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_LrnPinionCentr_Rte_Read_PinionCentrLrnEna_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnCmd_Val(float32 data);
Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnHwCentr_Val(float32 data);
Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnHwTrvl_Val(float32 data);
Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnSt_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_LrnPinionCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_LrnPinionCentr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Explicit inter-runnable variables */
float32 TSC_LrnPinionCentr_Rte_IrvRead_LrnPinionCentrPer1_TarA(void);
float32 TSC_LrnPinionCentr_Rte_IrvRead_LrnPinionCentrPer1_TarVel(void);
void TSC_LrnPinionCentr_Rte_IrvWrite_SetInpPrm_Oper_TarA(float32);
void TSC_LrnPinionCentr_Rte_IrvWrite_SetInpPrm_Oper_TarVel(float32);

/** Calibration Component Calibration Parameters */
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrDampgCtrlGain_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTq_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqErrThd_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqRateLim_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHwPosnErrThd_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrIntglCtrlGain_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMaxTqCmd_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMinMotTq_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMotVelThd_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrPropCtrlGain_Val(void);
float32  TSC_LrnPinionCentr_Rte_Prm_SysGlbPrmSysKineRat_Val(void);
uint16  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiOutThd_Val(void);
uint16  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiThd_Val(void);

/** Per Instance Memories */
float32 *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_TarHwAg(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_TarMotVel(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev(void);
float32 *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi(void);
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi(void);
uint8 *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev(void);
boolean *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev(void);
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil(void);
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil(void);
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil(void);
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil(void);
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil(void);
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil(void);
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil(void);



