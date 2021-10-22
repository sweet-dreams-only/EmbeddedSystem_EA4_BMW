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
 *          File:  TSC_BmwHwTqOvrlArbn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwHwTqOvrlArbn.h"
#include "TSC_BmwHwTqOvrlArbn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_BmwDrvgDynErrIfActv_Logl(boolean *data)
{
  return Rte_Read_BmwDrvgDynErrIfActv_Logl(data);
}

Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_BmwTarHwTqOvrl_Val(float32 *data)
{
  return Rte_Read_BmwTarHwTqOvrl_Val(data);
}

Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
{
  return Rte_Read_BmwTarHwTqOvrlQlfr_Val(data);
}

Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
{
  return Rte_Read_DrvgDynIfSt_Val(data);
}

Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_HwTqOvrlCmdEna_Logl(boolean *data)
{
  return Rte_Read_HwTqOvrlCmdEna_Logl(data);
}

Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Write_HwTqCmdOvrl_Val(float32 data)
{
  return Rte_Write_HwTqCmdOvrl_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwHwTqOvrlArbn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwTqOvrlArbnCmdErrThd_Val();
}
float32  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwTqOvrlArbnOutpTqCmdLim_Val();
}
float32  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRampRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwHwTqOvrlArbnRampRate_Val();
}
uint16  TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwHwTqOvrlArbnRefTiThd_Val();
}
Ary1D_u4p12_6 * TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D(void)
{
  return (Ary1D_u4p12_6 *) Rte_Prm_BmwHwTqOvrlArbnHwTqThdY_Ary1D();
}
Ary1D_u9p7_6 * TSC_BmwHwTqOvrlArbn_Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D(void)
{
  return (Ary1D_u9p7_6 *) Rte_Prm_BmwHwTqOvrlArbnVehSpdX_Ary1D();
}


     /* BmwHwTqOvrlArbn */
      /* BmwHwTqOvrlArbn */

/** Per Instance Memories */
float32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_ArbdHwTqOvrlLtch(void)
{
  return Rte_Pim_ArbdHwTqOvrlLtch();
}
float32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_HwTqOvrlScaFacStVari(void)
{
  return Rte_Pim_HwTqOvrlScaFacStVari();
}
float32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevArbdHwTqOvrl(void)
{
  return Rte_Pim_PrevArbdHwTqOvrl();
}
uint32 *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrTmr(void)
{
  return Rte_Pim_FctlErrTmr();
}
boolean *TSC_BmwHwTqOvrlArbn_Rte_Pim_FctlErrActv(void)
{
  return Rte_Pim_FctlErrActv();
}
boolean *TSC_BmwHwTqOvrlArbn_Rte_Pim_PrevFctlErr(void)
{
  return Rte_Pim_PrevFctlErr();
}



