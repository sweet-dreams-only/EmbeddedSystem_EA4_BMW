/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot315Bas0Repn1BusFrChA.c
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/MM530A_BmwMsgSlot315Bas0Repn1BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot315Bas0Repn1BusFrChA
 *  Generated at:  Fri May 18 09:12:45 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot315Bas0Repn1BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright 2018 Nxtr
* Nxtr Confidential
*
* Module File Name:   BmwMsgSlot315Bas0Repn1BusFrChA.c
* Module Description: BMW Message Slot 315 Base 0 Repetition 1 Bus FlexRay Channel A Processing (MM530A)
* Project           : CBD
* Author            : Brendon Binder
************************************************************************************************************************
* Version Control:
* %version:         2 %
* %derived_by:      nz3734 %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 04/24/18  1        BRB       Initial file creation                                                        EA4#23092
* 05/18/18  2        BRB       Update SYS_ST_EPS datatype and init values                                   EA4#24009
***********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

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
 * BmwVehCdn1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SysSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot315Bas0Repn1BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "NxtrMath.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE reads and writes */

#define VEHSPDEPSSCA_KPHPERCNT_F32                  (0.015625F)
#define VEHSPDEPSLOLIM_KPH_F32                      (0.0F)
#define VEHSPDEPSHILIM_KPH_F32                      (350.0F)
#define BATTVLTGEPSSCA_VOLTPERCNT_F32               (0.0005F)
#define BATTVLTGEPSOFFS_VOLT_F32                    (6.0F)
#define BATTVLTGEPSLOLIM_VOLT_F32                   (6.0F)
#define BATTVLTGEPSHILIM_VOLT_F32                   (26.5F)
#define ESTIMDPEAKMOTCURREPSSCA_AMPRSQDPERCNT_F32   (0.005F)
#define ESTIMDPEAKMOTCURREPSLOLIM_AMPRSQD_F32       (0.0F)
#define ESTIMDPEAKMOTCURREPSHILIM_AMPRSQD_F32       (62500.0F)  
#define MOTVELEPSSCA_MOTRADPERSECPERCNT_F32         (0.05F)
#define MOTVELEPSOFFS_MOTRADPERSEC_F32              (1350.0F)
#define MOTVELEPSLOLIM_MOTRADPERSEC_F32             (-1350.0F)
#define MOTVELEPSHILIM_MOTRADPERSEC_F32             (1350.0F)
#define MOTTQCMDLIMDEPSSCA_MOTNWTMTRPERCNT_F32      (0.01F)
#define MOTTQCMDLIMDEPSOFFS_MOTNWTMTR_F32           (8.8F)
#define MOTTQCMDLIMDEPSLOLIM_MOTNWTMTR_F32          (-8.8F)
#define MOTTQCMDLIMDEPSHILIM_MOTNWTMTR_F32          (8.8F)
#define PRIMHWTQSNSRVLTGEPSSCA_VOLTPERCNT_F32       (0.025F)
#define PRIMHWTQSNSRVLTGEPSLOLIM_VOLT_F32           (0.0F)
#define PRIMHWTQSNSRVLTGEPSHILIM_VOLT_F32           (5.0F)
#define SECDRYHWTQSNSRVLTGEPSSCA_VOLTPERCNT_F32     (0.025F)
#define SECDRYHWTQSNSRVLTGEPSLOLIM_VOLT_F32         (0.0F)
#define SECDRYHWTQSNSRVLTGEPSHILIM_VOLT_F32         (5.0F)
#define ECUTEMPEPSOFFS_DEGCGRD_F32                  (50.0F)
#define ECUTEMPEPSLOLIM_DEGCGRD_F32                 (-50.0F)
#define ECUTEMPEPSHILIM_DEGCGRD_F32                 (150.0F)
#define MOTFETTEMPEPSOFFS_DEGCGRD_F32               (50.0F)
#define MOTFETTEMPEPSLOLIM_DEGCGRD_F32              (-50.0F)
#define MOTFETTEMPEPSHILIM_DEGCGRD_F32              (200.0F)
#define MOTMAGTEMPEPSOFFS_DEGCGRD_F32               (50.0F)
#define MOTMAGTEMPEPSLOLIM_DEGCGRD_F32              (-50.0F)
#define MOTMAGTEMPEPSHILIM_DEGCGRD_F32              (150.0F)
#define MOTWIDGTEMPEPSOFFS_DEGCGRD_F32              (50.0F)
#define MOTWIDGTEMPEPSLOLIM_DEGCGRD_F32             (-50.0F)
#define MOTWIDGTEMPEPSHILIM_DEGCGRD_F32             (300.0F)
#define MOTTQCMDEPSSCA_MOTNWTMTRPERCNT_F32          (0.01F)
#define MOTTQCMDEPSOFFS_MOTNWTMTR_F32               (8.8F)
#define MOTTQCMDEPSLOLIM_MOTNWTMTR_F32              (-8.8F)
#define MOTTQCMDEPSHILIM_MOTNWTMTR_F32              (8.8F)

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
 * BATT_VLTG_EPS: Integer in interval [0...65535]
 * DBG_EPS_BS_MOD_58_BYTE_ID2: Integer in interval [0...255]
 * ECU_TEMP_EPS: Integer in interval [0...255]
 * ESTIMD_PEAK_MOT_CURR_EPS: Integer in interval [0...4294967295]
 * MOT_FET_TEMP_EPS: Integer in interval [0...255]
 * MOT_MAG_TEMP_EPS: Integer in interval [0...255]
 * MOT_TQ_CMD_EPS: Integer in interval [0...65535]
 * MOT_TQ_CMD_LIMD_EPS: Integer in interval [0...65535]
 * MOT_VEL_EPS: Integer in interval [0...65535]
 * MOT_WIDG_TEMP_EPS: Integer in interval [0...65535]
 * PRIM_HW_TQ_SNSR_VLTG_EPS: Integer in interval [0...255]
 * SECDRY_HW_TQ_SNSR_VLTG_EPS: Integer in interval [0...255]
 * ST_CON_VEH_EPS: Integer in interval [0...255]
 * SYS_ST_EPS: Integer in interval [0...255]
 * VEH_SPD_EPS: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwVehCdn1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHCDN_PRKGNBNOK (1U)
 *   BMWVEHCDN_PRKGBNOK (2U)
 *   BMWVEHCDN_FCTCUSTNOTINFZG (3U)
 *   BMWVEHCDN_LVNG (5U)
 *   BMWVEHCDN_CHKDIAGCANLS (7U)
 *   BMWVEHCDN_DRVRPREPGFOROPER (8U)
 *   BMWVEHCDN_DRVG (10U)
 *   BMWVEHCDN_DRVRPREPGFOREXITOPER (12U)
 *   BMWVEHCDN_INVLD (15U)
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 *   SYSST_DI (0U)
 *   SYSST_OFF (1U)
 *   SYSST_ENA (2U)
 *   SYSST_WRMININ (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   boolean *Rte_Pim_PerCntrFlg(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot315Bas0Repn1BusFrChA_START_SEC_CODE
#include "BmwMsgSlot315Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot315Bas0Repn1BusFrChA_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Init1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot315Bas0Repn1BusFrChA_CODE) BmwMsgSlot315Bas0Repn1BusFrChA_Init1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Init1
 *********************************************************************************************************************/

    /* Intialize PerCntrFlg to True so periodic executes the first time */
    *Rte_Pim_PerCntrFlg() = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot315Bas0Repn1BusFrChA_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *   Std_ReturnType Rte_Read_BrdgVltg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_EcuTFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq4RawAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq5RawAdc_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrPeakEstimdFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotFetT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotMagT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPreLim_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelMrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotWidgT_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BATT_VLTG_EPS_BATT_VLTG_EPS(BATT_VLTG_EPS data)
 *   Std_ReturnType Rte_Write_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2(DBG_EPS_BS_MOD_58_BYTE_ID2 data)
 *   Std_ReturnType Rte_Write_ECU_TEMP_EPS_ECU_TEMP_EPS(ECU_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS(ESTIMD_PEAK_MOT_CURR_EPS data)
 *   Std_ReturnType Rte_Write_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS(MOT_FET_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS(MOT_MAG_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS(MOT_TQ_CMD_EPS data)
 *   Std_ReturnType Rte_Write_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS(MOT_TQ_CMD_LIMD_EPS data)
 *   Std_ReturnType Rte_Write_MOT_VEL_EPS_MOT_VEL_EPS(MOT_VEL_EPS data)
 *   Std_ReturnType Rte_Write_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS(MOT_WIDG_TEMP_EPS data)
 *   Std_ReturnType Rte_Write_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS(PRIM_HW_TQ_SNSR_VLTG_EPS data)
 *   Std_ReturnType Rte_Write_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS(SECDRY_HW_TQ_SNSR_VLTG_EPS data)
 *   Std_ReturnType Rte_Write_ST_CON_VEH_EPS_ST_CON_VEH_EPS(ST_CON_VEH_EPS data)
 *   Std_ReturnType Rte_Write_SYS_ST_EPS_SYS_ST_EPS(SYS_ST_EPS data)
 *   Std_ReturnType Rte_Write_VEH_SPD_EPS_VEH_SPD_EPS(VEH_SPD_EPS data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Per1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot315Bas0Repn1BusFrChA_CODE) BmwMsgSlot315Bas0Repn1BusFrChA_Per1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot315Bas0Repn1BusFrChA_Per1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(BmwVehCdn1, AUTOMATIC) BmwVehCdn_Cnt_T_enum;
    VAR(ST_CON_VEH_EPS, AUTOMATIC) StConVehEps_Cnt_T_enum;
    VAR(float32, AUTOMATIC) BrdgVltg_Volt_T_f32;
    VAR(float32, AUTOMATIC) BrdgVltg_Cnt_T_f32;
    VAR(uint16, AUTOMATIC) BrdgVltg_Cnt_T_u16;
    VAR(float32, AUTOMATIC) EcuTFild_DegCgrd_T_f32;
    VAR(float32, AUTOMATIC) EcuTFild_Cnt_T_f32;
    VAR(uint8, AUTOMATIC) EcuTFild_Cnt_T_u08;
    VAR(float32, AUTOMATIC) HwTq4RawAdc_Volt_T_f32;
    VAR(float32, AUTOMATIC) HwTq4RawAdc_Cnt_T_f32;
    VAR(uint8, AUTOMATIC) HwTq4RawAdc_Cnt_T_u08;
    VAR(float32, AUTOMATIC) HwTq5RawAdc_Volt_T_f32;
    VAR(float32, AUTOMATIC) HwTq5RawAdc_Cnt_T_f32;
    VAR(uint8, AUTOMATIC) HwTq5RawAdc_Cnt_T_u08;
    VAR(float32, AUTOMATIC) MotCurrPeakEstimdFild_AmprSqd_T_f32;
    VAR(float32, AUTOMATIC) MotCurrPeakEstimdFild_Cnt_T_f32;
    VAR(uint32, AUTOMATIC) MotCurrPeakEstimdFild_Cnt_T_u32;
    VAR(float32, AUTOMATIC) MotFetT_DegCgrd_T_f32;
    VAR(float32, AUTOMATIC) MotFetT_Cnt_T_f32;
    VAR(uint8, AUTOMATIC) MotFetT_Cnt_T_u08;
    VAR(float32, AUTOMATIC) MotMagT_DegCgrd_T_f32;
    VAR(float32, AUTOMATIC) MotMagT_Cnt_T_f32;
    VAR(uint8, AUTOMATIC) MotMagT_Cnt_T_u08;
    VAR(float32, AUTOMATIC) MotTqCmdPreLim_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) MotTqCmdPreLim_Cnt_T_f32;
    VAR(uint16, AUTOMATIC) MotTqCmdPreLim_Cnt_T_u16;
    VAR(float32, AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) MotTqCmdPwrLimd_Cnt_T_f32;
    VAR(uint16, AUTOMATIC) MotTqCmdPwrLimd_Cnt_T_u16;
    VAR(float32, AUTOMATIC) MotVelMrf_MotRadPerSec_T_f32;
    VAR(float32, AUTOMATIC) MotVelMrf_Cnt_T_f32;
    VAR(uint16, AUTOMATIC) MotVelMrf_Cnt_T_u16;
    VAR(float32, AUTOMATIC) MotWidgT_DegCgrd_T_f32;
    VAR(float32, AUTOMATIC) MotWidgT_Cnt_T_f32;
    VAR(uint16, AUTOMATIC) MotWidgT_Cnt_T_u16;
    VAR(SysSt1, AUTOMATIC) SysSt_Cnt_T_enum;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Cnt_T_f32;
    VAR(uint16, AUTOMATIC) VehSpd_Cnt_T_u16;
 
    /* Only process the runnable if PerCntrFlg is true, in order to execute every 20ms */
    if (*Rte_Pim_PerCntrFlg() == TRUE)
    {
        /* Reset PerCntrFlg for next interval */
        *Rte_Pim_PerCntrFlg() = FALSE;
                
        /* Read inputs */
        (void)Rte_Read_BmwVehCdn_Val(&BmwVehCdn_Cnt_T_enum);
        (void)Rte_Read_BrdgVltg_Val(&BrdgVltg_Volt_T_f32);
        (void)Rte_Read_EcuTFild_Val(&EcuTFild_DegCgrd_T_f32);
        (void)Rte_Read_HwTq4RawAdc_Val(&HwTq4RawAdc_Volt_T_f32);
        (void)Rte_Read_HwTq5RawAdc_Val(&HwTq5RawAdc_Volt_T_f32);
        (void)Rte_Read_MotCurrPeakEstimdFild_Val(&MotCurrPeakEstimdFild_AmprSqd_T_f32);
        (void)Rte_Read_MotFetT_Val(&MotFetT_DegCgrd_T_f32);
        (void)Rte_Read_MotMagT_Val(&MotMagT_DegCgrd_T_f32);
        (void)Rte_Read_MotTqCmdPreLim_Val(&MotTqCmdPreLim_MotNwtMtr_T_f32);
        (void)Rte_Read_MotTqCmdPwrLimd_Val(&MotTqCmdPwrLimd_MotNwtMtr_T_f32);
        (void)Rte_Read_MotVelMrf_Val(&MotVelMrf_MotRadPerSec_T_f32);
        (void)Rte_Read_MotWidgT_Val(&MotWidgT_DegCgrd_T_f32);
        (void)Rte_Read_SysSt_Val(&SysSt_Cnt_T_enum);
        (void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
    
        /*** Start output processing ***/
        StConVehEps_Cnt_T_enum = (ST_CON_VEH_EPS)BmwVehCdn_Cnt_T_enum;
        
        VehSpd_Kph_T_f32 = Lim_f32(VehSpd_Kph_T_f32, VEHSPDEPSLOLIM_KPH_F32, VEHSPDEPSHILIM_KPH_F32);
        VehSpd_Cnt_T_f32 = (VehSpd_Kph_T_f32 / VEHSPDEPSSCA_KPHPERCNT_F32);
        VehSpd_Cnt_T_u16 = (VEH_SPD_EPS)VehSpd_Cnt_T_f32;
        
        BrdgVltg_Volt_T_f32 = Lim_f32(BrdgVltg_Volt_T_f32, BATTVLTGEPSLOLIM_VOLT_F32, BATTVLTGEPSHILIM_VOLT_F32) + BATTVLTGEPSOFFS_VOLT_F32;
        BrdgVltg_Cnt_T_f32 = (BrdgVltg_Volt_T_f32 / BATTVLTGEPSSCA_VOLTPERCNT_F32);
        BrdgVltg_Cnt_T_u16 = (BATT_VLTG_EPS)BrdgVltg_Cnt_T_f32;
        
        MotCurrPeakEstimdFild_AmprSqd_T_f32 = Lim_f32(MotCurrPeakEstimdFild_AmprSqd_T_f32, ESTIMDPEAKMOTCURREPSLOLIM_AMPRSQD_F32, ESTIMDPEAKMOTCURREPSHILIM_AMPRSQD_F32);
        MotCurrPeakEstimdFild_Cnt_T_f32 = (MotCurrPeakEstimdFild_AmprSqd_T_f32 / ESTIMDPEAKMOTCURREPSSCA_AMPRSQDPERCNT_F32);
        MotCurrPeakEstimdFild_Cnt_T_u32 = (ESTIMD_PEAK_MOT_CURR_EPS)MotCurrPeakEstimdFild_Cnt_T_f32;
        
        MotVelMrf_MotRadPerSec_T_f32 = Lim_f32(MotVelMrf_MotRadPerSec_T_f32, MOTVELEPSLOLIM_MOTRADPERSEC_F32, MOTVELEPSHILIM_MOTRADPERSEC_F32) + MOTVELEPSOFFS_MOTRADPERSEC_F32;
        MotVelMrf_Cnt_T_f32 = (MotVelMrf_MotRadPerSec_T_f32 / MOTVELEPSSCA_MOTRADPERSECPERCNT_F32);
        MotVelMrf_Cnt_T_u16 = (MOT_VEL_EPS)MotVelMrf_Cnt_T_f32;
        
        MotTqCmdPwrLimd_MotNwtMtr_T_f32 = Lim_f32(MotTqCmdPwrLimd_MotNwtMtr_T_f32, MOTTQCMDLIMDEPSLOLIM_MOTNWTMTR_F32, MOTTQCMDLIMDEPSHILIM_MOTNWTMTR_F32) + MOTTQCMDLIMDEPSOFFS_MOTNWTMTR_F32;
        MotTqCmdPwrLimd_Cnt_T_f32 = (MotTqCmdPwrLimd_MotNwtMtr_T_f32 / MOTTQCMDLIMDEPSSCA_MOTNWTMTRPERCNT_F32);
        MotTqCmdPwrLimd_Cnt_T_u16 = (MOT_TQ_CMD_LIMD_EPS)MotTqCmdPwrLimd_Cnt_T_f32;
        
        HwTq4RawAdc_Volt_T_f32 = Lim_f32(HwTq4RawAdc_Volt_T_f32, PRIMHWTQSNSRVLTGEPSLOLIM_VOLT_F32, PRIMHWTQSNSRVLTGEPSHILIM_VOLT_F32);
        HwTq4RawAdc_Cnt_T_f32 = (HwTq4RawAdc_Volt_T_f32 / PRIMHWTQSNSRVLTGEPSSCA_VOLTPERCNT_F32);
        HwTq4RawAdc_Cnt_T_u08 = (PRIM_HW_TQ_SNSR_VLTG_EPS)HwTq4RawAdc_Cnt_T_f32;
        
        HwTq5RawAdc_Volt_T_f32 = Lim_f32(HwTq5RawAdc_Volt_T_f32, SECDRYHWTQSNSRVLTGEPSLOLIM_VOLT_F32, SECDRYHWTQSNSRVLTGEPSHILIM_VOLT_F32);
        HwTq5RawAdc_Cnt_T_f32 = (HwTq5RawAdc_Volt_T_f32 / SECDRYHWTQSNSRVLTGEPSSCA_VOLTPERCNT_F32);
        HwTq5RawAdc_Cnt_T_u08 = (SECDRY_HW_TQ_SNSR_VLTG_EPS)HwTq5RawAdc_Cnt_T_f32;
        
        EcuTFild_DegCgrd_T_f32 = Lim_f32(EcuTFild_DegCgrd_T_f32, ECUTEMPEPSLOLIM_DEGCGRD_F32, ECUTEMPEPSHILIM_DEGCGRD_F32);
        EcuTFild_Cnt_T_f32 = (EcuTFild_DegCgrd_T_f32 + ECUTEMPEPSOFFS_DEGCGRD_F32);
        EcuTFild_Cnt_T_u08 = (ECU_TEMP_EPS)EcuTFild_Cnt_T_f32;
        
        MotFetT_DegCgrd_T_f32 = Lim_f32(MotFetT_DegCgrd_T_f32, MOTFETTEMPEPSLOLIM_DEGCGRD_F32, MOTFETTEMPEPSHILIM_DEGCGRD_F32);
        MotFetT_Cnt_T_f32 = (MotFetT_DegCgrd_T_f32 + MOTFETTEMPEPSOFFS_DEGCGRD_F32);
        MotFetT_Cnt_T_u08 = (MOT_FET_TEMP_EPS)MotFetT_Cnt_T_f32;
        
        MotMagT_DegCgrd_T_f32 = Lim_f32(MotMagT_DegCgrd_T_f32, MOTMAGTEMPEPSLOLIM_DEGCGRD_F32, MOTMAGTEMPEPSHILIM_DEGCGRD_F32);
        MotMagT_Cnt_T_f32 = (MotMagT_DegCgrd_T_f32 + MOTMAGTEMPEPSOFFS_DEGCGRD_F32);
        MotMagT_Cnt_T_u08 = (MOT_MAG_TEMP_EPS)MotMagT_Cnt_T_f32;
        
        MotWidgT_DegCgrd_T_f32 = Lim_f32(MotWidgT_DegCgrd_T_f32, MOTWIDGTEMPEPSLOLIM_DEGCGRD_F32, MOTWIDGTEMPEPSHILIM_DEGCGRD_F32);
        MotWidgT_Cnt_T_f32 = (MotWidgT_DegCgrd_T_f32 + MOTWIDGTEMPEPSOFFS_DEGCGRD_F32);
        MotWidgT_Cnt_T_u16 = (MOT_WIDG_TEMP_EPS)MotWidgT_Cnt_T_f32;
        
        MotTqCmdPreLim_MotNwtMtr_T_f32 = Lim_f32(MotTqCmdPreLim_MotNwtMtr_T_f32, MOTTQCMDEPSLOLIM_MOTNWTMTR_F32, MOTTQCMDEPSHILIM_MOTNWTMTR_F32) + MOTTQCMDEPSOFFS_MOTNWTMTR_F32;
        MotTqCmdPreLim_Cnt_T_f32 = (MotTqCmdPreLim_MotNwtMtr_T_f32 / MOTTQCMDEPSSCA_MOTNWTMTRPERCNT_F32);
        MotTqCmdPreLim_Cnt_T_u16 = (MOT_TQ_CMD_EPS)MotTqCmdPreLim_Cnt_T_f32;
        /*** End output processing ***/
        
        /* Write outputs */
        (void)Rte_Write_BATT_VLTG_EPS_BATT_VLTG_EPS(BrdgVltg_Cnt_T_u16);
        (void)Rte_Write_DBG_EPS_BS_MOD_58_BYTE_ID2_DBG_EPS_BS_MOD_58_BYTE_ID2((DBG_EPS_BS_MOD_58_BYTE_ID2)1U);
        (void)Rte_Write_ECU_TEMP_EPS_ECU_TEMP_EPS(EcuTFild_Cnt_T_u08);
        (void)Rte_Write_ESTIMD_PEAK_MOT_CURR_EPS_ESTIMD_PEAK_MOT_CURR_EPS(MotCurrPeakEstimdFild_Cnt_T_u32);
        (void)Rte_Write_MOT_FET_TEMP_EPS_MOT_FET_TEMP_EPS(MotFetT_Cnt_T_u08);
        (void)Rte_Write_MOT_MAG_TEMP_EPS_MOT_MAG_TEMP_EPS(MotMagT_Cnt_T_u08);
        (void)Rte_Write_MOT_TQ_CMD_EPS_MOT_TQ_CMD_EPS(MotTqCmdPreLim_Cnt_T_u16);
        (void)Rte_Write_MOT_TQ_CMD_LIMD_EPS_MOT_TQ_CMD_LIMD_EPS(MotTqCmdPwrLimd_Cnt_T_u16);
        (void)Rte_Write_MOT_VEL_EPS_MOT_VEL_EPS(MotVelMrf_Cnt_T_u16);
        (void)Rte_Write_MOT_WIDG_TEMP_EPS_MOT_WIDG_TEMP_EPS(MotWidgT_Cnt_T_u16);
        (void)Rte_Write_PRIM_HW_TQ_SNSR_VLTG_EPS_PRIM_HW_TQ_SNSR_VLTG_EPS(HwTq4RawAdc_Cnt_T_u08);
        (void)Rte_Write_SECDRY_HW_TQ_SNSR_VLTG_EPS_SECDRY_HW_TQ_SNSR_VLTG_EPS(HwTq5RawAdc_Cnt_T_u08);
        (void)Rte_Write_ST_CON_VEH_EPS_ST_CON_VEH_EPS(StConVehEps_Cnt_T_enum);
        (void)Rte_Write_SYS_ST_EPS_SYS_ST_EPS((SYS_ST_EPS)SysSt_Cnt_T_enum);
        (void)Rte_Write_VEH_SPD_EPS_VEH_SPD_EPS(VehSpd_Cnt_T_u16);        
    }
    else
    {
        /* Set PerCntrFlg for next interval */
        *Rte_Pim_PerCntrFlg() = TRUE;
    }
    

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot315Bas0Repn1BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot315Bas0Repn1BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
