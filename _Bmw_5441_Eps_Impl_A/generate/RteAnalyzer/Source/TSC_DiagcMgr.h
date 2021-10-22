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
 *          File:  TSC_DiagcMgr.h
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
Std_ReturnType TSC_DiagcMgr_Rte_Read_SwApplCrc_Val(uint32 *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_BrdgVltg_Val(float32 *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_EcuTFild_Val(float32 *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_IgnCntr_Val(uint32 *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_MfgDiagcInhb_Logl(boolean *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_MotTqCmdMrfScad_Val(float32 *data);
Std_ReturnType TSC_DiagcMgr_Rte_Read_SysSt_Val(SysSt1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_DiagcMgr_Rte_Write_ClrDiagcFlgProxy_Val(uint8 data);
Std_ReturnType TSC_DiagcMgr_Rte_Write_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean data);
Std_ReturnType TSC_DiagcMgr_Rte_Write_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean data);
Std_ReturnType TSC_DiagcMgr_Rte_Write_SysDiMotTqCmdSca_Val(float32 data);
Std_ReturnType TSC_DiagcMgr_Rte_Write_SysDiRampRate_Val(float32 data);
Std_ReturnType TSC_DiagcMgr_Rte_Write_SysStFltOutpReqDi_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_DiagcMgr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl0_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl1_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl10_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl2_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl3_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl4_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl5_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl6_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl7_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl8_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl9_Oper(DiagcDataRec2 *DiagcData_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl0_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl1_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl10_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl2_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl3_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl4_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl5_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl6_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl8_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl0_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl1_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl10_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl2_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl3_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl4_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl5_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl6_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl8_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl0_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl1_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl10_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl2_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl3_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl4_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl5_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl6_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl8_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl0_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl1_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl10_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl2_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl3_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl4_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl5_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl6_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl8_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl0_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl1_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl10_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl2_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl3_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl4_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl5_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl6_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl8_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl0_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl1_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl10_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl2_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl3_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl4_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl5_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl6_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl7_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl8_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl9_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl0_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl1_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl10_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl2_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl3_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl4_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl5_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl6_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl8_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetMcuDiagcSpplData_Oper(uint32 *McuDiagcData1_Arg);

/** Service interfaces */
Std_ReturnType TSC_DiagcMgr_Rte_Call_DiagcMgrLtchCntrAry_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_SnpshtDataAry_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_DiagcMgrApplCrc_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_DiagcMgr_Rte_Call_SnpshtDataAry_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
Ary1D_u16_512 * TSC_DiagcMgr_Rte_Prm_DiagcMgrFltResp_Ary1D(void);

/** SW-C local Calibration Parameters */
uint32  TSC_DiagcMgr_Rte_CData_DiagcMgrApplCrcDft(void);

/** Exclusive Areas */
void TSC_DiagcMgr_Rte_Enter_DiagcMgrExclusiveArea(void);
void TSC_DiagcMgr_Rte_Exit_DiagcMgrExclusiveArea(void);

/** Per Instance Memories */
uint32 *TSC_DiagcMgr_Rte_Pim_DiagcMgrApplCrc(void);
uint16 *TSC_DiagcMgr_Rte_Pim_DtcEnaSts(void);
uint8 *TSC_DiagcMgr_Rte_Pim_ClrDiagcFlg(void);
uint8 *TSC_DiagcMgr_Rte_Pim_PrevClrDtcFlg(void);
uint8 *TSC_DiagcMgr_Rte_Pim_DiagcMgrLtchCntrAry(void);
NtcFltInfoRec2 *TSC_DiagcMgr_Rte_Pim_DiagcMgrNtcFltAry(void);
uint8 *TSC_DiagcMgr_Rte_Pim_DtcIdxPrevSts(void);



