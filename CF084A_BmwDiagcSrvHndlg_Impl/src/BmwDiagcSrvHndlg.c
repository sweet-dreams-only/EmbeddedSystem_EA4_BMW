/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  BmwDiagcSrvHndlg.c
 *        Config:  C:/Component/BMW_5441_PSR_1234_V4/_Bmw_5441_Eps_Impl_A/autosar/EPS.dpa
 *     SW-C Type:  BmwDiagcSrvHndlg
 *  Generated at:  Wed Jan 17 18:32:20 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.15.0
 *                 RTE Core Version 1.15.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <BmwDiagcSrvHndlg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2017 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : BmwDiagcSrvHndlg.c
 * Module Description: BMW Diagnostics Services Hanlder
 * Project           : CBD
 * Author            : Akilan Rathakrishnan
 **********************************************************************************************************************
 * Version Control:
 * %version:          5 %
 * %derived_by:       tzyksv %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 12/10/17  1        AR       Initial version                                                               EA4#XXXXX
 * 01/17/18  2        AR       Updated DB57 Service to consider LongTermVehCentrCmpl 
                               and Turns counter correlatation status                                        EA4#19510
 * 05/18/18  3        AR       New services added for I-190 pre-delivery                                     EA4#XXXXX							   
 * 06/29/18  5        AR       Update CF084 To Match Input from CF071                                        EA4#25624							   
 *********************************************************************************************************************/
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
 * BmwBasPtlNetCtrl1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BmwMotAgSelnSt1
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
 * BmwVehCdn1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DrvgDynIfSt1
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
 * SysSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_BmwDiagcSrvHndlg.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Os.h" /* Included to access trusted functions */
#include "NxtrFixdPt.h"
#include "NxtrMath.h"
#include "Dlog_User.h"

# define DCM_E_PENDING                                               ((Std_ReturnType)10)  
 /* Routine Identifiers */
#define BMWDIAGCSRVHNDLGROUTINEEPSLOCKTOLOCKRID_CNT_U16 (0xAB72U)
#define BMWDIAGCSRVHNDLGROUTINEINACTV_CNT_U16           (0x0000U)
 
 /* Service States */
#define BMWDIAGCSRVHNDLGROUTINESTSDFT_CNT_U08    	(0x00U)
#define BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08     	(0x01U)
#define BMWDIAGCSRVHNDLGROUTINESTSPASSD_CNT_U08    	(0x02U)
#define BMWDIAGCSRVHNDLGROUTINESTSCNCLD_CNT_U08  	(0x03U)
#define BMWDIAGCSRVHNDLGROUTINESTSERR_CNT_U08      	(0x04U)
#define BMWDIAGCSRVHNDLGROUTINESTSHWVELHI_CNT_U08   (0x0AU)
#define BMWDIAGCSRVHNDLGROUTINESTSVEHSPD_CNT_U08    (0x0BU)
#define BMWDIAGCSRVHNDLGROUTINESTSHANDSON_CNT_U08 	(0x0CU)
#define BMWDIAGCSRVHNDLGROUTINESTSOBSTRCN_CNT_U08	(0x0DU)


/* Pinion Sensor Conditions */
#define CENTRNOTFOUND_CNT_U08 		 (0U)
#define RACKCENTRFOUND_CNT_U08 		 (1U)
#define VEHCENTRFOUND_CNT_U08 		 (2U)
#define RACKVEHCENTRNOTFOUND_CNT_U08 (3U)


/*TODO: following #defines shall be moved to calibration */
#define BMWDIAGCSRVHNDLGCUSTTRIMVEHSPDTHD_KPH_F32   (10.0f)   /*k_CustPosTrimVehSpdThres_kph_f32*/
#define BMWDIAGCSRVHNDLGGARAGEMODVEHSPDTHD_KPH_F32  (10.0f)   /*k_GarageModeVehSpdThres_kph_f32*/
#define BMWDIAGCSRVHNDLGOPERSTWAITTI_MICROSEC_U32   (300000U) /*k_CustSrvcOpStateWaitTime_mS_u16*/
#define BMWDIAGCSRVHNDLGHANDSONHWTQTHD_HWNWTMTR_F32 (4.0F)    /*k_CustSrvcHandsOnThres_HwNm_f32 */
#define BMWDIAGCSRVHNDLGHANDSONTI_MICROSEC_U32      (40000U)  /*k_CustSrvcHandsOnTime_mS_u16 */
#define BMWDIAGCSRVHNDLGHWVELTHD_HWRADPERSEC_F32    (10.5F)   /*k_CustSrvcHandwheelVelThres_HwRadpS_f32 */
#define BMWDIAGCSRVHNDLGHWVELTI_MICROSEC_U32        (100000U) /*k_CustSrvcHandwheelVelTime_mS_u16 */
#define TQPOSPOLARITY_CNT_S08                       (-1)      /*k_SComTrqPosPol_Cnt_s08 */
 /*TODO: Above #defines shall be moved to calibration */
 
#define LOCKTOLOCKTARHWVELLOLIM_DEGPS_F32			(1.0F)
#define LOCKTOLOCKTARHWVELHILIM_DEGPS_F32			(100.0F)
#define LOCKTOLOCKTARHWAGALOLIM_DEGSPSSQRD_F32		(10.0F)
#define LOCKTOLOCKTARHWAGAHILIM_DEGSPSSQRD_F32		(2000.0F)
#define LOCKTOLOCKTARHWASCA_DEGPSSQRDPCNT_U16		(10U)
#define PINIONAGMAXCONF_ULS_F32						(1.0F)

#define EOTPOSLOLIM_HWDEG_F32					(-1024.0F)
#define EOTPOSHILIM_HWDEG_F32					(1023.0F)	
#define EOTPOSSCALE_CNTSPHWDEG_F32				(100.0F)
#define CONVERTRADTODEG_DEGPRAD_F32				(57.2957795F)

#define HWVELLOLIM_HWDEGPERSEC_F32				(-1000.0F)
#define HWVELHILIM_HWDEGPERSEC_F32				(1000.0F)
#define HWVELSCA_CNT_F32					    (1.0F)
	
#define HWOFFSWRITELIM_CNT_U16				    (3000U)	

#define RACKCENTERINVLD_ULS_U16     ((uint16)4095U)
#define RACKOFFSSIGMIN_DEG_F32      (-89.9560546875F)
#define RACKOFFSSIGOFFS_DEG_F32     (-89.9560546875F)
#define RACKOFFSSIGMAX_DEG_F32      (89.9560546875F)
#define RACKOFFSSIGRESL_DEG_F32     (0.0439453125F)
#define HWOFFSSCA_HWDEGPERC_U0P16		FloatToFixd_u16_f32(0.01, NXTRFIXDPT_FLOATTOP16_ULS_F32)


/* Byte pack / unpack #defines */
#define GetHiHiByte(data)                ((uint8)(((uint32)(data))>>24))
#define GetHiLoByte(data)                ((uint8)(((uint32)(data))>>16))
#define GetLoHiByte(data)                ((uint8)(((uint32)(data))>>8))
#define GetLoLoByte(data)                ((uint8)(data))
#define Make16Bit(hiByte,loByte)         ((uint16)((((uint16)(hiByte))<<8)|((uint16)(loByte))))
										 
										 
#define PimTestStamp_u08         (*(Ary1D_u08_3*)(Rte_Pim_TestStamp()))
#define PimMilesKmEeprom_u32     (*(uint32*)(Rte_Pim_MilesKmEeprom()))
#define PimPrevCycleMilesKmEeprom_u32     (*(uint32*)(Rte_Pim_PrevCycleMilesKmEeprom()))

 									 
/* Local functions */										 
STATIC FUNC(void, BmwDiagcSrvHndlg_CODE) HwAgOrHwVelChk(uint8 RoutineSts_Cnt_T_u08);											 
STATIC FUNC(boolean, BmwDiagcSrvHndlg_CODE) OperStChk(void);	
STATIC FUNC(boolean, BmwDiagcSrvHndlg_CODE) HandsOnDetn (uint8 RoutineSts_Cnt_T_u08);	
STATIC FUNC(uint8, BmwDiagcSrvHndlg_CODE) ChkRoutineCdn (boolean ChkHwPosAuthy_Cnt_T_Logl, uint8 PrsntRoutineSts_Cnt_T_u08);	
STATIC FUNC(uint8, BmwDiagcSrvHndlg_CODE) SnsrCdnChk(void);	

typedef union 
{
	float32 Float32Data;
	uint32  Uint32Data;
}Float32ToUint32Conv;					 

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
	/* DID 1700 – Mileage*/
	uint32 BmwOdomDst_Cnt_T_u32;
	boolean BmwOdomDstVld_Cnt_T_logl;
 
	(void)Rte_Read_BmwOdomDst_Val(&BmwOdomDst_Cnt_T_u32);
	(void)Rte_Read_BmwOdomDstVld_Logl(&BmwOdomDstVld_Cnt_T_logl);
	
	if(BmwOdomDstVld_Cnt_T_logl != FALSE)
	{
		Data[0u] = GetHiLoByte(BmwOdomDst_Cnt_T_u32);
		Data[1u] = GetLoHiByte(BmwOdomDst_Cnt_T_u32);
		Data[2u] = GetLoLoByte(BmwOdomDst_Cnt_T_u32);		
	}
	else
	{
		Data[0u] = 0xFFu;
		Data[1u] = 0xFFu;
		Data[2u] = 0xFFu;			
	}
	

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
	/* DID 2805 – Outside Temperature (Aussentemperatur)*/
	VAR(float32, AUTOMATIC)  EcuTFild_DegCgrd_T_f32;
	
	(void) Rte_Read_EcuTFild_Val(&EcuTFild_DegCgrd_T_f32);
	
	Data[0u] = (sint8)((sint16)FloatToFixd_s16_f32(EcuTFild_DegCgrd_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32));
	
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

	/*DID 1750 – Base Network (F_UW_BN) */
	VAR(BmwBasPtlNetCtrl1, AUTOMATIC) BmwBasPtlNetCtrl_Cnt_T_enum;
	VAR(BmwVehCdn1, AUTOMATIC) BmwVehCdn_Cnt_T_enum;

	(void)Rte_Read_BmwBasPtlNetCtrl_Val(&BmwBasPtlNetCtrl_Cnt_T_enum);
	(void)Rte_Read_BmwVehCdn_Val(&BmwVehCdn_Cnt_T_enum);

	Data[0u] = ((((((uint8)BmwVehCdn_Cnt_T_enum)  & 0x0Fu)) << 4u) |  (((uint8)BmwBasPtlNetCtrl_Cnt_T_enum) & 0x0Fu));

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
	/* DID 2866 – Battery Voltage (Betriebsspannung) */
	VAR(float32, AUTOMATIC)  BrdgVltg_V_T_f32;
	
	(void) Rte_Read_BrdgVltg_Val(&BrdgVltg_V_T_f32);
	
	Data[0u] = (uint8)((uint16)FloatToFixd_s16_f32(BrdgVltg_V_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32));	

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

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninRes_Oper(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) DcmDspRequestRoutineResultsOutSignal_StatRoutineStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninRes_Oper (returns application error)
 *********************************************************************************************************************/
	if (*Rte_Pim_LockToLockRountineSts() != BMWDIAGCSRVHNDLGROUTINESTSDFT_CNT_U08)
	{
		*DcmDspRequestRoutineResultsOutSignal_StatRoutineStatus = *Rte_Pim_LockToLockRountineSts();
		
		*ErrorCode = DCM_E_POSITIVERESPONSE;
	}
	else
	{
		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	}
	
	if (*ErrorCode != DCM_E_POSITIVERESPONSE)
	{		
		return E_NOT_OK;
	}
	
	return RTE_E_OK;

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
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_DcmDspRoutine_EpsInitialisierungWerk>
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
 *   RTE_E_RoutineServices_DcmDspRoutine_EpsInitialisierungWerk_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_DcmDspRoutine_EpsInitialisierungWerk_DCM_E_PENDING
 *   RTE_E_RoutineServices_DcmDspRoutine_EpsInitialisierungWerk_E_NOT_OK
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
	VAR(uint8, AUTOMATIC) CmsData_Cnt_T_u08[1u]; /* This is dummy variable - just to keep CMS happy */
	
 	if (*Rte_Pim_LockToLockRountineSts() == BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
	{
		
		(void)Rte_Write_LockToLockEna_Logl(FALSE);
		/* Cancel lock to lock routine */
		*Rte_Pim_LockToLockRountineSts() = BMWDIAGCSRVHNDLGROUTINESTSCNCLD_CNT_U08;
		/* Defeat Motor Torque Command Ramping Stop*/
		/* TODO: Calling CMS function stright from here. Actual design to be discussed */		
		(void)CmnMfgSrv_SrvF101RoutineStop(CmsData_Cnt_T_u08);
		
		/* Allow other routines to run */
		*Rte_Pim_ActvRid() = BMWDIAGCSRVHNDLGROUTINEINACTV_CNT_U16;
		
		/* Defeat Stall Motor Torque Limit Stop */
		/* TODO: Calling CMS function stright from here. Actual design to be discussed */
		(void)CmnMfgSrv_SrvF114RoutineStop(CmsData_Cnt_T_u08);

		*ErrorCode =  DCM_E_POSITIVERESPONSE;
	}
	else
	{
		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	}
 
	if (*ErrorCode != DCM_E_POSITIVERESPONSE)
	{		
		return E_NOT_OK;
	}
	
	return RTE_E_OK;

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

FUNC(Std_ReturnType, BmwDiagcSrvHndlg_CODE) BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper(uint8 DcmDspStartRoutineInSignal_Winkel, uint8 DcmDspStartRoutineInSignal_Winkelgeschwindigkeit, uint8 DcmDspStartRoutineInSignal_Winkelbeschleunigung, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_BMWDIAGCSRVHNDLG_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BmwDiagcSrvFHndlgEpsFactryIninStrt_Oper (returns application error)
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) TarHwVel_DegpS_T_f32;
	VAR(float32, AUTOMATIC) TarHwA_DegpSSqrd_T_f32;
	VAR(uint16, AUTOMATIC)  TarHwVel_DegpS_T_u16p0;
	VAR(uint16, AUTOMATIC)  TarHwA_Cnt_T_u16p0;
	VAR(uint8, AUTOMATIC)   CmsData_Cnt_T_u08[1u]; /* This is dummy variable - just to keep CMS happy */	
	VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl;

	(void)Rte_Read_LongTermRackCentrCmpl_Logl(&LongTermRackCentrCmpl_Cnt_T_logl);

	if(LongTermRackCentrCmpl_Cnt_T_logl == FALSE)
	{
		if(*Rte_Pim_LockToLockRountineSts() != BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
		{
			if( BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08 == ChkRoutineCdn(FALSE,*Rte_Pim_LockToLockRountineSts()))
			{
				/* The TargetAngle - DcmDspStartRoutineInSignal_Winkel not unused for EPS per F40 DSR */
				/* Target Handwheel velocity */
				TarHwVel_DegpS_T_u16p0 = (uint16)DcmDspStartRoutineInSignal_Winkelgeschwindigkeit;
				TarHwVel_DegpS_T_f32 = FixdToFloat_f32_u16(TarHwVel_DegpS_T_u16p0, NXTRFIXDPT_P0TOFLOAT_ULS_F32);
				*Rte_Pim_TarHwVel() = Lim_f32(TarHwVel_DegpS_T_f32, LOCKTOLOCKTARHWVELLOLIM_DEGPS_F32,LOCKTOLOCKTARHWVELHILIM_DEGPS_F32);
													
				/* Target Handwheel Acceleration */
				TarHwA_Cnt_T_u16p0 = (uint16)DcmDspStartRoutineInSignal_Winkelbeschleunigung;
				TarHwA_Cnt_T_u16p0 = TarHwA_Cnt_T_u16p0 * LOCKTOLOCKTARHWASCA_DEGPSSQRDPCNT_U16;
				TarHwA_DegpSSqrd_T_f32 = FixdToFloat_f32_u16(TarHwA_Cnt_T_u16p0, NXTRFIXDPT_P0TOFLOAT_ULS_F32);
				*Rte_Pim_TarHwA() = Lim_f32(TarHwA_DegpSSqrd_T_f32,LOCKTOLOCKTARHWAGALOLIM_DEGSPSSQRD_F32, LOCKTOLOCKTARHWAGAHILIM_DEGSPSSQRD_F32);

				*Rte_Pim_LockToLockRountineSts() = BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08;
				
				(void)Rte_Call_GetRefTmr1MicroSec32bit_Oper(Rte_Pim_HandsONAbortTi());					

				*Rte_Pim_ActvRid() = BMWDIAGCSRVHNDLGROUTINEEPSLOCKTOLOCKRID_CNT_U16;
				/* Defeat Stall Motor Torque Limit Start */
				/* TODO: Calling CMS function stright from here. Actual design to be discussed */				
				(void)CmnMfgSrv_SrvF114RoutineStrt(CmsData_Cnt_T_u08);
				
				*ErrorCode =  DCM_E_POSITIVERESPONSE;
							
			}
			else
			{
				*ErrorCode =  DCM_E_CONDITIONSNOTCORRECT;
			}

		}
		else
		{
			*ErrorCode =  DCM_E_REQUESTSEQUENCEERROR;
		}

	}
	else
	{
		*ErrorCode =  DCM_E_CONDITIONSNOTCORRECT;	 
	} 

	if (*ErrorCode != DCM_E_POSITIVERESPONSE)
	{		
		return E_NOT_OK;;
	}
	
  return RTE_E_OK;

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

	/* No Specific condition need to be checked */
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return RTE_E_OK;

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
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DcmDspData_EpsRitzelwinkelsensor>
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
    VAR(float32, AUTOMATIC) PinionAg_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwVel_HwDegPerSec_T_f32;
	VAR(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32;
    VAR(sint32, AUTOMATIC) PinionAg_HwDeg_T_s32;
	VAR(sint16, AUTOMATIC) HwVel_Cnt_T_s16;

	(void)Rte_Read_HwVel_Val(&HwVel_HwRadPerSec_T_f32);
	(void)Rte_Read_PinionAg_Val(&PinionAg_HwDeg_T_f32);

	/* Convert f32 into s32 */
	PinionAg_HwDeg_T_f32 = Lim_f32((PinionAg_HwDeg_T_f32*TQPOSPOLARITY_CNT_S08),EOTPOSLOLIM_HWDEG_F32,EOTPOSHILIM_HWDEG_F32);
	PinionAg_HwDeg_T_s32 = FloatToFixd_s32_f32((EOTPOSSCALE_CNTSPHWDEG_F32*PinionAg_HwDeg_T_f32), NXTRFIXDPT_FLOATTOP0_ULS_F32);
	/* Covert f32 into s16 */
	HwVel_HwDegPerSec_T_f32 = HwVel_HwRadPerSec_T_f32*CONVERTRADTODEG_DEGPRAD_F32* (float32)TQPOSPOLARITY_CNT_S08;
	HwVel_HwDegPerSec_T_f32 = Lim_f32(HwVel_HwDegPerSec_T_f32, HWVELLOLIM_HWDEGPERSEC_F32,HWVELHILIM_HWDEGPERSEC_F32);
	HwVel_Cnt_T_s16 = FloatToFixd_s16_f32(HwVel_HwDegPerSec_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32);

	Data[0u] = GetHiHiByte(PinionAg_HwDeg_T_s32);
	Data[1u] = GetHiLoByte(PinionAg_HwDeg_T_s32);
	Data[2u] = GetLoHiByte(PinionAg_HwDeg_T_s32);
	Data[3u] = GetLoLoByte(PinionAg_HwDeg_T_s32);
	
	Data[4u] = GetLoHiByte(HwVel_Cnt_T_s16);
	Data[5u] = GetLoLoByte(HwVel_Cnt_T_s16);
	
	Data[6u] = SnsrCdnChk();

	return RTE_E_OK;

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
	*Rte_Pim_ProgCntrMaxVal() = ((Data[0u] << 8u) | (Data[1u])); 
	(void)Rte_Call_ProgCntrMaxVal_SetRamBlockStatus(TRUE);
	*ErrorCode = DCM_E_POSITIVERESPONSE;

	return RTE_E_OK;

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

	/* No Specific condition need to be checked */
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return RTE_E_OK;

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
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DcmDspData_EpsLenkwinkelsensorKalibrierung>
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
	VAR(float32, AUTOMATIC) BmwRackCentrToVehCentrOffs_HwDeg_T_f32; 
	VAR(uint16, AUTOMATIC) BmwRackCentrToVehCentrOffs_Cnt_T_u16; 
	VAR(boolean, AUTOMATIC) BmwRackCntrToVehCntrOffsVld_Cnt_T_logl; 

	(void)Rte_Read_BmwRackCentrToVehCentrOffs_Val(&BmwRackCentrToVehCentrOffs_HwDeg_T_f32);
    (void)Rte_Read_BmwRackCntrToVehCntrOffsVld_Logl(&BmwRackCntrToVehCntrOffsVld_Cnt_T_logl);
	
    /* TODO: The logic used to set OFFS_GRD_MID_EPS signal is duplicated here.*/
    if (BmwRackCntrToVehCntrOffsVld_Cnt_T_logl == FALSE)
    {
        BmwRackCentrToVehCentrOffs_Cnt_T_u16 = RACKCENTERINVLD_ULS_U16;
    }
    else
    {
        BmwRackCentrToVehCentrOffs_HwDeg_T_f32 = Lim_f32((BmwRackCentrToVehCentrOffs_HwDeg_T_f32 * (float32)TQPOSPOLARITY_CNT_S08),
														   RACKOFFSSIGMIN_DEG_F32, 
														   RACKOFFSSIGMAX_DEG_F32);
        BmwRackCentrToVehCentrOffs_HwDeg_T_f32 = (BmwRackCentrToVehCentrOffs_HwDeg_T_f32 - RACKOFFSSIGOFFS_DEG_F32) / RACKOFFSSIGRESL_DEG_F32;
		
        BmwRackCentrToVehCentrOffs_Cnt_T_u16 = (uint16)BmwRackCentrToVehCentrOffs_HwDeg_T_f32;
    }	
	
	Data[0u] =  GetLoHiByte(BmwRackCentrToVehCentrOffs_Cnt_T_u16);
	Data[1u] =  GetLoLoByte(BmwRackCentrToVehCentrOffs_Cnt_T_u16);

	return RTE_E_OK;

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

	VAR(BmwSetVehCentrOffsSts1, AUTOMATIC) BmwSetVehCentrOffsSts_Cnt_T_enum;
	VAR(sint16, AUTOMATIC) HwOffs_Cnt_T_s16;
	VAR(sint32, AUTOMATIC) HwOffs_Cnt_T_s15p16;
	VAR(float32, AUTOMATIC) EPSHwOffsSnsrCal_Deg_T_f32;
	VAR(float32, AUTOMATIC) CustHwOffsSnsrCal_Deg_T_f32;


	/* TODO: From F40 DSR:
	This DID shall respond with a NRC $22 to a write request if a motor position fault is CURRENT. 
	This DID shall respond with a NRC $22 to a write request if the system has already been trimmed. 
	*/
	HwOffs_Cnt_T_s16 = (sint16)(Make16Bit(Data[0], Data[1]));

	if ( Abslt_u16_s16(HwOffs_Cnt_T_s16) <= HWOFFSWRITELIM_CNT_U16 )
	{
		HwOffs_Cnt_T_s15p16 = ((sint32)HwOffs_Cnt_T_s16) * ((sint32)HWOFFSSCA_HWDEGPERC_U0P16);
		
		CustHwOffsSnsrCal_Deg_T_f32 = FixdToFloat_f32_s32(HwOffs_Cnt_T_s15p16, NXTRFIXDPT_P16TOFLOAT_ULS_F32);
		/* Convert VehCenterOffset from customer to EPS reference frame for processing */
		EPSHwOffsSnsrCal_Deg_T_f32 = (CustHwOffsSnsrCal_Deg_T_f32)*((float32)TQPOSPOLARITY_CNT_S08);

		/*TODO: SetVehCentrPosn_Oper interface from CF071A doesn't accept Hw offset data from DCM. 
		 Hw Offset received from DCM must be written before calling this server runnable. SetVehCentrPosn_Oper will read it via RTE */		
		(void)Rte_Write_BmwHwAgOffs_Val(EPSHwOffsSnsrCal_Deg_T_f32);

		(void)Rte_Call_SetVehCentrPosn_Oper(&BmwSetVehCentrOffsSts_Cnt_T_enum);
		
		/*TODO: Error codes need to be checked */

		if(BmwSetVehCentrOffsSts_Cnt_T_enum == BMWVEHCENTROFFSSTS_OFFSPRFMD)
		{
			*ErrorCode = DCM_E_POSITIVERESPONSE;
		}
		else if (BmwSetVehCentrOffsSts_Cnt_T_enum == BMWVEHCENTROFFSSTS_OFFSFAILD)
		{
			*ErrorCode =  DCM_E_CONDITIONSNOTCORRECT;
		}
		else
		{
			*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
		}		
	}
	else
	{
		*ErrorCode  = DCM_E_REQUESTOUTOFRANGE;
	}	


	if (*ErrorCode != DCM_E_POSITIVERESPONSE)
	{		
		return E_NOT_OK;;
	}
	
	return RTE_E_OK;

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

	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return RTE_E_OK;

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

	Data[0u] = PimTestStamp_u08[0u];
	Data[1u] = PimTestStamp_u08[1u];
	Data[2u] = PimTestStamp_u08[2u];
	
	return RTE_E_OK;

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
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
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
	/* DID 1000 - Test Stamp */
	PimTestStamp_u08[0u] = Data[0u];
	PimTestStamp_u08[1u] = Data[1u];
	PimTestStamp_u08[2u] = Data[2u];

	(void)Rte_Call_TestStamp_SetRamBlockStatus(TRUE);

	*ErrorCode = DCM_E_POSITIVERESPONSE;

	return RTE_E_OK;

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
	/* DID 5003 – Handwheel Angle */
	VAR(float32, AUTOMATIC)  PinionAg_HwDeg_T_f32;
	VAR(sint16, AUTOMATIC)  PinionAg_HwDeg_T_s16;

	(void) Rte_Read_BmwPinionAg_Val(&PinionAg_HwDeg_T_f32);

	PinionAg_HwDeg_T_s16  = ((sint16)FloatToFixd_s16_f32(PinionAg_HwDeg_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32));

	Data[0u] = GetLoHiByte(PinionAg_HwDeg_T_s16);
	Data[1u] = GetLoLoByte(PinionAg_HwDeg_T_s16);

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

	/* DID 500E Handwheel Torque */

	VAR(float32,  AUTOMATIC)  HwTq_HwNwtMtr_T_f32;
	VAR(sint16,  AUTOMATIC)  HwTq_HwNwtMtr_T_s16;

	(void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
	
	HwTq_HwNwtMtr_T_f32 = HwTq_HwNwtMtr_T_f32*100u;
	HwTq_HwNwtMtr_T_s16  = ((sint16)FloatToFixd_s16_f32(HwTq_HwNwtMtr_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32));	
	/* Managing Float data to be read as Uint data */
	Data[0] = GetLoHiByte(HwTq_HwNwtMtr_T_s16);
	Data[1] = GetLoLoByte(HwTq_HwNwtMtr_T_s16);

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
	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return RTE_E_OK;

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

	Data[0u] = GetHiLoByte(PimPrevCycleMilesKmEeprom_u32);
	Data[1u] = GetLoHiByte(PimPrevCycleMilesKmEeprom_u32);
	Data[2u] = GetLoLoByte(PimPrevCycleMilesKmEeprom_u32);

	return RTE_E_OK;

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

	/* DID 500F – Commanded Motor Torque*/
	VAR(float32,  AUTOMATIC)  MotTqCmdMrfScad_MotNwtMtr_T_f32;
	VAR(sint16,  AUTOMATIC)  MotTqCmdMrfScad_MotNwtMtr_T_s16;

	Rte_Read_MotTqCmdMrfScad_Val(&MotTqCmdMrfScad_MotNwtMtr_T_f32);
	
	MotTqCmdMrfScad_MotNwtMtr_T_f32 = MotTqCmdMrfScad_MotNwtMtr_T_f32*10u;
	MotTqCmdMrfScad_MotNwtMtr_T_s16  = ((sint16)FloatToFixd_s16_f32(MotTqCmdMrfScad_MotNwtMtr_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32));	

	Data[0] = GetLoHiByte(MotTqCmdMrfScad_MotNwtMtr_T_s16);
	Data[1] = GetLoLoByte(MotTqCmdMrfScad_MotNwtMtr_T_s16);	
	

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
	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return RTE_E_OK;

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
	/* DID 2503 - Programming Counter Max Value */
	/* Default Max programming counter set to 1000*/
	Data[0u] = GetLoHiByte(*Rte_Pim_ProgCntrMaxVal());
	Data[1u] = GetLoLoByte(*Rte_Pim_ProgCntrMaxVal());  
	
	return RTE_E_OK;

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
	/* DID 2502 – Programming Counter */
	
	uint8 ProgSts_Cnt_T_u08;
	if((*Rte_Pim_ProgCntr()) == (*Rte_Pim_ProgCntrMaxVal()))
	{
		/* Control Unit no longer programmable */
		ProgSts_Cnt_T_u08 = 0x02u;
	}
	else if ((*Rte_Pim_ProgCntr()) == ((*Rte_Pim_ProgCntrMaxVal()) - 1u))
	{
		/* Control unit programmable atlease once. Bootloader shall still allow 
		complete reprogramming if abnormal termination of flashing happens when Program Counter is 1 */
		ProgSts_Cnt_T_u08 = 0x01u;
	}
	else
	{
		/* Control unit is programmable several times, bootloader replacement is possible */
		ProgSts_Cnt_T_u08 = 0x00u;
	}
	
	Data [0u] = ProgSts_Cnt_T_u08;
	Data [1u] = GetLoHiByte(*Rte_Pim_ProgCntr());
	Data [2u] = GetLoLoByte(*Rte_Pim_ProgCntr());
	
	return RTE_E_OK;

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
	VAR(boolean, AUTOMATIC)       NTCB0Sts_Cnt_T_Logl;
	VAR(boolean, AUTOMATIC)       NTCB5Sts_Cnt_T_Logl;
	VAR(Std_ReturnType, AUTOMATIC)       SysStRet_Cnt_T_enum;
	VAR(SysSt1, AUTOMATIC)        SysSt_Cnt_T_enum;
	VAR(DrvgDynIfSt1, AUTOMATIC)  DrvgDynIfSt_Cnt_T_enum;
	VAR(float32, AUTOMATIC)       PinionAgConf_Uls_T_f32;
	VAR(uint16, AUTOMATIC)        PscmSts_Cnt_T_u16 = 0U;

	SysStRet_Cnt_T_enum = Rte_Read_SysSt_Val(&SysSt_Cnt_T_enum);
	(void)Rte_Read_DrvgDynIfSt_Val(&DrvgDynIfSt_Cnt_T_enum);
	(void)Rte_Read_PinionAgConf_Val(&PinionAgConf_Uls_T_f32);	
	(void)Rte_Call_GetNtcActv_Oper(NTCNR_0X0B0, &NTCB0Sts_Cnt_T_Logl );
	(void)Rte_Call_GetNtcActv_Oper(NTCNR_0X0B5, &NTCB5Sts_Cnt_T_Logl );

	
	if(PinionAgConf_Uls_T_f32 < 1.0F)
	{ 
		PscmSts_Cnt_T_u16 |= 0x0200U; /* Set Bit position 9 */
	}
	
	if((NTCB0Sts_Cnt_T_Logl != FALSE) ||(NTCB5Sts_Cnt_T_Logl != FALSE))
	{
		PscmSts_Cnt_T_u16 |= 0x0400U; /* Set Bit position 10 */
	}
	if((DrvgDynIfSt_Cnt_T_enum == DRVGDYNIFST_IFACTVADDLDAMPGNOTAVL) || (DrvgDynIfSt_Cnt_T_enum == DRVGDYNIFST_IFACTVADDLDAMPGAVL))
	{
		PscmSts_Cnt_T_u16 |= 0x0800U; /* Set Bit position 11 */
	}
	if(SysStRet_Cnt_T_enum == RTE_E_OK)
	{
		PscmSts_Cnt_T_u16 |= (SysSt_Cnt_T_enum << 13U);
	}
	else
	{
		PscmSts_Cnt_T_u16 |= (0x07U << 13U);
	}
	
	Data[0u] = GetLoHiByte(PscmSts_Cnt_T_u16);
	Data[1u] = GetLoLoByte(PscmSts_Cnt_T_u16);
	
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
 

	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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
	#if 0
	uint8 DlogSvkCurrentData_Cnt_T_u08[120u];
	uint16 UserNumberOfSvkEntries_Cnt_T_u16;
	uint16 i;
	Std_ReturnType DlogSvkCurrentRet_Cnt_T_enum;
	Std_ReturnType BmwDiagcSrvRet_Cnt_T_enum;
	
	
	DlogSvkCurrentRet_Cnt_T_enum = Dlog_UserReadSvkCurrent(OpStatus, DlogSvkCurrentData_Cnt_T_u08,&UserNumberOfSvkEntries_Cnt_T_u16);
	
	if(DlogSvkCurrentRet_Cnt_T_enum == DCM_E_PENDING)
	{
		BmwDiagcSrvRet_Cnt_T_enum = DCM_E_PENDING;		
	}
	else if(DlogSvkCurrentRet_Cnt_T_enum == E_OK)
	{
		/* Copy to DCM buffer and update SW Revision number */
		
		/** Dlog Data buffer layout
		 *
		 * Description of response out parameter data:
		 * Offset       |  Value |  Description
		 * ------------ | ------ | -----------------
		 *    0         |   0x01 | SVK Version
		 *    1         |   0x.. | ProgrammingDependenciesChecked
		 *    2         |   0x.. | Number of XWEs: (MSB)
		 *    3         |   0x.. | Number of XWEs: (LSB)
		 *    4         |   0x.. | Fingerprint \#1 (MSB)
		 *   ...        |   ...  | ...
		 *    7         |   0x.. | Fingerprint \#m (LSB)
		 *    8         |   0x.. | XWE\#1, SGBM-ID, Byte\#1
		 *   ...        |   ...  | ...
		 *   15         |   0x.. | XWE\#1, SGBM-ID, Byte\#8
		 *   ...        |   ...  | ...
		 *  8+(n-1)*8   |   0x.. | XWE\#n, SGBM-ID, Byte\#1
		 *   ...        |   ...  | ...
		 * \lhref FL848,FL849
		 *
		 */		
		 
		 for(i = 0u; i < 16u; i++)
		 {
			 Data[i] = DlogSvkCurrentData_Cnt_T_u08[i]; 
		 } /* Copy data upto first SWE */
		 
		 /* Fill revision number for first SWE */
		 Data[16u] = 0x00u;
		 Data[17u] = 0x00u;
		 Data[18u] = 0x00u;
		 Data[19u] = 0x00u;
		 
		 for(i = 20u; i < 28u; i++) /* Only first 16 bytes of DlogSvkCurrentData_Cnt_T_u08 copied */
		 {
			 Data[i] = DlogSvkCurrentData_Cnt_T_u08[i-4u]; 
		 } /* Copy data upto second SWE */	
		 
		 /* Fill revision number for second SWE */
		 Data[28u] = 0x00u;
		 Data[29u] = 0x00u;
		 Data[30u] = 0x00u;
		 Data[31u] = 0x00u;
		 
		 
		 for(i = 32u; i < 40u; i++)/* Only first 24 bytes of DlogSvkCurrentData_Cnt_T_u08 copied */
		 {
			 Data[i] = DlogSvkCurrentData_Cnt_T_u08[i-8u]; 
		 } /* Copy data upto third SWE */			 

		 /* Fill revision number for third SWE */		 
		 Data[40u] = 0x00u;
		 Data[41u] = 0x00u;
		 Data[42u] = 0x00u;
		 Data[43u] = 0x00u;
		 
		 for(i = 44u; i < 52u; i++)/* Only first 32 bytes of DlogSvkCurrentData_Cnt_T_u08 copied */
		 {
			 Data[i] = DlogSvkCurrentData_Cnt_T_u08[i-12u]; 
		 } /* Copy data upto third SWE */		
		 
		 /* Fill revision number for fourth SWE */		 
		 Data[52u] = 0x00u;
		 Data[53u] = 0x00u;
		 Data[54u] = 0x00u;
		 Data[55u] = 0x00u;		 
		 
		BmwDiagcSrvRet_Cnt_T_enum = E_OK;	
	}	
	else
	{		
		BmwDiagcSrvRet_Cnt_T_enum = E_NOT_OK;
	}
	#endif
	
	return (E_NOT_OK);

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

	/* No Specific condition need to be checked */
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return RTE_E_OK;

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
	VAR(boolean, AUTOMATIC) RackCentrMotAgErrPrsnt_Cnt_T_logl;
	VAR(float32, AUTOMATIC) TotRackTrvl_HwDeg_T_f32;

	VAR(Float32ToUint32Conv, AUTOMATIC)   RackTrvl;
	/* Read values */
	(void)Rte_Read_RackCentrMotAgErrPrsnt_Logl(&RackCentrMotAgErrPrsnt_Cnt_T_logl);
	(void)Rte_Read_TotRackTrvl_Val(&TotRackTrvl_HwDeg_T_f32);

	/* Stored rack travel data */
	if(FALSE == RackCentrMotAgErrPrsnt_Cnt_T_logl)
	{
		TotRackTrvl_HwDeg_T_f32 = 0.0F;
	}	
	
	RackTrvl.Float32Data = TotRackTrvl_HwDeg_T_f32;
	 
	/* Managing Float data to be read as Uint data */
	Data[0] = GetHiHiByte(RackTrvl.Uint32Data);
	Data[1] = GetHiLoByte(RackTrvl.Uint32Data);
	Data[2] = GetLoHiByte(RackTrvl.Uint32Data);
	Data[3] = GetLoLoByte(RackTrvl.Uint32Data);

	/* Same value since the stored PIM is the same as the one that is transmitted */
	Data[4] = GetHiHiByte(RackTrvl.Uint32Data);
	Data[5] = GetHiLoByte(RackTrvl.Uint32Data);
	Data[6] = GetLoHiByte(RackTrvl.Uint32Data);
	Data[7] = GetLoLoByte(RackTrvl.Uint32Data);

	return RTE_E_OK;

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
	/* No Specific condition need to be checked */
  *ErrorCode = DCM_E_POSITIVERESPONSE;
  return RTE_E_OK;

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
	Data[0] = 0x00u;
	Data[1] = 0x00u;
	Data[2] = 0xB5u;

	return RTE_E_OK;

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
	/* DID 2867 – Vehicle Speed (FAHRZEUGGESCHWINDIGKEIT) */
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32; 

	(void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);

	if(VehSpd_Kph_T_f32 >= 255.0F)
	{
		VehSpd_Kph_T_f32 = 255.0F;
	}

	Data[0u]  =(uint8)((uint16)FloatToFixd_s16_f32(VehSpd_Kph_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32));	
	
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
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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

	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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

	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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

	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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

	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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

	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_DcmDspRoutine_SteuernEpsMultiturnwertReset>
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
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32; 

	(void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);


	if( VehSpd_Kph_T_f32 < BMWDIAGCSRVHNDLGCUSTTRIMVEHSPDTHD_KPH_F32)
	{
		Rte_Call_ClrVehCentrPosn_Oper();
		Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper();
		Os_Call_RstRackCentrMotRev_Oper();

		*ErrorCode = DCM_E_POSITIVERESPONSE;
	}
	else
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
	} 
	
	if (*ErrorCode != DCM_E_POSITIVERESPONSE)
	{		
		return E_NOT_OK;;
	}
	
	return RTE_E_OK;

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

	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return RTE_E_OK;

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
	VAR(boolean, AUTOMATIC) LongTermRackCentrCmpl_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) RackCentrCmpl_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) RackCentrMotAgErrPrsnt_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) RackCentrMotAgVld_Cnt_T_logl;

	(void)Rte_Read_LongTermRackCentrCmpl_Logl(&LongTermRackCentrCmpl_Cnt_T_logl);
	(void)Rte_Read_RackCentrCmpl_Logl(&RackCentrCmpl_Cnt_T_logl);
	(void)Rte_Read_RackCentrMotAgErrPrsnt_Logl(&RackCentrMotAgErrPrsnt_Cnt_T_logl);
	(void)Rte_Read_RackCentrMotAgVld_Logl(&RackCentrMotAgVld_Cnt_T_logl);
	
	Data[0u] = 0u;
	
	if(LongTermRackCentrCmpl_Cnt_T_logl == TRUE)
	{
		Data[0u] |= 0x01u;
	}
	if(RackCentrCmpl_Cnt_T_logl == TRUE)
	{
		Data[0u] |= 0x02u;		
	}
	if(RackCentrMotAgErrPrsnt_Cnt_T_logl == TRUE)
	{
		Data[0u] |= 0x04u;		
	}
	if(RackCentrMotAgVld_Cnt_T_logl == TRUE)
	{
		Data[0u] |= 0x08u;		
	}
 
	return RTE_E_OK;

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
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32; 
	VAR(BmwPinionAgQlfr1, AUTOMATIC) BmwPinionAgQlfr_Cnt_T_enum;

	(void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
	(void)Rte_Read_BmwPinionAgQlfr_Val(&BmwPinionAgQlfr_Cnt_T_enum);

	if( VehSpd_Kph_T_f32 < BMWDIAGCSRVHNDLGCUSTTRIMVEHSPDTHD_KPH_F32)
	{

		if((BmwPinionAgQlfr_Cnt_T_enum != BMWPINIONAGQLFR_SIGVALVLD) && (BmwPinionAgQlfr_Cnt_T_enum != BMWPINIONAGQLFR_SIGVALINVLDBUTSTTMP))
		{			
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		}
		else
		{
			Os_Call_RstRackCentrMotAg_Oper();
			Os_Call_RstRackCentrMotRev_Oper();
			Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper();
			*ErrorCode = DCM_E_POSITIVERESPONSE;
		}
	}
	else
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
	} 
	
	if (*ErrorCode != DCM_E_POSITIVERESPONSE)
	{		
		return E_NOT_OK;
	}
	
	return RTE_E_OK;

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
    VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32; 
	VAR(BmwPinionAgQlfr1, AUTOMATIC) BmwPinionAgQlfr_Cnt_T_enum;

	
	(void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);
	(void)Rte_Read_BmwPinionAgQlfr_Val(&BmwPinionAgQlfr_Cnt_T_enum);
	
	if( VehSpd_Kph_T_f32 < BMWDIAGCSRVHNDLGCUSTTRIMVEHSPDTHD_KPH_F32)
	{
		Rte_Call_ClrVehCentrPosn_Oper();
		Rte_Call_ClrBmwRackCentrToVehCentrOffs_Oper();
		
		if((BmwPinionAgQlfr_Cnt_T_enum == BMWPINIONAGQLFR_SUBVALSETINUSRSIG) || (BmwPinionAgQlfr_Cnt_T_enum == BMWPINIONAGQLFR_SIGVALVLDANDTMPOFLOQLY))
		{			
			Os_Call_RstRackCentrMotRev_Oper();
		}
		*ErrorCode = DCM_E_POSITIVERESPONSE;
	}
	else
	{
		*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
	}
 
	if (*ErrorCode != DCM_E_POSITIVERESPONSE)
	{		
		return E_NOT_OK;;
	}
	
	return RTE_E_OK;

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
	*ErrorCode = DCM_E_POSITIVERESPONSE;
	return RTE_E_OK;

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
	VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
	VAR(sint16, AUTOMATIC) HwTq_HwNwtMtr_T_s16;
	VAR(uint8, AUTOMATIC) HwTqIdptSig_Cnt_T_u08;;

	(void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
	(void)Rte_Read_HwTqIdptSig_Val(&HwTqIdptSig_Cnt_T_u08);

	HwTq_HwNwtMtr_T_f32 = HwTq_HwNwtMtr_T_f32*100u;
	HwTq_HwNwtMtr_T_s16 = ((sint16)FloatToFixd_s16_f32(HwTq_HwNwtMtr_T_f32, NXTRFIXDPT_FLOATTOP0_ULS_F32));	


	Data[0u] = GetLoHiByte(HwTq_HwNwtMtr_T_s16);
	Data[1u] = GetLoLoByte(HwTq_HwNwtMtr_T_s16);

	/* 0x0 = OK 0x1 = Not OK The PSCM shall report OK, unless (SrlComHwTrqValid) is INVALID*/	
	if(HwTqIdptSig_Cnt_T_u08 != 0x00U)
	{
		Data[2u] = 0x00u;
	}
	else
	{
		Data[2u] = 0x01u;
	}
	return RTE_E_OK;

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

	*Rte_Pim_LockToLockRountineSts() = BMWDIAGCSRVHNDLGROUTINESTSDFT_CNT_U08;
	
	 PimPrevCycleMilesKmEeprom_u32 = PimMilesKmEeprom_u32;
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
	VAR(float32, AUTOMATIC) PinionCentrLrnHwTrvl_HwDeg_T_f32;
	VAR(uint32, AUTOMATIC) BmwOdomDst_Cnt_T_u32;
	VAR(uint8, AUTOMATIC) PinionCentrLrnSt_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) CmsData_Cnt_T_u08[1u]; /* This is dummy variable - just to keep CMS happy */
	
	(void)Rte_Read_BmwOdomDst_Val(&BmwOdomDst_Cnt_T_u32);
	
	(void)Rte_Read_PinionCentrLrnSt_Val(&PinionCentrLrnSt_Cnt_T_u08);
	(void)Rte_Read_PinionCentrLrnHwTrvl_Val(&PinionCentrLrnHwTrvl_HwDeg_T_f32);
	
	if(PimMilesKmEeprom_u32 < BmwOdomDst_Cnt_T_u32)
	{
		/* If received odo value is greater than what is stored in Nvm, then store received value in the Nvm */
		PimMilesKmEeprom_u32 = BmwOdomDst_Cnt_T_u32;
		Rte_Call_MilesKmEeprom_SetRamBlockStatus(TRUE);
	}	

	/* Customer Services hands on detection */
	
	if (*Rte_Pim_LockToLockRountineSts() != BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
	{
		HandsOnDetn (BMWDIAGCSRVHNDLGROUTINESTSDFT_CNT_U08);
		HwAgOrHwVelChk(BMWDIAGCSRVHNDLGROUTINESTSDFT_CNT_U08);		
	}

	/* AB72 */
	if (*Rte_Pim_LockToLockRountineSts() == BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
	{	/* Check conditions to move from ACTIVE/START to STOP state */
		if(PinionCentrLrnSt_Cnt_T_u08 == 0x06U) 	/*LktoLkStrStateType*/
		{
			*Rte_Pim_LockToLockRountineSts()  = BMWDIAGCSRVHNDLGROUTINESTSPASSD_CNT_U08;
			(void)Rte_Write_LockToLockEna_Logl(FALSE);
			/* Defeat Motor Torque Command Ramping Stop*/
			/* TODO: Calling CMS function stright from here. Actual design to be discussed */		
			(void)CmnMfgSrv_SrvF101RoutineStop(CmsData_Cnt_T_u08);
			*Rte_Pim_ActvRid() = BMWDIAGCSRVHNDLGROUTINEINACTV_CNT_U16;
		}
		else if(PinionCentrLrnSt_Cnt_T_u08 == 0x07U) 	/*LktoLkStrStateType*/
		{
			*Rte_Pim_LockToLockRountineSts() = BMWDIAGCSRVHNDLGROUTINESTSOBSTRCN_CNT_U08;
			(void)Rte_Write_LockToLockEna_Logl(FALSE);
			/* Defeat Motor Torque Command Ramping Stop*/
			/* TODO: Calling CMS function stright from here. Actual design to be discussed */		
			(void)CmnMfgSrv_SrvF101RoutineStop(CmsData_Cnt_T_u08);
			*Rte_Pim_ActvRid() = BMWDIAGCSRVHNDLGROUTINEINACTV_CNT_U16;
		}
		else
		{	/* Check Deactivation Conditions */
			HandsOnDetn (BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08);
			HwAgOrHwVelChk(BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08);

			*Rte_Pim_LockToLockRountineSts() = ChkRoutineCdn(FALSE, BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08);

			if (*Rte_Pim_LockToLockRountineSts()  !=  BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
			{
				(void)Rte_Write_LockToLockEna_Logl(FALSE);
			}
		}

		if (BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08 != *Rte_Pim_LockToLockRountineSts())
		{
			/* Defeat Stall Motor Torque Limit Stop */
			/* TODO: Calling CMS function stright from here. Actual design to be discussed */
			(void)CmnMfgSrv_SrvF114RoutineStop(CmsData_Cnt_T_u08);
		}
		
		if(PinionCentrLrnHwTrvl_HwDeg_T_f32 <= ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
		{
			*Rte_Pim_LrndPinionCentrHwTrvl() = PinionCentrLrnHwTrvl_HwDeg_T_f32;
		}
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
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	return E_NOT_OK;

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

  return E_NOT_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BmwDiagcSrvHndlg_STOP_SEC_CODE
#include "BmwDiagcSrvHndlg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




/*************************************************************************************
** FUNC-NAME     : CheckRoutineConditions                          			  		**
** DESCRIPTION   : Updates the routine status based on the start/stop conditions    **
**************************************************************************************/
STATIC FUNC(uint8, BmwDiagcSrvHndlg_CODE) ChkRoutineCdn (boolean ChkHwPosAuthy_Cnt_T_Logl, uint8 PrsntRoutineSts_Cnt_T_u08)
{
	VAR(float32, AUTOMATIC) PinionAgConf_Uls_T_f32;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(uint8, AUTOMATIC)   CmsData_Cnt_T_u08[1u]; /* This is dummy variable - just to keep CMS happy */	
	VAR(uint8, AUTOMATIC)   RoutineSts_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) HwPosCkFailed_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) OperStEnaChkFaild_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) HandsOnDetd_Cnt_T_logl;
	
	(void)Rte_Read_PinionAgConf_Val(&PinionAgConf_Uls_T_f32);
	
	(void)Rte_Read_VehSpd_Val(&VehSpd_Kph_T_f32);

	if (PrsntRoutineSts_Cnt_T_u08 == BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
	{
		HandsOnDetd_Cnt_T_logl = *Rte_Pim_HandsONAbort();

		OperStEnaChkFaild_Cnt_T_lgc = OperStChk();
	}
	else
	{   /* Initialize routine start parameters */
		HandsOnDetd_Cnt_T_logl = *Rte_Pim_HandsONStrt();
		/* Defeat Motor Torque Command Ramping Start*/
		/* TODO: Calling CMS function stright from here. Actual design to be discussed */	
		(void)CmnMfgSrv_SrvF101RoutineStrt(CmsData_Cnt_T_u08);
		
		Rte_Call_GetRefTmr1MicroSec32bit_Oper(Rte_Pim_OperStEnaWaitTi());
		
		*Rte_Pim_OperStPreStrtChk() = TRUE;
	}

	if ((TRUE == ChkHwPosAuthy_Cnt_T_Logl) &&
	    (PinionAgConf_Uls_T_f32 < PINIONAGMAXCONF_ULS_F32) )
	{
		HwPosCkFailed_Cnt_T_lgc = TRUE;
	}

	/* Update Routine Status based on EPS conditions */
	if (OperStEnaChkFaild_Cnt_T_lgc == TRUE)
	{
		RoutineSts_Cnt_T_u08 = BMWDIAGCSRVHNDLGROUTINESTSERR_CNT_U08;
	}
	else if (*Rte_Pim_HwAgOrHwVelChkRes() == TRUE)
	{
		RoutineSts_Cnt_T_u08 = BMWDIAGCSRVHNDLGROUTINESTSHWVELHI_CNT_U08;
	}
	else if (VehSpd_Kph_T_f32 >= BMWDIAGCSRVHNDLGGARAGEMODVEHSPDTHD_KPH_F32)

	{
		RoutineSts_Cnt_T_u08 = BMWDIAGCSRVHNDLGROUTINESTSVEHSPD_CNT_U08;
	}
	else if (HandsOnDetd_Cnt_T_logl == TRUE)
	{
		RoutineSts_Cnt_T_u08 = BMWDIAGCSRVHNDLGROUTINESTSHANDSON_CNT_U08;
	}
	else if (TRUE == HwPosCkFailed_Cnt_T_lgc)
	{
		RoutineSts_Cnt_T_u08 = BMWDIAGCSRVHNDLGROUTINESTSDFT_CNT_U08;
	}
	else
	{
		RoutineSts_Cnt_T_u08 = BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08;
	}

	if (RoutineSts_Cnt_T_u08 != BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
	{
		/* Defeat Motor Torque Command Ramping Stop*/
		/* TODO: Calling CMS function stright from here. Actual design to be discussed */		
		(void)CmnMfgSrv_SrvF101RoutineStop(CmsData_Cnt_T_u08);
		
		*Rte_Pim_ActvRid() = BMWDIAGCSRVHNDLGROUTINEINACTV_CNT_U16;
	}

	return 	RoutineSts_Cnt_T_u08;
}

/*************************************************************************************
** FUNC-NAME     : OperStChk                          			  			**
** DESCRIPTION   : Check for transition to operate state after EngOn defeat			**
**************************************************************************************/
STATIC FUNC(boolean, BmwDiagcSrvHndlg_CODE) OperStChk(void)
{
	VAR(boolean, AUTOMATIC) OperStEnaChkFaild_Cnt_T_logl = FALSE;

	VAR(uint32, AUTOMATIC) OperStEnaWaitTiSpan_MicroSec_T_u32;
	VAR(SysSt1,        AUTOMATIC) SysSt_Cnt_T_enum;
	
	(void) Rte_Read_SysSt_Val(&SysSt_Cnt_T_enum);

	if (*Rte_Pim_OperStPreStrtChk() == FALSE)
	{
		if (SYSST_ENA != SysSt_Cnt_T_enum)
		{   /* STATE TRANSITION FROM OPERATE AFTER STARTING ROUTINE */
			OperStEnaChkFaild_Cnt_T_logl = TRUE;
		}
	}
	else
	{
		if (SYSST_ENA != SysSt_Cnt_T_enum)
		{
		
			Rte_Call_GetTiSpan1MicroSec32bit_Oper(*Rte_Pim_OperStEnaWaitTi(), &OperStEnaWaitTiSpan_MicroSec_T_u32);

			if (OperStEnaWaitTiSpan_MicroSec_T_u32 > BMWDIAGCSRVHNDLGOPERSTWAITTI_MICROSEC_U32)
			{
				OperStEnaChkFaild_Cnt_T_logl = TRUE;
			}
		}
		else
		{
			 switch (*Rte_Pim_ActvRid())
			 {
			 	 case BMWDIAGCSRVHNDLGROUTINEEPSLOCKTOLOCKRID_CNT_U16:  /* EPS FACTORY INITIALIZATION - Lock to Lock steering rouinte */
				 
			 		Os_Call_SetInpPrm_Oper(*Rte_Pim_TarHwVel(), *Rte_Pim_TarHwA());
					
			 		(void)Rte_Write_LockToLockEna_Logl(TRUE);
					
			 		*Rte_Pim_OperStPreStrtChk() = FALSE;
				break;

				default:
				 /* should never get here */
				break;
			 }

		}
	}

	return OperStEnaChkFaild_Cnt_T_logl;
}


/*************************************************************************************
** FUNC-NAME     : HandsOnDetn                          			  			    **
** DESCRIPTION   : Check for torque input from Handwheel  							**
**************************************************************************************/
STATIC FUNC(boolean, BmwDiagcSrvHndlg_CODE) HandsOnDetn (uint8 RoutineSts_Cnt_T_u08)
{
	VAR(float32, AUTOMATIC) HwTq_HwNwtMtr_T_f32;
	VAR(uint32, AUTOMATIC)  HandsONAbortTiSpan_MicroSec_T_u32;
	VAR(uint32, AUTOMATIC)  HandsONStrtTiSpan_MicroSec_T_u32;
	VAR(boolean, AUTOMATIC) HandsOnDetd_Cnt_T_logl;

	(void)Rte_Read_HwTq_Val(&HwTq_HwNwtMtr_T_f32);
	
	if (RoutineSts_Cnt_T_u08 == BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
	{	/* Hands ON Abort Deactivation Conditions */
		HandsOnDetd_Cnt_T_logl = FALSE;

		if ( (Abslt_f32_f32(HwTq_HwNwtMtr_T_f32)) >= BMWDIAGCSRVHNDLGHANDSONHWTQTHD_HWNWTMTR_F32 )
		{
			Rte_Call_GetTiSpan1MicroSec32bit_Oper(*Rte_Pim_HandsONAbortTi(), &HandsONAbortTiSpan_MicroSec_T_u32);

			if (HandsONAbortTiSpan_MicroSec_T_u32 > BMWDIAGCSRVHNDLGHANDSONTI_MICROSEC_U32)
			{
				HandsOnDetd_Cnt_T_logl = TRUE;
			}
		}
		else
		{
			(void) Rte_Call_GetRefTmr1MicroSec32bit_Oper(Rte_Pim_HandsONAbortTi());
		}

		*Rte_Pim_HandsONAbort() = HandsOnDetd_Cnt_T_logl;

	}
	else
	{	/* Hands OFF Start Activation Conditions */
		HandsOnDetd_Cnt_T_logl = TRUE;

		if ( Abslt_f32_f32(HwTq_HwNwtMtr_T_f32) < BMWDIAGCSRVHNDLGHANDSONHWTQTHD_HWNWTMTR_F32 )
		{
			Rte_Call_GetTiSpan1MicroSec32bit_Oper(*Rte_Pim_HandsONStrtTi(), &HandsONStrtTiSpan_MicroSec_T_u32);

			if (HandsONStrtTiSpan_MicroSec_T_u32 > BMWDIAGCSRVHNDLGHANDSONTI_MICROSEC_U32)
			{
				HandsOnDetd_Cnt_T_logl = FALSE;
			}
		}
		else
		{
			(void) Rte_Call_GetRefTmr1MicroSec32bit_Oper(Rte_Pim_HandsONStrtTi());
		}

		*Rte_Pim_HandsONStrt() = HandsOnDetd_Cnt_T_logl;
	}

	return HandsOnDetd_Cnt_T_logl;
}

/*************************************************************************************
** FUNC-NAME     : HwAgOrHwVelChk                          			  			**
** DESCRIPTION   : Check for transition to operate state after EngOn defeat			**
**************************************************************************************/
STATIC FUNC(void, BmwDiagcSrvHndlg_CODE) HwAgOrHwVelChk(uint8 RoutineSts_Cnt_T_u08)
{
	VAR(boolean, AUTOMATIC) ChkRes_Cnt_T_logl = FALSE;
	VAR(uint32, AUTOMATIC) HwVelAbortTiSpan_Cnt_T_u32;
	VAR(float32, AUTOMATIC) HwVel_HwRadPerSec_T_f32;
	
	(void)Rte_Read_HwVel_Val(&HwVel_HwRadPerSec_T_f32);

	if(RoutineSts_Cnt_T_u08 == BMWDIAGCSRVHNDLGROUTINESTSACTV_CNT_U08)
	{
		/* HwVel Check */
		if(Abslt_f32_f32(HwVel_HwRadPerSec_T_f32) >= BMWDIAGCSRVHNDLGHWVELTHD_HWRADPERSEC_F32)
		{

			Rte_Call_GetTiSpan1MicroSec32bit_Oper(*Rte_Pim_HwVelAbortTi(), &HwVelAbortTiSpan_Cnt_T_u32);

			if(HwVelAbortTiSpan_Cnt_T_u32 > BMWDIAGCSRVHNDLGHWVELTI_MICROSEC_U32)
			{
				ChkRes_Cnt_T_logl = TRUE;
			}
		}
		else
		{
			(void) Rte_Call_GetRefTmr1MicroSec32bit_Oper(Rte_Pim_HwVelAbortTi());
		}
	}

	/* Update state variable */
	*Rte_Pim_HwAgOrHwVelChkRes() = ChkRes_Cnt_T_logl;

}

/*************************************************************************************
** FUNC-NAME     : SnsrCdnChk                          			  			**
** DESCRIPTION   : Returns the Pinion Angle Sensor Condition. Used in RIDs 0xAB6C	**
** 				   and 0xDB57														**
**************************************************************************************/
STATIC FUNC(uint8, BmwDiagcSrvHndlg_CODE) SnsrCdnChk(void)
{
	VAR(uint8, AUTOMATIC) SnsrCdn_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) TurnCntrCorrlnSts_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) LongTermRackCentrCmp_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) LongTermVehCentrCmpl_Cnt_T_logl;
	
	(void)Rte_Read_LongTermRackCentrCmpl_Logl(&LongTermRackCentrCmp_Cnt_T_logl);
	(void)Rte_Read_LongTermVehCentrCmpl_Logl(&LongTermVehCentrCmpl_Cnt_T_logl);
	(void)Rte_Read_TurnCntrCorrlnSts_Val(&TurnCntrCorrlnSts_Cnt_T_u08);

	 
	 if(LongTermVehCentrCmpl_Cnt_T_logl == TRUE) 
	{
		if((LongTermRackCentrCmp_Cnt_T_logl == TRUE) &&
		   ((TurnCntrCorrlnSts_Cnt_T_u08 & 0x01U) == 0x01U)) 
		{
			SnsrCdn_Cnt_T_u08 = RACKCENTRFOUND_CNT_U08; 
		}
		else
		{
			SnsrCdn_Cnt_T_u08 = VEHCENTRFOUND_CNT_U08;    
		}
	}
	else
	{

		if(LongTermRackCentrCmp_Cnt_T_logl == TRUE)
		{
			SnsrCdn_Cnt_T_u08 = RACKCENTRFOUND_CNT_U08;	  /* Rack Center Found */
		}
		else
		{
			SnsrCdn_Cnt_T_u08 = CENTRNOTFOUND_CNT_U08;     /* Rack & Vehicle Center Not Found */
		}
	}

	return SnsrCdn_Cnt_T_u08;
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
