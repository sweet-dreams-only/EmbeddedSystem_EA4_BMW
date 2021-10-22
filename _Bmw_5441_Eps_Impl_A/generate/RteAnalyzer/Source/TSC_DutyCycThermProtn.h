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
 *          File:  TSC_DutyCycThermProtn.h
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
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_DutyCycThermProtnDi_Logl(boolean *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_IgnTiOff_Val(uint32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_VehTiVld_Logl(boolean *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_DiagcStsLimdTPrfmnc_Logl(boolean *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_DutyCycThermProtnDi_Logl(boolean *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_EcuTFild_Val(float32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_IgnTiOff_Val(uint32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotCurrPeakEstimd_Val(float32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotCurrPeakEstimdFild_Val(float32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotFetT_Val(float32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotMagT_Val(float32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotWidgT_Val(float32 *data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_VehTiVld_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_DutyCycThermProtnMaxOutp_Val(uint16 data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermDutyCycProtnLoadDptLim_Val(float32 data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermDutyCycProtnTDptLim_Val(float32 data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermLimSlowFilMax_Val(float32 data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermMotTqLim_Val(float32 data);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermRednFac_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_DutyCycThermProtn_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Service interfaces */
Std_ReturnType TSC_DutyCycThermProtn_Rte_Call_FilStVal_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_DutyCycThermProtn_Rte_Call_FilStVal_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Explicit inter-runnable variables */
void TSC_DutyCycThermProtn_Rte_IrvWrite_DutyCycThermProtnInit1_FilStVariReInitFlg(boolean);
boolean TSC_DutyCycThermProtn_Rte_IrvRead_DutyCycThermProtnPer1_FilStVariReInitFlg(void);

/** Calibration Component Calibration Parameters */
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltMotVelBreakPt_Val(void);
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltTTqSlewHiLim_Val(void);
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltTTqSlewLoLim_Val(void);
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnCtrlT_Val(void);
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnIgnOffMsgWaitTi_Val(void);
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnThermLimScaFac_Val(void);
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnTqCmdSlewDwn_Val(void);
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnTqCmdSlewUp_Val(void);
u16p0  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnDutyCycFildThd_Val(void);
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnCtrlTSeln_Logl(void);
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnIgnOffCtrlEna_Logl(void);
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMotPrTSeln_Logl(void);
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplrTSeln_Logl(void);
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnSlowFilTSeln_Logl(void);
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D(void);
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTTblX_Ary1D(void);
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D(void);
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D(void);
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D(void);
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTTblX_Ary1D(void);
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D(void);
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTTqTblY_Ary1D(void);
Ary2D_u9p7_2_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnLstTblValNonStall_Ary2D(void);
Ary2D_u9p7_2_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnLstTblValStall_Ary2D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1NonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1StallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2NonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2StallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3NonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3StallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4NonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4StallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5NonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5StallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6NonStallTblY_Ary1D(void);
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6StallTblY_Ary1D(void);
Ary1D_s15p0_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplrFetMtgtnTblX_Ary1D(void);
Ary1D_s15p0_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplrTblX_Ary1D(void);
Ary2D_u16p0_2_8 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnThermLoadLimTblX_Ary2D(void);
Ary2D_u9p7_2_8 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnThermLoadLimTblY_Ary2D(void);

/** Per Instance Memories */
float32 *TSC_DutyCycThermProtn_Rte_Pim_AbsltTLimSlewStVari(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_LstTblValRateLimrStVari(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_ReInitCntrVal(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnAbsltCtrlrTTqLim(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnAbsltCuTTqLim(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnAbsltTTqLim(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr12T(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr36T(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnThermLoadLim(void);
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnThermLoadLimTblYVal(void);
u9p7 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnLstTblVal(void);
u9p7 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnLstTblValSlew(void);
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr1(void);
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr2(void);
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr3(void);
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr4(void);
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr5(void);
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr6(void);
uint8 *TSC_DutyCycThermProtn_Rte_Pim_FetMtgtnEnaCalIdx(void);
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil3ValPwrUp(void);
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil4ValPwrUp(void);
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil5ValPwrUp(void);
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil6ValPwrUp(void);
boolean *TSC_DutyCycThermProtn_Rte_Pim_FetLoaMtgtnEnaPrev(void);
boolean *TSC_DutyCycThermProtn_Rte_Pim_ReInitCntrFlg(void);
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fil1ValStVari(void);
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fil2ValStVari(void);
DutyCycThermProtnFilStValRec1 *TSC_DutyCycThermProtn_Rte_Pim_FilStVal(void);
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild3Val(void);
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild4Val(void);
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild5Val(void);
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild6Val(void);



