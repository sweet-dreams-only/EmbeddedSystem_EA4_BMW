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
 *          File:  TSC_MotCurrPeakEstimn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotCurrPeakEstimn.h"
#include "TSC_MotCurrPeakEstimn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_DualEcuMotCtrlMtgtnEna_Logl(boolean *data)
{
  return Rte_Read_DualEcuMotCtrlMtgtnEna_Logl(data);
}

Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
{
  return Rte_Read_MotAndThermProtnLoaMod_Val(data);
}

Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrDax_Val(float32 *data)
{
  return Rte_Read_MotCurrDax_Val(data);
}

Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrDaxCmd_Val(float32 *data)
{
  return Rte_Read_MotCurrDaxCmd_Val(data);
}

Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrQax_Val(float32 *data)
{
  return Rte_Read_MotCurrQax_Val(data);
}

Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Read_MotCurrQaxCmd_Val(float32 *data)
{
  return Rte_Read_MotCurrQaxCmd_Val(data);
}




Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Write_MotCurrPeakEstimd_Val(float32 data)
{
  return Rte_Write_MotCurrPeakEstimd_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_MotCurrPeakEstimn_Rte_IrvWrite_MotCurrPeakEstimnPer1_MotCurrEstimd(float32 data)
{
  Rte_IrvWrite_MotCurrPeakEstimnPer1_MotCurrEstimd( data);
}








Std_ReturnType TSC_MotCurrPeakEstimn_Rte_Write_MotCurrPeakEstimdFild_Val(float32 data)
{
  return Rte_Write_MotCurrPeakEstimdFild_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_MotCurrPeakEstimn_Rte_IrvRead_MotCurrPeakEstimnPer2_MotCurrEstimd(void)
{
return Rte_IrvRead_MotCurrPeakEstimnPer2_MotCurrEstimd();
}





float32  TSC_MotCurrPeakEstimn_Rte_Prm_MotCurrPeakEstimnCurrFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_MotCurrPeakEstimnCurrFilFrq_Val();
}
float32  TSC_MotCurrPeakEstimn_Rte_Prm_MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val();
}


     /* MotCurrPeakEstimn */
      /* MotCurrPeakEstimn */

/** Per Instance Memories */
float32 *TSC_MotCurrPeakEstimn_Rte_Pim_dMotCurrPeakEstimnMotCurrDaxFil(void)
{
  return Rte_Pim_dMotCurrPeakEstimnMotCurrDaxFil();
}
float32 *TSC_MotCurrPeakEstimn_Rte_Pim_dMotCurrPeakEstimnMotCurrQaxFil(void)
{
  return Rte_Pim_dMotCurrPeakEstimnMotCurrQaxFil();
}
FilLpRec1 *TSC_MotCurrPeakEstimn_Rte_Pim_MotCurrDaxFil(void)
{
  return Rte_Pim_MotCurrDaxFil();
}
FilLpRec1 *TSC_MotCurrPeakEstimn_Rte_Pim_MotCurrPeakEstimdFil(void)
{
  return Rte_Pim_MotCurrPeakEstimdFil();
}
FilLpRec1 *TSC_MotCurrPeakEstimn_Rte_Pim_MotCurrQaxFil(void)
{
  return Rte_Pim_MotCurrQaxFil();
}



