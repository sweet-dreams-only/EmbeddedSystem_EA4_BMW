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
 *          File:  Rte_BmwMsgSlot269Bas2Repn4BusFrChA.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMsgSlot269Bas2Repn4BusFrChA>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_H
# define _RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_H

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

# include "Rte_BmwMsgSlot269Bas2Repn4BusFrChA_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwHaptcFbDirNr1, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwHaptcFbIntenNr1, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwHaptcFbPatNr1, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_FltCodEnad_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BmwHaptcFbDirNr_Val (3U)
#  define Rte_InitValue_BmwHaptcFbDirNrVld_Logl (FALSE)
#  define Rte_InitValue_BmwHaptcFbIntenNr_Val (15U)
#  define Rte_InitValue_BmwHaptcFbIntenNrVld_Logl (FALSE)
#  define Rte_InitValue_BmwHaptcFbPatNr_Val (15U)
#  define Rte_InitValue_BmwHaptcFbPatNrVld_Logl (FALSE)
#  define Rte_InitValue_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS (3U)
#  define Rte_InitValue_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS (15U)
#  define Rte_InitValue_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS (15U)
#  define Rte_InitValue_FltCodEnad_Logl (TRUE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS(P2VAR(CTR_WARN_DIR_VIB_EPS1, AUTOMATIC, RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS(P2VAR(CTR_WARN_ILVL_VIB_EPS1, AUTOMATIC, RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS(P2VAR(CTR_WARN_PTRN_VIB_EPS1, AUTOMATIC, RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_DIR_VIB_EPS_CTR_WARN_DIR_VIB_EPS
#  define Rte_Read_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_ILVL_VIB_EPS_CTR_WARN_ILVL_VIB_EPS
#  define Rte_Read_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_CTR_WARN_PTRN_VIB_EPS_CTR_WARN_PTRN_VIB_EPS
#  define Rte_Read_FltCodEnad_Logl Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_FltCodEnad_Logl
#  define Rte_Read_BmwMsgSlot269Bas2Repn4BusFrChA_FltCodEnad_Logl(data) (*(data) = Rte_BmwMsgSlot269Bas2Repn4BusFrChA_FltCodEnad_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwHaptcFbDirNr_Val Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNr_Val
#  define Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNr_Val(data) (Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwHaptcFbDirNrVld_Logl Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrVld_Logl
#  define Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrVld_Logl(data) (Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwHaptcFbIntenNr_Val Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val
#  define Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val(data) (Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwHaptcFbIntenNrVld_Logl Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl
#  define Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl(data) (Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwHaptcFbPatNr_Val Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val
#  define Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val(data) (Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwHaptcFbPatNrVld_Logl Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl
#  define Rte_Write_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl(data) (Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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

extern VAR(BmwHaptcFbDirNr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwHaptcFbIntenNr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwHaptcFbPatNr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrVibStwDispExmiSp2015MissFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrVibStwDispExmiSp2015MissPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnDirVibEpsVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnDirVibEpsVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnIlvlVibEpsVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnIlvlVibEpsVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnPtrnVibEpsVldFaild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnPtrnVibEpsVldPassd; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwHaptcFbDirNrPrev() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbDirNrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwHaptcFbIntenNrPrev() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbIntenNrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwHaptcFbPatNrPrev() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_BmwHaptcFbPatNrPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrVibStwDispExmiSp2015MissFaild() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrVibStwDispExmiSp2015MissFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrVibStwDispExmiSp2015MissPassd() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrVibStwDispExmiSp2015MissPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrWarnDirVibEpsVldFaild() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnDirVibEpsVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrWarnDirVibEpsVldPassd() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnDirVibEpsVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrWarnIlvlVibEpsVldFaild() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnIlvlVibEpsVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrWarnIlvlVibEpsVldPassd() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnIlvlVibEpsVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrWarnPtrnVibEpsVldFaild() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnPtrnVibEpsVldFaild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CtrWarnPtrnVibEpsVldPassd() \
  (&Rte_BmwMsgSlot269Bas2Repn4BusFrChA_CtrWarnPtrnVibEpsVldPassd) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwMsgSlot269Bas2Repn4BusFrChA_START_SEC_CODE
# include "BmwMsgSlot269Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwMsgSlot269Bas2Repn4BusFrChA_Init BmwMsgSlot269Bas2Repn4BusFrChA_Init
#  define RTE_RUNNABLE_CTR_VIB_STW_DISP_EXMI_SP2015_Missing CTR_VIB_STW_DISP_EXMI_SP2015_Missing
#  define RTE_RUNNABLE_CTR_VIB_STW_DISP_EXMI_SP2015_Received CTR_VIB_STW_DISP_EXMI_SP2015_Received
# endif

FUNC(void, BmwMsgSlot269Bas2Repn4BusFrChA_CODE) BmwMsgSlot269Bas2Repn4BusFrChA_Init(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot269Bas2Repn4BusFrChA_CODE) CTR_VIB_STW_DISP_EXMI_SP2015_Missing(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwMsgSlot269Bas2Repn4BusFrChA_CODE) CTR_VIB_STW_DISP_EXMI_SP2015_Received(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwMsgSlot269Bas2Repn4BusFrChA_STOP_SEC_CODE
# include "BmwMsgSlot269Bas2Repn4BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMSGSLOT269BAS2REPN4BUSFRCHA_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
