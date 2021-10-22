/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  NxtrCalIds.c
 *        Config:  EPS.dpa
 *     SW-C Type:  NxtrCalIds
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <NxtrCalIds>
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

#include "Rte_NxtrCalIds.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_NxtrCalIds.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


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
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_u08_48: Array with 48 element(s) of type uint8
 * Ary1D_u08_6: Array with 6 element(s) of type uint8
 * Ary1D_u8_48: Array with 48 element(s) of type uint8
 * Ary1D_u8_6: Array with 6 element(s) of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint32 Rte_Prm_NxtrCalIdsCal0DevlpRelNr_Val(void)
 *   uint32 Rte_Prm_NxtrCalIdsCal0DevlpTiStamp_Val(void)
 *   uint32 Rte_Prm_NxtrCalIdsCal1DevlpRelNr_Val(void)
 *   uint32 Rte_Prm_NxtrCalIdsCal1DevlpTiStamp_Val(void)
 *   uint32 Rte_Prm_NxtrCalIdsCal2DevlpRelNr_Val(void)
 *   uint32 Rte_Prm_NxtrCalIdsCal2DevlpTiStamp_Val(void)
 *   uint8 Rte_Prm_NxtrCalIdsCal0DevlpRelSt_Val(void)
 *   uint8 Rte_Prm_NxtrCalIdsCal0DevlpVers_Val(void)
 *   uint8 Rte_Prm_NxtrCalIdsCal1DevlpRelSt_Val(void)
 *   uint8 Rte_Prm_NxtrCalIdsCal1DevlpVers_Val(void)
 *   uint8 Rte_Prm_NxtrCalIdsCal2DevlpRelSt_Val(void)
 *   uint8 Rte_Prm_NxtrCalIdsCal2DevlpVers_Val(void)
 *   uint8 *Rte_Prm_NxtrCalIdsCal0DevlpAuthor_Ary1D(void)
 *     Returnvalue: uint8* is of type Ary1D_u8_6
 *   uint8 *Rte_Prm_NxtrCalIdsCal0DevlpDescr_Ary1D(void)
 *     Returnvalue: uint8* is of type Ary1D_u8_48
 *   uint8 *Rte_Prm_NxtrCalIdsCal1DevlpAuthor_Ary1D(void)
 *     Returnvalue: uint8* is of type Ary1D_u8_6
 *   uint8 *Rte_Prm_NxtrCalIdsCal1DevlpDescr_Ary1D(void)
 *     Returnvalue: uint8* is of type Ary1D_u8_48
 *   uint8 *Rte_Prm_NxtrCalIdsCal2DevlpAuthor_Ary1D(void)
 *     Returnvalue: uint8* is of type Ary1D_u8_6
 *   uint8 *Rte_Prm_NxtrCalIdsCal2DevlpDescr_Ary1D(void)
 *     Returnvalue: uint8* is of type Ary1D_u8_48
 *
 *********************************************************************************************************************/


#define NxtrCalIds_START_SEC_CODE
#include "NxtrCalIds_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrCalIdsCalDevlpRd_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <NxtrCalIdsCalDevlpRd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NxtrCalIdsCalDevlpRd_Oper(uint8 CalRegn, uint8 *CalAuthor, uint8 *CalVers, uint32 *CalTiStamp, uint8 *CalDescr)
 *     Argument CalAuthor: uint8* is of type Ary1D_u8_6
 *     Argument CalDescr: uint8* is of type Ary1D_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NxtrCalIdsCalDevlpRd_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NxtrCalIdsCalDevlpRd_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, NxtrCalIds_CODE) NxtrCalIdsCalDevlpRd_Oper(uint8 CalRegn, P2VAR(uint8, AUTOMATIC, RTE_NXTRCALIDS_APPL_VAR) CalAuthor, P2VAR(uint8, AUTOMATIC, RTE_NXTRCALIDS_APPL_VAR) CalVers, P2VAR(uint32, AUTOMATIC, RTE_NXTRCALIDS_APPL_VAR) CalTiStamp, P2VAR(uint8, AUTOMATIC, RTE_NXTRCALIDS_APPL_VAR) CalDescr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NxtrCalIdsCalDevlpRd_Oper (returns application error)
 *********************************************************************************************************************/

  uint32 NxtrCalIdsCal0DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal0DevlpTiStamp_Val_data;
  uint32 NxtrCalIdsCal1DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal1DevlpTiStamp_Val_data;
  uint32 NxtrCalIdsCal2DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal2DevlpTiStamp_Val_data;
  uint8 NxtrCalIdsCal0DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal0DevlpVers_Val_data;
  uint8 NxtrCalIdsCal1DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal1DevlpVers_Val_data;
  uint8 NxtrCalIdsCal2DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal2DevlpVers_Val_data;
  Ary1D_u8_6 NxtrCalIdsCal0DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal0DevlpDescr_Ary1D_data;
  Ary1D_u8_6 NxtrCalIdsCal1DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal1DevlpDescr_Ary1D_data;
  Ary1D_u8_6 NxtrCalIdsCal2DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal2DevlpDescr_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  NxtrCalIdsCal0DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpRelNr_Val();
  NxtrCalIdsCal0DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpTiStamp_Val();
  NxtrCalIdsCal1DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpRelNr_Val();
  NxtrCalIdsCal1DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpTiStamp_Val();
  NxtrCalIdsCal2DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpRelNr_Val();
  NxtrCalIdsCal2DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpTiStamp_Val();
  NxtrCalIdsCal0DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpRelSt_Val();
  NxtrCalIdsCal0DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpVers_Val();
  NxtrCalIdsCal1DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpRelSt_Val();
  NxtrCalIdsCal1DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpVers_Val();
  NxtrCalIdsCal2DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpRelSt_Val();
  NxtrCalIdsCal2DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpVers_Val();
  (void)memcpy(NxtrCalIdsCal0DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal0DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));
  (void)memcpy(NxtrCalIdsCal1DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal1DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));
  (void)memcpy(NxtrCalIdsCal2DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal2DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrCalIdsCalRelRd_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <NxtrCalIdsCalRelRd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NxtrCalIdsCalRelRd_Oper(uint8 CalRegn, uint32 *RelNr, uint8 *RelSt)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NxtrCalIdsCalRelRd_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, NxtrCalIds_CODE) NxtrCalIdsCalRelRd_Oper(uint8 CalRegn, P2VAR(uint32, AUTOMATIC, RTE_NXTRCALIDS_APPL_VAR) RelNr, P2VAR(uint8, AUTOMATIC, RTE_NXTRCALIDS_APPL_VAR) RelSt) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NxtrCalIdsCalRelRd_Oper
 *********************************************************************************************************************/

  uint32 NxtrCalIdsCal0DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal0DevlpTiStamp_Val_data;
  uint32 NxtrCalIdsCal1DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal1DevlpTiStamp_Val_data;
  uint32 NxtrCalIdsCal2DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal2DevlpTiStamp_Val_data;
  uint8 NxtrCalIdsCal0DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal0DevlpVers_Val_data;
  uint8 NxtrCalIdsCal1DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal1DevlpVers_Val_data;
  uint8 NxtrCalIdsCal2DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal2DevlpVers_Val_data;
  Ary1D_u8_6 NxtrCalIdsCal0DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal0DevlpDescr_Ary1D_data;
  Ary1D_u8_6 NxtrCalIdsCal1DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal1DevlpDescr_Ary1D_data;
  Ary1D_u8_6 NxtrCalIdsCal2DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal2DevlpDescr_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  NxtrCalIdsCal0DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpRelNr_Val();
  NxtrCalIdsCal0DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpTiStamp_Val();
  NxtrCalIdsCal1DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpRelNr_Val();
  NxtrCalIdsCal1DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpTiStamp_Val();
  NxtrCalIdsCal2DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpRelNr_Val();
  NxtrCalIdsCal2DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpTiStamp_Val();
  NxtrCalIdsCal0DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpRelSt_Val();
  NxtrCalIdsCal0DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpVers_Val();
  NxtrCalIdsCal1DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpRelSt_Val();
  NxtrCalIdsCal1DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpVers_Val();
  NxtrCalIdsCal2DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpRelSt_Val();
  NxtrCalIdsCal2DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpVers_Val();
  (void)memcpy(NxtrCalIdsCal0DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal0DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));
  (void)memcpy(NxtrCalIdsCal1DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal1DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));
  (void)memcpy(NxtrCalIdsCal2DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal2DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NxtrCalIdsInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NxtrCalIdsInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, NxtrCalIds_CODE) NxtrCalIdsInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NxtrCalIdsInit1
 *********************************************************************************************************************/

  uint32 NxtrCalIdsCal0DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal0DevlpTiStamp_Val_data;
  uint32 NxtrCalIdsCal1DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal1DevlpTiStamp_Val_data;
  uint32 NxtrCalIdsCal2DevlpRelNr_Val_data;
  uint32 NxtrCalIdsCal2DevlpTiStamp_Val_data;
  uint8 NxtrCalIdsCal0DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal0DevlpVers_Val_data;
  uint8 NxtrCalIdsCal1DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal1DevlpVers_Val_data;
  uint8 NxtrCalIdsCal2DevlpRelSt_Val_data;
  uint8 NxtrCalIdsCal2DevlpVers_Val_data;
  Ary1D_u8_6 NxtrCalIdsCal0DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal0DevlpDescr_Ary1D_data;
  Ary1D_u8_6 NxtrCalIdsCal1DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal1DevlpDescr_Ary1D_data;
  Ary1D_u8_6 NxtrCalIdsCal2DevlpAuthor_Ary1D_data;
  Ary1D_u8_48 NxtrCalIdsCal2DevlpDescr_Ary1D_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  NxtrCalIdsCal0DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpRelNr_Val();
  NxtrCalIdsCal0DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpTiStamp_Val();
  NxtrCalIdsCal1DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpRelNr_Val();
  NxtrCalIdsCal1DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpTiStamp_Val();
  NxtrCalIdsCal2DevlpRelNr_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpRelNr_Val();
  NxtrCalIdsCal2DevlpTiStamp_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpTiStamp_Val();
  NxtrCalIdsCal0DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpRelSt_Val();
  NxtrCalIdsCal0DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpVers_Val();
  NxtrCalIdsCal1DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpRelSt_Val();
  NxtrCalIdsCal1DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpVers_Val();
  NxtrCalIdsCal2DevlpRelSt_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpRelSt_Val();
  NxtrCalIdsCal2DevlpVers_Val_data = TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpVers_Val();
  (void)memcpy(NxtrCalIdsCal0DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal0DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal0DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));
  (void)memcpy(NxtrCalIdsCal1DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal1DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal1DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));
  (void)memcpy(NxtrCalIdsCal2DevlpAuthor_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpAuthor_Ary1D(), sizeof(Ary1D_u8_6));
  (void)memcpy(NxtrCalIdsCal2DevlpDescr_Ary1D_data, TSC_NxtrCalIds_Rte_Prm_NxtrCalIdsCal2DevlpDescr_Ary1D(), sizeof(Ary1D_u8_48));


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define NxtrCalIds_STOP_SEC_CODE
#include "NxtrCalIds_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
