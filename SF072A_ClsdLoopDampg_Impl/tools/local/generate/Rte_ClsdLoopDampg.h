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
 *          File:  Rte_ClsdLoopDampg.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/SF072A_ClsdLoopDampg_Impl-nz2999/SF072A_ClsdLoopDampg_Impl/tools/Component.dpa
 *     SW-C Type:  ClsdLoopDampg
 *  Generated at:  Fri Mar 16 13:10:39 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ClsdLoopDampg> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CLSDLOOPDAMPG_H
# define _RTE_CLSDLOOPDAMPG_H

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

# include "Rte_ClsdLoopDampg_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_ClsdLoopDampg
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_ClsdLoopDampg, RTE_CONST, RTE_CONST) Rte_Inst_ClsdLoopDampg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_ClsdLoopDampg, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DampgCmdSca_Val (0.0F)
# define Rte_InitValue_EotCtrlSca_Val (0.0F)
# define Rte_InitValue_EotDeltaAg_Val (900.0F)
# define Rte_InitValue_EotSt_Val (0U)
# define Rte_InitValue_HwTqCmdDampg_Val (0.0F)
# define Rte_InitValue_PinionVel_Val (0.0F)
# define Rte_InitValue_RackFEstimd_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopDampg_DampgCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopDampg_EotCtrlSca_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopDampg_EotDeltaAg_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopDampg_EotSt_Val(P2VAR(EotSt1, AUTOMATIC, RTE_CLSDLOOPDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopDampg_PinionVel_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopDampg_RackFEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ClsdLoopDampg_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_CLSDLOOPDAMPG_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ClsdLoopDampg_HwTqCmdDampg_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u10p6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotEntrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u10p6_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotEntrX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotEntrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u1p15_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotEntrY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u10p6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotExitX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u10p6_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotExitX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotExitY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u1p15_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotExitY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgPinionVelX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u6p10_12_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgPinionVelX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgPinionVelY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u4p12_12_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgPinionVelY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u15p1, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgRackFX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u15p1_12_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgRackFX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgRackFY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u1p15_12_9, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_ClsdLoopDampgRackFY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_ClsdLoopDampg_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_DampgCmdSca_Val Rte_Read_ClsdLoopDampg_DampgCmdSca_Val
# define Rte_Read_EotCtrlSca_Val Rte_Read_ClsdLoopDampg_EotCtrlSca_Val
# define Rte_Read_EotDeltaAg_Val Rte_Read_ClsdLoopDampg_EotDeltaAg_Val
# define Rte_Read_EotSt_Val Rte_Read_ClsdLoopDampg_EotSt_Val
# define Rte_Read_PinionVel_Val Rte_Read_ClsdLoopDampg_PinionVel_Val
# define Rte_Read_RackFEstimd_Val Rte_Read_ClsdLoopDampg_RackFEstimd_Val
# define Rte_Read_VehSpd_Val Rte_Read_ClsdLoopDampg_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTqCmdDampg_Val Rte_Write_ClsdLoopDampg_HwTqCmdDampg_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotEntrX_Ary1D

# define Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotEntrY_Ary1D

# define Rte_Prm_ClsdLoopDampgEotExitX_Ary1D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotExitX_Ary1D

# define Rte_Prm_ClsdLoopDampgEotExitY_Ary1D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgEotExitY_Ary1D

# define Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgPinionVelX_Ary2D

# define Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgPinionVelY_Ary2D

# define Rte_Prm_ClsdLoopDampgRackFX_Ary2D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgRackFX_Ary2D

# define Rte_Prm_ClsdLoopDampgRackFY_Ary2D Rte_Prm_ClsdLoopDampg_ClsdLoopDampgRackFY_Ary2D

# define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D Rte_Prm_ClsdLoopDampg_SysGlbPrmVehSpdBilnrSeln_Ary1D



/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   u10p6 *Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(void)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u1p15 *Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_4
 *   u10p6 *Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(void)
 *     Returnvalue: u10p6* is of type Ary1D_u10p6_4
 *   u1p15 *Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_4
 *   u6p10 *Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_9
 *   u4p12 *Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_9
 *   u15p1 *Rte_Prm_ClsdLoopDampgRackFX_Ary2D(void)
 *     Returnvalue: u15p1* is of type Ary2D_u15p1_12_9
 *   u1p15 *Rte_Prm_ClsdLoopDampgRackFY_Ary2D(void)
 *     Returnvalue: u1p15* is of type Ary2D_u1p15_12_9
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *
 *********************************************************************************************************************/


# define ClsdLoopDampg_START_SEC_CODE
# include "ClsdLoopDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopDampgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ClsdLoopDampgInit1 ClsdLoopDampgInit1
FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClsdLoopDampgPer1
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
 *   Std_ReturnType Rte_Read_DampgCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EotCtrlSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EotDeltaAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EotSt_Val(EotSt1 *data)
 *   Std_ReturnType Rte_Read_PinionVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdDampg_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ClsdLoopDampgPer1 ClsdLoopDampgPer1
FUNC(void, ClsdLoopDampg_CODE) ClsdLoopDampgPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define ClsdLoopDampg_STOP_SEC_CODE
# include "ClsdLoopDampg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CLSDLOOPDAMPG_H */

#include "Rte_Stubs.h"
