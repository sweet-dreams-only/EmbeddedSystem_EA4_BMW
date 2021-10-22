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
 *          File:  TSC_PullCmpActv.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_PullCmpActv.h"
#include "TSC_PullCmpActv.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_PullCmpLongTerm_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_PullCmpActv_Rte_Call_PullCmpLongTerm_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_PullCmpLongTerm_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_PullCmpActv_Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(float32 data)
{
  Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize( data);
}





Std_ReturnType TSC_PullCmpActv_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_HwVel_Val(float32 *data)
{
  return Rte_Read_HwVel_Val(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_PinionAgConf_Val(float32 *data)
{
  return Rte_Read_PinionAgConf_Val(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpActvDi_Logl(boolean *data)
{
  return Rte_Read_PullCmpActvDi_Logl(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpCmdDi_Logl(boolean *data)
{
  return Rte_Read_PullCmpCmdDi_Logl(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpCustLrngDi_Logl(boolean *data)
{
  return Rte_Read_PullCmpCustLrngDi_Logl(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_PullCmpLrngDi_Logl(boolean *data)
{
  return Rte_Read_PullCmpLrngDi_Logl(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_VehLatA_Val(float32 *data)
{
  return Rte_Read_VehLatA_Val(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_VehSpdVld_Logl(boolean *data)
{
  return Rte_Read_VehSpdVld_Logl(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_VehYawRate_Val(float32 *data)
{
  return Rte_Read_VehYawRate_Val(data);
}

Std_ReturnType TSC_PullCmpActv_Rte_Read_VehYawRateVld_Logl(boolean *data)
{
  return Rte_Read_VehYawRateVld_Logl(data);
}




Std_ReturnType TSC_PullCmpActv_Rte_Write_PullCmpCmd_Val(float32 data)
{
  return Rte_Write_PullCmpCmd_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_PullCmpActv_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_f32_Oper(SigPah_Arg, LocnKey_Arg);
}
Std_ReturnType TSC_PullCmpActv_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_PullCmpActv_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_PullCmpActv_Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize(void)
{
return Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize();
}













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLongTermLim_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLongTermLim_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaTiThd_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaTiThd_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvOutpMaxRate_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvOutpMaxRate_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvPullCmpShoTermLim_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullCmpTotLim_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvPullCmpTotLim_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvPullErrLimLongTerm_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrMgnThd_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvPullErrMgnThd_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvPullErrShoTermLim_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvPullErrShoTermLim_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvShoTermRampTi_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvShoTermRampTi_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_PullCmpActvYawRateFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_PullCmpActvYawRateFilFrq_Val();
}
float32  TSC_PullCmpActv_Rte_Prm_SysGlbPrmSysTqRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysTqRat_Val();
}
boolean  TSC_PullCmpActv_Rte_Prm_PullCmpActvEna_Logl(void)
{
  return (boolean ) Rte_Prm_PullCmpActvEna_Logl();
}
Ary1D_u9p7_4 * TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(void)
{
  return (Ary1D_u9p7_4 *) Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D();
}
Ary1D_u2p14_4 * TSC_PullCmpActv_Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(void)
{
  return (Ary1D_u2p14_4 *) Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D();
}

float32  TSC_PullCmpActv_Rte_CData_PullCmpLongTermDft(void)
{
  return (float32 ) Rte_CData_PullCmpLongTermDft();
}

     /* PullCmpActv */
      /* PullCmpActv */

/** Per Instance Memories */
float32 *TSC_PullCmpActv_Rte_Pim_CmpLrnTiDecShoTerm(void)
{
  return Rte_Pim_CmpLrnTiDecShoTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_CmpLrnTiIncShoTerm(void)
{
  return Rte_Pim_CmpLrnTiIncShoTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_CmpLrnTiLongTerm(void)
{
  return Rte_Pim_CmpLrnTiLongTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_IntgtrGainDecShoTerm(void)
{
  return Rte_Pim_IntgtrGainDecShoTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_IntgtrGainIncShoTerm(void)
{
  return Rte_Pim_IntgtrGainIncShoTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_PrevLrnTiLongTerm(void)
{
  return Rte_Pim_PrevLrnTiLongTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpCmdRateLimPrev(void)
{
  return Rte_Pim_PullCmpCmdRateLimPrev();
}
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpCmdTot(void)
{
  return Rte_Pim_PullCmpCmdTot();
}
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpLongTerm(void)
{
  return Rte_Pim_PullCmpLongTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_PullCmpShoTerm(void)
{
  return Rte_Pim_PullCmpShoTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_VehSpdPrev(void)
{
  return Rte_Pim_VehSpdPrev();
}
float32 *TSC_PullCmpActv_Rte_Pim_VehSpdRate(void)
{
  return Rte_Pim_VehSpdRate();
}
float32 *TSC_PullCmpActv_Rte_Pim_dPullCmpActvIntgtrGainShoTerm(void)
{
  return Rte_Pim_dPullCmpActvIntgtrGainShoTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrLongTerm(void)
{
  return Rte_Pim_dPullCmpActvPullErrLongTerm();
}
float32 *TSC_PullCmpActv_Rte_Pim_dPullCmpActvPullErrShoTerm(void)
{
  return Rte_Pim_dPullCmpActvPullErrShoTerm();
}
uint32 *TSC_PullCmpActv_Rte_Pim_RefTiEnaLrng(void)
{
  return Rte_Pim_RefTiEnaLrng();
}
uint32 *TSC_PullCmpActv_Rte_Pim_RefTiOpstSign(void)
{
  return Rte_Pim_RefTiOpstSign();
}
boolean *TSC_PullCmpActv_Rte_Pim_LrngEnaPrev(void)
{
  return Rte_Pim_LrngEnaPrev();
}
boolean *TSC_PullCmpActv_Rte_Pim_LrngEnad(void)
{
  return Rte_Pim_LrngEnad();
}
boolean *TSC_PullCmpActv_Rte_Pim_OpstSignPrev(void)
{
  return Rte_Pim_OpstSignPrev();
}
boolean *TSC_PullCmpActv_Rte_Pim_PullCmpActvDi(void)
{
  return Rte_Pim_PullCmpActvDi();
}
boolean *TSC_PullCmpActv_Rte_Pim_PullCmpLongTermRst(void)
{
  return Rte_Pim_PullCmpLongTermRst();
}
boolean *TSC_PullCmpActv_Rte_Pim_PullCmpShoTermRst(void)
{
  return Rte_Pim_PullCmpShoTermRst();
}
boolean *TSC_PullCmpActv_Rte_Pim_dPullCmpActvShoTermRst(void)
{
  return Rte_Pim_dPullCmpActvShoTermRst();
}
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLongTerm(void)
{
  return Rte_Pim_HwTqLpFilLongTerm();
}
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_HwTqLpFilLrngEna(void)
{
  return Rte_Pim_HwTqLpFilLrngEna();
}
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_HwTqLpFilShoTerm(void)
{
  return Rte_Pim_HwTqLpFilShoTerm();
}
FilLpRec1 *TSC_PullCmpActv_Rte_Pim_VehYawRateLpFil(void)
{
  return Rte_Pim_VehYawRateLpFil();
}



