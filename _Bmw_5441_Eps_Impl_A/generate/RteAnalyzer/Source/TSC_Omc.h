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
 *          File:  TSC_Omc.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - implicit read services */
Omc_LifeCycleRequestType TSC_Omc_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void);

/** Client server interfaces */
Std_ReturnType TSC_Omc_Rte_Call_StdDiag_AllowOpModeSwitch(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode);
Std_ReturnType TSC_Omc_Rte_Call_StdDiag_OpModeSwitchCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode);
Std_ReturnType TSC_Omc_Rte_Call_StdDiag_AllowOpModeSwitch(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType NewOperatingMode, Omc_ExtendedOperatingModeType NewExtendedOperatingMode);
Std_ReturnType TSC_Omc_Rte_Call_StdDiag_OpModeSwitchCancelled(Omc_OperatingModeType OperatingMode, Omc_ExtendedOperatingModeType ExtendedOperatingMode, Omc_OperatingModeType RequestedOperatingMode, Omc_ExtendedOperatingModeType RequestedExtendedOperatingMode);

/** Service interfaces */
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_GetErrorStatus(RequestResultType *RequestResultPtr);
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_WriteBlock(SrcPtrType SrcPtr);
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_GetErrorStatus(RequestResultType *RequestResultPtr);
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_WriteBlock(SrcPtrType SrcPtr);
Std_ReturnType TSC_Omc_Rte_Call_EnableCond_OMC_SetEnableCondition(boolean ConditionFulfilled);
Std_ReturnType TSC_Omc_Rte_Call_VsmEventOpmode_SetEventStatus(Dem_EventStatusType EventStatus);
Std_ReturnType TSC_Omc_Rte_Call_EnableCond_OMC_SetEnableCondition(boolean ConditionFulfilled);
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_GetErrorStatus(RequestResultType *RequestResultPtr);
Std_ReturnType TSC_Omc_Rte_Call_NvMServicePort_WriteBlock(SrcPtrType SrcPtr);
Std_ReturnType TSC_Omc_Rte_Call_VsmEventOpmode_SetEventStatus(Dem_EventStatusType EventStatus);

/** Mode switches */
Omc_LifeCycleRequestType TSC_Omc_Rte_Mode_LifeCycle_Mode(Omc_LifeCycleRequestType *previousMode, Omc_LifeCycleRequestType *nextMode);
Std_ReturnType TSC_Omc_Rte_Switch_LifeCycle_Mode(Omc_LifeCycleRequestType mode);
Std_ReturnType TSC_Omc_Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(Omc_ExtendedOperatingModeType mode);
Std_ReturnType TSC_Omc_Rte_Switch_operatingModeSwitchPort_currentOperatingMode(Omc_OperatingModeType mode);
Std_ReturnType TSC_Omc_Rte_Switch_extendedOperatingModeSwitchPort_currentExtendedOperatingMode(Omc_ExtendedOperatingModeType mode);
Std_ReturnType TSC_Omc_Rte_Switch_operatingModeSwitchPort_currentOperatingMode(Omc_OperatingModeType mode);

/** Exclusive Areas */
void TSC_Omc_Rte_Enter_Mode(void);
void TSC_Omc_Rte_Exit_Mode(void);




