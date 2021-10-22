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
 *          File:  Rte_BmwVehSpd.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwVehSpd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWVEHSPD_H
# define _RTE_BMWVEHSPD_H

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

# include "Rte_BmwVehSpd_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwSecurVehSpdSts1, RTE_VAR_INIT) Rte_BmwVehSpd_BmwSecurVehSpdSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpdVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwCogVehSpdQlfr1, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwNearStillVehSpdSts1, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwPinionAgQlfr1, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
#  define Rte_InitValue_BmwPinionAgQlfr_Val (14U)
#  define Rte_InitValue_BmwSecurVehSpdSts_Val (15U)
#  define Rte_InitValue_VehSpd_Val (0.0F)
#  define Rte_InitValue_VehSpdVld_Logl (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwCogVehSpd_Val Rte_Read_BmwVehSpd_BmwCogVehSpd_Val
#  define Rte_Read_BmwVehSpd_BmwCogVehSpd_Val(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwCogVehSpdQlfr_Val Rte_Read_BmwVehSpd_BmwCogVehSpdQlfr_Val
#  define Rte_Read_BmwVehSpd_BmwCogVehSpdQlfr_Val(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwCogVehSpdQlfrVld_Logl Rte_Read_BmwVehSpd_BmwCogVehSpdQlfrVld_Logl
#  define Rte_Read_BmwVehSpd_BmwCogVehSpdQlfrVld_Logl(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdQlfrVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwCogVehSpdVld_Logl Rte_Read_BmwVehSpd_BmwCogVehSpdVld_Logl
#  define Rte_Read_BmwVehSpd_BmwCogVehSpdVld_Logl(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwCogVehSpdVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwNearStillVehSpdSts_Val Rte_Read_BmwVehSpd_BmwNearStillVehSpdSts_Val
#  define Rte_Read_BmwVehSpd_BmwNearStillVehSpdSts_Val(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwNearStillVehSpdStsVld_Logl Rte_Read_BmwVehSpd_BmwNearStillVehSpdStsVld_Logl
#  define Rte_Read_BmwVehSpd_BmwNearStillVehSpdStsVld_Logl(data) (*(data) = Rte_BmwMsgSlot55Bas3Repn4BusFrChA_BmwNearStillVehSpdStsVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAgQlfr_Val Rte_Read_BmwVehSpd_BmwPinionAgQlfr_Val
#  define Rte_Read_BmwVehSpd_BmwPinionAgQlfr_Val(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BmwSecurVehSpdSts_Val Rte_Write_BmwVehSpd_BmwSecurVehSpdSts_Val
#  define Rte_Write_BmwVehSpd_BmwSecurVehSpdSts_Val(data) (Rte_BmwVehSpd_BmwSecurVehSpdSts_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_VehSpd_Val Rte_Write_BmwVehSpd_VehSpd_Val
#  define Rte_Write_BmwVehSpd_VehSpd_Val(data) (Rte_BmwVehSpd_VehSpd_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_VehSpdVld_Logl Rte_Write_BmwVehSpd_VehSpdVld_Logl
#  define Rte_Write_BmwVehSpd_VehSpdVld_Logl(data) (Rte_BmwVehSpd_VehSpdVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


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


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwVehSpdNearStillSubVehSpd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwVehSpdRunngSubVehSpd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwVehSpdRunngSubVehSpd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwVehSpdSecurVehSpdInvldRateLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwVehSpdSecurVehSpdVldRateLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwVehSpd_VehSpdLimPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwVehSpd_BmwSecurVehSpdStsSigValVldDurn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl9_PIM_GROUP) Rte_BmwVehSpd_SpdDifChkFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_VehSpdLimPrev() \
  (&Rte_BmwVehSpd_VehSpdLimPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwSecurVehSpdStsSigValVldDurn() \
  (&Rte_BmwVehSpd_BmwSecurVehSpdStsSigValVldDurn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SpdDifChkFlg() \
  (&Rte_BmwVehSpd_SpdDifChkFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwVehSpd_START_SEC_CODE
# include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwVehSpdInit1 BmwVehSpdInit1
#  define RTE_RUNNABLE_BmwVehSpdPer1 BmwVehSpdPer1
# endif

FUNC(void, BmwVehSpd_CODE) BmwVehSpdInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwVehSpd_CODE) BmwVehSpdPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define BmwVehSpd_STOP_SEC_CODE
# include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWVEHSPD_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
