/*****************************************************************************
* Copyright 2015, 2018 Nxtr 
* Nxtr Confidential
*
* Module File Name: CDD_TSG31CfgAndUse_MotCtrl.c
* Module Description: Motor Control Loop runnable(s) for configuration and 
*                     use of the TSG31 timer peripheral
* Project           : CBD   
* Author            : Kathleen Creager
*****************************************************************************
* Version Control:
* %version:          4 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/23/15  1        KMC        Initial version                                                                EA4#337
* 06/20/15  2        KMC        changed CnvNanoSecToHalfTmrCnt() to CnvNanoSecToTmrCnt() and added             EA4#865
*                               masking per FDD 1.3.0
* 01/19/18  3        AJM        Added missed update counter diagnostic                                         EA4#14408
* 03/27/18  4        AJM        Added limiting of the Phase A,B and C On time                                  EA4#20019
******************************************************************************/

#include "Rte_CDD_TSG31CfgAndUse.h"
#include "CDD_TSG31CfgAndUse.h"
#include "CDD_TSG31CfgAndUse_private.h"
#include "tsg3_regs.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "NxtrMath.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 1.1  [NXTRDEV 1.1.2]: Inline functions are used for functions called from Motor Control ISR to allow for throughput optimization */

#define MISSUPDININCON_CNT_U08      ((uint8)100U)
#define MISSUPDCNTRTHD_CNT_U16      ((uint16)960U)


static inline FUNC (void, CDD_TSG31CfgAndUse_CODE) MissUpdtCntrDiagc (void);

#define CDD_TSG31CfgAndUse_MotCtrl_START_SEC_CODE
#include "CDD_TSG31CfgAndUse_MotCtrl_MemMap.h" 

/******************************************************************************
  * Name:        TSG31CfgAndUsePer1
  * Description: TSG31CfgAndUse periodic processing in the motor control loop
  * Inputs:      see component's DataDict.m file     
  * Outputs:     see component's DataDict.m file 
  * Usage Notes: Called at Motor Control loop rate 
  ****************************************************************************/
FUNC (void, CDD_TSG31CfgAndUse_CODE) TSG31CfgAndUsePer1 (void)
{
    /* CM475A_TSG31CfgAndUse/TSG31CfgAndUse/TSG31CfgAndUsePer1 */
    
    VAR (uint32, AUTOMATIC) PhaOnTiA_NanoSec_T_u32;
    VAR (uint32, AUTOMATIC) PhaOnTiB_NanoSec_T_u32;
    VAR (uint32, AUTOMATIC) PhaOnTiC_NanoSec_T_u32;
    VAR (uint32, AUTOMATIC) PwmPerd_NanoSec_T_u32;
    VAR (MotCurrEolCalSt2, AUTOMATIC) MotCurrEolCalSt_T_enum;
    VAR (uint32, AUTOMATIC) PwmPerd_Cnt_T_u32;
    VAR (boolean, AUTOMATIC) MotCtrlPhaDiscnctDiagcActv_Cnt_T_logl;
    VAR (PhaDiscnctPwmVect1, AUTOMATIC) PhaDiscnctDiagcPwmVect_Cnt_T_enum;

    MotCurrEolCalSt_T_enum = MOTCTRLMGR_MotCtrlMotCurrEolCalSt;
    MotCtrlPhaDiscnctDiagcActv_Cnt_T_logl = MOTCTRLMGR_MotCtrlPhaDiscnctDiagcActv;
    
    /* CM475A_TSG31CfgAndUse/TSG31CfgAndUse/TSG31CfgAndUsePer1/Truth Table */
    if(MotCtrlPhaDiscnctDiagcActv_Cnt_T_logl == FALSE)
    {
        /* Phase Disconnect diagnostic Not Active */
        if (MotCurrEolCalSt_T_enum == MCECS_OFFSCMDSTRT)
        {
            /* Action Table Row 4 */
            PwmPerd_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPwmPerd;
            PhaOnTiA_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPhaOnTiA;
            PhaOnTiB_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPhaOnTiB;
            PhaOnTiC_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPhaOnTiC;
        }
        else if (MotCurrEolCalSt_T_enum == MCECS_OFFSCMDHI)
        {
            /* Action Table Row 1 */
            PwmPerd_NanoSec_T_u32 = Rte_Prm_CurrMeasEolFixdPwmPerd_Val();
            PhaOnTiA_NanoSec_T_u32 = Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val();
            PhaOnTiB_NanoSec_T_u32 = Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val();
            PhaOnTiC_NanoSec_T_u32 = Rte_Prm_CurrMeasEolOffsHiCmuOffs_Val();
        }
        else if (MotCurrEolCalSt_T_enum == MCECS_OFFSCMDLO)
        {
            /* Action Table Row 2 */
            PwmPerd_NanoSec_T_u32 = Rte_Prm_CurrMeasEolFixdPwmPerd_Val();
            PhaOnTiA_NanoSec_T_u32 = Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val();
            PhaOnTiB_NanoSec_T_u32 = Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val();
            PhaOnTiC_NanoSec_T_u32 = Rte_Prm_CurrMeasEolOffsLoCmuOffs_Val();
        }
        else if (MotCurrEolCalSt_T_enum == MCECS_OFFSCMDZERO)
        {
            /* Action Table Row 3 */
            PwmPerd_NanoSec_T_u32 = Rte_Prm_CurrMeasEolFixdPwmPerd_Val();
            PhaOnTiA_NanoSec_T_u32 = 0U;
            PhaOnTiB_NanoSec_T_u32 = 0U;
            PhaOnTiC_NanoSec_T_u32 = 0U;
        }
        else 
        {
            /* Action Table Row 4 */
            PwmPerd_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPwmPerd;
            PhaOnTiA_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPhaOnTiA;
            PhaOnTiB_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPhaOnTiB;
            PhaOnTiC_NanoSec_T_u32 = MOTCTRLMGR_MotCtrlPhaOnTiC;
        }
    }
    else
    {
        /* Phase Disconnect diagnostic Active */
        PwmPerd_NanoSec_T_u32 = Rte_Prm_PhaDiscnctFixdPwmPerd_Val();
        PhaDiscnctDiagcPwmVect_Cnt_T_enum = MOTCTRLMGR_MotCtrlPhaDiscnctDiagcPwmVect;
        
        if(PhaDiscnctDiagcPwmVect_Cnt_T_enum == PHADISCNCTPWMVECT_PHAACMD)
        {
            PhaOnTiA_NanoSec_T_u32 = Rte_Prm_PhaDiscnctFixdPhaOnTi_Val();
        }
        else
        {
            PhaOnTiA_NanoSec_T_u32 = 0u;
        }
        
        if(PhaDiscnctDiagcPwmVect_Cnt_T_enum == PHADISCNCTPWMVECT_PHABCMD)
        {
            PhaOnTiB_NanoSec_T_u32 = Rte_Prm_PhaDiscnctFixdPhaOnTi_Val();
        }
        else
        {
            PhaOnTiB_NanoSec_T_u32 = 0u;
        }
        
        if(PhaDiscnctDiagcPwmVect_Cnt_T_enum == PHADISCNCTPWMVECT_PHACCMD)
        {
            PhaOnTiC_NanoSec_T_u32 = Rte_Prm_PhaDiscnctFixdPhaOnTi_Val();
        }
        else
        {
            PhaOnTiC_NanoSec_T_u32 = 0u;
        }
    }
    /* Asserting PWM on time <= PwmPerd. This is essential condition for correct generation of signals controlling gate driver*/
    PhaOnTiA_NanoSec_T_u32 = Min_u32(PhaOnTiA_NanoSec_T_u32,PwmPerd_NanoSec_T_u32);
    PhaOnTiB_NanoSec_T_u32 = Min_u32(PhaOnTiB_NanoSec_T_u32,PwmPerd_NanoSec_T_u32);
    PhaOnTiC_NanoSec_T_u32 = Min_u32(PhaOnTiC_NanoSec_T_u32,PwmPerd_NanoSec_T_u32);

    PwmPerd_Cnt_T_u32 = CnvNanoSecToTmrCnt(PwmPerd_NanoSec_T_u32);
    MOTCTRLMGR_MotCtrlTSG31CMP0E = PwmPerd_Cnt_T_u32;
    MOTCTRLMGR_MotCtrlTSG31CMPUE = PwmPerd_Cnt_T_u32 - CnvNanoSecToTmrCnt(PhaOnTiA_NanoSec_T_u32);
    MOTCTRLMGR_MotCtrlTSG31CMPVE = PwmPerd_Cnt_T_u32 - CnvNanoSecToTmrCnt(PhaOnTiB_NanoSec_T_u32);
    MOTCTRLMGR_MotCtrlTSG31CMPWE = PwmPerd_Cnt_T_u32 - CnvNanoSecToTmrCnt(PhaOnTiC_NanoSec_T_u32);
    MOTCTRLMGR_MotCtrlTSG31DCMP0E = (PwmPerd_Cnt_T_u32 - *Rte_Pim_TSG31CfgAndUseAdcStrtOfCnvnPeak()) & CLRBIT0MASK_CNT_U32;
    MOTCTRLMGR_MotCtrlTSG31CMP12E = (PwmPerd_Cnt_T_u32 - *Rte_Pim_TSG31CfgAndUseMotAg0SPIStart()) & CLRBIT0MASK_CNT_U32;
    
    /* Missed Update Counter Monitor */
    MissUpdtCntrDiagc();
}

/******************************************************************************
  * Name:        MissUpdtCntrDiagc
  * Description: MissUpdtCntrDiagc performs the diagnostic on missed update counter
  * Inputs:      None     
  * Outputs:     None 
  * Usage Notes: Called from TSG31CfgAndUsePer1 
  ****************************************************************************/
static inline FUNC (void, CDD_TSG31CfgAndUse_CODE) MissUpdtCntrDiagc (void)
{
    if(*Rte_Pim_MissUpdIninCntr() > MISSUPDININCON_CNT_U08)
    {
        if(TSG31CUF == 0U)
        {
            *Rte_Pim_MissUpdCoarse() += 1U;
        }
        else
        {
            if(TSG31CNT > *Rte_Pim_MissUpdMaxCntr())
            {
                *Rte_Pim_MissUpdMaxCntr() = TSG31CNT;
            }
            if(TSG31CNT < *Rte_Pim_MissUpdMinCntr())
            {
                *Rte_Pim_MissUpdMinCntr() = TSG31CNT;
            }
            if(TSG31CNT < MISSUPDCNTRTHD_CNT_U16)
            {
                *Rte_Pim_MissUpdFine() += 1U;
            }
        }
    }
    else
    {
        *Rte_Pim_MissUpdIninCntr() = *Rte_Pim_MissUpdIninCntr() + 1U;
    }
}

#define CDD_TSG31CfgAndUse_MotCtrl_STOP_SEC_CODE
#include "CDD_TSG31CfgAndUse_MotCtrl_MemMap.h" 

