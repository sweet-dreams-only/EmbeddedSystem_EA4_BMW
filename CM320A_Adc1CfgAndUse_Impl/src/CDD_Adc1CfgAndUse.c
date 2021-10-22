/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Adc1CfgAndUse.c
 *        Config:  C:/Users/nz3541/Documents/SynergyWorkingEA4/CM320A_Adc1CfgAndUse_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_Adc1CfgAndUse
 *  Generated at:  Fri Nov 17 09:51:17 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Adc1CfgAndUse>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2015, 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_Adc1CfgAndUse.c
* Module Description: Nxtr ADC1 
* Project           : CBD
* Author            : Selva Sengottaiyan
***********************************************************************************************************************
* Version Control:
* %version:          7 %
* %derived_by:       nz3541 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 05/04/15  1        Selva      Initial Version                                                                EA4#494
* 06/22/15  2 		 Nick S.	Update per new FDD															   EA4#878
* 02/08/16  3        Rijvi      Modify to support Adc Dynamic Diagnostic (Design rev. 2.0.0)                  EA4#3397
* 06/09/16  4		 AJM		Added Periodic 2 and removed the server runnable 							  EA4#5948
*                               Adc1CfgAndUseAdc1ScanGroup1Cfg
* 09/13/16  5        KK         Updates done in init (Design rev. 2.3.0)  									  EA4#7453
* 11/16/17  7        SPP        Removed application data types                                               EA4#17531
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CDD_Adc1CfgAndUse.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include  "adcd_regs.h"
#include  "CDD_Adc1CfgAndUse.h"
#include  "CDD_Adc0CfgAndUse.h"
#include  "CDD_Adc1CfgAndUse_Cfg.h"
/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return values for Rte_Read_* */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/
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
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_Adc1DiagcEndPtr(void)
 *   uint8 *Rte_Pim_Adc1DiagcStrtPtr(void)
 *
 *********************************************************************************************************************/


#define CDD_Adc1CfgAndUse_START_SEC_CODE
#include "CDD_Adc1CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUseAdc1EnaCnvn_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <Adc1CfgAndUseAdc1EnaCnvn>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Adc1CfgAndUseAdc1EnaCnvn_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseAdc1EnaCnvn_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUseAdc1EnaCnvn_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseAdc1EnaCnvn_Oper
 *********************************************************************************************************************/
 /*Enables scan groups*/
 
 ADCD1SGCR3   =  1U; 
 ADCD1SGCR2   =  1U; 
 ADCD1SGCR1   =  17U; 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUseInit1
 *********************************************************************************************************************/
    
    ADCD1VCR00 		=  ADC1CFGANDUSE_ADCD1VCR00_CNT_U32;  /*Virtual Channel Register 01*/
	ADCD1VCR01 		=  ADC1CFGANDUSE_ADCD1VCR01_CNT_U32;  /*Virtual Channel Register 02*/
	ADCD1VCR02 		=  ADC1CFGANDUSE_ADCD1VCR02_CNT_U32;  /*Virtual Channel Register 03*/
	ADCD1VCR03 		=  ADC1CFGANDUSE_ADCD1VCR03_CNT_U32;  /*Virtual Channel Register 04*/
	ADCD1VCR04 		=  ADC1CFGANDUSE_ADCD1VCR04_CNT_U32;  /*Virtual Channel Register 05*/
	ADCD1VCR05 		=  ADC1CFGANDUSE_ADCD1VCR05_CNT_U32;  /*Virtual Channel Register 06*/
	ADCD1VCR06 		=  ADC1CFGANDUSE_ADCD1VCR06_CNT_U32;  /*Virtual Channel Register 07*/
	ADCD1VCR07 		=  ADC1CFGANDUSE_ADCD1VCR07_CNT_U32;  /*Virtual Channel Register 08*/
	ADCD1VCR08 		=  ADC1CFGANDUSE_ADCD1VCR08_CNT_U32;  /*Virtual Channel Register 09*/
	ADCD1VCR09 		=  ADC1CFGANDUSE_ADCD1VCR09_CNT_U32;  /*Virtual Channel Register 10*/
	ADCD1VCR10 		=  ADC1CFGANDUSE_ADCD1VCR10_CNT_U32;  /*Virtual Channel Register 11*/
	ADCD1VCR11 		=  ADC1CFGANDUSE_ADCD1VCR11_CNT_U32;  /*Virtual Channel Register 12*/
	ADCD1VCR12 		=  ADC1CFGANDUSE_ADCD1VCR12_CNT_U32;  /*Virtual Channel Register 13*/
	ADCD1VCR13 		=  ADC1CFGANDUSE_ADCD1VCR13_CNT_U32;  /*Virtual Channel Register 14*/
	ADCD1VCR14 		=  ADC1CFGANDUSE_ADCD1VCR14_CNT_U32;  /*Virtual Channel Register 15*/
	ADCD1VCR15 		=  ADC1CFGANDUSE_ADCD1VCR15_CNT_U32;  /*Virtual Channel Register 16*/
	ADCD1VCR16 		=  ADC1CFGANDUSE_ADCD1VCR16_CNT_U32;  /*Virtual Channel Register 17*/
	ADCD1VCR17 		=  ADC1CFGANDUSE_ADCD1VCR17_CNT_U32;  /*Virtual Channel Register 18*/
	ADCD1VCR18 		=  ADC1CFGANDUSE_ADCD1VCR18_CNT_U32;  /*Virtual Channel Register 19*/
	ADCD1VCR19 		=  ADC1CFGANDUSE_ADCD1VCR19_CNT_U32;  /*Virtual Channel Register 20*/
	ADCD1VCR20 		=  ADC1CFGANDUSE_ADCD1VCR20_CNT_U32;  /*Virtual Channel Register 21*/
	ADCD1VCR21 		=  ADC1CFGANDUSE_ADCD1VCR21_CNT_U32;  /*Virtual Channel Register 22*/
	ADCD1VCR22 		=  ADC1CFGANDUSE_ADCD1VCR22_CNT_U32;  /*Virtual Channel Register 23*/
	ADCD1VCR23 		=  ADC1CFGANDUSE_ADCD1VCR23_CNT_U32;  /*Virtual Channel Register 24*/
	ADCD1SUSMTD		=  0U;                                /* Synchronous suspend - By design ADC groups shouldn't collide  */            /*  AD Control Register 1: Suspend Method     */
	ADCD1ADDNT 		=  0U;                                /* Feature not used                                              */            /*  AD Control Register 2: Addition Count Select     */
	ADCD1DFMT  		=  1U;                                /* 1: Signed integer format                                      */            /*  AD Control Register 2: Data Format     */
	ADCD1IDEIE 		=  0U;                                /* ID Error Interrupt - Disabled                                 */            /*  ID error interrupt Enable     */
	ADCD1PEIE  		=  0U;                                /* Parity Error Interrupt - Disabled                             */            /*  Parity error interrupt Enable     */
	ADCD1OWEIE 		=  0U;                                /* Overwrite Error Interrupt - Disabled                          */            /*  Overwrite error interrupt Enable     */
	ADCD1ULEIE 		=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */            /*  Upper-Limit/Lower-Limit Error Interrupt Enable */
	ADCD1RDCLRE		=  1U;                                /* Perform read and clear                                        */             /*  Read and Clear Enable     */
	ADCD1ULLMTBR0 	=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */             /*  Upper-Limit/Lower-Limit Table Registers 0    */
	ADCD1ULLMTBR1 	=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */             /*  Upper-Limit/Lower-Limit Table Registers 1    */
	ADCD1ULLMTBR2 	=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */             /*  Upper-Limit/Lower-Limit Table Registers 2    */
	ADCD1ODCR    	=  0U;                                /* Wiring break detection - not diagnosed                        */             /*  Wiring Break Detection Control Register       */
	ADCD1ADOPDIG1	=  0U;                                /* 0: Pulling up or pulling down the ADCDnIm pin is disabled     */  /*?*/       /*  Wiring-break Detection Pin Setting Register    */  
	ADCD1THCR    	=  0U;                                /* Transfer and Hold is not used                                 */             /*  T&H Control Register    */  
	ADCD1THACR   	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group A Control Register*/
	ADCD1THBCR   	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group B Control Register*/
	ADCD1THER    	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group B Enable Register*/
	ADCD1THGSR   	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group B Saftey Register*/
	ADCD1SGSTCR0	=  0U;                                /* Not used, performs software start of Scan Group               */             /* Scan Group 0 Start Control Register*/
	ADCD1SGCR0		=  0U;                                /* Scan Group 0 Control Register*/
	ADCD1SGVCSP0 	=  0U;                                /* Start pointer for Group 0 is fixed at 0 (minimum)             */             /* Scan Group 0 Start Virtual Channel Pointer*/
	ADCD1SGVCEP0 	=  23U;                               /* End pointer for Group 0 is fixed at 23 (maximum)              */             /* Scan Group 0 End Virtual Channel Pointer*/
	ADCD1SGMCYCR0 	=  0U;                                /* Perform scan group reads only once                            */             /* Scan Group 0 Synchronization Start Enable*/
	ADCD1ULLMSR0 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */             /* Scan group 0 upper-limit/lower-limit table select register 0*/
	ADCD1SGSTCR1 	=  0U;                                /* Not used, performs software start of Scan Group               */             /* Scan group 0 start control register 1*/
	ADCD1SGCR1   	=  1U;                                /* Don't trigger DMA                                             */            /* Scan group 0 control register 1 */
	ADCD1SGVCSP1 	=  21U;                               /* Configured to be start of ADC Reference voltage group         */            /* Scan group 0 start virtual channel pointer 1 */
	ADCD1SGVCEP1 	=  23U;                               /* Configured to be end of ADC Reference voltage group           */            /* Scan group 0 start virtual channel pointer 1 */
	ADCD1SGMCYCR1	=  0U;                                /* Perform scan group reads only once                            */            /* Scan group 0 multicycle register 1*/
	ADCD1ULLMSR1 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */            /* Scan group 0 upper-limit/lower-limit table select register 1*/
	ADCD1SGSTCR2 	=  0U;                                /* Not used, performs software start of Scan Group               */            /* Scan group 0 start control register 2*/
	ADCD1SGCR2   	=  1U;                                /*     Don't trigger DMA                                         */            /* Scan group 0 control register 2*/
	ADCD1SGVCSP2 	=  ADC1CFGANDUSE_ADCD1SGVCSP2_CNT_U08;/* Scan group 0 start virtual channel pointer 2*/
	ADCD1SGVCEP2 	=  ADC1CFGANDUSE_ADCD1SGVCEP2_CNT_U08;/* Scan group 0 start virtual channel pointer 2*/
	ADCD1SGMCYCR2	=  0U;                                /* Perform scan group reads only once                            */           /* Scan group 0 multicycle register 2*/                 
	ADCD1ULLMSR2 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */           /* Scan group 0 upper-limit/lower-limit table select register 2*/
	ADCD1SGSTCR3 	=  0U;                                /* Not used, performs software start of Scan Group               */           /* Scan group 0 start control register 3*/
	ADCD1SGCR3   	=  17U;                               /* Used to trigger DMA                                           */           /* Scan group 0 control register 3*/
	ADCD1SGVCSP3 	=  ADC1CFGANDUSE_ADCD1SGVCSP3_CNT_U08;/* Scan group 0 start virtual channel pointer 3*/
	ADCD1SGVCEP3 	=  ADC1CFGANDUSE_ADCD1SGVCEP3_CNT_U08;/* Scan group 0 start virtual channel pointer 3*/
	ADCD1SGMCYCR3	=  0U;                                /* Perform scan group reads only once                            */            /* Scan group 0 multicycle register 3*/     
	ADCD1ULLMSR3 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */            /* Scan group 0 upper-limit/lower-limit table select register 3*/ 
	ADCD1SGSTCR4 	=  0U;                                /* Not used, performs software start of Scan Group               */            /* Scan group 0 start control register 4*/
	ADCD1SGCR4   	=  0U;                                /* Scan Group 4 is not used                                      */            /* Scan group 0 control register 4*/
	ADCD1SGVCSP4 	=  23U;                               /* Scan Group 4 is not used                                      */            /* Scan group 0 start virtual channel pointer 4*/
	ADCD1SGVCEP4 	=  23U;                               /* Scan Group 4 is not used                                      */            /* Scan group 0 start virtual channel pointer 4*/
	ADCD1SGMCYCR4	=  0U;                                /* Perform scan group reads only once                            */            /* Scan group 0 multicycle register 4*/    
	ADCD1ULLMSR4 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */            /* Scan group 0 upper-limit/lower-limit table select register 4*/
    
    
	ADCD1SGSTCR0 	=  1U; 								  /* SW Trigger Scan Group 0 */  
	
	*Rte_Pim_Adc1DiagcStrtPtr()	= ADC0CFGANDUSE_DIAGCSCANGROUPMIN_CNT_U08;
	*Rte_Pim_Adc1DiagcEndPtr()	= ADC0CFGANDUSE_DIAGCSCANGROUPMAX_CNT_U08;
 
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUsePer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUsePer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer1
 *********************************************************************************************************************/
/*Disables scan groups, write in out1 order */
 ADCD1SGCR1   =  0U; 
 ADCD1SGCR2   =  0U; 
 ADCD1SGCR3   =  0U; 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc1CfgAndUsePer2
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
 *   Std_ReturnType Rte_Read_AdcDiagcEndPtrOutp_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_AdcDiagcStrtPtrOutp_Val(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_Adc1CfgAndUse_CODE) Adc1CfgAndUsePer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc1CfgAndUsePer2
 *********************************************************************************************************************/
	VAR (uint8, AUTOMATIC) AdcDiagcStrtPtrOutp_Cnt_T_u08;
	VAR (uint8, AUTOMATIC) AdcDiagcEndPtrOutp_Cnt_T_u08;
	
	/* Read the inputs */
	(void)Rte_Read_AdcDiagcStrtPtrOutp_Val(&AdcDiagcStrtPtrOutp_Cnt_T_u08);
	(void)Rte_Read_AdcDiagcEndPtrOutp_Val(&AdcDiagcEndPtrOutp_Cnt_T_u08);
	
	if((AdcDiagcStrtPtrOutp_Cnt_T_u08 != *Rte_Pim_Adc1DiagcStrtPtr()) ||
		(AdcDiagcEndPtrOutp_Cnt_T_u08 != *Rte_Pim_Adc1DiagcEndPtr()))
	{
		/* Validity Check */
		if( (AdcDiagcStrtPtrOutp_Cnt_T_u08 >= ADC0CFGANDUSE_DIAGCSCANGROUPMIN_CNT_U08) && 
		(AdcDiagcStrtPtrOutp_Cnt_T_u08 <= ADC0CFGANDUSE_DIAGCSCANGROUPMAX_CNT_U08) && 
		(AdcDiagcEndPtrOutp_Cnt_T_u08 >= ADC0CFGANDUSE_DIAGCSCANGROUPMIN_CNT_U08)  && 
		(AdcDiagcEndPtrOutp_Cnt_T_u08 <= ADC0CFGANDUSE_DIAGCSCANGROUPMAX_CNT_U08)  && 
		(AdcDiagcStrtPtrOutp_Cnt_T_u08 <= AdcDiagcEndPtrOutp_Cnt_T_u08) 		   &&
		(ADCD1SGSR1 == 0U))
		{
			/* Update Scan Group 1 Start and End Pointer */
			ADCD1SGVCSP1 = AdcDiagcStrtPtrOutp_Cnt_T_u08; 
			ADCD1SGVCEP1 = AdcDiagcEndPtrOutp_Cnt_T_u08; 
			
			*Rte_Pim_Adc1DiagcEndPtr() = AdcDiagcEndPtrOutp_Cnt_T_u08;
			*Rte_Pim_Adc1DiagcStrtPtr() = AdcDiagcStrtPtrOutp_Cnt_T_u08;
		}
		else
		{
			/* Empty Else */
		}
	}
	else
	{
		/* Empty Else */
	}

 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_Adc1CfgAndUse_STOP_SEC_CODE
#include "CDD_Adc1CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
