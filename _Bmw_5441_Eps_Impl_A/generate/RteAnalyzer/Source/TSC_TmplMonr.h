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
 *          File:  TSC_TmplMonr.h
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
Std_ReturnType TSC_TmplMonr_Rte_Read_StrtUpSt_Val(uint8 *data);
Std_ReturnType TSC_TmplMonr_Rte_Read_SysSt_Val(SysSt1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_TmplMonr_Rte_Write_TmplMonrIninTestCmpl_Logl(boolean data);
Std_ReturnType TSC_TmplMonr_Rte_Write_TmplMonrIninTestCmpl_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_TmplMonr_Rte_Call_CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_IoHwAb_GetGpioPwrOutpEnaFb_Oper(boolean *PinSt_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_IoHwAb_SetGpioTmplMonrWdg_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_IoHwAb_SetGpioTmplMonrWdg_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_TmplMonr_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Explicit inter-runnable variables */
void TSC_TmplMonr_Rte_IrvWrite_TmplMonrPer1_ElpdTiMicroSec(uint32);
uint32 TSC_TmplMonr_Rte_IrvRead_TmplMonrPer2_ElpdTiMicroSec(void);

/** Per Instance Memories */
uint32 *TSC_TmplMonr_Rte_Pim_AvrgElpdTiMicroSec(void);
uint16 *TSC_TmplMonr_Rte_Pim_TrsmErrCntr(void);
uint8 *TSC_TmplMonr_Rte_Pim_TmplMonrIninCntr(void);
uint8 *TSC_TmplMonr_Rte_Pim_TmplMonrNtc40PrmByte(void);
uint8 *TSC_TmplMonr_Rte_Pim_TmplMonrWdgRstrtCnt(void);
uint8 *TSC_TmplMonr_Rte_Pim_TrsmErrNtcThd(void);
boolean *TSC_TmplMonr_Rte_Pim_TmplMonrIninTestCmplFlg(void);
boolean *TSC_TmplMonr_Rte_Pim_TmplMonrSpiReadWrOrderFlg1(void);
boolean *TSC_TmplMonr_Rte_Pim_TmplMonrSpiReadWrOrderFlg2(void);



