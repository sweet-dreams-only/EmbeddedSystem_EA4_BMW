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
 *          File:  TSC_SysFricLrng.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_SysFricLrng.h"
#include "TSC_SysFricLrng.h"















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
Std_ReturnType TSC_SysFricLrng_Rte_Call_FricNonLrngData_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_FricNonLrngData_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_SysFricLrng_Rte_Write_SysFricOffs_Val(float32 data)
{
  return Rte_Write_SysFricOffs_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_SysFricLrng_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_SysFricLrng_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */
Std_ReturnType TSC_SysFricLrng_Rte_Call_FricLrngData_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_FricLrngData_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_SysFricLrng_Rte_Read_AssiMechT_Val(float32 *data)
{
  return Rte_Read_AssiMechT_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_FricLrngCustEna_Logl(boolean *data)
{
  return Rte_Read_FricLrngCustEna_Logl(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_FricLrngDi_Logl(boolean *data)
{
  return Rte_Read_FricLrngDi_Logl(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_HwAgAuthy_Val(float32 *data)
{
  return Rte_Read_HwAgAuthy_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_HwVel_Val(float32 *data)
{
  return Rte_Read_HwVel_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_MotTqCmdCrf_Val(float32 *data)
{
  return Rte_Read_MotTqCmdCrf_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_VehLatA_Val(float32 *data)
{
  return Rte_Read_VehLatA_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Read_VehSpdVld_Logl(boolean *data)
{
  return Rte_Read_VehSpdVld_Logl(data);
}




Std_ReturnType TSC_SysFricLrng_Rte_Write_MaxLrndFric_Val(float32 data)
{
  return Rte_Write_MaxLrndFric_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Write_SysFricEstimd_Val(float32 data)
{
  return Rte_Write_SysFricEstimd_Val(data);
}

Std_ReturnType TSC_SysFricLrng_Rte_Write_SysSatnFricEstimd_Val(float32 data)
{
  return Rte_Write_SysSatnFricEstimd_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_SysFricLrng_Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
{
  return Rte_Call_FltInj_f32_Oper(SigPah_Arg, LocnKey_Arg);
}
Std_ReturnType TSC_SysFricLrng_Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrSts_Oper(NtcNr_Arg, NtcQlfr_Arg);
}
Std_ReturnType TSC_SysFricLrng_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngAvrgFricFrq_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngAvrgFricFrq_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineEolFric_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngBasLineEolFric_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngEolFricDifHiLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngEolFricDifHiLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngEolFricDifLoLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngEolFricDifLoLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngEolFricDifScagFac_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngEolFricDifScagFac_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricDiagcThd_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngFricDiagcThd_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffs_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngFricOffs_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffsHiLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngFricOffsHiLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffsLoLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngFricOffsLoLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngGain_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngGain_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHiFricDiagcThd_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngHiFricDiagcThd_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwPosnAuthyThd_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngHwPosnAuthyThd_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwVelConstrLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngHwVelConstrLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwVelHiLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngHwVelHiLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngHwVelLoLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngHwVelLoLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngIgnCycFricChgLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngIgnCycFricChgLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngIgnCycFricOffs_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngIgnCycFricOffs_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngLatAHiLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngLatAHiLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngLatALoLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngLatALoLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngTHiLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngTHiLim_Val();
}
float32  TSC_SysFricLrng_Rte_Prm_SysFricLrngTLoLim_Val(void)
{
  return (float32 ) Rte_Prm_SysFricLrngTLoLim_Val();
}
uint32  TSC_SysFricLrng_Rte_Prm_SysFricLrngThd_Val(void)
{
  return (uint32 ) Rte_Prm_SysFricLrngThd_Val();
}
uint16  TSC_SysFricLrng_Rte_Prm_SysFricLrngDebStep_Val(void)
{
  return (uint16 ) Rte_Prm_SysFricLrngDebStep_Val();
}
uint16  TSC_SysFricLrng_Rte_Prm_SysFricLrngHiFricDebStep_Val(void)
{
  return (uint16 ) Rte_Prm_SysFricLrngHiFricDebStep_Val();
}
uint16  TSC_SysFricLrng_Rte_Prm_SysFricLrngRngCntrThd_Val(void)
{
  return (uint16 ) Rte_Prm_SysFricLrngRngCntrThd_Val();
}
Ary1D_f32_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineFric_Ary1D(void)
{
  return (Ary1D_f32_4 *) Rte_Prm_SysFricLrngBasLineFric_Ary1D();
}
Ary2D_f32_8_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineHys_Ary2D(void)
{
  return (Ary2D_f32_8_4 *) Rte_Prm_SysFricLrngBasLineHys_Ary2D();
}
Ary2D_u16_8_3 * TSC_SysFricLrng_Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D(void)
{
  return (Ary2D_u16_8_3 *) Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D();
}
Ary1D_f32_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngFricChgWght_Ary1D(void)
{
  return (Ary1D_f32_4 *) Rte_Prm_SysFricLrngFricChgWght_Ary1D();
}
Ary1D_f32_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D(void)
{
  return (Ary1D_f32_4 *) Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D();
}
Ary1D_u11p5_10 * TSC_SysFricLrng_Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D(void)
{
  return (Ary1D_u11p5_10 *) Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D();
}
Ary1D_u6p10_10 * TSC_SysFricLrng_Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D(void)
{
  return (Ary1D_u6p10_10 *) Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D();
}
Ary1D_boolean_4 * TSC_SysFricLrng_Rte_Prm_SysFricLrngMaskVehSpd_Ary1D(void)
{
  return (Ary1D_boolean_4 *) Rte_Prm_SysFricLrngMaskVehSpd_Ary1D();
}
Ary2D_f32_4_2 * TSC_SysFricLrng_Rte_Prm_SysFricLrngVehSpd_Ary2D(void)
{
  return (Ary2D_f32_4_2 *) Rte_Prm_SysFricLrngVehSpd_Ary2D();
}

SysFricDataRec1 * TSC_SysFricLrng_Rte_CData_FricLrngDataDft(void)
{
  return (SysFricDataRec1 *) Rte_CData_FricLrngDataDft();
}
SysFricNonLrngDataRec1 * TSC_SysFricLrng_Rte_CData_FricNonLrngDataDft(void)
{
  return (SysFricNonLrngDataRec1 *) Rte_CData_FricNonLrngDataDft();
}

     /* SysFricLrng */
      /* SysFricLrng */

/** Per Instance Memories */
float32 *TSC_SysFricLrng_Rte_Pim_EstimdFric(void)
{
  return Rte_Pim_EstimdFric();
}
float32 *TSC_SysFricLrng_Rte_Pim_FricOffs(void)
{
  return Rte_Pim_FricOffs();
}
float32 *TSC_SysFricLrng_Rte_Pim_PrevMaxRawAvrgFric(void)
{
  return Rte_Pim_PrevMaxRawAvrgFric();
}
float32 *TSC_SysFricLrng_Rte_Pim_SatnEstimdFric(void)
{
  return Rte_Pim_SatnEstimdFric();
}
uint32 *TSC_SysFricLrng_Rte_Pim_RefTmrLrngConstr(void)
{
  return Rte_Pim_RefTmrLrngConstr();
}
SysFricLrngOperMod1 *TSC_SysFricLrng_Rte_Pim_FricLrngOperModPrev(void)
{
  return Rte_Pim_FricLrngOperModPrev();
}
boolean *TSC_SysFricLrng_Rte_Pim_FricLrngRunOneTi(void)
{
  return Rte_Pim_FricLrngRunOneTi();
}
boolean *TSC_SysFricLrng_Rte_Pim_FricOffsOutpDi(void)
{
  return Rte_Pim_FricOffsOutpDi();
}
float32 *TSC_SysFricLrng_Rte_Pim_ColTqAry(void)
{
  return Rte_Pim_ColTqAry();
}
float32 *TSC_SysFricLrng_Rte_Pim_FilAvrgFric(void)
{
  return Rte_Pim_FilAvrgFric();
}
float32 *TSC_SysFricLrng_Rte_Pim_HwAgBuf(void)
{
  return Rte_Pim_HwAgBuf();
}
float32 *TSC_SysFricLrng_Rte_Pim_HwVelBuf(void)
{
  return Rte_Pim_HwVelBuf();
}
float32 *TSC_SysFricLrng_Rte_Pim_RawAvrgFric(void)
{
  return Rte_Pim_RawAvrgFric();
}
float32 *TSC_SysFricLrng_Rte_Pim_SatnAvrgFric(void)
{
  return Rte_Pim_SatnAvrgFric();
}
float32 *TSC_SysFricLrng_Rte_Pim_VehBasLineFric(void)
{
  return Rte_Pim_VehBasLineFric();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AssiMechTLpFil(void)
{
  return Rte_Pim_AssiMechTLpFil();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil1(void)
{
  return Rte_Pim_AvrgFricLpFil1();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil2(void)
{
  return Rte_Pim_AvrgFricLpFil2();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil3(void)
{
  return Rte_Pim_AvrgFricLpFil3();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_AvrgFricLpFil4(void)
{
  return Rte_Pim_AvrgFricLpFil4();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_ColTqLpFil(void)
{
  return Rte_Pim_ColTqLpFil();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_FricChgLpFil(void)
{
  return Rte_Pim_FricChgLpFil();
}
SysFricDataRec1 *TSC_SysFricLrng_Rte_Pim_FricLrngData(void)
{
  return Rte_Pim_FricLrngData();
}
SysFricNonLrngDataRec1 *TSC_SysFricLrng_Rte_Pim_FricNonLrngData(void)
{
  return Rte_Pim_FricNonLrngData();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_HwAgAuthyLpFil(void)
{
  return Rte_Pim_HwAgAuthyLpFil();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_HwAgLpFil(void)
{
  return Rte_Pim_HwAgLpFil();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_HwVelLpFil(void)
{
  return Rte_Pim_HwVelLpFil();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_LatALpFil(void)
{
  return Rte_Pim_LatALpFil();
}
FilLpRec1 *TSC_SysFricLrng_Rte_Pim_VehSpdLpFil(void)
{
  return Rte_Pim_VehSpdLpFil();
}



