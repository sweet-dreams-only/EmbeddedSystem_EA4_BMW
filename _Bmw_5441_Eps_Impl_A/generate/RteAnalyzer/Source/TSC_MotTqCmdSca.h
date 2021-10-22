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
 *          File:  TSC_MotTqCmdSca.h
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
Std_ReturnType TSC_MotTqCmdSca_Rte_Read_MotTqCmdMrf_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_MotTqCmdSca_Rte_Write_MotTqCmdMrfScad_Val(float32 data);

/** Service interfaces */
Std_ReturnType TSC_MotTqCmdSca_Rte_Call_MotTqScaFac_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_MotTqCmdSca_Rte_Call_MotTqScaFac_SetRamBlockStatus(boolean RamBlockStatus_Arg);
Std_ReturnType TSC_MotTqCmdSca_Rte_Call_MotTqScaFac_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg);
Std_ReturnType TSC_MotTqCmdSca_Rte_Call_MotTqScaFac_SetRamBlockStatus(boolean RamBlockStatus_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_MotTqCmdSca_Rte_Prm_MotTqCmdScaMax_Val(void);
float32  TSC_MotTqCmdSca_Rte_Prm_MotTqCmdScaMin_Val(void);

/** Per Instance Memories */
float32 *TSC_MotTqCmdSca_Rte_Pim_MotTqScaFac(void);



