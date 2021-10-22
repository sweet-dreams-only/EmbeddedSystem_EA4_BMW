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
 *          File:  TSC_TqOscn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_TqOscn.h"
#include "TSC_TqOscn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnEna_Logl(boolean *data)
{
  return Rte_Read_HwOscnEna_Logl(data);
}

Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnFallRampRate_Val(float32 *data)
{
  return Rte_Read_HwOscnFallRampRate_Val(data);
}

Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnFrq_Val(float32 *data)
{
  return Rte_Read_HwOscnFrq_Val(data);
}

Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnMotAmp_Val(float32 *data)
{
  return Rte_Read_HwOscnMotAmp_Val(data);
}

Std_ReturnType TSC_TqOscn_Rte_Read_HwOscnRisngRampRate_Val(float32 *data)
{
  return Rte_Read_HwOscnRisngRampRate_Val(data);
}




Std_ReturnType TSC_TqOscn_Rte_Write_HwOscnActv_Logl(boolean data)
{
  return Rte_Write_HwOscnActv_Logl(data);
}

Std_ReturnType TSC_TqOscn_Rte_Write_HwOscnCmd_Val(float32 data)
{
  return Rte_Write_HwOscnCmd_Val(data);
}

Std_ReturnType TSC_TqOscn_Rte_Write_HwOscnDcThdExcdd_Logl(boolean data)
{
  return Rte_Write_HwOscnDcThdExcdd_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_TqOscn_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_f32_Oper(SigPah_Arg, LocnKey_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_TqOscn_Rte_Prm_TqOscnFallRampRateCal_Val(void)
{
  return (float32 ) Rte_Prm_TqOscnFallRampRateCal_Val();
}
float32  TSC_TqOscn_Rte_Prm_TqOscnRisngRampRateCal_Val(void)
{
  return (float32 ) Rte_Prm_TqOscnRisngRampRateCal_Val();
}
boolean  TSC_TqOscn_Rte_Prm_TqOscnUseRampRateCal_Logl(void)
{
  return (boolean ) Rte_Prm_TqOscnUseRampRateCal_Logl();
}
Ary1D_u5p11_11 * TSC_TqOscn_Rte_Prm_TqOscnAmpLimY_Ary1D(void)
{
  return (Ary1D_u5p11_11 *) Rte_Prm_TqOscnAmpLimY_Ary1D();
}
Ary1D_u8p8_11 * TSC_TqOscn_Rte_Prm_TqOscnFrqIn_Ary1D(void)
{
  return (Ary1D_u8p8_11 *) Rte_Prm_TqOscnFrqIn_Ary1D();
}


     /* TqOscn */
      /* TqOscn */

/** Per Instance Memories */
float32 *TSC_TqOscn_Rte_Pim_AmpRampSt(void)
{
  return Rte_Pim_AmpRampSt();
}
float32 *TSC_TqOscn_Rte_Pim_PrevFallRampRate(void)
{
  return Rte_Pim_PrevFallRampRate();
}
float32 *TSC_TqOscn_Rte_Pim_PrevLimdAmp(void)
{
  return Rte_Pim_PrevLimdAmp();
}
float32 *TSC_TqOscn_Rte_Pim_PrevPhaAg(void)
{
  return Rte_Pim_PrevPhaAg();
}
float32 *TSC_TqOscn_Rte_Pim_PrevPhaAgInc(void)
{
  return Rte_Pim_PrevPhaAgInc();
}
float32 *TSC_TqOscn_Rte_Pim_PrevRisngRampRate(void)
{
  return Rte_Pim_PrevRisngRampRate();
}
float32 *TSC_TqOscn_Rte_Pim_dTqOscnPreFinalCmd(void)
{
  return Rte_Pim_dTqOscnPreFinalCmd();
}
float32 *TSC_TqOscn_Rte_Pim_dTqOscnRateLimdAmp(void)
{
  return Rte_Pim_dTqOscnRateLimdAmp();
}
float32 *TSC_TqOscn_Rte_Pim_dTqOscnSinCmd(void)
{
  return Rte_Pim_dTqOscnSinCmd();
}
boolean *TSC_TqOscn_Rte_Pim_PrevActv(void)
{
  return Rte_Pim_PrevActv();
}
boolean *TSC_TqOscn_Rte_Pim_PrevDcThdExcdd(void)
{
  return Rte_Pim_PrevDcThdExcdd();
}
boolean *TSC_TqOscn_Rte_Pim_PrevEna(void)
{
  return Rte_Pim_PrevEna();
}
boolean *TSC_TqOscn_Rte_Pim_dTqOscnNonZeroAmpFlg(void)
{
  return Rte_Pim_dTqOscnNonZeroAmpFlg();
}
FilLpRec1 *TSC_TqOscn_Rte_Pim_PreFinalCmdLpFil(void)
{
  return Rte_Pim_PreFinalCmdLpFil();
}



