/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SysTime.c
 *        Config:  EPS.dpa
 *     SW-C Type:  SysTime
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <SysTime>
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
 * SysTime_LifeCycleRequestType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_SysTime.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_SysTime.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void SysTime_TestDefines(void);


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
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * SysTime_LifeCycleRequestType: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTIME_INITIALIZED (0U)
 *   SYSTIME_RUNNING (1U)
 *   SYSTIME_STOPPED (2U)
 *
 * Array Types:
 * ============
 * Array4: Array with 4 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define SysTime_START_SEC_CODE
#include "SysTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LifeCycleHandler
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <requestMode> of PortPrototype <LifeCycleRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SysTime_LifeCycleRequestType Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode(void)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_LifeCycle_Mode(SysTime_LifeCycleRequestType mode)
 *   Modes of Rte_ModeType_SysTime_LifeCycle:
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED
 *   - RTE_TRANSITION_SysTime_LifeCycle
 *   SysTime_LifeCycleRequestType Rte_Mode_LifeCycle_Mode(SysTime_LifeCycleRequestType *previousMode, SysTime_LifeCycleRequestType *nextMode)
 *   Modes of Rte_ModeType_SysTime_LifeCycle:
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING
 *   - RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED
 *   - RTE_TRANSITION_SysTime_LifeCycle
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LifeCycleHandler_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SysTime_CODE) SysTime_LifeCycleHandler(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SysTime_LifeCycleHandler
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SysTime_LifeCycleRequestType IRead_LifeCycleRequest_requestMode;

  Rte_ModeType_SysTime_LifeCycle LifeCycle_Mode;
  Rte_ModeType_SysTime_LifeCycle LifeCycle_Mode_previousMode;
  Rte_ModeType_SysTime_LifeCycle LifeCycle_Mode_nextMode;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IRead_LifeCycleRequest_requestMode = TSC_SysTime_Rte_IRead_LifeCycleHandler_LifeCycleRequest_requestMode();

  fct_status = TSC_SysTime_Rte_Switch_LifeCycle_Mode(RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  LifeCycle_Mode = TSC_SysTime_Rte_Mode_LifeCycle_Mode(&LifeCycle_Mode_previousMode, &LifeCycle_Mode_nextMode);

  SysTime_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <SYSTIME_INITIALIZED, SYSTIME_STOPPED>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SysTimeGetTimeArea(void)
 *   void Rte_Exit_SysTimeGetTimeArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SysTime_CODE) SysTime_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SysTime_MainFunction
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_SysTime_Rte_Enter_SysTimeGetTimeArea();
  TSC_SysTime_Rte_Exit_SysTimeGetTimeArea();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReadDataSystemTime
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <SystemTime>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SysTimeGetTimeArea(void)
 *   void Rte_Exit_SysTimeGetTimeArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SysTime_GetSystemTime(uint8 *Data)
 *     Argument Data: uint8* is of type Array4
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SystemTime_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReadDataSystemTime_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SysTime_CODE) SysTime_GetSystemTime(P2VAR(uint8, AUTOMATIC, RTE_SYSTIME_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SysTime_GetSystemTime (returns application error)
 *********************************************************************************************************************/

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  TSC_SysTime_Rte_Enter_SysTimeGetTimeArea();
  TSC_SysTime_Rte_Exit_SysTimeGetTimeArea();

  return RTE_E_DataServices_SystemTime_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ReceiveSignal
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <timeSignal> of PortPrototype <SysTimeRx>
 *     and not in Mode(s) <SYSTIME_INITIALIZED, SYSTIME_STOPPED>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SysTimeRx_timeSignal(uint32 *data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SysTimeGetTimeArea(void)
 *   void Rte_Exit_SysTimeGetTimeArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ReceiveSignal_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SysTime_CODE) SysTime_ReceiveSignal(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SysTime_ReceiveSignal
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Read_SysTimeRx_timeSignal;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_SysTime_Rte_Read_SysTimeRx_timeSignal(&Read_SysTimeRx_timeSignal);
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

  TSC_SysTime_Rte_Enter_SysTimeGetTimeArea();
  TSC_SysTime_Rte_Exit_SysTimeGetTimeArea();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SysTime_STOP_SEC_CODE
#include "SysTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void SysTime_TestDefines(void)
{
  /* Enumeration Data Types */

  SysTime_LifeCycleRequestType Test_SysTime_LifeCycleRequestType_V_1 = SYSTIME_INITIALIZED;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycleRequestType_V_2 = SYSTIME_RUNNING;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycleRequestType_V_3 = SYSTIME_STOPPED;

  /* Modes */

  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_MV_1 = RTE_MODE_SysTime_LifeCycle_SYSTIME_INITIALIZED;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_MV_2 = RTE_MODE_SysTime_LifeCycle_SYSTIME_RUNNING;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_MV_3 = RTE_MODE_SysTime_LifeCycle_SYSTIME_STOPPED;
  SysTime_LifeCycleRequestType Test_SysTime_LifeCycle_TV = RTE_TRANSITION_SysTime_LifeCycle;
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
