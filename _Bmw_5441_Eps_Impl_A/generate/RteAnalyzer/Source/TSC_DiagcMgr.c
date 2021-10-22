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
 *          File:  TSC_DiagcMgr.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_DiagcMgr.h"
#include "TSC_DiagcMgr.h"











Std_ReturnType TSC_DiagcMgr_Rte_Write_ClrDiagcFlgProxy_Val(uint8 data)
{
  return Rte_Write_ClrDiagcFlgProxy_Val(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DiagcMgr_Rte_Call_DiagcMgrLtchCntrAry_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_DiagcMgrLtchCntrAry_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_DiagcMgr_Rte_Call_SnpshtDataAry_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_SnpshtDataAry_SetRamBlockStatus(RamBlockStatus_Arg);
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






Std_ReturnType TSC_DiagcMgr_Rte_Read_SwApplCrc_Val(uint32 *data)
{
  return Rte_Read_SwApplCrc_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgr_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */
Std_ReturnType TSC_DiagcMgr_Rte_Call_DiagcMgrApplCrc_SetRamBlockStatus(boolean RamBlockStatus_Arg)
{
  return Rte_Call_DiagcMgrApplCrc_SetRamBlockStatus(RamBlockStatus_Arg);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */









Std_ReturnType TSC_DiagcMgr_Rte_Write_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean data)
{
  return Rte_Write_DiagcStsCtrldShtDwnFltPrsnt_Logl(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Write_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(boolean data)
{
  return Rte_Write_DiagcStsNonRcvrlReqDiFltPrsnt_Logl(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Write_SysDiMotTqCmdSca_Val(float32 data)
{
  return Rte_Write_SysDiMotTqCmdSca_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Write_SysDiRampRate_Val(float32 data)
{
  return Rte_Write_SysDiRampRate_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Write_SysStFltOutpReqDi_Logl(boolean data)
{
  return Rte_Write_SysStFltOutpReqDi_Logl(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl0_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl0_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl1_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl1_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl10_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl10_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl2_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl2_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl3_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl3_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl4_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl4_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl5_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl5_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl6_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl6_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl7_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl7_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl8_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl8_Oper(DiagcData_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetDiagcDataAppl9_Oper(DiagcDataRec2 *DiagcData_Arg)
{
  return Rte_Call_GetDiagcDataAppl9_Oper(DiagcData_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl0_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl0_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl1_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl1_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl10_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl10_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl2_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl2_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl3_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl3_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl4_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl4_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl5_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl5_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl6_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl6_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl7_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl7_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl8_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl8_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcInfoAppl9_Oper(uint8 NtcInfoIdx_Arg, NtcInfoRec4 *NtcInfo_Arg)
{
  return Rte_Call_GetNtcInfoAppl9_Oper(NtcInfoIdx_Arg, NtcInfo_Arg);
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













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl0_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl0_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl1_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl1_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl10_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl10_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl2_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl2_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl3_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl3_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl4_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl4_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl5_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl5_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl6_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl6_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl7_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl7_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl8_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl8_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetNtcDebCntrAppl9_Oper(uint8 DebCntrIdx_Arg, sint16 *DebCntr_Arg)
{
  return Rte_Call_GetNtcDebCntrAppl9_Oper(DebCntrIdx_Arg, DebCntr_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_DiagcMgr_Rte_Read_BrdgVltg_Val(float32 *data)
{
  return Rte_Read_BrdgVltg_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Read_EcuTFild_Val(float32 *data)
{
  return Rte_Read_EcuTFild_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Read_HwTq_Val(float32 *data)
{
  return Rte_Read_HwTq_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Read_IgnCntr_Val(uint32 *data)
{
  return Rte_Read_IgnCntr_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Read_MfgDiagcInhb_Logl(boolean *data)
{
  return Rte_Read_MfgDiagcInhb_Logl(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data)
{
  return Rte_Read_MfgEnaSt_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Read_MotTqCmdMrfScad_Val(float32 *data)
{
  return Rte_Read_MotTqCmdMrfScad_Val(data);
}

Std_ReturnType TSC_DiagcMgr_Rte_Read_SysSt_Val(SysSt1 *data)
{
  return Rte_Read_SysSt_Val(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgr_Rte_Call_GetMcuDiagcSpplData_Oper(uint32 *McuDiagcData1_Arg)
{
  return Rte_Call_GetMcuDiagcSpplData_Oper(McuDiagcData1_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





Ary1D_u16_512 * TSC_DiagcMgr_Rte_Prm_DiagcMgrFltResp_Ary1D(void)
{
  return (Ary1D_u16_512 *) Rte_Prm_DiagcMgrFltResp_Ary1D();
}

uint32  TSC_DiagcMgr_Rte_CData_DiagcMgrApplCrcDft(void)
{
  return (uint32 ) Rte_CData_DiagcMgrApplCrcDft();
}

     /* DiagcMgr */
      /* DiagcMgr */
void TSC_DiagcMgr_Rte_Enter_DiagcMgrExclusiveArea(void)
{
  Rte_Enter_DiagcMgrExclusiveArea();
}
void TSC_DiagcMgr_Rte_Exit_DiagcMgrExclusiveArea(void)
{
  Rte_Exit_DiagcMgrExclusiveArea();
}

/** Per Instance Memories */
uint32 *TSC_DiagcMgr_Rte_Pim_DiagcMgrApplCrc(void)
{
  return Rte_Pim_DiagcMgrApplCrc();
}
uint16 *TSC_DiagcMgr_Rte_Pim_DtcEnaSts(void)
{
  return Rte_Pim_DtcEnaSts();
}
uint8 *TSC_DiagcMgr_Rte_Pim_ClrDiagcFlg(void)
{
  return Rte_Pim_ClrDiagcFlg();
}
uint8 *TSC_DiagcMgr_Rte_Pim_PrevClrDtcFlg(void)
{
  return Rte_Pim_PrevClrDtcFlg();
}
uint8 *TSC_DiagcMgr_Rte_Pim_DiagcMgrLtchCntrAry(void)
{
  return Rte_Pim_DiagcMgrLtchCntrAry();
}
NtcFltInfoRec2 *TSC_DiagcMgr_Rte_Pim_DiagcMgrNtcFltAry(void)
{
  return Rte_Pim_DiagcMgrNtcFltAry();
}
uint8 *TSC_DiagcMgr_Rte_Pim_DtcIdxPrevSts(void)
{
  return Rte_Pim_DtcIdxPrevSts();
}



