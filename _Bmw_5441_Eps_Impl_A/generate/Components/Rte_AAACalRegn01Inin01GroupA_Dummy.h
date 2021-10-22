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
 *          File:  Rte_AAACalRegn01Inin01GroupA_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <AAACalRegn01Inin01GroupA_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AAACALREGN01ININ01GROUPA_DUMMY_H
# define _RTE_AAACALREGN01ININ01GROUPA_DUMMY_H

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

# include "Rte_AAACalRegn01Inin01GroupA_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_AAACalRegn01Inin01GroupA_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val(self) ((self)->BmwHwAgArbnAndEotPosnEotCcwMax.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val(self) ((self)->BmwHwAgArbnAndEotPosnEotCcwMin.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val(self) ((self)->BmwHwAgArbnAndEotPosnEotCwMax.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val(self) ((self)->BmwHwAgArbnAndEotPosnEotCwMin.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwPwrPrkgDampgMaxRate_Val(self) ((self)->BmwPwrPrkgDampgMaxRate.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(self) ((self)->PullCmpActvCmpLrnTiDecShoTerm.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(self) ((self)->PullCmpActvCmpLrnTiIncShoTerm.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(self) ((self)->PullCmpActvCmpLrnTiLongTerm.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(self) ((self)->PullCmpActvCmpShoTermRstHwAgThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(self) ((self)->PullCmpActvCmpShoTermRstHwTqThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(self) ((self)->PullCmpActvCmpShoTermRstLatAThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(self) ((self)->PullCmpActvCmpShoTermRstYawRateThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(self) ((self)->PullCmpActvHwTqFilFrqLongTerm.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(self) ((self)->PullCmpActvHwTqFilFrqShoTerm.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLongTermLim_Val(self) ((self)->PullCmpActvLongTermLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(self) ((self)->PullCmpActvLrngEnaAgConfMinMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(self) ((self)->PullCmpActvLrngEnaHwAgMaxMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(self) ((self)->PullCmpActvLrngEnaHwTqMaxMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(self) ((self)->PullCmpActvLrngEnaHwVelMaxMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(self) ((self)->PullCmpActvLrngEnaLatAMaxMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaTiThd_Val(self) ((self)->PullCmpActvLrngEnaTiThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(self) ((self)->PullCmpActvLrngEnaVehSpdMaxMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(self) ((self)->PullCmpActvLrngEnaVehSpdMinMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(self) ((self)->PullCmpActvLrngEnaVehSpdRateMaxMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(self) ((self)->PullCmpActvLrngEnaYawRateMaxMgn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(self) ((self)->PullCmpActvOpstSignTiShoTerm.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvOutpMaxRate_Val(self) ((self)->PullCmpActvOutpMaxRate.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(self) ((self)->PullCmpActvPullCmpShoTermLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullCmpTotLim_Val(self) ((self)->PullCmpActvPullCmpTotLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(self) ((self)->PullCmpActvPullErrLimLongTerm.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullErrMgnThd_Val(self) ((self)->PullCmpActvPullErrMgnThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvPullErrShoTermLim_Val(self) ((self)->PullCmpActvPullErrShoTermLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvShoTermRampTi_Val(self) ((self)->PullCmpActvShoTermRampTi.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwPwrPrkgDampgDiScadDampg_Logl(self) ((self)->BmwPwrPrkgDampgDiScadDampg.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvEna_Logl(self) ((self)->PullCmpActvEna.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EpsStEstimnMtrxA_Ary2D(self) ((self)->EpsStEstimnMtrxA.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EpsStEstimnMtrxB_Ary2D(self) ((self)->EpsStEstimnMtrxB.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EpsStEstimnMtrxC_Ary2D(self) ((self)->EpsStEstimnMtrxC.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_EpsStEstimnMtrxD_Ary2D(self) ((self)->EpsStEstimnMtrxD.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTqTrakgCtrlFbGain1_Ary1D(self) ((self)->HwTqTrakgCtrlFbGain1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTqTrakgCtrlFbGain2_Ary1D(self) ((self)->HwTqTrakgCtrlFbGain2.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTqTrakgCtrlFbGain3_Ary1D(self) ((self)->HwTqTrakgCtrlFbGain3.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTqTrakgCtrlFbGain4_Ary1D(self) ((self)->HwTqTrakgCtrlFbGain4.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTqTrakgCtrlFbGain5_Ary1D(self) ((self)->HwTqTrakgCtrlFbGain5.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTqTrakgCtrlFfGainScaY_Ary1D(self) ((self)->HwTqTrakgCtrlFfGainScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HwTqTrakgCtrlVehSpdScaX_Ary1D(self) ((self)->HwTqTrakgCtrlVehSpdScaX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PosnTrakgServoEnaBlndFacTblX_Ary1D(self) ((self)->PosnTrakgServoEnaBlndFacTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PosnTrakgServoEnaBlndFacTblY_Ary1D(self) ((self)->PosnTrakgServoEnaBlndFacTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PosnTrakgServoGainArbnFltMtgtn_Ary1D(self) ((self)->PosnTrakgServoGainArbnFltMtgtn.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(self) ((self)->PullCmpActvVehSpdScaTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(self) ((self)->PullCmpActvVehSpdScaTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define AAACalRegn01Inin01GroupA_Dummy_START_SEC_CODE
# include "AAACalRegn01Inin01GroupA_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn01Inin01GroupADummyInit1 CalRegn01Inin01GroupADummyInit1
# endif

FUNC(void, AAACalRegn01Inin01GroupA_Dummy_CODE) CalRegn01Inin01GroupADummyInit1(P2CONST(struct Rte_CDS_AAACalRegn01Inin01GroupA_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define AAACalRegn01Inin01GroupA_Dummy_STOP_SEC_CODE
# include "AAACalRegn01Inin01GroupA_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_AAACALREGN01ININ01GROUPA_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
