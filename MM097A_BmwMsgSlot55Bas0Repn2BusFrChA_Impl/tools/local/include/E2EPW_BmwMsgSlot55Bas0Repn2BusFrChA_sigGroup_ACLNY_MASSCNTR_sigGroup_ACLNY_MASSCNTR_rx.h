/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_rx.h
 ** Thu, 26-Oct-2017, 17:45:02
 **/

#ifndef E2EPW_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_RX_H
#define E2EPW_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_RX_H
#include "Rte_Type.h"
#include "E2E_P01.h"


#define BmwMsgSlot55Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) E2EPW_ReadInit_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR (void);

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01CheckStateType
             , BmwMsgSlot55Bas0Repn2BusFrChA_VAR_NOINIT
             , BmwMsgSlot55Bas0Repn2BusFrChA_CODE
             )
    E2EPW_Get_CheckState_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR (void);

/**********************************************************
 * Function name: E2EPW_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR (sigGroup_ACLNY_MASSCNTR * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) E2EPW_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR
    ( P2VAR (sigGroup_ACLNY_MASSCNTR1, AUTOMATIC, BmwMsgSlot55Bas0Repn2BusFrChA_VAR_INIT) AppData);

#define BmwMsgSlot55Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h"

#endif
/*  << EOF >>  */
