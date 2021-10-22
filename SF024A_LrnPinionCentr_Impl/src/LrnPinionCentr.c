/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  LrnPinionCentr.c
 *        Config:  C:/_Synergy_Projects/Working/ses_dev_ea4/SF024A_LrnPinionCentr_Impl/tools/Component.dpa
 *     SW-C Type:  LrnPinionCentr
 *  Generated at:  Fri Jan 12 08:38:01 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <LrnPinionCentr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2017, 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name  : LrnPinionCentr.c
* Module Description: Implementation of Learn Pinion Center FDD (SF024A)
* Project           : CBD 
* Author            : Matthew Leser
***********************************************************************************************************************
* Version Control:
* %version          : 2 %
* %derived_by       : nz3734 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/01/17  1        ML       Initial Version                                                                 EA4#14379  
* 01/12/18  2        BRB      Update for anomaly EA4#17174                                                    EA4#17556                                                             
**********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_LrnPinionCentr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "NxtrFil.h"
#include "NxtrMath.h"
#include "ArchGlbPrm.h" 
#include "SysGlbPrm.h"
 
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value Rte_Read, Rte_Write*/ 
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.2]: Server runnable is a void functon; Rte generation adds standard return type 
                                              but no error information is returned for GetTiSpan100MicroSec32bit and
                                              GetRefTmr100MicroSec32bit */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */ 
 
#define AVRG_ULS_F32                             (0.5F)
#define CUTOFFFRQLOWRLIM_HZ_F32                  (1.0F)
#define CUTOFFFRQUPPRLIM_HZ_F32                  (150.0F)
#define MILLICNV100MICRO_ULS_U16                 10U
#define PINIONCENTRLRNHWCENTRLOWRLIM_HWDEG_F32   (-1440.0F)
#define PINIONCENTRLRNHWCENTRUPPRLIM_HWDEG_F32   (1440.0F)
#define PINIONCENTRLRNHWTRVLLOWRLIM_HWDEG_F32    (0.0F)
#define PINIONCENTRLRNHWTRVLUPPRLIM_HWDEG_F32    (2880.0F)
#define PINIONCENTRLRNSTLOWRLIM_CNT_U08          0U
#define PINIONCENTRLRNSTUPPRLIM_CNT_U08          7U
#define ST2_ULS_U08                              2U
#define ST3_ULS_U08                              3U
#define ST4_ULS_U08                              4U
#define ST5_ULS_U08                              5U
#define ST6_ULS_U08                              6U
#define ST7_ULS_U08                              7U
#define TARHWALOWRLIM_HWDEGPERSECPERSEC_F32      (100.0F)
#define TARHWAUPPRLIM_HWDEGPERSECPERSEC_F32      (50000.0F)
#define TARHWVELLOWRLIM_HWDEGPERSEC_F32          (10.0F)   
#define TARHWVELUPPRLIM_HWDEGPERSEC_F32          (1000.0F)
#define TARMOTPOSN_MOTRAD_F32                    (603.185789F)

static FUNC(void, LRNPINIONCNTR_CODE) RunMinMax(float32 HwAg_HwDeg_T_f32,
                                                boolean PinionCentrLrnEna_Cnt_T_logl,
                                                P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MaxHwPosn_HwDeg_T_f32,
                                                P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MinHwPosn_HwDeg_T_f32);

static FUNC(void, LRNPINIONCNTR_CODE) PosAgVelStCtrl1(float32 HwAg_HwDeg_T_f32,
                                                       float32 MotVelCrf_MotRadPerSec_T_f32,
                                                       float32 TarMotVel_MotRadPerSec_T_f32,
                                                       P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32);
                                                       
static FUNC(void, LRNPINIONCNTR_CODE) PosMotTqStCtrl2(P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32);                                                       

static FUNC(void, LRNPINIONCNTR_CODE) NegAgVelStCtrl3(float32 HwAg_HwDeg_T_f32,
                                                       float32 MotVelCrf_MotRadPerSec_T_f32,
                                                       float32 TarMotVel_MotRadPerSec_T_f32,
                                                       P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32);   

static FUNC(void, LRNPINIONCNTR_CODE) NegMotTqStCtrl4(float32 MaxHwPosn_HwDeg_T_f32,
                                                       float32 MinHwPosn_HwDeg_T_f32,
                                                       P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32);

static FUNC(void, LRNPINIONCNTR_CODE) MoveToStCtrl5(float32 HwAg_HwDeg_T_f32,
                                                    float32 TarHwAg_HwDeg_T_f32,
                                                    float32 MotVelCrf_MotRadPerSec_T_f32,
                                                    float32 TarMotVel_MotRadPerSec_T_f32,
                                                    P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                    P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                    P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32);

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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
 * FilLpRec1: Record with elements
 *   FilSt of type float32
 *   FilGain of type float32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_MaxHwPosnPrev(void)
 *   float32 *Rte_Pim_MinHwPosnPrev(void)
 *   float32 *Rte_Pim_PinionCentrLrnHwCentrPrev(void)
 *   float32 *Rte_Pim_PinionCentrLrnHwTrvlPrev(void)
 *   float32 *Rte_Pim_StCtrl1PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl2TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl3PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl3TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl4TqErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl5IntglEnaOutpPrev(void)
 *   float32 *Rte_Pim_StCtrl5PosnErrRateLim(void)
 *   float32 *Rte_Pim_StCtrl5TqErrRateLim(void)
 *   float32 *Rte_Pim_TarHwAg(void)
 *   float32 *Rte_Pim_TarMotVel(void)
 *   float32 *Rte_Pim_TqCmdEstimdPrev(void)
 *   float32 *Rte_Pim_dLrnPinionCentrHwPosnCmd(void)
 *   uint32 *Rte_Pim_StCtrl1TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl1TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl2TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl2TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl3TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl3TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl4TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl4TmrBRefTi(void)
 *   uint32 *Rte_Pim_StCtrl5TmrARefTi(void)
 *   uint32 *Rte_Pim_StCtrl5TmrBRefTi(void)
 *   uint8 *Rte_Pim_StEstimdPrev(void)
 *   boolean *Rte_Pim_PinionCentrLrnEnaPrev(void)
 *   FilLpRec1 *Rte_Pim_StCtrl1RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl2RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl3RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl3RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl4RateLimdTqErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl5RateLimdPosnErrLpFil(void)
 *   FilLpRec1 *Rte_Pim_StCtrl5RateLimdTqErrLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_LrnPinionCentrDampgCtrlGain_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTq_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTqErrThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHldTqRateLim_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrHwPosnErrThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrIntglCtrlGain_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMaxTqCmd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMinMotTq_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrMotVelThd_Val(void)
 *   float32 Rte_Prm_LrnPinionCentrPropCtrlGain_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint16 Rte_Prm_LrnPinionCentrTiOutThd_Val(void)
 *   uint16 Rte_Prm_LrnPinionCentrTiThd_Val(void)
 *
 *********************************************************************************************************************/


#define LrnPinionCentr_START_SEC_CODE
#include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnPinionCentrInit1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LrnPinionCentrInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LrnPinionCentrInit1
 *********************************************************************************************************************/

 VAR(float32, AUTOMATIC) HwAg_HwDeg_T_f32;
 
 (void)Rte_Read_HwAg_Val(&HwAg_HwDeg_T_f32);
 
 FilLpInit(0.0F,0.0F,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl2RateLimdTqErrLpFil());
 FilLpInit(0.0F,0.0F,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl3RateLimdTqErrLpFil());
 FilLpInit(0.0F,0.0F,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl5RateLimdPosnErrLpFil());
 FilLpInit(0.0F,0.0F,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl1RateLimdPosnErrLpFil());
 FilLpInit(0.0F,0.0F,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl3RateLimdPosnErrLpFil());
 FilLpInit(0.0F,0.0F,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl4RateLimdTqErrLpFil());
 FilLpInit(0.0F,0.0F,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl5RateLimdTqErrLpFil());
 
 *Rte_Pim_MaxHwPosnPrev() = HwAg_HwDeg_T_f32;
 *Rte_Pim_MinHwPosnPrev() = HwAg_HwDeg_T_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LrnPinionCentrPer1
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
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelCrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnEna_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PinionCentrLrnCmd_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnHwCentr_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnHwTrvl_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionCentrLrnSt_Val(uint8 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_LrnPinionCentrPer1_TarA(void)
 *   float32 Rte_IrvRead_LrnPinionCentrPer1_TarVel(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: LrnPinionCentrPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrnPinionCentr_CODE) LrnPinionCentrPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LrnPinionCentrPer1
 *********************************************************************************************************************/

 /*** Inputs ***/
 VAR(float32, AUTOMATIC) HwAg_HwDeg_T_f32;
 VAR(float32, AUTOMATIC) TarHwAg_HwDeg_T_f32;
 VAR(float32, AUTOMATIC) MotVelCrf_MotRadPerSec_T_f32;
 VAR(boolean, AUTOMATIC) PinionCentrLrnEna_Cnt_T_logl;
 VAR(float32, AUTOMATIC) TarA_HwDegPerSecPerSec_T_f32;
 VAR(float32, AUTOMATIC) TarVel_HwDegPerSec_T_f32; 
 
 /*** Outputs ***/
 VAR(float32, AUTOMATIC) PinionCentrLrnCmd_MotNwtMtr_T_f32;
 VAR(uint8,   AUTOMATIC) PinionCentrLrnSt_Cnt_T_u08;
 VAR(uint8,   AUTOMATIC) CaseSeln_Cnt_T_u08;
 
 /*** Temporary Variables ***/
 VAR(float32, AUTOMATIC) TarMotVel_MotRadPerSec_T_f32;
 VAR(float32, AUTOMATIC) CutOffFrq_Hz_T_f32;
 VAR(float32, AUTOMATIC) TqCmd_MotNwtMtr_T_f32;
 VAR(float32, AUTOMATIC) MotPosnCmd_MotRad_T_f32;
 VAR(float32, AUTOMATIC) MaxHwPosn_HwDeg_T_f32;
 VAR(float32, AUTOMATIC) MinHwPosn_HwDeg_T_f32;
 VAR(uint32, AUTOMATIC) Tmr_Cnt_T_u32;
 
 (void)Rte_Read_HwAg_Val(&HwAg_HwDeg_T_f32);
 (void)Rte_Read_MotVelCrf_Val(&MotVelCrf_MotRadPerSec_T_f32);
 (void)Rte_Read_PinionCentrLrnEna_Logl(&PinionCentrLrnEna_Cnt_T_logl);
 TarA_HwDegPerSecPerSec_T_f32 = Rte_IrvRead_LrnPinionCentrPer1_TarA();
 TarVel_HwDegPerSec_T_f32 = Rte_IrvRead_LrnPinionCentrPer1_TarVel();
 
 
 if((PinionCentrLrnEna_Cnt_T_logl == TRUE) && (*Rte_Pim_PinionCentrLrnEnaPrev() == FALSE))
 {
     *Rte_Pim_TarHwAg() = HwAg_HwDeg_T_f32;
     TarHwAg_HwDeg_T_f32 = HwAg_HwDeg_T_f32;
     
     TarVel_HwDegPerSec_T_f32 = Lim_f32(Abslt_f32_f32(TarVel_HwDegPerSec_T_f32), TARHWVELLOWRLIM_HWDEGPERSEC_F32, TARHWVELUPPRLIM_HWDEGPERSEC_F32);
     TarMotVel_MotRadPerSec_T_f32 = TarVel_HwDegPerSec_T_f32 * Rte_Prm_SysGlbPrmSysKineRat_Val() * ARCHGLBPRM_PIOVER180_ULS_F32;
     *Rte_Pim_TarMotVel() = TarMotVel_MotRadPerSec_T_f32;
     
     TarA_HwDegPerSecPerSec_T_f32 = Lim_f32(Abslt_f32_f32(TarA_HwDegPerSecPerSec_T_f32), TARHWALOWRLIM_HWDEGPERSECPERSEC_F32, TARHWAUPPRLIM_HWDEGPERSECPERSEC_F32);
     CutOffFrq_Hz_T_f32 = TarA_HwDegPerSecPerSec_T_f32 / (TarVel_HwDegPerSec_T_f32 * ARCHGLBPRM_2PI_ULS_F32);
     CutOffFrq_Hz_T_f32 = Lim_f32(CutOffFrq_Hz_T_f32, CUTOFFFRQLOWRLIM_HZ_F32, CUTOFFFRQUPPRLIM_HZ_F32);
     
     FilLpUpdGain(CutOffFrq_Hz_T_f32,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl2RateLimdTqErrLpFil());
     FilLpUpdGain(CutOffFrq_Hz_T_f32,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl3RateLimdTqErrLpFil());
     FilLpUpdGain(CutOffFrq_Hz_T_f32,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl5RateLimdPosnErrLpFil());
     FilLpUpdGain(CutOffFrq_Hz_T_f32,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl1RateLimdPosnErrLpFil());
     FilLpUpdGain(CutOffFrq_Hz_T_f32,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl3RateLimdPosnErrLpFil());
     FilLpUpdGain(CutOffFrq_Hz_T_f32,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl4RateLimdTqErrLpFil());
     FilLpUpdGain(CutOffFrq_Hz_T_f32,ARCHGLBPRM_2MILLISEC_SEC_F32,Rte_Pim_StCtrl5RateLimdTqErrLpFil());
 }
 else
 {
     TarHwAg_HwDeg_T_f32 = *Rte_Pim_TarHwAg();
     TarMotVel_MotRadPerSec_T_f32 = *Rte_Pim_TarMotVel();
 }
 
 /*** State Control ***/
 *Rte_Pim_PinionCentrLrnEnaPrev() = PinionCentrLrnEna_Cnt_T_logl;
 
 if(PinionCentrLrnEna_Cnt_T_logl == TRUE)
 {
     CaseSeln_Cnt_T_u08 = *Rte_Pim_StEstimdPrev();
 }
 else
 {
     CaseSeln_Cnt_T_u08 = 0U;
 }
 
 /* Running MinMax */
 RunMinMax(HwAg_HwDeg_T_f32,
           PinionCentrLrnEna_Cnt_T_logl,
           &MaxHwPosn_HwDeg_T_f32,
           &MinHwPosn_HwDeg_T_f32);
 
 switch(CaseSeln_Cnt_T_u08)
 {
     case(1U):
     {
         PosAgVelStCtrl1(HwAg_HwDeg_T_f32,
                          MotVelCrf_MotRadPerSec_T_f32,
                          TarMotVel_MotRadPerSec_T_f32,
                          &PinionCentrLrnSt_Cnt_T_u08,
                          &TqCmd_MotNwtMtr_T_f32,
                          &MotPosnCmd_MotRad_T_f32);
     }
     break;
     case(2U):
     {
         PosMotTqStCtrl2(&PinionCentrLrnSt_Cnt_T_u08,
                          &TqCmd_MotNwtMtr_T_f32,
                          &MotPosnCmd_MotRad_T_f32);
     }
     break;
     case(3U):
     {
         NegAgVelStCtrl3(HwAg_HwDeg_T_f32,
                          MotVelCrf_MotRadPerSec_T_f32,
                          TarMotVel_MotRadPerSec_T_f32,
                          &PinionCentrLrnSt_Cnt_T_u08,
                          &TqCmd_MotNwtMtr_T_f32,
                          &MotPosnCmd_MotRad_T_f32);
     }
     break;
     case(4U):
     {
         NegMotTqStCtrl4(MaxHwPosn_HwDeg_T_f32,
                         MinHwPosn_HwDeg_T_f32,
                         &PinionCentrLrnSt_Cnt_T_u08,
                         &TqCmd_MotNwtMtr_T_f32,
                         &MotPosnCmd_MotRad_T_f32);        
     }
     break;
     case(5U):
     {
         MoveToStCtrl5(HwAg_HwDeg_T_f32,
                       TarHwAg_HwDeg_T_f32,
                       MotVelCrf_MotRadPerSec_T_f32,
                       TarMotVel_MotRadPerSec_T_f32,
                       &PinionCentrLrnSt_Cnt_T_u08,
                       &TqCmd_MotNwtMtr_T_f32,
                       &MotPosnCmd_MotRad_T_f32);
     }
     break;
     case(6U):
     {
         PinionCentrLrnSt_Cnt_T_u08 = ST6_ULS_U08;
         TqCmd_MotNwtMtr_T_f32 = 0.0F;
         MotPosnCmd_MotRad_T_f32 = 0.0F;
     }
     break;
     case(7U):
     {
         PinionCentrLrnSt_Cnt_T_u08 = ST7_ULS_U08;
         TqCmd_MotNwtMtr_T_f32 = 0.0F;
         MotPosnCmd_MotRad_T_f32 = 0.0F;
     }
     break;
     default:
     {
         if(PinionCentrLrnEna_Cnt_T_logl == TRUE)
         {
             PinionCentrLrnSt_Cnt_T_u08 = 1U;
             (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Tmr_Cnt_T_u32);
             *Rte_Pim_StCtrl1TmrARefTi() = Tmr_Cnt_T_u32;
             *Rte_Pim_StCtrl1TmrBRefTi() = Tmr_Cnt_T_u32;
         }
         else
         {
             PinionCentrLrnSt_Cnt_T_u08 = 0U;
         }
         
         TqCmd_MotNwtMtr_T_f32 = 0.0F;
         MotPosnCmd_MotRad_T_f32 = 0.0F;
     }
     break;
 }
 
 PinionCentrLrnCmd_MotNwtMtr_T_f32 = Lim_f32(TqCmd_MotNwtMtr_T_f32, SYSGLBPRM_MOTTQCMDLOLIM_MOTNWTMTR_F32, SYSGLBPRM_MOTTQCMDHILIM_MOTNWTMTR_F32);
 *Rte_Pim_TqCmdEstimdPrev() = PinionCentrLrnCmd_MotNwtMtr_T_f32;
 
 PinionCentrLrnSt_Cnt_T_u08 = Lim_u08(PinionCentrLrnSt_Cnt_T_u08, PINIONCENTRLRNSTLOWRLIM_CNT_U08, PINIONCENTRLRNSTUPPRLIM_CNT_U08);
 *Rte_Pim_StEstimdPrev() = PinionCentrLrnSt_Cnt_T_u08;
 
 *Rte_Pim_dLrnPinionCentrHwPosnCmd() = MotPosnCmd_MotRad_T_f32 * (1.0F / Rte_Prm_SysGlbPrmSysKineRat_Val());
 
 *Rte_Pim_PinionCentrLrnHwCentrPrev() = Lim_f32(*Rte_Pim_PinionCentrLrnHwCentrPrev(), PINIONCENTRLRNHWCENTRLOWRLIM_HWDEG_F32, PINIONCENTRLRNHWCENTRUPPRLIM_HWDEG_F32);
 *Rte_Pim_PinionCentrLrnHwTrvlPrev() = Lim_f32(*Rte_Pim_PinionCentrLrnHwTrvlPrev(), PINIONCENTRLRNHWTRVLLOWRLIM_HWDEG_F32, PINIONCENTRLRNHWTRVLUPPRLIM_HWDEG_F32);
 
 (void)Rte_Write_PinionCentrLrnHwCentr_Val(*Rte_Pim_PinionCentrLrnHwCentrPrev());
 (void)Rte_Write_PinionCentrLrnHwTrvl_Val(*Rte_Pim_PinionCentrLrnHwTrvlPrev());
 
 (void)Rte_Write_PinionCentrLrnSt_Val(PinionCentrLrnSt_Cnt_T_u08);

 (void)Rte_Write_PinionCentrLrnCmd_Val(PinionCentrLrnCmd_MotNwtMtr_T_f32);
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetInpPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetInpPrm>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SetInpPrm_Oper_TarA(float32 data)
 *   void Rte_IrvWrite_SetInpPrm_Oper_TarVel(float32 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetInpPrm_Oper_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, LrnPinionCentr_CODE) SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetInpPrm_Oper
 *********************************************************************************************************************/
   
    VAR(float32, AUTOMATIC) TarA_HwDegPerSecPerSec_T_f32;
    VAR(float32, AUTOMATIC) TarVel_HwDegPerSec_T_f32;
    
    TarA_HwDegPerSecPerSec_T_f32 = TarA_Arg;
    TarVel_HwDegPerSec_T_f32 = TarVel_Arg;
    
    Rte_IrvWrite_SetInpPrm_Oper_TarA(TarA_HwDegPerSecPerSec_T_f32);
    Rte_IrvWrite_SetInpPrm_Oper_TarVel(TarVel_HwDegPerSec_T_f32);
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define LrnPinionCentr_STOP_SEC_CODE
#include "LrnPinionCentr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*******************************************************************************
* Name          :   RunMinMax
* Description   :   Implementation of Running MinMax
* Inputs        :   HwAg_HwDeg_T_f32
*                   PinionCentrLrnEna_Cnt_T_logl
*                   *MaxHwPosn_HwDeg_T_f32
*                   *MinHwPosn_HwDeg_T_f32
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/
static FUNC(void, LRNPINIONCNTR_CODE) RunMinMax(float32 HwAg_HwDeg_T_f32,
                                                boolean PinionCentrLrnEna_Cnt_T_logl,
                                                P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MaxHwPosn_HwDeg_T_f32,
                                                P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MinHwPosn_HwDeg_T_f32)
{
    if(PinionCentrLrnEna_Cnt_T_logl == TRUE)
    {
        *MaxHwPosn_HwDeg_T_f32 = Max_f32(*Rte_Pim_MaxHwPosnPrev(), HwAg_HwDeg_T_f32);
        *MinHwPosn_HwDeg_T_f32 = Min_f32(*Rte_Pim_MinHwPosnPrev(), HwAg_HwDeg_T_f32);
    }
    else
    {
        *MaxHwPosn_HwDeg_T_f32 = Max_f32(*Rte_Pim_MaxHwPosnPrev(), HwAg_HwDeg_T_f32 - *Rte_Pim_MaxHwPosnPrev());
        *MinHwPosn_HwDeg_T_f32 = Min_f32(*Rte_Pim_MinHwPosnPrev(), HwAg_HwDeg_T_f32 - *Rte_Pim_MinHwPosnPrev());
    }
    
    *Rte_Pim_MaxHwPosnPrev() = *MaxHwPosn_HwDeg_T_f32;
    *Rte_Pim_MinHwPosnPrev() = *MinHwPosn_HwDeg_T_f32;
} 
 
 
 /*******************************************************************************
* Name          :   PosAgVelStCtrl1
* Description   :   Implementation of POSANGVEL State Control 1
* Inputs        :   HwAg_HwDeg_T_f32
*                   MotVelCrf_MotRadPerSec_T_f32
*                   TarMotVel_MotRadPerSec_T_f32
*                   *PinionCentrLrnSt_Cnt_T_u08
*                   *TqCmd_MotNwtMtr_T_f32
*                   *MotPosnCmd_MotRad_T_f32
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/
static FUNC(void, LRNPINIONCNTR_CODE) PosAgVelStCtrl1(float32 HwAg_HwDeg_T_f32,
                                                      float32 MotVelCrf_MotRadPerSec_T_f32,
                                                      float32 TarMotVel_MotRadPerSec_T_f32,
                                                      P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                      P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                      P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32)
{
    VAR(float32, AUTOMATIC) IniMotPosn_MotRad_T_f32;
    VAR(float32, AUTOMATIC) LimdMotPosn_MotRad_T_f32;
    VAR(boolean, AUTOMATIC) TmrFlgA_Cnt_T_logl = FALSE;
    VAR(boolean, AUTOMATIC) TmrFlgB_Cnt_T_logl = FALSE;
    VAR(uint32, AUTOMATIC) Tmr_Cnt_T_u32;
    VAR(uint32,  AUTOMATIC) SpanTi_Cnt_T_u32;
    
    IniMotPosn_MotRad_T_f32 = HwAg_HwDeg_T_f32 * Rte_Prm_SysGlbPrmSysKineRat_Val() * ARCHGLBPRM_PIOVER180_ULS_F32;
    LimdMotPosn_MotRad_T_f32 = Lim_f32(TARMOTPOSN_MOTRAD_F32 - IniMotPosn_MotRad_T_f32,
                                       (-TarMotVel_MotRadPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl1PosnErrRateLim(),
                                       ( TarMotVel_MotRadPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl1PosnErrRateLim());
    *Rte_Pim_StCtrl1PosnErrRateLim() = LimdMotPosn_MotRad_T_f32;
    
    *MotPosnCmd_MotRad_T_f32 = FilLpUpdOutp_f32(LimdMotPosn_MotRad_T_f32,Rte_Pim_StCtrl1RateLimdPosnErrLpFil()) + IniMotPosn_MotRad_T_f32;
    
    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    *TqCmd_MotNwtMtr_T_f32 = ((*MotPosnCmd_MotRad_T_f32 - IniMotPosn_MotRad_T_f32) * Rte_Prm_LrnPinionCentrPropCtrlGain_Val()) -
                              (MotVelCrf_MotRadPerSec_T_f32 * Rte_Prm_LrnPinionCentrDampgCtrlGain_Val());
                              
    (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl1TmrARefTi(), &SpanTi_Cnt_T_u32);
    
    if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiOutThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
    {
        TmrFlgA_Cnt_T_logl = TRUE;
    }
    
    if((Abslt_f32_f32(MotVelCrf_MotRadPerSec_T_f32) <= Rte_Prm_LrnPinionCentrMotVelThd_Val()) &&
       (*Rte_Pim_TqCmdEstimdPrev() >= Rte_Prm_LrnPinionCentrMinMotTq_Val()))
    {
        (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl1TmrBRefTi(), &SpanTi_Cnt_T_u32);
        
        if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
        {
            TmrFlgB_Cnt_T_logl = TRUE;
        }
    }
    else
    {
        TmrFlgB_Cnt_T_logl = FALSE;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_StCtrl1TmrBRefTi());
    }
    
    if(TmrFlgB_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST2_ULS_U08;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Tmr_Cnt_T_u32);
        *Rte_Pim_StCtrl2TmrARefTi() = Tmr_Cnt_T_u32;
        *Rte_Pim_StCtrl2TmrBRefTi() = Tmr_Cnt_T_u32;
    }
    else
    {
        *PinionCentrLrnSt_Cnt_T_u08 = 1U;
    }
    
    if(TmrFlgA_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST7_ULS_U08;
    }
}

/*******************************************************************************
* Name          :   PosMotTqStCtrl2
* Description   :   Implementation of POSMTRTRQ State Control 2
* Inputs        :   *PinionCentrLrnSt_Cnt_T_u08
*                   *TqCmd_MotNwtMtr_T_f32
*                   *MotPosnCmd_MotRad_T_f32
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/
static FUNC(void, LRNPINIONCNTR_CODE) PosMotTqStCtrl2(P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32)
{
    VAR(boolean, AUTOMATIC) TmrFlgA_Cnt_T_logl = FALSE;
    VAR(boolean, AUTOMATIC) TmrFlgB_Cnt_T_logl = FALSE;
    VAR(uint32, AUTOMATIC) Tmr_Cnt_T_u32;
    VAR(uint32,  AUTOMATIC) SpanTi_Cnt_T_u32;
    VAR(float32, AUTOMATIC) LimdTqCmd_MotNwtMtr_T_f32;
    
    (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl2TmrARefTi(), &SpanTi_Cnt_T_u32);
    
    if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiOutThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
    {
        TmrFlgA_Cnt_T_logl = TRUE;
    }
    
    LimdTqCmd_MotNwtMtr_T_f32 = Lim_f32(Rte_Prm_LrnPinionCentrHldTq_Val() - Abslt_f32_f32(*Rte_Pim_TqCmdEstimdPrev()),
                                        (-Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl2TqErrRateLim(),
                                        ( Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl2TqErrRateLim());
   
    *Rte_Pim_StCtrl2TqErrRateLim() = LimdTqCmd_MotNwtMtr_T_f32;
    
    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    *TqCmd_MotNwtMtr_T_f32 = FilLpUpdOutp_f32(LimdTqCmd_MotNwtMtr_T_f32, Rte_Pim_StCtrl2RateLimdTqErrLpFil()) + Abslt_f32_f32(*Rte_Pim_TqCmdEstimdPrev());
    
    if(Abslt_f32_f32(Rte_Prm_LrnPinionCentrHldTq_Val() - *TqCmd_MotNwtMtr_T_f32) <= Rte_Prm_LrnPinionCentrHldTqErrThd_Val())
    {
        (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl2TmrBRefTi(), &SpanTi_Cnt_T_u32);
        
        if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
        {
            TmrFlgB_Cnt_T_logl = TRUE;
        }
    }
    else
    {
        TmrFlgB_Cnt_T_logl = FALSE;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_StCtrl2TmrBRefTi());
    }
    
    if(TmrFlgB_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST3_ULS_U08;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Tmr_Cnt_T_u32);
        *Rte_Pim_StCtrl3TmrARefTi() = Tmr_Cnt_T_u32;
        *Rte_Pim_StCtrl3TmrBRefTi() = Tmr_Cnt_T_u32;
    }
    else
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST2_ULS_U08;
    }
    
    if(TmrFlgA_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST7_ULS_U08;
    }
    
    *MotPosnCmd_MotRad_T_f32 = 0.0F;
}

/*******************************************************************************
* Name          :   NegAgVelStCtrl3
* Description   :   Implementation of NEGANGVEL State Control 3
* Inputs        :   HwAg_HwDeg_T_f32
*                   MotVelCrf_MotRadPerSec_T_f32
*                   TarMotVel_MotRadPerSec_T_f32
*                   *PinionCentrLrnSt_Cnt_T_u08
*                   *TqCmd_MotNwtMtr_T_f32
*                   *MotPosnCmd_MotRad_T_f32
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/
static FUNC(void, LRNPINIONCNTR_CODE) NegAgVelStCtrl3(float32 HwAg_HwDeg_T_f32,
                                                       float32 MotVelCrf_MotRadPerSec_T_f32,
                                                       float32 TarMotVel_MotRadPerSec_T_f32,
                                                       P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32)
{
    VAR(float32, AUTOMATIC) IniMotPosn_MotRad_T_f32;
    VAR(float32, AUTOMATIC) LimdMotPosn_MotRad_T_f32;
    VAR(float32, AUTOMATIC) LimdTqCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) RateLimdFildTq_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) TmpTq_MotNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) TmrFlgA_Cnt_T_logl = FALSE;
    VAR(boolean, AUTOMATIC) TmrFlgB_Cnt_T_logl = FALSE;
    VAR(uint32, AUTOMATIC) Tmr_Cnt_T_u32;
    VAR(uint32,  AUTOMATIC) SpanTi_Cnt_T_u32;
    
    (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl3TmrARefTi(), &SpanTi_Cnt_T_u32);
    if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiOutThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
    {
        TmrFlgA_Cnt_T_logl = TRUE;
    }
    
    IniMotPosn_MotRad_T_f32 = HwAg_HwDeg_T_f32 * Rte_Prm_SysGlbPrmSysKineRat_Val() * ARCHGLBPRM_PIOVER180_ULS_F32;
    
    LimdMotPosn_MotRad_T_f32 = Lim_f32(-TARMOTPOSN_MOTRAD_F32 - IniMotPosn_MotRad_T_f32,
                                       (-TarMotVel_MotRadPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl3PosnErrRateLim(),
                                       (TarMotVel_MotRadPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl3PosnErrRateLim());
    *Rte_Pim_StCtrl3PosnErrRateLim() = LimdMotPosn_MotRad_T_f32;
    
    *MotPosnCmd_MotRad_T_f32 = FilLpUpdOutp_f32(LimdMotPosn_MotRad_T_f32, Rte_Pim_StCtrl3RateLimdPosnErrLpFil()) + IniMotPosn_MotRad_T_f32;
    
    LimdTqCmd_MotNwtMtr_T_f32 = Lim_f32(0.0F - *Rte_Pim_TqCmdEstimdPrev(),
                                       (-Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl3TqErrRateLim(),
                                       (Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl3TqErrRateLim());
    *Rte_Pim_StCtrl3TqErrRateLim() = LimdTqCmd_MotNwtMtr_T_f32;
    RateLimdFildTq_MotNwtMtr_T_f32 = FilLpUpdOutp_f32(LimdTqCmd_MotNwtMtr_T_f32, Rte_Pim_StCtrl3RateLimdTqErrLpFil()) + *Rte_Pim_TqCmdEstimdPrev();
    
    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    TmpTq_MotNwtMtr_T_f32 = ((*MotPosnCmd_MotRad_T_f32 - IniMotPosn_MotRad_T_f32) * Rte_Prm_LrnPinionCentrPropCtrlGain_Val());
    
    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    *TqCmd_MotNwtMtr_T_f32 = (TmpTq_MotNwtMtr_T_f32 + RateLimdFildTq_MotNwtMtr_T_f32) -
                             (Rte_Prm_LrnPinionCentrDampgCtrlGain_Val() * MotVelCrf_MotRadPerSec_T_f32);
    
    if((Abslt_f32_f32(MotVelCrf_MotRadPerSec_T_f32) <= Rte_Prm_LrnPinionCentrMotVelThd_Val()) &&
       (-*Rte_Pim_TqCmdEstimdPrev() >= Rte_Prm_LrnPinionCentrMinMotTq_Val()))
    {
        (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl3TmrBRefTi(), &SpanTi_Cnt_T_u32);
        if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
        {
            TmrFlgB_Cnt_T_logl = TRUE;
        }
    }
    else
    {
        TmrFlgB_Cnt_T_logl = FALSE;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_StCtrl3TmrBRefTi());
    }
    
    if(TmrFlgB_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST4_ULS_U08;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Tmr_Cnt_T_u32);
        *Rte_Pim_StCtrl4TmrARefTi() = Tmr_Cnt_T_u32;
        *Rte_Pim_StCtrl4TmrBRefTi() = Tmr_Cnt_T_u32;
        
    }
    else
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST3_ULS_U08;
    }
    
    if(TmrFlgA_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST7_ULS_U08;
    }
    
}

/*******************************************************************************
* Name          :   NegMotTqStCtrl4
* Description   :   Implementation of NEGMTRTRQ State Control 4
* Inputs        :   MaxHwPosn_HwDeg_T_f32
*                   MinHwPosn_HwDeg_T_f32
*                   *PinionCentrLrnSt_Cnt_T_u08
*                   *TqCmd_MotNwtMtr_T_f32
*                   *MotPosnCmd_MotRad_T_f32
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/
static FUNC(void, LRNPINIONCNTR_CODE) NegMotTqStCtrl4(float32 MaxHwPosn_HwDeg_T_f32,
                                                       float32 MinHwPosn_HwDeg_T_f32,
                                                       P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                       P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32)
{
    VAR(float32, AUTOMATIC) LimdTqCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) RateLimdFildTq_MotNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) TmrFlgA_Cnt_T_logl = FALSE;
    VAR(boolean, AUTOMATIC) TmrFlgB_Cnt_T_logl = FALSE;
    VAR(uint32, AUTOMATIC) Tmr_Cnt_T_u32;
    VAR(uint32,  AUTOMATIC) SpanTi_Cnt_T_u32;

    (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl4TmrARefTi(), &SpanTi_Cnt_T_u32);
    if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiOutThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
    {
        TmrFlgA_Cnt_T_logl = TRUE;
    }
    
    LimdTqCmd_MotNwtMtr_T_f32 = Lim_f32(Rte_Prm_LrnPinionCentrHldTq_Val() - Abslt_f32_f32(*Rte_Pim_TqCmdEstimdPrev()),
                                       (-Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl4TqErrRateLim(),
                                       (Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl4TqErrRateLim());
    *Rte_Pim_StCtrl4TqErrRateLim() = LimdTqCmd_MotNwtMtr_T_f32;   

    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    RateLimdFildTq_MotNwtMtr_T_f32 = FilLpUpdOutp_f32(LimdTqCmd_MotNwtMtr_T_f32, Rte_Pim_StCtrl4RateLimdTqErrLpFil()) + Abslt_f32_f32(*Rte_Pim_TqCmdEstimdPrev());
    *TqCmd_MotNwtMtr_T_f32 = -RateLimdFildTq_MotNwtMtr_T_f32;
    
    if(Abslt_f32_f32(Rte_Prm_LrnPinionCentrHldTq_Val() - RateLimdFildTq_MotNwtMtr_T_f32) <= Rte_Prm_LrnPinionCentrHldTqErrThd_Val())
    {
        (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl4TmrBRefTi(), &SpanTi_Cnt_T_u32);
        
        if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
        {
            TmrFlgB_Cnt_T_logl = TRUE;
        }
    }
    else
    {
        TmrFlgB_Cnt_T_logl = FALSE;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_StCtrl4TmrBRefTi());
    }
    
    if(TmrFlgB_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST5_ULS_U08;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Tmr_Cnt_T_u32);
        *Rte_Pim_StCtrl5TmrARefTi() = Tmr_Cnt_T_u32;
        *Rte_Pim_StCtrl5TmrBRefTi() = Tmr_Cnt_T_u32;
    }
    else
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST4_ULS_U08;
    }
    
    if(TmrFlgA_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST7_ULS_U08;
    }
    
    *MotPosnCmd_MotRad_T_f32 = 0.0F;
    
    if(TmrFlgB_Cnt_T_logl == TRUE)
    {
        *Rte_Pim_PinionCentrLrnHwCentrPrev() = (MaxHwPosn_HwDeg_T_f32 + MinHwPosn_HwDeg_T_f32) * AVRG_ULS_F32;
    }
    
    if(TmrFlgB_Cnt_T_logl == TRUE)
    {
        *Rte_Pim_PinionCentrLrnHwTrvlPrev() = Abslt_f32_f32(MaxHwPosn_HwDeg_T_f32 - MinHwPosn_HwDeg_T_f32);
    }
}

/*******************************************************************************
* Name          :   MoveToStCtrl5
* Description   :   Implementation of MOVETO State Control 5
* Inputs        :   HwAg_HwDeg_T_f32
*                   TarHwAg_HwDeg_T_f32
*                   MotVelCrf_MotRadPerSec_T_f32
*                   TarMotVel_MotRadPerSec_T_f32
*                   *PinionCentrLrnSt_Cnt_T_u08
*                   *TqCmd_MotNwtMtr_T_f32
*                   *MotPosnCmd_MotRad_T_f32
* Outputs       :   None
* Usage Notes   :   None
*****************************************************************************/
static FUNC(void, LRNPINIONCNTR_CODE) MoveToStCtrl5(float32 HwAg_HwDeg_T_f32,
                                                    float32 TarHwAg_HwDeg_T_f32,
                                                    float32 MotVelCrf_MotRadPerSec_T_f32,
                                                    float32 TarMotVel_MotRadPerSec_T_f32,
                                                    P2VAR(uint8, AUTOMATIC, LrnPinionCentr_VAR) PinionCentrLrnSt_Cnt_T_u08,
                                                    P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) TqCmd_MotNwtMtr_T_f32,
                                                    P2VAR(float32, AUTOMATIC, LrnPinionCentr_VAR) MotPosnCmd_MotRad_T_f32)
{
    VAR(float32, AUTOMATIC) LimdTqCmd_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) RateLimdFildTq_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) TmpTq_MotNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) TarHwVel_HwDegPerSec_T_f32;
    VAR(float32, AUTOMATIC) LimdPosn_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) RateLimdFildPosn_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) Err_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) AWLim_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) IntglEnaOutp_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) IntglGain_MotNwtMtr_T_f32;
    VAR(boolean, AUTOMATIC) TmrFlgA_Cnt_T_logl = FALSE;
    VAR(boolean, AUTOMATIC) TmrFlgB_Cnt_T_logl = FALSE;
    VAR(uint32,  AUTOMATIC) SpanTi_Cnt_T_u32;
    
    
    (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl5TmrARefTi(), &SpanTi_Cnt_T_u32);
    
    if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiOutThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
    {
        TmrFlgA_Cnt_T_logl = TRUE;
    }
    
    TarHwVel_HwDegPerSec_T_f32 = (TarMotVel_MotRadPerSec_T_f32 / Rte_Prm_SysGlbPrmSysKineRat_Val()) * ARCHGLBPRM_180OVERPI_ULS_F32;
    
    LimdPosn_HwDeg_T_f32 = Lim_f32(TarHwAg_HwDeg_T_f32 - HwAg_HwDeg_T_f32, 
                                   (-TarHwVel_HwDegPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl5PosnErrRateLim(),
                                   (TarHwVel_HwDegPerSec_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl5PosnErrRateLim());
    *Rte_Pim_StCtrl5PosnErrRateLim() = LimdPosn_HwDeg_T_f32;
    RateLimdFildPosn_HwDeg_T_f32 = FilLpUpdOutp_f32(LimdPosn_HwDeg_T_f32, Rte_Pim_StCtrl5RateLimdPosnErrLpFil()) + HwAg_HwDeg_T_f32;
    
    LimdTqCmd_MotNwtMtr_T_f32 = Lim_f32(0.0F - *Rte_Pim_TqCmdEstimdPrev(),
                                       (-Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl5TqErrRateLim(),
                                       (Rte_Prm_LrnPinionCentrHldTqRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_StCtrl5TqErrRateLim());
    *Rte_Pim_StCtrl5TqErrRateLim() = LimdTqCmd_MotNwtMtr_T_f32;
    RateLimdFildTq_MotNwtMtr_T_f32 = FilLpUpdOutp_f32(LimdTqCmd_MotNwtMtr_T_f32, Rte_Pim_StCtrl5RateLimdTqErrLpFil()) + *Rte_Pim_TqCmdEstimdPrev();
    
    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    *MotPosnCmd_MotRad_T_f32 = RateLimdFildPosn_HwDeg_T_f32 * Rte_Prm_SysGlbPrmSysKineRat_Val() * ARCHGLBPRM_PIOVER180_ULS_F32;
    
    Err_HwDeg_T_f32 = RateLimdFildPosn_HwDeg_T_f32 - HwAg_HwDeg_T_f32;
    
    /* I-Term */
    
    if(Rte_Prm_LrnPinionCentrIntglCtrlGain_Val() < ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
    {
        AWLim_HwDeg_T_f32 = 0.0F;
    }
    else
    {
        /* Polyspace flags possible division by zero on the following line. Analysis determined this is impossible (file version 2). */
        AWLim_HwDeg_T_f32 = (Rte_Prm_LrnPinionCentrMaxTqCmd_Val() / ARCHGLBPRM_2MILLISEC_SEC_F32) / Rte_Prm_LrnPinionCentrIntglCtrlGain_Val();
    }
    
    IntglEnaOutp_HwDeg_T_f32 = Lim_f32(Err_HwDeg_T_f32 + *Rte_Pim_StCtrl5IntglEnaOutpPrev(), -AWLim_HwDeg_T_f32, AWLim_HwDeg_T_f32);
    
    *Rte_Pim_StCtrl5IntglEnaOutpPrev() = IntglEnaOutp_HwDeg_T_f32;
    
    IntglGain_MotNwtMtr_T_f32 = ARCHGLBPRM_2MILLISEC_SEC_F32 * Rte_Prm_LrnPinionCentrIntglCtrlGain_Val() * IntglEnaOutp_HwDeg_T_f32;
    
    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    TmpTq_MotNwtMtr_T_f32 = Err_HwDeg_T_f32 * Rte_Prm_LrnPinionCentrPropCtrlGain_Val() * Rte_Prm_SysGlbPrmSysKineRat_Val() * ARCHGLBPRM_PIOVER180_ULS_F32;
    
    /* Polyspace flags possible overflow on the following line. Analysis determined this is impossible (file version 2). */
    *TqCmd_MotNwtMtr_T_f32 = (TmpTq_MotNwtMtr_T_f32 + IntglGain_MotNwtMtr_T_f32 + RateLimdFildTq_MotNwtMtr_T_f32) -
                             (MotVelCrf_MotRadPerSec_T_f32 * Rte_Prm_LrnPinionCentrDampgCtrlGain_Val());
    
    if(Abslt_f32_f32(TarHwAg_HwDeg_T_f32 - HwAg_HwDeg_T_f32) <= Rte_Prm_LrnPinionCentrHwPosnErrThd_Val())
    {
        (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_StCtrl5TmrBRefTi(), &SpanTi_Cnt_T_u32);
        
        if(SpanTi_Cnt_T_u32 > ((uint32)Rte_Prm_LrnPinionCentrTiThd_Val() * (uint32)MILLICNV100MICRO_ULS_U16))
        {
            TmrFlgB_Cnt_T_logl = TRUE;
        }
    }
    else
    {
        TmrFlgB_Cnt_T_logl = FALSE;
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_StCtrl5TmrBRefTi());
    }
    
    if(TmrFlgB_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST6_ULS_U08;
    }
    else
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST5_ULS_U08;
    }
    
    if(TmrFlgA_Cnt_T_logl == TRUE)
    {
        *PinionCentrLrnSt_Cnt_T_u08 = ST7_ULS_U08;
    }
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
