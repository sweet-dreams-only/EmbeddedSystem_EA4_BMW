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
 *          File:  TSC_HiLoadStallLimr.h
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
Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data);
Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data);
Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_MotTqCmdLimdPreStall_Val(float32 *data);
Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_MotVelCrf_Val(float32 *data);
Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_StallMotTqLimDi_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_HiLoadStallLimr_Rte_Write_StallMotTqLim_Val(float32 data);

/** Calibration Component Calibration Parameters */
float32  TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val(void);
float32  TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFilFrq_Val(void);
float32  TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallThermLimSca_Val(void);
Ary1D_f32_2 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(void);
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(void);
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(void);
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(void);
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(void);
Ary1D_f32_2 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimFetMtgtnPrev(void);
float32 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimPrev(void);
float32 *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmd(void);
float32 *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild(void);
float32 *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqLim(void);
uint8 *TSC_HiLoadStallLimr_Rte_Pim_FetLoaMtgtnCalIdx(void);
FilLpRec1 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFetMtgtnFil(void);
FilLpRec1 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFil(void);



