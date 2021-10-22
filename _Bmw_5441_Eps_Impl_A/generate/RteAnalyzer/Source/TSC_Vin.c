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
 *          File:  TSC_Vin.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Vin.h"
#include "TSC_Vin.h"








Vin_LifeCycleRequestType TSC_Vin_Rte_IRead_Vin_LifeCycleModeRequest_LifeCycleRequest_requestMode(void)
{
  return Rte_IRead_Vin_LifeCycleModeRequest_LifeCycleRequest_requestMode();
}







     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */
Vin_LifeCycleRequestType TSC_Vin_Rte_Mode_LifeCycle_Mode(Vin_LifeCycleRequestType *previousMode, Vin_LifeCycleRequestType *nextMode)
{
  return Rte_Mode_LifeCycle_Mode( previousMode, nextMode);
}

Std_ReturnType TSC_Vin_Rte_Switch_LifeCycle_Mode(Vin_LifeCycleRequestType mode)
{
  return Rte_Switch_LifeCycle_Mode( mode);
}



     /* Inter-Runnable variables */







Std_ReturnType TSC_Vin_Rte_Send_VinRequest_RequestMessageIdentifier(uint16 data)
{
  return Rte_Send_VinRequest_RequestMessageIdentifier(data);
}






     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_GetErrorStatus(NvM_RequestResultType *RequestResultPtr)
{
  return Rte_Call_NvMService_Vin_GetErrorStatus(RequestResultPtr);
}
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_ReadBlock(NvM_DstPtrType DstPtr)
{
  return Rte_Call_NvMService_Vin_ReadBlock(DstPtr);
}


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_WriteBlock(NvM_SrcPtrType SrcPtr)
{
  return Rte_Call_NvMService_Vin_WriteBlock(SrcPtr);
}


     /* Mode Interfaces */

Std_ReturnType TSC_Vin_Rte_Switch_VinChangeIndicator_ChangeIndicator(uint8 mode)
{
  return Rte_Switch_VinChangeIndicator_ChangeIndicator( mode);
}

Std_ReturnType TSC_Vin_Rte_SwitchAck_VinChangeIndicator_ChangeIndicator(void)
{
  return Rte_SwitchAck_VinChangeIndicator_ChangeIndicator();
}


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
uint8 TSC_Vin_Rte_Mode_VinChangeIndicator_ChangeIndicator(void)
{
  return Rte_Mode_VinChangeIndicator_ChangeIndicator();
}




     /* Inter-Runnable variables */






const Vin_ComVinType *TSC_Vin_Rte_IRead_Vin_ReceiveFromCom_ComVin_ComVin(void)
{
  return Rte_IRead_Vin_ReceiveFromCom_ComVin_ComVin();
}



Std_ReturnType TSC_Vin_Rte_Write_Vin_Vin(const Vin_VinType *data)
{
  return Rte_Write_Vin_Vin(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Vin_Rte_Call_DlogEcuInfo_GetVin(uint8 *Vin)
{
  return Rte_Call_DlogEcuInfo_GetVin(Vin);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* Vin */
      /* Vin */
void TSC_Vin_Rte_Enter_VinState(void)
{
  Rte_Enter_VinState();
}
void TSC_Vin_Rte_Exit_VinState(void)
{
  Rte_Exit_VinState();
}



