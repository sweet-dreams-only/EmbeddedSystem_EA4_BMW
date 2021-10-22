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
 *          File:  TSC_DiagcMgrProxyAppl9.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_DiagcMgrProxyAppl9.h"
#include "TSC_DiagcMgrProxyAppl9.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgrProxyAppl9_Rte_Call_DiagcMgrIninCore_Oper(uint8 ApplIdx_Arg, uint8 NtcInfoArySize_Arg, NtcInfoRec4 *NtcInfoAry_Arg, DiagcDataRec2 *DiagcData_Arg, DiagcDataRec2 *ProxySetNtcData_Arg)
{
  return Rte_Call_DiagcMgrIninCore_Oper(ApplIdx_Arg, NtcInfoArySize_Arg, NtcInfoAry_Arg, DiagcData_Arg, ProxySetNtcData_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_DiagcMgrProxyAppl9_Rte_Read_ClrDiagcFlgProxy_Val(uint8 *data)
{
  return Rte_Read_ClrDiagcFlgProxy_Val(data);
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
Std_ReturnType TSC_DiagcMgrProxyAppl9_Rte_Call_GetNtcActvCore_Oper(NtcNr1 NtcNr_Arg, boolean *NtcActv_Arg)
{
  return Rte_Call_GetNtcActvCore_Oper(NtcNr_Arg, NtcActv_Arg);
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
Std_ReturnType TSC_DiagcMgrProxyAppl9_Rte_Call_GetNtcQlfrStsCore_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
{
  return Rte_Call_GetNtcQlfrStsCore_Oper(NtcNr_Arg, NtcQlfr_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgrProxyAppl9_Rte_Call_GetNtcStsCore_Oper(NtcNr1 NtcNr_Arg, uint8 *NtcInfoSts_Arg)
{
  return Rte_Call_GetNtcStsCore_Oper(NtcNr_Arg, NtcInfoSts_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_DiagcMgrProxyAppl9_Rte_Call_SetNtcStsCore_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, DiagcDataRec2 *DiagcData_Arg, DiagcDataRec2 *ProxySetNtcData_Arg, NtcInfoRec4 *NtcInfo_Arg, sint16 *NtcInfoDebCntr_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg, boolean SpclSnpshtDataPrsnt_Arg)
{
  return Rte_Call_SetNtcStsCore_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg, DiagcData_Arg, ProxySetNtcData_Arg, NtcInfo_Arg, NtcInfoDebCntr_Arg, SpclSnpshtData0_Arg, SpclSnpshtData1_Arg, SpclSnpshtData2_Arg, SpclSnpshtDataPrsnt_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





Ary1D_u16_512 * TSC_DiagcMgrProxyAppl9_Rte_Prm_DiagcMgrFltResp_Ary1D(void)
{
  return (Ary1D_u16_512 *) Rte_Prm_DiagcMgrFltResp_Ary1D();
}


     /* DiagcMgrProxyAppl9 */
      /* DiagcMgrProxyAppl9 */
void TSC_DiagcMgrProxyAppl9_Rte_Enter_DiagcMgrProxyAppl9(void)
{
  Rte_Enter_DiagcMgrProxyAppl9();
}
void TSC_DiagcMgrProxyAppl9_Rte_Exit_DiagcMgrProxyAppl9(void)
{
  Rte_Exit_DiagcMgrProxyAppl9();
}

/** Per Instance Memories */
uint8 *TSC_DiagcMgrProxyAppl9_Rte_Pim_PrevClrNtcFlg9(void)
{
  return Rte_Pim_PrevClrNtcFlg9();
}
NtcInfoRec4 *TSC_DiagcMgrProxyAppl9_Rte_Pim_DiagcMgrNtcInfo9Ary(void)
{
  return Rte_Pim_DiagcMgrNtcInfo9Ary();
}
sint16 *TSC_DiagcMgrProxyAppl9_Rte_Pim_DiagcMgrNtcInfo9DebCntrAry(void)
{
  return Rte_Pim_DiagcMgrNtcInfo9DebCntrAry();
}
DiagcDataRec2 *TSC_DiagcMgrProxyAppl9_Rte_Pim_DiagcData9(void)
{
  return Rte_Pim_DiagcData9();
}
DiagcDataRec2 *TSC_DiagcMgrProxyAppl9_Rte_Pim_ProxySetNtcData9(void)
{
  return Rte_Pim_ProxySetNtcData9();
}



