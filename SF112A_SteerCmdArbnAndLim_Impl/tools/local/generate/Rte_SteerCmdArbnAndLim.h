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
 *        Config:  C:/_S/work/ses_dev_ea4/SF112A_SteerCmdArbnAndLim_Impl-z172399/SF112A_SteerCmdArbnAndLim_Impl/tools/Component.dpa
 *     SW-C Type:  SteerCmdArbnAndLim
 *  Generated at:  Fri Apr 27 16:48:20 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <SteerCmdArbnAndLim> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_STEERCMDARBNANDLIM_H
# define _RTE_STEERCMDARBNANDLIM_H

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

# include "Rte_SteerCmdArbnAndLim_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_SteerCmdArbnAndLim
{
  /* PIM Handles section */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FalbckDebStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FwDebStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SteerCmdArbnAndLimDebStFalbck; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SteerCmdArbnAndLimDebStFw; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SteerCmdArbnAndLimSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_SteerCmdArbnAndLim, RTE_CONST, RTE_CONST) Rte_Inst_SteerCmdArbnAndLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_SteerCmdArbnAndLim, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ArbdMotTqCmd_Val (0.0F)
# define Rte_InitValue_AssiLnrGain_Val (0.0F)
# define Rte_InitValue_AssiLnrGainEna_Logl (FALSE)
# define Rte_InitValue_EotCtrlSca_Val (0.0F)
# define Rte_InitValue_FalbckAssiMotTqCmd_Val (0.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_LimdMotTqCmd_Val (0.0F)
# define Rte_InitValue_MotTqCmd_Val (0.0F)
# define Rte_InitValue_MotTqCmdLimDi_Logl (FALSE)
# define Rte_InitValue_MotTqCmdLimdPreStall_Val (0.0F)
# define Rte_InitValue_StallMotTqLim_Val (8.8F)
# define Rte_InitValue_SysMotTqCmdSca_Val (1.0F)
# define Rte_InitValue_ThermMotTqLim_Val (8.8F)
# define Rte_InitValue_VehSpd_Val (0.0F)
# define Rte_InitValue_VehSpdMotTqLim_Val (8.8F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_AssiLnrGain_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_AssiLnrGainEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_EotCtrlSca_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_FalbckAssiMotTqCmd_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_LimdMotTqCmd_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_MotTqCmd_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_MotTqCmdLimDi_Logl(P2VAR(boolean, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_StallMotTqLim_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_SysMotTqCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_ThermMotTqLim_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SteerCmdArbnAndLim_VehSpdMotTqLim_Val(P2VAR(float32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SteerCmdArbnAndLim_ArbdMotTqCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SteerCmdArbnAndLim_MotTqCmdLimdPreStall_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SteerCmdArbnAndLim_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SteerCmdArbnAndLim_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_STEERCMDARBNANDLIM_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SteerCmdArbnAndLim_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_SteerCmdArbnAndLim_SteerCmdArbnAndLimFalbckTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_SteerCmdArbnAndLim_SteerCmdArbnAndLimFwTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_SteerCmdArbnAndLim_SetManTqCmd_Oper_ProcdManTqCmd(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_SteerCmdArbnAndLim_SetManTqCmd_Oper_ProcdManTqCmdEna(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_IrvRead_SteerCmdArbnAndLim_SteerCmdArbnAndLimPer1_ProcdManTqCmd(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_IrvRead_SteerCmdArbnAndLim_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_AssiLnrGain_Val Rte_Read_SteerCmdArbnAndLim_AssiLnrGain_Val
# define Rte_Read_AssiLnrGainEna_Logl Rte_Read_SteerCmdArbnAndLim_AssiLnrGainEna_Logl
# define Rte_Read_EotCtrlSca_Val Rte_Read_SteerCmdArbnAndLim_EotCtrlSca_Val
# define Rte_Read_FalbckAssiMotTqCmd_Val Rte_Read_SteerCmdArbnAndLim_FalbckAssiMotTqCmd_Val
# define Rte_Read_HwTq_Val Rte_Read_SteerCmdArbnAndLim_HwTq_Val
# define Rte_Read_LimdMotTqCmd_Val Rte_Read_SteerCmdArbnAndLim_LimdMotTqCmd_Val
# define Rte_Read_MotTqCmd_Val Rte_Read_SteerCmdArbnAndLim_MotTqCmd_Val
# define Rte_Read_MotTqCmdLimDi_Logl Rte_Read_SteerCmdArbnAndLim_MotTqCmdLimDi_Logl
# define Rte_Read_StallMotTqLim_Val Rte_Read_SteerCmdArbnAndLim_StallMotTqLim_Val
# define Rte_Read_SysMotTqCmdSca_Val Rte_Read_SteerCmdArbnAndLim_SysMotTqCmdSca_Val
# define Rte_Read_ThermMotTqLim_Val Rte_Read_SteerCmdArbnAndLim_ThermMotTqLim_Val
# define Rte_Read_VehSpd_Val Rte_Read_SteerCmdArbnAndLim_VehSpd_Val
# define Rte_Read_VehSpdMotTqLim_Val Rte_Read_SteerCmdArbnAndLim_VehSpdMotTqLim_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_ArbdMotTqCmd_Val Rte_Write_SteerCmdArbnAndLim_ArbdMotTqCmd_Val
# define Rte_Write_MotTqCmdLimdPreStall_Val Rte_Write_SteerCmdArbnAndLim_MotTqCmdLimdPreStall_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_SteerCmdArbnAndLim_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_SteerCmdArbnAndLim_GetTiSpan100MicroSec32bit_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_SteerCmdArbnAndLim_SetNtcSts_Oper


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd(data) \
  Rte_IrvWrite_SteerCmdArbnAndLim_SetManTqCmd_Oper_ProcdManTqCmd(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna(data) \
  Rte_IrvWrite_SteerCmdArbnAndLim_SetManTqCmd_Oper_ProcdManTqCmdEna(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd() \
  Rte_IrvRead_SteerCmdArbnAndLim_SteerCmdArbnAndLimPer1_ProcdManTqCmd()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna() \
  Rte_IrvRead_SteerCmdArbnAndLim_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna()
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val Rte_Prm_SteerCmdArbnAndLim_SteerCmdArbnAndLimFalbckTiThd_Val

# define Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val Rte_Prm_SteerCmdArbnAndLim_SteerCmdArbnAndLimFwTiThd_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_SteerCmdArbnAndLimDebStFalbck() (Rte_Inst_SteerCmdArbnAndLim->Pim_SteerCmdArbnAndLimDebStFalbck) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SteerCmdArbnAndLimDebStFw() (Rte_Inst_SteerCmdArbnAndLim->Pim_SteerCmdArbnAndLimDebStFw) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SteerCmdArbnAndLimSt() (Rte_Inst_SteerCmdArbnAndLim->Pim_SteerCmdArbnAndLimSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FalbckDebStVari() (Rte_Inst_SteerCmdArbnAndLim->Pim_FalbckDebStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FwDebStVari() (Rte_Inst_SteerCmdArbnAndLim->Pim_FwDebStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_SteerCmdArbnAndLimDebStFalbck(void)
 *   uint32 *Rte_Pim_SteerCmdArbnAndLimDebStFw(void)
 *   uint8 *Rte_Pim_SteerCmdArbnAndLimSt(void)
 *   boolean *Rte_Pim_FalbckDebStVari(void)
 *   boolean *Rte_Pim_FwDebStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint16 Rte_Prm_SteerCmdArbnAndLimFalbckTiThd_Val(void)
 *   uint16 Rte_Prm_SteerCmdArbnAndLimFwTiThd_Val(void)
 *
 *********************************************************************************************************************/


# define SteerCmdArbnAndLim_START_SEC_CODE
# include "SteerCmdArbnAndLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetManTqCmd_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetManTqCmd>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmd(float32 data)
 *   void Rte_IrvWrite_SetManTqCmd_Oper_ProcdManTqCmdEna(boolean data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SetManTqCmd_Oper(float32 ManTqCmd_Arg, boolean ManTqCmdEna_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SetManTqCmd_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SetManTqCmd_Oper SetManTqCmd_Oper
FUNC(Std_ReturnType, SteerCmdArbnAndLim_CODE) SetManTqCmd_Oper(float32 ManTqCmd_Arg, boolean ManTqCmdEna_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SteerCmdArbnAndLimInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SteerCmdArbnAndLimInit1 SteerCmdArbnAndLimInit1
FUNC(void, SteerCmdArbnAndLim_CODE) SteerCmdArbnAndLimInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SteerCmdArbnAndLimPer1
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
 *   Std_ReturnType Rte_Read_AssiLnrGain_Val(float32 *data)
 *   Std_ReturnType Rte_Read_AssiLnrGainEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_EotCtrlSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_FalbckAssiMotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_LimdMotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdLimDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_StallMotTqLim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysMotTqCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_ThermMotTqLim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdMotTqLim_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ArbdMotTqCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotTqCmdLimdPreStall_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmd(void)
 *   boolean Rte_IrvRead_SteerCmdArbnAndLimPer1_ProcdManTqCmdEna(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_SteerCmdArbnAndLimPer1 SteerCmdArbnAndLimPer1
FUNC(void, SteerCmdArbnAndLim_CODE) SteerCmdArbnAndLimPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define SteerCmdArbnAndLim_STOP_SEC_CODE
# include "SteerCmdArbnAndLim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetManTqCmd_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_STEERCMDARBNANDLIM_H */

#include "Rte_Stubs.h"
