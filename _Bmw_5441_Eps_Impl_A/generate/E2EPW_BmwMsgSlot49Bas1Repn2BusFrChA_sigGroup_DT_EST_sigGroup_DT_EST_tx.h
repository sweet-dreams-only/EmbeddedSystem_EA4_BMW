/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST_tx.h
 ** Mon, 30-Jul-2018, 21:42:06
 **/

#ifndef E2EPW_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST_TX_H
#define E2EPW_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST_TX_H

#include "Rte_Type.h"
#include "E2E_P01.h"

#define BmwMsgSlot49Bas1Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_sigGroup_DT_EST_sigGroup_DT_EST_tx ()
 * Description:   Initialize the E2Elib transmission-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) E2EPW_WriteInit_sigGroup_DT_EST_sigGroup_DT_EST (void);

/**********************************************************
 * Function name: E2EPW_Get_SenderState_sigGroup_DT_EST_sigGroup_DT_EST ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01ProtectStateType
                  , BmwMsgSlot49Bas1Repn2BusFrChA_VAR_NOINIT
                  , BmwMsgSlot49Bas1Repn2BusFrChA_CODE
                  )
    E2EPW_Get_ProtectState_sigGroup_DT_EST_sigGroup_DT_EST (void);

/**********************************************************
 * Function name: E2EPW_Write_sigGroup_DT_EST_sigGroup_DT_EST (sigGroup_DT_EST1 *  AppData);
 * Description:   Protects data with E2Elib, transmits it
 *                with Rte_Write_<p>_<o> and return an
 *                error-code.
 *   Parameter AppData:
 *                The data to be protected and transmitted.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) E2EPW_Write_sigGroup_DT_EST_sigGroup_DT_EST
    (P2VAR (sigGroup_DT_EST1, AUTOMATIC, BmwMsgSlot49Bas1Repn2BusFrChA_VAR_INIT) AppData);

#define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"

#endif
/*  << EOF >>  */
