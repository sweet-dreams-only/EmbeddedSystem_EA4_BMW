/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : NxtrMcuIrqPatch.c 
* Module Description: Implements the errata patch for the MCU defined FE ISR routine
* Project           : CBD
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:           1 %
* %derived_by:        czgng4 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  --------
* 01/05/16   1       LWW       Initial Version                                                                EA4#3172
**********************************************************************************************************************/

/**********************************************************************************************************************
*   Patched_MCU_FEINT_ISR:
*   This section provides the SYNCP workaround for the FENMI exception (see Renesas Technical Update TN-RH8-S001A/E)
**********************************************************************************************************************/
__asm("   .align  4");
__asm("   .globl  _Patched_MCU_FEINT_ISR");
__asm("   .extern _MCU_FEINT_ISR");
__asm("_Patched_MCU_FEINT_ISR:");
__asm("   syncp");
__asm("   jr    _MCU_FEINT_ISR");
