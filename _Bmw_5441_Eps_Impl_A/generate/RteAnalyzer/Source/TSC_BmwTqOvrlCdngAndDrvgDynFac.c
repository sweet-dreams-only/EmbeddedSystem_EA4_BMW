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
 *          File:  TSC_BmwTqOvrlCdngAndDrvgDynFac.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwTqOvrlCdngAndDrvgDynFac.h"
#include "TSC_BmwTqOvrlCdngAndDrvgDynFac.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynDampgFacReq_Val(float32 *data)
{
  return Rte_Read_BmwDrvgDynDampgFacReq_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynEffortFacReq_Val(float32 *data)
{
  return Rte_Read_BmwDrvgDynEffortFacReq_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
{
  return Rte_Read_BmwDrvgDynErrIfActv_Logl(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwDrvgDynRtnFacReq_Val(float32 *data)
{
  return Rte_Read_BmwDrvgDynRtnFacReq_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwOutpTqOvrlCmdEna_Logl(boolean *data)
{
  return Rte_Read_BmwOutpTqOvrlCmdEna_Logl(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_BmwTarSteerTqDrvrActr_Val(float32 *data)
{
  return Rte_Read_BmwTarSteerTqDrvrActr_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynActv_Logl(boolean *data)
{
  return Rte_Read_DrvgDynActv_Logl(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynFacEna_Logl(boolean *data)
{
  return Rte_Read_DrvgDynFacEna_Logl(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
{
  return Rte_Read_DrvgDynIfSt_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_OutpTqOvrlRampInEna_Logl(boolean *data)
{
  return Rte_Read_OutpTqOvrlRampInEna_Logl(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_BmwOutpTqOvrlCmd_Val(float32 data)
{
  return Rte_Write_BmwOutpTqOvrlCmd_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_DampgCmdSca_Val(float32 data)
{
  return Rte_Write_DampgCmdSca_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_EffortCmdSca_Val(float32 data)
{
  return Rte_Write_EffortCmdSca_Val(data);
}

Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Write_RtnCmdSca_Val(float32 data)
{
  return Rte_Write_RtnCmdSca_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_f32_Oper(SigPah_Arg, LocnKey_Arg);
}
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvDampgSlewRate_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvEffortSlewRate_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacActvRtnSlewRate_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvDampgSlewRate_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvEffortSlewRate_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacInactvRtnSlewRate_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacOutpTqOvrlSlew_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacReqdRtnCmdScaLoLim_Val();
}
float32  TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrLpFilFrq_Val();
}
Ary1D_u11p5_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D(void)
{
  return (Ary1D_u11p5_12 *) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimX_Ary1D();
}
Ary2D_u1p15_12_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D(void)
{
  return (Ary2D_u1p15_12_12 *) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacDampgScaLoLimY_Ary2D();
}
Ary1D_u4p12_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D(void)
{
  return (Ary1D_u4p12_12 *) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimX_Ary1D();
}
Ary2D_u2p14_12_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D(void)
{
  return (Ary2D_u2p14_12_12 *) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacEffortScaHiLimY_Ary2D();
}
Ary1D_u4p12_10 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D(void)
{
  return (Ary1D_u4p12_10 *) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrMaxY_Ary1D();
}
Ary1D_u9p7_10 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D(void)
{
  return (Ary1D_u9p7_10 *) Rte_Prm_BmwTqOvrlCdngAndDrvgDynFacTarSteerTqDrvrActrSpdX_Ary1D();
}
Ary1D_u9p7_12 * TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
{
  return (Ary1D_u9p7_12 *) Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D();
}


     /* BmwTqOvrlCdngAndDrvgDynFac */
      /* BmwTqOvrlCdngAndDrvgDynFac */

/** Per Instance Memories */
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdStVari(void)
{
  return Rte_Pim_BmwOutpTqOvrlCmdStVari();
}
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_DampgCmdScaRateLimrStVari(void)
{
  return Rte_Pim_DampgCmdScaRateLimrStVari();
}
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_EffortCmdScaRateLimrStVari(void)
{
  return Rte_Pim_EffortCmdScaRateLimrStVari();
}
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznBmwTarSteerTqDrvrActr(void)
{
  return Rte_Pim_FrznBmwTarSteerTqDrvrActr();
}
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_LimdCdndTqOvrl(void)
{
  return Rte_Pim_LimdCdndTqOvrl();
}
float32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RtnCmdScaRateLimrStVari(void)
{
  return Rte_Pim_RtnCmdScaRateLimrStVari();
}
uint32 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_MsgCycTmr(void)
{
  return Rte_Pim_MsgCycTmr();
}
DrvgDynIfSt1 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynIfSt(void)
{
  return Rte_Pim_PrevDrvgDynIfSt();
}
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwOutpTqOvrlCmdRampCmpl(void)
{
  return Rte_Pim_BmwOutpTqOvrlCmdRampCmpl();
}
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_FrznSigActv(void)
{
  return Rte_Pim_FrznSigActv();
}
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDampgSlewInProgs(void)
{
  return Rte_Pim_PrevDampgSlewInProgs();
}
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevDrvgDynActv(void)
{
  return Rte_Pim_PrevDrvgDynActv();
}
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevEffortSlewInProgs(void)
{
  return Rte_Pim_PrevEffortSlewInProgs();
}
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_PrevRtnSlewInProgs(void)
{
  return Rte_Pim_PrevRtnSlewInProgs();
}
boolean *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_RampToZeroEnad(void)
{
  return Rte_Pim_RampToZeroEnad();
}
FilLpRec1 *TSC_BmwTqOvrlCdngAndDrvgDynFac_Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari(void)
{
  return Rte_Pim_BmwTarSteerTqDrvrActrLpFilStVari();
}



