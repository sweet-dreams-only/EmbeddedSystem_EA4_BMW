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
 *          File:  TSC_BmwDrvgDynStMac.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwDrvgDynStMac.h"
#include "TSC_BmwDrvgDynStMac.h"








Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
{
  return Rte_Read_MotTqCmdPwrLimd_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynEnaReq_Logl(boolean *data)
{
  return Rte_Read_BmwDrvgDynEnaReq_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 *data)
{
  return Rte_Read_BmwDrvgDynFacQlfr_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwDrvgDynFacQlfrVld_Logl(boolean *data)
{
  return Rte_Read_BmwDrvgDynFacQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 *data)
{
  return Rte_Read_BmwTarHwTqOvrlQlfr_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(boolean *data)
{
  return Rte_Read_BmwTarHwTqOvrlQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 *data)
{
  return Rte_Read_BmwTarSteerTqDrvrActrQlfr_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean *data)
{
  return Rte_Read_BmwTarSteerTqDrvrActrQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 *data)
{
  return Rte_Read_BmwTrfcJamAssiDampgStReq_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(boolean *data)
{
  return Rte_Read_BmwTrfcJamAssiDampgStReqVld_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
{
  return Rte_Read_BmwVehCdn_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_DampgCmdSca_Val(float32 *data)
{
  return Rte_Read_DampgCmdSca_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data)
{
  return Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean *data)
{
  return Rte_Read_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_EffortCmdSca_Val(float32 *data)
{
  return Rte_Read_EffortCmdSca_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_MotTqOvrlCmd_Val(float32 *data)
{
  return Rte_Read_MotTqOvrlCmd_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_RtnCmdSca_Val(float32 *data)
{
  return Rte_Read_RtnCmdSca_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_StsSteerAssi_Val(StsSteerAssi1 *data)
{
  return Rte_Read_StsSteerAssi_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Read_SysStFltOutpReqDi_Logl(boolean *data)
{
  return Rte_Read_SysStFltOutpReqDi_Logl(data);
}




Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Write_DrvgDynActv_Logl(boolean data)
{
  return Rte_Write_DrvgDynActv_Logl(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Write_DrvgDynIfSt_Val(DrvgDynIfSt1 data)
{
  return Rte_Write_DrvgDynIfSt_Val(data);
}

Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Write_OutpTqOvrlRampInEna_Logl(boolean data)
{
  return Rte_Write_OutpTqOvrlRampInEna_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr100MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwDrvgDynStMac_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan100MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val(void)
{
  return (float32 ) Rte_Prm_BmwDrvgDynStMacDampgCmdScaDft_Val();
}
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val(void)
{
  return (float32 ) Rte_Prm_BmwDrvgDynStMacEffortCmdScaDft_Val();
}
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlActvtThd_Val();
}
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val(void)
{
  return (float32 ) Rte_Prm_BmwDrvgDynStMacMotTqCmdOvrlDeactvtThd_Val();
}
float32  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val(void)
{
  return (float32 ) Rte_Prm_BmwDrvgDynStMacRtnCmdScaDft_Val();
}
uint16  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwDrvgDynStMacAssiLvlThd_Val();
}
uint16  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwDrvgDynStMacErrIfTmrThd_Val();
}
uint16  TSC_BmwDrvgDynStMac_Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val(void)
{
  return (uint16 ) Rte_Prm_BmwDrvgDynStMacVehCdnTmrThd_Val();
}


     /* BmwDrvgDynStMac */
      /* BmwDrvgDynStMac */

/** Per Instance Memories */
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlActvtTi(void)
{
  return Rte_Pim_AssiLvlActvtTi();
}
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_AssiLvlDeactvtTi(void)
{
  return Rte_Pim_AssiLvlDeactvtTi();
}
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_ErrIfTi(void)
{
  return Rte_Pim_ErrIfTi();
}
uint32 *TSC_BmwDrvgDynStMac_Rte_Pim_VehCdnTi(void)
{
  return Rte_Pim_VehCdnTi();
}
uint8 *TSC_BmwDrvgDynStMac_Rte_Pim_StMacSt(void)
{
  return Rte_Pim_StMacSt();
}
boolean *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnActvt(void)
{
  return Rte_Pim_MotTqCmdPwrLimdCdnActvt();
}
boolean *TSC_BmwDrvgDynStMac_Rte_Pim_MotTqCmdPwrLimdCdnDeactvt(void)
{
  return Rte_Pim_MotTqCmdPwrLimdCdnDeactvt();
}



