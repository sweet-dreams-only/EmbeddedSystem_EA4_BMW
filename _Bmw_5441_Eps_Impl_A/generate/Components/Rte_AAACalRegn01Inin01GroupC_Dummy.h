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
 *          File:  Rte_AAACalRegn01Inin01GroupC_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <AAACalRegn01Inin01GroupC_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AAACALREGN01ININ01GROUPC_DUMMY_H
# define _RTE_AAACALREGN01ININ01GROUPC_DUMMY_H

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

# include "Rte_AAACalRegn01Inin01GroupC_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_AAACalRegn01Inin01GroupC_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(self) ((self)->CtrldVelRtnDesVelLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(self) ((self)->CtrldVelRtnHwTqLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(self) ((self)->CtrldVelRtnHwTqScaSelnSlewHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(self) ((self)->CtrldVelRtnHwTqScaSelnSlewLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(self) ((self)->CtrldVelRtnHwTqScaSelnTqThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(self) ((self)->CtrldVelRtnHwTqScaSelnVelThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnOffsSlewThd_Val(self) ((self)->CtrldVelRtnOffsSlewThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnOffsThd_Val(self) ((self)->CtrldVelRtnOffsThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(self) ((self)->CtrldVelRtnScaLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(self) ((self)->CtrldVelRtnIntgrLimY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_FalbckAssiAssiX_Ary2D(self) ((self)->FalbckAssiAssiX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_FalbckAssiAssiY_Ary2D(self) ((self)->FalbckAssiAssiY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_GlbLimrBndX_Ary2D(self) ((self)->GlbLimrBndX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_GlbLimrBndY_Ary2D(self) ((self)->GlbLimrBndY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_GlbLimrVehSpdBilnrSeln_Ary1D(self) ((self)->GlbLimrVehSpdBilnrSeln.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_FalbckAssiNotchFil_Rec(self) ((self)->FalbckAssiNotchFil.Prm_Rec()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_GlbLimrNotchFilStruct_Rec(self) ((self)->GlbLimrNotchFilStruct.Prm_Rec()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define AAACalRegn01Inin01GroupC_Dummy_START_SEC_CODE
# include "AAACalRegn01Inin01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn01Inin01GroupCDummyInit1 CalRegn01Inin01GroupCDummyInit1
# endif

FUNC(void, AAACalRegn01Inin01GroupC_Dummy_CODE) CalRegn01Inin01GroupCDummyInit1(P2CONST(struct Rte_CDS_AAACalRegn01Inin01GroupC_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define AAACalRegn01Inin01GroupC_Dummy_STOP_SEC_CODE
# include "AAACalRegn01Inin01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_AAACALREGN01ININ01GROUPC_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
