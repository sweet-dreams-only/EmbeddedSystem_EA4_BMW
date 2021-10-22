/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_XcpIf.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_XcpIf
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_XcpIf>
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
 * AdrMpgReqTyp1
 *   
 *
 * CalCopySts1
 *   
 *
 * GetSegMod1
 *   
 *
 * MfgEnaSt1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CDD_XcpIf.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_XcpIf.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CDD_XcpIf_TestDefines(void);


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
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AdrMpgReqTyp1: Enumeration of integer in interval [0...255] with enumerators
 *   ADRMPGREQTYP_READ (0U)
 *   ADRMPGREQTYP_WR (1U)
 * CalCopySts1: Enumeration of integer in interval [0...255] with enumerators
 *   CALCOPYSTS_NOTRDY (0U)
 *   CALCOPYSTS_COPYPNDING (1U)
 *   CALCOPYSTS_COPYCMPL (2U)
 *   CALCOPYSTS_PROCERR (3U)
 * GetSegMod1: Enumeration of integer in interval [0...255] with enumerators
 *   GETSEGMOD_ADRINFO (0U)
 *   GETSEGMOD_STDINFO (1U)
 *   GETSEGMOD_ADRMPG (2U)
 * MfgEnaSt1: Enumeration of integer in interval [0...255] with enumerators
 *   MFGENAST_PRDNMOD (0U)
 *   MFGENAST_MFGMOD (1U)
 *   MFGENAST_TESTMOD (2U)
 *
 *********************************************************************************************************************/


#define CDD_XcpIf_START_SEC_CODE
#include "CDD_XcpIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ActvTunStsReq_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ActvTunStsReq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ActvGroup_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_ActvIninIdx_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_ActvIninOptSetAIdx_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_ActvRtIdx_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_CalCopySts_Val(CalCopySts1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_XcpCalChgReq_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_XcpCalChgReq_PortIf1_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ActvTunStsReq_Oper(uint8 *ActvRtIdx_Arg, uint8 *ActvIninIdx_Arg, uint8 *ActvIninOptSetAIdx_Arg, uint8 *CalChgAllwd_Arg, uint8 *ActvGroup_Arg, uint8 *CalCopyCmpl_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ActvTunStsReq_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_XcpIf_CODE) ActvTunStsReq_Oper(P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvRtIdx_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvIninIdx_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvIninOptSetAIdx_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) CalChgAllwd_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) ActvGroup_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_XCPIF_APPL_VAR) CalCopyCmpl_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ActvTunStsReq_Oper
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint8 Read_ActvGroup_Val;
  uint8 Read_ActvIninIdx_Val;
  uint8 Read_ActvIninOptSetAIdx_Val;
  uint8 Read_ActvRtIdx_Val;
  CalCopySts1 Read_CalCopySts_Val;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDD_XcpIf_Rte_Read_ActvGroup_Val(&Read_ActvGroup_Val);
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

  fct_status = TSC_CDD_XcpIf_Rte_Read_ActvIninIdx_Val(&Read_ActvIninIdx_Val);
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

  fct_status = TSC_CDD_XcpIf_Rte_Read_ActvIninOptSetAIdx_Val(&Read_ActvIninOptSetAIdx_Val);
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

  fct_status = TSC_CDD_XcpIf_Rte_Read_ActvRtIdx_Val(&Read_ActvRtIdx_Val);
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

  fct_status = TSC_CDD_XcpIf_Rte_Read_CalCopySts_Val(&Read_CalCopySts_Val);
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

  fct_status = TSC_CDD_XcpIf_Rte_Call_XcpCalChgReq_Oper();
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
    case RTE_E_XcpCalChgReq_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  CDD_XcpIf_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDD_XcpIfInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CustXcpEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CopyCalPageReq_Oper(uint8 Seg_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CopyCalPageReq_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_GetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 *Page_Arg, uint8 *Rtn_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetSegInfoReq_Oper(GetSegMod1 Mod_Arg, uint8 Seg_Arg, uint8 SegInfo_Arg, uint8 MpgIdx_Arg, uint8 *Resp_Arg, uint8 *RespLen_Arg, uint8 *Rtn_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_OnlineTunRamAdrMpg_Oper(uint32 ReqAdr_Arg, uint32 *CorrdAdr_Arg, AdrMpgReqTyp1 ReqTyp_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OnlineTunRamAdrMpg_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetCalPageReq_Oper(uint8 Seg_Arg, uint8 Mod_Arg, uint8 Page_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_XcpCalChgReq_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_XcpCalChgReq_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_XcpIf_CODE) CDD_XcpIfInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfInit1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_CustXcpEna_Logl;
  MfgEnaSt1 Read_MfgEnaSt_Val;

  uint8 Call_GetCalPageReq_Oper_Page_Arg = 0U;
  uint8 Call_GetCalPageReq_Oper_Rtn_Arg = 0U;
  uint32 Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint8 Call_GetSegInfoReq_Oper_Resp_Arg = 0U;
  uint8 Call_GetSegInfoReq_Oper_RespLen_Arg = 0U;
  uint8 Call_GetSegInfoReq_Oper_Rtn_Arg = 0U;
  uint32 Call_OnlineTunRamAdrMpg_Oper_CorrdAdr_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDD_XcpIf_Rte_Read_CustXcpEna_Logl(&Read_CustXcpEna_Logl);
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

  fct_status = TSC_CDD_XcpIf_Rte_Read_MfgEnaSt_Val(&Read_MfgEnaSt_Val);
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

  fct_status = TSC_CDD_XcpIf_Rte_Call_CopyCalPageReq_Oper(0U);
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
    case RTE_E_CopyCalPageReq_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_XcpIf_Rte_Call_GetCalPageReq_Oper(0U, 0U, &Call_GetCalPageReq_Oper_Page_Arg, &Call_GetCalPageReq_Oper_Rtn_Arg);
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

  fct_status = TSC_CDD_XcpIf_Rte_Call_GetRefTmr1MicroSec32bit_Oper(&Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_CDD_XcpIf_Rte_Call_GetSegInfoReq_Oper(0U, 0U, 0U, 0U, &Call_GetSegInfoReq_Oper_Resp_Arg, &Call_GetSegInfoReq_Oper_RespLen_Arg, &Call_GetSegInfoReq_Oper_Rtn_Arg);
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

  fct_status = TSC_CDD_XcpIf_Rte_Call_OnlineTunRamAdrMpg_Oper(0U, &Call_OnlineTunRamAdrMpg_Oper_CorrdAdr_Arg, 0U);
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
    case RTE_E_OnlineTunRamAdrMpg_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CDD_XcpIf_Rte_Call_SetCalPageReq_Oper(0U, 0U, 0U);
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

  fct_status = TSC_CDD_XcpIf_Rte_Call_XcpCalChgReq_Oper();
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
    case RTE_E_XcpCalChgReq_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDD_XcpIfPer1
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
 *   Std_ReturnType Rte_Read_CustXcpEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MfgEnaSt_Val(MfgEnaSt1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_XcpIf_CODE) CDD_XcpIfPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDD_XcpIfPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_CustXcpEna_Logl;
  MfgEnaSt1 Read_MfgEnaSt_Val;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CDD_XcpIf_Rte_Read_CustXcpEna_Logl(&Read_CustXcpEna_Logl);
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

  fct_status = TSC_CDD_XcpIf_Rte_Read_MfgEnaSt_Val(&Read_MfgEnaSt_Val);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_XcpIf_STOP_SEC_CODE
#include "CDD_XcpIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CDD_XcpIf_TestDefines(void)
{
  /* Enumeration Data Types */

  AdrMpgReqTyp1 Test_AdrMpgReqTyp1_V_1 = ADRMPGREQTYP_READ;
  AdrMpgReqTyp1 Test_AdrMpgReqTyp1_V_2 = ADRMPGREQTYP_WR;

  CalCopySts1 Test_CalCopySts1_V_1 = CALCOPYSTS_NOTRDY;
  CalCopySts1 Test_CalCopySts1_V_2 = CALCOPYSTS_COPYPNDING;
  CalCopySts1 Test_CalCopySts1_V_3 = CALCOPYSTS_COPYCMPL;
  CalCopySts1 Test_CalCopySts1_V_4 = CALCOPYSTS_PROCERR;

  GetSegMod1 Test_GetSegMod1_V_1 = GETSEGMOD_ADRINFO;
  GetSegMod1 Test_GetSegMod1_V_2 = GETSEGMOD_STDINFO;
  GetSegMod1 Test_GetSegMod1_V_3 = GETSEGMOD_ADRMPG;

  MfgEnaSt1 Test_MfgEnaSt1_V_1 = MFGENAST_PRDNMOD;
  MfgEnaSt1 Test_MfgEnaSt1_V_2 = MFGENAST_MFGMOD;
  MfgEnaSt1 Test_MfgEnaSt1_V_3 = MFGENAST_TESTMOD;
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
