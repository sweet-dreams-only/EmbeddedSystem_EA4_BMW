/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_sigGroup_TAR_STMOM_DV_ACT.c
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
/******************************************************************
 * MISRA RULE 11.4 VIOLATION:
 * Error Message : Msg(4:0310) Casting to different object pointer
 *   type.
 * Justification : Marshal code works on direct byte access for
 *   different application types.
 ******************************************************************/
/* PRQA S 0310 EOF */
/******************************************************************
 * MISRA RULE 10.1 VIOLATION:
 * Error Message : Msg(4:3757) Implicit conversion: int to unsigned
 *   char.
 * Justification : Marshal code generator ensures no loss of data
 *   during endianness conversion.
 ******************************************************************/
/* PRQA S 3757 EOF */

#include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h"
#include "E2EPW_Marshal_sigGroup_TAR_STMOM_DV_ACT.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_sigGroup_TAR_STMOM_DV_ACT
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_sigGroup_TAR_STMOM_DV_ACT
    ( P2CONST (sigGroup_TAR_STMOM_DV_ACT1, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal TAR_STMOM_DV_ACT_dummy_12_15 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TAR_STMOM_DV_ACT_dummy_12_15);
    ppa[1] &= 0x0f;
    ppa[1] |= (src[0] << 4) & 0xf0;

    /* packing signal TAR_STMOM_DV_ACT_dummy_32_51 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TAR_STMOM_DV_ACT_dummy_32_51);
    ppa[4]  = src[0];
    ppa[5]  = src[1];
    ppa[6]  = src[2] & 0x0f;

    /* packing signal QU_TAR_DMPNG_ADDON_STMOM_FTAX */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->QU_TAR_DMPNG_ADDON_STMOM_FTAX);
    ppa[6] |= (src[0] << 4) & 0xf0;

    /* packing signal FACT_DMPNG_ADDON_STMOM_FTAX */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->FACT_DMPNG_ADDON_STMOM_FTAX);
    ppa[7]  = src[0];

    /* packing signal TAR_STMOM_DV_ACT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->TAR_STMOM_DV_ACT);
    ppa[2]  = src[0];
    ppa[3]  = src[1] & 0x0f;

    /* packing signal QU_TAR_STMOM_DV_ACT */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->QU_TAR_STMOM_DV_ACT);
    ppa[3] |= (src[0] << 4) & 0xf0;
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
