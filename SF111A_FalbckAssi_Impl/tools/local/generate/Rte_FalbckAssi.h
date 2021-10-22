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
 *          File:  Rte_FalbckAssi.h
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/SF111A_FalbckAssi_Impl-nz2999/SF111A_FalbckAssi_Impl/tools/Component.dpa
 *     SW-C Type:  FalbckAssi
 *  Generated at:  Fri Apr 20 08:33:34 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <FalbckAssi> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_FALBCKASSI_H
# define _RTE_FALBCKASSI_H

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

# include "Rte_FalbckAssi_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_FalbckAssi
{
  /* PIM Handles section */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FalbckAssiNotchFil1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_FalbckAssiNotchFil2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_FalbckAssi, RTE_CONST, RTE_CONST) Rte_Inst_FalbckAssi; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_FalbckAssi, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_FalbckAssiMotTqCmd_Val (0.0F)
# define Rte_InitValue_HwTq_Val (0.0F)
# define Rte_InitValue_VehSpd_Val (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_FalbckAssi_HwTq_Val(P2VAR(float32, AUTOMATIC, RTE_FALBCKASSI_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_FalbckAssi_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_FALBCKASSI_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_FalbckAssi_FalbckAssiMotTqCmd_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u6p10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_FalbckAssi_FalbckAssiAssiX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u6p10_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_FalbckAssi_FalbckAssiAssiX_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u4p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_FalbckAssi_FalbckAssiAssiY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary2D_u4p12_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_FalbckAssi_FalbckAssiAssiY_Ary2D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_FalbckAssi_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_FalbckAssi_SysGlbPrmVehSpdBilnrSeln_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC_P2CONST(FilNotchGainRec1, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_FalbckAssi_FalbckAssiNotchFil_Rec(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTq_Val Rte_Read_FalbckAssi_HwTq_Val
# define Rte_Read_VehSpd_Val Rte_Read_FalbckAssi_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_FalbckAssiMotTqCmd_Val Rte_Write_FalbckAssi_FalbckAssiMotTqCmd_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_FalbckAssiAssiX_Ary2D Rte_Prm_FalbckAssi_FalbckAssiAssiX_Ary2D

# define Rte_Prm_FalbckAssiAssiY_Ary2D Rte_Prm_FalbckAssi_FalbckAssiAssiY_Ary2D

# define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D Rte_Prm_FalbckAssi_SysGlbPrmVehSpdBilnrSeln_Ary1D

# define Rte_Prm_FalbckAssiNotchFil_Rec Rte_Prm_FalbckAssi_FalbckAssiNotchFil_Rec

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_FalbckAssiNotchFil1() (Rte_Inst_FalbckAssi->Pim_FalbckAssiNotchFil1) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_FalbckAssiNotchFil2() (Rte_Inst_FalbckAssi->Pim_FalbckAssiNotchFil2) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_FalbckAssiNotchFil1(void)
 *   float32 *Rte_Pim_FalbckAssiNotchFil2(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   u6p10 *Rte_Prm_FalbckAssiAssiX_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_12_20
 *   u4p12 *Rte_Prm_FalbckAssiAssiY_Ary2D(void)
 *     Returnvalue: u4p12* is of type Ary2D_u4p12_12_20
 *   u9p7 *Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_12
 *   FilNotchGainRec1 *Rte_Prm_FalbckAssiNotchFil_Rec(void)
 *
 *********************************************************************************************************************/


# define FalbckAssi_START_SEC_CODE
# include "FalbckAssi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: FalbckAssiInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FalbckAssiInit1 FalbckAssiInit1
FUNC(void, FalbckAssi_CODE) FalbckAssiInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FalbckAssiPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FalbckAssiMotTqCmd_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_FalbckAssiPer1 FalbckAssiPer1
FUNC(void, FalbckAssi_CODE) FalbckAssiPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define FalbckAssi_STOP_SEC_CODE
# include "FalbckAssi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_FALBCKASSI_H */

#include "Rte_Stubs.h"
