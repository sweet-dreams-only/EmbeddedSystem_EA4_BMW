/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_rx.c
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
/**********************************************************
 * MISRA VIOLATION: 'Metrics VOCF<=4' VIOLATION:
 * Code-structure based on by AUTOSAR 'Spec.of EndtoEnd
 * Communication Protection', R3.2.1 V1.2.0./
 * and '893.061.D_End-to-End Kommunikationsabsicherung_v1.5'
 **********************************************************/
#include "Rte_BmwMsgSlot107Bas0Repn1BusFrChA.h"
#include "E2EPW_Marshal_sigGroup_OFFS_QUAD_EPS.h"
#include "E2EPW_CheckDeserial_sigGroup_OFFS_QUAD_EPS.h"
#include "E2EPW_BmwMsgSlot107Bas0Repn1BusFrChA_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_rx.h"
#ifndef STATIC
    #define STATIC static
#endif

#define BmwMsgSlot107Bas0Repn1BusFrChA_START_SEC_VAR_INIT_UNSPECIFIED
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"

STATIC VAR (E2E_P01CheckStateType, BmwMsgSlot107Bas0Repn1BusFrChA_VAR_INIT)
    StateVal_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS =
{
      0                        /* LastValidCounter */
    , 0                        /* MaxDeltaCounter  */
    , TRUE                     /* WaitForFirstData */
    , FALSE                    /* NewDataAvailable */
    , 0                        /* LostData */
    , E2E_P01STATUS_NONEWDATA  /* Status */
    , 0                        /* SyncCounter */
    , 0                        /* NoNewOrRepeatedCounter */
};

STATIC P2VAR ( E2E_P01CheckStateType
             , BmwMsgSlot107Bas0Repn1BusFrChA_VAR_INIT
             , BmwMsgSlot107Bas0Repn1BusFrChA_VAR_INIT
             )
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS =
        &StateVal_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS;

#define BmwMsgSlot107Bas0Repn1BusFrChA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"

#define BmwMsgSlot107Bas0Repn1BusFrChA_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ppa_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC VAR (uint8, BmwMsgSlot107Bas0Repn1BusFrChA_VAR_NOINIT)
    ppa_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_au8 [5];

#define BmwMsgSlot107Bas0Repn1BusFrChA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"

#define BmwMsgSlot107Bas0Repn1BusFrChA_START_SEC_CONST_UNSPECIFIED
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ConfigVal_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC CONST (E2E_P01ConfigType, BmwMsgSlot107Bas0Repn1BusFrChA_CONST)
    ConfigVal_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS =
{
      8
    , 0
    , 229
    , 12
    , E2E_P01_DATAID_BOTH
    , 40
    , 13
    , 15
    , 0
};

#define BmwMsgSlot107Bas0Repn1BusFrChA_STOP_SEC_CONST_UNSPECIFIED
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"

#define BmwMsgSlot107Bas0Repn1BusFrChA_START_SEC_CODE
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
FUNC (void, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) E2EPW_ReadInit_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS (void)
{
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS = &StateVal_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->LastValidCounter = 0;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->MaxDeltaCounter  = 0;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->WaitForFirstData = TRUE;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->NewDataAvailable = FALSE;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->LostData         = 0;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->Status           = E2E_P01STATUS_NONEWDATA;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->SyncCounter      = 0;
    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->NoNewOrRepeatedDataCounter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
FUNC_P2VAR ( E2E_P01CheckStateType
           , BmwMsgSlot107Bas0Repn1BusFrChA_VAR_NOINIT
           , BmwMsgSlot107Bas0Repn1BusFrChA_CODE
           )
    E2EPW_Get_CheckState_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS (void)
{
    return State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS;
}

/**********************************************************
 * Function name: E2EPW_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS (sigGroup_OFFS_QUAD_EPS1 * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, BmwMsgSlot107Bas0Repn1BusFrChA_CODE) E2EPW_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS
    ( P2VAR (sigGroup_OFFS_QUAD_EPS1, AUTOMATIC, BmwMsgSlot107Bas0Repn1BusFrChA_VAR_INIT) AppData)
{
    VAR (uint8, AUTOMATIC) ret_u8;
    VAR (uint8, AUTOMATIC) ret_rte_u8 = RTE_E_OK;

    VAR (uint32, AUTOMATIC) status_ok_u32 =
           (0<<31)                         /* Deserial-Check */
        |  ((E2E_P01STATUS_OK & 0x7F)<<24) /* ReceiverStatus */
        |  (E2E_E_OK<<16)                  /* Protection Wrapper */
        |  (RTE_E_OK<<8)                   /* Rte_Read */
        |  (E2E_E_OK);                     /* E2E_...Check */
    VAR (uint32, AUTOMATIC) status_u32 = status_ok_u32;

    P2CONST (E2E_P01ConfigType, AUTOMATIC, BmwMsgSlot107Bas0Repn1BusFrChA_CONST)
        Config_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS = &ConfigVal_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS;

    State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->NewDataAvailable =
        Rte_IsUpdated_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS ();

    if ((State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->NewDataAvailable != FALSE))
    {
        if (AppData == NULL_PTR)
        {
            ret_u8 = E2E_E_INPUTERR_NULL;
            status_u32 &= 0xFF00FFFFU;
            status_u32 |= (((uint32)ret_u8)<<16);
        }

        if (status_u32 == status_ok_u32)
        {
            /* Return-value of Rte_Read does not affect
               following workflow.
            */
            ret_rte_u8 = Rte_Read_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS (AppData);
        }

        if (status_u32 == status_ok_u32)
        {
            ret_u8 = E2EPW_CheckDeserial_sigGroup_OFFS_QUAD_EPS (AppData);
            status_u32 &= 0x7FFFFFFFU;
            status_u32 |= (((uint32)ret_u8)<<31);
        }

        if (status_u32 == status_ok_u32)
        {
            uint16 crcoffset_u16 = Config_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->CRCOffset >> 3u;
            uint16 cntoffset_u16 = Config_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->CounterOffset >> 3u;
            E2EPW_Marshal_sigGroup_OFFS_QUAD_EPS ( AppData, ppa_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_au8 );
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL.
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
            ppa_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_au8[crcoffset_u16]  = AppData->CRC_OFFS_QUAD_EPS;
            ppa_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_au8[cntoffset_u16] &= (uint8)0xf0;
            ppa_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_au8[cntoffset_u16] |= AppData->ALIV_OFFS_QUAD_EPS;
        }
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Check
                     ( Config_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS
                     , State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS
                     , ppa_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS_au8
                     );
        status_u32 &= 0x80FFFF00U;
        status_u32 |= ret_u8;
        status_u32 |= (uint32)(State_sigGroup_OFFS_QUAD_EPS_sigGroup_OFFS_QUAD_EPS->Status<<24);
    }

    status_u32 &= 0xFFFF00FFU;
    status_u32 |= (((uint32)ret_rte_u8)<<8);

    return status_u32;
}

#define BmwMsgSlot107Bas0Repn1BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot107Bas0Repn1BusFrChA_MemMap.h"
/*  << EOF >>  */
