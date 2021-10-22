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
 *          File:  TSC_BmwMotTqOvrlArbn.h
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
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_BmwOutpTqOvrlCmd_Val(float32 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_DrvgDynActv_Logl(boolean *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnActv_Logl(boolean *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnCmd_Val(float32 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PinionCentrLrnCmd_Val(float32 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PinionCentrLrnEna_Logl(boolean *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PosnServoCmd_Val(float32 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PosnServoEna_Logl(boolean *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PullCmpCmd_Val(float32 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_TrfcJamAssiCmd_Val(float32 *data);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_VehSpd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Write_MotTqOvrlCmd_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val(void);
float32  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val(void);
float32  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val(void);
uint16  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val(void);
uint16  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val(void);
uint16  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val(void);

/** Per Instance Memories */
uint32 *TSC_BmwMotTqOvrlArbn_Rte_Pim_BmwNearStillVehSpdStsCdnRefTi(void);
uint32 *TSC_BmwMotTqOvrlArbn_Rte_Pim_MfgModCmdCdnRefTi(void);
uint32 *TSC_BmwMotTqOvrlArbn_Rte_Pim_VehSpdCdnRefTi(void);
boolean *TSC_BmwMotTqOvrlArbn_Rte_Pim_FctlErrStVari(void);



