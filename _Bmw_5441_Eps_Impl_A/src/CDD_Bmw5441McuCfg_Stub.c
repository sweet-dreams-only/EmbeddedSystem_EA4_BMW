/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Bmw5441McuCfg.c
 *        Config:  C:/Component/FAAR_WE_Synergy/_Bmw_5441_Eps_Impl_A/autosar/EPS.dpa
 *     SW-C Type:  CDD_Bmw5441McuCfg
 *  Generated at:  Wed Apr 18 12:45:12 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Bmw5441McuCfg>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */


/**********************************************************************************************************************
* Copyright 2017 Nxtr
* Nxtr Confidential
*
* Module File Name:   CDD_Bmw5441McuCfg_Stub.c
* Module Description: Stub BMW 5441 Mcu Config File until component is created and implemented
* Project           : BMW 5441
* Author            : Kevin Smith
***********************************************************************************************************************
* Version Control:
* %version:          9 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 09/26/17  1        KJS       Initial Version. TODO comments added as placeholders for functions from 
*                              components that are being integrated into the project for the first build      EA4#14844
* 10/18/17  2        KJS       Added battery, ECU temperature, and handwheel torque.
*                              Created test ports to force states and modes to operate while MMs are being 
*                              implemented.                                                                   EA4#14844
* 11/23/17  3        AR        Removed stubs added in place of CF069A.                                        EA4#17066
* 01/29/18  4        AR        Changes made for ES252A_RvsBattProtn integration                               EA4#19850
* 01/29/18  5        AR        Fixed compilation issue                                                        EA4#19850
* 02/16/18  6        AR        Changes made for ES251A_BattRtnCurr integration                                EA4#19850
* 04/27/18  7        AR        CM020A update for QEP Primary, SPI Secondary MotAg Scheme integration          EA4#22691
* 05/18/18  8        AR        CM020A update for QEP Primary, SPI Secondary MotAg Scheme - DNF enabled        EA4#23989
* 06/01/18  9        AR        ADC read updates - read onces as UINT32 and spilt the value as needed          EA4#24385
**********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/************************************************ Include Statements *************************************************/
#include "CDD_Bmw5441McuCfg_Stub.h"
#include "Rte_CDD_Bmw5441McuCfg.h"
#include "CDD_Adc0CfgAndUse.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "pic_regs.h"
#include "adcd_regs.h"
#include "dnf_regs.h"
#include "sys_regs.h"
#include "Os.h"
/******************************************** File Level Rule Deviations *********************************************/

/********************************************* Embedded Local Constants **********************************************/

#define DNFINITWAITTI_CNT_U32                (uint32)12U
#define ADCCNVWAITTI_CNT_U32                (uint32)25U
#define BATTVLTGSWD1SCAGFAC_ULS_F32         3.3696682464454974F /* (1.0/0.2967651195499297) */
#define BATTVLTGSCAGFAC_ULS_F32             6.7471264367816104F /* (1.0/0.1482112436115843) */

#define SHIFTANDMASK16BIT_CNT_U16(x)         (((x)>> 16U) & 0xFFFFU)
#define MASK16BIT_CNT_U16(x)                 ((x) & 0xFFFFU)
/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************** Function Definitions ************************************************/

/**********************************************************************************************************************
 * Name:        Bmw5441McuCfgInit1
 * Description: Init1 Function
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: This function shall be called after Adc0CfgAndUseInit1 and Adc1CfgAndUseInit1.
 *********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit1(void)
{
    /* The register values used below are defined in design component for CM020A in the file: 
       CM020A_Bmw5441McuCfg_RegisterConfiguration.xlsm */
    PIC2BADCD0TSEL0 = 0x00000000U;
    PIC2BADCD0TSEL1 = 0x00000040U;
    PIC2BADCD0TSEL2 = 0x00000040U;
    PIC2BADCD0TSEL3 = 0x04000000U;
    PIC2BADCD0TSEL4 = 0x00000000U;
    PIC2BADCD0EDGSEL = 0x0000U;
    PIC2BADCD1TSEL0 = 0x00000000U;
    PIC2BADCD1TSEL1 = 0x00000080U;
    PIC2BADCD1TSEL2 = 0x00000080U;
    PIC2BADCD1TSEL3 = 0x00000080U;
    PIC2BADCD1TSEL4 = 0x00000000U;
    PIC2BADCD1EDGSEL = 0x0000U;
    PIC2BADTEN400 = 0x0000U;
    PIC2BADTEN401 = 0x0000U;
    PIC2BADTEN402 = 0x0000U;
    PIC2BADTEN403 = 0x0000U;
    PIC2BADTEN404 = 0x0000U;
    PIC2BADTEN410 = 0x0000U;
    PIC2BADTEN411 = 0x0000U;
    PIC2BADTEN412 = 0x0000U;
    PIC2BADTEN413 = 0x0000U;
    PIC2BADTEN414 = 0x0000U;
    PIC2BADSYNCTRG = 0x00U;
    return;
}

/**********************************************************************************************************************
  * Name:        Bmw5441McuCfgInit2
  * Description: Init2 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Shall be called after Bmw5441McuCfgInit1
  ********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit2(void)
{
    VAR(uint32, AUTOMATIC) StartTime_Cnt_T_u32;
    VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;

    Rte_Call_GetRefTmr1MicroSec32bit_Oper(&StartTime_Cnt_T_u32);

    do
    {
        Rte_Call_GetTiSpan1MicroSec32bit_Oper(StartTime_Cnt_T_u32, &ElapsedTime_Cnt_T_u32);
    }while( ElapsedTime_Cnt_T_u32 < ADCCNVWAITTI_CNT_U32 );

    Call_Adc0OutpInin();

    return;
}

/**********************************************************************************************************************
  * Name:        Bmw5441McuCfgInit3
  * Description: Init3 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Shall be called after Bmw5441McuCfgInit2
  ********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit3(void)
{
	uint32 ADCD1_DRxx_Cnt_T_u32;

    /* The init values used below are defined in design component for CM020A in the file: 
       CM020A_Bmw5441McuCfg_RegisterConfiguration.xlsm */

    /* ADCD1 DR00 */
	ADCD1_DRxx_Cnt_T_u32 = ADCD1.DR00.UINT32;	
    (void)Rte_Write_Adc1ScanGroup3Ref0_Val((float32)MASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_BattVltgSwd1_Val((float32)SHIFTANDMASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32) * BATTVLTGSWD1SCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);

    /* ADCD1 DR02 */
	ADCD1_DRxx_Cnt_T_u32 = ADCD1.DR02.UINT32;
    (void)Rte_Write_EcuT_Val((float32)MASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32)* 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1ScanGroup3Ref1_Val((float32)SHIFTANDMASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);

    /* ADCD1 DR04 */
	ADCD1_DRxx_Cnt_T_u32 = ADCD1.DR04.UINT32;
    (void)Rte_Write_Adc1ScanGroup2Ref0_Val((float32)MASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_RvsBattDiagcGndAdc_Val((float32)SHIFTANDMASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32)  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);

    /* ADCD1 DR06 */
	ADCD1_DRxx_Cnt_T_u32 = ADCD1.DR06.UINT32;
    (void)Rte_Write_RvsBattDiagcRtnAdc_Val((float32)MASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32)* 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1ScanGroup2Ref1_Val((float32)SHIFTANDMASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);

    /* Channels ADCD1.DR8 to ADCD1.DR18 not used */

    /* ADCD1 DR020 */
    (void)Rte_Write_Adc1SelfDiag0_Val((float32)ADCD1.DR20.BIT.DR21 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);

    /* ADCD1 DR022 */
	ADCD1_DRxx_Cnt_T_u32 = ADCD1.DR22.UINT32;
    (void)Rte_Write_Adc1SelfDiag2_Val((float32)MASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1SelfDiag4_Val((float32)SHIFTANDMASK16BIT_CNT_U16(ADCD1_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    
    return;
}


/**********************************************************************************************************************
  * Name:        Bmw5441McuCfgInit4
  * Description: Init4 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Initialize Digital Noise Filter Registers According to DigitalNoiseFilterConfig.xlsx.                 
  ********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgInit4(void)
{
	/*Input pin selection for ENCA0 and ENCA1 */
	PIC1AREG30      = 0x00000000U;
	/*Digital noise elimination enabled*/
	DNFA32NFENL0    = 0x1U;
	DNFA32NFENL1    = 0x1U;
	DNFA35NFENL0    = 0x1U;
	DNFA35NFENL1    = 0x1U; 
	/* Digital Noise Elimination Sampling Clock Source -  High-speed peripheral clock CLK_HSB */
	SYSDNFCKS112C   = 0x00000002U;
	/* Digital Noise Elimination Control Registers */
	DNFA20CTL       = 0x00U;
	DNFA21CTL       = 0x00U;
	DNFA23CTL       = 0x00U;
	/* Digital Noise Elimination Enable*/
	DNFA20EN     = 0x0001U;
	/* DELAY AT LEAST 12 CYCLES */
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	
	/* Digital Noise Elimination Enable*/
	DNFA21EN     = 0x0001U;
	/* DELAY AT LEAST 12 CYCLES */
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	/* Digital Noise Elimination Enable*/
	DNFA23EN     = 0x0001U;
	/* DELAY AT LEAST 12 CYCLES */
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	__asm("nop");
	return;
}

/**********************************************************************************************************************
  * Name:        Bmw5441McuCfgPer1
  * Description: Per1 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgPer1(void)
{
    /* The values used below are defined in design component for CM020A in the file: 
       CM020A_Bmw5441McuCfg_RegisterConfiguration.xlsm */

    MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref0 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[0]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcVlyA     = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[1]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcVlyB     = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[2]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcVlyC     = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[3]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref1 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[4]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref0 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[5]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcPeakA    = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[6]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcPeakB    = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[7]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcPeakC    = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[8]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrSnsrOffs1   = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[9]  * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlBattVltgAdc        = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[10] * BATTVLTGSCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlBattRtnCurrAdc     = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[11] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlHwTq4RawAdc        = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[12] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlHwTq5RawAdc        = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[13] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref1 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[14] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0SelfDiag0      = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[21] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0SelfDiag2      = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[22] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0SelfDiag4      = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[23] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;

    return;
}

/**********************************************************************************************************************
  * Name:        Bmw5441McuCfgPer2
  * Description: Per2 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgPer2(void)
{
    /* The values used below are defined in design component for CM020A in the file: 
       CM020A_Bmw5441McuCfg_RegisterConfiguration.xlsm */

    (void)Rte_Write_Adc1ScanGroup3Ref0_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[0] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_BattVltgSwd1_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[1] * BATTVLTGSWD1SCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_EcuT_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[2] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1ScanGroup3Ref1_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[3] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1ScanGroup2Ref0_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[4] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_RvsBattDiagcGndAdc_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[5] *  ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_RvsBattDiagcRtnAdc_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[6] *  ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1ScanGroup2Ref1_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[7] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1SelfDiag0_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[21] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1SelfDiag2_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[22] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
    (void)Rte_Write_Adc1SelfDiag4_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[23] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);

    return;
}

/**********************************************************************************************************************
  * Name:        Bmw5441McuCfgPer3
  * Description: Per3 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Bmw5441McuCfgPer3(void)
{
    /* The values used below are defined in design component for CM020A in the file: 
       CM020A_Bmw5441McuCfg_RegisterConfiguration.xlsm */

    VAR(boolean, AUTOMATIC) Adc0Faild_Cnt_T_logl;
    VAR(boolean, AUTOMATIC) Adc1Faild_Cnt_T_logl;

    (void)Rte_Read_Adc0Faild_Logl(&Adc0Faild_Cnt_T_logl);
    (void)Rte_Read_Adc1Faild_Logl(&Adc1Faild_Cnt_T_logl);

    /* ADC0 Diagnostics */
    (void)Rte_Write_MotCurrAdcVlyAAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_MotCurrAdcVlyBAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_MotCurrAdcVlyCAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_HwTq4RawAdcAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_HwTq5RawAdcAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    // <KJS> (void)Rte_Write_MotCurrAdcPeakAAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    // <KJS> (void)Rte_Write_MotCurrAdcPeakBAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    // <KJS> (void)Rte_Write_MotCurrAdcPeakCAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    // <KJS> (void)Rte_Write_MotCurrSnsrOffs1AdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_BattVltgAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_BattRtnCurrAdcFaild_Logl(Adc0Faild_Cnt_T_logl);

    /* ADC1 Diagnostics */
    (void)Rte_Write_BattVltgSwd1AdcFaild_Logl(Adc1Faild_Cnt_T_logl);
    (void)Rte_Write_EcuTAdcFaild_Logl(Adc1Faild_Cnt_T_logl);
    (void)Rte_Write_RvsBattDiagcGndAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_RvsBattDiagcRtnAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
    (void)Rte_Write_MotDrvr1IninTestCmpl_Logl(TRUE);
    
    return;
}

/**********************************************************************************************************************
  * Name:        Adc0OutpInin
  * Description: ADC 0 Output Initialization
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Called from Init1 above via trusted function call.
  ********************************************************************************************************************/
FUNC(void, CDD_Bmw5441McuCfg_CODE) Adc0OutpInin(void)
{
	
	uint32 ADCD0_DRxx_Cnt_T_u32;
	
    /* The init values used below are defined in design component for CM020A in the file: 
       CM020A_Bmw5441McuCfg_RegisterConfiguration.xlsm */
       
    /* ADCD0 DR00 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR00.UINT32;
    MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref0 = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcVlyA     = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR02 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR02.UINT32;
    MOTCTRLMGR_MotCtrlMotCurrAdcVlyB = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcVlyC = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR04 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR04.UINT32;
    MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref1 = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref0 = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR06 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR06.UINT32;
    MOTCTRLMGR_MotCtrlMotCurrAdcPeakA = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32)* 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrAdcPeakB = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32)* 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR08 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR08.UINT32;
    MOTCTRLMGR_MotCtrlMotCurrAdcPeakC  = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlMotCurrSnsrOffs1 = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR10 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR10.UINT32;
    MOTCTRLMGR_MotCtrlBattVltgAdc      = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * BATTVLTGSCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlBattRtnCurrAdc   = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32)* 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR12 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR12.UINT32;
    MOTCTRLMGR_MotCtrlHwTq4RawAdc = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32)* 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlHwTq5RawAdc = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR14 */
    MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref1 = (float32)ADCD0.DR14.BIT.DR14 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR20 */
    MOTCTRLMGR_MotCtrlAdc0SelfDiag0 = (float32)ADCD0.DR20.BIT.DR21 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    
    /* ADCD0 DR22 */
	ADCD0_DRxx_Cnt_T_u32 = ADCD0.DR22.UINT32;
    MOTCTRLMGR_MotCtrlAdc0SelfDiag2 = (float32)MASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32) * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
    MOTCTRLMGR_MotCtrlAdc0SelfDiag4 = (float32)SHIFTANDMASK16BIT_CNT_U16(ADCD0_DRxx_Cnt_T_u32)* 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;

    return;
}
