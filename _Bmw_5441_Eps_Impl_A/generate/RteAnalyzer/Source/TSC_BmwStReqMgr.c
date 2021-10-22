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
 *          File:  TSC_BmwStReqMgr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwStReqMgr.h"
#include "TSC_BmwStReqMgr.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwStReqMgr_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwStReqMgr_Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
{
  return Rte_Read_BmwVehCdn_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_BmwVehCdnVld_Logl(boolean *data)
{
  return Rte_Read_BmwVehCdnVld_Logl(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data)
{
  return Rte_Read_BmwVehSpdSts_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
{
  return Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_PwrLimrRednFac_Val(float32 *data)
{
  return Rte_Read_PwrLimrRednFac_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
{
  return Rte_Read_SysStFltOutpReqDi_Logl(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_ThermRednFac_Val(float32 *data)
{
  return Rte_Read_ThermRednFac_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}




Std_ReturnType TSC_BmwStReqMgr_Rte_Write_BmwEpsFctSts_Val(BmwEpsFctSts1 data)
{
  return Rte_Write_BmwEpsFctSts_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Write_PwrSplyEnaReq_Logl(boolean data)
{
  return Rte_Write_PwrSplyEnaReq_Logl(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Write_StsDrvrActvy_Val(StsDrvrActvy1 data)
{
  return Rte_Write_StsDrvrActvy_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Write_StsSteerAssi_Val(StsSteerAssi1 data)
{
  return Rte_Write_StsSteerAssi_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Write_SysOperMotTqCmdSca_Val(float32 data)
{
  return Rte_Write_SysOperMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Write_SysOperRampRate_Val(float32 data)
{
  return Rte_Write_SysOperRampRate_Val(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Write_SysStReqEna_Logl(boolean data)
{
  return Rte_Write_SysStReqEna_Logl(data);
}

Std_ReturnType TSC_BmwStReqMgr_Rte_Write_TarEcuSt_Val(SysSt1 data)
{
  return Rte_Write_TarEcuSt_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwStReqMgr_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}
Std_ReturnType TSC_BmwStReqMgr_Rte_Call_IoHwAb_GetGpioMcuEna_Oper(boolean *PinSt_Arg)
{
  return Rte_Call_IoHwAb_GetGpioMcuEna_Oper(PinSt_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrHwTqThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwStReqMgrHwTqThd_Val();
}
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrOperRampRate_Val(void)
{
  return (float32 ) Rte_Prm_BmwStReqMgrOperRampRate_Val();
}
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwStReqMgrStsDrvrActvyTqChgThd_Val();
}
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val(void)
{
  return (float32 ) Rte_Prm_BmwStReqMgrSwtOffSpdLim_Val();
}
float32  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwStReqMgrSysProtnRednFacThd_Val();
}
u16p0  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrAllwToOffThd_Val(void)
{
  return (u16p0 ) Rte_Prm_BmwStReqMgrAllwToOffThd_Val();
}
u16p0  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val(void)
{
  return (u16p0 ) Rte_Prm_BmwStReqMgrDrvrActvTmrThd_Val();
}
uint8  TSC_BmwStReqMgr_Rte_Prm_BmwStReqMgrVehCdnOvrd_Val(void)
{
  return (uint8 ) Rte_Prm_BmwStReqMgrVehCdnOvrd_Val();
}


     /* BmwStReqMgr */
      /* BmwStReqMgr */

/** Per Instance Memories */
float32 *TSC_BmwStReqMgr_Rte_Pim_PrevHwTq(void)
{
  return Rte_Pim_PrevHwTq();
}
uint32 *TSC_BmwStReqMgr_Rte_Pim_BmwVehCdnLvngDurn(void)
{
  return Rte_Pim_BmwVehCdnLvngDurn();
}
uint32 *TSC_BmwStReqMgr_Rte_Pim_DrvrActvRefTmr(void)
{
  return Rte_Pim_DrvrActvRefTmr();
}
uint8 *TSC_BmwStReqMgr_Rte_Pim_PrevTarEcuSt(void)
{
  return Rte_Pim_PrevTarEcuSt();
}



