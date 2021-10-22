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
 *          File:  TSC_HiLoadStallLimr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_HiLoadStallLimr.h"
#include "TSC_HiLoadStallLimr.h"








Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
{
  return Rte_Read_MotAndThermProtnLoaMod_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
{
  return Rte_Read_DualEcuFltMtgtnEna_Logl(data);
}

Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_MotTqCmdLimdPreStall_Val(float32 *data)
{
  return Rte_Read_MotTqCmdLimdPreStall_Val(data);
}

Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_HiLoadStallLimr_Rte_Read_StallMotTqLimDi_Logl(boolean *data)
{
  return Rte_Read_StallMotTqLimDi_Logl(data);
}




Std_ReturnType TSC_HiLoadStallLimr_Rte_Write_StallMotTqLim_Val(float32 data)
{
  return Rte_Write_StallMotTqLim_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_HiLoadStallLimrMotTqCmdFetMtgtnEnaFilFrq_Val();
}
float32  TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotTqCmdFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_HiLoadStallLimrMotTqCmdFilFrq_Val();
}
float32  TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallThermLimSca_Val(void)
{
  return (float32 ) Rte_Prm_HiLoadStallLimrStallThermLimSca_Val();
}
Ary1D_f32_2 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(void)
{
  return (Ary1D_f32_2 *) Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D();
}
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(void)
{
  return (Ary1D_u8p8_6 *) Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D();
}
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(void)
{
  return (Ary1D_u8p8_6 *) Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D();
}
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(void)
{
  return (Ary1D_u8p8_6 *) Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D();
}
Ary1D_u8p8_6 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(void)
{
  return (Ary1D_u8p8_6 *) Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D();
}
Ary1D_f32_2 * TSC_HiLoadStallLimr_Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(void)
{
  return (Ary1D_f32_2 *) Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D();
}


     /* HiLoadStallLimr */
      /* HiLoadStallLimr */

/** Per Instance Memories */
float32 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimFetMtgtnPrev(void)
{
  return Rte_Pim_StallMotTqLimFetMtgtnPrev();
}
float32 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqLimPrev(void)
{
  return Rte_Pim_StallMotTqLimPrev();
}
float32 *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmd(void)
{
  return Rte_Pim_dHiLoadStallLimrStallMotTqCmd();
}
float32 *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild(void)
{
  return Rte_Pim_dHiLoadStallLimrStallMotTqCmdFild();
}
float32 *TSC_HiLoadStallLimr_Rte_Pim_dHiLoadStallLimrStallMotTqLim(void)
{
  return Rte_Pim_dHiLoadStallLimrStallMotTqLim();
}
uint8 *TSC_HiLoadStallLimr_Rte_Pim_FetLoaMtgtnCalIdx(void)
{
  return Rte_Pim_FetLoaMtgtnCalIdx();
}
FilLpRec1 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFetMtgtnFil(void)
{
  return Rte_Pim_StallMotTqCmdFetMtgtnFil();
}
FilLpRec1 *TSC_HiLoadStallLimr_Rte_Pim_StallMotTqCmdFil(void)
{
  return Rte_Pim_StallMotTqCmdFil();
}



