/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_TSG31CfgAndUse.c
 *        Config:  E:/EA4NewTemplate/CM475A_TSG31CfgAndUse_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_TSG31CfgAndUse
 *  Generated at:  Tue Jan 23 10:19:42 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_TSG31CfgAndUse>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2015, 2016, 2017, 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name: CDD_TSG31CfgAndUse.c
* Module Description: Configuration and use of the TSG31 timer peripheral
* Project           : CBD   
* Author            : Kathleen Creager
*****************************************************************************
* Version Control:
* %version:          7 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/20/15  1        KMC        Initial version                                                                 EA4#337
* 06/20/15  2        KMC        changed CnvNanoSecToHalfTmrCnt() to CnvNanoSecToTmrCnt() and added              EA4#865
*                               masking per FDD 1.3.0
* 07/13/15  3        NS         Changed TSG31IOC0 bit settings and changed TSG31UPD_NANOSEC_U32 from            EA4#1090/1091
*                               2us to 5us per FDD 1.4.0
* 12/15/16  4        AJM        Added configurable motor control ISR interrupt source per design 1.7.0          EA4#8923
* 05/3/17   5        SPP        Removed application data types                                                  EA4#11047
* 05/3/17   6        AJM        Added PhaDiscnctDiagcActv check                                                 EA4#14408
* 03/27/17  7        AJM        Added Pim Initialization in the init function, removed requirement tags         EA4#20019
************************************************************************************************************************/
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
 * MotCurrEolCalSt2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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

#include "Rte_CDD_TSG31CfgAndUse.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CDD_TSG31CfgAndUse_private.h"
#include "ElecGlbPrm.h"
#include "tsg3_regs.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


#define MOTAG2SPISTRT_NANOSEC_U32       ((uint32)10000U)
#define TSG31UPD_NANOSEC_U32            ((uint32)5000U)
#define MISSUPDTMINCNTRININ_CNT_T_U16   ((uint16)0xFFFFU)

static FUNC (void, CDD_TSG31CfgAndUse_CODE) MapPinsToGpio (void);
static FUNC (void, CDD_TSG31CfgAndUse_CODE) MapFetCtrlSigToGpioAndSetLow (void);
static FUNC (void, CDD_TSG31CfgAndUse_CODE) NoTranSysStNotEn (SysSt1 SysSt_Cnt_T_enum, boolean PhaDiscnctDiagcActv_Cnt_T_lgc);
static FUNC (void, CDD_TSG31CfgAndUse_CODE) TranToEn (void);
static FUNC (void, CDD_TSG31CfgAndUse_CODE) TranFromEn (void);
static FUNC (void, CDD_TSG31CfgAndUse_CODE) NoTranSysStIsEn (MotCurrEolCalSt2 MotCurrEolCalSt_Cnt_T_enum);


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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * MotCurrEolCalSt2: Enumeration of integer in interval [0...255] with enumerators
 *   MCECS_OFFSCMDSTRT (0U)
 *   MCECS_OFFSCMDHI (1U)
 *   MCECS_OFFSCMDLO (2U)
 *   MCECS_OFFSCMDZERO (3U)
 *   MCECS_OFFSCMDEND (4U)
 *   MCECS_GAINCMDAD (5U)
 *   MCECS_GAINCMDBE (6U)
 *   MCECS_GAINCMDCF (7U)
 *   MCECS_CMDSAFEST (8U)
 * SysSt1: Enumeration of integer in interval [0...255] with enumerators
 *   SYSST_DI (0U)
 *   SYSST_OFF (1U)
 *   SYSST_ENA (2U)
 *   SYSST_WRMININ (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak(void)
 *   uint32 *Rte_Pim_TSG31CfgAndUseMotAg0SPIStart(void)
 *   uint16 *Rte_Pim_MissUpdCoarse(void)
 *   uint16 *Rte_Pim_MissUpdFine(void)
 *   uint16 *Rte_Pim_MissUpdMaxCntr(void)
 *   uint16 *Rte_Pim_MissUpdMinCntr(void)
 *   uint8 *Rte_Pim_MissUpdIninCntr(void)
 *   boolean *Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev(void)
 *   boolean *Rte_Pim_TSG31CfgAndUseSysStEnaPrev(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint32 Rte_Prm_CurrMeasEolFixdPwmPerd_Val(void)
 *   uint32 Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val(void)
 *   uint32 Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPhaOnTi_Val(void)
 *   uint32 Rte_Prm_PhaDiscnctFixdPwmPerd_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val(void)
 *   uint32 Rte_Prm_TSG31CfgAndUsePwmDbnd_Val(void)
 *
 *********************************************************************************************************************/


#define CDD_TSG31CfgAndUse_START_SEC_CODE
#include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSG31CfgAndUseInit1
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
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUseInit1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUseInit1
 *********************************************************************************************************************/
    VAR (uint32, AUTOMATIC) RawTmrCnt_Cnt_T_u32;
    VAR (uint32, AUTOMATIC) PwmPerdMin_Cnt_T_u32;
    
    /* Map FET Ctrl Signals to GPIO and Set Low */
    MapFetCtrlSigToGpioAndSetLow();
    
    /* PWM Dead Band */
    RawTmrCnt_Cnt_T_u32 = CnvNanoSecToTmrCnt(Rte_Prm_TSG31CfgAndUsePwmDbnd_Val());
    TSG31DTC1 = RawTmrCnt_Cnt_T_u32;
    TSG31DTC0 = RawTmrCnt_Cnt_T_u32;

    /* Minimum PWM Period */
    PwmPerdMin_Cnt_T_u32 = CnvNanoSecToTmrCnt(ELECGLBPRM_PWMPERDMIN_NANOSEC_U32);
    TSG31CMP0E = PwmPerdMin_Cnt_T_u32;
    TSG31CMPUE = PwmPerdMin_Cnt_T_u32;
    TSG31CMPVE = PwmPerdMin_Cnt_T_u32;
    TSG31CMPWE = PwmPerdMin_Cnt_T_u32;

    /* PeakMtrCtrlADCOffset */
    *Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak() = CnvNanoSecToTmrCnt(Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlPeakOffs_Val());
    RawTmrCnt_Cnt_T_u32 = PwmPerdMin_Cnt_T_u32 - *Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak();
    TSG31DCMP0E = RawTmrCnt_Cnt_T_u32 & CLRBIT0MASK_CNT_U32;

    /* MotAg0 SPI Transmission Start */ 
    *Rte_Pim_TSG31CfgAndUseMotAg0SPIStart() = CnvNanoSecToTmrCnt(Rte_Prm_TSG31CfgAndUseMtrAg0SPIStart_Val());
    RawTmrCnt_Cnt_T_u32 = PwmPerdMin_Cnt_T_u32 - *Rte_Pim_TSG31CfgAndUseMotAg0SPIStart();
    TSG31CMP12E = RawTmrCnt_Cnt_T_u32 & CLRBIT0MASK_CNT_U32;

    /* 2mSecADCOffset */
    RawTmrCnt_Cnt_T_u32 = CnvNanoSecToTmrCnt(Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvn2Offs_Val());
    TSG31DCMP1E = RawTmrCnt_Cnt_T_u32 & CLRBIT0MASK_CNT_U32;

    /* VlyMtrCtrlADCOffset */
    RawTmrCnt_Cnt_T_u32 = CnvNanoSecToTmrCnt(Rte_Prm_TSG31CfgAndUseAdcStrtOfCnvnMotCtrlVlyOffs_Val());
    TSG31CMP7E = RawTmrCnt_Cnt_T_u32 & CLRBIT0MASK_CNT_U32;

    /* TSG31UPDATE */
    RawTmrCnt_Cnt_T_u32 = CnvNanoSecToTmrCnt(TSG31UPD_NANOSEC_U32);
    TSG31CMP11E = RawTmrCnt_Cnt_T_u32 & CLRBIT0MASK_CNT_U32;

    /* CM475A_TSG31RegisterConfiguration.xlsm */

    TSG31CTL0 = 0x00U      /* only write when timer is stopped */
                | (uint8)(0x00U << 4U)  /* DWD */
                | (uint8)(0x01U << 0U); /* MD */ 
    
    TSG31CTL1 = 0x0000U /* only write when timer is stopped */
                | (uint16)((uint16)0x00U << 9U) /* TBA2 */
                | (uint16)((uint16)0x00U << 8U) /* TBA1 */
                | (uint16)((uint16)0x00U << 7U) /* TBA0 */
                | (uint16)((uint16)0x00U << 6U) /* PPC */
                | (uint16)((uint16)0x00U << 5U) /* PEC */
                | (uint16)((uint16)0x00U << 4U) /* TDC */
                | (uint16)((uint16)0x00U << 3U) /* NDC */
                | (uint16)((uint16)0x00U << 2U) /* PRC */
                | (uint16)((uint16)0x00U << 0U); /* PTC */
                
    TSG31CTL2 = 0x00000000U
                | (uint32)((uint32)0x00U << 0U); /* CKS */
                
    TSG31CTL3 = 0x00U    
                | (uint8)(0x00U << 1U)  /* RIA */
                | (uint8)(0x00U << 0U); /* RMC */ 
    
    TSG31CTL4 = 0x00000000U
                | (uint32)((uint32)0x00U << 8U) /* PRE */
                | (uint32)((uint32)0x01U << 7U) /* VRE */
                | (uint32)((uint32)0x00U << 6U) /* PIE */
                | (uint32)((uint32)0x01U << 5U) /* VIE */
                | (uint32)((uint32)0x00U << 0U); /* RCC */
                
    if((ELECGLBPRM_MOTCTRLINTRPTTRIGSRC_CNT_U08 == ELECGLBPRM_MOTCTRLINTRPTTRIGCFGB_CNT_U08))
    {
        TSG31CTL4 |= (uint32)((uint32)0x01U << 6U); /* PIE */
    }
    
    TSG31CTL5 = 0x0000U 
                | (uint16)((uint16)0x00U << 10U) /* ACC */
                | (uint16)((uint16)0x00U << 9U) /* AT09 */
                | (uint16)((uint16)0x00U << 8U) /* AT08 */
                | (uint16)((uint16)0x00U << 7U) /* AT07 */
                | (uint16)((uint16)0x00U << 6U) /* AT06 */
                | (uint16)((uint16)0x00U << 5U) /* AT05 */
                | (uint16)((uint16)0x00U << 4U) /* AT04 */
                | (uint16)((uint16)0x00U << 3U) /* AT03 */
                | (uint16)((uint16)0x01U << 2U) /* AT02 */
                | (uint16)((uint16)0x00U << 1U) /* AT01 */
                | (uint16)((uint16)0x00U << 0U); /* AT00 */
    
    
    TSG31CTL6 = 0x0000U 
                | (uint16)((uint16)0x00U << 10U) /* ACC */
                | (uint16)((uint16)0x00U << 9U) /* AT19 */
                | (uint16)((uint16)0x00U << 8U) /* AT18 */
                | (uint16)((uint16)0x00U << 7U) /* AT17 */
                | (uint16)((uint16)0x00U << 6U) /* AT16 */
                | (uint16)((uint16)0x01U << 5U) /* AT15 */
                | (uint16)((uint16)0x00U << 4U) /* AT14 */
                | (uint16)((uint16)0x00U << 3U) /* AT13 */
                | (uint16)((uint16)0x00U << 2U) /* AT12 */
                | (uint16)((uint16)0x00U << 1U) /* AT11 */
                | (uint16)((uint16)0x00U << 0U); /* AT10 */
    
    TSG31IOC0 = 0x00U         /* only write when timer is stopped */
                | (uint8)(0x01U << 6U)  /* TOE6 */
                | (uint8)(0x01U << 5U)  /* TOE5 */
                | (uint8)(0x01U << 4U)  /* TOE4 */
                | (uint8)(0x01U << 3U)  /* TOE3 */
                | (uint8)(0x01U << 2U)  /* TOE2 */
                | (uint8)(0x01U << 1U); /* TOE1 */ 

    TSG31IOC1 = 0x00U         /* only write when timer is stopped */
                | (uint8)(0x00U << 4U)  /* PTS */
                | (uint8)(0x00U << 3U)  /* EOC */
                | (uint8)(0x00U << 2U)  /* WOC */
                | (uint8)(0x00U << 1U)  /* TGS */
                | (uint8)(0x00U << 0U); /* TOS */ 
    
    TSG31IOC2 = 0x0000U 
                | (uint16)((uint16)0x00U << 14U) /* OL6 */
                | (uint16)((uint16)0x00U << 13U) /* OL5 */
                | (uint16)((uint16)0x00U << 12U) /* OL4 */
                | (uint16)((uint16)0x00U << 11U) /* OL3 */
                | (uint16)((uint16)0x00U << 10U) /* OL2 */
                | (uint16)((uint16)0x00U << 9U) /* OL1 */
                | (uint16)((uint16)0x00U << 6U) /* TO6 */
                | (uint16)((uint16)0x00U << 5U) /* TO5 */
                | (uint16)((uint16)0x00U << 4U) /* TO4 */
                | (uint16)((uint16)0x00U << 3U) /* TO3 */
                | (uint16)((uint16)0x00U << 2U) /* TO2 */
                | (uint16)((uint16)0x00U << 1U); /* TO1 */
    
    TSG31IOC3 = 0x00000000U
                | (uint32)((uint32)0x00U << 6U) /* TOL6 */
                | (uint32)((uint32)0x00U << 5U) /* TOL5 */
                | (uint32)((uint32)0x00U << 4U) /* TOL4 */
                | (uint32)((uint32)0x00U << 3U) /* TOL3 */
                | (uint32)((uint32)0x00U << 2U) /* TOL2 */
                | (uint32)((uint32)0x00U << 1U); /* TOL1 */
    
    TSG31STC = 0x0000U         
                | (uint16)((uint16)0x00U << 9U)  /* TBR2 */
                | (uint16)((uint16)0x00U << 8U)  /* TBR1 */
                | (uint16)((uint16)0x00U << 7U)  /* TBR0 */
                | (uint16)((uint16)0x00U << 6U)  /* PPR */
                | (uint16)((uint16)0x00U << 5U)  /* PER */
                | (uint16)((uint16)0x00U << 4U)  /* TDR */
                | (uint16)((uint16)0x00U << 3U)  /* NDR */
                | (uint16)((uint16)0x00U << 2U)  /* PRR */
                | (uint16)((uint16)0x00U << 1U); /* PTR */ 
    
    TSG31TRG2 = 0x00U
                | (uint8)(0x00U << 0U); /* IMT */
                
    /* write protection code check bits [30:16] = 0000 */
    TSG31DTC0W &= (uint32)0x8000FFFFU;

    /* write protection code check bits [30:16] = 0000 */
    TSG31DTC1W &= (uint32)0x8000FFFFU; 
    
    TSG31DTCM = 0x0000U; /* DTCM */    /* only write when timer is stopped */
    TSG31DTPR &= 0x8000U; /* write protection code */    /* only write when timer is stopped */
                
    TSG31TS = 0x01U;  /* start the timer */
    
    TSG31DCMP2E = 0x00000000UL;
    TSG31CMP4E = 0x00000000UL;
    TSG31CMP3E = 0x00000000UL;

    /* Initialization for the diagnostic counters */
    *Rte_Pim_MissUpdMaxCntr() = 0U;
    *Rte_Pim_MissUpdMinCntr() = MISSUPDTMINCNTRININ_CNT_T_U16;
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSG31CfgAndUsePer2
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
 *   Std_ReturnType Rte_Read_MotCurrEolCalSt_Val(MotCurrEolCalSt2 *data)
 *   Std_ReturnType Rte_Read_PhaDiscnctDiagcActv_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUsePer2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUsePer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSG31CfgAndUsePer2
 *********************************************************************************************************************/
    VAR (SysSt1, AUTOMATIC) SysSt_Cnt_T_enum;
    VAR (MotCurrEolCalSt2, AUTOMATIC) MotCurrEolCalSt_Cnt_T_enum;
    VAR (boolean, AUTOMATIC) SysStEn_Cnt_T_lgc;
    VAR (boolean, AUTOMATIC) PhaDiscnctDiagcActv_Cnt_T_lgc;
    
    (void) Rte_Read_SysSt_Val(&SysSt_Cnt_T_enum);
    (void) Rte_Read_MotCurrEolCalSt_Val(&MotCurrEolCalSt_Cnt_T_enum);
    (void) Rte_Read_PhaDiscnctDiagcActv_Logl(&PhaDiscnctDiagcActv_Cnt_T_lgc);

    /* Relational Operator */
    if (SysSt_Cnt_T_enum == SYSST_ENA)
    {
        SysStEn_Cnt_T_lgc = TRUE;
    }
    else
    {
        SysStEn_Cnt_T_lgc = FALSE;
    }
    
    /* Truth Table */
    if (SysStEn_Cnt_T_lgc == TRUE)
    {
        if (*Rte_Pim_TSG31CfgAndUseSysStEnaPrev() == TRUE)
        {
            /* No Transition; SysState = Enable */
            NoTranSysStIsEn(MotCurrEolCalSt_Cnt_T_enum);
        }
        else
        {
            /* Transition to Enable */
            TranToEn();
        }
    }
    else
    {
        if (*Rte_Pim_TSG31CfgAndUseSysStEnaPrev() == TRUE)
        {
            /* Transition from Enable */
            TranFromEn();
        }
        else
        {
            /* No Transition; SysSt != Enable */
            NoTranSysStNotEn(SysSt_Cnt_T_enum,PhaDiscnctDiagcActv_Cnt_T_lgc);
        }
    }
    
    /* Unit Delay */
    *Rte_Pim_TSG31CfgAndUseSysStEnaPrev() = SysStEn_Cnt_T_lgc;    

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_TSG31CfgAndUse_STOP_SEC_CODE
#include "CDD_TSG31CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /******************************************************************************
  * Name:        NoTranSysStIsEn
  * Description: Action for the "No Transition; SysSt = Enable" case in
  *              TSG31CfgAndUsePer2
  * Inputs:      NONE     
  * Outputs:     NONE 
  * Usage Notes: NONE 
  ****************************************************************************/
static FUNC (void, CDD_TSG31CfgAndUse_CODE) NoTranSysStIsEn (MotCurrEolCalSt2 MotCurrEolCalSt_Cnt_T_enum)
{
    /* No Transition; SysSt = Enable */
    /* Switch Case */
    switch (MotCurrEolCalSt_Cnt_T_enum)
    {
        case MCECS_OFFSCMDEND:
        case MCECS_GAINCMDAD:
            /* Map Pins to GPIO */
            MapPinsToGpio();
            /* Set GPIO Level */
            (void) Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(STD_HIGH);
            (void) Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(STD_LOW);
        break;
        
        case MCECS_GAINCMDBE:
            /* Map Pins to GPIO */
            MapPinsToGpio();
            /* Set GPIO Level */
            (void) Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(STD_HIGH);
            (void) Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(STD_LOW);
        break;
        
        case MCECS_GAINCMDCF:
            /* Map Pins to GPIO */
            MapPinsToGpio();
            /* Set GPIO Level */
            (void) Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(STD_HIGH);
            (void) Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(STD_LOW);
        break;
        
        case MCECS_CMDSAFEST:
            /* Map Pins to GPIO */
            MapPinsToGpio();
            /* Set GPIO Level */
            (void) Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(STD_LOW);
            (void) Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(STD_LOW);
        break;
        
        default:
            /* Do Nothing */
        break;
    }
    
}

/******************************************************************************
  * Name:        TranFromEn
  * Description: Action for the "Transition from Enable" case in
  *              TSG31CfgAndUsePer2
  * Inputs:      NONE     
  * Outputs:     NONE 
  * Usage Notes: NONE 
  ****************************************************************************/
static FUNC (void, CDD_TSG31CfgAndUse_CODE) TranFromEn (void)
{
    /* Transition From Enable */
    /* Map FET Ctrl Signals to GPIO and Set Low */
    MapFetCtrlSigToGpioAndSetLow();
    
}

/******************************************************************************
  * Name:        TranToEn
  * Description: Action for the "Transition to Enable" case in
  *              TSG31CfgAndUsePer2
  * Inputs:      NONE     
  * Outputs:     NONE 
  * Usage Notes: NONE 
  ****************************************************************************/
static FUNC (void, CDD_TSG31CfgAndUse_CODE) TranToEn (void)
{
    /* Transition to Enable */
    /* Map Pins to Peripheral */
    (void) Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper();
    
}

/******************************************************************************
  * Name:        NoTranSysStNotEn
  * Description: Action for the "No Transition; SysSt != Enable" case in
  *              TSG31CfgAndUsePer2
  * Inputs:      SysSt_Cnt_T_enum -System State , PhaDiscnctDiagcActv_Cnt_T_lgc -
                 Phase disconnect diagnostic active flag
  * Outputs:     NONE 
  * Usage Notes: NONE 
  ****************************************************************************/
static FUNC (void, CDD_TSG31CfgAndUse_CODE) NoTranSysStNotEn (SysSt1 SysSt_Cnt_T_enum, boolean PhaDiscnctDiagcActv_Cnt_T_lgc)
{
    VAR (boolean, AUTOMATIC) SysStWrmIninAndPhaDiscnctDiagcActv_Cnt_T_lgc = FALSE;
        
    /* No Transition; SysState != Enable */
    if((SysSt_Cnt_T_enum == SYSST_WRMININ) && (PhaDiscnctDiagcActv_Cnt_T_lgc == TRUE))
    {
        SysStWrmIninAndPhaDiscnctDiagcActv_Cnt_T_lgc = TRUE; 
    }
    
    if((SysStWrmIninAndPhaDiscnctDiagcActv_Cnt_T_lgc == TRUE) && (*Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() == FALSE))
    {
        /* Phase Disconnect Diagnostic Activated */
        (void) Rte_Call_IoHwAb_SetFctPeriphPhaALowrCmd_Oper();
        (void) Rte_Call_IoHwAb_SetFctPeriphPhaAUpprCmd_Oper();
        (void) Rte_Call_IoHwAb_SetFctPeriphPhaBLowrCmd_Oper();
        (void) Rte_Call_IoHwAb_SetFctPeriphPhaBUpprCmd_Oper();
        (void) Rte_Call_IoHwAb_SetFctPeriphPhaCLowrCmd_Oper();
        (void) Rte_Call_IoHwAb_SetFctPeriphPhaCUpprCmd_Oper();
    }
    else if((SysStWrmIninAndPhaDiscnctDiagcActv_Cnt_T_lgc == FALSE) && (*Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() == TRUE))
    {
        /* Phase Disconnect Diagnostic Dectivated */
        /* Map Pins to GPIO */
        MapPinsToGpio();
        /* Set GPIO Level to low */
        (void) Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(STD_LOW);
        (void) Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(STD_LOW);
        (void) Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(STD_LOW);
        (void) Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(STD_LOW);
        (void) Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(STD_LOW);
        (void) Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(STD_LOW);        
    }
    else
    {
        /* Do nothing */
    }
    
    *Rte_Pim_TSG31CfgAndUsePhaDiscntActvdStPrev() = SysStWrmIninAndPhaDiscnctDiagcActv_Cnt_T_lgc;
}

/******************************************************************************
  * Name:        MapFetCtrlSigToGpioAndSetLow
  * Description: Maps the PhaXUpprCmd and PhaXLowrCmd pins (for phases A, B, and C) 
  *              for use as GPIO pins and set their output value LOW
  * Inputs:      NONE     
  * Outputs:     NONE 
  * Usage Notes: NONE 
  ****************************************************************************/
static FUNC (void, CDD_TSG31CfgAndUse_CODE) MapFetCtrlSigToGpioAndSetLow (void)
{

    /* Map Pins to GPIO */
    MapPinsToGpio();

    /* Set GPIO Level */
    (void) Rte_Call_IoHwAb_SetGpioPhaALowrCmd_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetGpioPhaAUpprCmd_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetGpioPhaBLowrCmd_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetGpioPhaBUpprCmd_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetGpioPhaCLowrCmd_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetGpioPhaCUpprCmd_Oper(STD_LOW);
}

/******************************************************************************
  * Name:        MapPinsToGpio
  * Description: Maps the PhaXUpprCmd and PhaXLowrCmd pins (for phases A, B, and C) 
  *              for use as GPIO pins
  * Inputs:      NONE     
  * Outputs:     NONE 
  * Usage Notes: NONE 
  ****************************************************************************/
static FUNC (void, CDD_TSG31CfgAndUse_CODE) MapPinsToGpio (void)
{
    /* Map Pins to GPIO */
    (void) Rte_Call_IoHwAb_SetFctGpioPhaALowrCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctGpioPhaAUpprCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctGpioPhaBLowrCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctGpioPhaBUpprCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctGpioPhaCLowrCmd_Oper();
    (void) Rte_Call_IoHwAb_SetFctGpioPhaCUpprCmd_Oper();
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
