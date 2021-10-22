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
 *          File:  TSC_ElecPwrCns.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_ElecPwrCns.h"
#include "TSC_ElecPwrCns.h"








Std_ReturnType TSC_ElecPwrCns_Rte_Read_BrdgVltg_Val(float32 *data)
{
  return Rte_Read_BrdgVltg_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
{
  return Rte_Read_MotAndThermProtnLoaMod_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Read_MotCurrDax_Val(float32 *data)
{
  return Rte_Read_MotCurrDax_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Read_MotCurrDaxCmd_Val(float32 *data)
{
  return Rte_Read_MotCurrDaxCmd_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Read_MotCurrQax_Val(float32 *data)
{
  return Rte_Read_MotCurrQax_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Read_MotCurrQaxCmd_Val(float32 *data)
{
  return Rte_Read_MotCurrQaxCmd_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Read_MotVltgDax_Val(float32 *data)
{
  return Rte_Read_MotVltgDax_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Read_MotVltgQax_Val(float32 *data)
{
  return Rte_Read_MotVltgQax_Val(data);
}




Std_ReturnType TSC_ElecPwrCns_Rte_Write_ElecInpPwrEstim_Val(float32 data)
{
  return Rte_Write_ElecInpPwrEstim_Val(data);
}

Std_ReturnType TSC_ElecPwrCns_Rte_Write_SplyCurrEstim_Val(float32 data)
{
  return Rte_Write_SplyCurrEstim_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_ElecPwrCns_Rte_Prm_ElecPwrCnsCtrlrInpR_Val(void)
{
  return (float32 ) Rte_Prm_ElecPwrCnsCtrlrInpR_Val();
}
float32  TSC_ElecPwrCns_Rte_Prm_ElecPwrCnsPrstcPwrLoss_Val(void)
{
  return (float32 ) Rte_Prm_ElecPwrCnsPrstcPwrLoss_Val();
}


     /* ElecPwrCns */
      /* ElecPwrCns */

/** Per Instance Memories */
float32 *TSC_ElecPwrCns_Rte_Pim_dElecPwrCnsDrpInpPwr(void)
{
  return Rte_Pim_dElecPwrCnsDrpInpPwr();
}
float32 *TSC_ElecPwrCns_Rte_Pim_dElecPwrCnsModInpPwr(void)
{
  return Rte_Pim_dElecPwrCnsModInpPwr();
}
float32 *TSC_ElecPwrCns_Rte_Pim_dElecPwrCnsMotCurrDaxEstim(void)
{
  return Rte_Pim_dElecPwrCnsMotCurrDaxEstim();
}
float32 *TSC_ElecPwrCns_Rte_Pim_dElecPwrCnsMotCurrQaxEstim(void)
{
  return Rte_Pim_dElecPwrCnsMotCurrQaxEstim();
}



