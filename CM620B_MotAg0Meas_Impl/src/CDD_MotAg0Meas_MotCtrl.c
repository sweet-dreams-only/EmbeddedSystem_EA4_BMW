/**********************************************************************************************************************
 * Copyright 2016-2018 Nxtr
 * Nxtr Confidential
 *
 * Module File Name  : CDD_MotAg0Meas_MotCtrl.c
 * Module Description: Motor Control Loop runnable(s) for Measurement function of Motor Angle 0.
 *                     This function includes configuration and use of the CSIH1 peripheral.
 * Project           : CBD
 * Author            : Avinash James
 **********************************************************************************************************************
 * Version Control:
 * %version:          8 %
 * %derived_by:       nz2999 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                             SCR #
 * --------  -------  --------  ----------------------------------------------------------------------------  ---------
 * 06/07/16  1        AJM       Initial Version                                                               EA4#5027
 * 09/07/17  2        KByrski   Updated as per Design 2.0.0                                                   EA4#13291
 * 12/13/17  3        AJM       Code model mismatch fix for anomaly fix EA4#18334                             EA4#18489
 * 01/19/18  4        AJM       Updated the parity fault checks to mask the upper 16 bits                     EA4#19623
 * 04/25/18  5        KByrski   Updated as per Design 5.0.0                                                   EA4#15121,EA4#18232,EA4#22026
 * 04/27/18  6        AJM       Modified the IO Hw function calls to remove compiler warning                  EA4#22026
 * 05/03/18  7        AJM       Added polarity correction and offset calculation                              EA4#23192
 * 05/15/17  8        KByrski   Updated as per Design 6.1.0 (no functional changes)                           EA4#23813
 *********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotAg0Meas.h"
#include "CDD_MotAg0Meas_private.h"
#include "CDD_MotAg0Meas.h"
#include "CDD_MotAg0Meas_Cfg.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "CDD_MotAg3Meas.h"
#include "CDD_NxtrTi.h"
#include "FltInj.h"
#include "NxtrMath.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.2]: Per Instance Memory pointers to array base types are cast back to their array type for code readability and to allow use of "sizeof". */
/* MISRA-C:2004 Rule 13.7 [NXTRDEV 13.7.1]: Allowed in cases of comparisons involving configuration parameters/configurable constants. */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

/********************************************* Embedded Local Constants **********************************************/
#define MOTCTRLMOTAG0WARNREGLOLIM_CNT_U32         ((uint32)0U)
#define MOTCTRLMOTAG0WARNREGHILIM_CNT_U32         ((uint32)67108863U) /* 0x03FFFFFFU */
#define MOTCTRLMOTAG0ERRREGLOLIM_CNT_U32          ((uint32)0U)
#define MOTCTRLMOTAG0ERRREGHILIM_CNT_U32          ((uint32)67108863U) /* 0x03FFFFFFU */
#define MOTCTRLMOTAG0TURNCNTRREGLOLIM_CNT_U32     ((uint32)0U)
#define MOTCTRLMOTAG0TURNCNTRREGHILIM_CNT_U32     ((uint32)67108863U) /* 0x03FFFFFFU */

/******************************************** Local Function Prototypes **********************************************/
static FUNC(void, CDD_MotAg0Meas_CODE) SPI_AngleRawProcess(
        VAR(uint32, AUTOMATIC) RawAngReg_Cnt_T_u32);

static FUNC(u0p16, CDD_MotAg0Meas_CODE) CompensateMechMtrPos(
        VAR(u0p16, AUTOMATIC) MotAgRawMecl_MotRev_T_u0p16);


#define CDD_MotAg0Meas_MotCtrl_START_SEC_CODE
#include "CDD_MotAg0Meas_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Name:        MotAg0MeasPer1
 * Description: MotAg0Meas component periodic processing in the motor control loop
 * Inputs:      MotCtrlMotAg0Offs
 *              MotCtrlMotAg0QepFaild
 *              MotCtrlMotAg0RawRes
 *              MotCtrlMotAgMecl0Polarity
 * Outputs:     MotCtrlMotAg0ErrReg
 *              MotCtrlMotAg0Mecl
 *              MotCtrlMotAg0MeclRollgCntr
 *              MotCtrlMotAg0ParFltCnt
 *              MotCtrlMotAg0SpiMecl
 *              MotCtrlMotAg0TurnCntrReg
 *              MotCtrlMotAg0VltgFltCnt
 *              MotCtrlMotAg0WarnReg
 *              MotCtrlMotAg3Mecl
 *              MotCtrlMotAgMeasTi
 * Usage Notes: Called at Motor Control loop rate
 *********************************************************************************************************************/
FUNC (void, CDD_MotAg0Meas_CODE) MotAg0MeasPer1(void)
{
    /* Temporary variables */
    VAR(uint32, AUTOMATIC) RefTmr_Cnt_T_u32 = 0U;
    VAR(uint32, AUTOMATIC) RawAgReg_Cnt_T_u32;
    VAR(uint16, AUTOMATIC) MotCtrlMotAg0Mecl_MotRev_T_u0p16;
    VAR(sint32, AUTOMATIC) MotAgSpiMecl_MotRev_T_s32;
    VAR(u0p16,  AUTOMATIC) MotAgSpiMecl_MotRev_T_u0p16;
    VAR(u0p16,  AUTOMATIC) MotAgPolarityAdj_MotRev_T_u0p16;
    VAR(u0p16,  AUTOMATIC) MotAgMecl_MotRev_T_u0p16 = 0U;

    GetRefTmr1MicroSec32bit_Oper(&RefTmr_Cnt_T_u32);
    GetMotAg3Mecl_Oper(&MotAgMecl_MotRev_T_u0p16);

    /* Read inputs */
    RawAgReg_Cnt_T_u32 = MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWAGREGIDX_CNT_U08];

    /* Update the display variables */
    *Rte_Pim_dMotAg0MeasMotAg0RawStsReg()      = MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWERRSTSIDX_CNT_U08];
    *Rte_Pim_dMotAg0MeasMotAg0RawWarnReg()     = MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWERRWARNIDX_CNT_U08];
    *Rte_Pim_dMotAg0MeasMotAg0RawErrReg()      = MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWERRREGIDX_CNT_U08];
    *Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg() = MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWTURNCNTRREGIDX_CNT_U08];
    *Rte_Pim_dMotAg0MeasMotAg0RawAgReg()       = MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWAGREGIDX_CNT_U08];

    /* SPI_AngleRawProcess */
    SPI_AngleRawProcess(RawAgReg_Cnt_T_u32);

    /* SPI_AnglePolarityAdjust */
    if (*Rte_Pim_MotAgMecl0Polarity() < 0)
    {
        MotAgSpiMecl_MotRev_T_s32 = MOTAGLIMMASK_CNT_S32 - (sint32) *Rte_Pim_MotAg0RawMeclPrev();
        MotAgSpiMecl_MotRev_T_u0p16 = (u0p16) MotAgSpiMecl_MotRev_T_s32;
    }
    else
    {
        MotAgSpiMecl_MotRev_T_u0p16 = *Rte_Pim_MotAg0RawMeclPrev();
    }

    MotAgPolarityAdj_MotRev_T_u0p16 = MotAgSpiMecl_MotRev_T_u0p16;

    /* Offset Calculation */
    if (*Rte_Pim_MotAg0InitOffsCntr() >= MOTAGOFFSENAMASK_CNT_U08)
    {
        *Rte_Pim_dMotAg0MeasMotAg0RtOffs() = (sint32) MotAgMecl_MotRev_T_u0p16 - (sint32) MotAgSpiMecl_MotRev_T_u0p16;
    }
    else
    {
        *Rte_Pim_MotAg0InitOffs() = (sint32) MotAgMecl_MotRev_T_u0p16 - (sint32) MotAgSpiMecl_MotRev_T_u0p16;
        *Rte_Pim_MotAg0InitOffsCntr() += 1U;
    }
    /* End of Offset Calculation */

    if ((MOTAG0MEAS_DIQEPIF_CNT_LOGL != FALSE) || (MOTCTRLMGR_MotCtrlMotAg0QepFaild != FALSE))
    {
        /* Do nothing */
    }
    else
    {
        /* QEP_AngleRawProcess */
        MotAgSpiMecl_MotRev_T_s32 = ((sint32) MotAgMecl_MotRev_T_u0p16) - *Rte_Pim_MotAg0InitOffs();
        MotAgSpiMecl_MotRev_T_u0p16 = (u0p16) MotAgSpiMecl_MotRev_T_s32;
    }

    /* Compensate MechMtrPos */
    MotCtrlMotAg0Mecl_MotRev_T_u0p16 = CompensateMechMtrPos(MotAgSpiMecl_MotRev_T_u0p16);

#if (FLTINJENA == STD_ON)
    (void) FltInj_u0p16_Oper(&MotCtrlMotAg0Mecl_MotRev_T_u0p16, FLTINJ_MOTAG0MEAS_MOTCTRLMOTAG0MECL);
#endif

    /* Write outputs */
    MOTCTRLMGR_MotCtrlMotAgMeasTi           = RefTmr_Cnt_T_u32;
    MOTCTRLMGR_MotCtrlMotAg3Mecl            = MotAgMecl_MotRev_T_u0p16;
    MOTCTRLMGR_MotCtrlMotAg0Mecl            = MotCtrlMotAg0Mecl_MotRev_T_u0p16;
    MOTCTRLMGR_MotCtrlMotAg0SpiMecl         = MotAgPolarityAdj_MotRev_T_u0p16;
    MOTCTRLMGR_MotCtrlMotAg0MeclRollgCntr   = *Rte_Pim_MotAg0MeclRollgCntrPrev();
    MOTCTRLMGR_MotCtrlMotAg0ParFltCnt       = *Rte_Pim_MotAg0ParFltCntPrev();
    MOTCTRLMGR_MotCtrlMotAg0VltgFltCnt      = *Rte_Pim_MotAg0VltgFltCntPrev();

    MOTCTRLMGR_MotCtrlMotAg0WarnReg =  Lim_u32(
            MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWERRWARNIDX_CNT_U08],
            MOTCTRLMOTAG0WARNREGLOLIM_CNT_U32,
            MOTCTRLMOTAG0WARNREGHILIM_CNT_U32);

    MOTCTRLMGR_MotCtrlMotAg0ErrReg = Lim_u32(
            MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWERRREGIDX_CNT_U08],
            MOTCTRLMOTAG0ERRREGLOLIM_CNT_U32,
            MOTCTRLMOTAG0ERRREGHILIM_CNT_U32);

    MOTCTRLMGR_MotCtrlMotAg0TurnCntrReg = Lim_u32(
            MOTCTRLMGR_MotCtrlMotAg0RawRes[RAWTURNCNTRREGIDX_CNT_U08],
            MOTCTRLMOTAG0TURNCNTRREGLOLIM_CNT_U32,
            MOTCTRLMOTAG0TURNCNTRREGHILIM_CNT_U32);
}

/**********************************************************************************************************************
 * Name:        MotAg0CfgLoPwrMod
 * Description: Configure SPI (CSIH peripheral) signals to low state.
 * Inputs:      NONE
 * Outputs:     NONE
 * Usage Notes: NonRte Server Runnable
 *********************************************************************************************************************/
FUNC (void, CDD_MotAg0Meas_CODE) MotAg0CfgLoPwrMod(void)
{
    VAR(uint32, AUTOMATIC) RefTmrCnt_Cnt_T_u32 = 0U;
    VAR(uint32, AUTOMATIC) TiSpan_Cnt_T_u32 = 0U;

    /* IOConfiguration */
    /* The function calls are the ones generated by the RTE which just #defines it to the IO functions */
    (void) Rte_Call_IoHwAb_SetGpioMotAg0Mosi_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetFctGpioMotAg0Mosi_Oper();
    (void) Rte_Call_IoHwAb_SetGpioMotAg0Clk_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetFctGpioMotAg0Clk_Oper();
    (void) Rte_Call_IoHwAb_SetGpioMotAg0Cs_Oper(STD_LOW);
    (void) Rte_Call_IoHwAb_SetFctGpioMotAg0Cs_Oper();

    /* WaitInLoop */
    GetRefTmr1MicroSec32bit_Oper(&RefTmrCnt_Cnt_T_u32);

    /* WaitUntilTimeout */
    do
    {
        GetTiSpan1MicroSec32bit_Oper(RefTmrCnt_Cnt_T_u32, &TiSpan_Cnt_T_u32);
    } while (TiSpan_Cnt_T_u32 < MOTAG0SLEEPWAIT_MICROSEC_U32);
}


/************************************************** Local Functions **************************************************/


/**********************************************************************************************************************
 * Name:        SPI_AngleRawProcess
 * Description: Implementation of "SPI_AngleRawProcess" Simulink block
 * Inputs:      RawAngReg_Cnt_T_u32
 * Outputs:     Rte_Pim_MotAg0VltgFltCntPrev
 *              Rte_Pim_MotAg0ParFltCntPrev
 *              Rte_Pim_MotAg0MeclRollgCntrPrev
 *              Rte_Pim_MotAg0RawMeclPrev
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(void, CDD_MotAg0Meas_CODE) SPI_AngleRawProcess(
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
        (*Rte_Pim_MotAg0VltgFltCntPrev())++;
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

#if (FLTINJENA == STD_ON)
    (void) FltInj_u08_Oper(&MotAgParFlt_Cnt_T_u08, FLTINJ_MOTAG0MEAS_TESTOK);
#endif

    if (MotAgParFlt_Cnt_T_u08 == 0U)
    {
        MotAgParFlt_Cnt_T_logl = FALSE;
    }
    else
    {
        MotAgParFlt_Cnt_T_logl = TRUE;

        /* ParFlt_FltCnt_u16 */
        (*Rte_Pim_MotAg0ParFltCntPrev())++;
    }

    if ((MotAgVltgFlt_Cnt_T_logl == FALSE) && (MotAgParFlt_Cnt_T_logl == FALSE))
    {
        /* PassThroughTrue */
        *Rte_Pim_MotAg0RawMeclPrev() = (u0p16) ((RawAngReg_Cnt_T_u32 & SNSRAGMASK_CNT_U32) << 4U);

        /* MotCtrlMotAg0Flt_RollgCnt_u08 */
        (*Rte_Pim_MotAg0MeclRollgCntrPrev())++;
    }
}

/**********************************************************************************************************************
 * Name:        CompensateMechMtrPos
 * Description: Implementation of "Compensate MechMtrPos" Simulink block
 * Inputs:      MotAgRawMecl_MotRev_T_u0p16
 * Outputs:     MotAgMecl_MotRev_T_u0p16
 * Usage Notes: NONE
 *********************************************************************************************************************/
static FUNC(u0p16, CDD_MotAg0Meas_CODE) CompensateMechMtrPos(
        VAR(u0p16, AUTOMATIC) MotAgRawMecl_MotRev_T_u0p16)
{
    VAR(sint8,  AUTOMATIC) MotAg0CorrnA_MotRev_T_sm5p12;
    VAR(sint8,  AUTOMATIC) MotAg0CorrnB_MotRev_T_sm5p12;
    VAR(sint32, AUTOMATIC) MotAg0CorrnA_MotRev_T_s19p12;
    VAR(sint32, AUTOMATIC) MotAg0CorrnB_MotRev_T_s19p12;
    VAR(uint16, AUTOMATIC) MotAg0Gain_Uls_T_u12p4;
    VAR(sint32, AUTOMATIC) MotAg0CorrnTerm_MotRev_T_s15p16;
    VAR(sint32, AUTOMATIC) MotAgCmp_MotRev_T_s32;
    VAR(uint16, AUTOMATIC) MotAgMecl_MotRev_T_u0p16;

    /* Masking is redundant, but used to match the design */
    MotAg0CorrnA_MotRev_T_sm5p12 = PimMotAg0CorrnTbl[(MotAgRawMecl_MotRev_T_u0p16 >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
    MotAg0CorrnA_MotRev_T_s19p12 = (sint32) MotAg0CorrnA_MotRev_T_sm5p12;
    MotAg0CorrnB_MotRev_T_sm5p12 = PimMotAg0CorrnTbl[((MotAgRawMecl_MotRev_T_u0p16 + MOTAGDELTAPERCORRNPT_CNT_U16) >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
    MotAg0CorrnB_MotRev_T_s19p12 = (sint32) MotAg0CorrnB_MotRev_T_sm5p12;
    MotAg0Gain_Uls_T_u12p4 = (uint16) ((MotAgRawMecl_MotRev_T_u0p16 - (MotAgRawMecl_MotRev_T_u0p16 & MOTAGIDXMASK_CNT_U16)) >> 5U);

    MotAg0CorrnTerm_MotRev_T_s15p16 =
            ((MotAg0CorrnB_MotRev_T_s19p12 - MotAg0CorrnA_MotRev_T_s19p12) * (sint32) MotAg0Gain_Uls_T_u12p4) +
            (sint32) (uint32) ((uint32) MotAg0CorrnA_MotRev_T_s19p12 << 4U);

    /* Roll-over and typecasting from sign to unsigned is intentional here to implement part of the 'Normalize MechMtrPos' block */
    MotAgCmp_MotRev_T_s32 = ((sint32) MotAgRawMecl_MotRev_T_u0p16) - ((sint32) MotAg0CorrnTerm_MotRev_T_s15p16);

    /* Normalization */
    MotAgMecl_MotRev_T_u0p16 = (u0p16) MotAgCmp_MotRev_T_s32;

    return MotAgMecl_MotRev_T_u0p16;
}


#define CDD_MotAg0Meas_MotCtrl_STOP_SEC_CODE
#include "CDD_MotAg0Meas_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
