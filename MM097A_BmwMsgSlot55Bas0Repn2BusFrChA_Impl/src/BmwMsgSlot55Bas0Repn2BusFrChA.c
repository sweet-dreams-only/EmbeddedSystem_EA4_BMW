/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwMsgSlot55Bas0Repn2BusFrChA.c
 *        Config:  C:/_PratikJadhav/_Synergy_Projects/Working/MM097A_BmwMsgSlot55Bas0Repn2BusFrChA_Impl/tools/Component.dpa
 *     SW-C Type:  BmwMsgSlot55Bas0Repn2BusFrChA
 *  Generated at:  Wed May 30 13:10:02 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwMsgSlot55Bas0Repn2BusFrChA>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/**********************************************************************************************************************
* Copyright 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name	 : BmwMsgSlot55Bas0Repn2BusFrChA.c
* Module Description : Implementation of BmwMsgSlot55Bas0Repn2BusFrChA FDD MM097A
* Project            : CBD 
* Author             : Pratik Jadhav
***********************************************************************************************************************
* Version Control:
* %version:            6 %
* %derived_by:        nzlf92 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                      		                                   SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  -----------
* 04/17/18  1        PHJ        Initial Version                                                               EA4#22521
* 04/17/18  2        PHJ        Update Initial Version                                                        EA4#22521
* 04/25/18  3        PHJ        Alive counter NTC logic updated.                                              EA4#22521
* 05/06/18  4        PHJ        Calibration name updated.                                              		  EA4#22521
* 05/30/18  5        PHJ        Alive timeout updated.                                              		  EA4#24667
* 06/08/18  6        PHJ        To fix anomaly EA4#24784.                                              		  EA4#24789
*----------------------------------------------------------------------------------------------------------------------
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

#include "Rte_BmwMsgSlot55Bas0Repn2BusFrChA.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value */ 
 /* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

 #include "E2EPW_BmwMsgSlot55Bas0Repn2BusFrChA_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR_rx.h"
 #include "NxtrMath.h"

 #define NODEBSTEP_CNT_U16         	 			((uint16)65535U)
 #define MAXCNTRTHD_CNT_U08         			((uint8)2U)
 #define BITSHIFTALVCRC_ULS_U08      			((uint8)24U)
 #define CRCFAILTHD_CNT_U08      	 			((uint8)2U)
 #define ALVREPFAILTHD_CNT_U08	     			((uint8)8U)
 #define ALVSEQFAILTHD_CNT_U08       			((uint8)64U)
 #define ACLNYCOGINVLD_CNT_U16					((uint16)65000U)
 #define ACLNYCOGMULTIFAC_ULS_F32				(0.002F)
 #define ACLNYCOGOFFS_ULS_F32					(65.0F)
 #define BMWVEHLATALOWRLIM_ULS_F32				(-10.0F)
 #define BMWVEHLATAHIGRLIM_ULS_F32				(10.0F)
 #define QUACLNYCOGUNDEFD0_CNT_U08				((uint8)0U)
 #define QUACLNYCOGUNDEFD5_CNT_U08				((uint8)5U)
 #define QUACLNYCOGUNDEFD13_CNT_U08				((uint8)13U)
 
 
 static FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) ChkNtcSts(P2VAR(uint8, automatic, automatic) NtcCnt1_Cnt_T_u08, P2VAR(uint8, automatic, automatic) NtcCnt2_Cnt_T_u08,
																	NtcNr1 NtcNr_Cnt_T_enum, NtcSts1 NtcSts_Cnt_T_enum);
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
 * ACLNY_COG1: Integer in interval [0...65535]
 *   Unit: [m/s^2], Factor: 0.002, Offset: -65
 * ACLNY_COG_ERR_AMP1: Integer in interval [0...65535]
 *   Unit: [m/s^2], Factor: 0.005, Offset: 0
 * ACLNY_MASSCNTR_dummy_12_151: Integer in interval [0...255]
 * CRC_ACLNY_COG1: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ALIV_ACLNY_COG1: Enumeration of integer in interval [0...255] with enumerators
 *   ALIV_COU_4_Zaehlerstand0DotDotE (0U)
 *   ALIV_COU_4_SignalUngueltig (15U)
 * BmwVehLatAQlfr1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHLATAQLFR_SIGVALVLDANDPLAUS (1U)
 *   BMWVEHLATAQLFR_SIGVALVLD (2U)
 *   BMWVEHLATAQLFR_SIGQLTMONRSTRCTD (3U)
 *   BMWVEHLATAQLFR_RESD1 (4U)
 *   BMWVEHLATAQLFR_SIGVALINVLD (6U)
 *   BMWVEHLATAQLFR_RESD2 (7U)
 *   BMWVEHLATAQLFR_ININ (8U)
 *   BMWVEHLATAQLFR_SIGVALTMPVLDANDSECUR (9U)
 *   BMWVEHLATAQLFR_SIGVALTMPVLD (10U)
 *   BMWVEHLATAQLFR_SIGQLTMONTMPRSTRCTD (11U)
 *   BMWVEHLATAQLFR_SIGSUBVALVLDTMP (12U)
 *   BMWVEHLATAQLFR_SIGVALTMPINVLD (14U)
 *   BMWVEHLATAQLFR_INVLDSIG (15U)
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
 * QU_ACLNY_COG1: Enumeration of integer in interval [0...255] with enumerators
 *   QU_ACLNY_COG_Initialisierung (8U)
 *   QU_ACLNY_COG_SignalwertIstGueltigUndAbgesichertUndPlausibilisiert (1U)
 *   QU_ACLNY_COG_SignalwertIstGueltigUndAbgesichertZustandSlashStatusTemporaer (9U)
 *   QU_ACLNY_COG_SignalwertIstGueltig (2U)
 *   QU_ACLNY_COG_SignalwertIstGueltigZustandSlashStatusTemporaer (10U)
 *   QU_ACLNY_COG_SignalqualitaetBzwDotUeberwachungEingeschraenkt (3U)
 *   QU_ACLNY_COG_SignalqualitaetBzwDotUeberwachungEingeschraenktZustandSlashStatusTemporaer (11U)
 *   QU_ACLNY_COG_Reserved (4U)
 *   QU_ACLNY_COG_ErsatzwertIstImNutzsignalGesetztZustandSlashStatusTemporaer (12U)
 *   QU_ACLNY_COG_SignalwertIstUngueltig (6U)
 *   QU_ACLNY_COG_SignalwertIstUngueltigZustandSlashStatusTemporaer (14U)
 *   QU_ACLNY_COG_Reserved_bne_18ACE6A1DACA4F44BAB0F4D6BBE8870D_7 (7U)
 *   QU_ACLNY_COG_SignalUngueltig (15U)
 *
 * Record Types:
 * =============
 * sigGroup_ACLNY_MASSCNTR1: Record with elements
 *   ACLNY_MASSCNTR_dummy_12_15 of type ACLNY_MASSCNTR_dummy_12_151
 *   ACLNY_COG of type ACLNY_COG1
 *   QU_ACLNY_COG of type QU_ACLNY_COG1
 *   ACLNY_COG_ERR_AMP of type ACLNY_COG_ERR_AMP1
 *   ALIV_ACLNY_COG of type ALIV_ACLNY_COG1
 *   CRC_ACLNY_COG of type CRC_ACLNY_COG1
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_BmwVehLatAPrev(void)
 *   uint8 *Rte_Pim_AclnyCogFaildCnt(void)
 *   uint8 *Rte_Pim_AclnyCogPassdCnt(void)
 *   uint8 *Rte_Pim_AlvFaildCnt(void)
 *   uint8 *Rte_Pim_AlvPassdCnt(void)
 *   BmwVehLatAQlfr1 *Rte_Pim_BmwVehLatAQlfrPrev(void)
 *   uint8 *Rte_Pim_CrcFaildCnt(void)
 *   uint8 *Rte_Pim_CrcPassdCnt(void)
 *   uint8 *Rte_Pim_MissingMsgCnt(void)
 *   uint8 *Rte_Pim_QuAclnyCogFaildCnt(void)
 *   uint8 *Rte_Pim_QuAclnyCogPassdCnt(void)
 *   uint8 *Rte_Pim_RxdMsgCnt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   sint8 Rte_Prm_BmwMsgSlot55Bas0Repn2BusFrChABmwLatAPolarity_Val(void)
 *
 *********************************************************************************************************************/


#define BmwMsgSlot55Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ACLNY_MASSCNTR_Missing_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <sigGroup_ACLNY_MASSCNTR> of PortPrototype <sigGroup_ACLNY_MASSCNTR>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(sigGroup_ACLNY_MASSCNTR1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwVehLatA_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehLatAQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehLatAVld_Logl(boolean data)
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
 * Symbol: ACLNY_MASSCNTR_Missing_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) ACLNY_MASSCNTR_Missing_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ACLNY_MASSCNTR_Missing_Oper
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) FltCodEnad_Cnt_T_logl; 
	VAR(float32, AUTOMATIC) BmwVehLatA_MtrPerSecSq_T_f32;
	VAR(BmwVehLatAQlfr1, AUTOMATIC) BmwVehLatAQlfr_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) BmwVehLatAQlfrVld_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) BmwVehLatAVld_Cnt_T_logl;
	
	(void)Rte_Read_FltCodEnad_Logl(&FltCodEnad_Cnt_T_logl);
	
	if(FltCodEnad_Cnt_T_logl != TRUE)
	{
		*Rte_Pim_MissingMsgCnt() = 0U;
		
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14D, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14E, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14F, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X151, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X150, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
	}
	else
	{
		if(*Rte_Pim_MissingMsgCnt() >= MAXCNTRTHD_CNT_U08)
		{
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14D, 0U, NTCSTS_FAILD, NODEBSTEP_CNT_U16);
		}
		else
		{
			*Rte_Pim_MissingMsgCnt() = *Rte_Pim_MissingMsgCnt() + 1U;
		}
	}

	BmwVehLatA_MtrPerSecSq_T_f32	 = *Rte_Pim_BmwVehLatAPrev();
	BmwVehLatAQlfr_Cnt_T_enum		 = *Rte_Pim_BmwVehLatAQlfrPrev();
	BmwVehLatAQlfrVld_Cnt_T_logl	 = FALSE;
	BmwVehLatAVld_Cnt_T_logl		 = FALSE;

	*Rte_Pim_AlvFaildCnt()			= 0U;
	*Rte_Pim_AlvPassdCnt()			= 0U;
	*Rte_Pim_CrcFaildCnt()			= 0U;
	*Rte_Pim_CrcPassdCnt()			= 0U;
	*Rte_Pim_AclnyCogFaildCnt()	= 0U;
	*Rte_Pim_AclnyCogPassdCnt()	= 0U;
	*Rte_Pim_RxdMsgCnt()			= 0U;
	*Rte_Pim_QuAclnyCogFaildCnt()	= 0U;
	*Rte_Pim_QuAclnyCogPassdCnt()	= 0U;
	
	(void)Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr_Cnt_T_enum);
	(void)Rte_Write_BmwVehLatAQlfrVld_Logl(BmwVehLatAQlfrVld_Cnt_T_logl);
	(void)Rte_Write_BmwVehLatA_Val(BmwVehLatA_MtrPerSecSq_T_f32);
	(void)Rte_Write_BmwVehLatAVld_Logl(BmwVehLatAVld_Cnt_T_logl);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ACLNY_MASSCNTR_Received_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sigGroup_ACLNY_MASSCNTR> of PortPrototype <sigGroup_ACLNY_MASSCNTR>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(sigGroup_ACLNY_MASSCNTR1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwVehLatA_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehLatAQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehLatAVld_Logl(boolean data)
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
 * Symbol: ACLNY_MASSCNTR_Received_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) ACLNY_MASSCNTR_Received_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ACLNY_MASSCNTR_Received_Oper
 *********************************************************************************************************************/
	VAR(sigGroup_ACLNY_MASSCNTR1, AUTOMATIC) SigGroup_ACLNY_MASSCNTR_Cnt_T_rec;
	
	VAR(uint8, AUTOMATIC) CrcAlvSts_Cnt_T_u08;
	
	VAR(float32, AUTOMATIC) BmwVehLatA_MtrPerSecSq_T_f32;
	VAR(BmwVehLatAQlfr1, AUTOMATIC) BmwVehLatAQlfr_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) BmwVehLatAQlfrVld_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) BmwVehLatAVld_Cnt_T_logl;
	
	VAR(boolean, AUTOMATIC) FltCodEnad_Cnt_T_logl;
	
	(void)Rte_Read_FltCodEnad_Logl(&FltCodEnad_Cnt_T_logl);
	CrcAlvSts_Cnt_T_u08 = (E2EPW_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(&SigGroup_ACLNY_MASSCNTR_Cnt_T_rec)>> BITSHIFTALVCRC_ULS_U08);
	
	BmwVehLatA_MtrPerSecSq_T_f32	 = *Rte_Pim_BmwVehLatAPrev();
	BmwVehLatAQlfr_Cnt_T_enum		 = *Rte_Pim_BmwVehLatAQlfrPrev();
	
	/* INPUT PROCESSING */
	if(FltCodEnad_Cnt_T_logl == FALSE)
	{
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14D, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14E, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14F, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X151, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X150, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		
		*Rte_Pim_MissingMsgCnt() 		= 0U;
		*Rte_Pim_AlvFaildCnt()			= 0U;
		*Rte_Pim_AlvPassdCnt()			= 0U;
		*Rte_Pim_CrcFaildCnt()			= 0U;
		*Rte_Pim_CrcPassdCnt()			= 0U;
		*Rte_Pim_AclnyCogFaildCnt()		= 0U;
		*Rte_Pim_AclnyCogPassdCnt()		= 0U;
		*Rte_Pim_RxdMsgCnt()			= 0U;
		*Rte_Pim_QuAclnyCogFaildCnt()	= 0U;
		*Rte_Pim_QuAclnyCogPassdCnt()	= 0U;
		
	}
	else
	{
		if(*Rte_Pim_RxdMsgCnt() >= MAXCNTRTHD_CNT_U08)
		{
			(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14D, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
		}
		else
		{
			*Rte_Pim_RxdMsgCnt() = *Rte_Pim_RxdMsgCnt() + 1U;
		}
	}
	
	*Rte_Pim_MissingMsgCnt() 		= 0U;
	
	if(CrcAlvSts_Cnt_T_u08 == CRCFAILTHD_CNT_U08) 		
	{
		if(FltCodEnad_Cnt_T_logl == TRUE)
		{	
			ChkNtcSts(Rte_Pim_CrcFaildCnt(), Rte_Pim_CrcPassdCnt(), NTCNR_0X14E, NTCSTS_FAILD);
		}
		
		BmwVehLatAQlfrVld_Cnt_T_logl		 = FALSE;
		BmwVehLatAVld_Cnt_T_logl			 = FALSE;
		*Rte_Pim_AlvFaildCnt()			= 0U;
		*Rte_Pim_AlvPassdCnt()			= 0U;
		*Rte_Pim_AclnyCogFaildCnt()		= 0U;
		*Rte_Pim_AclnyCogPassdCnt()		= 0U;
		*Rte_Pim_QuAclnyCogFaildCnt()	= 0U;
		*Rte_Pim_QuAclnyCogPassdCnt()	= 0U;
	}
	else
	{
		if(FltCodEnad_Cnt_T_logl == TRUE)
		{
			ChkNtcSts(Rte_Pim_CrcPassdCnt(), Rte_Pim_CrcFaildCnt(), NTCNR_0X14E, NTCSTS_PASSD);
		}
		/* extract Alv */
		if( (CrcAlvSts_Cnt_T_u08 == ALVREPFAILTHD_CNT_U08) || 
			(CrcAlvSts_Cnt_T_u08 == ALVSEQFAILTHD_CNT_U08) || 
			(SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.ALIV_ACLNY_COG == ALIV_COU_4_SignalUngueltig) )
		{
			if(FltCodEnad_Cnt_T_logl == TRUE)
			{
				ChkNtcSts(Rte_Pim_AlvFaildCnt(), Rte_Pim_AlvPassdCnt(), NTCNR_0X14F, NTCSTS_FAILD);
			}
			BmwVehLatAQlfrVld_Cnt_T_logl	 = FALSE;
			BmwVehLatAVld_Cnt_T_logl		 = FALSE;
			
			*Rte_Pim_AclnyCogFaildCnt()		= 0U;
			*Rte_Pim_AclnyCogPassdCnt()		= 0U;
			*Rte_Pim_QuAclnyCogFaildCnt()	= 0U;
			*Rte_Pim_QuAclnyCogPassdCnt()	= 0U;
		}
		else
		{
			if(FltCodEnad_Cnt_T_logl == TRUE)
			{
				ChkNtcSts(Rte_Pim_AlvPassdCnt(), Rte_Pim_AlvFaildCnt(), NTCNR_0X14F, NTCSTS_PASSD);
			}
			/* extract QU_ACLNY_COG 	 */
			if( (SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.QU_ACLNY_COG == QUACLNYCOGUNDEFD0_CNT_U08) ||
				(SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.QU_ACLNY_COG ==  QU_ACLNY_COG_Reserved) ||
				(SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.QU_ACLNY_COG == QUACLNYCOGUNDEFD5_CNT_U08) ||
				(SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.QU_ACLNY_COG ==  QU_ACLNY_COG_Reserved_bne_18ACE6A1DACA4F44BAB0F4D6BBE8870D_7) ||
				(SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.QU_ACLNY_COG == QUACLNYCOGUNDEFD13_CNT_U08) ||
				(SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.QU_ACLNY_COG ==  QU_ACLNY_COG_SignalUngueltig) )
			{
				BmwVehLatAQlfrVld_Cnt_T_logl = FALSE;
				BmwVehLatAQlfr_Cnt_T_enum = *Rte_Pim_BmwVehLatAQlfrPrev();
				if(FltCodEnad_Cnt_T_logl == TRUE)
				{
					ChkNtcSts(Rte_Pim_QuAclnyCogFaildCnt(), Rte_Pim_QuAclnyCogPassdCnt(), NTCNR_0X151, NTCSTS_FAILD);
				}
			}
			else
			{
				BmwVehLatAQlfrVld_Cnt_T_logl = TRUE;
				BmwVehLatAQlfr_Cnt_T_enum = SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.QU_ACLNY_COG;
				*Rte_Pim_BmwVehLatAQlfrPrev() = BmwVehLatAQlfr_Cnt_T_enum;
				if(FltCodEnad_Cnt_T_logl == TRUE)
				{
					ChkNtcSts(Rte_Pim_QuAclnyCogPassdCnt(), Rte_Pim_QuAclnyCogFaildCnt(), NTCNR_0X151, NTCSTS_PASSD);
				}
				
			}
			
			/* extract ACLNY_COG 	 */
			if(SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.ACLNY_COG > ACLNYCOGINVLD_CNT_U16)
			{
				BmwVehLatAVld_Cnt_T_logl = FALSE;
				BmwVehLatA_MtrPerSecSq_T_f32 = *Rte_Pim_BmwVehLatAPrev();
				if(FltCodEnad_Cnt_T_logl == TRUE)
				{
					ChkNtcSts(Rte_Pim_AclnyCogFaildCnt(), Rte_Pim_AclnyCogPassdCnt(), NTCNR_0X150, NTCSTS_FAILD);
				}
			}
			else
			{
				BmwVehLatAVld_Cnt_T_logl = TRUE;
				BmwVehLatA_MtrPerSecSq_T_f32 = ((SigGroup_ACLNY_MASSCNTR_Cnt_T_rec.ACLNY_COG*ACLNYCOGMULTIFAC_ULS_F32) - ACLNYCOGOFFS_ULS_F32);
				BmwVehLatA_MtrPerSecSq_T_f32 = Lim_f32(BmwVehLatA_MtrPerSecSq_T_f32, BMWVEHLATALOWRLIM_ULS_F32, BMWVEHLATAHIGRLIM_ULS_F32);
				BmwVehLatA_MtrPerSecSq_T_f32 = BmwVehLatA_MtrPerSecSq_T_f32*(Rte_Prm_BmwMsgSlot55Bas0Repn2BusFrChABmwLatAPolarity_Val());
				*Rte_Pim_BmwVehLatAPrev() = BmwVehLatA_MtrPerSecSq_T_f32;
				if(FltCodEnad_Cnt_T_logl == TRUE)
				{
					ChkNtcSts(Rte_Pim_AclnyCogPassdCnt(), Rte_Pim_AclnyCogFaildCnt(), NTCNR_0X150, NTCSTS_PASSD);
				}
				
			}
		}
	}
	
	(void)Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr_Cnt_T_enum);
	(void)Rte_Write_BmwVehLatAQlfrVld_Logl(BmwVehLatAQlfrVld_Cnt_T_logl);
	(void)Rte_Write_BmwVehLatA_Val(BmwVehLatA_MtrPerSecSq_T_f32);
	(void)Rte_Write_BmwVehLatAVld_Logl(BmwVehLatAVld_Cnt_T_logl);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwMsgSlot55Bas0Repn2BusFrChAInit1
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
 *   Std_ReturnType Rte_Read_FltCodEnad_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_sigGroup_ACLNY_MASSCNTR_sigGroup_ACLNY_MASSCNTR(sigGroup_ACLNY_MASSCNTR1 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwVehLatA_Val(float32 data)
 *   Std_ReturnType Rte_Write_BmwVehLatAQlfr_Val(BmwVehLatAQlfr1 data)
 *   Std_ReturnType Rte_Write_BmwVehLatAQlfrVld_Logl(boolean data)
 *   Std_ReturnType Rte_Write_BmwVehLatAVld_Logl(boolean data)
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
 * Symbol: BmwMsgSlot55Bas0Repn2BusFrChAInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) BmwMsgSlot55Bas0Repn2BusFrChAInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwMsgSlot55Bas0Repn2BusFrChAInit1
 *********************************************************************************************************************/
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14D, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14E, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X14F, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X151, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
	(void)Rte_Call_SetNtcSts_Oper(NTCNR_0X150, 0U, NTCSTS_PASSD, NODEBSTEP_CNT_U16);
	
	*Rte_Pim_BmwVehLatAPrev() = 0.0F;
	*Rte_Pim_BmwVehLatAQlfrPrev() = (BmwVehLatAQlfr1)BMWVEHLATAQLFR_INVLDSIG;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwMsgSlot55Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#define BmwMsgSlot55Bas0Repn2BusFrChA_START_SEC_CODE
#include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/******************************************************************************
 * Name:        ChkNtcSts
 * Description: Set or Clear NTCs.
 * Inputs:      NONE   
 * Outputs:     NONE
 * Usage Notes: NONE
 ****************************************************************************/
static FUNC(void, BmwMsgSlot55Bas0Repn2BusFrChA_CODE) ChkNtcSts(P2VAR(uint8, automatic, automatic) NtcCnt1_Cnt_T_u08, P2VAR(uint8, automatic, automatic) NtcCnt2_Cnt_T_u08,
																	NtcNr1 NtcNr_Cnt_T_enum, NtcSts1 NtcSts_Cnt_T_enum)
{ 
	if(*NtcCnt1_Cnt_T_u08 >= MAXCNTRTHD_CNT_U08)
	{
		(void)Rte_Call_SetNtcSts_Oper(NtcNr_Cnt_T_enum, 0U, NtcSts_Cnt_T_enum, NODEBSTEP_CNT_U16);
	}
	else
	{
		*NtcCnt1_Cnt_T_u08 = *NtcCnt1_Cnt_T_u08 + 1U;
	}
	*NtcCnt2_Cnt_T_u08 = 0U;

}

#define BmwMsgSlot55Bas0Repn2BusFrChA_STOP_SEC_CODE
#include "BmwMsgSlot55Bas0Repn2BusFrChA_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
