/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwSwFctDi.c
 *        Config:  C:/Component/CF108A_BmwSwFctDi_Impl/tools/Component.dpa
 *     SW-C Type:  BmwSwFctDi
 *  Generated at:  Sat Jul 28 12:27:15 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwSwFctDi>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : BmwSwFctDi.c
* Module Description: Implementation of BMW Software Function Defeat (CF0108A)
* Project           : CBD 
* Author            : Akilan Rathakrishnan
***********************************************************************************************************************
* Version Control:
* %version          : 2 %
* %derived_by       : nz3734 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 07/27/18  1        AR       Initial Version                                                                 EA4#26426  
* 07/28/18  2        AR       Polyspace results updated and cleanup                                           EA4#26426  
**********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_BmwSwFctDi.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrMath.h"
#include "SysGlbPrm.h"
#include "Coding.h"


#define MAXHWTQCMDDAMPG_HWNWTMTR_F32     (10.0f)
#define MINHWTQCMDDAMPG_HWNWTMTR_F32     (-10.0f)
#define MINCURRATSPD_AMPR_U08            (0u)
#define MAXCURRATSPD_AMPR_U08            (120u)
#define ONE_ULS_U08                      (1u)
#define ZERO_ULS_U08                     (0u)
#define ZERO_ULS_F32                     (0.0f)

static FUNC(boolean, AUTOMATIC) OvrdCmdEna( VAR(boolean, AUTOMATIC) OvrdCal_Cnt_T_u08, VAR(uint8, AUTOMATIC) CodingBit_Cnt_T_u08);

static FUNC(float32, AUTOMATIC) CtrldVelRtnEna(	VAR(float32, AUTOMATIC) CtrldVelRtnCmd_MotNwtMtr_T_f32);

static FUNC(float32, AUTOMATIC) ClsdLoopHysEna(VAR(float32, AUTOMATIC) HwTqCmdHys_HwNwtMtr_T_f32);

static FUNC(boolean, AUTOMATIC) InertiaCmpVelCmdDiBmwOvrd(VAR(boolean, AUTOMATIC) InertiaCmpVelCmdDi_Cnt_T_logl);
												   
static FUNC(boolean, AUTOMATIC) PullCmpCmdDiBmwOvrd( VAR(boolean, AUTOMATIC) PullCmpCmdDi_Cnt_T_logl);
								   
static FUNC(void, AUTOMATIC) UpdCodingBits(VAR(uint8, AUTOMATIC) CodingDataMode_Cnt_T_u08);
 
static FUNC(void, AUTOMATIC) ReadCodingData(VAR(uint8, AUTOMATIC) CodingDataMode_Cnt_T_u08);
 
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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
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
 *   uint8 *Rte_Pim_BmwActvRtn(void)
 *   uint8 *Rte_Pim_BmwEngStrtStop(void)
 *   uint8 *Rte_Pim_BmwEpsOscn(void)
 *   uint8 *Rte_Pim_BmwFricCmp(void)
 *   uint8 *Rte_Pim_BmwGearInertiaCmp(void)
 *   uint8 *Rte_Pim_BmwHwInertiaCmp(void)
 *   uint8 *Rte_Pim_BmwHysActvInfl(void)
 *   uint8 *Rte_Pim_BmwIfNegDampg(void)
 *   uint8 *Rte_Pim_BmwIfNegFac(void)
 *   uint8 *Rte_Pim_BmwIfNegHwTq(void)
 *   uint8 *Rte_Pim_BmwIfNegMotTq(void)
 *   uint8 *Rte_Pim_BmwLrnSwt(void)
 *   uint8 *Rte_Pim_BmwPrkgPwrDampg(void)
 *   uint8 *Rte_Pim_BmwPullCmp(void)
 *   uint8 *Rte_Pim_PrevCodingDataMode(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint8 Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiBmwPullCmpOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiCodingOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val(void)
 *   uint8 Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val(void)
 *
 *********************************************************************************************************************/


#define BmwSwFctDi_START_SEC_CODE
#include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwSwFctDiInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CtrldVelRtnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdHys_Val(float32 *data)
 *   Std_ReturnType Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmdDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwOutpTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwStrtStopMsgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_DampgCmdPwrPrkgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_DrvgDynFacEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_FricLrngCustEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HaptcFbEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwTqCmdHysBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MaxCurrAtHiSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MaxCurrAtLoSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PullCmpCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TrfcJamAssiCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TunSetHndlrEna_Logl(boolean data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_Coding_DataMode_Mode(void)
 *   Modes of Rte_ModeType_Coding_DataMode:
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED
 *   - RTE_TRANSITION_Coding_DataMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Data_GetCurrentLimit(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_02_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_00_CompensationOfFriction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_02(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_03(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_06(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_07(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_04_EPSVibration(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_06_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME05_00_ActiveFanActuation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiInit1
 *********************************************************************************************************************/
 
	/************************ Akilan - To be clarified with BMW ************************/
	/* Keep all features controlled by Coding inactive 
	until Coding component ready to provide data */
	*Rte_Pim_BmwActvRtn()         = 0u;
	*Rte_Pim_BmwEngStrtStop()     = 0u; 
	*Rte_Pim_BmwEpsOscn()         = 0u; 
	*Rte_Pim_BmwFricCmp()         = 0u; 
	*Rte_Pim_BmwGearInertiaCmp()  = 0u; 
	*Rte_Pim_BmwHwInertiaCmp()    = 0u; 
	*Rte_Pim_BmwHysActvInfl()     = 0u; 
	*Rte_Pim_BmwIfNegDampg()      = 0u; 
	*Rte_Pim_BmwIfNegFac()        = 0u; 
	*Rte_Pim_BmwIfNegHwTq()       = 0u; 
	*Rte_Pim_BmwIfNegMotTq()      = 0u; 
	*Rte_Pim_BmwLrnSwt()          = 0u; 
	*Rte_Pim_BmwPrkgPwrDampg()    = 0u; 
	*Rte_Pim_BmwPullCmp()         = 0u; 
	*Rte_Pim_PrevCodingDataMode()     = 0u; 	

	*Rte_Pim_PrevCodingDataMode() = Rte_Mode_Coding_DataMode_Mode();
	
	if((*Rte_Pim_PrevCodingDataMode() == RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT) || 
		(*Rte_Pim_PrevCodingDataMode() == RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED) ||
		(*Rte_Pim_PrevCodingDataMode() == RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED)||
		(Rte_Prm_BmwSwFctDiCodingOvrd_Val() == ONE_ULS_U08))
	{
		/* Update coding bits only when 
		
			   Coding Data Mode is DEFAULT, QUALIFIED or UNQUALIFIED  
					OR
			   Coding Override calibration is active
		*/
		UpdCodingBits(*Rte_Pim_PrevCodingDataMode());	   
	}	
	
	return;
   
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwSwFctDiPer1
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
 *   Std_ReturnType Rte_Read_CtrldVelRtnCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqCmdHys_Val(float32 *data)
 *   Std_ReturnType Rte_Read_InertiaCmpVelCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmdDi_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwOutpTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwStrtStopMsgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_DampgCmdPwrPrkgEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_DrvgDynFacEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_FricLrngCustEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HaptcFbEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwTqCmdHysBmwOvrd_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwTqOvrlCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MaxCurrAtHiSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_MaxCurrAtLoSpd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PullCmpCmdDiBmwOvrd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TrfcJamAssiCmdEna_Logl(boolean data)
 *   Std_ReturnType Rte_Write_TunSetHndlrEna_Logl(boolean data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_Coding_DataMode_Mode(void)
 *   Modes of Rte_ModeType_Coding_DataMode:
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_INPROGRESS
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNDEFINED
 *   - RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED
 *   - RTE_TRANSITION_Coding_DataMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Data_GetCurrentLimit(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_00_CalculationOfLoadMinusstateMinusdependentSteeringAssistance(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_02_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_00_CompensationOfFriction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_02(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_03(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_06(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME02_07(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_00_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_01_VoltageDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME03_02_SpeedDependantDegredation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_04_EPSVibration(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_06_reserved(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetNAME05_00_ActiveFanActuation(boolean *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Data_GetSpeedMinuslimitForMaxCurrent(uint8 *Value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Data_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwSwFctDi_CODE) BmwSwFctDiPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwSwFctDiPer1
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) CodingDataMode_Cnt_T_u08;   

	CodingDataMode_Cnt_T_u08 =  Rte_Mode_Coding_DataMode_Mode();
	
	if(((*Rte_Pim_PrevCodingDataMode() != CodingDataMode_Cnt_T_u08) && 
	    ((CodingDataMode_Cnt_T_u08 == RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT) || 
		(CodingDataMode_Cnt_T_u08 == RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED) ||
		(CodingDataMode_Cnt_T_u08 == RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED))) ||
		(Rte_Prm_BmwSwFctDiCodingOvrd_Val() == ONE_ULS_U08))
	{
		/* Update coding bits only when 
		
			   Coding Data Mode transitioned to DEFAULT, QUALIFIED or UNQUALIFIED  
					OR
			   Coding Override calibration is active
		*/		
		UpdCodingBits(CodingDataMode_Cnt_T_u08);			
	}
	
	*Rte_Pim_PrevCodingDataMode()  = CodingDataMode_Cnt_T_u08;
	
	return;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwSwFctDi_STOP_SEC_CODE
#include "BmwSwFctDi_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*******************************************************************************
* Name          :   UpdCodingBits
* Description   :   Updates Coding bits that are affecting other functions (components)
* Inputs        :   CodingDataMode_Cnt_T_u08 - Coding component's data mode
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/  
static FUNC(void, AUTOMATIC) UpdCodingBits(VAR(uint8, AUTOMATIC) CodingDataMode_Cnt_T_u08)
 {
 
	VAR(float32, AUTOMATIC) CtrldVelRtnCmd_MotNwtMtr_T_f32 = 0.0F;
	VAR(float32, AUTOMATIC) HwTqCmdHys_HwNwtMtr_T_f32  = 0.0F;
	VAR(float32, AUTOMATIC) BmwOvrdHwTqCmdHys_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) BmwOvrdCtrldVelRtnCmd_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) MaxCurrAtHiSpd_Ampr_T_f32;
	VAR(float32, AUTOMATIC) MaxCurrAtLoSpd_Ampr_T_f32;
	VAR(boolean, AUTOMATIC) InertiaCmpVelCmdDi_Cnt_T_logl = FALSE; 
	VAR(boolean, AUTOMATIC) PullCmpCmdDi_Cnt_T_logl = FALSE;

	VAR(boolean, AUTOMATIC) InerCmpVelCmdDiBmwOvrd_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) PullCmpCmdDiBmwOvrd_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) HwTqOvrlCmdEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) FricLrngCustEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) DampgCmdPwrPrkgEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) TrfcJamAssiCmdEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) TunSetHndlrEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) BmwStrtStopMsgEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) BmwOutpTqOvrlCmdEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) DrvgDynFacEna_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) HaptcFbEna_Cnt_T_logl; 
	
	(void)Rte_Read_CtrldVelRtnCmd_Val(&CtrldVelRtnCmd_MotNwtMtr_T_f32);
	(void)Rte_Read_HwTqCmdHys_Val(&HwTqCmdHys_HwNwtMtr_T_f32);
	(void)Rte_Read_InertiaCmpVelCmdDi_Logl(&InertiaCmpVelCmdDi_Cnt_T_logl);
	(void)Rte_Read_PullCmpCmdDi_Logl(&PullCmpCmdDi_Cnt_T_logl);
	
	/* Read coding bits from coding component and update respective PIMs */
	ReadCodingData(CodingDataMode_Cnt_T_u08);	

	/* Pull Compensation Command */
 	PullCmpCmdDiBmwOvrd_Cnt_T_logl = PullCmpCmdDiBmwOvrd(PullCmpCmdDi_Cnt_T_logl);
	/* Inertia Compensation Velocity Command */
    InerCmpVelCmdDiBmwOvrd_Cnt_T_logl = InertiaCmpVelCmdDiBmwOvrd(InertiaCmpVelCmdDi_Cnt_T_logl);
	/* Closed Loop Hysteresis Enable */
	BmwOvrdHwTqCmdHys_HwNwtMtr_T_f32 = ClsdLoopHysEna(HwTqCmdHys_HwNwtMtr_T_f32);
	/* Controlled Velocity Return Enable */
	BmwOvrdCtrldVelRtnCmd_MotNwtMtr_T_f32 = CtrldVelRtnEna(CtrldVelRtnCmd_MotNwtMtr_T_f32);
	/* BmwInterfaceMinusHandwheelTorque*/
	HwTqOvrlCmdEna_Cnt_T_logl      = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwIfNegHwTqOvrd_Val(),*Rte_Pim_BmwIfNegHwTq());
	/* BmwFrictionCompensation*/
	FricLrngCustEna_Cnt_T_logl     = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwFricCmpOvrd_Val(),*Rte_Pim_BmwFricCmp());
	/* BmwParkingPowerDamping */
	DampgCmdPwrPrkgEna_Cnt_T_logl  = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwPrkgPwrDampgOvrd_Val(),*Rte_Pim_BmwPrkgPwrDampg());
	/* BmwInterfaceMinusDamping*/
	TrfcJamAssiCmdEna_Cnt_T_logl   = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwIfNegDampgOvrd_Val(),*Rte_Pim_BmwIfNegDampg());
	/* BmwExperienceSwitch*/
	TunSetHndlrEna_Cnt_T_logl      = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwLrnSwtOvrd_Val(),*Rte_Pim_BmwLrnSwt());
	/* BmwEngineStartStop*/
	BmwStrtStopMsgEna_Cnt_T_logl   = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwEngStrtStopOvrd_Val(),*Rte_Pim_BmwEngStrtStop()); 
	/* BmwInterfaceMinusMotorTorque*/
	BmwOutpTqOvrlCmdEna_Cnt_T_logl = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwIfNegMotTqOvrd_Val(),*Rte_Pim_BmwIfNegMotTq());
	/*BmwInterfaceMinusFactors*/
	DrvgDynFacEna_Cnt_T_logl       = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwIfNegFacOvrd_Val(), *Rte_Pim_BmwIfNegFac());
	/*BmwEPSVibration*/
	HaptcFbEna_Cnt_T_logl          = OvrdCmdEna(Rte_Prm_BmwSwFctDiBmwEpsOscnOvrd_Val(), *Rte_Pim_BmwEpsOscn());
	/*MaximumCurrentAtHighSpeed*/
	MaxCurrAtHiSpd_Ampr_T_f32 = (float32)Lim_u08(Rte_Prm_BmwSwFctDiMaxCurrAtHiSpdOvrd_Val(),MINCURRATSPD_AMPR_U08, MAXCURRATSPD_AMPR_U08);
	/*MaximumCurrentAtLowSpeed*/
	MaxCurrAtLoSpd_Ampr_T_f32 = (float32)Lim_u08(Rte_Prm_BmwSwFctDiMaxCurrAtLoSpdOvrd_Val(),MINCURRATSPD_AMPR_U08, MAXCURRATSPD_AMPR_U08);
	
	/* Rte Write */
	(void)Rte_Write_PullCmpCmdDiBmwOvrd_Logl(PullCmpCmdDiBmwOvrd_Cnt_T_logl);
	(void)Rte_Write_InertiaCmpVelCmdDiBmwOvrd_Logl(InerCmpVelCmdDiBmwOvrd_Cnt_T_logl);
	(void)Rte_Write_HwTqCmdHysBmwOvrd_Val(BmwOvrdHwTqCmdHys_HwNwtMtr_T_f32);
	(void)Rte_Write_CtrldVelRtnCmdBmwOvrd_Val(BmwOvrdCtrldVelRtnCmd_MotNwtMtr_T_f32);
	(void)Rte_Write_HwTqOvrlCmdEna_Logl(HwTqOvrlCmdEna_Cnt_T_logl);
	(void)Rte_Write_FricLrngCustEna_Logl(FricLrngCustEna_Cnt_T_logl);
	(void)Rte_Write_DampgCmdPwrPrkgEna_Logl(DampgCmdPwrPrkgEna_Cnt_T_logl);
	(void)Rte_Write_TrfcJamAssiCmdEna_Logl(TrfcJamAssiCmdEna_Cnt_T_logl);
	(void)Rte_Write_TunSetHndlrEna_Logl(TunSetHndlrEna_Cnt_T_logl);
	(void)Rte_Write_BmwStrtStopMsgEna_Logl(BmwStrtStopMsgEna_Cnt_T_logl);
	(void)Rte_Write_BmwOutpTqOvrlCmdEna_Logl(BmwOutpTqOvrlCmdEna_Cnt_T_logl);
	(void)Rte_Write_DrvgDynFacEna_Logl(DrvgDynFacEna_Cnt_T_logl);
	(void)Rte_Write_HaptcFbEna_Logl(HaptcFbEna_Cnt_T_logl);
	(void)Rte_Write_MaxCurrAtHiSpd_Val(MaxCurrAtHiSpd_Ampr_T_f32);
	(void)Rte_Write_MaxCurrAtLoSpd_Val(MaxCurrAtLoSpd_Ampr_T_f32);
	
	return;
 
 }
 
/*******************************************************************************
* Name          :   ReadCodingData
* Description   :   Reads Coding bits from Coding component
* Inputs        :   CodingDataMode_Cnt_T_u08 - Coding component's data mode
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/   
static FUNC(void, AUTOMATIC) ReadCodingData(VAR(uint8, AUTOMATIC) CodingDataMode_Cnt_T_u08)
{
	Std_ReturnType RetVal_Cnt_T_u08;
	
	/* Coding flags are initialized to FALSE since coding component may not update it sometimes */ 
	VAR(uint8, AUTOMATIC) BmwActvRtn_Cnt_T_u08 = 0u;          
	VAR(uint8, AUTOMATIC) BmwHysActvInfl_Cnt_T_u08 = 0u;      
	VAR(uint8, AUTOMATIC) BmwPrkgPwrDampg_Cnt_T_u08 = 0u;     
	VAR(uint8, AUTOMATIC) BmwFricCmp_Cnt_T_u08 = 0u;          
	VAR(uint8, AUTOMATIC) BmwPullCmp_Cnt_T_u08 = 0u;          
	VAR(uint8, AUTOMATIC) BmwGearInertiaCmp_Cnt_T_u08 = 0u;   
	VAR(uint8, AUTOMATIC) BmwHwInertiaCmp_Cnt_T_u08 = 0u;     
	VAR(uint8, AUTOMATIC) BmwIfNegHwTq_Cnt_T_u08 = 0u;        
	VAR(uint8, AUTOMATIC) BmwIfNegMotTq_Cnt_T_u08 = 0u;      
	VAR(uint8, AUTOMATIC) BmwIfNegFac_Cnt_T_u08 = 0u;         
	VAR(uint8, AUTOMATIC) BmwIfNegDampg_Cnt_T_u08 = 0u;       
	VAR(uint8, AUTOMATIC) BmwEpsOscn_Cnt_T_u08 = 0u;          
	VAR(uint8, AUTOMATIC) BmwLrnSwt_Cnt_T_u08 = 0u;           
	VAR(uint8, AUTOMATIC) BmwEngStrtStop_Cnt_T_u08 = 0u; 		
	
	/* Read coding bits only when Coding Data Mode is DEFAULT, QUALIFIED or UNQUALIFIED */	
	if((CodingDataMode_Cnt_T_u08  == RTE_MODE_Coding_DataMode_NCDSTATE_DEFAULT) || 
		(CodingDataMode_Cnt_T_u08 == RTE_MODE_Coding_DataMode_NCDSTATE_QUALIFIED) ||
		(CodingDataMode_Cnt_T_u08 == RTE_MODE_Coding_DataMode_NCDSTATE_UNQUALIFIED))
	{
		/* call Coding data servers to get coding bit value */
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME00_01_CalculationOfActiveReturn(&BmwActvRtn_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwActvRtn() = BmwActvRtn_Cnt_T_u08;			
		}			
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME00_03_ActiveInfluenceOnTheSteeringHysterisis(&BmwHysActvInfl_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwHysActvInfl() = BmwHysActvInfl_Cnt_T_u08;			
		}
					
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME01_03_ParkingPowerDamping(&BmwPrkgPwrDampg_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwPrkgPwrDampg() = BmwPrkgPwrDampg_Cnt_T_u08;
		}		
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME02_00_CompensationOfFriction(&BmwFricCmp_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwFricCmp() = BmwFricCmp_Cnt_T_u08;
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME02_01_CompensationOfConstantSteeringPullAndLateralInclinationPull(&BmwPullCmp_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{		
			*Rte_Pim_BmwPullCmp() = BmwPullCmp_Cnt_T_u08;
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME02_04_CompensationOfInertiaOfTheSteeringGear(&BmwGearInertiaCmp_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwGearInertiaCmp() = BmwGearInertiaCmp_Cnt_T_u08;
		}
			
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME02_05_CompensationOfInertiaOfTheSteeringWheel(&BmwHwInertiaCmp_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwHwInertiaCmp() = BmwHwInertiaCmp_Cnt_T_u08;
		}		
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusDriversTorque(&BmwIfNegHwTq_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwIfNegHwTq() = BmwIfNegHwTq_Cnt_T_u08;
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME04_00_DrivingDynamicsInterfaceMinusMotorTorque(&BmwIfNegMotTq_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwIfNegMotTq() = BmwIfNegMotTq_Cnt_T_u08;			
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME04_02_DrivingDynamicsInterfaceMinusFactors(&BmwIfNegFac_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwIfNegFac() = BmwIfNegFac_Cnt_T_u08;
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME04_03_DrivingDynamicsInterfaceMinusAdditionalDamping(&BmwIfNegDampg_Cnt_T_u08);
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwIfNegDampg() = BmwIfNegDampg_Cnt_T_u08;
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME04_04_EPSVibration(&BmwEpsOscn_Cnt_T_u08);

		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwEpsOscn() = BmwEpsOscn_Cnt_T_u08;
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME04_05_DrivingExperienceSwitch(&BmwLrnSwt_Cnt_T_u08);

		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwLrnSwt() = BmwLrnSwt_Cnt_T_u08;
		}
		
		RetVal_Cnt_T_u08 = Rte_Call_Data_GetNAME04_07_automaticEngineStartStopFunction(&BmwEngStrtStop_Cnt_T_u08); 
		
		if(RetVal_Cnt_T_u08 == CODING_RC_OK)
		{
			*Rte_Pim_BmwEngStrtStop() = BmwEngStrtStop_Cnt_T_u08;
		}		
		
	}
	else
	{
		/* Dont update coding PIMs */
	} 
	
	return;
} 

/*******************************************************************************
* Name          :   PullCmpCmdDiBmwOvrd
* Description   :   Implements logic for Pull compensation over-ride
* Inputs        :   PullCmpCmdDi_Cnt_T_logl -  Pull compensation command defeat from CMS
* Outputs       :   PullCmpCmdDiBmwOvrd_Cnt_T_logl - Calculated Pull compensation
*                   command over-ride
* Usage Notes   :   None
*****************************************************************************/   
static FUNC(boolean, AUTOMATIC) PullCmpCmdDiBmwOvrd( VAR(boolean, AUTOMATIC) PullCmpCmdDi_Cnt_T_logl)
{
	VAR(boolean, AUTOMATIC) TmpPullCmpCmdDiBmwOvrd_Cnt_T_logl; 
	VAR(boolean, AUTOMATIC) PullCmpCmdDiBmwOvrd_Cnt_T_logl; 
	
	/*Pull Compensation Command*/
	if(Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val() == ZERO_ULS_U08)
	{
		TmpPullCmpCmdDiBmwOvrd_Cnt_T_logl = FALSE;
	}
	else if(Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val() == ONE_ULS_U08)
	{
		TmpPullCmpCmdDiBmwOvrd_Cnt_T_logl = TRUE;
	}
	else
	{
		if(*Rte_Pim_BmwPullCmp() != 0)
		{
			TmpPullCmpCmdDiBmwOvrd_Cnt_T_logl = TRUE;
		}
		else
		{
			TmpPullCmpCmdDiBmwOvrd_Cnt_T_logl = FALSE;
		}
	}

	if(((TmpPullCmpCmdDiBmwOvrd_Cnt_T_logl == FALSE) && (PullCmpCmdDi_Cnt_T_logl == FALSE)) ||
	(PullCmpCmdDi_Cnt_T_logl == TRUE))
	{
		PullCmpCmdDiBmwOvrd_Cnt_T_logl = TRUE;
	}
	else
	{
		PullCmpCmdDiBmwOvrd_Cnt_T_logl = FALSE;	 
	}
	
	return (PullCmpCmdDiBmwOvrd_Cnt_T_logl);
}

/*******************************************************************************
* Name          :   InertiaCmpVelCmdDiBmwOvrd
* Description   :   Implements logic for Pull compensation over-ride
* Inputs        :   InertiaCmpVelCmdDi_Cnt_T_logl -  Inertia compensation velocity 
*                   command defeat from CMS
* Outputs       :   InertiaCmpVelCmdDiBmwOvrd_Cnt_T_logl - Calculated Inertia 
*                   compensation velocity command over-ride
* Usage Notes   :   None
*****************************************************************************/    
static FUNC(boolean, AUTOMATIC) InertiaCmpVelCmdDiBmwOvrd(VAR(boolean, AUTOMATIC) InertiaCmpVelCmdDi_Cnt_T_logl)
{
	VAR(boolean, AUTOMATIC) InertiaCmpVelCmdDiBmwOvrd_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) TmpGearInertiaCmpOvrd_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) TmpHwInertiaCmpOvrd_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) TmpInertiaCmpOvrd_Cnt_T_logl;
	
	/* Gear Inertia compensation */
	if(Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val() == ZERO_ULS_U08)
	{
		TmpGearInertiaCmpOvrd_Cnt_T_logl = FALSE;
	}
	else if(Rte_Prm_BmwSwFctDiBmwGearInertiaCmpOvrd_Val() == ONE_ULS_U08)
	{
		TmpGearInertiaCmpOvrd_Cnt_T_logl = TRUE;
	}
	else
	{
		if(*Rte_Pim_BmwGearInertiaCmp() != 0U)
		{
			TmpGearInertiaCmpOvrd_Cnt_T_logl = TRUE;
		}
		else
		{
			TmpGearInertiaCmpOvrd_Cnt_T_logl = FALSE;			
		}
	}
	
	/* Hw Inertia compensation */
	if(Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val() == ZERO_ULS_U08)
	{
		TmpHwInertiaCmpOvrd_Cnt_T_logl = FALSE;
	}
	else if(Rte_Prm_BmwSwFctDiBmwHwInertiaCmpOvrd_Val() == ONE_ULS_U08)
	{
		TmpHwInertiaCmpOvrd_Cnt_T_logl = TRUE;
	}
	else
	{
		if(*Rte_Pim_BmwHwInertiaCmp() != 0u)
		{
			TmpHwInertiaCmpOvrd_Cnt_T_logl = TRUE;
		}
		else
		{
			TmpHwInertiaCmpOvrd_Cnt_T_logl = FALSE;			
		}
	}
	
	/* Inertia compensation */
	if((TmpHwInertiaCmpOvrd_Cnt_T_logl == TRUE) && (TmpGearInertiaCmpOvrd_Cnt_T_logl==TRUE))
	{
		TmpInertiaCmpOvrd_Cnt_T_logl = TRUE; 
	}
	else
	{
		TmpInertiaCmpOvrd_Cnt_T_logl = FALSE;
	}
	/* Consider CMS */
	if(((TmpInertiaCmpOvrd_Cnt_T_logl == FALSE) && (InertiaCmpVelCmdDi_Cnt_T_logl==FALSE)) ||
		(InertiaCmpVelCmdDi_Cnt_T_logl == TRUE))
	{
		InertiaCmpVelCmdDiBmwOvrd_Cnt_T_logl = TRUE;
	}
	else
	{
		InertiaCmpVelCmdDiBmwOvrd_Cnt_T_logl = FALSE;
	} 
	return (InertiaCmpVelCmdDiBmwOvrd_Cnt_T_logl);
}

/*******************************************************************************
* Name          :   ClsdLoopHysEna
* Description   :   Implements logic for Pull compensation over-ride
* Inputs        :   HwTqCmdHys_HwNwtMtr_T_f32 -  Handwheel Torque Command Hysteresis from System
* Outputs       :   HwTqCmdHysBmwOvrd_HwNwtMtr_T_f32 - Calculated Handwheel Torque Command Hysteresis
* Usage Notes   :   None
*****************************************************************************/  
static FUNC(float32, AUTOMATIC) ClsdLoopHysEna(VAR(float32, AUTOMATIC) HwTqCmdHys_HwNwtMtr_T_f32)
{
	VAR(boolean, AUTOMATIC) BmwHysActv_Cnt_T_logl;
	VAR(float32, AUTOMATIC) HwTqCmdHysBmwOvrd_HwNwtMtr_T_f32;	
	
	if(Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val() == ZERO_ULS_U08)
	{
		BmwHysActv_Cnt_T_logl = FALSE;
	}
	else if(Rte_Prm_BmwSwFctDiBmwHysActvInflOvrd_Val() == ONE_ULS_U08)
	{
		BmwHysActv_Cnt_T_logl = FALSE;
	}	
	else
	{
		if(*Rte_Pim_BmwHysActvInfl() != 0u)
		{
			BmwHysActv_Cnt_T_logl = TRUE;
		}
		else
		{
			BmwHysActv_Cnt_T_logl = FALSE;
		}
	}
	
	if(BmwHysActv_Cnt_T_logl == TRUE)
	{
		HwTqCmdHysBmwOvrd_HwNwtMtr_T_f32 = HwTqCmdHys_HwNwtMtr_T_f32;
	}
	else
	{
		HwTqCmdHysBmwOvrd_HwNwtMtr_T_f32 = ZERO_ULS_F32;
	}
	
	HwTqCmdHysBmwOvrd_HwNwtMtr_T_f32 = Lim_f32(HwTqCmdHysBmwOvrd_HwNwtMtr_T_f32,MINHWTQCMDDAMPG_HWNWTMTR_F32, MAXHWTQCMDDAMPG_HWNWTMTR_F32);
	
	return (HwTqCmdHysBmwOvrd_HwNwtMtr_T_f32);
	
}

/*******************************************************************************
* Name          :   CtrldVelRtnEna
* Description   :   Implements logic for Pull compensation over-ride
* Inputs        :   CtrldVelRtnCmd_MotNwtMtr_T_f32 - Return command from System
* Outputs       :   CtrldVelRtnCmdBmwOvrd_MotNwtMtr_T_f32 - Calculated Return 
*                   Command Hysteresis
* Usage Notes   :   None
*****************************************************************************/  
static FUNC(float32, AUTOMATIC) CtrldVelRtnEna(	VAR(float32, AUTOMATIC) CtrldVelRtnCmd_MotNwtMtr_T_f32)
{
	VAR(boolean, AUTOMATIC) TmpBmwActvRtn_Cnt_T_logl;
	VAR(float32, AUTOMATIC) CtrldVelRtnCmdBmwOvrd_MotNwtMtr_T_f32 ;
	
	if(Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val() == ZERO_ULS_U08)
	{
		TmpBmwActvRtn_Cnt_T_logl = FALSE;
	}
	else if(Rte_Prm_BmwSwFctDiBmwActvRtnOvrd_Val() == ONE_ULS_U08)
	{
		TmpBmwActvRtn_Cnt_T_logl = TRUE;		
	}
	else
	{
		if(*Rte_Pim_BmwActvRtn() != 0u)
		{
			TmpBmwActvRtn_Cnt_T_logl = TRUE;
		}
		else
		{
			TmpBmwActvRtn_Cnt_T_logl = FALSE;			
		}
			
	}
	
	if(TmpBmwActvRtn_Cnt_T_logl == TRUE)
	{
		CtrldVelRtnCmdBmwOvrd_MotNwtMtr_T_f32 = CtrldVelRtnCmd_MotNwtMtr_T_f32;
	}
	else
	{
		CtrldVelRtnCmdBmwOvrd_MotNwtMtr_T_f32 = ZERO_ULS_F32;
	}
	
	CtrldVelRtnCmdBmwOvrd_MotNwtMtr_T_f32 = Lim_f32(CtrldVelRtnCmdBmwOvrd_MotNwtMtr_T_f32,SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32,SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32);

	return(CtrldVelRtnCmdBmwOvrd_MotNwtMtr_T_f32);
}

/*******************************************************************************
* Name          :   OvrdCmdEna
* Description   :   Implements logic for Pull compensation over-ride
* Inputs        :   OvrdCal_Cnt_T_u08 - Over-ride calibration value for the feature
*                   CodingBit_Cnt_T_u08 - Coding bit value for the feature
* Outputs       :   OvrlCmdEna_Cnt_T_logl - Override command Enable 
* Usage Notes   :   None
*****************************************************************************/  
static FUNC(boolean, AUTOMATIC) OvrdCmdEna( VAR(uint8, AUTOMATIC) OvrdCal_Cnt_T_u08, VAR(uint8, AUTOMATIC) CodingBit_Cnt_T_u08)
{
	VAR(boolean, AUTOMATIC) OvrlCmdEna_Cnt_T_logl;
	
	if(OvrdCal_Cnt_T_u08 == ZERO_ULS_U08)
	{
		OvrlCmdEna_Cnt_T_logl = FALSE;
	}
	else if(OvrdCal_Cnt_T_u08 == ONE_ULS_U08)
	{
		OvrlCmdEna_Cnt_T_logl = TRUE;
	}
	else
	{
		if(CodingBit_Cnt_T_u08 != 0u)
		{
			OvrlCmdEna_Cnt_T_logl = TRUE;
		}
		else
		{
			OvrlCmdEna_Cnt_T_logl = FALSE;
		}
	}	
	
	return(OvrlCmdEna_Cnt_T_logl);
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
