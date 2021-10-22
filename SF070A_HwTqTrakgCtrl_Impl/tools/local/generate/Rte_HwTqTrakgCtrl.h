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
 *          File:  Rte_HwTqTrakgCtrl.h
 *        Config:  C:/Nimmy/Autocode/BMW/BMW_Production/SF070/SF070A_HwTqTrakgCtrl_Impl/tools/Component.dpa
 *     SW-C Type:  HwTqTrakgCtrl
 *  Generated at:  Mon May 14 09:57:36 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <HwTqTrakgCtrl> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HWTQTRAKGCTRL_H
# define _RTE_HWTQTRAKGCTRL_H

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

# include "Rte_HwTqTrakgCtrl_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_HwTqTrakgCtrl
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_HwTqTrakgCtrl, RTE_CONST, RTE_CONST) Rte_Inst_HwTqTrakgCtrl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_HwTqTrakgCtrl, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_HwTqCmd_Val (1.0F)
# define Rte_InitValue_MotTqCmdOvrl_Val (2.0F)
# define Rte_InitValue_MotTqCmdTrakgCtrl_Val (0.0F)
# define Rte_InitValue_SysTqRat_Val (15.0F)
# define Rte_InitValue_VehSpd_Val (20.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTqTrakgCtrl_HwTqCmd_Val(P2VAR(float32, AUTOMATIC, RTE_HWTQTRAKGCTRL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTqTrakgCtrl_MotTqCmdOvrl_Val(P2VAR(float32, AUTOMATIC, RTE_HWTQTRAKGCTRL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTqTrakgCtrl_SysTqRat_Val(P2VAR(float32, AUTOMATIC, RTE_HWTQTRAKGCTRL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTqTrakgCtrl_TorsBarStEstimd_Rec(P2VAR(TorsBarStEstimdRec1, AUTOMATIC, RTE_HWTQTRAKGCTRL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HwTqTrakgCtrl_VehSpd_Val(P2VAR(float32, AUTOMATIC, RTE_HWTQTRAKGCTRL_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val(float32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlMotTqCmdOvrlGain_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s3p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain1_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s3p12_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain1_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s14p1, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain2_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s14p1_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain2_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s8p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain3_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s8p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain3_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s3p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain4_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s3p12_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain4_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s3p12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain5_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s3p12_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain5_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(s7p8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFfGainScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_s7p8_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFfGainScaY_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(u9p7, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlVehSpdScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlVehSpdScaX_Ary1D(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_HwTqCmd_Val Rte_Read_HwTqTrakgCtrl_HwTqCmd_Val
# define Rte_Read_MotTqCmdOvrl_Val Rte_Read_HwTqTrakgCtrl_MotTqCmdOvrl_Val
# define Rte_Read_SysTqRat_Val Rte_Read_HwTqTrakgCtrl_SysTqRat_Val
# define Rte_Read_TorsBarStEstimd_Rec Rte_Read_HwTqTrakgCtrl_TorsBarStEstimd_Rec
# define Rte_Read_VehSpd_Val Rte_Read_HwTqTrakgCtrl_VehSpd_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotTqCmdTrakgCtrl_Val Rte_Write_HwTqTrakgCtrl_MotTqCmdTrakgCtrl_Val


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlMotTqCmdOvrlGain_Val

# define Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain1_Ary1D

# define Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain2_Ary1D

# define Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain3_Ary1D

# define Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain4_Ary1D

# define Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFbGain5_Ary1D

# define Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlFfGainScaY_Ary1D

# define Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D Rte_Prm_HwTqTrakgCtrl_HwTqTrakgCtrlVehSpdScaX_Ary1D



/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_HwTqTrakgCtrlMotTqCmdOvrlGain_Val(void)
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(void)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s14p1 *Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(void)
 *     Returnvalue: s14p1* is of type Ary1D_s14p1_4
 *   s8p7 *Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(void)
 *     Returnvalue: s8p7* is of type Ary1D_s8p7_4
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(void)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s3p12 *Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(void)
 *     Returnvalue: s3p12* is of type Ary1D_s3p12_4
 *   s7p8 *Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(void)
 *     Returnvalue: s7p8* is of type Ary1D_s7p8_4
 *   u9p7 *Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *
 *********************************************************************************************************************/


# define HwTqTrakgCtrl_START_SEC_CODE
# include "HwTqTrakgCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqTrakgCtrlInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTqTrakgCtrlInit1 HwTqTrakgCtrlInit1
FUNC(void, HwTqTrakgCtrl_CODE) HwTqTrakgCtrlInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqTrakgCtrlPer1
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
 *   Std_ReturnType Rte_Read_HwTqCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdOvrl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysTqRat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TorsBarStEstimd_Rec(TorsBarStEstimdRec1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotTqCmdTrakgCtrl_Val(float32 data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_HwTqTrakgCtrlPer1 HwTqTrakgCtrlPer1
FUNC(void, HwTqTrakgCtrl_CODE) HwTqTrakgCtrlPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define HwTqTrakgCtrl_STOP_SEC_CODE
# include "HwTqTrakgCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_HWTQTRAKGCTRL_H */

#include "Rte_Stubs.h"
