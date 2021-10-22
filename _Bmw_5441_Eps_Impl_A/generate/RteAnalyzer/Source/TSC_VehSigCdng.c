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
 *          File:  TSC_VehSigCdng.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_VehSigCdng.h"
#include "TSC_VehSigCdng.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_VehSigCdng_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLatASerlCom_Val(float32 *data)
{
  return Rte_Read_VehLatASerlCom_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLatAVldSerlCom_Logl(boolean *data)
{
  return Rte_Read_VehLatAVldSerlCom_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLgtASerlCom_Val(float32 *data)
{
  return Rte_Read_VehLgtASerlCom_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehLgtAVldSerlCom_Logl(boolean *data)
{
  return Rte_Read_VehLgtAVldSerlCom_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdOvrd_Val(float32 *data)
{
  return Rte_Read_VehSpdOvrd_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdOvrdEna_Logl(boolean *data)
{
  return Rte_Read_VehSpdOvrdEna_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdSerlCom_Val(float32 *data)
{
  return Rte_Read_VehSpdSerlCom_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehSpdVldSerlCom_Logl(boolean *data)
{
  return Rte_Read_VehSpdVldSerlCom_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehYawRateSerlCom_Val(float32 *data)
{
  return Rte_Read_VehYawRateSerlCom_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Read_VehYawRateVldSerlCom_Logl(boolean *data)
{
  return Rte_Read_VehYawRateVldSerlCom_Logl(data);
}




Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatA_Val(float32 data)
{
  return Rte_Write_VehLatA_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatAEstimd_Val(float32 data)
{
  return Rte_Write_VehLatAEstimd_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatAEstimdVld_Logl(boolean data)
{
  return Rte_Write_VehLatAEstimdVld_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLatAVld_Logl(boolean data)
{
  return Rte_Write_VehLatAVld_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLgtA_Val(float32 data)
{
  return Rte_Write_VehLgtA_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehLgtAVld_Logl(boolean data)
{
  return Rte_Write_VehLgtAVld_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehSpd_Val(float32 data)
{
  return Rte_Write_VehSpd_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehSpdVld_Logl(boolean data)
{
  return Rte_Write_VehSpdVld_Logl(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehYawRate_Val(float32 data)
{
  return Rte_Write_VehYawRate_Val(data);
}

Std_ReturnType TSC_VehSigCdng_Rte_Write_VehYawRateVld_Logl(boolean data)
{
  return Rte_Write_VehYawRateVld_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_VehSigCdng_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_f32_Oper(SigPah_Arg, LocnKey_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLatA_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngDftLatA_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftLgtA_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngDftLgtA_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftVehSpd_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngDftVehSpd_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngDftYawRate_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngDftYawRate_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLatADifThd_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngLatADifThd_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLatAFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngLatAFilFrq_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLatASlewRate_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngLatASlewRate_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgADifThd_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngLtgADifThd_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngLtgASlewRate_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngLtgASlewRate_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdDifThd_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngVehSpdDifThd_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngVehSpdSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngVehSpdSlewRate_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngVehYawSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngVehYawSlewRate_Val();
}
float32  TSC_VehSigCdng_Rte_Prm_VehSigCdngYawRateDifThd_Val(void)
{
  return (float32 ) Rte_Prm_VehSigCdngYawRateDifThd_Val();
}


     /* VehSigCdng */
      /* VehSigCdng */

/** Per Instance Memories */
float32 *TSC_VehSigCdng_Rte_Pim_PrevLatA(void)
{
  return Rte_Pim_PrevLatA();
}
float32 *TSC_VehSigCdng_Rte_Pim_PrevLtgA(void)
{
  return Rte_Pim_PrevLtgA();
}
float32 *TSC_VehSigCdng_Rte_Pim_PrevVehSpd(void)
{
  return Rte_Pim_PrevVehSpd();
}
float32 *TSC_VehSigCdng_Rte_Pim_PrevYawRate(void)
{
  return Rte_Pim_PrevYawRate();
}
boolean *TSC_VehSigCdng_Rte_Pim_PrevLatAVld(void)
{
  return Rte_Pim_PrevLatAVld();
}
boolean *TSC_VehSigCdng_Rte_Pim_PrevLtgAVld(void)
{
  return Rte_Pim_PrevLtgAVld();
}
boolean *TSC_VehSigCdng_Rte_Pim_PrevVehSpdVld(void)
{
  return Rte_Pim_PrevVehSpdVld();
}
boolean *TSC_VehSigCdng_Rte_Pim_PrevYawRateVld(void)
{
  return Rte_Pim_PrevYawRateVld();
}
FilLpRec1 *TSC_VehSigCdng_Rte_Pim_HwTqFilRec(void)
{
  return Rte_Pim_HwTqFilRec();
}
FilLpRec1 *TSC_VehSigCdng_Rte_Pim_LatAFilRec(void)
{
  return Rte_Pim_LatAFilRec();
}



