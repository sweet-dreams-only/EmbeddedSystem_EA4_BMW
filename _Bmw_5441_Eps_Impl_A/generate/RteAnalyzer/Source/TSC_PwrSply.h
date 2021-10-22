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
 *          File:  TSC_PwrSply.h
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
Std_ReturnType TSC_PwrSply_Rte_Read_SysSt_Val(SysSt1 *data);

/** Client server interfaces */
Std_ReturnType TSC_PwrSply_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07BFailStep_Val(void);
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07BPassStep_Val(void);
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07CFailStep_Val(void);
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07CPassStep_Val(void);
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07DFailStep_Val(void);
uint16  TSC_PwrSply_Rte_Prm_PwrSplyNtc0x07DPassStep_Val(void);

/** Per Instance Memories */
uint16 *TSC_PwrSply_Rte_Pim_SpiTrsmErrCntr(void);
boolean *TSC_PwrSply_Rte_Pim_ReadWrOrderFlg1(void);
boolean *TSC_PwrSply_Rte_Pim_ReadWrOrderFlg2(void);
boolean *TSC_PwrSply_Rte_Pim_StrtUpSelfTestCmpl(void);



