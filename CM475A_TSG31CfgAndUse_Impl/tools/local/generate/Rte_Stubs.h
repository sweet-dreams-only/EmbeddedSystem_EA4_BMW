/******************************************************************************************************************
* Copyright 2016 Nxtr
* Nxtr Confidential
*
* Module File Name:   Rte_Stubs.h
* Module Description: Stubs header for Polyspace analysis.  Generated from TL109A_SwcSuprt.
* Project:            CBD
* Author:             Owen Tosh
******************************************************************************************************************/


#ifndef RTE_STUBS_H
#define RTE_STUBS_H

#include "math_stubs.h"

/*** Extern Statements ***/

/* Inputs */
extern VAR(MotCurrEolCalSt2, AUTOMATIC) TSG31CfgAndUse_Ip_MotCurrEolCalSt;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Ip_PhaDiscnctDiagcActv;
extern VAR(SysSt1, AUTOMATIC) TSG31CfgAndUse_Ip_SysSt;

/* Calibrations */
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_TSG31CfgAndUseAdcStrtOfCnvn2Offs;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_TSG31CfgAndUseMtrAg0SPIStart;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_TSG31CfgAndUsePwmDbnd;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_CurrMeasEolFixdPwmPerd;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_CurrMeasEolOffsHiCmuOffs;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_CurrMeasEolOffsLoCmuOffs;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_PhaDiscnctFixdPhaOnTi;
extern CONST(uint32, AUTOMATIC) TSG31CfgAndUse_Cal_PhaDiscnctFixdPwmPerd;

/* PIMs */
extern VAR(uint16, AUTOMATIC) TSG31CfgAndUse_Pim_MissUpdCoarse;
extern VAR(uint16, AUTOMATIC) TSG31CfgAndUse_Pim_MissUpdFine;
extern VAR(uint8, AUTOMATIC) TSG31CfgAndUse_Pim_MissUpdIninCntr;
extern VAR(uint16, AUTOMATIC) TSG31CfgAndUse_Pim_MissUpdMaxCntr;
extern VAR(uint16, AUTOMATIC) TSG31CfgAndUse_Pim_MissUpdMinCntr;
extern VAR(uint32, AUTOMATIC) TSG31CfgAndUse_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak;
extern VAR(uint32, AUTOMATIC) TSG31CfgAndUse_Pim_TSG31CfgAndUseMotAg0SPIStart;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Pim_TSG31CfgAndUseSysStEnaPrev;

/* Arguments and Returns */
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctGpioPhaALowrCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctGpioPhaAUpprCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctGpioPhaBLowrCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctGpioPhaBUpprCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctGpioPhaCLowrCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctGpioPhaCUpprCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctPeriphPhaALowrCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctPeriphPhaAUpprCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctPeriphPhaBLowrCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctPeriphPhaBUpprCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctPeriphPhaCLowrCmd_Return;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetFctPeriphPhaCUpprCmd_Return;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaALowrCmd_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaALowrCmd_Return;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaAUpprCmd_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaAUpprCmd_Return;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaBLowrCmd_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaBLowrCmd_Return;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaBUpprCmd_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaBUpprCmd_Return;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaCLowrCmd_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaCLowrCmd_Return;
extern VAR(boolean, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaCUpprCmd_PinSt;
extern VAR(Std_ReturnType, AUTOMATIC) TSG31CfgAndUse_Srv_IoHwAb_SetGpioPhaCUpprCmd_Return;


/*** Input Stubs ***/

#ifdef Rte_Read_MotCurrEolCalSt_Val
# undef Rte_Read_MotCurrEolCalSt_Val
#else
#error Rte_Read_MotCurrEolCalSt_Val is missing
#endif
#define Rte_Read_MotCurrEolCalSt_Val(data) (*(data) = TSG31CfgAndUse_Ip_MotCurrEolCalSt)

#ifdef Rte_Read_PhaDiscnctDiagcActv_Logl
# undef Rte_Read_PhaDiscnctDiagcActv_Logl
#else
#error Rte_Read_PhaDiscnctDiagcActv_Logl is missing
#endif
#define Rte_Read_PhaDiscnctDiagcActv_Logl(data) (*(data) = TSG31CfgAndUse_Ip_PhaDiscnctDiagcActv)

#ifdef Rte_Read_SysSt_Val
# undef Rte_Read_SysSt_Val
#else
#error Rte_Read_SysSt_Val is missing
#endif
#define Rte_Read_SysSt_Val(data) (*(data) = TSG31CfgAndUse_Ip_SysSt)


/*** Calibration Stubs ***/

#ifdef Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val
# undef Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val
#else
#error Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val is missing
#endif
#define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val() (TSG31CfgAndUse_Cal_TSG31CfgAndUseAdcStrtOfCnvn2Offs)

#ifdef Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val
# undef Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val
#else
#error Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val is missing
#endif
#define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val() (TSG31CfgAndUse_Cal_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs)

#ifdef Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val
# undef Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val
#else
#error Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val is missing
#endif
#define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val() (TSG31CfgAndUse_Cal_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs)

#ifdef Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val
# undef Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val
#else
#error Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val is missing
#endif
#define Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val() (TSG31CfgAndUse_Cal_TSG31CfgAndUseMtrAg0SPIStart)

#ifdef Rte_Prm_TSG31CfgAndUsePwmDbnd_Val
# undef Rte_Prm_TSG31CfgAndUsePwmDbnd_Val
#else
#error Rte_Prm_TSG31CfgAndUsePwmDbnd_Val is missing
#endif
#define Rte_Prm_TSG31CfgAndUsePwmDbnd_Val() (TSG31CfgAndUse_Cal_TSG31CfgAndUsePwmDbnd)

#ifdef Rte_Prm_CurrMeasEolFixdPwmPerd_Val
# undef Rte_Prm_CurrMeasEolFixdPwmPerd_Val
#else
#error Rte_Prm_CurrMeasEolFixdPwmPerd_Val is missing
#endif
#define Rte_Prm_CurrMeasEolFixdPwmPerd_Val() (TSG31CfgAndUse_Cal_CurrMeasEolFixdPwmPerd)

#ifdef Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val
# undef Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val
#else
#error Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val() (TSG31CfgAndUse_Cal_CurrMeasEolOffsHiCmuOffs)

#ifdef Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val
# undef Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val
#else
#error Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val is missing
#endif
#define Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val() (TSG31CfgAndUse_Cal_CurrMeasEolOffsLoCmuOffs)

#ifdef Rte_Prm_PhaDiscnctFixdPhaOnTi_Val
# undef Rte_Prm_PhaDiscnctFixdPhaOnTi_Val
#else
#error Rte_Prm_PhaDiscnctFixdPhaOnTi_Val is missing
#endif
#define Rte_Prm_PhaDiscnctFixdPhaOnTi_Val() (TSG31CfgAndUse_Cal_PhaDiscnctFixdPhaOnTi)

#ifdef Rte_Prm_PhaDiscnctFixdPwmPerd_Val
# undef Rte_Prm_PhaDiscnctFixdPwmPerd_Val
#else
#error Rte_Prm_PhaDiscnctFixdPwmPerd_Val is missing
#endif
#define Rte_Prm_PhaDiscnctFixdPwmPerd_Val() (TSG31CfgAndUse_Cal_PhaDiscnctFixdPwmPerd)


/*** PIM Stubs ***/

#ifdef Rte_Pim_MissUpdCoarse
# undef Rte_Pim_MissUpdCoarse
#else
#error Rte_Pim_MissUpdCoarse is missing
#endif
#define Rte_Pim_MissUpdCoarse() (&TSG31CfgAndUse_Pim_MissUpdCoarse)

#ifdef Rte_Pim_MissUpdFine
# undef Rte_Pim_MissUpdFine
#else
#error Rte_Pim_MissUpdFine is missing
#endif
#define Rte_Pim_MissUpdFine() (&TSG31CfgAndUse_Pim_MissUpdFine)

#ifdef Rte_Pim_MissUpdIninCntr
# undef Rte_Pim_MissUpdIninCntr
#else
#error Rte_Pim_MissUpdIninCntr is missing
#endif
#define Rte_Pim_MissUpdIninCntr() (&TSG31CfgAndUse_Pim_MissUpdIninCntr)

#ifdef Rte_Pim_MissUpdMaxCntr
# undef Rte_Pim_MissUpdMaxCntr
#else
#error Rte_Pim_MissUpdMaxCntr is missing
#endif
#define Rte_Pim_MissUpdMaxCntr() (&TSG31CfgAndUse_Pim_MissUpdMaxCntr)

#ifdef Rte_Pim_MissUpdMinCntr
# undef Rte_Pim_MissUpdMinCntr
#else
#error Rte_Pim_MissUpdMinCntr is missing
#endif
#define Rte_Pim_MissUpdMinCntr() (&TSG31CfgAndUse_Pim_MissUpdMinCntr)

#ifdef Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak
# undef Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak
#else
#error Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak is missing
#endif
#define Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak() (&TSG31CfgAndUse_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak)

#ifdef Rte_Pim_TSG31CfgAndUseMotAg0SPIStart
# undef Rte_Pim_TSG31CfgAndUseMotAg0SPIStart
#else
#error Rte_Pim_TSG31CfgAndUseMotAg0SPIStart is missing
#endif
#define Rte_Pim_TSG31CfgAndUseMotAg0SPIStart() (&TSG31CfgAndUse_Pim_TSG31CfgAndUseMotAg0SPIStart)

#ifdef Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev
# undef Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev
#else
#error Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev is missing
#endif
#define Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() (&TSG31CfgAndUse_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev)

#ifdef Rte_Pim_TSG31CfgAndUseSysStEnaPrev
# undef Rte_Pim_TSG31CfgAndUseSysStEnaPrev
#else
#error Rte_Pim_TSG31CfgAndUseSysStEnaPrev is missing
#endif
#define Rte_Pim_TSG31CfgAndUseSysStEnaPrev() (&TSG31CfgAndUse_Pim_TSG31CfgAndUseSysStEnaPrev)


/*** Client Stub ***/

extern FUNC(void, AUTOMATIC) Rte_Stub(void);


#endif
