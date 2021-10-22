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
 *          File:  TSC_MotAgCorrln.h
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
Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgAMecl_Val(u0p16 *data);
Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgAMeclQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgAMeclRollgCntr_Val(uint8 *data);
Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgBMecl_Val(u0p16 *data);
Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgBMeclQlfr_Val(SigQlfr1 *data);
Std_ReturnType TSC_MotAgCorrln_Rte_Read_MotAgBMeclRollgCntr_Val(uint8 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotAgCorrln_Rte_Write_MotAgMeclCorrlnSt_Val(uint8 data);
Std_ReturnType TSC_MotAgCorrln_Rte_Write_MotAgMeclIdptSig_Val(uint8 data);

/** Client server interfaces */
Std_ReturnType TSC_MotAgCorrln_Rte_Call_FltInj_u08_Oper(uint8 *SigPah_Arg, uint16 LocnKey_Arg);
Std_ReturnType TSC_MotAgCorrln_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg);
Std_ReturnType TSC_MotAgCorrln_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg);

/** Calibration Component Calibration Parameters */
uint8  TSC_MotAgCorrln_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void);

/** Per Instance Memories */
u0p16 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnErrThd(void);
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgARollgCntPrev(void);
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgAStallCntPrev(void);
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgBRollgCntPrev(void);
uint8 *TSC_MotAgCorrln_Rte_Pim_MotAgCorrlnMotAgBStallCntPrev(void);
boolean *TSC_MotAgCorrln_Rte_Pim_dMotAgCorrlnMotAgABOk(void);



