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
 *          File:  TSC_ProgMfgSrv.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_ProgMfgSrv.h"
#include "TSC_ProgMfgSrv.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_MotVrntRead_Oper(uint8 *BmwDesIninOptSetAIdx_Arg)
{
  return Rte_Call_MotVrntRead_Oper(BmwDesIninOptSetAIdx_Arg);
}
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_MotVrntWr_Oper(uint8 BmwDesIninOptSetAIdx_Arg)
{
  return Rte_Call_MotVrntWr_Oper(BmwDesIninOptSetAIdx_Arg);
}
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_TunVrntRead_Oper(uint8 *BmwDesIninIdx_Arg)
{
  return Rte_Call_TunVrntRead_Oper(BmwDesIninIdx_Arg);
}
Std_ReturnType TSC_ProgMfgSrv_Rte_Call_TunVrntWr_Oper(uint8 BmwDesIninIdx_Arg)
{
  return Rte_Call_TunVrntWr_Oper(BmwDesIninIdx_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* ProgMfgSrv */
      /* ProgMfgSrv */



