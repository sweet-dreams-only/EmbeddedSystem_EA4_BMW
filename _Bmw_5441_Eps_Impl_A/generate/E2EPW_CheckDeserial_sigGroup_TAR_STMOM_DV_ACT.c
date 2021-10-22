/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_CheckDeserial_sigGroup_TAR_STMOM_DV_ACT.c
 ** Mon, 30-Jul-2018, 21:42:06
 **/

/******************************************************************
 * MISRA RULE 19.1 VIOLATION:
 * Error Message : Msg(4:5087) #include statements in a file
 *   should only be preceded by other preprocessor directives or
 *   comments.
 * Justification : Inclusion of MemMap.h is AUTOSAR specific.
 ******************************************************************/
/* PRQA S 5087 EOF */

#include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h"
#include "E2EPW_CheckDeserial_sigGroup_TAR_STMOM_DV_ACT.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_CheckDeserial_sigGroup_TAR_STMOM_DV_ACT
 * Description        : Checks if the signals in the de-serialized
 *                      protected data element are in a valid
 *                      range, considering their bit length in the
 *                      protected pdu area.
 * Parameter pde (in) : pointer to protected data element
 * Return value       : 0                    deserial check passed
 *                      E2EPW_DESERIAL_ERR   deserial check failed
 * Remarks            : none
 ******************************************************************/
FUNC (uint8, E2EPW_CODE) E2EPW_CheckDeserial_sigGroup_TAR_STMOM_DV_ACT
    ( P2CONST (sigGroup_TAR_STMOM_DV_ACT1, AUTOMATIC, E2EPW_APPL_DATA) pde )
{
    VAR (uint8, AUTOMATIC) ret = 0;

    if ((pde->TAR_STMOM_DV_ACT_dummy_12_15 & 0xf0u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->TAR_STMOM_DV_ACT_dummy_32_51 & 0xfff00000u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->QU_TAR_DMPNG_ADDON_STMOM_FTAX & 0xf0u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->TAR_STMOM_DV_ACT & 0xf000u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->QU_TAR_STMOM_DV_ACT & 0xf0u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    if ((pde->ALIV_TAR_STMOM_DV_ACT & 0xf0u) != 0)
    {
        ret = E2EPW_DESERIAL_ERR;
    }

    return ret;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
