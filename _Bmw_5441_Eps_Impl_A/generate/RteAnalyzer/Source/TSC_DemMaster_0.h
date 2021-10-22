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
 *          File:  TSC_DemMaster_0.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Service interfaces */
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBClrEvt_CodingEventNotCoded_ClearEventAllowed(boolean *Allowed);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBClrEvt_VsmEventOpmode_ClearEventAllowed(boolean *Allowed);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_1700_KmStand_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_1701_Systemzeit_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_1750_FUwBn_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_2805_Aussentemperatur_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_2866_Betriebsspannung_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_2867_Fahrzeuggeschwindigkeit_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_5003_HwAg_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_500C_PscmSts_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_500E_HwTq_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_500F_MotTq_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_EDR_01_ConditionByte_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_EDR_02_OccurrenceCounter_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_EDR_03_HealingCounter_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_GeneralCBDataEvt_EventDataChanged(Dem_EventIdType EventId);




