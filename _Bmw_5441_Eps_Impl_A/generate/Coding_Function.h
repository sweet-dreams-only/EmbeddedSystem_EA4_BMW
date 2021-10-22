/**
 * \file
 *
 * \brief       Coding Function
 *
 * \project     BMW Platform Software
 *
 * \copyright   BMW AG 2016 - 2017
 *
 * \version     5.2.1
 *
 */

/*------------------------------------------------------------------------------
*
*  THIS FILE WAS GENERATED. DO NOT MODIFY!
*
*  GENERATOR       : BMW PAGe 1.1.0
*
*  GENERATION TIME : 2018-07-30 19:57:40.796167
*
------------------------------------------------------------------------------*/

#ifndef CODING_FUNCTION_H
#define CODING_FUNCTION_H

/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include "BUtil/PlatformTypes.h"     /* BMW Platform Types          */
#include "Coding.h"                  /* Coding_ReturnType */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Coding_CHECK_VERSION(5, 2, 1))
   #error "Version of Coding_Function.h does not match the version of the module!"
#endif


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define Coding_START_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

extern Coding_ReturnType Coding_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME00_01_CalculationOfActiveReturn(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME00_02_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME00_04_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME00_05_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME00_06_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME00_07_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetCurrentLimit(uint8 *funcVal);

extern Coding_ReturnType Coding_GetSpeedMinuslimitForMaxCurrent(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME08_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME09_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME10_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME11_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME12_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME13_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME14_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME15_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME16_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME17_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME18_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME19_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME20_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME21_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME22_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME23_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME24_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME25_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME26_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME27_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME28_reserved(uint8 *funcVal);

extern Coding_ReturnType Coding_GetNAME01_00_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME01_01_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME01_02_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME01_03_ParkingPowerDamping(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME01_04_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME01_05_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME01_06_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME01_07_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_00_CompensationOfFriction(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_02(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_03(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_06(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME02_07(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_00_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_01_VoltageDependantDegredation(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_02_SpeedDependantDegredation(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_03_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_04_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_05_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_06_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME03_07_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_04_EPSVibration(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_05_DrivingExperienceSwitch(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_06_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME04_07_automaticEngineStartStopFunction(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_00_ActiveFanActuation(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_01_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_02_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_03_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_04_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_05_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_06_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME05_07_reserved(boolean *funcVal);

extern Coding_ReturnType Coding_GetNAME29_reserved(uint8 *funcVal);


extern uint8 Coding_CheckCurrentLimit(void);

#define Coding_STOP_SEC_CODE
#include "Coding_MemMap.h" /* PRQA S 5087 */

#ifdef __cplusplus
}
#endif

#endif /* CODING_FUNCTION_H */
