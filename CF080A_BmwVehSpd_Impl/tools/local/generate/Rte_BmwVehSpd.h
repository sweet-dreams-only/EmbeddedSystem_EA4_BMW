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
 *        Config:  C:/_S/work/ses_dev_ea4/CF080A_BmwVehSpd_Impl-z172399/CF080A_BmwVehSpd_Impl/tools/Component.dpa
 *     SW-C Type:  BmwVehSpd
 *  Generated at:  Mon Jun 25 12:43:26 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwVehSpd> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWVEHSPD_H
# define _RTE_BMWVEHSPD_H

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

# include "Rte_BmwVehSpd_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwVehSpd
{
  /* PIM Handles section */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwSecurVehSpdStsSigValVldDurn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SpdDifChkFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehSpdLimPrev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwVehSpd, RTE_CONST, RTE_CONST) Rte_Inst_BmwVehSpd; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwVehSpd, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwCogVehSpd_Val (0.0F)
# define Rte_InitValue_BmwCogVehSpdQlfr_Val (15U)
# define Rte_InitValue_BmwCogVehSpdQlfrVld_Logl (FALSE)
# define Rte_InitValue_BmwCogVehSpdVld_Logl (FALSE)
# define Rte_InitValue_BmwNearStillVehSpdSts_Val (15U)
# define Rte_InitValue_BmwNearStillVehSpdStsVld_Logl (FALSE)
# define Rte_InitValue_BmwPinionAgQlfr_Val (14U)
# define Rte_InitValue_BmwSecurVehSpdSts_Val (15U)
# define Rte_InitValue_VehSpd_Val (0.0F)
# define Rte_InitValue_VehSpdVld_Logl (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwVehSpd_BmwCogVehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwVehSpd_BmwCogVehSpdQlfr_Val(P2VAR(BmwCogVehSpdQlfr1, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwVehSpd_BmwCogVehSpdQlfrVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwVehSpd_BmwCogVehSpdVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwVehSpd_BmwNearStillVehSpdSts_Val(P2VAR(BmwNearStillVehSpdSts1, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwVehSpd_BmwNearStillVehSpdStsVld_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwVehSpd_BmwPinionAgQlfr_Val(P2VAR(BmwPinionAgQlfr1, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwVehSpd_BmwSecurVehSpdSts_Val(BmwSecurVehSpdSts1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwVehSpd_VehSpd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwVehSpd_VehSpdVld_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwVehSpd_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwVehSpd_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWVEHSPD_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwVehSpd_BmwVehSpdNearStillSubVehSpd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwVehSpd_BmwVehSpdRunngSubVehSpd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwVehSpd_BmwVehSpdSecurVehSpdInvldRateLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwVehSpd_BmwVehSpdSecurVehSpdVldRateLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(u16p0, RTE_CODE) Rte_Prm_BmwVehSpd_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwCogVehSpd_Val Rte_Read_BmwVehSpd_BmwCogVehSpd_Val
# define Rte_Read_BmwCogVehSpdQlfr_Val Rte_Read_BmwVehSpd_BmwCogVehSpdQlfr_Val
# define Rte_Read_BmwCogVehSpdQlfrVld_Logl Rte_Read_BmwVehSpd_BmwCogVehSpdQlfrVld_Logl
# define Rte_Read_BmwCogVehSpdVld_Logl Rte_Read_BmwVehSpd_BmwCogVehSpdVld_Logl
# define Rte_Read_BmwNearStillVehSpdSts_Val Rte_Read_BmwVehSpd_BmwNearStillVehSpdSts_Val
# define Rte_Read_BmwNearStillVehSpdStsVld_Logl Rte_Read_BmwVehSpd_BmwNearStillVehSpdStsVld_Logl
# define Rte_Read_BmwPinionAgQlfr_Val Rte_Read_BmwVehSpd_BmwPinionAgQlfr_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_BmwSecurVehSpdSts_Val Rte_Write_BmwVehSpd_BmwSecurVehSpdSts_Val
# define Rte_Write_VehSpd_Val Rte_Write_BmwVehSpd_VehSpd_Val
# define Rte_Write_VehSpdVld_Logl Rte_Write_BmwVehSpd_VehSpdVld_Logl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwVehSpd_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwVehSpd_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val Rte_Prm_BmwVehSpd_BmwVehSpdNearStillSubVehSpd_Val

# define Rte_Prm_BmwVehSpdRunngSubVehSpd_Val Rte_Prm_BmwVehSpd_BmwVehSpdRunngSubVehSpd_Val

# define Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val Rte_Prm_BmwVehSpd_BmwVehSpdSecurVehSpdInvldRateLim_Val

# define Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val Rte_Prm_BmwVehSpd_BmwVehSpdSecurVehSpdVldRateLim_Val

# define Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val Rte_Prm_BmwVehSpd_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_VehSpdLimPrev() (Rte_Inst_BmwVehSpd->Pim_VehSpdLimPrev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_BmwSecurVehSpdStsSigValVldDurn() (Rte_Inst_BmwVehSpd->Pim_BmwSecurVehSpdStsSigValVldDurn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SpdDifChkFlg() (Rte_Inst_BmwVehSpd->Pim_SpdDifChkFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_VehSpdLimPrev(void)
 *   uint32 *Rte_Pim_BmwSecurVehSpdStsSigValVldDurn(void)
 *   boolean *Rte_Pim_SpdDifChkFlg(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val(void)
 *   float32 Rte_Prm_BmwVehSpdRunngSubVehSpd_Val(void)
 *   float32 Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val(void)
 *   float32 Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val(void)
 *   u16p0 Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val(void)
 *
 *********************************************************************************************************************/


# define BmwVehSpd_START_SEC_CODE
# include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwVehSpdInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwVehSpdInit1 BmwVehSpdInit1
FUNC(void, BmwVehSpd_CODE) BmwVehSpdInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwVehSpdPer1
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
 *   Std_ReturnType Rte_Read_BmwCogVehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdStsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwSecurVehSpdSts_Val(BmwSecurVehSpdSts1 data)
 *   Std_ReturnType Rte_Write_VehSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehSpdVld_Logl(boolean data)
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

# define RTE_RUNNABLE_BmwVehSpdPer1 BmwVehSpdPer1
FUNC(void, BmwVehSpd_CODE) BmwVehSpdPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwVehSpd_STOP_SEC_CODE
# include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWVEHSPD_H */

#include "Rte_Stubs.h"
