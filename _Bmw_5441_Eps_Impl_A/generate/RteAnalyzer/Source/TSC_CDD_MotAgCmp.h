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
 *          File:  TSC_CDD_MotAgCmp.h
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
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Read_AssiMechPolarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Read_MotAgCumvAlgndMrfRev_Val(s15p16 *data);
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Read_MotAgCumvInid_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndCrf_Val(s18p13 data);
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndMrf_Val(s18p13 data);
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Write_MotAgCumvAlgndVld_Logl(boolean data);

/** Service interfaces */
Std_ReturnType TSC_CDD_MotAgCmp_Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmSysKineRat_Val(void);
uint8  TSC_CDD_MotAgCmp_Rte_Prm_SysGlbPrmMotPoleCnt_Val(void);

/** SW-C local Calibration Parameters */
u0p16  TSC_CDD_MotAgCmp_Rte_CData_MotAgCmpMotAgBackEmfDft(void);

/** Per Instance Memories */
float32 *TSC_CDD_MotAgCmp_Rte_Pim_DigMotHwPosn(void);
s15p16 *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevPrev(void);
s15p16 *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev(void);
u0p16 *TSC_CDD_MotAgCmp_Rte_Pim_MotAgCmpMotAgBackEmf(void);
uint8 *TSC_CDD_MotAgCmp_Rte_Pim_CmpEnaCntr(void);



