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
 *          File:  Rte_BmwHwAgArbnAndEotPosn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <BmwHwAgArbnAndEotPosn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_BMWHWAGARBNANDEOTPOSN_H
# define _RTE_BMWHWAGARBNANDEOTPOSN_H

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

/* include files */

# include "Rte_BmwHwAgArbnAndEotPosn_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl8_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BmwVehSpdSts1, RTE_VAR_INIT) Rte_BmwVehSpd_BmwSecurVehSpdSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwVehSpd_VehSpdVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl9_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwPinionAgQlfr1, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_HwAgCcwDetd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_HwAgCwDetd_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_HwAgEotCcw_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_HwAgEotCw_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwDiagcSrvHndlg_BmwHwAgOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwPinionAgOffsSts1, RTE_VAR_INIT) Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwQuadOffsSts1, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CmplncErr_CmplncErrMotToPinion_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_BmwHwAgArbnAndEotPosn_DiKineIntegrityTest_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LrndRackCentr_LongTermRackCentrCmpl_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(s18p13, RTE_VAR_INIT) Rte_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MotAgCorrln_MotAgMeclCorrlnSt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0TurnCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrndRackCentr_RackCentrPinionAg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_LrndRackCentr_TotRackTrvl_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AlgndPinionAg_Val (0.0F)
#  define Rte_InitValue_BmwHwAgOffs_Val (0.0F)
#  define Rte_InitValue_BmwPinionAg_Val (0.0F)
#  define Rte_InitValue_BmwPinionAgOffs_Val (0.0F)
#  define Rte_InitValue_BmwPinionAgOffsSts_Val (4U)
#  define Rte_InitValue_BmwPinionAgQlfr_Val (14U)
#  define Rte_InitValue_BmwQuadOffsSts_Val (15U)
#  define Rte_InitValue_BmwQuadOffsStsVld_Logl (FALSE)
#  define Rte_InitValue_BmwQuadRotorOffs_Val (0)
#  define Rte_InitValue_BmwQuadRotorOffsVld_Logl (FALSE)
#  define Rte_InitValue_BmwRackCentrToVehCentrOffs_Val (0.0F)
#  define Rte_InitValue_BmwRackCentrToVehCentrOffsVld_Logl (FALSE)
#  define Rte_InitValue_BmwVehSpdSts_Val (15U)
#  define Rte_InitValue_CmplncErrMotToPinion_Val (0.0F)
#  define Rte_InitValue_DiKineIntegrityTest_Logl (FALSE)
#  define Rte_InitValue_HwAgCcwDetd_Logl (FALSE)
#  define Rte_InitValue_HwAgCwDetd_Logl (FALSE)
#  define Rte_InitValue_HwAgEotCcw_Val (-360.0F)
#  define Rte_InitValue_HwAgEotCw_Val (360.0F)
#  define Rte_InitValue_LongTermRackCentrCmpl_Logl (FALSE)
#  define Rte_InitValue_LongTermVehCentrCmpl_Logl (FALSE)
#  define Rte_InitValue_MotAgCumvAlgndMrf_Val (0)
#  define Rte_InitValue_MotAgMeclCorrlnSt_Val (3U)
#  define Rte_InitValue_MotAgTurnCntr_Val (0.0F)
#  define Rte_InitValue_OffsCmpdPinionAg_Val (0.0F)
#  define Rte_InitValue_PinionAg_Val (0.0F)
#  define Rte_InitValue_PinionAgConf_Val (0.0F)
#  define Rte_InitValue_RackCentrPinionAg_Val (0.0F)
#  define Rte_InitValue_TotRackTrvl_Val (0.0F)
#  define Rte_InitValue_TurnCntrCorrlnSts_Val (3U)
#  define Rte_InitValue_VehSpd_Val (0.0F)
#  define Rte_InitValue_VehSpdVld_Logl (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BmwHwAgOffs_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwHwAgOffs_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwHwAgOffs_Val(data) (*(data) = Rte_BmwDiagcSrvHndlg_BmwHwAgOffs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAgOffs_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffs_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffs_Val(data) (*(data) = Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwPinionAgOffsSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffsSts_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwPinionAgOffsSts_Val(data) (*(data) = Rte_BmwMsgSlot108Bas0Repn2BusFrChA_BmwPinionAgOffsSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwQuadOffsSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsSts_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsSts_Val(data) (*(data) = Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwQuadOffsStsVld_Logl Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsStsVld_Logl
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadOffsStsVld_Logl(data) (*(data) = Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadOffsStsVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwQuadRotorOffs_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffs_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffs_Val(data) (*(data) = Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffs_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwQuadRotorOffsVld_Logl Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffsVld_Logl
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwQuadRotorOffsVld_Logl(data) (*(data) = Rte_BmwMsgSlot107Bas0Repn1BusFrChA_BmwQuadRtrOffsVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BmwVehSpdSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_BmwVehSpdSts_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_BmwVehSpdSts_Val(data) (*(data) = Rte_BmwVehSpd_BmwSecurVehSpdSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_CmplncErrMotToPinion_Val Rte_Read_BmwHwAgArbnAndEotPosn_CmplncErrMotToPinion_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_CmplncErrMotToPinion_Val(data) (*(data) = Rte_CmplncErr_CmplncErrMotToPinion_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_DiKineIntegrityTest_Logl Rte_Read_BmwHwAgArbnAndEotPosn_DiKineIntegrityTest_Logl
#  define Rte_Read_BmwHwAgArbnAndEotPosn_DiKineIntegrityTest_Logl(data) (*(data) = Rte_BmwHwAgArbnAndEotPosn_DiKineIntegrityTest_Logl, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_LongTermRackCentrCmpl_Logl Rte_Read_BmwHwAgArbnAndEotPosn_LongTermRackCentrCmpl_Logl
#  define Rte_Read_BmwHwAgArbnAndEotPosn_LongTermRackCentrCmpl_Logl(data) (*(data) = Rte_LrndRackCentr_LongTermRackCentrCmpl_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgCumvAlgndMrf_Val Rte_Read_BmwHwAgArbnAndEotPosn_MotAgCumvAlgndMrf_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_MotAgCumvAlgndMrf_Val(data) (*(data) = Rte_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgMeclCorrlnSt_Val Rte_Read_BmwHwAgArbnAndEotPosn_MotAgMeclCorrlnSt_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_MotAgMeclCorrlnSt_Val(data) (*(data) = Rte_MotAgCorrln_MotAgMeclCorrlnSt_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotAgTurnCntr_Val Rte_Read_BmwHwAgArbnAndEotPosn_MotAgTurnCntr_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_MotAgTurnCntr_Val(data) (*(data) = Rte_CDD_MotAg0Meas_MotAg0TurnCntr_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_RackCentrPinionAg_Val Rte_Read_BmwHwAgArbnAndEotPosn_RackCentrPinionAg_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_RackCentrPinionAg_Val(data) (*(data) = Rte_LrndRackCentr_RackCentrPinionAg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_TotRackTrvl_Val Rte_Read_BmwHwAgArbnAndEotPosn_TotRackTrvl_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_TotRackTrvl_Val(data) (*(data) = Rte_LrndRackCentr_TotRackTrvl_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_TurnCntrCorrlnSts_Val Rte_Read_BmwHwAgArbnAndEotPosn_TurnCntrCorrlnSts_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_TurnCntrCorrlnSts_Val(data) (*(data) = Rte_TurnCntrCorrln_TurnCntrCorrlnSts_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_Val Rte_Read_BmwHwAgArbnAndEotPosn_VehSpd_Val
#  define Rte_Read_BmwHwAgArbnAndEotPosn_VehSpd_Val(data) (*(data) = Rte_BmwVehSpd_VehSpd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpdVld_Logl Rte_Read_BmwHwAgArbnAndEotPosn_VehSpdVld_Logl
#  define Rte_Read_BmwHwAgArbnAndEotPosn_VehSpdVld_Logl(data) (*(data) = Rte_BmwVehSpd_VehSpdVld_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AlgndPinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val(data) (Rte_BmwHwAgArbnAndEotPosn_AlgndPinionAg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwPinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val(data) (Rte_BmwHwAgArbnAndEotPosn_BmwPinionAg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwPinionAgQlfr_Val Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val(data) (Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwRackCentrToVehCentrOffs_Val Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val(data) (Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffs_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl
#  define Rte_Write_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl(data) (Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsVld_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwAgCcwDetd_Logl Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCcwDetd_Logl
#  define Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCcwDetd_Logl(data) (Rte_BmwHwAgArbnAndEotPosn_HwAgCcwDetd_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwAgCwDetd_Logl Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCwDetd_Logl
#  define Rte_Write_BmwHwAgArbnAndEotPosn_HwAgCwDetd_Logl(data) (Rte_BmwHwAgArbnAndEotPosn_HwAgCwDetd_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwAgEotCcw_Val Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCcw_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCcw_Val(data) (Rte_BmwHwAgArbnAndEotPosn_HwAgEotCcw_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_HwAgEotCw_Val Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCw_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_HwAgEotCw_Val(data) (Rte_BmwHwAgArbnAndEotPosn_HwAgEotCw_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_LongTermVehCentrCmpl_Logl Rte_Write_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl
#  define Rte_Write_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl(data) (Rte_BmwHwAgArbnAndEotPosn_LongTermVehCentrCmpl_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_OffsCmpdPinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val(data) (Rte_BmwHwAgArbnAndEotPosn_OffsCmpdPinionAg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionAg_Val Rte_Write_BmwHwAgArbnAndEotPosn_PinionAg_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_PinionAg_Val(data) (Rte_BmwHwAgArbnAndEotPosn_PinionAg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PinionAgConf_Val Rte_Write_BmwHwAgArbnAndEotPosn_PinionAgConf_Val
#  define Rte_Write_BmwHwAgArbnAndEotPosn_PinionAgConf_Val(data) (Rte_BmwHwAgArbnAndEotPosn_PinionAgConf_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_BmwVehCentrOffs_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)16, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)16, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) GetNtcQlfrSts10_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL10_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts10_Oper
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr100MicroSec32bit_Oper(arg1) (GetRefTmr100MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan100MicroSec32bit_Oper(arg1, arg2) (GetTiSpan100MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_LRNDRACKCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_LRNDRACKCENTR_APPL_CODE) RstRackCentrMotRev_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_LRNDRACKCENTR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_RstRackCentrMotRev_Oper() (RstRackCentrMotRev_Oper(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnEotCcwMax_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnEotCcwMin_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnEotCwMax_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00GroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnEotCwMin_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnMotToHwResl_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnOffsAuthy_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnPinionAgDifThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmSysKineRat_Val() (((P2CONST(Rte_Calprm_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Inin00_DEFAULT_RTE_CALPRM_GROUP])->SysGlbPrmSysKineRat_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnAllwExitFromInit_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01CmnGroupA_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl() (((P2CONST(Rte_Calprm_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Cmn_DEFAULT_RTE_CALPRM_GROUP])->BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgOffsRateLim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_CurrAlgndPinionAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PinionAgConfRampStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevBmwOffsAuthy; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevLoopPinionAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevPinionAgConf; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_AllwExitFromInitTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_MotPosnDegArbdBlndTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_OffsCorrnRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PinionAgFltRefTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_TurnCntrValTi; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwRackToVehCentrOffsSts1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_FirstLoopIndcr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_IniTurnCntrCorrlnSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwMotAgSelnSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycNtc8CSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycNtc8ESts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycTurnCntrCorrlnSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwMotAgSelnSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevLoopBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwQuadOffsSts1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevLoopBmwQuadOffsSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_ClrNotCmplPinionAgFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_CurrDftPinionAgFltPrsnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_DynStabyCtrlCdn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_KineIntegrityFlt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_LpFilActvd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_MotPosnDegArbdBlndFac; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevAllwCorrn; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PrevBmwOffsAuthyFlg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_SetBmwRackCentrToVehCentrOffsTrig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_SigInvldTranTrig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_TurnCntrCorrlnStsTmrTrig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_VehCentrCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(BmwVehCentrOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BmwHwAgArbnAndEotPosn_PinionAgFilStVari; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_BmwPinionAgOffsRateLim() \
  (&Rte_BmwHwAgArbnAndEotPosn_BmwPinionAgOffsRateLim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CurrAlgndPinionAg() \
  (&Rte_BmwHwAgArbnAndEotPosn_CurrAlgndPinionAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PinionAgConfRampStVari() \
  (&Rte_BmwHwAgArbnAndEotPosn_PinionAgConfRampStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevBmwOffsAuthy() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevBmwOffsAuthy) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevLoopPinionAg() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevLoopPinionAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevPinionAgConf() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevPinionAgConf) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_AllwExitFromInitTi() \
  (&Rte_BmwHwAgArbnAndEotPosn_AllwExitFromInitTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotPosnDegArbdBlndTi() \
  (&Rte_BmwHwAgArbnAndEotPosn_MotPosnDegArbdBlndTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_OffsCorrnRefTi() \
  (&Rte_BmwHwAgArbnAndEotPosn_OffsCorrnRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PinionAgFltRefTi() \
  (&Rte_BmwHwAgArbnAndEotPosn_PinionAgFltRefTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TurnCntrValTi() \
  (&Rte_BmwHwAgArbnAndEotPosn_TurnCntrValTi) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwRackCentrToVehCentrOffsSts() \
  (&Rte_BmwHwAgArbnAndEotPosn_BmwRackCentrToVehCentrOffsSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_FirstLoopIndcr() \
  (&Rte_BmwHwAgArbnAndEotPosn_FirstLoopIndcr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_IniTurnCntrCorrlnSts() \
  (&Rte_BmwHwAgArbnAndEotPosn_IniTurnCntrCorrlnSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevBmwMotAgSelnSt() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevIgnCycBmwMotAgSelnSt() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevIgnCycNtc8CSts() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycNtc8CSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevIgnCycNtc8ESts() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycNtc8ESts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevIgnCycTurnCntrCorrlnSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevLoopBmwMotAgSelnSt() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevLoopBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevLoopBmwQuadOffsSts() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevLoopBmwQuadOffsSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() \
  (&Rte_BmwHwAgArbnAndEotPosn_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_ClrNotCmplPinionAgFlg() \
  (&Rte_BmwHwAgArbnAndEotPosn_ClrNotCmplPinionAgFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CurrDftPinionAgFltPrsnt() \
  (&Rte_BmwHwAgArbnAndEotPosn_CurrDftPinionAgFltPrsnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DynStabyCtrlCdn() \
  (&Rte_BmwHwAgArbnAndEotPosn_DynStabyCtrlCdn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_KineIntegrityFlt() \
  (&Rte_BmwHwAgArbnAndEotPosn_KineIntegrityFlt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_LpFilActvd() \
  (&Rte_BmwHwAgArbnAndEotPosn_LpFilActvd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotPosnDegArbdBlndFac() \
  (&Rte_BmwHwAgArbnAndEotPosn_MotPosnDegArbdBlndFac) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevAllwCorrn() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevAllwCorrn) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PrevBmwOffsAuthyFlg() \
  (&Rte_BmwHwAgArbnAndEotPosn_PrevBmwOffsAuthyFlg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() \
  (&Rte_BmwHwAgArbnAndEotPosn_SetBmwRackCentrToVehCentrOffsTrig) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SigInvldTranTrig() \
  (&Rte_BmwHwAgArbnAndEotPosn_SigInvldTranTrig) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_TurnCntrCorrlnStsTmrTrig() \
  (&Rte_BmwHwAgArbnAndEotPosn_TurnCntrCorrlnStsTmrTrig) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_VehCentrCmpl() \
  (&Rte_BmwHwAgArbnAndEotPosn_VehCentrCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_BmwVehCentrOffs() \
  (&Rte_BmwHwAgArbnAndEotPosn_BmwVehCentrOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_PinionAgFilStVari() \
  (&Rte_BmwHwAgArbnAndEotPosn_PinionAgFilStVari) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define BmwHwAgArbnAndEotPosn_START_SEC_CODE
# include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BmwHwAgArbnAndEotPosnInit1 BmwHwAgArbnAndEotPosnInit1
#  define RTE_RUNNABLE_BmwHwAgArbnAndEotPosnPer1 BmwHwAgArbnAndEotPosnPer1
#  define RTE_RUNNABLE_ClrBmwRackCentrToVehCentrOffs_Oper ClrBmwRackCentrToVehCentrOffs_Oper
#  define RTE_RUNNABLE_ClrVehCentrPosn_Oper ClrVehCentrPosn_Oper
#  define RTE_RUNNABLE_SetVehCentrPosn_Oper SetVehCentrPosn_Oper
# endif

FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwHwAgArbnAndEotPosnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwHwAgArbnAndEotPosnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrBmwRackCentrToVehCentrOffs_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrVehCentrPosn_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, BmwHwAgArbnAndEotPosn_CODE) SetVehCentrPosn_Oper(P2VAR(BmwSetVehCentrOffsSts1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) BmwSetVehCentrOffsSts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define BmwHwAgArbnAndEotPosn_STOP_SEC_CODE
# include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_BMWHWAGARBNANDEOTPOSN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
