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
 *          File:  Rte_BmwMsgSlot53Bas3Repn8BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot53Bas3Repn8BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_H
# define _RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_H

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

# include "Rte_BmwMsgSlot53Bas3Repn8BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwRtIdx1, RTE_VAR_INIT) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFac_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwRtIdx_Val (15U)
#  define Rte_InitValue_BmwRtIdxVld_Logl (FALSE)
#  define Rte_InitValue_BmwSteerMdfnFac_Val (0.0F)
#  define Rte_InitValue_BmwSteerMdfnFacSts_Val (4U)
#  define Rte_InitValue_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP (255U)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
#  define Rte_InitValue_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP (15U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP(P2VAR(FACT_MO_STE_SO_DXP1, AUTOMATIC, RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP(P2VAR(SU_CLU_STMOM_SFE_DXP1, AUTOMATIC, RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot53Bas3Repn8BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP Rte_Read_BmwMsgSlot53Bas3Repn8BusFrChA_SU_CLU_STMOM_SFE_DXP_SU_CLU_STMOM_SFE_DXP


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP Rte_IsUpdated_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP
#  define Rte_IsUpdated_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot53Bas3Repn8BusFrChA_FACT_MO_STE_SO_DXP_FACT_MO_STE_SO_DXP_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwRtIdx_Val Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val
#  define Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val(data) (Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdx_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwRtIdxVld_Logl Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl
#  define Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl(data) (Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwSteerMdfnFac_Val Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFac_Val
#  define Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFac_Val(data) (Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFac_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwSteerMdfnFacSts_Val Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacSts_Val
#  define Rte_Write_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacSts_Val(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwRtIdx1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwSteerMdfnFacSts1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_FactMoSteSoDxpVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_FactMoSteSoDxpVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_MissMsgFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_MissMsgPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_SuCluStmomSfeDxpVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot53Bas3Repn8BusFrChA_SuCluStmomSfeDxpVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwSteerMdfnFacPrev() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwRtIdxPrev() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwRtIdxPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwSteerMdfnFacStsPrev() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_BmwSteerMdfnFacStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactMoSteSoDxpVldFaild() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_FactMoSteSoDxpVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FactMoSteSoDxpVldPassd() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_FactMoSteSoDxpVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissMsgFaild() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_MissMsgFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissMsgPassd() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_MissMsgPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SuCluStmomSfeDxpVldFaild() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_SuCluStmomSfeDxpVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SuCluStmomSfeDxpVldPassd() \
  (&Rte_BmwMsgSlot53Bas3Repn8BusFrChA_SuCluStmomSfeDxpVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot53Bas3Repn8BusFrChA_START_SEC_CODE
# include "BmwMsgSlot53Bas3Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot53Bas3Repn8BusFrChAInit1 BmwMsgSlot53Bas3Repn8BusFrChAInit1
#  define RTE_RUNNABLE_SU_CLE_DRDY_DXP_Miss SU_CLE_DRDY_DXP_Miss
#  define RTE_RUNNABLE_SU_CLE_DRDY_DXP_Rxd SU_CLE_DRDY_DXP_Rxd
# endif

FUNC(void, BmwMsgSlot53Bas3Repn8BusFrChA_CODE) BmwMsgSlot53Bas3Repn8BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot53Bas3Repn8BusFrChA_CODE) SU_CLE_DRDY_DXP_Miss(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot53Bas3Repn8BusFrChA_CODE) SU_CLE_DRDY_DXP_Rxd(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot53Bas3Repn8BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot53Bas3Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT53BAS3REPN8BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
