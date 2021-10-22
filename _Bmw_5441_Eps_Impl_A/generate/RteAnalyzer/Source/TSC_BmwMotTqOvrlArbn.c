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
 *          File:  TSC_BmwMotTqOvrlArbn.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMotTqOvrlArbn.h"
#include "TSC_BmwMotTqOvrlArbn.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
{
  return Rte_Read_BmwNearStillVehSpdSts_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_BmwOutpTqOvrlCmd_Val(float32 *data)
{
  return Rte_Read_BmwOutpTqOvrlCmd_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 *data)
{
  return Rte_Read_BmwTrfcJamAssiDampgSt_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_DrvgDynActv_Logl(boolean *data)
{
  return Rte_Read_DrvgDynActv_Logl(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnActv_Logl(boolean *data)
{
  return Rte_Read_HwOscnActv_Logl(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnCmd_Val(float32 *data)
{
  return Rte_Read_HwOscnCmd_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
{
  return Rte_Read_HwOscnDcThdExcdd_Logl(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PinionCentrLrnCmd_Val(float32 *data)
{
  return Rte_Read_PinionCentrLrnCmd_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
{
  return Rte_Read_PinionCentrLrnEna_Logl(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PosnServoCmd_Val(float32 *data)
{
  return Rte_Read_PosnServoCmd_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PosnServoEna_Logl(boolean *data)
{
  return Rte_Read_PosnServoEna_Logl(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_PullCmpCmd_Val(float32 *data)
{
  return Rte_Read_PullCmpCmd_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_TrfcJamAssiCmd_Val(float32 *data)
{
  return Rte_Read_TrfcJamAssiCmd_Val(data);
}

Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Write_MotTqOvrlCmd_Val(float32 data)
{
  return Rte_Write_MotTqOvrlCmd_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwMotTqOvrlArbn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val();
}
float32  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val();
}
float32  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val();
}
uint16  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val();
}
uint16  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val();
}
uint16  TSC_BmwMotTqOvrlArbn_Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val();
}


     /* BmwMotTqOvrlArbn */
      /* BmwMotTqOvrlArbn */

/** Per Instance Memories */
uint32 *TSC_BmwMotTqOvrlArbn_Rte_Pim_BmwNearStillVehSpdStsCdnRefTi(void)
{
  return Rte_Pim_BmwNearStillVehSpdStsCdnRefTi();
}
uint32 *TSC_BmwMotTqOvrlArbn_Rte_Pim_MfgModCmdCdnRefTi(void)
{
  return Rte_Pim_MfgModCmdCdnRefTi();
}
uint32 *TSC_BmwMotTqOvrlArbn_Rte_Pim_VehSpdCdnRefTi(void)
{
  return Rte_Pim_VehSpdCdnRefTi();
}
boolean *TSC_BmwMotTqOvrlArbn_Rte_Pim_FctlErrStVari(void)
{
  return Rte_Pim_FctlErrStVari();
}



