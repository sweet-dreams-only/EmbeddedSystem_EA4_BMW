/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MotCtrlPrmEstimn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  MotCtrlPrmEstimn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <MotCtrlPrmEstimn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * u2p14
 *   
 *
 * u9p7
 *   
 *
 *********************************************************************************************************************/

#include "Rte_MotCtrlPrmEstimn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MotCtrlPrmEstimn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void MotCtrlPrmEstimn_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * u2p14: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Array Types:
 * ============
 * Ary1D_u2p14_16: Array with 16 element(s) of type u2p14
 * Ary1D_u2p14_7: Array with 7 element(s) of type u2p14
 * Ary1D_u9p7_16: Array with 16 element(s) of type u9p7
 * Ary1D_u9p7_6: Array with 6 element(s) of type u9p7
 * Ary1D_u9p7_7: Array with 7 element(s) of type u9p7
 * Ary2D_u2p14_6_7: Array with 6 element(s) of type Ary1D_u2p14_7
 *
 * Record Types:
 * =============
 * MotPrmNomEolRec3: Record with elements
 *   MotBackEmfConNom of type float32
 *   MotRNom of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax(void)
 *   float32 *Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd(void)
 *   MotPrmNomEolRec3 *Rte_Pim_MotPrmNom(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_MotCtrlPrmEstimnFetRNom_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotRNom_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val(void)
 *   float32 Rte_Prm_MotCtrlPrmEstimnTNom_Val(void)
 *   u9p7 *Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_16
 *   u2p14 *Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_16
 *   u9p7 *Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_6
 *   u9p7 *Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_7
 *   u2p14 *Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_6_7
 *   u2p14 *Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_6_7
 *
 *********************************************************************************************************************/


#define MotCtrlPrmEstimn_START_SEC_CODE
#include "MotCtrlPrmEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMotPrmNomEol_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetMotPrmNomEol>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetMotPrmNomEol_Oper(float32 *MotBackEmfConNom_Arg, float32 *MotRNom_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMotPrmNomEol_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotCtrlPrmEstimn_CODE) GetMotPrmNomEol_Oper(P2VAR(float32, AUTOMATIC, RTE_MOTCTRLPRMESTIMN_APPL_VAR) MotBackEmfConNom_Arg, P2VAR(float32, AUTOMATIC, RTE_MOTCTRLPRMESTIMN_APPL_VAR) MotRNom_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMotPrmNomEol_Oper
 *********************************************************************************************************************/

  float32 PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  float32 PimdMotCtrlPrmEstimnFetRFfEstimd;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  float32 PimdMotCtrlPrmEstimnMotRFfEstimd;
  MotPrmNomEolRec3 PimMotPrmNom;

  float32 MotCtrlPrmEstimnFetRNom_Val_data;
  float32 MotCtrlPrmEstimnFetThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMagThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConNom_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotRHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotRLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotRNom_Val_data;
  float32 MotCtrlPrmEstimnMotWidgThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnTNom_Val_data;
  Ary1D_u9p7_16 MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data;
  Ary1D_u2p14_16 MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data;
  Ary1D_u9p7_6 MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data;
  Ary1D_u9p7_7 MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotCtrlPrmEstimnCtrlrREstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim() = PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  PimdMotCtrlPrmEstimnFetRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd() = PimdMotCtrlPrmEstimnFetRFfEstimd;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  PimdMotCtrlPrmEstimnMotRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd() = PimdMotCtrlPrmEstimnMotRFfEstimd;
  PimMotPrmNom = *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom() = PimMotPrmNom;

  MotCtrlPrmEstimnFetRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val();
  MotCtrlPrmEstimnFetThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val();
  MotCtrlPrmEstimnMagThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val();
  MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val();
  MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val();
  MotCtrlPrmEstimnMotBackEmfConNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val();
  MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val();
  MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val();
  MotCtrlPrmEstimnMotInduDaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val();
  MotCtrlPrmEstimnMotInduQaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val();
  MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduQaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val();
  MotCtrlPrmEstimnMotInduQaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val();
  MotCtrlPrmEstimnMotRHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val();
  MotCtrlPrmEstimnMotRLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val();
  MotCtrlPrmEstimnMotRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val();
  MotCtrlPrmEstimnMotWidgThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val();
  MotCtrlPrmEstimnTNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnTNom_Val();
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(), sizeof(Ary1D_u9p7_16));
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(), sizeof(Ary1D_u2p14_16));
  (void)memcpy(MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_6));
  (void)memcpy(MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(), sizeof(Ary1D_u9p7_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));

  MotCtrlPrmEstimn_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotCtrlPrmEstimnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotBackEmfConEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotInduDaxEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotInduQaxEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotREstimd_Val(float32 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotPrmNom_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_MotPrmNom_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCtrlPrmEstimnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotCtrlPrmEstimn_CODE) MotCtrlPrmEstimnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCtrlPrmEstimnInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  float32 PimdMotCtrlPrmEstimnFetRFfEstimd;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  float32 PimdMotCtrlPrmEstimnMotRFfEstimd;
  MotPrmNomEolRec3 PimMotPrmNom;

  float32 MotCtrlPrmEstimnFetRNom_Val_data;
  float32 MotCtrlPrmEstimnFetThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMagThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConNom_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotRHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotRLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotRNom_Val_data;
  float32 MotCtrlPrmEstimnMotWidgThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnTNom_Val_data;
  Ary1D_u9p7_16 MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data;
  Ary1D_u2p14_16 MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data;
  Ary1D_u9p7_6 MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data;
  Ary1D_u9p7_7 MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data;

  NvM_RequestResultType Call_MotPrmNom_GetErrorStatus_ErrorStatus_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotCtrlPrmEstimnCtrlrREstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim() = PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  PimdMotCtrlPrmEstimnFetRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd() = PimdMotCtrlPrmEstimnFetRFfEstimd;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  PimdMotCtrlPrmEstimnMotRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd() = PimdMotCtrlPrmEstimnMotRFfEstimd;
  PimMotPrmNom = *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom() = PimMotPrmNom;

  MotCtrlPrmEstimnFetRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val();
  MotCtrlPrmEstimnFetThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val();
  MotCtrlPrmEstimnMagThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val();
  MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val();
  MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val();
  MotCtrlPrmEstimnMotBackEmfConNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val();
  MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val();
  MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val();
  MotCtrlPrmEstimnMotInduDaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val();
  MotCtrlPrmEstimnMotInduQaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val();
  MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduQaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val();
  MotCtrlPrmEstimnMotInduQaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val();
  MotCtrlPrmEstimnMotRHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val();
  MotCtrlPrmEstimnMotRLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val();
  MotCtrlPrmEstimnMotRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val();
  MotCtrlPrmEstimnMotWidgThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val();
  MotCtrlPrmEstimnTNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnTNom_Val();
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(), sizeof(Ary1D_u9p7_16));
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(), sizeof(Ary1D_u2p14_16));
  (void)memcpy(MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_6));
  (void)memcpy(MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(), sizeof(Ary1D_u9p7_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotBackEmfConEstimd_Val(Rte_InitValue_MotBackEmfConEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimd_Val(Rte_InitValue_MotInduDaxEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimd_Val(Rte_InitValue_MotInduQaxEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotREstimd_Val(Rte_InitValue_MotREstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_GetErrorStatus(&Call_MotPrmNom_GetErrorStatus_ErrorStatus_Arg);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_SetRamBlockStatus(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotCtrlPrmEstimnPer1
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
 *   Std_ReturnType Rte_Read_DualEcuFltMtgtnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotAndThermProtnLoaMod_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotCurrDaxCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrQaxCmd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotBackEmfConEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotInduDaxEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotInduDaxEstimdIvs_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotInduQaxEstimd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotInduQaxEstimdIvs_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_MotCtrlPrmEstimnPer1_MotBackEmfConFf(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCtrlPrmEstimnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotCtrlPrmEstimn_CODE) MotCtrlPrmEstimnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCtrlPrmEstimnPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_DualEcuFltMtgtnEna_Logl;
  uint8 Read_MotAndThermProtnLoaMod_Val;
  float32 Read_MotCurrDaxCmd_Val;
  float32 Read_MotCurrQaxCmd_Val;

  float32 PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  float32 PimdMotCtrlPrmEstimnFetRFfEstimd;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  float32 PimdMotCtrlPrmEstimnMotRFfEstimd;
  MotPrmNomEolRec3 PimMotPrmNom;

  float32 MotCtrlPrmEstimnFetRNom_Val_data;
  float32 MotCtrlPrmEstimnFetThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMagThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConNom_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotRHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotRLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotRNom_Val_data;
  float32 MotCtrlPrmEstimnMotWidgThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnTNom_Val_data;
  Ary1D_u9p7_16 MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data;
  Ary1D_u2p14_16 MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data;
  Ary1D_u9p7_6 MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data;
  Ary1D_u9p7_7 MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data;

  float32 MotCtrlPrmEstimnPer1_MotBackEmfConFf;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotCtrlPrmEstimnCtrlrREstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim() = PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  PimdMotCtrlPrmEstimnFetRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd() = PimdMotCtrlPrmEstimnFetRFfEstimd;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  PimdMotCtrlPrmEstimnMotRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd() = PimdMotCtrlPrmEstimnMotRFfEstimd;
  PimMotPrmNom = *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom() = PimMotPrmNom;

  MotCtrlPrmEstimnFetRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val();
  MotCtrlPrmEstimnFetThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val();
  MotCtrlPrmEstimnMagThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val();
  MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val();
  MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val();
  MotCtrlPrmEstimnMotBackEmfConNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val();
  MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val();
  MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val();
  MotCtrlPrmEstimnMotInduDaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val();
  MotCtrlPrmEstimnMotInduQaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val();
  MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduQaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val();
  MotCtrlPrmEstimnMotInduQaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val();
  MotCtrlPrmEstimnMotRHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val();
  MotCtrlPrmEstimnMotRLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val();
  MotCtrlPrmEstimnMotRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val();
  MotCtrlPrmEstimnMotWidgThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val();
  MotCtrlPrmEstimnTNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnTNom_Val();
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(), sizeof(Ary1D_u9p7_16));
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(), sizeof(Ary1D_u2p14_16));
  (void)memcpy(MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_6));
  (void)memcpy(MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(), sizeof(Ary1D_u9p7_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Read_DualEcuFltMtgtnEna_Logl(&Read_DualEcuFltMtgtnEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Read_MotAndThermProtnLoaMod_Val(&Read_MotAndThermProtnLoaMod_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Read_MotCurrDaxCmd_Val(&Read_MotCurrDaxCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Read_MotCurrQaxCmd_Val(&Read_MotCurrQaxCmd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotBackEmfConEstimd_Val(Rte_InitValue_MotBackEmfConEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimd_Val(Rte_InitValue_MotInduDaxEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotInduDaxEstimdIvs_Val(Rte_InitValue_MotInduDaxEstimdIvs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimd_Val(Rte_InitValue_MotInduQaxEstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotInduQaxEstimdIvs_Val(Rte_InitValue_MotInduQaxEstimdIvs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  MotCtrlPrmEstimnPer1_MotBackEmfConFf = TSC_MotCtrlPrmEstimn_Rte_IrvRead_MotCtrlPrmEstimnPer1_MotBackEmfConFf();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotCtrlPrmEstimnPer2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotFetT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotMagT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotWidgT_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotREstimd_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_MotCtrlPrmEstimnPer2_MotBackEmfConFf(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCtrlPrmEstimnPer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotCtrlPrmEstimn_CODE) MotCtrlPrmEstimnPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotCtrlPrmEstimnPer2
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_MotFetT_Val;
  float32 Read_MotMagT_Val;
  float32 Read_MotWidgT_Val;

  float32 PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  float32 PimdMotCtrlPrmEstimnFetRFfEstimd;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  float32 PimdMotCtrlPrmEstimnMotRFfEstimd;
  MotPrmNomEolRec3 PimMotPrmNom;

  float32 MotCtrlPrmEstimnFetRNom_Val_data;
  float32 MotCtrlPrmEstimnFetThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMagThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConNom_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotRHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotRLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotRNom_Val_data;
  float32 MotCtrlPrmEstimnMotWidgThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnTNom_Val_data;
  Ary1D_u9p7_16 MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data;
  Ary1D_u2p14_16 MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data;
  Ary1D_u9p7_6 MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data;
  Ary1D_u9p7_7 MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotCtrlPrmEstimnCtrlrREstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim() = PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  PimdMotCtrlPrmEstimnFetRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd() = PimdMotCtrlPrmEstimnFetRFfEstimd;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  PimdMotCtrlPrmEstimnMotRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd() = PimdMotCtrlPrmEstimnMotRFfEstimd;
  PimMotPrmNom = *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom() = PimMotPrmNom;

  MotCtrlPrmEstimnFetRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val();
  MotCtrlPrmEstimnFetThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val();
  MotCtrlPrmEstimnMagThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val();
  MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val();
  MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val();
  MotCtrlPrmEstimnMotBackEmfConNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val();
  MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val();
  MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val();
  MotCtrlPrmEstimnMotInduDaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val();
  MotCtrlPrmEstimnMotInduQaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val();
  MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduQaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val();
  MotCtrlPrmEstimnMotInduQaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val();
  MotCtrlPrmEstimnMotRHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val();
  MotCtrlPrmEstimnMotRLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val();
  MotCtrlPrmEstimnMotRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val();
  MotCtrlPrmEstimnMotWidgThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val();
  MotCtrlPrmEstimnTNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnTNom_Val();
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(), sizeof(Ary1D_u9p7_16));
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(), sizeof(Ary1D_u2p14_16));
  (void)memcpy(MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_6));
  (void)memcpy(MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(), sizeof(Ary1D_u9p7_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Read_MotFetT_Val(&Read_MotFetT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Read_MotMagT_Val(&Read_MotMagT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Read_MotWidgT_Val(&Read_MotWidgT_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Write_MotREstimd_Val(Rte_InitValue_MotREstimd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  TSC_MotCtrlPrmEstimn_Rte_IrvWrite_MotCtrlPrmEstimnPer2_MotBackEmfConFf(0.03993F);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetMotPrmNomEol_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetMotPrmNomEol>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotPrmNom_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetMotPrmNomEol_Oper(float32 MotBackEmfConNom_Arg, float32 MotRNom_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetMotPrmNomEol_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotCtrlPrmEstimn_CODE) SetMotPrmNomEol_Oper(float32 MotBackEmfConNom_Arg, float32 MotRNom_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetMotPrmNomEol_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  float32 PimdMotCtrlPrmEstimnFetRFfEstimd;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  float32 PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  float32 PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  float32 PimdMotCtrlPrmEstimnMotRFfEstimd;
  MotPrmNomEolRec3 PimMotPrmNom;

  float32 MotCtrlPrmEstimnFetRNom_Val_data;
  float32 MotCtrlPrmEstimnFetThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMagThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConNom_Val_data;
  float32 MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduDaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotInduQaxNom_Val_data;
  float32 MotCtrlPrmEstimnMotRHiLim_Val_data;
  float32 MotCtrlPrmEstimnMotRLoLim_Val_data;
  float32 MotCtrlPrmEstimnMotRNom_Val_data;
  float32 MotCtrlPrmEstimnMotWidgThermCoeff_Val_data;
  float32 MotCtrlPrmEstimnTNom_Val_data;
  Ary1D_u9p7_16 MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data;
  Ary1D_u2p14_16 MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data;
  Ary1D_u9p7_6 MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data;
  Ary1D_u9p7_7 MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data;
  Ary2D_u2p14_6_7 MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimdMotCtrlPrmEstimnCtrlrREstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnCtrlrREstimdPreLim() = PimdMotCtrlPrmEstimnCtrlrREstimdPreLim;
  PimdMotCtrlPrmEstimnFetRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnFetRFfEstimd() = PimdMotCtrlPrmEstimnFetRFfEstimd;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdPreLim;
  PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca() = PimdMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimDax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimDax;
  PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdPreLimQax() = PimdMotCtrlPrmEstimnMotInduEstimdPreLimQax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaDax;
  PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax() = PimdMotCtrlPrmEstimnMotInduEstimdSatnScaQax;
  PimdMotCtrlPrmEstimnMotRFfEstimd = *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_dMotCtrlPrmEstimnMotRFfEstimd() = PimdMotCtrlPrmEstimnMotRFfEstimd;
  PimMotPrmNom = *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom();
  *TSC_MotCtrlPrmEstimn_Rte_Pim_MotPrmNom() = PimMotPrmNom;

  MotCtrlPrmEstimnFetRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetRNom_Val();
  MotCtrlPrmEstimnFetThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnFetThermCoeff_Val();
  MotCtrlPrmEstimnMagThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMagThermCoeff_Val();
  MotCtrlPrmEstimnMotBackEmfConHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConHiLim_Val();
  MotCtrlPrmEstimnMotBackEmfConLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConLoLim_Val();
  MotCtrlPrmEstimnMotBackEmfConNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConNom_Val();
  MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnScaIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxHiLim_Val();
  MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduDaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxLoLim_Val();
  MotCtrlPrmEstimnMotInduDaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxNom_Val();
  MotCtrlPrmEstimnMotInduQaxHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxHiLim_Val();
  MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxIvtrLoaMtgtn_Val();
  MotCtrlPrmEstimnMotInduQaxLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxLoLim_Val();
  MotCtrlPrmEstimnMotInduQaxNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxNom_Val();
  MotCtrlPrmEstimnMotRHiLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRHiLim_Val();
  MotCtrlPrmEstimnMotRLoLim_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRLoLim_Val();
  MotCtrlPrmEstimnMotRNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotRNom_Val();
  MotCtrlPrmEstimnMotWidgThermCoeff_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotWidgThermCoeff_Val();
  MotCtrlPrmEstimnTNom_Val_data = TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnTNom_Val();
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnX_Ary1D(), sizeof(Ary1D_u9p7_16));
  (void)memcpy(MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotBackEmfConSatnY_Ary1D(), sizeof(Ary1D_u2p14_16));
  (void)memcpy(MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrDaxInduSatnBilnrSeln_Ary1D(), sizeof(Ary1D_u9p7_6));
  (void)memcpy(MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotCurrQaxInduSatnX_Ary1D(), sizeof(Ary1D_u9p7_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduDaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));
  (void)memcpy(MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D_data, TSC_MotCtrlPrmEstimn_Rte_Prm_MotCtrlPrmEstimnMotInduQaxSatnScaY_Ary2D(), sizeof(Ary2D_u2p14_6_7));

  fct_status = TSC_MotCtrlPrmEstimn_Rte_Call_MotPrmNom_SetRamBlockStatus(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MotCtrlPrmEstimn_STOP_SEC_CODE
#include "MotCtrlPrmEstimn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void MotCtrlPrmEstimn_TestDefines(void)
{
  /* Enumeration Data Types */

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
