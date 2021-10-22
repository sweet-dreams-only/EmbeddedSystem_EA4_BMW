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
 *          File:  Rte_BmwPwrPrkgDampg.h
 *        Config:  C:/_S/work/ses_dev_ea4/CF082A_BmwPwrPrkgDampg_Impl-z172399/CF082A_BmwPwrPrkgDampg_Impl/tools/Component.dpa
 *     SW-C Type:  BmwPwrPrkgDampg
 *  Generated at:  Wed May 16 13:53:21 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwPwrPrkgDampg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWPWRPRKGDAMPG_H
# define _RTE_BMWPWRPRKGDAMPG_H

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

# include "Rte_BmwPwrPrkgDampg_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_BmwPwrPrkgDampg
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DampgCmdPwrPrkgStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_BmwPwrPrkgDampg, RTE_CONST, RTE_CONST) Rte_Inst_BmwPwrPrkgDampg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_BmwPwrPrkgDampg, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DampgCmdBas_Val (0.0F)
# define Rte_InitValue_DampgCmdPwrPrkg_Val (0.0F)
# define Rte_InitValue_DampgCmdPwrPrkgEna_Logl (FALSE)
# define Rte_InitValue_HwVel_Val (0.0F)
# define Rte_InitValue_PinionAg_Val (0.0F)
# define Rte_InitValue_PinionAgConf_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwPwrPrkgDampg_DampgCmdBas_Val(P2VAR(float32, AUTOMATIC, RTE_BMWPWRPRKGDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwPwrPrkgDampg_DampgCmdPwrPrkgEna_Logl(P2VAR(boolean, AUTOMATIC, RTE_BMWPWRPRKGDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwPwrPrkgDampg_HwVel_Val(P2VAR(float32, AUTOMATIC, RTE_BMWPWRPRKGDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwPwrPrkgDampg_PinionAg_Val(P2VAR(float32, AUTOMATIC, RTE_BMWPWRPRKGDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwPwrPrkgDampg_PinionAgConf_Val(P2VAR(float32, AUTOMATIC, RTE_BMWPWRPRKGDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BmwPwrPrkgDampg_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_BMWPWRPRKGDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgMaxRate_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgMinPinionAgConf_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgDiScadDampg_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u5p11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u5p11_9_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgHwVelTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u6p10_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgHwVelTblX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u12p4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u12p4_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u1p15_11, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_DampgCmdBas_Val Rte_Read_BmwPwrPrkgDampg_DampgCmdBas_Val
# define Rte_Read_DampgCmdPwrPrkgEna_Logl Rte_Read_BmwPwrPrkgDampg_DampgCmdPwrPrkgEna_Logl
# define Rte_Read_HwVel_Val Rte_Read_BmwPwrPrkgDampg_HwVel_Val
# define Rte_Read_PinionAg_Val Rte_Read_BmwPwrPrkgDampg_PinionAg_Val
# define Rte_Read_PinionAgConf_Val Rte_Read_BmwPwrPrkgDampg_PinionAgConf_Val
# define Rte_Read_VehSpd_Val Rte_Read_BmwPwrPrkgDampg_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_DampgCmdPwrPrkg_Val Rte_Write_BmwPwrPrkgDampg_DampgCmdPwrPrkg_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_BmwPwrPrkgDampgMaxRate_Val Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgMaxRate_Val

# define Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgMinPinionAgConf_Val

# define Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgDiScadDampg_Logl

# define Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D

# define Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgHwVelTblX_Ary1D

# define Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D

# define Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D

# define Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D Rte_Prm_BmwPwrPrkgDampg_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_DampgCmdPwrPrkgStVari() (Rte_Inst_BmwPwrPrkgDampg->Pim_DampgCmdPwrPrkgStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_DampgCmdPwrPrkgStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwPwrPrkgDampgMaxRate_Val(void)
 *   float32 Rte_Prm_BmwPwrPrkgDampgMinPinionAgConf_Val(void)
 *   boolean Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl(void)
 *   u5p11 *Rte_Prm_BmwPwrPrkgDampgBasPwrPrkgDampgY_Ary2D(void)
 *     Returnvalue: u5p11* is of type Ary2D_u5p11_9_9
 *   u6p10 *Rte_Prm_BmwPwrPrkgDampgHwVelTblX_Ary1D(void)
 *     Returnvalue: u6p10* is of type Ary1D_u6p10_9
 *   u12p4 *Rte_Prm_BmwPwrPrkgDampgPinionAgSelnTbl_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u9p7 *Rte_Prm_BmwPwrPrkgDampgVehSpdLnrSelnX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_11
 *   u1p15 *Rte_Prm_BmwPwrPrkgDampgVehSpdScaFacY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_11
 *
 *********************************************************************************************************************/


# define BmwPwrPrkgDampg_START_SEC_CODE
# include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwPwrPrkgDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwPwrPrkgDampgInit1 BmwPwrPrkgDampgInit1
FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwPwrPrkgDampgPer1
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
 *   Std_ReturnType Rte_Read_DampgCmdBas_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DampgCmdPwrPrkgEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DampgCmdPwrPrkg_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_BmwPwrPrkgDampgPer1 BmwPwrPrkgDampgPer1
FUNC(void, BmwPwrPrkgDampg_CODE) BmwPwrPrkgDampgPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwPwrPrkgDampg_STOP_SEC_CODE
# include "BmwPwrPrkgDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWPWRPRKGDAMPG_H */

#include "Rte_Stubs.h"
