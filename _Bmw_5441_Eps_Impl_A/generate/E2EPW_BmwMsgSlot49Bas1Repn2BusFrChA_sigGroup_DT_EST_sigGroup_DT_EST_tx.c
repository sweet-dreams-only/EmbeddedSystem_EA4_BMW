/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST_tx.c
 ** Mon, 30-Jul-2018, 21:42:06
 **/

/**********************************************************
 * MISRA RULE 14.1 VIOLATION:
 * Error Message : Msg(4:1503) The function '<name>' is
 *   defined but is not used within this project.
 * Justification : Library functions
 **********************************************************/
/* PRQA S 1503 EOF */
/**********************************************************
 * MISRA RULE 19.1 VIOLATION:
 * Error Message : Msg(4:5087) #include statements in a
 *   file should only be preceded by other preprocessor
 *   directives or comments.
 * Justification : Inclusion of MemMap file is AUTOSAR
 *   specific
 **********************************************************/
/* PRQA S 5087 EOF */
#include "Rte_BmwMsgSlot49Bas1Repn2BusFrChA.h"
#include "E2EPW_Marshal_sigGroup_DT_EST.h"
#include "E2EPW_BmwMsgSlot49Bas1Repn2BusFrChA_sigGroup_DT_EST_sigGroup_DT_EST_tx.h"
#ifndef STATIC
    #define STATIC static
#endif

#define BmwMsgSlot49Bas1Repn2BusFrChA_START_SEC_VAR_INIT_UNSPECIFIED
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"

STATIC VAR (E2E_P01ProtectStateType, BmwMsgSlot49Bas1Repn2BusFrChA_VAR_INIT)
    StateVal_sigGroup_DT_EST_sigGroup_DT_EST =
{
    0  /* Counter */
};

STATIC P2VAR ( E2E_P01ProtectStateType
             , BmwMsgSlot49Bas1Repn2BusFrChA_VAR_INIT
             , BmwMsgSlot49Bas1Repn2BusFrChA_VAR_INIT
             )
    State_sigGroup_DT_EST_sigGroup_DT_EST =
        &StateVal_sigGroup_DT_EST_sigGroup_DT_EST;

#define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"

#define BmwMsgSlot49Bas1Repn2BusFrChA_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ppa_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC VAR (uint8, BmwMsgSlot49Bas1Repn2BusFrChA_VAR_NOINIT)
    ppa_sigGroup_DT_EST_sigGroup_DT_EST_au8 [16];

#define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"

#define BmwMsgSlot49Bas1Repn2BusFrChA_START_SEC_CONST_UNSPECIFIED
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ConfigVal_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC CONST (E2E_P01ConfigType, BmwMsgSlot49Bas1Repn2BusFrChA_CONST)
    ConfigVal_sigGroup_DT_EST_sigGroup_DT_EST =
{
      8
    , 0
    , 230
    , 12
    , E2E_P01_DATAID_BOTH
    , 128
    , 13
    , 15
    , 0
};

#define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_CONST_UNSPECIFIED
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"

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
FUNC (void, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) E2EPW_WriteInit_sigGroup_DT_EST_sigGroup_DT_EST (void)
{
    State_sigGroup_DT_EST_sigGroup_DT_EST = &StateVal_sigGroup_DT_EST_sigGroup_DT_EST;
    State_sigGroup_DT_EST_sigGroup_DT_EST->Counter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_SenderState_sigGroup_DT_EST_sigGroup_DT_EST ()
 * Description:   Returns a pointer to the current E2Elib
 *                transmission-state.
 * Parameter:     None
 * Return value:  The current E2Elib transmission-status
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
FUNC_P2VAR ( E2E_P01ProtectStateType
           , BmwMsgSlot49Bas1Repn2BusFrChA_VAR_NOINIT
           , BmwMsgSlot49Bas1Repn2BusFrChA_CODE
           )
    E2EPW_Get_ProtectState_sigGroup_DT_EST_sigGroup_DT_EST (void)
{
    return State_sigGroup_DT_EST_sigGroup_DT_EST;
}

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
FUNC (uint32, BmwMsgSlot49Bas1Repn2BusFrChA_CODE) E2EPW_Write_sigGroup_DT_EST_sigGroup_DT_EST
    (P2VAR (sigGroup_DT_EST1, AUTOMATIC, BmwMsgSlot49Bas1Repn2BusFrChA_VAR_INIT) AppData)
{
    VAR (uint8, AUTOMATIC) ret_u8;

    VAR (uint32, AUTOMATIC) status_ok_u32 =
          (0       <<24)  /* unused */
        | (E2E_E_OK<<16)  /* Protection Wrapper */
        | (RTE_E_OK<<8)   /* Rte_Write */
        | (E2E_E_OK);     /* E2E_..Protect */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;

    P2CONST (E2E_P01ConfigType, AUTOMATIC, BmwMsgSlot49Bas1Repn2BusFrChA_CONST)
        Config_sigGroup_DT_EST_sigGroup_DT_EST = &ConfigVal_sigGroup_DT_EST_sigGroup_DT_EST;

    if (AppData == NULL_PTR)
    {
        ret_u8 = E2E_E_INPUTERR_NULL;
        status_u32 &= 0xFF00FFFFU;
        status_u32 |= (((uint32)ret_u8)<<16);
    }

    if (status_u32 == status_ok_u32)
    {
        E2EPW_Marshal_sigGroup_DT_EST ( AppData, ppa_sigGroup_DT_EST_sigGroup_DT_EST_au8 );
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Protect
                     ( Config_sigGroup_DT_EST_sigGroup_DT_EST
                     , State_sigGroup_DT_EST_sigGroup_DT_EST
                     , ppa_sigGroup_DT_EST_sigGroup_DT_EST_au8
                     );
        status_u32 &= 0xFFFFFF00U;
        status_u32 |= (ret_u8);
    }

    if (status_u32 == status_ok_u32)
    {
        uint16 crcoffset_u16 = Config_sigGroup_DT_EST_sigGroup_DT_EST->CRCOffset/8;
        uint16 cntoffset_u16 = Config_sigGroup_DT_EST_sigGroup_DT_EST->CounterOffset/8;
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL.
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
        AppData->CRC_DT_EST = ppa_sigGroup_DT_EST_sigGroup_DT_EST_au8[crcoffset_u16];
        AppData->ALIV_DT_EST = (ppa_sigGroup_DT_EST_sigGroup_DT_EST_au8[cntoffset_u16] & 0x0F);
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = Rte_Write_sigGroup_DT_EST_sigGroup_DT_EST ( AppData );
        status_u32 &= 0xFFFF00FFU;
        status_u32 |= (((uint32)ret_u8)<<8);
    }

    return status_u32;
}

#define BmwMsgSlot49Bas1Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot49Bas1Repn2BusFrChA_MemMap.h"
/*  << EOF >>  */
