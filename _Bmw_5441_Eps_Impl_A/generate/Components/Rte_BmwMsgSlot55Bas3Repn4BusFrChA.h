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
 *          File:  Rte_BmwMsgSlot55Bas3Repn4BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot55Bas3Repn4BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_H
# define _RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_H

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

# include "Rte_BmwMsgSlot55Bas3Repn4BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwCogVehSpdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwNearStillVehSpdSts1, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwCogVehSpd_Val (0.0F)
#  define Rte_InitValue_BmwCogVehSpdQlfr_Val (15U)
#  define Rte_InitValue_BmwCogVehSpdQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwCogVehSpdVld_Logl (FALSE)
#  define Rte_InitValue_BmwNearStillVehSpdSts_Val (15U)
#  define Rte_InitValue_BmwNearStillVehSpdStsVld_Logl (FALSE)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH(P2VAR(sigGroup_V_VEH1, AUTOMATIC, RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_sigGroup_V_VEH_sigGroup_V_VEH Rte_Read_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_sigGroup_V_VEH_sigGroup_V_VEH Rte_IsUpdated_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH
#  define Rte_IsUpdated_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwCogVehSpd_Val Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val
#  define Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val(data) (Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwCogVehSpdQlfr_Val Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val
#  define Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val(data) (Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwCogVehSpdQlfrVld_Logl Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl
#  define Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl(data) (Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwCogVehSpdVld_Logl Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl
#  define Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl(data) (Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwNearStillVehSpdSts_Val Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val
#  define Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val(data) (Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwNearStillVehSpdStsVld_Logl Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl
#  define Rte_Write_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl(data) (Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwCogVehSpdQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwNearStillVehSpdSts1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(QU_V_VEH_COG1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_Dummy_PIM1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ST_V_VEH_NSS1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_Dummy_PIM2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_MissMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_QlfrCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_QlfrCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_StVehNearStillFailCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_StVehNearStillPassCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_VehCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_VehCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwCogVehSpdPrev() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AlvFaildCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AlvPassdCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwCogVehSpdQlfrPrev() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwNearStillVehSpdStsPrev() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcFaildCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcPassdCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM1() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_Dummy_PIM1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM2() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_Dummy_PIM2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissMsgCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_MissMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QlfrCogFaildCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_QlfrCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QlfrCogPassdCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_QlfrCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RxdMsgCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StVehNearStillFailCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_StVehNearStillFailCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StVehNearStillPassCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_StVehNearStillPassCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehCogFaildCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_VehCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehCogPassdCnt() \
  (&Rte_BmwMsgSlot55Bas3Repn4BusFrChA_VehCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot55Bas3Repn4BusFrChA_START_SEC_CODE
# include "BmwMsgSlot55Bas3Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot55Bas3Repn4BusFrChAInit1 BmwMsgSlot55Bas3Repn4BusFrChAInit1
#  define RTE_RUNNABLE_V_VEH_Missing_Oper V_VEH_Missing_Oper
#  define RTE_RUNNABLE_V_VEH_Received_Oper V_VEH_Received_Oper
# endif

FUNC(void, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) BmwMsgSlot55Bas3Repn4BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) V_VEH_Missing_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) V_VEH_Received_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot55Bas3Repn4BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot55Bas3Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT55BAS3REPN4BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
