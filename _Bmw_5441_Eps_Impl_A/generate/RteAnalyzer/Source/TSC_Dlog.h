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
 *          File:  TSC_Dlog.h
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
Std_ReturnType TSC_Dlog_Rte_Write_ProgId_progId(const uint8 *data);
Std_ReturnType TSC_Dlog_Rte_Write_ProgId_progId(const uint8 *data);

/** Sender receiver - implicit read services */
Dlog_LifeCycleRequestType TSC_Dlog_Rte_IRead_Dlog_ModeSwitchRequestLifeCycle_LifeCycleRequest_requestMode(void);

/** Client server interfaces */
Std_ReturnType TSC_Dlog_Rte_Call_Coding_Svk_GetCafIds(uint8 *cafIds, uint16 *numberOfCafIds);

/** Service interfaces */
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_ReadBlock(NvM_DstPtrType DstPtr);
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(uint8 DataIndex);
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_ReadBlock(NvM_DstPtrType DstPtr);
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_SetDataIndex(uint8 DataIndex);
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogProgData_WriteBlock(NvM_SrcPtrType SrcPtr);
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkEntry_WriteBlock(NvM_SrcPtrType SrcPtr);
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkHistory_GetErrorStatus(NvM_RequestResultType *RequestResultPtr);
Std_ReturnType TSC_Dlog_Rte_Call_NvMService_DlogSvkHistory_WriteBlock(NvM_SrcPtrType SrcPtr);
Std_ReturnType TSC_Dlog_Rte_Call_NvMAdmin_DlogProgData_SetBlockProtection(boolean ProtectionEnabled);

/** Mode switches */
Std_ReturnType TSC_Dlog_Rte_Switch_LifeCycle_Mode(Dlog_LifeCycleRequestType mode);
Dlog_LifeCycleRequestType TSC_Dlog_Rte_Mode_LifeCycle_Mode(Dlog_LifeCycleRequestType *previousMode, Dlog_LifeCycleRequestType *nextMode);
Std_ReturnType TSC_Dlog_Rte_Switch_LifeCycle_Mode(Dlog_LifeCycleRequestType mode);

/** Mode switch acknowledgement */
Std_ReturnType TSC_Dlog_Rte_SwitchAck_LifeCycle_Mode(void);
Std_ReturnType TSC_Dlog_Rte_SwitchAck_LifeCycle_Mode(void);




