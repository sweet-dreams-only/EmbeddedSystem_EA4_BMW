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
 *          File:  TSC_LrndRackCentr.h
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
Std_ReturnType TSC_LrndRackCentr_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_HwAg_Val(float32 *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_MotTqCmd_Val(float32 *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnEna_Logl(boolean *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnHwCentr_Val(float32 *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnHwTrvl_Val(float32 *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnSt_Val(uint8 *data);
Std_ReturnType TSC_LrndRackCentr_Rte_Read_HwAg_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_LrndRackCentr_Rte_Write_LongTermRackCentrCmpl_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrCmpl_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrMotAgErrPrsnt_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrMotAgVld_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrPinionAg_Val(float32 data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_LongTermRackCentrCmpl_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrCmpl_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrMotAgVld_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrPinionAg_Val(float32 data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_TotRackTrvl_Val(float32 data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrMotAgVld_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_LongTermRackCentrCmpl_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrCmpl_Logl(boolean data);
Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrPinionAg_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_LrndRackCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_LrndRackCentr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_LrndRackCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);

/** Service interfaces */
Std_ReturnType TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrConfTrvlThd_Val(void);
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrHwAgFilFrq_Val(void);
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val(void);
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotTqThd_Val(void);
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotVelThd_Val(void);
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val(void);
float32  TSC_LrndRackCentr_Rte_Prm_SysGlbPrmSysKineRat_Val(void);
uint16  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrTiThd_Val(void);
boolean  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrAllwManIniLrng_Logl(void);

/** Per Instance Memories */
float32 *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot(void);
float32 *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot(void);
float32 *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev(void);
uint32 *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr(void);
uint32 *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr(void);
boolean *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld(void);
boolean *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld(void);
FilLpRec1 *TSC_LrndRackCentr_Rte_Pim_HwAgFil(void);
LrndRackCentrNvmRec1 *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr(void);



