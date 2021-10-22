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
 *          File:  TSC_MotTqTranlDampg.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotTqTranlDampg.h"
#include "TSC_MotTqTranlDampg.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_MotTqTranlDampg_Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaX(u16p0 *data)
{
  Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaX( data);
}
void TSC_MotTqTranlDampg_Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaY(u2p14 *data)
{
  Rte_IrvWrite_MotTqTranlDampgInit1_CtrldDampgScaY( data);
}





Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_AssiMechPolarity_Val(sint8 *data)
{
  return Rte_Read_AssiMechPolarity_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data)
{
  return Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_LoaSt_Val(LoaSt1 *data)
{
  return Rte_Read_LoaSt_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_MotTqCmdCrf_Val(float32 *data)
{
  return Rte_Read_MotTqCmdCrf_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_MotTqTranlDampg_Rte_Write_MotTqCmdCrfDampd_Val(float32 data)
{
  return Rte_Write_MotTqCmdCrfDampd_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Write_MotTqCmdMrfDampd_Val(float32 data)
{
  return Rte_Write_MotTqCmdMrfDampd_Val(data);
}

Std_ReturnType TSC_MotTqTranlDampg_Rte_Write_MotTqTranlDampgCmpl_Logl(boolean data)
{
  return Rte_Write_MotTqTranlDampgCmpl_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_MotTqTranlDampg_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_MotTqTranlDampg_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
void TSC_MotTqTranlDampg_Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaX(u16p0 *data)
{
Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaX( data);
}
void TSC_MotTqTranlDampg_Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaY(u2p14 *data)
{
Rte_IrvRead_MotTqTranlDampgPer1_CtrldDampgScaY( data);
}





float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgCmdLim_Val(void)
{
  return (float32 ) Rte_Prm_MotTqTranlDampgCmdLim_Val();
}
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgDampgCoeff_Val(void)
{
  return (float32 ) Rte_Prm_MotTqTranlDampgDampgCoeff_Val();
}
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt1_Val(void)
{
  return (float32 ) Rte_Prm_MotTqTranlDampgTmrPt1_Val();
}
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgTmrPt2_Val(void)
{
  return (float32 ) Rte_Prm_MotTqTranlDampgTmrPt2_Val();
}
float32  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVelThd_Val(void)
{
  return (float32 ) Rte_Prm_MotTqTranlDampgVelThd_Val();
}
u2p14  TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgRampEnd_Val(void)
{
  return (u2p14 ) Rte_Prm_MotTqTranlDampgRampEnd_Val();
}
Ary1D_u9p7_4 * TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndX_Ary1D(void)
{
  return (Ary1D_u9p7_4 *) Rte_Prm_MotTqTranlDampgVehSpdBlndX_Ary1D();
}
Ary1D_u2p14_4 * TSC_MotTqTranlDampg_Rte_Prm_MotTqTranlDampgVehSpdBlndY_Ary1D(void)
{
  return (Ary1D_u2p14_4 *) Rte_Prm_MotTqTranlDampgVehSpdBlndY_Ary1D();
}


     /* MotTqTranlDampg */
      /* MotTqTranlDampg */

/** Per Instance Memories */
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgCmdCtrld(void)
{
  return Rte_Pim_dMotTqTranlDampgCmdCtrld();
}
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgSignPhaSca(void)
{
  return Rte_Pim_dMotTqTranlDampgSignPhaSca();
}
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTiElpd(void)
{
  return Rte_Pim_dMotTqTranlDampgTiElpd();
}
float32 *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgVelDampgCmd(void)
{
  return Rte_Pim_dMotTqTranlDampgVelDampgCmd();
}
uint32 *TSC_MotTqTranlDampg_Rte_Pim_TmrRefTi(void)
{
  return Rte_Pim_TmrRefTi();
}
LoaSt1 *TSC_MotTqTranlDampg_Rte_Pim_LoaStPrev(void)
{
  return Rte_Pim_LoaStPrev();
}
boolean *TSC_MotTqTranlDampg_Rte_Pim_DiagStsPrev(void)
{
  return Rte_Pim_DiagStsPrev();
}
boolean *TSC_MotTqTranlDampg_Rte_Pim_StLtchPrev(void)
{
  return Rte_Pim_StLtchPrev();
}
boolean *TSC_MotTqTranlDampg_Rte_Pim_dMotTqTranlDampgTmrEna(void)
{
  return Rte_Pim_dMotTqTranlDampgTmrEna();
}



