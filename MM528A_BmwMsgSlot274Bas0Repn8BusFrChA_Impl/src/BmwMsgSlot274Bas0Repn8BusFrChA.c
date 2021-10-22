/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot274Bas0Repn8BusFrChA.c
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/MM528A_BmwMsgSlot274Bas0Repn8BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot274Bas0Repn8BusFrChA
 *  Generated at:  Thu May 31 11:34:49 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot274Bas0Repn8BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name: BmwMsgSlot274Bas0Repn8BusFrChA.c
* Module Description: Implementation of BMW Message Slot 274 Base 0 Repetition 8 Bus FlexRay Channel A MM528A
* Project           : CBD  
* Author            : Pratik Jadhav
*****************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       nz3734 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 04/10/18  1        PHJ       Initial Implementation                                                          EA4#22430
* 04/18/18  2        BRB       Continuing Initial Implementation                                               EA4#22430
* 05/31/18  3        BRB       Fix for anomaly EA4#24166                                                       EA4#24736
******************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot274Bas0Repn8BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "E2EPW_BmwMsgSlot274Bas0Repn8BusFrChA_sigGroup_SU_EPS_sigGroup_SU_EPS_tx.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE reads and writes */

#define TOTSTREPSVALUE_CNT_U16		((uint16) 1228U)
#define SUEPSBURSTLIM_CNT_U08		((uint8) 3U)
#define SUEPSBURSTDEB_CNT_U08	    ((uint8) 49U)
#define SUEPSPERCNTLIM_CNT_U16		((uint16) 499U)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ALIV_SU_EPS1: Integer in interval [0...255]
 * CRC_SU_EPS1: Integer in interval [0...255]
 * SU_EPS_dummy_14_191: Integer in interval [0...255]
 * SU_EPS_dummy_20_511: Integer in interval [0...4294967295]
 * TOT_STR_EPS1: Integer in interval [0...65535]
 *   Factor: 0.012213, Offset: 0
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * UN_TOT_STR_EPS1: Enumeration of integer in interval [0...255] with enumerators
 *   UN_TOT_STR_EPS_Ritzelschnittstelle (0U)
 *   UN_TOT_STR_EPS_Zahnstangenhubschnittstelle (1U)
 *   UN_TOT_STR_EPS_SignalUngueltig (3U)
 *
 * Record Types:
 * =============
 * sigGroup_SU_EPS1: Record with elements
 *   CRC_SU_EPS of type CRC_SU_EPS1
 *   UN_TOT_STR_EPS of type UN_TOT_STR_EPS1
 *   ALIV_SU_EPS of type ALIV_SU_EPS1
 *   TOT_STR_EPS of type TOT_STR_EPS1
 *   SU_EPS_dummy_20_51 of type SU_EPS_dummy_20_511
 *   SU_EPS_dummy_14_19 of type SU_EPS_dummy_14_191
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint16 *Rte_Pim_SuEpsPerCntr(void)
 *   uint8 *Rte_Pim_SuEpsBurstCntr(void)
 *   uint8 *Rte_Pim_SuEpsDebCntr(void)
 *   sigGroup_SU_EPS1 *Rte_Pim_SigGroupSuEps(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot274Bas0Repn8BusFrChA_START_SEC_CODE
#include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas0Repn8BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAInit1
 *********************************************************************************************************************/

	Rte_Pim_SigGroupSuEps()->UN_TOT_STR_EPS = UN_TOT_STR_EPS_Ritzelschnittstelle;
	Rte_Pim_SigGroupSuEps()->TOT_STR_EPS = TOTSTREPSVALUE_CNT_U16;
    
    *Rte_Pim_SuEpsBurstCntr() = *Rte_Pim_SuEpsBurstCntr() + 1U;
    
    /* Send message */
    (void)E2EPW_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(Rte_Pim_SigGroupSuEps());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot274Bas0Repn8BusFrChAPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(const sigGroup_SU_EPS1 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) BmwMsgSlot274Bas0Repn8BusFrChAPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot274Bas0Repn8BusFrChAPer1
 *********************************************************************************************************************/
 	
	if ( (*Rte_Pim_SuEpsDebCntr() >= SUEPSBURSTDEB_CNT_U08) && (*Rte_Pim_SuEpsBurstCntr() < SUEPSBURSTLIM_CNT_U08) )
	{
		/* Reset burst counter and update trigger condition  */
		*Rte_Pim_SuEpsDebCntr() = 0U;
		
		*Rte_Pim_SuEpsPerCntr() = *Rte_Pim_SuEpsPerCntr() + 1U;
        
        *Rte_Pim_SuEpsBurstCntr() = *Rte_Pim_SuEpsBurstCntr() + 1U;

		/* Send message */
		(void)E2EPW_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(Rte_Pim_SigGroupSuEps());
	}
	else if ((*Rte_Pim_SuEpsPerCntr() >= SUEPSPERCNTLIM_CNT_U16))
	{
		/* Reset the periodic counter back to 0 */
		*Rte_Pim_SuEpsPerCntr() = 0U;

		/* Send Message */
		(void)E2EPW_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(Rte_Pim_SigGroupSuEps());
	}
	else
	{
        *Rte_Pim_SuEpsPerCntr() = *Rte_Pim_SuEpsPerCntr() + 1U;
		*Rte_Pim_SuEpsDebCntr() = *Rte_Pim_SuEpsDebCntr() + 1U; /* Counter will roll over, but in a burst event, it is cleared to 0 */
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CfgMsgTxReq_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <CfgMsgTxReq>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CfgMsgTxReq_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CfgMsgTxReq_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot274Bas0Repn8BusFrChA_CODE) CfgMsgTxReq_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CfgMsgTxReq_Oper
 *********************************************************************************************************************/

    /* Only perform the write if no longer in burst mode */
    if (*Rte_Pim_SuEpsBurstCntr() >= SUEPSBURSTLIM_CNT_U08)
    {
        (void)E2EPW_Write_sigGroup_SU_EPS_sigGroup_SU_EPS(Rte_Pim_SigGroupSuEps());
    }	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot274Bas0Repn8BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot274Bas0Repn8BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
