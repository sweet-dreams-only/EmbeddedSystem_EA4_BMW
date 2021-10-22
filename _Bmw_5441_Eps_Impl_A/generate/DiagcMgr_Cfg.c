
/**********************************************************************************************************************
* Copyright 2015, 2016, 2017 Nxtr 
* Nxtr Confidential
*
* Module File Name  : DiagcMgr_Cfg.c
* Module Description: DiagcMgr
* Project           : CBD
* Author            : Spandana Balani
* Generator         : artt 2.0.2.0
* Generation Time   : 30.07.2018 19:59:42
***********************************************************************************************************************
* Version Control:
* %version:          30 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                         SCR #
* -------   -------  --------  ---------------------------------------------------------------------------   ----------
* 02/26/16  1        SB         ES101A_DiagcMgr_Design version 2 implementation                              EA4#3421
* 04/19/16  2        SB         ES101A_DiagcMgr_Design version 3 implementation                              EA4#5110
* 05/23/16  3        SB         Updated to fix anomaly EA4#5865  NTC BF not setting                          EA4#5905
* 06/20/16  4        SB         ES101A_DiagcMgr_Design version 4 implementation                              EA4#6251
* 08/30/16  5        SB         Updated logic for DEMDTCEVEIDMAP                                             EA4#6368
* 09/23/16  6        SB         Added error codes                                                            EA4#7191
* 04/10/17  7        SR         Added NtcPPtyAry definition. Also added CONST definitions for the config
*                               params DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM and DIAGCMGRNTCLTCHCNTRTHD_CNT_U08    EA4#10779
*                               Added Enviroment.Exit codes 13/14/15 for invalid config at generation.
* 08/04/17  8        SR         Fix for Anomaly EA4#12478                                                    EA4#13175
**********************************************************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#define DIAGCMGR_C 
#include "DiagcMgr_Cfg.h"
#include "Dem.h"

/*******************************************************************************
**                      Module Private Data                                   **
*******************************************************************************/
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */ 

#define DiagcMgr_START_SEC_CODE
#include "DiagcMgr_MemMap.h"

    /* 
     * Description: NTC to Application Index and Info Index aint with DebCntrIdx Map 
     * Usage:       Index into the table with the desired NTC (1 to 512)
     *              An application value 0xFFU indicates no mapping exists for the NTC
     */
    CONST(NtcMapRec1, DiagcMgr_CODE) DIAGCMGRNTCMAP_CNT_REC[D_MAXNUMBEROFNTCS_CNT_U16]= {
    /*  ApplIdx , NtcInfoIdx, DebCntrIdx  */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X000 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X001 */
        { 0x0AU,     0x00U,        0x00U }, /* NTCNR_0X002 */
        { 0x0AU,     0x01U,        0x00U }, /* NTCNR_0X003 */
        { 0x0AU,     0x02U,        0x00U }, /* NTCNR_0X004 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X005 */
        { 0x0AU,     0x03U,        0x00U }, /* NTCNR_0X006 */
        { 0x0AU,     0x04U,        0x00U }, /* NTCNR_0X007 */
        { 0x0AU,     0x05U,        0x00U }, /* NTCNR_0X008 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X009 */
        { 0x0AU,     0x06U,        0x00U }, /* NTCNR_0X00A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X00B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X00C */
        { 0x0AU,     0x07U,        0x00U }, /* NTCNR_0X00D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X00E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X00F */
        { 0x0AU,     0x08U,        0x00U }, /* NTCNR_0X010 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X011 */
        { 0x0AU,     0x09U,        0x00U }, /* NTCNR_0X012 */
        { 0x0AU,     0x0AU,        0x00U }, /* NTCNR_0X013 */
        { 0x0AU,     0x0BU,        0x00U }, /* NTCNR_0X014 */
        { 0x0AU,     0x0CU,        0x00U }, /* NTCNR_0X015 */
        { 0x0AU,     0x0DU,        0x00U }, /* NTCNR_0X016 */
        { 0x0AU,     0x0EU,        0x00U }, /* NTCNR_0X017 */
        { 0x0AU,     0x0FU,        0x01U }, /* NTCNR_0X018 */
        { 0x0AU,     0x10U,        0x00U }, /* NTCNR_0X019 */
        { 0x0AU,     0x11U,        0x00U }, /* NTCNR_0X01A */
        { 0x0AU,     0x12U,        0x00U }, /* NTCNR_0X01B */
        { 0x0AU,     0x13U,        0x00U }, /* NTCNR_0X01C */
        { 0x0AU,     0x14U,        0x00U }, /* NTCNR_0X01D */
        { 0x0AU,     0x15U,        0x00U }, /* NTCNR_0X01E */
        { 0x0AU,     0x16U,        0x00U }, /* NTCNR_0X01F */
        { 0x0AU,     0x17U,        0x00U }, /* NTCNR_0X020 */
        { 0x0AU,     0x18U,        0x00U }, /* NTCNR_0X021 */
        { 0x0AU,     0x19U,        0x00U }, /* NTCNR_0X022 */
        { 0x0AU,     0x1AU,        0x00U }, /* NTCNR_0X023 */
        { 0x0AU,     0x1BU,        0x00U }, /* NTCNR_0X024 */
        { 0x0AU,     0x1CU,        0x00U }, /* NTCNR_0X025 */
        { 0x0AU,     0x1DU,        0x00U }, /* NTCNR_0X026 */
        { 0x0AU,     0x1EU,        0x00U }, /* NTCNR_0X027 */
        { 0x0AU,     0x1FU,        0x00U }, /* NTCNR_0X028 */
        { 0x0AU,     0x20U,        0x00U }, /* NTCNR_0X029 */
        { 0x0AU,     0x21U,        0x00U }, /* NTCNR_0X02A */
        { 0x0AU,     0x22U,        0x02U }, /* NTCNR_0X02B */
        { 0x0AU,     0x23U,        0x00U }, /* NTCNR_0X02C */
        { 0x0AU,     0x24U,        0x00U }, /* NTCNR_0X02D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X02E */
        { 0x0AU,     0x25U,        0x00U }, /* NTCNR_0X02F */
        { 0x0AU,     0x26U,        0x00U }, /* NTCNR_0X030 */
        { 0x0AU,     0x27U,        0x00U }, /* NTCNR_0X031 */
        { 0x0AU,     0x28U,        0x03U }, /* NTCNR_0X032 */
        { 0x0AU,     0x29U,        0x04U }, /* NTCNR_0X033 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X034 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X035 */
        { 0x0AU,     0x2AU,        0x00U }, /* NTCNR_0X036 */
        { 0x0AU,     0x2BU,        0x00U }, /* NTCNR_0X037 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X038 */
        { 0x0AU,     0x2CU,        0x00U }, /* NTCNR_0X039 */
        { 0x0AU,     0x2DU,        0x00U }, /* NTCNR_0X03A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X03B */
        { 0x0AU,     0x2EU,        0x05U }, /* NTCNR_0X03C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X03D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X03E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X03F */
        { 0x0AU,     0x2FU,        0x00U }, /* NTCNR_0X040 */
        { 0x0AU,     0x30U,        0x00U }, /* NTCNR_0X041 */
        { 0x0AU,     0x31U,        0x06U }, /* NTCNR_0X042 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X043 */
        { 0x0AU,     0x32U,        0x07U }, /* NTCNR_0X044 */
        { 0x09U,     0x00U,        0x01U }, /* NTCNR_0X045 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X046 */
        { 0x0AU,     0x33U,        0x00U }, /* NTCNR_0X047 */
        { 0x0AU,     0x34U,        0x00U }, /* NTCNR_0X048 */
        { 0x0AU,     0x35U,        0x00U }, /* NTCNR_0X049 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X04A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X04B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X04C */
        { 0x0AU,     0x36U,        0x08U }, /* NTCNR_0X04D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X04E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X04F */
        { 0x0AU,     0x37U,        0x09U }, /* NTCNR_0X050 */
        { 0x0AU,     0x38U,        0x0AU }, /* NTCNR_0X051 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X052 */
        { 0x0AU,     0x39U,        0x00U }, /* NTCNR_0X053 */
        { 0x0AU,     0x3AU,        0x00U }, /* NTCNR_0X054 */
        { 0x0AU,     0x3BU,        0x0BU }, /* NTCNR_0X055 */
        { 0x0AU,     0x3CU,        0x00U }, /* NTCNR_0X056 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X057 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X058 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X059 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X05A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X05B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X05C */
        { 0x0AU,     0x3DU,        0x0CU }, /* NTCNR_0X05D */
        { 0x08U,     0x00U,        0x01U }, /* NTCNR_0X05E */
        { 0x07U,     0x00U,        0x01U }, /* NTCNR_0X05F */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X060 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X061 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X062 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X063 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X064 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X065 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X066 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X067 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X068 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X069 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X06A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X06B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X06C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X06D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X06E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X06F */
        { 0x0AU,     0x3EU,        0x00U }, /* NTCNR_0X070 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X071 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X072 */
        { 0x0AU,     0x3FU,        0x0DU }, /* NTCNR_0X073 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X074 */
        { 0x0AU,     0x40U,        0x0EU }, /* NTCNR_0X075 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X076 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X077 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X078 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X079 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X07A */
        { 0x0AU,     0x41U,        0x0FU }, /* NTCNR_0X07B */
        { 0x0AU,     0x42U,        0x10U }, /* NTCNR_0X07C */
        { 0x0AU,     0x43U,        0x11U }, /* NTCNR_0X07D */
        { 0x0AU,     0x44U,        0x12U }, /* NTCNR_0X07E */
        { 0x0AU,     0x45U,        0x13U }, /* NTCNR_0X07F */
        { 0x0AU,     0x46U,        0x14U }, /* NTCNR_0X080 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X081 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X082 */
        { 0x0AU,     0x47U,        0x15U }, /* NTCNR_0X083 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X084 */
        { 0x0AU,     0x48U,        0x16U }, /* NTCNR_0X085 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X086 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X087 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X088 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X089 */
        { 0x0AU,     0x49U,        0x00U }, /* NTCNR_0X08A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X08B */
        { 0x0AU,     0x4AU,        0x17U }, /* NTCNR_0X08C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X08D */
        { 0x0AU,     0x4BU,        0x18U }, /* NTCNR_0X08E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X08F */
        { 0x0AU,     0x4CU,        0x00U }, /* NTCNR_0X090 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X091 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X092 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X093 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X094 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X095 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X096 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X097 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X098 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X099 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X09A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X09B */
        { 0x0AU,     0x4DU,        0x00U }, /* NTCNR_0X09C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X09D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X09E */
        { 0x08U,     0x01U,        0x02U }, /* NTCNR_0X09F */
        { 0x0AU,     0x4EU,        0x00U }, /* NTCNR_0X0A0 */
        { 0x0AU,     0x4FU,        0x00U }, /* NTCNR_0X0A1 */
        { 0x0AU,     0x50U,        0x19U }, /* NTCNR_0X0A2 */
        { 0x07U,     0x01U,        0x00U }, /* NTCNR_0X0A3 */
        { 0x07U,     0x02U,        0x00U }, /* NTCNR_0X0A4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0A5 */
        { 0x0AU,     0x51U,        0x1AU }, /* NTCNR_0X0A6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0A7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0A8 */
        { 0x0AU,     0x52U,        0x00U }, /* NTCNR_0X0A9 */
        { 0x0AU,     0x53U,        0x00U }, /* NTCNR_0X0AA */
        { 0x0AU,     0x54U,        0x00U }, /* NTCNR_0X0AB */
        { 0x0AU,     0x55U,        0x00U }, /* NTCNR_0X0AC */
        { 0x0AU,     0x56U,        0x00U }, /* NTCNR_0X0AD */
        { 0x0AU,     0x57U,        0x00U }, /* NTCNR_0X0AE */
        { 0x0AU,     0x58U,        0x00U }, /* NTCNR_0X0AF */
        { 0x0AU,     0x59U,        0x1BU }, /* NTCNR_0X0B0 */
        { 0x0AU,     0x5AU,        0x1CU }, /* NTCNR_0X0B1 */
        { 0x0AU,     0x5BU,        0x00U }, /* NTCNR_0X0B2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0B3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0B4 */
        { 0x0AU,     0x5CU,        0x1DU }, /* NTCNR_0X0B5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0B6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0B7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0B8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0B9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0BA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0BB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0BC */
        { 0x0AU,     0x5DU,        0x1EU }, /* NTCNR_0X0BD */
        { 0x0AU,     0x5EU,        0x1FU }, /* NTCNR_0X0BE */
        { 0x0AU,     0x5FU,        0x00U }, /* NTCNR_0X0BF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0C9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0CA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0CB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0CC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0CD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0CE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0CF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D6 */
        { 0x0AU,     0x60U,        0x20U }, /* NTCNR_0X0D7 */
        { 0x0AU,     0x61U,        0x00U }, /* NTCNR_0X0D8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0D9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0DA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0DB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0DC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0DD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0DE */
        { 0x0AU,     0x62U,        0x00U }, /* NTCNR_0X0DF */
        { 0x0AU,     0x63U,        0x00U }, /* NTCNR_0X0E0 */
        { 0x0AU,     0x64U,        0x00U }, /* NTCNR_0X0E1 */
        { 0x09U,     0x01U,        0x00U }, /* NTCNR_0X0E2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0E3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0E4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0E5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0E6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0E7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0E8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0E9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0EA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0EB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0EC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0ED */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0EE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0EF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0F9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0FA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0FB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0FC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0FD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0FE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X0FF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X100 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X101 */
        { 0x0AU,     0x65U,        0x00U }, /* NTCNR_0X102 */
        { 0x0AU,     0x66U,        0x00U }, /* NTCNR_0X103 */
        { 0x0AU,     0x67U,        0x00U }, /* NTCNR_0X104 */
        { 0x0AU,     0x68U,        0x00U }, /* NTCNR_0X105 */
        { 0x0AU,     0x69U,        0x00U }, /* NTCNR_0X106 */
        { 0x0AU,     0x6AU,        0x00U }, /* NTCNR_0X107 */
        { 0x0AU,     0x6BU,        0x00U }, /* NTCNR_0X108 */
        { 0x0AU,     0x6CU,        0x00U }, /* NTCNR_0X109 */
        { 0x0AU,     0x6DU,        0x00U }, /* NTCNR_0X10A */
        { 0x0AU,     0x6EU,        0x00U }, /* NTCNR_0X10B */
        { 0x0AU,     0x6FU,        0x00U }, /* NTCNR_0X10C */
        { 0x0AU,     0x70U,        0x00U }, /* NTCNR_0X10D */
        { 0x0AU,     0x71U,        0x00U }, /* NTCNR_0X10E */
        { 0x0AU,     0x72U,        0x00U }, /* NTCNR_0X10F */
        { 0x0AU,     0x73U,        0x00U }, /* NTCNR_0X110 */
        { 0x0AU,     0x74U,        0x00U }, /* NTCNR_0X111 */
        { 0x0AU,     0x75U,        0x00U }, /* NTCNR_0X112 */
        { 0x0AU,     0x76U,        0x00U }, /* NTCNR_0X113 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X114 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X115 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X116 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X117 */
        { 0x0AU,     0x77U,        0x00U }, /* NTCNR_0X118 */
        { 0x0AU,     0x78U,        0x00U }, /* NTCNR_0X119 */
        { 0x0AU,     0x79U,        0x00U }, /* NTCNR_0X11A */
        { 0x0AU,     0x7AU,        0x00U }, /* NTCNR_0X11B */
        { 0x0AU,     0x7BU,        0x00U }, /* NTCNR_0X11C */
        { 0x0AU,     0x7CU,        0x00U }, /* NTCNR_0X11D */
        { 0x0AU,     0x7DU,        0x00U }, /* NTCNR_0X11E */
        { 0x0AU,     0x7EU,        0x00U }, /* NTCNR_0X11F */
        { 0x0AU,     0x7FU,        0x00U }, /* NTCNR_0X120 */
        { 0x0AU,     0x80U,        0x00U }, /* NTCNR_0X121 */
        { 0x0AU,     0x81U,        0x00U }, /* NTCNR_0X122 */
        { 0x0AU,     0x82U,        0x00U }, /* NTCNR_0X123 */
        { 0x0AU,     0x83U,        0x00U }, /* NTCNR_0X124 */
        { 0x0AU,     0x84U,        0x00U }, /* NTCNR_0X125 */
        { 0x0AU,     0x85U,        0x00U }, /* NTCNR_0X126 */
        { 0x0AU,     0x86U,        0x00U }, /* NTCNR_0X127 */
        { 0x0AU,     0x87U,        0x00U }, /* NTCNR_0X128 */
        { 0x0AU,     0x88U,        0x00U }, /* NTCNR_0X129 */
        { 0x0AU,     0x89U,        0x00U }, /* NTCNR_0X12A */
        { 0x0AU,     0x8AU,        0x00U }, /* NTCNR_0X12B */
        { 0x0AU,     0x8BU,        0x00U }, /* NTCNR_0X12C */
        { 0x0AU,     0x8CU,        0x00U }, /* NTCNR_0X12D */
        { 0x0AU,     0x8DU,        0x00U }, /* NTCNR_0X12E */
        { 0x0AU,     0x8EU,        0x00U }, /* NTCNR_0X12F */
        { 0x0AU,     0x8FU,        0x00U }, /* NTCNR_0X130 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X131 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X132 */
        { 0x0AU,     0x90U,        0x00U }, /* NTCNR_0X133 */
        { 0x0AU,     0x91U,        0x00U }, /* NTCNR_0X134 */
        { 0x0AU,     0x92U,        0x00U }, /* NTCNR_0X135 */
        { 0x0AU,     0x93U,        0x00U }, /* NTCNR_0X136 */
        { 0x0AU,     0x94U,        0x00U }, /* NTCNR_0X137 */
        { 0x0AU,     0x95U,        0x00U }, /* NTCNR_0X138 */
        { 0x0AU,     0x96U,        0x00U }, /* NTCNR_0X139 */
        { 0x0AU,     0x97U,        0x00U }, /* NTCNR_0X13A */
        { 0x0AU,     0x98U,        0x00U }, /* NTCNR_0X13B */
        { 0x0AU,     0x99U,        0x00U }, /* NTCNR_0X13C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X13D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X13E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X13F */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X140 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X141 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X142 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X143 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X144 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X145 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X146 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X147 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X148 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X149 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X14A */
        { 0x0AU,     0x9AU,        0x00U }, /* NTCNR_0X14B */
        { 0x0AU,     0x9BU,        0x00U }, /* NTCNR_0X14C */
        { 0x0AU,     0x9CU,        0x00U }, /* NTCNR_0X14D */
        { 0x0AU,     0x9DU,        0x00U }, /* NTCNR_0X14E */
        { 0x0AU,     0x9EU,        0x00U }, /* NTCNR_0X14F */
        { 0x0AU,     0x9FU,        0x00U }, /* NTCNR_0X150 */
        { 0x0AU,     0xA0U,        0x00U }, /* NTCNR_0X151 */
        { 0x0AU,     0xA1U,        0x00U }, /* NTCNR_0X152 */
        { 0x0AU,     0xA2U,        0x00U }, /* NTCNR_0X153 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X154 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X155 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X156 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X157 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X158 */
        { 0x0AU,     0xA3U,        0x00U }, /* NTCNR_0X159 */
        { 0x0AU,     0xA4U,        0x00U }, /* NTCNR_0X15A */
        { 0x0AU,     0xA5U,        0x00U }, /* NTCNR_0X15B */
        { 0x0AU,     0xA6U,        0x00U }, /* NTCNR_0X15C */
        { 0x0AU,     0xA7U,        0x00U }, /* NTCNR_0X15D */
        { 0x0AU,     0xA8U,        0x00U }, /* NTCNR_0X15E */
        { 0x0AU,     0xA9U,        0x00U }, /* NTCNR_0X15F */
        { 0x0AU,     0xAAU,        0x00U }, /* NTCNR_0X160 */
        { 0x0AU,     0xABU,        0x00U }, /* NTCNR_0X161 */
        { 0x0AU,     0xACU,        0x00U }, /* NTCNR_0X162 */
        { 0x0AU,     0xADU,        0x00U }, /* NTCNR_0X163 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X164 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X165 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X166 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X167 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X168 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X169 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X16A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X16B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X16C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X16D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X16E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X16F */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X170 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X171 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X172 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X173 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X174 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X175 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X176 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X177 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X178 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X179 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X17A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X17B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X17C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X17D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X17E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X17F */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X180 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X181 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X182 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X183 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X184 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X185 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X186 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X187 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X188 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X189 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X18A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X18B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X18C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X18D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X18E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X18F */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X190 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X191 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X192 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X193 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X194 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X195 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X196 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X197 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X198 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X199 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X19A */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X19B */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X19C */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X19D */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X19E */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X19F */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1A9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1AA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1AB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1AC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1AD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1AE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1AF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1B9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1BA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1BB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1BC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1BD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1BE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1BF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1C9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1CA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1CB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1CC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1CD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1CE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1CF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1D9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1DA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1DB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1DC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1DD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1DE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1DF */
        { 0x0AU,     0xAEU,        0x00U }, /* NTCNR_0X1E0 */
        { 0x0AU,     0xAFU,        0x00U }, /* NTCNR_0X1E1 */
        { 0x0AU,     0xB0U,        0x00U }, /* NTCNR_0X1E2 */
        { 0x0AU,     0xB1U,        0x00U }, /* NTCNR_0X1E3 */
        { 0x0AU,     0xB2U,        0x00U }, /* NTCNR_0X1E4 */
        { 0x0AU,     0xB3U,        0x00U }, /* NTCNR_0X1E5 */
        { 0x0AU,     0xB4U,        0x00U }, /* NTCNR_0X1E6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1E7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1E8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1E9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1EA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1EB */
        { 0x0AU,     0xB5U,        0x00U }, /* NTCNR_0X1EC */
        { 0x0AU,     0xB6U,        0x00U }, /* NTCNR_0X1ED */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1EE */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1EF */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F0 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F1 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F2 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F3 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F4 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F5 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F6 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F7 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F8 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1F9 */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1FA */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1FB */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1FC */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1FD */
        { 0xFFU,     0xFFU,        0x00U }, /* NTCNR_0X1FE */
        { 0x0AU,     0xB7U,        0x00U }, /* NTCNR_0X1FF */
    };

/* 
     * Description: Configuration for the properties for each of the 512 NTCs in system
     *              based on the NTC master list of the project
     * Usage:       Every active NTC should be configured as per NTC Master List
     */
CONST(uint8, DiagcMgr_CODE) DIAGCMGRNTCPPTYARY_CNT_U08[D_MAXNUMBEROFNTCS_CNT_U16]= {0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X000 - NTCNR_0X00F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X010 - NTCNR_0X01F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X020 - NTCNR_0X02F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X030 - NTCNR_0X03F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X040 - NTCNR_0X04F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X050 - NTCNR_0X05F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X060 - NTCNR_0X06F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X070 - NTCNR_0X07F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X080 - NTCNR_0X08F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X090 - NTCNR_0X09F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X0A0 - NTCNR_0X0AF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X0B0 - NTCNR_0X0BF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X0C0 - NTCNR_0X0CF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X0D0 - NTCNR_0X0DF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X0E0 - NTCNR_0X0EF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X0F0 - NTCNR_0X0FF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X100 - NTCNR_0X10F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X110 - NTCNR_0X11F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X120 - NTCNR_0X12F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X130 - NTCNR_0X13F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X140 - NTCNR_0X14F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X150 - NTCNR_0X15F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X160 - NTCNR_0X16F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X170 - NTCNR_0X17F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X180 - NTCNR_0X18F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X190 - NTCNR_0X19F*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X1A0 - NTCNR_0X1AF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X1B0 - NTCNR_0X1BF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X1C0 - NTCNR_0X1CF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X1D0 - NTCNR_0X1DF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,  /*NTCNR_0X1E0 - NTCNR_0X1EF*/
                                                                                    0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U,0X00U}; /*NTCNR_0X1F0 - NTCNR_0X1FF*/


    /* 
     * Description: List of the NTC numbers for Latch-Capable NTCs of this project. 
     * Usage:       Upto 20 NTCs for a project can be configured as latch capable.
     *              The NTCs for which LtchgEna is set to true will be reflected here.
     *              Any remaining unconfigured elements are set to NTC_RESD(0X000U)
     */
    CONST(uint16,DiagcMgr_CODE) DIAGCMGRLISTOFLTCHGNTC_CNT_ENUM[D_MAXNUMOFLTCHGNTCS_CNT_U16] = {0x000U,0x000U,0x000U,0x000U,0x000U, 
                                                                                                0X000U,0x000U,0x000U,0x000U,0x000U, 
                                                                                                0X000U,0x000U,0x000U,0x000U,0x000U, 
                                                                                                0X000U,0x000U,0x000U,0x000U,0x000U};

    /* 
     * Description: List of the Thresholds for latch capable NTCs 
     * Usage:       Each latch capable NTC must have a threshold set from 1-255
     *              If LtchEna is false but threshold is set it wont appear here.
     */
    CONST(uint8,DiagcMgr_CODE) DIAGCMGRNTCLTCHCNTRTHD_CNT_U08[D_MAXNUMOFLTCHGNTCS_CNT_U16] = {0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU,0XFFU};

    /** Ntc Info Arrays **/
    /* 
     * Description: NtcNr reference for NtcInfoAry 
     */
  
    /* Note: No NTCs Configured for SystemApplication */
  
    /* Note: No NTCs Configured for Appl0 */
  
  
    CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL10_CNT_U16[NTCCNTAPPL10_CNT_U16] = 
    { 0X002U ,    0X003U ,    0X004U ,    0X006U ,    0X007U ,    0X008U ,    0X00AU ,    0X00DU ,    0X010U ,    0X012U ,    0X013U ,    0X014U ,    0X015U ,    0X016U ,    0X017U ,    0X018U ,    0X019U ,    0X01AU ,    0X01BU ,    0X01CU ,    0X01DU ,    0X01EU ,    0X01FU ,    0X020U ,    0X021U ,    0X022U ,    0X023U ,    0X024U ,    0X025U ,    0X026U ,    0X027U ,    0X028U ,    0X029U ,    0X02AU ,    0X02BU ,    0X02CU ,    0X02DU ,    0X02FU ,    0X030U ,    0X031U ,    0X032U ,    0X033U ,    0X036U ,    0X037U ,    0X039U ,    0X03AU ,    0X03CU ,    0X040U ,    0X041U ,    0X042U ,    0X044U ,    0X047U ,    0X048U ,    0X049U ,    0X04DU ,    0X050U ,    0X051U ,    0X053U ,    0X054U ,    0X055U ,    0X056U ,    0X05DU ,    0X070U ,    0X073U ,    0X075U ,    0X07BU ,    0X07CU ,    0X07DU ,    0X07EU ,    0X07FU ,    0X080U ,    0X083U ,    0X085U ,    0X08AU ,    0X08CU ,    0X08EU ,    0X090U ,    0X09CU ,    0X0A0U ,    0X0A1U ,    0X0A2U ,    0X0A6U ,    0X0A9U ,    0X0AAU ,    0X0ABU ,    0X0ACU ,    0X0ADU ,    0X0AEU ,    0X0AFU ,    0X0B0U ,    0X0B1U ,    0X0B2U ,    0X0B5U ,    0X0BDU ,    0X0BEU ,    0X0BFU ,    0X0D7U ,    0X0D8U ,    0X0DFU ,    0X0E0U ,    0X0E1U ,    0X102U ,    0X103U ,    0X104U ,    0X105U ,    0X106U ,    0X107U ,    0X108U ,    0X109U ,    0X10AU ,    0X10BU ,    0X10CU ,    0X10DU ,    0X10EU ,    0X10FU ,    0X110U ,    0X111U ,    0X112U ,    0X113U ,    0X118U ,    0X119U ,    0X11AU ,    0X11BU ,    0X11CU ,    0X11DU ,    0X11EU ,    0X11FU ,    0X120U ,    0X121U ,    0X122U ,    0X123U ,    0X124U ,    0X125U ,    0X126U ,    0X127U ,    0X128U ,    0X129U ,    0X12AU ,    0X12BU ,    0X12CU ,    0X12DU ,    0X12EU ,    0X12FU ,    0X130U ,    0X133U ,    0X134U ,    0X135U ,    0X136U ,    0X137U ,    0X138U ,    0X139U ,    0X13AU ,    0X13BU ,    0X13CU ,    0X14BU ,    0X14CU ,    0X14DU ,    0X14EU ,    0X14FU ,    0X150U ,    0X151U ,    0X152U ,    0X153U ,    0X159U ,    0X15AU ,    0X15BU ,    0X15CU ,    0X15DU ,    0X15EU ,    0X15FU ,    0X160U ,    0X161U ,    0X162U ,    0X163U ,    0X1E0U ,    0X1E1U ,    0X1E2U ,    0X1E3U ,    0X1E4U ,    0X1E5U ,    0X1E6U ,    0X1ECU ,    0X1EDU ,    0X1FFU }; /* 184 */ 
  
  
    CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL7_CNT_U16[NTCCNTAPPL7_CNT_U16] = 
    { 0X05FU ,    0X0A3U ,    0X0A4U }; /* 3 */ 
  
  
    CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL8_CNT_U16[NTCCNTAPPL8_CNT_U16] = 
    { 0X05EU ,    0X09FU }; /* 2 */ 
  
  
    CONST(uint16, DiagcMgr_CODE) NTCNRARYAPPL9_CNT_U16[NTCCNTAPPL9_CNT_U16] = 
    { 0X045U ,    0X0E2U }; /* 2 */ 

    /* Table Contents: DTCENAMASK */
    CONST(uint16, DiagcMgr_CODE) DTCENAMASK[TOTNROFDTC_CNT_U08 +1U] = {
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    0x0000U,
    };

    /* Table Contents: DEMDTCEVEIDMAP */
    CONST(uint16, DiagcMgr_CODE) DEMDTCEVEIDMAP[TOTNROFDTC_CNT_U08 +1U]= {
    0x0000U,
    DemConf_DemEventParameter_DmTestAppl,
    DemConf_DemEventParameter_CodingEventUnqualifiedData,
    DemConf_DemEventParameter_VsmEventOpmode,
    DemConf_DemEventParameter_CodingEventNotCoded,
    DemConf_DemEventParameter_CodingEventWrongVehicle,
    DemConf_DemEventParameter_LocalOvervoltage,
    DemConf_DemEventParameter_LocalUndervoltage,
    DemConf_DemEventParameter_GlobalOvervoltageInt,
    DemConf_DemEventParameter_GlobalOvervoltageExt,
    DemConf_DemEventParameter_GlobalUndervoltageInt,
    DemConf_DemEventParameter_GlobalUndervoltageExt,
    DemConf_DemEventParameter_DmTestCom,
    DemConf_DemEventParameter_FrtrcvEFrBuserrorTrcv0,
    DemConf_DemEventParameter_FrsmEClusterSyncLoss,
    /* NXTR PATCH START
     * The following code was patched from the generated file until a solution is 
     * available KJS - 16Mar18*/
    DemConf_DemEventParameter_PriEve4822E4_SecEve21F100,
    DemConf_DemEventParameter_PriEve4822E4_SecEve31F100,
    DemConf_DemEventParameter_PriEve4822F5_SecEve21F300,
    DemConf_DemEventParameter_PriEve4822F5_SecEve31F300,
    DemConf_DemEventParameter_SecondaryEve_20F300,
    DemConf_DemEventParameter_SecondaryEve_30F300,
    DemConf_DemEventParameter_SecondaryEve_31F100,
    DemConf_DemEventParameter_SecondaryEve_31F300,
    /* NXTR PATCH END */
    };
#define DiagcMgr_STOP_SEC_CODE
#include "DiagcMgr_MemMap.h"

