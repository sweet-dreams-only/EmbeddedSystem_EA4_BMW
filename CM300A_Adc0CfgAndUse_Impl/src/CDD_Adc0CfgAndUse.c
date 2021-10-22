/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Adc0CfgAndUse.c
 *     SW-C Type:  CDD_Adc0CfgAndUse
 *  Generated at:  Thu Jun  9 10:30:43 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Adc0CfgAndUse>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_Adc0CfgAndUse.c
* Module Description: Nxtr ADC0 Initialisation
* Project           : CBD
* Author            : Selva Sengottaiyan
***********************************************************************************************************************
* Version Control:
* %version:          4 %
* %derived_by:       nz4qtt %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 05/04/15  1        Selva      Initial Version                                                                EA4#492
* 02/04/16  2        Rijvi      Modify to support Adc Dynamic Diagnostic (Design rev. 2.0.0)                   EA4#3393
* 06/09/16  3        AJM        Removed the server runnable Adc0CfgAndUseAdc0ScanGroup1Cfg                     EA4#5915 
* 09/13/16  4        KK         Updates done in init (Design rev. 2.2.0)  									   EA4#7452 
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CDD_Adc0CfgAndUse.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include  "adcd_regs.h"
#include  "CDD_Adc0CfgAndUse.h"
#include  "CDD_Adc0CfgAndUse_Cfg.h"
/******************************************** File Level Rule Deviations *********************************************/
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
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_Adc0DiagcEndPtr(void)
 *   uint8 *Rte_Pim_Adc0DiagcStrtPtr(void)
 *
 *********************************************************************************************************************/


#define CDD_Adc0CfgAndUse_START_SEC_CODE
#include "CDD_Adc0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc0CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Adc0CfgAndUse_CODE) Adc0CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc0CfgAndUseInit1
 *********************************************************************************************************************/
    
    ADCD0VCR00 		=  ADC0CFGANDUSE_ADCD0VCR00_CNT_U32;  /*Virtual Channel Register 01*/   
	ADCD0VCR01 		=  ADC0CFGANDUSE_ADCD0VCR01_CNT_U32;  /*Virtual Channel Register 02*/   
	ADCD0VCR02 		=  ADC0CFGANDUSE_ADCD0VCR02_CNT_U32;  /*Virtual Channel Register 03*/   
	ADCD0VCR03 		=  ADC0CFGANDUSE_ADCD0VCR03_CNT_U32;  /*Virtual Channel Register 04*/   
	ADCD0VCR04 		=  ADC0CFGANDUSE_ADCD0VCR04_CNT_U32;  /*Virtual Channel Register 05*/   
	ADCD0VCR05 		=  ADC0CFGANDUSE_ADCD0VCR05_CNT_U32;  /*Virtual Channel Register 06*/   
	ADCD0VCR06 		=  ADC0CFGANDUSE_ADCD0VCR06_CNT_U32;  /*Virtual Channel Register 07*/   
	ADCD0VCR07 		=  ADC0CFGANDUSE_ADCD0VCR07_CNT_U32;  /*Virtual Channel Register 08*/   
	ADCD0VCR08 		=  ADC0CFGANDUSE_ADCD0VCR08_CNT_U32;  /*Virtual Channel Register 09*/   
	ADCD0VCR09 		=  ADC0CFGANDUSE_ADCD0VCR09_CNT_U32;  /*Virtual Channel Register 10*/   
	ADCD0VCR10 		=  ADC0CFGANDUSE_ADCD0VCR10_CNT_U32;  /*Virtual Channel Register 11*/   
	ADCD0VCR11 		=  ADC0CFGANDUSE_ADCD0VCR11_CNT_U32;  /*Virtual Channel Register 12*/   
	ADCD0VCR12 		=  ADC0CFGANDUSE_ADCD0VCR12_CNT_U32;  /*Virtual Channel Register 13*/   
	ADCD0VCR13 		=  ADC0CFGANDUSE_ADCD0VCR13_CNT_U32;  /*Virtual Channel Register 14*/   
	ADCD0VCR14 		=  ADC0CFGANDUSE_ADCD0VCR14_CNT_U32;  /*Virtual Channel Register 15*/   
	ADCD0VCR15 		=  ADC0CFGANDUSE_ADCD0VCR15_CNT_U32;  /*Virtual Channel Register 16*/   
	ADCD0VCR16 		=  ADC0CFGANDUSE_ADCD0VCR16_CNT_U32;  /*Virtual Channel Register 17*/   
	ADCD0VCR17 		=  ADC0CFGANDUSE_ADCD0VCR17_CNT_U32;  /*Virtual Channel Register 18*/   
	ADCD0VCR18 		=  ADC0CFGANDUSE_ADCD0VCR18_CNT_U32;  /*Virtual Channel Register 19*/   
	ADCD0VCR19 		=  ADC0CFGANDUSE_ADCD0VCR19_CNT_U32;  /*Virtual Channel Register 20*/   
	ADCD0VCR20 		=  ADC0CFGANDUSE_ADCD0VCR20_CNT_U32;  /*Virtual Channel Register 21*/   
	ADCD0VCR21 		=  ADC0CFGANDUSE_ADCD0VCR21_CNT_U32;  /*Virtual Channel Register 22*/   
	ADCD0VCR22 		=  ADC0CFGANDUSE_ADCD0VCR22_CNT_U32;  /*Virtual Channel Register 23*/   
	ADCD0VCR23  	=  ADC0CFGANDUSE_ADCD0VCR23_CNT_U32;  /*Virtual Channel Register 24*/   
	ADCD0SUSMTD		=  0U;                                /* Synchronous suspend - By design ADC groups shouldn't collide  */            /*  AD Control Register 1: Suspend Method     */   
	ADCD0ADDNT 		=  0U;                                /* Feature not used                                              */            /*  AD Control Register 2: Addition Count Select     */  
	ADCD0DFMT  		=  1U;                                /* 1: Signed integer format                                      */            /*  AD Control Register 2: Data Format     */   
	ADCD0IDEIE 		=  0U;                                /* ID Error Interrupt - Disabled                                 */            /*  ID error interrupt Enable     */   
	ADCD0PEIE  		=  0U;                                /* Parity Error Interrupt - Disabled                             */            /*  Parity error interrupt Enable     */   
	ADCD0OWEIE 		=  0U;                                /* Overwrite Error Interrupt - Disabled                          */            /*  Overwrite error interrupt Enable     */ 
	ADCD0ULEIE 		=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */            /*  Upper-Limit/Lower-Limit Error Interrupt Enable */ 
	ADCD0RDCLRE		=  1U;                                /* Perform read and clear                                        */             /*  Read and Clear Enable     */   
	ADCD0ULLMTBR0 	=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */             /*  Upper-Limit/Lower-Limit Table Registers 0    */   
	ADCD0ULLMTBR1 	=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */             /*  Upper-Limit/Lower-Limit Table Registers 1    */   
	ADCD0ULLMTBR2 	=  0U;                                /* Upper-limit/lower-limit Error Interrupt - Disabled            */             /*  Upper-Limit/Lower-Limit Table Registers 2    */ 
	ADCD0ODCR    	=  0U;                                /* Wiring break detection - not diagnosed                        */             /*  Wiring Break Detection Control Register       */   
	ADCD0ADOPDIG0	=  0U;                                /* 0: Pulling up or pulling down the ADCDnIm pin is disabled     */             /*  Wiring-break Detection Pin Setting Register    */  
	ADCD0THCR    	=  0U;                                /* Transfer and Hold is not used                                 */             /*  T&H Control Register    */  
	ADCD0THACR   	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group A Control Register*/   
	ADCD0THBCR   	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group B Control Register*/   
	ADCD0THER    	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group B Enable Register*/   
	ADCD0THGSR   	=  0U;                                /* Transfer and Hold is not used                                 */             /* T&H Group B Saftey Register*/ 
	ADCD0SGSTCR0	=  0U;                                /* Not used, performs software start of Scan Group               */             /* Scan Group 0 Start Control Register*/ 
	ADCD0SGCR0		=  0U;                                /* Scan Group 0 Control Register*/   
	ADCD0SGVCSP0 	=  0U;                                /* Start pointer for Group 0 is fixed at 0 (minimum)             */             /* Scan Group 0 Start Virtual Channel Pointer*/  
	ADCD0SGVCEP0 	=  23U;                               /* End pointer for Group 0 is fixed at 23 (maximum)              */             /* Scan Group 0 End Virtual Channel Pointer*/  
	ADCD0SGMCYCR0 	=  0U;                                /* Perform scan group reads only once                            */             /* Scan Group 0 Synchronization Start Enable*/  
	ADCD0ULLMSR0 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */             /* Scan group 0 upper-limit/lower-limit table select register 0*/   
	ADCD0SGSTCR1 	=  0U;                                /* Not used, performs software start of Scan Group               */             /* Scan group 0 start control register 1*/   
	ADCD0SGCR1   	=  1U;                                /* Don't trigger DMA                                             */            /* Scan group 0 control register 1 */  
	ADCD0SGVCSP1 	=  21U;                               /* Configured to be start of ADC Reference voltage group         */            /* Scan group 0 start virtual channel pointer 1 */   
	ADCD0SGVCEP1 	=  23U;                               /* Configured to be end of ADC Reference voltage group           */            /* Scan group 0 start virtual channel pointer 1 */   
	ADCD0SGMCYCR1	=  0U;                                /* Perform scan group reads only once                            */            /* Scan group 0 multicycle register 1*/  
	ADCD0ULLMSR1 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */            /* Scan group 0 upper-limit/lower-limit table select register 1*/  
	ADCD0SGSTCR2 	=  0U;                                /* Not used, performs software start of Scan Group               */            /* Scan group 0 start control register 2*/   
	ADCD0SGCR2   	=  1U;                                /*     Don't trigger DMA                                         */            /* Scan group 0 control register 2*/ 
	ADCD0SGVCSP2 	=  ADC0CFGANDUSE_ADCD0SGVCSP2_CNT_U08;/* Scan group 0 start virtual channel pointer 2*/ 
	ADCD0SGVCEP2 	=  ADC0CFGANDUSE_ADCD0SGVCEP2_CNT_U08;/* Scan group 0 start virtual channel pointer 2*/  
	ADCD0SGMCYCR2	=  0U;                                /* Perform scan group reads only once                            */           /* Scan group 0 multicycle register 2*/                 
	ADCD0ULLMSR2 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */           /* Scan group 0 upper-limit/lower-limit table select register 2*/   
	ADCD0SGSTCR3 	=  0U;                                /* Not used, performs software start of Scan Group               */           /* Scan group 0 start control register 3*/ 
	ADCD0SGCR3   	=  17U;                               /* Used to trigger DMA                                           */           /* Scan group 0 control register 3*/  
	ADCD0SGVCSP3 	=  ADC0CFGANDUSE_ADCD0SGVCSP3_CNT_U08;/* Scan group 0 start virtual channel pointer 3*/ 
	ADCD0SGVCEP3 	=  ADC0CFGANDUSE_ADCD0SGVCEP3_CNT_U08;/* Scan group 0 start virtual channel pointer 3*/ 
	ADCD0SGMCYCR3	=  0U;                                /* Perform scan group reads only once                            */            /* Scan group 0 multicycle register 3*/     
	ADCD0ULLMSR3 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */            /* Scan group 0 upper-limit/lower-limit table select register 3*/ 
	ADCD0SGSTCR4 	=  0U;                                /* Not used, performs software start of Scan Group               */            /* Scan group 0 start control register 4*/ 
	ADCD0SGCR4   	=  0U;                                /* Scan Group 4 is not used                                      */            /* Scan group 0 control register 4*/ 
	ADCD0SGVCSP4 	=  23U;                               /* Scan Group 4 is not used                                      */            /* Scan group 0 start virtual channel pointer 4*/ 
	ADCD0SGVCEP4 	=  23U;                               /* Scan Group 4 is not used                                      */            /* Scan group 0 start virtual channel pointer 4*/ 
	ADCD0SGMCYCR4	=  0U;                                /* Perform scan group reads only once                            */            /* Scan group 0 multicycle register 4*/    
	ADCD0ULLMSR4 	=  0U;                                /* 0H: Neither upper limit nor lower limit is checked.           */            /* Scan group 0 upper-limit/lower-limit table select register 4*/ 
    
	/* REQ: CM300A #84 I */
	ADCD0SGSTCR0 	= 1U; 								  /* SW Trigger Scan Group 0 */     

	*Rte_Pim_Adc0DiagcStrtPtr()	= ADC0CFGANDUSE_DIAGCSCANGROUPMIN_CNT_U08;
	*Rte_Pim_Adc0DiagcEndPtr()	= ADC0CFGANDUSE_DIAGCSCANGROUPMAX_CNT_U08;
 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_Adc0CfgAndUse_STOP_SEC_CODE
#include "CDD_Adc0CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
