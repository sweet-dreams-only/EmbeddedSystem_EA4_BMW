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
 *          File:  TSC_SteerCmdArbnAndLim.h
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
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_AssiLnrGain_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_AssiLnrGainEna_Logl(boolean *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_EotCtrlSca_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_FalbckAssiMotTqCmd_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_LimdMotTqCmd_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_MotTqCmd_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_MotTqCmdLimDi_Logl(boolean *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_StallMotTqLim_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_SysMotTqCmdSca_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_ThermMotTqLim_Val(float32 *data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_VehSpdMotTqLim_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Write_ArbdMotTqCmd_Val(float32 data);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Write_MotTqCmdLimdPreStall_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Explicit inter-runnable variables */
void TSC_SteerCmdArbnAndLim_Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd(float32);
void TSC_SteerCmdArbnAndLim_Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna(boolean);
float32 TSC_SteerCmdArbnAndLim_Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd(void);
boolean TSC_SteerCmdArbnAndLim_Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna(void);

/** Calibration Component Calibration Parameters */
uint16  TSC_SteerCmdArbnAndLim_Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val(void);
uint16  TSC_SteerCmdArbnAndLim_Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val(void);

/** Per Instance Memories */
float32 *TSC_SteerCmdArbnAndLim_Rte_Pim_SteerCmdArbnAndLimDebStFalbck(void);
uint32 *TSC_SteerCmdArbnAndLim_Rte_Pim_SteerCmdArbnAndLimDebStFw(void);
uint8 *TSC_SteerCmdArbnAndLim_Rte_Pim_SteerCmdArbnAndLimSt(void);
boolean *TSC_SteerCmdArbnAndLim_Rte_Pim_FalbckDebStVari(void);
boolean *TSC_SteerCmdArbnAndLim_Rte_Pim_FwDebStVari(void);



