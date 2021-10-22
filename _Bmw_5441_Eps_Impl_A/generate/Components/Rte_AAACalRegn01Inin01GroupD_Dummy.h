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
 *          File:  Rte_AAACalRegn01Inin01GroupD_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <AAACalRegn01Inin01GroupD_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AAACALREGN01ININ01GROUPD_DUMMY_H
# define _RTE_AAACALREGN01ININ01GROUPD_DUMMY_H

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

# ifndef RTE_CORE
#  define RTE_MULTI_INST_API
# endif

/* include files */

# include "Rte_AAACalRegn01Inin01GroupD_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_AAACalRegn01Inin01GroupD_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_EotProtnDeltaTqThd_Val(self) ((self)->EotProtnDeltaTqThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnEntrGainAuthyThd_Val(self) ((self)->EotProtnEntrGainAuthyThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnEntrStLpFilFrq_Val(self) ((self)->EotProtnEntrStLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnExitStLpFilFrq_Val(self) ((self)->EotProtnExitStLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnHwTqLpFilFrq_Val(self) ((self)->EotProtnHwTqLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnMotSpdIncptSca_Val(self) ((self)->EotProtnMotSpdIncptSca.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnMotVelGain_Val(self) ((self)->EotProtnMotVelGain.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnPosnRampStep_Val(self) ((self)->EotProtnPosnRampStep.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnRackTrvlLimrAuthyThd_Val(self) ((self)->EotProtnRackTrvlLimrAuthyThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnRackTrvlLimrAuthyThdLimd_Val(self) ((self)->EotProtnRackTrvlLimrAuthyThdLimd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnRackTrvlLimrRng_Val(self) ((self)->EotProtnRackTrvlLimrRng.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnRackTrvlLimrRngLimd_Val(self) ((self)->EotProtnRackTrvlLimrRngLimd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnRackTrvlLimrVehSpdThd_Val(self) ((self)->EotProtnRackTrvlLimrVehSpdThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgDecelGain_Val(self) ((self)->InertiaCmpVelDampgDecelGain.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgDecelGainFallSlew_Val(self) ((self)->InertiaCmpVelDampgDecelGainFallSlew.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgGainOffThd_Val(self) ((self)->InertiaCmpVelDampgGainOffThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgGainOnThd_Val(self) ((self)->InertiaCmpVelDampgGainOnThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelMotInertia_Val(self) ((self)->InertiaCmpVelMotInertia.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelTqSnsrVelFilFrq_Val(self) ((self)->InertiaCmpVelTqSnsrVelFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnRunEotVelImpctAndSoftEndStop_Logl(self) ((self)->EotProtnRunEotVelImpctAndSoftEndStop.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDecelGainEnaCal_Logl(self) ((self)->InertiaCmpVelDecelGainEnaCal.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnDampgVehSpdTbl_Ary1D(self) ((self)->EotProtnDampgVehSpdTbl.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnEntrGainVehSpdTbl_Ary1D(self) ((self)->EotProtnEntrGainVehSpdTbl.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnEntrGainX_Ary2D(self) ((self)->EotProtnEntrGainX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnEntrGainY_Ary2D(self) ((self)->EotProtnEntrGainY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnExitDampgY_Ary2D(self) ((self)->EotProtnExitDampgY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnHwDegDampgX_Ary2D(self) ((self)->EotProtnHwDegDampgX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnHwTqScaX_Ary1D(self) ((self)->EotProtnHwTqScaX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnLoAuthyEntrGainY_Ary2D(self) ((self)->EotProtnLoAuthyEntrGainY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnMotSpdIncptX_Ary1D(self) ((self)->EotProtnMotSpdIncptX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnMotSpdIncptY_Ary1D(self) ((self)->EotProtnMotSpdIncptY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EotProtnNormDampgY_Ary2D(self) ((self)->EotProtnNormDampgY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(self) ((self)->InertiaCmpVelAssiBasdDampgCoeffX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(self) ((self)->InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(self) ((self)->InertiaCmpVelAssiBasdDampgRollgY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY_Ary1D(self) ((self)->InertiaCmpVelAssiBasdDampgStatWhlImbRejctnOnY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelAssiBasdDampgStatY_Ary1D(self) ((self)->InertiaCmpVelAssiBasdDampgStatY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelCmdScaY_Ary1D(self) ((self)->InertiaCmpVelCmdScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewX_Ary1D(self) ((self)->InertiaCmpVelDampgDecelGainRisngSlewX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgDecelGainRisngSlewY_Ary1D(self) ((self)->InertiaCmpVelDampgDecelGainRisngSlewY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(self) ((self)->InertiaCmpVelDampgFilFrq.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(self) ((self)->InertiaCmpVelDampgFilFrqWhlImbRejctnOn.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgSpdBlndY_Ary1D(self) ((self)->InertiaCmpVelDampgSpdBlndY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndX_Ary1D(self) ((self)->InertiaCmpVelDampgWhlImbRejctnBlndX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgWhlImbRejctnBlndY_Ary1D(self) ((self)->InertiaCmpVelDampgWhlImbRejctnBlndY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndX_Ary1D(self) ((self)->InertiaCmpVelModWhlImbRejctnBlndX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelModWhlImbRejctnBlndY_Ary1D(self) ((self)->InertiaCmpVelModWhlImbRejctnBlndY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelMotVelBasdOutpScagX_Ary1D(self) ((self)->InertiaCmpVelMotVelBasdOutpScagX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelMotVelBasdOutpScagY_Ary1D(self) ((self)->InertiaCmpVelMotVelBasdOutpScagY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelNotchBlndY_Ary1D(self) ((self)->InertiaCmpVelNotchBlndY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelTqSnsrVelSca_Ary1D(self) ((self)->InertiaCmpVelTqSnsrVelSca.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelNotchFilStruct_Rec(self) ((self)->InertiaCmpVelNotchFilStruct.Prm_Rec()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define AAACalRegn01Inin01GroupD_Dummy_START_SEC_CODE
# include "AAACalRegn01Inin01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn01Inin01GroupDDummyInit1 CalRegn01Inin01GroupDDummyInit1
# endif

FUNC(void, AAACalRegn01Inin01GroupD_Dummy_CODE) CalRegn01Inin01GroupDDummyInit1(P2CONST(struct Rte_CDS_AAACalRegn01Inin01GroupD_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define AAACalRegn01Inin01GroupD_Dummy_STOP_SEC_CODE
# include "AAACalRegn01Inin01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_AAACALREGN01ININ01GROUPD_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
