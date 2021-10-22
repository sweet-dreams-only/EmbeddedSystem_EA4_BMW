/** Generated code, do not change!
 ** Written by Protection Wrapper Generator (V 2.0.1)
 ** Module: E2EPW_Marshal_sigGroup_ENERG_DGR_DRDY.c
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

#include "Rte_BmwMsgSlot68Bas1Repn2BusFrChA.h"
#include "E2EPW_Marshal_sigGroup_ENERG_DGR_DRDY.h"

#define E2EPW_START_SEC_CODE_LIB
#include "MemMap.h"

/******************************************************************
 * Function name      : E2EPW_Marshal_sigGroup_ENERG_DGR_DRDY
 * Description        : Generates the bus representation of a
 *                      protected pdu area by packing the signals
 *                      of the protected data element into it (so
 *                      called 'Marshaling').
 * Parameter pde (in) : pointer to protected data element
 * Parameter ppa (out): pointer to protected pdu area
 * Return value       : void
 * Remarks            : none
 ******************************************************************/
FUNC (void, E2EPW_CODE) E2EPW_Marshal_sigGroup_ENERG_DGR_DRDY
    ( P2CONST (sigGroup_ENERG_DGR_DRDY1, AUTOMATIC, E2EPW_APPL_DATA) pde
    , P2VAR (uint8, AUTOMATIC, E2EPW_APPL_VAR) ppa
    )
{
    P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA) src;

    /* packing signal MAX_I_LD_SPEC_ARS */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->MAX_I_LD_SPEC_ARS);
    ppa[3]  = src[0];

    /* packing signal MAX_I_RECUP_SPEC_ARS */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->MAX_I_RECUP_SPEC_ARS);
    ppa[4]  = src[0];

    /* packing signal RQ_CULI_EST_SFY */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->RQ_CULI_EST_SFY);
    ppa[1]  = src[0] & 0x0f;

    /* packing signal ENERG_AVAI_ARS */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ENERG_AVAI_ARS);
    ppa[5]  = src[0];

    /* packing signal QU_DGR_AISP_ENERG */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->QU_DGR_AISP_ENERG);
    ppa[6] &= 0xf0;
    ppa[6] |= src[0] & 0x0f;

    /* packing signal MAX_I_SPEC_BAX_STE */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->MAX_I_SPEC_BAX_STE);
    ppa[2]  = src[0];

    /* packing signal ENERG_DGR_DRDY_dummy_12_15 */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->ENERG_DGR_DRDY_dummy_12_15);
    ppa[1] |= (src[0] << 4) & 0xf0;

    /* packing signal MAX_I_SPEC_EPS */
    src = (P2CONST (uint8, AUTOMATIC, E2EPW_APPL_DATA)) &(pde->MAX_I_SPEC_EPS);
    ppa[0]  = src[0];
}

#define E2EPW_STOP_SEC_CODE_LIB
#include "MemMap.h"

/*  << EOF >>  */
