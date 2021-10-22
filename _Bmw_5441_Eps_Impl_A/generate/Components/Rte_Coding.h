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
 *          File:  Rte_Coding.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Coding>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CODING_H
# define _RTE_CODING_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Coding_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Coding_LifeCycleRequestType, RTE_VAR_INIT) Rte_BswM_Provide_MSRP_Coding_requestMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Vin_VinType, RTE_VAR_INIT) Rte_Vin_Vin_Vin; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_LifeCycleRequest_requestMode (2U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_Coding_BusComModeSwitch_Mode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_Coding_DataMode_currentDataMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Coding_ProgId_progId(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Coding_ProgId_progId(P2VAR(Dlog_ProgIdArrayType, AUTOMATIC, RTE_CODING_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Coding_LifeCycleRequestType, RTE_CODE) Rte_Mode_Coding_LifeCycle_Mode(P2VAR(Coding_LifeCycleRequestType, AUTOMATIC, RTE_CODING_APPL_VAR) previousMode, P2VAR(Coding_LifeCycleRequestType, AUTOMATIC, RTE_CODING_APPL_VAR) nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Coding_DataMode_currentDataMode(uint8 nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Coding_LifeCycle_Mode(Coding_LifeCycleRequestType nextMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */



# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode() \
  (Rte_BswM_Provide_MSRP_Coding_requestMode)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IRead_VinReceiveHandler_Vin_Vin() \
  (&Rte_Vin_Vin_Vin)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ProgId_progId Rte_Read_Coding_ProgId_progId


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_BusCom_Mode() (Rte_ModeMachine_BswM_Switch_Coding_BusComModeSwitch_Mode) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Mode_ConditionMode_currentConditionMode() (RTE_MODE_Coding_ConditionMode_CODING_ALLOWED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Mode_DataMode_currentDataMode() (Rte_ModeMachine_Coding_DataMode_currentDataMode) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Mode_LifeCycle_Mode Rte_Mode_Coding_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_DataMode_currentDataMode Rte_Switch_Coding_DataMode_currentDataMode
#  define Rte_Switch_LifeCycle_Mode Rte_Switch_Coding_LifeCycle_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_CheckCurrentLimit_CheckPlausibility(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_EventNotCoded_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)1, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_EventWrongVehicle_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)5, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)10, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_NvMService_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)10, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_CodingData() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_CodingData() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Enter_CodingState() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_CodingState() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# endif /* !defined(RTE_CORE) */


# define Coding_START_SEC_CODE
# include "Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Coding_DemClearEventAllowedNotCoded Coding_ClearEventAllowed
#  define RTE_RUNNABLE_Coding_TimerMain Coding_TimerMain
#  define RTE_RUNNABLE_DCMConfirmation Coding_DCMConfirmation
#  define RTE_RUNNABLE_DCMIndication Coding_DCMIndication
#  define RTE_RUNNABLE_GetCafIds Coding_DlogGetCafIds
#  define RTE_RUNNABLE_LifeCycleHandler Coding_LifeCycleHandler
#  define RTE_RUNNABLE_R_CheckNCD Coding_RoutineControlcheckNCD
#  define RTE_RUNNABLE_R_ConditionCheckReadCPS Coding_ConditionCheckReadCPS
#  define RTE_RUNNABLE_R_ConditionCheckReadProtocolData Coding_ConditionCheckReadProtocolData
#  define RTE_RUNNABLE_R_GetCurrentLimit Coding_Func_GetCurrentLimit
#  define RTE_RUNNABLE_R_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance Coding_Func_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance
#  define RTE_RUNNABLE_R_GetNAME00_01_CalculationOfActiveReturn Coding_Func_GetNAME00_01_CalculationOfActiveReturn
#  define RTE_RUNNABLE_R_GetNAME00_02_reserved Coding_Func_GetNAME00_02_reserved
#  define RTE_RUNNABLE_R_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis Coding_Func_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis
#  define RTE_RUNNABLE_R_GetNAME00_04_reserved Coding_Func_GetNAME00_04_reserved
#  define RTE_RUNNABLE_R_GetNAME00_05_reserved Coding_Func_GetNAME00_05_reserved
#  define RTE_RUNNABLE_R_GetNAME00_06_reserved Coding_Func_GetNAME00_06_reserved
#  define RTE_RUNNABLE_R_GetNAME00_07_reserved Coding_Func_GetNAME00_07_reserved
#  define RTE_RUNNABLE_R_GetNAME01_00_reserved Coding_Func_GetNAME01_00_reserved
#  define RTE_RUNNABLE_R_GetNAME01_01_reserved Coding_Func_GetNAME01_01_reserved
#  define RTE_RUNNABLE_R_GetNAME01_02_reserved Coding_Func_GetNAME01_02_reserved
#  define RTE_RUNNABLE_R_GetNAME01_03_ParkingPowerDamping Coding_Func_GetNAME01_03_ParkingPowerDamping
#  define RTE_RUNNABLE_R_GetNAME01_04_reserved Coding_Func_GetNAME01_04_reserved
#  define RTE_RUNNABLE_R_GetNAME01_05_reserved Coding_Func_GetNAME01_05_reserved
#  define RTE_RUNNABLE_R_GetNAME01_06_reserved Coding_Func_GetNAME01_06_reserved
#  define RTE_RUNNABLE_R_GetNAME01_07_reserved Coding_Func_GetNAME01_07_reserved
#  define RTE_RUNNABLE_R_GetNAME02_00_CompensationOfFriction Coding_Func_GetNAME02_00_CompensationOfFriction
#  define RTE_RUNNABLE_R_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull Coding_Func_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull
#  define RTE_RUNNABLE_R_GetNAME02_02 Coding_Func_GetNAME02_02
#  define RTE_RUNNABLE_R_GetNAME02_03 Coding_Func_GetNAME02_03
#  define RTE_RUNNABLE_R_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear Coding_Func_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear
#  define RTE_RUNNABLE_R_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel Coding_Func_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel
#  define RTE_RUNNABLE_R_GetNAME02_06 Coding_Func_GetNAME02_06
#  define RTE_RUNNABLE_R_GetNAME02_07 Coding_Func_GetNAME02_07
#  define RTE_RUNNABLE_R_GetNAME03_00_reserved Coding_Func_GetNAME03_00_reserved
#  define RTE_RUNNABLE_R_GetNAME03_01_VoltageDependantDegredation Coding_Func_GetNAME03_01_VoltageDependantDegredation
#  define RTE_RUNNABLE_R_GetNAME03_02_SpeedDependantDegredation Coding_Func_GetNAME03_02_SpeedDependantDegredation
#  define RTE_RUNNABLE_R_GetNAME03_03_reserved Coding_Func_GetNAME03_03_reserved
#  define RTE_RUNNABLE_R_GetNAME03_04_reserved Coding_Func_GetNAME03_04_reserved
#  define RTE_RUNNABLE_R_GetNAME03_05_reserved Coding_Func_GetNAME03_05_reserved
#  define RTE_RUNNABLE_R_GetNAME03_06_reserved Coding_Func_GetNAME03_06_reserved
#  define RTE_RUNNABLE_R_GetNAME03_07_reserved Coding_Func_GetNAME03_07_reserved
#  define RTE_RUNNABLE_R_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque
#  define RTE_RUNNABLE_R_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque
#  define RTE_RUNNABLE_R_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors Coding_Func_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors
#  define RTE_RUNNABLE_R_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping Coding_Func_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping
#  define RTE_RUNNABLE_R_GetNAME04_04_EPSVibration Coding_Func_GetNAME04_04_EPSVibration
#  define RTE_RUNNABLE_R_GetNAME04_05_DrivingExperienceSwitch Coding_Func_GetNAME04_05_DrivingExperienceSwitch
#  define RTE_RUNNABLE_R_GetNAME04_06_reserved Coding_Func_GetNAME04_06_reserved
#  define RTE_RUNNABLE_R_GetNAME04_07_automaticEngineStartStopFunction Coding_Func_GetNAME04_07_automaticEngineStartStopFunction
#  define RTE_RUNNABLE_R_GetNAME05_00_ActiveFanActuation Coding_Func_GetNAME05_00_ActiveFanActuation
#  define RTE_RUNNABLE_R_GetNAME05_01_reserved Coding_Func_GetNAME05_01_reserved
#  define RTE_RUNNABLE_R_GetNAME05_02_reserved Coding_Func_GetNAME05_02_reserved
#  define RTE_RUNNABLE_R_GetNAME05_03_reserved Coding_Func_GetNAME05_03_reserved
#  define RTE_RUNNABLE_R_GetNAME05_04_reserved Coding_Func_GetNAME05_04_reserved
#  define RTE_RUNNABLE_R_GetNAME05_05_reserved Coding_Func_GetNAME05_05_reserved
#  define RTE_RUNNABLE_R_GetNAME05_06_reserved Coding_Func_GetNAME05_06_reserved
#  define RTE_RUNNABLE_R_GetNAME05_07_reserved Coding_Func_GetNAME05_07_reserved
#  define RTE_RUNNABLE_R_GetNAME08_reserved Coding_Func_GetNAME08_reserved
#  define RTE_RUNNABLE_R_GetNAME09_reserved Coding_Func_GetNAME09_reserved
#  define RTE_RUNNABLE_R_GetNAME10_reserved Coding_Func_GetNAME10_reserved
#  define RTE_RUNNABLE_R_GetNAME11_reserved Coding_Func_GetNAME11_reserved
#  define RTE_RUNNABLE_R_GetNAME12_reserved Coding_Func_GetNAME12_reserved
#  define RTE_RUNNABLE_R_GetNAME13_reserved Coding_Func_GetNAME13_reserved
#  define RTE_RUNNABLE_R_GetNAME14_reserved Coding_Func_GetNAME14_reserved
#  define RTE_RUNNABLE_R_GetNAME15_reserved Coding_Func_GetNAME15_reserved
#  define RTE_RUNNABLE_R_GetNAME16_reserved Coding_Func_GetNAME16_reserved
#  define RTE_RUNNABLE_R_GetNAME17_reserved Coding_Func_GetNAME17_reserved
#  define RTE_RUNNABLE_R_GetNAME18_reserved Coding_Func_GetNAME18_reserved
#  define RTE_RUNNABLE_R_GetNAME19_reserved Coding_Func_GetNAME19_reserved
#  define RTE_RUNNABLE_R_GetNAME20_reserved Coding_Func_GetNAME20_reserved
#  define RTE_RUNNABLE_R_GetNAME21_reserved Coding_Func_GetNAME21_reserved
#  define RTE_RUNNABLE_R_GetNAME22_reserved Coding_Func_GetNAME22_reserved
#  define RTE_RUNNABLE_R_GetNAME23_reserved Coding_Func_GetNAME23_reserved
#  define RTE_RUNNABLE_R_GetNAME24_reserved Coding_Func_GetNAME24_reserved
#  define RTE_RUNNABLE_R_GetNAME25_reserved Coding_Func_GetNAME25_reserved
#  define RTE_RUNNABLE_R_GetNAME26_reserved Coding_Func_GetNAME26_reserved
#  define RTE_RUNNABLE_R_GetNAME27_reserved Coding_Func_GetNAME27_reserved
#  define RTE_RUNNABLE_R_GetNAME28_reserved Coding_Func_GetNAME28_reserved
#  define RTE_RUNNABLE_R_GetNAME29_reserved Coding_Func_GetNAME29_reserved
#  define RTE_RUNNABLE_R_GetSpeedMinuslimitForMaxCurrent Coding_Func_GetSpeedMinuslimitForMaxCurrent
#  define RTE_RUNNABLE_R_ReadCPS Coding_ReadDataCPS
#  define RTE_RUNNABLE_R_ReadNCD Coding_RoutineControlreadNCD
#  define RTE_RUNNABLE_R_ReadProtocolData Coding_ReadDataProtocolData
#  define RTE_RUNNABLE_R_WriteNCD Coding_RoutineControlwriteNCD
#  define RTE_RUNNABLE_SessionChange Coding_SessionChange
#  define RTE_RUNNABLE_VinReceiveHandler Coding_VinReceivedExternalVin
#  define RTE_RUNNABLE_WriteDataBlockNotification Coding_NvMNotifyJobFinishedCodingData
# endif

FUNC(Std_ReturnType, Coding_CODE) Coding_ClearEventAllowed(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) allowed); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Coding_CODE) Coding_TimerMain(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Coding_CODE) Coding_DCMConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Coding_CODE) Coding_DCMIndication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CODING_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Coding_CODE) Coding_DCMIndication(uint8 SID, P2CONST(Dcm_Data1024ByteType, AUTOMATIC, RTE_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CODING_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Coding_CODE) Coding_DlogGetCafIds(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) cafIds, P2VAR(uint16, AUTOMATIC, RTE_CODING_APPL_VAR) numberOfCafIds); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Coding_CODE) Coding_DlogGetCafIds(P2VAR(Coding_CafIdArrayType, AUTOMATIC, RTE_CODING_APPL_VAR) cafIds, P2VAR(uint16, AUTOMATIC, RTE_CODING_APPL_VAR) numberOfCafIds); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Coding_CODE) Coding_LifeCycleHandler(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Coding_CODE) Coding_RoutineControlcheckNCD(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineInSignal, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineOutSignal, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Coding_CODE) Coding_RoutineControlcheckNCD(P2CONST(Dcm_Data18ByteType, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineInSignal, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineOutSignal, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, Coding_CODE) Coding_ConditionCheckReadCPS(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_ConditionCheckReadProtocolData(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CODING_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetCurrentLimit(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_01_CalculationOfActiveReturn(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_02_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_04_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_05_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_06_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME00_07_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_00_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_01_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_02_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_03_ParkingPowerDamping(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_04_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_05_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_06_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME01_07_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_00_CompensationOfFriction(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_02(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_03(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_06(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME02_07(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_00_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_01_VoltageDependantDegredation(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_02_SpeedDependantDegredation(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_03_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_04_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_05_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_06_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME03_07_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_04_EPSVibration(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_05_DrivingExperienceSwitch(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_06_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME04_07_automaticEngineStartStopFunction(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_00_ActiveFanActuation(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_01_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_02_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_03_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_04_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_05_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_06_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME05_07_reserved(P2VAR(boolean, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME08_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME09_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME10_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME11_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME12_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME13_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME14_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME15_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME16_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME17_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME18_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME19_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME20_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME21_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME22_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME23_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME24_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME25_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME26_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME27_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME28_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetNAME29_reserved(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, Coding_CODE) Coding_Func_GetSpeedMinuslimitForMaxCurrent(P2VAR(uint8, AUTOMATIC, RTE_CODING_APPL_VAR) Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Coding_CODE) Coding_ReadDataCPS(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Coding_CODE) Coding_ReadDataCPS(P2VAR(Dcm_Data18ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Coding_CODE) Coding_RoutineControlreadNCD(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineInSignal, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineOutSignal, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Coding_CODE) Coding_RoutineControlreadNCD(P2CONST(Dcm_Data6ByteType, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineInSignal, Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1024ByteType, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineOutSignal, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Coding_CODE) Coding_ReadDataProtocolData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Coding_CODE) Coding_ReadDataProtocolData(P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, Coding_CODE) Coding_RoutineControlwriteNCD(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineInSignal, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, Coding_CODE) Coding_RoutineControlwriteNCD(P2CONST(Dcm_Data1024ByteType, AUTOMATIC, RTE_VAR_NOINIT) DcmDspStartRoutineInSignal, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Coding_CODE) Coding_SessionChange(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Coding_CODE) Coding_VinReceivedExternalVin(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, Coding_CODE) Coding_NvMNotifyJobFinishedCodingData(uint8 ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Coding_STOP_SEC_CODE
# include "Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackClearEventAllowed_E_NOT_OK (1U)

#  define RTE_E_CallbackClearEventAllowed_E_OK (0U)

#  define RTE_E_CheckCurrentLimit_E_NOT_OK (1U)

#  define RTE_E_Coding_SVKInterface_E_OK (0U)

#  define RTE_E_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_DcmDspData_CPS_E_NOT_OK (1U)

#  define RTE_E_DataServices_DcmDspData_CPS_E_OK (0U)

#  define RTE_E_DataServices_DcmDspData_protocolData_E_NOT_OK (1U)

#  define RTE_E_DataServices_DcmDspData_protocolData_E_OK (0U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_OK (0U)

#  define RTE_E_NvMNotifyJobFinished_E_OK (0U)

#  define RTE_E_NvMService_E_NOT_OK (1U)

#  define RTE_E_NvMService_E_OK (0U)

#  define RTE_E_RoutineServices_DcmDspRoutine_checkNCD_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DcmDspRoutine_checkNCD_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DcmDspRoutine_checkNCD_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DcmDspRoutine_readNCD_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DcmDspRoutine_readNCD_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DcmDspRoutine_readNCD_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_DcmDspRoutine_writeNCD_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_DcmDspRoutine_writeNCD_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_DcmDspRoutine_writeNCD_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_OK (0U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CODING_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
