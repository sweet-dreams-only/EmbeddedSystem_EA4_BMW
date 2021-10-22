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
 *          File:  TSC_CDD_MotVel.h
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
Std_ReturnType TSC_CDD_MotVel_Rte_Read_AssiMechPolarity_Val(sint8 *data);
Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgBuf_Ary1D(u0p16 *data);
Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgBufIdx_Val(uint8 *data);
Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgMeclIdptSig_Val(uint8 *data);
Std_ReturnType TSC_CDD_MotVel_Rte_Read_MotAgTiBuf_Ary1D(uint32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CDD_MotVel_Rte_Write_MotVelCrf_Val(float32 data);
Std_ReturnType TSC_CDD_MotVel_Rte_Write_MotVelMrf_Val(float32 data);
Std_ReturnType TSC_CDD_MotVel_Rte_Write_MotVelVld_Logl(boolean data);

/** Per Instance Memories */
float32 *TSC_CDD_MotVel_Rte_Pim_dMotVelAvrgTi(void);
float32 *TSC_CDD_MotVel_Rte_Pim_dMotVelTiStampRef(void);
u0p16 *TSC_CDD_MotVel_Rte_Pim_dMotVelMotAgRef(void);
uint8 *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrev(void);
uint8 *TSC_CDD_MotVel_Rte_Pim_MotAgBufIdxPrim(void);
uint8 *TSC_CDD_MotVel_Rte_Pim_MotVelIninCntr(void);
u0p16 *TSC_CDD_MotVel_Rte_Pim_MotAgBufPrev(void);
uint32 *TSC_CDD_MotVel_Rte_Pim_MotAgTiBufPrev(void);



