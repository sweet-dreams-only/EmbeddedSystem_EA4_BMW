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
 *          File:  TSC_LrndRackCentr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_LrndRackCentr.h"
#include "TSC_LrndRackCentr.h"








Std_ReturnType TSC_LrndRackCentr_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}




Std_ReturnType TSC_LrndRackCentr_Rte_Write_LongTermRackCentrCmpl_Logl(boolean data)
{
  return Rte_Write_LongTermRackCentrCmpl_Logl(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrCmpl_Logl(boolean data)
{
  return Rte_Write_RackCentrCmpl_Logl(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrMotAgErrPrsnt_Logl(boolean data)
{
  return Rte_Write_RackCentrMotAgErrPrsnt_Logl(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrMotAgVld_Logl(boolean data)
{
  return Rte_Write_RackCentrMotAgVld_Logl(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Write_RackCentrPinionAg_Val(float32 data)
{
  return Rte_Write_RackCentrPinionAg_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_LrndRackCentrNvm_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_LrndRackCentr_Rte_Read_MotTqCmd_Val(float32 *data)
{
  return Rte_Read_MotTqCmd_Val(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
{
  return Rte_Read_PinionCentrLrnEna_Logl(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnHwCentr_Val(float32 *data)
{
  return Rte_Read_PinionCentrLrnHwCentr_Val(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnHwTrvl_Val(float32 *data)
{
  return Rte_Read_PinionCentrLrnHwTrvl_Val(data);
}

Std_ReturnType TSC_LrndRackCentr_Rte_Read_PinionCentrLrnSt_Val(uint8 *data)
{
  return Rte_Read_PinionCentrLrnSt_Val(data);
}




Std_ReturnType TSC_LrndRackCentr_Rte_Write_TotRackTrvl_Val(float32 data)
{
  return Rte_Write_TotRackTrvl_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_LrndRackCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_LrndRackCentr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */
Std_ReturnType TSC_LrndRackCentr_Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_LrndRackCentrNvm_SetRamBlockStatus(RamBlockStatus_Arg);
}


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





float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrConfTrvlThd_Val(void)
{
  return (float32 ) Rte_Prm_LrndRackCentrConfTrvlThd_Val();
}
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrHwAgFilFrq_Val(void)
{
  return (float32 ) Rte_Prm_LrndRackCentrHwAgFilFrq_Val();
}
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val(void)
{
  return (float32 ) Rte_Prm_LrndRackCentrMinMaxAdjmtFac_Val();
}
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotTqThd_Val(void)
{
  return (float32 ) Rte_Prm_LrndRackCentrMotTqThd_Val();
}
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrMotVelThd_Val(void)
{
  return (float32 ) Rte_Prm_LrndRackCentrMotVelThd_Val();
}
float32  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val(void)
{
  return (float32 ) Rte_Prm_LrndRackCentrRackCentrPosnChgAllwd_Val();
}
float32  TSC_LrndRackCentr_Rte_Prm_SysGlbPrmSysKineRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysKineRat_Val();
}
uint16  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_LrndRackCentrTiThd_Val();
}
boolean  TSC_LrndRackCentr_Rte_Prm_LrndRackCentrAllwManIniLrng_Logl(void)
{
  return (boolean ) Rte_Prm_LrndRackCentrAllwManIniLrng_Logl();
}


     /* LrndRackCentr */
      /* LrndRackCentr */

/** Per Instance Memories */
float32 *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEot(void)
{
  return Rte_Pim_ManLrndRackCentrNegEot();
}
float32 *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEot(void)
{
  return Rte_Pim_ManLrndRackCentrPosEot();
}
float32 *TSC_LrndRackCentr_Rte_Pim_RackCentrPinionAgPrev(void)
{
  return Rte_Pim_RackCentrPinionAgPrev();
}
uint32 *TSC_LrndRackCentr_Rte_Pim_RackCentrMaxTmr(void)
{
  return Rte_Pim_RackCentrMaxTmr();
}
uint32 *TSC_LrndRackCentr_Rte_Pim_RackCentrMinTmr(void)
{
  return Rte_Pim_RackCentrMinTmr();
}
boolean *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrNegEotVld(void)
{
  return Rte_Pim_ManLrndRackCentrNegEotVld();
}
boolean *TSC_LrndRackCentr_Rte_Pim_ManLrndRackCentrPosEotVld(void)
{
  return Rte_Pim_ManLrndRackCentrPosEotVld();
}
FilLpRec1 *TSC_LrndRackCentr_Rte_Pim_HwAgFil(void)
{
  return Rte_Pim_HwAgFil();
}
LrndRackCentrNvmRec1 *TSC_LrndRackCentr_Rte_Pim_LrndRackCentr(void)
{
  return Rte_Pim_LrndRackCentr();
}



