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
 *          File:  TSC_Dlog.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Dlog.h"
#include "TSC_Dlog.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_Dlog_Rte_Call_Coding_Svk_GetCafIds(uint8 *cafIds, uint16 *numberOfCafIds)
{
  return Rte_Call_Coding_Svk_GetCafIds(cafIds, numberOfCafIds);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_ReadBlock(NvM_DstPtrType DstPtr)
{
  return Rte_Call_NvMService_DlogSvkEntry_ReadBlock(DstPtr);
}
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(uint8 DataIndex)
{
  return Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(DataIndex);
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









Std_ReturnType TSC_Dlog_Rte_Write_ProgId_progId(const uint8 *data)
{
  return Rte_Write_ProgId_progId(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */

Std_ReturnType TSC_Dlog_Rte_Switch_LifeCycle_Mode(Dlog_LifeCycleRequestType mode)
{
  return Rte_Switch_LifeCycle_Mode( mode);
}

Std_ReturnType TSC_Dlog_Rte_SwitchAck_LifeCycle_Mode(void)
{
  return Rte_SwitchAck_LifeCycle_Mode();
}


     /* Inter-Runnable variables */






Dlog_LifeCycleRequestType TSC_Dlog_Rte_IRead_Dlog_ModeSwitchRequestLifeCycle_LifeCycleRequest_requestMode(void)
{
  return Rte_IRead_Dlog_ModeSwitchRequestLifeCycle_LifeCycleRequest_requestMode();
}







     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogProgData_WriteBlock(NvM_SrcPtrType SrcPtr)
{
  return Rte_Call_NvMService_DlogProgData_WriteBlock(SrcPtr);
}
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_WriteBlock(NvM_SrcPtrType SrcPtr)
{
  return Rte_Call_NvMService_DlogSvkEntry_WriteBlock(SrcPtr);
}
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkHistory_GetErrorStatus(NvM_RequestResultType *RequestResultPtr)
{
  return Rte_Call_NvMService_DlogSvkHistory_GetErrorStatus(RequestResultPtr);
}
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkHistory_WriteBlock(NvM_SrcPtrType SrcPtr)
{
  return Rte_Call_NvMService_DlogSvkHistory_WriteBlock(SrcPtr);
}


     /* Mode Interfaces */
Dlog_LifeCycleRequestType TSC_Dlog_Rte_Mode_LifeCycle_Mode(Dlog_LifeCycleRequestType *previousMode, Dlog_LifeCycleRequestType *nextMode)
{
  return Rte_Mode_LifeCycle_Mode( previousMode, nextMode);
}




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Dlog_Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(boolean ProtectionEnabled)
{
  return Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(ProtectionEnabled);
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







     /* Dlog */
      /* Dlog */



