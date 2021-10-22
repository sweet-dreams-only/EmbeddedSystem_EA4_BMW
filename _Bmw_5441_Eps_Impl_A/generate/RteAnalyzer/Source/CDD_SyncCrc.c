/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_SyncCrc.c
 *        Config:  EPS.dpa
 *     SW-C Type:  CDD_SyncCrc
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_SyncCrc>
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
 * CrcHwResvCfg1
 *   
 *
 * CrcHwResvMod1
 *   
 *
 * CrcHwSts1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CDD_SyncCrc.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CDD_SyncCrc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CDD_SyncCrc_TestDefines(void);


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
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * CrcHwResvCfg1: Enumeration of integer in interval [0...255] with enumerators
 *   CRCHWRESVCFG_32BITCRC32BITWIDTH (0U)
 *   CRCHWRESVCFG_32BITCRC16BITWIDTH (1U)
 *   CRCHWRESVCFG_32BITCRC8BITWIDTH (2U)
 *   CRCHWRESVCFG_16BITCRC16BITWIDTH (3U)
 *   CRCHWRESVCFG_16BITCRC8BITWIDTH (4U)
 *   CRCHWRESVCFG_8BITCRC (5U)
 *   CRCHWRESVCFG_8BITCRCH2F (6U)
 * CrcHwResvMod1: Enumeration of integer in interval [0...255] with enumerators
 *   CRCHWRESVMOD_RELS (0U)
 *   CRCHWRESVMOD_RESV (1U)
 * CrcHwSts1: Enumeration of integer in interval [0...255] with enumerators
 *   CRCHWSTS_NOTAVL (0U)
 *   CRCHWSTS_AVL (1U)
 *   CRCHWSTS_BUSY (2U)
 *   CRCHWSTS_NOTENAD (3U)
 *   CRCHWSTS_RESV (4U)
 *   CRCHWSTS_IDXINVLD (255U)
 *
 * Array Types:
 * ============
 * Ary1D_CrcHwStsRec2_8: Array with 8 element(s) of type CrcHwStsRec2
 *
 * Record Types:
 * =============
 * CrcHwStsRec2: Record with elements
 *   TaskId of type uint32
 *   CrcHwSts of type CrcHwSts1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   CrcHwStsRec2 *Rte_Pim_CrcHwSts(void)
 *     Returnvalue: CrcHwStsRec2* is of type Ary1D_CrcHwStsRec2_8
 *
 *********************************************************************************************************************/


#define CDD_SyncCrc_START_SEC_CODE
#include "CDD_SyncCrc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Calc16BitCrc_u08_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Calc16BitCrc_u08>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Calc16BitCrc_u08_Oper(uint8 *DataPtr_Arg, uint32 Len_Arg, uint16 StrtVal_Arg, boolean FirstCall_Arg, uint16 *CalcCrcRes_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Calc16BitCrc_u08_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc16BitCrc_u08_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) Calc16BitCrc_u08_Oper(P2VAR(uint8, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) DataPtr_Arg, uint32 Len_Arg, uint16 StrtVal_Arg, boolean FirstCall_Arg, P2VAR(uint16, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CalcCrcRes_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc16BitCrc_u08_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  CDD_SyncCrc_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Calc16BitCrc_u16_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Calc16BitCrc_u16>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Calc16BitCrc_u16_Oper(uint16 *DataPtr_Arg, uint32 Len_Arg, uint16 StrtVal_Arg, boolean FirstCall_Arg, uint16 *CalcCrcRes_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Calc16BitCrc_u16_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc16BitCrc_u16_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) Calc16BitCrc_u16_Oper(P2VAR(uint16, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) DataPtr_Arg, uint32 Len_Arg, uint16 StrtVal_Arg, boolean FirstCall_Arg, P2VAR(uint16, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CalcCrcRes_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc16BitCrc_u16_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Calc32BitCrc_u08_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Calc32BitCrc_u08>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Calc32BitCrc_u08_Oper(uint8 *DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, uint32 *CalcCrcRes_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Calc32BitCrc_u08_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc32BitCrc_u08_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) Calc32BitCrc_u08_Oper(P2VAR(uint8, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CalcCrcRes_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc32BitCrc_u08_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Calc32BitCrc_u16_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Calc32BitCrc_u16>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Calc32BitCrc_u16_Oper(uint16 *DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, uint32 *CalcCrcRes_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Calc32BitCrc_u16_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc32BitCrc_u16_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) Calc32BitCrc_u16_Oper(P2VAR(uint16, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CalcCrcRes_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc32BitCrc_u16_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Calc32BitCrc_u32_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Calc32BitCrc_u32>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Calc32BitCrc_u32_Oper(uint32 *DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, uint32 *CalcCrcRes_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Calc32BitCrc_u32_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc32BitCrc_u32_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) Calc32BitCrc_u32_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) DataPtr_Arg, uint32 Len_Arg, uint32 StrtVal_Arg, boolean FirstCall_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CalcCrcRes_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc32BitCrc_u32_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Calc8BitCrc0X2F_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Calc8BitCrc0X2F>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Calc8BitCrc0X2F_Oper(uint8 *DataPtr_Arg, uint32 Len_Arg, uint8 StrtVal_Arg, boolean FirstCall_Arg, uint8 *CalcCrcRes_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Calc8BitCrc_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc8BitCrc0X2F_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) Calc8BitCrc0X2F_Oper(P2VAR(uint8, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) DataPtr_Arg, uint32 Len_Arg, uint8 StrtVal_Arg, boolean FirstCall_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CalcCrcRes_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc8BitCrc0X2F_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Calc8BitCrc_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Calc8BitCrc>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Calc8BitCrc_Oper(uint8 *DataPtr_Arg, uint32 Len_Arg, uint8 StrtVal_Arg, boolean FirstCall_Arg, uint8 *CalcCrcRes_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Calc8BitCrc_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc8BitCrc_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) Calc8BitCrc_Oper(P2VAR(uint8, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) DataPtr_Arg, uint32 Len_Arg, uint8 StrtVal_Arg, boolean FirstCall_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CalcCrcRes_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Calc8BitCrc_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ResvCrcHwUnit_Oper
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ResvCrcHwUnit>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SyncCrcExclusiveArea(void)
 *   void Rte_Exit_SyncCrcExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ResvCrcHwUnit_Oper(CrcHwResvMod1 Mod_Arg, CrcHwResvCfg1 CrcCfg_Arg, uint32 *CrcHwInRegAdr_Arg, uint32 *CrcHwOutRegAdr_Arg, uint32 StrtVal_Arg, uint32 *ResvKey_Arg)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ResvCrcHwUnit_PortIf2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ResvCrcHwUnit_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_SyncCrc_CODE) ResvCrcHwUnit_Oper(CrcHwResvMod1 Mod_Arg, CrcHwResvCfg1 CrcCfg_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CrcHwInRegAdr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) CrcHwOutRegAdr_Arg, uint32 StrtVal_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_SYNCCRC_APPL_VAR) ResvKey_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ResvCrcHwUnit_Oper (returns application error)
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));


  TSC_CDD_SyncCrc_Rte_Enter_SyncCrcExclusiveArea();
  TSC_CDD_SyncCrc_Rte_Exit_SyncCrcExclusiveArea();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SyncCrcInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SyncCrcInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_SyncCrc_CODE) SyncCrcInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SyncCrcInit1
 *********************************************************************************************************************/

  Ary1D_CrcHwStsRec2_8 PimCrcHwSts;

  /*************************************************
  * Direct Function Accesses
  *************************************************/


  (void)memcpy(PimCrcHwSts, TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), sizeof(Ary1D_CrcHwStsRec2_8));
  (void)memcpy(TSC_CDD_SyncCrc_Rte_Pim_CrcHwSts(), PimCrcHwSts, sizeof(Ary1D_CrcHwStsRec2_8));



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_SyncCrc_STOP_SEC_CODE
#include "CDD_SyncCrc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CDD_SyncCrc_TestDefines(void)
{
  /* Enumeration Data Types */

  CrcHwResvCfg1 Test_CrcHwResvCfg1_V_1 = CRCHWRESVCFG_32BITCRC32BITWIDTH;
  CrcHwResvCfg1 Test_CrcHwResvCfg1_V_2 = CRCHWRESVCFG_32BITCRC16BITWIDTH;
  CrcHwResvCfg1 Test_CrcHwResvCfg1_V_3 = CRCHWRESVCFG_32BITCRC8BITWIDTH;
  CrcHwResvCfg1 Test_CrcHwResvCfg1_V_4 = CRCHWRESVCFG_16BITCRC16BITWIDTH;
  CrcHwResvCfg1 Test_CrcHwResvCfg1_V_5 = CRCHWRESVCFG_16BITCRC8BITWIDTH;
  CrcHwResvCfg1 Test_CrcHwResvCfg1_V_6 = CRCHWRESVCFG_8BITCRC;
  CrcHwResvCfg1 Test_CrcHwResvCfg1_V_7 = CRCHWRESVCFG_8BITCRCH2F;

  CrcHwResvMod1 Test_CrcHwResvMod1_V_1 = CRCHWRESVMOD_RELS;
  CrcHwResvMod1 Test_CrcHwResvMod1_V_2 = CRCHWRESVMOD_RESV;

  CrcHwSts1 Test_CrcHwSts1_V_1 = CRCHWSTS_NOTAVL;
  CrcHwSts1 Test_CrcHwSts1_V_2 = CRCHWSTS_AVL;
  CrcHwSts1 Test_CrcHwSts1_V_3 = CRCHWSTS_BUSY;
  CrcHwSts1 Test_CrcHwSts1_V_4 = CRCHWSTS_NOTENAD;
  CrcHwSts1 Test_CrcHwSts1_V_5 = CRCHWSTS_RESV;
  CrcHwSts1 Test_CrcHwSts1_V_6 = CRCHWSTS_IDXINVLD;
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
