/*************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_MotAg3Meas.h
* Module Description: MotAg3Meas header file for
*                     Non-RTE function declarations
* Project           : CBD
* Author            : Shruthi Raghavan
*****************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz2554 %
*------------------------------------------------------------------------------------------------------------
* Date          Rev     Author                          Change Description                            SCR #
* ----------   ------  --------  ---------------------------------------------------------------   ----------
* 11/10/2016    1        SR      Initial Version                                                   EA4#7579
*************************************************************************************************************/

/* -----[ MISRA Deviation Comments ]------------------- */
/* MISRA-C:2004 Rule 8.8   [NXTRDEV 8.8.1  ]: Deviation allowed for functions required to be declared in two headers
 *                                            to be accessible via the RTE as well as outside of the RTE.
 *                                            Function Names: GetMotAg3Mecl_Oper
 */

#ifndef CDD_MOTAG3MEAS_H
#define CDD_MOTAG3MEAS_H

extern FUNC(void, CDD_MotAg3Meas_CODE) GetMotAg3Mecl_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG3MEAS_APPL_VAR) MotAgMecl_Arg);

#endif
