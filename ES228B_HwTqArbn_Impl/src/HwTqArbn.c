/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  HwTqArbn.c
 *     SW-C Type:  HwTqArbn
 *  Generated at:  Wed May 25 15:51:35 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <HwTqArbn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : HwTqArbn.c
* Module Description: Arbitration between multiple Torque sensors and calculation of handwheel torque.
* Project           : CBD
* Author            : Basavaraja Ganeshappa
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       fzd2x9 %
*---------------------------------------------------------------------------------------------------------------------
* Date       Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 05/25/2016  1       BG         Initial Version                                                              EA4#5377
**********************************************************************************************************************/
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  SigQlfr1
    uint8 represents integers with a minimum value of 0 and a maximum value of 255.
     The order-relation on uint8 is: x < y if y - x is positive.
     uint8 has a lexical representation consisting of a finite-length sequence 
     of decimal digits (#x30-#x39).
     
     For example: 1, 0, 126, +10.

 *********************************************************************************************************************/

#include "Rte_HwTqArbn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 #include "NxtrMath.h"
 
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value */ 

#define MAXSTALLTQA_CNT_U08 10u
#define MAXSTALLTQB_CNT_U08 10u
#define MAXSTALLCNTR_CNT_U08 (255u)

#define HWTQMINLIM_HWNWTMTR_F32 (-10.0F)
#define HWTQMAXLIM_HWNWTMTR_F32 10.0F


#define  CORRLNSTSMASKSIGA_CNT_U08		0x01u
#define  CORRLNSTSMASKSIGB_CNT_U08		0x02u

#define  HWTQSCA_CNT_U08				(2u)


static FUNC(boolean, HwTqArbn_CODE) SigAvlChkRev( VAR(uint8,    AUTOMATIC) SigRollgCntr_Cnt_T_u08, 
												  VAR(SigQlfr1, AUTOMATIC) SigQlfr_Cnt_T_enum,
												  VAR(uint8,    AUTOMATIC) kMaxStallCnt_Cnt_T_u08,
												  P2VAR(uint8, AUTOMATIC, AUTOMATIC) LstRollgCntr_Cnt_T_u08,
												  P2VAR(uint8, AUTOMATIC, AUTOMATIC) StallCntr_Cnt_T_u08
												  ); 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Enumeration Types:
 * ==================
 * SigQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   SIGQLFR_NORES (0U)
 *   SIGQLFR_PASSD (1U)
 *   SIGQLFR_FAILD (2U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_HwTqPrevHwTq(void)
 *   uint8 *Rte_Pim_HwTqARollgCntrPrev(void)
 *   uint8 *Rte_Pim_HwTqAStallCntrPrev(void)
 *   uint8 *Rte_Pim_HwTqBRollgCntrPrev(void)
 *   uint8 *Rte_Pim_HwTqBStallCntrPrev(void)
 *   boolean *Rte_Pim_dHwTqArbnChAAvl(void)
 *
 *********************************************************************************************************************/


#define HwTqArbn_START_SEC_CODE
#include "HwTqArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, HwTqArbn_CODE) HwTqArbnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqArbnInit1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTqArbnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTqA_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqAQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_HwTqARollgCntr_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_HwTqB_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqBQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_HwTqBRollgCntr_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_HwTqCorrlnSts_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTq_Val(float32 data)
 *
 *********************************************************************************************************************/

FUNC(void, HwTqArbn_CODE) HwTqArbnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwTqArbnPer1
 *********************************************************************************************************************/

	/* Temporary variables for module i/p (for Torque A) */ 	
	VAR(float32,  AUTOMATIC)  HwTqA_HwNwtMtr_T_f32;
	VAR(SigQlfr1, AUTOMATIC)  HwTqAQlfr_Cnt_T_enum;
	VAR(uint8,    AUTOMATIC)  HwTqARollgCntr_Cnt_T_u08;
	
	/* Temporary variables for module i/p (for Torque B) */ 
	VAR(float32,  AUTOMATIC)  HwTqB_HwNwtMtr_T_f32;
	VAR(SigQlfr1, AUTOMATIC)  HwTqBQlfr_Cnt_T_enum;
	VAR(uint8,    AUTOMATIC)  HwTqBRollgCntr_Cnt_T_u08;
	
	/* Temporary variable for module i/p (for Torque correlation status) */ 
	VAR(uint8,    AUTOMATIC)  HwTqCorrlnSts_Cnt_T_u08;
	
	/* Temporary variable (module internal) */
	VAR(boolean,  AUTOMATIC)  SigAAvl_Cnt_T_logl;
	VAR(boolean,  AUTOMATIC)  SigBAvl_Cnt_T_logl;
	VAR(boolean,  AUTOMATIC)  CorrlnStsSigA_Cnt_T_logl;
	VAR(boolean,  AUTOMATIC)  CorrlnStsSigB_Cnt_T_logl;
	VAR(boolean,  AUTOMATIC)  ChAAvl_Cnt_T_logl;
	
	/* Temporary variables for module o/p */
	VAR(float32,  AUTOMATIC)  HwTqChA_HwNwtMtr_T_f32;	
	
	/* Read Module inputs */
	(void) Rte_Read_HwTqA_Val( &HwTqA_HwNwtMtr_T_f32 );
    (void) Rte_Read_HwTqAQlfr_Val( &HwTqAQlfr_Cnt_T_enum );
    (void) Rte_Read_HwTqARollgCntr_Val( &HwTqARollgCntr_Cnt_T_u08 );
	
    (void) Rte_Read_HwTqB_Val( &HwTqB_HwNwtMtr_T_f32 );
    (void) Rte_Read_HwTqBQlfr_Val( &HwTqBQlfr_Cnt_T_enum );
    (void) Rte_Read_HwTqBRollgCntr_Val( &HwTqBRollgCntr_Cnt_T_u08 );
	
	(void) Rte_Read_HwTqCorrlnSts_Val( &HwTqCorrlnSts_Cnt_T_u08 );
	
	 /* REQ: ES228B #85 I */	
 	 /* REQ: ES228B #129 I */	

	/*** ------------------- START: Extract Correlation Fault Status Bits --------------------- ***/
	CorrlnStsSigA_Cnt_T_logl = FALSE;
	CorrlnStsSigB_Cnt_T_logl = FALSE;

	
	if( CORRLNSTSMASKSIGA_CNT_U08 == (HwTqCorrlnSts_Cnt_T_u08 & CORRLNSTSMASKSIGA_CNT_U08))
	{
		CorrlnStsSigA_Cnt_T_logl = TRUE;
	}
	if( CORRLNSTSMASKSIGB_CNT_U08 == (HwTqCorrlnSts_Cnt_T_u08 & CORRLNSTSMASKSIGB_CNT_U08))
	{
		CorrlnStsSigB_Cnt_T_logl = TRUE;
	}

	/*** ------------------- END: Extract Correlation Fault Status Bits ----------------------- ***/
	
	/*REQ: ES228B #91 I */
	/*** ----- Signal Availability check for HwTorque signal A ----- ***/
	SigAAvl_Cnt_T_logl = SigAvlChkRev( HwTqARollgCntr_Cnt_T_u08, 
									  HwTqAQlfr_Cnt_T_enum,
									  MAXSTALLTQA_CNT_U08,
									  Rte_Pim_HwTqARollgCntrPrev(),
									  Rte_Pim_HwTqAStallCntrPrev() ); 
									  
	/*** ----- Signal Availability check for HwTorque signal B ----- ***/
	SigBAvl_Cnt_T_logl = SigAvlChkRev( HwTqBRollgCntr_Cnt_T_u08, 
									  HwTqBQlfr_Cnt_T_enum,
									  MAXSTALLTQB_CNT_U08,
									  Rte_Pim_HwTqBRollgCntrPrev(),
									  Rte_Pim_HwTqBStallCntrPrev());     
	/*** --------------- START: Channel Availability ---------------- ***/
	
	ChAAvl_Cnt_T_logl = FALSE;
	if( (CorrlnStsSigA_Cnt_T_logl == TRUE) && (SigAAvl_Cnt_T_logl == TRUE) && (CorrlnStsSigB_Cnt_T_logl == TRUE) && (SigBAvl_Cnt_T_logl == TRUE) )
	{
		ChAAvl_Cnt_T_logl = TRUE;
	}
	
	*(Rte_Pim_dHwTqArbnChAAvl()) = ChAAvl_Cnt_T_logl;
	/* ENDREQ: ES228B #129 */	
	/*ENDREQ: ES228B #91 */


	/*** --------------- END: Channel Availability ------------------ ***/
	
	/*REQ: ES228B #128 I */
	/*REQ: ES228B #98 I */
	/*** ---------------------- START: Arbitration ----------------------- ***/
	if((ChAAvl_Cnt_T_logl == TRUE))
	{
		HwTqChA_HwNwtMtr_T_f32 = (HwTqA_HwNwtMtr_T_f32 + HwTqB_HwNwtMtr_T_f32) / (float32)HWTQSCA_CNT_U08; /* REQ: ES228A #16 I */
	}	
	else
	{
		HwTqChA_HwNwtMtr_T_f32 = *Rte_Pim_HwTqPrevHwTq();
	}
	
		/* Limit the module o/p */
	HwTqChA_HwNwtMtr_T_f32 = Lim_f32(HwTqChA_HwNwtMtr_T_f32, HWTQMINLIM_HWNWTMTR_F32, HWTQMAXLIM_HWNWTMTR_F32);
	
	*Rte_Pim_HwTqPrevHwTq() = HwTqChA_HwNwtMtr_T_f32;	
		
	/*ENDREQ: ES228B #128 */
	/*ENDREQ: ES228B #98 */
	
	/* Write Module outputs */
	(void) Rte_Write_HwTq_Val(HwTqChA_HwNwtMtr_T_f32);
	
	 /* REQ: ES228B #85 */	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define HwTqArbn_STOP_SEC_CODE
#include "HwTqArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
* Name:        		SigAvlChkRev
* Description: 		Check availability of the signal based on 'RollingCounter', 'StallCounter' and 'SignalQualifier'.
* Inputs:      		SigRollgCntr_Cnt_T_u08       - Signal rolling counter
*              		SigQlfr_Cnt_T_enum		     - Signal qualifier	
*              		kMaxStallCnt_Cnt_T_u08	     - Max stall counter for the signal
* Inputs/Outputs:	*LstRollgCntr_Cnt_T_u08	     - Last rolling counter
*    				*StallCntr_Cnt_T_u08		 - Stall counter
* Outputs:          SigAvl_Cnt_T_logl   			 - Returns 'TRUE' when signal is available and 'FALSE' when not available.
* Usage Notes: 		None
**********************************************************************************************************************/
static FUNC(boolean, HwTqArbn_CODE) SigAvlChkRev( VAR(uint8,    AUTOMATIC) SigRollgCntr_Cnt_T_u08, 
												  VAR(SigQlfr1, AUTOMATIC) SigQlfr_Cnt_T_enum,
												  VAR(uint8,    AUTOMATIC) kMaxStallCnt_Cnt_T_u08,
												  P2VAR(uint8, AUTOMATIC, AUTOMATIC) LstRollgCntr_Cnt_T_u08,
												  P2VAR(uint8, AUTOMATIC, AUTOMATIC) StallCntr_Cnt_T_u08
												  )
{

	/* Temporary variable */
	VAR(boolean,  AUTOMATIC)  SigAvl_Cnt_T_logl;
	
	/* REQ: ES228A #91 I */
	
	if( SigRollgCntr_Cnt_T_u08 == (*LstRollgCntr_Cnt_T_u08) )
	{
		if( (*StallCntr_Cnt_T_u08) < MAXSTALLCNTR_CNT_U08 )
		{
			(*StallCntr_Cnt_T_u08) = (*StallCntr_Cnt_T_u08) + 1u;
		}
	}
	else
	{
		(*StallCntr_Cnt_T_u08) = 0u;
	}
	
	(*LstRollgCntr_Cnt_T_u08) = SigRollgCntr_Cnt_T_u08;
	
	
	if( (*StallCntr_Cnt_T_u08) >= kMaxStallCnt_Cnt_T_u08 )
	{
		SigAvl_Cnt_T_logl = FALSE;
	}
	else
	{
		if( SigQlfr_Cnt_T_enum < SIGQLFR_FAILD )
		{
			SigAvl_Cnt_T_logl = TRUE;
		}
		else
		{
			SigAvl_Cnt_T_logl = FALSE;
		}
	}
	
	
	return SigAvl_Cnt_T_logl;
	
	/* ENDREQ: ES228A #91 */
												  
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
