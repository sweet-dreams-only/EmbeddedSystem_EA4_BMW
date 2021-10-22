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
 *          File:  TSC_PwrUpSeq.h
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
Std_ReturnType TSC_PwrUpSeq_Rte_Read_CodFlsCrcChkCmpl_Logl(boolean *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_CurrMeasWrmIninTestCmpl_Logl(boolean *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_MotDrvr0IninTestCmpl_Logl(boolean *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_MotDrvr1IninTestCmpl_Logl(boolean *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_PhaDiscnctWrmIninTestCmpl_Logl(boolean *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_PwrDiscnctATestCmpl_Logl(boolean *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_PwrDiscnctBTestCmpl_Logl(boolean *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_SysSt_Val(SysSt1 *data);
Std_ReturnType TSC_PwrUpSeq_Rte_Read_TmplMonIninTestCmpl_Logl(boolean *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_PwrUpSeq_Rte_Write_StrtUpSt_Val(uint8 data);
Std_ReturnType TSC_PwrUpSeq_Rte_Write_SysStWrmIninCmpl_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_PwrUpSeq_Rte_Call_IoHwAb_SetGpioPwrTurnOffCtrl_Oper(boolean PinSt_Arg);

/** Per Instance Memories */
uint8 *TSC_PwrUpSeq_Rte_Pim_PwrTurnOffCtrlPrev(void);



