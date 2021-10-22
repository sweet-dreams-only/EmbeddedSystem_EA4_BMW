/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwHwAgArbnAndEotPosn.c
 *        Config:  C:/_S/work/ses_dev_ea4/CF071A_BmwHwAgArbnAndEotPosn_Impl-z172399/CF071A_BmwHwAgArbnAndEotPosn_Impl/tools/Component.dpa
 *     SW-C Type:  BmwHwAgArbnAndEotPosn
 *  Generated at:  Thu Jul 19 09:07:16 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwHwAgArbnAndEotPosn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2017-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwHwAgArbnAndEotPosn.c
 * Module Description: Implementation of BMW Handwheel Angle Arbitration And End of Travel Position
 * Project           : CBD
 * Author            : Krzysztof Byrski
 **********************************************************************************************************************
 * Version Control:
 * %version:          13 %
 * %derived_by:       z172399 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 10/25/17  1        KByrski   Initial version                                                               EA4#15659
 * 11/08/17  2        KByrski   Updated as per Design version 1.1.0, resolved issue with signal HwAgEotCcw    EA4#17094
 * 11/30/17  3        KByrski   Updated as per Design version 1.2.0                                           EA4#17435
 * 01/12/18  4        ML        Added Input/Output. Updated logic in Per1.                                    EA4#19235
 * 03/15/18  5        KByrski   Updated as per Design version 3.0.0                                           EA4#21692
 * 04/09/18  6        KByrski   Updated as per Design version 4.0.0                                           EA4#22410
 * 04/10/18  7        KByrski   Fix Design vs Implementation mismatch                                         EA4#22410
 * 06/29/18  8        BrykczyM  Updated as per the Design 5.1.0                                               EA4#24488
 * 07/06/18  9        SPP       Added PIM, added Timer in init, added Time Span, constant, NVM related logic. EA4#25770
 * 07/11/18 10        SPP       Added 2 inputs, changed state machine, new logic added.                       EA4#25684
 * 07/13/18 11        SPP       Added Display Variable, Removed PimPrev comparisons from Process functions    EA4#25992
 * 07/19/18 12        BrykczyM  The design 6.2.0, added limiting block and fixed the anomaly EA4#25997        EA4#26094
 * 07/25/18 13        BrykczyM  The design 6.3.0, added limiting block                                        EA4#26164
 *********************************************************************************************************************/
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
 * BmwMotAgSelnSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwPinionAgOffsSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwPinionAgQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwQuadOffsSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwRackToVehCentrOffsSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwSetVehCentrOffsSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwVehSpdSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NtcNr1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * NtcSts1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SigQlfr1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * s18p13
 *   sint32 represents integers with a minimum value of -2147483648 and a maximum 
 *      value of 2147483647. The order-relation on sint32 is: x < y if y - x is
 *      positive. sint32 has a lexical representation consisting of an optional sign 
 *      allowed by a finite-length sequence of decimal digits (#x30-#x39). If the 
 *      sign is omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12688778, +10000, 250098675.
 *
 *
 * Runnable Entities:
 * ==================
 * BmwHwAgArbnAndEotPosnInit1
 *   Function initialization
 *
 * BmwHwAgArbnAndEotPosnPer1
 *   Periodic functionality
 *
 *
 * Per-Instance Memory:
 * ====================
 * AllwExitFromInitTi
 *   Allow Exit From Initialization Time
 *
 * BmwRackCentrToVehCentrOffsSts
 *   BMW Rack Center To Vehicle Center Offset Status
 *
 * BmwVehCentrOffs
 *   BMW Vehicle Center Offsets
 *
 * ClrNotCmplPinionAgFlg
 *   Clear Not Complete Pinion Angle Flag
 *
 * CurrAlgndPinionAg
 *   Current Aligned Pinion Angle
 *
 * CurrDftPinionAgFltPrsnt
 *   Current Default Pinion Angle Fault Present
 *
 * FirstLoopIndcr
 *   This PIM is only needed for the purpose of catching first cycle of the periodic where BmwMotAgSelnSt stays in INIT. If it is equal to 0, then first loop is going, every other value is useless.
 *
 * KineIntegrityFlt
 *   Kinematic Integrity Fault Flag
 *
 * OffsCorrnRefTi
 *   Offset Correction Reference Time
 *
 * PinionAgConfRampStVari
 *   Pinion Angle Confidence Ramp First State Variable
 *
 * PinionAgFilStVari
 *   Pinion Angle Filter State Variable
 *
 * PinionAgFltRefTi
 *   Pinion Angle Fault Reference Time
 *
 * PrevAllwCorrn
 *   Previous Allow Correction
 *
 * PrevBmwMotAgSelnSt
 *   This is the state which we came from to the current state.
 *
 * PrevBmwOffsAuthy
 *   Previous BMW Offset Authority
 *
 * PrevBmwOffsAuthyFlg
 *   Previous BMW Offset Authority Flag
 *
 * PrevLoopBmwMotAgSelnSt
 *   This is the state which was calculated 2 ms ago, in the previous loop of the periodic function.
 *
 * PrevPinionAgConf
 *   Previous Pinion Angle Confidence
 *
 * SetBmwRackCentrToVehCentrOffsTrig
 *   Set BMW Rack Center To Vehicle Center Offset Trigger
 *
 * SigInvldTranTrig
 *   0 - DftHwPosn plus UntrimPinionAg AND !TurnsCntrVld, 1 -  UntrimPinionAg AND TurnsCntrVld
 *
 * VehCentrCmpl
 *   Vehicle Center Complete Flag
 *
 *********************************************************************************************************************/

#include "Rte_BmwHwAgArbnAndEotPosn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "BmwHwAgArbnAndEotPosn_Cfg.h"
#include "ArchGlbPrm.h"
#include "ElecGlbPrm.h"
#include "SysGlbPrm.h"
#include "NxtrFil.h"
#include "NxtrFixdPt.h"
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for Rte_Writes, Rte_Reads
                                              GetErrorStatus, SetRamBlockStatus, and SetNtcSts */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.2]: Server runnable is a void function; Rte generation adds standard return type but
                                              no error information is returned for GetTiSpan100MicroSec32bit, GetRefTmr100MicroSec32bit,
                                              and RstRackCentrMotRev */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define ALGNDPINIONAGHILIM_HWDEG_F32               (6000.0F)
#define ALGNDPINIONAGLOLIM_HWDEG_F32               (-6000.0F)
#define AUTHYTOL_ULS_F32                           (4e-05F)
#define BMWMOTAGSELNSTINVLD_CNT_U08                ((uint8)15U)
#define BMWMOTAGSELNSTOFFSCMPD_CNT_U08             ((uint8)2U)
#define BMWQUADROTOROFFSHILIM_MOTREV_S16           ((sint16)127)
#define BMWQUADROTOROFFSLOLIM_MOTREV_S16           ((sint16)(-127))
#define BMWQUADROTOROFFSPOLARITY_ULS_S08           ((sint8)(-1))
#define BMWRACKCENTRTOVEHCENTROFFSMAX_HWDEG_F32    (90.0F)
#define BMWRACKCENTRTOVEHCENTROFFSMIN_HWDEG_F32    (-90.0F)
#define CNVMILLISECTOCNT_CNTPERMILLISEC_U16        ((uint16)10U)
#define EOTCOEFF_ULS_F32                           (0.5F)
#define HWAGEOTCCWHILIM_HWDEG_F32                  (-360.0F)
#define HWAGEOTCCWLOLIM_HWDEG_F32                  (-900.0F)
#define HWAGEOTCWHILIM_HWDEG_F32                   (900.0F)
#define HWAGEOTCWLOLIM_HWDEG_F32                   (360.0F)
#define NEGPOLARITY_ULS_F32                        (-1.0F)
#define NODEBSTEP_CNT_U16                          ((uint16)65535U)
#define ONE_CNT_U08                                ((uint8)1U)
#define ONE_ULS_F32                                (1.0F)
#define PINIONAGCONFHILIM_ULS_F32                  (1.0F)
#define PINIONAGCONFLOLIM_ULS_F32                  (0.0F)
#define POSPOLARITY_ULS_F32                        (1.0F)
#define SIGQLFRFAILD_CNT_U08                       ((uint8)2U)
#define SIGQLFRPASSD_CNT_U08                       ((uint8)1U)
#define TURNCNTRCORRLNSTSVLD_CNT_U08               ((uint8)3U)
#define ZEROCONF_ULS_F32                           (0.0F)
#define ZEROMOTREV_MOTREV_S08                      ((sint8)0)
#define ZEROOFFS_HWDEG_F32                         (0.0F)

/********************************************* Local Function Prototypes *********************************************/
static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) HwAgSnsrNotTrimNTC(void);

static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) HwPosnFltDetn(
        VAR(boolean, AUTOMATIC) MotAgVld_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl);

static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) PinionAgFltTmr(
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl);

static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) OffsCorrnTmr(void);

static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) InitTmr(void);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnSt(
        VAR(boolean, AUTOMATIC) TurnCntrCorrlnStsCdn_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) PinionAgFltTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) OffsCorrnTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwExitFromInit_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStOffsCmpd(
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStSubVal(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStTmpCmpd(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStOffsCorrn(
        VAR(boolean, AUTOMATIC) OffsCorrnTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStSigInvld(
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) PinionAgFltTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStIni(
        VAR(boolean, AUTOMATIC) TurnCntrCorrlnStsCdn_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwExitFromInit_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwMotAgOffsSelnStTranCase(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl,
        VAR(float32, AUTOMATIC) MotAgTurnCntrDeg_MotDeg_T_f32,
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwMotAgSelnSt1, AUTOMATIC) PrevLoopBmwMotAgSelnSt_Cnt_T_enum,
        VAR(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        VAR(float32, AUTOMATIC) MotAgCumvAlgnMrf_MotDeg_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) PinionAgTarConf_Uls_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) MotPosnDegArbd_MotDeg_T_f32);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwMotAgSelnStOffsCmpd(
        VAR(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) PinionAgTarConf_Uls_T_f32);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwMotAgSelnStSigInvld(
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwMotAgSelnSt1, AUTOMATIC) PrevLoopBmwMotAgSelnSt_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl,
        VAR(float32, AUTOMATIC) MotAgTurnCntrDeg_MotDeg_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) PinionAgTarConf_Uls_T_f32);

static FUNC(float32, BmwHwAgArbnAndEotPosn_CODE) PinionAgCalc(
        VAR(float32, AUTOMATIC) OffsCpmpdMotPosn_MotDeg_T_f32,
        VAR(float32, AUTOMATIC) CmplncErrMotToPinion_HwDeg_T_f32);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrNotCmplPinionAgFlg(
        VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcEot(
        VAR(float32, AUTOMATIC) TotRackTrvl_HwDeg_T_f32,
        VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgEotCw_HwDeg_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgEotCcw_HwDeg_T_f32,
        P2VAR(boolean, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgCwDetd_Cnt_T_logl,
        P2VAR(boolean, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgCcwDetd_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) SetBmwRackCentrToVehCentrOffs(
        VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl,
        VAR(float32, AUTOMATIC) RackCentrPinionAg_HwDeg_T_f32);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) HndlgNTC(
        VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_logl,
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(BmwVehSpdSts1, AUTOMATIC) BmwVehSpdSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) DiKineIntegrityTest_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ChkNrcvrlFlt(
        CONST(SigQlfr1, AUTOMATIC) Ntc8CSts_Cnt_T_enum,
        CONST(SigQlfr1, AUTOMATIC) Ntc8ESts_Cnt_T_enum);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) TurnCntrCorrlnStsTmr(
        CONST(uint8, AUTOMATIC) TurnCntrCorrlnSts_Cnt_T_u08);

static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) ChkTurnCntrCorrlnStsCdn(
        CONST(uint8, AUTOMATIC) TurnCntrCorrlnSts_Cnt_T_u08);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ProcessBmwQuadOffsSts(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        P2VAR(boolean, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) ChgdValDetd_Cnt_T_logl);		
		
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ProcessBmwQuadRotorOffs1(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        VAR(boolean, AUTOMATIC) ChgdValDetd_Cnt_T_logl);
		
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ProcessBmwQuadRotorOffs2(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        VAR(boolean, AUTOMATIC) ChgdValDetd_Cnt_T_logl);

static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ActvtLpFil(void);

static FUNC(float32, BmwHwAgArbnAndEotPosn_CODE) CalcBmwPinionAgOffs(
        CONST(float32, AUTOMATIC) BmwPinionAgOffs_HwDeg_T_f32,
        CONST(BmwPinionAgOffsSts1, AUTOMATIC) BmwPinionAgOffsSts_Cnt_T_enum);

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
 * s18p13: Integer in interval [-2147483648...2147483647]
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwMotAgSelnSt1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWMOTAGSELNST_OFFSCMPD (2U)
 *   BMWMOTAGSELNST_SUBVAL (4U)
 *   BMWMOTAGSELNST_INI (8U)
 *   BMWMOTAGSELNST_TMPCMPD (10U)
 *   BMWMOTAGSELNST_OFFSCORRN (12U)
 *   BMWMOTAGSELNST_SIGINVLD (14U)
 *   BMWMOTAGSELNST_INVLD (15U)
 * BmwPinionAgOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWPINIONAGOFFSSTS_VLD (1U)
 *   BMWPINIONAGOFFSSTS_FCTIFNOTAVL (2U)
 *   BMWPINIONAGOFFSSTS_FCTRPRTERR (3U)
 *   BMWPINIONAGOFFSSTS_INVLD (4U)
 * BmwPinionAgQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWPINIONAGQLFR_SIGVALVLDANDPLAUS (1U)
 *   BMWPINIONAGQLFR_SIGVALVLD (2U)
 *   BMWPINIONAGQLFR_SUBVALSETINUSRSIG (4U)
 *   BMWPINIONAGQLFR_INIT (8U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY (9U)
 *   BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY (10U)
 *   BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG (12U)
 *   BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP (14U)
 *   BMWPINIONAGQLFR_INVLDSIG (15U)
 * BmwQuadOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWQUADOFFSSTS_ALGSLEEP (0U)
 *   BMWQUADOFFSSTS_OFFSKWN (1U)
 *   BMWQUADOFFSSTS_OFFSBYIDX (2U)
 *   BMWQUADOFFSSTS_OFFSBYMDLCOMP (3U)
 *   BMWQUADOFFSSTS_OFFSPOSNGBYSTRTSTOP (4U)
 *   BMWQUADOFFSSTS_OFFSPOSNGBYSUMCTRLAG (5U)
 *   BMWQUADOFFSSTS_OFFSINTEST (6U)
 *   BMWQUADOFFSSTS_CORROFFS (7U)
 *   BMWQUADOFFSSTS_ININ (8U)
 *   BMWQUADOFFSSTS_RSTOFFSKWN (9U)
 *   BMWQUADOFFSSTS_OFFSBYMDL (11U)
 *   BMWQUADOFFSSTS_INVLD (15U)
 * BmwRackToVehCentrOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRINVLD (0U)
 *   BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRLRND (1U)
 *   BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRUNLRND (2U)
 * BmwSetVehCentrOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHCENTROFFSSTS_OFFSPRFMD (0U)
 *   BMWVEHCENTROFFSSTS_OFFSFAILD (1U)
 *   BMWVEHCENTROFFSSTS_OFFSFAILDVALOUTOFRNG (2U)
 * BmwVehSpdSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHSPDSTS_VLD (1U)
 *   BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHSTANDG (4U)
 *   BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHRUNNG (12U)
 *   BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO (14U)
 *   BMWVEHSPDSTS_INVLD (15U)
 * NtcNr1: Enumeration of integer in interval [0...65535] with enumerators
 *   NTCNR_0X001 (1U)
 *   NTCNR_0X002 (2U)
 *   NTCNR_0X003 (3U)
 *   NTCNR_0X004 (4U)
 *   NTCNR_0X005 (5U)
 *   NTCNR_0X006 (6U)
 *   NTCNR_0X007 (7U)
 *   NTCNR_0X008 (8U)
 *   NTCNR_0X009 (9U)
 *   NTCNR_0X00A (10U)
 *   NTCNR_0X00B (11U)
 *   NTCNR_0X00C (12U)
 *   NTCNR_0X00D (13U)
 *   NTCNR_0X00E (14U)
 *   NTCNR_0X00F (15U)
 *   NTCNR_0X010 (16U)
 *   NTCNR_0X011 (17U)
 *   NTCNR_0X012 (18U)
 *   NTCNR_0X013 (19U)
 *   NTCNR_0X014 (20U)
 *   NTCNR_0X015 (21U)
 *   NTCNR_0X016 (22U)
 *   NTCNR_0X017 (23U)
 *   NTCNR_0X018 (24U)
 *   NTCNR_0X019 (25U)
 *   NTCNR_0X01A (26U)
 *   NTCNR_0X01B (27U)
 *   NTCNR_0X01C (28U)
 *   NTCNR_0X01D (29U)
 *   NTCNR_0X01E (30U)
 *   NTCNR_0X01F (31U)
 *   NTCNR_0X020 (32U)
 *   NTCNR_0X021 (33U)
 *   NTCNR_0X022 (34U)
 *   NTCNR_0X023 (35U)
 *   NTCNR_0X024 (36U)
 *   NTCNR_0X025 (37U)
 *   NTCNR_0X026 (38U)
 *   NTCNR_0X027 (39U)
 *   NTCNR_0X028 (40U)
 *   NTCNR_0X029 (41U)
 *   NTCNR_0X02A (42U)
 *   NTCNR_0X02B (43U)
 *   NTCNR_0X02C (44U)
 *   NTCNR_0X02D (45U)
 *   NTCNR_0X02E (46U)
 *   NTCNR_0X02F (47U)
 *   NTCNR_0X030 (48U)
 *   NTCNR_0X031 (49U)
 *   NTCNR_0X032 (50U)
 *   NTCNR_0X033 (51U)
 *   NTCNR_0X034 (52U)
 *   NTCNR_0X035 (53U)
 *   NTCNR_0X036 (54U)
 *   NTCNR_0X037 (55U)
 *   NTCNR_0X038 (56U)
 *   NTCNR_0X039 (57U)
 *   NTCNR_0X03A (58U)
 *   NTCNR_0X03B (59U)
 *   NTCNR_0X03C (60U)
 *   NTCNR_0X03D (61U)
 *   NTCNR_0X03E (62U)
 *   NTCNR_0X03F (63U)
 *   NTCNR_0X040 (64U)
 *   NTCNR_0X041 (65U)
 *   NTCNR_0X042 (66U)
 *   NTCNR_0X043 (67U)
 *   NTCNR_0X044 (68U)
 *   NTCNR_0X045 (69U)
 *   NTCNR_0X046 (70U)
 *   NTCNR_0X047 (71U)
 *   NTCNR_0X048 (72U)
 *   NTCNR_0X049 (73U)
 *   NTCNR_0X04A (74U)
 *   NTCNR_0X04B (75U)
 *   NTCNR_0X04C (76U)
 *   NTCNR_0X04D (77U)
 *   NTCNR_0X04E (78U)
 *   NTCNR_0X04F (79U)
 *   NTCNR_0X050 (80U)
 *   NTCNR_0X051 (81U)
 *   NTCNR_0X052 (82U)
 *   NTCNR_0X053 (83U)
 *   NTCNR_0X054 (84U)
 *   NTCNR_0X055 (85U)
 *   NTCNR_0X056 (86U)
 *   NTCNR_0X057 (87U)
 *   NTCNR_0X058 (88U)
 *   NTCNR_0X059 (89U)
 *   NTCNR_0X05A (90U)
 *   NTCNR_0X05B (91U)
 *   NTCNR_0X05C (92U)
 *   NTCNR_0X05D (93U)
 *   NTCNR_0X05E (94U)
 *   NTCNR_0X05F (95U)
 *   NTCNR_0X060 (96U)
 *   NTCNR_0X061 (97U)
 *   NTCNR_0X062 (98U)
 *   NTCNR_0X063 (99U)
 *   NTCNR_0X064 (100U)
 *   NTCNR_0X065 (101U)
 *   NTCNR_0X066 (102U)
 *   NTCNR_0X067 (103U)
 *   NTCNR_0X068 (104U)
 *   NTCNR_0X069 (105U)
 *   NTCNR_0X06A (106U)
 *   NTCNR_0X06B (107U)
 *   NTCNR_0X06C (108U)
 *   NTCNR_0X06D (109U)
 *   NTCNR_0X06E (110U)
 *   NTCNR_0X06F (111U)
 *   NTCNR_0X070 (112U)
 *   NTCNR_0X071 (113U)
 *   NTCNR_0X072 (114U)
 *   NTCNR_0X073 (115U)
 *   NTCNR_0X074 (116U)
 *   NTCNR_0X075 (117U)
 *   NTCNR_0X076 (118U)
 *   NTCNR_0X077 (119U)
 *   NTCNR_0X078 (120U)
 *   NTCNR_0X079 (121U)
 *   NTCNR_0X07A (122U)
 *   NTCNR_0X07B (123U)
 *   NTCNR_0X07C (124U)
 *   NTCNR_0X07D (125U)
 *   NTCNR_0X07E (126U)
 *   NTCNR_0X07F (127U)
 *   NTCNR_0X080 (128U)
 *   NTCNR_0X081 (129U)
 *   NTCNR_0X082 (130U)
 *   NTCNR_0X083 (131U)
 *   NTCNR_0X084 (132U)
 *   NTCNR_0X085 (133U)
 *   NTCNR_0X086 (134U)
 *   NTCNR_0X087 (135U)
 *   NTCNR_0X088 (136U)
 *   NTCNR_0X089 (137U)
 *   NTCNR_0X08A (138U)
 *   NTCNR_0X08B (139U)
 *   NTCNR_0X08C (140U)
 *   NTCNR_0X08D (141U)
 *   NTCNR_0X08E (142U)
 *   NTCNR_0X08F (143U)
 *   NTCNR_0X090 (144U)
 *   NTCNR_0X091 (145U)
 *   NTCNR_0X092 (146U)
 *   NTCNR_0X093 (147U)
 *   NTCNR_0X094 (148U)
 *   NTCNR_0X095 (149U)
 *   NTCNR_0X096 (150U)
 *   NTCNR_0X097 (151U)
 *   NTCNR_0X098 (152U)
 *   NTCNR_0X099 (153U)
 *   NTCNR_0X09A (154U)
 *   NTCNR_0X09B (155U)
 *   NTCNR_0X09C (156U)
 *   NTCNR_0X09D (157U)
 *   NTCNR_0X09E (158U)
 *   NTCNR_0X09F (159U)
 *   NTCNR_0X0A0 (160U)
 *   NTCNR_0X0A1 (161U)
 *   NTCNR_0X0A2 (162U)
 *   NTCNR_0X0A3 (163U)
 *   NTCNR_0X0A4 (164U)
 *   NTCNR_0X0A5 (165U)
 *   NTCNR_0X0A6 (166U)
 *   NTCNR_0X0A7 (167U)
 *   NTCNR_0X0A8 (168U)
 *   NTCNR_0X0A9 (169U)
 *   NTCNR_0X0AA (170U)
 *   NTCNR_0X0AB (171U)
 *   NTCNR_0X0AC (172U)
 *   NTCNR_0X0AD (173U)
 *   NTCNR_0X0AE (174U)
 *   NTCNR_0X0AF (175U)
 *   NTCNR_0X0B0 (176U)
 *   NTCNR_0X0B1 (177U)
 *   NTCNR_0X0B2 (178U)
 *   NTCNR_0X0B3 (179U)
 *   NTCNR_0X0B4 (180U)
 *   NTCNR_0X0B5 (181U)
 *   NTCNR_0X0B6 (182U)
 *   NTCNR_0X0B7 (183U)
 *   NTCNR_0X0B8 (184U)
 *   NTCNR_0X0B9 (185U)
 *   NTCNR_0X0BA (186U)
 *   NTCNR_0X0BB (187U)
 *   NTCNR_0X0BC (188U)
 *   NTCNR_0X0BD (189U)
 *   NTCNR_0X0BE (190U)
 *   NTCNR_0X0BF (191U)
 *   NTCNR_0X0C0 (192U)
 *   NTCNR_0X0C1 (193U)
 *   NTCNR_0X0C2 (194U)
 *   NTCNR_0X0C3 (195U)
 *   NTCNR_0X0C4 (196U)
 *   NTCNR_0X0C5 (197U)
 *   NTCNR_0X0C6 (198U)
 *   NTCNR_0X0C7 (199U)
 *   NTCNR_0X0C8 (200U)
 *   NTCNR_0X0C9 (201U)
 *   NTCNR_0X0CA (202U)
 *   NTCNR_0X0CB (203U)
 *   NTCNR_0X0CC (204U)
 *   NTCNR_0X0CD (205U)
 *   NTCNR_0X0CE (206U)
 *   NTCNR_0X0CF (207U)
 *   NTCNR_0X0D0 (208U)
 *   NTCNR_0X0D1 (209U)
 *   NTCNR_0X0D2 (210U)
 *   NTCNR_0X0D3 (211U)
 *   NTCNR_0X0D4 (212U)
 *   NTCNR_0X0D5 (213U)
 *   NTCNR_0X0D6 (214U)
 *   NTCNR_0X0D7 (215U)
 *   NTCNR_0X0D8 (216U)
 *   NTCNR_0X0D9 (217U)
 *   NTCNR_0X0DA (218U)
 *   NTCNR_0X0DB (219U)
 *   NTCNR_0X0DC (220U)
 *   NTCNR_0X0DD (221U)
 *   NTCNR_0X0DE (222U)
 *   NTCNR_0X0DF (223U)
 *   NTCNR_0X0E0 (224U)
 *   NTCNR_0X0E1 (225U)
 *   NTCNR_0X0E2 (226U)
 *   NTCNR_0X0E3 (227U)
 *   NTCNR_0X0E4 (228U)
 *   NTCNR_0X0E5 (229U)
 *   NTCNR_0X0E6 (230U)
 *   NTCNR_0X0E7 (231U)
 *   NTCNR_0X0E8 (232U)
 *   NTCNR_0X0E9 (233U)
 *   NTCNR_0X0EA (234U)
 *   NTCNR_0X0EB (235U)
 *   NTCNR_0X0EC (236U)
 *   NTCNR_0X0ED (237U)
 *   NTCNR_0X0EE (238U)
 *   NTCNR_0X0EF (239U)
 *   NTCNR_0X0F0 (240U)
 *   NTCNR_0X0F1 (241U)
 *   NTCNR_0X0F2 (242U)
 *   NTCNR_0X0F3 (243U)
 *   NTCNR_0X0F4 (244U)
 *   NTCNR_0X0F5 (245U)
 *   NTCNR_0X0F6 (246U)
 *   NTCNR_0X0F7 (247U)
 *   NTCNR_0X0F8 (248U)
 *   NTCNR_0X0F9 (249U)
 *   NTCNR_0X0FA (250U)
 *   NTCNR_0X0FB (251U)
 *   NTCNR_0X0FC (252U)
 *   NTCNR_0X0FD (253U)
 *   NTCNR_0X0FE (254U)
 *   NTCNR_0X0FF (255U)
 *   NTCNR_0X100 (256U)
 *   NTCNR_0X101 (257U)
 *   NTCNR_0X102 (258U)
 *   NTCNR_0X103 (259U)
 *   NTCNR_0X104 (260U)
 *   NTCNR_0X105 (261U)
 *   NTCNR_0X106 (262U)
 *   NTCNR_0X107 (263U)
 *   NTCNR_0X108 (264U)
 *   NTCNR_0X109 (265U)
 *   NTCNR_0X10A (266U)
 *   NTCNR_0X10B (267U)
 *   NTCNR_0X10C (268U)
 *   NTCNR_0X10D (269U)
 *   NTCNR_0X10E (270U)
 *   NTCNR_0X10F (271U)
 *   NTCNR_0X110 (272U)
 *   NTCNR_0X111 (273U)
 *   NTCNR_0X112 (274U)
 *   NTCNR_0X113 (275U)
 *   NTCNR_0X114 (276U)
 *   NTCNR_0X115 (277U)
 *   NTCNR_0X116 (278U)
 *   NTCNR_0X117 (279U)
 *   NTCNR_0X118 (280U)
 *   NTCNR_0X119 (281U)
 *   NTCNR_0X11A (282U)
 *   NTCNR_0X11B (283U)
 *   NTCNR_0X11C (284U)
 *   NTCNR_0X11D (285U)
 *   NTCNR_0X11E (286U)
 *   NTCNR_0X11F (287U)
 *   NTCNR_0X120 (288U)
 *   NTCNR_0X121 (289U)
 *   NTCNR_0X122 (290U)
 *   NTCNR_0X123 (291U)
 *   NTCNR_0X124 (292U)
 *   NTCNR_0X125 (293U)
 *   NTCNR_0X126 (294U)
 *   NTCNR_0X127 (295U)
 *   NTCNR_0X128 (296U)
 *   NTCNR_0X129 (297U)
 *   NTCNR_0X12A (298U)
 *   NTCNR_0X12B (299U)
 *   NTCNR_0X12C (300U)
 *   NTCNR_0X12D (301U)
 *   NTCNR_0X12E (302U)
 *   NTCNR_0X12F (303U)
 *   NTCNR_0X130 (304U)
 *   NTCNR_0X131 (305U)
 *   NTCNR_0X132 (306U)
 *   NTCNR_0X133 (307U)
 *   NTCNR_0X134 (308U)
 *   NTCNR_0X135 (309U)
 *   NTCNR_0X136 (310U)
 *   NTCNR_0X137 (311U)
 *   NTCNR_0X138 (312U)
 *   NTCNR_0X139 (313U)
 *   NTCNR_0X13A (314U)
 *   NTCNR_0X13B (315U)
 *   NTCNR_0X13C (316U)
 *   NTCNR_0X13D (317U)
 *   NTCNR_0X13E (318U)
 *   NTCNR_0X13F (319U)
 *   NTCNR_0X140 (320U)
 *   NTCNR_0X141 (321U)
 *   NTCNR_0X142 (322U)
 *   NTCNR_0X143 (323U)
 *   NTCNR_0X144 (324U)
 *   NTCNR_0X145 (325U)
 *   NTCNR_0X146 (326U)
 *   NTCNR_0X147 (327U)
 *   NTCNR_0X148 (328U)
 *   NTCNR_0X149 (329U)
 *   NTCNR_0X14A (330U)
 *   NTCNR_0X14B (331U)
 *   NTCNR_0X14C (332U)
 *   NTCNR_0X14D (333U)
 *   NTCNR_0X14E (334U)
 *   NTCNR_0X14F (335U)
 *   NTCNR_0X150 (336U)
 *   NTCNR_0X151 (337U)
 *   NTCNR_0X152 (338U)
 *   NTCNR_0X153 (339U)
 *   NTCNR_0X154 (340U)
 *   NTCNR_0X155 (341U)
 *   NTCNR_0X156 (342U)
 *   NTCNR_0X157 (343U)
 *   NTCNR_0X158 (344U)
 *   NTCNR_0X159 (345U)
 *   NTCNR_0X15A (346U)
 *   NTCNR_0X15B (347U)
 *   NTCNR_0X15C (348U)
 *   NTCNR_0X15D (349U)
 *   NTCNR_0X15E (350U)
 *   NTCNR_0X15F (351U)
 *   NTCNR_0X160 (352U)
 *   NTCNR_0X161 (353U)
 *   NTCNR_0X162 (354U)
 *   NTCNR_0X163 (355U)
 *   NTCNR_0X164 (356U)
 *   NTCNR_0X165 (357U)
 *   NTCNR_0X166 (358U)
 *   NTCNR_0X167 (359U)
 *   NTCNR_0X168 (360U)
 *   NTCNR_0X169 (361U)
 *   NTCNR_0X16A (362U)
 *   NTCNR_0X16B (363U)
 *   NTCNR_0X16C (364U)
 *   NTCNR_0X16D (365U)
 *   NTCNR_0X16E (366U)
 *   NTCNR_0X16F (367U)
 *   NTCNR_0X170 (368U)
 *   NTCNR_0X171 (369U)
 *   NTCNR_0X172 (370U)
 *   NTCNR_0X173 (371U)
 *   NTCNR_0X174 (372U)
 *   NTCNR_0X175 (373U)
 *   NTCNR_0X176 (374U)
 *   NTCNR_0X177 (375U)
 *   NTCNR_0X178 (376U)
 *   NTCNR_0X179 (377U)
 *   NTCNR_0X17A (378U)
 *   NTCNR_0X17B (379U)
 *   NTCNR_0X17C (380U)
 *   NTCNR_0X17D (381U)
 *   NTCNR_0X17E (382U)
 *   NTCNR_0X17F (383U)
 *   NTCNR_0X180 (384U)
 *   NTCNR_0X181 (385U)
 *   NTCNR_0X182 (386U)
 *   NTCNR_0X183 (387U)
 *   NTCNR_0X184 (388U)
 *   NTCNR_0X185 (389U)
 *   NTCNR_0X186 (390U)
 *   NTCNR_0X187 (391U)
 *   NTCNR_0X188 (392U)
 *   NTCNR_0X189 (393U)
 *   NTCNR_0X18A (394U)
 *   NTCNR_0X18B (395U)
 *   NTCNR_0X18C (396U)
 *   NTCNR_0X18D (397U)
 *   NTCNR_0X18E (398U)
 *   NTCNR_0X18F (399U)
 *   NTCNR_0X190 (400U)
 *   NTCNR_0X191 (401U)
 *   NTCNR_0X192 (402U)
 *   NTCNR_0X193 (403U)
 *   NTCNR_0X194 (404U)
 *   NTCNR_0X195 (405U)
 *   NTCNR_0X196 (406U)
 *   NTCNR_0X197 (407U)
 *   NTCNR_0X198 (408U)
 *   NTCNR_0X199 (409U)
 *   NTCNR_0X19A (410U)
 *   NTCNR_0X19B (411U)
 *   NTCNR_0X19C (412U)
 *   NTCNR_0X19D (413U)
 *   NTCNR_0X19E (414U)
 *   NTCNR_0X19F (415U)
 *   NTCNR_0X1A0 (416U)
 *   NTCNR_0X1A1 (417U)
 *   NTCNR_0X1A2 (418U)
 *   NTCNR_0X1A3 (419U)
 *   NTCNR_0X1A4 (420U)
 *   NTCNR_0X1A5 (421U)
 *   NTCNR_0X1A6 (422U)
 *   NTCNR_0X1A7 (423U)
 *   NTCNR_0X1A8 (424U)
 *   NTCNR_0X1A9 (425U)
 *   NTCNR_0X1AA (426U)
 *   NTCNR_0X1AB (427U)
 *   NTCNR_0X1AC (428U)
 *   NTCNR_0X1AD (429U)
 *   NTCNR_0X1AE (430U)
 *   NTCNR_0X1AF (431U)
 *   NTCNR_0X1B0 (432U)
 *   NTCNR_0X1B1 (433U)
 *   NTCNR_0X1B2 (434U)
 *   NTCNR_0X1B3 (435U)
 *   NTCNR_0X1B4 (436U)
 *   NTCNR_0X1B5 (437U)
 *   NTCNR_0X1B6 (438U)
 *   NTCNR_0X1B7 (439U)
 *   NTCNR_0X1B8 (440U)
 *   NTCNR_0X1B9 (441U)
 *   NTCNR_0X1BA (442U)
 *   NTCNR_0X1BB (443U)
 *   NTCNR_0X1BC (444U)
 *   NTCNR_0X1BD (445U)
 *   NTCNR_0X1BE (446U)
 *   NTCNR_0X1BF (447U)
 *   NTCNR_0X1C0 (448U)
 *   NTCNR_0X1C1 (449U)
 *   NTCNR_0X1C2 (450U)
 *   NTCNR_0X1C3 (451U)
 *   NTCNR_0X1C4 (452U)
 *   NTCNR_0X1C5 (453U)
 *   NTCNR_0X1C6 (454U)
 *   NTCNR_0X1C7 (455U)
 *   NTCNR_0X1C8 (456U)
 *   NTCNR_0X1C9 (457U)
 *   NTCNR_0X1CA (458U)
 *   NTCNR_0X1CB (459U)
 *   NTCNR_0X1CC (460U)
 *   NTCNR_0X1CD (461U)
 *   NTCNR_0X1CE (462U)
 *   NTCNR_0X1CF (463U)
 *   NTCNR_0X1D0 (464U)
 *   NTCNR_0X1D1 (465U)
 *   NTCNR_0X1D2 (466U)
 *   NTCNR_0X1D3 (467U)
 *   NTCNR_0X1D4 (468U)
 *   NTCNR_0X1D5 (469U)
 *   NTCNR_0X1D6 (470U)
 *   NTCNR_0X1D7 (471U)
 *   NTCNR_0X1D8 (472U)
 *   NTCNR_0X1D9 (473U)
 *   NTCNR_0X1DA (474U)
 *   NTCNR_0X1DB (475U)
 *   NTCNR_0X1DC (476U)
 *   NTCNR_0X1DD (477U)
 *   NTCNR_0X1DE (478U)
 *   NTCNR_0X1DF (479U)
 *   NTCNR_0X1E0 (480U)
 *   NTCNR_0X1E1 (481U)
 *   NTCNR_0X1E2 (482U)
 *   NTCNR_0X1E3 (483U)
 *   NTCNR_0X1E4 (484U)
 *   NTCNR_0X1E5 (485U)
 *   NTCNR_0X1E6 (486U)
 *   NTCNR_0X1E7 (487U)
 *   NTCNR_0X1E8 (488U)
 *   NTCNR_0X1E9 (489U)
 *   NTCNR_0X1EA (490U)
 *   NTCNR_0X1EB (491U)
 *   NTCNR_0X1EC (492U)
 *   NTCNR_0X1ED (493U)
 *   NTCNR_0X1EE (494U)
 *   NTCNR_0X1EF (495U)
 *   NTCNR_0X1F0 (496U)
 *   NTCNR_0X1F1 (497U)
 *   NTCNR_0X1F2 (498U)
 *   NTCNR_0X1F3 (499U)
 *   NTCNR_0X1F4 (500U)
 *   NTCNR_0X1F5 (501U)
 *   NTCNR_0X1F6 (502U)
 *   NTCNR_0X1F7 (503U)
 *   NTCNR_0X1F8 (504U)
 *   NTCNR_0X1F9 (505U)
 *   NTCNR_0X1FA (506U)
 *   NTCNR_0X1FB (507U)
 *   NTCNR_0X1FC (508U)
 *   NTCNR_0X1FD (509U)
 *   NTCNR_0X1FE (510U)
 *   NTCNR_0X1FF (511U)
 * NtcSts1: Enumeration of integer in interval [0...255] with enumerators
 *   NTCSTS_PASSD (0U)
 *   NTCSTS_FAILD (1U)
 *   NTCSTS_PREPASSD (2U)
 *   NTCSTS_PREFAILD (3U)
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
 * SigQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   SIGQLFR_NORES (0U)
 *   SIGQLFR_PASSD (1U)
 *   SIGQLFR_FAILD (2U)
 *
 * Record Types:
 * =============
 * BmwVehCentrOffsRec1: Record with elements
 *   BmwRackCentrToVehCentrOffs of type float32
 *   VehCentrOffs of type float32
 *   BmwPinionAgOffs of type float32
 *   BmwQuadRotorOffs of type sint8
 *   TurnCntrCorrlnSts of type uint8
 *   Ntc8CSts of type uint8
 *   Ntc8ESts of type uint8
 *   BmwMotAgSelnSt of type uint8
 *   LongTermVehCentrCmpl of type boolean
 *   RackCentrToVehCentrOffsVld of type boolean
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
 *   float32 *Rte_Pim_BmwPinionAgOffsRateLim(void)
 *   float32 *Rte_Pim_CurrAlgndPinionAg(void)
 *   float32 *Rte_Pim_PinionAgConfRampStVari(void)
 *   float32 *Rte_Pim_PrevBmwOffsAuthy(void)
 *   float32 *Rte_Pim_PrevLoopPinionAg(void)
 *   float32 *Rte_Pim_PrevPinionAgConf(void)
 *   uint32 *Rte_Pim_AllwExitFromInitTi(void)
 *   uint32 *Rte_Pim_MotPosnDegArbdBlndTi(void)
 *   uint32 *Rte_Pim_OffsCorrnRefTi(void)
 *   uint32 *Rte_Pim_PinionAgFltRefTi(void)
 *   uint32 *Rte_Pim_TurnCntrValTi(void)
 *   BmwRackToVehCentrOffsSts1 *Rte_Pim_BmwRackCentrToVehCentrOffsSts(void)
 *   uint8 *Rte_Pim_FirstLoopIndcr(void)
 *   uint8 *Rte_Pim_IniTurnCntrCorrlnSts(void)
 *   BmwMotAgSelnSt1 *Rte_Pim_PrevBmwMotAgSelnSt(void)
 *   uint8 *Rte_Pim_PrevIgnCycBmwMotAgSelnSt(void)
 *   uint8 *Rte_Pim_PrevIgnCycNtc8CSts(void)
 *   uint8 *Rte_Pim_PrevIgnCycNtc8ESts(void)
 *   uint8 *Rte_Pim_PrevIgnCycTurnCntrCorrlnSts(void)
 *   BmwMotAgSelnSt1 *Rte_Pim_PrevLoopBmwMotAgSelnSt(void)
 *   BmwQuadOffsSts1 *Rte_Pim_PrevLoopBmwQuadOffsSts(void)
 *   uint8 *Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt(void)
 *   boolean *Rte_Pim_ClrNotCmplPinionAgFlg(void)
 *   boolean *Rte_Pim_CurrDftPinionAgFltPrsnt(void)
 *   boolean *Rte_Pim_DynStabyCtrlCdn(void)
 *   boolean *Rte_Pim_KineIntegrityFlt(void)
 *   boolean *Rte_Pim_LpFilActvd(void)
 *   boolean *Rte_Pim_MotPosnDegArbdBlndFac(void)
 *   boolean *Rte_Pim_PrevAllwCorrn(void)
 *   boolean *Rte_Pim_PrevBmwOffsAuthyFlg(void)
 *   boolean *Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig(void)
 *   boolean *Rte_Pim_SigInvldTranTrig(void)
 *   boolean *Rte_Pim_TurnCntrCorrlnStsTmrTrig(void)
 *   boolean *Rte_Pim_VehCentrCmpl(void)
 *   BmwVehCentrOffsRec1 *Rte_Pim_BmwVehCentrOffs(void)
 *   FilLpRec1 *Rte_Pim_PinionAgFilStVari(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val(void)
 *   float32 Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val(void)
 *   float32 Rte_Prm_SysGlbPrmSysKineRat_Val(void)
 *   uint32 Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val(void)
 *   uint32 Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val(void)
 *   uint16 Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val(void)
 *   uint16 Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val(void)
 *   uint16 Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val(void)
 *   boolean Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl(void)
 *
 *********************************************************************************************************************/


#define BmwHwAgArbnAndEotPosn_START_SEC_CODE
#include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwAgArbnAndEotPosnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_BmwVehCentrOffs_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwAgArbnAndEotPosnInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwHwAgArbnAndEotPosnInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwAgArbnAndEotPosnInit1
 *********************************************************************************************************************/
    VAR(NvM_RequestResultType, AUTOMATIC) CentrOffsErrorStatus_Cnt_T_enum;

    /* PinionAgFil */
    FilLpInit(0.0F, Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val(), ARCHGLBPRM_2MILLISEC_SEC_F32, Rte_Pim_PinionAgFilStVari());

    (void) Rte_Call_BmwVehCentrOffs_GetErrorStatus(&CentrOffsErrorStatus_Cnt_T_enum);

    if (CentrOffsErrorStatus_Cnt_T_enum != NVM_REQ_OK)
    {
        /* NvmCorrupted */
        Rte_Pim_BmwVehCentrOffs()->BmwRackCentrToVehCentrOffs = ZEROOFFS_HWDEG_F32;
        Rte_Pim_BmwVehCentrOffs()->VehCentrOffs               = ZEROOFFS_HWDEG_F32;
        Rte_Pim_BmwVehCentrOffs()->BmwPinionAgOffs            = ZEROOFFS_HWDEG_F32;
        Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs           = ZEROMOTREV_MOTREV_S08;
        Rte_Pim_BmwVehCentrOffs()->TurnCntrCorrlnSts          = 0U;
        Rte_Pim_BmwVehCentrOffs()->Ntc8CSts                   = 0U;
        Rte_Pim_BmwVehCentrOffs()->Ntc8ESts                   = 0U;
        Rte_Pim_BmwVehCentrOffs()->BmwMotAgSelnSt             = BMWMOTAGSELNSTINVLD_CNT_U08;
        Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl       = FALSE;
        Rte_Pim_BmwVehCentrOffs()->RackCentrToVehCentrOffsVld = FALSE;

        *Rte_Pim_PrevIgnCycNtc8CSts()                          = 0U;
        *Rte_Pim_PrevIgnCycNtc8ESts()                          = 0U;
        *Rte_Pim_PrevIgnCycTurnCntrCorrlnSts()                 = 0U;
        *Rte_Pim_PrevIgnCycBmwMotAgSelnSt()                    = BMWMOTAGSELNSTINVLD_CNT_U08;
    }
    else
    {
        /* NvmOk */
        *Rte_Pim_PrevIgnCycTurnCntrCorrlnSts()                 = Rte_Pim_BmwVehCentrOffs()->TurnCntrCorrlnSts;
        *Rte_Pim_PrevIgnCycNtc8CSts()                          = Rte_Pim_BmwVehCentrOffs()->Ntc8CSts;
        *Rte_Pim_PrevIgnCycNtc8ESts()                          = Rte_Pim_BmwVehCentrOffs()->Ntc8ESts;
        *Rte_Pim_PrevIgnCycBmwMotAgSelnSt()                    = Rte_Pim_BmwVehCentrOffs()->BmwMotAgSelnSt;
    }

    *Rte_Pim_PrevBmwMotAgSelnSt()                              = BMWMOTAGSELNST_INI;
    *Rte_Pim_PrevLoopBmwMotAgSelnSt()                          = BMWMOTAGSELNST_INI;
    *Rte_Pim_BmwRackCentrToVehCentrOffsSts()                   = BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRUNLRND;
    *Rte_Pim_TurnCntrCorrlnStsTmrTrig()                        = TRUE;

	(void)Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_TurnCntrValTi());
	
    (void) Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(TRUE);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwHwAgArbnAndEotPosnPer1
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
 *   Std_ReturnType Rte_Read_BmwHwAgOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwPinionAgOffsSts_Val(BmwPinionAgOffsSts1 *data)
 *   Std_ReturnType Rte_Read_BmwQuadOffsSts_Val(BmwQuadOffsSts1 *data)
 *   Std_ReturnType Rte_Read_BmwQuadOffsStsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwQuadRotorOffs_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_BmwQuadRotorOffsVld_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_BmwVehSpdSts_Val(BmwVehSpdSts1 *data)
 *   Std_ReturnType Rte_Read_CmplncErrMotToPinion_Val(float32 *data)
 *   Std_ReturnType Rte_Read_DiKineIntegrityTest_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrf_Val(s18p13 *data)
 *   Std_ReturnType Rte_Read_MotAgMeclCorrlnSt_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_MotAgTurnCntr_Val(float32 *data)
 *   Std_ReturnType Rte_Read_RackCentrPinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TotRackTrvl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TurnCntrCorrlnSts_Val(uint8 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_VehSpdVld_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AlgndPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwRackCentrToVehCentrOffs_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwAgCcwDetd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwAgCwDetd_Logl(boolean data)
 *   Std_ReturnType Rte_Write_HwAgEotCcw_Val(float32 data)
 *   Std_ReturnType Rte_Write_HwAgEotCw_Val(float32 data)
 *   Std_ReturnType Rte_Write_LongTermVehCentrCmpl_Logl(boolean data)
 *   Std_ReturnType Rte_Write_OffsCmpdPinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAg_Val(float32 data)
 *   Std_ReturnType Rte_Write_PinionAgConf_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RstRackCentrMotRev_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwAgArbnAndEotPosnPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwHwAgArbnAndEotPosnPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwHwAgArbnAndEotPosnPer1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum;
    VAR(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08;
    VAR(BmwVehSpdSts1, AUTOMATIC) BmwVehSpdSts_Cnt_T_enum;
    VAR(float32, AUTOMATIC) CmplncErrMotToPinion_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) DiKineIntegrityTest_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl;
    VAR(s18p13,  AUTOMATIC) MotAgCumvAlgnMrf_MotDeg_T_s18p13;
    VAR(uint8,   AUTOMATIC) MotAgMeclCorrlnSt_Cnt_T_u08;
    VAR(float32, AUTOMATIC) MotAgTurnCntr_MotRev_T_f32;
    VAR(float32, AUTOMATIC) RackCentrPinionAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) TotRackTrvl_HwDeg_T_f32;
    VAR(uint8,   AUTOMATIC) TurnCntrCorrlnSts_Cnt_T_u08;
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
    VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_logl;
    VAR(float32, AUTOMATIC) BmwPinionAgOffs_HwDeg_T_f32;
    VAR(BmwPinionAgOffsSts1, AUTOMATIC) BmwPinionAgOffsSts_Cnt_T_enum;

    /* Outputs */
    VAR(float32, AUTOMATIC) BmwPinionAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) BmwRackCentrToVehCentrOffs_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) HwAgCcwDetd_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) HwAgCwDetd_Cnt_T_logl;
    VAR(float32, AUTOMATIC) HwAgEotCcw_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwAgEotCw_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) PinionAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) PinionAgConf_Uls_T_f32;
    VAR(float32, AUTOMATIC) OffsCmpdPinionAg_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) AlgndPinionAg_HwDeg_T_f32;

    /* Internals */
    VAR(BmwMotAgSelnSt1, AUTOMATIC) PrevLoopBmwMotAgSelnSt_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) PinionAgFltTmrElpd_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) OffsCorrnTmrElpd_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) AllwExitFromInit_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl;
    VAR(float32, AUTOMATIC) PinionAgTarConf_Uls_T_f32 = 0.0F;
    VAR(float32, AUTOMATIC) MotPosnDegArbd_MotDeg_T_f32 = 0.0F;
    VAR(float32, AUTOMATIC) Rate_Uls_T_f32;
    VAR(float32, AUTOMATIC) OffsCpmpdMotPosn_MotDeg_T_f32;
    VAR(float32, AUTOMATIC) MotAgCumvAlgnMrf_MotDeg_T_f32;
    VAR(SigQlfr1, AUTOMATIC) Ntc8CSts_Cnt_T_enum;
    VAR(SigQlfr1, AUTOMATIC) Ntc8ESts_Cnt_T_enum;
    VAR(boolean, AUTOMATIC) TurnCntrCorrlnStsCdn_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) NotFilDifTrig_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) BmwQuadOffStsVld_Cnt_logl;
    VAR(boolean, AUTOMATIC) BmwQuadRotorOffsVld_Cnt_logl;
	
    /* Read inputs */
    (void) Rte_Read_BmwQuadOffsSts_Val(&BmwQuadOffsSts_Cnt_T_enum);
    (void) Rte_Read_BmwQuadRotorOffs_Val(&BmwQuadRotorOffs_MotRev_T_s08);
    (void) Rte_Read_BmwVehSpdSts_Val(&BmwVehSpdSts_Cnt_T_enum);
    (void) Rte_Read_CmplncErrMotToPinion_Val(&CmplncErrMotToPinion_HwDeg_T_f32);
    (void) Rte_Read_DiKineIntegrityTest_Logl(&DiKineIntegrityTest_Cnt_T_logl);
    (void) Rte_Read_LongTermRackCentrCmpl_Logl(&LongTermRackCentrCmpl_Cnt_T_logl);
    (void) Rte_Read_MotAgCumvAlgndMrf_Val(&MotAgCumvAlgnMrf_MotDeg_T_s18p13);
    (void) Rte_Read_MotAgMeclCorrlnSt_Val(&MotAgMeclCorrlnSt_Cnt_T_u08);
    (void) Rte_Read_MotAgTurnCntr_Val(&MotAgTurnCntr_MotRev_T_f32);
    (void) Rte_Read_RackCentrPinionAg_Val(&RackCentrPinionAg_HwDeg_T_f32);
    (void) Rte_Read_TotRackTrvl_Val(&TotRackTrvl_HwDeg_T_f32);
    (void) Rte_Read_TurnCntrCorrlnSts_Val(&TurnCntrCorrlnSts_Cnt_T_u08);
    (void) Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
    (void) Rte_Read_VehSpdVld_Logl(&VehSpdVld_Cnt_T_logl);
    (void) Rte_Read_BmwPinionAgOffs_Val(&BmwPinionAgOffs_HwDeg_T_f32);
    (void) Rte_Read_BmwPinionAgOffsSts_Val(&BmwPinionAgOffsSts_Cnt_T_enum);
	(void) Rte_Read_BmwQuadOffsStsVld_Logl(&BmwQuadOffStsVld_Cnt_logl);
	(void) Rte_Read_BmwQuadRotorOffsVld_Logl(&BmwQuadRotorOffsVld_Cnt_logl);

    PrevLoopBmwMotAgSelnSt_Cnt_T_enum = *Rte_Pim_PrevLoopBmwMotAgSelnSt();

    /* HwAgSnsrNotTrimNTC */
    HwAgSnsrNotTrimFlt_Cnt_T_logl = HwAgSnsrNotTrimNTC();

    /* HwPosnFltDetn */
    HwAgNotVldFltPrsnt_Cnt_T_logl = HwPosnFltDetn(
            (MotAgMeclCorrlnSt_Cnt_T_u08 & 0x01U) == 0x01U ? TRUE : FALSE,
            HwAgSnsrNotTrimFlt_Cnt_T_logl);

    /* ChkNrcvrlFlt */
    (void) Rte_Call_GetNtcQlfrSts_Oper(NTCNR_0X08C, &Ntc8CSts_Cnt_T_enum);
    (void) Rte_Call_GetNtcQlfrSts_Oper(NTCNR_0X08E, &Ntc8ESts_Cnt_T_enum);

    /* IF_E */
    if (*Rte_Pim_FirstLoopIndcr() == 0U)
    {
        ChkNrcvrlFlt(Ntc8CSts_Cnt_T_enum, Ntc8ESts_Cnt_T_enum);
    }

    /* TurnCntrCorrlnStsTmr */
    TurnCntrCorrlnStsTmr(TurnCntrCorrlnSts_Cnt_T_u08);

    /* ChkTurnCntrCorrlnStsCdn */
    TurnCntrCorrlnStsCdn_Cnt_T_logl = ChkTurnCntrCorrlnStsCdn(TurnCntrCorrlnSts_Cnt_T_u08);


    /* PinionAgFltTmr */
    PinionAgFltTmrElpd_Cnt_T_logl = PinionAgFltTmr(HwAgSnsrNotTrimFlt_Cnt_T_logl);

    /* OffsCorrnTmr */
    OffsCorrnTmrElpd_Cnt_T_logl = OffsCorrnTmr();

    /* InitTmr */
    AllwExitFromInit_Cnt_T_logl = InitTmr();
	
	/* AllwTran */
	if ((BmwQuadOffStsVld_Cnt_logl == TRUE) && (BmwQuadRotorOffsVld_Cnt_logl == TRUE))
	{
		AllwTran_Cnt_T_logl = TRUE;
	}
	else 
	{
		AllwTran_Cnt_T_logl = FALSE;
	}

    /*** CalcBmwMotAgOffsSelnSt ***/
	  /* Call to State Machine */
    CalcBmwMotAgOffsSelnSt(
            TurnCntrCorrlnStsCdn_Cnt_T_logl,
            (TurnCntrCorrlnSts_Cnt_T_u08 & 0x01U) == 0x01U ? TRUE : FALSE,
            BmwQuadOffsSts_Cnt_T_enum,
            PinionAgFltTmrElpd_Cnt_T_logl,
            OffsCorrnTmrElpd_Cnt_T_logl,
            HwAgNotVldFltPrsnt_Cnt_T_logl,
            AllwExitFromInit_Cnt_T_logl,
			AllwTran_Cnt_T_logl);

    MotAgCumvAlgnMrf_MotDeg_T_f32 = FixdToFloat_f32_s32(MotAgCumvAlgnMrf_MotDeg_T_s18p13, NXTRFIXDPT_P13TOFLOAT_ULS_F32);

    /*** BmwMotAgOffsSelnStTranCase ***/
    BmwMotAgOffsSelnStTranCase(
            BmwQuadOffsSts_Cnt_T_enum,
            HwAgSnsrNotTrimFlt_Cnt_T_logl,
            MotAgTurnCntr_MotRev_T_f32 * ELECGLBPRM_DEGPERREV_DEGPERREV_F32,
            (TurnCntrCorrlnSts_Cnt_T_u08 & 0x01U) == 0x01U ? TRUE : FALSE,
            PrevLoopBmwMotAgSelnSt_Cnt_T_enum,
            (BmwQuadRotorOffs_MotRev_T_s08 * BMWQUADROTOROFFSPOLARITY_ULS_S08),
            MotAgCumvAlgnMrf_MotDeg_T_f32,
            &PinionAgTarConf_Uls_T_f32,
            &MotPosnDegArbd_MotDeg_T_f32);

    OffsCpmpdMotPosn_MotDeg_T_f32 = MotPosnDegArbd_MotDeg_T_f32 + ((float32) Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs * ELECGLBPRM_DEGPERREV_DEGPERREV_F32);

    /* PinionAgCalc */
    BmwPinionAg_HwDeg_T_f32 = PinionAgCalc(
            OffsCpmpdMotPosn_MotDeg_T_f32,
            CmplncErrMotToPinion_HwDeg_T_f32);

    /* IF_A */
    ActvtLpFil();

    /* IF_B */
    if(Abslt_f32_f32(BmwPinionAg_HwDeg_T_f32 - *Rte_Pim_PrevLoopPinionAg()) > Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val())
    {

        NotFilDifTrig_Cnt_T_logl = TRUE;
    }
    else
    {
        NotFilDifTrig_Cnt_T_logl = FALSE;
    }

    if ((*Rte_Pim_LpFilActvd() != FALSE) && (NotFilDifTrig_Cnt_T_logl != FALSE))
    {
        /* LpFilActvd */
        PinionAg_HwDeg_T_f32 = FilLpUpdOutp_f32(BmwPinionAg_HwDeg_T_f32, Rte_Pim_PinionAgFilStVari());
    }
    else
    {
        /* FilInactv */
        PinionAg_HwDeg_T_f32               = BmwPinionAg_HwDeg_T_f32;
        Rte_Pim_PinionAgFilStVari()->FilSt = BmwPinionAg_HwDeg_T_f32;
        *Rte_Pim_LpFilActvd()              = FALSE;

    }

    *Rte_Pim_PrevLoopPinionAg() = PinionAg_HwDeg_T_f32;

    /* CalcBmwPinionAgOffs */
    OffsCmpdPinionAg_HwDeg_T_f32 = CalcBmwPinionAgOffs(BmwPinionAgOffs_HwDeg_T_f32, BmwPinionAgOffsSts_Cnt_T_enum);

    /* LimStat_f1 */
    OffsCmpdPinionAg_HwDeg_T_f32 = Lim_f32(
            (PinionAg_HwDeg_T_f32 - OffsCmpdPinionAg_HwDeg_T_f32),
            SYSGLBPRM_HWAGLOLIM_HWDEG_F32,
            SYSGLBPRM_HWAGHILIM_HWDEG_F32);

    /* IF_C */
    if (NotFilDifTrig_Cnt_T_logl == FALSE)
    {
        /* Checking */
        if (PinionAgTarConf_Uls_T_f32 < *Rte_Pim_PrevPinionAgConf())
        {
            /* RampDown */
            Rate_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val();
        }
        else
        {
            /* RampUp */
            Rate_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val();
        }

        /* RateLimDyn_f32 */
        *Rte_Pim_PinionAgConfRampStVari() = Lim_f32(
                PinionAgTarConf_Uls_T_f32,
                *Rte_Pim_PinionAgConfRampStVari() - (Rate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32),
                *Rte_Pim_PinionAgConfRampStVari() + (Rate_Uls_T_f32 * ARCHGLBPRM_2MILLISEC_SEC_F32));
        *Rte_Pim_PrevPinionAgConf() = *Rte_Pim_PinionAgConfRampStVari();
    }
    else
    {
        /* HoldOrRamp*/
        if (PinionAgTarConf_Uls_T_f32 < *Rte_Pim_PrevPinionAgConf())
        {
            /* RampDown */
            /* RateLimDyn_f32 */
            *Rte_Pim_PinionAgConfRampStVari() = Lim_f32(
                    PinionAgTarConf_Uls_T_f32,
                    *Rte_Pim_PinionAgConfRampStVari() - (Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32),
                    *Rte_Pim_PinionAgConfRampStVari() + (Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32));
            *Rte_Pim_PrevPinionAgConf() = *Rte_Pim_PinionAgConfRampStVari();
        }
        else
        {
            /* Hold */
        }
    }

    /* ClrNotCmplPinionAgFlg */
    ClrNotCmplPinionAgFlg(
            LongTermRackCentrCmpl_Cnt_T_logl);

    /* CalcEot */
    CalcEot(
            TotRackTrvl_HwDeg_T_f32,
            LongTermRackCentrCmpl_Cnt_T_logl,
            &HwAgEotCw_HwDeg_T_f32,
            &HwAgEotCcw_HwDeg_T_f32,
            &HwAgCwDetd_Cnt_T_logl,
            &HwAgCcwDetd_Cnt_T_logl);

    /* IF_D */
    if (*Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() != FALSE)
    {
        /* SetBmwRackCentrToVehCentrOffs */
        SetBmwRackCentrToVehCentrOffs(
                LongTermRackCentrCmpl_Cnt_T_logl,
                RackCentrPinionAg_HwDeg_T_f32);
    }

    /* HndlgNTC */
    HndlgNTC(
            VehSpdVld_Cnt_T_logl,
            VehSpd_Kph_T_f32,
            BmwVehSpdSts_Cnt_T_enum,
            DiKineIntegrityTest_Cnt_T_logl);

    /* CalcBmwOffsAuthyFlg */
    *Rte_Pim_PrevBmwOffsAuthyFlg() =
            Abslt_f32_f32(*Rte_Pim_PrevBmwOffsAuthy() - Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val()) > AUTHYTOL_ULS_F32 ? TRUE : FALSE;

    /* Limit outputs */
    PinionAg_HwDeg_T_f32 = Lim_f32(
            PinionAg_HwDeg_T_f32,
            SYSGLBPRM_HWAGLOLIM_HWDEG_F32,
            SYSGLBPRM_HWAGHILIM_HWDEG_F32);
    BmwRackCentrToVehCentrOffs_HwDeg_T_f32 = Lim_f32(
            Rte_Pim_BmwVehCentrOffs()->BmwRackCentrToVehCentrOffs,
            SYSGLBPRM_HWAGLOLIM_HWDEG_F32,
            SYSGLBPRM_HWAGHILIM_HWDEG_F32);
    PinionAgConf_Uls_T_f32 = Lim_f32(
            *Rte_Pim_PrevPinionAgConf(),
            PINIONAGCONFLOLIM_ULS_F32,
            PINIONAGCONFHILIM_ULS_F32);
    AlgndPinionAg_HwDeg_T_f32 = Lim_f32(
            *Rte_Pim_CurrAlgndPinionAg(),
            SYSGLBPRM_HWAGLOLIM_HWDEG_F32,
            SYSGLBPRM_HWAGHILIM_HWDEG_F32);


    Rte_Pim_BmwVehCentrOffs()->TurnCntrCorrlnSts = (uint8) TurnCntrCorrlnSts_Cnt_T_u08;
    Rte_Pim_BmwVehCentrOffs()->BmwMotAgSelnSt    = (uint8) *Rte_Pim_PrevLoopBmwMotAgSelnSt();
	*Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() = (uint8) *Rte_Pim_PrevLoopBmwMotAgSelnSt();
    Rte_Pim_BmwVehCentrOffs()->Ntc8CSts          = Ntc8CSts_Cnt_T_enum;
    Rte_Pim_BmwVehCentrOffs()->Ntc8ESts          = Ntc8ESts_Cnt_T_enum;


    /* Write outputs */
    (void) Rte_Write_BmwPinionAg_Val(BmwPinionAg_HwDeg_T_f32);
    (void) Rte_Write_BmwPinionAgQlfr_Val((BmwPinionAgQlfr1) *Rte_Pim_PrevLoopBmwMotAgSelnSt());
    (void) Rte_Write_BmwRackCentrToVehCentrOffs_Val(BmwRackCentrToVehCentrOffs_HwDeg_T_f32);
    (void) Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(Rte_Pim_BmwVehCentrOffs()->RackCentrToVehCentrOffsVld);
    (void) Rte_Write_HwAgCcwDetd_Logl(HwAgCcwDetd_Cnt_T_logl);
    (void) Rte_Write_HwAgCwDetd_Logl(HwAgCwDetd_Cnt_T_logl);
    (void) Rte_Write_HwAgEotCcw_Val(HwAgEotCcw_HwDeg_T_f32);
    (void) Rte_Write_HwAgEotCw_Val(HwAgEotCw_HwDeg_T_f32);
    (void) Rte_Write_LongTermVehCentrCmpl_Logl(Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl);
    (void) Rte_Write_PinionAg_Val(PinionAg_HwDeg_T_f32);
    (void) Rte_Write_PinionAgConf_Val(PinionAgConf_Uls_T_f32);
    (void) Rte_Write_AlgndPinionAg_Val(AlgndPinionAg_HwDeg_T_f32);
    (void) Rte_Write_OffsCmpdPinionAg_Val(OffsCmpdPinionAg_HwDeg_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClrBmwRackCentrToVehCentrOffs_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ClrBmwRackCentrToVehCentrOffs>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ClrBmwRackCentrToVehCentrOffs_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClrBmwRackCentrToVehCentrOffs_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrBmwRackCentrToVehCentrOffs_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClrBmwRackCentrToVehCentrOffs_Oper
 *********************************************************************************************************************/

    Rte_Pim_BmwVehCentrOffs()->BmwRackCentrToVehCentrOffs = ZEROOFFS_HWDEG_F32;

    *Rte_Pim_BmwRackCentrToVehCentrOffsSts() = BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRUNLRND;

    Rte_Pim_BmwVehCentrOffs()->RackCentrToVehCentrOffsVld = FALSE;

    (void) Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(TRUE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClrVehCentrPosn_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <ClrVehCentrPosn>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ClrVehCentrPosn_Oper(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClrVehCentrPosn_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrVehCentrPosn_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClrVehCentrPosn_Oper
 *********************************************************************************************************************/

    Rte_Pim_BmwVehCentrOffs()->VehCentrOffs = ZEROOFFS_HWDEG_F32;
    Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl = FALSE;

    *Rte_Pim_VehCentrCmpl() = FALSE;

    (void) Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(TRUE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetVehCentrPosn_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <SetVehCentrPosn>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SetVehCentrPosn_Oper(BmwSetVehCentrOffsSts1 *BmwSetVehCentrOffsSts_Arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetVehCentrPosn_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwHwAgArbnAndEotPosn_CODE) SetVehCentrPosn_Oper(P2VAR(BmwSetVehCentrOffsSts1, AUTOMATIC, RTE_BMWHWAGARBNANDEOTPOSN_APPL_VAR) BmwSetVehCentrOffsSts_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SetVehCentrPosn_Oper
 *********************************************************************************************************************/

    VAR(float32, AUTOMATIC) BmwHwAgOffs_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) RawOffs_HwDeg_T_f32;

    (void) Rte_Read_BmwHwAgOffs_Val(&BmwHwAgOffs_HwDeg_T_f32);

    if ((Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl == FALSE) &&
        (*Rte_Pim_CurrDftPinionAgFltPrsnt() == FALSE) &&
        (*Rte_Pim_BmwRackCentrToVehCentrOffsSts() == BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRUNLRND))
    {
        /* CheckOffsets */
        RawOffs_HwDeg_T_f32 = *Rte_Pim_CurrAlgndPinionAg() - BmwHwAgOffs_HwDeg_T_f32;
        if (Abslt_f32_f32(RawOffs_HwDeg_T_f32) <= SYSGLBPRM_HWAGHILIM_HWDEG_F32)
        {
            /* UpdOffs */
            Rte_Pim_BmwVehCentrOffs()->VehCentrOffs = RawOffs_HwDeg_T_f32;
            Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl = TRUE;

            *Rte_Pim_VehCentrCmpl() = TRUE;
            *Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() = TRUE;

            *BmwSetVehCentrOffsSts_Arg = BMWVEHCENTROFFSSTS_OFFSPRFMD;

            (void) Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(TRUE);
        }
        else
        {
            /* OffsFaildValOutOfRng */
            *BmwSetVehCentrOffsSts_Arg = BMWVEHCENTROFFSSTS_OFFSFAILDVALOUTOFRNG;
        }
    }
    else
    {
        /* OffsFaild */
        *BmwSetVehCentrOffsSts_Arg = BMWVEHCENTROFFSSTS_OFFSFAILD;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwHwAgArbnAndEotPosn_STOP_SEC_CODE
#include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define BmwHwAgArbnAndEotPosn_START_SEC_CODE
#include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        HwAgSnsrNotTrimNTC
 * Description: Implementation of Simulink block HwAgSnsrNotTrimNTC
 * Inputs:      NONE
 * Outputs:     HwAgSnsrNotTrimFlt_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) HwAgSnsrNotTrimNTC(void)
{
    VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl;

    if ((Rte_Pim_BmwVehCentrOffs()->VehCentrOffs > SYSGLBPRM_HWAGHILIM_HWDEG_F32) ||
        (Rte_Pim_BmwVehCentrOffs()->VehCentrOffs < -SYSGLBPRM_HWAGHILIM_HWDEG_F32) ||
        (Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl == FALSE))
    {
        /* SetFaild */
        (void) Rte_Call_SetNtcSts_Oper(BMWHWAGARBNANDEOTPOSN_NTCHWAGSNSRNOTTRIM_CNT_ENUM, 0U, NTCSTS_FAILD, NODEBSTEP_CNT_U16);
        HwAgSnsrNotTrimFlt_Cnt_T_logl = TRUE;
    }
    else
    {
        /* SetPassd */
        (void) Rte_Call_SetNtcSts_Oper(BMWHWAGARBNANDEOTPOSN_NTCHWAGSNSRNOTTRIM_CNT_ENUM, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
        HwAgSnsrNotTrimFlt_Cnt_T_logl = FALSE;
    }

    return HwAgSnsrNotTrimFlt_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        HwPosnFltDetn
 * Description: Implementation of Simulink block HwPosnFltDetn
 * Inputs:      MotAgVld_Cnt_T_logl
 *              HwAgSnsrNotTrimFlt_Cnt_T_logl
 * Outputs:     Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) HwPosnFltDetn(
        VAR(boolean, AUTOMATIC) MotAgVld_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl;

    if ((MotAgVld_Cnt_T_logl == FALSE) ||
        (*Rte_Pim_KineIntegrityFlt() != FALSE))
    {
        /* FltPrsnt */
        *Rte_Pim_CurrDftPinionAgFltPrsnt() = TRUE;
    }
    else
    {
        /* FltNotPrsnt */
        *Rte_Pim_CurrDftPinionAgFltPrsnt() = FALSE;
    }

    if ((*Rte_Pim_CurrDftPinionAgFltPrsnt() != FALSE) || (HwAgSnsrNotTrimFlt_Cnt_T_logl != FALSE))
    {
        /* SetFlt */
        HwAgNotVldFltPrsnt_Cnt_T_logl = TRUE;
    }
    else
    {
        /* RstFlt */
        HwAgNotVldFltPrsnt_Cnt_T_logl = FALSE;
    }

    return HwAgNotVldFltPrsnt_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        PinionAgFltTmr
 * Description: Implementation of Simulink block PinionAgFltTmr
 * Inputs:      Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgSnsrNotTrimFlt_Cnt_T_logl
 *              Rte_Pim_PrevLoopBmwMotAgSelnSt
 * Outputs:     PinionAgFltTmrElpd_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) PinionAgFltTmr(
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) PinionAgFltTmrElpd_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if ((*Rte_Pim_CurrDftPinionAgFltPrsnt() == FALSE) &&
        (HwAgSnsrNotTrimFlt_Cnt_T_logl == FALSE) &&
        (*Rte_Pim_PrevLoopBmwMotAgSelnSt() == BMWMOTAGSELNST_SIGINVLD))
    {
        /* SpanTi */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_PinionAgFltRefTi(), &TiSpan_Cnt_T_u32);
        if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* SetTrue */
            PinionAgFltTmrElpd_Cnt_T_logl = TRUE;
        }
        else
        {
            /* SetFalse */
            PinionAgFltTmrElpd_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* RefTi */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_PinionAgFltRefTi());
        PinionAgFltTmrElpd_Cnt_T_logl = FALSE;
    }

    return PinionAgFltTmrElpd_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        OffsCorrnTmr
 * Description: Implementation of Simulink block OffsCorrnTmr
 * Inputs:      Rte_Pim_PrevLoopBmwMotAgSelnSt
 * Outputs:     OffsCorrnTmrElpd_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) OffsCorrnTmr(void)
{
    VAR(boolean, AUTOMATIC) OffsCorrnTmrElpd_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (*Rte_Pim_PrevLoopBmwMotAgSelnSt() == BMWMOTAGSELNST_OFFSCORRN)
    {
        /* SpanTi */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_OffsCorrnRefTi(), &TiSpan_Cnt_T_u32);
        if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /* SetTrue */
            OffsCorrnTmrElpd_Cnt_T_logl = TRUE;
        }
        else
        {
            /* SetFalse */
            OffsCorrnTmrElpd_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* RefTi */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_OffsCorrnRefTi());
        OffsCorrnTmrElpd_Cnt_T_logl = FALSE;
    }

    return OffsCorrnTmrElpd_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        InitTmr
 * Description: Implementation of Simulink block InitTmr
 * Inputs:      Rte_Pim_PrevLoopBmwMotAgSelnSt
 * Outputs:     AllwExitFromInit_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) InitTmr(void)
{
    VAR(boolean, AUTOMATIC) AllwExitFromInit_Cnt_T_logl;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (*Rte_Pim_PrevLoopBmwMotAgSelnSt() == BMWMOTAGSELNST_INI)
    {
        /* SpanTi */
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_AllwExitFromInitTi(), &TiSpan_Cnt_T_u32);
        if (TiSpan_Cnt_T_u32 >= ((uint32) Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val() * (uint32) CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            AllwExitFromInit_Cnt_T_logl = TRUE;
        }
        else
        {
            AllwExitFromInit_Cnt_T_logl = FALSE;
        }
    }
    else
    {
        /* RefTi */
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_AllwExitFromInitTi());
        AllwExitFromInit_Cnt_T_logl = FALSE;
    }

    return AllwExitFromInit_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        CalcBmwMotAgOffsSelnSt
 * Description: Implementation of Simulink stateflow CalcBmwMotAgOffsSelnSt
 * Inputs:      TurnCntrCorrlnStsCdn_Cnt_T_logl
 *              TurnCntrVld_Cnt_T_logl
 *              BmwQuadOffsSts_Cnt_T_enum
 *              PinionAgFltTmrElpd_Cnt_T_logl
 *              Rte_Pim_VehCentrCmpl
 *              OffsCorrnTmrElpd_Cnt_T_logl
 *              Rte_Pim_PrevAllwCorrn
 *              Rte_Pim_PrevBmwOffsAuthyFlg
 *              Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 *              AllwExitFromInit_Cnt_T_logl
 *				AllwTran_Cnt_T_logl
 * Outputs:     Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwMotAgSelnSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnSt(
        VAR(boolean, AUTOMATIC) TurnCntrCorrlnStsCdn_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) PinionAgFltTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) OffsCorrnTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwExitFromInit_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl)
{
    if (*Rte_Pim_FirstLoopIndcr() == 0U)
    {
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_INI;
    }
    else
    {
        switch (*Rte_Pim_PrevLoopBmwMotAgSelnSt())
        {
            case BMWMOTAGSELNST_OFFSCMPD:
            {
                /* OFFSET_COMPENSATED */
                CalcBmwMotAgOffsSelnStOffsCmpd(
                        TurnCntrVld_Cnt_T_logl,
                        BmwQuadOffsSts_Cnt_T_enum,
                        HwAgNotVldFltPrsnt_Cnt_T_logl,
						AllwTran_Cnt_T_logl);
            }
            break;

            case BMWMOTAGSELNST_SUBVAL:
            {
                /* SUBSTITUTE_VALUE */
                CalcBmwMotAgOffsSelnStSubVal(
                        BmwQuadOffsSts_Cnt_T_enum,
                        HwAgNotVldFltPrsnt_Cnt_T_logl,
						AllwTran_Cnt_T_logl);
            }
            break;

            case BMWMOTAGSELNST_TMPCMPD:
            {
                /* TEMPORARY_COMPENSATED */
                CalcBmwMotAgOffsSelnStTmpCmpd(
                        BmwQuadOffsSts_Cnt_T_enum,
                        HwAgNotVldFltPrsnt_Cnt_T_logl,
						AllwTran_Cnt_T_logl);
            }
            break;

            case BMWMOTAGSELNST_OFFSCORRN:
            {
                /* OFFSET_CORRECTION */
                CalcBmwMotAgOffsSelnStOffsCorrn(
                        OffsCorrnTmrElpd_Cnt_T_logl,
                        HwAgNotVldFltPrsnt_Cnt_T_logl,
						AllwTran_Cnt_T_logl);
            }
            break;

            case BMWMOTAGSELNST_SIGINVLD:
            {
                /* SIGNAL_INVALID */
                CalcBmwMotAgOffsSelnStSigInvld(
                        TurnCntrVld_Cnt_T_logl,
                        PinionAgFltTmrElpd_Cnt_T_logl,
                        HwAgNotVldFltPrsnt_Cnt_T_logl,
						AllwTran_Cnt_T_logl);
            }
            break;

            default: /* BMWMOTAGSELNST_INI */
            {
                /* INIT */
                CalcBmwMotAgOffsSelnStIni(
                        TurnCntrCorrlnStsCdn_Cnt_T_logl,
                        HwAgNotVldFltPrsnt_Cnt_T_logl,
                        AllwExitFromInit_Cnt_T_logl,
						AllwTran_Cnt_T_logl);
            }
            break;
        }
    }

    *Rte_Pim_FirstLoopIndcr() = ((uint8) *Rte_Pim_PrevLoopBmwMotAgSelnSt()) + 1U;
}

/**********************************************************************************************************************
 * Name:        CalcBmwMotAgOffsSelnStOffsCmpd
 * Description: Transitions from state OFFSET_COMPENSATED
 * Inputs:      TurnCntrVld_Cnt_T_logl
 *              BmwQuadOffsSts_Cnt_T_enum
 *              Rte_Pim_PrevAllwCorrn
 *              Rte_Pim_PrevBmwOffsAuthyFlg
 *              Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 *				AllwTran_Cnt_T_logl
 * Outputs:     Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwMotAgSelnSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStOffsCmpd(
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl)
{
    if ((AllwTran_Cnt_T_logl != FALSE) &&
	    ((*Rte_Pim_CurrDftPinionAgFltPrsnt() != FALSE) ||
        (HwAgNotVldFltPrsnt_Cnt_T_logl != FALSE) ||
        ((*Rte_Pim_PrevBmwOffsAuthyFlg() != FALSE) && (TurnCntrVld_Cnt_T_logl == FALSE))))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCMPD;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_SIGINVLD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
	         (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_CORROFFS) && 
			 (*Rte_Pim_PrevAllwCorrn() != FALSE))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCMPD;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCORRN;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        CalcBmwMotAgOffsSelnStSubVal
 * Description: Transitions from state SUBSTITUTE_VALUE
 * Inputs:      BmwQuadOffsSts_Cnt_T_enum
 *              Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 *				AllwTran_Cnt_T_logl
 * Outputs:     Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwMotAgSelnSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStSubVal(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl)
{
    if ((AllwTran_Cnt_T_logl != FALSE) &&
	    ((*Rte_Pim_CurrDftPinionAgFltPrsnt() != FALSE) || (HwAgNotVldFltPrsnt_Cnt_T_logl != FALSE)))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_SUBVAL;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_SIGINVLD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
	         ((BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDLCOMP) ||
              (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSTRTSTOP) ||
              (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSUMCTRLAG)))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_SUBVAL;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCMPD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
	         (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDL))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_SUBVAL;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_TMPCMPD;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        CalcBmwMotAgOffsSelnStTmpCmpd
 * Description: Transitions from state TEMPORARY_COMPENSATED
 * Inputs:      BmwQuadOffsSts_Cnt_T_enum
 *              Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 *				AllwTran_Cnt_T_logl
 * Outputs:     Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwMotAgSelnSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStTmpCmpd(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl)
{
    if ((AllwTran_Cnt_T_logl != FALSE) &&
	    ((*Rte_Pim_CurrDftPinionAgFltPrsnt() != FALSE) || (HwAgNotVldFltPrsnt_Cnt_T_logl != FALSE)))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_TMPCMPD;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_SIGINVLD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
	         ((BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDLCOMP) ||
              (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSTRTSTOP) ||
              (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSUMCTRLAG)))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_TMPCMPD;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCMPD;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        CalcBmwMotAgOffsSelnStOffsCorrn
 * Description: Transitions from state OFFSET_CORRECTION
 * Inputs:      OffsCorrnTmrElpd_Cnt_T_logl
 *              Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 *				AllwTran_Cnt_T_logl
 * Outputs:     Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwMotAgSelnSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStOffsCorrn(
        VAR(boolean, AUTOMATIC) OffsCorrnTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl)
{
    if ((AllwTran_Cnt_T_logl != FALSE) &&
	    ((*Rte_Pim_CurrDftPinionAgFltPrsnt() != FALSE) || (HwAgNotVldFltPrsnt_Cnt_T_logl != FALSE)))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCORRN;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_SIGINVLD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) && (OffsCorrnTmrElpd_Cnt_T_logl != FALSE))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCORRN;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCMPD;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        CalcBmwMotAgOffsSelnStSigInvld
 * Description: Transitions from state SIGNAL_INVALID
 * Inputs:      TurnCntrVld_Cnt_T_logl
 *              PinionAgFltTmrElpd_Cnt_T_logl
 *              Rte_Pim_VehCentrCmpl
 *              Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 *				AllwTran_Cnt_T_logl
 * Outputs:     Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwMotAgSelnSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStSigInvld(
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) PinionAgFltTmrElpd_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl)
{
    if ((AllwTran_Cnt_T_logl != FALSE) &&
	    ((TurnCntrVld_Cnt_T_logl != FALSE) || (*Rte_Pim_VehCentrCmpl() != FALSE)) &&
        (*Rte_Pim_CurrDftPinionAgFltPrsnt() == FALSE) &&
        (HwAgNotVldFltPrsnt_Cnt_T_logl == FALSE) &&
        (PinionAgFltTmrElpd_Cnt_T_logl != FALSE))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_SIGINVLD;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCMPD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
	         (*Rte_Pim_VehCentrCmpl() == FALSE) &&
             (TurnCntrVld_Cnt_T_logl == FALSE) &&
             (*Rte_Pim_CurrDftPinionAgFltPrsnt() == FALSE) &&
             (HwAgNotVldFltPrsnt_Cnt_T_logl == FALSE) &&
             (PinionAgFltTmrElpd_Cnt_T_logl != FALSE))
    {
        *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_SIGINVLD;
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_SUBVAL;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        CalcBmwMotAgOffsSelnStIni
 * Description: Transitions from state INIT
 * Inputs:      TurnCntrCorrlnStsCdn_Cnt_T_logl
 *              Rte_Pim_CurrDftPinionAgFltPrsnt
 *              HwAgNotVldFltPrsnt_Cnt_T_logl
 *				AllwTran_Cnt_T_logl
 * Outputs:     Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwMotAgSelnSt
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcBmwMotAgOffsSelnStIni(
        VAR(boolean, AUTOMATIC) TurnCntrCorrlnStsCdn_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) HwAgNotVldFltPrsnt_Cnt_T_logl,
        VAR(boolean, AUTOMATIC) AllwExitFromInit_Cnt_T_logl,
		VAR(boolean, AUTOMATIC) AllwTran_Cnt_T_logl)
{
    *Rte_Pim_PrevBmwMotAgSelnSt() = BMWMOTAGSELNST_INI;

    if ((AllwTran_Cnt_T_logl != FALSE) &&
	    ((*Rte_Pim_CurrDftPinionAgFltPrsnt() != FALSE) ||
              (HwAgNotVldFltPrsnt_Cnt_T_logl != FALSE)) &&
        (AllwExitFromInit_Cnt_T_logl != FALSE))
    {
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_SIGINVLD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
	         (TurnCntrCorrlnStsCdn_Cnt_T_logl != FALSE)&& 
			 (AllwExitFromInit_Cnt_T_logl != FALSE))
    {
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_OFFSCMPD;
    }
    else if ((AllwTran_Cnt_T_logl != FALSE) &&
	         (TurnCntrCorrlnStsCdn_Cnt_T_logl == FALSE)&& 
			 (AllwExitFromInit_Cnt_T_logl != FALSE))
    {
        *Rte_Pim_PrevLoopBmwMotAgSelnSt() = BMWMOTAGSELNST_SUBVAL;
    }
    else
    {
        /* Do nothing */
    }
}

/**********************************************************************************************************************
 * Name:        BmwMotAgOffsSelnStTranCase
 * Description: Implementation of Simulink block BmwMotAgOffsSelnStTranCase
 * Inputs:      Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              Rte_Pim_MotPosnDegArbdBlndTi
 *              Rte_Pim_MotPosnDegArbdBlndFac
 *              BmwQuadOffsSts_Cnt_T_enum
 *              HwAgSnsrNotTrimFlt_Cnt_T_logl
 *              MotAgTurnCntrDeg_MotDeg_T_f32
 *              TurnCntrVld_Cnt_T_logl
 *              PrevLoopBmwMotAgSelnSt_Cnt_T_enum
 *              Rte_Pim_PrevBmwMotAgSelnSt
 *              BmwQuadRotorOffs_MotRev_T_s08
 *              MotAgCumvAlgnMrf_MotDeg_T_f32
 * Outputs:     PinionAgTarConf_Uls_T_f32
 *              MotPosnDegArbd_MotDeg_T_f32
 *              Rte_Pim_PrevBmwOffsAuthy
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwMotAgOffsSelnStTranCase(
        VAR(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl,
        VAR(float32, AUTOMATIC) MotAgTurnCntrDeg_MotDeg_T_f32,
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwMotAgSelnSt1, AUTOMATIC) PrevLoopBmwMotAgSelnSt_Cnt_T_enum,
        VAR(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        VAR(float32, AUTOMATIC) MotAgCumvAlgnMrf_MotDeg_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) PinionAgTarConf_Uls_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) MotPosnDegArbd_MotDeg_T_f32)
{

    VAR(float32, AUTOMATIC) Fac_Uls_T_f32;
    VAR(uint32, AUTOMATIC)  TiSpan_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) ChgdValDetd_Cnt_T_logl;

    switch(*Rte_Pim_PrevLoopBmwMotAgSelnSt())
    {
        case BMWMOTAGSELNST_OFFSCMPD:
        {
            /* BmwMotAgSelnStOffsCmpd */
            BmwMotAgSelnStOffsCmpd(
                    BmwQuadRotorOffs_MotRev_T_s08,
                    PinionAgTarConf_Uls_T_f32);
        }
        break;

        case BMWMOTAGSELNST_SUBVAL:
        {
            /* BmwMotAgSelnStSubVal */
            *PinionAgTarConf_Uls_T_f32 = ZEROCONF_ULS_F32;
            if (PrevLoopBmwMotAgSelnSt_Cnt_T_enum == BMWMOTAGSELNST_INI)
            {
                /* SetFlg */
                *Rte_Pim_ClrNotCmplPinionAgFlg() = TRUE;
            }
        }
        break;

        case BMWMOTAGSELNST_INI:
        {
            /* BmwMotAgSelnStIni */
            *PinionAgTarConf_Uls_T_f32 = ZEROCONF_ULS_F32;
        }
        break;

        case BMWMOTAGSELNST_TMPCMPD:
        {
            /* BmwMotAgSelnStTmpCmpd */
            *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
            *Rte_Pim_PrevBmwOffsAuthy() = Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
        }
        break;

        case BMWMOTAGSELNST_OFFSCORRN:
        {
            /* BmwMotAgSelnStOffsCorrn */
            *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
            *Rte_Pim_PrevBmwOffsAuthy() = Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
        }
        break;

        default: /* BMWMOTAGSELNST_SIGINVLD */
        {
            /*** BmwMotAgSelnStSigInvld ***/
            BmwMotAgSelnStSigInvld(
                    TurnCntrVld_Cnt_T_logl,
                    PrevLoopBmwMotAgSelnSt_Cnt_T_enum,
                    HwAgSnsrNotTrimFlt_Cnt_T_logl,
                    MotAgTurnCntrDeg_MotDeg_T_f32,
                    PinionAgTarConf_Uls_T_f32);
        }
        break;
    }


    if (TurnCntrVld_Cnt_T_logl != FALSE)
    {
        /* CalculateDifference */
        if (*Rte_Pim_MotPosnDegArbdBlndFac() == FALSE)
        {
            /* CalculateFactor */
            (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_MotPosnDegArbdBlndTi(), &TiSpan_Cnt_T_u32);

            Fac_Uls_T_f32 = (float32) TiSpan_Cnt_T_u32
                    / (((float32)(uint32)Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val()) * ((float32)(uint32)CNVMILLISECTOCNT_CNTPERMILLISEC_U16));

            Fac_Uls_T_f32 = Lim_f32(
                    Fac_Uls_T_f32,
                    ZEROCONF_ULS_F32,
                    ONE_ULS_F32);
        }
        else
        {
            /* FactorEqualsOne */
            Fac_Uls_T_f32 = ONE_ULS_F32;
        }

        *MotPosnDegArbd_MotDeg_T_f32 = Blnd_f32(
                MotAgCumvAlgnMrf_MotDeg_T_f32,
                MotAgTurnCntrDeg_MotDeg_T_f32,
                Fac_Uls_T_f32);

        *Rte_Pim_MotPosnDegArbdBlndFac() = (Abslt_f32_f32(ONE_ULS_F32 - Fac_Uls_T_f32) <= ARCHGLBPRM_FLOATZEROTHD_ULS_F32) ? TRUE : FALSE;


    }
    else
    {
        /* Passthrough */
        *MotPosnDegArbd_MotDeg_T_f32 = MotAgCumvAlgnMrf_MotDeg_T_f32;
        (void) Rte_Call_GetRefTmr100MicroSec32bit_Oper(Rte_Pim_MotPosnDegArbdBlndTi());
        *Rte_Pim_MotPosnDegArbdBlndFac() = FALSE;
    }


    if ((BmwQuadOffsSts_Cnt_T_enum != BMWQUADOFFSSTS_CORROFFS ) && (BmwQuadOffsSts_Cnt_T_enum != BMWQUADOFFSSTS_INVLD))
    {
        /* SetTrue */
        *Rte_Pim_PrevAllwCorrn() = TRUE;
    }
    else
    {
        /* CheckTransition */
        if (*Rte_Pim_PrevLoopBmwMotAgSelnSt() == BMWMOTAGSELNST_OFFSCMPD)
        {
            /* KeepChecking */
            if (*Rte_Pim_PrevBmwMotAgSelnSt() == BMWMOTAGSELNST_OFFSCORRN)
            {
                /* SetFalse */
                *Rte_Pim_PrevAllwCorrn() = FALSE;
            }
            else
            {
                /* SetTrue */
                *Rte_Pim_PrevAllwCorrn() = TRUE;
            }
        }
        else
        {
            /* DoNothing */
        }
    }

    ProcessBmwQuadOffsSts(BmwQuadOffsSts_Cnt_T_enum,
	                      &ChgdValDetd_Cnt_T_logl);
						  
    ProcessBmwQuadRotorOffs1(BmwQuadOffsSts_Cnt_T_enum,
	                         BmwQuadRotorOffs_MotRev_T_s08,
	                         ChgdValDetd_Cnt_T_logl);
							
	ProcessBmwQuadRotorOffs2(BmwQuadOffsSts_Cnt_T_enum,
	                         BmwQuadRotorOffs_MotRev_T_s08,
	                         ChgdValDetd_Cnt_T_logl);						

}

/**********************************************************************************************************************
 * Name:        BmwMotAgSelnStOffsCmpd
 * Description: Implementation of Simulink block BmwMotAgSelnStOffsCmpd
 * Inputs:      Rte_Pim_PrevBmwMotAgSelnSt
 *              Rte_Pim_PrevBmwOffsAuthy
 *              BmwQuadRotorOffs_MotRev_T_s08
 * Outputs:     PinionAgTarConf_Uls_T_f32
 *              Rte_Pim_PrevBmwOffsAuthy
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwMotAgSelnStOffsCmpd(
        VAR(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) PinionAgTarConf_Uls_T_f32)
{
    switch(*Rte_Pim_PrevBmwMotAgSelnSt())
    {
        case BMWMOTAGSELNST_SUBVAL:
        {
            /* SetSigSubVal */
            *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
            *Rte_Pim_PrevBmwOffsAuthy() = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();

        }
        break;

        case BMWMOTAGSELNST_INI:
        {
            /* SetSigIni */
            *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
        }
        break;

        case BMWMOTAGSELNST_TMPCMPD:
        {
            /* SetSigTmpCmpd */
            *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
            *Rte_Pim_PrevBmwOffsAuthy() = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();

        }
        break;

        case BMWMOTAGSELNST_OFFSCORRN:
        {
            /* SetSigOffsCorrn */
            *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
            *Rte_Pim_PrevBmwOffsAuthy() = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
        }
        break;

        default:
        {
            /* SetSigInvld */
            if (*Rte_Pim_VehCentrCmpl() != FALSE)
            {
                /* VehCentrCmplTrue */
                *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
                *Rte_Pim_PrevBmwOffsAuthy() = Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
            }
            else
            {
                /* VehCentrCmplFalse */
                *PinionAgTarConf_Uls_T_f32 = Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
            }
        }
        break;
    }
}

/**********************************************************************************************************************
 * Name:        BmwMotAgSelnStSigInvld
 * Description: Implementation of Simulink block BmwMotAgSelnStSigInvld
 * Inputs:      TurnCntrVld_Cnt_T_logl
 *              PrevLoopBmwMotAgSelnSt_Cnt_T_enum
 *              HwAgSnsrNotTrimFlt_Cnt_T_logl
 *              MotAgTurnCntrDeg_MotDeg_T_f32
 * Outputs:     PinionAgTarConf_Uls_T_f32
 *              Rte_Pim_PrevBmwOffsAuthy
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) BmwMotAgSelnStSigInvld(
        VAR(boolean, AUTOMATIC) TurnCntrVld_Cnt_T_logl,
        VAR(BmwMotAgSelnSt1, AUTOMATIC) PrevLoopBmwMotAgSelnSt_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) HwAgSnsrNotTrimFlt_Cnt_T_logl,
        VAR(float32, AUTOMATIC) MotAgTurnCntrDeg_MotDeg_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) PinionAgTarConf_Uls_T_f32)
{
    *PinionAgTarConf_Uls_T_f32 = ZEROCONF_ULS_F32;
    *Rte_Pim_PrevBmwOffsAuthy() = ZEROCONF_ULS_F32;

    if (PrevLoopBmwMotAgSelnSt_Cnt_T_enum != BMWMOTAGSELNST_SIGINVLD)
    {
        /*** CheckTransReason ***/
        if (HwAgSnsrNotTrimFlt_Cnt_T_logl != FALSE)
        {
            /*** UntrimPinionAg ***/
            if (TurnCntrVld_Cnt_T_logl != FALSE)
            {
                /* SetTrue - Do Nothing if True */
            }
            else
            {   /* If NOT True */
                /*** SetFalse ***/
                if (PrevLoopBmwMotAgSelnSt_Cnt_T_enum == BMWMOTAGSELNST_INI)
                {
                    /* SetTrue */
                    *Rte_Pim_ClrNotCmplPinionAgFlg() = TRUE;
                }
                else
                {
                    /* SetFalse */
                    *Rte_Pim_ClrNotCmplPinionAgFlg() = FALSE;
                }
            }
        }
        else
        {
            /* DftHwPosn */
            *Rte_Pim_ClrNotCmplPinionAgFlg() = TRUE;
        }
    }
}

/**********************************************************************************************************************
 * Name:        PinionAgCalc
 * Description: Implementation of Simulink block PinionAgCalc
 * Inputs:      OffsCpmpdMotPosn_MotDeg_T_f32
 *              CmplncErrMotToPinion_HwDeg_T_f32
 * Outputs:     BmwPinionAg_HwDeg_T_f32
 *              Rte_Pim_CurrAlgndPinionAg
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, BmwHwAgArbnAndEotPosn_CODE) PinionAgCalc(
        VAR(float32, AUTOMATIC) OffsCpmpdMotPosn_MotDeg_T_f32,
        VAR(float32, AUTOMATIC) CmplncErrMotToPinion_HwDeg_T_f32)
{
    VAR(float32, AUTOMATIC) Polarity_Uls_T_f32;
    VAR(float32, AUTOMATIC) BmwPinionAg_HwDeg_T_f32;

    if (Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl() != FALSE)
    {
        /* SetPos */
        Polarity_Uls_T_f32 = POSPOLARITY_ULS_F32;
    }
    else
    {
        /* SetNeg */
        Polarity_Uls_T_f32 = NEGPOLARITY_ULS_F32;
    }

    *Rte_Pim_CurrAlgndPinionAg() = Lim_f32(
            (((OffsCpmpdMotPosn_MotDeg_T_f32 * Polarity_Uls_T_f32) / Rte_Prm_SysGlbPrmSysKineRat_Val()) - CmplncErrMotToPinion_HwDeg_T_f32) * Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val(),
            ALGNDPINIONAGLOLIM_HWDEG_F32,
            ALGNDPINIONAGHILIM_HWDEG_F32);

    BmwPinionAg_HwDeg_T_f32 = Lim_f32(
            *Rte_Pim_CurrAlgndPinionAg() - Rte_Pim_BmwVehCentrOffs()->VehCentrOffs,
            SYSGLBPRM_HWAGLOLIM_HWDEG_F32,
            SYSGLBPRM_HWAGHILIM_HWDEG_F32);

    return BmwPinionAg_HwDeg_T_f32;
}

/**********************************************************************************************************************
 * Name:        ClrNotCmplPinionAgFlg
 * Description: Implementation of Simulink block ClrNotCmplPinionAgFlg
 * Inputs:      LongTermRackCentrCmpl_Cnt_T_logl
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ClrNotCmplPinionAgFlg(
        VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl)
{
    if ((*Rte_Pim_BmwRackCentrToVehCentrOffsSts() == BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRUNLRND) &&
        (LongTermRackCentrCmpl_Cnt_T_logl != Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl) &&
        (*Rte_Pim_ClrNotCmplPinionAgFlg() != FALSE))
    {
        /* ClrFlg */
        *Rte_Pim_ClrNotCmplPinionAgFlg() = FALSE;
        *Rte_Pim_VehCentrCmpl() = FALSE;
        Rte_Pim_BmwVehCentrOffs()->VehCentrOffs = ZEROOFFS_HWDEG_F32;
        Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl = FALSE;

        (void) Rte_Call_RstRackCentrMotRev_Oper();
    }
}

/**********************************************************************************************************************
 * Name:        CalcEot
 * Description: Implementation of Simulink block CalcEot
 * Inputs:      TotRackTrvl_HwDeg_T_f32
 *              LongTermRackCentrCmpl_Cnt_T_logl
 * Outputs:     HwAgEotCw_HwDeg_T_f32
 *              HwAgEotCcw_HwDeg_T_f32
 *              HwAgCwDetd_Cnt_T_logl
 *              HwAgCcwDetd_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) CalcEot(
        VAR(float32, AUTOMATIC) TotRackTrvl_HwDeg_T_f32,
        VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgEotCw_HwDeg_T_f32,
        P2VAR(float32, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgEotCcw_HwDeg_T_f32,
        P2VAR(boolean, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgCwDetd_Cnt_T_logl,
        P2VAR(boolean, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) HwAgCcwDetd_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) AndRes_Cnt_T_logl;

    if ((Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl != FALSE) &&
        (LongTermRackCentrCmpl_Cnt_T_logl != FALSE))
    {
        AndRes_Cnt_T_logl = TRUE;
    }
    else
    {
        AndRes_Cnt_T_logl = FALSE;
    }

    *HwAgEotCcw_HwDeg_T_f32 = Lim_f32(
            Rte_Pim_BmwVehCentrOffs()->BmwRackCentrToVehCentrOffs - (TotRackTrvl_HwDeg_T_f32 * EOTCOEFF_ULS_F32),
            HWAGEOTCCWLOLIM_HWDEG_F32,
            HWAGEOTCCWHILIM_HWDEG_F32);
    *HwAgEotCw_HwDeg_T_f32 = Lim_f32(
            Rte_Pim_BmwVehCentrOffs()->BmwRackCentrToVehCentrOffs + (TotRackTrvl_HwDeg_T_f32 * EOTCOEFF_ULS_F32),
            HWAGEOTCWLOLIM_HWDEG_F32,
            HWAGEOTCWHILIM_HWDEG_F32);

    if ((*HwAgEotCcw_HwDeg_T_f32 < Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val()) &&
        (*HwAgEotCcw_HwDeg_T_f32 > Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val()) &&
        (AndRes_Cnt_T_logl != FALSE) &&
        (Rte_Pim_BmwVehCentrOffs()->RackCentrToVehCentrOffsVld != FALSE))
    {
        *HwAgCcwDetd_Cnt_T_logl = TRUE;
    }
    else
    {
        *HwAgCcwDetd_Cnt_T_logl = FALSE;
    }

    if ((*HwAgEotCw_HwDeg_T_f32 < Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val()) &&
        (*HwAgEotCw_HwDeg_T_f32 > Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val()) &&
        (AndRes_Cnt_T_logl != FALSE) &&
        (Rte_Pim_BmwVehCentrOffs()->RackCentrToVehCentrOffsVld != FALSE))
    {
        *HwAgCwDetd_Cnt_T_logl = TRUE;
    }
    else
    {
        *HwAgCwDetd_Cnt_T_logl = FALSE;
    }
}

/**********************************************************************************************************************
 * Name:        SetBmwRackCentrToVehCentrOffs
 * Description: Implementation of Simulink block SetBmwRackCentrToVehCentrOffs
 * Inputs:      LongTermRackCentrCmpl_Cnt_T_logl
 *              RackCentrPinionAg_HwDeg_T_f32
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) SetBmwRackCentrToVehCentrOffs(
        VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl,
        VAR(float32, AUTOMATIC) RackCentrPinionAg_HwDeg_T_f32)
{
    VAR(float32, AUTOMATIC) BmwRackCentrToVehCentrOffs_HwDeg_T_f32;
    VAR(boolean, AUTOMATIC) BmwRackCentrToVehCentrOffsVld_Cnt_T_logl;

    if ((LongTermRackCentrCmpl_Cnt_T_logl != FALSE) &&
        (Rte_Pim_BmwVehCentrOffs()->LongTermVehCentrCmpl != FALSE))
    {
        /* CalcBmwRackCentrToVehCentrOffs */
        BmwRackCentrToVehCentrOffs_HwDeg_T_f32 = RackCentrPinionAg_HwDeg_T_f32 - Rte_Pim_BmwVehCentrOffs()->VehCentrOffs;

        if ((BmwRackCentrToVehCentrOffs_HwDeg_T_f32 >= BMWRACKCENTRTOVEHCENTROFFSMIN_HWDEG_F32) &&
            (BmwRackCentrToVehCentrOffs_HwDeg_T_f32 <= BMWRACKCENTRTOVEHCENTROFFSMAX_HWDEG_F32))
        {
            /* StsLrnd */
            BmwRackCentrToVehCentrOffsVld_Cnt_T_logl = TRUE;
            *Rte_Pim_BmwRackCentrToVehCentrOffsSts() = BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRLRND;
        }
        else
        {
            /* StsInvld */
            BmwRackCentrToVehCentrOffsVld_Cnt_T_logl = FALSE;
            *Rte_Pim_BmwRackCentrToVehCentrOffsSts() = BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRINVLD;
        }

        /* ResetFlagLearnValue */
        if (BmwRackCentrToVehCentrOffsVld_Cnt_T_logl != FALSE)
        {
            *Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() = FALSE;

            Rte_Pim_BmwVehCentrOffs()->BmwRackCentrToVehCentrOffs = Lim_f32(
                    BmwRackCentrToVehCentrOffs_HwDeg_T_f32,
                    BMWRACKCENTRTOVEHCENTROFFSMIN_HWDEG_F32,
                    BMWRACKCENTRTOVEHCENTROFFSMAX_HWDEG_F32);
            Rte_Pim_BmwVehCentrOffs()->RackCentrToVehCentrOffsVld = TRUE;

        }
    }
}

/**********************************************************************************************************************
 * Name:        HndlgNTC
 * Description: Implementation of Simulink block HndlgNTC
 * Inputs:      Rte_Pim_CurrAlgndPinionAg
 *              VehSpdVld_Cnt_T_logl
 *              VehSpd_Kph_T_f32
 *              Rte_Pim_PrevLoopBmwMotAgSelnSt
 *              BmwVehSpdSts_Cnt_T_enum
 *              DiKineIntegrityTest_Cnt_T_logl
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) HndlgNTC(
        VAR(boolean, AUTOMATIC) VehSpdVld_Cnt_T_logl,
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(BmwVehSpdSts1, AUTOMATIC) BmwVehSpdSts_Cnt_T_enum,
        VAR(boolean, AUTOMATIC) DiKineIntegrityTest_Cnt_T_logl)
{
    /* LossOfPinionAgNTC */
    switch (*Rte_Pim_PrevLoopBmwMotAgSelnSt())
    {
        case BMWMOTAGSELNST_SUBVAL:
        case BMWMOTAGSELNST_SIGINVLD:
        {
            /* KeepChecking */
            (void) Rte_Call_SetNtcSts_Oper(BMWHWAGARBNANDEOTPOSN_NTCLOSSOFPINIOINAGZEROSPD_CNT_ENUM, 0U, NTCSTS_FAILD, NODEBSTEP_CNT_U16);

            if ((BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHRUNNG) ||
                (BmwVehSpdSts_Cnt_T_enum == BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO) ||
                ((VehSpd_Kph_T_f32 > Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val()) && (VehSpdVld_Cnt_T_logl != FALSE)))
            {
                (void) Rte_Call_SetNtcSts_Oper(BMWHWAGARBNANDEOTPOSN_NTCLOSSOFPINIONAG_CNT_ENUM, 0U, NTCSTS_FAILD, NODEBSTEP_CNT_U16);
            }
            else
            {
                (void) Rte_Call_SetNtcSts_Oper(BMWHWAGARBNANDEOTPOSN_NTCLOSSOFPINIONAG_CNT_ENUM, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
            }
        }
        break;

        default:
        {
           /* SetToPassd */
            (void) Rte_Call_SetNtcSts_Oper(BMWHWAGARBNANDEOTPOSN_NTCLOSSOFPINIONAG_CNT_ENUM, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
            (void) Rte_Call_SetNtcSts_Oper(BMWHWAGARBNANDEOTPOSN_NTCLOSSOFPINIOINAGZEROSPD_CNT_ENUM, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
        }
        break;
    }

    /* KineIntegrityDiagc */
    if (DiKineIntegrityTest_Cnt_T_logl == FALSE)
    {
        /* HndlgNTC */
        if (Abslt_f32_f32(*Rte_Pim_CurrAlgndPinionAg()) > Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val())
        {
            /* SetFaild */
            (void) Rte_Call_SetNtcSts_Oper(NTCNR_0X0A1, 0U, NTCSTS_FAILD, NODEBSTEP_CNT_U16);
            *Rte_Pim_KineIntegrityFlt() = TRUE;
        }
        else
        {
            /* SetPassd */
            (void) Rte_Call_SetNtcSts_Oper(NTCNR_0X0A1, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
            *Rte_Pim_KineIntegrityFlt() = FALSE;
        }
    }
}

/**********************************************************************************************************************
 * Name:        ChkNrcvrlFlt
 * Description: The implementation of Simulink block ChkNrcvrlFlt
 * Inputs:      Ntc8CSts_Cnt_T_enum
 *              Ntc8ESts_Cnt_T_enum
 *              *Rte_Pim_PrevIgnCycNtc8CSts()
 *              *Rte_Pim_PrevIgnCycNtc8ESts()
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ChkNrcvrlFlt(
        CONST(SigQlfr1, AUTOMATIC) Ntc8CSts_Cnt_T_enum,
        CONST(SigQlfr1, AUTOMATIC) Ntc8ESts_Cnt_T_enum)
{


    if (  ((*Rte_Pim_PrevIgnCycNtc8CSts() == SIGQLFRPASSD_CNT_U08) && (Ntc8CSts_Cnt_T_enum == SIGQLFRFAILD_CNT_U08))
       || ((*Rte_Pim_PrevIgnCycNtc8CSts() == SIGQLFRFAILD_CNT_U08) && (Ntc8CSts_Cnt_T_enum == SIGQLFRPASSD_CNT_U08))
       || ((*Rte_Pim_PrevIgnCycNtc8ESts() == SIGQLFRPASSD_CNT_U08) && (Ntc8ESts_Cnt_T_enum == SIGQLFRFAILD_CNT_U08))
       || ((*Rte_Pim_PrevIgnCycNtc8ESts() == SIGQLFRFAILD_CNT_U08) && (Ntc8ESts_Cnt_T_enum == SIGQLFRPASSD_CNT_U08)))
    {
        /* ClrNvmVari */
        Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs = ZEROMOTREV_MOTREV_S08;
    }
    else
    {
        /* Do Nothing */
    }

}

/**********************************************************************************************************************
 * Name:        TurnCntrCorrlnStsTmr
 * Description: The implementation of Simulink block TurnCntrCorrlnStsTmr
 * Inputs:      TurnCntrCorrlnSts_Cnt_T_u08
 *              *Rte_Pim_TurnCntrCorrlnStsTmrTrig()
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) TurnCntrCorrlnStsTmr(
        CONST(uint8, AUTOMATIC) TurnCntrCorrlnSts_Cnt_T_u08)
{

    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32;

    if (*Rte_Pim_TurnCntrCorrlnStsTmrTrig() != FALSE)
    {
        /*** SpanTi ***/
        (void) Rte_Call_GetTiSpan100MicroSec32bit_Oper(*Rte_Pim_TurnCntrValTi(), &TiSpan_Cnt_T_u32);

        if (TiSpan_Cnt_T_u32 >= ((uint32)Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val() * (uint32)CNVMILLISECTOCNT_CNTPERMILLISEC_U16))
        {
            /*** StopTmr ***/
            *Rte_Pim_IniTurnCntrCorrlnSts()     = (uint8) TurnCntrCorrlnSts_Cnt_T_u08;
            *Rte_Pim_TurnCntrCorrlnStsTmrTrig() = FALSE;
			if (TurnCntrCorrlnSts_Cnt_T_u08 != TURNCNTRCORRLNSTSVLD_CNT_U08)
			{
				Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs = ZEROMOTREV_MOTREV_S08;
			}
        }
        else
        {
            /* Do Nothing*/
        }
    }
    else
    {
        /* Do Nothing */
    }

}

/**********************************************************************************************************************
 * Name:        ChkTurnCntrCorrlnStsCdn
 * Description: The implementation of Simulink block ChkTurnCntrCorrlnStsCdn
 * Inputs:      TurnCntrCorrlnSts_Cnt_T_u08
 *              *Rte_Pim_PrevIgnCycBmwMotAgSelnSt()
 *              *Rte_Pim_PrevIgnCycTurnCntrCorrlnSts()
 *              *Rte_Pim_IniTurnCntrCorrlnSts()
 * Outputs:     return value of logic operation
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(boolean, BmwHwAgArbnAndEotPosn_CODE) ChkTurnCntrCorrlnStsCdn(
        CONST(uint8, AUTOMATIC) TurnCntrCorrlnSts_Cnt_T_u08)
{

    return (   (*Rte_Pim_PrevIgnCycBmwMotAgSelnSt()    == BMWMOTAGSELNSTOFFSCMPD_CNT_U08)
            && (*Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() == TURNCNTRCORRLNSTSVLD_CNT_U08)
            && (TurnCntrCorrlnSts_Cnt_T_u08            == TURNCNTRCORRLNSTSVLD_CNT_U08)
            && (*Rte_Pim_IniTurnCntrCorrlnSts()        == TURNCNTRCORRLNSTSVLD_CNT_U08)) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 * Name:        ProcessBmwQuadOffsSts
 * Description: The implementation of the state BmwQuadOffsSts processing from the block BmwMotAgOffsSelnStTranCase
 * Inputs:      BmwQuadOffsSts_Cnt_T_enum
 * In/Out:      *Rte_Pim_PrevLoopBmwQuadOffsSts(), ChgdValDetd_Cnt_T_logl
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ProcessBmwQuadOffsSts(
        CONST(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        P2VAR(boolean, AUTOMATIC, BmwHwAgArbnAndEotPosn_VAR) ChgdValDetd_Cnt_T_logl)
{
    VAR(boolean, AUTOMATIC) FromCdn_Cnt_T_logl;

    if (  (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYIDX)
       || (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDLCOMP)
       || (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSTRTSTOP)
       || (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSUMCTRLAG)
       || (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_CORROFFS)
       || (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDL))
    {
        FromCdn_Cnt_T_logl = TRUE;
    }
    else
    {
        FromCdn_Cnt_T_logl = FALSE;
    }
	/* Check BmwQuadOffSts vs PrevLoop PIM */
    if (BmwQuadOffsSts_Cnt_T_enum != *Rte_Pim_PrevLoopBmwQuadOffsSts())
	{
		*ChgdValDetd_Cnt_T_logl = TRUE;
	}
	else 
	{
		*ChgdValDetd_Cnt_T_logl = FALSE;
	}
	
    if ((FromCdn_Cnt_T_logl != FALSE) && (*ChgdValDetd_Cnt_T_logl != FALSE))
    {
        /* SetDSCCdn */
        *Rte_Pim_DynStabyCtrlCdn() =  TRUE;
    }
    else
    {
        /* NothingToDo */
    }

    *Rte_Pim_PrevLoopBmwQuadOffsSts() = BmwQuadOffsSts_Cnt_T_enum;
}


/**********************************************************************************************************************
 * Name:        ProcessBmwQuadRotorOffs1
 * Description: The implementation of the state BmwQuadRotorOffs processing from the block BmwMotAgOffsSelnStTranCase
 * Inputs:      BmwQuadRotorOffs_MotRev_T_s08, ChgdValDetd_Cnt_T_logl
 * Outputs:     Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ProcessBmwQuadRotorOffs1(
        CONST(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        CONST(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        VAR(boolean, AUTOMATIC) ChgdValDetd_Cnt_T_logl)
{
	
	if ((Rte_Pim_BmwVehCentrOffs()->BmwMotAgSelnSt == BMWMOTAGSELNST_SUBVAL) &&
		((ChgdValDetd_Cnt_T_logl != FALSE) && 
        ((BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDL) || 
		 (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDLCOMP) ||
		 (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSTRTSTOP))))
    {
		Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs = BmwQuadRotorOffs_MotRev_T_s08;	 
	}
	
}

/**********************************************************************************************************************
 * Name:        ProcessBmwQuadRotorOffs2
 * Description: The implementation of the state BmwQuadRotorOffs processing from the block BmwMotAgOffsSelnStTranCase
 * Inputs:      BmwQuadRotorOffs_MotRev_T_s08, ChgdValDetd_Cnt_T_logl
 * Outputs:     Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ProcessBmwQuadRotorOffs2(
        CONST(BmwQuadOffsSts1, AUTOMATIC) BmwQuadOffsSts_Cnt_T_enum,
        CONST(sint8, AUTOMATIC) BmwQuadRotorOffs_MotRev_T_s08,
        VAR(boolean, AUTOMATIC) ChgdValDetd_Cnt_T_logl)
{
	/* Start Existing */
    VAR(sint16, AUTOMATIC) CurrBmwQuadRotorOffsAndNvmSum_MotRev_T_s16;
	/* End Existing */
	
	if ((((ChgdValDetd_Cnt_T_logl != FALSE) && 
         ((BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSBYMDLCOMP) ||
		  (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_OFFSPOSNGBYSTRTSTOP))) &&
		 (Rte_Pim_BmwVehCentrOffs()->BmwMotAgSelnSt == BMWMOTAGSELNST_TMPCMPD)) ||
		(((ChgdValDetd_Cnt_T_logl != FALSE) &&
		  (BmwQuadOffsSts_Cnt_T_enum == BMWQUADOFFSSTS_CORROFFS)) && 
		 (Rte_Pim_BmwVehCentrOffs()->BmwMotAgSelnSt == BMWMOTAGSELNST_OFFSCMPD)))
	{
		/*** InctNvm ***/
        CurrBmwQuadRotorOffsAndNvmSum_MotRev_T_s16 = (sint16) BmwQuadRotorOffs_MotRev_T_s08 + (sint16) Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs;
		Rte_Pim_BmwVehCentrOffs()->BmwQuadRotorOffs = 
		           (sint8)Lim_s16(CurrBmwQuadRotorOffsAndNvmSum_MotRev_T_s16,BMWQUADROTOROFFSLOLIM_MOTREV_S16,BMWQUADROTOROFFSHILIM_MOTREV_S16);	   
	}
	else
	{
		/*** DoNothing ***/
	}

}


/**********************************************************************************************************************
 * Name:        ActvtLpFil
 * Description: The implementation the simulink block ActvtLpFil
 * Inputs:      *Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig()
 *              *Rte_Pim_DynStabyCtrlCdn()
 * Outputs:     *Rte_Pim_LpFilActvd()
 *              *Rte_Pim_DynStabyCtrlCdn()
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, BmwHwAgArbnAndEotPosn_CODE) ActvtLpFil(void)
{
    if ((*Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() != FALSE) || (*Rte_Pim_DynStabyCtrlCdn() != FALSE))
    {
        *Rte_Pim_LpFilActvd()      = TRUE;
        *Rte_Pim_DynStabyCtrlCdn() = FALSE;
    }
}


/**********************************************************************************************************************
 * Name:        CalcBmwPinionAgOffs
 * Description: The implementation the simulink block CalcBmwPinionAgOffs
 * Inputs:      BmwPinionAgOffs_HwDeg_T_f32
 *              BmwPinionAgOffsSts_Cnt_T_enum
 *              Rte_Pim_BmwVehCentrOffs()
 *              *Rte_Pim_BmwPinionAgOffsRateLim()
 * Outputs:     BmwPinionAgOffsOutp_HwDeg_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, BmwHwAgArbnAndEotPosn_CODE) CalcBmwPinionAgOffs(
        CONST(float32, AUTOMATIC) BmwPinionAgOffs_HwDeg_T_f32,
        CONST(BmwPinionAgOffsSts1, AUTOMATIC) BmwPinionAgOffsSts_Cnt_T_enum)
{
    VAR(float32, AUTOMATIC) BmwPinionAgOffsOutp_HwDeg_T_f32;


    if (BmwPinionAgOffsSts_Cnt_T_enum == BMWPINIONAGOFFSSTS_VLD)
    {
        Rte_Pim_BmwVehCentrOffs()->BmwPinionAgOffs = BmwPinionAgOffs_HwDeg_T_f32;
        BmwPinionAgOffsOutp_HwDeg_T_f32            = BmwPinionAgOffs_HwDeg_T_f32;
    }
    else
    {
        BmwPinionAgOffsOutp_HwDeg_T_f32 = Rte_Pim_BmwVehCentrOffs()->BmwPinionAgOffs;
    }

    /* LimStat_f4 */
    Rte_Pim_BmwVehCentrOffs()->BmwPinionAgOffs = Lim_f32(
            Rte_Pim_BmwVehCentrOffs()->BmwPinionAgOffs,
            SYSGLBPRM_HWAGLOLIM_HWDEG_F32,
            SYSGLBPRM_HWAGHILIM_HWDEG_F32);

    /* RateLimDyn_f32 */
    *Rte_Pim_BmwPinionAgOffsRateLim() = Lim_f32(
            BmwPinionAgOffsOutp_HwDeg_T_f32,
            *Rte_Pim_BmwPinionAgOffsRateLim() - (Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32),
            *Rte_Pim_BmwPinionAgOffsRateLim() + (Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val() * ARCHGLBPRM_2MILLISEC_SEC_F32));

    /* LimDyn_f32 */
    BmwPinionAgOffsOutp_HwDeg_T_f32 = Lim_f32(
            *Rte_Pim_BmwPinionAgOffsRateLim(),
            -Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val(),
            Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val());

    return BmwPinionAgOffsOutp_HwDeg_T_f32;
}

#define BmwHwAgArbnAndEotPosn_STOP_SEC_CODE
#include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
