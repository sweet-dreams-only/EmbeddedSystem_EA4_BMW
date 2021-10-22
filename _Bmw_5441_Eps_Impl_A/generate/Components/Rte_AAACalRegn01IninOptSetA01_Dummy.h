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
 *          File:  Rte_AAACalRegn01IninOptSetA01_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Application header file for SW-C <AAACalRegn01IninOptSetA01_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AAACALREGN01ININOPTSETA01_DUMMY_H
# define _RTE_AAACALREGN01ININOPTSETA01_DUMMY_H

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

# include "Rte_AAACalRegn01IninOptSetA01_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_AAACalRegn01IninOptSetA01_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_DutyCycThermProtnAbsltMotVelBreakPt_Val(self) ((self)->DutyCycThermProtnAbsltMotVelBreakPt.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltTTqSlewHiLim_Val(self) ((self)->DutyCycThermProtnAbsltTTqSlewHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltTTqSlewLoLim_Val(self) ((self)->DutyCycThermProtnAbsltTTqSlewLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnCtrlT_Val(self) ((self)->DutyCycThermProtnCtrlT.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnIgnOffMsgWaitTi_Val(self) ((self)->DutyCycThermProtnIgnOffMsgWaitTi.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnThermLimScaFac_Val(self) ((self)->DutyCycThermProtnThermLimScaFac.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnTqCmdSlewDwn_Val(self) ((self)->DutyCycThermProtnTqCmdSlewDwn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnTqCmdSlewUp_Val(self) ((self)->DutyCycThermProtnTqCmdSlewUp.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HiLoadStallLimrStallThermLimSca_Val(self) ((self)->HiLoadStallLimrStallThermLimSca.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrMotTqThd_Val(self) ((self)->LrndRackCentrMotTqThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_LrndRackCentrMotVelThd_Val(self) ((self)->LrndRackCentrMotVelThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnFetRNom_Val(self) ((self)->MotCtrlPrmEstimnFetRNom.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val(self) ((self)->MotCtrlPrmEstimnMotBackEmfConHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val(self) ((self)->MotCtrlPrmEstimnMotBackEmfConLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val(self) ((self)->MotCtrlPrmEstimnMotBackEmfConNom.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val(self) ((self)->MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val(self) ((self)->MotCtrlPrmEstimnMotInduDaxHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val(self) ((self)->MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val(self) ((self)->MotCtrlPrmEstimnMotInduDaxLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val(self) ((self)->MotCtrlPrmEstimnMotInduDaxNom.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val(self) ((self)->MotCtrlPrmEstimnMotInduQaxHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val(self) ((self)->MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val(self) ((self)->MotCtrlPrmEstimnMotInduQaxLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val(self) ((self)->MotCtrlPrmEstimnMotInduQaxNom.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val(self) ((self)->MotCtrlPrmEstimnMotRHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val(self) ((self)->MotCtrlPrmEstimnMotRLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotRNom_Val(self) ((self)->MotCtrlPrmEstimnMotRNom.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val(self) ((self)->MotCtrlPrmEstimnMotWidgThermCoeff.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnTNom_Val(self) ((self)->MotCtrlPrmEstimnTNom.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrPeakEstimnCurrFilFrq_Val(self) ((self)->MotCurrPeakEstimnCurrFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrPeakEstimnCurrPeakEstimdFilFrq_Val(self) ((self)->MotCurrPeakEstimnCurrPeakEstimdFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotDampgRatDax_Val(self) ((self)->MotCurrRegCfgMotDampgRatDax.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotDampgRatQax_Val(self) ((self)->MotCurrRegCfgMotDampgRatQax.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotRVirtDax_Val(self) ((self)->MotCurrRegCfgMotRVirtDax.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotRVirtQax_Val(self) ((self)->MotCurrRegCfgMotRVirtQax.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotVelFilFrq_Val(self) ((self)->MotCurrRegCfgMotVelFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrCurrLoaScarSlewRate_Val(self) ((self)->MotCurrRegVltgLimrCurrLoaScarSlewRate.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrDaxAntiWdupCoeff_Val(self) ((self)->MotCurrRegVltgLimrDaxAntiWdupCoeff.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrDualEcuLoaScarSlewRate_Val(self) ((self)->MotCurrRegVltgLimrDualEcuLoaScarSlewRate.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrFETLoaScarSlewRate_Val(self) ((self)->MotCurrRegVltgLimrFETLoaScarSlewRate.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrIvtrLoaScarSlewRate_Val(self) ((self)->MotCurrRegVltgLimrIvtrLoaScarSlewRate.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrMotVltgBrdgLpFilFrq_Val(self) ((self)->MotCurrRegVltgLimrMotVltgBrdgLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglHiLim_Val(self) ((self)->MotCurrRegVltgLimrMotVltgDaxIntglHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrMotVltgDaxIntglLoLim_Val(self) ((self)->MotCurrRegVltgLimrMotVltgDaxIntglLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq_Val(self) ((self)->MotCurrRegVltgLimrMotVltgQaxFfLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglHiLim_Val(self) ((self)->MotCurrRegVltgLimrMotVltgQaxIntglHiLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrMotVltgQaxIntglLoLim_Val(self) ((self)->MotCurrRegVltgLimrMotVltgQaxIntglLoLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupCoeff_Val(self) ((self)->MotCurrRegVltgLimrQaxAntiWdupCoeff.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlCurrDaxBoostGain_Val(self) ((self)->MotRefMdlCurrDaxBoostGain.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlCurrItrnTolr_Val(self) ((self)->MotRefMdlCurrItrnTolr.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlMotCurrDaxMaxSca_Val(self) ((self)->MotRefMdlMotCurrDaxMaxSca.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlVltgOverRThdSca_Val(self) ((self)->MotRefMdlVltgOverRThdSca.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotTqTranlDampgCmdLim_Val(self) ((self)->MotTqTranlDampgCmdLim.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotTqTranlDampgVelThd_Val(self) ((self)->MotTqTranlDampgVelThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrAssiRednLpFilFrq_Val(self) ((self)->PwrLimrAssiRednLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrBackEmfConStdT_Val(self) ((self)->PwrLimrBackEmfConStdT.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrBrdgVltgAdjSlew_Val(self) ((self)->PwrLimrBrdgVltgAdjSlew.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrBrdgVltgAltFltAdj_Val(self) ((self)->PwrLimrBrdgVltgAltFltAdj.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrFilAssiRednThd_Val(self) ((self)->PwrLimrFilAssiRednThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrLoVoltAssiRcvrThd_Val(self) ((self)->PwrLimrLoVoltAssiRcvrThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrMotVelLpFilFrq_Val(self) ((self)->PwrLimrMotVelLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrSpdAdjSlewDec_Val(self) ((self)->PwrLimrSpdAdjSlewDec.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrSpdAdjSlewInc_Val(self) ((self)->PwrLimrSpdAdjSlewInc.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmSysTqRat_Val(self) ((self)->SysGlbPrmSysTqRat.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechAmbLpFilFrq_Val(self) ((self)->TEstimnAssiMechAmbLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn_Val(self) ((self)->TEstimnAssiMechAmbLpFilFrqDualEcuFltMtgtn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechAmbLpFilFrqFetMtgtnEna_Val(self) ((self)->TEstimnAssiMechAmbLpFilFrqFetMtgtnEna.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuAmbLpFilFrq_Val(self) ((self)->TEstimnCuAmbLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuAmbLpFilFrqDualEcuFltMtgtn_Val(self) ((self)->TEstimnCuAmbLpFilFrqDualEcuFltMtgtn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuAmbLpFilFrqFetMtgtnEna_Val(self) ((self)->TEstimnCuAmbLpFilFrqFetMtgtnEna.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagAmbLpFilFrq_Val(self) ((self)->TEstimnMagAmbLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagAmbLpFilFrqDualEcuFltMtgtn_Val(self) ((self)->TEstimnMagAmbLpFilFrqDualEcuFltMtgtn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagAmbLpFilFrqFetMtgtnEna_Val(self) ((self)->TEstimnMagAmbLpFilFrqFetMtgtnEna.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiAmbLpFilFrq_Val(self) ((self)->TEstimnSiAmbLpFilFrq.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiAmbLpFilFrqDualEcuFltMtgtn_Val(self) ((self)->TEstimnSiAmbLpFilFrqDualEcuFltMtgtn.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiAmbLpFilFrqFetMtgtnEna_Val(self) ((self)->TEstimnSiAmbLpFilFrqFetMtgtnEna.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_VehSpdLimrPosMaxOffs2_Val(self) ((self)->VehSpdLimrPosMaxOffs2.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnDutyCycFildThd_Val(self) ((self)->DutyCycThermProtnDutyCycFildThd.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrLoVoltAssiRcvrTi_Val(self) ((self)->PwrLimrLoVoltAssiRcvrTi.Prm_Val()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnCtrlTSeln_Logl(self) ((self)->DutyCycThermProtnCtrlTSeln.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnIgnOffCtrlEna_Logl(self) ((self)->DutyCycThermProtnIgnOffCtrlEna.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMotPrTSeln_Logl(self) ((self)->DutyCycThermProtnMotPrTSeln.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplrTSeln_Logl(self) ((self)->DutyCycThermProtnMplrTSeln.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnSlowFilTSeln_Logl(self) ((self)->DutyCycThermProtnSlowFilTSeln.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegVltgLimrQaxAntiWdupScagDi_Logl(self) ((self)->MotCurrRegVltgLimrQaxAntiWdupScagDi.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrSpdAdjSlewEna_Logl(self) ((self)->PwrLimrSpdAdjSlewEna.Prm_Logl()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCtrlTFetMtgtnTblX_Ary1D(self) ((self)->DutyCycThermProtnAbsltCtrlTFetMtgtnTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCtrlTTblX_Ary1D(self) ((self)->DutyCycThermProtnAbsltCtrlTTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY_Ary1D(self) ((self)->DutyCycThermProtnAbsltCtrlTTqFetMtgtnTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCtrlTTqTblY_Ary1D(self) ((self)->DutyCycThermProtnAbsltCtrlTTqTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCuTFetMtgtnTblX_Ary1D(self) ((self)->DutyCycThermProtnAbsltCuTFetMtgtnTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCuTTblX_Ary1D(self) ((self)->DutyCycThermProtnAbsltCuTTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCuTTqFetMtgtnTblY_Ary1D(self) ((self)->DutyCycThermProtnAbsltCuTTqFetMtgtnTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnAbsltCuTTqTblY_Ary1D(self) ((self)->DutyCycThermProtnAbsltCuTTqTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnLstTblValNonStall_Ary2D(self) ((self)->DutyCycThermProtnLstTblValNonStall.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnLstTblValStall_Ary2D(self) ((self)->DutyCycThermProtnLstTblValStall.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr1FetMtgtnNonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr1FetMtgtnNonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr1FetMtgtnStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr1FetMtgtnStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr1NonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr1NonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr1StallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr1StallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr2FetMtgtnNonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr2FetMtgtnNonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr2FetMtgtnStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr2FetMtgtnStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr2NonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr2NonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr2StallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr2StallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr3FetMtgtnNonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr3FetMtgtnNonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr3FetMtgtnStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr3FetMtgtnStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr3NonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr3NonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr3StallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr3StallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr4FetMtgtnNonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr4FetMtgtnNonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr4FetMtgtnStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr4FetMtgtnStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr4NonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr4NonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr4StallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr4StallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr5FetMtgtnNonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr5FetMtgtnNonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr5FetMtgtnStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr5FetMtgtnStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr5NonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr5NonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr5StallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr5StallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr6FetMtgtnNonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr6FetMtgtnNonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr6FetMtgtnStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr6FetMtgtnStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr6NonStallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr6NonStallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplr6StallTblY_Ary1D(self) ((self)->DutyCycThermProtnMplr6StallTblY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplrFetMtgtnTblX_Ary1D(self) ((self)->DutyCycThermProtnMplrFetMtgtnTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnMplrTblX_Ary1D(self) ((self)->DutyCycThermProtnMplrTblX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnThermLoadLimTblX_Ary2D(self) ((self)->DutyCycThermProtnThermLoadLimTblX.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_DutyCycThermProtnThermLoadLimTblY_Ary2D(self) ((self)->DutyCycThermProtnThermLoadLimTblY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HiLoadStallLimrMotVelMgnThd_Ary1D(self) ((self)->HiLoadStallLimrMotVelMgnThd.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimX_Ary1D(self) ((self)->HiLoadStallLimrStallMotTqCmdFetMtgtnLimX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HiLoadStallLimrStallMotTqCmdFetMtgtnLimY_Ary1D(self) ((self)->HiLoadStallLimrStallMotTqCmdFetMtgtnLimY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HiLoadStallLimrStallMotTqCmdLimX_Ary1D(self) ((self)->HiLoadStallLimrStallMotTqCmdLimX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HiLoadStallLimrStallMotTqCmdLimY_Ary1D(self) ((self)->HiLoadStallLimrStallMotTqCmdLimY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_HiLoadStallLimrStallMotTqLimSlewRate_Ary1D(self) ((self)->HiLoadStallLimrStallMotTqLimSlewRate.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(self) ((self)->MotCtrlPrmEstimnMotBackEmfConSatnX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(self) ((self)->MotCtrlPrmEstimnMotBackEmfConSatnY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(self) ((self)->MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(self) ((self)->MotCtrlPrmEstimnMotCurrQaxInduSatnX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(self) ((self)->MotCtrlPrmEstimnMotInduDaxSatnScaY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(self) ((self)->MotCtrlPrmEstimnMotInduQaxSatnScaY.Prm_Ary2D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotClsdLoopBwDaxY_Ary1D(self) ((self)->MotCurrRegCfgMotClsdLoopBwDaxY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotClsdLoopBwQaxY_Ary1D(self) ((self)->MotCurrRegCfgMotClsdLoopBwQaxY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotNatFrqDaxY_Ary1D(self) ((self)->MotCurrRegCfgMotNatFrqDaxY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotCurrRegCfgMotNatFrqQaxY_Ary1D(self) ((self)->MotCurrRegCfgMotNatFrqQaxY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlCurrDaxBoostTqScaX_Ary1D(self) ((self)->MotRefMdlCurrDaxBoostTqScaX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlCurrDaxBoostTqScaY_Ary1D(self) ((self)->MotRefMdlCurrDaxBoostTqScaY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlCurrDaxQaxRefDelta_Ary1D(self) ((self)->MotRefMdlCurrDaxQaxRefDelta.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlQuad13VltgSdlX_Ary1D(self) ((self)->MotRefMdlQuad13VltgSdlX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlQuad13VltgSdlY_Ary1D(self) ((self)->MotRefMdlQuad13VltgSdlY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlQuad24VltgSdlX_Ary1D(self) ((self)->MotRefMdlQuad24VltgSdlX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_MotRefMdlQuad24VltgSdlY_Ary1D(self) ((self)->MotRefMdlQuad24VltgSdlY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrMotEnvlpX_Ary1D(self) ((self)->PwrLimrMotEnvlpX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrMotEnvlpY_Ary1D(self) ((self)->PwrLimrMotEnvlpY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrStdOperMotEnvlpX_Ary1D(self) ((self)->PwrLimrStdOperMotEnvlpX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrStdOperMotEnvlpY_Ary1D(self) ((self)->PwrLimrStdOperMotEnvlpY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrVltgDptMotVelOffsX_Ary1D(self) ((self)->PwrLimrVltgDptMotVelOffsX.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_PwrLimrVltgDptMotVelOffsY_Ary1D(self) ((self)->PwrLimrVltgDptMotVelOffsY.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAmbPwrMplr_Ary1D(self) ((self)->TEstimnAmbPwrMplr.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAmbTSca_Ary1D(self) ((self)->TEstimnAmbTSca.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechAmbMplr_Ary1D(self) ((self)->TEstimnAssiMechAmbMplr.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechCorrLim_Ary1D(self) ((self)->TEstimnAssiMechCorrLim.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechDampgSca_Ary1D(self) ((self)->TEstimnAssiMechDampgSca.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechDftT_Ary1D(self) ((self)->TEstimnAssiMechDftT.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechLLFilCoeffA1_Ary1D(self) ((self)->TEstimnAssiMechLLFilCoeffA1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechLLFilCoeffB0_Ary1D(self) ((self)->TEstimnAssiMechLLFilCoeffB0.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechLLFilCoeffB1_Ary1D(self) ((self)->TEstimnAssiMechLLFilCoeffB1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnAssiMechSlew_Ary1D(self) ((self)->TEstimnAssiMechSlew.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCorrnTAssiMech_Ary1D(self) ((self)->TEstimnCorrnTAssiMech.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCorrnTCu_Ary1D(self) ((self)->TEstimnCorrnTCu.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCorrnTMag_Ary1D(self) ((self)->TEstimnCorrnTMag.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCorrnTSi_Ary1D(self) ((self)->TEstimnCorrnTSi.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuAmbMplr_Ary1D(self) ((self)->TEstimnCuAmbMplr.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuCorrnLim_Ary1D(self) ((self)->TEstimnCuCorrnLim.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuLLFilCoeffA1_Ary1D(self) ((self)->TEstimnCuLLFilCoeffA1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuLLFilCoeffB0_Ary1D(self) ((self)->TEstimnCuLLFilCoeffB0.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnCuLLFilCoeffB1_Ary1D(self) ((self)->TEstimnCuLLFilCoeffB1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnEngTSca_Ary1D(self) ((self)->TEstimnEngTSca.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagAmbMplr_Ary1D(self) ((self)->TEstimnMagAmbMplr.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagCorrnLim_Ary1D(self) ((self)->TEstimnMagCorrnLim.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagLLFilCoeffA1_Ary1D(self) ((self)->TEstimnMagLLFilCoeffA1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagLLFilCoeffB0_Ary1D(self) ((self)->TEstimnMagLLFilCoeffB0.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnMagLLFilCoeffB1_Ary1D(self) ((self)->TEstimnMagLLFilCoeffB1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiAmbMplr_Ary1D(self) ((self)->TEstimnSiAmbMplr.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiCorrnLim_Ary1D(self) ((self)->TEstimnSiCorrnLim.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiLLFilCoeffA1_Ary1D(self) ((self)->TEstimnSiLLFilCoeffA1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiLLFilCoeffB0_Ary1D(self) ((self)->TEstimnSiLLFilCoeffB0.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnSiLLFilCoeffB1_Ary1D(self) ((self)->TEstimnSiLLFilCoeffB1.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnTauAssiMech_Ary1D(self) ((self)->TEstimnTauAssiMech.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnTauCu_Ary1D(self) ((self)->TEstimnTauCu.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnTauMag_Ary1D(self) ((self)->TEstimnTauMag.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnTauSi_Ary1D(self) ((self)->TEstimnTauSi.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_TEstimnWghtAvrgTDi_Ary1D(self) ((self)->TEstimnWghtAvrgTDi.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define AAACalRegn01IninOptSetA01_Dummy_START_SEC_CODE
# include "AAACalRegn01IninOptSetA01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn01IninOptSetA01DummyInit1 CalRegn01IninOptSetA01DummyInit1
# endif

FUNC(void, AAACalRegn01IninOptSetA01_Dummy_CODE) CalRegn01IninOptSetA01DummyInit1(P2CONST(struct Rte_CDS_AAACalRegn01IninOptSetA01_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define AAACalRegn01IninOptSetA01_Dummy_STOP_SEC_CODE
# include "AAACalRegn01IninOptSetA01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_AAACALREGN01ININOPTSETA01_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
