/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  PullCmpActv.c
 *        Config:  C:/Component/SF013A_PullCmpActv_Impl/tools/Component.dpa
 *     SW-C Type:  PullCmpActv
 *  Generated at:  Wed Jan 24 10:44:46 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <PullCmpActv>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
* Copyright 2015, 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : PullCmpActv.c
* Module Description: Implementation of Active Pull Compensation SF013A. 
* Project           : CBD 
* Author            : Tata Elxsi
***********************************************************************************************************************
* Version Control:
* %version          : 7 %
* %derived_by       : nz4qtt %
*--------------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                             SCR #
* -------   -------  --------  -----------------------------------------------------------------------------     ----------
* 10/01/15  1        AK              InitialVersion                                                        		  EA4#1017  
* 02/17/16  2        SB              Updated to design version 1.4.0 - New input VehLatA                     	  EA4#3447  
* 03/17/16  3        SB              Updated to fix anomaly EA4#2181 - only change in rte generated code 		  EA4#4194
*										because of change in port access for Per2 	                              
* 06/21/16	4		 SN	             Updated to design version 1.6.0					                          EA4#6250
* 01/17/17	5		 ML				 Updated to design version 2.0.0											  EA4#9208   		  		
* 05/05/17	6		 KK				 Updated to design version 2.1.0 (Added abs function as required)			  EA4#10240
* 12/22/17	7		 KK				 Updated to design version 2.2.0 											  
* 									 Removed intermediate variable 'ShoTermRst' from block 'ShoTermCmpFil'.       
* 									 Updated attributes for PIM 'CmpLrnTiLongTerm'                                
*									 Added a new PIM 'PrevLrnTiLongTerm'.                                         
* 									 Updated logic in 'PullCmpActvPer2/LongTermErrIntgtr /If Action Subsystem1.   
* 									 Non-zero initialization of PIMs has been done in Init block                  
* 									 Added a Fault Injection point to output 'PullCmpCmd'                         
* 									 Added constants 'CMPLRNTIINIVAL_SEC_F32', 'CMPLRNTILONGTERMINIVAL_ULS_F32',   
*									 'PREVLRNTILONGTERMINIVAL_MINS_F32' and 'FLTINJ_PULLCMPACTV_PULLCMPCMD' 	  EA4#13663
*--------------------------------------------------------------------------------------------------------------------------
**********************************************************************************************************************/

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
 * u2p14
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u9p7
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_PullCmpActv.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrFil.h"
#include "NxtrFixdPt.h"
#include "ArchGlbPrm.h"
#include "NxtrIntrpn.h"
#include "NxtrMath.h"
#include "FltInj.h"

/* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.1]: Calibration port pointers to array base types are cast back to their 
array type for code readability and to allow use of "sizeof". */ 

/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value */ 

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include 
statements */


#define INTGTRSCARSHOTERM_ULS_F32   	 (1.35F)
#define LONGTERMINTGTRSCAR_ULS_F32  	 (1.35F)
#define MICROSECTOSEC_ULS_F32       	 (0.0001F)
#define MINSTOSEC_SECPERMINS_F32    	 (60.0F)
#define PULLCMPCMDLOLIM_MOTNWTMTR_F32    (-2.5F)
#define PULLCMPCMDHILIM_MOTNWTMTR_F32    (2.5F)
#define CMPLRNTIINIVAL_SEC_F32    		 (5.0F)
#define CMPLRNTILONGTERMINIVAL_ULS_F32   (0.0045F)
#define PREVLRNTILONGTERMINIVAL_MIN_F32  (5.0F)


#define PrmPullCmpActvVehSpdScaTblX_u9p7     (*(const Ary1D_u9p7_4 *)    Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D())
#define PrmPullCmpActvVehSpdScaTblY_u2p14    (*(const Ary1D_u2p14_4 *)   Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D())

static FUNC(boolean, PullCmpActv_CODE)ActvCmpEna(boolean PullCmpActvShoTermRst_Cnt_T_logl,
                                                 float32 AbslHwTqFild_HwNwtMtr_T_f32,
                                                 float32 AbslHwAg_HwDeg_T_f32,
                                                 float32 AbslVehYawRateFild_VehDegPerSec_T_f32, 
                                                 float32 AbslVehLatA_MtrPerSecSqd_T_f32, 
                                                 float32 PinionAgConf_Uls_T_f32,
                                                 float32 VehSpd_Kph_T_f32,
                                                 boolean VehSpdVld_Cnt_T_logl,
                                                 float32 AbslHwVel_HwRadPerSec_T_f32,
                                                 boolean PullCmpSts_Cnt_T_logl,
												 boolean VehYawRateVld_Cnt_T_logl);

static FUNC(float32, PullCmpActv_CODE)CalcIntgtrGain(float32 HwTq_HwNwtMtr_T_f32,
                                                    float32 PullCmpShoTermPrev_HwNwtMtr_T_f32);

static FUNC(float32, PullCmpActv_CODE)ErrIntgtrActvLim(boolean PullCmpActvShoTermRst_Cnt_T_logl,
                                                       float32 IntgtrGainShoTerm_Uls_T_f32,
                                                       float32 PullErrShoTerm_HwNwtMtr_T_f32,
                                                       float32 PullCmpShoTermPrev_HwNwtMtr_T_f32,
                                                       float32 RampDwnStepSize_HwNwtMtr_T_f32,
                                                       boolean ShoTermRst_Cnt_T_logl);
                                                    
                                                    
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
 * Boolean: Boolean
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * u2p14: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 *
 * Array Types:
 * ============
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u9p7_4: Array with 4 element(s) of type u9p7
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
 *   float32 *Rte_Pim_CmpLrnTiDecShoTerm(void)
 *   float32 *Rte_Pim_CmpLrnTiIncShoTerm(void)
 *   float32 *Rte_Pim_CmpLrnTiLongTerm(void)
 *   float32 *Rte_Pim_IntgtrGainDecShoTerm(void)
 *   float32 *Rte_Pim_IntgtrGainIncShoTerm(void)
 *   float32 *Rte_Pim_PrevLrnTiLongTerm(void)
 *   float32 *Rte_Pim_PullCmpCmdRateLimPrev(void)
 *   float32 *Rte_Pim_PullCmpCmdTot(void)
 *   float32 *Rte_Pim_PullCmpLongTerm(void)
 *   float32 *Rte_Pim_PullCmpShoTerm(void)
 *   float32 *Rte_Pim_VehSpdPrev(void)
 *   float32 *Rte_Pim_VehSpdRate(void)
 *   float32 *Rte_Pim_dPullCmpActvIntgtrGainShoTerm(void)
 *   float32 *Rte_Pim_dPullCmpActvPullErrLongTerm(void)
 *   float32 *Rte_Pim_dPullCmpActvPullErrShoTerm(void)
 *   uint32 *Rte_Pim_RefTiEnaLrng(void)
 *   uint32 *Rte_Pim_RefTiOpstSign(void)
 *   boolean *Rte_Pim_LrngEnaPrev(void)
 *   boolean *Rte_Pim_LrngEnad(void)
 *   boolean *Rte_Pim_OpstSignPrev(void)
 *   boolean *Rte_Pim_PullCmpActvDi(void)
 *   boolean *Rte_Pim_PullCmpLongTermRst(void)
 *   boolean *Rte_Pim_PullCmpShoTermRst(void)
 *   boolean *Rte_Pim_dPullCmpActvShoTermRst(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilLongTerm(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilLrngEna(void)
 *   FilLpRec1 *Rte_Pim_HwTqLpFilShoTerm(void)
 *   FilLpRec1 *Rte_Pim_VehYawRateLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   float32 Rte_CData_PullCmpLongTermDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(void)
 *   float32 Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvLongTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaTiThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val(void)
 *   float32 Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvOutpMaxRate_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullCmpShoTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullCmpTotLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrLimLongTerm_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrMgnThd_Val(void)
 *   float32 Rte_Prm_PullCmpActvPullErrShoTermLim_Val(void)
 *   float32 Rte_Prm_PullCmpActvShoTermRampTi_Val(void)
 *   float32 Rte_Prm_PullCmpActvYawRateFilFrq_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *   boolean Rte_Prm_PullCmpActvEna_Logl(void)
 *   u9p7 *Rte_Prm_PullCmpActvVehSpdScaTblX_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_4
 *   u2p14 *Rte_Prm_PullCmpActvVehSpdScaTblY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *
 *********************************************************************************************************************/


#define PullCmpActv_START_SEC_CODE
#include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetPullCmpPrm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetPullCmpPrm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetPullCmpPrm_Oper(float32 *PullCmpCmdTot_Arg, float32 *PullCmpShoTerm_Arg, float32 *PullCmpLongTerm_Arg, boolean *LrngEnad_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetPullCmpPrm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) GetPullCmpPrm_Oper(P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpCmdTot_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpShoTerm_Arg, P2VAR(float32, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) PullCmpLongTerm_Arg, P2VAR(boolean, AUTOMATIC, RTE_PULLCMPACTV_APPL_VAR) LrngEnad_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetPullCmpPrm_Oper
 *********************************************************************************************************************/
    *PullCmpLongTerm_Arg = *Rte_Pim_PullCmpLongTerm();
    *PullCmpShoTerm_Arg  = *Rte_Pim_PullCmpShoTerm();    
    *PullCmpCmdTot_Arg   = *Rte_Pim_PullCmpCmdTot();
    *LrngEnad_Arg        = *Rte_Pim_LrngEnad();
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize(float32 data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) PullCmpActvInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvInit1
 *********************************************************************************************************************/
    
    FilLpInit(0.0F,
              Rte_Prm_PullCmpActvYawRateFilFrq_Val(),
              ARCHGLBPRM_2MILLISEC_SEC_F32,
              Rte_Pim_VehYawRateLpFil());
                
    FilLpInit(0.0F,
              Rte_Prm_PullCmpActvHwTqFilFrqLrngEna_Val(),
              ARCHGLBPRM_2MILLISEC_SEC_F32,
              Rte_Pim_HwTqLpFilLrngEna());
                
    FilLpInit(0.0F,
              Rte_Prm_PullCmpActvHwTqFilFrqShoTerm_Val(),
              ARCHGLBPRM_2MILLISEC_SEC_F32,
              Rte_Pim_HwTqLpFilShoTerm());
                
    FilLpInit(0.0F,
              Rte_Prm_PullCmpActvHwTqFilFrqLongTerm_Val(),
              ARCHGLBPRM_100MILLISEC_SEC_F32,
              Rte_Pim_HwTqLpFilLongTerm());
                
    /*** Write Output to Inter Runnable Variable ***/
    Rte_IrvWrite_PullCmpActvInit1_RampDwnStepSize((ARCHGLBPRM_2MILLISEC_SEC_F32 * 
                                                   Rte_Prm_PullCmpActvPullCmpShoTermLim_Val()) /
                                                   Rte_Prm_PullCmpActvShoTermRampTi_Val());

    *Rte_Pim_CmpLrnTiIncShoTerm() 	= CMPLRNTIINIVAL_SEC_F32;
	*Rte_Pim_CmpLrnTiDecShoTerm() 	= CMPLRNTIINIVAL_SEC_F32;
	*Rte_Pim_CmpLrnTiLongTerm()   	= CMPLRNTILONGTERMINIVAL_ULS_F32;
	*Rte_Pim_PrevLrnTiLongTerm()  	= PREVLRNTILONGTERMINIVAL_MIN_F32;
	
	/*** Set the RAMBlockStatus to TRUE ***/
    (void)Rte_Call_PullCmpLongTerm_SetRamBlockStatus(TRUE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvPer1
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
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PullCmpActvDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpCustLrngDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PullCmpLrngDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehLatA_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_VehYawRate_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehYawRateVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PullCmpCmd_Val(float32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   float32 Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInj_f32_Oper(float32 *SigPah_Arg, uint16 LocnKey_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) PullCmpActvPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer1
 *********************************************************************************************************************/

    VAR(float32, AUTOMATIC) HwAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwTqFild_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) VehYawRateFild_VehDegPerSec_T_f32;
    VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) VehYawRate_VehDegPerSec_T_f32;
    VAR(float32, AUTOMATIC) PinionAgConf_Uls_T_f32; 
    VAR(float32, AUTOMATIC) VehLatA_MtrPerSecSqd_T_f32;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32;
    VAR(float32, AUTOMATIC) IntgtrGainShoTerm_Uls_T_f32;
    VAR(float32, AUTOMATIC) PullCmpShoTerm_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullCmpCmdPreLim_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullCmpCmdLim_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullErrShoTerm_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) HwTqShoTermFild_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullCmpShoTermPrev_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) RampDwnStepSize_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) AbslHwTqFild_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) AbslHwAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) AbslVehYawRateFild_VehDegPerSec_T_f32; 
    VAR(float32, AUTOMATIC) AbslVehLatA_MtrPerSecSqd_T_f32;
    VAR(float32, AUTOMATIC) PullCmpCmd_HwNwtMtr_T_f32;
    
    VAR(boolean, AUTOMATIC) PullCmpActvShoTermRst_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) PullCmpCmdDi_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) PullCmpLrngDi_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) LrngEnad_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) ShoTermRst_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) PullCmpSts_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) VehYawRateVld_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) PullCmpCustLrngDi_Cnt_T_logl;
    
    VAR(uint16, AUTOMATIC)  VehSpd_Kph_T_u9p7;
    VAR(uint16, AUTOMATIC)  VehSpdSca_Uls_T_u2p14;
	VAR(boolean, AUTOMATIC) PullCmpActvDi_Cnt_T_logl;
	
	if(TRUE == Rte_Prm_PullCmpActvEna_Logl())
	{

		/*** Read inputs from RTE ***/
		(void)Rte_Read_HwAg_Val(&HwAg_HwDeg_T_f32);
		(void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
		(void)Rte_Read_VehYawRate_Val(&VehYawRate_VehDegPerSec_T_f32);
		(void)Rte_Read_PinionAgConf_Val(&PinionAgConf_Uls_T_f32);
		(void)Rte_Read_VehLatA_Val(&VehLatA_MtrPerSecSqd_T_f32);
		(void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
		(void)Rte_Read_VehSpdVld_Logl(&VehSpdVld_Cnt_T_logl);
		(void)Rte_Read_HwVel_Val(&HwVel_HwRadPerSec_T_f32);
		(void)Rte_Read_PullCmpCmdDi_Logl(&PullCmpCmdDi_Cnt_T_logl);
		(void)Rte_Read_PullCmpLrngDi_Logl(&PullCmpLrngDi_Cnt_T_logl);
		(void)Rte_Read_PullCmpActvDi_Logl(&PullCmpActvDi_Cnt_T_logl);
		(void)Rte_Read_VehYawRateVld_Logl(&VehYawRateVld_Cnt_T_logl);
		(void)Rte_Read_PullCmpCustLrngDi_Logl(&PullCmpCustLrngDi_Cnt_T_logl);
		
		/*** Fetching the value from IRV ***/
		RampDwnStepSize_HwNwtMtr_T_f32 = Rte_IrvRead_PullCmpActvPer1_RampDwnStepSize();
		
		HwTqFild_HwNwtMtr_T_f32 = FilLpUpdOutp_f32(HwTq_HwNwtMtr_T_f32, Rte_Pim_HwTqLpFilLrngEna());
		
		VehYawRateFild_VehDegPerSec_T_f32 = FilLpUpdOutp_f32(VehYawRate_VehDegPerSec_T_f32, Rte_Pim_VehYawRateLpFil());
		
		ShoTermRst_Cnt_T_logl = *Rte_Pim_PullCmpShoTermRst();
		
		if(TRUE == *Rte_Pim_PullCmpShoTermRst())
		{
			*Rte_Pim_PullCmpShoTermRst() = FALSE;
		}
		
		if((TRUE == PullCmpLrngDi_Cnt_T_logl) || (TRUE == PullCmpCmdDi_Cnt_T_logl) || (TRUE == PullCmpActvDi_Cnt_T_logl) || (TRUE == PullCmpCustLrngDi_Cnt_T_logl))
		{
			PullCmpSts_Cnt_T_logl = TRUE;
		}
		else
		{
			PullCmpSts_Cnt_T_logl = FALSE;
		}
		
		/*** Start of ActvCmpEna ***/
		AbslHwTqFild_HwNwtMtr_T_f32           = Abslt_f32_f32(HwTqFild_HwNwtMtr_T_f32);
		AbslVehYawRateFild_VehDegPerSec_T_f32 = Abslt_f32_f32(VehYawRateFild_VehDegPerSec_T_f32);
		AbslHwAg_HwDeg_T_f32                  = Abslt_f32_f32(HwAg_HwDeg_T_f32);
		AbslVehLatA_MtrPerSecSqd_T_f32        = Abslt_f32_f32(VehLatA_MtrPerSecSqd_T_f32); 
		
		
		if( (AbslHwAg_HwDeg_T_f32 >= Rte_Prm_PullCmpActvCmpShoTermRstHwAgThd_Val()) ||
			(AbslHwTqFild_HwNwtMtr_T_f32 >= Rte_Prm_PullCmpActvCmpShoTermRstHwTqThd_Val()) ||
			((AbslVehYawRateFild_VehDegPerSec_T_f32 >= Rte_Prm_PullCmpActvCmpShoTermRstYawRateThd_Val()) && (VehYawRateVld_Cnt_T_logl == TRUE)) ||
			(AbslVehLatA_MtrPerSecSqd_T_f32 >= Rte_Prm_PullCmpActvCmpShoTermRstLatAThd_Val()))
		{
			PullCmpActvShoTermRst_Cnt_T_logl = TRUE;
		}
		else
		{
			PullCmpActvShoTermRst_Cnt_T_logl = FALSE;
		}
		
		*Rte_Pim_dPullCmpActvShoTermRst() = PullCmpActvShoTermRst_Cnt_T_logl;
		
		LrngEnad_Cnt_T_logl = ActvCmpEna(PullCmpActvShoTermRst_Cnt_T_logl,
										 AbslHwTqFild_HwNwtMtr_T_f32,
										 AbslHwAg_HwDeg_T_f32,
										 AbslVehYawRateFild_VehDegPerSec_T_f32,
										 AbslVehLatA_MtrPerSecSqd_T_f32,
										 PinionAgConf_Uls_T_f32,
										 VehSpd_Kph_T_f32,
										 VehSpdVld_Cnt_T_logl,
										 Abslt_f32_f32(HwVel_HwRadPerSec_T_f32),
										 PullCmpSts_Cnt_T_logl,
										 VehYawRateVld_Cnt_T_logl);
		
		*Rte_Pim_LrngEnad() = LrngEnad_Cnt_T_logl;
		
		/*** End of ActvCmpEna ***/
		
		PullCmpShoTermPrev_HwNwtMtr_T_f32 = *Rte_Pim_PullCmpShoTerm();
		
		/*** Start of ShoTermCmpFil ***/
		HwTqShoTermFild_HwNwtMtr_T_f32 = FilLpUpdOutp_f32(HwTq_HwNwtMtr_T_f32, Rte_Pim_HwTqLpFilShoTerm());
		
		if(((Abslt_f32_f32(HwTqShoTermFild_HwNwtMtr_T_f32)) >= Rte_Prm_PullCmpActvPullErrMgnThd_Val()) &&
		   (TRUE == LrngEnad_Cnt_T_logl) && 
		   (TRUE != ShoTermRst_Cnt_T_logl))
		{
			PullErrShoTerm_HwNwtMtr_T_f32 = HwTqShoTermFild_HwNwtMtr_T_f32;
		}
		else
		{
			PullErrShoTerm_HwNwtMtr_T_f32 = 0.0F;
		}
		
		*Rte_Pim_dPullCmpActvPullErrShoTerm() = PullErrShoTerm_HwNwtMtr_T_f32;
		
		/*** End of ShoTermCmpFil ***/
		
		/*** Start of Calc Integrator Gain ***/
		
		IntgtrGainShoTerm_Uls_T_f32 = CalcIntgtrGain(HwTq_HwNwtMtr_T_f32,
													PullCmpShoTermPrev_HwNwtMtr_T_f32);
		
		*Rte_Pim_dPullCmpActvIntgtrGainShoTerm() = IntgtrGainShoTerm_Uls_T_f32;
		 
		/*** End of Calc Integrator Gain ***/
		
		/*** Start of Error Integrator and Active Limiter ***/
		
		PullCmpShoTerm_HwNwtMtr_T_f32 = ErrIntgtrActvLim(PullCmpActvShoTermRst_Cnt_T_logl,
														 IntgtrGainShoTerm_Uls_T_f32,    
														 PullErrShoTerm_HwNwtMtr_T_f32,
														 PullCmpShoTermPrev_HwNwtMtr_T_f32,
														 RampDwnStepSize_HwNwtMtr_T_f32,
														 ShoTermRst_Cnt_T_logl);
		
		*Rte_Pim_PullCmpShoTerm() = PullCmpShoTerm_HwNwtMtr_T_f32;
		/*** End of Error Integrator and Active Limiter ***/
		
		/*** Start of Calc_CmpTot ***/
		if((TRUE == ShoTermRst_Cnt_T_logl) || (TRUE == PullCmpCmdDi_Cnt_T_logl) || (TRUE == PullCmpActvDi_Cnt_T_logl))
		{
			PullCmpCmdPreLim_HwNwtMtr_T_f32 = 0.0F;
		}
		else
		{
			VehSpd_Kph_T_u9p7     = FloatToFixd_u16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP7_ULS_F32);
			
			VehSpdSca_Uls_T_u2p14 = LnrIntrpn_u16_u16VariXu16VariY(PrmPullCmpActvVehSpdScaTblX_u9p7,
																   PrmPullCmpActvVehSpdScaTblY_u2p14,
																   (uint16)TblSize_m(PrmPullCmpActvVehSpdScaTblX_u9p7),
																   VehSpd_Kph_T_u9p7);
																
			PullCmpCmdPreLim_HwNwtMtr_T_f32 = (PullCmpShoTerm_HwNwtMtr_T_f32 + (*Rte_Pim_PullCmpLongTerm())) * 
											  (FixdToFloat_f32_u16(VehSpdSca_Uls_T_u2p14, NXTRFIXDPT_P14TOFLOAT_ULS_F32));
		}
		
		PullCmpCmdLim_HwNwtMtr_T_f32 = Lim_f32(PullCmpCmdPreLim_HwNwtMtr_T_f32,
											   (((-Rte_Prm_PullCmpActvOutpMaxRate_Val()) * ARCHGLBPRM_2MILLISEC_SEC_F32) + 
												*Rte_Pim_PullCmpCmdRateLimPrev()),
											   ((( Rte_Prm_PullCmpActvOutpMaxRate_Val()) * ARCHGLBPRM_2MILLISEC_SEC_F32) + 
												*Rte_Pim_PullCmpCmdRateLimPrev()));
					
		*Rte_Pim_PullCmpCmdRateLimPrev() = PullCmpCmdLim_HwNwtMtr_T_f32;
		
		PullCmpCmd_HwNwtMtr_T_f32   = (PullCmpCmdLim_HwNwtMtr_T_f32 / Rte_Prm_SysGlbPrmSysTqRat_Val());
		
		*Rte_Pim_PullCmpCmdTot()    = PullCmpCmd_HwNwtMtr_T_f32;
		PullCmpCmd_HwNwtMtr_T_f32   = Lim_f32(PullCmpCmd_HwNwtMtr_T_f32, PULLCMPCMDLOLIM_MOTNWTMTR_F32, PULLCMPCMDHILIM_MOTNWTMTR_F32);
		
		/*** End of Calc_CmpTot ***/
		
		#if (STD_ON == FLTINJENA)    
		(void) Rte_Call_FltInj_f32_Oper(&PullCmpCmd_HwNwtMtr_T_f32, FLTINJ_PULLCMPACTV_PULLCMPCMD);          
		#endif
		
		(void)Rte_Write_PullCmpCmd_Val(PullCmpCmd_HwNwtMtr_T_f32);
    }
	else
	{
		/*Do Nothing*/
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PullCmpActvPer2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) PullCmpActvPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PullCmpActvPer2
 *********************************************************************************************************************/
         
    /*** Input Variables ***/
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
    
    /*** Temporary Variables ***/
    VAR(boolean, AUTOMATIC) PullCmpLngTrmSrvRst_Cnt_T_logl; 
    VAR(float32, AUTOMATIC) HwTqLpFilOutpLongTerm_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) AbslHwTqLpFildLngTrm_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullErrLongTerm_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullCmpLongTermLim_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullCmpLongTermErr_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) LongTermErrTerm_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) PullCmpLongTermPrev_HwNwtMtr_T_f32;
    
    /*** Read inputs from RTE ***/
    (void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
    (void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);

    *Rte_Pim_VehSpdRate() = ((VehSpd_Kph_T_f32 - *Rte_Pim_VehSpdPrev()) / ARCHGLBPRM_100MILLISEC_SEC_F32);  
    *Rte_Pim_VehSpdPrev() = VehSpd_Kph_T_f32;

    PullCmpLngTrmSrvRst_Cnt_T_logl = *Rte_Pim_PullCmpLongTermRst();

    if(TRUE == *Rte_Pim_PullCmpLongTermRst())
    {
        *Rte_Pim_PullCmpLongTermRst() = FALSE;
    }

    /*** Start of LongTerm Compensation Filter Function ***/
    HwTqLpFilOutpLongTerm_HwNwtMtr_T_f32 = FilLpUpdOutp_f32((HwTq_HwNwtMtr_T_f32 + *Rte_Pim_PullCmpShoTerm()),
                                                            Rte_Pim_HwTqLpFilLongTerm());
    
    AbslHwTqLpFildLngTrm_HwNwtMtr_T_f32 = Abslt_f32_f32(HwTqLpFilOutpLongTerm_HwNwtMtr_T_f32);
    
    if((AbslHwTqLpFildLngTrm_HwNwtMtr_T_f32  >= Rte_Prm_PullCmpActvPullErrMgnThd_Val()) && 
       (TRUE == *Rte_Pim_LrngEnad()) &&
       (TRUE != PullCmpLngTrmSrvRst_Cnt_T_logl))
    {
        PullErrLongTerm_HwNwtMtr_T_f32 = HwTqLpFilOutpLongTerm_HwNwtMtr_T_f32;
    }
    else
    {
        PullErrLongTerm_HwNwtMtr_T_f32 = 0.0F;
    }

    *Rte_Pim_dPullCmpActvPullErrLongTerm() = PullErrLongTerm_HwNwtMtr_T_f32;    
    /*** End of LongTerm Compensation Filter Function ***/
    
    PullCmpLongTermPrev_HwNwtMtr_T_f32 = *Rte_Pim_PullCmpLongTerm();

    /*** Start of LongTerm Error Integrator Function ***/
    if(TRUE == PullCmpLngTrmSrvRst_Cnt_T_logl)
    {
        *Rte_Pim_PullCmpLongTerm() = 0.0F;
    }
    else
    {
        
        if(Abslt_f32_f32(Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val() - *Rte_Pim_PrevLrnTiLongTerm()) >= ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
        {
              /*** Calculate new long term ***/ 
              LongTermErrTerm_HwNwtMtr_T_f32 = (((ARCHGLBPRM_100MILLISEC_SEC_F32 * LONGTERMINTGTRSCAR_ULS_F32)/
                                               Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val())/
                                               MINSTOSEC_SECPERMINS_F32);
			  *Rte_Pim_CmpLrnTiLongTerm() = LongTermErrTerm_HwNwtMtr_T_f32;
			  
			  *Rte_Pim_PrevLrnTiLongTerm() = Rte_Prm_PullCmpActvCmpLrnTiLongTerm_Val();
        }
		else
		{
			LongTermErrTerm_HwNwtMtr_T_f32 = *Rte_Pim_CmpLrnTiLongTerm();
		}
        
        PullCmpLongTermLim_HwNwtMtr_T_f32 =  Lim_f32(PullErrLongTerm_HwNwtMtr_T_f32,
                                                     (-Rte_Prm_PullCmpActvPullErrLimLongTerm_Val()), 
                                                     (Rte_Prm_PullCmpActvPullErrLimLongTerm_Val())); 
                                                      
        PullCmpLongTermErr_HwNwtMtr_T_f32 = (PullCmpLongTermLim_HwNwtMtr_T_f32 * (LongTermErrTerm_HwNwtMtr_T_f32)) + 
                                             PullCmpLongTermPrev_HwNwtMtr_T_f32;
        
        *Rte_Pim_PullCmpLongTerm() = Lim_f32(PullCmpLongTermErr_HwNwtMtr_T_f32,
                                             Max_f32((-Rte_Prm_PullCmpActvPullCmpTotLim_Val()),
                                                     (-Rte_Prm_PullCmpActvLongTermLim_Val())),
                                             Min_f32(Rte_Prm_PullCmpActvPullCmpTotLim_Val(),
                                                     Rte_Prm_PullCmpActvLongTermLim_Val()));
                                                     
    /*** End of LongTerm Error Integrator Function ***/                                              
    }
    
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RstPullCmp_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <RstPullCmp>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RstPullCmp_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RstPullCmp_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) RstPullCmp_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RstPullCmp_Oper
 *********************************************************************************************************************/
    *Rte_Pim_PullCmpShoTermRst()  = TRUE;
    *Rte_Pim_PullCmpLongTermRst() = TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetPullCmpLongTerm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetPullCmpLongTerm>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_PullCmpLongTerm_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpLongTerm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) SetPullCmpLongTerm_Oper(float32 PullCmpLongTerm_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpLongTerm_Oper
 *********************************************************************************************************************/
    *Rte_Pim_PullCmpLongTerm() = PullCmpLongTerm_Arg;
    
    /*** Set the RAMBlockStatus to TRUE ***/
    (void)Rte_Call_PullCmpLongTerm_SetRamBlockStatus(TRUE);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetPullCmpShoTerm_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetPullCmpShoTerm>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpShoTerm_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, PullCmpActv_CODE) SetPullCmpShoTerm_Oper(float32 PullCmpShoTerm_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetPullCmpShoTerm_Oper
 *********************************************************************************************************************/
    *Rte_Pim_PullCmpShoTerm() = PullCmpShoTerm_Arg;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define PullCmpActv_STOP_SEC_CODE
#include "PullCmpActv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /*****************************************************************************************************************
* Name        :   ActvCmpEna
* Description :   Sub function to calculate LrngEnad_Cnt_T_logl, reducing the path count.
* Inputs      :   PullCmpActvShoTermRst_Cnt_T_logl, AbslHwTqFild_HwNwtMtr_T_f32, AbslHwAg_HwDeg_T_f32, 
*                 AbslVehYawRateFild_VehDegPerSec_T_f32, AbslVehLatA_MtrPerSecSqd_T_f32, PinionAgConf_Uls_T_f32, *VehSpd_Kph_T_f32, VehSpdVld_Cnt_T_logl, 
*                 AbslHwVel_HwRadPerSec_T_f32, PullCmpSts_Cnt_T_logl, VehYawRateVld_Cnt_T_logl
* Returns     :   LrngEnad_Cnt_T_logl 
* Usage Notes :   None
****************************************************************************************************************/
static FUNC(boolean, PullCmpActv_CODE)ActvCmpEna(boolean PullCmpActvShoTermRst_Cnt_T_logl,
                                                 float32 AbslHwTqFild_HwNwtMtr_T_f32,
                                                 float32 AbslHwAg_HwDeg_T_f32,
                                                 float32 AbslVehYawRateFild_VehDegPerSec_T_f32, 
                                                 float32 AbslVehLatA_MtrPerSecSqd_T_f32, 
                                                 float32 PinionAgConf_Uls_T_f32,
                                                 float32 VehSpd_Kph_T_f32,
                                                 boolean VehSpdVld_Cnt_T_logl,
                                                 float32 AbslHwVel_HwRadPerSec_T_f32,
                                                 boolean PullCmpSts_Cnt_T_logl,
												 boolean VehYawRateVld_Cnt_T_logl)
{

    VAR(float32, AUTOMATIC) ElapsedTime_Sec_T_f32;
    VAR(float32, AUTOMATIC) AbslVehSpdRate_KphPerSec_T_f32;
    
    VAR(boolean, AUTOMATIC) LrngEnaFlag_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) LrngEnad_Cnt_T_logl;
    
    VAR(uint32, AUTOMATIC)  RefTmr_Sec_T_u32;
    VAR(uint32, AUTOMATIC)  TiSpan_Cnt_T_u32p0;
    
    AbslVehSpdRate_KphPerSec_T_f32 = Abslt_f32_f32(*Rte_Pim_VehSpdRate());
    
    if((TRUE                                  != PullCmpActvShoTermRst_Cnt_T_logl) && 
       (AbslHwTqFild_HwNwtMtr_T_f32           <  Rte_Prm_PullCmpActvLrngEnaHwTqMaxMgn_Val()) &&
       (AbslHwAg_HwDeg_T_f32                  <  Rte_Prm_PullCmpActvLrngEnaHwAgMaxMgn_Val()) &&
       (AbslVehYawRateFild_VehDegPerSec_T_f32 <  Rte_Prm_PullCmpActvLrngEnaYawRateMaxMgn_Val()) &&
	   (TRUE								  == VehYawRateVld_Cnt_T_logl) &&
       (AbslVehLatA_MtrPerSecSqd_T_f32        <  Rte_Prm_PullCmpActvLrngEnaLatAMaxMgn_Val()) &&
       (PinionAgConf_Uls_T_f32                >= Rte_Prm_PullCmpActvLrngEnaAgConfMinMgn_Val()) &&
       (VehSpd_Kph_T_f32                      >= Rte_Prm_PullCmpActvLrngEnaVehSpdMinMgn_Val()) &&
       (VehSpd_Kph_T_f32                      <  Rte_Prm_PullCmpActvLrngEnaVehSpdMaxMgn_Val()) &&
       (TRUE                                  == VehSpdVld_Cnt_T_logl) &&
       (AbslHwVel_HwRadPerSec_T_f32           <  Rte_Prm_PullCmpActvLrngEnaHwVelMaxMgn_Val()) &&
       (AbslVehSpdRate_KphPerSec_T_f32        <  Rte_Prm_PullCmpActvLrngEnaVehSpdRateMaxMgn_Val()) &&
       (TRUE                                  != PullCmpSts_Cnt_T_logl))
    {
        LrngEnaFlag_Cnt_T_logl = TRUE;
    }
    else
    {
        LrngEnaFlag_Cnt_T_logl = FALSE;
    }
    
    /*** Start of Elapsed time calculation ***/
    if(TRUE != LrngEnaFlag_Cnt_T_logl)
    {
        ElapsedTime_Sec_T_f32 = 0.0F;
    }
    else if(TRUE != (*Rte_Pim_LrngEnaPrev()))
    {
        ElapsedTime_Sec_T_f32 = 0.0F;
        
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(&RefTmr_Sec_T_u32);
        
        *Rte_Pim_RefTiEnaLrng() = RefTmr_Sec_T_u32;
        
    }
    else
    {
        
        (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_RefTiEnaLrng(), &TiSpan_Cnt_T_u32p0);
        
        ElapsedTime_Sec_T_f32 = (FixdToFloat_f32_u32(TiSpan_Cnt_T_u32p0, NXTRFIXDPT_P0TOFLOAT_ULS_F32)) * 
                                  MICROSECTOSEC_ULS_F32;
    }
    
    *Rte_Pim_LrngEnaPrev() = LrngEnaFlag_Cnt_T_logl;
    
    /*** End of Elapsed time calculation ***/
    
    if(ElapsedTime_Sec_T_f32 >= Rte_Prm_PullCmpActvLrngEnaTiThd_Val())
    {
        LrngEnad_Cnt_T_logl = TRUE;
    }
    else
    {
        LrngEnad_Cnt_T_logl = FALSE;
    }
    
    return (LrngEnad_Cnt_T_logl);
}


/*****************************************************************************************************************
* Name        :   CalcIntgtrGain
* Description :   Sub function to calculate IntgtrGainShoTerm_Uls_T_f32, reducing the path count.
* Inputs      :   HwTq_HwNwtMtr_T_f32, PullCmpShoTermPrev_HwNwtMtr_T_f32
* Returns     :   IntgtrGainShoTerm_Uls_T_f32 
* Usage Notes :   None
****************************************************************************************************************/
static FUNC(float32, PullCmpActv_CODE)CalcIntgtrGain(float32 HwTq_HwNwtMtr_T_f32,
                                                    float32 PullCmpShoTermPrev_HwNwtMtr_T_f32)
{
    
    VAR(float32, AUTOMATIC) ElapsedTime_Sec_T_f32;
    VAR(float32, AUTOMATIC) IntgtrGainShoTerm_Uls_T_f32;
    
    VAR(boolean, AUTOMATIC) OpstSign_Cnt_T_logl;
    
    VAR(uint32, AUTOMATIC)  RefTmr_Sec_T_u32;
    VAR(uint32, AUTOMATIC)  TiSpan_Cnt_T_u32p0;
    
    if(Sign_s08_f32(HwTq_HwNwtMtr_T_f32) != Sign_s08_f32(PullCmpShoTermPrev_HwNwtMtr_T_f32))
    {
        OpstSign_Cnt_T_logl = TRUE;
    }
    else
    {
        OpstSign_Cnt_T_logl = FALSE;
    }
    
    /*** Start of Elapsed time calculation ***/
    if(TRUE != OpstSign_Cnt_T_logl)
    {
        ElapsedTime_Sec_T_f32 = 0.0F;
    }
    else if(TRUE != (*Rte_Pim_OpstSignPrev()))
    {
        ElapsedTime_Sec_T_f32 = 0.0F;
        
        (void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(&RefTmr_Sec_T_u32);
        
        *Rte_Pim_RefTiOpstSign() = RefTmr_Sec_T_u32;
    }
    else
    {
        (void)Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_RefTiOpstSign(), &TiSpan_Cnt_T_u32p0);
        
        ElapsedTime_Sec_T_f32 = (FixdToFloat_f32_u32(TiSpan_Cnt_T_u32p0, NXTRFIXDPT_P0TOFLOAT_ULS_F32)) * 
                                  MICROSECTOSEC_ULS_F32;
    }
    
    *Rte_Pim_OpstSignPrev() = OpstSign_Cnt_T_logl;
    /*** End of Elapsed time calculation ***/
    
    if(ElapsedTime_Sec_T_f32 >= Rte_Prm_PullCmpActvOpstSignTiShoTerm_Val())
    {
        if(Abslt_f32_f32(Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val() - (*Rte_Pim_CmpLrnTiIncShoTerm())) >= 
            ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
        {
            IntgtrGainShoTerm_Uls_T_f32 = ARCHGLBPRM_2MILLISEC_SEC_F32 * (INTGTRSCARSHOTERM_ULS_F32 / 
                                                                          Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val());
            
            *Rte_Pim_CmpLrnTiIncShoTerm()   = Rte_Prm_PullCmpActvCmpLrnTiIncShoTerm_Val();
            *Rte_Pim_IntgtrGainIncShoTerm() = IntgtrGainShoTerm_Uls_T_f32;
        }
        else
        {
            IntgtrGainShoTerm_Uls_T_f32 = *Rte_Pim_IntgtrGainIncShoTerm();
        }
    }
    else
    {
        if(Abslt_f32_f32(Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val() - (*Rte_Pim_CmpLrnTiDecShoTerm())) >= 
            ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
        {
            IntgtrGainShoTerm_Uls_T_f32 = ARCHGLBPRM_2MILLISEC_SEC_F32 * (INTGTRSCARSHOTERM_ULS_F32 /
                                                                          Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val());
            
            *Rte_Pim_CmpLrnTiDecShoTerm()   = Rte_Prm_PullCmpActvCmpLrnTiDecShoTerm_Val();
            *Rte_Pim_IntgtrGainDecShoTerm() = IntgtrGainShoTerm_Uls_T_f32;
        }
        else
        {
            IntgtrGainShoTerm_Uls_T_f32 = *Rte_Pim_IntgtrGainDecShoTerm();
        }
    }
    
    return (IntgtrGainShoTerm_Uls_T_f32);
}


/*****************************************************************************************************************
* Name        :   ErrIntgtrActvLim
* Description :   Sub function to calculate PullCmpShoTerm_HwNwtMtr_T_f32, reducing the path count.
* Inputs      :   PullCmpActvShoTermRst_Cnt_T_logl, IntgtrGainShoTerm_Uls_T_f32, PullErrShoTerm_HwNwtMtr_T_f32,
*                 PullCmpShoTermPrev_HwNwtMtr_T_f32, RampDwnStepSize_HwNwtMtr_T_f32, ShoTermRst_Cnt_T_logl
* Returns     :   PullCmpShoTerm_HwNwtMtr_T_f32 
* Usage Notes :   None
****************************************************************************************************************/
static FUNC(float32, PullCmpActv_CODE)ErrIntgtrActvLim(boolean PullCmpActvShoTermRst_Cnt_T_logl,
                                                       float32 IntgtrGainShoTerm_Uls_T_f32,
                                                       float32 PullErrShoTerm_HwNwtMtr_T_f32,
                                                       float32 PullCmpShoTermPrev_HwNwtMtr_T_f32,
                                                       float32 RampDwnStepSize_HwNwtMtr_T_f32,
                                                       boolean ShoTermRst_Cnt_T_logl)
{
    VAR(float32, AUTOMATIC) PullCmpShoTerm_HwNwtMtr_T_f32;
    VAR(float32, AUTOMATIC) ShoTermCmpPreLim_HwNwtMtr_T_f32;
    
    if(TRUE == ShoTermRst_Cnt_T_logl)
    {
        PullCmpShoTerm_HwNwtMtr_T_f32 = 0.0F;
    }
    else
    {
        if(TRUE == PullCmpActvShoTermRst_Cnt_T_logl )
        {
            ShoTermCmpPreLim_HwNwtMtr_T_f32 = PullCmpShoTermPrev_HwNwtMtr_T_f32 + 
                                              (((-(float32)(Sign_s08_f32(PullCmpShoTermPrev_HwNwtMtr_T_f32)))) * 
                                               (Min_f32(Abslt_f32_f32(PullCmpShoTermPrev_HwNwtMtr_T_f32),
                                                        RampDwnStepSize_HwNwtMtr_T_f32)));
            
        }
        else
        {
            ShoTermCmpPreLim_HwNwtMtr_T_f32 = PullCmpShoTermPrev_HwNwtMtr_T_f32 + 
                                              (IntgtrGainShoTerm_Uls_T_f32 *
                                               Lim_f32(PullErrShoTerm_HwNwtMtr_T_f32, 
                                                       (-Rte_Prm_PullCmpActvPullErrShoTermLim_Val()), 
                                                       ( Rte_Prm_PullCmpActvPullErrShoTermLim_Val())));
        }
        
        PullCmpShoTerm_HwNwtMtr_T_f32 = Lim_f32(ShoTermCmpPreLim_HwNwtMtr_T_f32,
                                                Max_f32((-Rte_Prm_PullCmpActvPullCmpShoTermLim_Val()),
                                                       ((-Rte_Prm_PullCmpActvPullCmpTotLim_Val()) - 
                                                        (*Rte_Pim_PullCmpLongTerm()))),
                                                Min_f32((Rte_Prm_PullCmpActvPullCmpShoTermLim_Val()),
                                                       ((Rte_Prm_PullCmpActvPullCmpTotLim_Val()) - 
                                                        (*Rte_Pim_PullCmpLongTerm()))));
    }
    
    return (PullCmpShoTerm_HwNwtMtr_T_f32);
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
