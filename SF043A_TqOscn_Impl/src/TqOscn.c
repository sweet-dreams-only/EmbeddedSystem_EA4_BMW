/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TqOscn.c
 *     SW-C Type:  TqOscn
 *  Generated at:  Thu May 26 12:28:19 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NXTR", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <TqOscn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : TqOscn.c
* Module Description: Implementation of Torque Oscillation algorithm (FDD SF043A)
* Project           : CBD 
* Author            : Krishna Kanth Anne
************************************************************************************************************************
* Version Control:
* %version          : 1 %
* %derived_by       : nz4qtt %
*----------------------------------------------------------------------------------------------------------------------
* Date        Rev      Author   Change Description                                                            SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  -----------
* 02/04/16     1        KK     	Initial Version                                                              EA4#2983      
* 04/12/16     2        KK     	Updates found during unit testing                                            EA4#5274
* 05/26/16     3        KK     	Updates as per FDD v1.2.0                                         			 EA4#5782
***********************************************************************************************************************/

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
  u5p11
    uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
     The order-relation on uint16 is: x < y if y - x is positive.
     uint16 has a lexical representation consisting of a finite-length sequence 
     of decimal digits (#x30-#x39).
     
     For example: 1, 0, 1267, +10000.

  u8p8
    uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
     The order-relation on uint16 is: x < y if y - x is positive.
     uint16 has a lexical representation consisting of a finite-length sequence 
     of decimal digits (#x30-#x39).
     
     For example: 1, 0, 1267, +10000.

 *********************************************************************************************************************/

#include "Rte_TqOscn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrFil.h"
#include "NxtrFixdPt.h"
#include "ArchGlbPrm.h"
#include "NxtrMath.h"
#include "FltInj.h"

/* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.1]: Calibration port pointers to array base types are cast back to their array type for 
code readability and to allow use of "sizeof". */

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include 
statements */

/* MISRA-C:2004 Rule 19.11 [NXTRDEV 19.11]: AUTOSAR requires deviation from this rule for Memory Mapping include 
statements */
 
#define DCCALCNLPFILFRQ_HZ_F32					(0.32F) 		
#define DCTHD_MOTNWTMTR_F32						(0.1F)
#define DFTFALLRAMPRATE_MOTNWTMTRPERSEC_F32		(-4400.0F)
#define DFTPHAAGINC_MATRAD_F32					(0.6283F)
#define DFTRISNGRAMPRATE_MOTNWTMTRPERSEC_F32	(4400.0F)
#define MAXAMP_MOTNWTMTR_F32					(1.2F)			
#define MINAMP_MOTNWTMTR_F32					(0.0F)				
#define MAXFRQ_CNT_U16							(12800U)
#define MINFRQ_CNT_U16							(2560U)
#define MAXRAMPRATE_MOTNWTMTR_F32				(4400.0F)
#define MINRAMPRATE_MOTNWTMTR_F32				(0.1F)
 
#define PrmTqOscnAmpLim_u5p11	(*(const Ary1D_u5p11_11 *)	Rte_Prm_TqOscnAmpLimY_Ary1D())
#define PrmTqOscnFrqIn_u8p8		(*(const Ary1D_u8p8_11 *)	Rte_Prm_TqOscnFrqIn_Ary1D())

static FUNC(float32, AUTOMATIC)  ChkFlg(float32 PhaAg_MatRad_T_f32);


static FUNC(float32, AUTOMATIC)  AmpRateLim(float32 CmdAmp_MotNwtMtr_T_f32,
											float32 HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32,
											float32 HwOscnFallRampRate_MotNwtMtrPerSec_T_f32,
											boolean HwOscnEna_Cnt_T_logl,
											P2VAR(boolean, AUTOMATIC, TqOscn_VAR) NonZeroAmpFlg_Cnt_T_logl);
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
 * u5p11: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 *
 * Array Types:
 * ============
 * Ary1D_u5p11_11: Array with 11 element(s) of type u5p11
 * Ary1D_u8p8_11: Array with 11 element(s) of type u8p8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_AmpRampSt(void)
 *   float32 *Rte_Pim_PrevFallRampRate(void)
 *   float32 *Rte_Pim_PrevLimdAmp(void)
 *   float32 *Rte_Pim_PrevPhaAg(void)
 *   float32 *Rte_Pim_PrevPhaAgInc(void)
 *   float32 *Rte_Pim_PrevRisngRampRate(void)
 *   float32 *Rte_Pim_dTqOscnPreFinalCmd(void)
 *   float32 *Rte_Pim_dTqOscnRateLimdAmp(void)
 *   float32 *Rte_Pim_dTqOscnSinCmd(void)
 *   boolean *Rte_Pim_PrevActv(void)
 *   boolean *Rte_Pim_PrevDcThdExcdd(void)
 *   boolean *Rte_Pim_PrevEna(void)
 *   boolean *Rte_Pim_dTqOscnNonZeroAmpFlg(void)
 *   FilLpRec1 *Rte_Pim_PreFinalCmdLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_TqOscnFallRampRateCal_Val(void)
 *   float32 Rte_Prm_TqOscnRisngRampRateCal_Val(void)
 *   boolean Rte_Prm_TqOscnUseRampRateCal_Logl(void)
 *   u5p11 *Rte_Prm_TqOscnAmpLimY_Ary1D(void)
 *   u8p8 *Rte_Prm_TqOscnFrqIn_Ary1D(void)
 *
 *********************************************************************************************************************/


#define TqOscn_START_SEC_CODE
#include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqOscnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, TqOscn_CODE) TqOscnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TqOscnInit1
 *********************************************************************************************************************/

 /*** Filter initialization ***/
 FilLpInit( 0.0F, DCCALCNLPFILFRQ_HZ_F32, ARCHGLBPRM_2MILLISEC_SEC_F32, Rte_Pim_PreFinalCmdLpFil() );
 
 *Rte_Pim_PrevRisngRampRate()	= DFTRISNGRAMPRATE_MOTNWTMTRPERSEC_F32;
 *Rte_Pim_PrevFallRampRate()	= DFTFALLRAMPRATE_MOTNWTMTRPERSEC_F32;
 *Rte_Pim_PrevPhaAgInc()		= DFTPHAAGINC_MATRAD_F32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TqOscnPer1
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
 *   Std_ReturnType Rte_Read_HwOscnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_HwOscnFallRampRate_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnFrq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnMotAmp_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwOscnRisngRampRate_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwOscnActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwOscnCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwOscnDcThdExcdd_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, TqOscn_CODE) TqOscnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TqOscnPer1
 *********************************************************************************************************************/
	
	VAR(boolean, AUTOMATIC) HwOscnEna_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) DCCmp_Cnt_T_logl = FALSE;
	VAR(boolean, AUTOMATIC) TqOscnDcExcdd_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) HwOscnActv_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) NonZeroAmpFlg_Cnt_T_logl;
		
	VAR(float32, AUTOMATIC) TqOscnPhaAg_MatRad_T_f32;
	VAR(float32, AUTOMATIC) HwOscnMotAmp_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwOscnFrq_HZ_T_f32;
	VAR(float32, AUTOMATIC) TqOscnFrqAbslt_Hz_T_f32;
	VAR(float32, AUTOMATIC) TqOscnCmd_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) PreFinalCmd_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) TqOscnPhaAgSin_Uls_T_f32;
	VAR(float32, AUTOMATIC)	TqOscnAmpAbslt_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC)	SatTqOscnAmpAbslt_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC)	PhaAg_MatRad_T_f32;
	VAR(float32, AUTOMATIC)	PhaAgInc_MatRad_T_f32;
	VAR(float32, AUTOMATIC)	LimdAmp_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC)	RateLimdAmp_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC)	HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32;
	VAR(float32, AUTOMATIC)	HwOscnFallRampRate_MotNwtMtrPerSec_T_f32;
	
	VAR(uint16, AUTOMATIC) 	TqOscnFrqAbslt_Hz_T_u8p8;
	VAR(uint16, AUTOMATIC)	EfcTqOscnFrqAbslt_Hz_T_u8p8;
	VAR(uint16, AUTOMATIC) 	FrqIndex1_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 	FrqIndex2_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 	TqOscnAmp_MotNwtMtr_T_u5p11;
	 
	 
	 /*** Read inputs from RTE ***/
	(void)Rte_Read_HwOscnMotAmp_Val(&HwOscnMotAmp_MotNwtMtr_T_f32);							/* REQ: SF043A #300 I */
	(void)Rte_Read_HwOscnEna_Logl(&HwOscnEna_Cnt_T_logl);									/* REQ: SF043A #298 I */
	(void)Rte_Read_HwOscnFrq_Val(&HwOscnFrq_HZ_T_f32);										/* REQ: SF043A #299 I */
	(void)Rte_Read_HwOscnFallRampRate_Val(&HwOscnFallRampRate_MotNwtMtrPerSec_T_f32);		/* REQ: SF043A #302 I */
	(void)Rte_Read_HwOscnRisngRampRate_Val(&HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32);		/* REQ: SF043A #301 I */
	
	/*** Start of Update Variables ***/
	/* REQ: SF043A #314 I */ /* REQ: SF043A #320 I */ /* REQ: SF043A #321 I */ /* REQ: SF043A #322 I */
	if( (TRUE == HwOscnEna_Cnt_T_logl) && (FALSE == *Rte_Pim_PrevEna()) )
	{
		/*** CaptureInputs_UpdatePIM ***/ 
		/*** Lookup table implementation ***/
		TqOscnFrqAbslt_Hz_T_f32 	= Abslt_f32_f32(HwOscnFrq_HZ_T_f32);
		TqOscnFrqAbslt_Hz_T_u8p8	= FloatToFixd_u16_f32(TqOscnFrqAbslt_Hz_T_f32, NXTRFIXDPT_FLOATTOP8_ULS_F32);
		
		if (TqOscnFrqAbslt_Hz_T_u8p8 <= PrmTqOscnFrqIn_u8p8[0U])
		{
			TqOscnFrqAbslt_Hz_T_u8p8 = PrmTqOscnFrqIn_u8p8[0U];
		}
		else if(TqOscnFrqAbslt_Hz_T_u8p8 >= (PrmTqOscnFrqIn_u8p8[TblSize_m(PrmTqOscnFrqIn_u8p8)-1U]))
		{

			TqOscnFrqAbslt_Hz_T_u8p8 = PrmTqOscnFrqIn_u8p8[TblSize_m(PrmTqOscnFrqIn_u8p8)-1U];
		} 
		else
		{
			FrqIndex1_Cnt_T_u16 = 0U;
			while( PrmTqOscnFrqIn_u8p8[FrqIndex1_Cnt_T_u16+1U] <= TqOscnFrqAbslt_Hz_T_u8p8)
			{

				FrqIndex1_Cnt_T_u16++;
			}
			TqOscnFrqAbslt_Hz_T_u8p8 = PrmTqOscnFrqIn_u8p8[FrqIndex1_Cnt_T_u16];
		}
		
		EfcTqOscnFrqAbslt_Hz_T_u8p8 = Lim_u16(TqOscnFrqAbslt_Hz_T_u8p8, MINFRQ_CNT_U16, MAXFRQ_CNT_U16);
												
		/*** Lookup table implementation ***/
		if (EfcTqOscnFrqAbslt_Hz_T_u8p8 <= PrmTqOscnFrqIn_u8p8[0U])
		{
			TqOscnAmp_MotNwtMtr_T_u5p11 = PrmTqOscnAmpLim_u5p11[0U];
			
		}
		else if(EfcTqOscnFrqAbslt_Hz_T_u8p8 >= PrmTqOscnFrqIn_u8p8[TblSize_m(PrmTqOscnFrqIn_u8p8)-1U])
		{
			TqOscnAmp_MotNwtMtr_T_u5p11 = PrmTqOscnAmpLim_u5p11[TblSize_m(PrmTqOscnAmpLim_u5p11)-1U];
		} 
		else
		{
			FrqIndex2_Cnt_T_u16 = 0U;
			while( PrmTqOscnFrqIn_u8p8[FrqIndex2_Cnt_T_u16+1U] <= EfcTqOscnFrqAbslt_Hz_T_u8p8)
			{
				FrqIndex2_Cnt_T_u16++;
			}
			TqOscnAmp_MotNwtMtr_T_u5p11 = PrmTqOscnAmpLim_u5p11[FrqIndex2_Cnt_T_u16];
		}													
																
																
		TqOscnAmpAbslt_MotNwtMtr_T_f32 			= FixdToFloat_f32_u16(TqOscnAmp_MotNwtMtr_T_u5p11, NXTRFIXDPT_P11TOFLOAT_ULS_F32);
		SatTqOscnAmpAbslt_MotNwtMtr_T_f32 		= Lim_f32(Abslt_f32_f32(HwOscnMotAmp_MotNwtMtr_T_f32), 0.0F, TqOscnAmpAbslt_MotNwtMtr_T_f32);
		LimdAmp_MotNwtMtr_T_f32					= Lim_f32(SatTqOscnAmpAbslt_MotNwtMtr_T_f32, MINAMP_MOTNWTMTR_F32, MAXAMP_MOTNWTMTR_F32);
		TqOscnFrqAbslt_Hz_T_f32					= FixdToFloat_f32_u16(EfcTqOscnFrqAbslt_Hz_T_u8p8, NXTRFIXDPT_P8TOFLOAT_ULS_F32);
		PhaAgInc_MatRad_T_f32					= TqOscnFrqAbslt_Hz_T_f32 * ARCHGLBPRM_2PI_ULS_F32 * ARCHGLBPRM_2MILLISEC_SEC_F32;
			
		*Rte_Pim_PrevLimdAmp()					= LimdAmp_MotNwtMtr_T_f32;						/*** PIM update ***/
		*Rte_Pim_PrevPhaAgInc()					= PhaAgInc_MatRad_T_f32;						/*** PIM update ***/
		*Rte_Pim_PrevFallRampRate()				= HwOscnFallRampRate_MotNwtMtrPerSec_T_f32;		/*** PIM update ***/
		*Rte_Pim_PrevRisngRampRate()			= HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32;	/*** PIM update ***/
	}
	else
	{
		/*** UsePreviousValues ***/
		PhaAgInc_MatRad_T_f32 						= *Rte_Pim_PrevPhaAgInc();
		LimdAmp_MotNwtMtr_T_f32 					= *Rte_Pim_PrevLimdAmp();
		HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32	= *Rte_Pim_PrevRisngRampRate();
		HwOscnFallRampRate_MotNwtMtrPerSec_T_f32	= *Rte_Pim_PrevFallRampRate();
		
	}
	/*** PIM update ***/			
	/* REQ: SF043A #314 I */ /* REQ: SF043A #320 I */ /* REQ: SF043A #321 I */ /* REQ: SF043A #322 I */
	*Rte_Pim_PrevEna() 								= HwOscnEna_Cnt_T_logl;						
	/*** End of Update Variables ***/
	
	/*** Start of Angle Wrapper ***/
	TqOscnPhaAg_MatRad_T_f32 = (PhaAgInc_MatRad_T_f32 + *Rte_Pim_PrevPhaAg());
	
	if( TqOscnPhaAg_MatRad_T_f32 >= ARCHGLBPRM_2PI_ULS_F32 )
	{
		PhaAg_MatRad_T_f32 	= TqOscnPhaAg_MatRad_T_f32 - ARCHGLBPRM_2PI_ULS_F32;
	}
	else
	{
		PhaAg_MatRad_T_f32 	= TqOscnPhaAg_MatRad_T_f32;
	}
	/*** End of Angle Wrapper ***/
	
	/*** Start of CheckFlag ***/
	TqOscnPhaAg_MatRad_T_f32 		= ChkFlg(PhaAg_MatRad_T_f32);
	*Rte_Pim_PrevPhaAg()			= TqOscnPhaAg_MatRad_T_f32; 								/*** PIM update ***/	
	/*** End of CheckFlag ***/
	
	/*** Start of  Amplitude Rate Limiter ***/
	RateLimdAmp_MotNwtMtr_T_f32 	= 	AmpRateLim(LimdAmp_MotNwtMtr_T_f32,
												   HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32,
												   HwOscnFallRampRate_MotNwtMtrPerSec_T_f32,
												   HwOscnEna_Cnt_T_logl,
												   &NonZeroAmpFlg_Cnt_T_logl);
												   
	
	*Rte_Pim_dTqOscnRateLimdAmp()	= RateLimdAmp_MotNwtMtr_T_f32; 								/*** Display variable update ***/
	*Rte_Pim_dTqOscnNonZeroAmpFlg()	= NonZeroAmpFlg_Cnt_T_logl;									/*** Display variable update ***/
	/*** End of  Amplitude Rate Limiter ***/
	
	TqOscnPhaAgSin_Uls_T_f32 		= Sin_f32(TqOscnPhaAg_MatRad_T_f32);
	*Rte_Pim_dTqOscnSinCmd()		= TqOscnPhaAgSin_Uls_T_f32; 								/*** Display variable update ***/
	PreFinalCmd_MotNwtMtr_T_f32 	= TqOscnPhaAgSin_Uls_T_f32 * RateLimdAmp_MotNwtMtr_T_f32;
	*Rte_Pim_dTqOscnPreFinalCmd()	= PreFinalCmd_MotNwtMtr_T_f32; 								/*** Display variable update ***/

	
	/*** Start of  FltInj_f32 client ***/
	 #if (STD_ON == FLTINJENA)   
         (void) Rte_Call_FltInj_f32_Oper(&PreFinalCmd_MotNwtMtr_T_f32, FLTINJ_TQOSCN_PREFINALCMD);  
     #endif
	/*** End of  FltInj_f32 client ***/
	
	
	/*** Start of DC Check ***/
		/*** Start of DC Trend ***/
	if( Abslt_f32_f32(FilLpUpdOutp_f32(PreFinalCmd_MotNwtMtr_T_f32, Rte_Pim_PreFinalCmdLpFil())) >= DCTHD_MOTNWTMTR_F32 )
	{
		DCCmp_Cnt_T_logl = TRUE;
	}
		/*** End of DC Trend ***/
	
		/*** DC_Detd ***/
	if((TRUE == DCCmp_Cnt_T_logl) || (TRUE == *Rte_Pim_PrevDcThdExcdd()))
	{
		TqOscnDcExcdd_Cnt_T_logl	= TRUE;
		TqOscnCmd_MotNwtMtr_T_f32	= 0.0F;
	}
		/*** DC_ok ***/
	else
	{
		TqOscnDcExcdd_Cnt_T_logl	= FALSE;
		TqOscnCmd_MotNwtMtr_T_f32 	= PreFinalCmd_MotNwtMtr_T_f32;
	}
	*Rte_Pim_PrevDcThdExcdd()		= TqOscnDcExcdd_Cnt_T_logl;						/*** PIM update ***/
	/*** End of DC Check ***/
	
	if( (TqOscnDcExcdd_Cnt_T_logl == FALSE) && (NonZeroAmpFlg_Cnt_T_logl == TRUE) )
	
	{
		/* REQ: SF043A #337 I */
		HwOscnActv_Cnt_T_logl 		= TRUE;
	}
	else
	{
		/* REQ: SF043A #332 I */
		HwOscnActv_Cnt_T_logl 		= FALSE;
	}
	
	*Rte_Pim_PrevActv() 			= HwOscnActv_Cnt_T_logl;						/*** PIM update ***/
	
	/*** Range limit and Write outputs to RTE ***/
	/* REQ: SF043A #304 I */ /* REQ: SF043A #341 I */ /* REQ: SF043A #344 I */
	(void)Rte_Write_HwOscnCmd_Val(Lim_f32(TqOscnCmd_MotNwtMtr_T_f32, -MAXAMP_MOTNWTMTR_F32, MAXAMP_MOTNWTMTR_F32));
	/* REQ: SF043A #305 I */ /* REQ: SF043A #342 I */ /* REQ: SF043A #346 I */
	(void)Rte_Write_HwOscnDcThdExcdd_Logl(TqOscnDcExcdd_Cnt_T_logl);	
	/* REQ: SF043A #306 I */ /* REQ: SF043A #340 I */ /* REQ: SF043A #345 I */
	(void)Rte_Write_HwOscnActv_Logl(HwOscnActv_Cnt_T_logl);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define TqOscn_STOP_SEC_CODE
#include "TqOscn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************************************************
* Name        :   AmpRateLim
* Description :   Sub function that calculates Amplitude Rate Limiter and reduce the cyclomatic complexity.
* Inputs      :   CmdAmp_MotNwtMtr_T_f32, HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32, 
*			  :   HwOscnFallRampRate_MotNwtMtrPerSec_T_f32, HwOscnEna_Cnt_T_logl, *NonZeroAmpFlg_Cnt_T_logl
* Outputs     :   RateLimdAmp_MotNwtMtr_T_f32, *Rte_Pim_AmpRampSt()
* Usage Notes :   None
****************************************************************************************************************/


static FUNC(float32, AUTOMATIC)  AmpRateLim(float32 CmdAmp_MotNwtMtr_T_f32,
											float32 HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32,
											float32 HwOscnFallRampRate_MotNwtMtrPerSec_T_f32,
											boolean HwOscnEna_Cnt_T_logl,
											P2VAR(boolean, AUTOMATIC, TqOscn_VAR) NonZeroAmpFlg_Cnt_T_logl)
{
	VAR(float32, AUTOMATIC) DynLwrLmtAmp_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) DynUprLmtAmp_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) PreLmtAmplitude_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) RateLimdAmp_MotNwtMtr_T_f32;
	
	if(HwOscnEna_Cnt_T_logl == FALSE) 
	{

		PreLmtAmplitude_MotNwtMtr_T_f32 = 0.0F;
	}
	else
	{
		PreLmtAmplitude_MotNwtMtr_T_f32 = CmdAmp_MotNwtMtr_T_f32;
	}

	/* REQ: SF043A #327 I */ /* REQ: SF043A #328 I */ /* REQ: SF043A #329 I */
	if(TRUE == Rte_Prm_TqOscnUseRampRateCal_Logl() )
	{

		/* REQ: SF043A #327 I */ /* REQ: SF043A #328 I */ /* REQ: SF043A #329 I */ /* REQ: SF043A #331 I */
		DynLwrLmtAmp_MotNwtMtr_T_f32			= Lim_f32(Rte_Prm_TqOscnFallRampRateCal_Val(), -MAXRAMPRATE_MOTNWTMTR_F32, -MINRAMPRATE_MOTNWTMTR_F32);
		DynUprLmtAmp_MotNwtMtr_T_f32			= Lim_f32(Rte_Prm_TqOscnRisngRampRateCal_Val(), MINRAMPRATE_MOTNWTMTR_F32,  MAXRAMPRATE_MOTNWTMTR_F32);
	}

	else 
	{
		/* REQ: SF043A #328 I */ /* REQ: SF043A #329 I */ /* REQ: SF043A #330 I */
		DynLwrLmtAmp_MotNwtMtr_T_f32			= Lim_f32(HwOscnFallRampRate_MotNwtMtrPerSec_T_f32, -MAXRAMPRATE_MOTNWTMTR_F32, -MINRAMPRATE_MOTNWTMTR_F32);
		DynUprLmtAmp_MotNwtMtr_T_f32			= Lim_f32(HwOscnRisngRampRate_MotNwtMtrPerSec_T_f32, MINRAMPRATE_MOTNWTMTR_F32,  MAXRAMPRATE_MOTNWTMTR_F32);

	}

	/* REQ: SF043A #325 I */ /* REQ: SF043A #326 I */
	RateLimdAmp_MotNwtMtr_T_f32					= Lim_f32( PreLmtAmplitude_MotNwtMtr_T_f32,
														   ((DynLwrLmtAmp_MotNwtMtr_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + (*Rte_Pim_AmpRampSt())),
														   ((DynUprLmtAmp_MotNwtMtr_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + (*Rte_Pim_AmpRampSt())) );

	*Rte_Pim_AmpRampSt()						= RateLimdAmp_MotNwtMtr_T_f32;		/*** PIM update ***/
	
	if(RateLimdAmp_MotNwtMtr_T_f32 > 0.0F)
	{
		*NonZeroAmpFlg_Cnt_T_logl 	= TRUE;
	}

	else
	{
		*NonZeroAmpFlg_Cnt_T_logl 	= FALSE;
	}
	
	return RateLimdAmp_MotNwtMtr_T_f32;

}

/*****************************************************************************************************************
* Name        :   ChkFlg
* Description :   Sub function that calculates ChkFlg and reduce the cyclomatic complexity.
* Inputs      :   PhaAg_MatRad_T_f32, *Rte_Pim_PrevActv()
* Outputs     :   TqOscnPhaAg_MatRad_T_f32
* Usage Notes :   None
****************************************************************************************************************/
static FUNC(float32, AUTOMATIC)  ChkFlg(float32 PhaAg_MatRad_T_f32)
{
	VAR(float32, AUTOMATIC) TqOscnPhaAg_MatRad_T_f32;
	
	if(TRUE == *Rte_Pim_PrevActv() )
	{
		TqOscnPhaAg_MatRad_T_f32 = PhaAg_MatRad_T_f32;
	}
	else
	{
		TqOscnPhaAg_MatRad_T_f32 = 0.0F;	
	}
	
	return(TqOscnPhaAg_MatRad_T_f32);
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
