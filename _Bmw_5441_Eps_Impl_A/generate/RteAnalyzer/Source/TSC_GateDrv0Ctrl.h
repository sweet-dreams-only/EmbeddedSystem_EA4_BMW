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
 *          File:  TSC_GateDrv0Ctrl.h
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
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_StrtUpSt_Val(uint8 *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_Ivtr1PwrDiscnctFltSts_Logl(boolean *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiMeasdA_Val(uint32 *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiMeasdB_Val(uint32 *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiMeasdC_Val(uint32 *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiSumA_Val(uint32 *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiSumB_Val(uint32 *data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Read_PhaOnTiSumC_Val(uint32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_DiagcStsIvtr1Inactv_Logl(boolean data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_IvtrFetFltPha_Val(IvtrFetFltPha1 data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_IvtrFetFltTyp_Val(IvtrFetFltTyp1 data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvErrA_Val(float32 data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvErrB_Val(float32 data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvErrC_Val(float32 data);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Write_MotDrvr0IninTestCmpl_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_GetGpioMotDrvr0Diag_Oper(boolean *PinSt_Arg);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_SetGpioGateDrv0Rst_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_GetGpioMotDrvr0Diag_Oper(boolean *PinSt_Arg);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_SetGpioGateDrv0Rst_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_IoHwAb_SetGpioSysFlt2A_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_GateDrv0Ctrl_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg);

/** Explicit inter-runnable variables */
void TSC_GateDrv0Ctrl_Rte_IrvWrite_GateDrv0CtrlPer1_GateDrv0Ena(boolean);
void TSC_GateDrv0Ctrl_Rte_IrvWrite_GateDrv0CtrlPer1_GateDrv0PhaReasbnDiagcEna(boolean);
void TSC_GateDrv0Ctrl_Rte_IrvWrite_GateDrv0CtrlPer1_Ivtr0PhyFltInpActv(boolean);
boolean TSC_GateDrv0Ctrl_Rte_IrvRead_GateDrv0CtrlPer2_GateDrv0Ena(void);
boolean TSC_GateDrv0Ctrl_Rte_IrvRead_GateDrv0CtrlPer2_GateDrv0PhaReasbnDiagcEna(void);
boolean TSC_GateDrv0Ctrl_Rte_IrvRead_GateDrv0CtrlPer2_Ivtr0PhyFltInpActv(void);

/** Calibration Component Calibration Parameters */
float32  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlErrFilFrq_Val(void);
uint32  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlErrOffs_Val(void);
uint32  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlErrThd_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x050FailStep_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x050PassStep_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x051FailStep_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x051PassStep_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x055FailStep_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlNtcNr0x055PassStep_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg2WrVal_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg3WrVal_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg4WrVal_Val(void);
uint16  TSC_GateDrv0Ctrl_Rte_Prm_GateDrv0CtrlUnit0Cfg7WrVal_Val(void);

/** Per Instance Memories */
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaOnTiSumAPrev(void);
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaOnTiSumBPrev(void);
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaOnTiSumCPrev(void);
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0SpiTrsmErrCntr(void);
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumAExp(void);
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumBExp(void);
uint32 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0PhaOnTiSumCExp(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0Diag0Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0Diag1Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0Diag2Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0StsVal(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0VrfyRes0Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0VrfyRes1Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0Diag0Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0Diag1Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0Diag2Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0StsVal(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0VrfyRes0Val(void);
uint16 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0VrfyRes1Val(void);
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0CfgCnt(void);
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0OffStChkIdx(void);
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0OffStCnt(void);
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0St(void);
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0BootstrpSplyFltPrmVal(void);
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0GenericFltPrmVal(void);
IvtrFetFltPha1 *TSC_GateDrv0Ctrl_Rte_Pim_IvtrFetFltPhaDataStore(void);
IvtrFetFltTyp1 *TSC_GateDrv0Ctrl_Rte_Pim_IvtrFetFltTypDataStore(void);
uint8 *TSC_GateDrv0Ctrl_Rte_Pim_dGateDrv0CtrlGateDrv0OffsStVrfyPrmBitIdx(void);
boolean *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0CfgSecAtmpt(void);
boolean *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0OffStChkSecAtmpt(void);
boolean *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0SpiErrSecAtmpt(void);
boolean *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0InactvSts(void);
boolean *TSC_GateDrv0Ctrl_Rte_Pim_Ivtr0OffStChkCmpl(void);
FilLpRec1 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaAFilLp(void);
FilLpRec1 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaBFilLp(void);
FilLpRec1 *TSC_GateDrv0Ctrl_Rte_Pim_GateDrv0PhaCFilLp(void);



