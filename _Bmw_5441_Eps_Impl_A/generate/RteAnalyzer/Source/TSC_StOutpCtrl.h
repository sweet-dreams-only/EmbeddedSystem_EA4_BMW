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
 *          File:  TSC_StOutpCtrl.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nxtr Automotive Corporation
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_StOutpCtrl_Rte_Read_DiagcStsCtrldShtDwnFltPrsnt_Logl(boolean *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_LoaRateLim_Val(float32 *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_LoaSca_Val(float32 *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_MotTqTranlDampgCmpl_Logl(boolean *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysDiMotTqCmdSca_Val(float32 *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysDiRampRate_Val(float32 *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysMotTqCmdRampRateDi_Logl(boolean *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysOperMotTqCmdSca_Val(float32 *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysOperRampRate_Val(float32 *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_SysStFltOutpReqDi_Logl(boolean *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_VehStrtStopMotTqCmdSca_Val(float32 *data);
Std_ReturnType TSC_StOutpCtrl_Rte_Read_VehStrtStopRampRate_Val(float32 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_StOutpCtrl_Rte_Write_SysMotTqCmdSca_Val(float32 data);
Std_ReturnType TSC_StOutpCtrl_Rte_Write_SysStReqDi_Logl(boolean data);

/** Per Instance Memories */
float32 *TSC_StOutpCtrl_Rte_Pim_StOutpCtrlPrevCmdSca(void);
float32 *TSC_StOutpCtrl_Rte_Pim_dStOutpCtrlRateLim(void);
float32 *TSC_StOutpCtrl_Rte_Pim_dStOutpCtrlTarSca(void);
uint8 *TSC_StOutpCtrl_Rte_Pim_StOutpCtrlPrevSrc(void);



