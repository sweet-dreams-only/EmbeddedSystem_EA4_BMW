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
 *          File:  TSC_LimrCdng.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_LimrCdng.h"
#include "TSC_LimrCdng.h"








Std_ReturnType TSC_LimrCdng_Rte_Read_EotAssiSca_Val(float32 *data)
{
  return Rte_Read_EotAssiSca_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Read_EotMotTqLim_Val(float32 *data)
{
  return Rte_Read_EotMotTqLim_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Read_StallMotTqLim_Val(float32 *data)
{
  return Rte_Read_StallMotTqLim_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Read_SysMotTqCmdSca_Val(float32 *data)
{
  return Rte_Read_SysMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Read_ThermMotTqLim_Val(float32 *data)
{
  return Rte_Read_ThermMotTqLim_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Read_VehSpdMotTqLim_Val(float32 *data)
{
  return Rte_Read_VehSpdMotTqLim_Val(data);
}




Std_ReturnType TSC_LimrCdng_Rte_Write_EotAssiScaCdnd_Val(float32 data)
{
  return Rte_Write_EotAssiScaCdnd_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Write_EotMotTqLimCdnd_Val(float32 data)
{
  return Rte_Write_EotMotTqLimCdnd_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Write_StallMotTqLimCdnd_Val(float32 data)
{
  return Rte_Write_StallMotTqLimCdnd_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Write_SysMotTqCmdScaCdnd_Val(float32 data)
{
  return Rte_Write_SysMotTqCmdScaCdnd_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Write_ThermMotTqLimCdnd_Val(float32 data)
{
  return Rte_Write_ThermMotTqLimCdnd_Val(data);
}

Std_ReturnType TSC_LimrCdng_Rte_Write_VehSpdMotTqLimCdnd_Val(float32 data)
{
  return Rte_Write_VehSpdMotTqLimCdnd_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_LimrCdng_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_f32_Oper(SigPah_Arg, LocnKey_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_LimrCdng_Rte_Prm_LimrCdngGainDecSlew_Val(void)
{
  return (float32 ) Rte_Prm_LimrCdngGainDecSlew_Val();
}
float32  TSC_LimrCdng_Rte_Prm_LimrCdngTqDecSlew_Val(void)
{
  return (float32 ) Rte_Prm_LimrCdngTqDecSlew_Val();
}
Ary1D_u9p7_2 * TSC_LimrCdng_Rte_Prm_LimrCdngGainIncSlewX_Ary1D(void)
{
  return (Ary1D_u9p7_2 *) Rte_Prm_LimrCdngGainIncSlewX_Ary1D();
}
Ary1D_u9p7_2 * TSC_LimrCdng_Rte_Prm_LimrCdngGainIncSlewY_Ary1D(void)
{
  return (Ary1D_u9p7_2 *) Rte_Prm_LimrCdngGainIncSlewY_Ary1D();
}
Ary1D_u9p7_2 * TSC_LimrCdng_Rte_Prm_LimrCdngTqIncSlewX_Ary1D(void)
{
  return (Ary1D_u9p7_2 *) Rte_Prm_LimrCdngTqIncSlewX_Ary1D();
}
Ary1D_u13p3_2 * TSC_LimrCdng_Rte_Prm_LimrCdngTqIncSlewY_Ary1D(void)
{
  return (Ary1D_u13p3_2 *) Rte_Prm_LimrCdngTqIncSlewY_Ary1D();
}


     /* LimrCdng */
      /* LimrCdng */

/** Per Instance Memories */
float32 *TSC_LimrCdng_Rte_Pim_PrevEotAssiScaCdnd(void)
{
  return Rte_Pim_PrevEotAssiScaCdnd();
}
float32 *TSC_LimrCdng_Rte_Pim_PrevEotMotTqLimCdnd(void)
{
  return Rte_Pim_PrevEotMotTqLimCdnd();
}
float32 *TSC_LimrCdng_Rte_Pim_PrevStallMotTqLimCdnd(void)
{
  return Rte_Pim_PrevStallMotTqLimCdnd();
}
float32 *TSC_LimrCdng_Rte_Pim_PrevSysMotTqCmdScaCdnd(void)
{
  return Rte_Pim_PrevSysMotTqCmdScaCdnd();
}
float32 *TSC_LimrCdng_Rte_Pim_PrevThermMotTqLimCdnd(void)
{
  return Rte_Pim_PrevThermMotTqLimCdnd();
}
float32 *TSC_LimrCdng_Rte_Pim_PrevVehSpdMotTqLimCdnd(void)
{
  return Rte_Pim_PrevVehSpdMotTqLimCdnd();
}



