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
 *          File:  TSC_BmwHwAgArbnAndEotPosn.h
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
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwHwAgOffs_Val(float32 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwPinionAgOffs_Val(float32 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadOffsSts_Val(BmwQuadOffsSts1 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadOffsStsVld_Logl(boolean *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadRotorOffs_Val(sint8 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadRotorOffsVld_Logl(boolean *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_CmplncErrMotToPinion_Val(float32 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_DiKineIntegrityTest_Logl(boolean *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgMeclCorrlnSt_Val(uint8 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgTurnCntr_Val(float32 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_RackCentrPinionAg_Val(float32 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_TotRackTrvl_Val(float32 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_TurnCntrCorrlnSts_Val(uint8 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Read_VehSpdVld_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_AlgndPinionAg_Val(float32 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwPinionAg_Val(float32 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwRackCentrToVehCentrOffs_Val(float32 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(boolean data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgCcwDetd_Logl(boolean data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgCwDetd_Logl(boolean data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgEotCcw_Val(float32 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgEotCw_Val(float32 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_LongTermVehCentrCmpl_Logl(boolean data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_OffsCmpdPinionAg_Val(float32 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_PinionAg_Val(float32 data);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Write_PinionAgConf_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_RstRackCentrMotRev_Oper(void);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_BmwVehCentrOffs_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_BmwHwAgArbnAndEotPosn_Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val(void);
float32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_SysGlbPrmSysKineRat_Val(void);
uint32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val(void);
uint32  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val(void);
uint16  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val(void);
uint16  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val(void);
uint16  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val(void);
boolean  TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl(void);

/** Per Instance Memories */
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim(void);
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg(void);
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari(void);
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy(void);
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg(void);
float32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf(void);
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi(void);
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi(void);
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi(void);
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi(void);
uint32 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi(void);
BmwRackToVehCentrOffsSts1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts(void);
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr(void);
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts(void);
BmwMotAgSelnSt1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt(void);
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt(void);
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts(void);
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts(void);
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts(void);
BmwMotAgSelnSt1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt(void);
BmwQuadOffsSts1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts(void);
uint8 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig(void);
boolean *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl(void);
BmwVehCentrOffsRec1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs(void);
FilLpRec1 *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari(void);



