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
 *          File:  TSC_SteerCmdArbnAndLim.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_SteerCmdArbnAndLim.h"
#include "TSC_SteerCmdArbnAndLim.h"








Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_SteerCmdArbnAndLim_Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd(float32 data)
{
  Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd( data);
}
void TSC_SteerCmdArbnAndLim_Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna(boolean data)
{
  Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna( data);
}












     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_AssiLnrGain_Val(float32 *data)
{
  return Rte_Read_AssiLnrGain_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_AssiLnrGainEna_Logl(boolean *data)
{
  return Rte_Read_AssiLnrGainEna_Logl(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_EotCtrlSca_Val(float32 *data)
{
  return Rte_Read_EotCtrlSca_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_FalbckAssiMotTqCmd_Val(float32 *data)
{
  return Rte_Read_FalbckAssiMotTqCmd_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_LimdMotTqCmd_Val(float32 *data)
{
  return Rte_Read_LimdMotTqCmd_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_MotTqCmd_Val(float32 *data)
{
  return Rte_Read_MotTqCmd_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_MotTqCmdLimDi_Logl(boolean *data)
{
  return Rte_Read_MotTqCmdLimDi_Logl(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_StallMotTqLim_Val(float32 *data)
{
  return Rte_Read_StallMotTqLim_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_SysMotTqCmdSca_Val(float32 *data)
{
  return Rte_Read_SysMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_ThermMotTqLim_Val(float32 *data)
{
  return Rte_Read_ThermMotTqLim_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Read_VehSpdMotTqLim_Val(float32 *data)
{
  return Rte_Read_VehSpdMotTqLim_Val(data);
}




Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Write_ArbdMotTqCmd_Val(float32 data)
{
  return Rte_Write_ArbdMotTqCmd_Val(data);
}

Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Write_MotTqCmdLimdPreStall_Val(float32 data)
{
  return Rte_Write_MotTqCmdLimdPreStall_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}
Std_ReturnType TSC_SteerCmdArbnAndLim_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_SteerCmdArbnAndLim_Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd(void)
{
return Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd();
}
boolean TSC_SteerCmdArbnAndLim_Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna(void)
{
return Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna();
}





uint16  TSC_SteerCmdArbnAndLim_Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val();
}
uint16  TSC_SteerCmdArbnAndLim_Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val();
}


     /* SteerCmdArbnAndLim */
      /* SteerCmdArbnAndLim */

/** Per Instance Memories */
float32 *TSC_SteerCmdArbnAndLim_Rte_Pim_SteerCmdArbnAndLimDebStFalbck(void)
{
  return Rte_Pim_SteerCmdArbnAndLimDebStFalbck();
}
uint32 *TSC_SteerCmdArbnAndLim_Rte_Pim_SteerCmdArbnAndLimDebStFw(void)
{
  return Rte_Pim_SteerCmdArbnAndLimDebStFw();
}
uint8 *TSC_SteerCmdArbnAndLim_Rte_Pim_SteerCmdArbnAndLimSt(void)
{
  return Rte_Pim_SteerCmdArbnAndLimSt();
}
boolean *TSC_SteerCmdArbnAndLim_Rte_Pim_FalbckDebStVari(void)
{
  return Rte_Pim_FalbckDebStVari();
}
boolean *TSC_SteerCmdArbnAndLim_Rte_Pim_FwDebStVari(void)
{
  return Rte_Pim_FwDebStVari();
}



