/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot68Bas0Repn2BusFrChA.c
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM101A_BmwMsgSlot68Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot68Bas0Repn2BusFrChA
 *  Generated at:  Fri Jun  8 11:32:28 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot68Bas0Repn2BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /***********************************************************************************************************************
* Copyright 2018 Nxtr
* Nxtr Confidential
*
* Module File Name:   BmwMsgSlot68Bas0Repn2BusFrChA.c
* Module Description: BMW Message Slot 68 Base 0 Repetition 2 Bus FlexRay Channel A Processing
*                     Alive Timeout = 10ms
* Project           : CBD
* Author            : Brendon Binder
************************************************************************************************************************
* Version Control:
* %version:         5 %
* %derived_by:      nzlf92 %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 04/05/18  1        BRB       Initial file creation                                                        EA4#22318
* 04/20/18  2        BRB       Fix upper limit for BmwTarSteerTqDrvrActr                                    EA4#22318
* 04/20/18  3        PHJ       Update calibration name                                    					EA4#22318
* 06/05/18  4        PHJ       Alive Timeout Update and NTC 126 related fix                         		EA4#24654
* 06/08/18  5        PHJ       Fix anomaly EA4#24789                         								EA4#24792
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
 *********************************************************************************************************************/

#include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#include "NxtrMath.h"
#include "E2EPW_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV_rx.h"
#include "E2EPW_BmwMsgSlot68Bas0Repn2BusFrChA_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT_rx.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE reads and writes */
 
#define NTCCNTRTHD_CNT_U08                      ((uint8)3U)                                
#define BITSHIFTALVCRC_ULS_U08                  ((uint8)24U)
#define CRCMASK_ULS_U08                         ((uint8)0x02U)
#define ALVCNTRREPMASK_ULS_U08                  ((uint8)0x08U)
#define ALVCNTRSEQMASK_ULS_U08                  ((uint8)0x40U)
#define INVLD_ULS_U08                           ((uint8)0xFFU)
#define ARCINVLD_ULS_U08                        ((uint8)0xFU)
#define TARQTASTMOMDVINVLD_ULS_U16              ((uint16)0xFFFU)
#define TARQTASTMOMDVTHD_ULS_U16                ((uint16)0xFA0U)
#define FACTDMPNGADDONSTMOMFTAXTHD_ULS_U16      ((uint16)0X80U)
#define TARSTMOMDVACTTHD_ULS_U16                ((uint16)0XFA0U)
#define FACTASSSTMOMFTAXSCA_ULS_F32             (0.00390625F)
#define FACTASSSTMOMFTAXLOLIM_ULS_F32           (1.0F)
#define FACTASSSTMOMFTAXHILIM_ULS_F32           (2.0F)
#define FACTDMPNGSTMOMFTAXSCA_ULS_F32           (0.00390625F)
#define FACTDMPNGSTMOMFTAXOFFS_ULS_F32          (0.0078125F)
#define FACTDMPNGSTMOMFTAXLOLIM_ULS_F32         (0.0F)
#define FACTDMPNGSTMOMFTAXHILIM_ULS_F32         (1.0F)
#define FACTCTRRSTMOMFTAXSCA_ULS_F32            (0.00390625F)
#define FACTCTRRSTMOMFTAXOFFS_ULS_F32           (0.0078125F)
#define FACTCTRRSTMOMFTAXLOLIM_ULS_F32          (0.0F)
#define FACTCTRRSTMOMFTAXHILIM_ULS_F32          (1.0F)
#define TARQTASTMOMDVSCA_ULS_F32                (0.005F)
#define TARQTASTMOMDVOFFS_ULS_F32               (-10.0F)
#define TARQTASTMOMDVLOLIM_ULS_F32              (-10.0F)
#define TARQTASTMOMDVHILIM_ULS_F32              (10.0F)
#define FACTDMPNGADDONSTMOMFTAXSCA_ULS_F32      (0.015625F)
#define FACTDMPNGADDONSTMOMFTAXLOLIM_ULS_F32    (0.0F)
#define FACTDMPNGADDONSTMOMFTAXHILIM_ULS_F32    (2.0F)
#define TARSTMOMDVACTSCA_ULS_F32                (0.006F)
#define TARSTMOMDVACTOFFS_ULS_F32               (-12.0F)
#define TARSTMOMDVACTLOLIM_ULS_F32              (-12.0F)
#define TARSTMOMDVACTHILIM_ULS_F32              (12.0F)

static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) ClrNtcsAndCntrs(void);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc121Procg(boolean CrcVld_Cnt_T_logl);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc122Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc123Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, CTR_DEAC_EPS_FNS1 CtrDeacEpsFns_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc124Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_FACT_STMOM_FTAX1 QuTarFactStmomFtax_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc125Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_ASS_STMOM_FTAX1 FactAssStmomFtax_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc126Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_DMPNG_STMOM_FTAX1 FactDmpngStmomFtax_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc127Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_CTRR_STMOM_FTAX1 FactCtrrStmomFtax_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc128Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_QTA_STMOM_DV1 QuTarQtaStmomDv_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc129Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, TAR_QTA_STMOM_DV1 TarQtaStmomDv_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12BProcg(boolean CrcVld_Cnt_T_logl);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12CProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12DProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_DMPNG_ADDON_STMOM_FTAX1 FactDmpngAddonStmomFtax_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12EProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_DMPNG_ADDON_STMOM_FTAX1 QuTarDmpngAddonStmomFtax_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12FProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_STMOM_DV_ACT1 QuTarStmomDvAct_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc130Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, TAR_STMOM_DV_ACT1 TarStmomDvAct_Cnt_T_enum);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarQtaStrMomDvInpProcg(sigGroup_TAR_QTA_STRMOM_DV1 SigGroup_Cnt_T_rec,
                                                                             boolean ArcVld_Cnt_T_logl,
                                                                             boolean CrcVld_Cnt_T_logl,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactAssStmomFtaxCalcd_Uls_T_f32,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactDmpngStmomFtaxCalcd_Uls_T_f32,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactCtrrStmomFtaxCalcd_Uls_T_f32,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) TarQtaStmomDv_HwNm_T_f32);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarStmomDvActInpProcg(sigGroup_TAR_STMOM_DV_ACT1 SigGroup_Cnt_T_rec,
                                                                            boolean ArcVld_Cnt_T_logl,
                                                                            boolean CrcVld_Cnt_T_logl,
                                                                            P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactDmpngAddonStmomFtax_Uls_T_f32,
                                                                            P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) TarStmomDvAct_HwNm_T_f32);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarStmomDvActOutpProcg(sigGroup_TAR_STMOM_DV_ACT1 SigGroup_Cnt_T_rec,
                                                                             float32 FactDmpngAddonStmomFtax_Uls_T_f32,                       
                                                                             float32 TarStmomDvAct_HwNm_T_f32);   
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarQtaStrMomDvOutpProcg(sigGroup_TAR_QTA_STRMOM_DV1 SigGroup_Cnt_T_rec,
                                                                              float32 FactAssStmomFtaxCalcd_Uls_T_f32,
                                                                              float32 FactDmpngStmomFtaxCalcd_Uls_T_f32,
                                                                              float32 FactCtrrStmomFtaxCalcd_Uls_T_f32,
                                                                              float32 TarQtaStmomDv_HwNm_T_f32);
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) BmwDrvgDynErrIfActvProcg(void);

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
 * CRC_TAR_QTA_STMOM_DV1: Integer in interval [0...255]
 * CRC_TAR_STMOM_DV_ACT1: Integer in interval [0...255]
 * FACT_ASS_STMOM_FTAX1: Integer in interval [0...255]
 *   Factor: 0.00390625, Offset: 1
 * FACT_CTRR_STMOM_FTAX1: Integer in interval [0...255]
 *   Factor: 0.00390625, Offset: 0.0078125
 * FACT_DMPNG_STMOM_FTAX1: Integer in interval [0...255]
 *   Factor: 0.00390625, Offset: 0.0078125
 * TAR_QTA_STMOM_DV1: Integer in interval [0...65535]
 *   Factor: 0.005, Offset: -10
 * TAR_QTA_STRMOM_DV_dummy_12_151: Integer in interval [0...255]
 * TAR_STMOM_DV_ACT1: Integer in interval [0...65535]
 *   Factor: 0.006, Offset: -12
 * TAR_STMOM_DV_ACT_dummy_12_151: Integer in interval [0...255]
 * TAR_STMOM_DV_ACT_dummy_32_511: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_TAR_QTA_STMOM_DV1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * ALIV_TAR_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * BmwEpsDeactvnCtrl1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWEPSDEACTVNCTRL_NODEACTVNEPSFCT (0U)
 *   BMWEPSDEACTVNCTRL_DEACTVNEPSFCTGROUP1 (1U)
 *   BMWEPSDEACTVNCTRL_DEACTVNEPSFCTGROUP2 (2U)
 *   BMWEPSDEACTVNCTRL_FCTIFNOTAVL (13U)
 *   BMWEPSDEACTVNCTRL_FCTRPRTERR (14U)
 *   BMWEPSDEACTVNCTRL_INVLDSIG (15U)
 * BmwOvrlCmdQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWOVRLCMDQLFR_IMPLSP (2U)
 *   BMWOVRLCMDQLFR_SPNOTAVL (7U)
 *   BMWOVRLCMDQLFR_STBDONOTCNVSP (14U)
 *   BMWOVRLCMDQLFR_INVLDSIG (15U)
 * BmwTrfcJamAssiDampgStReq1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG (1U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_CNVSPADDLDAMPG (2U)
 *   BMWTRFCJAMASSIDAMPGSTREQ_INVLDSIG (15U)
 * CTR_DEAC_EPS_FNS1: Enumeration of integer in interval [0...255] with enumerators
 *   CTR_DEAC_EPS_FNS_Keine_Deaktivierung_EPS_Funktionen (0U)
 *   Keine_Deaktivierung_EPS_Funktionen_BflMask 15U (0b00001111)
 *   Keine_Deaktivierung_EPS_Funktionen_BflPn 0
 *   Keine_Deaktivierung_EPS_Funktionen_BflLn 4
 *   CTR_DEAC_EPS_FNS_Funktionsschnittstelle_ist_nicht_verfuegbar (13U)
 *   Funktionsschnittstelle_ist_nicht_verfuegbar_BflMask 15U (0b00001111)
 *   Funktionsschnittstelle_ist_nicht_verfuegbar_BflPn 0
 *   Funktionsschnittstelle_ist_nicht_verfuegbar_BflLn 4
 *   CTR_DEAC_EPS_FNS_Funktion_meldet_Fehler (14U)
 *   Funktion_meldet_Fehler_BflMask 15U (0b00001111)
 *   Funktion_meldet_Fehler_BflPn 0
 *   Funktion_meldet_Fehler_BflLn 4
 *   CTR_DEAC_EPS_FNS_Signal_unbefuellt (15U)
 *   Signal_unbefuellt_BflMask 15U (0b00001111)
 *   Signal_unbefuellt_BflPn 0
 *   Signal_unbefuellt_BflLn 4
 *   CTR_DEAC_EPS_FNS_Deaktivierung_EPS_Funktionen_Funktionsgruppe_1 (1U)
 *   Deaktivierung_EPS_Funktionen_Funktionsgruppe_1_BflMask 9U (0b00001001)
 *   CTR_DEAC_EPS_FNS_Deaktivierung_EPS_Funktionen_Funktionsgruppe_2 (2U)
 *   Deaktivierung_EPS_Funktionen_Funktionsgruppe_2_BflMask 10U (0b00001010)
 * FACT_DMPNG_ADDON_STMOM_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 *   FACT_DMPNG_ADDON_STMOM_FTAX_Reserviert (253U)
 *   FACT_DMPNG_ADDON_STMOM_FTAX_Reserviert_bne_5B8A124DE2884D68A663388C50F241EF_254 (254U)
 *   FACT_DMPNG_ADDON_STMOM_FTAX_Signal_unbefuellt (255U)
 *   Factor: 0.015625, Offset: 0
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
 * QU_TAR_DMPNG_ADDON_STMOM_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_TAR_DMPNG_ADDON_STMOM_FTAX_SollwertZusatzdaempfungNichtUmsetzen (1U)
 *   QU_TAR_DMPNG_ADDON_STMOM_FTAX_SollwertZusatzdaempfungUmsetzen (2U)
 *   QU_TAR_DMPNG_ADDON_STMOM_FTAX_SignalUnbefuellt (15U)
 * QU_TAR_FACT_STMOM_FTAX1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_TAR_FACT_STMOM_FTAX_SollwerteUmsetzen (2U)
 *   QU_TAR_FACT_STMOM_FTAX_SollwerteNichtVorhanden (7U)
 *   QU_TAR_FACT_STMOM_FTAX_StandbyColonSollwerteNichtUmsetzen (14U)
 *   QU_TAR_FACT_STMOM_FTAX_SignalUngueltig (15U)
 * QU_TAR_QTA_STMOM_DV1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_TAR_QTA_STMOM_DV_SollwerteUmsetzen (2U)
 *   QU_TAR_QTA_STMOM_DV_SollwerteNichtVorhanden (7U)
 *   QU_TAR_QTA_STMOM_DV_SollwerteNichtUmsetzen_Standby (14U)
 *   QU_TAR_QTA_STMOM_DV_SignalUngueltig (15U)
 * QU_TAR_STMOM_DV_ACT1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_TAR_STMOM_DV_ACT_SollwerteUmsetzen (2U)
 *   QU_TAR_STMOM_DV_ACT_SollwerteNichtVorhanden (7U)
 *   QU_TAR_STMOM_DV_ACT_StandbyColonSollwerteNichtUmsetzen (14U)
 *   QU_TAR_STMOM_DV_ACT_SignalUngueltig (15U)
 *
 * Record Types:
 * =============
 * sigGroup_TAR_QTA_STRMOM_DV1: Record with elements
 *   FACT_DMPNG_STMOM_FTAX of type FACT_DMPNG_STMOM_FTAX1
 *   QU_TAR_QTA_STMOM_DV of type QU_TAR_QTA_STMOM_DV1
 *   ALIV_TAR_QTA_STMOM_DV of type ALIV_TAR_QTA_STMOM_DV1
 *   QU_TAR_FACT_STMOM_FTAX of type QU_TAR_FACT_STMOM_FTAX1
 *   CTR_DEAC_EPS_FNS of type CTR_DEAC_EPS_FNS1
 *   FACT_CTRR_STMOM_FTAX of type FACT_CTRR_STMOM_FTAX1
 *   TAR_QTA_STRMOM_DV_dummy_12_15 of type TAR_QTA_STRMOM_DV_dummy_12_151
 *   FACT_ASS_STMOM_FTAX of type FACT_ASS_STMOM_FTAX1
 *   TAR_QTA_STMOM_DV of type TAR_QTA_STMOM_DV1
 *   CRC_TAR_QTA_STMOM_DV of type CRC_TAR_QTA_STMOM_DV1
 * sigGroup_TAR_STMOM_DV_ACT1: Record with elements
 *   TAR_STMOM_DV_ACT_dummy_12_15 of type TAR_STMOM_DV_ACT_dummy_12_151
 *   TAR_STMOM_DV_ACT_dummy_32_51 of type TAR_STMOM_DV_ACT_dummy_32_511
 *   QU_TAR_DMPNG_ADDON_STMOM_FTAX of type QU_TAR_DMPNG_ADDON_STMOM_FTAX1
 *   FACT_DMPNG_ADDON_STMOM_FTAX of type FACT_DMPNG_ADDON_STMOM_FTAX1
 *   TAR_STMOM_DV_ACT of type TAR_STMOM_DV_ACT1
 *   CRC_TAR_STMOM_DV_ACT of type CRC_TAR_STMOM_DV_ACT1
 *   QU_TAR_STMOM_DV_ACT of type QU_TAR_STMOM_DV_ACT1
 *   ALIV_TAR_STMOM_DV_ACT of type ALIV_TAR_STMOM_DV_ACT1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwDrvgDynDampgFacReqPrev(void)
 *   float32 *Rte_Pim_BmwDrvgDynEffortFacReqPrev(void)
 *   float32 *Rte_Pim_BmwDrvgDynRtnFacReqPrev(void)
 *   float32 *Rte_Pim_BmwTarHwTqOvrlPrev(void)
 *   float32 *Rte_Pim_BmwTarSteerTqDrvrActrPrev(void)
 *   float32 *Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev(void)
 *   BmwOvrlCmdQlfr1 *Rte_Pim_BmwDrvgDynFacQlfrPrev(void)
 *   BmwEpsDeactvnCtrl1 *Rte_Pim_BmwEpsDeactvnCtrlPrev(void)
 *   BmwOvrlCmdQlfr1 *Rte_Pim_BmwTarHwTqOvrlQlfPrev(void)
 *   BmwOvrlCmdQlfr1 *Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev(void)
 *   BmwTrfcJamAssiDampgStReq1 *Rte_Pim_BmwTrfcJamAssiDampgStReqPrev(void)
 *   uint8 *Rte_Pim_CtrDeacEpsFnsFaild(void)
 *   uint8 *Rte_Pim_CtrDeacEpsFnsPassd(void)
 *   uint8 *Rte_Pim_FactAssStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactAssStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_FactCtrrStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactCtrrStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_FactDmpngAddonStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactDmpngAddonStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_FactDmpngStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_FactDmpngStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_QuTarDmpngAddonStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_QuTarDmpngAddonStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_QuTarFactStmomFtaxFaild(void)
 *   uint8 *Rte_Pim_QuTarFactStmomFtaxPassd(void)
 *   uint8 *Rte_Pim_QuTarQtaStmomDvFaild(void)
 *   uint8 *Rte_Pim_QuTarQtaStmomDvPassd(void)
 *   uint8 *Rte_Pim_QuTarStmomDvActFaild(void)
 *   uint8 *Rte_Pim_QuTarStmomDvActPassd(void)
 *   uint8 *Rte_Pim_TarQtaStmomDvFaild(void)
 *   uint8 *Rte_Pim_TarQtaStmomDvPassd(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvAliveCntFaild(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvAliveCntPassd(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvCRCFaild(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvCRCPassd(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvMissFaild(void)
 *   uint8 *Rte_Pim_TarQtaStrmomDvMissPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActAliveCntFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActAliveCntPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActCrcFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActCrcPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActMissFaild(void)
 *   uint8 *Rte_Pim_TarStmomDvActMissPassd(void)
 *   uint8 *Rte_Pim_TarStmomDvActPassd(void)
 *   boolean *Rte_Pim_BmwDrvgDynDampgFacReqVldPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynEffortFacReqVldPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynEnaReqPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynErrIfActvPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynFacQlfrVldPrev(void)
 *   boolean *Rte_Pim_BmwDrvgDynRtnFacReqVldPrev(void)
 *   boolean *Rte_Pim_BmwEpsDeactvnCtrlVldPrev(void)
 *   boolean *Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev(void)
 *   boolean *Rte_Pim_BmwTarHwTqOvrlVldPrev(void)
 *   boolean *Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev(void)
 *   boolean *Rte_Pim_BmwTarSteerTqDrvrActrVldPrev(void)
 *   boolean *Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev(void)
 *   boolean *Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev(void)
 *   boolean *Rte_Pim_TarQtaStrmomDvArcVld(void)
 *   boolean *Rte_Pim_TarQtaStrmomDvMsgProcd(void)
 *   boolean *Rte_Pim_TarQtaStrmomDvMsgVld(void)
 *   boolean *Rte_Pim_TarStmomDvActArcVld(void)
 *   boolean *Rte_Pim_TarStmomDvActMsgProcd(void)
 *   boolean *Rte_Pim_TarStmomDvActMsgVld(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot68Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot68Bas0Repn2BusFrChAInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot68Bas0Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) BmwMsgSlot68Bas0Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot68Bas0Repn2BusFrChAInit1
 *********************************************************************************************************************/
    
    /* Clear all NTC counters and clear NTCs */
    ClrNtcsAndCntrs();
    
    /* Initialize output PIMs with nominal values */
    *Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev() = 0.0F;
    *Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() = FALSE;
    *Rte_Pim_BmwTrfcJamAssiDampgStReqPrev() = BMWTRFCJAMASSIDAMPGSTREQ_DONOTCNVSPADDLDAMPG;
    *Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() = FALSE;
    *Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev() = BMWOVRLCMDQLFR_INVLDSIG;
    *Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() = FALSE;
    *Rte_Pim_BmwTarSteerTqDrvrActrPrev() = 0.0F;
    *Rte_Pim_BmwEpsDeactvnCtrlPrev() = BMWEPSDEACTVNCTRL_INVLDSIG;
    *Rte_Pim_BmwDrvgDynFacQlfrPrev() = BMWOVRLCMDQLFR_INVLDSIG;
    *Rte_Pim_BmwDrvgDynFacQlfrVldPrev() = FALSE;
    *Rte_Pim_BmwDrvgDynEffortFacReqPrev() = FACTASSSTMOMFTAXLOLIM_ULS_F32;
    *Rte_Pim_BmwDrvgDynDampgFacReqPrev() = 0.0F;
    *Rte_Pim_BmwDrvgDynRtnFacReqPrev() = 0.0F;
    *Rte_Pim_BmwTarHwTqOvrlQlfPrev() = BMWOVRLCMDQLFR_INVLDSIG;
    *Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() = FALSE;
    *Rte_Pim_BmwTarHwTqOvrlPrev() = 0.0F;
    *Rte_Pim_BmwDrvgDynErrIfActvPrev() = FALSE;
    *Rte_Pim_BmwDrvgDynEnaReqPrev() = FALSE;
        
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_QTA_STRMOM_DV_Miss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_TAR_QTA_STRMOM_DV> of PortPrototype <sigGroup_TAR_QTA_STRMOM_DV>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(sigGroup_TAR_QTA_STRMOM_DV1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynDampgFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEffortFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynRtnFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwEpsDeactvnCtrl_Val(BmwEpsDeactvnCtrl1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrl_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_QTA_STRMOM_DV_Miss_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_QTA_STRMOM_DV_Miss(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_QTA_STRMOM_DV_Miss
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) FltCodEnad_Cnt_T_logl;
    
    /* Read Inputs */
    (void)Rte_Read_FltCodEnad_Logl(&FltCodEnad_Cnt_T_logl);    
    
    /* NTC $120 Processing */
    if (FltCodEnad_Cnt_T_logl == TRUE)
    {
        /* Clear NTC $120 passed counter */
        *Rte_Pim_TarQtaStrmomDvMissPassd() = 0U;
        
        if (*Rte_Pim_TarQtaStrmomDvMissFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStrmomDvMissFaild() = *Rte_Pim_TarQtaStrmomDvMissFaild() + 1U;
        }
        if (*Rte_Pim_TarQtaStrmomDvMissFaild() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X120, 0U, NTCSTS_FAILD, 0U);
        }
    }
    else
    {
        /* Clear all NTC counters and clear NTCs */
        ClrNtcsAndCntrs();
    }
    
    /* Populate outputs */
    *Rte_Pim_BmwEpsDeactvnCtrlVldPrev() = FALSE;
    *Rte_Pim_BmwDrvgDynFacQlfrVldPrev() = FALSE;
    *Rte_Pim_BmwDrvgDynEffortFacReqVldPrev() = FALSE;
    *Rte_Pim_BmwDrvgDynDampgFacReqVldPrev() = FALSE;
    *Rte_Pim_BmwDrvgDynRtnFacReqVldPrev() = FALSE;
    *Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() = FALSE;
    *Rte_Pim_BmwTarHwTqOvrlVldPrev() = FALSE;
    
    /* Write message outputs */
    (void)Rte_Write_BmwDrvgDynDampgFacReq_Val(*Rte_Pim_BmwDrvgDynDampgFacReqPrev());
    (void)Rte_Write_BmwDrvgDynEffortFacReq_Val(*Rte_Pim_BmwDrvgDynEffortFacReqPrev());
    (void)Rte_Write_BmwDrvgDynFacQlfr_Val(*Rte_Pim_BmwDrvgDynFacQlfrPrev());
    (void)Rte_Write_BmwDrvgDynFacQlfrVld_Logl(*Rte_Pim_BmwDrvgDynFacQlfrVldPrev());
    (void)Rte_Write_BmwDrvgDynRtnFacReq_Val(*Rte_Pim_BmwDrvgDynRtnFacReqPrev());
    (void)Rte_Write_BmwEpsDeactvnCtrl_Val(*Rte_Pim_BmwEpsDeactvnCtrlPrev());
    (void)Rte_Write_BmwTarHwTqOvrl_Val(*Rte_Pim_BmwTarHwTqOvrlPrev());
    (void)Rte_Write_BmwTarHwTqOvrlQlfr_Val(*Rte_Pim_BmwTarHwTqOvrlQlfPrev());
    (void)Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(*Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev());
    
    /* Write common outputs */
    (void)Rte_Write_BmwDrvgDynErrIfActv_Logl(*Rte_Pim_BmwDrvgDynErrIfActvPrev());
    (void)Rte_Write_BmwDrvgDynEnaRqst_Logl(*Rte_Pim_BmwDrvgDynEnaReqPrev());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_QTA_STRMOM_DV_Rxd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_TAR_QTA_STRMOM_DV> of PortPrototype <sigGroup_TAR_QTA_STRMOM_DV>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(sigGroup_TAR_QTA_STRMOM_DV1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynDampgFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEffortFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynFacQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynRtnFacReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwEpsDeactvnCtrl_Val(BmwEpsDeactvnCtrl1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrl_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_QTA_STRMOM_DV_Rxd_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_QTA_STRMOM_DV_Rxd(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_QTA_STRMOM_DV_Rxd
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) FltCodEnad_Cnt_T_logl;
    VAR(sigGroup_TAR_QTA_STRMOM_DV1, AUTOMATIC) SigGroup_Cnt_T_rec;
    VAR(uint8, AUTOMATIC) E2EReturn_Uls_T_u08;
    
    /* Variables */
    VAR(boolean, AUTOMATIC) CrcVld_Cnt_T_logl = TRUE;
    VAR(boolean, AUTOMATIC) ArcVld_Cnt_T_logl = TRUE;
    VAR(CTR_DEAC_EPS_FNS1, AUTOMATIC) CtrDeacEpsFns_Cnt_T_enum;
    VAR(QU_TAR_FACT_STMOM_FTAX1, AUTOMATIC) QuTarFactStmomFtax_Cnt_T_enum;
    VAR(FACT_ASS_STMOM_FTAX1, AUTOMATIC) FactAssStmomFtax_Cnt_T_enum;
    VAR(FACT_DMPNG_STMOM_FTAX1, AUTOMATIC) FactDmpngStmomFtax_Cnt_T_enum;
    VAR(FACT_CTRR_STMOM_FTAX1, AUTOMATIC) FactCtrrStmomFtax_Cnt_T_enum;
    VAR(QU_TAR_QTA_STMOM_DV1, AUTOMATIC) QuTarQtaStmomDv_Cnt_T_enum;
    VAR(TAR_QTA_STMOM_DV1, AUTOMATIC) TarQtaStmomDv_Cnt_T_enum;
    VAR(float32, AUTOMATIC) FactAssStmomFtaxCalcd_Uls_T_f32;
    VAR(float32, AUTOMATIC) FactDmpngStmomFtaxCalcd_Uls_T_f32;
    VAR(float32, AUTOMATIC) FactCtrrStmomFtaxCalcd_Uls_T_f32;
    VAR(float32, AUTOMATIC) TarQtaStmomDv_HwNm_T_f32;
    
    /* Read Inputs */
    (void)Rte_Read_FltCodEnad_Logl(&FltCodEnad_Cnt_T_logl);
        
    E2EReturn_Uls_T_u08 = (uint8)(E2EPW_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(&SigGroup_Cnt_T_rec) >> BITSHIFTALVCRC_ULS_U08);
    CtrDeacEpsFns_Cnt_T_enum = SigGroup_Cnt_T_rec.CTR_DEAC_EPS_FNS;
    QuTarFactStmomFtax_Cnt_T_enum = SigGroup_Cnt_T_rec.QU_TAR_FACT_STMOM_FTAX;
    FactAssStmomFtax_Cnt_T_enum = SigGroup_Cnt_T_rec.FACT_ASS_STMOM_FTAX;
    FactDmpngStmomFtax_Cnt_T_enum = SigGroup_Cnt_T_rec.FACT_DMPNG_STMOM_FTAX;
    FactCtrrStmomFtax_Cnt_T_enum = SigGroup_Cnt_T_rec.FACT_CTRR_STMOM_FTAX;
    QuTarQtaStmomDv_Cnt_T_enum = SigGroup_Cnt_T_rec.QU_TAR_QTA_STMOM_DV;
    TarQtaStmomDv_Cnt_T_enum = SigGroup_Cnt_T_rec.TAR_QTA_STMOM_DV;
    
    /* Check ARC and CRC */
    if ((E2EReturn_Uls_T_u08 & CRCMASK_ULS_U08) == CRCMASK_ULS_U08)
    {
        CrcVld_Cnt_T_logl = FALSE;
    }
    if (((E2EReturn_Uls_T_u08 & ALVCNTRREPMASK_ULS_U08) == ALVCNTRREPMASK_ULS_U08) ||
        ((E2EReturn_Uls_T_u08 & ALVCNTRSEQMASK_ULS_U08) == ALVCNTRSEQMASK_ULS_U08) ||
        (SigGroup_Cnt_T_rec.ALIV_TAR_QTA_STMOM_DV == ARCINVLD_ULS_U08))
    {
        ArcVld_Cnt_T_logl = FALSE;
    }
    
    /* Update CRC and ARC validity flag */
    if (ArcVld_Cnt_T_logl == TRUE)
    {
        *Rte_Pim_TarQtaStrmomDvArcVld() = TRUE;
    }
    else
    {
        *Rte_Pim_TarQtaStrmomDvArcVld() = FALSE;
    }
    
    /*** Start of NTC Processing ***/
    if (FltCodEnad_Cnt_T_logl == TRUE)
    {
        /*** Start of NTC $120 Processing ***/
        *Rte_Pim_TarQtaStrmomDvMissFaild() = 0U;
        
        if (*Rte_Pim_TarQtaStrmomDvMissPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStrmomDvMissPassd() = *Rte_Pim_TarQtaStrmomDvMissPassd() + 1U;
        }
        if (*Rte_Pim_TarQtaStrmomDvMissPassd() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X120, 0U, NTCSTS_PASSD, 0U);
        }    
        /*** End of NTC $120 Processing ***/
        
        /* NTC $121 Processing */
        Ntc121Procg(CrcVld_Cnt_T_logl);
        
        /* NTC $122 Processing */
        Ntc122Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl);
        
        /* NTC $123 Processing */
        Ntc123Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, CtrDeacEpsFns_Cnt_T_enum);
        
        /* NTC $124 Processing */
        Ntc124Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, QuTarFactStmomFtax_Cnt_T_enum);
        
        /* NTC $125 Processing */
        Ntc125Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, FactAssStmomFtax_Cnt_T_enum);
        
        /* NTC $126 Processing */
        Ntc126Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, FactDmpngStmomFtax_Cnt_T_enum);
        
        /* NTC $127 Processing */
        Ntc127Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, FactCtrrStmomFtax_Cnt_T_enum);
        
        /* NTC $128 Processing */
        Ntc128Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, QuTarQtaStmomDv_Cnt_T_enum);
        
        /* NTC $129 Processing */
        Ntc129Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, TarQtaStmomDv_Cnt_T_enum);
    }
    else
    {
        /* Clear all NTC counters and clear NTCs */
        ClrNtcsAndCntrs();
    }
    
    /* TAR_QTA_STMOM_DV Input Processing */
    TarQtaStrMomDvInpProcg(SigGroup_Cnt_T_rec,
                           ArcVld_Cnt_T_logl,
                           CrcVld_Cnt_T_logl,
                           &FactAssStmomFtaxCalcd_Uls_T_f32,
                           &FactDmpngStmomFtaxCalcd_Uls_T_f32,
                           &FactCtrrStmomFtaxCalcd_Uls_T_f32,
                           &TarQtaStmomDv_HwNm_T_f32);
                           
    /* Set message processed flag */
    *Rte_Pim_TarQtaStrmomDvMsgProcd() = TRUE;
                           
    /* TAR_QTA_STMOM_DV Output Processing */
    TarQtaStrMomDvOutpProcg(SigGroup_Cnt_T_rec,
                            FactAssStmomFtaxCalcd_Uls_T_f32,
                            FactDmpngStmomFtaxCalcd_Uls_T_f32,
                            FactCtrrStmomFtaxCalcd_Uls_T_f32,
                            TarQtaStmomDv_HwNm_T_f32);                            
                            
    /* BmwDrvgDynErrIfActv Processing */
    if ((*Rte_Pim_TarStmomDvActMsgProcd() == TRUE) && (*Rte_Pim_TarQtaStrmomDvMsgProcd() == TRUE))
    {
        /* Clear message processing flags */
        *Rte_Pim_TarStmomDvActMsgProcd() = FALSE;
        *Rte_Pim_TarQtaStrmomDvMsgProcd() = FALSE;
        
        /* Update BmwDrvgDynErrIfActv */
        BmwDrvgDynErrIfActvProcg();  
        
        /* Update BmwDrvgDynEnaReq */
        if ((*Rte_Pim_TarStmomDvActArcVld() == TRUE) && (*Rte_Pim_TarQtaStrmomDvArcVld() == TRUE))
        {
            *Rte_Pim_BmwDrvgDynEnaReqPrev() = TRUE;
        }
        else
        {
            *Rte_Pim_BmwDrvgDynEnaReqPrev() = FALSE;
        }
    }
    
    /* Write message outputs */
    (void)Rte_Write_BmwDrvgDynDampgFacReq_Val(*Rte_Pim_BmwDrvgDynDampgFacReqPrev());
    (void)Rte_Write_BmwDrvgDynEffortFacReq_Val(*Rte_Pim_BmwDrvgDynEffortFacReqPrev());
    (void)Rte_Write_BmwDrvgDynFacQlfr_Val(*Rte_Pim_BmwDrvgDynFacQlfrPrev());
    (void)Rte_Write_BmwDrvgDynFacQlfrVld_Logl(*Rte_Pim_BmwDrvgDynFacQlfrVldPrev());
    (void)Rte_Write_BmwDrvgDynRtnFacReq_Val(*Rte_Pim_BmwDrvgDynRtnFacReqPrev());
    (void)Rte_Write_BmwEpsDeactvnCtrl_Val(*Rte_Pim_BmwEpsDeactvnCtrlPrev());
    (void)Rte_Write_BmwTarHwTqOvrl_Val(*Rte_Pim_BmwTarHwTqOvrlPrev());
    (void)Rte_Write_BmwTarHwTqOvrlQlfr_Val(*Rte_Pim_BmwTarHwTqOvrlQlfPrev());
    (void)Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(*Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev());
    
    /* Write common outputs */
    (void)Rte_Write_BmwDrvgDynErrIfActv_Logl(*Rte_Pim_BmwDrvgDynErrIfActvPrev());
    (void)Rte_Write_BmwDrvgDynEnaRqst_Logl(*Rte_Pim_BmwDrvgDynEnaReqPrev());    

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_STMOM_DV_ACT_Miss
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_TAR_STMOM_DV_ACT> of PortPrototype <sigGroup_TAR_STMOM_DV_ACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(sigGroup_TAR_STMOM_DV_ACT1 *data)
 *   boolean Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActr_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_STMOM_DV_ACT_Miss_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_STMOM_DV_ACT_Miss(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_STMOM_DV_ACT_Miss
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) FltCodEnad_Cnt_T_logl;
    
    /* Read Inputs */
    (void)Rte_Read_FltCodEnad_Logl(&FltCodEnad_Cnt_T_logl);
    
    
    if (FltCodEnad_Cnt_T_logl == TRUE)
    {
        /*** Start of NTC $12A Processing ***/
        *Rte_Pim_TarStmomDvActMissPassd() = 0U;
        
        if (*Rte_Pim_TarStmomDvActMissFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActMissFaild() = *Rte_Pim_TarStmomDvActMissFaild() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActMissFaild() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12A, 0U, NTCSTS_FAILD, 0U);
        }
        /*** End of NTC $12A Processing ***/
    }
    else
    {
        /* Clear all NTC counters and clear NTCs */
        ClrNtcsAndCntrs();
    }    
    
    /* Populate outputs */
    *Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() = FALSE;
    *Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() = FALSE;
    *Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() = FALSE;
    *Rte_Pim_BmwTarSteerTqDrvrActrVldPrev() = FALSE;
    
    /* Write message outputs */
    (void)Rte_Write_BmwTarSteerTqDrvrActr_Val(*Rte_Pim_BmwTarSteerTqDrvrActrPrev());
    (void)Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(*Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev());
    (void)Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(*Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(*Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(*Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgStReq_Val(*Rte_Pim_BmwTrfcJamAssiDampgStReqPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(*Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev());
    
    /* Write common outputs */
    (void)Rte_Write_BmwDrvgDynErrIfActv_Logl(*Rte_Pim_BmwDrvgDynErrIfActvPrev());
    (void)Rte_Write_BmwDrvgDynEnaRqst_Logl(*Rte_Pim_BmwDrvgDynEnaReqPrev());
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TAR_STMOM_DV_ACT_Rxd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_TAR_STMOM_DV_ACT> of PortPrototype <sigGroup_TAR_STMOM_DV_ACT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(sigGroup_TAR_STMOM_DV_ACT1 *data)
 *   boolean Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActr_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 data)
 *   Std_ReturnType Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_STMOM_DV_ACT_Rxd_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TAR_STMOM_DV_ACT_Rxd(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TAR_STMOM_DV_ACT_Rxd
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) FltCodEnad_Cnt_T_logl;
    VAR(sigGroup_TAR_STMOM_DV_ACT1, AUTOMATIC) SigGroup_Cnt_T_rec;
    VAR(uint8, AUTOMATIC) E2EReturn_Uls_T_u08;
    
    /* Variables */
    VAR(boolean, AUTOMATIC) CrcVld_Cnt_T_logl = TRUE;
    VAR(boolean, AUTOMATIC) ArcVld_Cnt_T_logl = TRUE;
    VAR(FACT_DMPNG_ADDON_STMOM_FTAX1, AUTOMATIC) FactDmpngAddonStmomFtax_Cnt_T_enum;
    VAR(QU_TAR_DMPNG_ADDON_STMOM_FTAX1, AUTOMATIC) QuTarDmpngAddonStmomFtax_Cnt_T_enum;
    VAR(QU_TAR_STMOM_DV_ACT1, AUTOMATIC) QuTarStmomDvAct_Cnt_T_enum;
    VAR(TAR_STMOM_DV_ACT1, AUTOMATIC) TarStmomDvAct_Cnt_T_enum;
    VAR(float32, AUTOMATIC) FactDmpngAddonStmomFtax_Uls_T_f32;
    VAR(float32, AUTOMATIC) TarStmomDvAct_HwNm_T_f32;
    
    /* Read Inputs */
    (void)Rte_Read_FltCodEnad_Logl(&FltCodEnad_Cnt_T_logl);
    E2EReturn_Uls_T_u08 = (uint8)(E2EPW_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(&SigGroup_Cnt_T_rec) >> BITSHIFTALVCRC_ULS_U08);
    FactDmpngAddonStmomFtax_Cnt_T_enum = SigGroup_Cnt_T_rec.FACT_DMPNG_ADDON_STMOM_FTAX;
    QuTarDmpngAddonStmomFtax_Cnt_T_enum = SigGroup_Cnt_T_rec.QU_TAR_DMPNG_ADDON_STMOM_FTAX;
    QuTarStmomDvAct_Cnt_T_enum = SigGroup_Cnt_T_rec.QU_TAR_STMOM_DV_ACT;
    TarStmomDvAct_Cnt_T_enum = SigGroup_Cnt_T_rec.TAR_STMOM_DV_ACT;
    
    /* Check ARC and CRC */
    if ((E2EReturn_Uls_T_u08 & CRCMASK_ULS_U08) == CRCMASK_ULS_U08)
    {
        CrcVld_Cnt_T_logl = FALSE;
    }
    if (((E2EReturn_Uls_T_u08 & ALVCNTRREPMASK_ULS_U08) == ALVCNTRREPMASK_ULS_U08) ||
        ((E2EReturn_Uls_T_u08 & ALVCNTRSEQMASK_ULS_U08) == ALVCNTRSEQMASK_ULS_U08) ||
        (SigGroup_Cnt_T_rec.ALIV_TAR_STMOM_DV_ACT == ARCINVLD_ULS_U08))
    {
        ArcVld_Cnt_T_logl = FALSE;
    }
    
    /* Update ARC and CRC validity flag */
    if (ArcVld_Cnt_T_logl == TRUE)
    {
        *Rte_Pim_TarStmomDvActArcVld() = TRUE;
    }
    else
    {
        *Rte_Pim_TarStmomDvActArcVld() = FALSE;
    }
    
    /*** Start of NTC Processing ***/
    if (FltCodEnad_Cnt_T_logl == TRUE)
    {
        /*** Start of NTC $12A Processing ***/
        *Rte_Pim_TarStmomDvActMissFaild() = 0U;
        
        if (*Rte_Pim_TarStmomDvActMissPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActMissPassd() = *Rte_Pim_TarStmomDvActMissPassd() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActMissPassd() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12A, 0U, NTCSTS_PASSD, 0U);
        }
        /*** End of NTC $12A Processing ***/
        
        /* NTC $12B Processing */
        Ntc12BProcg(CrcVld_Cnt_T_logl);
        
        /* NTC $12C Processing */
        Ntc12CProcg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl);
        
        /* NTC $12D Processing */
        Ntc12DProcg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, FactDmpngAddonStmomFtax_Cnt_T_enum);
        
        /* NTC $12E Processing */
        Ntc12EProcg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, QuTarDmpngAddonStmomFtax_Cnt_T_enum);
        
        /* NTC $12F Processing */
        Ntc12FProcg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, QuTarStmomDvAct_Cnt_T_enum);
        
        /* NTC $130 Processing */
        Ntc130Procg(ArcVld_Cnt_T_logl, CrcVld_Cnt_T_logl, TarStmomDvAct_Cnt_T_enum);        
    }
    else
    {
        /* Clear all NTC counters and clear NTCs */
        ClrNtcsAndCntrs();
    }
    /*** End of NTC Processing ***/
    
    /* TAR_STMOM_DV_ACT Input Processing */
    TarStmomDvActInpProcg(SigGroup_Cnt_T_rec,
                          ArcVld_Cnt_T_logl,
                          CrcVld_Cnt_T_logl,
                          &FactDmpngAddonStmomFtax_Uls_T_f32,
                          &TarStmomDvAct_HwNm_T_f32);
    
    /* Set flag for this message being processed */
    *Rte_Pim_TarStmomDvActMsgProcd() = TRUE;
    
    /* TAR_STMOM_DV_ACT Output Processing */
    TarStmomDvActOutpProcg(SigGroup_Cnt_T_rec,
                           FactDmpngAddonStmomFtax_Uls_T_f32,                       
                           TarStmomDvAct_HwNm_T_f32);
                           
    /* BmwDrvgDynErrIfActv and BmwDrvgDynEnaReq Processing */
    if ((*Rte_Pim_TarStmomDvActMsgProcd() == TRUE) && (*Rte_Pim_TarQtaStrmomDvMsgProcd() == TRUE))
    {
        /* Clear message processing flags */
        *Rte_Pim_TarStmomDvActMsgProcd() = FALSE;
        *Rte_Pim_TarQtaStrmomDvMsgProcd() = FALSE;
        
        /* Update BmwDrvgDynErrIfActv */
        BmwDrvgDynErrIfActvProcg(); 

        /* Update BmwDrvgDynEnaReq */
        if ((*Rte_Pim_TarStmomDvActArcVld() == TRUE) && (*Rte_Pim_TarQtaStrmomDvArcVld() == TRUE))
        {
            *Rte_Pim_BmwDrvgDynEnaReqPrev() = TRUE;
        }
        else
        {
            *Rte_Pim_BmwDrvgDynEnaReqPrev() = FALSE;
        }
    }    

    /* Write message outputs */
    (void)Rte_Write_BmwTarSteerTqDrvrActr_Val(*Rte_Pim_BmwTarSteerTqDrvrActrPrev());
    (void)Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(*Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev());
    (void)Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(*Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(*Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(*Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgStReq_Val(*Rte_Pim_BmwTrfcJamAssiDampgStReqPrev());
    (void)Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(*Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev());
    
    /* Write common outputs */
    (void)Rte_Write_BmwDrvgDynErrIfActv_Logl(*Rte_Pim_BmwDrvgDynErrIfActvPrev());
    (void)Rte_Write_BmwDrvgDynEnaRqst_Logl(*Rte_Pim_BmwDrvgDynEnaReqPrev());

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot68Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot68Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
 * Name:        ClrNtcsAndCntrs
 * Description: Clears all NTC counters and clears all NTCs
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) ClrNtcsAndCntrs(void)
{
    /* Reset TAR_QTA_STRMOM_DV NTC Counters to 0 and clear NTCs */    
    *Rte_Pim_TarQtaStrmomDvMissFaild() = 0U;
    *Rte_Pim_TarQtaStrmomDvMissPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X120, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_TarQtaStrmomDvCRCFaild() = 0U;
    *Rte_Pim_TarQtaStrmomDvCRCPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X121, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_TarQtaStrmomDvAliveCntFaild() = 0U;
    *Rte_Pim_TarQtaStrmomDvAliveCntPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X122, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_CtrDeacEpsFnsFaild() = 0U;
    *Rte_Pim_CtrDeacEpsFnsPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X123, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_QuTarFactStmomFtaxFaild() = 0U;
    *Rte_Pim_QuTarFactStmomFtaxPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X124, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_FactAssStmomFtaxFaild() = 0U;
    *Rte_Pim_FactAssStmomFtaxPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X125, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_FactDmpngStmomFtaxFaild() = 0U;
    *Rte_Pim_FactDmpngStmomFtaxPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X126, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_FactCtrrStmomFtaxFaild() = 0U;
    *Rte_Pim_FactCtrrStmomFtaxPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X127, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_QuTarQtaStmomDvFaild() = 0U;
    *Rte_Pim_QuTarQtaStmomDvPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X128, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_TarQtaStmomDvFaild() = 0U;
    *Rte_Pim_TarQtaStmomDvPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X129, 0U, NTCSTS_PASSD, 0U);
    
    /* Reset TAR_STMOM_DV_ACT NTC counters to 0 and clear NTCs */
    *Rte_Pim_TarStmomDvActMissFaild() = 0U;
    *Rte_Pim_TarStmomDvActMissPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12A, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_TarStmomDvActCrcFaild() = 0U;
    *Rte_Pim_TarStmomDvActCrcPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12B, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_TarStmomDvActAliveCntFaild() = 0U;
    *Rte_Pim_TarStmomDvActAliveCntPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12C, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_FactDmpngAddonStmomFtaxFaild() = 0U;
    *Rte_Pim_FactDmpngAddonStmomFtaxPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12D, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() = 0U;
    *Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12E, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_QuTarStmomDvActFaild() = 0U;
    *Rte_Pim_QuTarStmomDvActPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12F, 0U, NTCSTS_PASSD, 0U);
    *Rte_Pim_TarStmomDvActFaild() = 0U;
    *Rte_Pim_TarStmomDvActPassd() = 0U;
    (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X130, 0U, NTCSTS_PASSD, 0U);
}

 
/******************************************************************************
 * Name:        NTC121Procg
 * Description: Performs the debounce check for NTC $121
 * Inputs:      CrcVld_Cnt_T_logl - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc121Procg(boolean CrcVld_Cnt_T_logl)
{    
    if (CrcVld_Cnt_T_logl == TRUE)
    {
        /* If CRC valid, clear failed counter and process passed counter */
        *Rte_Pim_TarQtaStrmomDvCRCFaild() = 0U;
        
        if (*Rte_Pim_TarQtaStrmomDvCRCPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStrmomDvCRCPassd() = *Rte_Pim_TarQtaStrmomDvCRCPassd() + 1U;
        }
        if (*Rte_Pim_TarQtaStrmomDvCRCPassd() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X121, 0U, NTCSTS_PASSD, 0U);
        }
    }
    else
    {
        /* If CRC invalid, clear passed counter and process failed counter */
        *Rte_Pim_TarQtaStrmomDvCRCPassd() = 0U;
        
        if (*Rte_Pim_TarQtaStrmomDvCRCFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStrmomDvCRCFaild() = *Rte_Pim_TarQtaStrmomDvCRCFaild() + 1U;
        }
        if (*Rte_Pim_TarQtaStrmomDvCRCFaild() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X121, 0U, NTCSTS_FAILD, 0U);
        }        
    }    
}


/******************************************************************************
 * Name:        NTC122Procg
 * Description: Performs the debounce check for NTC $122
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for ARC
 *              CrcVld_Cnt_T_logl - Validity flag for CRC    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc122Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl)
{
    if (ArcVld_Cnt_T_logl == TRUE)
    {
        /* If alive counter valid, clear failed counter and process passed counter */
        *Rte_Pim_TarQtaStrmomDvAliveCntFaild() = 0U;
        
        if (*Rte_Pim_TarQtaStrmomDvAliveCntPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStrmomDvAliveCntPassd() = *Rte_Pim_TarQtaStrmomDvAliveCntPassd() + 1U;
        }
        if (*Rte_Pim_TarQtaStrmomDvAliveCntPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if (CrcVld_Cnt_T_logl == TRUE)
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X122, 0U, NTCSTS_PASSD, 0U);
            }
        }       
    }
    else
    {
        /* If alive counter invalid, clear passed counter and process failed counter */
        *Rte_Pim_TarQtaStrmomDvAliveCntPassd() = 0U;
        
        if (*Rte_Pim_TarQtaStrmomDvAliveCntFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStrmomDvAliveCntFaild() = *Rte_Pim_TarQtaStrmomDvAliveCntFaild() + 1U;
        }
        if (*Rte_Pim_TarQtaStrmomDvAliveCntFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if (CrcVld_Cnt_T_logl == TRUE)
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X122, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }
}


/******************************************************************************
 * Name:        NTC123Procg
 * Description: Performs the debounce check for NTC $123
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              CtrDeacEpsFns_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc123Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, CTR_DEAC_EPS_FNS1 CtrDeacEpsFns_Cnt_T_enum)
{
    
    if ((CtrDeacEpsFns_Cnt_T_enum == CTR_DEAC_EPS_FNS_Keine_Deaktivierung_EPS_Funktionen) ||
        (CtrDeacEpsFns_Cnt_T_enum == CTR_DEAC_EPS_FNS_Deaktivierung_EPS_Funktionen_Funktionsgruppe_1) ||
        (CtrDeacEpsFns_Cnt_T_enum == CTR_DEAC_EPS_FNS_Deaktivierung_EPS_Funktionen_Funktionsgruppe_2) ||
        (CtrDeacEpsFns_Cnt_T_enum == CTR_DEAC_EPS_FNS_Funktionsschnittstelle_ist_nicht_verfuegbar) ||
        (CtrDeacEpsFns_Cnt_T_enum == CTR_DEAC_EPS_FNS_Funktion_meldet_Fehler))
    {
        /* If CtrDeacEpsFns valid, clear failed counter and process passed counter */
        *Rte_Pim_CtrDeacEpsFnsFaild() = 0U;
        
        if (*Rte_Pim_CtrDeacEpsFnsPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_CtrDeacEpsFnsPassd() = *Rte_Pim_CtrDeacEpsFnsPassd() + 1U;
        }
        if (*Rte_Pim_CtrDeacEpsFnsPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X123, 0U, NTCSTS_PASSD, 0U);
            }
        }        
    }
    else
    {
        /* If CtrDeacEpsFns invalid, clear the passed counter and process the failed counter */
        *Rte_Pim_CtrDeacEpsFnsPassd() = 0U;
        
        if (*Rte_Pim_CtrDeacEpsFnsFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_CtrDeacEpsFnsFaild() = *Rte_Pim_CtrDeacEpsFnsFaild() + 1U;
        }
        if (*Rte_Pim_CtrDeacEpsFnsFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X123, 0U, NTCSTS_FAILD, 0U);
            }
        }        
    }    
    
}


/******************************************************************************
 * Name:        NTC124Procg
 * Description: Performs the debounce check for NTC $124
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              QuTarFactStmomFtax_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc124Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_FACT_STMOM_FTAX1 QuTarFactStmomFtax_Cnt_T_enum)
{
    if ((QuTarFactStmomFtax_Cnt_T_enum == QU_TAR_FACT_STMOM_FTAX_SollwerteUmsetzen) ||
        (QuTarFactStmomFtax_Cnt_T_enum == QU_TAR_FACT_STMOM_FTAX_SollwerteNichtVorhanden) ||
        (QuTarFactStmomFtax_Cnt_T_enum == QU_TAR_FACT_STMOM_FTAX_StandbyColonSollwerteNichtUmsetzen))
    {
        /* If QuTarFactStmomFtax valid, clear failed counter and process passed counter */
        *Rte_Pim_QuTarFactStmomFtaxFaild() = 0U;
        
        if (*Rte_Pim_QuTarFactStmomFtaxPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarFactStmomFtaxPassd() = *Rte_Pim_QuTarFactStmomFtaxPassd() + 1U;
        }
        if (*Rte_Pim_QuTarFactStmomFtaxPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X124, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If QuTarFactStmomFtax invalid, clear the passed counter and process the failed counter */
        *Rte_Pim_QuTarFactStmomFtaxPassd() = 0U;
        if (*Rte_Pim_QuTarFactStmomFtaxFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarFactStmomFtaxFaild() = *Rte_Pim_QuTarFactStmomFtaxFaild() + 1U;
        }
        if (*Rte_Pim_QuTarFactStmomFtaxFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X124, 0U, NTCSTS_FAILD, 0U);
            }
        }   
    }    
}


/******************************************************************************
 * Name:        NTC125Procg
 * Description: Performs the debounce check for NTC $125
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              FactAssStmomFtax_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc125Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_ASS_STMOM_FTAX1 FactAssStmomFtax_Cnt_T_enum)
{
    if (FactAssStmomFtax_Cnt_T_enum != INVLD_ULS_U08)
    {
        /* If FactAssStmomFtax valid, clear failed counter and process passed counter */
        *Rte_Pim_FactAssStmomFtaxFaild() = 0U;
        
        if (*Rte_Pim_FactAssStmomFtaxPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactAssStmomFtaxPassd() = *Rte_Pim_FactAssStmomFtaxPassd() + 1U;
        }
        if (*Rte_Pim_FactAssStmomFtaxPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X125, 0U, NTCSTS_PASSD, 0U);
            }
        }   
    }
    else
    {
        /* If FactAssStmomFtax invalid, clear passed counter and process the failed counter */
        *Rte_Pim_FactAssStmomFtaxPassd() = 0U;
        
        if (*Rte_Pim_FactAssStmomFtaxFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactAssStmomFtaxFaild() = *Rte_Pim_FactAssStmomFtaxFaild() + 1U;
        }
        if (*Rte_Pim_FactAssStmomFtaxFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X125, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }    
}


/******************************************************************************
 * Name:        NTC126Procg
 * Description: Performs the debounce check for NTC $126
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              FactDmpngStmomFtax_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc126Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_DMPNG_STMOM_FTAX1 FactDmpngStmomFtax_Cnt_T_enum)
{
    if (FactDmpngStmomFtax_Cnt_T_enum != INVLD_ULS_U08)
    {
        /* If FactDmpngStmomFtax valid, clear failed counter and process passed counter */
        *Rte_Pim_FactDmpngStmomFtaxFaild() = 0U;
        
        if (*Rte_Pim_FactDmpngStmomFtaxPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactDmpngStmomFtaxPassd() = *Rte_Pim_FactDmpngStmomFtaxPassd() + 1U;
        }
        if (*Rte_Pim_FactDmpngStmomFtaxPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X126, 0U, NTCSTS_PASSD, 0U);
            }
        }  
    }
    else
    {
        /* If FactDmpngStmomFtax invalid, clear passed counter and process the failed counter */
        *Rte_Pim_FactDmpngStmomFtaxPassd() = 0U;
        
        if (*Rte_Pim_FactDmpngStmomFtaxFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactDmpngStmomFtaxFaild() = *Rte_Pim_FactDmpngStmomFtaxFaild() + 1U;
        }
        if (*Rte_Pim_FactDmpngStmomFtaxFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X126, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }        
}


/******************************************************************************
 * Name:        NTC127Procg
 * Description: Performs the debounce check for NTC $127
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              FactCtrrStmomFtax_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc127Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_CTRR_STMOM_FTAX1 FactCtrrStmomFtax_Cnt_T_enum)
{
    if (FactCtrrStmomFtax_Cnt_T_enum != INVLD_ULS_U08)
    {
        /* If FactCtrrStmomFtax valid, clear failed counter and process passed counter */
        *Rte_Pim_FactCtrrStmomFtaxFaild() = 0U;
          
        if (*Rte_Pim_FactCtrrStmomFtaxPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactCtrrStmomFtaxPassd() = *Rte_Pim_FactCtrrStmomFtaxPassd() + 1U;
        }        
        if (*Rte_Pim_FactCtrrStmomFtaxPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X127, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If FactCtrrStmomFtax invalid, clear passed counter and process the failed counter */
        *Rte_Pim_FactCtrrStmomFtaxPassd() = 0U;
        
        if (*Rte_Pim_FactCtrrStmomFtaxFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactCtrrStmomFtaxFaild() = *Rte_Pim_FactCtrrStmomFtaxFaild() + 1U;
        }
        if (*Rte_Pim_FactCtrrStmomFtaxFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X127, 0U, NTCSTS_FAILD, 0U);
            }
        }        
    }        
}


/******************************************************************************
 * Name:        NTC128Procg
 * Description: Performs the debounce check for NTC $128
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              QuTarQtaStmomDv_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc128Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_QTA_STMOM_DV1 QuTarQtaStmomDv_Cnt_T_enum)
{
    if ((QuTarQtaStmomDv_Cnt_T_enum == QU_TAR_QTA_STMOM_DV_SollwerteUmsetzen) ||
        (QuTarQtaStmomDv_Cnt_T_enum == QU_TAR_QTA_STMOM_DV_SollwerteNichtVorhanden) ||
        (QuTarQtaStmomDv_Cnt_T_enum == QU_TAR_QTA_STMOM_DV_SollwerteNichtUmsetzen_Standby))
    {
        /* If QuTarQtaStmomDv valid, clear failed counter and process passed counter */
        *Rte_Pim_QuTarQtaStmomDvFaild() = 0U;
        
        if (*Rte_Pim_QuTarQtaStmomDvPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarQtaStmomDvPassd() = *Rte_Pim_QuTarQtaStmomDvPassd() + 1U;
        }
        if (*Rte_Pim_QuTarQtaStmomDvPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X128, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If QuTarQtaStmomDv invalid, clear the passed counter and process the failed counter */
        *Rte_Pim_QuTarQtaStmomDvPassd() = 0U;
        
        if (*Rte_Pim_QuTarQtaStmomDvFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarQtaStmomDvFaild() = *Rte_Pim_QuTarQtaStmomDvFaild() + 1U;
        }
        if (*Rte_Pim_QuTarQtaStmomDvFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X128, 0U, NTCSTS_FAILD, 0U);
            }
        } 
    }        
}


/******************************************************************************
 * Name:        NTC129Procg
 * Description: Performs the debounce check for NTC $129
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              TarQtaStmomDv_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc129Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, TAR_QTA_STMOM_DV1 TarQtaStmomDv_Cnt_T_enum)
{    
    if (TarQtaStmomDv_Cnt_T_enum <= TARQTASTMOMDVTHD_ULS_U16)
    {
        /* If FactCtrrStmomFtax valid, clear failed counter and process passed counter */
        *Rte_Pim_TarQtaStmomDvFaild() = 0U;
        
        if (*Rte_Pim_TarQtaStmomDvPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStmomDvPassd() = *Rte_Pim_TarQtaStmomDvPassd() + 1U;
        }
        if (*Rte_Pim_TarQtaStmomDvPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X129, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If FactCtrrStmomFtax invalid, clear passed counter and process the failed counter */
        *Rte_Pim_TarQtaStmomDvPassd() = 0U;
        
        if (*Rte_Pim_TarQtaStmomDvFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarQtaStmomDvFaild() = *Rte_Pim_TarQtaStmomDvFaild() + 1U;
        }
        if (*Rte_Pim_TarQtaStmomDvFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((CrcVld_Cnt_T_logl == TRUE) && (ArcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X129, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }        
}


/******************************************************************************
 * Name:        NTC12BProcg
 * Description: Performs the debounce check for NTC $12B
 * Inputs:      CrcVld_Cnt_T_logl - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12BProcg(boolean CrcVld_Cnt_T_logl)
{
    if (CrcVld_Cnt_T_logl == TRUE)
    {
        /* If CRC valid, clear failed counter and process passed counter */
        *Rte_Pim_TarStmomDvActCrcFaild() = 0U;
        
        if (*Rte_Pim_TarStmomDvActCrcPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActCrcPassd() = *Rte_Pim_TarStmomDvActCrcPassd() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActCrcPassd() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12B, 0U, NTCSTS_PASSD, 0U);
        }
    }
    else
    {
        /* If CRC invalid, clear passed counter and process failed counter */
        *Rte_Pim_TarStmomDvActCrcPassd() = 0U;
        
        if (*Rte_Pim_TarStmomDvActCrcFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActCrcFaild() = *Rte_Pim_TarStmomDvActCrcFaild() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActCrcFaild() >= NTCCNTRTHD_CNT_U08)
        {
            (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12B, 0U, NTCSTS_FAILD, 0U);
        }
    }
}


/******************************************************************************
 * Name:        NTC12CProcg
 * Description: Performs the debounce check for NTC $12C
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for ARC
 *              CrcVld_Cnt_T_logl - Validity flag for CRC    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12CProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl)
{
    if (ArcVld_Cnt_T_logl == TRUE)
    {
        /* If ARC valid, clear failed counter and process passed counter */
        *Rte_Pim_TarStmomDvActAliveCntFaild() = 0U;
        
        if (*Rte_Pim_TarStmomDvActAliveCntPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActAliveCntPassd() = *Rte_Pim_TarStmomDvActAliveCntPassd() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActAliveCntPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if (CrcVld_Cnt_T_logl == TRUE)
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12C, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If ARC invalid, clear passed counter and process failed counter */
        *Rte_Pim_TarStmomDvActAliveCntPassd() = 0U;
        
        if (*Rte_Pim_TarStmomDvActAliveCntFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActAliveCntFaild() = *Rte_Pim_TarStmomDvActAliveCntFaild() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActAliveCntFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if (CrcVld_Cnt_T_logl == TRUE)
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12C, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }
}


/******************************************************************************
 * Name:        NTC12DProcg
 * Description: Performs the debounce check for NTC $12D
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              FactDmpngAddonStmomFtax_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12DProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, FACT_DMPNG_ADDON_STMOM_FTAX1 FactDmpngAddonStmomFtax_Cnt_T_enum)
{
    if (FactDmpngAddonStmomFtax_Cnt_T_enum <= FACTDMPNGADDONSTMOMFTAXTHD_ULS_U16)
    {
        /* If valid, clear failed counter and process passed counter */
        *Rte_Pim_FactDmpngAddonStmomFtaxFaild() = 0U;
        
        if (*Rte_Pim_FactDmpngAddonStmomFtaxPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactDmpngAddonStmomFtaxPassd() = *Rte_Pim_FactDmpngAddonStmomFtaxPassd() + 1U;
        }
        if (*Rte_Pim_FactDmpngAddonStmomFtaxPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12D, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If invalid, clear passed counter and process failed counter */
        *Rte_Pim_FactDmpngAddonStmomFtaxPassd() = 0U;
        
        if (*Rte_Pim_FactDmpngAddonStmomFtaxFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_FactDmpngAddonStmomFtaxFaild() = *Rte_Pim_FactDmpngAddonStmomFtaxFaild() + 1U;
        }
        if (*Rte_Pim_FactDmpngAddonStmomFtaxFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12D, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }
}


/******************************************************************************
 * Name:        NTC12EProcg
 * Description: Performs the debounce check for NTC $12E
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              QuTarDmpngAddonStmomFtax_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12EProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_DMPNG_ADDON_STMOM_FTAX1 QuTarDmpngAddonStmomFtax_Cnt_T_enum)
{
    if ((QuTarDmpngAddonStmomFtax_Cnt_T_enum == QU_TAR_DMPNG_ADDON_STMOM_FTAX_SollwertZusatzdaempfungNichtUmsetzen) ||
        (QuTarDmpngAddonStmomFtax_Cnt_T_enum == QU_TAR_DMPNG_ADDON_STMOM_FTAX_SollwertZusatzdaempfungUmsetzen))
    {
        /* If valid, clear failed counter and process passed counter */
        *Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() = 0U;
        
        if (*Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() = *Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() + 1U;
        }
        if (*Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12E, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If invalid, clear passed counter and process failed counter */
        *Rte_Pim_QuTarDmpngAddonStmomFtaxPassd() = 0U;
        
        if (*Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() = *Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() + 1U;
        }
        if (*Rte_Pim_QuTarDmpngAddonStmomFtaxFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12E, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }    
}


/******************************************************************************
 * Name:        NTC12FProcg
 * Description: Performs the debounce check for NTC $12F
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              QuTarStmomDvAct_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc12FProcg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, QU_TAR_STMOM_DV_ACT1 QuTarStmomDvAct_Cnt_T_enum)
{
    if ((QuTarStmomDvAct_Cnt_T_enum == QU_TAR_STMOM_DV_ACT_SollwerteUmsetzen) ||
        (QuTarStmomDvAct_Cnt_T_enum == QU_TAR_STMOM_DV_ACT_SollwerteNichtVorhanden) || 
        (QuTarStmomDvAct_Cnt_T_enum == QU_TAR_STMOM_DV_ACT_StandbyColonSollwerteNichtUmsetzen))
    {
        /* If valid, clear failed counter and process passed counter */
        *Rte_Pim_QuTarStmomDvActFaild() = 0U;
        
        if (*Rte_Pim_QuTarStmomDvActPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarStmomDvActPassd() = *Rte_Pim_QuTarStmomDvActPassd() + 1U;
        }
        if (*Rte_Pim_QuTarStmomDvActPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12F, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If invalid, clear passed counter and process failed counter */
        *Rte_Pim_QuTarStmomDvActPassd() = 0U;
        
        if (*Rte_Pim_QuTarStmomDvActFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_QuTarStmomDvActFaild() = *Rte_Pim_QuTarStmomDvActFaild() + 1U;
        }
        if (*Rte_Pim_QuTarStmomDvActFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X12F, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }     
}


/******************************************************************************
 * Name:        NTC130Procg
 * Description: Performs the debounce check for NTC $130
 * Inputs:      ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC
 *              TarStmomDvAct_Cnt_T_enum - NTC passed or failed counters will be set based on this input    
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) Ntc130Procg(boolean ArcVld_Cnt_T_logl, boolean CrcVld_Cnt_T_logl, TAR_STMOM_DV_ACT1 TarStmomDvAct_Cnt_T_enum)
{
    if (TarStmomDvAct_Cnt_T_enum <= TARSTMOMDVACTTHD_ULS_U16)
    {
        /* If valid, clear failed counter and process passed counter */
        *Rte_Pim_TarStmomDvActFaild() = 0U;
        
        if (*Rte_Pim_TarStmomDvActPassd() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActPassd() = *Rte_Pim_TarStmomDvActPassd() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActPassd() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X130, 0U, NTCSTS_PASSD, 0U);
            }
        }
    }
    else
    {
        /* If invalid, clear passed counter and process failed counter */
        *Rte_Pim_TarStmomDvActPassd() = 0U;
        
        if (*Rte_Pim_TarStmomDvActFaild() < NTCCNTRTHD_CNT_U08)
        {
            *Rte_Pim_TarStmomDvActFaild() = *Rte_Pim_TarStmomDvActFaild() + 1U;
        }
        if (*Rte_Pim_TarStmomDvActFaild() >= NTCCNTRTHD_CNT_U08)
        {
            if ((ArcVld_Cnt_T_logl == TRUE) && (CrcVld_Cnt_T_logl == TRUE))
            {
                (void)Rte_Call_SetNtcSts_Oper(NTCNR_0X130, 0U, NTCSTS_FAILD, 0U);
            }
        }
    }
}


/******************************************************************************
 * Name:        TarQtaStrMomDvInpProcg
 * Description: Processes TAR_QTA_STRMOM_DV inputs
 * Inputs:      SigGroup_Cnt_T_rec - Input message signal
 *              ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC   
 * Outputs:     FactAssStmomFtaxCalcd_Uls_T_f32 - Output for message
 *              FactDmpngStmomFtaxCalcd_Uls_T_f32 - Output for message
 *              FactCtrrStmomFtaxCalcd_Uls_T_f32 - Output for message
 *              TarQtaStmomDv_HwNm_T_f32 - Output for message
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarQtaStrMomDvInpProcg(sigGroup_TAR_QTA_STRMOM_DV1 SigGroup_Cnt_T_rec,
                                                                             boolean ArcVld_Cnt_T_logl,
                                                                             boolean CrcVld_Cnt_T_logl,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactAssStmomFtaxCalcd_Uls_T_f32,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactDmpngStmomFtaxCalcd_Uls_T_f32,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactCtrrStmomFtaxCalcd_Uls_T_f32,
                                                                             P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) TarQtaStmomDv_HwNm_T_f32)
{
    /* Calculate outputs */
    *FactAssStmomFtaxCalcd_Uls_T_f32 = ((float32)SigGroup_Cnt_T_rec.FACT_ASS_STMOM_FTAX * FACTASSSTMOMFTAXSCA_ULS_F32) + 1.0F;
    *FactAssStmomFtaxCalcd_Uls_T_f32 = Lim_f32(*FactAssStmomFtaxCalcd_Uls_T_f32, FACTASSSTMOMFTAXLOLIM_ULS_F32, FACTASSSTMOMFTAXHILIM_ULS_F32);
    *FactDmpngStmomFtaxCalcd_Uls_T_f32 = ((float32)SigGroup_Cnt_T_rec.FACT_DMPNG_STMOM_FTAX * FACTDMPNGSTMOMFTAXSCA_ULS_F32) + FACTDMPNGSTMOMFTAXOFFS_ULS_F32;
    *FactDmpngStmomFtaxCalcd_Uls_T_f32 = Lim_f32(*FactDmpngStmomFtaxCalcd_Uls_T_f32, FACTDMPNGSTMOMFTAXLOLIM_ULS_F32, FACTDMPNGSTMOMFTAXHILIM_ULS_F32);
    *FactCtrrStmomFtaxCalcd_Uls_T_f32 = ((float32)SigGroup_Cnt_T_rec.FACT_CTRR_STMOM_FTAX * FACTCTRRSTMOMFTAXSCA_ULS_F32) + FACTCTRRSTMOMFTAXOFFS_ULS_F32;
    *FactCtrrStmomFtaxCalcd_Uls_T_f32 = Lim_f32(*FactCtrrStmomFtaxCalcd_Uls_T_f32, FACTCTRRSTMOMFTAXLOLIM_ULS_F32, FACTCTRRSTMOMFTAXHILIM_ULS_F32);
    *TarQtaStmomDv_HwNm_T_f32 = ((float32)SigGroup_Cnt_T_rec.TAR_QTA_STMOM_DV * TARQTASTMOMDVSCA_ULS_F32) + TARQTASTMOMDVOFFS_ULS_F32;
    *TarQtaStmomDv_HwNm_T_f32 = Lim_f32(*TarQtaStmomDv_HwNm_T_f32, TARQTASTMOMDVLOLIM_ULS_F32, TARQTASTMOMDVHILIM_ULS_F32);
	*TarQtaStmomDv_HwNm_T_f32 = (*TarQtaStmomDv_HwNm_T_f32)*((float32)(Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val()));
        
    /* CTR_DEAC_EPS_FNS */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        ((SigGroup_Cnt_T_rec.CTR_DEAC_EPS_FNS == CTR_DEAC_EPS_FNS_Keine_Deaktivierung_EPS_Funktionen) ||
         (SigGroup_Cnt_T_rec.CTR_DEAC_EPS_FNS == CTR_DEAC_EPS_FNS_Deaktivierung_EPS_Funktionen_Funktionsgruppe_1) ||
         (SigGroup_Cnt_T_rec.CTR_DEAC_EPS_FNS == CTR_DEAC_EPS_FNS_Deaktivierung_EPS_Funktionen_Funktionsgruppe_2) ||
         (SigGroup_Cnt_T_rec.CTR_DEAC_EPS_FNS == CTR_DEAC_EPS_FNS_Funktionsschnittstelle_ist_nicht_verfuegbar) ||
         (SigGroup_Cnt_T_rec.CTR_DEAC_EPS_FNS == CTR_DEAC_EPS_FNS_Funktion_meldet_Fehler)))
    {
        *Rte_Pim_BmwEpsDeactvnCtrlVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwEpsDeactvnCtrlVldPrev() = FALSE;
    }
    
    /* QU_TAR_FACT_STMOM_FTAX */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        ((SigGroup_Cnt_T_rec.QU_TAR_FACT_STMOM_FTAX == QU_TAR_FACT_STMOM_FTAX_SollwerteUmsetzen) ||
         (SigGroup_Cnt_T_rec.QU_TAR_FACT_STMOM_FTAX == QU_TAR_FACT_STMOM_FTAX_SollwerteNichtVorhanden) ||
         (SigGroup_Cnt_T_rec.QU_TAR_FACT_STMOM_FTAX == QU_TAR_FACT_STMOM_FTAX_StandbyColonSollwerteNichtUmsetzen)))
    {
        *Rte_Pim_BmwDrvgDynFacQlfrVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwDrvgDynFacQlfrVldPrev() = FALSE;
    }
    
    /* FACT_ASS_STMOM_FTAX */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        (SigGroup_Cnt_T_rec.FACT_ASS_STMOM_FTAX != INVLD_ULS_U08))
    {
        *Rte_Pim_BmwDrvgDynEffortFacReqVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwDrvgDynEffortFacReqVldPrev() = FALSE;
    }
    
    /* FACT_DMPNG_STMOM_FTAX */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        (SigGroup_Cnt_T_rec.FACT_DMPNG_STMOM_FTAX != INVLD_ULS_U08))
    {
        *Rte_Pim_BmwDrvgDynDampgFacReqVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwDrvgDynDampgFacReqVldPrev() = FALSE;
    }
    
    /* FACT_CTRR_STMOM_FTAX */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        (SigGroup_Cnt_T_rec.FACT_CTRR_STMOM_FTAX != INVLD_ULS_U08))
    {
        *Rte_Pim_BmwDrvgDynRtnFacReqVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwDrvgDynRtnFacReqVldPrev() = FALSE;
    }
    
    /* QU_TAR_QTA_STMOM_DV */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        ((SigGroup_Cnt_T_rec.QU_TAR_QTA_STMOM_DV == QU_TAR_STMOM_DV_ACT_SollwerteUmsetzen) ||
         (SigGroup_Cnt_T_rec.QU_TAR_QTA_STMOM_DV == QU_TAR_STMOM_DV_ACT_SollwerteNichtVorhanden) ||
         (SigGroup_Cnt_T_rec.QU_TAR_QTA_STMOM_DV == QU_TAR_STMOM_DV_ACT_StandbyColonSollwerteNichtUmsetzen)))
    {
        *Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() = FALSE;
    }
    
    /* TAR_QTA_STMOM_DV */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        (SigGroup_Cnt_T_rec.TAR_QTA_STMOM_DV <= TARQTASTMOMDVTHD_ULS_U16))
    {
        *Rte_Pim_BmwTarHwTqOvrlVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwTarHwTqOvrlVldPrev() = FALSE;
    }
}


/******************************************************************************
 * Name:        TarStmomDvActInpProcg
 * Description: Processes TAR_STMOM_DV_ACT inputs
 * Inputs:      SigGroup_Cnt_T_rec - Input message signal
 *              ArcVld_Cnt_T_logl - Validity flag for alive rolling counter
 *              CrcVld_Cnt_T_logl - Validity flag for CRC    
 * Outputs:     FactDmpngAddonStmomFtax_Uls_T_f32 - Output for message
 *              TarStmomDvAct_HwNm_T_f32 - Output for message
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarStmomDvActInpProcg(sigGroup_TAR_STMOM_DV_ACT1 SigGroup_Cnt_T_rec,
                                                                            boolean ArcVld_Cnt_T_logl,
                                                                            boolean CrcVld_Cnt_T_logl,
                                                                            P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) FactDmpngAddonStmomFtax_Uls_T_f32,
                                                                            P2VAR(float32, AUTOMATIC, RTE_BMWMSGSLOT68BAS0REPN2BUSFRCHA_APPL_VAR) TarStmomDvAct_HwNm_T_f32)
                                                                            
{
    /* Calculate outputs */
    *FactDmpngAddonStmomFtax_Uls_T_f32 = ((float32)SigGroup_Cnt_T_rec.FACT_DMPNG_ADDON_STMOM_FTAX * FACTDMPNGADDONSTMOMFTAXSCA_ULS_F32);
    *FactDmpngAddonStmomFtax_Uls_T_f32 = Lim_f32(*FactDmpngAddonStmomFtax_Uls_T_f32, FACTDMPNGADDONSTMOMFTAXLOLIM_ULS_F32, FACTDMPNGADDONSTMOMFTAXHILIM_ULS_F32);
    *TarStmomDvAct_HwNm_T_f32 = ((float32)SigGroup_Cnt_T_rec.TAR_STMOM_DV_ACT * TARSTMOMDVACTSCA_ULS_F32) + TARSTMOMDVACTOFFS_ULS_F32;
    *TarStmomDvAct_HwNm_T_f32 = Lim_f32(*TarStmomDvAct_HwNm_T_f32, TARSTMOMDVACTLOLIM_ULS_F32, TARSTMOMDVACTHILIM_ULS_F32);
	*TarStmomDvAct_HwNm_T_f32 = (*TarStmomDvAct_HwNm_T_f32)*((float32)(Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val()));
        
    /* FACT_DMPNG_ADDON_STMOM_FTAX */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        (SigGroup_Cnt_T_rec.FACT_DMPNG_ADDON_STMOM_FTAX <= FACTDMPNGADDONSTMOMFTAXTHD_ULS_U16))
    {
        *Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() = FALSE;
    }
    
    /* QU_TAR_DMPNG_ADDON_STMOM_FTAX */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        ((SigGroup_Cnt_T_rec.QU_TAR_DMPNG_ADDON_STMOM_FTAX == QU_TAR_DMPNG_ADDON_STMOM_FTAX_SollwertZusatzdaempfungNichtUmsetzen) ||
         (SigGroup_Cnt_T_rec.QU_TAR_DMPNG_ADDON_STMOM_FTAX == QU_TAR_DMPNG_ADDON_STMOM_FTAX_SollwertZusatzdaempfungUmsetzen)))
    {
        *Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() = FALSE;
    }
    
    /* QU_TAR_STMOM_DV_ACT */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        ((SigGroup_Cnt_T_rec.QU_TAR_STMOM_DV_ACT == QU_TAR_STMOM_DV_ACT_SollwerteUmsetzen) ||
         (SigGroup_Cnt_T_rec.QU_TAR_STMOM_DV_ACT == QU_TAR_STMOM_DV_ACT_SollwerteNichtVorhanden) ||
         (SigGroup_Cnt_T_rec.QU_TAR_STMOM_DV_ACT == QU_TAR_STMOM_DV_ACT_StandbyColonSollwerteNichtUmsetzen)))
    {
        *Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() = FALSE;
    }
    
    /* TAR_STMOM_DV_ACT */
    if ((CrcVld_Cnt_T_logl == TRUE) && 
        (ArcVld_Cnt_T_logl == TRUE) && 
        (SigGroup_Cnt_T_rec.TAR_STMOM_DV_ACT <= TARSTMOMDVACTTHD_ULS_U16))
    {
        *Rte_Pim_BmwTarSteerTqDrvrActrVldPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwTarSteerTqDrvrActrVldPrev() = FALSE;
    }    
}


/******************************************************************************
 * Name:        TarStmomDvActOutpProcg
 * Description: Processes TAR_STMOM_DV_ACT outputs
 * Inputs:      SigGroup_Cnt_T_rec - Input message signal
 *              FactDmpngAddonStmomFtax_Uls_T_f32 - Output for message
 *              TarStmomDvAct_HwNm_T_f32 - Output for message
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarStmomDvActOutpProcg(sigGroup_TAR_STMOM_DV_ACT1 SigGroup_Cnt_T_rec,
                                                                             float32 FactDmpngAddonStmomFtax_Uls_T_f32,                       
                                                                             float32 TarStmomDvAct_HwNm_T_f32)
{
    if (*Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() == TRUE)
    {
        *Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev() = FactDmpngAddonStmomFtax_Uls_T_f32;
    }
    
    if (*Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() == TRUE)
    {
        *Rte_Pim_BmwTrfcJamAssiDampgStReqPrev() = SigGroup_Cnt_T_rec.QU_TAR_DMPNG_ADDON_STMOM_FTAX;
    }
    
    if (*Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() == TRUE)
    {
        *Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev() = SigGroup_Cnt_T_rec.QU_TAR_STMOM_DV_ACT;
    }
    
    if (*Rte_Pim_BmwTarSteerTqDrvrActrVldPrev() == TRUE)
    {
        *Rte_Pim_BmwTarSteerTqDrvrActrPrev() = TarStmomDvAct_HwNm_T_f32;
    }    
}


/******************************************************************************
 * Name:        TarQtaStrMomDvOutpProcg
 * Description: Processes TAR_QTA_STRMOM_DV outputs
 * Inputs:      SigGroup_Cnt_T_rec - Input message signal
 *              BmwEpsDeactvnCtrlVld_Cnt_T_logl - Validity flag for BmwTrfcJamAssiDampgScaReq
 *              FactAssStmomFtaxCalcd_Uls_T_f32 - Output for message
 *              FactDmpngStmomFtaxCalcd_Uls_T_f32 - Output for message
 *              FactCtrrStmomFtaxCalcd_Uls_T_f32 - Output for message
 *              TarQtaStmomDv_HwNm_T_f32 - Output for message
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) TarQtaStrMomDvOutpProcg(sigGroup_TAR_QTA_STRMOM_DV1 SigGroup_Cnt_T_rec,
                                                                              float32 FactAssStmomFtaxCalcd_Uls_T_f32,
                                                                              float32 FactDmpngStmomFtaxCalcd_Uls_T_f32,
                                                                              float32 FactCtrrStmomFtaxCalcd_Uls_T_f32,
                                                                              float32 TarQtaStmomDv_HwNm_T_f32)                                                                        
{
    if (*Rte_Pim_BmwEpsDeactvnCtrlVldPrev() == TRUE)
    {
        *Rte_Pim_BmwEpsDeactvnCtrlPrev() = SigGroup_Cnt_T_rec.CTR_DEAC_EPS_FNS;
    }
    
    if (*Rte_Pim_BmwDrvgDynFacQlfrVldPrev() == TRUE)
    {
        *Rte_Pim_BmwDrvgDynFacQlfrPrev() = SigGroup_Cnt_T_rec.QU_TAR_FACT_STMOM_FTAX;
    }
    
    if (*Rte_Pim_BmwDrvgDynEffortFacReqVldPrev() == TRUE)
    {
        *Rte_Pim_BmwDrvgDynEffortFacReqPrev() = FactAssStmomFtaxCalcd_Uls_T_f32;
    }
    
    if (*Rte_Pim_BmwDrvgDynDampgFacReqVldPrev() == TRUE)
    {
        *Rte_Pim_BmwDrvgDynDampgFacReqPrev() = FactDmpngStmomFtaxCalcd_Uls_T_f32;
    }
    
    if (*Rte_Pim_BmwDrvgDynRtnFacReqVldPrev() == TRUE)
    {
        *Rte_Pim_BmwDrvgDynRtnFacReqPrev() = FactCtrrStmomFtaxCalcd_Uls_T_f32;
    }
    
    if (*Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() == TRUE)
    {
        *Rte_Pim_BmwTarHwTqOvrlQlfPrev() = SigGroup_Cnt_T_rec.QU_TAR_QTA_STMOM_DV;
    }
    
    if (*Rte_Pim_BmwTarHwTqOvrlVldPrev() == TRUE)
    {
        *Rte_Pim_BmwTarHwTqOvrlPrev() = TarQtaStmomDv_HwNm_T_f32;
    }
}


/******************************************************************************
 * Name:        BmwDrvgDynErrIfActvProcg
 * Description: Processes BmwDrvgDynErrIfActv output
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot68Bas0Repn2BusFrChA_CODE) BmwDrvgDynErrIfActvProcg(void)
{   
    if ((*Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev() == FALSE) ||
        (*Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev() == FALSE) ||
        (*Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev() == FALSE) ||
        (*Rte_Pim_BmwTarSteerTqDrvrActrVldPrev() == FALSE) ||
        (*Rte_Pim_BmwEpsDeactvnCtrlVldPrev() == FALSE) ||
        (*Rte_Pim_BmwDrvgDynFacQlfrVldPrev() == FALSE) ||
        (*Rte_Pim_BmwDrvgDynEffortFacReqVldPrev() == FALSE) ||
        (*Rte_Pim_BmwDrvgDynDampgFacReqVldPrev() == FALSE) ||
        (*Rte_Pim_BmwDrvgDynRtnFacReqVldPrev() == FALSE) ||
        (*Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev() == FALSE) ||
        (*Rte_Pim_BmwTarHwTqOvrlVldPrev() == FALSE))
    {
        *Rte_Pim_BmwDrvgDynErrIfActvPrev() = TRUE;
    }
    else
    {
        *Rte_Pim_BmwDrvgDynErrIfActvPrev() = FALSE;
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
