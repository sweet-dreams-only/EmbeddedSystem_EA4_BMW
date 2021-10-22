/**********************************************************************************************************************
 * Copyright 2016-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg1Meas_MotCtrl.c
 * Module Description: Motor Control Loop runnable(s) for Measurement function of Motor Angle 1.
 *                     This function includes configuration and use of the CSIH3 peripheral.
 * Project           : CBD
 * Author            : Avinash James
 **********************************************************************************************************************
 * Version Control:
 * %version:          9 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/07/16  1        AJM       Initial version                                                               EA4#5033
 * 12/13/17  3        ML        Updated to fix Anomaly EA4#18334                                              EA4#18492
 * 12/14/17  4        ML        Updated to replace MOTAG1OFFS_MOTREV_U0P16 with Calibration                   EA4#18556
 * 01/19/18  5        AJM       Updated the parity fault checks to mask upper 16 bits                         EA4#19628
 * 04/25/18  6        KByrski   Updated as per Design 5.0.0                                                   EA4#17185,EA4#18362,EA4#22024
 * 04/27/18  7        AJM       Modified the IO Hw function calls to remove compiler warning                  EA4#22024
 * 05/03/18  8        AJM       Added polarity correction and offset calculation                              EA4#23197
 * 05/15/18  9        KByrski   Updated as per Design 6.1.0 (no functional changes)                           EA4#23818
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotAg1Meas.h"
#include "CDD_MotAg1Meas_private.h"
#include "CDD_MotAg1Meas.h"
#include "CDD_MotAg1Meas_Cfg.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "CDD_MotAg4Meas.h"
#include "CDD_NxtrTi.h"
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.2]: Per Instance Memory pointers to array base types are cast back to their array type for code readability and to allow use of "sizeof". */
/* MISRA-C:2004 Rule 13.7 [NXTRDEV 13.7.1]: Allowed in cases of comparisons involving configuration parameters/configurable constants. */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define MOTCTRLMOTAG1WARNREGLOLIM_CNT_U32         ((uint32)0U)
#define MOTCTRLMOTAG1WARNREGHILIM_CNT_U32         ((uint32)67108863U) /* 0x03FFFFFFU */
#define MOTCTRLMOTAG1ERRREGLOLIM_CNT_U32          ((uint32)0U)
#define MOTCTRLMOTAG1ERRREGHILIM_CNT_U32          ((uint32)67108863U) /* 0x03FFFFFFU */
#define MOTCTRLMOTAG1TURNCNTRREGLOLIM_CNT_U32     ((uint32)0U)
#define MOTCTRLMOTAG1TURNCNTRREGHILIM_CNT_U32     ((uint32)67108863U) /* 0x03FFFFFFU */

/******************************************** Local Function Prototypes **********************************************/
static FUNC(void, CDD_MotAg1Meas_CODE) SPI_AngleRawProcess(
        VAR(uint32, AUTOMATIC) RawAngReg_Cnt_T_u32);

static FUNC(u0p16, CDD_MotAg1Meas_CODE) CompensateMechMtrPos(
        VAR(u0p16, AUTOMATIC) MotAgRawMecl_MotRev_T_u0p16);


#define CDD_MotAg1Meas_MotCtrl_START_SEC_CODE
#include "CDD_MotAg1Meas_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        MotAg1MeasPer1
 * Description: MotAg1Meas component periodic processing in the motor control loop
 * Inputs:      MotCtrlMotAg1Offs
 *              MotCtrlMotAg1QepFaild
 *              MotCtrlMotAg1RawRes
 *              MotCtrlMotAgMecl0Polarity
 * Outputs:     MotCtrlMotAg1ErrReg
 *              MotCtrlMotAg1Mecl
 *              MotCtrlMotAg1MeclRollgCntr
 *              MotCtrlMotAg1ParFltCnt
 *              MotCtrlMotAg1SpiMecl
 *              MotCtrlMotAg1TurnCntrReg
 *              MotCtrlMotAg1VltgFltCnt
 *              MotCtrlMotAg1WarnReg
 *              MotCtrlMotAg4Mecl
 *              MotCtrlMotAgMeasTi
 * Usage Notes: Called at Motor Control loop rate
 *********************************************************************************************************************/
FUNC (void, CDD_MotAg1Meas_CODE) MotAg1MeasPer1(void)
{
    /* Temporary variables */
    VAR(uint32, AUTOMATIC) RawAgReg_Cnt_T_u32;
    VAR(uint16, AUTOMATIC) MotCtrlMotAg1Mecl_MotRev_T_u0p16;
    VAR(sint32, AUTOMATIC) MotAgSpiMecl_MotRev_T_s32;
    VAR(u0p16,  AUTOMATIC) MotAgSpiMecl_MotRev_T_u0p16;
    VAR(u0p16,  AUTOMATIC) MotAgPolarityAdj_MotRev_T_u0p16;
    VAR(u0p16,  AUTOMATIC) MotAgMecl_MotRev_T_u0p16 = 0U;

    GetMotAg4Mecl_Oper(&MotAgMecl_MotRev_T_u0p16);

    /* Read inputs */
    RawAgReg_Cnt_T_u32 = MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWAGREGIDX_CNT_U08];

    /* Update the display variables */
    *Rte_Pim_dMotAg1MeasMotAg1RawStsReg()      = MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWERRSTSIDX_CNT_U08];
    *Rte_Pim_dMotAg1MeasMotAg1RawWarnReg()     = MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWERRWARNIDX_CNT_U08];
    *Rte_Pim_dMotAg1MeasMotAg1RawErrReg()      = MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWERRREGIDX_CNT_U08];
    *Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg() = MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWTURNCNTRREGIDX_CNT_U08];
    *Rte_Pim_dMotAg1MeasMotAg1RawAgReg()       = MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWAGREGIDX_CNT_U08];

    /* SPI_AngleRawProcess */
    SPI_AngleRawProcess(RawAgReg_Cnt_T_u32);

    /* SPI_AnglePolarityAdjust */
    if (*Rte_Pim_MotAgMecl1Polarity() < 0)
    {
        MotAgSpiMecl_MotRev_T_s32 = MOTAGLIMMASK_CNT_S32 - (sint32) *Rte_Pim_MotAg1RawMeclPrev();
        MotAgSpiMecl_MotRev_T_u0p16 = (u0p16) MotAgSpiMecl_MotRev_T_s32;
    }
    else
    {
        MotAgSpiMecl_MotRev_T_u0p16 = *Rte_Pim_MotAg1RawMeclPrev();
    }

    MotAgPolarityAdj_MotRev_T_u0p16 = MotAgSpiMecl_MotRev_T_u0p16;

    /* Offset Calculation */
    if(*Rte_Pim_MotAg1InitOffsCntr() >= MOTAGOFFSENAMASK_CNT_U08)
    {
        *Rte_Pim_dMotAg1MeasMotAg1RtOffs() = (sint32) MotAgMecl_MotRev_T_u0p16 - (sint32) MotAgSpiMecl_MotRev_T_u0p16;
    }
    else
    {
        *Rte_Pim_MotAg1InitOffs() = (sint32) MotAgMecl_MotRev_T_u0p16 - (sint32) MotAgSpiMecl_MotRev_T_u0p16;
        *Rte_Pim_MotAg1InitOffsCntr() += 1U;
    }
    /* End of Offset Calculation */

    if ((MOTAG1MEAS_DIQEPIF_CNT_LOGL != FALSE) || (MOTCTRLMGR_MotCtrlMotAg1QepFaild != FALSE))
    {
        /* Do nothing */
    }
    else
    {
        /* QEP_AngleRawProcess */
        MotAgSpiMecl_MotRev_T_s32 = ((sint32) MotAgMecl_MotRev_T_u0p16) - *Rte_Pim_MotAg1InitOffs();
        MotAgSpiMecl_MotRev_T_u0p16 = (u0p16) MotAgSpiMecl_MotRev_T_s32;
    }

    /* Compensate MechMtrPos */
    MotCtrlMotAg1Mecl_MotRev_T_u0p16 = CompensateMechMtrPos(MotAgSpiMecl_MotRev_T_u0p16);

    /* Write outputs */
    MOTCTRLMGR_MotCtrlMotAg4Mecl            = MotAgMecl_MotRev_T_u0p16;
    MOTCTRLMGR_MotCtrlMotAg1Mecl            = MotCtrlMotAg1Mecl_MotRev_T_u0p16;
    MOTCTRLMGR_MotCtrlMotAg1SpiMecl         = MotAgPolarityAdj_MotRev_T_u0p16;
    MOTCTRLMGR_MotCtrlMotAg1MeclRollgCntr   = *Rte_Pim_MotAg1MeclRollgCntrPrev();
    MOTCTRLMGR_MotCtrlMotAg1ParFltCnt       = *Rte_Pim_MotAg1ParFltCntPrev();
    MOTCTRLMGR_MotCtrlMotAg1VltgFltCnt      = *Rte_Pim_MotAg1VltgFltCntPrev();

    MOTCTRLMGR_MotCtrlMotAg1WarnReg =  Lim_u32(
            MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWERRWARNIDX_CNT_U08],
            MOTCTRLMOTAG1WARNREGLOLIM_CNT_U32,
            MOTCTRLMOTAG1WARNREGHILIM_CNT_U32);

    MOTCTRLMGR_MotCtrlMotAg1ErrReg = Lim_u32(
            MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWERRREGIDX_CNT_U08],
            MOTCTRLMOTAG1ERRREGLOLIM_CNT_U32,
            MOTCTRLMOTAG1ERRREGHILIM_CNT_U32);

    MOTCTRLMGR_MotCtrlMotAg1TurnCntrReg = Lim_u32(
            MOTCTRLMGR_MotCtrlMotAg1RawRes[RAWTURNCNTRREGIDX_CNT_U08],
            MOTCTRLMOTAG1TURNCNTRREGLOLIM_CNT_U32,
            MOTCTRLMOTAG1TURNCNTRREGHILIM_CNT_U32);
}

/**********************************************************************************************************************
 * Name:        MotAg1CfgLoPwrMod
 * Description: Configure SPI (CSIH peripheral) signals to low state.
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: NonRte Server Runnable
 *********************************************************************************************************************/
FUNC (void, CDD_MotAg1Meas_CODE) MotAg1CfgLoPwrMod(void)
{
    VAR(uint32, AUTOMATIC) RefTmrCnt_Cnt_T_u32 = 0U;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32 = 0U;

    /* IOConfiguration */
    (void) Rte_Call_IoHwAb_SetGpioMotAg1Mosi_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetFctGpioMotAg1Mosi_Oper();
    (void) Rte_Call_IoHwAb_SetGpioMotAg1Clk_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetFctGpioMotAg1Clk_Oper();
    (void) Rte_Call_IoHwAb_SetGpioMotAg1Cs_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetFctGpioMotAg1Cs_Oper();

    /* WaitInLoop */
    GetRefTmr1MicroSec32bit_Oper(&RefTmrCnt_Cnt_T_u32);

    /* WaitUntilTimeout */
    do
    {
        GetTiSpan1MicroSec32bit_Oper(RefTmrCnt_Cnt_T_u32, &TiSpan_Cnt_T_u32);
    } while (TiSpan_Cnt_T_u32 < MOTAG1SLEEPWAIT_MICROSEC_U32);
}


/************************************************** Local Functions **************************************************/


/**********************************************************************************************************************
 * Name:        SPI_AngleRawProcess
 * Description: Implementation of "SPI_AngleRawProcess" Simulink block
 * Inputs:      RawAngReg_Cnt_T_u32
 * Outputs:     Rte_Pim_MotAg1VltgFltCntPrev
 *              Rte_Pim_MotAg1ParFltCntPrev
 *              Rte_Pim_MotAg1MeclRollgCntrPrev
 *              Rte_Pim_MotAg1RawMeclPrev
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, CDD_MotAg1Meas_CODE) SPI_AngleRawProcess(
        VAR(uint32, AUTOMATIC) RawAngReg_Cnt_T_u32)
{
    VAR(uint32, AUTOMATIC) OddParity_Cnt_T_u32;
    VAR(boolean,  AUTOMATIC) MotAgVltgFlt_Cnt_T_logl;
    VAR(uint8,  AUTOMATIC) MotAgParFlt_Cnt_T_u08;
    VAR(boolean,  AUTOMATIC) MotAgParFlt_Cnt_T_logl;

    if ((RawAngReg_Cnt_T_u32 & SNSRVLTGFLTMASK_CNT_U32) != 0U)
    {
        MotAgVltgFlt_Cnt_T_logl = TRUE;

        /* VltgFlt_FltCnt_u16 */
        (*Rte_Pim_MotAg1VltgFltCntPrev())++;
    }
    else
    {
        MotAgVltgFlt_Cnt_T_logl = FALSE;
    }

    /* OddParCalcn */
    OddParity_Cnt_T_u32 = RawAngReg_Cnt_T_u32;
    OddParity_Cnt_T_u32 ^= (OddParity_Cnt_T_u32 >> 1U);
    OddParity_Cnt_T_u32 ^= (OddParity_Cnt_T_u32 >> 2U);
    OddParity_Cnt_T_u32 &= ODDPARCALCNMASK_CNT_U32;
    OddParity_Cnt_T_u32 *= ODDPARCALCNMASK_CNT_U32;
    OddParity_Cnt_T_u32 = (OddParity_Cnt_T_u32 >> 12U);
    OddParity_Cnt_T_u32 &= 0x01U;

    MotAgParFlt_Cnt_T_u08 = (OddParity_Cnt_T_u32 == 0U) ? 1U : 0U;

    if (MotAgParFlt_Cnt_T_u08 == 0U)
    {
        MotAgParFlt_Cnt_T_logl = FALSE;
    }
    else
    {
        MotAgParFlt_Cnt_T_logl = TRUE;

        /* ParFlt_FltCnt_u16 */
        (*Rte_Pim_MotAg1ParFltCntPrev())++;
    }

    if ((MotAgVltgFlt_Cnt_T_logl == FALSE) && (MotAgParFlt_Cnt_T_logl == FALSE))
    {
        /* PassThroughTrue */
        *Rte_Pim_MotAg1RawMeclPrev() = (u0p16) ((RawAngReg_Cnt_T_u32 & SNSRAGMASK_CNT_U32) << 4U);

        /* MotCtrlMotAg1Flt_RollgCnt_u08 */
        (*Rte_Pim_MotAg1MeclRollgCntrPrev())++;
    }
}

/**********************************************************************************************************************
 * Name:        CompensateMechMtrPos
 * Description: Implementation of "Compensate MechMtrPos" Simulink block
 * Inputs:      MotAgRawMecl_MotRev_T_u0p16
 * Outputs:     MotAgMecl_MotRev_T_u0p16
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(u0p16, CDD_MotAg1Meas_CODE) CompensateMechMtrPos(
        VAR(u0p16, AUTOMATIC) MotAgRawMecl_MotRev_T_u0p16)
{
    VAR(sint8,  AUTOMATIC) MotAg1CorrnA_MotRev_T_sm5p12;
    VAR(sint8,  AUTOMATIC) MotAg1CorrnB_MotRev_T_sm5p12;
    VAR(sint32, AUTOMATIC) MotAg1CorrnA_MotRev_T_s19p12;
    VAR(sint32, AUTOMATIC) MotAg1CorrnB_MotRev_T_s19p12;
    VAR(uint16, AUTOMATIC) MotAg1Gain_Uls_T_u12p4;
    VAR(sint32, AUTOMATIC) MotAg1CorrnTerm_MotRev_T_s15p16;
    VAR(sint32, AUTOMATIC) MotAgCmp_MotRev_T_s32;
    VAR(uint16, AUTOMATIC) MotAgMecl_MotRev_T_u0p16;

    /* Masking is redundant, but used to match the design */
    MotAg1CorrnA_MotRev_T_sm5p12 = PimMotAg1CorrnTbl[(MotAgRawMecl_MotRev_T_u0p16 >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
    MotAg1CorrnA_MotRev_T_s19p12 = (sint32) MotAg1CorrnA_MotRev_T_sm5p12;
    MotAg1CorrnB_MotRev_T_sm5p12 = PimMotAg1CorrnTbl[((MotAgRawMecl_MotRev_T_u0p16 + MOTAGDELTAPERCORRNPT_CNT_U16) >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
    MotAg1CorrnB_MotRev_T_s19p12 = (sint32) MotAg1CorrnB_MotRev_T_sm5p12;
    MotAg1Gain_Uls_T_u12p4 = (uint16) ((MotAgRawMecl_MotRev_T_u0p16 - (MotAgRawMecl_MotRev_T_u0p16 & MOTAGIDXMASK_CNT_U16)) >> 5U);

    MotAg1CorrnTerm_MotRev_T_s15p16 =
            ((MotAg1CorrnB_MotRev_T_s19p12 - MotAg1CorrnA_MotRev_T_s19p12) * (sint32) MotAg1Gain_Uls_T_u12p4) +
            (sint32) (uint32) ((uint32) MotAg1CorrnA_MotRev_T_s19p12 << 4U);

    /* Roll-over and typecasting from sign to unsigned is intentional here to implement part of the 'Normalize MechMtrPos' block */
    MotAgCmp_MotRev_T_s32 = ((sint32) MotAgRawMecl_MotRev_T_u0p16) - ((sint32) MotAg1CorrnTerm_MotRev_T_s15p16);
    MotAgCmp_MotRev_T_s32 -= (sint32) Rte_Prm_MotAg1MeasOffs_Val();

    /* Normalization */
    MotAgMecl_MotRev_T_u0p16 = (u0p16) MotAgCmp_MotRev_T_s32;

    return MotAgMecl_MotRev_T_u0p16;
}
	
#define CDD_MotAg1Meas_MotCtrl_STOP_SEC_CODE
#include "CDD_MotAg1Meas_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
