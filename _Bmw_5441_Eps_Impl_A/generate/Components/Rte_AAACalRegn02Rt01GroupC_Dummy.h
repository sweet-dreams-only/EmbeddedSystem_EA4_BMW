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
 *          File:  Rte_AAACalRegn02Rt01GroupC_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <AAACalRegn02Rt01GroupC_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AAACALREGN02RT01GROUPC_DUMMY_H
# define _RTE_AAACALREGN02RT01GROUPC_DUMMY_H

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

# include "Rte_AAACalRegn02Rt01GroupC_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_AAACalRegn02Rt01GroupC_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(self) ((self)->CtrldVelRtnVelErrScaEna.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDampgX_Ary2D(self) ((self)->CtrldVelRtnDampgX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDampgY_Ary2D(self) ((self)->CtrldVelRtnDampgY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(self) ((self)->CtrldVelRtnDesVelScaX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(self) ((self)->CtrldVelRtnDesVelScaY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDesVelX_Ary2D(self) ((self)->CtrldVelRtnDesVelX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnDesVelY_Ary2D(self) ((self)->CtrldVelRtnDesVelY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(self) ((self)->CtrldVelRtnHwPosnScaX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(self) ((self)->CtrldVelRtnHwPosnScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(self) ((self)->CtrldVelRtnHwTqSca1X.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(self) ((self)->CtrldVelRtnHwTqSca1Y.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(self) ((self)->CtrldVelRtnHwTqSca2X.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(self) ((self)->CtrldVelRtnHwTqSca2Y.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnIntglGain_Ary1D(self) ((self)->CtrldVelRtnIntglGain.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(self) ((self)->CtrldVelRtnPinionTqScaX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(self) ((self)->CtrldVelRtnPinionTqScaY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnPropGain_Ary1D(self) ((self)->CtrldVelRtnPropGain.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(self) ((self)->CtrldVelRtnTqGrdtScaX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(self) ((self)->CtrldVelRtnTqGrdtScaY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(self) ((self)->CtrldVelRtnVehSpdScaBilnrSeln.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(self) ((self)->CtrldVelRtnVelErrScaBilnrSeln.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(self) ((self)->CtrldVelRtnVelErrScaX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(self) ((self)->CtrldVelRtnVelErrScaY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(self) ((self)->CtrldVelRtnVelErrVehSpdScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(self) ((self)->CtrldVelRtnVelSpdTbl.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define AAACalRegn02Rt01GroupC_Dummy_START_SEC_CODE
# include "AAACalRegn02Rt01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn02Rt01GroupCDummyInit1 CalRegn02Rt01GroupCDummyInit1
# endif

FUNC(void, AAACalRegn02Rt01GroupC_Dummy_CODE) CalRegn02Rt01GroupCDummyInit1(P2CONST(struct Rte_CDS_AAACalRegn02Rt01GroupC_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define AAACalRegn02Rt01GroupC_Dummy_STOP_SEC_CODE
# include "AAACalRegn02Rt01GroupC_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_AAACALREGN02RT01GROUPC_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
