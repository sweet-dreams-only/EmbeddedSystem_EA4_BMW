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
 *          File:  Rte_BmwMsgSlot108Bas0Repn2BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot108Bas0Repn2BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_H
# define _RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_H

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

# include "Rte_BmwMsgSlot108Bas0Repn2BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwPinionAgOffsSts1, RTE_VAR_INIT) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS (2046U)
#  define Rte_InitValue_BmwPinionAgOffs_Val (0.0F)
#  define Rte_InitValue_BmwPinionAgOffsSts_Val (4U)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS(P2VAR(AVL_STEA_PNI_OFFS1, AUTOMATIC, RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot108Bas0Repn2BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot108Bas0Repn2BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS Rte_IsUpdated_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS
#  define Rte_IsUpdated_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS() ((Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS == Rte_Appl10_RxUpdateFlags.Rte_RxUpdate_BmwMsgSlot108Bas0Repn2BusFrChA_AVL_STEA_PNI_OFFS_AVL_STEA_PNI_OFFS_Sender) ? FALSE : TRUE) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwPinionAgOffs_Val Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val
#  define Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val(data) (Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwPinionAgOffsSts_Val Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val
#  define Rte_Write_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val(data) (Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_AvlSteaPniOffsFaildCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_AvlSteaPniOffsPassdCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_MissingMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_RxMsgCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwPinionAgOffsPrev() \
  (&Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AvlSteaPniOffsFaildCnt() \
  (&Rte_BmwMsgSlot108Bas0Repn2BusFrChA_AvlSteaPniOffsFaildCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AvlSteaPniOffsPassdCnt() \
  (&Rte_BmwMsgSlot108Bas0Repn2BusFrChA_AvlSteaPniOffsPassdCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MissingMsgCnt() \
  (&Rte_BmwMsgSlot108Bas0Repn2BusFrChA_MissingMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_RxMsgCnt() \
  (&Rte_BmwMsgSlot108Bas0Repn2BusFrChA_RxMsgCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot108Bas0Repn2BusFrChA_START_SEC_CODE
# include "BmwMsgSlot108Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot108Bas0Repn2BusFrChAInit1 BmwMsgSlot108Bas0Repn2BusFrChAInit1
#  define RTE_RUNNABLE_STEA_OFFS_Missing_Oper STEA_OFFS_Missing_Oper
#  define RTE_RUNNABLE_STEA_OFFS_Received_Oper STEA_OFFS_Received_Oper
# endif

FUNC(void, BmwMsgSlot108Bas0Repn2BusFrChA_CODE) BmwMsgSlot108Bas0Repn2BusFrChAInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot108Bas0Repn2BusFrChA_CODE) STEA_OFFS_Missing_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot108Bas0Repn2BusFrChA_CODE) STEA_OFFS_Received_Oper(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot108Bas0Repn2BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot108Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT108BAS0REPN2BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
