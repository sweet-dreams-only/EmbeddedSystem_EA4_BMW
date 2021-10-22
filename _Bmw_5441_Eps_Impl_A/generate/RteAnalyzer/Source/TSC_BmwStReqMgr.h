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
 *          File:  TSC_BmwStReqMgr.h
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
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_BmwVehCdnVld_Logl(boolean *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_PwrLimrRednFac_Val(float32 *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_SysStFltOutpReqDi_Logl(boolean *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_ThermRednFac_Val(float32 *data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_BmwEpsFctSts_Val(BmwEpsFctSts1 data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_PwrSplyEnaReq_Logl(boolean data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_StsDrvrActvy_Val(StsDrvrActvy1 data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_StsSteerAssi_Val(StsSteerAssi1 data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_SysOperMotTqCmdSca_Val(float32 data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_SysOperRampRate_Val(float32 data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_SysStReqEna_Logl(boolean data);
Std_ReturnType TSC_BmwStReqMgr_Rte_Write_TarEcuSt_Val(SysSt1 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwStReqMgr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwStReqMgr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwStReqMgr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_BmwStReqMgr_Rte_Call_IoHwAb_GetGpioMcuEna_Oper(boolean *PinSt_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrHwTqThd_Val(void);
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrOperRampRate_Val(void);
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val(void);
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val(void);
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val(void);
u16p0  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrAllwToOffThd_Val(void);
u16p0  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val(void);
uint8  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrVehCdnOvrd_Val(void);

/** Per Instance Memories */
float32 *TSC_BmwStReqMgr_Rte_Pim_PrevHwTq(void);
uint32 *TSC_BmwStReqMgr_Rte_Pim_BmwVehCdnLvngDurn(void);
uint32 *TSC_BmwStReqMgr_Rte_Pim_DrvrActvRefTmr(void);
uint8 *TSC_BmwStReqMgr_Rte_Pim_PrevTarEcuSt(void);



