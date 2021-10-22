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
 *          File:  Rte_FltInj.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/DF001A_FltInj_Impl-nz2999/DF001A_FltInj_Impl/tools/Component.dpa
 *     SW-C Type:  FltInj
 *  Generated at:  Thu Mar 22 08:20:06 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <FltInj> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_FLTINJ_H
# define _RTE_FLTINJ_H

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

# include "Rte_FltInj_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_FltInj
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_FltInj, RTE_CONST, RTE_CONST) Rte_Inst_FltInj; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_FltInj, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwVel_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_FltInj_HwVel_Val(P2VAR(float32, AUTOMATIC, RTE_FLTINJ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FltInj_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_FLTINJ_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_FltInj_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_FLTINJ_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwVel_Val Rte_Read_FltInj_HwVel_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_FltInj_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_FltInj_GetTiSpan100MicroSec32bit_Oper




# define FltInj_START_SEC_CODE
# include "FltInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: FltInjPer1
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
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FltInjPer1 FltInjPer1
FUNC(void, FltInj_CODE) FltInjPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FltInj_f32_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <FltInj_f32>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FltInj_f32_Oper FltInj_f32_Oper
FUNC(void, FltInj_CODE) FltInj_f32_Oper(P2VAR(float32, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FltInj_logl_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <FltInj_logl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void FltInj_logl_Oper(boolean *SigPah_Arg, uint16 LocnKey_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FltInj_logl_Oper FltInj_logl_Oper
FUNC(void, FltInj_CODE) FltInj_logl_Oper(P2VAR(boolean, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FltInj_u08_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <FltInj_u08>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void FltInj_u08_Oper(uint8 *SigPah_Arg, uint16 LocnKey_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FltInj_u08_Oper FltInj_u08_Oper
FUNC(void, FltInj_CODE) FltInj_u08_Oper(P2VAR(uint8, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FltInj_u0p16_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <FltInj_u0p16>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void FltInj_u0p16_Oper(u0p16 *SigPah_Arg, uint16 LocnKey_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FltInj_u0p16_Oper FltInj_u0p16_Oper
FUNC(void, FltInj_CODE) FltInj_u0p16_Oper(P2VAR(u0p16, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define FltInj_STOP_SEC_CODE
# include "FltInj_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_FLTINJ_H */

#include "Rte_Stubs.h"
