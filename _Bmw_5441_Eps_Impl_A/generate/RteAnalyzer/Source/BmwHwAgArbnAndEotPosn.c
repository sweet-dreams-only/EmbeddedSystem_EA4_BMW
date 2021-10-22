/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwHwAgArbnAndEotPosn.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwHwAgArbnAndEotPosn
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwHwAgArbnAndEotPosn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

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
 *   
 *
 * BmwPinionAgOffsSts1
 *   
 *
 * BmwPinionAgQlfr1
 *   
 *
 * BmwQuadOffsSts1
 *   
 *
 * BmwRackToVehCentrOffsSts1
 *   
 *
 * BmwSetVehCentrOffsSts1
 *   
 *
 * BmwVehSpdSts1
 *   
 *
 * NtcNr1
 *   
 *
 * NtcSts1
 *   
 *
 * SigQlfr1
 *   
 *
 * s18p13
 *   
 *
 *
 * Runnable Entities:
 * ==================
 * BmwHwAgArbnAndEotPosnInit1
 *   
 *
 * BmwHwAgArbnAndEotPosnPer1
 *   
 *
 *
 * Per-Instance Memory:
 * ====================
 * AllwExitFromInitTi
 *   
 *
 * BmwRackCentrToVehCentrOffsSts
 *   
 *
 * BmwVehCentrOffs
 *   
 *
 * ClrNotCmplPinionAgFlg
 *   
 *
 * CurrAlgndPinionAg
 *   
 *
 * CurrDftPinionAgFltPrsnt
 *   
 *
 * FirstLoopIndcr
 *   
 *
 * KineIntegrityFlt
 *   
 *
 * OffsCorrnRefTi
 *   
 *
 * PinionAgConfRampStVari
 *   
 *
 * PinionAgFilStVari
 *   
 *
 * PinionAgFltRefTi
 *   
 *
 * PrevAllwCorrn
 *   
 *
 * PrevBmwMotAgSelnSt
 *   
 *
 * PrevBmwOffsAuthy
 *   
 *
 * PrevBmwOffsAuthyFlg
 *   
 *
 * PrevLoopBmwMotAgSelnSt
 *   
 *
 * PrevPinionAgConf
 *   
 *
 * SetBmwRackCentrToVehCentrOffsTrig
 *   
 *
 * SigInvldTranTrig
 *   
 *
 * VehCentrCmpl
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwHwAgArbnAndEotPosn.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwHwAgArbnAndEotPosn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwHwAgArbnAndEotPosn_TestDefines(void);


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
 *   Std_ReturnType Rte_Call_BmwVehCentrOffs_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(boolean RamBlockStatus_Arg)
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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimBmwPinionAgOffsRateLim;
  float32 PimCurrAlgndPinionAg;
  float32 PimPinionAgConfRampStVari;
  float32 PimPrevBmwOffsAuthy;
  float32 PimPrevLoopPinionAg;
  float32 PimPrevPinionAgConf;
  uint32 PimAllwExitFromInitTi;
  uint32 PimMotPosnDegArbdBlndTi;
  uint32 PimOffsCorrnRefTi;
  uint32 PimPinionAgFltRefTi;
  uint32 PimTurnCntrValTi;
  BmwRackToVehCentrOffsSts1 PimBmwRackCentrToVehCentrOffsSts;
  uint8 PimFirstLoopIndcr;
  uint8 PimIniTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevBmwMotAgSelnSt;
  uint8 PimPrevIgnCycBmwMotAgSelnSt;
  uint8 PimPrevIgnCycNtc8CSts;
  uint8 PimPrevIgnCycNtc8ESts;
  uint8 PimPrevIgnCycTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevLoopBmwMotAgSelnSt;
  BmwQuadOffsSts1 PimPrevLoopBmwQuadOffsSts;
  uint8 PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  boolean PimClrNotCmplPinionAgFlg;
  boolean PimCurrDftPinionAgFltPrsnt;
  boolean PimDynStabyCtrlCdn;
  boolean PimKineIntegrityFlt;
  boolean PimLpFilActvd;
  boolean PimMotPosnDegArbdBlndFac;
  boolean PimPrevAllwCorrn;
  boolean PimPrevBmwOffsAuthyFlg;
  boolean PimSetBmwRackCentrToVehCentrOffsTrig;
  boolean PimSigInvldTranTrig;
  boolean PimTurnCntrCorrlnStsTmrTrig;
  boolean PimVehCentrCmpl;
  BmwVehCentrOffsRec1 PimBmwVehCentrOffs;
  FilLpRec1 PimPinionAgFilStVari;

  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data;
  float32 BmwHwAgArbnAndEotPosnMotToHwResl_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data;
  float32 BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint32 BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data;
  uint32 BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data;
  uint16 BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data;
  boolean BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data;

  NvM_RequestResultType Call_BmwVehCentrOffs_GetErrorStatus_ErrorStatus_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwPinionAgOffsRateLim = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim() = PimBmwPinionAgOffsRateLim;
  PimCurrAlgndPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg() = PimCurrAlgndPinionAg;
  PimPinionAgConfRampStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari() = PimPinionAgConfRampStVari;
  PimPrevBmwOffsAuthy = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy() = PimPrevBmwOffsAuthy;
  PimPrevLoopPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg() = PimPrevLoopPinionAg;
  PimPrevPinionAgConf = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf() = PimPrevPinionAgConf;
  PimAllwExitFromInitTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi() = PimAllwExitFromInitTi;
  PimMotPosnDegArbdBlndTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi() = PimMotPosnDegArbdBlndTi;
  PimOffsCorrnRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi() = PimOffsCorrnRefTi;
  PimPinionAgFltRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi() = PimPinionAgFltRefTi;
  PimTurnCntrValTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi() = PimTurnCntrValTi;
  PimBmwRackCentrToVehCentrOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts() = PimBmwRackCentrToVehCentrOffsSts;
  PimFirstLoopIndcr = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr() = PimFirstLoopIndcr;
  PimIniTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts() = PimIniTurnCntrCorrlnSts;
  PimPrevBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt() = PimPrevBmwMotAgSelnSt;
  PimPrevIgnCycBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt() = PimPrevIgnCycBmwMotAgSelnSt;
  PimPrevIgnCycNtc8CSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts() = PimPrevIgnCycNtc8CSts;
  PimPrevIgnCycNtc8ESts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts() = PimPrevIgnCycNtc8ESts;
  PimPrevIgnCycTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() = PimPrevIgnCycTurnCntrCorrlnSts;
  PimPrevLoopBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt() = PimPrevLoopBmwMotAgSelnSt;
  PimPrevLoopBmwQuadOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts() = PimPrevLoopBmwQuadOffsSts;
  PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() = PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  PimClrNotCmplPinionAgFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg() = PimClrNotCmplPinionAgFlg;
  PimCurrDftPinionAgFltPrsnt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt() = PimCurrDftPinionAgFltPrsnt;
  PimDynStabyCtrlCdn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn() = PimDynStabyCtrlCdn;
  PimKineIntegrityFlt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt() = PimKineIntegrityFlt;
  PimLpFilActvd = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd() = PimLpFilActvd;
  PimMotPosnDegArbdBlndFac = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac() = PimMotPosnDegArbdBlndFac;
  PimPrevAllwCorrn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn() = PimPrevAllwCorrn;
  PimPrevBmwOffsAuthyFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg() = PimPrevBmwOffsAuthyFlg;
  PimSetBmwRackCentrToVehCentrOffsTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() = PimSetBmwRackCentrToVehCentrOffsTrig;
  PimSigInvldTranTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig() = PimSigInvldTranTrig;
  PimTurnCntrCorrlnStsTmrTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig() = PimTurnCntrCorrlnStsTmrTrig;
  PimVehCentrCmpl = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl() = PimVehCentrCmpl;
  PimBmwVehCentrOffs = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs() = PimBmwVehCentrOffs;
  PimPinionAgFilStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari() = PimPinionAgFilStVari;

  BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val();
  BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val();
  BmwHwAgArbnAndEotPosnEotCcwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val();
  BmwHwAgArbnAndEotPosnEotCcwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val();
  BmwHwAgArbnAndEotPosnEotCwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val();
  BmwHwAgArbnAndEotPosnEotCwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val();
  BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val();
  BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val();
  BmwHwAgArbnAndEotPosnMotToHwResl_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val();
  BmwHwAgArbnAndEotPosnOffsAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val();
  BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
  BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_SysGlbPrmSysKineRat_Val();
  BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val();
  BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val();
  BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val();
  BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl();

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Call_BmwVehCentrOffs_GetErrorStatus(&Call_BmwVehCentrOffs_GetErrorStatus_ErrorStatus_Arg);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Call_BmwVehCentrOffs_SetRamBlockStatus(FALSE);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_NvMService_AC3_SRBS_E_NOT_OK:
      fct_error = 1;
      break;
  }

  BmwHwAgArbnAndEotPosn_TestDefines();


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

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BmwHwAgOffs_Val;
  float32 Read_BmwPinionAgOffs_Val;
  BmwPinionAgOffsSts1 Read_BmwPinionAgOffsSts_Val;
  BmwQuadOffsSts1 Read_BmwQuadOffsSts_Val;
  boolean Read_BmwQuadOffsStsVld_Logl;
  sint8 Read_BmwQuadRotorOffs_Val;
  boolean Read_BmwQuadRotorOffsVld_Logl;
  BmwVehSpdSts1 Read_BmwVehSpdSts_Val;
  float32 Read_CmplncErrMotToPinion_Val;
  boolean Read_DiKineIntegrityTest_Logl;
  boolean Read_LongTermRackCentrCmpl_Logl;
  s18p13 Read_MotAgCumvAlgndMrf_Val;
  uint8 Read_MotAgMeclCorrlnSt_Val;
  float32 Read_MotAgTurnCntr_Val;
  float32 Read_RackCentrPinionAg_Val;
  float32 Read_TotRackTrvl_Val;
  uint8 Read_TurnCntrCorrlnSts_Val;
  float32 Read_VehSpd_Val;
  boolean Read_VehSpdVld_Logl;

  float32 PimBmwPinionAgOffsRateLim;
  float32 PimCurrAlgndPinionAg;
  float32 PimPinionAgConfRampStVari;
  float32 PimPrevBmwOffsAuthy;
  float32 PimPrevLoopPinionAg;
  float32 PimPrevPinionAgConf;
  uint32 PimAllwExitFromInitTi;
  uint32 PimMotPosnDegArbdBlndTi;
  uint32 PimOffsCorrnRefTi;
  uint32 PimPinionAgFltRefTi;
  uint32 PimTurnCntrValTi;
  BmwRackToVehCentrOffsSts1 PimBmwRackCentrToVehCentrOffsSts;
  uint8 PimFirstLoopIndcr;
  uint8 PimIniTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevBmwMotAgSelnSt;
  uint8 PimPrevIgnCycBmwMotAgSelnSt;
  uint8 PimPrevIgnCycNtc8CSts;
  uint8 PimPrevIgnCycNtc8ESts;
  uint8 PimPrevIgnCycTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevLoopBmwMotAgSelnSt;
  BmwQuadOffsSts1 PimPrevLoopBmwQuadOffsSts;
  uint8 PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  boolean PimClrNotCmplPinionAgFlg;
  boolean PimCurrDftPinionAgFltPrsnt;
  boolean PimDynStabyCtrlCdn;
  boolean PimKineIntegrityFlt;
  boolean PimLpFilActvd;
  boolean PimMotPosnDegArbdBlndFac;
  boolean PimPrevAllwCorrn;
  boolean PimPrevBmwOffsAuthyFlg;
  boolean PimSetBmwRackCentrToVehCentrOffsTrig;
  boolean PimSigInvldTranTrig;
  boolean PimTurnCntrCorrlnStsTmrTrig;
  boolean PimVehCentrCmpl;
  BmwVehCentrOffsRec1 PimBmwVehCentrOffs;
  FilLpRec1 PimPinionAgFilStVari;

  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data;
  float32 BmwHwAgArbnAndEotPosnMotToHwResl_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data;
  float32 BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint32 BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data;
  uint32 BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data;
  uint16 BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data;
  boolean BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data;

  SigQlfr1 Call_GetNtcQlfrSts_Oper_NtcQlfr_Arg = 0U;
  uint32 Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwPinionAgOffsRateLim = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim() = PimBmwPinionAgOffsRateLim;
  PimCurrAlgndPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg() = PimCurrAlgndPinionAg;
  PimPinionAgConfRampStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari() = PimPinionAgConfRampStVari;
  PimPrevBmwOffsAuthy = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy() = PimPrevBmwOffsAuthy;
  PimPrevLoopPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg() = PimPrevLoopPinionAg;
  PimPrevPinionAgConf = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf() = PimPrevPinionAgConf;
  PimAllwExitFromInitTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi() = PimAllwExitFromInitTi;
  PimMotPosnDegArbdBlndTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi() = PimMotPosnDegArbdBlndTi;
  PimOffsCorrnRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi() = PimOffsCorrnRefTi;
  PimPinionAgFltRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi() = PimPinionAgFltRefTi;
  PimTurnCntrValTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi() = PimTurnCntrValTi;
  PimBmwRackCentrToVehCentrOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts() = PimBmwRackCentrToVehCentrOffsSts;
  PimFirstLoopIndcr = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr() = PimFirstLoopIndcr;
  PimIniTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts() = PimIniTurnCntrCorrlnSts;
  PimPrevBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt() = PimPrevBmwMotAgSelnSt;
  PimPrevIgnCycBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt() = PimPrevIgnCycBmwMotAgSelnSt;
  PimPrevIgnCycNtc8CSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts() = PimPrevIgnCycNtc8CSts;
  PimPrevIgnCycNtc8ESts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts() = PimPrevIgnCycNtc8ESts;
  PimPrevIgnCycTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() = PimPrevIgnCycTurnCntrCorrlnSts;
  PimPrevLoopBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt() = PimPrevLoopBmwMotAgSelnSt;
  PimPrevLoopBmwQuadOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts() = PimPrevLoopBmwQuadOffsSts;
  PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() = PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  PimClrNotCmplPinionAgFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg() = PimClrNotCmplPinionAgFlg;
  PimCurrDftPinionAgFltPrsnt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt() = PimCurrDftPinionAgFltPrsnt;
  PimDynStabyCtrlCdn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn() = PimDynStabyCtrlCdn;
  PimKineIntegrityFlt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt() = PimKineIntegrityFlt;
  PimLpFilActvd = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd() = PimLpFilActvd;
  PimMotPosnDegArbdBlndFac = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac() = PimMotPosnDegArbdBlndFac;
  PimPrevAllwCorrn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn() = PimPrevAllwCorrn;
  PimPrevBmwOffsAuthyFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg() = PimPrevBmwOffsAuthyFlg;
  PimSetBmwRackCentrToVehCentrOffsTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() = PimSetBmwRackCentrToVehCentrOffsTrig;
  PimSigInvldTranTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig() = PimSigInvldTranTrig;
  PimTurnCntrCorrlnStsTmrTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig() = PimTurnCntrCorrlnStsTmrTrig;
  PimVehCentrCmpl = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl() = PimVehCentrCmpl;
  PimBmwVehCentrOffs = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs() = PimBmwVehCentrOffs;
  PimPinionAgFilStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari() = PimPinionAgFilStVari;

  BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val();
  BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val();
  BmwHwAgArbnAndEotPosnEotCcwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val();
  BmwHwAgArbnAndEotPosnEotCcwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val();
  BmwHwAgArbnAndEotPosnEotCwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val();
  BmwHwAgArbnAndEotPosnEotCwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val();
  BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val();
  BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val();
  BmwHwAgArbnAndEotPosnMotToHwResl_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val();
  BmwHwAgArbnAndEotPosnOffsAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val();
  BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
  BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_SysGlbPrmSysKineRat_Val();
  BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val();
  BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val();
  BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val();
  BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl();

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwHwAgOffs_Val(&Read_BmwHwAgOffs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwPinionAgOffs_Val(&Read_BmwPinionAgOffs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwPinionAgOffsSts_Val(&Read_BmwPinionAgOffsSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadOffsSts_Val(&Read_BmwQuadOffsSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadOffsStsVld_Logl(&Read_BmwQuadOffsStsVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadRotorOffs_Val(&Read_BmwQuadRotorOffs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwQuadRotorOffsVld_Logl(&Read_BmwQuadRotorOffsVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_BmwVehSpdSts_Val(&Read_BmwVehSpdSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_CmplncErrMotToPinion_Val(&Read_CmplncErrMotToPinion_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_DiKineIntegrityTest_Logl(&Read_DiKineIntegrityTest_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_LongTermRackCentrCmpl_Logl(&Read_LongTermRackCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgCumvAlgndMrf_Val(&Read_MotAgCumvAlgndMrf_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgMeclCorrlnSt_Val(&Read_MotAgMeclCorrlnSt_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_MotAgTurnCntr_Val(&Read_MotAgTurnCntr_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_RackCentrPinionAg_Val(&Read_RackCentrPinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_TotRackTrvl_Val(&Read_TotRackTrvl_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_TurnCntrCorrlnSts_Val(&Read_TurnCntrCorrlnSts_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Read_VehSpdVld_Logl(&Read_VehSpdVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_AlgndPinionAg_Val(Rte_InitValue_AlgndPinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwPinionAg_Val(Rte_InitValue_BmwPinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwPinionAgQlfr_Val(Rte_InitValue_BmwPinionAgQlfr_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwRackCentrToVehCentrOffs_Val(Rte_InitValue_BmwRackCentrToVehCentrOffs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_BmwRackCentrToVehCentrOffsVld_Logl(Rte_InitValue_BmwRackCentrToVehCentrOffsVld_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgCcwDetd_Logl(Rte_InitValue_HwAgCcwDetd_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgCwDetd_Logl(Rte_InitValue_HwAgCwDetd_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgEotCcw_Val(Rte_InitValue_HwAgEotCcw_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_HwAgEotCw_Val(Rte_InitValue_HwAgEotCw_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_LongTermVehCentrCmpl_Logl(Rte_InitValue_LongTermVehCentrCmpl_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_OffsCmpdPinionAg_Val(Rte_InitValue_OffsCmpdPinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_PinionAg_Val(Rte_InitValue_PinionAg_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Write_PinionAgConf_Val(Rte_InitValue_PinionAgConf_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetNtcQlfrSts_Oper(0U, &Call_GetNtcQlfrSts_Oper_NtcQlfr_Arg);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetRefTmr100MicroSec32bit_Oper(&Call_GetRefTmr100MicroSec32bit_Oper_RefTmr_Arg);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Call_GetTiSpan100MicroSec32bit_Oper(0U, &Call_GetTiSpan100MicroSec32bit_Oper_TiSpan_Arg);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Call_RstRackCentrMotRev_Oper();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwHwAgArbnAndEotPosn_Rte_Call_SetNtcSts_Oper(0U, 0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_SetNtcSts_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }


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

  float32 PimBmwPinionAgOffsRateLim;
  float32 PimCurrAlgndPinionAg;
  float32 PimPinionAgConfRampStVari;
  float32 PimPrevBmwOffsAuthy;
  float32 PimPrevLoopPinionAg;
  float32 PimPrevPinionAgConf;
  uint32 PimAllwExitFromInitTi;
  uint32 PimMotPosnDegArbdBlndTi;
  uint32 PimOffsCorrnRefTi;
  uint32 PimPinionAgFltRefTi;
  uint32 PimTurnCntrValTi;
  BmwRackToVehCentrOffsSts1 PimBmwRackCentrToVehCentrOffsSts;
  uint8 PimFirstLoopIndcr;
  uint8 PimIniTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevBmwMotAgSelnSt;
  uint8 PimPrevIgnCycBmwMotAgSelnSt;
  uint8 PimPrevIgnCycNtc8CSts;
  uint8 PimPrevIgnCycNtc8ESts;
  uint8 PimPrevIgnCycTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevLoopBmwMotAgSelnSt;
  BmwQuadOffsSts1 PimPrevLoopBmwQuadOffsSts;
  uint8 PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  boolean PimClrNotCmplPinionAgFlg;
  boolean PimCurrDftPinionAgFltPrsnt;
  boolean PimDynStabyCtrlCdn;
  boolean PimKineIntegrityFlt;
  boolean PimLpFilActvd;
  boolean PimMotPosnDegArbdBlndFac;
  boolean PimPrevAllwCorrn;
  boolean PimPrevBmwOffsAuthyFlg;
  boolean PimSetBmwRackCentrToVehCentrOffsTrig;
  boolean PimSigInvldTranTrig;
  boolean PimTurnCntrCorrlnStsTmrTrig;
  boolean PimVehCentrCmpl;
  BmwVehCentrOffsRec1 PimBmwVehCentrOffs;
  FilLpRec1 PimPinionAgFilStVari;

  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data;
  float32 BmwHwAgArbnAndEotPosnMotToHwResl_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data;
  float32 BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint32 BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data;
  uint32 BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data;
  uint16 BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data;
  boolean BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwPinionAgOffsRateLim = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim() = PimBmwPinionAgOffsRateLim;
  PimCurrAlgndPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg() = PimCurrAlgndPinionAg;
  PimPinionAgConfRampStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari() = PimPinionAgConfRampStVari;
  PimPrevBmwOffsAuthy = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy() = PimPrevBmwOffsAuthy;
  PimPrevLoopPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg() = PimPrevLoopPinionAg;
  PimPrevPinionAgConf = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf() = PimPrevPinionAgConf;
  PimAllwExitFromInitTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi() = PimAllwExitFromInitTi;
  PimMotPosnDegArbdBlndTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi() = PimMotPosnDegArbdBlndTi;
  PimOffsCorrnRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi() = PimOffsCorrnRefTi;
  PimPinionAgFltRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi() = PimPinionAgFltRefTi;
  PimTurnCntrValTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi() = PimTurnCntrValTi;
  PimBmwRackCentrToVehCentrOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts() = PimBmwRackCentrToVehCentrOffsSts;
  PimFirstLoopIndcr = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr() = PimFirstLoopIndcr;
  PimIniTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts() = PimIniTurnCntrCorrlnSts;
  PimPrevBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt() = PimPrevBmwMotAgSelnSt;
  PimPrevIgnCycBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt() = PimPrevIgnCycBmwMotAgSelnSt;
  PimPrevIgnCycNtc8CSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts() = PimPrevIgnCycNtc8CSts;
  PimPrevIgnCycNtc8ESts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts() = PimPrevIgnCycNtc8ESts;
  PimPrevIgnCycTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() = PimPrevIgnCycTurnCntrCorrlnSts;
  PimPrevLoopBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt() = PimPrevLoopBmwMotAgSelnSt;
  PimPrevLoopBmwQuadOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts() = PimPrevLoopBmwQuadOffsSts;
  PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() = PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  PimClrNotCmplPinionAgFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg() = PimClrNotCmplPinionAgFlg;
  PimCurrDftPinionAgFltPrsnt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt() = PimCurrDftPinionAgFltPrsnt;
  PimDynStabyCtrlCdn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn() = PimDynStabyCtrlCdn;
  PimKineIntegrityFlt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt() = PimKineIntegrityFlt;
  PimLpFilActvd = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd() = PimLpFilActvd;
  PimMotPosnDegArbdBlndFac = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac() = PimMotPosnDegArbdBlndFac;
  PimPrevAllwCorrn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn() = PimPrevAllwCorrn;
  PimPrevBmwOffsAuthyFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg() = PimPrevBmwOffsAuthyFlg;
  PimSetBmwRackCentrToVehCentrOffsTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() = PimSetBmwRackCentrToVehCentrOffsTrig;
  PimSigInvldTranTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig() = PimSigInvldTranTrig;
  PimTurnCntrCorrlnStsTmrTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig() = PimTurnCntrCorrlnStsTmrTrig;
  PimVehCentrCmpl = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl() = PimVehCentrCmpl;
  PimBmwVehCentrOffs = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs() = PimBmwVehCentrOffs;
  PimPinionAgFilStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari() = PimPinionAgFilStVari;

  BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val();
  BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val();
  BmwHwAgArbnAndEotPosnEotCcwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val();
  BmwHwAgArbnAndEotPosnEotCcwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val();
  BmwHwAgArbnAndEotPosnEotCwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val();
  BmwHwAgArbnAndEotPosnEotCwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val();
  BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val();
  BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val();
  BmwHwAgArbnAndEotPosnMotToHwResl_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val();
  BmwHwAgArbnAndEotPosnOffsAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val();
  BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
  BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_SysGlbPrmSysKineRat_Val();
  BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val();
  BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val();
  BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val();
  BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl();


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

  float32 PimBmwPinionAgOffsRateLim;
  float32 PimCurrAlgndPinionAg;
  float32 PimPinionAgConfRampStVari;
  float32 PimPrevBmwOffsAuthy;
  float32 PimPrevLoopPinionAg;
  float32 PimPrevPinionAgConf;
  uint32 PimAllwExitFromInitTi;
  uint32 PimMotPosnDegArbdBlndTi;
  uint32 PimOffsCorrnRefTi;
  uint32 PimPinionAgFltRefTi;
  uint32 PimTurnCntrValTi;
  BmwRackToVehCentrOffsSts1 PimBmwRackCentrToVehCentrOffsSts;
  uint8 PimFirstLoopIndcr;
  uint8 PimIniTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevBmwMotAgSelnSt;
  uint8 PimPrevIgnCycBmwMotAgSelnSt;
  uint8 PimPrevIgnCycNtc8CSts;
  uint8 PimPrevIgnCycNtc8ESts;
  uint8 PimPrevIgnCycTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevLoopBmwMotAgSelnSt;
  BmwQuadOffsSts1 PimPrevLoopBmwQuadOffsSts;
  uint8 PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  boolean PimClrNotCmplPinionAgFlg;
  boolean PimCurrDftPinionAgFltPrsnt;
  boolean PimDynStabyCtrlCdn;
  boolean PimKineIntegrityFlt;
  boolean PimLpFilActvd;
  boolean PimMotPosnDegArbdBlndFac;
  boolean PimPrevAllwCorrn;
  boolean PimPrevBmwOffsAuthyFlg;
  boolean PimSetBmwRackCentrToVehCentrOffsTrig;
  boolean PimSigInvldTranTrig;
  boolean PimTurnCntrCorrlnStsTmrTrig;
  boolean PimVehCentrCmpl;
  BmwVehCentrOffsRec1 PimBmwVehCentrOffs;
  FilLpRec1 PimPinionAgFilStVari;

  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data;
  float32 BmwHwAgArbnAndEotPosnMotToHwResl_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data;
  float32 BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint32 BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data;
  uint32 BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data;
  uint16 BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data;
  boolean BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwPinionAgOffsRateLim = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim() = PimBmwPinionAgOffsRateLim;
  PimCurrAlgndPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg() = PimCurrAlgndPinionAg;
  PimPinionAgConfRampStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari() = PimPinionAgConfRampStVari;
  PimPrevBmwOffsAuthy = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy() = PimPrevBmwOffsAuthy;
  PimPrevLoopPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg() = PimPrevLoopPinionAg;
  PimPrevPinionAgConf = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf() = PimPrevPinionAgConf;
  PimAllwExitFromInitTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi() = PimAllwExitFromInitTi;
  PimMotPosnDegArbdBlndTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi() = PimMotPosnDegArbdBlndTi;
  PimOffsCorrnRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi() = PimOffsCorrnRefTi;
  PimPinionAgFltRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi() = PimPinionAgFltRefTi;
  PimTurnCntrValTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi() = PimTurnCntrValTi;
  PimBmwRackCentrToVehCentrOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts() = PimBmwRackCentrToVehCentrOffsSts;
  PimFirstLoopIndcr = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr() = PimFirstLoopIndcr;
  PimIniTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts() = PimIniTurnCntrCorrlnSts;
  PimPrevBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt() = PimPrevBmwMotAgSelnSt;
  PimPrevIgnCycBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt() = PimPrevIgnCycBmwMotAgSelnSt;
  PimPrevIgnCycNtc8CSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts() = PimPrevIgnCycNtc8CSts;
  PimPrevIgnCycNtc8ESts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts() = PimPrevIgnCycNtc8ESts;
  PimPrevIgnCycTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() = PimPrevIgnCycTurnCntrCorrlnSts;
  PimPrevLoopBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt() = PimPrevLoopBmwMotAgSelnSt;
  PimPrevLoopBmwQuadOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts() = PimPrevLoopBmwQuadOffsSts;
  PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() = PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  PimClrNotCmplPinionAgFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg() = PimClrNotCmplPinionAgFlg;
  PimCurrDftPinionAgFltPrsnt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt() = PimCurrDftPinionAgFltPrsnt;
  PimDynStabyCtrlCdn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn() = PimDynStabyCtrlCdn;
  PimKineIntegrityFlt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt() = PimKineIntegrityFlt;
  PimLpFilActvd = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd() = PimLpFilActvd;
  PimMotPosnDegArbdBlndFac = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac() = PimMotPosnDegArbdBlndFac;
  PimPrevAllwCorrn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn() = PimPrevAllwCorrn;
  PimPrevBmwOffsAuthyFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg() = PimPrevBmwOffsAuthyFlg;
  PimSetBmwRackCentrToVehCentrOffsTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() = PimSetBmwRackCentrToVehCentrOffsTrig;
  PimSigInvldTranTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig() = PimSigInvldTranTrig;
  PimTurnCntrCorrlnStsTmrTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig() = PimTurnCntrCorrlnStsTmrTrig;
  PimVehCentrCmpl = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl() = PimVehCentrCmpl;
  PimBmwVehCentrOffs = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs() = PimBmwVehCentrOffs;
  PimPinionAgFilStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari() = PimPinionAgFilStVari;

  BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val();
  BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val();
  BmwHwAgArbnAndEotPosnEotCcwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val();
  BmwHwAgArbnAndEotPosnEotCcwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val();
  BmwHwAgArbnAndEotPosnEotCwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val();
  BmwHwAgArbnAndEotPosnEotCwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val();
  BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val();
  BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val();
  BmwHwAgArbnAndEotPosnMotToHwResl_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val();
  BmwHwAgArbnAndEotPosnOffsAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val();
  BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
  BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_SysGlbPrmSysKineRat_Val();
  BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val();
  BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val();
  BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val();
  BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl();


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

  float32 PimBmwPinionAgOffsRateLim;
  float32 PimCurrAlgndPinionAg;
  float32 PimPinionAgConfRampStVari;
  float32 PimPrevBmwOffsAuthy;
  float32 PimPrevLoopPinionAg;
  float32 PimPrevPinionAgConf;
  uint32 PimAllwExitFromInitTi;
  uint32 PimMotPosnDegArbdBlndTi;
  uint32 PimOffsCorrnRefTi;
  uint32 PimPinionAgFltRefTi;
  uint32 PimTurnCntrValTi;
  BmwRackToVehCentrOffsSts1 PimBmwRackCentrToVehCentrOffsSts;
  uint8 PimFirstLoopIndcr;
  uint8 PimIniTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevBmwMotAgSelnSt;
  uint8 PimPrevIgnCycBmwMotAgSelnSt;
  uint8 PimPrevIgnCycNtc8CSts;
  uint8 PimPrevIgnCycNtc8ESts;
  uint8 PimPrevIgnCycTurnCntrCorrlnSts;
  BmwMotAgSelnSt1 PimPrevLoopBmwMotAgSelnSt;
  BmwQuadOffsSts1 PimPrevLoopBmwQuadOffsSts;
  uint8 PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  boolean PimClrNotCmplPinionAgFlg;
  boolean PimCurrDftPinionAgFltPrsnt;
  boolean PimDynStabyCtrlCdn;
  boolean PimKineIntegrityFlt;
  boolean PimLpFilActvd;
  boolean PimMotPosnDegArbdBlndFac;
  boolean PimPrevAllwCorrn;
  boolean PimPrevBmwOffsAuthyFlg;
  boolean PimSetBmwRackCentrToVehCentrOffsTrig;
  boolean PimSigInvldTranTrig;
  boolean PimTurnCntrCorrlnStsTmrTrig;
  boolean PimVehCentrCmpl;
  BmwVehCentrOffsRec1 PimBmwVehCentrOffs;
  FilLpRec1 PimPinionAgFilStVari;

  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCcwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMax_Val_data;
  float32 BmwHwAgArbnAndEotPosnEotCwMin_Val_data;
  float32 BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data;
  float32 BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data;
  float32 BmwHwAgArbnAndEotPosnMotToHwResl_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data;
  float32 BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data;
  float32 BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data;
  float32 BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data;
  float32 SysGlbPrmSysKineRat_Val_data;
  uint32 BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data;
  uint32 BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data;
  uint16 BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data;
  uint16 BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data;
  boolean BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimBmwPinionAgOffsRateLim = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwPinionAgOffsRateLim() = PimBmwPinionAgOffsRateLim;
  PimCurrAlgndPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrAlgndPinionAg() = PimCurrAlgndPinionAg;
  PimPinionAgConfRampStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgConfRampStVari() = PimPinionAgConfRampStVari;
  PimPrevBmwOffsAuthy = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthy() = PimPrevBmwOffsAuthy;
  PimPrevLoopPinionAg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopPinionAg() = PimPrevLoopPinionAg;
  PimPrevPinionAgConf = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevPinionAgConf() = PimPrevPinionAgConf;
  PimAllwExitFromInitTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_AllwExitFromInitTi() = PimAllwExitFromInitTi;
  PimMotPosnDegArbdBlndTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndTi() = PimMotPosnDegArbdBlndTi;
  PimOffsCorrnRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_OffsCorrnRefTi() = PimOffsCorrnRefTi;
  PimPinionAgFltRefTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFltRefTi() = PimPinionAgFltRefTi;
  PimTurnCntrValTi = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrValTi() = PimTurnCntrValTi;
  PimBmwRackCentrToVehCentrOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwRackCentrToVehCentrOffsSts() = PimBmwRackCentrToVehCentrOffsSts;
  PimFirstLoopIndcr = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_FirstLoopIndcr() = PimFirstLoopIndcr;
  PimIniTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_IniTurnCntrCorrlnSts() = PimIniTurnCntrCorrlnSts;
  PimPrevBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwMotAgSelnSt() = PimPrevBmwMotAgSelnSt;
  PimPrevIgnCycBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycBmwMotAgSelnSt() = PimPrevIgnCycBmwMotAgSelnSt;
  PimPrevIgnCycNtc8CSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8CSts() = PimPrevIgnCycNtc8CSts;
  PimPrevIgnCycNtc8ESts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycNtc8ESts() = PimPrevIgnCycNtc8ESts;
  PimPrevIgnCycTurnCntrCorrlnSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevIgnCycTurnCntrCorrlnSts() = PimPrevIgnCycTurnCntrCorrlnSts;
  PimPrevLoopBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwMotAgSelnSt() = PimPrevLoopBmwMotAgSelnSt;
  PimPrevLoopBmwQuadOffsSts = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevLoopBmwQuadOffsSts() = PimPrevLoopBmwQuadOffsSts;
  PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_dBmwHwAgArbnAndEotPosnBmwMotAgSelnSt() = PimdBmwHwAgArbnAndEotPosnBmwMotAgSelnSt;
  PimClrNotCmplPinionAgFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_ClrNotCmplPinionAgFlg() = PimClrNotCmplPinionAgFlg;
  PimCurrDftPinionAgFltPrsnt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_CurrDftPinionAgFltPrsnt() = PimCurrDftPinionAgFltPrsnt;
  PimDynStabyCtrlCdn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_DynStabyCtrlCdn() = PimDynStabyCtrlCdn;
  PimKineIntegrityFlt = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_KineIntegrityFlt() = PimKineIntegrityFlt;
  PimLpFilActvd = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_LpFilActvd() = PimLpFilActvd;
  PimMotPosnDegArbdBlndFac = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_MotPosnDegArbdBlndFac() = PimMotPosnDegArbdBlndFac;
  PimPrevAllwCorrn = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevAllwCorrn() = PimPrevAllwCorrn;
  PimPrevBmwOffsAuthyFlg = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PrevBmwOffsAuthyFlg() = PimPrevBmwOffsAuthyFlg;
  PimSetBmwRackCentrToVehCentrOffsTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SetBmwRackCentrToVehCentrOffsTrig() = PimSetBmwRackCentrToVehCentrOffsTrig;
  PimSigInvldTranTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_SigInvldTranTrig() = PimSigInvldTranTrig;
  PimTurnCntrCorrlnStsTmrTrig = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_TurnCntrCorrlnStsTmrTrig() = PimTurnCntrCorrlnStsTmrTrig;
  PimVehCentrCmpl = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_VehCentrCmpl() = PimVehCentrCmpl;
  PimBmwVehCentrOffs = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_BmwVehCentrOffs() = PimBmwVehCentrOffs;
  PimPinionAgFilStVari = *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari();
  *TSC_BmwHwAgArbnAndEotPosn_Rte_Pim_PinionAgFilStVari() = PimPinionAgFilStVari;

  BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsLim_Val();
  BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnBmwPinionAgOffsRateLim_Val();
  BmwHwAgArbnAndEotPosnEotCcwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMax_Val();
  BmwHwAgArbnAndEotPosnEotCcwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCcwMin_Val();
  BmwHwAgArbnAndEotPosnEotCwMax_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMax_Val();
  BmwHwAgArbnAndEotPosnEotCwMin_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnEotCwMin_Val();
  BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnKineIntegrityDiagcMaxRackLim_Val();
  BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMinVehSpdReqdVldAbsPos_Val();
  BmwHwAgArbnAndEotPosnMotToHwResl_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotToHwResl_Val();
  BmwHwAgArbnAndEotPosnOffsAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsAuthy_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnAuthy_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampDwnRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgConfRampUpRate_Val();
  BmwHwAgArbnAndEotPosnPinionAgDifThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgDifThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFilFrq_Val();
  BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTmpCmpdAuthy_Val();
  BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrAuthy_Val();
  SysGlbPrmSysKineRat_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_SysGlbPrmSysKineRat_Val();
  BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnMotPosnDegArbdBlnd_Val();
  BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnTurnCntrCorrlnStsTmrThd_Val();
  BmwHwAgArbnAndEotPosnAllwExitFromInit_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnAllwExitFromInit_Val();
  BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnOffsCorrnTmrThd_Val();
  BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnPinionAgFltTmrThd_Val();
  BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl_data = TSC_BmwHwAgArbnAndEotPosn_Rte_Prm_BmwHwAgArbnAndEotPosnSysPolarityAssi_Logl();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwHwAgArbnAndEotPosn_STOP_SEC_CODE
#include "BmwHwAgArbnAndEotPosn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwHwAgArbnAndEotPosn_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwMotAgSelnSt1 Test_BmwMotAgSelnSt1_V_1 = BMWMOTAGSELNST_OFFSCMPD;
  BmwMotAgSelnSt1 Test_BmwMotAgSelnSt1_V_2 = BMWMOTAGSELNST_SUBVAL;
  BmwMotAgSelnSt1 Test_BmwMotAgSelnSt1_V_3 = BMWMOTAGSELNST_INI;
  BmwMotAgSelnSt1 Test_BmwMotAgSelnSt1_V_4 = BMWMOTAGSELNST_TMPCMPD;
  BmwMotAgSelnSt1 Test_BmwMotAgSelnSt1_V_5 = BMWMOTAGSELNST_OFFSCORRN;
  BmwMotAgSelnSt1 Test_BmwMotAgSelnSt1_V_6 = BMWMOTAGSELNST_SIGINVLD;
  BmwMotAgSelnSt1 Test_BmwMotAgSelnSt1_V_7 = BMWMOTAGSELNST_INVLD;

  BmwPinionAgOffsSts1 Test_BmwPinionAgOffsSts1_V_1 = BMWPINIONAGOFFSSTS_VLD;
  BmwPinionAgOffsSts1 Test_BmwPinionAgOffsSts1_V_2 = BMWPINIONAGOFFSSTS_FCTIFNOTAVL;
  BmwPinionAgOffsSts1 Test_BmwPinionAgOffsSts1_V_3 = BMWPINIONAGOFFSSTS_FCTRPRTERR;
  BmwPinionAgOffsSts1 Test_BmwPinionAgOffsSts1_V_4 = BMWPINIONAGOFFSSTS_INVLD;

  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_1 = BMWPINIONAGQLFR_SIGVALVLDANDPLAUS;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_2 = BMWPINIONAGQLFR_SIGVALVLD;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_3 = BMWPINIONAGQLFR_SUBVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_4 = BMWPINIONAGQLFR_INIT;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_5 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_6 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_7 = BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_8 = BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_9 = BMWPINIONAGQLFR_INVLDSIG;

  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_1 = BMWQUADOFFSSTS_ALGSLEEP;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_2 = BMWQUADOFFSSTS_OFFSKWN;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_3 = BMWQUADOFFSSTS_OFFSBYIDX;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_4 = BMWQUADOFFSSTS_OFFSBYMDLCOMP;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_5 = BMWQUADOFFSSTS_OFFSPOSNGBYSTRTSTOP;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_6 = BMWQUADOFFSSTS_OFFSPOSNGBYSUMCTRLAG;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_7 = BMWQUADOFFSSTS_OFFSINTEST;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_8 = BMWQUADOFFSSTS_CORROFFS;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_9 = BMWQUADOFFSSTS_ININ;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_10 = BMWQUADOFFSSTS_RSTOFFSKWN;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_11 = BMWQUADOFFSSTS_OFFSBYMDL;
  BmwQuadOffsSts1 Test_BmwQuadOffsSts1_V_12 = BMWQUADOFFSSTS_INVLD;

  BmwRackToVehCentrOffsSts1 Test_BmwRackToVehCentrOffsSts1_V_1 = BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRINVLD;
  BmwRackToVehCentrOffsSts1 Test_BmwRackToVehCentrOffsSts1_V_2 = BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRLRND;
  BmwRackToVehCentrOffsSts1 Test_BmwRackToVehCentrOffsSts1_V_3 = BMWRACKTOVEHCENTROFFSSTS_RACKTOVEHCENTRUNLRND;

  BmwSetVehCentrOffsSts1 Test_BmwSetVehCentrOffsSts1_V_1 = BMWVEHCENTROFFSSTS_OFFSPRFMD;
  BmwSetVehCentrOffsSts1 Test_BmwSetVehCentrOffsSts1_V_2 = BMWVEHCENTROFFSSTS_OFFSFAILD;
  BmwSetVehCentrOffsSts1 Test_BmwSetVehCentrOffsSts1_V_3 = BMWVEHCENTROFFSSTS_OFFSFAILDVALOUTOFRNG;

  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_1 = BMWVEHSPDSTS_VLD;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_2 = BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHSTANDG;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_3 = BMWVEHSPDSTS_SUBVALSETINUSFLSIGVEHRUNNG;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_4 = BMWVEHSPDSTS_SUBVALSETINUSRSIGNOINFO;
  BmwVehSpdSts1 Test_BmwVehSpdSts1_V_5 = BMWVEHSPDSTS_INVLD;

  NtcNr1 Test_NtcNr1_V_1 = NTCNR_0X001;
  NtcNr1 Test_NtcNr1_V_2 = NTCNR_0X002;
  NtcNr1 Test_NtcNr1_V_3 = NTCNR_0X003;
  NtcNr1 Test_NtcNr1_V_4 = NTCNR_0X004;
  NtcNr1 Test_NtcNr1_V_5 = NTCNR_0X005;
  NtcNr1 Test_NtcNr1_V_6 = NTCNR_0X006;
  NtcNr1 Test_NtcNr1_V_7 = NTCNR_0X007;
  NtcNr1 Test_NtcNr1_V_8 = NTCNR_0X008;
  NtcNr1 Test_NtcNr1_V_9 = NTCNR_0X009;
  NtcNr1 Test_NtcNr1_V_10 = NTCNR_0X00A;
  NtcNr1 Test_NtcNr1_V_11 = NTCNR_0X00B;
  NtcNr1 Test_NtcNr1_V_12 = NTCNR_0X00C;
  NtcNr1 Test_NtcNr1_V_13 = NTCNR_0X00D;
  NtcNr1 Test_NtcNr1_V_14 = NTCNR_0X00E;
  NtcNr1 Test_NtcNr1_V_15 = NTCNR_0X00F;
  NtcNr1 Test_NtcNr1_V_16 = NTCNR_0X010;
  NtcNr1 Test_NtcNr1_V_17 = NTCNR_0X011;
  NtcNr1 Test_NtcNr1_V_18 = NTCNR_0X012;
  NtcNr1 Test_NtcNr1_V_19 = NTCNR_0X013;
  NtcNr1 Test_NtcNr1_V_20 = NTCNR_0X014;
  NtcNr1 Test_NtcNr1_V_21 = NTCNR_0X015;
  NtcNr1 Test_NtcNr1_V_22 = NTCNR_0X016;
  NtcNr1 Test_NtcNr1_V_23 = NTCNR_0X017;
  NtcNr1 Test_NtcNr1_V_24 = NTCNR_0X018;
  NtcNr1 Test_NtcNr1_V_25 = NTCNR_0X019;
  NtcNr1 Test_NtcNr1_V_26 = NTCNR_0X01A;
  NtcNr1 Test_NtcNr1_V_27 = NTCNR_0X01B;
  NtcNr1 Test_NtcNr1_V_28 = NTCNR_0X01C;
  NtcNr1 Test_NtcNr1_V_29 = NTCNR_0X01D;
  NtcNr1 Test_NtcNr1_V_30 = NTCNR_0X01E;
  NtcNr1 Test_NtcNr1_V_31 = NTCNR_0X01F;
  NtcNr1 Test_NtcNr1_V_32 = NTCNR_0X020;
  NtcNr1 Test_NtcNr1_V_33 = NTCNR_0X021;
  NtcNr1 Test_NtcNr1_V_34 = NTCNR_0X022;
  NtcNr1 Test_NtcNr1_V_35 = NTCNR_0X023;
  NtcNr1 Test_NtcNr1_V_36 = NTCNR_0X024;
  NtcNr1 Test_NtcNr1_V_37 = NTCNR_0X025;
  NtcNr1 Test_NtcNr1_V_38 = NTCNR_0X026;
  NtcNr1 Test_NtcNr1_V_39 = NTCNR_0X027;
  NtcNr1 Test_NtcNr1_V_40 = NTCNR_0X028;
  NtcNr1 Test_NtcNr1_V_41 = NTCNR_0X029;
  NtcNr1 Test_NtcNr1_V_42 = NTCNR_0X02A;
  NtcNr1 Test_NtcNr1_V_43 = NTCNR_0X02B;
  NtcNr1 Test_NtcNr1_V_44 = NTCNR_0X02C;
  NtcNr1 Test_NtcNr1_V_45 = NTCNR_0X02D;
  NtcNr1 Test_NtcNr1_V_46 = NTCNR_0X02E;
  NtcNr1 Test_NtcNr1_V_47 = NTCNR_0X02F;
  NtcNr1 Test_NtcNr1_V_48 = NTCNR_0X030;
  NtcNr1 Test_NtcNr1_V_49 = NTCNR_0X031;
  NtcNr1 Test_NtcNr1_V_50 = NTCNR_0X032;
  NtcNr1 Test_NtcNr1_V_51 = NTCNR_0X033;
  NtcNr1 Test_NtcNr1_V_52 = NTCNR_0X034;
  NtcNr1 Test_NtcNr1_V_53 = NTCNR_0X035;
  NtcNr1 Test_NtcNr1_V_54 = NTCNR_0X036;
  NtcNr1 Test_NtcNr1_V_55 = NTCNR_0X037;
  NtcNr1 Test_NtcNr1_V_56 = NTCNR_0X038;
  NtcNr1 Test_NtcNr1_V_57 = NTCNR_0X039;
  NtcNr1 Test_NtcNr1_V_58 = NTCNR_0X03A;
  NtcNr1 Test_NtcNr1_V_59 = NTCNR_0X03B;
  NtcNr1 Test_NtcNr1_V_60 = NTCNR_0X03C;
  NtcNr1 Test_NtcNr1_V_61 = NTCNR_0X03D;
  NtcNr1 Test_NtcNr1_V_62 = NTCNR_0X03E;
  NtcNr1 Test_NtcNr1_V_63 = NTCNR_0X03F;
  NtcNr1 Test_NtcNr1_V_64 = NTCNR_0X040;
  NtcNr1 Test_NtcNr1_V_65 = NTCNR_0X041;
  NtcNr1 Test_NtcNr1_V_66 = NTCNR_0X042;
  NtcNr1 Test_NtcNr1_V_67 = NTCNR_0X043;
  NtcNr1 Test_NtcNr1_V_68 = NTCNR_0X044;
  NtcNr1 Test_NtcNr1_V_69 = NTCNR_0X045;
  NtcNr1 Test_NtcNr1_V_70 = NTCNR_0X046;
  NtcNr1 Test_NtcNr1_V_71 = NTCNR_0X047;
  NtcNr1 Test_NtcNr1_V_72 = NTCNR_0X048;
  NtcNr1 Test_NtcNr1_V_73 = NTCNR_0X049;
  NtcNr1 Test_NtcNr1_V_74 = NTCNR_0X04A;
  NtcNr1 Test_NtcNr1_V_75 = NTCNR_0X04B;
  NtcNr1 Test_NtcNr1_V_76 = NTCNR_0X04C;
  NtcNr1 Test_NtcNr1_V_77 = NTCNR_0X04D;
  NtcNr1 Test_NtcNr1_V_78 = NTCNR_0X04E;
  NtcNr1 Test_NtcNr1_V_79 = NTCNR_0X04F;
  NtcNr1 Test_NtcNr1_V_80 = NTCNR_0X050;
  NtcNr1 Test_NtcNr1_V_81 = NTCNR_0X051;
  NtcNr1 Test_NtcNr1_V_82 = NTCNR_0X052;
  NtcNr1 Test_NtcNr1_V_83 = NTCNR_0X053;
  NtcNr1 Test_NtcNr1_V_84 = NTCNR_0X054;
  NtcNr1 Test_NtcNr1_V_85 = NTCNR_0X055;
  NtcNr1 Test_NtcNr1_V_86 = NTCNR_0X056;
  NtcNr1 Test_NtcNr1_V_87 = NTCNR_0X057;
  NtcNr1 Test_NtcNr1_V_88 = NTCNR_0X058;
  NtcNr1 Test_NtcNr1_V_89 = NTCNR_0X059;
  NtcNr1 Test_NtcNr1_V_90 = NTCNR_0X05A;
  NtcNr1 Test_NtcNr1_V_91 = NTCNR_0X05B;
  NtcNr1 Test_NtcNr1_V_92 = NTCNR_0X05C;
  NtcNr1 Test_NtcNr1_V_93 = NTCNR_0X05D;
  NtcNr1 Test_NtcNr1_V_94 = NTCNR_0X05E;
  NtcNr1 Test_NtcNr1_V_95 = NTCNR_0X05F;
  NtcNr1 Test_NtcNr1_V_96 = NTCNR_0X060;
  NtcNr1 Test_NtcNr1_V_97 = NTCNR_0X061;
  NtcNr1 Test_NtcNr1_V_98 = NTCNR_0X062;
  NtcNr1 Test_NtcNr1_V_99 = NTCNR_0X063;
  NtcNr1 Test_NtcNr1_V_100 = NTCNR_0X064;
  NtcNr1 Test_NtcNr1_V_101 = NTCNR_0X065;
  NtcNr1 Test_NtcNr1_V_102 = NTCNR_0X066;
  NtcNr1 Test_NtcNr1_V_103 = NTCNR_0X067;
  NtcNr1 Test_NtcNr1_V_104 = NTCNR_0X068;
  NtcNr1 Test_NtcNr1_V_105 = NTCNR_0X069;
  NtcNr1 Test_NtcNr1_V_106 = NTCNR_0X06A;
  NtcNr1 Test_NtcNr1_V_107 = NTCNR_0X06B;
  NtcNr1 Test_NtcNr1_V_108 = NTCNR_0X06C;
  NtcNr1 Test_NtcNr1_V_109 = NTCNR_0X06D;
  NtcNr1 Test_NtcNr1_V_110 = NTCNR_0X06E;
  NtcNr1 Test_NtcNr1_V_111 = NTCNR_0X06F;
  NtcNr1 Test_NtcNr1_V_112 = NTCNR_0X070;
  NtcNr1 Test_NtcNr1_V_113 = NTCNR_0X071;
  NtcNr1 Test_NtcNr1_V_114 = NTCNR_0X072;
  NtcNr1 Test_NtcNr1_V_115 = NTCNR_0X073;
  NtcNr1 Test_NtcNr1_V_116 = NTCNR_0X074;
  NtcNr1 Test_NtcNr1_V_117 = NTCNR_0X075;
  NtcNr1 Test_NtcNr1_V_118 = NTCNR_0X076;
  NtcNr1 Test_NtcNr1_V_119 = NTCNR_0X077;
  NtcNr1 Test_NtcNr1_V_120 = NTCNR_0X078;
  NtcNr1 Test_NtcNr1_V_121 = NTCNR_0X079;
  NtcNr1 Test_NtcNr1_V_122 = NTCNR_0X07A;
  NtcNr1 Test_NtcNr1_V_123 = NTCNR_0X07B;
  NtcNr1 Test_NtcNr1_V_124 = NTCNR_0X07C;
  NtcNr1 Test_NtcNr1_V_125 = NTCNR_0X07D;
  NtcNr1 Test_NtcNr1_V_126 = NTCNR_0X07E;
  NtcNr1 Test_NtcNr1_V_127 = NTCNR_0X07F;
  NtcNr1 Test_NtcNr1_V_128 = NTCNR_0X080;
  NtcNr1 Test_NtcNr1_V_129 = NTCNR_0X081;
  NtcNr1 Test_NtcNr1_V_130 = NTCNR_0X082;
  NtcNr1 Test_NtcNr1_V_131 = NTCNR_0X083;
  NtcNr1 Test_NtcNr1_V_132 = NTCNR_0X084;
  NtcNr1 Test_NtcNr1_V_133 = NTCNR_0X085;
  NtcNr1 Test_NtcNr1_V_134 = NTCNR_0X086;
  NtcNr1 Test_NtcNr1_V_135 = NTCNR_0X087;
  NtcNr1 Test_NtcNr1_V_136 = NTCNR_0X088;
  NtcNr1 Test_NtcNr1_V_137 = NTCNR_0X089;
  NtcNr1 Test_NtcNr1_V_138 = NTCNR_0X08A;
  NtcNr1 Test_NtcNr1_V_139 = NTCNR_0X08B;
  NtcNr1 Test_NtcNr1_V_140 = NTCNR_0X08C;
  NtcNr1 Test_NtcNr1_V_141 = NTCNR_0X08D;
  NtcNr1 Test_NtcNr1_V_142 = NTCNR_0X08E;
  NtcNr1 Test_NtcNr1_V_143 = NTCNR_0X08F;
  NtcNr1 Test_NtcNr1_V_144 = NTCNR_0X090;
  NtcNr1 Test_NtcNr1_V_145 = NTCNR_0X091;
  NtcNr1 Test_NtcNr1_V_146 = NTCNR_0X092;
  NtcNr1 Test_NtcNr1_V_147 = NTCNR_0X093;
  NtcNr1 Test_NtcNr1_V_148 = NTCNR_0X094;
  NtcNr1 Test_NtcNr1_V_149 = NTCNR_0X095;
  NtcNr1 Test_NtcNr1_V_150 = NTCNR_0X096;
  NtcNr1 Test_NtcNr1_V_151 = NTCNR_0X097;
  NtcNr1 Test_NtcNr1_V_152 = NTCNR_0X098;
  NtcNr1 Test_NtcNr1_V_153 = NTCNR_0X099;
  NtcNr1 Test_NtcNr1_V_154 = NTCNR_0X09A;
  NtcNr1 Test_NtcNr1_V_155 = NTCNR_0X09B;
  NtcNr1 Test_NtcNr1_V_156 = NTCNR_0X09C;
  NtcNr1 Test_NtcNr1_V_157 = NTCNR_0X09D;
  NtcNr1 Test_NtcNr1_V_158 = NTCNR_0X09E;
  NtcNr1 Test_NtcNr1_V_159 = NTCNR_0X09F;
  NtcNr1 Test_NtcNr1_V_160 = NTCNR_0X0A0;
  NtcNr1 Test_NtcNr1_V_161 = NTCNR_0X0A1;
  NtcNr1 Test_NtcNr1_V_162 = NTCNR_0X0A2;
  NtcNr1 Test_NtcNr1_V_163 = NTCNR_0X0A3;
  NtcNr1 Test_NtcNr1_V_164 = NTCNR_0X0A4;
  NtcNr1 Test_NtcNr1_V_165 = NTCNR_0X0A5;
  NtcNr1 Test_NtcNr1_V_166 = NTCNR_0X0A6;
  NtcNr1 Test_NtcNr1_V_167 = NTCNR_0X0A7;
  NtcNr1 Test_NtcNr1_V_168 = NTCNR_0X0A8;
  NtcNr1 Test_NtcNr1_V_169 = NTCNR_0X0A9;
  NtcNr1 Test_NtcNr1_V_170 = NTCNR_0X0AA;
  NtcNr1 Test_NtcNr1_V_171 = NTCNR_0X0AB;
  NtcNr1 Test_NtcNr1_V_172 = NTCNR_0X0AC;
  NtcNr1 Test_NtcNr1_V_173 = NTCNR_0X0AD;
  NtcNr1 Test_NtcNr1_V_174 = NTCNR_0X0AE;
  NtcNr1 Test_NtcNr1_V_175 = NTCNR_0X0AF;
  NtcNr1 Test_NtcNr1_V_176 = NTCNR_0X0B0;
  NtcNr1 Test_NtcNr1_V_177 = NTCNR_0X0B1;
  NtcNr1 Test_NtcNr1_V_178 = NTCNR_0X0B2;
  NtcNr1 Test_NtcNr1_V_179 = NTCNR_0X0B3;
  NtcNr1 Test_NtcNr1_V_180 = NTCNR_0X0B4;
  NtcNr1 Test_NtcNr1_V_181 = NTCNR_0X0B5;
  NtcNr1 Test_NtcNr1_V_182 = NTCNR_0X0B6;
  NtcNr1 Test_NtcNr1_V_183 = NTCNR_0X0B7;
  NtcNr1 Test_NtcNr1_V_184 = NTCNR_0X0B8;
  NtcNr1 Test_NtcNr1_V_185 = NTCNR_0X0B9;
  NtcNr1 Test_NtcNr1_V_186 = NTCNR_0X0BA;
  NtcNr1 Test_NtcNr1_V_187 = NTCNR_0X0BB;
  NtcNr1 Test_NtcNr1_V_188 = NTCNR_0X0BC;
  NtcNr1 Test_NtcNr1_V_189 = NTCNR_0X0BD;
  NtcNr1 Test_NtcNr1_V_190 = NTCNR_0X0BE;
  NtcNr1 Test_NtcNr1_V_191 = NTCNR_0X0BF;
  NtcNr1 Test_NtcNr1_V_192 = NTCNR_0X0C0;
  NtcNr1 Test_NtcNr1_V_193 = NTCNR_0X0C1;
  NtcNr1 Test_NtcNr1_V_194 = NTCNR_0X0C2;
  NtcNr1 Test_NtcNr1_V_195 = NTCNR_0X0C3;
  NtcNr1 Test_NtcNr1_V_196 = NTCNR_0X0C4;
  NtcNr1 Test_NtcNr1_V_197 = NTCNR_0X0C5;
  NtcNr1 Test_NtcNr1_V_198 = NTCNR_0X0C6;
  NtcNr1 Test_NtcNr1_V_199 = NTCNR_0X0C7;
  NtcNr1 Test_NtcNr1_V_200 = NTCNR_0X0C8;
  NtcNr1 Test_NtcNr1_V_201 = NTCNR_0X0C9;
  NtcNr1 Test_NtcNr1_V_202 = NTCNR_0X0CA;
  NtcNr1 Test_NtcNr1_V_203 = NTCNR_0X0CB;
  NtcNr1 Test_NtcNr1_V_204 = NTCNR_0X0CC;
  NtcNr1 Test_NtcNr1_V_205 = NTCNR_0X0CD;
  NtcNr1 Test_NtcNr1_V_206 = NTCNR_0X0CE;
  NtcNr1 Test_NtcNr1_V_207 = NTCNR_0X0CF;
  NtcNr1 Test_NtcNr1_V_208 = NTCNR_0X0D0;
  NtcNr1 Test_NtcNr1_V_209 = NTCNR_0X0D1;
  NtcNr1 Test_NtcNr1_V_210 = NTCNR_0X0D2;
  NtcNr1 Test_NtcNr1_V_211 = NTCNR_0X0D3;
  NtcNr1 Test_NtcNr1_V_212 = NTCNR_0X0D4;
  NtcNr1 Test_NtcNr1_V_213 = NTCNR_0X0D5;
  NtcNr1 Test_NtcNr1_V_214 = NTCNR_0X0D6;
  NtcNr1 Test_NtcNr1_V_215 = NTCNR_0X0D7;
  NtcNr1 Test_NtcNr1_V_216 = NTCNR_0X0D8;
  NtcNr1 Test_NtcNr1_V_217 = NTCNR_0X0D9;
  NtcNr1 Test_NtcNr1_V_218 = NTCNR_0X0DA;
  NtcNr1 Test_NtcNr1_V_219 = NTCNR_0X0DB;
  NtcNr1 Test_NtcNr1_V_220 = NTCNR_0X0DC;
  NtcNr1 Test_NtcNr1_V_221 = NTCNR_0X0DD;
  NtcNr1 Test_NtcNr1_V_222 = NTCNR_0X0DE;
  NtcNr1 Test_NtcNr1_V_223 = NTCNR_0X0DF;
  NtcNr1 Test_NtcNr1_V_224 = NTCNR_0X0E0;
  NtcNr1 Test_NtcNr1_V_225 = NTCNR_0X0E1;
  NtcNr1 Test_NtcNr1_V_226 = NTCNR_0X0E2;
  NtcNr1 Test_NtcNr1_V_227 = NTCNR_0X0E3;
  NtcNr1 Test_NtcNr1_V_228 = NTCNR_0X0E4;
  NtcNr1 Test_NtcNr1_V_229 = NTCNR_0X0E5;
  NtcNr1 Test_NtcNr1_V_230 = NTCNR_0X0E6;
  NtcNr1 Test_NtcNr1_V_231 = NTCNR_0X0E7;
  NtcNr1 Test_NtcNr1_V_232 = NTCNR_0X0E8;
  NtcNr1 Test_NtcNr1_V_233 = NTCNR_0X0E9;
  NtcNr1 Test_NtcNr1_V_234 = NTCNR_0X0EA;
  NtcNr1 Test_NtcNr1_V_235 = NTCNR_0X0EB;
  NtcNr1 Test_NtcNr1_V_236 = NTCNR_0X0EC;
  NtcNr1 Test_NtcNr1_V_237 = NTCNR_0X0ED;
  NtcNr1 Test_NtcNr1_V_238 = NTCNR_0X0EE;
  NtcNr1 Test_NtcNr1_V_239 = NTCNR_0X0EF;
  NtcNr1 Test_NtcNr1_V_240 = NTCNR_0X0F0;
  NtcNr1 Test_NtcNr1_V_241 = NTCNR_0X0F1;
  NtcNr1 Test_NtcNr1_V_242 = NTCNR_0X0F2;
  NtcNr1 Test_NtcNr1_V_243 = NTCNR_0X0F3;
  NtcNr1 Test_NtcNr1_V_244 = NTCNR_0X0F4;
  NtcNr1 Test_NtcNr1_V_245 = NTCNR_0X0F5;
  NtcNr1 Test_NtcNr1_V_246 = NTCNR_0X0F6;
  NtcNr1 Test_NtcNr1_V_247 = NTCNR_0X0F7;
  NtcNr1 Test_NtcNr1_V_248 = NTCNR_0X0F8;
  NtcNr1 Test_NtcNr1_V_249 = NTCNR_0X0F9;
  NtcNr1 Test_NtcNr1_V_250 = NTCNR_0X0FA;
  NtcNr1 Test_NtcNr1_V_251 = NTCNR_0X0FB;
  NtcNr1 Test_NtcNr1_V_252 = NTCNR_0X0FC;
  NtcNr1 Test_NtcNr1_V_253 = NTCNR_0X0FD;
  NtcNr1 Test_NtcNr1_V_254 = NTCNR_0X0FE;
  NtcNr1 Test_NtcNr1_V_255 = NTCNR_0X0FF;
  NtcNr1 Test_NtcNr1_V_256 = NTCNR_0X100;
  NtcNr1 Test_NtcNr1_V_257 = NTCNR_0X101;
  NtcNr1 Test_NtcNr1_V_258 = NTCNR_0X102;
  NtcNr1 Test_NtcNr1_V_259 = NTCNR_0X103;
  NtcNr1 Test_NtcNr1_V_260 = NTCNR_0X104;
  NtcNr1 Test_NtcNr1_V_261 = NTCNR_0X105;
  NtcNr1 Test_NtcNr1_V_262 = NTCNR_0X106;
  NtcNr1 Test_NtcNr1_V_263 = NTCNR_0X107;
  NtcNr1 Test_NtcNr1_V_264 = NTCNR_0X108;
  NtcNr1 Test_NtcNr1_V_265 = NTCNR_0X109;
  NtcNr1 Test_NtcNr1_V_266 = NTCNR_0X10A;
  NtcNr1 Test_NtcNr1_V_267 = NTCNR_0X10B;
  NtcNr1 Test_NtcNr1_V_268 = NTCNR_0X10C;
  NtcNr1 Test_NtcNr1_V_269 = NTCNR_0X10D;
  NtcNr1 Test_NtcNr1_V_270 = NTCNR_0X10E;
  NtcNr1 Test_NtcNr1_V_271 = NTCNR_0X10F;
  NtcNr1 Test_NtcNr1_V_272 = NTCNR_0X110;
  NtcNr1 Test_NtcNr1_V_273 = NTCNR_0X111;
  NtcNr1 Test_NtcNr1_V_274 = NTCNR_0X112;
  NtcNr1 Test_NtcNr1_V_275 = NTCNR_0X113;
  NtcNr1 Test_NtcNr1_V_276 = NTCNR_0X114;
  NtcNr1 Test_NtcNr1_V_277 = NTCNR_0X115;
  NtcNr1 Test_NtcNr1_V_278 = NTCNR_0X116;
  NtcNr1 Test_NtcNr1_V_279 = NTCNR_0X117;
  NtcNr1 Test_NtcNr1_V_280 = NTCNR_0X118;
  NtcNr1 Test_NtcNr1_V_281 = NTCNR_0X119;
  NtcNr1 Test_NtcNr1_V_282 = NTCNR_0X11A;
  NtcNr1 Test_NtcNr1_V_283 = NTCNR_0X11B;
  NtcNr1 Test_NtcNr1_V_284 = NTCNR_0X11C;
  NtcNr1 Test_NtcNr1_V_285 = NTCNR_0X11D;
  NtcNr1 Test_NtcNr1_V_286 = NTCNR_0X11E;
  NtcNr1 Test_NtcNr1_V_287 = NTCNR_0X11F;
  NtcNr1 Test_NtcNr1_V_288 = NTCNR_0X120;
  NtcNr1 Test_NtcNr1_V_289 = NTCNR_0X121;
  NtcNr1 Test_NtcNr1_V_290 = NTCNR_0X122;
  NtcNr1 Test_NtcNr1_V_291 = NTCNR_0X123;
  NtcNr1 Test_NtcNr1_V_292 = NTCNR_0X124;
  NtcNr1 Test_NtcNr1_V_293 = NTCNR_0X125;
  NtcNr1 Test_NtcNr1_V_294 = NTCNR_0X126;
  NtcNr1 Test_NtcNr1_V_295 = NTCNR_0X127;
  NtcNr1 Test_NtcNr1_V_296 = NTCNR_0X128;
  NtcNr1 Test_NtcNr1_V_297 = NTCNR_0X129;
  NtcNr1 Test_NtcNr1_V_298 = NTCNR_0X12A;
  NtcNr1 Test_NtcNr1_V_299 = NTCNR_0X12B;
  NtcNr1 Test_NtcNr1_V_300 = NTCNR_0X12C;
  NtcNr1 Test_NtcNr1_V_301 = NTCNR_0X12D;
  NtcNr1 Test_NtcNr1_V_302 = NTCNR_0X12E;
  NtcNr1 Test_NtcNr1_V_303 = NTCNR_0X12F;
  NtcNr1 Test_NtcNr1_V_304 = NTCNR_0X130;
  NtcNr1 Test_NtcNr1_V_305 = NTCNR_0X131;
  NtcNr1 Test_NtcNr1_V_306 = NTCNR_0X132;
  NtcNr1 Test_NtcNr1_V_307 = NTCNR_0X133;
  NtcNr1 Test_NtcNr1_V_308 = NTCNR_0X134;
  NtcNr1 Test_NtcNr1_V_309 = NTCNR_0X135;
  NtcNr1 Test_NtcNr1_V_310 = NTCNR_0X136;
  NtcNr1 Test_NtcNr1_V_311 = NTCNR_0X137;
  NtcNr1 Test_NtcNr1_V_312 = NTCNR_0X138;
  NtcNr1 Test_NtcNr1_V_313 = NTCNR_0X139;
  NtcNr1 Test_NtcNr1_V_314 = NTCNR_0X13A;
  NtcNr1 Test_NtcNr1_V_315 = NTCNR_0X13B;
  NtcNr1 Test_NtcNr1_V_316 = NTCNR_0X13C;
  NtcNr1 Test_NtcNr1_V_317 = NTCNR_0X13D;
  NtcNr1 Test_NtcNr1_V_318 = NTCNR_0X13E;
  NtcNr1 Test_NtcNr1_V_319 = NTCNR_0X13F;
  NtcNr1 Test_NtcNr1_V_320 = NTCNR_0X140;
  NtcNr1 Test_NtcNr1_V_321 = NTCNR_0X141;
  NtcNr1 Test_NtcNr1_V_322 = NTCNR_0X142;
  NtcNr1 Test_NtcNr1_V_323 = NTCNR_0X143;
  NtcNr1 Test_NtcNr1_V_324 = NTCNR_0X144;
  NtcNr1 Test_NtcNr1_V_325 = NTCNR_0X145;
  NtcNr1 Test_NtcNr1_V_326 = NTCNR_0X146;
  NtcNr1 Test_NtcNr1_V_327 = NTCNR_0X147;
  NtcNr1 Test_NtcNr1_V_328 = NTCNR_0X148;
  NtcNr1 Test_NtcNr1_V_329 = NTCNR_0X149;
  NtcNr1 Test_NtcNr1_V_330 = NTCNR_0X14A;
  NtcNr1 Test_NtcNr1_V_331 = NTCNR_0X14B;
  NtcNr1 Test_NtcNr1_V_332 = NTCNR_0X14C;
  NtcNr1 Test_NtcNr1_V_333 = NTCNR_0X14D;
  NtcNr1 Test_NtcNr1_V_334 = NTCNR_0X14E;
  NtcNr1 Test_NtcNr1_V_335 = NTCNR_0X14F;
  NtcNr1 Test_NtcNr1_V_336 = NTCNR_0X150;
  NtcNr1 Test_NtcNr1_V_337 = NTCNR_0X151;
  NtcNr1 Test_NtcNr1_V_338 = NTCNR_0X152;
  NtcNr1 Test_NtcNr1_V_339 = NTCNR_0X153;
  NtcNr1 Test_NtcNr1_V_340 = NTCNR_0X154;
  NtcNr1 Test_NtcNr1_V_341 = NTCNR_0X155;
  NtcNr1 Test_NtcNr1_V_342 = NTCNR_0X156;
  NtcNr1 Test_NtcNr1_V_343 = NTCNR_0X157;
  NtcNr1 Test_NtcNr1_V_344 = NTCNR_0X158;
  NtcNr1 Test_NtcNr1_V_345 = NTCNR_0X159;
  NtcNr1 Test_NtcNr1_V_346 = NTCNR_0X15A;
  NtcNr1 Test_NtcNr1_V_347 = NTCNR_0X15B;
  NtcNr1 Test_NtcNr1_V_348 = NTCNR_0X15C;
  NtcNr1 Test_NtcNr1_V_349 = NTCNR_0X15D;
  NtcNr1 Test_NtcNr1_V_350 = NTCNR_0X15E;
  NtcNr1 Test_NtcNr1_V_351 = NTCNR_0X15F;
  NtcNr1 Test_NtcNr1_V_352 = NTCNR_0X160;
  NtcNr1 Test_NtcNr1_V_353 = NTCNR_0X161;
  NtcNr1 Test_NtcNr1_V_354 = NTCNR_0X162;
  NtcNr1 Test_NtcNr1_V_355 = NTCNR_0X163;
  NtcNr1 Test_NtcNr1_V_356 = NTCNR_0X164;
  NtcNr1 Test_NtcNr1_V_357 = NTCNR_0X165;
  NtcNr1 Test_NtcNr1_V_358 = NTCNR_0X166;
  NtcNr1 Test_NtcNr1_V_359 = NTCNR_0X167;
  NtcNr1 Test_NtcNr1_V_360 = NTCNR_0X168;
  NtcNr1 Test_NtcNr1_V_361 = NTCNR_0X169;
  NtcNr1 Test_NtcNr1_V_362 = NTCNR_0X16A;
  NtcNr1 Test_NtcNr1_V_363 = NTCNR_0X16B;
  NtcNr1 Test_NtcNr1_V_364 = NTCNR_0X16C;
  NtcNr1 Test_NtcNr1_V_365 = NTCNR_0X16D;
  NtcNr1 Test_NtcNr1_V_366 = NTCNR_0X16E;
  NtcNr1 Test_NtcNr1_V_367 = NTCNR_0X16F;
  NtcNr1 Test_NtcNr1_V_368 = NTCNR_0X170;
  NtcNr1 Test_NtcNr1_V_369 = NTCNR_0X171;
  NtcNr1 Test_NtcNr1_V_370 = NTCNR_0X172;
  NtcNr1 Test_NtcNr1_V_371 = NTCNR_0X173;
  NtcNr1 Test_NtcNr1_V_372 = NTCNR_0X174;
  NtcNr1 Test_NtcNr1_V_373 = NTCNR_0X175;
  NtcNr1 Test_NtcNr1_V_374 = NTCNR_0X176;
  NtcNr1 Test_NtcNr1_V_375 = NTCNR_0X177;
  NtcNr1 Test_NtcNr1_V_376 = NTCNR_0X178;
  NtcNr1 Test_NtcNr1_V_377 = NTCNR_0X179;
  NtcNr1 Test_NtcNr1_V_378 = NTCNR_0X17A;
  NtcNr1 Test_NtcNr1_V_379 = NTCNR_0X17B;
  NtcNr1 Test_NtcNr1_V_380 = NTCNR_0X17C;
  NtcNr1 Test_NtcNr1_V_381 = NTCNR_0X17D;
  NtcNr1 Test_NtcNr1_V_382 = NTCNR_0X17E;
  NtcNr1 Test_NtcNr1_V_383 = NTCNR_0X17F;
  NtcNr1 Test_NtcNr1_V_384 = NTCNR_0X180;
  NtcNr1 Test_NtcNr1_V_385 = NTCNR_0X181;
  NtcNr1 Test_NtcNr1_V_386 = NTCNR_0X182;
  NtcNr1 Test_NtcNr1_V_387 = NTCNR_0X183;
  NtcNr1 Test_NtcNr1_V_388 = NTCNR_0X184;
  NtcNr1 Test_NtcNr1_V_389 = NTCNR_0X185;
  NtcNr1 Test_NtcNr1_V_390 = NTCNR_0X186;
  NtcNr1 Test_NtcNr1_V_391 = NTCNR_0X187;
  NtcNr1 Test_NtcNr1_V_392 = NTCNR_0X188;
  NtcNr1 Test_NtcNr1_V_393 = NTCNR_0X189;
  NtcNr1 Test_NtcNr1_V_394 = NTCNR_0X18A;
  NtcNr1 Test_NtcNr1_V_395 = NTCNR_0X18B;
  NtcNr1 Test_NtcNr1_V_396 = NTCNR_0X18C;
  NtcNr1 Test_NtcNr1_V_397 = NTCNR_0X18D;
  NtcNr1 Test_NtcNr1_V_398 = NTCNR_0X18E;
  NtcNr1 Test_NtcNr1_V_399 = NTCNR_0X18F;
  NtcNr1 Test_NtcNr1_V_400 = NTCNR_0X190;
  NtcNr1 Test_NtcNr1_V_401 = NTCNR_0X191;
  NtcNr1 Test_NtcNr1_V_402 = NTCNR_0X192;
  NtcNr1 Test_NtcNr1_V_403 = NTCNR_0X193;
  NtcNr1 Test_NtcNr1_V_404 = NTCNR_0X194;
  NtcNr1 Test_NtcNr1_V_405 = NTCNR_0X195;
  NtcNr1 Test_NtcNr1_V_406 = NTCNR_0X196;
  NtcNr1 Test_NtcNr1_V_407 = NTCNR_0X197;
  NtcNr1 Test_NtcNr1_V_408 = NTCNR_0X198;
  NtcNr1 Test_NtcNr1_V_409 = NTCNR_0X199;
  NtcNr1 Test_NtcNr1_V_410 = NTCNR_0X19A;
  NtcNr1 Test_NtcNr1_V_411 = NTCNR_0X19B;
  NtcNr1 Test_NtcNr1_V_412 = NTCNR_0X19C;
  NtcNr1 Test_NtcNr1_V_413 = NTCNR_0X19D;
  NtcNr1 Test_NtcNr1_V_414 = NTCNR_0X19E;
  NtcNr1 Test_NtcNr1_V_415 = NTCNR_0X19F;
  NtcNr1 Test_NtcNr1_V_416 = NTCNR_0X1A0;
  NtcNr1 Test_NtcNr1_V_417 = NTCNR_0X1A1;
  NtcNr1 Test_NtcNr1_V_418 = NTCNR_0X1A2;
  NtcNr1 Test_NtcNr1_V_419 = NTCNR_0X1A3;
  NtcNr1 Test_NtcNr1_V_420 = NTCNR_0X1A4;
  NtcNr1 Test_NtcNr1_V_421 = NTCNR_0X1A5;
  NtcNr1 Test_NtcNr1_V_422 = NTCNR_0X1A6;
  NtcNr1 Test_NtcNr1_V_423 = NTCNR_0X1A7;
  NtcNr1 Test_NtcNr1_V_424 = NTCNR_0X1A8;
  NtcNr1 Test_NtcNr1_V_425 = NTCNR_0X1A9;
  NtcNr1 Test_NtcNr1_V_426 = NTCNR_0X1AA;
  NtcNr1 Test_NtcNr1_V_427 = NTCNR_0X1AB;
  NtcNr1 Test_NtcNr1_V_428 = NTCNR_0X1AC;
  NtcNr1 Test_NtcNr1_V_429 = NTCNR_0X1AD;
  NtcNr1 Test_NtcNr1_V_430 = NTCNR_0X1AE;
  NtcNr1 Test_NtcNr1_V_431 = NTCNR_0X1AF;
  NtcNr1 Test_NtcNr1_V_432 = NTCNR_0X1B0;
  NtcNr1 Test_NtcNr1_V_433 = NTCNR_0X1B1;
  NtcNr1 Test_NtcNr1_V_434 = NTCNR_0X1B2;
  NtcNr1 Test_NtcNr1_V_435 = NTCNR_0X1B3;
  NtcNr1 Test_NtcNr1_V_436 = NTCNR_0X1B4;
  NtcNr1 Test_NtcNr1_V_437 = NTCNR_0X1B5;
  NtcNr1 Test_NtcNr1_V_438 = NTCNR_0X1B6;
  NtcNr1 Test_NtcNr1_V_439 = NTCNR_0X1B7;
  NtcNr1 Test_NtcNr1_V_440 = NTCNR_0X1B8;
  NtcNr1 Test_NtcNr1_V_441 = NTCNR_0X1B9;
  NtcNr1 Test_NtcNr1_V_442 = NTCNR_0X1BA;
  NtcNr1 Test_NtcNr1_V_443 = NTCNR_0X1BB;
  NtcNr1 Test_NtcNr1_V_444 = NTCNR_0X1BC;
  NtcNr1 Test_NtcNr1_V_445 = NTCNR_0X1BD;
  NtcNr1 Test_NtcNr1_V_446 = NTCNR_0X1BE;
  NtcNr1 Test_NtcNr1_V_447 = NTCNR_0X1BF;
  NtcNr1 Test_NtcNr1_V_448 = NTCNR_0X1C0;
  NtcNr1 Test_NtcNr1_V_449 = NTCNR_0X1C1;
  NtcNr1 Test_NtcNr1_V_450 = NTCNR_0X1C2;
  NtcNr1 Test_NtcNr1_V_451 = NTCNR_0X1C3;
  NtcNr1 Test_NtcNr1_V_452 = NTCNR_0X1C4;
  NtcNr1 Test_NtcNr1_V_453 = NTCNR_0X1C5;
  NtcNr1 Test_NtcNr1_V_454 = NTCNR_0X1C6;
  NtcNr1 Test_NtcNr1_V_455 = NTCNR_0X1C7;
  NtcNr1 Test_NtcNr1_V_456 = NTCNR_0X1C8;
  NtcNr1 Test_NtcNr1_V_457 = NTCNR_0X1C9;
  NtcNr1 Test_NtcNr1_V_458 = NTCNR_0X1CA;
  NtcNr1 Test_NtcNr1_V_459 = NTCNR_0X1CB;
  NtcNr1 Test_NtcNr1_V_460 = NTCNR_0X1CC;
  NtcNr1 Test_NtcNr1_V_461 = NTCNR_0X1CD;
  NtcNr1 Test_NtcNr1_V_462 = NTCNR_0X1CE;
  NtcNr1 Test_NtcNr1_V_463 = NTCNR_0X1CF;
  NtcNr1 Test_NtcNr1_V_464 = NTCNR_0X1D0;
  NtcNr1 Test_NtcNr1_V_465 = NTCNR_0X1D1;
  NtcNr1 Test_NtcNr1_V_466 = NTCNR_0X1D2;
  NtcNr1 Test_NtcNr1_V_467 = NTCNR_0X1D3;
  NtcNr1 Test_NtcNr1_V_468 = NTCNR_0X1D4;
  NtcNr1 Test_NtcNr1_V_469 = NTCNR_0X1D5;
  NtcNr1 Test_NtcNr1_V_470 = NTCNR_0X1D6;
  NtcNr1 Test_NtcNr1_V_471 = NTCNR_0X1D7;
  NtcNr1 Test_NtcNr1_V_472 = NTCNR_0X1D8;
  NtcNr1 Test_NtcNr1_V_473 = NTCNR_0X1D9;
  NtcNr1 Test_NtcNr1_V_474 = NTCNR_0X1DA;
  NtcNr1 Test_NtcNr1_V_475 = NTCNR_0X1DB;
  NtcNr1 Test_NtcNr1_V_476 = NTCNR_0X1DC;
  NtcNr1 Test_NtcNr1_V_477 = NTCNR_0X1DD;
  NtcNr1 Test_NtcNr1_V_478 = NTCNR_0X1DE;
  NtcNr1 Test_NtcNr1_V_479 = NTCNR_0X1DF;
  NtcNr1 Test_NtcNr1_V_480 = NTCNR_0X1E0;
  NtcNr1 Test_NtcNr1_V_481 = NTCNR_0X1E1;
  NtcNr1 Test_NtcNr1_V_482 = NTCNR_0X1E2;
  NtcNr1 Test_NtcNr1_V_483 = NTCNR_0X1E3;
  NtcNr1 Test_NtcNr1_V_484 = NTCNR_0X1E4;
  NtcNr1 Test_NtcNr1_V_485 = NTCNR_0X1E5;
  NtcNr1 Test_NtcNr1_V_486 = NTCNR_0X1E6;
  NtcNr1 Test_NtcNr1_V_487 = NTCNR_0X1E7;
  NtcNr1 Test_NtcNr1_V_488 = NTCNR_0X1E8;
  NtcNr1 Test_NtcNr1_V_489 = NTCNR_0X1E9;
  NtcNr1 Test_NtcNr1_V_490 = NTCNR_0X1EA;
  NtcNr1 Test_NtcNr1_V_491 = NTCNR_0X1EB;
  NtcNr1 Test_NtcNr1_V_492 = NTCNR_0X1EC;
  NtcNr1 Test_NtcNr1_V_493 = NTCNR_0X1ED;
  NtcNr1 Test_NtcNr1_V_494 = NTCNR_0X1EE;
  NtcNr1 Test_NtcNr1_V_495 = NTCNR_0X1EF;
  NtcNr1 Test_NtcNr1_V_496 = NTCNR_0X1F0;
  NtcNr1 Test_NtcNr1_V_497 = NTCNR_0X1F1;
  NtcNr1 Test_NtcNr1_V_498 = NTCNR_0X1F2;
  NtcNr1 Test_NtcNr1_V_499 = NTCNR_0X1F3;
  NtcNr1 Test_NtcNr1_V_500 = NTCNR_0X1F4;
  NtcNr1 Test_NtcNr1_V_501 = NTCNR_0X1F5;
  NtcNr1 Test_NtcNr1_V_502 = NTCNR_0X1F6;
  NtcNr1 Test_NtcNr1_V_503 = NTCNR_0X1F7;
  NtcNr1 Test_NtcNr1_V_504 = NTCNR_0X1F8;
  NtcNr1 Test_NtcNr1_V_505 = NTCNR_0X1F9;
  NtcNr1 Test_NtcNr1_V_506 = NTCNR_0X1FA;
  NtcNr1 Test_NtcNr1_V_507 = NTCNR_0X1FB;
  NtcNr1 Test_NtcNr1_V_508 = NTCNR_0X1FC;
  NtcNr1 Test_NtcNr1_V_509 = NTCNR_0X1FD;
  NtcNr1 Test_NtcNr1_V_510 = NTCNR_0X1FE;
  NtcNr1 Test_NtcNr1_V_511 = NTCNR_0X1FF;

  NtcSts1 Test_NtcSts1_V_1 = NTCSTS_PASSD;
  NtcSts1 Test_NtcSts1_V_2 = NTCSTS_FAILD;
  NtcSts1 Test_NtcSts1_V_3 = NTCSTS_PREPASSD;
  NtcSts1 Test_NtcSts1_V_4 = NTCSTS_PREFAILD;

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;

  SigQlfr1 Test_SigQlfr1_V_1 = SIGQLFR_NORES;
  SigQlfr1 Test_SigQlfr1_V_2 = SIGQLFR_PASSD;
  SigQlfr1 Test_SigQlfr1_V_3 = SIGQLFR_FAILD;
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

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
