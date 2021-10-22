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
 *          File:  TSC_CDD_TSG31CfgAndUse.h
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
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Read_MotCurrEolCalSt_Val(MotCurrEolCalSt2 *data);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Read_PhaDiscnctDiagcActv_Logl(boolean *data);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Read_SysSt_Val(SysSt1 *data);

/** Client server interfaces */
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper(void);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg);
Std_ReturnType TSC_CDD_TSG31CfgAndUse_Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg);

/** Calibration Component Calibration Parameters */
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolFixdPwmPerd_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_PhaDiscnctFixdPhaOnTi_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_PhaDiscnctFixdPwmPerd_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val(void);
uint32  TSC_CDD_TSG31CfgAndUse_Rte_Prm_TSG31CfgAndUsePwmDbnd_Val(void);

/** Per Instance Memories */
uint32 *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak(void);
uint32 *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseMotAg0SPIStart(void);
uint16 *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdCoarse(void);
uint16 *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdFine(void);
uint16 *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMaxCntr(void);
uint16 *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdMinCntr(void);
uint8 *TSC_CDD_TSG31CfgAndUse_Rte_Pim_MissUpdIninCntr(void);
boolean *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev(void);
boolean *TSC_CDD_TSG31CfgAndUse_Rte_Pim_TSG31CfgAndUseSysStEnaPrev(void);



