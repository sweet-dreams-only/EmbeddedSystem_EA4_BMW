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
 *          File:  TSC_BmwSplyCurrLim.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwSplyCurrLim.h"
#include "TSC_BmwSplyCurrLim.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwMaxCurrLimr_Val(float32 *data)
{
  return Rte_Read_BmwMaxCurrLimr_Val(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwMaxCurrLimrSts_Val(BmwMaxCurrLimrSts1 *data)
{
  return Rte_Read_BmwMaxCurrLimrSts_Val(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwStrtStopLim_Val(float32 *data)
{
  return Rte_Read_BmwStrtStopLim_Val(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BmwStrtStopMsgActv_Logl(boolean *data)
{
  return Rte_Read_BmwStrtStopMsgActv_Logl(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_BrdgVltg_Val(float32 *data)
{
  return Rte_Read_BrdgVltg_Val(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_MaxCurrAtHiSpd_Val(float32 *data)
{
  return Rte_Read_MaxCurrAtHiSpd_Val(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_MaxCurrAtLoSpd_Val(float32 *data)
{
  return Rte_Read_MaxCurrAtLoSpd_Val(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_RemCtrlPrkgEna_Logl(boolean *data)
{
  return Rte_Read_RemCtrlPrkgEna_Logl(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_SysMotTqCmdSca_Val(float32 *data)
{
  return Rte_Read_SysMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_BmwSplyCurrLim_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_BmwSplyCurrLim_Rte_Write_SplyCurrLim_Val(float32 data)
{
  return Rte_Write_SplyCurrLim_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwSplyCurrLim_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMax_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimMin_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimBmwMaxCurrLimrGrdt_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimEpsCpbyOffs_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimEpsMaxGrdt_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimEpsMinGrdt_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimMaxCurrLim_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimRemCtrlPrkgLim_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimVltgDptCurrLimFltThd_Val();
}
float32  TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val(void)
{
  return (float32 ) Rte_Prm_BmwSplyCurrLimVrntMaxCurr_Val();
}
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D(void)
{
  return (Ary1D_u6p10_8 *) Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrX_Ary1D();
}
Ary1D_u8p8_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D(void)
{
  return (Ary1D_u8p8_8 *) Rte_Prm_BmwSplyCurrLimDegradedVltgMaxCurrY_Ary1D();
}
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D(void)
{
  return (Ary1D_u6p10_8 *) Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrX_Ary1D();
}
Ary1D_u8p8_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D(void)
{
  return (Ary1D_u8p8_8 *) Rte_Prm_BmwSplyCurrLimNormVltgMaxCurrY_Ary1D();
}
Ary1D_u9p7_6 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D(void)
{
  return (Ary1D_u9p7_6 *) Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimX_Ary1D();
}
Ary1D_u8p8_6 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D(void)
{
  return (Ary1D_u8p8_6 *) Rte_Prm_BmwSplyCurrLimVehSpdDptCurrLimY_Ary1D();
}
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D(void)
{
  return (Ary1D_u6p10_8 *) Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecX_Ary1D();
}
Ary1D_u16p0_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D(void)
{
  return (Ary1D_u16p0_8 *) Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtDecY_Ary1D();
}
Ary1D_u6p10_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D(void)
{
  return (Ary1D_u6p10_8 *) Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncX_Ary1D();
}
Ary1D_u16p0_8 * TSC_BmwSplyCurrLim_Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D(void)
{
  return (Ary1D_u16p0_8 *) Rte_Prm_BmwSplyCurrLimVltgDptCurrGrdtIncY_Ary1D();
}


     /* BmwSplyCurrLim */
      /* BmwSplyCurrLim */

/** Per Instance Memories */
float32 *TSC_BmwSplyCurrLim_Rte_Pim_BmwMaxCurrLimGrdt(void)
{
  return Rte_Pim_BmwMaxCurrLimGrdt();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_SplyCurrLimGrdt(void)
{
  return Rte_Pim_SplyCurrLimGrdt();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_VltgDptCurrLimGrdt(void)
{
  return Rte_Pim_VltgDptCurrLimGrdt();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim(void)
{
  return Rte_Pim_dBmwSplyCurrLimBmwMaxCurrLim();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimCurrLim(void)
{
  return Rte_Pim_dBmwSplyCurrLimCurrLim();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimCurrLimPrel(void)
{
  return Rte_Pim_dBmwSplyCurrLimCurrLimPrel();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimGlbLim(void)
{
  return Rte_Pim_dBmwSplyCurrLimGlbLim();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimSplyCurrLim(void)
{
  return Rte_Pim_dBmwSplyCurrLimSplyCurrLim();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim(void)
{
  return Rte_Pim_dBmwSplyCurrLimVehSpdDptCurrLim();
}
float32 *TSC_BmwSplyCurrLim_Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim(void)
{
  return Rte_Pim_dBmwSplyCurrLimVltgDptCurrLim();
}



