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
 *          File:  TSC_Dcm.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Dcm.h"
#include "TSC_Dcm.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1000_Pruefstempel_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_1000_Pruefstempel_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1000_Pruefstempel_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_1000_Pruefstempel_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1000_Pruefstempel_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_1000_Pruefstempel_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_100A_EnergySavingState_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_100A_EnergySavingState_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_100E_ExtendedEnergySavingState_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_100E_ExtendedEnergySavingState_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1701_Systemzeit_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_1701_Systemzeit_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_1704_DmDtcAktiveMeldung_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadDataLength(uint16 *DataLength)
{
  return Rte_Call_DataServices_DID_1723_DmIsDtcActiveResponse_ReadDataLength(DataLength);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2502_ProgrammingCounter_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_2502_ProgrammingCounter_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ConditionCheckRead(Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ConditionCheckRead(ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_WriteData(const uint8 *Data, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_2503_ProgrammingCounterMaxValue_WriteData(Data, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2504_FlashTimingParameter_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_2504_FlashTimingParameter_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ConditionCheckRead(Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ConditionCheckRead(ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_2507_SwfkDeleteSupported_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_250B_ReadSwRevision_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_250B_ReadSwRevision_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_250B_ReadSwRevision_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_250B_ReadSwRevision_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2540_MileKmEeprom_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_2540_MileKmEeprom_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2540_MileKmEeprom_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_2540_MileKmEeprom_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_2541_StatusCalcvn_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_2541_StatusCalcvn_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_37FE_Cps_ConditionCheckRead(Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_37FE_Cps_ConditionCheckRead(ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_37FE_Cps_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_37FE_Cps_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_37FF_ReadProtocolData_ConditionCheckRead(Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_37FF_ReadProtocolData_ConditionCheckRead(ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_37FF_ReadProtocolData_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_37FF_ReadProtocolData_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_DB3C_StatusFzgBordnetz_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_DB57_EpsRitzelwinkelsensor_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_DB99_EpsMomentensensor_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_DC77_EpsZahnstangenmitte_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_DFDD_GelernterZahnstangenweg_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ConditionCheckRead(Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ConditionCheckRead(ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_F100_ReadActiveSessionState_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F101_SvkAktuell_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_F101_SvkAktuell_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F101_SvkAktuell_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_F101_SvkAktuell_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F102_SvkSysSupplier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_F102_SvkSysSupplier_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F102_SvkSysSupplier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_F102_SvkSysSupplier_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F103_SvkWerk_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_F103_SvkWerk_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F103_SvkWerk_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_F103_SvkWerk_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F150_SgbdIdx_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_F150_SgbdIdx_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F152_Readhwmodificationindex_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_F152_Readhwmodificationindex_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F15A_WdbiFp_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_F15A_WdbiFp_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DID_F18A_SystemSupplierIdentifier_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F18B_Herstelldatum_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_F18B_Herstelldatum_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_F18C_EcuSerialNumber_ReadData(uint8 *Data)
{
  return Rte_Call_DataServices_DID_F18C_EcuSerialNumber_ReadData(Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SvkBackup0_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DcmDspData_SvkBackup0_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SvkBackup0_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DcmDspData_SvkBackup0_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SvkBackup1_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DcmDspData_SvkBackup1_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SvkBackup1_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DcmDspData_SvkBackup1_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SvkBackup2_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DcmDspData_SvkBackup2_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SvkBackup2_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DcmDspData_SvkBackup2_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_Vin_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DcmDspData_Vin_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_CheckNcd_Routine_Start(const uint8 *Cps_In, Dcm_OpStatusType OpStatus, uint8 *StatCheckNcdResult_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_CheckNcd_Routine_Start(Cps_In, OpStatus, StatCheckNcdResult_Out, DataLength, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_ControlExtendedEnergySavingState_Routine_Start(uint8 dataIn_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_ControlExtendedEnergySavingState_Routine_Start(dataIn_In, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_DarhStrtStop_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_DarhStrtStop_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_DarhStrtStop_Routine_Stop(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_DarhStrtStop_Routine_Stop(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_DeleteSwPackage_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_DeleteSwPackage_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_DiagCommLoopback_Routine_Start(const uint8 *dataIn_In, Dcm_OpStatusType OpStatus, uint8 *dataOut_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_DiagCommLoopback_Routine_Start(dataIn_In, OpStatus, dataOut_Out, DataLength, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_DmClientTriggerDtcEntry_Routine_Start(uint8 DTCType_In, Dcm_OpStatusType OpStatus, uint8 *DTCTypeOut_Out, uint8 *DTCByte1_Out, uint8 *DTCByte2_Out, uint8 *DTCByte3_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_DmClientTriggerDtcEntry_Routine_Start(DTCType_In, OpStatus, DTCTypeOut_Out, DTCByte1_Out, DTCByte2_Out, DTCByte3_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_Energiesparmode_Routine_Start(uint8 dataIn_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_Energiesparmode_Routine_Start(dataIn_In, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsInitialisierungService_Routine_RequestResults(Dcm_OpStatusType OpStatus, uint8 *StatRoutineStatus_Out, uint8 *StatLenkradwinkelWert_Out, uint8 *StatSensorZustandNr_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsInitialisierungService_Routine_RequestResults(OpStatus, StatRoutineStatus_Out, StatLenkradwinkelWert_Out, StatSensorZustandNr_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Stop(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsInitialisierungService_Routine_Stop(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_RequestResults(Dcm_OpStatusType OpStatus, uint8 *StatRoutineStatus_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_RequestResults(OpStatus, StatRoutineStatus_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Start(uint8 Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Start(Winkel_In, Winkelgeschwindigkeit_In, Winkelbeschleunigung_In, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Stop(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsInitialisierungWerk_Routine_Stop(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsPendeln_Routine_RequestResults(Dcm_OpStatusType OpStatus, uint8 *StatEpsPendelnAktivNr_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsPendeln_Routine_RequestResults(OpStatus, StatEpsPendelnAktivNr_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsPendeln_Routine_Start(uint8 Frequenz_In, uint8 MaxAmplitude_In, uint8 NumberOfCycles_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsPendeln_Routine_Start(Frequenz_In, MaxAmplitude_In, NumberOfCycles_In, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsVerfahren_Routine_RequestResults(Dcm_OpStatusType OpStatus, uint8 *StatEpsVerfahrenAktivNr_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsVerfahren_Routine_RequestResults(OpStatus, StatEpsVerfahrenAktivNr_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsVerfahren_Routine_Start(const uint8 *Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, uint8 AbsolutEin_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsVerfahren_Routine_Start(Winkel_In, Winkelgeschwindigkeit_In, Winkelbeschleunigung_In, AbsolutEin_In, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_EpsZahnstangenmitteReset_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_EpsZahnstangenmitteReset_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_IsLoeschen_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_IsLoeschen_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_RcCm_Routine_Start(uint8 RcCmIcvRcoStruct_In, Dcm_OpStatusType OpStatus, uint8 *StatRoutineStatus_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_RcCm_Routine_Start(RcCmIcvRcoStruct_In, OpStatus, StatRoutineStatus_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_RcCpd_Routine_Start(Dcm_OpStatusType OpStatus, uint8 *StatRoutineStatus_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_RcCpd_Routine_Start(OpStatus, StatRoutineStatus_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_RcCppc_Routine_Start(Dcm_OpStatusType OpStatus, uint8 *dataOut_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_RcCppc_Routine_Start(OpStatus, dataOut_Out, DataLength, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_RcEm_Routine_Start(uint8 RcEmIeRco_In, Dcm_OpStatusType OpStatus, uint8 *StatRoutineStatus_Out, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_RcEm_Routine_Start(RcEmIeRco_In, OpStatus, StatRoutineStatus_Out, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_RcRswedi_Routine_Start(const uint8 *DataIn_In, Dcm_OpStatusType OpStatus, uint8 *DataOut_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_RcRswedi_Routine_Start(DataIn_In, OpStatus, DataOut_Out, DataLength, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_ReadNcd_Routine_Start(const uint8 *ArgCodingArea_In, Dcm_OpStatusType OpStatus, uint8 *StatCodingArea_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_ReadNcd_Routine_Start(ArgCodingArea_In, OpStatus, StatCodingArea_Out, DataLength, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SteuernEpsMultiturnwertReset_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_SteuernEpsMultiturnwertReset_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_SteuernEpsPulldriftOffsetReset_Routine_Start(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_WriteNcd_Routine_Start(const uint8 *ArgCodingArea_In, Dcm_OpStatusType OpStatus, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_WriteNcd_Routine_Start(ArgCodingArea_In, OpStatus, DataLength, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_CompareKey(Key, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_GetSeed(const uint8 *SecurityAccessDataRecord, Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_SecurityAccess_DcmDspSecurityRow_Coding_GetSeed(SecurityAccessDataRecord, OpStatus, Seed, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_ServiceRequestManufacturerNotification_Coding_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
{
  return Rte_Call_ServiceRequestManufacturerNotification_Coding_Confirmation(SID, ReqType, SourceAddress, ConfirmationStatus);
}
Std_ReturnType TSC_Dcm_Rte_Call_ServiceRequestManufacturerNotification_Coding_Indication(uint8 SID, const uint8 *RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_ServiceRequestManufacturerNotification_Coding_Indication(SID, RequestData, DataSize, ReqType, SourceAddress, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
{
  return Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Confirmation(SID, ReqType, SourceAddress, ConfirmationStatus);
}
Std_ReturnType TSC_Dcm_Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Indication(uint8 SID, const uint8 *RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_ServiceRequestManufacturerNotification_StdDiag_Indication(SID, RequestData, DataSize, ReqType, SourceAddress, ErrorCode);
}


     /* Mode Interfaces */

Std_ReturnType TSC_Dcm_Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6(Dcm_CommunicationModeType mode)
{
  return Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6_DcmCommunicationControl_ComMConf_ComMChannel_A_FlexRay_372befd6( mode);
}
Std_ReturnType TSC_Dcm_Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode)
{
  return Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting( mode);
}
Std_ReturnType TSC_Dcm_Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode)
{
  return Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl( mode);
}
Std_ReturnType TSC_Dcm_Rte_Switch_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode)
{
  return Rte_Switch_DcmEcuReset_DcmEcuReset( mode);
}
Std_ReturnType TSC_Dcm_Rte_Switch_DcmResponseOnEvent_DcmDspRoeEvent_DcmResponseOnEvent_DcmDspRoeEvent(Dcm_ResponseOnEventType mode)
{
  return Rte_Switch_DcmResponseOnEvent_DcmDspRoeEvent_DcmResponseOnEvent_DcmDspRoeEvent( mode);
}

Std_ReturnType TSC_Dcm_Rte_SwitchAck_DcmEcuReset_DcmEcuReset(void)
{
  return Rte_SwitchAck_DcmEcuReset_DcmEcuReset();
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







     /* Dcm */
      /* Dcm */



