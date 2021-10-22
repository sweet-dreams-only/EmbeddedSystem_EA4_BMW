/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH_rx.h
 ** Mon, 30-Jul-2018, 21:42:06
 **/

#ifndef E2EPW_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH_RX_H
#define E2EPW_BmwMsgSlot55Bas3Repn4BusFrChA_sigGroup_V_VEH_sigGroup_V_VEH_RX_H
#include "Rte_Type.h"
#include "E2E_P01.h"

#define BmwMsgSlot55Bas3Repn4BusFrChA_START_SEC_CODE
#include "BmwMsgSlot55Bas3Repn4BusFrChA_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_sigGroup_V_VEH_sigGroup_V_VEH_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
extern FUNC (void, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) E2EPW_ReadInit_sigGroup_V_VEH_sigGroup_V_VEH (void);

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_sigGroup_V_VEH_sigGroup_V_VEH ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
extern FUNC_P2VAR ( E2E_P01CheckStateType
             , BmwMsgSlot55Bas3Repn4BusFrChA_VAR_NOINIT
             , BmwMsgSlot55Bas3Repn4BusFrChA_CODE
             )
    E2EPW_Get_CheckState_sigGroup_V_VEH_sigGroup_V_VEH (void);

/**********************************************************
 * Function name: E2EPW_Read_sigGroup_V_VEH_sigGroup_V_VEH (sigGroup_V_VEH1 * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
extern FUNC (uint32, BmwMsgSlot55Bas3Repn4BusFrChA_CODE) E2EPW_Read_sigGroup_V_VEH_sigGroup_V_VEH
    ( P2VAR (sigGroup_V_VEH1, AUTOMATIC, BmwMsgSlot55Bas3Repn4BusFrChA_VAR_INIT) AppData);

#define BmwMsgSlot55Bas3Repn4BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot55Bas3Repn4BusFrChA_MemMap.h"

#endif
/*  << EOF >>  */
