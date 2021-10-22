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
 *          File:  Rte_CDD_TSG31CfgAndUse.h
 *        Config:  E:/EA4NewTemplate/CM475A_TSG31CfgAndUse_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_TSG31CfgAndUse
 *  Generated at:  Tue Jan 23 10:19:42 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_TSG31CfgAndUse> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_TSG31CFGANDUSE_H
# define _RTE_CDD_TSG31CFGANDUSE_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_TSG31CfgAndUse_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_TSG31CfgAndUse
{
  /* PIM Handles section */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissUpdCoarse; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissUpdFine; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissUpdIninCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissUpdMaxCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MissUpdMinCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TSG31CfgAndUseMotAg0SPIStart; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TSG31CfgAndUsePhaDiscntActvdStPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_TSG31CfgAndUseSysStEnaPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_TSG31CfgAndUse, RTE_CONST, RTE_CONST) Rte_Inst_CDD_TSG31CfgAndUse; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_TSG31CfgAndUse, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotCurrEolCalSt_Val (0U)
# define Rte_InitValue_PhaDiscnctDiagcActv_Logl (FALSE)
# define Rte_InitValue_SysSt_Val (3U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_TSG31CfgAndUse_MotCurrEolCalSt_Val(P2VAR(MotCurrEolCalSt2, AUTOMATIC, RTE_CDD_TSG31CFGANDUSE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_TSG31CfgAndUse_PhaDiscnctDiagcActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_CDD_TSG31CFGANDUSE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_TSG31CfgAndUse_SysSt_Val(P2VAR(SysSt1, AUTOMATIC, RTE_CDD_TSG31CFGANDUSE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaALowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_CurrMeasEolFixdPwmPerd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_CurrMeasEolOffsHiCmuOffs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_CurrMeasEolOffsLoCmuOffs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_PhaDiscnctFixdPhaOnTi_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_PhaDiscnctFixdPwmPerd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseMtrAg0SPIStart_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUsePwmDbnd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotCurrEolCalSt_Val Rte_Read_CDD_TSG31CfgAndUse_MotCurrEolCalSt_Val
# define Rte_Read_PhaDiscnctDiagcActv_Logl Rte_Read_CDD_TSG31CfgAndUse_PhaDiscnctDiagcActv_Logl
# define Rte_Read_SysSt_Val Rte_Read_CDD_TSG31CfgAndUse_SysSt_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaALowrCmd_Oper
# define Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaAUpprCmd_Oper
# define Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaBLowrCmd_Oper
# define Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaBUpprCmd_Oper
# define Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaCLowrCmd_Oper
# define Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctGpioPhaCUpprCmd_Oper
# define Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaALowrCmd_Oper
# define Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper
# define Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper
# define Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper
# define Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper
# define Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper
# define Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaALowrCmd_Oper
# define Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaAUpprCmd_Oper
# define Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaBLowrCmd_Oper
# define Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaBUpprCmd_Oper
# define Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaCLowrCmd_Oper
# define Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper Rte_Call_CDD_TSG31CfgAndUse_IoHwAb_SetGpioPhaCUpprCmd_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_CurrMeasEolFixdPwmPerd_Val Rte_Prm_CDD_TSG31CfgAndUse_CurrMeasEolFixdPwmPerd_Val

# define Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val Rte_Prm_CDD_TSG31CfgAndUse_CurrMeasEolOffsHiCmuOffs_Val

# define Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val Rte_Prm_CDD_TSG31CfgAndUse_CurrMeasEolOffsLoCmuOffs_Val

# define Rte_Prm_PhaDiscnctFixdPhaOnTi_Val Rte_Prm_CDD_TSG31CfgAndUse_PhaDiscnctFixdPhaOnTi_Val

# define Rte_Prm_PhaDiscnctFixdPwmPerd_Val Rte_Prm_CDD_TSG31CfgAndUse_PhaDiscnctFixdPwmPerd_Val

# define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val

# define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val

# define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val

# define Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUseMtrAg0SPIStart_Val

# define Rte_Prm_TSG31CfgAndUsePwmDbnd_Val Rte_Prm_CDD_TSG31CfgAndUse_TSG31CfgAndUsePwmDbnd_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TSG31CfgAndUseMotAg0SPIStart() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_TSG31CfgAndUseMotAg0SPIStart) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissUpdCoarse() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_MissUpdCoarse) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissUpdFine() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_MissUpdFine) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissUpdMaxCntr() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_MissUpdMaxCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissUpdMinCntr() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_MissUpdMinCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MissUpdIninCntr() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_MissUpdIninCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_TSG31CfgAndUsePhaDiscntActvdStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_TSG31CfgAndUseSysStEnaPrev() (Rte_Inst_CDD_TSG31CfgAndUse->Pim_TSG31CfgAndUseSysStEnaPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak(void)
 *   uint32 *Rte_Pim_TSG31CfgAndUseMotAg0SPIStart(void)
 *   uint16 *Rte_Pim_MissUpdCoarse(void)
 *   uint16 *Rte_Pim_MissUpdFine(void)
 *   uint16 *Rte_Pim_MissUpdMaxCntr(void)
 *   uint16 *Rte_Pim_MissUpdMinCntr(void)
 *   uint8 *Rte_Pim_MissUpdIninCntr(void)
 *   boolean *Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev(void)
 *   boolean *Rte_Pim_TSG31CfgAndUseSysStEnaPrev(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint32 Rte_Prm_CurrMeasEolFixdPwmPerd_Val(void)
 *   uint32 Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val(void)
 *   uint32 Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPhaOnTi_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPwmPerd_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUsePwmDbnd_Val(void)
 *
 *********************************************************************************************************************/


# define CDD_TSG31CfgAndUse_START_SEC_CODE
# include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSG31CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TSG31CfgAndUseInit1 TSG31CfgAndUseInit1
FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUseInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSG31CfgAndUsePer2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotCurrEolCalSt_Val(MotCurrEolCalSt2 *data)
 *   Std_ReturnType Rte_Read_PhaDiscnctDiagcActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_TSG31CfgAndUsePer2 TSG31CfgAndUsePer2
FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUsePer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_TSG31CfgAndUse_STOP_SEC_CODE
# include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetFctPeriph_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_TSG31CFGANDUSE_H */

#include "Rte_Stubs.h"
