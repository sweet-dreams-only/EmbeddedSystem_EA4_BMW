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
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_TSG31CfgAndUse>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_TSG31CFGANDUSE_H
# define _RTE_CDD_TSG31CFGANDUSE_H

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

# include "Rte_CDD_TSG31CfgAndUse_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MotCurrEolCalSt2, RTE_VAR_INIT) Rte_CDD_CurrMeas_MotCurrEolCalSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_PhaDiscnct_PhaDiscnctDiagcActv_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotCurrEolCalSt_Val (0U)
#  define Rte_InitValue_PhaDiscnctDiagcActv_Logl (FALSE)
#  define Rte_InitValue_SysSt_Val (3U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotCurrEolCalSt_Val Rte_Read_CDD_TSG31CfgAndUse_MotCurrEolCalSt_Val
#  define Rte_Read_CDD_TSG31CfgAndUse_MotCurrEolCalSt_Val(data) (*(data) = Rte_CDD_CurrMeas_MotCurrEolCalSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PhaDiscnctDiagcActv_Logl Rte_Read_CDD_TSG31CfgAndUse_PhaDiscnctDiagcActv_Logl
#  define Rte_Read_CDD_TSG31CfgAndUse_PhaDiscnctDiagcActv_Logl(data) (*(data) = Rte_PhaDiscnct_PhaDiscnctDiagcActv_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysSt_Val Rte_Read_CDD_TSG31CfgAndUse_SysSt_Val
#  define Rte_Read_CDD_TSG31CfgAndUse_SysSt_Val(data) (*(data) = Rte_SysStMod_SysSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioPhaALowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper IoHwAb_SetFctGpioPhaALowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper IoHwAb_SetFctGpioPhaAUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper IoHwAb_SetFctGpioPhaBLowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper IoHwAb_SetFctGpioPhaBUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper IoHwAb_SetFctGpioPhaCLowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper IoHwAb_SetFctGpioPhaCUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctPeriphPhaALowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper IoHwAb_SetFctPeriphPhaALowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctPeriphPhaAUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper IoHwAb_SetFctPeriphPhaAUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctPeriphPhaBLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper IoHwAb_SetFctPeriphPhaBLowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctPeriphPhaBUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper IoHwAb_SetFctPeriphPhaBUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctPeriphPhaCLowrCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper IoHwAb_SetFctPeriphPhaCLowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctPeriphPhaCUpprCmd_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper IoHwAb_SetFctPeriphPhaCUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaALowrCmd_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper IoHwAb_SetGpioPhaALowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaAUpprCmd_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper IoHwAb_SetGpioPhaAUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaBLowrCmd_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper IoHwAb_SetGpioPhaBLowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaBUpprCmd_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper IoHwAb_SetGpioPhaBUpprCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaCLowrCmd_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper IoHwAb_SetGpioPhaCLowrCmd_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioPhaCUpprCmd_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper IoHwAb_SetGpioPhaCUpprCmd_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_CurrMeasEolFixdPwmPerd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->CurrMeasEolFixdPwmPerd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->CurrMeasEolOffsHiCmuOffs_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->CurrMeasEolOffsLoCmuOffs_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctFixdPhaOnTi_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctFixdPhaOnTi_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PhaDiscnctFixdPwmPerd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->PhaDiscnctFixdPwmPerd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TSG31CfgAndUseMtrAg0SPIStart_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TSG31CfgAndUsePwmDbnd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->TSG31CfgAndUsePwmDbnd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvnPeak; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseMotAg0SPIStart; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_MissUpdCoarse; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_MissUpdFine; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_MissUpdMaxCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_MissUpdMinCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_MissUpdIninCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUsePhaDiscntActvdStPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseSysStEnaPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak() \
  (&Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvnPeak) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TSG31CfgAndUseMotAg0SPIStart() \
  (&Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseMotAg0SPIStart) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissUpdCoarse() \
  (&Rte_CDD_TSG31CfgAndUse_MissUpdCoarse) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissUpdFine() \
  (&Rte_CDD_TSG31CfgAndUse_MissUpdFine) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissUpdMaxCntr() \
  (&Rte_CDD_TSG31CfgAndUse_MissUpdMaxCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissUpdMinCntr() \
  (&Rte_CDD_TSG31CfgAndUse_MissUpdMinCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissUpdIninCntr() \
  (&Rte_CDD_TSG31CfgAndUse_MissUpdIninCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() \
  (&Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUsePhaDiscntActvdStPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TSG31CfgAndUseSysStEnaPrev() \
  (&Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseSysStEnaPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_TSG31CfgAndUse_START_SEC_CODE
# include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_TSG31CfgAndUseInit1 TSG31CfgAndUseInit1
#  define RTE_RUNNABLE_TSG31CfgAndUsePer2 TSG31CfgAndUsePer2
# endif

FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUseInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUsePer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_TSG31CfgAndUse_STOP_SEC_CODE
# include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetFctPeriph_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_TSG31CFGANDUSE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
