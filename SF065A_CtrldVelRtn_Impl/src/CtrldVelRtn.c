/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtrldVelRtn.c
 *        Config:  C:/Component/SF065A_CtrldVelRtn_Impl/tools/Component.dpa
 *     SW-C Type:  CtrldVelRtn
 *  Generated at:  Wed Nov  8 14:19:12 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CtrldVelRtn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/**********************************************************************************************************************
 Copyright 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CtrldVelRtn.c
* Module Description: Implementation of Controlled Velocity Return SF109A
* Project           : CBD 
* Author            : Ramachandran(Tata Elxsi)
***********************************************************************************************************************
* Version Control 	:
* %version          : 1 %
* %derived_by       : nz4qtt %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author       Change Description                       	                                    SCR #
* -------   -------  --------  -----------------------------------------------------------------------------  ---------
* 10/16/17  1        RMG(TATA)    Initial Release based on SF002B v 1.2.2.                                    EA4#14086
*----------------------------------------------------------------------------------------------------------------------                                                   		   
***********************************************************************************************************************/

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
 * s10p5
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * u10p6
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u12p4
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u2p14
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u4p12
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u6p10
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u8p8
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

#include "Rte_CtrldVelRtn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    #include "NxtrMath.h"
	#include "NxtrFixdPt.h"
	#include "NxtrIntrpn.h"
	#include "NxtrFil.h"
	#include "ArchGlbPrm.h"
	
	/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
	 
  	#define TQGRDTCALCNWGHTFAC1_ULSPERSEC_F32         	(1.1978F)
	#define TQGRDTCALCNWGHTFAC2_ULSPERSEC_F32         	(3.3286F)
	#define TQGRDTCALCNWGHTFAC3_ULSPERSEC_F32         	(4.3159F)
	#define TQGRDTCALCNWGHTFAC4_ULSPERSEC_F32         	(18.0384F)
	#define ONEHALF_ULS_F32							    (0.5F)
	#define SIGNCORRN_CNT_S08                   	    (-1)
	#define RTNCMDLLIM_MOTNWTMTR_F32            	    (-8.8F)
	#define	RTNCMDULIM_MOTNWTMTR_F32			 	    (8.8F)
	#define UNITADJMTTERM_ULSPERSEC_F32                 (1.0F)
	#define DAMPGTERMZERO_KPH_F32                       (0.0F)
	#define DRVRTQOBSVRAGTHD_HWRAD_F32           	    (252.0F)
	#define DRVRTQOBSVRVELTHD_HWRADPERSEC_F32    	    (420.0F)
	#define DRVRTQOBSVRTQTHD_HWNWTMTR_F32        	    (100.0F)
	#define IDX2_CNT_U08                                ((uint8)2U)
	#define IDX3_CNT_U08                                ((uint8)3U)
	#define IDX4_CNT_U08                                ((uint8)4U)
	#define IDX5_CNT_U08                                ((uint8)5U)
	
	#define PrmCtrldVelRtnDrvrTqMtrxA				(*(const Ary2D_f32_5_5  *)       Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D())
	#define PrmCtrldVelRtnDrvrTqMtrxB				(*(const Ary2D_f32_5_4  *)       Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D())
    #define PrmCtrldVelRtnDrvrTqMtrxC 				(*(const Ary1D_f32_5  *)         Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D())
	#define PrmCtrldVelRtnDrvrTqMtrxD				(*(const Ary1D_f32_4 *)          Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D())
	#define PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7   (*(const Ary1D_u9p7_5  *)        Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D())
	#define PrmCtrldVelRtnTqGrdtScaX_u8p8           (*(const Ary2D_u8p8_5_8  *)      Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D())
	#define PrmCtrldVelRtnTqGrdtScaY_u2p14          (*(const Ary2D_u2p14_5_8 *)      Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D())
	#define PrmCtrldVelRtnHwPosnScaX_u12p4			(*(const Ary1D_u12p4_9  *)       Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D())
	#define PrmCtrldVelRtnHwPosnScaY_u2p14      	(*(const Ary1D_u2p14_9  *)       Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D())
	#define PrmCtrldVelRtnHwTqSca1X_u8p8		    (*(const Ary2D_u8p8_5_10 *)      Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D())
	#define PrmCtrldVelRtnHwTqSca1Y_u2p14           (*(const Ary2D_u2p14_5_10 *)     Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D())
	#define PrmCtrldVelRtnHwTqSca2X_u8p8            (*(const Ary2D_u8p8_5_10  *)     Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D())
	#define PrmCtrldVelRtnHwTqSca2Y_u2p14           (*(const Ary2D_u2p14_5_10  *)    Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D())
	#define PrmCtrldVelRtnHwAuthyScaX_u2p14			(*(const Ary1D_u2p14_4  *)       Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D())
	#define PrmCtrldVelRtnHwAuthyScaY_u2p14			(*(const Ary1D_u2p14_4  *)       Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D())
	#define PrmCtrldVelRtnVelErrScaBilnrSeln_u12p4  (*(const Ary1D_u12p4_7  *)       Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D())
	#define PrmCtrldVelRtnVelErrScaX_s10p5          (*(const Ary1D_s10p5_8  *)       Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D())
	#define PrmCtrldVelRtnVelErrScaY_u2p14          (*(const Ary2D_u2p14_7_8  *)     Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D())
	#define PrmCtrldVelRtnVelErrVehSpdScaY_u2p14    (*(const Ary1D_u2p14_5  *)       Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D())
	#define PrmCtrldVelRtnDesVelX_u12p4			    (*(const Ary2D_u12p4_8_12  *)    Rte_Prm_CtrldVelRtnDesVelX_Ary2D())
	#define PrmCtrldVelRtnDesVelY_u10p6		        (*(const Ary2D_u10p6_8_12  *)    Rte_Prm_CtrldVelRtnDesVelY_Ary2D())
	#define PrmCtrldVelRtnVelSpdTbl_u9p7            (*(const Ary1D_u9p7_8  *)        Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D())
	#define PrmCtrldVelRtnIntglGain_u8p8            (*(const Ary1D_u8p8_8  *)        Rte_Prm_CtrldVelRtnIntglGain_Ary1D())
	#define PrmCtrldVelRtnIntgrLimY_u6p10           (*(const Ary2D_u6p10_5_9  *)     Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D())
	#define PrmCtrldVelRtnDampgX_u10p6              (*(const Ary2D_u10p6_8_9  *)     Rte_Prm_CtrldVelRtnDampgX_Ary2D())
	#define PrmCtrldVelRtnDampgY_u6p10  			(*(const Ary2D_u6p10_8_9  *)     Rte_Prm_CtrldVelRtnDampgY_Ary2D())
	#define PrmCtrldVelRtnRtnCmdLimY_u4p12          (*(const Ary1D_u4p12_8  *)       Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D())
	#define PrmCtrldVelRtnPropGain_u4p12            (*(const Ary1D_u4p12_8  *)       Rte_Prm_CtrldVelRtnPropGain_Ary1D())
	#define PrmCtrldVelRtnDesVelScaX_u8p8 			(*(const Ary2D_u8p8_5_8  *)      Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D())
	#define PrmCtrldVelRtnDesVelScaY_u2p14 			(*(const Ary2D_u2p14_5_8  *)     Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D())
	#define PrmCtrldVelRtnPinionTqScaX_u8p8         (*(const Ary2D_u8p8_5_8  *)      Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D())
	#define PrmCtrldVelRtnPinionTqScaY_u2p14        (*(const Ary2D_u2p14_5_8  *)     Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D())
	
	static FUNC(float32,CtrldVelRtn_CODE) DrvrTqSeln(VAR(float32, AUTOMATIC)MotTqCmdPwrLimd_MotNwtMtr_T_f32,
                                                               VAR(float32, AUTOMATIC)HwTq_HwNwtMtr_T_f32,
														       VAR(float32, AUTOMATIC)HwAgCmp_HwDeg_T_f32,
															   VAR(float32, AUTOMATIC)HwVel_HwRadPerSec_T_f32,
															   VAR(sint8, AUTOMATIC)AssiMechPolarity_Uls_T_s08);
															   
	 
    static FUNC(float32,CtrldVelRtn_CODE)Dampg(VAR(float32, AUTOMATIC)HwVel_HwDegPerSec_T_f32,
                                                 VAR(float32, AUTOMATIC)CtrlSca_Uls_T_f32,
											     VAR(uint16, AUTOMATIC)VehSpd_Kph_T_u9p7);
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
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * s10p5: Integer in interval [-32768...32767]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * u10p6: Integer in interval [0...65535]
 * u12p4: Integer in interval [0...65535]
 * u2p14: Integer in interval [0...65535]
 * u4p12: Integer in interval [0...65535]
 * u6p10: Integer in interval [0...65535]
 * u8p8: Integer in interval [0...65535]
 * u9p7: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * Ary1D_f32_4: Array with 4 element(s) of type float32
 * Ary1D_f32_5: Array with 5 element(s) of type float32
 * Ary1D_s10p5_8: Array with 8 element(s) of type s10p5
 * Ary1D_u10p6_12: Array with 12 element(s) of type u10p6
 * Ary1D_u10p6_9: Array with 9 element(s) of type u10p6
 * Ary1D_u12p4_12: Array with 12 element(s) of type u12p4
 * Ary1D_u12p4_7: Array with 7 element(s) of type u12p4
 * Ary1D_u12p4_9: Array with 9 element(s) of type u12p4
 * Ary1D_u2p14_10: Array with 10 element(s) of type u2p14
 * Ary1D_u2p14_4: Array with 4 element(s) of type u2p14
 * Ary1D_u2p14_5: Array with 5 element(s) of type u2p14
 * Ary1D_u2p14_8: Array with 8 element(s) of type u2p14
 * Ary1D_u2p14_9: Array with 9 element(s) of type u2p14
 * Ary1D_u4p12_8: Array with 8 element(s) of type u4p12
 * Ary1D_u6p10_9: Array with 9 element(s) of type u6p10
 * Ary1D_u8p8_10: Array with 10 element(s) of type u8p8
 * Ary1D_u8p8_8: Array with 8 element(s) of type u8p8
 * Ary1D_u9p7_5: Array with 5 element(s) of type u9p7
 * Ary1D_u9p7_8: Array with 8 element(s) of type u9p7
 * Ary2D_f32_5_4: Array with 5 element(s) of type Ary1D_f32_4
 * Ary2D_f32_5_5: Array with 5 element(s) of type Ary1D_f32_5
 * Ary2D_u10p6_8_12: Array with 8 element(s) of type Ary1D_u10p6_12
 * Ary2D_u10p6_8_9: Array with 8 element(s) of type Ary1D_u10p6_9
 * Ary2D_u12p4_8_12: Array with 8 element(s) of type Ary1D_u12p4_12
 * Ary2D_u2p14_5_10: Array with 5 element(s) of type Ary1D_u2p14_10
 * Ary2D_u2p14_5_8: Array with 5 element(s) of type Ary1D_u2p14_8
 * Ary2D_u2p14_7_8: Array with 7 element(s) of type Ary1D_u2p14_8
 * Ary2D_u6p10_5_9: Array with 5 element(s) of type Ary1D_u6p10_9
 * Ary2D_u6p10_8_9: Array with 8 element(s) of type Ary1D_u6p10_9
 * Ary2D_u8p8_5_10: Array with 5 element(s) of type Ary1D_u8p8_10
 * Ary2D_u8p8_5_8: Array with 5 element(s) of type Ary1D_u8p8_8
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
 *   float32 *Rte_Pim_PrevDesVel(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildA(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildB(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildC(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildD(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildE(void)
 *   float32 *Rte_Pim_PrevDrvrTqFildF(void)
 *   float32 *Rte_Pim_PrevHwAuthySca(void)
 *   float32 *Rte_Pim_PrevHwTqSeln(void)
 *   float32 *Rte_Pim_PrevIntglTermA(void)
 *   float32 *Rte_Pim_PrevIntglTermB(void)
 *   float32 *Rte_Pim_PrevIntglTermC(void)
 *   float32 *Rte_Pim_PrevRtnOffs(void)
 *   float32 *Rte_Pim_dCtrldVelRtnCtrlSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnCtrlScaPreFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDampgCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVel(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVelSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDesVelScaPreFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDrvrTqEstimd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnDrvrTqFild(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwAgCmp(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwAuthySca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwPosnSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwTqSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnHwTqScaSeln(void)
 *   float32 *Rte_Pim_dCtrldVelRtnIntglTermCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnIntgrLim(void)
 *   float32 *Rte_Pim_dCtrldVelRtnPinionTqSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnPropTermCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnRtnCmd(void)
 *   float32 *Rte_Pim_dCtrldVelRtnRtnCmdPreLim(void)
 *   float32 *Rte_Pim_dCtrldVelRtnTqGrdt(void)
 *   float32 *Rte_Pim_dCtrldVelRtnTqGrdtSca(void)
 *   float32 *Rte_Pim_dCtrldVelRtnVelErrSca(void)
 *   float32 *Rte_Pim_PrevDrvrTqMtrx(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *   FilLpRec1 *Rte_Pim_CtrlScaLpFil(void)
 *   FilLpRec1 *Rte_Pim_DesVelLpFil(void)
 *   FilLpRec1 *Rte_Pim_DesVelScaLpFil(void)
 *   FilLpRec1 *Rte_Pim_DrvrTqLpFil(void)
 *   FilLpRec1 *Rte_Pim_PinionTqLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_CtrldVelRtnAntiWdup_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnOffsSlewThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnOffsThd_Val(void)
 *   float32 Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysTqRat_Val(void)
 *   boolean Rte_Prm_CtrldVelRtnDampgEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnDampgScaEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnDrvrTqEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl(void)
 *   boolean Rte_Prm_CtrldVelRtnVelErrScaEna_Logl(void)
 *   u10p6 *Rte_Prm_CtrldVelRtnDampgX_Ary2D(void)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_9
 *   u6p10 *Rte_Prm_CtrldVelRtnDampgY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_8_9
 *   u8p8 *Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u12p4 *Rte_Prm_CtrldVelRtnDesVelX_Ary2D(void)
 *     Returnvalue: u12p4* is of type Ary2D_u12p4_8_12
 *   u10p6 *Rte_Prm_CtrldVelRtnDesVelY_Ary2D(void)
 *     Returnvalue: u10p6* is of type Ary2D_u10p6_8_12
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxA_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_5
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxB_Ary2D(void)
 *     Returnvalue: float32* is of type Ary2D_f32_5_4
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxC_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_5
 *   float32 *Rte_Prm_CtrldVelRtnDrvrTqMtrxD_Ary1D(void)
 *     Returnvalue: float32* is of type Ary1D_f32_4
 *   u2p14 *Rte_Prm_CtrldVelRtnHwAuthyScaX_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *   u2p14 *Rte_Prm_CtrldVelRtnHwAuthyScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_4
 *   u12p4 *Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_9
 *   u2p14 *Rte_Prm_CtrldVelRtnHwPosnScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_9
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_10
 *   u2p14 *Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_10
 *   u8p8 *Rte_Prm_CtrldVelRtnIntglGain_Ary1D(void)
 *     Returnvalue: u8p8* is of type Ary1D_u8p8_8
 *   u6p10 *Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(void)
 *     Returnvalue: u6p10* is of type Ary2D_u6p10_5_9
 *   u8p8 *Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u4p12 *Rte_Prm_CtrldVelRtnPropGain_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_8
 *   u4p12 *Rte_Prm_CtrldVelRtnRtnCmdLimY_Ary1D(void)
 *     Returnvalue: u4p12* is of type Ary1D_u4p12_8
 *   u8p8 *Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(void)
 *     Returnvalue: u8p8* is of type Ary2D_u8p8_5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_5_8
 *   u9p7 *Rte_Prm_CtrldVelRtnVehSpdScaBilnrSeln_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_5
 *   u12p4 *Rte_Prm_CtrldVelRtnVelErrScaBilnrSeln_Ary1D(void)
 *     Returnvalue: u12p4* is of type Ary1D_u12p4_7
 *   s10p5 *Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(void)
 *     Returnvalue: s10p5* is of type Ary1D_s10p5_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(void)
 *     Returnvalue: u2p14* is of type Ary2D_u2p14_7_8
 *   u2p14 *Rte_Prm_CtrldVelRtnVelErrVehSpdScaY_Ary1D(void)
 *     Returnvalue: u2p14* is of type Ary1D_u2p14_5
 *   u9p7 *Rte_Prm_CtrldVelRtnVelSpdTbl_Ary1D(void)
 *     Returnvalue: u9p7* is of type Ary1D_u9p7_8
 *
 *********************************************************************************************************************/


#define CtrldVelRtn_START_SEC_CODE
#include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnInit1
 *********************************************************************************************************************/
    /*** DrvrTqLpFil ***/
	
	FilLpInit(0.0F, Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(), ARCHGLBPRM_2MILLISEC_SEC_F32, Rte_Pim_DrvrTqLpFil());
	
    /*** DesVelScaLpFil ***/
    FilLpInit(0.0F, Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(),  ARCHGLBPRM_2MILLISEC_SEC_F32, Rte_Pim_DesVelScaLpFil());
	
    /*** CtrlScaLpFil ***/
    FilLpInit(0.0F, Rte_Prm_CtrldVelRtnScaLpFilFrq_Val(),  ARCHGLBPRM_2MILLISEC_SEC_F32, Rte_Pim_CtrlScaLpFil());
	
    /*** PinionTqLpFil ***/
    FilLpInit(0.0F, Rte_Prm_CtrldVelRtnHwTqLpFilFrq_Val(), ARCHGLBPRM_2MILLISEC_SEC_F32, Rte_Pim_PinionTqLpFil());
	
    /*** DesVelLpFil ***/
    FilLpInit(0.0F, Rte_Prm_CtrldVelRtnDesVelLpFilFrq_Val(), ARCHGLBPRM_2MILLISEC_SEC_F32, Rte_Pim_DesVelLpFil());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldVelRtnPer1
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
 *   Std_ReturnType Rte_Read_AssiMechPolarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_HwAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgAuthy_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwAgRtnOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdPwrLimd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RtnCmdDiagcDi_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RtnCmdSca_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RtnCmdScaServo_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_CtrldVelRtnCmd_Val(float32 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtrldVelRtn_CODE) CtrldVelRtnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtrldVelRtnPer1
 *********************************************************************************************************************/
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) HwAgRtnOffs_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwAg_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32;
    VAR(float32, AUTOMATIC) LimDyn_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) RateLimDyn_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwVel_HwDegPerSec_T_f32;
	VAR(float32, AUTOMATIC) HwAgCmp_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) MotTqCmdPwrLimd_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwAgAuthy_Uls_T_f32;
	VAR(float32, AUTOMATIC) DrvrTq_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) DrvrTqFild_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) PinionTqFild_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) TqGrdtPrdt1_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) TqGrdtPrdt2_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) TqGrdtPrdt3_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) TqGrdt_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) TqGrdtSca_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwPosnSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) RateLimDynInp_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwTqScaSeln_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwTqSca1_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwTqSca2_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwTqSca_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwAuthySca_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelScaPreFild_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) DesVelSca_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) PinionTqSca_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) CalcVelErrSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) VelErrScaPrdt_Uls_T_f32;
	VAR(float32, AUTOMATIC) VelErrSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) ScalePrdt_Uls_T_f32;
	VAR(float32, AUTOMATIC) CtrlSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelPrdt_Uls_T_f32;
	VAR(float32, AUTOMATIC) DesVelFilpInp_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) DesVel_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) PropGain_Uls_T_f32;
	VAR(float32, AUTOMATIC) IntglGain_Uls_T_f32;
	VAR(float32, AUTOMATIC) PropTerm_Uls_T_f32;
	VAR(float32, AUTOMATIC) IntgrThdPrdt_Uls_T_f32;
	VAR(float32, AUTOMATIC) IntgrThd_Uls_T_f32;
	VAR(float32, AUTOMATIC) IntglTermPrdt_Uls_T_f32;
	VAR(float32, AUTOMATIC) IntglTermCntPrdt_Uls_T_f32;
	VAR(float32, AUTOMATIC) IntglTermLimDynInp_Uls_T_f32;
	VAR(float32, AUTOMATIC) IntglTerm_Uls_T_f32;
	VAR(float32, AUTOMATIC) PITerm_Uls_T_f32;
	VAR(float32, AUTOMATIC) DampgTerm_HwNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) RtnCmdSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) RtnCmdScaServo_Uls_T_f32;
	VAR(float32, AUTOMATIC) SetRtnCmd_Cnt_T_f32;
	VAR(float32, AUTOMATIC) LimitLimDynInp_Cnt_T_f32;
	VAR(float32, AUTOMATIC) RtnCmdLimLnrIntrpn_Cnt_T_f32;
	VAR(float32, AUTOMATIC) RtnCmdLim_Cnt_T_f32;
	VAR(float32, AUTOMATIC) CtrldVelRtnCmd_MotNwtMtr_T_f32;
	VAR(float32, AUTOMATIC) HwAgCmp_HwDegPerSec_T_f32;
	
	VAR(uint16,  AUTOMATIC) VehSpd_Kph_T_u9p7;
	VAR(uint16,  AUTOMATIC) TqGrdt_HwNwtMtr_T_u8p8;
	VAR(uint16,  AUTOMATIC) TqGrdt_HwNwtMtr_T_u2p14;
	VAR(uint16,  AUTOMATIC) HwAgCmp_HwDegPerSec_T_u12p4;
	VAR(uint16,  AUTOMATIC) HwPosnSca_Uls_T_u2p14;
    VAR(uint16,  AUTOMATIC) DrvrTqFild_HwNwtMtr_T_u8p8;
	VAR(uint16,  AUTOMATIC) HwTqSca1_HwNwtMtr_T_u2p14;
	VAR(uint16,  AUTOMATIC) HwTqSca2_HwNwtMtr_T_u2p14;
	VAR(uint16,  AUTOMATIC) HwAgAuthy_Uls_T_u2p14;
	VAR(uint16,  AUTOMATIC) HwAgAuthySca_Uls_T_u2p14;
	VAR(uint16,  AUTOMATIC) DesVelScaPreFild_HwNwtMtr_T_u2p14;
	VAR(uint16,  AUTOMATIC) PinionTqFild_HwNwtMtr_T_u8p8;
	VAR(uint16,  AUTOMATIC) PinionTqSca_HwNwtMtr_T_u2p14;
	VAR(uint16,  AUTOMATIC) CalcVelErrSca_Uls_T_u2p14;
	VAR(uint16,  AUTOMATIC) VelErrSca_Uls_T_u2p14;
	VAR(uint16,  AUTOMATIC) DesVelPrdt_Uls_T_u10p6;
	VAR(uint16,  AUTOMATIC) PropGain_Uls_T_u4p12;
	VAR(uint16,  AUTOMATIC) IntglGain_Uls_T_u8p8;
	VAR(uint16,  AUTOMATIC) IntgrThd_Uls_T_u6p10;
	VAR(uint16,  AUTOMATIC) RtnCmdLimLnrIntrpn_Cnt_T_u4p12;
	
	
	
	VAR(sint8, AUTOMATIC)AssiMechPolarity_Uls_T_s08;
	VAR(sint8, AUTOMATIC)HwAgCmp_HwDegPerSec_T_s08;
	
	VAR(sint16, AUTOMATIC)HwVel_HwDegPerSec_T_s10p5;
	VAR(sint16, AUTOMATIC)HwAgCmp_HwDegPerSec_T_s15p0;
	
	
	VAR(boolean, AUTOMATIC)RtnCmdDi_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) RtnCmdDiagcDi_Cnt_T_logl;
	

	
	 /*** Read inputs from RTE ***/
	(void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
	(void)Rte_Read_HwAgRtnOffs_Val(&HwAgRtnOffs_HwDeg_T_f32);
	(void)Rte_Read_HwAg_Val(&HwAg_HwDeg_T_f32);
	(void)Rte_Read_HwVel_Val(&HwVel_HwRadPerSec_T_f32);
	(void)Rte_Read_MotTqCmdPwrLimd_Val(&MotTqCmdPwrLimd_MotNwtMtr_T_f32);
	(void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
	(void)Rte_Read_AssiMechPolarity_Val(&AssiMechPolarity_Uls_T_s08);
	(void)Rte_Read_HwAgAuthy_Val(&HwAgAuthy_Uls_T_f32);
	(void)Rte_Read_RtnCmdDi_Logl(&RtnCmdDi_Cnt_T_logl);
    (void)Rte_Read_RtnCmdDiagcDi_Logl(&RtnCmdDiagcDi_Cnt_T_logl);
    (void)Rte_Read_RtnCmdSca_Val(&RtnCmdSca_Uls_T_f32);
    (void)Rte_Read_RtnCmdScaServo_Val(&RtnCmdScaServo_Uls_T_f32);
	
	
	VehSpd_Kph_T_u9p7  = FloatToFixd_u16_f32(VehSpd_Kph_T_f32,NXTRFIXDPT_FLOATTOP7_ULS_F32);
	
	/*** Start of Input Conditioning ***/
	LimDyn_HwDeg_T_f32 = Lim_f32(HwAgRtnOffs_HwDeg_T_f32,
								-Rte_Prm_CtrldVelRtnOffsThd_Val(),
								 Rte_Prm_CtrldVelRtnOffsThd_Val());
	RateLimDyn_HwDeg_T_f32 = Lim_f32(LimDyn_HwDeg_T_f32, 
								    (((-Rte_Prm_CtrldVelRtnOffsSlewThd_Val()) * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_PrevRtnOffs()), 
									(((Rte_Prm_CtrldVelRtnOffsSlewThd_Val())  * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_PrevRtnOffs()));	
    *Rte_Pim_PrevRtnOffs() = RateLimDyn_HwDeg_T_f32;
    HwAgCmp_HwDeg_T_f32 = HwAg_HwDeg_T_f32 - RateLimDyn_HwDeg_T_f32;
	*Rte_Pim_dCtrldVelRtnHwAgCmp() = HwAgCmp_HwDeg_T_f32;
	
	HwVel_HwDegPerSec_T_f32 = HwVel_HwRadPerSec_T_f32 * ARCHGLBPRM_180OVERPI_ULS_F32;
	/*** End of Input Conditioning ***/
	
	/*** Start of DriverTorque Selector ***/
	
	DrvrTq_HwNwtMtr_T_f32 = DrvrTqSeln(MotTqCmdPwrLimd_MotNwtMtr_T_f32,
                                                 HwTq_HwNwtMtr_T_f32,
												 HwAgCmp_HwDeg_T_f32,
												 HwVel_HwRadPerSec_T_f32,
												 AssiMechPolarity_Uls_T_s08);

												 
	/*** End of DriverTorque Selector ***/	
	
	
	/*** Start of Return Command ***/
	/*** Start of Scale ***/
	
	DrvrTqFild_HwNwtMtr_T_f32 = FilLpUpdOutp_f32(DrvrTq_HwNwtMtr_T_f32,Rte_Pim_DrvrTqLpFil());
	*Rte_Pim_dCtrldVelRtnDrvrTqFild() = DrvrTqFild_HwNwtMtr_T_f32;
	
	PinionTqFild_HwNwtMtr_T_f32 = FilLpUpdOutp_f32(HwTq_HwNwtMtr_T_f32,Rte_Pim_PinionTqLpFil());
	
	/*** Start of Torque Gradient Scale ***/
	

	if(TRUE == Rte_Prm_CtrldVelRtnTqGrdtScaEna_Logl())
	{   
	   
		TqGrdtPrdt1_HwNwtMtr_T_f32 = (*Rte_Pim_PrevDrvrTqFildA() - *Rte_Pim_PrevDrvrTqFildE()) * TQGRDTCALCNWGHTFAC2_ULSPERSEC_F32;
		
	    TqGrdtPrdt2_HwNwtMtr_T_f32 = (*Rte_Pim_PrevDrvrTqFildB() - *Rte_Pim_PrevDrvrTqFildD()) * TQGRDTCALCNWGHTFAC3_ULSPERSEC_F32;
		
	    TqGrdtPrdt3_HwNwtMtr_T_f32 =  ((TQGRDTCALCNWGHTFAC4_ULSPERSEC_F32 * DrvrTqFild_HwNwtMtr_T_f32) -  *Rte_Pim_PrevDrvrTqFildF()) *TQGRDTCALCNWGHTFAC1_ULSPERSEC_F32;
	    
		
		TqGrdt_HwNwtMtr_T_f32 = TqGrdtPrdt1_HwNwtMtr_T_f32 + TqGrdtPrdt2_HwNwtMtr_T_f32 + TqGrdtPrdt3_HwNwtMtr_T_f32;
	    
		*Rte_Pim_PrevDrvrTqFildF() = *Rte_Pim_PrevDrvrTqFildE();
		*Rte_Pim_PrevDrvrTqFildE() = *Rte_Pim_PrevDrvrTqFildD();
		*Rte_Pim_PrevDrvrTqFildD() = *Rte_Pim_PrevDrvrTqFildC();
		*Rte_Pim_PrevDrvrTqFildC() = *Rte_Pim_PrevDrvrTqFildB();
		*Rte_Pim_PrevDrvrTqFildB() = *Rte_Pim_PrevDrvrTqFildA();
		*Rte_Pim_PrevDrvrTqFildA() =  TQGRDTCALCNWGHTFAC4_ULSPERSEC_F32 * DrvrTqFild_HwNwtMtr_T_f32;
		
		*Rte_Pim_dCtrldVelRtnTqGrdt() = TqGrdt_HwNwtMtr_T_f32;
		
		TqGrdt_HwNwtMtr_T_u8p8 = FloatToFixd_u16_f32((Abslt_f32_f32(TqGrdt_HwNwtMtr_T_f32)),NXTRFIXDPT_FLOATTOP8_ULS_F32);
		
		TqGrdt_HwNwtMtr_T_u2p14 = BilnrIntrpnWithRound_u16_u16MplXu16MplY( VehSpd_Kph_T_u9p7,
																		  TqGrdt_HwNwtMtr_T_u8p8,
																		  PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7,
																		 (uint16)TblSize_m(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7),
																		  Rte_Prm_CtrldVelRtnTqGrdtScaX_Ary2D(),
																		  Rte_Prm_CtrldVelRtnTqGrdtScaY_Ary2D(),
																		 (uint16)TblSize_m(PrmCtrldVelRtnTqGrdtScaX_u8p8[0]));
																		  
		TqGrdtSca_HwNwtMtr_T_f32 = FixdToFloat_f32_u16(TqGrdt_HwNwtMtr_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);
		
	}
	else
	{
		TqGrdtSca_HwNwtMtr_T_f32 = 1.0F;
	}
	
	
		*Rte_Pim_dCtrldVelRtnTqGrdtSca() = TqGrdtSca_HwNwtMtr_T_f32;
		
	/*** End of Torque Gradient Scale ***/
	
	/*** Start of  Position Scale ***/
	HwAgCmp_HwDegPerSec_T_u12p4  = FloatToFixd_u16_f32((Abslt_f32_f32(HwAgCmp_HwDeg_T_f32)), NXTRFIXDPT_FLOATTOP4_ULS_F32);
   
    HwPosnSca_Uls_T_u2p14 = LnrIntrpn_u16_u16VariXu16VariY(PrmCtrldVelRtnHwPosnScaX_u12p4,
														   PrmCtrldVelRtnHwPosnScaY_u2p14,
														  (uint16)TblSize_m(PrmCtrldVelRtnHwPosnScaX_u12p4),
														   HwAgCmp_HwDegPerSec_T_u12p4);
															 
	 HwPosnSca_Uls_T_f32	= 	FixdToFloat_f32_u16(HwPosnSca_Uls_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);											 
	 
	 *Rte_Pim_dCtrldVelRtnHwPosnSca() = HwPosnSca_Uls_T_f32;
	 
	 /*** End of Position Scale ***/
	
	/*** Start of Driver Handwheel Torque Scale ***/
	
	 /*** Start of Handwheel Torque Scale Selection***/
	if(((DrvrTqFild_HwNwtMtr_T_f32 > Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val())&&
	    (HwVel_HwDegPerSec_T_f32 > Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val())) ||
		((DrvrTqFild_HwNwtMtr_T_f32 < -Rte_Prm_CtrldVelRtnHwTqScaSelnTqThd_Val())&&
	    (HwVel_HwDegPerSec_T_f32 < -Rte_Prm_CtrldVelRtnHwTqScaSelnVelThd_Val())))
	{      
	    RateLimDynInp_HwNwtMtr_T_f32 = 1.0F;
		
	}
	else
	{
	    RateLimDynInp_HwNwtMtr_T_f32 = 0.0F;
	}
	
	HwTqScaSeln_HwNwtMtr_T_f32 = Lim_f32(RateLimDynInp_HwNwtMtr_T_f32, 
									   (((Rte_Prm_CtrldVelRtnHwTqScaSelnSlewLoLim_Val())  * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_PrevHwTqSeln()), 
									   (((Rte_Prm_CtrldVelRtnHwTqScaSelnSlewHiLim_Val())  * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_PrevHwTqSeln()));
	*Rte_Pim_PrevHwTqSeln() = HwTqScaSeln_HwNwtMtr_T_f32;
	
	*Rte_Pim_dCtrldVelRtnHwTqScaSeln() = HwTqScaSeln_HwNwtMtr_T_f32;
	/*** End of Handwheel Torque Scale Selection ***/
	
	/*** Start of Handwheel Torque Scale Calculation ***/
	DrvrTqFild_HwNwtMtr_T_u8p8 = FloatToFixd_u16_f32((Abslt_f32_f32(DrvrTqFild_HwNwtMtr_T_f32)), NXTRFIXDPT_FLOATTOP8_ULS_F32);

																		
HwTqSca1_HwNwtMtr_T_u2p14 = BilnrIntrpnWithRound_u16_u16MplXu16MplY(	VehSpd_Kph_T_u9p7,DrvrTqFild_HwNwtMtr_T_u8p8,
																		PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7,
																		(uint16)TblSize_m(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7),
																		Rte_Prm_CtrldVelRtnHwTqSca1X_Ary2D(),
																		Rte_Prm_CtrldVelRtnHwTqSca1Y_Ary2D(),
																		(uint16)TblSize_m(PrmCtrldVelRtnHwTqSca1X_u8p8[0]));
																		
																	 
	HwTqSca1_HwNwtMtr_T_f32 = 	FixdToFloat_f32_u16(HwTqSca1_HwNwtMtr_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);
	
   
	
	HwTqSca2_HwNwtMtr_T_u2p14 = BilnrIntrpnWithRound_u16_u16MplXu16MplY(VehSpd_Kph_T_u9p7,
																	    DrvrTqFild_HwNwtMtr_T_u8p8,
																	    PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7,
																	    (uint16)TblSize_m(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7),
																	    Rte_Prm_CtrldVelRtnHwTqSca2X_Ary2D(),
																	    Rte_Prm_CtrldVelRtnHwTqSca2Y_Ary2D(),
																	   (uint16)TblSize_m(PrmCtrldVelRtnHwTqSca2X_u8p8[0]));	
																	   
	HwTqSca2_HwNwtMtr_T_f32 = 	FixdToFloat_f32_u16(HwTqSca2_HwNwtMtr_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);
	
	HwTqSca_HwNwtMtr_T_f32	= Blnd_f32(HwTqSca1_HwNwtMtr_T_f32,
                                       HwTqSca2_HwNwtMtr_T_f32,
                                       HwTqScaSeln_HwNwtMtr_T_f32);
									   
	*Rte_Pim_dCtrldVelRtnHwTqSca() = HwTqSca_HwNwtMtr_T_f32;
	/*** End of Handwheel Torque Scale Calculation ***/
	
	/*** End of Driver Handwheel Torque Scale ***/
	
	/*** Start of Handwheel Authority Scale ***/
	HwAgAuthy_Uls_T_u2p14  = FloatToFixd_u16_f32(HwAgAuthy_Uls_T_f32, NXTRFIXDPT_FLOATTOP14_ULS_F32);
	 
    HwAgAuthySca_Uls_T_u2p14 = LnrIntrpn_u16_u16VariXu16VariY(PrmCtrldVelRtnHwAuthyScaX_u2p14,
														      PrmCtrldVelRtnHwAuthyScaY_u2p14,
														      (uint16)TblSize_m(PrmCtrldVelRtnHwAuthyScaX_u2p14),
														      HwAgAuthy_Uls_T_u2p14);
															
	HwAuthySca_Uls_T_f32	= 	FixdToFloat_f32_u16(HwAgAuthySca_Uls_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);
				
	HwAuthySca_Uls_T_f32 = Lim_f32(HwAuthySca_Uls_T_f32, 
								(((-Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val())  * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_PrevHwAuthySca()), 
								(((Rte_Prm_CtrldVelRtnHwAuthySlewThd_Val())   * ARCHGLBPRM_2MILLISEC_SEC_F32) + *Rte_Pim_PrevHwAuthySca()));
		*Rte_Pim_PrevHwAuthySca() = HwAuthySca_Uls_T_f32;						  
	  *Rte_Pim_dCtrldVelRtnHwAuthySca() = HwAuthySca_Uls_T_f32;
    
    /*** End of Handwheel Authority Scale ***/	
	
	/*** Start of Desired Velocity Scale***/
	
	
	DesVelScaPreFild_HwNwtMtr_T_u2p14 = BilnrIntrpnWithRound_u16_u16MplXu16MplY(VehSpd_Kph_T_u9p7,
																		        DrvrTqFild_HwNwtMtr_T_u8p8,
																				PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7,
																				(uint16)TblSize_m(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7),
																				Rte_Prm_CtrldVelRtnDesVelScaX_Ary2D(),
																				Rte_Prm_CtrldVelRtnDesVelScaY_Ary2D(),
																				(uint16)TblSize_m(PrmCtrldVelRtnDesVelScaX_u8p8[0]));
																	 
	DesVelScaPreFild_HwNwtMtr_T_f32 = 	FixdToFloat_f32_u16(DesVelScaPreFild_HwNwtMtr_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);
	
	*Rte_Pim_dCtrldVelRtnDesVelScaPreFild() = DesVelScaPreFild_HwNwtMtr_T_f32;
	
	DesVelSca_HwNwtMtr_T_f32 = FilLpUpdOutp_f32(DesVelScaPreFild_HwNwtMtr_T_f32,Rte_Pim_DesVelScaLpFil());
	
	*Rte_Pim_dCtrldVelRtnDesVelSca() = DesVelSca_HwNwtMtr_T_f32;
	
	/*** End of Desired Velocity Scale ***/
	
	/*** Start of Pinion Torque Scale***/
	PinionTqFild_HwNwtMtr_T_u8p8 = FloatToFixd_u16_f32((Abslt_f32_f32(PinionTqFild_HwNwtMtr_T_f32)),NXTRFIXDPT_FLOATTOP8_ULS_F32);
	
	PinionTqSca_HwNwtMtr_T_u2p14 = BilnrIntrpnWithRound_u16_u16MplXu16MplY(VehSpd_Kph_T_u9p7,
																		   PinionTqFild_HwNwtMtr_T_u8p8,
																		   PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7,
																		  (uint16)TblSize_m(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7),
																		   Rte_Prm_CtrldVelRtnPinionTqScaX_Ary2D(),
																		   Rte_Prm_CtrldVelRtnPinionTqScaY_Ary2D(),
																		   (uint16)TblSize_m(PrmCtrldVelRtnPinionTqScaX_u8p8[0]));
																	 
	PinionTqSca_HwNwtMtr_T_f32 = FixdToFloat_f32_u16(PinionTqSca_HwNwtMtr_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);
	
	*Rte_Pim_dCtrldVelRtnPinionTqSca() = PinionTqSca_HwNwtMtr_T_f32;
	
	/*** End of Pinion Torque Scale ***/
	
	
	/*** Start of Velocity Error Scale ***/
	
	if(TRUE == Rte_Prm_CtrldVelRtnVelErrScaEna_Logl())
	{
	    HwVel_HwDegPerSec_T_s10p5 = FloatToFixd_s16_f32((Abslt_f32_f32(HwVel_HwDegPerSec_T_f32) - Abslt_f32_f32(*Rte_Pim_PrevDesVel())),NXTRFIXDPT_FLOATTOP5_ULS_F32);
	
		CalcVelErrSca_Uls_T_u2p14 =  BilnrIntrpnWithRound_u16_s16CmnXu16MplY(HwAgCmp_HwDegPerSec_T_u12p4,
																		   (sint16)HwVel_HwDegPerSec_T_s10p5,
																		    PrmCtrldVelRtnVelErrScaBilnrSeln_u12p4,
																		   (uint16)TblSize_m(PrmCtrldVelRtnVelErrScaBilnrSeln_u12p4),
																		    Rte_Prm_CtrldVelRtnVelErrScaX_Ary1D(),
																		    Rte_Prm_CtrldVelRtnVelErrScaY_Ary2D(),
																		   (uint16)TblSize_m(PrmCtrldVelRtnVelErrScaX_s10p5));
		
		CalcVelErrSca_Uls_T_f32 =  FixdToFloat_f32_u16(CalcVelErrSca_Uls_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);
		
	}	
	else
	{
		CalcVelErrSca_Uls_T_f32 = 1.0F;
	}
	
	VelErrSca_Uls_T_u2p14 = LnrIntrpn_u16_u16VariXu16VariY(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7,
														   PrmCtrldVelRtnVelErrVehSpdScaY_u2p14,
														  (uint16)TblSize_m(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7),
														   VehSpd_Kph_T_u9p7);
	
	VelErrScaPrdt_Uls_T_f32 = FixdToFloat_f32_u16(VelErrSca_Uls_T_u2p14,NXTRFIXDPT_P14TOFLOAT_ULS_F32);		
	
	VelErrSca_Uls_T_f32 =  (CalcVelErrSca_Uls_T_f32 * VelErrScaPrdt_Uls_T_f32) + (1.0F - VelErrScaPrdt_Uls_T_f32);

	*Rte_Pim_dCtrldVelRtnVelErrSca() = VelErrSca_Uls_T_f32;
	
	/*** End of Velocity Error Scale ***/
	
 
	ScalePrdt_Uls_T_f32 =  (HwPosnSca_Uls_T_f32 * HwTqSca_HwNwtMtr_T_f32 * PinionTqSca_HwNwtMtr_T_f32 * TqGrdtSca_HwNwtMtr_T_f32 * VelErrSca_Uls_T_f32 * HwAuthySca_Uls_T_f32);
	
	*Rte_Pim_dCtrldVelRtnCtrlScaPreFild() = ScalePrdt_Uls_T_f32;
	
	CtrlSca_Uls_T_f32 = FilLpUpdOutp_f32(ScalePrdt_Uls_T_f32,Rte_Pim_CtrlScaLpFil());
	
	*Rte_Pim_dCtrldVelRtnCtrlSca() = CtrlSca_Uls_T_f32;
	
	/*** End of Scale ***/
	
	/*** Start of Desired Velocity ***/
	
	DesVelPrdt_Uls_T_u10p6 =  BilnrIntrpnWithRound_u16_u16MplXu16MplY(VehSpd_Kph_T_u9p7,
																      HwAgCmp_HwDegPerSec_T_u12p4,
																      PrmCtrldVelRtnVelSpdTbl_u9p7,
																     (uint16)TblSize_m(PrmCtrldVelRtnVelSpdTbl_u9p7),
																      Rte_Prm_CtrldVelRtnDesVelX_Ary2D(),
																      Rte_Prm_CtrldVelRtnDesVelY_Ary2D(),
																     (uint16)TblSize_m(PrmCtrldVelRtnDesVelX_u12p4[0]));
	
	DesVelPrdt_Uls_T_f32 =  FixdToFloat_f32_u16(DesVelPrdt_Uls_T_u10p6,NXTRFIXDPT_P6TOFLOAT_ULS_F32);
	
	HwAgCmp_HwDegPerSec_T_s08 =  Sign_s08_f32(HwAgCmp_HwDeg_T_f32);
	HwAgCmp_HwDegPerSec_T_s15p0 = (sint16)HwAgCmp_HwDegPerSec_T_s08;
	HwAgCmp_HwDegPerSec_T_f32 = FixdToFloat_f32_s16(HwAgCmp_HwDegPerSec_T_s15p0, NXTRFIXDPT_P0TOFLOAT_ULS_F32);
	DesVelFilpInp_HwNwtMtr_T_f32 = DesVelSca_HwNwtMtr_T_f32 * (-HwAgCmp_HwDegPerSec_T_f32) * DesVelPrdt_Uls_T_f32;
	
	DesVel_HwNwtMtr_T_f32 = FilLpUpdOutp_f32(DesVelFilpInp_HwNwtMtr_T_f32,Rte_Pim_DesVelLpFil());
	
	*Rte_Pim_dCtrldVelRtnDesVel() = DesVel_HwNwtMtr_T_f32;
	
	*Rte_Pim_PrevDesVel() = DesVel_HwNwtMtr_T_f32;
	
	/*** End of Desired Velocity ***/
	
	/*** Start of Control ***/
	/*** Start of Control Gain***/ 
	PropGain_Uls_T_u4p12 = LnrIntrpn_u16_u16VariXu16VariY(PrmCtrldVelRtnVelSpdTbl_u9p7,
														  PrmCtrldVelRtnPropGain_u4p12,
														 (uint16)TblSize_m(PrmCtrldVelRtnVelSpdTbl_u9p7),
														  VehSpd_Kph_T_u9p7);
														  
	PropGain_Uls_T_f32  =  FixdToFloat_f32_u16(PropGain_Uls_T_u4p12,NXTRFIXDPT_P12TOFLOAT_ULS_F32);
	
	IntglGain_Uls_T_u8p8 = LnrIntrpn_u16_u16VariXu16VariY(PrmCtrldVelRtnVelSpdTbl_u9p7,
														 PrmCtrldVelRtnIntglGain_u8p8,
														 (uint16)TblSize_m(PrmCtrldVelRtnVelSpdTbl_u9p7),
														  VehSpd_Kph_T_u9p7);

	IntglGain_Uls_T_f32 =  FixdToFloat_f32_u16(IntglGain_Uls_T_u8p8,NXTRFIXDPT_P8TOFLOAT_ULS_F32);
	/*** End of Control Gain ***/
	
	/*** Start of Proportional Control***/
	PropTerm_Uls_T_f32 = (PropGain_Uls_T_f32 ) * (DesVel_HwNwtMtr_T_f32 - HwVel_HwDegPerSec_T_f32) * (CtrlSca_Uls_T_f32);
	*Rte_Pim_dCtrldVelRtnPropTermCmd() = PropTerm_Uls_T_f32;
	/*** End of Proportional Control ***/
	
	/*** Start of Integral Control***/
	IntgrThd_Uls_T_u6p10 =  BilnrIntrpnWithRound_u16_u16CmnXu16MplY(VehSpd_Kph_T_u9p7,
																    HwAgCmp_HwDegPerSec_T_u12p4,
																    PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7,
																   (uint16)TblSize_m(PrmCtrldVelRtnVehSpdScaBilnrSeln_u9p7),
																    Rte_Prm_CtrldVelRtnHwPosnScaX_Ary1D(),
																    Rte_Prm_CtrldVelRtnIntgrLimY_Ary2D(),
																   (uint16)TblSize_m(PrmCtrldVelRtnHwPosnScaX_u12p4));	
		
	IntgrThdPrdt_Uls_T_f32 =  FixdToFloat_f32_u16(IntgrThd_Uls_T_u6p10,NXTRFIXDPT_P10TOFLOAT_ULS_F32);
	IntgrThd_Uls_T_f32 =  IntgrThdPrdt_Uls_T_f32 * CtrlSca_Uls_T_f32;
	
	*Rte_Pim_dCtrldVelRtnIntgrLim() = IntgrThd_Uls_T_f32;
	
	
	IntglTermPrdt_Uls_T_f32 = (((IntglGain_Uls_T_f32) * (DesVel_HwNwtMtr_T_f32 - HwVel_HwDegPerSec_T_f32) * (CtrlSca_Uls_T_f32)) +  (*Rte_Pim_PrevIntglTermC()));
	
	
	
	IntglTermCntPrdt_Uls_T_f32 = (*Rte_Pim_PrevIntglTermA() + IntglTermPrdt_Uls_T_f32) * ONEHALF_ULS_F32 * ARCHGLBPRM_2MILLISEC_SEC_F32 * UNITADJMTTERM_ULSPERSEC_F32;
	*Rte_Pim_PrevIntglTermA() = IntglTermPrdt_Uls_T_f32;
	
	IntglTermLimDynInp_Uls_T_f32  =  IntglTermCntPrdt_Uls_T_f32 + *Rte_Pim_PrevIntglTermB();
	
	IntglTerm_Uls_T_f32 = Lim_f32(IntglTermLimDynInp_Uls_T_f32,
								 -IntgrThd_Uls_T_f32,
								  IntgrThd_Uls_T_f32);
	
	*Rte_Pim_PrevIntglTermB() = IntglTerm_Uls_T_f32;
	
	*Rte_Pim_PrevIntglTermC() = Rte_Prm_CtrldVelRtnAntiWdup_Val()*(IntglTerm_Uls_T_f32 - IntglTermLimDynInp_Uls_T_f32) ;
	
	*Rte_Pim_dCtrldVelRtnIntglTermCmd() = IntglTerm_Uls_T_f32;

	
	PITerm_Uls_T_f32 = PropTerm_Uls_T_f32 + IntglTerm_Uls_T_f32;
	
	/*** End of Integral Control***/
	
	/*** Start of Damping ***/
	DampgTerm_HwNwtMtr_T_f32 = Dampg(HwVel_HwDegPerSec_T_f32,
                                       CtrlSca_Uls_T_f32,
			                           VehSpd_Kph_T_u9p7);
	/*** End of Damping ***/
	
									   
	/*** Start of Limit ***/
	
	if((TRUE == RtnCmdDi_Cnt_T_logl)||
	   (TRUE == RtnCmdDiagcDi_Cnt_T_logl))
	{
		SetRtnCmd_Cnt_T_f32 = 0.0F;
	}
	else
	{   
		SetRtnCmd_Cnt_T_f32 = ((PITerm_Uls_T_f32) - (DampgTerm_HwNwtMtr_T_f32)) * ((float32)SIGNCORRN_CNT_S08) *  RtnCmdScaServo_Uls_T_f32 * RtnCmdSca_Uls_T_f32;
	}
	
	LimitLimDynInp_Cnt_T_f32 = (SetRtnCmd_Cnt_T_f32 / Rte_Prm_SysGlbPrmSysTqRat_Val());
	
	*Rte_Pim_dCtrldVelRtnRtnCmdPreLim() = LimitLimDynInp_Cnt_T_f32;

	RtnCmdLimLnrIntrpn_Cnt_T_u4p12 = LnrIntrpn_u16_u16VariXu16VariY(PrmCtrldVelRtnVelSpdTbl_u9p7,
														      PrmCtrldVelRtnRtnCmdLimY_u4p12,
														     (uint16)TblSize_m(PrmCtrldVelRtnVelSpdTbl_u9p7),
														      VehSpd_Kph_T_u9p7);

	RtnCmdLimLnrIntrpn_Cnt_T_f32 = FixdToFloat_f32_u16(RtnCmdLimLnrIntrpn_Cnt_T_u4p12,NXTRFIXDPT_P12TOFLOAT_ULS_F32);
	
	
	RtnCmdLim_Cnt_T_f32 = Lim_f32(LimitLimDynInp_Cnt_T_f32,
								 -RtnCmdLimLnrIntrpn_Cnt_T_f32,
								  RtnCmdLimLnrIntrpn_Cnt_T_f32);
								 
	CtrldVelRtnCmd_MotNwtMtr_T_f32    = Lim_f32(RtnCmdLim_Cnt_T_f32,
										RTNCMDLLIM_MOTNWTMTR_F32,
										RTNCMDULIM_MOTNWTMTR_F32);
							 
	*Rte_Pim_dCtrldVelRtnRtnCmd() = CtrldVelRtnCmd_MotNwtMtr_T_f32;	

	/*** End of Limit ***/
	/*** End of Return Command ***/
	
	
	/*** Write Output to RTE ***/
	(void)Rte_Write_CtrldVelRtnCmd_Val(CtrldVelRtnCmd_MotNwtMtr_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtrldVelRtn_STOP_SEC_CODE
#include "CtrldVelRtn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************************************************************
* Name        :   DrvrTqSeln
* Description :   Sub function to calculate Driver torque selector.
* Inputs      :   MotTqCmdPwrLimd_MotNwtMtr_T_f32,HwTq_HwNwtMtr_T_f32,HwAgCmp_HwDeg_T_f32,HwVel_HwRadPerSec_T_f32,AssiMechPolarity_Uls_T_s08.
* Returns     :   DrvrTq_HwNwtMtr_T_f32.
* Usage Notes :   This refers to "Driver Torque Selector" subsystem of FDD.
******************************************************************************************************************************/
 
 static FUNC(float32,CtrldVelRtn_CODE) DrvrTqSeln(VAR(float32, AUTOMATIC)MotTqCmdPwrLimd_MotNwtMtr_T_f32,
                                                            VAR(float32, AUTOMATIC)HwTq_HwNwtMtr_T_f32,
														    VAR(float32, AUTOMATIC)HwAgCmp_HwDeg_T_f32,
															VAR(float32, AUTOMATIC)HwVel_HwRadPerSec_T_f32,
															VAR(sint8, AUTOMATIC)AssiMechPolarity_Uls_T_s08)
 {
	VAR(float32, AUTOMATIC) DriverTorquePrdt1_Uls_T_f32;
	VAR(float32, AUTOMATIC) DriverTorquePrdt2_Uls_T_f32;
	VAR(float32, AUTOMATIC) DrvrTorque_Uls_T_f32[IDX4_CNT_U08][1];
	VAR(float32, AUTOMATIC) SumDrvrTorque1_Uls_T_f32[IDX5_CNT_U08]={0.0F,0.0F,0.0F,0.0F,0.0F};
	VAR(float32, AUTOMATIC) SumDrvrTorque2_Uls_T_f32[IDX5_CNT_U08]={0.0F,0.0F,0.0F,0.0F,0.0F};
	VAR(float32, AUTOMATIC) SumDrvrTorqueTot_Uls_T_f32[IDX5_CNT_U08];
	VAR(float32, AUTOMATIC) LimDyn1_Uls_T_f32;
	VAR(float32, AUTOMATIC) LimDyn2_Uls_T_f32;
	VAR(float32, AUTOMATIC) LimDyn3_Uls_T_f32;
	VAR(float32, AUTOMATIC) LimDyn4_Uls_T_f32;
	VAR(float32, AUTOMATIC) LimDyn5_Uls_T_f32;
	VAR(float32, AUTOMATIC) SumDrvrTorque3_Uls_T_f32[1]={0.0F};
	VAR(float32, AUTOMATIC) SumDrvrTorque4_Uls_T_f32[1]={0.0F};
	VAR(float32, AUTOMATIC) SumDrvrTorqueTot2_Uls_T_f32[1];
	VAR(float32, AUTOMATIC) DrvrTq_HwNwtMtr_T_f32;
	
	VAR(uint8, AUTOMATIC)   Index1_Cnt_T_u08= 0U;
	VAR(uint8, AUTOMATIC)   Index2_Cnt_T_u08= 0U;
	
	/*** Start of DriverTorque Selector ***/
	
	DriverTorquePrdt1_Uls_T_f32 = (MotTqCmdPwrLimd_MotNwtMtr_T_f32 * Rte_Prm_SysGlbPrmSysTqRat_Val() * (float32)AssiMechPolarity_Uls_T_s08);
	DriverTorquePrdt2_Uls_T_f32 = (HwAgCmp_HwDeg_T_f32 * ARCHGLBPRM_PIOVER180_ULS_F32);
	
	DrvrTorque_Uls_T_f32[0][0]             = DriverTorquePrdt1_Uls_T_f32;
	DrvrTorque_Uls_T_f32[1][0]             = HwTq_HwNwtMtr_T_f32;
	DrvrTorque_Uls_T_f32[IDX2_CNT_U08][0]  = DriverTorquePrdt2_Uls_T_f32;
	DrvrTorque_Uls_T_f32[IDX3_CNT_U08][0]  = HwVel_HwRadPerSec_T_f32;
	

	for (Index1_Cnt_T_u08=0U; Index1_Cnt_T_u08<IDX5_CNT_U08; Index1_Cnt_T_u08++)
	{
		for (Index2_Cnt_T_u08=0U; Index2_Cnt_T_u08<IDX4_CNT_U08; Index2_Cnt_T_u08++)
		{
			SumDrvrTorque1_Uls_T_f32[Index1_Cnt_T_u08]  += (PrmCtrldVelRtnDrvrTqMtrxB[Index1_Cnt_T_u08][Index2_Cnt_T_u08]) * DrvrTorque_Uls_T_f32[Index2_Cnt_T_u08][0];
		}
	}

	for (Index1_Cnt_T_u08=0U; Index1_Cnt_T_u08<IDX5_CNT_U08; Index1_Cnt_T_u08++)
	{
		for (Index2_Cnt_T_u08=0U; Index2_Cnt_T_u08<IDX5_CNT_U08; Index2_Cnt_T_u08++)
		{
			SumDrvrTorque2_Uls_T_f32[Index1_Cnt_T_u08]  += (PrmCtrldVelRtnDrvrTqMtrxA[Index1_Cnt_T_u08][Index2_Cnt_T_u08]) *  Rte_Pim_PrevDrvrTqMtrx()[Index2_Cnt_T_u08];
		}
	}	
	
	for (Index1_Cnt_T_u08=0U; Index1_Cnt_T_u08<IDX5_CNT_U08; Index1_Cnt_T_u08++)
	{
		SumDrvrTorqueTot_Uls_T_f32[Index1_Cnt_T_u08] = SumDrvrTorque1_Uls_T_f32[Index1_Cnt_T_u08] + SumDrvrTorque2_Uls_T_f32[Index1_Cnt_T_u08];
	}
	
	LimDyn1_Uls_T_f32 = Lim_f32(SumDrvrTorqueTot_Uls_T_f32[0],
								-DRVRTQOBSVRAGTHD_HWRAD_F32,
								DRVRTQOBSVRAGTHD_HWRAD_F32);
										
	LimDyn2_Uls_T_f32 = Lim_f32(SumDrvrTorqueTot_Uls_T_f32[1],
								-DRVRTQOBSVRVELTHD_HWRADPERSEC_F32,
							     DRVRTQOBSVRVELTHD_HWRADPERSEC_F32);
																			
	LimDyn3_Uls_T_f32 = Lim_f32(SumDrvrTorqueTot_Uls_T_f32[2],
								-DRVRTQOBSVRAGTHD_HWRAD_F32,
								DRVRTQOBSVRAGTHD_HWRAD_F32);									
																		
	LimDyn4_Uls_T_f32 = Lim_f32(SumDrvrTorqueTot_Uls_T_f32[3],
								-DRVRTQOBSVRVELTHD_HWRADPERSEC_F32,
								 DRVRTQOBSVRVELTHD_HWRADPERSEC_F32);									
																												
	LimDyn5_Uls_T_f32 = Lim_f32(SumDrvrTorqueTot_Uls_T_f32[4],
								-DRVRTQOBSVRTQTHD_HWNWTMTR_F32,
								DRVRTQOBSVRTQTHD_HWNWTMTR_F32);									
										
										
										
	Rte_Pim_PrevDrvrTqMtrx()[0] =  LimDyn1_Uls_T_f32;								
	Rte_Pim_PrevDrvrTqMtrx()[1] =	LimDyn2_Uls_T_f32;								
	Rte_Pim_PrevDrvrTqMtrx()[IDX2_CNT_U08] =	LimDyn3_Uls_T_f32;								
	Rte_Pim_PrevDrvrTqMtrx()[IDX3_CNT_U08] =	LimDyn4_Uls_T_f32;								
	Rte_Pim_PrevDrvrTqMtrx()[IDX4_CNT_U08] =	LimDyn5_Uls_T_f32;
	

	
	for (Index2_Cnt_T_u08=0U; Index2_Cnt_T_u08<IDX5_CNT_U08; Index2_Cnt_T_u08++)
	{
		SumDrvrTorque3_Uls_T_f32[0]  += (PrmCtrldVelRtnDrvrTqMtrxC[Index2_Cnt_T_u08]) * Rte_Pim_PrevDrvrTqMtrx()[Index2_Cnt_T_u08]; 
	}

	for (Index2_Cnt_T_u08=0U; Index2_Cnt_T_u08<IDX4_CNT_U08; Index2_Cnt_T_u08++)
	{
		SumDrvrTorque4_Uls_T_f32[0]  += (PrmCtrldVelRtnDrvrTqMtrxD[Index2_Cnt_T_u08]) * DrvrTorque_Uls_T_f32[Index2_Cnt_T_u08][0];
	}

	SumDrvrTorqueTot2_Uls_T_f32[0] = SumDrvrTorque3_Uls_T_f32[0]+ SumDrvrTorque4_Uls_T_f32[0];
   
    *Rte_Pim_dCtrldVelRtnDrvrTqEstimd() = SumDrvrTorqueTot2_Uls_T_f32[0];	
	
											
	if(TRUE == Rte_Prm_CtrldVelRtnDrvrTqEna_Logl())
	{
		DrvrTq_HwNwtMtr_T_f32 = SumDrvrTorqueTot2_Uls_T_f32[0];
	}
    else
	{
		DrvrTq_HwNwtMtr_T_f32 = HwTq_HwNwtMtr_T_f32;
	}	
	
	return (DrvrTq_HwNwtMtr_T_f32);
	 /*** End of DriverTorque Selector ***/
}	

/*****************************************************************************************************************************
* Name        :   Dampg
* Description :   Sub function to calculate Damping.
* Inputs      :   HwVel_HwDegPerSec_T_f32,CtrlSca_Uls_T_f32,VehSpd_Kph_T_u9p7.
* Returns     :   DampgTerm_HwNwtMtr_T_f32.
* Usage Notes :   This refers to "Damping" subsystem of FDD.
******************************************************************************************************************************/
 
 static FUNC(float32,CtrldVelRtn_CODE)Dampg(VAR(float32, AUTOMATIC)HwVel_HwDegPerSec_T_f32,
                                              VAR(float32, AUTOMATIC)CtrlSca_Uls_T_f32,
											  VAR(uint16, AUTOMATIC)VehSpd_Kph_T_u9p7)
															
{
	VAR(sint8,   AUTOMATIC) HwVel_HwDegPerSec_T_s08;
	VAR(uint16,  AUTOMATIC) HwVel_HwDegPerSec_T_u10p6;
	VAR(uint16,  AUTOMATIC) HwVel_HwDegPerSec_T_u6p10;
	VAR(float32,  AUTOMATIC) DampgTermPrdt1_HwNwtMtr_T_f32;
	VAR(float32,  AUTOMATIC) DampgTermPrdt2_HwNwtMtr_T_f32;
	VAR(float32,  AUTOMATIC) DampgTerm_HwNwtMtr_T_f32;
	
/*** Start of Damping ***/
    if(TRUE == Rte_Prm_CtrldVelRtnDampgEna_Logl())
   {
	    HwVel_HwDegPerSec_T_s08 =  Sign_s08_f32(HwVel_HwDegPerSec_T_f32);
	
	    HwVel_HwDegPerSec_T_u10p6 = FloatToFixd_u16_f32((Abslt_f32_f32(HwVel_HwDegPerSec_T_f32)),NXTRFIXDPT_FLOATTOP6_ULS_F32);
	
	    HwVel_HwDegPerSec_T_u6p10 =  BilnrIntrpnWithRound_u16_u16MplXu16MplY(VehSpd_Kph_T_u9p7,
																			HwVel_HwDegPerSec_T_u10p6,
																			PrmCtrldVelRtnVelSpdTbl_u9p7,
																			(uint16)TblSize_m(PrmCtrldVelRtnVelSpdTbl_u9p7),
																			Rte_Prm_CtrldVelRtnDampgX_Ary2D(),
																			Rte_Prm_CtrldVelRtnDampgY_Ary2D(),
																			(uint16)TblSize_m(PrmCtrldVelRtnDampgX_u10p6[0]));	
	
	    DampgTermPrdt1_HwNwtMtr_T_f32 = (FixdToFloat_f32_u16(HwVel_HwDegPerSec_T_u6p10,NXTRFIXDPT_P10TOFLOAT_ULS_F32)) * (float32) HwVel_HwDegPerSec_T_s08;
	
	    if(TRUE == Rte_Prm_CtrldVelRtnDampgScaEna_Logl())
	   {
		   DampgTermPrdt2_HwNwtMtr_T_f32 = CtrlSca_Uls_T_f32;
	   }
	   else
	   {
		   DampgTermPrdt2_HwNwtMtr_T_f32 = 1.0F;
	   }
	
	    DampgTerm_HwNwtMtr_T_f32 = DampgTermPrdt1_HwNwtMtr_T_f32 * DampgTermPrdt2_HwNwtMtr_T_f32;
    }
    else
    {
        DampgTerm_HwNwtMtr_T_f32 = DAMPGTERMZERO_KPH_F32;
	}

	
	*Rte_Pim_dCtrldVelRtnDampgCmd() = DampgTerm_HwNwtMtr_T_f32;
	
	return (DampgTerm_HwNwtMtr_T_f32);
	
	/*** End of Damping***/
	
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
