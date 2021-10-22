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
 *          File:  TSC_BmwDrvgDynStMac.h
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
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_MotTqCmdPwrLimd_Val(float32 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynEnaReq_Logl(boolean *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynFacQlfrVld_Logl(boolean *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(boolean *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_DampgCmdSca_Val(float32 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_EffortCmdSca_Val(float32 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_MotTqCmdPwrLimd_Val(float32 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_MotTqOvrlCmd_Val(float32 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_RtnCmdSca_Val(float32 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_SysStFltOutpReqDi_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Write_DrvgDynActv_Logl(boolean data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Write_DrvgDynIfSt_Val(DrvgDynIfSt1 data);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Write_OutpTqOvrlRampInEna_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val(void);
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val(void);
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val(void);
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val(void);
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val(void);
uint16  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val(void);
uint16  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val(void);
uint16  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val(void);

/** Per Instance Memories */
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlActvtTi(void);
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlDeactvtTi(void);
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_ErrIfTi(void);
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_VehCdnTi(void);
uint8 *TSC_BmwDrvgDynStMac_Rte_Pim_StMacSt(void);
boolean *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnActvt(void);
boolean *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnDeactvt(void);



