/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_MotAg0Meas.c
 *        Config:  C:/Users/nz2999/Documents/Synergy/ccm_wa/ses_dev_ea4/CM620B_MotAg0Meas_Impl-nz2999/CM620B_MotAg0Meas_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_MotAg0Meas
 *  Generated at:  Tue May 15 11:09:43 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_MotAg0Meas>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2016-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg0Meas.c
 * Module Description: Implementation of Motor Angle 0 Measurement component
 * Project           : CBD
 * Author            : Avinash James
 **********************************************************************************************************************
 * Version Control:
 * %version:          12 %
 * %derived_by:       zzr258 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/07/16  1        AJM       Initial Version                                                               EA4#5027
 * 06/07/16  2        AJM       Corrected Compilation errors                                                  EA4#5027
 * 09/01/17  3        BLS       Removed application data types                                                EA4#12427
 * 09/07/17  4        KByrski   Updated as per Design 2.0.0                                                   EA4#13291
 * 11/22/17  5        AJM       Corrected SPI register configuration for anomaly fix EA4#17707                EA4#17725
 * 01/05/18  6        AJM       Updated the sensor interface NTC fault mask constant to get rid of            EA4#18923
                                CommFlts & TurnsCntr Step Size
 * 01/19/18  7        AJM       Updated the parity fault checks to mask the upper 16 bits                     EA4#19623
 * 04/25/17  8        KByrski   Updated as per Design 5.0.0                                                   EA4#15121,EA4#18232,EA4#22026
 * 04/27/18  9        AJM       Added port access for IoHw calls to init runnable for motor control           EA4#22026
                                function access
 * 05/03/18  10       AJM       Add delay to initialize sensor offset learn and moved it to motor control     EA4#23192
 * 05/15/17  11       KByrski   Updated as per Design 6.1.0                                                   EA4#23813
 * 06/28/18  12       FCD       Change MOTAG0TURNCNTRVLTGFLTPASSSTEP_CNT_U16 set to  2620 (it was 655)        EA4#25381
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
 * EgyModSt1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MotAgSnsrCfgSt1
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
 * sm5p12
 *   sint8 represents integers with a minimum value of -128 and a maximum value of 127.
 *      The order-relation on sint8 is: x < y if y - x is positive.
 *      sint8 has a lexical representation consisting of an optional sign followed 
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is 
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, 12678, +10000.
 *
 * u0p16
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Per-Instance Memory:
 * ====================
 * dMotAg0MeasMotAg0Delta
 *   Display variable holding difference between angle from QEP interface and angle from SPI bus
 *
 * dMotAg0MeasMotAg0RawAgReg
 *   Display variable for Motor Angle 0 Raw Angle Register
 *
 * dMotAg0MeasMotAg0RawErrReg
 *   Display variable for Motor Angle 0 Raw Error Register
 *
 * dMotAg0MeasMotAg0RawStsReg
 *   Display variable for Motor Angle 0 Raw status Register
 *
 * dMotAg0MeasMotAg0RawTurnCntrReg
 *   Display variable Motor Angle 0 Raw Turn Counter Register
 *
 * dMotAg0MeasMotAg0RawWarnReg
 *   Display variable for Motor Angle 0 Raw warning Register
 *
 * dMotAg0MeasMotAg0RtOffs
 *   Display variable of Motor Angle 0 Runtime Offset
 *
 *********************************************************************************************************************/

#include "Rte_CDD_MotAg0Meas.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "csih_regs.h"
#include "ArchGlbPrm.h"
#include "NxtrMath.h"
#include "NxtrFixdPt.h"
#include "CDD_MotAg0Meas.h"
#include "CDD_MotAg0Meas_private.h"
#include "CDD_MotAg0Meas_Cfg.h"


/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 1.1     [NXTRDEV 1.1.2]: Inline functions are used for functions called from Motor Control ISR to allow for throughput optimization  */
/* MISRA-C:2004 Rule 11.3   [NXTRDEV 11.3.2]: Cast of a variable address to an integer type is required for writing a variable address to a register. */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value for:
                                              Rte_Read_*, Rte_Write_*, GetNtcQlfrSts, SetNtcSts, GetErrorStatus and SetRamBlockStatus */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.2]: Server runnable is a void function; No error information is returned for: Rte_IrvWrite_* */
/* MISRA-C:2004 Rule 19.1   [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


/********************************************* Embedded Local Constants **********************************************/
#define MOTAG0TURNCNTRLOLIM_CNT_F32             (-256.09375F)
#define MOTAG0TURNCNTRHILIM_CNT_F32             (255.96875F)

/******************************************** Local Function Prototypes **********************************************/
static FUNC(void, CDD_MotAg0Meas_CODE) ProcessErrorRegAndDieRevCtr(
        VAR(uint32, AUTOMATIC) MotAgErrReg_Cnt_T_u32,
        VAR(uint32, AUTOMATIC) MotAgTurnCntrReg_Cnt_T_u32,
        VAR(uint32, AUTOMATIC) MotAgWarnReg_Cnt_T_u32,
        P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAg0Err_Cnt_T_u16,
        P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAg0Warn_Cnt_T_u16,
        P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCntrParFltCnt_Cnt_T_u16,
        P2VAR(sint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCntr_Cnt_T_s16,
        P2VAR(uint8,  AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgTurnCntrRollgCntr_Cnt_T_u08);

static FUNC(uint8, CDD_MotAg0Meas_CODE) SPIvsENCA(
        VAR(u0p16, AUTOMATIC) MotAgSpiMecl_MotRev_T_u0p16,
        VAR(u0p16, AUTOMATIC) MotAgEncaMecl_MotRev_T_u0p16);

static FUNC(void, CDD_MotAg0Meas_CODE) MotAgFaultProcessing(
        VAR(uint16, AUTOMATIC) MotAgErr_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgWarn_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) TurnCntrParFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgVltgFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgParFltCnt_Cnt_T_u16,
        VAR(uint8,  AUTOMATIC) MotAgSyncErr_Cnt_T_u08,
        VAR(u0p16,  AUTOMATIC) MotAgQepMecl_MotRev_T_u0p16,
        VAR(u0p16,  AUTOMATIC) MotAgSPIMecl_MotRev_T_u0p16,
        VAR(sint16, AUTOMATIC) TurnCntr_Cnt_T_s16,
        P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgQlfr_Cnt_T_enum,
        P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgTurnCntrQlfr_Cnt_T_enum,
        P2VAR(boolean,  AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgQepFaild_Cnt_T_logl);

static FUNC(void, CDD_MotAg0Meas_CODE) CalcNtcPrm(
        VAR(uint16, AUTOMATIC) MotAgErr_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgWarn_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) TurnCntrParFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgVltgFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgParFltCnt_Cnt_T_u16,
        P2VAR(uint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgNtcParm_Cnt_T_u08,
        P2VAR(uint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCtrNtcParm_Cnt_T_u08,
        P2VAR(uint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCtrVltgNtcParm_Cnt_T_u08);

static FUNC(void, CDD_MotAg1Meas_CODE) SetMotAg0FltNtc(
        VAR(uint8, AUTOMATIC) MotAgNtcParm_Cnt_T_u08,
        VAR(uint8, AUTOMATIC) TurnCntrNtcParm_Cnt_T_u08,
        VAR(uint8, AUTOMATIC) TurnCntrVltgNtcParm_Cnt_T_u08,
        VAR(uint16, AUTOMATIC) MotAgQepMecl_MotRev_T_u0p16,
        VAR(uint16, AUTOMATIC) MotAgSPIMecl_MotRev_T_u0p16,
        VAR(sint16, AUTOMATIC) TurnCntr_Cnt_T_s16);

static FUNC(float32, CDD_MotAg0Meas_CODE) CalculateMotAgTurnCntr(
        VAR(u0p16,  AUTOMATIC) MotAgSpiMecl_MotRev_T_u0p16,
        VAR(sint16, AUTOMATIC) TurnCntr_Cnt_T_s16,
        VAR(sint8,  AUTOMATIC) MotAgPolarity_Cnt_T_s08);

LOCAL_INLINE FUNC(void, CDD_MotAg0Meas_CODE) CalcCorrnTbl(void);


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
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * sm5p12: Integer in interval [-128...127]
 * u0p16: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * EgyModSt1: Enumeration of integer in interval [0...255] with enumerators
 *   EGYMODST_NORM (0U)
 *   EGYMODST_PRDN (1U)
 *   EGYMODST_TRANSPT (2U)
 *   EGYMODST_FLS (3U)
 * MotAgSnsrCfgSt1: Enumeration of integer in interval [0...255] with enumerators
 *   MOTAGSNSRCFGST_RSTERR (0U)
 *   MOTAGSNSRCFGST_RSTTURNCNTR (1U)
 *   MOTAGSNSRCFGST_CMDTRANSPT (2U)
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
 * Array Types:
 * ============
 * Ary1D_f32_26: Array with 26 element(s) of type float32
 * Ary1D_sm5p12_128: Array with 128 element(s) of type sm5p12
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_MotAg0QepFaildCntr(void)
 *   uint32 *Rte_Pim_MotAg0SnsrCfg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawAgReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawErrReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawStsReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg(void)
 *   uint32 *Rte_Pim_dMotAg0MeasMotAg0RawWarnReg(void)
 *   sint32 *Rte_Pim_MotAg0InitOffs(void)
 *   sint32 *Rte_Pim_dMotAg0MeasMotAg0RtOffs(void)
 *   uint16 *Rte_Pim_MotAg0ParFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg0ParFltCntPrev(void)
 *   u0p16 *Rte_Pim_MotAg0PrevSpiMecl(void)
 *   u0p16 *Rte_Pim_MotAg0RawMeclPrev(void)
 *   uint16 *Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg0TurnCntrParFltCntPrev(void)
 *   uint16 *Rte_Pim_MotAg0VltgFltCntNtcPrev(void)
 *   uint16 *Rte_Pim_MotAg0VltgFltCntPrev(void)
 *   u0p16 *Rte_Pim_dMotAg0MeasMotAg0Delta(void)
 *   sint16 *Rte_Pim_MotAg0PrevTCUpd(void)
 *   sint16 *Rte_Pim_MotAg0TurnCntrPrev(void)
 *   uint8 *Rte_Pim_MotAg0InitOffsCntr(void)
 *   uint8 *Rte_Pim_MotAg0MeclRollgCntrPrev(void)
 *   uint8 *Rte_Pim_MotAg0TurnCntrRollgCntrPrev(void)
 *   uint8 *Rte_Pim_MotAgCtrlRegCfg(void)
 *   MotAgSnsrCfgSt1 *Rte_Pim_MotAgSnsrCfgSt(void)
 *   sint8 *Rte_Pim_MotAgMecl0Polarity(void)
 *   boolean *Rte_Pim_MotAg0QepFaildPrev(void)
 *   boolean *Rte_Pim_dMotAg0MeasPwrRstStsLtch(void)
 *   float32 *Rte_Pim_MotAg0CoeffTbl(void)
 *     Returnvalue: float32* is of type Ary1D_f32_26
 *   sm5p12 *Rte_Pim_MotAg0CorrnTbl(void)
 *     Returnvalue: sm5p12* is of type Ary1D_sm5p12_128
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   float32 *Rte_CData_MotAg0CoeffTblDft(void)
 *     Returnvalue: float32* is of type Ary1D_f32_26
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint16 Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val(void)
 *
 *********************************************************************************************************************/


#define CDD_MotAg0Meas_START_SEC_CODE
#include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0CoeffTblRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg0CoeffTblRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg0CoeffTblRead_Oper(float32 *MotAgCoeffTbl_Arg)
 *     Argument MotAgCoeffTbl_Arg: float32* is of type Ary1D_f32_26
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0CoeffTblRead_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblRead_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgCoeffTbl_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0CoeffTblRead_Oper
 *********************************************************************************************************************/

    VAR(uint8, AUTOMATIC) TblIdx_Cnt_T_u08;

    for(TblIdx_Cnt_T_u08 = 0U; TblIdx_Cnt_T_u08 < TblSize_m(PimMotAg0CoeffTbl); TblIdx_Cnt_T_u08++)
    {
        MotAgCoeffTbl_Arg[TblIdx_Cnt_T_u08] = PimMotAg0CoeffTbl[TblIdx_Cnt_T_u08];
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0CoeffTblWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg0CoeffTblWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg0CoeffTblWr_Oper(const float32 *MotAgCoeffTbl_Arg)
 *     Argument MotAgCoeffTbl_Arg: float32* is of type Ary1D_f32_26
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0CoeffTblWr_Oper_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblWr_Oper(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_DATA) MotAgCoeffTbl_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0CoeffTblWr_Oper
 *********************************************************************************************************************/

    VAR(uint8, AUTOMATIC) TblIdx_Cnt_T_u08;

    for(TblIdx_Cnt_T_u08 = 0U; TblIdx_Cnt_T_u08 < TblSize_m(PimMotAg0CoeffTbl); TblIdx_Cnt_T_u08++)
    {
        PimMotAg0CoeffTbl[TblIdx_Cnt_T_u08] = MotAgCoeffTbl_Arg[TblIdx_Cnt_T_u08];
    }

    (void) Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(TRUE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0MeasInit1
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
 *   Std_ReturnType Rte_Read_MotAg0Polarity_Val(sint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAg0SnsrCfgAdr_Val(uint32 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg0CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0MeasInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0MeasInit1
 *********************************************************************************************************************/

    /* Outputs */
    VAR(uint32, AUTOMATIC) MotAg0SnsrCfgAdr_Cnt_T_u32;

    VAR(NvM_RequestResultType,  AUTOMATIC) MotAg0CoeffTblErrSts_Cnt_T_enum;


    /************************************************************************************************************/
    /*** ------------------------------- START: CSIH1 register configuration -------------------------------- ***/
    /************************************************************************************************************/

    /* Configure CSIH1CTL0 register */
    CSIH1CTL0   =  0x00U
                   | (uint8)((uint8)0x00U << 0U)    /* MBS */
                   | (uint8)((uint8)0x00U << 1U)    /* JOBE */
                   | (uint8)((uint8)0x01U << 5U)    /* RXE */
                   | (uint8)((uint8)0x01U << 6U)    /* TXE */
                   | (uint8)((uint8)0x00U << 7U);   /* PWR */

    /* Configure CSIH1STCR0 register */
    CSIH1STCR0  =  0x0000U
                   | (uint16)((uint16)0x01U << 0U)   /* OVEC */
                   | (uint16)((uint16)0x01U << 1U)   /* PEC */
                   | (uint16)((uint16)0x01U << 3U)   /* DCEC */
                   | (uint16)((uint16)0x01U << 8U)   /* PCT */
                   | (uint16)((uint16)0x01U << 14U)  /* OFEC */
                   | (uint16)((uint16)0x01U << 15U); /* TMOEC */

    /* Configure CSIH1CTL1 register */
    CSIH1CTL1   =  0x00000000U
                   | (uint32)((uint32)0x00U << 0U)   /* SSE */
                   | (uint32)((uint32)0x00U << 1U)   /* HSE */
                   | (uint32)((uint32)0x00U << 2U)   /* SIT */
                   | (uint32)((uint32)0x00U << 3U)   /* LBM */
                   | (uint32)((uint32)0x01U << 4U)   /* CSRI */
                   | (uint32)((uint32)0x00U << 5U)   /* DCS */
                   | (uint32)((uint32)0x00U << 6U)   /* JE */
                   | (uint32)((uint32)0x00U << 7U)   /* EDLE */
                   | (uint32)((uint32)0x00U << 8U)   /* CSL0 */
                   | (uint32)((uint32)0x00U << 9U)   /* CSL1 */
                   | (uint32)((uint32)0x00U << 10U)  /* CSL2 */
                   | (uint32)((uint32)0x00U << 11U)  /* CSL3 */
                   | (uint32)((uint32)0x00U << 12U)  /* CSL4 */
                   | (uint32)((uint32)0x00U << 13U)  /* CSL5 */
                   | (uint32)((uint32)0x00U << 14U)  /* CSL6 */
                   | (uint32)((uint32)0x00U << 15U)  /* CSL7 */
                   | (uint32)((uint32)0x00U << 16U)  /* SLIT */
                   | (uint32)((uint32)0x00U << 17U)  /* CKR */
                   | (uint32)((uint32)0x00U << 18U); /* PHE */

    /* Configure CSIH1CTL2 register */
    CSIH1CTL2   =  0x0000U
                   | (uint16)((uint16)0x03U << 13U); /* PRS[2:0] */

    /* Configure CSIH1MCTL0 register */
    CSIH1MCTL0  =  0x0000U
                   | (uint16)((uint16)0x00U << 0U)   /* TO[4:0] */
                   | (uint16)((uint16)0x01U << 8U);  /* MMS[1:0] */

    /* Configure CSIH1MCTL1 register */
    CSIH1MCTL1  =  0x00000000U
                   | (uint32)((uint32)0x00U << 0U)   /* FFS[6:0] */
                   | (uint32)((uint32)0x00U << 16U); /* FES[6:0] */

    /* Configure CSIH1CFG0 register */
    CSIH1CFG0   =  0x00000000U
                   | (uint32)((uint32)0x00U << 0U)   /* SP0[3:0] */
                   | (uint32)((uint32)0x00U << 4U)   /* IN0[3:0] */
                   | (uint32)((uint32)0x00U << 8U)   /* HD0[3:0] */
                   | (uint32)((uint32)0x02U << 12U)  /* ID0[2:0] */
                   | (uint32)((uint32)0x01U << 15U)  /* IDL0 */
                   | (uint32)((uint32)0x00U << 16U)  /* DAP0 */
                   | (uint32)((uint32)0x00U << 17U)  /* CKP0 */
                   | (uint32)((uint32)0x00U << 18U)  /* DIR0 */
                   | (uint32)((uint32)0x00U << 19U)  /* RCB0 */
                   | (uint32)((uint32)0x00U << 24U)  /* DLS0[3:0] */
                   | (uint32)((uint32)0x00U << 28U)  /* PS0[1:0] */
                   | (uint32)((uint32)0x00U << 30U); /* BRSS0[1:0] */

    /* Configure CSIH1CFG1 register in bit field level */
    CSIH1RCB1    =  1U;    /* Recessive configuration = recessive */
                        /* Other bits are not written to at init - parameters derived from CFG0 */

    /* Configure CSIH1BRS0 register in bit field level */
    CSIH1BRS    =  1U;    /* k = 1. (alpha = 3, Clock = 80 MHz/(2^alpha*k*2) = 5MHz) */

    /* Configure CSIH1MRWP0 register */
    CSIH1MRWP0   =  0x00000000U
                   | (uint32)((uint32)0x00U << 0U)   /* TRWA[6:0] */
                   | (uint32)((uint32)0x00U << 16U); /* RRA[6:0] */

    /* Write the TxBuffer */
    CSIH1TX0W    =  (uint32)16526336U;  /* TxBuffer00 : ReadTURN */
    CSIH1TX0W    =  (uint32)16523264U;  /* TxBuffer01 : ReadANG */
    CSIH1TX0W    =  (uint32)16524288U;  /* TxBuffer02 : ReadERR */
    CSIH1TX0W    =  (uint32)16524800U;  /* TxBuffer03 : ReadWARN */
    CSIH1TX0W    =  (uint32)16523776U;  /* TxBuffer04 : ReadSTA */
    CSIH1TX0W    =  (uint32)16711680U;  /* TxBuffer05 : Nop */
    CSIH1TX0W    =  (uint32)16670211U;  /* TxBuffer06 : ResetERRAndWARN */
    CSIH1TX0W    =  (uint32)16523776U;  /* TxBuffer07 : ReadSTA */
    CSIH1TX0W    =  (uint32)16711680U;  /* TxBuffer08 : Nop */
    CSIH1TX0W    =  (uint32)16670272U;  /* TxBuffer09 : ResetTURNS_a */
    CSIH1TX0W    =  (uint32)16670534U;  /* TxBuffer10 : ResetTURNS_b */
    CSIH1TX0W    =  (uint32)16523776U;  /* TxBuffer11 : ReadSTA */
    CSIH1TX0W    =  (uint32)16711680U;  /* TxBuffer12 : Nop */
    CSIH1TX0W    =  (uint32)16670304U;  /* TxBuffer13 : EnterLPM */
    CSIH1TX0W    =  (uint32)16523776U;  /* TxBuffer14 : ReadSTA */

    /* Configure CSIH1CTL0 register in bit field level */
    CSIH1PWR     =  1U;    /* Controls the operation clock. 0: Stops operation clock. 1: Provides operation clock. */

    /************************************************************************************************************/
    /*** -------------------------------- END: CSIH1 register configuration --------------------------------- ***/
    /************************************************************************************************************/

    (void) Rte_Call_MotAg0CoeffTbl_GetErrorStatus( &MotAg0CoeffTblErrSts_Cnt_T_enum );

    if( MotAg0CoeffTblErrSts_Cnt_T_enum == NVM_REQ_OK )
    {    /* NVM is OK. */

        CalcCorrnTbl();
    }
    else
    {    /* NVM is not OK. */

        /* No action is required. Default value of "MotAg0CorrnTbl" will be used (i.e all zeros). */
    }

    /* Output Address of MotAg0SnsrCfg */
    MotAg0SnsrCfgAdr_Cnt_T_u32 = (uint32) Rte_Pim_MotAg0SnsrCfg();

    /* Read the MotAg0 Polarity to a Pim to be used later*/
    (void) Rte_Read_MotAg0Polarity_Val(Rte_Pim_MotAgMecl0Polarity());

    /* Write outputs */
    (void) Rte_Write_MotAg0SnsrCfgAdr_Val(MotAg0SnsrCfgAdr_Cnt_T_u32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0MeasPer2
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
 *   Std_ReturnType Rte_Read_MotAg0ErrReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg0ParFltCnt_Val(uint16 *data)
 *   Std_ReturnType Rte_Read_MotAg0Polarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_MotAg0SpiMecl_Val(u0p16 *data)
 *   Std_ReturnType Rte_Read_MotAg0TurnCntrReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg0VltgFltCnt_Val(uint16 *data)
 *   Std_ReturnType Rte_Read_MotAg0WarnReg_Val(uint32 *data)
 *   Std_ReturnType Rte_Read_MotAg3Mecl_Val(u0p16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAg0MeclQlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_MotAg0QepFaild_Logl(boolean data)
 *   Std_ReturnType Rte_Write_MotAg0TurnCntr_Val(float32 data)
 *   Std_ReturnType Rte_Write_MotAg0TurnCntrQlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_MotAg0TurnCntrRollgCntr_Val(uint8 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(SigQlfr1 data)
 *   void Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(SigQlfr1 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CnvSnpshtData_s16_Oper(uint32 *SnpshtDataCnvd_Arg, sint16 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CnvSnpshtData_u16_Oper(uint32 *SnpshtDataCnvd_Arg, uint16 SnpshtData_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcStsAndSnpshtData_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg, uint32 SpclSnpshtData0_Arg, uint32 SpclSnpshtData1_Arg, uint32 SpclSnpshtData2_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcStsAndSnpshtData_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0MeasPer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0MeasPer2
 *********************************************************************************************************************/

    /* Inputs */
    VAR(uint32,   AUTOMATIC) MotAg0ErrReg_Cnt_T_u32;
    VAR(uint16,   AUTOMATIC) MotAg0ParFltCnt_Cnt_T_u16;
    VAR(sint8,    AUTOMATIC) MotAg0Polarity_Cnt_T_s08;
    VAR(u0p16,    AUTOMATIC) MotAg0SpiMecl_MotRev_T_u0p16;
    VAR(uint32,   AUTOMATIC) MotAg0TurnCntrReg_Cnt_T_u32;
    VAR(uint16,   AUTOMATIC) MotAg0VltgFltCnt_Cnt_T_u16;
    VAR(uint32,   AUTOMATIC) MotAg0WarnReg_Cnt_T_u32;
    VAR(u0p16,    AUTOMATIC) MotAg3Mecl_MotRev_T_u0p16;

    /* Outputs */
    VAR(SigQlfr1, AUTOMATIC) MotAg0MeclQlfr_Cnt_T_enum;
    VAR(boolean,  AUTOMATIC) MotAg0QepFaild_Cnt_T_logl;
    VAR(float32,  AUTOMATIC) MotAg0TurnCntr_MotRev_T_f32;
    VAR(SigQlfr1, AUTOMATIC) MotAg0TurnCntrQlfr_Cnt_T_enum;
    VAR(uint8,    AUTOMATIC) MotAg0TurnCntrRollgCntr_Cnt_T_u08;

    /* Internals */
    VAR(uint16,   AUTOMATIC) MotAg0Err_Cnt_T_u16;
    VAR(uint16,   AUTOMATIC) MotAg0Warn_Cnt_T_u16;
    VAR(uint16,   AUTOMATIC) TurnCntrParFltCnt_Cnt_T_u16;
    VAR(sint16,   AUTOMATIC) TurnCntr_Cnt_T_s16;
    VAR(uint8,    AUTOMATIC) MotAgSyncErr_Cnt_T_u08;

    /* Read inputs */
    (void) Rte_Read_MotAg0ErrReg_Val(&MotAg0ErrReg_Cnt_T_u32);
    (void) Rte_Read_MotAg0ParFltCnt_Val(&MotAg0ParFltCnt_Cnt_T_u16);
    (void) Rte_Read_MotAg0Polarity_Val(&MotAg0Polarity_Cnt_T_s08);
    (void) Rte_Read_MotAg0SpiMecl_Val(&MotAg0SpiMecl_MotRev_T_u0p16);
    (void) Rte_Read_MotAg0TurnCntrReg_Val(&MotAg0TurnCntrReg_Cnt_T_u32);
    (void) Rte_Read_MotAg0VltgFltCnt_Val(&MotAg0VltgFltCnt_Cnt_T_u16);
    (void) Rte_Read_MotAg0WarnReg_Val(&MotAg0WarnReg_Cnt_T_u32);
    (void) Rte_Read_MotAg3Mecl_Val(&MotAg3Mecl_MotRev_T_u0p16);

    /* Process ErrorReg and DieRevCtr */
    ProcessErrorRegAndDieRevCtr(
            MotAg0ErrReg_Cnt_T_u32,
            MotAg0TurnCntrReg_Cnt_T_u32,
            MotAg0WarnReg_Cnt_T_u32,
            &MotAg0Err_Cnt_T_u16,
            &MotAg0Warn_Cnt_T_u16,
            &TurnCntrParFltCnt_Cnt_T_u16,
            &TurnCntr_Cnt_T_s16,
            &MotAg0TurnCntrRollgCntr_Cnt_T_u08);

    /* SPI vs ENCA */
    MotAgSyncErr_Cnt_T_u08 = SPIvsENCA(
            MotAg0SpiMecl_MotRev_T_u0p16,
            MotAg3Mecl_MotRev_T_u0p16);

    /* MotAg Fault Processing */
    MotAgFaultProcessing(
            MotAg0Err_Cnt_T_u16,
            MotAg0Warn_Cnt_T_u16,
            TurnCntrParFltCnt_Cnt_T_u16,
            MotAg0VltgFltCnt_Cnt_T_u16,
            MotAg0ParFltCnt_Cnt_T_u16,
            MotAgSyncErr_Cnt_T_u08,
            MotAg3Mecl_MotRev_T_u0p16,
            MotAg0SpiMecl_MotRev_T_u0p16,
            TurnCntr_Cnt_T_s16,
            &MotAg0MeclQlfr_Cnt_T_enum,
            &MotAg0TurnCntrQlfr_Cnt_T_enum,
            &MotAg0QepFaild_Cnt_T_logl);


    /* Calculate MotAgTurnCntr */
    MotAg0TurnCntr_MotRev_T_f32 = CalculateMotAgTurnCntr(
            MotAg0SpiMecl_MotRev_T_u0p16,
            TurnCntr_Cnt_T_s16,
            MotAg0Polarity_Cnt_T_s08);

    /* Write to Inter-Runnable Variables */
    (void) Rte_IrvWrite_MotAg0MeasPer2_MotAg0Qlfr(MotAg0MeclQlfr_Cnt_T_enum);
    (void) Rte_IrvWrite_MotAg0MeasPer2_TurnCntr0Qlfr(MotAg0TurnCntrQlfr_Cnt_T_enum);

    /* Write outputs */
    (void) Rte_Write_MotAg0MeclQlfr_Val(MotAg0MeclQlfr_Cnt_T_enum);
    (void) Rte_Write_MotAg0QepFaild_Logl(MotAg0QepFaild_Cnt_T_logl);
    (void) Rte_Write_MotAg0TurnCntr_Val(MotAg0TurnCntr_MotRev_T_f32);
    (void) Rte_Write_MotAg0TurnCntrQlfr_Val(MotAg0TurnCntrQlfr_Cnt_T_enum);
    (void) Rte_Write_MotAg0TurnCntrRollgCntr_Val(MotAg0TurnCntrRollgCntr_Cnt_T_u08);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg0MeasPer3
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
 *   Std_ReturnType Rte_Read_EgyModSt_Val(EgyModSt1 *data)
 *   Std_ReturnType Rte_Read_MotAg1MeclQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_MotAg1TurnCntrQlfr_Val(SigQlfr1 *data)
 *   Std_ReturnType Rte_Read_TurnCntrIdptSig_Val(uint8 *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   SigQlfr1 Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr(void)
 *   SigQlfr1 Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_MotAg0SnsrCfgDmaStrt_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_MotAg0SnsrCfgDmaStrt_PortIf2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0MeasPer3_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg0MeasPer3
 *********************************************************************************************************************/

    /* Inputs */
    VAR(EgyModSt1, AUTOMATIC) EgyModSt_Cnt_T_enum;
    VAR(SigQlfr1,  AUTOMATIC) MotAg1MeclQlfr_Cnt_T_enum;
    VAR(SigQlfr1,  AUTOMATIC) MotAg1TurnCntrQlfr_Cnt_T_enum;
    VAR(uint8,     AUTOMATIC) TurnCntrIdptSig_Cnt_T_u08;
    VAR(SigQlfr1,  AUTOMATIC) MotAg0Qlfr_Cnt_T_enum;
    VAR(SigQlfr1,  AUTOMATIC) TurnCntr0Qlfr_Cnt_T_enum;

    /* Internals */
    VAR(uint8,     AUTOMATIC) MotAgCtrlRegCfg_Cnt_T_u08 = 0U;
    VAR(boolean,   AUTOMATIC) TransferEnable_Cnt_T_logl;

    /* Read inputs */
    (void) Rte_Read_EgyModSt_Val(&EgyModSt_Cnt_T_enum);
    (void) Rte_Read_MotAg1MeclQlfr_Val(&MotAg1MeclQlfr_Cnt_T_enum);
    (void) Rte_Read_MotAg1TurnCntrQlfr_Val(&MotAg1TurnCntrQlfr_Cnt_T_enum);
    (void) Rte_Read_TurnCntrIdptSig_Val(&TurnCntrIdptSig_Cnt_T_u08);

    MotAg0Qlfr_Cnt_T_enum = Rte_IrvRead_MotAg0MeasPer3_MotAg0Qlfr();
    TurnCntr0Qlfr_Cnt_T_enum = Rte_IrvRead_MotAg0MeasPer3_TurnCntr0Qlfr();

    /* DetermineCommand */
    if ((MotAg0Qlfr_Cnt_T_enum == SIGQLFR_FAILD) || (MotAg1MeclQlfr_Cnt_T_enum == SIGQLFR_FAILD))
    {
        /* Output_TURNCNTRCFGRSTERROFFS */
        MotAgCtrlRegCfg_Cnt_T_u08 = TURNCNTRCFGRSTERROFFS_CNT_U08;
    }
    if ((TurnCntr0Qlfr_Cnt_T_enum == SIGQLFR_FAILD) ||
        (MotAg1TurnCntrQlfr_Cnt_T_enum == SIGQLFR_FAILD) ||
        (TurnCntrIdptSig_Cnt_T_u08 != TURNCNTRDESCNT_CNT_U08))
    {
        /* Output_TURNCNTRCFGRSTTURNCNTROFFS */
        MotAgCtrlRegCfg_Cnt_T_u08 |= (TURNCNTRCFGRSTTURNCNTROFFS_CNT_U08 | TURNCNTRCFGRSTERROFFS_CNT_U08);
    }
    if (EgyModSt_Cnt_T_enum == EGYMODST_TRANSPT)
    {
        /* Output_TURNCNTRCFGCMDTRANSPTOFFS */
        MotAgCtrlRegCfg_Cnt_T_u08 |= TURNCNTRCFGCMDTRANSPTOFFS_CNT_U08;
    }

    *Rte_Pim_MotAgCtrlRegCfg() = MotAgCtrlRegCfg_Cnt_T_u08;

    if(MotAgCtrlRegCfg_Cnt_T_u08 == 0U)
    {
        /* Idle */
        *Rte_Pim_MotAg0SnsrCfg() = TRFREGBASE_CNT_U32;
        *Rte_Pim_MotAgSnsrCfgSt() = MOTAGSNSRCFGST_RSTERR;
    }
    else
    {
        /* SendCmd */
        switch (*Rte_Pim_MotAgSnsrCfgSt())
        {
            case MOTAGSNSRCFGST_RSTTURNCNTR:
            {
                /* Reset TC */
                if ((*Rte_Pim_MotAgCtrlRegCfg() & TURNCNTRCFGRSTTURNCNTROFFS_CNT_U08) != 0U)
                {
                    /* ResetTC */
                    *Rte_Pim_MotAg0SnsrCfg() = MCTL2RSTTURNCNTR_CNT_U32;
                    TransferEnable_Cnt_T_logl = TRUE;
                }
                else
                {
                    /* idle */
                    *Rte_Pim_MotAg0SnsrCfg() = TRFREGBASE_CNT_U32;
                    TransferEnable_Cnt_T_logl = FALSE;
                }
                *Rte_Pim_MotAgSnsrCfgSt() = MOTAGSNSRCFGST_CMDTRANSPT;
            }
            break;

            case MOTAGSNSRCFGST_CMDTRANSPT:
            {
                /* Command Transport */
                if ((*Rte_Pim_MotAgCtrlRegCfg() & TURNCNTRCFGCMDTRANSPTOFFS_CNT_U08) != 0U)
                {
                    /* TransportMode */
                    *Rte_Pim_MotAg0SnsrCfg() = MCTL2CMDTRANSPT_CNT_U32;
                    TransferEnable_Cnt_T_logl = TRUE;
                }
                else
                {
                    /* idle */
                    *Rte_Pim_MotAg0SnsrCfg() = TRFREGBASE_CNT_U32;
                    TransferEnable_Cnt_T_logl = FALSE;
                }
                *Rte_Pim_MotAgSnsrCfgSt() = MOTAGSNSRCFGST_RSTERR;
            }
            break;

            default:
            {
                /* ResetErr/Default */
                if ((*Rte_Pim_MotAgCtrlRegCfg() & TURNCNTRCFGRSTERROFFS_CNT_U08) != 0U)
                {
                    /* ResetError */
                    *Rte_Pim_MotAg0SnsrCfg() = MCTL2RSTERR_CNT_U32;
                    TransferEnable_Cnt_T_logl = TRUE;
                }
                else
                {
                    *Rte_Pim_MotAg0SnsrCfg() = TRFREGBASE_CNT_U32;
                    TransferEnable_Cnt_T_logl = FALSE;
                }
                *Rte_Pim_MotAgSnsrCfgSt() = MOTAGSNSRCFGST_RSTTURNCNTR;
            }
            break;
        }

        if (TransferEnable_Cnt_T_logl != FALSE)
        {
            /* EnableTransfer */
            (void) Rte_Call_MotAg0SnsrCfgDmaStrt_Oper();
        }
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_MotAg0Meas_STOP_SEC_CODE
#include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define CDD_MotAg0Meas_START_SEC_CODE
#include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Name:        ProcessErrorRegAndDieRevCtr
 * Description: Implementation of "Process ErrorReg and DieRevCtr" Simulink block
 * Inputs:      MotAgErrReg_Cnt_T_u32
 *              MotAgTurnCntrReg_Cnt_T_u32
 *              MotAgWarnReg_Cnt_T_u32
 * Outputs:     MotAg0Err_Cnt_T_u16
 *              MotAg0Warn_Cnt_T_u16
 *              TurnCntrParFltCnt_Cnt_T_u16
 *              TurnCntr_Cnt_T_s16
 *              MotAgTurnCntrRollgCntr_Cnt_T_u08
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, CDD_MotAg0Meas_CODE) ProcessErrorRegAndDieRevCtr(
        VAR(uint32, AUTOMATIC) MotAgErrReg_Cnt_T_u32,
        VAR(uint32, AUTOMATIC) MotAgTurnCntrReg_Cnt_T_u32,
        VAR(uint32, AUTOMATIC) MotAgWarnReg_Cnt_T_u32,
        P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAg0Err_Cnt_T_u16,
        P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAg0Warn_Cnt_T_u16,
        P2VAR(uint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCntrParFltCnt_Cnt_T_u16,
        P2VAR(sint16, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCntr_Cnt_T_s16,
        P2VAR(uint8,  AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgTurnCntrRollgCntr_Cnt_T_u08)
{
    VAR(uint32,   AUTOMATIC) OddParity_Cnt_T_u32;
    VAR(boolean,  AUTOMATIC) MotAgTurnCntrParFlt_Cnt_T_logl;
    VAR(uint16,   AUTOMATIC) MotAgTurnCntr_Cnt_T_u16;
    VAR(sint16,   AUTOMATIC) MotAgTurnCntr_Cnt_T_s16;

    /* Process MotAgRawErr */
    *MotAg0Err_Cnt_T_u16 = (uint16) (MotAgErrReg_Cnt_T_u32 & SNSRERRMASK_CNT_U32);
    *MotAg0Warn_Cnt_T_u16 = (uint16) (MotAgWarnReg_Cnt_T_u32 & SNSRERRMASK_CNT_U32);

    /* Process TurnsCntrReg */
    /* OddParCalcn */
    OddParity_Cnt_T_u32 = MotAgTurnCntrReg_Cnt_T_u32;
    OddParity_Cnt_T_u32 ^= (OddParity_Cnt_T_u32 >> 1U);
    OddParity_Cnt_T_u32 ^= (OddParity_Cnt_T_u32 >> 2U);
    OddParity_Cnt_T_u32 &= ODDPARCALCNMASK_CNT_U32;
    OddParity_Cnt_T_u32 *= ODDPARCALCNMASK_CNT_U32;
    OddParity_Cnt_T_u32 = (OddParity_Cnt_T_u32 >> 12U);
    OddParity_Cnt_T_u32 &= 0x01U;

    MotAgTurnCntrParFlt_Cnt_T_logl = (OddParity_Cnt_T_u32 == 0U) ? TRUE : FALSE;

    if (MotAgTurnCntrParFlt_Cnt_T_logl != FALSE)
    {
        /* FltCnt_u16 */
        (*Rte_Pim_MotAg0TurnCntrParFltCntPrev())++;
    }
    else
    {
        MotAgTurnCntr_Cnt_T_u16 = (uint16) (MotAgTurnCntrReg_Cnt_T_u32 & SNSRTURNCNTRMASK_CNT_U32);
        MotAgTurnCntr_Cnt_T_u16 ^= (uint16) SNSRTURNCNTRSIGNMASK_CNT_S16;
        MotAgTurnCntr_Cnt_T_s16 = ((sint16) MotAgTurnCntr_Cnt_T_u16) - SNSRTURNCNTRSIGNMASK_CNT_S16;

        /* Valid Parity & data */
        *Rte_Pim_MotAg0TurnCntrPrev() = MotAgTurnCntr_Cnt_T_s16;

        /* TurnCntrlFlt_RollgCnt_u08 */
        (*Rte_Pim_MotAg0TurnCntrRollgCntrPrev())++;
    }

    *TurnCntr_Cnt_T_s16 = *Rte_Pim_MotAg0TurnCntrPrev();
    *TurnCntrParFltCnt_Cnt_T_u16 = *Rte_Pim_MotAg0TurnCntrParFltCntPrev();
    *MotAgTurnCntrRollgCntr_Cnt_T_u08 = *Rte_Pim_MotAg0TurnCntrRollgCntrPrev();
}

/**********************************************************************************************************************
 * Name:        SPIvsENCA
 * Description: Implementation of "SPI vs ENCA" Simulink block
 * Inputs:      MotAgSpiMecl_MotRev_T_u0p16
 *              MotAgEncaMecl_MotRev_T_u0p16
 * Outputs:     MotAgSyncErr_Cnt_T_u08
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(uint8, CDD_MotAg0Meas_CODE) SPIvsENCA(
        VAR(u0p16, AUTOMATIC) MotAgSpiMecl_MotRev_T_u0p16,
        VAR(u0p16, AUTOMATIC) MotAgEncaMecl_MotRev_T_u0p16)
{
    VAR(sint32, AUTOMATIC) MotAgDelta_MotRev_T_s32;
    VAR(uint8,  AUTOMATIC) MotAgSyncErr_Cnt_T_u08;

    MotAgDelta_MotRev_T_s32 = (sint32) Abslt_u32_s32((sint32) MotAgSpiMecl_MotRev_T_u0p16 - (sint32) MotAgEncaMecl_MotRev_T_u0p16);
    if (MotAgDelta_MotRev_T_s32 > MOTAGOFFS_CNT_S32)
    {
        MotAgDelta_MotRev_T_s32 = (sint32) Abslt_u32_s32(MotAgDelta_MotRev_T_s32 - MOTAGLIMMASK_CNT_S32);
    }
    *Rte_Pim_dMotAg0MeasMotAg0Delta() = (u0p16) MotAgDelta_MotRev_T_s32;

    if (((u0p16) MotAgDelta_MotRev_T_s32) > MOTAG0ERRTHD_MOTREV_U0P16)
    {
        /* Sync Error */
        MotAgSyncErr_Cnt_T_u08 = 1U;
    }
    else
    {
        /* No Error */
        MotAgSyncErr_Cnt_T_u08 = 0U;
    }

    return MotAgSyncErr_Cnt_T_u08;
}

/**********************************************************************************************************************
 * Name:        MotAgFaultProcessing
 * Description: Implementation of "MotAg Fault Processing" Simulink block
 * Inputs:      MotAgErr_Cnt_T_u16
 *              MotAgWarn_Cnt_T_u16
 *              TurnCntrParFltCnt_Cnt_T_u16
 *              MotAgVltgFltCnt_Cnt_T_u16
 *              MotAgParFltCnt_Cnt_T_u16
 *              MotAgSyncErr_Cnt_T_u08
 *              MotAgQepMecl_MotRev_T_u0p16
 *              MotAgSPIMecl_MotRev_T_u0p16
 *              TurnCntr_Cnt_T_s16
 * Outputs:     MotAgQlfr_Cnt_T_enum
 *              MotAgTurnCntrQlfr_Cnt_T_enum
 *              MotAgQepFaild_Cnt_T_logl
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, CDD_MotAg0Meas_CODE) MotAgFaultProcessing(
        VAR(uint16, AUTOMATIC) MotAgErr_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgWarn_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) TurnCntrParFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgVltgFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgParFltCnt_Cnt_T_u16,
        VAR(uint8,  AUTOMATIC) MotAgSyncErr_Cnt_T_u08,
        VAR(u0p16,  AUTOMATIC) MotAgQepMecl_MotRev_T_u0p16,
        VAR(u0p16,  AUTOMATIC) MotAgSPIMecl_MotRev_T_u0p16,
        VAR(sint16, AUTOMATIC) TurnCntr_Cnt_T_s16,
        P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgQlfr_Cnt_T_enum,
        P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgTurnCntrQlfr_Cnt_T_enum,
        P2VAR(boolean,  AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgQepFaild_Cnt_T_logl)
{
    VAR(uint8, AUTOMATIC) MotAgNtcParm_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) TurnCntrNtcParm_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) TurnCntrVltgNtcParm_Cnt_T_u08;
    VAR(SigQlfr1, AUTOMATIC) MotAg0TurnCntrQlfr_Cnt_T_enum;
    VAR(SigQlfr1, AUTOMATIC) MotAg0TurnCntrVltgQlfr_Cnt_T_enum;

    /* Determine NTC Parameters */
    CalcNtcPrm(
            MotAgErr_Cnt_T_u16,
            MotAgWarn_Cnt_T_u16,
            TurnCntrParFltCnt_Cnt_T_u16,
            MotAgVltgFltCnt_Cnt_T_u16,
            MotAgParFltCnt_Cnt_T_u16,
            &MotAgNtcParm_Cnt_T_u08,
            &TurnCntrNtcParm_Cnt_T_u08,
            &TurnCntrVltgNtcParm_Cnt_T_u08);

    /* PwrRstError */
    if ((MotAgErr_Cnt_T_u16 & SNSRERRPWRRSTMASK_CNT_U16) != 0U)
    {
        TurnCntrVltgNtcParm_Cnt_T_u08 |= 1U;

        /* PowerReset Latch */
        *Rte_Pim_dMotAg0MeasPwrRstStsLtch() = TRUE;
    }

    SetMotAg0FltNtc(
            MotAgNtcParm_Cnt_T_u08,
            TurnCntrNtcParm_Cnt_T_u08,
            TurnCntrVltgNtcParm_Cnt_T_u08,
            MotAgQepMecl_MotRev_T_u0p16,
            MotAgSPIMecl_MotRev_T_u0p16,
            TurnCntr_Cnt_T_s16);

    (void) Rte_Call_GetNtcQlfrSts_Oper(MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM, MotAgQlfr_Cnt_T_enum);
    (void) Rte_Call_GetNtcQlfrSts_Oper(NTCNR_0X08C, &MotAg0TurnCntrQlfr_Cnt_T_enum);
    (void) Rte_Call_GetNtcQlfrSts_Oper(NTCNR_0X0BD, &MotAg0TurnCntrVltgQlfr_Cnt_T_enum);

    *MotAgTurnCntrQlfr_Cnt_T_enum = (SigQlfr1) Max_u08((uint8) MotAg0TurnCntrQlfr_Cnt_T_enum, (uint8) MotAg0TurnCntrVltgQlfr_Cnt_T_enum);

    *MotAgQepFaild_Cnt_T_logl = ((MotAgSyncErr_Cnt_T_u08 != 0U) && ((MotAgErr_Cnt_T_u16 & SNSRERRQEPFAILDMASK_CNT_U16) != 0U)) ? TRUE : FALSE;

    /* QepFaildCnt */
    if ((*MotAgQepFaild_Cnt_T_logl != FALSE) && (*Rte_Pim_MotAg0QepFaildPrev() == FALSE))
    {
        /* IncCntr */
        (*Rte_Pim_MotAg0QepFaildCntr())++;
    }
    *Rte_Pim_MotAg0QepFaildPrev() = *MotAgQepFaild_Cnt_T_logl;
}

/**********************************************************************************************************************
 * Name:        CalcNtcPrm
 * Description: Implementation of "Determine NTC Parameters" Simulink block
 * Inputs:      MotAgErr_Cnt_T_u16
 *              MotAgWarn_Cnt_T_u16
 *              TurnCntrParFltCnt_Cnt_T_u16
 *              MotAgVltgFltCnt_Cnt_T_u16
 *              MotAgParFltCnt_Cnt_T_u16
 * Outputs:     MotAgNtcParm_Cnt_T_u08
 *              TurnCtrNtcParm_Cnt_T_u08
 *              TurnCtrVltgNtcParm_Cnt_T_u08
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, CDD_MotAg0Meas_CODE) CalcNtcPrm(
        VAR(uint16, AUTOMATIC) MotAgErr_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgWarn_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) TurnCntrParFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgVltgFltCnt_Cnt_T_u16,
        VAR(uint16, AUTOMATIC) MotAgParFltCnt_Cnt_T_u16,
        P2VAR(uint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgNtcParm_Cnt_T_u08,
        P2VAR(uint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCtrNtcParm_Cnt_T_u08,
        P2VAR(uint8, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) TurnCtrVltgNtcParm_Cnt_T_u08)
{
    /* ZeroDetnError */
    *MotAgNtcParm_Cnt_T_u08 = (MotAgErr_Cnt_T_u16 & SNSRERRNTCMASK_CNT_U16) != 0U ? 1U : 0U;

    /* TurnCtrOvf */
    *TurnCtrNtcParm_Cnt_T_u08 = (MotAgWarn_Cnt_T_u16 & SNSRERRTURNCTROVFNTCMASK_CNT_U16) != 0U ? 1U : 0U;

    /* PlkError */
    if ((MotAgErr_Cnt_T_u16 & SNSRERRMASK_CNT_U16) != 0U)
    {
        *MotAgNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 1U);
    }

    /* LowMagnError */
    /* HighMagnError */
    if (((MotAgErr_Cnt_T_u16 & SNSRMAGERRNTCMASK_CNT_U16) != 0U) || ((MotAgWarn_Cnt_T_u16 & SNSRMAGERRNTCMASK_CNT_U16) != 0))
    {
        *MotAgNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 2U);
    }

    /* TurnCtrWarn */
    if((MotAgWarn_Cnt_T_u16 & SNSRERRTURNCTRWARNNTCMASK_CNT_U16) != 0U)
    {
        *TurnCtrNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 3U);
    }

    /* TempError */
    if ((MotAgWarn_Cnt_T_u16 & SNSRERRNTCMASK_CNT_U16) != 0U)
    {
        *MotAgNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 3U);
    }

    /* IfErr */
    if((MotAgWarn_Cnt_T_u16 & Rte_Prm_MotAg0MeasSnsrIfErrNtcMask_Val()) != 0U)
    {
        *MotAgNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 4U);
        *TurnCtrNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 7U);
    }

    /* AngleVltgFlt */
    if (MotAgVltgFltCnt_Cnt_T_u16 != *Rte_Pim_MotAg0VltgFltCntNtcPrev())
    {
        *MotAgNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 5U);
        *TurnCtrNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 7U);
        *Rte_Pim_MotAg0VltgFltCntNtcPrev() = MotAgVltgFltCnt_Cnt_T_u16;
    }

    /* AngleParFlt */
    if (MotAgParFltCnt_Cnt_T_u16 != *Rte_Pim_MotAg0ParFltCntNtcPrev())
    {
        *MotAgNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 6U);
        *TurnCtrNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 7U);
        *Rte_Pim_MotAg0ParFltCntNtcPrev() = MotAgParFltCnt_Cnt_T_u16;
    }

    /* TurnCntrParityFlt */
    if (TurnCntrParFltCnt_Cnt_T_u16 != *Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev())
    {
        *TurnCtrNtcParm_Cnt_T_u08 |= (uint8) (0x01U << 6U);
        *Rte_Pim_MotAg0TurnCntrParFltCntNtcPrev() = TurnCntrParFltCnt_Cnt_T_u16;
    }

    /* TurnCtrVltgError */
    *TurnCtrVltgNtcParm_Cnt_T_u08 = (MotAgErr_Cnt_T_u16 & SNSRERRTURNCTRVLTGMASK_CNT_U16) != 0U ? 2U : 0U;
}

/**********************************************************************************************************************
 * Name:        SetMotAg0FltNtc
 * Description: Sets the NTCs corresponding to the MotAg1 faults.
 * Inputs:      MotAgNtcParm_Cnt_T_u08
 *              TurnCntrNtcParm_Cnt_T_u08
 *              TurnCntrVltgNtcParm_Cnt_T_u08
 *              MotAgQepMecl_MotRev_T_u0p16
 *              MotAgSPIMecl_MotRev_T_u0p16
 *              TurnCntr_Cnt_T_s16
 * Outputs:     NONE
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, CDD_MotAg1Meas_CODE) SetMotAg0FltNtc(
        VAR(uint8, AUTOMATIC) MotAgNtcParm_Cnt_T_u08,
        VAR(uint8, AUTOMATIC) TurnCntrNtcParm_Cnt_T_u08,
        VAR(uint8, AUTOMATIC) TurnCntrVltgNtcParm_Cnt_T_u08,
        VAR(uint16, AUTOMATIC) MotAgQepMecl_MotRev_T_u0p16,
        VAR(uint16, AUTOMATIC) MotAgSPIMecl_MotRev_T_u0p16,
        VAR(sint16, AUTOMATIC) TurnCntr_Cnt_T_s16)
{

    VAR(uint32, AUTOMATIC) SpclSnpshtData0_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) SpclSnpshtData1_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) SpclSnpshtData2_Cnt_T_u32;

    (void) Rte_Call_CnvSnpshtData_u16_Oper(&SpclSnpshtData0_Cnt_T_u32, MotAgQepMecl_MotRev_T_u0p16);
    (void) Rte_Call_CnvSnpshtData_u16_Oper(&SpclSnpshtData1_Cnt_T_u32, MotAgSPIMecl_MotRev_T_u0p16);
    (void) Rte_Call_CnvSnpshtData_s16_Oper(&SpclSnpshtData2_Cnt_T_u32, TurnCntr_Cnt_T_s16);

    /* MotAg0PtrclFlt Processing */
    if (MotAgNtcParm_Cnt_T_u08 != 0U)
    {
        (void) Rte_Call_SetNtcStsAndSnpshtData_Oper(
                MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM,
                MotAgNtcParm_Cnt_T_u08,
                NTCSTS_PREFAILD,
                MOTAG0PRTCLFLTFAILSTEP_CNT_U16,
                SpclSnpshtData0_Cnt_T_u32,
                SpclSnpshtData1_Cnt_T_u32,
                SpclSnpshtData2_Cnt_T_u32);
    }
    else
    {
        (void) Rte_Call_SetNtcStsAndSnpshtData_Oper(
                MOTAG0MEAS_MOTAG0PRTCLFLTNTCNR_CNT_ENUM,
                MotAgNtcParm_Cnt_T_u08,
                NTCSTS_PREPASSD,
                MOTAG0PRTCLFLTPASSSTEP_CNT_U16,
                0U,
                0U,
                0U);
    }

    /* MotAg0TurnCntrFlt Processing */
    if (TurnCntrNtcParm_Cnt_T_u08 != 0U)
    {
        (void) Rte_Call_SetNtcStsAndSnpshtData_Oper(
                NTCNR_0X08C,
                TurnCntrNtcParm_Cnt_T_u08,
                NTCSTS_PREFAILD,
                MOTAG0TURNCNTRPRTCLFLTFAILSTEP_CNT_U16,
                SpclSnpshtData0_Cnt_T_u32,
                SpclSnpshtData1_Cnt_T_u32,
                SpclSnpshtData2_Cnt_T_u32);
    }
    else
    {
        (void) Rte_Call_SetNtcStsAndSnpshtData_Oper(
                NTCNR_0X08C,
                TurnCntrNtcParm_Cnt_T_u08,
                NTCSTS_PREPASSD,
                MOTAG0TURNCNTRPRTCLFLTPASSSTEP_CNT_U16,
                0U,
                0U,
                0U);
    }

    /* MotAg0TurnCntrVltgFlt Processing */
    if (TurnCntrVltgNtcParm_Cnt_T_u08 != 0U)
    {
        (void) Rte_Call_SetNtcStsAndSnpshtData_Oper(
                NTCNR_0X0BD,
                TurnCntrVltgNtcParm_Cnt_T_u08,
                NTCSTS_PREFAILD,
                MOTAG0TURNCNTRVLTGFLTFAILSTEP_CNT_U16,
                SpclSnpshtData0_Cnt_T_u32,
                SpclSnpshtData1_Cnt_T_u32,
                SpclSnpshtData2_Cnt_T_u32);
    }
    else
    {
        (void) Rte_Call_SetNtcStsAndSnpshtData_Oper(
                NTCNR_0X0BD,
                TurnCntrVltgNtcParm_Cnt_T_u08,
                NTCSTS_PREPASSD,
                MOTAG0TURNCNTRVLTGFLTPASSSTEP_CNT_U16,
                0U,
                0U,
                0U);
    }
}

/**********************************************************************************************************************
 * Name:        CalculateMotAgTurnCntr
 * Description: Implementation of "Calculate MotAgTurnCntr" Simulink block
 * Inputs:      MotAgSpiMecl_MotRev_T_u0p16
 *              TurnCntr_Cnt_T_s16
 *              MotAgPolarity_Cnt_T_s08
 * Outputs:     MotAgTurnCntr_MotRev_T_f32
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(float32, CDD_MotAg0Meas_CODE) CalculateMotAgTurnCntr(
        VAR(u0p16,  AUTOMATIC) MotAgSpiMecl_MotRev_T_u0p16,
        VAR(sint16, AUTOMATIC) TurnCntr_Cnt_T_s16,
        VAR(sint8,  AUTOMATIC) MotAgPolarity_Cnt_T_s08)
{
    VAR(u0p16, AUTOMATIC) MotAgTurnCntr_MotRev_T_u0p16;
    VAR(sint32, AUTOMATIC) MotAgTurnCntr_MotRev_T_s32;
    VAR(float32, AUTOMATIC) MotAgTurnCntr_MotRev_T_f32;

    /* UpdateSpiMecl */
    if (TurnCntr_Cnt_T_s16 != *Rte_Pim_MotAg0PrevTCUpd())
    {
        /* UpdatePrevSpiMecl */
        *Rte_Pim_MotAg0PrevSpiMecl() = MotAgSpiMecl_MotRev_T_u0p16;
    }
    *Rte_Pim_MotAg0PrevTCUpd() = TurnCntr_Cnt_T_s16;

    MotAgTurnCntr_MotRev_T_u0p16 = MotAgSpiMecl_MotRev_T_u0p16 - *Rte_Pim_MotAg0PrevSpiMecl();
    MotAgTurnCntr_MotRev_T_s32 = (sint16) MotAgTurnCntr_MotRev_T_u0p16;
    MotAgTurnCntr_MotRev_T_s32 += ((sint32) MOTAG0MECLQUARTERPIMASK_MOTREV_U0P16 * (sint32) TurnCntr_Cnt_T_s16) * MotAgPolarity_Cnt_T_s08;
    MotAgTurnCntr_MotRev_T_f32 = Lim_f32(((float32) MotAgTurnCntr_MotRev_T_s32 * MOTAG0TURNCNTRFLOATCNVN_CNT_F32), MOTAG0TURNCNTRLOLIM_CNT_F32, MOTAG0TURNCNTRHILIM_CNT_F32);

    return MotAgTurnCntr_MotRev_T_f32;
}

/**********************************************************************************************************************
 * Name:        CalcCorrnTbl
 * Description: Calculate the motor angle 0 correction table from the coefficient table.
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: Called by MotAg0MeasInit1
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_MotAg0Meas_CODE) CalcCorrnTbl( void )
{
    VAR(uint8,      AUTOMATIC) TblIdx_Cnt_T_u08;
    VAR(uint8,      AUTOMATIC) CoeffTblIdx_Cnt_T_u08;
    VAR(float32,    AUTOMATIC) SinVal_Uls_T_f32;
    VAR(float32,    AUTOMATIC) CosVal_Uls_T_f32;
    VAR(float32,    AUTOMATIC) HarmAg_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) RecnstrdWaveForm_MotRev_T_f32[CORRNTBLSIZE_CNT_U16];
    VAR(uint8,      AUTOMATIC) LoopIdx_Cnt_T_u08;
    VAR(float32,    AUTOMATIC) IdxSca_MotRev_T_f32;
    VAR(boolean,    AUTOMATIC) LoopIdxFound_Cnt_T_logl;
    VAR(float32,    AUTOMATIC) Y1_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) Y2_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) CorrnTermFound_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) CorrnTermNotFound_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) RecnstrdWaveFormX_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) RecnstrdWaveFormX1_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) TempX_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) TempY_MotRev_T_f32;
    VAR(float32,    AUTOMATIC) TempA_MotRev_T_f32;

    /************************************************************************************************************/
    /*** --------------------- START:  Build Wave / Reconstructed Waveform Processing ----------------------- ***/
    /************************************************************************************************************/
    for (TblIdx_Cnt_T_u08 = 0U; TblIdx_Cnt_T_u08 < CORRNTBLSIZE_CNT_U16; TblIdx_Cnt_T_u08++)
    {
        HarmAg_MotRev_T_f32 = (float32) TblIdx_Cnt_T_u08 * CORRNTBLAGSTEPSIZE_MATRAD_F32;

        /* Formula: for i = 0 to 127, n = 1 to 12 */
        /* RecnstrdWaveForm[i] = SUM{ CoeffTbl[2*n] * cos(AgStep*i*n) + CoeffTbl[2*n + 1] * Sin(AgStep*i*n) } */

        /* First term is calculated outside of the for loop to avoid the initialization of all terms to zero. */
        SinCos_f32(HarmAg_MotRev_T_f32, &SinVal_Uls_T_f32, &CosVal_Uls_T_f32);
        RecnstrdWaveForm_MotRev_T_f32[TblIdx_Cnt_T_u08] = (PimMotAg0CoeffTbl[COEFFTBLELMSIZE_CNT_U08] * CosVal_Uls_T_f32)
                                                          + (PimMotAg0CoeffTbl[COEFFTBLELMSIZE_CNT_U08 + 1U] * SinVal_Uls_T_f32);

        for (CoeffTblIdx_Cnt_T_u08 = 2U; CoeffTblIdx_Cnt_T_u08 < COEFFTBLSIZE_CNT_U08; CoeffTblIdx_Cnt_T_u08++)
        {

            SinCos_f32(HarmAg_MotRev_T_f32 * (float32) CoeffTblIdx_Cnt_T_u08, &SinVal_Uls_T_f32, &CosVal_Uls_T_f32);
            RecnstrdWaveForm_MotRev_T_f32[TblIdx_Cnt_T_u08] = RecnstrdWaveForm_MotRev_T_f32[TblIdx_Cnt_T_u08]
                                                              + (PimMotAg0CoeffTbl[CoeffTblIdx_Cnt_T_u08 * COEFFTBLELMSIZE_CNT_U08] * CosVal_Uls_T_f32)
                                                              + (PimMotAg0CoeffTbl[(CoeffTblIdx_Cnt_T_u08 * COEFFTBLELMSIZE_CNT_U08) + 1U] * SinVal_Uls_T_f32);
        }
    }
    /************************************************************************************************************/
    /*** ----------------------  END:  Build Wave / Reconstructed Waveform Processing ----------------------- ***/
    /************************************************************************************************************/


    /************************************************************************************************************/
    /*** ---------------  START:  Change Correction Coordinate / Waveform Coordinate Change ----------------- ***/
    /************************************************************************************************************/
    for (TblIdx_Cnt_T_u08 = 0U; TblIdx_Cnt_T_u08 < CORRNTBLSIZE_CNT_U16; TblIdx_Cnt_T_u08++)
    {
        LoopIdx_Cnt_T_u08 = (TblIdx_Cnt_T_u08 < CORRNTBLSIDXOFFS_CNT_U16) ? (0U) : (TblIdx_Cnt_T_u08 - (uint8) CORRNTBLSIDXOFFS_CNT_U16);

        HarmAg_MotRev_T_f32 = (float32) TblIdx_Cnt_T_u08 * CORRNTBLAGSTEPSIZE_MATRAD_F32;

        /* Calculate Index Scale */
        if ((RecnstrdWaveForm_MotRev_T_f32[0U] >= 0.0F) && (RecnstrdWaveForm_MotRev_T_f32[0U] > HarmAg_MotRev_T_f32))
        {
            IdxSca_MotRev_T_f32 = HarmAg_MotRev_T_f32 + ARCHGLBPRM_2PI_ULS_F32;
        }
        else if ((RecnstrdWaveForm_MotRev_T_f32[0U] + ARCHGLBPRM_2PI_ULS_F32) <= HarmAg_MotRev_T_f32)
        {
            IdxSca_MotRev_T_f32 = HarmAg_MotRev_T_f32 - ARCHGLBPRM_2PI_ULS_F32;
        }
        else
        {
            IdxSca_MotRev_T_f32 = HarmAg_MotRev_T_f32;
        }

        /* Determine Non Wrapped Correction Term */
        LoopIdxFound_Cnt_T_logl = FALSE;
        do
        {
            /* Masking is redundant, but used to match the design */
            RecnstrdWaveFormX_MotRev_T_f32  = RecnstrdWaveForm_MotRev_T_f32[LoopIdx_Cnt_T_u08 & CORRNTBLSIZEMASK_CNT_U08];
            RecnstrdWaveFormX1_MotRev_T_f32 = RecnstrdWaveForm_MotRev_T_f32[(LoopIdx_Cnt_T_u08 + 1U) & CORRNTBLSIZEMASK_CNT_U08];

            Y1_MotRev_T_f32 = ((float32) LoopIdx_Cnt_T_u08 * CORRNTBLAGSTEPSIZE_MATRAD_F32) + RecnstrdWaveFormX_MotRev_T_f32;
            Y2_MotRev_T_f32 = ((float32) LoopIdx_Cnt_T_u08 * CORRNTBLAGSTEPSIZE_MATRAD_F32) + CORRNTBLAGSTEPSIZE_MATRAD_F32 + RecnstrdWaveFormX1_MotRev_T_f32;

            if ((Y1_MotRev_T_f32 <= IdxSca_MotRev_T_f32) && (Y2_MotRev_T_f32 >= IdxSca_MotRev_T_f32))
            {
                LoopIdxFound_Cnt_T_logl = TRUE;

                /* Calculate Correction Term */
                /* FDD simulation verified no possibility of overflow here (file version 3) */
                if (Abslt_f32_f32(Y2_MotRev_T_f32 - Y1_MotRev_T_f32) > ARCHGLBPRM_FLOATZEROTHD_ULS_F32)
                {
                    /* Denominator != 0 */
                    CorrnTermFound_MotRev_T_f32 = (((IdxSca_MotRev_T_f32 - Y1_MotRev_T_f32) / (Y2_MotRev_T_f32 - Y1_MotRev_T_f32))
                                                  * (RecnstrdWaveFormX1_MotRev_T_f32 - RecnstrdWaveFormX_MotRev_T_f32))
                                                  + RecnstrdWaveFormX_MotRev_T_f32;
                }
                else
                {
                    /* Denominator == 0 */
                    CorrnTermFound_MotRev_T_f32 = 0.0F;
                }
            }

            LoopIdx_Cnt_T_u08++;
        } while (((LoopIdx_Cnt_T_u08 + 1U) < (uint8) CORRNTBLSIZE_CNT_U16) && (LoopIdxFound_Cnt_T_logl == FALSE));


        if( LoopIdxFound_Cnt_T_logl == TRUE )
        {
            /* Correction Term Found */
            /* FDD simulation verified no possibility of overflow here (file version 3) */
            PimMotAg0CorrnTbl[TblIdx_Cnt_T_u08] = (sint8) FloatToFixd_s16_f32(CorrnTermFound_MotRev_T_f32, NXTRFIXDPT_FLOATTOP12_ULS_F32); /* Convert to sm5p12 format */
        }
        else
        {
            /* Correction Term Not Found */
            TempX_MotRev_T_f32 = RecnstrdWaveForm_MotRev_T_f32[0U];
            TempY_MotRev_T_f32 = RecnstrdWaveForm_MotRev_T_f32[CORRNTBLSIZE_CNT_U16 - 1U];
            TempA_MotRev_T_f32 = TempY_MotRev_T_f32 + ( CORRNTBLAGSTEPSIZE_MATRAD_F32 * (float32) (CORRNTBLSIZE_CNT_U16 - 1U));
            /* FDD simulation verified no possibility of overflow here (file version 3) */
            if( Abslt_f32_f32(ARCHGLBPRM_2PI_ULS_F32 + (TempX_MotRev_T_f32 - TempA_MotRev_T_f32)) > ARCHGLBPRM_FLOATZEROTHD_ULS_F32 )
            {
                /* Denominator != 0 */
                CorrnTermNotFound_MotRev_T_f32 = (((TempX_MotRev_T_f32 - TempY_MotRev_T_f32) * (IdxSca_MotRev_T_f32 - TempA_MotRev_T_f32)) /
                                                   ((ARCHGLBPRM_2PI_ULS_F32 + (TempX_MotRev_T_f32 - TempA_MotRev_T_f32))))
                                                  + TempY_MotRev_T_f32;
            }
            else
            {
                /* Denominator == 0 */
                CorrnTermNotFound_MotRev_T_f32 = 0.0F;
            }
            /* FDD simulation verified no possibility of overflow here (file version 3) */
            PimMotAg0CorrnTbl[TblIdx_Cnt_T_u08] = (sint8)FloatToFixd_s16_f32( CorrnTermNotFound_MotRev_T_f32, NXTRFIXDPT_FLOATTOP12_ULS_F32 ); /* Convert to sm5p12 format */
        }
    }
    /************************************************************************************************************/
    /*** ----------------   END:  Change Correction Coordinate / Waveform Coordinate Change ----------------- ***/
    /************************************************************************************************************/
}

#define CDD_MotAg0Meas_STOP_SEC_CODE
#include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
