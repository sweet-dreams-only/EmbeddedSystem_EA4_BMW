/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_MotAg3Meas.c
 *        Config:  C:/Users/NZ5334/Documents/Synergy/Working/ses_dev_ea4/CM510A_MotAg3Meas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_MotAg3Meas
 *  Generated at:  Thu Mar 29 12:09:32 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_MotAg3Meas>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/*************************************************************************************************************
* Copyright 2016, 2017, 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_MotAg3Meas.c
* Module Description: Implements the measurement function of MotorAngle3.
*                     Includes configuration and use of the ENCA peripheral.
* Project           : CBD
* Author            : Shruthi Raghavan
*****************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       nz5334 %
*-----------------------------------------------------------------------------------------------------------------
* Date          Rev     Author                          Change Description                            	 SCR #
* ----------   ------  --------  -------------------------------------------------------------------	----------
* 11/01/2016    1        SR        Initial Implementation of CM510A according to FDD v1.2.0         	 EA4#7579
* 02/21/2018    2        GS(TATA)  Added left shift operation instead of Bitwise AND for MotAg3Calcn     EA4#17182
*************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * u0p16
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Port Prototypes:
 * ================
 * MotAgMecl3Polarity
 *   Polarity value of Motor Angle 3
 *
 *
 * Runnable Entities:
 * ==================
 * MotAg3MeasInit1
 *   Initial Function for Motor Angle 3 Measurement
 *
 *********************************************************************************************************************/

#include "Rte_CDD_MotAg3Meas.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* -----[ File Includes ]------------------------------ */
 #include "CDD_MotAg3Meas.h"
 #include "enca_regs.h"
 #include "CDD_MotAg3Meas_Cfg.h"
 
 /* -----[ MISRA Deviation Comments ]------------------- */
 /* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE_Read function */
 /* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1 ]: AUTOSAR requires deviation from this rule for Memory Mapping include statements   */
 
 /* -----[ Local Constant Definitions ]----------------- */
 #define MOTAGLIM_CNT_U16                       ((uint16)65535U)
                                                
 #define REGENCA0CTLINITVAL_CNT_U16             ((uint16)0x03U)
 #define REGENCA0IOC1INITVAL_CNT_U08            ((uint8)0x04U)
                                                
 #define REGENCA0TTINITVAL_CNT_U08              ((uint8)0x01U)
 #define REGENCA0TSINITVAL_CNT_U08              ((uint8)0x01U)

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
 * sint8: Integer in interval [-128...127] (standard type)
 * u0p16: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 *********************************************************************************************************************/


#define CDD_MotAg3Meas_START_SEC_CODE
#include "CDD_MotAg3Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMotAg3Mecl_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetMotAg3Mecl>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAgMecl3Polarity_Val(sint8 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetMotAg3Mecl_Oper(u0p16 *MotAgMecl_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMotAg3Mecl_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg3Meas_CODE) GetMotAg3Mecl_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG3MEAS_APPL_VAR) MotAgMecl_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMotAg3Mecl_Oper
 *********************************************************************************************************************/

 /* -----[ Inputs ]------------------------------------- */
 VAR(uint16, AUTOMATIC) EncATmrCntr_Cnt_T_u16;
 VAR(sint8 , AUTOMATIC) MotAgMecl3Polarity_Uls_T_s08;

 /* -----[ Temporary Variables ]------------------------ */
 VAR(u0p16, AUTOMATIC) MotAg3Raw_Cnt_T_u0p16;

 /* -----[ Read Inputs ]-------------------------------- */
 EncATmrCntr_Cnt_T_u16 = ENCA0CNT; /*To ensure no unintended modification of register*/
 (void)Rte_Read_MotAgMecl3Polarity_Val(&MotAgMecl3Polarity_Uls_T_s08); 

 /* -----[ Processing ]--------------------------------- */

 /*Block: MotAg3Calcn*/
 MotAg3Raw_Cnt_T_u0p16 = (uint16)(EncATmrCntr_Cnt_T_u16 << MOTAG3_SNSRRLVBITWIDTHEXP_CNT_U08);
 /*Sub-block: Polarity
  *ENCA Counter is opposite to SPI's Internal Counter.*/
 if(MotAgMecl3Polarity_Uls_T_s08 < 0)
 {
    /** Negative Polarity **/
	*MotAgMecl_Arg = (MOTAGLIM_CNT_U16 - MotAg3Raw_Cnt_T_u0p16);
 }
 else
 {
    /** Positive Polarity **/
	*MotAgMecl_Arg = MotAg3Raw_Cnt_T_u0p16;
 }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg3MeasInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg3MeasInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg3Meas_CODE) MotAg3MeasInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg3MeasInit1
 *********************************************************************************************************************/

 /* -----[ Initialize ENCA Registers ]-------------------- */
 
 /*Stop Counter*/
 ENCA0TT       = REGENCA0TTINITVAL_CNT_U08;
 
 /*Configure operation settings of encoder timer*/
 ENCA0CTL      = REGENCA0CTLINITVAL_CNT_U16;

 /*Enable Rising Edge Detection and Clear counter on valid edge*/
 ENCA0IOC1     = REGENCA0IOC1INITVAL_CNT_U08;

 /*Enable Counter and Set to Operation*/
 ENCA0TS       = REGENCA0TSINITVAL_CNT_U08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_MotAg3Meas_STOP_SEC_CODE
#include "CDD_MotAg3Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
