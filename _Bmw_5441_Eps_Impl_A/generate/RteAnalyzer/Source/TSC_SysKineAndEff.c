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
 *          File:  TSC_SysKineAndEff.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_SysKineAndEff.h"
#include "TSC_SysKineAndEff.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_SysKineAndEff_Rte_Read_CmplncErrPinionToHw_Val(float32 *data)
{
  return Rte_Read_CmplncErrPinionToHw_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
{
  return Rte_Read_MotAgCumvAlgndMrf_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Read_PinionAg_Val(float32 *data)
{
  return Rte_Read_PinionAg_Val(data);
}




Std_ReturnType TSC_SysKineAndEff_Rte_Write_HwAg_Val(float32 data)
{
  return Rte_Write_HwAg_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_HwVel_Val(float32 data)
{
  return Rte_Write_HwVel_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_MotAgToRackPosnInstsRat_Val(float32 data)
{
  return Rte_Write_MotAgToRackPosnInstsRat_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_MotToRackFInstsRat_Val(float32 data)
{
  return Rte_Write_MotToRackFInstsRat_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_MotToRackInstsEff_Val(float32 data)
{
  return Rte_Write_MotToRackInstsEff_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_PinionAgToRackInstsEff_Val(float32 data)
{
  return Rte_Write_PinionAgToRackInstsEff_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_PinionAgToRackPosnInstsRat_Val(float32 data)
{
  return Rte_Write_PinionAgToRackPosnInstsRat_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_PinionTqToRackFInstsRat_Val(float32 data)
{
  return Rte_Write_PinionTqToRackFInstsRat_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_PinionVel_Val(float32 data)
{
  return Rte_Write_PinionVel_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_RackPosn_Val(float32 data)
{
  return Rte_Write_RackPosn_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_RackVel_Val(float32 data)
{
  return Rte_Write_RackVel_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_RoadWhlAg_Val(float32 data)
{
  return Rte_Write_RoadWhlAg_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_SteerArmLen_Val(float32 data)
{
  return Rte_Write_SteerArmLen_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_SysAssiTqRat_Val(float32 data)
{
  return Rte_Write_SysAssiTqRat_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_SysKineRat_Val(float32 data)
{
  return Rte_Write_SysKineRat_Val(data);
}

Std_ReturnType TSC_SysKineAndEff_Rte_Write_SysTqRat_Val(float32 data)
{
  return Rte_Write_SysTqRat_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_SysKineAndEff_Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val(void)
{
  return (float32 ) Rte_Prm_SysKineAndEffCmplncErrDerivtvCutOffFrq_Val();
}
Ary1D_s15p0_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotAgScaX_Ary1D(void)
{
  return (Ary1D_s15p0_21 *) Rte_Prm_SysKineAndEffMotAgScaX_Ary1D();
}
Ary1D_u4p12_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(void)
{
  return (Ary1D_u4p12_21 *) Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D();
}
Ary1D_u1p15_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D(void)
{
  return (Ary1D_u1p15_21 *) Rte_Prm_SysKineAndEffMotToRackEffScaY_Ary1D();
}
Ary1D_u5p11_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(void)
{
  return (Ary1D_u5p11_21 *) Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D();
}
Ary1D_u1p15_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(void)
{
  return (Ary1D_u1p15_21 *) Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D();
}
Ary1D_s8p7_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffRackPosScaY_Ary1D(void)
{
  return (Ary1D_s8p7_21 *) Rte_Prm_SysKineAndEffRackPosScaY_Ary1D();
}
Ary1D_s2p13_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(void)
{
  return (Ary1D_s2p13_21 *) Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D();
}
Ary1D_u1p15_21 * TSC_SysKineAndEff_Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(void)
{
  return (Ary1D_u1p15_21 *) Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D();
}


     /* SysKineAndEff */
      /* SysKineAndEff */

/** Per Instance Memories */
float32 *TSC_SysKineAndEff_Rte_Pim_CmplncErrDerivtvPrev(void)
{
  return Rte_Pim_CmplncErrDerivtvPrev();
}
float32 *TSC_SysKineAndEff_Rte_Pim_CmplncErrPinionToHwPrev(void)
{
  return Rte_Pim_CmplncErrPinionToHwPrev();
}



