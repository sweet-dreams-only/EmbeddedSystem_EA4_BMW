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
 *          File:  TSC_DutyCycThermProtn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_DutyCycThermProtn.h"
#include "TSC_DutyCycThermProtn.h"








Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_DutyCycThermProtnDi_Logl(boolean *data)
{
  return Rte_Read_DutyCycThermProtnDi_Logl(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_IgnTiOff_Val(uint32 *data)
{
  return Rte_Read_IgnTiOff_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
{
  return Rte_Read_MotAndThermProtnLoaMod_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_VehTiVld_Logl(boolean *data)
{
  return Rte_Read_VehTiVld_Logl(data);
}








     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DutyCycThermProtn_Rte_Call_FilStVal_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_FilStVal_GetErrorStatus(ErrorStatus_Arg);
}
Std_ReturnType TSC_DutyCycThermProtn_Rte_Call_FilStVal_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_FilStVal_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_DutyCycThermProtn_Rte_IrvWrite_DutyCycThermProtnInit1_FilStVariReInitFlg(boolean data)
{
  Rte_IrvWrite_DutyCycThermProtnInit1_FilStVariReInitFlg( data);
}





Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_DiagcStsLimdTPrfmnc_Logl(boolean *data)
{
  return Rte_Read_DiagcStsLimdTPrfmnc_Logl(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
{
  return Rte_Read_DualEcuFltMtgtnEna_Logl(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_EcuTFild_Val(float32 *data)
{
  return Rte_Read_EcuTFild_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotCurrPeakEstimd_Val(float32 *data)
{
  return Rte_Read_MotCurrPeakEstimd_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotCurrPeakEstimdFild_Val(float32 *data)
{
  return Rte_Read_MotCurrPeakEstimdFild_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotFetT_Val(float32 *data)
{
  return Rte_Read_MotFetT_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotMagT_Val(float32 *data)
{
  return Rte_Read_MotMagT_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Read_MotWidgT_Val(float32 *data)
{
  return Rte_Read_MotWidgT_Val(data);
}




Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_DutyCycThermProtnMaxOutp_Val(uint16 data)
{
  return Rte_Write_DutyCycThermProtnMaxOutp_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermDutyCycProtnLoadDptLim_Val(float32 data)
{
  return Rte_Write_ThermDutyCycProtnLoadDptLim_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermDutyCycProtnTDptLim_Val(float32 data)
{
  return Rte_Write_ThermDutyCycProtnTDptLim_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermLimSlowFilMax_Val(float32 data)
{
  return Rte_Write_ThermLimSlowFilMax_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermMotTqLim_Val(float32 data)
{
  return Rte_Write_ThermMotTqLim_Val(data);
}

Std_ReturnType TSC_DutyCycThermProtn_Rte_Write_ThermRednFac_Val(float32 data)
{
  return Rte_Write_ThermRednFac_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_DutyCycThermProtn_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
boolean TSC_DutyCycThermProtn_Rte_IrvRead_DutyCycThermProtnPer1_FilStVariReInitFlg(void)
{
return Rte_IrvRead_DutyCycThermProtnPer1_FilStVariReInitFlg();
}





float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltMotVelBreakPt_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnAbsltMotVelBreakPt_Val();
}
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltTTqSlewHiLim_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnAbsltTTqSlewHiLim_Val();
}
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltTTqSlewLoLim_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnAbsltTTqSlewLoLim_Val();
}
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnCtrlT_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnCtrlT_Val();
}
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnIgnOffMsgWaitTi_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnIgnOffMsgWaitTi_Val();
}
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnThermLimScaFac_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnThermLimScaFac_Val();
}
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnTqCmdSlewDwn_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnTqCmdSlewDwn_Val();
}
float32  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnTqCmdSlewUp_Val(void)
{
  return (float32 ) Rte_Prm_DutyCycThermProtnTqCmdSlewUp_Val();
}
u16p0  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnDutyCycFildThd_Val(void)
{
  return (u16p0 ) Rte_Prm_DutyCycThermProtnDutyCycFildThd_Val();
}
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnCtrlTSeln_Logl(void)
{
  return (boolean ) Rte_Prm_DutyCycThermProtnCtrlTSeln_Logl();
}
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnIgnOffCtrlEna_Logl(void)
{
  return (boolean ) Rte_Prm_DutyCycThermProtnIgnOffCtrlEna_Logl();
}
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMotPrTSeln_Logl(void)
{
  return (boolean ) Rte_Prm_DutyCycThermProtnMotPrTSeln_Logl();
}
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplrTSeln_Logl(void)
{
  return (boolean ) Rte_Prm_DutyCycThermProtnMplrTSeln_Logl();
}
boolean  TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnSlowFilTSeln_Logl(void)
{
  return (boolean ) Rte_Prm_DutyCycThermProtnSlowFilTSeln_Logl();
}
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D(void)
{
  return (Ary1D_s15p0_4 *) Rte_Prm_DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D();
}
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTTblX_Ary1D(void)
{
  return (Ary1D_s15p0_4 *) Rte_Prm_DutyCycThermProtnAbsltCtrlTTblX_Ary1D();
}
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D(void)
{
  return (Ary1D_u9p7_4 *) Rte_Prm_DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D();
}
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D(void)
{
  return (Ary1D_u9p7_4 *) Rte_Prm_DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D();
}
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D(void)
{
  return (Ary1D_s15p0_4 *) Rte_Prm_DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D();
}
Ary1D_s15p0_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTTblX_Ary1D(void)
{
  return (Ary1D_s15p0_4 *) Rte_Prm_DutyCycThermProtnAbsltCuTTblX_Ary1D();
}
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D(void)
{
  return (Ary1D_u9p7_4 *) Rte_Prm_DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D();
}
Ary1D_u9p7_4 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnAbsltCuTTqTblY_Ary1D(void)
{
  return (Ary1D_u9p7_4 *) Rte_Prm_DutyCycThermProtnAbsltCuTTqTblY_Ary1D();
}
Ary2D_u9p7_2_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnLstTblValNonStall_Ary2D(void)
{
  return (Ary2D_u9p7_2_5 *) Rte_Prm_DutyCycThermProtnLstTblValNonStall_Ary2D();
}
Ary2D_u9p7_2_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnLstTblValStall_Ary2D(void)
{
  return (Ary2D_u9p7_2_5 *) Rte_Prm_DutyCycThermProtnLstTblValStall_Ary2D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1NonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr1NonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr1StallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr1StallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2NonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr2NonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr2StallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr2StallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3NonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr3NonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr3StallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr3StallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4NonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr4NonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr4StallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr4StallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5NonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr5NonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr5StallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr5StallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6NonStallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr6NonStallTblY_Ary1D();
}
Ary1D_u3p13_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplr6StallTblY_Ary1D(void)
{
  return (Ary1D_u3p13_5 *) Rte_Prm_DutyCycThermProtnMplr6StallTblY_Ary1D();
}
Ary1D_s15p0_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplrFetMtgtnTblX_Ary1D(void)
{
  return (Ary1D_s15p0_5 *) Rte_Prm_DutyCycThermProtnMplrFetMtgtnTblX_Ary1D();
}
Ary1D_s15p0_5 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnMplrTblX_Ary1D(void)
{
  return (Ary1D_s15p0_5 *) Rte_Prm_DutyCycThermProtnMplrTblX_Ary1D();
}
Ary2D_u16p0_2_8 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnThermLoadLimTblX_Ary2D(void)
{
  return (Ary2D_u16p0_2_8 *) Rte_Prm_DutyCycThermProtnThermLoadLimTblX_Ary2D();
}
Ary2D_u9p7_2_8 * TSC_DutyCycThermProtn_Rte_Prm_DutyCycThermProtnThermLoadLimTblY_Ary2D(void)
{
  return (Ary2D_u9p7_2_8 *) Rte_Prm_DutyCycThermProtnThermLoadLimTblY_Ary2D();
}


     /* DutyCycThermProtn */
      /* DutyCycThermProtn */

/** Per Instance Memories */
float32 *TSC_DutyCycThermProtn_Rte_Pim_AbsltTLimSlewStVari(void)
{
  return Rte_Pim_AbsltTLimSlewStVari();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_LstTblValRateLimrStVari(void)
{
  return Rte_Pim_LstTblValRateLimrStVari();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_ReInitCntrVal(void)
{
  return Rte_Pim_ReInitCntrVal();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnAbsltCtrlrTTqLim(void)
{
  return Rte_Pim_dDutyCycThermProtnAbsltCtrlrTTqLim();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnAbsltCuTTqLim(void)
{
  return Rte_Pim_dDutyCycThermProtnAbsltCuTTqLim();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnAbsltTTqLim(void)
{
  return Rte_Pim_dDutyCycThermProtnAbsltTTqLim();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr12T(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr12T();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr36T(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr36T();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnThermLoadLim(void)
{
  return Rte_Pim_dDutyCycThermProtnThermLoadLim();
}
float32 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnThermLoadLimTblYVal(void)
{
  return Rte_Pim_dDutyCycThermProtnThermLoadLimTblYVal();
}
u9p7 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnLstTblVal(void)
{
  return Rte_Pim_dDutyCycThermProtnLstTblVal();
}
u9p7 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnLstTblValSlew(void)
{
  return Rte_Pim_dDutyCycThermProtnLstTblValSlew();
}
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr1(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr1();
}
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr2(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr2();
}
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr3(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr3();
}
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr4(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr4();
}
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr5(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr5();
}
u3p13 *TSC_DutyCycThermProtn_Rte_Pim_dDutyCycThermProtnMplr6(void)
{
  return Rte_Pim_dDutyCycThermProtnMplr6();
}
uint8 *TSC_DutyCycThermProtn_Rte_Pim_FetMtgtnEnaCalIdx(void)
{
  return Rte_Pim_FetMtgtnEnaCalIdx();
}
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil3ValPwrUp(void)
{
  return Rte_Pim_Fil3ValPwrUp();
}
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil4ValPwrUp(void)
{
  return Rte_Pim_Fil4ValPwrUp();
}
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil5ValPwrUp(void)
{
  return Rte_Pim_Fil5ValPwrUp();
}
uint8 *TSC_DutyCycThermProtn_Rte_Pim_Fil6ValPwrUp(void)
{
  return Rte_Pim_Fil6ValPwrUp();
}
boolean *TSC_DutyCycThermProtn_Rte_Pim_FetLoaMtgtnEnaPrev(void)
{
  return Rte_Pim_FetLoaMtgtnEnaPrev();
}
boolean *TSC_DutyCycThermProtn_Rte_Pim_ReInitCntrFlg(void)
{
  return Rte_Pim_ReInitCntrFlg();
}
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fil1ValStVari(void)
{
  return Rte_Pim_Fil1ValStVari();
}
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fil2ValStVari(void)
{
  return Rte_Pim_Fil2ValStVari();
}
DutyCycThermProtnFilStValRec1 *TSC_DutyCycThermProtn_Rte_Pim_FilStVal(void)
{
  return Rte_Pim_FilStVal();
}
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild3Val(void)
{
  return Rte_Pim_Fild3Val();
}
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild4Val(void)
{
  return Rte_Pim_Fild4Val();
}
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild5Val(void)
{
  return Rte_Pim_Fild5Val();
}
FilLpRec1 *TSC_DutyCycThermProtn_Rte_Pim_Fild6Val(void)
{
  return Rte_Pim_Fild6Val();
}



