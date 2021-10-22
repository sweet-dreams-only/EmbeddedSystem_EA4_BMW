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
 *          File:  TSC_BmwDiagcSrvHndlg.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwDiagcSrvHndlg.h"
#include "TSC_BmwDiagcSrvHndlg.h"








Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDst_Val(uint32 *data)
{
  return Rte_Read_BmwOdomDst_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDstVld_Logl(boolean *data)
{
  return Rte_Read_BmwOdomDstVld_Logl(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_EcuTFild_Val(float32 *data)
{
  return Rte_Read_EcuTFild_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 *data)
{
  return Rte_Read_BmwBasPtlNetCtrl_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
{
  return Rte_Read_BmwVehCdn_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BrdgVltg_Val(float32 *data)
{
  return Rte_Read_BrdgVltg_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Write_LockToLockEna_Logl(boolean data)
{
  return Rte_Write_LockToLockEna_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwVel_Val(float32 *data)
{
  return Rte_Read_HwVel_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data)
{
  return Rte_Read_LongTermRackCentrCmpl_Logl(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAgConf_Val(float32 *data)
{
  return Rte_Read_PinionAgConf_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(float32 *data)
{
  return Rte_Read_VehSpd_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
{
  return Rte_Call_GetRefTmr1MicroSec32bit_Oper(RefTmr_Arg);
}
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
{
  return Rte_Call_GetTiSpan1MicroSec32bit_Oper(RefTmr_Arg, TiSpan_Arg);
}
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg)
{
  return Rte_Call_SetInpPrm_Oper(TarVel_Arg, TarA_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermVehCentrCmpl_Logl(boolean *data)
{
  return Rte_Read_LongTermVehCentrCmpl_Logl(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAg_Val(float32 *data)
{
  return Rte_Read_PinionAg_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_TurnCntrCorrlnSts_Val(uint8 *data)
{
  return Rte_Read_TurnCntrCorrlnSts_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ProgCntrMaxVal_SetRamBlockStatus(boolean RamBlockStatus)
{
  return Rte_Call_ProgCntrMaxVal_SetRamBlockStatus(RamBlockStatus);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwRackCentrToVehCentrOffs_Val(float32 *data)
{
  return Rte_Read_BmwRackCentrToVehCentrOffs_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(boolean *data)
{
  return Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Write_BmwHwAgOffs_Val(float32 data)
{
  return Rte_Write_BmwHwAgOffs_Val(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_SetVehCentrPosn_Oper(BmwSetVehCentrOffsSts1 *BmwSetVehCentrOffsSts_Arg)
{
  return Rte_Call_SetVehCentrPosn_Oper(BmwSetVehCentrOffsSts_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_TestStamp_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_TestStamp_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_TestStamp_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_TestStamp_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAg_Val(float32 *data)
{
  return Rte_Read_BmwPinionAg_Val(data);
}








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






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_MotTqCmdMrfScad_Val(float32 *data)
{
  return Rte_Read_MotTqCmdMrfScad_Val(data);
}








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
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ProgCntr_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
{
  return Rte_Call_ProgCntr_GetErrorStatus(ErrorStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
{
  return Rte_Read_DrvgDynIfSt_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_GetNtcActv_Oper(NtcNr1 NtcNr, boolean *NtcActv)
{
  return Rte_Call_GetNtcActv_Oper(NtcNr, NtcActv);
}


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






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgErrPrsnt_Logl(boolean *data)
{
  return Rte_Read_RackCentrMotAgErrPrsnt_Logl(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_TotRackTrvl_Val(float32 *data)
{
  return Rte_Read_TotRackTrvl_Val(data);
}








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
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper(void)
{
  return Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper();
}
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_ClrVehCentrPosn_Oper(void)
{
  return Rte_Call_ClrVehCentrPosn_Oper();
}
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotRev_Oper(void)
{
  return Rte_Call_RstRackCentrMotRev_Oper();
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrCmpl_Logl(boolean *data)
{
  return Rte_Read_RackCentrCmpl_Logl(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgVld_Logl(boolean *data)
{
  return Rte_Read_RackCentrMotAgVld_Logl(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
{
  return Rte_Read_BmwPinionAgQlfr_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotAg_Oper(void)
{
  return Rte_Call_RstRackCentrMotAg_Oper();
}


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






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_HwTqIdptSig_Val(uint8 *data)
{
  return Rte_Read_HwTqIdptSig_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionCentrLrnHwTrvl_Val(float32 *data)
{
  return Rte_Read_PinionCentrLrnHwTrvl_Val(data);
}

Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Read_PinionCentrLrnSt_Val(uint8 *data)
{
  return Rte_Read_PinionCentrLrnSt_Val(data);
}








     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_BmwDiagcSrvHndlg_Rte_Call_MilesKmEeprom_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_MilesKmEeprom_SetRamBlockStatus(RamBlockStatus_Arg);
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






uint16  TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue(void)
{
  return (uint16 ) Rte_CData_NvmProgCntr_DefaultValue();
}
uint16  TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft(void)
{
  return (uint16 ) Rte_CData_ProgCntrMaxValDft();
}

     /* BmwDiagcSrvHndlg */
      /* BmwDiagcSrvHndlg */

/** Per Instance Memories */
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl(void)
{
  return Rte_Pim_LrndPinionCentrHwTrvl();
}
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt(void)
{
  return Rte_Pim_RoutineHwPosStrt();
}
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA(void)
{
  return Rte_Pim_TarHwA();
}
float32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel(void)
{
  return Rte_Pim_TarHwVel();
}
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi(void)
{
  return Rte_Pim_HandsONAbortTi();
}
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi(void)
{
  return Rte_Pim_HandsONStrtTi();
}
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi(void)
{
  return Rte_Pim_HwAgAbortTi();
}
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi(void)
{
  return Rte_Pim_HwVelAbortTi();
}
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom(void)
{
  return Rte_Pim_MilesKmEeprom();
}
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi(void)
{
  return Rte_Pim_OperStEnaWaitTi();
}
uint32 *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom(void)
{
  return Rte_Pim_PrevCycleMilesKmEeprom();
}
uint16 *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid(void)
{
  return Rte_Pim_ActvRid();
}
uint16 *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr(void)
{
  return Rte_Pim_ProgCntr();
}
uint16 *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal(void)
{
  return Rte_Pim_ProgCntrMaxVal();
}
uint8 *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts(void)
{
  return Rte_Pim_LockToLockRountineSts();
}
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort(void)
{
  return Rte_Pim_HandsONAbort();
}
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt(void)
{
  return Rte_Pim_HandsONStrt();
}
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes(void)
{
  return Rte_Pim_HwAgOrHwVelChkRes();
}
boolean *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk(void)
{
  return Rte_Pim_OperStPreStrtChk();
}
uint8 *TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(void)
{
  return Rte_Pim_TestStamp();
}



