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
 *          File:  TSC_BmwVehSpd.h
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
Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpd_Val(float32 *data);
Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdQlfr_Val(BmwCogVehSpdQlfr1 *data);
Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdQlfrVld_Logl(boolean *data);
Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwCogVehSpdVld_Logl(boolean *data);
Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwNearStillVehSpdSts_Val(BmwNearStillVehSpdSts1 *data);
Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwNearStillVehSpdStsVld_Logl(boolean *data);
Std_ReturnType TSC_BmwVehSpd_Rte_Read_BmwPinionAgQlfr_Val(BmwPinionAgQlfr1 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_BmwVehSpd_Rte_Write_BmwSecurVehSpdSts_Val(BmwSecurVehSpdSts1 data);
Std_ReturnType TSC_BmwVehSpd_Rte_Write_VehSpd_Val(float32 data);
Std_ReturnType TSC_BmwVehSpd_Rte_Write_VehSpdVld_Logl(boolean data);

/** Client server interfaces */
Std_ReturnType TSC_BmwVehSpd_Rte_Call_GetRefTmr100MicroSec32bit_Oper(uint32 *RefTmr_Arg);
Std_ReturnType TSC_BmwVehSpd_Rte_Call_GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg);

/** Calibration Component Calibration Parameters */
float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdNearStillSubVehSpd_Val(void);
float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdRunngSubVehSpd_Val(void);
float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdInvldRateLim_Val(void);
float32  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdSecurVehSpdVldRateLim_Val(void);
u16p0  TSC_BmwVehSpd_Rte_Prm_BmwVehSpdBmwSecurVehSpdStsSigValVldDurnTiVal_Val(void);

/** Per Instance Memories */
float32 *TSC_BmwVehSpd_Rte_Pim_VehSpdLimPrev(void);
uint32 *TSC_BmwVehSpd_Rte_Pim_BmwSecurVehSpdStsSigValVldDurn(void);
boolean *TSC_BmwVehSpd_Rte_Pim_SpdDifChkFlg(void);



