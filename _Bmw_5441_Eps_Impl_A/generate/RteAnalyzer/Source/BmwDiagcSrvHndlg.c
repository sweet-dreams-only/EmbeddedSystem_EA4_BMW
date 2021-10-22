/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwDiagcSrvHndlg.c
 *        Config:  EPS.dpa
 *     SW-C Type:  BmwDiagcSrvHndlg
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwDiagcSrvHndlg>
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
 * BmwBasPtlNetCtrl1
 *   
 *
 * BmwPinionAgQlfr1
 *   
 *
 * BmwSetVehCentrOffsSts1
 *   
 *
 * BmwVehCdn1
 *   
 *
 * Dcm_NegativeResponseCodeType
 *   
 *
 * Dcm_OpStatusType
 *   
 *
 * DrvgDynIfSt1
 *   
 *
 * NtcNr1
 *   
 *
 * SysSt1
 *   
 *
 *********************************************************************************************************************/

#include "Rte_BmwDiagcSrvHndlg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_BmwDiagcSrvHndlg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void BmwDiagcSrvHndlg_TestDefines(void);


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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BmwBasPtlNetCtrl1: Enumeration of integer in interval [0...255] with enumerators
 *   NoCommunication (0U)
 *   ParkingNotOk (1U)
 *   ParkingOk (2U)
 *   StandingFunctions (3U)
 *   Living (5U)
 *   CheckDiagnosticAnalysis (7U)
 *   DriverPreparingforOperation (8U)
 *   Driving (10U)
 *   DriverPreparingToExitOperation (12U)
 *   Invalid (15U)
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
 * BmwSetVehCentrOffsSts1: Enumeration of integer in interval [0...255] with enumerators
 *   BMWVEHCENTROFFSSTS_OFFSPRFMD (0U)
 *   BMWVEHCENTROFFSSTS_OFFSFAILD (1U)
 *   BMWVEHCENTROFFSSTS_OFFSFAILDVALOUTOFRNG (2U)
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
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
 * DrvgDynIfSt1: Enumeration of integer in interval [0...255] with enumerators
 *   DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG (32U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL (33U)
 *   DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG (34U)
 *   DRVGDYNIFST_IFACTVADDLDAMPGAVL (35U)
 *   DRVGDYNIFST_SRVNOTAVLERR (96U)
 *   DRVGDYNIFST_IFINID (128U)
 *   DRVGDYNIFST_SRVNOTAVLSTBPMA (224U)
 *   DRVGDYNIFST_SRVNOTAVLSTBEPSSTS (225U)
 *   DRVGDYNIFST_INVLDSIG (255U)
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
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 *   SYSST_DI (0U)
 *   SYSST_OFF (1U)
 *   SYSST_ENA (2U)
 *   SYSST_WRMININ (3U)
 *
 * Array Types:
 * ============
 * Ary1D_u08_3: Array with 3 element(s) of type uint8
 * DataArrayType_uint8_1: Array with 1 element(s) of type uint8
 * DataArrayType_uint8_2: Array with 2 element(s) of type uint8
 * DataArrayType_uint8_3: Array with 3 element(s) of type uint8
 * Dcm_Data140ByteType: Array with 140 element(s) of type uint8
 * Dcm_Data15ByteType: Array with 15 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data3ByteType: Array with 3 element(s) of type uint8
 * Dcm_Data7ByteType: Array with 7 element(s) of type uint8
 * Dcm_Data8ByteType: Array with 8 element(s) of type uint8
 * ProgCounterArrayType: Array with 4 element(s) of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_LrndPinionCentrHwTrvl(void)
 *   float32 *Rte_Pim_RoutineHwPosStrt(void)
 *   float32 *Rte_Pim_TarHwA(void)
 *   float32 *Rte_Pim_TarHwVel(void)
 *   uint32 *Rte_Pim_HandsONAbortTi(void)
 *   uint32 *Rte_Pim_HandsONStrtTi(void)
 *   uint32 *Rte_Pim_HwAgAbortTi(void)
 *   uint32 *Rte_Pim_HwVelAbortTi(void)
 *   uint32 *Rte_Pim_MilesKmEeprom(void)
 *   uint32 *Rte_Pim_OperStEnaWaitTi(void)
 *   uint32 *Rte_Pim_PrevCycleMilesKmEeprom(void)
 *   uint16 *Rte_Pim_ActvRid(void)
 *   uint16 *Rte_Pim_ProgCntr(void)
 *   uint16 *Rte_Pim_ProgCntrMaxVal(void)
 *   uint8 *Rte_Pim_LockToLockRountineSts(void)
 *   boolean *Rte_Pim_HandsONAbort(void)
 *   boolean *Rte_Pim_HandsONStrt(void)
 *   boolean *Rte_Pim_HwAgOrHwVelChkRes(void)
 *   boolean *Rte_Pim_OperStPreStrtChk(void)
 *   uint8 *Rte_Pim_TestStamp(void)
 *     Returnvalue: uint8* is of type Ary1D_u08_3
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint16 Rte_CData_NvmProgCntr_DefaultValue(void)
 *   uint16 Rte_CData_ProgCntrMaxValDft(void)
 *
 *********************************************************************************************************************/


#define BmwDiagcSrvHndlg_START_SEC_CODE
#include "BmwDiagcSrvHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlMileageRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_1700_KmStand>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwOdomDst_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_BmwOdomDstVld_Logl(boolean *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlMileageRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_1700_KmStand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlMileageRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlMileageRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlMileageRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Read_BmwOdomDst_Val;
  boolean Read_BmwOdomDstVld_Logl;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDst_Val(&Read_BmwOdomDst_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDstVld_Logl(&Read_BmwOdomDstVld_Logl);
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

  BmwDiagcSrvHndlg_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgAmbTRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_2805_Aussentemperatur>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EcuTFild_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgAmbTRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_2805_Aussentemperatur_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgAmbTRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgAmbTRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgAmbTRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_EcuTFild_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_EcuTFild_Val(&Read_EcuTFild_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsBaseNwRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_1750_FUwBn>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwBasPtlNetCtrl_Val(BmwBasPtlNetCtrl1 *data)
 *   Std_ReturnType Rte_Read_BmwVehCdn_Val(BmwVehCdn1 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsBaseNwRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_1750_FUwBn_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsBaseNwRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsBaseNwRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsBaseNwRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwBasPtlNetCtrl1 Read_BmwBasPtlNetCtrl_Val;
  BmwVehCdn1 Read_BmwVehCdn_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwBasPtlNetCtrl_Val(&Read_BmwBasPtlNetCtrl_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwVehCdn_Val(&Read_BmwVehCdn_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsBattVltgRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_2866_Betriebsspannung>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BrdgVltg_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsBattVltgRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_2866_Betriebsspannung_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsBattVltgRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsBattVltgRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsBattVltgRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BrdgVltg_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BrdgVltg_Val(&Read_BrdgVltg_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsFactryIninRes_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_EpsInitialisierungWerk_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsFactryIninRes_Oper(Dcm_OpStatusType OpStatus, uint8 *StatRoutineStatus_Out, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninRes_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninRes_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsFactryIninStop_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_EpsInitialisierungWerk_Routine>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LockToLockEna_Logl(boolean data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsFactryIninStop_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninStop_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninStop_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninStop_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Write_LockToLockEna_Logl(Rte_InitValue_LockToLockEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  return RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_EpsInitialisierungWerk_Routine>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LockToLockEna_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SetInpPrm_Oper(float32 TarVel_Arg, float32 TarA_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper(uint8 Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper(uint8 Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  float32 Read_HwVel_Val;
  boolean Read_LongTermRackCentrCmpl_Logl;
  float32 Read_PinionAgConf_Val;
  SysSt1 Read_SysSt_Val;
  float32 Read_VehSpd_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  uint32 Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermRackCentrCmpl_Logl(&Read_LongTermRackCentrCmpl_Logl);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAgConf_Val(&Read_PinionAgConf_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_SysSt_Val(&Read_SysSt_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Write_LockToLockEna_Logl(Rte_InitValue_LockToLockEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_GetRefTmr1MicroSec32bit_Oper(&Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg);
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
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_GetTiSpan1MicroSec32bit_Oper(0U, &Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg);
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
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_SetInpPrm_Oper(0.0F, 0.0F);
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
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_EpsInitialisierungWerk_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_DB57_EpsRitzelwinkelsensor>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsPinionAgSnsrReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_DB57_EpsRitzelwinkelsensor>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_LongTermVehCentrCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_TurnCntrCorrlnSts_Val(uint8 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data7ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsPinionAgSnsrRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwVel_Val;
  boolean Read_LongTermRackCentrCmpl_Logl;
  boolean Read_LongTermVehCentrCmpl_Logl;
  float32 Read_PinionAg_Val;
  uint8 Read_TurnCntrCorrlnSts_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermRackCentrCmpl_Logl(&Read_LongTermRackCentrCmpl_Logl);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermVehCentrCmpl_Logl(&Read_LongTermVehCentrCmpl_Logl);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAg_Val(&Read_PinionAg_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_TurnCntrCorrlnSts_Val(&Read_TurnCntrCorrlnSts_Val);
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

  return RTE_E_DataServices_DID_DB57_EpsRitzelwinkelsensor_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_DID_2503_ProgrammingCounterMaxValue>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ProgCntrMaxVal_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper(const uint8 *Data, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsProgCntrMaxValWrite_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_ProgCntrMaxVal_SetRamBlockStatus(FALSE);
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

  return RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwRackCentrToVehCentrOffs_Val(float32 *data)
 *   Std_ReturnType Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(boolean *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BmwRackCentrToVehCentrOffs_Val;
  boolean Read_BmwRackCntrToVehCntrOffsVld_Logl;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwRackCentrToVehCentrOffs_Val(&Read_BmwRackCentrToVehCentrOffs_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(&Read_BmwRackCntrToVehCntrOffsVld_Logl);
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

  return RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BmwHwAgOffs_Val(float32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetVehCentrPosn_Oper(BmwSetVehCentrOffsSts1 *BmwSetVehCentrOffsSts_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsSteerAgSnsrCalWrite_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  BmwSetVehCentrOffsSts1 Call_SetVehCentrPosn_Oper_BmwSetVehCentrOffsSts_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Write_BmwHwAgOffs_Val(Rte_InitValue_BmwHwAgOffs_Val);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_SetVehCentrPosn_Oper(&Call_SetVehCentrPosn_Oper_BmwSetVehCentrOffsSts_Arg);
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
    case RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_DataServices_DID_DB5A_EpsLenkwinkelsensorKalibrierung_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_1000_Pruefstempel>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_1000_Pruefstempel_DCM_E_PENDING
 *   RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsTestStampReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsTestStampRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_1000_Pruefstempel>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_TestStamp_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsTestStampRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_1000_Pruefstempel_DCM_E_PENDING
 *   RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsTestStampRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsTestStampRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  NvM_RequestResultType Call_TestStamp_GetErrorStatus_ErrorStatus_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_TestStamp_GetErrorStatus(&Call_TestStamp_GetErrorStatus_ErrorStatus_Arg);
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

  return RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgEpsTestStampWrite_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_DID_1000_Pruefstempel>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_TestStamp_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgEpsTestStampWrite_Oper(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_1000_Pruefstempel_DCM_E_PENDING
 *   RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsTestStampWrite_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsTestStampWrite_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsTestStampWrite_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_TestStamp_SetRamBlockStatus(FALSE);
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

  return RTE_E_DataServices_DID_1000_Pruefstempel_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgHwAgRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_5003_HwAg>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwPinionAg_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgHwAgRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_5003_HwAg_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgHwAgRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgHwAgRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgHwAgRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_BmwPinionAg_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAg_Val(&Read_BmwPinionAg_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgHwTqRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_500E_HwTq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgHwTqRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_500E_HwTq_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgHwTqRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgHwTqRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgHwTqRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_2540_MileKmEeprom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_2540_MileKmEeprom_DCM_E_PENDING
 *   RTE_E_DataServices_DID_2540_MileKmEeprom_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgMileKmEepromReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_2540_MileKmEeprom_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgMileKmEepromRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_2540_MileKmEeprom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwOdomDst_Val(uint32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgMileKmEepromRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_2540_MileKmEeprom_DCM_E_PENDING
 *   RTE_E_DataServices_DID_2540_MileKmEeprom_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgMileKmEepromRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMileKmEepromRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgMileKmEepromRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Read_BmwOdomDst_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDst_Val(&Read_BmwOdomDst_Val);
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

  return RTE_E_DataServices_DID_2540_MileKmEeprom_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgMotTqRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_500F_MotTq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotTqCmdMrfScad_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgMotTqRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_500F_MotTq_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgMotTqRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgMotTqRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgMotTqRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_MotTqCmdMrfScad_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_MotTqCmdMrfScad_Val(&Read_MotTqCmdMrfScad_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_2503_ProgrammingCounterMaxValue>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper(Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgProgmCntrMaxValReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_2503_ProgrammingCounterMaxValue>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgProgmCntrMaxValRead_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_2503_ProgrammingCounterMaxValue_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgProgmCntrRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_2502_ProgCounter>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ProgCntr_GetErrorStatus(NvM_RequestResultType *ErrorStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgProgmCntrRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type ProgCounterArrayType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ProgCounter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgProgmCntrRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgProgmCntrRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgProgmCntrRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  NvM_RequestResultType Call_ProgCntr_GetErrorStatus_ErrorStatus_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_ProgCntr_GetErrorStatus(&Call_ProgCntr_GetErrorStatus_ErrorStatus_Arg);
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

  return RTE_E_DataServices_ProgCounter_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgPscmStsRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_500C_PscmSts>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
 *   Std_ReturnType Rte_Read_PinionAgConf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcActv_Oper(NtcNr1 NtcNr, boolean *NtcActv)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcActv1_PortIf1_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgPscmStsRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_500C_PscmSts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgPscmStsRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgPscmStsRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgPscmStsRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  DrvgDynIfSt1 Read_DrvgDynIfSt_Val;
  float32 Read_PinionAgConf_Val;
  SysSt1 Read_SysSt_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  boolean Call_GetNtcActv_Oper_NtcActv = FALSE;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_DrvgDynIfSt_Val(&Read_DrvgDynIfSt_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAgConf_Val(&Read_PinionAgConf_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_SysSt_Val(&Read_SysSt_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_GetNtcActv_Oper(0U, &Call_GetNtcActv_Oper_NtcActv);
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
    case RTE_E_GetNtcActv1_PortIf1_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_250B_ReadSwRevision>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_250B_ReadSwRevision_DCM_E_PENDING
 *   RTE_E_DataServices_DID_250B_ReadSwRevision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgReadSwRevisionCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_250B_ReadSwRevision_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgReadSwRevision_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_250B_ReadSwRevision>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgReadSwRevision_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data140ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_250B_ReadSwRevision_DCM_E_PENDING
 *   RTE_E_DataServices_DID_250B_ReadSwRevision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgReadSwRevision_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgReadSwRevision_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgReadSwRevision_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_250B_ReadSwRevision_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_DFDD_GelernterZahnstangenweg>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_DFDD_GelernterZahnstangenweg>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RackCentrMotAgErrPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_TotRackTrvl_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgStordRackTrvlAndCentrDataRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_RackCentrMotAgErrPrsnt_Logl;
  float32 Read_TotRackTrvl_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgErrPrsnt_Logl(&Read_RackCentrMotAgErrPrsnt_Logl);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_TotRackTrvl_Val(&Read_TotRackTrvl_Val);
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

  return RTE_E_DataServices_DID_DFDD_GelernterZahnstangenweg_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_F18A_SystemSupplierIdentifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgSysSupplierIdentifierCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_F18A_SystemSupplierIdentifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgSysSupplierIdentifierRead_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_F18A_SystemSupplierIdentifier_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvFHndlgVehSpdRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_2867_Fahrzeuggeschwindigkeit>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvFHndlgVehSpdRead_Oper(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_2867_Fahrzeuggeschwindigkeit_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgVehSpdRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgVehSpdRead_Oper(P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgVehSpdRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_VehSpd_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsCommuteRes_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_EpsPendeln_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsCommuteRes_Oper(Dcm_OpStatusType OpStatus, uint8 *StatEpsPendelnAktivNr_Out, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsPendeln_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsCommuteRes_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsCommuteRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatEpsPendelnAktivNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsCommuteRes_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsPendeln_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsCommuteStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_EpsPendeln_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsCommuteStrt_Oper(uint8 Frequenz_In, uint8 MaxAmplitude_In, uint8 NumberOfCycles_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsPendeln_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsPendeln_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsCommuteStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsCommuteStrt_Oper(uint8 Frequenz_In, uint8 MaxAmplitude_In, uint8 NumberOfCycles_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsCommuteStrt_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsPendeln_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsIninSrvRes_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_EpsInitialisierungService_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsIninSrvRes_Oper(Dcm_OpStatusType OpStatus, uint8 *StatRoutineStatus_Out, uint8 *StatLenkradwinkelWert_Out, uint8 *StatSensorZustandNr_Out, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument StatLenkradwinkelWert_Out: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsIninSrvRes_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsIninSrvRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatRoutineStatus_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatLenkradwinkelWert_Out, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatSensorZustandNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsIninSrvRes_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsIninSrvStop_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_EpsInitialisierungService_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsIninSrvStop_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsIninSrvStop_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsIninSrvStop_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsIninSrvStop_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsIninSrvStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_EpsInitialisierungService_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsIninSrvStrt_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsIninSrvStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsIninSrvStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsIninSrvStrt_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsInitialisierungService_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsProcRes_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_EpsVerfahren_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsProcRes_Oper(Dcm_OpStatusType OpStatus, uint8 *StatEpsVerfahrenAktivNr_Out, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsVerfahren_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsProcRes_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsProcRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) StatEpsVerfahrenAktivNr_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsProcRes_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsVerfahren_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsProcStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_EpsVerfahren_Routine>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsProcStrt_Oper(const uint8 *Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, uint8 AbsolutEin_In, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Winkel_In: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsVerfahren_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsVerfahren_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsProcStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsProcStrt_Oper(P2CONST(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_DATA) Winkel_In, uint8 Winkelgeschwindigkeit_In, uint8 Winkelbeschleunigung_In, uint8 AbsolutEin_In, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsProcStrt_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_RoutineServices_EpsVerfahren_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_SteuernEpsMultiturnwertReset_Routine>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_ClrVehCentrPosn_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RstRackCentrMotRev_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsPtlRackCentrRstStrt_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_VehSpd_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper();
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
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_ClrVehCentrPosn_Oper();
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
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotRev_Oper();
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
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_SteuernEpsMultiturnwertReset_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_DC77_EpsZahnstangenmitte>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsRackCentrMotAgStsReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_DC77_EpsZahnstangenmitte>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_LongTermRackCentrCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RackCentrCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RackCentrMotAgErrPrsnt_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_RackCentrMotAgVld_Logl(boolean *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsRackCentrMotAgStsRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  boolean Read_LongTermRackCentrCmpl_Logl;
  boolean Read_RackCentrCmpl_Logl;
  boolean Read_RackCentrMotAgErrPrsnt_Logl;
  boolean Read_RackCentrMotAgVld_Logl;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_LongTermRackCentrCmpl_Logl(&Read_LongTermRackCentrCmpl_Logl);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrCmpl_Logl(&Read_RackCentrCmpl_Logl);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgErrPrsnt_Logl(&Read_RackCentrMotAgErrPrsnt_Logl);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_RackCentrMotAgVld_Logl(&Read_RackCentrMotAgVld_Logl);
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

  return RTE_E_DataServices_DID_DC77_EpsZahnstangenmitte_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_EpsZahnstangenmitteReset_Routine>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RstRackCentrMotAg_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RstRackCentrMotRev_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsRackCentrRstStrt_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwPinionAgQlfr1 Read_BmwPinionAgQlfr_Val;
  float32 Read_VehSpd_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAgQlfr_Val(&Read_BmwPinionAgQlfr_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper();
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
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotAg_Oper();
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
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotRev_Oper();
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
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_EpsZahnstangenmitteReset_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data)
 *   Std_ReturnType Rte_Read_VehSpd_Val(float32 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_ClrVehCentrPosn_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RstRackCentrMotRev_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_PENDING
 *   RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsSteerAgSnsrCalRstStrt_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BmwPinionAgQlfr1 Read_BmwPinionAgQlfr_Val;
  float32 Read_VehSpd_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwPinionAgQlfr_Val(&Read_BmwPinionAgQlfr_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_VehSpd_Val(&Read_VehSpd_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper();
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
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_ClrVehCentrPosn_Oper();
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
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_RstRackCentrMotRev_Oper();
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
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_FORCE_RCRRP:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_DCM_E_PENDING:
      fct_error = 1;
      break;
    case RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_RoutineServices_EpsLenkwinkelsensorKalibrierungReset_Routine_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_DB99_EpsMomentensensor>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB99_EpsMomentensensor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB99_EpsMomentensensor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsTqSensrReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_DB99_EpsMomentensensor_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgEpsTqSensrRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_DB99_EpsMomentensensor>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwTqIdptSig_Val(uint8 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgEpsTqSensrRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB99_EpsMomentensensor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB99_EpsMomentensensor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsTqSensrRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgEpsTqSensrRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgEpsTqSensrRead_Oper (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  float32 Read_HwTq_Val;
  uint8 Read_HwTqIdptSig_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwTqIdptSig_Val(&Read_HwTqIdptSig_Val);
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

  return RTE_E_DataServices_DID_DB99_EpsMomentensensor_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgInit1
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgPer1
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
 *   Std_ReturnType Rte_Read_BmwOdomDst_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_HwTq_Val(float32 *data)
 *   Std_ReturnType Rte_Read_HwVel_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionAg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnHwTrvl_Val(float32 *data)
 *   Std_ReturnType Rte_Read_PinionCentrLrnSt_Val(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LockToLockEna_Logl(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MilesKmEeprom_SetRamBlockStatus(boolean RamBlockStatus_Arg)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgPer1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgPer1
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint32 Read_BmwOdomDst_Val;
  float32 Read_HwTq_Val;
  float32 Read_HwVel_Val;
  float32 Read_PinionAg_Val;
  float32 Read_PinionCentrLrnHwTrvl_Val;
  uint8 Read_PinionCentrLrnSt_Val;

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  uint32 Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg = 0U;
  uint32 Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_BmwOdomDst_Val(&Read_BmwOdomDst_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwTq_Val(&Read_HwTq_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_HwVel_Val(&Read_HwVel_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_PinionAg_Val(&Read_PinionAg_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_PinionCentrLrnHwTrvl_Val(&Read_PinionCentrLrnHwTrvl_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Read_PinionCentrLrnSt_Val(&Read_PinionCentrLrnSt_Val);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Write_LockToLockEna_Logl(Rte_InitValue_LockToLockEna_Logl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_GetRefTmr1MicroSec32bit_Oper(&Call_GetRefTmr1MicroSec32bit_Oper_RefTmr_Arg);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_GetTiSpan1MicroSec32bit_Oper(0U, &Call_GetTiSpan1MicroSec32bit_Oper_TiSpan_Arg);
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

  fct_status = TSC_BmwDiagcSrvHndlg_Rte_Call_MilesKmEeprom_SetRamBlockStatus(FALSE);
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_DB3C_StatusFzgBordnetz>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgStatusFzgBordnetzReadCdnChk_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_DB3C_StatusFzgBordnetz>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_DCM_E_PENDING
 *   RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) Data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvHndlgStatusFzgBordnetzRead_Oper (returns application error)
 *********************************************************************************************************************/

  float32 PimLrndPinionCentrHwTrvl;
  float32 PimRoutineHwPosStrt;
  float32 PimTarHwA;
  float32 PimTarHwVel;
  uint32 PimHandsONAbortTi;
  uint32 PimHandsONStrtTi;
  uint32 PimHwAgAbortTi;
  uint32 PimHwVelAbortTi;
  uint32 PimMilesKmEeprom;
  uint32 PimOperStEnaWaitTi;
  uint32 PimPrevCycleMilesKmEeprom;
  uint16 PimActvRid;
  uint16 PimProgCntr;
  uint16 PimProgCntrMaxVal;
  uint8 PimLockToLockRountineSts;
  boolean PimHandsONAbort;
  boolean PimHandsONStrt;
  boolean PimHwAgOrHwVelChkRes;
  boolean PimOperStPreStrtChk;
  Ary1D_u08_3 PimTestStamp;

  uint16 NvmProgCntr_DefaultValue_data;
  uint16 ProgCntrMaxValDft_data;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  PimLrndPinionCentrHwTrvl = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LrndPinionCentrHwTrvl() = PimLrndPinionCentrHwTrvl;
  PimRoutineHwPosStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_RoutineHwPosStrt() = PimRoutineHwPosStrt;
  PimTarHwA = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwA() = PimTarHwA;
  PimTarHwVel = *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_TarHwVel() = PimTarHwVel;
  PimHandsONAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbortTi() = PimHandsONAbortTi;
  PimHandsONStrtTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrtTi() = PimHandsONStrtTi;
  PimHwAgAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgAbortTi() = PimHwAgAbortTi;
  PimHwVelAbortTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwVelAbortTi() = PimHwVelAbortTi;
  PimMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_MilesKmEeprom() = PimMilesKmEeprom;
  PimOperStEnaWaitTi = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStEnaWaitTi() = PimOperStEnaWaitTi;
  PimPrevCycleMilesKmEeprom = *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_PrevCycleMilesKmEeprom() = PimPrevCycleMilesKmEeprom;
  PimActvRid = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ActvRid() = PimActvRid;
  PimProgCntr = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntr() = PimProgCntr;
  PimProgCntrMaxVal = *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_ProgCntrMaxVal() = PimProgCntrMaxVal;
  PimLockToLockRountineSts = *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_LockToLockRountineSts() = PimLockToLockRountineSts;
  PimHandsONAbort = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONAbort() = PimHandsONAbort;
  PimHandsONStrt = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HandsONStrt() = PimHandsONStrt;
  PimHwAgOrHwVelChkRes = *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_HwAgOrHwVelChkRes() = PimHwAgOrHwVelChkRes;
  PimOperStPreStrtChk = *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk();
  *TSC_BmwDiagcSrvHndlg_Rte_Pim_OperStPreStrtChk() = PimOperStPreStrtChk;

  (void)memcpy(PimTestStamp, TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), sizeof(Ary1D_u08_3));
  (void)memcpy(TSC_BmwDiagcSrvHndlg_Rte_Pim_TestStamp(), PimTestStamp, sizeof(Ary1D_u08_3));


  NvmProgCntr_DefaultValue_data = TSC_BmwDiagcSrvHndlg_Rte_CData_NvmProgCntr_DefaultValue();
  ProgCntrMaxValDft_data = TSC_BmwDiagcSrvHndlg_Rte_CData_ProgCntrMaxValDft();

  return RTE_E_DataServices_DID_DB3C_StatusFzgBordnetz_E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwDiagcSrvHndlg_STOP_SEC_CODE
#include "BmwDiagcSrvHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void BmwDiagcSrvHndlg_TestDefines(void)
{
  /* Enumeration Data Types */

  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_1 = NoCommunication;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_2 = ParkingNotOk;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_3 = ParkingOk;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_4 = StandingFunctions;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_5 = Living;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_6 = CheckDiagnosticAnalysis;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_7 = DriverPreparingforOperation;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_8 = Driving;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_9 = DriverPreparingToExitOperation;
  BmwBasPtlNetCtrl1 Test_BmwBasPtlNetCtrl1_V_10 = Invalid;

  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_1 = BMWPINIONAGQLFR_SIGVALVLDANDPLAUS;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_2 = BMWPINIONAGQLFR_SIGVALVLD;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_3 = BMWPINIONAGQLFR_SUBVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_4 = BMWPINIONAGQLFR_INIT;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_5 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFAVRGQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_6 = BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_7 = BMWPINIONAGQLFR_ADJMTVALSETINUSRSIG;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_8 = BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP;
  BmwPinionAgQlfr1 Test_BmwPinionAgQlfr1_V_9 = BMWPINIONAGQLFR_INVLDSIG;

  BmwSetVehCentrOffsSts1 Test_BmwSetVehCentrOffsSts1_V_1 = BMWVEHCENTROFFSSTS_OFFSPRFMD;
  BmwSetVehCentrOffsSts1 Test_BmwSetVehCentrOffsSts1_V_2 = BMWVEHCENTROFFSSTS_OFFSFAILD;
  BmwSetVehCentrOffsSts1 Test_BmwSetVehCentrOffsSts1_V_3 = BMWVEHCENTROFFSSTS_OFFSFAILDVALOUTOFRNG;

  BmwVehCdn1 Test_BmwVehCdn1_V_1 = BMWVEHCDN_PRKGNBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_2 = BMWVEHCDN_PRKGBNOK;
  BmwVehCdn1 Test_BmwVehCdn1_V_3 = BMWVEHCDN_FCTCUSTNOTINFZG;
  BmwVehCdn1 Test_BmwVehCdn1_V_4 = BMWVEHCDN_LVNG;
  BmwVehCdn1 Test_BmwVehCdn1_V_5 = BMWVEHCDN_CHKDIAGCANLS;
  BmwVehCdn1 Test_BmwVehCdn1_V_6 = BMWVEHCDN_DRVRPREPGFOROPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_7 = BMWVEHCDN_DRVG;
  BmwVehCdn1 Test_BmwVehCdn1_V_8 = BMWVEHCDN_DRVRPREPGFOREXITOPER;
  BmwVehCdn1 Test_BmwVehCdn1_V_9 = BMWVEHCDN_INVLD;

  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_1 = DCM_E_POSITIVERESPONSE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_2 = DCM_E_GENERALREJECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_3 = DCM_E_SERVICENOTSUPPORTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_4 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_5 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_6 = DCM_E_RESPONSETOOLONG;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_7 = DCM_E_BUSYREPEATREQUEST;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_8 = DCM_E_CONDITIONSNOTCORRECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_9 = DCM_E_REQUESTSEQUENCEERROR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_10 = DCM_E_NORESPONSEFROMSUBNETCOMPONENT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_11 = DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_12 = DCM_E_REQUESTOUTOFRANGE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_13 = DCM_E_SECURITYACCESSDENIED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_14 = DCM_E_INVALIDKEY;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_15 = DCM_E_EXCEEDNUMBEROFATTEMPTS;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_16 = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_17 = DCM_E_UPLOADDOWNLOADNOTACCEPTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_18 = DCM_E_TRANSFERDATASUSPENDED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_19 = DCM_E_GENERALPROGRAMMINGFAILURE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_20 = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_21 = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_22 = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_23 = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_24 = DCM_E_RPMTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_25 = DCM_E_RPMTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_26 = DCM_E_ENGINEISRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_27 = DCM_E_ENGINEISNOTRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_28 = DCM_E_ENGINERUNTIMETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_29 = DCM_E_TEMPERATURETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_30 = DCM_E_TEMPERATURETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_31 = DCM_E_VEHICLESPEEDTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_32 = DCM_E_VEHICLESPEEDTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_33 = DCM_E_THROTTLE_PEDALTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_34 = DCM_E_THROTTLE_PEDALTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_35 = DCM_E_TRANSMISSIONRANGENOTINNEUTRAL;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_36 = DCM_E_TRANSMISSIONRANGENOTINGEAR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_37 = DCM_E_BRAKESWITCH_NOTCLOSED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_38 = DCM_E_SHIFTERLEVERNOTINPARK;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_39 = DCM_E_TORQUECONVERTERCLUTCHLOCKED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_40 = DCM_E_VOLTAGETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_41 = DCM_E_VOLTAGETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_42 = DCM_E_VMSCNC_0;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_43 = DCM_E_VMSCNC_1;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_44 = DCM_E_VMSCNC_2;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_45 = DCM_E_VMSCNC_3;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_46 = DCM_E_VMSCNC_4;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_47 = DCM_E_VMSCNC_5;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_48 = DCM_E_VMSCNC_6;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_49 = DCM_E_VMSCNC_7;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_50 = DCM_E_VMSCNC_8;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_51 = DCM_E_VMSCNC_9;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_52 = DCM_E_VMSCNC_A;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_53 = DCM_E_VMSCNC_B;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_54 = DCM_E_VMSCNC_C;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_55 = DCM_E_VMSCNC_D;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_56 = DCM_E_VMSCNC_E;

  Dcm_OpStatusType Test_Dcm_OpStatusType_V_1 = DCM_INITIAL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_2 = DCM_PENDING;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_3 = DCM_CANCEL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_4 = DCM_FORCE_RCRRP_OK;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_5 = DCM_FORCE_RCRRP_NOT_OK;

  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_1 = DRVGDYNIFST_IFAVLRDYFOROPERWOADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_2 = DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_3 = DRVGDYNIFST_IFAVLRDYFOROPERADDLDAMPG;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_4 = DRVGDYNIFST_IFACTVADDLDAMPGAVL;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_5 = DRVGDYNIFST_SRVNOTAVLERR;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_6 = DRVGDYNIFST_IFINID;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_7 = DRVGDYNIFST_SRVNOTAVLSTBPMA;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_8 = DRVGDYNIFST_SRVNOTAVLSTBEPSSTS;
  DrvgDynIfSt1 Test_DrvgDynIfSt1_V_9 = DRVGDYNIFST_INVLDSIG;

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

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;

  SysSt1 Test_SysSt1_V_1 = SYSST_DI;
  SysSt1 Test_SysSt1_V_2 = SYSST_OFF;
  SysSt1 Test_SysSt1_V_3 = SYSST_ENA;
  SysSt1 Test_SysSt1_V_4 = SYSST_WRMININ;
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
