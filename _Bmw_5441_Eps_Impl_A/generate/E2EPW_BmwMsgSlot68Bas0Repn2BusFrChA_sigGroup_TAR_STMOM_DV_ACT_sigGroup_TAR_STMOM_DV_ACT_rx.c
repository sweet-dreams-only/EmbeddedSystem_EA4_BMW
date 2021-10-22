/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_rx.c
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
#include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h"
#include "E2EPW_Marshal_sigGroup_TAR_STMOM_DV_ACT.h"
#include "E2EPW_CheckDeserial_sigGroup_TAR_STMOM_DV_ACT.h"
#include "E2EPW_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_rx.h"
#ifndef STATIC
    #define STATIC static
#endif

#define BmwMsgSlot68Bas0Repn2BusFrChA_START_SEC_VAR_INIT_UNSPECIFIED
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"

STATIC VAR (E2E_P01CheckStateType, BmwMsgSlot68Bas0Repn2BusFrChA_VAR_INIT)
    StateVal_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT =
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
             , BmwMsgSlot68Bas0Repn2BusFrChA_VAR_INIT
             , BmwMsgSlot68Bas0Repn2BusFrChA_VAR_INIT
             )
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT =
        &StateVal_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT;

#define BmwMsgSlot68Bas0Repn2BusFrChA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"

#define BmwMsgSlot68Bas0Repn2BusFrChA_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ppa_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC VAR (uint8, BmwMsgSlot68Bas0Repn2BusFrChA_VAR_NOINIT)
    ppa_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_au8 [8];

#define BmwMsgSlot68Bas0Repn2BusFrChA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"

#define BmwMsgSlot68Bas0Repn2BusFrChA_START_SEC_CONST_UNSPECIFIED
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"
/**********************************************************
 * MISRA RULE 8.7 VIOLATION:
 * Error Message : Msg(4:3218) File scope static,
 * 'ConfigVal_..', only accessed in one function.
 * Justification : Extracted from function for 
 *   MemMap (MemMap defines cannot be stacked).
 **********************************************************/
/* PRQA S 3218 2 */
STATIC CONST (E2E_P01ConfigType, BmwMsgSlot68Bas0Repn2BusFrChA_CONST)
    ConfigVal_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT =
{
      8
    , 0
    , 179
    , 12
    , E2E_P01_DATAID_BOTH
    , 64
    , 13
    , 15
    , 0
};

#define BmwMsgSlot68Bas0Repn2BusFrChA_STOP_SEC_CONST_UNSPECIFIED
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"

#define BmwMsgSlot68Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"

/**********************************************************
 * Function name: E2EPW_Init_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_rx ()
 * Description:   Initialize the E2Elib receiver-state.
 * Parameter:     None
 * Return value:  None
 * Remarks:       Call this function after an application or
 *                communication startup or reset and prior
 *                to any other E2EPW API-call.
 **********************************************************/
FUNC (void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) E2EPW_ReadInit_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT (void)
{
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT = &StateVal_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->LastValidCounter = 0;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->MaxDeltaCounter  = 0;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->WaitForFirstData = TRUE;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->NewDataAvailable = FALSE;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->LostData         = 0;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->Status           = E2E_P01STATUS_NONEWDATA;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->SyncCounter      = 0;
    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->NoNewOrRepeatedDataCounter = 0;
}

/**********************************************************
 * Function name: E2EPW_Get_ReceiverState_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT ()
 * Description:   Returns a pointer to the current E2Elib 
 * receiver-state.
 * Parameter:     None
 * Return value:  The current E2Elib receiver-status.
 * Remarks:       Can be used to manipulate the state.
 *                Use this function with care.
 **********************************************************/
FUNC_P2VAR ( E2E_P01CheckStateType
           , BmwMsgSlot68Bas0Repn2BusFrChA_VAR_NOINIT
           , BmwMsgSlot68Bas0Repn2BusFrChA_CODE
           )
    E2EPW_Get_CheckState_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT (void)
{
    return State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT;
}

/**********************************************************
 * Function name: E2EPW_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT (sigGroup_TAR_STMOM_DV_ACT1 * AppData);
 * Description:   Reads data with Rte_Read_<p>_<o> (),
 *                checks it with E2Elib and returns the data
 *                and an error-code.
 * Parameter AppData:
 *                The data received by Rte_Read and checked
 *                by E2Elib.
 * Return value:  Error-code
 * Remarks:       None
 **********************************************************/
FUNC (uint32, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) E2EPW_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT
    ( P2VAR (sigGroup_TAR_STMOM_DV_ACT1, AUTOMATIC, BmwMsgSlot68Bas0Repn2BusFrChA_VAR_INIT) AppData)
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

    P2CONST (E2E_P01ConfigType, AUTOMATIC, BmwMsgSlot68Bas0Repn2BusFrChA_CONST)
        Config_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT = &ConfigVal_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT;

    State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->NewDataAvailable =
        Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT ();

    if ((State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->NewDataAvailable != FALSE))
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
            ret_rte_u8 = Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT (AppData);
        }

        if (status_u32 == status_ok_u32)
        {
            ret_u8 = E2EPW_CheckDeserial_sigGroup_TAR_STMOM_DV_ACT (AppData);
            status_u32 &= 0x7FFFFFFFU;
            status_u32 |= (((uint32)ret_u8)<<31);
        }

        if (status_u32 == status_ok_u32)
        {
            uint16 crcoffset_u16 = Config_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->CRCOffset >> 3u;
            uint16 cntoffset_u16 = Config_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->CounterOffset >> 3u;
            E2EPW_Marshal_sigGroup_TAR_STMOM_DV_ACT ( AppData, ppa_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_au8 );
/**********************************************************
 * MISRA RULE 1.2 VIOLATION:
 * Error Message : Msg(7:0505) [U] Dereferencing pointer
 *   value that is apparently NULL.
 * Justification : AppData is checked for NULL above.
 *   Value does not change from check to here
 **********************************************************/
/* PRQA S 505 1*/
            ppa_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_au8[crcoffset_u16]  = AppData->CRC_TAR_STMOM_DV_ACT;
            ppa_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_au8[cntoffset_u16] &= (uint8)0xf0;
            ppa_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_au8[cntoffset_u16] |= AppData->ALIV_TAR_STMOM_DV_ACT;
        }
    }

    if (status_u32 == status_ok_u32)
    {
        ret_u8 = E2E_P01Check
                     ( Config_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT
                     , State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT
                     , ppa_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_au8
                     );
        status_u32 &= 0x80FFFF00U;
        status_u32 |= ret_u8;
        status_u32 |= (uint32)(State_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT->Status<<24);
    }

    status_u32 &= 0xFFFF00FFU;
    status_u32 |= (((uint32)ret_rte_u8)<<8);

    return status_u32;
}

#define BmwMsgSlot68Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h"
/*  << EOF >>  */
