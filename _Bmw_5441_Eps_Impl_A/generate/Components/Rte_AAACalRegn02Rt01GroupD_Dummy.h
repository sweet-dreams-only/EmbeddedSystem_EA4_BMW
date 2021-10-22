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
 *          File:  Rte_AAACalRegn02Rt01GroupD_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <AAACalRegn02Rt01GroupD_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AAACALREGN02RT01GROUPD_DUMMY_H
# define _RTE_AAACALREGN02RT01GROUPD_DUMMY_H

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

# include "Rte_AAACalRegn02Rt01GroupD_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_AAACalRegn02Rt01GroupD_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_ClsdLoopHysHwAgBlndFac_Val(self) ((self)->ClsdLoopHysHwAgBlndFac.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysPolarity_Val(self) ((self)->ClsdLoopHysPolarity.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgNegLowrLim_Val(self) ((self)->ClsdLoopHysSteerInHwAgNegLowrLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgNegUpprLim_Val(self) ((self)->ClsdLoopHysSteerInHwAgNegUpprLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgPosLowrLim_Val(self) ((self)->ClsdLoopHysSteerInHwAgPosLowrLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerInHwAgPosUpprLim_Val(self) ((self)->ClsdLoopHysSteerInHwAgPosUpprLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgNegLowrLim_Val(self) ((self)->ClsdLoopHysSteerOutHwAgNegLowrLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgNegUpprLim_Val(self) ((self)->ClsdLoopHysSteerOutHwAgNegUpprLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgPosLowrLim_Val(self) ((self)->ClsdLoopHysSteerOutHwAgPosLowrLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSteerOutHwAgPosUpprLim_Val(self) ((self)->ClsdLoopHysSteerOutHwAgPosUpprLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgEotEntrX_Ary1D(self) ((self)->ClsdLoopDampgEotEntrX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgEotEntrY_Ary1D(self) ((self)->ClsdLoopDampgEotEntrY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgEotExitX_Ary1D(self) ((self)->ClsdLoopDampgEotExitX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgEotExitY_Ary1D(self) ((self)->ClsdLoopDampgEotExitY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgPinionVelX_Ary2D(self) ((self)->ClsdLoopDampgPinionVelX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgPinionVelY_Ary2D(self) ((self)->ClsdLoopDampgPinionVelY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgRackFX_Ary2D(self) ((self)->ClsdLoopDampgRackFX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopDampgRackFY_Ary2D(self) ((self)->ClsdLoopDampgRackFY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysDeltaY_Ary1D(self) ((self)->ClsdLoopHysDeltaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysGainY_Ary1D(self) ((self)->ClsdLoopHysGainY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysHwAgQuadBlndX_Ary1D(self) ((self)->ClsdLoopHysHwAgQuadBlndX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysHwAgQuadBlndY_Ary1D(self) ((self)->ClsdLoopHysHwAgQuadBlndY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysHwAgQuadQlfrX_Ary1D(self) ((self)->ClsdLoopHysHwAgQuadQlfrX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysHwAgQuadQlfrY_Ary1D(self) ((self)->ClsdLoopHysHwAgQuadQlfrY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysHwVelQuadBlndX_Ary1D(self) ((self)->ClsdLoopHysHwVelQuadBlndX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysHwVelQuadBlndY_Ary1D(self) ((self)->ClsdLoopHysHwVelQuadBlndY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysRackFFacX_Ary1D(self) ((self)->ClsdLoopHysRackFFacX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysRackFFacY_Ary2D(self) ((self)->ClsdLoopHysRackFFacY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysRhoY_Ary1D(self) ((self)->ClsdLoopHysRhoY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSysFricOffsLimX_Ary1D(self) ((self)->ClsdLoopHysSysFricOffsLimX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSysFricOffsLimY_Ary1D(self) ((self)->ClsdLoopHysSysFricOffsLimY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSysFricScaX_Ary1D(self) ((self)->ClsdLoopHysSysFricScaX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ClsdLoopHysSysFricScaY_Ary1D(self) ((self)->ClsdLoopHysSysFricScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EffortRackFX_Ary2D(self) ((self)->EffortRackFX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EffortRackFY_Ary2D(self) ((self)->EffortRackFY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EffortVehSpdBilnrSeln_Ary1D(self) ((self)->EffortVehSpdBilnrSeln.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define AAACalRegn02Rt01GroupD_Dummy_START_SEC_CODE
# include "AAACalRegn02Rt01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn02Rt01GroupDDummyInit1 CalRegn02Rt01GroupDDummyInit1
# endif

FUNC(void, AAACalRegn02Rt01GroupD_Dummy_CODE) CalRegn02Rt01GroupDDummyInit1(P2CONST(struct Rte_CDS_AAACalRegn02Rt01GroupD_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define AAACalRegn02Rt01GroupD_Dummy_STOP_SEC_CODE
# include "AAACalRegn02Rt01GroupD_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_AAACALREGN02RT01GROUPD_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
