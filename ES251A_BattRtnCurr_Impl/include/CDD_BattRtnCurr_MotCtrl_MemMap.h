/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_BattRtnCurr_MotCtrl_MemMap.h
 * Module Description: Battery Return Current Motor control ISR header
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 07/21/17  1        KByrski   Initial version                                                               EA4#13927
 *********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#ifdef CDD_BattRtnCurr_MotCtrl_START_SEC_CODE
# undef CDD_BattRtnCurr_MotCtrl_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define MotCtrl_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

#ifdef CDD_BattRtnCurr_MotCtrl_STOP_SEC_CODE
# undef CDD_BattRtnCurr_MotCtrl_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define MotCtrl_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
