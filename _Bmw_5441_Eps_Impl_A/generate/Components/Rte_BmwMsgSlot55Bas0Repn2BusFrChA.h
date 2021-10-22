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
 *          File:  Rte_BmwMsgSlot55Bas0Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot55Bas0Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT55BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT55BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot55Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatA_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwVehLatA_Val (0.0F)
#  define Rte_InitValue_BmwVehLatAQlfr_Val (15U)
#  define Rte_InitValue_BmwVehLatAQlfrVld_Logl (FALSE)
#  define Rte_InitValue_BmwVehLatAVld_Logl (FALSE)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(P2VAR(sigGroup_ACLNY_MASSCNTR1, AUTOMATIC, RTE_BMWMSGSLOT55BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot55Bas0Repn2BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot55Bas0Repn2BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot55Bas0Repn2BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR Rte_Read_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR Rte_IsUpdated_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR
#  define Rte_IsUpdated_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwVehLatA_Val Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatA_Val
#  define Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatA_Val(data) (Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatA_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwVehLatAQlfr_Val Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfr_Val
#  define Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfr_Val(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwVehLatAQlfrVld_Logl Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfrVld_Logl
#  define Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfrVld_Logl(data) (Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwVehLatAVld_Logl Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAVld_Logl
#  define Rte_Write_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAVld_Logl(data) (Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwMsgSlot55Bas0Repn2BusFrChABmwLatAPolarity_Val() (-1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AclnyCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AclnyCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehLatAQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_MissingMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_QuAclnyCogFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_QuAclnyCogPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot55Bas0Repn2BusFrChA_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwVehLatAPrev() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AclnyCogFaildCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AclnyCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AclnyCogPassdCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AclnyCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AlvFaildCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AlvPassdCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwVehLatAQlfrPrev() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_BmwVehLatAQlfrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcFaildCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcPassdCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissingMsgCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_MissingMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuAclnyCogFaildCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_QuAclnyCogFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_QuAclnyCogPassdCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_QuAclnyCogPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RxdMsgCnt() \
  (&Rte_BmwMsgSlot55Bas0Repn2BusFrChA_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot55Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ACLNY_MASSCNTR_Missing_Oper ACLNY_MASSCNTR_Missing_Oper
#  define RTE_RUNNABLE_ACLNY_MASSCNTR_Received_Oper ACLNY_MASSCNTR_Received_Oper
#  define RTE_RUNNABLE_BmwMsgSlot55Bas0Repn2BusFrChAInit1 BmwMsgSlot55Bas0Repn2BusFrChAInit1
# endif

FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) ACLNY_MASSCNTR_Missing_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) ACLNY_MASSCNTR_Received_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) BmwMsgSlot55Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot55Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT55BAS0REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
