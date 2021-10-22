/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwVehSpd.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwVehSpd
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwVehSpd>
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
 * BmwCogVehSpdQlfr1
 *   
 *
 * BmwNearStillVehSpdSts1
 *   
 *
 * BmwPinionAgQlfr1
 *   
 *
 * BmwSecurVehSpdSts1
 *   
 *
 * u16p0
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwVehSpd.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwVehSpd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwVehSpd_TestDefines(void);


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
 * u16p0: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwCogVehSpdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWCOGVEHSPDQLFR_SIGVALVLDANDPLAUS (1U)
 *   BMWCOGVEHSPDQLFR_INIT (8U)
 *   BMWCOGVEHSPDQLFR_SIGVALTMPVLD (10U)
 *   BMWCOGVEHSPDQLFR_SIGQLYMONTMPRSTRCTD (11U)
 *   BMWCOGVEHSPDQLFR_SIGVALTMPINVLD (14U)
 *   BMWCOGVEHSPDQLFR_INVLD (15U)
 * BmwNearStillVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWNEARSTILLVEHSPDSTS_VEHREST (12U)
 *   BMWNEARSTILLVEHSPDSTS_VEHNOTREST (13U)
 *   BMWNEARSTILLVEHSPDSTS_INVLD (15U)
 * BmwPinionAgQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWPINIONAGQLFR_SIGVALVLDANDPLAUS (1U)
 *   BMWPINIONAGQLFR_SIGVALVLD (2U)
 *   BMWPINIONAGQLFR_SUBVALSETINUSRSIG (4U)
 *   BMWPINIONAGQLFR_INIT (8U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY (9U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY (10U)
 *   BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG (12U)
 *   BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP (14U)
 *   BMWPINIONAGQLFR_INVLDSIG (15U)
 * BmwSecurVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWSECURVEHSPDSTS_SIGVALVLD (1U)
 *   BMWSECURVEHSPDSTS_VEHSTANDG (4U)
 *   BMWSECURVEHSPDSTS_VEHRUNNG (12U)
 *   BMWSECURVEHSPDSTS_NOINFO (14U)
 *   BMWSECURVEHSPDSTS_INVLD (15U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_VehSpdLimPrev(void)
 *   uint32 *Rte_Pim_BmwSecurVehSpdStsSigValVldDurn(void)
 *   boolean *Rte_Pim_SpdDifChkFlg(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val(void)
 *   float32 Rte_Prm_BmwVehSpdRunngSubVehSpd_Val(void)
 *   float32 Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val(void)
 *   float32 Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val(void)
 *   u16p0 Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val(void)
 *
 *********************************************************************************************************************/


#define BmwVehSpd_START_SEC_CODE
#include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwVehSpdInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwVehSpd_CODE) BmwVehSpdInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdInit1
 *********************************************************************************************************************/

  float32 PimVehSpdLimPrev;
  uint32 PimBmwSecurVehSpdStsSigValVldDurn;
  boolean PimSpdDifChkFlg;

  float32 BmwVehSpdNearStillSubVehSpd_Val_data;
  float32 BmwVehSpdRunngSubVehSpd_Val_data;
  float32 BmwVehSpdSecurVehSpdInvldRateLim_Val_data;
  float32 BmwVehSpdSecurVehSpdVldRateLim_Val_data;
  u16p0 BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimVehSpdLimPrev = *TSC_BmwVehSpd_Rte_Pim_VehSpdLimPrev();
  *TSC_BmwVehSpd_Rte_Pim_VehSpdLimPrev() = PimVehSpdLimPrev;
  PimBmwSecurVehSpdStsSigValVldDurn = *TSC_BmwVehSpd_Rte_Pim_BmwSecurVehSpdStsSigValVldDurn();
  *TSC_BmwVehSpd_Rte_Pim_BmwSecurVehSpdStsSigValVldDurn() = PimBmwSecurVehSpdStsSigValVldDurn;
  PimSpdDifChkFlg = *TSC_BmwVehSpd_Rte_Pim_SpdDifChkFlg();
  *TSC_BmwVehSpd_Rte_Pim_SpdDifChkFlg() = PimSpdDifChkFlg;

  BmwVehSpdNearStillSubVehSpd_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val();
  BmwVehSpdRunngSubVehSpd_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdRunngSubVehSpd_Val();
  BmwVehSpdSecurVehSpdInvldRateLim_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val();
  BmwVehSpdSecurVehSpdVldRateLim_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val();
  BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val();

  BmwVehSpd_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwVehSpdPer1
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
 *   Std_ReturnType Rte_Read_BmwCogVehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdQlfrVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwCogVehSpdVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_BmwNearStillVehSpdStsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwSecurVehSpdSts_Val(BmwSecurVehSpdSts1 data)
 *   Std_ReturnType Rte_Write_VehSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_VehSpdVld_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwVehSpd_CODE) BmwVehSpdPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwVehSpdPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BmwCogVehSpd_Val;
  BmwCogVehSpdQlfr1 Read_BmwCogVehSpdQlfr_Val;
  boolean Read_BmwCogVehSpdQlfrVld_Logl;
  boolean Read_BmwCogVehSpdVld_Logl;
  BmwNearStillVehSpdSts1 Read_BmwNearStillVehSpdSts_Val;
  boolean Read_BmwNearStillVehSpdStsVld_Logl;
  BmwPinionAgQlfr1 Read_BmwPinionAgQlfr_Val;

  float32 PimVehSpdLimPrev;
  uint32 PimBmwSecurVehSpdStsSigValVldDurn;
  boolean PimSpdDifChkFlg;

  float32 BmwVehSpdNearStillSubVehSpd_Val_data;
  float32 BmwVehSpdRunngSubVehSpd_Val_data;
  float32 BmwVehSpdSecurVehSpdInvldRateLim_Val_data;
  float32 BmwVehSpdSecurVehSpdVldRateLim_Val_data;
  u16p0 BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val_data;

  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimVehSpdLimPrev = *TSC_BmwVehSpd_Rte_Pim_VehSpdLimPrev();
  *TSC_BmwVehSpd_Rte_Pim_VehSpdLimPrev() = PimVehSpdLimPrev;
  PimBmwSecurVehSpdStsSigValVldDurn = *TSC_BmwVehSpd_Rte_Pim_BmwSecurVehSpdStsSigValVldDurn();
  *TSC_BmwVehSpd_Rte_Pim_BmwSecurVehSpdStsSigValVldDurn() = PimBmwSecurVehSpdStsSigValVldDurn;
  PimSpdDifChkFlg = *TSC_BmwVehSpd_Rte_Pim_SpdDifChkFlg();
  *TSC_BmwVehSpd_Rte_Pim_SpdDifChkFlg() = PimSpdDifChkFlg;

  BmwVehSpdNearStillSubVehSpd_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val();
  BmwVehSpdRunngSubVehSpd_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdRunngSubVehSpd_Val();
  BmwVehSpdSecurVehSpdInvldRateLim_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val();
  BmwVehSpdSecurVehSpdVldRateLim_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val();
  BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val_data = TSC_BmwVehSpd_Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val();

  fct_status = TSC_BmwVehSpd_Rte_Read_BmwCogVehSpd_Val(&Read_BmwCogVehSpd_Val);
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

  fct_status = TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdQlfr_Val(&Read_BmwCogVehSpdQlfr_Val);
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

  fct_status = TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdQlfrVld_Logl(&Read_BmwCogVehSpdQlfrVld_Logl);
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

  fct_status = TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdVld_Logl(&Read_BmwCogVehSpdVld_Logl);
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

  fct_status = TSC_BmwVehSpd_Rte_Read_BmwNearStillVehSpdSts_Val(&Read_BmwNearStillVehSpdSts_Val);
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

  fct_status = TSC_BmwVehSpd_Rte_Read_BmwNearStillVehSpdStsVld_Logl(&Read_BmwNearStillVehSpdStsVld_Logl);
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

  fct_status = TSC_BmwVehSpd_Rte_Read_BmwPinionAgQlfr_Val(&Read_BmwPinionAgQlfr_Val);
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

  fct_status = TSC_BmwVehSpd_Rte_Write_BmwSecurVehSpdSts_Val(Rte_InitValue_BmwSecurVehSpdSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwVehSpd_Rte_Write_VehSpd_Val(Rte_InitValue_VehSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwVehSpd_Rte_Write_VehSpdVld_Logl(Rte_InitValue_VehSpdVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwVehSpd_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
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
  }

  fct_status = TSC_BmwVehSpd_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
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
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwVehSpd_STOP_SEC_CODE
#include "BmwVehSpd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwVehSpd_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwCogVehSpdQlfr1 Test_BmwCogVehSpdQlfr1_V_1 = BMWCOGVEHSPDQLFR_SIGVALVLDANDPLAUS;
  BmwCogVehSpdQlfr1 Test_BmwCogVehSpdQlfr1_V_2 = BMWCOGVEHSPDQLFR_INIT;
  BmwCogVehSpdQlfr1 Test_BmwCogVehSpdQlfr1_V_3 = BMWCOGVEHSPDQLFR_SIGVALTMPVLD;
  BmwCogVehSpdQlfr1 Test_BmwCogVehSpdQlfr1_V_4 = BMWCOGVEHSPDQLFR_SIGQLYMONTMPRSTRCTD;
  BmwCogVehSpdQlfr1 Test_BmwCogVehSpdQlfr1_V_5 = BMWCOGVEHSPDQLFR_SIGVALTMPINVLD;
  BmwCogVehSpdQlfr1 Test_BmwCogVehSpdQlfr1_V_6 = BMWCOGVEHSPDQLFR_INVLD;

  BmwNearStillVehSpdSts1 Test_BmwNearStillVehSpdSts1_V_1 = BMWNEARSTILLVEHSPDSTS_VEHREST;
  BmwNearStillVehSpdSts1 Test_BmwNearStillVehSpdSts1_V_2 = BMWNEARSTILLVEHSPDSTS_VEHNOTREST;
  BmwNearStillVehSpdSts1 Test_BmwNearStillVehSpdSts1_V_3 = BMWNEARSTILLVEHSPDSTS_INVLD;

  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_1 = BMWPINIONAGQLFR_SIGVALVLDANDPLAUS;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_2 = BMWPINIONAGQLFR_SIGVALVLD;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_3 = BMWPINIONAGQLFR_SUBVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_4 = BMWPINIONAGQLFR_INIT;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_5 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_6 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_7 = BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_8 = BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_9 = BMWPINIONAGQLFR_INVLDSIG;

  BmwSecurVehSpdSts1 Test_BmwSecurVehSpdSts1_V_1 = BMWSECURVEHSPDSTS_SIGVALVLD;
  BmwSecurVehSpdSts1 Test_BmwSecurVehSpdSts1_V_2 = BMWSECURVEHSPDSTS_VEHSTANDG;
  BmwSecurVehSpdSts1 Test_BmwSecurVehSpdSts1_V_3 = BMWSECURVEHSPDSTS_VEHRUNNG;
  BmwSecurVehSpdSts1 Test_BmwSecurVehSpdSts1_V_4 = BMWSECURVEHSPDSTS_NOINFO;
  BmwSecurVehSpdSts1 Test_BmwSecurVehSpdSts1_V_5 = BMWSECURVEHSPDSTS_INVLD;
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
