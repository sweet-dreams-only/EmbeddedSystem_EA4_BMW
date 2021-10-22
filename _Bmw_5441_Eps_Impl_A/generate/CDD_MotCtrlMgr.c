
/**********************************************************************************************************************
* Copyright 2015 Nxtr 
* Nxtr Confidential
*
* Module File Name  : CDD_MotCtrlMgr.c
* Module Description: Motor Control Manager
* Project           : CBD
* Author            : Lucas Wendling
* Generator         : artt 2.0.2.0
* Generation Time   : 30.07.2018 19:59:48
***********************************************************************************************************************
* Version Control:
* %version:          26 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 06/05/15  1        LWW       Initial Template Version                                                        EA4#511
* 10/29/15  2        LWW       Template update for signal mapping changes                                      EA4#3428
* 08/08/16  3        LWW       Template update for compatibility with MotCtrlMgr Configuration Tool            EA4#6787
**********************************************************************************************************************/



/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotCtrlMgr.h"
#include "CDD_MotCtrlMgr_Data.h"
/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value.  Applicable to all casts to void for all Rte_Read and Rte_Write and for client calls that don't have return errors. */ 

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/

#define CDD_MotCtrlMgr_START_SEC_CODE
#include "CDD_MotCtrlMgr_MemMap.h"

/**********************************************************************************************************************
  * Name:        MotCtrlMgrPer1
  * Description: This function copies all non-RTE data transferred by the DMA from the Motor Control loop to the 2ms loop
  *              and provides them as standard sender outputs for use by the RTE.  A DMA function is called to ensure
  *              completion of the transfer and in case of a timeout error, the RTE outputs are not updated from values
  *              last loop.
  * Inputs:      MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec structure
  * Outputs:     Individual RTE outputs for all signals
  * Usage Notes: To be scheduled by the RTE near the start of the 2ms loop.  Note that other runnables not requiring 
  *              Motor control data can be scheduled in-between the runnable triggering the DMA transfer and this function
  *              to try to prevent or minimize stalled execution while waiting for the DMA transfer.
  ********************************************************************************************************************/
FUNC(void, CDD_MotCtrlMgr_CODE) MotCtrlMgrPer1(void)
{
	if (Rte_Call_DmaWaitForMotCtrlTo2MilliSecTrf_Oper() == E_OK)
	{
		(void)Rte_Write_PhaOnTiSumB_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.PhaOnTiSumB);
		(void)Rte_Write_PhaOnTiSumC_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.PhaOnTiSumC);
		(void)Rte_Write_MotAg1Mecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1Mecl);
		(void)Rte_Write_HwTq4RawAdc_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.HwTq4RawAdc);
		(void)Rte_Write_MotAg0ErrReg_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0ErrReg);
		(void)Rte_Write_MotAg0VltgFltCnt_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0VltgFltCnt);
		(void)Rte_Write_Adc0SelfDiag4_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0SelfDiag4);
		(void)Rte_Write_MotAg1MeclRollgCntr_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1MeclRollgCntr);
		(void)Rte_Write_HwTq4RawFastAdcBuf_Ary1D(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.HwTq4RawFastAdcBuf);
		(void)Rte_Write_MotCurrCorrdC_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdC);
		(void)Rte_Write_MotCurrCorrdB_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdB);
		(void)Rte_Write_Adc0SelfDiag2_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0SelfDiag2);
		(void)Rte_Write_MotCurrCorrdA_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdA);
		(void)Rte_Write_MotAg0TurnCntrReg_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0TurnCntrReg);
		(void)Rte_Write_Adc0SelfDiag0_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0SelfDiag0);
		(void)Rte_Write_PhaOnTiSumA_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.PhaOnTiSumA);
		(void)Rte_Write_Adc0ScanGroup2Ref1_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup2Ref1);
		(void)Rte_Write_MotAg1TurnCntrReg_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1TurnCntrReg);
		(void)Rte_Write_Adc0ScanGroup2Ref0_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup2Ref0);
		(void)Rte_Write_MotAg0ParFltCnt_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0ParFltCnt);
		(void)Rte_Write_BattRtnCurrAdc_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.BattRtnCurrAdc);
		(void)Rte_Write_BattVltgAdc_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.BattVltgAdc);
		(void)Rte_Write_MotAg1ParFltCnt_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1ParFltCnt);
		(void)Rte_Write_MotCurrAdcVlyC_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrAdcVlyC);
		(void)Rte_Write_MotAgCumvInid_Logl(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgCumvInid);
		(void)Rte_Write_MotCurrRollgCntr1_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrRollgCntr1);
		(void)Rte_Write_MotAg0Mecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0Mecl);
		(void)Rte_Write_MotAg1ErrReg_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1ErrReg);
		(void)Rte_Write_HwTq5RawAdc_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.HwTq5RawAdc);
		(void)Rte_Write_MotAg1VltgFltCnt_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1VltgFltCnt);
		(void)Rte_Write_MotCurrAdcVlyB_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrAdcVlyB);
		(void)Rte_Write_MotCurrAdcVlyA_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrAdcVlyA);
		(void)Rte_Write_MotAgCumvAlgndMrfRev_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgCumvAlgndMrfRev);
		(void)Rte_Write_MotAg0MeclRollgCntr_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0MeclRollgCntr);
		(void)Rte_Write_HwTq5RawFastAdcBuf_Ary1D(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.HwTq5RawFastAdcBuf);
		(void)Rte_Write_Adc0ScanGroup3Ref1_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup3Ref1);
		(void)Rte_Write_Adc0ScanGroup3Ref0_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup3Ref0);
		(void)Rte_Write_Ntc5DErrCnt_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Ntc5DErrCnt);
		(void)Rte_Write_MotAgBuf_Ary1D(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgBuf);
		(void)Rte_Write_MotAgBufIdx_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgBufIdx);
		(void)Rte_Write_MotAgTiBuf_Ary1D(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgTiBuf);
		(void)Rte_Write_MotCurrDax_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrDax);
		(void)Rte_Write_MotCurrQax_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrQax);
		(void)Rte_Write_MotVltgDax_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotVltgDax);
		(void)Rte_Write_MotVltgQax_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotVltgQax);
		(void)Rte_Write_SlowLoopCntr_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.SlowLoopCntr);
		(void)Rte_Write_FastLoopCntr_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.FastLoopCntr);
		(void)Rte_Write_MotAg1WarnReg_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1WarnReg);
		(void)Rte_Write_MotAg0WarnReg_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0WarnReg);
		(void)Rte_Write_MotAg3Mecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg3Mecl);
		(void)Rte_Write_MotAg0SpiMecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0SpiMecl);
		(void)Rte_Write_MotAg4Mecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg4Mecl);
		(void)Rte_Write_MotAg1SpiMecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1SpiMecl);
	}
}


/**********************************************************************************************************************
  * Name:        MotCtrlMgrPer2
  * Description: This function copies all RTE data transferred by the DMA from the 2ms loop to the Motor Control loop 
  *              to the non-RTE structure the DMA references.  A DMA function is called at the end of processing to
  *              trigger the DMA transfer of the data.
  * Inputs:      Individual RTE inputs for all signals
  * Outputs:     MotCtrlMgr_TwoMilliSecToMotCtrl_Rec structure
  * Usage Notes: To be scheduled by the RTE at the end of the 2ms forward path after all critical forward path motor control
  *              signals have been calculated.
  ********************************************************************************************************************/
FUNC(void, CDD_MotCtrlMgr_CODE) MotCtrlMgrPer2(void)
{
	(void)Rte_Read_MotVelMrf_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotVelMrf);
	(void)Rte_Read_IvtrFetFltTyp_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.IvtrFetFltTyp);
	(void)Rte_Read_CurrMeasWrmIninTestCmpl_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.CurrMeasWrmIninTestCmpl);
	(void)Rte_Read_SysSt_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.SysSt);
	(void)Rte_Read_MotCurrEolCalSt_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrEolCalSt);
	(void)Rte_Read_DiagcStsIvtr1Inactv_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.DiagcStsIvtr1Inactv);
	(void)Rte_Read_MotCurrAdcVlyAAdcFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrAdcVlyAAdcFaild);
	(void)Rte_Read_MotCurrAdcVlyBAdcFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrAdcVlyBAdcFaild);
	(void)Rte_Read_VehSpd_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.VehSpd);
	(void)Rte_Read_EcuTFild_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.EcuTFild);
	(void)Rte_Read_AdcDiagcStrtPtrOutp_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.AdcDiagcStrtPtrOutp);
	(void)Rte_Read_MotCurrAdcVlyCAdcFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrAdcVlyCAdcFaild);
	(void)Rte_Read_AdcDiagcEndPtrOutp_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.AdcDiagcEndPtrOutp);
	(void)Rte_Read_MotElecMeclPolarity_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotElecMeclPolarity);
	(void)Rte_Read_BrdgVltg_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.BrdgVltg);
	(void)Rte_Read_IvtrFetFltPha_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.IvtrFetFltPha);
	(void)Rte_Read_MotAgElecDly_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAgElecDly);
	(void)Rte_Read_MotBackEmfVltg_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotBackEmfVltg);
	(void)Rte_Read_MotCurrDaxCmd_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrDaxCmd);
	(void)Rte_Read_MotCurrDaxMax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrDaxMax);
	(void)Rte_Read_MotCurrQaxCmd_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrQaxCmd);
	(void)Rte_Read_MotDampgDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotDampgDax);
	(void)Rte_Read_MotDampgQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotDampgQax);
	(void)Rte_Read_MotInduDaxEstimdIvs_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotInduDaxEstimdIvs);
	(void)Rte_Read_MotInduQaxEstimdIvs_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotInduQaxEstimdIvs);
	(void)Rte_Read_MotIntglGainDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotIntglGainDax);
	(void)Rte_Read_MotIntglGainQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotIntglGainQax);
	(void)Rte_Read_MotPropGainDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotPropGainDax);
	(void)Rte_Read_MotPropGainQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotPropGainQax);
	(void)Rte_Read_MotReacncDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotReacncDax);
	(void)Rte_Read_MotReacncQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotReacncQax);
	(void)Rte_Read_MotREstimd_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotREstimd);
	(void)Rte_Read_MotVltgDaxFf_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotVltgDaxFf);
	(void)Rte_Read_MotVltgQaxFf_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotVltgQaxFf);
	(void)Rte_Read_CurrMeasCorrlnSts_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.CurrMeasCorrlnSts);
	(void)Rte_Read_MotCurrQlfr1_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrQlfr1);
	(void)Rte_Read_LoopCntr2MilliSec_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.LoopCntr2MilliSec);
	(void)Rte_Read_PhaDiscnctDiagcActv_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.PhaDiscnctDiagcActv);
	(void)Rte_Read_PhaDiscnctDiagcPwmVect_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.PhaDiscnctDiagcPwmVect);
	(void)Rte_Read_MotAndThermProtnLoaMod_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAndThermProtnLoaMod);
	(void)Rte_Read_MotAg0QepFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg0QepFaild);
	(void)Rte_Read_MotAg1QepFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg1QepFaild);

	(void)Rte_Call_DmaEna2MilliSecToMotCtrlTrf_Oper();
}

#define CDD_MotCtrlMgr_STOP_SEC_CODE
#include "CDD_MotCtrlMgr_MemMap.h"
