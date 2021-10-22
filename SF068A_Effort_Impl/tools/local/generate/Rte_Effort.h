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
 *          File:  Rte_Effort.h
 *        Config:  C:/Nimmy/Autocode/BMW/BMW_Production/SF068/SF068A_Effort_Impl/tools/Component.dpa
 *     SW-C Type:  Effort
 *  Generated at:  Tue May 22 12:00:33 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <Effort> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_EFFORT_H
# define _RTE_EFFORT_H

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

# include "Rte_Effort_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Effort
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_Effort, RTE_CONST, RTE_CONST) Rte_Inst_Effort; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_Effort, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_EffortCmdSca_Val (1.0F)
# define Rte_InitValue_HwTqCmdEffort_Val (0.0F)
# define Rte_InitValue_RackFEstimd_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Effort_EffortCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_EFFORT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Effort_RackFEstimd_Val(P2VAR(float32, AUTOMATIC, RTE_EFFORT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Effort_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_EFFORT_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Effort_HwTqCmdEffort_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_Effort_EffortScaRackFThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u15p1, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortRackFX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u15p1_10_24, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortRackFX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortRackFY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u4p12_10_24, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortRackFY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s15p0, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortScaBlndX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s15p0_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortScaBlndX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u1p15, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortScaBlndY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortScaBlndY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_Effort_EffortVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_EffortCmdSca_Val Rte_Read_Effort_EffortCmdSca_Val
# define Rte_Read_RackFEstimd_Val Rte_Read_Effort_RackFEstimd_Val
# define Rte_Read_VehSpd_Val Rte_Read_Effort_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_HwTqCmdEffort_Val Rte_Write_Effort_HwTqCmdEffort_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_EffortScaRackFThd_Val Rte_Prm_Effort_EffortScaRackFThd_Val

# define Rte_Prm_EffortRackFX_Ary2D Rte_Prm_Effort_EffortRackFX_Ary2D

# define Rte_Prm_EffortRackFY_Ary2D Rte_Prm_Effort_EffortRackFY_Ary2D

# define Rte_Prm_EffortScaBlndX_Ary1D Rte_Prm_Effort_EffortScaBlndX_Ary1D

# define Rte_Prm_EffortScaBlndY_Ary1D Rte_Prm_Effort_EffortScaBlndY_Ary1D

# define Rte_Prm_EffortVehSpdBilnrSeln_Ary1D Rte_Prm_Effort_EffortVehSpdBilnrSeln_Ary1D



/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_EffortScaRackFThd_Val(void)
 *   u15p1 *Rte_Prm_EffortRackFX_Ary2D(void)
 *     Returnvalue: u15p1* is of type Ary2D_u15p1_10_24
 *   u4p12 *Rte_Prm_EffortRackFY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_10_24
 *   s15p0 *Rte_Prm_EffortScaBlndX_Ary1D(void)
 *     Returnvalue: s15p0* is of type Ary1D_s15p0_10
 *   u1p15 *Rte_Prm_EffortScaBlndY_Ary1D(void)
 *     Returnvalue: u1p15* is of type Ary1D_u1p15_10
 *   u9p7 *Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_10
 *
 *********************************************************************************************************************/


# define Effort_START_SEC_CODE
# include "Effort_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: EffortInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_EffortInit1 EffortInit1
FUNC(void, Effort_CODE) EffortInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EffortPer1
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
 *   Std_ReturnType Rte_Read_EffortCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackFEstimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTqCmdEffort_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_EffortPer1 EffortPer1
FUNC(void, Effort_CODE) EffortPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Effort_STOP_SEC_CODE
# include "Effort_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_EFFORT_H */

#include "Rte_Stubs.h"
