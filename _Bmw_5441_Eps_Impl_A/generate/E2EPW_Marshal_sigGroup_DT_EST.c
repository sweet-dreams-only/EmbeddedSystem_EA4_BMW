/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_sigGroup_DT_EST.c
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

#include "Rte_BmwMsgSlot49Bas1Repn2BusFrChA.h"
#include "E2EPW_Marshal_sigGroup_DT_EST.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_sigGroup_DT_EST
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_sigGroup_DT_EST
    ( P2CONST (sigGroup_DT_EST1, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal ST_CULI_EST */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ST_CULI_EST);
    ppa[7]  = src[0] & 0x0f;

    /* packing signal DT_EST_dummy_64_95 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DT_EST_dummy_64_95);
    ppa[8]  = src[0];
    ppa[9]  = src[1];
    ppa[10]  = src[2];
    ppa[11]  = src[3];

    /* packing signal QU_AVL_I_ACT_EST */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->QU_AVL_I_ACT_EST);
    ppa[7] |= (src[0] << 4) & 0xf0;

    /* packing signal DT_EST_dummy_12_15 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DT_EST_dummy_12_15);
    ppa[1] &= 0x0f;
    ppa[1] |= (src[0] << 4) & 0xf0;

    /* packing signal AVL_I_ACT_EST */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->AVL_I_ACT_EST);
    ppa[6]  = src[0];

    /* packing signal DT_EST_dummy_96_127 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DT_EST_dummy_96_127);
    ppa[12]  = src[0];
    ppa[13]  = src[1];
    ppa[14]  = src[2];
    ppa[15]  = src[3];

    /* packing signal DT_EST_dummy_16_47 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->DT_EST_dummy_16_47);
    ppa[2]  = src[0];
    ppa[3]  = src[1];
    ppa[4]  = src[2];
    ppa[5]  = src[3];
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
