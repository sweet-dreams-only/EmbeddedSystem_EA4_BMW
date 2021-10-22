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
 *          File:  TSC_EcuTMeas.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_EcuTMeas.h"
#include "TSC_EcuTMeas.h"








Std_ReturnType TSC_EcuTMeas_Rte_Read_EcuT_Val(float32 *data)
{
  return Rte_Read_EcuT_Val(data);
}




Std_ReturnType TSC_EcuTMeas_Rte_Write_EcuTFild_Val(float32 data)
{
  return Rte_Write_EcuTFild_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_EcuTMeas_Rte_Read_EcuTAdcFaild_Logl(boolean *data)
{
  return Rte_Read_EcuTAdcFaild_Logl(data);
}




Std_ReturnType TSC_EcuTMeas_Rte_Write_DiagcStsLimdTPrfmnc_Logl(boolean data)
{
  return Rte_Write_DiagcStsLimdTPrfmnc_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_EcuTMeas_Rte_Call_CnvSnpshtData_f32_Oper(uint32 *SnpshtDataCnvd_Arg, float32 SnpshtData_Arg)
{
  return Rte_Call_CnvSnpshtData_f32_Oper(SnpshtDataCnvd_Arg, SnpshtData_Arg);
}
Std_ReturnType TSC_EcuTMeas_Rte_Call_CnvSnpshtData_logl_Oper(uint32 *SnpshtDataCnvd_Arg, boolean SnpshtData_Arg)
{
  return Rte_Call_CnvSnpshtData_logl_Oper(SnpshtDataCnvd_Arg, SnpshtData_Arg);
}
Std_ReturnType TSC_EcuTMeas_Rte_Call_GetNtcActv_Oper(NtcNr1 NtcNr, boolean *NtcActv)
{
  return Rte_Call_GetNtcActv_Oper(NtcNr, NtcActv);
}
Std_ReturnType TSC_EcuTMeas_Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
{
  return Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg, SpclSnpshtData0_Arg, SpclSnpshtData1_Arg, SpclSnpshtData2_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* EcuTMeas */
      /* EcuTMeas */

/** Per Instance Memories */
float32 *TSC_EcuTMeas_Rte_Pim_dEcuTMeasEcuTCalcd(void)
{
  return Rte_Pim_dEcuTMeasEcuTCalcd();
}
FilLpRec1 *TSC_EcuTMeas_Rte_Pim_EcuTFilStVari(void)
{
  return Rte_Pim_EcuTFilStVari();
}



