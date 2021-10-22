/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BattVltg.c
 *        Config:  C:/Users/nz3893/Documents/Synergy/EA4/Working/ES250B_BattVltg_Impl/tools/Component.dpa
 *     SW-C Type:  BattVltg
 *  Generated at:  Wed Sep 27 14:07:39 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BattVltg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Copyright 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : BattVltg.c
* Module Description: Implementation of Battery Voltage measurement for single inverter design (ES250B)
* Project           : CBD 
* Author            : Nick Saxton
***********************************************************************************************************************
* Version Control:
* %version          : 2 %
* %derived_by       : nz3893 %
*-------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                            SCR #
* --------  -------  --------  --------------------------------------------------------------------------   --------
* 05/18/16  1        NS        Initial Version                                                          	EA4#5643  
* 09/25/17  2        BLS       Removed BattVltgPrevBattVltg PIM and associated logic                        EA4#15563
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_BattVltg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrMath.h"
 
/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Read_*, Rte_Write_* */
/* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1]:  AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/******************************************** Embedded Local Constants ***********************************************/
#define BRDGFLTVLTG_VOLT_F32    18.0F
#define BRDGVLTGMAX_VOLT_F32    26.5F
#define BRDGVLTGMIN_VOLT_F32    6.0F

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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define BattVltg_START_SEC_CODE
#include "BattVltg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattVltgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BattVltgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BattVltg_CODE) BattVltgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BattVltgInit1
 *********************************************************************************************************************/
    /* Empty init function */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattVltgPer1
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
 *   Std_ReturnType Rte_Read_BattSwdVltgCorrlnSts_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_BattVltg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BattVltgSwd1_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BrdgVltg_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BattVltgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BattVltg_CODE) BattVltgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BattVltgPer1
 *********************************************************************************************************************/
    /* Inputs */
    VAR(uint8  , AUTOMATIC) BattSwdVltgCorrlnSts_Cnt_T_u08;
    VAR(float32, AUTOMATIC) BattVltg_Volt_T_f32;
    VAR(float32, AUTOMATIC) BattVltgSwd1_Volt_T_f32;
    
    /* Output */
    VAR(float32, AUTOMATIC) BrdgVltg_Volt_T_f32;
    
    /*** Read inputs ***/
    (void)Rte_Read_BattSwdVltgCorrlnSts_Val(&BattSwdVltgCorrlnSts_Cnt_T_u08);
    (void)Rte_Read_BattVltg_Val(&BattVltg_Volt_T_f32);
    (void)Rte_Read_BattVltgSwd1_Val(&BattVltgSwd1_Volt_T_f32);
    
    switch (BattSwdVltgCorrlnSts_Cnt_T_u08)
    {
        /* BattSwdVltgCorrlnSts = 2 */
        case 2U:
            BrdgVltg_Volt_T_f32 = BattVltgSwd1_Volt_T_f32;
            break;
        
        /* BattSwdVltgCorrlnSts = 1 */
        case 1U:
            BrdgVltg_Volt_T_f32 = BattVltg_Volt_T_f32;
            break;
         
        /* BattSwdVltgCorrlnSts = No Correlation */    
        default:
            BrdgVltg_Volt_T_f32 = BRDGFLTVLTG_VOLT_F32;
            break;
    }
    
    /*** Limit output ***/
    BrdgVltg_Volt_T_f32 = Lim_f32(BrdgVltg_Volt_T_f32, BRDGVLTGMIN_VOLT_F32, BRDGVLTGMAX_VOLT_F32);
    
    /*** Write output ***/
    (void)Rte_Write_BrdgVltg_Val(BrdgVltg_Volt_T_f32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BattVltg_STOP_SEC_CODE
#include "BattVltg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
