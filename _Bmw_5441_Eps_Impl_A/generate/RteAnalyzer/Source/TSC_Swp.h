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
 *          File:  TSC_Swp.h
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
Std_ReturnType TSC_Swp_Rte_Read_HwTq_Val(float32 *data);
Std_ReturnType TSC_Swp_Rte_Read_VehSpd_Val(float32 *data);
Std_ReturnType TSC_Swp_Rte_Read_VehSpdVld_Logl(boolean *data);
Std_ReturnType TSC_Swp_Rte_Read_MotTqCmd_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Swp_Rte_Write_HwTqSwp_Val(float32 data);
Std_ReturnType TSC_Swp_Rte_Write_MotTqCmdSwp_Val(float32 data);

/** Client server interfaces */
Std_ReturnType TSC_Swp_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_Swp_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);




