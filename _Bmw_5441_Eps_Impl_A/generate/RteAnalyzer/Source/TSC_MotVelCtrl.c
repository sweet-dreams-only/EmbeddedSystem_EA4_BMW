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
 *          File:  TSC_MotVelCtrl.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotVelCtrl.h"
#include "TSC_MotVelCtrl.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupGain(void)
{
return Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupLim(void)
{
return Rte_IrvRead_GetCtrlPrm_Oper_AntiWdupLim();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_DerivtvGain(void)
{
return Rte_IrvRead_GetCtrlPrm_Oper_DerivtvGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_DerivtvLpFilTiCon(void)
{
return Rte_IrvRead_GetCtrlPrm_Oper_DerivtvLpFilTiCon();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_IntgtrGain(void)
{
return Rte_IrvRead_GetCtrlPrm_Oper_IntgtrGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_PropGain(void)
{
return Rte_IrvRead_GetCtrlPrm_Oper_PropGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_GetCtrlPrm_Oper_TqCmdLim(void)
{
return Rte_IrvRead_GetCtrlPrm_Oper_TqCmdLim();
}













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_MotVelCtrl_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_MotVelCtrl_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_MotVelCtrl_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}
Std_ReturnType TSC_MotVelCtrl_Rte_Call_SetManTqCmd_Oper(float32 ManTqCmd, boolean ManTqCmdEna)
{
  return Rte_Call_SetManTqCmd_Oper(ManTqCmd, ManTqCmdEna);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_AntiWdupGain(void)
{
return Rte_IrvRead_MotVelCtrlPer1_AntiWdupGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_AntiWdupLim(void)
{
return Rte_IrvRead_MotVelCtrlPer1_AntiWdupLim();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_DerivtvGain(void)
{
return Rte_IrvRead_MotVelCtrlPer1_DerivtvGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_DerivtvLpFilTiCon(void)
{
return Rte_IrvRead_MotVelCtrlPer1_DerivtvLpFilTiCon();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_IntgtrGain(void)
{
return Rte_IrvRead_MotVelCtrlPer1_IntgtrGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_PropGain(void)
{
return Rte_IrvRead_MotVelCtrlPer1_PropGain();
}
float32 TSC_MotVelCtrl_Rte_IrvRead_MotVelCtrlPer1_TqCmdLim(void)
{
return Rte_IrvRead_MotVelCtrlPer1_TqCmdLim();
}













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupGain(float32 data)
{
  Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupGain( data);
}
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupLim(float32 data)
{
  Rte_IrvWrite_SetCtrlPrm_Oper_AntiWdupLim( data);
}
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvGain(float32 data)
{
  Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvGain( data);
}
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvLpFilTiCon(float32 data)
{
  Rte_IrvWrite_SetCtrlPrm_Oper_DerivtvLpFilTiCon( data);
}
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_IntgtrGain(float32 data)
{
  Rte_IrvWrite_SetCtrlPrm_Oper_IntgtrGain( data);
}
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_PropGain(float32 data)
{
  Rte_IrvWrite_SetCtrlPrm_Oper_PropGain( data);
}
void TSC_MotVelCtrl_Rte_IrvWrite_SetCtrlPrm_Oper_TqCmdLim(float32 data)
{
  Rte_IrvWrite_SetCtrlPrm_Oper_TqCmdLim( data);
}












     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* MotVelCtrl */
      /* MotVelCtrl */

/** Per Instance Memories */
float32 *TSC_MotVelCtrl_Rte_Pim_MotVelTar(void)
{
  return Rte_Pim_MotVelTar();
}
float32 *TSC_MotVelCtrl_Rte_Pim_PrevAntiWdupCmd(void)
{
  return Rte_Pim_PrevAntiWdupCmd();
}
float32 *TSC_MotVelCtrl_Rte_Pim_PrevDerivtvOutp(void)
{
  return Rte_Pim_PrevDerivtvOutp();
}
float32 *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrInp(void)
{
  return Rte_Pim_PrevIntgtrInp();
}
float32 *TSC_MotVelCtrl_Rte_Pim_PrevIntgtrOutp(void)
{
  return Rte_Pim_PrevIntgtrOutp();
}
float32 *TSC_MotVelCtrl_Rte_Pim_PrevMotVelErr(void)
{
  return Rte_Pim_PrevMotVelErr();
}
float32 *TSC_MotVelCtrl_Rte_Pim_PrevMotVelTar(void)
{
  return Rte_Pim_PrevMotVelTar();
}
float32 *TSC_MotVelCtrl_Rte_Pim_VelSlewRate(void)
{
  return Rte_Pim_VelSlewRate();
}
uint32 *TSC_MotVelCtrl_Rte_Pim_RefTiRampDwn(void)
{
  return Rte_Pim_RefTiRampDwn();
}
boolean *TSC_MotVelCtrl_Rte_Pim_EnaCtrl(void)
{
  return Rte_Pim_EnaCtrl();
}
boolean *TSC_MotVelCtrl_Rte_Pim_EnaCtrlStVari(void)
{
  return Rte_Pim_EnaCtrlStVari();
}
boolean *TSC_MotVelCtrl_Rte_Pim_FctActvSts(void)
{
  return Rte_Pim_FctActvSts();
}
boolean *TSC_MotVelCtrl_Rte_Pim_RampDwnCmpl(void)
{
  return Rte_Pim_RampDwnCmpl();
}



