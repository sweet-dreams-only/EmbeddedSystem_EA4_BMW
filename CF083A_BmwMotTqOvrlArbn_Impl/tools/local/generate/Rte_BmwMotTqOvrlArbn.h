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
 *          File:  Rte_BmwMotTqOvrlArbn.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CF083A_BmwMotTqOvrlArbn_Impl-nz2999/CF083A_BmwMotTqOvrlArbn_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMotTqOvrlArbn
 *  Generated at:  Tue Jul  3 10:29:18 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwMotTqOvrlArbn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWMOTTQOVRLARBN_H
# define _RTE_BMWMOTTQOVRLARBN_H

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

# include "Rte_BmwMotTqOvrlArbn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwMotTqOvrlArbn
{
  /* PIM Handles section */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_BmwNearStillVehSpdStsCdnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FctlErrStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MfgModCmdCdnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_VehSpdCdnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwMotTqOvrlArbn, RTE_CONST, RTE_CONST) Rte_Inst_BmwMotTqOvrlArbn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwMotTqOvrlArbn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_BmwNearStillVehSpdSts_Val (15U)
# define Rte_InitValue_BmwOutpTqOvrlCmd_Val (0.0F)
# define Rte_InitValue_BmwTrfcJamAssiDampgSt_Val (1U)
# define Rte_InitValue_DrvgDynActv_Logl (FALSE)
# define Rte_InitValue_HwOscnActv_Logl (FALSE)
# define Rte_InitValue_HwOscnCmd_Val (0.0F)
# define Rte_InitValue_HwOscnDcThdExcdd_Logl (FALSE)
# define Rte_InitValue_MotTqOvrlCmd_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnCmd_Val (0.0F)
# define Rte_InitValue_PinionCentrLrnEna_Logl (FALSE)
# define Rte_InitValue_PosnServoCmd_Val (0.0F)
# define Rte_InitValue_PosnServoEna_Logl (FALSE)
# define Rte_InitValue_PullCmpCmd_Val (0.0F)
# define Rte_InitValue_TrfcJamAssiCmd_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_BmwNearStillVehSpdSts_Val(P2VAR(BmwNearStillVehSpdSts1, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_BmwOutpTqOvrlCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_BmwTrfcJamAssiDampgSt_Val(P2VAR(BmwTrfcJamAssiSt1, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_DrvgDynActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_HwOscnActv_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_HwOscnCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_HwOscnDcThdExcdd_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_PosnServoCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_PosnServoEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_PullCmpCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_TrfcJamAssiCmd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwMotTqOvrlArbn_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMotTqOvrlArbn_GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_BmwMotTqOvrlArbn_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_BMWMOTTQOVRLARBN_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnMfgModCmdThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnMfgModVehSpdThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnPullCmpCmdLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint16, RTE_CODE) Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnVehSpdRefTiThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_BmwNearStillVehSpdSts_Val Rte_Read_BmwMotTqOvrlArbn_BmwNearStillVehSpdSts_Val
# define Rte_Read_BmwOutpTqOvrlCmd_Val Rte_Read_BmwMotTqOvrlArbn_BmwOutpTqOvrlCmd_Val
# define Rte_Read_BmwTrfcJamAssiDampgSt_Val Rte_Read_BmwMotTqOvrlArbn_BmwTrfcJamAssiDampgSt_Val
# define Rte_Read_DrvgDynActv_Logl Rte_Read_BmwMotTqOvrlArbn_DrvgDynActv_Logl
# define Rte_Read_HwOscnActv_Logl Rte_Read_BmwMotTqOvrlArbn_HwOscnActv_Logl
# define Rte_Read_HwOscnCmd_Val Rte_Read_BmwMotTqOvrlArbn_HwOscnCmd_Val
# define Rte_Read_HwOscnDcThdExcdd_Logl Rte_Read_BmwMotTqOvrlArbn_HwOscnDcThdExcdd_Logl
# define Rte_Read_PinionCentrLrnCmd_Val Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnCmd_Val
# define Rte_Read_PinionCentrLrnEna_Logl Rte_Read_BmwMotTqOvrlArbn_PinionCentrLrnEna_Logl
# define Rte_Read_PosnServoCmd_Val Rte_Read_BmwMotTqOvrlArbn_PosnServoCmd_Val
# define Rte_Read_PosnServoEna_Logl Rte_Read_BmwMotTqOvrlArbn_PosnServoEna_Logl
# define Rte_Read_PullCmpCmd_Val Rte_Read_BmwMotTqOvrlArbn_PullCmpCmd_Val
# define Rte_Read_TrfcJamAssiCmd_Val Rte_Read_BmwMotTqOvrlArbn_TrfcJamAssiCmd_Val
# define Rte_Read_VehSpd_Val Rte_Read_BmwMotTqOvrlArbn_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotTqOvrlCmd_Val Rte_Write_BmwMotTqOvrlArbn_MotTqOvrlCmd_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetRefTmr100MicroSec32bit_Oper Rte_Call_BmwMotTqOvrlArbn_GetRefTmr100MicroSec32bit_Oper
# define Rte_Call_GetTiSpan100MicroSec32bit_Oper Rte_Call_BmwMotTqOvrlArbn_GetTiSpan100MicroSec32bit_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnMfgModCmdThd_Val

# define Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnMfgModVehSpdThd_Val

# define Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnPullCmpCmdLim_Val

# define Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val

# define Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val

# define Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val Rte_Prm_BmwMotTqOvrlArbn_BmwMotTqOvrlArbnVehSpdRefTiThd_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_BmwNearStillVehSpdStsCdnRefTi() (Rte_Inst_BmwMotTqOvrlArbn->Pim_BmwNearStillVehSpdStsCdnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MfgModCmdCdnRefTi() (Rte_Inst_BmwMotTqOvrlArbn->Pim_MfgModCmdCdnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_VehSpdCdnRefTi() (Rte_Inst_BmwMotTqOvrlArbn->Pim_VehSpdCdnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FctlErrStVari() (Rte_Inst_BmwMotTqOvrlArbn->Pim_FctlErrStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_BmwNearStillVehSpdStsCdnRefTi(void)
 *   uint32 *Rte_Pim_MfgModCmdCdnRefTi(void)
 *   uint32 *Rte_Pim_VehSpdCdnRefTi(void)
 *   boolean *Rte_Pim_FctlErrStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwMotTqOvrlArbnMfgModCmdThd_Val(void)
 *   float32 Rte_Prm_BmwMotTqOvrlArbnMfgModVehSpdThd_Val(void)
 *   float32 Rte_Prm_BmwMotTqOvrlArbnPullCmpCmdLim_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnBmwNearStillVehSpdStsRefTiThd_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnMfgModCmdRefTiThd_Val(void)
 *   uint16 Rte_Prm_BmwMotTqOvrlArbnVehSpdRefTiThd_Val(void)
 *
 *********************************************************************************************************************/


# define BmwMotTqOvrlArbn_START_SEC_CODE
# include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMotTqOvrlArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwMotTqOvrlArbnInit1 BmwMotTqOvrlArbnInit1
FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMotTqOvrlArbnPer1
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
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_BmwOutpTqOvrlCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwTrfcJamAssiDampgSt_Val(BmwTrfcJamAssiSt1 *data)
 *   Std_ReturnType Rte_Read_DrvgDynActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnDcThdExcdd_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PosnServoCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PosnServoEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TrfcJamAssiCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotTqOvrlCmd_Val(float32 data)
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

# define RTE_RUNNABLE_BmwMotTqOvrlArbnPer1 BmwMotTqOvrlArbnPer1
FUNC(void, BmwMotTqOvrlArbn_CODE) BmwMotTqOvrlArbnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwMotTqOvrlArbn_STOP_SEC_CODE
# include "BmwMotTqOvrlArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWMOTTQOVRLARBN_H */

#include "Rte_Stubs.h"
