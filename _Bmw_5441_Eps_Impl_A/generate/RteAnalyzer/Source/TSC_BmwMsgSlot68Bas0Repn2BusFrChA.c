/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_BmwMsgSlot68Bas0Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot68Bas0Repn2BusFrChA.h"
#include "TSC_BmwMsgSlot68Bas0Repn2BusFrChA.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Read_FltCodEnad_Logl(boolean *data)
{
  return Rte_Read_FltCodEnad_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(sigGroup_TAR_QTA_STRMOM_DV1 *data)
{
  return Rte_Read_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(data);
}


boolean TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV(void)
{
  return Rte_IsUpdated_sigGroup_TAR_QTA_STRMOM_DV_sigGroup_TAR_QTA_STRMOM_DV();
}



Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwDrvgDynDampgFacReq_Val(float32 data)
{
  return Rte_Write_BmwDrvgDynDampgFacReq_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwDrvgDynEffortFacReq_Val(float32 data)
{
  return Rte_Write_BmwDrvgDynEffortFacReq_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwDrvgDynEnaRqst_Logl(boolean data)
{
  return Rte_Write_BmwDrvgDynEnaRqst_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwDrvgDynErrIfActv_Logl(boolean data)
{
  return Rte_Write_BmwDrvgDynErrIfActv_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwDrvgDynFacQlfr_Val(BmwOvrlCmdQlfr1 data)
{
  return Rte_Write_BmwDrvgDynFacQlfr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwDrvgDynFacQlfrVld_Logl(boolean data)
{
  return Rte_Write_BmwDrvgDynFacQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwDrvgDynRtnFacReq_Val(float32 data)
{
  return Rte_Write_BmwDrvgDynRtnFacReq_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwEpsDeactvnCtrl_Val(BmwEpsDeactvnCtrl1 data)
{
  return Rte_Write_BmwEpsDeactvnCtrl_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTarHwTqOvrl_Val(float32 data)
{
  return Rte_Write_BmwTarHwTqOvrl_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTarHwTqOvrlQlfr_Val(BmwOvrlCmdQlfr1 data)
{
  return Rte_Write_BmwTarHwTqOvrlQlfr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(boolean data)
{
  return Rte_Write_BmwTarHwTqOvrlQlfrVld_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(sigGroup_TAR_STMOM_DV_ACT1 *data)
{
  return Rte_Read_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(data);
}


boolean TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT(void)
{
  return Rte_IsUpdated_sigGroup_TAR_STMOM_DV_ACT_sigGroup_TAR_STMOM_DV_ACT();
}



Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTarSteerTqDrvrActr_Val(float32 data)
{
  return Rte_Write_BmwTarSteerTqDrvrActr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(BmwOvrlCmdQlfr1 data)
{
  return Rte_Write_BmwTarSteerTqDrvrActrQlfr_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(boolean data)
{
  return Rte_Write_BmwTarSteerTqDrvrActrQlfrVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(float32 data)
{
  return Rte_Write_BmwTrfcJamAssiDampgScaReq_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(boolean data)
{
  return Rte_Write_BmwTrfcJamAssiDampgScaReqVld_Logl(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTrfcJamAssiDampgStReq_Val(BmwTrfcJamAssiDampgStReq1 data)
{
  return Rte_Write_BmwTrfcJamAssiDampgStReq_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(boolean data)
{
  return Rte_Write_BmwTrfcJamAssiDampgStReqVld_Logl(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */





sint8  TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val(void)
{
  return (sint8 ) Rte_Prm_BmwMsgSlot108Bas0Repn2BusFrChABmwSteerPolarity_Val();
}


     /* BmwMsgSlot68Bas0Repn2BusFrChA */
      /* BmwMsgSlot68Bas0Repn2BusFrChA */

/** Per Instance Memories */
float32 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynDampgFacReqPrev(void)
{
  return Rte_Pim_BmwDrvgDynDampgFacReqPrev();
}
float32 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynEffortFacReqPrev(void)
{
  return Rte_Pim_BmwDrvgDynEffortFacReqPrev();
}
float32 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynRtnFacReqPrev(void)
{
  return Rte_Pim_BmwDrvgDynRtnFacReqPrev();
}
float32 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarHwTqOvrlPrev(void)
{
  return Rte_Pim_BmwTarHwTqOvrlPrev();
}
float32 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarSteerTqDrvrActrPrev(void)
{
  return Rte_Pim_BmwTarSteerTqDrvrActrPrev();
}
float32 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev(void)
{
  return Rte_Pim_BmwTrfcJamAssiDampgScaReqPrev();
}
BmwOvrlCmdQlfr1 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynFacQlfrPrev(void)
{
  return Rte_Pim_BmwDrvgDynFacQlfrPrev();
}
BmwEpsDeactvnCtrl1 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwEpsDeactvnCtrlPrev(void)
{
  return Rte_Pim_BmwEpsDeactvnCtrlPrev();
}
BmwOvrlCmdQlfr1 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarHwTqOvrlQlfPrev(void)
{
  return Rte_Pim_BmwTarHwTqOvrlQlfPrev();
}
BmwOvrlCmdQlfr1 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev(void)
{
  return Rte_Pim_BmwTarSteerTqDrvrActrQlfrPrev();
}
BmwTrfcJamAssiDampgStReq1 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTrfcJamAssiDampgStReqPrev(void)
{
  return Rte_Pim_BmwTrfcJamAssiDampgStReqPrev();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_CtrDeacEpsFnsFaild(void)
{
  return Rte_Pim_CtrDeacEpsFnsFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_CtrDeacEpsFnsPassd(void)
{
  return Rte_Pim_CtrDeacEpsFnsPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactAssStmomFtaxFaild(void)
{
  return Rte_Pim_FactAssStmomFtaxFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactAssStmomFtaxPassd(void)
{
  return Rte_Pim_FactAssStmomFtaxPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactCtrrStmomFtaxFaild(void)
{
  return Rte_Pim_FactCtrrStmomFtaxFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactCtrrStmomFtaxPassd(void)
{
  return Rte_Pim_FactCtrrStmomFtaxPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactDmpngAddonStmomFtaxFaild(void)
{
  return Rte_Pim_FactDmpngAddonStmomFtaxFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactDmpngAddonStmomFtaxPassd(void)
{
  return Rte_Pim_FactDmpngAddonStmomFtaxPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactDmpngStmomFtaxFaild(void)
{
  return Rte_Pim_FactDmpngStmomFtaxFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_FactDmpngStmomFtaxPassd(void)
{
  return Rte_Pim_FactDmpngStmomFtaxPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarDmpngAddonStmomFtaxFaild(void)
{
  return Rte_Pim_QuTarDmpngAddonStmomFtaxFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarDmpngAddonStmomFtaxPassd(void)
{
  return Rte_Pim_QuTarDmpngAddonStmomFtaxPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarFactStmomFtaxFaild(void)
{
  return Rte_Pim_QuTarFactStmomFtaxFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarFactStmomFtaxPassd(void)
{
  return Rte_Pim_QuTarFactStmomFtaxPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarQtaStmomDvFaild(void)
{
  return Rte_Pim_QuTarQtaStmomDvFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarQtaStmomDvPassd(void)
{
  return Rte_Pim_QuTarQtaStmomDvPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarStmomDvActFaild(void)
{
  return Rte_Pim_QuTarStmomDvActFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_QuTarStmomDvActPassd(void)
{
  return Rte_Pim_QuTarStmomDvActPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStmomDvFaild(void)
{
  return Rte_Pim_TarQtaStmomDvFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStmomDvPassd(void)
{
  return Rte_Pim_TarQtaStmomDvPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvAliveCntFaild(void)
{
  return Rte_Pim_TarQtaStrmomDvAliveCntFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvAliveCntPassd(void)
{
  return Rte_Pim_TarQtaStrmomDvAliveCntPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvCRCFaild(void)
{
  return Rte_Pim_TarQtaStrmomDvCRCFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvCRCPassd(void)
{
  return Rte_Pim_TarQtaStrmomDvCRCPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvMissFaild(void)
{
  return Rte_Pim_TarQtaStrmomDvMissFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvMissPassd(void)
{
  return Rte_Pim_TarQtaStrmomDvMissPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActAliveCntFaild(void)
{
  return Rte_Pim_TarStmomDvActAliveCntFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActAliveCntPassd(void)
{
  return Rte_Pim_TarStmomDvActAliveCntPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActCrcFaild(void)
{
  return Rte_Pim_TarStmomDvActCrcFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActCrcPassd(void)
{
  return Rte_Pim_TarStmomDvActCrcPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActFaild(void)
{
  return Rte_Pim_TarStmomDvActFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActMissFaild(void)
{
  return Rte_Pim_TarStmomDvActMissFaild();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActMissPassd(void)
{
  return Rte_Pim_TarStmomDvActMissPassd();
}
uint8 *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActPassd(void)
{
  return Rte_Pim_TarStmomDvActPassd();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynDampgFacReqVldPrev(void)
{
  return Rte_Pim_BmwDrvgDynDampgFacReqVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynEffortFacReqVldPrev(void)
{
  return Rte_Pim_BmwDrvgDynEffortFacReqVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynEnaReqPrev(void)
{
  return Rte_Pim_BmwDrvgDynEnaReqPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynErrIfActvPrev(void)
{
  return Rte_Pim_BmwDrvgDynErrIfActvPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynFacQlfrVldPrev(void)
{
  return Rte_Pim_BmwDrvgDynFacQlfrVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwDrvgDynRtnFacReqVldPrev(void)
{
  return Rte_Pim_BmwDrvgDynRtnFacReqVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwEpsDeactvnCtrlVldPrev(void)
{
  return Rte_Pim_BmwEpsDeactvnCtrlVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev(void)
{
  return Rte_Pim_BmwTarHwTqOvrlQlfrVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarHwTqOvrlVldPrev(void)
{
  return Rte_Pim_BmwTarHwTqOvrlVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev(void)
{
  return Rte_Pim_BmwTarSteerTqDrvrActrQlfrVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTarSteerTqDrvrActrVldPrev(void)
{
  return Rte_Pim_BmwTarSteerTqDrvrActrVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev(void)
{
  return Rte_Pim_BmwTrfcJamAssiDampgScaReqVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev(void)
{
  return Rte_Pim_BmwTrfcJamAssiDampgStReqVldPrev();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvArcVld(void)
{
  return Rte_Pim_TarQtaStrmomDvArcVld();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvMsgProcd(void)
{
  return Rte_Pim_TarQtaStrmomDvMsgProcd();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarQtaStrmomDvMsgVld(void)
{
  return Rte_Pim_TarQtaStrmomDvMsgVld();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActArcVld(void)
{
  return Rte_Pim_TarStmomDvActArcVld();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActMsgProcd(void)
{
  return Rte_Pim_TarStmomDvActMsgProcd();
}
boolean *TSC_BmwMsgSlot68Bas0Repn2BusFrChA_Rte_Pim_TarStmomDvActMsgVld(void)
{
  return Rte_Pim_TarStmomDvActMsgVld();
}



