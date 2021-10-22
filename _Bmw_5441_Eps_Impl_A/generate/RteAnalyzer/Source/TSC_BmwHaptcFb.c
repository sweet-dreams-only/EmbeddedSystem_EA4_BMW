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
 *          File:  TSC_BmwHaptcFb.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwHaptcFb.h"
#include "TSC_BmwHaptcFb.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbIntenNr_Val(BmwHaptcFbIntenNr1 *data)
{
  return Rte_Read_BmwHaptcFbIntenNr_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbIntenNrVld_Logl(boolean *data)
{
  return Rte_Read_BmwHaptcFbIntenNrVld_Logl(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbPatNr_Val(BmwHaptcFbPatNr1 *data)
{
  return Rte_Read_BmwHaptcFbPatNr_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_BmwHaptcFbPatNrVld_Logl(boolean *data)
{
  return Rte_Read_BmwHaptcFbPatNrVld_Logl(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
{
  return Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_HaptcFbEna_Logl(boolean *data)
{
  return Rte_Read_HaptcFbEna_Logl(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_HwOscnActv_Logl(boolean *data)
{
  return Rte_Read_HwOscnActv_Logl(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
{
  return Rte_Read_HwOscnDcThdExcdd_Logl(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
{
  return Rte_Read_StsSteerAssi_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_ThermRednFac_Val(float32 *data)
{
  return Rte_Read_ThermRednFac_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Read_VehSpdVld_Logl(boolean *data)
{
  return Rte_Read_VehSpdVld_Logl(data);
}




Std_ReturnType TSC_BmwHaptcFb_Rte_Write_HaptcFbSt_Val(HaptcFbSt1 data)
{
  return Rte_Write_HaptcFbSt_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Write_HwOscnEna_Logl(boolean data)
{
  return Rte_Write_HwOscnEna_Logl(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Write_HwOscnFallRampRate_Val(float32 data)
{
  return Rte_Write_HwOscnFallRampRate_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Write_HwOscnFrq_Val(float32 data)
{
  return Rte_Write_HwOscnFrq_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Write_HwOscnMotAmp_Val(float32 data)
{
  return Rte_Write_HwOscnMotAmp_Val(data);
}

Std_ReturnType TSC_BmwHaptcFb_Rte_Write_HwOscnRisngRampRate_Val(float32 data)
{
  return Rte_Write_HwOscnRisngRampRate_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwHaptcFb_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwHaptcFb_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwHaptcFbEpsDegradedFltThd_Val();
}
Ary1D_u4p12_12 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D(void)
{
  return (Ary1D_u4p12_12 *) Rte_Prm_BmwHaptcFbAmpAndIntenHwTqTblX_Ary1D();
}
Ary1D_u4p12_13 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D(void)
{
  return (Ary1D_u4p12_13 *) Rte_Prm_BmwHaptcFbAmpBilnrSeln_Ary1D();
}
Ary2D_u4p12_13_13 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D(void)
{
  return (Ary2D_u4p12_13_13 *) Rte_Prm_BmwHaptcFbAmpSelnTblY_Ary2D();
}
Ary1D_u6p10_13 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D(void)
{
  return (Ary1D_u6p10_13 *) Rte_Prm_BmwHaptcFbFrqBilnrSeln_Ary1D();
}
Ary2D_u6p10_13_13 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D(void)
{
  return (Ary2D_u6p10_13_13 *) Rte_Prm_BmwHaptcFbFrqSelnTblY_Ary2D();
}
Ary2D_u6p10_12_12 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D(void)
{
  return (Ary2D_u6p10_12_12 *) Rte_Prm_BmwHaptcFbHwTqFrqTblY_Ary2D();
}
Ary1D_u16_13 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D(void)
{
  return (Ary1D_u16_13 *) Rte_Prm_BmwHaptcFbIntenSelnTblX_Ary1D();
}
Ary2D_u4p12_12_12 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D(void)
{
  return (Ary2D_u4p12_12_12 *) Rte_Prm_BmwHaptcFbMotTqAmpTblY_Ary2D();
}
Ary1D_f32_11 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D(void)
{
  return (Ary1D_f32_11 *) Rte_Prm_BmwHaptcFbPatActvTiTblY_Ary1D();
}
Ary1D_f32_11 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D(void)
{
  return (Ary1D_f32_11 *) Rte_Prm_BmwHaptcFbPatPasTiTblY_Ary1D();
}
Ary1D_f32_11 * TSC_BmwHaptcFb_Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D(void)
{
  return (Ary1D_f32_11 *) Rte_Prm_BmwHaptcFbPatRisngSlewTblY_Ary1D();
}
Ary1D_u9p7_12 * TSC_BmwHaptcFb_Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
{
  return (Ary1D_u9p7_12 *) Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D();
}


     /* BmwHaptcFb */
      /* BmwHaptcFb */

/** Per Instance Memories */
uint32 *TSC_BmwHaptcFb_Rte_Pim_TqOscnEnaTmr(void)
{
  return Rte_Pim_TqOscnEnaTmr();
}
BmwHaptcFbIntenNr1 *TSC_BmwHaptcFb_Rte_Pim_CurrInten(void)
{
  return Rte_Pim_CurrInten();
}
BmwHaptcFbPatNr1 *TSC_BmwHaptcFb_Rte_Pim_CurrPat(void)
{
  return Rte_Pim_CurrPat();
}



