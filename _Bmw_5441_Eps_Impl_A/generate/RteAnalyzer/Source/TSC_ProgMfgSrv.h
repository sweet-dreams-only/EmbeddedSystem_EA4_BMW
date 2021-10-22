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
 *          File:  TSC_ProgMfgSrv.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Client server interfaces */
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_MotVrntRead_Oper(uint8 *BmwDesIninOptSetAIdx_Arg);
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg);
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_TunVrntRead_Oper(uint8 *BmwDesIninIdx_Arg);
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg);




