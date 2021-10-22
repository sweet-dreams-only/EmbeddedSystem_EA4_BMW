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
 *          File:  Rte_SteerCmdArbnAndLim.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <SteerCmdArbnAndLim>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_STEERCMDARBNANDLIM_H
# define _RTE_STEERCMDARBNANDLIM_H

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

# include "Rte_SteerCmdArbnAndLim_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_EotProtn_EotAssiSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl7_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_StallMotTqLimCdnd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_SysMotTqCmdScaCdnd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_ThermMotTqLimCdnd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_VehSpdMotTqLimCdnd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_SteerCmdArbnAndLim_ArbdMotTqCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_SteerCmdArbnAndLim_MotTqCmdLimdPreStall_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CmnMfgSrv_AssiLnrGain_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CmnMfgSrv_AssiLnrGainEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_FalbckAssi_FalbckAssiMotTqCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_GlbLimr_LimdMotTqCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SteerCmdArbnAndLim_MotTqCmdLimDi_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ArbdMotTqCmd_Val (0.0F)
#  define Rte_InitValue_AssiLnrGain_Val (0.0F)
#  define Rte_InitValue_AssiLnrGainEna_Logl (FALSE)
#  define Rte_InitValue_EotCtrlSca_Val (1.0F)
#  define Rte_InitValue_FalbckAssiMotTqCmd_Val (0.0F)
#  define Rte_InitValue_HwTq_Val (0.0F)
#  define Rte_InitValue_LimdMotTqCmd_Val (0.0F)
#  define Rte_InitValue_MotTqCmd_Val (0.0F)
#  define Rte_InitValue_MotTqCmdLimDi_Logl (FALSE)
#  define Rte_InitValue_MotTqCmdLimdPreStall_Val (0.0F)
#  define Rte_InitValue_StallMotTqLim_Val (8.8F)
#  define Rte_InitValue_SysMotTqCmdSca_Val (1.0F)
#  define Rte_InitValue_ThermMotTqLim_Val (8.8F)
#  define Rte_InitValue_VehSpd_Val (0.0F)
#  define Rte_InitValue_VehSpdMotTqLim_Val (8.8F)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_Irv_SteerCmdArbnAndLim_ProcdManTqCmd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_Irv_SteerCmdArbnAndLim_ProcdManTqCmdEna; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AssiLnrGain_Val Rte_Read_SteerCmdArbnAndLim_AssiLnrGain_Val
#  define Rte_Read_SteerCmdArbnAndLim_AssiLnrGain_Val(data) (*(data) = Rte_CmnMfgSrv_AssiLnrGain_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_AssiLnrGainEna_Logl Rte_Read_SteerCmdArbnAndLim_AssiLnrGainEna_Logl
#  define Rte_Read_SteerCmdArbnAndLim_AssiLnrGainEna_Logl(data) (*(data) = Rte_CmnMfgSrv_AssiLnrGainEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_EotCtrlSca_Val Rte_Read_SteerCmdArbnAndLim_EotCtrlSca_Val
#  define Rte_Read_SteerCmdArbnAndLim_EotCtrlSca_Val(data) (*(data) = Rte_EotProtn_EotAssiSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_FalbckAssiMotTqCmd_Val Rte_Read_SteerCmdArbnAndLim_FalbckAssiMotTqCmd_Val
#  define Rte_Read_SteerCmdArbnAndLim_FalbckAssiMotTqCmd_Val(data) (*(data) = Rte_FalbckAssi_FalbckAssiMotTqCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_HwTq_Val Rte_Read_SteerCmdArbnAndLim_HwTq_Val
#  define Rte_Read_SteerCmdArbnAndLim_HwTq_Val(data) (*(data) = Rte_HwTqArbn_HwTq_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_LimdMotTqCmd_Val Rte_Read_SteerCmdArbnAndLim_LimdMotTqCmd_Val
#  define Rte_Read_SteerCmdArbnAndLim_LimdMotTqCmd_Val(data) (*(data) = Rte_GlbLimr_LimdMotTqCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmd_Val Rte_Read_SteerCmdArbnAndLim_MotTqCmd_Val
#  define Rte_Read_SteerCmdArbnAndLim_MotTqCmd_Val(data) (*(data) = Rte_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmdLimDi_Logl Rte_Read_SteerCmdArbnAndLim_MotTqCmdLimDi_Logl
#  define Rte_Read_SteerCmdArbnAndLim_MotTqCmdLimDi_Logl(data) (*(data) = Rte_SteerCmdArbnAndLim_MotTqCmdLimDi_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_StallMotTqLim_Val Rte_Read_SteerCmdArbnAndLim_StallMotTqLim_Val
#  define Rte_Read_SteerCmdArbnAndLim_StallMotTqLim_Val(data) (*(data) = Rte_LimrCdng_StallMotTqLimCdnd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysMotTqCmdSca_Val Rte_Read_SteerCmdArbnAndLim_SysMotTqCmdSca_Val
#  define Rte_Read_SteerCmdArbnAndLim_SysMotTqCmdSca_Val(data) (*(data) = Rte_LimrCdng_SysMotTqCmdScaCdnd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_ThermMotTqLim_Val Rte_Read_SteerCmdArbnAndLim_ThermMotTqLim_Val
#  define Rte_Read_SteerCmdArbnAndLim_ThermMotTqLim_Val(data) (*(data) = Rte_LimrCdng_ThermMotTqLimCdnd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_SteerCmdArbnAndLim_VehSpd_Val
#  define Rte_Read_SteerCmdArbnAndLim_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpdMotTqLim_Val Rte_Read_SteerCmdArbnAndLim_VehSpdMotTqLim_Val
#  define Rte_Read_SteerCmdArbnAndLim_VehSpdMotTqLim_Val(data) (*(data) = Rte_LimrCdng_VehSpdMotTqLimCdnd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ArbdMotTqCmd_Val Rte_Write_SteerCmdArbnAndLim_ArbdMotTqCmd_Val
#  define Rte_Write_SteerCmdArbnAndLim_ArbdMotTqCmd_Val(data) (Rte_SteerCmdArbnAndLim_ArbdMotTqCmd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotTqCmdLimdPreStall_Val Rte_Write_SteerCmdArbnAndLim_MotTqCmdLimdPreStall_Val
#  define Rte_Write_SteerCmdArbnAndLim_MotTqCmdLimdPreStall_Val(data) (Rte_SteerCmdArbnAndLim_MotTqCmdLimdPreStall_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr100MicroSec32bit_Oper(arg1) (GetRefTmr100MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan100MicroSec32bit_Oper(arg1, arg2) (GetTiSpan100MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd(data) \
  (Rte_Irv_SteerCmdArbnAndLim_ProcdManTqCmd = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna(data) \
  (Rte_Irv_SteerCmdArbnAndLim_ProcdManTqCmdEna = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd() \
  Rte_Irv_SteerCmdArbnAndLim_ProcdManTqCmd
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna() \
  Rte_Irv_SteerCmdArbnAndLim_ProcdManTqCmdEna
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->SteerCmdArbnAndLimFalbckTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupC_DEFAULT_RTE_CALPRM_GROUP])->SteerCmdArbnAndLimFwTiThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SteerCmdArbnAndLim_SteerCmdArbnAndLimDebStFalbck; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SteerCmdArbnAndLim_SteerCmdArbnAndLimDebStFw; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SteerCmdArbnAndLim_SteerCmdArbnAndLimSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SteerCmdArbnAndLim_FalbckDebStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SteerCmdArbnAndLim_FwDebStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_SteerCmdArbnAndLimDebStFalbck() \
  (&Rte_SteerCmdArbnAndLim_SteerCmdArbnAndLimDebStFalbck) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SteerCmdArbnAndLimDebStFw() \
  (&Rte_SteerCmdArbnAndLim_SteerCmdArbnAndLimDebStFw) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SteerCmdArbnAndLimSt() \
  (&Rte_SteerCmdArbnAndLim_SteerCmdArbnAndLimSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FalbckDebStVari() \
  (&Rte_SteerCmdArbnAndLim_FalbckDebStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FwDebStVari() \
  (&Rte_SteerCmdArbnAndLim_FwDebStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define SteerCmdArbnAndLim_START_SEC_CODE
# include "SteerCmdArbnAndLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SetManTqCmd_Oper SetManTqCmd_Oper
#  define RTE_RUNNABLE_SteerCmdArbnAndLimInit1 SteerCmdArbnAndLimInit1
#  define RTE_RUNNABLE_SteerCmdArbnAndLimPer1 SteerCmdArbnAndLimPer1
# endif

FUNC(Std_ReturnType, SteerCmdArbnAndLim_CODE) SetManTqCmd_Oper(float32 ManTqCmd_Arg, boolean ManTqCmdEna_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, SteerCmdArbnAndLim_CODE) SteerCmdArbnAndLimInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, SteerCmdArbnAndLim_CODE) SteerCmdArbnAndLimPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define SteerCmdArbnAndLim_STOP_SEC_CODE
# include "SteerCmdArbnAndLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetManTqCmd_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_STEERCMDARBNANDLIM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
