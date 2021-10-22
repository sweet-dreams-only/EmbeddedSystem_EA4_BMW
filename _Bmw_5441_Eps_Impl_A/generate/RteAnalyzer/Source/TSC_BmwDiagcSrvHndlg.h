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
 *          File:  TSC_BmwDiagcSrvHndlg.h
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
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDst_Val(uint32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDstVld_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_EcuTFild_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BrdgVltg_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAgConf_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermVehCentrCmpl_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAg_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_TurnCntrCorrlnSts_Val(uint8 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwRackCentrToVehCentrOffs_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAg_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDst_Val(uint32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_MotTqCmdMrfScad_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAgConf_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgErrPrsnt_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_TotRackTrvl_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrCmpl_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgErrPrsnt_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgVld_Logl(boolean *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwTqIdptSig_Val(uint8 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDst_Val(uint32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwVel_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAg_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionCentrLrnHwTrvl_Val(float32 *data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionCentrLrnSt_Val(uint8 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Write_LockToLockEna_Logl(boolean data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Write_LockToLockEna_Logl(boolean data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Write_BmwHwAgOffs_Val(float32 data);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Write_LockToLockEna_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_SetVehCentrPosn_Oper(BmwSetVehCentrOffsSts1 *BmwSetVehCentrOffsSts_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetNtcActv_Oper(NtcNr1 NtcNr, boolean *NtcActv);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ClrVehCentrPosn_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotRev_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotAg_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotRev_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ClrVehCentrPosn_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotRev_Oper(void);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Service interfaces */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ProgCntrMaxVal_SetRamBlockStatus(boolean RamBlockStatus);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_TestStamp_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_TestStamp_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ProgCntr_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_MilesKmEeprom_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** SW-C local Calibration Parameters */
uint16  TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue(void);
uint16  TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft(void);

/** Per Instance Memories */
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl(void);
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt(void);
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA(void);
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel(void);
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi(void);
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi(void);
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi(void);
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi(void);
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom(void);
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi(void);
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom(void);
uint16 *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid(void);
uint16 *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr(void);
uint16 *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal(void);
uint8 *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts(void);
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort(void);
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt(void);
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes(void);
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk(void);
uint8 *TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(void);



