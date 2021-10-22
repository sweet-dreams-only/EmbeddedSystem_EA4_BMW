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
 *          File:  TSC_Vin.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit write services */
Std_ReturnType TSC_Vin_Rte_Write_Vin_Vin(const Vin_VinType *data);

/** Sender receiver - implicit read services */
Vin_LifeCycleRequestType TSC_Vin_Rte_IRead_Vin_LifeCycleModeRequest_LifeCycleRequest_requestMode(void);
const Vin_ComVinType *TSC_Vin_Rte_IRead_Vin_ReceiveFromCom_ComVin_ComVin(void);

/** Sender receiver - Queued - Explicit send */
Std_ReturnType TSC_Vin_Rte_Send_VinRequest_RequestMessageIdentifier(uint16 data);

/** Client server interfaces */
Std_ReturnType TSC_Vin_Rte_Call_DlogEcuInfo_GetVin(uint8 *Vin);

/** Service interfaces */
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_GetErrorStatus(NvM_RequestResultType *RequestResultPtr);
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_ReadBlock(NvM_DstPtrType DstPtr);
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_WriteBlock(NvM_SrcPtrType SrcPtr);
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_WriteBlock(NvM_SrcPtrType SrcPtr);
Std_ReturnType TSC_Vin_Rte_Call_NvMService_Vin_WriteBlock(NvM_SrcPtrType SrcPtr);

/** Mode switches */
Vin_LifeCycleRequestType TSC_Vin_Rte_Mode_LifeCycle_Mode(Vin_LifeCycleRequestType *previousMode, Vin_LifeCycleRequestType *nextMode);
Std_ReturnType TSC_Vin_Rte_Switch_LifeCycle_Mode(Vin_LifeCycleRequestType mode);
Std_ReturnType TSC_Vin_Rte_Switch_VinChangeIndicator_ChangeIndicator(uint8 mode);
uint8 TSC_Vin_Rte_Mode_VinChangeIndicator_ChangeIndicator(void);
Std_ReturnType TSC_Vin_Rte_Switch_VinChangeIndicator_ChangeIndicator(uint8 mode);
Std_ReturnType TSC_Vin_Rte_Switch_VinChangeIndicator_ChangeIndicator(uint8 mode);

/** Mode switch acknowledgement */
Std_ReturnType TSC_Vin_Rte_SwitchAck_VinChangeIndicator_ChangeIndicator(void);
Std_ReturnType TSC_Vin_Rte_SwitchAck_VinChangeIndicator_ChangeIndicator(void);
Std_ReturnType TSC_Vin_Rte_SwitchAck_VinChangeIndicator_ChangeIndicator(void);

/** Exclusive Areas */
void TSC_Vin_Rte_Enter_VinState(void);
void TSC_Vin_Rte_Exit_VinState(void);




