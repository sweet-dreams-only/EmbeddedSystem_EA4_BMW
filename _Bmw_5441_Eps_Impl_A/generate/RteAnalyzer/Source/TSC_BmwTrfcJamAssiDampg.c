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
 *          File:  TSC_BmwTrfcJamAssiDampg.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwTrfcJamAssiDampg.h"
#include "TSC_BmwTrfcJamAssiDampg.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(float32 *data)
{
  return Rte_Read_BmwTrfcJamAssiDampgScaReq_Val(data);
}

Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean *data)
{
  return Rte_Read_BmwTrfcJamAssiDampgScaReqVld_Logl(data);
}

Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
{
  return Rte_Read_BmwTrfcJamAssiDampgStReq_Val(data);
}

Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
{
  return Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(data);
}

Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_TrfcJamAssiCmdEna_Logl(boolean *data)
{
  return Rte_Read_TrfcJamAssiCmdEna_Logl(data);
}

Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Write_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 data)
{
  return Rte_Write_BmwTrfcJamAssiDampgSt_Val(data);
}

Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Write_TrfcJamAssiCmd_Val(float32 data)
{
  return Rte_Write_TrfcJamAssiCmd_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwTrfcJamAssiDampg_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwTrfcJamAssiDampgRatThd_Val();
}
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val(void)
{
  return (float32 ) Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnActv_Val();
}
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val(void)
{
  return (float32 ) Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInactv_Val();
}
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val(void)
{
  return (float32 ) Rte_Prm_BmwTrfcJamAssiDampgSlewRateDwnInvld_Val();
}
float32  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val(void)
{
  return (float32 ) Rte_Prm_BmwTrfcJamAssiDampgSlewRateUp_Val();
}
uint16  TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwTrfcJamAssiDampgLimExcddFltRefTiThd_Val();
}
Ary1D_u11p5_10 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D(void)
{
  return (Ary1D_u11p5_10 *) Rte_Prm_BmwTrfcJamAssiDampgBasDampgX_Ary1D();
}
Ary1D_u4p12_10 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D(void)
{
  return (Ary1D_u4p12_10 *) Rte_Prm_BmwTrfcJamAssiDampgBasDampgY_Ary1D();
}
Ary1D_u11p5_12 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D(void)
{
  return (Ary1D_u11p5_12 *) Rte_Prm_BmwTrfcJamAssiDampgLimdDampgX_Ary1D();
}
Ary2D_u4p12_12_12 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D(void)
{
  return (Ary2D_u4p12_12_12 *) Rte_Prm_BmwTrfcJamAssiDampgLimdDampgY_Ary2D();
}
Ary1D_u9p7_12 * TSC_BmwTrfcJamAssiDampg_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
{
  return (Ary1D_u9p7_12 *) Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D();
}


     /* BmwTrfcJamAssiDampg */
      /* BmwTrfcJamAssiDampg */

/** Per Instance Memories */
float32 *TSC_BmwTrfcJamAssiDampg_Rte_Pim_BmwTrfcJamAssiDampgScaStVari(void)
{
  return Rte_Pim_BmwTrfcJamAssiDampgScaStVari();
}
uint32 *TSC_BmwTrfcJamAssiDampg_Rte_Pim_LimExcddFltRefTi(void)
{
  return Rte_Pim_LimExcddFltRefTi();
}
uint8 *TSC_BmwTrfcJamAssiDampg_Rte_Pim_TmpBmwTrfcJamAssiDampgSt(void)
{
  return Rte_Pim_TmpBmwTrfcJamAssiDampgSt();
}
boolean *TSC_BmwTrfcJamAssiDampg_Rte_Pim_PrevLimExcddFlt(void)
{
  return Rte_Pim_PrevLimExcddFlt();
}



