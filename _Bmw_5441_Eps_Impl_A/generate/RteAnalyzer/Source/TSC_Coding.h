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
 *          File:  TSC_Coding.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_Coding_Rte_Read_ProgId_progId(uint8 *data);
Std_ReturnType TSC_Coding_Rte_Read_ProgId_progId(uint8 *data);

/** Sender receiver - implicit read services */
Coding_LifeCycleRequestType TSC_Coding_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void);
const Vin_VinType *TSC_Coding_Rte_IRead_VinReceiveHandler_Vin_Vin(void);

/** Client server interfaces */
Std_ReturnType TSC_Coding_Rte_Call_CheckCurrentLimit_CheckPlausibility(uint8 Value);

/** Service interfaces */
Std_ReturnType TSC_Coding_Rte_Call_EventNotCoded_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Coding_Rte_Call_EventWrongVehicle_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Coding_Rte_Call_NvMService_WriteBlock(ConstVoidPtr SrcPtr);
Std_ReturnType TSC_Coding_Rte_Call_EventNotCoded_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Coding_Rte_Call_NvMService_ReadBlock(VoidPtr DstPtr);
Std_ReturnType TSC_Coding_Rte_Call_EventNotCoded_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Coding_Rte_Call_EventWrongVehicle_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Coding_Rte_Call_EventNotCoded_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Coding_Rte_Call_EventWrongVehicle_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Coding_Rte_Call_NvMService_ReadBlock(VoidPtr DstPtr);

/** Mode switches */
uint8 TSC_Coding_Rte_Mode_DataMode_currentDataMode(void);
uint8 TSC_Coding_Rte_Mode_BusCom_Mode(void);
uint8 TSC_Coding_Rte_Mode_ConditionMode_currentConditionMode(void);
Coding_LifeCycleRequestType TSC_Coding_Rte_Mode_LifeCycle_Mode(Coding_LifeCycleRequestType *previousMode, Coding_LifeCycleRequestType *nextMode);
Std_ReturnType TSC_Coding_Rte_Switch_DataMode_currentDataMode(uint8 mode);
Std_ReturnType TSC_Coding_Rte_Switch_LifeCycle_Mode(Coding_LifeCycleRequestType mode);
uint8 TSC_Coding_Rte_Mode_DataMode_currentDataMode(void);
Std_ReturnType TSC_Coding_Rte_Switch_DataMode_currentDataMode(uint8 mode);
uint8 TSC_Coding_Rte_Mode_DataMode_currentDataMode(void);
Std_ReturnType TSC_Coding_Rte_Switch_DataMode_currentDataMode(uint8 mode);
Coding_LifeCycleRequestType TSC_Coding_Rte_Mode_LifeCycle_Mode(Coding_LifeCycleRequestType *previousMode, Coding_LifeCycleRequestType *nextMode);

/** Exclusive Areas */
void TSC_Coding_Rte_Enter_CodingData(void);
void TSC_Coding_Rte_Exit_CodingData(void);
void TSC_Coding_Rte_Enter_CodingState(void);
void TSC_Coding_Rte_Exit_CodingState(void);




