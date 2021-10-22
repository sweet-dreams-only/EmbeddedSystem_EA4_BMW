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
 *          File:  Rte_BmwMsgSlot107Bas0Repn1BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot107Bas0Repn1BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_H
# define _RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_H

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

# include "Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxVal_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwQuadOffsSts1, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwActIntgtdCtrlModlPosnIdxValVld_Logl (FALSE)
#  define Rte_InitValue_BmwQuadOffsSts_Val (15U)
#  define Rte_InitValue_BmwQuadOffsStsVld_Logl (FALSE)
#  define Rte_InitValue_BmwQuadRtrOffs_Val (0)
#  define Rte_InitValue_BmwQuadRtrOffsVld_Logl (FALSE)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS(P2VAR(sigGroup_OFFS_QUAD_EPS1, AUTOMATIC, RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot107Bas0Repn1BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS Rte_Read_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS Rte_IsUpdated_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS
#  define Rte_IsUpdated_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwActIntgtdCtrlModlPosnIdxVal_Val Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxVal_Val
#  define Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxVal_Val(data) (Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxVal_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwActIntgtdCtrlModlPosnIdxValVld_Logl Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValVld_Logl
#  define Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValVld_Logl(data) (Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwQuadOffsSts_Val Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val
#  define Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val(data) (Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwQuadOffsStsVld_Logl Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl
#  define Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl(data) (Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwQuadRtrOffs_Val Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val
#  define Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val(data) (Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwQuadRtrOffsVld_Logl Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl
#  define Rte_Write_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl(data) (Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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

#  define Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val() (-1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(AVL_PO_IDX_ICM1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Dummy_PIM1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AlvFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AlvPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AvlPoIdxIcmFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AvlPoIdxIcmPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwQuadOffsSts1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_CrcFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_CrcPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ST_OFFS_QUAD_EPS1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Dummy_PIM2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(OFFS_QUAD_RTR_EPS1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Dummy_PIM3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_MissMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_OffsQuadRtrEpsFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_OffsQuadRtrEpsPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_RxdMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_StOffsQuadEpsFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_StOffsQuadEpsPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwActIntgtdCtrlModlPosnIdxValPrev() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwActIntgtdCtrlModlPosnIdxValPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM1() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Dummy_PIM1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AlvFaildCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AlvFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AlvPassdCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AlvPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AvlPoIdxIcmFaildCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AvlPoIdxIcmFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AvlPoIdxIcmPassdCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_AvlPoIdxIcmPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwQuadOffsStsPrev() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcFaildCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_CrcFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CrcPassdCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_CrcPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM2() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Dummy_PIM2) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Dummy_PIM3() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_Dummy_PIM3) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissMsgCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_MissMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_OffsQuadRtrEpsFaildCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_OffsQuadRtrEpsFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_OffsQuadRtrEpsPassdCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_OffsQuadRtrEpsPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RxdMsgCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_RxdMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StOffsQuadEpsFaildCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_StOffsQuadEpsFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_StOffsQuadEpsPassdCnt() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_StOffsQuadEpsPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwQuadRtrOffsPrev() \
  (&Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot107Bas0Repn1BusFrChA_START_SEC_CODE
# include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot107Bas0Repn1BusFrChAInit1 BmwMsgSlot107Bas0Repn1BusFrChAInit1
#  define RTE_RUNNABLE_OFFS_QUAD_EPS_Missing_Oper OFFS_QUAD_EPS_Missing_Oper
#  define RTE_RUNNABLE_OFFS_QUAD_EPS_Received_Oper OFFS_QUAD_EPS_Received_Oper
# endif

FUNC(void, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) BmwMsgSlot107Bas0Repn1BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) OFFS_QUAD_EPS_Missing_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) OFFS_QUAD_EPS_Received_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot107Bas0Repn1BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT107BAS0REPN1BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
