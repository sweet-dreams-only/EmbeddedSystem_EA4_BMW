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
 *          File:  TSC_LrnPinionCentr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_LrnPinionCentr.h"
#include "TSC_LrnPinionCentr.h"








Std_ReturnType TSC_LrnPinionCentr_Rte_Read_HwAg_Val(float32 *data)
{
  return Rte_Read_HwAg_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_LrnPinionCentr_Rte_Read_MotVelCrf_Val(float32 *data)
{
  return Rte_Read_MotVelCrf_Val(data);
}

Std_ReturnType TSC_LrnPinionCentr_Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
{
  return Rte_Read_PinionCentrLrnEna_Logl(data);
}




Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnCmd_Val(float32 data)
{
  return Rte_Write_PinionCentrLrnCmd_Val(data);
}

Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnHwCentr_Val(float32 data)
{
  return Rte_Write_PinionCentrLrnHwCentr_Val(data);
}

Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnHwTrvl_Val(float32 data)
{
  return Rte_Write_PinionCentrLrnHwTrvl_Val(data);
}

Std_ReturnType TSC_LrnPinionCentr_Rte_Write_PinionCentrLrnSt_Val(uint8 data)
{
  return Rte_Write_PinionCentrLrnSt_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_LrnPinionCentr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_LrnPinionCentr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */
float32 TSC_LrnPinionCentr_Rte_IrvRead_LrnPinionCentrPer1_TarA(void)
{
return Rte_IrvRead_LrnPinionCentrPer1_TarA();
}
float32 TSC_LrnPinionCentr_Rte_IrvRead_LrnPinionCentrPer1_TarVel(void)
{
return Rte_IrvRead_LrnPinionCentrPer1_TarVel();
}













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */

void TSC_LrnPinionCentr_Rte_IrvWrite_SetInpPrm_Oper_TarA(float32 data)
{
  Rte_IrvWrite_SetInpPrm_Oper_TarA( data);
}
void TSC_LrnPinionCentr_Rte_IrvWrite_SetInpPrm_Oper_TarVel(float32 data)
{
  Rte_IrvWrite_SetInpPrm_Oper_TarVel( data);
}




float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrDampgCtrlGain_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrDampgCtrlGain_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTq_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrHldTq_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqErrThd_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrHldTqErrThd_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHldTqRateLim_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrHldTqRateLim_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrHwPosnErrThd_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrHwPosnErrThd_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrIntglCtrlGain_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrIntglCtrlGain_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMaxTqCmd_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrMaxTqCmd_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMinMotTq_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrMinMotTq_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrMotVelThd_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrMotVelThd_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrPropCtrlGain_Val(void)
{
  return (float32 ) Rte_Prm_LrnPinionCentrPropCtrlGain_Val();
}
float32  TSC_LrnPinionCentr_Rte_Prm_SysGlbPrmSysKineRat_Val(void)
{
  return (float32 ) Rte_Prm_SysGlbPrmSysKineRat_Val();
}
uint16  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiOutThd_Val(void)
{
  return (uint16 ) Rte_Prm_LrnPinionCentrTiOutThd_Val();
}
uint16  TSC_LrnPinionCentr_Rte_Prm_LrnPinionCentrTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_LrnPinionCentrTiThd_Val();
}


     /* LrnPinionCentr */
      /* LrnPinionCentr */

/** Per Instance Memories */
float32 *TSC_LrnPinionCentr_Rte_Pim_MaxHwPosnPrev(void)
{
  return Rte_Pim_MaxHwPosnPrev();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_MinHwPosnPrev(void)
{
  return Rte_Pim_MinHwPosnPrev();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwCentrPrev(void)
{
  return Rte_Pim_PinionCentrLrnHwCentrPrev();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnHwTrvlPrev(void)
{
  return Rte_Pim_PinionCentrLrnHwTrvlPrev();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1PosnErrRateLim(void)
{
  return Rte_Pim_StCtrl1PosnErrRateLim();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TqErrRateLim(void)
{
  return Rte_Pim_StCtrl2TqErrRateLim();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3PosnErrRateLim(void)
{
  return Rte_Pim_StCtrl3PosnErrRateLim();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TqErrRateLim(void)
{
  return Rte_Pim_StCtrl3TqErrRateLim();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TqErrRateLim(void)
{
  return Rte_Pim_StCtrl4TqErrRateLim();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5IntglEnaOutpPrev(void)
{
  return Rte_Pim_StCtrl5IntglEnaOutpPrev();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5PosnErrRateLim(void)
{
  return Rte_Pim_StCtrl5PosnErrRateLim();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TqErrRateLim(void)
{
  return Rte_Pim_StCtrl5TqErrRateLim();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_TarHwAg(void)
{
  return Rte_Pim_TarHwAg();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_TarMotVel(void)
{
  return Rte_Pim_TarMotVel();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_TqCmdEstimdPrev(void)
{
  return Rte_Pim_TqCmdEstimdPrev();
}
float32 *TSC_LrnPinionCentr_Rte_Pim_dLrnPinionCentrHwPosnCmd(void)
{
  return Rte_Pim_dLrnPinionCentrHwPosnCmd();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrARefTi(void)
{
  return Rte_Pim_StCtrl1TmrARefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1TmrBRefTi(void)
{
  return Rte_Pim_StCtrl1TmrBRefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrARefTi(void)
{
  return Rte_Pim_StCtrl2TmrARefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2TmrBRefTi(void)
{
  return Rte_Pim_StCtrl2TmrBRefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrARefTi(void)
{
  return Rte_Pim_StCtrl3TmrARefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3TmrBRefTi(void)
{
  return Rte_Pim_StCtrl3TmrBRefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrARefTi(void)
{
  return Rte_Pim_StCtrl4TmrARefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4TmrBRefTi(void)
{
  return Rte_Pim_StCtrl4TmrBRefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrARefTi(void)
{
  return Rte_Pim_StCtrl5TmrARefTi();
}
uint32 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5TmrBRefTi(void)
{
  return Rte_Pim_StCtrl5TmrBRefTi();
}
uint8 *TSC_LrnPinionCentr_Rte_Pim_StEstimdPrev(void)
{
  return Rte_Pim_StEstimdPrev();
}
boolean *TSC_LrnPinionCentr_Rte_Pim_PinionCentrLrnEnaPrev(void)
{
  return Rte_Pim_PinionCentrLrnEnaPrev();
}
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl1RateLimdPosnErrLpFil(void)
{
  return Rte_Pim_StCtrl1RateLimdPosnErrLpFil();
}
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl2RateLimdTqErrLpFil(void)
{
  return Rte_Pim_StCtrl2RateLimdTqErrLpFil();
}
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdPosnErrLpFil(void)
{
  return Rte_Pim_StCtrl3RateLimdPosnErrLpFil();
}
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl3RateLimdTqErrLpFil(void)
{
  return Rte_Pim_StCtrl3RateLimdTqErrLpFil();
}
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl4RateLimdTqErrLpFil(void)
{
  return Rte_Pim_StCtrl4RateLimdTqErrLpFil();
}
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdPosnErrLpFil(void)
{
  return Rte_Pim_StCtrl5RateLimdPosnErrLpFil();
}
FilLpRec1 *TSC_LrnPinionCentr_Rte_Pim_StCtrl5RateLimdTqErrLpFil(void)
{
  return Rte_Pim_StCtrl5RateLimdTqErrLpFil();
}



