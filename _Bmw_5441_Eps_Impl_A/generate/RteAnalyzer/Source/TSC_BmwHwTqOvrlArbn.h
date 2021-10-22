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
 *          File:  TSC_BmwHwTqOvrlArbn.h
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
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data);
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_BmwTarHwTqOvrl_Val(float32 *data);
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data);
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data);
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_HwTqOvrlCmdEna_Logl(boolean *data);
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Write_HwTqCmdOvrl_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val(void);
float32  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val(void);
float32  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRampRate_Val(void);
uint16  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val(void);
Ary1D_u4p12_6 * TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(void);
Ary1D_u9p7_6 * TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(void);

/** Per Instance Memories */
float32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_ArbdHwTqOvrlLtch(void);
float32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_HwTqOvrlScaFacStVari(void);
float32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevArbdHwTqOvrl(void);
uint32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrTmr(void);
boolean *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrActv(void);
boolean *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevFctlErr(void);



