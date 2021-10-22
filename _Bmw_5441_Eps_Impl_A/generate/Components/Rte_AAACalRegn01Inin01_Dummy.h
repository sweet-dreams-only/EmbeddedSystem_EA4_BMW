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
 *          File:  Rte_AAACalRegn01Inin01_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <AAACalRegn01Inin01_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AAACALREGN01ININ01_DUMMY_H
# define _RTE_AAACALREGN01ININ01_DUMMY_H

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

# include "Rte_AAACalRegn01Inin01_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_AAACalRegn01Inin01_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(self) ((self)->BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EffortScaRackFThd_Val(self) ((self)->EffortScaRackFThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq_Val(self) ((self)->PosnTrakgServoArbnFltMtgtnLpFilCutOffFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(self) ((self)->PullCmpActvHwTqFilFrqLrngEna.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvYawRateFilFrq_Val(self) ((self)->PullCmpActvYawRateFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngAvrgFricFrq_Val(self) ((self)->SysFricLrngAvrgFricFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngBasLineEolFric_Val(self) ((self)->SysFricLrngBasLineEolFric.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngDataPrepLpFilFrq_Val(self) ((self)->SysFricLrngDataPrepLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngEolFricDifHiLim_Val(self) ((self)->SysFricLrngEolFricDifHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngEolFricDifLoLim_Val(self) ((self)->SysFricLrngEolFricDifLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngEolFricDifScagFac_Val(self) ((self)->SysFricLrngEolFricDifScagFac.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngFricDiagcThd_Val(self) ((self)->SysFricLrngFricDiagcThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngFricOffs_Val(self) ((self)->SysFricLrngFricOffs.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngFricOffsHiLim_Val(self) ((self)->SysFricLrngFricOffsHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngFricOffsLoLim_Val(self) ((self)->SysFricLrngFricOffsLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngFricOffsLpFilFrq_Val(self) ((self)->SysFricLrngFricOffsLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngGain_Val(self) ((self)->SysFricLrngGain.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngHiFricDiagcThd_Val(self) ((self)->SysFricLrngHiFricDiagcThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngHwPosnAuthyThd_Val(self) ((self)->SysFricLrngHwPosnAuthyThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngHwVelConstrLim_Val(self) ((self)->SysFricLrngHwVelConstrLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngHwVelHiLim_Val(self) ((self)->SysFricLrngHwVelHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngHwVelLoLim_Val(self) ((self)->SysFricLrngHwVelLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngIgnCycFricChgLim_Val(self) ((self)->SysFricLrngIgnCycFricChgLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngIgnCycFricOffs_Val(self) ((self)->SysFricLrngIgnCycFricOffs.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngLatAHiLim_Val(self) ((self)->SysFricLrngLatAHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngLatALoLim_Val(self) ((self)->SysFricLrngLatALoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngTHiLim_Val(self) ((self)->SysFricLrngTHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngTLoLim_Val(self) ((self)->SysFricLrngTLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmSysKineRat_Val(self) ((self)->SysGlbPrmSysKineRat.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngThd_Val(self) ((self)->SysFricLrngThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngDebStep_Val(self) ((self)->SysFricLrngDebStep.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngHiFricDebStep_Val(self) ((self)->SysFricLrngHiFricDebStep.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngRngCntrThd_Val(self) ((self)->SysFricLrngRngCntrThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EffortScaBlndX_Ary1D(self) ((self)->EffortScaBlndX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EffortScaBlndY_Ary1D(self) ((self)->EffortScaBlndY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngBasLineFric_Ary1D(self) ((self)->SysFricLrngBasLineFric.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngBasLineHys_Ary2D(self) ((self)->SysFricLrngBasLineHys.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngBasLineRngCntr_Ary2D(self) ((self)->SysFricLrngBasLineRngCntr.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngFricChgWght_Ary1D(self) ((self)->SysFricLrngFricChgWght.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngFricHysHwAgPt_Ary1D(self) ((self)->SysFricLrngFricHysHwAgPt.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngIvsTrsmRatX_Ary1D(self) ((self)->SysFricLrngIvsTrsmRatX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngIvsTrsmRatY_Ary1D(self) ((self)->SysFricLrngIvsTrsmRatY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngMaskVehSpd_Ary1D(self) ((self)->SysFricLrngMaskVehSpd.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysFricLrngVehSpd_Ary2D(self) ((self)->SysFricLrngVehSpd.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmVehSpdBilnrSeln_Ary1D(self) ((self)->SysGlbPrmVehSpdBilnrSeln.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysKineAndEffMotAgToRackPosRatScaY_Ary1D(self) ((self)->SysKineAndEffMotAgToRackPosRatScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysKineAndEffPinionAgToRackPosRatScaY_Ary1D(self) ((self)->SysKineAndEffPinionAgToRackPosRatScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysKineAndEffPinionToRackEffScaY_Ary1D(self) ((self)->SysKineAndEffPinionToRackEffScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysKineAndEffRoadWhlFromRackPosScaY_Ary1D(self) ((self)->SysKineAndEffRoadWhlFromRackPosScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysKineAndEffSteerArmLenFromRackPosScaY_Ary1D(self) ((self)->SysKineAndEffSteerArmLenFromRackPosScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TunSelnAuthyVehSpdX_Ary1D(self) ((self)->TunSelnAuthyVehSpdX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define AAACalRegn01Inin01_Dummy_START_SEC_CODE
# include "AAACalRegn01Inin01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn01Inin01DummyInit1 CalRegn01Inin01DummyInit1
# endif

FUNC(void, AAACalRegn01Inin01_Dummy_CODE) CalRegn01Inin01DummyInit1(P2CONST(struct Rte_CDS_AAACalRegn01Inin01_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define AAACalRegn01Inin01_Dummy_STOP_SEC_CODE
# include "AAACalRegn01Inin01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_AAACALREGN01ININ01_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
